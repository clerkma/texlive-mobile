/*4:*/
#line 126 "./pmpxout.w"

#ifndef MPXOUT_H
#define MPXOUT_H 1
typedef enum{
mpx_tex_mode= 0,
mpx_troff_mode= 1
}mpx_modes;
typedef struct mpx_data*MPX;
/*159:*/
#line 2548 "./pmpxout.w"

typedef char*(*mpx_file_finder)(MPX,const char*,const char*,int);
enum mpx_filetype{
mpx_tfm_format,
mpx_vf_format,
mpx_trfontmap_format,
mpx_trcharadj_format,
mpx_desc_format,
mpx_fontdesc_format,
mpx_specchar_format
};

/*:159*//*227:*/
#line 4132 "./pmpxout.w"

typedef struct mpx_options{
int mode;
char*cmd;
char*mptexpre;
char*mpname;
char*mpxname;
char*banner;
int debug;
mpx_file_finder find_file;
}mpx_options;
int mpx_makempx(mpx_options*mpxopt);
int mpx_run_dvitomp(mpx_options*mpxopt);


/*:227*/
#line 134 "./pmpxout.w"

#endif

/*:4*/
