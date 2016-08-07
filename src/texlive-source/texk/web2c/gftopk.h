void parsearguments (void);
void initialize (void);
void opengffile (void);
void openpkfile (void);
integer gfbyte (void);
integer gfsignedquad (void);
void zpkhalfword (integer a);
#define pkhalfword(a) zpkhalfword((integer) (a))
void zpkthreebytes (integer a);
#define pkthreebytes(a) zpkthreebytes((integer) (a))
void zpkword (integer a);
#define pkword(a) zpkword((integer) (a))
void zpknyb (integer a);
#define pknyb(a) zpknyb((integer) (a))
integer gflength (void);
void zmovetobyte (integer n);
#define movetobyte(n) zmovetobyte((integer) (n))
void packandsendcharacter (void);
void rowoverflow (void);
void convertgffile (void);
