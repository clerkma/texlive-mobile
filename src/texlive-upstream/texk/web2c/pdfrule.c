/*1:*/
#line 20 "./luatexdir/pdf/pdfrule.w"

#include "ptexlib.h"
#include "pdf/pdfpage.h"

/*:1*//*2:*/
#line 24 "./luatexdir/pdf/pdfrule.w"




void pdf_place_rule(PDF pdf,halfword q,scaledpos size,int callback_id)
{
pdfpos dim;
pdfstructure*p= pdf->pstruct;
scaledpos pos= pdf->posstruct->pos;

if(subtype(q)==box_rule){
pdf_place_form(pdf,q);
}else if(subtype(q)==image_rule){
pdf_place_image(pdf,q);
}else if(subtype(q)==empty_rule){

}else if(subtype(q)==user_rule){
if(callback_id!=0){
pdf_goto_pagemode(pdf);
pdf_puts(pdf,"q\n");
pdf_set_pos_temp(pdf,pos);
run_callback(callback_id,"Ndd->",q,size.h,size.v);
pdf_puts(pdf,"\nQ\n");
}
}else{

pdf_goto_pagemode(pdf);
dim.h.m= i64round(size.h*p->k1);
dim.h.e= p->pdf.h.e;
dim.v.m= i64round(size.v*p->k1);
dim.v.e= p->pdf.v.e;
pdf_puts(pdf,"q\n");
if(size.v<=one_bp){
pos.v+= i64round(0.5*size.v);
pdf_set_pos_temp(pdf,pos);
pdf_puts(pdf,"[]0 d 0 J ");
print_pdffloat(pdf,dim.v);
pdf_puts(pdf," w 0 0 m ");
print_pdffloat(pdf,dim.h);
pdf_puts(pdf," 0 l S\n");
}else if(size.h<=one_bp){
pos.h+= i64round(0.5*size.h);
pdf_set_pos_temp(pdf,pos);
pdf_puts(pdf,"[]0 d 0 J ");
print_pdffloat(pdf,dim.h);
pdf_puts(pdf," w 0 0 m 0 ");
print_pdffloat(pdf,dim.v);
pdf_puts(pdf," l S\n");
}else{
pdf_set_pos_temp(pdf,pos);
pdf_puts(pdf,"0 0 ");
print_pdffloat(pdf,dim.h);
pdf_out(pdf,' ');
print_pdffloat(pdf,dim.v);
pdf_puts(pdf," re f\n");
}
pdf_puts(pdf,"Q\n");
}
}/*:2*/
