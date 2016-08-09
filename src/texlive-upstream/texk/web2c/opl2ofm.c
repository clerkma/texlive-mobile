#define OPL2OFM
#include "cpascal.h"
#define bufsize ( 3000 ) 
#define maxheaderbytes ( 100 ) 
#define maxparamwords ( 100 ) 
#define maxligsteps ( 800000L ) 
#define xmaxlabel ( 800001L ) 
#define maxkerns ( 50000L ) 
#define hashsize ( 130003L ) 
#define hashmult ( 16007 ) 
#define ligsize ( 800000L ) 
#define maxchar ( 1114111L ) 
#define xmaxchar ( 1114112L ) 
#define xxmaxchar ( 1114113L ) 
#define memsize ( 4456452L ) 
#define maxwidth ( 65535L ) 
#define maxheight ( 255 ) 
#define maxdepth ( 255 ) 
#define maxitalic ( 255 ) 
#define rulearrays ( 20 ) 
#define ruleentries ( 200 ) 
#define gluearrays ( 20 ) 
#define glueentries ( 200 ) 
#define penaltyarrays ( 20 ) 
#define penaltyentries ( 200 ) 
#define mvaluearrays ( 20 ) 
#define mvalueentries ( 200 ) 
#define fvaluearrays ( 20 ) 
#define fvalueentries ( 200 ) 
#define ivaluearrays ( 20 ) 
#define ivalueentries ( 200 ) 
typedef unsigned short bytetype  ;
typedef unsigned char ASCIIcode  ;
typedef struct {
    bytetype b0 ;
  bytetype b1 ;
  bytetype b2 ;
  bytetype b3 ;
} fourbytes  ;
typedef integer fixword  ;
typedef integer unsignedinteger  ;
typedef integer chartype  ;
typedef integer xchartype  ;
typedef integer xxchartype  ;
typedef integer headerindex  ;
typedef xxchartype indx  ;
typedef integer pointer  ;
typedef integer rulearraytype  ;
typedef integer ruleentrytype  ;
typedef struct {
    fixword rnwidth ;
  fixword rnheight ;
  fixword rndepth ;
} rulenode  ;
typedef integer gluearraytype  ;
typedef integer glueentrytype  ;
typedef struct {
    fixword gnwidth ;
  fixword gnstretch ;
  fixword gnshrink ;
  integer gntype ;
  unsigned char gnargtype ;
  integer gnstretchorder ;
  integer gnshrinkorder ;
  integer gnargument ;
} gluenode  ;
typedef integer penaltyarraytype  ;
typedef integer penaltyentrytype  ;
typedef struct {
    integer pnval ;
} penaltynode  ;
typedef integer mvaluearraytype  ;
typedef integer mvalueentrytype  ;
typedef struct {
    fixword fnval ;
} mvaluenode  ;
typedef integer fvaluearraytype  ;
typedef integer fvalueentrytype  ;
typedef struct {
    fixword fnval ;
} fvaluenode  ;
typedef integer ivaluearraytype  ;
typedef integer ivalueentrytype  ;
typedef struct {
    integer inval ;
} ivaluenode  ;
text plfile  ;
text /* of  unsigned char */ tfmfile  ;
ASCIIcode xord[256]  ;
integer line  ;
integer goodindent  ;
integer indent  ;
integer level  ;
boolean leftln, rightln  ;
integer limit  ;
integer loc  ;
unsigned char buffer[bufsize + 1]  ;
boolean inputhasended  ;
unsigned char charsonline  ;
boolean perfect  ;
ASCIIcode curchar  ;
short start[301]  ;
ASCIIcode dictionary[3001]  ;
short startptr  ;
short dictptr  ;
ASCIIcode curname[21]  ;
unsigned char namelength  ;
short nameptr  ;
short nhash[307]  ;
short curhash  ;
bytetype equiv[301]  ;
bytetype curcode  ;
fourbytes curbytes  ;
fourbytes zerobytes  ;
integer fractiondigits[8]  ;
bytetype headerbytes[maxheaderbytes + 1]  ;
headerindex headerptr  ;
fixword designsize  ;
fixword designunits  ;
boolean sevenbitsafeflag  ;
fourbytes ligkern[maxligsteps + 1]  ;
unsignedinteger nl  ;
unsignedinteger minnl  ;
fixword kern[maxkerns + 1]  ;
integer nk  ;
fourbytes exten[maxchar + 1]  ;
xchartype ne  ;
fixword param[maxparamwords + 1]  ;
integer np  ;
boolean checksumspecified  ;
xchartype bchar  ;
integer fontdir  ;
fixword memory[memsize + 1]  ;
pointer memptr  ;
pointer link[memsize + 1]  ;
pointer charwd[maxchar + 1]  ;
pointer charht[maxchar + 1]  ;
pointer chardp[maxchar + 1]  ;
pointer charic[maxchar + 1]  ;
unsigned char chartag[maxchar + 1]  ;
xchartype charremainder[xmaxchar + 1]  ;
integer topwidth, topheight, topdepth, topitalic  ;
fixword nextd  ;
bytetype indexvar[memsize + 1]  ;
bytetype excess  ;
integer c  ;
chartype cprime  ;
chartype crange  ;
boolean lkstepended  ;
integer krnptr  ;
integer categoryremainders[257]  ;
integer ivaluecategory, maxivaluecategory  ;
integer gluecategory, maxgluecategory  ;
integer penaltycategory, maxpenaltycategory  ;
boolean charextendedtag[maxchar + 1]  ;
boolean tablesread  ;
integer charoriginal[maxchar + 1]  ;
integer charrepeats[maxchar + 1]  ;
boolean diff  ;
integer neededspace, extrabytes  ;
integer chartable[maxchar + 1][9]  ;
integer chtable, chentry  ;
integer tempvalue  ;
constcstring HEX  ;
integer dig[33]  ;
boolean sevenunsafe  ;
fixword delta  ;
integer ligptr  ;
integer64 hash[hashsize + 1]  ;
unsigned char classvar[hashsize + 1]  ;
xxchartype ligz[hashsize + 1]  ;
integer hashptr  ;
integer hashlist[hashsize + 1]  ;
integer h, hh  ;
indx tt  ;
xchartype xligcycle, yligcycle  ;
chartype bc  ;
chartype ec  ;
chartype lh  ;
unsignedinteger lf  ;
boolean notfound  ;
fixword tempwidth  ;
integer ncw, nco, npc  ;
integer j  ;
pointer p  ;
unsigned char q  ;
integer parptr  ;
integer tab  ;
struct {
    integer rr ;
  integer cc ;
} labeltable[xmaxchar + 1]  ;
xchartype labelptr  ;
xchartype sortptr  ;
xchartype lkoffset  ;
integer t  ;
boolean extralocneeded  ;
integer ofmlevel  ;
rulenode rules[rulearrays + 1][ruleentries + 1]  ;
integer npr[rulearrays + 1]  ;
integer nkr  ;
integer nwr  ;
integer rarray  ;
integer rnumber  ;
gluenode glues[gluearrays + 1][glueentries + 1]  ;
integer npg[gluearrays + 1]  ;
integer nkg  ;
integer nwg  ;
integer garray  ;
integer gbyte  ;
integer gnumber  ;
penaltynode penalties[penaltyarrays + 1][penaltyentries + 1]  ;
integer npp[penaltyarrays + 1]  ;
integer nkp  ;
integer nwp  ;
integer parray  ;
integer pnumber  ;
mvaluenode mvalues[mvaluearrays + 1][mvalueentries + 1]  ;
integer npm[mvaluearrays + 1]  ;
integer nkm  ;
integer nwm  ;
integer marray  ;
integer mnumber  ;
fvaluenode fvalues[fvaluearrays + 1][fvalueentries + 1]  ;
integer npf[fvaluearrays + 1]  ;
integer nkf  ;
integer nwf  ;
integer farray  ;
integer fnumber  ;
ivaluenode ivalues[ivaluearrays + 1][ivalueentries + 1]  ;
integer npi[ivaluearrays + 1]  ;
boolean fontiarray  ;
integer nki  ;
integer nwi  ;
integer iarray  ;
integer inumber  ;
cinttype verbose  ;
constcstring tfmname, plname  ;

#include "opl2ofm.h"
void 
parsearguments ( void ) 
{
  
#define noptions ( 3 ) 
  getoptstruct longoptions[noptions + 1]  ;
  integer getoptreturnval  ;
  cinttype optionindex  ;
  integer currentoption  ;
  verbose = false ;
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
      usage ( "opl2ofm" ) ;
    } 
    else if ( ( strcmp ( longoptions [optionindex ].name , "help" ) == 0 ) ) 
    {
      usagehelp ( OPL2OFMHELP , nil ) ;
    } 
    else if ( ( strcmp ( longoptions [optionindex ].name , "version" ) == 0 
    ) ) 
    {
      printversionandexit ( "This is OPL2OFM, Version 1.13" , nil , 
      "J. Plaice, Y. Haralambous, D.E. Knuth" , nil ) ;
    } 
  } while ( ! ( getoptreturnval == -1 ) ) ;
  if ( ( optind + 1 != argc ) && ( optind + 2 != argc ) ) 
  {
    fprintf ( stderr , "%s%s\n",  "opl2ofm" , ": Need one or two file arguments." ) ;
    usage ( "opl2ofm" ) ;
  } 
  plname = extendfilename ( cmdline ( optind ) , "opl" ) ;
  if ( optind + 2 == argc ) 
  {
    tfmname = extendfilename ( cmdline ( optind + 1 ) , "ofm" ) ;
  } 
  else {
      
    tfmname = basenamechangesuffix ( plname , ".opl" , ".ofm" ) ;
  } 
} 
void 
initialize ( void ) 
{
  integer k  ;
  short h  ;
  headerindex d  ;
  integer c  ;
  kpsesetprogramname ( argv [0 ], "opl2ofm" ) ;
  parsearguments () ;
  reset ( plfile , plname ) ;
  if ( verbose ) 
  {
    Fputs ( stderr ,  "This is OPL2OFM, Version 1.13" ) ;
    fprintf ( stderr , "%s\n",  versionstring ) ;
  } 
  rewritebin ( tfmfile , tfmname ) ;
  {register integer for_end; k = 0 ;for_end = 127 ; if ( k <= for_end) do 
    xord [chr ( k ) ]= 127 ;
  while ( k++ < for_end ) ;} 
  xord [' ' ]= 32 ;
  xord ['!' ]= 33 ;
  xord ['"' ]= 34 ;
  xord ['#' ]= 35 ;
  xord ['$' ]= 36 ;
  xord ['%' ]= 37 ;
  xord ['&' ]= 38 ;
  xord ['\'' ]= 39 ;
  xord ['(' ]= 40 ;
  xord [')' ]= 41 ;
  xord ['*' ]= 42 ;
  xord ['+' ]= 43 ;
  xord [',' ]= 44 ;
  xord ['-' ]= 45 ;
  xord ['.' ]= 46 ;
  xord ['/' ]= 47 ;
  xord ['0' ]= 48 ;
  xord ['1' ]= 49 ;
  xord ['2' ]= 50 ;
  xord ['3' ]= 51 ;
  xord ['4' ]= 52 ;
  xord ['5' ]= 53 ;
  xord ['6' ]= 54 ;
  xord ['7' ]= 55 ;
  xord ['8' ]= 56 ;
  xord ['9' ]= 57 ;
  xord [':' ]= 58 ;
  xord [';' ]= 59 ;
  xord ['<' ]= 60 ;
  xord ['=' ]= 61 ;
  xord ['>' ]= 62 ;
  xord ['?' ]= 63 ;
  xord ['@' ]= 64 ;
  xord ['A' ]= 65 ;
  xord ['B' ]= 66 ;
  xord ['C' ]= 67 ;
  xord ['D' ]= 68 ;
  xord ['E' ]= 69 ;
  xord ['F' ]= 70 ;
  xord ['G' ]= 71 ;
  xord ['H' ]= 72 ;
  xord ['I' ]= 73 ;
  xord ['J' ]= 74 ;
  xord ['K' ]= 75 ;
  xord ['L' ]= 76 ;
  xord ['M' ]= 77 ;
  xord ['N' ]= 78 ;
  xord ['O' ]= 79 ;
  xord ['P' ]= 80 ;
  xord ['Q' ]= 81 ;
  xord ['R' ]= 82 ;
  xord ['S' ]= 83 ;
  xord ['T' ]= 84 ;
  xord ['U' ]= 85 ;
  xord ['V' ]= 86 ;
  xord ['W' ]= 87 ;
  xord ['X' ]= 88 ;
  xord ['Y' ]= 89 ;
  xord ['Z' ]= 90 ;
  xord ['[' ]= 91 ;
  xord ['\\' ]= 92 ;
  xord [']' ]= 93 ;
  xord ['^' ]= 94 ;
  xord ['_' ]= 95 ;
  xord ['`' ]= 96 ;
  xord ['a' ]= 97 ;
  xord ['b' ]= 98 ;
  xord ['c' ]= 99 ;
  xord ['d' ]= 100 ;
  xord ['e' ]= 101 ;
  xord ['f' ]= 102 ;
  xord ['g' ]= 103 ;
  xord ['h' ]= 104 ;
  xord ['i' ]= 105 ;
  xord ['j' ]= 106 ;
  xord ['k' ]= 107 ;
  xord ['l' ]= 108 ;
  xord ['m' ]= 109 ;
  xord ['n' ]= 110 ;
  xord ['o' ]= 111 ;
  xord ['p' ]= 112 ;
  xord ['q' ]= 113 ;
  xord ['r' ]= 114 ;
  xord ['s' ]= 115 ;
  xord ['t' ]= 116 ;
  xord ['u' ]= 117 ;
  xord ['v' ]= 118 ;
  xord ['w' ]= 119 ;
  xord ['x' ]= 120 ;
  xord ['y' ]= 121 ;
  xord ['z' ]= 122 ;
  xord ['{' ]= 123 ;
  xord ['|' ]= 124 ;
  xord ['}' ]= 125 ;
  xord ['~' ]= 126 ;
  line = 0 ;
  goodindent = 0 ;
  indent = 0 ;
  level = 0 ;
  limit = 0 ;
  loc = 0 ;
  leftln = true ;
  rightln = true ;
  inputhasended = false ;
  charsonline = 0 ;
  perfect = true ;
  startptr = 1 ;
  start [1 ]= 0 ;
  dictptr = 0 ;
  {register integer for_end; h = 0 ;for_end = 306 ; if ( h <= for_end) do 
    nhash [h ]= 0 ;
  while ( h++ < for_end ) ;} 
  zerobytes .b0 = 0 ;
  zerobytes .b1 = 0 ;
  zerobytes .b2 = 0 ;
  zerobytes .b3 = 0 ;
  {register integer for_end; d = 0 ;for_end = 18 * 4 - 1 ; if ( d <= 
  for_end) do 
    headerbytes [d ]= 0 ;
  while ( d++ < for_end ) ;} 
  headerbytes [8 ]= 11 ;
  headerbytes [9 ]= 85 ;
  headerbytes [10 ]= 78 ;
  headerbytes [11 ]= 83 ;
  headerbytes [12 ]= 80 ;
  headerbytes [13 ]= 69 ;
  headerbytes [14 ]= 67 ;
  headerbytes [15 ]= 73 ;
  headerbytes [16 ]= 70 ;
  headerbytes [17 ]= 73 ;
  headerbytes [18 ]= 69 ;
  headerbytes [19 ]= 68 ;
  {register integer for_end; d = 48 ;for_end = 59 ; if ( d <= for_end) do 
    headerbytes [d ]= headerbytes [d - 40 ];
  while ( d++ < for_end ) ;} 
  designsize = 10 * 1048576L ;
  designunits = 1048576L ;
  sevenbitsafeflag = false ;
  headerptr = 18 * 4 ;
  nl = 0 ;
  minnl = 0 ;
  nk = 0 ;
  ne = 0 ;
  np = 0 ;
  checksumspecified = false ;
  bchar = xmaxchar ;
  fontdir = 0 ;
  charremainder [xmaxchar ]= xmaxlabel ;
  {register integer for_end; c = 0 ;for_end = maxchar ; if ( c <= for_end) 
  do 
    {
      charwd [c ]= 0 ;
      charht [c ]= 0 ;
      chardp [c ]= 0 ;
      charic [c ]= 0 ;
      chartag [c ]= 0 ;
      charremainder [c ]= 0 ;
    } 
  while ( c++ < for_end ) ;} 
  memory [0 ]= 2147483647L ;
  memory [1 ]= 0 ;
  link [1 ]= 0 ;
  memory [2 ]= 0 ;
  link [2 ]= 0 ;
  memory [3 ]= 0 ;
  link [3 ]= 0 ;
  memory [4 ]= 0 ;
  link [4 ]= 0 ;
  memptr = 4 ;
  {register integer for_end; ivaluecategory = 0 ;for_end = 256 ; if ( 
  ivaluecategory <= for_end) do 
    {
      categoryremainders [ivaluecategory ]= -1 ;
    } 
  while ( ivaluecategory++ < for_end ) ;} 
  maxivaluecategory = -1 ;
  maxgluecategory = -1 ;
  maxpenaltycategory = -1 ;
  {register integer for_end; c = 0 ;for_end = maxchar ; if ( c <= for_end) 
  do 
    charextendedtag [c ]= false ;
  while ( c++ < for_end ) ;} 
  tablesread = false ;
  {register integer for_end; chentry = 0 ;for_end = maxchar ; if ( chentry 
  <= for_end) do 
    {
      charoriginal [chentry ]= chentry ;
      charrepeats [chentry ]= 0 ;
    } 
  while ( chentry++ < for_end ) ;} 
  {register integer for_end; c = 0 ;for_end = maxchar ; if ( c <= for_end) 
  do 
    {register integer for_end; chtable = 0 ;for_end = 8 ; if ( chtable <= 
    for_end) do 
      chartable [c ][ chtable ]= 0 ;
    while ( chtable++ < for_end ) ;} 
  while ( c++ < for_end ) ;} 
  HEX = " 0123456789ABCDEF" ;
  hashptr = 0 ;
  yligcycle = xmaxchar ;
  {register integer for_end; k = 0 ;for_end = hashsize ; if ( k <= for_end) 
  do 
    hash [k ]= 0 ;
  while ( k++ < for_end ) ;} 
  npc = -1 ;
  ofmlevel = -1 ;
  {register integer for_end; rarray = 0 ;for_end = rulearrays ; if ( rarray 
  <= for_end) do 
    {
      npr [rarray ]= 0 ;
      {
	rules [rarray ][ npr [rarray ]].rnwidth = 0 ;
	rules [rarray ][ npr [rarray ]].rndepth = 0 ;
	rules [rarray ][ npr [rarray ]].rnheight = 0 ;
      } 
    } 
  while ( rarray++ < for_end ) ;} 
  nkr = -1 ;
  {register integer for_end; garray = 0 ;for_end = gluearrays ; if ( garray 
  <= for_end) do 
    {
      npg [garray ]= 0 ;
      {
	glues [garray ][ npg [garray ]].gnwidth = 0 ;
	glues [garray ][ npg [garray ]].gnstretch = 0 ;
	glues [garray ][ npg [garray ]].gnshrink = 0 ;
	glues [garray ][ npg [garray ]].gntype = 0 ;
	glues [garray ][ npg [garray ]].gnargtype = 0 ;
	glues [garray ][ npg [garray ]].gnstretchorder = 0 ;
	glues [garray ][ npg [garray ]].gnshrinkorder = 0 ;
	glues [garray ][ npg [garray ]].gnargument = 0 ;
      } 
    } 
  while ( garray++ < for_end ) ;} 
  nkg = -1 ;
  {register integer for_end; parray = 0 ;for_end = penaltyarrays ; if ( 
  parray <= for_end) do 
    {
      npp [parray ]= 0 ;
      {
	penalties [parray ][ npp [parray ]].pnval = 0 ;
      } 
    } 
  while ( parray++ < for_end ) ;} 
  nkp = -1 ;
  {register integer for_end; marray = 0 ;for_end = mvaluearrays ; if ( 
  marray <= for_end) do 
    {
      npm [marray ]= 0 ;
      {
	mvalues [marray ][ npm [marray ]].fnval = 0 ;
      } 
    } 
  while ( marray++ < for_end ) ;} 
  nkm = -1 ;
  {register integer for_end; farray = 0 ;for_end = fvaluearrays ; if ( 
  farray <= for_end) do 
    {
      npf [farray ]= 0 ;
      {
	fvalues [farray ][ npf [farray ]].fnval = 0 ;
      } 
    } 
  while ( farray++ < for_end ) ;} 
  nkf = -1 ;
  {register integer for_end; iarray = 0 ;for_end = ivaluearrays ; if ( 
  iarray <= for_end) do 
    {
      npi [iarray ]= 0 ;
      {
	ivalues [iarray ][ npi [iarray ]].inval = 0 ;
      } 
    } 
  while ( iarray++ < for_end ) ;} 
  nki = -1 ;
} 
void 
showerrorcontext ( void ) 
{
  integer k  ;
  fprintf ( stderr , "%s%ld%s\n",  " (line " , (long)line , ")." ) ;
  if ( ! leftln ) 
  Fputs ( stderr ,  "..." ) ;
  {register integer for_end; k = 1 ;for_end = loc ; if ( k <= for_end) do 
    putc ( buffer [k ],  stderr );
  while ( k++ < for_end ) ;} 
  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
  if ( ! leftln ) 
  Fputs ( stderr ,  "   " ) ;
  {register integer for_end; k = 1 ;for_end = loc ; if ( k <= for_end) do 
    putc ( ' ' ,  stderr );
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = loc + 1 ;for_end = limit ; if ( k <= 
  for_end) do 
    putc ( buffer [k ],  stderr );
  while ( k++ < for_end ) ;} 
  if ( rightln ) 
  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
  else
  fprintf ( stderr , "%s\n",  "..." ) ;
  charsonline = 0 ;
  perfect = false ;
} 
void 
fillbuffer ( void ) 
{
  leftln = rightln ;
  limit = 0 ;
  loc = 0 ;
  if ( leftln ) 
  {
    if ( line > 0 ) 
    readln ( plfile ) ;
    line = line + 1 ;
  } 
  if ( eof ( plfile ) ) 
  {
    limit = 1 ;
    buffer [1 ]= ')' ;
    rightln = false ;
    inputhasended = true ;
  } 
  else {
      
    while ( ( limit < bufsize - 2 ) && ( ! eoln ( plfile ) ) ) {
	
      limit = limit + 1 ;
      read ( plfile , buffer [limit ]) ;
    } 
    buffer [limit + 1 ]= ' ' ;
    rightln = eoln ( plfile ) ;
    if ( rightln ) 
    {
      limit = limit + 1 ;
      buffer [limit + 1 ]= ' ' ;
    } 
    if ( leftln ) 
    {
      while ( ( loc < limit ) && ( buffer [loc + 1 ]== ' ' ) ) loc = loc + 1 
      ;
      if ( loc < limit ) 
      {
	if ( level == 0 ) {
	    
	  if ( loc == 0 ) 
	  goodindent = goodindent + 1 ;
	  else {
	      
	    if ( goodindent >= 10 ) 
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,  "Warning: Indented line occurred at level zero"               ) ;
	      showerrorcontext () ;
	    } 
	    goodindent = 0 ;
	    indent = 0 ;
	  } 
	} 
	else if ( indent == 0 ) {
	    
	  if ( loc % level == 0 ) 
	  {
	    indent = loc / level ;
	    goodindent = 1 ;
	  } 
	  else goodindent = 0 ;
	} 
	else if ( indent * level == loc ) 
	goodindent = goodindent + 1 ;
	else {
	    
	  if ( goodindent >= 10 ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    fprintf ( stderr , "%s%s%ld",  "Warning: Inconsistent indentation; " ,             "you are at parenthesis level " , (long)level ) ;
	    showerrorcontext () ;
	  } 
	  goodindent = 0 ;
	  indent = 0 ;
	} 
      } 
    } 
  } 
} 
void 
getkeywordchar ( void ) 
{
  while ( loc == limit ) fillbuffer () ;
  {
    curchar = xord [buffer [loc + 1 ]];
    if ( curchar >= 97 ) 
    curchar = curchar - 32 ;
    if ( ( ( curchar >= 48 ) && ( curchar <= 57 ) ) ) 
    loc = loc + 1 ;
    else if ( ( ( curchar >= 65 ) && ( curchar <= 90 ) ) ) 
    loc = loc + 1 ;
    else if ( curchar == 47 ) 
    loc = loc + 1 ;
    else if ( curchar == 62 ) 
    loc = loc + 1 ;
    else curchar = 32 ;
  } 
} 
void 
getnext ( void ) 
{
  while ( loc == limit ) fillbuffer () ;
  loc = loc + 1 ;
  curchar = xord [buffer [loc ]];
  if ( curchar >= 97 ) {
      
    if ( curchar <= 122 ) 
    curchar = curchar - 32 ;
    else {
	
      if ( curchar == 127 ) 
      {
	{
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  Fputs ( stderr ,  "Illegal character in the file" ) ;
	  showerrorcontext () ;
	} 
	curchar = 63 ;
      } 
    } 
  } 
  else if ( ( curchar <= 41 ) && ( curchar >= 40 ) ) 
  loc = loc - 1 ;
} 
void 
skiptoendofitem ( void ) 
{
  integer l  ;
  l = level ;
  while ( level >= l ) {
      
    while ( loc == limit ) fillbuffer () ;
    loc = loc + 1 ;
    if ( buffer [loc ]== ')' ) 
    level = level - 1 ;
    else if ( buffer [loc ]== '(' ) 
    level = level + 1 ;
  } 
  if ( inputhasended ) 
  {
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    Fputs ( stderr ,  "File ended unexpectedly: No closing \")\"" ) ;
    showerrorcontext () ;
  } 
  curchar = 32 ;
} 
void 
finishtheproperty ( void ) 
{
  while ( curchar == 32 ) getnext () ;
  if ( curchar != 41 ) 
  {
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    Fputs ( stderr ,  "Junk after property value will be ignored" ) ;
    showerrorcontext () ;
  } 
  skiptoendofitem () ;
} 
void 
lookup ( void ) 
{
  unsigned char k  ;
  short j  ;
  boolean notfound  ;
  boolean curhashreset  ;
  curhash = curname [1 ];
  {register integer for_end; k = 2 ;for_end = namelength ; if ( k <= 
  for_end) do 
    curhash = ( curhash + curhash + curname [k ]) % 307 ;
  while ( k++ < for_end ) ;} 
  notfound = true ;
  curhashreset = false ;
  while ( notfound ) {
      
    if ( ( curhash == 0 ) && ( curhashreset ) ) 
    notfound = false ;
    else {
	
      if ( curhash == 0 ) 
      {
	curhash = 306 ;
	curhashreset = true ;
      } 
      else curhash = curhash - 1 ;
      if ( nhash [curhash ]== 0 ) 
      notfound = false ;
      else {
	  
	j = start [nhash [curhash ]];
	if ( start [nhash [curhash ]+ 1 ]== j + namelength ) 
	{
	  notfound = false ;
	  {register integer for_end; k = 1 ;for_end = namelength ; if ( k <= 
	  for_end) do 
	    if ( dictionary [j + k - 1 ]!= curname [k ]) 
	    notfound = true ;
	  while ( k++ < for_end ) ;} 
	} 
      } 
    } 
  } 
  nameptr = nhash [curhash ];
} 
void 
zentername ( bytetype v ) 
{
  unsigned char k  ;
  {register integer for_end; k = 1 ;for_end = namelength ; if ( k <= 
  for_end) do 
    curname [k ]= curname [k + 20 - namelength ];
  while ( k++ < for_end ) ;} 
  lookup () ;
  nhash [curhash ]= startptr ;
  equiv [startptr ]= v ;
  {register integer for_end; k = 1 ;for_end = namelength ; if ( k <= 
  for_end) do 
    {
      dictionary [dictptr ]= curname [k ];
      dictptr = dictptr + 1 ;
    } 
  while ( k++ < for_end ) ;} 
  startptr = startptr + 1 ;
  start [startptr ]= dictptr ;
} 
void 
getname ( void ) 
{
  loc = loc + 1 ;
  level = level + 1 ;
  curchar = 32 ;
  while ( curchar == 32 ) getnext () ;
  if ( ( curchar > 41 ) || ( curchar < 40 ) ) 
  loc = loc - 1 ;
  namelength = 0 ;
  getkeywordchar () ;
  while ( curchar != 32 ) {
      
    if ( namelength == 20 ) 
    curname [1 ]= 88 ;
    else namelength = namelength + 1 ;
    curname [namelength ]= curchar ;
    getkeywordchar () ;
  } 
  lookup () ;
  if ( nameptr == 0 ) 
  {
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    Fputs ( stderr ,  "Sorry, I don't know that property name" ) ;
    showerrorcontext () ;
  } 
  curcode = equiv [nameptr ];
} 
integer 
getcharcode ( void ) 
{
  register integer Result; integer acc  ;
  ASCIIcode t  ;
  do {
      getnext () ;
  } while ( ! ( curchar != 32 ) ) ;
  t = curchar ;
  acc = 0 ;
  do {
      getnext () ;
  } while ( ! ( curchar != 32 ) ) ;
  if ( t == 67 ) {
      
    if ( ( curchar >= 33 ) && ( curchar <= 126 ) && ( ( curchar < 40 ) || ( 
    curchar > 41 ) ) ) 
    acc = xord [buffer [loc ]];
    else {
	
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "\"C\" value must be standard ASCII and not a paren"         ) ;
	showerrorcontext () ;
      } 
      do {
	  getnext () ;
      } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
    } 
  } 
  else if ( t == 68 ) 
  {
    while ( ( curchar >= 48 ) && ( curchar <= 57 ) ) {
	
      acc = acc * 10 + curchar - 48 ;
      if ( acc > 1114111L ) 
      {
	{
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "This value shouldn't exceed 1114111" ) ;
	    showerrorcontext () ;
	  } 
	  do {
	      getnext () ;
	  } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	} 
	acc = 0 ;
	curchar = 32 ;
      } 
      else getnext () ;
    } 
    {
      if ( ( curchar > 41 ) || ( curchar < 40 ) ) 
      loc = loc - 1 ;
    } 
  } 
  else if ( t == 79 ) 
  {
    while ( ( curchar >= 48 ) && ( curchar <= 55 ) ) {
	
      acc = acc * 8 + curchar - 48 ;
      if ( acc > 1114111L ) 
      {
	{
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "This value shouldn't exceed '4177777" ) ;
	    showerrorcontext () ;
	  } 
	  do {
	      getnext () ;
	  } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	} 
	acc = 0 ;
	curchar = 32 ;
      } 
      else getnext () ;
    } 
    {
      if ( ( curchar > 41 ) || ( curchar < 40 ) ) 
      loc = loc - 1 ;
    } 
  } 
  else if ( t == 72 ) 
  {
    while ( ( ( curchar >= 48 ) && ( curchar <= 57 ) ) || ( ( curchar >= 65 ) 
    && ( curchar <= 70 ) ) ) {
	
      if ( curchar >= 65 ) 
      curchar = curchar - 7 ;
      acc = acc * 16 + curchar - 48 ;
      if ( acc > 1114111L ) 
      {
	{
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "This value shouldn't exceed \"10FFFF" ) ;
	    showerrorcontext () ;
	  } 
	  do {
	      getnext () ;
	  } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	} 
	acc = 0 ;
	curchar = 32 ;
      } 
      else getnext () ;
    } 
    {
      if ( ( curchar > 41 ) || ( curchar < 40 ) ) 
      loc = loc - 1 ;
    } 
  } 
  else if ( t == 70 ) 
  {
    if ( curchar == 66 ) 
    acc = 2 ;
    else if ( curchar == 76 ) 
    acc = 4 ;
    else if ( curchar != 77 ) 
    acc = 18 ;
    getnext () ;
    if ( curchar == 73 ) 
    acc = acc + 1 ;
    else if ( curchar != 82 ) 
    acc = 18 ;
    getnext () ;
    if ( curchar == 67 ) 
    acc = acc + 6 ;
    else if ( curchar == 69 ) 
    acc = acc + 12 ;
    else if ( curchar != 82 ) 
    acc = 18 ;
    if ( acc >= 18 ) 
    {
      {
	{
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  Fputs ( stderr ,  "Illegal face code, I changed it to MRR" ) ;
	  showerrorcontext () ;
	} 
	do {
	    getnext () ;
	} while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
      } 
      acc = 0 ;
    } 
  } 
  else {
      
    {
      if ( charsonline > 0 ) 
      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
      Fputs ( stderr ,        "You need \"C\" or \"D\" or \"O\" or \"H\" or \"F\" here" ) ;
      showerrorcontext () ;
    } 
    do {
	getnext () ;
    } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
  } 
  curchar = 32 ;
  Result = acc ;
  return Result ;
} 
integer 
getbyte ( void ) 
{
  register integer Result; integer acc  ;
  acc = getcharcode () ;
  if ( acc > 65535L ) 
  {
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "This value shouldn't exceed \"FFFF" ) ;
	showerrorcontext () ;
      } 
      do {
	  getnext () ;
      } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
    } 
    acc = 0 ;
    curchar = 32 ;
  } 
  Result = acc ;
  return Result ;
} 
void 
getfourbytes ( void ) 
{
  integer c  ;
  integer r  ;
  do {
      getnext () ;
  } while ( ! ( curchar != 32 ) ) ;
  r = 0 ;
  curbytes = zerobytes ;
  if ( curchar == 72 ) 
  r = 16 ;
  else if ( curchar == 79 ) 
  r = 8 ;
  else if ( curchar == 68 ) 
  r = 10 ;
  else {
      
    {
      if ( charsonline > 0 ) 
      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
      Fputs ( stderr ,        "Decimal (\"D\"), octal (\"O\") or hex (\"H\") value is needed here" ) ;
      showerrorcontext () ;
    } 
    do {
	getnext () ;
    } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
  } 
  if ( r > 0 ) 
  {
    do {
	getnext () ;
    } while ( ! ( curchar != 32 ) ) ;
    while ( ( ( curchar >= 48 ) && ( curchar <= 57 ) ) || ( ( curchar >= 65 ) 
    && ( curchar <= 70 ) ) ) {
	
      if ( curchar >= 65 ) 
      curchar = curchar - 7 ;
      if ( curchar >= 48 + r ) 
      {
	{
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  Fputs ( stderr ,  "Illegal digit" ) ;
	  showerrorcontext () ;
	} 
	do {
	    getnext () ;
	} while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
      } 
      else {
	  
	c = curbytes .b3 * r + curchar - 48 ;
	curbytes .b3 = c % 256 ;
	c = curbytes .b2 * r + c / 256 ;
	curbytes .b2 = c % 256 ;
	c = curbytes .b1 * r + c / 256 ;
	curbytes .b1 = c % 256 ;
	c = curbytes .b0 * r + c / 256 ;
	if ( c < 256 ) 
	curbytes .b0 = c ;
	else {
	    
	  curbytes = zerobytes ;
	  if ( r == 8 ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,                "Sorry, the maximum octal value is O 37777777777" ) ;
	      showerrorcontext () ;
	    } 
	    do {
		getnext () ;
	    } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	  } 
	  else if ( r == 10 ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,                "Sorry, the maximum decimal value is D 4294967295" ) ;
	      showerrorcontext () ;
	    } 
	    do {
		getnext () ;
	    } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	  } 
	  else {
	      
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,  "Sorry, the maximum hex value is H FFFFFFFF" ) 
	      ;
	      showerrorcontext () ;
	    } 
	    do {
		getnext () ;
	    } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	  } 
	} 
	getnext () ;
      } 
    } 
  } 
} 
integer 
getinteger ( void ) 
{
  register integer Result; integer a  ;
  getfourbytes () ;
  a = curbytes .b0 ;
  if ( a >= 128 ) 
  a = a - 256 ;
  Result = ( a * 16777216L ) + ( curbytes .b1 * 65536L ) + ( curbytes .b2 * 
  256 ) + curbytes .b3 ;
  return Result ;
} 
fixword 
getfix ( void ) 
{
  register fixword Result; boolean negative  ;
  integer acc  ;
  integer intpart  ;
  unsigned char j  ;
  do {
      getnext () ;
  } while ( ! ( curchar != 32 ) ) ;
  negative = false ;
  acc = 0 ;
  if ( ( curchar != 82 ) && ( curchar != 68 ) ) 
  {
    {
      if ( charsonline > 0 ) 
      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
      Fputs ( stderr ,  "An \"R\" or \"D\" value is needed here" ) ;
      showerrorcontext () ;
    } 
    do {
	getnext () ;
    } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
  } 
  else {
      
    do {
	getnext () ;
      if ( curchar == 45 ) 
      {
	curchar = 32 ;
	negative = ! negative ;
      } 
      else if ( curchar == 43 ) 
      curchar = 32 ;
    } while ( ! ( curchar != 32 ) ) ;
    while ( ( curchar >= 48 ) && ( curchar <= 57 ) ) {
	
      acc = acc * 10 + curchar - 48 ;
      if ( acc >= 2048 ) 
      {
	{
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "Real constants must be less than 2048" ) ;
	    showerrorcontext () ;
	  } 
	  do {
	      getnext () ;
	  } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	} 
	acc = 0 ;
	curchar = 32 ;
      } 
      else getnext () ;
    } 
    intpart = acc ;
    acc = 0 ;
    if ( curchar == 46 ) 
    {
      j = 0 ;
      getnext () ;
      while ( ( curchar >= 48 ) && ( curchar <= 57 ) ) {
	  
	if ( j < 7 ) 
	{
	  j = j + 1 ;
	  fractiondigits [j ]= 2097152L * ( curchar - 48 ) ;
	} 
	getnext () ;
      } 
      acc = 0 ;
      while ( j > 0 ) {
	  
	acc = fractiondigits [j ]+ ( acc / 10 ) ;
	j = j - 1 ;
      } 
      acc = ( acc + 10 ) / 20 ;
    } 
    if ( ( acc >= 1048576L ) && ( intpart == 2047 ) ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "Real constants must be less than 2048" ) ;
	showerrorcontext () ;
      } 
      do {
	  getnext () ;
      } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
    } 
    else acc = intpart * 1048576L + acc ;
  } 
  if ( negative ) 
  Result = - (integer) acc ;
  else Result = acc ;
  return Result ;
} 
pointer 
zsortin ( pointer h , fixword d ) 
{
  register pointer Result; pointer p  ;
  if ( ( d == 0 ) && ( h != 1 ) ) 
  Result = 0 ;
  else {
      
    p = h ;
    while ( d >= memory [link [p ]]) p = link [p ];
    if ( ( d == memory [p ]) && ( p != h ) ) 
    Result = p ;
    else if ( memptr == memsize ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "Memory overflow: too many widths, etc" ) ;
	showerrorcontext () ;
      } 
      fprintf ( stderr , "%s\n",  "Congratulations! It's hard to make this error." ) ;
      Result = p ;
    } 
    else {
	
      memptr = memptr + 1 ;
      memory [memptr ]= d ;
      link [memptr ]= link [p ];
      link [p ]= memptr ;
      memory [h ]= memory [h ]+ 1 ;
      Result = memptr ;
    } 
  } 
  return Result ;
} 
integer 
zmincover ( pointer h , fixword d ) 
{
  register integer Result; pointer p  ;
  fixword l  ;
  integer m  ;
  m = 0 ;
  p = link [h ];
  nextd = memory [0 ];
  while ( p != 0 ) {
      
    m = m + 1 ;
    l = memory [p ];
    while ( memory [link [p ]]<= l + d ) p = link [p ];
    p = link [p ];
    if ( memory [p ]- l < nextd ) 
    nextd = memory [p ]- l ;
  } 
  Result = m ;
  return Result ;
} 
fixword 
zshorten ( pointer h , integer m ) 
{
  register fixword Result; fixword d  ;
  integer k  ;
  if ( memory [h ]> m ) 
  {
    excess = memory [h ]- m ;
    k = mincover ( h , 0 ) ;
    d = nextd ;
    do {
	d = d + d ;
      k = mincover ( h , d ) ;
    } while ( ! ( k <= m ) ) ;
    d = d / 2 ;
    k = mincover ( h , d ) ;
    while ( k > m ) {
	
      d = nextd ;
      k = mincover ( h , d ) ;
    } 
    Result = d ;
  } 
  else Result = 0 ;
  return Result ;
} 
void 
zsetindices ( pointer h , fixword d ) 
{
  pointer p  ;
  pointer q  ;
  bytetype m  ;
  fixword l  ;
  q = h ;
  p = link [q ];
  m = 0 ;
  while ( p != 0 ) {
      
    m = m + 1 ;
    l = memory [p ];
    indexvar [p ]= m ;
    while ( memory [link [p ]]<= l + d ) {
	
      p = link [p ];
      indexvar [p ]= m ;
      excess = excess - 1 ;
      if ( excess == 0 ) 
      d = 0 ;
    } 
    link [q ]= p ;
    memory [p ]= l + ( memory [p ]- l ) / 2 ;
    q = p ;
    p = link [p ];
  } 
  memory [h ]= m ;
} 
void 
junkerror ( void ) 
{
  {
    if ( charsonline > 0 ) 
    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
    Fputs ( stderr ,  "There's junk here that is not in parentheses" ) ;
    showerrorcontext () ;
  } 
  do {
      getnext () ;
  } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
} 
void 
zreadfourbytes ( headerindex l ) 
{
  getfourbytes () ;
  headerbytes [l ]= curbytes .b0 ;
  headerbytes [l + 1 ]= curbytes .b1 ;
  headerbytes [l + 2 ]= curbytes .b2 ;
  headerbytes [l + 3 ]= curbytes .b3 ;
} 
void 
zreadBCPL ( headerindex l , bytetype n ) 
{
  headerindex k  ;
  k = l ;
  while ( curchar == 32 ) getnext () ;
  while ( ( curchar != 40 ) && ( curchar != 41 ) ) {
      
    if ( k < l + n ) 
    k = k + 1 ;
    if ( k < l + n ) 
    headerbytes [k ]= curchar ;
    getnext () ;
  } 
  if ( k == l + n ) 
  {
    {
      if ( charsonline > 0 ) 
      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
      fprintf ( stderr , "%s%ld%s",  "String is too long; its first " , (long)n - 1 ,       " characters will be kept" ) ;
      showerrorcontext () ;
    } 
    k = k - 1 ;
  } 
  headerbytes [l ]= k - l ;
  while ( k < l + n - 1 ) {
      
    k = k + 1 ;
    headerbytes [k ]= 0 ;
  } 
} 
void 
zchecktag ( integer c ) 
{
  switch ( chartag [c ]) 
  {case 0 : 
    ;
    break ;
  case 1 : 
    {
      if ( charsonline > 0 ) 
      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
      Fputs ( stderr ,  "This character already appeared in a LIGTABLE LABEL" ) 
      ;
      showerrorcontext () ;
    } 
    break ;
  case 2 : 
    {
      if ( charsonline > 0 ) 
      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
      Fputs ( stderr ,  "This character already has a NEXTLARGER spec" ) ;
      showerrorcontext () ;
    } 
    break ;
  case 3 : 
    {
      if ( charsonline > 0 ) 
      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
      Fputs ( stderr ,  "This character already has a VARCHAR spec" ) ;
      showerrorcontext () ;
    } 
    break ;
  } 
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
    fprintf ( stderr , "%s\n",  "Internal error: print_number" ) ;
    form = 10 ;
  } 
  while ( ( c > 0 ) || ( j == 0 ) ) {
      
    dig [j ]= c % form ;
    c = c / form ;
    j = j + 1 ;
  } 
  printdigs ( j ) ;
} 
boolean 
zhashinput ( indx p , indx c ) 
{
  /* 30 */ register boolean Result; unsigned char cc  ;
  chartype zz  ;
  chartype y  ;
  integer64 key  ;
  integer64 t64  ;
  integer t  ;
  if ( hashptr == hashsize ) 
  {
    Result = false ;
    goto lab30 ;
  } 
  y = ligkern [p ].b1 ;
  t = ligkern [p ].b2 ;
  cc = 0 ;
  zz = ligkern [p ].b3 ;
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
      {
	Result = false ;
	goto lab30 ;
      } 
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
  Result = true ;
  lab30: ;
  return Result ;
} 
#ifdef notdef
indx 
zf ( indx h , indx x , indx y ) 
{
  register indx Result; ;
  return Result ;
} 
#endif /* notdef */
indx 
zeval ( indx x , indx y ) 
{
  register indx Result; integer64 key  ;
  key = int64cast ( xmaxchar ) * x + y + 1 ;
  h = ( hashmult * key ) % hashsize ;
  while ( hash [h ]> key ) if ( h > 0 ) 
  h = h - 1 ;
  else h = hashsize ;
  if ( hash [h ]< key ) 
  Result = y ;
  else Result = f ( h , x , y ) ;
  return Result ;
} 
indx 
zf ( indx h , indx x , indx y ) 
{
  register indx Result; switch ( classvar [h ]) 
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
void 
zoutint ( integer x ) 
{
  if ( x < 0 ) 
  {
    x = x + 1073741824L ;
    x = x + 1073741824L ;
    putbyte ( ( x / 16777216L ) + 128 , tfmfile ) ;
  } 
  else putbyte ( x / 16777216L , tfmfile ) ;
  putbyte ( ( x % 16777216L ) / 65536L , tfmfile ) ;
  putbyte ( ( x % 65536L ) / 256 , tfmfile ) ;
  putbyte ( x % 256 , tfmfile ) ;
} 
void 
zoutscaled ( fixword x ) 
{
  bytetype n  ;
  unsigned short m  ;
  if ( fabs ( x / ((double) designunits ) ) >= 16.0 ) 
  {
    Fputs ( stderr ,  "The relative dimension " ) ;
    fprintreal ( stderr , x / ((double) 1048576L ) , 1 , 3 ) ;
    fprintf ( stderr , "%s\n",  " is too large." ) ;
    Fputs ( stderr ,  "  (Must be less than 16*designsize" ) ;
    if ( designunits != 1048576L ) 
    {
      Fputs ( stderr ,  " =" ) ;
      fprintreal ( stderr , designunits / ((double) 65536L ) , 1 , 3 ) ;
      Fputs ( stderr ,  " designunits" ) ;
    } 
    { putc ( ')' ,  stderr );  putc ( '\n',  stderr ); }
    x = 0 ;
  } 
  if ( designunits != 1048576L ) 
  x = round ( ( x / ((double) designunits ) ) * 1048576.0 ) ;
  if ( x < 0 ) 
  {
    putbyte ( 255 , tfmfile ) ;
    x = x + 16777216L ;
    if ( x <= 0 ) 
    x = 1 ;
  } 
  else {
      
    putbyte ( 0 , tfmfile ) ;
    if ( x >= 16777216L ) 
    x = 16777215L ;
  } 
  n = x / 65536L ;
  m = x % 65536L ;
  putbyte ( n , tfmfile ) ;
  putbyte ( m / 256 , tfmfile ) ;
  putbyte ( m % 256 , tfmfile ) ;
} 
void 
paramenter ( void ) 
{
  namelength = 5 ;
  curname [16 ]= 83 ;
  curname [17 ]= 76 ;
  curname [18 ]= 65 ;
  curname [19 ]= 78 ;
  curname [20 ]= 84 ;
  entername ( 31 ) ;
  namelength = 5 ;
  curname [16 ]= 83 ;
  curname [17 ]= 80 ;
  curname [18 ]= 65 ;
  curname [19 ]= 67 ;
  curname [20 ]= 69 ;
  entername ( 32 ) ;
  namelength = 7 ;
  curname [14 ]= 83 ;
  curname [15 ]= 84 ;
  curname [16 ]= 82 ;
  curname [17 ]= 69 ;
  curname [18 ]= 84 ;
  curname [19 ]= 67 ;
  curname [20 ]= 72 ;
  entername ( 33 ) ;
  namelength = 6 ;
  curname [15 ]= 83 ;
  curname [16 ]= 72 ;
  curname [17 ]= 82 ;
  curname [18 ]= 73 ;
  curname [19 ]= 78 ;
  curname [20 ]= 75 ;
  entername ( 34 ) ;
  namelength = 7 ;
  curname [14 ]= 88 ;
  curname [15 ]= 72 ;
  curname [16 ]= 69 ;
  curname [17 ]= 73 ;
  curname [18 ]= 71 ;
  curname [19 ]= 72 ;
  curname [20 ]= 84 ;
  entername ( 35 ) ;
  namelength = 4 ;
  curname [17 ]= 81 ;
  curname [18 ]= 85 ;
  curname [19 ]= 65 ;
  curname [20 ]= 68 ;
  entername ( 36 ) ;
  namelength = 10 ;
  curname [11 ]= 69 ;
  curname [12 ]= 88 ;
  curname [13 ]= 84 ;
  curname [14 ]= 82 ;
  curname [15 ]= 65 ;
  curname [16 ]= 83 ;
  curname [17 ]= 80 ;
  curname [18 ]= 65 ;
  curname [19 ]= 67 ;
  curname [20 ]= 69 ;
  entername ( 37 ) ;
  namelength = 4 ;
  curname [17 ]= 78 ;
  curname [18 ]= 85 ;
  curname [19 ]= 77 ;
  curname [20 ]= 49 ;
  entername ( 38 ) ;
  namelength = 4 ;
  curname [17 ]= 78 ;
  curname [18 ]= 85 ;
  curname [19 ]= 77 ;
  curname [20 ]= 50 ;
  entername ( 39 ) ;
  namelength = 4 ;
  curname [17 ]= 78 ;
  curname [18 ]= 85 ;
  curname [19 ]= 77 ;
  curname [20 ]= 51 ;
  entername ( 40 ) ;
  namelength = 6 ;
  curname [15 ]= 68 ;
  curname [16 ]= 69 ;
  curname [17 ]= 78 ;
  curname [18 ]= 79 ;
  curname [19 ]= 77 ;
  curname [20 ]= 49 ;
  entername ( 41 ) ;
  namelength = 6 ;
  curname [15 ]= 68 ;
  curname [16 ]= 69 ;
  curname [17 ]= 78 ;
  curname [18 ]= 79 ;
  curname [19 ]= 77 ;
  curname [20 ]= 50 ;
  entername ( 42 ) ;
  namelength = 4 ;
  curname [17 ]= 83 ;
  curname [18 ]= 85 ;
  curname [19 ]= 80 ;
  curname [20 ]= 49 ;
  entername ( 43 ) ;
  namelength = 4 ;
  curname [17 ]= 83 ;
  curname [18 ]= 85 ;
  curname [19 ]= 80 ;
  curname [20 ]= 50 ;
  entername ( 44 ) ;
  namelength = 4 ;
  curname [17 ]= 83 ;
  curname [18 ]= 85 ;
  curname [19 ]= 80 ;
  curname [20 ]= 51 ;
  entername ( 45 ) ;
  namelength = 4 ;
  curname [17 ]= 83 ;
  curname [18 ]= 85 ;
  curname [19 ]= 66 ;
  curname [20 ]= 49 ;
  entername ( 46 ) ;
  namelength = 4 ;
  curname [17 ]= 83 ;
  curname [18 ]= 85 ;
  curname [19 ]= 66 ;
  curname [20 ]= 50 ;
  entername ( 47 ) ;
  namelength = 7 ;
  curname [14 ]= 83 ;
  curname [15 ]= 85 ;
  curname [16 ]= 80 ;
  curname [17 ]= 68 ;
  curname [18 ]= 82 ;
  curname [19 ]= 79 ;
  curname [20 ]= 80 ;
  entername ( 48 ) ;
  namelength = 7 ;
  curname [14 ]= 83 ;
  curname [15 ]= 85 ;
  curname [16 ]= 66 ;
  curname [17 ]= 68 ;
  curname [18 ]= 82 ;
  curname [19 ]= 79 ;
  curname [20 ]= 80 ;
  entername ( 49 ) ;
  namelength = 6 ;
  curname [15 ]= 68 ;
  curname [16 ]= 69 ;
  curname [17 ]= 76 ;
  curname [18 ]= 73 ;
  curname [19 ]= 77 ;
  curname [20 ]= 49 ;
  entername ( 50 ) ;
  namelength = 6 ;
  curname [15 ]= 68 ;
  curname [16 ]= 69 ;
  curname [17 ]= 76 ;
  curname [18 ]= 73 ;
  curname [19 ]= 77 ;
  curname [20 ]= 50 ;
  entername ( 51 ) ;
  namelength = 10 ;
  curname [11 ]= 65 ;
  curname [12 ]= 88 ;
  curname [13 ]= 73 ;
  curname [14 ]= 83 ;
  curname [15 ]= 72 ;
  curname [16 ]= 69 ;
  curname [17 ]= 73 ;
  curname [18 ]= 71 ;
  curname [19 ]= 72 ;
  curname [20 ]= 84 ;
  entername ( 52 ) ;
  namelength = 20 ;
  curname [1 ]= 68 ;
  curname [2 ]= 69 ;
  curname [3 ]= 70 ;
  curname [4 ]= 65 ;
  curname [5 ]= 85 ;
  curname [6 ]= 76 ;
  curname [7 ]= 84 ;
  curname [8 ]= 82 ;
  curname [9 ]= 85 ;
  curname [10 ]= 76 ;
  curname [11 ]= 69 ;
  curname [12 ]= 84 ;
  curname [13 ]= 72 ;
  curname [14 ]= 73 ;
  curname [15 ]= 67 ;
  curname [16 ]= 75 ;
  curname [17 ]= 78 ;
  curname [18 ]= 69 ;
  curname [19 ]= 83 ;
  curname [20 ]= 83 ;
  entername ( 38 ) ;
  namelength = 13 ;
  curname [8 ]= 66 ;
  curname [9 ]= 73 ;
  curname [10 ]= 71 ;
  curname [11 ]= 79 ;
  curname [12 ]= 80 ;
  curname [13 ]= 83 ;
  curname [14 ]= 80 ;
  curname [15 ]= 65 ;
  curname [16 ]= 67 ;
  curname [17 ]= 73 ;
  curname [18 ]= 78 ;
  curname [19 ]= 71 ;
  curname [20 ]= 49 ;
  entername ( 39 ) ;
  namelength = 13 ;
  curname [8 ]= 66 ;
  curname [9 ]= 73 ;
  curname [10 ]= 71 ;
  curname [11 ]= 79 ;
  curname [12 ]= 80 ;
  curname [13 ]= 83 ;
  curname [14 ]= 80 ;
  curname [15 ]= 65 ;
  curname [16 ]= 67 ;
  curname [17 ]= 73 ;
  curname [18 ]= 78 ;
  curname [19 ]= 71 ;
  curname [20 ]= 50 ;
  entername ( 40 ) ;
  namelength = 13 ;
  curname [8 ]= 66 ;
  curname [9 ]= 73 ;
  curname [10 ]= 71 ;
  curname [11 ]= 79 ;
  curname [12 ]= 80 ;
  curname [13 ]= 83 ;
  curname [14 ]= 80 ;
  curname [15 ]= 65 ;
  curname [16 ]= 67 ;
  curname [17 ]= 73 ;
  curname [18 ]= 78 ;
  curname [19 ]= 71 ;
  curname [20 ]= 51 ;
  entername ( 41 ) ;
  namelength = 13 ;
  curname [8 ]= 66 ;
  curname [9 ]= 73 ;
  curname [10 ]= 71 ;
  curname [11 ]= 79 ;
  curname [12 ]= 80 ;
  curname [13 ]= 83 ;
  curname [14 ]= 80 ;
  curname [15 ]= 65 ;
  curname [16 ]= 67 ;
  curname [17 ]= 73 ;
  curname [18 ]= 78 ;
  curname [19 ]= 71 ;
  curname [20 ]= 52 ;
  entername ( 42 ) ;
  namelength = 13 ;
  curname [8 ]= 66 ;
  curname [9 ]= 73 ;
  curname [10 ]= 71 ;
  curname [11 ]= 79 ;
  curname [12 ]= 80 ;
  curname [13 ]= 83 ;
  curname [14 ]= 80 ;
  curname [15 ]= 65 ;
  curname [16 ]= 67 ;
  curname [17 ]= 73 ;
  curname [18 ]= 78 ;
  curname [19 ]= 71 ;
  curname [20 ]= 53 ;
  entername ( 43 ) ;
} 
void 
nameenter ( void ) 
{
  equiv [0 ]= 0 ;
  namelength = 8 ;
  curname [13 ]= 67 ;
  curname [14 ]= 72 ;
  curname [15 ]= 69 ;
  curname [16 ]= 67 ;
  curname [17 ]= 75 ;
  curname [18 ]= 83 ;
  curname [19 ]= 85 ;
  curname [20 ]= 77 ;
  entername ( 1 ) ;
  namelength = 10 ;
  curname [11 ]= 68 ;
  curname [12 ]= 69 ;
  curname [13 ]= 83 ;
  curname [14 ]= 73 ;
  curname [15 ]= 71 ;
  curname [16 ]= 78 ;
  curname [17 ]= 83 ;
  curname [18 ]= 73 ;
  curname [19 ]= 90 ;
  curname [20 ]= 69 ;
  entername ( 2 ) ;
  namelength = 11 ;
  curname [10 ]= 68 ;
  curname [11 ]= 69 ;
  curname [12 ]= 83 ;
  curname [13 ]= 73 ;
  curname [14 ]= 71 ;
  curname [15 ]= 78 ;
  curname [16 ]= 85 ;
  curname [17 ]= 78 ;
  curname [18 ]= 73 ;
  curname [19 ]= 84 ;
  curname [20 ]= 83 ;
  entername ( 3 ) ;
  namelength = 12 ;
  curname [9 ]= 67 ;
  curname [10 ]= 79 ;
  curname [11 ]= 68 ;
  curname [12 ]= 73 ;
  curname [13 ]= 78 ;
  curname [14 ]= 71 ;
  curname [15 ]= 83 ;
  curname [16 ]= 67 ;
  curname [17 ]= 72 ;
  curname [18 ]= 69 ;
  curname [19 ]= 77 ;
  curname [20 ]= 69 ;
  entername ( 4 ) ;
  namelength = 6 ;
  curname [15 ]= 70 ;
  curname [16 ]= 65 ;
  curname [17 ]= 77 ;
  curname [18 ]= 73 ;
  curname [19 ]= 76 ;
  curname [20 ]= 89 ;
  entername ( 5 ) ;
  namelength = 4 ;
  curname [17 ]= 70 ;
  curname [18 ]= 65 ;
  curname [19 ]= 67 ;
  curname [20 ]= 69 ;
  entername ( 6 ) ;
  namelength = 16 ;
  curname [5 ]= 83 ;
  curname [6 ]= 69 ;
  curname [7 ]= 86 ;
  curname [8 ]= 69 ;
  curname [9 ]= 78 ;
  curname [10 ]= 66 ;
  curname [11 ]= 73 ;
  curname [12 ]= 84 ;
  curname [13 ]= 83 ;
  curname [14 ]= 65 ;
  curname [15 ]= 70 ;
  curname [16 ]= 69 ;
  curname [17 ]= 70 ;
  curname [18 ]= 76 ;
  curname [19 ]= 65 ;
  curname [20 ]= 71 ;
  entername ( 7 ) ;
  namelength = 6 ;
  curname [15 ]= 72 ;
  curname [16 ]= 69 ;
  curname [17 ]= 65 ;
  curname [18 ]= 68 ;
  curname [19 ]= 69 ;
  curname [20 ]= 82 ;
  entername ( 8 ) ;
  namelength = 9 ;
  curname [12 ]= 70 ;
  curname [13 ]= 79 ;
  curname [14 ]= 78 ;
  curname [15 ]= 84 ;
  curname [16 ]= 68 ;
  curname [17 ]= 73 ;
  curname [18 ]= 77 ;
  curname [19 ]= 69 ;
  curname [20 ]= 78 ;
  entername ( 9 ) ;
  namelength = 8 ;
  curname [13 ]= 76 ;
  curname [14 ]= 73 ;
  curname [15 ]= 71 ;
  curname [16 ]= 84 ;
  curname [17 ]= 65 ;
  curname [18 ]= 66 ;
  curname [19 ]= 76 ;
  curname [20 ]= 69 ;
  entername ( 10 ) ;
  namelength = 12 ;
  curname [9 ]= 66 ;
  curname [10 ]= 79 ;
  curname [11 ]= 85 ;
  curname [12 ]= 78 ;
  curname [13 ]= 68 ;
  curname [14 ]= 65 ;
  curname [15 ]= 82 ;
  curname [16 ]= 89 ;
  curname [17 ]= 67 ;
  curname [18 ]= 72 ;
  curname [19 ]= 65 ;
  curname [20 ]= 82 ;
  entername ( 11 ) ;
  namelength = 9 ;
  curname [12 ]= 67 ;
  curname [13 ]= 72 ;
  curname [14 ]= 65 ;
  curname [15 ]= 82 ;
  curname [16 ]= 65 ;
  curname [17 ]= 67 ;
  curname [18 ]= 84 ;
  curname [19 ]= 69 ;
  curname [20 ]= 82 ;
  entername ( 14 ) ;
  namelength = 9 ;
  curname [12 ]= 80 ;
  curname [13 ]= 65 ;
  curname [14 ]= 82 ;
  curname [15 ]= 65 ;
  curname [16 ]= 77 ;
  curname [17 ]= 69 ;
  curname [18 ]= 84 ;
  curname [19 ]= 69 ;
  curname [20 ]= 82 ;
  entername ( 30 ) ;
  namelength = 6 ;
  curname [15 ]= 67 ;
  curname [16 ]= 72 ;
  curname [17 ]= 65 ;
  curname [18 ]= 82 ;
  curname [19 ]= 87 ;
  curname [20 ]= 68 ;
  entername ( 71 ) ;
  namelength = 6 ;
  curname [15 ]= 67 ;
  curname [16 ]= 72 ;
  curname [17 ]= 65 ;
  curname [18 ]= 82 ;
  curname [19 ]= 72 ;
  curname [20 ]= 84 ;
  entername ( 72 ) ;
  namelength = 6 ;
  curname [15 ]= 67 ;
  curname [16 ]= 72 ;
  curname [17 ]= 65 ;
  curname [18 ]= 82 ;
  curname [19 ]= 68 ;
  curname [20 ]= 80 ;
  entername ( 73 ) ;
  namelength = 6 ;
  curname [15 ]= 67 ;
  curname [16 ]= 72 ;
  curname [17 ]= 65 ;
  curname [18 ]= 82 ;
  curname [19 ]= 73 ;
  curname [20 ]= 67 ;
  entername ( 74 ) ;
  namelength = 5 ;
  curname [16 ]= 83 ;
  curname [17 ]= 69 ;
  curname [18 ]= 67 ;
  curname [19 ]= 87 ;
  curname [20 ]= 68 ;
  entername ( 75 ) ;
  namelength = 5 ;
  curname [16 ]= 83 ;
  curname [17 ]= 69 ;
  curname [18 ]= 67 ;
  curname [19 ]= 72 ;
  curname [20 ]= 84 ;
  entername ( 76 ) ;
  namelength = 5 ;
  curname [16 ]= 83 ;
  curname [17 ]= 69 ;
  curname [18 ]= 67 ;
  curname [19 ]= 68 ;
  curname [20 ]= 80 ;
  entername ( 77 ) ;
  namelength = 5 ;
  curname [16 ]= 83 ;
  curname [17 ]= 69 ;
  curname [18 ]= 67 ;
  curname [19 ]= 73 ;
  curname [20 ]= 67 ;
  entername ( 78 ) ;
  namelength = 6 ;
  curname [15 ]= 65 ;
  curname [16 ]= 67 ;
  curname [17 ]= 67 ;
  curname [18 ]= 69 ;
  curname [19 ]= 78 ;
  curname [20 ]= 84 ;
  entername ( 79 ) ;
  namelength = 11 ;
  curname [10 ]= 80 ;
  curname [11 ]= 82 ;
  curname [12 ]= 73 ;
  curname [13 ]= 77 ;
  curname [14 ]= 84 ;
  curname [15 ]= 79 ;
  curname [16 ]= 80 ;
  curname [17 ]= 65 ;
  curname [18 ]= 88 ;
  curname [19 ]= 73 ;
  curname [20 ]= 83 ;
  entername ( 80 ) ;
  namelength = 14 ;
  curname [7 ]= 80 ;
  curname [8 ]= 82 ;
  curname [9 ]= 73 ;
  curname [10 ]= 77 ;
  curname [11 ]= 84 ;
  curname [12 ]= 79 ;
  curname [13 ]= 80 ;
  curname [14 ]= 65 ;
  curname [15 ]= 88 ;
  curname [16 ]= 73 ;
  curname [17 ]= 83 ;
  curname [18 ]= 66 ;
  curname [19 ]= 73 ;
  curname [20 ]= 83 ;
  entername ( 81 ) ;
  namelength = 11 ;
  curname [10 ]= 80 ;
  curname [11 ]= 82 ;
  curname [12 ]= 73 ;
  curname [13 ]= 77 ;
  curname [14 ]= 66 ;
  curname [15 ]= 79 ;
  curname [16 ]= 84 ;
  curname [17 ]= 65 ;
  curname [18 ]= 88 ;
  curname [19 ]= 73 ;
  curname [20 ]= 83 ;
  entername ( 82 ) ;
  namelength = 14 ;
  curname [7 ]= 80 ;
  curname [8 ]= 82 ;
  curname [9 ]= 73 ;
  curname [10 ]= 77 ;
  curname [11 ]= 66 ;
  curname [12 ]= 79 ;
  curname [13 ]= 84 ;
  curname [14 ]= 65 ;
  curname [15 ]= 88 ;
  curname [16 ]= 73 ;
  curname [17 ]= 83 ;
  curname [18 ]= 66 ;
  curname [19 ]= 73 ;
  curname [20 ]= 83 ;
  entername ( 83 ) ;
  namelength = 10 ;
  curname [11 ]= 80 ;
  curname [12 ]= 82 ;
  curname [13 ]= 73 ;
  curname [14 ]= 77 ;
  curname [15 ]= 77 ;
  curname [16 ]= 73 ;
  curname [17 ]= 68 ;
  curname [18 ]= 72 ;
  curname [19 ]= 79 ;
  curname [20 ]= 82 ;
  entername ( 84 ) ;
  namelength = 10 ;
  curname [11 ]= 80 ;
  curname [12 ]= 82 ;
  curname [13 ]= 73 ;
  curname [14 ]= 77 ;
  curname [15 ]= 77 ;
  curname [16 ]= 73 ;
  curname [17 ]= 68 ;
  curname [18 ]= 86 ;
  curname [19 ]= 69 ;
  curname [20 ]= 82 ;
  entername ( 85 ) ;
  namelength = 13 ;
  curname [8 ]= 80 ;
  curname [9 ]= 82 ;
  curname [10 ]= 73 ;
  curname [11 ]= 77 ;
  curname [12 ]= 66 ;
  curname [13 ]= 65 ;
  curname [14 ]= 83 ;
  curname [15 ]= 69 ;
  curname [16 ]= 83 ;
  curname [17 ]= 76 ;
  curname [18 ]= 65 ;
  curname [19 ]= 78 ;
  curname [20 ]= 84 ;
  entername ( 86 ) ;
  namelength = 10 ;
  curname [11 ]= 83 ;
  curname [12 ]= 69 ;
  curname [13 ]= 67 ;
  curname [14 ]= 84 ;
  curname [15 ]= 79 ;
  curname [16 ]= 80 ;
  curname [17 ]= 65 ;
  curname [18 ]= 88 ;
  curname [19 ]= 73 ;
  curname [20 ]= 83 ;
  entername ( 87 ) ;
  namelength = 13 ;
  curname [8 ]= 83 ;
  curname [9 ]= 69 ;
  curname [10 ]= 67 ;
  curname [11 ]= 84 ;
  curname [12 ]= 79 ;
  curname [13 ]= 80 ;
  curname [14 ]= 65 ;
  curname [15 ]= 88 ;
  curname [16 ]= 73 ;
  curname [17 ]= 83 ;
  curname [18 ]= 66 ;
  curname [19 ]= 73 ;
  curname [20 ]= 83 ;
  entername ( 88 ) ;
  namelength = 10 ;
  curname [11 ]= 83 ;
  curname [12 ]= 69 ;
  curname [13 ]= 67 ;
  curname [14 ]= 66 ;
  curname [15 ]= 79 ;
  curname [16 ]= 84 ;
  curname [17 ]= 65 ;
  curname [18 ]= 88 ;
  curname [19 ]= 73 ;
  curname [20 ]= 83 ;
  entername ( 89 ) ;
  namelength = 13 ;
  curname [8 ]= 83 ;
  curname [9 ]= 69 ;
  curname [10 ]= 67 ;
  curname [11 ]= 66 ;
  curname [12 ]= 79 ;
  curname [13 ]= 84 ;
  curname [14 ]= 65 ;
  curname [15 ]= 88 ;
  curname [16 ]= 73 ;
  curname [17 ]= 83 ;
  curname [18 ]= 66 ;
  curname [19 ]= 73 ;
  curname [20 ]= 83 ;
  entername ( 90 ) ;
  namelength = 9 ;
  curname [12 ]= 83 ;
  curname [13 ]= 69 ;
  curname [14 ]= 67 ;
  curname [15 ]= 77 ;
  curname [16 ]= 73 ;
  curname [17 ]= 68 ;
  curname [18 ]= 72 ;
  curname [19 ]= 79 ;
  curname [20 ]= 82 ;
  entername ( 91 ) ;
  namelength = 9 ;
  curname [12 ]= 83 ;
  curname [13 ]= 69 ;
  curname [14 ]= 67 ;
  curname [15 ]= 77 ;
  curname [16 ]= 73 ;
  curname [17 ]= 68 ;
  curname [18 ]= 86 ;
  curname [19 ]= 69 ;
  curname [20 ]= 82 ;
  entername ( 92 ) ;
  namelength = 12 ;
  curname [9 ]= 83 ;
  curname [10 ]= 69 ;
  curname [11 ]= 67 ;
  curname [12 ]= 66 ;
  curname [13 ]= 65 ;
  curname [14 ]= 83 ;
  curname [15 ]= 69 ;
  curname [16 ]= 83 ;
  curname [17 ]= 76 ;
  curname [18 ]= 65 ;
  curname [19 ]= 78 ;
  curname [20 ]= 84 ;
  entername ( 93 ) ;
  namelength = 10 ;
  curname [11 ]= 78 ;
  curname [12 ]= 69 ;
  curname [13 ]= 88 ;
  curname [14 ]= 84 ;
  curname [15 ]= 76 ;
  curname [16 ]= 65 ;
  curname [17 ]= 82 ;
  curname [18 ]= 71 ;
  curname [19 ]= 69 ;
  curname [20 ]= 82 ;
  entername ( 100 ) ;
  namelength = 7 ;
  curname [14 ]= 86 ;
  curname [15 ]= 65 ;
  curname [16 ]= 82 ;
  curname [17 ]= 67 ;
  curname [18 ]= 72 ;
  curname [19 ]= 65 ;
  curname [20 ]= 82 ;
  entername ( 117 ) ;
  namelength = 3 ;
  curname [18 ]= 84 ;
  curname [19 ]= 79 ;
  curname [20 ]= 80 ;
  entername ( 118 ) ;
  namelength = 3 ;
  curname [18 ]= 77 ;
  curname [19 ]= 73 ;
  curname [20 ]= 68 ;
  entername ( 119 ) ;
  namelength = 3 ;
  curname [18 ]= 66 ;
  curname [19 ]= 79 ;
  curname [20 ]= 84 ;
  entername ( 120 ) ;
  namelength = 3 ;
  curname [18 ]= 82 ;
  curname [19 ]= 69 ;
  curname [20 ]= 80 ;
  entername ( 121 ) ;
  namelength = 3 ;
  curname [18 ]= 69 ;
  curname [19 ]= 88 ;
  curname [20 ]= 84 ;
  entername ( 121 ) ;
  namelength = 7 ;
  curname [14 ]= 67 ;
  curname [15 ]= 79 ;
  curname [16 ]= 77 ;
  curname [17 ]= 77 ;
  curname [18 ]= 69 ;
  curname [19 ]= 78 ;
  curname [20 ]= 84 ;
  entername ( 0 ) ;
  namelength = 5 ;
  curname [16 ]= 76 ;
  curname [17 ]= 65 ;
  curname [18 ]= 66 ;
  curname [19 ]= 69 ;
  curname [20 ]= 76 ;
  entername ( 130 ) ;
  namelength = 4 ;
  curname [17 ]= 83 ;
  curname [18 ]= 84 ;
  curname [19 ]= 79 ;
  curname [20 ]= 80 ;
  entername ( 131 ) ;
  namelength = 4 ;
  curname [17 ]= 83 ;
  curname [18 ]= 75 ;
  curname [19 ]= 73 ;
  curname [20 ]= 80 ;
  entername ( 132 ) ;
  namelength = 3 ;
  curname [18 ]= 75 ;
  curname [19 ]= 82 ;
  curname [20 ]= 78 ;
  entername ( 133 ) ;
  namelength = 3 ;
  curname [18 ]= 76 ;
  curname [19 ]= 73 ;
  curname [20 ]= 71 ;
  entername ( 134 ) ;
  namelength = 4 ;
  curname [17 ]= 47 ;
  curname [18 ]= 76 ;
  curname [19 ]= 73 ;
  curname [20 ]= 71 ;
  entername ( 136 ) ;
  namelength = 5 ;
  curname [16 ]= 47 ;
  curname [17 ]= 76 ;
  curname [18 ]= 73 ;
  curname [19 ]= 71 ;
  curname [20 ]= 62 ;
  entername ( 140 ) ;
  namelength = 4 ;
  curname [17 ]= 76 ;
  curname [18 ]= 73 ;
  curname [19 ]= 71 ;
  curname [20 ]= 47 ;
  entername ( 135 ) ;
  namelength = 5 ;
  curname [16 ]= 76 ;
  curname [17 ]= 73 ;
  curname [18 ]= 71 ;
  curname [19 ]= 47 ;
  curname [20 ]= 62 ;
  entername ( 139 ) ;
  namelength = 5 ;
  curname [16 ]= 47 ;
  curname [17 ]= 76 ;
  curname [18 ]= 73 ;
  curname [19 ]= 71 ;
  curname [20 ]= 47 ;
  entername ( 137 ) ;
  namelength = 6 ;
  curname [15 ]= 47 ;
  curname [16 ]= 76 ;
  curname [17 ]= 73 ;
  curname [18 ]= 71 ;
  curname [19 ]= 47 ;
  curname [20 ]= 62 ;
  entername ( 141 ) ;
  namelength = 7 ;
  curname [14 ]= 47 ;
  curname [15 ]= 76 ;
  curname [16 ]= 73 ;
  curname [17 ]= 71 ;
  curname [18 ]= 47 ;
  curname [19 ]= 62 ;
  curname [20 ]= 62 ;
  entername ( 145 ) ;
  namelength = 6 ;
  curname [15 ]= 67 ;
  curname [16 ]= 76 ;
  curname [17 ]= 65 ;
  curname [18 ]= 66 ;
  curname [19 ]= 69 ;
  curname [20 ]= 76 ;
  entername ( 150 ) ;
  namelength = 4 ;
  curname [17 ]= 67 ;
  curname [18 ]= 80 ;
  curname [19 ]= 69 ;
  curname [20 ]= 78 ;
  entername ( 151 ) ;
  namelength = 5 ;
  curname [16 ]= 67 ;
  curname [17 ]= 71 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 152 ) ;
  namelength = 8 ;
  curname [13 ]= 67 ;
  curname [14 ]= 80 ;
  curname [15 ]= 69 ;
  curname [16 ]= 78 ;
  curname [17 ]= 71 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 153 ) ;
  namelength = 4 ;
  curname [17 ]= 67 ;
  curname [18 ]= 75 ;
  curname [19 ]= 82 ;
  curname [20 ]= 78 ;
  entername ( 154 ) ;
  namelength = 8 ;
  curname [13 ]= 79 ;
  curname [14 ]= 70 ;
  curname [15 ]= 77 ;
  curname [16 ]= 76 ;
  curname [17 ]= 69 ;
  curname [18 ]= 86 ;
  curname [19 ]= 69 ;
  curname [20 ]= 76 ;
  entername ( 17 ) ;
  namelength = 7 ;
  curname [14 ]= 70 ;
  curname [15 ]= 79 ;
  curname [16 ]= 78 ;
  curname [17 ]= 84 ;
  curname [18 ]= 68 ;
  curname [19 ]= 73 ;
  curname [20 ]= 82 ;
  entername ( 15 ) ;
  namelength = 8 ;
  curname [13 ]= 78 ;
  curname [14 ]= 70 ;
  curname [15 ]= 79 ;
  curname [16 ]= 78 ;
  curname [17 ]= 84 ;
  curname [18 ]= 68 ;
  curname [19 ]= 73 ;
  curname [20 ]= 82 ;
  entername ( 16 ) ;
  namelength = 14 ;
  curname [7 ]= 78 ;
  curname [8 ]= 65 ;
  curname [9 ]= 84 ;
  curname [10 ]= 85 ;
  curname [11 ]= 82 ;
  curname [12 ]= 65 ;
  curname [13 ]= 76 ;
  curname [14 ]= 70 ;
  curname [15 ]= 79 ;
  curname [16 ]= 78 ;
  curname [17 ]= 84 ;
  curname [18 ]= 68 ;
  curname [19 ]= 73 ;
  curname [20 ]= 82 ;
  entername ( 16 ) ;
  namelength = 10 ;
  curname [11 ]= 67 ;
  curname [12 ]= 72 ;
  curname [13 ]= 65 ;
  curname [14 ]= 82 ;
  curname [15 ]= 82 ;
  curname [16 ]= 69 ;
  curname [17 ]= 80 ;
  curname [18 ]= 69 ;
  curname [19 ]= 65 ;
  curname [20 ]= 84 ;
  entername ( 24 ) ;
  namelength = 10 ;
  curname [11 ]= 67 ;
  curname [12 ]= 72 ;
  curname [13 ]= 65 ;
  curname [14 ]= 82 ;
  curname [15 ]= 73 ;
  curname [16 ]= 86 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 111 ) ;
  namelength = 10 ;
  curname [11 ]= 67 ;
  curname [12 ]= 72 ;
  curname [13 ]= 65 ;
  curname [14 ]= 82 ;
  curname [15 ]= 70 ;
  curname [16 ]= 86 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 112 ) ;
  namelength = 10 ;
  curname [11 ]= 67 ;
  curname [12 ]= 72 ;
  curname [13 ]= 65 ;
  curname [14 ]= 82 ;
  curname [15 ]= 77 ;
  curname [16 ]= 86 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 113 ) ;
  namelength = 8 ;
  curname [13 ]= 67 ;
  curname [14 ]= 72 ;
  curname [15 ]= 65 ;
  curname [16 ]= 82 ;
  curname [17 ]= 82 ;
  curname [18 ]= 85 ;
  curname [19 ]= 76 ;
  curname [20 ]= 69 ;
  entername ( 114 ) ;
  namelength = 8 ;
  curname [13 ]= 67 ;
  curname [14 ]= 72 ;
  curname [15 ]= 65 ;
  curname [16 ]= 82 ;
  curname [17 ]= 71 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 115 ) ;
  namelength = 11 ;
  curname [10 ]= 67 ;
  curname [11 ]= 72 ;
  curname [12 ]= 65 ;
  curname [13 ]= 82 ;
  curname [14 ]= 80 ;
  curname [15 ]= 69 ;
  curname [16 ]= 78 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 84 ;
  curname [20 ]= 89 ;
  entername ( 116 ) ;
  namelength = 8 ;
  curname [13 ]= 70 ;
  curname [14 ]= 79 ;
  curname [15 ]= 78 ;
  curname [16 ]= 84 ;
  curname [17 ]= 82 ;
  curname [18 ]= 85 ;
  curname [19 ]= 76 ;
  curname [20 ]= 69 ;
  entername ( 18 ) ;
  namelength = 4 ;
  curname [17 ]= 82 ;
  curname [18 ]= 85 ;
  curname [19 ]= 76 ;
  curname [20 ]= 69 ;
  entername ( 161 ) ;
  namelength = 6 ;
  curname [15 ]= 82 ;
  curname [16 ]= 85 ;
  curname [17 ]= 76 ;
  curname [18 ]= 69 ;
  curname [19 ]= 87 ;
  curname [20 ]= 68 ;
  entername ( 162 ) ;
  namelength = 6 ;
  curname [15 ]= 82 ;
  curname [16 ]= 85 ;
  curname [17 ]= 76 ;
  curname [18 ]= 69 ;
  curname [19 ]= 72 ;
  curname [20 ]= 84 ;
  entername ( 163 ) ;
  namelength = 6 ;
  curname [15 ]= 82 ;
  curname [16 ]= 85 ;
  curname [17 ]= 76 ;
  curname [18 ]= 69 ;
  curname [19 ]= 68 ;
  curname [20 ]= 80 ;
  entername ( 164 ) ;
  namelength = 8 ;
  curname [13 ]= 70 ;
  curname [14 ]= 79 ;
  curname [15 ]= 78 ;
  curname [16 ]= 84 ;
  curname [17 ]= 71 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 19 ) ;
  namelength = 4 ;
  curname [17 ]= 71 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 171 ) ;
  namelength = 8 ;
  curname [13 ]= 71 ;
  curname [14 ]= 76 ;
  curname [15 ]= 85 ;
  curname [16 ]= 69 ;
  curname [17 ]= 84 ;
  curname [18 ]= 89 ;
  curname [19 ]= 80 ;
  curname [20 ]= 69 ;
  entername ( 172 ) ;
  namelength = 16 ;
  curname [5 ]= 71 ;
  curname [6 ]= 76 ;
  curname [7 ]= 85 ;
  curname [8 ]= 69 ;
  curname [9 ]= 83 ;
  curname [10 ]= 84 ;
  curname [11 ]= 82 ;
  curname [12 ]= 69 ;
  curname [13 ]= 84 ;
  curname [14 ]= 67 ;
  curname [15 ]= 72 ;
  curname [16 ]= 79 ;
  curname [17 ]= 82 ;
  curname [18 ]= 68 ;
  curname [19 ]= 69 ;
  curname [20 ]= 82 ;
  entername ( 173 ) ;
  namelength = 15 ;
  curname [6 ]= 71 ;
  curname [7 ]= 76 ;
  curname [8 ]= 85 ;
  curname [9 ]= 69 ;
  curname [10 ]= 83 ;
  curname [11 ]= 72 ;
  curname [12 ]= 82 ;
  curname [13 ]= 73 ;
  curname [14 ]= 78 ;
  curname [15 ]= 75 ;
  curname [16 ]= 79 ;
  curname [17 ]= 82 ;
  curname [18 ]= 68 ;
  curname [19 ]= 69 ;
  curname [20 ]= 82 ;
  entername ( 174 ) ;
  namelength = 8 ;
  curname [13 ]= 71 ;
  curname [14 ]= 76 ;
  curname [15 ]= 85 ;
  curname [16 ]= 69 ;
  curname [17 ]= 82 ;
  curname [18 ]= 85 ;
  curname [19 ]= 76 ;
  curname [20 ]= 69 ;
  entername ( 179 ) ;
  namelength = 8 ;
  curname [13 ]= 71 ;
  curname [14 ]= 76 ;
  curname [15 ]= 85 ;
  curname [16 ]= 69 ;
  curname [17 ]= 67 ;
  curname [18 ]= 72 ;
  curname [19 ]= 65 ;
  curname [20 ]= 82 ;
  entername ( 178 ) ;
  namelength = 6 ;
  curname [15 ]= 71 ;
  curname [16 ]= 76 ;
  curname [17 ]= 85 ;
  curname [18 ]= 69 ;
  curname [19 ]= 87 ;
  curname [20 ]= 68 ;
  entername ( 175 ) ;
  namelength = 11 ;
  curname [10 ]= 71 ;
  curname [11 ]= 76 ;
  curname [12 ]= 85 ;
  curname [13 ]= 69 ;
  curname [14 ]= 83 ;
  curname [15 ]= 84 ;
  curname [16 ]= 82 ;
  curname [17 ]= 69 ;
  curname [18 ]= 84 ;
  curname [19 ]= 67 ;
  curname [20 ]= 72 ;
  entername ( 176 ) ;
  namelength = 10 ;
  curname [11 ]= 71 ;
  curname [12 ]= 76 ;
  curname [13 ]= 85 ;
  curname [14 ]= 69 ;
  curname [15 ]= 83 ;
  curname [16 ]= 72 ;
  curname [17 ]= 82 ;
  curname [18 ]= 73 ;
  curname [19 ]= 78 ;
  curname [20 ]= 75 ;
  entername ( 177 ) ;
  namelength = 11 ;
  curname [10 ]= 70 ;
  curname [11 ]= 79 ;
  curname [12 ]= 78 ;
  curname [13 ]= 84 ;
  curname [14 ]= 80 ;
  curname [15 ]= 69 ;
  curname [16 ]= 78 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 84 ;
  curname [20 ]= 89 ;
  entername ( 20 ) ;
  namelength = 7 ;
  curname [14 ]= 80 ;
  curname [15 ]= 69 ;
  curname [16 ]= 78 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 84 ;
  curname [20 ]= 89 ;
  entername ( 191 ) ;
  namelength = 10 ;
  curname [11 ]= 80 ;
  curname [12 ]= 69 ;
  curname [13 ]= 78 ;
  curname [14 ]= 65 ;
  curname [15 ]= 76 ;
  curname [16 ]= 84 ;
  curname [17 ]= 89 ;
  curname [18 ]= 86 ;
  curname [19 ]= 65 ;
  curname [20 ]= 76 ;
  entername ( 192 ) ;
  namelength = 10 ;
  curname [11 ]= 70 ;
  curname [12 ]= 79 ;
  curname [13 ]= 78 ;
  curname [14 ]= 84 ;
  curname [15 ]= 77 ;
  curname [16 ]= 86 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 21 ) ;
  namelength = 6 ;
  curname [15 ]= 77 ;
  curname [16 ]= 86 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 193 ) ;
  namelength = 9 ;
  curname [12 ]= 77 ;
  curname [13 ]= 86 ;
  curname [14 ]= 65 ;
  curname [15 ]= 76 ;
  curname [16 ]= 85 ;
  curname [17 ]= 69 ;
  curname [18 ]= 86 ;
  curname [19 ]= 65 ;
  curname [20 ]= 76 ;
  entername ( 194 ) ;
  namelength = 10 ;
  curname [11 ]= 70 ;
  curname [12 ]= 79 ;
  curname [13 ]= 78 ;
  curname [14 ]= 84 ;
  curname [15 ]= 70 ;
  curname [16 ]= 86 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 22 ) ;
  namelength = 6 ;
  curname [15 ]= 70 ;
  curname [16 ]= 86 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 195 ) ;
  namelength = 9 ;
  curname [12 ]= 70 ;
  curname [13 ]= 86 ;
  curname [14 ]= 65 ;
  curname [15 ]= 76 ;
  curname [16 ]= 85 ;
  curname [17 ]= 69 ;
  curname [18 ]= 86 ;
  curname [19 ]= 65 ;
  curname [20 ]= 76 ;
  entername ( 196 ) ;
  namelength = 10 ;
  curname [11 ]= 70 ;
  curname [12 ]= 79 ;
  curname [13 ]= 78 ;
  curname [14 ]= 84 ;
  curname [15 ]= 73 ;
  curname [16 ]= 86 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 23 ) ;
  namelength = 6 ;
  curname [15 ]= 73 ;
  curname [16 ]= 86 ;
  curname [17 ]= 65 ;
  curname [18 ]= 76 ;
  curname [19 ]= 85 ;
  curname [20 ]= 69 ;
  entername ( 197 ) ;
  namelength = 9 ;
  curname [12 ]= 73 ;
  curname [13 ]= 86 ;
  curname [14 ]= 65 ;
  curname [15 ]= 76 ;
  curname [16 ]= 85 ;
  curname [17 ]= 69 ;
  curname [18 ]= 86 ;
  curname [19 ]= 65 ;
  curname [20 ]= 76 ;
  entername ( 198 ) ;
  paramenter () ;
} 
void 
readligkern ( void ) 
{
  {
    lkstepended = false ;
    while ( level == 1 ) {
	
      while ( curchar == 32 ) getnext () ;
      if ( curchar == 40 ) 
      readligkerncommand () ;
      else if ( curchar == 41 ) 
      skiptoendofitem () ;
      else junkerror () ;
    } 
    {
      loc = loc - 1 ;
      level = level + 1 ;
      curchar = 41 ;
    } 
  } 
} 
void 
outputnewinformationofm ( void ) 
{
  {
    {
      {register integer for_end; iarray = 0 ;for_end = nki - 1 ; if ( iarray 
      <= for_end) do 
	{
	  putbyte ( ( npi [iarray ]) / 16777216L , tfmfile ) ;
	  putbyte ( ( ( npi [iarray ]) % 16777216L ) / 65536L , tfmfile ) ;
	  putbyte ( ( ( npi [iarray ]) % 65536L ) / 256 , tfmfile ) ;
	  putbyte ( ( npi [iarray ]) % 256 , tfmfile ) ;
	} 
      while ( iarray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; farray = 0 ;for_end = nkf - 1 ; if ( farray 
      <= for_end) do 
	{
	  putbyte ( ( npf [farray ]) / 16777216L , tfmfile ) ;
	  putbyte ( ( ( npf [farray ]) % 16777216L ) / 65536L , tfmfile ) ;
	  putbyte ( ( ( npf [farray ]) % 65536L ) / 256 , tfmfile ) ;
	  putbyte ( ( npf [farray ]) % 256 , tfmfile ) ;
	} 
      while ( farray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; marray = 0 ;for_end = nkm - 1 ; if ( marray 
      <= for_end) do 
	{
	  putbyte ( ( npm [marray ]) / 16777216L , tfmfile ) ;
	  putbyte ( ( ( npm [marray ]) % 16777216L ) / 65536L , tfmfile ) ;
	  putbyte ( ( ( npm [marray ]) % 65536L ) / 256 , tfmfile ) ;
	  putbyte ( ( npm [marray ]) % 256 , tfmfile ) ;
	} 
      while ( marray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; rarray = 0 ;for_end = nkr - 1 ; if ( rarray 
      <= for_end) do 
	{
	  putbyte ( ( npr [rarray ]) / 16777216L , tfmfile ) ;
	  putbyte ( ( ( npr [rarray ]) % 16777216L ) / 65536L , tfmfile ) ;
	  putbyte ( ( ( npr [rarray ]) % 65536L ) / 256 , tfmfile ) ;
	  putbyte ( ( npr [rarray ]) % 256 , tfmfile ) ;
	} 
      while ( rarray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; garray = 0 ;for_end = nkg - 1 ; if ( garray 
      <= for_end) do 
	{
	  putbyte ( ( npg [garray ]) / 16777216L , tfmfile ) ;
	  putbyte ( ( ( npg [garray ]) % 16777216L ) / 65536L , tfmfile ) ;
	  putbyte ( ( ( npg [garray ]) % 65536L ) / 256 , tfmfile ) ;
	  putbyte ( ( npg [garray ]) % 256 , tfmfile ) ;
	} 
      while ( garray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; parray = 0 ;for_end = nkp - 1 ; if ( parray 
      <= for_end) do 
	{
	  putbyte ( ( npp [parray ]) / 16777216L , tfmfile ) ;
	  putbyte ( ( ( npp [parray ]) % 16777216L ) / 65536L , tfmfile ) ;
	  putbyte ( ( ( npp [parray ]) % 65536L ) / 256 , tfmfile ) ;
	  putbyte ( ( npp [parray ]) % 256 , tfmfile ) ;
	} 
      while ( parray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; iarray = 0 ;for_end = nki - 1 ; if ( iarray 
      <= for_end) do 
	{register integer for_end; inumber = 0 ;for_end = npi [iarray ]- 1 
	; if ( inumber <= for_end) do 
	  {
	    outint ( ivalues [iarray ][ inumber ].inval ) ;
	  } 
	while ( inumber++ < for_end ) ;} 
      while ( iarray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; farray = 0 ;for_end = nkf - 1 ; if ( farray 
      <= for_end) do 
	{register integer for_end; fnumber = 0 ;for_end = npf [farray ]- 1 
	; if ( fnumber <= for_end) do 
	  {
	    outscaled ( fvalues [farray ][ fnumber ].fnval ) ;
	  } 
	while ( fnumber++ < for_end ) ;} 
      while ( farray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; marray = 0 ;for_end = nkm - 1 ; if ( marray 
      <= for_end) do 
	{register integer for_end; mnumber = 0 ;for_end = npm [marray ]- 1 
	; if ( mnumber <= for_end) do 
	  {
	    outscaled ( mvalues [marray ][ mnumber ].fnval ) ;
	  } 
	while ( mnumber++ < for_end ) ;} 
      while ( marray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; rarray = 0 ;for_end = nkr - 1 ; if ( rarray 
      <= for_end) do 
	{register integer for_end; rnumber = 0 ;for_end = npr [rarray ]- 1 
	; if ( rnumber <= for_end) do 
	  {
	    outscaled ( rules [rarray ][ rnumber ].rnwidth ) ;
	    outscaled ( rules [rarray ][ rnumber ].rnheight ) ;
	    outscaled ( rules [rarray ][ rnumber ].rndepth ) ;
	  } 
	while ( rnumber++ < for_end ) ;} 
      while ( rarray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; garray = 0 ;for_end = nkg - 1 ; if ( garray 
      <= for_end) do 
	{register integer for_end; gnumber = 0 ;for_end = npg [garray ]- 1 
	; if ( gnumber <= for_end) do 
	  {
	    gbyte = glues [garray ][ gnumber ].gntype * 16 + glues [garray 
	    ][ gnumber ].gnargtype ;
	    putbyte ( gbyte , tfmfile ) ;
	    gbyte = glues [garray ][ gnumber ].gnstretchorder * 16 + glues [
	    garray ][ gnumber ].gnshrinkorder ;
	    putbyte ( gbyte , tfmfile ) ;
	    gbyte = glues [garray ][ gnumber ].gnargument / 256 ;
	    putbyte ( gbyte , tfmfile ) ;
	    gbyte = glues [garray ][ gnumber ].gnargument % 256 ;
	    putbyte ( gbyte , tfmfile ) ;
	    outscaled ( glues [garray ][ gnumber ].gnwidth ) ;
	    outscaled ( glues [garray ][ gnumber ].gnstretch ) ;
	    outscaled ( glues [garray ][ gnumber ].gnshrink ) ;
	  } 
	while ( gnumber++ < for_end ) ;} 
      while ( garray++ < for_end ) ;} 
    } 
    {
      {register integer for_end; parray = 0 ;for_end = nkp - 1 ; if ( parray 
      <= for_end) do 
	{register integer for_end; pnumber = 0 ;for_end = npp [parray ]- 1 
	; if ( pnumber <= for_end) do 
	  {
	    outint ( penalties [parray ][ pnumber ].pnval ) ;
	  } 
	while ( pnumber++ < for_end ) ;} 
      while ( parray++ < for_end ) ;} 
    } 
  } 
} 
void 
computenewheaderofm ( void ) 
{
  {
    {
      nwi = 0 ;
      {register integer for_end; iarray = 0 ;for_end = nki ; if ( iarray <= 
      for_end) do 
	{
	  npi [iarray ]= npi [iarray ]+ 1 ;
	  nwi = nwi + npi [iarray ];
	} 
      while ( iarray++ < for_end ) ;} 
      nki = nki + 1 ;
    } 
    {
      nwf = 0 ;
      {register integer for_end; farray = 0 ;for_end = nkf ; if ( farray <= 
      for_end) do 
	{
	  npf [farray ]= npf [farray ]+ 1 ;
	  nwf = nwf + npf [farray ];
	} 
      while ( farray++ < for_end ) ;} 
      nkf = nkf + 1 ;
    } 
    {
      nwm = 0 ;
      {register integer for_end; marray = 0 ;for_end = nkm ; if ( marray <= 
      for_end) do 
	{
	  npm [marray ]= npm [marray ]+ 1 ;
	  nwm = nwm + npm [marray ];
	} 
      while ( marray++ < for_end ) ;} 
      nkm = nkm + 1 ;
    } 
    {
      nwr = 0 ;
      {register integer for_end; rarray = 0 ;for_end = nkr ; if ( rarray <= 
      for_end) do 
	{
	  npr [rarray ]= npr [rarray ]+ 1 ;
	  nwr = nwr + 3 * npr [rarray ];
	} 
      while ( rarray++ < for_end ) ;} 
      nkr = nkr + 1 ;
    } 
    {
      nwg = 0 ;
      {register integer for_end; garray = 0 ;for_end = nkg ; if ( garray <= 
      for_end) do 
	{
	  npg [garray ]= npg [garray ]+ 1 ;
	  nwg = nwg + 4 * npg [garray ];
	} 
      while ( garray++ < for_end ) ;} 
      nkg = nkg + 1 ;
    } 
    {
      nwp = 0 ;
      {register integer for_end; parray = 0 ;for_end = nkp ; if ( parray <= 
      for_end) do 
	{
	  npp [parray ]= npp [parray ]+ 1 ;
	  nwp = nwp + npp [parray ];
	} 
      while ( parray++ < for_end ) ;} 
      nkp = nkp + 1 ;
    } 
  } 
} 
void 
finishextendedfont ( void ) 
{
  {
    if ( maxpenaltycategory > 0 ) 
    {
      if ( nkp == 0 ) 
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "No PENALTY table" ) ;
	showerrorcontext () ;
      } 
      else if ( npp [0 ]< maxpenaltycategory ) 
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "Not enough PENALTY entries" ) ;
	showerrorcontext () ;
      } 
    } 
    if ( maxgluecategory > 0 ) 
    {
      if ( nkg == 0 ) 
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "No GLUE table" ) ;
	showerrorcontext () ;
      } 
      else if ( npg [0 ]< maxgluecategory ) 
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "Not enough GLUE entries" ) ;
	showerrorcontext () ;
      } 
    } 
    if ( maxivaluecategory > 0 ) 
    {
      if ( nki == 0 ) 
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "No IVALUE table" ) ;
	showerrorcontext () ;
      } 
      else if ( npi [0 ]< maxivaluecategory ) 
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "Not enough IVALUE entries" ) ;
	showerrorcontext () ;
      } 
      else {
	  
	{register integer for_end; c = 0 ;for_end = maxchar ; if ( c <= 
	for_end) do 
	  {
	    if ( ( charwd [c ]!= 0 ) ) 
	    {
	      {register integer for_end; j = 0 ;for_end = maxivaluecategory 
	      ; if ( j <= for_end) do 
		if ( chartable [c ][ 0 ]== j ) 
		{
		  if ( categoryremainders [j ]!= -1 ) 
		  {
		    if ( chartag [c ]!= 0 ) 
		    {
		      if ( charsonline > 0 ) 
		      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		      Fputs ( stderr ,  "Character already has a tag" ) ;
		      showerrorcontext () ;
		    } 
		    else {
			
		      charextendedtag [c ]= true ;
		      charremainder [c ]= categoryremainders [j ];
		    } 
		  } 
		} 
	      while ( j++ < for_end ) ;} 
	    } 
	  } 
	while ( c++ < for_end ) ;} 
      } 
    } 
  } 
} 
void 
outputsubfilesizes ( void ) 
{
  switch ( ofmlevel ) 
  {case -1 : 
    {
      putbyte ( ( lf ) / 256 , tfmfile ) ;
      putbyte ( ( lf ) % 256 , tfmfile ) ;
      putbyte ( ( lh ) / 256 , tfmfile ) ;
      putbyte ( ( lh ) % 256 , tfmfile ) ;
      putbyte ( ( bc ) / 256 , tfmfile ) ;
      putbyte ( ( bc ) % 256 , tfmfile ) ;
      putbyte ( ( ec ) / 256 , tfmfile ) ;
      putbyte ( ( ec ) % 256 , tfmfile ) ;
      putbyte ( ( memory [1 ]) / 256 , tfmfile ) ;
      putbyte ( ( memory [1 ]) % 256 , tfmfile ) ;
      putbyte ( ( memory [2 ]) / 256 , tfmfile ) ;
      putbyte ( ( memory [2 ]) % 256 , tfmfile ) ;
      putbyte ( ( memory [3 ]) / 256 , tfmfile ) ;
      putbyte ( ( memory [3 ]) % 256 , tfmfile ) ;
      putbyte ( ( memory [4 ]) / 256 , tfmfile ) ;
      putbyte ( ( memory [4 ]) % 256 , tfmfile ) ;
      putbyte ( ( nl + lkoffset ) / 256 , tfmfile ) ;
      putbyte ( ( nl + lkoffset ) % 256 , tfmfile ) ;
      putbyte ( ( nk ) / 256 , tfmfile ) ;
      putbyte ( ( nk ) % 256 , tfmfile ) ;
      putbyte ( ( ne ) / 256 , tfmfile ) ;
      putbyte ( ( ne ) % 256 , tfmfile ) ;
      putbyte ( ( np ) / 256 , tfmfile ) ;
      putbyte ( ( np ) % 256 , tfmfile ) ;
    } 
    break ;
  case 0 : 
    {
      putbyte ( ( 0 ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( 0 ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( 0 ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( 0 ) % 256 , tfmfile ) ;
      putbyte ( ( lf ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( lf ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( lf ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( lf ) % 256 , tfmfile ) ;
      putbyte ( ( lh ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( lh ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( lh ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( lh ) % 256 , tfmfile ) ;
      putbyte ( ( bc ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( bc ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( bc ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( bc ) % 256 , tfmfile ) ;
      putbyte ( ( ec ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( ec ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( ec ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( ec ) % 256 , tfmfile ) ;
      putbyte ( ( memory [1 ]) / 16777216L , tfmfile ) ;
      putbyte ( ( ( memory [1 ]) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( memory [1 ]) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( memory [1 ]) % 256 , tfmfile ) ;
      putbyte ( ( memory [2 ]) / 16777216L , tfmfile ) ;
      putbyte ( ( ( memory [2 ]) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( memory [2 ]) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( memory [2 ]) % 256 , tfmfile ) ;
      putbyte ( ( memory [3 ]) / 16777216L , tfmfile ) ;
      putbyte ( ( ( memory [3 ]) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( memory [3 ]) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( memory [3 ]) % 256 , tfmfile ) ;
      putbyte ( ( memory [4 ]) / 16777216L , tfmfile ) ;
      putbyte ( ( ( memory [4 ]) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( memory [4 ]) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( memory [4 ]) % 256 , tfmfile ) ;
      putbyte ( ( nl + lkoffset ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nl + lkoffset ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nl + lkoffset ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nl + lkoffset ) % 256 , tfmfile ) ;
      putbyte ( ( nk ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nk ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nk ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nk ) % 256 , tfmfile ) ;
      putbyte ( ( ne ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( ne ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( ne ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( ne ) % 256 , tfmfile ) ;
      putbyte ( ( np ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( np ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( np ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( np ) % 256 , tfmfile ) ;
      putbyte ( ( fontdir ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( fontdir ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( fontdir ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( fontdir ) % 256 , tfmfile ) ;
    } 
    break ;
  case 1 : 
    {
      putbyte ( ( 1 ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( 1 ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( 1 ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( 1 ) % 256 , tfmfile ) ;
      putbyte ( ( lf ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( lf ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( lf ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( lf ) % 256 , tfmfile ) ;
      putbyte ( ( lh ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( lh ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( lh ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( lh ) % 256 , tfmfile ) ;
      putbyte ( ( bc ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( bc ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( bc ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( bc ) % 256 , tfmfile ) ;
      putbyte ( ( ec ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( ec ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( ec ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( ec ) % 256 , tfmfile ) ;
      putbyte ( ( memory [1 ]) / 16777216L , tfmfile ) ;
      putbyte ( ( ( memory [1 ]) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( memory [1 ]) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( memory [1 ]) % 256 , tfmfile ) ;
      putbyte ( ( memory [2 ]) / 16777216L , tfmfile ) ;
      putbyte ( ( ( memory [2 ]) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( memory [2 ]) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( memory [2 ]) % 256 , tfmfile ) ;
      putbyte ( ( memory [3 ]) / 16777216L , tfmfile ) ;
      putbyte ( ( ( memory [3 ]) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( memory [3 ]) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( memory [3 ]) % 256 , tfmfile ) ;
      putbyte ( ( memory [4 ]) / 16777216L , tfmfile ) ;
      putbyte ( ( ( memory [4 ]) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( memory [4 ]) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( memory [4 ]) % 256 , tfmfile ) ;
      putbyte ( ( nl + lkoffset ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nl + lkoffset ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nl + lkoffset ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nl + lkoffset ) % 256 , tfmfile ) ;
      putbyte ( ( nk ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nk ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nk ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nk ) % 256 , tfmfile ) ;
      putbyte ( ( ne ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( ne ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( ne ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( ne ) % 256 , tfmfile ) ;
      putbyte ( ( np ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( np ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( np ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( np ) % 256 , tfmfile ) ;
      putbyte ( ( fontdir ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( fontdir ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( fontdir ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( fontdir ) % 256 , tfmfile ) ;
      putbyte ( ( nco ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nco ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nco ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nco ) % 256 , tfmfile ) ;
      putbyte ( ( ncw ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( ncw ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( ncw ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( ncw ) % 256 , tfmfile ) ;
      putbyte ( ( npc ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( npc ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( npc ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( npc ) % 256 , tfmfile ) ;
      putbyte ( ( nki ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nki ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nki ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nki ) % 256 , tfmfile ) ;
      putbyte ( ( nwi ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nwi ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nwi ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nwi ) % 256 , tfmfile ) ;
      putbyte ( ( nkf ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nkf ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nkf ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nkf ) % 256 , tfmfile ) ;
      putbyte ( ( nwf ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nwf ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nwf ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nwf ) % 256 , tfmfile ) ;
      putbyte ( ( nkm ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nkm ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nkm ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nkm ) % 256 , tfmfile ) ;
      putbyte ( ( nwm ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nwm ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nwm ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nwm ) % 256 , tfmfile ) ;
      putbyte ( ( nkr ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nkr ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nkr ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nkr ) % 256 , tfmfile ) ;
      putbyte ( ( nwr ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nwr ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nwr ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nwr ) % 256 , tfmfile ) ;
      putbyte ( ( nkg ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nkg ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nkg ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nkg ) % 256 , tfmfile ) ;
      putbyte ( ( nwg ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nwg ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nwg ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nwg ) % 256 , tfmfile ) ;
      putbyte ( ( nkp ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nkp ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nkp ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nkp ) % 256 , tfmfile ) ;
      putbyte ( ( nwp ) / 16777216L , tfmfile ) ;
      putbyte ( ( ( nwp ) % 16777216L ) / 65536L , tfmfile ) ;
      putbyte ( ( ( nwp ) % 65536L ) / 256 , tfmfile ) ;
      putbyte ( ( nwp ) % 256 , tfmfile ) ;
    } 
    break ;
  } 
} 
void 
computesubfilesizes ( void ) 
{
  lh = headerptr / 4 ;
  notfound = true ;
  bc = 0 ;
  if ( ( ofmlevel == -1 ) ) 
  ec = 255 ;
  else ec = maxchar ;
  while ( notfound ) if ( ( charwd [bc ]> 0 ) || ( bc == ec ) ) 
  notfound = false ;
  else bc = bc + 1 ;
  notfound = true ;
  while ( notfound ) if ( ( charwd [ec ]> 0 ) || ( ec == 0 ) ) 
  notfound = false ;
  else ec = ec - 1 ;
  if ( bc > ec ) 
  bc = 1 ;
  memory [1 ]= memory [1 ]+ 1 ;
  memory [2 ]= memory [2 ]+ 1 ;
  memory [3 ]= memory [3 ]+ 1 ;
  memory [4 ]= memory [4 ]+ 1 ;
  labelptr = 0 ;
  labeltable [0 ].rr = -1 ;
  {register integer for_end; c = bc ;for_end = ec ; if ( c <= for_end) do 
    if ( chartag [c ]== 1 ) 
    {
      sortptr = labelptr ;
      while ( labeltable [sortptr ].rr > charremainder [c ]) {
	  
	labeltable [sortptr + 1 ]= labeltable [sortptr ];
	sortptr = sortptr - 1 ;
      } 
      labeltable [sortptr + 1 ].cc = c ;
      labeltable [sortptr + 1 ].rr = charremainder [c ];
      labelptr = labelptr + 1 ;
    } 
  while ( c++ < for_end ) ;} 
  if ( bchar < xmaxchar ) 
  {
    extralocneeded = true ;
    lkoffset = 1 ;
  } 
  else {
      
    extralocneeded = false ;
    lkoffset = 0 ;
  } 
  {
    sortptr = labelptr ;
    if ( ofmlevel == -1 ) 
    {
      if ( labeltable [sortptr ].rr + lkoffset > 255 ) 
      {
	lkoffset = 0 ;
	extralocneeded = false ;
	do {
	    charremainder [labeltable [sortptr ].cc ]= lkoffset ;
	  while ( labeltable [sortptr - 1 ].rr == labeltable [sortptr ].rr 
	  ) {
	      
	    sortptr = sortptr - 1 ;
	    charremainder [labeltable [sortptr ].cc ]= lkoffset ;
	  } 
	  lkoffset = lkoffset + 1 ;
	  sortptr = sortptr - 1 ;
	} while ( ! ( lkoffset + labeltable [sortptr ].rr < 256 ) ) ;
      } 
    } 
    else {
	
      if ( labeltable [sortptr ].rr + lkoffset > 65535L ) 
      {
	lkoffset = 0 ;
	extralocneeded = false ;
	do {
	    charremainder [labeltable [sortptr ].cc ]= lkoffset ;
	  while ( labeltable [sortptr - 1 ].rr == labeltable [sortptr ].rr 
	  ) {
	      
	    sortptr = sortptr - 1 ;
	    charremainder [labeltable [sortptr ].cc ]= lkoffset ;
	  } 
	  lkoffset = lkoffset + 1 ;
	  sortptr = sortptr - 1 ;
	} while ( ! ( lkoffset + labeltable [sortptr ].rr < 65536L ) ) ;
      } 
    } 
    if ( lkoffset > 0 ) 
    while ( sortptr > 0 ) {
	
      charremainder [labeltable [sortptr ].cc ]= charremainder [
      labeltable [sortptr ].cc ]+ lkoffset ;
      sortptr = sortptr - 1 ;
    } 
  } 
  if ( charremainder [xmaxchar ]< xmaxlabel ) 
  {
    if ( ofmlevel == -1 ) 
    {
      ligkern [nl - 1 ].b2 = ( charremainder [xmaxchar ]+ lkoffset ) / 256 
      ;
      ligkern [nl - 1 ].b3 = ( charremainder [xmaxchar ]+ lkoffset ) % 256 
      ;
    } 
    else {
	
      ligkern [nl - 1 ].b2 = ( charremainder [xmaxchar ]+ lkoffset ) / 
      65536L ;
      ligkern [nl - 1 ].b3 = ( charremainder [xmaxchar ]+ lkoffset ) % 
      65536L ;
    } 
  } 
  switch ( ofmlevel ) 
  {case -1 : 
    {
      lf = 6 + lh + ( ec - bc + 1 ) + memory [1 ]+ memory [2 ]+ memory [3 
      ]+ memory [4 ]+ nl + lkoffset + nk + ne + np ;
    } 
    break ;
  case 0 : 
    {
      lf = 14 + lh + 2 * ( ec - bc + 1 ) + memory [1 ]+ memory [2 ]+ 
      memory [3 ]+ memory [4 ]+ 2 * ( nl + lkoffset ) + nk + 2 * ne + np ;
    } 
    break ;
  case 1 : 
    {
      if ( ofmlevel == 1 ) 
      {
	ncw = 0 ;
	npc = npc + 1 ;
	neededspace = ( 12 + npc * 2 ) / 4 ;
	extrabytes = ( neededspace * 4 ) - ( 10 + npc * 2 ) ;
	{register integer for_end; c = bc ;for_end = ec ; if ( c <= for_end) 
	do 
	  {
	    if ( charoriginal [c ]== c ) 
	    {
	      cprime = c + 1 ;
	      diff = false ;
	      while ( ( ! diff ) && ( cprime <= ec ) && ( cprime - c < 65536L 
	      ) ) {
		  
		if ( indexvar [charwd [c ]]!= indexvar [charwd [cprime ]
		]) 
		diff = true ;
		if ( indexvar [charht [c ]]!= indexvar [charht [cprime ]
		]) 
		diff = true ;
		if ( indexvar [chardp [c ]]!= indexvar [chardp [cprime ]
		]) 
		diff = true ;
		if ( indexvar [charic [c ]]!= indexvar [charic [cprime ]
		]) 
		diff = true ;
		if ( chartag [c ]!= chartag [cprime ]) 
		diff = true ;
		if ( charremainder [c ]!= charremainder [cprime ]) 
		diff = true ;
		{register integer for_end; tab = 0 ;for_end = npc - 1 ; if ( 
		tab <= for_end) do 
		  {
		    if ( chartable [c ][ tab ]!= chartable [cprime ][ tab ]
		    ) 
		    diff = true ;
		  } 
		while ( tab++ < for_end ) ;} 
		if ( ! diff ) 
		{
		  charoriginal [cprime ]= c ;
		  cprime = cprime + 1 ;
		} 
	      } 
	      if ( cprime > ( c + 1 ) ) 
	      {
		charrepeats [c ]= cprime - c - 1 ;
	      } 
	      ncw = ncw + neededspace ;
	    } 
	  } 
	while ( c++ < for_end ) ;} 
      } 
      lf = 29 + lh + ncw + memory [1 ]+ memory [2 ]+ memory [3 ]+ memory 
      [4 ]+ 2 * ( nl + lkoffset ) + nk + 2 * ne + np + nki + nwi + nkf + nwf 
      + nkm + nwm + nkr + nwr + nkg + nwg + nkp + nwp ;
      nco = 29 + lh + nki + nwi + nkf + nwf + nkm + nwm + nkr + nwr + nkg + 
      nwg + nkp + nwp ;
    } 
    break ;
  } 
} 
void 
outputcharacterinfo ( void ) 
{
  indexvar [0 ]= 0 ;
  {register integer for_end; c = bc ;for_end = ec ; if ( c <= for_end) do 
    switch ( ofmlevel ) 
    {case -1 : 
      {
	putbyte ( indexvar [charwd [c ]], tfmfile ) ;
	putbyte ( indexvar [charht [c ]]* 16 + indexvar [chardp [c ]], 
	tfmfile ) ;
	putbyte ( indexvar [charic [c ]]* 4 + chartag [c ], tfmfile ) ;
	putbyte ( charremainder [c ], tfmfile ) ;
      } 
      break ;
    case 0 : 
      {
	putbyte ( indexvar [charwd [c ]]/ 256 , tfmfile ) ;
	putbyte ( indexvar [charwd [c ]]% 256 , tfmfile ) ;
	putbyte ( indexvar [charht [c ]], tfmfile ) ;
	putbyte ( indexvar [chardp [c ]], tfmfile ) ;
	putbyte ( indexvar [charic [c ]], tfmfile ) ;
	putbyte ( chartag [c ], tfmfile ) ;
	putbyte ( charremainder [c ]/ 256 , tfmfile ) ;
	putbyte ( charremainder [c ]% 256 , tfmfile ) ;
      } 
      break ;
    case 1 : 
      {
	if ( c == charoriginal [c ]) 
	{
	  putbyte ( indexvar [charwd [c ]]/ 256 , tfmfile ) ;
	  putbyte ( indexvar [charwd [c ]]% 256 , tfmfile ) ;
	  putbyte ( indexvar [charht [c ]], tfmfile ) ;
	  putbyte ( indexvar [chardp [c ]], tfmfile ) ;
	  putbyte ( indexvar [charic [c ]], tfmfile ) ;
	  tab = chartag [c ];
	  if ( charextendedtag [c ]) 
	  {
	    tab = 5 ;
	  } 
	  putbyte ( tab , tfmfile ) ;
	  putbyte ( charremainder [c ]/ 256 , tfmfile ) ;
	  putbyte ( charremainder [c ]% 256 , tfmfile ) ;
	  putbyte ( ( charrepeats [c ]) / 256 , tfmfile ) ;
	  putbyte ( ( charrepeats [c ]) % 256 , tfmfile ) ;
	  {register integer for_end; tab = 0 ;for_end = npc - 1 ; if ( tab 
	  <= for_end) do 
	    {
	      putbyte ( chartable [c ][ tab ]/ 256 , tfmfile ) ;
	      putbyte ( chartable [c ][ tab ]% 256 , tfmfile ) ;
	    } 
	  while ( tab++ < for_end ) ;} 
	  {register integer for_end; tab = 1 ;for_end = extrabytes ; if ( 
	  tab <= for_end) do 
	    {
	      putbyte ( 0 , tfmfile ) ;
	    } 
	  while ( tab++ < for_end ) ;} 
	} 
      } 
      break ;
    } 
  while ( c++ < for_end ) ;} 
} 
void 
readfontrulelist ( void ) 
{
  {
    if ( tablesread ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "All parameter tables must appear before character info" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    rarray = getinteger () ;
    if ( rarray > rulearrays ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "This FONTRULE table index is too big for my present size" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else if ( rarray < 0 ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "This FONTRULE index is negative" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else {
	
      if ( rarray > nkr ) 
      nkr = rarray ;
      while ( level == 1 ) {
	  
	while ( curchar == 32 ) getnext () ;
	if ( curchar == 40 ) 
	{
	  getname () ;
	  if ( curcode == 0 ) 
	  skiptoendofitem () ;
	  else if ( curcode != 161 ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,                "This property name doesn't belong in a FONTRULE list" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    rnumber = getinteger () ;
	    if ( rnumber > ruleentries ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,                  "This RULE index is too big for my present table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else if ( rnumber < 0 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "This RULE index is negative" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      while ( npr [rarray ]< rnumber ) {
		  
		npr [rarray ]= npr [rarray ]+ 1 ;
		{
		  rules [rarray ][ npr [rarray ]].rnwidth = 0 ;
		  rules [rarray ][ npr [rarray ]].rndepth = 0 ;
		  rules [rarray ][ npr [rarray ]].rnheight = 0 ;
		} 
	      } 
	      {
		while ( level == 2 ) {
		    
		  while ( curchar == 32 ) getnext () ;
		  if ( curchar == 40 ) 
		  {
		    getname () ;
		    if ( curcode == 0 ) 
		    skiptoendofitem () ;
		    else if ( ( curcode < 162 ) || ( curcode > 164 ) ) 
		    {
		      {
			if ( charsonline > 0 ) 
			{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
			Fputs ( stderr ,                          "This property name doesn't belong in a RULE list" ) ;
			showerrorcontext () ;
		      } 
		      skiptoendofitem () ;
		    } 
		    else {
			
		      switch ( curcode ) 
		      {case 162 : 
			rules [rarray ][ rnumber ].rnwidth = getfix () ;
			break ;
		      case 163 : 
			rules [rarray ][ rnumber ].rnheight = getfix () ;
			break ;
		      case 164 : 
			rules [rarray ][ rnumber ].rndepth = getfix () ;
			break ;
		      } 
		      finishtheproperty () ;
		    } 
		  } 
		  else if ( curchar == 41 ) 
		  skiptoendofitem () ;
		  else junkerror () ;
		} 
		{
		  loc = loc - 1 ;
		  level = level + 1 ;
		  curchar = 41 ;
		} 
	      } 
	      finishtheproperty () ;
	    } 
	  } 
	} 
	else if ( curchar == 41 ) 
	skiptoendofitem () ;
	else junkerror () ;
      } 
      {
	loc = loc - 1 ;
	level = level + 1 ;
	curchar = 41 ;
      } 
    } 
  } 
} 
void 
readfontgluelist ( void ) 
{
  {
    if ( tablesread ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "All parameter tables must appear before character info" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    garray = getinteger () ;
    if ( garray > gluearrays ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "This FONTGLUE table index is too big for my present size" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else if ( garray < 0 ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "This FONTGLUE index is negative" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else {
	
      if ( garray > nkg ) 
      nkg = garray ;
      while ( level == 1 ) {
	  
	while ( curchar == 32 ) getnext () ;
	if ( curchar == 40 ) 
	{
	  getname () ;
	  if ( curcode == 0 ) 
	  skiptoendofitem () ;
	  else if ( curcode != 171 ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,                "This property name doesn't belong in a FONTGLUE list" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    gnumber = getinteger () ;
	    if ( gnumber > glueentries ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,                  "This GLUE index is too big for my present table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else if ( gnumber < 0 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "This GLUE index is negative" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      while ( npg [garray ]< gnumber ) {
		  
		npg [garray ]= npg [garray ]+ 1 ;
		{
		  glues [garray ][ npg [garray ]].gnwidth = 0 ;
		  glues [garray ][ npg [garray ]].gnstretch = 0 ;
		  glues [garray ][ npg [garray ]].gnshrink = 0 ;
		  glues [garray ][ npg [garray ]].gntype = 0 ;
		  glues [garray ][ npg [garray ]].gnargtype = 0 ;
		  glues [garray ][ npg [garray ]].gnstretchorder = 0 ;
		  glues [garray ][ npg [garray ]].gnshrinkorder = 0 ;
		  glues [garray ][ npg [garray ]].gnargument = 0 ;
		} 
	      } 
	      {
		while ( level == 2 ) {
		    
		  while ( curchar == 32 ) getnext () ;
		  if ( curchar == 40 ) 
		  {
		    getname () ;
		    if ( curcode == 0 ) 
		    skiptoendofitem () ;
		    else if ( ( curcode < 172 ) || ( curcode > 179 ) ) 
		    {
		      {
			if ( charsonline > 0 ) 
			{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
			Fputs ( stderr ,                          "This property name doesn't belong in a GLUE list" ) ;
			showerrorcontext () ;
		      } 
		      skiptoendofitem () ;
		    } 
		    else {
			
		      switch ( curcode ) 
		      {case 175 : 
			glues [garray ][ gnumber ].gnwidth = getfix () ;
			break ;
		      case 176 : 
			glues [garray ][ gnumber ].gnstretch = getfix () ;
			break ;
		      case 177 : 
			glues [garray ][ gnumber ].gnshrink = getfix () ;
			break ;
		      case 172 : 
			{
			  gbyte = getinteger () ;
			  if ( ( gbyte < 0 ) || ( gbyte > 3 ) ) 
			  {
			    gbyte = 0 ;
			  } 
			  glues [garray ][ gnumber ].gntype = gbyte ;
			} 
			break ;
		      case 173 : 
			{
			  gbyte = getinteger () ;
			  if ( ( gbyte < 0 ) || ( gbyte > 4 ) ) 
			  {
			    gbyte = 0 ;
			  } 
			  glues [garray ][ gnumber ].gnstretchorder = gbyte 
			  ;
			} 
			break ;
		      case 174 : 
			{
			  gbyte = getinteger () ;
			  if ( ( gbyte < 0 ) || ( gbyte > 4 ) ) 
			  {
			    gbyte = 0 ;
			  } 
			  glues [garray ][ gnumber ].gnshrinkorder = gbyte ;
			} 
			break ;
		      case 178 : 
			{
			  glues [garray ][ gnumber ].gnargument = getinteger 
			  () ;
			  glues [garray ][ gnumber ].gnargtype = 2 ;
			} 
			break ;
		      case 179 : 
			{
			  glues [garray ][ gnumber ].gnargument = getinteger 
			  () ;
			  glues [garray ][ gnumber ].gnargtype = 1 ;
			} 
			break ;
		      } 
		      finishtheproperty () ;
		    } 
		  } 
		  else if ( curchar == 41 ) 
		  skiptoendofitem () ;
		  else junkerror () ;
		} 
		{
		  loc = loc - 1 ;
		  level = level + 1 ;
		  curchar = 41 ;
		} 
	      } 
	      finishtheproperty () ;
	    } 
	  } 
	} 
	else if ( curchar == 41 ) 
	skiptoendofitem () ;
	else junkerror () ;
      } 
      {
	loc = loc - 1 ;
	level = level + 1 ;
	curchar = 41 ;
      } 
    } 
  } 
} 
void 
readfontpenaltylist ( void ) 
{
  {
    if ( tablesread ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "All parameter tables must appear before character info" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    parray = getinteger () ;
    if ( parray > penaltyarrays ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "This FONTPENALTY table index is too big for my present size" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else if ( parray < 0 ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "This FONTPENALTY index is negative" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else {
	
      if ( parray > nkp ) 
      nkp = parray ;
      while ( level == 1 ) {
	  
	while ( curchar == 32 ) getnext () ;
	if ( curchar == 40 ) 
	{
	  getname () ;
	  if ( curcode == 0 ) 
	  skiptoendofitem () ;
	  else if ( curcode != 191 ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,                "This property name doesn't belong in a FONTPENALTY list" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    pnumber = getinteger () ;
	    if ( pnumber > penaltyentries ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,                  "This PENALTY index is too big for my present table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else if ( pnumber < 0 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "This PENALTY index is negative" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      while ( npp [parray ]< pnumber ) {
		  
		npp [parray ]= npp [parray ]+ 1 ;
		{
		  penalties [parray ][ npp [parray ]].pnval = 0 ;
		} 
	      } 
	      {
		while ( level == 2 ) {
		    
		  while ( curchar == 32 ) getnext () ;
		  if ( curchar == 40 ) 
		  {
		    getname () ;
		    if ( curcode == 0 ) 
		    skiptoendofitem () ;
		    else if ( curcode != 192 ) 
		    {
		      {
			if ( charsonline > 0 ) 
			{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
			Fputs ( stderr ,                          "This property name doesn't belong in a PENALTY list"                         ) ;
			showerrorcontext () ;
		      } 
		      skiptoendofitem () ;
		    } 
		    else {
			
		      penalties [parray ][ pnumber ].pnval = getinteger () ;
		      finishtheproperty () ;
		    } 
		  } 
		  else if ( curchar == 41 ) 
		  skiptoendofitem () ;
		  else junkerror () ;
		} 
		{
		  loc = loc - 1 ;
		  level = level + 1 ;
		  curchar = 41 ;
		} 
	      } 
	      finishtheproperty () ;
	    } 
	  } 
	} 
	else if ( curchar == 41 ) 
	skiptoendofitem () ;
	else junkerror () ;
      } 
      {
	loc = loc - 1 ;
	level = level + 1 ;
	curchar = 41 ;
      } 
    } 
  } 
} 
void 
readfontmvaluelist ( void ) 
{
  {
    if ( tablesread ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "All parameter tables must appear before character info" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    marray = getinteger () ;
    if ( marray > mvaluearrays ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "This FONTMVALUE table index is too big for my present size" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else if ( marray < 0 ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "This FONTMVALUE index is negative" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else {
	
      if ( marray > nkm ) 
      nkm = marray ;
      while ( level == 1 ) {
	  
	while ( curchar == 32 ) getnext () ;
	if ( curchar == 40 ) 
	{
	  getname () ;
	  if ( curcode == 0 ) 
	  skiptoendofitem () ;
	  else if ( curcode != 193 ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,                "This property name doesn't belong in an FONTMVALUE list" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    mnumber = getinteger () ;
	    if ( mnumber > mvalueentries ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,                  "This MVALUE index is too big for my present table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else if ( mnumber < 0 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "This MVALUE index is negative" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      while ( npm [marray ]< mnumber ) {
		  
		npm [marray ]= npm [marray ]+ 1 ;
		{
		  mvalues [marray ][ npm [marray ]].fnval = 0 ;
		} 
	      } 
	      {
		while ( level == 2 ) {
		    
		  while ( curchar == 32 ) getnext () ;
		  if ( curchar == 40 ) 
		  {
		    getname () ;
		    if ( curcode == 0 ) 
		    skiptoendofitem () ;
		    else if ( curcode != 194 ) 
		    {
		      {
			if ( charsonline > 0 ) 
			{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
			Fputs ( stderr ,                          "This property name doesn't belong in a MVALUE list" ) 
			;
			showerrorcontext () ;
		      } 
		      skiptoendofitem () ;
		    } 
		    else {
			
		      mvalues [marray ][ mnumber ].fnval = getfix () ;
		      finishtheproperty () ;
		    } 
		  } 
		  else if ( curchar == 41 ) 
		  skiptoendofitem () ;
		  else junkerror () ;
		} 
		{
		  loc = loc - 1 ;
		  level = level + 1 ;
		  curchar = 41 ;
		} 
	      } 
	      finishtheproperty () ;
	    } 
	  } 
	} 
	else if ( curchar == 41 ) 
	skiptoendofitem () ;
	else junkerror () ;
      } 
      {
	loc = loc - 1 ;
	level = level + 1 ;
	curchar = 41 ;
      } 
    } 
  } 
} 
void 
readfontfvaluelist ( void ) 
{
  {
    if ( tablesread ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "All parameter tables must appear before character info" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    farray = getinteger () ;
    if ( farray > fvaluearrays ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "This FONTFVALUE table index is too big for my present size" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else if ( farray < 0 ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "This FONTFVALUE index is negative" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else {
	
      if ( farray > nkf ) 
      nkf = farray ;
      while ( level == 1 ) {
	  
	while ( curchar == 32 ) getnext () ;
	if ( curchar == 40 ) 
	{
	  getname () ;
	  if ( curcode == 0 ) 
	  skiptoendofitem () ;
	  else if ( curcode != 195 ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,                "This property name doesn't belong in an FONTFVALUE list" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    fnumber = getinteger () ;
	    if ( fnumber > fvalueentries ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,                  "This FVALUE index is too big for my present table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else if ( fnumber < 0 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "This FVALUE index is negative" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      while ( npf [farray ]< fnumber ) {
		  
		npf [farray ]= npf [farray ]+ 1 ;
		{
		  fvalues [farray ][ npf [farray ]].fnval = 0 ;
		} 
	      } 
	      {
		while ( level == 2 ) {
		    
		  while ( curchar == 32 ) getnext () ;
		  if ( curchar == 40 ) 
		  {
		    getname () ;
		    if ( curcode == 0 ) 
		    skiptoendofitem () ;
		    else if ( curcode != 196 ) 
		    {
		      {
			if ( charsonline > 0 ) 
			{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
			Fputs ( stderr ,                          "This property name doesn't belong in a FVALUE list" ) 
			;
			showerrorcontext () ;
		      } 
		      skiptoendofitem () ;
		    } 
		    else {
			
		      fvalues [farray ][ fnumber ].fnval = getfix () ;
		      finishtheproperty () ;
		    } 
		  } 
		  else if ( curchar == 41 ) 
		  skiptoendofitem () ;
		  else junkerror () ;
		} 
		{
		  loc = loc - 1 ;
		  level = level + 1 ;
		  curchar = 41 ;
		} 
	      } 
	      finishtheproperty () ;
	    } 
	  } 
	} 
	else if ( curchar == 41 ) 
	skiptoendofitem () ;
	else junkerror () ;
      } 
      {
	loc = loc - 1 ;
	level = level + 1 ;
	curchar = 41 ;
      } 
    } 
  } 
} 
void 
readfontivaluelist ( void ) 
{
  {
    if ( tablesread ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "All parameter tables must appear before character info" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    iarray = getinteger () ;
    if ( iarray > ivaluearrays ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "This FONTIVALUE table index is too big for my present size" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else if ( iarray < 0 ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "This FONTIVALUE index is negative" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else {
	
      if ( iarray > nki ) 
      nki = iarray ;
      while ( level == 1 ) {
	  
	while ( curchar == 32 ) getnext () ;
	if ( curchar == 40 ) 
	{
	  getname () ;
	  if ( curcode == 0 ) 
	  skiptoendofitem () ;
	  else if ( curcode != 197 ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,                "This property name doesn't belong in an FONTIVALUE list" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    inumber = getinteger () ;
	    if ( inumber > ivalueentries ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,                  "This IVALUE index is too big for my present table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else if ( inumber < 0 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "This IVALUE index is negative" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      while ( npi [iarray ]< inumber ) {
		  
		npi [iarray ]= npi [iarray ]+ 1 ;
		{
		  ivalues [iarray ][ npi [iarray ]].inval = 0 ;
		} 
	      } 
	      {
		while ( level == 2 ) {
		    
		  while ( curchar == 32 ) getnext () ;
		  if ( curchar == 40 ) 
		  {
		    getname () ;
		    if ( curcode == 0 ) 
		    skiptoendofitem () ;
		    else if ( curcode != 198 ) 
		    {
		      {
			if ( charsonline > 0 ) 
			{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
			Fputs ( stderr ,                          "This property name doesn't belong in a IVALUE list" ) 
			;
			showerrorcontext () ;
		      } 
		      skiptoendofitem () ;
		    } 
		    else {
			
		      ivalues [iarray ][ inumber ].inval = getinteger () ;
		      finishtheproperty () ;
		    } 
		  } 
		  else if ( curchar == 41 ) 
		  skiptoendofitem () ;
		  else junkerror () ;
		} 
		{
		  loc = loc - 1 ;
		  level = level + 1 ;
		  curchar = 41 ;
		} 
	      } 
	      finishtheproperty () ;
	    } 
	  } 
	} 
	else if ( curchar == 41 ) 
	skiptoendofitem () ;
	else junkerror () ;
      } 
      {
	loc = loc - 1 ;
	level = level + 1 ;
	curchar = 41 ;
      } 
    } 
  } 
} 
void 
readrepeatedcharacterinfo ( void ) 
{
  {
    if ( ! tablesread ) 
    {
      {
	{
	  nwi = 0 ;
	  {register integer for_end; iarray = 0 ;for_end = nki ; if ( iarray 
	  <= for_end) do 
	    {
	      npi [iarray ]= npi [iarray ]+ 1 ;
	      nwi = nwi + npi [iarray ];
	    } 
	  while ( iarray++ < for_end ) ;} 
	  nki = nki + 1 ;
	} 
	{
	  nwf = 0 ;
	  {register integer for_end; farray = 0 ;for_end = nkf ; if ( farray 
	  <= for_end) do 
	    {
	      npf [farray ]= npf [farray ]+ 1 ;
	      nwf = nwf + npf [farray ];
	    } 
	  while ( farray++ < for_end ) ;} 
	  nkf = nkf + 1 ;
	} 
	{
	  nwm = 0 ;
	  {register integer for_end; marray = 0 ;for_end = nkm ; if ( marray 
	  <= for_end) do 
	    {
	      npm [marray ]= npm [marray ]+ 1 ;
	      nwm = nwm + npm [marray ];
	    } 
	  while ( marray++ < for_end ) ;} 
	  nkm = nkm + 1 ;
	} 
	{
	  nwr = 0 ;
	  {register integer for_end; rarray = 0 ;for_end = nkr ; if ( rarray 
	  <= for_end) do 
	    {
	      npr [rarray ]= npr [rarray ]+ 1 ;
	      nwr = nwr + 3 * npr [rarray ];
	    } 
	  while ( rarray++ < for_end ) ;} 
	  nkr = nkr + 1 ;
	} 
	{
	  nwg = 0 ;
	  {register integer for_end; garray = 0 ;for_end = nkg ; if ( garray 
	  <= for_end) do 
	    {
	      npg [garray ]= npg [garray ]+ 1 ;
	      nwg = nwg + 4 * npg [garray ];
	    } 
	  while ( garray++ < for_end ) ;} 
	  nkg = nkg + 1 ;
	} 
	{
	  nwp = 0 ;
	  {register integer for_end; parray = 0 ;for_end = nkp ; if ( parray 
	  <= for_end) do 
	    {
	      npp [parray ]= npp [parray ]+ 1 ;
	      nwp = nwp + npp [parray ];
	    } 
	  while ( parray++ < for_end ) ;} 
	  nkp = nkp + 1 ;
	} 
      } 
      tablesread = true ;
    } 
    c = getcharcode () ;
    if ( verbose ) 
    {
      if ( charsonline >= 8 ) 
      {
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 1 ;
      } 
      else {
	  
	if ( charsonline > 0 ) 
	putc ( ' ' ,  stderr );
	charsonline = charsonline + 1 ;
      } 
      printnumber ( c , 16 ) ;
    } 
    crange = getbyte () ;
    if ( ( crange < 0 ) ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "Character ranges must be positive" ) ;
	showerrorcontext () ;
      } 
      crange = 0 ;
    } 
    if ( ( ( c + crange ) > maxchar ) ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "Character range too large" ) ;
	showerrorcontext () ;
      } 
      crange = 0 ;
    } 
    if ( verbose ) 
    {
      putc ( '-' ,  stderr );
      printnumber ( c + crange , 16 ) ;
      charsonline = charsonline + 1 ;
    } 
    while ( level == 1 ) {
	
      while ( curchar == 32 ) getnext () ;
      if ( curchar == 40 ) 
      readcharacterproperty () ;
      else if ( curchar == 41 ) 
      skiptoendofitem () ;
      else junkerror () ;
    } 
    if ( charwd [c ]== 0 ) 
    charwd [c ]= sortin ( 1 , 0 ) ;
    {
      loc = loc - 1 ;
      level = level + 1 ;
      curchar = 41 ;
    } 
    cprime = c ;
    {register integer for_end; c = ( cprime + 1 ) ;for_end = ( cprime + 
    crange ) ; if ( c <= for_end) do 
      {
	charwd [c ]= charwd [cprime ];
	charht [c ]= charht [cprime ];
	chardp [c ]= chardp [cprime ];
	charic [c ]= charic [cprime ];
	chartag [c ]= chartag [cprime ];
	charremainder [c ]= charremainder [cprime ];
	{register integer for_end; tab = 0 ;for_end = ( nki + nkf + nkm + 
	nkr + nkg + nkp - 1 ) ; if ( tab <= for_end) do 
	  {
	    chartable [c ][ tab ]= chartable [cprime ][ tab ];
	  } 
	while ( tab++ < for_end ) ;} 
      } 
    while ( c++ < for_end ) ;} 
  } 
} 
void 
readligkerncommand ( void ) 
{
  {
    getname () ;
    if ( curcode == 0 ) 
    skiptoendofitem () ;
    else if ( ( curcode < 130 ) || ( curcode > 154 ) ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "This property name doesn't belong in a LIGTABLE list" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else {
	
      switch ( curcode ) 
      {case 130 : 
	{
	  while ( curchar == 32 ) getnext () ;
	  if ( curchar == 66 ) 
	  {
	    charremainder [xmaxchar ]= nl ;
	    do {
		getnext () ;
	    } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	  } 
	  else {
	      
	    {
	      if ( ( curchar > 41 ) || ( curchar < 40 ) ) 
	      loc = loc - 1 ;
	    } 
	    c = getcharcode () ;
	    checktag ( c ) ;
	    chartag [c ]= 1 ;
	    charremainder [c ]= nl ;
	  } 
	  if ( minnl <= nl ) 
	  minnl = nl + 1 ;
	  lkstepended = false ;
	} 
	break ;
      case 131 : 
	if ( ! lkstepended ) 
	{
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  Fputs ( stderr ,  "STOP must follow LIG or KRN" ) ;
	  showerrorcontext () ;
	} 
	else {
	    
	  ligkern [nl - 1 ].b0 = ligkern [nl - 1 ].b0 / 256 * 256 + 128 ;
	  lkstepended = false ;
	} 
	break ;
      case 132 : 
	if ( ! lkstepended ) 
	{
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  Fputs ( stderr ,  "SKIP must follow LIG or KRN" ) ;
	  showerrorcontext () ;
	} 
	else {
	    
	  c = getbyte () ;
	  if ( c >= 128 ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "Maximum SKIP amount is 127" ) ;
	    showerrorcontext () ;
	  } 
	  else if ( nl + c >= maxligsteps ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "Sorry, LIGTABLE too long for me to handle" ) ;
	    showerrorcontext () ;
	  } 
	  else {
	      
	    ligkern [nl - 1 ].b0 = c ;
	    if ( minnl <= nl + c ) 
	    minnl = nl + c + 1 ;
	  } 
	  lkstepended = false ;
	} 
	break ;
      case 133 : 
	{
	  ligkern [nl ].b0 = 0 ;
	  ligkern [nl ].b1 = getbyte () ;
	  kern [nk ]= getfix () ;
	  krnptr = 0 ;
	  while ( kern [krnptr ]!= kern [nk ]) krnptr = krnptr + 1 ;
	  if ( krnptr == nk ) 
	  {
	    if ( nk < maxkerns ) 
	    nk = nk + 1 ;
	    else {
		
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,                  "Sorry, too many different kerns for me to handle" ) ;
		showerrorcontext () ;
	      } 
	      krnptr = krnptr - 1 ;
	    } 
	  } 
	  if ( ofmlevel == -1 ) 
	  {
	    ligkern [nl ].b2 = 128 + ( krnptr / 256 ) ;
	    ligkern [nl ].b3 = krnptr % 256 ;
	  } 
	  else {
	      
	    ligkern [nl ].b2 = 128 + ( krnptr / 65536L ) ;
	    ligkern [nl ].b3 = krnptr % 65536L ;
	  } 
	  if ( nl >= maxligsteps - 1 ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "Sorry, LIGTABLE too long for me to handle" ) ;
	    showerrorcontext () ;
	  } 
	  else nl = nl + 1 ;
	  lkstepended = true ;
	} 
	break ;
      case 134 : 
      case 135 : 
      case 136 : 
      case 137 : 
      case 139 : 
      case 140 : 
      case 141 : 
      case 145 : 
	{
	  ligkern [nl ].b0 = 0 ;
	  ligkern [nl ].b2 = curcode - 134 ;
	  ligkern [nl ].b1 = getbyte () ;
	  ligkern [nl ].b3 = getbyte () ;
	  if ( nl >= maxligsteps - 1 ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "Sorry, LIGTABLE too long for me to handle" ) ;
	    showerrorcontext () ;
	  } 
	  else nl = nl + 1 ;
	  lkstepended = true ;
	} 
	break ;
      case 150 : 
	{
	  c = getcharcode () ;
	  categoryremainders [c ]= nl ;
	  if ( maxivaluecategory < c ) 
	  maxivaluecategory = c ;
	  if ( minnl <= nl ) 
	  minnl = nl + 1 ;
	  lkstepended = false ;
	} 
	break ;
      case 151 : 
	{
	  ligkern [nl ].b0 = 256 ;
	  ligkern [nl ].b1 = getbyte () ;
	  ligkern [nl ].b2 = 17 ;
	  penaltycategory = getbyte () ;
	  if ( maxpenaltycategory < penaltycategory ) 
	  maxpenaltycategory = penaltycategory ;
	  ligkern [nl ].b3 = penaltycategory ;
	  if ( nl >= maxligsteps - 1 ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "Sorry, LIGTABLE too long for me to handle" ) ;
	    showerrorcontext () ;
	  } 
	  else nl = nl + 1 ;
	  lkstepended = true ;
	} 
	break ;
      case 152 : 
	{
	  ligkern [nl ].b0 = 256 ;
	  ligkern [nl ].b1 = getbyte () ;
	  ligkern [nl ].b2 = 18 ;
	  gluecategory = getbyte () ;
	  if ( maxgluecategory < gluecategory ) 
	  maxgluecategory = gluecategory ;
	  ligkern [nl ].b3 = gluecategory ;
	  if ( nl >= maxligsteps - 1 ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "Sorry, LIGTABLE too long for me to handle" ) ;
	    showerrorcontext () ;
	  } 
	  else nl = nl + 1 ;
	  lkstepended = true ;
	} 
	break ;
      case 153 : 
	{
	  ligkern [nl ].b0 = 256 ;
	  ligkern [nl ].b1 = getbyte () ;
	  ligkern [nl ].b2 = 19 ;
	  penaltycategory = getbyte () ;
	  if ( maxpenaltycategory < penaltycategory ) 
	  maxpenaltycategory = penaltycategory ;
	  gluecategory = getbyte () ;
	  if ( maxgluecategory < gluecategory ) 
	  maxgluecategory = gluecategory ;
	  ligkern [nl ].b3 = penaltycategory * 256 + gluecategory ;
	  if ( nl >= maxligsteps - 1 ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "Sorry, LIGTABLE too long for me to handle" ) ;
	    showerrorcontext () ;
	  } 
	  else nl = nl + 1 ;
	  lkstepended = true ;
	} 
	break ;
      case 154 : 
	{
	  ligkern [nl ].b0 = 256 ;
	  ligkern [nl ].b1 = getbyte () ;
	  ligkern [nl ].b2 = 20 ;
	  kern [nk ]= getfix () ;
	  krnptr = 0 ;
	  while ( kern [krnptr ]!= kern [nk ]) krnptr = krnptr + 1 ;
	  if ( krnptr == nk ) 
	  {
	    if ( nk < maxkerns ) 
	    nk = nk + 1 ;
	    else {
		
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,                  "Sorry, too many different kerns for me to handle" ) ;
		showerrorcontext () ;
	      } 
	      krnptr = krnptr - 1 ;
	    } 
	  } 
	  if ( krnptr > 65535L ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,              "Sorry, too many different kerns for me to handle" ) ;
	    showerrorcontext () ;
	  } 
	  ligkern [nl ].b3 = krnptr ;
	  if ( nl >= maxligsteps - 1 ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "Sorry, LIGTABLE too long for me to handle" ) ;
	    showerrorcontext () ;
	  } 
	  else nl = nl + 1 ;
	  lkstepended = true ;
	} 
	break ;
      } 
      finishtheproperty () ;
    } 
  } 
} 
void 
readcharacterproperty ( void ) 
{
  {
    getname () ;
    if ( curcode == 0 ) 
    skiptoendofitem () ;
    else if ( ( curcode < 71 ) || ( curcode > 117 ) ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,          "This property name doesn't belong in a CHARACTER list" ) ;
	showerrorcontext () ;
      } 
      skiptoendofitem () ;
    } 
    else {
	
      switch ( curcode ) 
      {case 71 : 
	charwd [c ]= sortin ( 1 , getfix () ) ;
	break ;
      case 72 : 
	charht [c ]= sortin ( 2 , getfix () ) ;
	break ;
      case 73 : 
	chardp [c ]= sortin ( 3 , getfix () ) ;
	break ;
      case 74 : 
	charic [c ]= sortin ( 4 , getfix () ) ;
	break ;
      case 75 : 
      case 76 : 
      case 77 : 
      case 78 : 
      case 79 : 
      case 80 : 
      case 81 : 
      case 82 : 
      case 83 : 
      case 84 : 
      case 85 : 
      case 86 : 
      case 87 : 
      case 88 : 
      case 89 : 
      case 90 : 
      case 91 : 
      case 92 : 
      case 93 : 
	tempvalue = getfix () ;
	break ;
      case 100 : 
	{
	  checktag ( c ) ;
	  chartag [c ]= 2 ;
	  charremainder [c ]= getbyte () ;
	} 
	break ;
      case 117 : 
	{
	  if ( ne == xmaxchar ) 
	  {
	    if ( charsonline > 0 ) 
	    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	    Fputs ( stderr ,  "Sorry, too many VARCHAR specs" ) ;
	    showerrorcontext () ;
	  } 
	  else {
	      
	    checktag ( c ) ;
	    chartag [c ]= 3 ;
	    charremainder [c ]= ne ;
	    exten [ne ]= zerobytes ;
	    while ( level == 2 ) {
		
	      while ( curchar == 32 ) getnext () ;
	      if ( curchar == 40 ) 
	      {
		getname () ;
		if ( curcode == 0 ) 
		skiptoendofitem () ;
		else if ( ( curcode < 118 ) || ( curcode > 121 ) ) 
		{
		  {
		    if ( charsonline > 0 ) 
		    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		    Fputs ( stderr ,                      "This property name doesn't belong in a VARCHAR list" ) ;
		    showerrorcontext () ;
		  } 
		  skiptoendofitem () ;
		} 
		else {
		    
		  switch ( curcode - ( 118 ) ) 
		  {case 0 : 
		    exten [ne ].b0 = getbyte () ;
		    break ;
		  case 1 : 
		    exten [ne ].b1 = getbyte () ;
		    break ;
		  case 2 : 
		    exten [ne ].b2 = getbyte () ;
		    break ;
		  case 3 : 
		    exten [ne ].b3 = getbyte () ;
		    break ;
		  } 
		  finishtheproperty () ;
		} 
	      } 
	      else if ( curchar == 41 ) 
	      skiptoendofitem () ;
	      else junkerror () ;
	    } 
	    ne = ne + 1 ;
	    {
	      loc = loc - 1 ;
	      level = level + 1 ;
	      curchar = 41 ;
	    } 
	  } 
	} 
	break ;
      case 111 : 
	{
	  chtable = getinteger () ;
	  if ( ( chtable < 0 ) || ( chtable >= nki ) ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,  "Character property index out of range" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    chtable = chtable + 0 ;
	    if ( chtable > 8 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "Character property exceeds table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      if ( chtable > npc ) 
	      npc = chtable ;
	      chartable [c ][ chtable ]= getinteger () ;
	    } 
	  } 
	} 
	break ;
      case 112 : 
	{
	  chtable = getinteger () ;
	  if ( ( chtable < 0 ) || ( chtable >= nkf ) ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,  "Character property index out of range" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    chtable = chtable + nki ;
	    if ( chtable > 8 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "Character property exceeds table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      if ( chtable > npc ) 
	      npc = chtable ;
	      chartable [c ][ chtable ]= getinteger () ;
	    } 
	  } 
	} 
	break ;
      case 113 : 
	{
	  chtable = getinteger () ;
	  if ( ( chtable < 0 ) || ( chtable >= nkm ) ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,  "Character property index out of range" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    chtable = chtable + nki + nkf ;
	    if ( chtable > 8 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "Character property exceeds table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      if ( chtable > npc ) 
	      npc = chtable ;
	      chartable [c ][ chtable ]= getinteger () ;
	    } 
	  } 
	} 
	break ;
      case 114 : 
	{
	  chtable = getinteger () ;
	  if ( ( chtable < 0 ) || ( chtable >= nkr ) ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,  "Character property index out of range" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    chtable = chtable + nki + nkf + nkm ;
	    if ( chtable > 8 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "Character property exceeds table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      if ( chtable > npc ) 
	      npc = chtable ;
	      chartable [c ][ chtable ]= getinteger () ;
	    } 
	  } 
	} 
	break ;
      case 115 : 
	{
	  chtable = getinteger () ;
	  if ( ( chtable < 0 ) || ( chtable >= nkg ) ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,  "Character property index out of range" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    chtable = chtable + nki + nkf + nkm + nkr ;
	    if ( chtable > 8 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "Character property exceeds table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      if ( chtable > npc ) 
	      npc = chtable ;
	      chartable [c ][ chtable ]= getinteger () ;
	    } 
	  } 
	} 
	break ;
      case 116 : 
	{
	  chtable = getinteger () ;
	  if ( ( chtable < 0 ) || ( chtable >= nkp ) ) 
	  {
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,  "Character property index out of range" ) ;
	      showerrorcontext () ;
	    } 
	    skiptoendofitem () ;
	  } 
	  else {
	      
	    chtable = chtable + nki + nkf + nkm + nkr + nkg ;
	    if ( chtable > 8 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "Character property exceeds table size" ) ;
		showerrorcontext () ;
	      } 
	      skiptoendofitem () ;
	    } 
	    else {
		
	      if ( chtable > npc ) 
	      npc = chtable ;
	      chartable [c ][ chtable ]= getinteger () ;
	    } 
	  } 
	} 
	break ;
      } 
      finishtheproperty () ;
    } 
  } 
} 
void 
readcharinfo ( void ) 
{
  {
    if ( ! tablesread ) 
    {
      computenewheaderofm () ;
      tablesread = true ;
    } 
    c = getcharcode () ;
    if ( verbose ) 
    {
      if ( charsonline >= 8 ) 
      {
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	charsonline = 1 ;
      } 
      else {
	  
	if ( charsonline > 0 ) 
	putc ( ' ' ,  stderr );
	charsonline = charsonline + 1 ;
      } 
      printnumber ( c , 16 ) ;
    } 
    while ( level == 1 ) {
	
      while ( curchar == 32 ) getnext () ;
      if ( curchar == 40 ) 
      readcharacterproperty () ;
      else if ( curchar == 41 ) 
      skiptoendofitem () ;
      else junkerror () ;
    } 
    if ( charwd [c ]== 0 ) 
    charwd [c ]= sortin ( 1 , 0 ) ;
    {
      loc = loc - 1 ;
      level = level + 1 ;
      curchar = 41 ;
    } 
  } 
} 
void 
readinput ( void ) 
{
  integer c  ;
  curchar = 32 ;
  do {
      while ( curchar == 32 ) getnext () ;
    if ( curchar == 40 ) 
    {
      getname () ;
      if ( curcode == 0 ) 
      skiptoendofitem () ;
      else if ( curcode > 24 ) 
      {
	{
	  if ( charsonline > 0 ) 
	  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	  Fputs ( stderr ,            "This property name doesn't belong on the outer level" ) ;
	  showerrorcontext () ;
	} 
	skiptoendofitem () ;
      } 
      else {
	  
	switch ( curcode ) 
	{case 1 : 
	  {
	    checksumspecified = true ;
	    readfourbytes ( 0 ) ;
	  } 
	  break ;
	case 2 : 
	  {
	    nextd = getfix () ;
	    if ( nextd < 1048576L ) 
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,  "The design size must be at least 1" ) ;
	      showerrorcontext () ;
	    } 
	    else designsize = nextd ;
	  } 
	  break ;
	case 3 : 
	  {
	    nextd = getfix () ;
	    if ( nextd <= 0 ) 
	    {
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,                "The number of units per design size must be positive" ) ;
	      showerrorcontext () ;
	    } 
	    else designunits = nextd ;
	  } 
	  break ;
	case 4 : 
	  readBCPL ( 8 , 40 ) ;
	  break ;
	case 5 : 
	  readBCPL ( 48 , 20 ) ;
	  break ;
	case 6 : 
	  {
	    c = getbyte () ;
	    if ( c > 255 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "FACE clipped to 255" ) ;
		showerrorcontext () ;
	      } 
	      c = 255 ;
	    } 
	    headerbytes [71 ]= c ;
	  } 
	  break ;
	case 7 : 
	  {
	    while ( curchar == 32 ) getnext () ;
	    if ( curchar == 84 ) 
	    sevenbitsafeflag = true ;
	    else if ( curchar == 70 ) 
	    sevenbitsafeflag = false ;
	    else {
		
	      if ( charsonline > 0 ) 
	      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	      Fputs ( stderr ,                "The flag value should be \"TRUE\" or \"FALSE\"" ) ;
	      showerrorcontext () ;
	    } 
	    do {
		getnext () ;
	    } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	  } 
	  break ;
	case 8 : 
	  {
	    c = getbyte () ;
	    if ( c < 18 ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,  "HEADER indices should be 18 or more" ) ;
		showerrorcontext () ;
	      } 
	      do {
		  getnext () ;
	      } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	    } 
	    else if ( 4 * c + 4 > maxheaderbytes ) 
	    {
	      {
		if ( charsonline > 0 ) 
		{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		Fputs ( stderr ,                  "This HEADER index is too big for my present table size" ) ;
		showerrorcontext () ;
	      } 
	      do {
		  getnext () ;
	      } while ( ! ( ( curchar == 40 ) || ( curchar == 41 ) ) ) ;
	    } 
	    else {
		
	      while ( headerptr < 4 * c + 4 ) {
		  
		headerbytes [headerptr ]= 0 ;
		headerptr = headerptr + 1 ;
	      } 
	      readfourbytes ( 4 * c ) ;
	    } 
	  } 
	  break ;
	case 9 : 
	  {
	    while ( level == 1 ) {
		
	      while ( curchar == 32 ) getnext () ;
	      if ( curchar == 40 ) 
	      {
		getname () ;
		if ( curcode == 0 ) 
		skiptoendofitem () ;
		else if ( ( curcode < 30 ) || ( curcode >= 71 ) ) 
		{
		  {
		    if ( charsonline > 0 ) 
		    { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		    Fputs ( stderr ,                      "This property name doesn't belong in a FONTDIMEN list" ) 
		    ;
		    showerrorcontext () ;
		  } 
		  skiptoendofitem () ;
		} 
		else {
		    
		  if ( curcode == 30 ) 
		  c = getinteger () ;
		  else c = curcode - 30 ;
		  if ( c < 1 ) 
		  {
		    {
		      if ( charsonline > 0 ) 
		      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		      Fputs ( stderr ,  "PARAMETER index must be at least 1" ) 
		      ;
		      showerrorcontext () ;
		    } 
		    skiptoendofitem () ;
		  } 
		  else if ( c > maxparamwords ) 
		  {
		    {
		      if ( charsonline > 0 ) 
		      { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		      Fputs ( stderr ,                        "This PARAMETER index is too big for my present table size"                       ) ;
		      showerrorcontext () ;
		    } 
		    skiptoendofitem () ;
		  } 
		  else {
		      
		    while ( np < c ) {
			
		      np = np + 1 ;
		      param [np ]= 0 ;
		    } 
		    param [c ]= getfix () ;
		    finishtheproperty () ;
		  } 
		} 
	      } 
	      else if ( curchar == 41 ) 
	      skiptoendofitem () ;
	      else junkerror () ;
	    } 
	    {
	      loc = loc - 1 ;
	      level = level + 1 ;
	      curchar = 41 ;
	    } 
	  } 
	  break ;
	case 10 : 
	  readligkern () ;
	  break ;
	case 11 : 
	  bchar = getbyte () ;
	  break ;
	case 14 : 
	  readcharinfo () ;
	  break ;
	case 17 : 
	  {
	    ofmlevel = getinteger () ;
	    if ( ( ofmlevel < 0 ) || ( ofmlevel > 1 ) ) 
	    {
	      {
		{
		  if ( charsonline > 0 ) 
		  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		  Fputs ( stderr ,  "OFMLEVEL must be 0 or 1 -- 1 assumed" ) ;
		  showerrorcontext () ;
		} 
		skiptoendofitem () ;
	      } 
	      ofmlevel = 1 ;
	    } 
	  } 
	  break ;
	case 15 : 
	  {
	    fontdir = -1 ;
	    do {
		getnext () ;
	    } while ( ! ( curchar != 32 ) ) ;
	    switch ( curchar ) 
	    {case 84 : 
	      {
		getnext () ;
		if ( curchar == 76 ) 
		fontdir = 0 ;
		else if ( curchar == 82 ) 
		fontdir = 2 ;
	      } 
	      break ;
	    case 66 : 
	      {
		getnext () ;
		if ( curchar == 76 ) 
		fontdir = 4 ;
		else if ( curchar == 82 ) 
		fontdir = 6 ;
	      } 
	      break ;
	    case 82 : 
	      {
		getnext () ;
		if ( curchar == 84 ) 
		fontdir = 5 ;
		else if ( curchar == 66 ) 
		fontdir = 7 ;
	      } 
	      break ;
	    case 76 : 
	      {
		getnext () ;
		if ( curchar == 84 ) 
		fontdir = 1 ;
		else if ( curchar == 66 ) 
		fontdir = 3 ;
	      } 
	      break ;
	    } 
	    while ( curchar != 41 ) getnext () ;
	    if ( fontdir == -1 ) 
	    {
	      {
		{
		  if ( charsonline > 0 ) 
		  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		  Fputs ( stderr ,                    "FONTDIR must be valid direction, -- TL assumed" ) ;
		  showerrorcontext () ;
		} 
		skiptoendofitem () ;
	      } 
	      fontdir = 0 ;
	    } 
	  } 
	  break ;
	case 16 : 
	  {
	    fontdir = -1 ;
	    do {
		getnext () ;
	    } while ( ! ( curchar != 32 ) ) ;
	    switch ( curchar ) 
	    {case 84 : 
	      {
		getnext () ;
		if ( curchar == 76 ) 
		fontdir = 8 ;
		else if ( curchar == 82 ) 
		fontdir = 10 ;
	      } 
	      break ;
	    case 66 : 
	      {
		getnext () ;
		if ( curchar == 76 ) 
		fontdir = 12 ;
		else if ( curchar == 82 ) 
		fontdir = 14 ;
	      } 
	      break ;
	    case 82 : 
	      {
		getnext () ;
		if ( curchar == 84 ) 
		fontdir = 13 ;
		else if ( curchar == 66 ) 
		fontdir = 15 ;
	      } 
	      break ;
	    case 76 : 
	      {
		getnext () ;
		if ( curchar == 84 ) 
		fontdir = 9 ;
		else if ( curchar == 66 ) 
		fontdir = 11 ;
	      } 
	      break ;
	    } 
	    while ( curchar != 41 ) getnext () ;
	    if ( fontdir == -1 ) 
	    {
	      {
		{
		  if ( charsonline > 0 ) 
		  { putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
		  Fputs ( stderr ,                    "NFONTDIR must be valid direction, -- TL assumed" ) ;
		  showerrorcontext () ;
		} 
		skiptoendofitem () ;
	      } 
	      fontdir = 8 ;
	    } 
	  } 
	  break ;
	case 24 : 
	  readrepeatedcharacterinfo () ;
	  break ;
	case 18 : 
	  readfontrulelist () ;
	  break ;
	case 19 : 
	  readfontgluelist () ;
	  break ;
	case 20 : 
	  readfontpenaltylist () ;
	  break ;
	case 21 : 
	  readfontmvaluelist () ;
	  break ;
	case 22 : 
	  readfontfvaluelist () ;
	  break ;
	case 23 : 
	  readfontivaluelist () ;
	  break ;
	} 
	finishtheproperty () ;
      } 
    } 
    else if ( ( curchar == 41 ) && ! inputhasended ) 
    {
      {
	if ( charsonline > 0 ) 
	{ putc ( ' ' ,  stderr );  putc ( '\n',  stderr ); }
	Fputs ( stderr ,  "Extra right parenthesis" ) ;
	showerrorcontext () ;
      } 
      loc = loc + 1 ;
      curchar = 32 ;
    } 
    else if ( ! inputhasended ) 
    junkerror () ;
  } while ( ! ( inputhasended ) ) ;
} 
void 
corrandcheck ( void ) 
{
  integer c  ;
  integer hh  ;
  integer ligptr  ;
  bytetype g  ;
  if ( nl > 0 ) 
  {
    if ( charremainder [xmaxchar ]< xmaxlabel ) 
    {
      ligkern [nl ].b0 = 255 ;
      ligkern [nl ].b1 = 0 ;
      ligkern [nl ].b2 = 0 ;
      ligkern [nl ].b3 = 0 ;
      nl = nl + 1 ;
    } 
    while ( minnl > nl ) {
	
      ligkern [nl ].b0 = 255 ;
      ligkern [nl ].b1 = 0 ;
      ligkern [nl ].b2 = 0 ;
      ligkern [nl ].b3 = 0 ;
      nl = nl + 1 ;
    } 
    if ( ( ligkern [nl - 1 ].b0 % 256 ) == 0 ) 
    ligkern [nl - 1 ].b0 = ligkern [nl - 1 ].b0 / 256 * 256 + 128 ;
  } 
  sevenunsafe = false ;
  {register integer for_end; c = 0 ;for_end = maxchar ; if ( c <= for_end) 
  do 
    if ( charwd [c ]!= 0 ) 
    switch ( chartag [c ]) 
    {case 0 : 
      ;
      break ;
    case 1 : 
      {
	ligptr = charremainder [c ];
	if ( ligkern [ligptr ].b0 < 256 ) 
	{
	  do {
	      if ( hashinput ( ligptr , c ) ) 
	    {
	      if ( ligkern [ligptr ].b2 < 128 ) 
	      {
		if ( ligkern [ligptr ].b1 != bchar ) 
		{
		  g = ligkern [ligptr ].b1 ;
		  if ( charwd [g ]== 0 ) 
		  {
		    charwd [g ]= sortin ( 1 , 0 ) ;
		    fprintf ( stderr , "%s%c",  "LIG character examined by" , ' ' ) ;
		    printnumber ( c , 16 ) ;
		    fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
		  } 
		} 
		{
		  g = ligkern [ligptr ].b3 ;
		  if ( charwd [g ]== 0 ) 
		  {
		    charwd [g ]= sortin ( 1 , 0 ) ;
		    fprintf ( stderr , "%s%c",  "LIG character generated by" , ' ' ) ;
		    printnumber ( c , 16 ) ;
		    fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
		  } 
		} 
		if ( ligkern [ligptr ].b3 >= 128 ) {
		    
		  if ( ( c < 128 ) || ( c == bchar ) ) {
		      
		    if ( ( ligkern [ligptr ].b1 < 128 ) || ( ligkern [
		    ligptr ].b1 == bchar ) ) 
		    sevenunsafe = true ;
		  } 
		} 
	      } 
	      else if ( ligkern [ligptr ].b1 != bchar ) 
	      {
		g = ligkern [ligptr ].b1 ;
		if ( charwd [g ]== 0 ) 
		{
		  charwd [g ]= sortin ( 1 , 0 ) ;
		  fprintf ( stderr , "%s%c",  "KRN character examined by" , ' ' ) ;
		  printnumber ( c , 16 ) ;
		  fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
		} 
	      } 
	    } 
	    if ( ligkern [ligptr ].b0 >= 128 ) 
	    ligptr = nl ;
	    else ligptr = ligptr + 1 + ligkern [ligptr ].b0 ;
	  } while ( ! ( ligptr >= nl ) ) ;
	} 
      } 
      break ;
    case 2 : 
      {
	g = charremainder [c ];
	if ( ( g >= 128 ) && ( c < 128 ) ) 
	sevenunsafe = true ;
	if ( charwd [g ]== 0 ) 
	{
	  charwd [g ]= sortin ( 1 , 0 ) ;
	  fprintf ( stderr , "%s%c",  "The character NEXTLARGER than" , ' ' ) ;
	  printnumber ( c , 16 ) ;
	  fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
	} 
      } 
      break ;
    case 3 : 
      {
	if ( exten [charremainder [c ]].b0 > 0 ) 
	{
	  g = exten [charremainder [c ]].b0 ;
	  if ( ( g >= 128 ) && ( c < 128 ) ) 
	  sevenunsafe = true ;
	  if ( charwd [g ]== 0 ) 
	  {
	    charwd [g ]= sortin ( 1 , 0 ) ;
	    fprintf ( stderr , "%s%c",  "TOP piece of character" , ' ' ) ;
	    printnumber ( c , 16 ) ;
	    fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
	  } 
	} 
	if ( exten [charremainder [c ]].b1 > 0 ) 
	{
	  g = exten [charremainder [c ]].b1 ;
	  if ( ( g >= 128 ) && ( c < 128 ) ) 
	  sevenunsafe = true ;
	  if ( charwd [g ]== 0 ) 
	  {
	    charwd [g ]= sortin ( 1 , 0 ) ;
	    fprintf ( stderr , "%s%c",  "MID piece of character" , ' ' ) ;
	    printnumber ( c , 16 ) ;
	    fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
	  } 
	} 
	if ( exten [charremainder [c ]].b2 > 0 ) 
	{
	  g = exten [charremainder [c ]].b2 ;
	  if ( ( g >= 128 ) && ( c < 128 ) ) 
	  sevenunsafe = true ;
	  if ( charwd [g ]== 0 ) 
	  {
	    charwd [g ]= sortin ( 1 , 0 ) ;
	    fprintf ( stderr , "%s%c",  "BOT piece of character" , ' ' ) ;
	    printnumber ( c , 16 ) ;
	    fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
	  } 
	} 
	{
	  g = exten [charremainder [c ]].b3 ;
	  if ( ( g >= 128 ) && ( c < 128 ) ) 
	  sevenunsafe = true ;
	  if ( charwd [g ]== 0 ) 
	  {
	    charwd [g ]= sortin ( 1 , 0 ) ;
	    fprintf ( stderr , "%s%c",  "REP piece of character" , ' ' ) ;
	    printnumber ( c , 16 ) ;
	    fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
	  } 
	} 
      } 
      break ;
    } 
  while ( c++ < for_end ) ;} 
  if ( charremainder [xmaxchar ]< xmaxlabel ) 
  {
    c = xmaxchar ;
    {
      ligptr = charremainder [c ];
      if ( ligkern [ligptr ].b0 < 256 ) 
      {
	do {
	    if ( hashinput ( ligptr , c ) ) 
	  {
	    if ( ligkern [ligptr ].b2 < 128 ) 
	    {
	      if ( ligkern [ligptr ].b1 != bchar ) 
	      {
		g = ligkern [ligptr ].b1 ;
		if ( charwd [g ]== 0 ) 
		{
		  charwd [g ]= sortin ( 1 , 0 ) ;
		  fprintf ( stderr , "%s%c",  "LIG character examined by" , ' ' ) ;
		  printnumber ( c , 16 ) ;
		  fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
		} 
	      } 
	      {
		g = ligkern [ligptr ].b3 ;
		if ( charwd [g ]== 0 ) 
		{
		  charwd [g ]= sortin ( 1 , 0 ) ;
		  fprintf ( stderr , "%s%c",  "LIG character generated by" , ' ' ) ;
		  printnumber ( c , 16 ) ;
		  fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
		} 
	      } 
	      if ( ligkern [ligptr ].b3 >= 128 ) {
		  
		if ( ( c < 128 ) || ( c == bchar ) ) {
		    
		  if ( ( ligkern [ligptr ].b1 < 128 ) || ( ligkern [ligptr 
		  ].b1 == bchar ) ) 
		  sevenunsafe = true ;
		} 
	      } 
	    } 
	    else if ( ligkern [ligptr ].b1 != bchar ) 
	    {
	      g = ligkern [ligptr ].b1 ;
	      if ( charwd [g ]== 0 ) 
	      {
		charwd [g ]= sortin ( 1 , 0 ) ;
		fprintf ( stderr , "%s%c",  "KRN character examined by" , ' ' ) ;
		printnumber ( c , 16 ) ;
		fprintf ( stderr , "%s\n",  " had no CHARACTER spec." ) ;
	      } 
	    } 
	  } 
	  if ( ligkern [ligptr ].b0 >= 128 ) 
	  ligptr = nl ;
	  else ligptr = ligptr + 1 + ligkern [ligptr ].b0 ;
	} while ( ! ( ligptr >= nl ) ) ;
      } 
    } 
  } 
  if ( sevenbitsafeflag && sevenunsafe ) 
  fprintf ( stderr , "%s\n",  "The font is not really seven-bit-safe!" ) ;
  if ( hashptr < hashsize ) 
  {register integer for_end; hh = 1 ;for_end = hashptr ; if ( hh <= for_end) 
  do 
    {
      tt = hashlist [hh ];
      if ( classvar [tt ]> 0 ) 
      tt = f ( tt , ( hash [tt ]- 1 ) / xmaxchar , ( hash [tt ]- 1 ) % 
      xmaxchar ) ;
    } 
  while ( hh++ < for_end ) ;} 
  if ( ( hashptr == hashsize ) || ( yligcycle < xmaxchar ) ) 
  {
    if ( hashptr < hashsize ) 
    {
      Fputs ( stderr ,  "Infinite ligature loop starting with " ) ;
      if ( xligcycle == xmaxchar ) 
      Fputs ( stderr ,  "boundary" ) ;
      else printnumber ( xligcycle , 16 ) ;
      Fputs ( stderr ,  " and " ) ;
      printnumber ( yligcycle , 16 ) ;
      { putc ( '!' ,  stderr );  putc ( '\n',  stderr ); }
    } 
    else
    fprintf ( stderr , "%s\n",      "Sorry, I haven't room for so many ligature/kern pairs!" ) ;
    fprintf ( stderr , "%s\n",  "All ligatures will be cleared." ) ;
    {register integer for_end; c = 0 ;for_end = maxchar ; if ( c <= for_end) 
    do 
      if ( chartag [c ]== 1 ) 
      {
	chartag [c ]= 0 ;
	charremainder [c ]= 0 ;
      } 
    while ( c++ < for_end ) ;} 
    nl = 0 ;
    bchar = xmaxchar ;
    charremainder [xmaxchar ]= xmaxlabel ;
  } 
  if ( nl > 0 ) 
  {register integer for_end; ligptr = 0 ;for_end = nl - 1 ; if ( ligptr <= 
  for_end) do 
    if ( ( ligkern [ligptr ].b0 / 256 ) == 0 ) 
    {
      if ( ligkern [ligptr ].b2 < 128 ) 
      {
	if ( ligkern [ligptr ].b0 < 255 ) 
	{
	  {
	    c = ligkern [ligptr ].b1 ;
	    if ( charwd [c ]== 0 ) {
		
	      if ( c != bchar ) 
	      {
		ligkern [ligptr ].b1 = 0 ;
		if ( charwd [0 ]== 0 ) 
		charwd [0 ]= sortin ( 1 , 0 ) ;
		fprintf ( stderr , "%s%s%s",  "Unused " , "LIG step" ,                 " refers to nonexistent character " ) ;
		printnumber ( c , 16 ) ;
		{ putc ( '!' ,  stderr );  putc ( '\n',  stderr ); }
	      } 
	    } 
	  } 
	  {
	    c = ligkern [ligptr ].b3 ;
	    if ( charwd [c ]== 0 ) {
		
	      if ( c != bchar ) 
	      {
		ligkern [ligptr ].b3 = 0 ;
		if ( charwd [0 ]== 0 ) 
		charwd [0 ]= sortin ( 1 , 0 ) ;
		fprintf ( stderr , "%s%s%s",  "Unused " , "LIG step" ,                 " refers to nonexistent character " ) ;
		printnumber ( c , 16 ) ;
		{ putc ( '!' ,  stderr );  putc ( '\n',  stderr ); }
	      } 
	    } 
	  } 
	} 
      } 
      else {
	  
	c = ligkern [ligptr ].b1 ;
	if ( charwd [c ]== 0 ) {
	    
	  if ( c != bchar ) 
	  {
	    ligkern [ligptr ].b1 = 0 ;
	    if ( charwd [0 ]== 0 ) 
	    charwd [0 ]= sortin ( 1 , 0 ) ;
	    fprintf ( stderr , "%s%s%s",  "Unused " , "KRN step" ,             " refers to nonexistent character " ) ;
	    printnumber ( c , 16 ) ;
	    { putc ( '!' ,  stderr );  putc ( '\n',  stderr ); }
	  } 
	} 
      } 
    } 
  while ( ligptr++ < for_end ) ;} 
  if ( ne > 0 ) 
  {register integer for_end; g = 0 ;for_end = ne - 1 ; if ( g <= for_end) do 
    {
      {
	c = exten [g ].b0 ;
	if ( c > 0 ) {
	    
	  if ( charwd [c ]== 0 ) 
	  {
	    exten [g ].b0 = 0 ;
	    if ( charwd [0 ]== 0 ) 
	    charwd [0 ]= sortin ( 1 , 0 ) ;
	    fprintf ( stderr , "%s%s%s",  "Unused " , "VARCHAR TOP" ,             " refers to nonexistent character " ) ;
	    printnumber ( c , 16 ) ;
	    { putc ( '!' ,  stderr );  putc ( '\n',  stderr ); }
	  } 
	} 
      } 
      {
	c = exten [g ].b1 ;
	if ( c > 0 ) {
	    
	  if ( charwd [c ]== 0 ) 
	  {
	    exten [g ].b1 = 0 ;
	    if ( charwd [0 ]== 0 ) 
	    charwd [0 ]= sortin ( 1 , 0 ) ;
	    fprintf ( stderr , "%s%s%s",  "Unused " , "VARCHAR MID" ,             " refers to nonexistent character " ) ;
	    printnumber ( c , 16 ) ;
	    { putc ( '!' ,  stderr );  putc ( '\n',  stderr ); }
	  } 
	} 
      } 
      {
	c = exten [g ].b2 ;
	if ( c > 0 ) {
	    
	  if ( charwd [c ]== 0 ) 
	  {
	    exten [g ].b2 = 0 ;
	    if ( charwd [0 ]== 0 ) 
	    charwd [0 ]= sortin ( 1 , 0 ) ;
	    fprintf ( stderr , "%s%s%s",  "Unused " , "VARCHAR BOT" ,             " refers to nonexistent character " ) ;
	    printnumber ( c , 16 ) ;
	    { putc ( '!' ,  stderr );  putc ( '\n',  stderr ); }
	  } 
	} 
      } 
      {
	c = exten [g ].b3 ;
	if ( charwd [c ]== 0 ) 
	{
	  exten [g ].b3 = 0 ;
	  if ( charwd [0 ]== 0 ) 
	  charwd [0 ]= sortin ( 1 , 0 ) ;
	  fprintf ( stderr , "%s%s%s",  "Unused " , "VARCHAR REP" ,           " refers to nonexistent character " ) ;
	  printnumber ( c , 16 ) ;
	  { putc ( '!' ,  stderr );  putc ( '\n',  stderr ); }
	} 
      } 
    } 
  while ( g++ < for_end ) ;} 
  finishextendedfont () ;
  {register integer for_end; c = 0 ;for_end = maxchar ; if ( c <= for_end) 
  do 
    if ( chartag [c ]== 2 ) 
    {
      g = charremainder [c ];
      while ( ( g < c ) && ( chartag [g ]== 2 ) ) g = charremainder [g ];
      if ( g == c ) 
      {
	chartag [c ]= 0 ;
	Fputs ( stderr ,          "A cycle of NEXTLARGER characters has been broken at " ) ;
	printnumber ( c , 16 ) ;
	{ putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
      } 
    } 
  while ( c++ < for_end ) ;} 
  switch ( ofmlevel ) 
  {case -1 : 
    {
      topwidth = 255 ;
      topdepth = 15 ;
      topheight = 15 ;
      topitalic = 63 ;
    } 
    break ;
  case 0 : 
    {
      topwidth = 65535L ;
      topdepth = 255 ;
      topheight = 255 ;
      topitalic = 255 ;
    } 
    break ;
  case 1 : 
    {
      topwidth = 65535L ;
      topdepth = 255 ;
      topheight = 255 ;
      topitalic = 255 ;
    } 
    break ;
  } 
  delta = shorten ( 1 , topwidth ) ;
  setindices ( 1 , delta ) ;
  if ( delta > 0 ) 
  {
    fprintf ( stderr , "%s%s%s",  "I had to round some " , "width" , "s by " ) ;
    fprintreal ( stderr , ( ( ( delta + 1 ) / 2 ) / ((double) 1048576L ) ) , 1 
    , 7 ) ;
    fprintf ( stderr , "%s\n",  " units." ) ;
  } 
  delta = shorten ( 2 , topheight ) ;
  setindices ( 2 , delta ) ;
  if ( delta > 0 ) 
  {
    fprintf ( stderr , "%s%s%s",  "I had to round some " , "height" , "s by " ) ;
    fprintreal ( stderr , ( ( ( delta + 1 ) / 2 ) / ((double) 1048576L ) ) , 1 
    , 7 ) ;
    fprintf ( stderr , "%s\n",  " units." ) ;
  } 
  delta = shorten ( 3 , topdepth ) ;
  setindices ( 3 , delta ) ;
  if ( delta > 0 ) 
  {
    fprintf ( stderr , "%s%s%s",  "I had to round some " , "depth" , "s by " ) ;
    fprintreal ( stderr , ( ( ( delta + 1 ) / 2 ) / ((double) 1048576L ) ) , 1 
    , 7 ) ;
    fprintf ( stderr , "%s\n",  " units." ) ;
  } 
  delta = shorten ( 4 , topitalic ) ;
  setindices ( 4 , delta ) ;
  if ( delta > 0 ) 
  {
    fprintf ( stderr , "%s%s%s",  "I had to round some " , "italic correction" , "s by " ) 
    ;
    fprintreal ( stderr , ( ( ( delta + 1 ) / 2 ) / ((double) 1048576L ) ) , 1 
    , 7 ) ;
    fprintf ( stderr , "%s\n",  " units." ) ;
  } 
} 
void mainbody( void ) {
    
  initialize () ;
  nameenter () ;
  readinput () ;
  if ( verbose ) 
  { putc ( '.' ,  stderr );  putc ( '\n',  stderr ); }
  corrandcheck () ;
  computesubfilesizes () ;
  outputsubfilesizes () ;
  if ( ! checksumspecified ) 
  {
    curbytes .b0 = bc ;
    curbytes .b1 = ec ;
    curbytes .b2 = bc ;
    curbytes .b3 = ec ;
    {register integer for_end; c = bc ;for_end = ec ; if ( c <= for_end) do 
      if ( charwd [c ]> 0 ) 
      {
	tempwidth = memory [charwd [c ]];
	if ( designunits != 1048576L ) 
	tempwidth = round ( ( tempwidth / ((double) designunits ) ) * 
	1048576.0 ) ;
	tempwidth = tempwidth + ( c + 4 ) * 4194304L ;
	curbytes .b0 = ( curbytes .b0 + curbytes .b0 + tempwidth ) % 255 ;
	curbytes .b1 = ( curbytes .b1 + curbytes .b1 + tempwidth ) % 253 ;
	curbytes .b2 = ( curbytes .b2 + curbytes .b2 + tempwidth ) % 251 ;
	curbytes .b3 = ( curbytes .b3 + curbytes .b3 + tempwidth ) % 247 ;
      } 
    while ( c++ < for_end ) ;} 
    headerbytes [0 ]= curbytes .b0 ;
    headerbytes [1 ]= curbytes .b1 ;
    headerbytes [2 ]= curbytes .b2 ;
    headerbytes [3 ]= curbytes .b3 ;
  } 
  headerbytes [4 ]= designsize / 16777216L ;
  headerbytes [5 ]= ( designsize / 65536L ) % 256 ;
  headerbytes [6 ]= ( designsize / 256 ) % 256 ;
  headerbytes [7 ]= designsize % 256 ;
  if ( ( ! sevenunsafe ) && ( ofmlevel == -1 ) ) 
  headerbytes [68 ]= 128 ;
  {register integer for_end; j = 0 ;for_end = headerptr - 1 ; if ( j <= 
  for_end) do 
    putbyte ( headerbytes [j ], tfmfile ) ;
  while ( j++ < for_end ) ;} 
  outputnewinformationofm () ;
  outputcharacterinfo () ;
  {register integer for_end; q = 1 ;for_end = 4 ; if ( q <= for_end) do 
    {
      putbyte ( 0 , tfmfile ) ;
      putbyte ( 0 , tfmfile ) ;
      putbyte ( 0 , tfmfile ) ;
      putbyte ( 0 , tfmfile ) ;
      p = link [q ];
      while ( p > 0 ) {
	  
	outscaled ( memory [p ]) ;
	p = link [p ];
      } 
    } 
  while ( q++ < for_end ) ;} 
  if ( ofmlevel == -1 ) 
  {
    if ( extralocneeded ) 
    {
      putbyte ( 255 , tfmfile ) ;
      putbyte ( bchar , tfmfile ) ;
      putbyte ( 0 , tfmfile ) ;
      putbyte ( 0 , tfmfile ) ;
    } 
    else {
	register integer for_end; sortptr = 1 ;for_end = lkoffset ; if ( 
    sortptr <= for_end) do 
      {
	t = labeltable [labelptr ].rr ;
	if ( bchar < 256 ) 
	{
	  putbyte ( 255 , tfmfile ) ;
	  putbyte ( bchar , tfmfile ) ;
	} 
	else {
	    
	  putbyte ( 254 , tfmfile ) ;
	  putbyte ( 0 , tfmfile ) ;
	} 
	putbyte ( ( t + lkoffset ) / 256 , tfmfile ) ;
	putbyte ( ( t + lkoffset ) % 256 , tfmfile ) ;
	do {
	    labelptr = labelptr - 1 ;
	} while ( ! ( labeltable [labelptr ].rr < t ) ) ;
      } 
    while ( sortptr++ < for_end ) ;} 
    if ( nl > 0 ) 
    {register integer for_end; ligptr = 0 ;for_end = nl - 1 ; if ( ligptr <= 
    for_end) do 
      {
	putbyte ( ligkern [ligptr ].b0 , tfmfile ) ;
	putbyte ( ligkern [ligptr ].b1 , tfmfile ) ;
	putbyte ( ligkern [ligptr ].b2 , tfmfile ) ;
	putbyte ( ligkern [ligptr ].b3 , tfmfile ) ;
      } 
    while ( ligptr++ < for_end ) ;} 
    if ( nk > 0 ) 
    {register integer for_end; krnptr = 0 ;for_end = nk - 1 ; if ( krnptr <= 
    for_end) do 
      outscaled ( kern [krnptr ]) ;
    while ( krnptr++ < for_end ) ;} 
  } 
  else {
      
    if ( extralocneeded ) 
    {
      putbyte ( ( 255 ) / 256 , tfmfile ) ;
      putbyte ( ( 255 ) % 256 , tfmfile ) ;
      putbyte ( ( bchar ) / 256 , tfmfile ) ;
      putbyte ( ( bchar ) % 256 , tfmfile ) ;
      putbyte ( ( 0 ) / 256 , tfmfile ) ;
      putbyte ( ( 0 ) % 256 , tfmfile ) ;
      putbyte ( ( 0 ) / 256 , tfmfile ) ;
      putbyte ( ( 0 ) % 256 , tfmfile ) ;
    } 
    else {
	register integer for_end; sortptr = 1 ;for_end = lkoffset ; if ( 
    sortptr <= for_end) do 
      {
	t = labeltable [labelptr ].rr ;
	if ( bchar < xmaxchar ) 
	{
	  putbyte ( ( 255 ) / 256 , tfmfile ) ;
	  putbyte ( ( 255 ) % 256 , tfmfile ) ;
	  putbyte ( ( bchar ) / 256 , tfmfile ) ;
	  putbyte ( ( bchar ) % 256 , tfmfile ) ;
	} 
	else {
	    
	  putbyte ( ( 254 ) / 256 , tfmfile ) ;
	  putbyte ( ( 254 ) % 256 , tfmfile ) ;
	  putbyte ( ( 0 ) / 256 , tfmfile ) ;
	  putbyte ( ( 0 ) % 256 , tfmfile ) ;
	} 
	putbyte ( ( ( t + lkoffset ) / 256 ) / 256 , tfmfile ) ;
	putbyte ( ( ( t + lkoffset ) / 256 ) % 256 , tfmfile ) ;
	putbyte ( ( ( t + lkoffset ) % 256 ) / 256 , tfmfile ) ;
	putbyte ( ( ( t + lkoffset ) % 256 ) % 256 , tfmfile ) ;
	do {
	    labelptr = labelptr - 1 ;
	} while ( ! ( labeltable [labelptr ].rr < t ) ) ;
      } 
    while ( sortptr++ < for_end ) ;} 
    if ( nl > 0 ) 
    {register integer for_end; ligptr = 0 ;for_end = nl - 1 ; if ( ligptr <= 
    for_end) do 
      {
	putbyte ( ( ligkern [ligptr ].b0 ) / 256 , tfmfile ) ;
	putbyte ( ( ligkern [ligptr ].b0 ) % 256 , tfmfile ) ;
	putbyte ( ( ligkern [ligptr ].b1 ) / 256 , tfmfile ) ;
	putbyte ( ( ligkern [ligptr ].b1 ) % 256 , tfmfile ) ;
	putbyte ( ( ligkern [ligptr ].b2 ) / 256 , tfmfile ) ;
	putbyte ( ( ligkern [ligptr ].b2 ) % 256 , tfmfile ) ;
	putbyte ( ( ligkern [ligptr ].b3 ) / 256 , tfmfile ) ;
	putbyte ( ( ligkern [ligptr ].b3 ) % 256 , tfmfile ) ;
      } 
    while ( ligptr++ < for_end ) ;} 
    if ( nk > 0 ) 
    {register integer for_end; krnptr = 0 ;for_end = nk - 1 ; if ( krnptr <= 
    for_end) do 
      outscaled ( kern [krnptr ]) ;
    while ( krnptr++ < for_end ) ;} 
  } 
  if ( ofmlevel == -1 ) 
  {
    if ( ne > 0 ) 
    {register integer for_end; c = 0 ;for_end = ne - 1 ; if ( c <= for_end) 
    do 
      {
	putbyte ( exten [c ].b0 , tfmfile ) ;
	putbyte ( exten [c ].b1 , tfmfile ) ;
	putbyte ( exten [c ].b2 , tfmfile ) ;
	putbyte ( exten [c ].b3 , tfmfile ) ;
      } 
    while ( c++ < for_end ) ;} 
  } 
  else {
      
    if ( ne > 0 ) 
    {register integer for_end; c = 0 ;for_end = ne - 1 ; if ( c <= for_end) 
    do 
      {
	putbyte ( ( exten [c ].b0 ) / 256 , tfmfile ) ;
	putbyte ( ( exten [c ].b0 ) % 256 , tfmfile ) ;
	putbyte ( ( exten [c ].b1 ) / 256 , tfmfile ) ;
	putbyte ( ( exten [c ].b1 ) % 256 , tfmfile ) ;
	putbyte ( ( exten [c ].b2 ) / 256 , tfmfile ) ;
	putbyte ( ( exten [c ].b2 ) % 256 , tfmfile ) ;
	putbyte ( ( exten [c ].b3 ) / 256 , tfmfile ) ;
	putbyte ( ( exten [c ].b3 ) % 256 , tfmfile ) ;
      } 
    while ( c++ < for_end ) ;} 
  } 
  {register integer for_end; parptr = 1 ;for_end = np ; if ( parptr <= 
  for_end) do 
    {
      if ( parptr == 1 ) 
      {
	if ( param [1 ]< 0 ) 
	{
	  param [1 ]= param [1 ]+ 1073741824L ;
	  putbyte ( ( param [1 ]/ 16777216L ) + 192 , tfmfile ) ;
	} 
	else putbyte ( param [1 ]/ 16777216L , tfmfile ) ;
	putbyte ( ( param [1 ]/ 65536L ) % 256 , tfmfile ) ;
	putbyte ( ( param [1 ]/ 256 ) % 256 , tfmfile ) ;
	putbyte ( param [1 ]% 256 , tfmfile ) ;
      } 
      else outscaled ( param [parptr ]) ;
    } 
  while ( parptr++ < for_end ) ;} 
  if ( ! perfect ) 
  uexit ( 1 ) ;
} 
