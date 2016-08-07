/*1:*/
#line 20 "./luatexdir/lua/luajitstuff.w"

#include "ptexlib.h"
#include "lua/luatex-api.h"
#include "lua/lauxlib_bridge.h"

/*:1*//*2:*/
#line 25 "./luatexdir/lua/luajitstuff.w"

lua_State*Luas= NULL;

int luastate_bytes= 0;
int lua_active= 0;

/*:2*//*3:*/
#line 31 "./luatexdir/lua/luajitstuff.w"

void make_table(lua_State*L,const char*tab,const char*mttab,const char*getfunc,
const char*setfunc)
{

lua_pushstring(L,tab);
lua_newtable(L);
lua_settable(L,-3);

lua_pushstring(L,tab);
lua_gettable(L,-2);

luaL_newmetatable(L,mttab);
lua_pushstring(L,"__index");
lua_pushstring(L,getfunc);
lua_gettable(L,-5);
lua_settable(L,-3);
lua_pushstring(L,"__newindex");
lua_pushstring(L,setfunc);
lua_gettable(L,-5);
lua_settable(L,-3);
lua_setmetatable(L,-2);
lua_pop(L,1);
}

/*:3*//*4:*/
#line 56 "./luatexdir/lua/luajitstuff.w"

static const char*getS(lua_State*L,void*ud,size_t*size)
{
LoadS*ls= (LoadS*)ud;
(void)L;
if(ls->size==0)
return NULL;
*size= ls->size;
ls->size= 0;
return ls->s;
}

/*:4*//*5:*/
#line 68 "./luatexdir/lua/luajitstuff.w"

#if 0 
static void*my_luaalloc(void*ud,void*ptr,size_t osize,size_t nsize)
{
void*ret= NULL;
(void)ud;
if(nsize==0)
free(ptr);
else
ret= realloc(ptr,nsize);
luastate_bytes+= (int)(nsize-osize);
return ret;
}
#endif

/*:5*//*6:*/
#line 83 "./luatexdir/lua/luajitstuff.w"

static int my_luapanic(lua_State*L)
{
(void)L;
fprintf(stderr,"PANIC: unprotected error in call to Lua API (%s)\n",
lua_tostring(L,-1));
return 0;
}

/*:6*//*7:*/
#line 92 "./luatexdir/lua/luajitstuff.w"

void luafunctioncall(int slot)
{
int i;
int stacktop= lua_gettop(Luas);
lua_active++;
lua_rawgeti(Luas,LUA_REGISTRYINDEX,lua_key_index(lua_functions));
lua_gettable(Luas,LUA_REGISTRYINDEX);
lua_rawgeti(Luas,-1,slot);
if(lua_isfunction(Luas,-1)){
int base= lua_gettop(Luas);
lua_pushinteger(Luas,slot);
lua_pushcfunction(Luas,lua_traceback);
lua_insert(Luas,base);
i= lua_pcall(Luas,1,0,base);
lua_remove(Luas,base);
if(i!=0){
lua_gc(Luas,LUA_GCCOLLECT,0);
Luas= luatex_error(Luas,(i==LUA_ERRRUN?0:1));
}
}
lua_settop(Luas,stacktop);
lua_active--;
}

/*:7*//*8:*/
#line 117 "./luatexdir/lua/luajitstuff.w"

static const luaL_Reg lualibs[]= {
{"",luaopen_base},
{"package",luaopen_package},

{"table",luaopen_table},
{"io",open_iolibext},
{"os",luaopen_os},
{"string",luaopen_string},
{"math",luaopen_math},
{"debug",luaopen_debug},
{"unicode",luaopen_unicode},
{"zip",luaopen_zip},
{"bit32",luaopen_bit32},
{"md5",luaopen_md5},
{"lfs",luaopen_lfs},
{"profiler",luaopen_profiler},
{"jit",luaopen_jit},
{"ffi",luaopen_ffi},
{"bit",luaopen_bit},
{NULL,NULL}
};

static const luaL_Reg lualibs_nofenv[]= {
{"lpeg",luaopen_lpeg},
{NULL,NULL}
};

/*:8*//*9:*/
#line 145 "./luatexdir/lua/luajitstuff.w"

static void do_openlibs(lua_State*L)
{
const luaL_Reg*lib= lualibs;
for(;lib->func;lib++){
lua_pushcfunction(L,lib->func);
lua_pushstring(L,lib->name);
lua_call(L,1,0);
}
lib= lualibs_nofenv;
for(;lib->func;lib++){
lua_pushcfunction(L,lib->func);
lua_newtable(L);
lua_setfenv(L,-2);
lua_pushstring(L,lib->name);
lua_call(L,1,0);
}
}

/*:9*//*10:*/
#line 164 "./luatexdir/lua/luajitstuff.w"

static int load_aux(lua_State*L,int status){
if(status==0)
return 1;
else{
lua_pushnil(L);
lua_insert(L,-2);
return 2;
}
}

/*:10*//*11:*/
#line 175 "./luatexdir/lua/luajitstuff.w"

static int luatex_loadfile(lua_State*L){
int status= 0;
const char*fname= luaL_optstring(L,1,NULL);
const char*mode= luaL_optstring(L,2,NULL);
int env= !lua_isnone(L,3);
if(!lua_only&&!fname&&interaction==batch_mode){
lua_pushnil(L);
lua_pushstring(L,"reading from stdin is disabled in batch mode");
return 2;
}
status= luaL_loadfilex(L,fname,mode);
if(status==LUA_OK){
recorder_record_input(fname);
if(env){
lua_pushvalue(L,3);
lua_setupvalue(L,-2,1);
}
}
return load_aux(L,status);
}

/*:11*//*12:*/
#line 197 "./luatexdir/lua/luajitstuff.w"

static int luatex_dofile(lua_State*L){
const char*fname= luaL_optstring(L,1,NULL);
int n= lua_gettop(L);
if(!lua_only&&!fname){
if(interaction==batch_mode){
lua_pushnil(L);
lua_pushstring(L,"reading from stdin is disabled in batch mode");
return 2;
}else{
tprint_nl("lua> ");
}
}
if(luaL_loadfile(L,fname)!=0)lua_error(L);
recorder_record_input(fname);
lua_call(L,0,LUA_MULTRET);
return lua_gettop(L)-n;
}

/*:12*//*13:*/
#line 216 "./luatexdir/lua/luajitstuff.w"

void luainterpreter(void)
{
lua_State*L;

if(jithash_hashname==NULL){

luajittex_choose_hash_function= 0;
jithash_hashname= (char*)xmalloc(strlen("lua51")+1);
jithash_hashname= strcpy(jithash_hashname,"lua51");
}else{
if(strcmp((const char*)jithash_hashname,"lua51")==0){
luajittex_choose_hash_function= 0;
}else if(strcmp((const char*)jithash_hashname,"luajit20")==0){
luajittex_choose_hash_function= 1;
}else{

luajittex_choose_hash_function= 0;
jithash_hashname= strcpy(jithash_hashname,"lua51");
}
}

L= luaL_newstate();

if(L==NULL){
fprintf(stderr,"Can't create the Lua state.\n");
return;
}
lua_atpanic(L,&my_luapanic);

do_openlibs(L);

if(luajiton){
luaJIT_setmode(L,0,LUAJIT_MODE_ENGINE|LUAJIT_MODE_ON);
}
else{
luaJIT_setmode(L,0,LUAJIT_MODE_ENGINE|LUAJIT_MODE_OFF);
}

lua_pushcfunction(L,luatex_dofile);
lua_setglobal(L,"dofile");
lua_pushcfunction(L,luatex_loadfile);
lua_setglobal(L,"loadfile");

luatex_md5_lua_open(L);

open_oslibext(L,safer_option);



open_strlibext(L);
open_lfslibext(L);







if(!nosocket_option){
lua_getglobal(L,"package");
lua_getfield(L,-1,"loaded");
if(!lua_istable(L,-1)){
lua_newtable(L);
lua_setfield(L,-2,"loaded");
lua_getfield(L,-1,"loaded");
}
luaopen_socket_core(L);
lua_setfield(L,-2,"socket.core");
lua_pushnil(L);
lua_setfield(L,-2,"socket");

luaopen_mime_core(L);
lua_setfield(L,-2,"mime.core");
lua_pushnil(L);
lua_setfield(L,-2,"mime");
lua_pop(L,2);

luatex_socketlua_open(L);
}

luaopen_zlib(L);
lua_setglobal(L,"zlib");
luaopen_gzip(L);


luaopen_ff(L);
luaopen_tex(L);
luaopen_token(L);
luaopen_node(L);
luaopen_texio(L);
luaopen_kpse(L);
luaopen_callback(L);
luaopen_lua(L,startup_filename);
luaopen_stats(L);
luaopen_font(L);
luaopen_lang(L);
luaopen_mplib(L);
luaopen_vf(L);



lua_pushcfunction(L,luaopen_pdf);
lua_pushstring(L,"pdf");
lua_call(L,1,0);

if(!lua_only){

lua_pushcfunction(L,luaopen_img);
lua_pushstring(L,"img");
lua_call(L,1,0);
}


lua_pushcfunction(L,luaopen_epdf);
lua_pushstring(L,"epdf");
lua_call(L,1,0);


lua_pushcfunction(L,luaopen_pdfscanner);
lua_pushstring(L,"pdfscanner");
lua_call(L,1,0);

lua_createtable(L,0,0);
lua_setglobal(L,"texconfig");

if(safer_option){

(void)hide_lua_value(L,"os","execute");
(void)hide_lua_value(L,"os","rename");
(void)hide_lua_value(L,"os","remove");
(void)hide_lua_value(L,"io","popen");

luaL_checkstack(L,2,"out of stack space");
lua_getglobal(L,"io");
lua_getfield(L,-1,"open_ro");
lua_setfield(L,-2,"open");
(void)hide_lua_value(L,"io","tmpfile");
(void)hide_lua_value(L,"io","output");
(void)hide_lua_value(L,"lfs","chdir");
(void)hide_lua_value(L,"lfs","lock");
(void)hide_lua_value(L,"lfs","touch");
(void)hide_lua_value(L,"lfs","rmdir");
(void)hide_lua_value(L,"lfs","mkdir");
}


Luas= L;
}

/*:13*//*14:*/
#line 366 "./luatexdir/lua/luajitstuff.w"

int hide_lua_table(lua_State*L,const char*name)
{
int r= 0;
lua_getglobal(L,name);
if(lua_istable(L,-1)){
r= luaL_ref(L,LUA_REGISTRYINDEX);
lua_pushnil(L);
lua_setglobal(L,name);
}
return r;
}

/*:14*//*15:*/
#line 379 "./luatexdir/lua/luajitstuff.w"

void unhide_lua_table(lua_State*L,const char*name,int r)
{
lua_rawgeti(L,LUA_REGISTRYINDEX,r);
lua_setglobal(L,name);
luaL_unref(L,LUA_REGISTRYINDEX,r);
}

/*:15*//*16:*/
#line 387 "./luatexdir/lua/luajitstuff.w"

int hide_lua_value(lua_State*L,const char*name,const char*item)
{
int r= 0;
lua_getglobal(L,name);
if(lua_istable(L,-1)){
lua_getfield(L,-1,item);
r= luaL_ref(L,LUA_REGISTRYINDEX);
lua_pushnil(L);
lua_setfield(L,-2,item);
}
return r;
}

/*:16*//*17:*/
#line 401 "./luatexdir/lua/luajitstuff.w"

void unhide_lua_value(lua_State*L,const char*name,const char*item,int r)
{
lua_getglobal(L,name);
if(lua_istable(L,-1)){
lua_rawgeti(L,LUA_REGISTRYINDEX,r);
lua_setfield(L,-2,item);
luaL_unref(L,LUA_REGISTRYINDEX,r);
}
}

/*:17*//*18:*/
#line 412 "./luatexdir/lua/luajitstuff.w"

int lua_traceback(lua_State*L)
{
lua_getglobal(L,"debug");
if(!lua_istable(L,-1)){
lua_pop(L,1);
return 1;
}
lua_getfield(L,-1,"traceback");
if(!lua_isfunction(L,-1)){
lua_pop(L,2);
return 1;
}
lua_pushvalue(L,1);
lua_pushinteger(L,2);
lua_call(L,2,1);
return 1;
}

/*:18*//*19:*/
#line 431 "./luatexdir/lua/luajitstuff.w"

static void luacall(int p,int nameptr,boolean is_string)
{
LoadS ls;
int i;
size_t ll= 0;
char*lua_id;
char*s= NULL;

if(Luas==NULL){
luainterpreter();
}
lua_active++;
if(is_string){
const char*ss= NULL;
lua_rawgeti(Luas,LUA_REGISTRYINDEX,p);
if(lua_isfunction(Luas,-1)){
int base= lua_gettop(Luas);
lua_checkstack(Luas,1);
lua_pushcfunction(Luas,lua_traceback);
lua_insert(Luas,base);
i= lua_pcall(Luas,0,0,base);
lua_remove(Luas,base);
if(i!=0){
lua_gc(Luas,LUA_GCCOLLECT,0);
Luas= luatex_error(Luas,(i==LUA_ERRRUN?0:1));
}
lua_active--;
return;
}
ss= lua_tolstring(Luas,-1,&ll);
s= xmalloc(ll+1);
memcpy(s,ss,ll+1);
lua_pop(Luas,1);
}else{
int l= 0;
s= tokenlist_to_cstring(p,1,&l);
ll= (size_t)l;
}
ls.s= s;
ls.size= ll;
if(ls.size> 0){
if(nameptr> 0){
int l= 0;
lua_id= tokenlist_to_cstring(nameptr,1,&l);
i= lua_load(Luas,getS,&ls,lua_id);
xfree(lua_id);
}else if(nameptr<0){
lua_id= get_lua_name((nameptr+65536));
if(lua_id!=NULL){
i= lua_load(Luas,getS,&ls,lua_id);
}else{
i= lua_load(Luas,getS,&ls,"=[\\latelua]");
}
}else{
i= lua_load(Luas,getS,&ls,"=[\\latelua]");
}
if(i!=0){
Luas= luatex_error(Luas,(i==LUA_ERRSYNTAX?0:1));
}else{
int base= lua_gettop(Luas);
lua_checkstack(Luas,1);
lua_pushcfunction(Luas,lua_traceback);
lua_insert(Luas,base);
i= lua_pcall(Luas,0,0,base);
lua_remove(Luas,base);
if(i!=0){
lua_gc(Luas,LUA_GCCOLLECT,0);
Luas= luatex_error(Luas,(i==LUA_ERRRUN?0:1));
}
}
xfree(ls.s);
}
lua_active--;
}

/*:19*//*20:*/
#line 507 "./luatexdir/lua/luajitstuff.w"

void late_lua(PDF pdf,halfword p)
{
(void)pdf;
if(late_lua_type(p)==normal){
expand_macros_in_tokenlist(p);
luacall(def_ref,late_lua_name(p),false);
flush_list(def_ref);
}else{
luacall(late_lua_data(p),late_lua_name(p),true);
}
}

/*:20*//*21:*/
#line 520 "./luatexdir/lua/luajitstuff.w"

void luatokencall(int p,int nameptr)
{
LoadS ls;
int i,l;
char*s= NULL;
char*lua_id;
assert(Luas);
l= 0;
lua_active++;
s= tokenlist_to_cstring(p,1,&l);
ls.s= s;
ls.size= (size_t)l;
if(ls.size> 0){
if(nameptr> 0){
lua_id= tokenlist_to_cstring(nameptr,1,&l);
i= lua_load(Luas,getS,&ls,lua_id);
xfree(lua_id);
}else if(nameptr<0){
lua_id= get_lua_name((nameptr+65536));
if(lua_id!=NULL){
i= lua_load(Luas,getS,&ls,lua_id);
}else{
i= lua_load(Luas,getS,&ls,"=[\\directlua]");
}
}else{
i= lua_load(Luas,getS,&ls,"=[\\directlua]");
}
xfree(s);
if(i!=0){
Luas= luatex_error(Luas,(i==LUA_ERRSYNTAX?0:1));
}else{
int base= lua_gettop(Luas);
lua_checkstack(Luas,1);
lua_pushcfunction(Luas,lua_traceback);
lua_insert(Luas,base);
i= lua_pcall(Luas,0,0,base);
lua_remove(Luas,base);
if(i!=0){
lua_gc(Luas,LUA_GCCOLLECT,0);
Luas= luatex_error(Luas,(i==LUA_ERRRUN?0:1));
}
}
}
lua_active--;
}

/*:21*//*22:*/
#line 567 "./luatexdir/lua/luajitstuff.w"

lua_State*luatex_error(lua_State*L,int is_fatal)
{

const_lstring luaerr;
char*err= NULL;
if(lua_type(L,-1)==LUA_TSTRING){
luaerr.s= lua_tolstring(L,-1,&luaerr.l);

err= (char*)xmalloc((unsigned)(luaerr.l+1));
snprintf(err,(luaerr.l+1),"%s",luaerr.s);
last_lua_error= err;
}
if(is_fatal> 0){



normal_error("lua",err);

lua_close(L);
return(lua_State*)NULL;
}else{
normal_warning("lua",err);
return L;
}
}

/*:22*//*23:*/
#line 594 "./luatexdir/lua/luajitstuff.w"

void preset_environment(lua_State*L,const parm_struct*p,const char*s)
{
int i;
assert(L!=NULL);

lua_pushstring(L,s);
lua_gettable(L,LUA_REGISTRYINDEX);
assert(lua_isnil(L,-1));
lua_pop(L,1);
lua_pushstring(L,s);
lua_newtable(L);
for(i= 1,++p;p->name!=NULL;i++,p++){
assert(i==p->idx);
lua_pushstring(L,p->name);
lua_pushinteger(L,p->idx);
lua_settable(L,-3);
}
lua_settable(L,LUA_REGISTRYINDEX);
}

/*:23*//*24:*/
#line 615 "./luatexdir/lua/luajitstuff.w"















/*:24*//*25:*/
#line 630 "./luatexdir/lua/luajitstuff.w"

LUALIB_API void*luaL_testudata(lua_State*L,int ud,const char*tname){
void*p= lua_touserdata(L,ud);
if(p!=NULL){
if(lua_getmetatable(L,ud)){
luaL_getmetatable(L,tname);
if(!lua_rawequal(L,-1,-2))
p= NULL;
lua_pop(L,2);
return p;
}
}
return NULL;
}

/*:25*//*26:*/
#line 645 "./luatexdir/lua/luajitstuff.w"




LUALIB_API void luaL_setfuncs(lua_State*L,const luaL_Reg*l,int nup){

luaL_checkstack(L,nup,"too many upvalues");
for(;l->name!=NULL;l++){
int i;
for(i= 0;i<nup;i++)
lua_pushvalue(L,-nup);
lua_pushcclosure(L,l->func,nup);
lua_setfield(L,-(nup+2),l->name);
}
lua_pop(L,nup);
}

/*:26*//*27:*/
#line 662 "./luatexdir/lua/luajitstuff.w"

LUALIB_API char*luaL_prepbuffsize(luaL_Buffer*B,size_t sz){
lua_State*L= B->L;
if(sz> LUAL_BUFFERSIZE)
luaL_error(L,"buffer too large");
return luaL_prepbuffer(B);
}

/*:27*//*28:*/
#line 670 "./luatexdir/lua/luajitstuff.w"

LUA_API int lua_compare(lua_State*L,int o1,int o2,int op){

int i= 0;
lua_lock(L);



switch(op){
case LUA_OPEQ:i= lua_equal(L,o1,o2);break;
case LUA_OPLT:i= lua_lessthan(L,o1,o2);break;
case LUA_OPLE:i= (lua_lessthan(L,o1,o2)||lua_equal(L,o1,o2));break;
default:luaL_error(L,"invalid option");
}

lua_unlock(L);
return i;
}
/*:28*/
