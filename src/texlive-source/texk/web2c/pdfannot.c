/*1:*/
#line 20 "./luatexdir/pdf/pdfannot.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 24 "./luatexdir/pdf/pdfannot.w"

#define tail cur_list.tail_field

void do_annot(PDF pdf,halfword p,halfword parent_box,scaledpos cur)
{
scaled_whd alt_rule;
int k;
if(global_shipping_mode==SHIPPING_FORM)
normal_error("pdf backend","annotations cannot be inside an xform");
if(doing_leaders)
return;
if(is_obj_scheduled(pdf,pdf_annot_objnum(p))){
k= pdf_create_obj(pdf,obj_type_annot,0);
obj_annot_ptr(pdf,pdf_annot_objnum(p))= p;
pdf_annot_objnum(p)= k;
}
alt_rule.wd= width(p);
alt_rule.ht= height(p);
alt_rule.dp= depth(p);
set_rect_dimens(pdf,p,parent_box,cur,alt_rule,0);
obj_annot_ptr(pdf,pdf_annot_objnum(p))= p;
addto_page_resources(pdf,obj_type_annot,pdf_annot_objnum(p));
}

/*:2*//*3:*/
#line 50 "./luatexdir/pdf/pdfannot.w"
void new_annot_whatsit(small_number w)
{
scaled_whd alt_rule;
new_whatsit(w);
alt_rule= scan_alt_rule();
set_width(tail,alt_rule.wd);
set_height(tail,alt_rule.ht);
set_depth(tail,alt_rule.dp);
if((w==pdf_thread_node)||(w==pdf_start_thread_node)){
if(scan_keyword("attr")){
scan_toks(false,true);
set_pdf_thread_attr(tail,def_ref);
}else{
set_pdf_thread_attr(tail,null);
}
}
}

/*:3*//*4:*/
#line 70 "./luatexdir/pdf/pdfannot.w"
void scan_annot(PDF pdf)
{
int k;
if(scan_keyword("reserveobjnum")){
k= pdf_create_obj(pdf,obj_type_annot,0);

get_x_token();
if(cur_cmd!=spacer_cmd)
back_input();
}else{
if(scan_keyword("useobjnum")){
scan_int();
k= cur_val;
check_obj_type(pdf,obj_type_annot,k);
if(obj_annot_ptr(pdf,k)!=0)
normal_error("pdf backend","annot object in use");
}else{
k= pdf_create_obj(pdf,obj_type_annot,0);
}
new_annot_whatsit(pdf_annot_node);
obj_annot_ptr(pdf,k)= tail;
set_pdf_annot_objnum(tail,k);
scan_toks(false,true);
set_pdf_annot_data(tail,def_ref);
}
pdf_last_annot= k;
}/*:4*/
