/*1:*/
#line 20 "./luatexdir/pdf/pdfliteral.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 24 "./luatexdir/pdf/pdfliteral.w"

void pdf_special(PDF pdf,halfword p)
{
int old_setting= selector;
str_number s;
selector= new_string;
show_token_list(token_link(write_tokens(p)),null,-1);
selector= old_setting;
s= make_string();
pdf_literal(pdf,s,scan_special,true);
flush_str(s);
}

/*:2*//*3:*/
#line 42 "./luatexdir/pdf/pdfliteral.w"

void pdf_out_literal(PDF pdf,halfword p)
{
int old_setting;
str_number s;
pdfstructure*ps= pdf->pstruct;
if(pdf_literal_type(p)==normal){
old_setting= selector;
selector= new_string;
show_token_list(token_link(pdf_literal_data(p)),null,-1);
selector= old_setting;
s= make_string();
pdf_literal(pdf,s,pdf_literal_mode(p),false);
flush_str(s);
}else{
switch(pdf_literal_mode(p)){
case set_origin:
pdf_goto_pagemode(pdf);
pdf_set_pos(pdf,pdf->posstruct->pos);
break;
case direct_page:
pdf_goto_pagemode(pdf);
break;
case direct_always:
pdf_end_string_nl(pdf);
ps->need_tm= true;
break;
default:
normal_error("pdf backend","bad literal mode");
break;
}
lua_pdf_literal(pdf,pdf_literal_data(p));
}
}

/*:3*//*4:*/
#line 78 "./luatexdir/pdf/pdfliteral.w"

static boolean str_in_cstr(str_number s,const char*r,unsigned i)
{
const unsigned char*k,*l;
if((unsigned)str_length(s)<i+strlen(r))
return false;
k= (const unsigned char*)r;
l= str_string(s)+i;
while((*l)&&(*k)){
if(*l++!=*k++)
return false;
}
return true;
}

/*:4*//*5:*/
#line 93 "./luatexdir/pdf/pdfliteral.w"

void pdf_literal(PDF pdf,str_number s,int literal_mode,boolean warn)
{
unsigned char*ss;
size_t l;
pool_pointer j= 0;
pdfstructure*p= pdf->pstruct;
if(s>=STRING_OFFSET){

j= 0;

if(literal_mode==scan_special){
if(!(str_in_cstr(s,"PDF:",0)||str_in_cstr(s,"pdf:",0))){
if(warn&&((!(str_in_cstr(s,"SRC:",0)||str_in_cstr(s,"src:",0)))||(str_length(s)==0)))
tprint_nl("Non-PDF special ignored!");
return;
}
j= j+(pool_pointer)strlen("PDF:");
if(str_in_cstr(s,"direct:",strlen("PDF:"))){
j= j+(pool_pointer)strlen("direct:");
literal_mode= direct_always;
}else if(str_in_cstr(s,"page:",strlen("PDF:"))){
j= j+(pool_pointer)strlen("page:");
literal_mode= direct_page;
}else{
literal_mode= set_origin;
}
}
}
switch(literal_mode){
case set_origin:
pdf_goto_pagemode(pdf);
pdf_set_pos(pdf,pdf->posstruct->pos);
break;
case direct_page:
pdf_goto_pagemode(pdf);
break;
case direct_always:
pdf_end_string_nl(pdf);
p->need_tm= true;
break;
default:
normal_error("pdf backend","bad literal mode");
break;
}
if(s>=STRING_OFFSET){
ss= str_string(s);
l= str_length(s)-(size_t)j;
pdf_out_block(pdf,(const char*)(ss+j),l);
}else{
pdf_out(pdf,s);
}
pdf_out(pdf,'\n');
}/*:5*/
