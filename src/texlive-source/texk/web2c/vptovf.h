void parsearguments (void);
void initialize (void);
void showerrorcontext (void);
void fillbuffer (void);
void getkeywordchar (void);
void getnext (void);
byte gethex (void);
void skiptoendofitem (void);
void copytoendofitem (void);
void finishtheproperty (void);
void lookup (void);
void zentername (byte v);
#define entername(v) zentername((byte) (v))
void getname (void);
byte getbyte (void);
void getfourbytes (void);
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
void zreadBCPL (headerindex l,byte n);
#define readBCPL(l, n) zreadBCPL((headerindex) (l), (byte) (n))
void zchecktag (byte c);
#define checktag(c) zchecktag((byte) (c))
void zvffix (byte opcode,fixword x);
#define vffix(opcode, x) zvffix((byte) (opcode), (fixword) (x))
void zreadpacket (byte c);
#define readpacket(c) zreadpacket((byte) (c))
void zprintoctal (byte c);
#define printoctal(c) zprintoctal((byte) (c))
boolean zhashinput (indx p,indx c);
#define hashinput(p, c) zhashinput((indx) (p), (indx) (c))
indx zf (indx h,indx x,indx y);
#define f(h, x, y) zf((indx) (h), (indx) (x), (indx) (y))
indx zeval (indx x,indx y);
#define eval(x, y) zeval((indx) (x), (indx) (y))
indx zf (indx h,indx x,indx y);
#define f(h, x, y) zf((indx) (h), (indx) (x), (indx) (y))
void zoutscaled (fixword x);
#define outscaled(x) zoutscaled((fixword) (x))
void zvoutint (integer x);
#define voutint(x) zvoutint((integer) (x))
void paramenter (void);
void vplenter (void);
void nameenter (void);
void readligkern (void);
void readcharinfo (void);
void readinput (void);
void corrandcheck (void);
void vfoutput (void);
