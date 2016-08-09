void parsearguments (void);
void initialize (void);
void jumpout (void);
void inputln (void);
void opengffile (void);
void opentfmfile (void);
void opendvifile (void);
void readtfmword (void);
integer getbyte (void);
integer gettwobytes (void);
integer getthreebytes (void);
integer signedquad (void);
void zreadfontinfo (integer f,scaled s);
#define readfontinfo(f, s) zreadfontinfo((integer) (f), (scaled) (s))
strnumber makestring (void);
void zfirststring (integer c);
#define firststring(c) zfirststring((integer) (c))
keywordcode interpretxxx (void);
scaled getyyy (void);
void skipnop (void);
void beginname (void);
boolean zmorename (ASCIIcode c);
#define morename(c) zmorename((ASCIIcode) (c))
void endname (void);
void zpackfilename (strnumber n,strnumber a,strnumber e);
#define packfilename(n, a, e) zpackfilename((strnumber) (n), (strnumber) (a), (strnumber) (e))
void startgf (void);
void dviswap (void);
void zdvifour (integer x);
#define dvifour(x) zdvifour((integer) (x))
void zdvifontdef (internalfontnumber f);
#define dvifontdef(f) zdvifontdef((internalfontnumber) (f))
void loadfonts (void);
void ztypeset (eightbits c);
#define typeset(c) ztypeset((eightbits) (c))
void zdviscaled (real x);
#define dviscaled(x) zdviscaled((real) (x))
void zhbox (strnumber s,internalfontnumber f,boolean sendit);
#define hbox(s, f, sendit) zhbox((strnumber) (s), (internalfontnumber) (f), (boolean) (sendit))
void zslantcomplaint (real r);
#define slantcomplaint(r) zslantcomplaint((real) (r))
nodepointer getavail (void);
void znodeins (nodepointer p,nodepointer q);
#define nodeins(p, q) znodeins((nodepointer) (p), (nodepointer) (q))
boolean zoverlap (nodepointer p,nodepointer q);
#define overlap(p, q) zoverlap((nodepointer) (p), (nodepointer) (q))
nodepointer znearestdot (nodepointer p,scaled d0);
#define nearestdot(p, d0) znearestdot((nodepointer) (p), (scaled) (d0))
void zconvert (scaled x,scaled y);
#define convert(x, y) zconvert((scaled) (x), (scaled) (y))
void zdvigoto (scaled x,scaled y);
#define dvigoto(x, y) zdvigoto((scaled) (x), (scaled) (y))
void ztopcoords (nodepointer p);
#define topcoords(p) ztopcoords((nodepointer) (p))
void zbotcoords (nodepointer p);
#define botcoords(p) zbotcoords((nodepointer) (p))
void zrightcoords (nodepointer p);
#define rightcoords(p) zrightcoords((nodepointer) (p))
void zleftcoords (nodepointer p);
#define leftcoords(p) zleftcoords((nodepointer) (p))
boolean zplacelabel (nodepointer p);
#define placelabel(p) zplacelabel((nodepointer) (p))
void dopixels (void);
