/*2:*/
#line 29 "./luatexdir/utils/managed-sa.w"


#include "ptexlib.h"

/*:2*//*3:*/
#line 33 "./luatexdir/utils/managed-sa.w"

static void store_sa_stack(sa_tree a,int n,sa_tree_item v,int gl)
{
sa_stack_item st;
st.code= n;
st.value= v;
st.level= gl;
if(a->stack==NULL){
a->stack= Mxmalloc_array(sa_stack_item,a->stack_size);
}else if(((a->stack_ptr)+1)>=a->stack_size){
a->stack_size+= a->stack_step;
a->stack= Mxrealloc_array(a->stack,sa_stack_item,a->stack_size);
}
(a->stack_ptr)++;
a->stack[a->stack_ptr]= st;
}

/*:3*//*4:*/
#line 50 "./luatexdir/utils/managed-sa.w"

static void skip_in_stack(sa_tree a,int n)
{
int p= a->stack_ptr;
if(a->stack==NULL)
return;
while(p> 0){
if(a->stack[p].code==n&&a->stack[p].level> 0){
a->stack[p].level= -(a->stack[p].level);
}
p--;
}
}

/*:4*//*5:*/
#line 64 "./luatexdir/utils/managed-sa.w"

sa_tree_item get_sa_item(const sa_tree head,const int n)
{
if(head->tree!=NULL){
register int h= HIGHPART_PART(n);
if(head->tree[h]!=NULL){
register int m= MIDPART_PART(n);
if(head->tree[h][m]!=NULL){
return head->tree[h][m][LOWPART_PART(n)];
}
}
}
return head->dflt;
}

/*:5*//*6:*/
#line 79 "./luatexdir/utils/managed-sa.w"

void set_sa_item(sa_tree head,int n,sa_tree_item v,int gl)
{
int h= HIGHPART_PART(n);
int m= MIDPART_PART(n);
int l= LOWPART_PART(n);
if(head->tree==NULL){
head->tree= (sa_tree_item***)Mxcalloc_array(sa_tree_item**,HIGHPART);
}
if(head->tree[h]==NULL){
head->tree[h]= (sa_tree_item**)Mxcalloc_array(sa_tree_item*,MIDPART);
}
if(head->tree[h][m]==NULL){
int i;
head->tree[h][m]= (sa_tree_item*)Mxmalloc_array(sa_tree_item,LOWPART);
for(i= 0;i<LOWPART;i++){
head->tree[h][m][i]= head->dflt;
}
}
if(gl<=1){
skip_in_stack(head,n);
}else{
store_sa_stack(head,n,head->tree[h][m][l],gl);
}
head->tree[h][m][l]= v;
}

/*:6*//*7:*/
#line 106 "./luatexdir/utils/managed-sa.w"

void rawset_sa_item(sa_tree head,int n,sa_tree_item v)
{
head->tree[HIGHPART_PART(n)][MIDPART_PART(n)][LOWPART_PART(n)]= v;
}

/*:7*//*8:*/
#line 112 "./luatexdir/utils/managed-sa.w"

void clear_sa_stack(sa_tree a)
{
xfree(a->stack);
a->stack_ptr= 0;
a->stack_size= a->stack_step;
}

/*:8*//*9:*/
#line 120 "./luatexdir/utils/managed-sa.w"

void destroy_sa_tree(sa_tree a)
{
if(a==NULL)
return;
if(a->tree!=NULL){
int h,m;
for(h= 0;h<HIGHPART;h++){
if(a->tree[h]!=NULL){
for(m= 0;m<MIDPART;m++){
xfree(a->tree[h][m]);
}
xfree(a->tree[h]);
}
}
xfree(a->tree);
}
xfree(a->stack);
xfree(a);
}

/*:9*//*10:*/
#line 141 "./luatexdir/utils/managed-sa.w"

sa_tree copy_sa_tree(sa_tree b)
{
sa_tree a= (sa_tree)Mxmalloc_array(sa_tree_head,1);
a->stack_step= b->stack_step;
a->stack_size= b->stack_size;
a->stack_type= b->stack_type;
a->dflt= b->dflt;
a->stack= NULL;
a->stack_ptr= 0;
a->tree= NULL;
if(b->tree!=NULL){
int h,m;
a->tree= (sa_tree_item***)Mxcalloc_array(void*,HIGHPART);
for(h= 0;h<HIGHPART;h++){
if(b->tree[h]!=NULL){
a->tree[h]= (sa_tree_item**)Mxcalloc_array(void*,MIDPART);
for(m= 0;m<MIDPART;m++){
if(b->tree[h][m]!=NULL){
a->tree[h][m]= Mxmalloc_array(sa_tree_item,LOWPART);
memcpy(a->tree[h][m],b->tree[h][m],
sizeof(sa_tree_item)*LOWPART);
}
}
}
}
}
return a;
}

/*:10*//*11:*/
#line 177 "./luatexdir/utils/managed-sa.w"




sa_tree new_sa_tree(int size,int type,sa_tree_item dflt)
{
sa_tree_head*a;
a= (sa_tree_head*)xmalloc(sizeof(sa_tree_head));
a->dflt= dflt;
a->stack= NULL;
a->tree= (sa_tree_item***)Mxcalloc_array(sa_tree_item**,HIGHPART);
a->tree[0]= (sa_tree_item**)Mxcalloc_array(sa_tree_item*,MIDPART);
a->stack_size= size;
a->stack_step= size;
a->stack_type= type;
a->stack_ptr= 0;

return(sa_tree)a;
}

/*:11*//*12:*/
#line 197 "./luatexdir/utils/managed-sa.w"

void restore_sa_stack(sa_tree head,int gl)
{
sa_stack_item st;
if(head->stack==NULL)
return;
while(head->stack_ptr> 0&&abs(head->stack[head->stack_ptr].level)>=gl){
st= head->stack[head->stack_ptr];
if(st.level> 0){
rawset_sa_item(head,st.code,st.value);
}
(head->stack_ptr)--;
}
}

/*:12*//*13:*/
#line 212 "./luatexdir/utils/managed-sa.w"

void dump_sa_tree(sa_tree a,const char*name)
{
boolean f;
int x,n;
int h,m,l;
dump_int(a->stack_step);
x= a->dflt.int_value;
dump_int(x);
if(a->tree!=NULL){
dump_int(1);
n= a->stack_type;
dump_int(n);

for(h= 0;h<HIGHPART;h++){
if(a->tree[h]!=NULL){
f= 1;
dump_qqqq(f);
for(m= 0;m<MIDPART;m++){
if(a->tree[h][m]!=NULL){
f= 1;
dump_qqqq(f);
for(l= 0;l<LOWPART;l++){
if(n==2){
x= a->tree[h][m][l].dump_uint.value_1;
dump_int(x);
x= a->tree[h][m][l].dump_uint.value_2;
dump_int(x);
}else{
x= a->tree[h][m][l].uint_value;
dump_int(x);
}
}
}else{
f= 0;
dump_qqqq(f);
}
}
}else{
f= 0;
dump_qqqq(f);
}
}
}else{
dump_int(0);
}
}

/*:13*//*14:*/
#line 260 "./luatexdir/utils/managed-sa.w"

sa_tree undump_sa_tree(const char*name)
{
int x,n;
int h,m,l;
boolean f;
sa_tree a= (sa_tree)Mxmalloc_array(sa_tree_head,1);
undump_int(x);
a->stack_step= x;
a->stack_size= x;
undump_int(x);
a->dflt.int_value= x;
a->stack= Mxmalloc_array(sa_stack_item,a->stack_size);
a->stack_ptr= 0;
a->tree= NULL;
undump_int(x);
if(x==0)
return a;
a->tree= (sa_tree_item***)Mxcalloc_array(void*,HIGHPART);
undump_int(n);
a->stack_type= n;

for(h= 0;h<HIGHPART;h++){
undump_qqqq(f);
if(f> 0){
a->tree[h]= (sa_tree_item**)Mxcalloc_array(void*,MIDPART);
for(m= 0;m<MIDPART;m++){
undump_qqqq(f);
if(f> 0){
a->tree[h][m]= Mxmalloc_array(sa_tree_item,LOWPART);
for(l= 0;l<LOWPART;l++){
if(n==2){
undump_int(x);
a->tree[h][m][l].dump_uint.value_1= x;
undump_int(x);
a->tree[h][m][l].dump_uint.value_2= x;
}else{
undump_int(x);
a->tree[h][m][l].uint_value= x;
}
}
}
}
}
}
return a;
}/*:14*/
