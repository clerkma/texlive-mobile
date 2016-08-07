/*1:*/
#line 20 "./luatexdir/tex/stringpool.w"



#include "ptexlib.h"

/*:1*//*2:*/
#line 46 "./luatexdir/tex/stringpool.w"

lstring*string_pool;
lstring*_string_pool;



str_number str_ptr= (STRING_OFFSET+1);
str_number init_str_ptr;

unsigned char*cur_string;
unsigned cur_length;
unsigned cur_string_size;
unsigned pool_size;


/*:2*//*3:*/
#line 66 "./luatexdir/tex/stringpool.w"

void reset_cur_string(void)
{
cur_length= 0;
cur_string_size= 255;
cur_string= (unsigned char*)xmalloc(256);
memset(cur_string,0,256);
}

/*:3*//*4:*/
#line 76 "./luatexdir/tex/stringpool.w"

str_number make_string(void)
{
if(str_ptr==(max_strings+STRING_OFFSET))
overflow("number of strings",
(unsigned)(max_strings-init_str_ptr+STRING_OFFSET));
str_room(1);
cur_string[cur_length]= '\0';
str_string(str_ptr)= (unsigned char*)cur_string;
str_length(str_ptr)= cur_length;
pool_size+= cur_length;
reset_cur_string();
#if 0
printf("Made a string: %s (s=%d)\n",(char*)str_string(str_ptr),(int)str_ptr);
#endif
str_ptr++;
return(str_ptr-1);
}

/*:4*//*5:*/
#line 95 "./luatexdir/tex/stringpool.w"

int pool_to_unichar(unsigned char*t)
{
return(int)str2uni(t);
}



/*:5*//*6:*/
#line 109 "./luatexdir/tex/stringpool.w"

boolean str_eq_buf(str_number s,int k)
{
int a;
if(s<STRING_OFFSET){
a= buffer_to_unichar(k);
if(a!=s)
return false;
}else{
unsigned char*j= str_string(s);
unsigned char*l= j+str_length(s);
while(j<l){
if(*j++!=buffer[k++])
return false;
}
}
return true;
}


/*:6*//*7:*/
#line 132 "./luatexdir/tex/stringpool.w"

boolean str_eq_str(str_number s,str_number t)
{
int a= 0;
unsigned char*j,*k,*l;
if(s<STRING_OFFSET){
if(t>=STRING_OFFSET){
k= str_string(t);
if(s<=0x7F&&(str_length(t)==1)&&*k==s)
return true;
a= pool_to_unichar(k);
if(a!=s)
return false;
}else{
if(t!=s)
return false;
}
}else if(t<STRING_OFFSET){
j= str_string(s);
if(t<=0x7F&&(str_length(s)==1)&&*j==t)
return true;
a= pool_to_unichar(j);
if(a!=t)
return false;
}else{
if(str_length(s)!=str_length(t))
return false;
k= str_string(t);
j= str_string(s);
l= j+str_length(s);
while(j<l){
if(*j++!=*k++)
return false;
}
}
return true;
}

/*:7*//*8:*/
#line 171 "./luatexdir/tex/stringpool.w"

boolean str_eq_cstr(str_number r,const char*s,size_t l)
{
if(l!=(size_t)str_length(r))
return false;
return(strncmp((const char*)(str_string(r)),s,l)==0);
}


/*:8*//*10:*/
#line 191 "./luatexdir/tex/stringpool.w"

boolean get_strings_started(void)
{
reset_cur_string();
return true;
}

/*:10*//*11:*/
#line 205 "./luatexdir/tex/stringpool.w"

str_number search_string(str_number search)
{
str_number s;
size_t len;
len= str_length(search);
if(len==0){
return get_nullstr();
}else{
s= search-1;
while(s>=STRING_OFFSET){

if(str_length(s)==len)
if(str_eq_str(s,search))
return s;
s--;
}
}
return 0;
}

/*:11*//*12:*/
#line 226 "./luatexdir/tex/stringpool.w"

str_number maketexstring(const char*s)
{
if(s==NULL||*s==0)
return get_nullstr();
return maketexlstring(s,strlen(s));
}

/*:12*//*13:*/
#line 234 "./luatexdir/tex/stringpool.w"

str_number maketexlstring(const char*s,size_t l)
{
if(s==NULL||l==0)
return get_nullstr();
str_string(str_ptr)= xmalloc((unsigned)(l+1));
memcpy(str_string(str_ptr),s,(l+1));
str_length(str_ptr)= (unsigned)l;
str_ptr++;
return(str_ptr-1);
}

/*:13*//*14:*/
#line 247 "./luatexdir/tex/stringpool.w"

void append_string(const unsigned char*s,unsigned l)
{
if(s==NULL||*s==0)
return;
l= (unsigned)strlen((const char*)s);
str_room(l);
memcpy(cur_string+cur_length,s,l);
cur_length+= l;
return;
}

/*:14*//*15:*/
#line 259 "./luatexdir/tex/stringpool.w"

char*makecstring(int s)
{
size_t l;
return makeclstring(s,&l);
}

/*:15*//*16:*/
#line 266 "./luatexdir/tex/stringpool.w"

char*makeclstring(int s,size_t*len)
{
if(s<STRING_OFFSET){
*len= (size_t)utf8_size(s);
return(char*)uni2str((unsigned)s);
}else{
unsigned l= (unsigned)str_length(s);
char*cstrbuf= xmalloc(l+1);
memcpy(cstrbuf,str_string(s),l);
cstrbuf[l]= '\0';
*len= (size_t)l;
return cstrbuf;
}
}

/*:16*//*17:*/
#line 282 "./luatexdir/tex/stringpool.w"

int dump_string_pool(void)
{
int j;
int l;
int k= str_ptr;
dump_int(k-STRING_OFFSET);
for(j= STRING_OFFSET+1;j<k;j++){
l= (int)str_length(j);
if(str_string(j)==NULL)
l= -1;
dump_int(l);
if(l> 0)
dump_things(*str_string(j),str_length(j));
}
return(k-STRING_OFFSET);
}

/*:17*//*18:*/
#line 300 "./luatexdir/tex/stringpool.w"

int undump_string_pool(void)
{
int j;
int x;
undump_int(str_ptr);
if(max_strings<str_ptr+strings_free)
max_strings= str_ptr+strings_free;
str_ptr+= STRING_OFFSET;
if(ini_version)
libcfree(string_pool);
init_string_pool_array((unsigned)max_strings);
for(j= STRING_OFFSET+1;j<str_ptr;j++){
undump_int(x);
if(x>=0){
str_length(j)= (unsigned)x;
pool_size+= (unsigned)x;
str_string(j)= xmallocarray(unsigned char,(unsigned)(x+1));
undump_things(*str_string(j),(unsigned)x);
*(str_string(j)+str_length(j))= '\0';
}else{
str_length(j)= 0;
}
}
init_str_ptr= str_ptr;
return str_ptr;
}

/*:18*//*19:*/
#line 328 "./luatexdir/tex/stringpool.w"

void init_string_pool_array(unsigned s)
{
string_pool= xmallocarray(lstring,s);
_string_pool= string_pool-STRING_OFFSET;
memset(string_pool,0,s*sizeof(lstring));

string_pool[0].s= xmalloc(1);
string_pool[0].s[0]= '\0';
}

/*:19*//*20:*/
#line 340 "./luatexdir/tex/stringpool.w"

void flush_str(str_number s)
{
#if 0 
printf("Flushing a string: %s (s=%d,str_ptr=%d)\n",(char*)str_string(s),(int)s,(int)str_ptr);
#endif
if(s> STRING_OFFSET){
pool_size-= (unsigned)str_length(s);
str_length(s)= 0;
xfree(str_string(s));
}
while(str_string((str_ptr-1))==NULL)
str_ptr--;
}/*:20*/
