void parsearguments (void);
void initialize (void);
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
indextype zffn (indextype h,indextype x,indextype y);
#define ffn(h, x, y) zffn((indextype) (h), (indextype) (x), (indextype) (y))
indextype zeval (indextype x,indextype y);
#define eval(x, y) zeval((indextype) (x), (indextype) (y))
indextype zffn (indextype h,indextype x,indextype y);
#define ffn(h, x, y) zffn((indextype) (h), (indextype) (x), (indextype) (y))
boolean organize (void);
void dosimplethings (void);
void docharacters (void);
void zoutkanji (integer jiscode);
#define outkanji(jiscode) zoutkanji((integer) (jiscode))
boolean zvalidjiscode (integer cx);
#define validjiscode(cx) zvalidjiscode((integer) (cx))
integer zindextojis (integer ix);
#define indextojis(ix) zindextojis((integer) (ix))
integer zjistoindex (integer cx);
#define jistoindex(cx) zjistoindex((integer) (cx))
