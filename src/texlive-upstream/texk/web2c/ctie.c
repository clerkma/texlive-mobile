#define version_number "1.1"
#define banner "This is CTIE, Version 1.1"
#define copyright  \
"Copyright 2002,2003 Julian Gilbey.  All rights reserved.  There is no warranty.\n\
Run with the --version option for other important information." \
 \

#define kpse_find_cweb(name) kpse_find_file(name,kpse_cweb_format,true)  \

#define buf_size 1024
#define max_file_index 32 \

#define xisupper(c) (isupper((unsigned char) c) &&((unsigned char) c<0200) )  \
 \

#define spotless 0
#define troublesome 1
#define fatal 2 \

#define max_include_files 20 \

#define max_file_name_length 1024 \

#define too_long() {total_include_files--;free(new_inc) ; \
err_print(i,"! Include file name too long") ;goto restart;} \

#define fatal_error(i,s,t) { \
fprintf(stderr,"\n%s",s) ; \
err_print(i,t) ; \
history= fatal; \
exit(wrap_up() ) ; \
} \
 \

#define none (-1)  \

/*2:*/
#line 89 "./ctiedir/ctie.w"

/*10:*/
#line 172 "./ctiedir/ctie.w"

#line 123 "./ctiedir/ctie-k.ch"
#include <kpathsea/kpathsea.h> 
#include <stdio.h> 
#line 174 "./ctiedir/ctie.w"


#line 139 "./ctiedir/ctie-k.ch"
/*:10*//*39:*/
#line 715 "./ctiedir/ctie.w"

#include <errno.h> 


/*:39*/
#line 90 "./ctiedir/ctie.w"

/*12:*/
#line 211 "./ctiedir/ctie.w"

#define search 0
#define test 1
#define reading 2
#define ignore 3
typedef int in_file_modes;
#define unknown 0
#define master 1
#define chf 2
typedef int file_types;


/*:12*//*13:*/
#line 229 "./ctiedir/ctie.w"

#define normal 0
#define pre 1
#define post 2
typedef int out_md_type;


/*:13*//*14:*/
#line 239 "./ctiedir/ctie.w"

typedef int file_index;


/*:14*//*15:*/
#line 246 "./ctiedir/ctie.w"

typedef struct _indsc{
char file_name[max_file_name_length];
long line;
FILE*the_file;
struct _indsc*parent;
}include_description;


/*:15*//*16:*/
#line 259 "./ctiedir/ctie.w"

typedef struct _idsc{
string file_name;
char buffer[buf_size];
in_file_modes mode;
long line;
file_types type_of_file;
include_description*current_include;
char*buffer_end;
char*limit;
char*loc;
FILE*the_file;
int dont_match;
}input_description;


/*:16*/
#line 91 "./ctiedir/ctie.w"

/*30:*/
#line 584 "./ctiedir/ctie.w"

#line 251 "./ctiedir/ctie-k.ch"
void err_print(file_index,const char*);
#line 586 "./ctiedir/ctie.w"

/*:30*//*35:*/
#line 673 "./ctiedir/ctie.w"

#line 271 "./ctiedir/ctie-k.ch"
int wrap_up(void);
#line 675 "./ctiedir/ctie.w"

/*:35*//*37:*/
#line 696 "./ctiedir/ctie.w"

#line 277 "./ctiedir/ctie-k.ch"
void pfatal_error(const char*,const char*);
#line 698 "./ctiedir/ctie.w"

/*:37*//*69:*/
#line 1232 "./ctiedir/ctie.w"

#line 451 "./ctiedir/ctie-k.ch"
static void usage_help(void);
static void print_version_and_exit(const_string,const_string);
#line 1235 "./ctiedir/ctie.w"


/*:69*/
#line 92 "./ctiedir/ctie.w"

/*9:*/
#line 162 "./ctiedir/ctie.w"

int history= spotless;


/*:9*//*17:*/
#line 286 "./ctiedir/ctie.w"

int total_include_files= 0;

/*:17*//*18:*/
#line 292 "./ctiedir/ctie.w"

file_index actual_input,test_input,no_ch;
file_types prod_chf= unknown;
out_md_type out_mode;

/*:18*//*20:*/
#line 309 "./ctiedir/ctie.w"

input_description*input_organisation[max_file_index+1];


/*:20*//*24:*/
#line 406 "./ctiedir/ctie.w"

boolean input_has_ended= false;


/*:24*//*41:*/
#line 742 "./ctiedir/ctie.w"

FILE*out_file;
string out_name;


#line 307 "./ctiedir/ctie-k.ch"
/*:41*//*68:*/
#line 1217 "./ctiedir/ctie.w"

#line 443 "./ctiedir/ctie-k.ch"
const_string CTIEHELP[]= {
"Usage: ctie -m|-c outfile master changefile(s)",
#line 1220 "./ctiedir/ctie.w"
"  Create a new master file or change file from the given",
"  master (C)WEB file and changefiles.",
"  All filenames are taken literally; no suffixes are added.",
"",
"-m  create a new master file from original (C)WEB and change file(s)",
"-c  create a master change file for original (C)WEB file from changefile(s)",
"--help      display this help and exit",
"--version   display version information and exit",
NULL
};


/*:68*/
#line 93 "./ctiedir/ctie.w"

/*31:*/
#line 589 "./ctiedir/ctie.w"

#line 258 "./ctiedir/ctie-k.ch"
void err_print(file_index i,const char*s)

#line 592 "./ctiedir/ctie.w"
{
char*k,*l;
fprintf(stderr,*s=='!'?"\n%s":"%s",s);
if(i>=0)/*32:*/
#line 611 "./ctiedir/ctie.w"

{
register input_description*inp_desc= input_organisation[i];
register include_description*inc_desc= inp_desc->current_include;

if(inc_desc!=NULL){
fprintf(stderr,". (l. %ld of include file %s",inc_desc->line,
inc_desc->file_name);
fprintf(stderr," included from l. %ld of %s file %s)\n",
inp_desc->line,
inp_desc->type_of_file==master?"master":"change",
inp_desc->file_name);
}
else
fprintf(stderr,". (l. %ld of %s file %s)\n",inp_desc->line,
inp_desc->type_of_file==master?"master":"change",
inp_desc->file_name);
l= (inp_desc->loc>=inp_desc->limit?inp_desc->limit:inp_desc->loc);
if(l> inp_desc->buffer){
for(k= inp_desc->buffer;k<l;k++)
if(*k=='\t')putc(' ',stderr);
else putc(*k,stderr);
putc('\n',stderr);
for(k= inp_desc->buffer;k<l;k++)
putc(' ',stderr);
}
for(k= l;k<inp_desc->limit;k++)
putc(*k,stderr);
putc('\n',stderr);
}


/*:32*/
#line 595 "./ctiedir/ctie.w"

else putc('\n',stderr);
fflush(stderr);
history= troublesome;
}

/*:31*//*38:*/
#line 699 "./ctiedir/ctie.w"

#line 284 "./ctiedir/ctie-k.ch"
void pfatal_error(const char*s,const char*t)
#line 702 "./ctiedir/ctie.w"
{
char*strerr= strerror(errno);

fprintf(stderr,"\n%s%s",s,t);
if(strerr)fprintf(stderr," (%s)\n",strerr);
else fprintf(stderr,"\n");
history= fatal;
exit(wrap_up());
}


/*:38*/
#line 94 "./ctiedir/ctie.w"

/*21:*/
#line 328 "./ctiedir/ctie.w"

#line 156 "./ctiedir/ctie-k.ch"
static boolean
get_line(file_index i,boolean do_includes)
#line 331 "./ctiedir/ctie.w"
{
register input_description*inp_desc= input_organisation[i];
register FILE*fp;

if(inp_desc->mode==ignore)return false;

restart:
if(inp_desc->current_include!=NULL){
register include_description*inc_desc= inp_desc->current_include;

fp= inc_desc->the_file;
/*26:*/
#line 426 "./ctiedir/ctie.w"

{
register int c;
register char*k;

if(feof(fp))
/*27:*/
#line 452 "./ctiedir/ctie.w"

{
include_description*temp= inc_desc->parent;

fclose(fp);
free(inc_desc);
total_include_files--;
inp_desc->current_include= temp;
goto restart;
}


/*:27*/
#line 432 "./ctiedir/ctie.w"


inp_desc->limit= k= inp_desc->buffer;
while(k<=inp_desc->buffer_end&&(c= getc(fp))!=EOF&&c!='\n')
#line 171 "./ctiedir/ctie-k.ch"
if((*(k++)= c)!=' '&&c!='\r')inp_desc->limit= k;
#line 437 "./ctiedir/ctie.w"
if(k> inp_desc->buffer_end)
if((c= getc(fp))!=EOF&&c!='\n'){
ungetc(c,fp);inp_desc->loc= inp_desc->buffer;
err_print(i,"! Input line too long");

}
if(c==EOF&&inp_desc->limit==inp_desc->buffer)
/*27:*/
#line 452 "./ctiedir/ctie.w"

{
include_description*temp= inc_desc->parent;

fclose(fp);
free(inc_desc);
total_include_files--;
inp_desc->current_include= temp;
goto restart;
}


/*:27*/
#line 444 "./ctiedir/ctie.w"


inc_desc->line++;
}

/*:26*/
#line 342 "./ctiedir/ctie.w"

}
else{
fp= inp_desc->the_file;
/*22:*/
#line 366 "./ctiedir/ctie.w"

{
register int c;
register char*k;

if(feof(fp))
/*23:*/
#line 394 "./ctiedir/ctie.w"

{
inp_desc->mode= ignore;
inp_desc->limit= NULL;
if(inp_desc->type_of_file==master)input_has_ended= true;
fclose(fp);
return false;
}


/*:23*/
#line 372 "./ctiedir/ctie.w"


inp_desc->limit= k= inp_desc->buffer;
while(k<=inp_desc->buffer_end&&(c= getc(fp))!=EOF&&c!='\n')
#line 165 "./ctiedir/ctie-k.ch"
if((*(k++)= c)!=' '&&c!='\r')inp_desc->limit= k;
#line 377 "./ctiedir/ctie.w"
if(k> inp_desc->buffer_end)
if((c= getc(fp))!=EOF&&c!='\n'){
ungetc(c,fp);inp_desc->loc= inp_desc->buffer;
err_print(i,"! Input line too long");

}
if(c==EOF&&inp_desc->limit==inp_desc->buffer)
/*23:*/
#line 394 "./ctiedir/ctie.w"

{
inp_desc->mode= ignore;
inp_desc->limit= NULL;
if(inp_desc->type_of_file==master)input_has_ended= true;
fclose(fp);
return false;
}


/*:23*/
#line 384 "./ctiedir/ctie.w"


/*25:*/
#line 414 "./ctiedir/ctie.w"

inp_desc->line++;
if(inp_desc->type_of_file==master&&inp_desc->line%100==0){
if(inp_desc->line%500==0)printf("%ld",inp_desc->line);
else putchar('.');
fflush(stdout);
}


/*:25*/
#line 387 "./ctiedir/ctie.w"

}


/*:22*/
#line 346 "./ctiedir/ctie.w"

}

if(do_includes)
/*28:*/
#line 467 "./ctiedir/ctie.w"

{
inp_desc->loc= inp_desc->buffer;
*inp_desc->limit= ' ';
if(*inp_desc->buffer=='@'&&
(inp_desc->buffer[1]=='i'||inp_desc->buffer[1]=='I')){
inp_desc->loc= inp_desc->buffer+2;
*inp_desc->limit= '"';
while(*inp_desc->loc==' '||*inp_desc->loc=='\t')
inp_desc->loc++;
if(inp_desc->loc>=inp_desc->limit){
err_print(i,"! Include file name not given");

goto restart;
}
if(total_include_files>=max_include_files){
err_print(i,"! Too many nested includes");

goto restart;
}
total_include_files++;
/*29:*/
#line 507 "./ctiedir/ctie.w"

{
include_description*new_inc;
#line 194 "./ctiedir/ctie-k.ch"
char*file_name_end;
string fullname;
char*k;
#line 514 "./ctiedir/ctie.w"

new_inc= (include_description*)malloc(sizeof(include_description));
if(new_inc==NULL)
fatal_error(i,"! No memory for new include descriptor","");
new_inc->line= 0;
k= new_inc->file_name;
file_name_end= k+max_file_name_length-1;

if(*inp_desc->loc=='"'){
inp_desc->loc++;
while(*inp_desc->loc!='"'&&k<=file_name_end)
*k++= *inp_desc->loc++;
if(inp_desc->loc==inp_desc->limit)
k= file_name_end+1;
}else
while(*inp_desc->loc!=' '&&*inp_desc->loc!='\t'&&
*inp_desc->loc!='"'&&k<=file_name_end)*k++= *inp_desc->loc++;
if(k> file_name_end)too_long();

*k= '\0';
#line 202 "./ctiedir/ctie-k.ch"
fullname= kpse_find_cweb(new_inc->file_name);
if(fullname)
new_inc->the_file= fopen(fullname,"r");
if(fullname!=NULL&&new_inc->the_file!=NULL){
free(fullname);
#line 535 "./ctiedir/ctie.w"
new_inc->parent= inp_desc->current_include;
inp_desc->current_include= new_inc;
goto restart;
}
#line 563 "./ctiedir/ctie.w"
total_include_files--;
free(new_inc);
#line 240 "./ctiedir/ctie-k.ch"
if(fullname){
free(fullname);
err_print(i,"! Cannot open include file");
}else
err_print(i,"! Cannot find include file");
#line 566 "./ctiedir/ctie.w"

goto restart;
}



/*:29*/
#line 488 "./ctiedir/ctie.w"
;
}
}


/*:28*/
#line 351 "./ctiedir/ctie.w"

return true;
}


/*:21*//*34:*/
#line 663 "./ctiedir/ctie.w"

#line 265 "./ctiedir/ctie-k.ch"
int wrap_up(void)
#line 665 "./ctiedir/ctie.w"
{
/*36:*/
#line 682 "./ctiedir/ctie.w"

switch(history){
case spotless:
printf("\n(No errors were found.)\n");break;
case troublesome:
printf("\n(Pardon me, but I think I spotted something wrong.)\n");break;
case fatal:printf("(That was a fatal error, my friend.)\n");
}


/*:36*/
#line 666 "./ctiedir/ctie.w"
;
if(history> spotless)return 1;
else return 0;
}

/*:34*//*44:*/
#line 791 "./ctiedir/ctie.w"

#line 376 "./ctiedir/ctie-k.ch"
static boolean
lines_dont_match(file_index i,file_index j)
#line 794 "./ctiedir/ctie.w"
{
register input_description*iptr= input_organisation[i],
*jptr= input_organisation[j];

if(iptr->limit-iptr->buffer!=jptr->limit-jptr->buffer)
return true;
return strncmp(iptr->buffer,jptr->buffer,iptr->limit-iptr->buffer);
}


/*:44*//*45:*/
#line 808 "./ctiedir/ctie.w"

#line 384 "./ctiedir/ctie-k.ch"
static void
init_change_file(file_index i)
#line 811 "./ctiedir/ctie.w"
{
register input_description*inp_desc= input_organisation[i];
char ccode;

inp_desc->limit= inp_desc->buffer;
/*46:*/
#line 827 "./ctiedir/ctie.w"

while(1){
if(!get_line(i,false))return;
if(inp_desc->limit<inp_desc->buffer+2)continue;
if(inp_desc->buffer[0]!='@')continue;
ccode= inp_desc->buffer[1];
#line 391 "./ctiedir/ctie-k.ch"
if(xisupper(ccode))ccode= tolower((unsigned char)ccode);
#line 834 "./ctiedir/ctie.w"
if(ccode=='x')break;
if(ccode=='y'||ccode=='z'||ccode=='i'){
inp_desc->loc= inp_desc->buffer+2;
err_print(i,"! Missing @x in change file");

}
}

/*:46*/
#line 816 "./ctiedir/ctie.w"

/*47:*/
#line 844 "./ctiedir/ctie.w"

do{
if(!get_line(i,true)){
err_print(i,"! Change file ended after @x");

return;
}
}while(inp_desc->limit==inp_desc->buffer);


/*:47*/
#line 817 "./ctiedir/ctie.w"

inp_desc->dont_match= 0;
}


/*:45*//*48:*/
#line 857 "./ctiedir/ctie.w"

#line 398 "./ctiedir/ctie-k.ch"
static void
put_line(file_index j)
#line 860 "./ctiedir/ctie.w"
{
char*ptr= input_organisation[j]->buffer;
char*lmt= input_organisation[j]->limit;

while(ptr<lmt)putc(*ptr++,out_file);
putc('\n',out_file);
}


/*:48*//*49:*/
#line 872 "./ctiedir/ctie.w"

#line 406 "./ctiedir/ctie-k.ch"
static boolean
e_of_ch_module(file_index i)
#line 875 "./ctiedir/ctie.w"
{
register input_description*inp_desc= input_organisation[i];

if(inp_desc->limit==NULL){
err_print(i,"! Change file ended without @z");

return true;
}else if(inp_desc->limit>=inp_desc->buffer+2)
if(inp_desc->buffer[0]=='@'&&
(inp_desc->buffer[1]=='Z'||inp_desc->buffer[1]=='z'))
return true;
return false;
}


/*:49*//*50:*/
#line 893 "./ctiedir/ctie.w"

#line 414 "./ctiedir/ctie-k.ch"
static boolean
e_of_ch_preamble(file_index i)
#line 896 "./ctiedir/ctie.w"
{
register input_description*inp_desc= input_organisation[i];

if(inp_desc->limit>=inp_desc->buffer+2&&inp_desc->buffer[0]=='@')
if(inp_desc->buffer[1]=='Y'||inp_desc->buffer[1]=='y'){
if(inp_desc->dont_match> 0){
inp_desc->loc= inp_desc->buffer+2;
fprintf(stderr,"\n! Hmm... %d ",inp_desc->dont_match);
err_print(i,"of the preceding lines failed to match");
}
return true;
}
return false;
}



/*:50*//*61:*/
#line 1105 "./ctiedir/ctie.w"

#line 424 "./ctiedir/ctie-k.ch"
static void
usage_error(void)
{
/*62:*/
#line 1118 "./ctiedir/ctie.w"

#line 434 "./ctiedir/ctie-k.ch"
{
printf("%s (%s)\n",banner,kpathsea_version_string);
}
#line 1120 "./ctiedir/ctie.w"
printf("%s\n",copyright);


/*:62*/
#line 427 "./ctiedir/ctie-k.ch"
;
fprintf(stderr,"Usage: ctie -m|-c outfile master changefile(s)\n");
#line 1110 "./ctiedir/ctie.w"
fprintf(stderr,"Type ctie --help for more information\n");
exit(1);
}


/*:61*/
#line 95 "./ctiedir/ctie.w"

/*3:*/
#line 101 "./ctiedir/ctie.w"

#line 32 "./ctiedir/ctie-k.ch"
int main(int argc,string*argv)
#line 104 "./ctiedir/ctie.w"
{
#line 38 "./ctiedir/ctie-k.ch"
/*5:*/
#line 84 "./ctiedir/ctie-k.ch"

kpse_set_program_name(argv[0],"ctie");

/*:5*/
#line 38 "./ctiedir/ctie-k.ch"
;
/*19:*/
#line 300 "./ctiedir/ctie.w"

actual_input= 0;
out_mode= normal;

/*:19*/
#line 39 "./ctiedir/ctie-k.ch"
;
#line 106 "./ctiedir/ctie.w"
/*63:*/
#line 1135 "./ctiedir/ctie.w"

{
if(argc> max_file_index+5-1)usage_error();
no_ch= -1;
while(--argc> 0){
argv++;
if(strcmp("-help",*argv)==0||strcmp("--help",*argv)==0)
/*66:*/
#line 1202 "./ctiedir/ctie.w"

usage_help();



/*:66*/
#line 1142 "./ctiedir/ctie.w"
;
if(strcmp("-version",*argv)==0||strcmp("--version",*argv)==0)
/*67:*/
#line 1208 "./ctiedir/ctie.w"

{
print_version_and_exit("CTIE",version_number);

}


/*:67*/
#line 1144 "./ctiedir/ctie.w"
;
if(**argv=='-')/*64:*/
#line 1158 "./ctiedir/ctie.w"

if(prod_chf!=unknown)usage_error();
else
switch(*(*argv+1)){
case'c':case'C':prod_chf= chf;break;
case'm':case'M':prod_chf= master;break;
default:usage_error();
}


/*:64*/
#line 1145 "./ctiedir/ctie.w"

else/*65:*/
#line 1172 "./ctiedir/ctie.w"

{
if(no_ch==(-1)){
out_name= *argv;
}else{
register input_description*inp_desc;

inp_desc= (input_description*)malloc(sizeof(input_description));
if(inp_desc==NULL)
fatal_error(-1,"! No memory for input descriptor","");

inp_desc->mode= search;
inp_desc->line= 0;
inp_desc->type_of_file= chf;
inp_desc->limit= inp_desc->buffer;
inp_desc->buffer[0]= ' ';
inp_desc->loc= inp_desc->buffer+1;
inp_desc->buffer_end= inp_desc->buffer+buf_size-2;
inp_desc->file_name= *argv;
inp_desc->current_include= NULL;
input_organisation[no_ch]= inp_desc;
}
no_ch++;
}


/*:65*/
#line 1146 "./ctiedir/ctie.w"

}
if(no_ch<=0||prod_chf==unknown)usage_error();
}


/*:63*/
#line 106 "./ctiedir/ctie.w"

/*62:*/
#line 1118 "./ctiedir/ctie.w"

#line 434 "./ctiedir/ctie-k.ch"
{
printf("%s (%s)\n",banner,kpathsea_version_string);
}
#line 1120 "./ctiedir/ctie.w"
printf("%s\n",copyright);


/*:62*/
#line 107 "./ctiedir/ctie.w"
;
/*42:*/
#line 311 "./ctiedir/ctie-k.ch"

{
string fullname;

fullname= kpse_find_cweb(input_organisation[0]->file_name);
if(fullname)
input_organisation[0]->the_file= fopen(fullname,"r");

if(fullname==NULL||input_organisation[0]->the_file==NULL){
if(fullname){
pfatal_error("! Cannot open master file ",
input_organisation[0]->file_name);
}else{
fatal_error(-1,"! Cannot find master file ",
input_organisation[0]->file_name);
}
}
else free(fullname);


#line 759 "./ctiedir/ctie.w"
printf("(%s)\n",input_organisation[0]->file_name);
input_organisation[0]->type_of_file= master;
get_line(0,true);
}


/*:42*/
#line 108 "./ctiedir/ctie.w"

/*43:*/
#line 347 "./ctiedir/ctie-k.ch"

{
file_index i;
string fullname;

i= 1;
while(i<no_ch){
fullname= kpse_find_cweb(input_organisation[i]->file_name);
if(fullname)
input_organisation[i]->the_file= fopen(fullname,"r");

if(fullname==NULL||input_organisation[i]->the_file==NULL){
if(fullname){
pfatal_error("! Cannot open change file ",
input_organisation[i]->file_name);
}else{
fatal_error(-1,"! Cannot find change file ",
input_organisation[i]->file_name);
}
}
else free(fullname);


#line 780 "./ctiedir/ctie.w"
printf("(%s)\n",input_organisation[i]->file_name);
init_change_file(i);
i++;
}
}


/*:43*/
#line 109 "./ctiedir/ctie.w"

/*40:*/
#line 729 "./ctiedir/ctie.w"

{
#line 290 "./ctiedir/ctie-k.ch"
out_file= fopen(out_name,"wb");
#line 732 "./ctiedir/ctie.w"
if(out_file==NULL){
pfatal_error("! Cannot open/create output file","");

}
}


/*:40*/
#line 110 "./ctiedir/ctie.w"

/*59:*/
#line 1074 "./ctiedir/ctie.w"

actual_input= 0;
input_has_ended= false;
while(input_has_ended==false||actual_input!=0)
/*51:*/
#line 917 "./ctiedir/ctie.w"

{
file_index test_file;

/*52:*/
#line 934 "./ctiedir/ctie.w"

{
register input_description*inp_desc;
while(actual_input> 0&&e_of_ch_module(actual_input)){
inp_desc= input_organisation[actual_input];
if(inp_desc->type_of_file==master){

fatal_error(-1,"! This can't happen: change file is master file","");

}
inp_desc->mode= search;
init_change_file(actual_input);
while((input_organisation[actual_input]->mode!=reading
&&actual_input> 0))
actual_input--;
}
}


/*:52*/
#line 921 "./ctiedir/ctie.w"

if(input_has_ended&&actual_input==0)break;
/*53:*/
#line 960 "./ctiedir/ctie.w"

test_input= none;
test_file= actual_input;
while(test_input==none&&test_file<no_ch-1){
test_file++;
switch(input_organisation[test_file]->mode){
case search:
if(lines_dont_match(actual_input,test_file)==false){
input_organisation[test_file]->mode= test;
test_input= test_file;
}
break;
case test:
if(lines_dont_match(actual_input,test_file)){

input_organisation[test_file]->dont_match++;
}
test_input= test_file;
break;
case reading:
break;
case ignore:
break;
}
}


/*:53*/
#line 923 "./ctiedir/ctie.w"

/*54:*/
#line 993 "./ctiedir/ctie.w"

if(prod_chf==chf){
while(1){
/*55:*/
#line 1007 "./ctiedir/ctie.w"

if(out_mode==normal){
if(test_input!=none){
fprintf(out_file,"@x\n");
out_mode= pre;
}else break;
}


/*:55*/
#line 996 "./ctiedir/ctie.w"

/*56:*/
#line 1021 "./ctiedir/ctie.w"

if(out_mode==pre){
if(test_input==none){
fprintf(out_file,"@y\n");
out_mode= post;
}else{
if(input_organisation[actual_input]->type_of_file==master)
put_line(actual_input);
break;
}
}


/*:56*/
#line 997 "./ctiedir/ctie.w"

/*57:*/
#line 1040 "./ctiedir/ctie.w"

if(out_mode==post){
if(input_organisation[actual_input]->type_of_file==chf){
if(test_input==none)put_line(actual_input);
break;
}else{
fprintf(out_file,"@z\n\n");
out_mode= normal;
}
}


/*:57*/
#line 998 "./ctiedir/ctie.w"

}
}else
if(test_input==none)put_line(actual_input);


/*:54*/
#line 924 "./ctiedir/ctie.w"

/*58:*/
#line 1055 "./ctiedir/ctie.w"

get_line(actual_input,true);
if(test_input!=none){
get_line(test_input,true);
if(e_of_ch_preamble(test_input)==true){
get_line(test_input,true);
input_organisation[test_input]->mode= reading;
actual_input= test_input;
test_input= none;
}
}


/*:58*/
#line 925 "./ctiedir/ctie.w"

}


/*:51*/
#line 1078 "./ctiedir/ctie.w"

if(out_mode==post)
fprintf(out_file,"@z\n");


/*:59*/
#line 111 "./ctiedir/ctie.w"

/*60:*/
#line 1087 "./ctiedir/ctie.w"

{
file_index i;

for(i= 1;i<no_ch;i++){
if(input_organisation[i]->mode!=ignore){
input_organisation[i]->loc= input_organisation[i]->buffer;
err_print(i,"! Change file entry did not match");

}
}
}


/*:60*/
#line 112 "./ctiedir/ctie.w"

exit(wrap_up());
}

#line 57 "./ctiedir/ctie-k.ch"
/*:3*/
#line 96 "./ctiedir/ctie.w"


/*:2*//*70:*/
#line 1237 "./ctiedir/ctie.w"

#line 460 "./ctiedir/ctie-k.ch"
static void
usage_help(void)
{
const_string*message= CTIEHELP;
#line 1241 "./ctiedir/ctie.w"

while(*message){
fputs(*message,stdout);
putchar('\n');
++message;
}
putchar('\n');
exit(0);
}


/*:70*//*71:*/
#line 1252 "./ctiedir/ctie.w"

#line 480 "./ctiedir/ctie-k.ch"
static void
print_version_and_exit(const_string name,const_string version)
{
printf("%s %s\n",name,version);
puts(kpathsea_version_string);

puts("Copyright (C) 2002,2003 Julian Gilbey.");
puts("Kpathsea is copyright (C) 1999 Free Software Foundation, Inc.");

puts("There is NO warranty.  This is free software.");
puts("Redistribution of this software is covered by the terms of");
puts("both the CTIE copyright and the GNU General Public Licence.");
puts("For more information about these matters, see the files");
puts("named COPYING and the CTIE source.");
puts("Primary authors of CTIE: Julian Gilbey.");
puts("Kpathsea written by Karl Berry and others.\n");

exit(0);
}
#line 1265 "./ctiedir/ctie.w"


#line 514 "./ctiedir/ctie-k.ch"
/*:71*/
