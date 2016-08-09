/*1:*/
#line 20 "./luatexdir/pdf/pdflink.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 28 "./luatexdir/pdf/pdflink.w"

void push_link_level(PDF pdf,halfword p)
{
if(pdf->link_stack_ptr>=pdf_max_link_level)
overflow("pdf link stack size",pdf_max_link_level);
pdf->link_stack_ptr++;
pdf->link_stack[pdf->link_stack_ptr].nesting_level= cur_s;
pdf->link_stack[pdf->link_stack_ptr].link_node= copy_node_list(p);
pdf->link_stack[pdf->link_stack_ptr].ref_link_node= p;
}

/*:2*//*3:*/
#line 39 "./luatexdir/pdf/pdflink.w"

void pop_link_level(PDF pdf)
{
flush_node_list(pdf->link_stack[pdf->link_stack_ptr].link_node);
pdf->link_stack_ptr--;
}

/*:3*//*4:*/
#line 46 "./luatexdir/pdf/pdflink.w"

void do_link(PDF pdf,halfword p,halfword parent_box,scaledpos cur)
{
scaled_whd alt_rule;
int k;
if(type(p)==vlist_node)
normal_error("pdf backend","'startlink' ended up in vlist");
if(global_shipping_mode==SHIPPING_FORM)
normal_error("pdf backend","link annotations cannot be inside an xform");
if(is_obj_scheduled(pdf,pdf_link_objnum(p)))
pdf_link_objnum(p)= pdf_create_obj(pdf,obj_type_others,0);
push_link_level(pdf,p);
alt_rule.wd= width(p);
alt_rule.ht= height(p);
alt_rule.dp= depth(p);
set_rect_dimens(pdf,p,parent_box,cur,alt_rule,pdf_link_margin);
obj_annot_ptr(pdf,pdf_link_objnum(p))= p;
k= pdf_link_objnum(p);
set_obj_scheduled(pdf,pdf_link_objnum(p));
addto_page_resources(pdf,obj_type_link,k);
}

/*:4*//*5:*/
#line 68 "./luatexdir/pdf/pdflink.w"

void end_link(PDF pdf,halfword p)
{
halfword q;
scaledpos pos= pdf->posstruct->pos;
if(type(p)==vlist_node)
normal_error("pdf backend","'endlink' ended up in vlist");
if(pdf->link_stack_ptr<1)
normal_error("pdf backend","pdf link_stack empty, 'endlink' used without 'startlink'");
if(pdf->link_stack[pdf->link_stack_ptr].nesting_level!=cur_s)
normal_error("pdf backend","'endlink' ended up in different nesting level than 'startlink'");





if(is_running(width(pdf->link_stack[pdf->link_stack_ptr].link_node))){
q= pdf->link_stack[pdf->link_stack_ptr].ref_link_node;
if(global_shipping_mode==SHIPPING_PAGE&&matrixused()){
matrixrecalculate(pos.h+pdf_link_margin);
pdf_ann_left(q)= getllx()-pdf_link_margin;
pdf_ann_top(q)= getlly()-pdf_link_margin;
pdf_ann_right(q)= geturx()+pdf_link_margin;
pdf_ann_bottom(q)= getury()+pdf_link_margin;
}else{
switch(pdf->posstruct->dir){
case dir_TLT:
pdf_ann_right(q)= pos.h+pdf_link_margin;
break;
case dir_TRT:
pdf_ann_left(q)= pos.h-pdf_link_margin;
break;
case dir_LTL:
case dir_RTT:
pdf_ann_bottom(q)= pos.v-pdf_link_margin;
break;
default:
pdf_ann_right(q)= pos.h+pdf_link_margin;
formatted_warning("pdf backend","forcing bad dir %i to TLT in link",pdf->posstruct->dir);
}
}
}
pop_link_level(pdf);
}

/*:5*//*7:*/
#line 121 "./luatexdir/pdf/pdflink.w"

void append_link(PDF pdf,halfword parent_box,scaledpos cur,small_number i)
{
halfword p;
int k;
scaled_whd alt_rule;
p= copy_node(pdf->link_stack[(int)i].link_node);
pdf->link_stack[(int)i].ref_link_node= p;
subtype(p)= pdf_link_data_node;
alt_rule.wd= width(p);
alt_rule.ht= height(p);
alt_rule.dp= depth(p);
set_rect_dimens(pdf,p,parent_box,cur,alt_rule,pdf_link_margin);
k= pdf_create_obj(pdf,obj_type_others,0);
obj_annot_ptr(pdf,k)= p;
set_obj_scheduled(pdf,pdf_link_objnum(p));
addto_page_resources(pdf,obj_type_link,k);
}

/*:7*//*8:*/
#line 140 "./luatexdir/pdf/pdflink.w"

void scan_startlink(PDF pdf)
{
int k;
halfword r;
if(abs(cur_list.mode_field)==vmode)
normal_error("pdf backend","startlink cannot be used in vertical mode");
k= pdf_create_obj(pdf,obj_type_others,0);
new_annot_whatsit(pdf_start_link_node);
set_pdf_link_attr(cur_list.tail_field,null);
if(scan_keyword("attr")){
scan_toks(false,true);
set_pdf_link_attr(cur_list.tail_field,def_ref);
}
r= scan_action(pdf);
set_pdf_link_action(cur_list.tail_field,r);
set_pdf_link_objnum(cur_list.tail_field,k);
pdf_last_link= k;






}/*:8*/
