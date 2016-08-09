void parsearguments (void);
void initialize (void);
ASCIIcode zgetASCII (textchar c);
#define getASCII(c) zgetASCII((textchar) (c))
void initpatterntrie (void);
triepointer firstfit (void);
void zunpack (triepointer s);
#define unpack(s) zunpack((triepointer) (s))
optype znewtrieop (valtype v,dottype d,optype n);
#define newtrieop(v, d, n) znewtrieop((valtype) (v), (dottype) (d), (optype) (n))
void zinsertpattern (valtype val,dottype dot);
#define insertpattern(val, dot) zinsertpattern((valtype) (val), (dottype) (dot))
void initcounttrie (void);
triecpointer firstcfit (void);
void zunpackc (triecpointer b);
#define unpackc(b) zunpackc((triecpointer) (b))
triecpointer zinsertcpat (wordindex fpos);
#define insertcpat(fpos) zinsertcpat((wordindex) (fpos))
void readtranslate (void);
void zfindletters (triepointer b,dottype i);
#define findletters(b, i) zfindletters((triepointer) (b), (dottype) (i))
void ztraversecounttrie (triecpointer b,dottype i);
#define traversecounttrie(b, i) ztraversecounttrie((triecpointer) (b), (dottype) (i))
void collectcounttrie (void);
triepointer zdeletepatterns (triepointer s);
#define deletepatterns(s) zdeletepatterns((triepointer) (s))
void deletebadpatterns (void);
void zoutputpatterns (triepointer s,dottype patlen);
#define outputpatterns(s, patlen) zoutputpatterns((triepointer) (s), (dottype) (patlen))
void readword (void);
void hyphenate (void);
void changedots (void);
void outputhyphenatedword (void);
void doword (void);
void dodictionary (void);
void readpatterns (void);
