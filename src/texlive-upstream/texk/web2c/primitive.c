/*1:*/
#line 20 "./luatexdir/tex/primitive.w"



#include "ptexlib.h"

/*:1*//*2:*/
#line 49 "./luatexdir/tex/primitive.w"

two_halves*hash;
halfword hash_used;
int hash_extra;
halfword hash_top;
halfword hash_high;
boolean no_new_control_sequence;
int cs_count;

#define hash_is_full (hash_used==hash_base)     

/*:2*//*3:*/
#line 62 "./luatexdir/tex/primitive.w"

#define prim_base 1

/*:3*//*4:*/
#line 70 "./luatexdir/tex/primitive.w"

#define prim_next(a) prim[(a)].lhfield  
#define prim_text(a) prim[(a)].rh       
#define prim_is_full (prim_used==prim_base)     

#define prim_origin_field(a) (a).hh.b1
#define prim_eq_type_field(a)  (a).hh.b0
#define prim_equiv_field(a) (a).hh.rh
#define prim_origin(a) prim_origin_field(prim_eqtb[(a)])        
#define prim_eq_type(a) prim_eq_type_field(prim_eqtb[(a)])      
#define prim_equiv(a) prim_equiv_field(prim_eqtb[(a)])  

static pointer prim_used;
static two_halves prim[(prim_size+1)];
static memory_word prim_eqtb[(prim_size+1)];

/*:4*//*5:*/
#line 89 "./luatexdir/tex/primitive.w"

typedef struct prim_info{
halfword subids;
halfword offset;
str_number*names;
}prim_info;

static prim_info prim_data[(last_cmd+1)];

/*:5*//*6:*/
#line 99 "./luatexdir/tex/primitive.w"

void init_primitives(void)
{
int k;
memset(prim_data,0,(sizeof(prim_info)*(last_cmd+1)));
memset(prim,0,(sizeof(two_halves)*(prim_size+1)));
memset(prim_eqtb,0,(sizeof(memory_word)*(prim_size+1)));
for(k= 0;k<=prim_size;k++)
prim_eq_type(k)= undefined_cs_cmd;
}

void ini_init_primitives(void)
{
prim_used= prim_size;
}


/*:6*//*7:*/
#line 122 "./luatexdir/tex/primitive.w"

static halfword compute_hash(const char*j,unsigned int l,
halfword prime_number)
{
int k;
halfword h= (unsigned char)*j;
for(k= 1;k<=(int)(l-1);k++){
h= h+h+(unsigned char)*(j+k);
while(h>=prime_number)
h= h-prime_number;
}
return h;
}


/*:7*//*8:*/
#line 138 "./luatexdir/tex/primitive.w"

pointer prim_lookup(str_number s)
{
int h;
pointer p;
unsigned char*j;
unsigned l;
if(s<STRING_OFFSET){
p= s;
if((p<0)||(get_prim_eq_type(p)==undefined_cs_cmd)){
p= undefined_primitive;
}
}else{
j= str_string(s);
l= (unsigned)str_length(s);
h= compute_hash((char*)j,l,prim_prime);
p= h+prim_base;
while(1){
if(prim_text(p)> 0)
if(str_length(prim_text(p))==l)
if(str_eq_str(prim_text(p),s))
goto FOUND;
if(prim_next(p)==0){
if(no_new_control_sequence){
p= undefined_primitive;
}else{

if(prim_text(p)> 0){
do{
if(prim_is_full)
overflow("primitive size",prim_size);
decr(prim_used);
}while(prim_text(prim_used)!=0);
prim_next(p)= prim_used;
p= prim_used;
}
prim_text(p)= s;
}
goto FOUND;
}
p= prim_next(p);
}
}
FOUND:
return p;
}

/*:8*//*9:*/
#line 186 "./luatexdir/tex/primitive.w"

boolean is_primitive(str_number csname)
{
int n,m;
char*ss;
m= prim_lookup(csname);
ss= makecstring(csname);
n= string_lookup(ss,str_length(csname));
free(ss);
return((n!=undefined_cs_cmd)&&
(m!=undefined_primitive)&&
(eq_type(n)==prim_eq_type(m))&&(equiv(n)==prim_equiv(m)));
}


/*:9*//*10:*/
#line 202 "./luatexdir/tex/primitive.w"

quarterword get_prim_eq_type(int p)
{
return prim_eq_type(p);
}

quarterword get_prim_origin(int p)
{
return prim_origin(p);
}

halfword get_prim_equiv(int p)
{
return prim_equiv(p);
}

str_number get_prim_text(int p)
{
return prim_text(p);
}


/*:10*//*11:*/
#line 225 "./luatexdir/tex/primitive.w"

void dump_primitives(void)
{
int p,q;
for(p= 0;p<=prim_size;p++)
dump_hh(prim[p]);
for(p= 0;p<=prim_size;p++)
dump_wd(prim_eqtb[p]);
for(p= 0;p<=last_cmd;p++){
dump_int(prim_data[p].offset);
dump_int(prim_data[p].subids);
for(q= 0;q<prim_data[p].subids;q++){
dump_int(prim_data[p].names[q]);
}
}
}

void undump_primitives(void)
{
int p,q;
for(p= 0;p<=prim_size;p++)
undump_hh(prim[p]);
for(p= 0;p<=prim_size;p++)
undump_wd(prim_eqtb[p]);

for(p= 0;p<=last_cmd;p++){
undump_int(prim_data[p].offset);
undump_int(prim_data[p].subids);
if(prim_data[p].subids> 0){
prim_data[p].names= (str_number*)
xmalloc((unsigned)
((unsigned)prim_data[p].subids*
sizeof(str_number*)));
for(q= 0;q<prim_data[p].subids;q++)
undump_int(prim_data[p].names[q]);
}
}
}

/*:11*//*13:*/
#line 275 "./luatexdir/tex/primitive.w"

void primitive_def(const char*s,size_t l,quarterword c,halfword o)
{
int nncs= no_new_control_sequence;
no_new_control_sequence= false;
cur_val= string_lookup(s,l);
no_new_control_sequence= nncs;
eq_level(cur_val)= level_one;
eq_type(cur_val)= c;
equiv(cur_val)= o;
}

/*:13*//*14:*/
#line 299 "./luatexdir/tex/primitive.w"

static void
store_primitive_name(str_number s,quarterword c,halfword o,halfword offset)
{
int idx;
if(prim_data[c].offset!=0&&prim_data[c].offset!=offset){
assert(false);
}
prim_data[c].offset= offset;
idx= ((int)o-offset);
assert(idx>=0);
assert(idx<=0xFFFF);
if(prim_data[c].subids<(idx+1)){
str_number*new= 
(str_number*)xcalloc((unsigned)(idx+1),sizeof(str_number*));
if(prim_data[c].names!=NULL){
assert(prim_data[c].subids);
memcpy(new,(prim_data[c].names),
(unsigned)(prim_data[c].subids)*sizeof(str_number));
free(prim_data[c].names);
}
prim_data[c].names= new;
prim_data[c].subids= idx+1;
}
prim_data[c].names[idx]= s;
}

/*:14*//*15:*/
#line 330 "./luatexdir/tex/primitive.w"

void
primitive(const char*thes,quarterword c,halfword o,halfword off,
int cmd_origin)
{
int prim_val;
str_number ss;
assert(o>=off);
ss= maketexstring(thes);
if(cmd_origin==tex_command||cmd_origin==core_command){
primitive_def(thes,strlen(thes),c,o);
}
prim_val= prim_lookup(ss);
prim_origin(prim_val)= (quarterword)cmd_origin;
prim_eq_type(prim_val)= c;
prim_equiv(prim_val)= o;
store_primitive_name(ss,c,o,off);
}



/*:15*//*16:*/
#line 353 "./luatexdir/tex/primitive.w"

static halfword insert_id(halfword p,const unsigned char*j,unsigned int l)
{
unsigned saved_cur_length;
unsigned saved_cur_string_size;
unsigned char*saved_cur_string;
const unsigned char*k;



if(cs_text(p)> 0){
if(hash_high<hash_extra){
incr(hash_high);


cs_next(p)= hash_high+eqtb_size;
p= cs_next(p);
}else{
do{
if(hash_is_full)
overflow("hash size",(unsigned)(hash_size+hash_extra));
decr(hash_used);
}while(cs_text(hash_used)!=0);
cs_next(p)= hash_used;
p= hash_used;
}
}
saved_cur_length= cur_length;
saved_cur_string= cur_string;
saved_cur_string_size= cur_string_size;
reset_cur_string();
for(k= j;k<=j+l-1;k++)
append_char(*k);
cs_text(p)= make_string();
cur_length= saved_cur_length;
xfree(cur_string);
cur_string= saved_cur_string;
cur_string_size= saved_cur_string_size;
incr(cs_count);
return p;
}


/*:16*//*17:*/
#line 404 "./luatexdir/tex/primitive.w"

pointer id_lookup(int j,int l)
{
int h;
pointer p;

h= compute_hash((char*)(buffer+j),(unsigned)l,hash_prime);
#ifdef VERBOSE
{
unsigned char*todo= xmalloc(l+2);
strncpy(todo,(buffer+j),l);
todo[l]= '\0';
todo[l+1]= '\0';
fprintf(stdout,"id_lookup(%s)\n",todo);
free(todo);
}
#endif
p= h+hash_base;
while(1){
if(cs_text(p)> 0)
if(str_length(cs_text(p))==(unsigned)l)
if(str_eq_buf(cs_text(p),j))
goto FOUND;
if(cs_next(p)==0){
if(no_new_control_sequence){
p= undefined_control_sequence;
}else{
p= insert_id(p,(buffer+j),(unsigned)l);
}
goto FOUND;
}
p= cs_next(p);
}
FOUND:
return p;
}

/*:17*//*18:*/
#line 444 "./luatexdir/tex/primitive.w"

pointer string_lookup(const char*s,size_t l)
{
int h;
pointer p;
h= compute_hash(s,(unsigned)l,hash_prime);
p= h+hash_base;
while(1){
if(cs_text(p)> 0)
if(str_eq_cstr(cs_text(p),s,l))
goto FOUND;
if(cs_next(p)==0){
if(no_new_control_sequence){
p= undefined_control_sequence;
}else{
p= insert_id(p,(const unsigned char*)s,(unsigned)l);
}
goto FOUND;
}
p= cs_next(p);
}
FOUND:
return p;
}

/*:18*//*19:*/
#line 482 "./luatexdir/tex/primitive.w"

#define chr_cmd(A) do { tprint(A); print(chr_code); } while (0)

static void prim_cmd_chr(quarterword cmd,halfword chr_code)
{
int idx= chr_code-prim_data[cmd].offset;
if(cmd<=last_cmd&&
idx>=0&&idx<prim_data[cmd].subids&&
prim_data[cmd].names!=NULL&&prim_data[cmd].names[idx]!=0){
tprint_esc("");
print(prim_data[cmd].names[idx]);
}else{

tprint("[unknown command code! (");
print_int(cmd);
tprint(", ");
print_int(idx);
tprint(")]");
}
}

void print_cmd_chr(quarterword cmd,halfword chr_code)
{
int n;
switch(cmd){
case left_brace_cmd:
chr_cmd("begin-group character ");
break;
case right_brace_cmd:
chr_cmd("end-group character ");
break;
case math_shift_cmd:
chr_cmd("math shift character ");
break;
case mac_param_cmd:
if(chr_code==tab_mark_cmd_code)
tprint_esc("alignmark");
else
chr_cmd("macro parameter character ");
break;
case sup_mark_cmd:
chr_cmd("superscript character ");
break;
case sub_mark_cmd:
chr_cmd("subscript character ");
break;
case endv_cmd:
tprint("end of alignment template");
break;
case spacer_cmd:
chr_cmd("blank space ");
break;
case letter_cmd:
chr_cmd("the letter ");
break;
case other_char_cmd:
chr_cmd("the character ");
break;
case tab_mark_cmd:
if(chr_code==span_code)
tprint_esc("span");
else if(chr_code==tab_mark_cmd_code)
tprint_esc("aligntab");
else
chr_cmd("alignment tab character ");
break;
case if_test_cmd:
if(chr_code>=unless_code)
tprint_esc("unless");
prim_cmd_chr(cmd,(chr_code%unless_code));
break;
case char_given_cmd:
tprint_esc("char");
print_hex(chr_code);
break;
case math_given_cmd:
if(math_umathcode_meaning_par==1){
tprint_esc("Umathchar");
show_mathcode_value(mathchar_from_integer(chr_code,tex_mathcode));
}else{

tprint_esc("mathchar");
show_mathcode_value_old(chr_code);
}
break;
case xmath_given_cmd:
tprint_esc("Umathchar");
show_mathcode_value(mathchar_from_integer(chr_code,umath_mathcode));
break;
case set_font_cmd:
tprint("select font ");
tprint(font_name(chr_code));
if(font_size(chr_code)!=font_dsize(chr_code)){
tprint(" at ");
print_scaled(font_size(chr_code));
tprint("pt");
}
break;
case undefined_cs_cmd:
tprint("undefined");
break;
case call_cmd:
case long_call_cmd:
case outer_call_cmd:
case long_outer_call_cmd:
n= cmd-call_cmd;
if(token_info(token_link(chr_code))==protected_token)
n= n+4;
if(odd(n/4))
tprint_esc("protected");
if(odd(n))
tprint_esc("long");
if(odd(n/2))
tprint_esc("outer");
if(n> 0)
tprint(" ");
tprint("macro");
break;
case assign_glue_cmd:
case assign_mu_glue_cmd:
if(chr_code<skip_base){
prim_cmd_chr(cmd,chr_code);
}else if(chr_code<mu_skip_base){
tprint_esc("skip");
print_int(chr_code-skip_base);
}else{
tprint_esc("muskip");
print_int(chr_code-mu_skip_base);
}
break;
case assign_toks_cmd:
if(chr_code>=toks_base){
tprint_esc("toks");
print_int(chr_code-toks_base);
}else{
prim_cmd_chr(cmd,chr_code);
}
break;
case assign_int_cmd:
if(chr_code<count_base){
prim_cmd_chr(cmd,chr_code);
}else{
tprint_esc("count");
print_int(chr_code-count_base);
}
break;
case assign_attr_cmd:
tprint_esc("attribute");
print_int(chr_code-attribute_base);
break;
case assign_dimen_cmd:
if(chr_code<scaled_base){
prim_cmd_chr(cmd,chr_code);
}else{
tprint_esc("dimen");
print_int(chr_code-scaled_base);
}
break;
case normal_cmd:
if(chr_code<prim_data[cmd].subids&&prim_data[cmd].names[chr_code]!=0){
prim_cmd_chr(cmd,chr_code);
}else{
tprint("[unknown command! (");
print_int(chr_code);
tprint(")]");
}
break;
case extension_cmd:
if(chr_code<prim_data[cmd].subids&&prim_data[cmd].names[chr_code]!=0){
prim_cmd_chr(cmd,chr_code);
}else{
tprint("[unknown extension! (");
print_int(chr_code);
tprint(")]");

}
break;
default:

prim_cmd_chr(cmd,chr_code);
break;
}
}/*:19*/
