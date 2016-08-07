/*1:*/
#line 21 "./luatexdir/font/writefont.w"



#include "ptexlib.h"
#include "lua/luatex-api.h"

void write_cid_fontdictionary(PDF pdf,fo_entry*fo,internal_font_number f);
static void create_cid_fontdictionary(PDF pdf,internal_font_number f);

const key_entry font_key[FONT_KEYS_NUM]= {
{"Ascent","Ascender",1}
,{"CapHeight","CapHeight",1}
,{"Descent","Descender",1}
,{"ItalicAngle","ItalicAngle",1}
,{"StemV","StdVW",1}
,{"XHeight","XHeight",1}
,{"FontBBox","FontBBox",1}
,{"","",0}
,{"","",0}
,{"","",0}
,{"FontName","FontName",1}
};

/*:1*//*2:*/
#line 45 "./luatexdir/font/writefont.w"

struct avl_table*fo_tree= NULL;
struct avl_table*fd_tree= NULL;

static int comp_fo_entry(const void*pa,const void*pb,void*p)
{
(void)p;
return strcmp(((const fo_entry*)pa)->fm->tfm_name,
((const fo_entry*)pb)->fm->tfm_name);
}

static int comp_fd_entry(const void*pa,const void*pb,void*p)
{
const fd_entry*p1= (const fd_entry*)pa,*p2= (const fd_entry*)pb;
(void)p;
assert(p1->fm!=NULL&&is_fontfile(p1->fm)&&
p2->fm!=NULL&&is_fontfile(p2->fm));
return strcmp(p1->fm->ff_name,p2->fm->ff_name);
}

/*:2*//*3:*/
#line 66 "./luatexdir/font/writefont.w"

static fo_entry*new_fo_entry(void)
{
fo_entry*fo;
fo= xtalloc(1,fo_entry);
fo->fo_objnum= 0;
fo->tex_font= 0;
fo->fm= NULL;
fo->fd= NULL;
fo->fe= NULL;
fo->cw_objnum= 0;
fo->first_char= 1;
fo->last_char= 0;
fo->tx_tree= NULL;
fo->tounicode_objnum= 0;
return fo;
}

/*:3*//*4:*/
#line 85 "./luatexdir/font/writefont.w"

fd_entry*new_fd_entry(void)
{
fd_entry*fd;
int i;
fd= xtalloc(1,fd_entry);
fd->fd_objnum= 0;
fd->fontname= NULL;
fd->subset_tag= NULL;
fd->ff_found= false;
fd->ff_objnum= 0;
fd->all_glyphs= false;
fd->write_ttf_glyph_names= false;
for(i= 0;i<FONT_KEYS_NUM;i++){
fd->font_dim[i].val= 0;
fd->font_dim[i].set= false;
}
fd->fe= NULL;
fd->builtin_glyph_names= NULL;
fd->fm= NULL;
fd->tx_tree= NULL;
fd->gl_tree= NULL;
return fd;
}

/*:4*//*5:*/
#line 115 "./luatexdir/font/writefont.w"

static void preset_fontmetrics(fd_entry*fd,internal_font_number f)
{
int i;
fd->font_dim[ITALIC_ANGLE_CODE].val= 0;
fd->font_dim[ASCENT_CODE].val= 
divide_scaled(char_height(f,'h'),font_size(f),3);
fd->font_dim[CAPHEIGHT_CODE].val= 
divide_scaled(char_height(f,'H'),font_size(f),3);
i= -divide_scaled(char_depth(f,'y'),font_size(f),3);
fd->font_dim[DESCENT_CODE].val= i<0?i:0;
fd->font_dim[STEMV_CODE].val= 
divide_scaled(char_width(f,'.')/3,font_size(f),3);
fd->font_dim[XHEIGHT_CODE].val= 
divide_scaled(get_x_height(f),font_size(f),3);
fd->font_dim[FONTBBOX1_CODE].val= 0;
fd->font_dim[FONTBBOX2_CODE].val= fd->font_dim[DESCENT_CODE].val;
fd->font_dim[FONTBBOX3_CODE].val= 
divide_scaled(get_quad(f),font_size(f),3);
fd->font_dim[FONTBBOX4_CODE].val= 
fd->font_dim[CAPHEIGHT_CODE].val> fd->font_dim[ASCENT_CODE].val?
fd->font_dim[CAPHEIGHT_CODE].val:fd->font_dim[ASCENT_CODE].val;
for(i= 0;i<INT_KEYS_NUM;i++)
fd->font_dim[i].set= true;
}

static void fix_fontmetrics(fd_entry*fd)
{
int i;
intparm*p= (intparm*)fd->font_dim;
assert(p[FONTBBOX1_CODE].set&&p[FONTBBOX2_CODE].set
&&p[FONTBBOX3_CODE].set&&p[FONTBBOX4_CODE].set);

if(p[FONTBBOX3_CODE].val<p[FONTBBOX1_CODE].val){
i= p[FONTBBOX3_CODE].val;
p[FONTBBOX3_CODE].val= p[FONTBBOX1_CODE].val;
p[FONTBBOX1_CODE].val= i;
}else if(p[FONTBBOX3_CODE].val==p[FONTBBOX1_CODE].val)
p[FONTBBOX3_CODE].val= p[FONTBBOX1_CODE].val+1;
if(p[FONTBBOX4_CODE].val<p[FONTBBOX2_CODE].val){
i= p[FONTBBOX4_CODE].val;
p[FONTBBOX4_CODE].val= p[FONTBBOX2_CODE].val;
p[FONTBBOX2_CODE].val= i;
}else if(p[FONTBBOX4_CODE].val==p[FONTBBOX2_CODE].val)
p[FONTBBOX4_CODE].val= p[FONTBBOX2_CODE].val+1;
if(!p[ASCENT_CODE].set){
p[ASCENT_CODE].val= p[FONTBBOX4_CODE].val;
p[ASCENT_CODE].set= true;
}
if(!p[DESCENT_CODE].set){
p[DESCENT_CODE].val= p[FONTBBOX2_CODE].val;
p[DESCENT_CODE].set= true;
}
if(!p[CAPHEIGHT_CODE].set){
p[CAPHEIGHT_CODE].val= p[FONTBBOX4_CODE].val;
p[CAPHEIGHT_CODE].set= true;
}
}

static void write_fontmetrics(PDF pdf,fd_entry*fd)
{
int i;
fix_fontmetrics(fd);
pdf_add_name(pdf,font_key[FONTBBOX1_CODE].pdfname);
pdf_begin_array(pdf);
pdf_printf(pdf,"%i %i %i %i",(int)fd->font_dim[FONTBBOX1_CODE].val,
(int)fd->font_dim[FONTBBOX2_CODE].val,
(int)fd->font_dim[FONTBBOX3_CODE].val,
(int)fd->font_dim[FONTBBOX4_CODE].val);
pdf_end_array(pdf);
for(i= 0;i<GEN_KEY_NUM;i++)
if(fd->font_dim[i].set)
pdf_dict_add_int(pdf,font_key[i].pdfname,fd->font_dim[i].val);
}

/*:5*//*6:*/
#line 191 "./luatexdir/font/writefont.w"

static void preset_fontname(fo_entry*fo,internal_font_number f)
{
if(fo->fm->ps_name!=NULL)
fo->fd->fontname= xstrdup(fo->fm->ps_name);
else if(font_fullname(f)!=NULL)
fo->fd->fontname= xstrdup(font_fullname(f));
else
fo->fd->fontname= xstrdup(fo->fm->tfm_name);
}

static void pdf_dict_add_fontname(PDF pdf,const char*key,fd_entry*fd)
{
char*s;
size_t l1= 0,l2;
assert(fd->fontname!=NULL);
assert(key!=NULL);
if(fd->subset_tag!=NULL)
l1= strlen(fd->subset_tag);
l2= strlen(fd->fontname);
s= xmalloc(l1+l2+2);
if(l1> 0)
snprintf(s,l1+l2+2,"%s+%s",fd->subset_tag,fd->fontname);
else
snprintf(s,l2+1,"%s",fd->fontname);
pdf_dict_add_name(pdf,key,s);
xfree(s);
}

/*:6*//*7:*/
#line 221 "./luatexdir/font/writefont.w"

fd_entry*lookup_fd_entry(char*s)
{
fd_entry fd;
fm_entry fm;
assert(s!=NULL);
fm.ff_name= s;
fd.fm= &fm;
if(fd_tree==NULL){
fd_tree= avl_create(comp_fd_entry,NULL,&avl_xallocator);
assert(fd_tree!=NULL);
}
return(fd_entry*)avl_find(fd_tree,&fd);
}

static fd_entry*lookup_fontdescriptor(fo_entry*fo)
{
assert(fo!=NULL);
assert(fo->fm!=NULL);
assert(is_fontfile(fo->fm));
return lookup_fd_entry(fo->fm->ff_name);
}

void register_fd_entry(fd_entry*fd)
{
void**aa;
if(fd_tree==NULL){
fd_tree= avl_create(comp_fd_entry,NULL,&avl_xallocator);
assert(fd_tree!=NULL);
}
assert(fd!=NULL&&fd->fm!=NULL&&is_fontfile(fd->fm));
assert(lookup_fd_entry(fd->fm->ff_name)==NULL);
aa= avl_probe(fd_tree,fd);
assert(aa!=NULL);
}

static void create_fontdescriptor(fo_entry*fo,internal_font_number f)
{
assert(fo!=NULL);
assert(fo->fm!=NULL);
assert(fo->fd==NULL);
fo->fd= new_fd_entry();
preset_fontname(fo,f);
preset_fontmetrics(fo->fd,f);
fo->fd->fe= fo->fe;
fo->fd->fm= fo->fm;
fo->fd->gl_tree= avl_create(comp_string_entry,NULL,&avl_xallocator);
assert(fo->fd->gl_tree!=NULL);
}

/*:7*//*8:*/
#line 276 "./luatexdir/font/writefont.w"

static void mark_reenc_glyphs(fo_entry*fo,internal_font_number f)
{
int i;
char**g;
void**aa;
assert(fo->fe!=NULL);
if(is_subsetted(fo->fm)){
assert(is_included(fo->fm));

g= fo->fe->glyph_names;
for(i= fo->first_char;i<=fo->last_char;i++){
if(pdf_char_marked(f,i)&&g[i]!=notdef
&&(char*)avl_find(fo->fd->gl_tree,g[i])==NULL){
aa= avl_probe(fo->fd->gl_tree,xstrdup(g[i]));
assert(aa!=NULL);
}
}
}
}

/*:8*//*9:*/
#line 302 "./luatexdir/font/writefont.w"

static struct avl_table*mark_chars(fo_entry*fo,struct avl_table*tx_tree,
internal_font_number f)
{
int i,*j;
void**aa;
if(tx_tree==NULL){
tx_tree= avl_create(comp_int_entry,NULL,&avl_xallocator);
assert(tx_tree!=NULL);
}
for(i= fo->first_char;i<=fo->last_char;i++){
if(pdf_char_marked(f,i)&&(int*)avl_find(tx_tree,&i)==NULL){
j= xtalloc(1,int);
*j= i;
aa= avl_probe(tx_tree,j);
assert(aa!=NULL);
}
}
return tx_tree;
}

/*:9*//*10:*/
#line 324 "./luatexdir/font/writefont.w"

static void get_char_range(fo_entry*fo,internal_font_number f)
{
int i;
assert(fo!=NULL);
for(i= font_bc(f);i<=font_ec(f);i++)
if(pdf_char_marked(f,i))
break;
fo->first_char= i;
for(i= font_ec(f);i>=font_bc(f);i--)
if(pdf_char_marked(f,i))
break;
fo->last_char= i;
if((fo->first_char> fo->last_char)
||!pdf_char_marked(f,fo->first_char)){
fo->last_char= 0;
fo->first_char= fo->last_char+1;
}
}

static int font_has_subset(internal_font_number f)
{
int i,s;
for(i= font_bc(f);i<=font_ec(f);i++)
if(pdf_char_marked(f,i))
break;
s= i;
for(i= font_ec(f);i>=font_bc(f);i--)
if(pdf_char_marked(f,i))
break;
if(s> i)
return 0;
else
return 1;
}

/*:10*//*11:*/
#line 361 "./luatexdir/font/writefont.w"

static void write_charwidth_array(PDF pdf,fo_entry*fo,
internal_font_number f)
{
int i,j,*ip,*fip;
struct avl_traverser t;
assert(fo->tx_tree!=NULL);
assert(fo->cw_objnum==0);
fo->cw_objnum= pdf_create_obj(pdf,obj_type_others,0);
pdf_begin_obj(pdf,fo->cw_objnum,OBJSTM_ALWAYS);
avl_t_init(&t,fo->tx_tree);
fip= (int*)avl_t_first(&t,fo->tx_tree);
assert(fip!=NULL);
pdf_begin_array(pdf);
for(ip= fip,j= *ip;ip!=NULL;ip= (int*)avl_t_next(&t)){
if(ip!=fip)
pdf_out(pdf,' ');
i= *ip;
while(j<i-1){
pdf_puts(pdf,"0 ");
j++;
}
j= i;
pdf_print_charwidth(pdf,f,i);
}
pdf_end_array(pdf);
pdf_end_obj(pdf);
}

/*:11*//*12:*/
#line 392 "./luatexdir/font/writefont.w"

static fo_entry*lookup_fo_entry(char*s)
{
fo_entry fo;
fm_entry fm;
assert(s!=NULL);
fm.tfm_name= s;
fo.fm= &fm;
if(fo_tree==NULL){
fo_tree= avl_create(comp_fo_entry,NULL,&avl_xallocator);
assert(fo_tree!=NULL);
}
return(fo_entry*)avl_find(fo_tree,&fo);
}

static void register_fo_entry(fo_entry*fo)
{
void**aa;
if(fo_tree==NULL){
fo_tree= avl_create(comp_fo_entry,NULL,&avl_xallocator);
assert(fo_tree!=NULL);
}
assert(fo!=NULL);
assert(fo->fm!=NULL);
assert(fo->fm->tfm_name!=NULL);
assert(lookup_fo_entry(fo->fm->tfm_name)==NULL);
aa= avl_probe(fo_tree,fo);
assert(aa!=NULL);
}

/*:12*//*13:*/
#line 423 "./luatexdir/font/writefont.w"

static void write_fontfile(PDF pdf,fd_entry*fd)
{
assert(is_included(fd->fm));



if(is_cidkeyed(fd->fm)){
if(is_opentype(fd->fm)){
writetype0(pdf,fd);
}else if(is_truetype(fd->fm)){
if(!writetype2(pdf,fd)){
writetype0(pdf,fd);
fd->fm->type|= F_OTF;fd->fm->type^= F_TRUETYPE;
}
}else if(is_type1(fd->fm))
writetype1w(pdf,fd);
else
assert(0);
}else{
if(is_type1(fd->fm))
writet1(pdf,fd);
else if(is_truetype(fd->fm))
writettf(pdf,fd);
else if(is_opentype(fd->fm))
writeotf(pdf,fd);
else
assert(0);
}
if(!fd->ff_found)
return;
assert(fd->ff_objnum==0);
fd->ff_objnum= pdf_create_obj(pdf,obj_type_others,0);
pdf_begin_obj(pdf,fd->ff_objnum,OBJSTM_NEVER);
pdf_begin_dict(pdf);
if(is_cidkeyed(fd->fm)){

if(is_opentype(fd->fm)||is_type1(fd->fm))
pdf_dict_add_name(pdf,"Subtype","CIDFontType0C");
#if 0
else
pdf_dict_add_name(pdf,"Subtype","OpenType");
#endif
}else{
if(is_type1(fd->fm)){
pdf_dict_add_int(pdf,"Length1",(int)t1_length1);
pdf_dict_add_int(pdf,"Length2",(int)t1_length2);
pdf_dict_add_int(pdf,"Length3",(int)t1_length3);
}else if(is_truetype(fd->fm))
pdf_dict_add_int(pdf,"Length1",(int)ttf_length);
else if(is_opentype(fd->fm))
pdf_dict_add_name(pdf,"Subtype","Type1C");
else
assert(0);
}
pdf_dict_add_streaminfo(pdf);
pdf_end_dict(pdf);
pdf_begin_stream(pdf);
strbuf_flush(pdf,pdf->fb);
pdf_end_stream(pdf);
pdf_end_obj(pdf);
}

/*:13*//*14:*/
#line 487 "./luatexdir/font/writefont.w"

int cidset= 0;
static void write_fontdescriptor(PDF pdf,fd_entry*fd)
{
static const int std_flags[]= {



1+2+(1<<5),
1+2+(1<<5)+(1<<18),
1+2+(1<<5)+(1<<6),
1+2+(1<<5)+(1<<6)+(1<<18),
(1<<5),
(1<<5)+(1<<18),
(1<<5)+(1<<6),
(1<<5)+(1<<6)+(1<<18),
4,
2+(1<<5),
2+(1<<5)+(1<<18),
2+(1<<5)+(1<<6),
2+(1<<5)+(1<<6)+(1<<18),
4

};
char*glyph;
struct avl_traverser t;
int fd_flags;
assert(fd!=NULL&&fd->fm!=NULL);
cidset= 0;
if(is_fontfile(fd->fm)&&is_included(fd->fm))
write_fontfile(pdf,fd);
if(fd->fd_objnum==0)
fd->fd_objnum= pdf_create_obj(pdf,obj_type_others,0);
pdf_begin_obj(pdf,fd->fd_objnum,OBJSTM_ALWAYS);
pdf_begin_dict(pdf);
pdf_dict_add_name(pdf,"Type","FontDescriptor");
pdf_dict_add_fontname(pdf,"FontName",fd);
if(fd->fm->fd_flags!=FD_FLAGS_NOT_SET_IN_MAPLINE)
fd_flags= (int)fd->fm->fd_flags;
else if(fd->ff_found)
fd_flags= FD_FLAGS_DEFAULT_EMBED;
else{
fd_flags= is_std_t1font(fd->fm)
?std_flags[check_std_t1font(fd->fm->ps_name)]
:FD_FLAGS_DEFAULT_NON_EMBED;
formatted_warning("map file",
"No flags specified for non-embedded font '%s' (%s), I'm using %i, fix your map entry",
fd->fm->ps_name!=NULL?fd->fm->ps_name:"No name given",
fd->fm->tfm_name,fd_flags);
}
pdf_dict_add_int(pdf,"Flags",fd_flags);
write_fontmetrics(pdf,fd);
if(fd->ff_found){
if(is_cidkeyed(fd->fm)){
if(is_type1(fd->fm))
pdf_dict_add_ref(pdf,"FontFile3",(int)fd->ff_objnum);
else if(is_truetype(fd->fm))
pdf_dict_add_ref(pdf,"FontFile2",(int)fd->ff_objnum);
else if(is_opentype(fd->fm))
pdf_dict_add_ref(pdf,"FontFile3",(int)fd->ff_objnum);
else
assert(0);
}else{
if(is_subsetted(fd->fm)&&is_type1(fd->fm)){

assert(fd->gl_tree!=NULL);
avl_t_init(&t,fd->gl_tree);
pdf_add_name(pdf,"CharSet");
pdf_out(pdf,'(');
for(glyph= (char*)avl_t_first(&t,fd->gl_tree);
glyph!=NULL;glyph= (char*)avl_t_next(&t))
pdf_add_name(pdf,glyph);
pdf_out(pdf,')');
pdf->cave= 0;
}
if(is_type1(fd->fm))
pdf_dict_add_ref(pdf,"FontFile",(int)fd->ff_objnum);
else if(is_truetype(fd->fm))
pdf_dict_add_ref(pdf,"FontFile2",(int)fd->ff_objnum);
else if(is_opentype(fd->fm))
pdf_dict_add_ref(pdf,"FontFile3",(int)fd->ff_objnum);
else
assert(0);
}
}
if(cidset!=0)
pdf_dict_add_ref(pdf,"CIDSet",cidset);




pdf_end_dict(pdf);
pdf_end_obj(pdf);
}

static void write_fontdescriptors(PDF pdf)
{
fd_entry*fd;
struct avl_traverser t;
if(fd_tree==NULL)
return;
avl_t_init(&t,fd_tree);
for(fd= (fd_entry*)avl_t_first(&t,fd_tree);fd!=NULL;
fd= (fd_entry*)avl_t_next(&t))
write_fontdescriptor(pdf,fd);
}

/*:14*//*15:*/
#line 595 "./luatexdir/font/writefont.w"

static void write_fontdictionary(PDF pdf,fo_entry*fo)
{
assert(fo!=NULL);
assert(fo->fm!=NULL);
assert(fo->fo_objnum!=0);


if(pdf->gen_tounicode> 0&&fo->fd!=NULL){
if(fo->fe!=NULL){
fo->tounicode_objnum= 
write_tounicode(pdf,fo->fe->glyph_names,fo->fe->name);
}else if(is_type1(fo->fm)){
assert(fo->fd->builtin_glyph_names!=NULL);
fo->tounicode_objnum= 
write_tounicode(pdf,fo->fd->builtin_glyph_names,
fo->fm->tfm_name);
}
}
pdf_begin_obj(pdf,fo->fo_objnum,OBJSTM_ALWAYS);
pdf_begin_dict(pdf);
pdf_dict_add_name(pdf,"Type","Font");
if(is_type1(fo->fm))
pdf_dict_add_name(pdf,"Subtype","Type1");
else if(is_truetype(fo->fm))
pdf_dict_add_name(pdf,"Subtype","TrueType");
else if(is_opentype(fo->fm))
pdf_dict_add_name(pdf,"Subtype","Type1");
else
assert(0);
assert(fo->fd!=NULL&&fo->fd->fd_objnum!=0);
pdf_dict_add_fontname(pdf,"BaseFont",fo->fd);
pdf_dict_add_ref(pdf,"FontDescriptor",(int)fo->fd->fd_objnum);
assert(fo->cw_objnum!=0);
pdf_dict_add_int(pdf,"FirstChar",(int)fo->first_char);
pdf_dict_add_int(pdf,"LastChar",(int)fo->last_char);
pdf_dict_add_ref(pdf,"Widths",(int)fo->cw_objnum);
if((is_type1(fo->fm)||is_opentype(fo->fm))&&fo->fe!=NULL
&&fo->fe->fe_objnum!=0)
pdf_dict_add_ref(pdf,"Encoding",(int)fo->fe->fe_objnum);
if(fo->tounicode_objnum!=0)
pdf_dict_add_ref(pdf,"ToUnicode",(int)fo->tounicode_objnum);
if(pdf_font_attr(fo->tex_font)!=get_nullstr()&&
pdf_font_attr(fo->tex_font)!=0){
pdf_print(pdf,pdf_font_attr(fo->tex_font));
pdf_out(pdf,'\n');
}
pdf_end_dict(pdf);
pdf_end_obj(pdf);
}

static void write_fontdictionaries(PDF pdf)
{
fo_entry*fo;
struct avl_traverser t;
if(fo_tree==NULL)
return;
avl_t_init(&t,fo_tree);
for(fo= (fo_entry*)avl_t_first(&t,fo_tree);fo!=NULL;
fo= (fo_entry*)avl_t_next(&t))
write_fontdictionary(pdf,fo);
}

/*:15*//*16:*/
#line 661 "./luatexdir/font/writefont.w"

void write_fontstuff(PDF pdf)
{
write_fontdescriptors(pdf);
write_fontencodings(pdf);
write_fontdictionaries(pdf);
}

/*:16*//*17:*/
#line 670 "./luatexdir/font/writefont.w"

static void create_fontdictionary(PDF pdf,internal_font_number f)
{
fo_entry*fo= new_fo_entry();
fm_entry*fm= font_map(f);
get_char_range(fo,f);
if(fo->last_char> 255)
fo->last_char= 255;
assert(fo->last_char>=fo->first_char);
fo->fm= fm;
fo->fo_objnum= pdf_font_num(f);
fo->tex_font= f;
if(is_reencoded(fo->fm)){
fo->fe= get_fe_entry(fo->fm->encname);
if(fo->fe!=NULL&&(is_type1(fo->fm)||is_opentype(fo->fm))){
if(fo->fe->fe_objnum==0)
fo->fe->fe_objnum= pdf_create_obj(pdf,obj_type_others,0);

fo->fe->tx_tree= mark_chars(fo,fo->fe->tx_tree,f);
}
}
fo->tx_tree= mark_chars(fo,fo->tx_tree,f);
write_charwidth_array(pdf,fo,f);
if(!is_builtin(fo->fm)){
if(is_type1(fo->fm)){
if((fo->fd= lookup_fontdescriptor(fo))==NULL){
create_fontdescriptor(fo,f);
register_fd_entry(fo->fd);
}
}else
create_fontdescriptor(fo,f);
if(fo->fe!=NULL){
mark_reenc_glyphs(fo,f);
if(!is_type1(fo->fm)){

assert(fo->fd->tx_tree==NULL);
fo->fd->tx_tree= mark_chars(fo,fo->fd->tx_tree,f);
if(is_truetype(fo->fm))
fo->fd->write_ttf_glyph_names= true;
}
}else

fo->fd->tx_tree= mark_chars(fo,fo->fd->tx_tree,f);
if(!is_type1(fo->fm))
write_fontdescriptor(pdf,fo->fd);
}else{



create_fontdescriptor(fo,f);
write_fontdescriptor(pdf,fo->fd);
if(!is_std_t1font(fo->fm))
formatted_warning("map file","font '%s' is not a standard font; I suppose it is available to your PDF viewer then",
fo->fm->ps_name);
}
if(is_type1(fo->fm))
register_fo_entry(fo);
else
write_fontdictionary(pdf,fo);
}

/*:17*//*18:*/
#line 732 "./luatexdir/font/writefont.w"

static int has_ttf_outlines(fm_entry*fm)
{
FILE*f= fopen(fm->ff_name,"rb");
if(f!=NULL){
int ch1= getc(f);
int ch2= getc(f);
int ch3= getc(f);
int ch4= getc(f);
fclose(f);
if(ch1=='O'&&ch2=='T'&&ch3=='T'&&ch4=='O')
return 0;
return 1;
}
return 0;
}

void do_pdf_font(PDF pdf,internal_font_number f)
{
int del_file= 0;
fm_entry*fm;




if(!font_has_subset(f))
return;

if(font_encodingbytes(f)==2){



fm= font_map(f)= new_fm_entry();
fm->tfm_name= font_name(f);
fm->ff_name= font_filename(f);
if(font_psname(f)!=NULL)
fm->ps_name= font_psname(f);
else
fm->ps_name= font_fullname(f);
if(fm->ff_name
&&strlen(fm->ff_name)>=6
&&strstr(fm->ff_name,
".dfont")==(fm->ff_name+strlen(fm->ff_name)-6)){





char*s= FindResourceTtfFont(fm->ff_name,fm->ps_name);
if(s!=NULL){
fm->ff_name= s;
del_file= 1;
}else{
formatted_error("font","file '%s' does not contain font '%s'",fm->ff_name,fm->ps_name);
}
}
fm->encname= font_encodingname(f);
fm->slant= font_slant(f);
set_slantset(fm);
fm->extend= font_extend(f);
set_extendset(fm);
fm->fd_flags= 4;
set_inuse(fm);

switch(font_format(f)){
case opentype_format:
if(has_ttf_outlines(fm)){
set_truetype(fm);
}else{
set_opentype(fm);
}
break;
case truetype_format:
set_truetype(fm);
break;
case type1_format:
set_type1(fm);
break;
default:
formatted_error("font","file format '%s' for '%s' is incompatible with wide characters",
font_format_name(f),font_name(f));
}

if(font_embedding(f)!=no_embedding){
set_included(fm);
if(font_embedding(f)!=full_embedding){
set_subsetted(fm);
}
}
set_cidkeyed(fm);
create_cid_fontdictionary(pdf,f);

if(del_file)
unlink(fm->ff_name);

}else{

if((fm= font_map(f))==NULL
||(fm->ps_name==NULL&&fm->ff_name==NULL))
writet3(pdf,f);
else
create_fontdictionary(pdf,f);
}
}

/*:18*//*19:*/
#line 845 "./luatexdir/font/writefont.w"

static int comp_glw_entry(const void*pa,const void*pb,void*p
__attribute__((unused)))
{
unsigned short i,j;

i= (unsigned short)(*(const glw_entry*)pa).id;
j= (unsigned short)(*(const glw_entry*)pb).id;
cmp_return(i,j);
return 0;
}

static void create_cid_fontdescriptor(fo_entry*fo,internal_font_number f)
{
assert(fo!=NULL);
assert(fo->fm!=NULL);
assert(fo->fd==NULL);
fo->fd= new_fd_entry();
preset_fontname(fo,f);
preset_fontmetrics(fo->fd,f);
fo->fd->fe= fo->fe;
fo->fd->fm= fo->fm;
fo->fd->gl_tree= avl_create(comp_glw_entry,NULL,&avl_xallocator);
assert(fo->fd->gl_tree!=NULL);
}


/*:19*//*20:*/
#line 876 "./luatexdir/font/writefont.w"

static void mark_cid_subset_glyphs(fo_entry*fo,internal_font_number f)
{
int i,k,l;
glw_entry*j;
void*aa;
for(k= 1;k<=max_font_id();k++){
if(k==f||-f==pdf_font_num(k)){
l= font_size(k);
for(i= font_bc(k);i<=font_ec(k);i++){
if(quick_char_exists(k,i)&&char_used(k,i)){
j= xtalloc(1,glw_entry);
j->id= (unsigned)char_index(k,i);
j->wd= divide_scaled_n(char_width(k,i),l,10000.0);
if((glw_entry*)avl_find(fo->fd->gl_tree,j)==NULL){
aa= avl_probe(fo->fd->gl_tree,j);
assert(aa!=NULL);
}else{
xfree(j);
}
}
}
}
}
}


/*:20*//*21:*/
#line 914 "./luatexdir/font/writefont.w"

static void write_cid_charwidth_array(PDF pdf,fo_entry*fo)
{
int i,j;
glw_entry*glyph;
struct avl_traverser t;

assert(fo->cw_objnum==0);
fo->cw_objnum= pdf_create_obj(pdf,obj_type_others,0);
pdf_begin_obj(pdf,fo->cw_objnum,OBJSTM_ALWAYS);
avl_t_init(&t,fo->fd->gl_tree);
glyph= (glw_entry*)avl_t_first(&t,fo->fd->gl_tree);
assert(glyph!=NULL);
i= (int)glyph->id;
pdf_begin_array(pdf);
pdf_add_int(pdf,i);
pdf_begin_array(pdf);
for(;glyph!=NULL;glyph= (glw_entry*)avl_t_next(&t)){
j= glyph->wd;
if(glyph->id> (unsigned)(i+1)){
pdf_end_array(pdf);
pdf_add_int(pdf,glyph->id);
pdf_begin_array(pdf);
j= glyph->wd;
}
if(glyph->id==(unsigned)(i+1))
pdf_out(pdf,' ');

if(j<0){
pdf_out(pdf,'-');
j= -j;
}

pdf_printf(pdf,"%i",(j/10));
if((j%10)!=0)
pdf_printf(pdf,".%i",(j%10));

i= (int)glyph->id;
}
pdf_end_array(pdf);
pdf_end_array(pdf);
pdf_end_obj(pdf);
}

static void destroy_glw_cid_entry(void*pa,void*pb)
{
glw_entry*e= (glw_entry*)pa;
(void)pb;
xfree(e);
}


static void create_cid_fontdictionary(PDF pdf,internal_font_number f)
{
fm_entry*fm= font_map(f);
fo_entry*fo= new_fo_entry();
get_char_range(fo,f);
assert(fo->last_char>=fo->first_char);
fo->fm= fm;
fo->fo_objnum= pdf_font_num(f);
fo->tex_font= f;
create_cid_fontdescriptor(fo,f);
mark_cid_subset_glyphs(fo,f);
if(is_subsetted(fo->fm)){





make_subset_tag(fo->fd);
}
write_cid_charwidth_array(pdf,fo);
write_fontdescriptor(pdf,fo->fd);

write_cid_fontdictionary(pdf,fo,f);
if(fo->fd){
if(fo->fd->gl_tree){
avl_destroy(fo->fd->gl_tree,destroy_glw_cid_entry);
}
xfree(fo->fd);
}
xfree(fo);
}

/*:21*//*22:*/
#line 998 "./luatexdir/font/writefont.w"

void write_cid_fontdictionary(PDF pdf,fo_entry*fo,internal_font_number f)
{
int i;

fo->tounicode_objnum= write_cid_tounicode(pdf,fo,f);

pdf_begin_obj(pdf,fo->fo_objnum,OBJSTM_ALWAYS);
pdf_begin_dict(pdf);
pdf_dict_add_name(pdf,"Type","Font");
pdf_dict_add_name(pdf,"Subtype","Type0");
pdf_dict_add_name(pdf,"Encoding","Identity-H");
pdf_dict_add_fontname(pdf,"BaseFont",fo->fd);
i= pdf_create_obj(pdf,obj_type_others,0);
pdf_add_name(pdf,"DescendantFonts");
pdf_begin_array(pdf);
pdf_add_ref(pdf,i);
pdf_end_array(pdf);

if(fo->tounicode_objnum!=0)
pdf_dict_add_ref(pdf,"ToUnicode",(int)fo->tounicode_objnum);
pdf_end_dict(pdf);
pdf_end_obj(pdf);

pdf_begin_obj(pdf,i,OBJSTM_ALWAYS);
pdf_begin_dict(pdf);
pdf_dict_add_name(pdf,"Type","Font");
if(is_opentype(fo->fm)||is_type1(fo->fm)){
pdf_dict_add_name(pdf,"Subtype","CIDFontType0");
}else{
pdf_dict_add_name(pdf,"Subtype","CIDFontType2");
pdf_dict_add_name(pdf,"CIDToGIDMap","Identity");
}
pdf_dict_add_fontname(pdf,"BaseFont",fo->fd);
pdf_dict_add_ref(pdf,"FontDescriptor",(int)fo->fd->fd_objnum);
pdf_dict_add_ref(pdf,"W",(int)fo->cw_objnum);
pdf_add_name(pdf,"CIDSystemInfo");
pdf_begin_dict(pdf);
pdf_dict_add_string(pdf,"Registry",
(font_cidregistry(f)?font_cidregistry(f):"Adobe"));
pdf_dict_add_string(pdf,"Ordering",
(font_cidordering(f)?font_cidordering(f):
"Identity"));
pdf_dict_add_int(pdf,"Supplement",(int)font_cidsupplement(f));
pdf_end_dict(pdf);


#if 0
if(pdf_font_attr(fo->tex_font)!=get_nullstr()){
pdf_out(pdf,'\n');
pdf_print(pdf_font_attr(fo->tex_font));
pdf_out(pdf,'\n');
}
#endif
pdf_end_dict(pdf);
pdf_end_obj(pdf);
}/*:22*/
