/*1:*/
#line 23 "./luatexdir/tex/extensions.w"

#include "ptexlib.h"

/*:1*//*2:*/
#line 26 "./luatexdir/tex/extensions.w"

#define mode     mode_par
#define tail     tail_par
#define head     head_par
#define dir_save dirs_par

/*:2*//*5:*/
#line 93 "./luatexdir/tex/extensions.w"

alpha_file write_file[last_file_selector+1];
halfword write_file_mode[last_file_selector+1];
halfword write_file_translation[last_file_selector+1];
boolean write_open[last_file_selector+1];

scaled neg_wd;
scaled pos_wd;
scaled neg_ht;

/*:5*//*6:*/
#line 106 "./luatexdir/tex/extensions.w"

halfword write_loc;






/*:6*//*7:*/
#line 117 "./luatexdir/tex/extensions.w"

int last_saved_image_index;
int last_saved_image_pages;
int last_saved_box_index;
scaledpos last_position= {0,0};

static void do_extension_dvi(int immediate)
{
if(scan_keyword("literal")){
new_whatsit(special_node);
write_stream(tail)= null;
scan_toks(false,true);
write_tokens(tail)= def_ref;
}else{
tex_error("unexpected use of \\dviextension",null);
}
}

static void do_extension_pdf(int immediate)
{
int i;

if(scan_keyword("literal")){
new_whatsit(pdf_literal_node);
if(scan_keyword("direct"))
set_pdf_literal_mode(tail,direct_always);
else if(scan_keyword("page"))
set_pdf_literal_mode(tail,direct_page);
else
set_pdf_literal_mode(tail,set_origin);
scan_toks(false,true);
set_pdf_literal_type(tail,normal);
set_pdf_literal_data(tail,def_ref);
}else if(scan_keyword("dest")){
scan_pdfdest(static_pdf);
}else if(scan_keyword("annot")){
scan_annot(static_pdf);
}else if(scan_keyword("save")){
new_whatsit(pdf_save_node);
}else if(scan_keyword("restore")){
new_whatsit(pdf_restore_node);
}else if(scan_keyword("setmatrix")){
new_whatsit(pdf_setmatrix_node);
scan_toks(false,true);
set_pdf_setmatrix_data(tail,def_ref);
}else if(scan_keyword("obj")){
scan_obj(static_pdf);
if(immediate){
if(obj_data_ptr(static_pdf,pdf_last_obj)==0)
normal_error("pdf backend","\\pdfextension obj 'reserveobjnum' cannot be used with \\immediate");
pdf_write_obj(static_pdf,pdf_last_obj);
}
}else if(scan_keyword("refobj")){
scan_refobj(static_pdf);
}else if(scan_keyword("colorstack")){
scan_int();
if(cur_val>=colorstackused()){
print_err("Unknown color stack number ");
print_int(cur_val);
help3
("Allocate and initialize a color stack with \\pdfextension colorstackinit.",
"I'll use default color stack 0 here.",
"Proceed, with fingers crossed.");
error();
cur_val= 0;
}
if(cur_val<0){
print_err("Invalid negative color stack number");
help2("I'll use default color stack 0 here.",
"Proceed, with fingers crossed.");
error();
cur_val= 0;
}
if(scan_keyword("set"))
i= colorstack_set;
else if(scan_keyword("push"))
i= colorstack_push;
else if(scan_keyword("pop"))
i= colorstack_pop;
else if(scan_keyword("current"))
i= colorstack_current;
else
i= -1;
if(i>=0){
new_whatsit(pdf_colorstack_node);
set_pdf_colorstack_stack(tail,cur_val);
set_pdf_colorstack_cmd(tail,i);
set_pdf_colorstack_data(tail,null);
if(i<=colorstack_data){
scan_toks(false,true);
set_pdf_colorstack_data(tail,def_ref);
}
}else{
print_err("Color stack action is missing");
help3("The expected actions for \\pdfextension colorstack:",
"    set, push, pop, current",
"I'll ignore the color stack command.");
error();
}
}else if(scan_keyword("startlink")){
scan_startlink(static_pdf);
}else if(scan_keyword("endlink")){
if(abs(mode)==vmode)
normal_error("pdf backend","\\pdfextension endlink cannot be used in vertical mode");
new_whatsit(pdf_end_link_node);
}else if(scan_keyword("startthread")){
new_annot_whatsit(pdf_start_thread_node);
scan_thread_id();
}else if(scan_keyword("endthread")){
new_whatsit(pdf_end_thread_node);
}else if(scan_keyword("thread")){
new_annot_whatsit(pdf_thread_node);
scan_thread_id();
}else if(scan_keyword("outline")){
scan_pdfoutline(static_pdf);
}else if(scan_keyword("glyphtounicode")){
glyph_to_unicode();
}else if(scan_keyword("catalog")){
scan_pdfcatalog(static_pdf);
}else if(scan_keyword("fontattr")){





scan_font_ident();
i= cur_val;
if(i==null_font)
normal_error("pdf backend","invalid font identifier");
scan_toks(false,true);
set_pdf_font_attr(i,tokens_to_string(def_ref));
if(str_length(pdf_font_attr(i))==0){
flush_str((str_ptr-1));
set_pdf_font_attr(i,0);
}
}else if(scan_keyword("mapfile")){
scan_toks(false,true);
pdfmapfile(def_ref);
delete_token_ref(def_ref);
}else if(scan_keyword("mapline")){
scan_toks(false,true);
pdfmapline(def_ref);
delete_token_ref(def_ref);
}else if(scan_keyword("includechars")){
pdf_include_chars(static_pdf);
}else if(scan_keyword("info")){
scan_toks(false,true);
pdf_info_toks= concat_tokens(pdf_info_toks,def_ref);
}else if(scan_keyword("names")){
scan_toks(false,true);
pdf_names_toks= concat_tokens(pdf_names_toks,def_ref);
}else if(scan_keyword("trailer")){
scan_toks(false,true);
pdf_trailer_toks= concat_tokens(pdf_trailer_toks,def_ref);
}else{
tex_error("unexpected use of \\pdfextension",null);
}
}

static void do_resource_dvi(int immediate,int code)
{
}

static void do_resource_pdf(int immediate,int code)
{
switch(code){
case use_box_resource_code:
scan_pdfrefxform(static_pdf);
break;
case use_image_resource_code:
scan_pdfrefximage(static_pdf);
break;
case save_box_resource_code:
scan_pdfxform(static_pdf);
if(immediate){
pdf_cur_form= last_saved_box_index;
ship_out(static_pdf,obj_xform_box(static_pdf,last_saved_box_index),SHIPPING_FORM);
}
break;
case save_image_resource_code:
fix_pdf_minorversion(static_pdf);
scan_pdfximage(static_pdf);
if(immediate){
pdf_write_image(static_pdf,last_saved_image_index);
}
break;
}
}





















/*:7*//*8:*/
#line 329 "./luatexdir/tex/extensions.w"

static void new_write_whatsit(int w,int check)
{
new_whatsit(cur_chr);
if(check){

scan_limited_int(last_file_selector,NULL);
}else{

scan_int();
if(cur_val<0)
cur_val= term_only;
else if(cur_val> last_file_selector){
cur_val= term_and_log;
}
}
write_stream(tail)= cur_val;
}

void do_extension(int immediate)
{
halfword p;
if(cur_cmd==extension_cmd){

switch(cur_chr){
case open_code:
p= tail;
new_write_whatsit(open_node_size,1);
scan_optional_equals();
scan_file_name();
open_name(tail)= cur_name;
open_area(tail)= cur_area;
open_ext(tail)= cur_ext;
if(immediate){
out_what(static_pdf,tail);
flush_node_list(tail);
tail= p;
vlink(p)= null;
}
break;
case write_code:





p= tail;
new_write_whatsit(write_node_size,0);
cur_cs= write_stream(tail);
scan_toks(false,false);
write_tokens(tail)= def_ref;
if(immediate){
out_what(static_pdf,tail);
flush_node_list(tail);
tail= p;
vlink(p)= null;
}
break;
case close_code:
p= tail;
new_write_whatsit(close_node_size,1);
write_tokens(tail)= null;
if(immediate){
out_what(static_pdf,tail);
flush_node_list(tail);
tail= p;
vlink(p)= null;
}
break;
case special_code:




new_whatsit(special_node);
write_stream(tail)= null;
p= scan_toks(false,true);
write_tokens(tail)= def_ref;
break;
case immediate_code:
get_x_token();
do_extension(1);
break;
case use_box_resource_code:
case use_image_resource_code:
case save_box_resource_code:
case save_image_resource_code:
switch(get_o_mode()){
case OMODE_DVI:
do_resource_dvi(immediate,cur_chr);
break;
case OMODE_PDF:
do_resource_pdf(immediate,cur_chr);
break;
default:
break;
}
break;

case dvi_extension_code:
if(get_o_mode()==OMODE_DVI)
do_extension_dvi(immediate);
break;
case pdf_extension_code:
if(get_o_mode()==OMODE_PDF)
do_extension_pdf(immediate);
break;

default:
if(immediate){
back_input();
}else{
confusion("invalid extension");
}
break;
}
}else{

back_input();
}
}

/*:8*//*9:*/
#line 455 "./luatexdir/tex/extensions.w"

void new_whatsit(int s)
{
halfword p= new_node(whatsit_node,s);
couple_nodes(tail,p);
tail= p;
}

/*:9*//*10:*/
#line 471 "./luatexdir/tex/extensions.w"

void expand_macros_in_tokenlist(halfword p)
{
int old_mode;
pointer q= get_avail();
pointer r= get_avail();
token_info(q)= right_brace_token+'}';
token_link(q)= r;
token_info(r)= end_write_token;
begin_token_list(q,inserted);
begin_token_list(write_tokens(p),write_text);
q= get_avail();
token_info(q)= left_brace_token+'{';
begin_token_list(q,inserted);


old_mode= mode;
mode= 0;

cur_cs= write_loc;
q= scan_toks(false,true);
get_token();
if(cur_tok!=end_write_token){

const char*hlp[]= {
"On this page there's a \\write with fewer real {'s than }'s.",
"I can't handle that very well; good luck.",NULL
};
tex_error("Unbalanced write command",hlp);
do{
get_token();
}while(cur_tok!=end_write_token);
}
mode= old_mode;
end_token_list();
}

void write_out(halfword p)
{
int old_setting;
int j;
char*s,*ss;
int callback_id;
int lua_retval;
expand_macros_in_tokenlist(p);
old_setting= selector;
j= write_stream(p);
if(file_can_be_written(j)){
selector= j;
}else if((j==term_only)&&(selector==term_and_log)){

selector= log_only;
tprint_nl("");
}else{
tprint_nl("");
}
s= tokenlist_to_cstring(def_ref,false,NULL);
if(selector<no_print){

callback_id= callback_defined(process_output_buffer_callback);
if(callback_id> 0){

lua_retval= run_callback(callback_id,"S->S",s,&ss);
if((lua_retval==true)&&(ss!=NULL)){
xfree(s);
s= ss;
}
}
}
tprint(s);
xfree(s);
print_ln();
flush_list(def_ref);
selector= old_setting;
}

void finalize_write_files(void){
int k;
for(k= 0;k<=last_file_selector;k++){
if(write_open[k]){
lua_a_close_out(write_file[k]);
}
}
}

void initialize_write_files(void){
int k;
for(k= 0;k<=last_file_selector;k++){
write_open[k]= false;
}
}

void close_write_file(int id){
if(write_open[id]){
lua_a_close_out(write_file[id]);
write_open[id]= false;
}
}

boolean open_write_file(int id,char*fn){
if(lua_a_open_out(&(write_file[id]),fn,(id+1))){
write_open[id]= true;
return true;
}else{
return false;
}
}


/*:10*//*11:*/
#line 583 "./luatexdir/tex/extensions.w"

halfword concat_tokens(halfword q,halfword r)
{
halfword p;
if(q==null)
return r;
p= q;
while(token_link(p)!=null)
p= token_link(p);
set_token_link(p,token_link(r));
free_avail(r);
return q;
}

/*:11*//*13:*/
#line 609 "./luatexdir/tex/extensions.w"

boolean*eof_seen;

/*:13*//*14:*/
#line 615 "./luatexdir/tex/extensions.w"

void print_group(boolean e)
{
switch(cur_group){
case bottom_level:
tprint("bottom level");
return;
break;
case simple_group:
case semi_simple_group:
if(cur_group==semi_simple_group)
tprint("semi ");
tprint("simple");
break;;
case hbox_group:
case adjusted_hbox_group:
if(cur_group==adjusted_hbox_group)
tprint("adjusted ");
tprint("hbox");
break;
case vbox_group:
tprint("vbox");
break;
case vtop_group:
tprint("vtop");
break;
case align_group:
case no_align_group:
if(cur_group==no_align_group)
tprint("no ");
tprint("align");
break;
case output_group:
tprint("output");
break;
case disc_group:
tprint("disc");
break;
case insert_group:
tprint("insert");
break;
case vcenter_group:
tprint("vcenter");
break;
case math_group:
case math_choice_group:
case math_shift_group:
case math_left_group:
tprint("math");
if(cur_group==math_choice_group)
tprint(" choice");
else if(cur_group==math_shift_group)
tprint(" shift");
else if(cur_group==math_left_group)
tprint(" left");
break;
}
tprint(" group (level ");
print_int(cur_level);
print_char(')');
if(saved_value(-1)!=0){
if(e)
tprint(" entered at line ");
else
tprint(" at line ");
print_int(saved_value(-1));
}
}

/*:14*//*15:*/
#line 688 "./luatexdir/tex/extensions.w"

void group_trace(boolean e)
{
begin_diagnostic();
print_char('{');
if(e)
tprint("leaving ");
else
tprint("entering ");
print_group(e);
print_char('}');
end_diagnostic(false);
}

/*:15*//*16:*/
#line 709 "./luatexdir/tex/extensions.w"

save_pointer*grp_stack;
halfword*if_stack;

/*:16*//*17:*/
#line 723 "./luatexdir/tex/extensions.w"

void group_warning(void)
{
boolean w= false;
int i= in_open;
base_ptr= input_ptr;
input_stack[base_ptr]= cur_input;
while((grp_stack[i]==cur_boundary)&&(i> 0)){



if(tracing_nesting_par> 0){
while((input_stack[base_ptr].state_field==token_list)||
(input_stack[base_ptr].index_field> i))
decr(base_ptr);
if(input_stack[base_ptr].name_field> 17)
w= true;
}

grp_stack[i]= save_value(save_ptr);
decr(i);
}
if(w){
tprint_nl("Warning: end of ");
print_group(true);
tprint(" of a different file");
print_ln();
if(tracing_nesting_par> 1)
show_context();
if(history==spotless)
history= warning_issued;
}
}

/*:17*//*18:*/
#line 762 "./luatexdir/tex/extensions.w"

void if_warning(void)
{
boolean w= false;
int i= in_open;
base_ptr= input_ptr;
input_stack[base_ptr]= cur_input;
while(if_stack[i]==cond_ptr){

if(tracing_nesting_par> 0){
while((input_stack[base_ptr].state_field==token_list)||
(input_stack[base_ptr].index_field> i))
decr(base_ptr);
if(input_stack[base_ptr].name_field> 17)
w= true;
}

if_stack[i]= vlink(cond_ptr);
decr(i);
}
if(w){
tprint_nl("Warning: end of ");
print_cmd_chr(if_test_cmd,cur_if);
print_if_line(if_line);
tprint(" of a different file");
print_ln();
if(tracing_nesting_par> 1)
show_context();
if(history==spotless)
history= warning_issued;
}
}


/*:18*//*19:*/
#line 800 "./luatexdir/tex/extensions.w"

void file_warning(void)
{
halfword p= save_ptr;
int l= cur_level;
int c= cur_group;
int i;
save_ptr= cur_boundary;
while(grp_stack[in_open]!=save_ptr){
decr(cur_level);
tprint_nl("Warning: end of file when ");
print_group(true);
tprint(" is incomplete");
cur_group= save_level(save_ptr);
save_ptr= save_value(save_ptr);
}
save_ptr= p;
cur_level= (quarterword)l;
cur_group= (group_code)c;
p= cond_ptr;
l= if_limit;
c= cur_if;
i= if_line;
while(if_stack[in_open]!=cond_ptr){
tprint_nl("Warning: end of file when ");
print_cmd_chr(if_test_cmd,cur_if);
if(if_limit==fi_code)
tprint_esc("else");
print_if_line(if_line);
tprint(" is incomplete");
if_line= if_line_field(cond_ptr);
cur_if= if_limit_subtype(cond_ptr);
if_limit= if_limit_type(cond_ptr);
cond_ptr= vlink(cond_ptr);
}
cond_ptr= p;
if_limit= l;
cur_if= c;
if_line= i;
print_ln();
if(tracing_nesting_par> 1)
show_context();
if(history==spotless)
history= warning_issued;
}

/*:19*//*20:*/
#line 846 "./luatexdir/tex/extensions.w"

halfword last_line_fill;

/*:20*//*21:*/
#line 854 "./luatexdir/tex/extensions.w"

#define get_tex_dimen_register(j) dimen(j)
#define get_tex_skip_register(j) skip(j)
#define get_tex_mu_skip_register(j) mu_skip(j)
#define get_tex_count_register(j) count(j)
#define get_tex_attribute_register(j) attribute(j)
#define get_tex_box_register(j) box(j)



int get_tex_extension_count_register(int i)
{
return(int)int_par(backend_int_base-int_base+i);
}

void set_tex_extension_count_register(int i,int d)
{
int_par(backend_int_base-int_base+i)= d;
}

int get_tex_extension_dimen_register(int i)
{
return(int)dimen_par(backend_dimen_base-dimen_base+i);
}

void set_tex_extension_dimen_register(int i,int d)
{
dimen_par(backend_dimen_base-dimen_base+i)= d;
}

int get_tex_extension_toks_register(int i)
{
return equiv(backend_toks_base+i);
}

int set_tex_dimen_register(int j,scaled v)
{
int a;
if(global_defs_par> 0)
a= 4;
else
a= 0;
word_define(j+scaled_base,v);
return 0;
}

int set_tex_skip_register(int j,halfword v)
{
int a;
if(global_defs_par> 0)
a= 4;
else
a= 0;
if(type(v)!=glue_spec_node)
return 1;
word_define(j+skip_base,v);
return 0;
}

int set_tex_mu_skip_register(int j,halfword v)
{
int a;
if(global_defs_par> 0)
a= 4;
else
a= 0;
if(type(v)!=glue_spec_node)
return 1;
word_define(j+mu_skip_base,v);
return 0;
}

int set_tex_count_register(int j,scaled v)
{
int a;
if(global_defs_par> 0)
a= 4;
else
a= 0;
word_define(j+count_base,v);
return 0;
}

int set_tex_box_register(int j,scaled v)
{
int a;
if(global_defs_par> 0)
a= 4;
else
a= 0;
define(j+box_base,box_ref_cmd,v);
return 0;
}

int set_tex_attribute_register(int j,scaled v)
{
int a;
if(global_defs_par> 0)
a= 4;
else
a= 0;
if(j> max_used_attr)
max_used_attr= j;
attr_list_cache= cache_disabled;
word_define(j+attribute_base,v);
return 0;
}

int get_tex_toks_register(int j)
{
str_number s= get_nullstr();
if(toks(j)!=null){
s= tokens_to_string(toks(j));
}
return s;
}

int set_tex_toks_register(int j,lstring s)
{
int a;
halfword ref= get_avail();
(void)str_toks(s);
set_token_ref_count(ref,0);
set_token_link(ref,token_link(temp_token_head));
if(global_defs_par> 0)
a= 4;
else
a= 0;
define(j+toks_base,call_cmd,ref);
return 0;
}

int scan_tex_toks_register(int j,int c,lstring s)
{
int a;
halfword ref= get_avail();
(void)str_scan_toks(c,s);
set_token_ref_count(ref,0);
set_token_link(ref,token_link(temp_token_head));
if(global_defs_par> 0)
a= 4;
else
a= 0;
define(j+toks_base,call_cmd,ref);
return 0;
}

scaled get_tex_box_width(int j)
{
halfword q= box(j);
if(q!=null)
return width(q);
return 0;
}

int set_tex_box_width(int j,scaled v)
{
halfword q= box(j);
if(q==null)
return 1;
width(q)= v;
return 0;
}

scaled get_tex_box_height(int j)
{
halfword q= box(j);
if(q!=null)
return height(q);
return 0;
}

int set_tex_box_height(int j,scaled v)
{
halfword q= box(j);
if(q==null)
return 1;
height(q)= v;
return 0;
}

scaled get_tex_box_depth(int j)
{
halfword q= box(j);
if(q!=null)
return depth(q);
return 0;
}

int set_tex_box_depth(int j,scaled v)
{
halfword q= box(j);
if(q==null)
return 1;
depth(q)= v;
return 0;
}

/*:21*//*22:*/
#line 1082 "./luatexdir/tex/extensions.w"

int synctexoption;

/*:22*//*23:*/
#line 1098 "./luatexdir/tex/extensions.w"

int synctexoffset;

/*:23*//*25:*/
#line 1190 "./luatexdir/tex/extensions.w"

pool_pointer edit_name_start;
int edit_name_length,edit_line;
int ipcon;
boolean stop_at_space;

/*:25*//*26:*/
#line 1199 "./luatexdir/tex/extensions.w"

int shellenabledp;
int restrictedshell;
char*output_comment;

/*:26*//*27:*/
#line 1206 "./luatexdir/tex/extensions.w"

boolean debug_format_file;/*:27*/
