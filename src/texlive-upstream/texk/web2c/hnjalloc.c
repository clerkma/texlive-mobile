/*1:*/
#line 38 "./luatexdir/lang/hnjalloc.w"


#include <stdlib.h> 
#include <stdio.h> 
#include "lang/hnjalloc.h"

void*hnj_malloc(int size)
{
void*p;

p= malloc((size_t)size);
if(p==NULL){
fprintf(stderr,"can't allocate %d bytes\n",size);
exit(1);
}
return p;
}

void*hnj_realloc(void*p,int size)
{
p= realloc(p,(size_t)size);
if(p==NULL){
fprintf(stderr,"can't allocate %d bytes\n",size);
exit(1);
}
return p;
}

void hnj_free(void*p)
{
free(p);
}/*:1*/
