/*1:*/
#line 20 "./luatexdir/pdf/pdfshipout.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 24 "./luatexdir/pdf/pdfshipout.w"

scaledpos shipbox_refpos;

/*:2*//*3:*/
#line 31 "./luatexdir/pdf/pdfshipout.w"

void ship_out(PDF pdf,halfword p,shipping_mode_e shipping_mode)
{
int j,k;
int post_callback_id;
int pre_callback_id;
posstructure refpoint;
int rule_callback_id= 0;
scaledpos cur= {0,0};
refpoint.pos.h= 0;
refpoint.pos.v= 0;
ensure_output_state(pdf,ST_HEADER_WRITTEN);
fix_o_mode();
init_backend_functionpointers(output_mode_used);
pdf->f_cur= null_font;




if(synctex_par){
if(output_mode_used==OMODE_DVI){
synctexsheet(mag_par);
}else{
synctexsheet(1000);
}
}
pre_callback_id= callback_defined(start_page_number_callback);
post_callback_id= callback_defined(stop_page_number_callback);
if((tracing_output_par> 0)&&(pre_callback_id==0)){
tprint_nl("");
print_ln();
tprint("Completed box being shipped out");
}
global_shipping_mode= shipping_mode;
if(shipping_mode==SHIPPING_PAGE){
if(pre_callback_id> 0)
(void)run_callback(pre_callback_id,"->");
else if(pre_callback_id==0){
if(term_offset> max_print_line-9)
print_ln();
else if((term_offset> 0)||(file_offset> 0))
print_char(' ');
print_char('[');
j= 9;
while((count(j)==0)&&(j> 0))
j--;
for(k= 0;k<=j;k++){
print_int(count(k));
if(k<j)
print_char('.');
}
}
}
if((tracing_output_par> 0)&&shipping_mode==SHIPPING_PAGE){
print_char(']');
update_terminal();
begin_diagnostic();
show_box(p);
end_diagnostic(true);
}

if(shipping_mode==SHIPPING_PAGE&&box_dir(p)!=page_direction_par)
normal_warning("backend","pagedir differs from bodydir, the output may be placed wrongly on the page");






if((height(p)> max_dimen)||(depth(p)> max_dimen)||(height(p)+depth(p)+v_offset_par> max_dimen)||(width(p)+h_offset_par> max_dimen)){
const char*hlp[]= {
"The page just created is more than 18 feet tall or",
"more than 18 feet wide, so I suspect something went wrong.",
NULL
};
tex_error("Huge page cannot be shipped out",hlp);
if(tracing_output_par<=0){
begin_diagnostic();
tprint_nl("The following box has been deleted:");
show_box(p);
end_diagnostic(true);
}
goto DONE;
}
if(height(p)+depth(p)+v_offset_par> max_v)
max_v= height(p)+depth(p)+v_offset_par;
if(width(p)+h_offset_par> max_h)
max_h= width(p)+h_offset_par;

if(global_shipping_mode==SHIPPING_PAGE){
if(page_width_par> 0)
pdf->page_size.h= page_width_par;
else{
switch(page_direction_par){
case dir_TLT:
pdf->page_size.h= width(p)+2*page_left_offset_par;
break;
case dir_TRT:
pdf->page_size.h= width(p)+2*page_right_offset_par;
break;
case dir_LTL:
pdf->page_size.h= height(p)+depth(p)+2*page_left_offset_par;
break;
case dir_RTT:
pdf->page_size.h= height(p)+depth(p)+2*page_right_offset_par;
break;
default:
pdf->page_size.h= width(p)+2*page_left_offset_par;
normal_warning("pdf backend","bad page direction, assuming TLT, case 1");
}
}
if(page_height_par> 0)
pdf->page_size.v= page_height_par;
else{
switch(page_direction_par){
case dir_TLT:
case dir_TRT:
pdf->page_size.v= height(p)+depth(p)+2*page_top_offset_par;
break;
case dir_LTL:
case dir_RTT:
pdf->page_size.v= width(p)+2*page_top_offset_par;
break;
default:
pdf->page_size.v= height(p)+depth(p)+2*page_top_offset_par;
normal_warning("pdf backend","bad page direction, assuming TLT, case 2");
}
}




switch(output_mode_used){
case OMODE_DVI:

refpoint.pos.h= one_true_inch;
refpoint.pos.v= pdf->page_size.v-one_true_inch;
dvi= refpoint.pos;
break;
case OMODE_PDF:
refpoint.pos.h= pdf_h_origin;
refpoint.pos.v= pdf->page_size.v-pdf_v_origin;
break;
default:
normal_error("pdf backend","unknown output mode");
}





switch(page_direction_par){
case dir_TLT:
case dir_LTL:
refpoint.pos.h+= h_offset_par;
refpoint.pos.v-= v_offset_par;
break;
case dir_TRT:
case dir_RTT:
refpoint.pos.h+= pdf->page_size.h-page_right_offset_par-one_true_inch;
refpoint.pos.v-= v_offset_par;
break;
default:
refpoint.pos.h+= h_offset_par;
refpoint.pos.v-= v_offset_par;
normal_warning("pdf backend","bad page direction, assuming TLT, case 3");
}




pdf->posstruct->dir= page_direction_par;
cur.h= 0;
cur.v= height(p);
synch_pos_with_cur(pdf->posstruct,&refpoint,cur);
}else{

pdf->posstruct->dir= box_dir(p);
switch(pdf->posstruct->dir){
case dir_TLT:
case dir_TRT:
pdf->page_size.h= width(p);
pdf->page_size.v= height(p)+depth(p);
break;
case dir_LTL:
case dir_RTT:
pdf->page_size.h= height(p)+depth(p);
pdf->page_size.v= width(p);
break;
default:
pdf->page_size.h= width(p);
pdf->page_size.v= height(p)+depth(p);
normal_warning("pdf backend","bad page direction, assuming TLT, case 4");
}
switch(pdf->posstruct->dir){
case dir_TLT:
pdf->posstruct->pos.h= 0;
pdf->posstruct->pos.v= depth(p);
break;
case dir_TRT:
pdf->posstruct->pos.h= width(p);
pdf->posstruct->pos.v= depth(p);
break;
case dir_LTL:
pdf->posstruct->pos.h= height(p);
pdf->posstruct->pos.v= width(p);
break;
case dir_RTT:
pdf->posstruct->pos.h= depth(p);
pdf->posstruct->pos.v= width(p);
break;
default:
pdf->posstruct->pos.h= 0;
pdf->posstruct->pos.v= depth(p);
normal_warning("pdf backend","bad page direction, assuming TLT, case 5");
}
}

shipbox_refpos= pdf->posstruct->pos;
switch(output_mode_used){
case OMODE_DVI:
dvi_begin_page(pdf);
break;
case OMODE_PDF:
pdf_begin_page(pdf);
break;
default:
normal_error("pdf backend","unknown output mode");
}
rule_callback_id= callback_defined(process_rule_callback);
switch(type(p)){
case vlist_node:
vlist_out(pdf,p,rule_callback_id);
break;
case hlist_node:
hlist_out(pdf,p,rule_callback_id);
break;
default:
normal_error("pdf backend","no vlist or hlist in (xform) shipout");
}
if(shipping_mode==SHIPPING_PAGE)
total_pages++;
cur_s= -1;

switch(output_mode_used){
case OMODE_DVI:
dvi_end_page(pdf);
break;
case OMODE_PDF:
pdf_end_page(pdf);
break;
default:
normal_error("pdf backend","unknown output mode");
}
DONE:
if((tracing_output_par<=0)&&(post_callback_id==0)&&shipping_mode==SHIPPING_PAGE){
print_char(']');
update_terminal();
}
dead_cycles= 0;

if((tracing_stats_par> 1)&&(pre_callback_id==0)){
tprint_nl("Memory usage before: ");
print_int(var_used);
print_char('&');
print_int(dyn_used);
print_char(';');
}
flush_node_list(p);
if((tracing_stats_par> 1)&&(post_callback_id==0)){
tprint(" after: ");
print_int(var_used);
print_char('&');
print_int(dyn_used);
print_ln();
}
if(shipping_mode==SHIPPING_PAGE&&(post_callback_id> 0))
(void)run_callback(post_callback_id,"->");

if(synctex_par)
synctexteehs();
global_shipping_mode= NOT_SHIPPING;
}/*:3*/
