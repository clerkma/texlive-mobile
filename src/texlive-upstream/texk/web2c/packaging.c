/*1:*/
#line 20 "./luatexdir/tex/packaging.w"


#include "ptexlib.h"

/*:1*//*3:*/
#line 58 "./luatexdir/tex/packaging.w"






















void scan_spec(group_code c)
{
int spec_code;
boolean done= false;
do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));
if(cur_cmd==left_brace_cmd){
spec_code= additional;
cur_val= 0;
done= true;
}else{

back_input();
if(scan_keyword("to")){
spec_code= exactly;
scan_normal_dimen();
}else if(scan_keyword("spread")){
spec_code= additional;
scan_normal_dimen();
}else{
spec_code= additional;
cur_val= 0;
}
}
set_saved_record(0,saved_boxspec,spec_code,cur_val);
save_ptr++;
new_save_level(c);
if(!done){
scan_left_brace();
}
}

/*:3*//*4:*/
#line 121 "./luatexdir/tex/packaging.w"







































































void scan_full_spec(group_code c,int spec_direction,int just_pack)
{
int s;
int i;
int v;
int spec_code;
boolean done= false;
halfword attr_list;
if(attr_list_cache==cache_disabled)
update_attribute_cache();
attr_list= attr_list_cache;
s= saved_value(0);
do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));
if(cur_cmd==left_brace_cmd){
goto QUICK;
}else{
back_input();
goto KEYWORDS;
}
CONTINUE:
while(cur_cmd==relax_cmd||cur_cmd==spacer_cmd){
get_x_token();
if(cur_cmd==left_brace_cmd){
goto QUICK;
}else if(cur_cmd!=relax_cmd&&cur_cmd!=spacer_cmd){
back_input();
break;
}
}
KEYWORDS:
if(scan_keyword("attr")){
scan_register_num();
i= cur_val;
scan_optional_equals();
scan_int();
v= cur_val;
if((attr_list!=null)&&(attr_list==attr_list_cache)){
attr_list= copy_attribute_list(attr_list_cache);
add_node_attr_ref(attr_list);
}
attr_list= do_set_attribute(attr_list,i,v);
goto CONTINUE;
}
if(scan_keyword("dir")){
scan_direction();
spec_direction= cur_val;
goto CONTINUE;
}
if(attr_list==attr_list_cache){
add_node_attr_ref(attr_list);
}
if(scan_keyword("to")){
spec_code= exactly;
}else if(scan_keyword("spread")){
spec_code= additional;
}else{
spec_code= additional;
cur_val= 0;
goto FOUND;
}
scan_normal_dimen();
goto FOUND;
QUICK:
spec_code= additional;
cur_val= 0;
add_node_attr_ref(attr_list);
done= true;
FOUND:
set_saved_record(0,saved_boxcontext,0,s);
set_saved_record(1,saved_boxspec,spec_code,cur_val);

if(spec_direction!=-1){
set_saved_record(2,saved_boxdir,spec_direction,text_dir_ptr);
text_dir_ptr= new_dir(spec_direction);
}else{
set_saved_record(2,saved_boxdir,spec_direction,null);
}
set_saved_record(3,saved_boxattr,0,attr_list);
set_saved_record(4,saved_boxpack,0,just_pack);
save_ptr+= 5;
new_save_level(c);
if(!done){
scan_left_brace();
}

eq_word_define(int_base+body_direction_code,spec_direction);
eq_word_define(int_base+par_direction_code,spec_direction);
eq_word_define(int_base+text_direction_code,spec_direction);
}

/*:4*//*5:*/
#line 301 "./luatexdir/tex/packaging.w"

scaled total_stretch[5];
scaled total_shrink[5];
int last_badness;

/*:5*//*6:*/
#line 310 "./luatexdir/tex/packaging.w"

halfword adjust_tail;


/*:6*//*7:*/
#line 317 "./luatexdir/tex/packaging.w"

halfword pre_adjust_tail;

halfword last_leftmost_char;
halfword last_rightmost_char;

halfword next_char_p;
halfword prev_char_p;

/*:7*//*8:*/
#line 327 "./luatexdir/tex/packaging.w"

void set_prev_char_p(halfword p)
{
prev_char_p= p;
}











/*:8*//*9:*/
#line 343 "./luatexdir/tex/packaging.w"

scaled char_stretch(halfword p)
{
internal_font_number f= font(p);
int m= font_max_stretch(f);
if(m> 0){
int c= character(p);
int ef= get_ef_code(f,c);
if(ef> 0){
scaled dw= calc_char_width(f,c,m)-char_width(f,c)-x_advance(p);
if(dw> 0){
return round_xn_over_d(dw,ef,1000);
}
}
}
return 0;
}

/*:9*//*10:*/
#line 361 "./luatexdir/tex/packaging.w"

scaled char_shrink(halfword p)
{
internal_font_number f= font(p);
int m= font_max_shrink(f);
if(m> 0){
int c= character(p);
int ef= get_ef_code(f,c);
if(ef> 0){
scaled dw= char_width(f,c)+x_advance(p)-calc_char_width(f,c,-m);
if(dw> 0){
return round_xn_over_d(dw,ef,1000);
}
}
}
return 0;
}

/*:10*//*11:*/
#line 379 "./luatexdir/tex/packaging.w"



























scaled kern_stretch(halfword p)
{
int m;
scaled d,e,x;
scaled w= width(p);
halfword l;
halfword r;
if(w==0){

return 0;
}
l= prev_char_p;
if((l==null)||(vlink(l)!=p)){

return 0;
}
r= vlink(p);
if(r==null){

}
if(!(is_char_node(l)&&is_char_node(r))){

return 0;
}

m= (font_max_stretch(font(l))+font_max_stretch(font(r)))/2;
if(m==0){

return 0;
}
d= round_xn_over_d(w,1000+m,1000);

e= (get_ef_code(font(l),character(l))+get_ef_code(font(r),character(r)))/2;
if(e==1000){
x= d-w;
}else{
x= round_xn_over_d(d-w,e,1000);
}



return x;
}

/*:11*//*12:*/
#line 450 "./luatexdir/tex/packaging.w"



























scaled kern_shrink(halfword p)
{
int m;
scaled d,e,x;
scaled w= width(p);
halfword l;
halfword r;
if(w==0){

return 0;
}
l= prev_char_p;
if((l==null)||(vlink(l)!=p)){

return 0;
}
r= vlink(p);
if(r==null){

}
if(!(is_char_node(l)&&is_char_node(r))){

return 0;
}

m= (font_max_shrink(font(l))+font_max_shrink(font(r)))/2;
if(m==0){

return 0;
}
d= round_xn_over_d(w,1000-m,1000);
e= (get_ef_code(font(l),character(l))+get_ef_code(font(r),character(r)))/2;
if(e==1000){
x= w-d;
}else{
x= round_xn_over_d(w-d,e,1000);
}



return x;
}

/*:12*//*13:*/
#line 520 "./luatexdir/tex/packaging.w"

void do_subst_font(halfword p,int ex_ratio)
{
if(type(p)==disc_node){
halfword r= vlink(pre_break(p));
while(r!=null){
if(is_char_node(r))
do_subst_font(r,ex_ratio);
r= vlink(r);
}
r= vlink(post_break(p));
while(r!=null){
if(is_char_node(r))
do_subst_font(r,ex_ratio);
r= vlink(r);
}
r= vlink(no_break(p));
while(r!=null){
if(is_char_node(r))
do_subst_font(r,ex_ratio);
r= vlink(r);
}
return;
}
if(!is_char_node(p)){
normal_error("font expansion","invalid node type");
return;
}else{
internal_font_number f= font(p);
int ef= get_ef_code(f,character(p));
if(ef==0)
return;
if((font_max_stretch(f)> 0)&&(ex_ratio> 0)){
int ex_stretch= ext_xn_over_d(ex_ratio*ef,font_max_stretch(f),1000000);
ex_glyph(p)= fix_expand_value(f,ex_stretch)*1000;
}else if((font_max_shrink(f)> 0)&&(ex_ratio<0)){
int ex_shrink= ext_xn_over_d(ex_ratio*ef,font_max_shrink(f),1000000);
ex_glyph(p)= fix_expand_value(f,ex_shrink)*1000;
}
}
}

/*:13*//*14:*/
#line 562 "./luatexdir/tex/packaging.w"

scaled char_pw(halfword p,int side)
{
internal_font_number f;
int c,w;
if(side==left_side)
last_leftmost_char= null;
else
last_rightmost_char= null;
if(p==null)
return 0;
if(!is_char_node(p))
return 0;
f= font(p);
if(side==left_side){
c= get_lp_code(f,character(p));
last_leftmost_char= p;
}else{
c= get_rp_code(f,character(p));
last_rightmost_char= p;
}
if(c==0)
return 0;
w= quad(f);
return round_xn_over_d(w,c,1000);
}

/*:14*//*15:*/
#line 589 "./luatexdir/tex/packaging.w"

halfword new_margin_kern(scaled w,halfword p,int side)
{
halfword k,q;
k= new_node(margin_kern_node,side);
width(k)= w;
if(p==null)
normal_error("margin kerning","invalid pointer to marginal char node");
q= new_char(font(p),character(p));
margin_char(k)= q;
return k;
}

/*:15*//*16:*/
#line 605 "./luatexdir/tex/packaging.w"

int font_expand_ratio= 0;

halfword hpack(halfword p,scaled w,int m,int pack_direction)
{
halfword r;
halfword q;
scaled h= 0;
scaled d= 0;
scaled x= 0;
scaled_whd whd;
scaled s;
int o;
halfword dir_ptr1= null;
int hpack_dir;
int disc_level= 0;
halfword pack_interrupt[8];
scaled font_stretch= 0;
scaled font_shrink= 0;
int adjust_spacing= adjust_spacing_par;




last_badness= 0;
r= new_node(hlist_node,min_quarterword);
if(pack_direction==-1){
hpack_dir= text_direction_par;
}else{
hpack_dir= pack_direction;
}
box_dir(r)= hpack_dir;









push_dir(dir_ptr1,hpack_dir);
q= r+list_offset;
vlink(q)= p;
if(m==cal_expand_ratio){
prev_char_p= null;
}
if(adjust_spacing> 2){
adjust_spacing= 0;
}
total_stretch[normal]= 0;
total_shrink[normal]= 0;
total_stretch[sfi]= 0;
total_shrink[sfi]= 0;
total_stretch[fil]= 0;
total_shrink[fil]= 0;
total_stretch[fill]= 0;
total_shrink[fill]= 0;
total_stretch[filll]= 0;
total_shrink[filll]= 0;

RESWITCH:
while((p!=null)||(disc_level> 0)){
if(p==null){
decr(disc_level);
p= pack_interrupt[disc_level];
goto RESWITCH;
}





while(is_char_node(p)){








if(m>=cal_expand_ratio){
prev_char_p= p;
if(m==cal_expand_ratio){
font_stretch+= char_stretch(p);
font_shrink+= char_shrink(p);
}else if(m==subst_ex_font){
do_subst_font(p,font_expand_ratio);
}
}
whd= pack_width_height_depth(hpack_dir,dir_TRT,p,true);
x+= whd.wd;
if(whd.ht> h)
h= whd.ht;
if(whd.dp> d)
d= whd.dp;
p= vlink(p);
}
if(p!=null){
switch(type(p)){
case hlist_node:
case vlist_node:








s= shift_amount(p);
whd= pack_width_height_depth(hpack_dir,box_dir(p),p,false);
x+= whd.wd;
if(whd.ht-s> h)
h= whd.ht-s;
if(whd.dp+s> d)
d= whd.dp+s;
break;














case rule_node:
case unset_node:
x+= width(p);
if(height(p)> h)
h= height(p);
if(depth(p)> d)
d= depth(p);
break;

case glue_node:

x+= width(p);
o= stretch_order(p);
total_stretch[o]= total_stretch[o]+stretch(p);
o= shrink_order(p);
total_shrink[o]= total_shrink[o]+shrink(p);
if(subtype(p)>=a_leaders){
halfword g= leader_ptr(p);
if(height(g)> h)
h= height(g);
if(depth(g)> d)
d= depth(g);
}
break;
case kern_node:
x+= width(p);
if(subtype(p)==font_kern&&adjust_spacing){

if(m==cal_expand_ratio){
font_stretch= font_stretch+kern_stretch(p);
font_shrink= font_shrink+kern_shrink(p);
}else if(m==subst_ex_font){

int k= 0;
if(font_expand_ratio> 0){
k= kern_stretch(p);
}else if(font_expand_ratio<0){
k= kern_shrink(p);
}
ex_kern(p)= k;
x+= k;



}
}
break;
case disc_node:
if(m==subst_ex_font)
do_subst_font(p,font_expand_ratio);
if((subtype(p)!=select_disc)&&(vlink(no_break(p))!=null)){
pack_interrupt[disc_level]= vlink(p);
incr(disc_level);
p= no_break(p);
}
break;
case dir_node:

if(dir_dir(p)>=0){
hpack_dir= dir_dir(p);
push_dir_node(dir_ptr1,p);
}else{
pop_dir_node(dir_ptr1);
if(dir_ptr1!=null)
hpack_dir= dir_dir(dir_ptr1);
}
break;
case math_node:

if(glue_is_zero(p)){
x+= surround(p);
break;
}else{

}

case margin_kern_node:
if(m==cal_expand_ratio){
int f= font(margin_char(p));
do_subst_font(margin_char(p),1000);
if(f!=font(margin_char(p)))
font_stretch= font_stretch-width(p)-char_pw(margin_char(p),subtype(p));
font(margin_char(p))= f;
do_subst_font(margin_char(p),-1000);
if(f!=font(margin_char(p)))
font_shrink= font_shrink-width(p)-char_pw(margin_char(p),subtype(p));
font(margin_char(p))= f;
}else if(m==subst_ex_font){
do_subst_font(margin_char(p),font_expand_ratio);
width(p)= -char_pw(margin_char(p),subtype(p));
}
x+= width(p);
break;
case ins_node:
case mark_node:
case adjust_node:









if(adjust_tail!=null||pre_adjust_tail!=null){
while(vlink(q)!=p)
q= vlink(q);
if(type(p)==adjust_node){
if(adjust_pre(p)!=0)
update_adjust_list(pre_adjust_tail);
else
update_adjust_list(adjust_tail);
p= vlink(p);
adjust_ptr(vlink(q))= null;
flush_node(vlink(q));
}else{
vlink(adjust_tail)= p;
adjust_tail= p;
p= vlink(p);
}
vlink(q)= p;
p= q;
}
break;

default:
break;
}
p= vlink(p);
}

}

if(adjust_tail!=null)
vlink(adjust_tail)= null;
if(pre_adjust_tail!=null)
vlink(pre_adjust_tail)= null;
height(r)= h;
depth(r)= d;







if(m==additional)
w= x+w;
width(r)= w;
x= w-x;

if(x==0){
glue_sign(r)= normal;
glue_order(r)= normal;
set_glue_ratio_zero(glue_set(r));
goto EXIT;
}else if(x> 0){








if(total_stretch[filll]!=0)
o= filll;
else if(total_stretch[fill]!=0)
o= fill;
else if(total_stretch[fil]!=0)
o= fil;
else if(total_stretch[sfi]!=0)
o= sfi;
else
o= normal;

if((m==cal_expand_ratio)&&(o==normal)&&(font_stretch> 0)){
font_expand_ratio= divide_scaled_n(x,font_stretch,1000.0);
goto EXIT;
}
glue_order(r)= (quarterword)o;
glue_sign(r)= stretching;
if(total_stretch[o]!=0){
glue_set(r)= unfloat((double)x/total_stretch[o]);
}else{

glue_sign(r)= normal;
set_glue_ratio_zero(glue_set(r));
}
if(o==normal){
if(list_ptr(r)!=null){




last_badness= badness(x,total_stretch[normal]);
if(last_badness> hbadness_par){
int callback_id= callback_defined(hpack_quality_callback);
if(callback_id> 0){
halfword rule= null;
if(last_badness> 100){
run_callback(callback_id,"SdNdd->N","underfull",last_badness,r,abs(pack_begin_line),line,&rule);
}else{
run_callback(callback_id,"SdNdd->N","loose",last_badness,r,abs(pack_begin_line),line,&rule);
}
if(rule!=null){
while(vlink(q)!=null){
q= vlink(q);
}
couple_nodes(q,rule);
}
}else{
print_ln();
if(last_badness> 100){
tprint_nl("Underfull \\hbox (badness ");
}else{
tprint_nl("Loose \\hbox (badness ");
}
print_int(last_badness);
goto COMMON_ENDING;
}
}
}
}
goto EXIT;
}else{




if(total_shrink[filll]!=0)
o= filll;
else if(total_shrink[fill]!=0)
o= fill;
else if(total_shrink[fil]!=0)
o= fil;
else if(total_shrink[sfi]!=0)
o= sfi;
else
o= normal;

if((m==cal_expand_ratio)&&(o==normal)&&(font_shrink> 0)){
font_expand_ratio= divide_scaled_n(x,font_shrink,1000.0);
goto EXIT;
}
glue_order(r)= (quarterword)o;
glue_sign(r)= shrinking;
if(total_shrink[o]!=0){
glue_set(r)= unfloat((double)(-x)/(double)total_shrink[o]);
}else{

glue_sign(r)= normal;
set_glue_ratio_zero(glue_set(r));
}
if((total_shrink[o]<-x)&&(o==normal)&&(list_ptr(r)!=null)){
int overshoot= -x-total_shrink[normal];
last_badness= 1000000;

set_glue_ratio_one(glue_set(r));




if((overshoot> hfuzz_par)||(hbadness_par<100)){
int callback_id= callback_defined(hpack_quality_callback);
halfword rule= null;
if(callback_id> 0){
run_callback(callback_id,"SdNdd->N","overfull",overshoot,r,abs(pack_begin_line),line,&rule);
}else if(overfull_rule_par> 0){
rule= new_rule(normal_rule);
rule_dir(rule)= box_dir(r);
width(rule)= overfull_rule_par;
}
if(rule!=null){
while(vlink(q)!=null){
q= vlink(q);
}
couple_nodes(q,rule);
}
if(callback_id==0){
print_ln();
tprint_nl("Overfull \\hbox (");
print_scaled(overshoot);
tprint("pt too wide");
goto COMMON_ENDING;
}
}
}else if(o==normal){
if(list_ptr(r)!=null){




last_badness= badness(-x,total_shrink[normal]);
if(last_badness> hbadness_par){
int callback_id= callback_defined(hpack_quality_callback);
if(callback_id> 0){
halfword rule= null;
run_callback(callback_id,"SdNdd->N","tight",last_badness,r,abs(pack_begin_line),line,&rule);
if(rule!=null){
while(vlink(q)!=null){
q= vlink(q);
}
couple_nodes(q,rule);
}
}else{
print_ln();
tprint_nl("Tight \\hbox (badness ");
print_int(last_badness);
goto COMMON_ENDING;
}
}
}
}
goto EXIT;
}

COMMON_ENDING:




if(output_active){
tprint(") has occurred while \\output is active");
}else{
if(pack_begin_line!=0){
if(pack_begin_line> 0){
tprint(") in paragraph at lines ");
}else{
tprint(") in alignment at lines ");
}
print_int(abs(pack_begin_line));
tprint("--");
}else{
tprint(") detected at line ");
}
print_int(line);
}

print_ln();
font_in_short_display= null_font;
short_display(list_ptr(r));
print_ln();
begin_diagnostic();
show_box(r);
end_diagnostic(true);
EXIT:
if((m==cal_expand_ratio)&&(font_expand_ratio!=0)){
font_expand_ratio= fix_int(font_expand_ratio,-1000,1000);
q= list_ptr(r);
list_ptr(r)= null;
flush_node(r);

r= hpack(q,w,subst_ex_font,hpack_dir);
}
while(dir_ptr1!=null)
pop_dir_node(dir_ptr1);

font_expand_ratio= 0;
return r;
}

/*:16*//*17:*/
#line 1101 "./luatexdir/tex/packaging.w"

halfword filtered_hpack(halfword p,halfword qt,scaled w,int m,int grp,int pac,int just_pack,halfword attr)
{
halfword q;
if(just_pack){
q= vlink(p);
}else if(type(p)==temp_node&&vlink(p)==null){
q= vlink(p);






}else{
new_hyphenation(p,qt);
(void)new_ligkern(p,qt);
q= vlink(p);

q= lua_hpack_filter(q,w,m,grp,pac,attr);
}
return hpack(q,w,m,pac);
}

/*:17*//*18:*/
#line 1127 "./luatexdir/tex/packaging.w"

scaled_whd natural_sizes(halfword p,halfword pp,glue_ratio g_mult,
int g_sign,int g_order,int pack_direction)
{
scaled s;
halfword g;
int hpack_dir;
scaled_whd xx;
scaled_whd whd,siz= {0,0,0};
scaled gp= 0;
scaled gm= 0;
if(pack_direction==-1){
hpack_dir= text_direction_par;
}else{
hpack_dir= pack_direction;
}
while(p!=pp&&p!=null){
while(is_char_node(p)&&p!=pp){
whd= pack_width_height_depth(hpack_dir,dir_TRT,p,true);
siz.wd+= whd.wd;
if(whd.ht> siz.ht)
siz.ht= whd.ht;
if(whd.dp> siz.dp)
siz.dp= whd.dp;
p= vlink(p);
}
if(p!=pp&&p!=null){
switch(type(p)){
case hlist_node:
case vlist_node:
s= shift_amount(p);
whd= pack_width_height_depth(hpack_dir,box_dir(p),p,false);
siz.wd+= whd.wd;
if(whd.ht-s> siz.ht)
siz.ht= whd.ht-s;
if(whd.dp+s> siz.dp)
siz.dp= whd.dp+s;
break;














case rule_node:
case unset_node:
siz.wd+= width(p);
if(height(p)> siz.ht)
siz.ht= height(p);
if(depth(p)> siz.dp)
siz.dp= depth(p);
break;

case math_node:

if(glue_is_zero(p)){
siz.wd+= surround(p);
break;
}else{

}

case glue_node:
siz.wd+= width(p);
if(g_sign!=normal){
if(g_sign==stretching){
if(stretch_order(p)==g_order){



gp+= stretch(p);
}
}else if(shrink_order(p)==g_order){



gm+= shrink(p);
}
}
if(subtype(p)>=a_leaders){
g= leader_ptr(p);
if(height(g)> siz.ht)
siz.ht= height(g);
if(depth(g)> siz.dp)
siz.dp= depth(g);
}
break;
case margin_kern_node:
siz.wd+= width(p);
break;
case kern_node:
siz.wd+= width(p)+ex_kern(p);
break;
case disc_node:
xx= natural_sizes(no_break(p),null,g_mult,g_sign,g_order,hpack_dir);
siz.wd+= xx.wd;
if(xx.ht> siz.ht)
siz.ht= xx.ht;
if(xx.dp> siz.dp)
siz.dp= xx.dp;
break;
default:
break;
}
p= vlink(p);
}

}
if(g_sign!=normal){
if(g_sign==stretching){
siz.wd+= float_round(float_cast(g_mult)*float_cast(gp));
}else{
siz.wd-= float_round(float_cast(g_mult)*float_cast(gm));
}
}
return siz;
}

/*:18*//*20:*/
#line 1261 "./luatexdir/tex/packaging.w"

int pack_begin_line;

/*:20*//*21:*/
#line 1271 "./luatexdir/tex/packaging.w"

halfword vpackage(halfword p,scaled h,int m,scaled l,int pack_direction)
{
halfword r;
scaled w= 0;
scaled d= 0;
scaled x= 0;
scaled_whd whd;
scaled s;
int o;
last_badness= 0;
r= new_node(vlist_node,0);
if(pack_direction==-1){
box_dir(r)= body_direction_par;
}else{
box_dir(r)= pack_direction;
}
subtype(r)= min_quarterword;
shift_amount(r)= 0;
list_ptr(r)= p;
total_stretch[normal]= 0;
total_shrink[normal]= 0;
total_stretch[sfi]= 0;
total_shrink[sfi]= 0;
total_stretch[fil]= 0;
total_shrink[fil]= 0;
total_stretch[fill]= 0;
total_shrink[fill]= 0;
total_stretch[filll]= 0;
total_shrink[filll]= 0;

while(p!=null){





if(is_char_node(p)){
confusion("vpack");
}else{
switch(type(p)){
case hlist_node:
case vlist_node:




s= shift_amount(p);
whd= pack_width_height_depth(box_dir(r),box_dir(p),p,false);
if(whd.wd+s> w)
w= whd.wd+s;
x+= d+whd.ht;
d= whd.dp;
break;













case rule_node:
case unset_node:
x+= d+height(p);
d= depth(p);
if(width(p)> w)
w= width(p);
break;

case glue_node:

x+= d;
d= 0;
x+= width(p);
o= stretch_order(p);
total_stretch[o]= total_stretch[o]+stretch(p);
o= shrink_order(p);
total_shrink[o]= total_shrink[o]+shrink(p);
if(subtype(p)>=a_leaders){
halfword g= leader_ptr(p);
if(width(g)> w)
w= width(g);
}
break;
case kern_node:
x+= d+width(p);
d= 0;
break;
default:
break;
}
}
p= vlink(p);
}
width(r)= w;
if(d> l){
x+= d-l;
depth(r)= l;
}else{
depth(r)= d;
}







if(m==additional)
h= x+h;
height(r)= h;
x= h-x;

if(x==0){
glue_sign(r)= normal;
glue_order(r)= normal;
set_glue_ratio_zero(glue_set(r));
return r;
}else if(x> 0){




if(total_stretch[filll]!=0)
o= filll;
else if(total_stretch[fill]!=0)
o= fill;
else if(total_stretch[fil]!=0)
o= fil;
else if(total_stretch[sfi]!=0)
o= sfi;
else
o= normal;

glue_order(r)= (quarterword)o;
glue_sign(r)= stretching;
if(total_stretch[o]!=0){
glue_set(r)= unfloat((double)x/total_stretch[o]);
}else{
glue_sign(r)= normal;
set_glue_ratio_zero(glue_set(r));
}
if(o==normal){
if(list_ptr(r)!=null){




last_badness= badness(x,total_stretch[normal]);
if(last_badness> vbadness_par){
int callback_id= callback_defined(vpack_quality_callback);
if(callback_id> 0){
if(last_badness> 100){
run_callback(callback_id,"SdNdd->","underfull",last_badness,r,abs(pack_begin_line),line);
}else{
run_callback(callback_id,"SdNdd->","loose",last_badness,r,abs(pack_begin_line),line);
}
goto EXIT;
}else{
print_ln();
if(last_badness> 100){
tprint_nl("Underfull \\vbox (badness ");
}else{
tprint_nl("Loose \\vbox (badness ");
}
print_int(last_badness);
goto COMMON_ENDING;
}
}
}
}
return r;

}else{




if(total_shrink[filll]!=0)
o= filll;
else if(total_shrink[fill]!=0)
o= fill;
else if(total_shrink[fil]!=0)
o= fil;
else if(total_shrink[sfi]!=0)
o= sfi;
else
o= normal;

glue_order(r)= (quarterword)o;
glue_sign(r)= shrinking;
if(total_shrink[o]!=0){
glue_set(r)= unfloat((double)(-x)/total_shrink[o]);
}else{

glue_sign(r)= normal;
set_glue_ratio_zero(glue_set(r));
}
if((total_shrink[o]<-x)&&(o==normal)&&(list_ptr(r)!=null)){
int overshoot= -x-total_shrink[normal];
last_badness= 1000000;

set_glue_ratio_one(glue_set(r));




if((overshoot> vfuzz_par)||(vbadness_par<100)){
int callback_id= callback_defined(vpack_quality_callback);
if(callback_id> 0){
run_callback(callback_id,"SdNdd->","overfull",overshoot,r,abs(pack_begin_line),line);
goto EXIT;
}else{
print_ln();
tprint_nl("Overfull \\vbox (");
print_scaled(-x-total_shrink[normal]);
tprint("pt too high");
goto COMMON_ENDING;
}
}
}else if(o==normal){
if(list_ptr(r)!=null){




last_badness= badness(-x,total_shrink[normal]);
if(last_badness> vbadness_par){
int callback_id= callback_defined(vpack_quality_callback);
if(callback_id> 0){
run_callback(callback_id,"SdNdd->","tight",last_badness,r,abs(pack_begin_line),line);
goto EXIT;
}else{
print_ln();
tprint_nl("Tight \\vbox (badness ");
print_int(last_badness);
goto COMMON_ENDING;
}
}
}
}
return r;
}

COMMON_ENDING:

if(output_active){
tprint(") has occurred while \\output is active");
}else{
if(pack_begin_line!=0){

tprint(") in alignment at lines ");
print_int(abs(pack_begin_line));
tprint("--");
}else{
tprint(") detected at line ");
}
print_int(line);
print_ln();
}
begin_diagnostic();
show_box(r);
end_diagnostic(true);
EXIT:
return r;
}

/*:21*//*22:*/
#line 1544 "./luatexdir/tex/packaging.w"

halfword filtered_vpackage(halfword p,scaled h,int m,scaled l,int grp,int pack_direction,int just_pack,halfword attr)
{
halfword q= p;
if(!just_pack)

q= lua_vpack_filter(q,h,m,l,grp,pack_direction,attr);
return vpackage(q,h,m,l,pack_direction);
}

/*:22*//*23:*/
#line 1554 "./luatexdir/tex/packaging.w"

void finish_vcenter(void)
{
halfword p;
unsave();
save_ptr--;
p= vpack(vlink(cur_list.head_field),saved_value(0),saved_level(0),-1);
pop_nest();
p= math_vcenter_group(p);
tail_append(p);
}

/*:23*//*24:*/
#line 1566 "./luatexdir/tex/packaging.w"

void package(int c)
{
halfword saved0,saved2,saved3,saved4;
int grp= cur_group;
scaled d= box_max_depth_par;
unsave();
save_ptr-= 5;
saved0= saved_value(0);
saved2= saved_value(2);
saved3= saved_value(3);
saved4= saved_value(4);
if(cur_list.mode_field==-hmode){
cur_box= filtered_hpack(cur_list.head_field,cur_list.tail_field,
saved_value(1),saved_level(1),grp,saved_level(2),saved4,saved3);
subtype(cur_box)= hbox_list;
}else{
cur_box= filtered_vpackage(vlink(cur_list.head_field),
saved_value(1),saved_level(1),d,grp,saved_level(2),saved4,saved3);
if(c==vtop_code){






scaled h= 0;
halfword p= list_ptr(cur_box);
if((p!=null)&&(type(p)<=rule_node)){

h= height(p);
}
depth(cur_box)= depth(cur_box)-h+height(cur_box);
height(cur_box)= h;
}
}
if(saved2!=null){

flush_node_list(text_dir_ptr);
text_dir_ptr= saved2;

}
replace_attribute_list(cur_box,saved3);
pop_nest();
box_end(saved0);
}

/*:24*//*25:*/
#line 1616 "./luatexdir/tex/packaging.w"

void append_to_vlist(halfword b,int location)
{
scaled d;
halfword p;
boolean mirrored= (type(b)==hlist_node)&&is_mirrored(box_dir(b));
halfword result= null;
halfword next_depth= ignore_depth;
boolean prev_set= false;
if(lua_appendtovlist_callback(b,location,prev_depth_par,mirrored,&result,&next_depth,&prev_set)){
while(result!=null){
couple_nodes(cur_list.tail_field,result);
cur_list.tail_field= result;
result= vlink(result);
}
if(prev_set){
prev_depth_par= next_depth;
}
}else{
if(prev_depth_par> ignore_depth){
if(mirrored){
d= width(baseline_skip_par)-prev_depth_par-depth(b);
}else{
d= width(baseline_skip_par)-prev_depth_par-height(b);
}
if(d<line_skip_limit_par){
p= new_param_glue(line_skip_code);
}else{
p= new_skip_param(baseline_skip_code);
width(p)= d;
}
couple_nodes(cur_list.tail_field,p);
cur_list.tail_field= p;
}
couple_nodes(cur_list.tail_field,b);
cur_list.tail_field= b;
if(mirrored){
prev_depth_par= height(b);
}else{
prev_depth_par= depth(b);
}
}
}

/*:25*//*26:*/
#line 1664 "./luatexdir/tex/packaging.w"

#define tail_page_disc disc_ptr[copy_code]  
#define page_disc disc_ptr[last_box_code]   
#define split_disc disc_ptr[vsplit_code]    

halfword disc_ptr[(vsplit_code+1)];

/*:26*//*27:*/
#line 1687 "./luatexdir/tex/packaging.w"

halfword prune_page_top(halfword p,boolean s)
{
halfword q;
halfword prev_p= temp_head;
halfword r= null;
vlink(temp_head)= p;
while(p!=null){
switch(type(p)){
case hlist_node:
case vlist_node:
case rule_node:

q= new_skip_param(split_top_skip_code);
vlink(prev_p)= q;
vlink(q)= p;
if(width(q)> height(p))
width(q)= width(q)-height(p);
else
width(q)= 0;
p= null;
break;
case boundary_node:
case whatsit_node:
case mark_node:
case ins_node:
prev_p= p;
p= vlink(prev_p);
break;
case glue_node:
case kern_node:
case penalty_node:
q= p;
p= vlink(q);
vlink(q)= null;
vlink(prev_p)= p;
if(s){
if(split_disc==null)
split_disc= q;
else
vlink(r)= q;
r= q;
}else{
flush_node_list(q);
}
break;
default:
confusion("pruning");
break;
}
}
return vlink(temp_head);
}

/*:27*//*28:*/
#line 1748 "./luatexdir/tex/packaging.w"

scaled active_height[10];

/*:28*//*29:*/
#line 1756 "./luatexdir/tex/packaging.w"

#define do_all_six(A) A(1);A(2);A(3);A(4);A(5);A(6);A(7)
#define set_height_zero(A) active_height[A]= 0   

/*:29*//*31:*/
#line 1766 "./luatexdir/tex/packaging.w"

scaled best_height_plus_depth;



halfword vert_break(halfword p,scaled h,scaled d)
{
halfword prev_p= p;

int pi= 0;
int b;
int t;
int least_cost;
halfword best_place= null;
scaled prev_dp= 0;
least_cost= awful_bad;
do_all_six(set_height_zero);
while(1){







if(p==null){
pi= eject_penalty;
}else{




switch(type(p)){
case hlist_node:
case vlist_node:
case rule_node:
cur_height= cur_height+prev_dp+height(p);
prev_dp= depth(p);
goto NOT_FOUND;
break;
case boundary_node:
case whatsit_node:
goto NOT_FOUND;
break;
case glue_node:
if(precedes_break(prev_p))
pi= 0;
else
goto UPDATE_HEIGHTS;
break;
case kern_node:
if(vlink(p)==null)
t= penalty_node;
else
t= type(vlink(p));
if(t==glue_node)
pi= 0;
else
goto UPDATE_HEIGHTS;
break;
case penalty_node:
pi= penalty(p);
break;
case mark_node:
case ins_node:
goto NOT_FOUND;
break;
default:
confusion("vertbreak");
break;
}
}


if(pi<inf_penalty){

if(cur_height<h){
if((active_height[3]!=0)||(active_height[4]!=0)||
(active_height[5]!=0)||(active_height[6]!=0))
b= 0;
else
b= badness(h-cur_height,active_height[2]);
}else if(cur_height-h> active_height[7]){
b= awful_bad;
}else{
b= badness(cur_height-h,active_height[7]);
}

if(b<awful_bad){
if(pi<=eject_penalty)
b= pi;
else if(b<inf_bad)
b= b+pi;
else
b= deplorable;
}
if(b<=least_cost){
best_place= p;
least_cost= b;
best_height_plus_depth= cur_height+prev_dp;
}
if((b==awful_bad)||(pi<=eject_penalty))
goto DONE;
}

if((type(p)<glue_node)||(type(p)> kern_node))
goto NOT_FOUND;
UPDATE_HEIGHTS:






if(type(p)!=kern_node){
active_height[2+stretch_order(p)]+= stretch(p);
active_height[7]+= shrink(p);
if((shrink_order(p)!=normal)&&(shrink(p)!=0)){
print_err("Infinite glue shrinkage found in box being split");
help4("The box you are \\vsplitting contains some infinitely",
"shrinkable glue, e.g., `\\vss' or `\\vskip 0pt minus 1fil'.",
"Such glue doesn't belong there; but you can safely proceed,",
"since the offensive shrinkability has been made finite.");
error();
shrink_order(p)= normal;
}
}
cur_height= cur_height+prev_dp+width(p);
prev_dp= 0;
NOT_FOUND:
if(prev_dp> d){
cur_height= cur_height+prev_dp-d;
prev_dp= d;
}
prev_p= p;
p= vlink(prev_p);
}
DONE:
return best_place;
}

/*:31*//*32:*/
#line 1922 "./luatexdir/tex/packaging.w"



halfword vsplit(halfword n,scaled h,int m)
{
halfword v;
int vdir;
halfword p;
halfword q;
halfword i;
v= box(n);
vdir= box_dir(v);
flush_node_list(split_disc);
split_disc= null;
for(i= 0;i<=biggest_used_mark;i++){
delete_split_first_mark(i);
delete_split_bot_mark(i);
}

if(v==null){
return null;
}
if(type(v)!=vlist_node){
print_err("\\vsplit needs a \\vbox");
help2("The box you are trying to split is an \\hbox.",
"i can't split such a box, so I''ll leave it alone.");
error();
return null;
}
q= vert_break(list_ptr(v),h,split_max_depth_par);






p= list_ptr(v);
if(p==q){
list_ptr(v)= null;
}else{
while(1){
if(type(p)==mark_node){
if(split_first_mark(mark_class(p))==null){
set_split_first_mark(mark_class(p),mark_ptr(p));
set_split_bot_mark(mark_class(p),split_first_mark(mark_class(p)));
set_token_ref_count(split_first_mark(mark_class(p)),
token_ref_count(split_first_mark(mark_class(p)))+2);
}else{
delete_token_ref(split_bot_mark(mark_class(p)));
set_split_bot_mark(mark_class(p),mark_ptr(p));
add_token_ref(split_bot_mark(mark_class(p)));
}
}
if(vlink(p)==q){
vlink(p)= null;
break;
}
p= vlink(p);
}
}
q= prune_page_top(q,saving_vdiscards_par> 0);
p= list_ptr(v);
list_ptr(v)= null;
flush_node(v);
if(q==null){

box(n)= null;
}else{
box(n)= filtered_vpackage(q,0,additional,max_depth_par,split_keep_group,vdir,0,0);
}
if(m==exactly){
return filtered_vpackage(p,h,exactly,split_max_depth_par,split_off_group,vdir,0,0);
}else{
return filtered_vpackage(p,0,additional,max_depth_par,split_off_group,vdir,0,0);
}
}

/*:32*//*33:*/
#line 2004 "./luatexdir/tex/packaging.w"

void begin_box(int box_context)
{
halfword q;
halfword k;
int n;
int spec_direction= -1;
int just_pack= 0;
int split_mode= exactly;
switch(cur_chr){
case box_code:
scan_register_num();
cur_box= box(cur_val);

box(cur_val)= null;
break;
case copy_code:
scan_register_num();
cur_box= copy_node_list(box(cur_val));
break;
case last_box_code:





cur_box= null;
if(abs(cur_list.mode_field)==mmode){
you_cant();
help1("Sorry; this \\lastbox will be void.");
error();
}else if((cur_list.mode_field==vmode)&&(cur_list.head_field==cur_list.tail_field)){
you_cant();
help2("Sorry...I usually can't take things from the current page.",
"This \\lastbox will therefore be void.");
error();
}else{
if(cur_list.head_field!=cur_list.tail_field){




if((type(cur_list.tail_field)==hlist_node)||(type(cur_list.tail_field)==vlist_node)){

q= alink(cur_list.tail_field);
if(q==null||vlink(q)!=cur_list.tail_field){
q= cur_list.head_field;
while(vlink(q)!=cur_list.tail_field)
q= vlink(q);
}
uncouple_node(cur_list.tail_field);
cur_box= cur_list.tail_field;
shift_amount(cur_box)= 0;
cur_list.tail_field= q;
vlink(cur_list.tail_field)= null;
}
}
}
break;
case vsplit_code:




scan_register_num();
n= cur_val;
if(scan_keyword("upto")){
split_mode= additional;
}else if(!scan_keyword("to")){
print_err("Missing `to' inserted");
help2("I'm working on `\\vsplit<box number> to <dimen>';",
"will look for the <dimen> next.");
error();
}
scan_normal_dimen();
cur_box= vsplit(n,cur_val,split_mode);
break;
default:





switch(cur_chr){
case tpack_code:
cur_chr= vtop_code;
just_pack= 1;
break;
case vpack_code:
cur_chr= vtop_code+vmode;
just_pack= 1;
break;
case hpack_code:
cur_chr= vtop_code+hmode;
just_pack= 1;
break;
}

k= cur_chr-vtop_code;
set_saved_record(0,saved_boxcontext,0,box_context);
switch(abs(cur_list.mode_field)){
case vmode:
spec_direction= body_direction_par;
break;
case hmode:
spec_direction= text_direction_par;
break;
case mmode:
spec_direction= math_direction_par;
break;
}
if(k==hmode){
if((box_context<box_flag)&&(abs(cur_list.mode_field)==vmode))
scan_full_spec(adjusted_hbox_group,spec_direction,just_pack);
else
scan_full_spec(hbox_group,spec_direction,just_pack);
}else{
if(k==vmode){
scan_full_spec(vbox_group,spec_direction,just_pack);
}else{
scan_full_spec(vtop_group,spec_direction,just_pack);
k= vmode;
}
normal_paragraph();
}
push_nest();
cur_list.mode_field= -k;
if(k==vmode){
prev_depth_par= ignore_depth;
if(every_vbox_par!=null)
begin_token_list(every_vbox_par,every_vbox_text);
}else{
space_factor_par= 1000;
if(every_hbox_par!=null)
begin_token_list(every_hbox_par,every_hbox_text);
}
return;
break;
}

box_end(box_context);
}/*:33*/
