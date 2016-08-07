void error (void);
void parsearguments (void);
void initialize (void);
void openinput (void);
boolean zinputln (textfile f);
#define inputln(f) zinputln((textfile) (f))
void zprintid (namepointer p);
#define printid(p) zprintid((namepointer) (p))
namepointer zidlookup (eightbits t);
#define idlookup(t) zidlookup((eightbits) (t))
namepointer zmodlookup (sixteenbits l);
#define modlookup(l) zmodlookup((sixteenbits) (l))
namepointer zprefixlookup (sixteenbits l);
#define prefixlookup(l) zprefixlookup((sixteenbits) (l))
void zstoretwobytes (sixteenbits x);
#define storetwobytes(x) zstoretwobytes((sixteenbits) (x))
void zpushlevel (namepointer p);
#define pushlevel(p) zpushlevel((namepointer) (p))
void poplevel (void);
sixteenbits getoutput (void);
void flushbuffer (void);
void zappval (integer v);
#define appval(v) zappval((integer) (v))
void zsendout (eightbits t,sixteenbits v);
#define sendout(t, v) zsendout((eightbits) (t), (sixteenbits) (v))
void zsendsign (integer v);
#define sendsign(v) zsendsign((integer) (v))
void zsendval (integer v);
#define sendval(v) zsendval((integer) (v))
void sendtheoutput (void);
boolean linesdontmatch (void);
void primethechangebuffer (void);
void checkchange (void);
void getline (void);
eightbits zcontrolcode (ASCIIcode c);
#define controlcode(c) zcontrolcode((ASCIIcode) (c))
eightbits skipahead (void);
void skipcomment (void);
eightbits getnext (void);
void zscannumeric (namepointer p);
#define scannumeric(p) zscannumeric((namepointer) (p))
void zscanrepl (eightbits t);
#define scanrepl(t) zscanrepl((eightbits) (t))
void zdefinemacro (eightbits t);
#define definemacro(t) zdefinemacro((eightbits) (t))
void scanmodule (void);
