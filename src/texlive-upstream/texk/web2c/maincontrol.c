/*1:*/
#line 20 "./luatexdir/tex/maincontrol.w"


#include "ptexlib.h"
#include "lua/luatex-api.h"

/*:1*//*2:*/
#line 25 "./luatexdir/tex/maincontrol.w"

#define mode     mode_par
#define tail     tail_par
#define head     head_par
#define dir_save dirs_par

/*:2*//*3:*/
#line 77 "./luatexdir/tex/maincontrol.w"

void adjust_space_factor(void)
{
halfword s= get_sf_code(cur_chr);
if(s==1000){
space_factor_par= 1000;
}else if(s<1000){
if(s> 0)
space_factor_par= s;
}else if(space_factor_par<1000){
space_factor_par= 1000;
}else{
space_factor_par= s;
}
}

/*:3*//*5:*/
#line 102 "./luatexdir/tex/maincontrol.w"

#define goto_next 0
#define goto_skip_token 1
#define goto_return 2

static int main_control_state;

/*:5*//*7:*/
#line 116 "./luatexdir/tex/maincontrol.w"

static void run_char_num(void){
scan_char_num();
cur_chr= cur_val;
adjust_space_factor();
tail_append(new_char(cur_font_par,cur_chr));
}

static void run_char(void){
adjust_space_factor();
tail_append(new_char(cur_font_par,cur_chr));
}

/*:7*//*8:*/
#line 140 "./luatexdir/tex/maincontrol.w"

static void run_app_space(void){
halfword p;
int method= disable_space_par;
if(method==1){

}else if(method==2){
p= new_glue(zero_glue);
couple_nodes(tail,p);
tail= p;
}else if((abs(mode)+cur_cmd==hmode+spacer_cmd)&&(!(space_factor_par==1000))){
app_space();
}else{

if(glue_is_zero(space_skip_par)){

p= new_glue(zero_glue);
width(p)= space(cur_font_par);
stretch(p)= space_stretch(cur_font_par);
shrink(p)= space_shrink(cur_font_par);

}else{
p= new_param_glue(space_skip_code);
}

subtype(p)= space_skip_code+1;
couple_nodes(tail,p);
tail= p;
}
}

/*:8*//*9:*/
#line 172 "./luatexdir/tex/maincontrol.w"

static void run_boundary(void){
halfword n;
n= new_node(boundary_node,cur_chr);
if((cur_chr==1)||(cur_chr==2)){

scan_int();
boundary_value(n)= cur_val;
}
couple_nodes(tail,n);
tail= n;
}

/*:9*//*10:*/
#line 185 "./luatexdir/tex/maincontrol.w"

static void run_char_ghost(void){
int t;
t= cur_chr;
get_x_token();
if((cur_cmd==letter_cmd)||(cur_cmd==other_char_cmd)
||(cur_cmd==char_given_cmd)||(cur_cmd==char_num_cmd)){
halfword p= new_glyph(get_cur_font(),cur_chr);
if(t==0){
set_is_leftghost(p);
}else{
set_is_rightghost(p);
}
tail_append(p);
}
}

/*:10*//*11:*/
#line 202 "./luatexdir/tex/maincontrol.w"

static void run_relax(void){
return;
}

/*:11*//*12:*/
#line 211 "./luatexdir/tex/maincontrol.w"

static void run_ignore_spaces(void){
if(cur_chr==0){

do{
get_x_token();
}while(cur_cmd==spacer_cmd);
main_control_state= goto_skip_token;
}else{
int t= scanner_status;
scanner_status= normal;
get_next();
scanner_status= t;
cur_cs= prim_lookup(cs_text(cur_cs));
if(cur_cs!=undefined_primitive){
cur_cmd= get_prim_eq_type(cur_cs);
cur_chr= get_prim_equiv(cur_cs);
cur_tok= (cur_cmd*STRING_OFFSET)+cur_chr;
main_control_state= goto_skip_token;
}
}
}

/*:12*//*13:*/
#line 237 "./luatexdir/tex/maincontrol.w"

static void run_stop(void){
if(its_all_over())
main_control_state= goto_return;
}

/*:13*//*14:*/
#line 243 "./luatexdir/tex/maincontrol.w"

static void run_non_math_math(void){
back_input();
new_graf(true);
}

/*:14*//*15:*/
#line 249 "./luatexdir/tex/maincontrol.w"

static void run_math_char_num(void){
mathcodeval mval;
if(cur_chr==0)
mval= scan_mathchar(tex_mathcode);
else if(cur_chr==1)
mval= scan_mathchar(umath_mathcode);
else
mval= scan_mathchar(umathnum_mathcode);
math_char_in_text(mval);
}

/*:15*//*16:*/
#line 261 "./luatexdir/tex/maincontrol.w"

static void run_math_given(void){
mathcodeval mval;
mval= mathchar_from_integer(cur_chr,tex_mathcode);
math_char_in_text(mval);
}

static void run_xmath_given(void){
mathcodeval mval;
mval= mathchar_from_integer(cur_chr,umath_mathcode);
math_char_in_text(mval);
}

/*:16*//*17:*/
#line 289 "./luatexdir/tex/maincontrol.w"

static void run_rule(void){
tail_append(scan_rule_spec());
if(abs(mode)==vmode)
prev_depth_par= ignore_depth;
else if(abs(mode)==hmode)
space_factor_par= 1000;
}

/*:17*//*18:*/
#line 320 "./luatexdir/tex/maincontrol.w"

static void run_left_brace(void){
new_save_level(simple_group);
eq_word_define(int_base+no_local_whatsits_code,0);
eq_word_define(int_base+no_local_dirs_code,0);
}

static void run_begin_group(void){
new_save_level(semi_simple_group);
eq_word_define(int_base+no_local_whatsits_code,0);
eq_word_define(int_base+no_local_dirs_code,0);
}

static void run_end_group(void){
if(cur_group==semi_simple_group){
fixup_directions();
}else{
off_save();
}
}

/*:18*//*19:*/
#line 345 "./luatexdir/tex/maincontrol.w"

static void run_move(void){
int t= cur_chr;
scan_normal_dimen();
if(t==0)
scan_box(cur_val);
else
scan_box(-cur_val);
}

/*:19*//*20:*/
#line 355 "./luatexdir/tex/maincontrol.w"

static void run_leader_ship(void){
scan_box(leader_flag-a_leaders+cur_chr);
}

/*:20*//*21:*/
#line 360 "./luatexdir/tex/maincontrol.w"

static void run_make_box(void){
begin_box(0);
}

/*:21*//*22:*/
#line 365 "./luatexdir/tex/maincontrol.w"

static void run_box_dir(void){
scan_register_num();
cur_box= box(cur_val);
scan_optional_equals();
scan_direction();
if(cur_box!=null)
box_dir(cur_box)= cur_val;
}

/*:22*//*23:*/
#line 384 "./luatexdir/tex/maincontrol.w"

static void run_start_par_vmode(void){
new_graf((cur_chr> 0));
}

/*:23*//*24:*/
#line 389 "./luatexdir/tex/maincontrol.w"

static void run_start_par(void){
if(cur_chr!=2)
indent_in_hmode();
}

/*:24*//*25:*/
#line 395 "./luatexdir/tex/maincontrol.w"

static void run_new_graf(void){
back_input();
new_graf(true);
}

/*:25*//*26:*/
#line 405 "./luatexdir/tex/maincontrol.w"

static void run_par_end_vmode(void){
normal_paragraph();
if(mode> 0){
checked_page_filter(vmode_par);
build_page();
}
}

/*:26*//*27:*/
#line 414 "./luatexdir/tex/maincontrol.w"

static void run_par_end_hmode(void){
if(align_state<0)
off_save();
end_graf(bottom_level);
if(mode==vmode){
checked_page_filter(hmode_par);
build_page();
}
}

/*:27*//*28:*/
#line 425 "./luatexdir/tex/maincontrol.w"

static void append_italic_correction_mmode(void){
tail_append(new_kern(0));
}

/*:28*//*29:*/
#line 430 "./luatexdir/tex/maincontrol.w"

static void run_local_box(void){
append_local_box(cur_chr);
}

/*:29*//*30:*/
#line 435 "./luatexdir/tex/maincontrol.w"

static void run_halign_mmode(void){
if(privileged()){
if(cur_group==math_shift_group)
init_align();
else
off_save();
}
}

/*:30*//*31:*/
#line 445 "./luatexdir/tex/maincontrol.w"

static void run_eq_no(void){
if(privileged()){
if(cur_group==math_shift_group)
start_eq_no();
else
off_save();
}
}

/*:31*//*32:*/
#line 455 "./luatexdir/tex/maincontrol.w"

static void run_letter_mmode(void){
set_math_char(get_math_code(cur_chr));
}

/*:32*//*33:*/
#line 460 "./luatexdir/tex/maincontrol.w"

static void run_char_num_mmode(void){
scan_char_num();
cur_chr= cur_val;
set_math_char(get_math_code(cur_chr));
}

/*:33*//*34:*/
#line 467 "./luatexdir/tex/maincontrol.w"

static void run_math_char_num_mmode(void){
mathcodeval mval;
if(cur_chr==0)
mval= scan_mathchar(tex_mathcode);
else if(cur_chr==1)
mval= scan_mathchar(umath_mathcode);
else
mval= scan_mathchar(umathnum_mathcode);
set_math_char(mval);
}

/*:34*//*35:*/
#line 479 "./luatexdir/tex/maincontrol.w"

static void run_math_given_mmode(void){
mathcodeval mval;
mval= mathchar_from_integer(cur_chr,tex_mathcode);
set_math_char(mval);
}

static void run_xmath_given_mmode(void){
mathcodeval mval;
mval= mathchar_from_integer(cur_chr,umath_mathcode);
set_math_char(mval);
}

/*:35*//*36:*/
#line 492 "./luatexdir/tex/maincontrol.w"

static void run_delim_num(void){
mathcodeval mval;
if(cur_chr==0)
mval= scan_delimiter_as_mathchar(tex_mathcode);
else
mval= scan_delimiter_as_mathchar(umath_mathcode);
set_math_char(mval);

}

/*:36*//*37:*/
#line 503 "./luatexdir/tex/maincontrol.w"

static void run_vcenter(void){
scan_spec(vcenter_group);
normal_paragraph();
push_nest();
mode= -vmode;
prev_depth_par= ignore_depth;
if(every_vbox_par!=null)
begin_token_list(every_vbox_par,every_vbox_text);
}

/*:37*//*38:*/
#line 514 "./luatexdir/tex/maincontrol.w"

static void run_math_style(void){
tail_append(new_style((small_number)cur_chr));
}

/*:38*//*39:*/
#line 519 "./luatexdir/tex/maincontrol.w"

static void run_non_script(void){
tail_append(new_glue(zero_glue));
subtype(tail)= cond_math_glue;
}

/*:39*//*40:*/
#line 525 "./luatexdir/tex/maincontrol.w"

static void run_math_choice(void){
if(cur_chr==0)
append_choices();
else
setup_math_style();
}

/*:40*//*41:*/
#line 533 "./luatexdir/tex/maincontrol.w"

static void run_math_shift(void){
if(cur_group==math_shift_group)
after_math();
else
off_save();
}

/*:41*//*42:*/
#line 541 "./luatexdir/tex/maincontrol.w"

static void run_after_assignment(void){
get_token();
after_token= cur_tok;
}

/*:42*//*43:*/
#line 547 "./luatexdir/tex/maincontrol.w"

static void run_after_group(void){
get_token();
save_for_after(cur_tok);
}

/*:43*//*44:*/
#line 553 "./luatexdir/tex/maincontrol.w"

static void run_extension(void){
do_extension(0);
}

static void run_normal(void){
{
switch(cur_chr){
case save_pos_code:
new_whatsit(save_pos_node);
break;
case save_cat_code_table_code:
scan_int();
if((cur_val<0)||(cur_val> 0x7FFF)){
print_err("Invalid \\catcode table");
help1("All \\catcode table ids must be between 0 and 0x7FFF");
error();
}else{
if(cur_val==cat_code_table_par){
print_err("Invalid \\catcode table");
help1("You cannot overwrite the current \\catcode table");
error();
}else{
copy_cat_codes(cat_code_table_par,cur_val);
}
}
break;
case init_cat_code_table_code:
scan_int();
if((cur_val<0)||(cur_val> 0x7FFF)){
print_err("Invalid \\catcode table");
help1("All \\catcode table ids must be between 0 and 0x7FFF");
error();
}else{
if(cur_val==cat_code_table_par){
print_err("Invalid \\catcode table");
help1("You cannot overwrite the current \\catcode table");
error();
}else{
initex_cat_codes(cur_val);
}
}
break;
case set_random_seed_code:

scan_int();
if(cur_val<0)
negate(cur_val);
random_seed= cur_val;
init_randoms(random_seed);
break;
case late_lua_code:
new_whatsit(late_lua_node);
late_lua_name(tail)= scan_lua_state();
(void)scan_toks(false,false);
late_lua_data(tail)= def_ref;
break;
case expand_font_code:
read_expand_font();
break;
default:
confusion("int1");
break;
}
}
}







#define mathoption_set_int(A) \
    scan_int(); \
    word_define(mathoption_int_base+A, cur_val);

static void run_option(void){
int a= 0;
switch(cur_chr){
case math_option_code:
if(scan_keyword("old")){
mathoption_set_int(c_mathoption_old_code);
}else if(scan_keyword("noitaliccompensation")){
mathoption_set_int(c_mathoption_no_italic_compensation_code);
}else if(scan_keyword("nocharitalic")){
mathoption_set_int(c_mathoption_no_char_italic_code);
}else if(scan_keyword("useoldfractionscaling")){
mathoption_set_int(c_mathoption_use_old_fraction_scaling_code);
}else if(scan_keyword("umathcodemeaning")){
mathoption_set_int(c_mathoption_umathcode_meaning_code);
}else{
normal_warning("mathoption","unknown key");
}
break;
default:

break;
}
}

/*:44*//*45:*/
#line 660 "./luatexdir/tex/maincontrol.w"

#define any_mode(A,B) jump_table[vmode+(A)]= B; jump_table[hmode+(A)]= B; jump_table[mmode+(A)]= B
#define non_math(A,B) jump_table[vmode+(A)]= B; jump_table[hmode+(A)]= B;


/*:45*//*46:*/
#line 666 "./luatexdir/tex/maincontrol.w"

typedef void(*main_control_function)(void);
main_control_function*jump_table;

static void init_main_control(void){
jump_table= xmalloc((mmode+max_command_cmd+1)*sizeof(main_control_function));

jump_table[hmode+char_num_cmd]= run_char_num;
jump_table[hmode+letter_cmd]= run_char;
jump_table[hmode+other_char_cmd]= run_char;
jump_table[hmode+char_given_cmd]= run_char;
jump_table[hmode+spacer_cmd]= run_app_space;
jump_table[hmode+ex_space_cmd]= run_app_space;
jump_table[mmode+ex_space_cmd]= run_app_space;
jump_table[hmode+boundary_cmd]= run_boundary;
jump_table[hmode+char_ghost_cmd]= run_char_ghost;
jump_table[mmode+char_ghost_cmd]= run_char_ghost;
any_mode(relax_cmd,run_relax);
jump_table[vmode+spacer_cmd]= run_relax;
jump_table[mmode+spacer_cmd]= run_relax;
jump_table[mmode+boundary_cmd]= run_relax;
any_mode(ignore_spaces_cmd,run_ignore_spaces);
jump_table[vmode+stop_cmd]= run_stop;
jump_table[vmode+math_char_num_cmd]= run_non_math_math;
jump_table[vmode+math_given_cmd]= run_non_math_math;
jump_table[vmode+xmath_given_cmd]= run_non_math_math;
jump_table[hmode+math_char_num_cmd]= run_math_char_num;
jump_table[hmode+math_given_cmd]= run_math_given;
jump_table[hmode+xmath_given_cmd]= run_xmath_given;

jump_table[vmode+vmove_cmd]= report_illegal_case;
jump_table[hmode+hmove_cmd]= report_illegal_case;
jump_table[mmode+hmove_cmd]= report_illegal_case;
any_mode(last_item_cmd,report_illegal_case);
jump_table[vmode+vadjust_cmd]= report_illegal_case;
jump_table[vmode+ital_corr_cmd]= report_illegal_case;
non_math(eq_no_cmd,report_illegal_case);
any_mode(mac_param_cmd,report_illegal_case);

non_math(sup_mark_cmd,insert_dollar_sign);
non_math(sub_mark_cmd,insert_dollar_sign);
non_math(super_sub_script_cmd,insert_dollar_sign);
non_math(math_comp_cmd,insert_dollar_sign);
non_math(delim_num_cmd,insert_dollar_sign);
non_math(left_right_cmd,insert_dollar_sign);
non_math(above_cmd,insert_dollar_sign);
non_math(radical_cmd,insert_dollar_sign);
non_math(math_style_cmd,insert_dollar_sign);
non_math(math_choice_cmd,insert_dollar_sign);
non_math(vcenter_cmd,insert_dollar_sign);
non_math(non_script_cmd,insert_dollar_sign);
non_math(mkern_cmd,insert_dollar_sign);
non_math(limit_switch_cmd,insert_dollar_sign);
non_math(mskip_cmd,insert_dollar_sign);
non_math(math_accent_cmd,insert_dollar_sign);
jump_table[mmode+endv_cmd]= insert_dollar_sign;
jump_table[mmode+par_end_cmd]= insert_dollar_sign_par_end;
jump_table[mmode+stop_cmd]= insert_dollar_sign;
jump_table[mmode+vskip_cmd]= insert_dollar_sign;
jump_table[mmode+un_vbox_cmd]= insert_dollar_sign;
jump_table[mmode+valign_cmd]= insert_dollar_sign;
jump_table[mmode+hrule_cmd]= insert_dollar_sign;
jump_table[mmode+no_hrule_cmd]= insert_dollar_sign;
jump_table[vmode+hrule_cmd]= run_rule;
jump_table[vmode+no_hrule_cmd]= run_rule;
jump_table[hmode+vrule_cmd]= run_rule;
jump_table[hmode+no_vrule_cmd]= run_rule;
jump_table[mmode+vrule_cmd]= run_rule;
jump_table[mmode+no_vrule_cmd]= run_rule;
jump_table[vmode+vskip_cmd]= append_glue;
jump_table[hmode+hskip_cmd]= append_glue;
jump_table[mmode+hskip_cmd]= append_glue;
jump_table[mmode+mskip_cmd]= append_glue;
any_mode(kern_cmd,append_kern);
jump_table[mmode+mkern_cmd]= append_kern;
non_math(left_brace_cmd,run_left_brace);
any_mode(begin_group_cmd,run_begin_group);
any_mode(end_group_cmd,run_end_group);
any_mode(right_brace_cmd,handle_right_brace);
jump_table[vmode+hmove_cmd]= run_move;
jump_table[hmode+vmove_cmd]= run_move;
jump_table[mmode+vmove_cmd]= run_move;
any_mode(leader_ship_cmd,run_leader_ship);
any_mode(make_box_cmd,run_make_box);
any_mode(assign_box_dir_cmd,run_box_dir);
jump_table[vmode+start_par_cmd]= run_start_par_vmode;
jump_table[hmode+start_par_cmd]= run_start_par;
jump_table[mmode+start_par_cmd]= run_start_par;
jump_table[vmode+letter_cmd]= run_new_graf;
jump_table[vmode+other_char_cmd]= run_new_graf;
jump_table[vmode+char_num_cmd]= run_new_graf;
jump_table[vmode+char_given_cmd]= run_new_graf;
jump_table[vmode+char_ghost_cmd]= run_new_graf;
jump_table[vmode+math_shift_cmd]= run_new_graf;
jump_table[vmode+math_shift_cs_cmd]= run_new_graf;
jump_table[vmode+un_hbox_cmd]= run_new_graf;
jump_table[vmode+vrule_cmd]= run_new_graf;
jump_table[vmode+no_vrule_cmd]= run_new_graf;
jump_table[vmode+accent_cmd]= run_new_graf;
jump_table[vmode+discretionary_cmd]= run_new_graf;
jump_table[vmode+hskip_cmd]= run_new_graf;
jump_table[vmode+valign_cmd]= run_new_graf;
jump_table[vmode+ex_space_cmd]= run_new_graf;
jump_table[vmode+boundary_cmd]= run_new_graf;
jump_table[vmode+par_end_cmd]= run_par_end_vmode;
jump_table[hmode+par_end_cmd]= run_par_end_hmode;
jump_table[hmode+stop_cmd]= head_for_vmode;
jump_table[hmode+vskip_cmd]= head_for_vmode;
jump_table[hmode+hrule_cmd]= head_for_vmode;
jump_table[hmode+no_hrule_cmd]= head_for_vmode;
jump_table[hmode+un_vbox_cmd]= head_for_vmode;
jump_table[hmode+halign_cmd]= head_for_vmode;
any_mode(insert_cmd,begin_insert_or_adjust);
jump_table[hmode+vadjust_cmd]= begin_insert_or_adjust;
jump_table[mmode+vadjust_cmd]= begin_insert_or_adjust;
any_mode(mark_cmd,handle_mark);
any_mode(break_penalty_cmd,append_penalty);
any_mode(remove_item_cmd,delete_last);
jump_table[vmode+un_vbox_cmd]= unpackage;
jump_table[hmode+un_hbox_cmd]= unpackage;
jump_table[mmode+un_hbox_cmd]= unpackage;
jump_table[hmode+ital_corr_cmd]= append_italic_correction;
jump_table[mmode+ital_corr_cmd]= append_italic_correction_mmode;
jump_table[hmode+discretionary_cmd]= append_discretionary;
jump_table[mmode+discretionary_cmd]= append_discretionary;
any_mode(assign_local_box_cmd,run_local_box);
jump_table[hmode+accent_cmd]= make_accent;
any_mode(car_ret_cmd,align_error);
any_mode(tab_mark_cmd,align_error);
any_mode(no_align_cmd,no_align_error);
any_mode(omit_cmd,omit_error);
jump_table[vmode+halign_cmd]= init_align;
jump_table[hmode+valign_cmd]= init_align;
jump_table[mmode+halign_cmd]= run_halign_mmode;
jump_table[vmode+endv_cmd]= do_endv;
jump_table[hmode+endv_cmd]= do_endv;
any_mode(end_cs_name_cmd,cs_error);
jump_table[hmode+math_shift_cmd]= init_math;
jump_table[hmode+math_shift_cs_cmd]= init_math;
jump_table[mmode+eq_no_cmd]= run_eq_no;
jump_table[mmode+left_brace_cmd]= math_left_brace;
jump_table[mmode+letter_cmd]= run_letter_mmode;
jump_table[mmode+other_char_cmd]= run_letter_mmode;
jump_table[mmode+char_given_cmd]= run_letter_mmode;
jump_table[mmode+char_num_cmd]= run_char_num_mmode;
jump_table[mmode+math_char_num_cmd]= run_math_char_num_mmode;
jump_table[mmode+math_given_cmd]= run_math_given_mmode;
jump_table[mmode+xmath_given_cmd]= run_xmath_given_mmode;
jump_table[mmode+delim_num_cmd]= run_delim_num;
jump_table[mmode+math_comp_cmd]= math_math_comp;
jump_table[mmode+limit_switch_cmd]= math_limit_switch;
jump_table[mmode+radical_cmd]= math_radical;
jump_table[mmode+accent_cmd]= math_ac;
jump_table[mmode+math_accent_cmd]= math_ac;
jump_table[mmode+vcenter_cmd]= run_vcenter;
jump_table[mmode+math_style_cmd]= run_math_style;
jump_table[mmode+non_script_cmd]= run_non_script;
jump_table[mmode+math_choice_cmd]= run_math_choice;
jump_table[mmode+above_cmd]= math_fraction;
jump_table[mmode+sub_mark_cmd]= sub_sup;
jump_table[mmode+sup_mark_cmd]= sub_sup;
jump_table[mmode+super_sub_script_cmd]= sub_sup;
jump_table[mmode+left_right_cmd]= math_left_right;
jump_table[mmode+math_shift_cmd]= run_math_shift;
jump_table[mmode+math_shift_cs_cmd]= run_math_shift;
any_mode(toks_register_cmd,prefixed_command);
any_mode(assign_toks_cmd,prefixed_command);
any_mode(assign_int_cmd,prefixed_command);
any_mode(assign_attr_cmd,prefixed_command);
any_mode(assign_dir_cmd,prefixed_command);
any_mode(assign_dimen_cmd,prefixed_command);
any_mode(assign_glue_cmd,prefixed_command);
any_mode(assign_mu_glue_cmd,prefixed_command);
any_mode(assign_font_dimen_cmd,prefixed_command);
any_mode(assign_font_int_cmd,prefixed_command);
any_mode(set_aux_cmd,prefixed_command);
any_mode(set_prev_graf_cmd,prefixed_command);
any_mode(set_page_dimen_cmd,prefixed_command);
any_mode(set_page_int_cmd,prefixed_command);
any_mode(set_box_dimen_cmd,prefixed_command);
any_mode(set_tex_shape_cmd,prefixed_command);
any_mode(set_etex_shape_cmd,prefixed_command);
any_mode(def_char_code_cmd,prefixed_command);
any_mode(def_del_code_cmd,prefixed_command);
any_mode(extdef_math_code_cmd,prefixed_command);
any_mode(extdef_del_code_cmd,prefixed_command);
any_mode(def_family_cmd,prefixed_command);
any_mode(set_math_param_cmd,prefixed_command);
any_mode(set_font_cmd,prefixed_command);
any_mode(def_font_cmd,prefixed_command);
any_mode(letterspace_font_cmd,prefixed_command);
any_mode(copy_font_cmd,prefixed_command);
any_mode(set_font_id_cmd,prefixed_command);
any_mode(register_cmd,prefixed_command);
any_mode(advance_cmd,prefixed_command);
any_mode(multiply_cmd,prefixed_command);
any_mode(divide_cmd,prefixed_command);
any_mode(prefix_cmd,prefixed_command);
any_mode(let_cmd,prefixed_command);
any_mode(shorthand_def_cmd,prefixed_command);
any_mode(read_to_cs_cmd,prefixed_command);
any_mode(def_cmd,prefixed_command);
any_mode(set_box_cmd,prefixed_command);
any_mode(hyph_data_cmd,prefixed_command);
any_mode(set_interaction_cmd,prefixed_command);
any_mode(after_assignment_cmd,run_after_assignment);
any_mode(after_group_cmd,run_after_group);
any_mode(in_stream_cmd,open_or_close_in);
any_mode(message_cmd,issue_message);
any_mode(case_shift_cmd,shift_case);
any_mode(xray_cmd,show_whatever);
any_mode(normal_cmd,run_normal);
any_mode(extension_cmd,run_extension);
any_mode(option_cmd,run_option);
}

/*:46*//*47:*/
#line 884 "./luatexdir/tex/maincontrol.w"

void main_control(void)
{
main_control_state= goto_next;
init_main_control();

if(equiv(every_job_loc)!=null)
begin_token_list(equiv(every_job_loc),every_job_text);

while(1){
if(main_control_state==goto_skip_token)
main_control_state= goto_next;
else
get_x_token();




if(interrupt!=0&&OK_to_interrupt){
back_input();
check_interrupt();
continue;
}
if(tracing_commands_par> 0)
show_cur_cmd_chr();

(jump_table[(abs(mode)+cur_cmd)])();

if(main_control_state==goto_return){
return;
}
}
return;
}

/*:47*//*48:*/
#line 919 "./luatexdir/tex/maincontrol.w"

void app_space(void)
{
halfword q;
if((space_factor_par>=2000)&&(!glue_is_zero(xspace_skip_par))){
q= new_param_glue(xspace_skip_code);

subtype(q)= xspace_skip_code+1;
}else{
if(!glue_is_zero(space_skip_par)){
q= new_glue(space_skip_par);
}else{
q= new_glue(zero_glue);
width(q)= space(cur_font_par);
stretch(q)= space_stretch(cur_font_par);
shrink(q)= space_shrink(cur_font_par);
}

if(space_factor_par>=2000)
width(q)= width(q)+extra_space(cur_font_par);
stretch(q)= xn_over_d(stretch(q),space_factor_par,1000);
shrink(q)= xn_over_d(shrink(q),1000,space_factor_par);


subtype(q)= space_skip_code+1;
}
couple_nodes(tail,q);
tail= q;
}

/*:48*//*49:*/
#line 949 "./luatexdir/tex/maincontrol.w"

void insert_dollar_sign(void)
{
back_input();
cur_tok= math_shift_token+'$';
print_err("Missing $ inserted");
help2("I've inserted a begin-math/end-math symbol since I think",
"you left one out. Proceed, with fingers crossed.");
ins_error();
}

/*:49*//*50:*/
#line 962 "./luatexdir/tex/maincontrol.w"

void insert_dollar_sign_par_end(void)
{
if(!suppress_mathpar_error_par){
insert_dollar_sign();
}
}

/*:50*//*51:*/
#line 973 "./luatexdir/tex/maincontrol.w"

void you_cant(void)
{
print_err("You can't use `");
print_cmd_chr((quarterword)cur_cmd,cur_chr);
print_in_mode(mode);
}

/*:51*//*52:*/
#line 992 "./luatexdir/tex/maincontrol.w"

void report_illegal_case(void)
{
you_cant();
help4("Sorry, but I'm not programmed to handle this case;",
"I'll just pretend that you didn''t ask for it.",
"If you're in the wrong mode, you might be able to",
"return to the right one by typing `I}' or `I$' or `I\\par'.");
error();
}

/*:52*//*53:*/
#line 1008 "./luatexdir/tex/maincontrol.w"

boolean privileged(void)
{
if(mode> 0){
return true;
}else{
report_illegal_case();
return false;
}
}

/*:53*//*54:*/
#line 1027 "./luatexdir/tex/maincontrol.w"

boolean its_all_over(void)
{
if(privileged()){
if((page_head==page_tail)&&(head==tail)&&(dead_cycles==0)){
return true;
}
back_input();
tail_append(new_null_box());
width(tail)= hsize_par;
tail_append(new_glue(fill_glue));
tail_append(new_penalty(-010000000000));
normal_page_filter(end);
build_page();
}
return false;
}


/*:54*//*55:*/
#line 1054 "./luatexdir/tex/maincontrol.w"

void append_glue(void)
{
int s= cur_chr;
switch(s){
case fil_code:
cur_val= new_glue(fil_glue);
break;
case fill_code:
cur_val= new_glue(fill_glue);
break;
case ss_code:
cur_val= new_glue(ss_glue);
break;
case fil_neg_code:
cur_val= new_glue(fil_neg_glue);
break;
case skip_code:
scan_glue(glue_val_level);
break;
case mskip_code:
scan_glue(mu_val_level);
break;
}

tail_append(new_glue(cur_val));
flush_node(cur_val);
if(s> skip_code){
subtype(tail)= mu_glue;
}
}

/*:55*//*56:*/
#line 1086 "./luatexdir/tex/maincontrol.w"

void append_kern(void)
{
int s;
s= cur_chr;
scan_dimen((s==mu_glue),false,false);
tail_append(new_kern(cur_val));
subtype(tail)= (quarterword)s;
}

/*:56*//*57:*/
#line 1106 "./luatexdir/tex/maincontrol.w"

void off_save(void)
{
halfword p,q;
if(cur_group==bottom_level){

print_err("Extra ");
print_cmd_chr((quarterword)cur_cmd,cur_chr);
help1("Things are pretty mixed up, but I think the worst is over.");
error();

}else{
back_input();
p= get_avail();
set_token_link(temp_token_head,p);
print_err("Missing ");


switch(cur_group){
case semi_simple_group:
set_token_info(p,cs_token_flag+frozen_end_group);
tprint_esc("endgroup");
break;
case math_shift_group:
set_token_info(p,math_shift_token+'$');
print_char('$');
break;
case math_left_group:
set_token_info(p,cs_token_flag+frozen_right);
q= get_avail();
set_token_link(p,q);
p= token_link(p);
set_token_info(p,other_token+'.');
tprint_esc("right.");
break;
default:
set_token_info(p,right_brace_token+'}');
print_char('}');
break;
}
tprint(" inserted");
ins_list(token_link(temp_token_head));
help5("I've inserted something that you may have forgotten.",
"(See the <inserted text> above.)",
"With luck, this will get me unwedged. But if you",
"really didn't forget anything, try typing `2' now; then",
"my insertion and my current dilemma will both disappear.");
error();
}
}

/*:57*//*58:*/
#line 1164 "./luatexdir/tex/maincontrol.w"

void handle_right_brace(void)
{
halfword p,q;
scaled d;
int f;
p= null;
switch(cur_group){
case simple_group:
fixup_directions();
break;
case bottom_level:
print_err("Too many }'s");
help2("You've closed more groups than you opened.",
"Such booboos are generally harmless, so keep going.");
error();
break;
case semi_simple_group:
case math_shift_group:
case math_left_group:
extra_right_brace();
break;
case hbox_group:



package(0);
break;
case adjusted_hbox_group:
adjust_tail= adjust_head;
pre_adjust_tail= pre_adjust_head;
package(0);
break;
case vbox_group:
end_graf(vbox_group);
package(0);
break;
case vtop_group:
end_graf(vtop_group);
package(vtop_code);
break;
case insert_group:
end_graf(insert_group);
q= new_glue(split_top_skip_par);
d= split_max_depth_par;
f= floating_penalty_par;
unsave();
save_ptr--;

p= vpack(vlink(head),0,additional,-1);
pop_nest();
if(saved_type(0)==saved_insert){
tail_append(new_node(ins_node,saved_value(0)));
height(tail)= height(p)+depth(p);
ins_ptr(tail)= list_ptr(p);
split_top_ptr(tail)= q;
depth(tail)= d;
float_cost(tail)= f;
}else if(saved_type(0)==saved_adjust){
tail_append(new_node(adjust_node,saved_value(0)));
adjust_ptr(tail)= list_ptr(p);
flush_node(q);
}else{
confusion("insert_group");
}
list_ptr(p)= null;
flush_node(p);
if(nest_ptr==0){
checked_page_filter(insert);
build_page();
}
break;
case output_group:

if(dir_level(text_dir_ptr)==cur_level){

halfword text_dir_tmp= vlink(text_dir_ptr);
flush_node(text_dir_ptr);
text_dir_ptr= text_dir_tmp;
}
resume_after_output();
break;
case disc_group:
build_discretionary();
break;
case local_box_group:
build_local_box();
break;
case align_group:
back_input();
cur_tok= cs_token_flag+frozen_cr;
print_err("Missing \\cr inserted");
help1("I'm guessing that you meant to end an alignment here.");
ins_error();
break;
case no_align_group:
end_graf(no_align_group);
unsave();
align_peek();
break;
case vcenter_group:
end_graf(vcenter_group);
finish_vcenter();
break;
case math_choice_group:
build_choices();
break;
case math_group:
close_math_group(p);
break;
default:
confusion("rightbrace");
break;
}
}

/*:58*//*59:*/
#line 1280 "./luatexdir/tex/maincontrol.w"

void extra_right_brace(void)
{
print_err("Extra }, or forgotten ");
switch(cur_group){
case semi_simple_group:
tprint_esc("endgroup");
break;
case math_shift_group:
print_char('$');
break;
case math_left_group:
tprint_esc("right");
break;
}
help5("I've deleted a group-closing symbol because it seems to be",
"spurious, as in `$x}$'. But perhaps the } is legitimate and",
"you forgot something else, as in `\\hbox{$x}'. In such cases",
"the way to recover is to insert both the forgotten and the",
"deleted material, e.g., by typing `I$}'.");
error();
incr(align_state);
}

/*:59*//*60:*/
#line 1307 "./luatexdir/tex/maincontrol.w"

void normal_paragraph(void)
{
if(looseness_par!=0)
eq_word_define(int_base+looseness_code,0);
if(hang_indent_par!=0)
eq_word_define(dimen_base+hang_indent_code,0);
if(hang_after_par!=1)
eq_word_define(int_base+hang_after_code,1);
if(par_shape_par_ptr!=null)
eq_define(par_shape_loc,shape_ref_cmd,null);
if(inter_line_penalties_par_ptr!=null)
eq_define(inter_line_penalties_loc,shape_ref_cmd,null);
if(shape_mode_par> 0)
eq_word_define(dimen_base+shape_mode_code,0);
}

/*:60*//*61:*/
#line 1329 "./luatexdir/tex/maincontrol.w"

halfword cur_box;

/*:61*//*62:*/
#line 1335 "./luatexdir/tex/maincontrol.w"

void box_end(int box_context)
{
if(box_context<box_flag){






if(cur_box!=null){
shift_amount(cur_box)= box_context;
if(abs(mode)==vmode){
if(pre_adjust_tail!=null){
if(pre_adjust_head!=pre_adjust_tail)
append_list(pre_adjust_head,pre_adjust_tail);
pre_adjust_tail= null;
}
append_to_vlist(cur_box,lua_key_index(box));
if(adjust_tail!=null){
if(adjust_head!=adjust_tail)
append_list(adjust_head,adjust_tail);
adjust_tail= null;
}
if(mode> 0){
checked_page_filter(box);
build_page();
}
}else{
if(abs(mode)==hmode)
space_factor_par= 1000;
else
cur_box= new_sub_box(cur_box);
couple_nodes(tail,cur_box);
tail= cur_box;
}
}
}else if(box_context<ship_out_flag){

if(box_context<global_box_flag)
eq_define(box_base+box_context-box_flag,box_ref_cmd,cur_box);
else
geq_define(box_base+box_context-global_box_flag,box_ref_cmd,cur_box);
}else if(cur_box!=null){
if(box_context> ship_out_flag){


do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));
if(((cur_cmd==hskip_cmd)&&(abs(mode)!=vmode))||
((cur_cmd==vskip_cmd)&&(abs(mode)==vmode))){
append_glue();
subtype(tail)= (quarterword)(box_context-(leader_flag-a_leaders));
leader_ptr(tail)= cur_box;
}else{
print_err("Leaders not followed by proper glue");
help3
("You should say `\\leaders <box or rule><hskip or vskip>'.",
"I found the <box or rule>, but there's no suitable",
"<hskip or vskip>, so I'm ignoring these leaders.");
back_error();
flush_node_list(cur_box);
}
}else{
ship_out(static_pdf,cur_box,SHIPPING_PAGE);
}
}
}

/*:62*//*63:*/
#line 1407 "./luatexdir/tex/maincontrol.w"

void scan_box(int box_context)
{

do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));
if(cur_cmd==make_box_cmd){
begin_box(box_context);
}else if((box_context>=leader_flag)&&
((cur_cmd==hrule_cmd)||(cur_cmd==vrule_cmd)||
(cur_cmd==no_hrule_cmd)||(cur_cmd==no_vrule_cmd))){
cur_box= scan_rule_spec();
box_end(box_context);
}else{
print_err("A <box> was supposed to be here");
help3("I was expecting to see \\hbox or \\vbox or \\copy or \\box or",
"something like that. So you might find something missing in",
"your output. But keep trying; you can fix this later.");
back_error();
}
}

/*:63*//*64:*/
#line 1430 "./luatexdir/tex/maincontrol.w"

void new_graf(boolean indented)
{
halfword p,q,dir_graf_tmp;
halfword dir_rover;
prev_graf_par= 0;
if((mode==vmode)||(head!=tail)){
tail_append(new_param_glue(par_skip_code));
}
push_nest();
mode= hmode;
space_factor_par= 1000;

tail_append(make_local_par_node(new_graf_par_code));
if(indented){
p= new_null_box();
box_dir(p)= par_direction_par;
width(p)= par_indent_par;
subtype(p)= indent_list;
q= tail;
tail_append(p);
}else{
q= tail;
}
dir_rover= text_dir_ptr;
while(dir_rover!=null){
if((vlink(dir_rover)!=null)||(dir_dir(dir_rover)!=par_direction_par)){
dir_graf_tmp= new_dir(dir_dir(dir_rover));
try_couple_nodes(dir_graf_tmp,vlink(q));
couple_nodes(q,dir_graf_tmp);
}
dir_rover= vlink(dir_rover);
}
q= head;
while(vlink(q)!=null)
q= vlink(q);
tail= q;
if(every_par_par!=null)
begin_token_list(every_par_par,every_par_text);
if(nest_ptr==1){
checked_page_filter(new_graf);
build_page();
}
}

/*:64*//*65:*/
#line 1475 "./luatexdir/tex/maincontrol.w"

void indent_in_hmode(void)
{
halfword p;
if(cur_chr> 0){
p= new_null_box();
width(p)= par_indent_par;
if(abs(mode)==hmode)
space_factor_par= 1000;
else
p= new_sub_box(p);
tail_append(p);
}
}

/*:65*//*66:*/
#line 1490 "./luatexdir/tex/maincontrol.w"

void head_for_vmode(void)
{
if(mode<0){
if((cur_cmd!=hrule_cmd)&&(cur_cmd!=no_hrule_cmd)){
off_save();
}else{
print_err("You can't use `\\hrule' here except with leaders");
help2("To put a horizontal rule in an hbox or an alignment,",
"you should use \\leaders or \\hrulefill (see The TeXbook).");
error();
}
}else{
back_input();
cur_tok= par_token;
back_input();
token_type= inserted;
}
}

/*:66*//*67:*/
#line 1515 "./luatexdir/tex/maincontrol.w"

void end_graf(int line_break_context)
{
if(mode==hmode){
if((head==tail)||(vlink(head)==tail)){
if(vlink(head)==tail)
flush_node(vlink(head));
pop_nest();
}else{
line_break(false,line_break_context);
}
if(dir_save!=null){
flush_node_list(dir_save);
dir_save= null;
}
normal_paragraph();
error_count= 0;
}
}

/*:67*//*68:*/
#line 1535 "./luatexdir/tex/maincontrol.w"

void begin_insert_or_adjust(void)
{
if(cur_cmd!=vadjust_cmd){
scan_register_num();
if(cur_val==output_box_par){
print_err("You can't \\insert");
print_int(output_box_par);
help1("I'm changing to \\insert0; box \\outputbox is special.");
error();
cur_val= 0;
}
set_saved_record(0,saved_insert,0,cur_val);
}else if(scan_keyword("pre")){
set_saved_record(0,saved_adjust,0,1);
}else{
set_saved_record(0,saved_adjust,0,0);
}
save_ptr++;
new_save_level(insert_group);
scan_left_brace();
normal_paragraph();
push_nest();
mode= -vmode;
prev_depth_par= ignore_depth;
}

/*:68*//*69:*/
#line 1567 "./luatexdir/tex/maincontrol.w"

void handle_mark(void)
{
halfword p;
halfword c;
if(cur_chr==clear_marks_code){
scan_mark_num();
c= cur_val;
delete_top_mark(c);
delete_bot_mark(c);
delete_first_mark(c);
delete_split_first_mark(c);
delete_split_bot_mark(c);
}else{
if(cur_chr==0){
c= 0;
}else{
scan_mark_num();
c= cur_val;
if(c> biggest_used_mark)
biggest_used_mark= c;
}
p= scan_toks(false,true);
p= new_node(mark_node,0);
mark_class(p)= c;
mark_ptr(p)= def_ref;
couple_nodes(tail,p);
tail= p;
}
}

/*:69*//*70:*/
#line 1598 "./luatexdir/tex/maincontrol.w"

void append_penalty(void)
{
scan_int();
tail_append(new_penalty(cur_val));
if(mode==vmode){
checked_page_filter(penalty);
build_page();
}
}

/*:70*//*71:*/
#line 1619 "./luatexdir/tex/maincontrol.w"

void delete_last(void)
{
halfword p,q;
if((mode==vmode)&&(tail==head)){


if((cur_chr!=glue_node)||(last_glue!=max_halfword)){
you_cant();
if(cur_chr==kern_node){
help2
("Sorry...I usually can't take things from the current page.",
"Try `I\\kern-\\lastkern' instead.");
}else if(cur_chr!=glue_node){
help2
("Sorry...I usually can't take things from the current page.",
"Perhaps you can make the output routine do it.");
}else{
help2
("Sorry...I usually can't take things from the current page.",
"Try `I\\vskip-\\lastskip' instead.");
}
error();
}
}else{

if(!is_char_node(tail)){
if(type(tail)==cur_chr){
q= head;
do{
p= q;
if(!is_char_node(q)){
if(type(q)==disc_node){
if(p==tail)
return;
}
}
q= vlink(p);
}while(q!=tail);
vlink(p)= null;
flush_node_list(tail);
tail= p;
}
}
}
}

/*:71*//*72:*/
#line 1666 "./luatexdir/tex/maincontrol.w"

void unpackage(void)
{
halfword p;
halfword r;
int c;
halfword s;
if(cur_chr> copy_code){

try_couple_nodes(tail,disc_ptr[cur_chr]);
disc_ptr[cur_chr]= null;
goto DONE;
}
c= cur_chr;
scan_register_num();
p= box(cur_val);
if(p==null)
return;
if((abs(mode)==mmode)
||((abs(mode)==vmode)&&(type(p)!=vlist_node))
||((abs(mode)==hmode)&&(type(p)!=hlist_node))){
print_err("Incompatible list can't be unboxed");
help3("Sorry, Pandora. (You sneaky devil.)",
"I refuse to unbox an \\hbox in vertical mode or vice versa.",
"And I can't open any boxes in math mode.");
error();
return;
}
if(c==copy_code){
s= copy_node_list(list_ptr(p));
try_couple_nodes(tail,s);
}else{
try_couple_nodes(tail,list_ptr(p));
box(cur_val)= null;
list_ptr(p)= null;
flush_node(p);
}
DONE:
while(vlink(tail)!=null){
r= vlink(tail);
if(!is_char_node(r)&&(type(r)==margin_kern_node)){
try_couple_nodes(tail,vlink(r));
flush_node(r);
}
tail= vlink(tail);
}
}

/*:72*//*73:*/
#line 1719 "./luatexdir/tex/maincontrol.w"

void append_italic_correction(void)
{
halfword p;
internal_font_number f;
if(tail!=head){
if(is_char_node(tail))
p= tail;
else
return;
f= font(p);
tail_append(new_kern(char_italic(f,character(p))));
subtype(tail)= italic_kern;
}
}

/*:73*//*74:*/
#line 1735 "./luatexdir/tex/maincontrol.w"

void append_local_box(int kind)
{
incr(save_ptr);
set_saved_record(-1,saved_boxtype,0,kind);
new_save_level(local_box_group);
scan_left_brace();
push_nest();
mode= -hmode;
space_factor_par= 1000;
}

/*:74*//*75:*/
#line 1753 "./luatexdir/tex/maincontrol.w"

void append_discretionary(void)
{
int c;
tail_append(new_disc());
subtype(tail)= (quarterword)cur_chr;
if(cur_chr==explicit_disc){

c= get_pre_hyphen_char(cur_lang_par);
if(c!=0){
vlink(pre_break(tail))= new_char(equiv(cur_font_loc),c);
alink(vlink(pre_break(tail)))= pre_break(tail);
tlink(pre_break(tail))= vlink(pre_break(tail));
}
c= get_post_hyphen_char(cur_lang_par);
if(c!=0){
vlink(post_break(tail))= new_char(equiv(cur_font_loc),c);
alink(vlink(post_break(tail)))= post_break(tail);
tlink(post_break(tail))= vlink(post_break(tail));
}
disc_penalty(tail)= ex_hyphen_penalty_par;
}else{

if(scan_keyword("penalty")){
scan_int();
disc_penalty(tail)= cur_val;
}
incr(save_ptr);
set_saved_record(-1,saved_disc,0,0);
new_save_level(disc_group);
scan_left_brace();
push_nest();
mode= -hmode;
space_factor_par= 1000;

}
}

/*:75*//*76:*/
#line 1794 "./luatexdir/tex/maincontrol.w"

void build_local_box(void)
{
halfword p;
int kind;
unsave();
assert(saved_type(-1)==saved_boxtype);
kind= saved_value(-1);
decr(save_ptr);
p= vlink(head);
pop_nest();
if(p!=null)
p= hpack(p,0,additional,-1);
if(kind==0)
eq_define(local_left_box_base,box_ref_cmd,p);
else
eq_define(local_right_box_base,box_ref_cmd,p);
if(abs(mode)==hmode){

tail_append(make_local_par_node(local_box_par_code));
}
eq_word_define(int_base+no_local_whatsits_code,no_local_whatsits_par+1);
}

/*:76*//*77:*/
#line 1822 "./luatexdir/tex/maincontrol.w"

void build_discretionary(void)
{
halfword p,q;
int n;
unsave();





q= head;
p= vlink(q);
n= 0;
while(p!=null){
if(!is_char_node(p)&&type(p)> rule_node&&type(p)!=kern_node){
print_err("Improper discretionary list");
help1("Discretionary lists must contain only boxes and kerns.");
error();
begin_diagnostic();
tprint_nl("The following discretionary sublist has been deleted:");
show_box(p);
end_diagnostic(true);
flush_node_list(p);
vlink(q)= null;
break;
}
alink(p)= q;
q= p;
p= vlink(q);
incr(n);
}

p= vlink(head);
pop_nest();
assert(saved_type(-1)==saved_disc);
switch(saved_value(-1)){
case 0:
if(n> 0){
vlink(pre_break(tail))= p;
alink(p)= pre_break(tail);
tlink(pre_break(tail))= q;
}
break;
case 1:
if(n> 0){
vlink(post_break(tail))= p;
alink(p)= post_break(tail);
tlink(post_break(tail))= q;
}
break;
case 2:


if((n> 0)&&(abs(mode)==mmode)){
print_err("Illegal math \\discretionary");
help2("Sorry: The third part of a discretionary break must be",
"empty, in math formulas. I had to delete your third part.");
flush_node_list(p);
error();
}else{
if(n> 0){
vlink(no_break(tail))= p;
alink(p)= no_break(tail);
tlink(no_break(tail))= q;
}
}
decr(save_ptr);
return;
break;
}
set_saved_record(-1,saved_disc,0,(saved_value(-1)+1));
new_save_level(disc_group);
scan_left_brace();
push_nest();
mode= -hmode;
space_factor_par= 1000;
}

/*:77*//*78:*/
#line 1909 "./luatexdir/tex/maincontrol.w"

void make_accent(void)
{
double s,t;
halfword p,q,r;
internal_font_number f;
scaled a,h,x,w,delta;
scan_char_num();
f= equiv(cur_font_loc);
p= new_glyph(f,cur_val);
if(p!=null){
x= x_height(f);
s= float_cast(slant(f))/float_constant(65536);
a= glyph_width(p);
do_assignments();


q= null;
f= equiv(cur_font_loc);
if((cur_cmd==letter_cmd)||
(cur_cmd==other_char_cmd)||(cur_cmd==char_given_cmd)){
q= new_glyph(f,cur_chr);
}else if(cur_cmd==char_num_cmd){
scan_char_num();
q= new_glyph(f,cur_val);
}else{
back_input();
}

if(q!=null){








t= float_cast(slant(f))/float_constant(65536);
w= glyph_width(q);
h= glyph_height(q);
if(h!=x){
p= hpack(p,0,additional,-1);
shift_amount(p)= x-h;
}
delta= round(float_cast(w-a)/float_constant(2)+h*t-x*s);
r= new_kern(delta);
subtype(r)= accent_kern;
couple_nodes(tail,r);
couple_nodes(r,p);
tail= new_kern(-a-delta);
subtype(tail)= accent_kern;
couple_nodes(p,tail);
p= q;

}
couple_nodes(tail,p);
tail= p;
space_factor_par= 1000;
}
}

/*:78*//*79:*/
#line 1979 "./luatexdir/tex/maincontrol.w"

void align_error(void)
{
if(abs(align_state)> 2){

print_err("Misplaced ");
print_cmd_chr((quarterword)cur_cmd,cur_chr);
if(cur_tok==tab_token+'&'){
help6("I can't figure out why you would want to use a tab mark",
"here. If you just want an ampersand, the remedy is",
"simple: Just type `I\\&' now. But if some right brace",
"up above has ended a previous alignment prematurely,",
"you're probably due for more error messages, and you",
"might try typing `S' now just to see what is salvageable.");
}else{
help5("I can't figure out why you would want to use a tab mark",
"or \\cr or \\span just now. If something like a right brace",
"up above has ended a previous alignment prematurely,",
"you're probably due for more error messages, and you",
"might try typing `S' now just to see what is salvageable.");
}
error();

}else{
back_input();
if(align_state<0){
print_err("Missing { inserted");
incr(align_state);
cur_tok= left_brace_token+'{';
}else{
print_err("Missing } inserted");
decr(align_state);
cur_tok= right_brace_token+'}';
}
help3("I've put in what seems to be necessary to fix",
"the current column of the current alignment.",
"Try to go on, since this might almost work.");
ins_error();
}
}

/*:79*//*80:*/
#line 2023 "./luatexdir/tex/maincontrol.w"

void no_align_error(void)
{
print_err("Misplaced \\noalign");
help2("I expect to see \\noalign only after the \\cr of",
"an alignment. Proceed, and I'll ignore this case.");
error();
}

void omit_error(void)
{
print_err("Misplaced \\omit");
help2("I expect to see \\omit only after tab marks or the \\cr of",
"an alignment. Proceed, and I'll ignore this case.");
error();
}

/*:80*//*81:*/
#line 2049 "./luatexdir/tex/maincontrol.w"

void do_endv(void)
{
base_ptr= input_ptr;
input_stack[base_ptr]= cur_input;
while((input_stack[base_ptr].index_field!=v_template)&&
(input_stack[base_ptr].loc_field==null)&&
(input_stack[base_ptr].state_field==token_list))
decr(base_ptr);
if((input_stack[base_ptr].index_field!=v_template)||
(input_stack[base_ptr].loc_field!=null)||
(input_stack[base_ptr].state_field!=token_list))
fatal_error("(interwoven alignment preambles are not allowed)");

if(cur_group==align_group){
end_graf(align_group);
if(fin_col())
fin_row();
}else{
off_save();
}
}

/*:81*//*82:*/
#line 2074 "./luatexdir/tex/maincontrol.w"

void cs_error(void)
{
print_err("Extra \\endcsname");
help1("I'm ignoring this, since I wasn't doing a \\csname.");
error();
}

/*:82*//*85:*/
#line 2104 "./luatexdir/tex/maincontrol.w"

#define check_def_code(A) do {      \
 if (((cur_val<0)&&(p<(A)))||(cur_val> n)) {   \
     print_err("Invalid code (");    \
     print_int(cur_val);      \
     if (p<(A))       \
  tprint("), should be in the range 0..");  \
     else       \
  tprint("), should be at most ");   \
     print_int(n);      \
     help1("I'm going to use 0 instead of that illegal code value."); \
     error();       \
     cur_val= 0;       \
 }        \
} while (0)

/*:85*//*86:*/
#line 2120 "./luatexdir/tex/maincontrol.w"




















void prefixed_command(void)
{
int a;
internal_font_number f;
halfword j;
halfword p,q;
int n;
boolean e,check_glue;
mathcodeval mval;
a= 0;
while(cur_cmd==prefix_cmd){
if(!odd(a/cur_chr))
a= a+cur_chr;

do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));

if(cur_cmd<=max_non_prefixed_command){

print_err("You can't use a prefix with `");
print_cmd_chr((quarterword)cur_cmd,cur_chr);
print_char('\'');
help2
("I'll pretend you didn't say \\long or \\outer or \\global or",
"\\protected.");
back_error();
return;
}
if(tracing_commands_par> 2)
show_cur_cmd_chr();
}

if(a>=8){
j= protected_token;
a= a-8;
}else{
j= 0;
}
if((cur_cmd!=def_cmd)&&((a%4!=0)||(j!=0))){
print_err("You can't use `\\long' or `\\outer' or `\\protected' with `");
print_cmd_chr((quarterword)cur_cmd,cur_chr);
print_char('\'');
help1("I'll pretend you didn't say \\long or \\outer or \\protected here.");
error();
}

if(global_defs_par!=0){
if(global_defs_par<0){
if(is_global(a))
a= a-4;
}else{
if(!is_global(a))
a= a+4;
}
}
switch(cur_cmd){
case set_font_cmd:


define(cur_font_loc,data_cmd,cur_chr);
break;
case def_cmd:




if(odd(cur_chr)&&!is_global(a)&&(global_defs_par>=0))
a= a+4;
e= (cur_chr>=2);
get_r_token();
p= cur_cs;
q= scan_toks(true,e);
if(j!=0){
q= get_avail();
set_token_info(q,j);
set_token_link(q,token_link(def_ref));
set_token_link(def_ref,q);
}
define(p,call_cmd+(a%4),def_ref);
break;
case let_cmd:
n= cur_chr;
if(n==normal){
get_r_token();
p= cur_cs;
do{
get_token();
}while(cur_cmd==spacer_cmd);
if(cur_tok==other_token+'='){
get_token();
if(cur_cmd==spacer_cmd)
get_token();
}
}else if(n==normal+1){

get_r_token();
p= cur_cs;
get_token();
q= cur_tok;
get_token();
back_input();
cur_tok= q;


back_input();
}else{

scan_int();
if(cur_val> 0){
cur_cs= active_to_cs(cur_val,true);
set_token_info(cur_cs,cur_cs+cs_token_flag);
p= cur_cs;
do{
get_token();
}while(cur_cmd==spacer_cmd);
if(cur_tok==other_token+'='){
get_token();
if(cur_cmd==spacer_cmd)
get_token();
}
}else{
p= null;
tex_error("invalid number for \\letcharcode",NULL);
}
}
if(cur_cmd>=call_cmd)
add_token_ref(cur_chr);
define(p,cur_cmd,cur_chr);
break;
case shorthand_def_cmd:





n= cur_chr;
get_r_token();
p= cur_cs;
define(p,relax_cmd,too_big_char);
scan_optional_equals();
switch(n){
case char_def_code:
scan_char_num();
define(p,char_given_cmd,cur_val);
break;
case math_char_def_code:
mval= scan_mathchar(tex_mathcode);
if(math_umathcode_meaning_par==1){
cur_val= (mval.class_value+(8*mval.family_value))*(65536*32)+mval.character_value;
define(p,xmath_given_cmd,cur_val);
}else{
cur_val= (mval.class_value*16+mval.family_value)*256+mval.character_value;
define(p,math_given_cmd,cur_val);
}
break;
case xmath_char_def_code:
mval= scan_mathchar(umath_mathcode);
cur_val= (mval.class_value+(8*mval.family_value))*(65536*32)+mval.character_value;
define(p,xmath_given_cmd,cur_val);
break;
case umath_char_def_code:
mval= scan_mathchar(umathnum_mathcode);
cur_val= (mval.class_value+(8*mval.family_value))*(65536*32)+mval.character_value;
define(p,xmath_given_cmd,cur_val);
break;
default:
scan_register_num();
switch(n){
case count_def_code:
define(p,assign_int_cmd,count_base+cur_val);
break;
case attribute_def_code:
define(p,assign_attr_cmd,attribute_base+cur_val);
break;
case dimen_def_code:
define(p,assign_dimen_cmd,scaled_base+cur_val);
break;
case skip_def_code:
define(p,assign_glue_cmd,skip_base+cur_val);
break;
case mu_skip_def_code:
define(p,assign_mu_glue_cmd,mu_skip_base+cur_val);
break;
case toks_def_code:
define(p,assign_toks_cmd,toks_base+cur_val);
break;
default:
confusion("shorthand_def");
break;
}
break;
}
break;
case read_to_cs_cmd:
j= cur_chr;
scan_int();
n= cur_val;
if(!scan_keyword("to")){
print_err("Missing `to' inserted");
help2("You should have said `\\read<number> to \\cs'.",
"I'm going to look for the \\cs now.");
error();
}
get_r_token();
p= cur_cs;
read_toks(n,p,j);
define(p,call_cmd,cur_val);
break;
case toks_register_cmd:
case assign_toks_cmd:



q= cur_cs;
if(cur_cmd==toks_register_cmd){
scan_register_num();
p= toks_base+cur_val;
}else{
p= cur_chr;
}
scan_optional_equals();

do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));

if(cur_cmd!=left_brace_cmd){


if(cur_cmd==toks_register_cmd){
scan_register_num();
cur_cmd= assign_toks_cmd;
cur_chr= toks_base+cur_val;
}
if(cur_cmd==assign_toks_cmd){
q= equiv(cur_chr);
if(q==null){
define(p,undefined_cs_cmd,null);
}else{
add_token_ref(q);
define(p,call_cmd,q);
}
goto DONE;
}
}
back_input();
cur_cs= q;
q= scan_toks(false,false);
if(token_link(def_ref)==null){
define(p,undefined_cs_cmd,null);
free_avail(def_ref);
}else{
if(p==output_routine_loc){
p= get_avail();
set_token_link(q,p);
p= output_routine_loc;
q= token_link(q);
set_token_info(q,right_brace_token+'}');
q= get_avail();
set_token_info(q,left_brace_token+'{');
set_token_link(q,token_link(def_ref));
set_token_link(def_ref,q);
}
define(p,call_cmd,def_ref);
}
break;
case assign_int_cmd:

p= cur_chr;
scan_optional_equals();
scan_int();
assign_internal_value(a,p,cur_val);
break;
case assign_attr_cmd:
p= cur_chr;
scan_optional_equals();
scan_int();
if((p-attribute_base)> max_used_attr)
max_used_attr= (p-attribute_base);
attr_list_cache= cache_disabled;
word_define(p,cur_val);
break;
case assign_dir_cmd:

scan_direction();
switch(cur_chr){
case int_base+page_direction_code:
eq_word_define(int_base+page_direction_code,cur_val);
break;
case int_base+body_direction_code:
eq_word_define(int_base+body_direction_code,cur_val);
break;
case int_base+par_direction_code:
eq_word_define(int_base+par_direction_code,cur_val);
break;
case int_base+math_direction_code:
eq_word_define(int_base+math_direction_code,cur_val);
break;
case int_base+text_direction_code:
case int_base+line_direction_code:

















check_glue= (cur_chr==(int_base+line_direction_code));
if(check_glue){
cur_chr= int_base+text_direction_code;
}
if(abs(mode)==hmode){
if(no_local_dirs_par> 0){

if(check_glue&&(tail!=null&&type(tail)==glue_node)){
halfword prev= alink(tail);
halfword dirn= new_dir(text_direction_par-dir_swap);
couple_nodes(prev,dirn);
couple_nodes(dirn,tail);
}else{
tail_append(new_dir(text_direction_par-dir_swap));
}
}else{

}
update_text_dir_ptr(cur_val);
tail_append(new_dir(cur_val));
dir_level(tail)= cur_level;
}else{
update_text_dir_ptr(cur_val);
}













eq_word_define(int_base+text_direction_code,cur_val);
eq_word_define(int_base+no_local_dirs_code,no_local_dirs_par+1);
break;
}
break;
case assign_dimen_cmd:
p= cur_chr;
scan_optional_equals();
scan_normal_dimen();
assign_internal_value(a,p,cur_val);
break;
case assign_glue_cmd:
case assign_mu_glue_cmd:
p= cur_chr;
n= cur_cmd;
scan_optional_equals();
if(n==assign_mu_glue_cmd)
scan_glue(mu_val_level);
else
scan_glue(glue_val_level);
define(p,glue_ref_cmd,cur_val);
break;
case def_char_code_cmd:
case def_del_code_cmd:

if(cur_chr==cat_code_base)
n= max_char_code;
else if(cur_chr==sf_code_base)
n= 077777;
else
n= biggest_char;

p= cur_chr;
if(cur_chr==math_code_base){
if(is_global(a))
cur_val1= level_one;
else
cur_val1= cur_level;
scan_extdef_math_code(cur_val1,tex_mathcode);
}else if(cur_chr==lc_code_base){
scan_char_num();
p= cur_val;
scan_optional_equals();
scan_int();
check_def_code(lc_code_base);
define_lc_code(p,cur_val);
}else if(cur_chr==uc_code_base){
scan_char_num();
p= cur_val;
scan_optional_equals();
scan_int();
check_def_code(uc_code_base);
define_uc_code(p,cur_val);
}else if(cur_chr==sf_code_base){
scan_char_num();
p= cur_val;
scan_optional_equals();
scan_int();
check_def_code(sf_code_base);
define_sf_code(p,cur_val);
}else if(cur_chr==cat_code_base){
scan_char_num();
p= cur_val;
scan_optional_equals();
scan_int();
check_def_code(cat_code_base);
define_cat_code(p,cur_val);
}else if(cur_chr==del_code_base){
if(is_global(a))
cur_val1= level_one;
else
cur_val1= cur_level;
scan_extdef_del_code(cur_val1,tex_mathcode);
}
break;
case extdef_math_code_cmd:
case extdef_del_code_cmd:
if(is_global(a))
cur_val1= level_one;
else
cur_val1= cur_level;
if(cur_chr==math_code_base)
scan_extdef_math_code(cur_val1,umath_mathcode);
else if(cur_chr==math_code_base+1)
scan_extdef_math_code(cur_val1,umathnum_mathcode);
else if(cur_chr==del_code_base)
scan_extdef_del_code(cur_val1,umath_mathcode);
else if(cur_chr==del_code_base+1)
scan_extdef_del_code(cur_val1,umathnum_mathcode);
break;
case def_family_cmd:
p= cur_chr;
scan_math_family_int();
cur_val1= cur_val;
scan_optional_equals();
scan_font_ident();
define_fam_fnt(cur_val1,p,cur_val);
break;
case set_math_param_cmd:
p= cur_chr;
get_token();
if(cur_cmd!=math_style_cmd){
print_err("Missing math style, treated as \\displaystyle");
help1
("A style should have been here; I inserted `\\displaystyle'.");
cur_val1= display_style;
back_error();
}else{
cur_val1= cur_chr;
}
scan_optional_equals();
if(p<math_param_first_mu_glue){
if(p==math_param_radical_degree_raise)
scan_int();
else
scan_dimen(false,false,false);
}else{
scan_glue(mu_val_level);
if(cur_val==thin_mu_skip_par)
cur_val= thin_mu_skip_code;
else if(cur_val==med_mu_skip_par)
cur_val= med_mu_skip_code;
else if(cur_val==thick_mu_skip_par)
cur_val= thick_mu_skip_code;
}
define_math_param(p,cur_val1,cur_val);
break;
case register_cmd:
case advance_cmd:
case multiply_cmd:
case divide_cmd:
do_register_command(a);
break;
case set_box_cmd:



scan_register_num();
if(is_global(a))
n= global_box_flag+cur_val;
else
n= box_flag+cur_val;
scan_optional_equals();
if(set_box_allowed){
scan_box(n);
}else{
print_err("Improper \\setbox");
help2("Sorry, \\setbox is not allowed after \\halign in a display,",
"or between \\accent and an accented character.");
error();
}
break;
case set_aux_cmd:




alter_aux();
break;
case set_prev_graf_cmd:
alter_prev_graf();
break;
case set_page_dimen_cmd:
alter_page_so_far();
break;
case set_page_int_cmd:
alter_integer();
break;
case set_box_dimen_cmd:


alter_box_dimen();
break;
case set_tex_shape_cmd:
q= cur_chr;
scan_optional_equals();
scan_int();
n= cur_val;
if(n<=0){
p= null;
}else{
p= new_node(shape_node,2*(n+1)+1);
vinfo(p+1)= n;
for(j= 1;j<=n;j++){
scan_normal_dimen();
varmem[p+2*j].cint= cur_val;
scan_normal_dimen();
varmem[p+2*j+1].cint= cur_val;
}
}
define(q,shape_ref_cmd,p);
break;
case set_etex_shape_cmd:
q= cur_chr;
scan_optional_equals();
scan_int();
n= cur_val;
if(n<=0){
p= null;
}else{
n= (cur_val/2)+1;
p= new_node(shape_node,2*n+1+1);
vinfo(p+1)= n;
n= cur_val;
varmem[p+2].cint= n;
for(j= p+3;j<=p+n+2;j++){
scan_int();
varmem[j].cint= cur_val;
}
if(!odd(n))
varmem[p+n+3].cint= 0;
}
define(q,shape_ref_cmd,p);
break;
case hyph_data_cmd:



switch(cur_chr){
case 0:
new_hyph_exceptions();
break;
case 1:
new_patterns();
break;
case 2:
new_pre_hyphen_char();
break;
case 3:
new_post_hyphen_char();
break;
case 4:
new_pre_exhyphen_char();
break;
case 5:
new_post_exhyphen_char();
break;
case 6:
new_hyphenation_min();
break;
case 7:
new_hj_code();
break;
}
break;
case assign_font_dimen_cmd:
set_font_dimen();
break;
case assign_font_int_cmd:
n= cur_chr;
scan_font_ident();
f= cur_val;
if(n==no_lig_code){
set_no_ligatures(f);
}else if(n<lp_code_base){
scan_optional_equals();
scan_int();
if(n==0)
set_hyphen_char(f,cur_val);
else
set_skew_char(f,cur_val);
}else{
scan_char_num();
p= cur_val;
scan_optional_equals();
scan_int();
switch(n){
case lp_code_base:
set_lp_code(f,p,cur_val);
break;
case rp_code_base:
set_rp_code(f,p,cur_val);
break;
case ef_code_base:
set_ef_code(f,p,cur_val);
break;
case tag_code:
set_tag_code(f,p,cur_val);
break;
}
}
break;
case def_font_cmd:

tex_def_font((small_number)a);
break;
case letterspace_font_cmd:
new_letterspaced_font((small_number)a);
break;
case copy_font_cmd:
make_font_copy((small_number)a);
break;
case set_font_id_cmd:
scan_int();
if(is_valid_font(cur_val))
zset_cur_font(cur_val);
break;
case set_interaction_cmd:
new_interaction();
break;
default:
confusion("prefix");
break;
}
DONE:

if(after_token!=0){
cur_tok= after_token;
back_input();
after_token= 0;
}
}

/*:86*//*87:*/
#line 2808 "./luatexdir/tex/maincontrol.w"

void fixup_directions(void)
{
int temp_no_whatsits= no_local_whatsits_par;
int temp_no_dirs= no_local_dirs_par;
int temporary_dir= text_direction_par;
if(dir_level(text_dir_ptr)==cur_level){

halfword text_dir_tmp= vlink(text_dir_ptr);
flush_node(text_dir_ptr);
text_dir_ptr= text_dir_tmp;
}
unsave();
if(abs(mode)==hmode){
if(temp_no_dirs!=0){

tail_append(new_dir(text_direction_par));
dir_dir(tail)= temporary_dir-dir_swap;
}
if(temp_no_whatsits!=0){

tail_append(make_local_par_node(hmode_par_par_code));
}
}
}

/*:87*//*88:*/
#line 2838 "./luatexdir/tex/maincontrol.w"

void get_r_token(void)
{
RESTART:
do{
get_token();
}while(cur_tok==space_token);
if((cur_cs==0)||(cur_cs> eqtb_top)||
((cur_cs> frozen_control_sequence)&&(cur_cs<=eqtb_size))){
print_err("Missing control sequence inserted");
help5("Please don't say `\\def cs{...}', say `\\def\\cs{...}'.",
"I've inserted an inaccessible control sequence so that your",
"definition will be completed without mixing me up too badly.",
"You can recover graciously from this error, if you're",
"careful; see exercise 27.2 in The TeXbook.");
if(cur_cs==0)
back_input();
cur_tok= cs_token_flag+frozen_protection;
ins_error();
goto RESTART;
}
}

/*:88*//*89:*/
#line 2861 "./luatexdir/tex/maincontrol.w"

void assign_internal_value(int a,halfword p,int val)
{
halfword n;
if((p>=int_base)&&(p<attribute_base)){
switch((p-int_base)){
case cat_code_table_code:
if(valid_catcode_table(val)){
if(val!=cat_code_table_par)
word_define(p,val);
}else{
print_err("Invalid \\catcode table");
help2
("You can only switch to a \\catcode table that is initialized",
"using \\savecatcodetable or \\initcatcodetable, or to table 0");
error();
}
break;
case output_box_code:
if((val> 65535)|(val<0)){
print_err("Invalid \\outputbox");
help1
("The value for \\outputbox has to be between 0 and 65535.");
error();
}else{
word_define(p,val);
}
break;
case new_line_char_code:
if(val> 127){
print_err("Invalid \\newlinechar");
help2
("The value for \\newlinechar has to be no higher than 127.",
"Your invalid assignment will be ignored.");
error();
}else{
word_define(p,val);
}
break;
case end_line_char_code:
if(val> 127){
print_err("Invalid \\endlinechar");
help2
("The value for \\endlinechar has to be no higher than 127.",
"Your invalid assignment will be ignored.");
error();
}else{
word_define(p,val);
}
break;
case language_code:
if(val<0){
word_define(int_base+cur_lang_code,-1);
word_define(p,-1);
}else if(val> 16383){
print_err("Invalid \\language");
help2
("The absolute value for \\language has to be no higher than 16383.",
"Your invalid assignment will be ignored.");
error();
}else{
word_define(int_base+cur_lang_code,val);
word_define(p,val);
}
break;
default:
word_define(p,val);
break;
}





if((abs(mode)==hmode)&&
((p==(int_base+local_inter_line_penalty_code))||
(p==(int_base+local_broken_penalty_code)))){

tail_append(make_local_par_node(penalty_par_code));
eq_word_define(int_base+no_local_whatsits_code,no_local_whatsits_par+1);
}
}else if((p>=dimen_base)&&(p<=eqtb_size)){
if(p==(dimen_base+page_left_offset_code)){
n= val-one_true_inch;
word_define(dimen_base+h_offset_code,n);
}else if(p==(dimen_base+h_offset_code)){
n= val+one_true_inch;
word_define(dimen_base+page_left_offset_code,n);
}else if(p==(dimen_base+page_top_offset_code)){
n= val-one_true_inch;
word_define(dimen_base+v_offset_code,n);
}else if(p==(dimen_base+v_offset_code)){
n= val+one_true_inch;
word_define(dimen_base+page_top_offset_code,n);
}
word_define(p,val);
}else if((p>=local_base)&&(p<toks_base)){
define(p,call_cmd,val);
}else{
confusion("assign internal value");
}
}

/*:89*//*90:*/
#line 2970 "./luatexdir/tex/maincontrol.w"

void do_register_command(int a)
{
int p;
halfword q= cur_cmd;
halfword l= 0;
if(q!=register_cmd){
get_x_token();
if((cur_cmd>=assign_int_cmd)&&(cur_cmd<=assign_mu_glue_cmd)){
l= cur_chr;
p= cur_cmd-assign_int_cmd;
goto FOUND;
}
if(cur_cmd!=register_cmd){
print_err("You can't use `");
print_cmd_chr((quarterword)cur_cmd,cur_chr);
tprint("' after ");
print_cmd_chr((quarterword)q,0);
help1("I'm forgetting what you said and not changing anything.");
error();
return;
}
}
p= cur_chr;
scan_register_num();
if(p==int_val_level)
l= cur_val+count_base;
else if(p==attr_val_level)
l= cur_val+attribute_base;
else if(p==dimen_val_level)
l= cur_val+scaled_base;
else if(p==glue_val_level)
l= cur_val+skip_base;
else if(p==mu_val_level)
l= cur_val+mu_skip_base;
FOUND:
if(q==register_cmd){
scan_optional_equals();
}else if(scan_keyword("by")){

}
arith_error= false;
if(q<multiply_cmd){

if(p<glue_val_level){
if((p==int_val_level)||(p==attr_val_level))
scan_int();
else
scan_normal_dimen();
if(q==advance_cmd)
cur_val= cur_val+eqtb[l].cint;
}else{

scan_glue(p);
if(q==advance_cmd){

halfword r= equiv(l);
q= new_spec(cur_val);
flush_node(cur_val);
width(q)= width(q)+width(r);
if(stretch(q)==0){
stretch_order(q)= normal;
}
if(stretch_order(q)==stretch_order(r)){
stretch(q)= stretch(q)+stretch(r);
}else if((stretch_order(q)<stretch_order(r))&&(stretch(r)!=0)){
stretch(q)= stretch(r);
stretch_order(q)= stretch_order(r);
}
if(shrink(q)==0){
shrink_order(q)= normal;
}
if(shrink_order(q)==shrink_order(r)){
shrink(q)= shrink(q)+shrink(r);
}else if((shrink_order(q)<shrink_order(r))&&(shrink(r)!=0)){
shrink(q)= shrink(r);
shrink_order(q)= shrink_order(r);
}
cur_val= q;
}
}
}else{

scan_int();
if(p<glue_val_level){
if(q==multiply_cmd){
if((p==int_val_level)||(p==attr_val_level)){
cur_val= mult_integers(eqtb[l].cint,cur_val);
}else{
cur_val= nx_plus_y(eqtb[l].cint,cur_val,0);
}
}else{
cur_val= x_over_n(eqtb[l].cint,cur_val);
}
}else{
halfword s= equiv(l);
halfword r= new_spec(s);
if(q==multiply_cmd){
width(r)= nx_plus_y(width(s),cur_val,0);
stretch(r)= nx_plus_y(stretch(s),cur_val,0);
shrink(r)= nx_plus_y(shrink(s),cur_val,0);
}else{
width(r)= x_over_n(width(s),cur_val);
stretch(r)= x_over_n(stretch(s),cur_val);
shrink(r)= x_over_n(shrink(s),cur_val);
}
cur_val= r;
}
}
if(arith_error){
print_err("Arithmetic overflow");
help2("I can't carry out that multiplication or division,",
"since the result is out of range.");
if(p>=glue_val_level)
flush_node(cur_val);
error();
return;
}
if(p<glue_val_level){
if(p==attr_val_level){
if((l-attribute_base)> max_used_attr)
max_used_attr= (l-attribute_base);
attr_list_cache= cache_disabled;
}
if((p==int_val_level)||(p==dimen_val_level))
assign_internal_value(a,l,cur_val);
else
word_define(l,cur_val);
}else{
define(l,glue_ref_cmd,cur_val);
}
}

/*:90*//*91:*/
#line 3103 "./luatexdir/tex/maincontrol.w"

void alter_aux(void)
{
halfword c;
if(cur_chr!=abs(mode)){
report_illegal_case();
}else{
c= cur_chr;
scan_optional_equals();
if(c==vmode){
scan_normal_dimen();
prev_depth_par= cur_val;
}else{
scan_int();
if((cur_val<=0)||(cur_val> 32767)){
print_err("Bad space factor");
help1("I allow only values in the range 1..32767 here.");
int_error(cur_val);
}else{
space_factor_par= cur_val;
}
}
}
}

/*:91*//*92:*/
#line 3128 "./luatexdir/tex/maincontrol.w"

void alter_prev_graf(void)
{
int p;
p= nest_ptr;
while(abs(nest[p].mode_field)!=vmode)
decr(p);
scan_optional_equals();
scan_int();
if(cur_val<0){
print_err("Bad \\prevgraf");
help1("I allow only nonnegative values here.");
int_error(cur_val);
}else{
nest[p].pg_field= cur_val;
}
}

/*:92*//*93:*/
#line 3146 "./luatexdir/tex/maincontrol.w"

void alter_page_so_far(void)
{
int c;
c= cur_chr;
scan_optional_equals();
scan_normal_dimen();
page_so_far[c]= cur_val;
}

/*:93*//*94:*/
#line 3156 "./luatexdir/tex/maincontrol.w"

void alter_integer(void)
{
int c;
c= cur_chr;
scan_optional_equals();
scan_int();
if(c==0){
dead_cycles= cur_val;
}else if(c==2){
if((cur_val<batch_mode)||(cur_val> error_stop_mode)){
print_err("Bad interaction mode");
help2("Modes are 0=batch, 1=nonstop, 2=scroll, and",
"3=errorstop. Proceed, and I'll ignore this case.");
int_error(cur_val);
}else{
cur_chr= cur_val;
new_interaction();
}
}else{
insert_penalties= cur_val;
}
}

/*:94*//*95:*/
#line 3180 "./luatexdir/tex/maincontrol.w"

void alter_box_dimen(void)
{
int c;
int b;
c= cur_chr;
scan_register_num();
b= cur_val;
scan_optional_equals();
scan_normal_dimen();
if(box(b)!=null)
varmem[box(b)+c].cint= cur_val;
}

/*:95*//*96:*/
#line 3194 "./luatexdir/tex/maincontrol.w"

void new_interaction(void)
{
print_ln();
interaction= cur_chr;
if(interaction==batch_mode)
kpse_make_tex_discard_errors= 1;
else
kpse_make_tex_discard_errors= 0;
fixup_selector(log_opened_global);
}

/*:96*//*97:*/
#line 3210 "./luatexdir/tex/maincontrol.w"

halfword after_token;

/*:97*//*98:*/
#line 3216 "./luatexdir/tex/maincontrol.w"

void do_assignments(void)
{
while(true){

do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));
if(cur_cmd<=max_non_prefixed_command)
return;
set_box_allowed= false;
prefixed_command();
set_box_allowed= true;
}
}

/*:98*//*99:*/
#line 3232 "./luatexdir/tex/maincontrol.w"

void open_or_close_in(void)
{
int c;
int n;
char*fn;
c= cur_chr;
scan_four_bit_int();
n= cur_val;
if(read_open[n]!=closed){
lua_a_close_in(read_file[n],(n+1));
read_open[n]= closed;
}
if(c!=0){
scan_optional_equals();
do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));
back_input();
if(cur_cmd!=left_brace_cmd){
scan_file_name();
if(cur_ext==get_nullstr())
cur_ext= maketexstring(".tex");
}else{
scan_file_name_toks();
}
fn= pack_file_name(cur_name,cur_area,cur_ext);
if(lua_a_open_in(&(read_file[n]),fn,(n+1))){
read_open[n]= just_open;
}
}
}

/*:99*//*100:*/
#line 3265 "./luatexdir/tex/maincontrol.w"

boolean long_help_seen;

void issue_message(void)
{
int old_setting;
int c;
str_number s;
c= cur_chr;
(void)scan_toks(false,true);
old_setting= selector;
selector= new_string;
token_show(def_ref);
selector= old_setting;
flush_list(def_ref);
str_room(1);
s= make_string();
if(c==0){

if(term_offset+(int)str_length(s)> max_print_line-2)
print_ln();
else if((term_offset> 0)||(file_offset> 0))
print_char(' ');
print(s);
update_terminal();

}else{




print_err("");
print(s);
if(err_help_par!=null){
use_err_help= true;
}else if(long_help_seen){
help1("(That was another \\errmessage.)");
}else{
if(interaction<error_stop_mode)
long_help_seen= true;
help4("This error message was generated by an \\errmessage",
"command, so I can't give any explicit help.",
"Pretend that you're Hercule Poirot: Examine all clues,",
"and deduce the truth by order and method.");
}
error();
use_err_help= false;

}
flush_str(s);
}

/*:100*//*101:*/
#line 3320 "./luatexdir/tex/maincontrol.w"

void give_err_help(void)
{
token_show(err_help_par);
}

/*:101*//*102:*/
#line 3329 "./luatexdir/tex/maincontrol.w"

void shift_case(void)
{
halfword b;
halfword p;
halfword t;
halfword c;
halfword i;
b= cur_chr;
p= scan_toks(false,false);
p= token_link(def_ref);
while(p!=null){





t= token_info(p);
if(t<cs_token_flag){
c= t%STRING_OFFSET;
if(b==uc_code_base)
i= get_uc_code(c);
else
i= get_lc_code(c);
if(i!=0)
set_token_info(p,t-c+i);
}else if(is_active_cs(cs_text(t-cs_token_flag))){
c= active_cs_value(cs_text(t-cs_token_flag));
if(b==uc_code_base)
i= get_uc_code(c);
else
i= get_lc_code(c);
if(i!=0)
set_token_info(p,active_to_cs(i,true)+cs_token_flag);
}
p= token_link(p);
}
back_list(token_link(def_ref));
free_avail(def_ref);
}

/*:102*//*103:*/
#line 3373 "./luatexdir/tex/maincontrol.w"

void show_whatever(void)
{
halfword p;
int t;
int m;
int l;
int n;
switch(cur_chr){
case show_lists:
begin_diagnostic();
show_activities();
break;
case show_box_code:

scan_register_num();
begin_diagnostic();
tprint_nl("> \\box");
print_int(cur_val);
print_char('=');
if(box(cur_val)==null)
tprint("void");
else
show_box(box(cur_val));
break;
case show_code:

get_token();
if(interaction==error_stop_mode)
wake_up_terminal();
tprint_nl("> ");
if(cur_cs!=0){
sprint_cs(cur_cs);
print_char('=');
}
print_meaning();
goto COMMON_ENDING;
break;

case show_groups:
begin_diagnostic();
show_save_groups();
break;
case show_ifs:
begin_diagnostic();
tprint_nl("");
print_ln();
if(cond_ptr==null){
tprint_nl("### ");
tprint("no active conditionals");
}else{
p= cond_ptr;
n= 0;
do{
incr(n);
p= vlink(p);
}while(p!=null);
p= cond_ptr;
t= cur_if;
l= if_line;
m= if_limit;
do{
tprint_nl("### level ");
print_int(n);
tprint(": ");
print_cmd_chr(if_test_cmd,t);
if(m==fi_code)
tprint_esc("else");
print_if_line(l);
decr(n);
t= if_limit_subtype(p);
l= if_line_field(p);
m= if_limit_type(p);
p= vlink(p);
}while(p!=null);
}
break;
default:


p= the_toks();
if(interaction==error_stop_mode)
wake_up_terminal();
tprint_nl("> ");
token_show(temp_token_head);
flush_list(token_link(temp_token_head));
goto COMMON_ENDING;
break;
}

end_diagnostic(true);
print_err("OK");
if(selector==term_and_log){
if(tracing_online_par<=0){
selector= term_only;
tprint(" (see the transcript file)");
selector= term_and_log;
}
}
COMMON_ENDING:
if(interaction<error_stop_mode){
help0();
decr(error_count);
}else if(tracing_online_par> 0){
help3("This isn't an error message; I'm just \\showing something.",
"Type `I\\show...' to show more (e.g., \\show\\cs,",
"\\showthe\\count10, \\showbox255, \\showlists).");
}else{
help5("This isn't an error message; I'm just \\showing something.",
"Type `I\\show...' to show more (e.g., \\show\\cs,",
"\\showthe\\count10, \\showbox255, \\showlists).",
"And type `I\\tracingonline=1\\show...' to show boxes and",
"lists on your terminal as well as in the transcript file.");
}
error();
}

/*:103*//*104:*/
#line 3490 "./luatexdir/tex/maincontrol.w"

void initialize(void)
{
int k;


initialize_errors();
initialize_arithmetic();
max_used_attr= -1;
attr_list_cache= cache_disabled;
initialize_nesting();


page_contents= empty;
page_tail= page_head;
#if 0
vlink(page_head)= null;
#endif
last_glue= max_halfword;
last_penalty= 0;
last_kern= 0;
last_node_type= -1;
page_depth= 0;
page_max_depth= 0;

initialize_equivalents();
no_new_control_sequence= true;
init_primitives();

mag_set= 0;
initialize_marks();
initialize_read();

static_pdf= init_pdf_struct(static_pdf);

format_ident= 0;
format_name= get_nullstr();
initialize_directions();
initialize_write_files();
seconds_and_micros(epochseconds,microseconds);
initialize_start_time(static_pdf);

edit_name_start= 0;
stop_at_space= true;

if(ini_version){


init_node_mem(500);
initialize_tokens();

initialize_alignments();
initialize_buildpage();

initialize_active();

set_eq_type(undefined_control_sequence,undefined_cs_cmd);
set_equiv(undefined_control_sequence,null);
set_eq_level(undefined_control_sequence,level_zero);
for(k= null_cs;k<=(eqtb_top-1);k++)
eqtb[k]= eqtb[undefined_control_sequence];
set_equiv(glue_base,zero_glue);
set_eq_level(glue_base,level_one);
set_eq_type(glue_base,glue_ref_cmd);
for(k= glue_base+1;k<=local_base-1;k++){
eqtb[k]= eqtb[glue_base];
}
par_shape_par_ptr= null;
set_eq_type(par_shape_loc,shape_ref_cmd);
set_eq_level(par_shape_loc,level_one);
for(k= etex_pen_base;k<=(etex_pens-1);k++)
eqtb[k]= eqtb[par_shape_loc];
for(k= output_routine_loc;k<=toks_base+biggest_reg;k++)
eqtb[k]= eqtb[undefined_control_sequence];
box(0)= null;
set_eq_type(box_base,box_ref_cmd);
set_eq_level(box_base,level_one);
for(k= box_base+1;k<=(box_base+biggest_reg);k++)
eqtb[k]= eqtb[box_base];
cur_font_par= null_font;
set_eq_type(cur_font_loc,data_cmd);
set_eq_level(cur_font_loc,level_one);
set_equiv(cat_code_base,0);
set_eq_type(cat_code_base,data_cmd);
set_eq_level(cat_code_base,level_one);
eqtb[internal_math_param_base]= eqtb[cat_code_base];
eqtb[lc_code_base]= eqtb[cat_code_base];
eqtb[uc_code_base]= eqtb[cat_code_base];
eqtb[sf_code_base]= eqtb[cat_code_base];
eqtb[math_code_base]= eqtb[cat_code_base];
cat_code_table_par= 0;
initialize_math_codes();
initialize_text_codes();
initex_cat_codes(0);
for(k= '0';k<='9';k++)
set_math_code(k,math_use_current_family_code,0,k,level_one);
for(k= 'A';k<='Z';k++){
set_math_code(k,math_use_current_family_code,1,k,level_one);
set_math_code((k+32),math_use_current_family_code,1,(k+32),level_one);
set_lc_code(k,k+32,level_one);
set_lc_code(k+32,k+32,level_one);
set_uc_code(k,k,level_one);
set_uc_code(k+32,k,level_one);
set_sf_code(k,999,level_one);
}
for(k= int_base;k<=attribute_base-1;k++)
eqtb[k].cint= 0;
for(k= attribute_base;k<=del_code_base-1;k++)
eqtb[k].cint= UNUSED_ATTRIBUTE;
mag_par= 1000;
tolerance_par= 10000;
hang_after_par= 1;
max_dead_cycles_par= 25;
escape_char_par= '\\';
end_line_char_par= carriage_return;
set_del_code('.',0,0,0,0,level_one);
ex_hyphen_char_par= '-';
output_box_par= 255;
for(k= dimen_base;k<=eqtb_size;k++)
eqtb[k].cint= 0;
page_left_offset_par= one_inch;
page_top_offset_par= one_inch;
page_right_offset_par= one_inch;
page_bottom_offset_par= one_inch;
ini_init_primitives();
hash_used= frozen_control_sequence;
hash_high= 0;
cs_count= 0;
set_eq_type(frozen_dont_expand,dont_expand_cmd);
cs_text(frozen_dont_expand)= maketexstring("notexpanded:");
set_eq_type(frozen_primitive,ignore_spaces_cmd);
set_equiv(frozen_primitive,1);
set_eq_level(frozen_primitive,level_one);
cs_text(frozen_primitive)= maketexstring("primitive");
create_null_font();
font_bytes= 0;
px_dimen_par= one_bp;
math_eqno_gap_step_par= 1000;
cs_text(frozen_protection)= maketexstring("inaccessible");
format_ident= maketexstring(" (INITEX)");
cs_text(end_write)= maketexstring("endwrite");
set_eq_level(end_write,level_one);
set_eq_type(end_write,outer_call_cmd);
set_equiv(end_write,null);

}
synctexoffset= int_base+synctex_code;

}/*:104*/
