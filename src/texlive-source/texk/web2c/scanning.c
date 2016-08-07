/*1:*/
#line 20 "./luatexdir/tex/scanning.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 24 "./luatexdir/tex/scanning.w"

#define prev_depth cur_list.prev_depth_field
#define space_factor cur_list.space_factor_field
#define par_shape_ptr  equiv(par_shape_loc)
#define font_id_text(A) cs_text(font_id_base+(A))

#define attribute(A) eqtb[attribute_base+(A)].hh.rh
#define dimen(A) eqtb[scaled_base+(A)].hh.rh
#undef skip
#define skip(A) eqtb[skip_base+(A)].hh.rh
#define mu_skip(A) eqtb[mu_skip_base+(A)].hh.rh
#define count(A) eqtb[count_base+(A)].hh.rh
#define box(A) equiv(box_base+(A))

static void scan_expr(void);

/*:2*//*3:*/
#line 50 "./luatexdir/tex/scanning.w"

void scan_left_brace(void)
{

do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));

if(cur_cmd!=left_brace_cmd){
print_err("Missing { inserted");
help4("A left brace was mandatory here, so I've put one in.",
"You might want to delete and/or insert some corrections",
"so that I will find a matching right brace soon.",
"If you're confused by all this, try typing `I}' now.");
back_error();
cur_tok= left_brace_token+'{';
cur_cmd= left_brace_cmd;
cur_chr= '{';
incr(align_state);
}
}

/*:3*//*4:*/
#line 75 "./luatexdir/tex/scanning.w"

void scan_optional_equals(void)
{

do{
get_x_token();
}while(cur_cmd==spacer_cmd);
if(cur_tok!=other_token+'=')
back_input();
}

/*:4*//*5:*/
#line 89 "./luatexdir/tex/scanning.w"

static void mu_error(void)
{
print_err("Incompatible glue units");
help1("I'm going to assume that 1mu=1pt when they're mixed.");
error();
}

/*:5*//*6:*/
#line 137 "./luatexdir/tex/scanning.w"

int cur_val;
int cur_val1;
int cur_val_level;

#define scanned_result(A,B) do {  \
 cur_val= A;    \
 cur_val_level= B;   \
    } while (0)

/*:6*//*7:*/
#line 153 "./luatexdir/tex/scanning.w"

static void downgrade_cur_val(boolean delete_glue)
{
halfword m;
if(cur_val_level==glue_val_level){
m= cur_val;
cur_val= width(m);
if(delete_glue)
delete_glue_ref(m);
}else if(cur_val_level==mu_val_level){
mu_error();
}
decr(cur_val_level);
}

static void negate_cur_val(boolean delete_glue)
{
halfword m;
if(cur_val_level>=glue_val_level){
m= cur_val;
cur_val= new_spec(m);
if(delete_glue)
delete_glue_ref(m);

negate(width(cur_val));
negate(stretch(cur_val));
negate(shrink(cur_val));

}else{
negate(cur_val);
}
}

/*:7*//*8:*/
#line 190 "./luatexdir/tex/scanning.w"

static boolean short_scan_something_internal(int cmd,int chr,int level,
boolean negative)
{
halfword m;
halfword q;
int p;
int save_cur_chr;
boolean succeeded= true;
m= chr;
switch(cmd){
case assign_toks_cmd:
scanned_result(equiv(m),tok_val_level);
break;
case assign_int_cmd:
scanned_result(eqtb[m].cint,int_val_level);
break;
case assign_attr_cmd:
scanned_result(eqtb[m].cint,int_val_level);
break;
case assign_dir_cmd:
scanned_result(eqtb[m].cint,dir_val_level);
break;
case assign_dimen_cmd:
scanned_result(eqtb[m].cint,dimen_val_level);
break;
case assign_glue_cmd:
scanned_result(equiv(m),glue_val_level);
break;
case assign_mu_glue_cmd:
scanned_result(equiv(m),mu_val_level);
break;
case math_style_cmd:
scanned_result(m,int_val_level);
break;
case set_aux_cmd:

if(abs(cur_list.mode_field)!=m){
print_err("Improper ");
print_cmd_chr(set_aux_cmd,m);
help4("You can refer to \\spacefactor only in horizontal mode;",
"you can refer to \\prevdepth only in vertical mode; and",
"neither of these is meaningful inside \\write. So",
"I'm forgetting what you said and using zero instead.");
error();
if(level!=tok_val_level)
scanned_result(0,dimen_val_level);
else
scanned_result(0,int_val_level);
}else if(m==vmode){
scanned_result(prev_depth,dimen_val_level);
}else{
scanned_result(space_factor,int_val_level);
}
break;
case set_prev_graf_cmd:

if(cur_list.mode_field==0){
scanned_result(0,int_val_level);
}else{
p= nest_ptr;
while(abs(nest[p].mode_field)!=vmode)
decr(p);
scanned_result(nest[p].pg_field,int_val_level);
}
break;
case set_page_int_cmd:

if(m==0)
cur_val= dead_cycles;
else if(m==2)
cur_val= interaction;
else
cur_val= insert_penalties;
cur_val_level= int_val_level;
break;
case set_page_dimen_cmd:

if((page_contents==empty)&&(!output_active)){
if(m==0)
cur_val= max_dimen;
else
cur_val= 0;
}else{
cur_val= page_so_far[m];
}
cur_val_level= dimen_val_level;
break;
case set_tex_shape_cmd:

if(par_shape_ptr==null)
cur_val= 0;
else
cur_val= vinfo(par_shape_ptr+1);
cur_val_level= int_val_level;
break;
case set_etex_shape_cmd:

scan_int();
if((equiv(m)==null)||(cur_val<0)){
cur_val= 0;
}else{
if(cur_val> penalty(equiv(m)))
cur_val= penalty(equiv(m));
cur_val= penalty(equiv(m)+cur_val);
}
cur_val_level= int_val_level;
break;
case char_given_cmd:
case math_given_cmd:
case xmath_given_cmd:
scanned_result(cur_chr,int_val_level);
break;
case last_item_cmd:


save_cur_chr= cur_chr;
cur_chr= chr;







if(m>=input_line_no_code){
if(m>=eTeX_glue){

if(m<eTeX_mu){
switch(m){
case mu_to_glue_code:
scan_mu_glue();
break;
};
cur_val_level= glue_val_level;
}else if(m<eTeX_expr){
switch(m){
case glue_to_mu_code:
scan_normal_glue();
break;
}
cur_val_level= mu_val_level;
}else{
cur_val_level= m-eTeX_expr+int_val_level;
scan_expr();
}





while(cur_val_level> level){
downgrade_cur_val(true);
}
if(negative){
negate_cur_val(true);
}
return succeeded;

}else if(m>=eTeX_dim){
switch(m){
case font_char_wd_code:
case font_char_ht_code:
case font_char_dp_code:
case font_char_ic_code:
scan_font_ident();
q= cur_val;
scan_char_num();
if(char_exists(q,cur_val)){
switch(m){
case font_char_wd_code:
cur_val= char_width(q,cur_val);
break;
case font_char_ht_code:
cur_val= char_height(q,cur_val);
break;
case font_char_dp_code:
cur_val= char_depth(q,cur_val);
break;
case font_char_ic_code:
cur_val= char_italic(q,cur_val);
break;
}
}else{
cur_val= 0;
}
break;
case par_shape_length_code:
case par_shape_indent_code:
case par_shape_dimen_code:
q= cur_chr-par_shape_length_code;
scan_int();
if((par_shape_ptr==null)||(cur_val<=0)){
cur_val= 0;
}else{
if(q==2){
q= cur_val%2;
cur_val= (cur_val+q)/2;
}
if(cur_val> vinfo(par_shape_ptr+1))
cur_val= vinfo(par_shape_ptr+1);
cur_val= 
varmem[par_shape_ptr+2*cur_val-q+1].cint;
}
cur_val_level= dimen_val_level;
break;
case glue_stretch_code:
case glue_shrink_code:
scan_normal_glue();
q= cur_val;
if(m==glue_stretch_code)
cur_val= stretch(q);
else
cur_val= shrink(q);
delete_glue_ref(q);
break;
}
cur_val_level= dimen_val_level;
}else{
switch(m){
case input_line_no_code:
cur_val= line;
break;
case badness_code:
cur_val= last_badness;
break;
case luatex_version_code:
cur_val= get_luatexversion();
break;
case last_saved_box_resource_index_code:
cur_val= last_saved_box_index;
break;
case last_saved_image_resource_index_code:
cur_val= last_saved_image_index;
break;
case last_saved_image_resource_pages_code:
cur_val= last_saved_image_pages;
break;
case last_x_pos_code:
cur_val= last_position.h;
break;
case last_y_pos_code:
cur_val= last_position.v;
break;
case random_seed_code:
cur_val= random_seed;
break;
case eTeX_version_code:
cur_val= eTeX_version;
break;
case eTeX_minor_version_code:
cur_val= eTeX_minor_version;
break;
case current_group_level_code:
cur_val= cur_level-level_one;
break;
case current_group_type_code:
cur_val= cur_group;
break;
case current_if_level_code:
q= cond_ptr;
cur_val= 0;
while(q!=null){
incr(cur_val);
q= vlink(q);
}
break;
case current_if_type_code:
if(cond_ptr==null)
cur_val= 0;
else if(cur_if<unless_code)
cur_val= cur_if+1;
else
cur_val= -(cur_if-unless_code+1);
break;
case current_if_branch_code:
if((if_limit==or_code)||(if_limit==else_code))
cur_val= 1;
else if(if_limit==fi_code)
cur_val= -1;
else
cur_val= 0;
break;
case glue_stretch_order_code:
case glue_shrink_order_code:
scan_normal_glue();
q= cur_val;
if(m==glue_stretch_order_code)
cur_val= stretch_order(q);
else
cur_val= shrink_order(q);
delete_glue_ref(q);
break;
}
cur_val_level= int_val_level;
}
}else{
if(cur_chr==glue_val_level)
cur_val= zero_glue;
else
cur_val= 0;
if(cur_chr==last_node_type_code){
cur_val_level= int_val_level;
if((cur_list.tail_field==cur_list.head_field)
||(cur_list.mode_field==0))
cur_val= -1;
}else{
cur_val_level= cur_chr;
}
if((cur_list.tail_field!=contrib_head)&&
!is_char_node(cur_list.tail_field)&&
(cur_list.mode_field!=0)){
switch(cur_chr){
case lastpenalty_code:
if(type(cur_list.tail_field)==penalty_node)
cur_val= penalty(cur_list.tail_field);
break;
case lastkern_code:
if(type(cur_list.tail_field)==kern_node)
cur_val= width(cur_list.tail_field);
break;
case lastskip_code:
if(type(cur_list.tail_field)==glue_node)
cur_val= glue_ptr(cur_list.tail_field);
if(subtype(cur_list.tail_field)==mu_glue)
cur_val_level= mu_val_level;
break;
case last_node_type_code:
cur_val= visible_last_node_type(cur_list.tail_field);
break;
}
}else if((cur_list.mode_field==vmode)
&&(cur_list.tail_field==cur_list.head_field)){
switch(cur_chr){
case lastpenalty_code:
cur_val= last_penalty;
break;
case lastkern_code:
cur_val= last_kern;
break;
case lastskip_code:
if(last_glue!=max_halfword)
cur_val= last_glue;
break;
case last_node_type_code:
cur_val= last_node_type;
break;
}
}
}
cur_chr= save_cur_chr;
break;
default:
succeeded= false;
}
if(succeeded){
while(cur_val_level> level){

downgrade_cur_val(false);
}





if(negative){
negate_cur_val(false);
}else if((cur_val_level>=glue_val_level)
&&(cur_val_level<=mu_val_level)){
add_glue_ref(cur_val);
}
}
return succeeded;
}

/*:8*//*9:*/
#line 569 "./luatexdir/tex/scanning.w"

void scan_something_simple(halfword cmd,halfword subitem)
{

if(!short_scan_something_internal(cmd,subitem,tok_val_level,false)){

print_err("You can't use `");
print_cmd_chr((quarterword)cmd,subitem);
tprint("' as tex library index");
help1("I'm forgetting what you said and using zero instead.");
error();
scanned_result(0,int_val_level);
}
}

/*:9*//*10:*/
#line 590 "./luatexdir/tex/scanning.w"

void scan_something_internal(int level,boolean negative)
{

halfword m;
int n,k;
RESTART:
m= cur_chr;
if(!short_scan_something_internal(cur_cmd,cur_chr,level,negative)){
switch(cur_cmd){
case def_char_code_cmd:

scan_char_num();
if(m==math_code_base){
cur_val1= get_math_code_num(cur_val);
scanned_result(cur_val1,int_val_level);
}else if(m==lc_code_base){
cur_val1= get_lc_code(cur_val);
scanned_result(cur_val1,int_val_level);
}else if(m==uc_code_base){
cur_val1= get_uc_code(cur_val);
scanned_result(cur_val1,int_val_level);
}else if(m==sf_code_base){
cur_val1= get_sf_code(cur_val);
scanned_result(cur_val1,int_val_level);
}else if(m==cat_code_base){
cur_val1= get_cat_code(int_par(cat_code_table_code),cur_val);
scanned_result(cur_val1,int_val_level);
}else{
confusion("def_char");
}
break;
case def_del_code_cmd:
case extdef_del_code_cmd:

scan_char_num();
cur_val1= get_del_code_num(cur_val);
scanned_result(cur_val1,int_val_level);
break;
case extdef_math_code_cmd:

scan_char_num();
cur_val1= get_math_code_num(cur_val);
scanned_result(cur_val1,int_val_level);
break;
case toks_register_cmd:
case set_font_cmd:
case def_font_cmd:
case letterspace_font_cmd:
case copy_font_cmd:

if(level!=tok_val_level){
print_err("Missing number, treated as zero");
help3("A number should have been here; I inserted `0'.",
"(If you can't figure out why I needed to see a number,",
"look up `weird error' in the index to The TeXbook.)");
back_error();
scanned_result(0,dimen_val_level);
}else if(cur_cmd==toks_register_cmd){
scan_register_num();
m= toks_base+cur_val;
scanned_result(equiv(m),tok_val_level);
}else{
back_input();
scan_font_ident();
scanned_result(font_id_base+cur_val,ident_val_level);
}
break;
case set_font_id_cmd:
scan_int();
scanned_result(font_id_base+cur_val,ident_val_level);
break;
case def_family_cmd:

scan_char_num();
cur_val1= fam_fnt(cur_val,m);
scanned_result(font_id_base+cur_val1,ident_val_level);
break;
case set_math_param_cmd:

cur_val1= cur_chr;
get_token();
if(cur_cmd!=math_style_cmd){
print_err("Missing math style, treated as \\displaystyle");
help1
("A style should have been here; I inserted `\\displaystyle'.");
cur_val= display_style;
back_error();
}else{
cur_val= cur_chr;
}
if(cur_val1<math_param_first_mu_glue){
if(cur_val1==math_param_radical_degree_raise){
cur_val1= get_math_param(cur_val1,cur_chr);
scanned_result(cur_val1,int_val_level);
}else{
cur_val1= get_math_param(cur_val1,cur_chr);
scanned_result(cur_val1,dimen_val_level);
}
}else{
cur_val1= get_math_param(cur_val1,cur_chr);
if(cur_val1==thin_mu_skip_code)
cur_val1= glue_par(thin_mu_skip_code);
else if(cur_val1==med_mu_skip_code)
cur_val1= glue_par(med_mu_skip_code);
else if(cur_val1==thick_mu_skip_code)
cur_val1= glue_par(thick_mu_skip_code);
scanned_result(cur_val1,mu_val_level);
}
break;
case assign_box_dir_cmd:
scan_register_num();
m= cur_val;
if(box(m)!=null)
cur_val= box_dir(box(m));
else
cur_val= 0;
cur_val_level= dir_val_level;
break;
case set_box_dimen_cmd:

scan_register_num();
if(box(cur_val)==null)
cur_val= 0;
else
cur_val= varmem[box(cur_val)+m].cint;
cur_val_level= dimen_val_level;
break;
case assign_font_dimen_cmd:

get_font_dimen();
break;
case assign_font_int_cmd:

scan_font_ident();
if(m==0){
scanned_result(hyphen_char(cur_val),int_val_level);
}else if(m==1){
scanned_result(skew_char(cur_val),int_val_level);
}else if(m==no_lig_code){
scanned_result(test_no_ligatures(cur_val),int_val_level);
}else{
n= cur_val;
scan_char_num();
k= cur_val;
switch(m){
case lp_code_base:
scanned_result(get_lp_code(n,k),int_val_level);
break;
case rp_code_base:
scanned_result(get_rp_code(n,k),int_val_level);
break;
case ef_code_base:
scanned_result(get_ef_code(n,k),int_val_level);
break;
case tag_code:
scanned_result(get_tag_code(n,k),int_val_level);
break;
}
}
break;
case register_cmd:

scan_register_num();
switch(m){
case int_val_level:
cur_val= count(cur_val);
break;
case attr_val_level:
cur_val= attribute(cur_val);
break;
case dimen_val_level:
cur_val= dimen(cur_val);
break;
case glue_val_level:
cur_val= skip(cur_val);
break;
case mu_val_level:
cur_val= mu_skip(cur_val);
break;
}
cur_val_level= m;
break;
case ignore_spaces_cmd:
if(cur_chr==1){








get_token();
cur_cs= prim_lookup(cs_text(cur_cs));
if(cur_cs!=undefined_primitive){
cur_cmd= get_prim_eq_type(cur_cs);
cur_chr= get_prim_equiv(cur_cs);
cur_tok= token_val(cur_cmd,cur_chr);
}else{
cur_cmd= relax_cmd;
cur_chr= 0;
cur_tok= cs_token_flag+frozen_relax;
cur_cs= frozen_relax;
}
goto RESTART;
}
break;
case hyph_data_cmd:
switch(cur_chr){
case 0:
case 1:
goto DEFAULT;
break;
case 2:
cur_val= get_pre_hyphen_char(int_par(language_code));
cur_val_level= int_val_level;
break;
case 3:
cur_val= get_post_hyphen_char(int_par(language_code));
cur_val_level= int_val_level;
break;
case 4:
cur_val= get_pre_exhyphen_char(int_par(language_code));
cur_val_level= int_val_level;
break;
case 5:
cur_val= get_post_exhyphen_char(int_par(language_code));
cur_val_level= int_val_level;
break;
case 6:
cur_val= get_hyphenation_min(int_par(language_code));
cur_val_level= int_val_level;
break;
case 7:
scan_int();
cur_val= get_hj_code(int_par(language_code),cur_val);
cur_val_level= int_val_level;
break;
}
break;
default:
DEFAULT:

print_err("You can't use `");
print_cmd_chr((quarterword)cur_cmd,cur_chr);
tprint("' after \\the");
help1("I'm forgetting what you said and using zero instead.");
error();
if(level!=tok_val_level)
scanned_result(0,dimen_val_level);
else
scanned_result(0,int_val_level);
break;
}
while(cur_val_level> level){

downgrade_cur_val(false);
}





if(negative){
negate_cur_val(false);
}else if((cur_val_level>=glue_val_level)&&
(cur_val_level<=mu_val_level)){
add_glue_ref(cur_val);
}
}
}

/*:10*//*11:*/
#line 871 "./luatexdir/tex/scanning.w"

void scan_limited_int(int max,const char*name)
{
char hlp[80];
scan_int();
if((cur_val<0)||(cur_val> max)){
if(name==NULL){
snprintf(hlp,80,
"Since I expected to read a number between 0 and %d,",
max);
print_err("Bad number");
}else{
char msg[80];
snprintf(hlp,80,"A %s must be between 0 and %d.",name,max);
snprintf(msg,80,"Bad %s",name);
print_err(msg);
}
help2(hlp,"I changed this one to zero.");
int_error(cur_val);
cur_val= 0;
}
}

/*:11*//*12:*/
#line 894 "./luatexdir/tex/scanning.w"

void scan_fifteen_bit_int(void)
{
scan_real_fifteen_bit_int();
cur_val= ((cur_val/0x1000)*0x1000000)+
(((cur_val%0x1000)/0x100)*0x10000)+(cur_val%0x100);
}

/*:12*//*13:*/
#line 902 "./luatexdir/tex/scanning.w"

void scan_fifty_one_bit_int(void)
{
int iiii;
scan_int();
if((cur_val<0)||(cur_val> 0777777777)){
print_err("Bad delimiter code");
help2
("A numeric delimiter (first part) must be between 0 and 2^{27}-1.",
"I changed this one to zero.");
int_error(cur_val);
cur_val= 0;
}
iiii= cur_val;
scan_int();
if((cur_val<0)||(cur_val> 0xFFFFFF)){
print_err("Bad delimiter code");
help2
("A numeric delimiter (second part) must be between 0 and 2^{24}-1.",
"I changed this one to zero.");
int_error(cur_val);
cur_val= 0;
}
cur_val1= cur_val;
cur_val= iiii;
}

/*:13*//*14:*/
#line 939 "./luatexdir/tex/scanning.w"

int radix;

/*:14*//*15:*/
#line 948 "./luatexdir/tex/scanning.w"

void scan_int(void)
{
boolean negative;
int m;
int d;
boolean vacuous;
boolean OK_so_far;
radix= 0;
OK_so_far= true;

negative= false;
do{

do{
get_x_token();
}while(cur_cmd==spacer_cmd);
if(cur_tok==other_token+'-'){
negative= !negative;
cur_tok= other_token+'+';
}
}while(cur_tok==other_token+'+');

RESTART:
if(cur_tok==alpha_token){



get_token();
if(cur_tok<cs_token_flag){
cur_val= cur_chr;
if(cur_cmd<=right_brace_cmd){
if(cur_cmd==right_brace_cmd)
incr(align_state);
else
decr(align_state);
}
}else{
str_number txt= cs_text(cur_tok-cs_token_flag);
if(is_active_cs(txt))
cur_val= active_cs_value(txt);
else if(single_letter(txt))
cur_val= pool_to_unichar(str_string(txt));
else
cur_val= (biggest_char+1);
}
if(cur_val> biggest_char){
print_err("Improper alphabetic constant");
help2("A one-character control sequence belongs after a ` mark.",
"So I'm essentially inserting \\0 here.");
cur_val= '0';
back_error();
}else{

get_x_token();
if(cur_cmd!=spacer_cmd)
back_input();
}

}else if(cur_tok==cs_token_flag+frozen_primitive){








get_token();
cur_cs= prim_lookup(cs_text(cur_cs));
if(cur_cs!=undefined_primitive){
cur_cmd= get_prim_eq_type(cur_cs);
cur_chr= get_prim_equiv(cur_cs);
cur_tok= token_val(cur_cmd,cur_chr);
}else{
cur_cmd= relax_cmd;
cur_chr= 0;
cur_tok= cs_token_flag+frozen_relax;
cur_cs= frozen_relax;
}
goto RESTART;
}else if(cur_cmd==math_style_cmd){
cur_val= cur_chr;
}else if((cur_cmd>=min_internal_cmd)&&(cur_cmd<=max_internal_cmd)){
scan_something_internal(int_val_level,false);
}else{

radix= 10;
m= 214748364;
if(cur_tok==octal_token){
radix= 8;
m= 02000000000;
get_x_token();
}else if(cur_tok==hex_token){
radix= 16;
m= 01000000000;
get_x_token();
}
vacuous= true;
cur_val= 0;

while(1){
if((cur_tok<zero_token+radix)&&(cur_tok>=zero_token)
&&(cur_tok<=zero_token+9)){
d= cur_tok-zero_token;
}else if(radix==16){
if((cur_tok<=A_token+5)&&(cur_tok>=A_token)){
d= cur_tok-A_token+10;
}else if((cur_tok<=other_A_token+5)
&&(cur_tok>=other_A_token)){
d= cur_tok-other_A_token+10;
}else{
break;
}
}else{
break;
}
vacuous= false;
if((cur_val>=m)&&((cur_val> m)||(d> 7)||(radix!=10))){
if(OK_so_far){
print_err("Number too big");
help2
("I can only go up to 2147483647='17777777777=\"7FFFFFFF,",
"so I'm using that number instead of yours.");
error();
cur_val= infinity;
OK_so_far= false;
}
}else{
cur_val= cur_val*radix+d;
}
get_x_token();
}
if(vacuous){

print_err("Missing number, treated as zero");
help3("A number should have been here; I inserted `0'.",
"(If you can't figure out why I needed to see a number,",
"look up `weird error' in the index to The TeXbook.)");
back_error();
}else if(cur_cmd!=spacer_cmd){
back_input();
}
}
if(negative)
negate(cur_val);
}

/*:15*//*16:*/
#line 1100 "./luatexdir/tex/scanning.w"

static void coerce_glue(void)
{
int v;
if(cur_val_level>=glue_val_level){
v= width(cur_val);
delete_glue_ref(cur_val);
cur_val= v;
}
}

/*:16*//*17:*/
#line 1125 "./luatexdir/tex/scanning.w"

int cur_order;


/*:17*//*19:*/
#line 1157 "./luatexdir/tex/scanning.w"


static void scan_dimen_mu_error(void){
print_err("Illegal unit of measure (mu inserted)");
help4("The unit of measurement in math glue must be mu.",
"To recover gracefully from this error, it's best to",
"delete the erroneous units; e.g., type `2' to delete",
"two letters. (See Chapter 27 of The TeXbook.)");
error();
}

static void scan_dimen_unknown_unit_error(void){
print_err("Illegal unit of measure (pt inserted)");
help6("Dimensions can be in units of em, ex, in, pt, pc,",
"cm, mm, dd, cc, nd, nc, bp, or sp; but yours is a new one!",
"I'll assume that you meant to say pt, for printer's points.",
"To recover gracefully from this error, it's best to",
"delete the erroneous units; e.g., type `2' to delete",
"two letters. (See Chapter 27 of The TeXbook.)");
error();
}

static void scan_dimen_out_of_range_error(void){
print_err("Dimension too large");
help2("I can't work with sizes bigger than about 19 feet.",
"Continue and I'll use the largest value I can.");
error();
}

#define set_conversion(A,B) do { num= (A); denom= (B); } while(0)






void scan_dimen(boolean mu,boolean inf,boolean shortcut)
{
boolean negative;
int f= 0;
int num,denom;
halfword q;
scaled v;
int save_cur_val;
arith_error= false;
cur_order= normal;
negative= false;
if(!shortcut){

do{

do{
get_x_token();
}while(cur_cmd==spacer_cmd);
if(cur_tok==other_token+'-'){
negative= !negative;
cur_tok= other_token+'+';
}
}while(cur_tok==other_token+'+');
if((cur_cmd>=min_internal_cmd)&&(cur_cmd<=max_internal_cmd)){

if(mu){
scan_something_internal(mu_val_level,false);
coerce_glue();
if(cur_val_level==mu_val_level){
goto ATTACH_SIGN;
}else if(cur_val_level!=int_val_level){
mu_error();
}
}else{
scan_something_internal(dimen_val_level,false);
if(cur_val_level==dimen_val_level){
goto ATTACH_SIGN;
}
}
}else{
back_input();
if(cur_tok==continental_point_token){
cur_tok= point_token;
}
if(cur_tok!=point_token){
scan_int();
}else{
radix= 10;
cur_val= 0;
}
if(cur_tok==continental_point_token){
cur_tok= point_token;
}
if((radix==10)&&(cur_tok==point_token)){






int k= 0;
halfword p= null;
int kk;
get_token();
while(1){
get_x_token();
if((cur_tok> zero_token+9)||(cur_tok<zero_token))
break;
if(k<17){

q= get_avail();
set_token_link(q,p);
set_token_info(q,cur_tok-zero_token);
p= q;
incr(k);
}
}
for(kk= k;kk>=1;kk--){
dig[kk-1]= token_info(p);
q= p;
p= token_link(p);
free_avail(q);
}
f= round_decimals(k);
if(cur_cmd!=spacer_cmd){
back_input();
}
}
}
}
if(cur_val<0){

negative= !negative;
negate(cur_val);
}









if(inf){






if(scan_keyword("filll")){
cur_order= filll;
goto ATTACH_FRACTION;
}else if(scan_keyword("fill")){
cur_order= fill;
goto ATTACH_FRACTION;
}else if(scan_keyword("fil")){
cur_order= fil;
goto ATTACH_FRACTION;
}else if(scan_keyword("fi")){
cur_order= sfi;
goto ATTACH_FRACTION;
}
}




save_cur_val= cur_val;

do{
get_x_token();
}while(cur_cmd==spacer_cmd);

if((cur_cmd<min_internal_cmd)||(cur_cmd> max_internal_cmd)){
back_input();
}else{

if(mu){
scan_something_internal(mu_val_level,false);
coerce_glue();
if(cur_val_level!=mu_val_level){
mu_error();
}
}else{
scan_something_internal(dimen_val_level,false);
}
v= cur_val;
goto FOUND;
}

if(mu){

if(!scan_keyword("mu")){
scan_dimen_mu_error();
}
goto ATTACH_FRACTION;
}else if(scan_keyword("em")){
v= quad(get_cur_font());
}else if(scan_keyword("ex")){
v= x_height(get_cur_font());
}else if(scan_keyword("px")){
v= dimen_par(px_dimen_code);
}else{
goto PICKUP_UNIT;
}

get_x_token();
if(cur_cmd!=spacer_cmd){
back_input();
}
FOUND:
cur_val= nx_plus_y(save_cur_val,v,xn_over_d(v,f,0200000));
goto ATTACH_SIGN;




PICKUP_UNIT:
if(scan_keyword("pt")){
goto ATTACH_FRACTION;
}else if(scan_keyword("mm")){
set_conversion(7227,2540);
goto SCALE_VALUE;
}else if(scan_keyword("cm")){
set_conversion(7227,254);
goto SCALE_VALUE;
}else if(scan_keyword("sp")){
goto DONE;
}else if(scan_keyword("bp")){
set_conversion(7227,7200);
goto SCALE_VALUE;
}else if(scan_keyword("in")){
set_conversion(7227,100);
goto SCALE_VALUE;
}else if(scan_keyword("dd")){
set_conversion(1238,1157);
goto SCALE_VALUE;
}else if(scan_keyword("cc")){
set_conversion(14856,1157);
goto SCALE_VALUE;
}else if(scan_keyword("pc")){
set_conversion(12,1);
goto SCALE_VALUE;
}else if(scan_keyword("nd")){
set_conversion(685,642);
goto SCALE_VALUE;
}else if(scan_keyword("nc")){
set_conversion(1370,107);
goto SCALE_VALUE;
}else if(scan_keyword("true")){

if(output_mode_used==OMODE_DVI){
prepare_mag();
if(int_par(mag_code)!=1000){
cur_val= xn_over_d(cur_val,1000,int_par(mag_code));
f= (1000*f+0200000*tex_remainder)/int_par(mag_code);
cur_val= cur_val+(f/0200000);
f= f%0200000;
}
}
goto PICKUP_UNIT;
}else{

scan_dimen_unknown_unit_error();
goto BAD_NEWS;
}
SCALE_VALUE:
cur_val= xn_over_d(cur_val,num,denom);
f= (num*f+0200000*tex_remainder)/denom;
cur_val= cur_val+(f/0200000);
f= f%0200000;
BAD_NEWS:
ATTACH_FRACTION:
if(cur_val>=040000){
arith_error= true;
}else{
cur_val= cur_val*unity+f;
}
DONE:

get_x_token();
if(cur_cmd!=spacer_cmd){
back_input();
}
ATTACH_SIGN:
if(arith_error||(abs(cur_val)>=010000000000)){

scan_dimen_out_of_range_error();
cur_val= max_dimen;
arith_error= false;
}
if(negative){
negate(cur_val);
}
}

/*:19*//*20:*/
#line 1461 "./luatexdir/tex/scanning.w"

void scan_glue(int level)
{
boolean negative;
halfword q;
boolean mu;
mu= (level==mu_val_level);

negative= false;
do{

do{
get_x_token();
}while(cur_cmd==spacer_cmd);
if(cur_tok==other_token+'-'){
negative= !negative;
cur_tok= other_token+'+';
}
}while(cur_tok==other_token+'+');

if((cur_cmd>=min_internal_cmd)&&(cur_cmd<=max_internal_cmd)){
scan_something_internal(level,negative);
if(cur_val_level>=glue_val_level){
if(cur_val_level!=level)
mu_error();
return;
}
if(cur_val_level==int_val_level)
scan_dimen(mu,false,true);
else if(level==mu_val_level)
mu_error();
}else{
back_input();
scan_dimen(mu,false,false);
if(negative)
negate(cur_val);
}


q= new_spec(zero_glue);
width(q)= cur_val;
if(scan_keyword("plus")){
scan_dimen(mu,true,false);
stretch(q)= cur_val;
stretch_order(q)= (quarterword)cur_order;
}
if(scan_keyword("minus")){
scan_dimen(mu,true,false);
shrink(q)= cur_val;
shrink_order(q)= (quarterword)cur_order;
}
cur_val= q;
}

/*:20*//*21:*/
#line 1516 "./luatexdir/tex/scanning.w"

void scan_scaled(void)
{
boolean negative;
int f;
int k,kk;
halfword p,q;
f= 0;
arith_error= false;
negative= false;

do{

do{
get_x_token();
}while(cur_cmd==spacer_cmd);
if(cur_tok==other_token+'-'){
negative= !negative;
cur_tok= other_token+'+';
}
}while(cur_tok==other_token+'+');

back_input();
if(cur_tok==continental_point_token)
cur_tok= point_token;
if(cur_tok!=point_token){
scan_int();
}else{
radix= 10;
cur_val= 0;
}
if(cur_tok==continental_point_token)
cur_tok= point_token;
if((radix==10)&&(cur_tok==point_token)){








k= 0;
p= null;
get_token();
while(1){
get_x_token();
if((cur_tok> zero_token+9)||(cur_tok<zero_token))
break;
if(k<17){
q= get_avail();
set_token_link(q,p);
set_token_info(q,cur_tok-zero_token);
p= q;
incr(k);
}
}
for(kk= k;kk>=1;kk--){
dig[kk-1]= token_info(p);
q= p;
p= token_link(p);
free_avail(q);
}
f= round_decimals(k);
if(cur_cmd!=spacer_cmd)
back_input();

}
if(cur_val<0){
negative= !negative;
negate(cur_val);
}
if(cur_val> 040000)
arith_error= true;
else
cur_val= cur_val*unity+f;
if(arith_error||(abs(cur_val)>=010000000000)){
print_err("Stack number too large");
error();
}
if(negative)
negate(cur_val);
}

/*:21*//*22:*/
#line 1604 "./luatexdir/tex/scanning.w"

halfword the_toks(void)
{
int old_setting;
halfword p,q,r;
int c;
str_number s;
halfword retval;

if(odd(cur_chr)){
c= cur_chr;
scan_general_text();
if(c==1){
return cur_val;
}else{
old_setting= selector;
selector= new_string;
p= get_avail();
set_token_link(p,token_link(temp_token_head));
token_show(p);
flush_list(p);
selector= old_setting;
s= make_string();
retval= str_toks(str_lstring(s));
flush_str(s);
return retval;
}
}
get_x_token();
scan_something_internal(tok_val_level,false);
if(cur_val_level>=ident_val_level){

p= temp_token_head;
set_token_link(p,null);
if(cur_val_level==ident_val_level){
store_new_token(cs_token_flag+cur_val);
}else if(cur_val!=null){
r= token_link(cur_val);
while(r!=null){
fast_store_new_token(token_info(r));
r= token_link(r);
}
}
return p;
}else{
old_setting= selector;
selector= new_string;
switch(cur_val_level){
case int_val_level:
print_int(cur_val);
break;
case attr_val_level:
print_int(cur_val);
break;
case dir_val_level:
print_dir(cur_val);
break;
case dimen_val_level:
print_scaled(cur_val);
tprint("pt");
break;
case glue_val_level:
print_spec(cur_val,"pt");
delete_glue_ref(cur_val);
break;
case mu_val_level:
print_spec(cur_val,"mu");
delete_glue_ref(cur_val);
break;
}
selector= old_setting;
s= make_string();
retval= str_toks(str_lstring(s));
flush_str(s);
return retval;
}
}

/*:22*//*23:*/
#line 1682 "./luatexdir/tex/scanning.w"

str_number the_scanned_result(void)
{
int old_setting;
str_number r;
old_setting= selector;
selector= new_string;
if(cur_val_level>=ident_val_level){
if(cur_val!=null){
show_token_list(token_link(cur_val),null,-1);
r= make_string();
}else{
r= get_nullstr();
}
}else{
switch(cur_val_level){
case int_val_level:
print_int(cur_val);
break;
case attr_val_level:
print_int(cur_val);
break;
case dir_val_level:
print_dir(cur_val);
break;
case dimen_val_level:
print_scaled(cur_val);
tprint("pt");
break;
case glue_val_level:
print_spec(cur_val,"pt");
delete_glue_ref(cur_val);
break;
case mu_val_level:
print_spec(cur_val,"mu");
delete_glue_ref(cur_val);
break;
}
r= make_string();
}
selector= old_setting;
return r;
}

/*:23*//*24:*/
#line 1730 "./luatexdir/tex/scanning.w"

static void font_param_error(int f)
{
print_err("Font ");
print_esc(font_id_text(f));
tprint(" has only ");
print_int(font_params(f));
tprint(" fontdimen parameters");
help2("To increase the number of font parameters, you must",
"use \\fontdimen immediately after the \\font is loaded.");
error();
}

void set_font_dimen(void)
{
internal_font_number f;
int n;
scan_int();
n= cur_val;
scan_font_ident();
f= cur_val;
if(n<=0){
font_param_error(f);
}else{
if(n> font_params(f)){
if(font_used(f)){
font_param_error(f);
}else{

do{
set_font_param(f,(font_params(f)+1),0);
}while(n!=font_params(f));
}
}
}
scan_optional_equals();
scan_normal_dimen();
set_font_param(f,n,cur_val);
}

void get_font_dimen(void)
{
internal_font_number f;
int n;
scan_int();
n= cur_val;
scan_font_ident();
f= cur_val;
cur_val= 0;
if(n<=0){
font_param_error(f);
goto EXIT;
}else{
if(n> font_params(f)){
if(font_used(f)){
font_param_error(f);
goto EXIT;
}else{

do{
set_font_param(f,(font_params(f)+1),0);
}while(n!=font_params(f));

}
}
}
cur_val= font_param(f,n);
EXIT:
scanned_result(cur_val,dimen_val_level);
}

/*:24*//*25:*/
#line 1808 "./luatexdir/tex/scanning.w"

halfword scan_rule_spec(void)
{

halfword q;
if(cur_cmd==no_vrule_cmd){
q= new_rule(empty_rule);
cur_cmd= vrule_cmd;
}else if(cur_cmd==no_hrule_cmd){
q= new_rule(empty_rule);
cur_cmd= hrule_cmd;
}else{
q= new_rule(normal_rule);
}
if(cur_cmd==vrule_cmd){
width(q)= default_rule;
rule_dir(q)= body_direction;
}else{
height(q)= default_rule;
depth(q)= 0;
rule_dir(q)= text_direction;
}
RESWITCH:
if(scan_keyword("width")){
scan_normal_dimen();
width(q)= cur_val;
goto RESWITCH;
}
if(scan_keyword("height")){
scan_normal_dimen();
height(q)= cur_val;
goto RESWITCH;
}
if(scan_keyword("depth")){
scan_normal_dimen();
depth(q)= cur_val;
goto RESWITCH;
}
return q;
}


/*:25*//*26:*/
#line 1852 "./luatexdir/tex/scanning.w"

void scan_font_ident(void)
{
internal_font_number f;
halfword m;

do{
get_x_token();
}while(cur_cmd==spacer_cmd);

if((cur_cmd==def_font_cmd)||(cur_cmd==letterspace_font_cmd)||(cur_cmd==copy_font_cmd)){
f= get_cur_font();
}else if(cur_cmd==set_font_cmd){
f= cur_chr;
set_font_touched(f,1);
}else if(cur_cmd==def_family_cmd){
m= cur_chr;
scan_math_family_int();
f= fam_fnt(cur_val,m);
set_font_touched(f,1);
}else{
print_err("Missing font identifier");
help2("I was looking for a control sequence whose",
"current meaning has been defined by \\font.");
back_error();
f= null_font;
}
cur_val= f;
}

/*:26*//*27:*/
#line 1889 "./luatexdir/tex/scanning.w"

void scan_general_text(void)
{
int s;
halfword w;
halfword d;
halfword p;
halfword q;
halfword unbalance;
s= scanner_status;
w= warning_index;
d= def_ref;
scanner_status= absorbing;
warning_index= cur_cs;
p= get_avail();
def_ref= p;
set_token_ref_count(def_ref,0);
p= def_ref;
scan_left_brace();
unbalance= 1;
while(1){
get_token();
if(cur_tok<right_brace_limit){
if(cur_cmd<right_brace_cmd){
incr(unbalance);
}else{
decr(unbalance);
if(unbalance==0)
break;
}
}
store_new_token(cur_tok);
}
q= token_link(def_ref);
free_avail(def_ref);
if(q==null)
cur_val= temp_token_head;
else
cur_val= p;
set_token_link(temp_token_head,q);
scanner_status= s;
warning_index= w;
def_ref= d;
}

/*:27*//*28:*/
#line 1937 "./luatexdir/tex/scanning.w"

void get_x_or_protected(void)
{

while(1){
get_token();
if(cur_cmd<=max_command_cmd)
return;
if((cur_cmd>=call_cmd)&&(cur_cmd<end_template_cmd)){
if(token_info(token_link(cur_chr))==protected_token)
return;
}
expand();
}
}

/*:28*//*29:*/
#line 1976 "./luatexdir/tex/scanning.w"

halfword scan_toks(boolean macro_def,boolean xpand)
{
halfword t;
halfword s;
halfword p;
halfword q;
halfword unbalance;
halfword hash_brace;
if(macro_def)
scanner_status= defining;
else
scanner_status= absorbing;
warning_index= cur_cs;
p= get_avail();
def_ref= p;
set_token_ref_count(def_ref,0);
p= def_ref;
hash_brace= 0;
t= zero_token;
if(macro_def){

while(1){
get_token();
if(cur_tok<right_brace_limit)
break;
if(cur_cmd==mac_param_cmd){




s= match_token+cur_chr;
get_token();
if(cur_cmd==left_brace_cmd){
hash_brace= cur_tok;
store_new_token(cur_tok);
store_new_token(end_match_token);
goto DONE;
}
if(t==zero_token+9){
print_err("You already have nine parameters");
help1("I'm going to ignore the # sign you just used.");
error();
}else{
incr(t);
if(cur_tok!=t){
print_err("Parameters must be numbered consecutively");
help2
("I've inserted the digit you should have used after the #.",
"Type `1' to delete what you did use.");
back_error();
}
cur_tok= s;
}
}
store_new_token(cur_tok);
}
store_new_token(end_match_token);
if(cur_cmd==right_brace_cmd){

print_err("Missing { inserted");
incr(align_state);
help2
("Where was the left brace? You said something like `\\def\\a}',",
"which I'm going to interpret as `\\def\\a{}'.");
error();
goto FOUND;
}

}else{
scan_left_brace();
}
DONE:

unbalance= 1;
while(1){
if(xpand){



while(1){
get_next();
if(cur_cmd>=call_cmd){
if(token_info(token_link(cur_chr))==protected_token){
cur_cmd= relax_cmd;
cur_chr= no_expand_flag;
}
}
if(cur_cmd<=max_command_cmd)
break;
if(cur_cmd!=the_cmd){
expand();
}else{
q= the_toks();
if(token_link(temp_token_head)!=null){
set_token_link(p,token_link(temp_token_head));
p= q;
}
}
}
x_token();

}else{
get_token();
}
if(cur_tok<right_brace_limit){
if(cur_cmd<right_brace_cmd){
incr(unbalance);
}else{
decr(unbalance);
if(unbalance==0)
goto FOUND;
}
}else if(cur_cmd==mac_param_cmd){
if(macro_def){

s= cur_tok;
if(xpand)
get_x_token();
else
get_token();
if(cur_cmd!=mac_param_cmd){
if((cur_tok<=zero_token)||(cur_tok> t)){
print_err("Illegal parameter number in definition of ");
sprint_cs(warning_index);
help3("You meant to type ## instead of #, right?",
"Or maybe a } was forgotten somewhere earlier, and things",
"are all screwed up? I'm going to assume that you meant ##.");
back_error();
cur_tok= s;
}else{
cur_tok= out_param_token-'0'+cur_chr;
}
}
}
}
store_new_token(cur_tok);
}
FOUND:
scanner_status= normal;
if(hash_brace!=0)
store_new_token(hash_brace);
return p;
}

/*:29*//*30:*/
#line 2124 "./luatexdir/tex/scanning.w"

void scan_normal_glue(void)
{
scan_glue(glue_val_level);
}

void scan_mu_glue(void)
{
scan_glue(mu_val_level);
}

/*:30*//*32:*/
#line 2142 "./luatexdir/tex/scanning.w"

typedef enum{
expr_none= 0,
expr_add= 1,
expr_sub= 2,
expr_mult= 3,
expr_div= 4,
expr_scale= 5,
}expression_states;


/*:32*//*34:*/
#line 2161 "./luatexdir/tex/scanning.w"

#define num_error(A) do { \
    arith_error= true; \
    A= 0; \
} while (0)

/*:34*//*35:*/
#line 2169 "./luatexdir/tex/scanning.w"

#define glue_error(A) do { \
    arith_error= true; \
    delete_glue_ref(A); \
    A= new_spec(zero_glue); \
} while (0)

#define normalize_glue(A) do { \
    if (stretch(A)==0) stretch_order(A)= normal; \
    if (shrink(A)==0) shrink_order(A)= normal; \
} while (0)

/*:35*//*36:*/
#line 2189 "./luatexdir/tex/scanning.w"

#define expr_type(A) type((A)+1)
#define expr_state(A) subtype((A)+1)
#define expr_e_field(A) vlink((A)+1)    
#define expr_t_field(A) vlink((A)+2)    
#define expr_n_field(A) vinfo((A)+2)    

#define expr_add_sub(A,B,C) add_or_sub((A),(B),(C),(r==expr_sub))
#define expr_a(A,B) expr_add_sub((A),(B),max_dimen)

/*:36*//*37:*/
#line 2205 "./luatexdir/tex/scanning.w"

inline static int add_or_sub(int x,int y,int max_answer,boolean negative)
{
int a;
if(negative)
negate(y);
if(x>=0){
if(y<=max_answer-x)
a= x+y;
else
num_error(a);
}else if(y>=-max_answer-x){
a= x+y;
}else{
num_error(a);
}
return a;
}

#define expr_m(A) A =  nx_plus_y((A),f,0)
#define expr_d(A) A= quotient((A),f)

/*:37*//*38:*/
#line 2230 "./luatexdir/tex/scanning.w"

inline static int quotient(int n,int d)
{
boolean negative;
int a;
if(d==0){
num_error(a);
}else{
if(d> 0){
negative= false;
}else{
negate(d);
negative= true;
}
if(n<0){
negate(n);
negative= !negative;
}
a= n/d;
n= n-a*d;
d= n-d;
if(d+n>=0)
incr(a);
if(negative)
negate(a);
}
return a;
}

#define expr_s(A) A= fract((A),n,f,max_dimen)

/*:38*//*39:*/
#line 2270 "./luatexdir/tex/scanning.w"

int fract(int x,int n,int d,int max_answer)
{
boolean negative;
int a;
int f;
int h;
int r;
int t;
if(d==0)
goto TOO_BIG;
a= 0;
if(d> 0){
negative= false;
}else{
negate(d);
negative= true;
}
if(x<0){
negate(x);
negative= !negative;
}else if(x==0){
goto DONE;
}
if(n<0){
negate(n);
negative= !negative;
}
t= n/d;
if(t> max_answer/x)
goto TOO_BIG;
a= t*x;
n= n-t*d;
if(n==0)
goto FOUND;
t= x/d;
if(t> (max_answer-a)/n)
goto TOO_BIG;
a= a+t*n;
x= x-t*d;
if(x==0)
goto FOUND;
if(x<n){
t= x;
x= n;
n= t;
}









f= 0;
r= (d/2)-d;
h= -r;
while(1){
if(odd(n)){
r= r+x;
if(r>=0){
r= r-d;
incr(f);
}
}
n= n/2;
if(n==0)
break;
if(x<h){
x= x+x;
}else{
t= x-d;
x= t+x;
f= f+n;
if(x<n){
if(x==0)
break;
t= x;
x= n;
n= t;
}
}
}

if(f> (max_answer-a))
goto TOO_BIG;
a= a+f;
FOUND:
if(negative)
negate(a);
goto DONE;
TOO_BIG:
num_error(a);
DONE:
return a;
}

/*:39*//*40:*/
#line 2369 "./luatexdir/tex/scanning.w"

static void scan_expr(void)
{
boolean a,b;
int l;
int r;
int s;
int o;
int e;
int t;
int f;
int n;
halfword p;
halfword q;
l= cur_val_level;
a= arith_error;
b= false;
p= null;

RESTART:
r= expr_none;
e= 0;
s= expr_none;
t= 0;
n= 0;
CONTINUE:
if(s==expr_none)
o= l;
else
o= int_val_level;


do{
get_x_token();
}while(cur_cmd==spacer_cmd);

if(cur_tok==other_token+'('){

q= new_node(expr_node,0);
vlink(q)= p;
expr_type(q)= (quarterword)l;
expr_state(q)= (quarterword)(4*s+r);
expr_e_field(q)= e;
expr_t_field(q)= t;
expr_n_field(q)= n;
p= q;
l= o;
goto RESTART;
}
back_input();
if((o==int_val_level)||(o==attr_val_level))
scan_int();
else if(o==dimen_val_level)
scan_normal_dimen();
else if(o==glue_val_level)
scan_normal_glue();
else
scan_mu_glue();
f= cur_val;

FOUND:


do{
get_x_token();
}while(cur_cmd==spacer_cmd);

if(cur_tok==other_token+'+'){
o= expr_add;
}else if(cur_tok==other_token+'-'){
o= expr_sub;
}else if(cur_tok==other_token+'*'){
o= expr_mult;
}else if(cur_tok==other_token+'/'){
o= expr_div;
}else{
o= expr_none;
if(p==null){
if(cur_cmd!=relax_cmd)
back_input();
}else if(cur_tok!=other_token+')'){
print_err("Missing ) inserted for expression");
help1("I was expecting to see `+', `-', `*', `/', or `)'. Didn't.");
back_error();
}
}

arith_error= b;

if(((l==int_val_level)||(l==attr_val_level))||(s> expr_sub)){
if((f> infinity)||(f<-infinity))
num_error(f);
}else if(l==dimen_val_level){
if(abs(f)> max_dimen)
num_error(f);
}else{
if((abs(width(f))> max_dimen)||(abs(stretch(f))> max_dimen)||(abs(shrink(f))> max_dimen))
glue_error(f);
}

switch(s){

case expr_none:







if((l>=glue_val_level)&&(o!=expr_none)){
t= new_spec(f);
delete_glue_ref(f);
normalize_glue(t);
}else{
t= f;
}
break;
case expr_mult:



if(o==expr_div){
n= f;
o= expr_scale;
}else if((l==int_val_level)||(l==attr_val_level)){
t= mult_integers(t,f);
}else if(l==dimen_val_level){
expr_m(t);
}else{
expr_m(width(t));
expr_m(stretch(t));
expr_m(shrink(t));
}
break;
case expr_div:

if(l<glue_val_level){
expr_d(t);
}else{
expr_d(width(t));
expr_d(stretch(t));
expr_d(shrink(t));
}
break;
case expr_scale:

if((l==int_val_level)||(l==attr_val_level)){
t= fract(t,n,f,infinity);
}else if(l==dimen_val_level){
expr_s(t);
}else{
expr_s(width(t));
expr_s(stretch(t));
expr_s(shrink(t));
}
break;
}
if(o> expr_sub){
s= o;
}else{



s= expr_none;
if(r==expr_none){
e= t;
}else if((l==int_val_level)||(l==attr_val_level)){
e= expr_add_sub(e,t,infinity);
}else if(l==dimen_val_level){
e= expr_a(e,t);
}else{



width(e)= expr_a(width(e),width(t));
if(stretch_order(e)==stretch_order(t)){
stretch(e)= expr_a(stretch(e),stretch(t));
}else if((stretch_order(e)<stretch_order(t))&&(stretch(t)!=0)){
stretch(e)= stretch(t);
stretch_order(e)= stretch_order(t);
}
if(shrink_order(e)==shrink_order(t)){
shrink(e)= expr_a(shrink(e),shrink(t));
}else if((shrink_order(e)<shrink_order(t))&&(shrink(t)!=0)){
shrink(e)= shrink(t);
shrink_order(e)= shrink_order(t);
}
delete_glue_ref(t);
normalize_glue(e);
}
r= o;
}
b= arith_error;
if(o!=expr_none)
goto CONTINUE;
if(p!=null){

f= e;
q= p;
e= expr_e_field(q);
t= expr_t_field(q);
n= expr_n_field(q);
s= expr_state(q)/4;
r= expr_state(q)%4;
l= expr_type(q);
p= vlink(q);
flush_node(q);
goto FOUND;
}

if(b){
print_err("Arithmetic overflow");
help2("I can't evaluate this expression,",
"since the result is out of range.");
error();
if(l>=glue_val_level){
delete_glue_ref(e);
e= zero_glue;
add_glue_ref(e);
}else{
e= 0;
}
}
arith_error= a;
cur_val= e;
cur_val_level= l;
}/*:40*/
