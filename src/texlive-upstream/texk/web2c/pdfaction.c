/*1:*/
#line 20 "./luatexdir/pdf/pdfaction.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 26 "./luatexdir/pdf/pdfaction.w"
halfword scan_action(PDF pdf)
{
int p= new_node(whatsit_node,pdf_action_node);
(void)pdf;
if(scan_keyword("user"))
set_pdf_action_type(p,pdf_action_user);
else if(scan_keyword("goto"))
set_pdf_action_type(p,pdf_action_goto);
else if(scan_keyword("thread"))
set_pdf_action_type(p,pdf_action_thread);
else
normal_error("pdf backend","action type missing");
if(pdf_action_type(p)==pdf_action_user){
scan_toks(false,true);
set_pdf_action_tokens(p,def_ref);
return p;
}
if(scan_keyword("file")){
scan_toks(false,true);
set_pdf_action_file(p,def_ref);
}
if(scan_keyword("page")){
if(pdf_action_type(p)!=pdf_action_goto)
normal_error("pdf backend","only GoTo action can be used with 'page'");
set_pdf_action_type(p,pdf_action_page);
scan_int();
if(cur_val<=0)
normal_error("pdf backend","page number must be positive");
set_pdf_action_id(p,cur_val);
set_pdf_action_named_id(p,0);
scan_toks(false,true);
set_pdf_action_tokens(p,def_ref);
}else if(scan_keyword("name")){
scan_toks(false,true);
set_pdf_action_named_id(p,1);
set_pdf_action_id(p,def_ref);
}else if(scan_keyword("num")){
if((pdf_action_type(p)==pdf_action_goto)&&
(pdf_action_file(p)!=null))
normal_error("pdf backend","'goto' option cannot be used with both 'file' and 'num'");
scan_int();
if(cur_val<=0)
normal_error("pdf backend","num identifier must be positive");
set_pdf_action_named_id(p,0);
set_pdf_action_id(p,cur_val);
}else{
normal_error("pdf backend","identifier type missing");
}
if(scan_keyword("newwindow")){
set_pdf_action_new_window(p,pdf_window_new);

get_x_token();
if(cur_cmd!=spacer_cmd)
back_input();
}else if(scan_keyword("nonewwindow")){
set_pdf_action_new_window(p,pdf_window_nonew);

get_x_token();
if(cur_cmd!=spacer_cmd)
back_input();
}else{
set_pdf_action_new_window(p,pdf_window_notset);
}
if((pdf_action_new_window(p)> pdf_window_notset)&&
(((pdf_action_type(p)!=pdf_action_goto)&&
(pdf_action_type(p)!=pdf_action_page))||
(pdf_action_file(p)==null)))
normal_error("pdf backend","'newwindow' or 'nonewwindow' must be used with 'goto' and 'file' option");
return p;
}

/*:2*//*3:*/
#line 99 "./luatexdir/pdf/pdfaction.w"
void write_action(PDF pdf,halfword p)
{
char*s;
int d= 0;
if(pdf_action_type(p)==pdf_action_user){
pdf_out(pdf,'\n');
pdf_print_toks(pdf,pdf_action_tokens(p));
pdf_out(pdf,'\n');
return;
}
pdf_begin_dict(pdf);
if(pdf_action_file(p)!=null){
pdf_add_name(pdf,"F");
pdf_out(pdf,' ');
s= tokenlist_to_cstring(pdf_action_file(p),true,NULL);
pdf_print_str(pdf,s);
xfree(s);
pdf_out(pdf,' ');
if(pdf_action_new_window(p)> pdf_window_notset){
if(pdf_action_new_window(p)==pdf_window_new)
pdf_dict_add_bool(pdf,"NewWindow",1);
else
pdf_dict_add_bool(pdf,"NewWindow",0);
}
}
switch(pdf_action_type(p)){
case pdf_action_page:
pdf_dict_add_name(pdf,"S","GoTo");
if(pdf_action_file(p)==null){
pdf_add_name(pdf,"D");
pdf_begin_array(pdf);
pdf_add_ref(pdf,pdf_get_obj(pdf,obj_type_page,pdf_action_id(p),false));
}else{
pdf_add_name(pdf,"D");
pdf_begin_array(pdf);
pdf_print_int(pdf,pdf_action_id(p)-1);
}
{
char*tokstr= tokenlist_to_cstring(pdf_action_tokens(p),true,NULL);
pdf_printf(pdf," %s",tokstr);
pdf_end_array(pdf);
xfree(tokstr);
}
break;
case pdf_action_goto:
if(pdf_action_file(p)==null){
pdf_dict_add_name(pdf,"S","GoTo");
d= pdf_get_obj(pdf,obj_type_dest,pdf_action_id(p),pdf_action_named_id(p));
}else
pdf_dict_add_name(pdf,"S","GoToR");
if(pdf_action_named_id(p)> 0){
char*tokstr= tokenlist_to_cstring(pdf_action_id(p),true,NULL);
pdf_dict_add_string(pdf,"D",tokstr);
xfree(tokstr);
}else if(pdf_action_file(p)==null){
pdf_dict_add_ref(pdf,"D",d);
}else{
normal_error("pdf backend","'goto' option cannot be used with both 'file' and 'num'");
}
break;
case pdf_action_thread:
pdf_dict_add_name(pdf,"S","Thread");
if(pdf_action_file(p)==null){
d= pdf_get_obj(pdf,obj_type_thread,pdf_action_id(p),pdf_action_named_id(p));
if(pdf_action_named_id(p)> 0){
char*tokstr= tokenlist_to_cstring(pdf_action_id(p),true,NULL);
pdf_dict_add_string(pdf,"D",tokstr);
xfree(tokstr);
}else if(pdf_action_file(p)==null){
pdf_dict_add_ref(pdf,"D",d);
}else{
pdf_dict_add_int(pdf,"D",pdf_action_id(p));
}
}
break;
}
pdf_end_dict(pdf);
}/*:3*/
