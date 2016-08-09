/*1:*/
#line 20 "./luatexdir/tex/inputstack.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 24 "./luatexdir/tex/inputstack.w"

in_state_record*input_stack= NULL;
int input_ptr= 0;
int max_in_stack= 0;
in_state_record cur_input;

int in_open= 0;
int open_parens= 0;
alpha_file*input_file= NULL;
int line= 0;
int*line_stack= NULL;
str_number*source_filename_stack= NULL;
char**full_source_filename_stack= NULL;

int scanner_status= 0;
pointer warning_index= null;
pointer def_ref= null;

/*:2*//*3:*/
#line 45 "./luatexdir/tex/inputstack.w"

void runaway(void)
{
pointer p= null;
if(scanner_status> skipping){
switch(scanner_status){
case defining:
tprint_nl("Runaway definition");
p= def_ref;
break;
case matching:
tprint_nl("Runaway argument");
p= temp_token_head;
break;
case aligning:
tprint_nl("Runaway preamble");
p= hold_token_head;
break;
case absorbing:
tprint_nl("Runaway text");
p= def_ref;
break;
default:

break;
}
print_char('?');
print_ln();
show_token_list(token_link(p),null,error_line-10);
}
}

/*:3*//*4:*/
#line 82 "./luatexdir/tex/inputstack.w"

pointer*param_stack= NULL;
int param_ptr= 0;
int max_param_stack= 0;

/*:4*//*5:*/
#line 97 "./luatexdir/tex/inputstack.w"

int align_state= 0;

/*:5*//*6:*/
#line 108 "./luatexdir/tex/inputstack.w"

int base_ptr= 0;

/*:6*//*7:*/
#line 118 "./luatexdir/tex/inputstack.w"

static void print_token_list_type(int t)
{
switch(t){
case parameter:
tprint_nl("<argument> ");
break;
case u_template:
case v_template:
tprint_nl("<template> ");
break;
case backed_up:
if(iloc==null)
tprint_nl("<recently read> ");
else
tprint_nl("<to be read again> ");
break;
case inserted:
tprint_nl("<inserted text> ");
break;
case macro:
print_ln();
print_cs(iname);
break;
case output_text:
tprint_nl("<output> ");
break;
case every_par_text:
tprint_nl("<everypar> ");
break;
case every_math_text:
tprint_nl("<everymath> ");
break;
case every_display_text:
tprint_nl("<everydisplay> ");
break;
case every_hbox_text:
tprint_nl("<everyhbox> ");
break;
case every_vbox_text:
tprint_nl("<everyvbox> ");
break;
case every_job_text:
tprint_nl("<everyjob> ");
break;
case every_cr_text:
tprint_nl("<everycr> ");
break;
case mark_text:
tprint_nl("<mark> ");
break;
case every_eof_text:
tprint_nl("<everyeof> ");
break;
case write_text:
tprint_nl("<write> ");
break;
default:
tprint_nl("?");

break;
}
}

/*:7*//*9:*/
#line 215 "./luatexdir/tex/inputstack.w"

void set_trick_count(void)
{
first_count= tally;
trick_count= tally+1+error_line-half_error_line;
if(trick_count<error_line)
trick_count= error_line;
}

#define begin_pseudoprint() do { \
    l= tally; \
    tally= 0; \
    selector= pseudo; \
    trick_count= 1000000; \
  } while (0)

#define PSEUDO_PRINT_THE_LINE() do { \
    begin_pseudoprint(); \
    if (buffer[ilimit]==end_line_char_par) \
        j= ilimit; \
    else \
        j= ilimit+1;  \
    if (j> 0) { \
        for (i= istart;i<=j-1;i++) { \
            if (i==iloc) \
                set_trick_count(); \
            print_char(buffer[i]); \
        } \
    } \
} while (0)







#define print_valid_utf8(q) do { \
    c =  (int)trick_buf[q % error_line]; \
    if (c < 128) { \
        print_char(c); \
    } else if (c < 194) { \
         \
    } else if (c < 224) { \
        print_char(c); \
        print_char(trick_buf[(q+1) % error_line]); \
    } else if (c < 240) { \
        print_char(c); \
        print_char(trick_buf[(q+1) % error_line]); \
        print_char(trick_buf[(q+2) % error_line]); \
    } else if (c < 245) { \
        print_char(c); \
        print_char(trick_buf[(q+1) % error_line]); \
        print_char(trick_buf[(q+2) % error_line]); \
        print_char(trick_buf[(q+3) % error_line]); \
    } else { \
         \
    } \
} while (0)

/*:9*//*10:*/
#line 275 "./luatexdir/tex/inputstack.w"

void show_context(void)
{
int old_setting;
int nn= -1;
boolean bottom_line= false;
int i;
int j;
int l;
int m;
int n;
int p;
int q;
int c;
base_ptr= input_ptr;
input_stack[base_ptr]= cur_input;

while(true){
cur_input= input_stack[base_ptr];
if(istate!=token_list){
if((iname> 21)||(base_ptr==0))
bottom_line= true;
}
if((base_ptr==input_ptr)||bottom_line||(nn<error_context_lines_par)){

if((base_ptr==input_ptr)||(istate!=token_list)||(token_type!=backed_up)||(iloc!=null)){

tally= 0;
old_setting= selector;
if(istate!=token_list){







if(iname<=17){
if(terminal_input){
if(base_ptr==0)
tprint_nl("<*>");
else
tprint_nl("<insert> ");
}else{
tprint_nl("<read ");
if(iname==17)
print_char('*');
else
print_int(iname-1);
print_char('>');
};
}else{
tprint_nl("l.");
if(iindex==in_open){
print_int(line);
}else{
print_int(line_stack[iindex+1]);
}
}
print_char(' ');
PSEUDO_PRINT_THE_LINE();
}else{
print_token_list_type(token_type);

begin_pseudoprint();
if(token_type<macro)
show_token_list(istart,iloc,100000);
else
show_token_list(token_link(istart),iloc,100000);
}

selector= old_setting;

if(trick_count==1000000)
set_trick_count();

if(tally<trick_count)
m= tally-first_count;
else
m= trick_count-first_count;
if(l+first_count<=half_error_line){
p= 0;
n= l+first_count;
}else{
tprint("...");
p= l+first_count-half_error_line+3;
n= half_error_line;
}
for(q= p;q<=first_count-1;q++)
print_valid_utf8(q);
print_ln();

for(q= 1;q<=n;q++)
print_char(' ');
if(m+n<=error_line)
p= first_count+m;
else
p= first_count+(error_line-n-3);
for(q= first_count;q<=p-1;q++)
print_valid_utf8(q);
if(m+n> error_line)
tprint("...");
incr(nn);
}
}else if(nn==error_context_lines_par){
tprint_nl("...");
incr(nn);

}
if(bottom_line)
break;
decr(base_ptr);
}

cur_input= input_stack[input_ptr];
}

/*:10*//*11:*/
#line 397 "./luatexdir/tex/inputstack.w"




# define pop_input() \
    cur_input= input_stack[--input_ptr]

# define push_input() \
    if (input_ptr >  max_in_stack) { \
        max_in_stack =  input_ptr; \
        if (input_ptr == stack_size) \
            overflow("input stack size", (unsigned) stack_size); \
    } \
    input_stack[input_ptr] =  cur_input; \
    nofilter =  false; \
    incr(input_ptr);

/*:11*//*12:*/
#line 419 "./luatexdir/tex/inputstack.w"

void begin_token_list(halfword p,quarterword t)
{
push_input();
istate= token_list;
istart= p;
token_type= (unsigned char)t;
if(t>=macro){

add_token_ref(p);
if(t==macro){
param_start= param_ptr;
}else{
iloc= token_link(p);
if(tracing_macros_par> 1){
begin_diagnostic();
tprint_nl("");
if(t==mark_text)
tprint_esc("mark");
else if(t==write_text)
tprint_esc("write");
else
print_cmd_chr(assign_toks_cmd,
t-output_text+output_routine_loc);
tprint("->");
token_show(p);
end_diagnostic(false);
}
}
}else{
iloc= p;
}
}

/*:12*//*13:*/
#line 458 "./luatexdir/tex/inputstack.w"

void end_token_list(void)
{

if(token_type>=backed_up){

if(token_type<=inserted){
flush_list(istart);
}else{

delete_token_ref(istart);
if(token_type==macro){

while(param_ptr> param_start){
decr(param_ptr);
flush_list(param_stack[param_ptr]);
}
}
}
}else if(token_type==u_template){
if(align_state> 500000)
align_state= 0;
else
fatal_error("(interwoven alignment preambles are not allowed)");
}
pop_input();
check_interrupt();
}

/*:13*//*14:*/
#line 495 "./luatexdir/tex/inputstack.w"




void back_input(void)
{
halfword p;
while((istate==token_list)&&(iloc==null)&&(token_type!=v_template)){

end_token_list();
}
p= get_avail();
set_token_info(p,cur_tok);
if(cur_tok<right_brace_limit){
if(cur_tok<left_brace_limit)
decr(align_state);
else
incr(align_state);
}
push_input();
istate= token_list;
istart= p;
token_type= backed_up;
iloc= p;
}

/*:14*//*15:*/
#line 522 "./luatexdir/tex/inputstack.w"


void reinsert_token(boolean a,halfword pp)
{
halfword t;
t= cur_tok;
cur_tok= pp;
if(a){
halfword p;
p= get_avail();
set_token_info(p,cur_tok);
set_token_link(p,iloc);
iloc= p;
istart= p;
if(cur_tok<right_brace_limit){
if(cur_tok<left_brace_limit)
decr(align_state);
else
incr(align_state);
}
}else{
back_input();
}
cur_tok= t;
}

/*:15*//*16:*/
#line 554 "./luatexdir/tex/inputstack.w"

void begin_file_reading(void)
{
if(in_open==max_in_open)
overflow("text input levels",(unsigned)max_in_open);
if(first==buf_size)
check_buffer_overflow(first);
incr(in_open);
push_input();
iindex= (unsigned char)in_open;
source_filename_stack[iindex]= 0;
full_source_filename_stack[iindex]= NULL;
eof_seen[iindex]= false;
grp_stack[iindex]= cur_boundary;
if_stack[iindex]= cond_ptr;
line_stack[iindex]= line;
istart= first;
istate= mid_line;
iname= 0;
line_catcode_table= DEFAULT_CAT_TABLE;
line_partial= false;

synctex_tag= 0;
}

/*:16*//*17:*/
#line 582 "./luatexdir/tex/inputstack.w"

void end_file_reading(void)
{
first= istart;
line= line_stack[iindex];
if((iname>=18)&&(iname<=20))
pseudo_close();
else if(iname==21)
luacstring_close(iindex);
else if(iname> 17)
lua_a_close_in(cur_file,0);
pop_input();
decr(in_open);
}

/*:17*//*18:*/
#line 601 "./luatexdir/tex/inputstack.w"

void clear_for_error_prompt(void)
{
while((istate!=token_list)&&terminal_input
&&(input_ptr> 0)&&(iloc> ilimit))
end_file_reading();
print_ln();
clear_terminal();
}

/*:18*//*19:*/
#line 613 "./luatexdir/tex/inputstack.w"

void initialize_inputstack(void)
{
input_ptr= 0;
max_in_stack= 0;
source_filename_stack[0]= 0;

full_source_filename_stack[0]= NULL;
in_open= 0;
open_parens= 0;
max_buf_stack= 0;

grp_stack[0]= 0;
if_stack[0]= null;
param_ptr= 0;
max_param_stack= 0;
first= buf_size;
do{
buffer[first]= 0;
decr(first);
}while(first!=0);
scanner_status= normal;
warning_index= null;
first= 1;
istate= new_line;
istart= 1;
iindex= 0;
line= 0;
iname= 0;
nofilter= false;
force_eof= false;
luacstrings= 0;
line_catcode_table= DEFAULT_CAT_TABLE;
line_partial= false;
align_state= 1000000;
if(!init_terminal())
exit(EXIT_FAILURE);
ilimit= last;
first= last+1;
}

/*:19*//*20:*/
#line 669 "./luatexdir/tex/inputstack.w"

halfword pseudo_files;

static halfword string_to_pseudo(str_number str,int nl)
{
halfword i,r,q= null;
unsigned l,len;
four_quarters w;
int sz;
halfword h= new_node(pseudo_file_node,0);
unsigned char*s= str_string(str);
len= (unsigned)str_length(str);
l= 0;
while(l<len){
unsigned m= l;
while((l<len)&&(s[l]!=nl))
l++;
sz= (int)(l-m+7)/4;
if(sz==1)
sz= 2;
r= new_node(pseudo_line_node,sz);
i= r;
while(--sz> 1){
w.b0= s[m++];
w.b1= s[m++];
w.b2= s[m++];
w.b3= s[m++];
varmem[++i].qqqq= w;
}
w.b0= (quarterword)(l> m?s[m++]:' ');
w.b1= (quarterword)(l> m?s[m++]:' ');
w.b2= (quarterword)(l> m?s[m++]:' ');
w.b3= (quarterword)(l> m?s[m]:' ');
varmem[++i].qqqq= w;
if(q==null){
pseudo_lines(h)= r;
}else{
vlink(q)= r;
}
q= r;
if(s[l]==nl)
l++;
}
return h;
}

/*:20*//*21:*/
#line 717 "./luatexdir/tex/inputstack.w"

void pseudo_from_string(void)
{
str_number s;
halfword p;
s= make_string();

p= string_to_pseudo(s,new_line_char_par);
vlink(p)= pseudo_files;
pseudo_files= p;
flush_str(s);

begin_file_reading();
line= 0;
ilimit= istart;
iloc= ilimit+1;
if(tracing_scan_tokens_par> 0){
if(term_offset> max_print_line-3)
print_ln();
else if((term_offset> 0)||(file_offset> 0))
print_char(' ');
iname= 20;
tprint("( ");
incr(open_parens);
update_terminal();
}else{
iname= 18;
}

synctex_tag= 0;
}

void pseudo_start(void)
{
int old_setting;
scan_general_text();
old_setting= selector;
selector= new_string;
token_show(temp_token_head);
selector= old_setting;
flush_list(token_link(temp_token_head));
str_room(1);
pseudo_from_string();
}

/*:21*//*22:*/
#line 762 "./luatexdir/tex/inputstack.w"

void lua_string_start(void)
{
begin_file_reading();
line= 0;
ilimit= istart;
iloc= ilimit+1;
iname= 21;
luacstring_start(iindex);
}

/*:22*//*23:*/
#line 775 "./luatexdir/tex/inputstack.w"



boolean pseudo_input(void)
{
halfword p;
int sz;
four_quarters w;
halfword r;
last= first;
p= pseudo_lines(pseudo_files);
if(p==null){
return false;
}else{
pseudo_lines(pseudo_files)= vlink(p);
sz= subtype(p);
if(4*sz-3>=buf_size-last)
check_buffer_overflow(last+4*sz);
last= first;
for(r= p+1;r<=p+sz-1;r++){
w= varmem[r].qqqq;
buffer[last]= (packed_ASCII_code)w.b0;
buffer[last+1]= (packed_ASCII_code)w.b1;
buffer[last+2]= (packed_ASCII_code)w.b2;
buffer[last+3]= (packed_ASCII_code)w.b3;
last+= 4;
}
if(last>=max_buf_stack)
max_buf_stack= last+1;
while((last> first)&&(buffer[last-1]==' '))
decr(last);
flush_node(p);
}
return true;
}

/*:23*//*24:*/
#line 813 "./luatexdir/tex/inputstack.w"



void pseudo_close(void)
{
halfword p;
p= vlink(pseudo_files);
flush_node(pseudo_files);
pseudo_files= p;
}/*:24*/
