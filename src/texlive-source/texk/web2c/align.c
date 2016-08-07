/*1:*/
#line 22 "./luatexdir/tex/align.w"



#include "ptexlib.h"

/*:1*//*2:*/
#line 27 "./luatexdir/tex/align.w"

void fin_align(void);
void init_row(void);
void init_col(void);

#define noDEBUG

#define end_template_token (cs_token_flag+frozen_end_template)

#define prev_depth      cur_list.prev_depth_field
#define space_factor    cur_list.space_factor_field
#define incompleat_noad cur_list.incompleat_noad_field

#define every_cr          equiv(every_cr_loc)
#define display_indent    dimen_par(display_indent_code)
#define max_depth         dimen_par(max_depth_code)
#define overfull_rule     dimen_par(overfull_rule_code)

/*:2*//*4:*/
#line 179 "./luatexdir/tex/align.w"

#define u_part(A) vlink((A)+depth_offset)       
#define v_part(A) vinfo((A)+depth_offset)       
#define span_ptr(A) vinfo((A)+1)        
#define extra_info(A) vinfo((A)+list_offset)    

/*:4*//*5:*/
#line 203 "./luatexdir/tex/align.w"

#define preamble vlink(align_head)      

pointer cur_align= null;
pointer cur_span= null;
pointer cur_loop= null;
pointer align_ptr= null;
pointer cur_head= null,cur_tail= null;
pointer cur_pre_head= null,cur_pre_tail= null;



/*:5*//*6:*/
#line 225 "./luatexdir/tex/align.w"

static void push_alignment(void)
{
pointer p;
p= new_node(align_stack_node,0);
vinfo(p+1)= align_ptr;
vlink(p+1)= cur_align;
vinfo(p+2)= preamble;
vlink(p+2)= cur_span;
vinfo(p+3)= cur_loop;
vlink(p+3)= align_state;
vinfo(p+4)= cur_head;
vlink(p+4)= cur_tail;
vinfo(p+5)= cur_pre_head;
vlink(p+5)= cur_pre_tail;
align_ptr= p;
cur_head= new_node(temp_node,0);
cur_pre_head= new_node(temp_node,0);
}

static void pop_alignment(void)
{
pointer p;
flush_node(cur_head);
flush_node(cur_pre_head);
p= align_ptr;
cur_pre_tail= vlink(p+5);
cur_pre_head= vinfo(p+5);
cur_tail= vlink(p+4);
cur_head= vinfo(p+4);
align_state= vlink(p+3);
cur_loop= vinfo(p+3);
cur_span= vlink(p+2);
preamble= vinfo(p+2);
cur_align= vlink(p+1);
align_ptr= vinfo(p+1);
flush_node(p);
}


/*:6*//*8:*/
#line 286 "./luatexdir/tex/align.w"

static void get_preamble_token(void)
{
RESTART:
get_token();
while((cur_chr==span_code)&&(cur_cmd==tab_mark_cmd)){
get_token();
if(cur_cmd> max_command_cmd){
expand();
get_token();
}
}
if(cur_cmd==endv_cmd)
fatal_error("(interwoven alignment preambles are not allowed)");
if((cur_cmd==assign_glue_cmd)
&&(cur_chr==glue_base+tab_skip_code)){
scan_optional_equals();
scan_glue(glue_val_level);
if(int_par(global_defs_code)> 0)
geq_define(glue_base+tab_skip_code,glue_ref_cmd,cur_val);
else
eq_define(glue_base+tab_skip_code,glue_ref_cmd,cur_val);
goto RESTART;
}
}



/*:8*//*9:*/
#line 320 "./luatexdir/tex/align.w"

void init_align(void)
{

pointer save_cs_ptr;
pointer p,r;
save_cs_ptr= cur_cs;
push_alignment();
align_state= -1000000;




if((cur_list.mode_field==mmode)
&&((cur_list.tail_field!=cur_list.head_field)
||(incompleat_noad!=null))){
const char*hlp[]= 
{"Displays can use special alignments (like \\eqalignno)",
"only if nothing but the alignment itself is between $$'s.",
"So I've deleted the formulas that preceded this alignment.",
NULL
};
tex_error("Improper \\halign inside $$'s",hlp);
flush_math();
}
push_nest();




if(cur_list.mode_field==mmode){
cur_list.mode_field= -vmode;
prev_depth= nest[nest_ptr-2].prev_depth_field;
}else if(cur_list.mode_field> 0){
cur_list.mode_field= -(cur_list.mode_field);
}
scan_spec(align_group);

preamble= null;
cur_align= align_head;
cur_loop= null;
scanner_status= aligning;
warning_index= save_cs_ptr;
align_state= -1000000;

while(true){

r= new_param_glue(tab_skip_code);
vlink(cur_align)= r;
cur_align= vlink(cur_align);

if(cur_cmd==car_ret_cmd)
break;





p= hold_token_head;
token_link(p)= null;
while(1){
get_preamble_token();
if(cur_cmd==mac_param_cmd)
break;
if((cur_cmd<=car_ret_cmd)&&(cur_cmd>=tab_mark_cmd)
&&(align_state==-1000000)){
if((p==hold_token_head)&&(cur_loop==null)
&&(cur_cmd==tab_mark_cmd)){
cur_loop= cur_align;
}else{
const char*hlp[]= 
{"There should be exactly one # between &'s, when an",
"\\halign or \\valign is being set up. In this case you had",
"none, so I've put one in; maybe that will work.",
NULL
};
back_input();
tex_error("Missing # inserted in alignment preamble",hlp);
break;
}
}else if((cur_cmd!=spacer_cmd)||(p!=hold_token_head)){
r= get_avail();
token_link(p)= r;
p= token_link(p);
token_info(p)= cur_tok;
}
}
r= new_node(align_record_node,0);
vlink(cur_align)= r;
cur_align= vlink(cur_align);
span_ptr(cur_align)= end_span;
width(cur_align)= null_flag;
u_part(cur_align)= token_link(hold_token_head);


p= hold_token_head;
token_link(p)= null;
while(1){
CONTINUE:
get_preamble_token();
if((cur_cmd<=car_ret_cmd)&&(cur_cmd>=tab_mark_cmd)
&&(align_state==-1000000))
break;
if(cur_cmd==mac_param_cmd){
const char*hlp[]= 
{"There should be exactly one # between &'s, when an",
"\\halign or \\valign is being set up. In this case you had",
"more than one, so I'm ignoring all but the first.",
NULL
};
tex_error("Only one # is allowed per tab",hlp);
goto CONTINUE;
}
r= get_avail();
token_link(p)= r;
p= token_link(p);
token_info(p)= cur_tok;
}
r= get_avail();
token_link(p)= r;
p= token_link(p);
token_info(p)= end_template_token;

v_part(cur_align)= token_link(hold_token_head);
}
scanner_status= normal;

new_save_level(align_group);
if(every_cr!=null)
begin_token_list(every_cr,every_cr_text);
align_peek();
}


/*:9*//*10:*/
#line 464 "./luatexdir/tex/align.w"

void align_peek(void)
{
RESTART:
align_state= 1000000;
do{
get_x_or_protected();
}while(cur_cmd==spacer_cmd);
if(cur_cmd==no_align_cmd){
scan_left_brace();
new_save_level(no_align_group);
if(cur_list.mode_field==-vmode)
normal_paragraph();
}else if(cur_cmd==right_brace_cmd){
fin_align();
}else if((cur_cmd==car_ret_cmd)&&(cur_chr==cr_cr_code)){
goto RESTART;
}else{
init_row();
init_col();
}
}


/*:10*//*11:*/
#line 492 "./luatexdir/tex/align.w"

static void init_span(pointer p)
{
push_nest();
if(cur_list.mode_field==-hmode){
space_factor= 1000;
}else{
prev_depth= ignore_depth;
normal_paragraph();
}
cur_span= p;
}


/*:11*//*12:*/
#line 512 "./luatexdir/tex/align.w"

void init_row(void)
{
push_nest();
cur_list.mode_field= (-hmode-vmode)-cur_list.mode_field;
if(cur_list.mode_field==-hmode)
space_factor= 0;
else
prev_depth= 0;
tail_append(new_glue(glue_ptr(preamble)));
subtype(cur_list.tail_field)= tab_skip_code+1;
cur_align= vlink(preamble);
cur_tail= cur_head;
cur_pre_tail= cur_pre_head;
init_span(cur_align);
}


/*:12*//*13:*/
#line 537 "./luatexdir/tex/align.w"

void init_col(void)
{
extra_info(cur_align)= cur_cmd;
if(cur_cmd==omit_cmd)
align_state= 0;
else{
back_input();
begin_token_list(u_part(cur_align),u_template);
}
}


/*:13*//*14:*/
#line 559 "./luatexdir/tex/align.w"

void insert_vj_template(void)
{
if((scanner_status==aligning)||(cur_align==null))
fatal_error("(interwoven alignment preambles are not allowed)");
cur_cmd= extra_info(cur_align);
extra_info(cur_align)= cur_chr;
if(cur_cmd==omit_cmd)
begin_token_list(omit_template,v_template);
else
begin_token_list(v_part(cur_align),v_template);
align_state= 1000000;
}


#define determine_stretch_order() do {              \
        if (total_stretch[filll]!=0)  o= filll;      \
        else if (total_stretch[fill]!=0)  o= fill;   \
        else if (total_stretch[fil]!=0)  o= fil;     \
        else if (total_stretch[sfi]!=0)  o= sfi;     \
        else o= normal;                              \
    } while (0)



#define determine_shrink_order() do {              \
        if (total_shrink[filll]!=0)  o= filll;      \
        else if (total_shrink[fill]!=0)  o= fill;   \
        else if (total_shrink[fil]!=0)  o= fil;     \
        else if (total_shrink[sfi]!=0)  o= sfi;     \
        else o= normal;                              \
    } while (0)



/*:14*//*15:*/
#line 599 "./luatexdir/tex/align.w"

boolean fin_col(void)
{
pointer p;
pointer q,r;
pointer s;
pointer u;
scaled w;
unsigned char o;
halfword n;
if(cur_align==null)
confusion("endv");
q= vlink(cur_align);
if(q==null)
confusion("endv");
if(align_state<500000)
fatal_error("(interwoven alignment preambles are not allowed)");
p= vlink(q);

if((p==null)&&(extra_info(cur_align)<cr_code)){
if(cur_loop!=null){

r= new_node(align_record_node,0);
vlink(q)= r;
p= vlink(q);
span_ptr(p)= end_span;
width(p)= null_flag;
cur_loop= vlink(cur_loop);


q= hold_token_head;
r= u_part(cur_loop);
while(r!=null){
s= get_avail();
token_link(q)= s;
q= token_link(q);
token_info(q)= token_info(r);
r= token_link(r);
}
token_link(q)= null;
u_part(p)= token_link(hold_token_head);
q= hold_token_head;
r= v_part(cur_loop);
while(r!=null){
s= get_avail();
token_link(q)= s;
q= token_link(q);
token_info(q)= token_info(r);
r= token_link(r);
}
token_link(q)= null;
v_part(p)= token_link(hold_token_head);

cur_loop= vlink(cur_loop);
r= new_glue(glue_ptr(cur_loop));
vlink(p)= r;
}else{
const char*hlp[]= 
{"You have given more \\span or & marks than there were",
"in the preamble to the \\halign or \\valign now in progress.",
"So I'll assume that you meant to type \\cr instead.",
NULL
};
extra_info(cur_align)= cr_code;
tex_error("Extra alignment tab has been changed to \\cr",hlp);
}
}
if(extra_info(cur_align)!=span_code){
unsave();
new_save_level(align_group);

if(cur_list.mode_field==-hmode){
adjust_tail= cur_tail;
pre_adjust_tail= cur_pre_tail;
u= filtered_hpack(cur_list.head_field,cur_list.tail_field,0,
additional,align_set_group,-1,0);
w= width(u);
cur_tail= adjust_tail;
adjust_tail= null;
cur_pre_tail= pre_adjust_tail;
pre_adjust_tail= null;
}else{
u= filtered_vpackage(vlink(cur_list.head_field),
0,additional,0,align_set_group,-1,0);
w= height(u);
}
n= min_quarterword;
if(cur_span!=cur_align){

q= cur_span;
do{
incr(n);
q= vlink(vlink(q));
}while(q!=cur_align);
if(n> max_quarterword)
confusion("too many spans");
q= cur_span;
while(span_span(span_ptr(q))<n){
q= span_ptr(q);
}
if(span_span(span_ptr(q))> n){
s= new_span_node(span_ptr(q),n,w);
span_ptr(q)= s;
}else if(width(span_ptr(q))<w){
width(span_ptr(q))= w;
}

}else if(w> width(cur_align)){
width(cur_align)= w;
}
type(u)= unset_node;
span_count(u)= (quarterword)n;
determine_stretch_order();
glue_order(u)= o;
glue_stretch(u)= total_stretch[o];
determine_shrink_order();
glue_sign(u)= o;
glue_shrink(u)= total_shrink[o];
pop_nest();
vlink(cur_list.tail_field)= u;
cur_list.tail_field= u;


tail_append(new_glue(glue_ptr(vlink(cur_align))));
subtype(cur_list.tail_field)= tab_skip_code+1;

if(extra_info(cur_align)>=cr_code){
return true;
}
init_span(p);
}
align_state= 1000000;
do{
get_x_or_protected();
}while(cur_cmd==spacer_cmd);
cur_align= p;
init_col();
return false;
}



/*:15*//*16:*/
#line 758 "./luatexdir/tex/align.w"

#ifndef span_span
#  define span_span(A) vlink((A)+1)     
#endif


/*:16*//*17:*/
#line 769 "./luatexdir/tex/align.w"

void fin_row(void)
{
pointer p;
if(cur_list.mode_field==-hmode){
p= filtered_hpack(cur_list.head_field,cur_list.tail_field,0,
additional,fin_row_group,-1,0);
pop_nest();
if(cur_pre_head!=cur_pre_tail)
append_list(cur_pre_head,cur_pre_tail);
append_to_vlist(p,lua_key_index(alignment));
if(cur_head!=cur_tail)
append_list(cur_head,cur_tail);
}else{
p= filtered_vpackage(vlink(cur_list.head_field),
0,additional,max_depth,fin_row_group,-1,0);
pop_nest();
vlink(cur_list.tail_field)= p;
cur_list.tail_field= p;
space_factor= 1000;
}
type(p)= unset_node;
glue_stretch(p)= 0;
if(every_cr!=null)
begin_token_list(every_cr,every_cr_text);
align_peek();

}


/*:17*//*18:*/
#line 803 "./luatexdir/tex/align.w"

void fin_align(void)
{
pointer p,q,r,s,u,v,rr;
scaled t,w;
scaled o;
halfword n;
scaled rule_save;
halfword pd;
if(cur_group!=align_group)
confusion("align1");
unsave();
if(cur_group!=align_group)
confusion("align0");
unsave();
if(nest[nest_ptr-1].mode_field==mmode)
o= display_indent;
else
o= 0;



























q= vlink(preamble);
do{
flush_list(u_part(q));
flush_list(v_part(q));
p= vlink(vlink(q));
if(width(q)==null_flag){

width(q)= 0;
r= vlink(q);
s= glue_ptr(r);
if(s!=zero_glue){
add_glue_ref(zero_glue);
delete_glue_ref(s);
glue_ptr(r)= zero_glue;
}
}
if(span_ptr(q)!=end_span){










t= width(q)+width(glue_ptr(vlink(q)));
r= span_ptr(q);
s= end_span;
span_ptr(s)= p;
n= min_quarterword+1;
do{
width(r)= width(r)-t;
u= span_ptr(r);
while(span_span(r)> n){
s= span_ptr(s);
n= span_span(span_ptr(s))+1;
}
if(span_span(r)<n){
span_ptr(r)= span_ptr(s);
span_ptr(s)= r;
decr(span_span(r));
s= r;
}else{
if(width(r)> width(span_ptr(s)))
width(span_ptr(s))= width(r);
flush_node(r);
}
r= u;
}while(r!=end_span);
}
type(q)= unset_node;
span_count(q)= min_quarterword;
height(q)= 0;
depth(q)= 0;
glue_order(q)= normal;
glue_sign(q)= normal;
glue_stretch(q)= 0;
glue_shrink(q)= 0;
q= p;
}while(q!=null);










decr(save_ptr);
pack_begin_line= -cur_list.ml_field;
if(cur_list.mode_field==-vmode){
rule_save= overfull_rule;
overfull_rule= 0;
p= hpack(preamble,saved_value(0),saved_level(0),-1);
overfull_rule= rule_save;
}else{
q= vlink(preamble);
do{
height(q)= width(q);
width(q)= 0;
q= vlink(vlink(q));
}while(q!=null);
p= filtered_vpackage(preamble,
saved_value(0),saved_level(0),max_depth,preamble_group,-1,0);
q= vlink(preamble);
do{
width(q)= height(q);
height(q)= 0;
q= vlink(vlink(q));
}while(q!=null);
}
pack_begin_line= 0;


q= vlink(cur_list.head_field);
s= cur_list.head_field;
while(q!=null){
if(!is_char_node(q)){
if(type(q)==unset_node){




if(cur_list.mode_field==-vmode){
type(q)= hlist_node;
subtype(q)= align_row_list;
width(q)= width(p);
}else{
type(q)= vlist_node;
subtype(q)= align_row_list;
height(q)= height(p);
}
glue_order(q)= glue_order(p);
glue_sign(q)= glue_sign(p);
glue_set(q)= glue_set(p);
shift_amount(q)= o;
r= vlink(list_ptr(q));
assert(type(r)==unset_node);
s= vlink(list_ptr(p));
do{






n= span_count(r);
t= width(s);
w= t;
u= hold_head;
while(n> min_quarterword){
decr(n);



s= vlink(s);
v= glue_ptr(s);
vlink(u)= new_glue(v);
u= vlink(u);
subtype(u)= tab_skip_code+1;
t= t+width(v);
if(glue_sign(p)==stretching){
if(stretch_order(v)==glue_order(p))
t= t+
round(float_cast(glue_set(p))*
float_cast(stretch(v)));
}else if(glue_sign(p)==shrinking){
if(shrink_order(v)==glue_order(p))
t= t-
round(float_cast(glue_set(p))*
float_cast(shrink(v)));
}
s= vlink(s);
rr= new_null_box();
vlink(u)= rr;
u= vlink(u);
t= t+width(s);
subtype(u)= align_cell_list;
if(cur_list.mode_field==-vmode){
width(u)= width(s);
}else{
type(u)= vlist_node;
height(u)= width(s);
}

}
if(cur_list.mode_field==-vmode){



height(r)= height(q);
depth(r)= depth(q);
if(t==width(r)){
glue_sign(r)= normal;
glue_order(r)= normal;
set_glue_ratio_zero(glue_set(r));
}else if(t> width(r)){
glue_sign(r)= stretching;
if(glue_stretch(r)==0)
set_glue_ratio_zero(glue_set(r));
else
glue_set(r)= 
unfloat((double)(t-width(r))/
glue_stretch(r));
}else{
glue_order(r)= glue_sign(r);
glue_sign(r)= shrinking;
if(glue_shrink(r)==0)
set_glue_ratio_zero(glue_set(r));
else if((glue_order(r)==normal)
&&(width(r)-t> glue_shrink(r)))
set_glue_ratio_one(glue_set(r));
else
glue_set(r)= 
unfloat((double)(width(r)-t)/
glue_shrink(r));
}
width(r)= w;
type(r)= hlist_node;
subtype(r)= align_cell_list;

}else{



width(r)= width(q);
if(t==height(r)){
glue_sign(r)= normal;
glue_order(r)= normal;
set_glue_ratio_zero(glue_set(r));
}else if(t> height(r)){
glue_sign(r)= stretching;
if(glue_stretch(r)==0)
set_glue_ratio_zero(glue_set(r));
else
glue_set(r)= 
unfloat((t-height(r))/glue_stretch(r));
}else{
glue_order(r)= glue_sign(r);
glue_sign(r)= shrinking;
if(glue_shrink(r)==0)
set_glue_ratio_zero(glue_set(r));
else if((glue_order(r)==normal)
&&(height(r)-t> glue_shrink(r)))
set_glue_ratio_one(glue_set(r));
else
glue_set(r)= 
unfloat((height(r)-t)/glue_shrink(r));
}
height(r)= w;
type(r)= vlist_node;
subtype(r)= align_cell_list;

}

shift_amount(r)= 0;
if(u!=hold_head){
vlink(u)= vlink(r);
vlink(r)= vlink(hold_head);
r= u;
}

r= vlink(vlink(r));
s= vlink(vlink(s));
}while(r!=null);

}else if(type(q)==rule_node){


if(is_running(width(q)))
width(q)= width(p);
if(is_running(height(q)))
height(q)= height(p);
if(is_running(depth(q)))
depth(q)= depth(p);
if(o!=0){
r= vlink(q);
vlink(q)= null;
q= hpack(q,0,additional,-1);
shift_amount(q)= o;
subtype(q)= align_cell_list;
vlink(q)= r;
vlink(s)= q;
}
}
}
s= q;
q= vlink(q);
}
flush_node_list(p);
pop_alignment();







pd= cur_list.prev_depth_field;
p= vlink(cur_list.head_field);
q= cur_list.tail_field;
pop_nest();
if(cur_list.mode_field==mmode){
finish_display_alignment(p,q,pd);
}else{
cur_list.prev_depth_field= pd;
vlink(cur_list.tail_field)= p;
if(p!=null)
cur_list.tail_field= q;
if(cur_list.mode_field==vmode){
if(!output_active)
lua_node_filter_s(buildpage_filter_callback,lua_key_index(alignment));
build_page();
}
}
}

/*:18*//*19:*/
#line 1153 "./luatexdir/tex/align.w"

void initialize_alignments(void)
{
token_info(omit_template)= end_template_token;
span_span(end_span)= max_quarterword+1;
span_ptr(end_span)= null;
}/*:19*/
