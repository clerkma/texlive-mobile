void parsearguments (void);
void initialize (void);
void showerrorcontext (void);
void fillbuffer (void);
void getkeywordchar (void);
void getnext (void);
bytetype gethex (void);
void skiptoendofitem (void);
void copytoendofitem (void);
void finishtheproperty (void);
void lookup (void);
void zentername (bytetype v);
#define entername(v) zentername((bytetype) (v))
void getname (void);
integer getcharcode (void);
integer getbyte (void);
void getfourbytes (void);
integer getinteger (void);
fixword getfix (void);
pointer zsortin (pointer h,fixword d);
#define sortin(h, d) zsortin((pointer) (h), (fixword) (d))
integer zmincover (pointer h,fixword d);
#define mincover(h, d) zmincover((pointer) (h), (fixword) (d))
fixword zshorten (pointer h,integer m);
#define shorten(h, m) zshorten((pointer) (h), (integer) (m))
void zsetindices (pointer h,fixword d);
#define setindices(h, d) zsetindices((pointer) (h), (fixword) (d))
void junkerror (void);
void zreadfourbytes (headerindex l);
#define readfourbytes(l) zreadfourbytes((headerindex) (l))
void zreadBCPL (headerindex l,bytetype n);
#define readBCPL(l, n) zreadBCPL((headerindex) (l), (bytetype) (n))
void zchecktag (integer c);
#define checktag(c) zchecktag((integer) (c))
void zprintdigs (integer j);
#define printdigs(j) zprintdigs((integer) (j))
void zprintnumber (integer c,integer form);
#define printnumber(c, form) zprintnumber((integer) (c), (integer) (form))
void zvfstoreset (integer x);
#define vfstoreset(x) zvfstoreset((integer) (x))
void zvfoutset (integer x);
#define vfoutset(x) zvfoutset((integer) (x))
void zvfstorefnt (integer x);
#define vfstorefnt(x) zvfstorefnt((integer) (x))
void zvfoutfntdef (integer x);
#define vfoutfntdef(x) zvfoutfntdef((integer) (x))
void zvfoutchar (integer x);
#define vfoutchar(x) zvfoutchar((integer) (x))
void zvffix (bytetype opcode,fixword x);
#define vffix(opcode, x) zvffix((bytetype) (opcode), (fixword) (x))
void zreadpacket (integer c);
#define readpacket(c) zreadpacket((integer) (c))
boolean zhashinput (indx p,indx c);
#define hashinput(p, c) zhashinput((indx) (p), (indx) (c))
indx zf (indx h,indx x,indx y);
#define f(h, x, y) zf((indx) (h), (indx) (x), (indx) (y))
indx zeval (indx x,indx y);
#define eval(x, y) zeval((indx) (x), (indx) (y))
indx zf (indx h,indx x,indx y);
#define f(h, x, y) zf((indx) (h), (indx) (x), (indx) (y))
void zoutint (integer x);
#define outint(x) zoutint((integer) (x))
void zoutscaled (fixword x);
#define outscaled(x) zoutscaled((fixword) (x))
void zvoutint (integer x);
#define voutint(x) zvoutint((integer) (x))
void paramenter (void);
void vplenter (void);
void nameenter (void);
void readligkern (void);
void outputnewinformationofm (void);
void computenewheaderofm (void);
void finishextendedfont (void);
void outputsubfilesizes (void);
void computesubfilesizes (void);
void outputcharacterinfo (void);
void readfontrulelist (void);
void readfontgluelist (void);
void readfontpenaltylist (void);
void readfontmvaluelist (void);
void readfontfvaluelist (void);
void readfontivaluelist (void);
void readrepeatedcharacterinfo (void);
void readligkerncommand (void);
void readcharacterproperty (void);
void readcharinfo (void);
void readinput (void);
void corrandcheck (void);
void vfoutput (void);
