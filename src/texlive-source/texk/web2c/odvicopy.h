void zprintpacket (pcktpointer p);
#define printpacket(p) zprintpacket((pcktpointer) (p))
void zprintfont (fontnumber f);
#define printfont(f) zprintfont((fontnumber) (f))
void printoptions (void);
WEB2C_NORETURN void jumpout (void);
WEB2C_NORETURN void zconfusion (pcktpointer p);
#define confusion(p) zconfusion((pcktpointer) (p))
WEB2C_NORETURN void zoverflow (pcktpointer p,int16u n);
#define overflow(p, n) zoverflow((pcktpointer) (p), (int16u) (n))
WEB2C_NORETURN void badtfm (void);
WEB2C_NORETURN void badfont (void);
WEB2C_NORETURN void baddvi (void);
void parsearguments (void);
void initialize (void);
pcktpointer makepacket (void);
pcktpointer newpacket (void);
void flushpacket (void);
int8odvicopy pcktsbyte (void);
int8u pcktubyte (void);
int16 pcktspair (void);
int16u pcktupair (void);
int24 pcktstrio (void);
int24u pcktutrio (void);
integer pcktsquad (void);
void zpcktfour (integer x);
#define pcktfour(x) zpcktfour((integer) (x))
void zpcktchar (boolean upd,integer ext,integer res);
#define pcktchar(upd, ext, res) zpcktchar((boolean) (upd), (integer) (ext), (integer) (res))
void zpcktunsigned (eightbits o,integer x);
#define pcktunsigned(o, x) zpcktunsigned((eightbits) (o), (integer) (x))
void zpcktsigned (eightbits o,integer x);
#define pcktsigned(o, x) zpcktsigned((eightbits) (o), (integer) (x))
void zmakename (pcktpointer e);
#define makename(e) zmakename((pcktpointer) (e))
widthpointer zmakewidth (integer w);
#define makewidth(w) zmakewidth((integer) (w))
boolean findpacket (void);
void zstartpacket (typeflag t);
#define startpacket(t) zstartpacket((typeflag) (t))
void buildpacket (void);
void readtfmword (void);
void zcheckchecksum (integer c,boolean u);
#define checkchecksum(c, u) zcheckchecksum((integer) (c), (boolean) (u))
void zcheckdesignsize (integer d);
#define checkdesignsize(d) zcheckdesignsize((integer) (d))
void zprinthex (int31 num);
#define printhex(num) zprinthex((int31) (num))
widthpointer zcheckwidth (integer w);
#define checkwidth(w) zcheckwidth((integer) (w))
void loadfont (void);
fontnumber zdefinefont (boolean load);
#define definefont(load) zdefinefont((boolean) (load))
integer dvilength (void);
void zdvimove (integer n);
#define dvimove(n) zdvimove((integer) (n))
int8odvicopy dvisbyte (void);
int8u dviubyte (void);
int16 dvispair (void);
int16u dviupair (void);
int24 dvistrio (void);
int24u dviutrio (void);
integer dvisquad (void);
int31 dviuquad (void);
int31 dvipquad (void);
integer dvipointer (void);
void dvifirstpar (void);
void dvifont (void);
void zdvidofont (boolean second);
#define dvidofont(second) zdvidofont((boolean) (second))
int8u vfubyte (void);
int16u vfupair (void);
int24 vfstrio (void);
int24u vfutrio (void);
integer vfsquad (void);
integer vffix1 (void);
integer vffix2 (void);
integer vffix3 (void);
integer vffix3u (void);
integer vffix4 (void);
int31 vfuquad (void);
int31 vfpquad (void);
int31 vffixp (void);
void vffirstpar (void);
void vffont (void);
void vfdofont (void);
boolean dovf (void);
void inputln (void);
boolean zscankeyword (pcktpointer p,int7 l);
#define scankeyword(p, l) zscankeyword((pcktpointer) (p), (int7) (l))
integer scanint (void);
void scancount (void);
void dialog (void);
void zoutpacket (pcktpointer p);
#define outpacket(p) zoutpacket((pcktpointer) (p))
void zoutfour (integer x);
#define outfour(x) zoutfour((integer) (x))
void zoutchar (boolean upd,integer ext,integer res);
#define outchar(upd, ext, res) zoutchar((boolean) (upd), (integer) (ext), (integer) (res))
void zoutunsigned (eightbits o,integer x);
#define outunsigned(o, x) zoutunsigned((eightbits) (o), (integer) (x))
void zoutsigned (eightbits o,integer x);
#define outsigned(o, x) zoutsigned((eightbits) (o), (integer) (x))
void zoutfntdef (fontnumber f);
#define outfntdef(f) zoutfntdef((fontnumber) (f))
boolean startmatch (void);
void dopre (void);
void dobop (void);
void doeop (void);
void dopush (void);
void dopop (void);
void doxxx (void);
void doright (void);
void dodown (void);
void dowidth (void);
void dorule (void);
void dochar (void);
void dofont (void);
void pcktfirstpar (void);
void dovfpacket (void);
void dodvi (void);
void closefilesandterminate (void);
