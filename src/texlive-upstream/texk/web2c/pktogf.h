void parsearguments (void);
void initialize (void);
void openpkfile (void);
void opengffile (void);
integer getbyte (void);
integer signedbyte (void);
integer gettwobytes (void);
integer signedpair (void);
integer signedquad (void);
void zgf16 (integer i);
#define gf16(i) zgf16((integer) (i))
void zgf24 (integer i);
#define gf24(i) zgf24((integer) (i))
void zgfquad (integer i);
#define gfquad(i) zgfquad((integer) (i))
integer getnyb (void);
boolean getbit (void);
integer pkpackednum (void);
void skipspecials (void);
