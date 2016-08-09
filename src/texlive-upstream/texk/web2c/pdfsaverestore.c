/*1:*/
#line 20 "./luatexdir/pdf/pdfsaverestore.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 24 "./luatexdir/pdf/pdfsaverestore.w"

pos_entry*pos_stack= 0;
int pos_stack_size= 0;
int pos_stack_used= 0;

/*:2*//*3:*/
#line 29 "./luatexdir/pdf/pdfsaverestore.w"

static void checkpdfsave(scaledpos pos)
{
pos_entry*new_stack;
if(pos_stack_used>=pos_stack_size){
pos_stack_size+= STACK_INCREMENT;
new_stack= xtalloc((unsigned)pos_stack_size,pos_entry);
memcpy((void*)new_stack,(void*)pos_stack,(unsigned)pos_stack_used*sizeof(pos_entry));
xfree(pos_stack);
pos_stack= new_stack;
}
pos_stack[pos_stack_used].pos.h= pos.h;
pos_stack[pos_stack_used].pos.v= pos.v;
if(global_shipping_mode==SHIPPING_PAGE){
pos_stack[pos_stack_used].matrix_stack= matrix_stack_used;
}
pos_stack_used++;
}

/*:3*//*4:*/
#line 48 "./luatexdir/pdf/pdfsaverestore.w"

static void checkpdfrestore(scaledpos pos)
{
scaledpos diff;
if(pos_stack_used==0){
normal_warning("pdf backend","'restore' is missing a 'save'");
return;
}
pos_stack_used--;
diff.h= pos.h-pos_stack[pos_stack_used].pos.h;
diff.v= pos.v-pos_stack[pos_stack_used].pos.v;
if(diff.h!=0||diff.v!=0){
formatted_warning("pdf backend","misplaced 'restore' by (%dsp, %dsp)",(int)diff.h,(int)diff.v);
}
if(global_shipping_mode==SHIPPING_PAGE){
matrix_stack_used= pos_stack[pos_stack_used].matrix_stack;
}
}

/*:4*//*5:*/
#line 67 "./luatexdir/pdf/pdfsaverestore.w"

void pdf_out_save(PDF pdf,halfword p)
{
(void)p;
checkpdfsave(pdf->posstruct->pos);
pdf_literal(pdf,'q',set_origin,false);
}

/*:5*//*6:*/
#line 75 "./luatexdir/pdf/pdfsaverestore.w"

void pdf_out_restore(PDF pdf,halfword p)
{
(void)p;
checkpdfrestore(pdf->posstruct->pos);
pdf_literal(pdf,'Q',set_origin,false);
}/*:6*/
