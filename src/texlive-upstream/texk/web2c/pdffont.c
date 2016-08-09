/*1:*/
#line 22 "./luatexdir/pdf/pdffont.w"


#include "ptexlib.h"

/*:1*//*3:*/
#line 36 "./luatexdir/pdf/pdffont.w"

scaled_whd output_one_char(PDF pdf,halfword p)
{
internal_font_number f= font(p);
int c= character(p);
int ex_glyph= ex_glyph(p)/1000;
scaled_whd ci= get_charinfo_whd(f,c);
if(!(char_exists(f,c))){
char_warning(f,c);
return ci;
}
ci.wd= ext_xn_over_d(ci.wd,1000000+ex_glyph(p),1000000);
switch(pdf->posstruct->dir){
case dir_TLT:
break;
case dir_TRT:
pos_left(ci.wd);
break;
case dir_LTL:
pos_down(ci.ht);
pos_left(ci.wd);
break;
case dir_RTT:
pos_down(ci.ht);
pos_left(ci.wd/2);
break;
default:
formatted_warning("pdf backend","ignoring bad dir %i when outputting a character",pdf->posstruct->dir);
}
if(has_packet(f,c)){
do_vf_packet(pdf,f,c,ex_glyph);
}else{

backend_out[glyph_node](pdf,f,c,ex_glyph);
}
return ci;
}

/*:3*//*4:*/
#line 75 "./luatexdir/pdf/pdffont.w"

static void pdf_use_font(internal_font_number f,int fontnum)
{
set_font_used(f,true);
if((fontnum> 0)||((fontnum<0)&&(pdf_font_num(-fontnum)> 0))){
set_pdf_font_num(f,fontnum);
}else{
normal_error("pdf backend","bad font id");
}
}

/*:4*//*5:*/
#line 92 "./luatexdir/pdf/pdffont.w"

#define same(n,f,k) (n(f) != NULL && n(k) != NULL && strcmp(n(f), n(k)) == 0)







static boolean font_shareable(internal_font_number f,internal_font_number k)
{
if(font_cidregistry(f)==NULL&&font_cidregistry(k)==NULL&&font_encodingbytes(f)!=2&&font_encodingbytes(k)!=2){
if(font_map(k)!=NULL&&font_map(f)!=NULL&&(same(font_name,k,f))){
return 1;
}
}else if((same(font_filename,k,f)&&same(font_fullname,k,f))){
return 1;
}
return 0;
}

/*:5*//*6:*/
#line 114 "./luatexdir/pdf/pdffont.w"

void pdf_init_font(PDF pdf,internal_font_number f)
{
internal_font_number k;
fm_entry*fm;
int i,l;
if(font_used(f)){
formatted_error("pdf backend","font %i gets initialized twice",(int)f);
}









fm= getfontmap(font_name(f));
if(font_map(f)==NULL&&fm!=NULL){
font_map(f)= fm;
if(is_slantset(fm))
font_slant(f)= fm->slant;
if(is_extendset(fm))
font_extend(f)= fm->extend;
}
i= pdf->head_tab[obj_type_font];
while(i!=0){
k= obj_info(pdf,i);
if(font_shareable(f,k)){
if(pdf_font_num(k)<0)
pdf_use_font(f,pdf_font_num(k));
else
pdf_use_font(f,-k);
return;
}
i= obj_link(pdf,i);
}

l= pdf_create_obj(pdf,obj_type_font,f);
pdf_use_font(f,l);
}

/*:6*//*7:*/
#line 162 "./luatexdir/pdf/pdffont.w"

internal_font_number pdf_set_font(PDF pdf,internal_font_number f)
{
int ff;
if(!font_used(f))
pdf_init_font(pdf,f);
ff= pdf_font_num(f)<0?-pdf_font_num(f):f;
addto_page_resources(pdf,obj_type_font,pdf_font_num(ff));
return ff;
}

/*:7*//*8:*/
#line 173 "./luatexdir/pdf/pdffont.w"

void pdf_include_chars(PDF pdf)
{
str_number s;
unsigned char*k,*j;
internal_font_number f;
scan_font_ident();
f= cur_val;
if(f==null_font)
normal_error("pdf backend","invalid font identifier for 'includechars'");
pdf_check_vf(cur_val);
if(!font_used(f))
pdf_init_font(pdf,f);
scan_toks(false,true);
s= tokens_to_string(def_ref);
delete_token_ref(def_ref);
j= str_string(s)+str_length(s);
for(k= str_string(s);k<j;k++){
pdf_mark_char(f,*k);
}
flush_str(s);
}/*:8*/
