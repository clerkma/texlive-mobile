/*1:*/
#line 20 "./luatexdir/font/tfmofm.w"



#include "ptexlib.h"

/*:1*//*2:*/
#line 26 "./luatexdir/font/tfmofm.w"

#define lig_kern_start(f,c)   char_remainder(f,c)
#define stop_flag 128           
#define kern_flag 128           

#define skip_byte(z)         lig_kerns[z].b0
#define next_char(z)         lig_kerns[z].b1
#define op_byte(z)           lig_kerns[z].b2
#define rem_byte(z)          lig_kerns[z].b3
#define lig_kern_restart(c)  (256*op_byte(c)+rem_byte(c))


/*:2*//*10:*/
#line 354 "./luatexdir/font/tfmofm.w"

#define tfm_abort { font_tables[f]->_font_name =  NULL;      \
                    font_tables[f]->_font_area =  NULL;      \
                    xfree(tfm_buffer); xfree(kerns);      \
        xfree(widths);  xfree(heights);  xfree(depths);     \
        xfree(italics);  xfree(extens);  xfree(lig_kerns);  \
        xfree(xligs);  xfree(xkerns);           \
      return 0; }

#define tfm_success { xfree(tfm_buffer); xfree(kerns);       \
                xfree(widths);  xfree(heights);  xfree(depths);    \
          xfree(italics);  xfree(extens);  xfree(lig_kerns); \
          xfree(xligs);  xfree(xkerns); return 1; }

/*:10*//*11:*/
#line 368 "./luatexdir/font/tfmofm.w"

static int open_tfm_file(const char*nom,unsigned char**tfm_buf,int*tfm_siz)
{
boolean res;
boolean opened;
int callback_id;
FILE*tfm_file;
char*fname= luatex_find_file(nom,find_font_file_callback);
if(!fname)
return-1;
callback_id= callback_defined(read_font_file_callback);
if(callback_id> 0){
res= 
run_callback(callback_id,"S->bSd",fname,&opened,tfm_buf,
tfm_siz);
if(res&&opened&&(*tfm_siz> 0)){
return 1;
}
if(!opened)
return-1;
}else{
if(luatex_open_input
(&(tfm_file),fname,kpse_ofm_format,FOPEN_RBIN_MODE,true)){
res= read_tfm_file(tfm_file,tfm_buf,tfm_siz);
close_file(tfm_file);
if(res){
return 1;
}
}else{
return-1;
}
}
return 0;
}


/*:11*//*12:*/
#line 412 "./luatexdir/font/tfmofm.w"


#define fget  tfm_byte++
#define fbyte tfm_buffer[tfm_byte]

#define read_sixteen(a)                                                 \
  { a= tfm_buffer[tfm_byte++];                                           \
    if (a> 127) { tfm_abort; }                                               \
    a= (a*256)+tfm_buffer[tfm_byte]; }

#define read_sixteen_unsigned(a)                                        \
  { a= tfm_buffer[tfm_byte++];                                           \
    a= (a*256)+tfm_buffer[tfm_byte]; }

#define read_thirtytwo(a)                                               \
  { a= tfm_buffer[++tfm_byte];                                           \
    if (a> 127) { tfm_abort; }                                               \
    a= (a*256)+tfm_buffer[++tfm_byte];                                   \
    a= (a*256)+tfm_buffer[++tfm_byte];                                   \
    a= (a*256)+tfm_buffer[++tfm_byte]; }

#define store_four_bytes(z)                                             \
  { a= tfm_buffer[++tfm_byte];           \
    a= (a*256)+tfm_buffer[++tfm_byte];         \
    a= (a*256)+tfm_buffer[++tfm_byte];         \
    a= (a*256)+tfm_buffer[++tfm_byte];         \
    z =  a; }

#define store_char_info(z)                                              \
  { if (font_level!=-1) {                                               \
      fget; read_sixteen_unsigned(a);         \
      ci._width_index= a;            \
      fget; read_sixteen_unsigned(b);         \
      ci._height_index= b>>8;            \
      ci._depth_index= b%256;            \
      fget; read_sixteen_unsigned(c);         \
      ci._italic_index= c>>8;            \
      ci._tag= (unsigned char)(c%4);       \
      fget; read_sixteen_unsigned(d);         \
      ci._remainder= d;              \
    } else {                                                            \
      a= tfm_buffer[++tfm_byte];           \
      ci._width_index= a;            \
      b= tfm_buffer[++tfm_byte];           \
      ci._height_index= b>>4;            \
      ci._depth_index= b%16;           \
      c= tfm_buffer[++tfm_byte];           \
      ci._italic_index= c>>2;            \
      ci._tag= (unsigned char)(c%4);   \
      d= tfm_buffer[++tfm_byte];           \
      ci._remainder= d;              \
    } }

#define read_four_quarters(q)           \
  { if (font_level!=-1) {                                        \
      fget; read_sixteen_unsigned(a); q.b0= (quarterword)a;  \
      fget; read_sixteen_unsigned(b); q.b1= (quarterword)b;       \
      fget; read_sixteen_unsigned(c); q.b2= (quarterword)c;       \
      fget; read_sixteen_unsigned(d); q.b3= (quarterword)d;       \
      } else {        \
      a= tfm_buffer[++tfm_byte]; q.b0= (quarterword)a;         \
      b= tfm_buffer[++tfm_byte]; q.b1= (quarterword)b;         \
      c= tfm_buffer[++tfm_byte]; q.b2= (quarterword)c;         \
      d= tfm_buffer[++tfm_byte]; q.b3= (quarterword)d;      \
    } }

#define check_byte_range(z)  { if ((z<bc)||(z> ec)) tfm_abort ; }


/*:12*//*13:*/
#line 499 "./luatexdir/font/tfmofm.w"

#define store_scaled(zz)                                                   \
  { fget; a= fbyte; fget; b= fbyte;                                          \
    fget; c= fbyte; fget; d= fbyte;                                          \
    sw= (((((d*z)>>8)+(c*z))>>8)+(b*z)) / beta;                             \
    if (a==0) { zz= sw; } else if (a==255) { zz= sw-alpha; } else tfm_abort; \
  }

scaled store_scaled_f(scaled sq,scaled z_in)
{
eight_bits a,b,c,d;
scaled sw;
static int alpha,beta;
static scaled z,z_prev= 0;

if(z_in!=z_prev||z_prev==0){
z= z_prev= z_in;
alpha= 16;
while(z>=0x800000){
z/= 2;
alpha+= alpha;
}
beta= 256/alpha;
alpha*= z;
};
if(sq>=0){
d= (eight_bits)(sq%256);
sq= sq/256;
c= (eight_bits)(sq%256);
sq= sq/256;
b= (eight_bits)(sq%256);
sq= sq/256;
a= (eight_bits)(sq%256);
}else{
sq= (sq+1073741824)+1073741824;
d= (eight_bits)(sq%256);
sq= sq/256;
c= (eight_bits)(sq%256);
sq= sq/256;
b= (eight_bits)(sq%256);
sq= sq/256;
a= (eight_bits)((sq+128)%256);
}
if(beta==0)
normal_error("vf","vf scaling");
sw= (((((d*z)>>8)+(c*z))>>8)+(b*z))/beta;
if(a==0)
return sw;
else if(a==255)
return(sw-alpha);
else
normal_error("vf","vf scaling");
return sw;
}

/*:13*//*14:*/
#line 554 "./luatexdir/font/tfmofm.w"

#define  check_existence(z)                                             \
  { check_byte_range(z);                                                \
    if (!char_exists(f,z)) tfm_abort;         \
  }

typedef struct tfmcharacterinfo{
int _kern_index;
int _lig_index;
int _width_index;
int _height_index;
int _depth_index;
int _italic_index;
int _remainder;
unsigned char _tag;
}tfmcharacterinfo;

/*:14*//*15:*/
#line 571 "./luatexdir/font/tfmofm.w"

int read_tfm_info(internal_font_number f,const char*cnom,scaled s)
{
int k;
halfword lf,lh,bc,ec,nw,nh,nd,ni,nl,nk,ne,np,slh;
scaled*widths,*heights,*depths,*italics,*kerns;
halfword font_dir;
int a,b,c= 0,d= 0;
int i;
int font_level,header_length;
int ncw,nlw,neew;
tfmcharacterinfo ci;
charinfo*co;
four_quarters qw;
four_quarters*lig_kerns,*extens;
scaled sw;
int bch_label;
int bchar;
int first_two;
scaled z;
int alpha;
char beta;
int*xligs,*xkerns;
liginfo*cligs;
kerninfo*ckerns;
int fligs,fkerns;
char*tmpnam;
int tfm_byte= 0;
int saved_tfm_byte= 0;
unsigned char*tfm_buffer= NULL;
int tfm_size= 0;
int tmp;

widths= NULL;
heights= NULL;
depths= NULL;
italics= NULL;
kerns= NULL;
lig_kerns= NULL;
extens= NULL;
xkerns= NULL;
ckerns= NULL;
xligs= NULL;
cligs= NULL;

font_dir= 0;

memset(&ci,0,sizeof(tfmcharacterinfo));

if(open_tfm_file(cnom,&tfm_buffer,&tfm_size)!=1)
tfm_abort;



tmpnam= strdup(xbasename(cnom));
if(strcmp(tmpnam+strlen(tmpnam)-4,".tfm")==0||strcmp(tmpnam+strlen(tmpnam)-4,".ofm")==0){
*(tmpnam+strlen(tmpnam)-4)= 0;
}
set_font_name(f,tmpnam);
set_font_area(f,NULL);


ncw= 0;
read_sixteen(first_two);
if(first_two!=0){
font_level= -1;
lf= first_two;
fget;
read_sixteen(lh);
fget;
read_sixteen(bc);
fget;
read_sixteen(ec);
if((bc> ec+1)||(ec> 255))
tfm_abort;
if(bc> 255){
bc= 1;
ec= 0;
};
fget;
read_sixteen(nw);
fget;
read_sixteen(nh);
fget;
read_sixteen(nd);
fget;
read_sixteen(ni);
fget;
read_sixteen(nl);
fget;
read_sixteen(nk);
fget;
read_sixteen(ne);
fget;
read_sixteen(np);
header_length= 6;
ncw= (ec-bc+1);
nlw= nl;
neew= ne;
}else{
fget;
read_sixteen(font_level);
if(font_level!=0)
tfm_abort;
read_thirtytwo(lf);
read_thirtytwo(lh);
read_thirtytwo(bc);
read_thirtytwo(ec);
if((bc> ec+1)||(ec> 65535))
tfm_abort;
if(bc> 65535){
bc= 1;
ec= 0;
};
read_thirtytwo(nw);
read_thirtytwo(nh);
read_thirtytwo(nd);
read_thirtytwo(ni);
read_thirtytwo(nl);
read_thirtytwo(nk);
read_thirtytwo(ne);
read_thirtytwo(np);
read_thirtytwo(font_dir);
nlw= 2*nl;
neew= 2*ne;
header_length= 14;
ncw= 2*(ec-bc+1);
};
if(lf!=
(header_length+lh+ncw+nw+nh+nd+ni+nlw+nk+neew+np))
tfm_abort;
if((nw==0)||(nh==0)||(nd==0)||(ni==0))
tfm_abort;





if(lf*4> tfm_size)
tfm_abort;



set_font_natural_dir(f,font_dir);
set_font_bc(f,bc);
set_font_ec(f,ec);


widths= xmalloc((unsigned)((unsigned)nw*sizeof(scaled)));
heights= xmalloc((unsigned)((unsigned)nh*sizeof(scaled)));
depths= xmalloc((unsigned)((unsigned)nd*sizeof(scaled)));
italics= xmalloc((unsigned)((unsigned)ni*sizeof(scaled)));
extens= xmalloc((unsigned)((unsigned)ne*sizeof(four_quarters)));
lig_kerns= xmalloc((unsigned)((unsigned)nl*sizeof(four_quarters)));
kerns= xmalloc((unsigned)((unsigned)nk*sizeof(scaled)));




slh= lh;
if(lh<2)
tfm_abort;
store_four_bytes(tmp);
font_checksum(f)= (unsigned)tmp;
fget;
read_sixteen(z);
fget;
z= z*256+fbyte;
fget;
z= (z*16)+(fbyte>>4);
if(z<unity)
tfm_abort;
while(lh> 2){
fget;
fget;
fget;
fget;
lh--;
};



set_font_dsize(f,z);
if(s!=-1000){
z= (s>=0?s:xn_over_d(z,-s,1000));
}
set_font_size(f,z);

if(np> 7)
set_font_params(f,np);

saved_tfm_byte= tfm_byte;
tfm_byte= (header_length+slh+ncw)*4-1;



alpha= 16;
while(z>=040000000){
z= z>>1;
alpha= alpha+alpha;
};
beta= (char)(256/alpha);


if(beta==0)
normal_error("vf","vf reading");
alpha= alpha*z;



for(k= 0;k<nw;k++){
store_scaled(sw);
widths[k]= sw;
}
if(widths[0]!=0)
tfm_abort;
for(k= 0;k<nh;k++){
store_scaled(sw);
heights[k]= sw;
}
if(heights[0]!=0)
tfm_abort;
for(k= 0;k<nd;k++){
store_scaled(sw);
depths[k]= sw;
}
if(depths[0]!=0)
tfm_abort;
for(k= 0;k<ni;k++){
store_scaled(sw);
italics[k]= sw;
}
if(italics[0]!=0)
tfm_abort;




bch_label= nl;
bchar= 65536;
if(nl> 0){
for(k= 0;k<nl;k++){
read_four_quarters(qw);
lig_kerns[k]= qw;
if(a> 128){
if(256*c+d>=nl)
tfm_abort;
if(a==255&&k==0)
bchar= b;
}else{
#if 0
if(b!=bchar)check_existence(b);
#endif
if(c<128){
#if 0
check_existence(d);
#endif
}else if(256*(c-128)+d>=nk){
tfm_abort;
}
if((a<128)&&(k-0+a+1>=nl))
tfm_abort;
};
};
if(a==255)
bch_label= 256*c+d;
};


for(k= 0;k<nk;k++){
store_scaled(sw);
kerns[k]= sw;
}


for(k= 0;k<ne;k++){
read_four_quarters(qw);
extens[k]= qw;
}



if(np> 7){
set_font_params(f,np);
}
for(k= 1;k<=np;k++){
if(k==1){
fget;
sw= fbyte;
if(sw> 127)
sw= sw-256;
fget;
sw= sw*256+fbyte;
fget;
sw= sw*256+fbyte;
fget;
sw= (sw*16)+(fbyte>>4);
set_font_param(f,k,sw);
}else{
store_scaled(font_param(f,k));
}
}

tfm_byte= saved_tfm_byte;


fligs= 0;
fkerns= 0;
if(bch_label!=nl){
k= bch_label;
#if 0
if(skip_byte(k)> stop_flag)
k= lig_kern_restart(k);
#endif
while(1){
if(skip_byte(k)<=stop_flag){
if(op_byte(k)>=kern_flag){
fkerns++;
}else{
fligs++;
}
}
if(skip_byte(k)==0){
k++;
}else{
if(skip_byte(k)>=stop_flag)
break;
k+= skip_byte(k)+1;
}
}
}
if(fkerns> 0||fligs> 0){
if(fligs> 0)
cligs= xcalloc((unsigned)(fligs+1),sizeof(liginfo));
if(fkerns> 0)
ckerns= xcalloc((unsigned)(fkerns+1),sizeof(kerninfo));
fligs= 0;
fkerns= 0;
k= bch_label;
#if 0
if(skip_byte(k)> stop_flag)
k= lig_kern_restart(k);
#endif
while(1){
if(skip_byte(k)<=stop_flag){
if(op_byte(k)>=kern_flag){
set_kern_item(ckerns[fkerns],next_char(k),
kerns[256*(op_byte(k)-128)+
rem_byte(k)]);
fkerns++;
}else{
set_ligature_item(cligs[fligs],(char)(op_byte(k)*2+1),
next_char(k),rem_byte(k));
fligs++;
}
}
if(skip_byte(k)==0){
k++;
}else{
if(skip_byte(k)>=stop_flag)
break;
k+= skip_byte(k)+1;
}
}
if(fkerns> 0||fligs> 0){
co= get_charinfo(f,left_boundarychar);
if(fkerns> 0){
set_kern_item(ckerns[fkerns],end_kern,0);
fkerns++;
set_charinfo_kerns(co,ckerns);
}
if(fligs> 0){
set_ligature_item(cligs[fligs],0,end_ligature,0);
fligs++;
set_charinfo_ligatures(co,cligs);
}
set_charinfo_remainder(co,0);
}
}


for(k= bc;k<=ec;k++){
store_char_info(k);
if(ci._width_index==0)
continue;
if(ci._width_index>=nw||ci._height_index>=nh||
ci._depth_index>=nd||ci._italic_index>=ni)
tfm_abort;
d= ci._remainder;
switch(ci._tag){
case lig_tag:
if(d>=nl)
tfm_abort;
break;
case ext_tag:
if(d>=ne)
tfm_abort;
break;
case list_tag:





check_byte_range(d);
while(d<k){
if(char_tag(f,d)!=list_tag)
goto NOT_FOUND;
d= char_remainder(f,d);
};
if(d==k)
tfm_abort;
NOT_FOUND:
break;
}

co= get_charinfo(f,k);
set_charinfo_index(co,k);
set_charinfo_tag(co,ci._tag);
if(ci._tag==ext_tag){
set_charinfo_extensible(co,extens[ci._remainder].b0,
extens[ci._remainder].b2,
extens[ci._remainder].b1,
extens[ci._remainder].b3);
set_charinfo_remainder(co,0);
}else{
set_charinfo_remainder(co,ci._remainder);
}
set_charinfo_width(co,widths[ci._width_index]);
set_charinfo_height(co,heights[ci._height_index]);
set_charinfo_depth(co,depths[ci._depth_index]);
set_charinfo_italic(co,italics[ci._italic_index]);
};



xligs= xcalloc((unsigned)(ec+1),sizeof(int));
xkerns= xcalloc((unsigned)(ec+1),sizeof(int));

for(i= bc;i<=ec;i++){
if(char_tag(f,i)==lig_tag){
k= lig_kern_start(f,i);
if(skip_byte(k)> stop_flag)
k= lig_kern_restart(k);

while(1){
if(skip_byte(k)<=stop_flag){
if(op_byte(k)>=kern_flag){
xkerns[i]++;
if(next_char(k)==bchar)
xkerns[i]++;
}else{
xligs[i]++;
if(next_char(k)==bchar)
xligs[i]++;
}
}
if(skip_byte(k)==0){
k++;
}else{
if(skip_byte(k)>=stop_flag)
break;
k+= skip_byte(k)+1;
}
}
}
}

cligs= NULL;
ckerns= NULL;

for(i= bc;i<=ec;i++){
fligs= 0;
fkerns= 0;
if(char_tag(f,i)==lig_tag){
k= lig_kern_start(f,i);
if(skip_byte(k)> stop_flag)
k= lig_kern_restart(k);

if(xligs[i]> 0)
cligs= xcalloc((unsigned)(xligs[i]+1),sizeof(liginfo));
if(xkerns[i]> 0)
ckerns= xcalloc((unsigned)(xkerns[i]+1),sizeof(kerninfo));
while(1){
if(skip_byte(k)<=stop_flag){
if(op_byte(k)>=kern_flag){
if(next_char(k)==bchar){
set_kern_item(ckerns[fkerns],right_boundarychar,
kerns[256*(op_byte(k)-128)+
rem_byte(k)]);
fkerns++;
}
set_kern_item(ckerns[fkerns],next_char(k),
kerns[256*(op_byte(k)-128)+
rem_byte(k)]);
fkerns++;
}else{
if(next_char(k)==bchar){
set_ligature_item(cligs[fligs],
(char)(op_byte(k)*2+1),
right_boundarychar,rem_byte(k));
fligs++;
}
set_ligature_item(cligs[fligs],
(char)(op_byte(k)*2+1),
next_char(k),rem_byte(k));
fligs++;
}
}
if(skip_byte(k)==0){
k++;
}else{
if(skip_byte(k)>=stop_flag)
break;
k+= skip_byte(k)+1;
}
}
if(fkerns> 0||fligs> 0){
co= get_charinfo(f,i);
if(fkerns> 0){
set_kern_item(ckerns[fkerns],end_kern,0);
fkerns++;
set_charinfo_kerns(co,ckerns);
}
if(fligs> 0){
set_ligature_item(cligs[fligs],0,end_ligature,0);
fligs++;
set_charinfo_ligatures(co,cligs);
}
set_charinfo_remainder(co,0);
}
}
}









if(bchar!=65536){
co= copy_charinfo(char_info(f,bchar));
set_right_boundary(f,co);
}

tfm_success;
}/*:15*/
