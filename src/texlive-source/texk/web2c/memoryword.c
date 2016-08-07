/*1:*/
#line 20 "./luatexdir/tex/memoryword.w"



#include "ptexlib.h"

/*:1*//*2:*/
#line 28 "./luatexdir/tex/memoryword.w"

#ifdef DEBUG
void print_word(memory_word w)
{

print_int(w.cint);
print_char(' ');
print_scaled(w.cint);
print_char(' ');
print_scaled(round(unity*float_cast(w.gr)));
print_ln();
print_int(w.hh.lhfield);
print_char('=');
print_int(w.hh.b0);
print_char(':');
print_int(w.hh.b1);
print_char(';');
print_int(w.hh.rh);
print_char(' ');
print_int(w.qqqq.b0);
print_char(':');
print_int(w.qqqq.b1);
print_char(':');
print_int(w.qqqq.b2);
print_char(':');
print_int(w.qqqq.b3);
}
#endif/*:2*/
