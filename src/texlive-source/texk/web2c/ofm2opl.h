void parsearguments (void);
void initialize (void);
integer zwidthindex (chartype c);
#define widthindex(c) zwidthindex((chartype) (c))
integer zheightindex (chartype c);
#define heightindex(c) zheightindex((chartype) (c))
integer zdepthindex (chartype c);
#define depthindex(c) zdepthindex((chartype) (c))
integer zitalicindex (chartype c);
#define italicindex(c) zitalicindex((chartype) (c))
integer ztag (chartype c);
#define tag(c) ztag((chartype) (c))
void zsetnotag (chartype c);
#define setnotag(c) zsetnotag((chartype) (c))
void zcheckunused (chartype c);
#define checkunused(c) zcheckunused((chartype) (c))
boolean zctag (chartype c);
#define ctag(c) zctag((chartype) (c))
void zsetnoctag (chartype c);
#define setnoctag(c) zsetnoctag((chartype) (c))
integer znorepeats (chartype c);
#define norepeats(c) znorepeats((chartype) (c))
integer zcharparam (chartype c,integer i);
#define charparam(c, i) zcharparam((chartype) (c), (integer) (i))
integer zrremainder (chartype c);
#define rremainder(c) zrremainder((chartype) (c))
integer zligstep (chartype c);
#define ligstep(c) zligstep((chartype) (c))
integer zexten (chartype c);
#define exten(c) zexten((chartype) (c))
integer zlskipbyte (integer c);
#define lskipbyte(c) zlskipbyte((integer) (c))
void zsetlskipbyte (integer c,integer newc);
#define setlskipbyte(c, newc) zsetlskipbyte((integer) (c), (integer) (newc))
integer zlnextchar (integer c);
#define lnextchar(c) zlnextchar((integer) (c))
void zsetlnextchar (integer c,chartype newc);
#define setlnextchar(c, newc) zsetlnextchar((integer) (c), (chartype) (newc))
integer zlopbyte (integer c);
#define lopbyte(c) zlopbyte((integer) (c))
void zsetlopbyte (integer c,integer newc);
#define setlopbyte(c, newc) zsetlopbyte((integer) (c), (integer) (newc))
integer zlremainder (integer c);
#define lremainder(c) zlremainder((integer) (c))
void zsetlremainder (integer c,chartype newc);
#define setlremainder(c, newc) zsetlremainder((integer) (c), (chartype) (newc))
void zoutdigs (integer j);
#define outdigs(j) zoutdigs((integer) (j))
void zprintdigs (integer j);
#define printdigs(j) zprintdigs((integer) (j))
void zprintnumber (integer c,integer form);
#define printnumber(c, form) zprintnumber((integer) (c), (integer) (form))
void outln (void);
void left (void);
void right (void);
void zoutBCPL (indextype k);
#define outBCPL(k) zoutBCPL((indextype) (k))
void zoutnumber (integer c,integer form);
#define outnumber(c, form) zoutnumber((integer) (c), (integer) (form))
void zouthex (indextype k,indextype l);
#define outhex(k, l) zouthex((indextype) (k), (indextype) (l))
void zoutchar (integer c);
#define outchar(c) zoutchar((integer) (c))
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
