void parsearguments (void);
void initialize (void);
void readtfmword (void);
integer zvfread (integer k);
#define vfread(k) zvfread((integer) (k))
integer ztfmwidth (byte c);
#define tfmwidth(c) ztfmwidth((byte) (c))
void zoutdigs (integer j);
#define outdigs(j) zoutdigs((integer) (j))
void zprintdigs (integer j);
#define printdigs(j) zprintdigs((integer) (j))
void zprintoctal (byte c);
#define printoctal(c) zprintoctal((byte) (c))
void outln (void);
void left (void);
void right (void);
void zoutBCPL (indextype k);
#define outBCPL(k) zoutBCPL((indextype) (k))
void zoutoctal (indextype k,indextype l);
#define outoctal(k, l) zoutoctal((indextype) (k), (indextype) (l))
void zoutchar (byte c);
#define outchar(c) zoutchar((byte) (c))
void zoutface (indextype k);
#define outface(k) zoutface((indextype) (k))
void zoutfix (indextype k);
#define outfix(k) zoutfix((indextype) (k))
void zcheckBCPL (indextype k,indextype l);
#define checkBCPL(k, l) zcheckBCPL((indextype) (k), (indextype) (l))
void hashinput (void);
indextype zligf (indextype h,indextype x,indextype y);
#define ligf(h, x, y) zligf((indextype) (h), (indextype) (x), (indextype) (y))
indextype zeval (indextype x,indextype y);
#define eval(x, y) zeval((indextype) (x), (indextype) (y))
indextype zligf (indextype h,indextype x,indextype y);
#define ligf(h, x, y) zligf((indextype) (h), (indextype) (x), (indextype) (y))
boolean zstringbalance (integer k,integer l);
#define stringbalance(k, l) zstringbalance((integer) (k), (integer) (l))
void zoutasfix (integer x);
#define outasfix(x) zoutasfix((integer) (x))
integer zgetbytes (integer k,boolean issigned);
#define getbytes(k, issigned) zgetbytes((integer) (k), (boolean) (issigned))
boolean vfinput (void);
boolean organize (void);
void dosimplethings (void);
boolean zdomap (byte c);
#define domap(c) zdomap((byte) (c))
boolean docharacters (void);
