/*1:*/
#line 20 "./luatexdir/tex/printing.w"

#include "ptexlib.h"
#include "lua/luatex-api.h" 

/*:1*//*2:*/
#line 24 "./luatexdir/tex/printing.w"

#define font_id_text(A) cs_text(font_id_base+(A))

#define wlog(A)  fputc(A,log_file)
#define wterm(A) fputc(A,term_out)

int new_string_line= 0;
int escape_controls= 1;

/*:2*//*3:*/
#line 72 "./luatexdir/tex/printing.w"

alpha_file log_file;
int selector= term_only;
int dig[23];
int tally= 0;
int term_offset= 0;
int file_offset= 0;
packed_ASCII_code trick_buf[(ssup_error_line+1)];
int trick_count;
int first_count;
boolean inhibit_par_tokens= false;

/*:3*//*4:*/
#line 86 "./luatexdir/tex/printing.w"

void print_ln(void)
{
switch(selector){
case no_print:
break;
case term_only:
wterm_cr();
term_offset= 0;
break;
case log_only:
wlog_cr();
file_offset= 0;
break;
case term_and_log:
wterm_cr();
wlog_cr();
term_offset= 0;
file_offset= 0;
break;
case pseudo:
break;
case new_string:
if(new_string_line> 0)
print_char(new_string_line);
break;
default:
fprintf(write_file[selector],"\n");
break;
}

}

/*:4*//*5:*/
#line 128 "./luatexdir/tex/printing.w"

#define needs_escaping(A) \
    ((! escape_controls) || (A>=0x20) || (A==0x0A) || (A==0x0D) || (A==0x09))

#define escaped_char(A) \
    A+64

#define wterm_char(A) \
    if (needs_escaping(A)) { \
        wterm(A); \
    } else { \
        if (term_offset+2>=max_print_line) { \
            wterm_cr(); \
            term_offset= 0; \
        } \
        wterm('^'); \
        wterm('^'); \
        wterm(escaped_char(A)); \
        term_offset +=  2; \
    }












#define needs_wrapping(A,B) \
  (   (A>=0xC0) && \
    (((A>=0xF0) && (B+4>=max_print_line)) || \
     ((A>=0xE0) && (B+3>=max_print_line)) || \
     (             (B+2>=max_print_line))) \
  )

#define fix_term_offset(A) \
    if (needs_wrapping(A,term_offset)){ \
        wterm_cr(); \
        term_offset= 0; \
    }

#define fix_log_offset(A) \
    if (needs_wrapping(A,file_offset)){ \
        wlog_cr(); \
        file_offset= 0; \
    }

void print_char(int s)
{
if(s<0||s> 255){
formatted_warning("print","weird character %i",s);
return;
}
if(s==int_par(new_line_char_code)){
if(selector<pseudo){
print_ln();
return;
}
}
switch(selector){
case no_print:
break;
case term_only:
fix_term_offset(s);
wterm_char(s);
incr(term_offset);
if(term_offset==max_print_line){
wterm_cr();
term_offset= 0;
}
break;
case log_only:
fix_log_offset(s);
wlog(s);
incr(file_offset);
if(file_offset==max_print_line){
wlog_cr();
file_offset= 0;
}
break;
case term_and_log:
fix_term_offset(s);
fix_log_offset(s);
wterm_char(s);
wlog(s);
incr(term_offset);
incr(file_offset);
if(term_offset==max_print_line){
wterm_cr();
term_offset= 0;
}
if(file_offset==max_print_line){
wlog_cr();
file_offset= 0;
}
break;
case pseudo:
if(tally<trick_count)
trick_buf[tally%error_line]= (packed_ASCII_code)s;
break;
case new_string:
append_char(s);
break;
default:
fprintf(write_file[selector],"%c",s);
}
incr(tally);
}

/*:5*//*6:*/
#line 257 "./luatexdir/tex/printing.w"

void print(int s)
{
if(s>=str_ptr){
normal_warning("print","bad string pointer");
return;
}else if(s<STRING_OFFSET){
if(s<0){
normal_warning("print","bad string offset");
}else{

if((false)&&(selector> pseudo)){

print_char(s);
return;
}
if(s==int_par(new_line_char_code)){
if(selector<pseudo){
print_ln();
return;
}
}
if(s<=0x7F){
print_char(s);
}else if(s<=0x7FF){
print_char(0xC0+(s/0x40));
print_char(0x80+(s%0x40));
}else if(s<=0xFFFF){
print_char(0xE0+(s/0x1000));
print_char(0x80+((s%0x1000)/0x40));
print_char(0x80+((s%0x1000)%0x40));
}else if(s>=0x110000){
int c= s-0x110000;
if(c>=256){
formatted_warning("print","bad raw byte to print (c=%d), skipped",c);
}else{
print_char(c);
}
}else{
print_char(0xF0+(s/0x40000));
print_char(0x80+((s%0x40000)/0x1000));
print_char(0x80+(((s%0x40000)%0x1000)/0x40));
print_char(0x80+(((s%0x40000)%0x1000)%0x40));
}
}
return;
}
if(selector==new_string){
append_string(str_string(s),(unsigned)str_length(s));
return;
}
lprint(&str_lstring(s));
}

void lprint(lstring*ss){
unsigned char*j,*l;
j= ss->s;
l= j+ss->l;
while(j<l){


if((j<l-4)&&(*j==0xF4)&&(*(j+1)==0x90)){
int c= (*(j+2)-128)*64+(*(j+3)-128);
assert(c>=0&&c<256);
print_char(c);
j= j+4;
}else{
print_char(*j);
incr(j);
}
}
}

/*:6*//*7:*/
#line 333 "./luatexdir/tex/printing.w"

void print_nlp(void)
{
if(new_string_line> 0){
print_char(new_string_line);
}else if(((term_offset> 0)&&(odd(selector)))||
((file_offset> 0)&&(selector>=log_only))){
print_ln();
}
}

void print_nl(str_number s)
{
print_nlp();
print(s);
}

/*:7*//*8:*/
#line 354 "./luatexdir/tex/printing.w"

#define t_flush_buffer(target,offset) \
    buffer[i++] =  '\n'; \
    buffer[i++] =  '\0';\
    fputs(buffer, target); \
    i =  0; \
    buffer[0] =  '\0'; \
    offset= 0;

void tprint(const char*sss)
{
char*buffer= NULL;
int i= 0;
int newlinechar= int_par(new_line_char_code);
int dolog= 0;
int doterm= 0;
switch(selector){
case no_print:
return;
break;
case term_only:
doterm= 1;
break;
case log_only:
dolog= 1;
break;
case term_and_log:
dolog= 1;
doterm= 1;
break;
case pseudo:
while(*sss){
if(tally<trick_count){
trick_buf[tally%error_line]= (packed_ASCII_code)*sss++;
tally++;
}else{
return;
}
}
return;
break;
case new_string:
append_string((const unsigned char*)sss,(unsigned)strlen(sss));
return;
break;
default:
{
char*newstr= xstrdup(sss);
char*s;
for(s= newstr;*s;s++){
if(*s==newlinechar){
*s= '\n';
}
}
fputs(newstr,write_file[selector]);
free(newstr);
return;
}
break;
}

if(dolog||doterm){
buffer= xmalloc(strlen(sss)*3);
if(dolog){
const unsigned char*ss= (const unsigned char*)sss;
while(*ss){
int s= *ss++;
if(needs_wrapping(s,file_offset)||s==newlinechar){
t_flush_buffer(log_file,file_offset);
}
if(s!=newlinechar){
buffer[i++]= s;
if(file_offset++==max_print_line){
t_flush_buffer(log_file,file_offset);
}
}
}
if(*buffer){
buffer[i++]= '\0';
fputs(buffer,log_file);
buffer[0]= '\0';
}
i= 0;
}
if(doterm){
const unsigned char*ss= (const unsigned char*)sss;
while(*ss){
int s= *ss++;
if(needs_wrapping(s,term_offset)||s==newlinechar){
t_flush_buffer(term_out,term_offset);
}
if(s!=newlinechar){
if(needs_escaping(s)){
buffer[i++]= s;
}else{
buffer[i++]= '^';
buffer[i++]= '^';
buffer[i++]= escaped_char(s);
term_offset+= 2;
}
if(++term_offset==max_print_line){
t_flush_buffer(term_out,term_offset);
}
}
}
if(*buffer){
buffer[i++]= '\0';
fputs(buffer,term_out);
}
}
free(buffer);
}
}

void tprint_nl(const char*s)
{
print_nlp();
tprint(s);
}

/*:8*//*9:*/
#line 480 "./luatexdir/tex/printing.w"

void print_banner(const char*v)
{
int callback_id= callback_defined(start_run_callback);
if(callback_id==0){
fprintf(term_out,"This is "MyName", Version %s%s ",v,WEB2CVERSION);
if(format_ident> 0)
print(format_ident);
print_ln();
if(show_luahashchars){
wterm(' ');
fprintf(term_out,"Number of bits used by the hash function ("my_name"): %d",LUAI_HASHLIMIT);
print_ln();
}
if(shellenabledp){
wterm(' ');
if(restrictedshell)
fprintf(term_out,"restricted ");
fprintf(term_out,"system commands enabled.\n");
}
}else if(callback_id> 0){
run_callback(callback_id,"->");
}
}

/*:9*//*10:*/
#line 505 "./luatexdir/tex/printing.w"

void log_banner(const char*v)
{
const char*months[]= {"   ",
"JAN","FEB","MAR","APR","MAY","JUN",
"JUL","AUG","SEP","OCT","NOV","DEC"
};
unsigned month= (unsigned)int_par(month_code);
if(month> 12)
month= 0;
fprintf(log_file,"This is "MyName", Version %s%s ",v,WEB2CVERSION);
print(format_ident);
print_char(' ');
print_char(' ');
print_int(int_par(day_code));
print_char(' ');
fprintf(log_file,"%s",months[month]);
print_char(' ');
print_int(int_par(year_code));
print_char(' ');
print_two(int_par(time_code)/60);
print_char(':');
print_two(int_par(time_code)%60);
if(shellenabledp){
wlog_cr();
wlog(' ');
if(restrictedshell)
fprintf(log_file,"restricted ");
fprintf(log_file,"system commands enabled.");
}
if(filelineerrorstylep){
wlog_cr();
fprintf(log_file," file:line:error style messages enabled.");
}
}

/*:10*//*11:*/
#line 541 "./luatexdir/tex/printing.w"

void print_version_banner(void)
{
fprintf(term_out,"%s",luatex_banner);
}

/*:11*//*12:*/
#line 550 "./luatexdir/tex/printing.w"

void print_esc(str_number s)
{
int c= int_par(escape_char_code);
if(c>=0&&c<STRING_OFFSET)
print(c);
print(s);
}

/*:12*//*13:*/
#line 561 "./luatexdir/tex/printing.w"

void tprint_esc(const char*s)
{
int c= int_par(escape_char_code);
if(c>=0&&c<STRING_OFFSET)
print(c);
tprint(s);
}

/*:13*//*14:*/
#line 572 "./luatexdir/tex/printing.w"

void print_the_digs(eight_bits k)
{

while(k--> 0){
if(dig[k]<10)
print_char('0'+dig[k]);
else
print_char('A'-10+dig[k]);
}
}

/*:14*//*15:*/
#line 590 "./luatexdir/tex/printing.w"

void print_int(longinteger n)
{
int k= 0;
longinteger m;
if(n<0){
print_char('-');
if(n> -100000000){
n= -n;
}else{
m= -1-n;
n= m/10;
m= (m%10)+1;
k= 1;
if(m<10)
dig[0]= (int)m;
else{
dig[0]= 0;
incr(n);
}
}
}
do{
dig[k]= (int)(n%10);
n= n/10;
incr(k);
}while(n!=0);
print_the_digs((eight_bits)k);
}


/*:15*//*16:*/
#line 624 "./luatexdir/tex/printing.w"

void print_two(int n)
{
n= abs(n)%100;
print_char('0'+(n/10));
print_char('0'+(n%10));
}

/*:16*//*17:*/
#line 634 "./luatexdir/tex/printing.w"

void print_hex(int n)
{
int k= 0;
print_char('"');
do{
dig[k]= n%16;
n= n/16;
incr(k);
}while(n!=0);
print_the_digs((eight_bits)k);
}

/*:17*//*18:*/
#line 652 "./luatexdir/tex/printing.w"

void print_roman_int(int n)
{
char*j,*k;
int u,v;
char mystery[]= "m2d5c2l5x2v5i";
j= (char*)mystery;
v= 1000;
while(1){
while(n>=v){
print_char(*j);
n= n-v;
}
if(n<=0){

return;
}
k= j+2;
u= v/(*(k-1)-'0');
if(*(k-1)=='2'){
k= k+2;
u= u/(*(k-1)-'0');
}
if(n+u>=v){
print_char(*k);
n= n+u;
}else{
j= j+2;
v= v/(*(j-1)-'0');
}
}
}

/*:18*//*19:*/
#line 688 "./luatexdir/tex/printing.w"

void print_current_string(void)
{
unsigned j= 0;
while(j<cur_length)
print_char(cur_string[j++]);
}

/*:19*//*20:*/
#line 703 "./luatexdir/tex/printing.w"

void print_cs(int p)
{
str_number t= cs_text(p);
if(p<hash_base){

if(p==null_cs){
tprint_esc("csname");
tprint_esc("endcsname");
print_char(' ');
}else{
tprint_esc("IMPOSSIBLE.");
}
}else if((p>=undefined_control_sequence)&&
((p<=eqtb_size)||p> eqtb_size+hash_extra)){
tprint_esc("IMPOSSIBLE.");
}else if(t>=str_ptr){
tprint_esc("NONEXISTENT.");
}else{
if(is_active_cs(t)){
print(active_cs_value(t));
}else{
print_esc(t);
if(single_letter(t)){
if(get_cat_code(int_par(cat_code_table_code),
pool_to_unichar(str_string(t)))==letter_cmd)
print_char(' ');
}else{
print_char(' ');
}
}
}
}

/*:20*//*21:*/
#line 740 "./luatexdir/tex/printing.w"

void sprint_cs(pointer p)
{
str_number t;
if(p==null_cs){
tprint_esc("csname");
tprint_esc("endcsname");
}else{
t= cs_text(p);
if(is_active_cs(t))
print(active_cs_value(t));
else
print_esc(t);
}
}

void sprint_cs_name(pointer p)
{
str_number t;
if(p!=null_cs){
t= cs_text(p);
if(is_active_cs(t))
print(active_cs_value(t));
else
print(t);
}
}

/*:21*//*22:*/
#line 770 "./luatexdir/tex/printing.w"

void prompt_input(const char*s)
{
wake_up_terminal();
tprint(s);
term_input();
}

/*:22*//*23:*/
#line 781 "./luatexdir/tex/printing.w"

void print_glue(scaled d,int order,const char*s)
{
print_scaled(d);
if((order<normal)||(order> filll)){
tprint("foul");
}else if(order> normal){
tprint("fi");
while(order> sfi){
print_char('l');
decr(order);
}
}else if(s!=NULL){
tprint(s);
}
}

/*:23*//*24:*/
#line 800 "./luatexdir/tex/printing.w"

void print_spec(int p,const char*s)
{
if(p<0){
print_char('*');
}else{
print_scaled(width(p));
if(s!=NULL)
tprint(s);
if(stretch(p)!=0){
tprint(" plus ");
print_glue(stretch(p),stretch_order(p),s);
}
if(shrink(p)!=0){
tprint(" minus ");
print_glue(shrink(p),shrink_order(p),s);
}
}
}

/*:24*//*25:*/
#line 837 "./luatexdir/tex/printing.w"

int font_in_short_display;

/*:25*//*26:*/
#line 843 "./luatexdir/tex/printing.w"

void print_font_identifier(internal_font_number f)
{
str_number fonttext;
fonttext= font_id_text(f);
if(fonttext> 0){
print_esc(fonttext);
}else{
tprint_esc("FONT");
print_int(f);
}
if(int_par(tracing_fonts_code)> 0){
tprint(" (");
print_font_name(f);
if(font_size(f)!=font_dsize(f)){
tprint("@");
print_scaled(font_size(f));
tprint("pt");
}
print_char(')');
}
}

/*:26*//*27:*/
#line 868 "./luatexdir/tex/printing.w"

void short_display(int p)
{
while(p!=null){
if(is_char_node(p)){
if(lig_ptr(p)!=null){
short_display(lig_ptr(p));
}else{
if(font(p)!=font_in_short_display){
if(!is_valid_font(font(p)))
print_char('*');
else
print_font_identifier(font(p));
print_char(' ');
font_in_short_display= font(p);
}
print(character(p));
}
}else{

print_short_node_contents(p);
}
p= vlink(p);
}
}

/*:27*//*29:*/
#line 900 "./luatexdir/tex/printing.w"

void print_font_and_char(int p)
{
if(!is_valid_font(font(p)))
print_char('*');
else
print_font_identifier(font(p));
print_char(' ');
print(character(p));
}

/*:29*//*30:*/
#line 913 "./luatexdir/tex/printing.w"

void print_mark(int p)
{
print_char('{');
if((p<(int)fix_mem_min)||(p> (int)fix_mem_end))
tprint_esc("CLOBBERED.");
else
show_token_list(token_link(p),null,max_print_line-10);
print_char('}');
}

/*:30*//*31:*/
#line 926 "./luatexdir/tex/printing.w"

void print_rule_dimen(scaled d)
{
if(is_running(d))
print_char('*');
else
print_scaled(d);
}

/*:31*//*32:*/
#line 948 "./luatexdir/tex/printing.w"

int depth_threshold;
int breadth_max;

/*:32*//*33:*/
#line 955 "./luatexdir/tex/printing.w"

void show_box(halfword p)
{
depth_threshold= int_par(show_box_depth_code);
breadth_max= int_par(show_box_breadth_code);
if(breadth_max<=0)
breadth_max= 5;

show_node_list(p);
print_ln();
}

/*:33*//*34:*/
#line 969 "./luatexdir/tex/printing.w"

void short_display_n(int p,int m)
{
int i= 0;
font_in_short_display= null_font;
if(p==null)
return;
while(p!=null){
if(is_char_node(p)){
if(p<=max_halfword){
if(font(p)!=font_in_short_display){
if(!is_valid_font(font(p)))
print_char('*');
else
print_font_identifier(font(p));
print_char(' ');
font_in_short_display= font(p);
}
print(character(p));
}
}else{
if((type(p)==glue_node)||
(type(p)==disc_node)||
(type(p)==penalty_node)||
((type(p)==kern_node)&&(subtype(p)==explicit)))
incr(i);
if(i>=m)
return;
if(type(p)==disc_node){
print_char('|');
short_display(vlink(pre_break(p)));
print_char('|');
short_display(vlink(post_break(p)));
print_char('|');
}else{

print_short_node_contents(p);
}
}
p= vlink(p);
if(p==null)
return;
}
update_terminal();
}

/*:34*//*35:*/
#line 1021 "./luatexdir/tex/printing.w"

void print_csnames(int hstart,int hfinish)
{
int h;
unsigned char*c,*l;
fprintf(stderr,"fmtdebug:csnames from %d to %d:",(int)hstart,(int)hfinish);
for(h= hstart;h<=hfinish;h++){
if(cs_text(h)> 0){

c= str_string(cs_text(h));
l= c+str_length(cs_text(h));
while(c<l){

fputc(*c++,stderr);
}
fprintf(stderr,"|");
}
}
}

/*:35*//*36:*/
#line 1045 "./luatexdir/tex/printing.w"

void print_file_line(void)
{
int level= in_open;
while((level> 0)&&(full_source_filename_stack[level]==0))
decr(level);
if(level==0){
tprint_nl("! ");
}else{
tprint_nl("");
tprint(full_source_filename_stack[level]);
print_char(':');
if(level==in_open)
print_int(line);
else
print_int(line_stack[level+1]);
tprint(": ");
}
}

/*:36*//*37:*/
#line 1069 "./luatexdir/tex/printing.w"

void begin_diagnostic(void)
{
global_old_setting= selector;
if((int_par(tracing_online_code)<=0)&&(selector==term_and_log)){
decr(selector);
if(history==spotless)
history= warning_issued;
}
}

/*:37*//*38:*/
#line 1082 "./luatexdir/tex/printing.w"

void end_diagnostic(boolean blank_line)
{
tprint_nl("");
if(blank_line)
print_ln();
selector= global_old_setting;
}

/*:38*//*39:*/
#line 1094 "./luatexdir/tex/printing.w"

int global_old_setting;/*:39*/
