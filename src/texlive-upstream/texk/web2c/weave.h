void parsearguments (void);
void error (void);
void jumpout (void);
void initialize (void);
void openinput (void);
boolean zinputln (textfile f);
#define inputln(f) zinputln((textfile) (f))
void zprintid (namepointer p);
#define printid(p) zprintid((namepointer) (p))
void znewxref (namepointer p);
#define newxref(p) znewxref((namepointer) (p))
void znewmodxref (namepointer p);
#define newmodxref(p) znewmodxref((namepointer) (p))
namepointer zidlookup (eightbits t);
#define idlookup(t) zidlookup((eightbits) (t))
namepointer zmodlookup (sixteenbits l);
#define modlookup(l) zmodlookup((sixteenbits) (l))
namepointer zprefixlookup (sixteenbits l);
#define prefixlookup(l) zprefixlookup((sixteenbits) (l))
boolean linesdontmatch (void);
void primethechangebuffer (void);
void checkchange (void);
void resetinput (void);
void getline (void);
eightbits zcontrolcode (ASCIIcode c);
#define controlcode(c) zcontrolcode((ASCIIcode) (c))
void skiplimbo (void);
eightbits skipTeX (void);
eightbits zskipcomment (eightbits bal);
#define skipcomment(bal) zskipcomment((eightbits) (bal))
eightbits getnext (void);
void Pascalxref (void);
void outerxref (void);
void zmodcheck (namepointer p);
#define modcheck(p) zmodcheck((namepointer) (p))
void zflushbuffer (eightbits b,boolean percent,boolean carryover);
#define flushbuffer(b, percent, carryover) zflushbuffer((eightbits) (b), (boolean) (percent), (boolean) (carryover))
void finishline (void);
void breakout (void);
void zoutmod (integer m);
#define outmod(m) zoutmod((integer) (m))
void zoutname (namepointer p);
#define outname(p) zoutname((namepointer) (p))
void copylimbo (void);
eightbits copyTeX (void);
eightbits zcopycomment (eightbits bal);
#define copycomment(bal) zcopycomment((eightbits) (bal))
void zred (sixteenbits j,eightbits k,eightbits c,integer d);
#define red(j, k, c, d) zred((sixteenbits) (j), (eightbits) (k), (eightbits) (c), (integer) (d))
void zsq (sixteenbits j,eightbits k,eightbits c,integer d);
#define sq(j, k, c, d) zsq((sixteenbits) (j), (eightbits) (k), (eightbits) (c), (integer) (d))
void fivecases (void);
void alphacases (void);
textpointer translate (void);
void appcomment (void);
void appoctal (void);
void apphex (void);
void easycases (void);
void zsubcases (namepointer p);
#define subcases(p) zsubcases((namepointer) (p))
void Pascalparse (void);
textpointer Pascaltranslate (void);
void outerparse (void);
void zpushlevel (textpointer p);
#define pushlevel(p) zpushlevel((textpointer) (p))
eightbits getoutput (void);
void outputPascal (void);
void makeoutput (void);
void finishPascal (void);
void zfootnote (sixteenbits flag);
#define footnote(flag) zfootnote((sixteenbits) (flag))
void zunbucket (eightbits d);
#define unbucket(d) zunbucket((eightbits) (d))
void zmodprint (namepointer p);
#define modprint(p) zmodprint((namepointer) (p))
void PhaseI (void);
void PhaseII (void);
