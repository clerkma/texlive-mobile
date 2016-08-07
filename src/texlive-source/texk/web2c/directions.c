/*1:*/
#line 20 "./luatexdir/tex/directions.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 24 "./luatexdir/tex/directions.w"

void scan_direction(void)
{
int save_cur_cmd= cur_cmd;
int save_cur_chr= cur_chr;
get_x_token();
if(cur_cmd==assign_dir_cmd){
cur_val= eqtb[cur_chr].cint;
goto EXIT;
}else{
back_input();
}
if(scan_keyword("TLT")){
cur_val= dir_TLT;
}else if(scan_keyword("TRT")){
cur_val= dir_TRT;
}else if(scan_keyword("LTL")){
cur_val= dir_LTL;
}else if(scan_keyword("RTT")){
cur_val= dir_RTT;
}else{
tex_error("Bad direction",NULL);
cur_val= 0;
}
get_x_token();
if(cur_cmd!=spacer_cmd)
back_input();
EXIT:
cur_cmd= save_cur_cmd;
cur_chr= save_cur_chr;
}

/*:2*//*3:*/
#line 58 "./luatexdir/tex/directions.w"

halfword do_push_dir_node(halfword p,halfword a)
{
halfword n= copy_node(a);
vlink(n)= p;
return n;
}

halfword do_pop_dir_node(halfword p)
{
halfword n= vlink(p);
flush_node(p);
return n;
}

/*:3*//*4:*/
#line 73 "./luatexdir/tex/directions.w"

halfword dir_ptr;

halfword text_dir_ptr;

/*:4*//*5:*/
#line 79 "./luatexdir/tex/directions.w"

void initialize_directions(void)
{
}

/*:5*//*6:*/
#line 84 "./luatexdir/tex/directions.w"

halfword new_dir(int s)
{
halfword p= new_node(dir_node,0);
dir_dir(p)= s;
dir_dvi_ptr(p)= -1;
dir_level(p)= cur_level;
return p;
}

/*:6*//*7:*/
#line 99 "./luatexdir/tex/directions.w"

























const char*dir_strings[8]= {
"-TLT","-TRT","-LTL","-RTT",
"+TLT","+TRT","+LTL","+RTT",
};

int dir_swap= 4;

const char*string_dir(int d)
{
return(dir_strings[d+dir_swap]+1);
}

/*:7*//*8:*/
#line 136 "./luatexdir/tex/directions.w"

void print_dir(int d)
{
tprint(string_dir(d));
}

/*:8*//*9:*/
#line 142 "./luatexdir/tex/directions.w"

scaled pack_width(int curdir,int pdir,halfword p,boolean isglyph)
{
scaled wd= 0;
if(isglyph){
if(textdir_parallel(curdir,pdir)==textglyphdir_orthogonal(pdir)){
wd= glyph_width(p);
if(ex_glyph(p)!=0){

wd= ext_xn_over_d(wd,1000000+ex_glyph(p),1000000);

}
}else{
wd= glyph_depth(p)+glyph_height(p);
}
}else{
if(textdir_parallel(pdir,curdir))
wd= width(p);
else
wd= depth(p)+height(p);
}
return wd;
}

/*:9*//*10:*/
#line 166 "./luatexdir/tex/directions.w"

scaled_whd pack_width_height_depth(int curdir,int pdir,halfword p,
boolean isglyph)
{
scaled_whd whd= {0,0,0};
whd.wd= pack_width(curdir,pdir,p,isglyph);
if(isglyph){
if(is_rotated(curdir)){
if(textdir_parallel(curdir,pdir))
whd.ht= whd.dp= (glyph_height(p)+glyph_depth(p))/2;
else
whd.ht= whd.dp= glyph_width(p)/2;
}else if(is_rotated(pdir)){
if(textdir_parallel(curdir,pdir))
whd.ht= whd.dp= (glyph_height(p)+glyph_depth(p))/2;
else
whd.ht= glyph_width(p);
}else{
if(glyphdir_eq(curdir,pdir)){
whd.ht= glyph_height(p);
whd.dp= glyph_depth(p);
}else if(glyphdir_opposite(curdir,pdir)){
whd.ht= glyph_depth(p);
whd.dp= glyph_height(p);
}else
whd.ht= glyph_width(p);
}
}else{
if(is_rotated(curdir)){
if(textdir_parallel(curdir,pdir))
whd.ht= whd.dp= (height(p)+depth(p))/2;
else
whd.ht= whd.dp= width(p)/2;
}else if(pardir_eq(curdir,pdir)){
whd.ht= height(p);
whd.dp= depth(p);
}else if(pardir_opposite(curdir,pdir)){
whd.ht= depth(p);
whd.dp= height(p);
}else
whd.ht= width(p);
}
return whd;
}

/*:10*//*11:*/
#line 211 "./luatexdir/tex/directions.w"

void update_text_dir_ptr(int val)
{
if(dir_level(text_dir_ptr)==cur_level){

dir_dir(text_dir_ptr)= val;
}else{

halfword text_dir_tmp= new_dir(val);
vlink(text_dir_tmp)= text_dir_ptr;
text_dir_ptr= text_dir_tmp;
}
}/*:11*/
