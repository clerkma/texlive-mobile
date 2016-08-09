/*1:*/
#line 21 "./luatexdir/image/writejpg.w"


#include "ptexlib.h"
#include <assert.h> 
#include "image/image.h"
#include "image/writejpg.h"

/*:1*//*2:*/
#line 28 "./luatexdir/image/writejpg.w"

#define JPG_GRAY  1  
#define JPG_RGB   3  
#define JPG_CMYK  4  

typedef enum{
M_SOF0= 0xc0,
M_SOF1= 0xc1,
M_SOF2= 0xc2,
M_SOF3= 0xc3,

M_SOF5= 0xc5,
M_SOF6= 0xc6,
M_SOF7= 0xc7,

M_JPG= 0xc8,
M_SOF9= 0xc9,
M_SOF10= 0xca,
M_SOF11= 0xcb,

M_SOF13= 0xcd,
M_SOF14= 0xce,
M_SOF15= 0xcf,

M_DHT= 0xc4,

M_DAC= 0xcc,

M_RST0= 0xd0,
M_RST1= 0xd1,
M_RST2= 0xd2,
M_RST3= 0xd3,
M_RST4= 0xd4,
M_RST5= 0xd5,
M_RST6= 0xd6,
M_RST7= 0xd7,

M_SOI= 0xd8,
M_EOI= 0xd9,
M_SOS= 0xda,
M_DQT= 0xdb,
M_DNL= 0xdc,
M_DRI= 0xdd,
M_DHP= 0xde,
M_EXP= 0xdf,

M_APP0= 0xe0,
M_APP1= 0xe1,
M_APP2= 0xe2,
M_APP3= 0xe3,
M_APP4= 0xe4,
M_APP5= 0xe5,
M_APP6= 0xe6,
M_APP7= 0xe7,
M_APP8= 0xe8,
M_APP9= 0xe9,
M_APP10= 0xea,
M_APP11= 0xeb,
M_APP12= 0xec,
M_APP13= 0xed,
M_APP14= 0xee,
M_APP15= 0xef,

M_JPG0= 0xf0,
M_JPG13= 0xfd,
M_COM= 0xfe,

M_TEM= 0x01,

M_ERROR= 0x100
}JPEG_MARKER;

/*:2*//*3:*/
#line 100 "./luatexdir/image/writejpg.w"

static unsigned char myget_unsigned_byte(FILE*file)
{
int ch;
ch= fgetc(file);
return(unsigned char)ch;
}

/*:3*//*4:*/
#line 108 "./luatexdir/image/writejpg.w"

static unsigned short myget_unsigned_pair(FILE*file)
{
unsigned short pair= myget_unsigned_byte(file);
pair= (pair<<8)|myget_unsigned_byte(file);
return pair;
}

/*:4*//*5:*/
#line 116 "./luatexdir/image/writejpg.w"

static unsigned int read_exif_bytes(unsigned char**p,int n,int b)
{
unsigned int rval= 0;
unsigned char*pp= *p;
if(b){
switch(n){
case 4:
rval+= *pp++;rval<<= 8;
rval+= *pp++;rval<<= 8;
case 2:
rval+= *pp++;rval<<= 8;
rval+= *pp;
break;
}
}else{
pp+= n;
switch(n){
case 4:
rval+= *--pp;rval<<= 8;
rval+= *--pp;rval<<= 8;
case 2:
rval+= *--pp;rval<<= 8;
rval+= *--pp;
break;
}
}
*p+= n;
return rval;
}

/*:5*//*6:*/
#line 147 "./luatexdir/image/writejpg.w"

static void read_APP1_Exif(FILE*fp,unsigned short length,int*xx,int*yy)
{


unsigned char*buffer= (unsigned char*)xmalloc(length);
unsigned char*p,*rp;
unsigned char*tiff_header;
char bigendian;
int i;
int num_fields,tag,type;
int value= 0,num= 0,den= 0;
double xres= 72.0;
double yres= 72.0;
double res_unit= 1.0;
size_t ret_len;
ret_len= fread(buffer,length,1,fp);
if(ret_len!=1)
goto err;
p= buffer;
while((p<buffer+length)&&(*p==0))
++p;
tiff_header= p;
if((*p=='M')&&(*(p+1)=='M'))
bigendian= 1;
else if((*p=='I')&&(*(p+1)=='I'))
bigendian= 0;
else
goto err;
p+= 2;
i= read_exif_bytes(&p,2,bigendian);
if(i!=42)
goto err;
i= read_exif_bytes(&p,4,bigendian);
p= tiff_header+i;
num_fields= read_exif_bytes(&p,2,bigendian);
while(num_fields--> 0){
tag= read_exif_bytes(&p,2,bigendian);
type= read_exif_bytes(&p,2,bigendian);
read_exif_bytes(&p,4,bigendian);
switch(type){
case 1:
value= *p++;
p+= 3;
break;
case 3:
value= read_exif_bytes(&p,2,bigendian);
p+= 2;
break;
case 4:
case 9:
value= read_exif_bytes(&p,4,bigendian);
break;
case 5:
case 10:
value= read_exif_bytes(&p,4,bigendian);
rp= tiff_header+value;
num= read_exif_bytes(&rp,4,bigendian);
den= read_exif_bytes(&rp,4,bigendian);
break;
case 7:
value= *p++;
p+= 3;
break;
case 2:
default:
p+= 4;
break;
}
switch(tag){
case 282:
if(den!=0)
xres= num/den;
break;
case 283:
if(den!=0)
yres= num/den;
break;
case 296:
switch(value){
case 2:
res_unit= 1.0;
break;
case 3:
res_unit= 2.54;
break;
}
}
}

*xx= (int)(xres*res_unit);
*yy= (int)(yres*res_unit);
err:
free(buffer);
return;
}









/*:6*//*7:*/
#line 252 "./luatexdir/image/writejpg.w"

static void close_and_cleanup_jpg(image_dict*idict)
{

if(img_file(idict)!=NULL){
xfclose(img_file(idict),img_filepath(idict));
img_file(idict)= NULL;
}
if(img_jpg_ptr(idict)!=NULL){
xfree(img_jpg_ptr(idict));
}
}

/*:7*//*8:*/
#line 265 "./luatexdir/image/writejpg.w"

void flush_jpg_info(image_dict*idict)
{
close_and_cleanup_jpg(idict);
}

/*:8*//*9:*/
#line 271 "./luatexdir/image/writejpg.w"

void read_jpg_info(image_dict*idict)
{
int i,units= 0;
unsigned short appmk,length;
unsigned char jpg_id[]= "JFIF";
if(img_type(idict)!=IMG_TYPE_JPG){
normal_error("readjpg","conflicting image dictionary");
}
if(img_file(idict)!=NULL){
normal_error("readjpg","image data already read");
}
img_totalpages(idict)= 1;
img_pagenum(idict)= 1;
img_xres(idict)= img_yres(idict)= 0;
img_file(idict)= xfopen(img_filepath(idict),FOPEN_RBIN_MODE);
if(img_file(idict)==NULL){
normal_error("readjpg","unable to read image file");
}
img_jpg_ptr(idict)= xtalloc(1,jpg_img_struct);
xfseek(img_file(idict),0,SEEK_END,img_filepath(idict));
img_jpg_ptr(idict)->length= xftell(img_file(idict),img_filepath(idict));
xfseek(img_file(idict),0,SEEK_SET,img_filepath(idict));
if((unsigned int)read2bytes(img_file(idict))!=0xFFD8){
normal_error("readjpg","no header found");
}

appmk= read2bytes(img_file(idict));
if(appmk==0xFFE0){

(void)read2bytes(img_file(idict));
for(i= 0;i<5;i++){
if(xgetc(img_file(idict))!=jpg_id[i])
break;
}
if(i==5){

(void)read2bytes(img_file(idict));
units= xgetc(img_file(idict));
img_xres(idict)= (int)read2bytes(img_file(idict));
img_yres(idict)= (int)read2bytes(img_file(idict));
switch(units){
case 1:

if((img_xres(idict)==1)||(img_yres(idict)==1)){
formatted_warning("readjpg","unusual resolution of %ddpi by %ddpi",img_xres(idict),img_yres(idict));
}
break;
case 2:

img_xres(idict)= (int)((double)img_xres(idict)*2.54);
img_yres(idict)= (int)((double)img_yres(idict)*2.54);
break;
default:
img_xres(idict)= img_yres(idict)= 0;
break;
}
}

if((img_xres(idict)==0)&&(img_yres(idict)!=0)){
img_xres(idict)= img_yres(idict);
}
if((img_yres(idict)==0)&&(img_xres(idict)!=0)){
img_yres(idict)= img_xres(idict);
}
}else if(appmk==0xFFE1){

FILE*fp= img_file(idict);
int xxres= 0;
int yyres= 0;
char app_sig[32];
length= myget_unsigned_pair(fp)-2;
if(length> 5){
if(fread(app_sig,sizeof(char),5,fp)!=5)
return;
length-= 5;
if(!memcmp(app_sig,"Exif\000",5)){
read_APP1_Exif(fp,length,&xxres,&yyres);
}
}
img_xres(idict)= xxres;
img_yres(idict)= yyres;
}
xfseek(img_file(idict),0,SEEK_SET,img_filepath(idict));
while(1){
if(feof(img_file(idict))){
normal_error("readjpg","premature file end");
}else if(fgetc(img_file(idict))!=0xFF){
normal_error("readjpg","no marker found");
}
i= xgetc(img_file(idict));
switch(i){
case M_SOF3:
case M_SOF5:
case M_SOF6:
case M_SOF7:
case M_SOF9:
case M_SOF10:
case M_SOF11:
case M_SOF13:
case M_SOF14:
case M_SOF15:
formatted_error("readjpg","unsupported compression SOF_%d",i-M_SOF0);
break;
case M_SOF2:
if(img_pdfminorversion(idict)<=2){
normal_error("readjpg","progressive DCT with PDF-1.2 is not permitted");
}
case M_SOF0:
case M_SOF1:
(void)read2bytes(img_file(idict));
img_colordepth(idict)= xgetc(img_file(idict));
img_ysize(idict)= (int)read2bytes(img_file(idict));
img_xsize(idict)= (int)read2bytes(img_file(idict));
img_jpg_color(idict)= xgetc(img_file(idict));
xfseek(img_file(idict),0,SEEK_SET,img_filepath(idict));
switch(img_jpg_color(idict)){
case JPG_GRAY:
img_procset(idict)|= PROCSET_IMAGE_B;
break;
case JPG_RGB:
img_procset(idict)|= PROCSET_IMAGE_C;
break;
case JPG_CMYK:
img_procset(idict)|= PROCSET_IMAGE_C;
break;
default:
formatted_error("readjpg","unsupported color space %i",(int)img_jpg_color(idict));
}



if(!img_keepopen(idict)){
close_and_cleanup_jpg(idict);
}
return;

case M_SOI:
case M_EOI:
case M_TEM:
case M_RST0:
case M_RST1:
case M_RST2:
case M_RST3:
case M_RST4:
case M_RST5:
case M_RST6:
case M_RST7:
break;
default:

xfseek(img_file(idict),(int)read2bytes(img_file(idict))-2,SEEK_CUR,img_filepath(idict));
break;
}
}
normal_error("readjpg","unknown fatal error");
}

/*:9*//*10:*/
#line 429 "./luatexdir/image/writejpg.w"

static void reopen_jpg(image_dict*idict)
{
int width= img_xsize(idict);
int height= img_ysize(idict);
int xres= img_xres(idict);
int yres= img_yres(idict);



img_keepopen(idict)= 1;
read_jpg_info(idict);
if(width!=img_xsize(idict)||height!=img_ysize(idict)||xres!=img_xres(idict)||yres!=img_yres(idict)){
normal_error("writejpg","image dimensions have changed");
}
}

/*:10*//*11:*/
#line 446 "./luatexdir/image/writejpg.w"

void write_jpg(PDF pdf,image_dict*idict)
{
size_t l;
if(img_file(idict)==NULL){
reopen_jpg(idict);
}
pdf_begin_obj(pdf,img_objnum(idict),OBJSTM_NEVER);
pdf_begin_dict(pdf);
pdf_dict_add_name(pdf,"Type","XObject");
pdf_dict_add_name(pdf,"Subtype","Image");
pdf_dict_add_img_filename(pdf,idict);
if(img_attr(idict)!=NULL&&strlen(img_attr(idict))> 0){
pdf_printf(pdf,"\n%s\n",img_attr(idict));
}
pdf_dict_add_int(pdf,"Width",(int)img_xsize(idict));
pdf_dict_add_int(pdf,"Height",(int)img_ysize(idict));
pdf_dict_add_int(pdf,"BitsPerComponent",(int)img_colordepth(idict));
pdf_dict_add_int(pdf,"Length",(int)img_jpg_ptr(idict)->length);
if(img_colorspace(idict)!=0){
pdf_dict_add_ref(pdf,"ColorSpace",(int)img_colorspace(idict));
}else{
switch(img_jpg_color(idict)){
case JPG_GRAY:
pdf_dict_add_name(pdf,"ColorSpace","DeviceGray");
break;
case JPG_RGB:
pdf_dict_add_name(pdf,"ColorSpace","DeviceRGB");
break;
case JPG_CMYK:
pdf_dict_add_name(pdf,"ColorSpace","DeviceCMYK");
pdf_add_name(pdf,"Decode");
pdf_begin_array(pdf);
pdf_add_int(pdf,1);
pdf_add_int(pdf,0);
pdf_add_int(pdf,1);
pdf_add_int(pdf,0);
pdf_add_int(pdf,1);
pdf_add_int(pdf,0);
pdf_add_int(pdf,1);
pdf_add_int(pdf,0);
pdf_end_array(pdf);
break;
default:
formatted_error("writejpg","unsupported JPEG color space %i",(int)img_jpg_color(idict));
}
}
pdf_dict_add_name(pdf,"Filter","DCTDecode");
pdf_end_dict(pdf);
pdf_begin_stream(pdf);
l= (size_t)img_jpg_ptr(idict)->length;
xfseek(img_file(idict),0,SEEK_SET,img_filepath(idict));
if(read_file_to_buf(pdf,img_file(idict),l)!=l){
normal_error("writejpg","fread failed");
}
pdf_end_stream(pdf);
pdf_end_obj(pdf);

close_and_cleanup_jpg(idict);
}/*:11*/
