/*1:*/
#line 20 "./luatexdir/tex/expand.w"



#include "ptexlib.h"

/*:1*//*2:*/
#line 43 "./luatexdir/tex/expand.w"

static int expand_depth_count= 0;


/*:2*//*3:*/
#line 59 "./luatexdir/tex/expand.w"

int is_in_csname= 0;

/*:3*//*4:*/
#line 62 "./luatexdir/tex/expand.w"

void expand(void)
{
halfword t;
halfword p;
halfword cur_ptr;
int cv_backup;
int cvl_backup,radix_backup,co_backup;
halfword backup_backup;
int save_scanner_status;
incr(expand_depth_count);
if(expand_depth_count>=expand_depth)
overflow("expansion depth",(unsigned)expand_depth);
cv_backup= cur_val;
cvl_backup= cur_val_level;
radix_backup= radix;
co_backup= cur_order;
backup_backup= token_link(backup_head);
RESWITCH:
if(cur_cmd<call_cmd){

if(int_par(tracing_commands_code)> 1)
show_cur_cmd_chr();
switch(cur_cmd){
case top_bot_mark_cmd:

t= cur_chr%marks_code;
if(cur_chr>=marks_code)
scan_mark_num();
else
cur_val= 0;
switch(t){
case first_mark_code:
cur_ptr= first_mark(cur_val);
break;
case bot_mark_code:
cur_ptr= bot_mark(cur_val);
break;
case split_first_mark_code:
cur_ptr= split_first_mark(cur_val);
break;
case split_bot_mark_code:
cur_ptr= split_bot_mark(cur_val);
break;
default:
cur_ptr= top_mark(cur_val);
break;
}
if(cur_ptr!=null)
begin_token_list(cur_ptr,mark_text);
break;
case expand_after_cmd:
if(cur_chr==0){


get_token();
t= cur_tok;
get_token();
if(cur_cmd> max_command_cmd)
expand();
else
back_input();
cur_tok= t;
back_input();

}else{



get_token();
if((cur_cmd==if_test_cmd)&&(cur_chr!=if_case_code)){
cur_chr= cur_chr+unless_code;
goto RESWITCH;
}
print_err("You can't use `\\unless' before `");
print_cmd_chr((quarterword)cur_cmd,cur_chr);
print_char('\'');
help1("Continue, and I'll forget that it ever happened.");
back_error();
}
break;
case no_expand_cmd:
if(cur_chr==0){










save_scanner_status= scanner_status;
scanner_status= normal;
get_token();
scanner_status= save_scanner_status;
t= cur_tok;
back_input();
if(t>=cs_token_flag){
p= get_avail();
set_token_info(p,cs_token_flag+frozen_dont_expand);
set_token_link(p,iloc);
istart= p;
iloc= p;
}

}else{





















save_scanner_status= scanner_status;
scanner_status= normal;
get_token();
scanner_status= save_scanner_status;
cur_cs= prim_lookup(cs_text(cur_cs));
if(cur_cs!=undefined_primitive){
t= get_prim_eq_type(cur_cs);
if(t> max_command_cmd){
cur_cmd= t;
cur_chr= get_prim_equiv(cur_cs);
cur_tok= token_val(cur_cmd,cur_chr);
cur_cs= 0;
goto RESWITCH;
}else{
back_input();
p= get_avail();
set_token_info(p,cs_token_flag+frozen_primitive);
set_token_link(p,iloc);
iloc= p;
istart= p;
}
}else{
print_err("Missing primitive name");
help2
("The control sequence marked <to be read again> does not",
"represent any known primitive.");
back_error();
}

}
break;
case cs_name_cmd:

if(cur_chr==0){
manufacture_csname(0);
}else if(cur_chr==1){
inject_last_tested_cs();
}else{
manufacture_csname(1);
}
break;
case convert_cmd:
conv_toks();
break;
case the_cmd:
ins_the_toks();
break;
case combine_toks_cmd:
combine_the_toks(cur_chr);
break;
case if_test_cmd:
conditional();
break;
case fi_or_else_cmd:





if(int_par(tracing_ifs_code)> 0)
if(int_par(tracing_commands_code)<=1)
show_cur_cmd_chr();
if(cur_chr> if_limit){
if(if_limit==if_code){
insert_relax();
}else{
print_err("Extra ");
print_cmd_chr(fi_or_else_cmd,cur_chr);
help1("I'm ignoring this; it doesn't match any \\if.");
error();
}
}else{
while(cur_chr!=fi_code)
pass_text();
pop_condition_stack();
}

break;
case input_cmd:

if(cur_chr==1)
force_eof= true;
else if(cur_chr==2)
pseudo_start();
else if(cur_chr==3){
pseudo_start();
iname= 19;
}else if(name_in_progress)
insert_relax();
else
start_input();
break;
case variable_cmd:
do_variable();
break;
case feedback_cmd:
do_feedback();
break;
default:

print_err("Undefined control sequence");
help5("The control sequence at the end of the top line",
"of your error message was never \\def'ed. If you have",
"misspelled it (e.g., `\\hobx'), type `I' and the correct",
"spelling (e.g., `I\\hbox'). Otherwise just continue,",
"and I'll forget about whatever was undefined.");
error();
break;
}
}else if(cur_cmd<end_template_cmd){
macro_call();
}else{







cur_tok= cs_token_flag+frozen_endv;
back_input();

}
cur_val= cv_backup;
cur_val_level= cvl_backup;
radix= radix_backup;
cur_order= co_backup;
set_token_link(backup_head,backup_backup);
decr(expand_depth_count);
}

/*:4*//*5:*/
#line 322 "./luatexdir/tex/expand.w"

void complain_missing_csname(void)
{
print_err("Missing \\endcsname inserted");
help2("The control sequence marked <to be read again> should",
"not appear between \\csname and \\endcsname.");
back_error();
}

/*:5*//*6:*/
#line 331 "./luatexdir/tex/expand.w"

void manufacture_csname(boolean use)
{
halfword p,q,r;
lstring*ss;
r= get_avail();
p= r;
is_in_csname+= 1;
do{
get_x_token();
if(cur_cs==0)
store_new_token(cur_tok);
}while(cur_cs==0);
if(cur_cmd!=end_cs_name_cmd){

complain_missing_csname();
}

ss= tokenlist_to_lstring(r,true);
is_in_csname-= 1;
if(use){
if(ss->l> 0){
cur_cs= string_lookup((char*)ss->s,ss->l);
}else{
cur_cs= null_cs;
}
last_cs_name= cur_cs;
free_lstring(ss);
flush_list(r);
if(cur_cs==null_cs){

}else if(eq_type(cur_cs)==undefined_cs_cmd){

}else{
cur_tok= cur_cs+cs_token_flag;
back_input();
}
}else{
if(ss->l> 0){
no_new_control_sequence= false;
cur_cs= string_lookup((char*)ss->s,ss->l);
no_new_control_sequence= true;
}else{
cur_cs= null_cs;
}
last_cs_name= cur_cs;
free_lstring(ss);
flush_list(r);
if(eq_type(cur_cs)==undefined_cs_cmd){
eq_define(cur_cs,relax_cmd,too_big_char);
};
cur_tok= cur_cs+cs_token_flag;
back_input();
}
}

void inject_last_tested_cs(void)
{
if(last_cs_name!=null_cs){
cur_cs= last_cs_name;
cur_tok= last_cs_name+cs_token_flag;
back_input();
}
}

/*:6*//*7:*/
#line 399 "./luatexdir/tex/expand.w"

void insert_relax(void)
{
cur_tok= cs_token_flag+cur_cs;
back_input();
cur_tok= cs_token_flag+frozen_relax;
back_input();
token_type= inserted;
}


/*:7*//*8:*/
#line 414 "./luatexdir/tex/expand.w"

void get_x_token(void)
{
RESTART:
get_next();
if(cur_cmd<=max_command_cmd)
goto DONE;
if(cur_cmd>=call_cmd){
if(cur_cmd<end_template_cmd){
macro_call();
}else{
cur_cs= frozen_endv;
cur_cmd= endv_cmd;
goto DONE;
}
}else{
expand();
}
goto RESTART;
DONE:
if(cur_cs==0)
cur_tok= token_val(cur_cmd,cur_chr);
else
cur_tok= cs_token_flag+cur_cs;
}


/*:8*//*9:*/
#line 444 "./luatexdir/tex/expand.w"

void x_token(void)
{
while(cur_cmd> max_command_cmd){
expand();
get_next();
}
if(cur_cs==0)
cur_tok= token_val(cur_cmd,cur_chr);
else
cur_tok= cs_token_flag+cur_cs;
}


/*:9*//*10:*/
#line 474 "./luatexdir/tex/expand.w"

halfword top_marks_array[(biggest_mark+1)];
halfword first_marks_array[(biggest_mark+1)];
halfword bot_marks_array[(biggest_mark+1)];
halfword split_first_marks_array[(biggest_mark+1)];
halfword split_bot_marks_array[(biggest_mark+1)];
halfword biggest_used_mark;

/*:10*//*11:*/
#line 482 "./luatexdir/tex/expand.w"

void initialize_marks(void)
{
int i;
biggest_used_mark= 0;
for(i= 0;i<=biggest_mark;i++){
top_mark(i)= null;
first_mark(i)= null;
bot_mark(i)= null;
split_first_mark(i)= null;
split_bot_mark(i)= null;
}
}


/*:11*//*12:*/
#line 509 "./luatexdir/tex/expand.w"

int long_state;

/*:12*//*13:*/
#line 520 "./luatexdir/tex/expand.w"

halfword pstack[9];


/*:13*//*14:*/
#line 537 "./luatexdir/tex/expand.w"

void macro_call(void)
{
halfword r;
halfword p= null;
halfword q;
halfword s;
halfword t;
halfword u,v;
halfword rbrace_ptr= null;
int n= 0;
halfword unbalance;
halfword m= 0;
halfword ref_count;
int save_scanner_status= scanner_status;
halfword save_warning_index= warning_index;
int match_chr= 0;
warning_index= cur_cs;
ref_count= cur_chr;
r= token_link(ref_count);
if(int_par(tracing_macros_code)> 0){

begin_diagnostic();
print_ln();
print_cs(warning_index);
token_show(ref_count);
end_diagnostic(false);
}
if(token_info(r)==protected_token)
r= token_link(r);
if(token_info(r)!=end_match_token){













scanner_status= matching;
unbalance= 0;
long_state= eq_type(cur_cs);
if(long_state>=outer_call_cmd)
long_state= long_state-2;
do{
set_token_link(temp_token_head,null);
if((token_info(r)>=end_match_token)
||(token_info(r)<match_token)){
s= null;
}else{
match_chr= token_info(r)-match_token;
s= token_link(r);
r= s;
p= temp_token_head;
m= 0;
}







CONTINUE:
get_token();
if(cur_tok==token_info(r)){







r= token_link(r);
if((token_info(r)>=match_token)
&&(token_info(r)<=end_match_token)){
if(cur_tok<left_brace_limit)
decr(align_state);
goto FOUND;
}else{
goto CONTINUE;
}

}



















if(s!=r){
if(s==null){

print_err("Use of ");
sprint_cs(warning_index);
tprint(" doesn't match its definition");
help4
("If you say, e.g., `\\def\\a1{...}', then you must always",
"put `1' after `\\a', since control sequence names are",
"made up of letters only. The macro here has not been",
"followed by the required stuff, so I'm ignoring it.");
error();
goto EXIT;

}else{
t= s;
do{
store_new_token(token_info(t));
incr(m);
u= token_link(t);
v= s;
while(1){
if(u==r){
if(cur_tok!=token_info(v)){
goto DONE;
}else{
r= token_link(v);
goto CONTINUE;
}
}
if(token_info(u)!=token_info(v))
goto DONE;
u= token_link(u);
v= token_link(v);
}
DONE:
t= token_link(t);
}while(t!=r);
r= s;
}
}

if(cur_tok==par_token)
if(long_state!=long_call_cmd)
if(!int_par(suppress_long_error_code)){
goto RUNAWAY;
}
if(cur_tok<right_brace_limit){
if(cur_tok<left_brace_limit){

unbalance= 1;
while(1){
fast_store_new_token(cur_tok);
get_token();
if(cur_tok==par_token){
if(long_state!=long_call_cmd){
if(!int_par(suppress_long_error_code)){
goto RUNAWAY;

}
}
}
if(cur_tok<right_brace_limit){
if(cur_tok<left_brace_limit){
incr(unbalance);
}else{
decr(unbalance);
if(unbalance==0)
break;
}
}
}
rbrace_ptr= p;
store_new_token(cur_tok);

}else{

back_input();
print_err("Argument of ");
sprint_cs(warning_index);
tprint(" has an extra }");
help6
("I've run across a `}' that doesn't seem to match anything.",
"For example, `\\def\\a#1{...}' and `\\a}' would produce",
"this error. If you simply proceed now, the `\\par' that",
"I've just inserted will cause me to report a runaway",
"argument that might be the root of the problem. But if",
"your `}' was spurious, just type `2' and it will go away.");
incr(align_state);
long_state= call_cmd;
cur_tok= par_token;
ins_error();
goto CONTINUE;

}
}else{


if(cur_tok==space_token)
if(token_info(r)<=end_match_token)
if(token_info(r)>=match_token)
goto CONTINUE;
store_new_token(cur_tok);

}
incr(m);
if(token_info(r)> end_match_token)
goto CONTINUE;
if(token_info(r)<match_token)
goto CONTINUE;
FOUND:
if(s!=null){



if((m==1)&&(token_info(p)<right_brace_limit)
&&(p!=temp_token_head)){
set_token_link(rbrace_ptr,null);
free_avail(p);
p= token_link(temp_token_head);
pstack[n]= token_link(p);
free_avail(p);
}else{
pstack[n]= token_link(temp_token_head);
}
incr(n);
if(int_par(tracing_macros_code)> 0){
begin_diagnostic();
print_nl(match_chr);
print_int(n);
tprint("<-");
show_token_list(pstack[n-1],null,1000);
end_diagnostic(false);
}

}


}while(token_info(r)!=end_match_token);

}




while((istate==token_list)&&(iloc==null)&&(token_type!=v_template)){

end_token_list();
}
begin_token_list(ref_count,macro);
iname= warning_index;
iloc= token_link(r);
if(n> 0){
if(param_ptr+n> max_param_stack){
max_param_stack= param_ptr+n;
if(max_param_stack> param_size)
overflow("parameter stack size",(unsigned)param_size);
}
for(m= 0;m<=n-1;m++)
param_stack[param_ptr+m]= pstack[m];
param_ptr= param_ptr+n;
}
goto EXIT;
RUNAWAY:


if(long_state==call_cmd){
runaway();
print_err("Paragraph ended before ");
sprint_cs(warning_index);
tprint(" was complete");
help3("I suspect you've forgotten a `}', causing me to apply this",
"control sequence to too much text. How can we recover?",
"My plan is to forget the whole thing and hope for the best.");
back_error();
}
pstack[n]= token_link(temp_token_head);
align_state= align_state-unbalance;
for(m= 0;m<=n;m++)
flush_list(pstack[m]);

EXIT:
scanner_status= save_scanner_status;
warning_index= save_warning_index;
}/*:14*/
