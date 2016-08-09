/*1:*/
#line 20 "./luatexdir/tex/nesting.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 25 "./luatexdir/tex/nesting.w"

#define page_goal page_so_far[0]

/*:2*//*3:*/
#line 61 "./luatexdir/tex/nesting.w"

static const char*string_mode(int m)
{
if(m> 0){
switch(m/(max_command_cmd+1)){
case 0:
return"vertical mode";
break;
case 1:
return"horizontal mode";
break;
case 2:
return"display math mode";
break;
default:
break;
}
}else if(m==0){
return"no mode";
}else{
switch((-m)/(max_command_cmd+1)){
case 0:
return"internal vertical mode";
break;
case 1:
return"restricted horizontal mode";
break;
case 2:
return"math mode";
break;
default:
break;
}
}
return"unknown mode";
}

/*:3*//*4:*/
#line 98 "./luatexdir/tex/nesting.w"

void print_mode(int m)
{
tprint(string_mode(m));
}

/*:4*//*5:*/
#line 104 "./luatexdir/tex/nesting.w"

void print_in_mode(int m)
{
tprint("' in ");
tprint(string_mode(m));
}

/*:5*//*6:*/
#line 111 "./luatexdir/tex/nesting.w"

int get_mode_id(void)
{
int m= cur_list.mode_field;
if(m> 0){
switch(m/(max_command_cmd+1)){
case 0:
return'v';
break;
case 1:
return'h';
break;
case 2:
return'm';
break;
default:
return'\0';
break;
}
}else if(m==0){
return'n';;
}else{
switch((-m)/(max_command_cmd+1)){
case 0:
return'V';
break;
case 1:
return'H';
break;
case 2:
return'M';
break;
default:
return'\0';
break;
}
}
}


/*:6*//*8:*/
#line 216 "./luatexdir/tex/nesting.w"

list_state_record*nest;
int nest_ptr;
int max_nest_stack;
int shown_mode;
halfword save_tail;


/*:8*//*9:*/
#line 232 "./luatexdir/tex/nesting.w"

void initialize_nesting(void)
{
nest_ptr= 0;
max_nest_stack= 0;
shown_mode= 0;
cur_list.mode_field= vmode;
cur_list.head_field= contrib_head;
cur_list.tail_field= contrib_head;
cur_list.eTeX_aux_field= null;
cur_list.prev_depth_field= ignore_depth;
cur_list.space_factor_field= 1000;
cur_list.incompleat_noad_field= null;
cur_list.ml_field= 0;
cur_list.pg_field= 0;
cur_list.dirs_field= null;
init_math_fields();
}

/*:9*//*10:*/
#line 253 "./luatexdir/tex/nesting.w"

void tail_append(halfword p)
{
couple_nodes(cur_list.tail_field,p);
cur_list.tail_field= vlink(cur_list.tail_field);
}

/*:10*//*11:*/
#line 260 "./luatexdir/tex/nesting.w"

halfword pop_tail(void)
{
halfword n,r;
if(cur_list.tail_field!=cur_list.head_field){
r= cur_list.tail_field;
if(vlink(alink(cur_list.tail_field))==cur_list.tail_field){
n= alink(cur_list.tail_field);
}else{
n= cur_list.head_field;
while(vlink(n)!=cur_list.tail_field)
n= vlink(n);
}
flush_node(cur_list.tail_field);
cur_list.tail_field= n;
vlink(n)= null;
return r;
}else{
return null;
}
}

/*:11*//*12:*/
#line 286 "./luatexdir/tex/nesting.w"

void push_nest(void)
{
if(nest_ptr> max_nest_stack){
max_nest_stack= nest_ptr;
if(nest_ptr==nest_size)
overflow("semantic nest size",(unsigned)nest_size);
}
incr(nest_ptr);
cur_list.mode_field= nest[nest_ptr-1].mode_field;
cur_list.head_field= new_node(temp_node,0);
cur_list.tail_field= cur_list.head_field;
cur_list.eTeX_aux_field= null;
cur_list.ml_field= line;
cur_list.pg_field= 0;
cur_list.dirs_field= null;
cur_list.prev_depth_field= nest[nest_ptr-1].prev_depth_field;
cur_list.space_factor_field= nest[nest_ptr-1].space_factor_field;
cur_list.incompleat_noad_field= nest[nest_ptr-1].incompleat_noad_field;
init_math_fields();
}

/*:12*//*13:*/
#line 313 "./luatexdir/tex/nesting.w"

void pop_nest(void)
{
flush_node(cur_list.head_field);
decr(nest_ptr);
}

/*:13*//*14:*/
#line 322 "./luatexdir/tex/nesting.w"

void show_activities(void)
{
int p;
int m;
halfword q,r;
int t;
tprint_nl("");
print_ln();
for(p= nest_ptr;p>=0;p--){
m= nest[p].mode_field;
tprint_nl("### ");
print_mode(m);
tprint(" entered at line ");
print_int(abs(nest[p].ml_field));

#if 0

if(m==hmode)
if(nest[p].pg_field!=040600000){
tprint(" (language");
print_int(nest[p].pg_field%0200000);
tprint(":hyphenmin");
print_int(nest[p].pg_field/020000000);
print_char(',');
print_int((nest[p].pg_field/0200000)%0100);
print_char(')');
}
#endif
if(nest[p].ml_field<0)
tprint(" (\\output routine)");
if(p==0){

if(page_head!=page_tail){
tprint_nl("### current page:");
if(output_active)
tprint(" (held over for next output)");
show_box(vlink(page_head));
if(page_contents> empty){
tprint_nl("total height ");
print_totals();
tprint_nl(" goal height ");
print_scaled(page_goal);
r= vlink(page_ins_head);
while(r!=page_ins_head){
print_ln();
tprint_esc("insert");
t= subtype(r);
print_int(t);
tprint(" adds ");
if(count(t)==1000)
t= height(r);
else
t= x_over_n(height(r),1000)*count(t);
print_scaled(t);
if(type(r)==split_up_node){
q= page_head;
t= 0;
do{
q= vlink(q);
if((type(q)==ins_node)
&&(subtype(q)==subtype(r)))
incr(t);
}while(q!=broken_ins(r));
tprint(", #");
print_int(t);
tprint(" might split");
}
r= vlink(r);
}
}
}
if(vlink(contrib_head)!=null)
tprint_nl("### recent contributions:");
}
show_box(vlink(nest[p].head_field));

switch(abs(m)/(max_command_cmd+1)){
case 0:
tprint_nl("prevdepth ");
if(nest[p].prev_depth_field<=ignore_depth)
tprint("ignored");
else
print_scaled(nest[p].prev_depth_field);
if(nest[p].pg_field!=0){
tprint(", prevgraf ");
print_int(nest[p].pg_field);
if(nest[p].pg_field!=1)
tprint(" lines");
else
tprint(" line");
}
break;
case 1:
tprint_nl("spacefactor ");
print_int(nest[p].space_factor_field);

#if 0
if(m> 0){
if(nest[p].current_language_field> 0){
tprint(", current language ");
print_int(nest[p].current_language_field);
}
}
#endif
break;
case 2:
if(nest[p].incompleat_noad_field!=null){
tprint("this will be denominator of:");
show_box(nest[p].incompleat_noad_field);
}
}

}
}/*:14*/
