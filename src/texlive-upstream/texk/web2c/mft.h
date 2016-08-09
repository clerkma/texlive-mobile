void error (void);
void jumpout (void);
void parsearguments (void);
void initialize (void);
void openinput (void);
boolean zinputln (textfile f);
#define inputln(f) zinputln((textfile) (f))
boolean linesdontmatch (void);
void primethechangebuffer (void);
void checkchange (void);
void getline (void);
namepointer lookup (void);
void getnext (void);
void zflushbuffer (eightbits b,boolean percent);
#define flushbuffer(b, percent) zflushbuffer((eightbits) (b), (boolean) (percent))
void breakout (void);
void zoutstr (namepointer p);
#define outstr(p) zoutstr((namepointer) (p))
void zoutname (namepointer p);
#define outname(p) zoutname((namepointer) (p))
void zoutmacandname (ASCIIcode n,namepointer p);
#define outmacandname(n, p) zoutmacandname((ASCIIcode) (n), (namepointer) (p))
void zcopy (integer firstloc);
#define copy(firstloc) zcopy((integer) (firstloc))
void dothetranslation (void);
