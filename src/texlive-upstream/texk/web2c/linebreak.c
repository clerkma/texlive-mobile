/*1:*/
#line 20 "./luatexdir/tex/linebreak.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 73 "./luatexdir/tex/linebreak.w"

halfword just_box;

/*:2*//*3:*/
#line 94 "./luatexdir/tex/linebreak.w"

void line_break(boolean d,int line_break_context)
{
int paragraph_dir= 0;
halfword final_par_glue;
halfword start_of_par;
int callback_id;
pack_begin_line= cur_list.ml_field;
alink(temp_head)= null;
vlink(temp_head)= vlink(cur_list.head_field);
new_hyphenation(temp_head,cur_list.tail_field);
cur_list.tail_field= new_ligkern(temp_head,cur_list.tail_field);
if(is_char_node(cur_list.tail_field)){
tail_append(new_penalty(inf_penalty));
}else if(type(cur_list.tail_field)!=glue_node){
tail_append(new_penalty(inf_penalty));
}else{
halfword t= alink(cur_list.tail_field);
flush_node(cur_list.tail_field);
cur_list.tail_field= t;
tail_append(new_penalty(inf_penalty));
}
final_par_glue= new_param_glue(par_fill_skip_code);
couple_nodes(cur_list.tail_field,final_par_glue);
cur_list.tail_field= vlink(cur_list.tail_field);
lua_node_filter(pre_linebreak_filter_callback,
line_break_context,temp_head,
addressof(cur_list.tail_field));
last_line_fill= cur_list.tail_field;
pop_nest();
start_of_par= cur_list.tail_field;
callback_id= callback_defined(linebreak_filter_callback);
if(callback_id> 0){
callback_id= lua_linebreak_callback(d,temp_head,addressof(cur_list.tail_field));
if(callback_id> 0){

halfword box_search= cur_list.tail_field;
just_box= null;
if(box_search!=null){
do{
if(type(box_search)==hlist_node){
just_box= box_search;
}
box_search= vlink(box_search);
}while(box_search!=null);
}
if(just_box==null){
help3
("A linebreaking routine should return a non-empty list of nodes",
"and at least one of those has to be a \\hbox.",
"Sorry, I cannot recover from this.");
print_err("Invalid linebreak_filter");
succumb();
}
}else{
if(tracing_paragraphs_par> 0){
begin_diagnostic();
print_int(line);
end_diagnostic(true);
}
}
}
if(callback_id==0){
if((!is_char_node(vlink(temp_head)))&&((type(vlink(temp_head))==local_par_node))){
paragraph_dir= local_par_dir(vlink(temp_head));
}else{
confusion("weird par dir");
}
ext_do_line_break(paragraph_dir,
pretolerance_par,
tracing_paragraphs_par,
tolerance_par,
emergency_stretch_par,
looseness_par,
adjust_spacing_par,
par_shape_par_ptr,
adj_demerits_par,
protrude_chars_par,
line_penalty_par,
last_line_fit_par,
double_hyphen_demerits_par,
final_hyphen_demerits_par,
hang_indent_par,
hsize_par,
hang_after_par,
left_skip_par,
right_skip_par,
inter_line_penalties_par_ptr,
inter_line_penalty_par,
club_penalty_par,
club_penalties_par_ptr,
(d?display_widow_penalties_par_ptr:widow_penalties_par_ptr),
(d?display_widow_penalty_code:widow_penalty_code),
broken_penalty_par,
final_par_glue);
}
lua_node_filter(post_linebreak_filter_callback,
line_break_context,start_of_par,
addressof(cur_list.tail_field));
pack_begin_line= 0;
}

/*:3*//*4:*/
#line 203 "./luatexdir/tex/linebreak.w"

#define check_shrinkage(a) \
    if ((shrink_order((a))!=normal)&&(shrink((a))!=0)) \
        a= finite_shrink((a))

static boolean no_shrink_error_yet;

static halfword finite_shrink(halfword p)
{
const char*hlp[]= {
"The paragraph just ended includes some glue that has",
"infinite shrinkability, e.g., `\\hskip 0pt minus 1fil'.",
"Such glue doesn't belong there---it allows a paragraph",
"of any length to fit on one line. But it's safe to proceed,",
"since the offensive shrinkability has been made finite.",
NULL
};
if(no_shrink_error_yet){
no_shrink_error_yet= false;
tex_error("Infinite glue shrinkage found in a paragraph",hlp);
}
shrink_order(p)= normal;
return p;
}

/*:4*//*5:*/
#line 250 "./luatexdir/tex/linebreak.w"

static boolean second_pass;
static boolean final_pass;
static int threshold;


#define max_hlist_stack 512     




static halfword hlist_stack[max_hlist_stack];


static short hlist_stack_level= 0;

/*:5*//*6:*/
#line 266 "./luatexdir/tex/linebreak.w"

static void push_node(halfword p)
{
if(hlist_stack_level>=max_hlist_stack)
normal_error("push_node","stack overflow");
hlist_stack[hlist_stack_level++]= p;
}

static halfword pop_node(void)
{
if(hlist_stack_level<=0)
normal_error("pop_node","stack underflow (internal error)");
return hlist_stack[--hlist_stack_level];
}

/*:6*//*7:*/
#line 281 "./luatexdir/tex/linebreak.w"

static int max_stretch_ratio= 0;
static int max_shrink_ratio= 0;
static int cur_font_step= 0;

static boolean check_expand_pars(internal_font_number f)
{
int m;

if((font_step(f)==0)
||((font_max_stretch(f)==0)&&(font_max_shrink(f)==0)))
return false;
if(cur_font_step<0)
cur_font_step= font_step(f);
else if(cur_font_step!=font_step(f))
normal_error("font expansion","using fonts with different step of expansion in one paragraph is not allowed");
m= font_max_stretch(f);
if(m!=0){
if(max_stretch_ratio<0)
max_stretch_ratio= m;
else if(max_stretch_ratio!=m)
normal_error("font expansion","using fonts with different limit of expansion in one paragraph is not allowed");
}
m= font_max_shrink(f);
if(m!=0){
if(max_shrink_ratio<0)
max_shrink_ratio= -m;
else if(max_shrink_ratio!=-m)
normal_error("font expansion","using fonts with different limit of expansion in one paragraph is not allowed");
}
return true;
}

/*:7*//*8:*/
#line 316 "./luatexdir/tex/linebreak.w"

halfword find_protchar_left(halfword l,boolean d)
{
halfword t;
boolean run;
boolean done= false;
while((vlink(l)!=null)&&(type(l)==hlist_node)&&zero_dimensions(l)&&(list_ptr(l)==null)){

l= vlink(l);
done= true;
}
if((!done)&&(type(l)==local_par_node)){
l= vlink(l);
done= true;
}
if((!done)&&d){
while((vlink(l)!=null)&&(!(is_char_node(l)||non_discardable(l)))){

l= vlink(l);
}
}
if(type(l)!=glyph_node){
hlist_stack_level= 0;
run= true;
do{
t= l;
while(run&&(type(l)==hlist_node)&&(list_ptr(l)!=null)){
push_node(l);
l= list_ptr(l);
}
while(run&&cp_skipable(l)){
while((vlink(l)==null)&&(hlist_stack_level> 0)){
l= pop_node();
run= false;
}
if((vlink(l)!=null)&&(type(l)==boundary_node)&&(subtype(l)==protrusion_boundary)&&
((boundary_value(l)==1)||(boundary_value(l)==3))){

l= vlink(l);
}
if(vlink(l)!=null){
l= vlink(l);
}else if(hlist_stack_level==0){
run= false;
}
}
}while(t!=l);
}
return l;
}

/*:8*//*9:*/
#line 369 "./luatexdir/tex/linebreak.w"

halfword find_protchar_right(halfword l,halfword r)
{
halfword t;
boolean run= true;
if(r==null)
return null;
hlist_stack_level= 0;
do{
t= r;
while(run&&(type(r)==hlist_node)&&(list_ptr(r)!=null)){
push_node(l);
push_node(r);
l= list_ptr(r);
r= l;
while(vlink(r)!=null){
halfword s= r;
r= vlink(r);
alink(r)= s;
}
}
while(run&&cp_skipable(r)){
while((r==l)&&(hlist_stack_level> 0)){
r= pop_node();
l= pop_node();
}
if((r!=l)&&(r!=null)){
if((alink(r)!=null)&&(type(r)==boundary_node)&&(subtype(r)==protrusion_boundary)&&
((boundary_value(r)==2)||(boundary_value(r)==3))){

r= alink(r);
}
if(alink(r)!=null){
r= alink(r);
}else{
run= false;
}
}else if((r==l)&&(hlist_stack_level==0))
run= false;
}
}while(t!=r);
return r;
}

/*:9*//*10:*/
#line 413 "./luatexdir/tex/linebreak.w"

#define left_pw(a) char_pw((a), left_side)
#define right_pw(a) char_pw((a), right_side)

/*:10*//*11:*/
#line 426 "./luatexdir/tex/linebreak.w"

typedef enum{
very_loose_fit= 0,

loose_fit,

decent_fit,
tight_fit

}fitness_value;


/*:11*//*13:*/
#line 479 "./luatexdir/tex/linebreak.w"

void initialize_active(void)
{
type(active)= hyphenated_node;
line_number(active)= max_halfword;
subtype(active)= 0;
}

/*:13*//*14:*/
#line 511 "./luatexdir/tex/linebreak.w"

static halfword passive;
static halfword printed_node;
static halfword pass_number;

/*:14*//*15:*/
#line 548 "./luatexdir/tex/linebreak.w"

static scaled active_width[10]= {0};
static scaled background[10]= {0};
static scaled break_width[10]= {0};

static boolean auto_breaking;

/*:15*//*17:*/
#line 610 "./luatexdir/tex/linebreak.w"

static int internal_pen_inter;
static int internal_pen_broken;
static halfword internal_left_box;
static int internal_left_box_width;
static halfword init_internal_left_box;
static int init_internal_left_box_width;
static halfword internal_right_box;
static int internal_right_box_width;

static scaled disc_width[10]= {0};

/*:17*//*18:*/
#line 634 "./luatexdir/tex/linebreak.w"

static int minimal_demerits[4];

static int minimum_demerits;

static halfword best_place[4];
static halfword best_pl_line[4];

/*:18*//*19:*/
#line 658 "./luatexdir/tex/linebreak.w"

static halfword easy_line;
static halfword last_special_line;
static scaled first_width;

static scaled second_width;
static scaled first_indent;
static scaled second_indent;

static halfword best_bet;
static int fewest_demerits;
static halfword best_line;
static int actual_looseness;

static int line_diff;


/*:19*//*20:*/
#line 682 "./luatexdir/tex/linebreak.w"

#define do_all_six(a) a(1);a(2);a(3);a(4);a(5);a(6);a(7)
#define do_seven_eight(a) if (adjust_spacing >  1) { a(8);a(9); }
#define do_all_eight(a) do_all_six(a); do_seven_eight(a)
#define do_one_seven_eight(a) a(1); do_seven_eight(a)

#define store_background(a) {active_width[a]= background[a];}

#define kern_break() { \
    if ((!is_char_node(vlink(cur_p))) && auto_breaking) \
        if (type(vlink(cur_p))==glue_node) \
            ext_try_break(0, \
                          unhyphenated_node, \
                          line_break_dir, \
                          adjust_spacing, \
                          par_shape_ptr, \
                          adj_demerits, \
                          tracing_paragraphs, \
                          protrude_chars, \
                          line_penalty, \
                          last_line_fit, \
                          double_hyphen_demerits, \
                          final_hyphen_demerits, \
                          first_p, \
                          cur_p); \
    if (type(cur_p)!=math_node) \
        active_width[1] +=  width(cur_p); \
    else \
        active_width[1] +=  surround(cur_p); \
}

#define clean_up_the_memory() { \
    q= vlink(active); \
    while (q!=active) { \
        cur_p =  vlink(q); \
        if (type(q)==delta_node) \
            flush_node(q); \
        else \
            flush_node(q); \
        q =  cur_p; \
    } \
    q =  passive;  \
    while (q!=null) { \
        cur_p =  vlink(q); \
        flush_node(q); \
        q =  cur_p; \
    } \
}

static boolean do_last_line_fit;
static scaled fill_width[4];
static scaled best_pl_short[4];
static scaled best_pl_glue[4];

#define reset_disc_width(a) disc_width[(a)] =  0

#define add_disc_width_to_break_width(a)     break_width[(a)] +=  disc_width[(a)]
#define sub_disc_width_from_active_width(a)  active_width[(a)] -=  disc_width[(a)]

#define add_char_shrink(a,b)  a +=  char_shrink((b))
#define add_char_stretch(a,b) a +=  char_stretch((b))
#define sub_char_shrink(a,b)  a -=  char_shrink((b))
#define sub_char_stretch(a,b) a -=  char_stretch((b))

#define add_kern_shrink(a,b)  a +=  kern_shrink((b))
#define add_kern_stretch(a,b) a +=  kern_stretch((b))
#define sub_kern_shrink(a,b)  a -=  kern_shrink((b))
#define sub_kern_stretch(a,b) a -=  kern_stretch((b))

/*:20*//*21:*/
#line 757 "./luatexdir/tex/linebreak.w"

static void add_to_widths(halfword s,int line_break_dir,int adjust_spacing,scaled*widths)
{
while(s!=null){
if(is_char_node(s)){
widths[1]+= pack_width(line_break_dir,dir_TRT,s,true);
if((adjust_spacing> 1)&&check_expand_pars(font(s))){
set_prev_char_p(s);
add_char_stretch(widths[8],s);
add_char_shrink(widths[9],s);
};
}else{
switch(type(s)){
case hlist_node:
case vlist_node:
widths[1]+= pack_width(line_break_dir,box_dir(s),s,false);
break;
case kern_node:
if((adjust_spacing==2)&&(subtype(s)==normal)){
add_kern_stretch(widths[8],s);
add_kern_shrink(widths[9],s);
}

case rule_node:
widths[1]+= width(s);
break;
case disc_node:
break;
default:
confusion("invalid node found in discretionary");
}
}
s= vlink(s);
}
}

/*:21*//*22:*/
#line 798 "./luatexdir/tex/linebreak.w"

static void sub_from_widths(halfword s,int line_break_dir,int adjust_spacing,scaled*widths)
{
while(s!=null){

if(is_char_node(s)){
widths[1]-= pack_width(line_break_dir,dir_TRT,s,true);
if((adjust_spacing> 1)&&check_expand_pars(font(s))){
set_prev_char_p(s);
sub_char_stretch(widths[8],s);
sub_char_shrink(widths[9],s);
}
}else{
switch(type(s)){
case hlist_node:
case vlist_node:
widths[1]-= pack_width(line_break_dir,box_dir(s),s,false);
break;
case kern_node:
if((adjust_spacing==2)&&(subtype(s)==normal)){
sub_kern_stretch(widths[8],s);
sub_kern_shrink(widths[9],s);
}

case rule_node:
widths[1]-= width(s);
break;
case disc_node:
break;
default:
confusion("invalid node found in discretionary");
break;
}
}
s= vlink(s);
}
}

/*:22*//*23:*/
#line 855 "./luatexdir/tex/linebreak.w"

static void compute_break_width(int break_type,int line_break_dir,int adjust_spacing,halfword p)
{
halfword s= p;

if(break_type> unhyphenated_node&&p!=null){



























sub_from_widths(vlink_no_break(p),line_break_dir,adjust_spacing,break_width);
add_to_widths(vlink_post_break(p),line_break_dir,adjust_spacing,break_width);
do_one_seven_eight(add_disc_width_to_break_width);
if(vlink_post_break(p)==null){
s= vlink(p);
}else{
s= null;
}
}
while(s!=null){
switch(type(s)){
case math_node:

if(glue_is_zero(math_skip_par)){
break_width[1]-= surround(s);
break;
}else{

}

case glue_node:

break_width[1]-= width(s);
break_width[2+stretch_order(s)]-= stretch(s);
break_width[7]-= shrink(s);
break;
case penalty_node:
break;
case kern_node:
if(subtype(s)!=explicit_kern&&subtype(s)!=italic_kern)
return;
else
break_width[1]-= width(s);
break;
default:
return;
};
s= vlink(s);
}
}

/*:23*//*24:*/
#line 929 "./luatexdir/tex/linebreak.w"

static void print_break_node(halfword q,fitness_value fit_class,
quarterword break_type,halfword cur_p)
{

tprint_nl("@@");
print_int(serial(passive));
tprint(": line ");
print_int(line_number(q)-1);
print_char('.');
print_int(fit_class);
if(break_type==hyphenated_node)
print_char('-');
tprint(" t=");
print_int(total_demerits(q));
if(do_last_line_fit){

tprint(" s=");
print_scaled(active_short(q));
if(cur_p==null)
tprint(" a=");
else
tprint(" g=");
print_scaled(active_glue(q));
}
tprint(" -> @");
if(prev_break(passive)==null)
print_char('0');
else
print_int(serial(prev_break(passive)));
}

/*:24*//*25:*/
#line 961 "./luatexdir/tex/linebreak.w"

static void print_feasible_break(halfword cur_p,pointer r,halfword b,int pi,
int d,boolean artificial_demerits)
{

if(printed_node!=cur_p){


tprint_nl("");
if(cur_p==null){
short_display(vlink(printed_node));
}else{
halfword save_link= vlink(cur_p);
vlink(cur_p)= null;
tprint_nl("");
short_display(vlink(printed_node));
vlink(cur_p)= save_link;
}
printed_node= cur_p;
}
tprint_nl("@");
if(cur_p==null){
tprint_esc("par");
}else if(type(cur_p)!=glue_node){
if(type(cur_p)==penalty_node)
tprint_esc("penalty");
else if(type(cur_p)==disc_node)
tprint_esc("discretionary");
else if(type(cur_p)==kern_node)
tprint_esc("kern");
else
tprint_esc("math");
}
tprint(" via @");
if(break_node(r)==null)
print_char('0');
else
print_int(serial(break_node(r)));
tprint(" b=");
if(b> inf_bad)
print_char('*');
else
print_int(b);
tprint(" p=");
print_int(pi);
tprint(" d=");
if(artificial_demerits)
print_char('*');
else
print_int(d);
}

/*:25*//*26:*/
#line 1013 "./luatexdir/tex/linebreak.w"

#define add_disc_width_to_active_width(a)   active_width[a] +=  disc_width[a]
#define update_width(a) cur_active_width[a] +=  varmem[(r+(a))].cint

#define set_break_width_to_background(a) break_width[a]= background[(a)]

#define convert_to_break_width(a) \
  varmem[(prev_r+(a))].cint =  varmem[(prev_r+(a))].cint-cur_active_width[(a)]+break_width[(a)]

#define store_break_width(a) active_width[(a)]= break_width[(a)]

#define new_delta_to_break_width(a) \
  varmem[(q+(a))].cint= break_width[(a)]-cur_active_width[(a)]

#define new_delta_from_break_width(a) \
  varmem[(q+(a))].cint= cur_active_width[(a)]-break_width[(a)]

#define copy_to_cur_active(a) cur_active_width[(a)]= active_width[(a)]

#define combine_two_deltas(a) varmem[(prev_r+(a))].cint +=  varmem[(r+(a))].cint
#define downdate_width(a) cur_active_width[(a)] -=  varmem[(prev_r+(a))].cint
#define update_active(a) active_width[(a)]+= varmem[(r+(a))].cint

#define total_font_stretch cur_active_width[8]
#define total_font_shrink cur_active_width[9]

#define cal_margin_kern_var(a) { \
    character(cp) =  character((a)); \
    font(cp) =  font((a)); \
    do_subst_font(cp, 1000); \
    if (font(cp) != font((a))) \
        margin_kern_stretch +=  (left_pw((a)) - left_pw(cp)); \
    font(cp) =  font((a)); \
    do_subst_font(cp, -1000); \
    if (font(cp) != font((a))) \
        margin_kern_shrink +=  (left_pw(cp) - left_pw((a))); \
}

static void ext_try_break(int pi,
quarterword break_type,
int line_break_dir,
int adjust_spacing,
int par_shape_ptr,
int adj_demerits,
int tracing_paragraphs,
int protrude_chars,
int line_penalty,
int last_line_fit,
int double_hyphen_demerits,
int final_hyphen_demerits,halfword first_p,halfword cur_p)
{

pointer r;
scaled margin_kern_stretch;
scaled margin_kern_shrink;
halfword lp,rp,cp;
halfword prev_r= active;
halfword prev_prev_r= null;
halfword old_l= 0;
boolean no_break_yet= true;
halfword q;
halfword l;
boolean node_r_stays_active;
scaled line_width= 0;
fitness_value fit_class;
halfword b;
int d;
boolean artificial_demerits;

scaled shortfall;
scaled g= 0;
scaled cur_active_width[10]= {0};


if(pi>=inf_penalty){
return;
}else if(pi<=-inf_penalty){
pi= eject_penalty;
}

do_all_eight(copy_to_cur_active);

while(1){
r= vlink(prev_r);



if(type(r)==delta_node){
do_all_eight(update_width);
prev_prev_r= prev_r;
prev_r= r;
continue;
}









l= line_number(r);
if(l> old_l){
if((minimum_demerits<awful_bad)
&&((old_l!=easy_line)||(r==active))){







if(no_break_yet){
no_break_yet= false;
do_all_eight(set_break_width_to_background);
compute_break_width(break_type,line_break_dir,adjust_spacing,cur_p);
}


if(type(prev_r)==delta_node){
do_all_eight(convert_to_break_width);
}else if(prev_r==active){
do_all_eight(store_break_width);
}else{
q= new_node(delta_node,0);
vlink(q)= r;
do_all_eight(new_delta_to_break_width);
vlink(prev_r)= q;
prev_prev_r= prev_r;
prev_r= q;
}

if(abs(adj_demerits)>=awful_bad-minimum_demerits)
minimum_demerits= awful_bad-1;
else
minimum_demerits+= abs(adj_demerits);
for(fit_class= very_loose_fit;fit_class<=tight_fit;
fit_class++){
if(minimal_demerits[fit_class]<=minimum_demerits){





q= new_node(passive_node,0);
vlink(q)= passive;
passive= q;
cur_break(q)= cur_p;
incr(pass_number);
serial(q)= pass_number;
prev_break(q)= best_place[fit_class];

passive_pen_inter(q)= internal_pen_inter;
passive_pen_broken(q)= internal_pen_broken;
passive_last_left_box(q)= internal_left_box;
passive_last_left_box_width(q)= 
internal_left_box_width;
if(prev_break(q)!=null){
passive_left_box(q)= 
passive_last_left_box(prev_break(q));
passive_left_box_width(q)= 
passive_last_left_box_width(prev_break(q));
}else{
passive_left_box(q)= init_internal_left_box;
passive_left_box_width(q)= 
init_internal_left_box_width;
}
passive_right_box(q)= internal_right_box;
passive_right_box_width(q)= internal_right_box_width;
q= new_node(break_type,fit_class);
break_node(q)= passive;
line_number(q)= best_pl_line[fit_class]+1;
total_demerits(q)= minimal_demerits[fit_class];
if(do_last_line_fit){



active_short(q)= best_pl_short[fit_class];
active_glue(q)= best_pl_glue[fit_class];
}
vlink(q)= r;
vlink(prev_r)= q;
prev_r= q;
if(tracing_paragraphs> 0)
print_break_node(q,fit_class,break_type,cur_p);
}
minimal_demerits[fit_class]= awful_bad;
}
minimum_demerits= awful_bad;




if(r!=active){
q= new_node(delta_node,0);
vlink(q)= r;
do_all_eight(new_delta_from_break_width);
vlink(prev_r)= q;
prev_prev_r= prev_r;
prev_r= q;
}
}
if(r==active)
return;








if(l> easy_line){
old_l= max_halfword-1;
line_width= second_width;
}else{
old_l= l;
if(l> last_special_line){
line_width= second_width;
}else if(par_shape_ptr==null){
line_width= first_width;
}else{
line_width= varmem[(par_shape_ptr+2*l+1)].cint;
}
}
}








artificial_demerits= false;
shortfall= line_width-cur_active_width[1];
if(break_node(r)==null)
shortfall-= init_internal_left_box_width;
else
shortfall-= passive_last_left_box_width(break_node(r));
shortfall-= internal_right_box_width;
if(protrude_chars> 1){
halfword l1,o;
l1= (break_node(r)==null)?first_p:cur_break(break_node(r));
if(cur_p==null){
o= null;
}else{
o= alink(cur_p);
assert(vlink(o)==cur_p);
}










if((cur_p!=null)&&(type(cur_p)==disc_node)
&&(vlink_pre_break(cur_p)!=null)){

o= tlink_pre_break(cur_p);
}else{
o= find_protchar_right(l1,o);
}

if((l1!=null)&&(type(l1)==disc_node)&&(vlink_post_break(l1)!=null)){

l1= vlink_post_break(l1);
}else{
l1= find_protchar_left(l1,true);
}
shortfall+= (left_pw(l1)+right_pw(o));
}
if(shortfall!=0){
margin_kern_stretch= 0;
margin_kern_shrink= 0;
if(protrude_chars> 1){

lp= last_leftmost_char;
rp= last_rightmost_char;
cp= raw_glyph_node();
if(lp!=null){
cal_margin_kern_var(lp);
}
if(rp!=null){
cal_margin_kern_var(rp);
}
flush_node(cp);
}
if((shortfall> 0)&&((total_font_stretch+margin_kern_stretch)> 0)){
if((total_font_stretch+margin_kern_stretch)> shortfall)
shortfall= ((total_font_stretch+margin_kern_stretch)/(max_stretch_ratio/cur_font_step))/2;
else
shortfall-= (total_font_stretch+margin_kern_stretch);
}else if((shortfall<0)&&((total_font_shrink+margin_kern_shrink)> 0)){
if((total_font_shrink+margin_kern_shrink)> -shortfall)
shortfall= -((total_font_shrink+margin_kern_shrink)/(max_shrink_ratio/cur_font_step))/2;
else
shortfall+= (total_font_shrink+margin_kern_shrink);
}
}
if(shortfall> 0){













if((cur_active_width[3]!=0)||(cur_active_width[4]!=0)||
(cur_active_width[5]!=0)||(cur_active_width[6]!=0)){
if(do_last_line_fit){
if(cur_p==null){









if((active_short(r)==0)||(active_glue(r)<=0))


goto NOT_FOUND;
if((cur_active_width[3]!=fill_width[0])||
(cur_active_width[4]!=fill_width[1])||
(cur_active_width[5]!=fill_width[2])||
(cur_active_width[6]!=fill_width[3]))


goto NOT_FOUND;
if(active_short(r)> 0)
g= cur_active_width[2];
else
g= cur_active_width[7];
if(g<=0)

goto NOT_FOUND;
arith_error= false;
g= fract(g,active_short(r),active_glue(r),
max_dimen);
if(last_line_fit<1000)
g= fract(g,last_line_fit,1000,max_dimen);
if(arith_error){
if(active_short(r)> 0)
g= max_dimen;
else
g= -max_dimen;
}
if(g> 0){






if(g> shortfall)
g= shortfall;
if(g> 7230584){
if(cur_active_width[2]<1663497){
b= inf_bad;
fit_class= very_loose_fit;
goto FOUND;
}
}
b= badness(g,cur_active_width[2]);
if(b> 99){
fit_class= very_loose_fit;
}else if(b> 12){
fit_class= loose_fit;
}else{
fit_class= decent_fit;
}
goto FOUND;
}else if(g<0){



if(-g> cur_active_width[7])
g= -cur_active_width[7];
b= badness(-g,cur_active_width[7]);
if(b> 12)
fit_class= tight_fit;
else
fit_class= decent_fit;
goto FOUND;
}
}
NOT_FOUND:
shortfall= 0;
}
b= 0;
fit_class= decent_fit;
}else{
if(shortfall> 7230584&&cur_active_width[2]<1663497){
b= inf_bad;
fit_class= very_loose_fit;
}else{
b= badness(shortfall,cur_active_width[2]);
if(b> 99){
fit_class= very_loose_fit;
}else if(b> 12){
fit_class= loose_fit;
}else{
fit_class= decent_fit;
}
}
}
}else{





if(-shortfall> cur_active_width[7])
b= inf_bad+1;
else
b= badness(-shortfall,cur_active_width[7]);
if(b> 12)
fit_class= tight_fit;
else
fit_class= decent_fit;
}
if(do_last_line_fit){

if(cur_p==null)
shortfall= 0;
if(shortfall> 0){
g= cur_active_width[2];
}else if(shortfall<0){
g= cur_active_width[7];
}else{
g= 0;
}
}
FOUND:
if((b> inf_bad)||(pi==eject_penalty)){










if(final_pass&&(minimum_demerits==awful_bad)&&
(vlink(r)==active)&&(prev_r==active)){
artificial_demerits= true;
}else if(b> threshold){
goto DEACTIVATE;
}
node_r_stays_active= false;
}else{
prev_r= r;
if(b> threshold)
continue;
node_r_stays_active= true;
}









if(artificial_demerits){
d= 0;
}else{

d= line_penalty+b;
if(abs(d)>=10000)
d= 100000000;
else
d= d*d;
if(pi!=0){
if(pi> 0){
d+= (pi*pi);
}else if(pi> eject_penalty){
d-= (pi*pi);
}
}
if((break_type==hyphenated_node)&&(type(r)==hyphenated_node)){
if(cur_p!=null)
d+= double_hyphen_demerits;
else
d+= final_hyphen_demerits;
}
if(abs(fit_class-fitness(r))> 1)
d= d+adj_demerits;
}
if(tracing_paragraphs> 0)
print_feasible_break(cur_p,r,b,pi,d,artificial_demerits);
d+= total_demerits(r);

if(d<=minimal_demerits[fit_class]){
minimal_demerits[fit_class]= d;
best_place[fit_class]= break_node(r);
best_pl_line[fit_class]= l;
if(do_last_line_fit){



best_pl_short[fit_class]= shortfall;
best_pl_glue[fit_class]= g;
}
if(d<minimum_demerits)
minimum_demerits= d;
}

if(node_r_stays_active)
continue;
DEACTIVATE:







vlink(prev_r)= vlink(r);
flush_node(r);
if(prev_r==active){







r= vlink(active);
if(type(r)==delta_node){
do_all_eight(update_active);
do_all_eight(copy_to_cur_active);
vlink(active)= vlink(r);
flush_node(r);
}
}else if(type(prev_r)==delta_node){
r= vlink(prev_r);
if(r==active){
do_all_eight(downdate_width);
vlink(prev_prev_r)= active;
flush_node(prev_r);
prev_r= prev_prev_r;
}else if(type(r)==delta_node){
do_all_eight(update_width);
do_all_eight(combine_two_deltas);
vlink(prev_r)= vlink(r);
flush_node(r);
}
}
}
}

/*:26*//*27:*/
#line 1582 "./luatexdir/tex/linebreak.w"

void ext_do_line_break(int paragraph_dir,
int pretolerance,
int tracing_paragraphs,
int tolerance,
scaled emergency_stretch,
int looseness,
int adjust_spacing,
halfword par_shape_ptr,
int adj_demerits,
int protrude_chars,
int line_penalty,
int last_line_fit,
int double_hyphen_demerits,
int final_hyphen_demerits,
int hang_indent,
int hsize,
int hang_after,
halfword left_skip,
halfword right_skip,
halfword inter_line_penalties_ptr,
int inter_line_penalty,
int club_penalty,
halfword club_penalties_ptr,
halfword widow_penalties_ptr,
int widow_penalty,
int broken_penalty,
halfword final_par_glue)
{

halfword cur_p,q,r,s;
int line_break_dir= paragraph_dir;


minimum_demerits= awful_bad;
minimal_demerits[tight_fit]= awful_bad;
minimal_demerits[decent_fit]= awful_bad;
minimal_demerits[loose_fit]= awful_bad;
minimal_demerits[very_loose_fit]= awful_bad;

fewest_demerits= 0;
actual_looseness= 0;



if(par_shape_ptr==null){
if(hang_indent==0){
last_special_line= 0;
second_width= hsize;
second_indent= 0;
}else{
halfword used_hang_indent= swap_hang_indent(hang_indent);



last_special_line= abs(hang_after);
if(hang_after<0){
first_width= hsize-abs(used_hang_indent);
if(used_hang_indent>=0)
first_indent= used_hang_indent;
else
first_indent= 0;
second_width= hsize;
second_indent= 0;
}else{
first_width= hsize;
first_indent= 0;
second_width= hsize-abs(used_hang_indent);
if(used_hang_indent>=0)
second_indent= used_hang_indent;
else
second_indent= 0;
}
}
}else{
last_special_line= vinfo(par_shape_ptr+1)-1;
second_indent= varmem[(par_shape_ptr+2*(last_special_line+1))].cint;
second_width= varmem[(par_shape_ptr+2*(last_special_line+1)+1)].cint;
second_indent= swap_parshape_indent(second_indent,second_width);
}
if(looseness==0)
easy_line= last_special_line;
else
easy_line= max_halfword;

no_shrink_error_yet= true;
check_shrinkage(left_skip);
check_shrinkage(right_skip);
q= left_skip;
r= right_skip;
background[1]= width(q)+width(r);
background[2]= 0;
background[3]= 0;
background[4]= 0;
background[5]= 0;
background[6]= 0;
background[2+stretch_order(q)]= stretch(q);
background[2+stretch_order(r)]+= stretch(r);
background[7]= shrink(q)+shrink(r);
if(adjust_spacing> 1){
background[8]= 0;
background[9]= 0;
max_stretch_ratio= -1;
max_shrink_ratio= -1;
cur_font_step= -1;
set_prev_char_p(null);
}





do_last_line_fit= false;
if(last_line_fit> 0){
q= last_line_fill;
if((stretch(q)> 0)&&(stretch_order(q)> normal)){
if((background[3]==0)&&(background[4]==0)&&
(background[5]==0)&&(background[6]==0)){
do_last_line_fit= true;
fill_width[0]= 0;
fill_width[1]= 0;
fill_width[2]= 0;
fill_width[3]= 0;
fill_width[stretch_order(q)-1]= stretch(q);
}
}
}

if(dir_ptr!=null){
flush_node_list(dir_ptr);
dir_ptr= null;
}
#if 0
push_dir(dir_ptr,paragraph_dir);
#endif


threshold= pretolerance;
if(threshold>=0){
if(tracing_paragraphs> 0){
begin_diagnostic();
tprint_nl("@firstpass");
}
second_pass= false;
final_pass= false;
}else{
threshold= tolerance;
second_pass= true;
final_pass= (emergency_stretch<=0);
if(tracing_paragraphs> 0)
begin_diagnostic();
}
while(1){
halfword first_p;
halfword nest_stack[10];
int nest_index= 0;
if(threshold> inf_bad)
threshold= inf_bad;

q= new_node(unhyphenated_node,decent_fit);
vlink(q)= active;
break_node(q)= null;
line_number(q)= cur_list.pg_field+1;
total_demerits(q)= 0;
active_short(q)= 0;
active_glue(q)= 0;
vlink(active)= q;
do_all_eight(store_background);
passive= null;
printed_node= temp_head;
pass_number= 0;
font_in_short_display= null_font;

auto_breaking= true;
cur_p= vlink(temp_head);

if((cur_p!=null)&&(type(cur_p)==local_par_node)){
alink(cur_p)= temp_head;
internal_pen_inter= local_pen_inter(cur_p);
internal_pen_broken= local_pen_broken(cur_p);
init_internal_left_box= local_box_left(cur_p);
init_internal_left_box_width= local_box_left_width(cur_p);
internal_left_box= init_internal_left_box;
internal_left_box_width= init_internal_left_box_width;
internal_right_box= local_box_right(cur_p);
internal_right_box_width= local_box_right_width(cur_p);
}else{
internal_pen_inter= 0;
internal_pen_broken= 0;
init_internal_left_box= null;
init_internal_left_box_width= 0;
internal_left_box= init_internal_left_box;
internal_left_box_width= init_internal_left_box_width;
internal_right_box= null;
internal_right_box_width= 0;
}

set_prev_char_p(null);
first_p= cur_p;


while((cur_p!=null)&&(vlink(active)!=active)){


while(is_char_node(cur_p)){






active_width[1]+= pack_width(line_break_dir,dir_TRT,cur_p,true);
if((adjust_spacing> 1)&&check_expand_pars(font(cur_p))){
set_prev_char_p(cur_p);
add_char_stretch(active_width[8],cur_p);
add_char_shrink(active_width[9],cur_p);
}
cur_p= vlink(cur_p);
while(cur_p==null&&nest_index> 0){
cur_p= nest_stack[--nest_index];
}
}
if(cur_p==null){
normal_error("linebreak","invalid list tail, probably missing glue");
}






switch(type(cur_p)){
case hlist_node:
case vlist_node:
active_width[1]+= pack_width(line_break_dir,box_dir(cur_p),cur_p,false);
break;
case rule_node:
active_width[1]+= width(cur_p);
break;
case dir_node:
if(dir_dir(cur_p)>=0){
line_break_dir= dir_dir(cur_p);
push_dir_node(dir_ptr,cur_p);
}else{
pop_dir_node(dir_ptr);
if(dir_ptr!=null){
line_break_dir= dir_dir(dir_ptr);
}
}
break;
case local_par_node:
internal_pen_inter= local_pen_inter(cur_p);
internal_pen_broken= local_pen_broken(cur_p);
internal_left_box= local_box_left(cur_p);
internal_left_box_width= local_box_left_width(cur_p);
internal_right_box= local_box_right(cur_p);
internal_right_box_width= local_box_right_width(cur_p);
break;
case math_node:
auto_breaking= (subtype(cur_p)==after);

if(glue_is_zero(math_skip_par)){
kern_break();
break;
}else{

}

case glue_node:















if(auto_breaking){
halfword prev_p= alink(cur_p);
if(prev_p!=temp_head&&(
is_char_node(prev_p)
||precedes_break(prev_p)
||((type(prev_p)==kern_node)&&(
subtype(prev_p)==font_kern||subtype(prev_p)==accent_kern)
)
)){
ext_try_break(0,unhyphenated_node,line_break_dir,adjust_spacing,
par_shape_ptr,adj_demerits,
tracing_paragraphs,protrude_chars,
line_penalty,last_line_fit,
double_hyphen_demerits,
final_hyphen_demerits,first_p,cur_p);
}
}

check_shrinkage(cur_p);
active_width[1]+= width(cur_p);
active_width[2+stretch_order(cur_p)]+= stretch(cur_p);
active_width[7]+= shrink(cur_p);
break;
case kern_node:
if(subtype(cur_p)==explicit_kern||subtype(cur_p)==italic_kern){
kern_break();
}else{
active_width[1]+= width(cur_p);
if((adjust_spacing==2)&&(subtype(cur_p)==normal)){
add_kern_stretch(active_width[8],cur_p);
add_kern_shrink(active_width[9],cur_p);
}
}
break;
case disc_node:

if(subtype(cur_p)==select_disc)
break;







if(second_pass||subtype(cur_p)<=automatic_disc){








int actual_penalty= (int)disc_penalty(cur_p);
s= vlink_pre_break(cur_p);
do_one_seven_eight(reset_disc_width);
if(s==null){
ext_try_break(actual_penalty,hyphenated_node,
line_break_dir,adjust_spacing,
par_shape_ptr,adj_demerits,
tracing_paragraphs,protrude_chars,
line_penalty,last_line_fit,
double_hyphen_demerits,
final_hyphen_demerits,first_p,cur_p);
}else{
add_to_widths(s,line_break_dir,adjust_spacing,disc_width);
do_one_seven_eight(add_disc_width_to_active_width);
ext_try_break(actual_penalty,hyphenated_node,
line_break_dir,adjust_spacing,
par_shape_ptr,adj_demerits,
tracing_paragraphs,protrude_chars,
line_penalty,last_line_fit,
double_hyphen_demerits,
final_hyphen_demerits,first_p,cur_p);
if(subtype(cur_p)==init_disc){






s= vlink_pre_break(vlink(cur_p));
add_to_widths(s,line_break_dir,adjust_spacing,disc_width);
ext_try_break(actual_penalty,hyphenated_node,
line_break_dir,adjust_spacing,
par_shape_ptr,adj_demerits,
tracing_paragraphs,
protrude_chars,line_penalty,
last_line_fit,double_hyphen_demerits,
final_hyphen_demerits,first_p,
vlink(cur_p));
#if 0


do_one_seven_eight(sub_disc_width_from_active_width);
do_one_seven_eight(reset_disc_width);

s= vlink_no_break(vlink(cur_p));
add_to_widths(s,line_break_dir,adjust_spacing,disc_width);
ext_try_break(actual_penalty,hyphenated_node,
line_break_dir,adjust_spacing,
par_shape_ptr,adj_demerits,
tracing_paragraphs,
protrude_chars,line_penalty,
last_line_fit,double_hyphen_demerits,
final_hyphen_demerits,first_p,
vlink(cur_p));
#endif
}
do_one_seven_eight(sub_disc_width_from_active_width);
}
}
s= vlink_no_break(cur_p);
add_to_widths(s,line_break_dir,adjust_spacing,active_width);
break;
case penalty_node:
ext_try_break(penalty(cur_p),unhyphenated_node,line_break_dir,
adjust_spacing,par_shape_ptr,adj_demerits,
tracing_paragraphs,protrude_chars,
line_penalty,last_line_fit,
double_hyphen_demerits,final_hyphen_demerits,
first_p,cur_p);
break;
case boundary_node:
case whatsit_node:

case mark_node:
case ins_node:
case adjust_node:
break;
case glue_spec_node:
normal_warning("parbuilder","found a glue_spec in a paragraph");
break;
default:
formatted_error("parbuilder","weird node %d in paragraph",type(cur_p));
}
cur_p= vlink(cur_p);
while(cur_p==null&&nest_index> 0){
cur_p= nest_stack[--nest_index];
}
}
if(cur_p==null){














ext_try_break(eject_penalty,hyphenated_node,line_break_dir,
adjust_spacing,par_shape_ptr,adj_demerits,
tracing_paragraphs,protrude_chars,line_penalty,
last_line_fit,double_hyphen_demerits,
final_hyphen_demerits,first_p,cur_p);
if(vlink(active)!=active){

r= vlink(active);
fewest_demerits= awful_bad;
do{
if(type(r)!=delta_node){
if(total_demerits(r)<fewest_demerits){
fewest_demerits= total_demerits(r);
best_bet= r;
}
}
r= vlink(r);
}while(r!=active);
best_line= line_number(best_bet);



if(looseness==0)
goto DONE;








r= vlink(active);
actual_looseness= 0;
do{
if(type(r)!=delta_node){
line_diff= line_number(r)-best_line;
if(((line_diff<actual_looseness)
&&(looseness<=line_diff))
||((line_diff> actual_looseness)
&&(looseness>=line_diff))){
best_bet= r;
actual_looseness= line_diff;
fewest_demerits= total_demerits(r);
}else if((line_diff==actual_looseness)&&
(total_demerits(r)<fewest_demerits)){
best_bet= r;
fewest_demerits= total_demerits(r);
}
}
r= vlink(r);
}while(r!=active);
best_line= line_number(best_bet);



if((actual_looseness==looseness)||final_pass)
goto DONE;
}
}

clean_up_the_memory();

if(!second_pass){
if(tracing_paragraphs> 0)
tprint_nl("@secondpass");
threshold= tolerance;
second_pass= true;
final_pass= (emergency_stretch<=0);
}else{

if(tracing_paragraphs> 0)
tprint_nl("@emergencypass");
background[2]+= emergency_stretch;
final_pass= true;
}
}

DONE:
if(tracing_paragraphs> 0){
end_diagnostic(true);
normalize_selector();
}
if(do_last_line_fit){




if(active_short(best_bet)==0){
do_last_line_fit= false;
}else{
width(last_line_fill)+= (active_short(best_bet)-active_glue(best_bet));
stretch(last_line_fill)= 0;
}
}









flush_node_list(dir_ptr);
dir_ptr= null;
ext_post_line_break(paragraph_dir,
right_skip,
left_skip,
protrude_chars,
par_shape_ptr,
adjust_spacing,
inter_line_penalties_par_ptr,
inter_line_penalty,
club_penalty,
club_penalties_ptr,
widow_penalties_ptr,
widow_penalty,
broken_penalty,
final_par_glue,
best_bet,
last_special_line,
second_width,
second_indent,first_width,first_indent,best_line);




clean_up_the_memory();
}

/*:27*//*28:*/
#line 2154 "./luatexdir/tex/linebreak.w"

void get_linebreak_info(int*f,int*a)
{
*f= fewest_demerits;
*a= actual_looseness;
}/*:28*/
