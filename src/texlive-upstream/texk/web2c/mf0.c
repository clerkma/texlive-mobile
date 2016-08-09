#define EXTERN extern
#include "mfd.h"

void 
initialize ( void ) 
{
  integer i  ;
  integer k  ;
  xchr [32 ]= ' ' ;
  xchr [33 ]= '!' ;
  xchr [34 ]= '"' ;
  xchr [35 ]= '#' ;
  xchr [36 ]= '$' ;
  xchr [37 ]= '%' ;
  xchr [38 ]= '&' ;
  xchr [39 ]= '\'' ;
  xchr [40 ]= '(' ;
  xchr [41 ]= ')' ;
  xchr [42 ]= '*' ;
  xchr [43 ]= '+' ;
  xchr [44 ]= ',' ;
  xchr [45 ]= '-' ;
  xchr [46 ]= '.' ;
  xchr [47 ]= '/' ;
  xchr [48 ]= '0' ;
  xchr [49 ]= '1' ;
  xchr [50 ]= '2' ;
  xchr [51 ]= '3' ;
  xchr [52 ]= '4' ;
  xchr [53 ]= '5' ;
  xchr [54 ]= '6' ;
  xchr [55 ]= '7' ;
  xchr [56 ]= '8' ;
  xchr [57 ]= '9' ;
  xchr [58 ]= ':' ;
  xchr [59 ]= ';' ;
  xchr [60 ]= '<' ;
  xchr [61 ]= '=' ;
  xchr [62 ]= '>' ;
  xchr [63 ]= '?' ;
  xchr [64 ]= '@' ;
  xchr [65 ]= 'A' ;
  xchr [66 ]= 'B' ;
  xchr [67 ]= 'C' ;
  xchr [68 ]= 'D' ;
  xchr [69 ]= 'E' ;
  xchr [70 ]= 'F' ;
  xchr [71 ]= 'G' ;
  xchr [72 ]= 'H' ;
  xchr [73 ]= 'I' ;
  xchr [74 ]= 'J' ;
  xchr [75 ]= 'K' ;
  xchr [76 ]= 'L' ;
  xchr [77 ]= 'M' ;
  xchr [78 ]= 'N' ;
  xchr [79 ]= 'O' ;
  xchr [80 ]= 'P' ;
  xchr [81 ]= 'Q' ;
  xchr [82 ]= 'R' ;
  xchr [83 ]= 'S' ;
  xchr [84 ]= 'T' ;
  xchr [85 ]= 'U' ;
  xchr [86 ]= 'V' ;
  xchr [87 ]= 'W' ;
  xchr [88 ]= 'X' ;
  xchr [89 ]= 'Y' ;
  xchr [90 ]= 'Z' ;
  xchr [91 ]= '[' ;
  xchr [92 ]= '\\' ;
  xchr [93 ]= ']' ;
  xchr [94 ]= '^' ;
  xchr [95 ]= '_' ;
  xchr [96 ]= '`' ;
  xchr [97 ]= 'a' ;
  xchr [98 ]= 'b' ;
  xchr [99 ]= 'c' ;
  xchr [100 ]= 'd' ;
  xchr [101 ]= 'e' ;
  xchr [102 ]= 'f' ;
  xchr [103 ]= 'g' ;
  xchr [104 ]= 'h' ;
  xchr [105 ]= 'i' ;
  xchr [106 ]= 'j' ;
  xchr [107 ]= 'k' ;
  xchr [108 ]= 'l' ;
  xchr [109 ]= 'm' ;
  xchr [110 ]= 'n' ;
  xchr [111 ]= 'o' ;
  xchr [112 ]= 'p' ;
  xchr [113 ]= 'q' ;
  xchr [114 ]= 'r' ;
  xchr [115 ]= 's' ;
  xchr [116 ]= 't' ;
  xchr [117 ]= 'u' ;
  xchr [118 ]= 'v' ;
  xchr [119 ]= 'w' ;
  xchr [120 ]= 'x' ;
  xchr [121 ]= 'y' ;
  xchr [122 ]= 'z' ;
  xchr [123 ]= '{' ;
  xchr [124 ]= '|' ;
  xchr [125 ]= '}' ;
  xchr [126 ]= '~' ;
  {register integer for_end; i = 0 ;for_end = 31 ; if ( i <= for_end) do 
    xchr [i ]= i ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 127 ;for_end = 255 ; if ( i <= for_end) do 
    xchr [i ]= i ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 0 ;for_end = 255 ; if ( i <= for_end) do 
    xord [chr ( i ) ]= 127 ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 128 ;for_end = 255 ; if ( i <= for_end) do 
    xord [xchr [i ]]= i ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 0 ;for_end = 126 ; if ( i <= for_end) do 
    xord [xchr [i ]]= i ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 0 ;for_end = 255 ; if ( i <= for_end) do 
    xprn [i ]= ( eightbitp || ( ( i >= 32 ) && ( i <= 126 ) ) ) ;
  while ( i++ < for_end ) ;} 
  if ( translatefilename ) 
  readtcxfile () ;
  if ( interactionoption == 4 ) 
  interaction = 3 ;
  else interaction = interactionoption ;
  deletionsallowed = true ;
  errorcount = 0 ;
  helpptr = 0 ;
  useerrhelp = false ;
  errhelp = 0 ;
  interrupt = 0 ;
  OKtointerrupt = true ;
  aritherror = false ;
  twotothe [0 ]= 1 ;
  {register integer for_end; k = 1 ;for_end = 30 ; if ( k <= for_end) do 
    twotothe [k ]= 2 * twotothe [k - 1 ];
  while ( k++ < for_end ) ;} 
  speclog [1 ]= 93032640L ;
  speclog [2 ]= 38612034L ;
  speclog [3 ]= 17922280L ;
  speclog [4 ]= 8662214L ;
  speclog [5 ]= 4261238L ;
  speclog [6 ]= 2113709L ;
  speclog [7 ]= 1052693L ;
  speclog [8 ]= 525315L ;
  speclog [9 ]= 262400L ;
  speclog [10 ]= 131136L ;
  speclog [11 ]= 65552L ;
  speclog [12 ]= 32772L ;
  speclog [13 ]= 16385 ;
  {register integer for_end; k = 14 ;for_end = 27 ; if ( k <= for_end) do 
    speclog [k ]= twotothe [27 - k ];
  while ( k++ < for_end ) ;} 
  speclog [28 ]= 1 ;
  specatan [1 ]= 27855475L ;
  specatan [2 ]= 14718068L ;
  specatan [3 ]= 7471121L ;
  specatan [4 ]= 3750058L ;
  specatan [5 ]= 1876857L ;
  specatan [6 ]= 938658L ;
  specatan [7 ]= 469357L ;
  specatan [8 ]= 234682L ;
  specatan [9 ]= 117342L ;
  specatan [10 ]= 58671L ;
  specatan [11 ]= 29335 ;
  specatan [12 ]= 14668 ;
  specatan [13 ]= 7334 ;
  specatan [14 ]= 3667 ;
  specatan [15 ]= 1833 ;
  specatan [16 ]= 917 ;
  specatan [17 ]= 458 ;
  specatan [18 ]= 229 ;
  specatan [19 ]= 115 ;
  specatan [20 ]= 57 ;
  specatan [21 ]= 29 ;
  specatan [22 ]= 14 ;
  specatan [23 ]= 7 ;
  specatan [24 ]= 4 ;
  specatan [25 ]= 2 ;
  specatan [26 ]= 1 ;
	;
#ifdef TEXMF_DEBUG
  wasmemend = 0 ;
  waslomax = 0 ;
  washimin = memmax ;
  panicking = false ;
#endif /* TEXMF_DEBUG */
  {register integer for_end; k = 1 ;for_end = 41 ; if ( k <= for_end) do 
    internal [k ]= 0 ;
  while ( k++ < for_end ) ;} 
  intptr = 41 ;
  {register integer for_end; k = 48 ;for_end = 57 ; if ( k <= for_end) do 
    charclass [k ]= 0 ;
  while ( k++ < for_end ) ;} 
  charclass [46 ]= 1 ;
  charclass [32 ]= 2 ;
  charclass [37 ]= 3 ;
  charclass [34 ]= 4 ;
  charclass [44 ]= 5 ;
  charclass [59 ]= 6 ;
  charclass [40 ]= 7 ;
  charclass [41 ]= 8 ;
  {register integer for_end; k = 65 ;for_end = 90 ; if ( k <= for_end) do 
    charclass [k ]= 9 ;
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = 97 ;for_end = 122 ; if ( k <= for_end) do 
    charclass [k ]= 9 ;
  while ( k++ < for_end ) ;} 
  charclass [95 ]= 9 ;
  charclass [60 ]= 10 ;
  charclass [61 ]= 10 ;
  charclass [62 ]= 10 ;
  charclass [58 ]= 10 ;
  charclass [124 ]= 10 ;
  charclass [96 ]= 11 ;
  charclass [39 ]= 11 ;
  charclass [43 ]= 12 ;
  charclass [45 ]= 12 ;
  charclass [47 ]= 13 ;
  charclass [42 ]= 13 ;
  charclass [92 ]= 13 ;
  charclass [33 ]= 14 ;
  charclass [63 ]= 14 ;
  charclass [35 ]= 15 ;
  charclass [38 ]= 15 ;
  charclass [64 ]= 15 ;
  charclass [36 ]= 15 ;
  charclass [94 ]= 16 ;
  charclass [126 ]= 16 ;
  charclass [91 ]= 17 ;
  charclass [93 ]= 18 ;
  charclass [123 ]= 19 ;
  charclass [125 ]= 19 ;
  {register integer for_end; k = 0 ;for_end = 31 ; if ( k <= for_end) do 
    charclass [k ]= 20 ;
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = 127 ;for_end = 255 ; if ( k <= for_end) do 
    charclass [k ]= 20 ;
  while ( k++ < for_end ) ;} 
  charclass [9 ]= 2 ;
  charclass [12 ]= 2 ;
  hash [1 ].lhfield = 0 ;
  hash [1 ].v.RH = 0 ;
  eqtb [1 ].lhfield = 41 ;
  eqtb [1 ].v.RH = 0 ;
  {register integer for_end; k = 2 ;for_end = 9769 ; if ( k <= for_end) do 
    {
      hash [k ]= hash [1 ];
      eqtb [k ]= eqtb [1 ];
    } 
  while ( k++ < for_end ) ;} 
  bignodesize [13 ]= 12 ;
  bignodesize [14 ]= 4 ;
  saveptr = 0 ;
  octantdir [1 ]= 548 ;
  octantdir [5 ]= 549 ;
  octantdir [6 ]= 550 ;
  octantdir [2 ]= 551 ;
  octantdir [4 ]= 552 ;
  octantdir [8 ]= 553 ;
  octantdir [7 ]= 554 ;
  octantdir [3 ]= 555 ;
  maxroundingptr = 0 ;
  octantcode [1 ]= 1 ;
  octantcode [2 ]= 5 ;
  octantcode [3 ]= 6 ;
  octantcode [4 ]= 2 ;
  octantcode [5 ]= 4 ;
  octantcode [6 ]= 8 ;
  octantcode [7 ]= 7 ;
  octantcode [8 ]= 3 ;
  {register integer for_end; k = 1 ;for_end = 8 ; if ( k <= for_end) do 
    octantnumber [octantcode [k ]]= k ;
  while ( k++ < for_end ) ;} 
  revturns = false ;
  xcorr [1 ]= 0 ;
  ycorr [1 ]= 0 ;
  xycorr [1 ]= 0 ;
  xcorr [5 ]= 0 ;
  ycorr [5 ]= 0 ;
  xycorr [5 ]= 1 ;
  xcorr [6 ]= -1 ;
  ycorr [6 ]= 1 ;
  xycorr [6 ]= 0 ;
  xcorr [2 ]= 1 ;
  ycorr [2 ]= 0 ;
  xycorr [2 ]= 1 ;
  xcorr [4 ]= 0 ;
  ycorr [4 ]= 1 ;
  xycorr [4 ]= 1 ;
  xcorr [8 ]= 0 ;
  ycorr [8 ]= 1 ;
  xycorr [8 ]= 0 ;
  xcorr [7 ]= 1 ;
  ycorr [7 ]= 0 ;
  xycorr [7 ]= 1 ;
  xcorr [3 ]= -1 ;
  ycorr [3 ]= 1 ;
  xycorr [3 ]= 0 ;
  {register integer for_end; k = 1 ;for_end = 8 ; if ( k <= for_end) do 
    zcorr [k ]= xycorr [k ]- xcorr [k ];
  while ( k++ < for_end ) ;} 
  screenstarted = false ;
  screenOK = false ;
  {register integer for_end; k = 0 ;for_end = 15 ; if ( k <= for_end) do 
    {
      windowopen [k ]= false ;
      windowtime [k ]= 0 ;
    } 
  while ( k++ < for_end ) ;} 
  fixneeded = false ;
  watchcoefs = true ;
  condptr = 0 ;
  iflimit = 0 ;
  curif = 0 ;
  ifline = 0 ;
  loopptr = 0 ;
  curexp = 0 ;
  varflag = 0 ;
  startsym = 0 ;
  longhelpseen = false ;
  {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
    {
      tfmwidth [k ]= 0 ;
      tfmheight [k ]= 0 ;
      tfmdepth [k ]= 0 ;
      tfmitalcorr [k ]= 0 ;
      charexists [k ]= false ;
      chartag [k ]= 0 ;
      charremainder [k ]= 0 ;
      skiptable [k ]= ligtablesize ;
    } 
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = 1 ;for_end = headersize ; if ( k <= 
  for_end) do 
    headerbyte [k ]= -1 ;
  while ( k++ < for_end ) ;} 
  bc = 255 ;
  ec = 0 ;
  nl = 0 ;
  nk = 0 ;
  ne = 0 ;
  np = 0 ;
  internal [41 ]= -65536L ;
  bchlabel = ligtablesize ;
  labelloc [0 ]= -1 ;
  labelptr = 0 ;
  gfprevptr = 0 ;
  totalchars = 0 ;
  halfbuf = gfbufsize / 2 ;
  gflimit = gfbufsize ;
  gfptr = 0 ;
  gfoffset = 0 ;
  baseident = 0 ;
  editnamestart = 0 ;
  stopatspace = true ;
} 
void 
println ( void ) 
{
  switch ( selector ) 
  {case 3 : 
    {
      putc ('\n',  stdout );
      putc ('\n',  logfile );
      termoffset = 0 ;
      fileoffset = 0 ;
    } 
    break ;
  case 2 : 
    {
      putc ('\n',  logfile );
      fileoffset = 0 ;
    } 
    break ;
  case 1 : 
    {
      putc ('\n',  stdout );
      termoffset = 0 ;
    } 
    break ;
  case 0 : 
  case 4 : 
  case 5 : 
    ;
    break ;
  } 
} 
void 
zprintchar ( ASCIIcode s ) 
{
  switch ( selector ) 
  {case 3 : 
    {
      putc ( xchr [s ],  stdout );
      putc ( xchr [s ],  logfile );
      incr ( termoffset ) ;
      incr ( fileoffset ) ;
      if ( termoffset == maxprintline ) 
      {
	putc ('\n',  stdout );
	termoffset = 0 ;
      } 
      if ( fileoffset == maxprintline ) 
      {
	putc ('\n',  logfile );
	fileoffset = 0 ;
      } 
    } 
    break ;
  case 2 : 
    {
      putc ( xchr [s ],  logfile );
      incr ( fileoffset ) ;
      if ( fileoffset == maxprintline ) 
      println () ;
    } 
    break ;
  case 1 : 
    {
      putc ( xchr [s ],  stdout );
      incr ( termoffset ) ;
      if ( termoffset == maxprintline ) 
      println () ;
    } 
    break ;
  case 0 : 
    ;
    break ;
  case 4 : 
    if ( tally < trickcount ) 
    trickbuf [tally % errorline ]= s ;
    break ;
  case 5 : 
    {
      if ( poolptr < poolsize ) 
      {
	strpool [poolptr ]= s ;
	incr ( poolptr ) ;
      } 
    } 
    break ;
  } 
  incr ( tally ) ;
} 
void 
zprint ( integer s ) 
{
  poolpointer j  ;
  if ( ( s < 0 ) || ( s >= strptr ) ) 
  s = 259 ;
  if ( ( s < 256 ) && ( ( selector > 4 ) || xprn [s ]) ) 
  printchar ( s ) ;
  else {
      
    j = strstart [s ];
    while ( j < strstart [s + 1 ]) {
	
      printchar ( strpool [j ]) ;
      incr ( j ) ;
    } 
  } 
} 
void 
zslowprint ( integer s ) 
{
  poolpointer j  ;
  if ( ( s < 0 ) || ( s >= strptr ) ) 
  s = 259 ;
  if ( ( s < 256 ) && ( ( selector > 4 ) || xprn [s ]) ) 
  printchar ( s ) ;
  else {
      
    j = strstart [s ];
    while ( j < strstart [s + 1 ]) {
	
      print ( strpool [j ]) ;
      incr ( j ) ;
    } 
  } 
} 
void 
zprintnl ( strnumber s ) 
{
  if ( ( ( termoffset > 0 ) && ( odd ( selector ) ) ) || ( ( fileoffset > 0 
  ) && ( selector >= 2 ) ) ) 
  println () ;
  print ( s ) ;
} 
void 
zprintthedigs ( eightbits k ) 
{
  while ( k > 0 ) {
      
    decr ( k ) ;
    printchar ( 48 + dig [k ]) ;
  } 
} 
void 
zprintint ( integer n ) 
{
  unsigned char k  ;
  integer m  ;
  k = 0 ;
  if ( n < 0 ) 
  {
    printchar ( 45 ) ;
    if ( n > -100000000L ) 
    n = - (integer) n ;
    else {
	
      m = -1 - n ;
      n = m / 10 ;
      m = ( m % 10 ) + 1 ;
      k = 1 ;
      if ( m < 10 ) 
      dig [0 ]= m ;
      else {
	  
	dig [0 ]= 0 ;
	incr ( n ) ;
      } 
    } 
  } 
  do {
      dig [k ]= n % 10 ;
    n = n / 10 ;
    incr ( k ) ;
  } while ( ! ( n == 0 ) ) ;
  printthedigs ( k ) ;
} 
void 
zprintscaled ( scaled s ) 
{
  scaled delta  ;
  if ( s < 0 ) 
  {
    printchar ( 45 ) ;
    s = - (integer) s ;
  } 
  printint ( s / 65536L ) ;
  s = 10 * ( s % 65536L ) + 5 ;
  if ( s != 5 ) 
  {
    delta = 10 ;
    printchar ( 46 ) ;
    do {
	if ( delta > 65536L ) 
      s = s + 32768L - ( delta / 2 ) ;
      printchar ( 48 + ( s / 65536L ) ) ;
      s = 10 * ( s % 65536L ) ;
      delta = delta * 10 ;
    } while ( ! ( s <= delta ) ) ;
  } 
} 
void 
zprinttwo ( scaled x , scaled y ) 
{
  printchar ( 40 ) ;
  printscaled ( x ) ;
  printchar ( 44 ) ;
  printscaled ( y ) ;
  printchar ( 41 ) ;
} 
void 
zprinttype ( smallnumber t ) 
{
  switch ( t ) 
  {case 1 : 
    print ( 323 ) ;
    break ;
  case 2 : 
    print ( 324 ) ;
    break ;
  case 3 : 
    print ( 325 ) ;
    break ;
  case 4 : 
    print ( 326 ) ;
    break ;
  case 5 : 
    print ( 327 ) ;
    break ;
  case 6 : 
    print ( 328 ) ;
    break ;
  case 7 : 
    print ( 329 ) ;
    break ;
  case 8 : 
    print ( 330 ) ;
    break ;
  case 9 : 
    print ( 331 ) ;
    break ;
  case 10 : 
    print ( 332 ) ;
    break ;
  case 11 : 
    print ( 333 ) ;
    break ;
  case 12 : 
    print ( 334 ) ;
    break ;
  case 13 : 
    print ( 335 ) ;
    break ;
  case 14 : 
    print ( 336 ) ;
    break ;
  case 16 : 
    print ( 337 ) ;
    break ;
  case 17 : 
    print ( 338 ) ;
    break ;
  case 18 : 
    print ( 339 ) ;
    break ;
  case 15 : 
    print ( 340 ) ;
    break ;
  case 19 : 
    print ( 341 ) ;
    break ;
  case 20 : 
    print ( 342 ) ;
    break ;
  case 21 : 
    print ( 343 ) ;
    break ;
  case 22 : 
    print ( 344 ) ;
    break ;
  case 23 : 
    print ( 345 ) ;
    break ;
    default: 
    print ( 346 ) ;
    break ;
  } 
} 
void 
begindiagnostic ( void ) 
{
  oldsetting = selector ;
  if ( ( internal [13 ]<= 0 ) && ( selector == 3 ) ) 
  {
    decr ( selector ) ;
    if ( history == 0 ) 
    history = 1 ;
  } 
} 
void 
zenddiagnostic ( boolean blankline ) 
{
  printnl ( 261 ) ;
  if ( blankline ) 
  println () ;
  selector = oldsetting ;
} 
void 
zprintdiagnostic ( strnumber s , strnumber t , boolean nuline ) 
{
  begindiagnostic () ;
  if ( nuline ) 
  printnl ( s ) ;
  else print ( s ) ;
  print ( 450 ) ;
  printint ( line ) ;
  print ( t ) ;
  printchar ( 58 ) ;
} 
void 
zprintfilename ( integer n , integer a , integer e ) 
{
  boolean mustquote  ;
  poolpointer j  ;
  mustquote = false ;
  if ( a != 0 ) 
  {
    j = strstart [a ];
    while ( ( ! mustquote ) && ( j < strstart [a + 1 ]) ) {
	
      mustquote = strpool [j ]== 32 ;
      incr ( j ) ;
    } 
  } 
  if ( n != 0 ) 
  {
    j = strstart [n ];
    while ( ( ! mustquote ) && ( j < strstart [n + 1 ]) ) {
	
      mustquote = strpool [j ]== 32 ;
      incr ( j ) ;
    } 
  } 
  if ( e != 0 ) 
  {
    j = strstart [e ];
    while ( ( ! mustquote ) && ( j < strstart [e + 1 ]) ) {
	
      mustquote = strpool [j ]== 32 ;
      incr ( j ) ;
    } 
  } 
  if ( mustquote ) 
  slowprint ( 34 ) ;
  if ( a != 0 ) 
  {register integer for_end; j = strstart [a ];for_end = strstart [a + 1 
  ]- 1 ; if ( j <= for_end) do 
    if ( strpool [j ]!= 34 ) 
    print ( strpool [j ]) ;
  while ( j++ < for_end ) ;} 
  if ( n != 0 ) 
  {register integer for_end; j = strstart [n ];for_end = strstart [n + 1 
  ]- 1 ; if ( j <= for_end) do 
    if ( strpool [j ]!= 34 ) 
    print ( strpool [j ]) ;
  while ( j++ < for_end ) ;} 
  if ( e != 0 ) 
  {register integer for_end; j = strstart [e ];for_end = strstart [e + 1 
  ]- 1 ; if ( j <= for_end) do 
    if ( strpool [j ]!= 34 ) 
    print ( strpool [j ]) ;
  while ( j++ < for_end ) ;} 
  if ( mustquote ) 
  slowprint ( 34 ) ;
} 
#ifdef TEXMF_DEBUG
#endif /* TEXMF_DEBUG */
void 
zflushstring ( strnumber s ) 
{
  if ( s < strptr - 1 ) 
  strref [s ]= 0 ;
  else do {
      decr ( strptr ) ;
  } while ( ! ( strref [strptr - 1 ]!= 0 ) ) ;
  poolptr = strstart [strptr ];
} 
void 
jumpout ( void ) 
{
  closefilesandterminate () ;
  {
    fflush ( stdout ) ;
    readyalready = 0 ;
    if ( ( history != 0 ) && ( history != 1 ) ) 
    uexit ( 1 ) ;
    else uexit ( 0 ) ;
  } 
} 
void 
error ( void ) 
{
  /* 22 10 */ ASCIIcode c  ;
  integer s1, s2, s3  ;
  poolpointer j  ;
  if ( history < 2 ) 
  history = 2 ;
  printchar ( 46 ) ;
  showcontext () ;
  if ( ( haltonerrorp ) ) 
  {
    history = 3 ;
    jumpout () ;
  } 
  if ( interaction == 3 ) 
  while ( true ) {
      
    lab22: clearforerrorprompt () ;
    {
      ;
      print ( 265 ) ;
      terminput () ;
    } 
    if ( last == first ) 
    goto lab10 ;
    c = buffer [first ];
    if ( c >= 97 ) 
    c = c - 32 ;
    switch ( c ) 
    {case 48 : 
    case 49 : 
    case 50 : 
    case 51 : 
    case 52 : 
    case 53 : 
    case 54 : 
    case 55 : 
    case 56 : 
    case 57 : 
      if ( deletionsallowed ) 
      {
	s1 = curcmd ;
	s2 = curmod ;
	s3 = cursym ;
	OKtointerrupt = false ;
	if ( ( last > first + 1 ) && ( buffer [first + 1 ]>= 48 ) && ( 
	buffer [first + 1 ]<= 57 ) ) 
	c = c * 10 + buffer [first + 1 ]- 48 * 11 ;
	else c = c - 48 ;
	while ( c > 0 ) {
	    
	  getnext () ;
	  if ( curcmd == 39 ) 
	  {
	    if ( strref [curmod ]< 127 ) {
		
	      if ( strref [curmod ]> 1 ) 
	      decr ( strref [curmod ]) ;
	      else flushstring ( curmod ) ;
	    } 
	  } 
	  decr ( c ) ;
	} 
	curcmd = s1 ;
	curmod = s2 ;
	cursym = s3 ;
	OKtointerrupt = true ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 278 ;
	  helpline [0 ]= 279 ;
	} 
	showcontext () ;
	goto lab22 ;
      } 
      break ;
	;
#ifdef TEXMF_DEBUG
    case 68 : 
      {
	debughelp () ;
	goto lab22 ;
      } 
      break ;
#endif /* TEXMF_DEBUG */
    case 69 : 
      if ( fileptr > 0 ) 
      {
	editnamestart = strstart [inputstack [fileptr ].namefield ];
	editnamelength = strstart [inputstack [fileptr ].namefield + 1 ]- 
	strstart [inputstack [fileptr ].namefield ];
	editline = line ;
	jumpout () ;
      } 
      break ;
    case 72 : 
      {
	if ( useerrhelp ) 
	{
	  j = strstart [errhelp ];
	  while ( j < strstart [errhelp + 1 ]) {
	      
	    if ( strpool [j ]!= 37 ) 
	    print ( strpool [j ]) ;
	    else if ( j + 1 == strstart [errhelp + 1 ]) 
	    println () ;
	    else if ( strpool [j + 1 ]!= 37 ) 
	    println () ;
	    else {
		
	      incr ( j ) ;
	      printchar ( 37 ) ;
	    } 
	    incr ( j ) ;
	  } 
	  useerrhelp = false ;
	} 
	else {
	    
	  if ( helpptr == 0 ) 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 280 ;
	    helpline [0 ]= 281 ;
	  } 
	  do {
	      decr ( helpptr ) ;
	    print ( helpline [helpptr ]) ;
	    println () ;
	  } while ( ! ( helpptr == 0 ) ) ;
	} 
	{
	  helpptr = 4 ;
	  helpline [3 ]= 282 ;
	  helpline [2 ]= 281 ;
	  helpline [1 ]= 283 ;
	  helpline [0 ]= 284 ;
	} 
	goto lab22 ;
      } 
      break ;
    case 73 : 
      {
	beginfilereading () ;
	if ( last > first + 1 ) 
	{
	  curinput .locfield = first + 1 ;
	  buffer [first ]= 32 ;
	} 
	else {
	    
	  {
	    ;
	    print ( 277 ) ;
	    terminput () ;
	  } 
	  curinput .locfield = first ;
	} 
	first = last + 1 ;
	curinput .limitfield = last ;
	goto lab10 ;
      } 
      break ;
    case 81 : 
    case 82 : 
    case 83 : 
      {
	errorcount = 0 ;
	interaction = 0 + c - 81 ;
	print ( 272 ) ;
	switch ( c ) 
	{case 81 : 
	  {
	    print ( 273 ) ;
	    decr ( selector ) ;
	  } 
	  break ;
	case 82 : 
	  print ( 274 ) ;
	  break ;
	case 83 : 
	  print ( 275 ) ;
	  break ;
	} 
	print ( 276 ) ;
	println () ;
	fflush ( stdout ) ;
	goto lab10 ;
      } 
      break ;
    case 88 : 
      {
	interaction = 2 ;
	jumpout () ;
      } 
      break ;
      default: 
      ;
      break ;
    } 
    {
      print ( 266 ) ;
      printnl ( 267 ) ;
      printnl ( 268 ) ;
      if ( fileptr > 0 ) 
      print ( 269 ) ;
      if ( deletionsallowed ) 
      printnl ( 270 ) ;
      printnl ( 271 ) ;
    } 
  } 
  incr ( errorcount ) ;
  if ( errorcount == 100 ) 
  {
    printnl ( 264 ) ;
    history = 3 ;
    jumpout () ;
  } 
  if ( interaction > 0 ) 
  decr ( selector ) ;
  if ( useerrhelp ) 
  {
    printnl ( 261 ) ;
    j = strstart [errhelp ];
    while ( j < strstart [errhelp + 1 ]) {
	
      if ( strpool [j ]!= 37 ) 
      print ( strpool [j ]) ;
      else if ( j + 1 == strstart [errhelp + 1 ]) 
      println () ;
      else if ( strpool [j + 1 ]!= 37 ) 
      println () ;
      else {
	  
	incr ( j ) ;
	printchar ( 37 ) ;
      } 
      incr ( j ) ;
    } 
  } 
  else while ( helpptr > 0 ) {
      
    decr ( helpptr ) ;
    printnl ( helpline [helpptr ]) ;
  } 
  println () ;
  if ( interaction > 0 ) 
  incr ( selector ) ;
  println () ;
  lab10: ;
} 
void 
zfatalerror ( strnumber s ) 
{
  normalizeselector () ;
  {
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( 285 ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( 285 ) ;
    } 
  } 
  {
    helpptr = 1 ;
    helpline [0 ]= s ;
  } 
  {
    if ( interaction == 3 ) 
    interaction = 2 ;
    if ( logopened ) 
    error () ;
	;
#ifdef TEXMF_DEBUG
    if ( interaction > 0 ) 
    debughelp () ;
#endif /* TEXMF_DEBUG */
    history = 3 ;
    jumpout () ;
  } 
} 
void 
zoverflow ( strnumber s , integer n ) 
{
  normalizeselector () ;
  {
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( 286 ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( 286 ) ;
    } 
  } 
  print ( s ) ;
  printchar ( 61 ) ;
  printint ( n ) ;
  printchar ( 93 ) ;
  {
    helpptr = 2 ;
    helpline [1 ]= 287 ;
    helpline [0 ]= 288 ;
  } 
  {
    if ( interaction == 3 ) 
    interaction = 2 ;
    if ( logopened ) 
    error () ;
	;
#ifdef TEXMF_DEBUG
    if ( interaction > 0 ) 
    debughelp () ;
#endif /* TEXMF_DEBUG */
    history = 3 ;
    jumpout () ;
  } 
} 
void 
zconfusion ( strnumber s ) 
{
  normalizeselector () ;
  if ( history < 2 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 289 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 289 ) ;
      } 
    } 
    print ( s ) ;
    printchar ( 41 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 290 ;
    } 
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 291 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 291 ) ;
      } 
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 292 ;
      helpline [0 ]= 293 ;
    } 
  } 
  {
    if ( interaction == 3 ) 
    interaction = 2 ;
    if ( logopened ) 
    error () ;
	;
#ifdef TEXMF_DEBUG
    if ( interaction > 0 ) 
    debughelp () ;
#endif /* TEXMF_DEBUG */
    history = 3 ;
    jumpout () ;
  } 
} 
boolean 
initterminal ( void ) 
{
  /* 10 */ register boolean Result; topenin () ;
  if ( last > first ) 
  {
    curinput .locfield = first ;
    while ( ( curinput .locfield < last ) && ( buffer [curinput .locfield ]
    == ' ' ) ) incr ( curinput .locfield ) ;
    if ( curinput .locfield < last ) 
    {
      Result = true ;
      goto lab10 ;
    } 
  } 
  while ( true ) {
      
    ;
    Fputs ( stdout ,  "**" ) ;
    fflush ( stdout ) ;
    if ( ! inputln ( stdin , true ) ) 
    {
      putc ('\n',  stdout );
      fprintf ( stdout , "%s\n",  "! End of file on the terminal... why?" ) ;
      Result = false ;
      goto lab10 ;
    } 
    curinput .locfield = first ;
    while ( ( curinput .locfield < last ) && ( buffer [curinput .locfield ]
    == 32 ) ) incr ( curinput .locfield ) ;
    if ( curinput .locfield < last ) 
    {
      Result = true ;
      goto lab10 ;
    } 
    fprintf ( stdout , "%s\n",  "Please type the name of your input file." ) ;
  } 
  lab10: ;
  return Result ;
} 
strnumber 
makestring ( void ) 
{
  register strnumber Result; if ( strptr == maxstrptr ) 
  {
    if ( strptr == maxstrings ) 
    overflow ( 258 , maxstrings - initstrptr ) ;
    incr ( maxstrptr ) ;
  } 
  strref [strptr ]= 1 ;
  incr ( strptr ) ;
  strstart [strptr ]= poolptr ;
  Result = strptr - 1 ;
  return Result ;
} 
boolean 
zstreqbuf ( strnumber s , integer k ) 
{
  /* 45 */ register boolean Result; poolpointer j  ;
  boolean result  ;
  j = strstart [s ];
  while ( j < strstart [s + 1 ]) {
      
    if ( strpool [j ]!= buffer [k ]) 
    {
      result = false ;
      goto lab45 ;
    } 
    incr ( j ) ;
    incr ( k ) ;
  } 
  result = true ;
  lab45: Result = result ;
  return Result ;
} 
integer 
zstrvsstr ( strnumber s , strnumber t ) 
{
  /* 10 */ register integer Result; poolpointer j, k  ;
  integer ls, lt  ;
  integer l  ;
  ls = ( strstart [s + 1 ]- strstart [s ]) ;
  lt = ( strstart [t + 1 ]- strstart [t ]) ;
  if ( ls <= lt ) 
  l = ls ;
  else l = lt ;
  j = strstart [s ];
  k = strstart [t ];
  while ( l > 0 ) {
      
    if ( strpool [j ]!= strpool [k ]) 
    {
      Result = strpool [j ]- strpool [k ];
      goto lab10 ;
    } 
    incr ( j ) ;
    incr ( k ) ;
    decr ( l ) ;
  } 
  Result = ls - lt ;
  lab10: ;
  return Result ;
} 
void 
zprintdd ( integer n ) 
{
  n = abs ( n ) % 100 ;
  printchar ( 48 + ( n / 10 ) ) ;
  printchar ( 48 + ( n % 10 ) ) ;
} 
void 
terminput ( void ) 
{
  integer k  ;
  fflush ( stdout ) ;
  if ( ! inputln ( stdin , true ) ) 
  fatalerror ( 260 ) ;
  termoffset = 0 ;
  decr ( selector ) ;
  if ( last != first ) 
  {register integer for_end; k = first ;for_end = last - 1 ; if ( k <= 
  for_end) do 
    print ( buffer [k ]) ;
  while ( k++ < for_end ) ;} 
  println () ;
  buffer [last ]= 37 ;
  incr ( selector ) ;
} 
void 
normalizeselector ( void ) 
{
  if ( logopened ) 
  selector = 3 ;
  else selector = 1 ;
  if ( jobname == 0 ) 
  openlogfile () ;
  if ( interaction == 0 ) 
  decr ( selector ) ;
} 
void 
pauseforinstructions ( void ) 
{
  if ( OKtointerrupt ) 
  {
    interaction = 3 ;
    if ( ( selector == 2 ) || ( selector == 0 ) ) 
    incr ( selector ) ;
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 294 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 294 ) ;
      } 
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 295 ;
      helpline [1 ]= 296 ;
      helpline [0 ]= 297 ;
    } 
    deletionsallowed = false ;
    error () ;
    deletionsallowed = true ;
    interrupt = 0 ;
  } 
} 
void 
zmissingerr ( strnumber s ) 
{
  {
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( 298 ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( 298 ) ;
    } 
  } 
  print ( s ) ;
  print ( 299 ) ;
} 
void 
cleararith ( void ) 
{
  {
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( 300 ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( 300 ) ;
    } 
  } 
  {
    helpptr = 4 ;
    helpline [3 ]= 301 ;
    helpline [2 ]= 302 ;
    helpline [1 ]= 303 ;
    helpline [0 ]= 304 ;
  } 
  error () ;
  aritherror = false ;
} 
integer 
zslowadd ( integer x , integer y ) 
{
  register integer Result; if ( x >= 0 ) {
      
    if ( y <= 2147483647L - x ) 
    Result = x + y ;
    else {
	
      aritherror = true ;
      Result = 2147483647L ;
    } 
  } 
  else if ( - (integer) y <= 2147483647L + x ) 
  Result = x + y ;
  else {
      
    aritherror = true ;
    Result = -2147483647L ;
  } 
  return Result ;
} 
scaled 
zrounddecimals ( smallnumber k ) 
{
  register scaled Result; integer a  ;
  a = 0 ;
  while ( k > 0 ) {
      
    decr ( k ) ;
    a = ( a + dig [k ]* 131072L ) / 10 ;
  } 
  Result = halfp ( a + 1 ) ;
  return Result ;
} 
#ifdef FIXPT
fraction 
zmakefraction ( integer p , integer q ) 
{
  register fraction Result; integer f  ;
  integer n  ;
  boolean negative  ;
  integer becareful  ;
  if ( p >= 0 ) 
  negative = false ;
  else {
      
    p = - (integer) p ;
    negative = true ;
  } 
  if ( q <= 0 ) 
  {
	;
#ifdef TEXMF_DEBUG
    if ( q == 0 ) 
    confusion ( 47 ) ;
#endif /* TEXMF_DEBUG */
    q = - (integer) q ;
    negative = ! negative ;
  } 
  n = p / q ;
  p = p % q ;
  if ( n >= 8 ) 
  {
    aritherror = true ;
    if ( negative ) 
    Result = -2147483647L ;
    else Result = 2147483647L ;
  } 
  else {
      
    n = ( n - 1 ) * 268435456L ;
    f = 1 ;
    do {
	becareful = p - q ;
      p = becareful + p ;
      if ( p >= 0 ) 
      f = f + f + 1 ;
      else {
	  
	f = f + f ;
	p = p + q ;
      } 
    } while ( ! ( f >= 268435456L ) ) ;
    becareful = p - q ;
    if ( becareful + p >= 0 ) 
    incr ( f ) ;
    if ( negative ) 
    Result = - (integer) ( f + n ) ;
    else Result = f + n ;
  } 
  return Result ;
} 
#endif /* FIXPT */
#ifdef FIXPT
integer 
ztakefraction ( integer q , fraction f ) 
{
  register integer Result; integer p  ;
  boolean negative  ;
  integer n  ;
  integer becareful  ;
  if ( f >= 0 ) 
  negative = false ;
  else {
      
    f = - (integer) f ;
    negative = true ;
  } 
  if ( q < 0 ) 
  {
    q = - (integer) q ;
    negative = ! negative ;
  } 
  if ( f < 268435456L ) 
  n = 0 ;
  else {
      
    n = f / 268435456L ;
    f = f % 268435456L ;
    if ( q <= 2147483647L / n ) 
    n = n * q ;
    else {
	
      aritherror = true ;
      n = 2147483647L ;
    } 
  } 
  f = f + 268435456L ;
  p = 134217728L ;
  if ( q < 1073741824L ) 
  do {
      if ( odd ( f ) ) 
    p = halfp ( p + q ) ;
    else p = halfp ( p ) ;
    f = halfp ( f ) ;
  } while ( ! ( f == 1 ) ) ;
  else do {
      if ( odd ( f ) ) 
    p = p + halfp ( q - p ) ;
    else p = halfp ( p ) ;
    f = halfp ( f ) ;
  } while ( ! ( f == 1 ) ) ;
  becareful = n - 2147483647L ;
  if ( becareful + p > 0 ) 
  {
    aritherror = true ;
    n = 2147483647L - p ;
  } 
  if ( negative ) 
  Result = - (integer) ( n + p ) ;
  else Result = n + p ;
  return Result ;
} 
#endif /* FIXPT */
#ifdef FIXPT
integer 
ztakescaled ( integer q , scaled f ) 
{
  register integer Result; integer p  ;
  boolean negative  ;
  integer n  ;
  integer becareful  ;
  if ( f >= 0 ) 
  negative = false ;
  else {
      
    f = - (integer) f ;
    negative = true ;
  } 
  if ( q < 0 ) 
  {
    q = - (integer) q ;
    negative = ! negative ;
  } 
  if ( f < 65536L ) 
  n = 0 ;
  else {
      
    n = f / 65536L ;
    f = f % 65536L ;
    if ( q <= 2147483647L / n ) 
    n = n * q ;
    else {
	
      aritherror = true ;
      n = 2147483647L ;
    } 
  } 
  f = f + 65536L ;
  p = 32768L ;
  if ( q < 1073741824L ) 
  do {
      if ( odd ( f ) ) 
    p = halfp ( p + q ) ;
    else p = halfp ( p ) ;
    f = halfp ( f ) ;
  } while ( ! ( f == 1 ) ) ;
  else do {
      if ( odd ( f ) ) 
    p = p + halfp ( q - p ) ;
    else p = halfp ( p ) ;
    f = halfp ( f ) ;
  } while ( ! ( f == 1 ) ) ;
  becareful = n - 2147483647L ;
  if ( becareful + p > 0 ) 
  {
    aritherror = true ;
    n = 2147483647L - p ;
  } 
  if ( negative ) 
  Result = - (integer) ( n + p ) ;
  else Result = n + p ;
  return Result ;
} 
#endif /* FIXPT */
#ifdef FIXPT
scaled 
zmakescaled ( integer p , integer q ) 
{
  register scaled Result; integer f  ;
  integer n  ;
  boolean negative  ;
  integer becareful  ;
  if ( p >= 0 ) 
  negative = false ;
  else {
      
    p = - (integer) p ;
    negative = true ;
  } 
  if ( q <= 0 ) 
  {
	;
#ifdef TEXMF_DEBUG
    if ( q == 0 ) 
    confusion ( 47 ) ;
#endif /* TEXMF_DEBUG */
    q = - (integer) q ;
    negative = ! negative ;
  } 
  n = p / q ;
  p = p % q ;
  if ( n >= 32768L ) 
  {
    aritherror = true ;
    if ( negative ) 
    Result = -2147483647L ;
    else Result = 2147483647L ;
  } 
  else {
      
    n = ( n - 1 ) * 65536L ;
    f = 1 ;
    do {
	becareful = p - q ;
      p = becareful + p ;
      if ( p >= 0 ) 
      f = f + f + 1 ;
      else {
	  
	f = f + f ;
	p = p + q ;
      } 
    } while ( ! ( f >= 65536L ) ) ;
    becareful = p - q ;
    if ( becareful + p >= 0 ) 
    incr ( f ) ;
    if ( negative ) 
    Result = - (integer) ( f + n ) ;
    else Result = f + n ;
  } 
  return Result ;
} 
#endif /* FIXPT */
fraction 
zvelocity ( fraction st , fraction ct , fraction sf , fraction cf , scaled t ) 
{
  register fraction Result; integer acc, num, denom  ;
  acc = takefraction ( st - ( sf / 16 ) , sf - ( st / 16 ) ) ;
  acc = takefraction ( acc , ct - cf ) ;
  num = 536870912L + takefraction ( acc , 379625062L ) ;
  denom = 805306368L + takefraction ( ct , 497706707L ) + takefraction ( cf , 
  307599661L ) ;
  if ( t != 65536L ) 
  num = makescaled ( num , t ) ;
  if ( num / 4 >= denom ) 
  Result = 1073741824L ;
  else Result = makefraction ( num , denom ) ;
  return Result ;
} 
integer 
zabvscd ( integer a , integer b , integer c , integer d ) 
{
  /* 10 */ register integer Result; integer q, r  ;
  if ( a < 0 ) 
  {
    a = - (integer) a ;
    b = - (integer) b ;
  } 
  if ( c < 0 ) 
  {
    c = - (integer) c ;
    d = - (integer) d ;
  } 
  if ( d <= 0 ) 
  {
    if ( b >= 0 ) {
	
      if ( ( ( a == 0 ) || ( b == 0 ) ) && ( ( c == 0 ) || ( d == 0 ) ) ) 
      {
	Result = 0 ;
	goto lab10 ;
      } 
      else {
	  
	Result = 1 ;
	goto lab10 ;
      } 
    } 
    if ( d == 0 ) {
	
      if ( a == 0 ) 
      {
	Result = 0 ;
	goto lab10 ;
      } 
      else {
	  
	Result = -1 ;
	goto lab10 ;
      } 
    } 
    q = a ;
    a = c ;
    c = q ;
    q = - (integer) b ;
    b = - (integer) d ;
    d = q ;
  } 
  else if ( b <= 0 ) 
  {
    if ( b < 0 ) {
	
      if ( a > 0 ) 
      {
	Result = -1 ;
	goto lab10 ;
      } 
    } 
    if ( c == 0 ) 
    {
      Result = 0 ;
      goto lab10 ;
    } 
    else {
	
      Result = -1 ;
      goto lab10 ;
    } 
  } 
  while ( true ) {
      
    q = a / d ;
    r = c / b ;
    if ( q != r ) {
	
      if ( q > r ) 
      {
	Result = 1 ;
	goto lab10 ;
      } 
      else {
	  
	Result = -1 ;
	goto lab10 ;
      } 
    } 
    q = a % d ;
    r = c % b ;
    if ( r == 0 ) {
	
      if ( q == 0 ) 
      {
	Result = 0 ;
	goto lab10 ;
      } 
      else {
	  
	Result = 1 ;
	goto lab10 ;
      } 
    } 
    if ( q == 0 ) 
    {
      Result = -1 ;
      goto lab10 ;
    } 
    a = b ;
    b = q ;
    c = d ;
    d = r ;
  } 
  lab10: ;
  return Result ;
} 
scaled 
zsquarert ( scaled x ) 
{
  register scaled Result; smallnumber k  ;
  integer y, q  ;
  if ( x <= 0 ) 
  {
    if ( x < 0 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 305 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 305 ) ;
	} 
      } 
      printscaled ( x ) ;
      print ( 306 ) ;
      {
	helpptr = 2 ;
	helpline [1 ]= 307 ;
	helpline [0 ]= 308 ;
      } 
      error () ;
    } 
    Result = 0 ;
  } 
  else {
      
    k = 23 ;
    q = 2 ;
    while ( x < 536870912L ) {
	
      decr ( k ) ;
      x = x + x + x + x ;
    } 
    if ( x < 1073741824L ) 
    y = 0 ;
    else {
	
      x = x - 1073741824L ;
      y = 1 ;
    } 
    do {
	x = x + x ;
      y = y + y ;
      if ( x >= 1073741824L ) 
      {
	x = x - 1073741824L ;
	incr ( y ) ;
      } 
      x = x + x ;
      y = y + y - q ;
      q = q + q ;
      if ( x >= 1073741824L ) 
      {
	x = x - 1073741824L ;
	incr ( y ) ;
      } 
      if ( y > q ) 
      {
	y = y - q ;
	q = q + 2 ;
      } 
      else if ( y <= 0 ) 
      {
	q = q - 2 ;
	y = y + q ;
      } 
      decr ( k ) ;
    } while ( ! ( k == 0 ) ) ;
    Result = halfp ( q ) ;
  } 
  return Result ;
} 
integer 
zpythadd ( integer a , integer b ) 
{
  /* 30 */ register integer Result; fraction r  ;
  boolean big  ;
  a = abs ( a ) ;
  b = abs ( b ) ;
  if ( a < b ) 
  {
    r = b ;
    b = a ;
    a = r ;
  } 
  if ( b > 0 ) 
  {
    if ( a < 536870912L ) 
    big = false ;
    else {
	
      a = a / 4 ;
      b = b / 4 ;
      big = true ;
    } 
    while ( true ) {
	
      r = makefraction ( b , a ) ;
      r = takefraction ( r , r ) ;
      if ( r == 0 ) 
      goto lab30 ;
      r = makefraction ( r , 1073741824L + r ) ;
      a = a + takefraction ( a + a , r ) ;
      b = takefraction ( b , r ) ;
    } 
    lab30: ;
    if ( big ) {
	
      if ( a < 536870912L ) 
      a = a + a + a + a ;
      else {
	  
	aritherror = true ;
	a = 2147483647L ;
      } 
    } 
  } 
  Result = a ;
  return Result ;
} 
integer 
zpythsub ( integer a , integer b ) 
{
  /* 30 */ register integer Result; fraction r  ;
  boolean big  ;
  a = abs ( a ) ;
  b = abs ( b ) ;
  if ( a <= b ) 
  {
    if ( a < b ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 309 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 309 ) ;
	} 
      } 
      printscaled ( a ) ;
      print ( 310 ) ;
      printscaled ( b ) ;
      print ( 306 ) ;
      {
	helpptr = 2 ;
	helpline [1 ]= 307 ;
	helpline [0 ]= 308 ;
      } 
      error () ;
    } 
    a = 0 ;
  } 
  else {
      
    if ( a < 1073741824L ) 
    big = false ;
    else {
	
      a = halfp ( a ) ;
      b = halfp ( b ) ;
      big = true ;
    } 
    while ( true ) {
	
      r = makefraction ( b , a ) ;
      r = takefraction ( r , r ) ;
      if ( r == 0 ) 
      goto lab30 ;
      r = makefraction ( r , 1073741824L - r ) ;
      a = a - takefraction ( a + a , r ) ;
      b = takefraction ( b , r ) ;
    } 
    lab30: ;
    if ( big ) 
    a = a + a ;
  } 
  Result = a ;
  return Result ;
} 
scaled 
zmlog ( scaled x ) 
{
  register scaled Result; integer y, z  ;
  integer k  ;
  if ( x <= 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 311 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 311 ) ;
      } 
    } 
    printscaled ( x ) ;
    print ( 306 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 312 ;
      helpline [0 ]= 308 ;
    } 
    error () ;
    Result = 0 ;
  } 
  else {
      
    y = 1302456860L ;
    z = 6581195L ;
    while ( x < 1073741824L ) {
	
      x = x + x ;
      y = y - 93032639L ;
      z = z - 48782L ;
    } 
    y = y + ( z / 65536L ) ;
    k = 2 ;
    while ( x > 1073741828L ) {
	
      z = ( ( x - 1 ) / twotothe [k ]) + 1 ;
      while ( x < 1073741824L + z ) {
	  
	z = halfp ( z + 1 ) ;
	k = k + 1 ;
      } 
      y = y + speclog [k ];
      x = x - z ;
    } 
    Result = y / 8 ;
  } 
  return Result ;
} 
scaled 
zmexp ( scaled x ) 
{
  register scaled Result; smallnumber k  ;
  integer y, z  ;
  if ( x > 174436200L ) 
  {
    aritherror = true ;
    Result = 2147483647L ;
  } 
  else if ( x < -197694359L ) 
  Result = 0 ;
  else {
      
    if ( x <= 0 ) 
    {
      z = -8 * x ;
      y = 1048576L ;
    } 
    else {
	
      if ( x <= 127919879L ) 
      z = 1023359037L - 8 * x ;
      else z = 8 * ( 174436200L - x ) ;
      y = 2147483647L ;
    } 
    k = 1 ;
    while ( z > 0 ) {
	
      while ( z >= speclog [k ]) {
	  
	z = z - speclog [k ];
	y = y - 1 - ( ( y - twotothe [k - 1 ]) / twotothe [k ]) ;
      } 
      incr ( k ) ;
    } 
    if ( x <= 127919879L ) 
    Result = ( y + 8 ) / 16 ;
    else Result = y ;
  } 
  return Result ;
} 
angle 
znarg ( integer x , integer y ) 
{
  register angle Result; angle z  ;
  integer t  ;
  smallnumber k  ;
  unsigned char octant  ;
  if ( x >= 0 ) 
  octant = 1 ;
  else {
      
    x = - (integer) x ;
    octant = 2 ;
  } 
  if ( y < 0 ) 
  {
    y = - (integer) y ;
    octant = octant + 2 ;
  } 
  if ( x < y ) 
  {
    t = y ;
    y = x ;
    x = t ;
    octant = octant + 4 ;
  } 
  if ( x == 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 313 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 313 ) ;
      } 
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 314 ;
      helpline [0 ]= 308 ;
    } 
    error () ;
    Result = 0 ;
  } 
  else {
      
    while ( x >= 536870912L ) {
	
      x = halfp ( x ) ;
      y = halfp ( y ) ;
    } 
    z = 0 ;
    if ( y > 0 ) 
    {
      while ( x < 268435456L ) {
	  
	x = x + x ;
	y = y + y ;
      } 
      k = 0 ;
      do {
	  y = y + y ;
	incr ( k ) ;
	if ( y > x ) 
	{
	  z = z + specatan [k ];
	  t = x ;
	  x = x + ( y / twotothe [k + k ]) ;
	  y = y - t ;
	} 
      } while ( ! ( k == 15 ) ) ;
      do {
	  y = y + y ;
	incr ( k ) ;
	if ( y > x ) 
	{
	  z = z + specatan [k ];
	  y = y - x ;
	} 
      } while ( ! ( k == 26 ) ) ;
    } 
    switch ( octant ) 
    {case 1 : 
      Result = z ;
      break ;
    case 5 : 
      Result = 94371840L - z ;
      break ;
    case 6 : 
      Result = 94371840L + z ;
      break ;
    case 2 : 
      Result = 188743680L - z ;
      break ;
    case 4 : 
      Result = z - 188743680L ;
      break ;
    case 8 : 
      Result = - (integer) z - 94371840L ;
      break ;
    case 7 : 
      Result = z - 94371840L ;
      break ;
    case 3 : 
      Result = - (integer) z ;
      break ;
    } 
  } 
  return Result ;
} 
void 
znsincos ( angle z ) 
{
  smallnumber k  ;
  unsigned char q  ;
  fraction r  ;
  integer x, y, t  ;
  while ( z < 0 ) z = z + 377487360L ;
  z = z % 377487360L ;
  q = z / 47185920L ;
  z = z % 47185920L ;
  x = 268435456L ;
  y = x ;
  if ( ! odd ( q ) ) 
  z = 47185920L - z ;
  k = 1 ;
  while ( z > 0 ) {
      
    if ( z >= specatan [k ]) 
    {
      z = z - specatan [k ];
      t = x ;
      x = t + y / twotothe [k ];
      y = y - t / twotothe [k ];
    } 
    incr ( k ) ;
  } 
  if ( y < 0 ) 
  y = 0 ;
  switch ( q ) 
  {case 0 : 
    ;
    break ;
  case 1 : 
    {
      t = x ;
      x = y ;
      y = t ;
    } 
    break ;
  case 2 : 
    {
      t = x ;
      x = - (integer) y ;
      y = t ;
    } 
    break ;
  case 3 : 
    x = - (integer) x ;
    break ;
  case 4 : 
    {
      x = - (integer) x ;
      y = - (integer) y ;
    } 
    break ;
  case 5 : 
    {
      t = x ;
      x = - (integer) y ;
      y = - (integer) t ;
    } 
    break ;
  case 6 : 
    {
      t = x ;
      x = y ;
      y = - (integer) t ;
    } 
    break ;
  case 7 : 
    y = - (integer) y ;
    break ;
  } 
  r = pythadd ( x , y ) ;
  ncos = makefraction ( x , r ) ;
  nsin = makefraction ( y , r ) ;
} 
void 
newrandoms ( void ) 
{
  unsigned char k  ;
  fraction x  ;
  {register integer for_end; k = 0 ;for_end = 23 ; if ( k <= for_end) do 
    {
      x = randoms [k ]- randoms [k + 31 ];
      if ( x < 0 ) 
      x = x + 268435456L ;
      randoms [k ]= x ;
    } 
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = 24 ;for_end = 54 ; if ( k <= for_end) do 
    {
      x = randoms [k ]- randoms [k - 24 ];
      if ( x < 0 ) 
      x = x + 268435456L ;
      randoms [k ]= x ;
    } 
  while ( k++ < for_end ) ;} 
  jrandom = 54 ;
} 
void 
zinitrandoms ( scaled seed ) 
{
  fraction j, jj, k  ;
  unsigned char i  ;
  j = abs ( seed ) ;
  while ( j >= 268435456L ) j = halfp ( j ) ;
  k = 1 ;
  {register integer for_end; i = 0 ;for_end = 54 ; if ( i <= for_end) do 
    {
      jj = k ;
      k = j - k ;
      j = jj ;
      if ( k < 0 ) 
      k = k + 268435456L ;
      randoms [( i * 21 ) % 55 ]= j ;
    } 
  while ( i++ < for_end ) ;} 
  newrandoms () ;
  newrandoms () ;
  newrandoms () ;
} 
scaled 
zunifrand ( scaled x ) 
{
  register scaled Result; scaled y  ;
  if ( jrandom == 0 ) 
  newrandoms () ;
  else decr ( jrandom ) ;
  y = takefraction ( abs ( x ) , randoms [jrandom ]) ;
  if ( y == abs ( x ) ) 
  Result = 0 ;
  else if ( x > 0 ) 
  Result = y ;
  else Result = - (integer) y ;
  return Result ;
} 
scaled 
normrand ( void ) 
{
  register scaled Result; integer x, u, l  ;
  do {
      do { if ( jrandom == 0 ) 
      newrandoms () ;
      else decr ( jrandom ) ;
      x = takefraction ( 112429L , randoms [jrandom ]- 134217728L ) ;
      if ( jrandom == 0 ) 
      newrandoms () ;
      else decr ( jrandom ) ;
      u = randoms [jrandom ];
    } while ( ! ( abs ( x ) < u ) ) ;
    x = makefraction ( x , u ) ;
    l = 139548960L - mlog ( u ) ;
  } while ( ! ( abvscd ( 1024 , l , x , x ) >= 0 ) ) ;
  Result = x ;
  return Result ;
} 
#ifdef TEXMF_DEBUG
void 
zprintword ( memoryword w ) 
{
  printint ( w .cint ) ;
  printchar ( 32 ) ;
  printscaled ( w .cint ) ;
  printchar ( 32 ) ;
  printscaled ( w .cint / 4096 ) ;
  println () ;
  printint ( w .hhfield .lhfield ) ;
  printchar ( 61 ) ;
  printint ( w .hhfield .b0 ) ;
  printchar ( 58 ) ;
  printint ( w .hhfield .b1 ) ;
  printchar ( 59 ) ;
  printint ( w .hhfield .v.RH ) ;
  printchar ( 32 ) ;
  printint ( w .qqqq .b0 ) ;
  printchar ( 58 ) ;
  printint ( w .qqqq .b1 ) ;
  printchar ( 58 ) ;
  printint ( w .qqqq .b2 ) ;
  printchar ( 58 ) ;
  printint ( w .qqqq .b3 ) ;
} 
#endif /* TEXMF_DEBUG */
void 
zshowtokenlist ( integer p , integer q , integer l , integer nulltally ) 
{
  /* 10 */ smallnumber cclass, c  ;
  integer r, v  ;
  cclass = 3 ;
  tally = nulltally ;
  while ( ( p != 0 ) && ( tally < l ) ) {
      
    if ( p == q ) 
    {
      firstcount = tally ;
      trickcount = tally + 1 + errorline - halferrorline ;
      if ( trickcount < errorline ) 
      trickcount = errorline ;
    } 
    c = 9 ;
    if ( ( p < 0 ) || ( p > memend ) ) 
    {
      print ( 493 ) ;
      goto lab10 ;
    } 
    if ( p < himemmin ) {
	
      if ( mem [p ].hhfield .b1 == 12 ) {
	  
	if ( mem [p ].hhfield .b0 == 16 ) 
	{
	  if ( cclass == 0 ) 
	  printchar ( 32 ) ;
	  v = mem [p + 1 ].cint ;
	  if ( v < 0 ) 
	  {
	    if ( cclass == 17 ) 
	    printchar ( 32 ) ;
	    printchar ( 91 ) ;
	    printscaled ( v ) ;
	    printchar ( 93 ) ;
	    c = 18 ;
	  } 
	  else {
	      
	    printscaled ( v ) ;
	    c = 0 ;
	  } 
	} 
	else if ( mem [p ].hhfield .b0 != 4 ) 
	print ( 496 ) ;
	else {
	    
	  printchar ( 34 ) ;
	  slowprint ( mem [p + 1 ].cint ) ;
	  printchar ( 34 ) ;
	  c = 4 ;
	} 
      } 
      else if ( ( mem [p ].hhfield .b1 != 11 ) || ( mem [p ].hhfield .b0 < 
      1 ) || ( mem [p ].hhfield .b0 > 19 ) ) 
      print ( 496 ) ;
      else {
	  
	gpointer = p ;
	printcapsule () ;
	c = 8 ;
      } 
    } 
    else {
	
      r = mem [p ].hhfield .lhfield ;
      if ( r >= 9770 ) 
      {
	if ( r < 9920 ) 
	{
	  print ( 498 ) ;
	  r = r - ( 9770 ) ;
	} 
	else if ( r < 10070 ) 
	{
	  print ( 499 ) ;
	  r = r - ( 9920 ) ;
	} 
	else {
	    
	  print ( 500 ) ;
	  r = r - ( 10070 ) ;
	} 
	printint ( r ) ;
	printchar ( 41 ) ;
	c = 8 ;
      } 
      else if ( r < 1 ) {
	  
	if ( r == 0 ) 
	{
	  if ( cclass == 17 ) 
	  printchar ( 32 ) ;
	  print ( 497 ) ;
	  c = 18 ;
	} 
	else print ( 494 ) ;
      } 
      else {
	  
	r = hash [r ].v.RH ;
	if ( ( r < 0 ) || ( r >= strptr ) ) 
	print ( 495 ) ;
	else {
	    
	  c = charclass [strpool [strstart [r ]]];
	  if ( c == cclass ) 
	  switch ( c ) 
	  {case 9 : 
	    printchar ( 46 ) ;
	    break ;
	  case 5 : 
	  case 6 : 
	  case 7 : 
	  case 8 : 
	    ;
	    break ;
	    default: 
	    printchar ( 32 ) ;
	    break ;
	  } 
	  slowprint ( r ) ;
	} 
      } 
    } 
    cclass = c ;
    p = mem [p ].hhfield .v.RH ;
  } 
  if ( p != 0 ) 
  print ( 492 ) ;
  lab10: ;
} 
void 
runaway ( void ) 
{
  if ( scannerstatus > 2 ) 
  {
    printnl ( 638 ) ;
    switch ( scannerstatus ) 
    {case 3 : 
      print ( 639 ) ;
      break ;
    case 4 : 
    case 5 : 
      print ( 640 ) ;
      break ;
    case 6 : 
      print ( 641 ) ;
      break ;
    } 
    println () ;
    showtokenlist ( mem [memtop - 2 ].hhfield .v.RH , 0 , errorline - 10 , 0 
    ) ;
  } 
} 
halfword 
getavail ( void ) 
{
  register halfword Result; halfword p  ;
  p = avail ;
  if ( p != 0 ) 
  avail = mem [avail ].hhfield .v.RH ;
  else if ( memend < memmax ) 
  {
    incr ( memend ) ;
    p = memend ;
  } 
  else {
      
    decr ( himemmin ) ;
    p = himemmin ;
    if ( himemmin <= lomemmax ) 
    {
      runaway () ;
      overflow ( 315 , memmax + 1 ) ;
    } 
  } 
  mem [p ].hhfield .v.RH = 0 ;
	;
#ifdef STAT
  incr ( dynused ) ;
#endif /* STAT */
  Result = p ;
  return Result ;
} 
halfword 
zgetnode ( integer s ) 
{
  /* 40 10 20 */ register halfword Result; halfword p  ;
  halfword q  ;
  integer r  ;
  integer t, tt  ;
  lab20: p = rover ;
  do {
      q = p + mem [p ].hhfield .lhfield ;
    while ( ( mem [q ].hhfield .v.RH == 268435455L ) ) {
	
      t = mem [q + 1 ].hhfield .v.RH ;
      tt = mem [q + 1 ].hhfield .lhfield ;
      if ( q == rover ) 
      rover = t ;
      mem [t + 1 ].hhfield .lhfield = tt ;
      mem [tt + 1 ].hhfield .v.RH = t ;
      q = q + mem [q ].hhfield .lhfield ;
    } 
    r = q - s ;
    if ( r > p + 1 ) 
    {
      mem [p ].hhfield .lhfield = r - p ;
      rover = p ;
      goto lab40 ;
    } 
    if ( r == p ) {
	
      if ( mem [p + 1 ].hhfield .v.RH != p ) 
      {
	rover = mem [p + 1 ].hhfield .v.RH ;
	t = mem [p + 1 ].hhfield .lhfield ;
	mem [rover + 1 ].hhfield .lhfield = t ;
	mem [t + 1 ].hhfield .v.RH = rover ;
	goto lab40 ;
      } 
    } 
    mem [p ].hhfield .lhfield = q - p ;
    p = mem [p + 1 ].hhfield .v.RH ;
  } while ( ! ( p == rover ) ) ;
  if ( s == 1073741824L ) 
  {
    Result = 268435455L ;
    goto lab10 ;
  } 
  if ( lomemmax + 2 < himemmin ) {
      
    if ( lomemmax + 2 <= 268435455L ) 
    {
      if ( himemmin - lomemmax >= 1998 ) 
      t = lomemmax + 1000 ;
      else t = lomemmax + 1 + ( himemmin - lomemmax ) / 2 ;
      if ( t > 268435455L ) 
      t = 268435455L ;
      p = mem [rover + 1 ].hhfield .lhfield ;
      q = lomemmax ;
      mem [p + 1 ].hhfield .v.RH = q ;
      mem [rover + 1 ].hhfield .lhfield = q ;
      mem [q + 1 ].hhfield .v.RH = rover ;
      mem [q + 1 ].hhfield .lhfield = p ;
      mem [q ].hhfield .v.RH = 268435455L ;
      mem [q ].hhfield .lhfield = t - lomemmax ;
      lomemmax = t ;
      mem [lomemmax ].hhfield .v.RH = 0 ;
      mem [lomemmax ].hhfield .lhfield = 0 ;
      rover = q ;
      goto lab20 ;
    } 
  } 
  overflow ( 315 , memmax + 1 ) ;
  lab40: mem [r ].hhfield .v.RH = 0 ;
	;
#ifdef STAT
  varused = varused + s ;
#endif /* STAT */
  Result = r ;
  lab10: ;
  return Result ;
} 
void 
zfreenode ( halfword p , halfword s ) 
{
  halfword q  ;
  mem [p ].hhfield .lhfield = s ;
  mem [p ].hhfield .v.RH = 268435455L ;
  q = mem [rover + 1 ].hhfield .lhfield ;
  mem [p + 1 ].hhfield .lhfield = q ;
  mem [p + 1 ].hhfield .v.RH = rover ;
  mem [rover + 1 ].hhfield .lhfield = p ;
  mem [q + 1 ].hhfield .v.RH = p ;
	;
#ifdef STAT
  varused = varused - s ;
#endif /* STAT */
} 
void 
zflushlist ( halfword p ) 
{
  /* 30 */ halfword q, r  ;
  if ( p >= himemmin ) {
      
    if ( p != memtop ) 
    {
      r = p ;
      do {
	  q = r ;
	r = mem [r ].hhfield .v.RH ;
	;
#ifdef STAT
	decr ( dynused ) ;
#endif /* STAT */
	if ( r < himemmin ) 
	goto lab30 ;
      } while ( ! ( r == memtop ) ) ;
      lab30: mem [q ].hhfield .v.RH = avail ;
      avail = p ;
    } 
  } 
} 
void 
zflushnodelist ( halfword p ) 
{
  halfword q  ;
  while ( p != 0 ) {
      
    q = p ;
    p = mem [p ].hhfield .v.RH ;
    if ( q < himemmin ) 
    freenode ( q , 2 ) ;
    else {
	
      mem [q ].hhfield .v.RH = avail ;
      avail = q ;
	;
#ifdef STAT
      decr ( dynused ) ;
#endif /* STAT */
    } 
  } 
} 
#ifdef TEXMF_DEBUG
void 
zcheckmem ( boolean printlocs ) 
{
  /* 31 32 */ halfword p, q, r  ;
  boolean clobbered  ;
  {register integer for_end; p = 0 ;for_end = lomemmax ; if ( p <= for_end) 
  do 
    freearr [p ]= false ;
  while ( p++ < for_end ) ;} 
  {register integer for_end; p = himemmin ;for_end = memend ; if ( p <= 
  for_end) do 
    freearr [p ]= false ;
  while ( p++ < for_end ) ;} 
  p = avail ;
  q = 0 ;
  clobbered = false ;
  while ( p != 0 ) {
      
    if ( ( p > memend ) || ( p < himemmin ) ) 
    clobbered = true ;
    else if ( freearr [p ]) 
    clobbered = true ;
    if ( clobbered ) 
    {
      printnl ( 316 ) ;
      printint ( q ) ;
      goto lab31 ;
    } 
    freearr [p ]= true ;
    q = p ;
    p = mem [q ].hhfield .v.RH ;
  } 
  lab31: ;
  p = rover ;
  q = 0 ;
  clobbered = false ;
  do {
      if ( ( p >= lomemmax ) ) 
    clobbered = true ;
    else if ( ( mem [p + 1 ].hhfield .v.RH >= lomemmax ) ) 
    clobbered = true ;
    else if ( ! ( ( mem [p ].hhfield .v.RH == 268435455L ) ) || ( mem [p ]
    .hhfield .lhfield < 2 ) || ( p + mem [p ].hhfield .lhfield > lomemmax ) 
    || ( mem [mem [p + 1 ].hhfield .v.RH + 1 ].hhfield .lhfield != p ) ) 
    clobbered = true ;
    if ( clobbered ) 
    {
      printnl ( 317 ) ;
      printint ( q ) ;
      goto lab32 ;
    } 
    {register integer for_end; q = p ;for_end = p + mem [p ].hhfield 
    .lhfield - 1 ; if ( q <= for_end) do 
      {
	if ( freearr [q ]) 
	{
	  printnl ( 318 ) ;
	  printint ( q ) ;
	  goto lab32 ;
	} 
	freearr [q ]= true ;
      } 
    while ( q++ < for_end ) ;} 
    q = p ;
    p = mem [p + 1 ].hhfield .v.RH ;
  } while ( ! ( p == rover ) ) ;
  lab32: ;
  p = 0 ;
  while ( p <= lomemmax ) {
      
    if ( ( mem [p ].hhfield .v.RH == 268435455L ) ) 
    {
      printnl ( 319 ) ;
      printint ( p ) ;
    } 
    while ( ( p <= lomemmax ) && ! freearr [p ]) incr ( p ) ;
    while ( ( p <= lomemmax ) && freearr [p ]) incr ( p ) ;
  } 
  q = 13 ;
  p = mem [q ].hhfield .v.RH ;
  while ( p != 13 ) {
      
    if ( mem [p + 1 ].hhfield .lhfield != q ) 
    {
      printnl ( 598 ) ;
      printint ( p ) ;
    } 
    p = mem [p + 1 ].hhfield .v.RH ;
    r = 19 ;
    do {
	if ( mem [mem [p ].hhfield .lhfield + 1 ].cint >= mem [r + 1 ]
      .cint ) 
      {
	printnl ( 599 ) ;
	printint ( p ) ;
      } 
      r = mem [p ].hhfield .lhfield ;
      q = p ;
      p = mem [q ].hhfield .v.RH ;
    } while ( ! ( r == 0 ) ) ;
  } 
  if ( printlocs ) 
  {
    printnl ( 320 ) ;
    {register integer for_end; p = 0 ;for_end = lomemmax ; if ( p <= 
    for_end) do 
      if ( ! freearr [p ]&& ( ( p > waslomax ) || wasfree [p ]) ) 
      {
	printchar ( 32 ) ;
	printint ( p ) ;
      } 
    while ( p++ < for_end ) ;} 
    {register integer for_end; p = himemmin ;for_end = memend ; if ( p <= 
    for_end) do 
      if ( ! freearr [p ]&& ( ( p < washimin ) || ( p > wasmemend ) || 
      wasfree [p ]) ) 
      {
	printchar ( 32 ) ;
	printint ( p ) ;
      } 
    while ( p++ < for_end ) ;} 
  } 
  {register integer for_end; p = 0 ;for_end = lomemmax ; if ( p <= for_end) 
  do 
    wasfree [p ]= freearr [p ];
  while ( p++ < for_end ) ;} 
  {register integer for_end; p = himemmin ;for_end = memend ; if ( p <= 
  for_end) do 
    wasfree [p ]= freearr [p ];
  while ( p++ < for_end ) ;} 
  wasmemend = memend ;
  waslomax = lomemmax ;
  washimin = himemmin ;
} 
#endif /* TEXMF_DEBUG */
#ifdef TEXMF_DEBUG
void 
zsearchmem ( halfword p ) 
{
  integer q  ;
  {register integer for_end; q = 0 ;for_end = lomemmax ; if ( q <= for_end) 
  do 
    {
      if ( mem [q ].hhfield .v.RH == p ) 
      {
	printnl ( 321 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
      if ( mem [q ].hhfield .lhfield == p ) 
      {
	printnl ( 322 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
    } 
  while ( q++ < for_end ) ;} 
  {register integer for_end; q = himemmin ;for_end = memend ; if ( q <= 
  for_end) do 
    {
      if ( mem [q ].hhfield .v.RH == p ) 
      {
	printnl ( 321 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
      if ( mem [q ].hhfield .lhfield == p ) 
      {
	printnl ( 322 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
    } 
  while ( q++ < for_end ) ;} 
  {register integer for_end; q = 1 ;for_end = 9769 ; if ( q <= for_end) do 
    {
      if ( eqtb [q ].v.RH == p ) 
      {
	printnl ( 458 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
    } 
  while ( q++ < for_end ) ;} 
} 
#endif /* TEXMF_DEBUG */
void 
zprintop ( quarterword c ) 
{
  if ( c <= 15 ) 
  printtype ( c ) ;
  else switch ( c ) 
  {case 30 : 
    print ( 347 ) ;
    break ;
  case 31 : 
    print ( 348 ) ;
    break ;
  case 32 : 
    print ( 349 ) ;
    break ;
  case 33 : 
    print ( 350 ) ;
    break ;
  case 34 : 
    print ( 351 ) ;
    break ;
  case 35 : 
    print ( 352 ) ;
    break ;
  case 36 : 
    print ( 353 ) ;
    break ;
  case 37 : 
    print ( 354 ) ;
    break ;
  case 38 : 
    print ( 355 ) ;
    break ;
  case 39 : 
    print ( 356 ) ;
    break ;
  case 40 : 
    print ( 357 ) ;
    break ;
  case 41 : 
    print ( 358 ) ;
    break ;
  case 42 : 
    print ( 359 ) ;
    break ;
  case 43 : 
    print ( 360 ) ;
    break ;
  case 44 : 
    print ( 361 ) ;
    break ;
  case 45 : 
    print ( 362 ) ;
    break ;
  case 46 : 
    print ( 363 ) ;
    break ;
  case 47 : 
    print ( 364 ) ;
    break ;
  case 48 : 
    print ( 365 ) ;
    break ;
  case 49 : 
    print ( 366 ) ;
    break ;
  case 50 : 
    print ( 367 ) ;
    break ;
  case 51 : 
    print ( 368 ) ;
    break ;
  case 52 : 
    print ( 369 ) ;
    break ;
  case 53 : 
    print ( 370 ) ;
    break ;
  case 54 : 
    print ( 371 ) ;
    break ;
  case 55 : 
    print ( 372 ) ;
    break ;
  case 56 : 
    print ( 373 ) ;
    break ;
  case 57 : 
    print ( 374 ) ;
    break ;
  case 58 : 
    print ( 375 ) ;
    break ;
  case 59 : 
    print ( 376 ) ;
    break ;
  case 60 : 
    print ( 377 ) ;
    break ;
  case 61 : 
    print ( 378 ) ;
    break ;
  case 62 : 
    print ( 379 ) ;
    break ;
  case 63 : 
    print ( 380 ) ;
    break ;
  case 64 : 
    print ( 381 ) ;
    break ;
  case 65 : 
    print ( 382 ) ;
    break ;
  case 66 : 
    print ( 383 ) ;
    break ;
  case 67 : 
    print ( 384 ) ;
    break ;
  case 68 : 
    print ( 385 ) ;
    break ;
  case 69 : 
    printchar ( 43 ) ;
    break ;
  case 70 : 
    printchar ( 45 ) ;
    break ;
  case 71 : 
    printchar ( 42 ) ;
    break ;
  case 72 : 
    printchar ( 47 ) ;
    break ;
  case 73 : 
    print ( 386 ) ;
    break ;
  case 74 : 
    print ( 310 ) ;
    break ;
  case 75 : 
    print ( 387 ) ;
    break ;
  case 76 : 
    print ( 388 ) ;
    break ;
  case 77 : 
    printchar ( 60 ) ;
    break ;
  case 78 : 
    print ( 389 ) ;
    break ;
  case 79 : 
    printchar ( 62 ) ;
    break ;
  case 80 : 
    print ( 390 ) ;
    break ;
  case 81 : 
    printchar ( 61 ) ;
    break ;
  case 82 : 
    print ( 391 ) ;
    break ;
  case 83 : 
    print ( 38 ) ;
    break ;
  case 84 : 
    print ( 392 ) ;
    break ;
  case 85 : 
    print ( 393 ) ;
    break ;
  case 86 : 
    print ( 394 ) ;
    break ;
  case 87 : 
    print ( 395 ) ;
    break ;
  case 88 : 
    print ( 396 ) ;
    break ;
  case 89 : 
    print ( 397 ) ;
    break ;
  case 90 : 
    print ( 398 ) ;
    break ;
  case 91 : 
    print ( 399 ) ;
    break ;
  case 92 : 
    print ( 400 ) ;
    break ;
  case 94 : 
    print ( 401 ) ;
    break ;
  case 95 : 
    print ( 402 ) ;
    break ;
  case 96 : 
    print ( 403 ) ;
    break ;
  case 97 : 
    print ( 404 ) ;
    break ;
  case 98 : 
    print ( 405 ) ;
    break ;
  case 99 : 
    print ( 406 ) ;
    break ;
  case 100 : 
    print ( 407 ) ;
    break ;
    default: 
    print ( 408 ) ;
    break ;
  } 
} 
void 
fixdateandtime ( void ) 
{
  dateandtime ( internal [17 ], internal [16 ], internal [15 ], 
  internal [14 ]) ;
  internal [17 ]= internal [17 ]* 65536L ;
  internal [16 ]= internal [16 ]* 65536L ;
  internal [15 ]= internal [15 ]* 65536L ;
  internal [14 ]= internal [14 ]* 65536L ;
} 
halfword 
zidlookup ( integer j , integer l ) 
{
  /* 40 */ register halfword Result; integer h  ;
  halfword p  ;
  halfword k  ;
  if ( l == 1 ) 
  {
    p = buffer [j ]+ 1 ;
    hash [p ].v.RH = p - 1 ;
    goto lab40 ;
  } 
  h = buffer [j ];
  {register integer for_end; k = j + 1 ;for_end = j + l - 1 ; if ( k <= 
  for_end) do 
    {
      h = h + h + buffer [k ];
      while ( h >= 7919 ) h = h - 7919 ;
    } 
  while ( k++ < for_end ) ;} 
  p = h + 257 ;
  while ( true ) {
      
    if ( hash [p ].v.RH > 0 ) {
	
      if ( ( strstart [hash [p ].v.RH + 1 ]- strstart [hash [p ].v.RH ]
      ) == l ) {
	  
	if ( streqbuf ( hash [p ].v.RH , j ) ) 
	goto lab40 ;
      } 
    } 
    if ( hash [p ].lhfield == 0 ) 
    {
      if ( hash [p ].v.RH > 0 ) 
      {
	do {
	    if ( ( hashused == 257 ) ) 
	  overflow ( 457 , 9500 ) ;
	  decr ( hashused ) ;
	} while ( ! ( hash [hashused ].v.RH == 0 ) ) ;
	hash [p ].lhfield = hashused ;
	p = hashused ;
      } 
      {
	if ( poolptr + l > maxpoolptr ) 
	{
	  if ( poolptr + l > poolsize ) 
	  overflow ( 257 , poolsize - initpoolptr ) ;
	  maxpoolptr = poolptr + l ;
	} 
      } 
      {register integer for_end; k = j ;for_end = j + l - 1 ; if ( k <= 
      for_end) do 
	{
	  strpool [poolptr ]= buffer [k ];
	  incr ( poolptr ) ;
	} 
      while ( k++ < for_end ) ;} 
      hash [p ].v.RH = makestring () ;
      strref [hash [p ].v.RH ]= 127 ;
	;
#ifdef STAT
      incr ( stcount ) ;
#endif /* STAT */
      goto lab40 ;
    } 
    p = hash [p ].lhfield ;
  } 
  lab40: Result = p ;
  return Result ;
} 
halfword 
znewnumtok ( scaled v ) 
{
  register halfword Result; halfword p  ;
  p = getnode ( 2 ) ;
  mem [p + 1 ].cint = v ;
  mem [p ].hhfield .b0 = 16 ;
  mem [p ].hhfield .b1 = 12 ;
  Result = p ;
  return Result ;
} 
void 
zflushtokenlist ( halfword p ) 
{
  halfword q  ;
  while ( p != 0 ) {
      
    q = p ;
    p = mem [p ].hhfield .v.RH ;
    if ( q >= himemmin ) 
    {
      mem [q ].hhfield .v.RH = avail ;
      avail = q ;
	;
#ifdef STAT
      decr ( dynused ) ;
#endif /* STAT */
    } 
    else {
	
      switch ( mem [q ].hhfield .b0 ) 
      {case 1 : 
      case 2 : 
      case 16 : 
	;
	break ;
      case 4 : 
	{
	  if ( strref [mem [q + 1 ].cint ]< 127 ) {
	      
	    if ( strref [mem [q + 1 ].cint ]> 1 ) 
	    decr ( strref [mem [q + 1 ].cint ]) ;
	    else flushstring ( mem [q + 1 ].cint ) ;
	  } 
	} 
	break ;
      case 3 : 
      case 5 : 
      case 7 : 
      case 12 : 
      case 10 : 
      case 6 : 
      case 9 : 
      case 8 : 
      case 11 : 
      case 14 : 
      case 13 : 
      case 17 : 
      case 18 : 
      case 19 : 
	{
	  gpointer = q ;
	  tokenrecycle () ;
	} 
	break ;
	default: 
	confusion ( 491 ) ;
	break ;
      } 
      freenode ( q , 2 ) ;
    } 
  } 
} 
void 
zdeletemacref ( halfword p ) 
{
  if ( mem [p ].hhfield .lhfield == 0 ) 
  flushtokenlist ( p ) ;
  else decr ( mem [p ].hhfield .lhfield ) ;
} 
void 
zprintcmdmod ( integer c , integer m ) 
{
  switch ( c ) 
  {case 18 : 
    print ( 462 ) ;
    break ;
  case 77 : 
    print ( 461 ) ;
    break ;
  case 59 : 
    print ( 464 ) ;
    break ;
  case 72 : 
    print ( 463 ) ;
    break ;
  case 79 : 
    print ( 460 ) ;
    break ;
  case 32 : 
    print ( 465 ) ;
    break ;
  case 81 : 
    print ( 58 ) ;
    break ;
  case 82 : 
    print ( 44 ) ;
    break ;
  case 57 : 
    print ( 466 ) ;
    break ;
  case 19 : 
    print ( 467 ) ;
    break ;
  case 60 : 
    print ( 468 ) ;
    break ;
  case 27 : 
    print ( 469 ) ;
    break ;
  case 11 : 
    print ( 470 ) ;
    break ;
  case 80 : 
    print ( 459 ) ;
    break ;
  case 84 : 
    print ( 453 ) ;
    break ;
  case 26 : 
    print ( 471 ) ;
    break ;
  case 6 : 
    print ( 472 ) ;
    break ;
  case 9 : 
    print ( 473 ) ;
    break ;
  case 70 : 
    print ( 474 ) ;
    break ;
  case 73 : 
    print ( 475 ) ;
    break ;
  case 13 : 
    print ( 476 ) ;
    break ;
  case 46 : 
    print ( 123 ) ;
    break ;
  case 63 : 
    print ( 91 ) ;
    break ;
  case 14 : 
    print ( 477 ) ;
    break ;
  case 15 : 
    print ( 478 ) ;
    break ;
  case 69 : 
    print ( 479 ) ;
    break ;
  case 28 : 
    print ( 480 ) ;
    break ;
  case 47 : 
    print ( 408 ) ;
    break ;
  case 24 : 
    print ( 481 ) ;
    break ;
  case 7 : 
    printchar ( 92 ) ;
    break ;
  case 65 : 
    print ( 125 ) ;
    break ;
  case 64 : 
    print ( 93 ) ;
    break ;
  case 12 : 
    print ( 482 ) ;
    break ;
  case 8 : 
    print ( 483 ) ;
    break ;
  case 83 : 
    print ( 59 ) ;
    break ;
  case 17 : 
    print ( 484 ) ;
    break ;
  case 78 : 
    print ( 485 ) ;
    break ;
  case 74 : 
    print ( 486 ) ;
    break ;
  case 35 : 
    print ( 487 ) ;
    break ;
  case 58 : 
    print ( 488 ) ;
    break ;
  case 71 : 
    print ( 489 ) ;
    break ;
  case 75 : 
    print ( 490 ) ;
    break ;
  case 16 : 
    if ( m <= 2 ) {
	
      if ( m == 1 ) 
      print ( 655 ) ;
      else if ( m < 1 ) 
      print ( 454 ) ;
      else print ( 656 ) ;
    } 
    else if ( m == 53 ) 
    print ( 657 ) ;
    else if ( m == 44 ) 
    print ( 658 ) ;
    else print ( 659 ) ;
    break ;
  case 4 : 
    if ( m <= 1 ) {
	
      if ( m == 1 ) 
      print ( 662 ) ;
      else print ( 455 ) ;
    } 
    else if ( m == 9770 ) 
    print ( 660 ) ;
    else print ( 661 ) ;
    break ;
  case 61 : 
    switch ( m ) 
    {case 1 : 
      print ( 664 ) ;
      break ;
    case 2 : 
      printchar ( 64 ) ;
      break ;
    case 3 : 
      print ( 665 ) ;
      break ;
      default: 
      print ( 663 ) ;
      break ;
    } 
    break ;
  case 56 : 
    if ( m >= 9770 ) {
	
      if ( m == 9770 ) 
      print ( 676 ) ;
      else if ( m == 9920 ) 
      print ( 677 ) ;
      else print ( 678 ) ;
    } 
    else if ( m < 2 ) 
    print ( 679 ) ;
    else if ( m == 2 ) 
    print ( 680 ) ;
    else print ( 681 ) ;
    break ;
  case 3 : 
    if ( m == 0 ) 
    print ( 691 ) ;
    else print ( 617 ) ;
    break ;
  case 1 : 
  case 2 : 
    switch ( m ) 
    {case 1 : 
      print ( 718 ) ;
      break ;
    case 2 : 
      print ( 452 ) ;
      break ;
    case 3 : 
      print ( 719 ) ;
      break ;
      default: 
      print ( 720 ) ;
      break ;
    } 
    break ;
  case 33 : 
  case 34 : 
  case 37 : 
  case 55 : 
  case 45 : 
  case 50 : 
  case 36 : 
  case 43 : 
  case 54 : 
  case 48 : 
  case 51 : 
  case 52 : 
    printop ( m ) ;
    break ;
  case 30 : 
    printtype ( m ) ;
    break ;
  case 85 : 
    if ( m == 0 ) 
    print ( 912 ) ;
    else print ( 913 ) ;
    break ;
  case 23 : 
    switch ( m ) 
    {case 0 : 
      print ( 273 ) ;
      break ;
    case 1 : 
      print ( 274 ) ;
      break ;
    case 2 : 
      print ( 275 ) ;
      break ;
      default: 
      print ( 919 ) ;
      break ;
    } 
    break ;
  case 21 : 
    if ( m == 0 ) 
    print ( 920 ) ;
    else print ( 921 ) ;
    break ;
  case 22 : 
    switch ( m ) 
    {case 0 : 
      print ( 935 ) ;
      break ;
    case 1 : 
      print ( 936 ) ;
      break ;
    case 2 : 
      print ( 937 ) ;
      break ;
    case 3 : 
      print ( 938 ) ;
      break ;
      default: 
      print ( 939 ) ;
      break ;
    } 
    break ;
  case 31 : 
  case 62 : 
    {
      if ( c == 31 ) 
      print ( 942 ) ;
      else print ( 943 ) ;
      print ( 944 ) ;
      slowprint ( hash [m ].v.RH ) ;
    } 
    break ;
  case 41 : 
    if ( m == 0 ) 
    print ( 945 ) ;
    else print ( 946 ) ;
    break ;
  case 10 : 
    print ( 947 ) ;
    break ;
  case 53 : 
  case 44 : 
  case 49 : 
    {
      printcmdmod ( 16 , c ) ;
      print ( 948 ) ;
      println () ;
      showtokenlist ( mem [mem [m ].hhfield .v.RH ].hhfield .v.RH , 0 , 
      1000 , 0 ) ;
    } 
    break ;
  case 5 : 
    print ( 949 ) ;
    break ;
  case 40 : 
    slowprint ( intname [m ]) ;
    break ;
  case 68 : 
    if ( m == 1 ) 
    print ( 956 ) ;
    else if ( m == 0 ) 
    print ( 957 ) ;
    else print ( 958 ) ;
    break ;
  case 66 : 
    if ( m == 6 ) 
    print ( 959 ) ;
    else print ( 960 ) ;
    break ;
  case 67 : 
    if ( m == 0 ) 
    print ( 961 ) ;
    else print ( 962 ) ;
    break ;
  case 25 : 
    if ( m < 1 ) 
    print ( 992 ) ;
    else if ( m == 1 ) 
    print ( 993 ) ;
    else print ( 994 ) ;
    break ;
  case 20 : 
    switch ( m ) 
    {case 0 : 
      print ( 1004 ) ;
      break ;
    case 1 : 
      print ( 1005 ) ;
      break ;
    case 2 : 
      print ( 1006 ) ;
      break ;
    case 3 : 
      print ( 1007 ) ;
      break ;
      default: 
      print ( 1008 ) ;
      break ;
    } 
    break ;
  case 76 : 
    switch ( m ) 
    {case 0 : 
      print ( 1026 ) ;
      break ;
    case 1 : 
      print ( 1027 ) ;
      break ;
    case 2 : 
      print ( 1029 ) ;
      break ;
    case 3 : 
      print ( 1031 ) ;
      break ;
    case 5 : 
      print ( 1028 ) ;
      break ;
    case 6 : 
      print ( 1030 ) ;
      break ;
    case 7 : 
      print ( 1032 ) ;
      break ;
    case 11 : 
      print ( 1033 ) ;
      break ;
      default: 
      print ( 1034 ) ;
      break ;
    } 
    break ;
  case 29 : 
    if ( m == 16 ) 
    print ( 1060 ) ;
    else print ( 1059 ) ;
    break ;
    default: 
    print ( 603 ) ;
    break ;
  } 
} 
void 
zshowmacro ( halfword p , integer q , integer l ) 
{
  /* 10 */ halfword r  ;
  p = mem [p ].hhfield .v.RH ;
  while ( mem [p ].hhfield .lhfield > 7 ) {
      
    r = mem [p ].hhfield .v.RH ;
    mem [p ].hhfield .v.RH = 0 ;
    showtokenlist ( p , 0 , l , 0 ) ;
    mem [p ].hhfield .v.RH = r ;
    p = r ;
    if ( l > 0 ) 
    l = l - tally ;
    else goto lab10 ;
  } 
  tally = 0 ;
  switch ( mem [p ].hhfield .lhfield ) 
  {case 0 : 
    print ( 501 ) ;
    break ;
  case 1 : 
  case 2 : 
  case 3 : 
    {
      printchar ( 60 ) ;
      printcmdmod ( 56 , mem [p ].hhfield .lhfield ) ;
      print ( 502 ) ;
    } 
    break ;
  case 4 : 
    print ( 503 ) ;
    break ;
  case 5 : 
    print ( 504 ) ;
    break ;
  case 6 : 
    print ( 505 ) ;
    break ;
  case 7 : 
    print ( 506 ) ;
    break ;
  } 
  showtokenlist ( mem [p ].hhfield .v.RH , q , l - tally , 0 ) ;
  lab10: ;
} 
void 
zinitbignode ( halfword p ) 
{
  halfword q  ;
  smallnumber s  ;
  s = bignodesize [mem [p ].hhfield .b0 ];
  q = getnode ( s ) ;
  do {
      s = s - 2 ;
    {
      if ( serialno > 2147483583L ) 
      overflow ( 588 , serialno / 64 ) ;
      mem [q + s ].hhfield .b0 = 19 ;
      serialno = serialno + 64 ;
      mem [q + s + 1 ].cint = serialno ;
    } 
    mem [q + s ].hhfield .b1 = halfp ( s ) + 5 ;
    mem [q + s ].hhfield .v.RH = 0 ;
  } while ( ! ( s == 0 ) ) ;
  mem [q ].hhfield .v.RH = p ;
  mem [p + 1 ].cint = q ;
} 
halfword 
idtransform ( void ) 
{
  register halfword Result; halfword p, q, r  ;
  p = getnode ( 2 ) ;
  mem [p ].hhfield .b0 = 13 ;
  mem [p ].hhfield .b1 = 11 ;
  mem [p + 1 ].cint = 0 ;
  initbignode ( p ) ;
  q = mem [p + 1 ].cint ;
  r = q + 12 ;
  do {
      r = r - 2 ;
    mem [r ].hhfield .b0 = 16 ;
    mem [r + 1 ].cint = 0 ;
  } while ( ! ( r == q ) ) ;
  mem [q + 5 ].cint = 65536L ;
  mem [q + 11 ].cint = 65536L ;
  Result = p ;
  return Result ;
} 
void 
znewroot ( halfword x ) 
{
  halfword p  ;
  p = getnode ( 2 ) ;
  mem [p ].hhfield .b0 = 0 ;
  mem [p ].hhfield .b1 = 0 ;
  mem [p ].hhfield .v.RH = x ;
  eqtb [x ].v.RH = p ;
} 
void 
zprintvariablename ( halfword p ) 
{
  /* 40 10 */ halfword q  ;
  halfword r  ;
  while ( mem [p ].hhfield .b1 >= 5 ) {
      
    switch ( mem [p ].hhfield .b1 ) 
    {case 5 : 
      printchar ( 120 ) ;
      break ;
    case 6 : 
      printchar ( 121 ) ;
      break ;
    case 7 : 
      print ( 509 ) ;
      break ;
    case 8 : 
      print ( 510 ) ;
      break ;
    case 9 : 
      print ( 511 ) ;
      break ;
    case 10 : 
      print ( 512 ) ;
      break ;
    case 11 : 
      {
	print ( 513 ) ;
	printint ( p - 0 ) ;
	goto lab10 ;
      } 
      break ;
    } 
    print ( 514 ) ;
    p = mem [p - 2 * ( mem [p ].hhfield .b1 - 5 ) ].hhfield .v.RH ;
  } 
  q = 0 ;
  while ( mem [p ].hhfield .b1 > 1 ) {
      
    if ( mem [p ].hhfield .b1 == 3 ) 
    {
      r = newnumtok ( mem [p + 2 ].cint ) ;
      do {
	  p = mem [p ].hhfield .v.RH ;
      } while ( ! ( mem [p ].hhfield .b1 == 4 ) ) ;
    } 
    else if ( mem [p ].hhfield .b1 == 2 ) 
    {
      p = mem [p ].hhfield .v.RH ;
      goto lab40 ;
    } 
    else {
	
      if ( mem [p ].hhfield .b1 != 4 ) 
      confusion ( 508 ) ;
      r = getavail () ;
      mem [r ].hhfield .lhfield = mem [p + 2 ].hhfield .lhfield ;
    } 
    mem [r ].hhfield .v.RH = q ;
    q = r ;
    lab40: p = mem [p + 2 ].hhfield .v.RH ;
  } 
  r = getavail () ;
  mem [r ].hhfield .lhfield = mem [p ].hhfield .v.RH ;
  mem [r ].hhfield .v.RH = q ;
  if ( mem [p ].hhfield .b1 == 1 ) 
  print ( 507 ) ;
  showtokenlist ( r , 0 , 2147483647L , tally ) ;
  flushtokenlist ( r ) ;
  lab10: ;
} 
boolean 
zinteresting ( halfword p ) 
{
  register boolean Result; smallnumber t  ;
  if ( internal [3 ]> 0 ) 
  Result = true ;
  else {
      
    t = mem [p ].hhfield .b1 ;
    if ( t >= 5 ) {
	
      if ( t != 11 ) 
      t = mem [mem [p - 2 * ( t - 5 ) ].hhfield .v.RH ].hhfield .b1 ;
    } 
    Result = ( t != 11 ) ;
  } 
  return Result ;
} 
halfword 
znewstructure ( halfword p ) 
{
  register halfword Result; halfword q, r  ;
  switch ( mem [p ].hhfield .b1 ) 
  {case 0 : 
    {
      q = mem [p ].hhfield .v.RH ;
      r = getnode ( 2 ) ;
      eqtb [q ].v.RH = r ;
    } 
    break ;
  case 3 : 
    {
      q = p ;
      do {
	  q = mem [q ].hhfield .v.RH ;
      } while ( ! ( mem [q ].hhfield .b1 == 4 ) ) ;
      q = mem [q + 2 ].hhfield .v.RH ;
      r = q + 1 ;
      do {
	  q = r ;
	r = mem [r ].hhfield .v.RH ;
      } while ( ! ( r == p ) ) ;
      r = getnode ( 3 ) ;
      mem [q ].hhfield .v.RH = r ;
      mem [r + 2 ].cint = mem [p + 2 ].cint ;
    } 
    break ;
  case 4 : 
    {
      q = mem [p + 2 ].hhfield .v.RH ;
      r = mem [q + 1 ].hhfield .lhfield ;
      do {
	  q = r ;
	r = mem [r ].hhfield .v.RH ;
      } while ( ! ( r == p ) ) ;
      r = getnode ( 3 ) ;
      mem [q ].hhfield .v.RH = r ;
      mem [r + 2 ]= mem [p + 2 ];
      if ( mem [p + 2 ].hhfield .lhfield == 0 ) 
      {
	q = mem [p + 2 ].hhfield .v.RH + 1 ;
	while ( mem [q ].hhfield .v.RH != p ) q = mem [q ].hhfield .v.RH ;
	mem [q ].hhfield .v.RH = r ;
      } 
    } 
    break ;
    default: 
    confusion ( 515 ) ;
    break ;
  } 
  mem [r ].hhfield .v.RH = mem [p ].hhfield .v.RH ;
  mem [r ].hhfield .b0 = 21 ;
  mem [r ].hhfield .b1 = mem [p ].hhfield .b1 ;
  mem [r + 1 ].hhfield .lhfield = p ;
  mem [p ].hhfield .b1 = 2 ;
  q = getnode ( 3 ) ;
  mem [p ].hhfield .v.RH = q ;
  mem [r + 1 ].hhfield .v.RH = q ;
  mem [q + 2 ].hhfield .v.RH = r ;
  mem [q ].hhfield .b0 = 0 ;
  mem [q ].hhfield .b1 = 4 ;
  mem [q ].hhfield .v.RH = 17 ;
  mem [q + 2 ].hhfield .lhfield = 0 ;
  Result = r ;
  return Result ;
} 
halfword 
zfindvariable ( halfword t ) 
{
  /* 10 */ register halfword Result; halfword p, q, r, s  ;
  halfword pp, qq, rr, ss  ;
  integer n  ;
  memoryword saveword  ;
  p = mem [t ].hhfield .lhfield ;
  t = mem [t ].hhfield .v.RH ;
  if ( eqtb [p ].lhfield % 86 != 41 ) 
  {
    Result = 0 ;
    goto lab10 ;
  } 
  if ( eqtb [p ].v.RH == 0 ) 
  newroot ( p ) ;
  p = eqtb [p ].v.RH ;
  pp = p ;
  while ( t != 0 ) {
      
    if ( mem [pp ].hhfield .b0 != 21 ) 
    {
      if ( mem [pp ].hhfield .b0 > 21 ) 
      {
	Result = 0 ;
	goto lab10 ;
      } 
      ss = newstructure ( pp ) ;
      if ( p == pp ) 
      p = ss ;
      pp = ss ;
    } 
    if ( mem [p ].hhfield .b0 != 21 ) 
    p = newstructure ( p ) ;
    if ( t < himemmin ) 
    {
      n = mem [t + 1 ].cint ;
      pp = mem [mem [pp + 1 ].hhfield .lhfield ].hhfield .v.RH ;
      q = mem [mem [p + 1 ].hhfield .lhfield ].hhfield .v.RH ;
      saveword = mem [q + 2 ];
      mem [q + 2 ].cint = 2147483647L ;
      s = p + 1 ;
      do {
	  r = s ;
	s = mem [s ].hhfield .v.RH ;
      } while ( ! ( n <= mem [s + 2 ].cint ) ) ;
      if ( n == mem [s + 2 ].cint ) 
      p = s ;
      else {
	  
	p = getnode ( 3 ) ;
	mem [r ].hhfield .v.RH = p ;
	mem [p ].hhfield .v.RH = s ;
	mem [p + 2 ].cint = n ;
	mem [p ].hhfield .b1 = 3 ;
	mem [p ].hhfield .b0 = 0 ;
      } 
      mem [q + 2 ]= saveword ;
    } 
    else {
	
      n = mem [t ].hhfield .lhfield ;
      ss = mem [pp + 1 ].hhfield .lhfield ;
      do {
	  rr = ss ;
	ss = mem [ss ].hhfield .v.RH ;
      } while ( ! ( n <= mem [ss + 2 ].hhfield .lhfield ) ) ;
      if ( n < mem [ss + 2 ].hhfield .lhfield ) 
      {
	qq = getnode ( 3 ) ;
	mem [rr ].hhfield .v.RH = qq ;
	mem [qq ].hhfield .v.RH = ss ;
	mem [qq + 2 ].hhfield .lhfield = n ;
	mem [qq ].hhfield .b1 = 4 ;
	mem [qq ].hhfield .b0 = 0 ;
	mem [qq + 2 ].hhfield .v.RH = pp ;
	ss = qq ;
      } 
      if ( p == pp ) 
      {
	p = ss ;
	pp = ss ;
      } 
      else {
	  
	pp = ss ;
	s = mem [p + 1 ].hhfield .lhfield ;
	do {
	    r = s ;
	  s = mem [s ].hhfield .v.RH ;
	} while ( ! ( n <= mem [s + 2 ].hhfield .lhfield ) ) ;
	if ( n == mem [s + 2 ].hhfield .lhfield ) 
	p = s ;
	else {
	    
	  q = getnode ( 3 ) ;
	  mem [r ].hhfield .v.RH = q ;
	  mem [q ].hhfield .v.RH = s ;
	  mem [q + 2 ].hhfield .lhfield = n ;
	  mem [q ].hhfield .b1 = 4 ;
	  mem [q ].hhfield .b0 = 0 ;
	  mem [q + 2 ].hhfield .v.RH = p ;
	  p = q ;
	} 
      } 
    } 
    t = mem [t ].hhfield .v.RH ;
  } 
  if ( mem [pp ].hhfield .b0 >= 21 ) {
      
    if ( mem [pp ].hhfield .b0 == 21 ) 
    pp = mem [pp + 1 ].hhfield .lhfield ;
    else {
	
      Result = 0 ;
      goto lab10 ;
    } 
  } 
  if ( mem [p ].hhfield .b0 == 21 ) 
  p = mem [p + 1 ].hhfield .lhfield ;
  if ( mem [p ].hhfield .b0 == 0 ) 
  {
    if ( mem [pp ].hhfield .b0 == 0 ) 
    {
      mem [pp ].hhfield .b0 = 15 ;
      mem [pp + 1 ].cint = 0 ;
    } 
    mem [p ].hhfield .b0 = mem [pp ].hhfield .b0 ;
    mem [p + 1 ].cint = 0 ;
  } 
  Result = p ;
  lab10: ;
  return Result ;
} 
void 
zprintpath ( halfword h , strnumber s , boolean nuline ) 
{
  /* 30 31 */ halfword p, q  ;
  printdiagnostic ( 517 , s , nuline ) ;
  println () ;
  p = h ;
  do {
      q = mem [p ].hhfield .v.RH ;
    if ( ( p == 0 ) || ( q == 0 ) ) 
    {
      printnl ( 259 ) ;
      goto lab30 ;
    } 
    printtwo ( mem [p + 1 ].cint , mem [p + 2 ].cint ) ;
    switch ( mem [p ].hhfield .b1 ) 
    {case 0 : 
      {
	if ( mem [p ].hhfield .b0 == 4 ) 
	print ( 518 ) ;
	if ( ( mem [q ].hhfield .b0 != 0 ) || ( q != h ) ) 
	q = 0 ;
	goto lab31 ;
      } 
      break ;
    case 1 : 
      {
	print ( 524 ) ;
	printtwo ( mem [p + 5 ].cint , mem [p + 6 ].cint ) ;
	print ( 523 ) ;
	if ( mem [q ].hhfield .b0 != 1 ) 
	print ( 525 ) ;
	else printtwo ( mem [q + 3 ].cint , mem [q + 4 ].cint ) ;
	goto lab31 ;
      } 
      break ;
    case 4 : 
      if ( ( mem [p ].hhfield .b0 != 1 ) && ( mem [p ].hhfield .b0 != 4 ) 
      ) 
      print ( 518 ) ;
      break ;
    case 3 : 
    case 2 : 
      {
	if ( mem [p ].hhfield .b0 == 4 ) 
	print ( 525 ) ;
	if ( mem [p ].hhfield .b1 == 3 ) 
	{
	  print ( 521 ) ;
	  printscaled ( mem [p + 5 ].cint ) ;
	} 
	else {
	    
	  nsincos ( mem [p + 5 ].cint ) ;
	  printchar ( 123 ) ;
	  printscaled ( ncos ) ;
	  printchar ( 44 ) ;
	  printscaled ( nsin ) ;
	} 
	printchar ( 125 ) ;
      } 
      break ;
      default: 
      print ( 259 ) ;
      break ;
    } 
    if ( mem [q ].hhfield .b0 <= 1 ) 
    print ( 519 ) ;
    else if ( ( mem [p + 6 ].cint != 65536L ) || ( mem [q + 4 ].cint != 
    65536L ) ) 
    {
      print ( 522 ) ;
      if ( mem [p + 6 ].cint < 0 ) 
      print ( 464 ) ;
      printscaled ( abs ( mem [p + 6 ].cint ) ) ;
      if ( mem [p + 6 ].cint != mem [q + 4 ].cint ) 
      {
	print ( 523 ) ;
	if ( mem [q + 4 ].cint < 0 ) 
	print ( 464 ) ;
	printscaled ( abs ( mem [q + 4 ].cint ) ) ;
      } 
    } 
    lab31: ;
    p = q ;
    if ( ( p != h ) || ( mem [h ].hhfield .b0 != 0 ) ) 
    {
      printnl ( 520 ) ;
      if ( mem [p ].hhfield .b0 == 2 ) 
      {
	nsincos ( mem [p + 3 ].cint ) ;
	printchar ( 123 ) ;
	printscaled ( ncos ) ;
	printchar ( 44 ) ;
	printscaled ( nsin ) ;
	printchar ( 125 ) ;
      } 
      else if ( mem [p ].hhfield .b0 == 3 ) 
      {
	print ( 521 ) ;
	printscaled ( mem [p + 3 ].cint ) ;
	printchar ( 125 ) ;
      } 
    } 
  } while ( ! ( p == h ) ) ;
  if ( mem [h ].hhfield .b0 != 0 ) 
  print ( 385 ) ;
  lab30: enddiagnostic ( true ) ;
} 
void 
zprintweight ( halfword q , integer xoff ) 
{
  integer w, m  ;
  integer d  ;
  d = mem [q ].hhfield .lhfield ;
  w = d % 8 ;
  m = ( d / 8 ) - mem [curedges + 3 ].hhfield .lhfield ;
  if ( fileoffset > maxprintline - 9 ) 
  printnl ( 32 ) ;
  else printchar ( 32 ) ;
  printint ( m + xoff ) ;
  while ( w > 4 ) {
      
    printchar ( 43 ) ;
    decr ( w ) ;
  } 
  while ( w < 4 ) {
      
    printchar ( 45 ) ;
    incr ( w ) ;
  } 
} 
void 
zprintedges ( strnumber s , boolean nuline , integer xoff , integer yoff ) 
{
  halfword p, q, r  ;
  integer n  ;
  printdiagnostic ( 532 , s , nuline ) ;
  p = mem [curedges ].hhfield .lhfield ;
  n = mem [curedges + 1 ].hhfield .v.RH - 4096 ;
  while ( p != curedges ) {
      
    q = mem [p + 1 ].hhfield .lhfield ;
    r = mem [p + 1 ].hhfield .v.RH ;
    if ( ( q > 1 ) || ( r != memtop ) ) 
    {
      printnl ( 533 ) ;
      printint ( n + yoff ) ;
      printchar ( 58 ) ;
      while ( q > 1 ) {
	  
	printweight ( q , xoff ) ;
	q = mem [q ].hhfield .v.RH ;
      } 
      print ( 534 ) ;
      while ( r != memtop ) {
	  
	printweight ( r , xoff ) ;
	r = mem [r ].hhfield .v.RH ;
      } 
    } 
    p = mem [p ].hhfield .lhfield ;
    decr ( n ) ;
  } 
  enddiagnostic ( true ) ;
} 
void 
zunskew ( scaled x , scaled y , smallnumber octant ) 
{
  switch ( octant ) 
  {case 1 : 
    {
      curx = x + y ;
      cury = y ;
    } 
    break ;
  case 5 : 
    {
      curx = y ;
      cury = x + y ;
    } 
    break ;
  case 6 : 
    {
      curx = - (integer) y ;
      cury = x + y ;
    } 
    break ;
  case 2 : 
    {
      curx = - (integer) x - y ;
      cury = y ;
    } 
    break ;
  case 4 : 
    {
      curx = - (integer) x - y ;
      cury = - (integer) y ;
    } 
    break ;
  case 8 : 
    {
      curx = - (integer) y ;
      cury = - (integer) x - y ;
    } 
    break ;
  case 7 : 
    {
      curx = y ;
      cury = - (integer) x - y ;
    } 
    break ;
  case 3 : 
    {
      curx = x + y ;
      cury = - (integer) y ;
    } 
    break ;
  } 
} 
void 
zprintpen ( halfword p , strnumber s , boolean nuline ) 
{
  boolean nothingprinted  ;
  unsigned char k  ;
  halfword h  ;
  integer m, n  ;
  halfword w, ww  ;
  printdiagnostic ( 569 , s , nuline ) ;
  nothingprinted = true ;
  println () ;
  {register integer for_end; k = 1 ;for_end = 8 ; if ( k <= for_end) do 
    {
      octant = octantcode [k ];
      h = p + octant ;
      n = mem [h ].hhfield .lhfield ;
      w = mem [h ].hhfield .v.RH ;
      if ( ! odd ( k ) ) 
      w = mem [w ].hhfield .lhfield ;
      {register integer for_end; m = 1 ;for_end = n + 1 ; if ( m <= for_end) 
      do 
	{
	  if ( odd ( k ) ) 
	  ww = mem [w ].hhfield .v.RH ;
	  else ww = mem [w ].hhfield .lhfield ;
	  if ( ( mem [ww + 1 ].cint != mem [w + 1 ].cint ) || ( mem [ww + 
	  2 ].cint != mem [w + 2 ].cint ) ) 
	  {
	    if ( nothingprinted ) 
	    nothingprinted = false ;
	    else printnl ( 571 ) ;
	    unskew ( mem [ww + 1 ].cint , mem [ww + 2 ].cint , octant ) ;
	    printtwo ( curx , cury ) ;
	  } 
	  w = ww ;
	} 
      while ( m++ < for_end ) ;} 
    } 
  while ( k++ < for_end ) ;} 
  if ( nothingprinted ) 
  {
    w = mem [p + 1 ].hhfield .v.RH ;
    printtwo ( mem [w + 1 ].cint + mem [w + 2 ].cint , mem [w + 2 ].cint 
    ) ;
  } 
  printnl ( 570 ) ;
  enddiagnostic ( true ) ;
} 
void 
zprintdependency ( halfword p , smallnumber t ) 
{
  /* 10 */ integer v  ;
  halfword pp, q  ;
  pp = p ;
  while ( true ) {
      
    v = abs ( mem [p + 1 ].cint ) ;
    q = mem [p ].hhfield .lhfield ;
    if ( q == 0 ) 
    {
      if ( ( v != 0 ) || ( p == pp ) ) 
      {
	if ( mem [p + 1 ].cint > 0 ) {
	    
	  if ( p != pp ) 
	  printchar ( 43 ) ;
	} 
	printscaled ( mem [p + 1 ].cint ) ;
      } 
      goto lab10 ;
    } 
    if ( mem [p + 1 ].cint < 0 ) 
    printchar ( 45 ) ;
    else if ( p != pp ) 
    printchar ( 43 ) ;
    if ( t == 17 ) 
    v = roundfraction ( v ) ;
    if ( v != 65536L ) 
    printscaled ( v ) ;
    if ( mem [q ].hhfield .b0 != 19 ) 
    confusion ( 589 ) ;
    printvariablename ( q ) ;
    v = mem [q + 1 ].cint % 64 ;
    while ( v > 0 ) {
	
      print ( 590 ) ;
      v = v - 2 ;
    } 
    p = mem [p ].hhfield .v.RH ;
  } 
  lab10: ;
} 
void 
zprintdp ( smallnumber t , halfword p , smallnumber verbosity ) 
{
  halfword q  ;
  q = mem [p ].hhfield .v.RH ;
  if ( ( mem [q ].hhfield .lhfield == 0 ) || ( verbosity > 0 ) ) 
  printdependency ( p , t ) ;
  else print ( 764 ) ;
} 
halfword 
stashcurexp ( void ) 
{
  register halfword Result; halfword p  ;
  switch ( curtype ) 
  {case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
  case 13 : 
  case 14 : 
  case 17 : 
  case 18 : 
  case 19 : 
    p = curexp ;
    break ;
    default: 
    {
      p = getnode ( 2 ) ;
      mem [p ].hhfield .b1 = 11 ;
      mem [p ].hhfield .b0 = curtype ;
      mem [p + 1 ].cint = curexp ;
    } 
    break ;
  } 
  curtype = 1 ;
  mem [p ].hhfield .v.RH = 1 ;
  Result = p ;
  return Result ;
} 
void 
zunstashcurexp ( halfword p ) 
{
  curtype = mem [p ].hhfield .b0 ;
  switch ( curtype ) 
  {case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
  case 13 : 
  case 14 : 
  case 17 : 
  case 18 : 
  case 19 : 
    curexp = p ;
    break ;
    default: 
    {
      curexp = mem [p + 1 ].cint ;
      freenode ( p , 2 ) ;
    } 
    break ;
  } 
} 
void 
zprintexp ( halfword p , smallnumber verbosity ) 
{
  boolean restorecurexp  ;
  smallnumber t  ;
  integer v  ;
  halfword q  ;
  if ( p != 0 ) 
  restorecurexp = false ;
  else {
      
    p = stashcurexp () ;
    restorecurexp = true ;
  } 
  t = mem [p ].hhfield .b0 ;
  if ( t < 17 ) 
  v = mem [p + 1 ].cint ;
  else if ( t < 19 ) 
  v = mem [p + 1 ].hhfield .v.RH ;
  switch ( t ) 
  {case 1 : 
    print ( 323 ) ;
    break ;
  case 2 : 
    if ( v == 30 ) 
    print ( 347 ) ;
    else print ( 348 ) ;
    break ;
  case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
  case 15 : 
    {
      printtype ( t ) ;
      if ( v != 0 ) 
      {
	printchar ( 32 ) ;
	while ( ( mem [v ].hhfield .b1 == 11 ) && ( v != p ) ) v = mem [v + 
	1 ].cint ;
	printvariablename ( v ) ;
      } 
    } 
    break ;
  case 4 : 
    {
      printchar ( 34 ) ;
      slowprint ( v ) ;
      printchar ( 34 ) ;
    } 
    break ;
  case 6 : 
  case 8 : 
  case 9 : 
  case 11 : 
    if ( verbosity <= 1 ) 
    printtype ( t ) ;
    else {
	
      if ( selector == 3 ) {
	  
	if ( internal [13 ]<= 0 ) 
	{
	  selector = 1 ;
	  printtype ( t ) ;
	  print ( 762 ) ;
	  selector = 3 ;
	} 
      } 
      switch ( t ) 
      {case 6 : 
	printpen ( v , 261 , false ) ;
	break ;
      case 8 : 
	printpath ( v , 763 , false ) ;
	break ;
      case 9 : 
	printpath ( v , 261 , false ) ;
	break ;
      case 11 : 
	{
	  curedges = v ;
	  printedges ( 261 , false , 0 , 0 ) ;
	} 
	break ;
      } 
    } 
    break ;
  case 13 : 
  case 14 : 
    if ( v == 0 ) 
    printtype ( t ) ;
    else {
	
      printchar ( 40 ) ;
      q = v + bignodesize [t ];
      do {
	  if ( mem [v ].hhfield .b0 == 16 ) 
	printscaled ( mem [v + 1 ].cint ) ;
	else if ( mem [v ].hhfield .b0 == 19 ) 
	printvariablename ( v ) ;
	else printdp ( mem [v ].hhfield .b0 , mem [v + 1 ].hhfield .v.RH , 
	verbosity ) ;
	v = v + 2 ;
	if ( v != q ) 
	printchar ( 44 ) ;
      } while ( ! ( v == q ) ) ;
      printchar ( 41 ) ;
    } 
    break ;
  case 16 : 
    printscaled ( v ) ;
    break ;
  case 17 : 
  case 18 : 
    printdp ( t , v , verbosity ) ;
    break ;
  case 19 : 
    printvariablename ( p ) ;
    break ;
    default: 
    confusion ( 761 ) ;
    break ;
  } 
  if ( restorecurexp ) 
  unstashcurexp ( p ) ;
} 
void 
zdisperr ( halfword p , strnumber s ) 
{
  if ( interaction == 3 ) 
  ;
  printnl ( 765 ) ;
  printexp ( p , 1 ) ;
  if ( s != 261 ) 
  {
    printnl ( 263 ) ;
    print ( s ) ;
  } 
} 
halfword 
zpplusfq ( halfword p , integer f , halfword q , smallnumber t , smallnumber 
tt ) 
{
  /* 30 */ register halfword Result; halfword pp, qq  ;
  halfword r, s  ;
  integer threshold  ;
  integer v  ;
  if ( t == 17 ) 
  threshold = 2685 ;
  else threshold = 8 ;
  r = memtop - 1 ;
  pp = mem [p ].hhfield .lhfield ;
  qq = mem [q ].hhfield .lhfield ;
  while ( true ) if ( pp == qq ) {
      
    if ( pp == 0 ) 
    goto lab30 ;
    else {
	
      if ( tt == 17 ) 
      v = mem [p + 1 ].cint + takefraction ( f , mem [q + 1 ].cint ) ;
      else v = mem [p + 1 ].cint + takescaled ( f , mem [q + 1 ].cint ) ;
      mem [p + 1 ].cint = v ;
      s = p ;
      p = mem [p ].hhfield .v.RH ;
      if ( abs ( v ) < threshold ) 
      freenode ( s , 2 ) ;
      else {
	  
	if ( abs ( v ) >= 626349397L ) {
	    
	  if ( watchcoefs ) 
	  {
	    mem [qq ].hhfield .b0 = 0 ;
	    fixneeded = true ;
	  } 
	} 
	mem [r ].hhfield .v.RH = s ;
	r = s ;
      } 
      pp = mem [p ].hhfield .lhfield ;
      q = mem [q ].hhfield .v.RH ;
      qq = mem [q ].hhfield .lhfield ;
    } 
  } 
  else if ( mem [pp + 1 ].cint < mem [qq + 1 ].cint ) 
  {
    if ( tt == 17 ) 
    v = takefraction ( f , mem [q + 1 ].cint ) ;
    else v = takescaled ( f , mem [q + 1 ].cint ) ;
    if ( abs ( v ) > halfp ( threshold ) ) 
    {
      s = getnode ( 2 ) ;
      mem [s ].hhfield .lhfield = qq ;
      mem [s + 1 ].cint = v ;
      if ( abs ( v ) >= 626349397L ) {
	  
	if ( watchcoefs ) 
	{
	  mem [qq ].hhfield .b0 = 0 ;
	  fixneeded = true ;
	} 
      } 
      mem [r ].hhfield .v.RH = s ;
      r = s ;
    } 
    q = mem [q ].hhfield .v.RH ;
    qq = mem [q ].hhfield .lhfield ;
  } 
  else {
      
    mem [r ].hhfield .v.RH = p ;
    r = p ;
    p = mem [p ].hhfield .v.RH ;
    pp = mem [p ].hhfield .lhfield ;
  } 
  lab30: if ( t == 17 ) 
  mem [p + 1 ].cint = slowadd ( mem [p + 1 ].cint , takefraction ( mem [q 
  + 1 ].cint , f ) ) ;
  else mem [p + 1 ].cint = slowadd ( mem [p + 1 ].cint , takescaled ( mem 
  [q + 1 ].cint , f ) ) ;
  mem [r ].hhfield .v.RH = p ;
  depfinal = p ;
  Result = mem [memtop - 1 ].hhfield .v.RH ;
  return Result ;
} 
halfword 
zpoverv ( halfword p , scaled v , smallnumber t0 , smallnumber t1 ) 
{
  register halfword Result; halfword r, s  ;
  integer w  ;
  integer threshold  ;
  boolean scalingdown  ;
  if ( t0 != t1 ) 
  scalingdown = true ;
  else scalingdown = false ;
  if ( t1 == 17 ) 
  threshold = 1342 ;
  else threshold = 4 ;
  r = memtop - 1 ;
  while ( mem [p ].hhfield .lhfield != 0 ) {
      
    if ( scalingdown ) {
	
      if ( abs ( v ) < 524288L ) 
      w = makescaled ( mem [p + 1 ].cint , v * 4096 ) ;
      else w = makescaled ( roundfraction ( mem [p + 1 ].cint ) , v ) ;
    } 
    else w = makescaled ( mem [p + 1 ].cint , v ) ;
    if ( abs ( w ) <= threshold ) 
    {
      s = mem [p ].hhfield .v.RH ;
      freenode ( p , 2 ) ;
      p = s ;
    } 
    else {
	
      if ( abs ( w ) >= 626349397L ) 
      {
	fixneeded = true ;
	mem [mem [p ].hhfield .lhfield ].hhfield .b0 = 0 ;
      } 
      mem [r ].hhfield .v.RH = p ;
      r = p ;
      mem [p + 1 ].cint = w ;
      p = mem [p ].hhfield .v.RH ;
    } 
  } 
  mem [r ].hhfield .v.RH = p ;
  mem [p + 1 ].cint = makescaled ( mem [p + 1 ].cint , v ) ;
  Result = mem [memtop - 1 ].hhfield .v.RH ;
  return Result ;
} 
void 
zvaltoobig ( scaled x ) 
{
  if ( internal [40 ]> 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 591 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 591 ) ;
      } 
    } 
    printscaled ( x ) ;
    printchar ( 41 ) ;
    {
      helpptr = 4 ;
      helpline [3 ]= 592 ;
      helpline [2 ]= 593 ;
      helpline [1 ]= 594 ;
      helpline [0 ]= 595 ;
    } 
    error () ;
  } 
} 
void 
zmakeknown ( halfword p , halfword q ) 
{
  unsigned char t  ;
  mem [mem [q ].hhfield .v.RH + 1 ].hhfield .lhfield = mem [p + 1 ]
  .hhfield .lhfield ;
  mem [mem [p + 1 ].hhfield .lhfield ].hhfield .v.RH = mem [q ].hhfield 
  .v.RH ;
  t = mem [p ].hhfield .b0 ;
  mem [p ].hhfield .b0 = 16 ;
  mem [p + 1 ].cint = mem [q + 1 ].cint ;
  freenode ( q , 2 ) ;
  if ( abs ( mem [p + 1 ].cint ) >= 268435456L ) 
  valtoobig ( mem [p + 1 ].cint ) ;
  if ( internal [2 ]> 0 ) {
      
    if ( interesting ( p ) ) 
    {
      begindiagnostic () ;
      printnl ( 596 ) ;
      printvariablename ( p ) ;
      printchar ( 61 ) ;
      printscaled ( mem [p + 1 ].cint ) ;
      enddiagnostic ( false ) ;
    } 
  } 
  if ( curexp == p ) {
      
    if ( curtype == t ) 
    {
      curtype = 16 ;
      curexp = mem [p + 1 ].cint ;
      freenode ( p , 2 ) ;
    } 
  } 
} 
void 
fixdependencies ( void ) 
{
  /* 30 */ halfword p, q, r, s, t  ;
  halfword x  ;
  r = mem [13 ].hhfield .v.RH ;
  s = 0 ;
  while ( r != 13 ) {
      
    t = r ;
    r = t + 1 ;
    while ( true ) {
	
      q = mem [r ].hhfield .v.RH ;
      x = mem [q ].hhfield .lhfield ;
      if ( x == 0 ) 
      goto lab30 ;
      if ( mem [x ].hhfield .b0 <= 1 ) 
      {
	if ( mem [x ].hhfield .b0 < 1 ) 
	{
	  p = getavail () ;
	  mem [p ].hhfield .v.RH = s ;
	  s = p ;
	  mem [s ].hhfield .lhfield = x ;
	  mem [x ].hhfield .b0 = 1 ;
	} 
	mem [q + 1 ].cint = mem [q + 1 ].cint / 4 ;
	if ( mem [q + 1 ].cint == 0 ) 
	{
	  mem [r ].hhfield .v.RH = mem [q ].hhfield .v.RH ;
	  freenode ( q , 2 ) ;
	  q = r ;
	} 
      } 
      r = q ;
    } 
    lab30: ;
    r = mem [q ].hhfield .v.RH ;
    if ( q == mem [t + 1 ].hhfield .v.RH ) 
    makeknown ( t , q ) ;
  } 
  while ( s != 0 ) {
      
    p = mem [s ].hhfield .v.RH ;
    x = mem [s ].hhfield .lhfield ;
    {
      mem [s ].hhfield .v.RH = avail ;
      avail = s ;
	;
#ifdef STAT
      decr ( dynused ) ;
#endif /* STAT */
    } 
    s = p ;
    mem [x ].hhfield .b0 = 19 ;
    mem [x + 1 ].cint = mem [x + 1 ].cint + 2 ;
  } 
  fixneeded = false ;
} 
void 
ztossknotlist ( halfword p ) 
{
  halfword q  ;
  halfword r  ;
  q = p ;
  do {
      r = mem [q ].hhfield .v.RH ;
    freenode ( q , 7 ) ;
    q = r ;
  } while ( ! ( q == p ) ) ;
} 
void 
ztossedges ( halfword h ) 
{
  halfword p, q  ;
  q = mem [h ].hhfield .v.RH ;
  while ( q != h ) {
      
    flushlist ( mem [q + 1 ].hhfield .v.RH ) ;
    if ( mem [q + 1 ].hhfield .lhfield > 1 ) 
    flushlist ( mem [q + 1 ].hhfield .lhfield ) ;
    p = q ;
    q = mem [q ].hhfield .v.RH ;
    freenode ( p , 2 ) ;
  } 
  freenode ( h , 6 ) ;
} 
void 
ztosspen ( halfword p ) 
{
  unsigned char k  ;
  halfword w, ww  ;
  if ( p != 3 ) 
  {
    {register integer for_end; k = 1 ;for_end = 8 ; if ( k <= for_end) do 
      {
	w = mem [p + k ].hhfield .v.RH ;
	do {
	    ww = mem [w ].hhfield .v.RH ;
	  freenode ( w , 3 ) ;
	  w = ww ;
	} while ( ! ( w == mem [p + k ].hhfield .v.RH ) ) ;
      } 
    while ( k++ < for_end ) ;} 
    freenode ( p , 10 ) ;
  } 
} 
void 
zringdelete ( halfword p ) 
{
  halfword q  ;
  q = mem [p + 1 ].cint ;
  if ( q != 0 ) {
      
    if ( q != p ) 
    {
      while ( mem [q + 1 ].cint != p ) q = mem [q + 1 ].cint ;
      mem [q + 1 ].cint = mem [p + 1 ].cint ;
    } 
  } 
} 
void 
zrecyclevalue ( halfword p ) 
{
  /* 30 */ smallnumber t  ;
  integer v  ;
  integer vv  ;
  halfword q, r, s, pp  ;
  t = mem [p ].hhfield .b0 ;
  if ( t < 17 ) 
  v = mem [p + 1 ].cint ;
  switch ( t ) 
  {case 0 : 
  case 1 : 
  case 2 : 
  case 16 : 
  case 15 : 
    ;
    break ;
  case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
    ringdelete ( p ) ;
    break ;
  case 4 : 
    {
      if ( strref [v ]< 127 ) {
	  
	if ( strref [v ]> 1 ) 
	decr ( strref [v ]) ;
	else flushstring ( v ) ;
      } 
    } 
    break ;
  case 6 : 
    if ( mem [v ].hhfield .lhfield == 0 ) 
    tosspen ( v ) ;
    else decr ( mem [v ].hhfield .lhfield ) ;
    break ;
  case 9 : 
  case 8 : 
    tossknotlist ( v ) ;
    break ;
  case 11 : 
    tossedges ( v ) ;
    break ;
  case 14 : 
  case 13 : 
    if ( v != 0 ) 
    {
      q = v + bignodesize [t ];
      do {
	  q = q - 2 ;
	recyclevalue ( q ) ;
      } while ( ! ( q == v ) ) ;
      freenode ( v , bignodesize [t ]) ;
    } 
    break ;
  case 17 : 
  case 18 : 
    {
      q = mem [p + 1 ].hhfield .v.RH ;
      while ( mem [q ].hhfield .lhfield != 0 ) q = mem [q ].hhfield .v.RH 
      ;
      mem [mem [p + 1 ].hhfield .lhfield ].hhfield .v.RH = mem [q ]
      .hhfield .v.RH ;
      mem [mem [q ].hhfield .v.RH + 1 ].hhfield .lhfield = mem [p + 1 ]
      .hhfield .lhfield ;
      mem [q ].hhfield .v.RH = 0 ;
      flushnodelist ( mem [p + 1 ].hhfield .v.RH ) ;
    } 
    break ;
  case 19 : 
    {
      maxc [17 ]= 0 ;
      maxc [18 ]= 0 ;
      maxlink [17 ]= 0 ;
      maxlink [18 ]= 0 ;
      q = mem [13 ].hhfield .v.RH ;
      while ( q != 13 ) {
	  
	s = q + 1 ;
	while ( true ) {
	    
	  r = mem [s ].hhfield .v.RH ;
	  if ( mem [r ].hhfield .lhfield == 0 ) 
	  goto lab30 ;
	  if ( mem [r ].hhfield .lhfield != p ) 
	  s = r ;
	  else {
	      
	    t = mem [q ].hhfield .b0 ;
	    mem [s ].hhfield .v.RH = mem [r ].hhfield .v.RH ;
	    mem [r ].hhfield .lhfield = q ;
	    if ( abs ( mem [r + 1 ].cint ) > maxc [t ]) 
	    {
	      if ( maxc [t ]> 0 ) 
	      {
		mem [maxptr [t ]].hhfield .v.RH = maxlink [t ];
		maxlink [t ]= maxptr [t ];
	      } 
	      maxc [t ]= abs ( mem [r + 1 ].cint ) ;
	      maxptr [t ]= r ;
	    } 
	    else {
		
	      mem [r ].hhfield .v.RH = maxlink [t ];
	      maxlink [t ]= r ;
	    } 
	  } 
	} 
	lab30: q = mem [r ].hhfield .v.RH ;
      } 
      if ( ( maxc [17 ]> 0 ) || ( maxc [18 ]> 0 ) ) 
      {
	if ( ( maxc [17 ]/ 4096 >= maxc [18 ]) ) 
	t = 17 ;
	else t = 18 ;
	s = maxptr [t ];
	pp = mem [s ].hhfield .lhfield ;
	v = mem [s + 1 ].cint ;
	if ( t == 17 ) 
	mem [s + 1 ].cint = -268435456L ;
	else mem [s + 1 ].cint = -65536L ;
	r = mem [pp + 1 ].hhfield .v.RH ;
	mem [s ].hhfield .v.RH = r ;
	while ( mem [r ].hhfield .lhfield != 0 ) r = mem [r ].hhfield 
	.v.RH ;
	q = mem [r ].hhfield .v.RH ;
	mem [r ].hhfield .v.RH = 0 ;
	mem [q + 1 ].hhfield .lhfield = mem [pp + 1 ].hhfield .lhfield ;
	mem [mem [pp + 1 ].hhfield .lhfield ].hhfield .v.RH = q ;
	{
	  if ( serialno > 2147483583L ) 
	  overflow ( 588 , serialno / 64 ) ;
	  mem [pp ].hhfield .b0 = 19 ;
	  serialno = serialno + 64 ;
	  mem [pp + 1 ].cint = serialno ;
	} 
	if ( curexp == pp ) {
	    
	  if ( curtype == t ) 
	  curtype = 19 ;
	} 
	if ( internal [2 ]> 0 ) {
	    
	  if ( interesting ( p ) ) 
	  {
	    begindiagnostic () ;
	    printnl ( 767 ) ;
	    if ( v > 0 ) 
	    printchar ( 45 ) ;
	    if ( t == 17 ) 
	    vv = roundfraction ( maxc [17 ]) ;
	    else vv = maxc [18 ];
	    if ( vv != 65536L ) 
	    printscaled ( vv ) ;
	    printvariablename ( p ) ;
	    while ( mem [p + 1 ].cint % 64 > 0 ) {
		
	      print ( 590 ) ;
	      mem [p + 1 ].cint = mem [p + 1 ].cint - 2 ;
	    } 
	    if ( t == 17 ) 
	    printchar ( 61 ) ;
	    else print ( 768 ) ;
	    printdependency ( s , t ) ;
	    enddiagnostic ( false ) ;
	  } 
	} 
	t = 35 - t ;
	if ( maxc [t ]> 0 ) 
	{
	  mem [maxptr [t ]].hhfield .v.RH = maxlink [t ];
	  maxlink [t ]= maxptr [t ];
	} 
	if ( t != 17 ) 
	{register integer for_end; t = 17 ;for_end = 18 ; if ( t <= for_end) 
	do 
	  {
	    r = maxlink [t ];
	    while ( r != 0 ) {
		
	      q = mem [r ].hhfield .lhfield ;
	      mem [q + 1 ].hhfield .v.RH = pplusfq ( mem [q + 1 ].hhfield 
	      .v.RH , makefraction ( mem [r + 1 ].cint , - (integer) v ) , s 
	      , t , 17 ) ;
	      if ( mem [q + 1 ].hhfield .v.RH == depfinal ) 
	      makeknown ( q , depfinal ) ;
	      q = r ;
	      r = mem [r ].hhfield .v.RH ;
	      freenode ( q , 2 ) ;
	    } 
	  } 
	while ( t++ < for_end ) ;} 
	else {
	    register integer for_end; t = 17 ;for_end = 18 ; if ( t <= 
	for_end) do 
	  {
	    r = maxlink [t ];
	    while ( r != 0 ) {
		
	      q = mem [r ].hhfield .lhfield ;
	      if ( t == 17 ) 
	      {
		if ( curexp == q ) {
		    
		  if ( curtype == 17 ) 
		  curtype = 18 ;
		} 
		mem [q + 1 ].hhfield .v.RH = poverv ( mem [q + 1 ].hhfield 
		.v.RH , 65536L , 17 , 18 ) ;
		mem [q ].hhfield .b0 = 18 ;
		mem [r + 1 ].cint = roundfraction ( mem [r + 1 ].cint ) ;
	      } 
	      mem [q + 1 ].hhfield .v.RH = pplusfq ( mem [q + 1 ].hhfield 
	      .v.RH , makescaled ( mem [r + 1 ].cint , - (integer) v ) , s , 
	      18 , 18 ) ;
	      if ( mem [q + 1 ].hhfield .v.RH == depfinal ) 
	      makeknown ( q , depfinal ) ;
	      q = r ;
	      r = mem [r ].hhfield .v.RH ;
	      freenode ( q , 2 ) ;
	    } 
	  } 
	while ( t++ < for_end ) ;} 
	flushnodelist ( s ) ;
	if ( fixneeded ) 
	fixdependencies () ;
	{
	  if ( aritherror ) 
	  cleararith () ;
	} 
      } 
    } 
    break ;
  case 20 : 
  case 21 : 
    confusion ( 766 ) ;
    break ;
  case 22 : 
  case 23 : 
    deletemacref ( mem [p + 1 ].cint ) ;
    break ;
  } 
  mem [p ].hhfield .b0 = 0 ;
} 
void 
zflushcurexp ( scaled v ) 
{
  switch ( curtype ) 
  {case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
  case 13 : 
  case 14 : 
  case 17 : 
  case 18 : 
  case 19 : 
    {
      recyclevalue ( curexp ) ;
      freenode ( curexp , 2 ) ;
    } 
    break ;
  case 6 : 
    if ( mem [curexp ].hhfield .lhfield == 0 ) 
    tosspen ( curexp ) ;
    else decr ( mem [curexp ].hhfield .lhfield ) ;
    break ;
  case 4 : 
    {
      if ( strref [curexp ]< 127 ) {
	  
	if ( strref [curexp ]> 1 ) 
	decr ( strref [curexp ]) ;
	else flushstring ( curexp ) ;
      } 
    } 
    break ;
  case 8 : 
  case 9 : 
    tossknotlist ( curexp ) ;
    break ;
  case 11 : 
    tossedges ( curexp ) ;
    break ;
    default: 
    ;
    break ;
  } 
  curtype = 16 ;
  curexp = v ;
} 
void 
zflusherror ( scaled v ) 
{
  error () ;
  flushcurexp ( v ) ;
} 
void 
putgeterror ( void ) 
{
  backerror () ;
  getxnext () ;
} 
void 
zputgetflusherror ( scaled v ) 
{
  putgeterror () ;
  flushcurexp ( v ) ;
} 
void 
zflushbelowvariable ( halfword p ) 
{
  halfword q, r  ;
  if ( mem [p ].hhfield .b0 != 21 ) 
  recyclevalue ( p ) ;
  else {
      
    q = mem [p + 1 ].hhfield .v.RH ;
    while ( mem [q ].hhfield .b1 == 3 ) {
	
      flushbelowvariable ( q ) ;
      r = q ;
      q = mem [q ].hhfield .v.RH ;
      freenode ( r , 3 ) ;
    } 
    r = mem [p + 1 ].hhfield .lhfield ;
    q = mem [r ].hhfield .v.RH ;
    recyclevalue ( r ) ;
    if ( mem [p ].hhfield .b1 <= 1 ) 
    freenode ( r , 2 ) ;
    else freenode ( r , 3 ) ;
    do {
	flushbelowvariable ( q ) ;
      r = q ;
      q = mem [q ].hhfield .v.RH ;
      freenode ( r , 3 ) ;
    } while ( ! ( q == 17 ) ) ;
    mem [p ].hhfield .b0 = 0 ;
  } 
} 
void 
zflushvariable ( halfword p , halfword t , boolean discardsuffixes ) 
{
  /* 10 */ halfword q, r  ;
  halfword n  ;
  while ( t != 0 ) {
      
    if ( mem [p ].hhfield .b0 != 21 ) 
    goto lab10 ;
    n = mem [t ].hhfield .lhfield ;
    t = mem [t ].hhfield .v.RH ;
    if ( n == 0 ) 
    {
      r = p + 1 ;
      q = mem [r ].hhfield .v.RH ;
      while ( mem [q ].hhfield .b1 == 3 ) {
	  
	flushvariable ( q , t , discardsuffixes ) ;
	if ( t == 0 ) {
	    
	  if ( mem [q ].hhfield .b0 == 21 ) 
	  r = q ;
	  else {
	      
	    mem [r ].hhfield .v.RH = mem [q ].hhfield .v.RH ;
	    freenode ( q , 3 ) ;
	  } 
	} 
	else r = q ;
	q = mem [r ].hhfield .v.RH ;
      } 
    } 
    p = mem [p + 1 ].hhfield .lhfield ;
    do {
	r = p ;
      p = mem [p ].hhfield .v.RH ;
    } while ( ! ( mem [p + 2 ].hhfield .lhfield >= n ) ) ;
    if ( mem [p + 2 ].hhfield .lhfield != n ) 
    goto lab10 ;
  } 
  if ( discardsuffixes ) 
  flushbelowvariable ( p ) ;
  else {
      
    if ( mem [p ].hhfield .b0 == 21 ) 
    p = mem [p + 1 ].hhfield .lhfield ;
    recyclevalue ( p ) ;
  } 
  lab10: ;
} 
smallnumber 
zundtype ( halfword p ) 
{
  register smallnumber Result; switch ( mem [p ].hhfield .b0 ) 
  {case 0 : 
  case 1 : 
    Result = 0 ;
    break ;
  case 2 : 
  case 3 : 
    Result = 3 ;
    break ;
  case 4 : 
  case 5 : 
    Result = 5 ;
    break ;
  case 6 : 
  case 7 : 
  case 8 : 
    Result = 7 ;
    break ;
  case 9 : 
  case 10 : 
    Result = 10 ;
    break ;
  case 11 : 
  case 12 : 
    Result = 12 ;
    break ;
  case 13 : 
  case 14 : 
  case 15 : 
    Result = mem [p ].hhfield .b0 ;
    break ;
  case 16 : 
  case 17 : 
  case 18 : 
  case 19 : 
    Result = 15 ;
    break ;
  } 
  return Result ;
} 
void 
zclearsymbol ( halfword p , boolean saving ) 
{
  halfword q  ;
  q = eqtb [p ].v.RH ;
  switch ( eqtb [p ].lhfield % 86 ) 
  {case 10 : 
  case 53 : 
  case 44 : 
  case 49 : 
    if ( ! saving ) 
    deletemacref ( q ) ;
    break ;
  case 41 : 
    if ( q != 0 ) {
	
      if ( saving ) 
      mem [q ].hhfield .b1 = 1 ;
      else {
	  
	flushbelowvariable ( q ) ;
	freenode ( q , 2 ) ;
      } 
    } 
    break ;
    default: 
    ;
    break ;
  } 
  eqtb [p ]= eqtb [9769 ];
} 
void 
zsavevariable ( halfword q ) 
{
  halfword p  ;
  if ( saveptr != 0 ) 
  {
    p = getnode ( 2 ) ;
    mem [p ].hhfield .lhfield = q ;
    mem [p ].hhfield .v.RH = saveptr ;
    mem [p + 1 ].hhfield = eqtb [q ];
    saveptr = p ;
  } 
  clearsymbol ( q , ( saveptr != 0 ) ) ;
} 
void 
zsaveinternal ( halfword q ) 
{
  halfword p  ;
  if ( saveptr != 0 ) 
  {
    p = getnode ( 2 ) ;
    mem [p ].hhfield .lhfield = 9769 + q ;
    mem [p ].hhfield .v.RH = saveptr ;
    mem [p + 1 ].cint = internal [q ];
    saveptr = p ;
  } 
} 
void 
unsave ( void ) 
{
  halfword q  ;
  halfword p  ;
  while ( mem [saveptr ].hhfield .lhfield != 0 ) {
      
    q = mem [saveptr ].hhfield .lhfield ;
    if ( q > 9769 ) 
    {
      if ( internal [8 ]> 0 ) 
      {
	begindiagnostic () ;
	printnl ( 516 ) ;
	slowprint ( intname [q - ( 9769 ) ]) ;
	printchar ( 61 ) ;
	printscaled ( mem [saveptr + 1 ].cint ) ;
	printchar ( 125 ) ;
	enddiagnostic ( false ) ;
      } 
      internal [q - ( 9769 ) ]= mem [saveptr + 1 ].cint ;
    } 
    else {
	
      if ( internal [8 ]> 0 ) 
      {
	begindiagnostic () ;
	printnl ( 516 ) ;
	slowprint ( hash [q ].v.RH ) ;
	printchar ( 125 ) ;
	enddiagnostic ( false ) ;
      } 
      clearsymbol ( q , false ) ;
      eqtb [q ]= mem [saveptr + 1 ].hhfield ;
      if ( eqtb [q ].lhfield % 86 == 41 ) 
      {
	p = eqtb [q ].v.RH ;
	if ( p != 0 ) 
	mem [p ].hhfield .b1 = 0 ;
      } 
    } 
    p = mem [saveptr ].hhfield .v.RH ;
    freenode ( saveptr , 2 ) ;
    saveptr = p ;
  } 
  p = mem [saveptr ].hhfield .v.RH ;
  {
    mem [saveptr ].hhfield .v.RH = avail ;
    avail = saveptr ;
	;
#ifdef STAT
    decr ( dynused ) ;
#endif /* STAT */
  } 
  saveptr = p ;
} 
halfword 
zcopyknot ( halfword p ) 
{
  register halfword Result; halfword q  ;
  unsigned char k  ;
  q = getnode ( 7 ) ;
  {register integer for_end; k = 0 ;for_end = 6 ; if ( k <= for_end) do 
    mem [q + k ]= mem [p + k ];
  while ( k++ < for_end ) ;} 
  Result = q ;
  return Result ;
} 
halfword 
zcopypath ( halfword p ) 
{
  /* 10 */ register halfword Result; halfword q, pp, qq  ;
  q = getnode ( 7 ) ;
  qq = q ;
  pp = p ;
  while ( true ) {
      
    mem [qq ].hhfield .b0 = mem [pp ].hhfield .b0 ;
    mem [qq ].hhfield .b1 = mem [pp ].hhfield .b1 ;
    mem [qq + 1 ].cint = mem [pp + 1 ].cint ;
    mem [qq + 2 ].cint = mem [pp + 2 ].cint ;
    mem [qq + 3 ].cint = mem [pp + 3 ].cint ;
    mem [qq + 4 ].cint = mem [pp + 4 ].cint ;
    mem [qq + 5 ].cint = mem [pp + 5 ].cint ;
    mem [qq + 6 ].cint = mem [pp + 6 ].cint ;
    if ( mem [pp ].hhfield .v.RH == p ) 
    {
      mem [qq ].hhfield .v.RH = q ;
      Result = q ;
      goto lab10 ;
    } 
    mem [qq ].hhfield .v.RH = getnode ( 7 ) ;
    qq = mem [qq ].hhfield .v.RH ;
    pp = mem [pp ].hhfield .v.RH ;
  } 
  lab10: ;
  return Result ;
} 
halfword 
zhtapypoc ( halfword p ) 
{
  /* 10 */ register halfword Result; halfword q, pp, qq, rr  ;
  q = getnode ( 7 ) ;
  qq = q ;
  pp = p ;
  while ( true ) {
      
    mem [qq ].hhfield .b1 = mem [pp ].hhfield .b0 ;
    mem [qq ].hhfield .b0 = mem [pp ].hhfield .b1 ;
    mem [qq + 1 ].cint = mem [pp + 1 ].cint ;
    mem [qq + 2 ].cint = mem [pp + 2 ].cint ;
    mem [qq + 5 ].cint = mem [pp + 3 ].cint ;
    mem [qq + 6 ].cint = mem [pp + 4 ].cint ;
    mem [qq + 3 ].cint = mem [pp + 5 ].cint ;
    mem [qq + 4 ].cint = mem [pp + 6 ].cint ;
    if ( mem [pp ].hhfield .v.RH == p ) 
    {
      mem [q ].hhfield .v.RH = qq ;
      pathtail = pp ;
      Result = q ;
      goto lab10 ;
    } 
    rr = getnode ( 7 ) ;
    mem [rr ].hhfield .v.RH = qq ;
    qq = rr ;
    pp = mem [pp ].hhfield .v.RH ;
  } 
  lab10: ;
  return Result ;
} 
fraction 
zcurlratio ( scaled gamma , scaled atension , scaled btension ) 
{
  register fraction Result; fraction alpha, beta, num, denom, ff  ;
  alpha = makefraction ( 65536L , atension ) ;
  beta = makefraction ( 65536L , btension ) ;
  if ( alpha <= beta ) 
  {
    ff = makefraction ( alpha , beta ) ;
    ff = takefraction ( ff , ff ) ;
    gamma = takefraction ( gamma , ff ) ;
    beta = beta / 4096 ;
    denom = takefraction ( gamma , alpha ) + 196608L - beta ;
    num = takefraction ( gamma , 805306368L - alpha ) + beta ;
  } 
  else {
      
    ff = makefraction ( beta , alpha ) ;
    ff = takefraction ( ff , ff ) ;
    beta = takefraction ( beta , ff ) / 4096 ;
    denom = takefraction ( gamma , alpha ) + ( ff / 1365 ) - beta ;
    num = takefraction ( gamma , 805306368L - alpha ) + beta ;
  } 
  if ( num >= denom + denom + denom + denom ) 
  Result = 1073741824L ;
  else Result = makefraction ( num , denom ) ;
  return Result ;
} 
void 
zsetcontrols ( halfword p , halfword q , integer k ) 
{
  fraction rr, ss  ;
  scaled lt, rt  ;
  fraction sine  ;
  lt = abs ( mem [q + 4 ].cint ) ;
  rt = abs ( mem [p + 6 ].cint ) ;
  rr = velocity ( st , ct , sf , cf , rt ) ;
  ss = velocity ( sf , cf , st , ct , lt ) ;
  if ( ( mem [p + 6 ].cint < 0 ) || ( mem [q + 4 ].cint < 0 ) ) {
      
    if ( ( ( st >= 0 ) && ( sf >= 0 ) ) || ( ( st <= 0 ) && ( sf <= 0 ) ) ) 
    {
      sine = takefraction ( abs ( st ) , cf ) + takefraction ( abs ( sf ) , ct 
      ) ;
      if ( sine > 0 ) 
      {
	sine = takefraction ( sine , 268500992L ) ;
	if ( mem [p + 6 ].cint < 0 ) {
	    
	  if ( abvscd ( abs ( sf ) , 268435456L , rr , sine ) < 0 ) 
	  rr = makefraction ( abs ( sf ) , sine ) ;
	} 
	if ( mem [q + 4 ].cint < 0 ) {
	    
	  if ( abvscd ( abs ( st ) , 268435456L , ss , sine ) < 0 ) 
	  ss = makefraction ( abs ( st ) , sine ) ;
	} 
      } 
    } 
  } 
  mem [p + 5 ].cint = mem [p + 1 ].cint + takefraction ( takefraction ( 
  deltax [k ], ct ) - takefraction ( deltay [k ], st ) , rr ) ;
  mem [p + 6 ].cint = mem [p + 2 ].cint + takefraction ( takefraction ( 
  deltay [k ], ct ) + takefraction ( deltax [k ], st ) , rr ) ;
  mem [q + 3 ].cint = mem [q + 1 ].cint - takefraction ( takefraction ( 
  deltax [k ], cf ) + takefraction ( deltay [k ], sf ) , ss ) ;
  mem [q + 4 ].cint = mem [q + 2 ].cint - takefraction ( takefraction ( 
  deltay [k ], cf ) - takefraction ( deltax [k ], sf ) , ss ) ;
  mem [p ].hhfield .b1 = 1 ;
  mem [q ].hhfield .b0 = 1 ;
} 
void 
zsolvechoices ( halfword p , halfword q , halfword n ) 
{
  /* 40 10 */ integer k  ;
  halfword r, s, t  ;
  fraction aa, bb, cc, ff, acc  ;
  scaled dd, ee  ;
  scaled lt, rt  ;
  k = 0 ;
  s = p ;
  while ( true ) {
      
    t = mem [s ].hhfield .v.RH ;
    if ( k == 0 ) 
    switch ( mem [s ].hhfield .b1 ) 
    {case 2 : 
      if ( mem [t ].hhfield .b0 == 2 ) 
      {
	aa = narg ( deltax [0 ], deltay [0 ]) ;
	nsincos ( mem [p + 5 ].cint - aa ) ;
	ct = ncos ;
	st = nsin ;
	nsincos ( mem [q + 3 ].cint - aa ) ;
	cf = ncos ;
	sf = - (integer) nsin ;
	setcontrols ( p , q , 0 ) ;
	goto lab10 ;
      } 
      else {
	  
	vv [0 ]= mem [s + 5 ].cint - narg ( deltax [0 ], deltay [0 ]) 
	;
	if ( abs ( vv [0 ]) > 188743680L ) {
	    
	  if ( vv [0 ]> 0 ) 
	  vv [0 ]= vv [0 ]- 377487360L ;
	  else vv [0 ]= vv [0 ]+ 377487360L ;
	} 
	uu [0 ]= 0 ;
	ww [0 ]= 0 ;
      } 
      break ;
    case 3 : 
      if ( mem [t ].hhfield .b0 == 3 ) 
      {
	mem [p ].hhfield .b1 = 1 ;
	mem [q ].hhfield .b0 = 1 ;
	lt = abs ( mem [q + 4 ].cint ) ;
	rt = abs ( mem [p + 6 ].cint ) ;
	if ( rt == 65536L ) 
	{
	  if ( deltax [0 ]>= 0 ) 
	  mem [p + 5 ].cint = mem [p + 1 ].cint + ( ( deltax [0 ]+ 1 ) / 
	  3 ) ;
	  else mem [p + 5 ].cint = mem [p + 1 ].cint + ( ( deltax [0 ]- 
	  1 ) / 3 ) ;
	  if ( deltay [0 ]>= 0 ) 
	  mem [p + 6 ].cint = mem [p + 2 ].cint + ( ( deltay [0 ]+ 1 ) / 
	  3 ) ;
	  else mem [p + 6 ].cint = mem [p + 2 ].cint + ( ( deltay [0 ]- 
	  1 ) / 3 ) ;
	} 
	else {
	    
	  ff = makefraction ( 65536L , 3 * rt ) ;
	  mem [p + 5 ].cint = mem [p + 1 ].cint + takefraction ( deltax [
	  0 ], ff ) ;
	  mem [p + 6 ].cint = mem [p + 2 ].cint + takefraction ( deltay [
	  0 ], ff ) ;
	} 
	if ( lt == 65536L ) 
	{
	  if ( deltax [0 ]>= 0 ) 
	  mem [q + 3 ].cint = mem [q + 1 ].cint - ( ( deltax [0 ]+ 1 ) / 
	  3 ) ;
	  else mem [q + 3 ].cint = mem [q + 1 ].cint - ( ( deltax [0 ]- 
	  1 ) / 3 ) ;
	  if ( deltay [0 ]>= 0 ) 
	  mem [q + 4 ].cint = mem [q + 2 ].cint - ( ( deltay [0 ]+ 1 ) / 
	  3 ) ;
	  else mem [q + 4 ].cint = mem [q + 2 ].cint - ( ( deltay [0 ]- 
	  1 ) / 3 ) ;
	} 
	else {
	    
	  ff = makefraction ( 65536L , 3 * lt ) ;
	  mem [q + 3 ].cint = mem [q + 1 ].cint - takefraction ( deltax [
	  0 ], ff ) ;
	  mem [q + 4 ].cint = mem [q + 2 ].cint - takefraction ( deltay [
	  0 ], ff ) ;
	} 
	goto lab10 ;
      } 
      else {
	  
	cc = mem [s + 5 ].cint ;
	lt = abs ( mem [t + 4 ].cint ) ;
	rt = abs ( mem [s + 6 ].cint ) ;
	if ( ( rt == 65536L ) && ( lt == 65536L ) ) 
	uu [0 ]= makefraction ( cc + cc + 65536L , cc + 131072L ) ;
	else uu [0 ]= curlratio ( cc , rt , lt ) ;
	vv [0 ]= - (integer) takefraction ( psi [1 ], uu [0 ]) ;
	ww [0 ]= 0 ;
      } 
      break ;
    case 4 : 
      {
	uu [0 ]= 0 ;
	vv [0 ]= 0 ;
	ww [0 ]= 268435456L ;
      } 
      break ;
    } 
    else switch ( mem [s ].hhfield .b0 ) 
    {case 5 : 
    case 4 : 
      {
	if ( abs ( mem [r + 6 ].cint ) == 65536L ) 
	{
	  aa = 134217728L ;
	  dd = 2 * delta [k ];
	} 
	else {
	    
	  aa = makefraction ( 65536L , 3 * abs ( mem [r + 6 ].cint ) - 
	  65536L ) ;
	  dd = takefraction ( delta [k ], 805306368L - makefraction ( 65536L 
	  , abs ( mem [r + 6 ].cint ) ) ) ;
	} 
	if ( abs ( mem [t + 4 ].cint ) == 65536L ) 
	{
	  bb = 134217728L ;
	  ee = 2 * delta [k - 1 ];
	} 
	else {
	    
	  bb = makefraction ( 65536L , 3 * abs ( mem [t + 4 ].cint ) - 
	  65536L ) ;
	  ee = takefraction ( delta [k - 1 ], 805306368L - makefraction ( 
	  65536L , abs ( mem [t + 4 ].cint ) ) ) ;
	} 
	cc = 268435456L - takefraction ( uu [k - 1 ], aa ) ;
	dd = takefraction ( dd , cc ) ;
	lt = abs ( mem [s + 4 ].cint ) ;
	rt = abs ( mem [s + 6 ].cint ) ;
	if ( lt != rt ) {
	    
	  if ( lt < rt ) 
	  {
	    ff = makefraction ( lt , rt ) ;
	    ff = takefraction ( ff , ff ) ;
	    dd = takefraction ( dd , ff ) ;
	  } 
	  else {
	      
	    ff = makefraction ( rt , lt ) ;
	    ff = takefraction ( ff , ff ) ;
	    ee = takefraction ( ee , ff ) ;
	  } 
	} 
	ff = makefraction ( ee , ee + dd ) ;
	uu [k ]= takefraction ( ff , bb ) ;
	acc = - (integer) takefraction ( psi [k + 1 ], uu [k ]) ;
	if ( mem [r ].hhfield .b1 == 3 ) 
	{
	  ww [k ]= 0 ;
	  vv [k ]= acc - takefraction ( psi [1 ], 268435456L - ff ) ;
	} 
	else {
	    
	  ff = makefraction ( 268435456L - ff , cc ) ;
	  acc = acc - takefraction ( psi [k ], ff ) ;
	  ff = takefraction ( ff , aa ) ;
	  vv [k ]= acc - takefraction ( vv [k - 1 ], ff ) ;
	  if ( ww [k - 1 ]== 0 ) 
	  ww [k ]= 0 ;
	  else ww [k ]= - (integer) takefraction ( ww [k - 1 ], ff ) ;
	} 
	if ( mem [s ].hhfield .b0 == 5 ) 
	{
	  aa = 0 ;
	  bb = 268435456L ;
	  do {
	      decr ( k ) ;
	    if ( k == 0 ) 
	    k = n ;
	    aa = vv [k ]- takefraction ( aa , uu [k ]) ;
	    bb = ww [k ]- takefraction ( bb , uu [k ]) ;
	  } while ( ! ( k == n ) ) ;
	  aa = makefraction ( aa , 268435456L - bb ) ;
	  theta [n ]= aa ;
	  vv [0 ]= aa ;
	  {register integer for_end; k = 1 ;for_end = n - 1 ; if ( k <= 
	  for_end) do 
	    vv [k ]= vv [k ]+ takefraction ( aa , ww [k ]) ;
	  while ( k++ < for_end ) ;} 
	  goto lab40 ;
	} 
      } 
      break ;
    case 3 : 
      {
	cc = mem [s + 3 ].cint ;
	lt = abs ( mem [s + 4 ].cint ) ;
	rt = abs ( mem [r + 6 ].cint ) ;
	if ( ( rt == 65536L ) && ( lt == 65536L ) ) 
	ff = makefraction ( cc + cc + 65536L , cc + 131072L ) ;
	else ff = curlratio ( cc , lt , rt ) ;
	theta [n ]= - (integer) makefraction ( takefraction ( vv [n - 1 ], 
	ff ) , 268435456L - takefraction ( ff , uu [n - 1 ]) ) ;
	goto lab40 ;
      } 
      break ;
    case 2 : 
      {
	theta [n ]= mem [s + 3 ].cint - narg ( deltax [n - 1 ], deltay [
	n - 1 ]) ;
	if ( abs ( theta [n ]) > 188743680L ) {
	    
	  if ( theta [n ]> 0 ) 
	  theta [n ]= theta [n ]- 377487360L ;
	  else theta [n ]= theta [n ]+ 377487360L ;
	} 
	goto lab40 ;
      } 
      break ;
    } 
    r = s ;
    s = t ;
    incr ( k ) ;
  } 
  lab40: {
      register integer for_end; k = n - 1 ;for_end = 0 ; if ( k >= 
  for_end) do 
    theta [k ]= vv [k ]- takefraction ( theta [k + 1 ], uu [k ]) ;
  while ( k-- > for_end ) ;} 
  s = p ;
  k = 0 ;
  do {
      t = mem [s ].hhfield .v.RH ;
    nsincos ( theta [k ]) ;
    st = nsin ;
    ct = ncos ;
    nsincos ( - (integer) psi [k + 1 ]- theta [k + 1 ]) ;
    sf = nsin ;
    cf = ncos ;
    setcontrols ( s , t , k ) ;
    incr ( k ) ;
    s = t ;
  } while ( ! ( k == n ) ) ;
  lab10: ;
} 
void 
zmakechoices ( halfword knots ) 
{
  /* 30 */ halfword h  ;
  halfword p, q  ;
  integer k, n  ;
  halfword s, t  ;
  scaled delx, dely  ;
  fraction sine, cosine  ;
  {
    if ( aritherror ) 
    cleararith () ;
  } 
  if ( internal [4 ]> 0 ) 
  printpath ( knots , 526 , true ) ;
  p = knots ;
  do {
      q = mem [p ].hhfield .v.RH ;
    if ( mem [p + 1 ].cint == mem [q + 1 ].cint ) {
	
      if ( mem [p + 2 ].cint == mem [q + 2 ].cint ) {
	  
	if ( mem [p ].hhfield .b1 > 1 ) 
	{
	  mem [p ].hhfield .b1 = 1 ;
	  if ( mem [p ].hhfield .b0 == 4 ) 
	  {
	    mem [p ].hhfield .b0 = 3 ;
	    mem [p + 3 ].cint = 65536L ;
	  } 
	  mem [q ].hhfield .b0 = 1 ;
	  if ( mem [q ].hhfield .b1 == 4 ) 
	  {
	    mem [q ].hhfield .b1 = 3 ;
	    mem [q + 5 ].cint = 65536L ;
	  } 
	  mem [p + 5 ].cint = mem [p + 1 ].cint ;
	  mem [q + 3 ].cint = mem [p + 1 ].cint ;
	  mem [p + 6 ].cint = mem [p + 2 ].cint ;
	  mem [q + 4 ].cint = mem [p + 2 ].cint ;
	} 
      } 
    } 
    p = q ;
  } while ( ! ( p == knots ) ) ;
  h = knots ;
  while ( true ) {
      
    if ( mem [h ].hhfield .b0 != 4 ) 
    goto lab30 ;
    if ( mem [h ].hhfield .b1 != 4 ) 
    goto lab30 ;
    h = mem [h ].hhfield .v.RH ;
    if ( h == knots ) 
    {
      mem [h ].hhfield .b0 = 5 ;
      goto lab30 ;
    } 
  } 
  lab30: ;
  p = h ;
  do {
      q = mem [p ].hhfield .v.RH ;
    if ( mem [p ].hhfield .b1 >= 2 ) 
    {
      while ( ( mem [q ].hhfield .b0 == 4 ) && ( mem [q ].hhfield .b1 == 4 
      ) ) q = mem [q ].hhfield .v.RH ;
      k = 0 ;
      s = p ;
      n = pathsize ;
      do {
	  t = mem [s ].hhfield .v.RH ;
	deltax [k ]= mem [t + 1 ].cint - mem [s + 1 ].cint ;
	deltay [k ]= mem [t + 2 ].cint - mem [s + 2 ].cint ;
	delta [k ]= pythadd ( deltax [k ], deltay [k ]) ;
	if ( k > 0 ) 
	{
	  sine = makefraction ( deltay [k - 1 ], delta [k - 1 ]) ;
	  cosine = makefraction ( deltax [k - 1 ], delta [k - 1 ]) ;
	  psi [k ]= narg ( takefraction ( deltax [k ], cosine ) + 
	  takefraction ( deltay [k ], sine ) , takefraction ( deltay [k ], 
	  cosine ) - takefraction ( deltax [k ], sine ) ) ;
	} 
	incr ( k ) ;
	s = t ;
	if ( k == pathsize ) 
	overflow ( 531 , pathsize ) ;
	if ( s == q ) 
	n = k ;
      } while ( ! ( ( k >= n ) && ( mem [s ].hhfield .b0 != 5 ) ) ) ;
      if ( k == n ) 
      psi [n ]= 0 ;
      else psi [k ]= psi [1 ];
      if ( mem [q ].hhfield .b0 == 4 ) 
      {
	delx = mem [q + 5 ].cint - mem [q + 1 ].cint ;
	dely = mem [q + 6 ].cint - mem [q + 2 ].cint ;
	if ( ( delx == 0 ) && ( dely == 0 ) ) 
	{
	  mem [q ].hhfield .b0 = 3 ;
	  mem [q + 3 ].cint = 65536L ;
	} 
	else {
	    
	  mem [q ].hhfield .b0 = 2 ;
	  mem [q + 3 ].cint = narg ( delx , dely ) ;
	} 
      } 
      if ( ( mem [p ].hhfield .b1 == 4 ) && ( mem [p ].hhfield .b0 == 1 ) 
      ) 
      {
	delx = mem [p + 1 ].cint - mem [p + 3 ].cint ;
	dely = mem [p + 2 ].cint - mem [p + 4 ].cint ;
	if ( ( delx == 0 ) && ( dely == 0 ) ) 
	{
	  mem [p ].hhfield .b1 = 3 ;
	  mem [p + 5 ].cint = 65536L ;
	} 
	else {
	    
	  mem [p ].hhfield .b1 = 2 ;
	  mem [p + 5 ].cint = narg ( delx , dely ) ;
	} 
      } 
      solvechoices ( p , q , n ) ;
    } 
    p = q ;
  } while ( ! ( p == h ) ) ;
  if ( internal [4 ]> 0 ) 
  printpath ( knots , 527 , true ) ;
  if ( aritherror ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 528 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 528 ) ;
      } 
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 529 ;
      helpline [0 ]= 530 ;
    } 
    putgeterror () ;
    aritherror = false ;
  } 
} 
void 
zmakemoves ( scaled xx0 , scaled xx1 , scaled xx2 , scaled xx3 , scaled yy0 , 
scaled yy1 , scaled yy2 , scaled yy3 , smallnumber xicorr , smallnumber 
etacorr ) 
{
  /* 22 30 10 */ integer x1, x2, x3, m, r, y1, y2, y3, n, s, l  ;
  integer q, t, u, x2a, x3a, y2a, y3a  ;
  if ( ( xx3 < xx0 ) || ( yy3 < yy0 ) ) 
  confusion ( 109 ) ;
  l = 16 ;
  bisectptr = 0 ;
  x1 = xx1 - xx0 ;
  x2 = xx2 - xx1 ;
  x3 = xx3 - xx2 ;
  if ( xx0 >= xicorr ) 
  r = ( xx0 - xicorr ) % 65536L ;
  else r = 65535L - ( ( - (integer) xx0 + xicorr - 1 ) % 65536L ) ;
  m = ( xx3 - xx0 + r ) / 65536L ;
  y1 = yy1 - yy0 ;
  y2 = yy2 - yy1 ;
  y3 = yy3 - yy2 ;
  if ( yy0 >= etacorr ) 
  s = ( yy0 - etacorr ) % 65536L ;
  else s = 65535L - ( ( - (integer) yy0 + etacorr - 1 ) % 65536L ) ;
  n = ( yy3 - yy0 + s ) / 65536L ;
  if ( ( xx3 - xx0 >= 268435456L ) || ( yy3 - yy0 >= 268435456L ) ) 
  {
    x1 = half ( x1 + xicorr ) ;
    x2 = half ( x2 + xicorr ) ;
    x3 = half ( x3 + xicorr ) ;
    r = half ( r + xicorr ) ;
    y1 = half ( y1 + etacorr ) ;
    y2 = half ( y2 + etacorr ) ;
    y3 = half ( y3 + etacorr ) ;
    s = half ( s + etacorr ) ;
    l = 15 ;
  } 
  while ( true ) {
      
    lab22: if ( m == 0 ) 
    while ( n > 0 ) {
	
      incr ( moveptr ) ;
      move [moveptr ]= 1 ;
      decr ( n ) ;
    } 
    else if ( n == 0 ) 
    move [moveptr ]= move [moveptr ]+ m ;
    else if ( m + n == 2 ) 
    {
      r = twotothe [l ]- r ;
      s = twotothe [l ]- s ;
      while ( l < 30 ) {
	  
	x3a = x3 ;
	x2a = half ( x2 + x3 + xicorr ) ;
	x2 = half ( x1 + x2 + xicorr ) ;
	x3 = half ( x2 + x2a + xicorr ) ;
	t = x1 + x2 + x3 ;
	r = r + r - xicorr ;
	y3a = y3 ;
	y2a = half ( y2 + y3 + etacorr ) ;
	y2 = half ( y1 + y2 + etacorr ) ;
	y3 = half ( y2 + y2a + etacorr ) ;
	u = y1 + y2 + y3 ;
	s = s + s - etacorr ;
	if ( t < r ) {
	    
	  if ( u < s ) 
	  {
	    x1 = x3 ;
	    x2 = x2a ;
	    x3 = x3a ;
	    r = r - t ;
	    y1 = y3 ;
	    y2 = y2a ;
	    y3 = y3a ;
	    s = s - u ;
	  } 
	  else {
	      
	    {
	      incr ( moveptr ) ;
	      move [moveptr ]= 2 ;
	    } 
	    goto lab30 ;
	  } 
	} 
	else if ( u < s ) 
	{
	  {
	    incr ( move [moveptr ]) ;
	    incr ( moveptr ) ;
	    move [moveptr ]= 1 ;
	  } 
	  goto lab30 ;
	} 
	incr ( l ) ;
      } 
      r = r - xicorr ;
      s = s - etacorr ;
      if ( abvscd ( x1 + x2 + x3 , s , y1 + y2 + y3 , r ) - xicorr >= 0 ) 
      {
	incr ( move [moveptr ]) ;
	incr ( moveptr ) ;
	move [moveptr ]= 1 ;
      } 
      else {
	  
	incr ( moveptr ) ;
	move [moveptr ]= 2 ;
      } 
      lab30: ;
    } 
    else {
	
      incr ( l ) ;
      bisectstack [bisectptr + 10 ]= l ;
      bisectstack [bisectptr + 2 ]= x3 ;
      bisectstack [bisectptr + 1 ]= half ( x2 + x3 + xicorr ) ;
      x2 = half ( x1 + x2 + xicorr ) ;
      x3 = half ( x2 + bisectstack [bisectptr + 1 ]+ xicorr ) ;
      bisectstack [bisectptr ]= x3 ;
      r = r + r + xicorr ;
      t = x1 + x2 + x3 + r ;
      q = t / twotothe [l ];
      bisectstack [bisectptr + 3 ]= t % twotothe [l ];
      bisectstack [bisectptr + 4 ]= m - q ;
      m = q ;
      bisectstack [bisectptr + 7 ]= y3 ;
      bisectstack [bisectptr + 6 ]= half ( y2 + y3 + etacorr ) ;
      y2 = half ( y1 + y2 + etacorr ) ;
      y3 = half ( y2 + bisectstack [bisectptr + 6 ]+ etacorr ) ;
      bisectstack [bisectptr + 5 ]= y3 ;
      s = s + s + etacorr ;
      u = y1 + y2 + y3 + s ;
      q = u / twotothe [l ];
      bisectstack [bisectptr + 8 ]= u % twotothe [l ];
      bisectstack [bisectptr + 9 ]= n - q ;
      n = q ;
      bisectptr = bisectptr + 11 ;
      goto lab22 ;
    } 
    if ( bisectptr == 0 ) 
    goto lab10 ;
    bisectptr = bisectptr - 11 ;
    x1 = bisectstack [bisectptr ];
    x2 = bisectstack [bisectptr + 1 ];
    x3 = bisectstack [bisectptr + 2 ];
    r = bisectstack [bisectptr + 3 ];
    m = bisectstack [bisectptr + 4 ];
    y1 = bisectstack [bisectptr + 5 ];
    y2 = bisectstack [bisectptr + 6 ];
    y3 = bisectstack [bisectptr + 7 ];
    s = bisectstack [bisectptr + 8 ];
    n = bisectstack [bisectptr + 9 ];
    l = bisectstack [bisectptr + 10 ];
  } 
  lab10: ;
} 
void 
zsmoothmoves ( integer b , integer t ) 
{
  integer k  ;
  integer a, aa, aaa  ;
  if ( t - b >= 3 ) 
  {
    k = b + 2 ;
    aa = move [k - 1 ];
    aaa = move [k - 2 ];
    do {
	a = move [k ];
      if ( abs ( a - aa ) > 1 ) {
	  
	if ( a > aa ) 
	{
	  if ( aaa >= aa ) {
	      
	    if ( a >= move [k + 1 ]) 
	    {
	      incr ( move [k - 1 ]) ;
	      move [k ]= a - 1 ;
	    } 
	  } 
	} 
	else {
	    
	  if ( aaa <= aa ) {
	      
	    if ( a <= move [k + 1 ]) 
	    {
	      decr ( move [k - 1 ]) ;
	      move [k ]= a + 1 ;
	    } 
	  } 
	} 
      } 
      incr ( k ) ;
      aaa = aa ;
      aa = a ;
    } while ( ! ( k == t ) ) ;
  } 
} 
void 
zinitedges ( halfword h ) 
{
  mem [h ].hhfield .lhfield = h ;
  mem [h ].hhfield .v.RH = h ;
  mem [h + 1 ].hhfield .lhfield = 8191 ;
  mem [h + 1 ].hhfield .v.RH = 1 ;
  mem [h + 2 ].hhfield .lhfield = 8191 ;
  mem [h + 2 ].hhfield .v.RH = 1 ;
  mem [h + 3 ].hhfield .lhfield = 4096 ;
  mem [h + 3 ].hhfield .v.RH = 0 ;
  mem [h + 4 ].cint = 0 ;
  mem [h + 5 ].hhfield .v.RH = h ;
  mem [h + 5 ].hhfield .lhfield = 0 ;
} 
void 
fixoffset ( void ) 
{
  halfword p, q  ;
  integer delta  ;
  delta = 8 * ( mem [curedges + 3 ].hhfield .lhfield - 4096 ) ;
  mem [curedges + 3 ].hhfield .lhfield = 4096 ;
  q = mem [curedges ].hhfield .v.RH ;
  while ( q != curedges ) {
      
    p = mem [q + 1 ].hhfield .v.RH ;
    while ( p != memtop ) {
	
      mem [p ].hhfield .lhfield = mem [p ].hhfield .lhfield - delta ;
      p = mem [p ].hhfield .v.RH ;
    } 
    p = mem [q + 1 ].hhfield .lhfield ;
    while ( p > 1 ) {
	
      mem [p ].hhfield .lhfield = mem [p ].hhfield .lhfield - delta ;
      p = mem [p ].hhfield .v.RH ;
    } 
    q = mem [q ].hhfield .v.RH ;
  } 
} 
void 
zedgeprep ( integer ml , integer mr , integer nl , integer nr ) 
{
  halfword delta  ;
  integer temp  ;
  halfword p, q  ;
  ml = ml + 4096 ;
  mr = mr + 4096 ;
  nl = nl + 4096 ;
  nr = nr + 4095 ;
  if ( ml < mem [curedges + 2 ].hhfield .lhfield ) 
  mem [curedges + 2 ].hhfield .lhfield = ml ;
  if ( mr > mem [curedges + 2 ].hhfield .v.RH ) 
  mem [curedges + 2 ].hhfield .v.RH = mr ;
  temp = mem [curedges + 3 ].hhfield .lhfield - 4096 ;
  if ( ! ( abs ( mem [curedges + 2 ].hhfield .lhfield + temp - 4096 ) < 4096 
  ) || ! ( abs ( mem [curedges + 2 ].hhfield .v.RH + temp - 4096 ) < 4096 ) 
  ) 
  fixoffset () ;
  if ( mem [curedges ].hhfield .v.RH == curedges ) 
  {
    mem [curedges + 1 ].hhfield .lhfield = nr + 1 ;
    mem [curedges + 1 ].hhfield .v.RH = nr ;
  } 
  if ( nl < mem [curedges + 1 ].hhfield .lhfield ) 
  {
    delta = mem [curedges + 1 ].hhfield .lhfield - nl ;
    mem [curedges + 1 ].hhfield .lhfield = nl ;
    p = mem [curedges ].hhfield .v.RH ;
    do {
	q = getnode ( 2 ) ;
      mem [q + 1 ].hhfield .v.RH = memtop ;
      mem [q + 1 ].hhfield .lhfield = 1 ;
      mem [p ].hhfield .lhfield = q ;
      mem [q ].hhfield .v.RH = p ;
      p = q ;
      decr ( delta ) ;
    } while ( ! ( delta == 0 ) ) ;
    mem [p ].hhfield .lhfield = curedges ;
    mem [curedges ].hhfield .v.RH = p ;
    if ( mem [curedges + 5 ].hhfield .v.RH == curedges ) 
    mem [curedges + 5 ].hhfield .lhfield = nl - 1 ;
  } 
  if ( nr > mem [curedges + 1 ].hhfield .v.RH ) 
  {
    delta = nr - mem [curedges + 1 ].hhfield .v.RH ;
    mem [curedges + 1 ].hhfield .v.RH = nr ;
    p = mem [curedges ].hhfield .lhfield ;
    do {
	q = getnode ( 2 ) ;
      mem [q + 1 ].hhfield .v.RH = memtop ;
      mem [q + 1 ].hhfield .lhfield = 1 ;
      mem [p ].hhfield .v.RH = q ;
      mem [q ].hhfield .lhfield = p ;
      p = q ;
      decr ( delta ) ;
    } while ( ! ( delta == 0 ) ) ;
    mem [p ].hhfield .v.RH = curedges ;
    mem [curedges ].hhfield .lhfield = p ;
    if ( mem [curedges + 5 ].hhfield .v.RH == curedges ) 
    mem [curedges + 5 ].hhfield .lhfield = nr + 1 ;
  } 
} 
halfword 
zcopyedges ( halfword h ) 
{
  register halfword Result; halfword p, r  ;
  halfword hh, pp, qq, rr, ss  ;
  hh = getnode ( 6 ) ;
  mem [hh + 1 ]= mem [h + 1 ];
  mem [hh + 2 ]= mem [h + 2 ];
  mem [hh + 3 ]= mem [h + 3 ];
  mem [hh + 4 ]= mem [h + 4 ];
  mem [hh + 5 ].hhfield .lhfield = mem [hh + 1 ].hhfield .v.RH + 1 ;
  mem [hh + 5 ].hhfield .v.RH = hh ;
  p = mem [h ].hhfield .v.RH ;
  qq = hh ;
  while ( p != h ) {
      
    pp = getnode ( 2 ) ;
    mem [qq ].hhfield .v.RH = pp ;
    mem [pp ].hhfield .lhfield = qq ;
    r = mem [p + 1 ].hhfield .v.RH ;
    rr = pp + 1 ;
    while ( r != memtop ) {
	
      ss = getavail () ;
      mem [rr ].hhfield .v.RH = ss ;
      rr = ss ;
      mem [rr ].hhfield .lhfield = mem [r ].hhfield .lhfield ;
      r = mem [r ].hhfield .v.RH ;
    } 
    mem [rr ].hhfield .v.RH = memtop ;
    r = mem [p + 1 ].hhfield .lhfield ;
    rr = memtop - 1 ;
    while ( r > 1 ) {
	
      ss = getavail () ;
      mem [rr ].hhfield .v.RH = ss ;
      rr = ss ;
      mem [rr ].hhfield .lhfield = mem [r ].hhfield .lhfield ;
      r = mem [r ].hhfield .v.RH ;
    } 
    mem [rr ].hhfield .v.RH = r ;
    mem [pp + 1 ].hhfield .lhfield = mem [memtop - 1 ].hhfield .v.RH ;
    p = mem [p ].hhfield .v.RH ;
    qq = pp ;
  } 
  mem [qq ].hhfield .v.RH = hh ;
  mem [hh ].hhfield .lhfield = qq ;
  Result = hh ;
  return Result ;
} 
void 
yreflectedges ( void ) 
{
  halfword p, q, r  ;
  p = mem [curedges + 1 ].hhfield .lhfield ;
  mem [curedges + 1 ].hhfield .lhfield = 8191 - mem [curedges + 1 ]
  .hhfield .v.RH ;
  mem [curedges + 1 ].hhfield .v.RH = 8191 - p ;
  mem [curedges + 5 ].hhfield .lhfield = 8191 - mem [curedges + 5 ]
  .hhfield .lhfield ;
  p = mem [curedges ].hhfield .v.RH ;
  q = curedges ;
  do {
      r = mem [p ].hhfield .v.RH ;
    mem [p ].hhfield .v.RH = q ;
    mem [q ].hhfield .lhfield = p ;
    q = p ;
    p = r ;
  } while ( ! ( q == curedges ) ) ;
  mem [curedges + 4 ].cint = 0 ;
} 
void 
xreflectedges ( void ) 
{
  halfword p, q, r, s  ;
  integer m  ;
  p = mem [curedges + 2 ].hhfield .lhfield ;
  mem [curedges + 2 ].hhfield .lhfield = 8192 - mem [curedges + 2 ]
  .hhfield .v.RH ;
  mem [curedges + 2 ].hhfield .v.RH = 8192 - p ;
  m = ( 4096 + mem [curedges + 3 ].hhfield .lhfield ) * 8 + 8 ;
  mem [curedges + 3 ].hhfield .lhfield = 4096 ;
  p = mem [curedges ].hhfield .v.RH ;
  do {
      q = mem [p + 1 ].hhfield .v.RH ;
    r = memtop ;
    while ( q != memtop ) {
	
      s = mem [q ].hhfield .v.RH ;
      mem [q ].hhfield .v.RH = r ;
      r = q ;
      mem [r ].hhfield .lhfield = m - mem [q ].hhfield .lhfield ;
      q = s ;
    } 
    mem [p + 1 ].hhfield .v.RH = r ;
    q = mem [p + 1 ].hhfield .lhfield ;
    while ( q > 1 ) {
	
      mem [q ].hhfield .lhfield = m - mem [q ].hhfield .lhfield ;
      q = mem [q ].hhfield .v.RH ;
    } 
    p = mem [p ].hhfield .v.RH ;
  } while ( ! ( p == curedges ) ) ;
  mem [curedges + 4 ].cint = 0 ;
} 
void 
zyscaleedges ( integer s ) 
{
  halfword p, q, pp, r, rr, ss  ;
  integer t  ;
  if ( ( s * ( mem [curedges + 1 ].hhfield .v.RH - 4095 ) >= 4096 ) || ( s * 
  ( mem [curedges + 1 ].hhfield .lhfield - 4096 ) <= -4096 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 535 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 535 ) ;
      } 
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 536 ;
      helpline [1 ]= 537 ;
      helpline [0 ]= 538 ;
    } 
    putgeterror () ;
  } 
  else {
      
    mem [curedges + 1 ].hhfield .v.RH = s * ( mem [curedges + 1 ].hhfield 
    .v.RH - 4095 ) + 4095 ;
    mem [curedges + 1 ].hhfield .lhfield = s * ( mem [curedges + 1 ]
    .hhfield .lhfield - 4096 ) + 4096 ;
    p = curedges ;
    do {
	q = p ;
      p = mem [p ].hhfield .v.RH ;
      {register integer for_end; t = 2 ;for_end = s ; if ( t <= for_end) do 
	{
	  pp = getnode ( 2 ) ;
	  mem [q ].hhfield .v.RH = pp ;
	  mem [p ].hhfield .lhfield = pp ;
	  mem [pp ].hhfield .v.RH = p ;
	  mem [pp ].hhfield .lhfield = q ;
	  q = pp ;
	  r = mem [p + 1 ].hhfield .v.RH ;
	  rr = pp + 1 ;
	  while ( r != memtop ) {
	      
	    ss = getavail () ;
	    mem [rr ].hhfield .v.RH = ss ;
	    rr = ss ;
	    mem [rr ].hhfield .lhfield = mem [r ].hhfield .lhfield ;
	    r = mem [r ].hhfield .v.RH ;
	  } 
	  mem [rr ].hhfield .v.RH = memtop ;
	  r = mem [p + 1 ].hhfield .lhfield ;
	  rr = memtop - 1 ;
	  while ( r > 1 ) {
	      
	    ss = getavail () ;
	    mem [rr ].hhfield .v.RH = ss ;
	    rr = ss ;
	    mem [rr ].hhfield .lhfield = mem [r ].hhfield .lhfield ;
	    r = mem [r ].hhfield .v.RH ;
	  } 
	  mem [rr ].hhfield .v.RH = r ;
	  mem [pp + 1 ].hhfield .lhfield = mem [memtop - 1 ].hhfield .v.RH 
	  ;
	} 
      while ( t++ < for_end ) ;} 
    } while ( ! ( mem [p ].hhfield .v.RH == curedges ) ) ;
    mem [curedges + 4 ].cint = 0 ;
  } 
} 
void 
zxscaleedges ( integer s ) 
{
  halfword p, q  ;
  unsigned short t  ;
  unsigned char w  ;
  integer delta  ;
  if ( ( s * ( mem [curedges + 2 ].hhfield .v.RH - 4096 ) >= 4096 ) || ( s * 
  ( mem [curedges + 2 ].hhfield .lhfield - 4096 ) <= -4096 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 535 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 535 ) ;
      } 
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 539 ;
      helpline [1 ]= 537 ;
      helpline [0 ]= 538 ;
    } 
    putgeterror () ;
  } 
  else if ( ( mem [curedges + 2 ].hhfield .v.RH != 4096 ) || ( mem [
  curedges + 2 ].hhfield .lhfield != 4096 ) ) 
  {
    mem [curedges + 2 ].hhfield .v.RH = s * ( mem [curedges + 2 ].hhfield 
    .v.RH - 4096 ) + 4096 ;
    mem [curedges + 2 ].hhfield .lhfield = s * ( mem [curedges + 2 ]
    .hhfield .lhfield - 4096 ) + 4096 ;
    delta = 8 * ( 4096 - s * mem [curedges + 3 ].hhfield .lhfield ) + 0 ;
    mem [curedges + 3 ].hhfield .lhfield = 4096 ;
    q = mem [curedges ].hhfield .v.RH ;
    do {
	p = mem [q + 1 ].hhfield .v.RH ;
      while ( p != memtop ) {
	  
	t = mem [p ].hhfield .lhfield ;
	w = t % 8 ;
	mem [p ].hhfield .lhfield = ( t - w ) * s + w + delta ;
	p = mem [p ].hhfield .v.RH ;
      } 
      p = mem [q + 1 ].hhfield .lhfield ;
      while ( p > 1 ) {
	  
	t = mem [p ].hhfield .lhfield ;
	w = t % 8 ;
	mem [p ].hhfield .lhfield = ( t - w ) * s + w + delta ;
	p = mem [p ].hhfield .v.RH ;
      } 
      q = mem [q ].hhfield .v.RH ;
    } while ( ! ( q == curedges ) ) ;
    mem [curedges + 4 ].cint = 0 ;
  } 
} 
void 
znegateedges ( halfword h ) 
{
  /* 30 */ halfword p, q, r, s, t, u  ;
  p = mem [h ].hhfield .v.RH ;
  while ( p != h ) {
      
    q = mem [p + 1 ].hhfield .lhfield ;
    while ( q > 1 ) {
	
      mem [q ].hhfield .lhfield = 8 - 2 * ( ( mem [q ].hhfield .lhfield ) 
      % 8 ) + mem [q ].hhfield .lhfield ;
      q = mem [q ].hhfield .v.RH ;
    } 
    q = mem [p + 1 ].hhfield .v.RH ;
    if ( q != memtop ) 
    {
      do {
	  mem [q ].hhfield .lhfield = 8 - 2 * ( ( mem [q ].hhfield 
	.lhfield ) % 8 ) + mem [q ].hhfield .lhfield ;
	q = mem [q ].hhfield .v.RH ;
      } while ( ! ( q == memtop ) ) ;
      u = p + 1 ;
      q = mem [u ].hhfield .v.RH ;
      r = q ;
      s = mem [r ].hhfield .v.RH ;
      while ( true ) if ( mem [s ].hhfield .lhfield > mem [r ].hhfield 
      .lhfield ) 
      {
	mem [u ].hhfield .v.RH = q ;
	if ( s == memtop ) 
	goto lab30 ;
	u = r ;
	q = s ;
	r = q ;
	s = mem [r ].hhfield .v.RH ;
      } 
      else {
	  
	t = s ;
	s = mem [t ].hhfield .v.RH ;
	mem [t ].hhfield .v.RH = q ;
	q = t ;
      } 
      lab30: mem [r ].hhfield .v.RH = memtop ;
    } 
    p = mem [p ].hhfield .v.RH ;
  } 
  mem [h + 4 ].cint = 0 ;
} 
void 
zsortedges ( halfword h ) 
{
  /* 30 */ halfword k  ;
  halfword p, q, r, s  ;
  r = mem [h + 1 ].hhfield .lhfield ;
  mem [h + 1 ].hhfield .lhfield = 0 ;
  p = mem [r ].hhfield .v.RH ;
  mem [r ].hhfield .v.RH = memtop ;
  mem [memtop - 1 ].hhfield .v.RH = r ;
  while ( p > 1 ) {
      
    k = mem [p ].hhfield .lhfield ;
    q = memtop - 1 ;
    do {
	r = q ;
      q = mem [r ].hhfield .v.RH ;
    } while ( ! ( k <= mem [q ].hhfield .lhfield ) ) ;
    mem [r ].hhfield .v.RH = p ;
    r = mem [p ].hhfield .v.RH ;
    mem [p ].hhfield .v.RH = q ;
    p = r ;
  } 
  {
    r = h + 1 ;
    q = mem [r ].hhfield .v.RH ;
    p = mem [memtop - 1 ].hhfield .v.RH ;
    while ( true ) {
	
      k = mem [p ].hhfield .lhfield ;
      while ( k > mem [q ].hhfield .lhfield ) {
	  
	r = q ;
	q = mem [r ].hhfield .v.RH ;
      } 
      mem [r ].hhfield .v.RH = p ;
      s = mem [p ].hhfield .v.RH ;
      mem [p ].hhfield .v.RH = q ;
      if ( s == memtop ) 
      goto lab30 ;
      r = p ;
      p = s ;
    } 
    lab30: ;
  } 
} 
void 
zculledges ( integer wlo , integer whi , integer wout , integer win ) 
{
  /* 30 */ halfword p, q, r, s  ;
  integer w  ;
  integer d  ;
  integer m  ;
  integer mm  ;
  integer ww  ;
  integer prevw  ;
  halfword n, minn, maxn  ;
  halfword mind, maxd  ;
  mind = 268435455L ;
  maxd = 0 ;
  minn = 268435455L ;
  maxn = 0 ;
  p = mem [curedges ].hhfield .v.RH ;
  n = mem [curedges + 1 ].hhfield .lhfield ;
  while ( p != curedges ) {
      
    if ( mem [p + 1 ].hhfield .lhfield > 1 ) 
    sortedges ( p ) ;
    if ( mem [p + 1 ].hhfield .v.RH != memtop ) 
    {
      r = memtop - 1 ;
      q = mem [p + 1 ].hhfield .v.RH ;
      ww = 0 ;
      m = 1000000L ;
      prevw = 0 ;
      while ( true ) {
	  
	if ( q == memtop ) 
	mm = 1000000L ;
	else {
	    
	  d = mem [q ].hhfield .lhfield ;
	  mm = d / 8 ;
	  ww = ww + ( d % 8 ) - 4 ;
	} 
	if ( mm > m ) 
	{
	  if ( w != prevw ) 
	  {
	    s = getavail () ;
	    mem [r ].hhfield .v.RH = s ;
	    mem [s ].hhfield .lhfield = 8 * m + 4 + w - prevw ;
	    r = s ;
	    prevw = w ;
	  } 
	  if ( q == memtop ) 
	  goto lab30 ;
	} 
	m = mm ;
	if ( ww >= wlo ) {
	    
	  if ( ww <= whi ) 
	  w = win ;
	  else w = wout ;
	} 
	else w = wout ;
	s = mem [q ].hhfield .v.RH ;
	{
	  mem [q ].hhfield .v.RH = avail ;
	  avail = q ;
	;
#ifdef STAT
	  decr ( dynused ) ;
#endif /* STAT */
	} 
	q = s ;
      } 
      lab30: mem [r ].hhfield .v.RH = memtop ;
      mem [p + 1 ].hhfield .v.RH = mem [memtop - 1 ].hhfield .v.RH ;
      if ( r != memtop - 1 ) 
      {
	if ( minn == 268435455L ) 
	minn = n ;
	maxn = n ;
	if ( mind > mem [mem [memtop - 1 ].hhfield .v.RH ].hhfield 
	.lhfield ) 
	mind = mem [mem [memtop - 1 ].hhfield .v.RH ].hhfield .lhfield ;
	if ( maxd < mem [r ].hhfield .lhfield ) 
	maxd = mem [r ].hhfield .lhfield ;
      } 
    } 
    p = mem [p ].hhfield .v.RH ;
    incr ( n ) ;
  } 
  if ( minn > maxn ) 
  {
    p = mem [curedges ].hhfield .v.RH ;
    while ( p != curedges ) {
	
      q = mem [p ].hhfield .v.RH ;
      freenode ( p , 2 ) ;
      p = q ;
    } 
    initedges ( curedges ) ;
  } 
  else {
      
    n = mem [curedges + 1 ].hhfield .lhfield ;
    mem [curedges + 1 ].hhfield .lhfield = minn ;
    while ( minn > n ) {
	
      p = mem [curedges ].hhfield .v.RH ;
      mem [curedges ].hhfield .v.RH = mem [p ].hhfield .v.RH ;
      mem [mem [p ].hhfield .v.RH ].hhfield .lhfield = curedges ;
      freenode ( p , 2 ) ;
      incr ( n ) ;
    } 
    n = mem [curedges + 1 ].hhfield .v.RH ;
    mem [curedges + 1 ].hhfield .v.RH = maxn ;
    mem [curedges + 5 ].hhfield .lhfield = maxn + 1 ;
    mem [curedges + 5 ].hhfield .v.RH = curedges ;
    while ( maxn < n ) {
	
      p = mem [curedges ].hhfield .lhfield ;
      mem [curedges ].hhfield .lhfield = mem [p ].hhfield .lhfield ;
      mem [mem [p ].hhfield .lhfield ].hhfield .v.RH = curedges ;
      freenode ( p , 2 ) ;
      decr ( n ) ;
    } 
    mem [curedges + 2 ].hhfield .lhfield = ( ( mind ) / 8 ) - mem [curedges 
    + 3 ].hhfield .lhfield + 4096 ;
    mem [curedges + 2 ].hhfield .v.RH = ( ( maxd ) / 8 ) - mem [curedges + 
    3 ].hhfield .lhfield + 4096 ;
  } 
  mem [curedges + 4 ].cint = 0 ;
} 
void 
xyswapedges ( void ) 
{
  /* 30 */ integer mmagic, nmagic  ;
  halfword p, q, r, s  ;
  integer mspread  ;
  integer j, jj  ;
  integer m, mm  ;
  integer pd, rd  ;
  integer pm, rm  ;
  integer w  ;
  integer ww  ;
  integer dw  ;
  integer extras  ;
  schar xw  ;
  integer k  ;
  mspread = mem [curedges + 2 ].hhfield .v.RH - mem [curedges + 2 ]
  .hhfield .lhfield ;
  if ( mspread > movesize ) 
  overflow ( 540 , movesize ) ;
  {register integer for_end; j = 0 ;for_end = mspread ; if ( j <= for_end) 
  do 
    move [j ]= memtop ;
  while ( j++ < for_end ) ;} 
  p = getnode ( 2 ) ;
  mem [p + 1 ].hhfield .v.RH = memtop ;
  mem [p + 1 ].hhfield .lhfield = 0 ;
  mem [p ].hhfield .lhfield = curedges ;
  mem [mem [curedges ].hhfield .v.RH ].hhfield .lhfield = p ;
  p = getnode ( 2 ) ;
  mem [p + 1 ].hhfield .v.RH = memtop ;
  mem [p ].hhfield .lhfield = mem [curedges ].hhfield .lhfield ;
  mmagic = mem [curedges + 2 ].hhfield .lhfield + mem [curedges + 3 ]
  .hhfield .lhfield - 4096 ;
  nmagic = 8 * mem [curedges + 1 ].hhfield .v.RH + 12 ;
  do {
      q = mem [p ].hhfield .lhfield ;
    if ( mem [q + 1 ].hhfield .lhfield > 1 ) 
    sortedges ( q ) ;
    r = mem [p + 1 ].hhfield .v.RH ;
    freenode ( p , 2 ) ;
    p = r ;
    pd = mem [p ].hhfield .lhfield ;
    pm = pd / 8 ;
    r = mem [q + 1 ].hhfield .v.RH ;
    rd = mem [r ].hhfield .lhfield ;
    rm = rd / 8 ;
    w = 0 ;
    while ( true ) {
	
      if ( pm < rm ) 
      mm = pm ;
      else mm = rm ;
      if ( w != 0 ) {
	  
	if ( m != mm ) 
	{
	  if ( mm - mmagic >= movesize ) 
	  confusion ( 510 ) ;
	  extras = ( abs ( w ) - 1 ) / 3 ;
	  if ( extras > 0 ) 
	  {
	    if ( w > 0 ) 
	    xw = 3 ;
	    else xw = -3 ;
	    ww = w - extras * xw ;
	  } 
	  else ww = w ;
	  do {
	      j = m - mmagic ;
	    {register integer for_end; k = 1 ;for_end = extras ; if ( k <= 
	    for_end) do 
	      {
		s = getavail () ;
		mem [s ].hhfield .lhfield = nmagic + xw ;
		mem [s ].hhfield .v.RH = move [j ];
		move [j ]= s ;
	      } 
	    while ( k++ < for_end ) ;} 
	    s = getavail () ;
	    mem [s ].hhfield .lhfield = nmagic + ww ;
	    mem [s ].hhfield .v.RH = move [j ];
	    move [j ]= s ;
	    incr ( m ) ;
	  } while ( ! ( m == mm ) ) ;
	} 
      } 
      if ( pd < rd ) 
      {
	dw = ( pd % 8 ) - 4 ;
	s = mem [p ].hhfield .v.RH ;
	{
	  mem [p ].hhfield .v.RH = avail ;
	  avail = p ;
	;
#ifdef STAT
	  decr ( dynused ) ;
#endif /* STAT */
	} 
	p = s ;
	pd = mem [p ].hhfield .lhfield ;
	pm = pd / 8 ;
      } 
      else {
	  
	if ( r == memtop ) 
	goto lab30 ;
	dw = - (integer) ( ( rd % 8 ) - 4 ) ;
	r = mem [r ].hhfield .v.RH ;
	rd = mem [r ].hhfield .lhfield ;
	rm = rd / 8 ;
      } 
      m = mm ;
      w = w + dw ;
    } 
    lab30: ;
    p = q ;
    nmagic = nmagic - 8 ;
  } while ( ! ( mem [p ].hhfield .lhfield == curedges ) ) ;
  freenode ( p , 2 ) ;
  move [mspread ]= 0 ;
  j = 0 ;
  while ( move [j ]== memtop ) incr ( j ) ;
  if ( j == mspread ) 
  initedges ( curedges ) ;
  else {
      
    mm = mem [curedges + 2 ].hhfield .lhfield ;
    mem [curedges + 2 ].hhfield .lhfield = mem [curedges + 1 ].hhfield 
    .lhfield ;
    mem [curedges + 2 ].hhfield .v.RH = mem [curedges + 1 ].hhfield .v.RH 
    + 1 ;
    mem [curedges + 3 ].hhfield .lhfield = 4096 ;
    jj = mspread - 1 ;
    while ( move [jj ]== memtop ) decr ( jj ) ;
    mem [curedges + 1 ].hhfield .lhfield = j + mm ;
    mem [curedges + 1 ].hhfield .v.RH = jj + mm ;
    q = curedges ;
    do {
	p = getnode ( 2 ) ;
      mem [q ].hhfield .v.RH = p ;
      mem [p ].hhfield .lhfield = q ;
      mem [p + 1 ].hhfield .v.RH = move [j ];
      mem [p + 1 ].hhfield .lhfield = 0 ;
      incr ( j ) ;
      q = p ;
    } while ( ! ( j > jj ) ) ;
    mem [q ].hhfield .v.RH = curedges ;
    mem [curedges ].hhfield .lhfield = q ;
    mem [curedges + 5 ].hhfield .lhfield = mem [curedges + 1 ].hhfield 
    .v.RH + 1 ;
    mem [curedges + 5 ].hhfield .v.RH = curedges ;
    mem [curedges + 4 ].cint = 0 ;
  } 
} 
void 
zmergeedges ( halfword h ) 
{
  /* 30 */ halfword p, q, r, pp, qq, rr  ;
  integer n  ;
  halfword k  ;
  integer delta  ;
  if ( mem [h ].hhfield .v.RH != h ) 
  {
    if ( ( mem [h + 2 ].hhfield .lhfield < mem [curedges + 2 ].hhfield 
    .lhfield ) || ( mem [h + 2 ].hhfield .v.RH > mem [curedges + 2 ]
    .hhfield .v.RH ) || ( mem [h + 1 ].hhfield .lhfield < mem [curedges + 1 
    ].hhfield .lhfield ) || ( mem [h + 1 ].hhfield .v.RH > mem [curedges + 
    1 ].hhfield .v.RH ) ) 
    edgeprep ( mem [h + 2 ].hhfield .lhfield - 4096 , mem [h + 2 ].hhfield 
    .v.RH - 4096 , mem [h + 1 ].hhfield .lhfield - 4096 , mem [h + 1 ]
    .hhfield .v.RH - 4095 ) ;
    if ( mem [h + 3 ].hhfield .lhfield != mem [curedges + 3 ].hhfield 
    .lhfield ) 
    {
      pp = mem [h ].hhfield .v.RH ;
      delta = 8 * ( mem [curedges + 3 ].hhfield .lhfield - mem [h + 3 ]
      .hhfield .lhfield ) ;
      do {
	  qq = mem [pp + 1 ].hhfield .v.RH ;
	while ( qq != memtop ) {
	    
	  mem [qq ].hhfield .lhfield = mem [qq ].hhfield .lhfield + delta 
	  ;
	  qq = mem [qq ].hhfield .v.RH ;
	} 
	qq = mem [pp + 1 ].hhfield .lhfield ;
	while ( qq > 1 ) {
	    
	  mem [qq ].hhfield .lhfield = mem [qq ].hhfield .lhfield + delta 
	  ;
	  qq = mem [qq ].hhfield .v.RH ;
	} 
	pp = mem [pp ].hhfield .v.RH ;
      } while ( ! ( pp == h ) ) ;
    } 
    n = mem [curedges + 1 ].hhfield .lhfield ;
    p = mem [curedges ].hhfield .v.RH ;
    pp = mem [h ].hhfield .v.RH ;
    while ( n < mem [h + 1 ].hhfield .lhfield ) {
	
      incr ( n ) ;
      p = mem [p ].hhfield .v.RH ;
    } 
    do {
	qq = mem [pp + 1 ].hhfield .lhfield ;
      if ( qq > 1 ) {
	  
	if ( mem [p + 1 ].hhfield .lhfield <= 1 ) 
	mem [p + 1 ].hhfield .lhfield = qq ;
	else {
	    
	  while ( mem [qq ].hhfield .v.RH > 1 ) qq = mem [qq ].hhfield 
	  .v.RH ;
	  mem [qq ].hhfield .v.RH = mem [p + 1 ].hhfield .lhfield ;
	  mem [p + 1 ].hhfield .lhfield = mem [pp + 1 ].hhfield .lhfield ;
	} 
      } 
      mem [pp + 1 ].hhfield .lhfield = 0 ;
      qq = mem [pp + 1 ].hhfield .v.RH ;
      if ( qq != memtop ) 
      {
	if ( mem [p + 1 ].hhfield .lhfield == 1 ) 
	mem [p + 1 ].hhfield .lhfield = 0 ;
	mem [pp + 1 ].hhfield .v.RH = memtop ;
	r = p + 1 ;
	q = mem [r ].hhfield .v.RH ;
	if ( q == memtop ) 
	mem [p + 1 ].hhfield .v.RH = qq ;
	else while ( true ) {
	    
	  k = mem [qq ].hhfield .lhfield ;
	  while ( k > mem [q ].hhfield .lhfield ) {
	      
	    r = q ;
	    q = mem [r ].hhfield .v.RH ;
	  } 
	  mem [r ].hhfield .v.RH = qq ;
	  rr = mem [qq ].hhfield .v.RH ;
	  mem [qq ].hhfield .v.RH = q ;
	  if ( rr == memtop ) 
	  goto lab30 ;
	  r = qq ;
	  qq = rr ;
	} 
      } 
      lab30: ;
      pp = mem [pp ].hhfield .v.RH ;
      p = mem [p ].hhfield .v.RH ;
    } while ( ! ( pp == h ) ) ;
  } 
} 
integer 
ztotalweight ( halfword h ) 
{
  register integer Result; halfword p, q  ;
  integer n  ;
  unsigned short m  ;
  n = 0 ;
  p = mem [h ].hhfield .v.RH ;
  while ( p != h ) {
      
    q = mem [p + 1 ].hhfield .v.RH ;
    while ( q != memtop ) {
	
      m = mem [q ].hhfield .lhfield ;
      n = n - ( ( m % 8 ) - 4 ) * ( m / 8 ) ;
      q = mem [q ].hhfield .v.RH ;
    } 
    q = mem [p + 1 ].hhfield .lhfield ;
    while ( q > 1 ) {
	
      m = mem [q ].hhfield .lhfield ;
      n = n - ( ( m % 8 ) - 4 ) * ( m / 8 ) ;
      q = mem [q ].hhfield .v.RH ;
    } 
    p = mem [p ].hhfield .v.RH ;
  } 
  Result = n ;
  return Result ;
} 
void 
beginedgetracing ( void ) 
{
  printdiagnostic ( 541 , 261 , true ) ;
  print ( 542 ) ;
  printint ( curwt ) ;
  printchar ( 41 ) ;
  tracex = -4096 ;
} 
void 
traceacorner ( void ) 
{
  if ( fileoffset > maxprintline - 13 ) 
  printnl ( 261 ) ;
  printchar ( 40 ) ;
  printint ( tracex ) ;
  printchar ( 44 ) ;
  printint ( traceyy ) ;
  printchar ( 41 ) ;
  tracey = traceyy ;
} 
void 
endedgetracing ( void ) 
{
  if ( tracex == -4096 ) 
  printnl ( 543 ) ;
  else {
      
    traceacorner () ;
    printchar ( 46 ) ;
  } 
  enddiagnostic ( true ) ;
} 
void 
ztracenewedge ( halfword r , integer n ) 
{
  integer d  ;
  schar w  ;
  integer m, n0, n1  ;
  d = mem [r ].hhfield .lhfield ;
  w = ( d % 8 ) - 4 ;
  m = ( d / 8 ) - mem [curedges + 3 ].hhfield .lhfield ;
  if ( w == curwt ) 
  {
    n0 = n + 1 ;
    n1 = n ;
  } 
  else {
      
    n0 = n ;
    n1 = n + 1 ;
  } 
  if ( m != tracex ) 
  {
    if ( tracex == -4096 ) 
    {
      printnl ( 261 ) ;
      traceyy = n0 ;
    } 
    else if ( traceyy != n0 ) 
    printchar ( 63 ) ;
    else traceacorner () ;
    tracex = m ;
    traceacorner () ;
  } 
  else {
      
    if ( n0 != traceyy ) 
    printchar ( 33 ) ;
    if ( ( ( n0 < n1 ) && ( tracey > traceyy ) ) || ( ( n0 > n1 ) && ( tracey 
    < traceyy ) ) ) 
    traceacorner () ;
  } 
  traceyy = n1 ;
} 
void 
zlineedges ( scaled x0 , scaled y0 , scaled x1 , scaled y1 ) 
{
  /* 30 31 */ integer m0, n0, m1, n1  ;
  scaled delx, dely  ;
  scaled yt  ;
  scaled tx  ;
  halfword p, r  ;
  integer base  ;
  integer n  ;
  n0 = roundunscaled ( y0 ) ;
  n1 = roundunscaled ( y1 ) ;
  if ( n0 != n1 ) 
  {
    m0 = roundunscaled ( x0 ) ;
    m1 = roundunscaled ( x1 ) ;
    delx = x1 - x0 ;
    dely = y1 - y0 ;
    yt = n0 * 65536L - 32768L ;
    y0 = y0 - yt ;
    y1 = y1 - yt ;
    if ( n0 < n1 ) 
    {
      base = 8 * mem [curedges + 3 ].hhfield .lhfield + 4 - curwt ;
      if ( m0 <= m1 ) 
      edgeprep ( m0 , m1 , n0 , n1 ) ;
      else edgeprep ( m1 , m0 , n0 , n1 ) ;
      n = mem [curedges + 5 ].hhfield .lhfield - 4096 ;
      p = mem [curedges + 5 ].hhfield .v.RH ;
      if ( n != n0 ) {
	  
	if ( n < n0 ) 
	do {
	    incr ( n ) ;
	  p = mem [p ].hhfield .v.RH ;
	} while ( ! ( n == n0 ) ) ;
	else do {
	    decr ( n ) ;
	  p = mem [p ].hhfield .lhfield ;
	} while ( ! ( n == n0 ) ) ;
      } 
      y0 = 65536L - y0 ;
      while ( true ) {
	  
	r = getavail () ;
	mem [r ].hhfield .v.RH = mem [p + 1 ].hhfield .lhfield ;
	mem [p + 1 ].hhfield .lhfield = r ;
	tx = takefraction ( delx , makefraction ( y0 , dely ) ) ;
	if ( abvscd ( delx , y0 , dely , tx ) < 0 ) 
	decr ( tx ) ;
	mem [r ].hhfield .lhfield = 8 * roundunscaled ( x0 + tx ) + base ;
	y1 = y1 - 65536L ;
	if ( internal [10 ]> 0 ) 
	tracenewedge ( r , n ) ;
	if ( y1 < 65536L ) 
	goto lab30 ;
	p = mem [p ].hhfield .v.RH ;
	y0 = y0 + 65536L ;
	incr ( n ) ;
      } 
      lab30: ;
    } 
    else {
	
      base = 8 * mem [curedges + 3 ].hhfield .lhfield + 4 + curwt ;
      if ( m0 <= m1 ) 
      edgeprep ( m0 , m1 , n1 , n0 ) ;
      else edgeprep ( m1 , m0 , n1 , n0 ) ;
      decr ( n0 ) ;
      n = mem [curedges + 5 ].hhfield .lhfield - 4096 ;
      p = mem [curedges + 5 ].hhfield .v.RH ;
      if ( n != n0 ) {
	  
	if ( n < n0 ) 
	do {
	    incr ( n ) ;
	  p = mem [p ].hhfield .v.RH ;
	} while ( ! ( n == n0 ) ) ;
	else do {
	    decr ( n ) ;
	  p = mem [p ].hhfield .lhfield ;
	} while ( ! ( n == n0 ) ) ;
      } 
      while ( true ) {
	  
	r = getavail () ;
	mem [r ].hhfield .v.RH = mem [p + 1 ].hhfield .lhfield ;
	mem [p + 1 ].hhfield .lhfield = r ;
	tx = takefraction ( delx , makefraction ( y0 , dely ) ) ;
	if ( abvscd ( delx , y0 , dely , tx ) < 0 ) 
	incr ( tx ) ;
	mem [r ].hhfield .lhfield = 8 * roundunscaled ( x0 - tx ) + base ;
	y1 = y1 + 65536L ;
	if ( internal [10 ]> 0 ) 
	tracenewedge ( r , n ) ;
	if ( y1 >= 0 ) 
	goto lab31 ;
	p = mem [p ].hhfield .lhfield ;
	y0 = y0 + 65536L ;
	decr ( n ) ;
      } 
      lab31: ;
    } 
    mem [curedges + 5 ].hhfield .v.RH = p ;
    mem [curedges + 5 ].hhfield .lhfield = n + 4096 ;
  } 
} 
void 
zmovetoedges ( integer m0 , integer n0 , integer m1 , integer n1 ) 
{
  /* 60 61 62 63 30 */ integer delta  ;
  integer k  ;
  halfword p, r  ;
  integer dx  ;
  integer edgeandweight  ;
  integer j  ;
  integer n  ;
#ifdef TEXMF_DEBUG
  integer sum  ;
#endif /* TEXMF_DEBUG */
  delta = n1 - n0 ;
	;
#ifdef TEXMF_DEBUG
  sum = move [0 ];
  {register integer for_end; k = 1 ;for_end = delta ; if ( k <= for_end) do 
    sum = sum + abs ( move [k ]) ;
  while ( k++ < for_end ) ;} 
  if ( sum != m1 - m0 ) 
  confusion ( 48 ) ;
#endif /* TEXMF_DEBUG */
  switch ( octant ) 
  {case 1 : 
    {
      dx = 8 ;
      edgeprep ( m0 , m1 , n0 , n1 ) ;
      goto lab60 ;
    } 
    break ;
  case 5 : 
    {
      dx = 8 ;
      edgeprep ( n0 , n1 , m0 , m1 ) ;
      goto lab62 ;
    } 
    break ;
  case 6 : 
    {
      dx = -8 ;
      edgeprep ( - (integer) n1 , - (integer) n0 , m0 , m1 ) ;
      n0 = - (integer) n0 ;
      goto lab62 ;
    } 
    break ;
  case 2 : 
    {
      dx = -8 ;
      edgeprep ( - (integer) m1 , - (integer) m0 , n0 , n1 ) ;
      m0 = - (integer) m0 ;
      goto lab60 ;
    } 
    break ;
  case 4 : 
    {
      dx = -8 ;
      edgeprep ( - (integer) m1 , - (integer) m0 , - (integer) n1 , 
      - (integer) n0 ) ;
      m0 = - (integer) m0 ;
      goto lab61 ;
    } 
    break ;
  case 8 : 
    {
      dx = -8 ;
      edgeprep ( - (integer) n1 , - (integer) n0 , - (integer) m1 , 
      - (integer) m0 ) ;
      n0 = - (integer) n0 ;
      goto lab63 ;
    } 
    break ;
  case 7 : 
    {
      dx = 8 ;
      edgeprep ( n0 , n1 , - (integer) m1 , - (integer) m0 ) ;
      goto lab63 ;
    } 
    break ;
  case 3 : 
    {
      dx = 8 ;
      edgeprep ( m0 , m1 , - (integer) n1 , - (integer) n0 ) ;
      goto lab61 ;
    } 
    break ;
  } 
  lab60: n = mem [curedges + 5 ].hhfield .lhfield - 4096 ;
  p = mem [curedges + 5 ].hhfield .v.RH ;
  if ( n != n0 ) {
      
    if ( n < n0 ) 
    do {
	incr ( n ) ;
      p = mem [p ].hhfield .v.RH ;
    } while ( ! ( n == n0 ) ) ;
    else do {
	decr ( n ) ;
      p = mem [p ].hhfield .lhfield ;
    } while ( ! ( n == n0 ) ) ;
  } 
  if ( delta > 0 ) 
  {
    k = 0 ;
    edgeandweight = 8 * ( m0 + mem [curedges + 3 ].hhfield .lhfield ) + 4 - 
    curwt ;
    do {
	edgeandweight = edgeandweight + dx * move [k ];
      {
	r = avail ;
	if ( r == 0 ) 
	r = getavail () ;
	else {
	    
	  avail = mem [r ].hhfield .v.RH ;
	  mem [r ].hhfield .v.RH = 0 ;
	;
#ifdef STAT
	  incr ( dynused ) ;
#endif /* STAT */
	} 
      } 
      mem [r ].hhfield .v.RH = mem [p + 1 ].hhfield .lhfield ;
      mem [r ].hhfield .lhfield = edgeandweight ;
      if ( internal [10 ]> 0 ) 
      tracenewedge ( r , n ) ;
      mem [p + 1 ].hhfield .lhfield = r ;
      p = mem [p ].hhfield .v.RH ;
      incr ( k ) ;
      incr ( n ) ;
    } while ( ! ( k == delta ) ) ;
  } 
  goto lab30 ;
  lab61: n0 = - (integer) n0 - 1 ;
  n = mem [curedges + 5 ].hhfield .lhfield - 4096 ;
  p = mem [curedges + 5 ].hhfield .v.RH ;
  if ( n != n0 ) {
      
    if ( n < n0 ) 
    do {
	incr ( n ) ;
      p = mem [p ].hhfield .v.RH ;
    } while ( ! ( n == n0 ) ) ;
    else do {
	decr ( n ) ;
      p = mem [p ].hhfield .lhfield ;
    } while ( ! ( n == n0 ) ) ;
  } 
  if ( delta > 0 ) 
  {
    k = 0 ;
    edgeandweight = 8 * ( m0 + mem [curedges + 3 ].hhfield .lhfield ) + 4 + 
    curwt ;
    do {
	edgeandweight = edgeandweight + dx * move [k ];
      {
	r = avail ;
	if ( r == 0 ) 
	r = getavail () ;
	else {
	    
	  avail = mem [r ].hhfield .v.RH ;
	  mem [r ].hhfield .v.RH = 0 ;
	;
#ifdef STAT
	  incr ( dynused ) ;
#endif /* STAT */
	} 
      } 
      mem [r ].hhfield .v.RH = mem [p + 1 ].hhfield .lhfield ;
      mem [r ].hhfield .lhfield = edgeandweight ;
      if ( internal [10 ]> 0 ) 
      tracenewedge ( r , n ) ;
      mem [p + 1 ].hhfield .lhfield = r ;
      p = mem [p ].hhfield .lhfield ;
      incr ( k ) ;
      decr ( n ) ;
    } while ( ! ( k == delta ) ) ;
  } 
  goto lab30 ;
  lab62: edgeandweight = 8 * ( n0 + mem [curedges + 3 ].hhfield .lhfield ) + 
  4 - curwt ;
  n0 = m0 ;
  k = 0 ;
  n = mem [curedges + 5 ].hhfield .lhfield - 4096 ;
  p = mem [curedges + 5 ].hhfield .v.RH ;
  if ( n != n0 ) {
      
    if ( n < n0 ) 
    do {
	incr ( n ) ;
      p = mem [p ].hhfield .v.RH ;
    } while ( ! ( n == n0 ) ) ;
    else do {
	decr ( n ) ;
      p = mem [p ].hhfield .lhfield ;
    } while ( ! ( n == n0 ) ) ;
  } 
  do {
      j = move [k ];
    while ( j > 0 ) {
	
      {
	r = avail ;
	if ( r == 0 ) 
	r = getavail () ;
	else {
	    
	  avail = mem [r ].hhfield .v.RH ;
	  mem [r ].hhfield .v.RH = 0 ;
	;
#ifdef STAT
	  incr ( dynused ) ;
#endif /* STAT */
	} 
      } 
      mem [r ].hhfield .v.RH = mem [p + 1 ].hhfield .lhfield ;
      mem [r ].hhfield .lhfield = edgeandweight ;
      if ( internal [10 ]> 0 ) 
      tracenewedge ( r , n ) ;
      mem [p + 1 ].hhfield .lhfield = r ;
      p = mem [p ].hhfield .v.RH ;
      decr ( j ) ;
      incr ( n ) ;
    } 
    edgeandweight = edgeandweight + dx ;
    incr ( k ) ;
  } while ( ! ( k > delta ) ) ;
  goto lab30 ;
  lab63: edgeandweight = 8 * ( n0 + mem [curedges + 3 ].hhfield .lhfield ) + 
  4 + curwt ;
  n0 = - (integer) m0 - 1 ;
  k = 0 ;
  n = mem [curedges + 5 ].hhfield .lhfield - 4096 ;
  p = mem [curedges + 5 ].hhfield .v.RH ;
  if ( n != n0 ) {
      
    if ( n < n0 ) 
    do {
	incr ( n ) ;
      p = mem [p ].hhfield .v.RH ;
    } while ( ! ( n == n0 ) ) ;
    else do {
	decr ( n ) ;
      p = mem [p ].hhfield .lhfield ;
    } while ( ! ( n == n0 ) ) ;
  } 
  do {
      j = move [k ];
    while ( j > 0 ) {
	
      {
	r = avail ;
	if ( r == 0 ) 
	r = getavail () ;
	else {
	    
	  avail = mem [r ].hhfield .v.RH ;
	  mem [r ].hhfield .v.RH = 0 ;
	;
#ifdef STAT
	  incr ( dynused ) ;
#endif /* STAT */
	} 
      } 
      mem [r ].hhfield .v.RH = mem [p + 1 ].hhfield .lhfield ;
      mem [r ].hhfield .lhfield = edgeandweight ;
      if ( internal [10 ]> 0 ) 
      tracenewedge ( r , n ) ;
      mem [p + 1 ].hhfield .lhfield = r ;
      p = mem [p ].hhfield .lhfield ;
      decr ( j ) ;
      decr ( n ) ;
    } 
    edgeandweight = edgeandweight + dx ;
    incr ( k ) ;
  } while ( ! ( k > delta ) ) ;
  goto lab30 ;
  lab30: mem [curedges + 5 ].hhfield .lhfield = n + 4096 ;
  mem [curedges + 5 ].hhfield .v.RH = p ;
} 
void 
zskew ( scaled x , scaled y , smallnumber octant ) 
{
  switch ( octant ) 
  {case 1 : 
    {
      curx = x - y ;
      cury = y ;
    } 
    break ;
  case 5 : 
    {
      curx = y - x ;
      cury = x ;
    } 
    break ;
  case 6 : 
    {
      curx = y + x ;
      cury = - (integer) x ;
    } 
    break ;
  case 2 : 
    {
      curx = - (integer) x - y ;
      cury = y ;
    } 
    break ;
  case 4 : 
    {
      curx = - (integer) x + y ;
      cury = - (integer) y ;
    } 
    break ;
  case 8 : 
    {
      curx = - (integer) y + x ;
      cury = - (integer) x ;
    } 
    break ;
  case 7 : 
    {
      curx = - (integer) y - x ;
      cury = x ;
    } 
    break ;
  case 3 : 
    {
      curx = x + y ;
      cury = - (integer) y ;
    } 
    break ;
  } 
} 
void 
zabnegate ( scaled x , scaled y , smallnumber octantbefore , smallnumber 
octantafter ) 
{
  if ( odd ( octantbefore ) == odd ( octantafter ) ) 
  curx = x ;
  else curx = - (integer) x ;
  if ( ( octantbefore > 2 ) == ( octantafter > 2 ) ) 
  cury = y ;
  else cury = - (integer) y ;
} 
fraction 
zcrossingpoint ( integer a , integer b , integer c ) 
{
  /* 10 */ register fraction Result; integer d  ;
  integer x, xx, x0, x1, x2  ;
  if ( a < 0 ) 
  {
    Result = 0 ;
    goto lab10 ;
  } 
  if ( c >= 0 ) 
  {
    if ( b >= 0 ) {
	
      if ( c > 0 ) 
      {
	Result = 268435457L ;
	goto lab10 ;
      } 
      else if ( ( a == 0 ) && ( b == 0 ) ) 
      {
	Result = 268435457L ;
	goto lab10 ;
      } 
      else {
	  
	Result = 268435456L ;
	goto lab10 ;
      } 
    } 
    if ( a == 0 ) 
    {
      Result = 0 ;
      goto lab10 ;
    } 
  } 
  else if ( a == 0 ) {
      
    if ( b <= 0 ) 
    {
      Result = 0 ;
      goto lab10 ;
    } 
  } 
  d = 1 ;
  x0 = a ;
  x1 = a - b ;
  x2 = b - c ;
  do {
      x = half ( x1 + x2 ) ;
    if ( x1 - x0 > x0 ) 
    {
      x2 = x ;
      x0 = x0 + x0 ;
      d = d + d ;
    } 
    else {
	
      xx = x1 + x - x0 ;
      if ( xx > x0 ) 
      {
	x2 = x ;
	x0 = x0 + x0 ;
	d = d + d ;
      } 
      else {
	  
	x0 = x0 - xx ;
	if ( x <= x0 ) {
	    
	  if ( x + x2 <= x0 ) 
	  {
	    Result = 268435457L ;
	    goto lab10 ;
	  } 
	} 
	x1 = x ;
	d = d + d + 1 ;
      } 
    } 
  } while ( ! ( d >= 268435456L ) ) ;
  Result = d - 268435456L ;
  lab10: ;
  return Result ;
} 
void 
zprintspec ( strnumber s ) 
{
  /* 45 30 */ halfword p, q  ;
  smallnumber octant  ;
  printdiagnostic ( 544 , s , true ) ;
  p = curspec ;
  octant = mem [p + 3 ].cint ;
  println () ;
  unskew ( mem [curspec + 1 ].cint , mem [curspec + 2 ].cint , octant ) ;
  printtwo ( curx , cury ) ;
  print ( 545 ) ;
  while ( true ) {
      
    print ( octantdir [octant ]) ;
    printchar ( 39 ) ;
    while ( true ) {
	
      q = mem [p ].hhfield .v.RH ;
      if ( mem [p ].hhfield .b1 == 0 ) 
      goto lab45 ;
      {
	printnl ( 556 ) ;
	unskew ( mem [p + 5 ].cint , mem [p + 6 ].cint , octant ) ;
	printtwo ( curx , cury ) ;
	print ( 523 ) ;
	unskew ( mem [q + 3 ].cint , mem [q + 4 ].cint , octant ) ;
	printtwo ( curx , cury ) ;
	printnl ( 520 ) ;
	unskew ( mem [q + 1 ].cint , mem [q + 2 ].cint , octant ) ;
	printtwo ( curx , cury ) ;
	print ( 557 ) ;
	printint ( mem [q ].hhfield .b0 - 1 ) ;
      } 
      p = q ;
    } 
    lab45: if ( q == curspec ) 
    goto lab30 ;
    p = q ;
    octant = mem [p + 3 ].cint ;
    printnl ( 546 ) ;
  } 
  lab30: printnl ( 547 ) ;
  enddiagnostic ( true ) ;
} 
void 
zprintstrange ( strnumber s ) 
{
  halfword p  ;
  halfword f  ;
  halfword q  ;
  integer t  ;
  if ( interaction == 3 ) 
  ;
  printnl ( 62 ) ;
  p = curspec ;
  t = 256 ;
  do {
      p = mem [p ].hhfield .v.RH ;
    if ( mem [p ].hhfield .b0 != 0 ) 
    {
      if ( mem [p ].hhfield .b0 < t ) 
      f = p ;
      t = mem [p ].hhfield .b0 ;
    } 
  } while ( ! ( p == curspec ) ) ;
  p = curspec ;
  q = p ;
  do {
      p = mem [p ].hhfield .v.RH ;
    if ( mem [p ].hhfield .b0 == 0 ) 
    q = p ;
  } while ( ! ( p == f ) ) ;
  t = 0 ;
  do {
      if ( mem [p ].hhfield .b0 != 0 ) 
    {
      if ( mem [p ].hhfield .b0 != t ) 
      {
	t = mem [p ].hhfield .b0 ;
	printchar ( 32 ) ;
	printint ( t - 1 ) ;
      } 
      if ( q != 0 ) 
      {
	if ( mem [mem [q ].hhfield .v.RH ].hhfield .b0 == 0 ) 
	{
	  print ( 558 ) ;
	  print ( octantdir [mem [q + 3 ].cint ]) ;
	  q = mem [q ].hhfield .v.RH ;
	  while ( mem [mem [q ].hhfield .v.RH ].hhfield .b0 == 0 ) {
	      
	    printchar ( 32 ) ;
	    print ( octantdir [mem [q + 3 ].cint ]) ;
	    q = mem [q ].hhfield .v.RH ;
	  } 
	  printchar ( 41 ) ;
	} 
	printchar ( 32 ) ;
	print ( octantdir [mem [q + 3 ].cint ]) ;
	q = 0 ;
      } 
    } 
    else if ( q == 0 ) 
    q = p ;
    p = mem [p ].hhfield .v.RH ;
  } while ( ! ( p == f ) ) ;
  printchar ( 32 ) ;
  printint ( mem [p ].hhfield .b0 - 1 ) ;
  if ( q != 0 ) {
      
    if ( mem [mem [q ].hhfield .v.RH ].hhfield .b0 == 0 ) 
    {
      print ( 558 ) ;
      print ( octantdir [mem [q + 3 ].cint ]) ;
      q = mem [q ].hhfield .v.RH ;
      while ( mem [mem [q ].hhfield .v.RH ].hhfield .b0 == 0 ) {
	  
	printchar ( 32 ) ;
	print ( octantdir [mem [q + 3 ].cint ]) ;
	q = mem [q ].hhfield .v.RH ;
      } 
      printchar ( 41 ) ;
    } 
  } 
  {
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( s ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( s ) ;
    } 
  } 
} 
void 
zremovecubic ( halfword p ) 
{
  halfword q  ;
  q = mem [p ].hhfield .v.RH ;
  mem [p ].hhfield .b1 = mem [q ].hhfield .b1 ;
  mem [p ].hhfield .v.RH = mem [q ].hhfield .v.RH ;
  mem [p + 1 ].cint = mem [q + 1 ].cint ;
  mem [p + 2 ].cint = mem [q + 2 ].cint ;
  mem [p + 5 ].cint = mem [q + 5 ].cint ;
  mem [p + 6 ].cint = mem [q + 6 ].cint ;
  freenode ( q , 7 ) ;
} 
void 
zsplitcubic ( halfword p , fraction t , scaled xq , scaled yq ) 
{
  scaled v  ;
  halfword q, r  ;
  q = mem [p ].hhfield .v.RH ;
  r = getnode ( 7 ) ;
  mem [p ].hhfield .v.RH = r ;
  mem [r ].hhfield .v.RH = q ;
  mem [r ].hhfield .b0 = mem [q ].hhfield .b0 ;
  mem [r ].hhfield .b1 = mem [p ].hhfield .b1 ;
  v = mem [p + 5 ].cint - takefraction ( mem [p + 5 ].cint - mem [q + 3 ]
  .cint , t ) ;
  mem [p + 5 ].cint = mem [p + 1 ].cint - takefraction ( mem [p + 1 ]
  .cint - mem [p + 5 ].cint , t ) ;
  mem [q + 3 ].cint = mem [q + 3 ].cint - takefraction ( mem [q + 3 ]
  .cint - xq , t ) ;
  mem [r + 3 ].cint = mem [p + 5 ].cint - takefraction ( mem [p + 5 ]
  .cint - v , t ) ;
  mem [r + 5 ].cint = v - takefraction ( v - mem [q + 3 ].cint , t ) ;
  mem [r + 1 ].cint = mem [r + 3 ].cint - takefraction ( mem [r + 3 ]
  .cint - mem [r + 5 ].cint , t ) ;
  v = mem [p + 6 ].cint - takefraction ( mem [p + 6 ].cint - mem [q + 4 ]
  .cint , t ) ;
  mem [p + 6 ].cint = mem [p + 2 ].cint - takefraction ( mem [p + 2 ]
  .cint - mem [p + 6 ].cint , t ) ;
  mem [q + 4 ].cint = mem [q + 4 ].cint - takefraction ( mem [q + 4 ]
  .cint - yq , t ) ;
  mem [r + 4 ].cint = mem [p + 6 ].cint - takefraction ( mem [p + 6 ]
  .cint - v , t ) ;
  mem [r + 6 ].cint = v - takefraction ( v - mem [q + 4 ].cint , t ) ;
  mem [r + 2 ].cint = mem [r + 4 ].cint - takefraction ( mem [r + 4 ]
  .cint - mem [r + 6 ].cint , t ) ;
} 
void 
quadrantsubdivide ( void ) 
{
  /* 22 10 */ halfword p, q, r, s, pp, qq  ;
  scaled firstx, firsty  ;
  scaled del1, del2, del3, del, dmax  ;
  fraction t  ;
  scaled destx, desty  ;
  boolean constantx  ;
  p = curspec ;
  firstx = mem [curspec + 1 ].cint ;
  firsty = mem [curspec + 2 ].cint ;
  do {
      lab22: q = mem [p ].hhfield .v.RH ;
    if ( q == curspec ) 
    {
      destx = firstx ;
      desty = firsty ;
    } 
    else {
	
      destx = mem [q + 1 ].cint ;
      desty = mem [q + 2 ].cint ;
    } 
    del1 = mem [p + 5 ].cint - mem [p + 1 ].cint ;
    del2 = mem [q + 3 ].cint - mem [p + 5 ].cint ;
    del3 = destx - mem [q + 3 ].cint ;
    if ( del1 != 0 ) 
    del = del1 ;
    else if ( del2 != 0 ) 
    del = del2 ;
    else del = del3 ;
    if ( del != 0 ) 
    {
      dmax = abs ( del1 ) ;
      if ( abs ( del2 ) > dmax ) 
      dmax = abs ( del2 ) ;
      if ( abs ( del3 ) > dmax ) 
      dmax = abs ( del3 ) ;
      while ( dmax < 134217728L ) {
	  
	dmax = dmax + dmax ;
	del1 = del1 + del1 ;
	del2 = del2 + del2 ;
	del3 = del3 + del3 ;
      } 
    } 
    if ( del == 0 ) 
    constantx = true ;
    else {
	
      constantx = false ;
      if ( del < 0 ) 
      {
	mem [p + 1 ].cint = - (integer) mem [p + 1 ].cint ;
	mem [p + 5 ].cint = - (integer) mem [p + 5 ].cint ;
	mem [q + 3 ].cint = - (integer) mem [q + 3 ].cint ;
	del1 = - (integer) del1 ;
	del2 = - (integer) del2 ;
	del3 = - (integer) del3 ;
	destx = - (integer) destx ;
	mem [p ].hhfield .b1 = 2 ;
      } 
      t = crossingpoint ( del1 , del2 , del3 ) ;
      if ( t < 268435456L ) 
      {
	splitcubic ( p , t , destx , desty ) ;
	r = mem [p ].hhfield .v.RH ;
	if ( mem [r ].hhfield .b1 > 1 ) 
	mem [r ].hhfield .b1 = 1 ;
	else mem [r ].hhfield .b1 = 2 ;
	if ( mem [r + 1 ].cint < mem [p + 1 ].cint ) 
	mem [r + 1 ].cint = mem [p + 1 ].cint ;
	mem [r + 3 ].cint = mem [r + 1 ].cint ;
	if ( mem [p + 5 ].cint > mem [r + 1 ].cint ) 
	mem [p + 5 ].cint = mem [r + 1 ].cint ;
	mem [r + 1 ].cint = - (integer) mem [r + 1 ].cint ;
	mem [r + 5 ].cint = mem [r + 1 ].cint ;
	mem [q + 3 ].cint = - (integer) mem [q + 3 ].cint ;
	destx = - (integer) destx ;
	del2 = del2 - takefraction ( del2 - del3 , t ) ;
	if ( del2 > 0 ) 
	del2 = 0 ;
	t = crossingpoint ( 0 , - (integer) del2 , - (integer) del3 ) ;
	if ( t < 268435456L ) 
	{
	  splitcubic ( r , t , destx , desty ) ;
	  s = mem [r ].hhfield .v.RH ;
	  if ( mem [s + 1 ].cint < destx ) 
	  mem [s + 1 ].cint = destx ;
	  if ( mem [s + 1 ].cint < mem [r + 1 ].cint ) 
	  mem [s + 1 ].cint = mem [r + 1 ].cint ;
	  mem [s ].hhfield .b1 = mem [p ].hhfield .b1 ;
	  mem [s + 3 ].cint = mem [s + 1 ].cint ;
	  if ( mem [q + 3 ].cint < destx ) 
	  mem [q + 3 ].cint = - (integer) destx ;
	  else if ( mem [q + 3 ].cint > mem [s + 1 ].cint ) 
	  mem [q + 3 ].cint = - (integer) mem [s + 1 ].cint ;
	  else mem [q + 3 ].cint = - (integer) mem [q + 3 ].cint ;
	  mem [s + 1 ].cint = - (integer) mem [s + 1 ].cint ;
	  mem [s + 5 ].cint = mem [s + 1 ].cint ;
	} 
	else {
	    
	  if ( mem [r + 1 ].cint > destx ) 
	  {
	    mem [r + 1 ].cint = destx ;
	    mem [r + 3 ].cint = - (integer) mem [r + 1 ].cint ;
	    mem [r + 5 ].cint = mem [r + 1 ].cint ;
	  } 
	  if ( mem [q + 3 ].cint > destx ) 
	  mem [q + 3 ].cint = destx ;
	  else if ( mem [q + 3 ].cint < mem [r + 1 ].cint ) 
	  mem [q + 3 ].cint = mem [r + 1 ].cint ;
	} 
      } 
    } 
    pp = p ;
    do {
	qq = mem [pp ].hhfield .v.RH ;
      abnegate ( mem [qq + 1 ].cint , mem [qq + 2 ].cint , mem [qq ]
      .hhfield .b1 , mem [pp ].hhfield .b1 ) ;
      destx = curx ;
      desty = cury ;
      del1 = mem [pp + 6 ].cint - mem [pp + 2 ].cint ;
      del2 = mem [qq + 4 ].cint - mem [pp + 6 ].cint ;
      del3 = desty - mem [qq + 4 ].cint ;
      if ( del1 != 0 ) 
      del = del1 ;
      else if ( del2 != 0 ) 
      del = del2 ;
      else del = del3 ;
      if ( del != 0 ) 
      {
	dmax = abs ( del1 ) ;
	if ( abs ( del2 ) > dmax ) 
	dmax = abs ( del2 ) ;
	if ( abs ( del3 ) > dmax ) 
	dmax = abs ( del3 ) ;
	while ( dmax < 134217728L ) {
	    
	  dmax = dmax + dmax ;
	  del1 = del1 + del1 ;
	  del2 = del2 + del2 ;
	  del3 = del3 + del3 ;
	} 
      } 
      if ( del != 0 ) 
      {
	if ( del < 0 ) 
	{
	  mem [pp + 2 ].cint = - (integer) mem [pp + 2 ].cint ;
	  mem [pp + 6 ].cint = - (integer) mem [pp + 6 ].cint ;
	  mem [qq + 4 ].cint = - (integer) mem [qq + 4 ].cint ;
	  del1 = - (integer) del1 ;
	  del2 = - (integer) del2 ;
	  del3 = - (integer) del3 ;
	  desty = - (integer) desty ;
	  mem [pp ].hhfield .b1 = mem [pp ].hhfield .b1 + 2 ;
	} 
	t = crossingpoint ( del1 , del2 , del3 ) ;
	if ( t < 268435456L ) 
	{
	  splitcubic ( pp , t , destx , desty ) ;
	  r = mem [pp ].hhfield .v.RH ;
	  if ( mem [r ].hhfield .b1 > 2 ) 
	  mem [r ].hhfield .b1 = mem [r ].hhfield .b1 - 2 ;
	  else mem [r ].hhfield .b1 = mem [r ].hhfield .b1 + 2 ;
	  if ( mem [r + 2 ].cint < mem [pp + 2 ].cint ) 
	  mem [r + 2 ].cint = mem [pp + 2 ].cint ;
	  mem [r + 4 ].cint = mem [r + 2 ].cint ;
	  if ( mem [pp + 6 ].cint > mem [r + 2 ].cint ) 
	  mem [pp + 6 ].cint = mem [r + 2 ].cint ;
	  mem [r + 2 ].cint = - (integer) mem [r + 2 ].cint ;
	  mem [r + 6 ].cint = mem [r + 2 ].cint ;
	  mem [qq + 4 ].cint = - (integer) mem [qq + 4 ].cint ;
	  desty = - (integer) desty ;
	  if ( mem [r + 1 ].cint < mem [pp + 1 ].cint ) 
	  mem [r + 1 ].cint = mem [pp + 1 ].cint ;
	  else if ( mem [r + 1 ].cint > destx ) 
	  mem [r + 1 ].cint = destx ;
	  if ( mem [r + 3 ].cint > mem [r + 1 ].cint ) 
	  {
	    mem [r + 3 ].cint = mem [r + 1 ].cint ;
	    if ( mem [pp + 5 ].cint > mem [r + 1 ].cint ) 
	    mem [pp + 5 ].cint = mem [r + 1 ].cint ;
	  } 
	  if ( mem [r + 5 ].cint < mem [r + 1 ].cint ) 
	  {
	    mem [r + 5 ].cint = mem [r + 1 ].cint ;
	    if ( mem [qq + 3 ].cint < mem [r + 1 ].cint ) 
	    mem [qq + 3 ].cint = mem [r + 1 ].cint ;
	  } 
	  del2 = del2 - takefraction ( del2 - del3 , t ) ;
	  if ( del2 > 0 ) 
	  del2 = 0 ;
	  t = crossingpoint ( 0 , - (integer) del2 , - (integer) del3 ) ;
	  if ( t < 268435456L ) 
	  {
	    splitcubic ( r , t , destx , desty ) ;
	    s = mem [r ].hhfield .v.RH ;
	    if ( mem [s + 2 ].cint < desty ) 
	    mem [s + 2 ].cint = desty ;
	    if ( mem [s + 2 ].cint < mem [r + 2 ].cint ) 
	    mem [s + 2 ].cint = mem [r + 2 ].cint ;
	    mem [s ].hhfield .b1 = mem [pp ].hhfield .b1 ;
	    mem [s + 4 ].cint = mem [s + 2 ].cint ;
	    if ( mem [qq + 4 ].cint < desty ) 
	    mem [qq + 4 ].cint = - (integer) desty ;
	    else if ( mem [qq + 4 ].cint > mem [s + 2 ].cint ) 
	    mem [qq + 4 ].cint = - (integer) mem [s + 2 ].cint ;
	    else mem [qq + 4 ].cint = - (integer) mem [qq + 4 ].cint ;
	    mem [s + 2 ].cint = - (integer) mem [s + 2 ].cint ;
	    mem [s + 6 ].cint = mem [s + 2 ].cint ;
	    if ( mem [s + 1 ].cint < mem [r + 1 ].cint ) 
	    mem [s + 1 ].cint = mem [r + 1 ].cint ;
	    else if ( mem [s + 1 ].cint > destx ) 
	    mem [s + 1 ].cint = destx ;
	    if ( mem [s + 3 ].cint > mem [s + 1 ].cint ) 
	    {
	      mem [s + 3 ].cint = mem [s + 1 ].cint ;
	      if ( mem [r + 5 ].cint > mem [s + 1 ].cint ) 
	      mem [r + 5 ].cint = mem [s + 1 ].cint ;
	    } 
	    if ( mem [s + 5 ].cint < mem [s + 1 ].cint ) 
	    {
	      mem [s + 5 ].cint = mem [s + 1 ].cint ;
	      if ( mem [qq + 3 ].cint < mem [s + 1 ].cint ) 
	      mem [qq + 3 ].cint = mem [s + 1 ].cint ;
	    } 
	  } 
	  else {
	      
	    if ( mem [r + 2 ].cint > desty ) 
	    {
	      mem [r + 2 ].cint = desty ;
	      mem [r + 4 ].cint = - (integer) mem [r + 2 ].cint ;
	      mem [r + 6 ].cint = mem [r + 2 ].cint ;
	    } 
	    if ( mem [qq + 4 ].cint > desty ) 
	    mem [qq + 4 ].cint = desty ;
	    else if ( mem [qq + 4 ].cint < mem [r + 2 ].cint ) 
	    mem [qq + 4 ].cint = mem [r + 2 ].cint ;
	  } 
	} 
      } 
      else if ( constantx ) 
      {
	if ( q != p ) 
	{
	  removecubic ( p ) ;
	  if ( curspec != q ) 
	  goto lab22 ;
	  else {
	      
	    curspec = p ;
	    goto lab10 ;
	  } 
	} 
      } 
      else if ( ! odd ( mem [pp ].hhfield .b1 ) ) 
      {
	mem [pp + 2 ].cint = - (integer) mem [pp + 2 ].cint ;
	mem [pp + 6 ].cint = - (integer) mem [pp + 6 ].cint ;
	mem [qq + 4 ].cint = - (integer) mem [qq + 4 ].cint ;
	del1 = - (integer) del1 ;
	del2 = - (integer) del2 ;
	del3 = - (integer) del3 ;
	desty = - (integer) desty ;
	mem [pp ].hhfield .b1 = mem [pp ].hhfield .b1 + 2 ;
      } 
      pp = qq ;
    } while ( ! ( pp == q ) ) ;
    if ( constantx ) 
    {
      pp = p ;
      do {
	  qq = mem [pp ].hhfield .v.RH ;
	if ( mem [pp ].hhfield .b1 > 2 ) 
	{
	  mem [pp ].hhfield .b1 = mem [pp ].hhfield .b1 + 1 ;
	  mem [pp + 1 ].cint = - (integer) mem [pp + 1 ].cint ;
	  mem [pp + 5 ].cint = - (integer) mem [pp + 5 ].cint ;
	  mem [qq + 3 ].cint = - (integer) mem [qq + 3 ].cint ;
	} 
	pp = qq ;
      } while ( ! ( pp == q ) ) ;
    } 
    p = q ;
  } while ( ! ( p == curspec ) ) ;
  lab10: ;
} 
void 
octantsubdivide ( void ) 
{
  halfword p, q, r, s  ;
  scaled del1, del2, del3, del, dmax  ;
  fraction t  ;
  scaled destx, desty  ;
  p = curspec ;
  do {
      q = mem [p ].hhfield .v.RH ;
    mem [p + 1 ].cint = mem [p + 1 ].cint - mem [p + 2 ].cint ;
    mem [p + 5 ].cint = mem [p + 5 ].cint - mem [p + 6 ].cint ;
    mem [q + 3 ].cint = mem [q + 3 ].cint - mem [q + 4 ].cint ;
    if ( q == curspec ) 
    {
      unskew ( mem [q + 1 ].cint , mem [q + 2 ].cint , mem [q ].hhfield 
      .b1 ) ;
      skew ( curx , cury , mem [p ].hhfield .b1 ) ;
      destx = curx ;
      desty = cury ;
    } 
    else {
	
      abnegate ( mem [q + 1 ].cint , mem [q + 2 ].cint , mem [q ]
      .hhfield .b1 , mem [p ].hhfield .b1 ) ;
      destx = curx - cury ;
      desty = cury ;
    } 
    del1 = mem [p + 5 ].cint - mem [p + 1 ].cint ;
    del2 = mem [q + 3 ].cint - mem [p + 5 ].cint ;
    del3 = destx - mem [q + 3 ].cint ;
    if ( del1 != 0 ) 
    del = del1 ;
    else if ( del2 != 0 ) 
    del = del2 ;
    else del = del3 ;
    if ( del != 0 ) 
    {
      dmax = abs ( del1 ) ;
      if ( abs ( del2 ) > dmax ) 
      dmax = abs ( del2 ) ;
      if ( abs ( del3 ) > dmax ) 
      dmax = abs ( del3 ) ;
      while ( dmax < 134217728L ) {
	  
	dmax = dmax + dmax ;
	del1 = del1 + del1 ;
	del2 = del2 + del2 ;
	del3 = del3 + del3 ;
      } 
    } 
    if ( del != 0 ) 
    {
      if ( del < 0 ) 
      {
	mem [p + 2 ].cint = mem [p + 1 ].cint + mem [p + 2 ].cint ;
	mem [p + 1 ].cint = - (integer) mem [p + 1 ].cint ;
	mem [p + 6 ].cint = mem [p + 5 ].cint + mem [p + 6 ].cint ;
	mem [p + 5 ].cint = - (integer) mem [p + 5 ].cint ;
	mem [q + 4 ].cint = mem [q + 3 ].cint + mem [q + 4 ].cint ;
	mem [q + 3 ].cint = - (integer) mem [q + 3 ].cint ;
	del1 = - (integer) del1 ;
	del2 = - (integer) del2 ;
	del3 = - (integer) del3 ;
	desty = destx + desty ;
	destx = - (integer) destx ;
	mem [p ].hhfield .b1 = mem [p ].hhfield .b1 + 4 ;
      } 
      t = crossingpoint ( del1 , del2 , del3 ) ;
      if ( t < 268435456L ) 
      {
	splitcubic ( p , t , destx , desty ) ;
	r = mem [p ].hhfield .v.RH ;
	if ( mem [r ].hhfield .b1 > 4 ) 
	mem [r ].hhfield .b1 = mem [r ].hhfield .b1 - 4 ;
	else mem [r ].hhfield .b1 = mem [r ].hhfield .b1 + 4 ;
	if ( mem [r + 2 ].cint < mem [p + 2 ].cint ) 
	mem [r + 2 ].cint = mem [p + 2 ].cint ;
	else if ( mem [r + 2 ].cint > desty ) 
	mem [r + 2 ].cint = desty ;
	if ( mem [p + 1 ].cint + mem [r + 2 ].cint > destx + desty ) 
	mem [r + 2 ].cint = destx + desty - mem [p + 1 ].cint ;
	if ( mem [r + 4 ].cint > mem [r + 2 ].cint ) 
	{
	  mem [r + 4 ].cint = mem [r + 2 ].cint ;
	  if ( mem [p + 6 ].cint > mem [r + 2 ].cint ) 
	  mem [p + 6 ].cint = mem [r + 2 ].cint ;
	} 
	if ( mem [r + 6 ].cint < mem [r + 2 ].cint ) 
	{
	  mem [r + 6 ].cint = mem [r + 2 ].cint ;
	  if ( mem [q + 4 ].cint < mem [r + 2 ].cint ) 
	  mem [q + 4 ].cint = mem [r + 2 ].cint ;
	} 
	if ( mem [r + 1 ].cint < mem [p + 1 ].cint ) 
	mem [r + 1 ].cint = mem [p + 1 ].cint ;
	else if ( mem [r + 1 ].cint + mem [r + 2 ].cint > destx + desty ) 
	mem [r + 1 ].cint = destx + desty - mem [r + 2 ].cint ;
	mem [r + 3 ].cint = mem [r + 1 ].cint ;
	if ( mem [p + 5 ].cint > mem [r + 1 ].cint ) 
	mem [p + 5 ].cint = mem [r + 1 ].cint ;
	mem [r + 2 ].cint = mem [r + 2 ].cint + mem [r + 1 ].cint ;
	mem [r + 6 ].cint = mem [r + 6 ].cint + mem [r + 1 ].cint ;
	mem [r + 1 ].cint = - (integer) mem [r + 1 ].cint ;
	mem [r + 5 ].cint = mem [r + 1 ].cint ;
	mem [q + 4 ].cint = mem [q + 4 ].cint + mem [q + 3 ].cint ;
	mem [q + 3 ].cint = - (integer) mem [q + 3 ].cint ;
	desty = desty + destx ;
	destx = - (integer) destx ;
	if ( mem [r + 6 ].cint < mem [r + 2 ].cint ) 
	{
	  mem [r + 6 ].cint = mem [r + 2 ].cint ;
	  if ( mem [q + 4 ].cint < mem [r + 2 ].cint ) 
	  mem [q + 4 ].cint = mem [r + 2 ].cint ;
	} 
	del2 = del2 - takefraction ( del2 - del3 , t ) ;
	if ( del2 > 0 ) 
	del2 = 0 ;
	t = crossingpoint ( 0 , - (integer) del2 , - (integer) del3 ) ;
	if ( t < 268435456L ) 
	{
	  splitcubic ( r , t , destx , desty ) ;
	  s = mem [r ].hhfield .v.RH ;
	  if ( mem [s + 2 ].cint < mem [r + 2 ].cint ) 
	  mem [s + 2 ].cint = mem [r + 2 ].cint ;
	  else if ( mem [s + 2 ].cint > desty ) 
	  mem [s + 2 ].cint = desty ;
	  if ( mem [r + 1 ].cint + mem [s + 2 ].cint > destx + desty ) 
	  mem [s + 2 ].cint = destx + desty - mem [r + 1 ].cint ;
	  if ( mem [s + 4 ].cint > mem [s + 2 ].cint ) 
	  {
	    mem [s + 4 ].cint = mem [s + 2 ].cint ;
	    if ( mem [r + 6 ].cint > mem [s + 2 ].cint ) 
	    mem [r + 6 ].cint = mem [s + 2 ].cint ;
	  } 
	  if ( mem [s + 6 ].cint < mem [s + 2 ].cint ) 
	  {
	    mem [s + 6 ].cint = mem [s + 2 ].cint ;
	    if ( mem [q + 4 ].cint < mem [s + 2 ].cint ) 
	    mem [q + 4 ].cint = mem [s + 2 ].cint ;
	  } 
	  if ( mem [s + 1 ].cint + mem [s + 2 ].cint > destx + desty ) 
	  mem [s + 1 ].cint = destx + desty - mem [s + 2 ].cint ;
	  else {
	      
	    if ( mem [s + 1 ].cint < destx ) 
	    mem [s + 1 ].cint = destx ;
	    if ( mem [s + 1 ].cint < mem [r + 1 ].cint ) 
	    mem [s + 1 ].cint = mem [r + 1 ].cint ;
	  } 
	  mem [s ].hhfield .b1 = mem [p ].hhfield .b1 ;
	  mem [s + 3 ].cint = mem [s + 1 ].cint ;
	  if ( mem [q + 3 ].cint < destx ) 
	  {
	    mem [q + 4 ].cint = mem [q + 4 ].cint + destx ;
	    mem [q + 3 ].cint = - (integer) destx ;
	  } 
	  else if ( mem [q + 3 ].cint > mem [s + 1 ].cint ) 
	  {
	    mem [q + 4 ].cint = mem [q + 4 ].cint + mem [s + 1 ].cint ;
	    mem [q + 3 ].cint = - (integer) mem [s + 1 ].cint ;
	  } 
	  else {
	      
	    mem [q + 4 ].cint = mem [q + 4 ].cint + mem [q + 3 ].cint ;
	    mem [q + 3 ].cint = - (integer) mem [q + 3 ].cint ;
	  } 
	  mem [s + 2 ].cint = mem [s + 2 ].cint + mem [s + 1 ].cint ;
	  mem [s + 6 ].cint = mem [s + 6 ].cint + mem [s + 1 ].cint ;
	  mem [s + 1 ].cint = - (integer) mem [s + 1 ].cint ;
	  mem [s + 5 ].cint = mem [s + 1 ].cint ;
	  if ( mem [s + 6 ].cint < mem [s + 2 ].cint ) 
	  {
	    mem [s + 6 ].cint = mem [s + 2 ].cint ;
	    if ( mem [q + 4 ].cint < mem [s + 2 ].cint ) 
	    mem [q + 4 ].cint = mem [s + 2 ].cint ;
	  } 
	} 
	else {
	    
	  if ( mem [r + 1 ].cint > destx ) 
	  {
	    mem [r + 1 ].cint = destx ;
	    mem [r + 3 ].cint = - (integer) mem [r + 1 ].cint ;
	    mem [r + 5 ].cint = mem [r + 1 ].cint ;
	  } 
	  if ( mem [q + 3 ].cint > destx ) 
	  mem [q + 3 ].cint = destx ;
	  else if ( mem [q + 3 ].cint < mem [r + 1 ].cint ) 
	  mem [q + 3 ].cint = mem [r + 1 ].cint ;
	} 
      } 
    } 
    p = q ;
  } while ( ! ( p == curspec ) ) ;
} 
void 
makesafe ( void ) 
{
  integer k  ;
  boolean allsafe  ;
  scaled nexta  ;
  scaled deltaa, deltab  ;
  before [curroundingptr ]= before [0 ];
  nodetoround [curroundingptr ]= nodetoround [0 ];
  do {
      after [curroundingptr ]= after [0 ];
    allsafe = true ;
    nexta = after [0 ];
    {register integer for_end; k = 0 ;for_end = curroundingptr - 1 ; if ( k 
    <= for_end) do 
      {
	deltab = before [k + 1 ]- before [k ];
	if ( deltab >= 0 ) 
	deltaa = after [k + 1 ]- nexta ;
	else deltaa = nexta - after [k + 1 ];
	nexta = after [k + 1 ];
	if ( ( deltaa < 0 ) || ( deltaa > abs ( deltab + deltab ) ) ) 
	{
	  allsafe = false ;
	  after [k ]= before [k ];
	  if ( k == curroundingptr - 1 ) 
	  after [0 ]= before [0 ];
	  else after [k + 1 ]= before [k + 1 ];
	} 
      } 
    while ( k++ < for_end ) ;} 
  } while ( ! ( allsafe ) ) ;
} 
void 
zbeforeandafter ( scaled b , scaled a , halfword p ) 
{
  if ( curroundingptr == maxroundingptr ) {
      
    if ( maxroundingptr < maxwiggle ) 
    incr ( maxroundingptr ) ;
    else overflow ( 568 , maxwiggle ) ;
  } 
  after [curroundingptr ]= a ;
  before [curroundingptr ]= b ;
  nodetoround [curroundingptr ]= p ;
  incr ( curroundingptr ) ;
} 
scaled 
zgoodval ( scaled b , scaled o ) 
{
  register scaled Result; scaled a  ;
  a = b + o ;
  if ( a >= 0 ) 
  a = a - ( a % curgran ) - o ;
  else a = a + ( ( - (integer) ( a + 1 ) ) % curgran ) - curgran + 1 - o ;
  if ( b - a < a + curgran - b ) 
  Result = a ;
  else Result = a + curgran ;
  return Result ;
} 
scaled 
zcompromise ( scaled u , scaled v ) 
{
  register scaled Result; Result = half ( goodval ( u + u , - (integer) u - 
  v ) ) ;
  return Result ;
} 
void 
xyround ( void ) 
{
  halfword p, q  ;
  scaled b, a  ;
  scaled penedge  ;
  fraction alpha  ;
  curgran = abs ( internal [37 ]) ;
  if ( curgran == 0 ) 
  curgran = 65536L ;
  p = curspec ;
  curroundingptr = 0 ;
  do {
      q = mem [p ].hhfield .v.RH ;
    if ( odd ( mem [p ].hhfield .b1 ) != odd ( mem [q ].hhfield .b1 ) ) 
    {
      if ( odd ( mem [q ].hhfield .b1 ) ) 
      b = mem [q + 1 ].cint ;
      else b = - (integer) mem [q + 1 ].cint ;
      if ( ( abs ( mem [q + 1 ].cint - mem [q + 5 ].cint ) < 655 ) || ( 
      abs ( mem [q + 1 ].cint + mem [q + 3 ].cint ) < 655 ) ) 
      {
	if ( curpen == 3 ) 
	penedge = 0 ;
	else if ( curpathtype == 0 ) 
	penedge = compromise ( mem [mem [curpen + 5 ].hhfield .v.RH + 2 ]
	.cint , mem [mem [curpen + 7 ].hhfield .v.RH + 2 ].cint ) ;
	else if ( odd ( mem [q ].hhfield .b1 ) ) 
	penedge = mem [mem [curpen + 7 ].hhfield .v.RH + 2 ].cint ;
	else penedge = mem [mem [curpen + 5 ].hhfield .v.RH + 2 ].cint ;
	a = goodval ( b , penedge ) ;
      } 
      else a = b ;
      if ( abs ( a ) > maxallowed ) {
	  
	if ( a > 0 ) 
	a = maxallowed ;
	else a = - (integer) maxallowed ;
      } 
      beforeandafter ( b , a , q ) ;
    } 
    p = q ;
  } while ( ! ( p == curspec ) ) ;
  if ( curroundingptr > 0 ) 
  {
    makesafe () ;
    do {
	decr ( curroundingptr ) ;
      if ( ( after [curroundingptr ]!= before [curroundingptr ]) || ( 
      after [curroundingptr + 1 ]!= before [curroundingptr + 1 ]) ) 
      {
	p = nodetoround [curroundingptr ];
	if ( odd ( mem [p ].hhfield .b1 ) ) 
	{
	  b = before [curroundingptr ];
	  a = after [curroundingptr ];
	} 
	else {
	    
	  b = - (integer) before [curroundingptr ];
	  a = - (integer) after [curroundingptr ];
	} 
	if ( before [curroundingptr ]== before [curroundingptr + 1 ]) 
	alpha = 268435456L ;
	else alpha = makefraction ( after [curroundingptr + 1 ]- after [
	curroundingptr ], before [curroundingptr + 1 ]- before [
	curroundingptr ]) ;
	do {
	    mem [p + 1 ].cint = takefraction ( alpha , mem [p + 1 ].cint 
	  - b ) + a ;
	  mem [p + 5 ].cint = takefraction ( alpha , mem [p + 5 ].cint - b 
	  ) + a ;
	  p = mem [p ].hhfield .v.RH ;
	  mem [p + 3 ].cint = takefraction ( alpha , mem [p + 3 ].cint - b 
	  ) + a ;
	} while ( ! ( p == nodetoround [curroundingptr + 1 ]) ) ;
      } 
    } while ( ! ( curroundingptr == 0 ) ) ;
  } 
  p = curspec ;
  curroundingptr = 0 ;
  do {
      q = mem [p ].hhfield .v.RH ;
    if ( ( mem [p ].hhfield .b1 > 2 ) != ( mem [q ].hhfield .b1 > 2 ) ) 
    {
      if ( mem [q ].hhfield .b1 <= 2 ) 
      b = mem [q + 2 ].cint ;
      else b = - (integer) mem [q + 2 ].cint ;
      if ( ( abs ( mem [q + 2 ].cint - mem [q + 6 ].cint ) < 655 ) || ( 
      abs ( mem [q + 2 ].cint + mem [q + 4 ].cint ) < 655 ) ) 
      {
	if ( curpen == 3 ) 
	penedge = 0 ;
	else if ( curpathtype == 0 ) 
	penedge = compromise ( mem [mem [curpen + 2 ].hhfield .v.RH + 2 ]
	.cint , mem [mem [curpen + 1 ].hhfield .v.RH + 2 ].cint ) ;
	else if ( mem [q ].hhfield .b1 <= 2 ) 
	penedge = mem [mem [curpen + 1 ].hhfield .v.RH + 2 ].cint ;
	else penedge = mem [mem [curpen + 2 ].hhfield .v.RH + 2 ].cint ;
	a = goodval ( b , penedge ) ;
      } 
      else a = b ;
      if ( abs ( a ) > maxallowed ) {
	  
	if ( a > 0 ) 
	a = maxallowed ;
	else a = - (integer) maxallowed ;
      } 
      beforeandafter ( b , a , q ) ;
    } 
    p = q ;
  } while ( ! ( p == curspec ) ) ;
  if ( curroundingptr > 0 ) 
  {
    makesafe () ;
    do {
	decr ( curroundingptr ) ;
      if ( ( after [curroundingptr ]!= before [curroundingptr ]) || ( 
      after [curroundingptr + 1 ]!= before [curroundingptr + 1 ]) ) 
      {
	p = nodetoround [curroundingptr ];
	if ( mem [p ].hhfield .b1 <= 2 ) 
	{
	  b = before [curroundingptr ];
	  a = after [curroundingptr ];
	} 
	else {
	    
	  b = - (integer) before [curroundingptr ];
	  a = - (integer) after [curroundingptr ];
	} 
	if ( before [curroundingptr ]== before [curroundingptr + 1 ]) 
	alpha = 268435456L ;
	else alpha = makefraction ( after [curroundingptr + 1 ]- after [
	curroundingptr ], before [curroundingptr + 1 ]- before [
	curroundingptr ]) ;
	do {
	    mem [p + 2 ].cint = takefraction ( alpha , mem [p + 2 ].cint 
	  - b ) + a ;
	  mem [p + 6 ].cint = takefraction ( alpha , mem [p + 6 ].cint - b 
	  ) + a ;
	  p = mem [p ].hhfield .v.RH ;
	  mem [p + 4 ].cint = takefraction ( alpha , mem [p + 4 ].cint - b 
	  ) + a ;
	} while ( ! ( p == nodetoround [curroundingptr + 1 ]) ) ;
      } 
    } while ( ! ( curroundingptr == 0 ) ) ;
  } 
} 
void 
diaground ( void ) 
{
  halfword p, q, pp  ;
  scaled b, a, bb, aa, d, c, dd, cc  ;
  scaled penedge  ;
  fraction alpha, beta  ;
  scaled nexta  ;
  boolean allsafe  ;
  integer k  ;
  scaled firstx, firsty  ;
  p = curspec ;
  curroundingptr = 0 ;
  do {
      q = mem [p ].hhfield .v.RH ;
    if ( mem [p ].hhfield .b1 != mem [q ].hhfield .b1 ) 
    {
      if ( mem [q ].hhfield .b1 > 4 ) 
      b = - (integer) mem [q + 1 ].cint ;
      else b = mem [q + 1 ].cint ;
      if ( abs ( mem [q ].hhfield .b1 - mem [p ].hhfield .b1 ) == 4 ) {
	  
	if ( ( abs ( mem [q + 1 ].cint - mem [q + 5 ].cint ) < 655 ) || ( 
	abs ( mem [q + 1 ].cint + mem [q + 3 ].cint ) < 655 ) ) 
	{
	  if ( curpen == 3 ) 
	  penedge = 0 ;
	  else if ( curpathtype == 0 ) 
	  switch ( mem [q ].hhfield .b1 ) 
	  {case 1 : 
	  case 5 : 
	    penedge = compromise ( mem [mem [mem [curpen + 1 ].hhfield 
	    .v.RH ].hhfield .lhfield + 1 ].cint , - (integer) mem [mem [
	    mem [curpen + 4 ].hhfield .v.RH ].hhfield .lhfield + 1 ].cint 
	    ) ;
	    break ;
	  case 4 : 
	  case 8 : 
	    penedge = - (integer) compromise ( mem [mem [mem [curpen + 1 ]
	    .hhfield .v.RH ].hhfield .lhfield + 1 ].cint , - (integer) mem [
	    mem [mem [curpen + 4 ].hhfield .v.RH ].hhfield .lhfield + 1 ]
	    .cint ) ;
	    break ;
	  case 6 : 
	  case 2 : 
	    penedge = compromise ( mem [mem [mem [curpen + 2 ].hhfield 
	    .v.RH ].hhfield .lhfield + 1 ].cint , - (integer) mem [mem [
	    mem [curpen + 3 ].hhfield .v.RH ].hhfield .lhfield + 1 ].cint 
	    ) ;
	    break ;
	  case 7 : 
	  case 3 : 
	    penedge = - (integer) compromise ( mem [mem [mem [curpen + 2 ]
	    .hhfield .v.RH ].hhfield .lhfield + 1 ].cint , - (integer) mem [
	    mem [mem [curpen + 3 ].hhfield .v.RH ].hhfield .lhfield + 1 ]
	    .cint ) ;
	    break ;
	  } 
	  else if ( mem [q ].hhfield .b1 <= 4 ) 
	  penedge = mem [mem [mem [curpen + mem [q ].hhfield .b1 ]
	  .hhfield .v.RH ].hhfield .lhfield + 1 ].cint ;
	  else penedge = - (integer) mem [mem [mem [curpen + mem [q ]
	  .hhfield .b1 ].hhfield .v.RH ].hhfield .lhfield + 1 ].cint ;
	  if ( odd ( mem [q ].hhfield .b1 ) ) 
	  a = goodval ( b , penedge + halfp ( curgran ) ) ;
	  else a = goodval ( b - 1 , penedge + halfp ( curgran ) ) ;
	} 
	else a = b ;
      } 
      else a = b ;
      beforeandafter ( b , a , q ) ;
    } 
    p = q ;
  } while ( ! ( p == curspec ) ) ;
  if ( curroundingptr > 0 ) 
  {
    p = nodetoround [0 ];
    firstx = mem [p + 1 ].cint ;
    firsty = mem [p + 2 ].cint ;
    before [curroundingptr ]= before [0 ];
    nodetoround [curroundingptr ]= nodetoround [0 ];
    do {
	after [curroundingptr ]= after [0 ];
      allsafe = true ;
      nexta = after [0 ];
      {register integer for_end; k = 0 ;for_end = curroundingptr - 1 ; if ( 
      k <= for_end) do 
	{
	  a = nexta ;
	  b = before [k ];
	  nexta = after [k + 1 ];
	  aa = nexta ;
	  bb = before [k + 1 ];
	  if ( ( a != b ) || ( aa != bb ) ) 
	  {
	    p = nodetoround [k ];
	    pp = nodetoround [k + 1 ];
	    if ( aa == bb ) 
	    {
	      if ( pp == nodetoround [0 ]) 
	      unskew ( firstx , firsty , mem [pp ].hhfield .b1 ) ;
	      else unskew ( mem [pp + 1 ].cint , mem [pp + 2 ].cint , mem 
	      [pp ].hhfield .b1 ) ;
	      skew ( curx , cury , mem [p ].hhfield .b1 ) ;
	      bb = curx ;
	      aa = bb ;
	      dd = cury ;
	      cc = dd ;
	      if ( mem [p ].hhfield .b1 > 4 ) 
	      {
		b = - (integer) b ;
		a = - (integer) a ;
	      } 
	    } 
	    else {
		
	      if ( mem [p ].hhfield .b1 > 4 ) 
	      {
		bb = - (integer) bb ;
		aa = - (integer) aa ;
		b = - (integer) b ;
		a = - (integer) a ;
	      } 
	      if ( pp == nodetoround [0 ]) 
	      dd = firsty - bb ;
	      else dd = mem [pp + 2 ].cint - bb ;
	      if ( odd ( aa - bb ) ) {
		  
		if ( mem [p ].hhfield .b1 > 4 ) 
		cc = dd - half ( aa - bb + 1 ) ;
		else cc = dd - half ( aa - bb - 1 ) ;
	      } 
	      else cc = dd - half ( aa - bb ) ;
	    } 
	    d = mem [p + 2 ].cint ;
	    if ( odd ( a - b ) ) {
		
	      if ( mem [p ].hhfield .b1 > 4 ) 
	      c = d - half ( a - b - 1 ) ;
	      else c = d - half ( a - b + 1 ) ;
	    } 
	    else c = d - half ( a - b ) ;
	    if ( ( aa < a ) || ( cc < c ) || ( aa - a > 2 * ( bb - b ) ) || ( 
	    cc - c > 2 * ( dd - d ) ) ) 
	    {
	      allsafe = false ;
	      after [k ]= before [k ];
	      if ( k == curroundingptr - 1 ) 
	      after [0 ]= before [0 ];
	      else after [k + 1 ]= before [k + 1 ];
	    } 
	  } 
	} 
      while ( k++ < for_end ) ;} 
    } while ( ! ( allsafe ) ) ;
    {register integer for_end; k = 0 ;for_end = curroundingptr - 1 ; if ( k 
    <= for_end) do 
      {
	a = after [k ];
	b = before [k ];
	aa = after [k + 1 ];
	bb = before [k + 1 ];
	if ( ( a != b ) || ( aa != bb ) ) 
	{
	  p = nodetoround [k ];
	  pp = nodetoround [k + 1 ];
	  if ( aa == bb ) 
	  {
	    if ( pp == nodetoround [0 ]) 
	    unskew ( firstx , firsty , mem [pp ].hhfield .b1 ) ;
	    else unskew ( mem [pp + 1 ].cint , mem [pp + 2 ].cint , mem [
	    pp ].hhfield .b1 ) ;
	    skew ( curx , cury , mem [p ].hhfield .b1 ) ;
	    bb = curx ;
	    aa = bb ;
	    dd = cury ;
	    cc = dd ;
	    if ( mem [p ].hhfield .b1 > 4 ) 
	    {
	      b = - (integer) b ;
	      a = - (integer) a ;
	    } 
	  } 
	  else {
	      
	    if ( mem [p ].hhfield .b1 > 4 ) 
	    {
	      bb = - (integer) bb ;
	      aa = - (integer) aa ;
	      b = - (integer) b ;
	      a = - (integer) a ;
	    } 
	    if ( pp == nodetoround [0 ]) 
	    dd = firsty - bb ;
	    else dd = mem [pp + 2 ].cint - bb ;
	    if ( odd ( aa - bb ) ) {
		
	      if ( mem [p ].hhfield .b1 > 4 ) 
	      cc = dd - half ( aa - bb + 1 ) ;
	      else cc = dd - half ( aa - bb - 1 ) ;
	    } 
	    else cc = dd - half ( aa - bb ) ;
	  } 
	  d = mem [p + 2 ].cint ;
	  if ( odd ( a - b ) ) {
	      
	    if ( mem [p ].hhfield .b1 > 4 ) 
	    c = d - half ( a - b - 1 ) ;
	    else c = d - half ( a - b + 1 ) ;
	  } 
	  else c = d - half ( a - b ) ;
	  if ( b == bb ) 
	  alpha = 268435456L ;
	  else alpha = makefraction ( aa - a , bb - b ) ;
	  if ( d == dd ) 
	  beta = 268435456L ;
	  else beta = makefraction ( cc - c , dd - d ) ;
	  do {
	      mem [p + 1 ].cint = takefraction ( alpha , mem [p + 1 ]
	    .cint - b ) + a ;
	    mem [p + 2 ].cint = takefraction ( beta , mem [p + 2 ].cint - 
	    d ) + c ;
	    mem [p + 5 ].cint = takefraction ( alpha , mem [p + 5 ].cint - 
	    b ) + a ;
	    mem [p + 6 ].cint = takefraction ( beta , mem [p + 6 ].cint - 
	    d ) + c ;
	    p = mem [p ].hhfield .v.RH ;
	    mem [p + 3 ].cint = takefraction ( alpha , mem [p + 3 ].cint - 
	    b ) + a ;
	    mem [p + 4 ].cint = takefraction ( beta , mem [p + 4 ].cint - 
	    d ) + c ;
	  } while ( ! ( p == pp ) ) ;
	} 
      } 
    while ( k++ < for_end ) ;} 
  } 
} 
void 
znewboundary ( halfword p , smallnumber octant ) 
{
  halfword q, r  ;
  q = mem [p ].hhfield .v.RH ;
  r = getnode ( 7 ) ;
  mem [r ].hhfield .v.RH = q ;
  mem [p ].hhfield .v.RH = r ;
  mem [r ].hhfield .b0 = mem [q ].hhfield .b0 ;
  mem [r + 3 ].cint = mem [q + 3 ].cint ;
  mem [r + 4 ].cint = mem [q + 4 ].cint ;
  mem [r ].hhfield .b1 = 0 ;
  mem [q ].hhfield .b0 = 0 ;
  mem [r + 5 ].cint = octant ;
  mem [q + 3 ].cint = mem [q ].hhfield .b1 ;
  unskew ( mem [q + 1 ].cint , mem [q + 2 ].cint , mem [q ].hhfield .b1 
  ) ;
  skew ( curx , cury , octant ) ;
  mem [r + 1 ].cint = curx ;
  mem [r + 2 ].cint = cury ;
} 
halfword 
zmakespec ( halfword h , scaled safetymargin , integer tracing ) 
{
  /* 22 30 */ register halfword Result; halfword p, q, r, s  ;
  integer k  ;
  integer chopped  ;
  smallnumber o1, o2  ;
  boolean clockwise  ;
  integer dx1, dy1, dx2, dy2  ;
  integer dmax, del  ;
  curspec = h ;
  if ( tracing > 0 ) 
  printpath ( curspec , 559 , true ) ;
  maxallowed = 268402687L - safetymargin ;
  p = curspec ;
  k = 1 ;
  chopped = 0 ;
  dmax = half ( maxallowed ) ;
  do {
      if ( abs ( mem [p + 3 ].cint ) >= dmax ) { 
      if ( abs ( mem [p + 3 ].cint ) > maxallowed ) 
      {
	chopped = 1 ;
	if ( mem [p + 3 ].cint > 0 ) 
	mem [p + 3 ].cint = maxallowed ;
	else mem [p + 3 ].cint = - (integer) maxallowed ;
      } 
      else if ( chopped == 0 ) 
      chopped = -1 ;
    } 
    if ( abs ( mem [p + 4 ].cint ) >= dmax ) {
	
      if ( abs ( mem [p + 4 ].cint ) > maxallowed ) 
      {
	chopped = 1 ;
	if ( mem [p + 4 ].cint > 0 ) 
	mem [p + 4 ].cint = maxallowed ;
	else mem [p + 4 ].cint = - (integer) maxallowed ;
      } 
      else if ( chopped == 0 ) 
      chopped = -1 ;
    } 
    if ( abs ( mem [p + 1 ].cint ) >= dmax ) {
	
      if ( abs ( mem [p + 1 ].cint ) > maxallowed ) 
      {
	chopped = 1 ;
	if ( mem [p + 1 ].cint > 0 ) 
	mem [p + 1 ].cint = maxallowed ;
	else mem [p + 1 ].cint = - (integer) maxallowed ;
      } 
      else if ( chopped == 0 ) 
      chopped = -1 ;
    } 
    if ( abs ( mem [p + 2 ].cint ) >= dmax ) {
	
      if ( abs ( mem [p + 2 ].cint ) > maxallowed ) 
      {
	chopped = 1 ;
	if ( mem [p + 2 ].cint > 0 ) 
	mem [p + 2 ].cint = maxallowed ;
	else mem [p + 2 ].cint = - (integer) maxallowed ;
      } 
      else if ( chopped == 0 ) 
      chopped = -1 ;
    } 
    if ( abs ( mem [p + 5 ].cint ) >= dmax ) {
	
      if ( abs ( mem [p + 5 ].cint ) > maxallowed ) 
      {
	chopped = 1 ;
	if ( mem [p + 5 ].cint > 0 ) 
	mem [p + 5 ].cint = maxallowed ;
	else mem [p + 5 ].cint = - (integer) maxallowed ;
      } 
      else if ( chopped == 0 ) 
      chopped = -1 ;
    } 
    if ( abs ( mem [p + 6 ].cint ) >= dmax ) {
	
      if ( abs ( mem [p + 6 ].cint ) > maxallowed ) 
      {
	chopped = 1 ;
	if ( mem [p + 6 ].cint > 0 ) 
	mem [p + 6 ].cint = maxallowed ;
	else mem [p + 6 ].cint = - (integer) maxallowed ;
      } 
      else if ( chopped == 0 ) 
      chopped = -1 ;
    } 
    p = mem [p ].hhfield .v.RH ;
    mem [p ].hhfield .b0 = k ;
    if ( k < 255 ) 
    incr ( k ) ;
    else k = 1 ;
  } while ( ! ( p == curspec ) ) ;
  if ( chopped > 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 563 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 563 ) ;
      } 
    } 
    {
      helpptr = 4 ;
      helpline [3 ]= 564 ;
      helpline [2 ]= 565 ;
      helpline [1 ]= 566 ;
      helpline [0 ]= 567 ;
    } 
    putgeterror () ;
  } 
  quadrantsubdivide () ;
  if ( ( internal [36 ]> 0 ) && ( chopped == 0 ) ) 
  xyround () ;
  octantsubdivide () ;
  if ( ( internal [36 ]> 65536L ) && ( chopped == 0 ) ) 
  diaground () ;
  p = curspec ;
  do {
      lab22: q = mem [p ].hhfield .v.RH ;
    if ( p != q ) 
    {
      if ( mem [p + 1 ].cint == mem [p + 5 ].cint ) {
	  
	if ( mem [p + 2 ].cint == mem [p + 6 ].cint ) {
	    
	  if ( mem [p + 1 ].cint == mem [q + 3 ].cint ) {
	      
	    if ( mem [p + 2 ].cint == mem [q + 4 ].cint ) 
	    {
	      unskew ( mem [q + 1 ].cint , mem [q + 2 ].cint , mem [q ]
	      .hhfield .b1 ) ;
	      skew ( curx , cury , mem [p ].hhfield .b1 ) ;
	      if ( mem [p + 1 ].cint == curx ) {
		  
		if ( mem [p + 2 ].cint == cury ) 
		{
		  removecubic ( p ) ;
		  if ( q != curspec ) 
		  goto lab22 ;
		  curspec = p ;
		  q = p ;
		} 
	      } 
	    } 
	  } 
	} 
      } 
    } 
    p = q ;
  } while ( ! ( p == curspec ) ) ;
  turningnumber = 0 ;
  p = curspec ;
  q = mem [p ].hhfield .v.RH ;
  do {
      r = mem [q ].hhfield .v.RH ;
    if ( ( mem [p ].hhfield .b1 != mem [q ].hhfield .b1 ) || ( q == r ) ) 
    {
      newboundary ( p , mem [p ].hhfield .b1 ) ;
      s = mem [p ].hhfield .v.RH ;
      o1 = octantnumber [mem [p ].hhfield .b1 ];
      o2 = octantnumber [mem [q ].hhfield .b1 ];
      switch ( o2 - o1 ) 
      {case 1 : 
      case -7 : 
      case 7 : 
      case -1 : 
	goto lab30 ;
	break ;
      case 2 : 
      case -6 : 
	clockwise = false ;
	break ;
      case 3 : 
      case -5 : 
      case 4 : 
      case -4 : 
      case 5 : 
      case -3 : 
	{
	  dx1 = mem [s + 1 ].cint - mem [s + 3 ].cint ;
	  dy1 = mem [s + 2 ].cint - mem [s + 4 ].cint ;
	  if ( dx1 == 0 ) {
	      
	    if ( dy1 == 0 ) 
	    {
	      dx1 = mem [s + 1 ].cint - mem [p + 5 ].cint ;
	      dy1 = mem [s + 2 ].cint - mem [p + 6 ].cint ;
	      if ( dx1 == 0 ) {
		  
		if ( dy1 == 0 ) 
		{
		  dx1 = mem [s + 1 ].cint - mem [p + 1 ].cint ;
		  dy1 = mem [s + 2 ].cint - mem [p + 2 ].cint ;
		} 
	      } 
	    } 
	  } 
	  dmax = abs ( dx1 ) ;
	  if ( abs ( dy1 ) > dmax ) 
	  dmax = abs ( dy1 ) ;
	  while ( dmax < 268435456L ) {
	      
	    dmax = dmax + dmax ;
	    dx1 = dx1 + dx1 ;
	    dy1 = dy1 + dy1 ;
	  } 
	  dx2 = mem [q + 5 ].cint - mem [q + 1 ].cint ;
	  dy2 = mem [q + 6 ].cint - mem [q + 2 ].cint ;
	  if ( dx2 == 0 ) {
	      
	    if ( dy2 == 0 ) 
	    {
	      dx2 = mem [r + 3 ].cint - mem [q + 1 ].cint ;
	      dy2 = mem [r + 4 ].cint - mem [q + 2 ].cint ;
	      if ( dx2 == 0 ) {
		  
		if ( dy2 == 0 ) 
		{
		  if ( mem [r ].hhfield .b1 == 0 ) 
		  {
		    curx = mem [r + 1 ].cint ;
		    cury = mem [r + 2 ].cint ;
		  } 
		  else {
		      
		    unskew ( mem [r + 1 ].cint , mem [r + 2 ].cint , mem [
		    r ].hhfield .b1 ) ;
		    skew ( curx , cury , mem [q ].hhfield .b1 ) ;
		  } 
		  dx2 = curx - mem [q + 1 ].cint ;
		  dy2 = cury - mem [q + 2 ].cint ;
		} 
	      } 
	    } 
	  } 
	  dmax = abs ( dx2 ) ;
	  if ( abs ( dy2 ) > dmax ) 
	  dmax = abs ( dy2 ) ;
	  while ( dmax < 268435456L ) {
	      
	    dmax = dmax + dmax ;
	    dx2 = dx2 + dx2 ;
	    dy2 = dy2 + dy2 ;
	  } 
	  unskew ( dx1 , dy1 , mem [p ].hhfield .b1 ) ;
	  del = pythadd ( curx , cury ) ;
	  dx1 = makefraction ( curx , del ) ;
	  dy1 = makefraction ( cury , del ) ;
	  unskew ( dx2 , dy2 , mem [q ].hhfield .b1 ) ;
	  del = pythadd ( curx , cury ) ;
	  dx2 = makefraction ( curx , del ) ;
	  dy2 = makefraction ( cury , del ) ;
	  del = takefraction ( dx1 , dy2 ) - takefraction ( dx2 , dy1 ) ;
	  if ( del > 4684844L ) 
	  clockwise = false ;
	  else if ( del < -4684844L ) 
	  clockwise = true ;
	  else clockwise = revturns ;
	} 
	break ;
      case 6 : 
      case -2 : 
	clockwise = true ;
	break ;
      case 0 : 
	clockwise = revturns ;
	break ;
      } 
      while ( true ) {
	  
	if ( clockwise ) {
	    
	  if ( o1 == 1 ) 
	  o1 = 8 ;
	  else decr ( o1 ) ;
	} 
	else if ( o1 == 8 ) 
	o1 = 1 ;
	else incr ( o1 ) ;
	if ( o1 == o2 ) 
	goto lab30 ;
	newboundary ( s , octantcode [o1 ]) ;
	s = mem [s ].hhfield .v.RH ;
	mem [s + 3 ].cint = mem [s + 5 ].cint ;
      } 
      lab30: if ( q == r ) 
      {
	q = mem [q ].hhfield .v.RH ;
	r = q ;
	p = s ;
	mem [s ].hhfield .v.RH = q ;
	mem [q + 3 ].cint = mem [q + 5 ].cint ;
	mem [q ].hhfield .b0 = 0 ;
	freenode ( curspec , 7 ) ;
	curspec = q ;
      } 
      p = mem [p ].hhfield .v.RH ;
      do {
	  s = mem [p ].hhfield .v.RH ;
	o1 = octantnumber [mem [p + 5 ].cint ];
	o2 = octantnumber [mem [s + 3 ].cint ];
	if ( abs ( o1 - o2 ) == 1 ) 
	{
	  if ( o2 < o1 ) 
	  o2 = o1 ;
	  if ( odd ( o2 ) ) 
	  mem [p + 6 ].cint = 0 ;
	  else mem [p + 6 ].cint = 1 ;
	} 
	else {
	    
	  if ( o1 == 8 ) 
	  incr ( turningnumber ) ;
	  else decr ( turningnumber ) ;
	  mem [p + 6 ].cint = 0 ;
	} 
	mem [s + 4 ].cint = mem [p + 6 ].cint ;
	p = s ;
      } while ( ! ( p == q ) ) ;
    } 
    p = q ;
    q = r ;
  } while ( ! ( p == curspec ) ) ;
  while ( mem [curspec ].hhfield .b0 != 0 ) curspec = mem [curspec ]
  .hhfield .v.RH ;
  if ( tracing > 0 ) {
      
    if ( ( internal [36 ]<= 0 ) || ( chopped != 0 ) ) 
    printspec ( 560 ) ;
    else if ( internal [36 ]> 65536L ) 
    printspec ( 561 ) ;
    else printspec ( 562 ) ;
  } 
  Result = curspec ;
  return Result ;
} 
void 
zendround ( scaled x , scaled y ) 
{
  y = y + 32768L - ycorr [octant ];
  x = x + y - xcorr [octant ];
  m1 = floorunscaled ( x ) ;
  n1 = floorunscaled ( y ) ;
  if ( x - 65536L * m1 >= y - 65536L * n1 + zcorr [octant ]) 
  d1 = 1 ;
  else d1 = 0 ;
} 
void 
zfillspec ( halfword h ) 
{
  halfword p, q, r, s  ;
  if ( internal [10 ]> 0 ) 
  beginedgetracing () ;
  p = h ;
  do {
      octant = mem [p + 3 ].cint ;
    q = p ;
    while ( mem [q ].hhfield .b1 != 0 ) q = mem [q ].hhfield .v.RH ;
    if ( q != p ) 
    {
      endround ( mem [p + 1 ].cint , mem [p + 2 ].cint ) ;
      m0 = m1 ;
      n0 = n1 ;
      d0 = d1 ;
      endround ( mem [q + 1 ].cint , mem [q + 2 ].cint ) ;
      if ( n1 - n0 >= movesize ) 
      overflow ( 540 , movesize ) ;
      move [0 ]= d0 ;
      moveptr = 0 ;
      r = p ;
      do {
	  s = mem [r ].hhfield .v.RH ;
	makemoves ( mem [r + 1 ].cint , mem [r + 5 ].cint , mem [s + 3 ]
	.cint , mem [s + 1 ].cint , mem [r + 2 ].cint + 32768L , mem [r + 
	6 ].cint + 32768L , mem [s + 4 ].cint + 32768L , mem [s + 2 ]
	.cint + 32768L , xycorr [octant ], ycorr [octant ]) ;
	r = s ;
      } while ( ! ( r == q ) ) ;
      move [moveptr ]= move [moveptr ]- d1 ;
      if ( internal [35 ]> 0 ) 
      smoothmoves ( 0 , moveptr ) ;
      movetoedges ( m0 , n0 , m1 , n1 ) ;
    } 
    p = mem [q ].hhfield .v.RH ;
  } while ( ! ( p == h ) ) ;
  tossknotlist ( h ) ;
  if ( internal [10 ]> 0 ) 
  endedgetracing () ;
} 
void 
zdupoffset ( halfword w ) 
{
  halfword r  ;
  r = getnode ( 3 ) ;
  mem [r + 1 ].cint = mem [w + 1 ].cint ;
  mem [r + 2 ].cint = mem [w + 2 ].cint ;
  mem [r ].hhfield .v.RH = mem [w ].hhfield .v.RH ;
  mem [mem [w ].hhfield .v.RH ].hhfield .lhfield = r ;
  mem [r ].hhfield .lhfield = w ;
  mem [w ].hhfield .v.RH = r ;
} 
halfword 
zmakepen ( halfword h ) 
{
  /* 30 31 45 40 */ register halfword Result; smallnumber o, oo, k  ;
  halfword p  ;
  halfword q, r, s, w, hh  ;
  integer n  ;
  scaled dx, dy  ;
  scaled mc  ;
  q = h ;
  r = mem [q ].hhfield .v.RH ;
  mc = abs ( mem [h + 1 ].cint ) ;
  if ( q == r ) 
  {
    hh = h ;
    mem [h ].hhfield .b1 = 0 ;
    if ( mc < abs ( mem [h + 2 ].cint ) ) 
    mc = abs ( mem [h + 2 ].cint ) ;
  } 
  else {
      
    o = 0 ;
    hh = 0 ;
    while ( true ) {
	
      s = mem [r ].hhfield .v.RH ;
      if ( mc < abs ( mem [r + 1 ].cint ) ) 
      mc = abs ( mem [r + 1 ].cint ) ;
      if ( mc < abs ( mem [r + 2 ].cint ) ) 
      mc = abs ( mem [r + 2 ].cint ) ;
      dx = mem [r + 1 ].cint - mem [q + 1 ].cint ;
      dy = mem [r + 2 ].cint - mem [q + 2 ].cint ;
      if ( dx == 0 ) {
	  
	if ( dy == 0 ) 
	goto lab45 ;
      } 
      if ( abvscd ( dx , mem [s + 2 ].cint - mem [r + 2 ].cint , dy , mem 
      [s + 1 ].cint - mem [r + 1 ].cint ) < 0 ) 
      goto lab45 ;
      if ( dx > 0 ) 
      octant = 1 ;
      else if ( dx == 0 ) {
	  
	if ( dy > 0 ) 
	octant = 1 ;
	else octant = 2 ;
      } 
      else {
	  
	dx = - (integer) dx ;
	octant = 2 ;
      } 
      if ( dy < 0 ) 
      {
	dy = - (integer) dy ;
	octant = octant + 2 ;
      } 
      else if ( dy == 0 ) {
	  
	if ( octant > 1 ) 
	octant = 4 ;
      } 
      if ( dx < dy ) 
      octant = octant + 4 ;
      mem [q ].hhfield .b1 = octant ;
      oo = octantnumber [octant ];
      if ( o > oo ) 
      {
	if ( hh != 0 ) 
	goto lab45 ;
	hh = q ;
      } 
      o = oo ;
      if ( ( q == h ) && ( hh != 0 ) ) 
      goto lab30 ;
      q = r ;
      r = s ;
    } 
    lab30: ;
  } 
  if ( mc >= 268402688L ) 
  goto lab45 ;
  p = getnode ( 10 ) ;
  q = hh ;
  mem [p + 9 ].cint = mc ;
  mem [p ].hhfield .lhfield = 0 ;
  if ( mem [q ].hhfield .v.RH != q ) 
  mem [p ].hhfield .v.RH = 1 ;
  {register integer for_end; k = 1 ;for_end = 8 ; if ( k <= for_end) do 
    {
      octant = octantcode [k ];
      n = 0 ;
      h = p + octant ;
      while ( true ) {
	  
	r = getnode ( 3 ) ;
	skew ( mem [q + 1 ].cint , mem [q + 2 ].cint , octant ) ;
	mem [r + 1 ].cint = curx ;
	mem [r + 2 ].cint = cury ;
	if ( n == 0 ) 
	mem [h ].hhfield .v.RH = r ;
	else if ( odd ( k ) ) 
	{
	  mem [w ].hhfield .v.RH = r ;
	  mem [r ].hhfield .lhfield = w ;
	} 
	else {
	    
	  mem [w ].hhfield .lhfield = r ;
	  mem [r ].hhfield .v.RH = w ;
	} 
	w = r ;
	if ( mem [q ].hhfield .b1 != octant ) 
	goto lab31 ;
	q = mem [q ].hhfield .v.RH ;
	incr ( n ) ;
      } 
      lab31: r = mem [h ].hhfield .v.RH ;
      if ( odd ( k ) ) 
      {
	mem [w ].hhfield .v.RH = r ;
	mem [r ].hhfield .lhfield = w ;
      } 
      else {
	  
	mem [w ].hhfield .lhfield = r ;
	mem [r ].hhfield .v.RH = w ;
	mem [h ].hhfield .v.RH = w ;
	r = w ;
      } 
      if ( ( mem [r + 2 ].cint != mem [mem [r ].hhfield .v.RH + 2 ].cint 
      ) || ( n == 0 ) ) 
      {
	dupoffset ( r ) ;
	incr ( n ) ;
      } 
      r = mem [r ].hhfield .lhfield ;
      if ( mem [r + 1 ].cint != mem [mem [r ].hhfield .lhfield + 1 ]
      .cint ) 
      dupoffset ( r ) ;
      else decr ( n ) ;
      if ( n >= 255 ) 
      overflow ( 579 , 255 ) ;
      mem [h ].hhfield .lhfield = n ;
    } 
  while ( k++ < for_end ) ;} 
  goto lab40 ;
  lab45: p = 3 ;
  if ( mc >= 268402688L ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 573 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 573 ) ;
      } 
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 574 ;
      helpline [0 ]= 575 ;
    } 
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 576 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 576 ) ;
      } 
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 577 ;
      helpline [1 ]= 578 ;
      helpline [0 ]= 575 ;
    } 
  } 
  putgeterror () ;
  lab40: if ( internal [6 ]> 0 ) 
  printpen ( p , 572 , true ) ;
  Result = p ;
  return Result ;
} 
halfword 
ztrivialknot ( scaled x , scaled y ) 
{
  register halfword Result; halfword p  ;
  p = getnode ( 7 ) ;
  mem [p ].hhfield .b0 = 1 ;
  mem [p ].hhfield .b1 = 1 ;
  mem [p + 1 ].cint = x ;
  mem [p + 3 ].cint = x ;
  mem [p + 5 ].cint = x ;
  mem [p + 2 ].cint = y ;
  mem [p + 4 ].cint = y ;
  mem [p + 6 ].cint = y ;
  Result = p ;
  return Result ;
} 
halfword 
zmakepath ( halfword penhead ) 
{
  register halfword Result; halfword p  ;
  unsigned char k  ;
  halfword h  ;
  integer m, n  ;
  halfword w, ww  ;
  p = memtop - 1 ;
  {register integer for_end; k = 1 ;for_end = 8 ; if ( k <= for_end) do 
    {
      octant = octantcode [k ];
      h = penhead + octant ;
      n = mem [h ].hhfield .lhfield ;
      w = mem [h ].hhfield .v.RH ;
      if ( ! odd ( k ) ) 
      w = mem [w ].hhfield .lhfield ;
      {register integer for_end; m = 1 ;for_end = n + 1 ; if ( m <= for_end) 
      do 
	{
	  if ( odd ( k ) ) 
	  ww = mem [w ].hhfield .v.RH ;
	  else ww = mem [w ].hhfield .lhfield ;
	  if ( ( mem [ww + 1 ].cint != mem [w + 1 ].cint ) || ( mem [ww + 
	  2 ].cint != mem [w + 2 ].cint ) ) 
	  {
	    unskew ( mem [ww + 1 ].cint , mem [ww + 2 ].cint , octant ) ;
	    mem [p ].hhfield .v.RH = trivialknot ( curx , cury ) ;
	    p = mem [p ].hhfield .v.RH ;
	  } 
	  w = ww ;
	} 
      while ( m++ < for_end ) ;} 
    } 
  while ( k++ < for_end ) ;} 
  if ( p == memtop - 1 ) 
  {
    w = mem [penhead + 1 ].hhfield .v.RH ;
    p = trivialknot ( mem [w + 1 ].cint + mem [w + 2 ].cint , mem [w + 2 
    ].cint ) ;
    mem [memtop - 1 ].hhfield .v.RH = p ;
  } 
  mem [p ].hhfield .v.RH = mem [memtop - 1 ].hhfield .v.RH ;
  Result = mem [memtop - 1 ].hhfield .v.RH ;
  return Result ;
} 
void 
zfindoffset ( scaled x , scaled y , halfword p ) 
{
  /* 30 10 */ unsigned char octant  ;
  schar s  ;
  integer n  ;
  halfword h, w, ww  ;
  if ( x > 0 ) 
  octant = 1 ;
  else if ( x == 0 ) {
      
    if ( y <= 0 ) {
	
      if ( y == 0 ) 
      {
	curx = 0 ;
	cury = 0 ;
	goto lab10 ;
      } 
      else octant = 2 ;
    } 
    else octant = 1 ;
  } 
  else {
      
    x = - (integer) x ;
    if ( y == 0 ) 
    octant = 4 ;
    else octant = 2 ;
  } 
  if ( y < 0 ) 
  {
    octant = octant + 2 ;
    y = - (integer) y ;
  } 
  if ( x >= y ) 
  x = x - y ;
  else {
      
    octant = octant + 4 ;
    x = y - x ;
    y = y - x ;
  } 
  if ( odd ( octantnumber [octant ]) ) 
  s = -1 ;
  else s = 1 ;
  h = p + octant ;
  w = mem [mem [h ].hhfield .v.RH ].hhfield .v.RH ;
  ww = mem [w ].hhfield .v.RH ;
  n = mem [h ].hhfield .lhfield ;
  while ( n > 1 ) {
      
    if ( abvscd ( x , mem [ww + 2 ].cint - mem [w + 2 ].cint , y , mem [
    ww + 1 ].cint - mem [w + 1 ].cint ) != s ) 
    goto lab30 ;
    w = ww ;
    ww = mem [w ].hhfield .v.RH ;
    decr ( n ) ;
  } 
  lab30: unskew ( mem [w + 1 ].cint , mem [w + 2 ].cint , octant ) ;
  lab10: ;
} 
void 
zsplitforoffset ( halfword p , fraction t ) 
{
  halfword q  ;
  halfword r  ;
  q = mem [p ].hhfield .v.RH ;
  splitcubic ( p , t , mem [q + 1 ].cint , mem [q + 2 ].cint ) ;
  r = mem [p ].hhfield .v.RH ;
  if ( mem [r + 2 ].cint < mem [p + 2 ].cint ) 
  mem [r + 2 ].cint = mem [p + 2 ].cint ;
  else if ( mem [r + 2 ].cint > mem [q + 2 ].cint ) 
  mem [r + 2 ].cint = mem [q + 2 ].cint ;
  if ( mem [r + 1 ].cint < mem [p + 1 ].cint ) 
  mem [r + 1 ].cint = mem [p + 1 ].cint ;
  else if ( mem [r + 1 ].cint > mem [q + 1 ].cint ) 
  mem [r + 1 ].cint = mem [q + 1 ].cint ;
} 
void 
zfinoffsetprep ( halfword p , halfword k , halfword w , integer x0 , integer 
x1 , integer x2 , integer y0 , integer y1 , integer y2 , boolean rising , 
integer n ) 
{
  /* 10 */ halfword ww  ;
  scaled du, dv  ;
  integer t0, t1, t2  ;
  fraction t  ;
  fraction s  ;
  integer v  ;
  while ( true ) {
      
    mem [p ].hhfield .b1 = k ;
    if ( rising ) {
	
      if ( k == n ) 
      goto lab10 ;
      else ww = mem [w ].hhfield .v.RH ;
    } 
    else if ( k == 1 ) 
    goto lab10 ;
    else ww = mem [w ].hhfield .lhfield ;
    du = mem [ww + 1 ].cint - mem [w + 1 ].cint ;
    dv = mem [ww + 2 ].cint - mem [w + 2 ].cint ;
    if ( abs ( du ) >= abs ( dv ) ) 
    {
      s = makefraction ( dv , du ) ;
      t0 = takefraction ( x0 , s ) - y0 ;
      t1 = takefraction ( x1 , s ) - y1 ;
      t2 = takefraction ( x2 , s ) - y2 ;
    } 
    else {
	
      s = makefraction ( du , dv ) ;
      t0 = x0 - takefraction ( y0 , s ) ;
      t1 = x1 - takefraction ( y1 , s ) ;
      t2 = x2 - takefraction ( y2 , s ) ;
    } 
    t = crossingpoint ( t0 , t1 , t2 ) ;
    if ( t >= 268435456L ) 
    goto lab10 ;
    {
      splitforoffset ( p , t ) ;
      mem [p ].hhfield .b1 = k ;
      p = mem [p ].hhfield .v.RH ;
      v = x0 - takefraction ( x0 - x1 , t ) ;
      x1 = x1 - takefraction ( x1 - x2 , t ) ;
      x0 = v - takefraction ( v - x1 , t ) ;
      v = y0 - takefraction ( y0 - y1 , t ) ;
      y1 = y1 - takefraction ( y1 - y2 , t ) ;
      y0 = v - takefraction ( v - y1 , t ) ;
      t1 = t1 - takefraction ( t1 - t2 , t ) ;
      if ( t1 > 0 ) 
      t1 = 0 ;
      t = crossingpoint ( 0 , - (integer) t1 , - (integer) t2 ) ;
      if ( t < 268435456L ) 
      {
	splitforoffset ( p , t ) ;
	mem [mem [p ].hhfield .v.RH ].hhfield .b1 = k ;
	v = x1 - takefraction ( x1 - x2 , t ) ;
	x1 = x0 - takefraction ( x0 - x1 , t ) ;
	x2 = x1 - takefraction ( x1 - v , t ) ;
	v = y1 - takefraction ( y1 - y2 , t ) ;
	y1 = y0 - takefraction ( y0 - y1 , t ) ;
	y2 = y1 - takefraction ( y1 - v , t ) ;
      } 
    } 
    if ( rising ) 
    incr ( k ) ;
    else decr ( k ) ;
    w = ww ;
  } 
  lab10: ;
} 
void 
zoffsetprep ( halfword c , halfword h ) 
{
  /* 30 45 */ halfword n  ;
  halfword p, q, r, lh, ww  ;
  halfword k  ;
  halfword w  ;
  integer x0, x1, x2, y0, y1, y2  ;
  integer t0, t1, t2  ;
  integer du, dv, dx, dy  ;
  integer lmaxcoef  ;
  integer x0a, x1a, x2a, y0a, y1a, y2a  ;
  fraction t  ;
  fraction s  ;
  p = c ;
  n = mem [h ].hhfield .lhfield ;
  lh = mem [h ].hhfield .v.RH ;
  while ( mem [p ].hhfield .b1 != 0 ) {
      
    q = mem [p ].hhfield .v.RH ;
    if ( n <= 1 ) 
    mem [p ].hhfield .b1 = 1 ;
    else {
	
      x0 = mem [p + 5 ].cint - mem [p + 1 ].cint ;
      x2 = mem [q + 1 ].cint - mem [q + 3 ].cint ;
      x1 = mem [q + 3 ].cint - mem [p + 5 ].cint ;
      y0 = mem [p + 6 ].cint - mem [p + 2 ].cint ;
      y2 = mem [q + 2 ].cint - mem [q + 4 ].cint ;
      y1 = mem [q + 4 ].cint - mem [p + 6 ].cint ;
      lmaxcoef = abs ( x0 ) ;
      if ( abs ( x1 ) > lmaxcoef ) 
      lmaxcoef = abs ( x1 ) ;
      if ( abs ( x2 ) > lmaxcoef ) 
      lmaxcoef = abs ( x2 ) ;
      if ( abs ( y0 ) > lmaxcoef ) 
      lmaxcoef = abs ( y0 ) ;
      if ( abs ( y1 ) > lmaxcoef ) 
      lmaxcoef = abs ( y1 ) ;
      if ( abs ( y2 ) > lmaxcoef ) 
      lmaxcoef = abs ( y2 ) ;
      if ( lmaxcoef == 0 ) 
      goto lab45 ;
      while ( lmaxcoef < 134217728L ) {
	  
	lmaxcoef = lmaxcoef + lmaxcoef ;
	x0 = x0 + x0 ;
	x1 = x1 + x1 ;
	x2 = x2 + x2 ;
	y0 = y0 + y0 ;
	y1 = y1 + y1 ;
	y2 = y2 + y2 ;
      } 
      dx = x0 ;
      dy = y0 ;
      if ( dx == 0 ) {
	  
	if ( dy == 0 ) 
	{
	  dx = x1 ;
	  dy = y1 ;
	  if ( dx == 0 ) {
	      
	    if ( dy == 0 ) 
	    {
	      dx = x2 ;
	      dy = y2 ;
	    } 
	  } 
	} 
      } 
      if ( dx == 0 ) 
      finoffsetprep ( p , n , mem [mem [lh ].hhfield .lhfield ].hhfield 
      .lhfield , - (integer) x0 , - (integer) x1 , - (integer) x2 , 
      - (integer) y0 , - (integer) y1 , - (integer) y2 , false , n ) ;
      else {
	  
	k = 1 ;
	w = mem [lh ].hhfield .v.RH ;
	while ( true ) {
	    
	  if ( k == n ) 
	  goto lab30 ;
	  ww = mem [w ].hhfield .v.RH ;
	  if ( abvscd ( dy , abs ( mem [ww + 1 ].cint - mem [w + 1 ].cint 
	  ) , dx , abs ( mem [ww + 2 ].cint - mem [w + 2 ].cint ) ) >= 0 ) 
	  {
	    incr ( k ) ;
	    w = ww ;
	  } 
	  else goto lab30 ;
	} 
	lab30: ;
	if ( k == 1 ) 
	t = 268435457L ;
	else {
	    
	  ww = mem [w ].hhfield .lhfield ;
	  du = mem [ww + 1 ].cint - mem [w + 1 ].cint ;
	  dv = mem [ww + 2 ].cint - mem [w + 2 ].cint ;
	  if ( abs ( du ) >= abs ( dv ) ) 
	  {
	    s = makefraction ( dv , du ) ;
	    t0 = takefraction ( x0 , s ) - y0 ;
	    t1 = takefraction ( x1 , s ) - y1 ;
	    t2 = takefraction ( x2 , s ) - y2 ;
	  } 
	  else {
	      
	    s = makefraction ( du , dv ) ;
	    t0 = x0 - takefraction ( y0 , s ) ;
	    t1 = x1 - takefraction ( y1 , s ) ;
	    t2 = x2 - takefraction ( y2 , s ) ;
	  } 
	  t = crossingpoint ( - (integer) t0 , - (integer) t1 , - (integer) t2 
	  ) ;
	} 
	if ( t >= 268435456L ) 
	finoffsetprep ( p , k , w , x0 , x1 , x2 , y0 , y1 , y2 , true , n ) ;
	else {
	    
	  splitforoffset ( p , t ) ;
	  r = mem [p ].hhfield .v.RH ;
	  x1a = x0 - takefraction ( x0 - x1 , t ) ;
	  x1 = x1 - takefraction ( x1 - x2 , t ) ;
	  x2a = x1a - takefraction ( x1a - x1 , t ) ;
	  y1a = y0 - takefraction ( y0 - y1 , t ) ;
	  y1 = y1 - takefraction ( y1 - y2 , t ) ;
	  y2a = y1a - takefraction ( y1a - y1 , t ) ;
	  finoffsetprep ( p , k , w , x0 , x1a , x2a , y0 , y1a , y2a , true , 
	  n ) ;
	  x0 = x2a ;
	  y0 = y2a ;
	  t1 = t1 - takefraction ( t1 - t2 , t ) ;
	  if ( t1 < 0 ) 
	  t1 = 0 ;
	  t = crossingpoint ( 0 , t1 , t2 ) ;
	  if ( t < 268435456L ) 
	  {
	    splitforoffset ( r , t ) ;
	    x1a = x1 - takefraction ( x1 - x2 , t ) ;
	    x1 = x0 - takefraction ( x0 - x1 , t ) ;
	    x0a = x1 - takefraction ( x1 - x1a , t ) ;
	    y1a = y1 - takefraction ( y1 - y2 , t ) ;
	    y1 = y0 - takefraction ( y0 - y1 , t ) ;
	    y0a = y1 - takefraction ( y1 - y1a , t ) ;
	    finoffsetprep ( mem [r ].hhfield .v.RH , k , w , x0a , x1a , x2 
	    , y0a , y1a , y2 , true , n ) ;
	    x2 = x0a ;
	    y2 = y0a ;
	  } 
	  finoffsetprep ( r , k - 1 , ww , - (integer) x0 , - (integer) x1 , 
	  - (integer) x2 , - (integer) y0 , - (integer) y1 , - (integer) y2 , 
	  false , n ) ;
	} 
      } 
      lab45: ;
    } 
    do {
	r = mem [p ].hhfield .v.RH ;
      if ( mem [p + 1 ].cint == mem [p + 5 ].cint ) {
	  
	if ( mem [p + 2 ].cint == mem [p + 6 ].cint ) {
	    
	  if ( mem [p + 1 ].cint == mem [r + 3 ].cint ) {
	      
	    if ( mem [p + 2 ].cint == mem [r + 4 ].cint ) {
		
	      if ( mem [p + 1 ].cint == mem [r + 1 ].cint ) {
		  
		if ( mem [p + 2 ].cint == mem [r + 2 ].cint ) 
		{
		  removecubic ( p ) ;
		  if ( r == q ) 
		  q = p ;
		  r = p ;
		} 
	      } 
	    } 
	  } 
	} 
      } 
      p = r ;
    } while ( ! ( p == q ) ) ;
  } 
} 
void 
zskewlineedges ( halfword p , halfword w , halfword ww ) 
{
  scaled x0, y0, x1, y1  ;
  if ( ( mem [w + 1 ].cint != mem [ww + 1 ].cint ) || ( mem [w + 2 ]
  .cint != mem [ww + 2 ].cint ) ) 
  {
    x0 = mem [p + 1 ].cint + mem [w + 1 ].cint ;
    y0 = mem [p + 2 ].cint + mem [w + 2 ].cint ;
    x1 = mem [p + 1 ].cint + mem [ww + 1 ].cint ;
    y1 = mem [p + 2 ].cint + mem [ww + 2 ].cint ;
    unskew ( x0 , y0 , octant ) ;
    x0 = curx ;
    y0 = cury ;
    unskew ( x1 , y1 , octant ) ;
	;
#ifdef STAT
    if ( internal [10 ]> 65536L ) 
    {
      printnl ( 585 ) ;
      printtwo ( x0 , y0 ) ;
      print ( 584 ) ;
      printtwo ( curx , cury ) ;
      printnl ( 261 ) ;
    } 
#endif /* STAT */
    lineedges ( x0 , y0 , curx , cury ) ;
  } 
} 
void 
zdualmoves ( halfword h , halfword p , halfword q ) 
{
  /* 30 31 */ halfword r, s  ;
  integer m, n  ;
  integer mm0, mm1  ;
  integer k  ;
  halfword w, ww  ;
  integer smoothbot, smoothtop  ;
  scaled xx, yy, xp, yp, delx, dely, tx, ty  ;
  k = mem [h ].hhfield .lhfield + 1 ;
  ww = mem [h ].hhfield .v.RH ;
  w = mem [ww ].hhfield .lhfield ;
  mm0 = floorunscaled ( mem [p + 1 ].cint + mem [w + 1 ].cint - xycorr [
  octant ]) ;
  mm1 = floorunscaled ( mem [q + 1 ].cint + mem [ww + 1 ].cint - xycorr [
  octant ]) ;
  {register integer for_end; n = 1 ;for_end = n1 - n0 + 1 ; if ( n <= 
  for_end) do 
    envmove [n ]= mm1 ;
  while ( n++ < for_end ) ;} 
  envmove [0 ]= mm0 ;
  moveptr = 0 ;
  m = mm0 ;
  r = p ;
  while ( true ) {
      
    if ( r == q ) 
    smoothtop = moveptr ;
    while ( mem [r ].hhfield .b1 != k ) {
	
      xx = mem [r + 1 ].cint + mem [w + 1 ].cint ;
      yy = mem [r + 2 ].cint + mem [w + 2 ].cint + 32768L ;
	;
#ifdef STAT
      if ( internal [10 ]> 65536L ) 
      {
	printnl ( 586 ) ;
	printint ( k ) ;
	print ( 587 ) ;
	unskew ( xx , yy - 32768L , octant ) ;
	printtwo ( curx , cury ) ;
      } 
#endif /* STAT */
      if ( mem [r ].hhfield .b1 < k ) 
      {
	decr ( k ) ;
	w = mem [w ].hhfield .lhfield ;
	xp = mem [r + 1 ].cint + mem [w + 1 ].cint ;
	yp = mem [r + 2 ].cint + mem [w + 2 ].cint + 32768L ;
	if ( yp != yy ) 
	{
	  ty = floorscaled ( yy - ycorr [octant ]) ;
	  dely = yp - yy ;
	  yy = yy - ty ;
	  ty = yp - ycorr [octant ]- ty ;
	  if ( ty >= 65536L ) 
	  {
	    delx = xp - xx ;
	    yy = 65536L - yy ;
	    while ( true ) {
		
	      if ( m < envmove [moveptr ]) 
	      envmove [moveptr ]= m ;
	      tx = takefraction ( delx , makefraction ( yy , dely ) ) ;
	      if ( abvscd ( tx , dely , delx , yy ) + xycorr [octant ]> 0 ) 
	      decr ( tx ) ;
	      m = floorunscaled ( xx + tx ) ;
	      ty = ty - 65536L ;
	      incr ( moveptr ) ;
	      if ( ty < 65536L ) 
	      goto lab31 ;
	      yy = yy + 65536L ;
	    } 
	    lab31: if ( m < envmove [moveptr ]) 
	    envmove [moveptr ]= m ;
	  } 
	} 
      } 
      else {
	  
	incr ( k ) ;
	w = mem [w ].hhfield .v.RH ;
	xp = mem [r + 1 ].cint + mem [w + 1 ].cint ;
	yp = mem [r + 2 ].cint + mem [w + 2 ].cint + 32768L ;
      } 
	;
#ifdef STAT
      if ( internal [10 ]> 65536L ) 
      {
	print ( 584 ) ;
	unskew ( xp , yp - 32768L , octant ) ;
	printtwo ( curx , cury ) ;
	printnl ( 261 ) ;
      } 
#endif /* STAT */
      m = floorunscaled ( xp - xycorr [octant ]) ;
      moveptr = floorunscaled ( yp - ycorr [octant ]) - n0 ;
      if ( m < envmove [moveptr ]) 
      envmove [moveptr ]= m ;
    } 
    if ( r == p ) 
    smoothbot = moveptr ;
    if ( r == q ) 
    goto lab30 ;
    move [moveptr ]= 1 ;
    n = moveptr ;
    s = mem [r ].hhfield .v.RH ;
    makemoves ( mem [r + 1 ].cint + mem [w + 1 ].cint , mem [r + 5 ]
    .cint + mem [w + 1 ].cint , mem [s + 3 ].cint + mem [w + 1 ].cint , 
    mem [s + 1 ].cint + mem [w + 1 ].cint , mem [r + 2 ].cint + mem [w 
    + 2 ].cint + 32768L , mem [r + 6 ].cint + mem [w + 2 ].cint + 32768L 
    , mem [s + 4 ].cint + mem [w + 2 ].cint + 32768L , mem [s + 2 ].cint 
    + mem [w + 2 ].cint + 32768L , xycorr [octant ], ycorr [octant ]) ;
    do {
	if ( m < envmove [n ]) 
      envmove [n ]= m ;
      m = m + move [n ]- 1 ;
      incr ( n ) ;
    } while ( ! ( n > moveptr ) ) ;
    r = s ;
  } 
  lab30: 
	;
#ifdef TEXMF_DEBUG
  if ( ( m != mm1 ) || ( moveptr != n1 - n0 ) ) 
  confusion ( 50 ) ;
#endif /* TEXMF_DEBUG */
  move [0 ]= d0 + envmove [1 ]- mm0 ;
  {register integer for_end; n = 1 ;for_end = moveptr ; if ( n <= for_end) 
  do 
    move [n ]= envmove [n + 1 ]- envmove [n ]+ 1 ;
  while ( n++ < for_end ) ;} 
  move [moveptr ]= move [moveptr ]- d1 ;
  if ( internal [35 ]> 0 ) 
  smoothmoves ( smoothbot , smoothtop ) ;
  movetoedges ( m0 , n0 , m1 , n1 ) ;
  if ( mem [q + 6 ].cint == 1 ) 
  {
    w = mem [h ].hhfield .v.RH ;
    skewlineedges ( q , w , mem [w ].hhfield .lhfield ) ;
  } 
} 
void 
zfillenvelope ( halfword spechead ) 
{
  /* 30 31 */ halfword p, q, r, s  ;
  halfword h  ;
  halfword www  ;
  integer m, n  ;
  integer mm0, mm1  ;
  integer k  ;
  halfword w, ww  ;
  integer smoothbot, smoothtop  ;
  scaled xx, yy, xp, yp, delx, dely, tx, ty  ;
  if ( internal [10 ]> 0 ) 
  beginedgetracing () ;
  p = spechead ;
  do {
      octant = mem [p + 3 ].cint ;
    h = curpen + octant ;
    q = p ;
    while ( mem [q ].hhfield .b1 != 0 ) q = mem [q ].hhfield .v.RH ;
    w = mem [h ].hhfield .v.RH ;
    if ( mem [p + 4 ].cint == 1 ) 
    w = mem [w ].hhfield .lhfield ;
	;
#ifdef STAT
    if ( internal [10 ]> 65536L ) 
    {
      printnl ( 580 ) ;
      print ( octantdir [octant ]) ;
      print ( 558 ) ;
      printint ( mem [h ].hhfield .lhfield ) ;
      if ( mem [h ].hhfield .lhfield != 1 ) 
      print ( 581 ) ;
      else print ( 582 ) ;
      print ( 583 ) ;
      unskew ( mem [p + 1 ].cint + mem [w + 1 ].cint , mem [p + 2 ].cint 
      + mem [w + 2 ].cint , octant ) ;
      printtwo ( curx , cury ) ;
      ww = mem [h ].hhfield .v.RH ;
      if ( mem [q + 6 ].cint == 1 ) 
      ww = mem [ww ].hhfield .lhfield ;
      print ( 584 ) ;
      unskew ( mem [q + 1 ].cint + mem [ww + 1 ].cint , mem [q + 2 ]
      .cint + mem [ww + 2 ].cint , octant ) ;
      printtwo ( curx , cury ) ;
    } 
#endif /* STAT */
    ww = mem [h ].hhfield .v.RH ;
    www = ww ;
    if ( odd ( octantnumber [octant ]) ) 
    www = mem [www ].hhfield .lhfield ;
    else ww = mem [ww ].hhfield .lhfield ;
    if ( w != ww ) 
    skewlineedges ( p , w , ww ) ;
    endround ( mem [p + 1 ].cint + mem [ww + 1 ].cint , mem [p + 2 ]
    .cint + mem [ww + 2 ].cint ) ;
    m0 = m1 ;
    n0 = n1 ;
    d0 = d1 ;
    endround ( mem [q + 1 ].cint + mem [www + 1 ].cint , mem [q + 2 ]
    .cint + mem [www + 2 ].cint ) ;
    if ( n1 - n0 >= movesize ) 
    overflow ( 540 , movesize ) ;
    offsetprep ( p , h ) ;
    q = p ;
    while ( mem [q ].hhfield .b1 != 0 ) q = mem [q ].hhfield .v.RH ;
    if ( odd ( octantnumber [octant ]) ) 
    {
      k = 0 ;
      w = mem [h ].hhfield .v.RH ;
      ww = mem [w ].hhfield .lhfield ;
      mm0 = floorunscaled ( mem [p + 1 ].cint + mem [w + 1 ].cint - xycorr 
      [octant ]) ;
      mm1 = floorunscaled ( mem [q + 1 ].cint + mem [ww + 1 ].cint - 
      xycorr [octant ]) ;
      {register integer for_end; n = 0 ;for_end = n1 - n0 ; if ( n <= 
      for_end) do 
	envmove [n ]= mm0 ;
      while ( n++ < for_end ) ;} 
      envmove [n1 - n0 ]= mm1 ;
      moveptr = 0 ;
      m = mm0 ;
      r = p ;
      mem [q ].hhfield .b1 = mem [h ].hhfield .lhfield + 1 ;
      while ( true ) {
	  
	if ( r == q ) 
	smoothtop = moveptr ;
	while ( mem [r ].hhfield .b1 != k ) {
	    
	  xx = mem [r + 1 ].cint + mem [w + 1 ].cint ;
	  yy = mem [r + 2 ].cint + mem [w + 2 ].cint + 32768L ;
	;
#ifdef STAT
	  if ( internal [10 ]> 65536L ) 
	  {
	    printnl ( 586 ) ;
	    printint ( k ) ;
	    print ( 587 ) ;
	    unskew ( xx , yy - 32768L , octant ) ;
	    printtwo ( curx , cury ) ;
	  } 
#endif /* STAT */
	  if ( mem [r ].hhfield .b1 > k ) 
	  {
	    incr ( k ) ;
	    w = mem [w ].hhfield .v.RH ;
	    xp = mem [r + 1 ].cint + mem [w + 1 ].cint ;
	    yp = mem [r + 2 ].cint + mem [w + 2 ].cint + 32768L ;
	    if ( yp != yy ) 
	    {
	      ty = floorscaled ( yy - ycorr [octant ]) ;
	      dely = yp - yy ;
	      yy = yy - ty ;
	      ty = yp - ycorr [octant ]- ty ;
	      if ( ty >= 65536L ) 
	      {
		delx = xp - xx ;
		yy = 65536L - yy ;
		while ( true ) {
		    
		  tx = takefraction ( delx , makefraction ( yy , dely ) ) ;
		  if ( abvscd ( tx , dely , delx , yy ) + xycorr [octant ]> 
		  0 ) 
		  decr ( tx ) ;
		  m = floorunscaled ( xx + tx ) ;
		  if ( m > envmove [moveptr ]) 
		  envmove [moveptr ]= m ;
		  ty = ty - 65536L ;
		  if ( ty < 65536L ) 
		  goto lab31 ;
		  yy = yy + 65536L ;
		  incr ( moveptr ) ;
		} 
		lab31: ;
	      } 
	    } 
	  } 
	  else {
	      
	    decr ( k ) ;
	    w = mem [w ].hhfield .lhfield ;
	    xp = mem [r + 1 ].cint + mem [w + 1 ].cint ;
	    yp = mem [r + 2 ].cint + mem [w + 2 ].cint + 32768L ;
	  } 
	;
#ifdef STAT
	  if ( internal [10 ]> 65536L ) 
	  {
	    print ( 584 ) ;
	    unskew ( xp , yp - 32768L , octant ) ;
	    printtwo ( curx , cury ) ;
	    printnl ( 261 ) ;
	  } 
#endif /* STAT */
	  m = floorunscaled ( xp - xycorr [octant ]) ;
	  moveptr = floorunscaled ( yp - ycorr [octant ]) - n0 ;
	  if ( m > envmove [moveptr ]) 
	  envmove [moveptr ]= m ;
	} 
	if ( r == p ) 
	smoothbot = moveptr ;
	if ( r == q ) 
	goto lab30 ;
	move [moveptr ]= 1 ;
	n = moveptr ;
	s = mem [r ].hhfield .v.RH ;
	makemoves ( mem [r + 1 ].cint + mem [w + 1 ].cint , mem [r + 5 ]
	.cint + mem [w + 1 ].cint , mem [s + 3 ].cint + mem [w + 1 ]
	.cint , mem [s + 1 ].cint + mem [w + 1 ].cint , mem [r + 2 ]
	.cint + mem [w + 2 ].cint + 32768L , mem [r + 6 ].cint + mem [w + 
	2 ].cint + 32768L , mem [s + 4 ].cint + mem [w + 2 ].cint + 
	32768L , mem [s + 2 ].cint + mem [w + 2 ].cint + 32768L , xycorr [
	octant ], ycorr [octant ]) ;
	do {
	    m = m + move [n ]- 1 ;
	  if ( m > envmove [n ]) 
	  envmove [n ]= m ;
	  incr ( n ) ;
	} while ( ! ( n > moveptr ) ) ;
	r = s ;
      } 
      lab30: 
	;
#ifdef TEXMF_DEBUG
      if ( ( m != mm1 ) || ( moveptr != n1 - n0 ) ) 
      confusion ( 49 ) ;
#endif /* TEXMF_DEBUG */
      move [0 ]= d0 + envmove [0 ]- mm0 ;
      {register integer for_end; n = 1 ;for_end = moveptr ; if ( n <= 
      for_end) do 
	move [n ]= envmove [n ]- envmove [n - 1 ]+ 1 ;
      while ( n++ < for_end ) ;} 
      move [moveptr ]= move [moveptr ]- d1 ;
      if ( internal [35 ]> 0 ) 
      smoothmoves ( smoothbot , smoothtop ) ;
      movetoedges ( m0 , n0 , m1 , n1 ) ;
      if ( mem [q + 6 ].cint == 0 ) 
      {
	w = mem [h ].hhfield .v.RH ;
	skewlineedges ( q , mem [w ].hhfield .lhfield , w ) ;
      } 
    } 
    else dualmoves ( h , p , q ) ;
    mem [q ].hhfield .b1 = 0 ;
    p = mem [q ].hhfield .v.RH ;
  } while ( ! ( p == spechead ) ) ;
  if ( internal [10 ]> 0 ) 
  endedgetracing () ;
  tossknotlist ( spechead ) ;
} 
halfword 
zmakeellipse ( scaled majoraxis , scaled minoraxis , angle theta ) 
{
  /* 30 31 40 */ register halfword Result; halfword p, q, r, s  ;
  halfword h  ;
  integer alpha, beta, gamma, delta  ;
  integer c, d  ;
  integer u, v  ;
  boolean symmetric  ;
  if ( ( majoraxis == minoraxis ) || ( theta % 94371840L == 0 ) ) 
  {
    symmetric = true ;
    alpha = 0 ;
    if ( odd ( theta / 94371840L ) ) 
    {
      beta = majoraxis ;
      gamma = minoraxis ;
      nsin = 268435456L ;
      ncos = 0 ;
    } 
    else {
	
      beta = minoraxis ;
      gamma = majoraxis ;
      theta = 0 ;
    } 
  } 
  else {
      
    symmetric = false ;
    nsincos ( theta ) ;
    gamma = takefraction ( majoraxis , nsin ) ;
    delta = takefraction ( minoraxis , ncos ) ;
    beta = pythadd ( gamma , delta ) ;
    alpha = makefraction ( gamma , beta ) ;
    alpha = takefraction ( majoraxis , alpha ) ;
    alpha = takefraction ( alpha , ncos ) ;
    alpha = ( alpha + 32768L ) / 65536L ;
    gamma = takefraction ( minoraxis , nsin ) ;
    gamma = pythadd ( takefraction ( majoraxis , ncos ) , gamma ) ;
  } 
  beta = ( beta + 32768L ) / 65536L ;
  gamma = ( gamma + 32768L ) / 65536L ;
  p = getnode ( 7 ) ;
  q = getnode ( 7 ) ;
  r = getnode ( 7 ) ;
  if ( symmetric ) 
  s = 0 ;
  else s = getnode ( 7 ) ;
  h = p ;
  mem [p ].hhfield .v.RH = q ;
  mem [q ].hhfield .v.RH = r ;
  mem [r ].hhfield .v.RH = s ;
  if ( beta == 0 ) 
  beta = 1 ;
  if ( gamma == 0 ) 
  gamma = 1 ;
  if ( gamma <= abs ( alpha ) ) {
      
    if ( alpha > 0 ) 
    alpha = gamma - 1 ;
    else alpha = 1 - gamma ;
  } 
  mem [p + 1 ].cint = - (integer) alpha * 32768L ;
  mem [p + 2 ].cint = - (integer) beta * 32768L ;
  mem [q + 1 ].cint = gamma * 32768L ;
  mem [q + 2 ].cint = mem [p + 2 ].cint ;
  mem [r + 1 ].cint = mem [q + 1 ].cint ;
  mem [p + 5 ].cint = 0 ;
  mem [q + 3 ].cint = -32768L ;
  mem [q + 5 ].cint = 32768L ;
  mem [r + 3 ].cint = 0 ;
  mem [r + 5 ].cint = 0 ;
  mem [p + 6 ].cint = beta ;
  mem [q + 6 ].cint = gamma ;
  mem [r + 6 ].cint = beta ;
  mem [q + 4 ].cint = gamma + alpha ;
  if ( symmetric ) 
  {
    mem [r + 2 ].cint = 0 ;
    mem [r + 4 ].cint = beta ;
  } 
  else {
      
    mem [r + 2 ].cint = - (integer) mem [p + 2 ].cint ;
    mem [r + 4 ].cint = beta + beta ;
    mem [s + 1 ].cint = - (integer) mem [p + 1 ].cint ;
    mem [s + 2 ].cint = mem [r + 2 ].cint ;
    mem [s + 3 ].cint = 32768L ;
    mem [s + 4 ].cint = gamma - alpha ;
  } 
  while ( true ) {
      
    u = mem [p + 5 ].cint + mem [q + 5 ].cint ;
    v = mem [q + 3 ].cint + mem [r + 3 ].cint ;
    c = mem [p + 6 ].cint + mem [q + 6 ].cint ;
    delta = pythadd ( u , v ) ;
    if ( majoraxis == minoraxis ) 
    d = majoraxis ;
    else {
	
      if ( theta == 0 ) 
      {
	alpha = u ;
	beta = v ;
      } 
      else {
	  
	alpha = takefraction ( u , ncos ) + takefraction ( v , nsin ) ;
	beta = takefraction ( v , ncos ) - takefraction ( u , nsin ) ;
      } 
      alpha = makefraction ( alpha , delta ) ;
      beta = makefraction ( beta , delta ) ;
      d = pythadd ( takefraction ( majoraxis , alpha ) , takefraction ( 
      minoraxis , beta ) ) ;
    } 
    alpha = abs ( u ) ;
    beta = abs ( v ) ;
    if ( alpha < beta ) 
    {
      alpha = abs ( v ) ;
      beta = abs ( u ) ;
    } 
    if ( internal [38 ]!= 0 ) 
    d = d - takefraction ( internal [38 ], makefraction ( beta + beta , 
    delta ) ) ;
    d = takefraction ( ( d + 4 ) / 8 , delta ) ;
    alpha = alpha / 32768L ;
    if ( d < alpha ) 
    d = alpha ;
    delta = c - d ;
    if ( delta > 0 ) 
    {
      if ( delta > mem [r + 4 ].cint ) 
      delta = mem [r + 4 ].cint ;
      if ( delta >= mem [q + 4 ].cint ) 
      {
	delta = mem [q + 4 ].cint ;
	mem [p + 6 ].cint = c - delta ;
	mem [p + 5 ].cint = u ;
	mem [q + 3 ].cint = v ;
	mem [q + 1 ].cint = mem [q + 1 ].cint - delta * mem [r + 3 ]
	.cint ;
	mem [q + 2 ].cint = mem [q + 2 ].cint + delta * mem [q + 5 ]
	.cint ;
	mem [r + 4 ].cint = mem [r + 4 ].cint - delta ;
      } 
      else {
	  
	s = getnode ( 7 ) ;
	mem [p ].hhfield .v.RH = s ;
	mem [s ].hhfield .v.RH = q ;
	mem [s + 1 ].cint = mem [q + 1 ].cint + delta * mem [q + 3 ]
	.cint ;
	mem [s + 2 ].cint = mem [q + 2 ].cint - delta * mem [p + 5 ]
	.cint ;
	mem [q + 1 ].cint = mem [q + 1 ].cint - delta * mem [r + 3 ]
	.cint ;
	mem [q + 2 ].cint = mem [q + 2 ].cint + delta * mem [q + 5 ]
	.cint ;
	mem [s + 3 ].cint = mem [q + 3 ].cint ;
	mem [s + 5 ].cint = u ;
	mem [q + 3 ].cint = v ;
	mem [s + 6 ].cint = c - delta ;
	mem [s + 4 ].cint = mem [q + 4 ].cint - delta ;
	mem [q + 4 ].cint = delta ;
	mem [r + 4 ].cint = mem [r + 4 ].cint - delta ;
      } 
    } 
    else p = q ;
    while ( true ) {
	
      q = mem [p ].hhfield .v.RH ;
      if ( q == 0 ) 
      goto lab30 ;
      if ( mem [q + 4 ].cint == 0 ) 
      {
	mem [p ].hhfield .v.RH = mem [q ].hhfield .v.RH ;
	mem [p + 6 ].cint = mem [q + 6 ].cint ;
	mem [p + 5 ].cint = mem [q + 5 ].cint ;
	freenode ( q , 7 ) ;
      } 
      else {
	  
	r = mem [q ].hhfield .v.RH ;
	if ( r == 0 ) 
	goto lab30 ;
	if ( mem [r + 4 ].cint == 0 ) 
	{
	  mem [p ].hhfield .v.RH = r ;
	  freenode ( q , 7 ) ;
	  p = r ;
	} 
	else goto lab40 ;
      } 
    } 
    lab40: ;
  } 
  lab30: ;
  if ( symmetric ) 
  {
    s = 0 ;
    q = h ;
    while ( true ) {
	
      r = getnode ( 7 ) ;
      mem [r ].hhfield .v.RH = s ;
      s = r ;
      mem [s + 1 ].cint = mem [q + 1 ].cint ;
      mem [s + 2 ].cint = - (integer) mem [q + 2 ].cint ;
      if ( q == p ) 
      goto lab31 ;
      q = mem [q ].hhfield .v.RH ;
      if ( mem [q + 2 ].cint == 0 ) 
      goto lab31 ;
    } 
    lab31: if ( ( mem [p ].hhfield .v.RH != 0 ) ) 
    freenode ( mem [p ].hhfield .v.RH , 7 ) ;
    mem [p ].hhfield .v.RH = s ;
    beta = - (integer) mem [h + 2 ].cint ;
    while ( mem [p + 2 ].cint != beta ) p = mem [p ].hhfield .v.RH ;
    q = mem [p ].hhfield .v.RH ;
  } 
  if ( q != 0 ) 
  {
    if ( mem [h + 5 ].cint == 0 ) 
    {
      p = h ;
      h = mem [h ].hhfield .v.RH ;
      freenode ( p , 7 ) ;
      mem [q + 1 ].cint = - (integer) mem [h + 1 ].cint ;
    } 
    p = q ;
  } 
  else q = p ;
  r = mem [h ].hhfield .v.RH ;
  do {
      s = getnode ( 7 ) ;
    mem [p ].hhfield .v.RH = s ;
    p = s ;
    mem [p + 1 ].cint = - (integer) mem [r + 1 ].cint ;
    mem [p + 2 ].cint = - (integer) mem [r + 2 ].cint ;
    r = mem [r ].hhfield .v.RH ;
  } while ( ! ( r == q ) ) ;
  mem [p ].hhfield .v.RH = h ;
  Result = h ;
  return Result ;
} 
scaled 
zfinddirectiontime ( scaled x , scaled y , halfword h ) 
{
  /* 10 40 45 30 */ register scaled Result; scaled max  ;
  halfword p, q  ;
  scaled n  ;
  scaled tt  ;
  scaled x1, x2, x3, y1, y2, y3  ;
  angle theta, phi  ;
  fraction t  ;
  if ( abs ( x ) < abs ( y ) ) 
  {
    x = makefraction ( x , abs ( y ) ) ;
    if ( y > 0 ) 
    y = 268435456L ;
    else y = -268435456L ;
  } 
  else if ( x == 0 ) 
  {
    Result = 0 ;
    goto lab10 ;
  } 
  else {
      
    y = makefraction ( y , abs ( x ) ) ;
    if ( x > 0 ) 
    x = 268435456L ;
    else x = -268435456L ;
  } 
  n = 0 ;
  p = h ;
  while ( true ) {
      
    if ( mem [p ].hhfield .b1 == 0 ) 
    goto lab45 ;
    q = mem [p ].hhfield .v.RH ;
    tt = 0 ;
    x1 = mem [p + 5 ].cint - mem [p + 1 ].cint ;
    x2 = mem [q + 3 ].cint - mem [p + 5 ].cint ;
    x3 = mem [q + 1 ].cint - mem [q + 3 ].cint ;
    y1 = mem [p + 6 ].cint - mem [p + 2 ].cint ;
    y2 = mem [q + 4 ].cint - mem [p + 6 ].cint ;
    y3 = mem [q + 2 ].cint - mem [q + 4 ].cint ;
    max = abs ( x1 ) ;
    if ( abs ( x2 ) > max ) 
    max = abs ( x2 ) ;
    if ( abs ( x3 ) > max ) 
    max = abs ( x3 ) ;
    if ( abs ( y1 ) > max ) 
    max = abs ( y1 ) ;
    if ( abs ( y2 ) > max ) 
    max = abs ( y2 ) ;
    if ( abs ( y3 ) > max ) 
    max = abs ( y3 ) ;
    if ( max == 0 ) 
    goto lab40 ;
    while ( max < 134217728L ) {
	
      max = max + max ;
      x1 = x1 + x1 ;
      x2 = x2 + x2 ;
      x3 = x3 + x3 ;
      y1 = y1 + y1 ;
      y2 = y2 + y2 ;
      y3 = y3 + y3 ;
    } 
    t = x1 ;
    x1 = takefraction ( x1 , x ) + takefraction ( y1 , y ) ;
    y1 = takefraction ( y1 , x ) - takefraction ( t , y ) ;
    t = x2 ;
    x2 = takefraction ( x2 , x ) + takefraction ( y2 , y ) ;
    y2 = takefraction ( y2 , x ) - takefraction ( t , y ) ;
    t = x3 ;
    x3 = takefraction ( x3 , x ) + takefraction ( y3 , y ) ;
    y3 = takefraction ( y3 , x ) - takefraction ( t , y ) ;
    if ( y1 == 0 ) {
	
      if ( x1 >= 0 ) 
      goto lab40 ;
    } 
    if ( n > 0 ) 
    {
      theta = narg ( x1 , y1 ) ;
      if ( theta >= 0 ) {
	  
	if ( phi <= 0 ) {
	    
	  if ( phi >= theta - 188743680L ) 
	  goto lab40 ;
	} 
      } 
      if ( theta <= 0 ) {
	  
	if ( phi >= 0 ) {
	    
	  if ( phi <= theta + 188743680L ) 
	  goto lab40 ;
	} 
      } 
      if ( p == h ) 
      goto lab45 ;
    } 
    if ( ( x3 != 0 ) || ( y3 != 0 ) ) 
    phi = narg ( x3 , y3 ) ;
    if ( x1 < 0 ) {
	
      if ( x2 < 0 ) {
	  
	if ( x3 < 0 ) 
	goto lab30 ;
      } 
    } 
    if ( abvscd ( y1 , y3 , y2 , y2 ) == 0 ) 
    {
      if ( abvscd ( y1 , y2 , 0 , 0 ) < 0 ) 
      {
	t = makefraction ( y1 , y1 - y2 ) ;
	x1 = x1 - takefraction ( x1 - x2 , t ) ;
	x2 = x2 - takefraction ( x2 - x3 , t ) ;
	if ( x1 - takefraction ( x1 - x2 , t ) >= 0 ) 
	{
	  tt = ( t + 2048 ) / 4096 ;
	  goto lab40 ;
	} 
      } 
      else if ( y3 == 0 ) {
	  
	if ( y1 == 0 ) 
	{
	  t = crossingpoint ( - (integer) x1 , - (integer) x2 , - (integer) x3 
	  ) ;
	  if ( t <= 268435456L ) 
	  {
	    tt = ( t + 2048 ) / 4096 ;
	    goto lab40 ;
	  } 
	  if ( abvscd ( x1 , x3 , x2 , x2 ) <= 0 ) 
	  {
	    t = makefraction ( x1 , x1 - x2 ) ;
	    {
	      tt = ( t + 2048 ) / 4096 ;
	      goto lab40 ;
	    } 
	  } 
	} 
	else if ( x3 >= 0 ) 
	{
	  tt = 65536L ;
	  goto lab40 ;
	} 
      } 
      goto lab30 ;
    } 
    if ( y1 <= 0 ) {
	
      if ( y1 < 0 ) 
      {
	y1 = - (integer) y1 ;
	y2 = - (integer) y2 ;
	y3 = - (integer) y3 ;
      } 
      else if ( y2 > 0 ) 
      {
	y2 = - (integer) y2 ;
	y3 = - (integer) y3 ;
      } 
    } 
    t = crossingpoint ( y1 , y2 , y3 ) ;
    if ( t > 268435456L ) 
    goto lab30 ;
    y2 = y2 - takefraction ( y2 - y3 , t ) ;
    x1 = x1 - takefraction ( x1 - x2 , t ) ;
    x2 = x2 - takefraction ( x2 - x3 , t ) ;
    x1 = x1 - takefraction ( x1 - x2 , t ) ;
    if ( x1 >= 0 ) 
    {
      tt = ( t + 2048 ) / 4096 ;
      goto lab40 ;
    } 
    if ( y2 > 0 ) 
    y2 = 0 ;
    tt = t ;
    t = crossingpoint ( 0 , - (integer) y2 , - (integer) y3 ) ;
    if ( t > 268435456L ) 
    goto lab30 ;
    x1 = x1 - takefraction ( x1 - x2 , t ) ;
    x2 = x2 - takefraction ( x2 - x3 , t ) ;
    if ( x1 - takefraction ( x1 - x2 , t ) >= 0 ) 
    {
      t = tt - takefraction ( tt - 268435456L , t ) ;
      {
	tt = ( t + 2048 ) / 4096 ;
	goto lab40 ;
      } 
    } 
    lab30: ;
    p = q ;
    n = n + 65536L ;
  } 
  lab45: Result = -65536L ;
  goto lab10 ;
  lab40: Result = n + tt ;
  lab10: ;
  return Result ;
} 
void 
zcubicintersection ( halfword p , halfword pp ) 
{
  /* 22 45 10 */ halfword q, qq  ;
  timetogo = 5000 ;
  maxt = 2 ;
  q = mem [p ].hhfield .v.RH ;
  qq = mem [pp ].hhfield .v.RH ;
  bisectptr = 20 ;
  bisectstack [bisectptr - 5 ]= mem [p + 5 ].cint - mem [p + 1 ].cint ;
  bisectstack [bisectptr - 4 ]= mem [q + 3 ].cint - mem [p + 5 ].cint ;
  bisectstack [bisectptr - 3 ]= mem [q + 1 ].cint - mem [q + 3 ].cint ;
  if ( bisectstack [bisectptr - 5 ]< 0 ) {
      
    if ( bisectstack [bisectptr - 3 ]>= 0 ) 
    {
      if ( bisectstack [bisectptr - 4 ]< 0 ) 
      bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ]+ 
      bisectstack [bisectptr - 4 ];
      else bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ];
      bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ]+ 
      bisectstack [bisectptr - 4 ]+ bisectstack [bisectptr - 3 ];
      if ( bisectstack [bisectptr - 1 ]< 0 ) 
      bisectstack [bisectptr - 1 ]= 0 ;
    } 
    else {
	
      bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ]+ 
      bisectstack [bisectptr - 4 ]+ bisectstack [bisectptr - 3 ];
      if ( bisectstack [bisectptr - 2 ]> bisectstack [bisectptr - 5 ]) 
      bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ];
      bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ]+ 
      bisectstack [bisectptr - 4 ];
      if ( bisectstack [bisectptr - 1 ]< 0 ) 
      bisectstack [bisectptr - 1 ]= 0 ;
    } 
  } 
  else if ( bisectstack [bisectptr - 3 ]<= 0 ) 
  {
    if ( bisectstack [bisectptr - 4 ]> 0 ) 
    bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ]+ 
    bisectstack [bisectptr - 4 ];
    else bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ];
    bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ]+ 
    bisectstack [bisectptr - 4 ]+ bisectstack [bisectptr - 3 ];
    if ( bisectstack [bisectptr - 2 ]> 0 ) 
    bisectstack [bisectptr - 2 ]= 0 ;
  } 
  else {
      
    bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ]+ 
    bisectstack [bisectptr - 4 ]+ bisectstack [bisectptr - 3 ];
    if ( bisectstack [bisectptr - 1 ]< bisectstack [bisectptr - 5 ]) 
    bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ];
    bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ]+ 
    bisectstack [bisectptr - 4 ];
    if ( bisectstack [bisectptr - 2 ]> 0 ) 
    bisectstack [bisectptr - 2 ]= 0 ;
  } 
  bisectstack [bisectptr - 10 ]= mem [p + 6 ].cint - mem [p + 2 ].cint ;
  bisectstack [bisectptr - 9 ]= mem [q + 4 ].cint - mem [p + 6 ].cint ;
  bisectstack [bisectptr - 8 ]= mem [q + 2 ].cint - mem [q + 4 ].cint ;
  if ( bisectstack [bisectptr - 10 ]< 0 ) {
      
    if ( bisectstack [bisectptr - 8 ]>= 0 ) 
    {
      if ( bisectstack [bisectptr - 9 ]< 0 ) 
      bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ]+ 
      bisectstack [bisectptr - 9 ];
      else bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ];
      bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ]+ 
      bisectstack [bisectptr - 9 ]+ bisectstack [bisectptr - 8 ];
      if ( bisectstack [bisectptr - 6 ]< 0 ) 
      bisectstack [bisectptr - 6 ]= 0 ;
    } 
    else {
	
      bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ]+ 
      bisectstack [bisectptr - 9 ]+ bisectstack [bisectptr - 8 ];
      if ( bisectstack [bisectptr - 7 ]> bisectstack [bisectptr - 10 ]) 
      bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ];
      bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ]+ 
      bisectstack [bisectptr - 9 ];
      if ( bisectstack [bisectptr - 6 ]< 0 ) 
      bisectstack [bisectptr - 6 ]= 0 ;
    } 
  } 
  else if ( bisectstack [bisectptr - 8 ]<= 0 ) 
  {
    if ( bisectstack [bisectptr - 9 ]> 0 ) 
    bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ]+ 
    bisectstack [bisectptr - 9 ];
    else bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ];
    bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ]+ 
    bisectstack [bisectptr - 9 ]+ bisectstack [bisectptr - 8 ];
    if ( bisectstack [bisectptr - 7 ]> 0 ) 
    bisectstack [bisectptr - 7 ]= 0 ;
  } 
  else {
      
    bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ]+ 
    bisectstack [bisectptr - 9 ]+ bisectstack [bisectptr - 8 ];
    if ( bisectstack [bisectptr - 6 ]< bisectstack [bisectptr - 10 ]) 
    bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ];
    bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ]+ 
    bisectstack [bisectptr - 9 ];
    if ( bisectstack [bisectptr - 7 ]> 0 ) 
    bisectstack [bisectptr - 7 ]= 0 ;
  } 
  bisectstack [bisectptr - 15 ]= mem [pp + 5 ].cint - mem [pp + 1 ].cint 
  ;
  bisectstack [bisectptr - 14 ]= mem [qq + 3 ].cint - mem [pp + 5 ].cint 
  ;
  bisectstack [bisectptr - 13 ]= mem [qq + 1 ].cint - mem [qq + 3 ].cint 
  ;
  if ( bisectstack [bisectptr - 15 ]< 0 ) {
      
    if ( bisectstack [bisectptr - 13 ]>= 0 ) 
    {
      if ( bisectstack [bisectptr - 14 ]< 0 ) 
      bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 ]+ 
      bisectstack [bisectptr - 14 ];
      else bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 ];
      bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 ]+ 
      bisectstack [bisectptr - 14 ]+ bisectstack [bisectptr - 13 ];
      if ( bisectstack [bisectptr - 11 ]< 0 ) 
      bisectstack [bisectptr - 11 ]= 0 ;
    } 
    else {
	
      bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 ]+ 
      bisectstack [bisectptr - 14 ]+ bisectstack [bisectptr - 13 ];
      if ( bisectstack [bisectptr - 12 ]> bisectstack [bisectptr - 15 ]) 
      bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 ];
      bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 ]+ 
      bisectstack [bisectptr - 14 ];
      if ( bisectstack [bisectptr - 11 ]< 0 ) 
      bisectstack [bisectptr - 11 ]= 0 ;
    } 
  } 
  else if ( bisectstack [bisectptr - 13 ]<= 0 ) 
  {
    if ( bisectstack [bisectptr - 14 ]> 0 ) 
    bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 ]+ 
    bisectstack [bisectptr - 14 ];
    else bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 ];
    bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 ]+ 
    bisectstack [bisectptr - 14 ]+ bisectstack [bisectptr - 13 ];
    if ( bisectstack [bisectptr - 12 ]> 0 ) 
    bisectstack [bisectptr - 12 ]= 0 ;
  } 
  else {
      
    bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 ]+ 
    bisectstack [bisectptr - 14 ]+ bisectstack [bisectptr - 13 ];
    if ( bisectstack [bisectptr - 11 ]< bisectstack [bisectptr - 15 ]) 
    bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 ];
    bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 ]+ 
    bisectstack [bisectptr - 14 ];
    if ( bisectstack [bisectptr - 12 ]> 0 ) 
    bisectstack [bisectptr - 12 ]= 0 ;
  } 
  bisectstack [bisectptr - 20 ]= mem [pp + 6 ].cint - mem [pp + 2 ].cint 
  ;
  bisectstack [bisectptr - 19 ]= mem [qq + 4 ].cint - mem [pp + 6 ].cint 
  ;
  bisectstack [bisectptr - 18 ]= mem [qq + 2 ].cint - mem [qq + 4 ].cint 
  ;
  if ( bisectstack [bisectptr - 20 ]< 0 ) {
      
    if ( bisectstack [bisectptr - 18 ]>= 0 ) 
    {
      if ( bisectstack [bisectptr - 19 ]< 0 ) 
      bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 ]+ 
      bisectstack [bisectptr - 19 ];
      else bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 ];
      bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 ]+ 
      bisectstack [bisectptr - 19 ]+ bisectstack [bisectptr - 18 ];
      if ( bisectstack [bisectptr - 16 ]< 0 ) 
      bisectstack [bisectptr - 16 ]= 0 ;
    } 
    else {
	
      bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 ]+ 
      bisectstack [bisectptr - 19 ]+ bisectstack [bisectptr - 18 ];
      if ( bisectstack [bisectptr - 17 ]> bisectstack [bisectptr - 20 ]) 
      bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 ];
      bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 ]+ 
      bisectstack [bisectptr - 19 ];
      if ( bisectstack [bisectptr - 16 ]< 0 ) 
      bisectstack [bisectptr - 16 ]= 0 ;
    } 
  } 
  else if ( bisectstack [bisectptr - 18 ]<= 0 ) 
  {
    if ( bisectstack [bisectptr - 19 ]> 0 ) 
    bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 ]+ 
    bisectstack [bisectptr - 19 ];
    else bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 ];
    bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 ]+ 
    bisectstack [bisectptr - 19 ]+ bisectstack [bisectptr - 18 ];
    if ( bisectstack [bisectptr - 17 ]> 0 ) 
    bisectstack [bisectptr - 17 ]= 0 ;
  } 
  else {
      
    bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 ]+ 
    bisectstack [bisectptr - 19 ]+ bisectstack [bisectptr - 18 ];
    if ( bisectstack [bisectptr - 16 ]< bisectstack [bisectptr - 20 ]) 
    bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 ];
    bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 ]+ 
    bisectstack [bisectptr - 19 ];
    if ( bisectstack [bisectptr - 17 ]> 0 ) 
    bisectstack [bisectptr - 17 ]= 0 ;
  } 
  delx = mem [p + 1 ].cint - mem [pp + 1 ].cint ;
  dely = mem [p + 2 ].cint - mem [pp + 2 ].cint ;
  tol = 0 ;
  uv = bisectptr ;
  xy = bisectptr ;
  threel = 0 ;
  curt = 1 ;
  curtt = 1 ;
  while ( true ) {
      
    lab22: if ( delx - tol <= bisectstack [xy - 11 ]- bisectstack [uv - 2 ]
    ) {
	
      if ( delx + tol >= bisectstack [xy - 12 ]- bisectstack [uv - 1 ]) {
	  
	if ( dely - tol <= bisectstack [xy - 16 ]- bisectstack [uv - 7 ]) 
	{
	  if ( dely + tol >= bisectstack [xy - 17 ]- bisectstack [uv - 6 ]
	  ) 
	  {
	    if ( curt >= maxt ) 
	    {
	      if ( maxt == 131072L ) 
	      {
		curt = halfp ( curt + 1 ) ;
		curtt = halfp ( curtt + 1 ) ;
		goto lab10 ;
	      } 
	      maxt = maxt + maxt ;
	      apprt = curt ;
	      apprtt = curtt ;
	    } 
	    bisectstack [bisectptr ]= delx ;
	    bisectstack [bisectptr + 1 ]= dely ;
	    bisectstack [bisectptr + 2 ]= tol ;
	    bisectstack [bisectptr + 3 ]= uv ;
	    bisectstack [bisectptr + 4 ]= xy ;
	    bisectptr = bisectptr + 45 ;
	    curt = curt + curt ;
	    curtt = curtt + curtt ;
	    bisectstack [bisectptr - 25 ]= bisectstack [uv - 5 ];
	    bisectstack [bisectptr - 3 ]= bisectstack [uv - 3 ];
	    bisectstack [bisectptr - 24 ]= half ( bisectstack [bisectptr - 
	    25 ]+ bisectstack [uv - 4 ]) ;
	    bisectstack [bisectptr - 4 ]= half ( bisectstack [bisectptr - 3 
	    ]+ bisectstack [uv - 4 ]) ;
	    bisectstack [bisectptr - 23 ]= half ( bisectstack [bisectptr - 
	    24 ]+ bisectstack [bisectptr - 4 ]) ;
	    bisectstack [bisectptr - 5 ]= bisectstack [bisectptr - 23 ];
	    if ( bisectstack [bisectptr - 25 ]< 0 ) {
		
	      if ( bisectstack [bisectptr - 23 ]>= 0 ) 
	      {
		if ( bisectstack [bisectptr - 24 ]< 0 ) 
		bisectstack [bisectptr - 22 ]= bisectstack [bisectptr - 25 
		]+ bisectstack [bisectptr - 24 ];
		else bisectstack [bisectptr - 22 ]= bisectstack [bisectptr 
		- 25 ];
		bisectstack [bisectptr - 21 ]= bisectstack [bisectptr - 25 
		]+ bisectstack [bisectptr - 24 ]+ bisectstack [bisectptr - 
		23 ];
		if ( bisectstack [bisectptr - 21 ]< 0 ) 
		bisectstack [bisectptr - 21 ]= 0 ;
	      } 
	      else {
		  
		bisectstack [bisectptr - 22 ]= bisectstack [bisectptr - 25 
		]+ bisectstack [bisectptr - 24 ]+ bisectstack [bisectptr - 
		23 ];
		if ( bisectstack [bisectptr - 22 ]> bisectstack [bisectptr 
		- 25 ]) 
		bisectstack [bisectptr - 22 ]= bisectstack [bisectptr - 25 
		];
		bisectstack [bisectptr - 21 ]= bisectstack [bisectptr - 25 
		]+ bisectstack [bisectptr - 24 ];
		if ( bisectstack [bisectptr - 21 ]< 0 ) 
		bisectstack [bisectptr - 21 ]= 0 ;
	      } 
	    } 
	    else if ( bisectstack [bisectptr - 23 ]<= 0 ) 
	    {
	      if ( bisectstack [bisectptr - 24 ]> 0 ) 
	      bisectstack [bisectptr - 21 ]= bisectstack [bisectptr - 25 ]
	      + bisectstack [bisectptr - 24 ];
	      else bisectstack [bisectptr - 21 ]= bisectstack [bisectptr - 
	      25 ];
	      bisectstack [bisectptr - 22 ]= bisectstack [bisectptr - 25 ]
	      + bisectstack [bisectptr - 24 ]+ bisectstack [bisectptr - 23 
	      ];
	      if ( bisectstack [bisectptr - 22 ]> 0 ) 
	      bisectstack [bisectptr - 22 ]= 0 ;
	    } 
	    else {
		
	      bisectstack [bisectptr - 21 ]= bisectstack [bisectptr - 25 ]
	      + bisectstack [bisectptr - 24 ]+ bisectstack [bisectptr - 23 
	      ];
	      if ( bisectstack [bisectptr - 21 ]< bisectstack [bisectptr - 
	      25 ]) 
	      bisectstack [bisectptr - 21 ]= bisectstack [bisectptr - 25 ]
	      ;
	      bisectstack [bisectptr - 22 ]= bisectstack [bisectptr - 25 ]
	      + bisectstack [bisectptr - 24 ];
	      if ( bisectstack [bisectptr - 22 ]> 0 ) 
	      bisectstack [bisectptr - 22 ]= 0 ;
	    } 
	    if ( bisectstack [bisectptr - 5 ]< 0 ) {
		
	      if ( bisectstack [bisectptr - 3 ]>= 0 ) 
	      {
		if ( bisectstack [bisectptr - 4 ]< 0 ) 
		bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ]
		+ bisectstack [bisectptr - 4 ];
		else bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 
		5 ];
		bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ]
		+ bisectstack [bisectptr - 4 ]+ bisectstack [bisectptr - 3 
		];
		if ( bisectstack [bisectptr - 1 ]< 0 ) 
		bisectstack [bisectptr - 1 ]= 0 ;
	      } 
	      else {
		  
		bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ]
		+ bisectstack [bisectptr - 4 ]+ bisectstack [bisectptr - 3 
		];
		if ( bisectstack [bisectptr - 2 ]> bisectstack [bisectptr - 
		5 ]) 
		bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ]
		;
		bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ]
		+ bisectstack [bisectptr - 4 ];
		if ( bisectstack [bisectptr - 1 ]< 0 ) 
		bisectstack [bisectptr - 1 ]= 0 ;
	      } 
	    } 
	    else if ( bisectstack [bisectptr - 3 ]<= 0 ) 
	    {
	      if ( bisectstack [bisectptr - 4 ]> 0 ) 
	      bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ]+ 
	      bisectstack [bisectptr - 4 ];
	      else bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 
	      ];
	      bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ]+ 
	      bisectstack [bisectptr - 4 ]+ bisectstack [bisectptr - 3 ];
	      if ( bisectstack [bisectptr - 2 ]> 0 ) 
	      bisectstack [bisectptr - 2 ]= 0 ;
	    } 
	    else {
		
	      bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ]+ 
	      bisectstack [bisectptr - 4 ]+ bisectstack [bisectptr - 3 ];
	      if ( bisectstack [bisectptr - 1 ]< bisectstack [bisectptr - 5 
	      ]) 
	      bisectstack [bisectptr - 1 ]= bisectstack [bisectptr - 5 ];
	      bisectstack [bisectptr - 2 ]= bisectstack [bisectptr - 5 ]+ 
	      bisectstack [bisectptr - 4 ];
	      if ( bisectstack [bisectptr - 2 ]> 0 ) 
	      bisectstack [bisectptr - 2 ]= 0 ;
	    } 
	    bisectstack [bisectptr - 30 ]= bisectstack [uv - 10 ];
	    bisectstack [bisectptr - 8 ]= bisectstack [uv - 8 ];
	    bisectstack [bisectptr - 29 ]= half ( bisectstack [bisectptr - 
	    30 ]+ bisectstack [uv - 9 ]) ;
	    bisectstack [bisectptr - 9 ]= half ( bisectstack [bisectptr - 8 
	    ]+ bisectstack [uv - 9 ]) ;
	    bisectstack [bisectptr - 28 ]= half ( bisectstack [bisectptr - 
	    29 ]+ bisectstack [bisectptr - 9 ]) ;
	    bisectstack [bisectptr - 10 ]= bisectstack [bisectptr - 28 ];
	    if ( bisectstack [bisectptr - 30 ]< 0 ) {
		
	      if ( bisectstack [bisectptr - 28 ]>= 0 ) 
	      {
		if ( bisectstack [bisectptr - 29 ]< 0 ) 
		bisectstack [bisectptr - 27 ]= bisectstack [bisectptr - 30 
		]+ bisectstack [bisectptr - 29 ];
		else bisectstack [bisectptr - 27 ]= bisectstack [bisectptr 
		- 30 ];
		bisectstack [bisectptr - 26 ]= bisectstack [bisectptr - 30 
		]+ bisectstack [bisectptr - 29 ]+ bisectstack [bisectptr - 
		28 ];
		if ( bisectstack [bisectptr - 26 ]< 0 ) 
		bisectstack [bisectptr - 26 ]= 0 ;
	      } 
	      else {
		  
		bisectstack [bisectptr - 27 ]= bisectstack [bisectptr - 30 
		]+ bisectstack [bisectptr - 29 ]+ bisectstack [bisectptr - 
		28 ];
		if ( bisectstack [bisectptr - 27 ]> bisectstack [bisectptr 
		- 30 ]) 
		bisectstack [bisectptr - 27 ]= bisectstack [bisectptr - 30 
		];
		bisectstack [bisectptr - 26 ]= bisectstack [bisectptr - 30 
		]+ bisectstack [bisectptr - 29 ];
		if ( bisectstack [bisectptr - 26 ]< 0 ) 
		bisectstack [bisectptr - 26 ]= 0 ;
	      } 
	    } 
	    else if ( bisectstack [bisectptr - 28 ]<= 0 ) 
	    {
	      if ( bisectstack [bisectptr - 29 ]> 0 ) 
	      bisectstack [bisectptr - 26 ]= bisectstack [bisectptr - 30 ]
	      + bisectstack [bisectptr - 29 ];
	      else bisectstack [bisectptr - 26 ]= bisectstack [bisectptr - 
	      30 ];
	      bisectstack [bisectptr - 27 ]= bisectstack [bisectptr - 30 ]
	      + bisectstack [bisectptr - 29 ]+ bisectstack [bisectptr - 28 
	      ];
	      if ( bisectstack [bisectptr - 27 ]> 0 ) 
	      bisectstack [bisectptr - 27 ]= 0 ;
	    } 
	    else {
		
	      bisectstack [bisectptr - 26 ]= bisectstack [bisectptr - 30 ]
	      + bisectstack [bisectptr - 29 ]+ bisectstack [bisectptr - 28 
	      ];
	      if ( bisectstack [bisectptr - 26 ]< bisectstack [bisectptr - 
	      30 ]) 
	      bisectstack [bisectptr - 26 ]= bisectstack [bisectptr - 30 ]
	      ;
	      bisectstack [bisectptr - 27 ]= bisectstack [bisectptr - 30 ]
	      + bisectstack [bisectptr - 29 ];
	      if ( bisectstack [bisectptr - 27 ]> 0 ) 
	      bisectstack [bisectptr - 27 ]= 0 ;
	    } 
	    if ( bisectstack [bisectptr - 10 ]< 0 ) {
		
	      if ( bisectstack [bisectptr - 8 ]>= 0 ) 
	      {
		if ( bisectstack [bisectptr - 9 ]< 0 ) 
		bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ]
		+ bisectstack [bisectptr - 9 ];
		else bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 
		10 ];
		bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ]
		+ bisectstack [bisectptr - 9 ]+ bisectstack [bisectptr - 8 
		];
		if ( bisectstack [bisectptr - 6 ]< 0 ) 
		bisectstack [bisectptr - 6 ]= 0 ;
	      } 
	      else {
		  
		bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ]
		+ bisectstack [bisectptr - 9 ]+ bisectstack [bisectptr - 8 
		];
		if ( bisectstack [bisectptr - 7 ]> bisectstack [bisectptr - 
		10 ]) 
		bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ]
		;
		bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ]
		+ bisectstack [bisectptr - 9 ];
		if ( bisectstack [bisectptr - 6 ]< 0 ) 
		bisectstack [bisectptr - 6 ]= 0 ;
	      } 
	    } 
	    else if ( bisectstack [bisectptr - 8 ]<= 0 ) 
	    {
	      if ( bisectstack [bisectptr - 9 ]> 0 ) 
	      bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ]+ 
	      bisectstack [bisectptr - 9 ];
	      else bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 
	      10 ];
	      bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ]+ 
	      bisectstack [bisectptr - 9 ]+ bisectstack [bisectptr - 8 ];
	      if ( bisectstack [bisectptr - 7 ]> 0 ) 
	      bisectstack [bisectptr - 7 ]= 0 ;
	    } 
	    else {
		
	      bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ]+ 
	      bisectstack [bisectptr - 9 ]+ bisectstack [bisectptr - 8 ];
	      if ( bisectstack [bisectptr - 6 ]< bisectstack [bisectptr - 
	      10 ]) 
	      bisectstack [bisectptr - 6 ]= bisectstack [bisectptr - 10 ];
	      bisectstack [bisectptr - 7 ]= bisectstack [bisectptr - 10 ]+ 
	      bisectstack [bisectptr - 9 ];
	      if ( bisectstack [bisectptr - 7 ]> 0 ) 
	      bisectstack [bisectptr - 7 ]= 0 ;
	    } 
	    bisectstack [bisectptr - 35 ]= bisectstack [xy - 15 ];
	    bisectstack [bisectptr - 13 ]= bisectstack [xy - 13 ];
	    bisectstack [bisectptr - 34 ]= half ( bisectstack [bisectptr - 
	    35 ]+ bisectstack [xy - 14 ]) ;
	    bisectstack [bisectptr - 14 ]= half ( bisectstack [bisectptr - 
	    13 ]+ bisectstack [xy - 14 ]) ;
	    bisectstack [bisectptr - 33 ]= half ( bisectstack [bisectptr - 
	    34 ]+ bisectstack [bisectptr - 14 ]) ;
	    bisectstack [bisectptr - 15 ]= bisectstack [bisectptr - 33 ];
	    if ( bisectstack [bisectptr - 35 ]< 0 ) {
		
	      if ( bisectstack [bisectptr - 33 ]>= 0 ) 
	      {
		if ( bisectstack [bisectptr - 34 ]< 0 ) 
		bisectstack [bisectptr - 32 ]= bisectstack [bisectptr - 35 
		]+ bisectstack [bisectptr - 34 ];
		else bisectstack [bisectptr - 32 ]= bisectstack [bisectptr 
		- 35 ];
		bisectstack [bisectptr - 31 ]= bisectstack [bisectptr - 35 
		]+ bisectstack [bisectptr - 34 ]+ bisectstack [bisectptr - 
		33 ];
		if ( bisectstack [bisectptr - 31 ]< 0 ) 
		bisectstack [bisectptr - 31 ]= 0 ;
	      } 
	      else {
		  
		bisectstack [bisectptr - 32 ]= bisectstack [bisectptr - 35 
		]+ bisectstack [bisectptr - 34 ]+ bisectstack [bisectptr - 
		33 ];
		if ( bisectstack [bisectptr - 32 ]> bisectstack [bisectptr 
		- 35 ]) 
		bisectstack [bisectptr - 32 ]= bisectstack [bisectptr - 35 
		];
		bisectstack [bisectptr - 31 ]= bisectstack [bisectptr - 35 
		]+ bisectstack [bisectptr - 34 ];
		if ( bisectstack [bisectptr - 31 ]< 0 ) 
		bisectstack [bisectptr - 31 ]= 0 ;
	      } 
	    } 
	    else if ( bisectstack [bisectptr - 33 ]<= 0 ) 
	    {
	      if ( bisectstack [bisectptr - 34 ]> 0 ) 
	      bisectstack [bisectptr - 31 ]= bisectstack [bisectptr - 35 ]
	      + bisectstack [bisectptr - 34 ];
	      else bisectstack [bisectptr - 31 ]= bisectstack [bisectptr - 
	      35 ];
	      bisectstack [bisectptr - 32 ]= bisectstack [bisectptr - 35 ]
	      + bisectstack [bisectptr - 34 ]+ bisectstack [bisectptr - 33 
	      ];
	      if ( bisectstack [bisectptr - 32 ]> 0 ) 
	      bisectstack [bisectptr - 32 ]= 0 ;
	    } 
	    else {
		
	      bisectstack [bisectptr - 31 ]= bisectstack [bisectptr - 35 ]
	      + bisectstack [bisectptr - 34 ]+ bisectstack [bisectptr - 33 
	      ];
	      if ( bisectstack [bisectptr - 31 ]< bisectstack [bisectptr - 
	      35 ]) 
	      bisectstack [bisectptr - 31 ]= bisectstack [bisectptr - 35 ]
	      ;
	      bisectstack [bisectptr - 32 ]= bisectstack [bisectptr - 35 ]
	      + bisectstack [bisectptr - 34 ];
	      if ( bisectstack [bisectptr - 32 ]> 0 ) 
	      bisectstack [bisectptr - 32 ]= 0 ;
	    } 
	    if ( bisectstack [bisectptr - 15 ]< 0 ) {
		
	      if ( bisectstack [bisectptr - 13 ]>= 0 ) 
	      {
		if ( bisectstack [bisectptr - 14 ]< 0 ) 
		bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 
		]+ bisectstack [bisectptr - 14 ];
		else bisectstack [bisectptr - 12 ]= bisectstack [bisectptr 
		- 15 ];
		bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 
		]+ bisectstack [bisectptr - 14 ]+ bisectstack [bisectptr - 
		13 ];
		if ( bisectstack [bisectptr - 11 ]< 0 ) 
		bisectstack [bisectptr - 11 ]= 0 ;
	      } 
	      else {
		  
		bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 
		]+ bisectstack [bisectptr - 14 ]+ bisectstack [bisectptr - 
		13 ];
		if ( bisectstack [bisectptr - 12 ]> bisectstack [bisectptr 
		- 15 ]) 
		bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 
		];
		bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 
		]+ bisectstack [bisectptr - 14 ];
		if ( bisectstack [bisectptr - 11 ]< 0 ) 
		bisectstack [bisectptr - 11 ]= 0 ;
	      } 
	    } 
	    else if ( bisectstack [bisectptr - 13 ]<= 0 ) 
	    {
	      if ( bisectstack [bisectptr - 14 ]> 0 ) 
	      bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 ]
	      + bisectstack [bisectptr - 14 ];
	      else bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 
	      15 ];
	      bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 ]
	      + bisectstack [bisectptr - 14 ]+ bisectstack [bisectptr - 13 
	      ];
	      if ( bisectstack [bisectptr - 12 ]> 0 ) 
	      bisectstack [bisectptr - 12 ]= 0 ;
	    } 
	    else {
		
	      bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 ]
	      + bisectstack [bisectptr - 14 ]+ bisectstack [bisectptr - 13 
	      ];
	      if ( bisectstack [bisectptr - 11 ]< bisectstack [bisectptr - 
	      15 ]) 
	      bisectstack [bisectptr - 11 ]= bisectstack [bisectptr - 15 ]
	      ;
	      bisectstack [bisectptr - 12 ]= bisectstack [bisectptr - 15 ]
	      + bisectstack [bisectptr - 14 ];
	      if ( bisectstack [bisectptr - 12 ]> 0 ) 
	      bisectstack [bisectptr - 12 ]= 0 ;
	    } 
	    bisectstack [bisectptr - 40 ]= bisectstack [xy - 20 ];
	    bisectstack [bisectptr - 18 ]= bisectstack [xy - 18 ];
	    bisectstack [bisectptr - 39 ]= half ( bisectstack [bisectptr - 
	    40 ]+ bisectstack [xy - 19 ]) ;
	    bisectstack [bisectptr - 19 ]= half ( bisectstack [bisectptr - 
	    18 ]+ bisectstack [xy - 19 ]) ;
	    bisectstack [bisectptr - 38 ]= half ( bisectstack [bisectptr - 
	    39 ]+ bisectstack [bisectptr - 19 ]) ;
	    bisectstack [bisectptr - 20 ]= bisectstack [bisectptr - 38 ];
	    if ( bisectstack [bisectptr - 40 ]< 0 ) {
		
	      if ( bisectstack [bisectptr - 38 ]>= 0 ) 
	      {
		if ( bisectstack [bisectptr - 39 ]< 0 ) 
		bisectstack [bisectptr - 37 ]= bisectstack [bisectptr - 40 
		]+ bisectstack [bisectptr - 39 ];
		else bisectstack [bisectptr - 37 ]= bisectstack [bisectptr 
		- 40 ];
		bisectstack [bisectptr - 36 ]= bisectstack [bisectptr - 40 
		]+ bisectstack [bisectptr - 39 ]+ bisectstack [bisectptr - 
		38 ];
		if ( bisectstack [bisectptr - 36 ]< 0 ) 
		bisectstack [bisectptr - 36 ]= 0 ;
	      } 
	      else {
		  
		bisectstack [bisectptr - 37 ]= bisectstack [bisectptr - 40 
		]+ bisectstack [bisectptr - 39 ]+ bisectstack [bisectptr - 
		38 ];
		if ( bisectstack [bisectptr - 37 ]> bisectstack [bisectptr 
		- 40 ]) 
		bisectstack [bisectptr - 37 ]= bisectstack [bisectptr - 40 
		];
		bisectstack [bisectptr - 36 ]= bisectstack [bisectptr - 40 
		]+ bisectstack [bisectptr - 39 ];
		if ( bisectstack [bisectptr - 36 ]< 0 ) 
		bisectstack [bisectptr - 36 ]= 0 ;
	      } 
	    } 
	    else if ( bisectstack [bisectptr - 38 ]<= 0 ) 
	    {
	      if ( bisectstack [bisectptr - 39 ]> 0 ) 
	      bisectstack [bisectptr - 36 ]= bisectstack [bisectptr - 40 ]
	      + bisectstack [bisectptr - 39 ];
	      else bisectstack [bisectptr - 36 ]= bisectstack [bisectptr - 
	      40 ];
	      bisectstack [bisectptr - 37 ]= bisectstack [bisectptr - 40 ]
	      + bisectstack [bisectptr - 39 ]+ bisectstack [bisectptr - 38 
	      ];
	      if ( bisectstack [bisectptr - 37 ]> 0 ) 
	      bisectstack [bisectptr - 37 ]= 0 ;
	    } 
	    else {
		
	      bisectstack [bisectptr - 36 ]= bisectstack [bisectptr - 40 ]
	      + bisectstack [bisectptr - 39 ]+ bisectstack [bisectptr - 38 
	      ];
	      if ( bisectstack [bisectptr - 36 ]< bisectstack [bisectptr - 
	      40 ]) 
	      bisectstack [bisectptr - 36 ]= bisectstack [bisectptr - 40 ]
	      ;
	      bisectstack [bisectptr - 37 ]= bisectstack [bisectptr - 40 ]
	      + bisectstack [bisectptr - 39 ];
	      if ( bisectstack [bisectptr - 37 ]> 0 ) 
	      bisectstack [bisectptr - 37 ]= 0 ;
	    } 
	    if ( bisectstack [bisectptr - 20 ]< 0 ) {
		
	      if ( bisectstack [bisectptr - 18 ]>= 0 ) 
	      {
		if ( bisectstack [bisectptr - 19 ]< 0 ) 
		bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 
		]+ bisectstack [bisectptr - 19 ];
		else bisectstack [bisectptr - 17 ]= bisectstack [bisectptr 
		- 20 ];
		bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 
		]+ bisectstack [bisectptr - 19 ]+ bisectstack [bisectptr - 
		18 ];
		if ( bisectstack [bisectptr - 16 ]< 0 ) 
		bisectstack [bisectptr - 16 ]= 0 ;
	      } 
	      else {
		  
		bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 
		]+ bisectstack [bisectptr - 19 ]+ bisectstack [bisectptr - 
		18 ];
		if ( bisectstack [bisectptr - 17 ]> bisectstack [bisectptr 
		- 20 ]) 
		bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 
		];
		bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 
		]+ bisectstack [bisectptr - 19 ];
		if ( bisectstack [bisectptr - 16 ]< 0 ) 
		bisectstack [bisectptr - 16 ]= 0 ;
	      } 
	    } 
	    else if ( bisectstack [bisectptr - 18 ]<= 0 ) 
	    {
	      if ( bisectstack [bisectptr - 19 ]> 0 ) 
	      bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 ]
	      + bisectstack [bisectptr - 19 ];
	      else bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 
	      20 ];
	      bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 ]
	      + bisectstack [bisectptr - 19 ]+ bisectstack [bisectptr - 18 
	      ];
	      if ( bisectstack [bisectptr - 17 ]> 0 ) 
	      bisectstack [bisectptr - 17 ]= 0 ;
	    } 
	    else {
		
	      bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 ]
	      + bisectstack [bisectptr - 19 ]+ bisectstack [bisectptr - 18 
	      ];
	      if ( bisectstack [bisectptr - 16 ]< bisectstack [bisectptr - 
	      20 ]) 
	      bisectstack [bisectptr - 16 ]= bisectstack [bisectptr - 20 ]
	      ;
	      bisectstack [bisectptr - 17 ]= bisectstack [bisectptr - 20 ]
	      + bisectstack [bisectptr - 19 ];
	      if ( bisectstack [bisectptr - 17 ]> 0 ) 
	      bisectstack [bisectptr - 17 ]= 0 ;
	    } 
	    uv = bisectptr - 20 ;
	    xy = bisectptr - 20 ;
	    delx = delx + delx ;
	    dely = dely + dely ;
	    tol = tol - threel + tolstep ;
	    tol = tol + tol ;
	    threel = threel + tolstep ;
	    goto lab22 ;
	  } 
	} 
      } 
    } 
    if ( timetogo > 0 ) 
    decr ( timetogo ) ;
    else {
	
      while ( apprt < 65536L ) {
	  
	apprt = apprt + apprt ;
	apprtt = apprtt + apprtt ;
      } 
      curt = apprt ;
      curtt = apprtt ;
      goto lab10 ;
    } 
    lab45: if ( odd ( curtt ) ) {
	
      if ( odd ( curt ) ) 
      {
	curt = halfp ( curt ) ;
	curtt = halfp ( curtt ) ;
	if ( curt == 0 ) 
	goto lab10 ;
	bisectptr = bisectptr - 45 ;
	threel = threel - tolstep ;
	delx = bisectstack [bisectptr ];
	dely = bisectstack [bisectptr + 1 ];
	tol = bisectstack [bisectptr + 2 ];
	uv = bisectstack [bisectptr + 3 ];
	xy = bisectstack [bisectptr + 4 ];
	goto lab45 ;
      } 
      else {
	  
	incr ( curt ) ;
	delx = delx + bisectstack [uv - 5 ]+ bisectstack [uv - 4 ]+ 
	bisectstack [uv - 3 ];
	dely = dely + bisectstack [uv - 10 ]+ bisectstack [uv - 9 ]+ 
	bisectstack [uv - 8 ];
	uv = uv + 20 ;
	decr ( curtt ) ;
	xy = xy - 20 ;
	delx = delx + bisectstack [xy - 15 ]+ bisectstack [xy - 14 ]+ 
	bisectstack [xy - 13 ];
	dely = dely + bisectstack [xy - 20 ]+ bisectstack [xy - 19 ]+ 
	bisectstack [xy - 18 ];
      } 
    } 
    else {
	
      incr ( curtt ) ;
      tol = tol + threel ;
      delx = delx - bisectstack [xy - 15 ]- bisectstack [xy - 14 ]- 
      bisectstack [xy - 13 ];
      dely = dely - bisectstack [xy - 20 ]- bisectstack [xy - 19 ]- 
      bisectstack [xy - 18 ];
      xy = xy + 20 ;
    } 
  } 
  lab10: ;
} 
void 
zpathintersection ( halfword h , halfword hh ) 
{
  /* 10 */ halfword p, pp  ;
  integer n, nn  ;
  if ( mem [h ].hhfield .b1 == 0 ) 
  {
    mem [h + 5 ].cint = mem [h + 1 ].cint ;
    mem [h + 3 ].cint = mem [h + 1 ].cint ;
    mem [h + 6 ].cint = mem [h + 2 ].cint ;
    mem [h + 4 ].cint = mem [h + 2 ].cint ;
    mem [h ].hhfield .b1 = 1 ;
  } 
  if ( mem [hh ].hhfield .b1 == 0 ) 
  {
    mem [hh + 5 ].cint = mem [hh + 1 ].cint ;
    mem [hh + 3 ].cint = mem [hh + 1 ].cint ;
    mem [hh + 6 ].cint = mem [hh + 2 ].cint ;
    mem [hh + 4 ].cint = mem [hh + 2 ].cint ;
    mem [hh ].hhfield .b1 = 1 ;
  } 
  tolstep = 0 ;
  do {
      n = -65536L ;
    p = h ;
    do {
	if ( mem [p ].hhfield .b1 != 0 ) 
      {
	nn = -65536L ;
	pp = hh ;
	do {
	    if ( mem [pp ].hhfield .b1 != 0 ) 
	  {
	    cubicintersection ( p , pp ) ;
	    if ( curt > 0 ) 
	    {
	      curt = curt + n ;
	      curtt = curtt + nn ;
	      goto lab10 ;
	    } 
	  } 
	  nn = nn + 65536L ;
	  pp = mem [pp ].hhfield .v.RH ;
	} while ( ! ( pp == hh ) ) ;
      } 
      n = n + 65536L ;
      p = mem [p ].hhfield .v.RH ;
    } while ( ! ( p == h ) ) ;
    tolstep = tolstep + 3 ;
  } while ( ! ( tolstep > 3 ) ) ;
  curt = -65536L ;
  curtt = -65536L ;
  lab10: ;
} 
void 
zopenawindow ( windownumber k , scaled r0 , scaled c0 , scaled r1 , scaled c1 
, scaled x , scaled y ) 
{
  integer m, n  ;
  if ( r0 < 0 ) 
  r0 = 0 ;
  else r0 = roundunscaled ( r0 ) ;
  r1 = roundunscaled ( r1 ) ;
  if ( r1 > screendepth ) 
  r1 = screendepth ;
  if ( r1 < r0 ) {
      
    if ( r0 > screendepth ) 
    r0 = r1 ;
    else r1 = r0 ;
  } 
  if ( c0 < 0 ) 
  c0 = 0 ;
  else c0 = roundunscaled ( c0 ) ;
  c1 = roundunscaled ( c1 ) ;
  if ( c1 > screenwidth ) 
  c1 = screenwidth ;
  if ( c1 < c0 ) {
      
    if ( c0 > screenwidth ) 
    c0 = c1 ;
    else c1 = c0 ;
  } 
  windowopen [k ]= true ;
  incr ( windowtime [k ]) ;
  leftcol [k ]= c0 ;
  rightcol [k ]= c1 ;
  toprow [k ]= r0 ;
  botrow [k ]= r1 ;
  m = roundunscaled ( x ) ;
  n = roundunscaled ( y ) - 1 ;
  mwindow [k ]= c0 - m ;
  nwindow [k ]= r0 + n ;
  {
    if ( ! screenstarted ) 
    {
      screenOK = initscreen () ;
      screenstarted = true ;
    } 
  } 
  if ( screenOK ) 
  {
    blankrectangle ( c0 , c1 , r0 , r1 ) ;
    updatescreen () ;
  } 
} 
void 
zdispedges ( windownumber k ) 
{
  /* 30 40 */ halfword p, q  ;
  boolean alreadythere  ;
  integer r  ;
  screencol n  ;
  integer w, ww  ;
  pixelcolor b  ;
  integer m, mm  ;
  integer d  ;
  integer madjustment  ;
  integer rightedge  ;
  screencol mincol  ;
  if ( screenOK ) {
      
    if ( leftcol [k ]< rightcol [k ]) {
	
      if ( toprow [k ]< botrow [k ]) 
      {
	alreadythere = false ;
	if ( mem [curedges + 3 ].hhfield .v.RH == k ) {
	    
	  if ( mem [curedges + 4 ].cint == windowtime [k ]) 
	  alreadythere = true ;
	} 
	if ( ! alreadythere ) 
	blankrectangle ( leftcol [k ], rightcol [k ], toprow [k ], 
	botrow [k ]) ;
	madjustment = mwindow [k ]- mem [curedges + 3 ].hhfield .lhfield ;
	rightedge = 8 * ( rightcol [k ]- madjustment ) ;
	mincol = leftcol [k ];
	p = mem [curedges ].hhfield .v.RH ;
	r = nwindow [k ]- ( mem [curedges + 1 ].hhfield .lhfield - 4096 ) 
	;
	while ( ( p != curedges ) && ( r >= toprow [k ]) ) {
	    
	  if ( r < botrow [k ]) 
	  {
	    if ( mem [p + 1 ].hhfield .lhfield > 1 ) 
	    sortedges ( p ) ;
	    else if ( mem [p + 1 ].hhfield .lhfield == 1 ) {
		
	      if ( alreadythere ) 
	      goto lab30 ;
	    } 
	    mem [p + 1 ].hhfield .lhfield = 1 ;
	    n = 0 ;
	    ww = 0 ;
	    m = -1 ;
	    w = 0 ;
	    q = mem [p + 1 ].hhfield .v.RH ;
	    rowtransition [0 ]= mincol ;
	    while ( true ) {
		
	      if ( q == memtop ) 
	      d = rightedge ;
	      else d = mem [q ].hhfield .lhfield ;
	      mm = ( d / 8 ) + madjustment ;
	      if ( mm != m ) 
	      {
		if ( w <= 0 ) 
		{
		  if ( ww > 0 ) {
		      
		    if ( m > mincol ) 
		    {
		      if ( n == 0 ) {
			  
			if ( alreadythere ) 
			{
			  b = 0 ;
			  incr ( n ) ;
			} 
			else b = 1 ;
		      } 
		      else incr ( n ) ;
		      rowtransition [n ]= m ;
		    } 
		  } 
		} 
		else if ( ww <= 0 ) {
		    
		  if ( m > mincol ) 
		  {
		    if ( n == 0 ) 
		    b = 1 ;
		    incr ( n ) ;
		    rowtransition [n ]= m ;
		  } 
		} 
		m = mm ;
		w = ww ;
	      } 
	      if ( d >= rightedge ) 
	      goto lab40 ;
	      ww = ww + ( d % 8 ) - 4 ;
	      q = mem [q ].hhfield .v.RH ;
	    } 
	    lab40: if ( alreadythere || ( ww > 0 ) ) 
	    {
	      if ( n == 0 ) {
		  
		if ( ww > 0 ) 
		b = 1 ;
		else b = 0 ;
	      } 
	      incr ( n ) ;
	      rowtransition [n ]= rightcol [k ];
	    } 
	    else if ( n == 0 ) 
	    goto lab30 ;
	    paintrow ( r , b , rowtransition , n ) ;
	    lab30: ;
	  } 
	  p = mem [p ].hhfield .v.RH ;
	  decr ( r ) ;
	} 
	updatescreen () ;
	incr ( windowtime [k ]) ;
	mem [curedges + 3 ].hhfield .v.RH = k ;
	mem [curedges + 4 ].cint = windowtime [k ];
      } 
    } 
  } 
} 
fraction 
zmaxcoef ( halfword p ) 
{
  register fraction Result; fraction x  ;
  x = 0 ;
  while ( mem [p ].hhfield .lhfield != 0 ) {
      
    if ( abs ( mem [p + 1 ].cint ) > x ) 
    x = abs ( mem [p + 1 ].cint ) ;
    p = mem [p ].hhfield .v.RH ;
  } 
  Result = x ;
  return Result ;
} 
halfword 
zpplusq ( halfword p , halfword q , smallnumber t ) 
{
  /* 30 */ register halfword Result; halfword pp, qq  ;
  halfword r, s  ;
  integer threshold  ;
  integer v  ;
  if ( t == 17 ) 
  threshold = 2685 ;
  else threshold = 8 ;
  r = memtop - 1 ;
  pp = mem [p ].hhfield .lhfield ;
  qq = mem [q ].hhfield .lhfield ;
  while ( true ) if ( pp == qq ) {
      
    if ( pp == 0 ) 
    goto lab30 ;
    else {
	
      v = mem [p + 1 ].cint + mem [q + 1 ].cint ;
      mem [p + 1 ].cint = v ;
      s = p ;
      p = mem [p ].hhfield .v.RH ;
      pp = mem [p ].hhfield .lhfield ;
      if ( abs ( v ) < threshold ) 
      freenode ( s , 2 ) ;
      else {
	  
	if ( abs ( v ) >= 626349397L ) {
	    
	  if ( watchcoefs ) 
	  {
	    mem [qq ].hhfield .b0 = 0 ;
	    fixneeded = true ;
	  } 
	} 
	mem [r ].hhfield .v.RH = s ;
	r = s ;
      } 
      q = mem [q ].hhfield .v.RH ;
      qq = mem [q ].hhfield .lhfield ;
    } 
  } 
  else if ( mem [pp + 1 ].cint < mem [qq + 1 ].cint ) 
  {
    s = getnode ( 2 ) ;
    mem [s ].hhfield .lhfield = qq ;
    mem [s + 1 ].cint = mem [q + 1 ].cint ;
    q = mem [q ].hhfield .v.RH ;
    qq = mem [q ].hhfield .lhfield ;
    mem [r ].hhfield .v.RH = s ;
    r = s ;
  } 
  else {
      
    mem [r ].hhfield .v.RH = p ;
    r = p ;
    p = mem [p ].hhfield .v.RH ;
    pp = mem [p ].hhfield .lhfield ;
  } 
  lab30: mem [p + 1 ].cint = slowadd ( mem [p + 1 ].cint , mem [q + 1 ]
  .cint ) ;
  mem [r ].hhfield .v.RH = p ;
  depfinal = p ;
  Result = mem [memtop - 1 ].hhfield .v.RH ;
  return Result ;
} 
halfword 
zptimesv ( halfword p , integer v , smallnumber t0 , smallnumber t1 , boolean 
visscaled ) 
{
  register halfword Result; halfword r, s  ;
  integer w  ;
  integer threshold  ;
  boolean scalingdown  ;
  if ( t0 != t1 ) 
  scalingdown = true ;
  else scalingdown = ! visscaled ;
  if ( t1 == 17 ) 
  threshold = 1342 ;
  else threshold = 4 ;
  r = memtop - 1 ;
  while ( mem [p ].hhfield .lhfield != 0 ) {
      
    if ( scalingdown ) 
    w = takefraction ( v , mem [p + 1 ].cint ) ;
    else w = takescaled ( v , mem [p + 1 ].cint ) ;
    if ( abs ( w ) <= threshold ) 
    {
      s = mem [p ].hhfield .v.RH ;
      freenode ( p , 2 ) ;
      p = s ;
    } 
    else {
	
      if ( abs ( w ) >= 626349397L ) 
      {
	fixneeded = true ;
	mem [mem [p ].hhfield .lhfield ].hhfield .b0 = 0 ;
      } 
      mem [r ].hhfield .v.RH = p ;
      r = p ;
      mem [p + 1 ].cint = w ;
      p = mem [p ].hhfield .v.RH ;
    } 
  } 
  mem [r ].hhfield .v.RH = p ;
  if ( visscaled ) 
  mem [p + 1 ].cint = takescaled ( mem [p + 1 ].cint , v ) ;
  else mem [p + 1 ].cint = takefraction ( mem [p + 1 ].cint , v ) ;
  Result = mem [memtop - 1 ].hhfield .v.RH ;
  return Result ;
} 
halfword 
zpwithxbecomingq ( halfword p , halfword x , halfword q , smallnumber t ) 
{
  register halfword Result; halfword r, s  ;
  integer v  ;
  integer sx  ;
  s = p ;
  r = memtop - 1 ;
  sx = mem [x + 1 ].cint ;
  while ( mem [mem [s ].hhfield .lhfield + 1 ].cint > sx ) {
      
    r = s ;
    s = mem [s ].hhfield .v.RH ;
  } 
  if ( mem [s ].hhfield .lhfield != x ) 
  Result = p ;
  else {
      
    mem [memtop - 1 ].hhfield .v.RH = p ;
    mem [r ].hhfield .v.RH = mem [s ].hhfield .v.RH ;
    v = mem [s + 1 ].cint ;
    freenode ( s , 2 ) ;
    Result = pplusfq ( mem [memtop - 1 ].hhfield .v.RH , v , q , t , 17 ) ;
  } 
  return Result ;
} 
void 
znewdep ( halfword q , halfword p ) 
{
  halfword r  ;
  mem [q + 1 ].hhfield .v.RH = p ;
  mem [q + 1 ].hhfield .lhfield = 13 ;
  r = mem [13 ].hhfield .v.RH ;
  mem [depfinal ].hhfield .v.RH = r ;
  mem [r + 1 ].hhfield .lhfield = depfinal ;
  mem [13 ].hhfield .v.RH = q ;
} 
halfword 
zconstdependency ( scaled v ) 
{
  register halfword Result; depfinal = getnode ( 2 ) ;
  mem [depfinal + 1 ].cint = v ;
  mem [depfinal ].hhfield .lhfield = 0 ;
  Result = depfinal ;
  return Result ;
} 
halfword 
zsingledependency ( halfword p ) 
{
  register halfword Result; halfword q  ;
  integer m  ;
  m = mem [p + 1 ].cint % 64 ;
  if ( m > 28 ) 
  Result = constdependency ( 0 ) ;
  else {
      
    q = getnode ( 2 ) ;
    mem [q + 1 ].cint = twotothe [28 - m ];
    mem [q ].hhfield .lhfield = p ;
    mem [q ].hhfield .v.RH = constdependency ( 0 ) ;
    Result = q ;
  } 
  return Result ;
} 
halfword 
zcopydeplist ( halfword p ) 
{
  /* 30 */ register halfword Result; halfword q  ;
  q = getnode ( 2 ) ;
  depfinal = q ;
  while ( true ) {
      
    mem [depfinal ].hhfield .lhfield = mem [p ].hhfield .lhfield ;
    mem [depfinal + 1 ].cint = mem [p + 1 ].cint ;
    if ( mem [depfinal ].hhfield .lhfield == 0 ) 
    goto lab30 ;
    mem [depfinal ].hhfield .v.RH = getnode ( 2 ) ;
    depfinal = mem [depfinal ].hhfield .v.RH ;
    p = mem [p ].hhfield .v.RH ;
  } 
  lab30: Result = q ;
  return Result ;
} 
void 
zlineareq ( halfword p , smallnumber t ) 
{
  halfword q, r, s  ;
  halfword x  ;
  integer n  ;
  integer v  ;
  halfword prevr  ;
  halfword finalnode  ;
  integer w  ;
  q = p ;
  r = mem [p ].hhfield .v.RH ;
  v = mem [q + 1 ].cint ;
  while ( mem [r ].hhfield .lhfield != 0 ) {
      
    if ( abs ( mem [r + 1 ].cint ) > abs ( v ) ) 
    {
      q = r ;
      v = mem [r + 1 ].cint ;
    } 
    r = mem [r ].hhfield .v.RH ;
  } 
  x = mem [q ].hhfield .lhfield ;
  n = mem [x + 1 ].cint % 64 ;
  s = memtop - 1 ;
  mem [s ].hhfield .v.RH = p ;
  r = p ;
  do {
      if ( r == q ) 
    {
      mem [s ].hhfield .v.RH = mem [r ].hhfield .v.RH ;
      freenode ( r , 2 ) ;
    } 
    else {
	
      w = makefraction ( mem [r + 1 ].cint , v ) ;
      if ( abs ( w ) <= 1342 ) 
      {
	mem [s ].hhfield .v.RH = mem [r ].hhfield .v.RH ;
	freenode ( r , 2 ) ;
      } 
      else {
	  
	mem [r + 1 ].cint = - (integer) w ;
	s = r ;
      } 
    } 
    r = mem [s ].hhfield .v.RH ;
  } while ( ! ( mem [r ].hhfield .lhfield == 0 ) ) ;
  if ( t == 18 ) 
  mem [r + 1 ].cint = - (integer) makescaled ( mem [r + 1 ].cint , v ) ;
  else if ( v != -268435456L ) 
  mem [r + 1 ].cint = - (integer) makefraction ( mem [r + 1 ].cint , v ) ;
  finalnode = r ;
  p = mem [memtop - 1 ].hhfield .v.RH ;
  if ( internal [2 ]> 0 ) {
      
    if ( interesting ( x ) ) 
    {
      begindiagnostic () ;
      printnl ( 597 ) ;
      printvariablename ( x ) ;
      w = n ;
      while ( w > 0 ) {
	  
	print ( 590 ) ;
	w = w - 2 ;
      } 
      printchar ( 61 ) ;
      printdependency ( p , 17 ) ;
      enddiagnostic ( false ) ;
    } 
  } 
  prevr = 13 ;
  r = mem [13 ].hhfield .v.RH ;
  while ( r != 13 ) {
      
    s = mem [r + 1 ].hhfield .v.RH ;
    q = pwithxbecomingq ( s , x , p , mem [r ].hhfield .b0 ) ;
    if ( mem [q ].hhfield .lhfield == 0 ) 
    makeknown ( r , q ) ;
    else {
	
      mem [r + 1 ].hhfield .v.RH = q ;
      do {
	  q = mem [q ].hhfield .v.RH ;
      } while ( ! ( mem [q ].hhfield .lhfield == 0 ) ) ;
      prevr = q ;
    } 
    r = mem [prevr ].hhfield .v.RH ;
  } 
  if ( n > 0 ) 
  {
    s = memtop - 1 ;
    mem [memtop - 1 ].hhfield .v.RH = p ;
    r = p ;
    do {
	if ( n > 30 ) 
      w = 0 ;
      else w = mem [r + 1 ].cint / twotothe [n ];
      if ( ( abs ( w ) <= 1342 ) && ( mem [r ].hhfield .lhfield != 0 ) ) 
      {
	mem [s ].hhfield .v.RH = mem [r ].hhfield .v.RH ;
	freenode ( r , 2 ) ;
      } 
      else {
	  
	mem [r + 1 ].cint = w ;
	s = r ;
      } 
      r = mem [s ].hhfield .v.RH ;
    } while ( ! ( mem [s ].hhfield .lhfield == 0 ) ) ;
    p = mem [memtop - 1 ].hhfield .v.RH ;
  } 
  if ( mem [p ].hhfield .lhfield == 0 ) 
  {
    mem [x ].hhfield .b0 = 16 ;
    mem [x + 1 ].cint = mem [p + 1 ].cint ;
    if ( abs ( mem [x + 1 ].cint ) >= 268435456L ) 
    valtoobig ( mem [x + 1 ].cint ) ;
    freenode ( p , 2 ) ;
    if ( curexp == x ) {
	
      if ( curtype == 19 ) 
      {
	curexp = mem [x + 1 ].cint ;
	curtype = 16 ;
	freenode ( x , 2 ) ;
      } 
    } 
  } 
  else {
      
    mem [x ].hhfield .b0 = 17 ;
    depfinal = finalnode ;
    newdep ( x , p ) ;
    if ( curexp == x ) {
	
      if ( curtype == 19 ) 
      curtype = 17 ;
    } 
  } 
  if ( fixneeded ) 
  fixdependencies () ;
} 
halfword 
znewringentry ( halfword p ) 
{
  register halfword Result; halfword q  ;
  q = getnode ( 2 ) ;
  mem [q ].hhfield .b1 = 11 ;
  mem [q ].hhfield .b0 = mem [p ].hhfield .b0 ;
  if ( mem [p + 1 ].cint == 0 ) 
  mem [q + 1 ].cint = p ;
  else mem [q + 1 ].cint = mem [p + 1 ].cint ;
  mem [p + 1 ].cint = q ;
  Result = q ;
  return Result ;
} 
void 
znonlineareq ( integer v , halfword p , boolean flushp ) 
{
  smallnumber t  ;
  halfword q, r  ;
  t = mem [p ].hhfield .b0 - 1 ;
  q = mem [p + 1 ].cint ;
  if ( flushp ) 
  mem [p ].hhfield .b0 = 1 ;
  else p = q ;
  do {
      r = mem [q + 1 ].cint ;
    mem [q ].hhfield .b0 = t ;
    switch ( t ) 
    {case 2 : 
      mem [q + 1 ].cint = v ;
      break ;
    case 4 : 
      {
	mem [q + 1 ].cint = v ;
	{
	  if ( strref [v ]< 127 ) 
	  incr ( strref [v ]) ;
	} 
      } 
      break ;
    case 6 : 
      {
	mem [q + 1 ].cint = v ;
	incr ( mem [v ].hhfield .lhfield ) ;
      } 
      break ;
    case 9 : 
      mem [q + 1 ].cint = copypath ( v ) ;
      break ;
    case 11 : 
      mem [q + 1 ].cint = copyedges ( v ) ;
      break ;
    } 
    q = r ;
  } while ( ! ( q == p ) ) ;
} 
void 
zringmerge ( halfword p , halfword q ) 
{
  /* 10 */ halfword r  ;
  r = mem [p + 1 ].cint ;
  while ( r != p ) {
      
    if ( r == q ) 
    {
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	  {
	    printnl ( 261 ) ;
	    print ( fullsourcefilenamestack [inopen ]) ;
	    print ( 58 ) ;
	    printint ( line ) ;
	    print ( 262 ) ;
	    print ( 600 ) ;
	  } 
	  else {
	      
	    printnl ( 263 ) ;
	    print ( 600 ) ;
	  } 
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 601 ;
	  helpline [0 ]= 602 ;
	} 
	putgeterror () ;
      } 
      goto lab10 ;
    } 
    r = mem [r + 1 ].cint ;
  } 
  r = mem [p + 1 ].cint ;
  mem [p + 1 ].cint = mem [q + 1 ].cint ;
  mem [q + 1 ].cint = r ;
  lab10: ;
} 
void 
zshowcmdmod ( integer c , integer m ) 
{
  begindiagnostic () ;
  printnl ( 123 ) ;
  printcmdmod ( c , m ) ;
  printchar ( 125 ) ;
  enddiagnostic ( false ) ;
} 
void 
showcontext ( void ) 
{
  /* 30 */ unsigned char oldsetting  ;
  integer i  ;
  integer l  ;
  integer m  ;
  integer n  ;
  integer p  ;
  integer q  ;
  fileptr = inputptr ;
  inputstack [fileptr ]= curinput ;
  while ( true ) {
      
    curinput = inputstack [fileptr ];
    if ( ( fileptr == inputptr ) || ( curinput .indexfield <= 15 ) || ( 
    curinput .indexfield != 19 ) || ( curinput .locfield != 0 ) ) 
    {
      tally = 0 ;
      oldsetting = selector ;
      if ( ( curinput .indexfield <= 15 ) ) 
      {
	if ( curinput .namefield <= 1 ) {
	    
	  if ( ( curinput .namefield == 0 ) && ( fileptr == 0 ) ) 
	  printnl ( 604 ) ;
	  else printnl ( 605 ) ;
	} 
	else if ( curinput .namefield == 2 ) 
	printnl ( 606 ) ;
	else {
	    
	  printnl ( 607 ) ;
	  printint ( line ) ;
	} 
	printchar ( 32 ) ;
	{
	  l = tally ;
	  tally = 0 ;
	  selector = 4 ;
	  trickcount = 1000000L ;
	} 
	if ( curinput .limitfield > 0 ) 
	{register integer for_end; i = curinput .startfield ;for_end = 
	curinput .limitfield - 1 ; if ( i <= for_end) do 
	  {
	    if ( i == curinput .locfield ) 
	    {
	      firstcount = tally ;
	      trickcount = tally + 1 + errorline - halferrorline ;
	      if ( trickcount < errorline ) 
	      trickcount = errorline ;
	    } 
	    print ( buffer [i ]) ;
	  } 
	while ( i++ < for_end ) ;} 
      } 
      else {
	  
	switch ( curinput .indexfield ) 
	{case 16 : 
	  printnl ( 608 ) ;
	  break ;
	case 17 : 
	  {
	    printnl ( 613 ) ;
	    p = paramstack [curinput .limitfield ];
	    if ( p != 0 ) {
		
	      if ( mem [p ].hhfield .v.RH == 1 ) 
	      printexp ( p , 0 ) ;
	      else showtokenlist ( p , 0 , 20 , tally ) ;
	    } 
	    print ( 614 ) ;
	  } 
	  break ;
	case 18 : 
	  printnl ( 609 ) ;
	  break ;
	case 19 : 
	  if ( curinput .locfield == 0 ) 
	  printnl ( 610 ) ;
	  else printnl ( 611 ) ;
	  break ;
	case 20 : 
	  printnl ( 612 ) ;
	  break ;
	case 21 : 
	  {
	    println () ;
	    if ( curinput .namefield != 0 ) 
	    slowprint ( hash [curinput .namefield ].v.RH ) ;
	    else {
		
	      p = paramstack [curinput .limitfield ];
	      if ( p == 0 ) 
	      showtokenlist ( paramstack [curinput .limitfield + 1 ], 0 , 20 
	      , tally ) ;
	      else {
		  
		q = p ;
		while ( mem [q ].hhfield .v.RH != 0 ) q = mem [q ].hhfield 
		.v.RH ;
		mem [q ].hhfield .v.RH = paramstack [curinput .limitfield + 
		1 ];
		showtokenlist ( p , 0 , 20 , tally ) ;
		mem [q ].hhfield .v.RH = 0 ;
	      } 
	    } 
	    print ( 501 ) ;
	  } 
	  break ;
	  default: 
	  printnl ( 63 ) ;
	  break ;
	} 
	{
	  l = tally ;
	  tally = 0 ;
	  selector = 4 ;
	  trickcount = 1000000L ;
	} 
	if ( curinput .indexfield != 21 ) 
	showtokenlist ( curinput .startfield , curinput .locfield , 100000L , 
	0 ) ;
	else showmacro ( curinput .startfield , curinput .locfield , 100000L ) 
	;
      } 
      selector = oldsetting ;
      if ( trickcount == 1000000L ) 
      {
	firstcount = tally ;
	trickcount = tally + 1 + errorline - halferrorline ;
	if ( trickcount < errorline ) 
	trickcount = errorline ;
      } 
      if ( tally < trickcount ) 
      m = tally - firstcount ;
      else m = trickcount - firstcount ;
      if ( l + firstcount <= halferrorline ) 
      {
	p = 0 ;
	n = l + firstcount ;
      } 
      else {
	  
	print ( 276 ) ;
	p = l + firstcount - halferrorline + 3 ;
	n = halferrorline ;
      } 
      {register integer for_end; q = p ;for_end = firstcount - 1 ; if ( q <= 
      for_end) do 
	printchar ( trickbuf [q % errorline ]) ;
      while ( q++ < for_end ) ;} 
      println () ;
      {register integer for_end; q = 1 ;for_end = n ; if ( q <= for_end) do 
	printchar ( 32 ) ;
      while ( q++ < for_end ) ;} 
      if ( m + n <= errorline ) 
      p = firstcount + m ;
      else p = firstcount + ( errorline - n - 3 ) ;
      {register integer for_end; q = firstcount ;for_end = p - 1 ; if ( q <= 
      for_end) do 
	printchar ( trickbuf [q % errorline ]) ;
      while ( q++ < for_end ) ;} 
      if ( m + n > errorline ) 
      print ( 276 ) ;
    } 
    if ( ( curinput .indexfield <= 15 ) ) {
	
      if ( ( curinput .namefield > 2 ) || ( fileptr == 0 ) ) 
      goto lab30 ;
    } 
    decr ( fileptr ) ;
  } 
  lab30: curinput = inputstack [inputptr ];
} 
void 
zbegintokenlist ( halfword p , quarterword t ) 
{
  {
    if ( inputptr > maxinstack ) 
    {
      maxinstack = inputptr ;
      if ( inputptr == stacksize ) 
      overflow ( 615 , stacksize ) ;
    } 
    inputstack [inputptr ]= curinput ;
    incr ( inputptr ) ;
  } 
  curinput .startfield = p ;
  curinput .indexfield = t ;
  curinput .limitfield = paramptr ;
  curinput .locfield = p ;
} 
void 
endtokenlist ( void ) 
{
  /* 30 */ halfword p  ;
  if ( curinput .indexfield >= 19 ) {
      
    if ( curinput .indexfield <= 20 ) 
    {
      flushtokenlist ( curinput .startfield ) ;
      goto lab30 ;
    } 
    else deletemacref ( curinput .startfield ) ;
  } 
  while ( paramptr > curinput .limitfield ) {
      
    decr ( paramptr ) ;
    p = paramstack [paramptr ];
    if ( p != 0 ) {
	
      if ( mem [p ].hhfield .v.RH == 1 ) 
      {
	recyclevalue ( p ) ;
	freenode ( p , 2 ) ;
      } 
      else flushtokenlist ( p ) ;
    } 
  } 
  lab30: {
      
    decr ( inputptr ) ;
    curinput = inputstack [inputptr ];
  } 
  {
    if ( interrupt != 0 ) 
    pauseforinstructions () ;
  } 
} 
void 
zencapsulate ( halfword p ) 
{
  curexp = getnode ( 2 ) ;
  mem [curexp ].hhfield .b0 = curtype ;
  mem [curexp ].hhfield .b1 = 11 ;
  newdep ( curexp , p ) ;
} 
void 
zinstall ( halfword r , halfword q ) 
{
  halfword p  ;
  if ( mem [q ].hhfield .b0 == 16 ) 
  {
    mem [r + 1 ].cint = mem [q + 1 ].cint ;
    mem [r ].hhfield .b0 = 16 ;
  } 
  else if ( mem [q ].hhfield .b0 == 19 ) 
  {
    p = singledependency ( q ) ;
    if ( p == depfinal ) 
    {
      mem [r ].hhfield .b0 = 16 ;
      mem [r + 1 ].cint = 0 ;
      freenode ( p , 2 ) ;
    } 
    else {
	
      mem [r ].hhfield .b0 = 17 ;
      newdep ( r , p ) ;
    } 
  } 
  else {
      
    mem [r ].hhfield .b0 = mem [q ].hhfield .b0 ;
    newdep ( r , copydeplist ( mem [q + 1 ].hhfield .v.RH ) ) ;
  } 
} 
void 
zmakeexpcopy ( halfword p ) 
{
  /* 20 */ halfword q, r, t  ;
  lab20: curtype = mem [p ].hhfield .b0 ;
  switch ( curtype ) 
  {case 1 : 
  case 2 : 
  case 16 : 
    curexp = mem [p + 1 ].cint ;
    break ;
  case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
    curexp = newringentry ( p ) ;
    break ;
  case 4 : 
    {
      curexp = mem [p + 1 ].cint ;
      {
	if ( strref [curexp ]< 127 ) 
	incr ( strref [curexp ]) ;
      } 
    } 
    break ;
  case 6 : 
    {
      curexp = mem [p + 1 ].cint ;
      incr ( mem [curexp ].hhfield .lhfield ) ;
    } 
    break ;
  case 11 : 
    curexp = copyedges ( mem [p + 1 ].cint ) ;
    break ;
  case 9 : 
  case 8 : 
    curexp = copypath ( mem [p + 1 ].cint ) ;
    break ;
  case 13 : 
  case 14 : 
    {
      if ( mem [p + 1 ].cint == 0 ) 
      initbignode ( p ) ;
      t = getnode ( 2 ) ;
      mem [t ].hhfield .b1 = 11 ;
      mem [t ].hhfield .b0 = curtype ;
      initbignode ( t ) ;
      q = mem [p + 1 ].cint + bignodesize [curtype ];
      r = mem [t + 1 ].cint + bignodesize [curtype ];
      do {
	  q = q - 2 ;
	r = r - 2 ;
	install ( r , q ) ;
      } while ( ! ( q == mem [p + 1 ].cint ) ) ;
      curexp = t ;
    } 
    break ;
  case 17 : 
  case 18 : 
    encapsulate ( copydeplist ( mem [p + 1 ].hhfield .v.RH ) ) ;
    break ;
  case 15 : 
    {
      {
	if ( serialno > 2147483583L ) 
	overflow ( 588 , serialno / 64 ) ;
	mem [p ].hhfield .b0 = 19 ;
	serialno = serialno + 64 ;
	mem [p + 1 ].cint = serialno ;
      } 
      goto lab20 ;
    } 
    break ;
  case 19 : 
    {
      q = singledependency ( p ) ;
      if ( q == depfinal ) 
      {
	curtype = 16 ;
	curexp = 0 ;
	freenode ( q , 2 ) ;
      } 
      else {
	  
	curtype = 17 ;
	encapsulate ( q ) ;
      } 
    } 
    break ;
    default: 
    confusion ( 800 ) ;
    break ;
  } 
} 
halfword 
curtok ( void ) 
{
  register halfword Result; halfword p  ;
  smallnumber savetype  ;
  integer saveexp  ;
  if ( cursym == 0 ) {
      
    if ( curcmd == 38 ) 
    {
      savetype = curtype ;
      saveexp = curexp ;
      makeexpcopy ( curmod ) ;
      p = stashcurexp () ;
      mem [p ].hhfield .v.RH = 0 ;
      curtype = savetype ;
      curexp = saveexp ;
    } 
    else {
	
      p = getnode ( 2 ) ;
      mem [p + 1 ].cint = curmod ;
      mem [p ].hhfield .b1 = 12 ;
      if ( curcmd == 42 ) 
      mem [p ].hhfield .b0 = 16 ;
      else mem [p ].hhfield .b0 = 4 ;
    } 
  } 
  else {
      
    {
      p = avail ;
      if ( p == 0 ) 
      p = getavail () ;
      else {
	  
	avail = mem [p ].hhfield .v.RH ;
	mem [p ].hhfield .v.RH = 0 ;
	;
#ifdef STAT
	incr ( dynused ) ;
#endif /* STAT */
      } 
    } 
    mem [p ].hhfield .lhfield = cursym ;
  } 
  Result = p ;
  return Result ;
} 
void 
backinput ( void ) 
{
  halfword p  ;
  p = curtok () ;
  while ( ( curinput .indexfield > 15 ) && ( curinput .locfield == 0 ) ) 
  endtokenlist () ;
  begintokenlist ( p , 19 ) ;
} 
void 
backerror ( void ) 
{
  OKtointerrupt = false ;
  backinput () ;
  OKtointerrupt = true ;
  error () ;
} 
void 
inserror ( void ) 
{
  OKtointerrupt = false ;
  backinput () ;
  curinput .indexfield = 20 ;
  OKtointerrupt = true ;
  error () ;
} 
void 
beginfilereading ( void ) 
{
  if ( inopen == 15 ) 
  overflow ( 616 , 15 ) ;
  if ( first == bufsize ) 
  overflow ( 256 , bufsize ) ;
  incr ( inopen ) ;
  {
    if ( inputptr > maxinstack ) 
    {
      maxinstack = inputptr ;
      if ( inputptr == stacksize ) 
      overflow ( 615 , stacksize ) ;
    } 
    inputstack [inputptr ]= curinput ;
    incr ( inputptr ) ;
  } 
  curinput .indexfield = inopen ;
  linestack [curinput .indexfield ]= line ;
  curinput .startfield = first ;
  curinput .namefield = 0 ;
} 
void 
endfilereading ( void ) 
{
  first = curinput .startfield ;
  line = linestack [curinput .indexfield ];
  if ( curinput .indexfield != inopen ) 
  confusion ( 617 ) ;
  if ( curinput .namefield > 2 ) 
  aclose ( inputfile [curinput .indexfield ]) ;
  {
    decr ( inputptr ) ;
    curinput = inputstack [inputptr ];
  } 
  decr ( inopen ) ;
} 
void 
clearforerrorprompt ( void ) 
{
  while ( ( curinput .indexfield <= 15 ) && ( curinput .namefield == 0 ) && 
  ( inputptr > 0 ) && ( curinput .locfield == curinput .limitfield ) ) 
  endfilereading () ;
  println () ;
} 
boolean 
checkoutervalidity ( void ) 
{
  register boolean Result; halfword p  ;
  if ( scannerstatus == 0 ) 
  Result = true ;
  else {
      
    deletionsallowed = false ;
    if ( cursym != 0 ) 
    {
      p = getavail () ;
      mem [p ].hhfield .lhfield = cursym ;
      begintokenlist ( p , 19 ) ;
    } 
    if ( scannerstatus > 1 ) 
    {
      runaway () ;
      if ( cursym == 0 ) 
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 623 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 623 ) ;
	} 
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	  {
	    printnl ( 261 ) ;
	    print ( fullsourcefilenamestack [inopen ]) ;
	    print ( 58 ) ;
	    printint ( line ) ;
	    print ( 262 ) ;
	    print ( 624 ) ;
	  } 
	  else {
	      
	    printnl ( 263 ) ;
	    print ( 624 ) ;
	  } 
	} 
      } 
      print ( 625 ) ;
      {
	helpptr = 4 ;
	helpline [3 ]= 626 ;
	helpline [2 ]= 627 ;
	helpline [1 ]= 628 ;
	helpline [0 ]= 629 ;
      } 
      switch ( scannerstatus ) 
      {case 2 : 
	{
	  print ( 630 ) ;
	  helpline [3 ]= 631 ;
	  cursym = 9763 ;
	} 
	break ;
      case 3 : 
	{
	  print ( 632 ) ;
	  helpline [3 ]= 633 ;
	  if ( warninginfo == 0 ) 
	  cursym = 9767 ;
	  else {
	      
	    cursym = 9759 ;
	    eqtb [9759 ].v.RH = warninginfo ;
	  } 
	} 
	break ;
      case 4 : 
      case 5 : 
	{
	  print ( 634 ) ;
	  if ( scannerstatus == 5 ) 
	  slowprint ( hash [warninginfo ].v.RH ) ;
	  else printvariablename ( warninginfo ) ;
	  cursym = 9765 ;
	} 
	break ;
      case 6 : 
	{
	  print ( 635 ) ;
	  slowprint ( hash [warninginfo ].v.RH ) ;
	  print ( 636 ) ;
	  helpline [3 ]= 637 ;
	  cursym = 9764 ;
	} 
	break ;
      } 
      inserror () ;
    } 
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 618 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 618 ) ;
	} 
      } 
      printint ( warninginfo ) ;
      {
	helpptr = 3 ;
	helpline [2 ]= 619 ;
	helpline [1 ]= 620 ;
	helpline [0 ]= 621 ;
      } 
      if ( cursym == 0 ) 
      helpline [2 ]= 622 ;
      cursym = 9766 ;
      inserror () ;
    } 
    deletionsallowed = true ;
    Result = false ;
  } 
  return Result ;
} 
void 
getnext ( void ) 
{
  /* 20 10 40 25 85 86 87 30 */ integer k  ;
  ASCIIcode c  ;
  ASCIIcode cclass  ;
  integer n, f  ;
  lab20: cursym = 0 ;
  if ( ( curinput .indexfield <= 15 ) ) 
  {
    lab25: c = buffer [curinput .locfield ];
    incr ( curinput .locfield ) ;
    cclass = charclass [c ];
    switch ( cclass ) 
    {case 0 : 
      goto lab85 ;
      break ;
    case 1 : 
      {
	cclass = charclass [buffer [curinput .locfield ]];
	if ( cclass > 1 ) 
	goto lab25 ;
	else if ( cclass < 1 ) 
	{
	  n = 0 ;
	  goto lab86 ;
	} 
      } 
      break ;
    case 2 : 
      goto lab25 ;
      break ;
    case 3 : 
      {
	if ( curinput .namefield > 2 ) 
	{
	  incr ( line ) ;
	  first = curinput .startfield ;
	  if ( ! forceeof ) 
	  {
	    if ( inputln ( inputfile [curinput .indexfield ], true ) ) 
	    firmuptheline () ;
	    else forceeof = true ;
	  } 
	  if ( forceeof ) 
	  {
	    printchar ( 41 ) ;
	    decr ( openparens ) ;
	    fflush ( stdout ) ;
	    forceeof = false ;
	    endfilereading () ;
	    if ( checkoutervalidity () ) 
	    goto lab20 ;
	    else goto lab20 ;
	  } 
	  buffer [curinput .limitfield ]= 37 ;
	  first = curinput .limitfield + 1 ;
	  curinput .locfield = curinput .startfield ;
	} 
	else {
	    
	  if ( inputptr > 0 ) 
	  {
	    endfilereading () ;
	    goto lab20 ;
	  } 
	  if ( selector < 2 ) 
	  openlogfile () ;
	  if ( interaction > 1 ) 
	  {
	    if ( curinput .limitfield == curinput .startfield ) 
	    printnl ( 652 ) ;
	    println () ;
	    first = curinput .startfield ;
	    {
	      ;
	      print ( 42 ) ;
	      terminput () ;
	    } 
	    curinput .limitfield = last ;
	    buffer [curinput .limitfield ]= 37 ;
	    first = curinput .limitfield + 1 ;
	    curinput .locfield = curinput .startfield ;
	  } 
	  else fatalerror ( 653 ) ;
	} 
	{
	  if ( interrupt != 0 ) 
	  pauseforinstructions () ;
	} 
	goto lab25 ;
      } 
      break ;
    case 4 : 
      {
	if ( buffer [curinput .locfield ]== 34 ) 
	curmod = 261 ;
	else {
	    
	  k = curinput .locfield ;
	  buffer [curinput .limitfield + 1 ]= 34 ;
	  do {
	      incr ( curinput .locfield ) ;
	  } while ( ! ( buffer [curinput .locfield ]== 34 ) ) ;
	  if ( curinput .locfield > curinput .limitfield ) 
	  {
	    curinput .locfield = curinput .limitfield ;
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	      {
		printnl ( 261 ) ;
		print ( fullsourcefilenamestack [inopen ]) ;
		print ( 58 ) ;
		printint ( line ) ;
		print ( 262 ) ;
		print ( 645 ) ;
	      } 
	      else {
		  
		printnl ( 263 ) ;
		print ( 645 ) ;
	      } 
	    } 
	    {
	      helpptr = 3 ;
	      helpline [2 ]= 646 ;
	      helpline [1 ]= 647 ;
	      helpline [0 ]= 648 ;
	    } 
	    deletionsallowed = false ;
	    error () ;
	    deletionsallowed = true ;
	    goto lab20 ;
	  } 
	  if ( ( curinput .locfield == k + 1 ) && ( ( strstart [buffer [k ]
	  + 1 ]- strstart [buffer [k ]]) == 1 ) ) 
	  curmod = buffer [k ];
	  else {
	      
	    {
	      if ( poolptr + curinput .locfield - k > maxpoolptr ) 
	      {
		if ( poolptr + curinput .locfield - k > poolsize ) 
		overflow ( 257 , poolsize - initpoolptr ) ;
		maxpoolptr = poolptr + curinput .locfield - k ;
	      } 
	    } 
	    do {
		{ 
		strpool [poolptr ]= buffer [k ];
		incr ( poolptr ) ;
	      } 
	      incr ( k ) ;
	    } while ( ! ( k == curinput .locfield ) ) ;
	    curmod = makestring () ;
	  } 
	} 
	incr ( curinput .locfield ) ;
	curcmd = 39 ;
	goto lab10 ;
      } 
      break ;
    case 5 : 
    case 6 : 
    case 7 : 
    case 8 : 
      {
	k = curinput .locfield - 1 ;
	goto lab40 ;
      } 
      break ;
    case 20 : 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	  {
	    printnl ( 261 ) ;
	    print ( fullsourcefilenamestack [inopen ]) ;
	    print ( 58 ) ;
	    printint ( line ) ;
	    print ( 262 ) ;
	    print ( 642 ) ;
	  } 
	  else {
	      
	    printnl ( 263 ) ;
	    print ( 642 ) ;
	  } 
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 643 ;
	  helpline [0 ]= 644 ;
	} 
	deletionsallowed = false ;
	error () ;
	deletionsallowed = true ;
	goto lab20 ;
      } 
      break ;
      default: 
      ;
      break ;
    } 
    k = curinput .locfield - 1 ;
    while ( charclass [buffer [curinput .locfield ]]== cclass ) incr ( 
    curinput .locfield ) ;
    goto lab40 ;
    lab85: n = c - 48 ;
    while ( charclass [buffer [curinput .locfield ]]== 0 ) {
	
      if ( n < 4096 ) 
      n = 10 * n + buffer [curinput .locfield ]- 48 ;
      incr ( curinput .locfield ) ;
    } 
    if ( buffer [curinput .locfield ]== 46 ) {
	
      if ( charclass [buffer [curinput .locfield + 1 ]]== 0 ) 
      goto lab30 ;
    } 
    f = 0 ;
    goto lab87 ;
    lab30: incr ( curinput .locfield ) ;
    lab86: k = 0 ;
    do {
	if ( k < 17 ) 
      {
	dig [k ]= buffer [curinput .locfield ]- 48 ;
	incr ( k ) ;
      } 
      incr ( curinput .locfield ) ;
    } while ( ! ( charclass [buffer [curinput .locfield ]]!= 0 ) ) ;
    f = rounddecimals ( k ) ;
    if ( f == 65536L ) 
    {
      incr ( n ) ;
      f = 0 ;
    } 
    lab87: if ( n < 4096 ) 
    curmod = n * 65536L + f ;
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 649 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 649 ) ;
	} 
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 650 ;
	helpline [0 ]= 651 ;
      } 
      deletionsallowed = false ;
      error () ;
      deletionsallowed = true ;
      curmod = 268435455L ;
    } 
    curcmd = 42 ;
    goto lab10 ;
    lab40: cursym = idlookup ( k , curinput .locfield - k ) ;
  } 
  else if ( curinput .locfield >= himemmin ) 
  {
    cursym = mem [curinput .locfield ].hhfield .lhfield ;
    curinput .locfield = mem [curinput .locfield ].hhfield .v.RH ;
    if ( cursym >= 9770 ) {
	
      if ( cursym >= 9920 ) 
      {
	if ( cursym >= 10070 ) 
	cursym = cursym - 150 ;
	begintokenlist ( paramstack [curinput .limitfield + cursym - ( 9920 ) 
	], 18 ) ;
	goto lab20 ;
      } 
      else {
	  
	curcmd = 38 ;
	curmod = paramstack [curinput .limitfield + cursym - ( 9770 ) ];
	cursym = 0 ;
	goto lab10 ;
      } 
    } 
  } 
  else if ( curinput .locfield > 0 ) 
  {
    if ( mem [curinput .locfield ].hhfield .b1 == 12 ) 
    {
      curmod = mem [curinput .locfield + 1 ].cint ;
      if ( mem [curinput .locfield ].hhfield .b0 == 16 ) 
      curcmd = 42 ;
      else {
	  
	curcmd = 39 ;
	{
	  if ( strref [curmod ]< 127 ) 
	  incr ( strref [curmod ]) ;
	} 
      } 
    } 
    else {
	
      curmod = curinput .locfield ;
      curcmd = 38 ;
    } 
    curinput .locfield = mem [curinput .locfield ].hhfield .v.RH ;
    goto lab10 ;
  } 
  else {
      
    endtokenlist () ;
    goto lab20 ;
  } 
  curcmd = eqtb [cursym ].lhfield ;
  curmod = eqtb [cursym ].v.RH ;
  if ( curcmd >= 86 ) {
      
    if ( checkoutervalidity () ) 
    curcmd = curcmd - 86 ;
    else goto lab20 ;
  } 
  lab10: ;
} 
void 
firmuptheline ( void ) 
{
  integer k  ;
  curinput .limitfield = last ;
  if ( internal [31 ]> 0 ) {
      
    if ( interaction > 1 ) 
    {
      ;
      println () ;
      if ( curinput .startfield < curinput .limitfield ) 
      {register integer for_end; k = curinput .startfield ;for_end = 
      curinput .limitfield - 1 ; if ( k <= for_end) do 
	print ( buffer [k ]) ;
      while ( k++ < for_end ) ;} 
      first = curinput .limitfield ;
      {
	;
	print ( 654 ) ;
	terminput () ;
      } 
      if ( last > first ) 
      {
	{register integer for_end; k = first ;for_end = last - 1 ; if ( k <= 
	for_end) do 
	  buffer [k + curinput .startfield - first ]= buffer [k ];
	while ( k++ < for_end ) ;} 
	curinput .limitfield = curinput .startfield + last - first ;
      } 
    } 
  } 
} 
halfword 
zscantoks ( commandcode terminator , halfword substlist , halfword tailend , 
smallnumber suffixcount ) 
{
  /* 30 40 */ register halfword Result; halfword p  ;
  halfword q  ;
  integer balance  ;
  p = memtop - 2 ;
  balance = 1 ;
  mem [memtop - 2 ].hhfield .v.RH = 0 ;
  while ( true ) {
      
    getnext () ;
    if ( cursym > 0 ) 
    {
      {
	q = substlist ;
	while ( q != 0 ) {
	    
	  if ( mem [q ].hhfield .lhfield == cursym ) 
	  {
	    cursym = mem [q + 1 ].cint ;
	    curcmd = 7 ;
	    goto lab40 ;
	  } 
	  q = mem [q ].hhfield .v.RH ;
	} 
	lab40: ;
      } 
      if ( curcmd == terminator ) {
	  
	if ( curmod > 0 ) 
	incr ( balance ) ;
	else {
	    
	  decr ( balance ) ;
	  if ( balance == 0 ) 
	  goto lab30 ;
	} 
      } 
      else if ( curcmd == 61 ) 
      {
	if ( curmod == 0 ) 
	getnext () ;
	else if ( curmod <= suffixcount ) 
	cursym = 9919 + curmod ;
      } 
    } 
    mem [p ].hhfield .v.RH = curtok () ;
    p = mem [p ].hhfield .v.RH ;
  } 
  lab30: mem [p ].hhfield .v.RH = tailend ;
  flushnodelist ( substlist ) ;
  Result = mem [memtop - 2 ].hhfield .v.RH ;
  return Result ;
} 
void 
getsymbol ( void ) 
{
  /* 20 */ lab20: getnext () ;
  if ( ( cursym == 0 ) || ( cursym > 9757 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 666 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 666 ) ;
      } 
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 667 ;
      helpline [1 ]= 668 ;
      helpline [0 ]= 669 ;
    } 
    if ( cursym > 0 ) 
    helpline [2 ]= 670 ;
    else if ( curcmd == 39 ) 
    {
      if ( strref [curmod ]< 127 ) {
	  
	if ( strref [curmod ]> 1 ) 
	decr ( strref [curmod ]) ;
	else flushstring ( curmod ) ;
      } 
    } 
    cursym = 9757 ;
    inserror () ;
    goto lab20 ;
  } 
} 
void 
getclearsymbol ( void ) 
{
  getsymbol () ;
  clearsymbol ( cursym , false ) ;
} 
void 
checkequals ( void ) 
{
  if ( curcmd != 51 ) {
      
    if ( curcmd != 77 ) 
    {
      missingerr ( 61 ) ;
      {
	helpptr = 5 ;
	helpline [4 ]= 671 ;
	helpline [3 ]= 672 ;
	helpline [2 ]= 673 ;
	helpline [1 ]= 674 ;
	helpline [0 ]= 675 ;
      } 
      backerror () ;
    } 
  } 
} 
void 
makeopdef ( void ) 
{
  commandcode m  ;
  halfword p, q, r  ;
  m = curmod ;
  getsymbol () ;
  q = getnode ( 2 ) ;
  mem [q ].hhfield .lhfield = cursym ;
  mem [q + 1 ].cint = 9770 ;
  getclearsymbol () ;
  warninginfo = cursym ;
  getsymbol () ;
  p = getnode ( 2 ) ;
  mem [p ].hhfield .lhfield = cursym ;
  mem [p + 1 ].cint = 9771 ;
  mem [p ].hhfield .v.RH = q ;
  getnext () ;
  checkequals () ;
  scannerstatus = 5 ;
  q = getavail () ;
  mem [q ].hhfield .lhfield = 0 ;
  r = getavail () ;
  mem [q ].hhfield .v.RH = r ;
  mem [r ].hhfield .lhfield = 0 ;
  mem [r ].hhfield .v.RH = scantoks ( 16 , p , 0 , 0 ) ;
  scannerstatus = 0 ;
  eqtb [warninginfo ].lhfield = m ;
  eqtb [warninginfo ].v.RH = q ;
  getxnext () ;
} 
void 
zcheckdelimiter ( halfword ldelim , halfword rdelim ) 
{
  /* 10 */ if ( curcmd == 62 ) {
      
    if ( curmod == ldelim ) 
    goto lab10 ;
  } 
  if ( cursym != rdelim ) 
  {
    missingerr ( hash [rdelim ].v.RH ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 922 ;
      helpline [0 ]= 923 ;
    } 
    backerror () ;
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 924 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 924 ) ;
      } 
    } 
    slowprint ( hash [rdelim ].v.RH ) ;
    print ( 925 ) ;
    {
      helpptr = 3 ;
      helpline [2 ]= 926 ;
      helpline [1 ]= 927 ;
      helpline [0 ]= 928 ;
    } 
    error () ;
  } 
  lab10: ;
} 
halfword 
scandeclaredvariable ( void ) 
{
  /* 30 */ register halfword Result; halfword x  ;
  halfword h, t  ;
  halfword l  ;
  getsymbol () ;
  x = cursym ;
  if ( curcmd != 41 ) 
  clearsymbol ( x , false ) ;
  h = getavail () ;
  mem [h ].hhfield .lhfield = x ;
  t = h ;
  while ( true ) {
      
    getxnext () ;
    if ( cursym == 0 ) 
    goto lab30 ;
    if ( curcmd != 41 ) {
	
      if ( curcmd != 40 ) {
	  
	if ( curcmd == 63 ) 
	{
	  l = cursym ;
	  getxnext () ;
	  if ( curcmd != 64 ) 
	  {
	    backinput () ;
	    cursym = l ;
	    curcmd = 63 ;
	    goto lab30 ;
	  } 
	  else cursym = 0 ;
	} 
	else goto lab30 ;
      } 
    } 
    mem [t ].hhfield .v.RH = getavail () ;
    t = mem [t ].hhfield .v.RH ;
    mem [t ].hhfield .lhfield = cursym ;
  } 
  lab30: if ( eqtb [x ].lhfield % 86 != 41 ) 
  clearsymbol ( x , false ) ;
  if ( eqtb [x ].v.RH == 0 ) 
  newroot ( x ) ;
  Result = h ;
  return Result ;
} 
void 
scandef ( void ) 
{
  unsigned char m  ;
  unsigned char n  ;
  unsigned char k  ;
  unsigned char c  ;
  halfword r  ;
  halfword q  ;
  halfword p  ;
  halfword base  ;
  halfword ldelim, rdelim  ;
  m = curmod ;
  c = 0 ;
  mem [memtop - 2 ].hhfield .v.RH = 0 ;
  q = getavail () ;
  mem [q ].hhfield .lhfield = 0 ;
  r = 0 ;
  if ( m == 1 ) 
  {
    getclearsymbol () ;
    warninginfo = cursym ;
    getnext () ;
    scannerstatus = 5 ;
    n = 0 ;
    eqtb [warninginfo ].lhfield = 10 ;
    eqtb [warninginfo ].v.RH = q ;
  } 
  else {
      
    p = scandeclaredvariable () ;
    flushvariable ( eqtb [mem [p ].hhfield .lhfield ].v.RH , mem [p ]
    .hhfield .v.RH , true ) ;
    warninginfo = findvariable ( p ) ;
    flushlist ( p ) ;
    if ( warninginfo == 0 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 682 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 682 ) ;
	} 
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 683 ;
	helpline [0 ]= 684 ;
      } 
      error () ;
      warninginfo = 21 ;
    } 
    scannerstatus = 4 ;
    n = 2 ;
    if ( curcmd == 61 ) {
	
      if ( curmod == 3 ) 
      {
	n = 3 ;
	getnext () ;
      } 
    } 
    mem [warninginfo ].hhfield .b0 = 20 + n ;
    mem [warninginfo + 1 ].cint = q ;
  } 
  k = n ;
  if ( curcmd == 31 ) 
  do {
      ldelim = cursym ;
    rdelim = curmod ;
    getnext () ;
    if ( ( curcmd == 56 ) && ( curmod >= 9770 ) ) 
    base = curmod ;
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 685 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 685 ) ;
	} 
      } 
      {
	helpptr = 1 ;
	helpline [0 ]= 686 ;
      } 
      backerror () ;
      base = 9770 ;
    } 
    do {
	mem [q ].hhfield .v.RH = getavail () ;
      q = mem [q ].hhfield .v.RH ;
      mem [q ].hhfield .lhfield = base + k ;
      getsymbol () ;
      p = getnode ( 2 ) ;
      mem [p + 1 ].cint = base + k ;
      mem [p ].hhfield .lhfield = cursym ;
      if ( k == 150 ) 
      overflow ( 687 , 150 ) ;
      incr ( k ) ;
      mem [p ].hhfield .v.RH = r ;
      r = p ;
      getnext () ;
    } while ( ! ( curcmd != 82 ) ) ;
    checkdelimiter ( ldelim , rdelim ) ;
    getnext () ;
  } while ( ! ( curcmd != 31 ) ) ;
  if ( curcmd == 56 ) 
  {
    p = getnode ( 2 ) ;
    if ( curmod < 9770 ) 
    {
      c = curmod ;
      mem [p + 1 ].cint = 9770 + k ;
    } 
    else {
	
      mem [p + 1 ].cint = curmod + k ;
      if ( curmod == 9770 ) 
      c = 4 ;
      else if ( curmod == 9920 ) 
      c = 6 ;
      else c = 7 ;
    } 
    if ( k == 150 ) 
    overflow ( 687 , 150 ) ;
    incr ( k ) ;
    getsymbol () ;
    mem [p ].hhfield .lhfield = cursym ;
    mem [p ].hhfield .v.RH = r ;
    r = p ;
    getnext () ;
    if ( c == 4 ) {
	
      if ( curcmd == 69 ) 
      {
	c = 5 ;
	p = getnode ( 2 ) ;
	if ( k == 150 ) 
	overflow ( 687 , 150 ) ;
	mem [p + 1 ].cint = 9770 + k ;
	getsymbol () ;
	mem [p ].hhfield .lhfield = cursym ;
	mem [p ].hhfield .v.RH = r ;
	r = p ;
	getnext () ;
      } 
    } 
  } 
  checkequals () ;
  p = getavail () ;
  mem [p ].hhfield .lhfield = c ;
  mem [q ].hhfield .v.RH = p ;
  if ( m == 1 ) 
  mem [p ].hhfield .v.RH = scantoks ( 16 , r , 0 , n ) ;
  else {
      
    q = getavail () ;
    mem [q ].hhfield .lhfield = bgloc ;
    mem [p ].hhfield .v.RH = q ;
    p = getavail () ;
    mem [p ].hhfield .lhfield = egloc ;
    mem [q ].hhfield .v.RH = scantoks ( 16 , r , p , n ) ;
  } 
  if ( warninginfo == 21 ) 
  flushtokenlist ( mem [22 ].cint ) ;
  scannerstatus = 0 ;
  getxnext () ;
} 
void 
zprintmacroname ( halfword a , halfword n ) 
{
  halfword p, q  ;
  if ( n != 0 ) 
  slowprint ( hash [n ].v.RH ) ;
  else {
      
    p = mem [a ].hhfield .lhfield ;
    if ( p == 0 ) 
    slowprint ( hash [mem [mem [mem [a ].hhfield .v.RH ].hhfield 
    .lhfield ].hhfield .lhfield ].v.RH ) ;
    else {
	
      q = p ;
      while ( mem [q ].hhfield .v.RH != 0 ) q = mem [q ].hhfield .v.RH ;
      mem [q ].hhfield .v.RH = mem [mem [a ].hhfield .v.RH ].hhfield 
      .lhfield ;
      showtokenlist ( p , 0 , 1000 , 0 ) ;
      mem [q ].hhfield .v.RH = 0 ;
    } 
  } 
} 
void 
zprintarg ( halfword q , integer n , halfword b ) 
{
  if ( mem [q ].hhfield .v.RH == 1 ) 
  printnl ( 498 ) ;
  else if ( ( b < 10070 ) && ( b != 7 ) ) 
  printnl ( 499 ) ;
  else printnl ( 500 ) ;
  printint ( n ) ;
  print ( 703 ) ;
  if ( mem [q ].hhfield .v.RH == 1 ) 
  printexp ( q , 1 ) ;
  else showtokenlist ( q , 0 , 1000 , 0 ) ;
} 
void 
zscantextarg ( halfword ldelim , halfword rdelim ) 
{
  /* 30 */ integer balance  ;
  halfword p  ;
  warninginfo = ldelim ;
  scannerstatus = 3 ;
  p = memtop - 2 ;
  balance = 1 ;
  mem [memtop - 2 ].hhfield .v.RH = 0 ;
  while ( true ) {
      
    getnext () ;
    if ( ldelim == 0 ) 
    {
      if ( curcmd > 82 ) 
      {
	if ( balance == 1 ) 
	goto lab30 ;
	else if ( curcmd == 84 ) 
	decr ( balance ) ;
      } 
      else if ( curcmd == 32 ) 
      incr ( balance ) ;
    } 
    else {
	
      if ( curcmd == 62 ) 
      {
	if ( curmod == ldelim ) 
	{
	  decr ( balance ) ;
	  if ( balance == 0 ) 
	  goto lab30 ;
	} 
      } 
      else if ( curcmd == 31 ) {
	  
	if ( curmod == rdelim ) 
	incr ( balance ) ;
      } 
    } 
    mem [p ].hhfield .v.RH = curtok () ;
    p = mem [p ].hhfield .v.RH ;
  } 
  lab30: curexp = mem [memtop - 2 ].hhfield .v.RH ;
  curtype = 20 ;
  scannerstatus = 0 ;
} 
void 
zmacrocall ( halfword defref , halfword arglist , halfword macroname ) 
{
  /* 40 */ halfword r  ;
  halfword p, q  ;
  integer n  ;
  halfword ldelim, rdelim  ;
  halfword tail  ;
  r = mem [defref ].hhfield .v.RH ;
  incr ( mem [defref ].hhfield .lhfield ) ;
  if ( arglist == 0 ) 
  n = 0 ;
  else {
      
    n = 1 ;
    tail = arglist ;
    while ( mem [tail ].hhfield .v.RH != 0 ) {
	
      incr ( n ) ;
      tail = mem [tail ].hhfield .v.RH ;
    } 
  } 
  if ( internal [9 ]> 0 ) 
  {
    begindiagnostic () ;
    println () ;
    printmacroname ( arglist , macroname ) ;
    if ( n == 3 ) 
    print ( 665 ) ;
    showmacro ( defref , 0 , 100000L ) ;
    if ( arglist != 0 ) 
    {
      n = 0 ;
      p = arglist ;
      do {
	  q = mem [p ].hhfield .lhfield ;
	printarg ( q , n , 0 ) ;
	incr ( n ) ;
	p = mem [p ].hhfield .v.RH ;
      } while ( ! ( p == 0 ) ) ;
    } 
    enddiagnostic ( false ) ;
  } 
  curcmd = 83 ;
  while ( mem [r ].hhfield .lhfield >= 9770 ) {
      
    if ( curcmd != 82 ) 
    {
      getxnext () ;
      if ( curcmd != 31 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	  {
	    printnl ( 261 ) ;
	    print ( fullsourcefilenamestack [inopen ]) ;
	    print ( 58 ) ;
	    printint ( line ) ;
	    print ( 262 ) ;
	    print ( 709 ) ;
	  } 
	  else {
	      
	    printnl ( 263 ) ;
	    print ( 709 ) ;
	  } 
	} 
	printmacroname ( arglist , macroname ) ;
	{
	  helpptr = 3 ;
	  helpline [2 ]= 710 ;
	  helpline [1 ]= 711 ;
	  helpline [0 ]= 712 ;
	} 
	if ( mem [r ].hhfield .lhfield >= 9920 ) 
	{
	  curexp = 0 ;
	  curtype = 20 ;
	} 
	else {
	    
	  curexp = 0 ;
	  curtype = 16 ;
	} 
	backerror () ;
	curcmd = 62 ;
	goto lab40 ;
      } 
      ldelim = cursym ;
      rdelim = curmod ;
    } 
    if ( mem [r ].hhfield .lhfield >= 10070 ) 
    scantextarg ( ldelim , rdelim ) ;
    else {
	
      getxnext () ;
      if ( mem [r ].hhfield .lhfield >= 9920 ) 
      scansuffix () ;
      else scanexpression () ;
    } 
    if ( curcmd != 82 ) {
	
      if ( ( curcmd != 62 ) || ( curmod != ldelim ) ) {
	  
	if ( mem [mem [r ].hhfield .v.RH ].hhfield .lhfield >= 9770 ) 
	{
	  missingerr ( 44 ) ;
	  {
	    helpptr = 3 ;
	    helpline [2 ]= 713 ;
	    helpline [1 ]= 714 ;
	    helpline [0 ]= 708 ;
	  } 
	  backerror () ;
	  curcmd = 82 ;
	} 
	else {
	    
	  missingerr ( hash [rdelim ].v.RH ) ;
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 715 ;
	    helpline [0 ]= 708 ;
	  } 
	  backerror () ;
	} 
      } 
    } 
    lab40: {
	
      p = getavail () ;
      if ( curtype == 20 ) 
      mem [p ].hhfield .lhfield = curexp ;
      else mem [p ].hhfield .lhfield = stashcurexp () ;
      if ( internal [9 ]> 0 ) 
      {
	begindiagnostic () ;
	printarg ( mem [p ].hhfield .lhfield , n , mem [r ].hhfield 
	.lhfield ) ;
	enddiagnostic ( false ) ;
      } 
      if ( arglist == 0 ) 
      arglist = p ;
      else mem [tail ].hhfield .v.RH = p ;
      tail = p ;
      incr ( n ) ;
    } 
    r = mem [r ].hhfield .v.RH ;
  } 
  if ( curcmd == 82 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 704 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 704 ) ;
      } 
    } 
    printmacroname ( arglist , macroname ) ;
    printchar ( 59 ) ;
    printnl ( 705 ) ;
    slowprint ( hash [rdelim ].v.RH ) ;
    print ( 299 ) ;
    {
      helpptr = 3 ;
      helpline [2 ]= 706 ;
      helpline [1 ]= 707 ;
      helpline [0 ]= 708 ;
    } 
    error () ;
  } 
  if ( mem [r ].hhfield .lhfield != 0 ) 
  {
    if ( mem [r ].hhfield .lhfield < 7 ) 
    {
      getxnext () ;
      if ( mem [r ].hhfield .lhfield != 6 ) {
	  
	if ( ( curcmd == 51 ) || ( curcmd == 77 ) ) 
	getxnext () ;
      } 
    } 
    switch ( mem [r ].hhfield .lhfield ) 
    {case 1 : 
      scanprimary () ;
      break ;
    case 2 : 
      scansecondary () ;
      break ;
    case 3 : 
      scantertiary () ;
      break ;
    case 4 : 
      scanexpression () ;
      break ;
    case 5 : 
      {
	scanexpression () ;
	p = getavail () ;
	mem [p ].hhfield .lhfield = stashcurexp () ;
	if ( internal [9 ]> 0 ) 
	{
	  begindiagnostic () ;
	  printarg ( mem [p ].hhfield .lhfield , n , 0 ) ;
	  enddiagnostic ( false ) ;
	} 
	if ( arglist == 0 ) 
	arglist = p ;
	else mem [tail ].hhfield .v.RH = p ;
	tail = p ;
	incr ( n ) ;
	if ( curcmd != 69 ) 
	{
	  missingerr ( 479 ) ;
	  print ( 716 ) ;
	  printmacroname ( arglist , macroname ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 717 ;
	  } 
	  backerror () ;
	} 
	getxnext () ;
	scanprimary () ;
      } 
      break ;
    case 6 : 
      {
	if ( curcmd != 31 ) 
	ldelim = 0 ;
	else {
	    
	  ldelim = cursym ;
	  rdelim = curmod ;
	  getxnext () ;
	} 
	scansuffix () ;
	if ( ldelim != 0 ) 
	{
	  if ( ( curcmd != 62 ) || ( curmod != ldelim ) ) 
	  {
	    missingerr ( hash [rdelim ].v.RH ) ;
	    {
	      helpptr = 2 ;
	      helpline [1 ]= 715 ;
	      helpline [0 ]= 708 ;
	    } 
	    backerror () ;
	  } 
	  getxnext () ;
	} 
      } 
      break ;
    case 7 : 
      scantextarg ( 0 , 0 ) ;
      break ;
    } 
    backinput () ;
    {
      p = getavail () ;
      if ( curtype == 20 ) 
      mem [p ].hhfield .lhfield = curexp ;
      else mem [p ].hhfield .lhfield = stashcurexp () ;
      if ( internal [9 ]> 0 ) 
      {
	begindiagnostic () ;
	printarg ( mem [p ].hhfield .lhfield , n , mem [r ].hhfield 
	.lhfield ) ;
	enddiagnostic ( false ) ;
      } 
      if ( arglist == 0 ) 
      arglist = p ;
      else mem [tail ].hhfield .v.RH = p ;
      tail = p ;
      incr ( n ) ;
    } 
  } 
  r = mem [r ].hhfield .v.RH ;
  while ( ( curinput .indexfield > 15 ) && ( curinput .locfield == 0 ) ) 
  endtokenlist () ;
  if ( paramptr + n > maxparamstack ) 
  {
    maxparamstack = paramptr + n ;
    if ( maxparamstack > 150 ) 
    overflow ( 687 , 150 ) ;
  } 
  begintokenlist ( defref , 21 ) ;
  curinput .namefield = macroname ;
  curinput .locfield = r ;
  if ( n > 0 ) 
  {
    p = arglist ;
    do {
	paramstack [paramptr ]= mem [p ].hhfield .lhfield ;
      incr ( paramptr ) ;
      p = mem [p ].hhfield .v.RH ;
    } while ( ! ( p == 0 ) ) ;
    flushlist ( arglist ) ;
  } 
} 
void 
expand ( void ) 
{
  halfword p  ;
  integer k  ;
  poolpointer j  ;
  if ( internal [7 ]> 65536L ) {
      
    if ( curcmd != 10 ) 
    showcmdmod ( curcmd , curmod ) ;
  } 
  switch ( curcmd ) 
  {case 1 : 
    conditional () ;
    break ;
  case 2 : 
    if ( curmod > iflimit ) {
	
      if ( iflimit == 1 ) 
      {
	missingerr ( 58 ) ;
	backinput () ;
	cursym = 9762 ;
	inserror () ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	  {
	    printnl ( 261 ) ;
	    print ( fullsourcefilenamestack [inopen ]) ;
	    print ( 58 ) ;
	    printint ( line ) ;
	    print ( 262 ) ;
	    print ( 724 ) ;
	  } 
	  else {
	      
	    printnl ( 263 ) ;
	    print ( 724 ) ;
	  } 
	} 
	printcmdmod ( 2 , curmod ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 725 ;
	} 
	error () ;
      } 
    } 
    else {
	
      while ( curmod != 2 ) passtext () ;
      {
	p = condptr ;
	ifline = mem [p + 1 ].cint ;
	curif = mem [p ].hhfield .b1 ;
	iflimit = mem [p ].hhfield .b0 ;
	condptr = mem [p ].hhfield .v.RH ;
	freenode ( p , 2 ) ;
      } 
    } 
    break ;
  case 3 : 
    if ( curmod > 0 ) 
    forceeof = true ;
    else startinput () ;
    break ;
  case 4 : 
    if ( curmod == 0 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 688 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 688 ) ;
	} 
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 689 ;
	helpline [0 ]= 690 ;
      } 
      error () ;
    } 
    else beginiteration () ;
    break ;
  case 5 : 
    {
      while ( ( curinput .indexfield > 15 ) && ( curinput .locfield == 0 ) ) 
      endtokenlist () ;
      if ( loopptr == 0 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	  {
	    printnl ( 261 ) ;
	    print ( fullsourcefilenamestack [inopen ]) ;
	    print ( 58 ) ;
	    printint ( line ) ;
	    print ( 262 ) ;
	    print ( 692 ) ;
	  } 
	  else {
	      
	    printnl ( 263 ) ;
	    print ( 692 ) ;
	  } 
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 693 ;
	  helpline [0 ]= 694 ;
	} 
	error () ;
      } 
      else resumeiteration () ;
    } 
    break ;
  case 6 : 
    {
      getboolean () ;
      if ( internal [7 ]> 65536L ) 
      showcmdmod ( 33 , curexp ) ;
      if ( curexp == 30 ) {
	  
	if ( loopptr == 0 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	    {
	      printnl ( 261 ) ;
	      print ( fullsourcefilenamestack [inopen ]) ;
	      print ( 58 ) ;
	      printint ( line ) ;
	      print ( 262 ) ;
	      print ( 695 ) ;
	    } 
	    else {
		
	      printnl ( 263 ) ;
	      print ( 695 ) ;
	    } 
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 696 ;
	  } 
	  if ( curcmd == 83 ) 
	  error () ;
	  else backerror () ;
	} 
	else {
	    
	  p = 0 ;
	  do {
	      if ( ( curinput .indexfield <= 15 ) ) 
	    endfilereading () ;
	    else {
		
	      if ( curinput .indexfield <= 17 ) 
	      p = curinput .startfield ;
	      endtokenlist () ;
	    } 
	  } while ( ! ( p != 0 ) ) ;
	  if ( p != mem [loopptr ].hhfield .lhfield ) 
	  fatalerror ( 699 ) ;
	  stopiteration () ;
	} 
      } 
      else if ( curcmd != 83 ) 
      {
	missingerr ( 59 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 697 ;
	  helpline [0 ]= 698 ;
	} 
	backerror () ;
      } 
    } 
    break ;
  case 7 : 
    ;
    break ;
  case 9 : 
    {
      getnext () ;
      p = curtok () ;
      getnext () ;
      if ( curcmd < 11 ) 
      expand () ;
      else backinput () ;
      begintokenlist ( p , 19 ) ;
    } 
    break ;
  case 8 : 
    {
      getxnext () ;
      scanprimary () ;
      if ( curtype != 4 ) 
      {
	disperr ( 0 , 700 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 701 ;
	  helpline [0 ]= 702 ;
	} 
	putgetflusherror ( 0 ) ;
      } 
      else {
	  
	backinput () ;
	if ( ( strstart [curexp + 1 ]- strstart [curexp ]) > 0 ) 
	{
	  beginfilereading () ;
	  curinput .namefield = 2 ;
	  k = first + ( strstart [curexp + 1 ]- strstart [curexp ]) ;
	  if ( k >= maxbufstack ) 
	  {
	    if ( k >= bufsize ) 
	    {
	      maxbufstack = bufsize ;
	      overflow ( 256 , bufsize ) ;
	    } 
	    maxbufstack = k + 1 ;
	  } 
	  j = strstart [curexp ];
	  curinput .limitfield = k ;
	  while ( first < curinput .limitfield ) {
	      
	    buffer [first ]= strpool [j ];
	    incr ( j ) ;
	    incr ( first ) ;
	  } 
	  buffer [curinput .limitfield ]= 37 ;
	  first = curinput .limitfield + 1 ;
	  curinput .locfield = curinput .startfield ;
	  flushcurexp ( 0 ) ;
	} 
      } 
    } 
    break ;
  case 10 : 
    macrocall ( curmod , 0 , cursym ) ;
    break ;
  } 
} 
void 
getxnext ( void ) 
{
  halfword saveexp  ;
  getnext () ;
  if ( curcmd < 11 ) 
  {
    saveexp = stashcurexp () ;
    do {
	if ( curcmd == 10 ) 
      macrocall ( curmod , 0 , cursym ) ;
      else expand () ;
      getnext () ;
    } while ( ! ( curcmd >= 11 ) ) ;
    unstashcurexp ( saveexp ) ;
  } 
} 
void 
zstackargument ( halfword p ) 
{
  if ( paramptr == maxparamstack ) 
  {
    incr ( maxparamstack ) ;
    if ( maxparamstack > 150 ) 
    overflow ( 687 , 150 ) ;
  } 
  paramstack [paramptr ]= p ;
  incr ( paramptr ) ;
} 
void 
passtext ( void ) 
{
  /* 30 */ integer l  ;
  scannerstatus = 1 ;
  l = 0 ;
  warninginfo = line ;
  while ( true ) {
      
    getnext () ;
    if ( curcmd <= 2 ) {
	
      if ( curcmd < 2 ) 
      incr ( l ) ;
      else {
	  
	if ( l == 0 ) 
	goto lab30 ;
	if ( curmod == 2 ) 
	decr ( l ) ;
      } 
    } 
    else if ( curcmd == 39 ) 
    {
      if ( strref [curmod ]< 127 ) {
	  
	if ( strref [curmod ]> 1 ) 
	decr ( strref [curmod ]) ;
	else flushstring ( curmod ) ;
      } 
    } 
  } 
  lab30: scannerstatus = 0 ;
} 
void 
zchangeiflimit ( smallnumber l , halfword p ) 
{
  /* 10 */ halfword q  ;
  if ( p == condptr ) 
  iflimit = l ;
  else {
      
    q = condptr ;
    while ( true ) {
	
      if ( q == 0 ) 
      confusion ( 718 ) ;
      if ( mem [q ].hhfield .v.RH == p ) 
      {
	mem [q ].hhfield .b0 = l ;
	goto lab10 ;
      } 
      q = mem [q ].hhfield .v.RH ;
    } 
  } 
  lab10: ;
} 
void 
checkcolon ( void ) 
{
  if ( curcmd != 81 ) 
  {
    missingerr ( 58 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 721 ;
      helpline [0 ]= 698 ;
    } 
    backerror () ;
  } 
} 
void 
conditional ( void ) 
{
  /* 10 30 21 40 */ halfword savecondptr  ;
  unsigned char newiflimit  ;
  halfword p  ;
  {
    p = getnode ( 2 ) ;
    mem [p ].hhfield .v.RH = condptr ;
    mem [p ].hhfield .b0 = iflimit ;
    mem [p ].hhfield .b1 = curif ;
    mem [p + 1 ].cint = ifline ;
    condptr = p ;
    iflimit = 1 ;
    ifline = line ;
    curif = 1 ;
  } 
  savecondptr = condptr ;
  lab21: getboolean () ;
  newiflimit = 4 ;
  if ( internal [7 ]> 65536L ) 
  {
    begindiagnostic () ;
    if ( curexp == 30 ) 
    print ( 722 ) ;
    else print ( 723 ) ;
    enddiagnostic ( false ) ;
  } 
  lab40: checkcolon () ;
  if ( curexp == 30 ) 
  {
    changeiflimit ( newiflimit , savecondptr ) ;
    goto lab10 ;
  } 
  while ( true ) {
      
    passtext () ;
    if ( condptr == savecondptr ) 
    goto lab30 ;
    else if ( curmod == 2 ) 
    {
      p = condptr ;
      ifline = mem [p + 1 ].cint ;
      curif = mem [p ].hhfield .b1 ;
      iflimit = mem [p ].hhfield .b0 ;
      condptr = mem [p ].hhfield .v.RH ;
      freenode ( p , 2 ) ;
    } 
  } 
  lab30: curif = curmod ;
  ifline = line ;
  if ( curmod == 2 ) 
  {
    p = condptr ;
    ifline = mem [p + 1 ].cint ;
    curif = mem [p ].hhfield .b1 ;
    iflimit = mem [p ].hhfield .b0 ;
    condptr = mem [p ].hhfield .v.RH ;
    freenode ( p , 2 ) ;
  } 
  else if ( curmod == 4 ) 
  goto lab21 ;
  else {
      
    curexp = 30 ;
    newiflimit = 2 ;
    getxnext () ;
    goto lab40 ;
  } 
  lab10: ;
} 
void 
zbadfor ( strnumber s ) 
{
  disperr ( 0 , 726 ) ;
  print ( s ) ;
  print ( 306 ) ;
  {
    helpptr = 4 ;
    helpline [3 ]= 727 ;
    helpline [2 ]= 728 ;
    helpline [1 ]= 729 ;
    helpline [0 ]= 308 ;
  } 
  putgetflusherror ( 0 ) ;
} 
void 
beginiteration ( void ) 
{
  /* 22 30 40 */ halfword m  ;
  halfword n  ;
  halfword p, q, s, pp  ;
  m = curmod ;
  n = cursym ;
  s = getnode ( 2 ) ;
  if ( m == 1 ) 
  {
    mem [s + 1 ].hhfield .lhfield = 1 ;
    p = 0 ;
    getxnext () ;
    goto lab40 ;
  } 
  getsymbol () ;
  p = getnode ( 2 ) ;
  mem [p ].hhfield .lhfield = cursym ;
  mem [p + 1 ].cint = m ;
  getxnext () ;
  if ( ( curcmd != 51 ) && ( curcmd != 77 ) ) 
  {
    missingerr ( 61 ) ;
    {
      helpptr = 3 ;
      helpline [2 ]= 730 ;
      helpline [1 ]= 673 ;
      helpline [0 ]= 731 ;
    } 
    backerror () ;
  } 
  mem [s + 1 ].hhfield .lhfield = 0 ;
  q = s + 1 ;
  mem [q ].hhfield .v.RH = 0 ;
  do {
      getxnext () ;
    if ( m != 9770 ) 
    scansuffix () ;
    else {
	
      if ( curcmd >= 81 ) {
	  
	if ( curcmd <= 82 ) 
	goto lab22 ;
      } 
      scanexpression () ;
      if ( curcmd == 74 ) {
	  
	if ( q == s + 1 ) 
	{
	  if ( curtype != 16 ) 
	  badfor ( 737 ) ;
	  pp = getnode ( 4 ) ;
	  mem [pp + 1 ].cint = curexp ;
	  getxnext () ;
	  scanexpression () ;
	  if ( curtype != 16 ) 
	  badfor ( 738 ) ;
	  mem [pp + 2 ].cint = curexp ;
	  if ( curcmd != 75 ) 
	  {
	    missingerr ( 490 ) ;
	    {
	      helpptr = 2 ;
	      helpline [1 ]= 739 ;
	      helpline [0 ]= 740 ;
	    } 
	    backerror () ;
	  } 
	  getxnext () ;
	  scanexpression () ;
	  if ( curtype != 16 ) 
	  badfor ( 741 ) ;
	  mem [pp + 3 ].cint = curexp ;
	  mem [s + 1 ].hhfield .lhfield = pp ;
	  goto lab30 ;
	} 
      } 
      curexp = stashcurexp () ;
    } 
    mem [q ].hhfield .v.RH = getavail () ;
    q = mem [q ].hhfield .v.RH ;
    mem [q ].hhfield .lhfield = curexp ;
    curtype = 1 ;
    lab22: ;
  } while ( ! ( curcmd != 82 ) ) ;
  lab30: ;
  lab40: if ( curcmd != 81 ) 
  {
    missingerr ( 58 ) ;
    {
      helpptr = 3 ;
      helpline [2 ]= 732 ;
      helpline [1 ]= 733 ;
      helpline [0 ]= 734 ;
    } 
    backerror () ;
  } 
  q = getavail () ;
  mem [q ].hhfield .lhfield = 9758 ;
  scannerstatus = 6 ;
  warninginfo = n ;
  mem [s ].hhfield .lhfield = scantoks ( 4 , p , q , 0 ) ;
  scannerstatus = 0 ;
  mem [s ].hhfield .v.RH = loopptr ;
  loopptr = s ;
  resumeiteration () ;
} 
void 
resumeiteration ( void ) 
{
  /* 45 10 */ halfword p, q  ;
  p = mem [loopptr + 1 ].hhfield .lhfield ;
  if ( p > 1 ) 
  {
    curexp = mem [p + 1 ].cint ;
    if ( ( ( mem [p + 2 ].cint > 0 ) && ( curexp > mem [p + 3 ].cint ) ) 
    || ( ( mem [p + 2 ].cint < 0 ) && ( curexp < mem [p + 3 ].cint ) ) ) 
    goto lab45 ;
    curtype = 16 ;
    q = stashcurexp () ;
    mem [p + 1 ].cint = curexp + mem [p + 2 ].cint ;
  } 
  else if ( p < 1 ) 
  {
    p = mem [loopptr + 1 ].hhfield .v.RH ;
    if ( p == 0 ) 
    goto lab45 ;
    mem [loopptr + 1 ].hhfield .v.RH = mem [p ].hhfield .v.RH ;
    q = mem [p ].hhfield .lhfield ;
    {
      mem [p ].hhfield .v.RH = avail ;
      avail = p ;
	;
#ifdef STAT
      decr ( dynused ) ;
#endif /* STAT */
    } 
  } 
  else {
      
    begintokenlist ( mem [loopptr ].hhfield .lhfield , 16 ) ;
    goto lab10 ;
  } 
  begintokenlist ( mem [loopptr ].hhfield .lhfield , 17 ) ;
  stackargument ( q ) ;
  if ( internal [7 ]> 65536L ) 
  {
    begindiagnostic () ;
    printnl ( 736 ) ;
    if ( ( q != 0 ) && ( mem [q ].hhfield .v.RH == 1 ) ) 
    printexp ( q , 1 ) ;
    else showtokenlist ( q , 0 , 50 , 0 ) ;
    printchar ( 125 ) ;
    enddiagnostic ( false ) ;
  } 
  goto lab10 ;
  lab45: stopiteration () ;
  lab10: ;
} 
void 
stopiteration ( void ) 
{
  halfword p, q  ;
  p = mem [loopptr + 1 ].hhfield .lhfield ;
  if ( p > 1 ) 
  freenode ( p , 4 ) ;
  else if ( p < 1 ) 
  {
    q = mem [loopptr + 1 ].hhfield .v.RH ;
    while ( q != 0 ) {
	
      p = mem [q ].hhfield .lhfield ;
      if ( p != 0 ) {
	  
	if ( mem [p ].hhfield .v.RH == 1 ) 
	{
	  recyclevalue ( p ) ;
	  freenode ( p , 2 ) ;
	} 
	else flushtokenlist ( p ) ;
      } 
      p = q ;
      q = mem [q ].hhfield .v.RH ;
      {
	mem [p ].hhfield .v.RH = avail ;
	avail = p ;
	;
#ifdef STAT
	decr ( dynused ) ;
#endif /* STAT */
      } 
    } 
  } 
  p = loopptr ;
  loopptr = mem [p ].hhfield .v.RH ;
  flushtokenlist ( mem [p ].hhfield .lhfield ) ;
  freenode ( p , 2 ) ;
} 
void 
beginname ( void ) 
{
  areadelimiter = 0 ;
  extdelimiter = 0 ;
  quotedfilename = false ;
} 
boolean 
zmorename ( ASCIIcode c ) 
{
  register boolean Result; if ( c == 34 ) 
  {
    quotedfilename = ! quotedfilename ;
    Result = true ;
  } 
  else if ( ( ( c == 32 ) || ( c == 9 ) ) && stopatspace && ( ! quotedfilename 
  ) ) 
  Result = false ;
  else {
      
    if ( ISDIRSEP ( c ) ) 
    {
      areadelimiter = poolptr ;
      extdelimiter = 0 ;
    } 
    else if ( c == 46 ) 
    extdelimiter = poolptr ;
    {
      if ( poolptr + 1 > maxpoolptr ) 
      {
	if ( poolptr + 1 > poolsize ) 
	overflow ( 257 , poolsize - initpoolptr ) ;
	maxpoolptr = poolptr + 1 ;
      } 
    } 
    {
      strpool [poolptr ]= c ;
      incr ( poolptr ) ;
    } 
    Result = true ;
  } 
  return Result ;
} 
void 
endname ( void ) 
{
  boolean mustquote  ;
  poolpointer j, s, t  ;
  if ( strptr + 3 > maxstrptr ) 
  {
    if ( strptr + 3 > maxstrings ) 
    overflow ( 258 , maxstrings - initstrptr ) ;
    maxstrptr = strptr + 3 ;
  } 
  {
    if ( poolptr + 6 > maxpoolptr ) 
    {
      if ( poolptr + 6 > poolsize ) 
      overflow ( 257 , poolsize - initpoolptr ) ;
      maxpoolptr = poolptr + 6 ;
    } 
  } 
  if ( areadelimiter == 0 ) 
  curarea = 261 ;
  else {
      
    mustquote = false ;
    s = strstart [strptr ];
    t = areadelimiter + 1 ;
    j = s ;
    while ( ( ! mustquote ) && ( j < t ) ) {
	
      mustquote = strpool [j ]== 32 ;
      incr ( j ) ;
    } 
    if ( mustquote ) 
    {
      {register integer for_end; j = poolptr - 1 ;for_end = t ; if ( j >= 
      for_end) do 
	strpool [j + 2 ]= strpool [j ];
      while ( j-- > for_end ) ;} 
      strpool [t + 1 ]= 34 ;
      {register integer for_end; j = t - 1 ;for_end = s ; if ( j >= for_end) 
      do 
	strpool [j + 1 ]= strpool [j ];
      while ( j-- > for_end ) ;} 
      strpool [s ]= 34 ;
      poolptr = poolptr + 2 ;
      areadelimiter = areadelimiter + 2 ;
      if ( extdelimiter != 0 ) 
      extdelimiter = extdelimiter + 2 ;
    } 
    curarea = strptr ;
    incr ( strptr ) ;
    strstart [strptr ]= areadelimiter + 1 ;
  } 
  if ( extdelimiter == 0 ) 
  curext = 261 ;
  else {
      
    mustquote = false ;
    s = strstart [strptr ];
    t = extdelimiter ;
    j = s ;
    while ( ( ! mustquote ) && ( j < t ) ) {
	
      mustquote = strpool [j ]== 32 ;
      incr ( j ) ;
    } 
    if ( mustquote ) 
    {
      {register integer for_end; j = poolptr - 1 ;for_end = t ; if ( j >= 
      for_end) do 
	strpool [j + 2 ]= strpool [j ];
      while ( j-- > for_end ) ;} 
      strpool [t + 1 ]= 34 ;
      {register integer for_end; j = t - 1 ;for_end = s ; if ( j >= for_end) 
      do 
	strpool [j + 1 ]= strpool [j ];
      while ( j-- > for_end ) ;} 
      strpool [s ]= 34 ;
      poolptr = poolptr + 2 ;
      extdelimiter = extdelimiter + 2 ;
    } 
    curname = strptr ;
    incr ( strptr ) ;
    strstart [strptr ]= extdelimiter ;
  } 
  mustquote = false ;
  s = strstart [strptr ];
  t = poolptr ;
  j = s ;
  while ( ( ! mustquote ) && ( j < t ) ) {
      
    mustquote = strpool [j ]== 32 ;
    incr ( j ) ;
  } 
  if ( mustquote ) 
  {
    strpool [t + 1 ]= 34 ;
    {register integer for_end; j = t - 1 ;for_end = s ; if ( j >= for_end) 
    do 
      strpool [j + 1 ]= strpool [j ];
    while ( j-- > for_end ) ;} 
    strpool [s ]= 34 ;
    poolptr = poolptr + 2 ;
  } 
  if ( extdelimiter == 0 ) 
  curname = makestring () ;
  else curext = makestring () ;
} 
void 
zpackfilename ( strnumber n , strnumber a , strnumber e ) 
{
  integer k  ;
  ASCIIcode c  ;
  poolpointer j  ;
  k = 0 ;
  if ( nameoffile ) 
  libcfree ( nameoffile ) ;
  nameoffile = xmallocarray ( ASCIIcode , ( strstart [a + 1 ]- strstart [a 
  ]) + ( strstart [n + 1 ]- strstart [n ]) + ( strstart [e + 1 ]- 
  strstart [e ]) + 1 ) ;
  {register integer for_end; j = strstart [a ];for_end = strstart [a + 1 
  ]- 1 ; if ( j <= for_end) do 
    {
      c = strpool [j ];
      if ( ! ( c == 34 ) ) 
      {
	incr ( k ) ;
	if ( k <= maxint ) 
	nameoffile [k ]= xchr [c ];
      } 
    } 
  while ( j++ < for_end ) ;} 
  {register integer for_end; j = strstart [n ];for_end = strstart [n + 1 
  ]- 1 ; if ( j <= for_end) do 
    {
      c = strpool [j ];
      if ( ! ( c == 34 ) ) 
      {
	incr ( k ) ;
	if ( k <= maxint ) 
	nameoffile [k ]= xchr [c ];
      } 
    } 
  while ( j++ < for_end ) ;} 
  {register integer for_end; j = strstart [e ];for_end = strstart [e + 1 
  ]- 1 ; if ( j <= for_end) do 
    {
      c = strpool [j ];
      if ( ! ( c == 34 ) ) 
      {
	incr ( k ) ;
	if ( k <= maxint ) 
	nameoffile [k ]= xchr [c ];
      } 
    } 
  while ( j++ < for_end ) ;} 
  if ( k <= maxint ) 
  namelength = k ;
  else namelength = maxint ;
  nameoffile [namelength + 1 ]= 0 ;
} 
void 
zpackbufferedname ( smallnumber n , integer a , integer b ) 
{
  integer k  ;
  ASCIIcode c  ;
  integer j  ;
  if ( n + b - a + 6 > maxint ) 
  b = a + maxint - n - 6 ;
  k = 0 ;
  if ( nameoffile ) 
  libcfree ( nameoffile ) ;
  nameoffile = xmallocarray ( ASCIIcode , n + ( b - a + 1 ) + 6 ) ;
  {register integer for_end; j = 1 ;for_end = n ; if ( j <= for_end) do 
    {
      c = xord [ucharcast ( MFbasedefault [j ]) ];
      if ( ! ( c == 34 ) ) 
      {
	incr ( k ) ;
	if ( k <= maxint ) 
	nameoffile [k ]= xchr [c ];
      } 
    } 
  while ( j++ < for_end ) ;} 
  {register integer for_end; j = a ;for_end = b ; if ( j <= for_end) do 
    {
      c = buffer [j ];
      if ( ! ( c == 34 ) ) 
      {
	incr ( k ) ;
	if ( k <= maxint ) 
	nameoffile [k ]= xchr [c ];
      } 
    } 
  while ( j++ < for_end ) ;} 
  {register integer for_end; j = basedefaultlength - 4 ;for_end = 
  basedefaultlength ; if ( j <= for_end) do 
    {
      c = xord [ucharcast ( MFbasedefault [j ]) ];
      if ( ! ( c == 34 ) ) 
      {
	incr ( k ) ;
	if ( k <= maxint ) 
	nameoffile [k ]= xchr [c ];
      } 
    } 
  while ( j++ < for_end ) ;} 
  if ( k <= maxint ) 
  namelength = k ;
  else namelength = maxint ;
  nameoffile [namelength + 1 ]= 0 ;
} 
strnumber 
makenamestring ( void ) 
{
  register strnumber Result; integer k  ;
  if ( ( poolptr + namelength > poolsize ) || ( strptr == maxstrings ) ) 
  Result = 63 ;
  else {
      
    {register integer for_end; k = 1 ;for_end = namelength ; if ( k <= 
    for_end) do 
      {
	strpool [poolptr ]= xord [nameoffile [k ]];
	incr ( poolptr ) ;
      } 
    while ( k++ < for_end ) ;} 
    Result = makestring () ;
  } 
  k = 1 ;
  beginname () ;
  stopatspace = false ;
  while ( ( k <= namelength ) && ( morename ( nameoffile [k ]) ) ) incr ( k 
  ) ;
  stopatspace = true ;
  endname () ;
  return Result ;
} 
strnumber 
zamakenamestring ( alphafile f ) 
{
  register strnumber Result; Result = makenamestring () ;
  return Result ;
} 
strnumber 
zbmakenamestring ( bytefile f ) 
{
  register strnumber Result; Result = makenamestring () ;
  return Result ;
} 
strnumber 
zwmakenamestring ( wordfile f ) 
{
  register strnumber Result; Result = makenamestring () ;
  return Result ;
} 
void 
scanfilename ( void ) 
{
  /* 30 */ beginname () ;
  while ( ( buffer [curinput .locfield ]== 32 ) || ( buffer [curinput 
  .locfield ]== 9 ) ) incr ( curinput .locfield ) ;
  while ( true ) {
      
    if ( ( buffer [curinput .locfield ]== 59 ) || ( buffer [curinput 
    .locfield ]== 37 ) ) 
    goto lab30 ;
    if ( ! morename ( buffer [curinput .locfield ]) ) 
    goto lab30 ;
    incr ( curinput .locfield ) ;
  } 
  lab30: endname () ;
} 
void 
zpackjobname ( strnumber s ) 
{
  curarea = 261 ;
  curext = s ;
  curname = jobname ;
  packfilename ( curname , curarea , curext ) ;
} 
void 
zpromptfilename ( strnumber s , strnumber e ) 
{
  /* 30 */ integer k  ;
  strnumber savedcurname  ;
  if ( interaction == 2 ) 
  ;
  if ( s == 743 ) 
  {
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( 744 ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( 744 ) ;
    } 
  } 
  else {
      
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( 745 ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( 745 ) ;
    } 
  } 
  printfilename ( curname , curarea , curext ) ;
  print ( 746 ) ;
  if ( e == 747 ) 
  showcontext () ;
  printnl ( 748 ) ;
  print ( s ) ;
  if ( interaction < 2 ) 
  fatalerror ( 749 ) ;
  savedcurname = curname ;
  {
    ;
    print ( 262 ) ;
    terminput () ;
  } 
  {
    beginname () ;
    k = first ;
    while ( ( ( buffer [k ]== 32 ) || ( buffer [k ]== 9 ) ) && ( k < last 
    ) ) incr ( k ) ;
    while ( true ) {
	
      if ( k == last ) 
      goto lab30 ;
      if ( ! morename ( buffer [k ]) ) 
      goto lab30 ;
      incr ( k ) ;
    } 
    lab30: endname () ;
  } 
  if ( curext == 261 ) 
  curext = e ;
  if ( ( strstart [curname + 1 ]- strstart [curname ]) == 0 ) 
  curname = savedcurname ;
  packfilename ( curname , curarea , curext ) ;
} 
void 
openlogfile ( void ) 
{
  unsigned char oldsetting  ;
  integer k  ;
  integer l  ;
  integer m  ;
  constcstring months  ;
  oldsetting = selector ;
  if ( jobname == 0 ) 
  jobname = getjobname ( 750 ) ;
  packjobname ( 751 ) ;
  recorderchangefilename ( stringcast ( nameoffile + 1 ) ) ;
  packjobname ( 752 ) ;
  while ( ! aopenout ( logfile ) ) {
      
    selector = 1 ;
    promptfilename ( 754 , 752 ) ;
  } 
  texmflogname = amakenamestring ( logfile ) ;
  selector = 2 ;
  logopened = true ;
  {
    Fputs ( logfile ,  "This is METAFONT, Version 2.7182818" ) ;
    Fputs ( logfile ,  versionstring ) ;
    slowprint ( baseident ) ;
    print ( 755 ) ;
    printint ( roundunscaled ( internal [16 ]) ) ;
    printchar ( 32 ) ;
    months = " JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC" ;
    m = roundunscaled ( internal [15 ]) ;
    {register integer for_end; k = 3 * m - 2 ;for_end = 3 * m ; if ( k <= 
    for_end) do 
      putc ( months [k ],  logfile );
    while ( k++ < for_end ) ;} 
    printchar ( 32 ) ;
    printint ( roundunscaled ( internal [14 ]) ) ;
    printchar ( 32 ) ;
    m = roundunscaled ( internal [17 ]) ;
    printdd ( m / 60 ) ;
    printchar ( 58 ) ;
    printdd ( m % 60 ) ;
    if ( translatefilename ) 
    {
      putc ('\n',  logfile );
      putc ( '(' ,  logfile );
      fputs ( translatefilename , logfile ) ;
      putc ( ')' ,  logfile );
    } 
  } 
  inputstack [inputptr ]= curinput ;
  printnl ( 753 ) ;
  l = inputstack [0 ].limitfield - 1 ;
  {register integer for_end; k = 1 ;for_end = l ; if ( k <= for_end) do 
    print ( buffer [k ]) ;
  while ( k++ < for_end ) ;} 
  println () ;
  selector = oldsetting + 2 ;
} 
void 
startinput ( void ) 
{
  /* 30 */ while ( ( curinput .indexfield > 15 ) && ( curinput .locfield == 
  0 ) ) endtokenlist () ;
  if ( ( curinput .indexfield > 15 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 757 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 757 ) ;
      } 
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 758 ;
      helpline [1 ]= 759 ;
      helpline [0 ]= 760 ;
    } 
    error () ;
  } 
  if ( ( curinput .indexfield <= 15 ) ) 
  scanfilename () ;
  else {
      
    curname = 261 ;
    curext = 261 ;
    curarea = 261 ;
  } 
  packfilename ( curname , curarea , curext ) ;
  while ( true ) {
      
    beginfilereading () ;
    if ( curext == 747 ) 
    {
      curext = 261 ;
      packfilename ( curname , curarea , curext ) ;
    } 
    if ( kpseinnameok ( stringcast ( nameoffile + 1 ) ) && aopenin ( inputfile 
    [curinput .indexfield ], kpsemfformat ) ) 
    goto lab30 ;
    endfilereading () ;
    promptfilename ( 743 , 747 ) ;
  } 
  lab30: curinput .namefield = amakenamestring ( inputfile [curinput 
  .indexfield ]) ;
  strref [curname ]= 127 ;
  if ( jobname == 0 ) 
  {
    jobname = getjobname ( curname ) ;
    openlogfile () ;
  } 
  if ( termoffset + ( strstart [curinput .namefield + 1 ]- strstart [
  curinput .namefield ]) > maxprintline - 2 ) 
  println () ;
  else if ( ( termoffset > 0 ) || ( fileoffset > 0 ) ) 
  printchar ( 32 ) ;
  printchar ( 40 ) ;
  incr ( openparens ) ;
  slowprint ( curinput .namefield ) ;
  fflush ( stdout ) ;
  {
    line = 1 ;
    if ( inputln ( inputfile [curinput .indexfield ], false ) ) 
    ;
    firmuptheline () ;
    buffer [curinput .limitfield ]= 37 ;
    first = curinput .limitfield + 1 ;
    curinput .locfield = curinput .startfield ;
  } 
} 
void 
zbadexp ( strnumber s ) 
{
  unsigned char saveflag  ;
  {
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( s ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( s ) ;
    } 
  } 
  print ( 770 ) ;
  printcmdmod ( curcmd , curmod ) ;
  printchar ( 39 ) ;
  {
    helpptr = 4 ;
    helpline [3 ]= 771 ;
    helpline [2 ]= 772 ;
    helpline [1 ]= 773 ;
    helpline [0 ]= 774 ;
  } 
  backinput () ;
  cursym = 0 ;
  curcmd = 42 ;
  curmod = 0 ;
  inserror () ;
  saveflag = varflag ;
  varflag = 0 ;
  getxnext () ;
  varflag = saveflag ;
} 
void 
zstashin ( halfword p ) 
{
  halfword q  ;
  mem [p ].hhfield .b0 = curtype ;
  if ( curtype == 16 ) 
  mem [p + 1 ].cint = curexp ;
  else {
      
    if ( curtype == 19 ) 
    {
      q = singledependency ( curexp ) ;
      if ( q == depfinal ) 
      {
	mem [p ].hhfield .b0 = 16 ;
	mem [p + 1 ].cint = 0 ;
	freenode ( q , 2 ) ;
      } 
      else {
	  
	mem [p ].hhfield .b0 = 17 ;
	newdep ( p , q ) ;
      } 
      recyclevalue ( curexp ) ;
    } 
    else {
	
      mem [p + 1 ]= mem [curexp + 1 ];
      mem [mem [p + 1 ].hhfield .lhfield ].hhfield .v.RH = p ;
    } 
    freenode ( curexp , 2 ) ;
  } 
  curtype = 1 ;
} 
void 
backexpr ( void ) 
{
  halfword p  ;
  p = stashcurexp () ;
  mem [p ].hhfield .v.RH = 0 ;
  begintokenlist ( p , 19 ) ;
} 
void 
badsubscript ( void ) 
{
  disperr ( 0 , 786 ) ;
  {
    helpptr = 3 ;
    helpline [2 ]= 787 ;
    helpline [1 ]= 788 ;
    helpline [0 ]= 789 ;
  } 
  flusherror ( 0 ) ;
} 
void 
zobliterated ( halfword q ) 
{
  {
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( 790 ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( 790 ) ;
    } 
  } 
  showtokenlist ( q , 0 , 1000 , 0 ) ;
  print ( 791 ) ;
  {
    helpptr = 5 ;
    helpline [4 ]= 792 ;
    helpline [3 ]= 793 ;
    helpline [2 ]= 794 ;
    helpline [1 ]= 795 ;
    helpline [0 ]= 796 ;
  } 
} 
void 
zbinarymac ( halfword p , halfword c , halfword n ) 
{
  halfword q, r  ;
  q = getavail () ;
  r = getavail () ;
  mem [q ].hhfield .v.RH = r ;
  mem [q ].hhfield .lhfield = p ;
  mem [r ].hhfield .lhfield = stashcurexp () ;
  macrocall ( c , q , n ) ;
} 
void 
materializepen ( void ) 
{
  /* 50 */ scaled aminusb, aplusb, majoraxis, minoraxis  ;
  angle theta  ;
  halfword p  ;
  halfword q  ;
  q = curexp ;
  if ( mem [q ].hhfield .b0 == 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 806 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 806 ) ;
      } 
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 807 ;
      helpline [0 ]= 575 ;
    } 
    putgeterror () ;
    curexp = 3 ;
    goto lab50 ;
  } 
  else if ( mem [q ].hhfield .b0 == 4 ) 
  {
    tx = mem [q + 1 ].cint ;
    ty = mem [q + 2 ].cint ;
    txx = mem [q + 3 ].cint - tx ;
    tyx = mem [q + 4 ].cint - ty ;
    txy = mem [q + 5 ].cint - tx ;
    tyy = mem [q + 6 ].cint - ty ;
    aminusb = pythadd ( txx - tyy , tyx + txy ) ;
    aplusb = pythadd ( txx + tyy , tyx - txy ) ;
    majoraxis = halfp ( aminusb + aplusb ) ;
    minoraxis = halfp ( abs ( aplusb - aminusb ) ) ;
    if ( majoraxis == minoraxis ) 
    theta = 0 ;
    else theta = half ( narg ( txx - tyy , tyx + txy ) + narg ( txx + tyy , 
    tyx - txy ) ) ;
    freenode ( q , 7 ) ;
    q = makeellipse ( majoraxis , minoraxis , theta ) ;
    if ( ( tx != 0 ) || ( ty != 0 ) ) 
    {
      p = q ;
      do {
	  mem [p + 1 ].cint = mem [p + 1 ].cint + tx ;
	mem [p + 2 ].cint = mem [p + 2 ].cint + ty ;
	p = mem [p ].hhfield .v.RH ;
      } while ( ! ( p == q ) ) ;
    } 
  } 
  curexp = makepen ( q ) ;
  lab50: tossknotlist ( q ) ;
  curtype = 6 ;
} 
void 
knownpair ( void ) 
{
  halfword p  ;
  if ( curtype != 14 ) 
  {
    disperr ( 0 , 809 ) ;
    {
      helpptr = 5 ;
      helpline [4 ]= 810 ;
      helpline [3 ]= 811 ;
      helpline [2 ]= 812 ;
      helpline [1 ]= 813 ;
      helpline [0 ]= 814 ;
    } 
    putgetflusherror ( 0 ) ;
    curx = 0 ;
    cury = 0 ;
  } 
  else {
      
    p = mem [curexp + 1 ].cint ;
    if ( mem [p ].hhfield .b0 == 16 ) 
    curx = mem [p + 1 ].cint ;
    else {
	
      disperr ( p , 815 ) ;
      {
	helpptr = 5 ;
	helpline [4 ]= 816 ;
	helpline [3 ]= 811 ;
	helpline [2 ]= 812 ;
	helpline [1 ]= 813 ;
	helpline [0 ]= 814 ;
      } 
      putgeterror () ;
      recyclevalue ( p ) ;
      curx = 0 ;
    } 
    if ( mem [p + 2 ].hhfield .b0 == 16 ) 
    cury = mem [p + 3 ].cint ;
    else {
	
      disperr ( p + 2 , 817 ) ;
      {
	helpptr = 5 ;
	helpline [4 ]= 818 ;
	helpline [3 ]= 811 ;
	helpline [2 ]= 812 ;
	helpline [1 ]= 813 ;
	helpline [0 ]= 814 ;
      } 
      putgeterror () ;
      recyclevalue ( p + 2 ) ;
      cury = 0 ;
    } 
    flushcurexp ( 0 ) ;
  } 
} 
halfword 
newknot ( void ) 
{
  register halfword Result; halfword q  ;
  q = getnode ( 7 ) ;
  mem [q ].hhfield .b0 = 0 ;
  mem [q ].hhfield .b1 = 0 ;
  mem [q ].hhfield .v.RH = q ;
  knownpair () ;
  mem [q + 1 ].cint = curx ;
  mem [q + 2 ].cint = cury ;
  Result = q ;
  return Result ;
} 
smallnumber 
scandirection ( void ) 
{
  register smallnumber Result; unsigned char t  ;
  scaled x  ;
  getxnext () ;
  if ( curcmd == 60 ) 
  {
    getxnext () ;
    scanexpression () ;
    if ( ( curtype != 16 ) || ( curexp < 0 ) ) 
    {
      disperr ( 0 , 821 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 822 ;
      } 
      putgetflusherror ( 65536L ) ;
    } 
    t = 3 ;
  } 
  else {
      
    scanexpression () ;
    if ( curtype > 14 ) 
    {
      if ( curtype != 16 ) 
      {
	disperr ( 0 , 815 ) ;
	{
	  helpptr = 5 ;
	  helpline [4 ]= 816 ;
	  helpline [3 ]= 811 ;
	  helpline [2 ]= 812 ;
	  helpline [1 ]= 813 ;
	  helpline [0 ]= 814 ;
	} 
	putgetflusherror ( 0 ) ;
      } 
      x = curexp ;
      if ( curcmd != 82 ) 
      {
	missingerr ( 44 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 823 ;
	  helpline [0 ]= 824 ;
	} 
	backerror () ;
      } 
      getxnext () ;
      scanexpression () ;
      if ( curtype != 16 ) 
      {
	disperr ( 0 , 817 ) ;
	{
	  helpptr = 5 ;
	  helpline [4 ]= 818 ;
	  helpline [3 ]= 811 ;
	  helpline [2 ]= 812 ;
	  helpline [1 ]= 813 ;
	  helpline [0 ]= 814 ;
	} 
	putgetflusherror ( 0 ) ;
      } 
      cury = curexp ;
      curx = x ;
    } 
    else knownpair () ;
    if ( ( curx == 0 ) && ( cury == 0 ) ) 
    t = 4 ;
    else {
	
      t = 2 ;
      curexp = narg ( curx , cury ) ;
    } 
  } 
  if ( curcmd != 65 ) 
  {
    missingerr ( 125 ) ;
    {
      helpptr = 3 ;
      helpline [2 ]= 819 ;
      helpline [1 ]= 820 ;
      helpline [0 ]= 698 ;
    } 
    backerror () ;
  } 
  getxnext () ;
  Result = t ;
  return Result ;
} 
void 
zdonullary ( quarterword c ) 
{
  integer k  ;
  {
    if ( aritherror ) 
    cleararith () ;
  } 
  if ( internal [7 ]> 131072L ) 
  showcmdmod ( 33 , c ) ;
  switch ( c ) 
  {case 30 : 
  case 31 : 
    {
      curtype = 2 ;
      curexp = c ;
    } 
    break ;
  case 32 : 
    {
      curtype = 11 ;
      curexp = getnode ( 6 ) ;
      initedges ( curexp ) ;
    } 
    break ;
  case 33 : 
    {
      curtype = 6 ;
      curexp = 3 ;
    } 
    break ;
  case 37 : 
    {
      curtype = 16 ;
      curexp = normrand () ;
    } 
    break ;
  case 36 : 
    {
      curtype = 8 ;
      curexp = getnode ( 7 ) ;
      mem [curexp ].hhfield .b0 = 4 ;
      mem [curexp ].hhfield .b1 = 4 ;
      mem [curexp ].hhfield .v.RH = curexp ;
      mem [curexp + 1 ].cint = 0 ;
      mem [curexp + 2 ].cint = 0 ;
      mem [curexp + 3 ].cint = 65536L ;
      mem [curexp + 4 ].cint = 0 ;
      mem [curexp + 5 ].cint = 0 ;
      mem [curexp + 6 ].cint = 65536L ;
    } 
    break ;
  case 34 : 
    {
      if ( jobname == 0 ) 
      openlogfile () ;
      curtype = 4 ;
      curexp = jobname ;
    } 
    break ;
  case 35 : 
    {
      if ( interaction <= 1 ) 
      fatalerror ( 835 ) ;
      beginfilereading () ;
      curinput .namefield = 1 ;
      {
	;
	print ( 261 ) ;
	terminput () ;
      } 
      {
	if ( poolptr + last - curinput .startfield > maxpoolptr ) 
	{
	  if ( poolptr + last - curinput .startfield > poolsize ) 
	  overflow ( 257 , poolsize - initpoolptr ) ;
	  maxpoolptr = poolptr + last - curinput .startfield ;
	} 
      } 
      {register integer for_end; k = curinput .startfield ;for_end = last - 
      1 ; if ( k <= for_end) do 
	{
	  strpool [poolptr ]= buffer [k ];
	  incr ( poolptr ) ;
	} 
      while ( k++ < for_end ) ;} 
      endfilereading () ;
      curtype = 4 ;
      curexp = makestring () ;
    } 
    break ;
  } 
  {
    if ( aritherror ) 
    cleararith () ;
  } 
} 
boolean 
znicepair ( integer p , quarterword t ) 
{
  /* 10 */ register boolean Result; if ( t == 14 ) 
  {
    p = mem [p + 1 ].cint ;
    if ( mem [p ].hhfield .b0 == 16 ) {
	
      if ( mem [p + 2 ].hhfield .b0 == 16 ) 
      {
	Result = true ;
	goto lab10 ;
      } 
    } 
  } 
  Result = false ;
  lab10: ;
  return Result ;
} 
void 
zprintknownorunknowntype ( smallnumber t , integer v ) 
{
  printchar ( 40 ) ;
  if ( t < 17 ) {
      
    if ( t != 14 ) 
    printtype ( t ) ;
    else if ( nicepair ( v , 14 ) ) 
    print ( 336 ) ;
    else print ( 836 ) ;
  } 
  else print ( 837 ) ;
  printchar ( 41 ) ;
} 
void 
zbadunary ( quarterword c ) 
{
  disperr ( 0 , 838 ) ;
  printop ( c ) ;
  printknownorunknowntype ( curtype , curexp ) ;
  {
    helpptr = 3 ;
    helpline [2 ]= 839 ;
    helpline [1 ]= 840 ;
    helpline [0 ]= 841 ;
  } 
  putgeterror () ;
} 
void 
znegatedeplist ( halfword p ) 
{
  /* 10 */ while ( true ) {
      
    mem [p + 1 ].cint = - (integer) mem [p + 1 ].cint ;
    if ( mem [p ].hhfield .lhfield == 0 ) 
    goto lab10 ;
    p = mem [p ].hhfield .v.RH ;
  } 
  lab10: ;
} 
void 
pairtopath ( void ) 
{
  curexp = newknot () ;
  curtype = 9 ;
} 
void 
ztakepart ( quarterword c ) 
{
  halfword p  ;
  p = mem [curexp + 1 ].cint ;
  mem [18 ].cint = p ;
  mem [17 ].hhfield .b0 = curtype ;
  mem [p ].hhfield .v.RH = 17 ;
  freenode ( curexp , 2 ) ;
  makeexpcopy ( p + 2 * ( c - 53 ) ) ;
  recyclevalue ( 17 ) ;
} 
void 
zstrtonum ( quarterword c ) 
{
  integer n  ;
  ASCIIcode m  ;
  poolpointer k  ;
  unsigned char b  ;
  boolean badchar  ;
  if ( c == 49 ) {
      
    if ( ( strstart [curexp + 1 ]- strstart [curexp ]) == 0 ) 
    n = -1 ;
    else n = strpool [strstart [curexp ]];
  } 
  else {
      
    if ( c == 47 ) 
    b = 8 ;
    else b = 16 ;
    n = 0 ;
    badchar = false ;
    {register integer for_end; k = strstart [curexp ];for_end = strstart [
    curexp + 1 ]- 1 ; if ( k <= for_end) do 
      {
	m = strpool [k ];
	if ( ( m >= 48 ) && ( m <= 57 ) ) 
	m = m - 48 ;
	else if ( ( m >= 65 ) && ( m <= 70 ) ) 
	m = m - 55 ;
	else if ( ( m >= 97 ) && ( m <= 102 ) ) 
	m = m - 87 ;
	else {
	    
	  badchar = true ;
	  m = 0 ;
	} 
	if ( m >= b ) 
	{
	  badchar = true ;
	  m = 0 ;
	} 
	if ( n < 32768L / b ) 
	n = n * b + m ;
	else n = 32767 ;
      } 
    while ( k++ < for_end ) ;} 
    if ( badchar ) 
    {
      disperr ( 0 , 843 ) ;
      if ( c == 47 ) 
      {
	helpptr = 1 ;
	helpline [0 ]= 844 ;
      } 
      else {
	  
	helpptr = 1 ;
	helpline [0 ]= 845 ;
      } 
      putgeterror () ;
    } 
    if ( n > 4095 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 846 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 846 ) ;
	} 
      } 
      printint ( n ) ;
      printchar ( 41 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 847 ;
      } 
      putgeterror () ;
    } 
  } 
  flushcurexp ( n * 65536L ) ;
} 
scaled 
pathlength ( void ) 
{
  register scaled Result; scaled n  ;
  halfword p  ;
  p = curexp ;
  if ( mem [p ].hhfield .b0 == 0 ) 
  n = -65536L ;
  else n = 0 ;
  do {
      p = mem [p ].hhfield .v.RH ;
    n = n + 65536L ;
  } while ( ! ( p == curexp ) ) ;
  Result = n ;
  return Result ;
} 
void 
ztestknown ( quarterword c ) 
{
  /* 30 */ unsigned char b  ;
  halfword p, q  ;
  b = 31 ;
  switch ( curtype ) 
  {case 1 : 
  case 2 : 
  case 4 : 
  case 6 : 
  case 8 : 
  case 9 : 
  case 11 : 
  case 16 : 
    b = 30 ;
    break ;
  case 13 : 
  case 14 : 
    {
      p = mem [curexp + 1 ].cint ;
      q = p + bignodesize [curtype ];
      do {
	  q = q - 2 ;
	if ( mem [q ].hhfield .b0 != 16 ) 
	goto lab30 ;
      } while ( ! ( q == p ) ) ;
      b = 30 ;
      lab30: ;
    } 
    break ;
    default: 
    ;
    break ;
  } 
  if ( c == 39 ) 
  flushcurexp ( b ) ;
  else flushcurexp ( 61 - b ) ;
  curtype = 2 ;
} 
void 
zdounary ( quarterword c ) 
{
  halfword p, q  ;
  integer x  ;
  {
    if ( aritherror ) 
    cleararith () ;
  } 
  if ( internal [7 ]> 131072L ) 
  {
    begindiagnostic () ;
    printnl ( 123 ) ;
    printop ( c ) ;
    printchar ( 40 ) ;
    printexp ( 0 , 0 ) ;
    print ( 842 ) ;
    enddiagnostic ( false ) ;
  } 
  switch ( c ) 
  {case 69 : 
    if ( curtype < 14 ) {
	
      if ( curtype != 11 ) 
      badunary ( 69 ) ;
    } 
    break ;
  case 70 : 
    switch ( curtype ) 
    {case 14 : 
    case 19 : 
      {
	q = curexp ;
	makeexpcopy ( q ) ;
	if ( curtype == 17 ) 
	negatedeplist ( mem [curexp + 1 ].hhfield .v.RH ) ;
	else if ( curtype == 14 ) 
	{
	  p = mem [curexp + 1 ].cint ;
	  if ( mem [p ].hhfield .b0 == 16 ) 
	  mem [p + 1 ].cint = - (integer) mem [p + 1 ].cint ;
	  else negatedeplist ( mem [p + 1 ].hhfield .v.RH ) ;
	  if ( mem [p + 2 ].hhfield .b0 == 16 ) 
	  mem [p + 3 ].cint = - (integer) mem [p + 3 ].cint ;
	  else negatedeplist ( mem [p + 3 ].hhfield .v.RH ) ;
	} 
	recyclevalue ( q ) ;
	freenode ( q , 2 ) ;
      } 
      break ;
    case 17 : 
    case 18 : 
      negatedeplist ( mem [curexp + 1 ].hhfield .v.RH ) ;
      break ;
    case 16 : 
      curexp = - (integer) curexp ;
      break ;
    case 11 : 
      negateedges ( curexp ) ;
      break ;
      default: 
      badunary ( 70 ) ;
      break ;
    } 
    break ;
  case 41 : 
    if ( curtype != 2 ) 
    badunary ( 41 ) ;
    else curexp = 61 - curexp ;
    break ;
  case 59 : 
  case 60 : 
  case 61 : 
  case 62 : 
  case 63 : 
  case 64 : 
  case 65 : 
  case 38 : 
  case 66 : 
    if ( curtype != 16 ) 
    badunary ( c ) ;
    else switch ( c ) 
    {case 59 : 
      curexp = squarert ( curexp ) ;
      break ;
    case 60 : 
      curexp = mexp ( curexp ) ;
      break ;
    case 61 : 
      curexp = mlog ( curexp ) ;
      break ;
    case 62 : 
    case 63 : 
      {
	nsincos ( ( curexp % 23592960L ) * 16 ) ;
	if ( c == 62 ) 
	curexp = roundfraction ( nsin ) ;
	else curexp = roundfraction ( ncos ) ;
      } 
      break ;
    case 64 : 
      curexp = floorscaled ( curexp ) ;
      break ;
    case 65 : 
      curexp = unifrand ( curexp ) ;
      break ;
    case 38 : 
      {
	if ( odd ( roundunscaled ( curexp ) ) ) 
	curexp = 30 ;
	else curexp = 31 ;
	curtype = 2 ;
      } 
      break ;
    case 66 : 
      {
	curexp = roundunscaled ( curexp ) % 256 ;
	if ( curexp < 0 ) 
	curexp = curexp + 256 ;
	if ( charexists [curexp ]) 
	curexp = 30 ;
	else curexp = 31 ;
	curtype = 2 ;
      } 
      break ;
    } 
    break ;
  case 67 : 
    if ( nicepair ( curexp , curtype ) ) 
    {
      p = mem [curexp + 1 ].cint ;
      x = narg ( mem [p + 1 ].cint , mem [p + 3 ].cint ) ;
      if ( x >= 0 ) 
      flushcurexp ( ( x + 8 ) / 16 ) ;
      else flushcurexp ( - (integer) ( ( - (integer) x + 8 ) / 16 ) ) ;
    } 
    else badunary ( 67 ) ;
    break ;
  case 53 : 
  case 54 : 
    if ( ( curtype <= 14 ) && ( curtype >= 13 ) ) 
    takepart ( c ) ;
    else badunary ( c ) ;
    break ;
  case 55 : 
  case 56 : 
  case 57 : 
  case 58 : 
    if ( curtype == 13 ) 
    takepart ( c ) ;
    else badunary ( c ) ;
    break ;
  case 50 : 
    if ( curtype != 16 ) 
    badunary ( 50 ) ;
    else {
	
      curexp = roundunscaled ( curexp ) % 256 ;
      curtype = 4 ;
      if ( curexp < 0 ) 
      curexp = curexp + 256 ;
      if ( ( strstart [curexp + 1 ]- strstart [curexp ]) != 1 ) 
      {
	{
	  if ( poolptr + 1 > maxpoolptr ) 
	  {
	    if ( poolptr + 1 > poolsize ) 
	    overflow ( 257 , poolsize - initpoolptr ) ;
	    maxpoolptr = poolptr + 1 ;
	  } 
	} 
	{
	  strpool [poolptr ]= curexp ;
	  incr ( poolptr ) ;
	} 
	curexp = makestring () ;
      } 
    } 
    break ;
  case 42 : 
    if ( curtype != 16 ) 
    badunary ( 42 ) ;
    else {
	
      oldsetting = selector ;
      selector = 5 ;
      printscaled ( curexp ) ;
      curexp = makestring () ;
      selector = oldsetting ;
      curtype = 4 ;
    } 
    break ;
  case 47 : 
  case 48 : 
  case 49 : 
    if ( curtype != 4 ) 
    badunary ( c ) ;
    else strtonum ( c ) ;
    break ;
  case 51 : 
    if ( curtype == 4 ) 
    flushcurexp ( ( strstart [curexp + 1 ]- strstart [curexp ]) * 65536L ) 
    ;
    else if ( curtype == 9 ) 
    flushcurexp ( pathlength () ) ;
    else if ( curtype == 16 ) 
    curexp = abs ( curexp ) ;
    else if ( nicepair ( curexp , curtype ) ) 
    flushcurexp ( pythadd ( mem [mem [curexp + 1 ].cint + 1 ].cint , mem [
    mem [curexp + 1 ].cint + 3 ].cint ) ) ;
    else badunary ( c ) ;
    break ;
  case 52 : 
    if ( curtype == 14 ) 
    flushcurexp ( 0 ) ;
    else if ( curtype != 9 ) 
    badunary ( 52 ) ;
    else if ( mem [curexp ].hhfield .b0 == 0 ) 
    flushcurexp ( 0 ) ;
    else {
	
      curpen = 3 ;
      curpathtype = 1 ;
      curexp = makespec ( curexp , -1879080960L , 0 ) ;
      flushcurexp ( turningnumber * 65536L ) ;
    } 
    break ;
  case 2 : 
    {
      if ( ( curtype >= 2 ) && ( curtype <= 3 ) ) 
      flushcurexp ( 30 ) ;
      else flushcurexp ( 31 ) ;
      curtype = 2 ;
    } 
    break ;
  case 4 : 
    {
      if ( ( curtype >= 4 ) && ( curtype <= 5 ) ) 
      flushcurexp ( 30 ) ;
      else flushcurexp ( 31 ) ;
      curtype = 2 ;
    } 
    break ;
  case 6 : 
    {
      if ( ( curtype >= 6 ) && ( curtype <= 8 ) ) 
      flushcurexp ( 30 ) ;
      else flushcurexp ( 31 ) ;
      curtype = 2 ;
    } 
    break ;
  case 9 : 
    {
      if ( ( curtype >= 9 ) && ( curtype <= 10 ) ) 
      flushcurexp ( 30 ) ;
      else flushcurexp ( 31 ) ;
      curtype = 2 ;
    } 
    break ;
  case 11 : 
    {
      if ( ( curtype >= 11 ) && ( curtype <= 12 ) ) 
      flushcurexp ( 30 ) ;
      else flushcurexp ( 31 ) ;
      curtype = 2 ;
    } 
    break ;
  case 13 : 
  case 14 : 
    {
      if ( curtype == c ) 
      flushcurexp ( 30 ) ;
      else flushcurexp ( 31 ) ;
      curtype = 2 ;
    } 
    break ;
  case 15 : 
    {
      if ( ( curtype >= 16 ) && ( curtype <= 19 ) ) 
      flushcurexp ( 30 ) ;
      else flushcurexp ( 31 ) ;
      curtype = 2 ;
    } 
    break ;
  case 39 : 
  case 40 : 
    testknown ( c ) ;
    break ;
  case 68 : 
    {
      if ( curtype != 9 ) 
      flushcurexp ( 31 ) ;
      else if ( mem [curexp ].hhfield .b0 != 0 ) 
      flushcurexp ( 30 ) ;
      else flushcurexp ( 31 ) ;
      curtype = 2 ;
    } 
    break ;
  case 45 : 
    {
      if ( curtype == 14 ) 
      pairtopath () ;
      if ( curtype == 9 ) 
      curtype = 8 ;
      else badunary ( 45 ) ;
    } 
    break ;
  case 44 : 
    {
      if ( curtype == 8 ) 
      materializepen () ;
      if ( curtype != 6 ) 
      badunary ( 44 ) ;
      else {
	  
	flushcurexp ( makepath ( curexp ) ) ;
	curtype = 9 ;
      } 
    } 
    break ;
  case 46 : 
    if ( curtype != 11 ) 
    badunary ( 46 ) ;
    else flushcurexp ( totalweight ( curexp ) ) ;
    break ;
  case 43 : 
    if ( curtype == 9 ) 
    {
      p = htapypoc ( curexp ) ;
      if ( mem [p ].hhfield .b1 == 0 ) 
      p = mem [p ].hhfield .v.RH ;
      tossknotlist ( curexp ) ;
      curexp = p ;
    } 
    else if ( curtype == 14 ) 
    pairtopath () ;
    else badunary ( 43 ) ;
    break ;
  } 
  {
    if ( aritherror ) 
    cleararith () ;
  } 
} 
void 
zbadbinary ( halfword p , quarterword c ) 
{
  disperr ( p , 261 ) ;
  disperr ( 0 , 838 ) ;
  if ( c >= 94 ) 
  printop ( c ) ;
  printknownorunknowntype ( mem [p ].hhfield .b0 , p ) ;
  if ( c >= 94 ) 
  print ( 479 ) ;
  else printop ( c ) ;
  printknownorunknowntype ( curtype , curexp ) ;
  {
    helpptr = 3 ;
    helpline [2 ]= 839 ;
    helpline [1 ]= 848 ;
    helpline [0 ]= 849 ;
  } 
  putgeterror () ;
} 
halfword 
ztarnished ( halfword p ) 
{
  /* 10 */ register halfword Result; halfword q  ;
  halfword r  ;
  q = mem [p + 1 ].cint ;
  r = q + bignodesize [mem [p ].hhfield .b0 ];
  do {
      r = r - 2 ;
    if ( mem [r ].hhfield .b0 == 19 ) 
    {
      Result = 1 ;
      goto lab10 ;
    } 
  } while ( ! ( r == q ) ) ;
  Result = 0 ;
  lab10: ;
  return Result ;
} 
void 
zdepfinish ( halfword v , halfword q , smallnumber t ) 
{
  halfword p  ;
  scaled vv  ;
  if ( q == 0 ) 
  p = curexp ;
  else p = q ;
  mem [p + 1 ].hhfield .v.RH = v ;
  mem [p ].hhfield .b0 = t ;
  if ( mem [v ].hhfield .lhfield == 0 ) 
  {
    vv = mem [v + 1 ].cint ;
    if ( q == 0 ) 
    flushcurexp ( vv ) ;
    else {
	
      recyclevalue ( p ) ;
      mem [q ].hhfield .b0 = 16 ;
      mem [q + 1 ].cint = vv ;
    } 
  } 
  else if ( q == 0 ) 
  curtype = t ;
  if ( fixneeded ) 
  fixdependencies () ;
} 
void 
zaddorsubtract ( halfword p , halfword q , quarterword c ) 
{
  /* 30 10 */ smallnumber s, t  ;
  halfword r  ;
  integer v  ;
  if ( q == 0 ) 
  {
    t = curtype ;
    if ( t < 17 ) 
    v = curexp ;
    else v = mem [curexp + 1 ].hhfield .v.RH ;
  } 
  else {
      
    t = mem [q ].hhfield .b0 ;
    if ( t < 17 ) 
    v = mem [q + 1 ].cint ;
    else v = mem [q + 1 ].hhfield .v.RH ;
  } 
  if ( t == 16 ) 
  {
    if ( c == 70 ) 
    v = - (integer) v ;
    if ( mem [p ].hhfield .b0 == 16 ) 
    {
      v = slowadd ( mem [p + 1 ].cint , v ) ;
      if ( q == 0 ) 
      curexp = v ;
      else mem [q + 1 ].cint = v ;
      goto lab10 ;
    } 
    r = mem [p + 1 ].hhfield .v.RH ;
    while ( mem [r ].hhfield .lhfield != 0 ) r = mem [r ].hhfield .v.RH ;
    mem [r + 1 ].cint = slowadd ( mem [r + 1 ].cint , v ) ;
    if ( q == 0 ) 
    {
      q = getnode ( 2 ) ;
      curexp = q ;
      curtype = mem [p ].hhfield .b0 ;
      mem [q ].hhfield .b1 = 11 ;
    } 
    mem [q + 1 ].hhfield .v.RH = mem [p + 1 ].hhfield .v.RH ;
    mem [q ].hhfield .b0 = mem [p ].hhfield .b0 ;
    mem [q + 1 ].hhfield .lhfield = mem [p + 1 ].hhfield .lhfield ;
    mem [mem [p + 1 ].hhfield .lhfield ].hhfield .v.RH = q ;
    mem [p ].hhfield .b0 = 16 ;
  } 
  else {
      
    if ( c == 70 ) 
    negatedeplist ( v ) ;
    if ( mem [p ].hhfield .b0 == 16 ) 
    {
      while ( mem [v ].hhfield .lhfield != 0 ) v = mem [v ].hhfield .v.RH 
      ;
      mem [v + 1 ].cint = slowadd ( mem [p + 1 ].cint , mem [v + 1 ]
      .cint ) ;
    } 
    else {
	
      s = mem [p ].hhfield .b0 ;
      r = mem [p + 1 ].hhfield .v.RH ;
      if ( t == 17 ) 
      {
	if ( s == 17 ) {
	    
	  if ( maxcoef ( r ) + maxcoef ( v ) < 626349397L ) 
	  {
	    v = pplusq ( v , r , 17 ) ;
	    goto lab30 ;
	  } 
	} 
	t = 18 ;
	v = poverv ( v , 65536L , 17 , 18 ) ;
      } 
      if ( s == 18 ) 
      v = pplusq ( v , r , 18 ) ;
      else v = pplusfq ( v , 65536L , r , 18 , 17 ) ;
      lab30: if ( q != 0 ) 
      depfinish ( v , q , t ) ;
      else {
	  
	curtype = t ;
	depfinish ( v , 0 , t ) ;
      } 
    } 
  } 
  lab10: ;
} 
void 
zdepmult ( halfword p , integer v , boolean visscaled ) 
{
  /* 10 */ halfword q  ;
  smallnumber s, t  ;
  if ( p == 0 ) 
  q = curexp ;
  else if ( mem [p ].hhfield .b0 != 16 ) 
  q = p ;
  else {
      
    if ( visscaled ) 
    mem [p + 1 ].cint = takescaled ( mem [p + 1 ].cint , v ) ;
    else mem [p + 1 ].cint = takefraction ( mem [p + 1 ].cint , v ) ;
    goto lab10 ;
  } 
  t = mem [q ].hhfield .b0 ;
  q = mem [q + 1 ].hhfield .v.RH ;
  s = t ;
  if ( t == 17 ) {
      
    if ( visscaled ) {
	
      if ( abvscd ( maxcoef ( q ) , abs ( v ) , 626349396L , 65536L ) >= 0 ) 
      t = 18 ;
    } 
  } 
  q = ptimesv ( q , v , s , t , visscaled ) ;
  depfinish ( q , p , t ) ;
  lab10: ;
} 
void 
zhardtimes ( halfword p ) 
{
  halfword q  ;
  halfword r  ;
  scaled u, v  ;
  if ( mem [p ].hhfield .b0 == 14 ) 
  {
    q = stashcurexp () ;
    unstashcurexp ( p ) ;
    p = q ;
  } 
  r = mem [curexp + 1 ].cint ;
  u = mem [r + 1 ].cint ;
  v = mem [r + 3 ].cint ;
  mem [r + 2 ].hhfield .b0 = mem [p ].hhfield .b0 ;
  newdep ( r + 2 , copydeplist ( mem [p + 1 ].hhfield .v.RH ) ) ;
  mem [r ].hhfield .b0 = mem [p ].hhfield .b0 ;
  mem [r + 1 ]= mem [p + 1 ];
  mem [mem [p + 1 ].hhfield .lhfield ].hhfield .v.RH = r ;
  freenode ( p , 2 ) ;
  depmult ( r , u , true ) ;
  depmult ( r + 2 , v , true ) ;
} 
void 
zdepdiv ( halfword p , scaled v ) 
{
  /* 10 */ halfword q  ;
  smallnumber s, t  ;
  if ( p == 0 ) 
  q = curexp ;
  else if ( mem [p ].hhfield .b0 != 16 ) 
  q = p ;
  else {
      
    mem [p + 1 ].cint = makescaled ( mem [p + 1 ].cint , v ) ;
    goto lab10 ;
  } 
  t = mem [q ].hhfield .b0 ;
  q = mem [q + 1 ].hhfield .v.RH ;
  s = t ;
  if ( t == 17 ) {
      
    if ( abvscd ( maxcoef ( q ) , 65536L , 626349396L , abs ( v ) ) >= 0 ) 
    t = 18 ;
  } 
  q = poverv ( q , v , s , t ) ;
  depfinish ( q , p , t ) ;
  lab10: ;
} 
void 
zsetuptrans ( quarterword c ) 
{
  /* 30 10 */ halfword p, q, r  ;
  if ( ( c != 88 ) || ( curtype != 13 ) ) 
  {
    p = stashcurexp () ;
    curexp = idtransform () ;
    curtype = 13 ;
    q = mem [curexp + 1 ].cint ;
    switch ( c ) 
    {case 84 : 
      if ( mem [p ].hhfield .b0 == 16 ) 
      {
	nsincos ( ( mem [p + 1 ].cint % 23592960L ) * 16 ) ;
	mem [q + 5 ].cint = roundfraction ( ncos ) ;
	mem [q + 9 ].cint = roundfraction ( nsin ) ;
	mem [q + 7 ].cint = - (integer) mem [q + 9 ].cint ;
	mem [q + 11 ].cint = mem [q + 5 ].cint ;
	goto lab30 ;
      } 
      break ;
    case 85 : 
      if ( mem [p ].hhfield .b0 > 14 ) 
      {
	install ( q + 6 , p ) ;
	goto lab30 ;
      } 
      break ;
    case 86 : 
      if ( mem [p ].hhfield .b0 > 14 ) 
      {
	install ( q + 4 , p ) ;
	install ( q + 10 , p ) ;
	goto lab30 ;
      } 
      break ;
    case 87 : 
      if ( mem [p ].hhfield .b0 == 14 ) 
      {
	r = mem [p + 1 ].cint ;
	install ( q , r ) ;
	install ( q + 2 , r + 2 ) ;
	goto lab30 ;
      } 
      break ;
    case 89 : 
      if ( mem [p ].hhfield .b0 > 14 ) 
      {
	install ( q + 4 , p ) ;
	goto lab30 ;
      } 
      break ;
    case 90 : 
      if ( mem [p ].hhfield .b0 > 14 ) 
      {
	install ( q + 10 , p ) ;
	goto lab30 ;
      } 
      break ;
    case 91 : 
      if ( mem [p ].hhfield .b0 == 14 ) 
      {
	r = mem [p + 1 ].cint ;
	install ( q + 4 , r ) ;
	install ( q + 10 , r ) ;
	install ( q + 8 , r + 2 ) ;
	if ( mem [r + 2 ].hhfield .b0 == 16 ) 
	mem [r + 3 ].cint = - (integer) mem [r + 3 ].cint ;
	else negatedeplist ( mem [r + 3 ].hhfield .v.RH ) ;
	install ( q + 6 , r + 2 ) ;
	goto lab30 ;
      } 
      break ;
    case 88 : 
      ;
      break ;
    } 
    disperr ( p , 858 ) ;
    {
      helpptr = 3 ;
      helpline [2 ]= 859 ;
      helpline [1 ]= 860 ;
      helpline [0 ]= 538 ;
    } 
    putgeterror () ;
    lab30: recyclevalue ( p ) ;
    freenode ( p , 2 ) ;
  } 
  q = mem [curexp + 1 ].cint ;
  r = q + 12 ;
  do {
      r = r - 2 ;
    if ( mem [r ].hhfield .b0 != 16 ) 
    goto lab10 ;
  } while ( ! ( r == q ) ) ;
  txx = mem [q + 5 ].cint ;
  txy = mem [q + 7 ].cint ;
  tyx = mem [q + 9 ].cint ;
  tyy = mem [q + 11 ].cint ;
  tx = mem [q + 1 ].cint ;
  ty = mem [q + 3 ].cint ;
  flushcurexp ( 0 ) ;
  lab10: ;
} 
void 
zsetupknowntrans ( quarterword c ) 
{
  setuptrans ( c ) ;
  if ( curtype != 16 ) 
  {
    disperr ( 0 , 861 ) ;
    {
      helpptr = 3 ;
      helpline [2 ]= 862 ;
      helpline [1 ]= 863 ;
      helpline [0 ]= 538 ;
    } 
    putgetflusherror ( 0 ) ;
    txx = 65536L ;
    txy = 0 ;
    tyx = 0 ;
    tyy = 65536L ;
    tx = 0 ;
    ty = 0 ;
  } 
} 
void 
ztrans ( halfword p , halfword q ) 
{
  scaled v  ;
  v = takescaled ( mem [p ].cint , txx ) + takescaled ( mem [q ].cint , 
  txy ) + tx ;
  mem [q ].cint = takescaled ( mem [p ].cint , tyx ) + takescaled ( mem [
  q ].cint , tyy ) + ty ;
  mem [p ].cint = v ;
} 
void 
zpathtrans ( halfword p , quarterword c ) 
{
  /* 10 */ halfword q  ;
  setupknowntrans ( c ) ;
  unstashcurexp ( p ) ;
  if ( curtype == 6 ) 
  {
    if ( mem [curexp + 9 ].cint == 0 ) {
	
      if ( tx == 0 ) {
	  
	if ( ty == 0 ) 
	goto lab10 ;
      } 
    } 
    flushcurexp ( makepath ( curexp ) ) ;
    curtype = 8 ;
  } 
  q = curexp ;
  do {
      if ( mem [q ].hhfield .b0 != 0 ) 
    trans ( q + 3 , q + 4 ) ;
    trans ( q + 1 , q + 2 ) ;
    if ( mem [q ].hhfield .b1 != 0 ) 
    trans ( q + 5 , q + 6 ) ;
    q = mem [q ].hhfield .v.RH ;
  } while ( ! ( q == curexp ) ) ;
  lab10: ;
} 
void 
zedgestrans ( halfword p , quarterword c ) 
{
  /* 10 */ setupknowntrans ( c ) ;
  unstashcurexp ( p ) ;
  curedges = curexp ;
  if ( mem [curedges ].hhfield .v.RH == curedges ) 
  goto lab10 ;
  if ( txx == 0 ) {
      
    if ( tyy == 0 ) {
	
      if ( txy % 65536L == 0 ) {
	  
	if ( tyx % 65536L == 0 ) 
	{
	  xyswapedges () ;
	  txx = txy ;
	  tyy = tyx ;
	  txy = 0 ;
	  tyx = 0 ;
	  if ( mem [curedges ].hhfield .v.RH == curedges ) 
	  goto lab10 ;
	} 
      } 
    } 
  } 
  if ( txy == 0 ) {
      
    if ( tyx == 0 ) {
	
      if ( txx % 65536L == 0 ) {
	  
	if ( tyy % 65536L == 0 ) 
	{
	  if ( ( txx == 0 ) || ( tyy == 0 ) ) 
	  {
	    tossedges ( curedges ) ;
	    curexp = getnode ( 6 ) ;
	    initedges ( curexp ) ;
	  } 
	  else {
	      
	    if ( txx < 0 ) 
	    {
	      xreflectedges () ;
	      txx = - (integer) txx ;
	    } 
	    if ( tyy < 0 ) 
	    {
	      yreflectedges () ;
	      tyy = - (integer) tyy ;
	    } 
	    if ( txx != 65536L ) 
	    xscaleedges ( txx / 65536L ) ;
	    if ( tyy != 65536L ) 
	    yscaleedges ( tyy / 65536L ) ;
	    tx = roundunscaled ( tx ) ;
	    ty = roundunscaled ( ty ) ;
	    if ( ( mem [curedges + 2 ].hhfield .lhfield + tx <= 0 ) || ( mem 
	    [curedges + 2 ].hhfield .v.RH + tx >= 8192 ) || ( mem [curedges 
	    + 1 ].hhfield .lhfield + ty <= 0 ) || ( mem [curedges + 1 ]
	    .hhfield .v.RH + ty >= 8191 ) || ( abs ( tx ) >= 4096 ) || ( abs ( 
	    ty ) >= 4096 ) ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) 
		) 
		{
		  printnl ( 261 ) ;
		  print ( fullsourcefilenamestack [inopen ]) ;
		  print ( 58 ) ;
		  printint ( line ) ;
		  print ( 262 ) ;
		  print ( 867 ) ;
		} 
		else {
		    
		  printnl ( 263 ) ;
		  print ( 867 ) ;
		} 
	      } 
	      {
		helpptr = 3 ;
		helpline [2 ]= 868 ;
		helpline [1 ]= 537 ;
		helpline [0 ]= 538 ;
	      } 
	      putgeterror () ;
	    } 
	    else {
		
	      if ( tx != 0 ) 
	      {
		if ( ! ( abs ( mem [curedges + 3 ].hhfield .lhfield - tx - 
		4096 ) < 4096 ) ) 
		fixoffset () ;
		mem [curedges + 2 ].hhfield .lhfield = mem [curedges + 2 ]
		.hhfield .lhfield + tx ;
		mem [curedges + 2 ].hhfield .v.RH = mem [curedges + 2 ]
		.hhfield .v.RH + tx ;
		mem [curedges + 3 ].hhfield .lhfield = mem [curedges + 3 ]
		.hhfield .lhfield - tx ;
		mem [curedges + 4 ].cint = 0 ;
	      } 
	      if ( ty != 0 ) 
	      {
		mem [curedges + 1 ].hhfield .lhfield = mem [curedges + 1 ]
		.hhfield .lhfield + ty ;
		mem [curedges + 1 ].hhfield .v.RH = mem [curedges + 1 ]
		.hhfield .v.RH + ty ;
		mem [curedges + 5 ].hhfield .lhfield = mem [curedges + 5 ]
		.hhfield .lhfield + ty ;
		mem [curedges + 4 ].cint = 0 ;
	      } 
	    } 
	  } 
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( 864 ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( 864 ) ;
    } 
  } 
  {
    helpptr = 3 ;
    helpline [2 ]= 865 ;
    helpline [1 ]= 866 ;
    helpline [0 ]= 538 ;
  } 
  putgeterror () ;
  lab10: ;
} 
void 
zbilin1 ( halfword p , scaled t , halfword q , scaled u , scaled delta ) 
{
  halfword r  ;
  if ( t != 65536L ) 
  depmult ( p , t , true ) ;
  if ( u != 0 ) {
      
    if ( mem [q ].hhfield .b0 == 16 ) 
    delta = delta + takescaled ( mem [q + 1 ].cint , u ) ;
    else {
	
      if ( mem [p ].hhfield .b0 != 18 ) 
      {
	if ( mem [p ].hhfield .b0 == 16 ) 
	newdep ( p , constdependency ( mem [p + 1 ].cint ) ) ;
	else mem [p + 1 ].hhfield .v.RH = ptimesv ( mem [p + 1 ].hhfield 
	.v.RH , 65536L , 17 , 18 , true ) ;
	mem [p ].hhfield .b0 = 18 ;
      } 
      mem [p + 1 ].hhfield .v.RH = pplusfq ( mem [p + 1 ].hhfield .v.RH , 
      u , mem [q + 1 ].hhfield .v.RH , 18 , mem [q ].hhfield .b0 ) ;
    } 
  } 
  if ( mem [p ].hhfield .b0 == 16 ) 
  mem [p + 1 ].cint = mem [p + 1 ].cint + delta ;
  else {
      
    r = mem [p + 1 ].hhfield .v.RH ;
    while ( mem [r ].hhfield .lhfield != 0 ) r = mem [r ].hhfield .v.RH ;
    delta = mem [r + 1 ].cint + delta ;
    if ( r != mem [p + 1 ].hhfield .v.RH ) 
    mem [r + 1 ].cint = delta ;
    else {
	
      recyclevalue ( p ) ;
      mem [p ].hhfield .b0 = 16 ;
      mem [p + 1 ].cint = delta ;
    } 
  } 
  if ( fixneeded ) 
  fixdependencies () ;
} 
void 
zaddmultdep ( halfword p , scaled v , halfword r ) 
{
  if ( mem [r ].hhfield .b0 == 16 ) 
  mem [depfinal + 1 ].cint = mem [depfinal + 1 ].cint + takescaled ( mem [
  r + 1 ].cint , v ) ;
  else {
      
    mem [p + 1 ].hhfield .v.RH = pplusfq ( mem [p + 1 ].hhfield .v.RH , v 
    , mem [r + 1 ].hhfield .v.RH , 18 , mem [r ].hhfield .b0 ) ;
    if ( fixneeded ) 
    fixdependencies () ;
  } 
} 
void 
zbilin2 ( halfword p , halfword t , scaled v , halfword u , halfword q ) 
{
  scaled vv  ;
  vv = mem [p + 1 ].cint ;
  mem [p ].hhfield .b0 = 18 ;
  newdep ( p , constdependency ( 0 ) ) ;
  if ( vv != 0 ) 
  addmultdep ( p , vv , t ) ;
  if ( v != 0 ) 
  addmultdep ( p , v , u ) ;
  if ( q != 0 ) 
  addmultdep ( p , 65536L , q ) ;
  if ( mem [p + 1 ].hhfield .v.RH == depfinal ) 
  {
    vv = mem [depfinal + 1 ].cint ;
    recyclevalue ( p ) ;
    mem [p ].hhfield .b0 = 16 ;
    mem [p + 1 ].cint = vv ;
  } 
} 
void 
zbilin3 ( halfword p , scaled t , scaled v , scaled u , scaled delta ) 
{
  if ( t != 65536L ) 
  delta = delta + takescaled ( mem [p + 1 ].cint , t ) ;
  else delta = delta + mem [p + 1 ].cint ;
  if ( u != 0 ) 
  mem [p + 1 ].cint = delta + takescaled ( v , u ) ;
  else mem [p + 1 ].cint = delta ;
} 
void 
zbigtrans ( halfword p , quarterword c ) 
{
  /* 10 */ halfword q, r, pp, qq  ;
  smallnumber s  ;
  s = bignodesize [mem [p ].hhfield .b0 ];
  q = mem [p + 1 ].cint ;
  r = q + s ;
  do {
      r = r - 2 ;
    if ( mem [r ].hhfield .b0 != 16 ) 
    {
      setupknowntrans ( c ) ;
      makeexpcopy ( p ) ;
      r = mem [curexp + 1 ].cint ;
      if ( curtype == 13 ) 
      {
	bilin1 ( r + 10 , tyy , q + 6 , tyx , 0 ) ;
	bilin1 ( r + 8 , tyy , q + 4 , tyx , 0 ) ;
	bilin1 ( r + 6 , txx , q + 10 , txy , 0 ) ;
	bilin1 ( r + 4 , txx , q + 8 , txy , 0 ) ;
      } 
      bilin1 ( r + 2 , tyy , q , tyx , ty ) ;
      bilin1 ( r , txx , q + 2 , txy , tx ) ;
      goto lab10 ;
    } 
  } while ( ! ( r == q ) ) ;
  setuptrans ( c ) ;
  if ( curtype == 16 ) 
  {
    makeexpcopy ( p ) ;
    r = mem [curexp + 1 ].cint ;
    if ( curtype == 13 ) 
    {
      bilin3 ( r + 10 , tyy , mem [q + 7 ].cint , tyx , 0 ) ;
      bilin3 ( r + 8 , tyy , mem [q + 5 ].cint , tyx , 0 ) ;
      bilin3 ( r + 6 , txx , mem [q + 11 ].cint , txy , 0 ) ;
      bilin3 ( r + 4 , txx , mem [q + 9 ].cint , txy , 0 ) ;
    } 
    bilin3 ( r + 2 , tyy , mem [q + 1 ].cint , tyx , ty ) ;
    bilin3 ( r , txx , mem [q + 3 ].cint , txy , tx ) ;
  } 
  else {
      
    pp = stashcurexp () ;
    qq = mem [pp + 1 ].cint ;
    makeexpcopy ( p ) ;
    r = mem [curexp + 1 ].cint ;
    if ( curtype == 13 ) 
    {
      bilin2 ( r + 10 , qq + 10 , mem [q + 7 ].cint , qq + 8 , 0 ) ;
      bilin2 ( r + 8 , qq + 10 , mem [q + 5 ].cint , qq + 8 , 0 ) ;
      bilin2 ( r + 6 , qq + 4 , mem [q + 11 ].cint , qq + 6 , 0 ) ;
      bilin2 ( r + 4 , qq + 4 , mem [q + 9 ].cint , qq + 6 , 0 ) ;
    } 
    bilin2 ( r + 2 , qq + 10 , mem [q + 1 ].cint , qq + 8 , qq + 2 ) ;
    bilin2 ( r , qq + 4 , mem [q + 3 ].cint , qq + 6 , qq ) ;
    recyclevalue ( pp ) ;
    freenode ( pp , 2 ) ;
  } 
  lab10: ;
} 
void 
zcat ( halfword p ) 
{
  strnumber a, b  ;
  poolpointer k  ;
  a = mem [p + 1 ].cint ;
  b = curexp ;
  {
    if ( poolptr + ( strstart [a + 1 ]- strstart [a ]) + ( strstart [b + 
    1 ]- strstart [b ]) > maxpoolptr ) 
    {
      if ( poolptr + ( strstart [a + 1 ]- strstart [a ]) + ( strstart [b 
      + 1 ]- strstart [b ]) > poolsize ) 
      overflow ( 257 , poolsize - initpoolptr ) ;
      maxpoolptr = poolptr + ( strstart [a + 1 ]- strstart [a ]) + ( 
      strstart [b + 1 ]- strstart [b ]) ;
    } 
  } 
  {register integer for_end; k = strstart [a ];for_end = strstart [a + 1 
  ]- 1 ; if ( k <= for_end) do 
    {
      strpool [poolptr ]= strpool [k ];
      incr ( poolptr ) ;
    } 
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = strstart [b ];for_end = strstart [b + 1 
  ]- 1 ; if ( k <= for_end) do 
    {
      strpool [poolptr ]= strpool [k ];
      incr ( poolptr ) ;
    } 
  while ( k++ < for_end ) ;} 
  curexp = makestring () ;
  {
    if ( strref [b ]< 127 ) {
	
      if ( strref [b ]> 1 ) 
      decr ( strref [b ]) ;
      else flushstring ( b ) ;
    } 
  } 
} 
void 
zchopstring ( halfword p ) 
{
  integer a, b  ;
  integer l  ;
  integer k  ;
  strnumber s  ;
  boolean reversed  ;
  a = roundunscaled ( mem [p + 1 ].cint ) ;
  b = roundunscaled ( mem [p + 3 ].cint ) ;
  if ( a <= b ) 
  reversed = false ;
  else {
      
    reversed = true ;
    k = a ;
    a = b ;
    b = k ;
  } 
  s = curexp ;
  l = ( strstart [s + 1 ]- strstart [s ]) ;
  if ( a < 0 ) 
  {
    a = 0 ;
    if ( b < 0 ) 
    b = 0 ;
  } 
  if ( b > l ) 
  {
    b = l ;
    if ( a > l ) 
    a = l ;
  } 
  {
    if ( poolptr + b - a > maxpoolptr ) 
    {
      if ( poolptr + b - a > poolsize ) 
      overflow ( 257 , poolsize - initpoolptr ) ;
      maxpoolptr = poolptr + b - a ;
    } 
  } 
  if ( reversed ) 
  {register integer for_end; k = strstart [s ]+ b - 1 ;for_end = strstart 
  [s ]+ a ; if ( k >= for_end) do 
    {
      strpool [poolptr ]= strpool [k ];
      incr ( poolptr ) ;
    } 
  while ( k-- > for_end ) ;} 
  else {
      register integer for_end; k = strstart [s ]+ a ;for_end = strstart 
  [s ]+ b - 1 ; if ( k <= for_end) do 
    {
      strpool [poolptr ]= strpool [k ];
      incr ( poolptr ) ;
    } 
  while ( k++ < for_end ) ;} 
  curexp = makestring () ;
  {
    if ( strref [s ]< 127 ) {
	
      if ( strref [s ]> 1 ) 
      decr ( strref [s ]) ;
      else flushstring ( s ) ;
    } 
  } 
} 
void 
zchoppath ( halfword p ) 
{
  halfword q  ;
  halfword pp, qq, rr, ss  ;
  scaled a, b, k, l  ;
  boolean reversed  ;
  l = pathlength () ;
  a = mem [p + 1 ].cint ;
  b = mem [p + 3 ].cint ;
  if ( a <= b ) 
  reversed = false ;
  else {
      
    reversed = true ;
    k = a ;
    a = b ;
    b = k ;
  } 
  if ( a < 0 ) {
      
    if ( mem [curexp ].hhfield .b0 == 0 ) 
    {
      a = 0 ;
      if ( b < 0 ) 
      b = 0 ;
    } 
    else do {
	a = a + l ;
      b = b + l ;
    } while ( ! ( a >= 0 ) ) ;
  } 
  if ( b > l ) {
      
    if ( mem [curexp ].hhfield .b0 == 0 ) 
    {
      b = l ;
      if ( a > l ) 
      a = l ;
    } 
    else while ( a >= l ) {
	
      a = a - l ;
      b = b - l ;
    } 
  } 
  q = curexp ;
  while ( a >= 65536L ) {
      
    q = mem [q ].hhfield .v.RH ;
    a = a - 65536L ;
    b = b - 65536L ;
  } 
  if ( b == a ) 
  {
    if ( a > 0 ) 
    {
      qq = mem [q ].hhfield .v.RH ;
      splitcubic ( q , a * 4096 , mem [qq + 1 ].cint , mem [qq + 2 ].cint 
      ) ;
      q = mem [q ].hhfield .v.RH ;
    } 
    pp = copyknot ( q ) ;
    qq = pp ;
  } 
  else {
      
    pp = copyknot ( q ) ;
    qq = pp ;
    do {
	q = mem [q ].hhfield .v.RH ;
      rr = qq ;
      qq = copyknot ( q ) ;
      mem [rr ].hhfield .v.RH = qq ;
      b = b - 65536L ;
    } while ( ! ( b <= 0 ) ) ;
    if ( a > 0 ) 
    {
      ss = pp ;
      pp = mem [pp ].hhfield .v.RH ;
      splitcubic ( ss , a * 4096 , mem [pp + 1 ].cint , mem [pp + 2 ].cint 
      ) ;
      pp = mem [ss ].hhfield .v.RH ;
      freenode ( ss , 7 ) ;
      if ( rr == ss ) 
      {
	b = makescaled ( b , 65536L - a ) ;
	rr = pp ;
      } 
    } 
    if ( b < 0 ) 
    {
      splitcubic ( rr , ( b + 65536L ) * 4096 , mem [qq + 1 ].cint , mem [
      qq + 2 ].cint ) ;
      freenode ( qq , 7 ) ;
      qq = mem [rr ].hhfield .v.RH ;
    } 
  } 
  mem [pp ].hhfield .b0 = 0 ;
  mem [qq ].hhfield .b1 = 0 ;
  mem [qq ].hhfield .v.RH = pp ;
  tossknotlist ( curexp ) ;
  if ( reversed ) 
  {
    curexp = mem [htapypoc ( pp ) ].hhfield .v.RH ;
    tossknotlist ( pp ) ;
  } 
  else curexp = pp ;
} 
void 
zpairvalue ( scaled x , scaled y ) 
{
  halfword p  ;
  p = getnode ( 2 ) ;
  flushcurexp ( p ) ;
  curtype = 14 ;
  mem [p ].hhfield .b0 = 14 ;
  mem [p ].hhfield .b1 = 11 ;
  initbignode ( p ) ;
  p = mem [p + 1 ].cint ;
  mem [p ].hhfield .b0 = 16 ;
  mem [p + 1 ].cint = x ;
  mem [p + 2 ].hhfield .b0 = 16 ;
  mem [p + 3 ].cint = y ;
} 
void 
zsetupoffset ( halfword p ) 
{
  findoffset ( mem [p + 1 ].cint , mem [p + 3 ].cint , curexp ) ;
  pairvalue ( curx , cury ) ;
} 
void 
zsetupdirectiontime ( halfword p ) 
{
  flushcurexp ( finddirectiontime ( mem [p + 1 ].cint , mem [p + 3 ]
  .cint , curexp ) ) ;
} 
void 
zfindpoint ( scaled v , quarterword c ) 
{
  halfword p  ;
  scaled n  ;
  halfword q  ;
  p = curexp ;
  if ( mem [p ].hhfield .b0 == 0 ) 
  n = -65536L ;
  else n = 0 ;
  do {
      p = mem [p ].hhfield .v.RH ;
    n = n + 65536L ;
  } while ( ! ( p == curexp ) ) ;
  if ( n == 0 ) 
  v = 0 ;
  else if ( v < 0 ) {
      
    if ( mem [p ].hhfield .b0 == 0 ) 
    v = 0 ;
    else v = n - 1 - ( ( - (integer) v - 1 ) % n ) ;
  } 
  else if ( v > n ) {
      
    if ( mem [p ].hhfield .b0 == 0 ) 
    v = n ;
    else v = v % n ;
  } 
  p = curexp ;
  while ( v >= 65536L ) {
      
    p = mem [p ].hhfield .v.RH ;
    v = v - 65536L ;
  } 
  if ( v != 0 ) 
  {
    q = mem [p ].hhfield .v.RH ;
    splitcubic ( p , v * 4096 , mem [q + 1 ].cint , mem [q + 2 ].cint ) ;
    p = mem [p ].hhfield .v.RH ;
  } 
  switch ( c ) 
  {case 97 : 
    pairvalue ( mem [p + 1 ].cint , mem [p + 2 ].cint ) ;
    break ;
  case 98 : 
    if ( mem [p ].hhfield .b0 == 0 ) 
    pairvalue ( mem [p + 1 ].cint , mem [p + 2 ].cint ) ;
    else pairvalue ( mem [p + 3 ].cint , mem [p + 4 ].cint ) ;
    break ;
  case 99 : 
    if ( mem [p ].hhfield .b1 == 0 ) 
    pairvalue ( mem [p + 1 ].cint , mem [p + 2 ].cint ) ;
    else pairvalue ( mem [p + 5 ].cint , mem [p + 6 ].cint ) ;
    break ;
  } 
} 
void 
zdobinary ( halfword p , quarterword c ) 
{
  /* 30 31 10 */ halfword q, r, rr  ;
  halfword oldp, oldexp  ;
  integer v  ;
  {
    if ( aritherror ) 
    cleararith () ;
  } 
  if ( internal [7 ]> 131072L ) 
  {
    begindiagnostic () ;
    printnl ( 850 ) ;
    printexp ( p , 0 ) ;
    printchar ( 41 ) ;
    printop ( c ) ;
    printchar ( 40 ) ;
    printexp ( 0 , 0 ) ;
    print ( 842 ) ;
    enddiagnostic ( false ) ;
  } 
  switch ( mem [p ].hhfield .b0 ) 
  {case 13 : 
  case 14 : 
    oldp = tarnished ( p ) ;
    break ;
  case 19 : 
    oldp = 1 ;
    break ;
    default: 
    oldp = 0 ;
    break ;
  } 
  if ( oldp != 0 ) 
  {
    q = stashcurexp () ;
    oldp = p ;
    makeexpcopy ( oldp ) ;
    p = stashcurexp () ;
    unstashcurexp ( q ) ;
  } 
  switch ( curtype ) 
  {case 13 : 
  case 14 : 
    oldexp = tarnished ( curexp ) ;
    break ;
  case 19 : 
    oldexp = 1 ;
    break ;
    default: 
    oldexp = 0 ;
    break ;
  } 
  if ( oldexp != 0 ) 
  {
    oldexp = curexp ;
    makeexpcopy ( oldexp ) ;
  } 
  switch ( c ) 
  {case 69 : 
  case 70 : 
    if ( ( curtype < 14 ) || ( mem [p ].hhfield .b0 < 14 ) ) {
	
      if ( ( curtype == 11 ) && ( mem [p ].hhfield .b0 == 11 ) ) 
      {
	if ( c == 70 ) 
	negateedges ( curexp ) ;
	curedges = curexp ;
	mergeedges ( mem [p + 1 ].cint ) ;
      } 
      else badbinary ( p , c ) ;
    } 
    else if ( curtype == 14 ) {
	
      if ( mem [p ].hhfield .b0 != 14 ) 
      badbinary ( p , c ) ;
      else {
	  
	q = mem [p + 1 ].cint ;
	r = mem [curexp + 1 ].cint ;
	addorsubtract ( q , r , c ) ;
	addorsubtract ( q + 2 , r + 2 , c ) ;
      } 
    } 
    else if ( mem [p ].hhfield .b0 == 14 ) 
    badbinary ( p , c ) ;
    else addorsubtract ( p , 0 , c ) ;
    break ;
  case 77 : 
  case 78 : 
  case 79 : 
  case 80 : 
  case 81 : 
  case 82 : 
    {
      if ( ( curtype > 14 ) && ( mem [p ].hhfield .b0 > 14 ) ) 
      addorsubtract ( p , 0 , 70 ) ;
      else if ( curtype != mem [p ].hhfield .b0 ) 
      {
	badbinary ( p , c ) ;
	goto lab30 ;
      } 
      else if ( curtype == 4 ) 
      flushcurexp ( strvsstr ( mem [p + 1 ].cint , curexp ) ) ;
      else if ( ( curtype == 5 ) || ( curtype == 3 ) ) 
      {
	q = mem [curexp + 1 ].cint ;
	while ( ( q != curexp ) && ( q != p ) ) q = mem [q + 1 ].cint ;
	if ( q == p ) 
	flushcurexp ( 0 ) ;
      } 
      else if ( ( curtype == 14 ) || ( curtype == 13 ) ) 
      {
	q = mem [p + 1 ].cint ;
	r = mem [curexp + 1 ].cint ;
	rr = r + bignodesize [curtype ]- 2 ;
	while ( true ) {
	    
	  addorsubtract ( q , r , 70 ) ;
	  if ( mem [r ].hhfield .b0 != 16 ) 
	  goto lab31 ;
	  if ( mem [r + 1 ].cint != 0 ) 
	  goto lab31 ;
	  if ( r == rr ) 
	  goto lab31 ;
	  q = q + 2 ;
	  r = r + 2 ;
	} 
	lab31: takepart ( 53 + half ( r - mem [curexp + 1 ].cint ) ) ;
      } 
      else if ( curtype == 2 ) 
      flushcurexp ( curexp - mem [p + 1 ].cint ) ;
      else {
	  
	badbinary ( p , c ) ;
	goto lab30 ;
      } 
      if ( curtype != 16 ) 
      {
	if ( curtype < 16 ) 
	{
	  disperr ( p , 261 ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 851 ;
	  } 
	} 
	else {
	    
	  helpptr = 2 ;
	  helpline [1 ]= 852 ;
	  helpline [0 ]= 853 ;
	} 
	disperr ( 0 , 854 ) ;
	putgetflusherror ( 31 ) ;
      } 
      else switch ( c ) 
      {case 77 : 
	if ( curexp < 0 ) 
	curexp = 30 ;
	else curexp = 31 ;
	break ;
      case 78 : 
	if ( curexp <= 0 ) 
	curexp = 30 ;
	else curexp = 31 ;
	break ;
      case 79 : 
	if ( curexp > 0 ) 
	curexp = 30 ;
	else curexp = 31 ;
	break ;
      case 80 : 
	if ( curexp >= 0 ) 
	curexp = 30 ;
	else curexp = 31 ;
	break ;
      case 81 : 
	if ( curexp == 0 ) 
	curexp = 30 ;
	else curexp = 31 ;
	break ;
      case 82 : 
	if ( curexp != 0 ) 
	curexp = 30 ;
	else curexp = 31 ;
	break ;
      } 
      curtype = 2 ;
      lab30: ;
    } 
    break ;
  case 76 : 
  case 75 : 
    if ( ( mem [p ].hhfield .b0 != 2 ) || ( curtype != 2 ) ) 
    badbinary ( p , c ) ;
    else if ( mem [p + 1 ].cint == c - 45 ) 
    curexp = mem [p + 1 ].cint ;
    break ;
  case 71 : 
    if ( ( curtype < 14 ) || ( mem [p ].hhfield .b0 < 14 ) ) 
    badbinary ( p , 71 ) ;
    else if ( ( curtype == 16 ) || ( mem [p ].hhfield .b0 == 16 ) ) 
    {
      if ( mem [p ].hhfield .b0 == 16 ) 
      {
	v = mem [p + 1 ].cint ;
	freenode ( p , 2 ) ;
      } 
      else {
	  
	v = curexp ;
	unstashcurexp ( p ) ;
      } 
      if ( curtype == 16 ) 
      curexp = takescaled ( curexp , v ) ;
      else if ( curtype == 14 ) 
      {
	p = mem [curexp + 1 ].cint ;
	depmult ( p , v , true ) ;
	depmult ( p + 2 , v , true ) ;
      } 
      else depmult ( 0 , v , true ) ;
      goto lab10 ;
    } 
    else if ( ( nicepair ( p , mem [p ].hhfield .b0 ) && ( curtype > 14 ) ) 
    || ( nicepair ( curexp , curtype ) && ( mem [p ].hhfield .b0 > 14 ) ) ) 
    {
      hardtimes ( p ) ;
      goto lab10 ;
    } 
    else badbinary ( p , 71 ) ;
    break ;
  case 72 : 
    if ( ( curtype != 16 ) || ( mem [p ].hhfield .b0 < 14 ) ) 
    badbinary ( p , 72 ) ;
    else {
	
      v = curexp ;
      unstashcurexp ( p ) ;
      if ( v == 0 ) 
      {
	disperr ( 0 , 784 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 856 ;
	  helpline [0 ]= 857 ;
	} 
	putgeterror () ;
      } 
      else {
	  
	if ( curtype == 16 ) 
	curexp = makescaled ( curexp , v ) ;
	else if ( curtype == 14 ) 
	{
	  p = mem [curexp + 1 ].cint ;
	  depdiv ( p , v ) ;
	  depdiv ( p + 2 , v ) ;
	} 
	else depdiv ( 0 , v ) ;
      } 
      goto lab10 ;
    } 
    break ;
  case 73 : 
  case 74 : 
    if ( ( curtype == 16 ) && ( mem [p ].hhfield .b0 == 16 ) ) {
	
      if ( c == 73 ) 
      curexp = pythadd ( mem [p + 1 ].cint , curexp ) ;
      else curexp = pythsub ( mem [p + 1 ].cint , curexp ) ;
    } 
    else badbinary ( p , c ) ;
    break ;
  case 84 : 
  case 85 : 
  case 86 : 
  case 87 : 
  case 88 : 
  case 89 : 
  case 90 : 
  case 91 : 
    if ( ( mem [p ].hhfield .b0 == 9 ) || ( mem [p ].hhfield .b0 == 8 ) || 
    ( mem [p ].hhfield .b0 == 6 ) ) 
    {
      pathtrans ( p , c ) ;
      goto lab10 ;
    } 
    else if ( ( mem [p ].hhfield .b0 == 14 ) || ( mem [p ].hhfield .b0 == 
    13 ) ) 
    bigtrans ( p , c ) ;
    else if ( mem [p ].hhfield .b0 == 11 ) 
    {
      edgestrans ( p , c ) ;
      goto lab10 ;
    } 
    else badbinary ( p , c ) ;
    break ;
  case 83 : 
    if ( ( curtype == 4 ) && ( mem [p ].hhfield .b0 == 4 ) ) 
    cat ( p ) ;
    else badbinary ( p , 83 ) ;
    break ;
  case 94 : 
    if ( nicepair ( p , mem [p ].hhfield .b0 ) && ( curtype == 4 ) ) 
    chopstring ( mem [p + 1 ].cint ) ;
    else badbinary ( p , 94 ) ;
    break ;
  case 95 : 
    {
      if ( curtype == 14 ) 
      pairtopath () ;
      if ( nicepair ( p , mem [p ].hhfield .b0 ) && ( curtype == 9 ) ) 
      choppath ( mem [p + 1 ].cint ) ;
      else badbinary ( p , 95 ) ;
    } 
    break ;
  case 97 : 
  case 98 : 
  case 99 : 
    {
      if ( curtype == 14 ) 
      pairtopath () ;
      if ( ( curtype == 9 ) && ( mem [p ].hhfield .b0 == 16 ) ) 
      findpoint ( mem [p + 1 ].cint , c ) ;
      else badbinary ( p , c ) ;
    } 
    break ;
  case 100 : 
    {
      if ( curtype == 8 ) 
      materializepen () ;
      if ( ( curtype == 6 ) && nicepair ( p , mem [p ].hhfield .b0 ) ) 
      setupoffset ( mem [p + 1 ].cint ) ;
      else badbinary ( p , 100 ) ;
    } 
    break ;
  case 96 : 
    {
      if ( curtype == 14 ) 
      pairtopath () ;
      if ( ( curtype == 9 ) && nicepair ( p , mem [p ].hhfield .b0 ) ) 
      setupdirectiontime ( mem [p + 1 ].cint ) ;
      else badbinary ( p , 96 ) ;
    } 
    break ;
  case 92 : 
    {
      if ( mem [p ].hhfield .b0 == 14 ) 
      {
	q = stashcurexp () ;
	unstashcurexp ( p ) ;
	pairtopath () ;
	p = stashcurexp () ;
	unstashcurexp ( q ) ;
      } 
      if ( curtype == 14 ) 
      pairtopath () ;
      if ( ( curtype == 9 ) && ( mem [p ].hhfield .b0 == 9 ) ) 
      {
	pathintersection ( mem [p + 1 ].cint , curexp ) ;
	pairvalue ( curt , curtt ) ;
      } 
      else badbinary ( p , 92 ) ;
    } 
    break ;
  } 
  recyclevalue ( p ) ;
  freenode ( p , 2 ) ;
  lab10: {
      
    if ( aritherror ) 
    cleararith () ;
  } 
  if ( oldp != 0 ) 
  {
    recyclevalue ( oldp ) ;
    freenode ( oldp , 2 ) ;
  } 
  if ( oldexp != 0 ) 
  {
    recyclevalue ( oldexp ) ;
    freenode ( oldexp , 2 ) ;
  } 
} 
void 
zfracmult ( scaled n , scaled d ) 
{
  halfword p  ;
  halfword oldexp  ;
  fraction v  ;
  if ( internal [7 ]> 131072L ) 
  {
    begindiagnostic () ;
    printnl ( 850 ) ;
    printscaled ( n ) ;
    printchar ( 47 ) ;
    printscaled ( d ) ;
    print ( 855 ) ;
    printexp ( 0 , 0 ) ;
    print ( 842 ) ;
    enddiagnostic ( false ) ;
  } 
  switch ( curtype ) 
  {case 13 : 
  case 14 : 
    oldexp = tarnished ( curexp ) ;
    break ;
  case 19 : 
    oldexp = 1 ;
    break ;
    default: 
    oldexp = 0 ;
    break ;
  } 
  if ( oldexp != 0 ) 
  {
    oldexp = curexp ;
    makeexpcopy ( oldexp ) ;
  } 
  v = makefraction ( n , d ) ;
  if ( curtype == 16 ) 
  curexp = takefraction ( curexp , v ) ;
  else if ( curtype == 14 ) 
  {
    p = mem [curexp + 1 ].cint ;
    depmult ( p , v , false ) ;
    depmult ( p + 2 , v , false ) ;
  } 
  else depmult ( 0 , v , false ) ;
  if ( oldexp != 0 ) 
  {
    recyclevalue ( oldexp ) ;
    freenode ( oldexp , 2 ) ;
  } 
} 
void 
gfswap ( void ) 
{
  if ( gfptr > ( 2147483647L - gfoffset ) ) 
  {
    gfprevptr = 0 ;
    fatalerror ( 1053 ) ;
  } 
  if ( gflimit == gfbufsize ) 
  {
    writegf ( 0 , halfbuf - 1 ) ;
    gflimit = halfbuf ;
    gfoffset = gfoffset + gfbufsize ;
    gfptr = 0 ;
  } 
  else {
      
    writegf ( halfbuf , gfbufsize - 1 ) ;
    gflimit = gfbufsize ;
  } 
} 
void 
zgffour ( integer x ) 
{
  if ( x >= 0 ) 
  {
    gfbuf [gfptr ]= x / 16777216L ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  else {
      
    x = x + 1073741824L ;
    x = x + 1073741824L ;
    {
      gfbuf [gfptr ]= ( x / 16777216L ) + 128 ;
      incr ( gfptr ) ;
      if ( gfptr == gflimit ) 
      gfswap () ;
    } 
  } 
  x = x % 16777216L ;
  {
    gfbuf [gfptr ]= x / 65536L ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  x = x % 65536L ;
  {
    gfbuf [gfptr ]= x / 256 ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  {
    gfbuf [gfptr ]= x % 256 ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
} 
void 
zgftwo ( integer x ) 
{
  {
    gfbuf [gfptr ]= x / 256 ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  {
    gfbuf [gfptr ]= x % 256 ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
} 
void 
zgfthree ( integer x ) 
{
  {
    gfbuf [gfptr ]= x / 65536L ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  {
    gfbuf [gfptr ]= ( x % 65536L ) / 256 ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  {
    gfbuf [gfptr ]= x % 256 ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
} 
void 
zgfpaint ( integer d ) 
{
  if ( d < 64 ) 
  {
    gfbuf [gfptr ]= 0 + d ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  else if ( d < 256 ) 
  {
    {
      gfbuf [gfptr ]= 64 ;
      incr ( gfptr ) ;
      if ( gfptr == gflimit ) 
      gfswap () ;
    } 
    {
      gfbuf [gfptr ]= d ;
      incr ( gfptr ) ;
      if ( gfptr == gflimit ) 
      gfswap () ;
    } 
  } 
  else {
      
    {
      gfbuf [gfptr ]= 65 ;
      incr ( gfptr ) ;
      if ( gfptr == gflimit ) 
      gfswap () ;
    } 
    gftwo ( d ) ;
  } 
} 
void 
zgfstring ( strnumber s , strnumber t ) 
{
  poolpointer k  ;
  integer l  ;
  if ( s != 0 ) 
  {
    l = ( strstart [s + 1 ]- strstart [s ]) ;
    if ( t != 0 ) 
    l = l + ( strstart [t + 1 ]- strstart [t ]) ;
    if ( l <= 255 ) 
    {
      {
	gfbuf [gfptr ]= 239 ;
	incr ( gfptr ) ;
	if ( gfptr == gflimit ) 
	gfswap () ;
      } 
      {
	gfbuf [gfptr ]= l ;
	incr ( gfptr ) ;
	if ( gfptr == gflimit ) 
	gfswap () ;
      } 
    } 
    else {
	
      {
	gfbuf [gfptr ]= 241 ;
	incr ( gfptr ) ;
	if ( gfptr == gflimit ) 
	gfswap () ;
      } 
      gfthree ( l ) ;
    } 
    {register integer for_end; k = strstart [s ];for_end = strstart [s + 
    1 ]- 1 ; if ( k <= for_end) do 
      {
	gfbuf [gfptr ]= strpool [k ];
	incr ( gfptr ) ;
	if ( gfptr == gflimit ) 
	gfswap () ;
      } 
    while ( k++ < for_end ) ;} 
  } 
  if ( t != 0 ) 
  {register integer for_end; k = strstart [t ];for_end = strstart [t + 1 
  ]- 1 ; if ( k <= for_end) do 
    {
      gfbuf [gfptr ]= strpool [k ];
      incr ( gfptr ) ;
      if ( gfptr == gflimit ) 
      gfswap () ;
    } 
  while ( k++ < for_end ) ;} 
} 
void 
zgfboc ( integer minm , integer maxm , integer minn , integer maxn ) 
{
  /* 10 */ if ( minm < gfminm ) 
  gfminm = minm ;
  if ( maxn > gfmaxn ) 
  gfmaxn = maxn ;
  if ( bocp == -1 ) {
      
    if ( bocc >= 0 ) {
	
      if ( bocc < 256 ) {
	  
	if ( maxm - minm >= 0 ) {
	    
	  if ( maxm - minm < 256 ) {
	      
	    if ( maxm >= 0 ) {
		
	      if ( maxm < 256 ) {
		  
		if ( maxn - minn >= 0 ) {
		    
		  if ( maxn - minn < 256 ) {
		      
		    if ( maxn >= 0 ) {
			
		      if ( maxn < 256 ) 
		      {
			{
			  gfbuf [gfptr ]= 68 ;
			  incr ( gfptr ) ;
			  if ( gfptr == gflimit ) 
			  gfswap () ;
			} 
			{
			  gfbuf [gfptr ]= bocc ;
			  incr ( gfptr ) ;
			  if ( gfptr == gflimit ) 
			  gfswap () ;
			} 
			{
			  gfbuf [gfptr ]= maxm - minm ;
			  incr ( gfptr ) ;
			  if ( gfptr == gflimit ) 
			  gfswap () ;
			} 
			{
			  gfbuf [gfptr ]= maxm ;
			  incr ( gfptr ) ;
			  if ( gfptr == gflimit ) 
			  gfswap () ;
			} 
			{
			  gfbuf [gfptr ]= maxn - minn ;
			  incr ( gfptr ) ;
			  if ( gfptr == gflimit ) 
			  gfswap () ;
			} 
			{
			  gfbuf [gfptr ]= maxn ;
			  incr ( gfptr ) ;
			  if ( gfptr == gflimit ) 
			  gfswap () ;
			} 
			goto lab10 ;
		      } 
		    } 
		  } 
		} 
	      } 
	    } 
	  } 
	} 
      } 
    } 
  } 
  {
    gfbuf [gfptr ]= 67 ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  gffour ( bocc ) ;
  gffour ( bocp ) ;
  gffour ( minm ) ;
  gffour ( maxm ) ;
  gffour ( minn ) ;
  gffour ( maxn ) ;
  lab10: ;
} 
void 
initgf ( void ) 
{
  short k  ;
  integer t  ;
  gfminm = 4096 ;
  gfmaxm = -4096 ;
  gfminn = 4096 ;
  gfmaxn = -4096 ;
  {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
    charptr [k ]= -1 ;
  while ( k++ < for_end ) ;} 
  if ( internal [27 ]<= 0 ) 
  gfext = 1055 ;
  else {
      
    oldsetting = selector ;
    selector = 5 ;
    printchar ( 46 ) ;
    printint ( makescaled ( internal [27 ], 59429463L ) ) ;
    print ( 1056 ) ;
    gfext = makestring () ;
    selector = oldsetting ;
  } 
  {
    if ( jobname == 0 ) 
    openlogfile () ;
    packjobname ( gfext ) ;
    while ( ! bopenout ( gffile ) ) promptfilename ( 756 , gfext ) ;
    outputfilename = bmakenamestring ( gffile ) ;
  } 
  {
    gfbuf [gfptr ]= 247 ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  {
    gfbuf [gfptr ]= 131 ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  oldsetting = selector ;
  selector = 5 ;
  print ( 1054 ) ;
  printint ( roundunscaled ( internal [14 ]) ) ;
  printchar ( 46 ) ;
  printdd ( roundunscaled ( internal [15 ]) ) ;
  printchar ( 46 ) ;
  printdd ( roundunscaled ( internal [16 ]) ) ;
  printchar ( 58 ) ;
  t = roundunscaled ( internal [17 ]) ;
  printdd ( t / 60 ) ;
  printdd ( t % 60 ) ;
  selector = oldsetting ;
  {
    gfbuf [gfptr ]= ( poolptr - strstart [strptr ]) ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  gfstring ( 0 , makestring () ) ;
  decr ( strptr ) ;
  poolptr = strstart [strptr ];
  gfprevptr = gfoffset + gfptr ;
} 
void 
zshipout ( eightbits c ) 
{
  /* 30 */ integer f  ;
  integer prevm, m, mm  ;
  integer prevn, n  ;
  halfword p, q  ;
  integer prevw, w, ww  ;
  integer d  ;
  integer delta  ;
  integer curminm  ;
  integer xoff, yoff  ;
  if ( outputfilename == 0 ) 
  initgf () ;
  f = roundunscaled ( internal [19 ]) ;
  xoff = roundunscaled ( internal [29 ]) ;
  yoff = roundunscaled ( internal [30 ]) ;
  if ( termoffset > maxprintline - 9 ) 
  println () ;
  else if ( ( termoffset > 0 ) || ( fileoffset > 0 ) ) 
  printchar ( 32 ) ;
  printchar ( 91 ) ;
  printint ( c ) ;
  if ( f != 0 ) 
  {
    printchar ( 46 ) ;
    printint ( f ) ;
  } 
  fflush ( stdout ) ;
  bocc = 256 * f + c ;
  bocp = charptr [c ];
  charptr [c ]= gfprevptr ;
  if ( internal [34 ]> 0 ) 
  {
    if ( xoff != 0 ) 
    {
      gfstring ( 437 , 0 ) ;
      {
	gfbuf [gfptr ]= 243 ;
	incr ( gfptr ) ;
	if ( gfptr == gflimit ) 
	gfswap () ;
      } 
      gffour ( xoff * 65536L ) ;
    } 
    if ( yoff != 0 ) 
    {
      gfstring ( 438 , 0 ) ;
      {
	gfbuf [gfptr ]= 243 ;
	incr ( gfptr ) ;
	if ( gfptr == gflimit ) 
	gfswap () ;
      } 
      gffour ( yoff * 65536L ) ;
    } 
  } 
  prevn = 4096 ;
  p = mem [curedges ].hhfield .lhfield ;
  n = mem [curedges + 1 ].hhfield .v.RH - 4096 ;
  while ( p != curedges ) {
      
    if ( mem [p + 1 ].hhfield .lhfield > 1 ) 
    sortedges ( p ) ;
    q = mem [p + 1 ].hhfield .v.RH ;
    w = 0 ;
    prevm = -268435456L ;
    ww = 0 ;
    prevw = 0 ;
    m = prevm ;
    do {
	if ( q == memtop ) 
      mm = 268435456L ;
      else {
	  
	d = mem [q ].hhfield .lhfield ;
	mm = d / 8 ;
	ww = ww + ( d % 8 ) - 4 ;
      } 
      if ( mm != m ) 
      {
	if ( prevw <= 0 ) 
	{
	  if ( w > 0 ) 
	  {
	    if ( prevm == -268435456L ) 
	    {
	      if ( prevn == 4096 ) 
	      {
		gfboc ( mem [curedges + 2 ].hhfield .lhfield + xoff - 4096 , 
		mem [curedges + 2 ].hhfield .v.RH + xoff - 4096 , mem [
		curedges + 1 ].hhfield .lhfield + yoff - 4096 , n + yoff ) ;
		curminm = mem [curedges + 2 ].hhfield .lhfield - 4096 + mem 
		[curedges + 3 ].hhfield .lhfield ;
	      } 
	      else if ( prevn > n + 1 ) 
	      {
		delta = prevn - n - 1 ;
		if ( delta < 256 ) 
		{
		  {
		    gfbuf [gfptr ]= 71 ;
		    incr ( gfptr ) ;
		    if ( gfptr == gflimit ) 
		    gfswap () ;
		  } 
		  {
		    gfbuf [gfptr ]= delta ;
		    incr ( gfptr ) ;
		    if ( gfptr == gflimit ) 
		    gfswap () ;
		  } 
		} 
		else {
		    
		  {
		    gfbuf [gfptr ]= 72 ;
		    incr ( gfptr ) ;
		    if ( gfptr == gflimit ) 
		    gfswap () ;
		  } 
		  gftwo ( delta ) ;
		} 
	      } 
	      else {
		  
		delta = m - curminm ;
		if ( delta > 164 ) 
		{
		  gfbuf [gfptr ]= 70 ;
		  incr ( gfptr ) ;
		  if ( gfptr == gflimit ) 
		  gfswap () ;
		} 
		else {
		    
		  {
		    gfbuf [gfptr ]= 74 + delta ;
		    incr ( gfptr ) ;
		    if ( gfptr == gflimit ) 
		    gfswap () ;
		  } 
		  goto lab30 ;
		} 
	      } 
	      gfpaint ( m - curminm ) ;
	      lab30: prevn = n ;
	    } 
	    else gfpaint ( m - prevm ) ;
	    prevm = m ;
	    prevw = w ;
	  } 
	} 
	else if ( w <= 0 ) 
	{
	  gfpaint ( m - prevm ) ;
	  prevm = m ;
	  prevw = w ;
	} 
	m = mm ;
      } 
      w = ww ;
      q = mem [q ].hhfield .v.RH ;
    } while ( ! ( mm == 268435456L ) ) ;
    if ( w != 0 ) 
    printnl ( 1058 ) ;
    if ( prevm - mem [curedges + 3 ].hhfield .lhfield + xoff > gfmaxm ) 
    gfmaxm = prevm - mem [curedges + 3 ].hhfield .lhfield + xoff ;
    p = mem [p ].hhfield .lhfield ;
    decr ( n ) ;
  } 
  if ( prevn == 4096 ) 
  {
    gfboc ( 0 , 0 , 0 , 0 ) ;
    if ( gfmaxm < 0 ) 
    gfmaxm = 0 ;
    if ( gfminn > 0 ) 
    gfminn = 0 ;
  } 
  else if ( prevn + yoff < gfminn ) 
  gfminn = prevn + yoff ;
  {
    gfbuf [gfptr ]= 69 ;
    incr ( gfptr ) ;
    if ( gfptr == gflimit ) 
    gfswap () ;
  } 
  gfprevptr = gfoffset + gfptr ;
  incr ( totalchars ) ;
  printchar ( 93 ) ;
  fflush ( stdout ) ;
  if ( internal [11 ]> 0 ) 
  printedges ( 1057 , true , xoff , yoff ) ;
} 
void 
ztryeq ( halfword l , halfword r ) 
{
  /* 30 31 */ halfword p  ;
  unsigned char t  ;
  halfword q  ;
  halfword pp  ;
  unsigned char tt  ;
  boolean copied  ;
  t = mem [l ].hhfield .b0 ;
  if ( t == 16 ) 
  {
    t = 17 ;
    p = constdependency ( - (integer) mem [l + 1 ].cint ) ;
    q = p ;
  } 
  else if ( t == 19 ) 
  {
    t = 17 ;
    p = singledependency ( l ) ;
    mem [p + 1 ].cint = - (integer) mem [p + 1 ].cint ;
    q = depfinal ;
  } 
  else {
      
    p = mem [l + 1 ].hhfield .v.RH ;
    q = p ;
    while ( true ) {
	
      mem [q + 1 ].cint = - (integer) mem [q + 1 ].cint ;
      if ( mem [q ].hhfield .lhfield == 0 ) 
      goto lab30 ;
      q = mem [q ].hhfield .v.RH ;
    } 
    lab30: mem [mem [l + 1 ].hhfield .lhfield ].hhfield .v.RH = mem [q ]
    .hhfield .v.RH ;
    mem [mem [q ].hhfield .v.RH + 1 ].hhfield .lhfield = mem [l + 1 ]
    .hhfield .lhfield ;
    mem [l ].hhfield .b0 = 16 ;
  } 
  if ( r == 0 ) {
      
    if ( curtype == 16 ) 
    {
      mem [q + 1 ].cint = mem [q + 1 ].cint + curexp ;
      goto lab31 ;
    } 
    else {
	
      tt = curtype ;
      if ( tt == 19 ) 
      pp = singledependency ( curexp ) ;
      else pp = mem [curexp + 1 ].hhfield .v.RH ;
    } 
  } 
  else if ( mem [r ].hhfield .b0 == 16 ) 
  {
    mem [q + 1 ].cint = mem [q + 1 ].cint + mem [r + 1 ].cint ;
    goto lab31 ;
  } 
  else {
      
    tt = mem [r ].hhfield .b0 ;
    if ( tt == 19 ) 
    pp = singledependency ( r ) ;
    else pp = mem [r + 1 ].hhfield .v.RH ;
  } 
  if ( tt != 19 ) 
  copied = false ;
  else {
      
    copied = true ;
    tt = 17 ;
  } 
  watchcoefs = false ;
  if ( t == tt ) 
  p = pplusq ( p , pp , t ) ;
  else if ( t == 18 ) 
  p = pplusfq ( p , 65536L , pp , 18 , 17 ) ;
  else {
      
    q = p ;
    while ( mem [q ].hhfield .lhfield != 0 ) {
	
      mem [q + 1 ].cint = roundfraction ( mem [q + 1 ].cint ) ;
      q = mem [q ].hhfield .v.RH ;
    } 
    t = 18 ;
    p = pplusq ( p , pp , t ) ;
  } 
  watchcoefs = true ;
  if ( copied ) 
  flushnodelist ( pp ) ;
  lab31: ;
  if ( mem [p ].hhfield .lhfield == 0 ) 
  {
    if ( abs ( mem [p + 1 ].cint ) > 64 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 897 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 897 ) ;
	} 
      } 
      print ( 899 ) ;
      printscaled ( mem [p + 1 ].cint ) ;
      printchar ( 41 ) ;
      {
	helpptr = 2 ;
	helpline [1 ]= 898 ;
	helpline [0 ]= 896 ;
      } 
      putgeterror () ;
    } 
    else if ( r == 0 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 600 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 600 ) ;
	} 
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 601 ;
	helpline [0 ]= 602 ;
      } 
      putgeterror () ;
    } 
    freenode ( p , 2 ) ;
  } 
  else {
      
    lineareq ( p , t ) ;
    if ( r == 0 ) {
	
      if ( curtype != 16 ) {
	  
	if ( mem [curexp ].hhfield .b0 == 16 ) 
	{
	  pp = curexp ;
	  curexp = mem [curexp + 1 ].cint ;
	  curtype = 16 ;
	  freenode ( pp , 2 ) ;
	} 
      } 
    } 
  } 
} 
void 
zmakeeq ( halfword lhs ) 
{
  /* 20 30 45 */ smallnumber t  ;
  integer v  ;
  halfword p, q  ;
  lab20: t = mem [lhs ].hhfield .b0 ;
  if ( t <= 14 ) 
  v = mem [lhs + 1 ].cint ;
  switch ( t ) 
  {case 2 : 
  case 4 : 
  case 6 : 
  case 9 : 
  case 11 : 
    if ( curtype == t + 1 ) 
    {
      nonlineareq ( v , curexp , false ) ;
      unstashcurexp ( curexp ) ;
      goto lab30 ;
    } 
    else if ( curtype == t ) 
    {
      if ( curtype <= 4 ) 
      {
	if ( curtype == 4 ) 
	{
	  if ( strvsstr ( v , curexp ) != 0 ) 
	  goto lab45 ;
	} 
	else if ( v != curexp ) 
	goto lab45 ;
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	    {
	      printnl ( 261 ) ;
	      print ( fullsourcefilenamestack [inopen ]) ;
	      print ( 58 ) ;
	      printint ( line ) ;
	      print ( 262 ) ;
	      print ( 600 ) ;
	    } 
	    else {
		
	      printnl ( 263 ) ;
	      print ( 600 ) ;
	    } 
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 601 ;
	    helpline [0 ]= 602 ;
	  } 
	  putgeterror () ;
	} 
	goto lab30 ;
      } 
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 894 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 894 ) ;
	} 
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 895 ;
	helpline [0 ]= 896 ;
      } 
      putgeterror () ;
      goto lab30 ;
      lab45: {
	  
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 897 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 897 ) ;
	} 
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 898 ;
	helpline [0 ]= 896 ;
      } 
      putgeterror () ;
      goto lab30 ;
    } 
    break ;
  case 3 : 
  case 5 : 
  case 7 : 
  case 12 : 
  case 10 : 
    if ( curtype == t - 1 ) 
    {
      nonlineareq ( curexp , lhs , true ) ;
      goto lab30 ;
    } 
    else if ( curtype == t ) 
    {
      ringmerge ( lhs , curexp ) ;
      goto lab30 ;
    } 
    else if ( curtype == 14 ) {
	
      if ( t == 10 ) 
      {
	pairtopath () ;
	goto lab20 ;
      } 
    } 
    break ;
  case 13 : 
  case 14 : 
    if ( curtype == t ) 
    {
      p = v + bignodesize [t ];
      q = mem [curexp + 1 ].cint + bignodesize [t ];
      do {
	  p = p - 2 ;
	q = q - 2 ;
	tryeq ( p , q ) ;
      } while ( ! ( p == v ) ) ;
      goto lab30 ;
    } 
    break ;
  case 16 : 
  case 17 : 
  case 18 : 
  case 19 : 
    if ( curtype >= 16 ) 
    {
      tryeq ( lhs , 0 ) ;
      goto lab30 ;
    } 
    break ;
  case 1 : 
    ;
    break ;
  } 
  disperr ( lhs , 261 ) ;
  disperr ( 0 , 891 ) ;
  if ( mem [lhs ].hhfield .b0 <= 14 ) 
  printtype ( mem [lhs ].hhfield .b0 ) ;
  else print ( 340 ) ;
  printchar ( 61 ) ;
  if ( curtype <= 14 ) 
  printtype ( curtype ) ;
  else print ( 340 ) ;
  printchar ( 41 ) ;
  {
    helpptr = 2 ;
    helpline [1 ]= 892 ;
    helpline [0 ]= 893 ;
  } 
  putgeterror () ;
  lab30: {
      
    if ( aritherror ) 
    cleararith () ;
  } 
  recyclevalue ( lhs ) ;
  freenode ( lhs , 2 ) ;
} 
void 
doequation ( void ) 
{
  halfword lhs  ;
  halfword p  ;
  lhs = stashcurexp () ;
  getxnext () ;
  varflag = 77 ;
  scanexpression () ;
  if ( curcmd == 51 ) 
  doequation () ;
  else if ( curcmd == 77 ) 
  doassignment () ;
  if ( internal [7 ]> 131072L ) 
  {
    begindiagnostic () ;
    printnl ( 850 ) ;
    printexp ( lhs , 0 ) ;
    print ( 886 ) ;
    printexp ( 0 , 0 ) ;
    print ( 842 ) ;
    enddiagnostic ( false ) ;
  } 
  if ( curtype == 10 ) {
      
    if ( mem [lhs ].hhfield .b0 == 14 ) 
    {
      p = stashcurexp () ;
      unstashcurexp ( lhs ) ;
      lhs = p ;
    } 
  } 
  makeeq ( lhs ) ;
} 
void 
doassignment ( void ) 
{
  halfword lhs  ;
  halfword p  ;
  halfword q  ;
  if ( curtype != 20 ) 
  {
    disperr ( 0 , 883 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 884 ;
      helpline [0 ]= 885 ;
    } 
    error () ;
    doequation () ;
  } 
  else {
      
    lhs = curexp ;
    curtype = 1 ;
    getxnext () ;
    varflag = 77 ;
    scanexpression () ;
    if ( curcmd == 51 ) 
    doequation () ;
    else if ( curcmd == 77 ) 
    doassignment () ;
    if ( internal [7 ]> 131072L ) 
    {
      begindiagnostic () ;
      printnl ( 123 ) ;
      if ( mem [lhs ].hhfield .lhfield > 9769 ) 
      slowprint ( intname [mem [lhs ].hhfield .lhfield - ( 9769 ) ]) ;
      else showtokenlist ( lhs , 0 , 1000 , 0 ) ;
      print ( 461 ) ;
      printexp ( 0 , 0 ) ;
      printchar ( 125 ) ;
      enddiagnostic ( false ) ;
    } 
    if ( mem [lhs ].hhfield .lhfield > 9769 ) {
	
      if ( curtype == 16 ) 
      internal [mem [lhs ].hhfield .lhfield - ( 9769 ) ]= curexp ;
      else {
	  
	disperr ( 0 , 887 ) ;
	slowprint ( intname [mem [lhs ].hhfield .lhfield - ( 9769 ) ]) ;
	print ( 888 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 889 ;
	  helpline [0 ]= 890 ;
	} 
	putgeterror () ;
      } 
    } 
    else {
	
      p = findvariable ( lhs ) ;
      if ( p != 0 ) 
      {
	q = stashcurexp () ;
	curtype = undtype ( p ) ;
	recyclevalue ( p ) ;
	mem [p ].hhfield .b0 = curtype ;
	mem [p + 1 ].cint = 0 ;
	makeexpcopy ( p ) ;
	p = stashcurexp () ;
	unstashcurexp ( q ) ;
	makeeq ( p ) ;
      } 
      else {
	  
	obliterated ( lhs ) ;
	putgeterror () ;
      } 
    } 
    flushnodelist ( lhs ) ;
  } 
} 
void 
dotypedeclaration ( void ) 
{
  smallnumber t  ;
  halfword p  ;
  halfword q  ;
  if ( curmod >= 13 ) 
  t = curmod ;
  else t = curmod + 1 ;
  do {
      p = scandeclaredvariable () ;
    flushvariable ( eqtb [mem [p ].hhfield .lhfield ].v.RH , mem [p ]
    .hhfield .v.RH , false ) ;
    q = findvariable ( p ) ;
    if ( q != 0 ) 
    {
      mem [q ].hhfield .b0 = t ;
      mem [q + 1 ].cint = 0 ;
    } 
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 900 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 900 ) ;
	} 
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 901 ;
	helpline [0 ]= 902 ;
      } 
      putgeterror () ;
    } 
    flushlist ( p ) ;
    if ( curcmd < 82 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 903 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 903 ) ;
	} 
      } 
      {
	helpptr = 5 ;
	helpline [4 ]= 904 ;
	helpline [3 ]= 905 ;
	helpline [2 ]= 906 ;
	helpline [1 ]= 907 ;
	helpline [0 ]= 908 ;
      } 
      if ( curcmd == 42 ) 
      helpline [2 ]= 909 ;
      putgeterror () ;
      scannerstatus = 2 ;
      do {
	  getnext () ;
	if ( curcmd == 39 ) 
	{
	  if ( strref [curmod ]< 127 ) {
	      
	    if ( strref [curmod ]> 1 ) 
	    decr ( strref [curmod ]) ;
	    else flushstring ( curmod ) ;
	  } 
	} 
      } while ( ! ( curcmd >= 82 ) ) ;
      scannerstatus = 0 ;
    } 
  } while ( ! ( curcmd > 82 ) ) ;
} 
void 
dorandomseed ( void ) 
{
  getxnext () ;
  if ( curcmd != 77 ) 
  {
    missingerr ( 461 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 914 ;
    } 
    backerror () ;
  } 
  getxnext () ;
  scanexpression () ;
  if ( curtype != 16 ) 
  {
    disperr ( 0 , 915 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 916 ;
      helpline [0 ]= 917 ;
    } 
    putgetflusherror ( 0 ) ;
  } 
  else {
      
    initrandoms ( curexp ) ;
    if ( selector >= 2 ) 
    {
      oldsetting = selector ;
      selector = 2 ;
      printnl ( 918 ) ;
      printscaled ( curexp ) ;
      printchar ( 125 ) ;
      printnl ( 261 ) ;
      selector = oldsetting ;
    } 
  } 
} 
void 
doprotection ( void ) 
{
  unsigned char m  ;
  halfword t  ;
  m = curmod ;
  do {
      getsymbol () ;
    t = eqtb [cursym ].lhfield ;
    if ( m == 0 ) 
    {
      if ( t >= 86 ) 
      eqtb [cursym ].lhfield = t - 86 ;
    } 
    else if ( t < 86 ) 
    eqtb [cursym ].lhfield = t + 86 ;
    getxnext () ;
  } while ( ! ( curcmd != 82 ) ) ;
} 
void 
defdelims ( void ) 
{
  halfword ldelim, rdelim  ;
  getclearsymbol () ;
  ldelim = cursym ;
  getclearsymbol () ;
  rdelim = cursym ;
  eqtb [ldelim ].lhfield = 31 ;
  eqtb [ldelim ].v.RH = rdelim ;
  eqtb [rdelim ].lhfield = 62 ;
  eqtb [rdelim ].v.RH = ldelim ;
  getxnext () ;
} 
void 
dointerim ( void ) 
{
  getxnext () ;
  if ( curcmd != 40 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 924 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 924 ) ;
      } 
    } 
    if ( cursym == 0 ) 
    print ( 929 ) ;
    else slowprint ( hash [cursym ].v.RH ) ;
    print ( 930 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 931 ;
    } 
    backerror () ;
  } 
  else {
      
    saveinternal ( curmod ) ;
    backinput () ;
  } 
  dostatement () ;
} 
void 
dolet ( void ) 
{
  halfword l  ;
  getsymbol () ;
  l = cursym ;
  getxnext () ;
  if ( curcmd != 51 ) {
      
    if ( curcmd != 77 ) 
    {
      missingerr ( 61 ) ;
      {
	helpptr = 3 ;
	helpline [2 ]= 932 ;
	helpline [1 ]= 673 ;
	helpline [0 ]= 933 ;
      } 
      backerror () ;
    } 
  } 
  getsymbol () ;
  switch ( curcmd ) 
  {case 10 : 
  case 53 : 
  case 44 : 
  case 49 : 
    incr ( mem [curmod ].hhfield .lhfield ) ;
    break ;
    default: 
    ;
    break ;
  } 
  clearsymbol ( l , false ) ;
  eqtb [l ].lhfield = curcmd ;
  if ( curcmd == 41 ) 
  eqtb [l ].v.RH = 0 ;
  else eqtb [l ].v.RH = curmod ;
  getxnext () ;
} 
void 
donewinternal ( void ) 
{
  do {
      if ( intptr == maxinternal ) 
    overflow ( 934 , maxinternal ) ;
    getclearsymbol () ;
    incr ( intptr ) ;
    eqtb [cursym ].lhfield = 40 ;
    eqtb [cursym ].v.RH = intptr ;
    intname [intptr ]= hash [cursym ].v.RH ;
    internal [intptr ]= 0 ;
    getxnext () ;
  } while ( ! ( curcmd != 82 ) ) ;
} 
void 
doshow ( void ) 
{
  do {
      getxnext () ;
    scanexpression () ;
    printnl ( 765 ) ;
    printexp ( 0 , 2 ) ;
    flushcurexp ( 0 ) ;
  } while ( ! ( curcmd != 82 ) ) ;
} 
void 
disptoken ( void ) 
{
  printnl ( 940 ) ;
  if ( cursym == 0 ) 
  {
    if ( curcmd == 42 ) 
    printscaled ( curmod ) ;
    else if ( curcmd == 38 ) 
    {
      gpointer = curmod ;
      printcapsule () ;
    } 
    else {
	
      printchar ( 34 ) ;
      slowprint ( curmod ) ;
      printchar ( 34 ) ;
      {
	if ( strref [curmod ]< 127 ) {
	    
	  if ( strref [curmod ]> 1 ) 
	  decr ( strref [curmod ]) ;
	  else flushstring ( curmod ) ;
	} 
      } 
    } 
  } 
  else {
      
    slowprint ( hash [cursym ].v.RH ) ;
    printchar ( 61 ) ;
    if ( eqtb [cursym ].lhfield >= 86 ) 
    print ( 941 ) ;
    printcmdmod ( curcmd , curmod ) ;
    if ( curcmd == 10 ) 
    {
      println () ;
      showmacro ( curmod , 0 , 100000L ) ;
    } 
  } 
} 
void 
doshowtoken ( void ) 
{
  do {
      getnext () ;
    disptoken () ;
    getxnext () ;
  } while ( ! ( curcmd != 82 ) ) ;
} 
void 
doshowstats ( void ) 
{
  printnl ( 950 ) ;
	;
#ifdef STAT
  printint ( varused ) ;
  printchar ( 38 ) ;
  printint ( dynused ) ;
  if ( false ) 
#endif /* STAT */
  print ( 357 ) ;
  print ( 558 ) ;
  printint ( himemmin - lomemmax - 1 ) ;
  print ( 951 ) ;
  println () ;
  printnl ( 952 ) ;
  printint ( strptr - initstrptr ) ;
  printchar ( 38 ) ;
  printint ( poolptr - initpoolptr ) ;
  print ( 558 ) ;
  printint ( maxstrings - maxstrptr ) ;
  printchar ( 38 ) ;
  printint ( poolsize - maxpoolptr ) ;
  print ( 951 ) ;
  println () ;
  getxnext () ;
} 
void 
zdispvar ( halfword p ) 
{
  halfword q  ;
  integer n  ;
  if ( mem [p ].hhfield .b0 == 21 ) 
  {
    q = mem [p + 1 ].hhfield .lhfield ;
    do {
	dispvar ( q ) ;
      q = mem [q ].hhfield .v.RH ;
    } while ( ! ( q == 17 ) ) ;
    q = mem [p + 1 ].hhfield .v.RH ;
    while ( mem [q ].hhfield .b1 == 3 ) {
	
      dispvar ( q ) ;
      q = mem [q ].hhfield .v.RH ;
    } 
  } 
  else if ( mem [p ].hhfield .b0 >= 22 ) 
  {
    printnl ( 261 ) ;
    printvariablename ( p ) ;
    if ( mem [p ].hhfield .b0 > 22 ) 
    print ( 665 ) ;
    print ( 953 ) ;
    if ( fileoffset >= maxprintline - 20 ) 
    n = 5 ;
    else n = maxprintline - fileoffset - 15 ;
    showmacro ( mem [p + 1 ].cint , 0 , n ) ;
  } 
  else if ( mem [p ].hhfield .b0 != 0 ) 
  {
    printnl ( 261 ) ;
    printvariablename ( p ) ;
    printchar ( 61 ) ;
    printexp ( p , 0 ) ;
  } 
} 
void 
doshowvar ( void ) 
{
  /* 30 */ do {
      getnext () ;
    if ( cursym > 0 ) {
	
      if ( cursym <= 9769 ) {
	  
	if ( curcmd == 41 ) {
	    
	  if ( curmod != 0 ) 
	  {
	    dispvar ( curmod ) ;
	    goto lab30 ;
	  } 
	} 
      } 
    } 
    disptoken () ;
    lab30: getxnext () ;
  } while ( ! ( curcmd != 82 ) ) ;
} 
void 
doshowdependencies ( void ) 
{
  halfword p  ;
  p = mem [13 ].hhfield .v.RH ;
  while ( p != 13 ) {
      
    if ( interesting ( p ) ) 
    {
      printnl ( 261 ) ;
      printvariablename ( p ) ;
      if ( mem [p ].hhfield .b0 == 17 ) 
      printchar ( 61 ) ;
      else print ( 768 ) ;
      printdependency ( mem [p + 1 ].hhfield .v.RH , mem [p ].hhfield .b0 
      ) ;
    } 
    p = mem [p + 1 ].hhfield .v.RH ;
    while ( mem [p ].hhfield .lhfield != 0 ) p = mem [p ].hhfield .v.RH ;
    p = mem [p ].hhfield .v.RH ;
  } 
  getxnext () ;
} 
void 
doshowwhatever ( void ) 
{
  if ( interaction == 3 ) 
  ;
  switch ( curmod ) 
  {case 0 : 
    doshowtoken () ;
    break ;
  case 1 : 
    doshowstats () ;
    break ;
  case 2 : 
    doshow () ;
    break ;
  case 3 : 
    doshowvar () ;
    break ;
  case 4 : 
    doshowdependencies () ;
    break ;
  } 
  if ( internal [32 ]> 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 954 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 954 ) ;
      } 
    } 
    if ( interaction < 3 ) 
    {
      helpptr = 0 ;
      decr ( errorcount ) ;
    } 
    else {
	
      helpptr = 1 ;
      helpline [0 ]= 955 ;
    } 
    if ( curcmd == 83 ) 
    error () ;
    else putgeterror () ;
  } 
} 
boolean 
scanwith ( void ) 
{
  register boolean Result; smallnumber t  ;
  boolean result  ;
  t = curmod ;
  curtype = 1 ;
  getxnext () ;
  scanexpression () ;
  result = false ;
  if ( curtype != t ) 
  {
    disperr ( 0 , 963 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 964 ;
      helpline [0 ]= 965 ;
    } 
    if ( t == 6 ) 
    helpline [1 ]= 966 ;
    putgetflusherror ( 0 ) ;
  } 
  else if ( curtype == 6 ) 
  result = true ;
  else {
      
    curexp = roundunscaled ( curexp ) ;
    if ( ( abs ( curexp ) < 4 ) && ( curexp != 0 ) ) 
    result = true ;
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 967 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 967 ) ;
	} 
      } 
      {
	helpptr = 1 ;
	helpline [0 ]= 965 ;
      } 
      putgetflusherror ( 0 ) ;
    } 
  } 
  Result = result ;
  return Result ;
} 
void 
zfindedgesvar ( halfword t ) 
{
  halfword p  ;
  p = findvariable ( t ) ;
  curedges = 0 ;
  if ( p == 0 ) 
  {
    obliterated ( t ) ;
    putgeterror () ;
  } 
  else if ( mem [p ].hhfield .b0 != 11 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 790 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 790 ) ;
      } 
    } 
    showtokenlist ( t , 0 , 1000 , 0 ) ;
    print ( 968 ) ;
    printtype ( mem [p ].hhfield .b0 ) ;
    printchar ( 41 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 969 ;
      helpline [0 ]= 970 ;
    } 
    putgeterror () ;
  } 
  else curedges = mem [p + 1 ].cint ;
  flushnodelist ( t ) ;
} 
void 
doaddto ( void ) 
{
  /* 30 45 */ halfword lhs, rhs  ;
  integer w  ;
  halfword p  ;
  halfword q  ;
  unsigned char addtotype  ;
  getxnext () ;
  varflag = 68 ;
  scanprimary () ;
  if ( curtype != 20 ) 
  {
    disperr ( 0 , 971 ) ;
    {
      helpptr = 4 ;
      helpline [3 ]= 972 ;
      helpline [2 ]= 973 ;
      helpline [1 ]= 974 ;
      helpline [0 ]= 970 ;
    } 
    putgetflusherror ( 0 ) ;
  } 
  else {
      
    lhs = curexp ;
    addtotype = curmod ;
    curtype = 1 ;
    getxnext () ;
    scanexpression () ;
    if ( addtotype == 2 ) 
    {
      findedgesvar ( lhs ) ;
      if ( curedges == 0 ) 
      flushcurexp ( 0 ) ;
      else if ( curtype != 11 ) 
      {
	disperr ( 0 , 975 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 976 ;
	  helpline [0 ]= 970 ;
	} 
	putgetflusherror ( 0 ) ;
      } 
      else {
	  
	mergeedges ( curexp ) ;
	flushcurexp ( 0 ) ;
      } 
    } 
    else {
	
      if ( curtype == 14 ) 
      pairtopath () ;
      if ( curtype != 9 ) 
      {
	disperr ( 0 , 975 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 977 ;
	  helpline [0 ]= 970 ;
	} 
	putgetflusherror ( 0 ) ;
	flushtokenlist ( lhs ) ;
      } 
      else {
	  
	rhs = curexp ;
	w = 1 ;
	curpen = 3 ;
	while ( curcmd == 66 ) if ( scanwith () ) {
	    
	  if ( curtype == 16 ) 
	  w = curexp ;
	  else {
	      
	    if ( mem [curpen ].hhfield .lhfield == 0 ) 
	    tosspen ( curpen ) ;
	    else decr ( mem [curpen ].hhfield .lhfield ) ;
	    curpen = curexp ;
	  } 
	} 
	findedgesvar ( lhs ) ;
	if ( curedges == 0 ) 
	tossknotlist ( rhs ) ;
	else {
	    
	  lhs = 0 ;
	  curpathtype = addtotype ;
	  if ( mem [rhs ].hhfield .b0 == 0 ) {
	      
	    if ( curpathtype == 0 ) {
		
	      if ( mem [rhs ].hhfield .v.RH == rhs ) 
	      {
		mem [rhs + 5 ].cint = mem [rhs + 1 ].cint ;
		mem [rhs + 6 ].cint = mem [rhs + 2 ].cint ;
		mem [rhs + 3 ].cint = mem [rhs + 1 ].cint ;
		mem [rhs + 4 ].cint = mem [rhs + 2 ].cint ;
		mem [rhs ].hhfield .b0 = 1 ;
		mem [rhs ].hhfield .b1 = 1 ;
	      } 
	      else {
		  
		p = htapypoc ( rhs ) ;
		q = mem [p ].hhfield .v.RH ;
		mem [pathtail + 5 ].cint = mem [q + 5 ].cint ;
		mem [pathtail + 6 ].cint = mem [q + 6 ].cint ;
		mem [pathtail ].hhfield .b1 = mem [q ].hhfield .b1 ;
		mem [pathtail ].hhfield .v.RH = mem [q ].hhfield .v.RH ;
		freenode ( q , 7 ) ;
		mem [p + 5 ].cint = mem [rhs + 5 ].cint ;
		mem [p + 6 ].cint = mem [rhs + 6 ].cint ;
		mem [p ].hhfield .b1 = mem [rhs ].hhfield .b1 ;
		mem [p ].hhfield .v.RH = mem [rhs ].hhfield .v.RH ;
		freenode ( rhs , 7 ) ;
		rhs = p ;
	      } 
	    } 
	    else {
		
	      {
		if ( interaction == 3 ) 
		;
		if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) 
		) 
		{
		  printnl ( 261 ) ;
		  print ( fullsourcefilenamestack [inopen ]) ;
		  print ( 58 ) ;
		  printint ( line ) ;
		  print ( 262 ) ;
		  print ( 978 ) ;
		} 
		else {
		    
		  printnl ( 263 ) ;
		  print ( 978 ) ;
		} 
	      } 
	      {
		helpptr = 2 ;
		helpline [1 ]= 979 ;
		helpline [0 ]= 970 ;
	      } 
	      putgeterror () ;
	      tossknotlist ( rhs ) ;
	      goto lab45 ;
	    } 
	  } 
	  else if ( curpathtype == 0 ) 
	  lhs = htapypoc ( rhs ) ;
	  curwt = w ;
	  rhs = makespec ( rhs , mem [curpen + 9 ].cint , internal [5 ]) ;
	  if ( turningnumber <= 0 ) {
	      
	    if ( curpathtype != 0 ) {
		
	      if ( internal [39 ]> 0 ) {
		  
		if ( ( turningnumber < 0 ) && ( mem [curpen ].hhfield .v.RH 
		== 0 ) ) 
		curwt = - (integer) curwt ;
		else {
		    
		  if ( turningnumber == 0 ) {
		      
		    if ( ( internal [39 ]<= 65536L ) && ( mem [curpen ]
		    .hhfield .v.RH == 0 ) ) 
		    goto lab30 ;
		    else printstrange ( 980 ) ;
		  } 
		  else printstrange ( 981 ) ;
		  {
		    helpptr = 3 ;
		    helpline [2 ]= 982 ;
		    helpline [1 ]= 983 ;
		    helpline [0 ]= 984 ;
		  } 
		  putgeterror () ;
		} 
	      } 
	    } 
	  } 
	  lab30: ;
	  if ( mem [curpen + 9 ].cint == 0 ) 
	  fillspec ( rhs ) ;
	  else fillenvelope ( rhs ) ;
	  if ( lhs != 0 ) 
	  {
	    revturns = true ;
	    lhs = makespec ( lhs , mem [curpen + 9 ].cint , internal [5 ]) 
	    ;
	    revturns = false ;
	    if ( mem [curpen + 9 ].cint == 0 ) 
	    fillspec ( lhs ) ;
	    else fillenvelope ( lhs ) ;
	  } 
	  lab45: ;
	} 
	if ( mem [curpen ].hhfield .lhfield == 0 ) 
	tosspen ( curpen ) ;
	else decr ( mem [curpen ].hhfield .lhfield ) ;
      } 
    } 
  } 
} 
scaled 
ztfmcheck ( smallnumber m ) 
{
  register scaled Result; if ( abs ( internal [m ]) >= 134217728L ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 1001 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 1001 ) ;
      } 
    } 
    print ( intname [m ]) ;
    print ( 1002 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 1003 ;
    } 
    putgeterror () ;
    if ( internal [m ]> 0 ) 
    Result = 134217727L ;
    else Result = -134217727L ;
  } 
  else Result = internal [m ];
  return Result ;
} 
void 
doshipout ( void ) 
{
  /* 10 */ integer c  ;
  getxnext () ;
  varflag = 83 ;
  scanexpression () ;
  if ( curtype != 20 ) {
      
    if ( curtype == 11 ) 
    curedges = curexp ;
    else {
	
      {
	disperr ( 0 , 971 ) ;
	{
	  helpptr = 4 ;
	  helpline [3 ]= 972 ;
	  helpline [2 ]= 973 ;
	  helpline [1 ]= 974 ;
	  helpline [0 ]= 970 ;
	} 
	putgetflusherror ( 0 ) ;
      } 
      goto lab10 ;
    } 
  } 
  else {
      
    findedgesvar ( curexp ) ;
    curtype = 1 ;
  } 
  if ( curedges != 0 ) 
  {
    c = roundunscaled ( internal [18 ]) % 256 ;
    if ( c < 0 ) 
    c = c + 256 ;
    if ( c < bc ) 
    bc = c ;
    if ( c > ec ) 
    ec = c ;
    charexists [c ]= true ;
    gfdx [c ]= internal [24 ];
    gfdy [c ]= internal [25 ];
    tfmwidth [c ]= tfmcheck ( 20 ) ;
    tfmheight [c ]= tfmcheck ( 21 ) ;
    tfmdepth [c ]= tfmcheck ( 22 ) ;
    tfmitalcorr [c ]= tfmcheck ( 23 ) ;
    if ( internal [34 ]>= 0 ) 
    shipout ( c ) ;
  } 
  flushcurexp ( 0 ) ;
  lab10: ;
} 
void 
dodisplay ( void ) 
{
  /* 45 50 10 */ halfword e  ;
  getxnext () ;
  varflag = 73 ;
  scanprimary () ;
  if ( curtype != 20 ) 
  {
    disperr ( 0 , 971 ) ;
    {
      helpptr = 4 ;
      helpline [3 ]= 972 ;
      helpline [2 ]= 973 ;
      helpline [1 ]= 974 ;
      helpline [0 ]= 970 ;
    } 
    putgetflusherror ( 0 ) ;
  } 
  else {
      
    e = curexp ;
    curtype = 1 ;
    getxnext () ;
    scanexpression () ;
    if ( curtype != 16 ) 
    goto lab50 ;
    curexp = roundunscaled ( curexp ) ;
    if ( curexp < 0 ) 
    goto lab45 ;
    if ( curexp > 15 ) 
    goto lab45 ;
    if ( ! windowopen [curexp ]) 
    goto lab45 ;
    findedgesvar ( e ) ;
    if ( curedges != 0 ) 
    dispedges ( curexp ) ;
    goto lab10 ;
    lab45: curexp = curexp * 65536L ;
    lab50: disperr ( 0 , 985 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 986 ;
    } 
    putgetflusherror ( 0 ) ;
    flushtokenlist ( e ) ;
  } 
  lab10: ;
} 
boolean 
zgetpair ( commandcode c ) 
{
  register boolean Result; halfword p  ;
  boolean b  ;
  if ( curcmd != c ) 
  Result = false ;
  else {
      
    getxnext () ;
    scanexpression () ;
    if ( nicepair ( curexp , curtype ) ) 
    {
      p = mem [curexp + 1 ].cint ;
      curx = mem [p + 1 ].cint ;
      cury = mem [p + 3 ].cint ;
      b = true ;
    } 
    else b = false ;
    flushcurexp ( 0 ) ;
    Result = b ;
  } 
  return Result ;
} 
void 
doopenwindow ( void ) 
{
  /* 45 10 */ integer k  ;
  scaled r0, c0, r1, c1  ;
  getxnext () ;
  scanexpression () ;
  if ( curtype != 16 ) 
  goto lab45 ;
  k = roundunscaled ( curexp ) ;
  if ( k < 0 ) 
  goto lab45 ;
  if ( k > 15 ) 
  goto lab45 ;
  if ( ! getpair ( 70 ) ) 
  goto lab45 ;
  r0 = curx ;
  c0 = cury ;
  if ( ! getpair ( 71 ) ) 
  goto lab45 ;
  r1 = curx ;
  c1 = cury ;
  if ( ! getpair ( 72 ) ) 
  goto lab45 ;
  openawindow ( k , r0 , c0 , r1 , c1 , curx , cury ) ;
  goto lab10 ;
  lab45: {
      
    if ( interaction == 3 ) 
    ;
    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
    {
      printnl ( 261 ) ;
      print ( fullsourcefilenamestack [inopen ]) ;
      print ( 58 ) ;
      printint ( line ) ;
      print ( 262 ) ;
      print ( 987 ) ;
    } 
    else {
	
      printnl ( 263 ) ;
      print ( 987 ) ;
    } 
  } 
  {
    helpptr = 2 ;
    helpline [1 ]= 988 ;
    helpline [0 ]= 989 ;
  } 
  putgeterror () ;
  lab10: ;
} 
void 
docull ( void ) 
{
  /* 45 10 */ halfword e  ;
  unsigned char keeping  ;
  integer w, win, wout  ;
  w = 1 ;
  getxnext () ;
  varflag = 67 ;
  scanprimary () ;
  if ( curtype != 20 ) 
  {
    disperr ( 0 , 971 ) ;
    {
      helpptr = 4 ;
      helpline [3 ]= 972 ;
      helpline [2 ]= 973 ;
      helpline [1 ]= 974 ;
      helpline [0 ]= 970 ;
    } 
    putgetflusherror ( 0 ) ;
  } 
  else {
      
    e = curexp ;
    curtype = 1 ;
    keeping = curmod ;
    if ( ! getpair ( 67 ) ) 
    goto lab45 ;
    while ( ( curcmd == 66 ) && ( curmod == 16 ) ) if ( scanwith () ) 
    w = curexp ;
    if ( curx > cury ) 
    goto lab45 ;
    if ( keeping == 0 ) 
    {
      if ( ( curx > 0 ) || ( cury < 0 ) ) 
      goto lab45 ;
      wout = w ;
      win = 0 ;
    } 
    else {
	
      if ( ( curx <= 0 ) && ( cury >= 0 ) ) 
      goto lab45 ;
      wout = 0 ;
      win = w ;
    } 
    findedgesvar ( e ) ;
    if ( curedges != 0 ) 
    culledges ( floorunscaled ( curx + 65535L ) , floorunscaled ( cury ) , 
    wout , win ) ;
    goto lab10 ;
    lab45: {
	
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 990 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 990 ) ;
      } 
    } 
    {
      helpptr = 1 ;
      helpline [0 ]= 991 ;
    } 
    putgeterror () ;
    flushtokenlist ( e ) ;
  } 
  lab10: ;
} 
void 
domessage ( void ) 
{
  unsigned char m  ;
  m = curmod ;
  getxnext () ;
  scanexpression () ;
  if ( curtype != 4 ) 
  {
    disperr ( 0 , 700 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 995 ;
    } 
    putgeterror () ;
  } 
  else switch ( m ) 
  {case 0 : 
    {
      printnl ( 261 ) ;
      slowprint ( curexp ) ;
    } 
    break ;
  case 1 : 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 261 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 261 ) ;
	} 
      } 
      slowprint ( curexp ) ;
      if ( errhelp != 0 ) 
      useerrhelp = true ;
      else if ( longhelpseen ) 
      {
	helpptr = 1 ;
	helpline [0 ]= 996 ;
      } 
      else {
	  
	if ( interaction < 3 ) 
	longhelpseen = true ;
	{
	  helpptr = 4 ;
	  helpline [3 ]= 997 ;
	  helpline [2 ]= 998 ;
	  helpline [1 ]= 999 ;
	  helpline [0 ]= 1000 ;
	} 
      } 
      putgeterror () ;
      useerrhelp = false ;
    } 
    break ;
  case 2 : 
    {
      if ( errhelp != 0 ) 
      {
	if ( strref [errhelp ]< 127 ) {
	    
	  if ( strref [errhelp ]> 1 ) 
	  decr ( strref [errhelp ]) ;
	  else flushstring ( errhelp ) ;
	} 
      } 
      if ( ( strstart [curexp + 1 ]- strstart [curexp ]) == 0 ) 
      errhelp = 0 ;
      else {
	  
	errhelp = curexp ;
	{
	  if ( strref [errhelp ]< 127 ) 
	  incr ( strref [errhelp ]) ;
	} 
      } 
    } 
    break ;
  } 
  flushcurexp ( 0 ) ;
} 
eightbits 
getcode ( void ) 
{
  /* 40 */ register eightbits Result; integer c  ;
  getxnext () ;
  scanexpression () ;
  if ( curtype == 16 ) 
  {
    c = roundunscaled ( curexp ) ;
    if ( c >= 0 ) {
	
      if ( c < 256 ) 
      goto lab40 ;
    } 
  } 
  else if ( curtype == 4 ) {
      
    if ( ( strstart [curexp + 1 ]- strstart [curexp ]) == 1 ) 
    {
      c = strpool [strstart [curexp ]];
      goto lab40 ;
    } 
  } 
  disperr ( 0 , 1009 ) ;
  {
    helpptr = 2 ;
    helpline [1 ]= 1010 ;
    helpline [0 ]= 1011 ;
  } 
  putgetflusherror ( 0 ) ;
  c = 0 ;
  lab40: Result = c ;
  return Result ;
} 
void 
zsettag ( halfword c , smallnumber t , halfword r ) 
{
  if ( chartag [c ]== 0 ) 
  {
    chartag [c ]= t ;
    charremainder [c ]= r ;
    if ( t == 1 ) 
    {
      incr ( labelptr ) ;
      labelloc [labelptr ]= r ;
      labelchar [labelptr ]= c ;
    } 
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 1012 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 1012 ) ;
      } 
    } 
    if ( ( c > 32 ) && ( c < 127 ) ) 
    print ( c ) ;
    else if ( c == 256 ) 
    print ( 1013 ) ;
    else {
	
      print ( 1014 ) ;
      printint ( c ) ;
    } 
    print ( 1015 ) ;
    switch ( chartag [c ]) 
    {case 1 : 
      print ( 1016 ) ;
      break ;
    case 2 : 
      print ( 1017 ) ;
      break ;
    case 3 : 
      print ( 1006 ) ;
      break ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 1018 ;
      helpline [0 ]= 970 ;
    } 
    putgeterror () ;
  } 
} 
void 
dotfmcommand ( void ) 
{
  /* 22 30 */ short c, cc  ;
  integer k  ;
  integer j  ;
  switch ( curmod ) 
  {case 0 : 
    {
      c = getcode () ;
      while ( curcmd == 81 ) {
	  
	cc = getcode () ;
	settag ( c , 2 , cc ) ;
	c = cc ;
      } 
    } 
    break ;
  case 1 : 
    {
      lkstarted = false ;
      lab22: getxnext () ;
      if ( ( curcmd == 78 ) && lkstarted ) 
      {
	c = getcode () ;
	if ( nl - skiptable [c ]> 128 ) 
	{
	  {
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	      {
		printnl ( 261 ) ;
		print ( fullsourcefilenamestack [inopen ]) ;
		print ( 58 ) ;
		printint ( line ) ;
		print ( 262 ) ;
		print ( 1035 ) ;
	      } 
	      else {
		  
		printnl ( 263 ) ;
		print ( 1035 ) ;
	      } 
	    } 
	    {
	      helpptr = 1 ;
	      helpline [0 ]= 1036 ;
	    } 
	    error () ;
	    ll = skiptable [c ];
	    do {
		lll = ligkern [ll ].b0 ;
	      ligkern [ll ].b0 = 128 ;
	      ll = ll - lll ;
	    } while ( ! ( lll == 0 ) ) ;
	  } 
	  skiptable [c ]= ligtablesize ;
	} 
	if ( skiptable [c ]== ligtablesize ) 
	ligkern [nl - 1 ].b0 = 0 ;
	else ligkern [nl - 1 ].b0 = nl - skiptable [c ]- 1 ;
	skiptable [c ]= nl - 1 ;
	goto lab30 ;
      } 
      if ( curcmd == 79 ) 
      {
	c = 256 ;
	curcmd = 81 ;
      } 
      else {
	  
	backinput () ;
	c = getcode () ;
      } 
      if ( ( curcmd == 81 ) || ( curcmd == 80 ) ) 
      {
	if ( curcmd == 81 ) {
	    
	  if ( c == 256 ) 
	  bchlabel = nl ;
	  else settag ( c , 1 , nl ) ;
	} 
	else if ( skiptable [c ]< ligtablesize ) 
	{
	  ll = skiptable [c ];
	  skiptable [c ]= ligtablesize ;
	  do {
	      lll = ligkern [ll ].b0 ;
	    if ( nl - ll > 128 ) 
	    {
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) 
		  ) ) 
		  {
		    printnl ( 261 ) ;
		    print ( fullsourcefilenamestack [inopen ]) ;
		    print ( 58 ) ;
		    printint ( line ) ;
		    print ( 262 ) ;
		    print ( 1035 ) ;
		  } 
		  else {
		      
		    printnl ( 263 ) ;
		    print ( 1035 ) ;
		  } 
		} 
		{
		  helpptr = 1 ;
		  helpline [0 ]= 1036 ;
		} 
		error () ;
		ll = ll ;
		do {
		    lll = ligkern [ll ].b0 ;
		  ligkern [ll ].b0 = 128 ;
		  ll = ll - lll ;
		} while ( ! ( lll == 0 ) ) ;
	      } 
	      goto lab22 ;
	    } 
	    ligkern [ll ].b0 = nl - ll - 1 ;
	    ll = ll - lll ;
	  } while ( ! ( lll == 0 ) ) ;
	} 
	goto lab22 ;
      } 
      if ( curcmd == 76 ) 
      {
	ligkern [nl ].b1 = c ;
	ligkern [nl ].b0 = 0 ;
	if ( curmod < 128 ) 
	{
	  ligkern [nl ].b2 = curmod ;
	  ligkern [nl ].b3 = getcode () ;
	} 
	else {
	    
	  getxnext () ;
	  scanexpression () ;
	  if ( curtype != 16 ) 
	  {
	    disperr ( 0 , 1037 ) ;
	    {
	      helpptr = 2 ;
	      helpline [1 ]= 1038 ;
	      helpline [0 ]= 308 ;
	    } 
	    putgetflusherror ( 0 ) ;
	  } 
	  kern [nk ]= curexp ;
	  k = 0 ;
	  while ( kern [k ]!= curexp ) incr ( k ) ;
	  if ( k == nk ) 
	  {
	    if ( nk == maxkerns ) 
	    overflow ( 1034 , maxkerns ) ;
	    incr ( nk ) ;
	  } 
	  ligkern [nl ].b2 = 128 + ( k / 256 ) ;
	  ligkern [nl ].b3 = ( k % 256 ) ;
	} 
	lkstarted = true ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	  {
	    printnl ( 261 ) ;
	    print ( fullsourcefilenamestack [inopen ]) ;
	    print ( 58 ) ;
	    printint ( line ) ;
	    print ( 262 ) ;
	    print ( 1023 ) ;
	  } 
	  else {
	      
	    printnl ( 263 ) ;
	    print ( 1023 ) ;
	  } 
	} 
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1024 ;
	} 
	backerror () ;
	ligkern [nl ].b1 = 0 ;
	ligkern [nl ].b2 = 0 ;
	ligkern [nl ].b3 = 0 ;
	ligkern [nl ].b0 = 129 ;
      } 
      if ( nl == ligtablesize ) 
      overflow ( 1025 , ligtablesize ) ;
      incr ( nl ) ;
      if ( curcmd == 82 ) 
      goto lab22 ;
      if ( ligkern [nl - 1 ].b0 < 128 ) 
      ligkern [nl - 1 ].b0 = 128 ;
      lab30: ;
    } 
    break ;
  case 2 : 
    {
      if ( ne == 256 ) 
      overflow ( 1006 , 256 ) ;
      c = getcode () ;
      settag ( c , 3 , ne ) ;
      if ( curcmd != 81 ) 
      {
	missingerr ( 58 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1039 ;
	} 
	backerror () ;
      } 
      exten [ne ].b0 = getcode () ;
      if ( curcmd != 82 ) 
      {
	missingerr ( 44 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1039 ;
	} 
	backerror () ;
      } 
      exten [ne ].b1 = getcode () ;
      if ( curcmd != 82 ) 
      {
	missingerr ( 44 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1039 ;
	} 
	backerror () ;
      } 
      exten [ne ].b2 = getcode () ;
      if ( curcmd != 82 ) 
      {
	missingerr ( 44 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1039 ;
	} 
	backerror () ;
      } 
      exten [ne ].b3 = getcode () ;
      incr ( ne ) ;
    } 
    break ;
  case 3 : 
  case 4 : 
    {
      c = curmod ;
      getxnext () ;
      scanexpression () ;
      if ( ( curtype != 16 ) || ( curexp < 32768L ) ) 
      {
	disperr ( 0 , 1019 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1020 ;
	  helpline [0 ]= 1021 ;
	} 
	putgeterror () ;
      } 
      else {
	  
	j = roundunscaled ( curexp ) ;
	if ( curcmd != 81 ) 
	{
	  missingerr ( 58 ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1022 ;
	  } 
	  backerror () ;
	} 
	if ( c == 3 ) 
	do {
	    if ( j > headersize ) 
	  overflow ( 1007 , headersize ) ;
	  headerbyte [j ]= getcode () ;
	  incr ( j ) ;
	} while ( ! ( curcmd != 82 ) ) ;
	else do {
	    if ( j > maxfontdimen ) 
	  overflow ( 1008 , maxfontdimen ) ;
	  while ( j > np ) {
	      
	    incr ( np ) ;
	    param [np ]= 0 ;
	  } 
	  getxnext () ;
	  scanexpression () ;
	  if ( curtype != 16 ) 
	  {
	    disperr ( 0 , 1040 ) ;
	    {
	      helpptr = 1 ;
	      helpline [0 ]= 308 ;
	    } 
	    putgetflusherror ( 0 ) ;
	  } 
	  param [j ]= curexp ;
	  incr ( j ) ;
	} while ( ! ( curcmd != 82 ) ) ;
      } 
    } 
    break ;
  } 
} 
void 
dospecial ( void ) 
{
  smallnumber m  ;
  m = curmod ;
  getxnext () ;
  scanexpression () ;
  if ( internal [34 ]>= 0 ) {
      
    if ( curtype != m ) 
    {
      disperr ( 0 , 1061 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 1062 ;
      } 
      putgeterror () ;
    } 
    else {
	
      if ( outputfilename == 0 ) 
      initgf () ;
      if ( m == 4 ) 
      gfstring ( curexp , 0 ) ;
      else {
	  
	{
	  gfbuf [gfptr ]= 243 ;
	  incr ( gfptr ) ;
	  if ( gfptr == gflimit ) 
	  gfswap () ;
	} 
	gffour ( curexp ) ;
      } 
    } 
  } 
  flushcurexp ( 0 ) ;
} 
void 
dostatement ( void ) 
{
  curtype = 1 ;
  getxnext () ;
  if ( curcmd > 43 ) 
  {
    if ( curcmd < 83 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 869 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 869 ) ;
	} 
      } 
      printcmdmod ( curcmd , curmod ) ;
      printchar ( 39 ) ;
      {
	helpptr = 5 ;
	helpline [4 ]= 870 ;
	helpline [3 ]= 871 ;
	helpline [2 ]= 872 ;
	helpline [1 ]= 873 ;
	helpline [0 ]= 874 ;
      } 
      backerror () ;
      getxnext () ;
    } 
  } 
  else if ( curcmd > 30 ) 
  {
    varflag = 77 ;
    scanexpression () ;
    if ( curcmd < 84 ) 
    {
      if ( curcmd == 51 ) 
      doequation () ;
      else if ( curcmd == 77 ) 
      doassignment () ;
      else if ( curtype == 4 ) 
      {
	if ( internal [1 ]> 0 ) 
	{
	  printnl ( 261 ) ;
	  slowprint ( curexp ) ;
	  fflush ( stdout ) ;
	} 
	if ( internal [34 ]> 0 ) 
	{
	  if ( outputfilename == 0 ) 
	  initgf () ;
	  gfstring ( 1063 , curexp ) ;
	} 
      } 
      else if ( curtype != 1 ) 
      {
	disperr ( 0 , 879 ) ;
	{
	  helpptr = 3 ;
	  helpline [2 ]= 880 ;
	  helpline [1 ]= 881 ;
	  helpline [0 ]= 882 ;
	} 
	putgeterror () ;
      } 
      flushcurexp ( 0 ) ;
      curtype = 1 ;
    } 
  } 
  else {
      
    if ( internal [7 ]> 0 ) 
    showcmdmod ( curcmd , curmod ) ;
    switch ( curcmd ) 
    {case 30 : 
      dotypedeclaration () ;
      break ;
    case 16 : 
      if ( curmod > 2 ) 
      makeopdef () ;
      else if ( curmod > 0 ) 
      scandef () ;
      break ;
    case 24 : 
      dorandomseed () ;
      break ;
    case 23 : 
      {
	println () ;
	interaction = curmod ;
	if ( interaction == 0 ) 
	kpsemaketexdiscarderrors = 1 ;
	else kpsemaketexdiscarderrors = 0 ;
	if ( interaction == 0 ) 
	selector = 0 ;
	else selector = 1 ;
	if ( logopened ) 
	selector = selector + 2 ;
	getxnext () ;
      } 
      break ;
    case 21 : 
      doprotection () ;
      break ;
    case 27 : 
      defdelims () ;
      break ;
    case 12 : 
      do {
	  getsymbol () ;
	savevariable ( cursym ) ;
	getxnext () ;
      } while ( ! ( curcmd != 82 ) ) ;
      break ;
    case 13 : 
      dointerim () ;
      break ;
    case 14 : 
      dolet () ;
      break ;
    case 15 : 
      donewinternal () ;
      break ;
    case 22 : 
      doshowwhatever () ;
      break ;
    case 18 : 
      doaddto () ;
      break ;
    case 17 : 
      doshipout () ;
      break ;
    case 11 : 
      dodisplay () ;
      break ;
    case 28 : 
      doopenwindow () ;
      break ;
    case 19 : 
      docull () ;
      break ;
    case 26 : 
      {
	getsymbol () ;
	startsym = cursym ;
	getxnext () ;
      } 
      break ;
    case 25 : 
      domessage () ;
      break ;
    case 20 : 
      dotfmcommand () ;
      break ;
    case 29 : 
      dospecial () ;
      break ;
    } 
    curtype = 1 ;
  } 
  if ( curcmd < 83 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
      {
	printnl ( 261 ) ;
	print ( fullsourcefilenamestack [inopen ]) ;
	print ( 58 ) ;
	printint ( line ) ;
	print ( 262 ) ;
	print ( 875 ) ;
      } 
      else {
	  
	printnl ( 263 ) ;
	print ( 875 ) ;
      } 
    } 
    {
      helpptr = 6 ;
      helpline [5 ]= 876 ;
      helpline [4 ]= 877 ;
      helpline [3 ]= 878 ;
      helpline [2 ]= 872 ;
      helpline [1 ]= 873 ;
      helpline [0 ]= 874 ;
    } 
    backerror () ;
    scannerstatus = 2 ;
    do {
	getnext () ;
      if ( curcmd == 39 ) 
      {
	if ( strref [curmod ]< 127 ) {
	    
	  if ( strref [curmod ]> 1 ) 
	  decr ( strref [curmod ]) ;
	  else flushstring ( curmod ) ;
	} 
      } 
    } while ( ! ( curcmd > 82 ) ) ;
    scannerstatus = 0 ;
  } 
  errorcount = 0 ;
} 
void 
maincontrol ( void ) 
{
  do {
      dostatement () ;
    if ( curcmd == 84 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	{
	  printnl ( 261 ) ;
	  print ( fullsourcefilenamestack [inopen ]) ;
	  print ( 58 ) ;
	  printint ( line ) ;
	  print ( 262 ) ;
	  print ( 910 ) ;
	} 
	else {
	    
	  printnl ( 263 ) ;
	  print ( 910 ) ;
	} 
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 911 ;
	helpline [0 ]= 690 ;
      } 
      flusherror ( 0 ) ;
    } 
  } while ( ! ( curcmd == 85 ) ) ;
} 
halfword 
zsortin ( scaled v ) 
{
  /* 40 */ register halfword Result; halfword p, q, r  ;
  p = memtop - 1 ;
  while ( true ) {
      
    q = mem [p ].hhfield .v.RH ;
    if ( v <= mem [q + 1 ].cint ) 
    goto lab40 ;
    p = q ;
  } 
  lab40: if ( v < mem [q + 1 ].cint ) 
  {
    r = getnode ( 2 ) ;
    mem [r + 1 ].cint = v ;
    mem [r ].hhfield .v.RH = q ;
    mem [p ].hhfield .v.RH = r ;
  } 
  Result = mem [p ].hhfield .v.RH ;
  return Result ;
} 
integer 
zmincover ( scaled d ) 
{
  register integer Result; halfword p  ;
  scaled l  ;
  integer m  ;
  m = 0 ;
  p = mem [memtop - 1 ].hhfield .v.RH ;
  perturbation = 2147483647L ;
  while ( p != 19 ) {
      
    incr ( m ) ;
    l = mem [p + 1 ].cint ;
    do {
	p = mem [p ].hhfield .v.RH ;
    } while ( ! ( mem [p + 1 ].cint > l + d ) ) ;
    if ( mem [p + 1 ].cint - l < perturbation ) 
    perturbation = mem [p + 1 ].cint - l ;
  } 
  Result = m ;
  return Result ;
} 
scaled 
zthresholdfn ( integer m ) 
{
  register scaled Result; scaled d  ;
  excess = mincover ( 0 ) - m ;
  if ( excess <= 0 ) 
  Result = 0 ;
  else {
      
    do {
	d = perturbation ;
    } while ( ! ( mincover ( d + d ) <= m ) ) ;
    while ( mincover ( d ) > m ) d = perturbation ;
    Result = d ;
  } 
  return Result ;
} 
integer 
zskimp ( integer m ) 
{
  register integer Result; scaled d  ;
  halfword p, q, r  ;
  scaled l  ;
  scaled v  ;
  d = thresholdfn ( m ) ;
  perturbation = 0 ;
  q = memtop - 1 ;
  m = 0 ;
  p = mem [memtop - 1 ].hhfield .v.RH ;
  while ( p != 19 ) {
      
    incr ( m ) ;
    l = mem [p + 1 ].cint ;
    mem [p ].hhfield .lhfield = m ;
    if ( mem [mem [p ].hhfield .v.RH + 1 ].cint <= l + d ) 
    {
      do {
	  p = mem [p ].hhfield .v.RH ;
	mem [p ].hhfield .lhfield = m ;
	decr ( excess ) ;
	if ( excess == 0 ) 
	d = 0 ;
      } while ( ! ( mem [mem [p ].hhfield .v.RH + 1 ].cint > l + d ) ) ;
      v = l + halfp ( mem [p + 1 ].cint - l ) ;
      if ( mem [p + 1 ].cint - v > perturbation ) 
      perturbation = mem [p + 1 ].cint - v ;
      r = q ;
      do {
	  r = mem [r ].hhfield .v.RH ;
	mem [r + 1 ].cint = v ;
      } while ( ! ( r == p ) ) ;
      mem [q ].hhfield .v.RH = p ;
    } 
    q = p ;
    p = mem [p ].hhfield .v.RH ;
  } 
  Result = m ;
  return Result ;
} 
void 
ztfmwarning ( smallnumber m ) 
{
  printnl ( 1041 ) ;
  print ( intname [m ]) ;
  print ( 1042 ) ;
  printscaled ( perturbation ) ;
  print ( 1043 ) ;
} 
void 
fixdesignsize ( void ) 
{
  scaled d  ;
  d = internal [26 ];
  if ( ( d < 65536L ) || ( d >= 134217728L ) ) 
  {
    if ( d != 0 ) 
    printnl ( 1044 ) ;
    d = 8388608L ;
    internal [26 ]= d ;
  } 
  if ( headerbyte [5 ]< 0 ) {
      
    if ( headerbyte [6 ]< 0 ) {
	
      if ( headerbyte [7 ]< 0 ) {
	  
	if ( headerbyte [8 ]< 0 ) 
	{
	  headerbyte [5 ]= d / 1048576L ;
	  headerbyte [6 ]= ( d / 4096 ) % 256 ;
	  headerbyte [7 ]= ( d / 16 ) % 256 ;
	  headerbyte [8 ]= ( d % 16 ) * 16 ;
	} 
      } 
    } 
  } 
  maxtfmdimen = 16 * internal [26 ]- 1 - internal [26 ]/ 2097152L ;
  if ( maxtfmdimen >= 134217728L ) 
  maxtfmdimen = 134217727L ;
} 
integer 
zdimenout ( scaled x ) 
{
  register integer Result; if ( abs ( x ) > maxtfmdimen ) 
  {
    incr ( tfmchanged ) ;
    if ( x > 0 ) 
    x = maxtfmdimen ;
    else x = - (integer) maxtfmdimen ;
  } 
  x = makescaled ( x * 16 , internal [26 ]) ;
  Result = x ;
  return Result ;
} 
void 
fixchecksum ( void ) 
{
  /* 10 */ eightbits k  ;
  eightbits lb1, lb2, lb3, b4  ;
  integer x  ;
  if ( headerbyte [1 ]< 0 ) {
      
    if ( headerbyte [2 ]< 0 ) {
	
      if ( headerbyte [3 ]< 0 ) {
	  
	if ( headerbyte [4 ]< 0 ) 
	{
	  lb1 = bc ;
	  lb2 = ec ;
	  lb3 = bc ;
	  b4 = ec ;
	  tfmchanged = 0 ;
	  {register integer for_end; k = bc ;for_end = ec ; if ( k <= 
	  for_end) do 
	    if ( charexists [k ]) 
	    {
	      x = dimenout ( mem [tfmwidth [k ]+ 1 ].cint ) + ( k + 4 ) * 
	      4194304L ;
	      lb1 = ( lb1 + lb1 + x ) % 255 ;
	      lb2 = ( lb2 + lb2 + x ) % 253 ;
	      lb3 = ( lb3 + lb3 + x ) % 251 ;
	      b4 = ( b4 + b4 + x ) % 247 ;
	    } 
	  while ( k++ < for_end ) ;} 
	  headerbyte [1 ]= lb1 ;
	  headerbyte [2 ]= lb2 ;
	  headerbyte [3 ]= lb3 ;
	  headerbyte [4 ]= b4 ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {register integer for_end; k = 1 ;for_end = 4 ; if ( k <= for_end) do 
    if ( headerbyte [k ]< 0 ) 
    headerbyte [k ]= 0 ;
  while ( k++ < for_end ) ;} 
  lab10: ;
} 
void 
ztfmqqqq ( fourquarters x ) 
{
  putbyte ( x .b0 , tfmfile ) ;
  putbyte ( x .b1 , tfmfile ) ;
  putbyte ( x .b2 , tfmfile ) ;
  putbyte ( x .b3 , tfmfile ) ;
} 
boolean 
openbasefile ( void ) 
{
  /* 40 10 */ register boolean Result; integer j  ;
  j = curinput .locfield ;
  if ( buffer [curinput .locfield ]== 38 ) 
  {
    incr ( curinput .locfield ) ;
    j = curinput .locfield ;
    buffer [last ]= 32 ;
    while ( buffer [j ]!= 32 ) incr ( j ) ;
    packbufferedname ( 0 , curinput .locfield , j - 1 ) ;
    if ( wopenin ( basefile ) ) 
    goto lab40 ;
    Fputs ( stdout ,  "Sorry, I can't find the base `" ) ;
    fputs ( stringcast ( nameoffile + 1 ) , stdout ) ;
    Fputs ( stdout ,  "'; will try `" ) ;
    fputs ( MFbasedefault + 1 , stdout ) ;
    fprintf ( stdout , "%s\n",  "'." ) ;
    fflush ( stdout ) ;
  } 
  packbufferedname ( basedefaultlength - 5 , 1 , 0 ) ;
  if ( ! wopenin ( basefile ) ) 
  {
    ;
    Fputs ( stdout ,  "I can't find the base file `" ) ;
    fputs ( MFbasedefault + 1 , stdout ) ;
    fprintf ( stdout , "%s\n",  "'!" ) ;
    Result = false ;
    goto lab10 ;
  } 
  lab40: curinput .locfield = j ;
  Result = true ;
  lab10: ;
  return Result ;
} 
void 
scanprimary ( void ) 
{
  /* 20 30 31 32 */ halfword p, q, r  ;
  quarterword c  ;
  unsigned char myvarflag  ;
  halfword ldelim, rdelim  ;
  integer groupline  ;
  scaled num, denom  ;
  halfword prehead, posthead, tail  ;
  smallnumber tt  ;
  halfword t  ;
  halfword macroref  ;
  myvarflag = varflag ;
  varflag = 0 ;
  lab20: {
      
    if ( aritherror ) 
    cleararith () ;
  } 
	;
#ifdef TEXMF_DEBUG
  if ( panicking ) 
  checkmem ( false ) ;
#endif /* TEXMF_DEBUG */
  if ( interrupt != 0 ) {
      
    if ( OKtointerrupt ) 
    {
      backinput () ;
      {
	if ( interrupt != 0 ) 
	pauseforinstructions () ;
      } 
      getxnext () ;
    } 
  } 
  switch ( curcmd ) 
  {case 31 : 
    {
      ldelim = cursym ;
      rdelim = curmod ;
      getxnext () ;
      scanexpression () ;
      if ( ( curcmd == 82 ) && ( curtype >= 16 ) ) 
      {
	p = getnode ( 2 ) ;
	mem [p ].hhfield .b0 = 14 ;
	mem [p ].hhfield .b1 = 11 ;
	initbignode ( p ) ;
	q = mem [p + 1 ].cint ;
	stashin ( q ) ;
	getxnext () ;
	scanexpression () ;
	if ( curtype < 16 ) 
	{
	  disperr ( 0 , 775 ) ;
	  {
	    helpptr = 4 ;
	    helpline [3 ]= 776 ;
	    helpline [2 ]= 777 ;
	    helpline [1 ]= 778 ;
	    helpline [0 ]= 779 ;
	  } 
	  putgetflusherror ( 0 ) ;
	} 
	stashin ( q + 2 ) ;
	checkdelimiter ( ldelim , rdelim ) ;
	curtype = 14 ;
	curexp = p ;
      } 
      else checkdelimiter ( ldelim , rdelim ) ;
    } 
    break ;
  case 32 : 
    {
      groupline = line ;
      if ( internal [7 ]> 0 ) 
      showcmdmod ( curcmd , curmod ) ;
      {
	p = getavail () ;
	mem [p ].hhfield .lhfield = 0 ;
	mem [p ].hhfield .v.RH = saveptr ;
	saveptr = p ;
      } 
      do {
	  dostatement () ;
      } while ( ! ( curcmd != 83 ) ) ;
      if ( curcmd != 84 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	  {
	    printnl ( 261 ) ;
	    print ( fullsourcefilenamestack [inopen ]) ;
	    print ( 58 ) ;
	    printint ( line ) ;
	    print ( 262 ) ;
	    print ( 780 ) ;
	  } 
	  else {
	      
	    printnl ( 263 ) ;
	    print ( 780 ) ;
	  } 
	} 
	printint ( groupline ) ;
	print ( 781 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 782 ;
	  helpline [0 ]= 783 ;
	} 
	backerror () ;
	curcmd = 84 ;
      } 
      unsave () ;
      if ( internal [7 ]> 0 ) 
      showcmdmod ( curcmd , curmod ) ;
    } 
    break ;
  case 39 : 
    {
      curtype = 4 ;
      curexp = curmod ;
    } 
    break ;
  case 42 : 
    {
      curexp = curmod ;
      curtype = 16 ;
      getxnext () ;
      if ( curcmd != 54 ) 
      {
	num = 0 ;
	denom = 0 ;
      } 
      else {
	  
	getxnext () ;
	if ( curcmd != 42 ) 
	{
	  backinput () ;
	  curcmd = 54 ;
	  curmod = 72 ;
	  cursym = 9761 ;
	  goto lab30 ;
	} 
	num = curexp ;
	denom = curmod ;
	if ( denom == 0 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) ) ) 
	    {
	      printnl ( 261 ) ;
	      print ( fullsourcefilenamestack [inopen ]) ;
	      print ( 58 ) ;
	      printint ( line ) ;
	      print ( 262 ) ;
	      print ( 784 ) ;
	    } 
	    else {
		
	      printnl ( 263 ) ;
	      print ( 784 ) ;
	    } 
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 785 ;
	  } 
	  error () ;
	} 
	else curexp = makescaled ( num , denom ) ;
	{
	  if ( aritherror ) 
	  cleararith () ;
	} 
	getxnext () ;
      } 
      if ( curcmd >= 30 ) {
	  
	if ( curcmd < 42 ) 
	{
	  p = stashcurexp () ;
	  scanprimary () ;
	  if ( ( abs ( num ) >= abs ( denom ) ) || ( curtype < 14 ) ) 
	  dobinary ( p , 71 ) ;
	  else {
	      
	    fracmult ( num , denom ) ;
	    freenode ( p , 2 ) ;
	  } 
	} 
      } 
      goto lab30 ;
    } 
    break ;
  case 33 : 
    donullary ( curmod ) ;
    break ;
  case 34 : 
  case 30 : 
  case 36 : 
  case 43 : 
    {
      c = curmod ;
      getxnext () ;
      scanprimary () ;
      dounary ( c ) ;
      goto lab30 ;
    } 
    break ;
  case 37 : 
    {
      c = curmod ;
      getxnext () ;
      scanexpression () ;
      if ( curcmd != 69 ) 
      {
	missingerr ( 479 ) ;
	print ( 716 ) ;
	printcmdmod ( 37 , c ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 717 ;
	} 
	backerror () ;
      } 
      p = stashcurexp () ;
      getxnext () ;
      scanprimary () ;
      dobinary ( p , c ) ;
      goto lab30 ;
    } 
    break ;
  case 35 : 
    {
      getxnext () ;
      scansuffix () ;
      oldsetting = selector ;
      selector = 5 ;
      showtokenlist ( curexp , 0 , 100000L , 0 ) ;
      flushtokenlist ( curexp ) ;
      curexp = makestring () ;
      selector = oldsetting ;
      curtype = 4 ;
      goto lab30 ;
    } 
    break ;
  case 40 : 
    {
      q = curmod ;
      if ( myvarflag == 77 ) 
      {
	getxnext () ;
	if ( curcmd == 77 ) 
	{
	  curexp = getavail () ;
	  mem [curexp ].hhfield .lhfield = q + 9769 ;
	  curtype = 20 ;
	  goto lab30 ;
	} 
	backinput () ;
      } 
      curtype = 16 ;
      curexp = internal [q ];
    } 
    break ;
  case 38 : 
    makeexpcopy ( curmod ) ;
    break ;
  case 41 : 
    {
      {
	prehead = avail ;
	if ( prehead == 0 ) 
	prehead = getavail () ;
	else {
	    
	  avail = mem [prehead ].hhfield .v.RH ;
	  mem [prehead ].hhfield .v.RH = 0 ;
	;
#ifdef STAT
	  incr ( dynused ) ;
#endif /* STAT */
	} 
      } 
      tail = prehead ;
      posthead = 0 ;
      tt = 1 ;
      while ( true ) {
	  
	t = curtok () ;
	mem [tail ].hhfield .v.RH = t ;
	if ( tt != 0 ) 
	{
	  {
	    p = mem [prehead ].hhfield .v.RH ;
	    q = mem [p ].hhfield .lhfield ;
	    tt = 0 ;
	    if ( eqtb [q ].lhfield % 86 == 41 ) 
	    {
	      q = eqtb [q ].v.RH ;
	      if ( q == 0 ) 
	      goto lab32 ;
	      while ( true ) {
		  
		p = mem [p ].hhfield .v.RH ;
		if ( p == 0 ) 
		{
		  tt = mem [q ].hhfield .b0 ;
		  goto lab32 ;
		} 
		if ( mem [q ].hhfield .b0 != 21 ) 
		goto lab32 ;
		q = mem [mem [q + 1 ].hhfield .lhfield ].hhfield .v.RH ;
		if ( p >= himemmin ) 
		{
		  do {
		      q = mem [q ].hhfield .v.RH ;
		  } while ( ! ( mem [q + 2 ].hhfield .lhfield >= mem [p ]
		  .hhfield .lhfield ) ) ;
		  if ( mem [q + 2 ].hhfield .lhfield > mem [p ].hhfield 
		  .lhfield ) 
		  goto lab32 ;
		} 
	      } 
	    } 
	    lab32: ;
	  } 
	  if ( tt >= 22 ) 
	  {
	    mem [tail ].hhfield .v.RH = 0 ;
	    if ( tt > 22 ) 
	    {
	      posthead = getavail () ;
	      tail = posthead ;
	      mem [tail ].hhfield .v.RH = t ;
	      tt = 0 ;
	      macroref = mem [q + 1 ].cint ;
	      incr ( mem [macroref ].hhfield .lhfield ) ;
	    } 
	    else {
		
	      p = getavail () ;
	      mem [prehead ].hhfield .lhfield = mem [prehead ].hhfield 
	      .v.RH ;
	      mem [prehead ].hhfield .v.RH = p ;
	      mem [p ].hhfield .lhfield = t ;
	      macrocall ( mem [q + 1 ].cint , prehead , 0 ) ;
	      getxnext () ;
	      goto lab20 ;
	    } 
	  } 
	} 
	getxnext () ;
	tail = t ;
	if ( curcmd == 63 ) 
	{
	  getxnext () ;
	  scanexpression () ;
	  if ( curcmd != 64 ) 
	  {
	    backinput () ;
	    backexpr () ;
	    curcmd = 63 ;
	    curmod = 0 ;
	    cursym = 9760 ;
	  } 
	  else {
	      
	    if ( curtype != 16 ) 
	    badsubscript () ;
	    curcmd = 42 ;
	    curmod = curexp ;
	    cursym = 0 ;
	  } 
	} 
	if ( curcmd > 42 ) 
	goto lab31 ;
	if ( curcmd < 40 ) 
	goto lab31 ;
      } 
      lab31: if ( posthead != 0 ) 
      {
	backinput () ;
	p = getavail () ;
	q = mem [posthead ].hhfield .v.RH ;
	mem [prehead ].hhfield .lhfield = mem [prehead ].hhfield .v.RH ;
	mem [prehead ].hhfield .v.RH = posthead ;
	mem [posthead ].hhfield .lhfield = q ;
	mem [posthead ].hhfield .v.RH = p ;
	mem [p ].hhfield .lhfield = mem [q ].hhfield .v.RH ;
	mem [q ].hhfield .v.RH = 0 ;
	macrocall ( macroref , prehead , 0 ) ;
	decr ( mem [macroref ].hhfield .lhfield ) ;
	getxnext () ;
	goto lab20 ;
      } 
      q = mem [prehead ].hhfield .v.RH ;
      {
	mem [prehead ].hhfield .v.RH = avail ;
	avail = prehead ;
	;
#ifdef STAT
	decr ( dynused ) ;
#endif /* STAT */
      } 
      if ( curcmd == myvarflag ) 
      {
	curtype = 20 ;
	curexp = q ;
	goto lab30 ;
      } 
      p = findvariable ( q ) ;
      if ( p != 0 ) 
      makeexpcopy ( p ) ;
      else {
	  
	obliterated ( q ) ;
	helpline [2 ]= 797 ;
	helpline [1 ]= 798 ;
	helpline [0 ]= 799 ;
	putgetflusherror ( 0 ) ;
      } 
      flushnodelist ( q ) ;
      goto lab30 ;
    } 
    break ;
    default: 
    {
      badexp ( 769 ) ;
      goto lab20 ;
    } 
    break ;
  } 
  getxnext () ;
  lab30: if ( curcmd == 63 ) {
      
    if ( curtype >= 16 ) 
    {
      p = stashcurexp () ;
      getxnext () ;
      scanexpression () ;
      if ( curcmd != 82 ) 
      {
	{
	  backinput () ;
	  backexpr () ;
	  curcmd = 63 ;
	  curmod = 0 ;
	  cursym = 9760 ;
	} 
	unstashcurexp ( p ) ;
      } 
      else {
	  
	q = stashcurexp () ;
	getxnext () ;
	scanexpression () ;
	if ( curcmd != 64 ) 
	{
	  missingerr ( 93 ) ;
	  {
	    helpptr = 3 ;
	    helpline [2 ]= 801 ;
	    helpline [1 ]= 802 ;
	    helpline [0 ]= 698 ;
	  } 
	  backerror () ;
	} 
	r = stashcurexp () ;
	makeexpcopy ( q ) ;
	dobinary ( r , 70 ) ;
	dobinary ( p , 71 ) ;
	dobinary ( q , 69 ) ;
	getxnext () ;
      } 
    } 
  } 
} 
void 
scansuffix ( void ) 
{
  /* 30 */ halfword h, t  ;
  halfword p  ;
  h = getavail () ;
  t = h ;
  while ( true ) {
      
    if ( curcmd == 63 ) 
    {
      getxnext () ;
      scanexpression () ;
      if ( curtype != 16 ) 
      badsubscript () ;
      if ( curcmd != 64 ) 
      {
	missingerr ( 93 ) ;
	{
	  helpptr = 3 ;
	  helpline [2 ]= 803 ;
	  helpline [1 ]= 802 ;
	  helpline [0 ]= 698 ;
	} 
	backerror () ;
      } 
      curcmd = 42 ;
      curmod = curexp ;
    } 
    if ( curcmd == 42 ) 
    p = newnumtok ( curmod ) ;
    else if ( ( curcmd == 41 ) || ( curcmd == 40 ) ) 
    {
      p = getavail () ;
      mem [p ].hhfield .lhfield = cursym ;
    } 
    else goto lab30 ;
    mem [t ].hhfield .v.RH = p ;
    t = p ;
    getxnext () ;
  } 
  lab30: curexp = mem [h ].hhfield .v.RH ;
  {
    mem [h ].hhfield .v.RH = avail ;
    avail = h ;
	;
#ifdef STAT
    decr ( dynused ) ;
#endif /* STAT */
  } 
  curtype = 20 ;
} 
void 
scansecondary ( void ) 
{
  /* 20 22 */ halfword p  ;
  halfword c, d  ;
  halfword macname  ;
  lab20: if ( ( curcmd < 30 ) || ( curcmd > 43 ) ) 
  badexp ( 804 ) ;
  scanprimary () ;
  lab22: if ( curcmd <= 55 ) {
      
    if ( curcmd >= 52 ) 
    {
      p = stashcurexp () ;
      c = curmod ;
      d = curcmd ;
      if ( d == 53 ) 
      {
	macname = cursym ;
	incr ( mem [c ].hhfield .lhfield ) ;
      } 
      getxnext () ;
      scanprimary () ;
      if ( d != 53 ) 
      dobinary ( p , c ) ;
      else {
	  
	backinput () ;
	binarymac ( p , c , macname ) ;
	decr ( mem [c ].hhfield .lhfield ) ;
	getxnext () ;
	goto lab20 ;
      } 
      goto lab22 ;
    } 
  } 
} 
void 
scantertiary ( void ) 
{
  /* 20 22 */ halfword p  ;
  halfword c, d  ;
  halfword macname  ;
  lab20: if ( ( curcmd < 30 ) || ( curcmd > 43 ) ) 
  badexp ( 805 ) ;
  scansecondary () ;
  if ( curtype == 8 ) 
  materializepen () ;
  lab22: if ( curcmd <= 45 ) {
      
    if ( curcmd >= 43 ) 
    {
      p = stashcurexp () ;
      c = curmod ;
      d = curcmd ;
      if ( d == 44 ) 
      {
	macname = cursym ;
	incr ( mem [c ].hhfield .lhfield ) ;
      } 
      getxnext () ;
      scansecondary () ;
      if ( d != 44 ) 
      dobinary ( p , c ) ;
      else {
	  
	backinput () ;
	binarymac ( p , c , macname ) ;
	decr ( mem [c ].hhfield .lhfield ) ;
	getxnext () ;
	goto lab20 ;
      } 
      goto lab22 ;
    } 
  } 
} 
void 
scanexpression ( void ) 
{
  /* 20 30 22 25 26 10 */ halfword p, q, r, pp, qq  ;
  halfword c, d  ;
  unsigned char myvarflag  ;
  halfword macname  ;
  boolean cyclehit  ;
  scaled x, y  ;
  unsigned char t  ;
  myvarflag = varflag ;
  lab20: if ( ( curcmd < 30 ) || ( curcmd > 43 ) ) 
  badexp ( 808 ) ;
  scantertiary () ;
  lab22: if ( curcmd <= 51 ) {
      
    if ( curcmd >= 46 ) {
	
      if ( ( curcmd != 51 ) || ( myvarflag != 77 ) ) 
      {
	p = stashcurexp () ;
	c = curmod ;
	d = curcmd ;
	if ( d == 49 ) 
	{
	  macname = cursym ;
	  incr ( mem [c ].hhfield .lhfield ) ;
	} 
	if ( ( d < 48 ) || ( ( d == 48 ) && ( ( mem [p ].hhfield .b0 == 14 ) 
	|| ( mem [p ].hhfield .b0 == 9 ) ) ) ) 
	{
	  cyclehit = false ;
	  {
	    unstashcurexp ( p ) ;
	    if ( curtype == 14 ) 
	    p = newknot () ;
	    else if ( curtype == 9 ) 
	    p = curexp ;
	    else goto lab10 ;
	    q = p ;
	    while ( mem [q ].hhfield .v.RH != p ) q = mem [q ].hhfield 
	    .v.RH ;
	    if ( mem [p ].hhfield .b0 != 0 ) 
	    {
	      r = copyknot ( p ) ;
	      mem [q ].hhfield .v.RH = r ;
	      q = r ;
	    } 
	    mem [p ].hhfield .b0 = 4 ;
	    mem [q ].hhfield .b1 = 4 ;
	  } 
	  lab25: if ( curcmd == 46 ) 
	  {
	    t = scandirection () ;
	    if ( t != 4 ) 
	    {
	      mem [q ].hhfield .b1 = t ;
	      mem [q + 5 ].cint = curexp ;
	      if ( mem [q ].hhfield .b0 == 4 ) 
	      {
		mem [q ].hhfield .b0 = t ;
		mem [q + 3 ].cint = curexp ;
	      } 
	    } 
	  } 
	  d = curcmd ;
	  if ( d == 47 ) 
	  {
	    getxnext () ;
	    if ( curcmd == 58 ) 
	    {
	      getxnext () ;
	      y = curcmd ;
	      if ( curcmd == 59 ) 
	      getxnext () ;
	      scanprimary () ;
	      if ( ( curtype != 16 ) || ( curexp < 49152L ) ) 
	      {
		disperr ( 0 , 826 ) ;
		{
		  helpptr = 1 ;
		  helpline [0 ]= 827 ;
		} 
		putgetflusherror ( 65536L ) ;
	      } 
	      if ( y == 59 ) 
	      curexp = - (integer) curexp ;
	      mem [q + 6 ].cint = curexp ;
	      if ( curcmd == 52 ) 
	      {
		getxnext () ;
		y = curcmd ;
		if ( curcmd == 59 ) 
		getxnext () ;
		scanprimary () ;
		if ( ( curtype != 16 ) || ( curexp < 49152L ) ) 
		{
		  disperr ( 0 , 826 ) ;
		  {
		    helpptr = 1 ;
		    helpline [0 ]= 827 ;
		  } 
		  putgetflusherror ( 65536L ) ;
		} 
		if ( y == 59 ) 
		curexp = - (integer) curexp ;
	      } 
	      y = curexp ;
	    } 
	    else if ( curcmd == 57 ) 
	    {
	      mem [q ].hhfield .b1 = 1 ;
	      t = 1 ;
	      getxnext () ;
	      scanprimary () ;
	      knownpair () ;
	      mem [q + 5 ].cint = curx ;
	      mem [q + 6 ].cint = cury ;
	      if ( curcmd != 52 ) 
	      {
		x = mem [q + 5 ].cint ;
		y = mem [q + 6 ].cint ;
	      } 
	      else {
		  
		getxnext () ;
		scanprimary () ;
		knownpair () ;
		x = curx ;
		y = cury ;
	      } 
	    } 
	    else {
		
	      mem [q + 6 ].cint = 65536L ;
	      y = 65536L ;
	      backinput () ;
	      goto lab30 ;
	    } 
	    if ( curcmd != 47 ) 
	    {
	      missingerr ( 408 ) ;
	      {
		helpptr = 1 ;
		helpline [0 ]= 825 ;
	      } 
	      backerror () ;
	    } 
	    lab30: ;
	  } 
	  else if ( d != 48 ) 
	  goto lab26 ;
	  getxnext () ;
	  if ( curcmd == 46 ) 
	  {
	    t = scandirection () ;
	    if ( mem [q ].hhfield .b1 != 1 ) 
	    x = curexp ;
	    else t = 1 ;
	  } 
	  else if ( mem [q ].hhfield .b1 != 1 ) 
	  {
	    t = 4 ;
	    x = 0 ;
	  } 
	  if ( curcmd == 36 ) 
	  {
	    cyclehit = true ;
	    getxnext () ;
	    pp = p ;
	    qq = p ;
	    if ( d == 48 ) {
		
	      if ( p == q ) 
	      {
		d = 47 ;
		mem [q + 6 ].cint = 65536L ;
		y = 65536L ;
	      } 
	    } 
	  } 
	  else {
	      
	    scantertiary () ;
	    {
	      if ( curtype != 9 ) 
	      pp = newknot () ;
	      else pp = curexp ;
	      qq = pp ;
	      while ( mem [qq ].hhfield .v.RH != pp ) qq = mem [qq ]
	      .hhfield .v.RH ;
	      if ( mem [pp ].hhfield .b0 != 0 ) 
	      {
		r = copyknot ( pp ) ;
		mem [qq ].hhfield .v.RH = r ;
		qq = r ;
	      } 
	      mem [pp ].hhfield .b0 = 4 ;
	      mem [qq ].hhfield .b1 = 4 ;
	    } 
	  } 
	  {
	    if ( d == 48 ) {
		
	      if ( ( mem [q + 1 ].cint != mem [pp + 1 ].cint ) || ( mem [
	      q + 2 ].cint != mem [pp + 2 ].cint ) ) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( ( filelineerrorstylep && ! ( curinput .namefield == 0 ) 
		  ) ) 
		  {
		    printnl ( 261 ) ;
		    print ( fullsourcefilenamestack [inopen ]) ;
		    print ( 58 ) ;
		    printint ( line ) ;
		    print ( 262 ) ;
		    print ( 828 ) ;
		  } 
		  else {
		      
		    printnl ( 263 ) ;
		    print ( 828 ) ;
		  } 
		} 
		{
		  helpptr = 3 ;
		  helpline [2 ]= 829 ;
		  helpline [1 ]= 830 ;
		  helpline [0 ]= 831 ;
		} 
		putgeterror () ;
		d = 47 ;
		mem [q + 6 ].cint = 65536L ;
		y = 65536L ;
	      } 
	    } 
	    if ( mem [pp ].hhfield .b1 == 4 ) {
		
	      if ( ( t == 3 ) || ( t == 2 ) ) 
	      {
		mem [pp ].hhfield .b1 = t ;
		mem [pp + 5 ].cint = x ;
	      } 
	    } 
	    if ( d == 48 ) 
	    {
	      if ( mem [q ].hhfield .b0 == 4 ) {
		  
		if ( mem [q ].hhfield .b1 == 4 ) 
		{
		  mem [q ].hhfield .b0 = 3 ;
		  mem [q + 3 ].cint = 65536L ;
		} 
	      } 
	      if ( mem [pp ].hhfield .b1 == 4 ) {
		  
		if ( t == 4 ) 
		{
		  mem [pp ].hhfield .b1 = 3 ;
		  mem [pp + 5 ].cint = 65536L ;
		} 
	      } 
	      mem [q ].hhfield .b1 = mem [pp ].hhfield .b1 ;
	      mem [q ].hhfield .v.RH = mem [pp ].hhfield .v.RH ;
	      mem [q + 5 ].cint = mem [pp + 5 ].cint ;
	      mem [q + 6 ].cint = mem [pp + 6 ].cint ;
	      freenode ( pp , 7 ) ;
	      if ( qq == pp ) 
	      qq = q ;
	    } 
	    else {
		
	      if ( mem [q ].hhfield .b1 == 4 ) {
		  
		if ( ( mem [q ].hhfield .b0 == 3 ) || ( mem [q ].hhfield 
		.b0 == 2 ) ) 
		{
		  mem [q ].hhfield .b1 = mem [q ].hhfield .b0 ;
		  mem [q + 5 ].cint = mem [q + 3 ].cint ;
		} 
	      } 
	      mem [q ].hhfield .v.RH = pp ;
	      mem [pp + 4 ].cint = y ;
	      if ( t != 4 ) 
	      {
		mem [pp + 3 ].cint = x ;
		mem [pp ].hhfield .b0 = t ;
	      } 
	    } 
	    q = qq ;
	  } 
	  if ( curcmd >= 46 ) {
	      
	    if ( curcmd <= 48 ) {
		
	      if ( ! cyclehit ) 
	      goto lab25 ;
	    } 
	  } 
	  lab26: if ( cyclehit ) 
	  {
	    if ( d == 48 ) 
	    p = q ;
	  } 
	  else {
	      
	    mem [p ].hhfield .b0 = 0 ;
	    if ( mem [p ].hhfield .b1 == 4 ) 
	    {
	      mem [p ].hhfield .b1 = 3 ;
	      mem [p + 5 ].cint = 65536L ;
	    } 
	    mem [q ].hhfield .b1 = 0 ;
	    if ( mem [q ].hhfield .b0 == 4 ) 
	    {
	      mem [q ].hhfield .b0 = 3 ;
	      mem [q + 3 ].cint = 65536L ;
	    } 
	    mem [q ].hhfield .v.RH = p ;
	  } 
	  makechoices ( p ) ;
	  curtype = 9 ;
	  curexp = p ;
	} 
	else {
	    
	  getxnext () ;
	  scantertiary () ;
	  if ( d != 49 ) 
	  dobinary ( p , c ) ;
	  else {
	      
	    backinput () ;
	    binarymac ( p , c , macname ) ;
	    decr ( mem [c ].hhfield .lhfield ) ;
	    getxnext () ;
	    goto lab20 ;
	  } 
	} 
	goto lab22 ;
      } 
    } 
  } 
  lab10: ;
} 
void 
getboolean ( void ) 
{
  getxnext () ;
  scanexpression () ;
  if ( curtype != 2 ) 
  {
    disperr ( 0 , 832 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 833 ;
      helpline [0 ]= 834 ;
    } 
    putgetflusherror ( 31 ) ;
    curtype = 2 ;
  } 
} 
void 
printcapsule ( void ) 
{
  printchar ( 40 ) ;
  printexp ( gpointer , 0 ) ;
  printchar ( 41 ) ;
} 
void 
tokenrecycle ( void ) 
{
  recyclevalue ( gpointer ) ;
} 
void 
closefilesandterminate ( void ) 
{
  integer k  ;
  integer lh  ;
  short lkoffset  ;
  halfword p  ;
  scaled x  ;
	;
#ifdef STAT
  if ( internal [12 ]> 0 ) {
      
    if ( logopened ) 
    {
      { putc ( ' ' ,  logfile );  putc ( '\n',  logfile ); }
      fprintf ( logfile , "%s%s\n",  "Here is how much of METAFONT's memory" ,       " you used:" ) ;
      fprintf ( logfile , "%c%ld%s",  ' ' , (long)maxstrptr - initstrptr , " string" ) ;
      if ( maxstrptr != initstrptr + 1 ) 
      putc ( 's' ,  logfile );
      fprintf ( logfile , "%s%ld\n",  " out of " , (long)maxstrings - initstrptr ) ;
      fprintf ( logfile , "%c%ld%s%ld\n",  ' ' , (long)maxpoolptr - initpoolptr ,       " string characters out of " , (long)poolsize - initpoolptr ) ;
      fprintf ( logfile , "%c%ld%s%ld\n",  ' ' , (long)lomemmax + 0 + memend - himemmin + 2 ,       " words of memory out of " , (long)memend + 1 ) ;
      fprintf ( logfile , "%c%ld%s%ld\n",  ' ' , (long)stcount , " symbolic tokens out of " , (long)9500 ) 
      ;
      fprintf ( logfile , "%c%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%c\n",  ' ' , (long)maxinstack , "i," , (long)intptr , "n," ,       (long)maxroundingptr , "r," , (long)maxparamstack , "p," , (long)maxbufstack + 1 ,       "b stack positions out of " , (long)stacksize , "i," , (long)maxinternal , "n," ,       (long)maxwiggle , "r," , (long)150 , "p," , (long)bufsize , 'b' ) ;
    } 
  } 
#endif /* STAT */
  if ( ( gfprevptr > 0 ) || ( internal [33 ]> 0 ) ) 
  {
    rover = 23 ;
    mem [rover ].hhfield .v.RH = 268435455L ;
    lomemmax = himemmin - 1 ;
    if ( lomemmax - rover > 268435455L ) 
    lomemmax = 268435455L + rover ;
    mem [rover ].hhfield .lhfield = lomemmax - rover ;
    mem [rover + 1 ].hhfield .lhfield = rover ;
    mem [rover + 1 ].hhfield .v.RH = rover ;
    mem [lomemmax ].hhfield .v.RH = 0 ;
    mem [lomemmax ].hhfield .lhfield = 0 ;
    mem [memtop - 1 ].hhfield .v.RH = 19 ;
    {register integer for_end; k = bc ;for_end = ec ; if ( k <= for_end) do 
      if ( charexists [k ]) 
      tfmwidth [k ]= sortin ( tfmwidth [k ]) ;
    while ( k++ < for_end ) ;} 
    nw = skimp ( 255 ) + 1 ;
    dimenhead [1 ]= mem [memtop - 1 ].hhfield .v.RH ;
    if ( perturbation >= 4096 ) 
    tfmwarning ( 20 ) ;
    fixdesignsize () ;
    fixchecksum () ;
    if ( internal [33 ]> 0 ) 
    {
      mem [memtop - 1 ].hhfield .v.RH = 19 ;
      {register integer for_end; k = bc ;for_end = ec ; if ( k <= for_end) 
      do 
	if ( charexists [k ]) {
	    
	  if ( tfmheight [k ]== 0 ) 
	  tfmheight [k ]= 15 ;
	  else tfmheight [k ]= sortin ( tfmheight [k ]) ;
	} 
      while ( k++ < for_end ) ;} 
      nh = skimp ( 15 ) + 1 ;
      dimenhead [2 ]= mem [memtop - 1 ].hhfield .v.RH ;
      if ( perturbation >= 4096 ) 
      tfmwarning ( 21 ) ;
      mem [memtop - 1 ].hhfield .v.RH = 19 ;
      {register integer for_end; k = bc ;for_end = ec ; if ( k <= for_end) 
      do 
	if ( charexists [k ]) {
	    
	  if ( tfmdepth [k ]== 0 ) 
	  tfmdepth [k ]= 15 ;
	  else tfmdepth [k ]= sortin ( tfmdepth [k ]) ;
	} 
      while ( k++ < for_end ) ;} 
      nd = skimp ( 15 ) + 1 ;
      dimenhead [3 ]= mem [memtop - 1 ].hhfield .v.RH ;
      if ( perturbation >= 4096 ) 
      tfmwarning ( 22 ) ;
      mem [memtop - 1 ].hhfield .v.RH = 19 ;
      {register integer for_end; k = bc ;for_end = ec ; if ( k <= for_end) 
      do 
	if ( charexists [k ]) {
	    
	  if ( tfmitalcorr [k ]== 0 ) 
	  tfmitalcorr [k ]= 15 ;
	  else tfmitalcorr [k ]= sortin ( tfmitalcorr [k ]) ;
	} 
      while ( k++ < for_end ) ;} 
      ni = skimp ( 63 ) + 1 ;
      dimenhead [4 ]= mem [memtop - 1 ].hhfield .v.RH ;
      if ( perturbation >= 4096 ) 
      tfmwarning ( 23 ) ;
      internal [33 ]= 0 ;
      if ( jobname == 0 ) 
      openlogfile () ;
      packjobname ( 1045 ) ;
      while ( ! bopenout ( tfmfile ) ) promptfilename ( 1046 , 1045 ) ;
      metricfilename = bmakenamestring ( tfmfile ) ;
      k = headersize ;
      while ( headerbyte [k ]< 0 ) decr ( k ) ;
      lh = ( k + 3 ) / 4 ;
      if ( bc > ec ) 
      bc = 1 ;
      bchar = roundunscaled ( internal [41 ]) ;
      if ( ( bchar < 0 ) || ( bchar > 255 ) ) 
      {
	bchar = -1 ;
	lkstarted = false ;
	lkoffset = 0 ;
      } 
      else {
	  
	lkstarted = true ;
	lkoffset = 1 ;
      } 
      k = labelptr ;
      if ( labelloc [k ]+ lkoffset > 255 ) 
      {
	lkoffset = 0 ;
	lkstarted = false ;
	do {
	    charremainder [labelchar [k ]]= lkoffset ;
	  while ( labelloc [k - 1 ]== labelloc [k ]) {
	      
	    decr ( k ) ;
	    charremainder [labelchar [k ]]= lkoffset ;
	  } 
	  incr ( lkoffset ) ;
	  decr ( k ) ;
	} while ( ! ( lkoffset + labelloc [k ]< 256 ) ) ;
      } 
      if ( lkoffset > 0 ) 
      while ( k > 0 ) {
	  
	charremainder [labelchar [k ]]= charremainder [labelchar [k ]]
	+ lkoffset ;
	decr ( k ) ;
      } 
      if ( bchlabel < ligtablesize ) 
      {
	ligkern [nl ].b0 = 255 ;
	ligkern [nl ].b1 = 0 ;
	ligkern [nl ].b2 = ( ( bchlabel + lkoffset ) / 256 ) ;
	ligkern [nl ].b3 = ( ( bchlabel + lkoffset ) % 256 ) ;
	incr ( nl ) ;
      } 
      put2bytes ( tfmfile , 6 + lh + ( ec - bc + 1 ) + nw + nh + nd + ni + nl 
      + lkoffset + nk + ne + np ) ;
      put2bytes ( tfmfile , lh ) ;
      put2bytes ( tfmfile , bc ) ;
      put2bytes ( tfmfile , ec ) ;
      put2bytes ( tfmfile , nw ) ;
      put2bytes ( tfmfile , nh ) ;
      put2bytes ( tfmfile , nd ) ;
      put2bytes ( tfmfile , ni ) ;
      put2bytes ( tfmfile , nl + lkoffset ) ;
      put2bytes ( tfmfile , nk ) ;
      put2bytes ( tfmfile , ne ) ;
      put2bytes ( tfmfile , np ) ;
      {register integer for_end; k = 1 ;for_end = 4 * lh ; if ( k <= 
      for_end) do 
	{
	  if ( headerbyte [k ]< 0 ) 
	  headerbyte [k ]= 0 ;
	  putbyte ( headerbyte [k ], tfmfile ) ;
	} 
      while ( k++ < for_end ) ;} 
      {register integer for_end; k = bc ;for_end = ec ; if ( k <= for_end) 
      do 
	if ( ! charexists [k ]) 
	put4bytes ( tfmfile , 0 ) ;
	else {
	    
	  putbyte ( mem [tfmwidth [k ]].hhfield .lhfield , tfmfile ) ;
	  putbyte ( ( mem [tfmheight [k ]].hhfield .lhfield ) * 16 + mem [
	  tfmdepth [k ]].hhfield .lhfield , tfmfile ) ;
	  putbyte ( ( mem [tfmitalcorr [k ]].hhfield .lhfield ) * 4 + 
	  chartag [k ], tfmfile ) ;
	  putbyte ( charremainder [k ], tfmfile ) ;
	} 
      while ( k++ < for_end ) ;} 
      tfmchanged = 0 ;
      {register integer for_end; k = 1 ;for_end = 4 ; if ( k <= for_end) do 
	{
	  put4bytes ( tfmfile , 0 ) ;
	  p = dimenhead [k ];
	  while ( p != 19 ) {
	      
	    put4bytes ( tfmfile , dimenout ( mem [p + 1 ].cint ) ) ;
	    p = mem [p ].hhfield .v.RH ;
	  } 
	} 
      while ( k++ < for_end ) ;} 
      {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) 
      do 
	if ( skiptable [k ]< ligtablesize ) 
	{
	  printnl ( 1048 ) ;
	  printint ( k ) ;
	  print ( 1049 ) ;
	  ll = skiptable [k ];
	  do {
	      lll = ligkern [ll ].b0 ;
	    ligkern [ll ].b0 = 128 ;
	    ll = ll - lll ;
	  } while ( ! ( lll == 0 ) ) ;
	} 
      while ( k++ < for_end ) ;} 
      if ( lkstarted ) 
      {
	putbyte ( 255 , tfmfile ) ;
	putbyte ( bchar , tfmfile ) ;
	put2bytes ( tfmfile , 0 ) ;
      } 
      else {
	  register integer for_end; k = 1 ;for_end = lkoffset ; if ( k <= 
      for_end) do 
	{
	  ll = labelloc [labelptr ];
	  if ( bchar < 0 ) 
	  {
	    putbyte ( 254 , tfmfile ) ;
	    putbyte ( 0 , tfmfile ) ;
	  } 
	  else {
	      
	    putbyte ( 255 , tfmfile ) ;
	    putbyte ( bchar , tfmfile ) ;
	  } 
	  put2bytes ( tfmfile , ll + lkoffset ) ;
	  do {
	      decr ( labelptr ) ;
	  } while ( ! ( labelloc [labelptr ]< ll ) ) ;
	} 
      while ( k++ < for_end ) ;} 
      {register integer for_end; k = 0 ;for_end = nl - 1 ; if ( k <= 
      for_end) do 
	tfmqqqq ( ligkern [k ]) ;
      while ( k++ < for_end ) ;} 
      {register integer for_end; k = 0 ;for_end = nk - 1 ; if ( k <= 
      for_end) do 
	put4bytes ( tfmfile , dimenout ( kern [k ]) ) ;
      while ( k++ < for_end ) ;} 
      {register integer for_end; k = 0 ;for_end = ne - 1 ; if ( k <= 
      for_end) do 
	tfmqqqq ( exten [k ]) ;
      while ( k++ < for_end ) ;} 
      {register integer for_end; k = 1 ;for_end = np ; if ( k <= for_end) do 
	if ( k == 1 ) {
	    
	  if ( abs ( param [1 ]) < 134217728L ) 
	  put4bytes ( tfmfile , param [1 ]* 16 ) ;
	  else {
	      
	    incr ( tfmchanged ) ;
	    if ( param [1 ]> 0 ) 
	    put4bytes ( tfmfile , 2147483647L ) ;
	    else put4bytes ( tfmfile , -2147483647L ) ;
	  } 
	} 
	else put4bytes ( tfmfile , dimenout ( param [k ]) ) ;
      while ( k++ < for_end ) ;} 
      if ( tfmchanged > 0 ) 
      {
	if ( tfmchanged == 1 ) 
	printnl ( 1050 ) ;
	else {
	    
	  printnl ( 40 ) ;
	  printint ( tfmchanged ) ;
	  print ( 1051 ) ;
	} 
	print ( 1052 ) ;
      } 
	;
#ifdef STAT
      if ( internal [12 ]> 0 ) 
      {
	{ putc ( ' ' ,  logfile );  putc ( '\n',  logfile ); }
	if ( bchlabel < ligtablesize ) 
	decr ( nl ) ;
	fprintf ( logfile , "%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s\n",  "(You used " , (long)nw , "w," , (long)nh , "h," , (long)nd , "d," ,         (long)ni , "i," , (long)nl , "l," , (long)nk , "k," , (long)ne , "e," , (long)np ,         "p metric file positions" ) ;
	fprintf ( logfile , "%s%s%ld%s%ld%s%ld%s\n",  "  out of " , "256w,16h,16d,64i," , (long)ligtablesize ,         "l," , (long)maxkerns , "k,256e," , (long)maxfontdimen , "p)" ) ;
      } 
#endif /* STAT */
      printnl ( 1047 ) ;
      printfilename ( 0 , metricfilename , 0 ) ;
      printchar ( 46 ) ;
      bclose ( tfmfile ) ;
    } 
    if ( gfprevptr > 0 ) 
    {
      {
	gfbuf [gfptr ]= 248 ;
	incr ( gfptr ) ;
	if ( gfptr == gflimit ) 
	gfswap () ;
      } 
      gffour ( gfprevptr ) ;
      gfprevptr = gfoffset + gfptr - 5 ;
      gffour ( internal [26 ]* 16 ) ;
      {register integer for_end; k = 1 ;for_end = 4 ; if ( k <= for_end) do 
	{
	  gfbuf [gfptr ]= headerbyte [k ];
	  incr ( gfptr ) ;
	  if ( gfptr == gflimit ) 
	  gfswap () ;
	} 
      while ( k++ < for_end ) ;} 
      gffour ( internal [27 ]) ;
      gffour ( internal [28 ]) ;
      gffour ( gfminm ) ;
      gffour ( gfmaxm ) ;
      gffour ( gfminn ) ;
      gffour ( gfmaxn ) ;
      {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) 
      do 
	if ( charexists [k ]) 
	{
	  x = gfdx [k ]/ 65536L ;
	  if ( ( gfdy [k ]== 0 ) && ( x >= 0 ) && ( x < 256 ) && ( gfdx [k 
	  ]== x * 65536L ) ) 
	  {
	    {
	      gfbuf [gfptr ]= 246 ;
	      incr ( gfptr ) ;
	      if ( gfptr == gflimit ) 
	      gfswap () ;
	    } 
	    {
	      gfbuf [gfptr ]= k ;
	      incr ( gfptr ) ;
	      if ( gfptr == gflimit ) 
	      gfswap () ;
	    } 
	    {
	      gfbuf [gfptr ]= x ;
	      incr ( gfptr ) ;
	      if ( gfptr == gflimit ) 
	      gfswap () ;
	    } 
	  } 
	  else {
	      
	    {
	      gfbuf [gfptr ]= 245 ;
	      incr ( gfptr ) ;
	      if ( gfptr == gflimit ) 
	      gfswap () ;
	    } 
	    {
	      gfbuf [gfptr ]= k ;
	      incr ( gfptr ) ;
	      if ( gfptr == gflimit ) 
	      gfswap () ;
	    } 
	    gffour ( gfdx [k ]) ;
	    gffour ( gfdy [k ]) ;
	  } 
	  x = mem [tfmwidth [k ]+ 1 ].cint ;
	  if ( abs ( x ) > maxtfmdimen ) {
	      
	    if ( x > 0 ) 
	    x = 16777215L ;
	    else x = -16777215L ;
	  } 
	  else x = makescaled ( x * 16 , internal [26 ]) ;
	  gffour ( x ) ;
	  gffour ( charptr [k ]) ;
	} 
      while ( k++ < for_end ) ;} 
      {
	gfbuf [gfptr ]= 249 ;
	incr ( gfptr ) ;
	if ( gfptr == gflimit ) 
	gfswap () ;
      } 
      gffour ( gfprevptr ) ;
      {
	gfbuf [gfptr ]= 131 ;
	incr ( gfptr ) ;
	if ( gfptr == gflimit ) 
	gfswap () ;
      } 
      k = 4 + ( ( gfbufsize - gfptr ) % 4 ) ;
      while ( k > 0 ) {
	  
	{
	  gfbuf [gfptr ]= 223 ;
	  incr ( gfptr ) ;
	  if ( gfptr == gflimit ) 
	  gfswap () ;
	} 
	decr ( k ) ;
      } 
      if ( gflimit == halfbuf ) 
      writegf ( halfbuf , gfbufsize - 1 ) ;
      if ( gfptr > ( 2147483647L - gfoffset ) ) 
      {
	gfprevptr = 0 ;
	fatalerror ( 1053 ) ;
      } 
      if ( gfptr > 0 ) 
      writegf ( 0 , gfptr - 1 ) ;
      printnl ( 1064 ) ;
      printfilename ( 0 , outputfilename , 0 ) ;
      print ( 558 ) ;
      printint ( totalchars ) ;
      if ( totalchars != 1 ) 
      print ( 1065 ) ;
      else print ( 1066 ) ;
      print ( 1067 ) ;
      printint ( gfoffset + gfptr ) ;
      print ( 1068 ) ;
      bclose ( gffile ) ;
    } 
  } 
  if ( logopened ) 
  {
    putc ('\n',  logfile );
    aclose ( logfile ) ;
    selector = selector - 2 ;
    if ( selector == 1 ) 
    {
      printnl ( 1076 ) ;
      printfilename ( 0 , texmflogname , 0 ) ;
      printchar ( 46 ) ;
    } 
  } 
  println () ;
  if ( ( editnamestart != 0 ) && ( interaction > 0 ) ) 
  calledit ( strpool , editnamestart , editnamelength , editline ) ;
} 
#ifdef TEXMF_DEBUG
void 
debughelp ( void ) 
{
  /* 888 10 */ integer k, l, m, n  ;
  while ( true ) {
      
    ;
    printnl ( 1083 ) ;
    fflush ( stdout ) ;
    read ( stdin , m ) ;
    if ( m < 0 ) 
    goto lab10 ;
    else if ( m == 0 ) 
    {
      goto lab888 ;
      lab888: m = 0 ;
    } 
    else {
	
      read ( stdin , n ) ;
      switch ( m ) 
      {case 1 : 
	printword ( mem [n ]) ;
	break ;
      case 2 : 
	printint ( mem [n ].hhfield .lhfield ) ;
	break ;
      case 3 : 
	printint ( mem [n ].hhfield .v.RH ) ;
	break ;
      case 4 : 
	{
	  printint ( eqtb [n ].lhfield ) ;
	  printchar ( 58 ) ;
	  printint ( eqtb [n ].v.RH ) ;
	} 
	break ;
      case 5 : 
	printvariablename ( n ) ;
	break ;
      case 6 : 
	printint ( internal [n ]) ;
	break ;
      case 7 : 
	doshowdependencies () ;
	break ;
      case 9 : 
	showtokenlist ( n , 0 , 100000L , 0 ) ;
	break ;
      case 10 : 
	slowprint ( n ) ;
	break ;
      case 11 : 
	checkmem ( n > 0 ) ;
	break ;
      case 12 : 
	searchmem ( n ) ;
	break ;
      case 13 : 
	{
	  read ( stdin , l ) ;
	  printcmdmod ( n , l ) ;
	} 
	break ;
      case 14 : 
	{register integer for_end; k = 0 ;for_end = n ; if ( k <= for_end) 
	do 
	  print ( buffer [k ]) ;
	while ( k++ < for_end ) ;} 
	break ;
      case 15 : 
	panicking = ! panicking ;
	break ;
	default: 
	print ( 63 ) ;
	break ;
      } 
    } 
  } 
  lab10: ;
} 
#endif /* TEXMF_DEBUG */
