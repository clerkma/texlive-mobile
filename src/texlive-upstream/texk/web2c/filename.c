/*1:*/
#line 20 "./luatexdir/tex/filename.w"



#include "ptexlib.h"


/*:1*//*3:*/
#line 56 "./luatexdir/tex/filename.w"

static void begin_name(void)
{
area_delimiter= 0;
ext_delimiter= 0;
quoted_filename= false;
}

/*:3*//*4:*/
#line 70 "./luatexdir/tex/filename.w"

static boolean more_name(ASCII_code c)
{
if(c==' '&&stop_at_space&&(!quoted_filename)){
return false;
}else if(c=='"'){
quoted_filename= !quoted_filename;
return true;
}else{
str_room(1);
append_char(c);
if(IS_DIR_SEP(c)){
area_delimiter= (pool_pointer)cur_length;
ext_delimiter= 0;
}else if(c=='.')
ext_delimiter= (pool_pointer)cur_length;
return true;
}
}

/*:4*//*5:*/
#line 93 "./luatexdir/tex/filename.w"

static void end_name(void)
{
unsigned char*s;
if(str_ptr+3> (max_strings+STRING_OFFSET))
overflow("number of strings",
(unsigned)(max_strings-init_str_ptr+STRING_OFFSET));

if(area_delimiter==0){
cur_area= get_nullstr();
}else{
s= (unsigned char*)xstrdup((char*)(cur_string+area_delimiter));
cur_string[area_delimiter]= '\0';
cur_length= (unsigned)strlen((char*)cur_string);
cur_area= make_string();
xfree(cur_string);
cur_length= (unsigned)strlen((char*)s);
cur_string= s;
}
if(ext_delimiter==0){
cur_name= make_string();
cur_ext= get_nullstr();
}else{
int l= (ext_delimiter-area_delimiter-1);
s= (unsigned char*)xstrdup((char*)(cur_string+l));
cur_string[l]= '\0';
cur_length= (unsigned)strlen((char*)cur_string);
cur_name= make_string();
xfree(cur_string);
cur_length= (unsigned)strlen((char*)s);
cur_string= s;
cur_ext= make_string();
}
}

/*:5*//*6:*/
#line 132 "./luatexdir/tex/filename.w"

void scan_file_name(void)
{
str_number u= 0;
name_in_progress= true;
begin_name();

do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));

while(true){
if((cur_cmd> other_char_cmd)||(cur_chr> biggest_char)){
back_input();
break;
}



if((cur_chr==' ')&&(istate!=token_list)&&(iloc> ilimit)
&&!quoted_filename)
break;
if(cur_chr> 127){
unsigned char*bytes;
unsigned char*thebytes;
thebytes= uni2str((unsigned)cur_chr);
bytes= thebytes;
while(*bytes){
if(!more_name(*bytes))
break;
bytes++;
}
xfree(thebytes);
}else{
if(!more_name(cur_chr))
break;
}
u= save_cur_string();
get_x_token();
restore_cur_string(u);
}
end_name();
name_in_progress= false;
}

/*:6*//*7:*/
#line 178 "./luatexdir/tex/filename.w"

void scan_file_name_toks(void)
{
char*a,*n,*e,*s= NULL;
int i,l= 0;
(void)scan_toks(false,true);
s= tokenlist_to_cstring(def_ref,true,&l);
a= n= s;
e= NULL;
for(i= 0;i<l;i++){
if(IS_DIR_SEP(s[i])){
n= s+i+1;
e= NULL;
}else if(s[i]=='.'){
e= s+i;
}
}
if(n!=s){
cur_area= maketexlstring(a,(size_t)(n-a));
}else{
cur_area= get_nullstr();
}
if(e!=NULL){
cur_name= maketexlstring(n,(size_t)(e-n));
cur_ext= maketexstring(e);
}else{
cur_name= maketexstring(n);
cur_ext= get_nullstr();
}
xfree(s);

}




/*:7*//*8:*/
#line 218 "./luatexdir/tex/filename.w"

char*pack_job_name(const char*s)
{
cur_area= get_nullstr();
cur_ext= maketexstring(s);
cur_name= job_name;
return pack_file_name(cur_name,cur_area,cur_ext);
}

/*:8*//*9:*/
#line 234 "./luatexdir/tex/filename.w"

char*prompt_file_name(const char*s,const char*e)
{
int k;
str_number saved_cur_name;
int callback_id;
char prompt[256];
char*ar,*na,*ex;
saved_cur_name= cur_name;
if(interaction==scroll_mode){
wake_up_terminal();
}
ar= makecstring(cur_area);
na= makecstring(cur_name);
ex= makecstring(cur_ext);
if(strcmp(s,"input file name")==0){
snprintf(prompt,255,"I can't find file `%s%s%s'.",ar,na,ex);
}else{
snprintf(prompt,255,"I can't write on file `%s%s%s'.",ar,na,ex);
}
free(ar);
free(na);
free(ex);
print_err(prompt);
callback_id= callback_defined(show_error_hook_callback);
if(callback_id> 0){
flush_err();
run_callback(callback_id,"->");
}else{
if((strcmp(e,".tex")==0)||(strcmp(e,"")==0))
show_context();
if(strcmp(s,"input file name")==0)
tprint_nl(promptfilenamehelpmsg")");
}
tprint_nl("Please type another ");
tprint(s);
if(interaction<scroll_mode)
fatal_error("*** (job aborted, file error in nonstop mode)");
clear_terminal();
prompt_input(": ");
begin_name();
k= first;
while((buffer[k]==' ')&&(k<last))
k++;
while(true){
if(k==last)
break;
if(!more_name(buffer[k]))
break;
k++;
}
end_name();
if(cur_ext==get_nullstr())
cur_ext= maketexstring(e);
if(str_length(cur_name)==0)
cur_name= saved_cur_name;
return pack_file_name(cur_name,cur_area,cur_ext);
}


/*:9*//*10:*/
#line 294 "./luatexdir/tex/filename.w"

void tprint_file_name(unsigned char*n,unsigned char*a,unsigned char*e)
{
boolean must_quote;
unsigned char*j;
must_quote= false;
if(a!=NULL){
j= a;
while((!must_quote)&&(*j)){
must_quote= (*j==' ');
j++;
}
}
if(n!=NULL){
j= n;
while((!must_quote)&&(*j)){
must_quote= (*j==' ');
j++;
}
}
if(e!=NULL){
j= e;
while((!must_quote)&&(*j)){
must_quote= (*j==' ');
j++;
}
}







if(must_quote)
print_char('"');
if(a!=NULL){
for(j= a;*j;j++)
if(*j!='"')
print_char(*j);
}
if(n!=NULL){
for(j= n;*j;j++)
if(*j!='"')
print_char(*j);
}
if(e!=NULL){
for(j= e;*j;j++)
if(*j!='"')
print_char(*j);
}
if(must_quote)
print_char('"');
}

/*:10*//*11:*/
#line 349 "./luatexdir/tex/filename.w"

void print_file_name(str_number n,str_number a,str_number e)
{
char*nam,*are,*ext;
nam= makecstring(n);
are= makecstring(a);
ext= makecstring(e);
tprint_file_name((unsigned char*)nam,(unsigned char*)are,
(unsigned char*)ext);
free(nam);
free(are);
free(ext);
}/*:11*/
