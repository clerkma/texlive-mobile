/*1:*/
#line 21 "./luatexdir/image/pdftoepdf.w"


#define __STDC_FORMAT_MACROS 

#include "image/epdf.h"






extern void md5(Guchar*msg,int msgLen,Guchar*digest);

static GBool isInit= gFalse;



static avl_table*PdfDocumentTree= NULL;



static int CompPdfDocument(const void*pa,const void*pb,void*)
{
return strcmp(((const PdfDocument*)pa)->file_path,((const PdfDocument*)pb)->file_path);
}



static PdfDocument*findPdfDocument(char*file_path)
{
PdfDocument*pdf_doc,tmp;
if(file_path==NULL){
normal_error("pdf backend","empty filename when loading pdf file");
}else if(PdfDocumentTree==NULL){
return NULL;
}
tmp.file_path= file_path;
pdf_doc= (PdfDocument*)avl_find(PdfDocumentTree,&tmp);
return pdf_doc;
}

#define PDF_CHECKSUM_SIZE 32

static char*get_file_checksum(const char*a,file_error_mode fe)
{
struct stat finfo;
char*ck= NULL;
if(stat(a,&finfo)==0){
off_t size= finfo.st_size;
time_t mtime= finfo.st_mtime;
ck= (char*)malloc(PDF_CHECKSUM_SIZE);
if(ck==NULL)
formatted_error("pdf inclusion","out of memory while processing '%s'",a);
snprintf(ck,PDF_CHECKSUM_SIZE,"%"PRIu64"_%"PRIu64,(uint64_t)size,(uint64_t)mtime);
}else{
switch(fe){
case FE_FAIL:
formatted_error("pdf inclusion","could not stat() file '%s'",a);
break;
case FE_RETURN_NULL:
if(ck!=NULL)
free(ck);
ck= NULL;
break;
default:
assert(0);
}
}
return ck;
}


static char*get_stream_checksum(const char*str,unsigned long long str_size){


unsigned long hash;
char*ck= NULL;
unsigned int i;
hash= 5381;
ck= (char*)malloc(STRSTREAM_CHECKSUM_SIZE+1);
if(ck==NULL)
normal_error("pdf inclusion","out of memory while processing a memstream");
for(i= 0;i<(unsigned int)(str_size);i++){
hash= ((hash<<5)+hash)+str[i];
}
snprintf(ck,STRSTREAM_CHECKSUM_SIZE+1,"%lx",hash);
ck[STRSTREAM_CHECKSUM_SIZE]= '\0';
return ck;
}







PdfDocument*refPdfDocument(const char*file_path,file_error_mode fe)
{
char*checksum,*path_copy;
PdfDocument*pdf_doc;
PDFDoc*doc= NULL;
GooString*docName= NULL;
int new_flag= 0;
if((checksum= get_file_checksum(file_path,fe))==NULL){
return(PdfDocument*)NULL;
}
path_copy= xstrdup(file_path);
if((pdf_doc= findPdfDocument(path_copy))==NULL){
new_flag= 1;
pdf_doc= new PdfDocument;
pdf_doc->file_path= path_copy;
pdf_doc->checksum= checksum;
pdf_doc->doc= NULL;
pdf_doc->inObjList= NULL;
pdf_doc->ObjMapTree= NULL;
pdf_doc->occurences= 0;
pdf_doc->pc= 0;
}else{
if(strncmp(pdf_doc->checksum,checksum,PDF_CHECKSUM_SIZE)!=0){
formatted_error("pdf inclusion","file has changed '%s'",file_path);
}
free(checksum);
free(path_copy);
}
if(pdf_doc->doc==NULL){
docName= new GooString(file_path);
doc= new PDFDoc(docName);
pdf_doc->pc++;

if(!doc->isOk()||!doc->okToPrint()){
switch(fe){
case FE_FAIL:
normal_error("pdf inclusion","reading image failed");
break;
case FE_RETURN_NULL:
delete doc;

if(new_flag==1){
if(pdf_doc->file_path!=NULL)
free(pdf_doc->file_path);
if(pdf_doc->checksum!=NULL)
free(pdf_doc->checksum);
delete pdf_doc;
}
return(PdfDocument*)NULL;
break;
default:
assert(0);
}
}
pdf_doc->doc= doc;
}

if(PdfDocumentTree==NULL)
PdfDocumentTree= avl_create(CompPdfDocument,NULL,&avl_xallocator);
if((PdfDocument*)avl_find(PdfDocumentTree,pdf_doc)==NULL){
avl_probe(PdfDocumentTree,pdf_doc);
}
pdf_doc->occurences++;
return pdf_doc;
}







PdfDocument*refMemStreamPdfDocument(char*docstream,unsigned long long streamsize,const char*file_id)
{
char*checksum;
char*file_path;
PdfDocument*pdf_doc;
PDFDoc*doc= NULL;
Object obj;
MemStream*docmemstream= NULL;

size_t cnt= 0;
checksum= get_stream_checksum(docstream,streamsize);
cnt= strlen(file_id);
assert(cnt> 0&&cnt<STREAM_FILE_ID_LEN);
file_path= (char*)malloc(cnt+STREAM_URI_LEN+STRSTREAM_CHECKSUM_SIZE+1);
assert(file_path!=NULL);
strcpy(file_path,STREAM_URI);
strcat(file_path,file_id);
strcat(file_path,checksum);
file_path[cnt+STREAM_URI_LEN+STRSTREAM_CHECKSUM_SIZE]= '\0';
if((pdf_doc= findPdfDocument(file_path))==NULL){

pdf_doc= new PdfDocument;
pdf_doc->file_path= file_path;
pdf_doc->checksum= checksum;
pdf_doc->doc= NULL;
pdf_doc->inObjList= NULL;
pdf_doc->ObjMapTree= NULL;
pdf_doc->occurences= 0;
pdf_doc->pc= 0;
}else{

if(strncmp(pdf_doc->checksum,checksum,STRSTREAM_CHECKSUM_SIZE)!=0){
formatted_error("pdf inclusion","stream has changed '%s'",file_path);
}
free(file_path);
free(checksum);
}
if(pdf_doc->doc==NULL){
docmemstream= new MemStream(docstream,0,streamsize,obj.initNull());
doc= new PDFDoc(docmemstream);
pdf_doc->pc++;
if(!doc->isOk()||!doc->okToPrint()){
normal_error("pdf inclusion","reading pdf Stream failed");
}
pdf_doc->doc= doc;
}

if(PdfDocumentTree==NULL)
PdfDocumentTree= avl_create(CompPdfDocument,NULL,&avl_xallocator);
if((PdfDocument*)avl_find(PdfDocumentTree,pdf_doc)==NULL){
avl_probe(PdfDocumentTree,pdf_doc);
}
pdf_doc->occurences++;
return pdf_doc;
}






struct ObjMap{
Ref in;
int out_num;
};

static int CompObjMap(const void*pa,const void*pb,void*)
{
const Ref*a= &(((const ObjMap*)pa)->in);
const Ref*b= &(((const ObjMap*)pb)->in);
if(a->num> b->num)
return 1;
else if(a->num<b->num)
return-1;
else if(a->gen==b->gen)
return 0;
else if(a->gen<b->gen)
return-1;
return 1;
}

static ObjMap*findObjMap(PdfDocument*pdf_doc,Ref in)
{
ObjMap*obj_map,tmp;
if(pdf_doc->ObjMapTree==NULL)
return NULL;
tmp.in= in;
obj_map= (ObjMap*)avl_find(pdf_doc->ObjMapTree,&tmp);
return obj_map;
}

static void addObjMap(PdfDocument*pdf_doc,Ref in,int out_num)
{
ObjMap*obj_map= NULL;
if(pdf_doc->ObjMapTree==NULL)
pdf_doc->ObjMapTree= avl_create(CompObjMap,NULL,&avl_xallocator);
obj_map= new ObjMap;
obj_map->in= in;
obj_map->out_num= out_num;
avl_probe(pdf_doc->ObjMapTree,obj_map);
}












static int addInObj(PDF pdf,PdfDocument*pdf_doc,Ref ref)
{
ObjMap*obj_map;
InObj*p,*q,*n;
if(ref.num==0){
normal_error("pdf inclusion","reference to invalid object (broken pdf)");
}
if((obj_map= findObjMap(pdf_doc,ref))!=NULL)
return obj_map->out_num;
n= new InObj;
n->ref= ref;
n->next= NULL;
n->num= pdf_create_obj(pdf,obj_type_others,0);
addObjMap(pdf_doc,ref,n->num);
if(pdf_doc->inObjList==NULL){
pdf_doc->inObjList= n;
}else{





for(p= pdf_doc->inObjList;p!=NULL;p= p->next)
q= p;
q->next= n;
}
return n->num;
}












static pdffloat conv_double_to_pdffloat(double n)
{
pdffloat a;
a.e= 6;
a.m= i64round(n*ten_pow[a.e]);
return a;
}

static void copyObject(PDF,PdfDocument*,Object*);

void copyReal(PDF pdf,double d)
{
if(pdf->cave)
pdf_out(pdf,' ');
print_pdffloat(pdf,conv_double_to_pdffloat(d));
pdf->cave= true;
}

static void copyString(PDF pdf,GooString*string)
{
char*p;
unsigned char c;
size_t i,l;
p= string->getCString();
l= (size_t)string->getLength();
if(pdf->cave)
pdf_out(pdf,' ');
if(strlen(p)==l){
pdf_out(pdf,'(');
for(;*p!=0;p++){
c= (unsigned char)*p;
if(c=='('||c==')'||c=='\\')
pdf_printf(pdf,"\\%c",c);
else if(c<0x20||c> 0x7F)
pdf_printf(pdf,"\\%03o",(int)c);
else
pdf_out(pdf,c);
}
pdf_out(pdf,')');
}else{
pdf_out(pdf,'<');
for(i= 0;i<l;i++){
c= (unsigned char)string->getChar(i);
pdf_printf(pdf,"%.2x",(int)c);
}
pdf_out(pdf,'>');
}
pdf->cave= true;
}

static void copyName(PDF pdf,char*s)
{
pdf_out(pdf,'/');
for(;*s!=0;s++){
if(isdigit(*s)||isupper(*s)||islower(*s)||*s=='_'||
*s=='.'||*s=='-'||*s=='+')
pdf_out(pdf,*s);
else
pdf_printf(pdf,"#%.2X",*s&0xFF);
}
pdf->cave= true;
}

static void copyArray(PDF pdf,PdfDocument*pdf_doc,Array*array)
{
int i,l;
Object obj1;
pdf_begin_array(pdf);
for(i= 0,l= array->getLength();i<l;++i){
array->getNF(i,&obj1);
copyObject(pdf,pdf_doc,&obj1);
obj1.free();
}
pdf_end_array(pdf);
}

static void copyDict(PDF pdf,PdfDocument*pdf_doc,Dict*dict)
{
int i,l;
Object obj1;
pdf_begin_dict(pdf);
for(i= 0,l= dict->getLength();i<l;++i){
copyName(pdf,dict->getKey(i));
dict->getValNF(i,&obj1);
copyObject(pdf,pdf_doc,&obj1);
obj1.free();
}
pdf_end_dict(pdf);
}

static void copyStreamStream(PDF pdf,Stream*str)
{
int c,i,len= 1024;
str->reset();
i= len;
while((c= str->getChar())!=EOF){
if(i==len){
pdf_room(pdf,len);
i= 0;
}
pdf_quick_out(pdf,c);
i++;
}
}

static void copyStream(PDF pdf,PdfDocument*pdf_doc,Stream*stream)
{
copyDict(pdf,pdf_doc,stream->getDict());
pdf_begin_stream(pdf);
copyStreamStream(pdf,stream->getUndecodedStream());
pdf_end_stream(pdf);
}

static void copyObject(PDF pdf,PdfDocument*pdf_doc,Object*obj)
{
switch(obj->getType()){
case objBool:
pdf_add_bool(pdf,(int)obj->getBool());
break;
case objInt:
pdf_add_int(pdf,obj->getInt());
break;
case objReal:
copyReal(pdf,obj->getReal());
break;





case objString:
copyString(pdf,obj->getString());
break;
case objName:
copyName(pdf,obj->getName());
break;
case objNull:
pdf_add_null(pdf);
break;
case objArray:
copyArray(pdf,pdf_doc,obj->getArray());
break;
case objDict:
copyDict(pdf,pdf_doc,obj->getDict());
break;
case objStream:
copyStream(pdf,pdf_doc,obj->getStream());
break;
case objRef:
pdf_add_ref(pdf,addInObj(pdf,pdf_doc,obj->getRef()));
break;
case objCmd:
case objError:
case objEOF:
case objNone:
formatted_error("pdf inclusion","type '%s' cannot be copied",obj->getTypeName());
break;
default:

assert(0);
}
}

static void writeRefs(PDF pdf,PdfDocument*pdf_doc)
{
InObj*r,*n;
Object obj1;
XRef*xref;
PDFDoc*doc= pdf_doc->doc;
xref= doc->getXRef();
for(r= pdf_doc->inObjList;r!=NULL;){
xref->fetch(r->ref.num,r->ref.gen,&obj1);
if(obj1.isStream())
pdf_begin_obj(pdf,r->num,OBJSTM_NEVER);
else
pdf_begin_obj(pdf,r->num,2);
copyObject(pdf,pdf_doc,&obj1);
obj1.free();
pdf_end_obj(pdf);
n= r->next;
delete r;
pdf_doc->inObjList= r= n;
}
}



static PDFRectangle*get_pagebox(Page*page,int pagebox_spec)
{
switch(pagebox_spec){
case PDF_BOX_SPEC_MEDIA:
return page->getMediaBox();
break;
case PDF_BOX_SPEC_CROP:
return page->getCropBox();
break;
case PDF_BOX_SPEC_BLEED:
return page->getBleedBox();
break;
case PDF_BOX_SPEC_TRIM:
return page->getTrimBox();
break;
case PDF_BOX_SPEC_ART:
return page->getArtBox();
break;
default:
return page->getMediaBox();
break;
}
}








void flush_pdf_info(image_dict*idict)
{
if(img_keepopen(idict)){
unrefPdfDocument(img_filepath(idict));
}
}













void read_pdf_info(image_dict*idict)
{
PdfDocument*pdf_doc= NULL;
PDFDoc*doc= NULL;
Catalog*catalog;
Page*page;
int rotate;
PDFRectangle*pagebox;
int pdf_major_version_found,pdf_minor_version_found;
float xsize,ysize,xorig,yorig;
if(isInit==gFalse){
if(!(globalParams))
globalParams= new GlobalParams();
globalParams->setErrQuiet(gFalse);
isInit= gTrue;
}
if(img_type(idict)==IMG_TYPE_PDF)
pdf_doc= refPdfDocument(img_filepath(idict),FE_FAIL);
else if(img_type(idict)==IMG_TYPE_PDFMEMSTREAM){
pdf_doc= findPdfDocument(img_filepath(idict));
if(pdf_doc==NULL)
normal_error("pdf inclusion","memstream not initialized");
if(pdf_doc->doc==NULL)
normal_error("pdf inclusion","memstream document is empty");
pdf_doc->occurences++;
}else{
normal_error("pdf inclusion","unknown document");
}
doc= pdf_doc->doc;
catalog= doc->getCatalog();





pdf_major_version_found= doc->getPDFMajorVersion();
pdf_minor_version_found= doc->getPDFMinorVersion();
if((pdf_major_version_found> 1)||(pdf_minor_version_found> img_pdfminorversion(idict))){
const char*msg= "PDF inclusion: found PDF version '%d.%d', but at most version '1.%d' allowed";
if(img_errorlevel(idict)> 0){
formatted_error("pdf inclusion",msg,pdf_major_version_found,pdf_minor_version_found,img_pdfminorversion(idict));
}else{
formatted_warning("pdf inclusion",msg,pdf_major_version_found,pdf_minor_version_found,img_pdfminorversion(idict));
}
}
img_totalpages(idict)= catalog->getNumPages();
if(img_pagename(idict)){

GooString name(img_pagename(idict));
LinkDest*link= doc->findDest(&name);
if(link==NULL||!link->isOk())
formatted_error("pdf inclusion","invalid destination '%s'",img_pagename(idict));
Ref ref= link->getPageRef();
img_pagenum(idict)= catalog->findPage(ref.num,ref.gen);
if(img_pagenum(idict)==0)
formatted_error("pdf inclusion","destination is not a page '%s'",img_pagename(idict));
delete link;
}else{

if(img_pagenum(idict)<=0
||img_pagenum(idict)> img_totalpages(idict))
formatted_error("pdf inclusion","required page '%i' does not exist",(int)img_pagenum(idict));
}

page= catalog->getPage(img_pagenum(idict));

pagebox= get_pagebox(page,img_pagebox(idict));
if(pagebox->x2> pagebox->x1){
xorig= pagebox->x1;
xsize= pagebox->x2-pagebox->x1;
}else{
xorig= pagebox->x2;
xsize= pagebox->x1-pagebox->x2;
}
if(pagebox->y2> pagebox->y1){
yorig= pagebox->y1;
ysize= pagebox->y2-pagebox->y1;
}else{
yorig= pagebox->y2;
ysize= pagebox->y1-pagebox->y2;
}

img_xsize(idict)= bp2sp(xsize);
img_ysize(idict)= bp2sp(ysize);
img_xorig(idict)= bp2sp(xorig);
img_yorig(idict)= bp2sp(yorig);



rotate= page->getRotate();
switch(((rotate%360)+360)%360){
case 0:
img_rotation(idict)= 0;
break;
case 90:
img_rotation(idict)= 3;
break;
case 180:
img_rotation(idict)= 2;
break;
case 270:
img_rotation(idict)= 1;
break;
default:
formatted_warning("pdf inclusion","/Rotate parameter in PDF file not multiple of 90 degrees");
}

if(page->getGroup()!=NULL)
img_set_group(idict);
















if(!img_keepopen(idict)){
unrefPdfDocument(img_filepath(idict));
}
}






void write_epdf(PDF pdf,image_dict*idict,int suppress_optional_info)
{
PdfDocument*pdf_doc= NULL;
PDFDoc*doc= NULL;
Catalog*catalog;
Page*page;
Ref*pageref;
Dict*pageDict;
Object obj1,contents,pageobj,pagesobj1,pagesobj2,*op1,*op2,*optmp;
PDFRectangle*pagebox;
int i,l;
double bbox[4];

const char*pagedictkeys[]= {
"Group","LastModified","Metadata","PieceInfo","Resources","SeparationInfo",NULL
};

if(img_type(idict)==IMG_TYPE_PDF){
pdf_doc= refPdfDocument(img_filepath(idict),FE_FAIL);
}else if(img_type(idict)==IMG_TYPE_PDFMEMSTREAM){
pdf_doc= findPdfDocument(img_filepath(idict));
pdf_doc->occurences++;
}else{
normal_error("pdf inclusion","unknown document");
}
doc= pdf_doc->doc;
catalog= doc->getCatalog();
page= catalog->getPage(img_pagenum(idict));
pageref= catalog->getPageRef(img_pagenum(idict));
doc->getXRef()->fetch(pageref->num,pageref->gen,&pageobj);
pageDict= pageobj.getDict();

pdf_begin_obj(pdf,img_objnum(idict),OBJSTM_NEVER);
pdf_begin_dict(pdf);
pdf_dict_add_name(pdf,"Type","XObject");
pdf_dict_add_name(pdf,"Subtype","Form");
if(img_attr(idict)!=NULL&&strlen(img_attr(idict))> 0){
pdf_printf(pdf,"\n%s\n",img_attr(idict));
}
pdf_dict_add_int(pdf,"FormType",1);

pdf_dict_add_img_filename(pdf,idict);
if((suppress_optional_info&4)==0){
pdf_dict_add_int(pdf,"PTEX.PageNumber",(int)img_pagenum(idict));
}
if((suppress_optional_info&8)==0){
doc->getDocInfoNF(&obj1);
if(obj1.isRef()){

pdf_dict_add_ref(pdf,"PTEX.InfoDict",addInObj(pdf,pdf_doc,obj1.getRef()));
}
obj1.free();
}
if(img_is_bbox(idict)){
bbox[0]= sp2bp(img_bbox(idict)[0]);
bbox[1]= sp2bp(img_bbox(idict)[1]);
bbox[2]= sp2bp(img_bbox(idict)[2]);
bbox[3]= sp2bp(img_bbox(idict)[3]);
}else{

pagebox= get_pagebox(page,img_pagebox(idict));
bbox[0]= pagebox->x1;
bbox[1]= pagebox->y1;
bbox[2]= pagebox->x2;
bbox[3]= pagebox->y2;
}
pdf_add_name(pdf,"BBox");
pdf_begin_array(pdf);
copyReal(pdf,bbox[0]);
copyReal(pdf,bbox[1]);
copyReal(pdf,bbox[2]);
copyReal(pdf,bbox[3]);
pdf_end_array(pdf);




pageDict->lookupNF("Metadata",&obj1);
if(!obj1.isNull()&&!obj1.isRef())
formatted_warning("pdf inclusion","/Metadata must be indirect object");
obj1.free();

for(i= 0;pagedictkeys[i]!=NULL;i++){
pageDict->lookupNF(pagedictkeys[i],&obj1);
if(!obj1.isNull()){
pdf_add_name(pdf,pagedictkeys[i]);

copyObject(pdf,pdf_doc,&obj1);
}
obj1.free();
}






pageDict->lookupNF("Resources",&obj1);
if(obj1.isNull()){
op1= &pagesobj1;
op2= &pagesobj2;
pageDict->lookup("Parent",op1);
while(op1->isDict()){
obj1.free();
op1->dictLookupNF("Resources",&obj1);
if(!obj1.isNull()){
pdf_add_name(pdf,"Resources");
copyObject(pdf,pdf_doc,&obj1);
break;
}
op1->dictLookup("Parent",op2);
optmp= op1;
op1= op2;
op2= optmp;
op2->free();
};
if(!op1->isDict())
formatted_warning("pdf inclusion","Page /Resources missing");
op1->free();
}
obj1.free();

page->getContents(&contents);
if(contents.isStream()){









contents.streamGetDict()->lookup("F",&obj1);
if(!obj1.isNull()){
normal_error("pdf inclusion","unsupported external stream");
}
obj1.free();
contents.streamGetDict()->lookup("Length",&obj1);
pdf_add_name(pdf,"Length");
copyObject(pdf,pdf_doc,&obj1);
obj1.free();
contents.streamGetDict()->lookup("Filter",&obj1);
if(!obj1.isNull()){
pdf_add_name(pdf,"Filter");
copyObject(pdf,pdf_doc,&obj1);
obj1.free();
contents.streamGetDict()->lookup("DecodeParms",&obj1);
if(!obj1.isNull()){
pdf_add_name(pdf,"DecodeParms");
copyObject(pdf,pdf_doc,&obj1);
}
}
obj1.free();
pdf_end_dict(pdf);
pdf_begin_stream(pdf);
copyStreamStream(pdf,contents.getStream()->getUndecodedStream());
pdf_end_stream(pdf);
pdf_end_obj(pdf);
}else if(contents.isArray()){
pdf_dict_add_streaminfo(pdf);
pdf_end_dict(pdf);
pdf_begin_stream(pdf);
for(i= 0,l= contents.arrayGetLength();i<l;++i){
copyStreamStream(pdf,(contents.arrayGet(i,&obj1))->getStream());
obj1.free();
if(i<(l-1)){




pdf_out(pdf,' ');
}
}
pdf_end_stream(pdf);
pdf_end_obj(pdf);
}else{

pdf_dict_add_streaminfo(pdf);
pdf_end_dict(pdf);
pdf_begin_stream(pdf);
pdf_end_stream(pdf);
pdf_end_obj(pdf);
}

writeRefs(pdf,pdf_doc);
contents.free();
pageobj.free();






}



static void deletePdfDocumentPdfDoc(PdfDocument*pdf_doc)
{
InObj*r,*n;

for(r= pdf_doc->inObjList;r!=NULL;r= n){
n= r->next;
delete r;
}
delete pdf_doc->doc;
pdf_doc->doc= NULL;
pdf_doc->pc++;
}

static void destroyPdfDocument(void*pa,void*)
{
PdfDocument*pdf_doc= (PdfDocument*)pa;
deletePdfDocumentPdfDoc(pdf_doc);

}






void unrefPdfDocument(char*file_path)
{
PdfDocument*pdf_doc= findPdfDocument(file_path);
if(pdf_doc->occurences> 0){
pdf_doc->occurences--;
if(pdf_doc->occurences==0){
deletePdfDocumentPdfDoc(pdf_doc);
}
}else{




formatted_warning("pdf inclusion","there can be a mismatch in opening and closing file '%s'",file_path);
}
}






void unrefMemStreamPdfDocument(char*file_id)
{
(void)unrefPdfDocument(file_id);

}






void epdf_free()
{
if(PdfDocumentTree!=NULL)
avl_destroy(PdfDocumentTree,destroyPdfDocument);
PdfDocumentTree= NULL;
if(isInit==gTrue)
delete globalParams;
isInit= gFalse;
}/*:1*/
