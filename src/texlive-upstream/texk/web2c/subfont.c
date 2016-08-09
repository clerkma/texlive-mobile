/*1:*/
#line 21 "./luatexdir/font/subfont.w"



#include "ptexlib.h"
#include <string.h> 

/*:1*//*2:*/
#line 27 "./luatexdir/font/subfont.w"

static struct avl_table*sfd_tree= NULL;

static unsigned char*sfd_buffer= NULL;
static int sfd_size= 0;
static int sfd_curbyte= 0;

#define SFD_BUF_SIZE    SMALL_BUF_SIZE

#define sfd_close()     xfclose(sfd_file, cur_file_name)
#define sfd_open(a)      (sfd_file =  fopen((char *)(a), FOPEN_RBIN_MODE))

#define sfd_read_file() readbinfile(sfd_file,&sfd_buffer,&sfd_size)
#define sfd_getchar()   sfd_buffer[sfd_curbyte++]
#define sfd_eof()      (sfd_curbyte>=sfd_size)


static FILE*sfd_file;
static char sfd_line[SFD_BUF_SIZE];

static subfont_entry*new_subfont_entry(void)
{
int i;
subfont_entry*subfont;
subfont= xtalloc(1,subfont_entry);
subfont->infix= NULL;
for(i= 0;i<256;++i)
subfont->charcodes[i]= -1;
subfont->next= NULL;
return subfont;
}

static sfd_entry*new_sfd_entry(void)
{
sfd_entry*sfd;
sfd= xtalloc(1,sfd_entry);
sfd->name= NULL;
sfd->subfont= NULL;
return sfd;
}

static void destroy_sfd_entry(void*pa,void*pb)
{
subfont_entry*p,*q;
sfd_entry*sfd;
sfd= (sfd_entry*)pa;
(void)pb;
p= sfd->subfont;
while(p!=NULL){
q= p->next;
xfree(p->infix);
xfree(p);
p= q;
}
xfree(sfd->name);
}

static int comp_sfd_entry(const void*pa,const void*pb,void*p)
{
(void)p;
return strcmp(((const sfd_entry*)pa)->name,
((const sfd_entry*)pb)->name);
}

void sfd_free(void)
{
if(sfd_tree!=NULL)
avl_destroy(sfd_tree,destroy_sfd_entry);
}

static void sfd_getline(boolean expect_eof)
{
char*p;
char c;
restart:
if(sfd_eof()){
if(expect_eof){
if(*sfd_line=='#')
*sfd_line= 10;
return;
}else
normal_error("sub font","unexpected end of file");
}
p= sfd_line;
do{
c= (char)sfd_getchar();
append_char_to_buf(c,p,sfd_line,SFD_BUF_SIZE);
}while(c!=10&&!sfd_eof());
append_eol(p,sfd_line,SFD_BUF_SIZE);
if(p-sfd_line<2||*sfd_line=='#')
goto restart;
}

/*:2*//*3:*/
#line 120 "./luatexdir/font/subfont.w"

static sfd_entry*read_sfd(char*sfd_name)
{
void**aa;
sfd_entry*sfd,tmp_sfd;
subfont_entry*sf;

char buf[SMALL_BUF_SIZE],*p;
long int i,j,k;
int n;
int callback_id= 0;
int file_opened= 0;

tmp_sfd.name= sfd_name;
if(sfd_tree==NULL){
sfd_tree= avl_create(comp_sfd_entry,NULL,&avl_xallocator);
assert(sfd_tree!=NULL);
}
sfd= (sfd_entry*)avl_find(sfd_tree,&tmp_sfd);
if(sfd!=NULL)
return sfd;
xfree(sfd_buffer);
sfd_curbyte= 0;
sfd_size= 0;

cur_file_name= luatex_find_file(sfd_name,find_sfd_file_callback);
if(cur_file_name){
callback_id= callback_defined(read_sfd_file_callback);
if(callback_id> 0){
if(!(run_callback(callback_id,"S->bSd",cur_file_name,&file_opened,&sfd_buffer,&sfd_size)&&
file_opened&&sfd_size> 0)){
formatted_warning("ttf font","cannot open SFD file for reading '%s'",cur_file_name);
cur_file_name= NULL;
return NULL;
}
}else{
if(!sfd_open(cur_file_name)){
formatted_warning("ttf font","cannot open SFD file for reading '%s'",cur_file_name);
cur_file_name= NULL;
return NULL;
}
sfd_read_file();
sfd_close();
}
}
tex_printf("{");
tex_printf("%s",cur_file_name);
sfd= new_sfd_entry();
sfd->name= xstrdup(sfd_name);
while(!sfd_eof()){
sfd_getline(true);
if(*sfd_line==10)
break;
sf= new_subfont_entry();
sf->next= sfd->subfont;
sfd->subfont= sf;
sscanf(sfd_line,"%s %n",buf,&n);
sf->infix= xstrdup(buf);
p= sfd_line+n;
k= 0;
read_ranges:
for(;;){
if(*p=='\\'){
sfd_getline(false);
p= sfd_line;
goto read_ranges;
}else if(*p==0)
break;
if(sscanf(p," %li %n",&i,&n)==0)
formatted_error("sub font","invalid token: %s",p);
p+= n;
if(*p==':'){
k= i;
p++;
}else if(*p=='_'){
if(sscanf(p+1," %li %n",&j,&n)==0)
formatted_error("sub font","invalid token: %s",p);
if(i> j||k+(j-i)> 255)
formatted_error("sub font","invalid range: %s",p);
while(i<=j)
sf->charcodes[k++]= i++;
p+= n+1;
}else
sf->charcodes[k++]= i;
}
}
tex_printf("}");
aa= avl_probe(sfd_tree,sfd);
assert(aa!=NULL);
return sfd;
}

/*:3*//*4:*/
#line 212 "./luatexdir/font/subfont.w"

boolean handle_subfont_fm(fm_entry*fm,int mode)
{
size_t l;
char*p,*q,*r;
sfd_entry*sfd;
subfont_entry*sf;
fm_entry*fm2;
char buf[SMALL_BUF_SIZE];
assert(fm->tfm_name!=NULL);
p= fm->tfm_name;
q= strchr(p,'@');
if(q==NULL)
return false;
r= strchr(q+1,'@');
if(r==NULL)
return false;
if(q<=p||r<=q+1
||r-p!=(int)strlen(p)-1)
return false;
l= (size_t)(r-(q+1));
strncpy(buf,q+1,l);
buf[l]= 0;
check_buf(strlen(buf)+4,SMALL_BUF_SIZE);
strcat(buf,".sfd");
sfd= read_sfd(buf);
if(sfd==NULL)
return false;

set_subfont(fm);
xfree(fm->ps_name);

if(fm->pid==-1){
fm->pid= 3;
fm->eid= 1;
}
l= (size_t)(q-p);
for(sf= sfd->subfont;sf!=NULL;sf= sf->next){
strncpy(buf,p,l);
buf[l]= 0;
strcat(buf,sf->infix);
fm2= new_fm_entry();
fm2->tfm_name= xstrdup(buf);
fm2->ff_name= xstrdup(fm->ff_name);
fm2->type= fm->type;
fm2->pid= fm->pid;
fm2->eid= fm->eid;
fm2->subfont= sf;
if(avl_do_entry(fm2,mode)!=0)
delete_fm_entry(fm2);
}
delete_fm_entry(fm);
return true;
}/*:4*/
