void parsearguments (void);
void initialize (void);
void opendvifile (void);
void opentfmfile (void);
void readtfmword (void);
integer getbyte (void);
integer signedbyte (void);
integer gettwobytes (void);
integer signedpair (void);
integer getthreebytes (void);
integer signedtrio (void);
integer signedquad (void);
integer dvilength (void);
void zmovetobyte (integer n);
#define movetobyte(n) zmovetobyte((integer) (n))
void zprintfont (integer f);
#define printfont(f) zprintfont((integer) (f))
boolean zinTFM (integer z);
#define inTFM(z) zinTFM((integer) (z))
boolean startmatch (void);
void zdefinefont (integer e);
#define definefont(e) zdefinefont((integer) (e))
void flushtext (void);
void zouttext (ASCIIcode c);
#define outtext(c) zouttext((ASCIIcode) (c))
integer zfirstpar (eightbits o);
#define firstpar(o) zfirstpar((eightbits) (o))
integer zrulepixels (integer x);
#define rulepixels(x) zrulepixels((integer) (x))
boolean zspecialcases (eightbits o,integer p,integer a);
#define specialcases(o, p, a) zspecialcases((eightbits) (o), (integer) (p), (integer) (a))
boolean dopage (void);
void scanbop (void);
void zskippages (boolean bopseen);
#define skippages(bopseen) zskippages((boolean) (bopseen))
void readpostamble (void);
