/*174:*/
#line 5077 "./ppsout.w"

#ifndef MPLIBPS_H
#define MPLIBPS_H 1
#include "pmplib.h"
/*183:*/
#line 5210 "./ppsout.w"

typedef struct{
double a_val,b_val,c_val,d_val;
}mp_color;

/*:183*//*184:*/
#line 5220 "./ppsout.w"

typedef struct{
double offset;
double*array;
}mp_dash_object;


/*:184*//*189:*/
#line 5302 "./ppsout.w"

#define GRAPHIC_BODY                      \
  int type;                               \
  struct mp_graphic_object * next

typedef struct mp_graphic_object{
GRAPHIC_BODY;
}mp_graphic_object;

typedef struct mp_text_object{
GRAPHIC_BODY;
char*pre_script;
char*post_script;
mp_color color;
unsigned char color_model;
unsigned char size_index;
char*text_p;
size_t text_l;
char*font_name;
double font_dsize;
unsigned int font_n;
double width;
double height;
double depth;
double tx;
double ty;
double txx;
double txy;
double tyx;
double tyy;
}mp_text_object;

typedef struct mp_fill_object{
GRAPHIC_BODY;
char*pre_script;
char*post_script;
mp_color color;
unsigned char color_model;
unsigned char ljoin;
mp_gr_knot path_p;
mp_gr_knot htap_p;
mp_gr_knot pen_p;
double miterlim;
}mp_fill_object;

typedef struct mp_stroked_object{
GRAPHIC_BODY;
char*pre_script;
char*post_script;
mp_color color;
unsigned char color_model;
unsigned char ljoin;
unsigned char lcap;
mp_gr_knot path_p;
mp_gr_knot pen_p;
double miterlim;
mp_dash_object*dash_p;
}mp_stroked_object;

typedef struct mp_clip_object{
GRAPHIC_BODY;
mp_gr_knot path_p;
}mp_clip_object;

typedef struct mp_bounds_object{
GRAPHIC_BODY;
mp_gr_knot path_p;
}mp_bounds_object;

typedef struct mp_special_object{
GRAPHIC_BODY;
char*pre_script;
}mp_special_object;

typedef struct mp_edge_object{
struct mp_graphic_object*body;
struct mp_edge_object*next;
char*filename;
MP parent;
double minx,miny,maxx,maxy;
double width,height,depth,ital_corr;
int charcode;
}mp_edge_object;

/*:189*//*236:*/
#line 6317 "./ppsout.w"

int mp_ps_ship_out(mp_edge_object*hh,int prologues,int procset);

/*:236*//*241:*/
#line 6372 "./ppsout.w"

void mp_gr_toss_objects(mp_edge_object*hh);
void mp_gr_toss_object(mp_graphic_object*p);

/*:241*//*244:*/
#line 6436 "./ppsout.w"

mp_graphic_object*mp_gr_copy_object(MP mp,mp_graphic_object*p);

/*:244*/
#line 5081 "./ppsout.w"

#endif


/*:174*/
