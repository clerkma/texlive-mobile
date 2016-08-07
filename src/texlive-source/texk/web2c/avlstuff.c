/*2:*/
#line 23 "./luatexdir/utils/avlstuff.w"



#include "ptexlib.h"
#include "utils/avl.h"

/*:2*//*3:*/
#line 30 "./luatexdir/utils/avlstuff.w"

static void*avl_xmalloc(struct libavl_allocator*allocator,size_t size)
{
assert(allocator!=NULL&&size> 0);
return xmalloc((unsigned)size);
}

static void avl_xfree(struct libavl_allocator*allocator,void*block)
{
assert(allocator!=NULL&&block!=NULL);
xfree(block);
}

struct libavl_allocator avl_xallocator= {
avl_xmalloc,
avl_xfree
};

/*:3*//*4:*/
#line 49 "./luatexdir/utils/avlstuff.w"

int comp_int_entry(const void*pa,const void*pb,void*p)
{
(void)p;
cmp_return(*(const int*)pa,*(const int*)pb);
return 0;
}

int comp_string_entry(const void*pa,const void*pb,void*p)
{
(void)p;
return strcmp((const char*)pa,(const char*)pb);
}/*:4*/
