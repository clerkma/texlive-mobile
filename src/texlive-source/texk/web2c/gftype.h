void parsearguments (void);
void initialize (void);
void opengffile (void);
integer getbyte (void);
integer gettwobytes (void);
integer getthreebytes (void);
integer signedquad (void);
void zprintscaled (integer s);
#define printscaled(s) zprintscaled((integer) (s))
integer zfirstpar (eightbits o);
#define firstpar(o) zfirstpar((eightbits) (o))
boolean dochar (void);
void readpostamble (void);
