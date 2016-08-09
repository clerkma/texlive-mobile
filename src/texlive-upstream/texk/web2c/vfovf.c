/*1:*/
#line 21 "./luatexdir/font/vfovf.w"



#include "ptexlib.h"

/*:1*//*2:*/
#line 26 "./luatexdir/font/vfovf.w"


#define font_max 5000

#define set_char_0 0            
#define set1 128                
#define set2 129                
#define set3 130                
#define set4 131                
#define set_rule 132            
#define put1  133               
#define put2  134               
#define put3  135               
#define put4  136               
#define put_rule 137            
#define nop 138                 
#define bop 139                 
#define eop 140                 
#define push 141                
#define pop 142                 
#define right1  143             
#define right2  144             
#define right3  145             
#define right4  146             
#define w0 147                  
#define w1 148                  
#define w2 149                  
#define w3 150                  
#define w4 151                  
#define x0 152                  
#define x1 153                  
#define x2 154                  
#define x3 155                  
#define x4 156                  
#define down1 157               
#define down2 158               
#define down3 159               
#define down4 160               
#define y0 161                  
#define y1 162                  
#define y2 163                  
#define y3 164                  
#define y4 165                  
#define z0 166                  
#define z1 167                  
#define z2 168                  
#define z3 169                  
#define z4 170                  
#define fnt_num_0 171           
#define fnt1 235                
#define fnt2 236                
#define fnt3 237                
#define fnt4 238                
#define xxx1 239                
#define xxx2 240                
#define xxx3 241                
#define xxx4 242                
#define fnt_def1 243            
#define pre 247                 
#define post 248                
#define post_post 249           
#define yyy1 250                
#define yyy2 251                
#define yyy3 252                
#define yyy4 253                

#define null_font 0

#define long_char 242           
#define vf_id 202               

/*:2*//*3:*/
#line 98 "./luatexdir/font/vfovf.w"

#define bad_vf(a) { \
    xfree(vf_buffer); \
    print_nlp(); \
    formatted_warning("virtual font","file '%s', %s, font will be ignored",font_name(f),a); \
    print_ln(); \
    return; \
}

#define lua_bad_vf(a) { \
    xfree(vf_buffer); \
    lua_settop(L,s_top); \
    lua_pushnil(L); \
    lua_pushstring(L,a); \
    return 2; \
}

#define tmp_b0  tmp_w.qqqq.b0
#define tmp_b1  tmp_w.qqqq.b1
#define tmp_b2  tmp_w.qqqq.b2
#define tmp_b3  tmp_w.qqqq.b3
#define tmp_int tmp_w.cint

#define vf_stack_size 100       

/*:3*//*4:*/
#line 123 "./luatexdir/font/vfovf.w"

typedef unsigned char vf_stack_index;

typedef struct vf_stack_record{
scaled stack_w,stack_x,stack_y,stack_z;
}vf_stack_record;

/*:4*//*5:*/
#line 131 "./luatexdir/font/vfovf.w"

#define vf_byte(a)                                     \
{                                                      \
  eight_bits vf_tmp_b;                       \
    if (vf_cur >= vf_size) {                           \
        normal_error("virtual font","unexpected eof"); \
    }                                                  \
    vf_tmp_b =  vf_buffer[vf_cur++];                    \
    a =  vf_tmp_b;                                      \
}

/*:5*//*6:*/
#line 142 "./luatexdir/font/vfovf.w"

#define vf_replace_z()                           \
{                                                \
    vf_alpha =  16;                               \
    while (vf_z >= 040000000) {                  \
        vf_z =  vf_z / 2;                         \
        vf_alpha +=  vf_alpha;                    \
    }                                            \
      \
    vf_alpha =  (vf_alpha * vf_z);   \
}


/*:6*//*7:*/
#line 157 "./luatexdir/font/vfovf.w"

#define vf_read(k, l)                            \
{                                                \
    int itmp =  0, dtmp =  (int)(k), jtmp =  0;  \
    while (dtmp >  0) {                           \
        vf_byte(jtmp);                           \
        if ((dtmp == (int) k) && jtmp >  127)     \
            jtmp =  jtmp - 256;                   \
        itmp =  itmp * 256 + jtmp;                \
        decr(dtmp);                              \
    }                                            \
    l =  itmp;                                    \
}

#define vf_read_u(k, l)                          \
{                                                \
    int dtmp =  (int)(k);    \
    unsigned int itmp =  0, jtmp =  0;   \
    while (dtmp-- >  0) {                         \
        vf_byte(jtmp);                           \
        itmp =  itmp * 256 + jtmp;                \
    }                                            \
    l =  itmp;                                    \
}

/*:7*//*8:*/
#line 182 "./luatexdir/font/vfovf.w"

void pdf_check_vf(internal_font_number f)
{
if(font_type(f)==virtual_font_type)
normal_error("font","command cannot be used with virtual font");
}

static void
vf_local_font_warning(internal_font_number f,internal_font_number k,const char*s,int a,int b)
{
print_nlp();
tprint(s);
tprint(" in local font ");
tprint(font_name(k));
tprint(" (");
print_int(b);
tprint(" != ");
print_int(a);
tprint(") in virtual font ");
tprint(font_name(f));
tprint(".vf ignored.");
}


/*:8*//*9:*/
#line 207 "./luatexdir/font/vfovf.w"

int level= 0;

static internal_font_number
vf_def_font(internal_font_number f,unsigned char*vf_buffer,int*vf_cr)
{
internal_font_number k;
str_number s;
char*st;
scaled ds,fs;
four_quarters cs;
memory_word tmp_w;
int junk;
unsigned int checksum;
cs.b0= vf_buffer[(*vf_cr)];
cs.b1= vf_buffer[(*vf_cr)+1];
cs.b2= vf_buffer[(*vf_cr)+2];
cs.b3= vf_buffer[(*vf_cr)+3];
(*vf_cr)+= 4;
checksum= (unsigned)
(cs.b0*256*256*256+cs.b1*256*256+cs.b2*256+cs.b3);
k= vf_buffer[(*vf_cr)];
(*vf_cr)++;
if(k> 127)
k-= 256;
k= k*256+vf_buffer[(*vf_cr)];
(*vf_cr)++;
k= k*256+vf_buffer[(*vf_cr)];
(*vf_cr)++;
k= k*256+vf_buffer[(*vf_cr)];
(*vf_cr)++;

fs= store_scaled_f(k,font_size(f));

k= vf_buffer[(*vf_cr)];
(*vf_cr)++;
if(k> 127)
k-= 256;
k= k*256+vf_buffer[(*vf_cr)];
(*vf_cr)++;
k= k*256+vf_buffer[(*vf_cr)];
(*vf_cr)++;
k= k*256+vf_buffer[(*vf_cr)];
(*vf_cr)++;

ds= k/16;


tmp_b0= vf_buffer[(*vf_cr)];
(*vf_cr)++;
tmp_b1= vf_buffer[(*vf_cr)];
(*vf_cr)++;
while(tmp_b0> 0){
tmp_b0--;
(*vf_cr)++;
}
str_room((unsigned)tmp_b1);
while(tmp_b1> 0){
tmp_b1--;
junk= vf_buffer[(*vf_cr)];
(*vf_cr)++;
append_char(junk);
}
if(level> 5){
normal_warning("vf","quitting at recurse depth > 5");
k= f;
}else if((level> 1)&&(fs> 65536*1024)){
normal_warning("vf","quitting when recursing at size > 65536*1024");
k= f;
}else{
level+= 1;
s= make_string();
st= makecstring(s);
k= tfm_lookup(st,fs);
if(k==null_font)
k= read_font_info(null_cs,st,fs,-1);
free(st);
level-= 1;
if(k!=null_font){
if(checksum!=0&&font_checksum(k)!=0
&&checksum!=font_checksum(k))
vf_local_font_warning(f,k,"checksum mismatch",(int)checksum,(int)font_checksum(k));
if(ds!=font_dsize(k))
vf_local_font_warning(f,k,"design size mismatch",ds,font_dsize(k));
}
}
return k;
}

/*:9*//*10:*/
#line 296 "./luatexdir/font/vfovf.w"

static int open_vf_file(const char*fn,unsigned char**vbuffer,int*vsize)
{
boolean res;
int callback_id;
boolean file_read= false;
FILE*vf_file;
const char*fname= luatex_find_file(fn,find_vf_file_callback);
if(fname==NULL||strlen(fname)==0){

return 0;
}

callback_id= callback_defined(read_vf_file_callback);
if(callback_id> 0){
res= run_callback(callback_id,"S->bSd",fname,
&file_read,vbuffer,vsize);
if(res&&file_read&&(*vsize> 0)){
return 1;
}
if(!file_read)
return 0;
}else{
if(luatex_open_input
(&(vf_file),fname,kpse_ovf_format,FOPEN_RBIN_MODE,false)
||luatex_open_input(&(vf_file),fname,kpse_vf_format,
FOPEN_RBIN_MODE,false)){
res= read_vf_file(vf_file,vbuffer,vsize);
close_file(vf_file);
if(res){
return 1;
}
}else{
return 0;
}
}
return 0;
}



/*:10*//*11:*/
#line 343 "./luatexdir/font/vfovf.w"

#define append_packet(k) vpackets[vf_np++] =  (eight_bits)(k)

/*:11*//*12:*/
#line 349 "./luatexdir/font/vfovf.w"

#define append_fnt_set(k)            \
{                                    \
    assert(k >  0);                   \
    append_packet(packet_font_code); \
    append_four(k);                  \
}

#define append_four(k)                     \
{                                          \
    append_packet((k & 0xFF000000) >> 24); \
    append_packet((k & 0x00FF0000) >> 16); \
    append_packet((k & 0x0000FF00) >> 8);  \
    append_packet((k & 0x000000FF));       \
}

/*:12*//*13:*/
#line 367 "./luatexdir/font/vfovf.w"

#define test_checksum()  { vf_byte(tmp_b0); vf_byte(tmp_b1);    \
    vf_byte(tmp_b2); vf_byte(tmp_b3);         \
    if (((tmp_b0 != 0) || (tmp_b1 != 0) || (tmp_b2 != 0) || (tmp_b3 != 0)) && \
  ((font_check_0(f) != 0) || (font_check_1(f) != 0) ||    \
   (font_check_2(f) != 0) || (font_check_3(f) != 0)) &&   \
  ((tmp_b0 != font_check_0(f)) || (tmp_b1 != font_check_1(f)) ||  \
   (tmp_b2 != font_check_2(f)) || (tmp_b3 != font_check_3(f)))) { \
      print_nlp();              \
      tprint("checksum mismatch in font ");     \
      tprint(font_name(f));         \
      tprint(".vf ignored "); } }

#define test_dsize()                                   \
{                                                      \
    int read_tmp;                                      \
    vf_read(4, read_tmp);                              \
    if ((read_tmp / 16) != font_dsize(f)) {            \
        print_nlp();                                   \
        tprint("design size mismatch in font ");       \
        tprint(font_name(f));          \
        tprint(".vf ignored");          \
    }                                                  \
}

/*:13*//*14:*/
#line 392 "./luatexdir/font/vfovf.w"

static int count_packet_bytes(eight_bits*vf_buf,int cur_bute,int count)
{
unsigned k= 0;
int ff= 0;
int acc= 0;
unsigned int cmd= 0;
unsigned int d= 0;
while(k<(unsigned)count){
cmd= vf_buf[cur_bute+(int)k];
k++;
if(cmd<set1){
if(ff==0){
ff= 1;
acc+= 5;
}
acc+= 5;
}else if((fnt_num_0<=cmd)&&(cmd<=fnt_num_0+63)){
ff= 1;
acc+= 5;
}else{
switch(cmd){
case fnt1:
acc+= 5;
k+= 1;
ff= 1;
break;
case fnt2:
acc+= 5;
k+= 2;
ff= 1;
break;
case fnt3:
acc+= 5;
k+= 3;
ff= 1;
break;
case fnt4:
acc+= 5;
k+= 4;
ff= 1;
break;
case set_rule:
acc+= 9;
k+= 8;
break;
case put_rule:
acc+= 11;
k+= 8;
break;
case set1:
acc+= 5;
k+= 1;
if(ff==0){
ff= 1;
acc+= 5;
}
break;
case set2:
acc+= 5;
k+= 2;
if(ff==0){
ff= 1;
acc+= 5;
}
break;
case set3:
acc+= 5;
k+= 3;
if(ff==0){
ff= 1;
acc+= 5;
}
break;
case set4:
acc+= 5;
k+= 4;
if(ff==0){
ff= 1;
acc+= 5;
}
break;
case put1:
acc+= 7;
k+= 1;
if(ff==0){
ff= 1;
acc+= 5;
}
break;
case put2:
acc+= 7;
k+= 2;
if(ff==0){
ff= 1;
acc+= 5;
}
break;
case put3:
acc+= 7;
k+= 3;
if(ff==0){
ff= 1;
acc+= 5;
}
break;
case put4:
acc+= 7;
k+= 4;
if(ff==0){
ff= 1;
acc+= 5;
}
break;
case right1:
acc+= 5;
k+= 1;
break;
case right2:
acc+= 5;
k+= 2;
break;
case right3:
acc+= 5;
k+= 3;
break;
case right4:
acc+= 5;
k+= 4;
break;
case w1:
acc+= 5;
k+= 1;
break;
case w2:
acc+= 5;
k+= 2;
break;
case w3:
acc+= 5;
k+= 3;
break;
case w4:
acc+= 5;
k+= 4;
break;
case x1:
acc+= 5;
k+= 1;
break;
case x2:
acc+= 5;
k+= 2;
break;
case x3:
acc+= 5;
k+= 3;
break;
case x4:
acc+= 5;
k+= 4;
break;
case down1:
acc+= 5;
k+= 1;
break;
case down2:
acc+= 5;
k+= 2;
break;
case down3:
acc+= 5;
k+= 3;
break;
case down4:
acc+= 5;
k+= 4;
break;
case y1:
acc+= 5;
k+= 1;
break;
case y2:
acc+= 5;
k+= 2;
break;
case y3:
acc+= 5;
k+= 3;
break;
case y4:
acc+= 5;
k+= 4;
break;
case z1:
acc+= 5;
k+= 1;
break;
case z2:
acc+= 5;
k+= 2;
break;
case z3:
acc+= 5;
k+= 3;
break;
case z4:
acc+= 5;
k+= 4;
break;
case xxx1:
d= vf_buf[cur_bute+(int)k];
k++;
k+= d;
acc+= 5+(int)d;
break;
case xxx2:
d= vf_buf[cur_bute+(int)k];
k++;
d= d*256+vf_buf[cur_bute+(int)k];
k++;
k+= d;
acc+= 5+(int)d;
break;
case xxx3:
d= vf_buf[cur_bute+(int)k];
k++;
d= d*256+vf_buf[cur_bute+(int)k];
k++;
d= d*256+vf_buf[cur_bute+(int)k];
k++;
k+= d;
acc+= 5+(int)d;
break;
case xxx4:
d= vf_buf[cur_bute+(int)k];
k++;
d= d*256+vf_buf[cur_bute+(int)k];
k++;
d= d*256+vf_buf[cur_bute+(int)k];
k++;
d= d*256+vf_buf[cur_bute+(int)k];
k++;
k+= d;
acc+= 5+(int)d;
break;
case w0:
acc+= 5;
break;
case x0:
acc+= 5;
break;
case y0:
acc+= 5;
break;
case z0:
acc+= 5;
break;
case nop:
break;
case push:
acc+= 1;
break;
case pop:
acc+= 1;
break;
}
}
}
return(acc+1);
}

/*:14*//*15:*/
#line 664 "./luatexdir/font/vfovf.w"

void do_vf(internal_font_number f)
{
int k,i;
unsigned cmd,n;
scaled x,y,w,z,h,v;
int cc,cmd_length;
unsigned packet_length;
charinfo*co;
scaled tfm_width;
int save_cur_byte;
vf_stack_index stack_level;
int vf_z;
int vf_alpha;

int vf_np;
eight_bits*vpackets;
memory_word tmp_w;
vf_stack_record vf_stack[256];
int junk;
unsigned utmp;
unsigned char*vf_buffer;
int vf_size;
int vf_cur;
unsigned*vf_local_fnts= NULL;
unsigned*vf_real_fnts= NULL;
unsigned vf_nf= 0;

if(font_type(f)!=unknown_font_type)
return;
set_font_type(f,real_font_type);
stack_level= 0;

vf_cur= 0;
vf_buffer= NULL;
vf_size= 0;
if(!open_vf_file(font_name(f),&vf_buffer,&vf_size))
return;

set_font_type(f,virtual_font_type);
vf_byte(k);
if(k!=pre)
bad_vf("PRE command expected");
vf_byte(k);
if(k!=vf_id)
bad_vf("wrong id byte");
vf_byte(cmd_length);
for(k= 1;k<=cmd_length;k++)
vf_byte(junk);
test_checksum();
test_dsize();
vf_z= font_size(f);
vf_replace_z();


vf_nf= 0;
save_cur_byte= vf_cur;
vf_byte(cmd);
while((cmd>=fnt_def1)&&(cmd<=(fnt_def1+3))){
vf_read_u((cmd-fnt_def1+1),utmp);
vf_read(4,junk);
vf_read(4,junk);
vf_read(4,junk);
vf_byte(k);
vf_byte(junk);
k+= junk;
while(k--> 0){
vf_byte(junk);
}
incr(vf_nf);
vf_byte(cmd);
}
vf_cur= save_cur_byte;
vf_byte(cmd);

if(vf_nf> 0){
unsigned ii= (unsigned)((unsigned)vf_nf*sizeof(int));
vf_local_fnts= xmalloc(ii);
memset(vf_local_fnts,0,ii);
vf_real_fnts= xmalloc(ii);
memset(vf_real_fnts,0,ii);
vf_nf= 0;
while((cmd>=fnt_def1)&&(cmd<=(fnt_def1+3))){
vf_read_u((cmd-fnt_def1+1),vf_local_fnts[vf_nf]);
vf_real_fnts[vf_nf]= (unsigned)vf_def_font(f,vf_buffer,&vf_cur);
incr(vf_nf);
vf_byte(cmd);
}
}


while(cmd<=long_char){

vf_np= 0;
if(cmd==long_char){
vf_read_u(4,packet_length);
vf_read_u(4,utmp);
cc= (int)utmp;
if(!char_exists(f,cc)){
bad_vf("invalid character code");
}
vf_read(4,k);
tfm_width= store_scaled_f(k,font_size(f));
}else{
packet_length= cmd;
vf_byte(cc);
if(!char_exists(f,cc)){
bad_vf("invalid character code");
}
vf_read_u(3,utmp);
k= (int)utmp;
tfm_width= store_scaled_f(k,font_size(f));
}


if(tfm_width!=char_width(f,cc)){
if(tfm_width!=char_width(f,cc)){
print_nlp();
tprint("character width mismatch in font ");
tprint(font_name(f));
tprint(".vf ignored");
}
}
k= count_packet_bytes(vf_buffer,vf_cur,(int)packet_length);
vpackets= xmalloc((unsigned)(k+1));
co= get_charinfo(f,cc);
k= 0;
w= 0;
x= 0;
y= 0;
z= 0;
while(packet_length> 0){
vf_byte(cmd);
decr(packet_length);

if(cmd<set1){
if(k==0){
k= (int)vf_real_fnts[0];
append_fnt_set(k);
}
append_packet(packet_char_code);
append_four(cmd);
cmd_length= 0;
cmd= nop;

}else if(((fnt_num_0<=cmd)&&(cmd<=fnt_num_0+63))||
((fnt1<=cmd)&&(cmd<=fnt1+3))){
if(cmd>=fnt1){
vf_read_u((cmd-fnt1+1),utmp);
k= (int)utmp;
packet_length-= (cmd-fnt1+1);
}else{
k= (int)cmd-fnt_num_0;
}


n= 0;
while((n<vf_nf)&&(vf_local_fnts[n]!=(unsigned)k))
n++;
if(n==vf_nf)
bad_vf("undefined local font");

k= (int)vf_real_fnts[n];
append_fnt_set(k);
cmd_length= 0;
cmd= nop;
}else{
switch(cmd){
case set_rule:
vf_read(4,h);
vf_read(4,v);
append_packet(packet_rule_code);
append_four(h);
append_four(v);
packet_length-= 8;
break;
case put_rule:
vf_read(4,h);
vf_read(4,v);
append_packet(packet_push_code);
append_packet(packet_rule_code);
append_four(h);
append_four(v);
append_packet(packet_pop_code);
packet_length-= 8;
break;
case set1:
case set2:
case set3:
case set4:
if(k==0){
k= (int)vf_real_fnts[0];
append_fnt_set(k);
}
vf_read_u((cmd-set1+1),utmp);
i= (int)utmp;
append_packet(packet_char_code);
append_four(i);
packet_length-= (cmd-set1+1);
break;
case put1:
case put2:
case put3:
case put4:
if(k==0){
k= (int)vf_real_fnts[0];
append_fnt_set(k);
}
vf_read_u((cmd-put1+1),utmp);
i= (int)utmp;
append_packet(packet_push_code);
append_packet(packet_char_code);
append_four(i);
append_packet(packet_pop_code);
packet_length-= (cmd-put1+1);
break;
case right1:
case right2:
case right3:
case right4:
vf_read((cmd-right1+1),i);
append_packet(packet_right_code);
append_four(i);
packet_length-= (cmd-right1+1);
break;
case w1:
case w2:
case w3:
case w4:
vf_read((cmd-w1+1),w);
append_packet(packet_right_code);
append_four(w);
packet_length-= (cmd-w1+1);
break;
case x1:
case x2:
case x3:
case x4:
vf_read((cmd-x1+1),x);
append_packet(packet_right_code);
append_four(x);
packet_length-= (cmd-x1+1);
break;
case down1:
case down2:
case down3:
case down4:
vf_read((cmd-down1+1),i);
append_packet(packet_down_code);
append_four(i);
packet_length-= (cmd-down1+1);
break;
case y1:
case y2:
case y3:
case y4:
vf_read((cmd-y1+1),y);
append_packet(packet_down_code);
append_four(y);
packet_length-= (cmd-y1+1);
break;
case z1:
case z2:
case z3:
case z4:
vf_read((cmd-z1+1),z);
append_packet(packet_down_code);
append_four(z);
packet_length-= (cmd-z1+1);
break;
case xxx1:
case xxx2:
case xxx3:
case xxx4:
vf_read_u((cmd-xxx1+1),utmp);
cmd_length= (int)utmp;
packet_length-= (cmd-xxx1+1);
if(cmd_length<=0)
bad_vf("special of negative length");
packet_length-= (unsigned)cmd_length;

append_packet(packet_special_code);
append_four(cmd_length);
while(cmd_length> 0){
cmd_length--;
vf_byte(i);
append_packet(i);
}
break;
case w0:
append_packet(packet_right_code);
append_four(w);
break;
case x0:
append_packet(packet_right_code);
append_four(x);
break;
case y0:
append_packet(packet_down_code);
append_four(y);
break;
case z0:
append_packet(packet_down_code);
append_four(z);
break;
case nop:
break;
case push:
if(stack_level==vf_stack_size){
overflow("virtual font stack size",vf_stack_size);
}else{
vf_stack[stack_level].stack_w= w;
vf_stack[stack_level].stack_x= x;
vf_stack[stack_level].stack_y= y;
vf_stack[stack_level].stack_z= z;
incr(stack_level);
append_packet(packet_push_code);
}
break;
case pop:
if(stack_level==0){
bad_vf("more POPs than PUSHs in character");
}else{
decr(stack_level);
w= vf_stack[stack_level].stack_w;
x= vf_stack[stack_level].stack_x;
y= vf_stack[stack_level].stack_y;
z= vf_stack[stack_level].stack_z;
append_packet(packet_pop_code);
}
break;
default:
bad_vf("improver DVI command");
}
}
}

append_packet(packet_end_code);

if(stack_level!=0)
bad_vf("more PUSHs than POPs in character packet");
if(packet_length!=0)
bad_vf("invalid packet length or DVI command in packet");

set_charinfo_packets(co,vpackets);
vf_byte(cmd);
}
if(cmd!=post)
bad_vf("POST command expected");

xfree(vf_buffer);
}

/*:15*//*16:*/
#line 1017 "./luatexdir/font/vfovf.w"

#define make_command0(N,K) { \
    lua_newtable(L);         \
    lua_pushstring(L, N);    \
    lua_rawseti(L,-2, 1);    \
    lua_rawseti(L,-2, K);    \
    K++; }

#define make_command1(N,V,K) { \
    lua_newtable(L);           \
    lua_pushstring(L, N);      \
    lua_rawseti(L,-2, 1);      \
    lua_pushinteger(L, V);     \
    lua_rawseti(L,-2, 2);      \
    lua_rawseti(L,-2, K);      \
    K++; }

#define make_command2(N,V,W,K) { \
    lua_newtable(L);             \
    lua_pushstring(L, N);        \
    lua_rawseti(L,-2, 1);        \
    lua_pushinteger(L, V);       \
    lua_rawseti(L,-2, 2);        \
    lua_pushinteger(L, W);       \
    lua_rawseti(L,-2, 3);        \
    lua_rawseti(L,-2, K);        \
    K++; }

#define make_commands(N,S,V,K) {    \
    lua_newtable(L);        \
    lua_pushstring(L, N);     \
    lua_rawseti(L,-2, 1);     \
    lua_pushlstring(L, S, V);     \
    lua_rawseti(L,-2, 2);     \
    lua_rawseti(L,-2, K);     \
    K++; }


int make_vf_table(lua_State*L,const char*cnom,scaled atsize)
{
int cmd,k,i;
int cc;
unsigned cmd_length,packet_length;
scaled tfm_width;
vf_stack_index stack_level;
int vf_z;
int vf_alpha;

eight_bits*s;
scaled h,v;
scaled w,x,y,z;
int s_top;
int vf_nf;
scaled ds,fs;
four_quarters cs;
memory_word tmp_w;
vf_stack_record vf_stack[256];
unsigned char*vf_buffer;
int vf_size;
int vf_cur;
unsigned utmp;


stack_level= 0;

vf_cur= 0;
vf_buffer= NULL;
vf_size= 0;
if(!open_vf_file(cnom,&vf_buffer,&vf_size)){
lua_pushnil(L);
return 1;
}


s_top= lua_gettop(L);
lua_newtable(L);


vf_byte(k);
if(k!=pre)
lua_bad_vf("PRE command expected");
vf_byte(k);
if(k!=vf_id)
lua_bad_vf("wrong id byte");
vf_byte(cmd_length);

s= xmalloc(cmd_length);
for(k= 1;k<=(int)cmd_length;k++)
vf_byte(s[(k-1)]);

lua_pushlstring(L,(char*)s,(size_t)cmd_length);
free(s);
lua_setfield(L,-2,"header");

vf_byte(cs.b0);
vf_byte(cs.b1);
vf_byte(cs.b2);
vf_byte(cs.b3);
lua_pushinteger(L,(lua_Number)((cs.b0<<24)+(cs.b1<<16)+(cs.b2<<8)+cs.b3));
lua_setfield(L,-2,"checksum");

vf_read(4,k);
ds= k/16;
lua_pushinteger(L,ds);
lua_setfield(L,-2,"designsize");


lua_pushstring(L,cnom);
lua_setfield(L,-2,"name");

lua_pushinteger(L,atsize);
lua_setfield(L,-2,"size");

vf_z= atsize;
vf_replace_z();

vf_byte(cmd);
lua_newtable(L);

i= 1;
while((cmd>=fnt_def1)&&(cmd<=fnt_def1+3)){

lua_newtable(L);
vf_read_u((cmd-fnt_def1+1),utmp);
vf_nf= (int)utmp;
vf_nf++;

vf_byte(cs.b0);
vf_byte(cs.b1);
vf_byte(cs.b2);
vf_byte(cs.b3);

vf_read(4,k);
fs= store_scaled_f(k,atsize);
lua_pushstring(L,"size");
lua_pushinteger(L,fs);
lua_rawset(L,-3);

vf_read(4,k);
ds= k/16;

vf_byte(tmp_b0);
vf_byte(tmp_b1);
while(tmp_b0> 0){
tmp_b0--;
vf_byte(k);
}

s= xmalloc((unsigned)(tmp_b1+1));
k= 0;
while(tmp_b1--> 0)
vf_byte(s[k++]);
s[k]= 0;
lua_pushstring(L,"name");
lua_pushstring(L,xstrdup((char*)s));
free(s);
lua_rawset(L,-3);

lua_rawseti(L,-2,vf_nf);
i++;
vf_byte(cmd);
}

if(i> 1){
lua_setfield(L,-2,"fonts");
}else{
lua_pop(L,1);
}

lua_newtable(L);
while(cmd<=long_char){

if(cmd==long_char){
vf_read_u(4,packet_length);
vf_read_u(4,utmp);
cc= (int)utmp;
vf_read(4,tfm_width);
}else{
packet_length= (unsigned)cmd;
vf_byte(cc);
vf_read_u(3,utmp);
tfm_width= (int)utmp;
}
lua_newtable(L);
lua_pushinteger(L,tfm_width);
lua_setfield(L,-2,"width");
lua_newtable(L);
k= 1;
vf_nf= 0;
w= 0;
x= 0;
y= 0;
z= 0;
while(packet_length> 0){
vf_byte(cmd);
decr(packet_length);
if((cmd>=set_char_0)&&(cmd<set1)){
if(vf_nf==0){
vf_nf= 1;
make_command1("font",vf_nf,k);
}
make_command1("char",cmd,k);
}else if(((fnt_num_0<=cmd)&&(cmd<=fnt_num_0+63))||
((fnt1<=cmd)&&(cmd<=fnt1+3))){
if(cmd>=fnt1){
vf_read_u((cmd-fnt1+1),utmp);
vf_nf= (int)utmp;
vf_nf++;
packet_length-= (unsigned)(cmd-fnt1+1);
}else{
vf_nf= cmd-fnt_num_0+1;
}
make_command1("font",vf_nf,k);
}else{
switch(cmd){
case set_rule:
vf_read(4,h);
vf_read(4,v);
make_command2("rule",store_scaled_f(h,atsize),
store_scaled_f(v,atsize),k);
packet_length-= 8;
break;
case put_rule:
vf_read(4,h);
vf_read(4,v);
make_command0("push",k);
make_command2("rule",store_scaled_f(h,atsize),
store_scaled_f(v,atsize),k);
make_command0("pop",k);
packet_length-= 8;
break;
case set1:
case set2:
case set3:
case set4:
if(vf_nf==0){
vf_nf= 1;
make_command1("font",vf_nf,k);
}
vf_read_u((cmd-set1+1),utmp);
i= (int)utmp;
make_command1("char",i,k);
packet_length-= (unsigned)(cmd-set1+1);
break;
case put1:
case put2:
case put3:
case put4:
if(vf_nf==0){
vf_nf= 1;
make_command1("font",vf_nf,k);
}
vf_read_u((cmd-put1+1),utmp);
i= (int)utmp;
make_command0("push",k);
make_command1("char",i,k);
make_command0("pop",k);
packet_length-= (unsigned)(cmd-put1+1);
break;
case right1:
case right2:
case right3:
case right4:
vf_read((cmd-right1+1),i);
make_command1("right",store_scaled_f(i,atsize),k);
packet_length-= (unsigned)(cmd-right1+1);
break;
case w1:
case w2:
case w3:
case w4:
vf_read((cmd-w1+1),w);
make_command1("right",store_scaled_f(w,atsize),k);
packet_length-= (unsigned)(cmd-w1+1);
break;
case x1:
case x2:
case x3:
case x4:
vf_read((cmd-x1+1),x);
make_command1("right",store_scaled_f(x,atsize),k);
packet_length-= (unsigned)(cmd-x1+1);
break;
case down1:
case down2:
case down3:
case down4:
vf_read((cmd-down1+1),i);
make_command1("down",store_scaled_f(i,atsize),k);
packet_length-= (unsigned)(cmd-down1+1);
break;
case y1:
case y2:
case y3:
case y4:
vf_read((cmd-y1+1),y);
make_command1("down",store_scaled_f(y,atsize),k);
packet_length-= (unsigned)(cmd-y1+1);
break;
case z1:
case z2:
case z3:
case z4:
vf_read((cmd-z1+1),z);
make_command1("down",store_scaled_f(z,atsize),k);
packet_length-= (unsigned)(cmd-z1+1);
break;
case xxx1:
case xxx2:
case xxx3:
case xxx4:
vf_read_u((cmd-xxx1+1),cmd_length);
packet_length-= (unsigned)(cmd-xxx1+1);
if(cmd_length<=0)
lua_bad_vf("special of negative length");
packet_length-= cmd_length;

s= xmalloc((cmd_length+1));
i= 0;
while(cmd_length> 0){
cmd_length--;
vf_byte(s[i]);
i++;
}
s[i]= 0;
make_commands("special",xstrdup((char*)s),(size_t)i,
k);
free(s);
break;
case w0:
make_command1("right",store_scaled_f(w,atsize),k);
break;
case x0:
make_command1("right",store_scaled_f(x,atsize),k);
break;
case y0:
make_command1("down",store_scaled_f(y,atsize),k);
break;
case z0:
make_command1("down",store_scaled_f(z,atsize),k);
break;
case nop:
break;
case push:
if(stack_level==vf_stack_size){
overflow("virtual font stack size",vf_stack_size);
}else{
vf_stack[stack_level].stack_w= w;
vf_stack[stack_level].stack_x= x;
vf_stack[stack_level].stack_y= y;
vf_stack[stack_level].stack_z= z;
incr(stack_level);
make_command0("push",k);
}
break;
case pop:
if(stack_level==0){
lua_bad_vf("more POPs than PUSHs in character");
}else{
decr(stack_level);
w= vf_stack[stack_level].stack_w;
x= vf_stack[stack_level].stack_x;
y= vf_stack[stack_level].stack_y;
z= vf_stack[stack_level].stack_z;
make_command0("pop",k);
}
break;
default:
lua_bad_vf("improver DVI command");
}
}
}

lua_setfield(L,-2,"commands");

if(stack_level!=0)
lua_bad_vf("more PUSHs than POPs in character packet");
if(packet_length!=0)
lua_bad_vf("invalid packet length or DVI command in packet");

lua_rawseti(L,-2,cc);

vf_byte(cmd);
}
lua_setfield(L,-2,"characters");

if(cmd!=post)
lua_bad_vf("POST command expected");
xfree(vf_buffer);
return 1;
}

/*:16*//*17:*/
#line 1409 "./luatexdir/font/vfovf.w"

internal_font_number
letter_space_font(internal_font_number f,int e,boolean nolig)
{
internal_font_number k;
scaled w;
int c;
charinfo*co;
char*new_font_name;


k= copy_font(f);

if(nolig)
set_no_ligatures(k);


new_font_name= xmalloc((unsigned)(strlen(font_name(k))+8));
if(e> 0){
sprintf(new_font_name,"%s+%ils",font_name(k),(int)e);
}else{

sprintf(new_font_name,"%s%ils",font_name(k),(int)e);
}
set_font_name(k,new_font_name);


set_font_type(k,virtual_font_type);

for(c= font_bc(k);c<=font_ec(k);c++){
if(quick_char_exists(k,c)){
int half_w;
int vf_np= 0;
eight_bits*vpackets= xmalloc((unsigned)(10+10+1));
if(e<0){
half_w= -round_xn_over_d(quad(k),-e,2000);
}else{
half_w= round_xn_over_d(quad(k),e,2000);
}
co= get_charinfo(k,c);
w= char_width(k,c)+2*half_w;
set_charinfo_width(co,w);

append_packet(packet_right_code);
append_four(half_w);
append_fnt_set(f);
append_packet(packet_char_code);
append_four(c);
append_packet(packet_right_code);
append_four(half_w);
append_packet(packet_end_code);

set_charinfo_packets(co,vpackets);
}
}


#if 0
if(e<0){
set_font_param(k,quad_code,-round_xn_over_d(quad(k),1000-e,1000));
}else{
set_font_param(k,quad_code,round_xn_over_d(quad(k),1000+e,1000));
}
#endif
return k;
}

/*:17*//*18:*/
#line 1476 "./luatexdir/font/vfovf.w"

internal_font_number copy_font_info(internal_font_number f)
{
return copy_font(f);
}/*:18*/
