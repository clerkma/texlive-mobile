void parsearguments (void);
void initialize (void);
void openpkfile (void);
integer getbyte (void);
integer gettwobytes (void);
integer signedquad (void);
integer getnyb (void);
boolean getbit (void);
void zsendout (boolean repeatcount,integer value);
#define sendout(repeatcount, value) zsendout((boolean) (repeatcount), (integer) (value))
integer pkpackednum (void);
void skipspecials (void);
