/*1:*/
#line 20 "./luatexdir/lang/texlang.w"


#include "ptexlib.h"
#include <string.h> 
#include "lua/luatex-api.h"

/*:1*//*3:*/
#line 28 "./luatexdir/lang/texlang.w"

#define unVERBOSE

#define MAX_TEX_LANGUAGES  16384

static struct tex_language*tex_languages[MAX_TEX_LANGUAGES]= {NULL};

static int next_lang_id= 0;

struct tex_language*new_language(int n)
{
struct tex_language*lang;
unsigned l;
if(n>=0){
l= (unsigned)n;
if(l!=(MAX_TEX_LANGUAGES-1))
if(next_lang_id<=n)
next_lang_id= n+1;
}else{
while(tex_languages[next_lang_id]!=NULL)
next_lang_id++;
l= (unsigned)next_lang_id++;
}
if(l<(MAX_TEX_LANGUAGES-1)&&tex_languages[l]==NULL){
lang= xmalloc(sizeof(struct tex_language));
tex_languages[l]= lang;
lang->id= (int)l;
lang->exceptions= 0;
lang->patterns= NULL;
lang->pre_hyphen_char= '-';
lang->post_hyphen_char= 0;
lang->pre_exhyphen_char= 0;
lang->post_exhyphen_char= 0;
lang->hyphenation_min= -1;
if(saving_hyph_codes_par){
hj_codes_from_lc_codes(l);
}
return lang;
}else{
return NULL;
}
}

struct tex_language*get_language(int n)
{
if(n>=0&&n<MAX_TEX_LANGUAGES){
if(tex_languages[n]!=NULL){
return tex_languages[n];
}else{
return new_language(n);
}
}else{
return NULL;
}
}

/*:3*//*4:*/
#line 84 "./luatexdir/lang/texlang.w"

void set_pre_hyphen_char(int n,int v)
{
struct tex_language*l= get_language((int)n);
if(l!=NULL)
l->pre_hyphen_char= (int)v;
}

void set_post_hyphen_char(int n,int v)
{
struct tex_language*l= get_language((int)n);
if(l!=NULL)
l->post_hyphen_char= (int)v;
}

void set_pre_exhyphen_char(int n,int v)
{
struct tex_language*l= get_language((int)n);
if(l!=NULL)
l->pre_exhyphen_char= (int)v;
}

void set_post_exhyphen_char(int n,int v)
{
struct tex_language*l= get_language((int)n);
if(l!=NULL)
l->post_exhyphen_char= (int)v;
}

int get_pre_hyphen_char(int n)
{
struct tex_language*l= get_language((int)n);
if(l==NULL)
return-1;
return(int)l->pre_hyphen_char;
}

int get_post_hyphen_char(int n)
{
struct tex_language*l= get_language((int)n);
if(l==NULL)
return-1;
return(int)l->post_hyphen_char;
}

int get_pre_exhyphen_char(int n)
{
struct tex_language*l= get_language((int)n);
if(l==NULL)
return-1;
return(int)l->pre_exhyphen_char;
}

int get_post_exhyphen_char(int n)
{
struct tex_language*l= get_language((int)n);
if(l==NULL)
return-1;
return(int)l->post_exhyphen_char;
}

void set_hyphenation_min(int n,int v)
{
struct tex_language*l= get_language((int)n);
if(l!=NULL)
l->hyphenation_min= (int)v;
}

int get_hyphenation_min(int n)
{
struct tex_language*l= get_language((int)n);
if(l==NULL)
return-1;
return(int)l->hyphenation_min;
}

void load_patterns(struct tex_language*lang,const unsigned char*buff)
{
if(lang==NULL||buff==NULL||strlen((const char*)buff)==0)
return;
if(lang->patterns==NULL){
lang->patterns= hnj_hyphen_new();
}
hnj_hyphen_load(lang->patterns,buff);
}

void clear_patterns(struct tex_language*lang)
{
if(lang==NULL)
return;
if(lang->patterns!=NULL){
hnj_hyphen_clear(lang->patterns);
}
}

void load_tex_patterns(int curlang,halfword head)
{
char*s= tokenlist_to_cstring(head,1,NULL);
load_patterns(get_language(curlang),(unsigned char*)s);
}

/*:4*//*5:*/
#line 185 "./luatexdir/lang/texlang.w"

#define STORE_CHAR(l,x) do { \
    unsigned xx =  get_hj_code(l,x); \
    if (!xx || xx <= 32) { \
        xx =  x; \
    } \
    uindex =  uni2string(uindex, xx); \
} while (0)

/*:5*//*6:*/
#line 197 "./luatexdir/lang/texlang.w"

const char*clean_hyphenation(int id,const char*buff,char**cleaned)
{
int items= 0;
unsigned char word[MAX_WORD_LEN+1];
unsigned uword[MAX_WORD_LEN+1]= {0};
int u= 0;
int i= 0;
char*uindex= (char*)word;
const char*s= buff;

while(*s&&!isspace((unsigned char)*s)){
word[i++]= (unsigned)*s;
s++;
if((s-buff)> MAX_WORD_LEN){

*cleaned= NULL;
tex_error("exception too long",NULL);
return s;
}
}

word[i]= '\0';
utf2uni_strcpy(uword,(const char*)word);


i= 0;
while(uword[i]> 0){
u= uword[i++];
if(u=='-'){
}else if(u=='='){
STORE_CHAR(id,'-');
}else if(u=='{'){
u= uword[i++];
items= 0;
while(u&&u!='}'){
u= uword[i++];
}
if(u=='}'){
items++;
u= uword[i++];
}
while(u&&u!='}'){
u= uword[i++];
}
if(u=='}'){
items++;
u= uword[i++];
}
if(u=='{'){
u= uword[i++];
}
while(u&&u!='}'){
STORE_CHAR(id,u);
u= uword[i++];
}
if(u=='}'){
items++;
}
if(items!=3){
*cleaned= NULL;
tex_error("exception syntax error",NULL);
return s;
}
}else{
STORE_CHAR(id,u);
}
}
*uindex= '\0';
*cleaned= xstrdup((char*)word);
return s;
}

/*:6*//*7:*/
#line 270 "./luatexdir/lang/texlang.w"

void load_hyphenation(struct tex_language*lang,const unsigned char*buff)
{
const char*s;
const char*value;
char*cleaned;
int id;
if(lang==NULL)
return;
if(lang->exceptions==0){
lua_newtable(Luas);
lang->exceptions= luaL_ref(Luas,LUA_REGISTRYINDEX);
}
lua_rawgeti(Luas,LUA_REGISTRYINDEX,lang->exceptions);
s= (const char*)buff;
id= lang->id;
while(*s){
while(isspace((unsigned char)*s))
s++;
if(*s){
value= s;
s= clean_hyphenation(id,s,&cleaned);
if(cleaned!=NULL){
if((s-value)> 0){
lua_pushstring(Luas,cleaned);
lua_pushlstring(Luas,value,(size_t)(s-value));
lua_rawset(Luas,-3);
}
free(cleaned);
}else{
#ifdef VERBOSE
formatted_warning("hyphenation","skipping invalid hyphenation exception: %s",value);
#endif
}
}
}
}

void clear_hyphenation(struct tex_language*lang)
{
if(lang==NULL)
return;
if(lang->exceptions!=0){
luaL_unref(Luas,LUA_REGISTRYINDEX,lang->exceptions);
lang->exceptions= 0;
}
}

void load_tex_hyphenation(int curlang,halfword head)
{
char*s= tokenlist_to_cstring(head,1,NULL);
load_hyphenation(get_language(curlang),(unsigned char*)s);
}

/*:7*//*8:*/
#line 328 "./luatexdir/lang/texlang.w"

halfword insert_discretionary(halfword t,halfword pre,halfword post,
halfword replace,int penalty)
{
halfword g,n;
int f;
n= new_node(disc_node,syllable_disc);
disc_penalty(n)= penalty;
try_couple_nodes(n,vlink(t));
couple_nodes(t,n);
if(replace!=null)
f= font(replace);
else
f= get_cur_font();
for(g= pre;g!=null;g= vlink(g)){
font(g)= f;
if(node_attr(t)!=null){
delete_attribute_ref(node_attr(g));
node_attr(g)= node_attr(t);
attr_list_ref(node_attr(t))+= 1;
}
}
for(g= post;g!=null;g= vlink(g)){
font(g)= f;
if(node_attr(t)!=null){
delete_attribute_ref(node_attr(g));
node_attr(g)= node_attr(t);
attr_list_ref(node_attr(t))+= 1;
}
}
for(g= replace;g!=null;g= vlink(g)){
if(node_attr(t)!=null){
delete_attribute_ref(node_attr(g));
node_attr(g)= node_attr(t);
attr_list_ref(node_attr(t))+= 1;
}
}
if(node_attr(t)!=null){
delete_attribute_ref(node_attr(vlink(t)));
node_attr(vlink(t))= node_attr(t);
attr_list_ref(node_attr(t))+= 1;
}
t= vlink(t);
set_disc_field(pre_break(t),pre);
set_disc_field(post_break(t),post);
set_disc_field(no_break(t),replace);
return t;
}

halfword insert_syllable_discretionary(halfword t,lang_variables*lan)
{
halfword g,n;
n= new_node(disc_node,syllable_disc);
disc_penalty(n)= hyphen_penalty_par;
couple_nodes(n,vlink(t));
couple_nodes(t,n);
delete_attribute_ref(node_attr(n));
if(node_attr(t)!=null){
node_attr(n)= node_attr(t);
attr_list_ref(node_attr(t))++;
}else{
node_attr(n)= null;
}
if(lan->pre_hyphen_char> 0){
g= raw_glyph_node();
set_to_character(g);
character(g)= lan->pre_hyphen_char;
font(g)= font(t);
lang_data(g)= lang_data(t);
if(node_attr(t)!=null){
node_attr(g)= node_attr(t);
attr_list_ref(node_attr(t))++;
}
set_disc_field(pre_break(n),g);
}

if(lan->post_hyphen_char> 0){
t= vlink(n);
g= raw_glyph_node();
set_to_character(g);
character(g)= lan->post_hyphen_char;
font(g)= font(t);
lang_data(g)= lang_data(t);
if(node_attr(t)!=null){
node_attr(g)= node_attr(t);
attr_list_ref(node_attr(t))+= 1;
}
set_disc_field(post_break(n),g);
}
return n;
}

halfword insert_word_discretionary(halfword t,lang_variables*lan)
{
halfword pre= null,pos= null;
if(lan->pre_exhyphen_char> 0)
pre= insert_character(null,lan->pre_exhyphen_char);
if(lan->post_exhyphen_char> 0)
pos= insert_character(null,lan->post_exhyphen_char);
return insert_discretionary(t,pre,pos,null,ex_hyphen_penalty_par);
}

/*:8*//*9:*/
#line 430 "./luatexdir/lang/texlang.w"

halfword compound_word_break(halfword t,int clang)
{
int disc;
lang_variables langdata;
langdata.pre_exhyphen_char= get_pre_exhyphen_char(clang);
langdata.post_exhyphen_char= get_post_exhyphen_char(clang);
disc= insert_word_discretionary(t,&langdata);
return disc;
}

halfword insert_complex_discretionary(halfword t,lang_variables*lan,
halfword pre,halfword pos,
halfword replace)
{
(void)lan;
return insert_discretionary(t,pre,pos,replace,hyphen_penalty_par);
}

halfword insert_character(halfword t,int c)
{
halfword p;
p= new_node(glyph_node,0);
set_to_character(p);
character(p)= c;
if(t!=null){
couple_nodes(t,p);
}
return p;
}

/*:9*//*10:*/
#line 461 "./luatexdir/lang/texlang.w"

void set_disc_field(halfword f,halfword t)
{
if(t!=null){
couple_nodes(f,t);
tlink(f)= tail_of_list(t);
}else{
vlink(f)= null;
tlink(f)= null;
}
}

/*:10*//*11:*/
#line 473 "./luatexdir/lang/texlang.w"

static char*hyphenation_exception(int exceptions,char*w)
{
char*ret= NULL;
lua_checkstack(Luas,2);
lua_rawgeti(Luas,LUA_REGISTRYINDEX,exceptions);
if(lua_istable(Luas,-1)){
lua_pushstring(Luas,w);
lua_rawget(Luas,-2);
if(lua_type(Luas,-1)==LUA_TSTRING){
ret= xstrdup(lua_tostring(Luas,-1));
}
lua_pop(Luas,2);
}else{
lua_pop(Luas,1);
}
return ret;
}

/*:11*//*12:*/
#line 492 "./luatexdir/lang/texlang.w"

char*exception_strings(struct tex_language*lang)
{
const char*value;
size_t size= 0,current= 0;
size_t l= 0;
char*ret= NULL;
if(lang->exceptions==0)
return NULL;
lua_checkstack(Luas,2);
lua_rawgeti(Luas,LUA_REGISTRYINDEX,lang->exceptions);
if(lua_istable(Luas,-1)){

lua_pushnil(Luas);
while(lua_next(Luas,-2)!=0){
value= lua_tolstring(Luas,-1,&l);
if(current+2+l> size){
ret= xrealloc(ret,(unsigned)((size+size/5)+current+l+1024));
size= (size+size/5)+current+l+1024;
}
*(ret+current)= ' ';
strcpy(ret+current+1,value);
current+= l+1;
lua_pop(Luas,1);
}
}
return ret;
}

/*:12*//*13:*/
#line 524 "./luatexdir/lang/texlang.w"

static halfword find_exception_part(unsigned int*j,unsigned int*uword,int len)
{
halfword g= null,gg= null;
register unsigned i= *j;
i++;
while(i<(unsigned)len&&uword[i+1]!='}'){
if(g==null){
gg= new_char(0,(int)uword[i+1]);
g= gg;
}else{
halfword s= new_char(0,(int)uword[i+1]);
couple_nodes(g,s);
g= vlink(g);
}
i++;
}
*j= ++i;
return gg;
}

static int count_exception_part(unsigned int*j,unsigned int*uword,int len)
{
int ret= 0;
register unsigned i= *j;
i++;
while(i<(unsigned)len&&uword[i+1]!='}'){
ret++;
i++;
}
*j= ++i;
return ret;
}

/*:13*//*14:*/
#line 558 "./luatexdir/lang/texlang.w"

static const char*PAT_ERROR[]= {
"Exception discretionaries should contain three pairs of braced items.",
"No intervening spaces are allowed.",
NULL
};






static void do_exception(halfword wordstart,halfword r,char*replacement)
{
unsigned i;
halfword t;
unsigned len;
int clang;
lang_variables langdata;
unsigned uword[MAX_WORD_LEN+1]= {0};
utf2uni_strcpy(uword,replacement);
len= u_length(uword);
i= 0;
t= wordstart;
clang= char_lang(wordstart);
langdata.pre_hyphen_char= get_pre_hyphen_char(clang);
langdata.post_hyphen_char= get_post_hyphen_char(clang);

for(i= 0;i<len;i++){
if(uword[i+1]=='-'){
while(vlink(t)!=r&&(type(t)!=glyph_node||!is_simple_character(t)))
t= vlink(t);
if(vlink(t)==r)
break;
insert_syllable_discretionary(t,&langdata);
t= vlink(t);
}else if(uword[i+1]=='='){

t= vlink(t);
}else if(uword[i+1]=='{'){
halfword gg,hh,replace= null;
int repl;
gg= find_exception_part(&i,uword,(int)len);
if(i==len||uword[i+1]!='{'){
tex_error("broken pattern 1",PAT_ERROR);
}
hh= find_exception_part(&i,uword,(int)len);
if(i==len||uword[i+1]!='{'){
tex_error("broken pattern 2",PAT_ERROR);
}
repl= count_exception_part(&i,uword,(int)len);
if(i==len){
tex_error("broken pattern 3",PAT_ERROR);
}

if(vlink(t)==r)
break;
if(repl> 0){
halfword q= t;
replace= vlink(q);
while(repl> 0&&q!=null){
q= vlink(q);
if(type(q)==glyph_node){
repl--;
}
}
try_couple_nodes(t,vlink(q));
vlink(q)= null;
}
t= insert_discretionary(t,gg,hh,replace,hyphen_penalty_par);
t= vlink(t);
}else{
t= vlink(t);
}
}
}

/*:14*//*16:*/
#line 696 "./luatexdir/lang/texlang.w"
























static halfword find_next_wordstart(halfword r,halfword first_language,halfword strict_bound)
{
register int l;
register int start_ok= 1;
int mathlevel= 1;
int chr;
halfword t;
while(r!=null){
switch(type(r)){
case boundary_node:
if(subtype(r)==word_boundary){
start_ok= 1;
}
break;
case hlist_node:
case vlist_node:
case rule_node:
case dir_node:
case whatsit_node:
if(strict_bound==1||strict_bound==3){
start_ok= 0;
}
break;
case glue_node:
start_ok= 1;
break;
case math_node:
while(mathlevel> 0){
r= vlink(r);
if(r==null)
return r;
if(type(r)==math_node){
if(subtype(r)==before){
mathlevel++;
}else{
mathlevel--;
}
}
}
break;
case glyph_node:
if(is_simple_character(r)){
chr= character(r);
if(chr==ex_hyphen_char_par){








t= vlink(r);
if((start_ok==0)&&(t!=null)&&(type(t)==glyph_node)&&(character(t)!=ex_hyphen_char_par)){
t= compound_word_break(r,char_lang(r));
subtype(t)= automatic_disc;
start_ok= 1;
}else{
start_ok= 0;
}
}else if(start_ok&&(char_lang(r)>=first_language)&&((l= get_hj_code(char_lang(r),chr))> 0)){
if(char_uchyph(r)||l==chr||l<=32){
return r;
}else{
start_ok= 0;
}
}
}
break;
default:
start_ok= 0;
break;
}
r= vlink(r);
}
return r;
}

/*:16*//*17:*/
#line 798 "./luatexdir/lang/texlang.w"

static int valid_wordend(halfword s,halfword strict_bound)
{
register halfword r= s;
register int clang= char_lang(s);
if(r==null)
return 1;
while((r!=null)&&
((type(r)==glyph_node&&is_simple_character(r)&&clang==char_lang(r))
||(type(r)==kern_node&&(subtype(r)==normal))
)
){
r= vlink(r);
}
if(r==null||(type(r)==glyph_node&&is_simple_character(r)&&clang!=char_lang(r))
||type(r)==glue_node
||type(r)==penalty_node
||(type(r)==kern_node&&(subtype(r)==explicit_kern||
subtype(r)==italic_kern||
subtype(r)==accent_kern))
||((type(r)==hlist_node||
type(r)==vlist_node||
type(r)==rule_node||
type(r)==dir_node||
type(r)==whatsit_node||
type(r)==ins_node||
type(r)==adjust_node
)&&!(strict_bound==2||strict_bound==3))
||type(r)==boundary_node
)
return 1;
return 0;
}

/*:17*//*18:*/
#line 832 "./luatexdir/lang/texlang.w"

void hnj_hyphenation(halfword head,halfword tail)
{
int lchar,i;
struct tex_language*lang;
lang_variables langdata;
char utf8word[(4*MAX_WORD_LEN)+1]= {0};
int wordlen= 0;
char*hy= utf8word;
char*replacement= NULL;
boolean explicit_hyphen= false;
halfword first_language= first_valid_language_par;
halfword strict_bound= hyphenation_bounds_par;
halfword s,r= head,wordstart= null,save_tail1= null,left= null,right= null;









while(r!=null&&(type(r)!=glyph_node||!is_simple_character(r))){
r= vlink(r);
}

r= find_next_wordstart(r,first_language,strict_bound);
if(r==null)
return;

assert(tail!=null);
save_tail1= vlink(tail);
s= new_penalty(0);
couple_nodes(tail,s);

while(r!=null){
int clang,lhmin,rhmin,hmin;
halfword hyf_font;
halfword end_word= r;
wordstart= r;
assert(is_simple_character(wordstart));
hyf_font= font(wordstart);
if(hyphen_char(hyf_font)<0)
hyf_font= 0;
clang= char_lang(wordstart);
lhmin= char_lhmin(wordstart);
rhmin= char_rhmin(wordstart);
hmin= get_hyphenation_min(clang);
langdata.pre_hyphen_char= get_pre_hyphen_char(clang);
langdata.post_hyphen_char= get_post_hyphen_char(clang);
while(r!=null
&&type(r)==glyph_node
&&is_simple_character(r)
&&clang==char_lang(r)
&&(((clang>=first_language)
&&(lchar= get_hj_code(clang,character(r)))> 0
)
||(character(r)==ex_hyphen_char_par
&&(lchar= ex_hyphen_char_par)
)
)
){
if(character(r)==ex_hyphen_char_par){
explicit_hyphen= true;
}
wordlen++;
if(lchar<=32){
if(lchar==32){
lchar= 0;
}
if(wordlen<=lhmin){
lhmin= lhmin-lchar+1;
}
if(wordlen>=rhmin){
rhmin= rhmin-lchar+1;
}
hmin= hmin-lchar+1;
lchar= character(r);
}
hy= uni2string(hy,(unsigned)lchar);


end_word= r;
r= vlink(r);
}
if(valid_wordend(r,strict_bound)
&&clang>=first_language
&&wordlen>=lhmin+rhmin
&&(hmin<=0||wordlen>=hmin)
&&(hyf_font!=0)
&&(lang= tex_languages[clang])!=NULL
){
*hy= 0;
if(lang->exceptions!=0
&&(replacement= hyphenation_exception(lang->exceptions,utf8word))!=NULL
){
#ifdef VERBOSE
formatted_warning("hyphenation","replacing %s (c=%d) by %s",utf8word,clang,replacement);
#endif
do_exception(wordstart,r,replacement);
free(replacement);
}else if(explicit_hyphen==true){




halfword rr= r;
halfword t= null;
#ifdef VERBOSE
formatted_warning("hyphenation","explicit hyphen(s) found in %s (c=%d)",utf8word,clang);
#endif
while(rr!=wordstart){
if(is_simple_character(rr)){
if(character(rr)==ex_hyphen_char_par){
t= compound_word_break(rr,clang);
subtype(t)= automatic_disc;
while(character(alink(rr))==ex_hyphen_char_par)
rr= alink(rr);
if(rr==wordstart)
break;
}
}
rr= alink(rr);
}
}else if(lang->patterns!=NULL){
left= wordstart;
for(i= lhmin;i> 1;i--){
left= vlink(left);
while(!is_simple_character(left))
left= vlink(left);
}
right= r;
for(i= rhmin;i> 0;i--){
right= alink(right);
while(!is_simple_character(right))
right= alink(right);
}
#ifdef VERBOSE
formatted_warning("hyphenation","hyphenate %s (c=%d,l=%d,r=%d) from %c to %c",
utf8word,clang,lhmin,rhmin,character(left),character(right));
#endif
(void)hnj_hyphen_hyphenate(lang->patterns,wordstart,end_word,wordlen,left,right,&langdata);
}
}
explicit_hyphen= false;
wordlen= 0;
hy= utf8word;
if(r==null)
break;
r= find_next_wordstart(r,first_language,strict_bound);
}
flush_node(vlink(tail));
vlink(tail)= save_tail1;
}

/*:18*//*19:*/
#line 988 "./luatexdir/lang/texlang.w"

void new_hyphenation(halfword head,halfword tail)
{
register int callback_id= 0;
if(head==null||vlink(head)==null)
return;
fix_node_list(head);
callback_id= callback_defined(hyphenate_callback);
if(callback_id> 0){
if(!get_callback(Luas,callback_id)){
lua_pop(Luas,2);
return;
}
nodelist_to_lua(Luas,head);
nodelist_to_lua(Luas,tail);
if(lua_pcall(Luas,2,0,0)!=0){
formatted_warning("hyphenation","bad specification: %s",lua_tostring(Luas,-1));
lua_pop(Luas,2);
lua_error(Luas);
return;
}
lua_pop(Luas,1);
}else if(callback_id==0){
hnj_hyphenation(head,tail);
}
}

/*:19*//*20:*/
#line 1017 "./luatexdir/lang/texlang.w"

#define dump_string(a)                \
  if (a!=NULL) {                      \
      x =  (int)strlen(a)+1;           \
    dump_int(x);  dump_things(*a, x); \
  } else {                            \
    x =  0; dump_int(x);               \
  }

static void dump_one_language(int i)
{
char*s= NULL;
int x= 0;
struct tex_language*lang;
lang= tex_languages[i];
dump_int(lang->id);
dump_int(lang->pre_hyphen_char);
dump_int(lang->post_hyphen_char);
dump_int(lang->pre_exhyphen_char);
dump_int(lang->post_exhyphen_char);
dump_int(lang->hyphenation_min);
if(lang->patterns!=NULL){
s= (char*)hnj_serialize(lang->patterns);
}
dump_string(s);
if(s!=NULL){
free(s);
s= NULL;
}
if(lang->exceptions!=0)
s= exception_strings(lang);
dump_string(s);
if(s!=NULL){
free(s);
}
free(lang);
}

void dump_language_data(void)
{
int i;
dump_int(next_lang_id);
for(i= 0;i<next_lang_id;i++){
if(tex_languages[i]){
dump_int(1);
dump_one_language(i);
}else{
dump_int(0);
}
}
}

static void undump_one_language(int i)
{
char*s= NULL;
int x= 0;
struct tex_language*lang= get_language(i);
undump_int(x);
lang->id= x;
undump_int(x);
lang->pre_hyphen_char= x;
undump_int(x);
lang->post_hyphen_char= x;
undump_int(x);
lang->pre_exhyphen_char= x;
undump_int(x);
lang->post_exhyphen_char= x;
undump_int(x);
lang->hyphenation_min= x;

undump_int(x);
if(x> 0){
s= xmalloc((unsigned)x);
undump_things(*s,x);
load_patterns(lang,(unsigned char*)s);
free(s);
}

undump_int(x);
if(x> 0){
s= xmalloc((unsigned)x);
undump_things(*s,x);
load_hyphenation(lang,(unsigned char*)s);
free(s);
}
}

void undump_language_data(void)
{
int i,x,numlangs;
undump_int(numlangs);
next_lang_id= numlangs;
for(i= 0;i<numlangs;i++){
undump_int(x);
if(x==1){
undump_one_language(i);
}
}
}

/*:20*//*21:*/
#line 1120 "./luatexdir/lang/texlang.w"

void new_hyph_exceptions(void)
{
(void)scan_toks(false,true);
load_tex_hyphenation(language_par,def_ref);
flush_list(def_ref);
}

/*:21*//*22:*/
#line 1131 "./luatexdir/lang/texlang.w"

void new_patterns(void)
{
(void)scan_toks(false,true);
load_tex_patterns(language_par,def_ref);
flush_list(def_ref);
}

/*:22*//*23:*/
#line 1143 "./luatexdir/lang/texlang.w"

void new_pre_hyphen_char(void)
{
scan_optional_equals();
scan_int();
set_pre_hyphen_char(language_par,cur_val);
}

void new_post_hyphen_char(void)
{
scan_optional_equals();
scan_int();
set_post_hyphen_char(language_par,cur_val);
}

/*:23*//*24:*/
#line 1162 "./luatexdir/lang/texlang.w"

void new_pre_exhyphen_char(void)
{
scan_optional_equals();
scan_int();
set_pre_exhyphen_char(language_par,cur_val);
}

void new_post_exhyphen_char(void)
{
scan_optional_equals();
scan_int();
set_post_exhyphen_char(language_par,cur_val);
}

void new_hyphenation_min(void)
{
scan_optional_equals();
scan_int();
set_hyphenation_min(language_par,cur_val);
}

void new_hj_code(void)
{
int i;
scan_int();
i= cur_val;
scan_optional_equals();
scan_int();
set_hj_code(language_par,i,cur_val,-1);
}/*:24*/
