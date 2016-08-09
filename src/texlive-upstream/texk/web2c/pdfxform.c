/*1:*/
#line 20 "./luatexdir/pdf/pdfxform.w"

#include "ptexlib.h"
#include "pdf/pdfpage.h"

/*:1*//*2:*/
#line 24 "./luatexdir/pdf/pdfxform.w"

int pdf_cur_form;

void pdf_place_form(PDF pdf,halfword p)
{
scaled_whd nat,tex;
scaled x,y;
pdffloat cm[6];
pdfstructure*q= pdf->pstruct;
int r= 6;
int objnum= rule_index(p);
nat.wd= obj_xform_width(pdf,objnum);
nat.ht= obj_xform_height(pdf,objnum);
nat.dp= obj_xform_depth(pdf,objnum);

tex.wd= width(p);
tex.ht= height(p);
tex.dp= depth(p);
if(nat.wd!=tex.wd||nat.ht!=tex.ht||nat.dp!=tex.dp){
x= ext_xn_over_d(ten_pow[r],tex.wd,nat.wd);
y= ext_xn_over_d(ten_pow[r],tex.dp+tex.ht,nat.dp+nat.ht);
}else
x= y= ten_pow[r];
setpdffloat(cm[0],x,r);
setpdffloat(cm[1],0,r);
setpdffloat(cm[2],0,r);
setpdffloat(cm[3],y,r);
pdf_goto_pagemode(pdf);
(void)calc_pdfpos(q,pdf->posstruct->pos);
cm[4]= q->cm[4];
cm[5]= q->cm[5];
pdf_puts(pdf,"q\n");
pdf_print_cm(pdf,cm);
pdf_printf(pdf,"/Fm%d",(int)obj_info(pdf,objnum));
pdf_print_resname_prefix(pdf);
pdf_puts(pdf," Do\nQ\n");
addto_page_resources(pdf,obj_type_xform,objnum);
}



/*:2*//*3:*/
#line 65 "./luatexdir/pdf/pdfxform.w"

void scan_pdfxform(PDF pdf)
{
int k;
halfword p;
pdf->xform_count++;
k= pdf_create_obj(pdf,obj_type_xform,pdf->xform_count);
set_obj_data_ptr(pdf,k,pdf_get_mem(pdf,pdfmem_xform_size));
if(scan_keyword("type")){
scan_int();
set_obj_xform_type(pdf,k,cur_val);
}else{
set_obj_xform_type(pdf,k,0);
}
if(scan_keyword("attr")){
scan_toks(false,true);
set_obj_xform_attr(pdf,k,def_ref);
}else{
set_obj_xform_attr(pdf,k,null);
}
set_obj_xform_attr_str(pdf,k,null);
if(scan_keyword("resources")){
scan_toks(false,true);
set_obj_xform_resources(pdf,k,def_ref);
}else{
set_obj_xform_resources(pdf,k,null);
}
set_obj_xform_resources_str(pdf,k,null);
scan_int();
p= box(cur_val);
if(p==null)
normal_error("pdf backend","xforms cannot be used with a void box");
set_obj_xform_box(pdf,k,p);
set_obj_xform_width(pdf,k,width(p));
set_obj_xform_height(pdf,k,height(p));
set_obj_xform_depth(pdf,k,depth(p));
box(cur_val)= null;
last_saved_box_index= k;
}

/*:3*//*4:*/
#line 105 "./luatexdir/pdf/pdfxform.w"

void scan_pdfrefxform(PDF pdf)
{
scaled_whd alt_rule,dim,nat;
alt_rule= scan_alt_rule();
scan_int();
check_obj_type(pdf,obj_type_xform,cur_val);
tail_append(new_rule(box_rule));
nat.wd= obj_xform_width(pdf,cur_val);
nat.ht= obj_xform_height(pdf,cur_val);
nat.dp= obj_xform_depth(pdf,cur_val);
if(alt_rule.wd!=null_flag||alt_rule.ht!=null_flag||alt_rule.dp!=null_flag){
dim= tex_scale(nat,alt_rule);
}else{
dim= nat;
}
width(tail_par)= dim.wd;
height(tail_par)= dim.ht;
depth(tail_par)= dim.dp;
rule_index(tail_par)= cur_val;
}/*:4*/
