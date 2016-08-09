/*1:*/
#line 31 "./luatexdir/dvi/dvigen.w"

#include "ptexlib.h"

/*:1*//*2:*/
#line 35 "./luatexdir/dvi/dvigen.w"

#undef write_dvi



#define mode cur_list.mode_field        

/*:2*//*5:*/
#line 356 "./luatexdir/dvi/dvigen.w"

#define set_char_0  0           
#define set1  128               
#define set_rule  132           
#define put1    133             
#define put_rule  137           
#define nop  138                
#define bop  139                
#define eop  140                
#define push  141               
#define pop  142                
#define right1    143           
#define right4    146           
#define w0  147                 
#define w1  148                 
#define x0  152                 
#define x1  153                 
#define down1  157              
#define down4  160              
#define y0  161                 
#define y1  162                 
#define z0  166                 
#define z1  167                 
#define fnt_num_0  171          
#define fnt1  235               
#define xxx1  239               
#define xxx4  242               
#define fnt_def1  243           
#define pre  247                
#define post  248               
#define post_post  249          

/*:5*//*6:*/
#line 419 "./luatexdir/dvi/dvigen.w"

#define id_byte 2               

/*:6*//*11:*/
#line 571 "./luatexdir/dvi/dvigen.w"

int total_pages= 0;
scaled max_v= 0;
scaled max_h= 0;
int max_push= 0;
int last_bop= -1;
int dead_cycles= 0;
boolean doing_leaders= false;
int oval,ocmd;
pointer g;
int lq,lr;
int cur_s= -1;

/*:11*//*13:*/
#line 615 "./luatexdir/dvi/dvigen.w"

int dvi_buf_size= 800;
eight_bits*dvi_buf;
dvi_index half_buf= 0;
dvi_index dvi_limit= 0;
dvi_index dvi_ptr= 0;
int dvi_offset= 0;
int dvi_gone= 0;

/*:13*//*14:*/
#line 635 "./luatexdir/dvi/dvigen.w"

static void write_dvi(dvi_index a,dvi_index b)
{
dvi_index k;
for(k= a;k<=b;k++)
fputc(dvi_buf[k],static_pdf->file);
}


void dvi_swap(void)
{
if(dvi_limit==dvi_buf_size){
write_dvi(0,half_buf-1);
dvi_limit= half_buf;
dvi_offset= dvi_offset+dvi_buf_size;
dvi_ptr= 0;
}else{
write_dvi(half_buf,dvi_buf_size-1);
dvi_limit= dvi_buf_size;
}
dvi_gone= dvi_gone+half_buf;
}

/*:14*//*15:*/
#line 661 "./luatexdir/dvi/dvigen.w"

void dvi_four(int x)
{
if(x>=0){
dvi_out(x/0100000000);
}else{
x= x+010000000000;
x= x+010000000000;
dvi_out((x/0100000000)+128);
}
x= x%0100000000;
dvi_out(x/0200000);
x= x%0200000;
dvi_out(x/0400);
dvi_out(x%0400);
}

/*:15*//*16:*/
#line 685 "./luatexdir/dvi/dvigen.w"

void dvi_push(void)
{
dvi_out(push);
}

void dvi_pop(int l)
{
if((l==dvi_offset+dvi_ptr)&&(dvi_ptr> 0))
decr(dvi_ptr);
else
dvi_out(pop);
}

/*:16*//*17:*/
#line 703 "./luatexdir/dvi/dvigen.w"

void out_cmd(void)
{
if((oval<0x100)&&(oval>=0)){
if((ocmd!=set1)||(oval> 127)){
if((ocmd==fnt1)&&(oval<64))
oval+= fnt_num_0;
else
dvi_out(ocmd);
}
}else{
if((oval<0x10000)&&(oval>=0)){
dvi_out(ocmd+1);
}else{
if((oval<0x1000000)&&(oval>=0)){
dvi_out(ocmd+2);
}else{
dvi_out(ocmd+3);
if(oval>=0){
dvi_out(oval/0x1000000);
}else{
oval+= 0x40000000;
oval+= 0x40000000;
dvi_out((oval/0x1000000)+128);
oval= oval%0x1000000;
}
dvi_out(oval/0x10000);
oval= oval%0x10000;
}
dvi_out(oval/0x10000);
oval= oval%0x10000;
}
dvi_out(oval/0x100);
oval= oval%0x100;
}
dvi_out(oval);
}

void dvi_font_def(internal_font_number f)
{
char*fa;
oval= f-1;
ocmd= fnt_def1;
out_cmd();
dvi_out(font_check_0(f));
dvi_out(font_check_1(f));
dvi_out(font_check_2(f));
dvi_out(font_check_3(f));
dvi_four(font_size(f));
dvi_four(font_dsize(f));
dvi_out(0);
dvi_out(strlen(font_name(f)));

fa= font_name(f);
while(*fa!='\0'){
dvi_out(*fa++);
}
}

/*:17*//*19:*/
#line 820 "./luatexdir/dvi/dvigen.w"

#define location(A) varmem[(A)+1].cint  

halfword down_ptr= null,right_ptr= null;

/*:19*//*20:*/
#line 831 "./luatexdir/dvi/dvigen.w"

void movement(scaled w,eight_bits o)
{
small_number mstate;
halfword p,q;
int k;
if(false){
q= new_node(movement_node,0);
width(q)= w;
location(q)= dvi_offset+dvi_ptr;
if(o==down1){
vlink(q)= down_ptr;
down_ptr= q;
}else{
vlink(q)= right_ptr;
right_ptr= q;
}


p= vlink(q);
mstate= none_seen;
while(p!=null){
if(width(p)==w){





switch(mstate+vinfo(p)){
case none_seen+yz_OK:
case none_seen+y_OK:
case z_seen+yz_OK:
case z_seen+y_OK:
if(location(p)<dvi_gone){
goto NOT_FOUND;
}else{

k= location(p)-dvi_offset;
if(k<0)
k= k+dvi_buf_size;
dvi_buf[k]= (eight_bits)(dvi_buf[k]+y1-down1);
vinfo(p)= y_here;
goto FOUND;
}
break;
case none_seen+z_OK:
case y_seen+yz_OK:
case y_seen+z_OK:
if(location(p)<dvi_gone){
goto NOT_FOUND;
}else{

k= location(p)-dvi_offset;
if(k<0)
k= k+dvi_buf_size;
dvi_buf[k]= (eight_bits)(dvi_buf[k]+z1-down1);
vinfo(p)= z_here;
goto FOUND;
}
break;
case none_seen+y_here:
case none_seen+z_here:
case y_seen+z_here:
case z_seen+y_here:
goto FOUND;
break;
default:
break;
}
}else{
switch(mstate+vinfo(p)){
case none_seen+y_here:
mstate= y_seen;
break;
case none_seen+z_here:
mstate= z_seen;
break;
case y_seen+z_here:
case z_seen+y_here:
goto NOT_FOUND;
break;
default:
break;
}
}
p= vlink(p);
}
}
NOT_FOUND:

if(abs(w)>=040000000){
dvi_out(o+3);
dvi_four(w);
return;
}
if(abs(w)>=0100000){
dvi_out(o+2);
if(w<0)
w= w+0100000000;
dvi_out(w/0200000);
w= w%0200000;
goto TWO;
}
if(abs(w)>=0200){
dvi_out(o+1);
if(w<0)
w= w+0200000;
goto TWO;
}
dvi_out(o);
if(w<0)
w= w+0400;
goto ONE;
TWO:
dvi_out(w/0400);
ONE:
dvi_out(w%0400);
return;
FOUND:









vinfo(q)= vinfo(p);
if(vinfo(q)==y_here){
dvi_out(o+y0-down1);
while(vlink(q)!=p){
q= vlink(q);
switch(vinfo(q)){
case yz_OK:
vinfo(q)= z_OK;
break;
case y_OK:
vinfo(q)= d_fixed;
break;
default:
break;
}
}
}else{
dvi_out(o+z0-down1);
while(vlink(q)!=p){
q= vlink(q);
switch(vinfo(q)){
case yz_OK:
vinfo(q)= y_OK;
break;
case z_OK:
vinfo(q)= d_fixed;
break;
default:
break;
}
}
}
}

/*:20*//*21:*/
#line 1000 "./luatexdir/dvi/dvigen.w"


void prune_movements(int l)
{
pointer p;
while(down_ptr!=null){
if(location(down_ptr)<l)
break;
p= down_ptr;
down_ptr= vlink(p);
flush_node(p);
}
while(right_ptr!=null){
if(location(right_ptr)<l)
return;
p= right_ptr;
right_ptr= vlink(p);
flush_node(p);
}
}

scaledpos dvi;

/*:21*//*23:*/
#line 1038 "./luatexdir/dvi/dvigen.w"

void dvi_place_rule(PDF pdf,halfword q,scaledpos size)
{
synch_dvi_with_pos(pdf->posstruct->pos);
if((subtype(q)>=box_rule)&&(subtype(q)<=user_rule)){

if(textdir_is_L(pdf->posstruct->dir))
dvi.h+= size.h;
}else{

if(textdir_is_L(pdf->posstruct->dir)){
dvi_out(set_rule);
dvi.h+= size.h;
}else
dvi_out(put_rule);
}
dvi_four(size.v);
dvi_four(size.h);
}

void dvi_place_glyph(PDF pdf,internal_font_number f,int c,int ex)
{

scaled_whd ci;
synch_dvi_with_pos(pdf->posstruct->pos);
if(f!=pdf->f_cur){

if(!font_used(f)){
dvi_font_def(f);
set_font_used(f,true);
}
oval= f-1;
ocmd= fnt1;
out_cmd();
pdf->f_cur= f;
}
if(textdir_is_L(pdf->posstruct->dir)){
ci= get_charinfo_whd(f,c);
dvi_set(c,ci.wd);
}else
dvi_put(c);
}

void dvi_special(PDF pdf,halfword p)
{
int old_setting;
unsigned k;
synch_dvi_with_pos(pdf->posstruct->pos);
old_setting= selector;
selector= new_string;
show_token_list(token_link(write_tokens(p)),null,-1);
selector= old_setting;
if(cur_length<256){
dvi_out(xxx1);
dvi_out(cur_length);
}else{
dvi_out(xxx4);
dvi_four((int)cur_length);
}
for(k= 0;k<cur_length;k++)
dvi_out(cur_string[k]);
cur_length= 0;
}

/*:23*//*24:*/
#line 1105 "./luatexdir/dvi/dvigen.w"

void ensure_dvi_header_written(PDF pdf)
{
unsigned l;
unsigned s;
int old_setting;
assert(output_mode_used==OMODE_DVI);
assert(pdf->o_state==ST_FILE_OPEN);

if(half_buf==0){
half_buf= dvi_buf_size/2;
dvi_limit= dvi_buf_size;
}

dvi_out(pre);
dvi_out(id_byte);
dvi_four(25400000);
dvi_four(473628672);
prepare_mag();
dvi_four(mag_par);
if(output_comment){
l= (unsigned)strlen(output_comment);
dvi_out(l);
for(s= 0;s<l;s++)
dvi_out(output_comment[s]);
}else{
old_setting= selector;
selector= new_string;
tprint(" LuaTeX output ");
print_int(year_par);
print_char('.');
print_two(month_par);
print_char('.');
print_two(day_par);
print_char(':');
print_two(time_par/60);
print_two(time_par%60);
selector= old_setting;
dvi_out(cur_length);
for(s= 0;s<cur_length;s++)
dvi_out(cur_string[s]);
cur_length= 0;
}
}

void dvi_begin_page(PDF pdf)
{
int k;
int page_loc;
ensure_output_state(pdf,ST_HEADER_WRITTEN);

page_loc= dvi_offset+dvi_ptr;
dvi_out(bop);
for(k= 0;k<=9;k++)
dvi_four(count(k));
dvi_four(last_bop);
last_bop= page_loc;
}

void dvi_end_page(PDF pdf)
{
(void)pdf;
dvi_out(eop);

#ifdef IPC
if(ipcon> 0){
if(dvi_limit==half_buf){
write_dvi(half_buf,dvi_buf_size-1);
fflush(static_pdf->file);
dvi_gone= dvi_gone+half_buf;
}
if(dvi_ptr> 0){
write_dvi(0,dvi_ptr-1);
fflush(static_pdf->file);
dvi_offset= dvi_offset+dvi_ptr;
dvi_gone= dvi_gone+dvi_ptr;
}
dvi_ptr= 0;
dvi_limit= dvi_buf_size;
ipcpage(dvi_gone);
}
#endif                          
}

/*:24*//*25:*/
#line 1194 "./luatexdir/dvi/dvigen.w"

void finish_dvi_file(PDF pdf,int version,int revision)
{
int k;
int callback_id= callback_defined(stop_run_callback);
(void)version;
(void)revision;
while(cur_s> -1){
if(cur_s> 0){
dvi_out(pop);
}else{
dvi_out(eop);
incr(total_pages);
}
decr(cur_s);
}
if(total_pages==0){
if(callback_id==0){
tprint_nl("No pages of output.");
print_ln();
}else if(callback_id> 0){
run_callback(callback_id,"->");
}
}else{
dvi_out(post);
dvi_four(last_bop);
last_bop= dvi_offset+dvi_ptr-5;
dvi_four(25400000);
dvi_four(473628672);
prepare_mag();
dvi_four(mag_par);
dvi_four(max_v);
dvi_four(max_h);
dvi_out(max_push/256);
dvi_out(max_push%256);
dvi_out((total_pages/256)%256);
dvi_out(total_pages%256);

k= max_font_id();
while(k> 0){
if(font_used(k)){
dvi_font_def(k);
}
decr(k);
}

dvi_out(post_post);
dvi_four(last_bop);
dvi_out(id_byte);
#ifndef IPC
k= 4+((dvi_buf_size-dvi_ptr)%4);
#else
k= 7-((3+dvi_offset+dvi_ptr)%4);
#endif

while(k> 0){
dvi_out(223);
decr(k);
}



if(dvi_limit==half_buf)
write_dvi(half_buf,dvi_buf_size-1);
if(dvi_ptr> 0)
write_dvi(0,dvi_ptr-1);

if(callback_id==0){
tprint_nl("Output written on ");
tprint(pdf->file_name);
tprint(" (");
print_int(total_pages);
tprint(" page");
if(total_pages!=1)
print_char('s');
tprint(", ");
print_int(dvi_offset+dvi_ptr);
tprint(" bytes).");
}else if(callback_id> 0){
run_callback(callback_id,"->");
}
close_file(pdf->file);
}
}/*:25*/
