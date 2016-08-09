/*1:*/
#line 20 "./luatexdir/utils/unistring.w"



/*:1*//*2:*/
#line 23 "./luatexdir/utils/unistring.w"

#include "ptexlib.h"
#include <string.h> 

/*:2*//*3:*/
#line 27 "./luatexdir/utils/unistring.w"

static void utf_error(void)
{
const char*hlp[]= 
{"A funny symbol that I can't read has just been (re)read.",
"Just continue, I'll change it to 0xFFFD.",
NULL
};
deletions_allowed= false;
tex_error("String contains an invalid utf-8 sequence",hlp);
deletions_allowed= true;
}

/*:3*//*4:*/
#line 40 "./luatexdir/utils/unistring.w"

unsigned str2uni(const unsigned char*k)
{
register int ch;
int val= 0xFFFD;
const unsigned char*text= k;
if((ch= *text++)<0x80){
val= (unsigned)ch;
}else if(ch<=0xbf){
}else if(ch<=0xdf){
if(*text>=0x80&&*text<0xc0)
val= (unsigned)(((ch&0x1f)<<6)|(*text++&0x3f));
}else if(ch<=0xef){
if(*text>=0x80&&*text<0xc0&&text[1]>=0x80&&text[1]<0xc0){
val= (unsigned)
(((ch&0xf)<<12)|((text[0]&0x3f)<<6)|
(text[1]&0x3f));
}
}else if(ch<=0xf7){
int w= (((ch&0x7)<<2)|((text[0]&0x30)>>4))-1,w2;
w= (w<<6)|((text[0]&0xf)<<2)|((text[1]&0x30)>>4);
w2= ((text[1]&0xf)<<6)|(text[2]&0x3f);
val= (unsigned)(w*0x400+w2+0x10000);
if(*text<0x80||text[1]<0x80||text[2]<0x80||
*text>=0xc0||text[1]>=0xc0||text[2]>=0xc0)
val= 0xFFFD;
}else{




}
if(val==0xFFFD)
utf_error();
return(val);
}

/*:4*//*5:*/
#line 78 "./luatexdir/utils/unistring.w"

unsigned char*uni2str(unsigned unic)
{
unsigned char*buf= xmalloc(5);
unsigned char*pt= buf;
if(unic<0x80)
*pt++= (unsigned char)unic;
else if(unic<0x800){
*pt++= (unsigned char)(0xc0|(unic>>6));
*pt++= (unsigned char)(0x80|(unic&0x3f));
}else if(unic>=0x110000){
*pt++= (unsigned char)(unic-0x110000);
}else if(unic<0x10000){
*pt++= (unsigned char)(0xe0|(unic>>12));
*pt++= (unsigned char)(0x80|((unic>>6)&0x3f));
*pt++= (unsigned char)(0x80|(unic&0x3f));
}else{
unsigned val= unic-0x10000;
int u= (int)(((val&0xf0000)>>16)+1);
int z= (int)((val&0x0f000)>>12);
int y= (int)((val&0x00fc0)>>6);
int x= (int)(val&0x0003f);
*pt++= (unsigned char)(0xf0|(u>>2));
*pt++= (unsigned char)(0x80|((u&3)<<4)|z);
*pt++= (unsigned char)(0x80|y);
*pt++= (unsigned char)(0x80|x);
}
*pt= '\0';
return buf;
}

/*:5*//*6:*/
#line 114 "./luatexdir/utils/unistring.w"

int buffer_to_unichar(int k)
{
return str2uni((const unsigned char*)(buffer+k));
}


/*:6*//*7:*/
#line 122 "./luatexdir/utils/unistring.w"

char*uni2string(char*utf8_text,unsigned ch)
{

if(ch>=17*65536)
return(utf8_text);

if(ch<=127)
*utf8_text++= (char)ch;
else if(ch<=0x7ff){
*utf8_text++= (char)(0xc0|(ch>>6));
*utf8_text++= (char)(0x80|(ch&0x3f));
}else if(ch<=0xffff){
*utf8_text++= (char)(0xe0|(ch>>12));
*utf8_text++= (char)(0x80|((ch>>6)&0x3f));
*utf8_text++= (char)(0x80|(ch&0x3f));
}else{
unsigned val= ch-0x10000;
unsigned u= ((val&0xf0000)>>16)+1,z= (val&0x0f000)>>12,y= 
(val&0x00fc0)>>6,x= val&0x0003f;
*utf8_text++= (char)(0xf0|(u>>2));
*utf8_text++= (char)(0x80|((u&3)<<4)|z);
*utf8_text++= (char)(0x80|y);
*utf8_text++= (char)(0x80|x);
}
return(utf8_text);
}

unsigned u_length(register unsigned int*str)
{
register unsigned len= 0;
while(*str++!='\0')
++len;
return(len);
}


void utf2uni_strcpy(unsigned int*ubuf,const char*utf8buf)
{
int len= (int)strlen(utf8buf)+1;
unsigned int*upt= ubuf,*uend= ubuf+len-1;
const unsigned char*pt= (const unsigned char*)utf8buf,*end= 
pt+strlen(utf8buf);
int w,w2;

while(pt<end&&*pt!='\0'&&upt<uend){
if(*pt<=127)
*upt= *pt++;
else if(*pt<=0xdf){
*upt= (unsigned int)(((*pt&0x1f)<<6)|(pt[1]&0x3f));
pt+= 2;
}else if(*pt<=0xef){
*upt= 
(unsigned int)(((*pt&0xf)<<12)|((pt[1]&0x3f)<<6)|
(pt[2]&0x3f));
pt+= 3;
}else{
w= (((*pt&0x7)<<2)|((pt[1]&0x30)>>4))-1;
w= (w<<6)|((pt[1]&0xf)<<2)|((pt[2]&0x30)>>4);
w2= ((pt[2]&0xf)<<6)|(pt[3]&0x3f);
*upt= (unsigned int)(w*0x400+w2+0x10000);
pt+= 4;
}
++upt;
}
*upt= '\0';
}

/*:7*//*8:*/
#line 190 "./luatexdir/utils/unistring.w"

char*utf16be_str(long code)
{
static char buf[SMALL_BUF_SIZE];
long v;
unsigned vh,vl;

assert(code>=0);

if(code<=0xFFFF)
sprintf(buf,"%04lX",code);
else{
v= code-0x10000;
vh= (unsigned)(v/0x400+0xD800);
vl= (unsigned)(v%0x400+0xDC00);
sprintf(buf,"%04X%04X",vh,vl);
}
return buf;
}

/*:8*/
