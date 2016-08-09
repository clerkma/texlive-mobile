/*1:*/
#line 20 "./luatexdir/tex/texfileio.w"



#include "ptexlib.h"

#include <string.h> 
#include <kpathsea/absolute.h> 

/*:1*//*3:*/
#line 65 "./luatexdir/tex/texfileio.w"

char*nameoffile;
int namelength;


/*:3*//*4:*/
#line 78 "./luatexdir/tex/texfileio.w"

int*input_file_callback_id;
int read_file_callback_id[17];

/*:4*//*5:*/
#line 89 "./luatexdir/tex/texfileio.w"

static char*find_in_output_directory(const char*s)
{
if(output_directory&&!kpse_absolute_p(s,false)){
FILE*f_ptr;
char*ftemp= concat3(output_directory,DIR_SEP_STRING,s);
f_ptr= fopen(ftemp,"rb");
if(f_ptr){
fclose(f_ptr);
return ftemp;
}else{
free(ftemp);

}
}
return NULL;
}

/*:5*//*6:*/
#line 109 "./luatexdir/tex/texfileio.w"

char*luatex_find_read_file(const char*s,int n,int callback_index)
{
char*ftemp= NULL;
int callback_id= callback_defined(callback_index);
if(callback_id> 0){
(void)run_callback(callback_id,"dS->R",n,s,&ftemp);
}else{

ftemp= find_in_output_directory(s);
if(!ftemp)
ftemp= kpse_find_file(s,kpse_tex_format,1);
}
if(ftemp){
if(fullnameoffile)
free(fullnameoffile);
fullnameoffile= xstrdup(ftemp);
}
return ftemp;
}

/*:6*//*7:*/
#line 131 "./luatexdir/tex/texfileio.w"

char*luatex_find_file(const char*s,int callback_index)
{
char*ftemp= NULL;
int callback_id= callback_defined(callback_index);
if(callback_id> 0){
(void)run_callback(callback_id,"S->R",s,&ftemp);

}else{

switch(callback_index){
case find_enc_file_callback:
ftemp= kpse_find_file(s,kpse_enc_format,0);
break;
case find_sfd_file_callback:
ftemp= kpse_find_file(s,kpse_sfd_format,0);
break;
case find_map_file_callback:
ftemp= kpse_find_file(s,kpse_fontmap_format,0);
break;
case find_type1_file_callback:
ftemp= kpse_find_file(s,kpse_type1_format,0);
break;
case find_truetype_file_callback:
ftemp= kpse_find_file(s,kpse_truetype_format,0);
break;
case find_opentype_file_callback:
ftemp= kpse_find_file(s,kpse_opentype_format,0);
if(ftemp==NULL)
ftemp= kpse_find_file(s,kpse_truetype_format,0);
break;
case find_data_file_callback:
ftemp= find_in_output_directory(s);
if(!ftemp)
ftemp= kpse_find_file(s,kpse_tex_format,0);
break;
case find_font_file_callback:
ftemp= kpse_find_file(s,kpse_ofm_format,0);
if(ftemp==NULL)
ftemp= kpse_find_file(s,kpse_tfm_format,0);
break;
case find_vf_file_callback:
ftemp= kpse_find_file(s,kpse_ovf_format,0);
if(ftemp==NULL)
ftemp= kpse_find_file(s,kpse_vf_format,0);
break;
case find_cidmap_file_callback:
ftemp= kpse_find_file(s,kpse_cid_format,0);
break;
default:
printf
("luatex_find_file(): do not know how to handle file %s of type %d\n",
s,callback_index);
break;
}
}
return ftemp;
}


/*:7*//*8:*/
#line 199 "./luatexdir/tex/texfileio.w"

#define openoutnameok(A)  kpse_out_name_ok (A)
#define openinnameok(A)  kpse_in_name_ok (A)

/*:8*//*9:*/
#line 207 "./luatexdir/tex/texfileio.w"

boolean
luatex_open_input(FILE**f_ptr,const char*fn,int filefmt,
const_string fopen_mode,boolean must_exist)
{
string fname= NULL;

*f_ptr= NULL;
if(fullnameoffile)
free(fullnameoffile);
fullnameoffile= NULL;
fname= kpse_find_file(fn,(kpse_file_format_type)filefmt,must_exist);
if(fname){
fullnameoffile= xstrdup(fname);






if(fname[0]=='.'&&IS_DIR_SEP(fname[1])
&&(fn[0]!='.'||!IS_DIR_SEP(fn[1]))){
unsigned i= 0;
while(fname[i+2]!=0){
fname[i]= fname[i+2];
i++;
}
fname[i]= 0;
}

*f_ptr= xfopen(fname,fopen_mode);
}
if(*f_ptr){
recorder_record_input(fname);
}
return*f_ptr!=NULL;
}

/*:9*//*10:*/
#line 245 "./luatexdir/tex/texfileio.w"

boolean luatex_open_output(FILE**f_ptr,const char*fn,
const_string fopen_mode)
{
char*fname;
boolean absolute= kpse_absolute_p(fn,false);


if(output_directory&&!absolute){
fname= concat3(output_directory,DIR_SEP_STRING,fn);
}else{
fname= xstrdup(fn);
}


*f_ptr= fopen(fname,fopen_mode);

if(!*f_ptr){

string texmfoutput= kpse_var_value("TEXMFOUTPUT");

if(texmfoutput&&*texmfoutput&&!absolute){
fname= concat3(texmfoutput,DIR_SEP_STRING,fn);
*f_ptr= fopen(fname,fopen_mode);
}
}
if(*f_ptr){
recorder_record_output(fname);
}
free(fname);
return*f_ptr!=NULL;
}


/*:10*//*11:*/
#line 279 "./luatexdir/tex/texfileio.w"

boolean lua_a_open_in(alpha_file*f,char*fn,int n)
{
int k;
char*fnam;
int callback_id;
boolean ret= true;
boolean file_ok= true;
if(n==0){
input_file_callback_id[iindex]= 0;
}else{
read_file_callback_id[n]= 0;
}
if(*fn=='|')
fnam= fn;
else
fnam= luatex_find_read_file(fn,n,find_read_file_callback);
if(!fnam)
return false;
callback_id= callback_defined(open_read_file_callback);
if(callback_id> 0){
k= run_and_save_callback(callback_id,"S->",fnam);
if(k> 0){
ret= true;
if(n==0)
input_file_callback_id[iindex]= k;
else
read_file_callback_id[n]= k;
}else{
file_ok= false;
}
}else{
if(openinnameok(fnam)){
ret= 
open_in_or_pipe(f,fnam,kpse_tex_format,FOPEN_RBIN_MODE,
(n==0?true:false));
}else{
file_ok= false;
}
}
if(!file_ok){
ret= false;
}
return ret;
}


/*:11*//*12:*/
#line 326 "./luatexdir/tex/texfileio.w"

boolean lua_a_open_out(alpha_file*f,char*fn,int n)
{
boolean test;
str_number fnam;
int callback_id;
boolean ret= false;
callback_id= callback_defined(find_write_file_callback);
if(callback_id> 0){
fnam= 0;
test= run_callback(callback_id,"dS->s",n,fn,&fnam);
if((test)&&(fnam!=0)&&(str_length(fnam)> 0)){



ret= open_outfile(f,fn,FOPEN_W_MODE);
}
}else{
if(openoutnameok(fn)){
if(n> 0&&selector!=term_only){



fprintf(log_file,"\n\\openout%i = %s\n",n-1,fn);
}
ret= open_out_or_pipe(f,fn,FOPEN_W_MODE);
}
}
return ret;
}


/*:12*//*13:*/
#line 358 "./luatexdir/tex/texfileio.w"

boolean lua_b_open_out(alpha_file*f,char*fn)
{
boolean test;
str_number fnam;
int callback_id;
boolean ret= false;
callback_id= callback_defined(find_output_file_callback);
if(callback_id> 0){
fnam= 0;
test= run_callback(callback_id,"S->s",fn,&fnam);
if((test)&&(fnam!=0)&&(str_length(fnam)> 0)){
ret= open_outfile(f,fn,FOPEN_WBIN_MODE);
}
}else{
if(openoutnameok(fn)){
ret= luatex_open_output(f,fn,FOPEN_WBIN_MODE);
}
}
return ret;
}

/*:13*//*14:*/
#line 380 "./luatexdir/tex/texfileio.w"

void lua_a_close_in(alpha_file f,int n)
{
int callback_id;
if(n==0)
callback_id= input_file_callback_id[iindex];
else
callback_id= read_file_callback_id[n];
if(callback_id> 0){
run_saved_callback(callback_id,"close","->");
destroy_saved_callback(callback_id);
if(n==0)
input_file_callback_id[iindex]= 0;
else
read_file_callback_id[n]= 0;
}else{
close_file_or_pipe(f);
}
}

/*:14*//*15:*/
#line 400 "./luatexdir/tex/texfileio.w"

void lua_a_close_out(alpha_file f)
{
close_file_or_pipe(f);
}


/*:15*//*16:*/
#line 422 "./luatexdir/tex/texfileio.w"

packed_ASCII_code*buffer;
int first;
int last;
int max_buf_stack;


/*:16*//*17:*/
#line 462 "./luatexdir/tex/texfileio.w"

boolean lua_input_ln(alpha_file f,int n,boolean bypass_eoln)
{
boolean lua_result;
int last_ptr;
int callback_id;
(void)bypass_eoln;
if(n==0)
callback_id= input_file_callback_id[iindex];
else
callback_id= read_file_callback_id[n];
if(callback_id> 0){
last= first;
last_ptr= first;
lua_result= 
run_saved_callback(callback_id,"reader","->l",&last_ptr);
if((lua_result==true)&&(last_ptr!=0)){
last= last_ptr;
if(last> max_buf_stack)
max_buf_stack= last;
}else{
lua_result= false;
}
}else{
lua_result= input_ln(f,bypass_eoln);
}
if(lua_result==true){

if(last>=first){
callback_id= callback_defined(process_input_buffer_callback);
if(callback_id> 0){
last_ptr= first;
lua_result= 
run_callback(callback_id,"l->l",(last-first),
&last_ptr);
if((lua_result==true)&&(last_ptr!=0)){
last= last_ptr;
if(last> max_buf_stack)
max_buf_stack= last;
}
}
}
return true;
}
return false;
}


/*:17*//*19:*/
#line 557 "./luatexdir/tex/texfileio.w"

boolean init_terminal(void)
{
t_open_in();
if(last> first){
iloc= first;
while((iloc<last)&&(buffer[iloc]==' '))
incr(iloc);
if(iloc<last){
return true;
}
}
while(1){
wake_up_terminal();
fputs("**",term_out);
update_terminal();
if(!input_ln(term_in,true)){

fputs("\n! End of file on the terminal... why?\n",term_out);
return false;
}
iloc= first;
while((iloc<last)&&(buffer[iloc]==' '))
incr(iloc);
if(iloc<last){
return true;
}
fputs("Please type the name of your input file.\n",term_out);
}
}


/*:19*//*20:*/
#line 594 "./luatexdir/tex/texfileio.w"

void term_input(void)
{
int k;
update_terminal();
if(!input_ln(term_in,true))
fatal_error("End of file on the terminal!");
term_offset= 0;
decr(selector);
if(last!=first){
for(k= first;k<=last-1;k++)
print_char(buffer[k]);
}
print_ln();
incr(selector);
}


/*:20*//*21:*/
#line 655 "./luatexdir/tex/texfileio.w"

str_number cur_name;
str_number cur_area;
str_number cur_ext;


/*:21*//*22:*/
#line 672 "./luatexdir/tex/texfileio.w"

pool_pointer area_delimiter;
pool_pointer ext_delimiter;


/*:22*//*23:*/
#line 684 "./luatexdir/tex/texfileio.w"

#define append_to_fn(A) do {                                    \
        c= (A);                                                  \
        if (c!='"') {                                           \
            if (k<file_name_size) fn[k++]= (unsigned char)(c);   \
        }                                                       \
    } while (0)


char*pack_file_name(str_number n,str_number a,str_number e)
{
ASCII_code c;
unsigned char*j;
int k= 0;
unsigned char*fn= xmallocarray(packed_ASCII_code,
str_length(a)+str_length(n)+
str_length(e)+1);
for(j= str_string(a);j<str_string(a)+str_length(a);j++)
append_to_fn(*j);
for(j= str_string(n);j<str_string(n)+str_length(n);j++)
append_to_fn(*j);
for(j= str_string(e);j<str_string(e)+str_length(e);j++)
append_to_fn(*j);
fn[k]= 0;
return(char*)fn;
}



/*:23*//*24:*/
#line 723 "./luatexdir/tex/texfileio.w"

char*TEX_format_default;


/*:24*//*25:*/
#line 733 "./luatexdir/tex/texfileio.w"

char*open_fmt_file(void)
{
int j;
char*fmt= NULL;
int dist;
j= iloc;
if(buffer[iloc]=='&'){
incr(iloc);
j= iloc;
buffer[last]= ' ';
while(buffer[j]!=' ')
incr(j);
fmt= xmalloc((unsigned)(j-iloc+1));
strncpy(fmt,(char*)(buffer+iloc),(size_t)(j-iloc));
fmt[j-iloc]= 0;
dist= (int)(strlen(fmt)-strlen(DUMP_EXT));
if(!(strstr(fmt,DUMP_EXT)==fmt+dist))
fmt= concat(fmt,DUMP_EXT);
if(zopen_w_input(&fmt_file,fmt,DUMP_FORMAT,FOPEN_RBIN_MODE))
goto FOUND;
wake_up_terminal();
fprintf(stdout,"Sorry, I can't find the format `%s'; will try `%s'.\n",
fmt,TEX_format_default);
update_terminal();
}

fmt= TEX_format_default;
if(!zopen_w_input(&fmt_file,fmt,DUMP_FORMAT,FOPEN_RBIN_MODE)){
wake_up_terminal();
fprintf(stdout,"I can't find the format file `%s'!\n",
TEX_format_default);
return NULL;
}
FOUND:
iloc= j;
return fmt;
}


/*:25*//*26:*/
#line 785 "./luatexdir/tex/texfileio.w"

boolean name_in_progress;
str_number job_name;
boolean log_opened_global;


/*:26*//*27:*/
#line 795 "./luatexdir/tex/texfileio.w"

unsigned char*texmf_log_name;

/*:27*//*28:*/
#line 801 "./luatexdir/tex/texfileio.w"

void open_log_file(void)
{
int old_setting;
int k;
int l;
char*fn;
old_setting= selector;
if(job_name==0)
job_name= getjobname(maketexstring("texput"));
fn= pack_job_name(".fls");
recorder_change_filename(fn);
fn= pack_job_name(".log");
while(!lua_a_open_out(&log_file,fn,0)){















selector= term_only;
fn= prompt_file_name("transcript file name",".log");
}
texmf_log_name= (unsigned char*)xstrdup(fn);
selector= log_only;
log_opened_global= true;
if(callback_defined(start_run_callback)==0){

log_banner(luatex_version_string);

input_stack[input_ptr]= cur_input;
tprint_nl("**");
l= input_stack[0].limit_field;
if(buffer[l]==end_line_char_par)
decr(l);
for(k= 1;k<=l;k++)
print_char(buffer[k]);
print_ln();
}
flush_loggable_info();
selector= old_setting+2;
}

/*:28*//*29:*/
#line 856 "./luatexdir/tex/texfileio.w"

char*get_full_log_name(void)
{
if(output_directory){
char*ret= xmalloc(strlen((char*)texmf_log_name)+2+strlen(output_directory));
ret= strcpy(ret,output_directory);
strcat(ret,"/");
strcat(ret,(char*)texmf_log_name);
return ret;
}else{
return xstrdup((const char*)texmf_log_name);
}
}

/*:29*//*30:*/
#line 872 "./luatexdir/tex/texfileio.w"

char*luatex_synctex_get_current_name(void)
{
char*pwdbuf= NULL,*ret;
if(kpse_absolute_p(fullnameoffile,false)){
return xstrdup(fullnameoffile);
}
pwdbuf= xgetcwd();
ret= concat3(pwdbuf,DIR_SEP_STRING,fullnameoffile);
free(pwdbuf);
return ret;
}


/*:30*//*31:*/
#line 889 "./luatexdir/tex/texfileio.w"

void start_input(void)
{
str_number temp_str;
char*fn;
do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));

back_input();
if(cur_cmd!=left_brace_cmd){
scan_file_name();
}else{
scan_file_name_toks();
}
fn= pack_file_name(cur_name,cur_area,cur_ext);
while(1){
begin_file_reading();
if(lua_a_open_in(&cur_file,fn,0))
break;
end_file_reading();
fn= prompt_file_name("input file name","");
}
iname= maketexstring(fullnameoffile);


{
char*n,*p;
n= p= fullnameoffile+strlen(fullnameoffile);
while(p> fullnameoffile){
p--;
if(IS_DIR_SEP(*p)){
break;
}
}
if(IS_DIR_SEP(*p)){
p++;
}
while(n> fullnameoffile){
n--;
if(*n=='.'){
break;
}
}
if(n> p){
int q= *n;
cur_ext= maketexstring(n);
*n= 0;
cur_name= maketexstring(p);
*n= q;
}
}


source_filename_stack[in_open]= iname;
full_source_filename_stack[in_open]= xstrdup(fullnameoffile);

temp_str= search_string(iname);
if(temp_str> 0){
flush_str(iname);
iname= temp_str;
}
if(job_name==0){
job_name= getjobname(cur_name);
open_log_file();
}


report_start_file(filetype_tex,fullnameoffile);
incr(open_parens);
update_terminal();
istate= new_line;

synctexstartinput();






line= 1;
if(lua_input_ln(cur_file,0,false)){
;
}
firm_up_the_line();
if(end_line_char_inactive)
decr(ilimit);
else
buffer[ilimit]= (packed_ASCII_code)end_line_char_par;
first= ilimit+1;
iloc= istart;
}

/*:31*//*33:*/
#line 988 "./luatexdir/tex/texfileio.w"

static gzFile gz_fmtfile= NULL;

/*:33*//*34:*/
#line 999 "./luatexdir/tex/texfileio.w"

#if !defined (WORDS_BIGENDIAN) && !defined (NO_DUMP_SHARE)



#  define SWAP(x, y) do { temp =  x; x =  y; y =  temp; } while (0)



static void
swap_items(char*pp,int nitems,int size)
{
char temp;
unsigned total= (unsigned)(nitems*size);
char*q= xmalloc(total);
char*p= q;
memcpy(p,pp,total);


switch(size){


case 16:
while(nitems--){
SWAP(p[0],p[15]);
SWAP(p[1],p[14]);
SWAP(p[2],p[13]);
SWAP(p[3],p[12]);
SWAP(p[4],p[11]);
SWAP(p[5],p[10]);
SWAP(p[6],p[9]);
SWAP(p[7],p[8]);
p+= size;
}
break;

case 12:
while(nitems--){
SWAP(p[0],p[11]);
SWAP(p[1],p[10]);
SWAP(p[2],p[9]);
SWAP(p[3],p[8]);
SWAP(p[4],p[7]);
SWAP(p[5],p[6]);
p+= size;
}
break;

case 8:
while(nitems--){
SWAP(p[0],p[7]);
SWAP(p[1],p[6]);
SWAP(p[2],p[5]);
SWAP(p[3],p[4]);
p+= size;
}
break;

case 4:
while(nitems--){
SWAP(p[0],p[3]);
SWAP(p[1],p[2]);
p+= size;
}
break;

case 2:
while(nitems--){
SWAP(p[0],p[1]);
p+= size;
}
break;

case 1:

break;

default:
FATAL1("Can't swap a %d-byte item for (un)dumping",size);
}
memcpy(pp,q,total);
xfree(q);
}
#endif                          

/*:34*//*35:*/
#line 1087 "./luatexdir/tex/texfileio.w"

void do_zdump(char*p,int item_size,int nitems,FILE*out_file)
{
int err;
(void)out_file;
if(nitems==0)
return;
#if !defined (WORDS_BIGENDIAN) && !defined (NO_DUMP_SHARE)
swap_items(p,nitems,item_size);
#endif
if(gzwrite(gz_fmtfile,(void*)p,(unsigned)(item_size*nitems))!=
item_size*nitems){
fprintf(stderr,"! Could not write %d %d-byte item(s): %s.\n",nitems,
item_size,gzerror(gz_fmtfile,&err));
uexit(1);
}
#if !defined (WORDS_BIGENDIAN) && !defined (NO_DUMP_SHARE)
swap_items(p,nitems,item_size);
#endif
}

/*:35*//*36:*/
#line 1108 "./luatexdir/tex/texfileio.w"

void do_zundump(char*p,int item_size,int nitems,FILE*in_file)
{
int err;
(void)in_file;
if(nitems==0)
return;
if(gzread(gz_fmtfile,(void*)p,(unsigned)(item_size*nitems))<=0){
fprintf(stderr,"Could not undump %d %d-byte item(s): %s.\n",
nitems,item_size,gzerror(gz_fmtfile,&err));
uexit(1);
}
#if !defined (WORDS_BIGENDIAN) && !defined (NO_DUMP_SHARE)
swap_items(p,nitems,item_size);
#endif
}

/*:36*//*37:*/
#line 1125 "./luatexdir/tex/texfileio.w"

#define COMPRESSION "R3"

boolean zopen_w_input(FILE**f,const char*fname,int format,
const_string fopen_mode)
{
int callbackid;
int res;
char*fnam;
callbackid= callback_defined(find_format_file_callback);
if(callbackid> 0){
res= run_callback(callbackid,"S->R",fname,&fnam);
if(res&&fnam&&strlen(fnam)> 0){
*f= fopen(fnam,fopen_mode);
if(*f==NULL){
return 0;
}
}else{
return 0;
}
}else{
res= luatex_open_input(f,fname,format,fopen_mode,true);
}
if(res){
gz_fmtfile= gzdopen(fileno(*f),"rb"COMPRESSION);
}
return res;
}

/*:37*//*38:*/
#line 1154 "./luatexdir/tex/texfileio.w"

boolean zopen_w_output(FILE**f,const char*s,const_string fopen_mode)
{
int res= 1;
if(luainit){
*f= fopen(s,fopen_mode);
if(*f==NULL){
return 0;
}
}else{
res= luatex_open_output(f,s,fopen_mode);
}
if(res){
gz_fmtfile= gzdopen(fileno(*f),"wb"COMPRESSION);
}
return res;
}

/*:38*//*39:*/
#line 1172 "./luatexdir/tex/texfileio.w"

void zwclose(FILE*f)
{
(void)f;
gzclose(gz_fmtfile);
}

/*:39*//*40:*/
#line 1180 "./luatexdir/tex/texfileio.w"

int open_outfile(FILE**f,const char*name,const char*mode)
{
FILE*res;
res= fopen(name,mode);
if(res!=NULL){
*f= res;
return 1;
}
return 0;
}


/*:40*//*41:*/
#line 1194 "./luatexdir/tex/texfileio.w"

int readbinfile(FILE*f,unsigned char**tfm_buffer,int*tfm_size)
{
void*buf;
int size;
if(fseek(f,0,SEEK_END)==0){
size= (int)ftell(f);
if(size> 0){
buf= xmalloc((unsigned)size);
if(fseek(f,0,SEEK_SET)==0){
if(fread((void*)buf,(size_t)size,1,f)==1){
*tfm_buffer= (unsigned char*)buf;
*tfm_size= size;
return 1;
}
}
}else{
*tfm_buffer= NULL;
*tfm_size= 0;
return 1;
}
}
return 0;
}

/*:41*//*42:*/
#line 1224 "./luatexdir/tex/texfileio.w"

static FILE*runpopen(char*cmd,const char*mode)
{
FILE*f= NULL;
char*safecmd= NULL;
char*cmdname= NULL;
int allow;

#ifdef WIN32
char*pp;

for(pp= cmd;*pp;pp++){
if(*pp=='\'')*pp= '"';
}
#endif


if(restrictedshell==0){
allow= 1;
}else{
const char*thecmd= cmd;
allow= shell_cmd_is_allowed(thecmd,&safecmd,&cmdname);
}
if(allow==1)
f= popen(cmd,mode);
else if(allow==2)
f= popen(safecmd,mode);
else if(allow==-1)
fprintf(stderr,"\nrunpopen quotation error in command line: %s\n",
cmd);
else
fprintf(stderr,"\nrunpopen command not allowed: %s\n",cmdname);

if(safecmd)
free(safecmd);
if(cmdname)
free(cmdname);
return f;
}

/*:42*//*44:*/
#line 1271 "./luatexdir/tex/texfileio.w"

#define NUM_PIPES 16
static FILE*pipes[NUM_PIPES];

#ifdef WIN32
FILE*Poptr;
#endif

boolean open_in_or_pipe(FILE**f_ptr,char*fn,int filefmt,
const_string fopen_mode,boolean must_exist)
{
string fname= NULL;
int i;





if(shellenabledp&&*fn=='|'){

*f_ptr= NULL;
fname= (string)xmalloc((unsigned)(strlen(fn)+1));
strcpy(fname,fn);
if(fullnameoffile)
free(fullnameoffile);
fullnameoffile= xstrdup(fname);
recorder_record_input(fname+1);
*f_ptr= runpopen(fname+1,"r");
free(fname);
for(i= 0;i<NUM_PIPES;i++){
if(pipes[i]==NULL){
pipes[i]= *f_ptr;
break;
}
}
if(*f_ptr)
setvbuf(*f_ptr,(char*)NULL,_IONBF,0);
#ifdef WIN32
Poptr= *f_ptr;
#endif

return*f_ptr!=NULL;
}

return luatex_open_input(f_ptr,fn,filefmt,fopen_mode,must_exist);
}


boolean open_out_or_pipe(FILE**f_ptr,char*fn,const_string fopen_mode)
{
string fname;
int i;







if(shellenabledp&&*fn=='|'){

fname= (string)xmalloc((unsigned)(strlen(fn)+1));
strcpy(fname,fn);
if(strchr(fname,' ')==NULL&&strchr(fname,'>')==NULL){


if(STREQ((fname+strlen(fname)-3),"tex"))
*(fname+strlen(fname)-4)= 0;
*f_ptr= runpopen(fname+1,"w");
*(fname+strlen(fname))= '.';
}else{
*f_ptr= runpopen(fname+1,"w");
}
recorder_record_output(fname+1);
free(fname);

for(i= 0;i<NUM_PIPES;i++){
if(pipes[i]==NULL){
pipes[i]= *f_ptr;
break;
}
}

if(*f_ptr)
setvbuf(*f_ptr,(char*)NULL,_IONBF,0);

return*f_ptr!=NULL;
}

return luatex_open_output(f_ptr,fn,fopen_mode);
}


void close_file_or_pipe(FILE*f)
{
int i;

if(shellenabledp){
for(i= 0;i<=15;i++){

if(pipes[i]==f){
if(f){
pclose(f);
#ifdef WIN32
Poptr= NULL;
#endif
}
pipes[i]= NULL;
return;
}
}
}
close_file(f);
}/*:44*/
