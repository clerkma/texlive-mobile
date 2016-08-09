/*1:*/
#line 21 "./luatexdir/tex/mathcodes.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 26 "./luatexdir/tex/mathcodes.w"

static sa_tree mathcode_head= NULL;



#define MATHCODESTACK 8
#define MATHCODEDEFAULT 0xFFFFFFFF
#define MATHCODEACTIVE  0xFFFFFFFE

/*:2*//*3:*/
#line 36 "./luatexdir/tex/mathcodes.w"

static sa_tree delcode_head= NULL;

#define DELCODESTACK 4
#define DELCODEDEFAULT 0xFFFFFFFF

/*:3*//*4:*/
#line 44 "./luatexdir/tex/mathcodes.w"

#define print_hex_digit(A) do {                 \
    if ((A)>=10) print_char('A'+(A)-10);        \
    else print_char('0'+(A));                   \
  } while (0)

#define two_hex(A) do {       \
    print_hex_digit((A)/16);  \
    print_hex_digit((A)%16);  \
  } while (0)

#define four_hex(A) do {      \
    two_hex((A)/256);         \
    two_hex((A)%256);         \
  } while (0)

#define six_hex(A) do {       \
    two_hex((A)/65536);       \
    two_hex(((A)%65536)/256); \
    two_hex((A)%256);         \
  } while (0)








/*:4*//*5:*/
#line 73 "./luatexdir/tex/mathcodes.w"

mathcodeval mathchar_from_integer(int value,int extcode)
{
mathcodeval mval;
if(extcode==tex_mathcode){

mval.class_value= (value/0x1000);
mval.family_value= ((value%0x1000)/0x100);
mval.character_value= (value%0x100);
}else{
int mfam= (value/0x200000)&0x7FF;
mval.class_value= mfam%0x08;
mval.family_value= mfam/0x08;
mval.character_value= value&0x1FFFFF;
}
return mval;
}

/*:5*//*6:*/
#line 91 "./luatexdir/tex/mathcodes.w"

void show_mathcode_value_old(int value)
{
print_char('"');
four_hex(value);
}
void show_mathcode_value(mathcodeval c)
{
print_char('"');
print_hex_digit(c.class_value);
print_char('"');
two_hex(c.family_value);
print_char('"');
six_hex(c.character_value);
}

/*:6*//*7:*/
#line 107 "./luatexdir/tex/mathcodes.w"

static void show_mathcode(int n)
{
mathcodeval c= get_math_code(n);
tprint_esc("Umathcode");
print_int(n);
print_char('=');
show_mathcode_value(c);
}

/*:7*//*8:*/
#line 117 "./luatexdir/tex/mathcodes.w"

static void unsavemathcode(quarterword gl)
{
sa_stack_item st;
if(mathcode_head->stack==NULL)
return;
while(mathcode_head->stack_ptr> 0&&abs(mathcode_head->stack[mathcode_head->stack_ptr].level)>=gl){
st= mathcode_head->stack[mathcode_head->stack_ptr];
if(st.level> 0){
rawset_sa_item(mathcode_head,st.code,st.value);
if(tracing_restores_par> 1){
begin_diagnostic();
print_char('{');
tprint("restoring");
print_char(' ');
show_mathcode(st.code);
print_char('}');
end_diagnostic(false);
}
}
(mathcode_head->stack_ptr)--;
}
}

/*:8*//*9:*/
#line 141 "./luatexdir/tex/mathcodes.w"

void set_math_code(int n,int mathclass,int mathfamily,int mathcharacter,quarterword level)
{
sa_tree_item v;
if(mathclass==8&&mathfamily==0&&mathcharacter==0){
v.uint_value= MATHCODEACTIVE;
}else{
v.math_code_value.class_value= mathclass;
v.math_code_value.family_value= mathfamily;
v.math_code_value.character_value= mathcharacter;
}
set_sa_item(mathcode_head,n,v,level);
if(tracing_assigns_par> 1){
begin_diagnostic();
print_char('{');
tprint("assigning");
print_char(' ');
show_mathcode(n);
print_char('}');
end_diagnostic(false);
}
}

/*:9*//*10:*/
#line 164 "./luatexdir/tex/mathcodes.w"



mathcodeval get_math_code(int n)
{
mathcodeval d;
sa_tree_item v= get_sa_item(mathcode_head,n);
if(v.uint_value==MATHCODEDEFAULT){
d.class_value= 0;
d.family_value= 0;
d.character_value= n;
}else if(v.uint_value==MATHCODEACTIVE){
d.class_value= 8;
d.family_value= 0;
d.character_value= 0;
}else{
d.class_value= v.math_code_value.class_value;
if(d.class_value==8){
d.family_value= 0;
d.character_value= n;
}else{
d.family_value= v.math_code_value.family_value;
d.character_value= v.math_code_value.character_value;
}
}
return d;
}

/*:10*//*11:*/
#line 192 "./luatexdir/tex/mathcodes.w"

int get_math_code_num(int n)
{
mathcodeval d= get_math_code(n);
return(d.class_value+(d.family_value*8))*(65536*32)+d.character_value;
}

/*:11*//*12:*/
#line 199 "./luatexdir/tex/mathcodes.w"

static void initializemathcode(void)
{
sa_tree_item sa_value= {0};
sa_value.uint_value= MATHCODEDEFAULT;
mathcode_head= new_sa_tree(MATHCODESTACK,1,sa_value);
}

static void dumpmathcode(void)
{
dump_sa_tree(mathcode_head,"mathcodes");
}

static void undumpmathcode(void)
{
mathcode_head= undump_sa_tree("mathcodes");
}

/*:12*//*13:*/
#line 217 "./luatexdir/tex/mathcodes.w"

static void show_delcode(int n)
{
delcodeval c;
c= get_del_code(n);
tprint_esc("Udelcode");
print_int(n);
print_char('=');
if(c.small_family_value<0){
print_char('-');
print_char('1');
}else{
print_char('"');
two_hex(c.small_family_value);
six_hex(c.small_character_value);
}
}

/*:13*//*14:*/
#line 235 "./luatexdir/tex/mathcodes.w"

static void unsavedelcode(quarterword gl)
{
sa_stack_item st;
if(delcode_head->stack==NULL)
return;
while(delcode_head->stack_ptr> 0&&abs(delcode_head->stack[delcode_head->stack_ptr].level)>=gl){
st= delcode_head->stack[delcode_head->stack_ptr];
if(st.level> 0){
rawset_sa_item(delcode_head,st.code,st.value);
if(tracing_restores_par> 1){
begin_diagnostic();
print_char('{');
tprint("restoring");
print_char(' ');
show_delcode(st.code);
print_char('}');
end_diagnostic(false);
}
}
(mathcode_head->stack_ptr)--;
}
}

/*:14*//*15:*/
#line 259 "./luatexdir/tex/mathcodes.w"

void set_del_code(int n,int smathfamily,int smathcharacter,int lmathfamily,int lmathcharacter,quarterword gl)
{
sa_tree_item v;
v.del_code_value.class_value= 0;
v.del_code_value.small_family_value= smathfamily;
v.del_code_value.small_character_value= smathcharacter;
v.del_code_value.dummy_value= 0;
v.del_code_value.large_family_value= lmathfamily;
v.del_code_value.large_character_value= lmathcharacter;
set_sa_item(delcode_head,n,v,gl);
if(tracing_assigns_par> 1){
begin_diagnostic();
print_char('{');
tprint("assigning");
print_char(' ');
show_delcode(n);
print_char('}');
end_diagnostic(false);
}
}

/*:15*//*16:*/
#line 281 "./luatexdir/tex/mathcodes.w"

delcodeval get_del_code(int n)
{
delcodeval d;
sa_tree_item v= get_sa_item(delcode_head,n);
if(v.uint_value==DELCODEDEFAULT){
d.class_value= 0;
d.small_family_value= -1;
d.small_character_value= 0;
d.large_family_value= 0;
d.large_character_value= 0;
}else{
d.class_value= v.del_code_value.class_value;
d.small_family_value= v.del_code_value.small_family_value;
d.small_character_value= v.del_code_value.small_character_value;
d.large_family_value= v.del_code_value.large_family_value;
d.large_character_value= v.del_code_value.large_character_value;
}
return d;
}

/*:16*//*17:*/
#line 304 "./luatexdir/tex/mathcodes.w"

int get_del_code_num(int n)
{
delcodeval d= get_del_code(n);
if(d.small_family_value<0){
return-1;
}else{
return((d.small_family_value*256+d.small_character_value)*4096+
(d.large_family_value*256)+d.large_character_value);
}
}

/*:17*//*18:*/
#line 316 "./luatexdir/tex/mathcodes.w"

static void initializedelcode(void)
{
sa_tree_item sa_value= {0};
sa_value.uint_value= DELCODEDEFAULT;
delcode_head= new_sa_tree(DELCODESTACK,2,sa_value);
}

/*:18*//*19:*/
#line 324 "./luatexdir/tex/mathcodes.w"

static void dumpdelcode(void)
{
dump_sa_tree(delcode_head,"delcodes");
}

static void undumpdelcode(void)
{
delcode_head= undump_sa_tree("delcodes");
}

/*:19*//*20:*/
#line 335 "./luatexdir/tex/mathcodes.w"

void unsave_math_codes(quarterword grouplevel)
{
unsavemathcode(grouplevel);
unsavedelcode(grouplevel);
}

/*:20*//*21:*/
#line 342 "./luatexdir/tex/mathcodes.w"

void initialize_math_codes(void)
{
initializemathcode();
initializedelcode();
}

/*:21*//*22:*/
#line 349 "./luatexdir/tex/mathcodes.w"

void free_math_codes(void)
{
destroy_sa_tree(mathcode_head);
destroy_sa_tree(delcode_head);
}

/*:22*//*23:*/
#line 356 "./luatexdir/tex/mathcodes.w"

void dump_math_codes(void)
{
dumpmathcode();
dumpdelcode();
}

void undump_math_codes(void)
{
undumpmathcode();
undumpdelcode();
}/*:23*/
