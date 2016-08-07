/*2:*/
#line 43 "./ptfmin.w"

#line 4 "./pmpostdir/ptfmin.ch"
#include <kpathsea/kpathsea.h> 
#include <w2c/config.h> 
#line 45 "./ptfmin.w"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "pmplib.h"
#include "pmpmp.h" 
#include "pmpmath.h" 
#include "pmpstrings.h" 
/*3:*/
#line 59 "./ptfmin.w"

font_number mp_read_font_info(MP mp,char*fname);

/*:3*/
#line 52 "./ptfmin.w"
;
#define qi(A) (quarterword) (A) 
#define null_font 0
#define false 0
#define true 1
#define hlp1(A) mp->help_line[0]= A;}
#define hlp2(A,B) mp->help_line[1]= A;hlp1(B) 
#define hlp3(A,B,C) mp->help_line[2]= A;hlp2(B,C) 
#define help3 {mp->help_ptr= 3;hlp3 \

#define tfget do{ \
size_t wanted= 1; \
unsigned char abyte= 0; \
void*tfbyte_ptr= &abyte; \
(mp->read_binary_file) (mp,mp->tfm_infile,&tfbyte_ptr,&wanted) ; \
if(wanted==0) goto BAD_TFM; \
tfbyte= (int) abyte; \
}while(0) 
#define read_pair(A) {(A) = tfbyte; \
tfget;(A) = (A) *0400+tfbyte; \
}
#define read_two(A) {(A) = tfbyte; \
if((A) > 127) goto BAD_TFM; \
tfget;(A) = (A) *0400+tfbyte; \
}
#define tf_ignore(A) {for(jj= (A) ;jj>=1;jj--) tfget;} \

#define yoko_jfm_id 11
#define tate_jfm_id 9
#define font_jfm_p(A) (mp->font_id[(A) ]!=0) 
#define incr(A) (A) = (A) +1
#define integer_as_fraction(A) (int) (A)  \


#line 53 "./ptfmin.w"


/*:2*//*4:*/
#line 62 "./ptfmin.w"

font_number mp_read_font_info(MP mp,char*fname){
boolean file_opened;
font_number n;
#line 13 "./pmpostdir/ptfmin.ch"
halfword lf,tfm_lh,bc,ec,nw,nh,nd,nt;
#line 67 "./ptfmin.w"
size_t whd_size;
int i,ii;
int jj;
int z;
int d;
#line 19 "./pmpostdir/ptfmin.ch"
int h_and_d;
halfword ct;
halfword id;
#line 73 "./ptfmin.w"
int tfbyte= 0;
n= null_font;
/*13:*/
#line 234 "./ptfmin.w"

file_opened= false;
mp_ptr_scan_file(mp,fname);
if(strlen(mp->cur_area)==0){mp_xfree(mp->cur_area);mp->cur_area= NULL;}
if(strlen(mp->cur_ext)==0){
mp_xfree(mp->cur_ext);
mp->cur_ext= mp_xstrdup(mp,".tfm");
}
#line 106 "./pmpostdir/ptfmin.ch"
mp_pack_file_name(mp,mp->cur_name,mp->cur_area,mp->cur_ext);
{
char*fulln;
fulln= kpse_find_file(fname,kpse_tfm_format,1);
mp->tfm_infile= (mp->open_file)(mp,fulln,"r",mp_filetype_metrics);
if(fulln)mp_xfree(fulln);
}
#line 244 "./ptfmin.w"
if(!mp->tfm_infile)goto BAD_TFM;
file_opened= true







/*:13*/
#line 75 "./ptfmin.w"
;
/*6:*/
#line 109 "./ptfmin.w"

/*7:*/
#line 52 "./pmpostdir/ptfmin.ch"

tfget;read_two(lf);
if((lf==yoko_jfm_id)||(lf==tate_jfm_id)){
id= lf;
tfget;read_two(nt);
tfget;read_two(lf);
}else{
id= 0;nt= 0;
};
#line 140 "./ptfmin.w"
tfget;read_two(tfm_lh);
tfget;read_two(bc);
tfget;read_two(ec);
if((bc> 1+ec)||(ec> 255))goto BAD_TFM;
tfget;read_two(nw);
tfget;read_two(nh);
tfget;read_two(nd);
#line 66 "./pmpostdir/ptfmin.ch"
whd_size= (size_t)((ec+1-bc)+nt+nw+nh+nd);
#line 148 "./ptfmin.w"
if(lf<(int)(6+(size_t)tfm_lh+whd_size))goto BAD_TFM;
tf_ignore(10)

/*:7*/
#line 110 "./ptfmin.w"
;
/*8:*/
#line 157 "./ptfmin.w"

if(mp->next_fmem<(size_t)bc)
mp->next_fmem= (size_t)bc;
if(mp->last_fnum==mp->font_max)
mp_reallocate_fonts(mp,(mp->font_max+(mp->font_max/4)));
while(mp->next_fmem+whd_size>=mp->font_mem_size){
size_t l= mp->font_mem_size+(mp->font_mem_size/4);
font_data*font_info;
font_info= mp_xmalloc(mp,(l+1),sizeof(font_data));
memset(font_info,0,sizeof(font_data)*(l+1));
memcpy(font_info,mp->font_info,sizeof(font_data)*(mp->font_mem_size+1));
mp_xfree(mp->font_info);
mp->font_info= font_info;
mp->font_mem_size= l;
}
mp->last_fnum++;
n= mp->last_fnum;
mp->font_bc[n]= (eight_bits)bc;
mp->font_ec[n]= (eight_bits)ec;
#line 75 "./pmpostdir/ptfmin.ch"
mp->font_id[n]= id;
mp->font_nt[n]= nt;
mp->ctype_base[n]= mp->next_fmem;
mp->char_base[n]= (int)(mp->next_fmem+nt-(size_t)bc);
mp->width_base[n]= (int)(mp->next_fmem+nt+(size_t)(ec-bc)+1);
#line 178 "./ptfmin.w"
mp->height_base[n]= mp->width_base[n]+nw;
mp->depth_base[n]= mp->height_base[n]+nh;
mp->next_fmem= mp->next_fmem+whd_size;


/*:8*/
#line 111 "./ptfmin.w"
;
/*9:*/
#line 187 "./ptfmin.w"

if(tfm_lh<2)goto BAD_TFM;
tf_ignore(4);
tfget;read_two(z);
tfget;z= z*0400+tfbyte;
tfget;z= z*0400+tfbyte;
mp->font_dsize[n]= mp_take_fraction(mp,z,integer_as_fraction(267432584));

#line 88 "./pmpostdir/ptfmin.ch"
tf_ignore(4*(tfm_lh-2))

/*:9*/
#line 112 "./ptfmin.w"
;
#line 28 "./pmpostdir/ptfmin.ch"
/*10:*/
#line 90 "./pmpostdir/ptfmin.ch"

ii= mp->ctype_base[n]+nt;
i= mp->ctype_base[n];
while(i<ii){
tfget;read_pair(ct);
mp->font_info[i].hh.LH= ct;
tfget;read_two(ct);
mp->font_info[i].hh.RH= ct;
incr(i);
}
#line 196 "./ptfmin.w"

/*:10*/
#line 28 "./pmpostdir/ptfmin.ch"
;
/*11:*/
#line 197 "./ptfmin.w"

ii= mp->width_base[n];
i= mp->char_base[n]+bc;
while(i<ii){
tfget;mp->font_info[i].qqqq.b0= qi(tfbyte);
tfget;h_and_d= tfbyte;
mp->font_info[i].qqqq.b1= qi(h_and_d/16);
mp->font_info[i].qqqq.b2= qi(h_and_d%16);
tfget;tfget;
i++;
}
while(i<(int)mp->next_fmem){
/*12:*/
#line 220 "./ptfmin.w"

{
tfget;d= tfbyte;
if(d>=0200)d= d-0400;
tfget;d= d*0400+tfbyte;
tfget;d= d*0400+tfbyte;
tfget;d= d*0400+tfbyte;
mp->font_info[i].sc= mp_take_fraction(mp,d*16,integer_as_fraction(mp->font_dsize[n]));
i++;
}

/*:12*/
#line 210 "./ptfmin.w"
;
}
goto DONE

/*:11*/
#line 30 "./pmpostdir/ptfmin.ch"

#line 115 "./ptfmin.w"

/*:6*/
#line 77 "./ptfmin.w"
;
BAD_TFM:
/*5:*/
#line 94 "./ptfmin.w"

{
char msg[256];
const char*hlp[]= {
"I wasn't able to read the size data for this font so this",
"`infont' operation won't produce anything. If the font name",
"is right, you might ask an expert to make a TFM file",
NULL};
if(file_opened)
hlp[2]= "is right, try asking an expert to fix the TFM file";
mp_snprintf(msg,256,"Font %s not usable: TFM file %s",fname,
(file_opened?"is bad":"not found"));
mp_error(mp,msg,hlp,true);
}

/*:5*/
#line 79 "./ptfmin.w"
;
DONE:
if(file_opened)(mp->close_file)(mp,mp->tfm_infile);
if(n!=null_font){
mp->font_ps_name[n]= mp_xstrdup(mp,fname);
mp->font_name[n]= mp_xstrdup(mp,fname);
}
return n;
}

/*:4*/
