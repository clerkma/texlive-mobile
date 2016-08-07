/*3:*/
#line 24 "./mplibdir/mpstrings.w"

#ifndef MPSTRINGS_H
#define MPSTRINGS_H 1
#include "mplib.h"
#include "mplibps.h"            
#include "mplibsvg.h"           
#include "mpmp.h"               
#include "mppsout.h"            
#include "mpsvgout.h"           
#include "mpmath.h"             
/*4:*/
#line 39 "./mplibdir/mpstrings.w"

void*copy_strings_entry(const void*p);

/*:4*//*8:*/
#line 101 "./mplibdir/mpstrings.w"

extern int mp_xstrcmp(const char*a,const char*b);
extern char*mp_xstrdup(MP mp,const char*s);
extern char*mp_xstrldup(MP mp,const char*s,size_t l);
extern char*mp_strdup(const char*p);
extern char*mp_strldup(const char*p,size_t l);

/*:8*//*13:*/
#line 177 "./mplibdir/mpstrings.w"

extern void mp_initialize_strings(MP mp);
extern void mp_dealloc_strings(MP mp);

/*:13*//*14:*/
#line 185 "./mplibdir/mpstrings.w"

char*mp_str(MP mp,mp_string s);
mp_string mp_rtsl(MP mp,const char*s,size_t l);
mp_string mp_rts(MP mp,const char*s);
mp_string mp_make_string(MP mp);

/*:14*//*18:*/
#line 228 "./mplibdir/mpstrings.w"

#define EXTRA_STRING 500
#define append_char(A) do { \
    str_room(1); \
    *(mp->cur_string+mp->cur_length)= (unsigned char)(A); \
    mp->cur_length++; \
} while (0)
#define str_room(wsize) do { \
    size_t nsize; \
    if ((mp->cur_length+(size_t)wsize) >  mp->cur_string_size) { \
        nsize =  mp->cur_string_size + mp->cur_string_size / 5 + EXTRA_STRING; \
        if (nsize < (size_t)(wsize)) { \
            nsize =  (size_t)wsize + EXTRA_STRING; \
        } \
        mp->cur_string =  (unsigned char *) mp_xrealloc(mp, mp->cur_string, (unsigned)nsize, sizeof(unsigned char)); \
        memset (mp->cur_string+mp->cur_length,0,(nsize-mp->cur_length)); \
        mp->cur_string_size =  nsize; \
    } \
} while (0)


/*:18*//*19:*/
#line 255 "./mplibdir/mpstrings.w"

void mp_reset_cur_string(MP mp);

/*:19*//*21:*/
#line 280 "./mplibdir/mpstrings.w"

#define MAX_STR_REF 127 
#define add_str_ref(A) { if ( (A)->refs < MAX_STR_REF ) ((A)->refs)++; }

/*:21*//*22:*/
#line 286 "./mplibdir/mpstrings.w"

#define delete_str_ref(A) do {  \
    if ( (A)->refs < MAX_STR_REF ) { \
       if ( (A)->refs >  1 ) ((A)->refs)--;  \
       else mp_flush_string(mp, (A)); \
    } \
  } while (0)

/*:22*//*23:*/
#line 294 "./mplibdir/mpstrings.w"

void mp_flush_string(MP mp,mp_string s);

/*:23*//*26:*/
#line 318 "./mplibdir/mpstrings.w"

mp_string mp_intern(MP mp,const char*s);


/*:26*//*27:*/
#line 326 "./mplibdir/mpstrings.w"

mp_string mp_make_string(MP mp);

/*:27*//*29:*/
#line 360 "./mplibdir/mpstrings.w"

integer mp_str_vs_str(MP mp,mp_string s,mp_string t);

/*:29*//*31:*/
#line 371 "./mplibdir/mpstrings.w"

mp_string mp_cat(MP mp,mp_string a,mp_string b);

/*:31*//*33:*/
#line 400 "./mplibdir/mpstrings.w"

mp_string mp_chop_string(MP mp,mp_string s,integer a,integer b);

/*:33*/
#line 34 "./mplibdir/mpstrings.w"
;
#endif

/*:3*/
