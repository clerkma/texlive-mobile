/*1:*/
#line 24 "./luatexdir/tex/mainbody.w"



#include "ptexlib.h"

/*:1*//*3:*/
#line 182 "./luatexdir/tex/mainbody.w"

boolean luainit;
boolean tracefilenames;


/*:3*//*4:*/
#line 193 "./luatexdir/tex/mainbody.w"

boolean ini_version;
boolean dump_option;
boolean dump_line;
int bound_default;
char*bound_name;
int error_line;
int half_error_line;

int max_print_line;
int max_strings;
int strings_free;
int font_k;
int buf_size;


int stack_size;
int max_in_open;

int param_size;
int nest_size;
int save_size;

int expand_depth;
int parsefirstlinep;
int filelineerrorstylep;
int haltonerrorp;
boolean quoted_filename;

/*:4*//*5:*/
#line 222 "./luatexdir/tex/mainbody.w"

int get_luatexversion(void)
{
return luatex_version;
}

str_number get_luatexrevision(void)
{
return luatex_revision;
}

int get_luatex_date_info(void)
{
return luatex_date_info;
}


/*:5*//*6:*/
#line 250 "./luatexdir/tex/mainbody.w"

#define const_chk(A) do {   \
 if (A < inf_##A) A =  inf_##A;  \
 if (A >  sup_##A) A =  sup_##A;  \
    } while (0)

#define setup_bound_var(A,B,C) do {    \
 if (luainit> 0) {     \
     get_lua_number("texconfig",B,&C);   \
     if (C==0) C= A;     \
 } else {      \
     integer x;      \
     setupboundvariable(&x, B, A);   \
     C =  (int)x;      \
 }       \
    } while (0)


int ready_already= 0;

int main_initialize(void)
{


int bad= 0;





setup_bound_var(15000,"max_strings",max_strings);
setup_bound_var(100,"strings_free",strings_free);
setup_bound_var(3000,"buf_size",buf_size);
setup_bound_var(50,"nest_size",nest_size);
setup_bound_var(15,"max_in_open",max_in_open);
setup_bound_var(60,"param_size",param_size);
setup_bound_var(4000,"save_size",save_size);
setup_bound_var(300,"stack_size",stack_size);
setup_bound_var(16384,"dvi_buf_size",dvi_buf_size);
setup_bound_var(79,"error_line",error_line);
setup_bound_var(50,"half_error_line",half_error_line);
setup_bound_var(79,"max_print_line",max_print_line);
setup_bound_var(0,"hash_extra",hash_extra);
setup_bound_var(72,"pk_dpi",pk_dpi);
setup_bound_var(10000,"expand_depth",expand_depth);


const_chk(buf_size);
const_chk(nest_size);
const_chk(max_in_open);
const_chk(param_size);
const_chk(save_size);
const_chk(stack_size);
const_chk(dvi_buf_size);
const_chk(max_strings);
const_chk(strings_free);
const_chk(hash_extra);
const_chk(pk_dpi);
if(error_line> ssup_error_line)
error_line= ssup_error_line;


buffer= xmallocarray(packed_ASCII_code,(unsigned)buf_size);
nest= xmallocarray(list_state_record,(unsigned)nest_size);
save_stack= xmallocarray(save_record,(unsigned)save_size);
input_stack= xmallocarray(in_state_record,(unsigned)stack_size);
input_file= xmallocarray(alpha_file,(unsigned)max_in_open);
input_file_callback_id= xmallocarray(int,(unsigned)max_in_open);
line_stack= xmallocarray(int,(unsigned)max_in_open);
eof_seen= xmallocarray(boolean,(unsigned)max_in_open);
grp_stack= xmallocarray(save_pointer,(unsigned)max_in_open);
if_stack= xmallocarray(pointer,(unsigned)max_in_open);
source_filename_stack= xmallocarray(str_number,(unsigned)max_in_open);
full_source_filename_stack= xmallocarray(char*,(unsigned)max_in_open);
param_stack= xmallocarray(halfword,(unsigned)param_size);
dvi_buf= xmallocarray(eight_bits,(unsigned)dvi_buf_size);

if(ini_version){
fixmem= xmallocarray(smemory_word,fix_mem_init+1);
memset(voidcast(fixmem),0,(fix_mem_init+1)*sizeof(smemory_word));
fix_mem_min= 0;
fix_mem_max= fix_mem_init;
eqtb_top= eqtb_size+hash_extra;
if(hash_extra==0)
hash_top= undefined_control_sequence;
else
hash_top= eqtb_top;
hash= xmallocarray(two_halves,(unsigned)(hash_top+1));
memset(hash,0,sizeof(two_halves)*(unsigned)(hash_top+1));
eqtb= xmallocarray(memory_word,(unsigned)(eqtb_top+1));
memset(eqtb,0,sizeof(memory_word)*(unsigned)(eqtb_top+1));
init_string_pool_array((unsigned)max_strings);
reset_cur_string();
}

if((half_error_line<30)||(half_error_line> error_line-15))
bad= 1;
if(max_print_line<60)
bad= 2;
if(dvi_buf_size%8!=0)
bad= 3;
if(hash_prime> hash_size)
bad= 5;
if(max_in_open>=(sup_max_in_open+1))
bad= 6;


if((min_quarterword> 0)||(max_quarterword<0x7FFF))
bad= 11;
if((min_halfword> 0)||(max_halfword<0x3FFFFFFF))
bad= 12;
if((min_quarterword<min_halfword)||(max_quarterword> max_halfword))
bad= 13;
if(font_base<min_quarterword)
bad= 15;
if((save_size> max_halfword)||(max_strings> max_halfword))
bad= 17;
if(buf_size> max_halfword)
bad= 18;
if(max_quarterword-min_quarterword<0xFFFF)
bad= 19;
if(cs_token_flag+eqtb_size+hash_extra> max_halfword)
bad= 21;
if(bad> 0){
wterm_cr();
fprintf(term_out,
"Ouch---my internal constants have been clobbered! ---case %d",
(int)bad);
}else{
initialize();
if(ini_version){

no_new_control_sequence= false;
first= 0;
initialize_commands();
initialize_etex_commands();
init_str_ptr= str_ptr;
no_new_control_sequence= true;
fix_date_and_time();
}
ready_already= 314159;
}
return bad;
}

/*:6*//*7:*/
#line 395 "./luatexdir/tex/mainbody.w"

void main_body(void)
{
static char pdftex_map[]= "pdftex.map";
int bad= main_initialize();
history= fatal_error_stop;
t_open_out();
if(!luainit)
tracefilenames= true;
if(bad> 0){
goto FINAL_END;
}
print_banner(luatex_version_string);









initialize_inputstack();
if(buffer[iloc]=='*')
incr(iloc);
if((format_ident==0)||(buffer[iloc]=='&')||dump_line){
char*fname= NULL;
if(format_ident!=0&&!ini_version)
initialize();
if((fname= open_fmt_file())==NULL)
goto FINAL_END;
if(!load_fmt_file(fname)){
zwclose(fmt_file);
goto FINAL_END;
}
zwclose(fmt_file);
while((iloc<ilimit)&&(buffer[iloc]==' '))
incr(iloc);
}
if(output_mode_option!=0)
output_mode_par= output_mode_value;
if(draft_mode_option!=0){
draft_mode_par= draft_mode_value;
}

pdf_init_map_file((char*)pdftex_map);

if(end_line_char_inactive)
decr(ilimit);
else
buffer[ilimit]= (packed_ASCII_code)end_line_char_par;
fix_date_and_time();
random_seed= (microseconds*1000)+(epochseconds%1000000);
init_randoms(random_seed);
initialize_math();
fixup_selector(log_opened_global);
check_texconfig_init();
if((iloc<ilimit)&&(get_cat_code(cat_code_table_code,buffer[iloc])!=escape_cmd))
start_input();

text_dir_ptr= new_dir(0);

history= spotless;

synctexinitcommand();
main_control();
flush_node(text_dir_ptr);
final_cleanup();
close_files_and_terminate();
FINAL_END:
do_final_end();
}


/*:7*//*8:*/
#line 483 "./luatexdir/tex/mainbody.w"

void close_files_and_terminate(void)
{
int callback_id;
callback_id= callback_defined(stop_run_callback);
finalize_write_files();
if(tracing_stats_par> 0){
if(callback_id==0){






if(log_opened_global){
fprintf(log_file,
"\n\nHere is how much of LuaTeX's memory you used:\n");
fprintf(log_file," %d string%s out of %d\n",
(int)(str_ptr-init_str_ptr),
(str_ptr==(init_str_ptr+1)?"":"s"),
(int)(max_strings-init_str_ptr+STRING_OFFSET));
fprintf(log_file," %d,%d words of node,token memory allocated",
(int)var_mem_max,(int)fix_mem_max);
print_node_mem_stats();
fprintf(log_file,
" %d multiletter control sequences out of %ld+%d\n",
(int)cs_count,(long)hash_size,(int)hash_extra);
fprintf(log_file," %d font%s using %d bytes\n",
(int)max_font_id(),(max_font_id()==1?"":"s"),
(int)font_bytes);
fprintf(log_file,
" %di,%dn,%dp,%db,%ds stack positions out of %di,%dn,%dp,%db,%ds\n",
(int)max_in_stack,(int)max_nest_stack,
(int)max_param_stack,(int)max_buf_stack,
(int)max_save_stack+6,(int)stack_size,
(int)nest_size,(int)param_size,(int)buf_size,
(int)save_size);
}
}
}
wake_up_terminal();

wrapup_backend();

synctexterminate(log_opened_global);
free_text_codes();
free_math_codes();
if(log_opened_global){
wlog_cr();
selector= selector-2;
if((selector==term_only)&&(callback_id==0)){
tprint_nl("Transcript written on ");
tprint_file_name(NULL,texmf_log_name,NULL);
print_char('.');
print_ln();
}
lua_a_close_out(log_file);
}
}


/*:8*//*9:*/
#line 547 "./luatexdir/tex/mainbody.w"

void final_cleanup(void)
{
int c;
halfword i;
halfword t;
c= cur_chr;
if(job_name==0)
open_log_file();
while(input_ptr> 0)
if(istate==token_list)
end_token_list();
else
end_file_reading();
while(open_parens> 0){
report_stop_file(filetype_tex);
decr(open_parens);
}
if(cur_level> level_one){
tprint_nl("(\\end occurred inside a group at level ");
print_int(cur_level-level_one);
print_char(')');
show_save_groups();
}
while(cond_ptr!=null){
tprint_nl("(\\end occurred when ");
print_cmd_chr(if_test_cmd,cur_if);
if(if_line!=0){
tprint(" on line ");
print_int(if_line);
}
tprint(" was incomplete)");
if_line= if_line_field(cond_ptr);
cur_if= subtype(cond_ptr);
t= cond_ptr;
cond_ptr= vlink(cond_ptr);
flush_node(t);
}
if(callback_defined(stop_run_callback)==0)
if(history!=spotless)
if((history==warning_issued)||(interaction<error_stop_mode))
if(selector==term_and_log){
selector= term_only;
tprint_nl("(see the transcript file for additional information)");
selector= term_and_log;
}
if(c==1){
if(ini_version){
for(i= 0;i<=biggest_used_mark;i++){
delete_top_mark(i);
delete_first_mark(i);
delete_bot_mark(i);
delete_split_first_mark(i);
delete_split_bot_mark(i);
}
for(c= last_box_code;c<=vsplit_code;c++)
flush_node_list(disc_ptr[c]);
if(last_glue!=max_halfword){
flush_node(last_glue);
}
while(pseudo_files!=null)
pseudo_close();
store_fmt_file();
return;
}
tprint_nl("(\\dump is performed only by INITEX)");
return;
}
}

/*:9*//*10:*/
#line 635 "./luatexdir/tex/mainbody.w"

#ifdef DEBUG
void debug_help(void)
{
int k;
int m= 0,n= 0,l= 0;
while(1){
wake_up_terminal();
tprint_nl("debug # (-1 to exit):");
update_terminal();
(void)fscanf(term_in,"%d",&m);
if(m<0)
return;
else if(m==0)
abort();
else{
(void)fscanf(term_in,"%d",&n);
switch(m){
case 1:
print_word(varmem[n]);
break;
case 2:
print_int(info(n));
break;
case 3:
print_int(link(n));
break;
case 4:
print_word(eqtb[n]);
break;
case 6:
print_int(save_type(n));
print_int(save_level(n));
print_word(save_word(n));
break;
case 7:
show_box(n);
break;
case 8:
breadth_max= 10000;
depth_threshold= 0x7FFFFFFF;
show_node_list(n);
break;
case 9:
show_token_list(n,null,1000);
break;
case 10:
print(n);
break;
case 13:
(void)fscanf(term_in,"%d",&l);
print_cmd_chr(n,l);
break;
case 14:
for(k= 0;k<=n;k++)
print(buffer[k]);
break;
case 15:
font_in_short_display= null_font;
short_display(n);
break;
default:
tprint("?");
break;
}
}
}
}
#endif/*:10*/
