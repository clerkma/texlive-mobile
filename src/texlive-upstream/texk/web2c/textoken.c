/*1:*/
#line 20 "./luatexdir/tex/textoken.w"


#include "ptexlib.h"

/*:1*//*2:*/
#line 24 "./luatexdir/tex/textoken.w"

#define detokenized_line() (line_catcode_table==NO_CAT_TABLE)












#define do_get_cat_code(a,b) do { \
    if (line_catcode_table==DEFAULT_CAT_TABLE) \
      a= get_cat_code(cat_code_table_par,b); \
    else if (line_catcode_table> -0xFF) \
      a= get_cat_code(line_catcode_table,b); \
    else \
      a=  - line_catcode_table - 0xFF ; \
  } while (0)


/*:2*//*4:*/
#line 64 "./luatexdir/tex/textoken.w"

smemory_word*fixmem;
unsigned fix_mem_min;
unsigned fix_mem_max;

/*:4*//*5:*/
#line 75 "./luatexdir/tex/textoken.w"

int var_used,dyn_used;

halfword avail;
unsigned fix_mem_end;

halfword garbage;
halfword temp_token_head;
halfword hold_token_head;
halfword omit_template;
halfword null_list;
halfword backup_head;

/*:5*//*6:*/
#line 88 "./luatexdir/tex/textoken.w"

void initialize_tokens(void)
{
halfword p;
avail= null;
fix_mem_end= 0;
p= get_avail();
temp_token_head= p;
set_token_info(temp_token_head,0);
p= get_avail();
hold_token_head= p;
set_token_info(hold_token_head,0);
p= get_avail();
omit_template= p;
set_token_info(omit_template,0);
p= get_avail();
null_list= p;
set_token_info(null_list,0);
p= get_avail();
backup_head= p;
set_token_info(backup_head,0);
p= get_avail();
garbage= p;
set_token_info(garbage,0);
dyn_used= 0;
}

/*:6*//*7:*/
#line 124 "./luatexdir/tex/textoken.w"

halfword get_avail(void)
{
unsigned p;
unsigned t;
p= (unsigned)avail;
if(p!=null){
avail= token_link(avail);
}else if(fix_mem_end<fix_mem_max){
incr(fix_mem_end);
p= fix_mem_end;
}else{
smemory_word*new_fixmem;
t= (fix_mem_max/5);
new_fixmem= 
fixmemcast(realloc
(fixmem,sizeof(smemory_word)*(fix_mem_max+t+1)));
if(new_fixmem==NULL){
runaway();
overflow("token memory size",fix_mem_max);
}else{
fixmem= new_fixmem;
}
memset(voidcast(fixmem+fix_mem_max+1),0,t*sizeof(smemory_word));
fix_mem_max+= t;
p= ++fix_mem_end;
}
token_link(p)= null;
incr(dyn_used);
return(halfword)p;
}

/*:7*//*8:*/
#line 160 "./luatexdir/tex/textoken.w"

void flush_list(halfword p)
{
halfword q,r;
if(p!=null){
r= p;
do{
q= r;
r= token_link(r);
decr(dyn_used);
}while(r!=null);
token_link(q)= avail;
avail= p;
}
}

/*:8*//*10:*/
#line 240 "./luatexdir/tex/textoken.w"

void print_meaning(void)
{






print_cmd_chr((quarterword)cur_cmd,cur_chr);
if(cur_cmd>=call_cmd){
print_char(':');
print_ln();
token_show(cur_chr);
}else{

if((cur_cmd==top_bot_mark_cmd)&&(cur_chr<marks_code)){
print_char(':');
print_ln();
switch(cur_chr){
case first_mark_code:
token_show(first_mark(0));
break;
case bot_mark_code:
token_show(bot_mark(0));
break;
case split_first_mark_code:
token_show(split_first_mark(0));
break;
case split_bot_mark_code:
token_show(split_bot_mark(0));
break;
default:
token_show(top_mark(0));
break;
}
}
}
}

/*:10*//*11:*/
#line 304 "./luatexdir/tex/textoken.w"

#define not_so_bad(p) \
    switch (m) { \
        case assign_int_cmd: \
            if (c >= (backend_int_base) && c <= (backend_int_last)) \
                p("[internal backend integer]"); \
            break; \
        case assign_dimen_cmd: \
            if (c >= (backend_dimen_base) && c <= (backend_dimen_last)) \
                p("[internal backend dimension]"); \
            break; \
        case assign_toks_cmd: \
            if (c >= (backend_toks_base) && c <= (backend_toks_last)) \
                p("[internal backend tokenlist]"); \
            break; \
        default: \
            p("BAD"); \
            break; \
    }

void show_token_list(int p,int q,int l)
{
int m,c;
ASCII_code match_chr= '#';
ASCII_code n= '0';
tally= 0;
if(l<0)
l= 0x3FFFFFFF;
while((p!=null)&&(tally<l)){
if(p==q){

set_trick_count();
}

if((p<(int)fix_mem_min)||(p> (int)fix_mem_end)){
tprint_esc("CLOBBERED.");
return;
}
if(token_info(p)>=cs_token_flag){
if(!((inhibit_par_tokens)&&(token_info(p)==par_token)))
print_cs(token_info(p)-cs_token_flag);
}else{
m= token_cmd(token_info(p));
c= token_chr(token_info(p));
if(token_info(p)<0){
tprint_esc("BAD");
}else{







switch(m){
case left_brace_cmd:
case right_brace_cmd:
case math_shift_cmd:
case tab_mark_cmd:
case sup_mark_cmd:
case sub_mark_cmd:
case spacer_cmd:
case letter_cmd:
case other_char_cmd:
print(c);
break;
case mac_param_cmd:
if(!in_lua_escape&&(is_in_csname==0))
print(c);
print(c);
break;
case out_param_cmd:
print(match_chr);
if(c<=9){
print_char(c+'0');
}else{
print_char('!');
return;
}
break;
case match_cmd:
match_chr= c;
print(c);
incr(n);
print_char(n);
if(n> '9')
return;
break;
case end_match_cmd:
if(c==0)
tprint("->");
break;
default:
not_so_bad(tprint);
break;
}
}
}
p= token_link(p);
}
if(p!=null)
tprint_esc("ETC.");
}

/*:11*//*12:*/
#line 408 "./luatexdir/tex/textoken.w"

#define do_buffer_to_unichar(a,b) do { \
    a =  (halfword)str2uni(buffer+b); \
    b +=  utf8_size(a); \
} while (0)

/*:12*//*13:*/
#line 417 "./luatexdir/tex/textoken.w"

void token_show(halfword p)
{
if(p!=null)
show_token_list(token_link(p),null,10000000);
}

/*:13*//*15:*/
#line 432 "./luatexdir/tex/textoken.w"

void delete_token_ref(halfword p)
{
if(token_ref_count(p)==0)
flush_list(p);
else
decr(token_ref_count(p));
}

/*:15*//*16:*/
#line 441 "./luatexdir/tex/textoken.w"

int get_char_cat_code(int curchr)
{
int a;
do_get_cat_code(a,curchr);
return a;
}

/*:16*//*17:*/
#line 449 "./luatexdir/tex/textoken.w"

static void invalid_character_error(void)
{
const char*hlp[]= {
"A funny symbol that I can't read has just been input.",
"Continue, and I'll forget that it ever happened.",
NULL
};
deletions_allowed= false;
tex_error("Text line contains an invalid character",hlp);
deletions_allowed= true;
}

/*:17*//*18:*/
#line 462 "./luatexdir/tex/textoken.w"

static boolean process_sup_mark(void);

static int scan_control_sequence(void);

typedef enum{
next_line_ok,
next_line_return,
next_line_restart
}next_line_retval;

static next_line_retval next_line(void);

/*:18*//*19:*/
#line 488 "./luatexdir/tex/textoken.w"

boolean scan_keyword(const char*s)
{
halfword p;
halfword q;
const char*k;
halfword save_cur_cs= cur_cs;
if(strlen(s)==0)
return false;
p= backup_head;
token_link(p)= null;
k= s;
while(*k){
get_x_token();
if((cur_cs==0)&&((cur_chr==*k)||(cur_chr==*k-'a'+'A'))){
store_new_token(cur_tok);
k++;
}else if((cur_cmd!=spacer_cmd)||(p!=backup_head)){













back_input();
if(p!=backup_head){
begin_token_list(token_link(backup_head),backed_up);
}

cur_cs= save_cur_cs;
return false;
}
}
if(token_link(backup_head)!=null)
flush_list(token_link(backup_head));
cur_cs= save_cur_cs;
return true;
}

/*:19*//*20:*/
#line 537 "./luatexdir/tex/textoken.w"































halfword active_to_cs(int curchr,int force)
{
halfword curcs;
int nncs= no_new_control_sequence;
if(force){
no_new_control_sequence= false;
}
if(curchr> 0){
char*b= (char*)uni2str((unsigned)curchr);
char*utfbytes= xmalloc(8);
utfbytes= strcpy(utfbytes,"\xEF\xBF\xBF");
utfbytes= strcat(utfbytes,b);
free(b);
curcs= string_lookup(utfbytes,utf8_size(curchr)+3);
free(utfbytes);
}else{
curcs= string_lookup("\xEF\xBF\xBF",4);
}
no_new_control_sequence= nncs;
return curcs;
}























































/*:20*//*22:*/
#line 648 "./luatexdir/tex/textoken.w"

static char*cs_to_string(halfword p)
{
const char*s;
char*sh;
int k= 0;
static char ret[256]= {0};
if(p==0||p==null_cs){
ret[k++]= '\\';
s= "csname";
while(*s){
ret[k++]= *s++;
}
ret[k++]= '\\';
s= "endcsname";
while(*s){
ret[k++]= *s++;
}
ret[k]= 0;

}else{
str_number txt= cs_text(p);
sh= makecstring(txt);
s= sh;
if(is_active_cs(txt)){
s= s+3;
while(*s){
ret[k++]= *s++;
}
ret[k]= 0;
}else{
ret[k++]= '\\';
while(*s){
ret[k++]= *s++;
}
ret[k]= 0;
}
free(sh);
}
return(char*)ret;
}

/*:22*//*23:*/
#line 692 "./luatexdir/tex/textoken.w"

static char*cmd_chr_to_string(int cmd,int chr)
{
char*s;
str_number str;
int sel= selector;
selector= new_string;
print_cmd_chr((quarterword)cmd,chr);
str= make_string();
s= makecstring(str);
selector= sel;
flush_str(str);
return s;
}

/*:23*//*24:*/
#line 732 "./luatexdir/tex/textoken.w"

halfword par_loc;
halfword par_token;

/*:24*//*25:*/
#line 743 "./luatexdir/tex/textoken.w"

boolean force_eof;
int luacstrings;

/*:25*//*26:*/
#line 753 "./luatexdir/tex/textoken.w"

void firm_up_the_line(void)
{
int k;
ilimit= last;
if(pausing_par> 0){
if(interaction> nonstop_mode){
wake_up_terminal();
print_ln();
if(istart<ilimit){
for(k= istart;k<=ilimit-1;k++)
print_char(buffer[k]);
}
first= ilimit;
prompt_input("=>");
if(last> first){
for(k= first;k<+last-1;k++)
buffer[k+istart-first]= buffer[k];
ilimit= istart+last-first;
}
}
}
}

/*:26*//*27:*/
#line 782 "./luatexdir/tex/textoken.w"

void check_outer_validity(void)
{
halfword p;
halfword q;
if(suppress_outer_error_par)
return;
if(scanner_status!=normal){
deletions_allowed= false;



if(cur_cs!=0){
if((istate==token_list)||(iname<1)||(iname> 17)){
p= get_avail();
token_info(p)= cs_token_flag+cur_cs;
begin_token_list(p,backed_up);
}
cur_cmd= spacer_cmd;
cur_chr= ' ';
}
if(scanner_status> skipping){
const char*errhlp[]= {
"I suspect you have forgotten a `}', causing me",
"to read past where you wanted me to stop.",
"I'll try to recover; but if the error is serious,",
"you'd better type `E' or `X' now and fix your file.",
NULL
};
char errmsg[256];
const char*startmsg;
const char*scannermsg;

runaway();
if(cur_cs==0){
startmsg= "File ended";
}else{
cur_cs= 0;
startmsg= "Forbidden control sequence found";
}








p= get_avail();
switch(scanner_status){
case defining:
scannermsg= "definition";
token_info(p)= right_brace_token+'}';
break;
case matching:
scannermsg= "use";
token_info(p)= par_token;
long_state= outer_call_cmd;
break;
case aligning:
scannermsg= "preamble";
token_info(p)= right_brace_token+'}';
q= p;
p= get_avail();
token_link(p)= q;
token_info(p)= cs_token_flag+frozen_cr;
align_state= -1000000;
break;
case absorbing:
scannermsg= "text";
token_info(p)= right_brace_token+'}';
break;
default:
scannermsg= "unknown";
break;
}
begin_token_list(p,inserted);
snprintf(errmsg,255,"%s while scanning %s of %s",
startmsg,scannermsg,cs_to_string(warning_index));
tex_error(errmsg,errhlp);
}else{
char errmsg[256];
const char*errhlp_no[]= {
"The file ended while I was skipping conditional text.",
"This kind of error happens when you say `\\if...' and forget",
"the matching `\\fi'. I've inserted a `\\fi'; this might work.",
NULL
};
const char*errhlp_cs[]= {
"A forbidden control sequence occurred in skipped text.",
"This kind of error happens when you say `\\if...' and forget",
"the matching `\\fi'. I've inserted a `\\fi'; this might work.",
NULL
};
const char**errhlp= (const char**)errhlp_no;
char*ss;
if(cur_cs!=0){
errhlp= errhlp_cs;
cur_cs= 0;
}
ss= cmd_chr_to_string(if_test_cmd,cur_if);
snprintf(errmsg,255,"Incomplete %s; all text was ignored after line %d",
ss,(int)skip_line);
free(ss);

cur_tok= cs_token_flag+frozen_fi;

{
OK_to_interrupt= false;
back_input();
token_type= inserted;
OK_to_interrupt= true;
tex_error(errmsg,errhlp);
}
}
deletions_allowed= true;
}
}

/*:27*//*28:*/
#line 901 "./luatexdir/tex/textoken.w"


#if 0






static boolean get_next_file(void)
{
SWITCH:
if(iloc<=ilimit){

do_buffer_to_unichar(cur_chr,iloc);

RESWITCH:
if(detokenized_line()){
cur_cmd= (cur_chr==' '?10:12);
}else{
do_get_cat_code(cur_cmd,cur_chr);
}



































switch(istate+cur_cmd){
case mid_line+ignore_cmd:
case skip_blanks+ignore_cmd:
case new_line+ignore_cmd:
case skip_blanks+spacer_cmd:
case new_line+spacer_cmd:

goto SWITCH;
break;
case mid_line+escape_cmd:
case new_line+escape_cmd:
case skip_blanks+escape_cmd:

istate= (unsigned char)scan_control_sequence();
if(!suppress_outer_error_par&&cur_cmd>=outer_call_cmd)
check_outer_validity();
break;
case mid_line+active_char_cmd:
case new_line+active_char_cmd:
case skip_blanks+active_char_cmd:

cur_cs= active_to_cs(cur_chr,false);
cur_cmd= eq_type(cur_cs);
cur_chr= equiv(cur_cs);
istate= mid_line;
if(!suppress_outer_error_par&&cur_cmd>=outer_call_cmd)
check_outer_validity();
break;
case mid_line+sup_mark_cmd:
case new_line+sup_mark_cmd:
case skip_blanks+sup_mark_cmd:

if(process_sup_mark())
goto RESWITCH;
else
istate= mid_line;
break;
case mid_line+invalid_char_cmd:
case new_line+invalid_char_cmd:
case skip_blanks+invalid_char_cmd:

invalid_character_error();
return false;
break;
case mid_line+spacer_cmd:

istate= skip_blanks;
cur_chr= ' ';
break;
case mid_line+car_ret_cmd:







iloc= ilimit+1;
cur_cmd= spacer_cmd;
cur_chr= ' ';
break;
case skip_blanks+car_ret_cmd:
case mid_line+comment_cmd:
case new_line+comment_cmd:
case skip_blanks+comment_cmd:

iloc= ilimit+1;
goto SWITCH;
break;
case new_line+car_ret_cmd:

iloc= ilimit+1;
cur_cs= par_loc;
cur_cmd= eq_type(cur_cs);
cur_chr= equiv(cur_cs);
if(!suppress_outer_error_par&&cur_cmd>=outer_call_cmd)
check_outer_validity();
break;
case skip_blanks+left_brace_cmd:
case new_line+left_brace_cmd:
istate= mid_line;

case mid_line+left_brace_cmd:
align_state++;
break;
case skip_blanks+right_brace_cmd:
case new_line+right_brace_cmd:
istate= mid_line;

case mid_line+right_brace_cmd:
align_state--;
break;
case mid_line+math_shift_cmd:
case mid_line+tab_mark_cmd:
case mid_line+mac_param_cmd:
case mid_line+sub_mark_cmd:
case mid_line+letter_cmd:
case mid_line+other_char_cmd:
break;














default:
istate= mid_line;
break;
}
}else{
if(iname!=21)
istate= new_line;





do{
next_line_retval r= next_line();
if(r==next_line_return){
return true;
}else if(r==next_line_restart){
return false;
}
}while(0);
check_interrupt();
goto SWITCH;
}
return true;
}

#else










static boolean get_next_file(void)
{
int c= 0;
SWITCH:
if(iloc<=ilimit){

do_buffer_to_unichar(cur_chr,iloc);
RESWITCH:
if(detokenized_line()){
cur_cmd= (cur_chr==' '?10:12);
}else{
do_get_cat_code(cur_cmd,cur_chr);
}





c= istate+cur_cmd;
if(c==(mid_line+letter_cmd)||c==(mid_line+other_char_cmd)){
return true;
}else if(c>=new_line){
switch(c-new_line){
case escape_cmd:
istate= (unsigned char)scan_control_sequence();
if(!suppress_outer_error_par&&cur_cmd>=outer_call_cmd)
check_outer_validity();
return true;
case left_brace_cmd:
istate= mid_line;
align_state++;
return true;
case right_brace_cmd:
istate= mid_line;
align_state--;
return true;
case math_shift_cmd:
istate= mid_line;
return true;
case tab_mark_cmd:
istate= mid_line;
return true;
case car_ret_cmd:

iloc= ilimit+1;
cur_cs= par_loc;
cur_cmd= eq_type(cur_cs);
cur_chr= equiv(cur_cs);
if(!suppress_outer_error_par&&cur_cmd>=outer_call_cmd)
check_outer_validity();
return true;
case mac_param_cmd:
istate= mid_line;
return true;
case sup_mark_cmd:
if(process_sup_mark())
goto RESWITCH;
else
istate= mid_line;
return true;
case sub_mark_cmd:
istate= mid_line;
return true;
case ignore_cmd:
goto SWITCH;
return true;
case spacer_cmd:

goto SWITCH;
case letter_cmd:
istate= mid_line;
return true;
case other_char_cmd:
istate= mid_line;
return true;
case active_char_cmd:
cur_cs= active_to_cs(cur_chr,false);
cur_cmd= eq_type(cur_cs);
cur_chr= equiv(cur_cs);
istate= mid_line;
if(!suppress_outer_error_par&&cur_cmd>=outer_call_cmd)
check_outer_validity();
return true;
case comment_cmd:
iloc= ilimit+1;
goto SWITCH;
case invalid_char_cmd:
invalid_character_error();
return false;
default:
istate= mid_line;
return true;
}
}else if(c>=skip_blanks){
switch(c-skip_blanks){
case escape_cmd:

istate= (unsigned char)scan_control_sequence();
if(!suppress_outer_error_par&&cur_cmd>=outer_call_cmd)
check_outer_validity();
return true;
case left_brace_cmd:
istate= mid_line;
align_state++;
return true;
case right_brace_cmd:
istate= mid_line;
align_state--;
return true;
case math_shift_cmd:
istate= mid_line;
return true;
case tab_mark_cmd:
istate= mid_line;
return true;
case car_ret_cmd:
iloc= ilimit+1;
goto SWITCH;
case mac_param_cmd:
istate= mid_line;
return true;
case sup_mark_cmd:

if(process_sup_mark())
goto RESWITCH;
else
istate= mid_line;
return true;
case sub_mark_cmd:
istate= mid_line;
return true;
case ignore_cmd:
goto SWITCH;
case spacer_cmd:
goto SWITCH;
case letter_cmd:
istate= mid_line;
return true;
case other_char_cmd:
istate= mid_line;
return true;
case active_char_cmd:
cur_cs= active_to_cs(cur_chr,false);
cur_cmd= eq_type(cur_cs);
cur_chr= equiv(cur_cs);
istate= mid_line;
if(!suppress_outer_error_par&&cur_cmd>=outer_call_cmd)
check_outer_validity();
return true;
case comment_cmd:

iloc= ilimit+1;
goto SWITCH;
case invalid_char_cmd:

invalid_character_error();
return false;
default:
istate= mid_line;
return true;
}
}else if(c>=mid_line){
switch(c-mid_line){
case escape_cmd:
istate= (unsigned char)scan_control_sequence();
if(!suppress_outer_error_par&&cur_cmd>=outer_call_cmd)
check_outer_validity();
return true;
case left_brace_cmd:
align_state++;
return true;
case right_brace_cmd:
align_state--;
return true;
case math_shift_cmd:
return true;
case tab_mark_cmd:
return true;
case car_ret_cmd:







iloc= ilimit+1;
cur_cmd= spacer_cmd;
cur_chr= ' ';
return true;
case mac_param_cmd:
return true;
case sup_mark_cmd:
if(process_sup_mark())
goto RESWITCH;
else
istate= mid_line;
return true;
case sub_mark_cmd:
return true;
case ignore_cmd:
goto SWITCH;
case spacer_cmd:

istate= skip_blanks;
cur_chr= ' ';
return true;
case letter_cmd:
istate= mid_line;
return true;
case other_char_cmd:
istate= mid_line;
return true;
case active_char_cmd:
cur_cs= active_to_cs(cur_chr,false);
cur_cmd= eq_type(cur_cs);
cur_chr= equiv(cur_cs);
istate= mid_line;
if(!suppress_outer_error_par&&cur_cmd>=outer_call_cmd)
check_outer_validity();
return true;
case comment_cmd:
iloc= ilimit+1;
goto SWITCH;
case invalid_char_cmd:
invalid_character_error();
return false;
default:
istate= mid_line;
return true;
}
}else{
istate= mid_line;
return true;
}
}else{
if(iname!=21){
istate= new_line;
}




do{
next_line_retval r= next_line();
if(r==next_line_return){
return true;
}else if(r==next_line_restart){
return false;
}
}while(0);
check_interrupt();
goto SWITCH;
}
return true;
}

#endif

/*:28*//*29:*/
#line 1374 "./luatexdir/tex/textoken.w"


#define is_hex(a) ((a>='0'&&a<='9')||(a>='a'&&a<='f'))

#define add_nybble(c) \
    if (c<='9') { \
        cur_chr= (cur_chr<<4)+c-'0'; \
    } else { \
        cur_chr= (cur_chr<<4)+c-'a'+10; \
    }

#define set_nybble(c) \
    if (c<='9') { \
        cur_chr= c-'0'; \
    } else { \
        cur_chr= c-'a'+10; \
    }

#define one_hex_to_cur_chr(c1) \
    set_nybble(c1);

#define two_hex_to_cur_chr(c1,c2) \
    set_nybble(c1); \
    add_nybble(c2);

#define four_hex_to_cur_chr(c1,c2,c3,c4) \
    two_hex_to_cur_chr(c1,c2); \
    add_nybble(c3); \
    add_nybble(c4);

#define six_hex_to_cur_chr(c1,c2,c3,c4,c5,c6) \
    four_hex_to_cur_chr(c1,c2,c3,c4); \
    add_nybble(c5); \
    add_nybble(c6);

static boolean process_sup_mark(void)
{
if(cur_chr==buffer[iloc]){
if(iloc<ilimit){
if((cur_chr==buffer[iloc+1])&&(cur_chr==buffer[iloc+2])){
if((cur_chr==buffer[iloc+3])&&(cur_chr==buffer[iloc+4])){

if((iloc+10)<=ilimit){
int c1= buffer[iloc+5];
int c2= buffer[iloc+6];
int c3= buffer[iloc+7];
int c4= buffer[iloc+8];
int c5= buffer[iloc+9];
int c6= buffer[iloc+10];
if(is_hex(c1)&&is_hex(c2)&&is_hex(c3)&&
is_hex(c4)&&is_hex(c5)&&is_hex(c6)){
iloc= iloc+11;
six_hex_to_cur_chr(c1,c2,c3,c4,c5,c6);
return true;
}else{
tex_error("^^^^^^ needs six hex digits",NULL);
}
}else{
tex_error("^^^^^^ needs six hex digits, end of input",NULL);
}
}else{

if((iloc+6)<=ilimit){
int c1= buffer[iloc+3];
int c2= buffer[iloc+4];
int c3= buffer[iloc+5];
int c4= buffer[iloc+6];
if(is_hex(c1)&&is_hex(c2)&&is_hex(c3)&&is_hex(c4)){
iloc= iloc+7;
four_hex_to_cur_chr(c1,c2,c3,c4);
return true;
}else{
tex_error("^^^^ needs four hex digits",NULL);
}
}else{
tex_error("^^^^ needs four hex digits, end of input",NULL);
}
}
}else{

if((iloc+2)<=ilimit){
int c1= buffer[iloc+1];
int c2= buffer[iloc+2];
if(is_hex(c1)&&is_hex(c2)){
iloc= iloc+3;
two_hex_to_cur_chr(c1,c2);
return true;
}
}

}
}

{
int c1= buffer[iloc+1];
if(c1<0200){
iloc= iloc+2;
if(is_hex(c1)&&(iloc<=ilimit)){
int c2= buffer[iloc];
if(is_hex(c2)){
incr(iloc);
two_hex_to_cur_chr(c1,c2);
return true;
}
}
cur_chr= (c1<0100?c1+0100:c1-0100);
return true;
}
}
}
return false;
}

/*:29*//*30:*/
#line 1501 "./luatexdir/tex/textoken.w"

static boolean check_expanded_code(int*kk);

static int scan_control_sequence(void)
{
int retval= mid_line;
if(iloc> ilimit){
cur_cs= null_cs;
}else{
register int cat;
while(1){
int k= iloc;
do_buffer_to_unichar(cur_chr,k);
do_get_cat_code(cat,cur_chr);
if(cat!=letter_cmd||k> ilimit){
retval= (cat==spacer_cmd?skip_blanks:mid_line);
if(cat==sup_mark_cmd&&check_expanded_code(&k))
continue;
}else{
retval= skip_blanks;
do{
do_buffer_to_unichar(cur_chr,k);
do_get_cat_code(cat,cur_chr);
}while(cat==letter_cmd&&k<=ilimit);

if(cat==sup_mark_cmd&&check_expanded_code(&k))
continue;
if(cat!=letter_cmd){










if(cur_chr<=0x7F){
k-= 1;
}else if(cur_chr> 0xFFFF){
k-= 4;
}else if(cur_chr> 0x7FF){
k-= 3;
}else{
k-= 2;
}

}
}
cur_cs= id_lookup(iloc,k-iloc);
iloc= k;
break;
}
}
cur_cmd= eq_type(cur_cs);
cur_chr= equiv(cur_cs);
return retval;
}

/*:30*//*31:*/
#line 1568 "./luatexdir/tex/textoken.w"

static boolean check_expanded_code(int*kk)
{
int l;
int k= *kk;
int d= 1;
if(buffer[k]==cur_chr&&k<ilimit){
if((cur_chr==buffer[k+1])&&(cur_chr==buffer[k+2])){
if((cur_chr==buffer[k+3])&&(cur_chr==buffer[k+4])){
if((k+10)<=ilimit){
int c1= buffer[k+6-1];
int c2= buffer[k+6];
int c3= buffer[k+6+1];
int c4= buffer[k+6+2];
int c5= buffer[k+6+3];
int c6= buffer[k+6+4];
if(is_hex(c1)&&is_hex(c2)&&is_hex(c3)&&is_hex(c4)&&is_hex(c5)&&is_hex(c6)){
d= 6;
six_hex_to_cur_chr(c1,c2,c3,c4,c5,c6);
}else{
tex_error("^^^^^^ needs six hex digits",NULL);
}
}else{
tex_error("^^^^^^ needs six hex digits, end of input",NULL);
}
}else{
if((k+6)<=ilimit){
int c1= buffer[k+4-1];
int c2= buffer[k+4];
int c3= buffer[k+4+1];
int c4= buffer[k+4+2];
if(is_hex(c1)&&is_hex(c2)&&is_hex(c3)&&is_hex(c4)){
d= 4;
four_hex_to_cur_chr(c1,c2,c3,c4);
}else{
tex_error("^^^^ needs four hex digits",NULL);
}
}else{
tex_error("^^^^ needs four hex digits, end of input",NULL);
}
}
}else{
int c1= buffer[k+1];
if(c1<0200){
d= 1;
if(is_hex(c1)&&(k+2)<=ilimit){
int c2= buffer[k+2];
if(is_hex(c2)){
d= 2;
two_hex_to_cur_chr(c1,c2);
}else{
cur_chr= (c1<0100?c1+0100:c1-0100);
}
}else{
cur_chr= (c1<0100?c1+0100:c1-0100);
}
}
}
if(d> 2)
d= 2*d-1;
else
d++;
if(cur_chr<=0x7F){
buffer[k-1]= (packed_ASCII_code)cur_chr;
}else if(cur_chr<=0x7FF){
buffer[k-1]= (packed_ASCII_code)(0xC0+cur_chr/0x40);
k++;
d--;
buffer[k-1]= (packed_ASCII_code)(0x80+cur_chr%0x40);
}else if(cur_chr<=0xFFFF){
buffer[k-1]= (packed_ASCII_code)(0xE0+cur_chr/0x1000);
k++;
d--;
buffer[k-1]= (packed_ASCII_code)(0x80+(cur_chr%0x1000)/0x40);
k++;
d--;
buffer[k-1]= (packed_ASCII_code)(0x80+(cur_chr%0x1000)%0x40);
}else{
buffer[k-1]= (packed_ASCII_code)(0xF0+cur_chr/0x40000);
k++;
d--;
buffer[k-1]= (packed_ASCII_code)(0x80+(cur_chr%0x40000)/0x1000);
k++;
d--;
buffer[k-1]= (packed_ASCII_code)(0x80+((cur_chr%0x40000)%0x1000)/0x40);
k++;
d--;
buffer[k-1]= (packed_ASCII_code)(0x80+((cur_chr%0x40000)%0x1000)%0x40);
}
l= k;
ilimit= ilimit-d;
while(l<=ilimit){
buffer[l]= buffer[l+d];
l++;
}
*kk= k;
return true;
}
return false;
}

/*:31*//*32:*/
#line 1672 "./luatexdir/tex/textoken.w"
static next_line_retval next_line(void)
{
boolean inhibit_eol= false;
if(iname> 17){

incr(line);
first= istart;
if(!force_eof){
if(iname<=20){
if(pseudo_input()){
firm_up_the_line();
line_catcode_table= DEFAULT_CAT_TABLE;
if((iname==19)&&(pseudo_lines(pseudo_files)==null))
inhibit_eol= true;
}else if((every_eof_par!=null)&&!eof_seen[iindex]){
ilimit= first-1;
eof_seen[iindex]= true;
if(iname!=19)
begin_token_list(every_eof_par,every_eof_text);
return next_line_restart;
}else{
force_eof= true;
}
}else{
if(iname==21){
if(luacstring_input()){
firm_up_the_line();
line_catcode_table= (short)luacstring_cattable();
line_partial= (signed char)luacstring_partial();
if(luacstring_final_line()||line_partial
||line_catcode_table==NO_CAT_TABLE)
inhibit_eol= true;
if(!line_partial)
istate= new_line;
}else{
force_eof= true;
}
}else{
if(lua_input_ln(cur_file,0,true)){
firm_up_the_line();
line_catcode_table= DEFAULT_CAT_TABLE;
}else if((every_eof_par!=null)&&(!eof_seen[iindex])){
ilimit= first-1;
eof_seen[iindex]= true;
begin_token_list(every_eof_par,every_eof_text);
return next_line_restart;
}else{
force_eof= true;
}
}
}
}
if(force_eof){
if(tracing_nesting_par> 0)
if((grp_stack[in_open]!=cur_boundary)||(if_stack[in_open]!=cond_ptr))
if(!((iname==19)||(iname==21))){

file_warning();
}
if((iname> 21)||(iname==20)){
report_stop_file(filetype_tex);
decr(open_parens);
}
force_eof= false;

if(iname==21||iname==19){
end_file_reading();
}else{
end_file_reading();
if(!suppress_outer_error_par)
check_outer_validity();
}
return next_line_restart;
}
if(inhibit_eol||end_line_char_inactive)
ilimit--;
else
buffer[ilimit]= (packed_ASCII_code)end_line_char_par;
first= ilimit+1;
iloc= istart;
}else{
if(!terminal_input){

cur_cmd= 0;
cur_chr= 0;
return next_line_return;
}
if(input_ptr> 0){

end_file_reading();
return next_line_restart;
}
if(selector<log_only)
open_log_file();
if(interaction> nonstop_mode){
if(end_line_char_inactive)
ilimit++;
if(ilimit==istart){

tprint_nl("(Please type a command or say `\\end')");
}
print_ln();
first= istart;
prompt_input("*");
ilimit= last;
if(end_line_char_inactive)
ilimit--;
else
buffer[ilimit]= (packed_ASCII_code)end_line_char_par;
first= ilimit+1;
iloc= istart;
}else{




fatal_error("*** (job aborted, no legal \\end found)");
}
}
return next_line_ok;
}

/*:32*//*33:*/
#line 1796 "./luatexdir/tex/textoken.w"

static boolean get_next_tokenlist(void)
{
register halfword t= token_info(iloc);
iloc= token_link(iloc);
if(t>=cs_token_flag){

cur_cs= t-cs_token_flag;
cur_cmd= eq_type(cur_cs);
if(cur_cmd>=outer_call_cmd){
if(cur_cmd==dont_expand_cmd){






cur_cs= token_info(iloc)-cs_token_flag;
iloc= null;
cur_cmd= eq_type(cur_cs);
if(cur_cmd> max_command_cmd){
cur_cmd= relax_cmd;
cur_chr= no_expand_flag;
return true;
}
}else if(!suppress_outer_error_par){
check_outer_validity();
}
}
cur_chr= equiv(cur_cs);
}else{
cur_cmd= token_cmd(t);
cur_chr= token_chr(t);
switch(cur_cmd){
case left_brace_cmd:
align_state++;
break;
case right_brace_cmd:
align_state--;
break;
case out_param_cmd:

begin_token_list(param_stack[param_start+cur_chr-1],parameter);
return false;
break;
}
}
return true;
}

/*:33*//*35:*/
#line 1852 "./luatexdir/tex/textoken.w"

void get_next(void)
{
RESTART:
cur_cs= 0;
if(istate!=token_list){

if(!get_next_file())
goto RESTART;
}else{
if(iloc==null){
end_token_list();
goto RESTART;
}else if(!get_next_tokenlist()){
goto RESTART;
}
}

if((cur_cmd==tab_mark_cmd||cur_cmd==car_ret_cmd)&&align_state==0){
insert_vj_template();
goto RESTART;
}
}

/*:35*//*37:*/
#line 1900 "./luatexdir/tex/textoken.w"

void get_token(void)
{
no_new_control_sequence= false;
get_next();
no_new_control_sequence= true;
if(cur_cs==0)
cur_tok= token_val(cur_cmd,cur_chr);
else
cur_tok= cs_token_flag+cur_cs;
}

/*:37*//*38:*/
#line 1914 "./luatexdir/tex/textoken.w"

halfword string_to_toks(const char*ss)
{
halfword p;
halfword q;
halfword t;
const char*s= ss;
const char*se= ss+strlen(s);
p= temp_token_head;
set_token_link(p,null);
while(s<se){
t= (halfword)str2uni((const unsigned char*)s);
s+= utf8_size(t);
if(t==' ')
t= space_token;
else
t= other_token+t;
fast_store_new_token(t);
}
return token_link(temp_token_head);
}

/*:38*//*40:*/
#line 1952 "./luatexdir/tex/textoken.w"

halfword lua_str_toks(lstring b)
{
halfword p;
halfword q;
halfword t;
unsigned char*k;
p= temp_token_head;
set_token_link(p,null);
k= (unsigned char*)b.s;
while(k<(unsigned char*)b.s+b.l){
t= pool_to_unichar(k);
k+= utf8_size(t);
if(t==' '){
t= space_token;
}else{
if((t=='\\')||(t=='"')||(t=='\'')||(t==10)||(t==13))
fast_store_new_token(other_token+'\\');
if(t==10)
t= 'n';
if(t==13)
t= 'r';
t= other_token+t;
}
fast_store_new_token(t);
}
return p;
}

/*:40*//*42:*/
#line 1986 "./luatexdir/tex/textoken.w"

halfword str_toks(lstring s)
{
halfword p;
halfword q;
halfword t;
unsigned char*k,*l;
p= temp_token_head;
set_token_link(p,null);
k= s.s;
l= k+s.l;
while(k<l){
t= pool_to_unichar(k);
k+= utf8_size(t);
if(t==' ')
t= space_token;
else
t= other_token+t;
fast_store_new_token(t);
}
return p;
}







halfword str_scan_toks(int ct,lstring s)
{
halfword p;
halfword q;
halfword t;
unsigned char*k,*l;
int cc;
p= temp_token_head;
set_token_link(p,null);
k= s.s;
l= k+s.l;
while(k<l){
t= pool_to_unichar(k);
k+= utf8_size(t);
cc= get_cat_code(ct,t);
if(cc==0){

int _lname= 0;
int _s= 0;
int _c= 0;
halfword _cs= null;
unsigned char*_name= k;
while(k<l){
t= (halfword)str2uni((const unsigned char*)k);
_s= utf8_size(t);
_c= get_cat_code(ct,t);
if(_c==11){
k+= _s;
_lname= _lname+_s;
}else if(_c==10){

k+= _s;
break;
}else{
break;
}
}
if(_s> 0){

_cs= string_lookup((const char*)_name,_lname);
if(_cs==undefined_control_sequence){

t= cc*(1<<21)+t;
k= _name;
}else{
t= cs_token_flag+_cs;
}
}else{


t= cc*(1<<21)+t;
k= _name;
}

}else{


t= cc*(1<<21)+t;
}
fast_store_new_token(t);

}
return p;
}

/*:42*//*43:*/
#line 2082 "./luatexdir/tex/textoken.w"

void ins_the_toks(void)
{
(void)the_toks();
ins_list(token_link(temp_token_head));
}

#define set_toks_register(n,t,g) { \
    int a =  (g> 0) ? 4 : 0; \
    halfword ref =  get_avail();  \
    set_token_ref_count(ref, 0); \
    set_token_link(ref, token_link(t)); \
    define(n + toks_base, call_cmd, ref); \
}

void combine_the_toks(int how)
{
halfword nt;
get_x_token();

if(cur_cmd==assign_toks_cmd){
nt= equiv(cur_cs)-toks_base;

}else{
back_input();
scan_int();
nt= cur_val;
}

do{
get_x_token();
}while(cur_cmd==spacer_cmd);
if(cur_cmd==left_brace_cmd){
halfword x,source;
back_input();
x= scan_toks(false,how> 1);
source= def_ref;

if(source!=null){
halfword target= toks(nt);
if(target==null){
set_toks_register(nt,source,0);
}else{
halfword s= token_link(source);
if(s!=null){
halfword t= token_link(target);
if(t==null){

set_token_link(target,s);
}else if(odd(how)){

if(cur_level!=eq_level_field(eqtb[toks_base+nt])){
halfword p= temp_token_head;
halfword q;
set_token_link(p,s);
p= x;
while(t!=null){
fast_store_new_token(token_info(t));
t= token_link(t);
}
set_toks_register(nt,temp_token_head,0);
}else{
set_token_link(x,t);
set_token_link(target,s);
}
}else{

if(cur_level!=eq_level_field(eqtb[toks_base+nt])){
halfword p= temp_token_head;
halfword q;
set_token_link(p,null);
while(t!=null){
fast_store_new_token(token_info(t));
t= token_link(t);
}
set_token_link(p,s);
set_toks_register(nt,temp_token_head,0);
}else{
while(token_link(t)!=null){
t= token_link(t);
}
set_token_link(t,s);
}
}
}
}
}
}else{
halfword source,ns;
if(cur_cmd==assign_toks_cmd){
ns= equiv(cur_cs)-toks_base;

}else{
back_input();
scan_int();
ns= cur_val;
}

source= toks(ns);
if(source!=null){
halfword target= toks(nt);
if(target==null){
equiv(toks_base+nt)= source;
equiv(toks_base+ns)= null;
}else{
halfword s= token_link(source);
if(s!=null){
halfword t= token_link(target);
if(t==null){
set_token_link(target,s);
}else if(odd(how)){

halfword x= s;
while(token_link(x)!=null){
x= token_link(x);
}
set_token_link(x,t);
set_token_link(target,s);
}else{

while(token_link(t)!=null){
t= token_link(t);
}
set_token_link(t,s);
}
equiv(toks_base+ns)= null;
}
}
}
}
}

/*:43*//*44:*/
#line 2217 "./luatexdir/tex/textoken.w"

static void print_job_name(void)
{
if(job_name){
char*s,*ss;
int callback_id,lua_retval;
s= (char*)str_string(job_name);
callback_id= callback_defined(process_jobname_callback);
if(callback_id> 0){
lua_retval= run_callback(callback_id,"S->S",s,&ss);
if((lua_retval==true)&&(ss!=NULL))
s= ss;
}
tprint(s);
}else{
print(job_name);
}
}

/*:44*//*46:*/
#line 2244 "./luatexdir/tex/textoken.w"


int scan_lua_state(void)
{
int sn= 0;
do{
get_x_token();
}while((cur_cmd==spacer_cmd)||(cur_cmd==relax_cmd));
back_input();
if(cur_cmd!=left_brace_cmd){
if(scan_keyword("name")){
(void)scan_toks(false,true);
sn= def_ref;
}else{
scan_register_num();
if(get_lua_name(cur_val))
sn= (cur_val-65536);
}
}
return sn;
}

/*:46*//*47:*/
#line 2274 "./luatexdir/tex/textoken.w"

#define push_selector { \
    old_setting =  selector; \
    selector =  new_string; \
}

#define pop_selector { \
    selector =  old_setting; \
}

static int do_variable_dvi(halfword c)
{
return 0;
}

#define do_variable_backend_int(i) \
    cur_cmd =  assign_int_cmd; \
    cur_val =  backend_int_base + i; \
    cur_tok =  token_val(cur_cmd, cur_val); \
    back_input();

#define do_variable_backend_dimen(i) \
    cur_cmd =  assign_dimen_cmd; \
    cur_val =  backend_dimen_base + i; \
    cur_tok =  token_val(cur_cmd, cur_val); \
    back_input();

#define do_variable_backend_toks(i) \
    cur_cmd =  assign_toks_cmd; \
    cur_val =  backend_toks_base + i ; \
    cur_tok =  token_val(cur_cmd, cur_val); \
    back_input();

static int do_variable_pdf(halfword c)
{
if(scan_keyword("compresslevel")){do_variable_backend_int(c_pdf_compress_level);}
else if(scan_keyword("decimaldigits")){do_variable_backend_int(c_pdf_decimal_digits);}
else if(scan_keyword("imageresolution")){do_variable_backend_int(c_pdf_image_resolution);}
else if(scan_keyword("pkresolution")){do_variable_backend_int(c_pdf_pk_resolution);}
else if(scan_keyword("uniqueresname")){do_variable_backend_int(c_pdf_unique_resname);}
else if(scan_keyword("minorversion")){do_variable_backend_int(c_pdf_minor_version);}
else if(scan_keyword("pagebox")){do_variable_backend_int(c_pdf_pagebox);}
else if(scan_keyword("inclusionerrorlevel")){do_variable_backend_int(c_pdf_inclusion_errorlevel);}
else if(scan_keyword("ignoreunknownimages")){do_variable_backend_int(c_pdf_ignore_unknown_images);}
else if(scan_keyword("gamma")){do_variable_backend_int(c_pdf_gamma);}
else if(scan_keyword("imageapplygamma")){do_variable_backend_int(c_pdf_image_apply_gamma);}
else if(scan_keyword("imagegamma")){do_variable_backend_int(c_pdf_image_gamma);}
else if(scan_keyword("imagehicolor")){do_variable_backend_int(c_pdf_image_hicolor);}
else if(scan_keyword("imageaddfilename")){do_variable_backend_int(c_pdf_image_addfilename);}
else if(scan_keyword("objcompresslevel")){do_variable_backend_int(c_pdf_obj_compress_level);}
else if(scan_keyword("inclusioncopyfonts")){do_variable_backend_int(c_pdf_inclusion_copy_font);}
else if(scan_keyword("gentounicode")){do_variable_backend_int(c_pdf_gen_tounicode);}
else if(scan_keyword("pkfixeddpi")){do_variable_backend_int(c_pdf_pk_fixed_dpi);}
else if(scan_keyword("suppressoptionalinfo")){do_variable_backend_int(c_pdf_suppress_optional_info);}

else if(scan_keyword("horigin")){do_variable_backend_dimen(d_pdf_h_origin);}
else if(scan_keyword("vorigin")){do_variable_backend_dimen(d_pdf_v_origin);}
else if(scan_keyword("threadmargin")){do_variable_backend_dimen(d_pdf_thread_margin);}
else if(scan_keyword("destmargin")){do_variable_backend_dimen(d_pdf_dest_margin);}
else if(scan_keyword("linkmargin")){do_variable_backend_dimen(d_pdf_link_margin);}
else if(scan_keyword("xformmargin")){do_variable_backend_dimen(d_pdf_xform_margin);}

else if(scan_keyword("pageattr")){do_variable_backend_toks(t_pdf_page_attr);}
else if(scan_keyword("pageresources")){do_variable_backend_toks(t_pdf_page_resources);}
else if(scan_keyword("pagesattr")){do_variable_backend_toks(t_pdf_pages_attr);}
else if(scan_keyword("xformattr")){do_variable_backend_toks(t_pdf_xform_attr);}
else if(scan_keyword("xformresources")){do_variable_backend_toks(t_pdf_xform_resources);}
else if(scan_keyword("pkmode")){do_variable_backend_toks(t_pdf_pk_mode);}
else if(scan_keyword("trailerid")){do_variable_backend_toks(t_pdf_trailer_id);}

else
return 0;
return 1;
}

static int do_feedback_dvi(halfword c)
{
return 0;
}



#define pdftex_version  140 
#define pdftex_revision "0" 

static int do_feedback_pdf(halfword c)
{
int old_setting;
int save_scanner_status;
halfword save_def_ref;
halfword save_warning_index;
boolean bool;
str_number s;
int ff;
str_number u= 0;
char*str;

if(scan_keyword("lastlink")){
push_selector;
print_int(pdf_last_link);
pop_selector;
}else if(scan_keyword("retval")){
push_selector;
print_int(pdf_retval);
pop_selector;
}else if(scan_keyword("lastobj")){
push_selector;
print_int(pdf_last_obj);
pop_selector;
}else if(scan_keyword("lastannot")){
push_selector;
print_int(pdf_last_annot);
pop_selector;
}else if(scan_keyword("xformname")){
scan_int();
check_obj_type(static_pdf,obj_type_xform,cur_val);
push_selector;
print_int(obj_info(static_pdf,cur_val));
pop_selector;
}else if(scan_keyword("creationdate")){
ins_list(string_to_toks(getcreationdate(static_pdf)));

return 2;
}else if(scan_keyword("fontname")){
scan_font_ident();
if(cur_val==null_font)
normal_error("pdf backend","invalid font identifier when asking 'fontname'");
pdf_check_vf(cur_val);
if(!font_used(cur_val))
pdf_init_font(static_pdf,cur_val);
push_selector;
set_ff(cur_val);
print_int(obj_info(static_pdf,pdf_font_num(ff)));
pop_selector;
}else if(scan_keyword("fontobjnum")){
scan_font_ident();
if(cur_val==null_font)
normal_error("pdf backend","invalid font identifier when asking 'objnum'");
pdf_check_vf(cur_val);
if(!font_used(cur_val))
pdf_init_font(static_pdf,cur_val);
push_selector;
set_ff(cur_val);
print_int(pdf_font_num(ff));
pop_selector;
}else if(scan_keyword("fontsize")){
scan_font_ident();
if(cur_val==null_font)
normal_error("pdf backend","invalid font identifier when asking 'fontsize'");
push_selector;
print_scaled(font_size(cur_val));
tprint("pt");
pop_selector;
}else if(scan_keyword("pageref")){
scan_int();
if(cur_val<=0)
normal_error("pdf backend","invalid page number when asking 'pageref'");
push_selector;
print_int(pdf_get_obj(static_pdf,obj_type_page,cur_val,false));
pop_selector;
}else if(scan_keyword("colorstackinit")){
bool= scan_keyword("page");
if(scan_keyword("direct"))
cur_val= direct_always;
else if(scan_keyword("page"))
cur_val= direct_page;
else
cur_val= set_origin;
save_scanner_status= scanner_status;
save_warning_index= warning_index;
save_def_ref= def_ref;
u= save_cur_string();
scan_toks(false,true);
s= tokens_to_string(def_ref);
delete_token_ref(def_ref);
def_ref= save_def_ref;
warning_index= save_warning_index;
scanner_status= save_scanner_status;
str= makecstring(s);
cur_val= newcolorstack(str,cur_val,bool);
free(str);
flush_str(s);
cur_val_level= int_val_level;
if(cur_val<0){
print_err("Too many color stacks");
help2("The number of color stacks is limited to 32768.",
"I'll use the default color stack 0 here.");
error();
cur_val= 0;
restore_cur_string(u);
}
push_selector;
print_int(cur_val);
pop_selector;
}else if(scan_keyword("version")){
push_selector;
print_int(pdftex_version);
pop_selector;
}else if(scan_keyword("revision")){
ins_list(string_to_toks(pdftex_revision));
return 2;
}else{
return 0;
}
return 1;
}

void conv_toks(void)
{
int old_setting;
halfword p,q;
int save_scanner_status;
halfword save_def_ref;
halfword save_warning_index;
boolean bool;
str_number s;
int sn;
str_number u= 0;
int c= cur_chr;
str_number str;
int i= 0;

switch(c){
case number_code:
scan_int();
push_selector;
print_int(cur_val);
pop_selector;
break;
case lua_function_code:
scan_int();
if(cur_val<=0){
normal_error("luafunction","invalid number");
}else{
u= save_cur_string();
luacstrings= 0;
luafunctioncall(cur_val);
restore_cur_string(u);
if(luacstrings> 0)
lua_string_start();
}

return;
break;
case lua_code:
u= save_cur_string();
save_scanner_status= scanner_status;
save_def_ref= def_ref;
save_warning_index= warning_index;
sn= scan_lua_state();
scan_toks(false,true);
s= def_ref;
warning_index= save_warning_index;
def_ref= save_def_ref;
scanner_status= save_scanner_status;
luacstrings= 0;
luatokencall(s,sn);
delete_token_ref(s);
restore_cur_string(u);
if(luacstrings> 0)
lua_string_start();

return;
break;
case expanded_code:
save_scanner_status= scanner_status;
save_warning_index= warning_index;
save_def_ref= def_ref;
u= save_cur_string();
scan_toks(false,true);
warning_index= save_warning_index;
scanner_status= save_scanner_status;
ins_list(token_link(def_ref));
def_ref= save_def_ref;
restore_cur_string(u);

return;
break;
case math_style_code:
push_selector;
print_math_style();
pop_selector;
break;
case string_code:
save_scanner_status= scanner_status;
scanner_status= normal;
get_token();
scanner_status= save_scanner_status;
push_selector;
if(cur_cs!=0)
sprint_cs(cur_cs);
else
print(cur_chr);
pop_selector;
break;
case cs_string_code:
save_scanner_status= scanner_status;
scanner_status= normal;
get_token();
scanner_status= save_scanner_status;
push_selector;
if(cur_cs!=0)
sprint_cs_name(cur_cs);
else
print(cur_chr);
pop_selector;
break;
case roman_numeral_code:
scan_int();
push_selector;
print_roman_int(cur_val);
pop_selector;
break;
case meaning_code:
save_scanner_status= scanner_status;
scanner_status= normal;
get_token();
scanner_status= save_scanner_status;
push_selector;
print_meaning();
pop_selector;
break;
case uchar_code:
scan_char_num();
push_selector;
print(cur_val);
pop_selector;
break;
case lua_escape_string_code:
{
lstring escstr;
int l= 0;
save_scanner_status= scanner_status;
save_def_ref= def_ref;
save_warning_index= warning_index;
scan_toks(false,true);
bool= in_lua_escape;
in_lua_escape= true;
escstr.s= (unsigned char*)tokenlist_to_cstring(def_ref,false,&l);
escstr.l= (unsigned)l;
in_lua_escape= bool;
delete_token_ref(def_ref);
def_ref= save_def_ref;
warning_index= save_warning_index;
scanner_status= save_scanner_status;
(void)lua_str_toks(escstr);
ins_list(token_link(temp_token_head));
free(escstr.s);
return;
}

break;
case font_id_code:
scan_font_ident();
push_selector;
print_int(cur_val);
pop_selector;
break;
case font_name_code:
scan_font_ident();
push_selector;
append_string((unsigned char*)font_name(cur_val),(unsigned)strlen(font_name(cur_val)));
if(font_size(cur_val)!=font_dsize(cur_val)){
tprint(" at ");
print_scaled(font_size(cur_val));
tprint("pt");
}
pop_selector;
break;
case left_margin_kern_code:
scan_int();
if((box(cur_val)==null)||(type(box(cur_val))!=hlist_node))
normal_error("marginkern","a non-empty hbox expected");
push_selector;
p= list_ptr(box(cur_val));
while((p!=null)&&(type(p)==glue_node)){
p= vlink(p);
}
if((p!=null)&&(type(p)==margin_kern_node)&&(subtype(p)==left_side))
print_scaled(width(p));
else
print_char('0');
tprint("pt");
pop_selector;
break;
case right_margin_kern_code:
scan_int();
if((box(cur_val)==null)||(type(box(cur_val))!=hlist_node))
normal_error("marginkern","a non-empty hbox expected");
push_selector;
p= list_ptr(box(cur_val));
if(p!=null){
p= tail_of_list(p);




while((p!=null)&&(type(p)==glue_node)){
p= alink(p);
}
if((p!=null)&&!((type(p)==margin_kern_node)&&(subtype(p)==right_side))){
if(type(p)==disc_node){
q= alink(p);
if((q!=null)&&((type(q)==margin_kern_node)&&(subtype(q)==right_side))){
p= q;
}else{





}
}
}
}
if((p!=null)&&(type(p)==margin_kern_node)&&(subtype(p)==right_side))
print_scaled(width(p));
else
print_char('0');
tprint("pt");
pop_selector;
break;
case uniform_deviate_code:
scan_int();
push_selector;
print_int(unif_rand(cur_val));
pop_selector;
break;
case normal_deviate_code:
scan_int();
push_selector;
print_int(norm_rand());
pop_selector;
break;
case math_char_class_code:
{
mathcodeval mval;
scan_int();
mval= get_math_code(cur_val);
push_selector;
print_int(mval.class_value);
pop_selector;
}
break;
case math_char_fam_code:
{
mathcodeval mval;
scan_int();
mval= get_math_code(cur_val);
push_selector;
print_int(mval.family_value);
pop_selector;
}
break;
case math_char_slot_code:
{
mathcodeval mval;
scan_int();
mval= get_math_code(cur_val);
push_selector;
print_int(mval.character_value);
pop_selector;
}
break;
case insert_ht_code:
scan_register_num();
push_selector;
i= cur_val;
p= page_ins_head;
while(i>=subtype(vlink(p)))
p= vlink(p);
if(subtype(p)==i)
print_scaled(height(p));
else
print_char('0');
tprint("pt");
pop_selector;
break;
case job_name_code:
if(job_name==0)
open_log_file();
push_selector;
print_job_name();
pop_selector;
break;
case format_name_code:
if(job_name==0)
open_log_file();
push_selector;
print(format_name);
pop_selector;
break;
case luatex_banner_code:
push_selector;
tprint(luatex_banner);
pop_selector;
break;
case luatex_revision_code:
push_selector;
print(get_luatexrevision());
pop_selector;
break;
case luatex_date_code:
push_selector;
print_int(get_luatex_date_info());
pop_selector;
break;
case etex_code:
push_selector;
tprint(eTeX_version_string);
pop_selector;
break;
case eTeX_revision_code:
push_selector;
tprint(eTeX_revision);
pop_selector;
break;
case font_identifier_code:
confusion("convert");
break;
default:
confusion("convert");
break;
}
str= make_string();
(void)str_toks(str_lstring(str));
flush_str(str);
ins_list(token_link(temp_token_head));
}

void do_feedback(void)
{
int c= cur_chr;
str_number str;
int done= 1;
switch(c){
case dvi_feedback_code:
if(get_o_mode()==OMODE_DVI){
done= do_feedback_dvi(c);
}else{
tex_error("unexpected use of \\dvifeedback",null);
return;
}
if(done==0){

normal_warning("dvi backend","unexpected use of \\dvifeedback");
return;
}else if(done==2){
return;
}
break;
case pdf_feedback_code:
if(get_o_mode()==OMODE_PDF){
done= do_feedback_pdf(c);
}else{
tex_error("unexpected use of \\pdffeedback",null);
return;
}
if(done==0){

normal_warning("pdf backend","unexpected use of \\pdffeedback");
return;
}else if(done==2){
return;
}
break;
default:
confusion("feedback");
break;
}
str= make_string();
(void)str_toks(str_lstring(str));
flush_str(str);
ins_list(token_link(temp_token_head));
}

void do_variable(void)
{
int c= cur_chr;
int done= 1;
switch(c){
case dvi_variable_code:
done= do_variable_dvi(c);
if(done==0){

normal_warning("dvi backend","unexpected use of \\dvivariable");
}
return;
break;
case pdf_variable_code:
done= do_variable_pdf(c);
if(done==0){

normal_warning("pdf backend","unexpected use of \\pdfvariable");
}
return;
break;
default:
confusion("variable");
break;
}
}


























/*:47*//*48:*/
#line 2903 "./luatexdir/tex/textoken.w"

boolean in_lua_escape;

static int the_convert_string_dvi(halfword c,int i)
{
return 0;
}

static int the_convert_string_pdf(halfword c,int i)
{
int ff;
if(get_o_mode()!=OMODE_PDF){
return 0;
}else if(scan_keyword("lastlink")){
print_int(pdf_last_link);
}else if(scan_keyword("retval")){
print_int(pdf_retval);
}else if(scan_keyword("lastobj")){
print_int(pdf_last_obj);
}else if(scan_keyword("lastannot")){
print_int(pdf_last_annot);
}else if(scan_keyword("xformname")){
print_int(obj_info(static_pdf,i));
}else if(scan_keyword("creationdate")){
return 0;
}else if(scan_keyword("fontname")){
set_ff(i);
print_int(obj_info(static_pdf,pdf_font_num(ff)));
}else if(scan_keyword("fontobjnum")){
set_ff(i);
print_int(pdf_font_num(ff));
}else if(scan_keyword("fontsize")){
print_scaled(font_size(i));
tprint("pt");
}else if(scan_keyword("pageref")){
print_int(pdf_get_obj(static_pdf,obj_type_page,i,false));
}else if(scan_keyword("colorstackinit")){
return 0;
}else{
return 0;
}
return 1;
}

str_number the_convert_string(halfword c,int i)
{
int old_setting;
str_number ret= 0;
boolean done= true;
old_setting= selector;
selector= new_string;
switch(c){
case number_code:
print_int(i);
break;



case math_style_code:
print_math_style();
break;


case roman_numeral_code:
print_roman_int(i);
break;

case uchar_code:
print(i);
break;

case font_id_code:
print_int(i);
break;
case font_name_code:
append_string((unsigned char*)font_name(i),(unsigned)strlen(font_name(i)));
if(font_size(i)!=font_dsize(i)){
tprint(" at ");
print_scaled(font_size(i));
tprint("pt");
}
break;


case uniform_deviate_code:
print_int(unif_rand(i));
break;
case normal_deviate_code:
print_int(norm_rand());
break;




case job_name_code:
print_job_name();
break;
case format_name_code:
print(format_name);
break;
case luatex_banner_code:
tprint(luatex_banner);
break;
case luatex_revision_code:
print(get_luatexrevision());
break;
case luatex_date_code:
print_int(get_luatex_date_info());
break;
case etex_code:
tprint(eTeX_version_string);
break;
case eTeX_revision_code:
tprint(eTeX_revision);
break;
case font_identifier_code:
print_font_identifier(i);
break;

case dvi_feedback_code:
done= the_convert_string_dvi(c,i);
break;
case pdf_feedback_code:
done= the_convert_string_pdf(c,i);
break;

default:
done= false;
break;
}
if(done){
ret= make_string();
}
selector= old_setting;
return ret;
}

/*:48*//*49:*/
#line 3047 "./luatexdir/tex/textoken.w"

FILE*read_file[16];
int read_open[17];

void initialize_read(void)
{
int k;
for(k= 0;k<=16;k++)
read_open[k]= closed;
}

/*:49*//*50:*/
#line 3062 "./luatexdir/tex/textoken.w"

void read_toks(int n,halfword r,halfword j)
{
halfword p;
halfword q;
int s;
int m;
scanner_status= defining;
warning_index= r;
p= get_avail();
def_ref= p;
set_token_ref_count(def_ref,0);
p= def_ref;
store_new_token(end_match_token);
if((n<0)||(n> 15))
m= 16;
else
m= n;
s= align_state;
align_state= 1000000;
do{

begin_file_reading();
iname= m+1;
if(read_open[m]==closed){







if(interaction> nonstop_mode){
if(n<0){
prompt_input("");
}else{
wake_up_terminal();
print_ln();
sprint_cs(r);
prompt_input(" =");
n= -1;
}
}else{
fatal_error
("*** (cannot \\read from terminal in nonstop modes)");
}

}else if(read_open[m]==just_open){






if(lua_input_ln(read_file[m],(m+1),false)){
read_open[m]= normal;
}else{
lua_a_close_in(read_file[m],(m+1));
read_open[m]= closed;
}

}else{





if(!lua_input_ln(read_file[m],(m+1),true)){
lua_a_close_in(read_file[m],(m+1));
read_open[m]= closed;
if(align_state!=1000000){
runaway();
print_err("File ended within \\read");
help1("This \\read has unbalanced braces.");
align_state= 1000000;
error();
}
}

}
ilimit= last;
if(end_line_char_inactive)
decr(ilimit);
else
buffer[ilimit]= (packed_ASCII_code)end_line_char_par;
first= ilimit+1;
iloc= istart;
istate= new_line;

if(j==1){
while(iloc<=ilimit){

do_buffer_to_unichar(cur_chr,iloc);
if(cur_chr==' ')
cur_tok= space_token;
else
cur_tok= cur_chr+other_token;
store_new_token(cur_tok);
}
}else{
while(1){
get_token();
if(cur_tok==0){

break;
}
if(align_state<1000000){

do{
get_token();
}while(cur_tok!=0);
align_state= 1000000;
break;
}
store_new_token(cur_tok);
}
}
end_file_reading();

}while(align_state!=1000000);
cur_val= def_ref;
scanner_status= normal;
align_state= s;
}

/*:50*//*51:*/
#line 3189 "./luatexdir/tex/textoken.w"

str_number tokens_to_string(halfword p)
{
int old_setting;
if(selector==new_string)
normal_error("tokens","tokens_to_string() called while selector = new_string");
old_setting= selector;
selector= new_string;
show_token_list(token_link(p),null,-1);
selector= old_setting;
return make_string();
}

/*:51*//*52:*/
#line 3202 "./luatexdir/tex/textoken.w"

#define make_room(a)                     \
    if ((unsigned)i+a+1> alloci) {        \
        ret =  xrealloc(ret,(alloci+64)); \
        alloci =  alloci + 64;            \
    }

#define append_i_byte(a) ret[i++] =  (char)(a)

#define Print_char(a) make_room(1); append_i_byte(a)

#define Print_uchar(s) {                                       \
    make_room(4);                                              \
    if (s<=0x7F) {                                             \
      append_i_byte(s);                                        \
    } else if (s<=0x7FF) {                                     \
      append_i_byte(0xC0 + (s / 0x40));                        \
      append_i_byte(0x80 + (s % 0x40));                        \
    } else if (s<=0xFFFF) {                                    \
      append_i_byte(0xE0 + (s / 0x1000));                      \
      append_i_byte(0x80 + ((s % 0x1000) / 0x40));             \
      append_i_byte(0x80 + ((s % 0x1000) % 0x40));             \
    } else if (s>=0x110000) {                                  \
      append_i_byte(s-0x11000);                                \
    } else {                                                   \
      append_i_byte(0xF0 + (s / 0x40000));                     \
      append_i_byte(0x80 + ((s % 0x40000) / 0x1000));          \
      append_i_byte(0x80 + (((s % 0x40000) % 0x1000) / 0x40)); \
      append_i_byte(0x80 + (((s % 0x40000) % 0x1000) % 0x40)); \
    } }

#define Print_esc(b) {                     \
    const char *v =  b;                     \
    if (e> 0 && e<STRING_OFFSET) {          \
        Print_uchar (e);                   \
    }                                      \
    make_room(strlen(v));                  \
    while (*v) { append_i_byte(*v); v++; } \
  }

#define Print_str(b) {                     \
    const char *v =  b;                     \
    make_room(strlen(v));                  \
    while (*v) { append_i_byte(*v); v++; } \
  }

#define is_cat_letter(a) \
    (get_char_cat_code(pool_to_unichar(str_string((a)))) == 11)

/*:52*//*53:*/
#line 3255 "./luatexdir/tex/textoken.w"

char*tokenlist_to_cstring(int pp,int inhibit_par,int*siz)
{
register int p,c,m;
int q;
int infop;
char*s,*sh;
int e= 0;
char*ret;
int match_chr= '#';
int n= '0';
unsigned alloci= 1024;
int i= 0;
p= pp;
if(p==null){
if(siz!=NULL)
*siz= 0;
return NULL;
}
ret= xmalloc(alloci);
p= token_link(p);
if(p!=null){
e= escape_char_par;
}
while(p!=null){
if(p<(int)fix_mem_min||p> (int)fix_mem_end){
Print_esc("CLOBBERED.");
break;
}
infop= token_info(p);
if(infop>=cs_token_flag){
if(!(inhibit_par&&infop==par_token)){
q= infop-cs_token_flag;
if(q<hash_base){
if(q==null_cs){
Print_esc("csname");
Print_esc("endcsname");
}else{
Print_esc("IMPOSSIBLE.");
}
}else if((q>=undefined_control_sequence)&&((q<=eqtb_size)||(q> eqtb_size+hash_extra))){
Print_esc("IMPOSSIBLE.");
}else if((cs_text(q)<0)||(cs_text(q)>=str_ptr)){
Print_esc("NONEXISTENT.");
}else{
str_number txt= cs_text(q);
sh= makecstring(txt);
s= sh;
if(is_active_cs(txt)){
s= s+3;
while(*s){
Print_char(*s);
s++;
}
}else{
if(e>=0&&e<0x110000)Print_uchar(e);
while(*s){
Print_char(*s);
s++;
}
if((!single_letter(txt))||is_cat_letter(txt)){
Print_char(' ');
}
}
free(sh);
}
}
}else{
if(infop<0){
Print_esc("BAD");
}else{
m= token_cmd(infop);
c= token_chr(infop);
switch(m){
case left_brace_cmd:
case right_brace_cmd:
case math_shift_cmd:
case tab_mark_cmd:
case sup_mark_cmd:
case sub_mark_cmd:
case spacer_cmd:
case letter_cmd:
case other_char_cmd:
Print_uchar(c);
break;
case mac_param_cmd:
if(!in_lua_escape&&(is_in_csname==0))
Print_uchar(c);
Print_uchar(c);
break;
case out_param_cmd:
Print_uchar(match_chr);
if(c<=9){
Print_char(c+'0');
}else{
Print_char('!');
goto EXIT;
}
break;
case match_cmd:
match_chr= c;
Print_uchar(c);
n++;
Print_char(n);
if(n> '9')
goto EXIT;
break;
case end_match_cmd:
if(c==0){
Print_char('-');
Print_char('>');
}
break;
default:
not_so_bad(Print_esc);
break;
}
}
}
p= token_link(p);
}
EXIT:
ret[i]= '\0';
if(siz!=NULL)
*siz= i;
return ret;
}

/*:53*//*54:*/
#line 3383 "./luatexdir/tex/textoken.w"

lstring*tokenlist_to_lstring(int pp,int inhibit_par)
{
int siz;
lstring*ret= xmalloc(sizeof(lstring));
ret->s= (unsigned char*)tokenlist_to_cstring(pp,inhibit_par,&siz);
ret->l= (size_t)siz;
return ret;
}

/*:54*//*55:*/
#line 3393 "./luatexdir/tex/textoken.w"

void free_lstring(lstring*ls)
{
if(ls==NULL)
return;
if(ls->s!=NULL)
free(ls->s);
free(ls);
}/*:55*/
