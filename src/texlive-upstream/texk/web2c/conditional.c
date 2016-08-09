/*1:*/
#line 20 "./luatexdir/tex/conditional.w"


#include "ptexlib.h"

/*:1*//*3:*/
#line 42 "./luatexdir/tex/conditional.w"

halfword cond_ptr;
int if_limit;
int cur_if;
int if_line;

/*:3*//*4:*/
#line 51 "./luatexdir/tex/conditional.w"

int skip_line;

/*:4*//*5:*/
#line 60 "./luatexdir/tex/conditional.w"

void pass_text(void)
{
int l= 0;
int save_scanner_status= scanner_status;
scanner_status= skipping;
skip_line= line;
while(1){
get_next();
if(cur_cmd==fi_or_else_cmd){
if(l==0)
break;
if(cur_chr==fi_code)
decr(l);
}else if(cur_cmd==if_test_cmd){
incr(l);
}
}
scanner_status= save_scanner_status;
if(tracing_ifs_par> 0)
show_cur_cmd_chr();
}

/*:5*//*6:*/
#line 89 "./luatexdir/tex/conditional.w"

void push_condition_stack(void)
{
halfword p= new_node(if_node,0);
vlink(p)= cond_ptr;
if_limit_type(p)= (quarterword)if_limit;
if_limit_subtype(p)= (quarterword)cur_if;
if_line_field(p)= if_line;
cond_ptr= p;
cur_if= cur_chr;
if_limit= if_code;
if_line= line;
}

void pop_condition_stack(void)
{
halfword p;
if(if_stack[in_open]==cond_ptr)
if_warning();

p= cond_ptr;
if_line= if_line_field(p);
cur_if= if_limit_subtype(p);
if_limit= if_limit_type(p);
cond_ptr= vlink(p);
flush_node(p);
}

/*:6*//*7:*/
#line 120 "./luatexdir/tex/conditional.w"

void change_if_limit(int l,halfword p)
{
if(p==cond_ptr){

if_limit= l;
}else{
halfword q= cond_ptr;
while(1){
if(q==null)
confusion("if");
if(vlink(q)==p){
if_limit_type(q)= (quarterword)l;
return;
}
q= vlink(q);
}
}
}

/*:7*//*8:*/
#line 145 "./luatexdir/tex/conditional.w"

static halfword last_tested_cs;

static boolean test_for_cs(void)
{
boolean b= false;
int m,s;
halfword q;
halfword n= get_avail();
halfword p= n;
while(1){
get_x_token();
if(cur_cs!=0)
break;
store_new_token(cur_tok);
}
if(cur_cmd!=end_cs_name_cmd){
last_tested_cs= null_cs;
if(suppress_ifcsname_error_par){
do{
get_x_token();
}while(cur_cmd!=end_cs_name_cmd);
flush_list(n);
return b;
}else{
complain_missing_csname();
}
}

m= first;
p= token_link(n);
while(p!=null){
if(m>=max_buf_stack){
max_buf_stack= m+4;
if(max_buf_stack>=buf_size)
check_buffer_overflow(max_buf_stack);
}
s= token_chr(token_info(p));
if(s<=0x7F){
buffer[m++]= (packed_ASCII_code)s;
}else if(s<=0x7FF){
buffer[m++]= (packed_ASCII_code)(0xC0+s/0x40);
buffer[m++]= (packed_ASCII_code)(0x80+s%0x40);
}else if(s<=0xFFFF){
buffer[m++]= (packed_ASCII_code)(0xE0+s/0x1000);
buffer[m++]= (packed_ASCII_code)(0x80+(s%0x1000)/0x40);
buffer[m++]= (packed_ASCII_code)(0x80+(s%0x1000)%0x40);
}else{
buffer[m++]= (packed_ASCII_code)(0xF0+s/0x40000);
buffer[m++]= (packed_ASCII_code)(0x80+(s%0x40000)/0x1000);
buffer[m++]= (packed_ASCII_code)(0x80+((s%0x40000)%0x1000)/0x40);
buffer[m++]= (packed_ASCII_code)(0x80+((s%0x40000)%0x1000)%0x40);
}
p= token_link(p);
}
if(m> first){
cur_cs= id_lookup(first,m-first);
}else if(m==first){
cur_cs= null_cs;
}
b= (eq_type(cur_cs)!=undefined_cs_cmd);
flush_list(n);
last_cs_name= cur_cs;
return b;
}

/*:8*//*9:*/
#line 214 "./luatexdir/tex/conditional.w"

#define get_x_token_or_active_char() do { \
    get_x_token(); \
    if (cur_cmd==relax_cmd && cur_chr==no_expand_flag) { \
        if (is_active_cs(cs_text(cur_cs))) { \
            cur_cmd= active_char_cmd; \
            cur_chr= active_cs_value(cs_text(cur_tok-cs_token_flag)); \
        } \
    } \
} while (0)

/*:9*//*10:*/
#line 230 "./luatexdir/tex/conditional.w"

void conditional(void)
{
boolean b= false;
int r;
int m,n;
halfword p,q;
int save_scanner_status;
halfword save_cond_ptr;
int this_if;
boolean is_unless;
if((tracing_ifs_par> 0)&&(tracing_commands_par<=1))
show_cur_cmd_chr();
push_condition_stack();
save_cond_ptr= cond_ptr;
is_unless= (cur_chr>=unless_code);
this_if= cur_chr%unless_code;

switch(this_if){
case if_char_code:
case if_cat_code:

get_x_token_or_active_char();
if((cur_cmd> active_char_cmd)||(cur_chr> biggest_char)){

m= relax_cmd;
n= too_big_char;
}else{
m= cur_cmd;
n= cur_chr;
}
get_x_token_or_active_char();
if((cur_cmd> active_char_cmd)||(cur_chr> biggest_char)){
cur_cmd= relax_cmd;
cur_chr= too_big_char;
}
if(this_if==if_char_code)
b= (n==cur_chr);
else
b= (m==cur_cmd);
break;
case if_int_code:
case if_dim_code:
case if_abs_dim_code:
case if_abs_num_code:


if(this_if==if_int_code||this_if==if_abs_num_code)
scan_int();
else
scan_normal_dimen();
n= cur_val;
if((n<0)&&(this_if==if_abs_dim_code||this_if==if_abs_num_code))
negate(n);

do{
get_x_token();
}while(cur_cmd==spacer_cmd);





r= cur_tok-other_token;
if((r<'<')||(r> '>')){
print_err("Missing = inserted for ");
print_cmd_chr(if_test_cmd,this_if);
help1("I was expecting to see `<', `=', or `>'. Didn't.");
back_error();
r= '=';
}
if(this_if==if_int_code||this_if==if_abs_num_code)
scan_int();
else
scan_normal_dimen();
if((cur_val<0)&&(this_if==if_abs_dim_code||this_if==if_abs_num_code))
negate(cur_val);
switch(r){
case'<':
b= (n<cur_val);
break;
case'=':
b= (n==cur_val);
break;
case'>':
b= (n> cur_val);
break;
default:

b= false;
break;
}
break;
case if_odd_code:

scan_int();
b= odd(cur_val);
break;
case if_vmode_code:
b= (abs(cur_list.mode_field)==vmode);
break;
case if_hmode_code:
b= (abs(cur_list.mode_field)==hmode);
break;
case if_mmode_code:
b= (abs(cur_list.mode_field)==mmode);
break;
case if_inner_code:
b= (cur_list.mode_field<0);
break;
















case if_void_code:
scan_register_num();
p= box(cur_val);
b= (p==null);
break;
case if_hbox_code:
scan_register_num();
p= box(cur_val);
b= (p!=null)&&(type(p)==hlist_node);
break;
case if_vbox_code:
scan_register_num();
p= box(cur_val);
b= (p!=null)&&(type(p)==vlist_node);
break;
case ifx_code:










save_scanner_status= scanner_status;
scanner_status= normal;
get_next();
n= cur_cs;
p= cur_cmd;
q= cur_chr;
get_next();
if(cur_cmd!=p){
b= false;
}else if(cur_cmd<call_cmd){
b= (cur_chr==q);
}else{












p= token_link(cur_chr);

q= token_link(equiv(n));
if(p==q){
b= true;
}else{
while((p!=null)&&(q!=null)){
if(token_info(p)!=token_info(q)){
p= null;
break;
}else{
p= token_link(p);
q= token_link(q);
}
}
b= ((p==null)&&(q==null));
}
}
scanner_status= save_scanner_status;
break;
case if_eof_code:
scan_four_bit_int();
b= (read_open[cur_val]==closed);
break;
case if_true_code:
b= true;
break;
case if_false_code:
b= false;
break;
case if_case_code:

scan_int();

n= cur_val;
if(tracing_commands_par> 1){
begin_diagnostic();
tprint("{case ");
print_int(n);
print_char('}');
end_diagnostic(false);
}
while(n!=0){
pass_text();
if(cond_ptr==save_cond_ptr){
if(cur_chr==or_code)
decr(n);
else
goto COMMON_ENDING;
}else if(cur_chr==fi_code){
pop_condition_stack();
}
}
change_if_limit(or_code,save_cond_ptr);

return;
break;
case if_primitive_code:
save_scanner_status= scanner_status;
scanner_status= normal;
get_next();
scanner_status= save_scanner_status;
m= prim_lookup(cs_text(cur_cs));
b= ((cur_cmd!=undefined_cs_cmd)&&
(m!=undefined_primitive)&&
(cur_cmd==get_prim_eq_type(m))&&
(cur_chr==get_prim_equiv(m)));
break;
case if_def_code:





save_scanner_status= scanner_status;
scanner_status= normal;
get_next();
b= (cur_cmd!=undefined_cs_cmd);
scanner_status= save_scanner_status;
break;
case if_cs_code:
b= test_for_cs();
break;
case if_in_csname_code:
b= is_in_csname;
break;
case if_font_char_code:




scan_font_ident();
n= cur_val;
scan_char_num();
b= char_exists(n,cur_val);
break;
default:

b= false;
}
if(is_unless)
b= !b;
if(tracing_commands_par> 1){

begin_diagnostic();
if(b)
tprint("{true}");
else
tprint("{false}");
end_diagnostic(false);
}
if(b){
change_if_limit(else_code,save_cond_ptr);

return;
}








while(1){
pass_text();
if(cond_ptr==save_cond_ptr){
if(cur_chr!=or_code)
goto COMMON_ENDING;
print_err("Extra \\or");
help1("I'm ignoring this; it doesn't match any \\if.");
error();
}else if(cur_chr==fi_code){
pop_condition_stack();
}
}
COMMON_ENDING:
if(cur_chr==fi_code){
pop_condition_stack();
}else{

if_limit= fi_code;
}
}/*:10*/
