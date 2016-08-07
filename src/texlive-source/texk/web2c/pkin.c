/*1:*/
#line 49 "./luatexdir/font/pkin.w"



#include "ptexlib.h"

typedef short shalfword;

/*:1*//*2:*/
#line 60 "./luatexdir/font/pkin.w"

static shalfword pkbyte(void)
{
register shalfword i;
i= t3_getchar();
if(t3_eof())
normal_error("type 3","unexpected EOF in pk file");
return(i);
}

static int pkduo(void)
{
register int i;

i= pkbyte();
if(i> 127)
i-= 256;
i= i*256+pkbyte();
return(i);
}

static int pktrio(void)
{
register int i;

i= pkbyte();
if(i> 127)
i-= 256;
i= i*256+pkbyte();
i= i*256+pkbyte();
return(i);
}

static int pkquad(void)
{
register int i;

i= pkbyte();
if(i> 127)
i-= 256;
i= i*256+pkbyte();
i= i*256+pkbyte();
i= i*256+pkbyte();
return(i);
}



/*:2*//*4:*/
#line 113 "./luatexdir/font/pkin.w"

static halfword inputbyte,flagbyte;
static halfword bitweight;
static halfword dynf;
static halfword repeatcount;

static shalfword getnyb(void)
{
halfword temp;
if(bitweight==0){
bitweight= 16;
inputbyte= pkbyte();
temp= inputbyte>>4;
}else{
bitweight= 0;
temp= inputbyte&15;
}
return(shalfword)(temp);
}

static boolean getbit(void)
{
bitweight>>= 1;
if(bitweight==0){
inputbyte= pkbyte();
bitweight= 128;
}
return(inputbyte&bitweight);
}

static halfword(*realfunc)(void);
long pk_remainder;
static halfword handlehuge(halfword i,halfword k);

static halfword pkpackednum(void)
{
register halfword i,j;
i= getnyb();
if(i==0){
do{
j= getnyb();
i++;
}while(!(j!=0));
if(i> 3){




return(handlehuge(i,j));
}else{
while(i> 0){
j= j*16+getnyb();
i--;
}
return(j-15+(13-dynf)*16+dynf);
}
}else if(i<=dynf)
return(i);
else if(i<14)
return((i-dynf-1)*16+getnyb()+dynf+1);
else{
if(i==14)
repeatcount= pkpackednum();
else
repeatcount= 1;
#ifdef DEBUG
printf("[%d]",(int)repeatcount);
#endif
return((*realfunc)());
}
}

static halfword rest(void)
{
halfword i;

if(pk_remainder<0){
pk_remainder= -pk_remainder;
return(0);
}else if(pk_remainder> 0){
if(pk_remainder> 4000){
pk_remainder= 4000-pk_remainder;
return(4000);
}else{
i= (halfword)pk_remainder;
pk_remainder= 0;
realfunc= pkpackednum;
return(i);
}
}else{
normal_error("type 3","pk issue that shouldn't happen");
return 0;
}
}

static halfword handlehuge(halfword i,halfword k)
{
register long j= k;

while(i){
j= (j<<4L)+getnyb();
i--;
}
pk_remainder= j-15+(13-dynf)*16+dynf;
realfunc= rest;
return(rest());
}


/*:4*//*5:*/
#line 224 "./luatexdir/font/pkin.w"

static halfword gpower[17]= {0,1,3,7,15,31,63,127,
255,511,1023,2047,4095,8191,16383,32767,65535
};

static void unpack(chardesc*cd)
{
register int i,j;
register halfword word,wordweight;
halfword*raster;
shalfword rowsleft;
boolean turnon;
shalfword hbit;
halfword count;
shalfword wordwidth;

wordwidth= (shalfword)((cd->cwidth+15)/16);
i= (int)(2*cd->cheight*(long)wordwidth);
if(i<=0)
i= 2;
if(i> cd->rastersize){
xfree(cd->raster);
cd->rastersize= i;
cd->raster= xtalloc((unsigned)cd->rastersize,halfword);
}
raster= cd->raster;
realfunc= pkpackednum;
dynf= flagbyte/16;
turnon= flagbyte&8;
if(dynf==14){
bitweight= 0;
for(i= 1;i<=cd->cheight;i++){
word= 0;
wordweight= 32768;
for(j= 1;j<=cd->cwidth;j++){
if(getbit())
word+= wordweight;
wordweight>>= 1;
if(wordweight==0){
*raster++= word;
word= 0;
wordweight= 32768;
}
}
if(wordweight!=32768)
*raster++= word;
}
}else{
rowsleft= (shalfword)cd->cheight;
hbit= (shalfword)cd->cwidth;
repeatcount= 0;
wordweight= 16;
word= 0;
bitweight= 0;
while(rowsleft> 0){
count= (*realfunc)();
while(count!=0){
if((count<wordweight)&&(count<hbit)){
if(turnon)
word+= gpower[wordweight]-gpower[wordweight-count];
hbit= (shalfword)(hbit-count);
wordweight-= count;
count= 0;
}else if((count>=hbit)&&(hbit<=wordweight)){
if(turnon)
word+= gpower[wordweight]-gpower[wordweight-hbit];
*raster++= word;
for(i= 1;i<=repeatcount;i++){
for(j= 1;j<=wordwidth;j++){
*raster= *(raster-wordwidth);
raster++;
}
}
rowsleft= (shalfword)(rowsleft-repeatcount-1);
repeatcount= 0;
word= 0;
wordweight= 16;
count-= hbit;
hbit= (shalfword)cd->cwidth;
}else{
if(turnon)
word+= gpower[wordweight];
*raster++= word;
word= 0;
count-= wordweight;
hbit= (shalfword)(hbit-wordweight);
wordweight= 16;
}
}
turnon= !turnon;
}
if((rowsleft!=0)||((int)hbit!=cd->cwidth))
normal_error("type 3","error while unpacking, more bits than required");
}
}

/*:5*//*6:*/
#line 326 "./luatexdir/font/pkin.w"

int readchar(boolean check_preamble,chardesc*cd)
{
register shalfword i;
register int k;
register int length= 0;




if(check_preamble){
if(pkbyte()!=247)
normal_error("type 3","bad pk file, expected pre");
if(pkbyte()!=89)
normal_error("type 3","bad version of pk file");
for(i= pkbyte();i> 0;i--)
(void)pkbyte();
(void)pkquad();
k= pkquad();
k= pkquad();
k= pkquad();
}



while((flagbyte= pkbyte())!=245){
if(flagbyte<240){
switch(flagbyte&7){
case 0:
case 1:
case 2:
case 3:
length= (flagbyte&7)*256+pkbyte()-3;
cd->charcode= pkbyte();
(void)pktrio();
cd->xescape= pkbyte();
cd->cwidth= pkbyte();
cd->cheight= pkbyte();
cd->xoff= pkbyte();
cd->yoff= pkbyte();
if(cd->xoff> 127)
cd->xoff-= 256;
if(cd->yoff> 127)
cd->yoff-= 256;
break;
case 4:
case 5:
case 6:
length= (int)((flagbyte&3)*65536L+pkbyte()*256L);
length= (int)(length+pkbyte()-4L);
cd->charcode= pkbyte();
(void)pktrio();
cd->xescape= pkduo();
cd->cwidth= pkduo();
cd->cheight= pkduo();
cd->xoff= pkduo();
cd->yoff= pkduo();
break;
case 7:
length= (int)(pkquad()-9L);
cd->charcode= pkquad();
(void)pkquad();
cd->xescape= pkquad();
k= pkquad();
cd->cwidth= pkquad();
cd->cheight= pkquad();
cd->xoff= pkquad();
cd->yoff= pkquad();
}
if(length<=0)
formatted_error("type 3","pk packet length '%i' too small",(int)length);
unpack(cd);
return 1;
}else{
k= 0;
switch(flagbyte){
case 243:
k= pkbyte();
if(k> 127)
k-= 256;
case 242:
k= k*256+pkbyte();
case 241:
k= k*256+pkbyte();
case 240:
k= k*256+pkbyte();
while(k--> 0)
i= pkbyte();
break;
case 244:
k= pkquad();
break;
case 246:
break;
default:
formatted_error("type 3","unexpected pk command '%i'",(int)flagbyte);
}
}
}
return 0;
}/*:6*/
