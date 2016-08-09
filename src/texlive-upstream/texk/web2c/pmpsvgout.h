/*3:*/
#line 78 "./psvgout.w"

#ifndef MPSVGOUT_H
#define MPSVGOUT_H 1
#include "pmplib.h"
#include "pmpmp.h"
#include "pmplibps.h"
typedef struct svgout_data_struct{
/*6:*/
#line 111 "./psvgout.w"

size_t file_offset;

/*:6*//*12:*/
#line 163 "./psvgout.w"

char*buf;
unsigned loc;
unsigned bufsize;

/*:12*//*20:*/
#line 297 "./psvgout.w"

int level;

/*:20*//*27:*/
#line 384 "./psvgout.w"

integer dx;
integer dy;

/*:27*//*56:*/
#line 1157 "./psvgout.w"

int clipid;

/*:56*/
#line 85 "./psvgout.w"

}svgout_data_struct;
/*4:*/
#line 90 "./psvgout.w"

void mp_svg_backend_initialize(MP mp);
void mp_svg_backend_free(MP mp);

/*:4*//*60:*/
#line 1207 "./psvgout.w"

int mp_svg_gr_ship_out(mp_edge_object*hh,int prologues,int standalone);

/*:60*/
#line 87 "./psvgout.w"

#endif

/*:3*/
