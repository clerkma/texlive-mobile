/*1:*/
#line 20 "./luatexdir/tex/buildpage.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 24 "./luatexdir/tex/buildpage.w"

#define box(A) eqtb[box_base+(A)].hh.rh
#define count(A) eqtb[count_base+(A)].hh.rh
#undef skip
#define skip(A) eqtb[skip_base+(A)].hh.rh
#define dimen(A) eqtb[scaled_base+(A)].hh.rh

#define vbadness int_par(vbadness_code)
#define max_dead_cycles int_par(max_dead_cycles_code)
#define output_box int_par(output_box_code)
#define holding_inserts int_par(holding_inserts_code)

#define vsize dimen_par(vsize_code)
#define vfuzz dimen_par(vfuzz_code)
#define max_depth dimen_par(max_depth_code)

#define output_routine equiv(output_routine_loc)
#define split_top_skip glue_par(split_top_skip_code)

#define prev_depth cur_list.prev_depth_field
#define mode_line cur_list.ml_field
#define mode cur_list.mode_field
#define tail cur_list.tail_field
#define head cur_list.head_field

/*:2*//*3:*/
#line 88 "./luatexdir/tex/buildpage.w"

halfword page_tail;
int page_contents;
scaled page_max_depth;
halfword best_page_break;
int least_page_cost;
scaled best_size;

/*:3*//*5:*/
#line 152 "./luatexdir/tex/buildpage.w"

void initialize_buildpage(void)
{
subtype(page_ins_head)= 65535;
type(page_ins_head)= split_up_node;
vlink(page_ins_head)= page_ins_head;

type(page_head)= glue_node;
subtype(page_head)= normal;
}


/*:5*//*6:*/
#line 185 "./luatexdir/tex/buildpage.w"

scaled page_so_far[8];
halfword last_glue;
int last_penalty;
scaled last_kern;
int last_node_type;
int insert_penalties;

#define print_plus(A,B) do { \
    if (page_so_far[(A)]!=0) { \
        tprint(" plus "); \
        print_scaled(page_so_far[(A)]); \
        tprint((B)); \
    } \
} while (0)

void print_totals(void)
{
print_scaled(page_total);
print_plus(2,"");
print_plus(3,"fil");
print_plus(4,"fill");
print_plus(5,"filll");
if(page_shrink!=0){
tprint(" minus ");
print_scaled(page_shrink);
}
}

/*:6*//*7:*/
#line 217 "./luatexdir/tex/buildpage.w"

#define do_all_six(A) A(1);A(2);A(3);A(4);A(5);A(6);A(7)
#define set_page_so_far_zero(A) page_so_far[(A)]= 0

void freeze_page_specs(int s)
{
page_contents= s;
page_goal= vsize;
page_max_depth= max_depth;
page_depth= 0;
do_all_six(set_page_so_far_zero);
least_page_cost= awful_bad;
if(int_par(tracing_pages_code)> 0){
begin_diagnostic();
tprint_nl("%% goal height=");
print_scaled(page_goal);
tprint(", max depth=");
print_scaled(page_max_depth);
end_diagnostic(false);
}
}

/*:7*//*8:*/
#line 242 "./luatexdir/tex/buildpage.w"

boolean output_active;

/*:8*//*9:*/
#line 249 "./luatexdir/tex/buildpage.w"

void start_new_page(void)
{
page_contents= empty;
page_tail= page_head;
vlink(page_head)= null;
last_glue= max_halfword;
last_penalty= 0;
last_kern= 0;
last_node_type= -1;
page_depth= 0;
page_max_depth= 0;
}

/*:9*//*10:*/
#line 268 "./luatexdir/tex/buildpage.w"

static void box_error(int n)
{
error();
begin_diagnostic();
tprint_nl("The following box has been deleted:");
show_box(box(n));
end_diagnostic(true);
flush_node_list(box(n));
box(n)= null;
}

/*:10*//*11:*/
#line 283 "./luatexdir/tex/buildpage.w"

static void ensure_vbox(int n)
{
halfword p;
p= box(n);
if(p!=null&&type(p)==hlist_node){
print_err("Insertions can only be added to a vbox");
help3("Tut tut: You're trying to \\insert into a",
"\\box register that now contains an \\hbox.",
"Proceed, and I'll discard its present contents.");
box_error(n);
}
}

/*:11*//*12:*/
#line 303 "./luatexdir/tex/buildpage.w"

void build_page(void)
{
halfword p;
halfword q,r;
int b,c;
int pi= 0;
int n;
scaled delta,h,w;
if((vlink(contrib_head)==null)||output_active)
return;
do{
CONTINUE:
p= vlink(contrib_head);

if(last_glue!=max_halfword){
delete_glue_ref(last_glue);
last_glue= max_halfword;
}
last_penalty= 0;
last_kern= 0;
last_node_type= type(p)+1;
if(type(p)==glue_node){
last_glue= glue_ptr(p);
add_glue_ref(last_glue);
}else if(type(p)==penalty_node){
last_penalty= penalty(p);
}else if(type(p)==kern_node){
last_kern= width(p);
}



















switch(type(p)){
case hlist_node:
case vlist_node:
case rule_node:
if(page_contents<box_there){


if(page_contents==empty)
freeze_page_specs(box_there);
else
page_contents= box_there;
q= new_skip_param(top_skip_code);
if((type(p)==hlist_node)&&is_mirrored(body_direction)){
if(width(temp_ptr)> depth(p))
width(temp_ptr)= width(temp_ptr)-depth(p);
else
width(temp_ptr)= 0;
}else{
if(width(temp_ptr)> height(p))
width(temp_ptr)= width(temp_ptr)-height(p);
else
width(temp_ptr)= 0;
}
couple_nodes(q,p);
couple_nodes(contrib_head,q);
goto CONTINUE;

}else{


if((type(p)==hlist_node)&&is_mirrored(body_direction)){
page_total= page_total+page_depth+depth(p);
page_depth= height(p);
}else{
page_total= page_total+page_depth+height(p);
page_depth= depth(p);
}
goto CONTRIBUTE;

}
break;
case boundary_node:
case whatsit_node:
goto CONTRIBUTE;
break;
case glue_node:
if(page_contents<box_there)
goto DONE1;
else if(precedes_break(page_tail))
pi= 0;
else
goto UPDATE_HEIGHTS;
break;
case kern_node:
if(page_contents<box_there)
goto DONE1;
else if(vlink(p)==null)
goto EXIT;
else if(type(vlink(p))==glue_node)
pi= 0;
else
goto UPDATE_HEIGHTS;
break;
case penalty_node:
if(page_contents<box_there)
goto DONE1;
else
pi= penalty(p);
break;
case mark_node:
goto CONTRIBUTE;
break;
case ins_node:

if(page_contents==empty)
freeze_page_specs(inserts_only);
n= subtype(p);
r= page_ins_head;
while(n>=subtype(vlink(r)))
r= vlink(r);
if(subtype(r)!=n){









q= new_node(inserting_node,n);
try_couple_nodes(q,vlink(r));
couple_nodes(r,q);
r= q;
ensure_vbox(n);
if(box(n)==null)
height(r)= 0;
else
height(r)= height(box(n))+depth(box(n));
best_ins_ptr(r)= null;
q= skip(n);
if(count(n)==1000)
h= height(r);
else
h= x_over_n(height(r),1000)*count(n);
page_goal= page_goal-h-width(q);
if(stretch_order(q)> 1)
page_so_far[1+stretch_order(q)]= 
page_so_far[1+stretch_order(q)]+stretch(q);
else
page_so_far[2+stretch_order(q)]= 
page_so_far[2+stretch_order(q)]+stretch(q);
page_shrink= page_shrink+shrink(q);
if((shrink_order(q)!=normal)&&(shrink(q)!=0)){
print_err("Infinite glue shrinkage inserted from \\skip");
print_int(n);
help3
("The correction glue for page breaking with insertions",
"must have finite shrinkability. But you may proceed,",
"since the offensive shrinkability has been made finite.");
error();
}

}
if(type(r)==split_up_node){
insert_penalties= insert_penalties+float_cost(p);
}else{
last_ins_ptr(r)= p;
delta= page_goal-page_total-page_depth+page_shrink;

if(count(n)==1000)
h= height(p);
else
h= x_over_n(height(p),1000)*count(n);
if(((h<=0)||(h<=delta))
&&(height(p)+height(r)<=dimen(n))){
page_goal= page_goal-h;
height(r)= height(r)+height(p);
}else{












if(count(n)<=0){
w= max_dimen;
}else{
w= page_goal-page_total-page_depth;
if(count(n)!=1000)
w= x_over_n(w,count(n))*1000;
}
if(w> dimen(n)-height(r))
w= dimen(n)-height(r);
q= vert_break(ins_ptr(p),w,depth(p));
height(r)= height(r)+best_height_plus_depth;
if(int_par(tracing_pages_code)> 0){

begin_diagnostic();
tprint_nl("% split");
print_int(n);
tprint(" to ");
print_scaled(w);
print_char(',');
print_scaled(best_height_plus_depth);
tprint(" p=");
if(q==null)
print_int(eject_penalty);
else if(type(q)==penalty_node)
print_int(penalty(q));
else
print_char('0');
end_diagnostic(false);

}
if(count(n)!=1000)
best_height_plus_depth= 
x_over_n(best_height_plus_depth,1000)*count(n);
page_goal= page_goal-best_height_plus_depth;
type(r)= split_up_node;
broken_ptr(r)= q;
broken_ins(r)= p;
if(q==null)
insert_penalties= insert_penalties+eject_penalty;
else if(type(q)==penalty_node)
insert_penalties= insert_penalties+penalty(q);
}
}
goto CONTRIBUTE;

break;
default:
fprintf(stderr,"type(p)=%d\n",type(p));
confusion("page");
break;
}





if(pi<inf_penalty){


if(page_total<page_goal){
if((page_so_far[3]!=0)||(page_so_far[4]!=0)||
(page_so_far[5]!=0))
b= 0;
else
b= badness(page_goal-page_total,page_so_far[2]);
}else if(page_total-page_goal> page_shrink){
b= awful_bad;
}else{
b= badness(page_total-page_goal,page_shrink);
}

if(b<awful_bad){
if(pi<=eject_penalty)
c= pi;
else if(b<inf_bad)
c= b+pi+insert_penalties;
else
c= deplorable;
}else{
c= b;
}
if(insert_penalties>=10000)
c= awful_bad;
if(int_par(tracing_pages_code)> 0){

begin_diagnostic();
tprint_nl("%");
tprint(" t=");
print_totals();
tprint(" g=");
print_scaled(page_goal);
tprint(" b=");
if(b==awful_bad)
print_char('*');
else
print_int(b);
tprint(" p=");
print_int(pi);
tprint(" c=");
if(c==awful_bad)
print_char('*');
else
print_int(c);
if(c<=least_page_cost)
print_char('#');
end_diagnostic(false);

}
if(c<=least_page_cost){
best_page_break= p;
best_size= page_goal;
least_page_cost= c;
r= vlink(page_ins_head);
while(r!=page_ins_head){
best_ins_ptr(r)= last_ins_ptr(r);
r= vlink(r);
}
}
if((c==awful_bad)||(pi<=eject_penalty)){
fire_up(p);
if(output_active)
goto EXIT;
goto DONE;
}
}

if((type(p)<glue_node)||(type(p)> kern_node))
goto CONTRIBUTE;

UPDATE_HEIGHTS:



if(type(p)==kern_node){
q= p;
}else{
q= glue_ptr(p);
if(stretch_order(q)> 1)
page_so_far[1+stretch_order(q)]= 
page_so_far[1+stretch_order(q)]+stretch(q);
else
page_so_far[2+stretch_order(q)]= 
page_so_far[2+stretch_order(q)]+stretch(q);
page_shrink= page_shrink+shrink(q);
if((shrink_order(q)!=normal)&&(shrink(q)!=0)){
print_err("Infinite glue shrinkage found on current page");
help4("The page about to be output contains some infinitely",
"shrinkable glue, e.g., `\\vss' or `\\vskip 0pt minus 1fil'.",
"Such glue doesn't belong there; but you can safely proceed,",
"since the offensive shrinkability has been made finite.");
error();
r= new_spec(q);
shrink_order(r)= normal;
delete_glue_ref(q);
glue_ptr(p)= r;
q= r;
}
}
page_total= page_total+page_depth+width(q);
page_depth= 0;

CONTRIBUTE:


if(page_depth> page_max_depth){
page_total= page_total+page_depth-page_max_depth;
page_depth= page_max_depth;
}


couple_nodes(page_tail,p);
page_tail= p;
try_couple_nodes(contrib_head,vlink(p));
vlink(p)= null;
goto DONE;
DONE1:

try_couple_nodes(contrib_head,vlink(p));
vlink(p)= null;
if(int_par(saving_vdiscards_code)> 0){
if(page_disc==null){
page_disc= p;
}else{
couple_nodes(tail_page_disc,p);
}
tail_page_disc= p;
}else{
flush_node_list(p);
}
DONE:
;
}while(vlink(contrib_head)!=null);

contrib_tail= contrib_head;
EXIT:
;
}

/*:12*//*13:*/
#line 716 "./luatexdir/tex/buildpage.w"

void fire_up(halfword c)
{
halfword p,q,r,s;
halfword prev_p;
int n;
boolean wait;
int save_vbadness;
scaled save_vfuzz;
halfword save_split_top_skip;
halfword i;


if(type(best_page_break)==penalty_node){
geq_word_define(int_base+output_penalty_code,
penalty(best_page_break));
penalty(best_page_break)= inf_penalty;
}else{
geq_word_define(int_base+output_penalty_code,inf_penalty);
}

for(i= 0;i<=biggest_used_mark;i++){
if(bot_mark(i)!=null){
if(top_mark(i)!=null)
delete_token_ref(top_mark(i));
set_top_mark(i,bot_mark(i));
add_token_ref(top_mark(i));
delete_first_mark(i);
}
}









if(c==best_page_break)
best_page_break= null;

if(box(output_box)!=null){
print_err("\\box");
print_int(output_box);
tprint(" is not void");
help2("You shouldn't use \\box\\outputbox except in \\output routines.",
"Proceed, and I'll discard its present contents.");
box_error(output_box);
}

insert_penalties= 0;
save_split_top_skip= split_top_skip;
if(holding_inserts<=0){







r= vlink(page_ins_head);
while(r!=page_ins_head){
if(best_ins_ptr(r)!=null){
n= subtype(r);
ensure_vbox(n);
if(box(n)==null)
box(n)= new_null_box();
p= box(n)+list_offset;
while(vlink(p)!=null)
p= vlink(p);
last_ins_ptr(r)= p;
}
r= vlink(r);
}

}
q= hold_head;
vlink(q)= null;
prev_p= page_head;
p= vlink(prev_p);
while(p!=best_page_break){
if(type(p)==ins_node){
if(holding_inserts<=0){







r= vlink(page_ins_head);
while(subtype(r)!=subtype(p))
r= vlink(r);
if(best_ins_ptr(r)==null){
wait= true;
}else{
wait= false;
s= last_ins_ptr(r);
vlink(s)= ins_ptr(p);
if(best_ins_ptr(r)==p){



if(type(r)==split_up_node){
if((broken_ins(r)==p)&&(broken_ptr(r)!=null)){
while(vlink(s)!=broken_ptr(r))
s= vlink(s);
vlink(s)= null;
split_top_skip= split_top_ptr(p);
ins_ptr(p)= 
prune_page_top(broken_ptr(r),false);
if(ins_ptr(p)!=null){
temp_ptr= 
vpack(ins_ptr(p),0,additional,-1);
height(p)= 
height(temp_ptr)+depth(temp_ptr);
list_ptr(temp_ptr)= null;
flush_node(temp_ptr);
wait= true;
}
}
}
best_ins_ptr(r)= null;
n= subtype(r);
temp_ptr= list_ptr(box(n));
list_ptr(box(n))= null;
flush_node(box(n));
box(n)= vpack(temp_ptr,0,additional,body_direction);

}else{
while(vlink(s)!=null)
s= vlink(s);
last_ins_ptr(r)= s;
}
}


try_couple_nodes(prev_p,vlink(p));
vlink(p)= null;
if(wait){
couple_nodes(q,p);
q= p;
incr(insert_penalties);
}else{
ins_ptr(p)= null;
flush_node(p);
}
p= prev_p;

}
}else if(type(p)==mark_node){

if(first_mark(mark_class(p))==null){
set_first_mark(mark_class(p),mark_ptr(p));
add_token_ref(first_mark(mark_class(p)));
}
if(bot_mark(mark_class(p))!=null)
delete_token_ref(bot_mark(mark_class(p)));
set_bot_mark(mark_class(p),mark_ptr(p));
add_token_ref(bot_mark(mark_class(p)));

}
prev_p= p;
p= vlink(prev_p);
}
split_top_skip= save_split_top_skip;













if(p!=null){
if(vlink(contrib_head)==null){
contrib_tail= page_tail;
}
couple_nodes(page_tail,vlink(contrib_head));
couple_nodes(contrib_head,p);
vlink(prev_p)= null;
}
save_vbadness= vbadness;
vbadness= inf_bad;
save_vfuzz= vfuzz;
vfuzz= max_dimen;
box(output_box)= filtered_vpackage(vlink(page_head),
best_size,exactly,page_max_depth,output_group,body_direction,0);
vbadness= save_vbadness;
vfuzz= save_vfuzz;
if(last_glue!=max_halfword)
delete_glue_ref(last_glue);

start_new_page();
if(q!=hold_head){
vlink(page_head)= vlink(hold_head);
page_tail= q;
}


r= vlink(page_ins_head);
while(r!=page_ins_head){
q= vlink(r);
flush_node(r);
r= q;
}
vlink(page_ins_head)= page_ins_head;

for(i= 0;i<=biggest_used_mark;i++){
if((top_mark(i)!=null)&&(first_mark(i)==null)){
set_first_mark(i,top_mark(i));
add_token_ref(top_mark(i));
}
}
if(output_routine!=null){
if(dead_cycles>=max_dead_cycles){

print_err("Output loop---");
print_int(dead_cycles);
tprint(" consecutive dead cycles");
help3("I've concluded that your \\output is awry; it never does a",
"\\shipout, so I'm shipping \\box\\outputbox out myself. Next time",
"increase \\maxdeadcycles if you want me to be more patient!");
error();

}else{

output_active= true;
incr(dead_cycles);
push_nest();
mode= -vmode;
prev_depth= ignore_depth;
mode_line= -line;
begin_token_list(output_routine,output_text);
new_save_level(output_group);
normal_paragraph();
scan_left_brace();
return;

}
}




if(vlink(page_head)!=null){
if(vlink(contrib_head)==null){
contrib_tail= page_tail;
}else{
vlink(page_tail)= vlink(contrib_head);
}
vlink(contrib_head)= vlink(page_head);
vlink(page_head)= null;
page_tail= page_head;
}
flush_node_list(page_disc);
page_disc= null;
ship_out(static_pdf,box(output_box),SHIPPING_PAGE);
box(output_box)= null;
}

/*:13*//*14:*/
#line 986 "./luatexdir/tex/buildpage.w"

void resume_after_output(void)
{
if((iloc!=null)
||((token_type!=output_text)&&(token_type!=backed_up))){

print_err("Unbalanced output routine");
help2("Your sneaky output routine has problematic {'s and/or }'s.",
"I can't handle that very well; good luck.");
error();
do{
get_token();
}while(iloc!=null);


}
end_token_list();
end_graf(bottom_level);
unsave();
output_active= false;
insert_penalties= 0;

if(box(output_box)!=null){
print_err("Output routine didn't use all of \\box");
print_int(output_box);
help3("Your \\output commands should empty \\box\\outputbox,",
"e.g., by saying `\\shipout\\box\\outputbox'.",
"Proceed; I'll discard its present contents.");
box_error(output_box);
}

if(tail!=head){
try_couple_nodes(page_tail,vlink(head));
page_tail= tail;
}
if(vlink(page_head)!=null){
if(vlink(contrib_head)==null)
contrib_tail= page_tail;
try_couple_nodes(page_tail,vlink(contrib_head));
try_couple_nodes(contrib_head,vlink(page_head));
vlink(page_head)= null;
page_tail= page_head;
}
flush_node_list(page_disc);
page_disc= null;
pop_nest();
lua_node_filter_s(buildpage_filter_callback,lua_key_index(after_output));
build_page();
}/*:14*/
