#define OVF2OVP
#include "cpascal.h"
/* 9999 */ 
#define vfsize ( 600000L ) 
#define maxfonts ( 300 ) 
#define vcsize ( 150000L ) 
#define ligsize ( 800000L ) 
#define hashsize ( 130003L ) 
#define hashmult ( 16007 ) 
#define maxchar ( 1114111L ) 
#define xmaxchar ( 1114112L ) 
#define xxmaxchar ( 1114113L ) 
#define xmaxlabel ( 80001L ) 
#define maxstack ( 50 ) 
#define charcodeascii ( 0 ) 
#define charcodehex ( 1 ) 
#define charcodedefault ( 2 ) 
typedef unsigned char byte  ;
typedef integer indextype  ;
typedef integer chartype  ;
typedef integer xchartype  ;
typedef integer xxchartype  ;
typedef integer xxxchartype  ;
typedef integer charcodeformattype  ;
text /* of  byte */ vffile  ;
text /* of  byte */ tfmfile  ;
integer ofmlevel, nco, ncw, npc, nki, nwi, nkf, nwf, nkr, nwr, nkg, nwg, nkp, 
nwp, nkm, nwm, reallf, nlw, neew, lf, lh, bc, ec, nw, nh, nd, ni, nl, nk, ne, 
np, fontdir  ;
boolean ofmon  ;
text vplfile  ;
#define tfm (tfmfilearray + 1001)
byte * tfmfilearray  ;
integer topchar, topwidth, topheight, topdepth, topitalic  ;
integer startptr, checksum, designsize, scheme, family, randomword  ;
integer headerlength, charptr, copies, j  ;
integer ivaluesstart, fvaluesstart, mvaluesstart, rulesstart, gluesstart, 
penaltiesstart  ;
integer ivaluesbase, fvaluesbase, mvaluesbase, rulesbase, gluesbase, 
penaltiesbase  ;
integer charbase, widthbase, heightbase, depthbase, italicbase  ;
integer ligkernbase, kernbase, extenbase, parambase  ;
integer charstart[maxchar + 1]  ;
integer bytesperentry  ;
unsigned char fonttype  ;
byte vf[vfsize + 1]  ;
chartype vc[vcsize + 1]  ;
integer fontnumber[maxfonts + 1]  ;
integer fontstart[maxfonts + 1]  ;
integer fontchars[maxfonts + 1]  ;
integer fontptr  ;
integer packetstart[1114112], packetend[1114112]  ;
boolean packetfound  ;
byte tempbyte  ;
integer regcount  ;
real realdsize  ;
integer pl  ;
integer vfptr  ;
integer vcptr  ;
integer vfcount  ;
integer a  ;
integer l  ;
char * curname  ;
byte b0, b1, b2, b3  ;
integer fontlh  ;
integer fontbc, fontec  ;
integer fontofmlevel, fontextrawords  ;
integer fontkprime, fontj, fontwd  ;
char defaultdirectory[10]  ;
constcstring ASCII04, ASCII10, ASCII14  ;
char ASCIIall[257]  ;
char xchr[256]  ;
constcstring MBLstring, RIstring, RCEstring  ;
constcstring HEX  ;
integer dig[12]  ;
unsigned char level  ;
unsigned char charsonline  ;
boolean perfect  ;
integer i  ;
xchartype c  ;
unsigned char d  ;
indextype k  ;
integer r  ;
unsigned char count  ;
integer startcounter, basecounter, numberentries  ;
integer value  ;
integer gluesubtype, glueargumentkind, gluestretchorder, glueshrinkorder, 
glueargument  ;
struct {
    xchartype cc ;
  integer rr ;
  boolean ischar ;
} labeltable[1114115]  ;
xxchartype labelptr  ;
xxchartype sortptr  ;
xchartype boundarychar  ;
integer bcharlabel  ;
unsigned char activity[ligsize + 1]  ;
integer ai, acti  ;
boolean outputclabels[257]  ;
integer clabelrunner  ;
integer cprime  ;
integer extenchar  ;
integer64 hash[hashsize + 1]  ;
unsigned char classvar[hashsize + 1]  ;
xxchartype ligz[hashsize + 1]  ;
integer hashptr  ;
integer hashlist[hashsize + 1]  ;
integer h, hh  ;
xchartype xligcycle, yligcycle  ;
integer top  ;
integer wstack[maxstack + 1], xstack[maxstack + 1], ystack[maxstack + 1], 
zstack[maxstack + 1]  ;
integer vflimit  ;
byte o  ;
cinttype verbose  ;
charcodeformattype charcodeformat  ;
cstring tfmname  ;
constcstring vfname, vplname  ;

#include "ovf2ovp.h"
void 
parsearguments ( void ) 
{
  
#define noptions ( 4 ) 
  getoptstruct longoptions[noptions + 1]  ;
  integer getoptreturnval  ;
  cinttype optionindex  ;
  integer currentoption  ;
  verbose = false ;
  charcodeformat = charcodedefault ;
  currentoption = 0 ;
  longoptions [currentoption ].name = "help" ;
  longoptions [currentoption ].hasarg = 0 ;
  longoptions [currentoption ].flag = 0 ;
  longoptions [currentoption ].val = 0 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = "version" ;
  longoptions [currentoption ].hasarg = 0 ;
  longoptions [currentoption ].flag = 0 ;
  longoptions [currentoption ].val = 0 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = "verbose" ;
  longoptions [currentoption ].hasarg = 0 ;
  longoptions [currentoption ].flag = addressof ( verbose ) ;
  longoptions [currentoption ].val = 1 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = "charcode-format" ;
  longoptions [currentoption ].hasarg = 1 ;
  longoptions [currentoption ].flag = 0 ;
  longoptions [currentoption ].val = 0 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = 0 ;
  longoptions [currentoption ].hasarg = 0 ;
  longoptions [currentoption ].flag = 0 ;
  longoptions [currentoption ].val = 0 ;
  do {
      getoptreturnval = getoptlongonly ( argc , argv , "" , longoptions , 
    addressof ( optionindex ) ) ;
    if ( getoptreturnval == -1 ) 
    {
      ;
    } 
    else if ( getoptreturnval == 63 ) 
    {
      usage ( "ovf2ovp" ) ;
    } 
    else if ( ( strcmp ( longoptions [optionindex ].name , "help" ) == 0 ) ) 
    {
      usagehelp ( OVF2OVPHELP , nil ) ;
    } 
    else if ( ( strcmp ( longoptions [optionindex ].name , "version" ) == 0 
    ) ) 
    {
      printversionandexit ( "This is OVF2OVP, Version 1.13" , nil , 
      "J. Plaice, Y. Haralambous, D.E. Knuth" , nil ) ;
    } 
    else if ( ( strcmp ( longoptions [optionindex ].name , "charcode-format" 
    ) == 0 ) ) 
    {
      if ( strcmp ( optarg , "ascii" ) == 0 ) 
      charcodeformat = charcodeascii ;
      else if ( strcmp ( optarg , "hex" ) == 0 ) 
      charcodeformat = charcodehex ;
      else
      fprintf ( stderr , "%s%s%c\n",  "Bad character code format " , stringcast (       optarg ) , '.' ) ;
    } 
  } while ( ! ( getoptreturnval == -1 ) ) ;
  if ( ( optind + 1 != argc ) && ( optind + 2 != argc ) && ( optind + 3 != 
  argc ) ) 
  {
    fprintf ( stderr , "%s%s\n",  "ovf2ovp" , ": Need one to three file arguments." ) ;
    usage ( "ovf2ovp" ) ;
  } 
  vfname = cmdline ( optind ) ;
  if ( optind + 2 <= argc ) 
  {
    tfmname = cmdline ( optind + 1 ) ;
  } 
  else {
      
    tfmname = basenamechangesuffix ( vfname , ".ovf" , ".ofm" ) ;
  } 
} 
void 
initialize ( void ) 
{
  integer k  ;
  kpsesetprogramname ( argv [0 ], "ovf2ovp" ) ;
  kpseinitprog ( "VFTOVP" , 0 , nil , nil ) ;
  tfmfilearray = xmallocarray ( byte , 1008 ) ;
  parsearguments () ;
  vffile = kpseopenfile ( vfname , kpseovfformat ) ;
  tfmfile = kpseopenfile ( tfmname , kpseofmformat ) ;
  if ( verbose ) 
  {
    Fputs ( stderr ,  "This is OVF2OVP, Version 1.13" ) ;
    fprintf ( stderr , "%s\n",  versionstring ) ;
  } 
  ofmon = false ;
  ofmlevel = -1 ;
  lf = 0 ;
  lh = 0 ;
  nco = 0 ;
  ncw = 0 ;
  npc = 0 ;
  bc = 0 ;
  ec = 0 ;
  nw = 0 ;
  nh = 0 ;
  nd = 0 ;
  ni = 0 ;
  nl = 0 ;
  nk = 0 ;
  ne = 0 ;
  np = 0 ;
  nki = 0 ;
  nwi = 0 ;
  nkf = 0 ;
  nwf = 0 ;
  nkm = 0 ;
  nwm = 0 ;
  reallf = 0 ;
  nkr = 0 ;
  nwr = 0 ;
  nkg = 0 ;
  nwg = 0 ;
  nkp = 0 ;
  nwp = 0 ;
  fontdir = 0 ;
  if ( optind + 3 > argc ) 
  {
    vplfile = stdout ;
  } 
  else {
      
    vplname = extendfilename ( cmdline ( optind + 2 ) , "ovp" ) ;
    rewrite ( vplfile , vplname ) ;
  } 
  ASCII04 = "  !\"#$%&'()*+,-./0123456789:;<=>?" ;
  ASCII10 = " @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_" ;
  ASCII14 = " `abcdefghijklmnopqrstuvwxyz{|}~?" ;
  strcpy ( ASCIIall , ASCII04 ) ;
  strcat ( ASCIIall , "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_" ) ;
  strcat ( ASCIIall , "`abcdefghijklmnopqrstuvwxyz{|}~" ) ;
  {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
    xchr [k ]= '?' ;
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = 0 ;for_end = 31 ; if ( k <= for_end) do 
    {
      xchr [k + 32 ]= ASCII04 [k + 1 ];
      xchr [k + 64 ]= ASCII10 [k + 1 ];
      xchr [k + 96 ]= ASCII14 [k + 1 ];
    } 
  while ( k++ < for_end ) ;} 
  MBLstring = " MBL" ;
  RIstring = " RI " ;
  RCEstring = " RCE" ;
  HEX = " 0123456789ABCDEF" ;
  level = 0 ;
  charsonline = 0 ;
  perfect = true ;
  boundarychar = xmaxchar ;
  bcharlabel = xmaxlabel ;
  labelptr = 0 ;
  labeltable [0 ].rr = 0 ;
  {register integer for_end; clabelrunner = 0 ;for_end = 256 ; if ( 
  clabelrunner <= for_end) do 
    outputclabels [clabelrunner ]= false ;
  while ( clabelrunner++ < for_end ) ;} 
} 
integer 
zwidthindex ( chartype c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = tfm [charstart [c ]];
  else Result = 256 * tfm [charstart [c ]]+ tfm [charstart [c ]+ 1 ];
  return Result ;
} 
integer 
zheightindex ( chartype c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = tfm [charstart [c ]+ 1 ]/ 16 ;
  else Result = tfm [charstart [c ]+ 2 ];
  return Result ;
} 
integer 
zdepthindex ( chartype c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = tfm [charstart [c ]+ 1 ]% 16 ;
  else Result = tfm [charstart [c ]+ 3 ];
  return Result ;
} 
integer 
zitalicindex ( chartype c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = tfm [charstart [c ]+ 2 ]/ 4 ;
  else Result = tfm [charstart [c ]+ 4 ];
  return Result ;
} 
integer 
ztag ( chartype c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = tfm [charstart [c ]+ 2 ]% 4 ;
  else Result = tfm [charstart [c ]+ 5 ]% 4 ;
  return Result ;
} 
void 
zsetnotag ( chartype c ) 
{
  if ( ! ofmon ) 
  tfm [charstart [c ]+ 2 ]= ( tfm [charstart [c ]+ 2 ]/ 64 ) * 64 + 0 
  ;
  else tfm [charstart [c ]+ 5 ]= ( tfm [charstart [c ]+ 5 ]/ 64 ) * 64 
  + 0 ;
} 
void 
zcheckunused ( chartype c ) 
{
  integer x  ;
  if ( ofmlevel == 1 ) 
  x = tfm [charstart [c ]+ 5 ]/ 8 ;
  else x = tfm [charstart [c ]+ 5 ]/ 4 ;
  if ( x != 0 ) 
  {
    if ( ofmlevel == 1 ) 
    x = tfm [charstart [c ]+ 5 ]% 8 ;
    else x = tfm [charstart [c ]+ 5 ]% 4 ;
    tfm [charstart [c ]+ 5 ]= x ;
    perfect = false ;
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    charsonline = 0 ;
    fprintf ( stderr , "%s\n",  "Ignoring non-zero unused char info bits" ) ;
  } 
} 
boolean 
zctag ( chartype c ) 
{
  register boolean Result; if ( ! ( ofmlevel == 1 ) ) 
  Result = false ;
  else Result = tfm [charstart [c ]+ 5 ]/ 4 % 2 ;
  return Result ;
} 
void 
zsetnoctag ( chartype c ) 
{
  if ( ! ( ofmlevel == 1 ) ) 
  tfm [charstart [c ]+ 5 ]= tfm [charstart [c ]+ 5 ]/ 8 * 8 + tfm [
  charstart [c ]+ 5 ]% 4 ;
} 
integer 
znorepeats ( chartype c ) 
{
  register integer Result; if ( ofmlevel <= 0 ) 
  Result = 0 ;
  else Result = 256 * tfm [charstart [c ]+ 8 ]+ tfm [charstart [c ]+ 9 
  ];
  return Result ;
} 
integer 
zcharparam ( chartype c , integer i ) 
{
  register integer Result; Result = 256 * tfm [charstart [c ]+ 2 * i + 10 
  ]+ tfm [charstart [c ]+ 2 * i + 11 ];
  return Result ;
} 
integer 
zrremainder ( chartype c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = tfm [charstart [c ]+ 3 ];
  else Result = 256 * tfm [charstart [c ]+ 6 ]+ tfm [charstart [c ]+ 7 
  ];
  return Result ;
} 
integer 
zligstep ( chartype c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = 4 * ( ligkernbase + c ) ;
  else Result = 4 * ( ligkernbase + 2 * c ) ;
  return Result ;
} 
integer 
zexten ( chartype c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = 4 * ( extenbase + rremainder ( c ) ) ;
  else Result = 4 * ( extenbase + 2 * rremainder ( c ) ) ;
  return Result ;
} 
integer 
zlskipbyte ( integer c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = tfm [c ];
  else Result = 256 * tfm [c ]+ tfm [c + 1 ];
  return Result ;
} 
void 
zsetlskipbyte ( integer c , integer newc ) 
{
  if ( ! ofmon ) 
  tfm [c ]= newc ;
  else {
      
    tfm [c ]= newc / 256 ;
    tfm [c + 1 ]= newc % 256 ;
  } 
} 
integer 
zlnextchar ( integer c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = tfm [c + 1 ];
  else Result = 256 * tfm [c + 2 ]+ tfm [c + 3 ];
  return Result ;
} 
void 
zsetlnextchar ( integer c , chartype newc ) 
{
  if ( ! ofmon ) 
  tfm [c + 1 ]= newc ;
  else {
      
    tfm [c + 2 ]= newc / 256 ;
    tfm [c + 3 ]= newc % 256 ;
  } 
} 
integer 
zlopbyte ( integer c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = tfm [c + 2 ];
  else Result = 256 * tfm [c + 4 ]+ tfm [c + 5 ];
  return Result ;
} 
void 
zsetlopbyte ( integer c , integer newc ) 
{
  if ( ! ofmon ) 
  tfm [c + 2 ]= newc ;
  else {
      
    tfm [c + 2 ]= newc / 256 ;
    tfm [c + 3 ]= newc % 256 ;
  } 
} 
integer 
zlremainder ( integer c ) 
{
  register integer Result; if ( ! ofmon ) 
  Result = tfm [c + 3 ];
  else Result = 256 * tfm [c + 6 ]+ tfm [c + 7 ];
  return Result ;
} 
void 
zsetlremainder ( integer c , chartype newc ) 
{
  if ( ! ofmon ) 
  tfm [c + 3 ]= newc ;
  else {
      
    tfm [c + 6 ]= newc / 256 ;
    tfm [c + 7 ]= newc % 256 ;
  } 
} 
void 
readtfmword ( void ) 
{
  if ( eof ( tfmfile ) ) 
  b0 = 0 ;
  else read ( tfmfile , b0 ) ;
  if ( eof ( tfmfile ) ) 
  b1 = 0 ;
  else read ( tfmfile , b1 ) ;
  if ( eof ( tfmfile ) ) 
  b2 = 0 ;
  else read ( tfmfile , b2 ) ;
  if ( eof ( tfmfile ) ) 
  b3 = 0 ;
  else read ( tfmfile , b3 ) ;
} 
integer 
zvfread ( integer k ) 
{
  register integer Result; byte b  ;
  integer a  ;
  vfcount = vfcount + k ;
  if ( eof ( vffile ) ) 
  b = 0 ;
  else read ( vffile , b ) ;
  a = b ;
  if ( k == 4 ) {
      
    if ( b >= 128 ) 
    a = a - 256 ;
  } 
  while ( k > 1 ) {
      
    if ( eof ( vffile ) ) 
    b = 0 ;
    else read ( vffile , b ) ;
    a = 256 * a + b ;
    k = k - 1 ;
  } 
  Result = a ;
  return Result ;
} 
integer 
ztfmwidth ( integer c ) 
{
  register integer Result; integer a  ;
  indextype k  ;
  k = 4 * ( widthbase + widthindex ( c ) ) ;
  a = tfm [k ];
  if ( a >= 128 ) 
  a = a - 256 ;
  Result = ( ( 256 * a + tfm [k + 1 ]) * 256 + tfm [k + 2 ]) * 256 + tfm [
  k + 3 ];
  return Result ;
} 
void 
zoutdigs ( integer j ) 
{
  do {
      j = j - 1 ;
    putc ( HEX [1 + dig [j ]],  vplfile );
  } while ( ! ( j == 0 ) ) ;
} 
void 
zprintdigs ( integer j ) 
{
  do {
      j = j - 1 ;
    putc ( HEX [1 + dig [j ]],  stderr );
  } while ( ! ( j == 0 ) ) ;
} 
void 
zprintnumber ( integer c , integer form ) 
{
  unsigned char j  ;
  j = 0 ;
  if ( ( c < 0 ) ) 
  {
    fprintf ( stderr , "%s\n",  "Internal error: print_number (negative value)" ) ;
    c = 0 ;
  } 
  if ( form == 8 ) 
  putc ( '\'' ,  stderr );
  else if ( form == 16 ) 
  putc ( '"' ,  stderr );
  else if ( form != 10 ) 
  {
    fprintf ( stderr , "%s\n",  "Internal error: print_number (form)" ) ;
    form = 16 ;
  } 
  while ( ( c > 0 ) || ( j == 0 ) ) {
      
    dig [j ]= c % form ;
    c = c / form ;
    j = j + 1 ;
  } 
  printdigs ( j ) ;
} 
void 
outln ( void ) 
{
  unsigned char l  ;
  putc ('\n',  vplfile );
  {register integer for_end; l = 1 ;for_end = level ; if ( l <= for_end) do 
    Fputs ( vplfile ,  "   " ) ;
  while ( l++ < for_end ) ;} 
} 
void 
left ( void ) 
{
  level = level + 1 ;
  putc ( '(' ,  vplfile );
} 
void 
right ( void ) 
{
  level = level - 1 ;
  putc ( ')' ,  vplfile );
  outln () ;
} 
void 
zoutBCPL ( indextype k ) 
{
  unsigned char l  ;
  putc ( ' ' ,  vplfile );
  l = tfm [k ];
  while ( l > 0 ) {
      
    k = k + 1 ;
    l = l - 1 ;
    putc ( xchr [tfm [k ]],  vplfile );
  } 
} 
void 
zoutnumber ( integer c , integer form ) 
{
  unsigned char j  ;
  j = 0 ;
  if ( ( c < 0 ) ) 
  {
    fprintf ( stderr , "%s\n",  "Internal error: print_number (negative value)" ) ;
    c = 0 ;
  } 
  if ( form == 8 ) 
  Fputs ( vplfile ,  " O " ) ;
  else if ( form == 10 ) 
  Fputs ( vplfile ,  " D " ) ;
  else if ( form == 16 ) 
  Fputs ( vplfile ,  " H " ) ;
  else {
      
    fprintf ( stderr , "%s\n",  "Internal error: print_number (form)" ) ;
    form = 16 ;
    Fputs ( vplfile ,  " H " ) ;
  } 
  while ( ( c > 0 ) || ( j == 0 ) ) {
      
    dig [j ]= c % form ;
    c = c / form ;
    j = j + 1 ;
  } 
  outdigs ( j ) ;
} 
void 
zouthex ( indextype k , indextype l ) 
{
  integer a  ;
  unsigned char b  ;
  unsigned char j  ;
  Fputs ( vplfile ,  " H " ) ;
  a = 0 ;
  b = 0 ;
  j = 0 ;
  while ( l > 0 ) {
      
    l = l - 1 ;
    if ( tfm [k + l ]!= 0 ) 
    {
      while ( b > 2 ) {
	  
	dig [j ]= a % 16 ;
	a = a / 16 ;
	b = b - 4 ;
	j = j + 1 ;
      } 
      switch ( b ) 
      {case 0 : 
	a = tfm [k + l ];
	break ;
      case 1 : 
	a = a + 2 * tfm [k + l ];
	break ;
      case 2 : 
	a = a + 4 * tfm [k + l ];
	break ;
      case 3 : 
	a = a + 8 * tfm [k + l ];
	break ;
      } 
    } 
    b = b + 8 ;
  } 
  while ( ( a > 0 ) || ( j == 0 ) ) {
      
    dig [j ]= a % 16 ;
    a = a / 16 ;
    j = j + 1 ;
  } 
  outdigs ( j ) ;
} 
void 
zoutchar ( integer c ) 
{
  if ( ( fonttype > 0 ) || ( charcodeformat == charcodehex ) ) 
  outnumber ( c , 16 ) ;
  else if ( ( charcodeformat == charcodeascii ) && ( c > 32 ) && ( c <= 126 ) 
  && ( c != 40 ) && ( c != 41 ) ) 
  fprintf ( vplfile , "%s%c",  " C " , ASCIIall [c - 31 ]) ;
  else outnumber ( c , 16 ) ;
} 
void 
zoutface ( indextype k ) 
{
  unsigned char s  ;
  unsigned char b  ;
  if ( tfm [k ]>= 18 ) 
  outhex ( k , 1 ) ;
  else {
      
    Fputs ( vplfile ,  " F " ) ;
    s = tfm [k ]% 2 ;
    b = tfm [k ]/ 2 ;
    putbyte ( MBLstring [1 + ( b % 3 ) ], vplfile ) ;
    putbyte ( RIstring [1 + s ], vplfile ) ;
    putbyte ( RCEstring [1 + ( b / 3 ) ], vplfile ) ;
  } 
} 
void 
zoutfix ( indextype k ) 
{
  short a  ;
  integer f  ;
  unsigned char j  ;
  integer delta  ;
  Fputs ( vplfile ,  " R " ) ;
  a = ( tfm [k ]* 16 ) + ( tfm [k + 1 ]/ 16 ) ;
  f = ( ( tfm [k + 1 ]% 16 ) * 256 + tfm [k + 2 ]) * 256 + tfm [k + 3 ];
  if ( a > 2047 ) 
  {
    putc ( '-' ,  vplfile );
    a = 4096 - a ;
    if ( f > 0 ) 
    {
      f = 1048576L - f ;
      a = a - 1 ;
    } 
  } 
  {
    j = 0 ;
    do {
	dig [j ]= a % 10 ;
      a = a / 10 ;
      j = j + 1 ;
    } while ( ! ( a == 0 ) ) ;
    outdigs ( j ) ;
  } 
  {
    putc ( '.' ,  vplfile );
    f = 10 * f + 5 ;
    delta = 10 ;
    do {
	if ( delta > 1048576L ) 
      f = f + 524288L - ( delta / 2 ) ;
      fprintf ( vplfile , "%ld",  (long)f / 1048576L ) ;
      f = 10 * ( f % 1048576L ) ;
      delta = delta * 10 ;
    } while ( ! ( f <= delta ) ) ;
  } 
} 
void 
zcheckBCPL ( indextype k , indextype l ) 
{
  indextype j  ;
  integer c  ;
  if ( tfm [k ]>= l ) 
  {
    {
      perfect = false ;
      if ( charsonline > 0 ) 
      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
      charsonline = 0 ;
      fprintf ( stderr , "%s%s\n",  "Bad OFM file: " ,       "String is too long; I've shortened it drastically." ) ;
    } 
    tfm [k ]= 1 ;
  } 
  {register integer for_end; j = k + 1 ;for_end = k + tfm [k ]; if ( j <= 
  for_end) do 
    {
      c = tfm [j ];
      if ( ( c == 40 ) || ( c == 41 ) ) 
      {
	{
	  perfect = false ;
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  charsonline = 0 ;
	  fprintf ( stderr , "%s%s\n",  "Bad OFM file: " ,           "Parenthesis in string has been changed to slash." ) ;
	} 
	tfm [j ]= 47 ;
      } 
      else if ( ( c < 32 ) || ( c > 126 ) ) 
      {
	{
	  perfect = false ;
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  charsonline = 0 ;
	  fprintf ( stderr , "%s%s\n",  "Bad OFM file: " ,           "Nonstandard ASCII code has been blotted out." ) ;
	} 
	tfm [j ]= 63 ;
      } 
      else if ( ( c >= 97 ) && ( c <= 122 ) ) 
      tfm [j ]= c - 32 ;
    } 
  while ( j++ < for_end ) ;} 
} 
void 
hashinput ( void ) 
{
  /* 10 */ unsigned char cc  ;
  chartype zz  ;
  chartype y  ;
  integer64 key  ;
  integer64 t64  ;
  integer t  ;
  if ( hashptr == hashsize ) 
  goto lab10 ;
  k = ligstep ( i ) ;
  y = lnextchar ( k ) ;
  t = lopbyte ( k ) ;
  cc = 0 ;
  zz = lremainder ( k ) ;
  if ( t >= 128 ) 
  zz = y ;
  else {
      
    switch ( t ) 
    {case 0 : 
    case 6 : 
      ;
      break ;
    case 5 : 
    case 11 : 
      zz = y ;
      break ;
    case 1 : 
    case 7 : 
      cc = 1 ;
      break ;
    case 2 : 
      cc = 2 ;
      break ;
    case 3 : 
      cc = 3 ;
      break ;
    } 
  } 
  key = int64cast ( xmaxchar ) * c + y + 1 ;
  h = ( hashmult * key ) % hashsize ;
  while ( hash [h ]> 0 ) {
      
    if ( hash [h ]<= key ) 
    {
      if ( hash [h ]== key ) 
      goto lab10 ;
      t64 = hash [h ];
      hash [h ]= key ;
      key = t64 ;
      t = classvar [h ];
      classvar [h ]= cc ;
      cc = t ;
      t = ligz [h ];
      ligz [h ]= zz ;
      zz = t ;
    } 
    if ( h > 0 ) 
    h = h - 1 ;
    else h = hashsize ;
  } 
  hash [h ]= key ;
  classvar [h ]= cc ;
  ligz [h ]= zz ;
  hashptr = hashptr + 1 ;
  hashlist [hashptr ]= h ;
  lab10: ;
} 
#ifdef notdef
indextype 
zligf ( indextype h , indextype x , indextype y ) 
{
  register indextype Result; ;
  return Result ;
} 
#endif /* notdef */
indextype 
zeval ( indextype x , indextype y ) 
{
  register indextype Result; integer64 key  ;
  key = int64cast ( xmaxchar ) * x + y + 1 ;
  h = ( hashmult * key ) % hashsize ;
  while ( hash [h ]> key ) if ( h > 0 ) 
  h = h - 1 ;
  else h = hashsize ;
  if ( hash [h ]< key ) 
  Result = y ;
  else Result = ligf ( h , x , y ) ;
  return Result ;
} 
indextype 
zligf ( indextype h , indextype x , indextype y ) 
{
  register indextype Result; switch ( classvar [h ]) 
  {case 0 : 
    ;
    break ;
  case 1 : 
    {
      classvar [h ]= 4 ;
      ligz [h ]= eval ( ligz [h ], y ) ;
      classvar [h ]= 0 ;
    } 
    break ;
  case 2 : 
    {
      classvar [h ]= 4 ;
      ligz [h ]= eval ( x , ligz [h ]) ;
      classvar [h ]= 0 ;
    } 
    break ;
  case 3 : 
    {
      classvar [h ]= 4 ;
      ligz [h ]= eval ( eval ( x , ligz [h ]) , y ) ;
      classvar [h ]= 0 ;
    } 
    break ;
  case 4 : 
    {
      xligcycle = x ;
      yligcycle = y ;
      ligz [h ]= xxmaxchar ;
      classvar [h ]= 0 ;
    } 
    break ;
  } 
  Result = ligz [h ];
  return Result ;
} 
boolean 
zstringbalance ( integer k , integer l ) 
{
  /* 45 10 */ register boolean Result; integer j, bal  ;
  if ( l > 0 ) {
      
    if ( vf [k ]== 32 ) 
    goto lab45 ;
  } 
  bal = 0 ;
  {register integer for_end; j = k ;for_end = k + l - 1 ; if ( j <= for_end) 
  do 
    {
      if ( ( vf [j ]< 32 ) || ( vf [j ]>= 127 ) ) 
      goto lab45 ;
      if ( vf [j ]== 40 ) 
      bal = bal + 1 ;
      else if ( vf [j ]== 41 ) {
	  
	if ( bal == 0 ) 
	goto lab45 ;
	else bal = bal - 1 ;
      } 
    } 
  while ( j++ < for_end ) ;} 
  if ( bal > 0 ) 
  goto lab45 ;
  Result = true ;
  goto lab10 ;
  lab45: Result = false ;
  lab10: ;
  return Result ;
} 
void 
zoutasfix ( integer x ) 
{
  unsigned char k  ;
  if ( abs ( x ) >= 16777216L ) 
  {
    {
      perfect = false ;
      if ( charsonline > 0 ) 
      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
      charsonline = 0 ;
      fprintf ( stderr , "%s%s\n",  "Bad OVF file: " ,       "Oversize dimension has been reset to zero." ) ;
    } 
    x = 0 ;
  } 
  if ( x >= 0 ) 
  tfm [designsize ]= 0 ;
  else {
      
    tfm [designsize ]= 255 ;
    x = x + 16777216L ;
  } 
  {register integer for_end; k = 3 ;for_end = 1 ; if ( k >= for_end) do 
    {
      tfm [designsize + k ]= x % 256 ;
      x = x / 256 ;
    } 
  while ( k-- > for_end ) ;} 
  outfix ( designsize ) ;
} 
integer 
zgetbytes ( integer k , boolean issigned ) 
{
  register integer Result; integer a  ;
  if ( vfptr + k > vflimit ) 
  {
    {
      perfect = false ;
      if ( charsonline > 0 ) 
      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
      charsonline = 0 ;
      fprintf ( stderr , "%s%s\n",  "Bad OVF file: " , "Packet ended prematurely" ) ;
    } 
    k = vflimit - vfptr ;
  } 
  a = vf [vfptr ];
  if ( ( k == 4 ) || issigned ) {
      
    if ( a >= 128 ) 
    a = a - 256 ;
  } 
  vfptr = vfptr + 1 ;
  while ( k > 1 ) {
      
    a = a * 256 + vf [vfptr ];
    vfptr = vfptr + 1 ;
    k = k - 1 ;
  } 
  Result = a ;
  return Result ;
} 
boolean 
vfinput ( void ) 
{
  register boolean Result; integer vfptr  ;
  integer k  ;
  integer c  ;
  read ( vffile , tempbyte ) ;
  if ( tempbyte != 247 ) 
  {
    fprintf ( stderr , "%s\n",  "The first byte isn't `pre'!" ) ;
    fprintf ( stderr , "%s\n",  "Sorry, but I can't go on; are you sure this is a OVF?"     ) ;
    uexit ( 1 ) ;
  } 
  if ( eof ( vffile ) ) 
  {
    fprintf ( stderr , "%s\n",  "The input file is only one byte long!" ) ;
    fprintf ( stderr , "%s\n",  "Sorry, but I can't go on; are you sure this is a OVF?"     ) ;
    uexit ( 1 ) ;
  } 
  read ( vffile , tempbyte ) ;
  if ( tempbyte != 202 ) 
  {
    fprintf ( stderr , "%s\n",  "Wrong OVF version number in second byte!" ) ;
    fprintf ( stderr , "%s\n",  "Sorry, but I can't go on; are you sure this is a OVF?"     ) ;
    uexit ( 1 ) ;
  } 
  if ( eof ( vffile ) ) 
  {
    fprintf ( stderr , "%s\n",  "The input file is only two bytes long!" ) ;
    fprintf ( stderr , "%s\n",  "Sorry, but I can't go on; are you sure this is a OVF?"     ) ;
    uexit ( 1 ) ;
  } 
  read ( vffile , tempbyte ) ;
  vfcount = 11 ;
  vfptr = 0 ;
  if ( vfptr + tempbyte >= vfsize ) 
  {
    fprintf ( stderr , "%s\n",  "The file is bigger than I can handle!" ) ;
    fprintf ( stderr , "%s\n",  "Sorry, but I can't go on; are you sure this is a OVF?"     ) ;
    uexit ( 1 ) ;
  } 
  {register integer for_end; k = vfptr ;for_end = vfptr + tempbyte - 1 
  ; if ( k <= for_end) do 
    {
      if ( eof ( vffile ) ) 
      {
	fprintf ( stderr , "%s\n",  "The file ended prematurely!" ) ;
	fprintf ( stderr , "%s\n",          "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
	uexit ( 1 ) ;
      } 
      read ( vffile , vf [k ]) ;
    } 
  while ( k++ < for_end ) ;} 
  vfcount = vfcount + tempbyte ;
  vfptr = vfptr + tempbyte ;
  if ( verbose ) 
  {
    {register integer for_end; k = 0 ;for_end = vfptr - 1 ; if ( k <= 
    for_end) do 
      putc ( xchr [vf [k ]],  stderr );
    while ( k++ < for_end ) ;} 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
  } 
  regcount = 0 ;
  {register integer for_end; k = 0 ;for_end = 7 ; if ( k <= for_end) do 
    {
      if ( eof ( vffile ) ) 
      {
	fprintf ( stderr , "%s\n",  "The file ended prematurely!" ) ;
	fprintf ( stderr , "%s\n",          "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
	uexit ( 1 ) ;
      } 
      read ( vffile , tempbyte ) ;
      if ( tempbyte == tfm [checksum + k ]) 
      regcount = regcount + 1 ;
    } 
  while ( k++ < for_end ) ;} 
  realdsize = ( ( ( tfm [designsize ]* 256 + tfm [designsize + 1 ]) * 256 
  + tfm [designsize + 2 ]) * 256 + tfm [designsize + 3 ]) / ((double) 
  1048576L ) ;
  if ( regcount != 8 ) 
  {
    fprintf ( stderr , "%s\n",  "Check sum and/or design size mismatch." ) ;
    fprintf ( stderr , "%s\n",  "Data from OFM file will be assumed correct." ) ;
  } 
  {register integer for_end; k = 0 ;for_end = 1114111L ; if ( k <= for_end) 
  do 
    packetstart [k ]= vfsize ;
  while ( k++ < for_end ) ;} 
  fontptr = 0 ;
  packetfound = false ;
  fontstart [0 ]= vfptr ;
  vcptr = 0 ;
  fontchars [0 ]= vcptr ;
  do {
      if ( eof ( vffile ) ) 
    {
      fprintf ( stderr , "%s\n",  "File ended without a postamble!" ) ;
      tempbyte = 248 ;
    } 
    else {
	
      read ( vffile , tempbyte ) ;
      vfcount = vfcount + 1 ;
      if ( tempbyte != 248 ) {
	  
	if ( tempbyte > 242 ) 
	{
	  if ( packetfound || ( tempbyte >= 247 ) ) 
	  {
	    fprintf ( stderr , "%s%ld%s\n",  "Illegal byte " , (long)tempbyte ,             " at beginning of character packet!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
	    uexit ( 1 ) ;
	  } 
	  fontnumber [fontptr ]= vfread ( tempbyte - 242 ) ;
	  if ( fontptr == maxfonts ) 
	  {
	    fprintf ( stderr , "%s\n",  "I can't handle that many fonts!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
	    uexit ( 1 ) ;
	  } 
	  if ( vfptr + 14 >= vfsize ) 
	  {
	    fprintf ( stderr , "%s\n",  "The file is bigger than I can handle!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
	    uexit ( 1 ) ;
	  } 
	  {register integer for_end; k = vfptr ;for_end = vfptr + 13 ; if ( 
	  k <= for_end) do 
	    {
	      if ( eof ( vffile ) ) 
	      {
		fprintf ( stderr , "%s\n",  "The file ended prematurely!" ) ;
		fprintf ( stderr , "%s\n",                  "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
		uexit ( 1 ) ;
	      } 
	      read ( vffile , vf [k ]) ;
	    } 
	  while ( k++ < for_end ) ;} 
	  vfcount = vfcount + 14 ;
	  vfptr = vfptr + 14 ;
	  if ( vf [vfptr - 10 ]> 0 ) 
	  {
	    fprintf ( stderr , "%s\n",  "Mapped font size is too big!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
	    uexit ( 1 ) ;
	  } 
	  a = vf [vfptr - 2 ];
	  l = vf [vfptr - 1 ];
	  if ( vfptr + a + l >= vfsize ) 
	  {
	    fprintf ( stderr , "%s\n",  "The file is bigger than I can handle!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
	    uexit ( 1 ) ;
	  } 
	  {register integer for_end; k = vfptr ;for_end = vfptr + a + l - 1 
	  ; if ( k <= for_end) do 
	    {
	      if ( eof ( vffile ) ) 
	      {
		fprintf ( stderr , "%s\n",  "The file ended prematurely!" ) ;
		fprintf ( stderr , "%s\n",                  "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
		uexit ( 1 ) ;
	      } 
	      read ( vffile , vf [k ]) ;
	    } 
	  while ( k++ < for_end ) ;} 
	  vfcount = vfcount + a + l ;
	  vfptr = vfptr + a + l ;
	  if ( verbose ) 
	  {
	    fprintf ( stderr , "%s%ld%s",  "MAPFONT " , (long)fontptr , ": " ) ;
	    {register integer for_end; k = fontstart [fontptr ]+ 14 ;
	    for_end = vfptr - 1 ; if ( k <= for_end) do 
	      putc ( xchr [vf [k ]],  stderr );
	    while ( k++ < for_end ) ;} 
	    k = fontstart [fontptr ]+ 5 ;
	    Fputs ( stderr ,  " at " ) ;
	    fprintreal ( stderr , ( ( ( vf [k ]* 256 + vf [k + 1 ]) * 256 
	    + vf [k + 2 ]) / ((double) 1048576L ) ) * realdsize , 2 , 2 ) ;
	    fprintf ( stderr , "%s\n",  "pt" ) ;
	  } 
	  r = vfptr - ( fontstart [fontptr ]+ 14 ) ;
	  curname = xmalloc ( r + 1 ) ;
	  {register integer for_end; k = ( fontstart [fontptr ]+ 14 ) ;
	  for_end = vfptr ; if ( k <= for_end) do 
	    {
	      curname [k - ( fontstart [fontptr ]+ 14 ) ]= xchr [vf [k ]
	      ];
	    } 
	  while ( k++ < for_end ) ;} 
	  curname [r ]= 0 ;
	  tfmfile = kpseopenfile ( curname , kpseofmformat ) ;
	  if ( eof ( tfmfile ) ) 
	  fprintf ( stderr , "%s\n",            "---not loaded, font metric file can't be opened!" ) ;
	  else {
	      
	    fontbc = 0 ;
	    fontec = 1114112L ;
	    readtfmword () ;
	    if ( ( b0 * 256 + b1 ) != 0 ) 
	    {
	      fontofmlevel = -1 ;
	      fontlh = b2 * 256 + b3 ;
	      readtfmword () ;
	      fontbc = b0 * 256 + b1 ;
	      fontec = b2 * 256 + b3 ;
	      if ( fontec < fontbc ) 
	      fontbc = fontec + 1 ;
	      readtfmword () ;
	      {register integer for_end; k = 1 ;for_end = 3 + fontlh ; if ( 
	      k <= for_end) do 
		{
		  readtfmword () ;
		  if ( k == 4 ) {
		      
		    if ( b0 + b1 + b2 + b3 > 0 ) {
			
		      if ( ( b0 != vf [fontstart [fontptr ]]) || ( b1 != 
		      vf [fontstart [fontptr ]+ 1 ]) || ( b2 != vf [
		      fontstart [fontptr ]+ 2 ]) || ( b3 != vf [fontstart 
		      [fontptr ]+ 3 ]) ) 
		      {
			if ( verbose ) 
			fprintf ( stderr , "%s\n",                          "Check sum in OVF file being replaced by font metric check sum"                         ) ;
			vf [fontstart [fontptr ]]= b0 ;
			vf [fontstart [fontptr ]+ 1 ]= b1 ;
			vf [fontstart [fontptr ]+ 2 ]= b2 ;
			vf [fontstart [fontptr ]+ 3 ]= b3 ;
		      } 
		    } 
		  } 
		  if ( k == 5 ) {
		      
		    if ( ( b0 != vf [fontstart [fontptr ]+ 8 ]) || ( b1 != 
		    vf [fontstart [fontptr ]+ 9 ]) || ( b2 != vf [
		    fontstart [fontptr ]+ 10 ]) || ( b3 != vf [fontstart [
		    fontptr ]+ 11 ]) ) 
		    {
		      fprintf ( stderr , "%s\n",                        "Design size in OVF file being replaced by font metric design size"                       ) ;
		      vf [fontstart [fontptr ]+ 8 ]= b0 ;
		      vf [fontstart [fontptr ]+ 9 ]= b1 ;
		      vf [fontstart [fontptr ]+ 10 ]= b2 ;
		      vf [fontstart [fontptr ]+ 11 ]= b3 ;
		    } 
		  } 
		} 
	      while ( k++ < for_end ) ;} 
	    } 
	    else {
		
	      fontofmlevel = b2 * 256 + b3 ;
	      readtfmword () ;
	      readtfmword () ;
	      fontlh = ( ( b0 * 256 + b1 ) * 256 + b2 ) * 256 + b3 ;
	      readtfmword () ;
	      fontbc = ( ( b0 * 256 + b1 ) * 256 + b2 ) * 256 + b3 ;
	      readtfmword () ;
	      fontec = ( ( b0 * 256 + b1 ) * 256 + b2 ) * 256 + b3 ;
	      if ( fontec < fontbc ) 
	      fontbc = fontec + 1 ;
	      readtfmword () ;
	      {register integer for_end; k = 1 ;for_end = 8 ; if ( k <= 
	      for_end) do 
		{
		  readtfmword () ;
		} 
	      while ( k++ < for_end ) ;} 
	      if ( fontofmlevel == 1 ) 
	      {
		readtfmword () ;
		fontlh = ( ( b0 * 256 + b1 ) * 256 + b2 ) * 256 + b3 - 29 ;
		readtfmword () ;
		readtfmword () ;
		fontextrawords = ( ( ( b0 * 256 + b1 ) * 256 + b2 ) * 256 + b3 
		) / 2 ;
		{register integer for_end; k = 1 ;for_end = 12 ; if ( k <= 
		for_end) do 
		  {
		    readtfmword () ;
		  } 
		while ( k++ < for_end ) ;} 
	      } 
	      {register integer for_end; k = 1 ;for_end = fontlh ; if ( k <= 
	      for_end) do 
		{
		  readtfmword () ;
		  if ( k == 1 ) {
		      
		    if ( b0 + b1 + b2 + b3 > 0 ) {
			
		      if ( ( b0 != vf [fontstart [fontptr ]]) || ( b1 != 
		      vf [fontstart [fontptr ]+ 1 ]) || ( b2 != vf [
		      fontstart [fontptr ]+ 2 ]) || ( b3 != vf [fontstart 
		      [fontptr ]+ 3 ]) ) 
		      {
			if ( verbose ) 
			fprintf ( stderr , "%s\n",                          "Check sum in OVF file being replaced by font metric check sum"                         ) ;
			vf [fontstart [fontptr ]]= b0 ;
			vf [fontstart [fontptr ]+ 1 ]= b1 ;
			vf [fontstart [fontptr ]+ 2 ]= b2 ;
			vf [fontstart [fontptr ]+ 3 ]= b3 ;
		      } 
		    } 
		  } 
		  if ( k == 2 ) {
		      
		    if ( ( b0 != vf [fontstart [fontptr ]+ 8 ]) || ( b1 != 
		    vf [fontstart [fontptr ]+ 9 ]) || ( b2 != vf [
		    fontstart [fontptr ]+ 10 ]) || ( b3 != vf [fontstart [
		    fontptr ]+ 11 ]) ) 
		    {
		      fprintf ( stderr , "%s\n",                        "Design size in OVF file being replaced by font metric design size"                       ) ;
		      vf [fontstart [fontptr ]+ 8 ]= b0 ;
		      vf [fontstart [fontptr ]+ 9 ]= b1 ;
		      vf [fontstart [fontptr ]+ 10 ]= b2 ;
		      vf [fontstart [fontptr ]+ 11 ]= b3 ;
		    } 
		  } 
		} 
	      while ( k++ < for_end ) ;} 
	    } 
	    if ( fontbc <= fontec ) {
		
	      if ( fontec > 1114111L ) 
	      fprintf ( stderr , "%s\n",  "---not loaded, bad font metric file!" ) ;
	      else switch ( fontofmlevel ) 
	      {case -1 : 
		{
		  {register integer for_end; k = fontbc ;for_end = fontec 
		  ; if ( k <= for_end) do 
		    {
		      readtfmword () ;
		      if ( b0 > 0 ) 
		      {
			vc [vcptr ]= k ;
			vcptr = vcptr + 1 ;
			if ( vcptr == vcsize ) 
			{
			  fprintf ( stderr , "%s\n",  "I'm out of OVF memory!" ) ;
			  fprintf ( stderr , "%s\n",                            "Sorry, but I can't go on; are you sure this is a OVF?"                           ) ;
			  uexit ( 1 ) ;
			} 
		      } 
		    } 
		  while ( k++ < for_end ) ;} 
		} 
		break ;
	      case 0 : 
		{
		  {register integer for_end; k = fontbc ;for_end = fontec 
		  ; if ( k <= for_end) do 
		    {
		      readtfmword () ;
		      if ( ( b0 * 256 + b1 ) > 0 ) 
		      {
			vc [vcptr ]= k ;
			vcptr = vcptr + 1 ;
			if ( vcptr == vcsize ) 
			{
			  fprintf ( stderr , "%s\n",  "I'm out of OVF memory!" ) ;
			  fprintf ( stderr , "%s\n",                            "Sorry, but I can't go on; are you sure this is a OVF?"                           ) ;
			  uexit ( 1 ) ;
			} 
		      } 
		      readtfmword () ;
		    } 
		  while ( k++ < for_end ) ;} 
		} 
		break ;
	      case 1 : 
		{
		  k = fontbc ;
		  while ( k <= fontec ) {
		      
		    readtfmword () ;
		    fontwd = b0 * 256 + b1 ;
		    readtfmword () ;
		    readtfmword () ;
		    fontkprime = k + ( b0 * 256 + b1 ) ;
		    if ( fontwd > 0 ) 
		    {register integer for_end; fontj = k ;for_end = 
		    fontkprime ; if ( fontj <= for_end) do 
		      {
			vc [vcptr ]= fontj ;
			vcptr = vcptr + 1 ;
			if ( vcptr == vcsize ) 
			{
			  fprintf ( stderr , "%s\n",  "I'm out of OVF memory!" ) ;
			  fprintf ( stderr , "%s\n",                            "Sorry, but I can't go on; are you sure this is a OVF?"                           ) ;
			  uexit ( 1 ) ;
			} 
		      } 
		    while ( fontj++ < for_end ) ;} 
		    k = fontkprime + 1 ;
		    {register integer for_end; fontj = 1 ;for_end = 
		    fontextrawords ; if ( fontj <= for_end) do 
		      readtfmword () ;
		    while ( fontj++ < for_end ) ;} 
		  } 
		} 
		break ;
	      } 
	    } 
	    if ( eof ( tfmfile ) ) 
	    fprintf ( stderr , "%s\n",              "---trouble is brewing, font metric file ended too soon!" ) ;
	  } 
	  vcptr = vcptr + 1 ;
	  fontptr = fontptr + 1 ;
	  fontstart [fontptr ]= vfptr ;
	  fontchars [fontptr ]= vcptr ;
	} 
	else {
	    
	  if ( tempbyte == 242 ) 
	  {
	    pl = vfread ( 4 ) ;
	    c = vfread ( 4 ) ;
	    regcount = vfread ( 4 ) ;
	  } 
	  else {
	      
	    pl = tempbyte ;
	    c = vfread ( 1 ) ;
	    regcount = vfread ( 3 ) ;
	  } 
	  if ( ( ( c < bc ) || ( c > ec ) || ( widthindex ( c ) == 0 ) ) ) 
	  {
	    fprintf ( stderr , "%s%ld%s\n",  "Character " , (long)c , " does not exist!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
	    uexit ( 1 ) ;
	  } 
	  if ( packetstart [c ]< vfsize ) 
	  fprintf ( stderr , "%s%ld\n",  "Discarding earlier packet for character " , (long)c ) 
	  ;
	  if ( regcount != tfmwidth ( c ) ) 
	  fprintf ( stderr , "%s%ld%s\n",  "Incorrect OFM width for character " , (long)c ,           " in OVF file" ) ;
	  if ( pl < 0 ) 
	  {
	    fprintf ( stderr , "%s\n",  "Negative packet length!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
	    uexit ( 1 ) ;
	  } 
	  packetstart [c ]= vfptr ;
	  if ( vfptr + pl >= vfsize ) 
	  {
	    fprintf ( stderr , "%s\n",  "The file is bigger than I can handle!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
	    uexit ( 1 ) ;
	  } 
	  {register integer for_end; k = vfptr ;for_end = vfptr + pl - 1 
	  ; if ( k <= for_end) do 
	    {
	      if ( eof ( vffile ) ) 
	      {
		fprintf ( stderr , "%s\n",  "The file ended prematurely!" ) ;
		fprintf ( stderr , "%s\n",                  "Sorry, but I can't go on; are you sure this is a OVF?" ) ;
		uexit ( 1 ) ;
	      } 
	      read ( vffile , vf [k ]) ;
	    } 
	  while ( k++ < for_end ) ;} 
	  vfcount = vfcount + pl ;
	  vfptr = vfptr + pl ;
	  packetend [c ]= vfptr - 1 ;
	  packetfound = true ;
	} 
      } 
    } 
  } while ( ! ( tempbyte == 248 ) ) ;
  while ( ( tempbyte == 248 ) && ! eof ( vffile ) ) {
      
    read ( vffile , tempbyte ) ;
    vfcount = vfcount + 1 ;
  } 
  if ( ! eof ( vffile ) ) 
  {
    fprintf ( stderr , "%s\n",  "There's some extra junk at the end of the OVF file." ) 
    ;
    fprintf ( stderr , "%s\n",  "I'll proceed as if it weren't there." ) ;
  } 
  if ( vfcount % 4 != 0 ) 
  fprintf ( stderr , "%s\n",  "VF data not a multiple of 4 bytes" ) ;
  Result = true ;
  return Result ;
} 
boolean 
organize ( void ) 
{
  register boolean Result; indextype tfmptr  ;
  read ( tfmfile , tfm [0 ]) ;
  if ( tfm [0 ]> 127 ) 
  {
    fprintf ( stderr , "%s\n",  "The first byte of the input file exceeds 127!" ) ;
    fprintf ( stderr , "%s\n",  "Sorry, but I can't go on; are you sure this is a OFM?"     ) ;
    uexit ( 1 ) ;
  } 
  if ( eof ( tfmfile ) ) 
  {
    fprintf ( stderr , "%s\n",  "The input file is only one byte long!" ) ;
    fprintf ( stderr , "%s\n",  "Sorry, but I can't go on; are you sure this is a OFM?"     ) ;
    uexit ( 1 ) ;
  } 
  read ( tfmfile , tfm [1 ]) ;
  lf = tfm [0 ]* 256 + tfm [1 ];
  if ( lf == 0 ) 
  {
    {register integer for_end; i = 2 ;for_end = 7 ; if ( i <= for_end) do 
      {
	if ( eof ( tfmfile ) ) 
	{
	  fprintf ( stderr , "%s\n",            "The input file is too short to designate its length!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	read ( tfmfile , tfm [i ]) ;
      } 
    while ( i++ < for_end ) ;} 
    ofmon = true ;
    ofmlevel = tfm [2 ]* 256 + tfm [3 ];
    if ( ofmlevel > 1 ) 
    {
      fprintf ( stderr , "%s%ld%s\n",  "OFMLEVEL " , (long)ofmlevel ,       " not supported, must be 0 or 1!" ) ;
      fprintf ( stderr , "%s\n",        "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
      uexit ( 1 ) ;
    } 
    if ( tfm [4 ]> 127 ) 
    {
      fprintf ( stderr , "%s\n",  "The fifth byte of the input file exceeds 127!" ) ;
      fprintf ( stderr , "%s\n",        "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
      uexit ( 1 ) ;
    } 
    lf = tfm [4 ]* 16777216L + tfm [5 ]* 65536L + tfm [6 ]* 256 + tfm [
    7 ];
  } 
  else {
      
    ofmon = false ;
  } 
  switch ( ofmlevel ) 
  {case -1 : 
    {
      startptr = 2 ;
      checksum = 24 ;
    } 
    break ;
  case 0 : 
    {
      startptr = 8 ;
      checksum = 56 ;
    } 
    break ;
  case 1 : 
    {
      startptr = 8 ;
      checksum = 116 ;
    } 
    break ;
  } 
  designsize = checksum + 4 ;
  scheme = designsize + 4 ;
  family = scheme + 40 ;
  randomword = family + 20 ;
  if ( lf == 0 ) 
  {
    fprintf ( stderr , "%s\n",      "The file claims to have length zero, but that's impossible!" ) ;
    fprintf ( stderr , "%s\n",  "Sorry, but I can't go on; are you sure this is a OFM?"     ) ;
    uexit ( 1 ) ;
  } 
  tfmfilearray = xreallocarray ( tfmfilearray , byte , 4 * lf + 1000 ) ;
  {register integer for_end; tfmptr = startptr ;for_end = 4 * lf - 1 ; if ( 
  tfmptr <= for_end) do 
    {
      if ( eof ( tfmfile ) ) 
      {
	fprintf ( stderr , "%s\n",  "The file has fewer bytes than it claims!" ) ;
	fprintf ( stderr , "%s\n",          "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	uexit ( 1 ) ;
      } 
      read ( tfmfile , tfm [tfmptr ]) ;
    } 
  while ( tfmptr++ < for_end ) ;} 
  if ( ! eof ( tfmfile ) ) 
  {
    fprintf ( stderr , "%s\n",  "There's some extra junk at the end of the OFM file," ) 
    ;
    fprintf ( stderr , "%s\n",  "but I'll proceed as if it weren't there." ) ;
  } 
  {
    if ( ! ofmon ) 
    {
      tfmptr = 2 ;
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	lh = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	bc = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	ec = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	nw = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	nh = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	nd = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	ni = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	nl = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	nk = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	ne = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	np = tfm [tfmptr ]* 256 + tfm [tfmptr + 1 ];
	tfmptr = tfmptr + 2 ;
      } 
      ncw = ( ec - bc + 1 ) ;
      nlw = nl ;
      neew = ne ;
      headerlength = 6 ;
      topchar = 255 ;
      topwidth = 255 ;
      topheight = 15 ;
      topdepth = 15 ;
      topitalic = 63 ;
    } 
    else {
	
      tfmptr = 8 ;
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	lh = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	bc = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	ec = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	nw = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	nh = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	nd = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	ni = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	nl = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	nk = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	ne = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	np = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm [
	tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      {
	if ( tfm [tfmptr ]> 127 ) 
	{
	  fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	  fprintf ( stderr , "%s\n",            "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	  uexit ( 1 ) ;
	} 
	fontdir = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + 
	tfm [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	tfmptr = tfmptr + 4 ;
      } 
      nlw = 2 * nl ;
      neew = 2 * ne ;
      topchar = 1114111L ;
      topwidth = 1114111L ;
      topheight = 255 ;
      topdepth = 255 ;
      topitalic = 255 ;
      if ( ofmlevel == 0 ) 
      {
	headerlength = 14 ;
	ncw = 2 * ( ec - bc + 1 ) ;
      } 
      else {
	  
	headerlength = 29 ;
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nco = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  ncw = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  npc = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nki = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nwi = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nkf = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nwf = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nkm = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nwm = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nkr = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nwr = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nkg = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nwg = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nkp = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
	{
	  if ( tfm [tfmptr ]> 127 ) 
	  {
	    fprintf ( stderr , "%s\n",  "One of the subfile sizes is negative!" ) ;
	    fprintf ( stderr , "%s\n",              "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	    uexit ( 1 ) ;
	  } 
	  nwp = tfm [tfmptr ]* 16777216L + tfm [tfmptr + 1 ]* 65536L + tfm 
	  [tfmptr + 2 ]* 256 + tfm [tfmptr + 3 ];
	  tfmptr = tfmptr + 4 ;
	} 
      } 
    } 
    if ( lf != ( headerlength + lh + ncw + nw + nh + nd + ni + nlw + nk + neew 
    + np + nki + nwi + nkf + nwf + nkm + nwm + nkr + nwr + nkg + nwg + nkp + 
    nwp ) ) 
    {
      fprintf ( stderr , "%s\n",  "Subfile sizes don't add up to the stated total!" ) ;
      fprintf ( stderr , "%s\n",        "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
      uexit ( 1 ) ;
    } 
    if ( lh < 2 ) 
    {
      fprintf ( stderr , "%s%ld%c\n",  "The header length is only " , (long)lh , '!' ) ;
      fprintf ( stderr , "%s\n",        "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
      uexit ( 1 ) ;
    } 
    if ( nl > ligsize ) 
    {
      fprintf ( stderr , "%s\n",  "The lig/kern program is longer than I can handle!" ) 
      ;
      fprintf ( stderr , "%s\n",        "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
      uexit ( 1 ) ;
    } 
    if ( ( bc > ec + 1 ) || ( ec > topchar ) ) 
    {
      fprintf ( stderr , "%s%ld%s%ld%s\n",  "The character code range " , (long)bc , ".." , (long)ec ,       " is illegal!" ) ;
      fprintf ( stderr , "%s\n",        "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
      uexit ( 1 ) ;
    } 
    if ( ec > maxchar ) 
    {
      fprintf ( stderr , "%s%ld%s\n",  "Character " , (long)ec ,       "is too large.  Ask a wizard to enlarge me." ) ;
      fprintf ( stderr , "%s\n",        "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
      uexit ( 1 ) ;
    } 
    if ( ( nw == 0 ) || ( nh == 0 ) || ( nd == 0 ) || ( ni == 0 ) ) 
    {
      fprintf ( stderr , "%s\n",  "Incomplete subfiles for character dimensions!" ) ;
      fprintf ( stderr , "%s\n",        "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
      uexit ( 1 ) ;
    } 
    if ( ne > ( topchar + 1 ) ) 
    {
      fprintf ( stderr , "%s%ld%s\n",  "There are " , (long)ne , " extensible recipes!" ) ;
      fprintf ( stderr , "%s\n",        "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
      uexit ( 1 ) ;
    } 
  } 
  {
    ivaluesstart = headerlength + lh ;
    fvaluesstart = ivaluesstart + nki ;
    mvaluesstart = fvaluesstart + nkf ;
    rulesstart = mvaluesstart + nkm ;
    gluesstart = rulesstart + nkr ;
    penaltiesstart = gluesstart + nkg ;
    ivaluesbase = penaltiesstart + nkp ;
    fvaluesbase = ivaluesbase + nwi ;
    mvaluesbase = fvaluesbase + nwf ;
    rulesbase = mvaluesbase + nwm ;
    gluesbase = rulesbase + nwr ;
    penaltiesbase = gluesbase + nwg ;
    charbase = penaltiesbase + nwp ;
    bytesperentry = ( 12 + 2 * npc ) / 4 * 4 ;
    if ( ! ofmon ) 
    {
      {register integer for_end; i = bc ;for_end = ec ; if ( i <= for_end) 
      do 
	{
	  charstart [i ]= 4 * charbase + 4 * ( i - bc ) ;
	} 
      while ( i++ < for_end ) ;} 
    } 
    else if ( ofmlevel == 0 ) 
    {
      {register integer for_end; i = bc ;for_end = ec ; if ( i <= for_end) 
      do 
	{
	  charstart [i ]= 4 * charbase + 8 * ( i - bc ) ;
	} 
      while ( i++ < for_end ) ;} 
    } 
    else {
	
      charptr = 4 * charbase ;
      i = bc ;
      while ( i <= ec ) {
	  
	copies = 1 + 256 * tfm [charptr + 8 ]+ tfm [charptr + 9 ];
	{register integer for_end; j = 1 ;for_end = copies ; if ( j <= 
	for_end) do 
	  {
	    charstart [i ]= charptr ;
	    i = i + 1 ;
	  } 
	while ( j++ < for_end ) ;} 
	charptr = charptr + bytesperentry ;
      } 
      if ( charptr != ( 4 * ( charbase + ncw ) ) ) 
      {
	fprintf ( stderr , "%s\n",          "Length of char info table does not correspond to specification" ) ;
	fprintf ( stderr , "%s\n",          "Sorry, but I can't go on; are you sure this is a OFM?" ) ;
	uexit ( 1 ) ;
      } 
    } 
    widthbase = charbase + ncw ;
    heightbase = widthbase + nw ;
    depthbase = heightbase + nh ;
    italicbase = depthbase + nd ;
    ligkernbase = italicbase + ni ;
    kernbase = ligkernbase + nlw ;
    extenbase = kernbase + nk ;
    parambase = extenbase + neew - 1 ;
  } 
  Result = vfinput () ;
  return Result ;
} 
void 
dosimplethings ( void ) 
{
  short i  ;
  integer f  ;
  integer k  ;
  if ( stringbalance ( 0 , fontstart [0 ]) ) 
  {
    left () ;
    Fputs ( vplfile ,  "VTITLE " ) ;
    {register integer for_end; k = 0 ;for_end = fontstart [0 ]- 1 ; if ( k 
    <= for_end) do 
      putc ( xchr [vf [k ]],  vplfile );
    while ( k++ < for_end ) ;} 
    right () ;
  } 
  else {
      
    perfect = false ;
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    charsonline = 0 ;
    fprintf ( stderr , "%s%s\n",  "Bad OVF file: " ,     "Title is not a balanced ASCII string" ) ;
  } 
  {
    switch ( ofmlevel ) 
    {case 0 : 
      {
	Fputs ( vplfile ,  "(OFMLEVEL H 0)" ) ;
	outln () ;
      } 
      break ;
    case 1 : 
      {
	Fputs ( vplfile ,  "(OFMLEVEL H 1)" ) ;
	outln () ;
      } 
      break ;
    } 
    if ( ofmon ) 
    {
      left () ;
      if ( fontdir <= 7 ) 
      Fputs ( vplfile ,  "FONTDIR" ) ;
      else
      Fputs ( vplfile ,  "NFONTDIR" ) ;
      switch ( fontdir % 8 ) 
      {case 0 : 
	Fputs ( vplfile ,  " TL" ) ;
	break ;
      case 1 : 
	Fputs ( vplfile ,  " LT" ) ;
	break ;
      case 2 : 
	Fputs ( vplfile ,  " TR" ) ;
	break ;
      case 3 : 
	Fputs ( vplfile ,  " LB" ) ;
	break ;
      case 4 : 
	Fputs ( vplfile ,  " BL" ) ;
	break ;
      case 5 : 
	Fputs ( vplfile ,  " RT" ) ;
	break ;
      case 6 : 
	Fputs ( vplfile ,  " BR" ) ;
	break ;
      case 7 : 
	Fputs ( vplfile ,  " RB" ) ;
	break ;
      } 
      right () ;
    } 
    fonttype = 0 ;
    if ( lh >= 12 ) 
    {
      {
	checkBCPL ( scheme , 40 ) ;
	if ( ( tfm [scheme ]>= 11 ) && ( tfm [scheme + 1 ]== 84 ) && ( tfm 
	[scheme + 2 ]== 69 ) && ( tfm [scheme + 3 ]== 88 ) && ( tfm [
	scheme + 4 ]== 32 ) && ( tfm [scheme + 5 ]== 77 ) && ( tfm [scheme 
	+ 6 ]== 65 ) && ( tfm [scheme + 7 ]== 84 ) && ( tfm [scheme + 8 ]
	== 72 ) && ( tfm [scheme + 9 ]== 32 ) ) 
	{
	  if ( ( tfm [scheme + 10 ]== 83 ) && ( tfm [scheme + 11 ]== 89 ) 
	  ) 
	  fonttype = 1 ;
	  else if ( ( tfm [scheme + 10 ]== 69 ) && ( tfm [scheme + 11 ]== 
	  88 ) ) 
	  fonttype = 2 ;
	} 
      } 
      if ( lh >= 17 ) 
      {
	left () ;
	Fputs ( vplfile ,  "FAMILY" ) ;
	checkBCPL ( family , 20 ) ;
	outBCPL ( family ) ;
	right () ;
	if ( lh >= 18 ) 
	{
	  left () ;
	  Fputs ( vplfile ,  "FACE" ) ;
	  outface ( randomword + 3 ) ;
	  right () ;
	  {register integer for_end; i = 18 ;for_end = lh - 1 ; if ( i <= 
	  for_end) do 
	    {
	      left () ;
	      fprintf ( vplfile , "%s%ld",  "HEADER D " , (long)i ) ;
	      outhex ( checksum + 4 * i , 4 ) ;
	      right () ;
	    } 
	  while ( i++ < for_end ) ;} 
	} 
      } 
      left () ;
      Fputs ( vplfile ,  "CODINGSCHEME" ) ;
      outBCPL ( scheme ) ;
      right () ;
    } 
    left () ;
    Fputs ( vplfile ,  "DESIGNSIZE" ) ;
    if ( tfm [designsize ]> 127 ) 
    {
      {
	perfect = false ;
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 0 ;
	fprintf ( stderr , "%s%s%s%c\n",  "Bad OFM file: " , "Design size " , "negative" ,         '!' ) ;
      } 
      fprintf ( stderr , "%s\n",  "I've set it to 10 points." ) ;
      Fputs ( vplfile ,  " D 10" ) ;
    } 
    else if ( ( tfm [designsize ]== 0 ) && ( tfm [designsize + 1 ]< 16 ) ) 
    {
      {
	perfect = false ;
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 0 ;
	fprintf ( stderr , "%s%s%s%c\n",  "Bad OFM file: " , "Design size " , "too small" ,         '!' ) ;
      } 
      fprintf ( stderr , "%s\n",  "I've set it to 10 points." ) ;
      Fputs ( vplfile ,  " D 10" ) ;
    } 
    else outfix ( designsize ) ;
    right () ;
    Fputs ( vplfile ,  "(COMMENT DESIGNSIZE IS IN POINTS)" ) ;
    outln () ;
    Fputs ( vplfile ,  "(COMMENT OTHER SIZES ARE MULTIPLES OF DESIGNSIZE)" ) ;
    outln () ;
    left () ;
    Fputs ( vplfile ,  "CHECKSUM" ) ;
    outhex ( checksum , 4 ) ;
    right () ;
    if ( ofmon ) 
    {
      left () ;
      Fputs ( vplfile ,  "SEVENBITSAFEFLAG FALSE" ) ;
      right () ;
    } 
    else if ( ( lh > 17 ) && ( tfm [randomword ]> 127 ) ) 
    {
      left () ;
      Fputs ( vplfile ,  "SEVENBITSAFEFLAG TRUE" ) ;
      right () ;
    } 
  } 
  if ( np > 0 ) 
  {
    left () ;
    Fputs ( vplfile ,  "FONTDIMEN" ) ;
    outln () ;
    {register integer for_end; i = 1 ;for_end = np ; if ( i <= for_end) do 
      {
	left () ;
	if ( i == 1 ) 
	Fputs ( vplfile ,  "SLANT" ) ;
	else {
	    
	  if ( ( tfm [4 * ( parambase + i ) ]> 0 ) && ( tfm [4 * ( 
	  parambase + i ) ]< 255 ) ) 
	  {
	    tfm [4 * ( parambase + i ) ]= 0 ;
	    tfm [( 4 * ( parambase + i ) ) + 1 ]= 0 ;
	    tfm [( 4 * ( parambase + i ) ) + 2 ]= 0 ;
	    tfm [( 4 * ( parambase + i ) ) + 3 ]= 0 ;
	    {
	      perfect = false ;
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      charsonline = 0 ;
	      fprintf ( stderr , "%s%s%c%ld%s\n",  "Bad OFM file: " , "Parameter" , ' ' , (long)i ,               " is too big;" ) ;
	    } 
	    fprintf ( stderr , "%s\n",  "I have set it to zero." ) ;
	  } 
	  if ( i <= 7 ) 
	  switch ( i ) 
	  {case 2 : 
	    Fputs ( vplfile ,  "SPACE" ) ;
	    break ;
	  case 3 : 
	    Fputs ( vplfile ,  "STRETCH" ) ;
	    break ;
	  case 4 : 
	    Fputs ( vplfile ,  "SHRINK" ) ;
	    break ;
	  case 5 : 
	    Fputs ( vplfile ,  "XHEIGHT" ) ;
	    break ;
	  case 6 : 
	    Fputs ( vplfile ,  "QUAD" ) ;
	    break ;
	  case 7 : 
	    Fputs ( vplfile ,  "EXTRASPACE" ) ;
	    break ;
	  } 
	  else if ( ( i <= 22 ) && ( fonttype == 1 ) ) 
	  switch ( i ) 
	  {case 8 : 
	    Fputs ( vplfile ,  "NUM1" ) ;
	    break ;
	  case 9 : 
	    Fputs ( vplfile ,  "NUM2" ) ;
	    break ;
	  case 10 : 
	    Fputs ( vplfile ,  "NUM3" ) ;
	    break ;
	  case 11 : 
	    Fputs ( vplfile ,  "DENOM1" ) ;
	    break ;
	  case 12 : 
	    Fputs ( vplfile ,  "DENOM2" ) ;
	    break ;
	  case 13 : 
	    Fputs ( vplfile ,  "SUP1" ) ;
	    break ;
	  case 14 : 
	    Fputs ( vplfile ,  "SUP2" ) ;
	    break ;
	  case 15 : 
	    Fputs ( vplfile ,  "SUP3" ) ;
	    break ;
	  case 16 : 
	    Fputs ( vplfile ,  "SUB1" ) ;
	    break ;
	  case 17 : 
	    Fputs ( vplfile ,  "SUB2" ) ;
	    break ;
	  case 18 : 
	    Fputs ( vplfile ,  "SUPDROP" ) ;
	    break ;
	  case 19 : 
	    Fputs ( vplfile ,  "SUBDROP" ) ;
	    break ;
	  case 20 : 
	    Fputs ( vplfile ,  "DELIM1" ) ;
	    break ;
	  case 21 : 
	    Fputs ( vplfile ,  "DELIM2" ) ;
	    break ;
	  case 22 : 
	    Fputs ( vplfile ,  "AXISHEIGHT" ) ;
	    break ;
	  } 
	  else if ( ( i <= 13 ) && ( fonttype == 2 ) ) {
	      
	    if ( i == 8 ) 
	    Fputs ( vplfile ,  "DEFAULTRULETHICKNESS" ) ;
	    else
	    fprintf ( vplfile , "%s%ld",  "BIGOPSPACING" , (long)i - 8 ) ;
	  } 
	  else
	  fprintf ( vplfile , "%s%ld",  "PARAMETER D " , (long)i ) ;
	} 
	outfix ( 4 * ( parambase + i ) ) ;
	right () ;
      } 
    while ( i++ < for_end ) ;} 
    right () ;
  } 
  if ( ( fonttype == 1 ) && ( np != 22 ) ) 
  fprintf ( stderr , "%s%ld%s\n",    "Unusual number of fontdimen parameters for a math symbols font (" , (long)np ,   " not 22)." ) ;
  else if ( ( fonttype == 2 ) && ( np != 13 ) ) 
  fprintf ( stderr , "%s%ld%s\n",    "Unusual number of fontdimen parameters for an extension font (" , (long)np ,   " not 13)." ) ;
  if ( nki > 0 ) 
  {
    startcounter = ivaluesstart * 4 ;
    basecounter = ivaluesbase * 4 ;
    {register integer for_end; i = 0 ;for_end = nki - 1 ; if ( i <= for_end) 
    do 
      {
	left () ;
	Fputs ( vplfile ,  "FONTIVALUE" ) ;
	outnumber ( i , 16 ) ;
	outln () ;
	numberentries = 256 * tfm [startcounter + 2 ]+ tfm [startcounter + 
	3 ];
	{register integer for_end; j = 0 ;for_end = numberentries - 1 ; if ( 
	j <= for_end) do 
	  {
	    left () ;
	    Fputs ( vplfile ,  "IVALUE" ) ;
	    outnumber ( j , 16 ) ;
	    outln () ;
	    value = 256 * tfm [basecounter + 2 ]+ tfm [basecounter + 3 ];
	    left () ;
	    Fputs ( vplfile ,  "IVALUEVAL" ) ;
	    outnumber ( value , 16 ) ;
	    right () ;
	    right () ;
	    basecounter = basecounter + 4 ;
	  } 
	while ( j++ < for_end ) ;} 
	right () ;
	startcounter = startcounter + 4 ;
      } 
    while ( i++ < for_end ) ;} 
  } 
  if ( nkf > 0 ) 
  {
    startcounter = fvaluesstart * 4 ;
    basecounter = fvaluesbase * 4 ;
    {register integer for_end; i = 0 ;for_end = nkf - 1 ; if ( i <= for_end) 
    do 
      {
	left () ;
	Fputs ( vplfile ,  "FONTFVALUE" ) ;
	outnumber ( i , 16 ) ;
	outln () ;
	numberentries = 256 * tfm [startcounter + 2 ]+ tfm [startcounter + 
	3 ];
	{register integer for_end; j = 0 ;for_end = numberentries - 1 ; if ( 
	j <= for_end) do 
	  {
	    left () ;
	    Fputs ( vplfile ,  "FVALUE" ) ;
	    outnumber ( j , 16 ) ;
	    outln () ;
	    left () ;
	    Fputs ( vplfile ,  "FVALUEVAL" ) ;
	    outfix ( basecounter ) ;
	    right () ;
	    right () ;
	    basecounter = basecounter + 4 ;
	  } 
	while ( j++ < for_end ) ;} 
	right () ;
	startcounter = startcounter + 4 ;
      } 
    while ( i++ < for_end ) ;} 
  } 
  if ( nkm > 0 ) 
  {
    startcounter = mvaluesstart * 4 ;
    basecounter = mvaluesbase * 4 ;
    {register integer for_end; i = 0 ;for_end = nkm - 1 ; if ( i <= for_end) 
    do 
      {
	left () ;
	Fputs ( vplfile ,  "FONTMVALUE" ) ;
	outnumber ( i , 16 ) ;
	outln () ;
	numberentries = 256 * tfm [startcounter + 2 ]+ tfm [startcounter + 
	3 ];
	{register integer for_end; j = 0 ;for_end = numberentries - 1 ; if ( 
	j <= for_end) do 
	  {
	    left () ;
	    Fputs ( vplfile ,  "MVALUE" ) ;
	    outnumber ( j , 16 ) ;
	    outln () ;
	    left () ;
	    Fputs ( vplfile ,  "MVALUEVAL" ) ;
	    outfix ( basecounter ) ;
	    right () ;
	    right () ;
	    basecounter = basecounter + 4 ;
	  } 
	while ( j++ < for_end ) ;} 
	right () ;
	startcounter = startcounter + 4 ;
      } 
    while ( i++ < for_end ) ;} 
  } 
  if ( nkr > 0 ) 
  {
    startcounter = rulesstart * 4 ;
    basecounter = rulesbase * 4 ;
    {register integer for_end; i = 0 ;for_end = nkr - 1 ; if ( i <= for_end) 
    do 
      {
	left () ;
	Fputs ( vplfile ,  "FONTRULE" ) ;
	outnumber ( i , 16 ) ;
	outln () ;
	numberentries = 256 * tfm [startcounter + 2 ]+ tfm [startcounter + 
	3 ];
	{register integer for_end; j = 0 ;for_end = numberentries - 1 ; if ( 
	j <= for_end) do 
	  {
	    left () ;
	    Fputs ( vplfile ,  "RULE" ) ;
	    outnumber ( j , 16 ) ;
	    outln () ;
	    left () ;
	    Fputs ( vplfile ,  "RULEWD" ) ;
	    outfix ( basecounter ) ;
	    right () ;
	    left () ;
	    Fputs ( vplfile ,  "RULEHT" ) ;
	    outfix ( basecounter + 4 ) ;
	    right () ;
	    left () ;
	    Fputs ( vplfile ,  "RULEDP" ) ;
	    outfix ( basecounter + 8 ) ;
	    right () ;
	    right () ;
	    basecounter = basecounter + 12 ;
	  } 
	while ( j++ < for_end ) ;} 
	right () ;
	startcounter = startcounter + 4 ;
      } 
    while ( i++ < for_end ) ;} 
  } 
  if ( nkg > 0 ) 
  {
    startcounter = gluesstart * 4 ;
    basecounter = gluesbase * 4 ;
    {register integer for_end; i = 0 ;for_end = nkg - 1 ; if ( i <= for_end) 
    do 
      {
	left () ;
	Fputs ( vplfile ,  "FONTGLUE" ) ;
	outnumber ( i , 16 ) ;
	outln () ;
	numberentries = 256 * tfm [startcounter + 2 ]+ tfm [startcounter + 
	3 ];
	{register integer for_end; j = 0 ;for_end = numberentries - 1 ; if ( 
	j <= for_end) do 
	  {
	    left () ;
	    Fputs ( vplfile ,  "GLUE" ) ;
	    outnumber ( j , 16 ) ;
	    outln () ;
	    gluesubtype = tfm [basecounter ]/ 16 ;
	    glueargumentkind = tfm [basecounter ]% 16 ;
	    gluestretchorder = tfm [basecounter + 1 ]/ 16 ;
	    glueshrinkorder = tfm [basecounter + 1 ]% 16 ;
	    glueargument = tfm [basecounter + 2 ]* 256 + tfm [basecounter + 
	    3 ];
	    left () ;
	    Fputs ( vplfile ,  "GLUETYPE" ) ;
	    switch ( gluesubtype ) 
	    {case 0 : 
	      Fputs ( vplfile ,  " H 0" ) ;
	      break ;
	    case 1 : 
	      Fputs ( vplfile ,  " H 1" ) ;
	      break ;
	    case 2 : 
	      Fputs ( vplfile ,  " H 2" ) ;
	      break ;
	    case 3 : 
	      Fputs ( vplfile ,  " H 3" ) ;
	      break ;
	    } 
	    right () ;
	    switch ( glueargumentkind ) 
	    {case 1 : 
	      {
		left () ;
		Fputs ( vplfile ,  "GLUERULE" ) ;
		outnumber ( glueargument , 16 ) ;
		right () ;
	      } 
	      break ;
	    case 2 : 
	      {
		left () ;
		Fputs ( vplfile ,  "GLUECHAR" ) ;
		outnumber ( glueargument , 16 ) ;
		right () ;
	      } 
	      break ;
	    } 
	    left () ;
	    Fputs ( vplfile ,  "GLUESTRETCHORDER" ) ;
	    switch ( gluestretchorder ) 
	    {case 0 : 
	      Fputs ( vplfile ,  " H 0" ) ;
	      break ;
	    case 1 : 
	      Fputs ( vplfile ,  " H 1" ) ;
	      break ;
	    case 2 : 
	      Fputs ( vplfile ,  " H 2" ) ;
	      break ;
	    case 3 : 
	      Fputs ( vplfile ,  " H 3" ) ;
	      break ;
	    case 4 : 
	      Fputs ( vplfile ,  " H 4" ) ;
	      break ;
	    } 
	    right () ;
	    left () ;
	    Fputs ( vplfile ,  "GLUESHRINKORDER" ) ;
	    switch ( glueshrinkorder ) 
	    {case 0 : 
	      Fputs ( vplfile ,  " H 0" ) ;
	      break ;
	    case 1 : 
	      Fputs ( vplfile ,  " H 1" ) ;
	      break ;
	    case 2 : 
	      Fputs ( vplfile ,  " H 2" ) ;
	      break ;
	    case 3 : 
	      Fputs ( vplfile ,  " H 3" ) ;
	      break ;
	    case 4 : 
	      Fputs ( vplfile ,  " H 4" ) ;
	      break ;
	    } 
	    right () ;
	    left () ;
	    Fputs ( vplfile ,  "GLUEWD" ) ;
	    outfix ( basecounter + 4 ) ;
	    right () ;
	    left () ;
	    Fputs ( vplfile ,  "GLUESTRETCH" ) ;
	    outfix ( basecounter + 8 ) ;
	    right () ;
	    left () ;
	    Fputs ( vplfile ,  "GLUESHRINK" ) ;
	    outfix ( basecounter + 12 ) ;
	    right () ;
	    right () ;
	    basecounter = basecounter + 16 ;
	  } 
	while ( j++ < for_end ) ;} 
	right () ;
	startcounter = startcounter + 4 ;
      } 
    while ( i++ < for_end ) ;} 
  } 
  if ( nkp > 0 ) 
  {
    startcounter = penaltiesstart * 4 ;
    basecounter = penaltiesbase * 4 ;
    {register integer for_end; i = 0 ;for_end = nkp - 1 ; if ( i <= for_end) 
    do 
      {
	left () ;
	Fputs ( vplfile ,  "FONTPENALTY" ) ;
	outnumber ( i , 16 ) ;
	outln () ;
	numberentries = 256 * tfm [startcounter + 2 ]+ tfm [startcounter + 
	3 ];
	{register integer for_end; j = 0 ;for_end = numberentries - 1 ; if ( 
	j <= for_end) do 
	  {
	    left () ;
	    Fputs ( vplfile ,  "PENALTY" ) ;
	    outnumber ( j , 16 ) ;
	    outln () ;
	    value = 256 * tfm [basecounter + 2 ]+ tfm [basecounter + 3 ];
	    left () ;
	    Fputs ( vplfile ,  "PENALTYVAL" ) ;
	    outnumber ( value , 16 ) ;
	    right () ;
	    right () ;
	    basecounter = basecounter + 4 ;
	  } 
	while ( j++ < for_end ) ;} 
	right () ;
	startcounter = startcounter + 4 ;
      } 
    while ( i++ < for_end ) ;} 
  } 
  {register integer for_end; f = 0 ;for_end = fontptr - 1 ; if ( f <= 
  for_end) do 
    {
      left () ;
      fprintf ( vplfile , "%s%ld",  "MAPFONT D " , (long)f ) ;
      outln () ;
      a = vf [fontstart [f ]+ 12 ];
      l = vf [fontstart [f ]+ 13 ];
      if ( a > 0 ) {
	  
	if ( ! stringbalance ( fontstart [f ]+ 14 , a ) ) 
	{
	  perfect = false ;
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  charsonline = 0 ;
	  fprintf ( stderr , "%s%s\n",  "Bad OVF file: " ,           "Improper font area will be ignored" ) ;
	} 
	else {
	    
	  left () ;
	  Fputs ( vplfile ,  "FONTAREA " ) ;
	  {register integer for_end; k = fontstart [f ]+ 14 ;for_end = 
	  fontstart [f ]+ a + 13 ; if ( k <= for_end) do 
	    putc ( xchr [vf [k ]],  vplfile );
	  while ( k++ < for_end ) ;} 
	  right () ;
	} 
      } 
      if ( ( l == 0 ) || ! stringbalance ( fontstart [f ]+ 14 + a , l ) ) 
      {
	perfect = false ;
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 0 ;
	fprintf ( stderr , "%s%s\n",  "Bad OVF file: " ,         "Improper font name will be ignored" ) ;
      } 
      else {
	  
	left () ;
	Fputs ( vplfile ,  "FONTNAME " ) ;
	{register integer for_end; k = fontstart [f ]+ 14 + a ;for_end = 
	fontstart [f ]+ a + l + 13 ; if ( k <= for_end) do 
	  putc ( xchr [vf [k ]],  vplfile );
	while ( k++ < for_end ) ;} 
	right () ;
      } 
      {register integer for_end; k = 0 ;for_end = 11 ; if ( k <= for_end) do 
	tfm [k ]= vf [fontstart [f ]+ k ];
      while ( k++ < for_end ) ;} 
      if ( tfm [0 ]+ tfm [1 ]+ tfm [2 ]+ tfm [3 ]> 0 ) 
      {
	left () ;
	Fputs ( vplfile ,  "FONTCHECKSUM" ) ;
	outhex ( 0 , 4 ) ;
	right () ;
      } 
      left () ;
      Fputs ( vplfile ,  "FONTAT" ) ;
      outfix ( 4 ) ;
      right () ;
      left () ;
      Fputs ( vplfile ,  "FONTDSIZE" ) ;
      outfix ( 8 ) ;
      right () ;
      right () ;
    } 
  while ( f++ < for_end ) ;} 
  if ( ( tfm [4 * widthbase ]> 0 ) || ( tfm [4 * widthbase + 1 ]> 0 ) || ( 
  tfm [4 * widthbase + 2 ]> 0 ) || ( tfm [4 * widthbase + 3 ]> 0 ) ) 
  {
    perfect = false ;
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    charsonline = 0 ;
    fprintf ( stderr , "%s%s\n",  "Bad OFM file: " , "width[0] should be zero." ) ;
  } 
  if ( ( tfm [4 * heightbase ]> 0 ) || ( tfm [4 * heightbase + 1 ]> 0 ) || 
  ( tfm [4 * heightbase + 2 ]> 0 ) || ( tfm [4 * heightbase + 3 ]> 0 ) ) 
  {
    perfect = false ;
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    charsonline = 0 ;
    fprintf ( stderr , "%s%s\n",  "Bad OFM file: " , "height[0] should be zero." ) ;
  } 
  if ( ( tfm [4 * depthbase ]> 0 ) || ( tfm [4 * depthbase + 1 ]> 0 ) || ( 
  tfm [4 * depthbase + 2 ]> 0 ) || ( tfm [4 * depthbase + 3 ]> 0 ) ) 
  {
    perfect = false ;
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    charsonline = 0 ;
    fprintf ( stderr , "%s%s\n",  "Bad OFM file: " , "depth[0] should be zero." ) ;
  } 
  if ( ( tfm [4 * italicbase ]> 0 ) || ( tfm [4 * italicbase + 1 ]> 0 ) || 
  ( tfm [4 * italicbase + 2 ]> 0 ) || ( tfm [4 * italicbase + 3 ]> 0 ) ) 
  {
    perfect = false ;
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    charsonline = 0 ;
    fprintf ( stderr , "%s%s\n",  "Bad OFM file: " , "italic[0] should be zero." ) ;
  } 
  {register integer for_end; i = 0 ;for_end = nw - 1 ; if ( i <= for_end) do 
    if ( ( tfm [4 * ( widthbase + i ) ]> 0 ) && ( tfm [4 * ( widthbase + i 
    ) ]< 255 ) ) 
    {
      tfm [4 * ( widthbase + i ) ]= 0 ;
      tfm [( 4 * ( widthbase + i ) ) + 1 ]= 0 ;
      tfm [( 4 * ( widthbase + i ) ) + 2 ]= 0 ;
      tfm [( 4 * ( widthbase + i ) ) + 3 ]= 0 ;
      {
	perfect = false ;
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 0 ;
	fprintf ( stderr , "%s%s%c%ld%s\n",  "Bad OFM file: " , "Width" , ' ' , (long)i ,         " is too big;" ) ;
      } 
      fprintf ( stderr , "%s\n",  "I have set it to zero." ) ;
    } 
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 0 ;for_end = nh - 1 ; if ( i <= for_end) do 
    if ( ( tfm [4 * ( heightbase + i ) ]> 0 ) && ( tfm [4 * ( heightbase + 
    i ) ]< 255 ) ) 
    {
      tfm [4 * ( heightbase + i ) ]= 0 ;
      tfm [( 4 * ( heightbase + i ) ) + 1 ]= 0 ;
      tfm [( 4 * ( heightbase + i ) ) + 2 ]= 0 ;
      tfm [( 4 * ( heightbase + i ) ) + 3 ]= 0 ;
      {
	perfect = false ;
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 0 ;
	fprintf ( stderr , "%s%s%c%ld%s\n",  "Bad OFM file: " , "Height" , ' ' , (long)i ,         " is too big;" ) ;
      } 
      fprintf ( stderr , "%s\n",  "I have set it to zero." ) ;
    } 
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 0 ;for_end = nd - 1 ; if ( i <= for_end) do 
    if ( ( tfm [4 * ( depthbase + i ) ]> 0 ) && ( tfm [4 * ( depthbase + i 
    ) ]< 255 ) ) 
    {
      tfm [4 * ( depthbase + i ) ]= 0 ;
      tfm [( 4 * ( depthbase + i ) ) + 1 ]= 0 ;
      tfm [( 4 * ( depthbase + i ) ) + 2 ]= 0 ;
      tfm [( 4 * ( depthbase + i ) ) + 3 ]= 0 ;
      {
	perfect = false ;
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 0 ;
	fprintf ( stderr , "%s%s%c%ld%s\n",  "Bad OFM file: " , "Depth" , ' ' , (long)i ,         " is too big;" ) ;
      } 
      fprintf ( stderr , "%s\n",  "I have set it to zero." ) ;
    } 
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 0 ;for_end = ni - 1 ; if ( i <= for_end) do 
    if ( ( tfm [4 * ( italicbase + i ) ]> 0 ) && ( tfm [4 * ( italicbase + 
    i ) ]< 255 ) ) 
    {
      tfm [4 * ( italicbase + i ) ]= 0 ;
      tfm [( 4 * ( italicbase + i ) ) + 1 ]= 0 ;
      tfm [( 4 * ( italicbase + i ) ) + 2 ]= 0 ;
      tfm [( 4 * ( italicbase + i ) ) + 3 ]= 0 ;
      {
	perfect = false ;
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 0 ;
	fprintf ( stderr , "%s%s%c%ld%s\n",  "Bad OFM file: " , "Italic correction" , ' ' , (long)i ,         " is too big;" ) ;
      } 
      fprintf ( stderr , "%s\n",  "I have set it to zero." ) ;
    } 
  while ( i++ < for_end ) ;} 
  if ( nk > 0 ) 
  {register integer for_end; i = 0 ;for_end = nk - 1 ; if ( i <= for_end) do 
    if ( ( tfm [4 * ( kernbase + i ) ]> 0 ) && ( tfm [4 * ( kernbase + i ) 
    ]< 255 ) ) 
    {
      tfm [4 * ( kernbase + i ) ]= 0 ;
      tfm [( 4 * ( kernbase + i ) ) + 1 ]= 0 ;
      tfm [( 4 * ( kernbase + i ) ) + 2 ]= 0 ;
      tfm [( 4 * ( kernbase + i ) ) + 3 ]= 0 ;
      {
	perfect = false ;
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 0 ;
	fprintf ( stderr , "%s%s%c%ld%s\n",  "Bad OFM file: " , "Kern" , ' ' , (long)i ,         " is too big;" ) ;
      } 
      fprintf ( stderr , "%s\n",  "I have set it to zero." ) ;
    } 
  while ( i++ < for_end ) ;} 
} 
boolean 
zdomap ( integer c ) 
{
  register boolean Result; integer k  ;
  integer f  ;
  if ( packetstart [c ]== vfsize ) 
  {
    perfect = false ;
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    charsonline = 0 ;
    fprintf ( stderr , "%s%s%ld\n",  "Bad OVF file: " , "Missing packet for character " , (long)c     ) ;
  } 
  else {
      
    left () ;
    Fputs ( vplfile ,  "MAP" ) ;
    outln () ;
    top = 0 ;
    wstack [0 ]= 0 ;
    xstack [0 ]= 0 ;
    ystack [0 ]= 0 ;
    zstack [0 ]= 0 ;
    vfptr = packetstart [c ];
    vflimit = packetend [c ]+ 1 ;
    f = 0 ;
    while ( vfptr < vflimit ) {
	
      o = vf [vfptr ];
      vfptr = vfptr + 1 ;
      if ( ( o <= 131 ) || ( ( o >= 133 ) && ( o <= 136 ) ) ) 
      {
	if ( o >= 128 ) {
	    
	  if ( o >= 133 ) 
	  c = getbytes ( o - 132 , false ) ;
	  else c = getbytes ( o - 127 , false ) ;
	} 
	else c = o ;
	if ( ( c < 0 ) || ( c > 1114111L ) ) 
	{
	  perfect = false ;
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  charsonline = 0 ;
	  fprintf ( stderr , "%s%s%ld%s\n",  "Bad OVF file: " , "Character " , (long)c ,           " is out of range and will be ignored" ) ;
	} 
	else if ( f == fontptr ) 
	{
	  perfect = false ;
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  charsonline = 0 ;
	  fprintf ( stderr , "%s%s%ld%s\n",  "Bad OVF file: " , "Character " , (long)c ,           " in undeclared font will be ignored" ) ;
	} 
	else {
	    
	  vc [fontchars [f + 1 ]- 1 ]= c ;
	  k = fontchars [f ];
	  while ( vc [k ]!= c ) k = k + 1 ;
	  if ( k == fontchars [f + 1 ]- 1 ) 
	  {
	    perfect = false ;
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    charsonline = 0 ;
	    fprintf ( stderr , "%s%s%ld%s%ld%s\n",  "Bad OVF file: " , "Character " , (long)c ,             " in font " , (long)f , " will be ignored" ) ;
	  } 
	  else {
	      
	    if ( o >= 133 ) 
	    Fputs ( vplfile ,  "(PUSH)" ) ;
	    left () ;
	    Fputs ( vplfile ,  "SETCHAR" ) ;
	    outchar ( c ) ;
	    if ( o >= 133 ) 
	    Fputs ( vplfile ,  ")(POP" ) ;
	    right () ;
	  } 
	} 
      } 
      else switch ( o ) 
      {case 138 : 
	;
	break ;
      case 141 : 
	{
	  if ( top == maxstack ) 
	  {
	    fprintf ( stderr , "%s\n",  "Stack overflow!" ) ;
	    uexit ( 1 ) ;
	  } 
	  top = top + 1 ;
	  wstack [top ]= wstack [top - 1 ];
	  xstack [top ]= xstack [top - 1 ];
	  ystack [top ]= ystack [top - 1 ];
	  zstack [top ]= zstack [top - 1 ];
	  Fputs ( vplfile ,  "(PUSH)" ) ;
	  outln () ;
	} 
	break ;
      case 142 : 
	if ( top == 0 ) 
	{
	  perfect = false ;
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  charsonline = 0 ;
	  fprintf ( stderr , "%s%s\n",  "Bad OVF file: " , "More pops than pushes!" ) ;
	} 
	else {
	    
	  top = top - 1 ;
	  Fputs ( vplfile ,  "(POP)" ) ;
	  outln () ;
	} 
	break ;
      case 132 : 
      case 137 : 
	{
	  if ( o == 137 ) 
	  Fputs ( vplfile ,  "(PUSH)" ) ;
	  left () ;
	  Fputs ( vplfile ,  "SETRULE" ) ;
	  outasfix ( getbytes ( 4 , true ) ) ;
	  outasfix ( getbytes ( 4 , true ) ) ;
	  if ( o == 137 ) 
	  Fputs ( vplfile ,  ")(POP" ) ;
	  right () ;
	} 
	break ;
      case 143 : 
      case 144 : 
      case 145 : 
      case 146 : 
	{
	  Fputs ( vplfile ,  "(MOVERIGHT" ) ;
	  outasfix ( getbytes ( o - 142 , true ) ) ;
	  putc ( ')' ,  vplfile );
	  outln () ;
	} 
	break ;
      case 147 : 
      case 148 : 
      case 149 : 
      case 150 : 
      case 151 : 
	{
	  if ( o != 147 ) 
	  wstack [top ]= getbytes ( o - 147 , true ) ;
	  Fputs ( vplfile ,  "(MOVERIGHT" ) ;
	  outasfix ( wstack [top ]) ;
	  putc ( ')' ,  vplfile );
	  outln () ;
	} 
	break ;
      case 152 : 
      case 153 : 
      case 154 : 
      case 155 : 
      case 156 : 
	{
	  if ( o != 152 ) 
	  xstack [top ]= getbytes ( o - 152 , true ) ;
	  Fputs ( vplfile ,  "(MOVERIGHT" ) ;
	  outasfix ( xstack [top ]) ;
	  putc ( ')' ,  vplfile );
	  outln () ;
	} 
	break ;
      case 157 : 
      case 158 : 
      case 159 : 
      case 160 : 
	{
	  Fputs ( vplfile ,  "(MOVEDOWN" ) ;
	  outasfix ( getbytes ( o - 156 , true ) ) ;
	  putc ( ')' ,  vplfile );
	  outln () ;
	} 
	break ;
      case 161 : 
      case 162 : 
      case 163 : 
      case 164 : 
      case 165 : 
	{
	  if ( o != 161 ) 
	  ystack [top ]= getbytes ( o - 161 , true ) ;
	  Fputs ( vplfile ,  "(MOVEDOWN" ) ;
	  outasfix ( ystack [top ]) ;
	  putc ( ')' ,  vplfile );
	  outln () ;
	} 
	break ;
      case 166 : 
      case 167 : 
      case 168 : 
      case 169 : 
      case 170 : 
	{
	  if ( o != 166 ) 
	  zstack [top ]= getbytes ( o - 166 , true ) ;
	  Fputs ( vplfile ,  "(MOVEDOWN" ) ;
	  outasfix ( zstack [top ]) ;
	  putc ( ')' ,  vplfile );
	  outln () ;
	} 
	break ;
      case 171 : 
      case 172 : 
      case 173 : 
      case 174 : 
      case 175 : 
      case 176 : 
      case 177 : 
      case 178 : 
      case 179 : 
      case 180 : 
      case 181 : 
      case 182 : 
      case 183 : 
      case 184 : 
      case 185 : 
      case 186 : 
      case 187 : 
      case 188 : 
      case 189 : 
      case 190 : 
      case 191 : 
      case 192 : 
      case 193 : 
      case 194 : 
      case 195 : 
      case 196 : 
      case 197 : 
      case 198 : 
      case 199 : 
      case 200 : 
      case 201 : 
      case 202 : 
      case 203 : 
      case 204 : 
      case 205 : 
      case 206 : 
      case 207 : 
      case 208 : 
      case 209 : 
      case 210 : 
      case 211 : 
      case 212 : 
      case 213 : 
      case 214 : 
      case 215 : 
      case 216 : 
      case 217 : 
      case 218 : 
      case 219 : 
      case 220 : 
      case 221 : 
      case 222 : 
      case 223 : 
      case 224 : 
      case 225 : 
      case 226 : 
      case 227 : 
      case 228 : 
      case 229 : 
      case 230 : 
      case 231 : 
      case 232 : 
      case 233 : 
      case 234 : 
      case 235 : 
      case 236 : 
      case 237 : 
      case 238 : 
	{
	  f = 0 ;
	  if ( o >= 235 ) 
	  fontnumber [fontptr ]= getbytes ( o - 234 , false ) ;
	  else fontnumber [fontptr ]= o - 171 ;
	  while ( fontnumber [f ]!= fontnumber [fontptr ]) f = f + 1 ;
	  if ( f == fontptr ) 
	  {
	    perfect = false ;
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    charsonline = 0 ;
	    fprintf ( stderr , "%s%s\n",  "Bad OVF file: " , "Undeclared font selected" ) 
	    ;
	  } 
	  else {
	      
	    fprintf ( vplfile , "%s%ld%c",  "(SELECTFONT D " , (long)f , ')' ) ;
	    outln () ;
	  } 
	} 
	break ;
      case 239 : 
      case 240 : 
      case 241 : 
      case 242 : 
	{
	  k = getbytes ( o - 238 , false ) ;
	  if ( k < 0 ) 
	  {
	    perfect = false ;
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    charsonline = 0 ;
	    fprintf ( stderr , "%s%s\n",  "Bad OVF file: " , "String of negative length!"             ) ;
	  } 
	  else {
	      
	    left () ;
	    if ( k + vfptr > vflimit ) 
	    {
	      {
		perfect = false ;
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		charsonline = 0 ;
		fprintf ( stderr , "%s%s\n",  "Bad OVF file: " ,                 "Special command truncated to packet length" ) ;
	      } 
	      k = vflimit - vfptr ;
	    } 
	    if ( ( k > 64 ) || ! stringbalance ( vfptr , k ) ) 
	    {
	      Fputs ( vplfile ,  "SPECIALHEX " ) ;
	      while ( k > 0 ) {
		  
		if ( k % 32 == 0 ) 
		outln () ;
		else if ( k % 4 == 0 ) 
		putc ( ' ' ,  vplfile );
		{
		  a = vf [vfptr ]/ 16 ;
		  if ( a < 10 ) 
		  fprintf ( vplfile , "%ld",  (long)a ) ;
		  else
		  putc ( xchr [a + 55 ],  vplfile );
		} 
		{
		  a = vf [vfptr ]% 16 ;
		  if ( a < 10 ) 
		  fprintf ( vplfile , "%ld",  (long)a ) ;
		  else
		  putc ( xchr [a + 55 ],  vplfile );
		} 
		vfptr = vfptr + 1 ;
		k = k - 1 ;
	      } 
	    } 
	    else {
		
	      Fputs ( vplfile ,  "SPECIAL " ) ;
	      while ( k > 0 ) {
		  
		putc ( xchr [vf [vfptr ]],  vplfile );
		vfptr = vfptr + 1 ;
		k = k - 1 ;
	      } 
	    } 
	    right () ;
	  } 
	} 
	break ;
      case 139 : 
      case 140 : 
      case 243 : 
      case 244 : 
      case 245 : 
      case 246 : 
      case 247 : 
      case 248 : 
      case 249 : 
      case 250 : 
      case 251 : 
      case 252 : 
      case 253 : 
      case 254 : 
      case 255 : 
	{
	  perfect = false ;
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  charsonline = 0 ;
	  fprintf ( stderr , "%s%s%ld%s\n",  "Bad OVF file: " , "Illegal DVI code " , (long)o ,           " will be ignored" ) ;
	} 
	break ;
      } 
    } 
    if ( top > 0 ) 
    {
      {
	perfect = false ;
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 0 ;
	fprintf ( stderr , "%s%s\n",  "Bad OVF file: " , "More pushes than pops!" ) ;
      } 
      do {
	  Fputs ( vplfile ,  "(POP)" ) ;
	top = top - 1 ;
      } while ( ! ( top == 0 ) ) ;
    } 
    right () ;
  } 
  Result = true ;
  return Result ;
} 
boolean 
docharacters ( void ) 
{
  /* 9999 10 */ register boolean Result; integer c  ;
  indextype k  ;
  integer ai  ;
  sortptr = 0 ;
  c = bc ;
  while ( ( c <= ec ) ) {
      
    if ( widthindex ( c ) > 0 ) 
    {register integer for_end; cprime = c ;for_end = ( c + norepeats ( c ) ) 
    ; if ( cprime <= for_end) do 
      {
	if ( verbose ) 
	{
	  if ( charsonline == 8 ) 
	  {
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    charsonline = 1 ;
	  } 
	  else {
	      
	    if ( charsonline > 0 ) 
	    putc ( ' ' ,  stderr );
	    charsonline = charsonline + 1 ;
	  } 
	  printnumber ( cprime , 16 ) ;
	} 
	left () ;
	Fputs ( vplfile ,  "CHARACTER" ) ;
	outchar ( cprime ) ;
	outln () ;
	if ( ofmon ) 
	checkunused ( c ) ;
	if ( widthindex ( c ) >= nw ) 
	{
	  perfect = false ;
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  fprintf ( stderr , "%s%s",  "Width" , " index for character " ) ;
	  printnumber ( c , 16 ) ;
	  fprintf ( stderr , "%s\n",  " is too large;" ) ;
	  fprintf ( stderr , "%s\n",  "so I reset it to zero." ) ;
	} 
	else {
	    
	  left () ;
	  Fputs ( vplfile ,  "CHARWD" ) ;
	  outfix ( 4 * ( widthbase + widthindex ( c ) ) ) ;
	  right () ;
	} 
	if ( heightindex ( c ) > 0 ) {
	    
	  if ( heightindex ( c ) >= nh ) 
	  {
	    perfect = false ;
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    fprintf ( stderr , "%s%s",  "Height" , " index for character " ) ;
	    printnumber ( c , 16 ) ;
	    fprintf ( stderr , "%s\n",  " is too large;" ) ;
	    fprintf ( stderr , "%s\n",  "so I reset it to zero." ) ;
	  } 
	  else {
	      
	    left () ;
	    Fputs ( vplfile ,  "CHARHT" ) ;
	    outfix ( 4 * ( heightbase + heightindex ( c ) ) ) ;
	    right () ;
	  } 
	} 
	if ( depthindex ( c ) > 0 ) {
	    
	  if ( depthindex ( c ) >= nd ) 
	  {
	    perfect = false ;
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    fprintf ( stderr , "%s%s",  "Depth" , " index for character " ) ;
	    printnumber ( c , 16 ) ;
	    fprintf ( stderr , "%s\n",  " is too large;" ) ;
	    fprintf ( stderr , "%s\n",  "so I reset it to zero." ) ;
	  } 
	  else {
	      
	    left () ;
	    Fputs ( vplfile ,  "CHARDP" ) ;
	    outfix ( 4 * ( depthbase + depthindex ( c ) ) ) ;
	    right () ;
	  } 
	} 
	if ( italicindex ( c ) > 0 ) {
	    
	  if ( italicindex ( c ) >= ni ) 
	  {
	    perfect = false ;
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    fprintf ( stderr , "%s%s",  "Italic correction" , " index for character " ) ;
	    printnumber ( c , 16 ) ;
	    fprintf ( stderr , "%s\n",  " is too large;" ) ;
	    fprintf ( stderr , "%s\n",  "so I reset it to zero." ) ;
	  } 
	  else {
	      
	    left () ;
	    Fputs ( vplfile ,  "CHARIC" ) ;
	    outfix ( 4 * ( italicbase + italicindex ( c ) ) ) ;
	    right () ;
	  } 
	} 
	switch ( tag ( c ) ) 
	{case 0 : 
	  ;
	  break ;
	case 1 : 
	  {
	    left () ;
	    Fputs ( vplfile ,  "COMMENT" ) ;
	    outln () ;
	    i = rremainder ( c ) ;
	    r = ligstep ( i ) ;
	    if ( ( lskipbyte ( r ) % 256 ) > 128 ) 
	    i = 256 * lopbyte ( r ) + lremainder ( r ) ;
	    do {
		{ 
		k = ligstep ( i ) ;
		if ( ( lskipbyte ( k ) / 256 ) == 1 ) 
		{
		  switch ( lopbyte ( k ) ) 
		  {case 17 : 
		    {
		      left () ;
		      Fputs ( vplfile ,  "CPEN" ) ;
		      outnumber ( lnextchar ( k ) , 16 ) ;
		      outnumber ( lremainder ( k ) , 16 ) ;
		      right () ;
		    } 
		    break ;
		  case 18 : 
		    {
		      left () ;
		      Fputs ( vplfile ,  "CGLUE" ) ;
		      outnumber ( lnextchar ( k ) , 16 ) ;
		      outnumber ( lremainder ( k ) , 16 ) ;
		      right () ;
		    } 
		    break ;
		  case 19 : 
		    {
		      left () ;
		      Fputs ( vplfile ,  "CPENGLUE" ) ;
		      outnumber ( lnextchar ( k ) , 16 ) ;
		      outnumber ( lremainder ( k ) / 256 , 16 ) ;
		      outnumber ( lremainder ( k ) % 256 , 16 ) ;
		      right () ;
		    } 
		    break ;
		  case 20 : 
		    {
		      left () ;
		      Fputs ( vplfile ,  "CKRN" ) ;
		      outnumber ( lnextchar ( k ) , 16 ) ;
		      r = lremainder ( k ) ;
		      if ( r >= nk ) 
		      {
			{
			  perfect = false ;
			  if ( charsonline > 0 ) 
			  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
			  charsonline = 0 ;
			  fprintf ( stderr , "%s%s\n",  "Bad OFM file: " ,                           "Kern index too large." ) ;
			} 
			Fputs ( vplfile ,  " R 0.0" ) ;
		      } 
		      else outfix ( 4 * ( kernbase + r ) ) ;
		      right () ;
		    } 
		    break ;
		  } 
		} 
		else if ( lskipbyte ( k ) > 128 ) 
		{
		  if ( ( 256 * lopbyte ( k ) + lremainder ( k ) ) >= nl ) 
		  {
		    perfect = false ;
		    if ( charsonline > 0 ) 
		    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		    charsonline = 0 ;
		    fprintf ( stderr , "%s%s\n",  "Bad OFM file: " ,                     "Ligature unconditional stop command address is too big."                     ) ;
		  } 
		} 
		else if ( lopbyte ( k ) >= 128 ) 
		{
		  if ( ( ( lnextchar ( k ) < bc ) || ( lnextchar ( k ) > ec ) 
		  || ( widthindex ( lnextchar ( k ) ) == 0 ) ) ) {
		      
		    if ( lnextchar ( k ) != boundarychar ) 
		    {
		      perfect = false ;
		      if ( charsonline > 0 ) 
		      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		      charsonline = 0 ;
		      fprintf ( stderr , "%s%s%s",  "Bad OFM file: " , "Kern step for" ,                       " nonexistent character " ) ;
		      printnumber ( lnextchar ( k ) , 16 ) ;
		      { putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
		      setlnextchar ( k , 0 ) ;
		    } 
		  } 
		  left () ;
		  Fputs ( vplfile ,  "KRN" ) ;
		  outchar ( lnextchar ( k ) ) ;
		  r = 256 * ( lopbyte ( k ) - 128 ) + lremainder ( k ) ;
		  if ( r >= nk ) 
		  {
		    {
		      perfect = false ;
		      if ( charsonline > 0 ) 
		      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		      charsonline = 0 ;
		      fprintf ( stderr , "%s%s\n",  "Bad OFM file: " ,                       "Kern index too large." ) ;
		    } 
		    Fputs ( vplfile ,  " R 0.0" ) ;
		  } 
		  else outfix ( 4 * ( kernbase + r ) ) ;
		  right () ;
		} 
		else {
		    
		  if ( ( ( lnextchar ( k ) < bc ) || ( lnextchar ( k ) > ec ) 
		  || ( widthindex ( lnextchar ( k ) ) == 0 ) ) ) {
		      
		    if ( lnextchar ( k ) != boundarychar ) 
		    {
		      perfect = false ;
		      if ( charsonline > 0 ) 
		      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		      charsonline = 0 ;
		      fprintf ( stderr , "%s%s%s",  "Bad OFM file: " , "Ligature step for"                       , " nonexistent character " ) ;
		      printnumber ( lnextchar ( k ) , 16 ) ;
		      { putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
		      setlnextchar ( k , 0 ) ;
		    } 
		  } 
		  if ( ( ( lremainder ( k ) < bc ) || ( lremainder ( k ) > ec 
		  ) || ( widthindex ( lremainder ( k ) ) == 0 ) ) ) 
		  {
		    perfect = false ;
		    if ( charsonline > 0 ) 
		    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		    charsonline = 0 ;
		    fprintf ( stderr , "%s%s%s",  "Bad OFM file: " ,                     "Ligature step produces the" , " nonexistent character " ) 
		    ;
		    printnumber ( lremainder ( k ) , 16 ) ;
		    { putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
		    setlremainder ( k , 0 ) ;
		  } 
		  left () ;
		  r = lopbyte ( k ) ;
		  if ( ( r == 4 ) || ( ( r > 7 ) && ( r != 11 ) ) ) 
		  {
		    fprintf ( stderr , "%s\n",                      "Ligature step with nonstandard code changed to LIG" ) ;
		    r = 0 ;
		    setlopbyte ( k , 0 ) ;
		  } 
		  if ( r % 4 > 1 ) 
		  putc ( '/' ,  vplfile );
		  Fputs ( vplfile ,  "LIG" ) ;
		  if ( odd ( r ) ) 
		  putc ( '/' ,  vplfile );
		  while ( r > 3 ) {
		      
		    putc ( '>' ,  vplfile );
		    r = r - 4 ;
		  } 
		  outchar ( lnextchar ( k ) ) ;
		  outchar ( lremainder ( k ) ) ;
		  right () ;
		} 
		if ( ( lskipbyte ( k ) % 256 ) > 0 ) {
		    
		  if ( level == 1 ) 
		  {
		    if ( ( lskipbyte ( k ) % 256 ) >= 128 ) 
		    Fputs ( vplfile ,  "(STOP)" ) ;
		    else {
			
		      count = 0 ;
		      {register integer for_end; ai = i + 1 ;for_end = ( i + 
		      ( lskipbyte ( k ) % 256 ) ) ; if ( ai <= for_end) do 
			if ( activity [ai ]== 2 ) 
			count = count + 1 ;
		      while ( ai++ < for_end ) ;} 
		      fprintf ( vplfile , "%s%ld%c",  "(SKIP D " , (long)count , ')' ) ;
		    } 
		    outln () ;
		  } 
		} 
	      } 
	      if ( ( lskipbyte ( k ) % 256 ) >= 128 ) 
	      i = nl ;
	      else i = i + 1 + ( lskipbyte ( k ) % 256 ) ;
	    } while ( ! ( i >= nl ) ) ;
	    right () ;
	  } 
	  break ;
	case 2 : 
	  {
	    r = rremainder ( c ) ;
	    if ( ( ( r < bc ) || ( r > ec ) || ( widthindex ( r ) == 0 ) ) ) 
	    {
	      {
		perfect = false ;
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		charsonline = 0 ;
		fprintf ( stderr , "%s%s%s",  "Bad OFM file: " , "Character list link to" ,                 " nonexistent character " ) ;
		printnumber ( r , 16 ) ;
		{ putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
	      } 
	      setnotag ( c ) ;
	    } 
	    else {
		
	      while ( ( r < c ) && ( tag ( r ) == 2 ) ) r = rremainder ( r ) ;
	      if ( r == c ) 
	      {
		{
		  perfect = false ;
		  if ( charsonline > 0 ) 
		  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		  charsonline = 0 ;
		  fprintf ( stderr , "%s%s\n",  "Bad OFM file: " ,                   "Cycle in a character list!" ) ;
		} 
		Fputs ( stderr ,  "Character " ) ;
		printnumber ( c , 16 ) ;
		fprintf ( stderr , "%s\n",  " now ends the list." ) ;
		setnotag ( c ) ;
	      } 
	      else {
		  
		left () ;
		Fputs ( vplfile ,  "NEXTLARGER" ) ;
		outchar ( rremainder ( c ) ) ;
		right () ;
	      } 
	    } 
	  } 
	  break ;
	case 3 : 
	  if ( rremainder ( c ) >= ne ) 
	  {
	    {
	      perfect = false ;
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      fprintf ( stderr , "%s%s",  "Extensible" , " index for character " ) ;
	      printnumber ( c , 16 ) ;
	      fprintf ( stderr , "%s\n",  " is too large;" ) ;
	      fprintf ( stderr , "%s\n",  "so I reset it to zero." ) ;
	    } 
	    setnotag ( c ) ;
	  } 
	  else {
	      
	    left () ;
	    Fputs ( vplfile ,  "VARCHAR" ) ;
	    outln () ;
	    {register integer for_end; d = 0 ;for_end = 3 ; if ( d <= 
	    for_end) do 
	      {
		if ( ! ofmon ) 
		{
		  k = exten ( c ) + d ;
		  extenchar = tfm [k ];
		} 
		else {
		    
		  k = exten ( c ) + 2 * d ;
		  extenchar = 256 * tfm [k ]+ tfm [k + 1 ];
		} 
		if ( ( d == 3 ) || ( extenchar > 0 ) ) 
		{
		  left () ;
		  switch ( d ) 
		  {case 0 : 
		    Fputs ( vplfile ,  "TOP" ) ;
		    break ;
		  case 1 : 
		    Fputs ( vplfile ,  "MID" ) ;
		    break ;
		  case 2 : 
		    Fputs ( vplfile ,  "BOT" ) ;
		    break ;
		  case 3 : 
		    Fputs ( vplfile ,  "REP" ) ;
		    break ;
		  } 
		  if ( ( ( extenchar < bc ) || ( extenchar > ec ) || ( 
		  widthindex ( extenchar ) == 0 ) ) ) 
		  outchar ( c ) ;
		  else outchar ( extenchar ) ;
		  right () ;
		} 
	      } 
	    while ( d++ < for_end ) ;} 
	    right () ;
	  } 
	  break ;
	} 
	{register integer for_end; i = 0 ;for_end = npc - 1 ; if ( i <= 
	for_end) do 
	  {
	    if ( charparam ( c , i ) != 0 ) 
	    {
	      left () ;
	      if ( i < nki ) 
	      {
		Fputs ( vplfile ,  "CHARIVALUE" ) ;
		outnumber ( i , 16 ) ;
	      } 
	      else if ( i < ( nki + nkf ) ) 
	      {
		Fputs ( vplfile ,  "CHARFVALUE" ) ;
		outnumber ( i - nki , 16 ) ;
	      } 
	      else if ( i < ( nki + nkf + nkm ) ) 
	      {
		Fputs ( vplfile ,  "CHARMVALUE" ) ;
		outnumber ( i - nki - nkf , 16 ) ;
	      } 
	      else if ( i < ( nki + nkf + nkm + nkr ) ) 
	      {
		Fputs ( vplfile ,  "CHARRULE" ) ;
		outnumber ( i - nki - nkf - nkm , 16 ) ;
	      } 
	      else if ( i < ( nki + nkf + nkm + nkr + nkg ) ) 
	      {
		Fputs ( vplfile ,  "CHARGLUE" ) ;
		outnumber ( i - nki - nkf - nkm - nkr , 16 ) ;
	      } 
	      else if ( i < ( nki + nkf + nkm + nkr + nkg + nkp ) ) 
	      {
		Fputs ( vplfile ,  "CHARPENALTY" ) ;
		outnumber ( i - nki - nkf - nkm - nkr - nkg , 16 ) ;
	      } 
	      outnumber ( charparam ( c , i ) , 16 ) ;
	      right () ;
	    } 
	  } 
	while ( i++ < for_end ) ;} 
	if ( ! domap ( cprime ) ) 
	goto lab9999 ;
	right () ;
      } 
    while ( cprime++ < for_end ) ;} 
    c = c + 1 + norepeats ( c ) ;
  } 
  Result = true ;
  goto lab10 ;
  lab9999: Result = false ;
  lab10: ;
  return Result ;
} 
void mainbody( void ) {
    
  initialize () ;
  if ( ! organize () ) 
  goto lab9999 ;
  dosimplethings () ;
  if ( nl > 0 ) 
  {
    {register integer for_end; ai = 0 ;for_end = ( nl - 1 ) ; if ( ai <= 
    for_end) do 
      activity [ai ]= 0 ;
    while ( ai++ < for_end ) ;} 
    if ( lskipbyte ( ligstep ( 0 ) ) == 255 ) 
    {
      left () ;
      Fputs ( vplfile ,  "BOUNDARYCHAR" ) ;
      boundarychar = lnextchar ( ligstep ( 0 ) ) ;
      outchar ( boundarychar ) ;
      right () ;
      activity [0 ]= 1 ;
    } 
    if ( lskipbyte ( ligstep ( nl - 1 ) ) == 255 ) 
    {
      r = 256 * lopbyte ( ligstep ( nl - 1 ) ) + lremainder ( ligstep ( nl - 1 
      ) ) ;
      if ( r >= nl ) 
      {
	perfect = false ;
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "Ligature/kern starting index for boundarychar is too large;" ) ;
	fprintf ( stderr , "%s\n",  "so I removed it." ) ;
      } 
      else {
	  
	labelptr = 1 ;
	labeltable [1 ].cc = xmaxchar ;
	labeltable [1 ].rr = r ;
	bcharlabel = r ;
	activity [r ]= 2 ;
      } 
      activity [nl - 1 ]= 1 ;
    } 
  } 
  {register integer for_end; c = bc ;for_end = ec ; if ( c <= for_end) do 
    if ( ( tag ( c ) == 1 ) || ( ctag ( c ) ) ) 
    {
      r = rremainder ( c ) ;
      if ( ( lskipbyte ( ligstep ( r ) ) / 256 ) == 0 ) 
      {
	if ( r < nl ) 
	{
	  if ( lskipbyte ( ligstep ( r ) ) > 128 ) 
	  {
	    r = 256 * lopbyte ( ligstep ( r ) ) + lremainder ( ligstep ( r ) ) 
	    ;
	    if ( r < nl ) {
		
	      if ( activity [rremainder ( c ) ]== 0 ) 
	      activity [rremainder ( c ) ]= 1 ;
	    } 
	  } 
	} 
      } 
      if ( r >= nl ) 
      {
	perfect = false ;
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "Ligature/kern starting index for character " ) ;
	printnumber ( c , 16 ) ;
	fprintf ( stderr , "%s\n",  " is too large;" ) ;
	fprintf ( stderr , "%s\n",  "so I removed it." ) ;
	setnotag ( c ) ;
	setnoctag ( c ) ;
      } 
      else {
	  
	sortptr = labelptr ;
	while ( labeltable [sortptr ].rr > r ) {
	    
	  labeltable [sortptr + 1 ]= labeltable [sortptr ];
	  sortptr = sortptr - 1 ;
	} 
	labeltable [sortptr + 1 ].ischar = ! ctag ( c ) ;
	if ( ctag ( c ) ) 
	labeltable [sortptr + 1 ].cc = charparam ( c , 0 ) ;
	else labeltable [sortptr + 1 ].cc = c ;
	labeltable [sortptr + 1 ].rr = r ;
	labelptr = labelptr + 1 ;
	activity [r ]= 2 ;
      } 
    } 
  while ( c++ < for_end ) ;} 
  labeltable [labelptr + 1 ].rr = ligsize ;
  if ( nl > 0 ) 
  {
    left () ;
    Fputs ( vplfile ,  "LIGTABLE" ) ;
    outln () ;
    {register integer for_end; ai = 0 ;for_end = ( nl - 1 ) ; if ( ai <= 
    for_end) do 
      if ( ( lskipbyte ( ligstep ( ai ) ) / 256 ) == 1 ) 
      activity [ai ]= 2 ;
      else if ( activity [ai ]== 2 ) 
      {
	r = lskipbyte ( ligstep ( ai ) ) ;
	if ( r < 128 ) 
	{
	  r = r + ai + 1 ;
	  if ( r >= nl ) 
	  {
	    {
	      perfect = false ;
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      charsonline = 0 ;
	      fprintf ( stderr , "%s%s%ld%s\n",  "Bad OFM file: " , "Ligature/kern step " , (long)ai               , " skips too far;" ) ;
	    } 
	    fprintf ( stderr , "%s\n",  "I made it stop." ) ;
	    setlskipbyte ( ligstep ( ai ) , 128 ) ;
	  } 
	  else activity [r ]= 2 ;
	} 
      } 
    while ( ai++ < for_end ) ;} 
    sortptr = 1 ;
    {register integer for_end; acti = 0 ;for_end = nl - 1 ; if ( acti <= 
    for_end) do 
      if ( activity [acti ]!= 1 ) 
      {
	i = acti ;
	if ( activity [i ]== 0 ) 
	{
	  if ( level == 1 ) 
	  {
	    left () ;
	    Fputs ( vplfile ,              "COMMENT THIS PART OF THE PROGRAM IS NEVER USED!" ) ;
	    outln () ;
	  } 
	} 
	else if ( level == 2 ) 
	right () ;
	while ( i == labeltable [sortptr ].rr ) {
	    
	  if ( labeltable [sortptr ].cc != xmaxchar && ! labeltable [
	  sortptr ].ischar ) 
	  {
	    if ( ! outputclabels [labeltable [sortptr ].cc ]) 
	    {
	      outputclabels [labeltable [sortptr ].cc ]= true ;
	      left () ;
	      Fputs ( vplfile ,  "CLABEL" ) ;
	      outchar ( labeltable [sortptr ].cc ) ;
	      right () ;
	    } 
	  } 
	  else {
	      
	    left () ;
	    Fputs ( vplfile ,  "LABEL" ) ;
	    if ( labeltable [sortptr ].cc == xmaxchar ) 
	    Fputs ( vplfile ,  " BOUNDARYCHAR" ) ;
	    else outchar ( labeltable [sortptr ].cc ) ;
	    right () ;
	  } 
	  sortptr = sortptr + 1 ;
	} 
	{
	  k = ligstep ( i ) ;
	  if ( ( lskipbyte ( k ) / 256 ) == 1 ) 
	  {
	    switch ( lopbyte ( k ) ) 
	    {case 17 : 
	      {
		left () ;
		Fputs ( vplfile ,  "CPEN" ) ;
		outnumber ( lnextchar ( k ) , 16 ) ;
		outnumber ( lremainder ( k ) , 16 ) ;
		right () ;
	      } 
	      break ;
	    case 18 : 
	      {
		left () ;
		Fputs ( vplfile ,  "CGLUE" ) ;
		outnumber ( lnextchar ( k ) , 16 ) ;
		outnumber ( lremainder ( k ) , 16 ) ;
		right () ;
	      } 
	      break ;
	    case 19 : 
	      {
		left () ;
		Fputs ( vplfile ,  "CPENGLUE" ) ;
		outnumber ( lnextchar ( k ) , 16 ) ;
		outnumber ( lremainder ( k ) / 256 , 16 ) ;
		outnumber ( lremainder ( k ) % 256 , 16 ) ;
		right () ;
	      } 
	      break ;
	    case 20 : 
	      {
		left () ;
		Fputs ( vplfile ,  "CKRN" ) ;
		outnumber ( lnextchar ( k ) , 16 ) ;
		r = lremainder ( k ) ;
		if ( r >= nk ) 
		{
		  {
		    perfect = false ;
		    if ( charsonline > 0 ) 
		    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		    charsonline = 0 ;
		    fprintf ( stderr , "%s%s\n",  "Bad OFM file: " ,                     "Kern index too large." ) ;
		  } 
		  Fputs ( vplfile ,  " R 0.0" ) ;
		} 
		else outfix ( 4 * ( kernbase + r ) ) ;
		right () ;
	      } 
	      break ;
	    } 
	  } 
	  else if ( lskipbyte ( k ) > 128 ) 
	  {
	    if ( ( 256 * lopbyte ( k ) + lremainder ( k ) ) >= nl ) 
	    {
	      perfect = false ;
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      charsonline = 0 ;
	      fprintf ( stderr , "%s%s\n",  "Bad OFM file: " ,               "Ligature unconditional stop command address is too big." ) ;
	    } 
	  } 
	  else if ( lopbyte ( k ) >= 128 ) 
	  {
	    if ( ( ( lnextchar ( k ) < bc ) || ( lnextchar ( k ) > ec ) || ( 
	    widthindex ( lnextchar ( k ) ) == 0 ) ) ) {
		
	      if ( lnextchar ( k ) != boundarychar ) 
	      {
		perfect = false ;
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		charsonline = 0 ;
		fprintf ( stderr , "%s%s%s",  "Bad OFM file: " , "Kern step for" ,                 " nonexistent character " ) ;
		printnumber ( lnextchar ( k ) , 16 ) ;
		{ putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
		setlnextchar ( k , 0 ) ;
	      } 
	    } 
	    left () ;
	    Fputs ( vplfile ,  "KRN" ) ;
	    outchar ( lnextchar ( k ) ) ;
	    r = 256 * ( lopbyte ( k ) - 128 ) + lremainder ( k ) ;
	    if ( r >= nk ) 
	    {
	      {
		perfect = false ;
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		charsonline = 0 ;
		fprintf ( stderr , "%s%s\n",  "Bad OFM file: " , "Kern index too large."                 ) ;
	      } 
	      Fputs ( vplfile ,  " R 0.0" ) ;
	    } 
	    else outfix ( 4 * ( kernbase + r ) ) ;
	    right () ;
	  } 
	  else {
	      
	    if ( ( ( lnextchar ( k ) < bc ) || ( lnextchar ( k ) > ec ) || ( 
	    widthindex ( lnextchar ( k ) ) == 0 ) ) ) {
		
	      if ( lnextchar ( k ) != boundarychar ) 
	      {
		perfect = false ;
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		charsonline = 0 ;
		fprintf ( stderr , "%s%s%s",  "Bad OFM file: " , "Ligature step for" ,                 " nonexistent character " ) ;
		printnumber ( lnextchar ( k ) , 16 ) ;
		{ putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
		setlnextchar ( k , 0 ) ;
	      } 
	    } 
	    if ( ( ( lremainder ( k ) < bc ) || ( lremainder ( k ) > ec ) || ( 
	    widthindex ( lremainder ( k ) ) == 0 ) ) ) 
	    {
	      perfect = false ;
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      charsonline = 0 ;
	      fprintf ( stderr , "%s%s%s",  "Bad OFM file: " , "Ligature step produces the"               , " nonexistent character " ) ;
	      printnumber ( lremainder ( k ) , 16 ) ;
	      { putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
	      setlremainder ( k , 0 ) ;
	    } 
	    left () ;
	    r = lopbyte ( k ) ;
	    if ( ( r == 4 ) || ( ( r > 7 ) && ( r != 11 ) ) ) 
	    {
	      fprintf ( stderr , "%s\n",                "Ligature step with nonstandard code changed to LIG" ) ;
	      r = 0 ;
	      setlopbyte ( k , 0 ) ;
	    } 
	    if ( r % 4 > 1 ) 
	    putc ( '/' ,  vplfile );
	    Fputs ( vplfile ,  "LIG" ) ;
	    if ( odd ( r ) ) 
	    putc ( '/' ,  vplfile );
	    while ( r > 3 ) {
		
	      putc ( '>' ,  vplfile );
	      r = r - 4 ;
	    } 
	    outchar ( lnextchar ( k ) ) ;
	    outchar ( lremainder ( k ) ) ;
	    right () ;
	  } 
	  if ( ( lskipbyte ( k ) % 256 ) > 0 ) {
	      
	    if ( level == 1 ) 
	    {
	      if ( ( lskipbyte ( k ) % 256 ) >= 128 ) 
	      Fputs ( vplfile ,  "(STOP)" ) ;
	      else {
		  
		count = 0 ;
		{register integer for_end; ai = i + 1 ;for_end = ( i + ( 
		lskipbyte ( k ) % 256 ) ) ; if ( ai <= for_end) do 
		  if ( activity [ai ]== 2 ) 
		  count = count + 1 ;
		while ( ai++ < for_end ) ;} 
		fprintf ( vplfile , "%s%ld%c",  "(SKIP D " , (long)count , ')' ) ;
	      } 
	      outln () ;
	    } 
	  } 
	} 
      } 
    while ( acti++ < for_end ) ;} 
    if ( level == 2 ) 
    right () ;
    right () ;
    hashptr = 0 ;
    yligcycle = xmaxchar ;
    {register integer for_end; hh = 0 ;for_end = hashsize ; if ( hh <= 
    for_end) do 
      hash [hh ]= 0 ;
    while ( hh++ < for_end ) ;} 
    {register integer for_end; c = bc ;for_end = ec ; if ( c <= for_end) do 
      if ( tag ( c ) == 1 ) 
      {
	i = rremainder ( c ) ;
	if ( ( lskipbyte ( ligstep ( i ) ) % 256 ) > 128 ) 
	i = 256 * lopbyte ( ligstep ( i ) ) + lremainder ( ligstep ( i ) ) ;
	do {
	    hashinput () ;
	  k = lskipbyte ( ligstep ( i ) ) ;
	  if ( k >= 128 ) 
	  i = nl ;
	  else i = i + 1 + k ;
	} while ( ! ( i >= nl ) ) ;
      } 
    while ( c++ < for_end ) ;} 
    if ( bcharlabel < nl ) 
    {
      c = xmaxchar ;
      i = bcharlabel ;
      do {
	  hashinput () ;
	k = lskipbyte ( ligstep ( i ) ) ;
	if ( k >= 128 ) 
	i = nl ;
	else i = i + 1 + k ;
      } while ( ! ( i >= nl ) ) ;
    } 
    if ( hashptr == hashsize ) 
    {
      fprintf ( stderr , "%s\n",        "Sorry, I haven't room for so many ligature/kern pairs!" ) ;
      uexit ( 1 ) ;
    } 
    {register integer for_end; hh = 1 ;for_end = hashptr ; if ( hh <= 
    for_end) do 
      {
	r = hashlist [hh ];
	if ( classvar [r ]> 0 ) 
	r = ligf ( r , ( hash [r ]- 1 ) / xmaxchar , ( hash [r ]- 1 ) % 
	xmaxchar ) ;
      } 
    while ( hh++ < for_end ) ;} 
    if ( yligcycle < xmaxchar ) 
    {
      Fputs ( stderr ,  "Infinite ligature loop starting with " ) ;
      if ( xligcycle == xmaxchar ) 
      Fputs ( stderr ,  "boundary" ) ;
      else printnumber ( xligcycle , 16 ) ;
      Fputs ( stderr ,  " and " ) ;
      printnumber ( yligcycle , 16 ) ;
      { putc ( '!' ,  stderr );  putc ( '\n',  stderr ); }
      Fputs ( vplfile ,  "(INFINITE LIGATURE LOOP MUST BE BROKEN!)" ) ;
      outln () ;
      perfect = false ;
    } 
  } 
  if ( ne > 0 ) 
  {register integer for_end; c = 0 ;for_end = ne - 1 ; if ( c <= for_end) do 
    {register integer for_end; d = 0 ;for_end = 3 ; if ( d <= for_end) do 
      {
	if ( ! ofmon ) 
	{
	  k = 4 * ( extenbase + c ) + d ;
	  extenchar = tfm [k ];
	} 
	else {
	    
	  k = 4 * ( extenbase + c ) + 2 * d ;
	  extenchar = 256 * tfm [k ]+ tfm [k + 1 ];
	} 
	if ( ( extenchar > 0 ) || ( d == 3 ) ) 
	{
	  if ( ( ( extenchar < bc ) || ( extenchar > ec ) || ( widthindex ( 
	  extenchar ) == 0 ) ) ) 
	  {
	    {
	      perfect = false ;
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      charsonline = 0 ;
	      fprintf ( stderr , "%s%s%s",  "Bad OFM file: " ,               "Extensible recipe involves the" , " nonexistent character " ) ;
	      printnumber ( extenchar , 16 ) ;
	      { putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
	    } 
	    if ( d < 3 ) 
	    {
	      if ( ! ofmon ) 
	      {
		tfm [k ]= 0 ;
	      } 
	      else {
		  
		tfm [k ]= 0 ;
		tfm [k + 1 ]= 0 ;
	      } 
	    } 
	  } 
	} 
      } 
    while ( d++ < for_end ) ;} 
  while ( c++ < for_end ) ;} 
  if ( ! docharacters () ) 
  goto lab9999 ;
  if ( verbose ) 
  { putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
  if ( level != 0 ) 
  fprintf ( stderr , "%s\n",  "This program isn't working!" ) ;
  if ( ! perfect ) 
  {
    Fputs ( vplfile ,  "(COMMENT THE OFM AND/OR OVF FILE WAS BAD, " ) ;
    Fputs ( vplfile ,  "SO THE DATA HAS BEEN CHANGED!)" ) ;
    putc ('\n',  vplfile );
  } 
  lab9999: ;
} 
