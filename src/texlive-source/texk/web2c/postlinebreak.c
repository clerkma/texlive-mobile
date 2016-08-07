/*1:*/
#line 20 "./luatexdir/tex/postlinebreak.w"



#include "ptexlib.h"

/*:1*//*3:*/
#line 54 "./luatexdir/tex/postlinebreak.w"

#define next_break prev_break   


void ext_post_line_break(int paragraph_dir,
int right_skip,
int left_skip,
int protrude_chars,
halfword par_shape_ptr,
int adjust_spacing,
halfword inter_line_penalties_ptr,
int inter_line_penalty,
int club_penalty,
halfword club_penalties_ptr,
halfword widow_penalties_ptr,
int widow_penalty,
int broken_penalty,
halfword final_par_glue,
halfword best_bet,
halfword last_special_line,
scaled second_width,
scaled second_indent,
scaled first_width,
scaled first_indent,halfword best_line)
{

boolean have_directional= true;
halfword q,r;
halfword k;
scaled w;
boolean glue_break;
boolean disc_break;
boolean post_disc_break;
scaled cur_width;
scaled cur_indent;
int pen;
halfword cur_p;
halfword cur_line;

dir_ptr= cur_list.dirs_field;








q= break_node(best_bet);
#if 0
used_discs= used_disc(best_bet);
#endif

cur_p= null;
do{
r= q;
q= prev_break(q);
next_break(r)= cur_p;
cur_p= r;
}while(q!=null);


cur_line= cur_list.pg_field+1;

do{











#if 0
tprint("BEGIN OF LINE ");
print_int(cur_break(cur_p));
breadth_max= 100000;
depth_threshold= 100000;
show_node_list(temp_head);
#endif


for(q= dir_ptr;q!=null;q= vlink(q)){
halfword tmp= new_dir(dir_dir(q));
halfword nxt= vlink(temp_head);
delete_attribute_ref(node_attr(tmp));
node_attr(tmp)= node_attr(temp_head);
add_node_attr_ref(node_attr(tmp));
couple_nodes(temp_head,tmp);
try_couple_nodes(tmp,nxt);
}
if(dir_ptr!=null){
flush_node_list(dir_ptr);
dir_ptr= null;
}









if(temp_head!=null){
q= temp_head;
while(q!=null){
if(type(q)==math_node){
surround(q)= 0;
if(glue_ptr(q)!=zero_glue){
delete_glue_ref(glue_ptr(q));
glue_ptr(q)= zero_glue;
}
break;
}else if((type(q)==hlist_node)&&(subtype(q)==indent_list)){

}else if(is_char_node(q)){
break;
}else if(non_discardable(q)){
break;
}else if(type(q)==kern_node&&subtype(q)!=explicit){
break;
}
q= vlink(q);
}
}


r= cur_break(cur_p);
q= null;
disc_break= false;
post_disc_break= false;
glue_break= false;


if(r==null){
for(r= temp_head;vlink(r)!=null;r= vlink(r));
if(r==final_par_glue){


q= r;

r= alink(r);
}

}else if(type(r)==math_node){
surround(r)= 0;

if(glue_ptr(r)!=zero_glue){
delete_glue_ref(glue_ptr(r));
glue_ptr(r)= zero_glue;
}

}else if(type(r)==glue_node){
delete_glue_ref(glue_ptr(r));
glue_ptr(r)= right_skip;
subtype(r)= right_skip_code+1;
incr(glue_ref_count(right_skip));
glue_break= true;

q= r;
r= alink(r);
assert(vlink(r)==q);

}else if(type(r)==disc_node){
halfword a= alink(r);
halfword v= vlink(r);
assert(a!=null);
assert(v!=null);
switch(subtype(r)){
case select_disc:
if(vlink_pre_break(r)!=null){
flush_node_list(vlink_pre_break(r));
vlink_pre_break(r)= null;
tlink_pre_break(r)= null;
}
if(vlink_no_break(r)!=null){
couple_nodes(a,vlink_no_break(r));
couple_nodes(tlink_no_break(r),r);
vlink_no_break(r)= null;
tlink_no_break(r)= null;
}

assert(type(a)==disc_node&&subtype(a)==init_disc);
flush_node_list(vlink_no_break(a));
vlink_no_break(a)= null;
tlink_no_break(a)= null;
flush_node_list(vlink_pre_break(a));
vlink_pre_break(a)= null;
tlink_pre_break(a)= null;
flush_node_list(vlink_post_break(a));
vlink_post_break(a)= null;
tlink_post_break(a)= null;

break;
case init_disc:
assert(type(v)==disc_node&&subtype(v)==select_disc);
subtype(v)= syllable_disc;
flush_node_list(vlink_no_break(v));
vlink_no_break(v)= vlink_post_break(r);
tlink_no_break(v)= tlink_post_break(r);
vlink_post_break(r)= null;
tlink_post_break(r)= null;
default:
if(vlink_no_break(r)!=null){
flush_node_list(vlink_no_break(r));
vlink_no_break(r)= null;
tlink_no_break(r)= null;
}
if(vlink_pre_break(r)!=null){
couple_nodes(a,vlink_pre_break(r));
couple_nodes(tlink_pre_break(r),r);
vlink_pre_break(r)= null;
tlink_pre_break(r)= null;
}
}
if(vlink_post_break(r)!=null){
couple_nodes(r,vlink_post_break(r));
couple_nodes(tlink_post_break(r),v);
vlink_post_break(r)= null;
tlink_post_break(r)= null;
post_disc_break= true;
}
disc_break= true;
}else if(type(r)==kern_node){
width(r)= 0;
}



if(have_directional){
halfword e;
halfword p;
for(e= vlink(temp_head);e!=null&&e!=cur_break(cur_p);e= vlink(e)){
if(type(e)==dir_node){
if(dir_dir(e)>=0){
dir_ptr= do_push_dir_node(dir_ptr,e);
}else if(dir_ptr!=null&&dir_dir(dir_ptr)==(dir_dir(e)+dir_swap)){
dir_ptr= do_pop_dir_node(dir_ptr);
}
}
}
assert(e==cur_break(cur_p));


e= vlink(r);
for(p= dir_ptr;p!=null;p= vlink(p)){
halfword s= new_dir(dir_dir(p)-dir_swap);
delete_attribute_ref(node_attr(s));
node_attr(s)= node_attr(r);
add_node_attr_ref(node_attr(s));
couple_nodes(r,s);
try_couple_nodes(s,e);
r= s;
}
}
if(passive_right_box(cur_p)!=null){

halfword s= copy_node_list(passive_right_box(cur_p));
halfword e= vlink(r);
couple_nodes(r,s);
try_couple_nodes(s,e);
r= s;
}
if(q==null){
q= r;
}









if(q!=temp_head&&protrude_chars> 0){
halfword p,ptmp;
if(disc_break&&(is_char_node(q)||(type(q)!=disc_node))){
p= q;
ptmp= p;
}else{
p= alink(q);
assert(vlink(p)==q);
ptmp= p;
}
p= find_protchar_right(vlink(temp_head),p);
w= char_pw(p,right_side);
if(w!=0){
k= new_margin_kern(-w,last_rightmost_char,right_side);
delete_attribute_ref(node_attr(k));
node_attr(k)= node_attr(p);
add_node_attr_ref(node_attr(k));
try_couple_nodes(k,vlink(ptmp));
couple_nodes(ptmp,k);
if(ptmp==q)
q= vlink(q);
}
}


if(!glue_break){

halfword r1= new_glue((right_skip==null?null:copy_node(right_skip)));
glue_ref_count(glue_ptr(r1))= null;
subtype(r1)= right_skip_code+1;
try_couple_nodes(r1,vlink(q));
delete_attribute_ref(node_attr(r1));
node_attr(r1)= node_attr(q);
add_node_attr_ref(node_attr(r1));
couple_nodes(q,r1);
q= r1;
}








r= vlink(q);
vlink(q)= null;

q= vlink(temp_head);
try_couple_nodes(temp_head,r);
if(passive_left_box(cur_p)!=null&&passive_left_box(cur_p)!=0){

halfword s;
r= copy_node_list(passive_left_box(cur_p));
s= vlink(q);
couple_nodes(r,q);
q= r;
if((cur_line==cur_list.pg_field+1)&&(s!=null)){
if(type(s)==hlist_node){
if(list_ptr(s)==null){
q= vlink(q);
try_couple_nodes(r,vlink(s));
try_couple_nodes(s,r);
}
}
}
}

if(protrude_chars> 0){
halfword p;
p= q;
p= find_protchar_left(p,false);
w= char_pw(p,left_side);
if(w!=0){
k= new_margin_kern(-w,last_leftmost_char,left_side);
delete_attribute_ref(node_attr(k));
node_attr(k)= node_attr(q);
add_node_attr_ref(node_attr(k));
couple_nodes(k,q);
q= k;
}
}
if(left_skip!=zero_glue){
r= new_glue(copy_node(left_skip));
glue_ref_count(glue_ptr(r))= null;
subtype(r)= left_skip_code+1;
delete_attribute_ref(node_attr(r));
node_attr(r)= node_attr(q);
add_node_attr_ref(node_attr(r));
couple_nodes(r,q);
q= r;
}







if(cur_line> last_special_line){
cur_width= second_width;
cur_indent= second_indent;
}else if(par_shape_ptr==null){
cur_width= first_width;
cur_indent= first_indent;
}else{
cur_indent= varmem[(par_shape_ptr+2*cur_line)].cint;
cur_width= varmem[(par_shape_ptr+2*cur_line+1)].cint;
}
adjust_tail= adjust_head;
pre_adjust_tail= pre_adjust_head;
if(adjust_spacing> 0){
just_box= hpack(q,cur_width,cal_expand_ratio,paragraph_dir);
}else{
just_box= hpack(q,cur_width,exactly,paragraph_dir);
}
shift_amount(just_box)= cur_indent;
subtype(just_box)= line_list;


if((vlink(contrib_head)!=null))
if(!output_active)
lua_node_filter_s(buildpage_filter_callback,lua_key_index(pre_box));
if(pre_adjust_head!=pre_adjust_tail){
append_list(pre_adjust_head,pre_adjust_tail);
if(!output_active)
lua_node_filter_s(buildpage_filter_callback,lua_key_index(pre_adjust));
}
pre_adjust_tail= null;
append_to_vlist(just_box,lua_key_index(post_linebreak));
if(!output_active)
lua_node_filter_s(buildpage_filter_callback,lua_key_index(box));
if(adjust_head!=adjust_tail){
append_list(adjust_head,adjust_tail);
if(!output_active)
lua_node_filter_s(buildpage_filter_callback,lua_key_index(adjust));
}
adjust_tail= null;











if(cur_line+1!=best_line){
q= inter_line_penalties_ptr;
if(q!=null){
r= cur_line;
if(r> penalty(q))
r= penalty(q);
pen= penalty(q+r);
}else{
if(passive_pen_inter(cur_p)!=0){
pen= passive_pen_inter(cur_p);
}else{
pen= inter_line_penalty;
}
}
q= club_penalties_ptr;
if(q!=null){
r= cur_line-cur_list.pg_field;
if(r> penalty(q))
r= penalty(q);
pen+= penalty(q+r);
}else if(cur_line==cur_list.pg_field+1){
pen+= club_penalty;
}
q= widow_penalties_ptr;
if(q!=null){
r= best_line-cur_line-1;
if(r> penalty(q))
r= penalty(q);
pen+= penalty(q+r);
}else if(cur_line+2==best_line){
pen+= widow_penalty;
}
if(disc_break){
if(passive_pen_broken(cur_p)!=0){
pen+= passive_pen_broken(cur_p);
}else{
pen+= broken_penalty;
}
}
if(pen!=0){
r= new_penalty(pen);
couple_nodes(cur_list.tail_field,r);
cur_list.tail_field= r;
}
}





incr(cur_line);
cur_p= next_break(cur_p);
if(cur_p!=null&&!post_disc_break){








r= temp_head;












while(1){
q= vlink(r);








if(type(q)==math_node){

surround(q)= 0;
if(glue_ptr(q)!=zero_glue){
delete_glue_ref(glue_ptr(q));
glue_ptr(q)= zero_glue;
add_glue_ref(glue_ptr(q));
}

}
if(q==cur_break(cur_p)){
break;
}else if(is_char_node(q)){
break;
}else if(type(q)==local_par_node){

}else if(non_discardable(q)){
break;
}else if(type(q)==kern_node&&subtype(q)!=explicit){
break;
}
r= q;
}
if(r!=temp_head){
vlink(r)= null;
flush_node_list(vlink(temp_head));
try_couple_nodes(temp_head,q);
}
}
}while(cur_p!=null);
if((cur_line!=best_line)||(vlink(temp_head)!=null))
confusion("line breaking");
cur_list.pg_field= best_line-1;
cur_list.dirs_field= dir_ptr;
dir_ptr= null;
}/*:3*/
