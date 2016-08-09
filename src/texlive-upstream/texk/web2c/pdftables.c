/*1:*/
#line 20 "./luatexdir/pdf/pdftables.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 24 "./luatexdir/pdf/pdftables.w"

const char*pdf_obj_typenames[PDF_OBJ_TYPE_MAX+1]= {
"font","outline","dest","obj","xform","ximage","thread",
"pagestream","page","pages","catalog","info","link","annot","annots",
"bead","beads","objstm","others"
};

int pdf_last_annot;
int pdf_last_link;
int pdf_last_obj;
int pdf_retval;

/*:2*//*3:*/
#line 37 "./luatexdir/pdf/pdftables.w"

static int compare_info(const void*pa,const void*pb,void*param)
{
const oentry*a= (const oentry*)pa;
const oentry*b= (const oentry*)pb;
(void)param;
if(a->u_type==b->u_type){
if(a->u_type==union_type_int)
return((a->u.int0<b->u.int0?-1:(a->u.int0> b->u.int0?1:0)));
else
return strcmp(a->u.str0,b->u.str0);
}else if(a->u_type==union_type_int){
return-1;
}else{
return 1;
}
}

static void avl_put_obj(PDF pdf,int t,oentry*oe)
{
void**pp;
if(pdf->obj_tree[t]==NULL){
pdf->obj_tree[t]= avl_create(compare_info,NULL,&avl_xallocator);
if(pdf->obj_tree[t]==NULL)
formatted_error("pdf backend","avl_create() pdf->obj_tree failed");
}
pp= avl_probe(pdf->obj_tree[t],oe);
if(pp==NULL)
formatted_error("pdf backend","avl_probe() out of memory in insertion");
}

static void avl_put_int_obj(PDF pdf,int int0,int objptr,int t)
{
oentry*oe= xtalloc(1,oentry);
oe->u.int0= int0;
oe->u_type= union_type_int;
oe->objptr= objptr;
avl_put_obj(pdf,t,oe);
}

static void avl_put_str_obj(PDF pdf,char*str0,int objptr,int t)
{
oentry*oe= xtalloc(1,oentry);
oe->u.str0= str0;
oe->u_type= union_type_cstring;
oe->objptr= objptr;
avl_put_obj(pdf,t,oe);
}

static int avl_find_int_obj(PDF pdf,int t,int i)
{
oentry*p;
oentry tmp;
tmp.u.int0= i;
tmp.u_type= union_type_int;
if(pdf->obj_tree[t]==NULL)
return 0;
p= (oentry*)avl_find(pdf->obj_tree[t],&tmp);
if(p==NULL)
return 0;
return p->objptr;
}

static int avl_find_str_obj(PDF pdf,int t,char*s)
{
oentry*p;
oentry tmp;
tmp.u.str0= s;
tmp.u_type= union_type_cstring;
if(pdf->obj_tree[t]==NULL)
return 0;
p= (oentry*)avl_find(pdf->obj_tree[t],&tmp);
if(p==NULL)
return 0;
return p->objptr;
}

/*:3*//*4:*/
#line 116 "./luatexdir/pdf/pdftables.w"

int pdf_create_obj(PDF pdf,int t,int i)
{
int a;
char*ss= NULL;
if(pdf->obj_ptr==sup_obj_tab_size)
overflow("indirect objects table size",(unsigned)pdf->obj_tab_size);
if(pdf->obj_ptr==pdf->obj_tab_size){
a= pdf->obj_tab_size/5;
if(pdf->obj_tab_size<sup_obj_tab_size-a)
pdf->obj_tab_size= pdf->obj_tab_size+a;
else
pdf->obj_tab_size= sup_obj_tab_size;
pdf->obj_tab= xreallocarray(pdf->obj_tab,obj_entry,(unsigned)pdf->obj_tab_size);
}
pdf->obj_ptr++;
obj_info(pdf,pdf->obj_ptr)= i;
obj_type(pdf,pdf->obj_ptr)= t;
set_obj_fresh(pdf,pdf->obj_ptr);
obj_aux(pdf,pdf->obj_ptr)= 0;
if(i<0){
ss= makecstring(-i);
avl_put_str_obj(pdf,ss,pdf->obj_ptr,t);
}else if(i> 0)
avl_put_int_obj(pdf,i,pdf->obj_ptr,t);
if(t<=HEAD_TAB_MAX){
obj_link(pdf,pdf->obj_ptr)= pdf->head_tab[t];
pdf->head_tab[t]= pdf->obj_ptr;
if((t==obj_type_dest)&&(i<0))
append_dest_name(pdf,makecstring(-obj_info(pdf,pdf->obj_ptr)),pdf->obj_ptr);
}
return pdf->obj_ptr;
}

/*:4*//*5:*/
#line 150 "./luatexdir/pdf/pdftables.w"

int find_obj(PDF pdf,int t,int i,boolean byname)
{
char*ss= NULL;
int ret;
if(byname){
ss= makecstring(i);
ret= avl_find_str_obj(pdf,t,ss);
free(ss);
}else{
ret= avl_find_int_obj(pdf,t,i);
}
return ret;
}

/*:5*//*6:*/
#line 172 "./luatexdir/pdf/pdftables.w"

int pdf_get_obj(PDF pdf,int t,int i,boolean byname)
{
int r;
str_number s;
if(byname> 0){
s= tokens_to_string(i);
r= find_obj(pdf,t,s,true);
}else{
s= 0;
r= find_obj(pdf,t,i,false);
}
if(r==0){
if(byname> 0){
r= pdf_create_obj(pdf,t,-s);
s= 0;
}else{
r= pdf_create_obj(pdf,t,i);
}
if(t==obj_type_dest)
set_obj_dest_ptr(pdf,r,null);
}
if(s!=0)
flush_str(s);
return r;
}

/*:6*//*7:*/
#line 200 "./luatexdir/pdf/pdftables.w"

void check_obj_exists(PDF pdf,int objnum)
{
if(objnum<0||objnum> pdf->obj_ptr)
normal_error("pdf backend","cannot find referenced object");
}

void check_obj_type(PDF pdf,int t,int objnum)
{
int u;
check_obj_exists(pdf,objnum);
u= obj_type(pdf,objnum);
if(t!=u){
formatted_error("pdf backend","referenced object has wrong type %s; should be %s",
pdf_obj_typenames[u],pdf_obj_typenames[t]);
}
}

/*:7*//*8:*/
#line 218 "./luatexdir/pdf/pdftables.w"

void set_rect_dimens(PDF pdf,halfword p,halfword parent_box,scaledpos cur,scaled_whd alt_rule,scaled margin)
{
scaledpos ll,ur;
scaledpos pos_ll,pos_ur,tmp;
posstructure localpos;
localpos.dir= pdf->posstruct->dir;
ll.h= 0;
if(is_running(alt_rule.dp))
ll.v= depth(parent_box)-cur.v;
else
ll.v= alt_rule.dp;
if(is_running(alt_rule.wd))
ur.h= width(parent_box)-cur.h;
else
ur.h= alt_rule.wd;
if(is_running(alt_rule.ht))
ur.v= -height(parent_box)-cur.v;
else
ur.v= -alt_rule.ht;
synch_pos_with_cur(&localpos,pdf->posstruct,ll);
pos_ll= localpos.pos;
synch_pos_with_cur(&localpos,pdf->posstruct,ur);
pos_ur= localpos.pos;
if(pos_ll.h> pos_ur.h){
tmp.h= pos_ll.h;
pos_ll.h= pos_ur.h;
pos_ur.h= tmp.h;
}
if(pos_ll.v> pos_ur.v){
tmp.v= pos_ll.v;
pos_ll.v= pos_ur.v;
pos_ur.v= tmp.v;
}
if(global_shipping_mode==SHIPPING_PAGE&&matrixused()){
matrixtransformrect(pos_ll.h,pos_ll.v,pos_ur.h,pos_ur.v);
pos_ll.h= getllx();
pos_ll.v= getlly();
pos_ur.h= geturx();
pos_ur.v= getury();
}
pdf_ann_left(p)= pos_ll.h-margin;
pdf_ann_bottom(p)= pos_ll.v-margin;
pdf_ann_right(p)= pos_ur.h+margin;
pdf_ann_top(p)= pos_ur.v+margin;
}

/*:8*//*9:*/
#line 265 "./luatexdir/pdf/pdftables.w"

void libpdffinish(PDF pdf)
{
strbuf_free(pdf->fb);
xfree(pdf->job_id_string);
fm_free();
t1_free();
enc_free();
epdf_free();
ttf_free();
sfd_free();
glyph_unicode_free();
zip_free(pdf);
}/*:9*/
