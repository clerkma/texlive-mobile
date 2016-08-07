/*1:*/
#line 20 "./luatexdir/tex/equivalents.w"


#include "ptexlib.h"

halfword last_cs_name= null_cs;



static void diagnostic_trace(halfword p,const char*s)
{
begin_diagnostic();
print_char('{');
tprint(s);
print_char(' ');
show_eqtb(p);
print_char('}');
end_diagnostic(false);
}

/*:1*//*2:*/
#line 39 "./luatexdir/tex/equivalents.w"

#define par_shape_ptr equiv(par_shape_loc)

void show_eqtb_meaning(halfword n);

/*:2*//*4:*/
#line 89 "./luatexdir/tex/equivalents.w"

memory_word*eqtb;
halfword eqtb_top;
quarterword xeq_level[(eqtb_size+1)];

/*:4*//*5:*/
#line 94 "./luatexdir/tex/equivalents.w"

void initialize_equivalents(void)
{
int k;
for(k= int_base;k<=eqtb_size;k++)
xeq_level[k]= level_one;
}

/*:5*//*7:*/
#line 165 "./luatexdir/tex/equivalents.w"

save_record*save_stack;
int save_ptr;
int max_save_stack;
quarterword cur_level= level_one;
group_code cur_group= bottom_level;
int cur_boundary;

/*:7*//*9:*/
#line 184 "./luatexdir/tex/equivalents.w"

#define check_full_save_stack() do { \
    if (save_ptr> max_save_stack) { \
        max_save_stack= save_ptr; \
        if (max_save_stack> save_size-8) \
            overflow("save size",(unsigned)save_size); \
    } \
} while (0)

/*:9*//*10:*/
#line 205 "./luatexdir/tex/equivalents.w"

void new_save_level(group_code c)
{
check_full_save_stack();
set_saved_record(0,saved_line,0,line);
incr(save_ptr);
save_type(save_ptr)= level_boundary;
save_level(save_ptr)= cur_group;
save_value(save_ptr)= cur_boundary;
if(cur_level==max_quarterword)
overflow("grouping levels",max_quarterword-min_quarterword);

cur_boundary= save_ptr;
cur_group= c;
if(int_par(tracing_groups_code)> 0)
group_trace(false);
incr(cur_level);
incr(save_ptr);
}

/*:10*//*11:*/
#line 225 "./luatexdir/tex/equivalents.w"

static const char*save_stack_type(int v)
{
const char*s= "";
switch(save_type(v)){
case restore_old_value:s= "restore_old_value";break;
case restore_zero:s= "restore_zero";break;
case insert_token:s= "insert_token";break;
case level_boundary:s= "level_boundary";break;
case saved_line:s= "saved_line";break;
case saved_adjust:s= "saved_adjust";break;
case saved_insert:s= "saved_insert";break;
case saved_disc:s= "saved_disc";break;
case saved_boxtype:s= "saved_boxtype";break;
case saved_textdir:s= "saved_textdir";break;
case saved_eqno:s= "saved_eqno";break;
case saved_choices:s= "saved_choices";break;
case saved_math:s= "saved_math";break;
case saved_boxcontext:s= "saved_boxcontext";break;
case saved_boxspec:s= "saved_boxspec";break;
case saved_boxdir:s= "saved_boxdir";break;
case saved_boxattr:s= "saved_boxattr";break;
case saved_boxpack:s= "saved_boxpack";break;
case saved_eqtb:s= "saved_eqtb";break;
default:break;
}
return s;
}

/*:11*//*12:*/
#line 254 "./luatexdir/tex/equivalents.w"

void print_save_stack(void)
{
int i;
begin_diagnostic();
selector= term_and_log;
print_ln();
for(i= (save_ptr-1);i>=0;i--){
tprint("save_stack[");
if(i<100)
print_char(' ');
if(i<10)
print_char(' ');
print_int(i);
tprint("]: ");
tprint(save_stack_type(i));
switch(save_type(i)){
case restore_old_value:
tprint(", ");
show_eqtb_meaning(save_value(i));
tprint("=");
if(save_value(i)>=int_base){
print_int(save_word(i-1).cint);
}else{
print_int(eq_type_field(save_word(i-1)));
print_char(',');
print_int(equiv_field(save_word(i-1)));
}
i--;
break;
case restore_zero:
tprint(", ");
show_eqtb_meaning(save_value(i));
break;
case insert_token:
tprint(", ");
{
halfword p= get_avail();
set_token_info(p,save_value(i));
show_token_list(p,null,1);
free_avail(p);
}
break;
case level_boundary:
tprint(", old group=");
print_int(save_level(i));
tprint(", boundary = ");
print_int(save_value(i));
tprint(", line = ");
print_int(save_value(i-1));
i--;
break;
case saved_adjust:
tprint(", ");
print_int(save_level(i));
break;
case saved_insert:
tprint(", ");
print_int(save_value(i));
break;
case saved_boxtype:
tprint(", ");
print_int(save_value(i));
break;
case saved_eqno:
tprint(", ");
print_int(save_value(i));
break;
case saved_disc:
case saved_choices:
tprint(", ");
print_int(save_value(i));
break;
case saved_math:
tprint(", listptr=");
print_int(save_value(i));
break;
case saved_boxcontext:
tprint(", ");
print_int(save_value(i));
break;
case saved_boxspec:
tprint(", spec=");
print_int(save_level(i));
tprint(", dimen=");
print_int(save_value(i));
break;
case saved_textdir:
case saved_boxdir:
tprint(", ");
print_dir(dir_dir(save_value(i)));
break;
case saved_boxattr:
case saved_boxpack:
tprint(", ");
print_int(save_value(i));
break;
case saved_line:
case saved_eqtb:
break;
default:
break;
}
print_ln();
}
end_diagnostic(true);
}

/*:12*//*14:*/
#line 374 "./luatexdir/tex/equivalents.w"

void show_save_groups(void)
{
int p= nest_ptr;
int m;
save_pointer v= save_ptr;
quarterword l= cur_level;
group_code c= cur_group;
int a= 1;
int i;
quarterword j;
const char*s= NULL;
save_ptr= cur_boundary;
decr(cur_level);
tprint_nl("");
print_ln();
while(1){
tprint_nl("### ");
print_group(true);
if(cur_group==bottom_level)
goto DONE;
do{
m= nest[p].mode_field;
if(p> 0)
decr(p);
else
m= vmode;
}while(m==hmode);
tprint(" (");
switch(cur_group){
case simple_group:
incr(p);
goto FOUND2;
break;
case hbox_group:
case adjusted_hbox_group:
s= "hbox";
break;
case vbox_group:
s= "vbox";
break;
case vtop_group:
s= "vtop";
break;
case align_group:
if(a==0){
if(m==-vmode)
s= "halign";
else
s= "valign";
a= 1;
goto FOUND1;
}else{
if(a==1)
tprint("align entry");
else
tprint_esc("cr");
if(p>=a)
p= p-a;
a= 0;
goto FOUND;
}
break;
case no_align_group:
incr(p);
a= -1;
tprint_esc("noalign");
goto FOUND2;
break;
case output_group:
tprint_esc("output");
goto FOUND;
break;
case math_group:
goto FOUND2;
break;
case disc_group:
tprint_esc("discretionary");
for(i= 1;i<3;i++)
if(i<=saved_value(-2))
tprint("{}");
goto FOUND2;
break;
case math_choice_group:
tprint_esc("mathchoice");
for(i= 1;i<4;i++)
if(i<=saved_value(-3))
tprint("{}");
goto FOUND2;
break;
case insert_group:
if(saved_type(-1)==saved_adjust){
tprint_esc("vadjust");
if(saved_level(-1)!=0)
tprint(" pre");
}else{
tprint_esc("insert");
print_int(saved_value(-1));
}
goto FOUND2;
break;
case vcenter_group:
s= "vcenter";
goto FOUND1;
break;
case semi_simple_group:
incr(p);
tprint_esc("begingroup");
goto FOUND;
break;
case math_shift_group:
if(m==mmode){
print_char('$');
}else if(nest[p].mode_field==mmode){
print_cmd_chr(eq_no_cmd,saved_value(-2));
goto FOUND;
}
print_char('$');
goto FOUND;
break;
case math_left_group:
if(subtype(nest[p+1].eTeX_aux_field)==left_noad_side)
tprint_esc("left");
else
tprint_esc("middle");
goto FOUND;
break;
default:
confusion("showgroups");
break;
}

i= saved_value(-5);
if(i!=0){
if(i<box_flag){
if(abs(nest[p].mode_field)==vmode)
j= hmove_cmd;
else
j= vmove_cmd;
if(i> 0)
print_cmd_chr(j,0);
else
print_cmd_chr(j,1);
print_scaled(abs(i));
tprint("pt");
}else if(i<ship_out_flag){
if(i>=global_box_flag){
tprint_esc("global");
i= i-(global_box_flag-box_flag);
}
tprint_esc("setbox");
print_int(i-box_flag);
print_char('=');
}else{
print_cmd_chr(leader_ship_cmd,i-(leader_flag-a_leaders));
}
}
FOUND1:
tprint_esc(s);

{

int ii= -1;
while(saved_type(ii)!=saved_boxspec)
ii--;
if(saved_value(ii)!=0){
print_char(' ');
if(saved_level(ii)==exactly)
tprint("to");
else
tprint("spread");
print_scaled(saved_value(ii));
tprint("pt");
}
}
FOUND2:
print_char('{');
FOUND:
print_char(')');
decr(cur_level);
cur_group= save_level(save_ptr);
save_ptr= save_value(save_ptr);
}
DONE:
save_ptr= v;
cur_level= l;
cur_group= c;
}

/*:14*//*15:*/
#line 569 "./luatexdir/tex/equivalents.w"

void eq_destroy(memory_word w)
{
halfword q;
switch(eq_type_field(w)){
case call_cmd:
case long_call_cmd:
case outer_call_cmd:
case long_outer_call_cmd:
delete_token_ref(equiv_field(w));
break;
case glue_ref_cmd:
delete_glue_ref(equiv_field(w));
break;
case shape_ref_cmd:
q= equiv_field(w);
if(q!=null)
flush_node(q);
break;
case box_ref_cmd:
flush_node_list(equiv_field(w));
break;
default:
break;
}
}

/*:15*//*16:*/
#line 599 "./luatexdir/tex/equivalents.w"

void eq_save(halfword p,quarterword l)
{
check_full_save_stack();
if(l==level_zero){
save_type(save_ptr)= restore_zero;
}else{
save_word(save_ptr)= eqtb[p];
save_type(save_ptr)= saved_eqtb;
incr(save_ptr);
save_type(save_ptr)= restore_old_value;
}
save_level(save_ptr)= l;
save_value(save_ptr)= p;
incr(save_ptr);
}

/*:16*//*18:*/
#line 625 "./luatexdir/tex/equivalents.w"

void eq_define(halfword p,quarterword t,halfword e)
{
boolean trace= int_par(tracing_assigns_code)> 0;
if((eq_type(p)==t)&&(equiv(p)==e)){
if(trace)
diagnostic_trace(p,"reassigning");
eq_destroy(eqtb[p]);
return;
}
if(trace)
diagnostic_trace(p,"changing");
if(eq_level(p)==cur_level)
eq_destroy(eqtb[p]);
else if(cur_level> level_one)
eq_save(p,eq_level(p));
set_eq_level(p,cur_level);
set_eq_type(p,t);
set_equiv(p,e);
if(trace)
diagnostic_trace(p,"into");
}

/*:18*//*19:*/
#line 652 "./luatexdir/tex/equivalents.w"

void eq_word_define(halfword p,int w)
{
boolean trace= int_par(tracing_assigns_code)> 0;
if(eqtb[p].cint==w){
if(trace)
diagnostic_trace(p,"reassigning");
return;
}
if(trace)
diagnostic_trace(p,"changing");
if(xeq_level[p]!=cur_level){
eq_save(p,xeq_level[p]);
xeq_level[p]= cur_level;
}
eqtb[p].cint= w;
if(trace)
diagnostic_trace(p,"into");
}


/*:19*//*20:*/
#line 678 "./luatexdir/tex/equivalents.w"

void geq_define(halfword p,quarterword t,halfword e)
{
boolean trace= int_par(tracing_assigns_code)> 0;
if(trace)
diagnostic_trace(p,"globally changing");
eq_destroy(eqtb[p]);
set_eq_level(p,level_one);
set_eq_type(p,t);
set_equiv(p,e);
if(trace)
diagnostic_trace(p,"into");
}

void geq_word_define(halfword p,int w)
{
boolean trace= int_par(tracing_assigns_code)> 0;
if(trace)
diagnostic_trace(p,"globally changing");
eqtb[p].cint= w;
xeq_level[p]= level_one;
if(trace)
diagnostic_trace(p,"into");
}

/*:20*//*21:*/
#line 705 "./luatexdir/tex/equivalents.w"

void save_for_after(halfword t)
{
if(cur_level> level_one){
check_full_save_stack();
save_type(save_ptr)= insert_token;
save_level(save_ptr)= level_zero;
save_value(save_ptr)= t;
incr(save_ptr);
}
}

/*:21*//*22:*/
#line 721 "./luatexdir/tex/equivalents.w"

void unsave(void)
{
halfword p;
quarterword l= level_one;
boolean a= false;
unsave_math_codes(cur_level);
unsave_cat_codes(int_par(cat_code_table_code),cur_level);
unsave_text_codes(cur_level);
unsave_math_data(cur_level);
if(cur_level> level_one){
boolean trace= int_par(tracing_restores_code)> 0;
decr(cur_level);

while(true){
decr(save_ptr);
if(save_type(save_ptr)==level_boundary)
break;
p= save_value(save_ptr);
if(save_type(save_ptr)==insert_token){
reinsert_token(a,p);
a= true;
}else{
if(save_type(save_ptr)==restore_old_value){
l= save_level(save_ptr);
decr(save_ptr);
}else{
save_word(save_ptr)= eqtb[undefined_control_sequence];
}







if(p<int_base||p> eqtb_size){
if(eq_level(p)==level_one){
eq_destroy(save_word(save_ptr));
if(trace)
diagnostic_trace(p,"retaining");
}else{
eq_destroy(eqtb[p]);
eqtb[p]= save_word(save_ptr);
if(trace)
diagnostic_trace(p,"restoring");
}
}else if(xeq_level[p]!=level_one){
eqtb[p]= save_word(save_ptr);
xeq_level[p]= l;
if(trace)
diagnostic_trace(p,"restoring");
}else{
if(trace)
diagnostic_trace(p,"retaining");
}
}
}
if(int_par(tracing_groups_code)> 0)
group_trace(true);
if(grp_stack[in_open]==cur_boundary)
group_warning();
cur_group= save_level(save_ptr);
cur_boundary= save_value(save_ptr);
decr(save_ptr);
}else{
confusion("curlevel");
}
attr_list_cache= cache_disabled;
}

/*:22*//*23:*/
#line 798 "./luatexdir/tex/equivalents.w"

int mag_set;

/*:23*//*24:*/
#line 804 "./luatexdir/tex/equivalents.w"

#define mag int_par(mag_code)

void prepare_mag(void)
{
if((mag_set> 0)&&(mag!=mag_set)){
print_err("Incompatible magnification (");
print_int(mag);
tprint(");");
tprint_nl(" the previous value will be retained");
help2("I can handle only one magnification ratio per job. So I've",
"reverted to the magnification you used earlier on this run.");
int_error(mag_set);
geq_word_define(int_base+mag_code,mag_set);
}
if((mag<=0)||(mag> 32768)){
print_err("Illegal magnification has been changed to 1000");
help1("The magnification ratio must be between 1 and 32768.");
int_error(mag);
geq_word_define(int_base+mag_code,1000);
}
if((mag_set==0)&&(mag!=mag_set)){
if(mag!=1000)
one_true_inch= xn_over_d(one_hundred_inch,10,mag);
else
one_true_inch= one_inch;
}
mag_set= mag;
}

/*:24*//*25:*/
#line 880 "./luatexdir/tex/equivalents.w"

int cur_cmd;
halfword cur_chr;
halfword cur_cs;
halfword cur_tok;

/*:25*//*26:*/
#line 888 "./luatexdir/tex/equivalents.w"

#define mode cur_list.mode_field

void show_cur_cmd_chr(void)
{
int n;
int l;
halfword p;
begin_diagnostic();
tprint_nl("{");
if(mode!=shown_mode){
print_mode(mode);
tprint(": ");
shown_mode= mode;
}
print_cmd_chr((quarterword)cur_cmd,cur_chr);
if(int_par(tracing_ifs_code)> 0){
if(cur_cmd>=if_test_cmd){
if(cur_cmd<=fi_or_else_cmd){
tprint(": ");
if(cur_cmd==fi_or_else_cmd){
print_cmd_chr(if_test_cmd,cur_if);
print_char(' ');
n= 0;
l= if_line;
}else{
n= 1;
l= line;
}
p= cond_ptr;
while(p!=null){
incr(n);
p= vlink(p);
}
tprint("(level ");
print_int(n);
print_char(')');
print_if_line(l);
}
}
}
print_char('}');
end_diagnostic(false);
}

/*:26*//*27:*/
#line 935 "./luatexdir/tex/equivalents.w"

void show_eqtb(halfword n)
{
if(n<null_cs){

print_char('?');
}else if((n<glue_base)||((n> eqtb_size)&&(n<=eqtb_top))){








sprint_cs(n);
print_char('=');
print_cmd_chr(eq_type(n),equiv(n));
if(eq_type(n)>=call_cmd){
print_char(':');
show_token_list(token_link(equiv(n)),null,32);
}
}else if(n<local_base){





if(n<skip_base){
if(n<glue_base+thin_mu_skip_code)
print_cmd_chr(assign_glue_cmd,n);
else
print_cmd_chr(assign_mu_glue_cmd,n);
print_char('=');
if(n<glue_base+thin_mu_skip_code)
print_spec(equiv(n),"pt");
else
print_spec(equiv(n),"mu");
}else if(n<mu_skip_base){
tprint_esc("skip");
print_int(n-skip_base);
print_char('=');
print_spec(equiv(n),"pt");
}else{
tprint_esc("muskip");
print_int(n-mu_skip_base);
print_char('=');
print_spec(equiv(n),"mu");
}

}else if(n<int_base){













if((n==par_shape_loc)||((n>=etex_pen_base)&&(n<etex_pens))){
if(n==par_shape_loc)
print_cmd_chr(set_tex_shape_cmd,n);
else
print_cmd_chr(set_etex_shape_cmd,n);
print_char('=');
if(equiv(n)==null){
print_char('0');
}else if(n> par_shape_loc){
print_int(penalty(equiv(n)));
print_char(' ');
print_int(penalty(equiv(n)+1));
if(penalty(equiv(n))> 1)
tprint_esc("ETC.");
}else{
print_int(vinfo(par_shape_ptr+1));
}
}else if(n<toks_base){
print_cmd_chr(assign_toks_cmd,n);
print_char('=');
if(equiv(n)!=null)
show_token_list(token_link(equiv(n)),null,32);
}else if(n<box_base){
tprint_esc("toks");
print_int(n-toks_base);
print_char('=');
if(equiv(n)!=null)
show_token_list(token_link(equiv(n)),null,32);
}else if(n<cur_font_loc){
tprint_esc("box");
print_int(n-box_base);
print_char('=');
if(equiv(n)==null){
tprint("void");
}else{
depth_threshold= 0;
breadth_max= 1;
show_node_list(equiv(n));
}
}else if(n==cur_font_loc){

tprint("current font");
print_char('=');
print_esc(hash[font_id_base+equiv(n)].rh);
}
}else if(n<dimen_base){

if(n<dir_base){
print_cmd_chr(assign_int_cmd,n);
print_char('=');
print_int(eqtb[n].cint);
}else if(n<count_base){
print_cmd_chr(assign_dir_cmd,n);
print_char(' ');
print_dir(eqtb[n].cint);
}else if(n<attribute_base){
tprint_esc("count");
print_int(n-count_base);
print_char('=');
print_int(eqtb[n].cint);
}else if(n<del_code_base){
tprint_esc("attribute");
print_int(n-attribute_base);
print_char('=');
print_int(eqtb[n].cint);
}
}else if(n<=eqtb_size){

if(n<scaled_base){
print_cmd_chr(assign_dimen_cmd,n);
}else{
tprint_esc("dimen");
print_int(n-scaled_base);
}
print_char('=');
print_scaled(eqtb[n].cint);
tprint("pt");
}else{

print_char('?');
}
}

/*:27*//*28:*/
#line 1082 "./luatexdir/tex/equivalents.w"

void show_eqtb_meaning(halfword n)
{
if(n<null_cs){

print_char('?');
}else if((n<glue_base)||((n> eqtb_size)&&(n<=eqtb_top))){







sprint_cs(n);
}else if(n<local_base){





if(n<skip_base){
if(n<glue_base+thin_mu_skip_code)
print_cmd_chr(assign_glue_cmd,n);
else
print_cmd_chr(assign_mu_glue_cmd,n);
}else if(n<mu_skip_base){
tprint_esc("skip");
print_int(n-skip_base);
}else{
tprint_esc("muskip");
print_int(n-mu_skip_base);
}

}else if(n<int_base){













if((n==par_shape_loc)||((n>=etex_pen_base)&&(n<etex_pens))){
if(n==par_shape_loc)
print_cmd_chr(set_tex_shape_cmd,n);
else
print_cmd_chr(set_etex_shape_cmd,n);
}else if(n<toks_base){
print_cmd_chr(assign_toks_cmd,n);
}else if(n<box_base){
tprint_esc("toks");
print_int(n-toks_base);
}else if(n<cur_font_loc){
tprint_esc("box");
print_int(n-box_base);
}else if(n==cur_font_loc){

tprint("current font");
}
}else if(n<dimen_base){

if(n<dir_base){
print_cmd_chr(assign_int_cmd,n);
}else if(n<count_base){
print_cmd_chr(assign_dir_cmd,n);
}else if(n<attribute_base){
tprint_esc("count");
print_int(n-count_base);
}else if(n<del_code_base){
tprint_esc("attribute");
print_int(n-attribute_base);
}
}else if(n<=eqtb_size){

if(n<scaled_base){
print_cmd_chr(assign_dimen_cmd,n);
}else{
tprint_esc("dimen");
print_int(n-scaled_base);
}
}else{

print_char('?');
}
}/*:28*/
