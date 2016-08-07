/*2:*/
#line 25 "./luatexdir/tex/errors.w"

#include "ptexlib.h"

/*:2*//*3:*/
#line 28 "./luatexdir/tex/errors.w"

#define new_line_char int_par(new_line_char_code)

/*:3*//*4:*/
#line 53 "./luatexdir/tex/errors.w"

int interaction;
int interactionoption;



char*last_error= NULL;
char*last_lua_error= NULL;
char*last_warning_tag= NULL;
char*last_warning_str= NULL;
char*last_error_context= NULL;

int err_old_setting= 0;
int in_error= 0;

void set_last_error_context(void)
{
str_number str;
int sel= selector;
int saved_new_line_char;
int saved_new_string_line;
selector= new_string;
saved_new_line_char= new_line_char;
saved_new_string_line= new_string_line;
new_line_char= 10;
new_string_line= 10;
show_context();
xfree(last_error_context);
str= make_string();
last_error_context= makecstring(str);
flush_str(str);
selector= sel;
new_line_char= saved_new_line_char;
new_string_line= saved_new_string_line;
return;
}

void flush_err(void)
{
str_number s_error;
char*s= NULL;
int callback_id;
if(in_error){
selector= err_old_setting;
str_room(1);
s_error= make_string();
s= makecstring(s_error);
flush_str(s_error);
if(interaction==error_stop_mode){
wake_up_terminal();
}
xfree(last_error);
last_error= (string)xmalloc((unsigned)(strlen(s)+1));
strcpy(last_error,s);
callback_id= callback_defined(show_error_message_callback);
if(callback_id> 0){
run_callback(callback_id,"->");
}else{
tprint(s);
}
in_error= 0;
}
}

void print_err(const char*s)
{
int callback_id= callback_defined(show_error_message_callback);
if(interaction==error_stop_mode){
wake_up_terminal();
}
if(callback_id> 0){
err_old_setting= selector;
selector= new_string;
in_error= 1;
}
if(filelineerrorstylep){
print_file_line();
}else{
tprint_nl("! ");
}
tprint(s);
if(callback_id<=0){
xfree(last_error);
last_error= (string)xmalloc((unsigned)(strlen(s)+1));
strcpy(last_error,s);
}
}

/*:4*//*5:*/
#line 154 "./luatexdir/tex/errors.w"

void fixup_selector(boolean logopened)
{
if(interaction==batch_mode)
selector= no_print;
else
selector= term_only;
if(logopened)
selector= selector+2;
}

/*:5*//*6:*/
#line 180 "./luatexdir/tex/errors.w"

boolean deletions_allowed;
boolean set_box_allowed;
int history;
int error_count;
int interrupt;
boolean OK_to_interrupt;

/*:6*//*7:*/
#line 191 "./luatexdir/tex/errors.w"

void initialize_errors(void)
{
if(interactionoption==unspecified_mode)
interaction= error_stop_mode;
else
interaction= interactionoption;
deletions_allowed= true;
set_box_allowed= true;
OK_to_interrupt= true;

}

/*:7*//*9:*/
#line 212 "./luatexdir/tex/errors.w"

const char*help_line[7];
boolean use_err_help;

/*:9*//*10:*/
#line 219 "./luatexdir/tex/errors.w"

__attribute__((noreturn))
void do_final_end(void)
{
update_terminal();
ready_already= 0;
if((history!=spotless)&&(history!=warning_issued))
uexit(1);
else
uexit(0);
}

__attribute__((noreturn))
void jump_out(void)
{
close_files_and_terminate();
do_final_end();
}

/*:10*//*11:*/
#line 238 "./luatexdir/tex/errors.w"

void error(void)
{
ASCII_code c;
int callback_id;
int s1,s2,s3,s4;
int i;
flush_err();
if(history<error_message_issued)
history= error_message_issued;
callback_id= callback_defined(show_error_hook_callback);
if(callback_id> 0){
set_last_error_context();
run_callback(callback_id,"->");
}else{
print_char('.');
show_context();
}
if(haltonerrorp){
history= fatal_error_stop;
jump_out();
}
if(interaction==error_stop_mode){

while(1){
CONTINUE:
clear_for_error_prompt();
prompt_input("? ");
if(last==first)
return;
c= buffer[first];
if(c>='a')
c= c+'A'-'a';











switch(c){
case'0':
case'1':
case'2':
case'3':
case'4':
case'5':
case'6':
case'7':
case'8':
case'9':
if(deletions_allowed){


s1= cur_tok;
s2= cur_cmd;
s3= cur_chr;
s4= align_state;
align_state= 1000000;
OK_to_interrupt= false;
if((last> first+1)&&(buffer[first+1]>='0')
&&(buffer[first+1]<='9'))
c= c*10+buffer[first+1]-'0'*11;
else
c= c-'0';
while(c> 0){
get_token();
decr(c);
}
cur_tok= s1;
cur_cmd= s2;
cur_chr= s3;
align_state= s4;
OK_to_interrupt= true;
help2("I have just deleted some text, as you asked.",
"You can now delete more, or insert, or whatever.");
show_context();
goto CONTINUE;
}
break;
#ifdef DEBUG
case'D':
debug_help();
goto CONTINUE;
break;
#endif
case'E':
if(base_ptr> 0){
tprint_nl("You want to edit file ");
print(input_stack[base_ptr].name_field);
tprint(" at line ");
print_int(line);
interaction= scroll_mode;
jump_out();
}
break;
case'H':

if(use_err_help){
give_err_help();
}else{
if(help_line[0]==NULL){
help2
("Sorry, I don't know how to help in this situation.",
"Maybe you should try asking a human?");
}
i= 0;
while(help_line[i]!=NULL)
tprint_nl(help_line[i++]);
help4("Sorry, I already gave what help I could...",
"Maybe you should try asking a human?",
"An error might have occurred before I noticed any problems.",
"``If all else fails, read the instructions.''");
goto CONTINUE;
}
break;
case'I':






begin_file_reading();

if(last> first+1){
iloc= first+1;
buffer[first]= ' ';
}else{
prompt_input("insert>");
iloc= first;
}
first= last;
ilimit= last-1;
return;
break;
case'Q':
case'R':
case'S':




error_count= 0;
interaction= batch_mode+c-'Q';
tprint("OK, entering ");
switch(c){
case'Q':
tprint_esc("batchmode");
decr(selector);
break;
case'R':
tprint_esc("nonstopmode");
break;
case'S':
tprint_esc("scrollmode");
break;
}
tprint("...");
print_ln();
update_terminal();
return;
break;
case'X':
interaction= scroll_mode;
jump_out();
break;
default:
break;
}
if(!use_err_help){

tprint("Type <return> to proceed, S to scroll future error messages,");
tprint_nl("R to run without stopping, Q to run quietly,");
tprint_nl("I to insert something, ");
if(base_ptr> 0)
tprint("E to edit your file,");
if(deletions_allowed)
tprint_nl("1 or ... or 9 to ignore the next 1 to 9 tokens of input,");
tprint_nl("H for help, X to quit.");
}
use_err_help= false;
}

}
incr(error_count);
if(error_count==100){
tprint_nl("(That makes 100 errors; please try again.)");
history= fatal_error_stop;
jump_out();
}

if(interaction> batch_mode)
decr(selector);
if(use_err_help){
print_ln();
give_err_help();
}else{
int i1= 0;
while(help_line[i1]!=NULL)
tprint_nl(help_line[i1++]);
}
print_ln();
if(interaction> batch_mode)
incr(selector);
print_ln();
}

/*:11*//*12:*/
#line 453 "./luatexdir/tex/errors.w"

void int_error(int n)
{
tprint(" (");
print_int(n);
print_char(')');
error();
}

/*:12*//*13:*/
#line 466 "./luatexdir/tex/errors.w"

void normalize_selector(void)
{
if(log_opened_global)
selector= term_and_log;
else
selector= term_only;
if(job_name==0)
open_log_file();
if(interaction==batch_mode)
decr(selector);
}

/*:13*//*14:*/
#line 480 "./luatexdir/tex/errors.w"

void succumb(void)
{
if(interaction==error_stop_mode)
interaction= scroll_mode;
if(log_opened_global)
error();
#ifdef DEBUG
if(interaction> batch_mode)
debug_help();
#endif
history= fatal_error_stop;
jump_out();
}

/*:14*//*15:*/
#line 495 "./luatexdir/tex/errors.w"

void fatal_error(const char*s)
{
normalize_selector();
print_err("Emergency stop");
help1(s);
succumb();
}

/*:15*//*16:*/
#line 505 "./luatexdir/tex/errors.w"

void overflow(const char*s,unsigned int n)
{
normalize_selector();
print_err("TeX capacity exceeded, sorry [");
tprint(s);
print_char('=');
print_int((int)n);
print_char(']');
help2("If you really absolutely need more capacity,",
"you can ask a wizard to enlarge me.");
succumb();
}

/*:16*//*17:*/
#line 527 "./luatexdir/tex/errors.w"

void confusion(const char*s)
{
normalize_selector();
if(history<error_message_issued){
print_err("This can't happen (");
tprint(s);
print_char(')');
help1("I'm broken. Please show this to someone who can fix can fix");
}else{
print_err("I can't go on meeting you like this");
help2("One of your faux pas seems to have wounded me deeply...",
"in fact, I'm barely conscious. Please fix it and try again.");
}
succumb();
}

/*:17*//*18:*/
#line 552 "./luatexdir/tex/errors.w"

void check_interrupt(void)
{
if(interrupt!=0)
pause_for_instructions();
}

/*:18*//*19:*/
#line 564 "./luatexdir/tex/errors.w"

void pause_for_instructions(void)
{
if(OK_to_interrupt){
interaction= error_stop_mode;
if((selector==log_only)||(selector==no_print))
incr(selector);
print_err("Interruption");
help3("You rang?",
"Try to insert some instructions for me (e.g.,`I\\showlists'),",
"unless you just want to quit by typing `X'.");
deletions_allowed= false;
error();
deletions_allowed= true;
interrupt= 0;
}
}

/*:19*//*20:*/
#line 582 "./luatexdir/tex/errors.w"

void tex_error(const char*msg,const char**hlp)
{
print_err(msg);
if(hlp!=NULL){
int i;
for(i= 0;(hlp[i]!=NULL&&i<=5);i++){
help_line[i]= hlp[i];
}
help_line[i]= NULL;
}else{
help_line[0]= NULL;
}
error();
}

/*:20*//*21:*/
#line 603 "./luatexdir/tex/errors.w"

void back_error(void)
{
OK_to_interrupt= false;
back_input();
OK_to_interrupt= true;
error();
}

/*:21*//*22:*/
#line 612 "./luatexdir/tex/errors.w"

void ins_error(void)
{
OK_to_interrupt= false;
back_input();
token_type= inserted;
OK_to_interrupt= true;
error();
}

/*:22*//*23:*/
#line 627 "./luatexdir/tex/errors.w"

void char_warning(internal_font_number f,int c)
{
int old_setting;
int k;
if(int_par(tracing_lost_chars_code)> 0){
old_setting= int_par(tracing_online_code);
if(int_par(tracing_lost_chars_code)> 1)
int_par(tracing_online_code)= 1;
begin_diagnostic();
tprint_nl("Missing character: There is no ");
print(c);
tprint(" (U+");
k= 0;
if(c<16)
print_char('0');
if(c<256)
print_char('0');
if(c<4096)
print_char('0');
do{
dig[k]= c%16;
c= c/16;
incr(k);
}while(c!=0);
print_the_digs((eight_bits)k);
tprint(") in font ");
print_font_name(f);
print_char('!');
end_diagnostic(false);
int_par(tracing_online_code)= old_setting;
}
}

/*:23*//*24:*/
#line 661 "./luatexdir/tex/errors.w"


void wrapup_backend(void){
ensure_output_state(static_pdf,ST_OMODE_FIX);
switch(output_mode_used){
case OMODE_NONE:
print_err(" ==> Fatal error occurred, no FMT file produced!");
break;
case OMODE_PDF:
if(history==fatal_error_stop){
remove_pdffile(static_pdf);
print_err(" ==> Fatal error occurred, no output PDF file produced!");
}else{
finish_pdf_file(static_pdf,luatex_version,get_luatexrevision());
}
break;
case OMODE_DVI:
if(history==fatal_error_stop){
print_err(" ==> Fatal error occurred, bad output DVI file produced!");
finish_dvi_file(static_pdf,luatex_version,get_luatexrevision());
}else{
finish_dvi_file(static_pdf,luatex_version,get_luatexrevision());
}
break;
}
}

void normal_error(const char*t,const char*p)
{
normalize_selector();
print_err("error ");
if(cur_file_name){
tprint(" (file ");
tprint(cur_file_name);
tprint(")");
}
if(t!=NULL){
tprint(" (");
tprint(t);
tprint(")");
}
tprint(": ");
if(p!=NULL)
tprint(p);

history= fatal_error_stop;
wrapup_backend();
exit(EXIT_FAILURE);
}

/*:24*//*25:*/
#line 711 "./luatexdir/tex/errors.w"

void normal_warning(const char*t,const char*p)
{
int report_id;
if(strcmp(t,"lua")==0){
int saved_new_line_char;
saved_new_line_char= new_line_char;
new_line_char= 10;
report_id= callback_defined(show_lua_error_hook_callback);
if(report_id==0){
tprint(p);
help2("The lua interpreter ran into a problem, so the",
"remainder of this lua chunk will be ignored.");
}else{
(void)run_callback(report_id,"->");
}
error();
new_line_char= saved_new_line_char;
}else{
report_id= callback_defined(show_warning_message_callback);
if(report_id> 0){

xfree(last_warning_str);
xfree(last_warning_tag);
last_warning_str= (string)xmalloc(strlen(p)+1);
last_warning_tag= (string)xmalloc(strlen(t)+1);
strcpy(last_warning_str,p);
strcpy(last_warning_tag,t);
run_callback(report_id,"->");
}else{
print_ln();
tprint("warning ");
if(cur_file_name){
tprint(" (file ");
tprint(cur_file_name);
tprint(")");
}
if(t!=NULL){
tprint(" (");
tprint(t);
tprint(")");
}
tprint(": ");
if(p!=NULL)
tprint(p);
print_ln();
}
if(history==spotless)
history= warning_issued;
}
}

/*:25*//*26:*/
#line 763 "./luatexdir/tex/errors.w"

static char print_buf[PRINTF_BUF_SIZE];
__attribute__((format(printf,2,3)))
void formatted_error(const char*t,const char*fmt,...)
{
va_list args;
va_start(args,fmt);
vsnprintf(print_buf,PRINTF_BUF_SIZE,fmt,args);
normal_error(t,print_buf);
va_end(args);
}

__attribute__((format(printf,2,3)))
void formatted_warning(const char*t,const char*fmt,...)
{
va_list args;
va_start(args,fmt);
vsnprintf(print_buf,PRINTF_BUF_SIZE,fmt,args);
normal_warning(t,print_buf);
va_end(args);
}/*:26*/
