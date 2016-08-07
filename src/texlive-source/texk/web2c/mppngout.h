/*3:*/
#line 78 "./mplibdir/pngout.w"

#ifndef MPPNGOUT_H
#define MPPNGOUT_H 1
#include "cairo.h"
#define PNG_SKIP_SETJMP_CHECK 1
#include "png.h"
#include "mplib.h"
#include "mpmp.h"
#include "mplibps.h"
typedef struct pngout_data_struct{
/*6:*/
#line 109 "./mplibdir/pngout.w"

cairo_surface_t*surface;
cairo_t*cr;

/*:6*//*7:*/
#line 116 "./mplibdir/pngout.w"

integer dx;
integer dy;

/*:7*//*23:*/
#line 417 "./mplibdir/pngout.w"

mp_edge_object**psfonts;
int font_max;
int last_fnum;

/*:23*/
#line 88 "./mplibdir/pngout.w"

}pngout_data_struct;
/*4:*/
#line 93 "./mplibdir/pngout.w"

void mp_png_backend_initialize(MP mp);
void mp_png_backend_free(MP mp);

/*:4*//*30:*/
#line 578 "./mplibdir/pngout.w"

int mp_png_gr_ship_out(mp_edge_object*hh,const char*options,int standalone);

/*:30*/
#line 90 "./mplibdir/pngout.w"

#endif

/*:3*/
