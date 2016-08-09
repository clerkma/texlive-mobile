#define EXTERN extern
#include "alephd.h"

void 
initialize ( void ) 
{
  initialize_regmem 
  integer i  ;
  integer k  ;
  hyphpointer z  ;
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
    xchr [i ]= chr ( i ) ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 127 ;for_end = 255 ; if ( i <= for_end) do 
    xchr [i ]= chr ( i ) ;
  while ( i++ < for_end ) ;} 
  initeqtbtable () ;
  if ( interactionoption == 4 ) 
  interaction = 3 ;
  else interaction = interactionoption ;
  deletionsallowed = true ;
  setboxallowed = true ;
  errorcount = 0 ;
  helpptr = 0 ;
  useerrhelp = false ;
  interrupt = 0 ;
  OKtointerrupt = true ;
	;
#ifdef TEXMF_DEBUG
  wasmemend = memmin ;
  waslomax = memmin ;
  washimin = memmax ;
  panicking = false ;
#endif /* TEXMF_DEBUG */
  nestptr = 0 ;
  maxneststack = 0 ;
  curlist .modefield = 1 ;
  curlist .headfield = memtop - 1 ;
  curlist .tailfield = memtop - 1 ;
  curlist .eTeXauxfield = 0 ;
  curlist .auxfield .cint = -65536000L ;
  curlist .mlfield = 0 ;
  curlist .pgfield = 0 ;
  shownmode = 0 ;
  curlist .dirsfield = 0 ;
  curlist .mathfield = false ;
  curlist .localparfield = 0 ;
  curlist .localparboolfield = false ;
  pagecontents = 0 ;
  pagetail = memtop - 2 ;
  lastglue = 1073741823L ;
  lastpenalty = 0 ;
  lastkern = 0 ;
  pagesofar [7 ]= 0 ;
  pagemaxdepth = 0 ;
  nonewcontrolsequence = true ;
  saveptr = 0 ;
  curlevel = 1 ;
  curgroup = 0 ;
  curboundary = 0 ;
  maxsavestack = 0 ;
  magset = 0 ;
  curmark [0 ]= 0 ;
  curmark [1 ]= 0 ;
  curmark [2 ]= 0 ;
  curmark [3 ]= 0 ;
  curmark [4 ]= 0 ;
  curval = 0 ;
  curvallevel = 0 ;
  radix = 0 ;
  curorder = 0 ;
  {register integer for_end; k = 0 ;for_end = 16 ; if ( k <= for_end) do 
    readopen [k ]= 2 ;
  while ( k++ < for_end ) ;} 
  condptr = 0 ;
  iflimit = 0 ;
  curif = 0 ;
  ifline = 0 ;
  nullcharacter .b0 = 0 ;
  nullcharacter .b1 = 0 ;
  nullcharacter .b2 = 0 ;
  nullcharacter .b3 = 0 ;
  totalpages = 0 ;
  maxv = 0 ;
  maxh = 0 ;
  maxpush = 0 ;
  lastbop = -1 ;
  doingleaders = false ;
  deadcycles = 0 ;
  curs = -1 ;
  halfbuf = dvibufsize / 2 ;
  dvilimit = dvibufsize ;
  dviptr = 0 ;
  dvioffset = 0 ;
  dvigone = 0 ;
  downptr = 0 ;
  rightptr = 0 ;
  adjusttail = 0 ;
  lastbadness = 0 ;
  packbeginline = 0 ;
  emptyfield .v.RH = 0 ;
  emptyfield .v.LH = 0 ;
  nulldelimiter .b0 = 0 ;
  nulldelimiter .b1 = 0 ;
  nulldelimiter .b2 = 0 ;
  nulldelimiter .b3 = 0 ;
  alignptr = 0 ;
  curalign = 0 ;
  curspan = 0 ;
  curloop = 0 ;
  curhead = 0 ;
  curtail = 0 ;
  tempnowhatsits = 0 ;
  tempnodirs = 0 ;
  temporarydir = 0 ;
  dirptr = 0 ;
  dirtmp = 0 ;
  dirrover = 0 ;
  tempnowhatsits = 0 ;
  maxhyphchar = 256 ;
  {register integer for_end; z = 0 ;for_end = hyphsize ; if ( z <= for_end) 
  do 
    {
      hyphword [z ]= 0 ;
      hyphlist [z ]= 0 ;
      hyphlink [z ]= 0 ;
    } 
  while ( z++ < for_end ) ;} 
  hyphcount = 0 ;
  hyphnext = 608 ;
  if ( hyphnext > hyphsize ) 
  hyphnext = 607 ;
  outputactive = false ;
  insertpenalties = 0 ;
  ligaturepresent = false ;
  cancelboundary = false ;
  lfthit = false ;
  rthit = false ;
  leftghost = false ;
  rightghost = false ;
  newleftghost = false ;
  newrightghost = false ;
  insdisc = false ;
  aftertoken = 0 ;
  longhelpseen = false ;
  formatident = 0 ;
  {register integer for_end; k = 0 ;for_end = 17 ; if ( k <= for_end) do 
    writeopen [k ]= false ;
  while ( k++ < for_end ) ;} 
  setneweqtbint ( 1049479L , 0 ) ;
  setneweqtbint ( 1049480L , 0 ) ;
  setneweqtbint ( 1049481L , 0 ) ;
  setneweqtbint ( 1049482L , 0 ) ;
  setneweqtbint ( 1049483L , 0 ) ;
  packdirection = -1 ;
  setneweqtbsc ( 1180578L , 55380984L ) ;
  setneweqtbsc ( 1180577L , 39158276L ) ;
  setneweqtbsc ( 1180580L , 4736287L ) ;
  setneweqtbsc ( 1180579L , 4736287L ) ;
  {register integer for_end; k = 0 ;for_end = 7 ; if ( k <= for_end) do 
    {
      dirprimary [k ]= 0 ;
      dirprimary [k + 8 ]= 1 ;
      dirprimary [k + 16 ]= 2 ;
      dirprimary [k + 24 ]= 3 ;
    } 
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = 0 ;for_end = 3 ; if ( k <= for_end) do 
    {
      dirsecondary [k ]= 1 ;
      dirsecondary [k + 4 ]= 3 ;
      dirsecondary [k + 8 ]= 0 ;
      dirsecondary [k + 12 ]= 2 ;
      dirsecondary [k + 16 ]= 1 ;
      dirsecondary [k + 20 ]= 3 ;
      dirsecondary [k + 24 ]= 0 ;
      dirsecondary [k + 28 ]= 2 ;
    } 
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = 0 ;for_end = 7 ; if ( k <= for_end) do 
    {
      dirtertiary [k * 4 ]= 0 ;
      dirtertiary [k * 4 + 1 ]= 1 ;
      dirtertiary [k * 4 + 2 ]= 2 ;
      dirtertiary [k * 4 + 3 ]= 3 ;
    } 
  while ( k++ < for_end ) ;} 
  dirrearrange [0 ]= 0 ;
  dirrearrange [1 ]= 0 ;
  dirrearrange [2 ]= 1 ;
  dirrearrange [3 ]= 1 ;
  dirnames [0 ]= 84 ;
  dirnames [1 ]= 76 ;
  dirnames [2 ]= 66 ;
  dirnames [3 ]= 82 ;
  pseudofiles = 0 ;
  samark = 0 ;
  sanull .hh .v.LH = 0 ;
  sanull .hh .v.RH = 0 ;
  sachain = 0 ;
  salevel = 0 ;
  discptr [2 ]= 0 ;
  discptr [3 ]= 0 ;
  editnamestart = 0 ;
  stopatspace = true ;
	;
#ifdef INITEX
  if ( iniversion ) 
  {
    {register integer for_end; k = membot + 1 ;for_end = membot + 23 ; if ( 
    k <= for_end) do 
      mem [k ].cint = 0 ;
    while ( k++ < for_end ) ;} 
    k = membot ;
    while ( k <= membot + 23 ) {
	
      mem [k ].hh .v.RH = 1 ;
      mem [k ].hh.b0 = 0 ;
      mem [k ].hh.b1 = 0 ;
      k = k + 4 ;
    } 
    mem [membot + 6 ].cint = 65536L ;
    mem [membot + 4 ].hh.b0 = 1 ;
    mem [membot + 10 ].cint = 65536L ;
    mem [membot + 8 ].hh.b0 = 2 ;
    mem [membot + 14 ].cint = 65536L ;
    mem [membot + 12 ].hh.b0 = 3 ;
    mem [membot + 18 ].cint = 65536L ;
    mem [membot + 16 ].hh.b0 = 2 ;
    mem [membot + 19 ].cint = 65536L ;
    mem [membot + 16 ].hh.b1 = 2 ;
    mem [membot + 22 ].cint = -65536L ;
    mem [membot + 20 ].hh.b0 = 2 ;
    rover = membot + 24 ;
    mem [rover ].hh .v.RH = 1073741823L ;
    mem [rover ].hh .v.LH = 1000 ;
    mem [rover + 1 ].hh .v.LH = rover ;
    mem [rover + 1 ].hh .v.RH = rover ;
    lomemmax = rover + 1000 ;
    mem [lomemmax ].hh .v.RH = 0 ;
    mem [lomemmax ].hh .v.LH = 0 ;
    {register integer for_end; k = memtop - 13 ;for_end = memtop ; if ( k <= 
    for_end) do 
      mem [k ]= mem [lomemmax ];
    while ( k++ < for_end ) ;} 
    mem [memtop - 10 ].hh .v.LH = 1245190L ;
    mem [memtop - 9 ].hh .v.RH = 65536L ;
    mem [memtop - 9 ].hh .v.LH = 0 ;
    mem [memtop - 7 ].hh.b0 = 1 ;
    mem [memtop - 6 ].hh .v.LH = 1073741823L ;
    mem [memtop - 7 ].hh.b1 = 0 ;
    mem [memtop ].hh.b1 = 255 ;
    mem [memtop ].hh.b0 = 1 ;
    mem [memtop ].hh .v.RH = memtop ;
    mem [memtop - 2 ].hh.b0 = 10 ;
    mem [memtop - 2 ].hh.b1 = 0 ;
    avail = 0 ;
    memend = memtop ;
    himemmin = memtop - 13 ;
    varused = membot + 24 - membot ;
    dynused = 14 ;
    seteqtype ( 393229L , 118 ) ;
    setequiv ( 393229L , 0 ) ;
    seteqlevel ( 393229L , 0 ) ;
    setequiv ( 393230L , membot ) ;
    seteqlevel ( 393230L , 1 ) ;
    seteqtype ( 393230L , 134 ) ;
    mem [membot ].hh .v.RH = mem [membot ].hh .v.RH + 131090L ;
    setequiv ( 524320L , 0 ) ;
    seteqtype ( 524320L , 135 ) ;
    seteqlevel ( 524320L , 1 ) ;
    setequiv ( 721741L , 5 ) ;
    setequiv ( 721760L , 10 ) ;
    setequiv ( 721820L , 0 ) ;
    setequiv ( 721765L , 14 ) ;
    setequiv ( 721855L , 15 ) ;
    setequiv ( 721728L , 9 ) ;
    {register integer for_end; k = 48 ;for_end = 57 ; if ( k <= for_end) do 
      setequiv ( 983872L + k , k + 117440512L ) ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 65 ;for_end = 90 ; if ( k <= for_end) do 
      {
	setequiv ( 721728L + k , 11 ) ;
	setequiv ( 721728L + k + 32 , 11 ) ;
	setequiv ( 983872L + k , k + 117506048L ) ;
	setequiv ( 983872L + k + 32 , k + 117506080L ) ;
	setequiv ( 787264L + k , k + 32 ) ;
	setequiv ( 787264L + k + 32 , k + 32 ) ;
	setequiv ( 852800L + k , k ) ;
	setequiv ( 852800L + k + 32 , k ) ;
	setequiv ( 918336L + k , 999 ) ;
      } 
    while ( k++ < for_end ) ;} 
    setneweqtbint ( 1049425L , 1000 ) ;
    setneweqtbint ( 1049409L , 10000 ) ;
    setneweqtbint ( 1049449L , 1 ) ;
    setneweqtbint ( 1049448L , 25 ) ;
    setneweqtbint ( 1049453L , 92 ) ;
    setneweqtbint ( 1049456L , 13 ) ;
    setneweqtbint ( 1049467L , 1 ) ;
    setequiv ( 1115066L , 0 ) ;
    setequiv1 ( 1115066L , 0 ) ;
    hashused = 196610L ;
    cscount = 0 ;
    seteqtype ( 196619L , 133 ) ;
    sethashtext ( 1442735L , 65792L ) ;
    fontptr = 0 ;
    allocatefonttable ( 0 , 152 ) ;
    fonttables [0 ][ 0 ].cint = 152 ;
    fonttables [0 ][ 15 ].cint = false ;
    fonttables [0 ][ 10 ].cint = 66130L ;
    fonttables [0 ][ 11 ].cint = 65624L ;
    fonttables [0 ][ 16 ].cint = 45 ;
    fonttables [0 ][ 17 ].cint = -1 ;
    fonttables [0 ][ 18 ].cint = 0 ;
    fonttables [0 ][ 19 ].cint = 65536L ;
    fonttables [0 ][ 20 ].cint = 65536L ;
    fonttables [0 ][ 12 ].cint = 1 ;
    fonttables [0 ][ 13 ].cint = 0 ;
    fonttables [0 ][ 6 ].cint = 0 ;
    fonttables [0 ][ 7 ].cint = 0 ;
    fonttables [0 ][ 34 ].cint = 44 ;
    fonttables [0 ][ 35 ].cint = 44 ;
    fonttables [0 ][ 22 ].cint = 44 ;
    fonttables [0 ][ 23 ].cint = 44 ;
    fonttables [0 ][ 24 ].cint = 44 ;
    fonttables [0 ][ 25 ].cint = 44 ;
    fonttables [0 ][ 26 ].cint = 44 ;
    fonttables [0 ][ 27 ].cint = 44 ;
    fonttables [0 ][ 28 ].cint = 44 ;
    fonttables [0 ][ 29 ].cint = 44 ;
    fonttables [0 ][ 30 ].cint = 44 ;
    fonttables [0 ][ 31 ].cint = 44 ;
    fonttables [0 ][ 32 ].cint = 44 ;
    fonttables [0 ][ 33 ].cint = 44 ;
    fonttables [0 ][ 36 ].cint = 44 ;
    fonttables [0 ][ 37 ].cint = 44 ;
    fonttables [0 ][ 38 ].cint = 44 ;
    fonttables [0 ][ 39 ].cint = 44 ;
    fonttables [0 ][ 40 ].cint = 44 ;
    fonttables [0 ][ 41 ].cint = 44 ;
    fonttables [0 ][ 42 ].cint = 44 ;
    fonttables [0 ][ 14 ].cint = 0 ;
    fonttables [0 ][ 8 ].cint = 7 ;
    fonttables [0 ][ 43 ].cint = 43 ;
    fonttables [0 ][ 5 ].cint = 0 ;
    {register integer for_end; k = 1 ;for_end = 7 ; if ( k <= for_end) do 
      fonttables [0 ][ fonttables [0 ][ 43 ].cint + k ].cint = 0 ;
    while ( k++ < for_end ) ;} 
    activeminptr = 0 ;
    activereal = 0 ;
    ocpptr = 0 ;
    allocateocptable ( 0 , 17 ) ;
    ocptables [0 ][ 0 ]= 17 ;
    ocptables [0 ][ 1 ]= 66157L ;
    ocptables [0 ][ 2 ]= 65624L ;
    ocptables [0 ][ 3 ]= 0 ;
    ocptables [0 ][ 4 ]= 0 ;
    ocptables [0 ][ 5 ]= 1 ;
    ocptables [0 ][ 6 ]= 1 ;
    ocptables [0 ][ 7 ]= 0 ;
    ocptables [0 ][ 8 ]= 1 ;
    ocptables [f ][ 9 ]= 11 ;
    ocptables [f ][ 10 ]= 11 ;
    ocptables [0 ][ 11 ]= 13 ;
    ocptables [0 ][ 12 ]= 16 ;
    ocptables [0 ][ 13 ]= 23 ;
    ocptables [0 ][ 14 ]= 3 ;
    ocptables [0 ][ 15 ]= 36 ;
    ocplistmemptr = 2 ;
    ocplistinfo [0 ].hh.b1 = 0 ;
    ocplistinfo [1 ].cint = ocpmaxint ;
    ocplistinfo [0 ].hh.b0 = 0 ;
    ocplistptr = 0 ;
    ocplistlist [0 ]= 0 ;
    ocplstackmemptr = 1 ;
    {register integer for_end; k = - (integer) trieopsize ;for_end = 
    trieopsize ; if ( k <= for_end) do 
      trieophash [k ]= 0 ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      trieused [k ]= 0 ;
    while ( k++ < for_end ) ;} 
    trieopptr = 0 ;
    trienotready = true ;
    sethashtext ( 1442726L , 66554L ) ;
    if ( iniversion ) 
    formatident = 66630L ;
    sethashtext ( 1442734L , 66681L ) ;
    seteqlevel ( 196618L , 1 ) ;
    seteqtype ( 196618L , 130 ) ;
    setequiv ( 196618L , 0 ) ;
    eTeXmode = 0 ;
    maxregnum = 255 ;
    maxreghelpline = 66788L ;
  } 
#endif /* INITEX */
} 
#ifdef INITEX
boolean 
getstringsstarted ( void ) 
{
  /* 30 10 */ register boolean Result; getstringsstarted_regmem 
  strnumber g  ;
  poolptr = 0 ;
  strptr = 0 ;
  strstartar [0 ]= 0 ;
  strstartar [1 ]= 0 ;
  {
    strptr = 65536L ;
  } 
  g = loadpoolstrings ( ( poolsize - stringvacancies ) ) ;
  if ( g == 0 ) 
  {
    ;
    fprintf ( stdout , "%s\n",  "! You have to increase POOLSIZE." ) ;
    Result = false ;
    return Result ;
  } 
  Result = true ;
  return Result ;
} 
#endif /* INITEX */
#ifdef INITEX
void 
sortavail ( void ) 
{
  sortavail_regmem 
  halfword p, q, r  ;
  halfword oldrover  ;
  p = getnode ( 1073741824L ) ;
  p = mem [rover + 1 ].hh .v.RH ;
  mem [rover + 1 ].hh .v.RH = 1073741823L ;
  oldrover = rover ;
  while ( p != oldrover ) if ( p < rover ) 
  {
    q = p ;
    p = mem [q + 1 ].hh .v.RH ;
    mem [q + 1 ].hh .v.RH = rover ;
    rover = q ;
  } 
  else {
      
    q = rover ;
    while ( mem [q + 1 ].hh .v.RH < p ) q = mem [q + 1 ].hh .v.RH ;
    r = mem [p + 1 ].hh .v.RH ;
    mem [p + 1 ].hh .v.RH = mem [q + 1 ].hh .v.RH ;
    mem [q + 1 ].hh .v.RH = p ;
    p = r ;
  } 
  p = rover ;
  while ( mem [p + 1 ].hh .v.RH != 1073741823L ) {
      
    mem [mem [p + 1 ].hh .v.RH + 1 ].hh .v.LH = p ;
    p = mem [p + 1 ].hh .v.RH ;
  } 
  mem [p + 1 ].hh .v.RH = rover ;
  mem [rover + 1 ].hh .v.LH = p ;
} 
#endif /* INITEX */
#ifdef INITEX
void 
zprimitive ( strnumber s , quarterword c , halfword o ) 
{
  primitive_regmem 
  poolpointer k  ;
  integer j  ;
  smallnumber l  ;
  if ( s <= 65535L ) 
  curval = s + 65537L ;
  else {
      
    k = strstartar [s - 65536L ];
    l = strstartar [s - 65535L ]- k ;
    if ( first + l > bufsize + 1 ) 
    overflow ( 65542L , bufsize ) ;
    {register integer for_end; j = 0 ;for_end = l - 1 ; if ( j <= for_end) 
    do 
      buffer [first + j ]= strpool [k + j ];
    while ( j++ < for_end ) ;} 
    curval = idlookup ( first , l ) ;
    {
      decr ( strptr ) ;
      poolptr = strstartar [strptr - 65536L ];
    } 
    sethashtext ( 1246116L + curval , s ) ;
  } 
  seteqlevel ( curval , 1 ) ;
  seteqtype ( curval , c ) ;
  setequiv ( curval , o ) ;
} 
#endif /* INITEX */
#ifdef INITEX
quarterword 
znewtrieop ( smallnumber d , smallnumber n , quarterword v ) 
{
  /* 10 */ register quarterword Result; newtrieop_regmem 
  integer h  ;
  quarterword u  ;
  integer l  ;
  h = abs ( n + 313 * d + 361 * v + 1009 * curlang ) % ( trieopsize - 
  negtrieopsize ) + negtrieopsize ;
  while ( true ) {
      
    l = trieophash [h ];
    if ( l == 0 ) 
    {
      if ( trieopptr == trieopsize ) 
      overflow ( 66305L , trieopsize ) ;
      u = trieused [curlang ];
      if ( u == 65535L ) 
      overflow ( 66306L , 65535L ) ;
      incr ( trieopptr ) ;
      incr ( u ) ;
      trieused [curlang ]= u ;
      hyfdistance [trieopptr ]= d ;
      hyfnum [trieopptr ]= n ;
      hyfnext [trieopptr ]= v ;
      trieoplang [trieopptr ]= curlang ;
      trieophash [h ]= trieopptr ;
      trieopval [trieopptr ]= u ;
      Result = u ;
      return Result ;
    } 
    if ( ( hyfdistance [l ]== d ) && ( hyfnum [l ]== n ) && ( hyfnext [l 
    ]== v ) && ( trieoplang [l ]== curlang ) ) 
    {
      Result = trieopval [l ];
      return Result ;
    } 
    if ( h > - (integer) trieopsize ) 
    decr ( h ) ;
    else h = trieopsize ;
  } 
  return Result ;
} 
triepointer 
ztrienode ( triepointer p ) 
{
  /* 10 */ register triepointer Result; trienode_regmem 
  triepointer h  ;
  triepointer q  ;
  h = abs ( triec [p ]+ 1009 * trieo [p ]+ 2718 * triel [p ]+ 3142 * 
  trier [p ]) % triesize ;
  while ( true ) {
      
    q = triehash [h ];
    if ( q == 0 ) 
    {
      triehash [h ]= p ;
      Result = p ;
      return Result ;
    } 
    if ( ( triec [q ]== triec [p ]) && ( trieo [q ]== trieo [p ]) && ( 
    triel [q ]== triel [p ]) && ( trier [q ]== trier [p ]) ) 
    {
      Result = q ;
      return Result ;
    } 
    if ( h > 0 ) 
    decr ( h ) ;
    else h = triesize ;
  } 
  return Result ;
} 
triepointer 
zcompresstrie ( triepointer p ) 
{
  register triepointer Result; compresstrie_regmem 
  if ( p == 0 ) 
  Result = 0 ;
  else {
      
    triel [p ]= compresstrie ( triel [p ]) ;
    trier [p ]= compresstrie ( trier [p ]) ;
    Result = trienode ( p ) ;
  } 
  return Result ;
} 
void 
zfirstfit ( triepointer p ) 
{
  /* 45 40 */ firstfit_regmem 
  triepointer h  ;
  triepointer z  ;
  triepointer q  ;
  ASCIIcode c  ;
  triepointer l, r  ;
  integer ll  ;
  c = triec [p ];
  z = triemin [c ];
  while ( true ) {
      
    h = z - c ;
    if ( triemax < h + maxhyphchar ) 
    {
      if ( triesize <= h + maxhyphchar ) 
      overflow ( 66307L , triesize ) ;
      do {
	  incr ( triemax ) ;
	trietaken [triemax ]= false ;
	trie [triemax ].v.RH = triemax + 1 ;
	trie [triemax ].v.LH = triemax - 1 ;
      } while ( ! ( triemax == h + maxhyphchar ) ) ;
    } 
    if ( trietaken [h ]) 
    goto lab45 ;
    q = trier [p ];
    while ( q > 0 ) {
	
      if ( trie [h + triec [q ]].v.RH == 0 ) 
      goto lab45 ;
      q = trier [q ];
    } 
    goto lab40 ;
    lab45: z = trie [z ].v.RH ;
  } 
  lab40: trietaken [h ]= true ;
  triehash [p ]= h ;
  q = p ;
  do {
      z = h + triec [q ];
    l = trie [z ].v.LH ;
    r = trie [z ].v.RH ;
    trie [r ].v.LH = l ;
    trie [l ].v.RH = r ;
    trie [z ].v.RH = 0 ;
    if ( l < maxhyphchar ) 
    {
      if ( z < maxhyphchar ) 
      ll = z ;
      else ll = maxhyphchar ;
      do {
	  triemin [l ]= r ;
	incr ( l ) ;
      } while ( ! ( l == ll ) ) ;
    } 
    q = trier [q ];
  } while ( ! ( q == 0 ) ) ;
} 
void 
ztriepack ( triepointer p ) 
{
  triepack_regmem 
  triepointer q  ;
  do {
      q = triel [p ];
    if ( ( q > 0 ) && ( triehash [q ]== 0 ) ) 
    {
      firstfit ( q ) ;
      triepack ( q ) ;
    } 
    p = trier [p ];
  } while ( ! ( p == 0 ) ) ;
} 
void 
ztriefix ( triepointer p ) 
{
  triefix_regmem 
  triepointer q  ;
  ASCIIcode c  ;
  triepointer z  ;
  z = triehash [p ];
  do {
      q = triel [p ];
    c = triec [p ];
    trie [z + c ].v.RH = triehash [q ];
    trie [z + c ].b1 = c ;
    trie [z + c ].b0 = trieo [p ];
    if ( q > 0 ) 
    triefix ( q ) ;
    p = trier [p ];
  } while ( ! ( p == 0 ) ) ;
} 
void 
newpatterns ( void ) 
{
  /* 30 31 */ newpatterns_regmem 
  unsigned char k, l  ;
  boolean digitsensed  ;
  quarterword v  ;
  triepointer p, q  ;
  boolean firstchild  ;
  ASCIIcode c  ;
  if ( trienotready ) 
  {
    if ( neweqtbint ( 1049458L ) <= 0 ) 
    curlang = 0 ;
    else if ( neweqtbint ( 1049458L ) > 255 ) 
    curlang = 0 ;
    else curlang = neweqtbint ( 1049458L ) ;
    scanleftbrace () ;
    k = 0 ;
    hyf [0 ]= 0 ;
    digitsensed = false ;
    while ( true ) {
	
      getxtoken () ;
      switch ( curcmd ) 
      {case 11 : 
      case 12 : 
	if ( digitsensed || ( curchr < 48 ) || ( curchr > 57 ) ) 
	{
	  if ( curchr == 46 ) 
	  curchr = 0 ;
	  else {
	      
	    curchr = newequiv ( 787264L + curchr ) ;
	    if ( curchr == 0 ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66313L ) ;
	      } 
	      {
		helpptr = 1 ;
		helpline [0 ]= 66312L ;
	      } 
	      error () ;
	    } 
	  } 
	  if ( curchr > maxhyphchar ) 
	  maxhyphchar = curchr ;
	  if ( k < 63 ) 
	  {
	    incr ( k ) ;
	    hc [k ]= curchr ;
	    hyf [k ]= 0 ;
	    digitsensed = false ;
	  } 
	} 
	else if ( k < 63 ) 
	{
	  hyf [k ]= curchr - 48 ;
	  digitsensed = true ;
	} 
	break ;
      case 10 : 
      case 2 : 
	{
	  if ( k > 0 ) 
	  {
	    if ( hc [1 ]== 0 ) 
	    hyf [0 ]= 0 ;
	    if ( hc [k ]== 0 ) 
	    hyf [k ]= 0 ;
	    l = k ;
	    v = 0 ;
	    while ( true ) {
		
	      if ( hyf [l ]!= 0 ) 
	      v = newtrieop ( k - l , hyf [l ], v ) ;
	      if ( l > 0 ) 
	      decr ( l ) ;
	      else goto lab31 ;
	    } 
	    lab31: ;
	    q = 0 ;
	    hc [0 ]= curlang ;
	    while ( l <= k ) {
		
	      c = hc [l ];
	      incr ( l ) ;
	      p = triel [q ];
	      firstchild = true ;
	      while ( ( p > 0 ) && ( c > triec [p ]) ) {
		  
		q = p ;
		p = trier [q ];
		firstchild = false ;
	      } 
	      if ( ( p == 0 ) || ( c < triec [p ]) ) 
	      {
		if ( trieptr == triesize ) 
		overflow ( 66307L , triesize ) ;
		incr ( trieptr ) ;
		trier [trieptr ]= p ;
		p = trieptr ;
		triel [p ]= 0 ;
		if ( firstchild ) 
		triel [q ]= p ;
		else trier [q ]= p ;
		triec [p ]= c ;
		trieo [p ]= 0 ;
	      } 
	      q = p ;
	    } 
	    if ( trieo [q ]!= 0 ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66314L ) ;
	      } 
	      {
		helpptr = 1 ;
		helpline [0 ]= 66312L ;
	      } 
	      error () ;
	    } 
	    trieo [q ]= v ;
	  } 
	  if ( curcmd == 2 ) 
	  goto lab30 ;
	  k = 0 ;
	  hyf [0 ]= 0 ;
	  digitsensed = false ;
	} 
	break ;
	default: 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 66311L ) ;
	  } 
	  printesc ( 66309L ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 66312L ;
	  } 
	  error () ;
	} 
	break ;
      } 
    } 
    lab30: ;
    if ( neweqtbint ( 1049477L ) > 0 ) 
    {
      c = curlang ;
      firstchild = false ;
      p = 0 ;
      do {
	  q = p ;
	p = trier [q ];
      } while ( ! ( ( p == 0 ) || ( c <= triec [p ]) ) ) ;
      if ( ( p == 0 ) || ( c < triec [p ]) ) 
      {
	if ( trieptr == triesize ) 
	overflow ( 66307L , triesize ) ;
	incr ( trieptr ) ;
	trier [trieptr ]= p ;
	p = trieptr ;
	triel [p ]= 0 ;
	if ( firstchild ) 
	triel [q ]= p ;
	else trier [q ]= p ;
	triec [p ]= c ;
	trieo [p ]= 0 ;
      } 
      q = p ;
      p = triel [q ];
      firstchild = true ;
      {register integer for_end; c = 0 ;for_end = 255 ; if ( c <= for_end) 
      do 
	if ( ( newequiv ( 787264L + c ) > 0 ) || ( ( c == 255 ) && firstchild 
	) ) 
	{
	  if ( p == 0 ) 
	  {
	    if ( trieptr == triesize ) 
	    overflow ( 66307L , triesize ) ;
	    incr ( trieptr ) ;
	    trier [trieptr ]= p ;
	    p = trieptr ;
	    triel [p ]= 0 ;
	    if ( firstchild ) 
	    triel [q ]= p ;
	    else trier [q ]= p ;
	    triec [p ]= c ;
	    trieo [p ]= 0 ;
	  } 
	  else triec [p ]= c ;
	  trieo [p ]= newequiv ( 787264L + c ) ;
	  q = p ;
	  p = trier [q ];
	  firstchild = false ;
	} 
      while ( c++ < for_end ) ;} 
      if ( firstchild ) 
      triel [q ]= 0 ;
      else trier [q ]= 0 ;
    } 
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66308L ) ;
    } 
    printesc ( 66309L ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 66310L ;
    } 
    error () ;
    mem [memtop - 12 ].hh .v.RH = scantoks ( false , false ) ;
    flushlist ( defref ) ;
  } 
} 
void 
inittrie ( void ) 
{
  inittrie_regmem 
  triepointer p  ;
  integer j, k, t  ;
  triepointer r, s  ;
  twohalves h  ;
  incr ( maxhyphchar ) ;
  opstart [0 ]= -0 ;
  {register integer for_end; j = 1 ;for_end = 255 ; if ( j <= for_end) do 
    opstart [j ]= opstart [j - 1 ]+ trieused [j - 1 ];
  while ( j++ < for_end ) ;} 
  {register integer for_end; j = 1 ;for_end = trieopptr ; if ( j <= for_end) 
  do 
    trieophash [j ]= opstart [trieoplang [j ]]+ trieopval [j ];
  while ( j++ < for_end ) ;} 
  {register integer for_end; j = 1 ;for_end = trieopptr ; if ( j <= for_end) 
  do 
    while ( trieophash [j ]> j ) {
	
      k = trieophash [j ];
      t = hyfdistance [k ];
      hyfdistance [k ]= hyfdistance [j ];
      hyfdistance [j ]= t ;
      t = hyfnum [k ];
      hyfnum [k ]= hyfnum [j ];
      hyfnum [j ]= t ;
      t = hyfnext [k ];
      hyfnext [k ]= hyfnext [j ];
      hyfnext [j ]= t ;
      trieophash [j ]= trieophash [k ];
      trieophash [k ]= k ;
    } 
  while ( j++ < for_end ) ;} 
  {register integer for_end; p = 0 ;for_end = triesize ; if ( p <= for_end) 
  do 
    triehash [p ]= 0 ;
  while ( p++ < for_end ) ;} 
  trier [0 ]= compresstrie ( trier [0 ]) ;
  triel [0 ]= compresstrie ( triel [0 ]) ;
  {register integer for_end; p = 0 ;for_end = trieptr ; if ( p <= for_end) 
  do 
    triehash [p ]= 0 ;
  while ( p++ < for_end ) ;} 
  {register integer for_end; p = 0 ;for_end = 65535L ; if ( p <= for_end) do 
    triemin [p ]= p + 1 ;
  while ( p++ < for_end ) ;} 
  trie [0 ].v.RH = 1 ;
  triemax = 0 ;
  if ( triel [0 ]!= 0 ) 
  {
    firstfit ( triel [0 ]) ;
    triepack ( triel [0 ]) ;
  } 
  if ( trier [0 ]!= 0 ) 
  {
    if ( triel [0 ]== 0 ) 
    {register integer for_end; p = 0 ;for_end = 255 ; if ( p <= for_end) do 
      triemin [p ]= p + 2 ;
    while ( p++ < for_end ) ;} 
    firstfit ( trier [0 ]) ;
    triepack ( trier [0 ]) ;
    hyphstart = triehash [trier [0 ]];
  } 
  h .v.RH = 0 ;
  h .b0 = 0 ;
  h .b1 = 0 ;
  if ( triemax == 0 ) 
  {
    {register integer for_end; r = 0 ;for_end = maxhyphchar ; if ( r <= 
    for_end) do 
      trie [r ]= h ;
    while ( r++ < for_end ) ;} 
    triemax = maxhyphchar ;
  } 
  else {
      
    if ( trier [0 ]> 0 ) 
    triefix ( trier [0 ]) ;
    if ( triel [0 ]> 0 ) 
    triefix ( triel [0 ]) ;
    r = 0 ;
    do {
	s = trie [r ].v.RH ;
      trie [r ]= h ;
      r = s ;
    } while ( ! ( r > triemax ) ) ;
  } 
  trie [0 ].b1 = 63 ;
  trienotready = false ;
} 
#endif /* INITEX */
void 
zlinebreak ( boolean d ) 
{
  /* 30 31 32 33 34 35 22 */ linebreak_regmem 
  boolean autobreaking  ;
  halfword prevp  ;
  halfword q, r, s, prevs  ;
  internalfontnumber f  ;
  smallnumber j  ;
  ASCIIcode c  ;
  packbeginline = curlist .mlfield ;
  mem [memtop - 3 ].hh .v.RH = mem [curlist .headfield ].hh .v.RH ;
  if ( ( curlist .tailfield >= himemmin ) ) 
  {
    mem [curlist .tailfield ].hh .v.RH = newpenalty ( 10000 ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  else if ( mem [curlist .tailfield ].hh.b0 != 10 ) 
  {
    mem [curlist .tailfield ].hh .v.RH = newpenalty ( 10000 ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  else {
      
    mem [curlist .tailfield ].hh.b0 = 12 ;
    deleteglueref ( mem [curlist .tailfield + 1 ].hh .v.LH ) ;
    flushnodelist ( mem [curlist .tailfield + 1 ].hh .v.RH ) ;
    mem [curlist .tailfield + 1 ].cint = 10000 ;
  } 
  finalparglue = newparamglue ( 14 ) ;
  mem [curlist .tailfield ].hh .v.RH = finalparglue ;
  lastlinefill = mem [curlist .tailfield ].hh .v.RH ;
  initcurlang = curlist .pgfield % 65536L ;
  initlhyf = curlist .pgfield / 4194304L ;
  initrhyf = ( curlist .pgfield / 65536L ) % 64 ;
  paragraphdir = mem [mem [curlist .headfield ].hh .v.RH + 7 ].cint ;
  linebreakdir = paragraphdir ;
  {
    dirptr = 0 ;
    {
      dirtmp = newdir ( paragraphdir ) ;
      mem [dirtmp ].hh .v.RH = dirptr ;
      dirptr = dirtmp ;
      dirptr = dirtmp ;
    } 
  } 
  popnest () ;
  noshrinkerroryet = true ;
  if ( ( mem [newequiv ( 393237L ) ].hh.b1 != 0 ) && ( mem [newequiv ( 
  393237L ) + 3 ].cint != 0 ) ) 
  {
    setequiv ( 393237L , finiteshrink ( newequiv ( 393237L ) ) ) ;
  } 
  if ( ( mem [newequiv ( 393238L ) ].hh.b1 != 0 ) && ( mem [newequiv ( 
  393238L ) + 3 ].cint != 0 ) ) 
  {
    setequiv ( 393238L , finiteshrink ( newequiv ( 393238L ) ) ) ;
  } 
  q = newequiv ( 393237L ) ;
  r = newequiv ( 393238L ) ;
  background [1 ]= mem [q + 1 ].cint + mem [r + 1 ].cint ;
  background [2 ]= 0 ;
  background [3 ]= 0 ;
  background [4 ]= 0 ;
  background [5 ]= 0 ;
  background [6 ]= 0 ;
  background [2 + mem [q ].hh.b0 ]= mem [q + 2 ].cint ;
  background [2 + mem [r ].hh.b0 ]= background [2 + mem [r ].hh.b0 ]+ 
  mem [r + 2 ].cint ;
  background [7 ]= mem [q + 3 ].cint + mem [r + 3 ].cint ;
  dolastlinefit = false ;
  activenodesize = 3 ;
  if ( neweqtbint ( 1049475L ) > 0 ) 
  {
    q = mem [lastlinefill + 1 ].hh .v.LH ;
    if ( ( mem [q + 2 ].cint > 0 ) && ( mem [q ].hh.b0 > 0 ) ) {
	
      if ( ( background [3 ]== 0 ) && ( background [4 ]== 0 ) && ( 
      background [5 ]== 0 ) ) 
      {
	dolastlinefit = true ;
	activenodesize = 5 ;
	fillwidth [0 ]= 0 ;
	fillwidth [1 ]= 0 ;
	fillwidth [2 ]= 0 ;
	fillwidth [mem [q ].hh.b0 - 1 ]= mem [q + 2 ].cint ;
      } 
    } 
  } 
  minimumdemerits = 1073741823L ;
  minimaldemerits [3 ]= 1073741823L ;
  minimaldemerits [2 ]= 1073741823L ;
  minimaldemerits [1 ]= 1073741823L ;
  minimaldemerits [0 ]= 1073741823L ;
  if ( newequiv ( 524320L ) == 0 ) {
      
    if ( neweqtbsc ( 1180556L + ( 17 ) ) == 0 ) 
    {
      lastspecialline = 0 ;
      secondwidth = neweqtbsc ( 1180556L + ( 3 ) ) ;
      secondindent = 0 ;
    } 
    else {
	
      lastspecialline = abs ( neweqtbint ( 1049449L ) ) ;
      if ( neweqtbint ( 1049449L ) < 0 ) 
      {
	firstwidth = neweqtbsc ( 1180556L + ( 3 ) ) - abs ( neweqtbsc ( 
	1180556L + ( 17 ) ) ) ;
	if ( neweqtbsc ( 1180556L + ( 17 ) ) >= 0 ) 
	firstindent = neweqtbsc ( 1180556L + ( 17 ) ) ;
	else firstindent = 0 ;
	secondwidth = neweqtbsc ( 1180556L + ( 3 ) ) ;
	secondindent = 0 ;
      } 
      else {
	  
	firstwidth = neweqtbsc ( 1180556L + ( 3 ) ) ;
	firstindent = 0 ;
	secondwidth = neweqtbsc ( 1180556L + ( 3 ) ) - abs ( neweqtbsc ( 
	1180556L + ( 17 ) ) ) ;
	if ( neweqtbsc ( 1180556L + ( 17 ) ) >= 0 ) 
	secondindent = neweqtbsc ( 1180556L + ( 17 ) ) ;
	else secondindent = 0 ;
      } 
    } 
  } 
  else {
      
    lastspecialline = mem [newequiv ( 524320L ) ].hh .v.LH - 1 ;
    secondwidth = mem [newequiv ( 524320L ) + 2 * ( lastspecialline + 1 ) ]
    .cint ;
    secondindent = mem [newequiv ( 524320L ) + 2 * lastspecialline + 1 ]
    .cint ;
  } 
  if ( neweqtbint ( 1049427L ) == 0 ) 
  easyline = lastspecialline ;
  else easyline = 1073741823L ;
  threshold = neweqtbint ( 1049408L ) ;
  if ( threshold >= 0 ) 
  {
	;
#ifdef STAT
    if ( neweqtbint ( 1049440L ) > 0 ) 
    {
      begindiagnostic () ;
      printnl ( 66289L ) ;
    } 
#endif /* STAT */
    secondpass = false ;
    finalpass = false ;
  } 
  else {
      
    threshold = neweqtbint ( 1049409L ) ;
    secondpass = true ;
    finalpass = ( neweqtbsc ( 1180556L + ( 20 ) ) <= 0 ) ;
	;
#ifdef STAT
    if ( neweqtbint ( 1049440L ) > 0 ) 
    begindiagnostic () ;
#endif /* STAT */
  } 
  while ( true ) {
      
    if ( threshold > 10000 ) 
    threshold = 10000 ;
    if ( secondpass ) 
    {
	;
#ifdef INITEX
      if ( trienotready ) 
      inittrie () ;
#endif /* INITEX */
      curlang = initcurlang ;
      lhyf = initlhyf ;
      rhyf = initrhyf ;
      if ( trie [hyphstart + curlang ].b1 != curlang ) 
      hyphindex = 0 ;
      else hyphindex = trie [hyphstart + curlang ].v.RH ;
    } 
    q = getnode ( activenodesize ) ;
    mem [q ].hh.b0 = 0 ;
    mem [q ].hh.b1 = 2 ;
    mem [q ].hh .v.RH = memtop - 7 ;
    mem [q + 1 ].hh .v.RH = 0 ;
    mem [q + 1 ].hh .v.LH = curlist .pgfield + 1 ;
    mem [q + 2 ].cint = 0 ;
    mem [memtop - 7 ].hh .v.RH = q ;
    if ( dolastlinefit ) 
    {
      mem [q + 3 ].cint = 0 ;
      mem [q + 4 ].cint = 0 ;
    } 
    activewidth [1 ]= background [1 ];
    activewidth [2 ]= background [2 ];
    activewidth [3 ]= background [3 ];
    activewidth [4 ]= background [4 ];
    activewidth [5 ]= background [5 ];
    activewidth [6 ]= background [6 ];
    activewidth [7 ]= background [7 ];
    passive = 0 ;
    printednode = memtop - 3 ;
    passnumber = 0 ;
    fontinshortdisplay = 0 ;
    curp = mem [memtop - 3 ].hh .v.RH ;
    autobreaking = true ;
    prevp = curp ;
    if ( mem [curp ].hh.b1 == 6 ) 
    {
      internalpeninter = mem [curp + 1 ].cint ;
      internalpenbroken = mem [curp + 2 ].cint ;
      initinternalleftbox = mem [curp + 3 ].cint ;
      initinternalleftboxwidth = mem [curp + 4 ].cint ;
      internalleftbox = initinternalleftbox ;
      internalleftboxwidth = initinternalleftboxwidth ;
      internalrightbox = mem [curp + 5 ].cint ;
      internalrightboxwidth = mem [curp + 6 ].cint ;
    } 
    while ( ( curp != 0 ) && ( mem [memtop - 7 ].hh .v.RH != memtop - 7 ) ) 
    {
      if ( ( curp >= himemmin ) ) 
      {
	prevp = curp ;
	do {
	    f = mem [curp ].hh.b0 ;
	  if ( ( ( dirsecondary [linebreakdir ]) % 2 ) == ( ( dirtertiary [
	  linebreakdir ]) % 2 ) ) 
	  {
	    breakchtdp = fonttables [f ][ fonttables [f ][ 34 ].cint - 
	    fonttables [f ][ 5 ].cint + mem [curp ].hh.b1 ].qqqq .b1 ;
	    activewidth [1 ]= activewidth [1 ]+ fonttables [f ][ 
	    fonttables [f ][ 37 ].cint + ( breakchtdp ) / 256 ].cint + 
	    fonttables [f ][ fonttables [f ][ 38 ].cint + ( breakchtdp ) % 
	    256 ].cint ;
	  } 
	  else activewidth [1 ]= activewidth [1 ]+ fonttables [f ][ 
	  fonttables [f ][ 36 ].cint + fonttables [f ][ fonttables [f ][ 
	  34 ].cint - fonttables [f ][ 5 ].cint + mem [curp ].hh.b1 ]
	  .qqqq .b0 ].cint ;
	  curp = mem [curp ].hh .v.RH ;
	} while ( ! ( ! ( curp >= himemmin ) ) ) ;
      } 
      switch ( mem [curp ].hh.b0 ) 
      {case 0 : 
      case 1 : 
	if ( ! ( ( ( dirprimary [mem [curp + 7 ].cint ]) % 2 ) != ( 
	dirprimary [linebreakdir ]% 2 ) ) ) 
	activewidth [1 ]= activewidth [1 ]+ mem [curp + 1 ].cint ;
	else activewidth [1 ]= activewidth [1 ]+ ( mem [curp + 2 ].cint 
	+ mem [curp + 3 ].cint ) ;
	break ;
      case 2 : 
	activewidth [1 ]= activewidth [1 ]+ mem [curp + 1 ].cint ;
	break ;
      case 8 : 
	if ( mem [curp ].hh.b1 == 4 ) 
	{
	  curlang = mem [curp + 1 ].hh .v.RH ;
	  lhyf = mem [curp + 1 ].hh.b0 ;
	  rhyf = mem [curp + 1 ].hh.b1 ;
	} 
	else if ( mem [curp ].hh.b1 == 6 ) 
	{
	  internalpeninter = mem [curp + 1 ].cint ;
	  internalpenbroken = mem [curp + 2 ].cint ;
	  internalleftbox = mem [curp + 3 ].cint ;
	  internalleftboxwidth = mem [curp + 4 ].cint ;
	  internalrightbox = mem [curp + 5 ].cint ;
	  internalrightboxwidth = mem [curp + 6 ].cint ;
	} 
	else if ( mem [curp ].hh.b1 == 7 ) 
	{
	  if ( mem [curp + 1 ].hh .v.LH >= 0 ) 
	  {
	    linebreakdir = mem [curp + 1 ].hh .v.LH ;
	    {
	      dirtmp = getnode ( 4 ) ;
	      mem [dirtmp ].hh.b0 = 8 ;
	      mem [dirtmp ].hh.b1 = 7 ;
	      mem [dirtmp + 1 ].hh .v.LH = mem [curp + 1 ].hh .v.LH ;
	      mem [dirtmp + 1 ].hh .v.RH = mem [curp + 1 ].hh .v.RH ;
	      mem [dirtmp + 3 ].hh .v.LH = mem [curp + 3 ].hh .v.LH ;
	      mem [dirtmp + 2 ].hh .v.LH = mem [curp + 2 ].hh .v.LH ;
	      mem [dirtmp ].hh .v.RH = dirptr ;
	      dirptr = dirtmp ;
	    } 
	  } 
	  else {
	      
	    {
	      dirtmp = dirptr ;
	      dirptr = mem [dirtmp ].hh .v.RH ;
	      freenode ( dirtmp , 4 ) ;
	    } 
	    linebreakdir = mem [dirptr + 1 ].hh .v.LH ;
	  } 
	} 
	break ;
      case 10 : 
	{
	  if ( autobreaking ) 
	  {
	    if ( ( prevp >= himemmin ) ) 
	    trybreak ( 0 , 0 ) ;
	    else if ( ( mem [prevp ].hh.b0 < 9 ) ) 
	    trybreak ( 0 , 0 ) ;
	    else if ( ( mem [prevp ].hh.b0 == 11 ) && ( mem [prevp ].hh.b1 
	    != 1 ) ) 
	    trybreak ( 0 , 0 ) ;
	  } 
	  if ( ( mem [mem [curp + 1 ].hh .v.LH ].hh.b1 != 0 ) && ( mem [
	  mem [curp + 1 ].hh .v.LH + 3 ].cint != 0 ) ) 
	  {
	    mem [curp + 1 ].hh .v.LH = finiteshrink ( mem [curp + 1 ].hh 
	    .v.LH ) ;
	  } 
	  q = mem [curp + 1 ].hh .v.LH ;
	  activewidth [1 ]= activewidth [1 ]+ mem [q + 1 ].cint ;
	  activewidth [2 + mem [q ].hh.b0 ]= activewidth [2 + mem [q ]
	  .hh.b0 ]+ mem [q + 2 ].cint ;
	  activewidth [7 ]= activewidth [7 ]+ mem [q + 3 ].cint ;
	  if ( secondpass && autobreaking ) 
	  {
	    prevs = curp ;
	    s = mem [prevs ].hh .v.RH ;
	    if ( s != 0 ) 
	    {
	      while ( true ) {
		  
		if ( ( s >= himemmin ) ) 
		{
		  c = mem [s ].hh.b1 ;
		  hf = mem [s ].hh.b0 ;
		} 
		else if ( mem [s ].hh.b0 == 6 ) {
		    
		  if ( mem [s + 1 ].hh .v.RH == 0 ) 
		  goto lab22 ;
		  else {
		      
		    q = mem [s + 1 ].hh .v.RH ;
		    c = mem [q ].hh.b1 ;
		    hf = mem [q ].hh.b0 ;
		  } 
		} 
		else if ( ( mem [s ].hh.b0 == 11 ) && ( mem [s ].hh.b1 == 
		0 ) ) 
		goto lab22 ;
		else if ( mem [s ].hh.b0 == 8 ) 
		{
		  if ( mem [s ].hh.b1 == 4 ) 
		  {
		    curlang = mem [s + 1 ].hh .v.RH ;
		    lhyf = mem [s + 1 ].hh.b0 ;
		    rhyf = mem [s + 1 ].hh.b1 ;
		    if ( trie [hyphstart + curlang ].b1 != curlang ) 
		    hyphindex = 0 ;
		    else hyphindex = trie [hyphstart + curlang ].v.RH ;
		  } 
		  goto lab22 ;
		} 
		else goto lab31 ;
		if ( hyphindex == 0 ) 
		hc [0 ]= newequiv ( 787264L + c ) ;
		else if ( trie [hyphindex + c ].b1 != c ) 
		hc [0 ]= 0 ;
		else hc [0 ]= trie [hyphindex + c ].b0 ;
		if ( hc [0 ]!= 0 ) {
		    
		  if ( ( hc [0 ]== c ) || ( neweqtbint ( 1049446L ) > 0 ) ) 
		  goto lab32 ;
		  else goto lab31 ;
		} 
		lab22: prevs = s ;
		s = mem [prevs ].hh .v.RH ;
	      } 
	      lab32: hyfchar = fonttables [hf ][ 16 ].cint ;
	      if ( hyfchar < 0 ) 
	      goto lab31 ;
	      if ( hyfchar > 65535L ) 
	      goto lab31 ;
	      ha = prevs ;
	      if ( lhyf + rhyf > 63 ) 
	      goto lab31 ;
	      hn = 0 ;
	      while ( true ) {
		  
		if ( ( s >= himemmin ) ) 
		{
		  if ( mem [s ].hh.b0 != hf ) 
		  goto lab33 ;
		  hyfbchar = mem [s ].hh.b1 ;
		  c = hyfbchar ;
		  if ( hyphindex == 0 ) 
		  hc [0 ]= newequiv ( 787264L + c ) ;
		  else if ( trie [hyphindex + c ].b1 != c ) 
		  hc [0 ]= 0 ;
		  else hc [0 ]= trie [hyphindex + c ].b0 ;
		  if ( hc [0 ]== 0 ) 
		  goto lab33 ;
		  if ( newequiv ( 787264L + c ) > maxhyphchar ) 
		  goto lab33 ;
		  if ( hn == 63 ) 
		  goto lab33 ;
		  hb = s ;
		  incr ( hn ) ;
		  hu [hn ]= c ;
		  hc [hn ]= hc [0 ];
		  hyfbchar = 65536L ;
		} 
		else if ( mem [s ].hh.b0 == 6 ) 
		{
		  if ( mem [s + 1 ].hh.b0 != hf ) 
		  goto lab33 ;
		  j = hn ;
		  q = mem [s + 1 ].hh .v.RH ;
		  if ( q > 0 ) 
		  hyfbchar = mem [q ].hh.b1 ;
		  while ( q > 0 ) {
		      
		    c = mem [q ].hh.b1 ;
		    if ( hyphindex == 0 ) 
		    hc [0 ]= newequiv ( 787264L + c ) ;
		    else if ( trie [hyphindex + c ].b1 != c ) 
		    hc [0 ]= 0 ;
		    else hc [0 ]= trie [hyphindex + c ].b0 ;
		    if ( hc [0 ]== 0 ) 
		    goto lab33 ;
		    if ( newequiv ( 787264L + c ) > maxhyphchar ) 
		    goto lab33 ;
		    if ( j == 63 ) 
		    goto lab33 ;
		    incr ( j ) ;
		    hu [j ]= c ;
		    hc [j ]= hc [0 ];
		    q = mem [q ].hh .v.RH ;
		  } 
		  hb = s ;
		  hn = j ;
		  if ( odd ( mem [s ].hh.b1 ) ) 
		  hyfbchar = fonttables [hf ][ 19 ].cint ;
		  else hyfbchar = 65536L ;
		} 
		else if ( ( mem [s ].hh.b0 == 11 ) && ( mem [s ].hh.b1 == 
		0 ) ) 
		{
		  hb = s ;
		  hyfbchar = fonttables [hf ][ 19 ].cint ;
		} 
		else goto lab33 ;
		s = mem [s ].hh .v.RH ;
	      } 
	      lab33: ;
	      if ( hn < lhyf + rhyf ) 
	      goto lab31 ;
	      while ( true ) {
		  
		if ( ! ( ( s >= himemmin ) ) ) 
		switch ( mem [s ].hh.b0 ) 
		{case 6 : 
		  ;
		  break ;
		case 11 : 
		  if ( mem [s ].hh.b1 != 0 ) 
		  goto lab34 ;
		  break ;
		case 8 : 
		case 10 : 
		case 12 : 
		case 3 : 
		case 5 : 
		case 4 : 
		  goto lab34 ;
		  break ;
		  default: 
		  goto lab31 ;
		  break ;
		} 
		s = mem [s ].hh .v.RH ;
	      } 
	      lab34: ;
	      hyphenate () ;
	    } 
	    lab31: ;
	  } 
	} 
	break ;
      case 11 : 
	if ( mem [curp ].hh.b1 == 1 ) 
	{
	  if ( ! ( mem [curp ].hh .v.RH >= himemmin ) && autobreaking ) {
	      
	    if ( mem [mem [curp ].hh .v.RH ].hh.b0 == 10 ) 
	    trybreak ( 0 , 0 ) ;
	  } 
	  activewidth [1 ]= activewidth [1 ]+ mem [curp + 1 ].cint ;
	} 
	else activewidth [1 ]= activewidth [1 ]+ mem [curp + 1 ].cint ;
	break ;
      case 6 : 
	{
	  f = mem [curp + 1 ].hh.b0 ;
	  if ( ( ( dirsecondary [linebreakdir ]) % 2 ) == ( ( dirtertiary [
	  linebreakdir ]) % 2 ) ) 
	  {
	    breakchtdp = fonttables [f ][ fonttables [f ][ 34 ].cint - 
	    fonttables [f ][ 5 ].cint + mem [curp + 1 ].hh.b1 ].qqqq .b1 
	    ;
	    activewidth [1 ]= activewidth [1 ]+ fonttables [f ][ 
	    fonttables [f ][ 37 ].cint + ( breakchtdp ) / 256 ].cint + 
	    fonttables [f ][ fonttables [f ][ 38 ].cint + ( breakchtdp ) % 
	    256 ].cint ;
	  } 
	  else activewidth [1 ]= activewidth [1 ]+ fonttables [f ][ 
	  fonttables [f ][ 36 ].cint + fonttables [f ][ fonttables [f ][ 
	  34 ].cint - fonttables [f ][ 5 ].cint + mem [curp + 1 ].hh.b1 ]
	  .qqqq .b0 ].cint ;
	} 
	break ;
      case 7 : 
	{
	  s = mem [curp + 1 ].hh .v.LH ;
	  discwidth = 0 ;
	  if ( s == 0 ) 
	  trybreak ( neweqtbint ( 1049412L ) , 1 ) ;
	  else {
	      
	    do {
		if ( ( s >= himemmin ) ) 
	      {
		f = mem [s ].hh.b0 ;
		if ( ( ( dirsecondary [linebreakdir ]) % 2 ) == ( ( 
		dirtertiary [linebreakdir ]) % 2 ) ) 
		{
		  breakchtdp = fonttables [f ][ fonttables [f ][ 34 ].cint 
		  - fonttables [f ][ 5 ].cint + mem [s ].hh.b1 ].qqqq .b1 
		  ;
		  discwidth = discwidth + fonttables [f ][ fonttables [f ][ 
		  37 ].cint + ( breakchtdp ) / 256 ].cint + fonttables [f 
		  ][ fonttables [f ][ 38 ].cint + ( breakchtdp ) % 256 ]
		  .cint ;
		} 
		else discwidth = discwidth + fonttables [f ][ fonttables [f 
		][ 36 ].cint + fonttables [f ][ fonttables [f ][ 34 ].cint 
		- fonttables [f ][ 5 ].cint + mem [s ].hh.b1 ].qqqq .b0 ]
		.cint ;
	      } 
	      else switch ( mem [s ].hh.b0 ) 
	      {case 6 : 
		{
		  f = mem [s + 1 ].hh.b0 ;
		  if ( ( ( dirsecondary [linebreakdir ]) % 2 ) == ( ( 
		  dirtertiary [linebreakdir ]) % 2 ) ) 
		  {
		    breakchtdp = fonttables [f ][ fonttables [f ][ 34 ]
		    .cint - fonttables [f ][ 5 ].cint + mem [s + 1 ].hh.b1 
		    ].qqqq .b1 ;
		    discwidth = discwidth + fonttables [f ][ fonttables [f 
		    ][ 37 ].cint + ( breakchtdp ) / 256 ].cint + fonttables 
		    [f ][ fonttables [f ][ 38 ].cint + ( breakchtdp ) % 256 
		    ].cint ;
		  } 
		  else discwidth = discwidth + fonttables [f ][ fonttables [
		  f ][ 36 ].cint + fonttables [f ][ fonttables [f ][ 34 ]
		  .cint - fonttables [f ][ 5 ].cint + mem [s + 1 ].hh.b1 ]
		  .qqqq .b0 ].cint ;
		} 
		break ;
	      case 0 : 
	      case 1 : 
		if ( ! ( ( ( dirprimary [mem [s + 7 ].cint ]) % 2 ) != ( 
		dirprimary [linebreakdir ]% 2 ) ) ) 
		discwidth = discwidth + mem [s + 1 ].cint ;
		else discwidth = discwidth + ( mem [s + 2 ].cint + mem [s + 
		3 ].cint ) ;
		break ;
	      case 2 : 
	      case 11 : 
		discwidth = discwidth + mem [s + 1 ].cint ;
		break ;
		default: 
		confusion ( 66293L ) ;
		break ;
	      } 
	      s = mem [s ].hh .v.RH ;
	    } while ( ! ( s == 0 ) ) ;
	    activewidth [1 ]= activewidth [1 ]+ discwidth ;
	    trybreak ( neweqtbint ( 1049411L ) , 1 ) ;
	    activewidth [1 ]= activewidth [1 ]- discwidth ;
	  } 
	  r = mem [curp ].hh.b1 ;
	  s = mem [curp ].hh .v.RH ;
	  while ( r > 0 ) {
	      
	    if ( ( s >= himemmin ) ) 
	    {
	      f = mem [s ].hh.b0 ;
	      if ( ( ( dirsecondary [linebreakdir ]) % 2 ) == ( ( 
	      dirtertiary [linebreakdir ]) % 2 ) ) 
	      {
		breakchtdp = fonttables [f ][ fonttables [f ][ 34 ].cint - 
		fonttables [f ][ 5 ].cint + mem [s ].hh.b1 ].qqqq .b1 ;
		activewidth [1 ]= activewidth [1 ]+ fonttables [f ][ 
		fonttables [f ][ 37 ].cint + ( breakchtdp ) / 256 ].cint + 
		fonttables [f ][ fonttables [f ][ 38 ].cint + ( breakchtdp 
		) % 256 ].cint ;
	      } 
	      else activewidth [1 ]= activewidth [1 ]+ fonttables [f ][ 
	      fonttables [f ][ 36 ].cint + fonttables [f ][ fonttables [f 
	      ][ 34 ].cint - fonttables [f ][ 5 ].cint + mem [s ].hh.b1 ]
	      .qqqq .b0 ].cint ;
	    } 
	    else switch ( mem [s ].hh.b0 ) 
	    {case 6 : 
	      {
		f = mem [s + 1 ].hh.b0 ;
		if ( ( ( dirsecondary [linebreakdir ]) % 2 ) == ( ( 
		dirtertiary [linebreakdir ]) % 2 ) ) 
		{
		  breakchtdp = fonttables [f ][ fonttables [f ][ 34 ].cint 
		  - fonttables [f ][ 5 ].cint + mem [s + 1 ].hh.b1 ].qqqq 
		  .b1 ;
		  activewidth [1 ]= activewidth [1 ]+ fonttables [f ][ 
		  fonttables [f ][ 37 ].cint + ( breakchtdp ) / 256 ].cint 
		  + fonttables [f ][ fonttables [f ][ 38 ].cint + ( 
		  breakchtdp ) % 256 ].cint ;
		} 
		else activewidth [1 ]= activewidth [1 ]+ fonttables [f ][ 
		fonttables [f ][ 36 ].cint + fonttables [f ][ fonttables [
		f ][ 34 ].cint - fonttables [f ][ 5 ].cint + mem [s + 1 ]
		.hh.b1 ].qqqq .b0 ].cint ;
	      } 
	      break ;
	    case 0 : 
	    case 1 : 
	      if ( ! ( ( ( dirprimary [mem [s + 7 ].cint ]) % 2 ) != ( 
	      dirprimary [linebreakdir ]% 2 ) ) ) 
	      activewidth [1 ]= activewidth [1 ]+ mem [s + 1 ].cint ;
	      else activewidth [1 ]= activewidth [1 ]+ ( mem [s + 2 ]
	      .cint + mem [s + 3 ].cint ) ;
	      break ;
	    case 2 : 
	    case 11 : 
	      activewidth [1 ]= activewidth [1 ]+ mem [s + 1 ].cint ;
	      break ;
	      default: 
	      confusion ( 66294L ) ;
	      break ;
	    } 
	    decr ( r ) ;
	    s = mem [s ].hh .v.RH ;
	  } 
	  prevp = curp ;
	  curp = s ;
	  goto lab35 ;
	} 
	break ;
      case 9 : 
	{
	  autobreaking = ( mem [curp ].hh.b1 == 1 ) ;
	  {
	    if ( ! ( mem [curp ].hh .v.RH >= himemmin ) && autobreaking ) {
		
	      if ( mem [mem [curp ].hh .v.RH ].hh.b0 == 10 ) 
	      trybreak ( 0 , 0 ) ;
	    } 
	    activewidth [1 ]= activewidth [1 ]+ mem [curp + 1 ].cint ;
	  } 
	} 
	break ;
      case 12 : 
	trybreak ( mem [curp + 1 ].cint , 0 ) ;
	break ;
      case 4 : 
      case 3 : 
      case 5 : 
	;
	break ;
	default: 
	confusion ( 66292L ) ;
	break ;
      } 
      prevp = curp ;
      curp = mem [curp ].hh .v.RH ;
      lab35: ;
    } 
    if ( curp == 0 ) 
    {
      trybreak ( -10000 , 1 ) ;
      if ( mem [memtop - 7 ].hh .v.RH != memtop - 7 ) 
      {
	r = mem [memtop - 7 ].hh .v.RH ;
	fewestdemerits = 1073741823L ;
	do {
	    if ( mem [r ].hh.b0 != 2 ) { 
	    if ( mem [r + 2 ].cint < fewestdemerits ) 
	    {
	      fewestdemerits = mem [r + 2 ].cint ;
	      bestbet = r ;
	    } 
	  } 
	  r = mem [r ].hh .v.RH ;
	} while ( ! ( r == memtop - 7 ) ) ;
	bestline = mem [bestbet + 1 ].hh .v.LH ;
	if ( neweqtbint ( 1049427L ) == 0 ) 
	goto lab30 ;
	{
	  r = mem [memtop - 7 ].hh .v.RH ;
	  actuallooseness = 0 ;
	  do {
	      if ( mem [r ].hh.b0 != 2 ) 
	    {
	      linediff = mem [r + 1 ].hh .v.LH - bestline ;
	      if ( ( ( linediff < actuallooseness ) && ( neweqtbint ( 1049427L 
	      ) <= linediff ) ) || ( ( linediff > actuallooseness ) && ( 
	      neweqtbint ( 1049427L ) >= linediff ) ) ) 
	      {
		bestbet = r ;
		actuallooseness = linediff ;
		fewestdemerits = mem [r + 2 ].cint ;
	      } 
	      else if ( ( linediff == actuallooseness ) && ( mem [r + 2 ]
	      .cint < fewestdemerits ) ) 
	      {
		bestbet = r ;
		fewestdemerits = mem [r + 2 ].cint ;
	      } 
	    } 
	    r = mem [r ].hh .v.RH ;
	  } while ( ! ( r == memtop - 7 ) ) ;
	  bestline = mem [bestbet + 1 ].hh .v.LH ;
	} 
	if ( ( actuallooseness == neweqtbint ( 1049427L ) ) || finalpass ) 
	goto lab30 ;
      } 
    } 
    q = mem [memtop - 7 ].hh .v.RH ;
    while ( q != memtop - 7 ) {
	
      curp = mem [q ].hh .v.RH ;
      if ( mem [q ].hh.b0 == 2 ) 
      freenode ( q , 8 ) ;
      else freenode ( q , activenodesize ) ;
      q = curp ;
    } 
    q = passive ;
    while ( q != 0 ) {
	
      curp = mem [q ].hh .v.RH ;
      freenode ( q , 10 ) ;
      q = curp ;
    } 
    if ( ! secondpass ) 
    {
	;
#ifdef STAT
      if ( neweqtbint ( 1049440L ) > 0 ) 
      printnl ( 66290L ) ;
#endif /* STAT */
      threshold = neweqtbint ( 1049409L ) ;
      secondpass = true ;
      finalpass = ( neweqtbsc ( 1180556L + ( 20 ) ) <= 0 ) ;
    } 
    else {
	
	;
#ifdef STAT
      if ( neweqtbint ( 1049440L ) > 0 ) 
      printnl ( 66291L ) ;
#endif /* STAT */
      background [2 ]= background [2 ]+ neweqtbsc ( 1180556L + ( 20 ) ) ;
      finalpass = true ;
    } 
  } 
  lab30: 
	;
#ifdef STAT
  if ( neweqtbint ( 1049440L ) > 0 ) 
  {
    enddiagnostic ( true ) ;
    normalizeselector () ;
  } 
#endif /* STAT */
  if ( dolastlinefit ) {
      
    if ( mem [bestbet + 3 ].cint == 0 ) 
    dolastlinefit = false ;
    else {
	
      q = newspec ( mem [lastlinefill + 1 ].hh .v.LH ) ;
      deleteglueref ( mem [lastlinefill + 1 ].hh .v.LH ) ;
      mem [q + 1 ].cint = mem [q + 1 ].cint + mem [bestbet + 3 ].cint - 
      mem [bestbet + 4 ].cint ;
      mem [q + 2 ].cint = 0 ;
      mem [lastlinefill + 1 ].hh .v.LH = q ;
    } 
  } 
  postlinebreak ( d ) ;
  q = mem [memtop - 7 ].hh .v.RH ;
  while ( q != memtop - 7 ) {
      
    curp = mem [q ].hh .v.RH ;
    if ( mem [q ].hh.b0 == 2 ) 
    freenode ( q , 8 ) ;
    else freenode ( q , activenodesize ) ;
    q = curp ;
  } 
  q = passive ;
  while ( q != 0 ) {
      
    curp = mem [q ].hh .v.RH ;
    freenode ( q , 10 ) ;
    q = curp ;
  } 
  packbeginline = 0 ;
} 
void 
newhyphexceptions ( void ) 
{
  /* 21 10 40 45 46 */ newhyphexceptions_regmem 
  unsigned char n  ;
  unsigned char j  ;
  hyphpointer h  ;
  strnumber k  ;
  halfword p  ;
  halfword q  ;
  strnumber s  ;
  poolpointer u, v  ;
  scanleftbrace () ;
  if ( neweqtbint ( 1049458L ) <= 0 ) 
  curlang = 0 ;
  else if ( neweqtbint ( 1049458L ) > 255 ) 
  curlang = 0 ;
  else curlang = neweqtbint ( 1049458L ) ;
	;
#ifdef INITEX
  if ( trienotready ) 
  {
    hyphindex = 0 ;
    goto lab46 ;
  } 
#endif /* INITEX */
  if ( trie [hyphstart + curlang ].b1 != curlang ) 
  hyphindex = 0 ;
  else hyphindex = trie [hyphstart + curlang ].v.RH ;
  lab46: n = 0 ;
  p = 0 ;
  while ( true ) {
      
    getxtoken () ;
    lab21: switch ( curcmd ) 
    {case 11 : 
    case 12 : 
    case 70 : 
      if ( curchr == 45 ) 
      {
	if ( n < 63 ) 
	{
	  q = getavail () ;
	  mem [q ].hh .v.RH = p ;
	  mem [q ].hh .v.LH = n ;
	  p = q ;
	} 
      } 
      else {
	  
	if ( hyphindex == 0 ) 
	hc [0 ]= newequiv ( 787264L + curchr ) ;
	else if ( trie [hyphindex + curchr ].b1 != curchr ) 
	hc [0 ]= 0 ;
	else hc [0 ]= trie [hyphindex + curchr ].b0 ;
	if ( hc [0 ]== 0 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 66301L ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 66302L ;
	    helpline [0 ]= 66303L ;
	  } 
	  error () ;
	} 
	else if ( n < 63 ) 
	{
	  incr ( n ) ;
	  hc [n ]= hc [0 ];
	} 
      } 
      break ;
    case 16 : 
      {
	scancharnum () ;
	curchr = curval ;
	curcmd = 70 ;
	goto lab21 ;
      } 
      break ;
    case 10 : 
    case 2 : 
      {
	if ( n > 1 ) 
	{
	  incr ( n ) ;
	  hc [n ]= curlang ;
	  {
	    if ( poolptr + n > poolsize ) 
	    overflow ( 65543L , poolsize - initpoolptr ) ;
	  } 
	  h = 0 ;
	  {register integer for_end; j = 1 ;for_end = n ; if ( j <= for_end) 
	  do 
	    {
	      h = ( h + h + hc [j ]) % 607 ;
	      {
		strpool [poolptr ]= hc [j ];
		incr ( poolptr ) ;
	      } 
	    } 
	  while ( j++ < for_end ) ;} 
	  s = makestring () ;
	  if ( hyphnext <= 607 ) 
	  while ( ( hyphnext > 0 ) && ( hyphword [hyphnext - 1 ]> 0 ) ) decr 
	  ( hyphnext ) ;
	  if ( ( hyphcount == hyphsize ) || ( hyphnext == 0 ) ) 
	  overflow ( 66304L , hyphsize ) ;
	  incr ( hyphcount ) ;
	  while ( hyphword [h ]!= 0 ) {
	      
	    k = hyphword [h ];
	    if ( length ( k ) != length ( s ) ) 
	    goto lab45 ;
	    u = strstartar [k - 65536L ];
	    v = strstartar [s - 65536L ];
	    do {
		if ( strpool [u ]!= strpool [v ]) 
	      goto lab45 ;
	      incr ( u ) ;
	      incr ( v ) ;
	    } while ( ! ( u == strstartar [k - 65535L ]) ) ;
	    {
	      decr ( strptr ) ;
	      poolptr = strstartar [strptr - 65536L ];
	    } 
	    s = hyphword [h ];
	    decr ( hyphcount ) ;
	    goto lab40 ;
	    lab45: ;
	    if ( hyphlink [h ]== 0 ) 
	    {
	      hyphlink [h ]= hyphnext ;
	      if ( hyphnext >= hyphsize ) 
	      hyphnext = 607 ;
	      if ( hyphnext > 607 ) 
	      incr ( hyphnext ) ;
	    } 
	    h = hyphlink [h ]- 1 ;
	  } 
	  lab40: hyphword [h ]= s ;
	  hyphlist [h ]= p ;
	} 
	if ( curcmd == 2 ) 
	return ;
	n = 0 ;
	p = 0 ;
      } 
      break ;
      default: 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 65996L ) ;
	} 
	printesc ( 66297L ) ;
	print ( 66298L ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66299L ;
	  helpline [0 ]= 66300L ;
	} 
	error () ;
      } 
      break ;
    } 
  } 
} 
boolean 
zdomarks ( smallnumber a , smallnumber l , halfword q ) 
{
  register boolean Result; domarks_regmem 
  smallnumber i  ;
  if ( l < 4 ) 
  {
    {register integer for_end; i = 0 ;for_end = 15 ; if ( i <= for_end) do 
      {
	if ( odd ( i ) ) 
	curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
	else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
	if ( curptr != 0 ) {
	    
	  if ( domarks ( a , l + 1 , curptr ) ) 
	  {
	    if ( odd ( i ) ) 
	    mem [q + ( i / 2 ) + 1 ].hh .v.RH = 0 ;
	    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = 0 ;
	    decr ( mem [q ].hh.b1 ) ;
	  } 
	} 
      } 
    while ( i++ < for_end ) ;} 
    if ( mem [q ].hh.b1 == 0 ) 
    {
      freenode ( q , 9 ) ;
      q = 0 ;
    } 
  } 
  else {
      
    switch ( a ) 
    {case 0 : 
      if ( mem [q + 2 ].hh .v.RH != 0 ) 
      {
	deletetokenref ( mem [q + 2 ].hh .v.RH ) ;
	mem [q + 2 ].hh .v.RH = 0 ;
	deletetokenref ( mem [q + 3 ].hh .v.LH ) ;
	mem [q + 3 ].hh .v.LH = 0 ;
      } 
      break ;
    case 1 : 
      if ( mem [q + 2 ].hh .v.LH != 0 ) 
      {
	if ( mem [q + 1 ].hh .v.LH != 0 ) 
	deletetokenref ( mem [q + 1 ].hh .v.LH ) ;
	deletetokenref ( mem [q + 1 ].hh .v.RH ) ;
	mem [q + 1 ].hh .v.RH = 0 ;
	if ( mem [mem [q + 2 ].hh .v.LH ].hh .v.RH == 0 ) 
	{
	  deletetokenref ( mem [q + 2 ].hh .v.LH ) ;
	  mem [q + 2 ].hh .v.LH = 0 ;
	} 
	else incr ( mem [mem [q + 2 ].hh .v.LH ].hh .v.LH ) ;
	mem [q + 1 ].hh .v.LH = mem [q + 2 ].hh .v.LH ;
      } 
      break ;
    case 2 : 
      if ( ( mem [q + 1 ].hh .v.LH != 0 ) && ( mem [q + 1 ].hh .v.RH == 0 
      ) ) 
      {
	mem [q + 1 ].hh .v.RH = mem [q + 1 ].hh .v.LH ;
	incr ( mem [mem [q + 1 ].hh .v.LH ].hh .v.LH ) ;
      } 
      break ;
	;
#ifdef INITEX
    case 3 : 
      {register integer for_end; i = 0 ;for_end = 4 ; if ( i <= for_end) do 
	{
	  if ( odd ( i ) ) 
	  curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
	  else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
	  if ( curptr != 0 ) 
	  {
	    deletetokenref ( curptr ) ;
	    if ( odd ( i ) ) 
	    mem [q + ( i / 2 ) + 1 ].hh .v.RH = 0 ;
	    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = 0 ;
	  } 
	} 
      while ( i++ < for_end ) ;} 
      break ;
#endif /* INITEX */
    } 
    if ( mem [q + 2 ].hh .v.LH == 0 ) {
	
      if ( mem [q + 3 ].hh .v.LH == 0 ) 
      {
	freenode ( q , 4 ) ;
	q = 0 ;
      } 
    } 
  } 
  Result = ( q == 0 ) ;
  return Result ;
} 
void 
prefixedcommand ( void ) 
{
  /* 30 10 */ prefixedcommand_regmem 
  smallnumber a  ;
  internalfontnumber f  ;
  halfword j  ;
  fontindex k  ;
  halfword p, q  ;
  integer n  ;
  boolean e  ;
  a = 0 ;
  while ( curcmd == 99 ) {
      
    if ( ! odd ( a / curchr ) ) 
    a = a + curchr ;
    do {
	getxtoken () ;
    } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
    if ( curcmd <= 73 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66540L ) ;
      } 
      printcmdchr ( curcmd , curchr ) ;
      printchar ( 39 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 66541L ;
      } 
      if ( ( eTeXmode == 1 ) ) 
      helpline [0 ]= 66542L ;
      backerror () ;
      return ;
    } 
    if ( neweqtbint ( 1049444L ) > 2 ) {
	
      if ( ( eTeXmode == 1 ) ) 
      showcurcmdchr () ;
    } 
  } 
  if ( a >= 8 ) 
  {
    j = 917505L ;
    a = a - 8 ;
  } 
  else j = 0 ;
  if ( ( curcmd != 103 ) && ( ( a % 4 != 0 ) || ( j != 0 ) ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66002L ) ;
    } 
    printesc ( 66532L ) ;
    print ( 66543L ) ;
    printesc ( 66533L ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 66544L ;
    } 
    if ( ( eTeXmode == 1 ) ) 
    {
      helpline [0 ]= 66545L ;
      print ( 66543L ) ;
      printesc ( 66546L ) ;
    } 
    print ( 66547L ) ;
    printcmdchr ( curcmd , curchr ) ;
    printchar ( 39 ) ;
    error () ;
  } 
  if ( neweqtbint ( 1049451L ) != 0 ) {
      
    if ( neweqtbint ( 1049451L ) < 0 ) 
    {
      if ( ( a >= 4 ) ) 
      a = a - 4 ;
    } 
    else {
	
      if ( ! ( a >= 4 ) ) 
      a = a + 4 ;
    } 
  } 
  switch ( curcmd ) 
  {case 90 : 
    if ( ( a >= 4 ) ) 
    geqdefine ( 720959L , 137 , curchr ) ;
    else eqdefine ( 720959L , 137 , curchr ) ;
    break ;
  case 103 : 
    {
      if ( odd ( curchr ) && ! ( a >= 4 ) && ( neweqtbint ( 1049451L ) >= 0 ) 
      ) 
      a = a + 4 ;
      e = ( curchr >= 2 ) ;
      getrtoken () ;
      p = curcs ;
      q = scantoks ( true , e ) ;
      if ( j != 0 ) 
      {
	q = getavail () ;
	mem [q ].hh .v.LH = j ;
	mem [q ].hh .v.RH = mem [defref ].hh .v.RH ;
	mem [defref ].hh .v.RH = q ;
      } 
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 128 + ( a % 4 ) , defref ) ;
      else eqdefine ( p , 128 + ( a % 4 ) , defref ) ;
    } 
    break ;
  case 100 : 
    {
      n = curchr ;
      getrtoken () ;
      p = curcs ;
      if ( n == 0 ) 
      {
	do {
	    gettoken () ;
	} while ( ! ( curcmd != 10 ) ) ;
	if ( curtok == 786493L ) 
	{
	  gettoken () ;
	  if ( curcmd == 10 ) 
	  gettoken () ;
	} 
      } 
      else {
	  
	gettoken () ;
	q = curtok ;
	gettoken () ;
	backinput () ;
	curtok = q ;
	backinput () ;
      } 
      if ( curcmd >= 128 ) 
      incr ( mem [curchr ].hh .v.LH ) ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , curcmd , curchr ) ;
      else eqdefine ( p , curcmd , curchr ) ;
    } 
    break ;
  case 101 : 
    {
      n = curchr ;
      getrtoken () ;
      p = curcs ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 0 , 65536L ) ;
      else eqdefine ( p , 0 , 65536L ) ;
      scanoptionalequals () ;
      switch ( n ) 
      {case 0 : 
	{
	  scancharnum () ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 70 , curval ) ;
	  else eqdefine ( p , 70 , curval ) ;
	} 
	break ;
      case 1 : 
	{
	  scanrealfifteenbitint () ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 71 , curval ) ;
	  else eqdefine ( p , 71 , curval ) ;
	} 
	break ;
      case 2 : 
	{
	  scanbigfifteenbitint () ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 72 , curval ) ;
	  else eqdefine ( p , 72 , curval ) ;
	} 
	break ;
	default: 
	{
	  scaneightbitint () ;
	  switch ( n ) 
	  {case 3 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 76 , 1049484L + curval ) ;
	    else eqdefine ( p , 76 , 1049484L + curval ) ;
	    break ;
	  case 4 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 77 , 1180581L + curval ) ;
	    else eqdefine ( p , 77 , 1180581L + curval ) ;
	    break ;
	  case 5 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 78 , 393248L + curval ) ;
	    else eqdefine ( p , 78 , 393248L + curval ) ;
	    break ;
	  case 6 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 79 , 458784L + curval ) ;
	    else eqdefine ( p , 79 , 458784L + curval ) ;
	    break ;
	  case 7 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 75 , 589885L + curval ) ;
	    else eqdefine ( p , 75 , 589885L + curval ) ;
	    break ;
	  } 
	} 
	break ;
      } 
    } 
    break ;
  case 102 : 
    {
      j = curchr ;
      scanint () ;
      n = curval ;
      if ( ! scankeyword ( 66197L ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66431L ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66565L ;
	  helpline [0 ]= 66566L ;
	} 
	error () ;
      } 
      getrtoken () ;
      p = curcs ;
      readtoks ( n , p , j ) ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 128 , curval ) ;
      else eqdefine ( p , 128 , curval ) ;
    } 
    break ;
  case 74 : 
  case 75 : 
    {
      q = curcs ;
      if ( curcmd == 74 ) 
      {
	scaneightbitint () ;
	p = 589885L + curval ;
      } 
      else p = curchr ;
      scanoptionalequals () ;
      do {
	  getxtoken () ;
      } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
      if ( curcmd != 1 ) 
      {
	if ( curcmd == 74 ) 
	{
	  scaneightbitint () ;
	  curcmd = 75 ;
	  curchr = 589885L + curval ;
	} 
	if ( curcmd == 75 ) 
	{
	  q = newequiv ( curchr ) ;
	  if ( q == 0 ) {
	      
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 118 , 0 ) ;
	    else eqdefine ( p , 118 , 0 ) ;
	  } 
	  else {
	      
	    incr ( mem [q ].hh .v.LH ) ;
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 128 , q ) ;
	    else eqdefine ( p , 128 , q ) ;
	  } 
	  goto lab30 ;
	} 
      } 
      backinput () ;
      curcs = q ;
      q = scantoks ( false , false ) ;
      if ( mem [defref ].hh .v.RH == 0 ) 
      {
	if ( ( a >= 4 ) ) 
	geqdefine ( p , 118 , 0 ) ;
	else eqdefine ( p , 118 , 0 ) ;
	{
	  mem [defref ].hh .v.RH = avail ;
	  avail = defref ;
	;
#ifdef STAT
	  decr ( dynused ) ;
#endif /* STAT */
	} 
      } 
      else {
	  
	if ( p == 524325L ) 
	{
	  mem [q ].hh .v.RH = getavail () ;
	  q = mem [q ].hh .v.RH ;
	  mem [q ].hh .v.LH = 131197L ;
	  q = getavail () ;
	  mem [q ].hh .v.LH = 65659L ;
	  mem [q ].hh .v.RH = mem [defref ].hh .v.RH ;
	  mem [defref ].hh .v.RH = q ;
	} 
	if ( ( a >= 4 ) ) 
	geqdefine ( p , 128 , defref ) ;
	else eqdefine ( p , 128 , defref ) ;
      } 
    } 
    break ;
  case 76 : 
    {
      p = curchr ;
      scanoptionalequals () ;
      scanint () ;
      if ( ( a >= 4 ) ) 
      geqworddefine ( p , curval ) ;
      else eqworddefine ( p , curval ) ;
      if ( ( abs ( curlist .modefield ) == 119 ) && ( ( p == ( 1049463L ) ) || 
      ( p == ( 1049464L ) ) ) ) 
      {
	{
	  {
	    mem [curlist .tailfield ].hh .v.RH = makelocalparnode () ;
	    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	  } 
	} 
	eqworddefine ( 1049465L , neweqtbint ( 1049465L ) + 1 ) ;
	curlist .localparboolfield = true ;
      } 
    } 
    break ;
  case 95 : 
    {
      switch ( curchr ) 
      {case 1049479 : 
	{
	  if ( itsallover () ) 
	  {
	    scandir () ;
	    eqworddefine ( 1049479L , curval ) ;
	  } 
	} 
	break ;
      case 1049480 : 
	{
	  if ( itsallover () ) 
	  {
	    scandir () ;
	    eqworddefine ( 1049480L , curval ) ;
	  } 
	} 
	break ;
      case 1049481 : 
	{
	  scandir () ;
	  eqworddefine ( 1049481L , curval ) ;
	} 
	break ;
      case 1049482 : 
	{
	  scandir () ;
	  if ( ( neweqtbint ( 1049466L ) > 0 ) && ( abs ( curlist .modefield ) 
	  == 119 ) ) 
	  {
	    {
	      mem [curlist .tailfield ].hh .v.RH = newdir ( neweqtbint ( 
	      1049482L ) ) ;
	      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	    } 
	    mem [curlist .tailfield + 1 ].hh .v.LH = mem [curlist 
	    .tailfield + 1 ].hh .v.LH - 64 ;
	  } 
	  if ( mem [textdirptr + 1 ].hh .v.RH == curlevel ) 
	  {
	    textdirtmp = mem [textdirptr ].hh .v.RH ;
	    freenode ( textdirptr , 4 ) ;
	    textdirptr = textdirtmp ;
	  } 
	  eqworddefine ( 1049482L , curval ) ;
	  {
	    textdirtmp = newdir ( neweqtbint ( 1049482L ) ) ;
	    mem [textdirtmp ].hh .v.RH = textdirptr ;
	    textdirptr = textdirtmp ;
	  } 
	  if ( abs ( curlist .modefield ) == 119 ) 
	  {
	    {
	      mem [curlist .tailfield ].hh .v.RH = newdir ( neweqtbint ( 
	      1049482L ) ) ;
	      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	    } 
	    mem [curlist .tailfield + 1 ].hh .v.RH = curlevel ;
	  } 
	  eqworddefine ( 1049466L , neweqtbint ( 1049466L ) + 1 ) ;
	  eqworddefine ( 1049467L , curlevel ) ;
	} 
	break ;
      case 1049483 : 
	{
	  scandir () ;
	  eqworddefine ( 1049483L , curval ) ;
	} 
	break ;
      } 
    } 
    break ;
  case 77 : 
    {
      p = curchr ;
      scanoptionalequals () ;
      scandimen ( false , false , false ) ;
      if ( ( a >= 4 ) ) 
      geqworddefine ( p , curval ) ;
      else eqworddefine ( p , curval ) ;
    } 
    break ;
  case 78 : 
  case 79 : 
    {
      p = curchr ;
      n = curcmd ;
      scanoptionalequals () ;
      if ( n == 79 ) 
      scanglue ( 3 ) ;
      else scanglue ( 2 ) ;
      trapzeroglue () ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 134 , curval ) ;
      else eqdefine ( p , 134 , curval ) ;
    } 
    break ;
  case 88 : 
    {
      if ( curchr == ( 1115276L ) ) 
      {
	p = curchr - 256 ;
	scancharnum () ;
	p = p + curval ;
	scanoptionalequals () ;
	scanint () ;
	curval1 = curval ;
	scanint () ;
	if ( ( curval1 > 16777215L ) || ( curval > 16777215L ) ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 66569L ) ;
	  } 
	  printint ( curval1 ) ;
	  print ( 32 ) ;
	  printint ( curval ) ;
	  print ( 66570L ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 66571L ;
	  } 
	  error () ;
	  curval1 = 0 ;
	  curval = 0 ;
	} 
	if ( ( a >= 4 ) ) 
	delgeqworddefine ( p , curval1 , curval ) ;
	else deleqworddefine ( p , curval1 , curval ) ;
      } 
      else {
	  
	if ( curchr == 721728L ) 
	n = 15 ;
	else if ( curchr == 983872L ) 
	n = 32768L ;
	else if ( curchr == ( 984128L ) ) 
	n = 134217728L ;
	else if ( curchr == 918336L ) 
	n = 32767 ;
	else if ( curchr == 1115020L ) 
	n = 16777215L ;
	else n = 65535L ;
	p = curchr ;
	scancharnum () ;
	p = p + curval ;
	scanoptionalequals () ;
	scanint () ;
	if ( ( ( curval < 0 ) && ( p < 1115020L ) ) || ( curval > n ) ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 66569L ) ;
	  } 
	  printint ( curval ) ;
	  if ( p < 1115020L ) 
	  print ( 66572L ) ;
	  else print ( 66573L ) ;
	  printint ( n ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 66571L ;
	  } 
	  error () ;
	  curval = 0 ;
	} 
	if ( p < 983872L ) {
	    
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 137 , curval ) ;
	  else eqdefine ( p , 137 , curval ) ;
	} 
	else if ( p < ( 984128L ) ) 
	{
	  if ( curval == 32768L ) 
	  curval = 134217728L ;
	  else curval = ( ( curval / 4096 ) * 16777216L ) + ( ( ( curval % 
	  4096 ) / 256 ) * 65536L ) + ( curval % 256 ) ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 137 , curval ) ;
	  else eqdefine ( p , 137 , curval ) ;
	} 
	else if ( p < 1115020L ) {
	    
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p - 256 , 137 , curval ) ;
	  else eqdefine ( p - 256 , 137 , curval ) ;
	} 
	else {
	    
	  curval1 = curval / 4096 ;
	  curval1 = ( curval1 / 256 ) * 65536L + ( curval1 % 256 ) ;
	  curval = curval % 4096 ;
	  curval = ( curval / 256 ) * 65536L + ( curval % 256 ) ;
	  if ( ( a >= 4 ) ) 
	  delgeqworddefine ( p , curval1 , curval ) ;
	  else deleqworddefine ( p , curval1 , curval ) ;
	} 
      } 
    } 
    break ;
  case 89 : 
    {
      p = curchr ;
      scanbigfourbitint () ;
      p = p + curval ;
      scanoptionalequals () ;
      scanfontident () ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 137 , curval ) ;
      else eqdefine ( p , 137 , curval ) ;
    } 
    break ;
  case 92 : 
  case 96 : 
  case 97 : 
  case 98 : 
    doregistercommand ( a ) ;
    break ;
  case 104 : 
    {
      scaneightbitint () ;
      if ( ( a >= 4 ) ) 
      n = ( 1073807360L ) + curval ;
      else n = 1073741824L + curval ;
      scanoptionalequals () ;
      if ( setboxallowed ) 
      scanbox ( n ) ;
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 65996L ) ;
	} 
	printesc ( 65837L ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66579L ;
	  helpline [0 ]= 66580L ;
	} 
	error () ;
      } 
    } 
    break ;
  case 82 : 
    alteraux () ;
    break ;
  case 83 : 
    alterprevgraf () ;
    break ;
  case 84 : 
    alterpagesofar () ;
    break ;
  case 85 : 
    alterinteger () ;
    break ;
  case 86 : 
    alterboxdimen () ;
    break ;
  case 87 : 
    {
      q = curchr ;
      scanoptionalequals () ;
      scanint () ;
      n = curval ;
      if ( n <= 0 ) 
      p = 0 ;
      else if ( q > 524320L ) 
      {
	n = ( curval / 2 ) + 1 ;
	p = getnode ( 2 * n + 1 ) ;
	mem [p ].hh .v.LH = n ;
	n = curval ;
	mem [p + 1 ].cint = n ;
	{register integer for_end; j = p + 2 ;for_end = p + n + 1 ; if ( j 
	<= for_end) do 
	  {
	    scanint () ;
	    mem [j ].cint = curval ;
	  } 
	while ( j++ < for_end ) ;} 
	if ( ! odd ( n ) ) 
	mem [p + n + 2 ].cint = 0 ;
      } 
      else {
	  
	p = getnode ( 2 * n + 1 ) ;
	mem [p ].hh .v.LH = n ;
	{register integer for_end; j = 1 ;for_end = n ; if ( j <= for_end) 
	do 
	  {
	    scandimen ( false , false , false ) ;
	    mem [p + 2 * j - 1 ].cint = curval ;
	    scandimen ( false , false , false ) ;
	    mem [p + 2 * j ].cint = curval ;
	  } 
	while ( j++ < for_end ) ;} 
      } 
      if ( ( a >= 4 ) ) 
      geqdefine ( q , 135 , p ) ;
      else eqdefine ( q , 135 , p ) ;
    } 
    break ;
  case 105 : 
    if ( curchr == 1 ) 
    {
	;
#ifdef INITEX
      if ( iniversion ) 
      {
	newpatterns () ;
	goto lab30 ;
      } 
#endif /* INITEX */
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66584L ) ;
      } 
      helpptr = 0 ;
      error () ;
      do {
	  gettoken () ;
      } while ( ! ( curcmd == 2 ) ) ;
      return ;
    } 
    else {
	
      newhyphexceptions () ;
      goto lab30 ;
    } 
    break ;
  case 80 : 
    {
      n = curchr ;
      if ( n == 0 ) 
      {
	findfontdimen ( true ) ;
	k = curval ;
	scanoptionalequals () ;
	scandimen ( false , false , false ) ;
	fonttables [dimenfont ][ k ].cint = curval ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66585L ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66586L ;
	  helpline [0 ]= 66587L ;
	} 
	error () ;
	scancharnum () ;
	scanoptionalequals () ;
	scandimen ( false , false , false ) ;
      } 
    } 
    break ;
  case 81 : 
    {
      n = curchr ;
      scanfontident () ;
      f = curval ;
      scanoptionalequals () ;
      scanint () ;
      if ( n == 0 ) 
      fonttables [f ][ 16 ].cint = curval ;
      else fonttables [f ][ 17 ].cint = curval ;
    } 
    break ;
  case 91 : 
    newfont ( a ) ;
    break ;
  case 106 : 
    newinteraction () ;
    break ;
  case 107 : 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66838L ) ;
      } 
      printesc ( 66828L ) ;
      print ( 66839L ) ;
      println () ;
    } 
    break ;
  case 108 : 
    newocp ( a ) ;
    break ;
  case 109 : 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66840L ) ;
      } 
      printesc ( 66828L ) ;
      print ( 66839L ) ;
      println () ;
    } 
    break ;
  case 110 : 
    newocplist ( a ) ;
    break ;
  case 112 : 
    dopushocplist ( a ) ;
    break ;
  case 113 : 
    dopopocplist ( a ) ;
    break ;
  case 111 : 
    doclearocplists ( a ) ;
    break ;
  case 114 : 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66841L ) ;
      } 
      printesc ( 66827L ) ;
      print ( 66839L ) ;
      println () ;
    } 
    break ;
  case 115 : 
    {
      scanoptionalequals () ;
      scanint () ;
      if ( curval != 0 ) 
      curval = 1 ;
      if ( ( a >= 4 ) ) 
      geqdefine ( 524335L , 137 , curval ) ;
      else eqdefine ( 524335L , 137 , curval ) ;
    } 
    break ;
    default: 
    confusion ( 66539L ) ;
    break ;
  } 
  lab30: if ( aftertoken != 0 ) 
  {
    curtok = aftertoken ;
    backinput () ;
    aftertoken = 0 ;
  } 
} 
#ifdef INITEX
void 
storefmtfile ( void ) 
{
  /* 41 42 31 32 */ storefmtfile_regmem 
  integer j, k  ;
  halfword p, q  ;
  integer x  ;
  char * formatengine  ;
  if ( saveptr != 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66631L ) ;
    } 
    {
      helpptr = 1 ;
      helpline [0 ]= 66632L ;
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
  selector = 21 ;
  print ( 66648L ) ;
  print ( jobname ) ;
  printchar ( 32 ) ;
  printint ( neweqtbint ( 1049431L ) ) ;
  printchar ( 46 ) ;
  printint ( neweqtbint ( 1049430L ) ) ;
  printchar ( 46 ) ;
  printint ( neweqtbint ( 1049429L ) ) ;
  printchar ( 41 ) ;
  if ( interaction == 0 ) 
  selector = 18 ;
  else selector = 19 ;
  {
    if ( poolptr + 1 > poolsize ) 
    overflow ( 65543L , poolsize - initpoolptr ) ;
  } 
  formatident = makestring () ;
  packjobname ( 66112L ) ;
  while ( ! wopenout ( fmtfile ) ) promptfilename ( 66649L , 66112L ) ;
  printnl ( 66650L ) ;
  slowprint ( wmakenamestring ( fmtfile ) ) ;
  {
    decr ( strptr ) ;
    poolptr = strstartar [strptr - 65536L ];
  } 
  printnl ( 65624L ) ;
  slowprint ( formatident ) ;
  dumpint ( 1462916184L ) ;
  x = strlen ( enginename ) ;
  formatengine = xmallocarray ( char , x + 4 ) ;
  strcpy ( formatengine , enginename ) ;
  {register integer for_end; k = x ;for_end = x + 3 ; if ( k <= for_end) do 
    formatengine [k ]= 0 ;
  while ( k++ < for_end ) ;} 
  x = x + 4 - ( x % 4 ) ;
  dumpint ( x ) ;
  dumpthings ( formatengine [0 ], x ) ;
  libcfree ( formatengine ) ;
  dumpint ( 72365655L ) ;
  dumpint ( 1073741823L ) ;
  dumpint ( eTeXmode ) ;
  {register integer for_end; j = 0 ;for_end = -0 ; if ( j <= for_end) do 
    setneweqtbint ( 1049478L + j , 0 ) ;
  while ( j++ < for_end ) ;} 
  while ( pseudofiles != 0 ) pseudoclose () ;
  dumpint ( membot ) ;
  dumpint ( memtop ) ;
  dumpint ( 1246116L ) ;
  dumpint ( 55711L ) ;
  dumpint ( 607 ) ;
  dumpint ( poolptr ) ;
  dumpint ( strptr ) ;
  dumpthings ( strstartar [-0 ], strptr - 65535L ) ;
  dumpthings ( strpool [0 ], poolptr ) ;
  println () ;
  printint ( strptr ) ;
  print ( 66633L ) ;
  printint ( poolptr ) ;
  sortavail () ;
  varused = 0 ;
  dumpint ( lomemmax ) ;
  dumpint ( rover ) ;
  p = membot ;
  q = rover ;
  x = 0 ;
  do {
      dumpthings ( mem [p ], q + 2 - p ) ;
    x = x + q + 2 - p ;
    varused = varused + q - p ;
    p = q + mem [q ].hh .v.LH ;
    q = mem [q + 1 ].hh .v.RH ;
  } while ( ! ( q == rover ) ) ;
  varused = varused + lomemmax - p ;
  dynused = memend + 1 - himemmin ;
  dumpthings ( mem [p ], lomemmax + 1 - p ) ;
  x = x + lomemmax + 1 - p ;
  dumpint ( himemmin ) ;
  dumpint ( avail ) ;
  dumpthings ( mem [himemmin ], memend + 1 - himemmin ) ;
  x = x + memend + 1 - himemmin ;
  p = avail ;
  while ( p != 0 ) {
      
    decr ( dynused ) ;
    p = mem [p ].hh .v.RH ;
  } 
  dumpint ( varused ) ;
  dumpint ( dynused ) ;
  println () ;
  printint ( x ) ;
  print ( 66634L ) ;
  printint ( varused ) ;
  printchar ( 38 ) ;
  printint ( dynused ) ;
  dumpeqtbtable () ;
  dumpint ( parloc ) ;
  dumpint ( writeloc ) ;
  dumpint ( specialloc ) ;
  dumpint ( hashused ) ;
  dumpint ( fontptr ) ;
  {register integer for_end; k = 0 ;for_end = fontptr ; if ( k <= for_end) 
  do 
    {
      dumpfonttable ( k , fonttables [k ][ 43 ].cint + fonttables [k ][ 8 ]
      .cint + 1 ) ;
      printnl ( 66636L ) ;
      printesc ( newhashtext ( 1442736L + k ) ) ;
      printchar ( 61 ) ;
      printfilename ( fonttables [k ][ 10 ].cint , fonttables [k ][ 11 ]
      .cint , 65624L ) ;
      if ( fonttables [k ][ 6 ].cint != fonttables [k ][ 7 ].cint ) 
      {
	print ( 66069L ) ;
	printscaled ( fonttables [k ][ 6 ].cint ) ;
	print ( 65683L ) ;
      } 
    } 
  while ( k++ < for_end ) ;} 
  println () ;
  printint ( fontptr - 0 ) ;
  print ( 66635L ) ;
  if ( fontptr != 1 ) 
  printchar ( 115 ) ;
  dumpint ( activeminptr ) ;
  dumpint ( activemaxptr ) ;
  dumpthings ( activeinfo [0 ], activemaxptr ) ;
  println () ;
  printint ( activemaxptr ) ;
  print ( 66637L ) ;
  dumpint ( ocpptr ) ;
  {register integer for_end; k = 0 ;for_end = ocpptr ; if ( k <= for_end) do 
    {
      dumpocptable ( k ) ;
      printnl ( 66639L ) ;
      printesc ( newhashtext ( 1508273L + k ) ) ;
      printchar ( 61 ) ;
      printfilename ( ocptables [k ][ 1 ], ocptables [k ][ 2 ], 65624L ) ;
    } 
  while ( k++ < for_end ) ;} 
  println () ;
  printint ( ocpptr - 0 ) ;
  print ( 66638L ) ;
  if ( ocpptr != 1 ) 
  printchar ( 115 ) ;
  dumpint ( ocplistmemptr ) ;
  dumpthings ( ocplistinfo [0 ], ocplistmemptr ) ;
  dumpint ( ocplistptr ) ;
  dumpthings ( ocplistlist [0 ], ocplistptr + 1 ) ;
  {register integer for_end; k = 0 ;for_end = ocplistptr ; if ( k <= 
  for_end) do 
    {
      printnl ( 66640L ) ;
      printesc ( newhashtext ( 1573809L + k ) ) ;
      printchar ( 61 ) ;
      printocplist ( ocplistlist [k ]) ;
    } 
  while ( k++ < for_end ) ;} 
  dumpint ( ocplstackmemptr ) ;
  dumpthings ( ocplstackinfo [0 ], ocplstackmemptr ) ;
  dumpint ( hyphcount ) ;
  if ( hyphnext <= 607 ) 
  hyphnext = hyphsize ;
  dumpint ( hyphnext ) ;
  {register integer for_end; k = 0 ;for_end = hyphsize ; if ( k <= for_end) 
  do 
    if ( hyphword [k ]!= 0 ) 
    {
      dumpint ( k + 65536L * hyphlink [k ]) ;
      dumpint ( hyphword [k ]) ;
      dumpint ( hyphlist [k ]) ;
    } 
  while ( k++ < for_end ) ;} 
  println () ;
  printint ( hyphcount ) ;
  print ( 66641L ) ;
  if ( hyphcount != 1 ) 
  printchar ( 115 ) ;
  if ( trienotready ) 
  inittrie () ;
  dumpint ( triemax ) ;
  dumpint ( hyphstart ) ;
  dumpthings ( trie [0 ], triemax + 1 ) ;
  dumpint ( maxhyphchar ) ;
  dumpint ( trieopptr ) ;
  dumpthings ( hyfdistance [1 ], trieopptr ) ;
  dumpthings ( hyfnum [1 ], trieopptr ) ;
  dumpthings ( hyfnext [1 ], trieopptr ) ;
  printnl ( 66642L ) ;
  printint ( triemax ) ;
  print ( 66643L ) ;
  printint ( trieopptr ) ;
  print ( 66644L ) ;
  if ( trieopptr != 1 ) 
  printchar ( 115 ) ;
  print ( 66645L ) ;
  printint ( trieopsize ) ;
  {register integer for_end; k = 255 ;for_end = 0 ; if ( k >= for_end) do 
    if ( trieused [k ]> 0 ) 
    {
      printnl ( 66646L ) ;
      printint ( trieused [k ]) ;
      print ( 66647L ) ;
      printint ( k ) ;
      dumpint ( k ) ;
      dumpint ( trieused [k ]) ;
    } 
  while ( k-- > for_end ) ;} 
  dumpint ( interaction ) ;
  dumpint ( formatident ) ;
  dumpint ( 69069L ) ;
  setneweqtbint ( 1049439L , 0 ) ;
  wclose ( fmtfile ) ;
} 
#endif /* INITEX */
boolean 
loadfmtfile ( void ) 
{
  /* 6666 10 */ register boolean Result; loadfmtfile_regmem 
  integer j, k  ;
  halfword p, q  ;
  integer x  ;
  char * formatengine  ;
	;
#ifdef INITEX
  if ( iniversion ) 
  {
    libcfree ( strpool ) ;
    libcfree ( strstartar ) ;
    libcfree ( yzmem ) ;
  } 
#endif /* INITEX */
  undumpint ( x ) ;
  if ( debugformatfile ) 
  {
    fprintf ( stderr , "%s%s",  "fmtdebug:" , "format magic number" ) ;
    fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
  } 
  if ( x != 1462916184L ) 
  goto lab6666 ;
  undumpint ( x ) ;
  if ( debugformatfile ) 
  {
    fprintf ( stderr , "%s%s",  "fmtdebug:" , "engine name size" ) ;
    fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
  } 
  if ( ( x < 0 ) || ( x > 256 ) ) 
  goto lab6666 ;
  formatengine = xmallocarray ( char , x ) ;
  undumpthings ( formatengine [0 ], x ) ;
  formatengine [x - 1 ]= 0 ;
  if ( strcmp ( enginename , formatengine ) ) 
  {
    ;
    fprintf ( stdout , "%s%s%s%s\n",  "---! " , stringcast ( nameoffile + 1 ) ,     " was written by " , formatengine ) ;
    libcfree ( formatengine ) ;
    goto lab6666 ;
  } 
  libcfree ( formatengine ) ;
  undumpint ( x ) ;
  if ( debugformatfile ) 
  {
    fprintf ( stderr , "%s%s",  "fmtdebug:" , "string pool checksum" ) ;
    fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
  } 
  if ( x != 72365655L ) 
  {
    ;
    fprintf ( stdout , "%s%s%s%s\n",  "---! " , stringcast ( nameoffile + 1 ) ,     " doesn't match " , poolname ) ;
    goto lab6666 ;
  } 
  undumpint ( x ) ;
  if ( x != 1073741823L ) 
  goto lab6666 ;
  {
    undumpint ( x ) ;
    if ( ( x < 0 ) || ( x > 1 ) ) 
    goto lab6666 ;
    else eTeXmode = x ;
  } 
  if ( ( eTeXmode == 1 ) ) 
  {
    maxregnum = 65535L ;
    maxreghelpline = 66006L ;
  } 
  else {
      
    maxregnum = 255 ;
    maxreghelpline = 66788L ;
  } 
  undumpint ( x ) ;
  if ( debugformatfile ) 
  {
    fprintf ( stderr , "%s%s",  "fmtdebug:" , "mem_bot" ) ;
    fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
  } 
  if ( x != membot ) 
  goto lab6666 ;
  undumpint ( memtop ) ;
  if ( debugformatfile ) 
  {
    fprintf ( stderr , "%s%s",  "fmtdebug:" , "mem_top" ) ;
    fprintf ( stderr , "%s%ld\n",  " = " , (long)memtop ) ;
  } 
  if ( membot + 1100 > memtop ) 
  goto lab6666 ;
  curlist .headfield = memtop - 1 ;
  curlist .tailfield = memtop - 1 ;
  pagetail = memtop - 2 ;
  memmin = membot - extramembot ;
  memmax = memtop + extramemtop ;
  yzmem = xmallocarray ( memoryword , memmax - memmin + 1 ) ;
  zmem = yzmem - memmin ;
  mem = zmem ;
  undumpint ( x ) ;
  if ( x != 1246116L ) 
  goto lab6666 ;
  undumpint ( x ) ;
  if ( x != 55711L ) 
  goto lab6666 ;
  undumpint ( x ) ;
  if ( x != 607 ) 
  goto lab6666 ;
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > suppoolsize - poolfree ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "string pool size" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "string pool size" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    poolptr = x ;
  } 
  if ( poolsize < poolptr + poolfree ) 
  poolsize = poolptr + poolfree ;
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > supmaxstrings - stringsfree ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "sup strings" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "sup strings" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    strptr = x ;
  } 
  if ( maxstrings < strptr + stringsfree ) 
  maxstrings = strptr + stringsfree ;
  strstartar = xmallocarray ( poolpointer , maxstrings - 65535L ) ;
  undumpthings ( strstartar [-0 ], strptr - 65535L ) ;
  strpool = xmallocarray ( packedASCIIcode , poolsize ) ;
  undumpthings ( strpool [0 ], poolptr ) ;
  initstrptr = strptr ;
  initpoolptr = poolptr ;
  {
    undumpint ( x ) ;
    if ( ( x < membot + 1023 ) || ( x > memtop - 14 ) ) 
    goto lab6666 ;
    else lomemmax = x ;
  } 
  {
    undumpint ( x ) ;
    if ( ( x < membot + 24 ) || ( x > lomemmax ) ) 
    goto lab6666 ;
    else rover = x ;
  } 
  p = membot ;
  q = rover ;
  do {
      undumpthings ( mem [p ], q + 2 - p ) ;
    p = q + mem [q ].hh .v.LH ;
    if ( ( p > lomemmax ) || ( ( q >= mem [q + 1 ].hh .v.RH ) && ( mem [q + 
    1 ].hh .v.RH != rover ) ) ) 
    goto lab6666 ;
    q = mem [q + 1 ].hh .v.RH ;
  } while ( ! ( q == rover ) ) ;
  undumpthings ( mem [p ], lomemmax + 1 - p ) ;
  if ( memmin < membot - 2 ) 
  {
    p = mem [rover + 1 ].hh .v.LH ;
    q = memmin + 1 ;
    mem [memmin ].hh .v.RH = 0 ;
    mem [memmin ].hh .v.LH = 0 ;
    mem [p + 1 ].hh .v.RH = q ;
    mem [rover + 1 ].hh .v.LH = q ;
    mem [q + 1 ].hh .v.RH = rover ;
    mem [q + 1 ].hh .v.LH = p ;
    mem [q ].hh .v.RH = 1073741823L ;
    mem [q ].hh .v.LH = membot - q ;
  } 
  {
    undumpint ( x ) ;
    if ( ( x < lomemmax + 1 ) || ( x > memtop - 13 ) ) 
    goto lab6666 ;
    else himemmin = x ;
  } 
  {
    undumpint ( x ) ;
    if ( ( x < 0 ) || ( x > memtop ) ) 
    goto lab6666 ;
    else avail = x ;
  } 
  memend = memtop ;
  undumpthings ( mem [himemmin ], memend + 1 - himemmin ) ;
  undumpint ( varused ) ;
  undumpint ( dynused ) ;
  undumpeqtbtable () ;
  {
    undumpint ( x ) ;
    if ( ( x < 131074L ) || ( x > 196610L ) ) 
    goto lab6666 ;
    else parloc = x ;
  } 
  partoken = 1048575L + parloc ;
  {
    undumpint ( x ) ;
    if ( ( x < 131074L ) || ( x > 196610L ) ) 
    goto lab6666 ;
    else
    writeloc = x ;
  } 
  {
    undumpint ( x ) ;
    if ( ( x < 131074L ) || ( x > 196610L ) ) 
    goto lab6666 ;
    else specialloc = x ;
  } 
  specialtoken = 1048575L + specialloc ;
  {
    undumpint ( x ) ;
    if ( ( x < 131074L ) || ( x > 196610L ) ) 
    goto lab6666 ;
    else hashused = x ;
  } 
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > fontmax ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "font max" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "font max" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    fontptr = x ;
  } 
  {register integer for_end; k = 0 ;for_end = fontptr ; if ( k <= for_end) 
  do 
    {
      undumpfonttable ( k ) ;
    } 
  while ( k++ < for_end ) ;} 
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > activememsize ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "active start point" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "active start point" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    activeminptr = x ;
  } 
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > activememsize ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "active mem size" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "active mem size" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    activemaxptr = x ;
  } 
  undumpthings ( activeinfo [0 ], activemaxptr ) ;
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > 65535L ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "ocp max" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "ocp max" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    ocpptr = x ;
  } 
  {register integer for_end; k = 0 ;for_end = ocpptr ; if ( k <= for_end) do 
    {
      undumpocptable ( k ) ;
    } 
  while ( k++ < for_end ) ;} 
  {
    undumpint ( x ) ;
    if ( x < 1 ) 
    goto lab6666 ;
    if ( x > 1000000L ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "ocp list mem size" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "ocp list mem size" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    ocplistmemptr = x ;
  } 
  undumpthings ( ocplistinfo [0 ], ocplistmemptr ) ;
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > 1000000L ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "ocp list max" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "ocp list max" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    ocplistptr = x ;
  } 
  undumpthings ( ocplistlist [0 ], ocplistptr + 1 ) ;
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > 1000000L ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "ocp lstack mem size" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "ocp lstack mem size" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    ocplstackmemptr = x ;
  } 
  undumpthings ( ocplstackinfo [0 ], ocplstackmemptr ) ;
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > hyphsize ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "hyph_size" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "hyph_size" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    hyphcount = x ;
  } 
  {
    undumpint ( x ) ;
    if ( x < 607 ) 
    goto lab6666 ;
    if ( x > hyphsize ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "hyph_size" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "hyph_size" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    hyphnext = x ;
  } 
  j = 0 ;
  {register integer for_end; k = 1 ;for_end = hyphcount ; if ( k <= for_end) 
  do 
    {
      undumpint ( j ) ;
      if ( j < 0 ) 
      goto lab6666 ;
      if ( j > 65535L ) 
      {
	hyphnext = j / 65536L ;
	j = j - hyphnext * 65536L ;
      } 
      else hyphnext = 0 ;
      if ( ( j >= hyphsize ) || ( hyphnext > hyphsize ) ) 
      goto lab6666 ;
      hyphlink [j ]= hyphnext ;
      {
	undumpint ( x ) ;
	if ( ( x < 0 ) || ( x > strptr ) ) 
	goto lab6666 ;
	else hyphword [j ]= x ;
      } 
      {
	undumpint ( x ) ;
	if ( ( x < 0 ) || ( x > 1073741823L ) ) 
	goto lab6666 ;
	else hyphlist [j ]= x ;
      } 
    } 
  while ( k++ < for_end ) ;} 
  incr ( j ) ;
  if ( j < 607 ) 
  j = 607 ;
  hyphnext = j ;
  if ( hyphnext >= hyphsize ) 
  hyphnext = 607 ;
  else if ( hyphnext >= 607 ) 
  incr ( hyphnext ) ;
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > triesize ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "trie size" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "trie size" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    j = x ;
  } 
	;
#ifdef INITEX
  triemax = j ;
#endif /* INITEX */
  {
    undumpint ( x ) ;
    if ( ( x < 0 ) || ( x > j ) ) 
    goto lab6666 ;
    else hyphstart = x ;
  } 
  if ( ! trie ) 
  trie = xmallocarray ( twohalves , j + 1 ) ;
  undumpthings ( trie [0 ], j + 1 ) ;
  undumpint ( maxhyphchar ) ;
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > trieopsize ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "trie op size" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "trie op size" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    j = x ;
  } 
	;
#ifdef INITEX
  trieopptr = j ;
#endif /* INITEX */
  undumpthings ( hyfdistance [1 ], j ) ;
  undumpthings ( hyfnum [1 ], j ) ;
  undumpuppercheckthings ( 65535L , hyfnext [1 ], j ) ;
	;
#ifdef INITEX
  {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
    trieused [k ]= 0 ;
  while ( k++ < for_end ) ;} 
#endif /* INITEX */
  k = 256 ;
  while ( j > 0 ) {
      
    {
      undumpint ( x ) ;
      if ( ( x < 0 ) || ( x > k - 1 ) ) 
      goto lab6666 ;
      else k = x ;
    } 
    {
      undumpint ( x ) ;
      if ( ( x < 1 ) || ( x > j ) ) 
      goto lab6666 ;
      else x = x ;
    } 
	;
#ifdef INITEX
    trieused [k ]= x ;
#endif /* INITEX */
    j = j - x ;
    opstart [k ]= j ;
  } 
	;
#ifdef INITEX
  trienotready = false 
#endif /* INITEX */
  ;
  {
    undumpint ( x ) ;
    if ( ( x < 0 ) || ( x > 3 ) ) 
    goto lab6666 ;
    else interaction = x ;
  } 
  if ( interactionoption != 4 ) 
  interaction = interactionoption ;
  {
    undumpint ( x ) ;
    if ( ( x < 0 ) || ( x > strptr ) ) 
    goto lab6666 ;
    else formatident = x ;
  } 
  undumpint ( x ) ;
  if ( x != 69069L ) 
  goto lab6666 ;
  Result = true ;
  return Result ;
  lab6666: ;
  fprintf ( stdout , "%s\n",  "(Fatal format file error; I'm stymied)" ) ;
  Result = false ;
  return Result ;
} 
void 
finalcleanup ( void ) 
{
  /* 10 */ finalcleanup_regmem 
  smallnumber c  ;
  c = curchr ;
  if ( jobname == 0 ) 
  openlogfile () ;
  while ( inputptr > 0 ) if ( curinput .statefield == 0 ) 
  endtokenlist () ;
  else endfilereading () ;
  while ( openparens > 0 ) {
      
    print ( 66652L ) ;
    decr ( openparens ) ;
  } 
  if ( curlevel > 1 ) 
  {
    printnl ( 40 ) ;
    printesc ( 66653L ) ;
    print ( 66654L ) ;
    printint ( curlevel - 1 ) ;
    printchar ( 41 ) ;
    if ( ( eTeXmode == 1 ) ) 
    showsavegroups () ;
  } 
  while ( condptr != 0 ) {
      
    printnl ( 40 ) ;
    printesc ( 66653L ) ;
    print ( 66655L ) ;
    printcmdchr ( 122 , curif ) ;
    if ( ifline != 0 ) 
    {
      print ( 66656L ) ;
      printint ( ifline ) ;
    } 
    print ( 66657L ) ;
    ifline = mem [condptr + 1 ].cint ;
    curif = mem [condptr ].hh.b1 ;
    tempptr = condptr ;
    condptr = mem [condptr ].hh .v.RH ;
    freenode ( tempptr , 2 ) ;
  } 
  if ( history != 0 ) {
      
    if ( ( ( history == 1 ) || ( interaction < 3 ) ) ) {
	
      if ( selector == 19 ) 
      {
	selector = 17 ;
	printnl ( 66658L ) ;
	selector = 19 ;
      } 
    } 
  } 
  if ( c == 1 ) 
  {
	;
#ifdef INITEX
    if ( iniversion ) 
    {
      {register integer for_end; c = 0 ;for_end = 4 ; if ( c <= for_end) do 
	if ( curmark [c ]!= 0 ) 
	deletetokenref ( curmark [c ]) ;
      while ( c++ < for_end ) ;} 
      if ( samark != 0 ) {
	  
	if ( domarks ( 3 , 0 , samark ) ) 
	samark = 0 ;
      } 
      {register integer for_end; c = 2 ;for_end = 3 ; if ( c <= for_end) do 
	flushnodelist ( discptr [c ]) ;
      while ( c++ < for_end ) ;} 
      storefmtfile () ;
      return ;
    } 
#endif /* INITEX */
    printnl ( 66659L ) ;
    return ;
  } 
} 
#ifdef INITEX
void 
initprim ( void ) 
{
  initprim_regmem 
  nonewcontrolsequence = false ;
  first = 0 ;
  primitive ( 65662L , 78 , 393230L ) ;
  primitive ( 65663L , 78 , 393231L ) ;
  primitive ( 65664L , 78 , 393232L ) ;
  primitive ( 65665L , 78 , 393233L ) ;
  primitive ( 65666L , 78 , 393234L ) ;
  primitive ( 65667L , 78 , 393235L ) ;
  primitive ( 65668L , 78 , 393236L ) ;
  primitive ( 65669L , 78 , 393237L ) ;
  primitive ( 65670L , 78 , 393238L ) ;
  primitive ( 65671L , 78 , 393239L ) ;
  primitive ( 65672L , 78 , 393240L ) ;
  primitive ( 65673L , 78 , 393241L ) ;
  primitive ( 65674L , 78 , 393242L ) ;
  primitive ( 65675L , 78 , 393243L ) ;
  primitive ( 65676L , 78 , 393244L ) ;
  primitive ( 65677L , 79 , 393245L ) ;
  primitive ( 65678L , 79 , 393246L ) ;
  primitive ( 65679L , 79 , 393247L ) ;
  primitive ( 65684L , 75 , 524325L ) ;
  primitive ( 65685L , 75 , 524326L ) ;
  primitive ( 65686L , 75 , 524327L ) ;
  primitive ( 65687L , 75 , 524328L ) ;
  primitive ( 65688L , 75 , 524329L ) ;
  primitive ( 65689L , 75 , 524330L ) ;
  primitive ( 65690L , 75 , 524331L ) ;
  primitive ( 65691L , 75 , 524332L ) ;
  primitive ( 65692L , 75 , 524334L ) ;
  primitive ( 65706L , 76 , 1049408L ) ;
  primitive ( 65707L , 76 , 1049409L ) ;
  primitive ( 65708L , 76 , 1049410L ) ;
  primitive ( 65709L , 76 , 1049411L ) ;
  primitive ( 65710L , 76 , 1049412L ) ;
  primitive ( 65711L , 76 , 1049413L ) ;
  primitive ( 65712L , 76 , 1049414L ) ;
  primitive ( 65713L , 76 , 1049415L ) ;
  primitive ( 65714L , 76 , 1049416L ) ;
  primitive ( 65715L , 76 , 1049417L ) ;
  primitive ( 65716L , 76 , 1049418L ) ;
  primitive ( 65717L , 76 , 1049419L ) ;
  primitive ( 65718L , 76 , 1049420L ) ;
  primitive ( 65719L , 76 , 1049421L ) ;
  primitive ( 65720L , 76 , 1049422L ) ;
  primitive ( 65721L , 76 , 1049423L ) ;
  primitive ( 65722L , 76 , 1049424L ) ;
  primitive ( 65723L , 76 , 1049425L ) ;
  primitive ( 65724L , 76 , 1049426L ) ;
  primitive ( 65725L , 76 , 1049427L ) ;
  primitive ( 65726L , 76 , 1049428L ) ;
  primitive ( 65727L , 76 , 1049429L ) ;
  primitive ( 65728L , 76 , 1049430L ) ;
  primitive ( 65729L , 76 , 1049431L ) ;
  primitive ( 65730L , 76 , 1049432L ) ;
  primitive ( 65731L , 76 , 1049433L ) ;
  primitive ( 65732L , 76 , 1049434L ) ;
  primitive ( 65733L , 76 , 1049435L ) ;
  primitive ( 65734L , 76 , 1049436L ) ;
  primitive ( 65735L , 76 , 1049437L ) ;
  primitive ( 65736L , 76 , 1049438L ) ;
  primitive ( 65737L , 76 , 1049439L ) ;
  primitive ( 65738L , 76 , 1049440L ) ;
  primitive ( 65739L , 76 , 1049441L ) ;
  primitive ( 65740L , 76 , 1049442L ) ;
  primitive ( 65741L , 76 , 1049443L ) ;
  primitive ( 65742L , 76 , 1049444L ) ;
  primitive ( 65743L , 76 , 1049445L ) ;
  primitive ( 65744L , 76 , 1049446L ) ;
  primitive ( 65745L , 76 , 1049447L ) ;
  primitive ( 65746L , 76 , 1049448L ) ;
  primitive ( 65747L , 76 , 1049449L ) ;
  primitive ( 65748L , 76 , 1049450L ) ;
  primitive ( 65749L , 76 , 1049451L ) ;
  primitive ( 65750L , 76 , 1049452L ) ;
  primitive ( 65751L , 76 , 1049453L ) ;
  primitive ( 65752L , 76 , 1049454L ) ;
  primitive ( 65753L , 76 , 1049455L ) ;
  primitive ( 65754L , 76 , 1049456L ) ;
  primitive ( 65755L , 76 , 1049457L ) ;
  primitive ( 65756L , 76 , 1049458L ) ;
  primitive ( 65757L , 76 , 1049459L ) ;
  primitive ( 65758L , 76 , 1049460L ) ;
  primitive ( 65759L , 76 , 1049461L ) ;
  primitive ( 65760L , 76 , 1049462L ) ;
  primitive ( 65764L , 77 , 1180556L ) ;
  primitive ( 65765L , 77 , 1180557L ) ;
  primitive ( 65766L , 77 , 1180558L ) ;
  primitive ( 65767L , 77 , 1180559L ) ;
  primitive ( 65768L , 77 , 1180560L ) ;
  primitive ( 65769L , 77 , 1180561L ) ;
  primitive ( 65770L , 77 , 1180562L ) ;
  primitive ( 65771L , 77 , 1180563L ) ;
  primitive ( 65772L , 77 , 1180564L ) ;
  primitive ( 65773L , 77 , 1180565L ) ;
  primitive ( 65774L , 77 , 1180566L ) ;
  primitive ( 65775L , 77 , 1180567L ) ;
  primitive ( 65776L , 77 , 1180568L ) ;
  primitive ( 65777L , 77 , 1180569L ) ;
  primitive ( 65778L , 77 , 1180570L ) ;
  primitive ( 65779L , 77 , 1180571L ) ;
  primitive ( 65780L , 77 , 1180572L ) ;
  primitive ( 65781L , 77 , 1180573L ) ;
  primitive ( 65782L , 77 , 1180574L ) ;
  primitive ( 65783L , 77 , 1180575L ) ;
  primitive ( 65784L , 77 , 1180576L ) ;
  primitive ( 32 , 64 , 0 ) ;
  primitive ( 47 , 44 , 0 ) ;
  primitive ( 65798L , 45 , 0 ) ;
  primitive ( 65799L , 96 , 0 ) ;
  primitive ( 65800L , 40 , 0 ) ;
  primitive ( 65801L , 41 , 0 ) ;
  primitive ( 65802L , 61 , 0 ) ;
  primitive ( 65803L , 16 , 0 ) ;
  primitive ( 65794L , 124 , 0 ) ;
  primitive ( 65804L , 15 , 0 ) ;
  primitive ( 65805L , 15 , 1 ) ;
  primitive ( 65806L , 98 , 0 ) ;
  primitive ( 65795L , 67 , 0 ) ;
  primitive ( 65807L , 62 , 0 ) ;
  sethashtext ( 1442728L , 65807L ) ;
  setneweqtb ( 196612L , neweqtb ( curval ) ) ;
  primitive ( 65808L , 119 , 0 ) ;
  primitive ( 65809L , 91 , 0 ) ;
  primitive ( 65810L , 80 , 0 ) ;
  primitive ( 65811L , 80 , 1 ) ;
  primitive ( 65812L , 80 , 2 ) ;
  primitive ( 65813L , 80 , 3 ) ;
  primitive ( 65814L , 80 , 4 ) ;
  primitive ( 65815L , 32 , 0 ) ;
  primitive ( 65816L , 36 , 0 ) ;
  primitive ( 65817L , 39 , 0 ) ;
  primitive ( 65616L , 37 , 0 ) ;
  primitive ( 65818L , 68 , 0 ) ;
  primitive ( 65637L , 18 , 0 ) ;
  primitive ( 65819L , 46 , 0 ) ;
  primitive ( 65820L , 17 , 0 ) ;
  primitive ( 65821L , 46 , 1 ) ;
  primitive ( 65822L , 17 , 1 ) ;
  primitive ( 65823L , 54 , 0 ) ;
  primitive ( 65824L , 97 , 0 ) ;
  primitive ( 65825L , 34 , 0 ) ;
  primitive ( 65826L , 65 , 0 ) ;
  primitive ( 65827L , 120 , 0 ) ;
  primitive ( 65621L , 55 , 0 ) ;
  primitive ( 65828L , 63 , 0 ) ;
  primitive ( 65829L , 87 , 524320L ) ;
  primitive ( 65830L , 42 , 0 ) ;
  primitive ( 65831L , 83 , 0 ) ;
  primitive ( 65832L , 66 , 0 ) ;
  primitive ( 65833L , 66 , 1 ) ;
  primitive ( 65834L , 102 , 0 ) ;
  primitive ( 65835L , 0 , 65536L ) ;
  sethashtext ( 1442733L , 65835L ) ;
  setneweqtb ( 196617L , neweqtb ( curval ) ) ;
  primitive ( 65836L , 68 , 1 ) ;
  primitive ( 65837L , 104 , 0 ) ;
  primitive ( 65838L , 126 , 0 ) ;
  primitive ( 65693L , 74 , membot ) ;
  primitive ( 65638L , 38 , 0 ) ;
  primitive ( 65839L , 33 , 0 ) ;
  primitive ( 65840L , 56 , 0 ) ;
  primitive ( 65841L , 35 , 0 ) ;
  primitive ( 65906L , 13 , 65536L ) ;
  parloc = curval ;
  partoken = 1048575L + parloc ;
  primitive ( 65938L , 121 , 0 ) ;
  primitive ( 65939L , 121 , 1 ) ;
  primitive ( 65940L , 127 , 0 ) ;
  primitive ( 65941L , 127 , 1 ) ;
  primitive ( 65942L , 127 , 2 ) ;
  primitive ( 65943L , 127 , 3 ) ;
  primitive ( 65944L , 127 , 4 ) ;
  primitive ( 65762L , 92 , membot + 0 ) ;
  primitive ( 65790L , 92 , membot + 1 ) ;
  primitive ( 65681L , 92 , membot + 2 ) ;
  primitive ( 65682L , 92 , membot + 3 ) ;
  primitive ( 65983L , 82 , 119 ) ;
  primitive ( 65984L , 82 , 1 ) ;
  primitive ( 65985L , 85 , 0 ) ;
  primitive ( 65986L , 85 , 1 ) ;
  primitive ( 65987L , 86 , 1 ) ;
  primitive ( 65988L , 86 , 3 ) ;
  primitive ( 65989L , 86 , 2 ) ;
  primitive ( 65990L , 73 , 0 ) ;
  primitive ( 65991L , 73 , 1 ) ;
  primitive ( 65992L , 73 , 2 ) ;
  primitive ( 65993L , 73 , 4 ) ;
  primitive ( 65994L , 73 , 5 ) ;
  primitive ( 66060L , 125 , 0 ) ;
  primitive ( 66061L , 125 , 1 ) ;
  primitive ( 66062L , 125 , 2 ) ;
  primitive ( 66063L , 125 , 3 ) ;
  primitive ( 66064L , 125 , 4 ) ;
  primitive ( 66065L , 125 , 5 ) ;
  primitive ( 66066L , 125 , 6 ) ;
  primitive ( 66067L , 125 , 7 ) ;
  primitive ( 66068L , 125 , 8 ) ;
  primitive ( 66084L , 122 , 0 ) ;
  primitive ( 66085L , 122 , 1 ) ;
  primitive ( 66086L , 122 , 2 ) ;
  primitive ( 66087L , 122 , 3 ) ;
  primitive ( 66088L , 122 , 4 ) ;
  primitive ( 66089L , 122 , 5 ) ;
  primitive ( 66090L , 122 , 6 ) ;
  primitive ( 66091L , 122 , 7 ) ;
  primitive ( 66092L , 122 , 8 ) ;
  primitive ( 66093L , 122 , 9 ) ;
  primitive ( 66094L , 122 , 10 ) ;
  primitive ( 66095L , 122 , 11 ) ;
  primitive ( 66096L , 122 , 12 ) ;
  primitive ( 66097L , 122 , 13 ) ;
  primitive ( 66098L , 122 , 14 ) ;
  primitive ( 66099L , 122 , 15 ) ;
  primitive ( 66100L , 122 , 16 ) ;
  primitive ( 65597L , 123 , 2 ) ;
  sethashtext ( 1442730L , 65597L ) ;
  setneweqtb ( 196614L , neweqtb ( curval ) ) ;
  primitive ( 66102L , 123 , 4 ) ;
  primitive ( 66103L , 123 , 3 ) ;
  primitive ( 66130L , 90 , 0 ) ;
  sethashtext ( 1442736L , 66130L ) ;
  setneweqtb ( 196620L , neweqtb ( curval ) ) ;
  primitive ( 66157L , 107 , 0 ) ;
  sethashtext ( 1508273L , 66157L ) ;
  setneweqtb ( 262157L , neweqtb ( curval ) ) ;
  geqdefine ( 524336L , 137 , 0 ) ;
  geqdefine ( 524337L , 137 , 0 ) ;
  geqdefine ( 524338L , 137 , 0 ) ;
  primitive ( 66171L , 109 , 0 ) ;
  sethashtext ( 1573809L , 66171L ) ;
  setneweqtb ( 327693L , neweqtb ( curval ) ) ;
  primitive ( 66254L , 4 , 65537L ) ;
  primitive ( 66255L , 5 , 65538L ) ;
  sethashtext ( 1442727L , 66255L ) ;
  setneweqtb ( 196611L , neweqtb ( curval ) ) ;
  primitive ( 66256L , 5 , 65539L ) ;
  sethashtext ( 1442731L , 66257L ) ;
  sethashtext ( 1442732L , 66257L ) ;
  seteqtype ( 196616L , 9 ) ;
  setequiv ( 196616L , memtop - 11 ) ;
  seteqlevel ( 196616L , 1 ) ;
  setneweqtb ( 196615L , neweqtb ( 196616L ) ) ;
  seteqtype ( 196615L , 132 ) ;
  primitive ( 66326L , 84 , 0 ) ;
  primitive ( 66327L , 84 , 1 ) ;
  primitive ( 66328L , 84 , 2 ) ;
  primitive ( 66329L , 84 , 3 ) ;
  primitive ( 66330L , 84 , 4 ) ;
  primitive ( 66331L , 84 , 5 ) ;
  primitive ( 66332L , 84 , 6 ) ;
  primitive ( 66333L , 84 , 7 ) ;
  primitive ( 66382L , 14 , 0 ) ;
  primitive ( 66383L , 14 , 1 ) ;
  primitive ( 66384L , 26 , 4 ) ;
  primitive ( 66385L , 26 , 0 ) ;
  primitive ( 66386L , 26 , 1 ) ;
  primitive ( 66387L , 26 , 2 ) ;
  primitive ( 66388L , 26 , 3 ) ;
  primitive ( 66389L , 27 , 4 ) ;
  primitive ( 66390L , 27 , 0 ) ;
  primitive ( 66391L , 27 , 1 ) ;
  primitive ( 66392L , 27 , 2 ) ;
  primitive ( 66393L , 27 , 3 ) ;
  primitive ( 65622L , 28 , 5 ) ;
  primitive ( 65626L , 29 , 1 ) ;
  primitive ( 65628L , 30 , 99 ) ;
  primitive ( 66411L , 21 , 1 ) ;
  primitive ( 66412L , 21 , 0 ) ;
  primitive ( 66413L , 22 , 1 ) ;
  primitive ( 66414L , 22 , 0 ) ;
  primitive ( 65695L , 20 , 0 ) ;
  primitive ( 66415L , 20 , 1 ) ;
  primitive ( 66416L , 20 , 2 ) ;
  primitive ( 66321L , 20 , 3 ) ;
  primitive ( 66417L , 20 , 4 ) ;
  primitive ( 66323L , 20 , 5 ) ;
  primitive ( 66418L , 20 , 123 ) ;
  primitive ( 66419L , 31 , 99 ) ;
  primitive ( 66420L , 31 , 100 ) ;
  primitive ( 66421L , 31 , 101 ) ;
  primitive ( 66422L , 31 , 102 ) ;
  primitive ( 66423L , 94 , 0 ) ;
  primitive ( 66438L , 43 , 1 ) ;
  primitive ( 66439L , 43 , 0 ) ;
  primitive ( 66448L , 25 , 12 ) ;
  primitive ( 66449L , 25 , 11 ) ;
  primitive ( 66450L , 25 , 10 ) ;
  primitive ( 66451L , 23 , 0 ) ;
  primitive ( 66452L , 23 , 1 ) ;
  primitive ( 66453L , 24 , 0 ) ;
  primitive ( 66454L , 24 , 1 ) ;
  primitive ( 45 , 47 , 1 ) ;
  primitive ( 65635L , 47 , 0 ) ;
  primitive ( 66459L , 69 , 0 ) ;
  primitive ( 66460L , 69 , 1 ) ;
  primitive ( 66487L , 48 , 0 ) ;
  primitive ( 66488L , 48 , 1 ) ;
  primitive ( 66221L , 50 , 16 ) ;
  primitive ( 66222L , 50 , 17 ) ;
  primitive ( 66223L , 50 , 18 ) ;
  primitive ( 66224L , 50 , 19 ) ;
  primitive ( 66225L , 50 , 20 ) ;
  primitive ( 66226L , 50 , 21 ) ;
  primitive ( 66227L , 50 , 22 ) ;
  primitive ( 66228L , 50 , 23 ) ;
  primitive ( 66230L , 50 , 26 ) ;
  primitive ( 66229L , 50 , 27 ) ;
  primitive ( 66489L , 51 , 0 ) ;
  primitive ( 66234L , 51 , 1 ) ;
  primitive ( 66235L , 51 , 2 ) ;
  primitive ( 66216L , 53 , 0 ) ;
  primitive ( 66217L , 53 , 2 ) ;
  primitive ( 66218L , 53 , 4 ) ;
  primitive ( 66219L , 53 , 6 ) ;
  primitive ( 66507L , 52 , 0 ) ;
  primitive ( 66508L , 52 , 1 ) ;
  primitive ( 66509L , 52 , 2 ) ;
  primitive ( 66510L , 52 , 3 ) ;
  primitive ( 66511L , 52 , 4 ) ;
  primitive ( 66512L , 52 , 5 ) ;
  primitive ( 66231L , 49 , 30 ) ;
  primitive ( 66232L , 49 , 31 ) ;
  sethashtext ( 1442729L , 66232L ) ;
  setneweqtb ( 196613L , neweqtb ( curval ) ) ;
  primitive ( 66532L , 99 , 1 ) ;
  primitive ( 66533L , 99 , 2 ) ;
  primitive ( 66534L , 99 , 4 ) ;
  primitive ( 66535L , 103 , 0 ) ;
  primitive ( 66536L , 103 , 1 ) ;
  primitive ( 66537L , 103 , 2 ) ;
  primitive ( 66538L , 103 , 3 ) ;
  primitive ( 66555L , 100 , 0 ) ;
  primitive ( 66556L , 100 , 1 ) ;
  primitive ( 66557L , 101 , 0 ) ;
  primitive ( 66558L , 101 , 1 ) ;
  primitive ( 66559L , 101 , 2 ) ;
  primitive ( 66560L , 101 , 3 ) ;
  primitive ( 66561L , 101 , 4 ) ;
  primitive ( 66562L , 101 , 5 ) ;
  primitive ( 66563L , 101 , 6 ) ;
  primitive ( 66564L , 101 , 7 ) ;
  primitive ( 65701L , 88 , 721728L ) ;
  primitive ( 65705L , 88 , 983872L ) ;
  primitive ( 66567L , 88 , 984128L ) ;
  primitive ( 65702L , 88 , 787264L ) ;
  primitive ( 65703L , 88 , 852800L ) ;
  primitive ( 65704L , 88 , 918336L ) ;
  primitive ( 65763L , 88 , 1115020L ) ;
  primitive ( 66568L , 88 , 1115276L ) ;
  primitive ( 65698L , 89 , 720960L ) ;
  primitive ( 65699L , 89 , 721216L ) ;
  primitive ( 65700L , 89 , 721472L ) ;
  primitive ( 66297L , 105 , 0 ) ;
  primitive ( 66309L , 105 , 1 ) ;
  primitive ( 66588L , 81 , 0 ) ;
  primitive ( 66589L , 81 , 1 ) ;
  primitive ( 65558L , 106 , 0 ) ;
  primitive ( 65559L , 106 , 1 ) ;
  primitive ( 65560L , 106 , 2 ) ;
  primitive ( 66602L , 106 , 3 ) ;
  primitive ( 66603L , 60 , 1 ) ;
  primitive ( 66604L , 60 , 0 ) ;
  primitive ( 66605L , 58 , 0 ) ;
  primitive ( 66606L , 58 , 1 ) ;
  primitive ( 66612L , 57 , 787264L ) ;
  primitive ( 66613L , 57 , 852800L ) ;
  primitive ( 66614L , 19 , 0 ) ;
  primitive ( 66615L , 19 , 1 ) ;
  primitive ( 66616L , 19 , 2 ) ;
  primitive ( 66617L , 19 , 3 ) ;
  primitive ( 66661L , 59 , 0 ) ;
  primitive ( 65903L , 59 , 1 ) ;
  writeloc = curval ;
  primitive ( 66662L , 59 , 2 ) ;
  primitive ( 66663L , 59 , 3 ) ;
  specialloc = curval ;
  specialtoken = 1048575L + specialloc ;
  primitive ( 66664L , 59 , 4 ) ;
  primitive ( 66665L , 59 , 5 ) ;
  primitive ( 66666L , 76 , 55 ) ;
  primitive ( 66667L , 76 , 56 ) ;
  primitive ( 66668L , 95 , 1049479L ) ;
  primitive ( 66669L , 95 , 1049480L ) ;
  primitive ( 66670L , 95 , 1049481L ) ;
  primitive ( 66671L , 95 , 1049482L ) ;
  primitive ( 66672L , 95 , 1049483L ) ;
  primitive ( 65786L , 77 , 1180578L ) ;
  primitive ( 65785L , 77 , 1180577L ) ;
  primitive ( 65787L , 77 , 1180579L ) ;
  primitive ( 65788L , 77 , 1180580L ) ;
  primitive ( 66797L , 116 , 0 ) ;
  primitive ( 66798L , 116 , 1 ) ;
  primitive ( 66799L , 116 , 2 ) ;
  primitive ( 66800L , 116 , 3 ) ;
  primitive ( 66801L , 116 , 4 ) ;
  primitive ( 66802L , 116 , 5 ) ;
  primitive ( 66803L , 116 , 6 ) ;
  primitive ( 66804L , 116 , 7 ) ;
  primitive ( 66805L , 117 , 0 ) ;
  primitive ( 66806L , 117 , 1 ) ;
  primitive ( 66807L , 117 , 2 ) ;
  primitive ( 66808L , 117 , 3 ) ;
  primitive ( 66809L , 117 , 4 ) ;
  primitive ( 66810L , 117 , 5 ) ;
  primitive ( 66811L , 117 , 6 ) ;
  primitive ( 66812L , 117 , 7 ) ;
  geqdefine ( 589876L , 137 , 0 ) ;
  geqdefine ( 589877L , 137 , 0 ) ;
  geqdefine ( 589878L , 137 , 0 ) ;
  geqdefine ( 589879L , 137 , 0 ) ;
  geqdefine ( 589875L , 137 , 0 ) ;
  geqdefine ( 589881L , 137 , 0 ) ;
  geqdefine ( 589882L , 137 , 0 ) ;
  geqdefine ( 589883L , 137 , 0 ) ;
  geqdefine ( 589884L , 137 , 0 ) ;
  geqdefine ( 589880L , 137 , 0 ) ;
  primitive ( 66825L , 108 , 0 ) ;
  primitive ( 66826L , 108 , 1 ) ;
  primitive ( 66827L , 110 , 0 ) ;
  primitive ( 66828L , 112 , 0 ) ;
  primitive ( 66829L , 113 , 0 ) ;
  primitive ( 66830L , 111 , 0 ) ;
  primitive ( 66831L , 114 , 1 ) ;
  primitive ( 66832L , 114 , 2 ) ;
  primitive ( 66833L , 114 , 3 ) ;
  primitive ( 66834L , 114 , 4 ) ;
  primitive ( 66835L , 115 , 0 ) ;
  setequiv ( 524335L , 0 ) ;
  nonewcontrolsequence = true ;
} 
#endif /* INITEX */
void 
mainbody ( void ) 
{
  mainbody_regmem 
  bounddefault = 1000000L ;
  boundname = "main_memory" ;
  setupboundvariable ( addressof ( mainmemory ) , boundname , bounddefault ) ;
  bounddefault = 0 ;
  boundname = "extra_mem_top" ;
  setupboundvariable ( addressof ( extramemtop ) , boundname , bounddefault ) 
  ;
  bounddefault = 0 ;
  boundname = "extra_mem_bot" ;
  setupboundvariable ( addressof ( extramembot ) , boundname , bounddefault ) 
  ;
  bounddefault = 300000L ;
  boundname = "pool_size" ;
  setupboundvariable ( addressof ( poolsize ) , boundname , bounddefault ) ;
  bounddefault = 200000L ;
  boundname = "string_vacancies" ;
  setupboundvariable ( addressof ( stringvacancies ) , boundname , 
  bounddefault ) ;
  bounddefault = 5000 ;
  boundname = "pool_free" ;
  setupboundvariable ( addressof ( poolfree ) , boundname , bounddefault ) ;
  bounddefault = 100000L ;
  boundname = "max_strings" ;
  setupboundvariable ( addressof ( maxstrings ) , boundname , bounddefault ) ;
  bounddefault = 100 ;
  boundname = "strings_free" ;
  setupboundvariable ( addressof ( stringsfree ) , boundname , bounddefault ) 
  ;
  bounddefault = 20000 ;
  boundname = "trie_size" ;
  setupboundvariable ( addressof ( triesize ) , boundname , bounddefault ) ;
  bounddefault = 659 ;
  boundname = "hyph_size" ;
  setupboundvariable ( addressof ( hyphsize ) , boundname , bounddefault ) ;
  bounddefault = 20000 ;
  boundname = "buf_size" ;
  setupboundvariable ( addressof ( bufsize ) , boundname , bounddefault ) ;
  bounddefault = 50 ;
  boundname = "nest_size" ;
  setupboundvariable ( addressof ( nestsize ) , boundname , bounddefault ) ;
  bounddefault = 15 ;
  boundname = "max_in_open" ;
  setupboundvariable ( addressof ( maxinopen ) , boundname , bounddefault ) ;
  bounddefault = 60 ;
  boundname = "param_size" ;
  setupboundvariable ( addressof ( paramsize ) , boundname , bounddefault ) ;
  bounddefault = 4000 ;
  boundname = "save_size" ;
  setupboundvariable ( addressof ( savesize ) , boundname , bounddefault ) ;
  bounddefault = 300 ;
  boundname = "stack_size" ;
  setupboundvariable ( addressof ( stacksize ) , boundname , bounddefault ) ;
  bounddefault = 16384 ;
  boundname = "dvi_buf_size" ;
  setupboundvariable ( addressof ( dvibufsize ) , boundname , bounddefault ) ;
  bounddefault = 79 ;
  boundname = "error_line" ;
  setupboundvariable ( addressof ( errorline ) , boundname , bounddefault ) ;
  bounddefault = 50 ;
  boundname = "half_error_line" ;
  setupboundvariable ( addressof ( halferrorline ) , boundname , bounddefault 
  ) ;
  bounddefault = 79 ;
  boundname = "max_print_line" ;
  setupboundvariable ( addressof ( maxprintline ) , boundname , bounddefault ) 
  ;
  bounddefault = 1000 ;
  boundname = "ocp_list_size" ;
  setupboundvariable ( addressof ( ocplistsize ) , boundname , bounddefault ) 
  ;
  bounddefault = 1000 ;
  boundname = "ocp_buf_size" ;
  setupboundvariable ( addressof ( ocpbufsize ) , boundname , bounddefault ) ;
  bounddefault = 1000 ;
  boundname = "ocp_stack_size" ;
  setupboundvariable ( addressof ( ocpstacksize ) , boundname , bounddefault ) 
  ;
  {
    if ( mainmemory < infmainmemory ) 
    mainmemory = infmainmemory ;
    else if ( mainmemory > supmainmemory ) 
    mainmemory = supmainmemory ;
  } 
	;
#ifdef INITEX
  if ( iniversion ) 
  {
    extramemtop = 0 ;
  } 
#endif /* INITEX */
  extramembot = 0 ;
  if ( extramemtop > supmainmemory ) 
  extramemtop = supmainmemory ;
  memtop = membot + mainmemory - 1 ;
  memmin = membot ;
  memmax = memtop ;
  {
    if ( triesize < inftriesize ) 
    triesize = inftriesize ;
    else if ( triesize > suptriesize ) 
    triesize = suptriesize ;
  } 
  {
    if ( hyphsize < infhyphsize ) 
    hyphsize = infhyphsize ;
    else if ( hyphsize > suphyphsize ) 
    hyphsize = suphyphsize ;
  } 
  {
    if ( bufsize < infbufsize ) 
    bufsize = infbufsize ;
    else if ( bufsize > supbufsize ) 
    bufsize = supbufsize ;
  } 
  {
    if ( nestsize < infnestsize ) 
    nestsize = infnestsize ;
    else if ( nestsize > supnestsize ) 
    nestsize = supnestsize ;
  } 
  {
    if ( maxinopen < infmaxinopen ) 
    maxinopen = infmaxinopen ;
    else if ( maxinopen > supmaxinopen ) 
    maxinopen = supmaxinopen ;
  } 
  {
    if ( paramsize < infparamsize ) 
    paramsize = infparamsize ;
    else if ( paramsize > supparamsize ) 
    paramsize = supparamsize ;
  } 
  {
    if ( savesize < infsavesize ) 
    savesize = infsavesize ;
    else if ( savesize > supsavesize ) 
    savesize = supsavesize ;
  } 
  {
    if ( stacksize < infstacksize ) 
    stacksize = infstacksize ;
    else if ( stacksize > supstacksize ) 
    stacksize = supstacksize ;
  } 
  {
    if ( dvibufsize < infdvibufsize ) 
    dvibufsize = infdvibufsize ;
    else if ( dvibufsize > supdvibufsize ) 
    dvibufsize = supdvibufsize ;
  } 
  {
    if ( poolsize < infpoolsize ) 
    poolsize = infpoolsize ;
    else if ( poolsize > suppoolsize ) 
    poolsize = suppoolsize ;
  } 
  {
    if ( stringvacancies < infstringvacancies ) 
    stringvacancies = infstringvacancies ;
    else if ( stringvacancies > supstringvacancies ) 
    stringvacancies = supstringvacancies ;
  } 
  {
    if ( poolfree < infpoolfree ) 
    poolfree = infpoolfree ;
    else if ( poolfree > suppoolfree ) 
    poolfree = suppoolfree ;
  } 
  {
    if ( maxstrings < infmaxstrings ) 
    maxstrings = infmaxstrings ;
    else if ( maxstrings > supmaxstrings ) 
    maxstrings = supmaxstrings ;
  } 
  {
    if ( stringsfree < infstringsfree ) 
    stringsfree = infstringsfree ;
    else if ( stringsfree > supstringsfree ) 
    stringsfree = supstringsfree ;
  } 
  if ( errorline > 255 ) 
  errorline = 255 ;
  buffer = xmallocarray ( ASCIIcode , bufsize ) ;
  nest = xmallocarray ( liststaterecord , nestsize ) ;
  savestack = xmallocarray ( memoryword , savesize ) ;
  inputstack = xmallocarray ( instaterecord , stacksize ) ;
  inputfile = xmallocarray ( alphafile , maxinopen ) ;
  inputfilemode = xmallocarray ( halfword , maxinopen ) ;
  inputfiletranslation = xmallocarray ( halfword , maxinopen ) ;
  linestack = xmallocarray ( integer , maxinopen ) ;
  eofseen = xmallocarray ( boolean , maxinopen ) ;
  grpstack = xmallocarray ( savepointer , maxinopen ) ;
  ifstack = xmallocarray ( halfword , maxinopen ) ;
  sourcefilenamestack = xmallocarray ( strnumber , maxinopen ) ;
  fullsourcefilenamestack = xmallocarray ( strnumber , maxinopen ) ;
  paramstack = xmallocarray ( halfword , paramsize ) ;
  dvibuf = xmallocarray ( realeightbits , dvibufsize ) ;
  hyphword = xmallocarray ( strnumber , hyphsize ) ;
  hyphlist = xmallocarray ( halfword , hyphsize ) ;
  hyphlink = xmallocarray ( hyphpointer , hyphsize ) ;
  ocplistinfo = xmallocarray ( memoryword , ocplistsize ) ;
  ocplstackinfo = xmallocarray ( memoryword , ocplistsize ) ;
  ocplistlist = xmallocarray ( ocplistindex , ocplistsize ) ;
  otpinitinputbuf = xmallocarray ( quarterword , ocpbufsize ) ;
  otpinputbuf = xmallocarray ( quarterword , ocpbufsize ) ;
  otpoutputbuf = xmallocarray ( quarterword , ocpbufsize ) ;
  otpstackbuf = xmallocarray ( quarterword , ocpstacksize ) ;
  otpcalcs = xmallocarray ( halfword , ocpstacksize ) ;
  otpstates = xmallocarray ( halfword , ocpstacksize ) ;
	;
#ifdef INITEX
  if ( iniversion ) 
  {
    yzmem = xmallocarray ( memoryword , memtop - membot + 1 ) ;
    zmem = yzmem - membot ;
    strstartar = xmallocarray ( poolpointer , maxstrings - 65535L ) ;
    strpool = xmallocarray ( packedASCIIcode , poolsize ) ;
  } 
#endif /* INITEX */
  history = 3 ;
  if ( readyalready == 314159L ) 
  goto lab1 ;
  bad = 0 ;
  if ( ( halferrorline < 30 ) || ( halferrorline > errorline - 15 ) ) 
  bad = 1 ;
  if ( maxprintline < 60 ) 
  bad = 2 ;
  if ( dvibufsize % 8 != 0 ) 
  bad = 3 ;
  if ( membot + 1100 > memtop ) 
  bad = 4 ;
  if ( 55711L > 65536L ) 
  bad = 5 ;
  if ( maxinopen >= 128 ) 
  bad = 6 ;
  if ( memtop < 267 ) 
  bad = 7 ;
	;
#ifdef INITEX
  if ( ( memmin != membot ) || ( memmax != memtop ) ) 
  bad = 10 ;
#endif /* INITEX */
  if ( ( memmin > membot ) || ( memmax < memtop ) ) 
  bad = 10 ;
  if ( ( 0 > 0 ) || ( 65535L < 32767 ) ) 
  bad = 11 ;
  if ( ( 0 != 0 ) || ( 1073741823L < 1073741823L ) ) 
  bad = 12 ;
  if ( ( 0 < 0 ) || ( 65535L > 1073741823L ) ) 
  bad = 13 ;
  if ( ( memmin < 0 ) || ( memtop + supmainmemory >= 1073741823L ) ) 
  bad = 14 ;
  if ( ( 0 < 0 ) || ( fontmax > 65535L ) ) 
  bad = 15 ;
  if ( fontmax > 65536L ) 
  bad = 16 ;
  if ( ( savesize > 1073741823L ) || ( maxstrings > 1073741823L ) ) 
  bad = 17 ;
  if ( bufsize > 1073741823L ) 
  bad = 18 ;
  if ( 65535L < 65535L ) 
  bad = 19 ;
  if ( 1441804L > 1073741823L ) 
  bad = 21 ;
  if ( formatdefaultlength > maxint ) 
  bad = 31 ;
  if ( 2 * 1073741823L < memtop - memmin ) 
  bad = 41 ;
  if ( bad > 0 ) 
  {
    fprintf ( stdout , "%s%s%ld\n",  "Ouch---my internal constants have been clobbered!" ,     "---case " , (long)bad ) ;
    goto lab9999 ;
  } 
  initialize () ;
	;
#ifdef INITEX
  if ( iniversion ) 
  {
    if ( ! getstringsstarted () ) 
    goto lab9999 ;
    initprim () ;
    initstrptr = strptr ;
    initpoolptr = poolptr ;
    odateandtime ( 1049428L , 1049429L , 1049430L , 1049431L ) ;
  } 
#endif /* INITEX */
  readyalready = 314159L ;
  lab1: selector = 17 ;
  tally = 0 ;
  termoffset = 0 ;
  fileoffset = 0 ;
  if ( srcspecialsp || filelineerrorstylep || parsefirstlinep ) 
  fprintf ( stdout , "%s%s%c%s%c%s",  "This is Aleph, Version 3.14159265-" , "1.15" , '-' , "2.1"   , '-' , "0.1" ) ;
  else
  fprintf ( stdout , "%s%s%c%s%c%s",  "This is Aleph, Version 3.14159265-" , "1.15" , '-' ,   "2.1" , '-' , "0.1" ) ;
  Fputs ( stdout ,  versionstring ) ;
  if ( formatident == 0 ) 
  fprintf ( stdout , "%s%s%c\n",  " (preloaded format=" , dumpname , ')' ) ;
  else {
      
    slowprint ( formatident ) ;
    println () ;
  } 
  if ( shellenabledp ) 
  {
    putc ( ' ' ,  stdout );
    if ( restrictedshell ) 
    {
      Fputs ( stdout ,  "restricted " ) ;
    } 
    fprintf ( stdout , "%s\n",  "\\write18 enabled." ) ;
  } 
  if ( srcspecialsp ) 
  {
    fprintf ( stdout , "%s\n",  " Source specials enabled." ) ;
  } 
  fflush ( stdout ) ;
  jobname = 0 ;
  nameinprogress = false ;
  logopened = false ;
  outputfilename = 0 ;
  {
    {
      inputptr = 0 ;
      maxinstack = 0 ;
      sourcefilenamestack [0 ]= 0 ;
      fullsourcefilenamestack [0 ]= 0 ;
      inopen = 0 ;
      openparens = 0 ;
      maxbufstack = 0 ;
      grpstack [0 ]= 0 ;
      ifstack [0 ]= 0 ;
      paramptr = 0 ;
      maxparamstack = 0 ;
      geqdefine ( 589875L , 137 , 1 ) ;
      terminmode = newequiv ( 589875L ) ;
      termoutmode = newequiv ( 589875L ) ;
      if ( terminmode > 0 ) 
      termintranslation = newequiv ( 589876L + terminmode - 1 ) ;
      if ( termoutmode > 0 ) 
      termouttranslation = newequiv ( 589881L + terminmode - 1 ) ;
      first = bufsize ;
      do {
	  buffer [first ]= 0 ;
	decr ( first ) ;
      } while ( ! ( first == 0 ) ) ;
      scannerstatus = 0 ;
      warningindex = 0 ;
      first = 1 ;
      curinput .statefield = 33 ;
      curinput .startfield = 1 ;
      curinput .indexfield = 0 ;
      line = 0 ;
      curinput .namefield = 0 ;
      curinput .ocplstackfield = 0 ;
      curinput .ocpnofield = 0 ;
      forceeof = false ;
      alignstate = 1000000L ;
      if ( ! initterminal () ) 
      goto lab9999 ;
      curinput .limitfield = last ;
      first = last + 1 ;
    } 
	;
#ifdef INITEX
    if ( ( etexp || ( buffer [curinput .locfield ]== 42 ) ) && ( formatident 
    == 66630L ) ) 
    {
      nonewcontrolsequence = false ;
      primitive ( 66698L , 73 , 3 ) ;
      primitive ( 66699L , 73 , 6 ) ;
      primitive ( 66700L , 73 , 7 ) ;
      primitive ( 66701L , 73 , 11 ) ;
      primitive ( 66702L , 73 , 8 ) ;
      primitive ( 66703L , 73 , 9 ) ;
      primitive ( 66704L , 73 , 10 ) ;
      primitive ( 66705L , 125 , 9 ) ;
      primitive ( 66706L , 125 , 10 ) ;
      primitive ( 66707L , 125 , 11 ) ;
      primitive ( 66709L , 75 , 524333L ) ;
      primitive ( 66710L , 76 , 1049469L ) ;
      primitive ( 66711L , 76 , 1049470L ) ;
      primitive ( 66712L , 76 , 1049471L ) ;
      primitive ( 66713L , 76 , 1049472L ) ;
      primitive ( 66714L , 76 , 1049473L ) ;
      primitive ( 66715L , 76 , 1049474L ) ;
      primitive ( 66716L , 76 , 1049475L ) ;
      primitive ( 66717L , 76 , 1049476L ) ;
      primitive ( 66718L , 76 , 1049477L ) ;
      primitive ( 66733L , 73 , 12 ) ;
      primitive ( 66734L , 73 , 13 ) ;
      primitive ( 66735L , 73 , 14 ) ;
      primitive ( 66736L , 73 , 15 ) ;
      primitive ( 66737L , 73 , 16 ) ;
      primitive ( 66738L , 73 , 19 ) ;
      primitive ( 66739L , 73 , 20 ) ;
      primitive ( 66740L , 73 , 21 ) ;
      primitive ( 66741L , 73 , 22 ) ;
      primitive ( 66742L , 73 , 23 ) ;
      primitive ( 66743L , 73 , 24 ) ;
      primitive ( 66744L , 73 , 25 ) ;
      primitive ( 66745L , 19 , 4 ) ;
      primitive ( 66747L , 19 , 5 ) ;
      primitive ( 66748L , 126 , 1 ) ;
      primitive ( 66749L , 126 , 5 ) ;
      primitive ( 66750L , 19 , 6 ) ;
      primitive ( 66754L , 85 , 2 ) ;
      primitive ( 66233L , 49 , 1 ) ;
      primitive ( 66758L , 121 , 2 ) ;
      primitive ( 66760L , 102 , 1 ) ;
      primitive ( 66101L , 119 , 1 ) ;
      primitive ( 66761L , 122 , 17 ) ;
      primitive ( 66762L , 122 , 18 ) ;
      primitive ( 66763L , 122 , 19 ) ;
      primitive ( 66546L , 99 , 8 ) ;
      primitive ( 66769L , 73 , 30 ) ;
      primitive ( 66770L , 73 , 31 ) ;
      primitive ( 66771L , 73 , 32 ) ;
      primitive ( 66772L , 73 , 33 ) ;
      primitive ( 66776L , 73 , 17 ) ;
      primitive ( 66777L , 73 , 18 ) ;
      primitive ( 66778L , 73 , 26 ) ;
      primitive ( 66779L , 73 , 27 ) ;
      primitive ( 66780L , 73 , 28 ) ;
      primitive ( 66781L , 73 , 29 ) ;
      primitive ( 66782L , 18 , 5 ) ;
      primitive ( 66783L , 127 , 5 ) ;
      primitive ( 66784L , 127 , 6 ) ;
      primitive ( 66785L , 127 , 7 ) ;
      primitive ( 66786L , 127 , 8 ) ;
      primitive ( 66787L , 127 , 9 ) ;
      primitive ( 66791L , 24 , 2 ) ;
      primitive ( 66792L , 24 , 3 ) ;
      primitive ( 66793L , 87 , 524321L ) ;
      primitive ( 66794L , 87 , 524322L ) ;
      primitive ( 66795L , 87 , 524323L ) ;
      primitive ( 66796L , 87 , 524324L ) ;
      if ( ( buffer [curinput .locfield ]== 42 ) ) 
      incr ( curinput .locfield ) ;
      eTeXmode = 1 ;
      maxregnum = 65535L ;
      maxreghelpline = 66006L ;
    } 
#endif /* INITEX */
    if ( ! nonewcontrolsequence ) 
    nonewcontrolsequence = true ;
    else if ( ( formatident == 0 ) || ( buffer [curinput .locfield ]== 38 ) 
    || dumpline ) 
    {
      if ( formatident != 0 ) 
      initialize () ;
      if ( ! openfmtfile () ) 
      goto lab9999 ;
      if ( ! loadfmtfile () ) 
      {
	wclose ( fmtfile ) ;
	goto lab9999 ;
      } 
      wclose ( fmtfile ) ;
      while ( ( curinput .locfield < curinput .limitfield ) && ( buffer [
      curinput .locfield ]== 32 ) ) incr ( curinput .locfield ) ;
    } 
    if ( ( eTeXmode == 1 ) ) 
    fprintf ( stdout , "%s\n",  "entering extended mode" ) ;
    if ( ( neweqtbint ( 1049456L ) < 0 ) || ( neweqtbint ( 1049456L ) > 255 ) 
    ) 
    decr ( curinput .limitfield ) ;
    else buffer [curinput .limitfield ]= neweqtbint ( 1049456L ) ;
    odateandtime ( 1049428L , 1049429L , 1049430L , 1049431L ) ;
	;
#ifdef INITEX
    if ( trienotready ) 
    {
      trie = xmallocarray ( twohalves , triesize ) ;
      triec = xmallocarray ( ASCIIcode , triesize ) ;
      trieo = xmallocarray ( quarterword , triesize ) ;
      triel = xmallocarray ( triepointer , triesize ) ;
      trier = xmallocarray ( triepointer , triesize ) ;
      triehash = xmallocarray ( triepointer , triesize ) ;
      trietaken = xmallocarray ( boolean , triesize ) ;
      triemin = xmallocarray ( triepointer , 65536L ) ;
      triel [0 ]= 0 ;
      triec [0 ]= 0 ;
      trieptr = 0 ;
      trier [0 ]= 0 ;
      hyphstart = 0 ;
    } 
#endif /* INITEX */
    magicoffset = strstartar [712 ]- 9 * 16 ;
    if ( interaction == 0 ) 
    selector = 16 ;
    else selector = 17 ;
    if ( ( curinput .locfield < curinput .limitfield ) && ( newequiv ( 721728L 
    + buffer [curinput .locfield ]) != 0 ) ) 
    startinput () ;
    {
      textdirptr = newdir ( 0 ) ;
    } 
  } 
  history = 0 ;
  maincontrol () ;
  finalcleanup () ;
  closefilesandterminate () ;
  lab9999: {
      
    fflush ( stdout ) ;
    readyalready = 0 ;
    if ( ( history != 0 ) && ( history != 1 ) ) 
    uexit ( 1 ) ;
    else uexit ( 0 ) ;
  } 
} 
