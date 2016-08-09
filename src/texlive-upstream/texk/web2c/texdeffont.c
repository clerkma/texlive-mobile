/*1:*/
#line 20 "./luatexdir/tex/texdeffont.w"



#include "ptexlib.h"

/*:1*//*2:*/
#line 30 "./luatexdir/tex/texdeffont.w"

int font_bytes;

void set_cur_font(internal_font_number f)
{
int a= 0;
define(cur_font_loc,data_cmd,f);
}

/*:2*//*3:*/
#line 39 "./luatexdir/tex/texdeffont.w"

static char*scaled_to_string(scaled s)
{
static char result[16];
int n,k;
scaled delta;
k= 0;
if(s<0){
result[k++]= '-';
s= -s;
}
{
int l= 0;
char digs[8]= {0};
n= s/unity;

do{
digs[l++]= (char)(n%10);
n= n/10;;
}while(n> 0);
while(l> 0){
result[k++]= (char)(digs[--l]+'0');
}
}
result[k++]= '.';
s= 10*(s%unity)+5;
delta= 10;
do{
if(delta> unity)
s= s+0100000-050000;
result[k++]= (char)('0'+(s/unity));
s= 10*(s%unity);
delta= delta*10;
}while(s> delta);

result[k]= 0;
return(char*)result;
}

/*:3*//*4:*/
#line 78 "./luatexdir/tex/texdeffont.w"

void tex_def_font(small_number a)
{
pointer u;
internal_font_number f;
str_number t;
int old_setting;
scaled s= -1000;
int natural_dir= -1;
char*fn;
if(job_name==0)
open_log_file();
get_r_token();
u= cur_cs;
if(u>=null_cs)
t= cs_text(u);
else
t= maketexstring("FONT");
if(a>=4){
geq_define(u,set_font_cmd,null_font);
}else{
eq_define(u,set_font_cmd,null_font);
}
scan_optional_equals();

do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));

if(cur_cmd!=left_brace_cmd){
back_input();
scan_file_name();
if(cur_area!=get_nullstr()||cur_ext!=get_nullstr()){


old_setting= selector;
selector= new_string;
if(cur_area!=get_nullstr()){
print(cur_area);
}
if(cur_name!=get_nullstr()){
print(cur_name);
}
if(cur_ext!=get_nullstr()){
print(cur_ext);
}
selector= old_setting;
cur_name= make_string();
cur_ext= get_nullstr();
cur_area= get_nullstr();
}
}else{
back_input();
(void)scan_toks(false,true);
old_setting= selector;
selector= new_string;
token_show(def_ref);
selector= old_setting;
flush_list(def_ref);

cur_name= make_string();
cur_ext= get_nullstr();
cur_area= get_nullstr();
}

name_in_progress= true;
if(scan_keyword("at")){

scan_normal_dimen();
s= cur_val;
if((s<=0)||(s>=01000000000)){
char err[256];
const char*errhelp[]= 
{"I can only handle fonts at positive sizes that are",
"less than 2048pt, so I've changed what you said to 10pt.",
NULL
};
snprintf(err,255,"Improper `at' size (%spt), replaced by 10pt",
scaled_to_string(s));
tex_error(err,errhelp);
s= 10*unity;
}
}else if(scan_keyword("scaled")){
scan_int();
s= -cur_val;
if((cur_val<=0)||(cur_val> 32768)){
char err[256];
const char*errhelp[]= 
{"The magnification ratio must be between 1 and 32768.",
NULL
};
snprintf(err,255,
"Illegal magnification has been changed to 1000 (%d)",
(int)cur_val);
tex_error(err,errhelp);
s= -1000;
}
}
if(scan_keyword("naturaldir")){
scan_direction();
natural_dir= cur_val;
}
name_in_progress= false;
fn= makecstring(cur_name);
f= read_font_info(u,fn,s,natural_dir);
xfree(fn);
equiv(u)= f;

eqtb[font_id_base+f]= eqtb[u];
cs_text(font_id_base+f)= t;
}/*:4*/
