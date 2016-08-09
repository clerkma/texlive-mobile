#define EXTERN extern
#include "eptexd.h"

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
  curlist .pnodefield = curlist .tailfield ;
  curlist .dirfield = 4 ;
  curlist .adjdirfield = curlist .dirfield ;
  curlist .pdispfield = 0 ;
  curlist .lastjchrfield = -268435455L ;
  curlist .eTeXauxfield = -268435455L ;
  curlist .auxfield .cint = -65536000L ;
  curlist .mlfield = 0 ;
  curlist .pgfield = 0 ;
  shownmode = 0 ;
  pagecontents = 0 ;
  pagetail = memtop - 2 ;
  lastglue = 268435455L ;
  lastpenalty = 0 ;
  lastkern = 0 ;
  pagesofar [8 ]= 0 ;
  pagemaxdepth = 0 ;
  {register integer for_end; k = 28931 ;for_end = 30053 ; if ( k <= for_end) 
  do 
    xeqlevel [k ]= 1 ;
  while ( k++ < for_end ) ;} 
  nonewcontrolsequence = true ;
  prim [0 ].v.LH = 0 ;
  prim [0 ].v.RH = 0 ;
  {register integer for_end; k = 1 ;for_end = 2100 ; if ( k <= for_end) do 
    prim [k ]= prim [0 ];
  while ( k++ < for_end ) ;} 
  primeqtb [0 ].hh.b1 = 0 ;
  primeqtb [0 ].hh.b0 = 113 ;
  primeqtb [0 ].hh .v.RH = -268435455L ;
  {register integer for_end; k = 1 ;for_end = 2100 ; if ( k <= for_end) do 
    primeqtb [k ]= primeqtb [0 ];
  while ( k++ < for_end ) ;} 
  saveptr = 0 ;
  curlevel = 1 ;
  curgroup = 0 ;
  curboundary = 0 ;
  maxsavestack = 0 ;
  magset = 0 ;
  skipmode = true ;
  expanddepthcount = 0 ;
  curmark [0 ]= -268435455L ;
  curmark [1 ]= -268435455L ;
  curmark [2 ]= -268435455L ;
  curmark [3 ]= -268435455L ;
  curmark [4 ]= -268435455L ;
  curval = 0 ;
  curvallevel = 0 ;
  radix = 0 ;
  curorder = 0 ;
  {register integer for_end; k = 0 ;for_end = 16 ; if ( k <= for_end) do 
    readopen [k ]= 2 ;
  while ( k++ < for_end ) ;} 
  condptr = -268435455L ;
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
  dirused = false ;
  halfbuf = dvibufsize / 2 ;
  dvilimit = dvibufsize ;
  dviptr = 0 ;
  dvioffset = 0 ;
  dvigone = 0 ;
  downptr = -268435455L ;
  rightptr = -268435455L ;
  adjusttail = -268435455L ;
  lastbadness = 0 ;
  curkanjiskip = membot ;
  curxkanjiskip = membot ;
  packbeginline = 0 ;
  emptyfield .v.RH = 0 ;
  emptyfield .v.LH = -268435455L ;
  nulldelimiter .b0 = 0 ;
  nulldelimiter .b1 = 0 ;
  nulldelimiter .b2 = 0 ;
  nulldelimiter .b3 = 0 ;
  alignptr = -268435455L ;
  curalign = -268435455L ;
  curspan = -268435455L ;
  curloop = -268435455L ;
  curhead = -268435455L ;
  curtail = -268435455L ;
  {register integer for_end; z = 0 ;for_end = hyphsize ; if ( z <= for_end) 
  do 
    {
      hyphword [z ]= 0 ;
      hyphlist [z ]= -268435455L ;
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
  insdisc = false ;
  aftertoken = 0 ;
  longhelpseen = false ;
  formatident = 0 ;
  {register integer for_end; k = 0 ;for_end = 17 ; if ( k <= for_end) do 
    writeopen [k ]= false ;
  while ( k++ < for_end ) ;} 
  LRptr = -268435455L ;
  LRproblems = 0 ;
  curdir = 0 ;
  pseudofiles = -268435455L ;
  saroot [6 ]= -268435455L ;
  sanull .hh .v.LH = -268435455L ;
  sanull .hh .v.RH = -268435455L ;
  sachain = -268435455L ;
  salevel = 0 ;
  discptr [2 ]= -268435455L ;
  discptr [3 ]= -268435455L ;
  editnamestart = 0 ;
  stopatspace = true ;
	;
#ifdef TEXMF_DEBUG
  debugformatfile = true ;
#endif /* TEXMF_DEBUG */
  mltexenabledp = false ;
  inhibitglueflag = false ;
  pagedir = 4 ;
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
	
      mem [k ].hh .v.RH = -268435454L ;
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
    mem [rover ].hh .v.RH = 268435455L ;
    mem [rover ].hh .v.LH = 1000 ;
    mem [rover + 1 ].hh .v.LH = rover ;
    mem [rover + 1 ].hh .v.RH = rover ;
    lomemmax = rover + 1000 ;
    mem [lomemmax ].hh .v.RH = -268435455L ;
    mem [lomemmax ].hh .v.LH = -268435455L ;
    {register integer for_end; k = memtop - 13 ;for_end = memtop ; if ( k <= 
    for_end) do 
      mem [k ]= mem [lomemmax ];
    while ( k++ < for_end ) ;} 
    mem [memtop - 10 ].hh .v.LH = 81054L ;
    mem [memtop - 9 ].hh .v.RH = 65536L ;
    mem [memtop - 9 ].hh .v.LH = -268435455L ;
    mem [memtop - 7 ].hh.b0 = 1 ;
    mem [memtop - 6 ].hh .v.LH = 268435455L ;
    mem [memtop - 7 ].hh.b1 = 0 ;
    mem [memtop ].hh.b1 = 255 ;
    mem [memtop ].hh.b0 = 1 ;
    mem [memtop ].hh .v.RH = memtop ;
    mem [memtop - 2 ].hh.b0 = 12 ;
    mem [memtop - 2 ].hh.b1 = 0 ;
    avail = -268435455L ;
    memend = memtop ;
    himemmin = memtop - 13 ;
    varused = membot + 24 - membot ;
    dynused = 14 ;
    eqtb [24527 ].hh.b0 = 113 ;
    eqtb [24527 ].hh .v.RH = -268435455L ;
    eqtb [24527 ].hh.b1 = 0 ;
    {register integer for_end; k = 1 ;for_end = eqtbtop ; if ( k <= for_end) 
    do 
      eqtb [k ]= eqtb [24527 ];
    while ( k++ < for_end ) ;} 
    eqtb [24528 ].hh .v.RH = membot ;
    eqtb [24528 ].hh.b1 = 1 ;
    eqtb [24528 ].hh.b0 = 129 ;
    {register integer for_end; k = 24529 ;for_end = 25060 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [24528 ];
    while ( k++ < for_end ) ;} 
    mem [membot ].hh .v.RH = mem [membot ].hh .v.RH + 533 ;
    eqtb [25061 ].hh .v.RH = -268435455L ;
    eqtb [25061 ].hh.b0 = 130 ;
    eqtb [25061 ].hh.b1 = 1 ;
    {register integer for_end; k = 25328 ;for_end = 25331 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [25061 ];
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 25062 ;for_end = 25327 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [24527 ];
    while ( k++ < for_end ) ;} 
    eqtb [25332 ].hh .v.RH = -268435455L ;
    eqtb [25332 ].hh.b0 = 131 ;
    eqtb [25332 ].hh.b1 = 1 ;
    {register integer for_end; k = 25333 ;for_end = 25587 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [25332 ];
    while ( k++ < for_end ) ;} 
    eqtb [25588 ].hh .v.RH = 0 ;
    eqtb [25588 ].hh.b0 = 132 ;
    eqtb [25588 ].hh.b1 = 1 ;
    eqtb [26357 ].hh .v.RH = 0 ;
    eqtb [26357 ].hh.b0 = 132 ;
    eqtb [26357 ].hh.b1 = 1 ;
    eqtb [26358 ].hh .v.RH = 0 ;
    eqtb [26358 ].hh.b0 = 132 ;
    eqtb [26358 ].hh.b1 = 1 ;
    {register integer for_end; k = 25589 ;for_end = 26356 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [25588 ];
    while ( k++ < for_end ) ;} 
    eqtb [26361 ].hh .v.RH = 0 ;
    eqtb [26361 ].hh.b0 = 132 ;
    eqtb [26361 ].hh.b1 = 1 ;
    {register integer for_end; k = 26362 ;for_end = 28930 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [26361 ];
    while ( k++ < for_end ) ;} 
    eqtb [26359 ]= eqtb [26361 ];
    eqtb [26360 ]= eqtb [26361 ];
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      {
	eqtb [26361 + k ].hh .v.RH = 12 ;
	eqtb [26617 + k ].hh .v.RH = 18 ;
	eqtb [28419 + k ].hh .v.RH = k ;
	eqtb [28163 + k ].hh .v.RH = 1000 ;
	eqtb [26873 + k ].hh .v.RH = 0 ;
	eqtb [27129 + k ].hh .v.RH = 0 ;
	eqtb [27129 + k ].hh.b0 = 0 ;
	eqtb [27385 + k ].hh .v.RH = 0 ;
	eqtb [27385 + k ].hh.b0 = 0 ;
      } 
    while ( k++ < for_end ) ;} 
    eqtb [26374 ].hh .v.RH = 5 ;
    eqtb [26393 ].hh .v.RH = 10 ;
    eqtb [26453 ].hh .v.RH = 0 ;
    eqtb [26398 ].hh .v.RH = 14 ;
    eqtb [26488 ].hh .v.RH = 15 ;
    eqtb [26361 ].hh .v.RH = 9 ;
    {register integer for_end; k = 48 ;for_end = 57 ; if ( k <= for_end) do 
      {
	eqtb [28419 + k ].hh .v.RH = k + 458752L ;
	eqtb [26873 + k ].hh .v.RH = 3 ;
      } 
    while ( k++ < for_end ) ;} 
    eqtb [27641 ].hh .v.RH = toDVI ( fromJIS ( 8507 ) ) ;
    eqtb [27642 ].hh .v.RH = toDVI ( fromJIS ( 12396 ) ) ;
    eqtb [27643 ].hh .v.RH = toDVI ( fromJIS ( 18035 ) ) ;
    eqtb [27644 ].hh .v.RH = toDVI ( fromJIS ( 15152 ) ) ;
    eqtb [27645 ].hh .v.RH = toDVI ( fromJIS ( 15181 ) ) ;
    eqtb [27646 ].hh .v.RH = toDVI ( fromJIS ( 14430 ) ) ;
    eqtb [27647 ].hh .v.RH = toDVI ( fromJIS ( 20283 ) ) ;
    eqtb [27648 ].hh .v.RH = toDVI ( fromJIS ( 15415 ) ) ;
    eqtb [27649 ].hh .v.RH = toDVI ( fromJIS ( 18476 ) ) ;
    eqtb [27650 ].hh .v.RH = toDVI ( fromJIS ( 13925 ) ) ;
    {register integer for_end; k = 65 ;for_end = 90 ; if ( k <= for_end) do 
      {
	eqtb [26361 + k ].hh .v.RH = 11 ;
	eqtb [26361 + k + 32 ].hh .v.RH = 11 ;
	eqtb [28419 + k ].hh .v.RH = k + 459008L ;
	eqtb [28419 + k + 32 ].hh .v.RH = k + 459040L ;
	eqtb [27651 + k ].hh .v.RH = k + 32 ;
	eqtb [27651 + k + 32 ].hh .v.RH = k + 32 ;
	eqtb [27907 + k ].hh .v.RH = k ;
	eqtb [27907 + k + 32 ].hh .v.RH = k ;
	eqtb [26873 + k ].hh .v.RH = 3 ;
	eqtb [26873 + k + 32 ].hh .v.RH = 3 ;
	eqtb [28163 + k ].hh .v.RH = 999 ;
      } 
    while ( k++ < for_end ) ;} 
    eqtb [26650 ].hh .v.RH = 18 ;
    eqtb [26651 ].hh .v.RH = 18 ;
    {register integer for_end; k = 3 ;for_end = 6 ; if ( k <= for_end) do 
      eqtb [26649 + k ].hh .v.RH = 17 ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 7 ;for_end = 8 ; if ( k <= for_end) do 
      eqtb [26649 + k ].hh .v.RH = 18 ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 16 ;for_end = 84 ; if ( k <= for_end) do 
      eqtb [26649 + k ].hh .v.RH = 16 ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 28931 ;for_end = 29260 ; if ( k <= 
    for_end) do 
      eqtb [k ].cint = 0 ;
    while ( k++ < for_end ) ;} 
    eqtb [28991 ].cint = 256 ;
    eqtb [28992 ].cint = -1 ;
    eqtb [28948 ].cint = 1000 ;
    eqtb [28932 ].cint = 10000 ;
    eqtb [28972 ].cint = 1 ;
    eqtb [28971 ].cint = 25 ;
    eqtb [28977 ].cint = 92 ;
    eqtb [28980 ].cint = 13 ;
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      {
	eqtb [29261 + k ].cint = -1 ;
	setintone ( eqtb [29261 + k ], -1 ) ;
      } 
    while ( k++ < for_end ) ;} 
    eqtb [29307 ].cint = 0 ;
    setintone ( eqtb [29307 ], 0 ) ;
    {register integer for_end; k = 29517 ;for_end = 30053 ; if ( k <= 
    for_end) do 
      eqtb [k ].cint = 0 ;
    while ( k++ < for_end ) ;} 
    hashused = 15514 ;
    hashhigh = 0 ;
    cscount = 0 ;
    eqtb [15523 ].hh.b0 = 128 ;
    primused = 2100 ;
    hash [15523 ].v.RH = 541 ;
    eqtb [15525 ].hh.b0 = 42 ;
    eqtb [15525 ].hh .v.RH = 1 ;
    eqtb [15525 ].hh.b1 = 1 ;
    hash [15525 ].v.RH = 542 ;
    eqtb [28988 ].cint = 1000 ;
    eqtb [28989 ].cint = 700 ;
    eqtb [28990 ].cint = 500 ;
    {register integer for_end; k = - (integer) trieopsize ;for_end = 
    trieopsize ; if ( k <= for_end) do 
      trieophash [k ]= 0 ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      trieused [k ]= mintrieop ;
    while ( k++ < for_end ) ;} 
    maxopused = mintrieop ;
    trieopptr = 0 ;
    trienotready = true ;
    hash [15514 ].v.RH = 1318 ;
    if ( iniversion ) 
    formatident = 1393 ;
    hash [15522 ].v.RH = 1437 ;
    eqtb [15522 ].hh.b1 = 1 ;
    eqtb [15522 ].hh.b0 = 125 ;
    eqtb [15522 ].hh .v.RH = -268435455L ;
    eTeXmode = 0 ;
    maxregnum = 255 ;
    maxreghelpline = 752 ;
    {register integer for_end; i = 0 ;for_end = 5 ; if ( i <= for_end) do 
      saroot [i ]= -268435455L ;
    while ( i++ < for_end ) ;} 
  } 
#endif /* INITEX */
  synctexoffset = 28994 ;
} 
#ifdef INITEX
boolean 
getstringsstarted ( void ) 
{
  /* 30 10 */ register boolean Result; getstringsstarted_regmem 
  KANJIcode k, l  ;
  strnumber g  ;
  poolptr = 0 ;
  strptr = 0 ;
  strstart [0 ]= 0 ;
  {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
    {
      if ( ( ! ( ismultiprn ( k ) || xprn [k ]) ) ) 
      {
	{
	  strpool [poolptr ]= 94 ;
	  incr ( poolptr ) ;
	} 
	{
	  strpool [poolptr ]= 94 ;
	  incr ( poolptr ) ;
	} 
	if ( k < 64 ) 
	{
	  strpool [poolptr ]= k + 64 ;
	  incr ( poolptr ) ;
	} 
	else if ( k < 128 ) 
	{
	  strpool [poolptr ]= k - 64 ;
	  incr ( poolptr ) ;
	} 
	else {
	    
	  l = k / 16 ;
	  if ( l < 10 ) 
	  {
	    strpool [poolptr ]= l + 48 ;
	    incr ( poolptr ) ;
	  } 
	  else {
	      
	    strpool [poolptr ]= l + 87 ;
	    incr ( poolptr ) ;
	  } 
	  l = k % 16 ;
	  if ( l < 10 ) 
	  {
	    strpool [poolptr ]= l + 48 ;
	    incr ( poolptr ) ;
	  } 
	  else {
	      
	    strpool [poolptr ]= l + 87 ;
	    incr ( poolptr ) ;
	  } 
	} 
      } 
      else {
	  
	strpool [poolptr ]= k ;
	incr ( poolptr ) ;
      } 
      g = makestring () ;
    } 
  while ( k++ < for_end ) ;} 
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
  mem [rover + 1 ].hh .v.RH = 268435455L ;
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
  while ( mem [p + 1 ].hh .v.RH != 268435455L ) {
      
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
  integer primval  ;
  integer j  ;
  smallnumber l  ;
  if ( s < 256 ) 
  {
    curval = s + 257 ;
    primval = s ;
  } 
  else {
      
    k = strstart [s ];
    l = strstart [s + 1 ]- k ;
    if ( first + l > bufsize + 1 ) 
    overflow ( 257 , bufsize ) ;
    {register integer for_end; j = 0 ;for_end = l - 1 ; if ( j <= for_end) 
    do 
      buffer [first + j ]= strpool [k + j ];
    while ( j++ < for_end ) ;} 
    curval = idlookup ( first , l ) ;
    {
      decr ( strptr ) ;
      poolptr = strstart [strptr ];
    } 
    hash [curval ].v.RH = s ;
    primval = primlookup ( s ) ;
  } 
  eqtb [curval ].hh.b1 = 1 ;
  eqtb [curval ].hh.b0 = c ;
  eqtb [curval ].hh .v.RH = o ;
  primeqtb [primval ].hh.b1 = 1 ;
  primeqtb [primval ].hh.b0 = c ;
  primeqtb [primval ].hh .v.RH = o ;
} 
#endif /* INITEX */
#ifdef INITEX
trieopcode 
znewtrieop ( smallnumber d , smallnumber n , trieopcode v ) 
{
  /* 10 */ register trieopcode Result; newtrieop_regmem 
  integer h  ;
  trieopcode u  ;
  integer l  ;
  h = abs ( n + 313 * d + 361 * v + 1009 * curlang ) % ( trieopsize - 
  negtrieopsize ) + negtrieopsize ;
  while ( true ) {
      
    l = trieophash [h ];
    if ( l == 0 ) 
    {
      if ( trieopptr == trieopsize ) 
      overflow ( 1047 , trieopsize ) ;
      u = trieused [curlang ];
      if ( u == maxtrieop ) 
      overflow ( 1048 , maxtrieop - mintrieop ) ;
      incr ( trieopptr ) ;
      incr ( u ) ;
      trieused [curlang ]= u ;
      if ( u > maxopused ) 
      maxopused = u ;
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
  short ll  ;
  c = triec [p ];
  z = triemin [c ];
  while ( true ) {
      
    h = z - c ;
    if ( triemax < h + 256 ) 
    {
      if ( triesize <= h + 256 ) 
      overflow ( 1049 , triesize ) ;
      do {
	  incr ( triemax ) ;
	trietaken [triemax ]= false ;
	trietrl [triemax ]= triemax + 1 ;
	trietro [triemax ]= triemax - 1 ;
      } while ( ! ( triemax == h + 256 ) ) ;
    } 
    if ( trietaken [h ]) 
    goto lab45 ;
    q = trier [p ];
    while ( q > 0 ) {
	
      if ( trietrl [h + triec [q ]]== 0 ) 
      goto lab45 ;
      q = trier [q ];
    } 
    goto lab40 ;
    lab45: z = trietrl [z ];
  } 
  lab40: trietaken [h ]= true ;
  triehash [p ]= h ;
  q = p ;
  do {
      z = h + triec [q ];
    l = trietro [z ];
    r = trietrl [z ];
    trietro [r ]= l ;
    trietrl [l ]= r ;
    trietrl [z ]= 0 ;
    if ( l < 256 ) 
    {
      if ( z < 256 ) 
      ll = z ;
      else ll = 256 ;
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
    trietrl [z + c ]= triehash [q ];
    trietrc [z + c ]= c ;
    trietro [z + c ]= trieo [p ];
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
  trieopcode v  ;
  triepointer p, q  ;
  boolean firstchild  ;
  ASCIIcode c  ;
  if ( trienotready ) 
  {
    if ( eqtb [28982 ].cint <= 0 ) 
    curlang = 0 ;
    else if ( eqtb [28982 ].cint > 255 ) 
    curlang = 0 ;
    else curlang = eqtb [28982 ].cint ;
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
	      
	    curchr = eqtb [27651 + curchr ].hh .v.RH ;
	    if ( curchr == 0 ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 263 ) ;
		print ( 1055 ) ;
	      } 
	      {
		helpptr = 1 ;
		helpline [0 ]= 1054 ;
	      } 
	      error () ;
	    } 
	  } 
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
	    v = mintrieop ;
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
		overflow ( 1049 , triesize ) ;
		incr ( trieptr ) ;
		trier [trieptr ]= p ;
		p = trieptr ;
		triel [p ]= 0 ;
		if ( firstchild ) 
		triel [q ]= p ;
		else trier [q ]= p ;
		triec [p ]= c ;
		trieo [p ]= mintrieop ;
	      } 
	      q = p ;
	    } 
	    if ( trieo [q ]!= mintrieop ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 263 ) ;
		print ( 1056 ) ;
	      } 
	      {
		helpptr = 1 ;
		helpline [0 ]= 1054 ;
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
	    else printnl ( 263 ) ;
	    print ( 1053 ) ;
	  } 
	  printesc ( 1051 ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1054 ;
	  } 
	  error () ;
	} 
	break ;
      } 
    } 
    lab30: ;
    if ( eqtb [29003 ].cint > 0 ) 
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
	overflow ( 1049 , triesize ) ;
	incr ( trieptr ) ;
	trier [trieptr ]= p ;
	p = trieptr ;
	triel [p ]= 0 ;
	if ( firstchild ) 
	triel [q ]= p ;
	else trier [q ]= p ;
	triec [p ]= c ;
	trieo [p ]= mintrieop ;
      } 
      q = p ;
      p = triel [q ];
      firstchild = true ;
      {register integer for_end; c = 0 ;for_end = 255 ; if ( c <= for_end) 
      do 
	if ( ( eqtb [27651 + c ].hh .v.RH > 0 ) || ( ( c == 255 ) && 
	firstchild ) ) 
	{
	  if ( p == 0 ) 
	  {
	    if ( trieptr == triesize ) 
	    overflow ( 1049 , triesize ) ;
	    incr ( trieptr ) ;
	    trier [trieptr ]= p ;
	    p = trieptr ;
	    triel [p ]= 0 ;
	    if ( firstchild ) 
	    triel [q ]= p ;
	    else trier [q ]= p ;
	    triec [p ]= c ;
	    trieo [p ]= mintrieop ;
	  } 
	  else triec [p ]= c ;
	  trieo [p ]= eqtb [27651 + c ].hh .v.RH ;
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
      else printnl ( 263 ) ;
      print ( 1050 ) ;
    } 
    printesc ( 1051 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 1052 ;
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
  opstart [0 ]= - (integer) mintrieop ;
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
  {register integer for_end; p = 0 ;for_end = 255 ; if ( p <= for_end) do 
    triemin [p ]= p + 1 ;
  while ( p++ < for_end ) ;} 
  trietrl [0 ]= 1 ;
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
  if ( triemax == 0 ) 
  {
    {register integer for_end; r = 0 ;for_end = 256 ; if ( r <= for_end) do 
      {
	trietrl [r ]= 0 ;
	trietro [r ]= mintrieop ;
	trietrc [r ]= 0 ;
      } 
    while ( r++ < for_end ) ;} 
    triemax = 256 ;
  } 
  else {
      
    if ( trier [0 ]> 0 ) 
    triefix ( trier [0 ]) ;
    if ( triel [0 ]> 0 ) 
    triefix ( triel [0 ]) ;
    r = 0 ;
    do {
	s = trietrl [r ];
      {
	trietrl [r ]= 0 ;
	trietro [r ]= mintrieop ;
	trietrc [r ]= 0 ;
      } 
      r = s ;
    } while ( ! ( r > triemax ) ) ;
  } 
  trietrc [0 ]= 63 ;
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
  internalfontnumber f, postf  ;
  halfword postp  ;
  ASCIIcode cc  ;
  boolean firstuse  ;
  smallnumber j  ;
  unsigned char c  ;
  packbeginline = curlist .mlfield ;
  firstuse = true ;
  chain = false ;
  deleteglueref ( curkanjiskip ) ;
  deleteglueref ( curxkanjiskip ) ;
  curkanjiskip = mem [curlist .headfield + 7 ].hh .v.RH ;
  curxkanjiskip = mem [curlist .headfield + 7 ].hh .v.LH ;
  incr ( mem [curkanjiskip ].hh .v.RH ) ;
  incr ( mem [curxkanjiskip ].hh .v.RH ) ;
  mem [memtop - 3 ].hh .v.RH = mem [curlist .headfield ].hh .v.RH ;
  if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield ]
  .hh.b0 == 5 ) ) 
  {
    freenode ( curlist .tailfield , 2 ) ;
    curlist .tailfield = curlist .pnodefield ;
    mem [curlist .tailfield ].hh .v.RH = -268435455L ;
  } 
  if ( ( curlist .tailfield >= himemmin ) ) 
  {
    mem [curlist .tailfield ].hh .v.RH = newpenalty ( 10000 ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  else if ( mem [curlist .tailfield ].hh.b0 != 12 ) 
  {
    mem [curlist .tailfield ].hh .v.RH = newpenalty ( 10000 ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  else {
      
    mem [curlist .tailfield ].hh.b0 = 14 ;
    deleteglueref ( mem [curlist .tailfield + 1 ].hh .v.LH ) ;
    flushnodelist ( mem [curlist .tailfield + 1 ].hh .v.RH ) ;
    mem [curlist .tailfield + 1 ].cint = 10000 ;
  } 
  mem [curlist .tailfield ].hh .v.RH = newparamglue ( 14 ) ;
  lastlinefill = mem [curlist .tailfield ].hh .v.RH ;
  initcurlang = curlist .pgfield % 65536L ;
  initlhyf = curlist .pgfield / 4194304L ;
  initrhyf = ( curlist .pgfield / 65536L ) % 64 ;
  popnest () ;
  noshrinkerroryet = true ;
  if ( ( mem [eqtb [24535 ].hh .v.RH ].hh.b1 != 0 ) && ( mem [eqtb [
  24535 ].hh .v.RH + 3 ].cint != 0 ) ) 
  {
    eqtb [24535 ].hh .v.RH = finiteshrink ( eqtb [24535 ].hh .v.RH ) ;
  } 
  if ( ( mem [eqtb [24536 ].hh .v.RH ].hh.b1 != 0 ) && ( mem [eqtb [
  24536 ].hh .v.RH + 3 ].cint != 0 ) ) 
  {
    eqtb [24536 ].hh .v.RH = finiteshrink ( eqtb [24536 ].hh .v.RH ) ;
  } 
  q = eqtb [24535 ].hh .v.RH ;
  r = eqtb [24536 ].hh .v.RH ;
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
  if ( eqtb [29001 ].cint > 0 ) 
  {
    q = mem [lastlinefill + 1 ].hh .v.LH ;
    if ( ( mem [q + 2 ].cint > 0 ) && ( mem [q ].hh.b0 > 0 ) ) {
	
      if ( ( background [3 ]== 0 ) && ( background [4 ]== 0 ) && ( 
      background [5 ]== 0 ) && ( background [6 ]== 0 ) ) 
      {
	dolastlinefit = true ;
	activenodesize = 5 ;
	fillwidth [0 ]= 0 ;
	fillwidth [1 ]= 0 ;
	fillwidth [2 ]= 0 ;
	fillwidth [3 ]= 0 ;
	fillwidth [mem [q ].hh.b0 - 1 ]= mem [q + 2 ].cint ;
      } 
    } 
  } 
  minimumdemerits = 1073741823L ;
  minimaldemerits [3 ]= 1073741823L ;
  minimaldemerits [2 ]= 1073741823L ;
  minimaldemerits [1 ]= 1073741823L ;
  minimaldemerits [0 ]= 1073741823L ;
  if ( eqtb [25061 ].hh .v.RH == -268435455L ) {
      
    if ( eqtb [29534 ].cint == 0 ) 
    {
      lastspecialline = 0 ;
      secondwidth = eqtb [29520 ].cint ;
      secondindent = 0 ;
    } 
    else {
	
      lastspecialline = abs ( eqtb [28972 ].cint ) ;
      if ( eqtb [28972 ].cint < 0 ) 
      {
	firstwidth = eqtb [29520 ].cint - abs ( eqtb [29534 ].cint ) ;
	if ( eqtb [29534 ].cint >= 0 ) 
	firstindent = eqtb [29534 ].cint ;
	else firstindent = 0 ;
	secondwidth = eqtb [29520 ].cint ;
	secondindent = 0 ;
      } 
      else {
	  
	firstwidth = eqtb [29520 ].cint ;
	firstindent = 0 ;
	secondwidth = eqtb [29520 ].cint - abs ( eqtb [29534 ].cint ) ;
	if ( eqtb [29534 ].cint >= 0 ) 
	secondindent = eqtb [29534 ].cint ;
	else secondindent = 0 ;
      } 
    } 
  } 
  else {
      
    lastspecialline = mem [eqtb [25061 ].hh .v.RH ].hh .v.LH - 1 ;
    secondwidth = mem [eqtb [25061 ].hh .v.RH + 2 * ( lastspecialline + 1 ) 
    ].cint ;
    secondindent = mem [eqtb [25061 ].hh .v.RH + 2 * lastspecialline + 1 ]
    .cint ;
  } 
  if ( eqtb [28950 ].cint == 0 ) 
  easyline = lastspecialline ;
  else easyline = 268435455L ;
  threshold = eqtb [28931 ].cint ;
  if ( threshold >= 0 ) 
  {
	;
#ifdef STAT
    if ( eqtb [28963 ].cint > 0 ) 
    {
      begindiagnostic () ;
      printnl ( 1031 ) ;
    } 
#endif /* STAT */
    secondpass = false ;
    finalpass = false ;
  } 
  else {
      
    threshold = eqtb [28932 ].cint ;
    secondpass = true ;
    finalpass = ( eqtb [29537 ].cint <= 0 ) ;
	;
#ifdef STAT
    if ( eqtb [28963 ].cint > 0 ) 
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
      if ( trietrc [hyphstart + curlang ]!= curlang ) 
      hyphindex = 0 ;
      else hyphindex = trietrl [hyphstart + curlang ];
    } 
    q = getnode ( activenodesize ) ;
    mem [q ].hh.b0 = 0 ;
    mem [q ].hh.b1 = 2 ;
    mem [q ].hh .v.RH = memtop - 7 ;
    mem [q + 1 ].hh .v.RH = -268435455L ;
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
    passive = -268435455L ;
    printednode = memtop - 3 ;
    passnumber = 0 ;
    fontinshortdisplay = 0 ;
    curp = mem [memtop - 3 ].hh .v.RH ;
    autobreaking = true ;
    prevp = curp ;
    while ( ( curp != -268435455L ) && ( mem [memtop - 7 ].hh .v.RH != 
    memtop - 7 ) ) {
	
      if ( ( curp >= himemmin ) ) 
      {
	chain = false ;
	if ( ( curp >= himemmin ) ) {
	    
	  if ( fontdir [mem [curp ].hh.b0 ]!= 0 ) 
	  {
	    switch ( mem [prevp ].hh.b0 ) 
	    {case 0 : 
	    case 1 : 
	    case 2 : 
	    case 3 : 
	    case 8 : 
	    case 9 : 
	    case 11 : 
	      {
		curp = prevp ;
		trybreak ( 0 , 0 ) ;
		curp = mem [curp ].hh .v.RH ;
	      } 
	      break ;
	      default: 
	      ;
	      break ;
	    } 
	  } 
	} 
	prevp = curp ;
	postp = curp ;
	postf = mem [postp ].hh.b0 ;
	do {
	    f = postf ;
	  cc = mem [curp ].hh.b1 ;
	  activewidth [1 ]= activewidth [1 ]+ fontinfo [widthbase [f ]+ 
	  fontinfo [charbase [f ]+ cc ].qqqq .b0 ].cint ;
	  postp = mem [curp ].hh .v.RH ;
	  if ( fontdir [f ]!= 0 ) 
	  {
	    prevp = curp ;
	    curp = postp ;
	    postp = mem [postp ].hh .v.RH ;
	    if ( ( postp >= himemmin ) ) 
	    {
	      postf = mem [postp ].hh.b0 ;
	      if ( fontdir [postf ]!= 0 ) 
	      chain = true ;
	      else chain = false ;
	      trybreak ( 0 , 0 ) ;
	    } 
	    else {
		
	      chain = false ;
	      switch ( mem [postp ].hh.b0 ) 
	      {case 0 : 
	      case 1 : 
	      case 2 : 
	      case 3 : 
	      case 8 : 
	      case 9 : 
	      case 11 : 
		trybreak ( 0 , 0 ) ;
		break ;
		default: 
		;
		break ;
	      } 
	    } 
	    if ( chain ) 
	    {
	      if ( firstuse ) 
	      {
		if ( ( mem [curkanjiskip ].hh.b1 != 0 ) && ( mem [
		curkanjiskip + 3 ].cint != 0 ) ) 
		{
		  curkanjiskip = finiteshrink ( curkanjiskip ) ;
		} 
		firstuse = false ;
	      } 
	      activewidth [1 ]= activewidth [1 ]+ mem [curkanjiskip + 1 ]
	      .cint ;
	      activewidth [2 + mem [curkanjiskip ].hh.b0 ]= activewidth [
	      2 + mem [curkanjiskip ].hh.b0 ]+ mem [curkanjiskip + 2 ]
	      .cint ;
	      activewidth [7 ]= activewidth [7 ]+ mem [curkanjiskip + 3 ]
	      .cint ;
	    } 
	    prevp = curp ;
	  } 
	  else if ( ( postp >= himemmin ) ) 
	  {
	    postf = mem [postp ].hh.b0 ;
	    chain = false ;
	    if ( fontdir [postf ]!= 0 ) 
	    trybreak ( 0 , 0 ) ;
	  } 
	  curp = postp ;
	} while ( ! ( ! ( curp >= himemmin ) ) ) ;
	chain = false ;
      } 
      switch ( mem [curp ].hh.b0 ) 
      {case 0 : 
      case 1 : 
      case 2 : 
      case 3 : 
	activewidth [1 ]= activewidth [1 ]+ mem [curp + 1 ].cint ;
	break ;
      case 10 : 
	if ( mem [curp ].hh.b1 == 4 ) 
	{
	  curlang = mem [curp + 1 ].hh .v.RH ;
	  lhyf = mem [curp + 1 ].hh.b0 ;
	  rhyf = mem [curp + 1 ].hh.b1 ;
	  if ( trietrc [hyphstart + curlang ]!= curlang ) 
	  hyphindex = 0 ;
	  else hyphindex = trietrl [hyphstart + curlang ];
	} 
	break ;
      case 12 : 
	{
	  if ( autobreaking ) 
	  {
	    if ( ( prevp >= himemmin ) ) 
	    trybreak ( 0 , 0 ) ;
	    else if ( ( mem [prevp ].hh.b0 < 11 ) ) 
	    trybreak ( 0 , 0 ) ;
	    else if ( mem [prevp ].hh.b0 == 13 ) {
		
	      if ( ( mem [prevp ].hh.b1 != 1 ) && ( mem [prevp ].hh.b1 != 
	      3 ) ) 
	      trybreak ( 0 , 0 ) ;
	    } 
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
	    if ( s != -268435455L ) 
	    {
	      while ( true ) {
		  
		if ( ( s >= himemmin ) ) 
		{
		  hf = mem [s ].hh.b0 ;
		  if ( fontdir [hf ]!= 0 ) 
		  {
		    prevs = s ;
		    s = mem [prevs ].hh .v.RH ;
		    c = mem [s ].hh .v.LH ;
		    goto lab22 ;
		  } 
		  else c = mem [s ].hh.b1 ;
		} 
		else if ( mem [s ].hh.b0 == 5 ) 
		goto lab22 ;
		else if ( ( mem [s ].hh.b0 == 14 ) && ( ! mem [s ].hh.b1 
		== 0 ) ) 
		goto lab22 ;
		else if ( mem [s ].hh.b0 == 8 ) {
		    
		  if ( mem [s + 1 ].hh .v.RH == -268435455L ) 
		  goto lab22 ;
		  else {
		      
		    q = mem [s + 1 ].hh .v.RH ;
		    c = mem [q ].hh.b1 ;
		    hf = mem [q ].hh.b0 ;
		  } 
		} 
		else if ( ( mem [s ].hh.b0 == 13 ) && ( mem [s ].hh.b1 == 
		0 ) ) 
		goto lab22 ;
		else if ( ( mem [s ].hh.b0 == 11 ) && ( mem [s ].hh.b1 >= 
		4 ) ) 
		goto lab22 ;
		else if ( mem [s ].hh.b0 == 10 ) 
		{
		  if ( mem [s ].hh.b1 == 4 ) 
		  {
		    curlang = mem [s + 1 ].hh .v.RH ;
		    lhyf = mem [s + 1 ].hh.b0 ;
		    rhyf = mem [s + 1 ].hh.b1 ;
		    if ( trietrc [hyphstart + curlang ]!= curlang ) 
		    hyphindex = 0 ;
		    else hyphindex = trietrl [hyphstart + curlang ];
		  } 
		  goto lab22 ;
		} 
		else goto lab31 ;
		if ( hyphindex == 0 ) 
		hc [0 ]= eqtb [27651 + c ].hh .v.RH ;
		else if ( trietrc [hyphindex + c ]!= c ) 
		hc [0 ]= 0 ;
		else hc [0 ]= trietro [hyphindex + c ];
		if ( hc [0 ]!= 0 ) {
		    
		  if ( ( hc [0 ]== c ) || ( eqtb [28969 ].cint > 0 ) ) 
		  goto lab32 ;
		  else goto lab31 ;
		} 
		lab22: prevs = s ;
		s = mem [prevs ].hh .v.RH ;
	      } 
	      lab32: hyfchar = hyphenchar [hf ];
	      if ( hyfchar < 0 ) 
	      goto lab31 ;
	      if ( hyfchar > 255 ) 
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
		  hc [0 ]= eqtb [27651 + c ].hh .v.RH ;
		  else if ( trietrc [hyphindex + c ]!= c ) 
		  hc [0 ]= 0 ;
		  else hc [0 ]= trietro [hyphindex + c ];
		  if ( hc [0 ]== 0 ) 
		  goto lab33 ;
		  if ( hn == 63 ) 
		  goto lab33 ;
		  hb = s ;
		  incr ( hn ) ;
		  hu [hn ]= c ;
		  hc [hn ]= hc [0 ];
		  hyfbchar = 256 ;
		} 
		else if ( mem [s ].hh.b0 == 8 ) 
		{
		  if ( mem [s + 1 ].hh.b0 != hf ) 
		  goto lab33 ;
		  j = hn ;
		  q = mem [s + 1 ].hh .v.RH ;
		  if ( q > -268435455L ) 
		  hyfbchar = mem [q ].hh.b1 ;
		  while ( q > -268435455L ) {
		      
		    c = mem [q ].hh.b1 ;
		    if ( hyphindex == 0 ) 
		    hc [0 ]= eqtb [27651 + c ].hh .v.RH ;
		    else if ( trietrc [hyphindex + c ]!= c ) 
		    hc [0 ]= 0 ;
		    else hc [0 ]= trietro [hyphindex + c ];
		    if ( hc [0 ]== 0 ) 
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
		  hyfbchar = fontbchar [hf ];
		  else hyfbchar = 256 ;
		} 
		else if ( ( mem [s ].hh.b0 == 13 ) && ( mem [s ].hh.b1 == 
		0 ) ) 
		{
		  hb = s ;
		  hyfbchar = fontbchar [hf ];
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
		{case 8 : 
		  ;
		  break ;
		case 13 : 
		  if ( mem [s ].hh.b1 != 0 ) 
		  goto lab34 ;
		  break ;
		case 5 : 
		  ;
		  break ;
		case 10 : 
		case 12 : 
		case 14 : 
		case 4 : 
		case 7 : 
		case 6 : 
		  goto lab34 ;
		  break ;
		case 11 : 
		  if ( mem [s ].hh.b1 >= 4 ) 
		  goto lab34 ;
		  else goto lab31 ;
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
      case 13 : 
	if ( ( mem [curp ].hh.b1 == 1 ) || ( mem [curp ].hh.b1 == 3 ) ) 
	{
	  if ( ! ( mem [curp ].hh .v.RH >= himemmin ) && autobreaking ) {
	      
	    if ( mem [mem [curp ].hh .v.RH ].hh.b0 == 12 ) 
	    trybreak ( 0 , 0 ) ;
	  } 
	  activewidth [1 ]= activewidth [1 ]+ mem [curp + 1 ].cint ;
	} 
	else activewidth [1 ]= activewidth [1 ]+ mem [curp + 1 ].cint ;
	break ;
      case 8 : 
	{
	  f = mem [curp + 1 ].hh.b0 ;
	  activewidth [1 ]= activewidth [1 ]+ fontinfo [widthbase [f ]+ 
	  fontinfo [charbase [f ]+ effectivechar ( true , f , mem [curp + 
	  1 ].hh.b1 ) ].qqqq .b0 ].cint ;
	} 
	break ;
      case 9 : 
	{
	  s = mem [curp + 1 ].hh .v.LH ;
	  discwidth = 0 ;
	  if ( s == -268435455L ) 
	  trybreak ( eqtb [28935 ].cint , 1 ) ;
	  else {
	      
	    do {
		if ( ( s >= himemmin ) ) 
	      {
		f = mem [s ].hh.b0 ;
		discwidth = discwidth + fontinfo [widthbase [f ]+ fontinfo 
		[charbase [f ]+ mem [s ].hh.b1 ].qqqq .b0 ].cint ;
		if ( fontdir [f ]!= 0 ) 
		s = mem [s ].hh .v.RH ;
	      } 
	      else switch ( mem [s ].hh.b0 ) 
	      {case 8 : 
		{
		  f = mem [s + 1 ].hh.b0 ;
		  discwidth = discwidth + fontinfo [widthbase [f ]+ 
		  fontinfo [charbase [f ]+ mem [s + 1 ].hh.b1 ].qqqq .b0 
		  ].cint ;
		} 
		break ;
	      case 0 : 
	      case 1 : 
	      case 2 : 
	      case 3 : 
	      case 13 : 
		discwidth = discwidth + mem [s + 1 ].cint ;
		break ;
	      case 5 : 
		;
		break ;
		default: 
		confusion ( 1035 ) ;
		break ;
	      } 
	      s = mem [s ].hh .v.RH ;
	    } while ( ! ( s == -268435455L ) ) ;
	    activewidth [1 ]= activewidth [1 ]+ discwidth ;
	    trybreak ( eqtb [28934 ].cint , 1 ) ;
	    activewidth [1 ]= activewidth [1 ]- discwidth ;
	  } 
	  r = mem [curp ].hh.b1 ;
	  s = mem [curp ].hh .v.RH ;
	  while ( r > 0 ) {
	      
	    if ( ( s >= himemmin ) ) 
	    {
	      f = mem [s ].hh.b0 ;
	      activewidth [1 ]= activewidth [1 ]+ fontinfo [widthbase [f 
	      ]+ fontinfo [charbase [f ]+ mem [s ].hh.b1 ].qqqq .b0 ]
	      .cint ;
	      if ( fontdir [f ]!= 0 ) 
	      s = mem [s ].hh .v.RH ;
	    } 
	    else switch ( mem [s ].hh.b0 ) 
	    {case 8 : 
	      {
		f = mem [s + 1 ].hh.b0 ;
		activewidth [1 ]= activewidth [1 ]+ fontinfo [widthbase [
		f ]+ fontinfo [charbase [f ]+ mem [s + 1 ].hh.b1 ].qqqq 
		.b0 ].cint ;
	      } 
	      break ;
	    case 0 : 
	    case 1 : 
	    case 2 : 
	    case 3 : 
	    case 13 : 
	      activewidth [1 ]= activewidth [1 ]+ mem [s + 1 ].cint ;
	      break ;
	    case 5 : 
	      ;
	      break ;
	      default: 
	      confusion ( 1036 ) ;
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
      case 11 : 
	{
	  if ( mem [curp ].hh.b1 < 4 ) 
	  autobreaking = odd ( mem [curp ].hh.b1 ) ;
	  {
	    if ( ! ( mem [curp ].hh .v.RH >= himemmin ) && autobreaking ) {
		
	      if ( mem [mem [curp ].hh .v.RH ].hh.b0 == 12 ) 
	      trybreak ( 0 , 0 ) ;
	    } 
	    activewidth [1 ]= activewidth [1 ]+ mem [curp + 1 ].cint ;
	  } 
	} 
	break ;
      case 14 : 
	trybreak ( mem [curp + 1 ].cint , 0 ) ;
	break ;
      case 5 : 
      case 6 : 
      case 4 : 
      case 7 : 
	;
	break ;
	default: 
	confusion ( 1034 ) ;
	break ;
      } 
      prevp = curp ;
      curp = mem [curp ].hh .v.RH ;
      lab35: ;
    } 
    if ( curp == -268435455L ) 
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
	if ( eqtb [28950 ].cint == 0 ) 
	goto lab30 ;
	{
	  r = mem [memtop - 7 ].hh .v.RH ;
	  actuallooseness = 0 ;
	  do {
	      if ( mem [r ].hh.b0 != 2 ) 
	    {
	      linediff = mem [r + 1 ].hh .v.LH - bestline ;
	      if ( ( ( linediff < actuallooseness ) && ( eqtb [28950 ].cint 
	      <= linediff ) ) || ( ( linediff > actuallooseness ) && ( eqtb [
	      28950 ].cint >= linediff ) ) ) 
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
	if ( ( actuallooseness == eqtb [28950 ].cint ) || finalpass ) 
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
    while ( q != -268435455L ) {
	
      curp = mem [q ].hh .v.RH ;
      freenode ( q , 2 ) ;
      q = curp ;
    } 
    if ( ! secondpass ) 
    {
	;
#ifdef STAT
      if ( eqtb [28963 ].cint > 0 ) 
      printnl ( 1032 ) ;
#endif /* STAT */
      threshold = eqtb [28932 ].cint ;
      secondpass = true ;
      finalpass = ( eqtb [29537 ].cint <= 0 ) ;
    } 
    else {
	
	;
#ifdef STAT
      if ( eqtb [28963 ].cint > 0 ) 
      printnl ( 1033 ) ;
#endif /* STAT */
      background [2 ]= background [2 ]+ eqtb [29537 ].cint ;
      finalpass = true ;
    } 
  } 
  lab30: 
	;
#ifdef STAT
  if ( eqtb [28963 ].cint > 0 ) 
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
  while ( q != -268435455L ) {
      
    curp = mem [q ].hh .v.RH ;
    freenode ( q , 2 ) ;
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
  if ( eqtb [28982 ].cint <= 0 ) 
  curlang = 0 ;
  else if ( eqtb [28982 ].cint > 255 ) 
  curlang = 0 ;
  else curlang = eqtb [28982 ].cint ;
	;
#ifdef INITEX
  if ( trienotready ) 
  {
    hyphindex = 0 ;
    goto lab46 ;
  } 
#endif /* INITEX */
  if ( trietrc [hyphstart + curlang ]!= curlang ) 
  hyphindex = 0 ;
  else hyphindex = trietrl [hyphstart + curlang ];
  lab46: n = 0 ;
  p = -268435455L ;
  while ( true ) {
      
    getxtoken () ;
    lab21: switch ( curcmd ) 
    {case 11 : 
    case 12 : 
    case 71 : 
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
	hc [0 ]= eqtb [27651 + curchr ].hh .v.RH ;
	else if ( trietrc [hyphindex + curchr ]!= curchr ) 
	hc [0 ]= 0 ;
	else hc [0 ]= trietro [hyphindex + curchr ];
	if ( hc [0 ]== 0 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 263 ) ;
	    print ( 1043 ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 1044 ;
	    helpline [0 ]= 1045 ;
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
    case 19 : 
      {
	scancharnum () ;
	curchr = curval ;
	curcmd = 71 ;
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
	    overflow ( 258 , poolsize - initpoolptr ) ;
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
	  overflow ( 1046 , hyphsize ) ;
	  incr ( hyphcount ) ;
	  while ( hyphword [h ]!= 0 ) {
	      
	    k = hyphword [h ];
	    if ( ( strstart [k + 1 ]- strstart [k ]) != ( strstart [s + 1 
	    ]- strstart [s ]) ) 
	    goto lab45 ;
	    u = strstart [k ];
	    v = strstart [s ];
	    do {
		if ( strpool [u ]!= strpool [v ]) 
	      goto lab45 ;
	      incr ( u ) ;
	      incr ( v ) ;
	    } while ( ! ( u == strstart [k + 1 ]) ) ;
	    {
	      decr ( strptr ) ;
	      poolptr = strstart [strptr ];
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
	p = -268435455L ;
      } 
      break ;
      default: 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 744 ) ;
	} 
	printesc ( 1039 ) ;
	print ( 1040 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1041 ;
	  helpline [0 ]= 1042 ;
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
  if ( l < 5 ) 
  {
    {register integer for_end; i = 0 ;for_end = 15 ; if ( i <= for_end) do 
      {
	if ( odd ( i ) ) 
	curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
	else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
	if ( curptr != -268435455L ) {
	    
	  if ( domarks ( a , l + 1 , curptr ) ) 
	  {
	    if ( odd ( i ) ) 
	    mem [q + ( i / 2 ) + 1 ].hh .v.RH = -268435455L ;
	    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = -268435455L ;
	    decr ( mem [q ].hh.b1 ) ;
	  } 
	} 
      } 
    while ( i++ < for_end ) ;} 
    if ( mem [q ].hh.b1 == 0 ) 
    {
      freenode ( q , 9 ) ;
      q = -268435455L ;
    } 
  } 
  else {
      
    switch ( a ) 
    {case 0 : 
      if ( mem [q + 2 ].hh .v.RH != -268435455L ) 
      {
	deletetokenref ( mem [q + 2 ].hh .v.RH ) ;
	mem [q + 2 ].hh .v.RH = -268435455L ;
	deletetokenref ( mem [q + 3 ].hh .v.LH ) ;
	mem [q + 3 ].hh .v.LH = -268435455L ;
      } 
      break ;
    case 1 : 
      if ( mem [q + 2 ].hh .v.LH != -268435455L ) 
      {
	if ( mem [q + 1 ].hh .v.LH != -268435455L ) 
	deletetokenref ( mem [q + 1 ].hh .v.LH ) ;
	deletetokenref ( mem [q + 1 ].hh .v.RH ) ;
	mem [q + 1 ].hh .v.RH = -268435455L ;
	if ( mem [mem [q + 2 ].hh .v.LH ].hh .v.RH == -268435455L ) 
	{
	  deletetokenref ( mem [q + 2 ].hh .v.LH ) ;
	  mem [q + 2 ].hh .v.LH = -268435455L ;
	} 
	else incr ( mem [mem [q + 2 ].hh .v.LH ].hh .v.LH ) ;
	mem [q + 1 ].hh .v.LH = mem [q + 2 ].hh .v.LH ;
      } 
      break ;
    case 2 : 
      if ( ( mem [q + 1 ].hh .v.LH != -268435455L ) && ( mem [q + 1 ].hh 
      .v.RH == -268435455L ) ) 
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
	  if ( curptr != -268435455L ) 
	  {
	    deletetokenref ( curptr ) ;
	    if ( odd ( i ) ) 
	    mem [q + ( i / 2 ) + 1 ].hh .v.RH = -268435455L ;
	    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = -268435455L ;
	  } 
	} 
      while ( i++ < for_end ) ;} 
      break ;
#endif /* INITEX */
    } 
    if ( mem [q + 2 ].hh .v.LH == -268435455L ) {
	
      if ( mem [q + 3 ].hh .v.LH == -268435455L ) 
      {
	freenode ( q , 4 ) ;
	q = -268435455L ;
      } 
    } 
  } 
  Result = ( q == -268435455L ) ;
  return Result ;
} 
void 
prefixedcommand ( void ) 
{
  /* 30 10 */ prefixedcommand_regmem 
  smallnumber a  ;
  integer m  ;
  internalfontnumber f  ;
  halfword j  ;
  fontindex k  ;
  halfword p, q  ;
  integer n  ;
  boolean e  ;
  a = 0 ;
  while ( curcmd == 104 ) {
      
    if ( ! odd ( a / curchr ) ) 
    a = a + curchr ;
    do {
	getxtoken () ;
    } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
    if ( curcmd <= 76 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 263 ) ;
	print ( 1304 ) ;
      } 
      printcmdchr ( curcmd , curchr ) ;
      printchar ( 39 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 1305 ;
      } 
      if ( ( eTeXmode == 1 ) ) 
      helpline [0 ]= 1306 ;
      backerror () ;
      return ;
    } 
    if ( eqtb [28967 ].cint > 2 ) {
	
      if ( ( eTeXmode == 1 ) ) 
      showcurcmdchr () ;
    } 
  } 
  if ( a >= 8 ) 
  {
    j = 3585 ;
    a = a - 8 ;
  } 
  else j = 0 ;
  if ( ( curcmd != 108 ) && ( ( a % 4 != 0 ) || ( j != 0 ) ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 263 ) ;
      print ( 749 ) ;
    } 
    printesc ( 1296 ) ;
    print ( 1307 ) ;
    printesc ( 1297 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 1308 ;
    } 
    if ( ( eTeXmode == 1 ) ) 
    {
      helpline [0 ]= 1309 ;
      print ( 1307 ) ;
      printesc ( 1310 ) ;
    } 
    print ( 1311 ) ;
    printcmdchr ( curcmd , curchr ) ;
    printchar ( 39 ) ;
    error () ;
  } 
  if ( eqtb [28974 ].cint != 0 ) {
      
    if ( eqtb [28974 ].cint < 0 ) 
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
  {case 96 : 
    {
      if ( fontdir [curchr ]== 4 ) {
	  
	if ( ( a >= 4 ) ) 
	geqdefine ( 26357 , 132 , curchr ) ;
	else eqdefine ( 26357 , 132 , curchr ) ;
      } 
      else if ( fontdir [curchr ]== 3 ) {
	  
	if ( ( a >= 4 ) ) 
	geqdefine ( 26358 , 132 , curchr ) ;
	else eqdefine ( 26358 , 132 , curchr ) ;
      } 
      else if ( ( a >= 4 ) ) 
      geqdefine ( 25588 , 132 , curchr ) ;
      else eqdefine ( 25588 , 132 , curchr ) ;
    } 
    break ;
  case 108 : 
    {
      if ( odd ( curchr ) && ! ( a >= 4 ) && ( eqtb [28974 ].cint >= 0 ) ) 
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
      geqdefine ( p , 123 + ( a % 4 ) , defref ) ;
      else eqdefine ( p , 123 + ( a % 4 ) , defref ) ;
    } 
    break ;
  case 105 : 
    {
      n = curchr ;
      getrtoken () ;
      p = curcs ;
      if ( n == 0 ) 
      {
	do {
	    gettoken () ;
	} while ( ! ( curcmd != 10 ) ) ;
	if ( curtok == 3133 ) 
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
      if ( curcmd >= 123 ) 
      incr ( mem [curchr ].hh .v.LH ) ;
      else if ( ( curcmd == 100 ) || ( curcmd == 77 ) ) {
	  
	if ( ( curchr < membot ) || ( curchr > membot + 23 ) ) 
	incr ( mem [curchr + 1 ].hh .v.LH ) ;
      } 
      if ( ( a >= 4 ) ) 
      geqdefine ( p , curcmd , curchr ) ;
      else eqdefine ( p , curcmd , curchr ) ;
    } 
    break ;
  case 106 : 
    if ( curchr == 8 ) 
    {
      scancharnum () ;
      p = 28675 + curval ;
      scanoptionalequals () ;
      scancharnum () ;
      n = curval ;
      scancharnum () ;
      if ( ( eqtb [28993 ].cint > 0 ) ) 
      {
	begindiagnostic () ;
	printnl ( 1330 ) ;
	print ( p - 28675 ) ;
	print ( 1331 ) ;
	print ( n ) ;
	printchar ( 32 ) ;
	print ( curval ) ;
	enddiagnostic ( false ) ;
      } 
      n = n * 256 + curval ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 132 , n ) ;
      else eqdefine ( p , 132 , n ) ;
      if ( ( p - 28675 ) < eqtb [28991 ].cint ) {
	  
	if ( ( a >= 4 ) ) 
	geqworddefine ( 28991 , p - 28675 ) ;
	else eqworddefine ( 28991 , p - 28675 ) ;
      } 
      if ( ( p - 28675 ) > eqtb [28992 ].cint ) {
	  
	if ( ( a >= 4 ) ) 
	geqworddefine ( 28992 , p - 28675 ) ;
	else eqworddefine ( 28992 , p - 28675 ) ;
      } 
    } 
    else {
	
      n = curchr ;
      getrtoken () ;
      p = curcs ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 0 , 256 ) ;
      else eqdefine ( p , 0 , 256 ) ;
      scanoptionalequals () ;
      switch ( n ) 
      {case 0 : 
	{
	  scancharnum () ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 71 , curval ) ;
	  else eqdefine ( p , 71 , curval ) ;
	} 
	break ;
      case 1 : 
	{
	  scanrealfifteenbitint () ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 72 , curval ) ;
	  else eqdefine ( p , 72 , curval ) ;
	} 
	break ;
      case 2 : 
	{
	  scanomegafifteenbitint () ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 73 , curval ) ;
	  else eqdefine ( p , 73 , curval ) ;
	} 
	break ;
	default: 
	{
	  scanregisternum () ;
	  if ( curval > 255 ) 
	  {
	    j = n - 3 ;
	    if ( j > 3 ) 
	    j = 5 ;
	    findsaelement ( j , curval , true ) ;
	    incr ( mem [curptr + 1 ].hh .v.LH ) ;
	    if ( j == 5 ) 
	    j = 77 ;
	    else j = 100 ;
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , j , curptr ) ;
	    else eqdefine ( p , j , curptr ) ;
	  } 
	  else switch ( n ) 
	  {case 3 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 79 , 29005 + curval ) ;
	    else eqdefine ( p , 79 , 29005 + curval ) ;
	    break ;
	  case 4 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 80 , 29542 + curval ) ;
	    else eqdefine ( p , 80 , 29542 + curval ) ;
	    break ;
	  case 5 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 81 , 24549 + curval ) ;
	    else eqdefine ( p , 81 , 24549 + curval ) ;
	    break ;
	  case 6 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 82 , 24805 + curval ) ;
	    else eqdefine ( p , 82 , 24805 + curval ) ;
	    break ;
	  case 7 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 78 , 25072 + curval ) ;
	    else eqdefine ( p , 78 , 25072 + curval ) ;
	    break ;
	  } 
	} 
	break ;
      } 
    } 
    break ;
  case 107 : 
    {
      j = curchr ;
      scanint () ;
      n = curval ;
      if ( ! scankeyword ( 938 ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 1190 ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1332 ;
	  helpline [0 ]= 1333 ;
	} 
	error () ;
      } 
      getrtoken () ;
      p = curcs ;
      readtoks ( n , p , j ) ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 123 , curval ) ;
      else eqdefine ( p , 123 , curval ) ;
    } 
    break ;
  case 77 : 
  case 78 : 
    {
      q = curcs ;
      e = false ;
      if ( curcmd == 77 ) {
	  
	if ( curchr == membot ) 
	{
	  scanregisternum () ;
	  if ( curval > 255 ) 
	  {
	    findsaelement ( 5 , curval , true ) ;
	    curchr = curptr ;
	    e = true ;
	  } 
	  else curchr = 25072 + curval ;
	} 
	else e = true ;
      } 
      p = curchr ;
      scanoptionalequals () ;
      do {
	  getxtoken () ;
      } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
      if ( curcmd != 1 ) {
	  
	if ( ( curcmd == 77 ) || ( curcmd == 78 ) ) 
	{
	  if ( curcmd == 77 ) {
	      
	    if ( curchr == membot ) 
	    {
	      scanregisternum () ;
	      if ( curval < 256 ) 
	      q = eqtb [25072 + curval ].hh .v.RH ;
	      else {
		  
		findsaelement ( 5 , curval , false ) ;
		if ( curptr == -268435455L ) 
		q = -268435455L ;
		else q = mem [curptr + 1 ].hh .v.RH ;
	      } 
	    } 
	    else q = mem [curchr + 1 ].hh .v.RH ;
	  } 
	  else q = eqtb [curchr ].hh .v.RH ;
	  if ( q == -268435455L ) {
	      
	    if ( e ) {
		
	      if ( ( a >= 4 ) ) 
	      gsadef ( p , -268435455L ) ;
	      else sadef ( p , -268435455L ) ;
	    } 
	    else if ( ( a >= 4 ) ) 
	    geqdefine ( p , 113 , -268435455L ) ;
	    else eqdefine ( p , 113 , -268435455L ) ;
	  } 
	  else {
	      
	    incr ( mem [q ].hh .v.LH ) ;
	    if ( e ) {
		
	      if ( ( a >= 4 ) ) 
	      gsadef ( p , q ) ;
	      else sadef ( p , q ) ;
	    } 
	    else if ( ( a >= 4 ) ) 
	    geqdefine ( p , 123 , q ) ;
	    else eqdefine ( p , 123 , q ) ;
	  } 
	  goto lab30 ;
	} 
      } 
      backinput () ;
      curcs = q ;
      q = scantoks ( false , false ) ;
      if ( mem [defref ].hh .v.RH == -268435455L ) 
      {
	if ( e ) {
	    
	  if ( ( a >= 4 ) ) 
	  gsadef ( p , -268435455L ) ;
	  else sadef ( p , -268435455L ) ;
	} 
	else if ( ( a >= 4 ) ) 
	geqdefine ( p , 113 , -268435455L ) ;
	else eqdefine ( p , 113 , -268435455L ) ;
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
	  
	if ( ( p == 25062 ) && ! e ) 
	{
	  mem [q ].hh .v.RH = getavail () ;
	  q = mem [q ].hh .v.RH ;
	  mem [q ].hh .v.LH = 637 ;
	  q = getavail () ;
	  mem [q ].hh .v.LH = 379 ;
	  mem [q ].hh .v.RH = mem [defref ].hh .v.RH ;
	  mem [defref ].hh .v.RH = q ;
	} 
	if ( e ) {
	    
	  if ( ( a >= 4 ) ) 
	  gsadef ( p , defref ) ;
	  else sadef ( p , defref ) ;
	} 
	else if ( ( a >= 4 ) ) 
	geqdefine ( p , 123 , defref ) ;
	else eqdefine ( p , 123 , defref ) ;
      } 
    } 
    break ;
  case 79 : 
    {
      p = curchr ;
      scanoptionalequals () ;
      scanint () ;
      if ( p == 28975 ) 
      {
	if ( fontdir [eqtb [25589 + curval ].hh .v.RH ]!= 0 ) {
	    
	  if ( ( a >= 4 ) ) 
	  geqworddefine ( 28976 , curval ) ;
	  else eqworddefine ( 28976 , curval ) ;
	} 
	else if ( ( a >= 4 ) ) 
	geqworddefine ( p , curval ) ;
	else eqworddefine ( p , curval ) ;
      } 
      else if ( ( a >= 4 ) ) 
      geqworddefine ( p , curval ) ;
      else eqworddefine ( p , curval ) ;
    } 
    break ;
  case 80 : 
    {
      p = curchr ;
      scanoptionalequals () ;
      scandimen ( false , false , false ) ;
      if ( ( a >= 4 ) ) 
      geqworddefine ( p , curval ) ;
      else eqworddefine ( p , curval ) ;
    } 
    break ;
  case 81 : 
  case 82 : 
    {
      p = curchr ;
      n = curcmd ;
      scanoptionalequals () ;
      if ( n == 82 ) 
      scanglue ( 3 ) ;
      else scanglue ( 2 ) ;
      trapzeroglue () ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 129 , curval ) ;
      else eqdefine ( p , 129 , curval ) ;
    } 
    break ;
  case 94 : 
    {
      if ( curchr == ( 29389 ) ) 
      {
	p = curchr - 128 ;
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
	    else printnl ( 263 ) ;
	    print ( 1336 ) ;
	  } 
	  printint ( curval1 ) ;
	  print ( 32 ) ;
	  printint ( curval ) ;
	  print ( 1337 ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1338 ;
	  } 
	  error () ;
	  curval1 = 0 ;
	  curval = 0 ;
	} 
	curval1 = ( curval1 / 65536L ) * 256 + ( curval1 % 256 ) ;
	curval = ( curval / 65536L ) * 256 + ( curval % 256 ) ;
	if ( ( a >= 4 ) ) 
	delgeqworddefine ( p , curval1 , curval ) ;
	else deleqworddefine ( p , curval1 , curval ) ;
      } 
      else {
	  
	if ( curchr == 26617 ) 
	m = 16 ;
	else m = 0 ;
	if ( curchr == 26361 ) 
	n = 15 ;
	else if ( curchr == 26617 ) 
	n = 18 ;
	else if ( curchr == 28419 ) 
	n = 32768L ;
	else if ( curchr == ( 28547 ) ) 
	n = 134217728L ;
	else if ( curchr == 28163 ) 
	n = 32767 ;
	else if ( curchr == 29261 ) 
	n = 16777215L ;
	else n = 255 ;
	p = curchr ;
	curval1 = p ;
	scancharnum () ;
	if ( p == 26617 ) 
	p = p + kcatcodekey ( curval ) ;
	else if ( ! ischarascii ( curval ) ) 
	p = p + Hi ( curval ) ;
	else p = p + curval ;
	scanoptionalequals () ;
	scanint () ;
	if ( ( ( curval < m ) && ( p < 29261 ) ) || ( curval > n ) ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 263 ) ;
	    print ( 1336 ) ;
	  } 
	  printint ( curval ) ;
	  if ( p < 29261 ) 
	  {
	    print ( 1339 ) ;
	    printint ( m ) ;
	    print ( 1340 ) ;
	  } 
	  else print ( 1341 ) ;
	  printint ( n ) ;
	  if ( m == 0 ) 
	  {
	    {
	      helpptr = 1 ;
	      helpline [0 ]= 1338 ;
	    } 
	    error () ;
	  } 
	  else {
	      
	    {
	      helpptr = 1 ;
	      helpline [0 ]= 1342 ;
	    } 
	    error () ;
	  } 
	  curval = m ;
	} 
	if ( p < 28419 ) {
	    
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 132 , curval ) ;
	  else eqdefine ( p , 132 , curval ) ;
	} 
	else if ( curval1 == 28419 ) 
	{
	  if ( curval == 32768L ) 
	  curval = 524288L ;
	  else curval = ( ( curval / 4096 ) * 65536L ) + ( curval % 4096 ) ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 132 , curval ) ;
	  else eqdefine ( p , 132 , curval ) ;
	} 
	else if ( curval1 == 28547 ) 
	{
	  curval = ( ( curval / 65536L ) * 256 ) + ( curval % 256 ) ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p - 128 , 132 , curval ) ;
	  else eqdefine ( p - 128 , 132 , curval ) ;
	} 
	else if ( curval1 == 29261 ) 
	{
	  curval1 = curval / 4096 ;
	  curval1 = ( curval1 / 4096 ) * 65536L + curval1 % 4096 ;
	  curval = curval % 4096 ;
	  if ( ( a >= 4 ) ) 
	  delgeqworddefine ( p , curval1 , curval ) ;
	  else deleqworddefine ( p , curval1 , curval ) ;
	} 
	else if ( ( a >= 4 ) ) 
	geqdefine ( p , 132 , curval ) ;
	else eqdefine ( p , 132 , curval ) ;
      } 
    } 
    break ;
  case 95 : 
    {
      p = curchr ;
      scanbigfourbitint () ;
      p = p + curval ;
      scanoptionalequals () ;
      scanfontident () ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 132 , curval ) ;
      else eqdefine ( p , 132 , curval ) ;
    } 
    break ;
  case 100 : 
  case 101 : 
  case 102 : 
  case 103 : 
    doregistercommand ( a ) ;
    break ;
  case 109 : 
    {
      scanregisternum () ;
      if ( ( a >= 4 ) ) 
      n = 1073807360L + curval ;
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
	  else printnl ( 263 ) ;
	  print ( 744 ) ;
	} 
	printesc ( 584 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1348 ;
	  helpline [0 ]= 1349 ;
	} 
	error () ;
      } 
    } 
    break ;
  case 88 : 
    alteraux () ;
    break ;
  case 89 : 
    alterprevgraf () ;
    break ;
  case 90 : 
    alterpagesofar () ;
    break ;
  case 91 : 
    alterinteger () ;
    break ;
  case 92 : 
    alterboxdimen () ;
    break ;
  case 93 : 
    {
      q = curchr ;
      scanoptionalequals () ;
      scanint () ;
      n = curval ;
      if ( n <= 0 ) 
      p = -268435455L ;
      else if ( q > 25061 ) 
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
      geqdefine ( q , 130 , p ) ;
      else eqdefine ( q , 130 , p ) ;
    } 
    break ;
  case 110 : 
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
	else printnl ( 263 ) ;
	print ( 1353 ) ;
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
  case 83 : 
    {
      findfontdimen ( true ) ;
      k = curval ;
      scanoptionalequals () ;
      scandimen ( false , false , false ) ;
      fontinfo [k ].cint = curval ;
    } 
    break ;
  case 84 : 
    {
      n = curchr ;
      scanfontident () ;
      f = curval ;
      scanoptionalequals () ;
      scanint () ;
      if ( n == 0 ) 
      hyphenchar [f ]= curval ;
      else skewchar [f ]= curval ;
    } 
    break ;
  case 99 : 
  case 98 : 
  case 97 : 
    newfont ( a ) ;
    break ;
  case 111 : 
    newinteraction () ;
    break ;
  case 87 : 
    {
      p = curchr ;
      scanint () ;
      n = curval ;
      scanoptionalequals () ;
      scanint () ;
      if ( ! ischarkanji ( curval ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 1564 ) ;
	} 
	printhex ( curval ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1565 ;
	} 
	error () ;
	return ;
      } 
      else if ( ( n < 0 ) || ( n > 9 ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 1566 ) ;
	} 
	printint ( n ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1565 ;
	} 
	error () ;
	return ;
      } 
      else if ( ( a >= 4 ) ) 
      geqdefine ( 27641 + n , n , toDVI ( curval ) ) ;
      else eqdefine ( 27641 + n , n , toDVI ( curval ) ) ;
    } 
    break ;
  case 112 : 
    {
      if ( curchr < 2 ) 
      p = 26359 ;
      else {
	  
	p = 26360 ;
	curchr = ( curchr % 2 ) ;
      } 
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 132 , curchr ) ;
      else eqdefine ( p , 132 , curchr ) ;
    } 
    break ;
  case 86 : 
    {
      p = curchr ;
      scanint () ;
      n = curval ;
      scanoptionalequals () ;
      scanint () ;
      if ( ischarkanji ( n ) ) 
      {
	j = getinhibitpos ( n , 0 ) ;
	if ( j == 1000 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 263 ) ;
	    print ( 1581 ) ;
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1565 ;
	  } 
	  error () ;
	  return ;
	} 
	if ( ( a >= 4 ) ) 
	geqdefine ( 27129 + j , curval , n ) ;
	else eqdefine ( 27129 + j , curval , n ) ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 1582 ) ;
	} 
	printhex ( n ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1565 ;
	} 
	error () ;
	return ;
      } 
    } 
    break ;
  case 85 : 
    {
      p = curchr ;
      scanint () ;
      n = curval ;
      scanoptionalequals () ;
      scanint () ;
      if ( ischarascii ( n ) || ischarkanji ( n ) ) 
      {
	j = getkinsokupos ( n , 0 ) ;
	if ( j == 1000 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 263 ) ;
	    print ( 1588 ) ;
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1565 ;
	  } 
	  error () ;
	  return ;
	} 
	if ( ( p == 1 ) || ( p == 2 ) ) 
	{
	  if ( ( a >= 4 ) ) 
	  geqdefine ( 27385 + j , p , n ) ;
	  else eqdefine ( 27385 + j , p , n ) ;
	  if ( ( a >= 4 ) ) 
	  geqworddefine ( 29798 + j , curval ) ;
	  else eqworddefine ( 29798 + j , curval ) ;
	} 
	else confusion ( 539 ) ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 1589 ) ;
	} 
	if ( p == 1 ) 
	print ( 1590 ) ;
	else if ( p == 2 ) 
	print ( 1591 ) ;
	else printchar ( 63 ) ;
	print ( 1592 ) ;
	printhex ( n ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1565 ;
	} 
	error () ;
	return ;
      } 
    } 
    break ;
    default: 
    confusion ( 1303 ) ;
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
  integer j, k, l  ;
  halfword p, q  ;
  integer x  ;
  ASCIIcode * formatengine  ;
  if ( saveptr != 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 263 ) ;
      print ( 1394 ) ;
    } 
    {
      helpptr = 1 ;
      helpline [0 ]= 1395 ;
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
  print ( 1411 ) ;
  print ( jobname ) ;
  printchar ( 32 ) ;
  printint ( eqtb [28954 ].cint ) ;
  printchar ( 46 ) ;
  printint ( eqtb [28953 ].cint ) ;
  printchar ( 46 ) ;
  printint ( eqtb [28952 ].cint ) ;
  printchar ( 41 ) ;
  if ( interaction == 0 ) 
  selector = 18 ;
  else selector = 19 ;
  {
    if ( poolptr + 1 > poolsize ) 
    overflow ( 258 , poolsize - initpoolptr ) ;
  } 
  formatident = makestring () ;
  packjobname ( 879 ) ;
  while ( ! wopenout ( fmtfile ) ) promptfilename ( 1412 , 879 ) ;
  printnl ( 1413 ) ;
  slowprint ( wmakenamestring ( fmtfile ) ) ;
  {
    decr ( strptr ) ;
    poolptr = strstart [strptr ];
  } 
  printnl ( 343 ) ;
  slowprint ( formatident ) ;
  dumpint ( 1462916184L ) ;
  x = strlen ( enginename ) ;
  formatengine = xmallocarray ( ASCIIcode , x + 4 ) ;
  strcpy ( stringcast ( formatengine ) , enginename ) ;
  {register integer for_end; k = x ;for_end = x + 3 ; if ( k <= for_end) do 
    formatengine [k ]= 0 ;
  while ( k++ < for_end ) ;} 
  x = x + 4 - ( x % 4 ) ;
  dumpint ( x ) ;
  dumpthings ( formatengine [0 ], x ) ;
  libcfree ( formatengine ) ;
  dumpint ( 147802702L ) ;
  dumpthings ( xord [0 ], 256 ) ;
  dumpthings ( xchr [0 ], 256 ) ;
  dumpthings ( xprn [0 ], 256 ) ;
  dumpint ( 268435455L ) ;
  dumpint ( hashhigh ) ;
  dumpint ( eTeXmode ) ;
  {register integer for_end; j = 0 ;for_end = -0 ; if ( j <= for_end) do 
    eqtb [29004 + j ].cint = 0 ;
  while ( j++ < for_end ) ;} 
  while ( pseudofiles != -268435455L ) pseudoclose () ;
  dumpint ( membot ) ;
  dumpint ( memtop ) ;
  dumpint ( 30053 ) ;
  dumpint ( 8501 ) ;
  dumpint ( 607 ) ;
  dumpint ( 1296847960L ) ;
  if ( mltexp ) 
  dumpint ( 1 ) ;
  else dumpint ( 0 ) ;
  dumpint ( poolptr ) ;
  dumpint ( strptr ) ;
  dumpthings ( strstart [0 ], strptr + 1 ) ;
  dumpthings ( strpool [0 ], poolptr ) ;
  println () ;
  printint ( strptr ) ;
  print ( 1396 ) ;
  printint ( poolptr ) ;
  sortavail () ;
  varused = 0 ;
  dumpint ( lomemmax ) ;
  dumpint ( rover ) ;
  if ( ( eTeXmode == 1 ) ) 
  {register integer for_end; k = 0 ;for_end = 5 ; if ( k <= for_end) do 
    dumpint ( saroot [k ]) ;
  while ( k++ < for_end ) ;} 
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
  while ( p != -268435455L ) {
      
    decr ( dynused ) ;
    p = mem [p ].hh .v.RH ;
  } 
  dumpint ( varused ) ;
  dumpint ( dynused ) ;
  println () ;
  printint ( x ) ;
  print ( 1397 ) ;
  printint ( varused ) ;
  printchar ( 38 ) ;
  printint ( dynused ) ;
  k = 1 ;
  do {
      j = k ;
    while ( j < 28930 ) {
	
      if ( ( eqtb [j ].hh .v.RH == eqtb [j + 1 ].hh .v.RH ) && ( eqtb [j 
      ].hh.b0 == eqtb [j + 1 ].hh.b0 ) && ( eqtb [j ].hh.b1 == eqtb [j + 
      1 ].hh.b1 ) ) 
      goto lab41 ;
      incr ( j ) ;
    } 
    l = 28931 ;
    goto lab31 ;
    lab41: incr ( j ) ;
    l = j ;
    while ( j < 28930 ) {
	
      if ( ( eqtb [j ].hh .v.RH != eqtb [j + 1 ].hh .v.RH ) || ( eqtb [j 
      ].hh.b0 != eqtb [j + 1 ].hh.b0 ) || ( eqtb [j ].hh.b1 != eqtb [j + 
      1 ].hh.b1 ) ) 
      goto lab31 ;
      incr ( j ) ;
    } 
    lab31: dumpint ( l - k ) ;
    dumpthings ( eqtb [k ], l - k ) ;
    k = j + 1 ;
    dumpint ( k - l ) ;
  } while ( ! ( k == 28931 ) ) ;
  do {
      j = k ;
    while ( j < 30053 ) {
	
      if ( ( eqtb [j ].cint == eqtb [j + 1 ].cint ) && ( getintone ( eqtb 
      [j ]) == getintone ( eqtb [j + 1 ]) ) ) 
      goto lab42 ;
      incr ( j ) ;
    } 
    l = 30054 ;
    goto lab32 ;
    lab42: incr ( j ) ;
    l = j ;
    while ( j < 30053 ) {
	
      if ( ( eqtb [j ].cint != eqtb [j + 1 ].cint ) || ( getintone ( eqtb 
      [j ]) != getintone ( eqtb [j + 1 ]) ) ) 
      goto lab32 ;
      incr ( j ) ;
    } 
    lab32: dumpint ( l - k ) ;
    dumpthings ( eqtb [k ], l - k ) ;
    k = j + 1 ;
    dumpint ( k - l ) ;
  } while ( ! ( k > 30053 ) ) ;
  if ( hashhigh > 0 ) 
  dumpthings ( eqtb [30054 ], hashhigh ) ;
  dumpint ( parloc ) ;
  dumpint ( writeloc ) ;
  {register integer for_end; p = 0 ;for_end = 2100 ; if ( p <= for_end) do 
    dumphh ( prim [p ]) ;
  while ( p++ < for_end ) ;} 
  {register integer for_end; p = 0 ;for_end = 2100 ; if ( p <= for_end) do 
    dumpwd ( primeqtb [p ]) ;
  while ( p++ < for_end ) ;} 
  dumpint ( hashused ) ;
  cscount = 15513 - hashused + hashhigh ;
  {register integer for_end; p = 514 ;for_end = hashused ; if ( p <= 
  for_end) do 
    if ( hash [p ].v.RH != 0 ) 
    {
      dumpint ( p ) ;
      dumphh ( hash [p ]) ;
      incr ( cscount ) ;
    } 
  while ( p++ < for_end ) ;} 
  dumpthings ( hash [hashused + 1 ], 24526 - hashused ) ;
  if ( hashhigh > 0 ) 
  dumpthings ( hash [30054 ], hashhigh ) ;
  dumpint ( cscount ) ;
  println () ;
  printint ( cscount ) ;
  print ( 1398 ) ;
  dumpint ( fmemptr ) ;
  dumpthings ( fontinfo [0 ], fmemptr ) ;
  dumpint ( fontptr ) ;
  {
    dumpthings ( fontdir [0 ], fontptr + 1 ) ;
    dumpthings ( fontnumext [0 ], fontptr + 1 ) ;
    dumpthings ( fontcheck [0 ], fontptr + 1 ) ;
    dumpthings ( fontsize [0 ], fontptr + 1 ) ;
    dumpthings ( fontdsize [0 ], fontptr + 1 ) ;
    dumpthings ( fontparams [0 ], fontptr + 1 ) ;
    dumpthings ( hyphenchar [0 ], fontptr + 1 ) ;
    dumpthings ( skewchar [0 ], fontptr + 1 ) ;
    dumpthings ( fontname [0 ], fontptr + 1 ) ;
    dumpthings ( fontarea [0 ], fontptr + 1 ) ;
    dumpthings ( fontbc [0 ], fontptr + 1 ) ;
    dumpthings ( fontec [0 ], fontptr + 1 ) ;
    dumpthings ( ctypebase [0 ], fontptr + 1 ) ;
    dumpthings ( charbase [0 ], fontptr + 1 ) ;
    dumpthings ( widthbase [0 ], fontptr + 1 ) ;
    dumpthings ( heightbase [0 ], fontptr + 1 ) ;
    dumpthings ( depthbase [0 ], fontptr + 1 ) ;
    dumpthings ( italicbase [0 ], fontptr + 1 ) ;
    dumpthings ( ligkernbase [0 ], fontptr + 1 ) ;
    dumpthings ( kernbase [0 ], fontptr + 1 ) ;
    dumpthings ( extenbase [0 ], fontptr + 1 ) ;
    dumpthings ( parambase [0 ], fontptr + 1 ) ;
    dumpthings ( fontglue [0 ], fontptr + 1 ) ;
    dumpthings ( bcharlabel [0 ], fontptr + 1 ) ;
    dumpthings ( fontbchar [0 ], fontptr + 1 ) ;
    dumpthings ( fontfalsebchar [0 ], fontptr + 1 ) ;
    {register integer for_end; k = 0 ;for_end = fontptr ; if ( k <= for_end) 
    do 
      {
	printnl ( 1402 ) ;
	printesc ( hash [15526 + k ].v.RH ) ;
	printchar ( 61 ) ;
	printfilename ( fontname [k ], fontarea [k ], 343 ) ;
	if ( fontsize [k ]!= fontdsize [k ]) 
	{
	  print ( 829 ) ;
	  printscaled ( fontsize [k ]) ;
	  print ( 418 ) ;
	} 
      } 
    while ( k++ < for_end ) ;} 
  } 
  println () ;
  printint ( fmemptr - 7 ) ;
  print ( 1399 ) ;
  printint ( fontptr - 0 ) ;
  if ( fontptr != 1 ) 
  print ( 1400 ) ;
  else print ( 1401 ) ;
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
  if ( hyphcount != 1 ) 
  print ( 1403 ) ;
  else print ( 1404 ) ;
  if ( trienotready ) 
  inittrie () ;
  dumpint ( triemax ) ;
  dumpint ( hyphstart ) ;
  dumpthings ( trietrl [0 ], triemax + 1 ) ;
  dumpthings ( trietro [0 ], triemax + 1 ) ;
  dumpthings ( trietrc [0 ], triemax + 1 ) ;
  dumpint ( trieopptr ) ;
  dumpthings ( hyfdistance [1 ], trieopptr ) ;
  dumpthings ( hyfnum [1 ], trieopptr ) ;
  dumpthings ( hyfnext [1 ], trieopptr ) ;
  printnl ( 1405 ) ;
  printint ( triemax ) ;
  print ( 1406 ) ;
  printint ( trieopptr ) ;
  if ( trieopptr != 1 ) 
  print ( 1407 ) ;
  else print ( 1408 ) ;
  print ( 1409 ) ;
  printint ( trieopsize ) ;
  {register integer for_end; k = 255 ;for_end = 0 ; if ( k >= for_end) do 
    if ( trieused [k ]> 0 ) 
    {
      printnl ( 895 ) ;
      printint ( trieused [k ]) ;
      print ( 1410 ) ;
      printint ( k ) ;
      dumpint ( k ) ;
      dumpint ( trieused [k ]) ;
    } 
  while ( k-- > for_end ) ;} 
  dumpint ( interaction ) ;
  dumpint ( formatident ) ;
  dumpint ( 69069L ) ;
  eqtb [28962 ].cint = 0 ;
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
  ASCIIcode * formatengine  ;
  ASCIIcode dummyxord  ;
  ASCIIcode dummyxchr  ;
  ASCIIcode dummyxprn  ;
	;
#ifdef INITEX
  if ( iniversion ) 
  {
    libcfree ( fontinfo ) ;
    libcfree ( strpool ) ;
    libcfree ( strstart ) ;
    libcfree ( yhash ) ;
    libcfree ( zeqtb ) ;
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
  formatengine = xmallocarray ( ASCIIcode , x ) ;
  undumpthings ( formatengine [0 ], x ) ;
  formatengine [x - 1 ]= 0 ;
  if ( strcmp ( enginename , stringcast ( formatengine ) ) ) 
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
  if ( x != 147802702L ) 
  {
    ;
    fprintf ( stdout , "%s%s%s%s\n",  "---! " , stringcast ( nameoffile + 1 ) ,     " doesn't match " , poolname ) ;
    goto lab6666 ;
  } 
  if ( translatefilename ) 
  {
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      undumpthings ( dummyxord , 1 ) ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      undumpthings ( dummyxchr , 1 ) ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      undumpthings ( dummyxprn , 1 ) ;
    while ( k++ < for_end ) ;} 
  } 
  else {
      
    undumpthings ( xord [0 ], 256 ) ;
    undumpthings ( xchr [0 ], 256 ) ;
    undumpthings ( xprn [0 ], 256 ) ;
    if ( eightbitp ) 
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      xprn [k ]= 1 ;
    while ( k++ < for_end ) ;} 
  } 
  undumpint ( x ) ;
  if ( x != 268435455L ) 
  goto lab6666 ;
  undumpint ( hashhigh ) ;
  if ( ( hashhigh < 0 ) || ( hashhigh > suphashextra ) ) 
  goto lab6666 ;
  if ( hashextra < hashhigh ) 
  hashextra = hashhigh ;
  eqtbtop = 30053 + hashextra ;
  if ( hashextra == 0 ) 
  hashtop = 24527 ;
  else hashtop = eqtbtop ;
  yhash = xmallocarray ( twohalves , 1 + hashtop - hashoffset ) ;
  hash = yhash - hashoffset ;
  hash [514 ].v.LH = 0 ;
  hash [514 ].v.RH = 0 ;
  {register integer for_end; x = 515 ;for_end = hashtop ; if ( x <= for_end) 
  do 
    hash [x ]= hash [514 ];
  while ( x++ < for_end ) ;} 
  zeqtb = xmallocarray ( memoryword , eqtbtop + 1 ) ;
  eqtb = zeqtb ;
  eqtb [24527 ].hh.b0 = 113 ;
  eqtb [24527 ].hh .v.RH = -268435455L ;
  eqtb [24527 ].hh.b1 = 0 ;
  {register integer for_end; x = 30054 ;for_end = eqtbtop ; if ( x <= 
  for_end) do 
    eqtb [x ]= eqtb [24527 ];
  while ( x++ < for_end ) ;} 
  {
    undumpint ( x ) ;
    if ( ( x < 0 ) || ( x > 1 ) ) 
    goto lab6666 ;
    else eTeXmode = x ;
  } 
  if ( ( eTeXmode == 1 ) ) 
  {
    maxregnum = 65535L ;
    maxreghelpline = 1551 ;
  } 
  else {
      
    maxregnum = 255 ;
    maxreghelpline = 752 ;
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
  if ( x != 30053 ) 
  goto lab6666 ;
  undumpint ( x ) ;
  if ( x != 8501 ) 
  goto lab6666 ;
  undumpint ( x ) ;
  if ( x != 607 ) 
  goto lab6666 ;
  undumpint ( x ) ;
  if ( x != 1296847960L ) 
  goto lab6666 ;
  undumpint ( x ) ;
  if ( x == 1 ) 
  mltexenabledp = true ;
  else if ( x != 0 ) 
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
  strstart = xmallocarray ( poolpointer , maxstrings ) ;
  undumpcheckedthings ( 0 , poolptr , strstart [0 ], strptr + 1 ) ;
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
  if ( ( eTeXmode == 1 ) ) 
  {register integer for_end; k = 0 ;for_end = 5 ; if ( k <= for_end) do 
    {
      undumpint ( x ) ;
      if ( ( x < -268435455L ) || ( x > lomemmax ) ) 
      goto lab6666 ;
      else saroot [k ]= x ;
    } 
  while ( k++ < for_end ) ;} 
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
    mem [memmin ].hh .v.RH = -268435455L ;
    mem [memmin ].hh .v.LH = -268435455L ;
    mem [p + 1 ].hh .v.RH = q ;
    mem [rover + 1 ].hh .v.LH = q ;
    mem [q + 1 ].hh .v.RH = rover ;
    mem [q + 1 ].hh .v.LH = p ;
    mem [q ].hh .v.RH = 268435455L ;
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
    if ( ( x < -268435455L ) || ( x > memtop ) ) 
    goto lab6666 ;
    else avail = x ;
  } 
  memend = memtop ;
  undumpthings ( mem [himemmin ], memend + 1 - himemmin ) ;
  undumpint ( varused ) ;
  undumpint ( dynused ) ;
  k = 1 ;
  do {
      undumpint ( x ) ;
    if ( ( x < 1 ) || ( k + x > 30054 ) ) 
    goto lab6666 ;
    undumpthings ( eqtb [k ], x ) ;
    k = k + x ;
    undumpint ( x ) ;
    if ( ( x < 0 ) || ( k + x > 30054 ) ) 
    goto lab6666 ;
    {register integer for_end; j = k ;for_end = k + x - 1 ; if ( j <= 
    for_end) do 
      eqtb [j ]= eqtb [k - 1 ];
    while ( j++ < for_end ) ;} 
    k = k + x ;
  } while ( ! ( k > 30053 ) ) ;
  if ( hashhigh > 0 ) 
  undumpthings ( eqtb [30054 ], hashhigh ) ;
  {
    undumpint ( x ) ;
    if ( ( x < 514 ) || ( x > hashtop ) ) 
    goto lab6666 ;
    else parloc = x ;
  } 
  partoken = 65535L + parloc ;
  {
    undumpint ( x ) ;
    if ( ( x < 514 ) || ( x > hashtop ) ) 
    goto lab6666 ;
    else
    writeloc = x ;
  } 
  {register integer for_end; p = 0 ;for_end = 2100 ; if ( p <= for_end) do 
    undumphh ( prim [p ]) ;
  while ( p++ < for_end ) ;} 
  {register integer for_end; p = 0 ;for_end = 2100 ; if ( p <= for_end) do 
    undumpwd ( primeqtb [p ]) ;
  while ( p++ < for_end ) ;} 
  {
    undumpint ( x ) ;
    if ( ( x < 514 ) || ( x > 15514 ) ) 
    goto lab6666 ;
    else hashused = x ;
  } 
  p = 513 ;
  do {
      { 
      undumpint ( x ) ;
      if ( ( x < p + 1 ) || ( x > hashused ) ) 
      goto lab6666 ;
      else p = x ;
    } 
    undumphh ( hash [p ]) ;
  } while ( ! ( p == hashused ) ) ;
  undumpthings ( hash [hashused + 1 ], 24526 - hashused ) ;
  if ( debugformatfile ) 
  {
    printcsnames ( 514 , 24526 ) ;
  } 
  if ( hashhigh > 0 ) 
  {
    undumpthings ( hash [30054 ], hashhigh ) ;
    if ( debugformatfile ) 
    {
      printcsnames ( 30054 , hashhigh - ( 30054 ) ) ;
    } 
  } 
  undumpint ( cscount ) ;
  {
    undumpint ( x ) ;
    if ( x < 7 ) 
    goto lab6666 ;
    if ( x > supfontmemsize ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "font mem size" ) ;
      goto lab6666 ;
    } 
    else if ( debugformatfile ) 
    {
      fprintf ( stderr , "%s%s",  "fmtdebug:" , "font mem size" ) ;
      fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
    } 
    fmemptr = x ;
  } 
  if ( fmemptr > fontmemsize ) 
  fontmemsize = fmemptr ;
  fontinfo = xmallocarray ( memoryword , fontmemsize ) ;
  undumpthings ( fontinfo [0 ], fmemptr ) ;
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > 9000 ) 
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
  {
    fontdir = xmallocarray ( eightbits , fontmax ) ;
    fontnumext = xmallocarray ( integer , fontmax ) ;
    fontcheck = xmallocarray ( fourquarters , fontmax ) ;
    fontsize = xmallocarray ( scaled , fontmax ) ;
    fontdsize = xmallocarray ( scaled , fontmax ) ;
    fontparams = xmallocarray ( fontindex , fontmax ) ;
    fontname = xmallocarray ( strnumber , fontmax ) ;
    fontarea = xmallocarray ( strnumber , fontmax ) ;
    fontbc = xmallocarray ( eightbits , fontmax ) ;
    fontec = xmallocarray ( eightbits , fontmax ) ;
    fontglue = xmallocarray ( halfword , fontmax ) ;
    hyphenchar = xmallocarray ( integer , fontmax ) ;
    skewchar = xmallocarray ( integer , fontmax ) ;
    bcharlabel = xmallocarray ( fontindex , fontmax ) ;
    fontbchar = xmallocarray ( ninebits , fontmax ) ;
    fontfalsebchar = xmallocarray ( ninebits , fontmax ) ;
    ctypebase = xmallocarray ( integer , fontmax ) ;
    charbase = xmallocarray ( integer , fontmax ) ;
    widthbase = xmallocarray ( integer , fontmax ) ;
    heightbase = xmallocarray ( integer , fontmax ) ;
    depthbase = xmallocarray ( integer , fontmax ) ;
    italicbase = xmallocarray ( integer , fontmax ) ;
    ligkernbase = xmallocarray ( integer , fontmax ) ;
    kernbase = xmallocarray ( integer , fontmax ) ;
    extenbase = xmallocarray ( integer , fontmax ) ;
    parambase = xmallocarray ( integer , fontmax ) ;
    undumpthings ( fontdir [0 ], fontptr + 1 ) ;
    undumpthings ( fontnumext [0 ], fontptr + 1 ) ;
    undumpthings ( fontcheck [0 ], fontptr + 1 ) ;
    undumpthings ( fontsize [0 ], fontptr + 1 ) ;
    undumpthings ( fontdsize [0 ], fontptr + 1 ) ;
    undumpcheckedthings ( -268435455L , 268435455L , fontparams [0 ], 
    fontptr + 1 ) ;
    undumpthings ( hyphenchar [0 ], fontptr + 1 ) ;
    undumpthings ( skewchar [0 ], fontptr + 1 ) ;
    undumpuppercheckthings ( strptr , fontname [0 ], fontptr + 1 ) ;
    undumpuppercheckthings ( strptr , fontarea [0 ], fontptr + 1 ) ;
    undumpthings ( fontbc [0 ], fontptr + 1 ) ;
    undumpthings ( fontec [0 ], fontptr + 1 ) ;
    undumpthings ( ctypebase [0 ], fontptr + 1 ) ;
    undumpthings ( charbase [0 ], fontptr + 1 ) ;
    undumpthings ( widthbase [0 ], fontptr + 1 ) ;
    undumpthings ( heightbase [0 ], fontptr + 1 ) ;
    undumpthings ( depthbase [0 ], fontptr + 1 ) ;
    undumpthings ( italicbase [0 ], fontptr + 1 ) ;
    undumpthings ( ligkernbase [0 ], fontptr + 1 ) ;
    undumpthings ( kernbase [0 ], fontptr + 1 ) ;
    undumpthings ( extenbase [0 ], fontptr + 1 ) ;
    undumpthings ( parambase [0 ], fontptr + 1 ) ;
    undumpcheckedthings ( -268435455L , lomemmax , fontglue [0 ], fontptr + 
    1 ) ;
    undumpcheckedthings ( 0 , fmemptr - 1 , bcharlabel [0 ], fontptr + 1 ) ;
    undumpcheckedthings ( 0 , 256 , fontbchar [0 ], fontptr + 1 ) ;
    undumpcheckedthings ( 0 , 256 , fontfalsebchar [0 ], fontptr + 1 ) ;
  } 
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
	if ( ( x < -268435455L ) || ( x > 268435455L ) ) 
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
  if ( ! trietrl ) 
  trietrl = xmallocarray ( triepointer , j + 1 ) ;
  undumpthings ( trietrl [0 ], j + 1 ) ;
  if ( ! trietro ) 
  trietro = xmallocarray ( triepointer , j + 1 ) ;
  undumpthings ( trietro [0 ], j + 1 ) ;
  if ( ! trietrc ) 
  trietrc = xmallocarray ( quarterword , j + 1 ) ;
  undumpthings ( trietrc [0 ], j + 1 ) ;
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
  undumpuppercheckthings ( maxtrieop , hyfnext [1 ], j ) ;
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
      
    print ( 1415 ) ;
    decr ( openparens ) ;
  } 
  if ( curlevel > 1 ) 
  {
    printnl ( 40 ) ;
    printesc ( 1416 ) ;
    print ( 1417 ) ;
    printint ( curlevel - 1 ) ;
    printchar ( 41 ) ;
    if ( ( eTeXmode == 1 ) ) 
    showsavegroups () ;
  } 
  while ( condptr != -268435455L ) {
      
    printnl ( 40 ) ;
    printesc ( 1416 ) ;
    print ( 1418 ) ;
    printcmdchr ( 117 , curif ) ;
    if ( ifline != 0 ) 
    {
      print ( 1419 ) ;
      printint ( ifline ) ;
    } 
    print ( 1420 ) ;
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
	printnl ( 1421 ) ;
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
	if ( curmark [c ]!= -268435455L ) 
	deletetokenref ( curmark [c ]) ;
      while ( c++ < for_end ) ;} 
      if ( saroot [6 ]!= -268435455L ) {
	  
	if ( domarks ( 3 , 0 , saroot [6 ]) ) 
	saroot [6 ]= -268435455L ;
      } 
      {register integer for_end; c = 2 ;for_end = 3 ; if ( c <= for_end) do 
	flushnodelist ( discptr [c ]) ;
      while ( c++ < for_end ) ;} 
      if ( lastglue != 268435455L ) 
      deleteglueref ( lastglue ) ;
      storefmtfile () ;
      return ;
    } 
#endif /* INITEX */
    printnl ( 1422 ) ;
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
  primitive ( 394 , 81 , 24528 ) ;
  primitive ( 395 , 81 , 24529 ) ;
  primitive ( 396 , 81 , 24530 ) ;
  primitive ( 397 , 81 , 24531 ) ;
  primitive ( 398 , 81 , 24532 ) ;
  primitive ( 399 , 81 , 24533 ) ;
  primitive ( 400 , 81 , 24534 ) ;
  primitive ( 401 , 81 , 24535 ) ;
  primitive ( 402 , 81 , 24536 ) ;
  primitive ( 403 , 81 , 24537 ) ;
  primitive ( 404 , 81 , 24538 ) ;
  primitive ( 405 , 81 , 24539 ) ;
  primitive ( 406 , 81 , 24540 ) ;
  primitive ( 407 , 81 , 24541 ) ;
  primitive ( 408 , 81 , 24542 ) ;
  primitive ( 409 , 82 , 24545 ) ;
  primitive ( 410 , 82 , 24546 ) ;
  primitive ( 411 , 82 , 24547 ) ;
  primitive ( 412 , 81 , 24543 ) ;
  primitive ( 413 , 81 , 24544 ) ;
  primitive ( 419 , 78 , 25062 ) ;
  primitive ( 420 , 78 , 25063 ) ;
  primitive ( 421 , 78 , 25064 ) ;
  primitive ( 422 , 78 , 25065 ) ;
  primitive ( 423 , 78 , 25066 ) ;
  primitive ( 424 , 78 , 25067 ) ;
  primitive ( 425 , 78 , 25068 ) ;
  primitive ( 426 , 78 , 25069 ) ;
  primitive ( 427 , 78 , 25070 ) ;
  primitive ( 446 , 79 , 28931 ) ;
  primitive ( 447 , 79 , 28932 ) ;
  primitive ( 448 , 79 , 28933 ) ;
  primitive ( 449 , 79 , 28934 ) ;
  primitive ( 450 , 79 , 28935 ) ;
  primitive ( 451 , 79 , 28936 ) ;
  primitive ( 452 , 79 , 28937 ) ;
  primitive ( 453 , 79 , 28938 ) ;
  primitive ( 454 , 79 , 28939 ) ;
  primitive ( 455 , 79 , 28940 ) ;
  primitive ( 456 , 79 , 28941 ) ;
  primitive ( 457 , 79 , 28942 ) ;
  primitive ( 458 , 79 , 28943 ) ;
  primitive ( 459 , 79 , 28944 ) ;
  primitive ( 460 , 79 , 28945 ) ;
  primitive ( 461 , 79 , 28946 ) ;
  primitive ( 462 , 79 , 28947 ) ;
  primitive ( 463 , 79 , 28948 ) ;
  primitive ( 464 , 79 , 28949 ) ;
  primitive ( 465 , 79 , 28950 ) ;
  primitive ( 466 , 79 , 28951 ) ;
  primitive ( 467 , 79 , 28952 ) ;
  primitive ( 468 , 79 , 28953 ) ;
  primitive ( 469 , 79 , 28954 ) ;
  primitive ( 470 , 79 , 28955 ) ;
  primitive ( 471 , 79 , 28956 ) ;
  primitive ( 472 , 79 , 28957 ) ;
  primitive ( 473 , 79 , 28958 ) ;
  primitive ( 474 , 79 , 28959 ) ;
  primitive ( 475 , 79 , 28960 ) ;
  primitive ( 476 , 79 , 28961 ) ;
  primitive ( 477 , 79 , 28962 ) ;
  primitive ( 478 , 79 , 28963 ) ;
  primitive ( 479 , 79 , 28964 ) ;
  primitive ( 480 , 79 , 28965 ) ;
  primitive ( 481 , 79 , 28966 ) ;
  primitive ( 482 , 79 , 28967 ) ;
  primitive ( 483 , 79 , 28968 ) ;
  primitive ( 484 , 79 , 28969 ) ;
  primitive ( 485 , 79 , 28970 ) ;
  primitive ( 486 , 79 , 28971 ) ;
  primitive ( 487 , 79 , 28972 ) ;
  primitive ( 488 , 79 , 28973 ) ;
  primitive ( 489 , 79 , 28974 ) ;
  primitive ( 490 , 79 , 28975 ) ;
  primitive ( 491 , 79 , 28977 ) ;
  primitive ( 492 , 79 , 28978 ) ;
  primitive ( 493 , 79 , 28979 ) ;
  primitive ( 494 , 79 , 28980 ) ;
  primitive ( 495 , 79 , 28981 ) ;
  primitive ( 496 , 79 , 28976 ) ;
  primitive ( 497 , 79 , 28987 ) ;
  primitive ( 498 , 79 , 28988 ) ;
  primitive ( 499 , 79 , 28989 ) ;
  primitive ( 500 , 79 , 28990 ) ;
  primitive ( 501 , 79 , 28982 ) ;
  primitive ( 502 , 79 , 28983 ) ;
  primitive ( 503 , 79 , 28984 ) ;
  primitive ( 504 , 79 , 28985 ) ;
  primitive ( 505 , 79 , 28986 ) ;
  if ( mltexp ) 
  {
    mltexenabledp = true ;
    if ( false ) 
    primitive ( 506 , 79 , 28991 ) ;
    primitive ( 507 , 79 , 28992 ) ;
    primitive ( 508 , 79 , 28993 ) ;
  } 
  primitive ( 512 , 80 , 29517 ) ;
  primitive ( 513 , 80 , 29518 ) ;
  primitive ( 514 , 80 , 29519 ) ;
  primitive ( 515 , 80 , 29520 ) ;
  primitive ( 516 , 80 , 29521 ) ;
  primitive ( 517 , 80 , 29522 ) ;
  primitive ( 518 , 80 , 29523 ) ;
  primitive ( 519 , 80 , 29524 ) ;
  primitive ( 520 , 80 , 29525 ) ;
  primitive ( 521 , 80 , 29526 ) ;
  primitive ( 522 , 80 , 29527 ) ;
  primitive ( 523 , 80 , 29528 ) ;
  primitive ( 524 , 80 , 29529 ) ;
  primitive ( 525 , 80 , 29530 ) ;
  primitive ( 526 , 80 , 29531 ) ;
  primitive ( 527 , 80 , 29532 ) ;
  primitive ( 528 , 80 , 29533 ) ;
  primitive ( 529 , 80 , 29534 ) ;
  primitive ( 530 , 80 , 29535 ) ;
  primitive ( 531 , 80 , 29536 ) ;
  primitive ( 532 , 80 , 29538 ) ;
  primitive ( 533 , 80 , 29539 ) ;
  primitive ( 534 , 80 , 29537 ) ;
  primitive ( 32 , 67 , 0 ) ;
  primitive ( 47 , 47 , 0 ) ;
  primitive ( 549 , 48 , 0 ) ;
  primitive ( 550 , 101 , 0 ) ;
  primitive ( 551 , 43 , 0 ) ;
  primitive ( 552 , 44 , 0 ) ;
  primitive ( 553 , 64 , 0 ) ;
  primitive ( 554 , 19 , 0 ) ;
  primitive ( 545 , 119 , 0 ) ;
  primitive ( 555 , 15 , 0 ) ;
  primitive ( 556 , 15 , 1 ) ;
  primitive ( 557 , 103 , 0 ) ;
  primitive ( 546 , 70 , 0 ) ;
  primitive ( 558 , 65 , 0 ) ;
  hash [15516 ].v.RH = 558 ;
  eqtb [15516 ]= eqtb [curval ];
  primitive ( 559 , 114 , 0 ) ;
  primitive ( 560 , 97 , 0 ) ;
  primitive ( 561 , 98 , 0 ) ;
  primitive ( 562 , 99 , 0 ) ;
  primitive ( 563 , 83 , 0 ) ;
  primitive ( 564 , 35 , 0 ) ;
  primitive ( 565 , 39 , 0 ) ;
  primitive ( 566 , 42 , 0 ) ;
  primitive ( 335 , 40 , 0 ) ;
  primitive ( 360 , 21 , 0 ) ;
  primitive ( 567 , 49 , 0 ) ;
  primitive ( 568 , 20 , 0 ) ;
  primitive ( 569 , 49 , 1 ) ;
  primitive ( 570 , 20 , 1 ) ;
  primitive ( 571 , 57 , 0 ) ;
  primitive ( 572 , 102 , 0 ) ;
  primitive ( 573 , 37 , 0 ) ;
  primitive ( 574 , 68 , 0 ) ;
  primitive ( 575 , 115 , 0 ) ;
  primitive ( 340 , 58 , 0 ) ;
  primitive ( 576 , 66 , 0 ) ;
  primitive ( 577 , 93 , 25061 ) ;
  primitive ( 578 , 45 , 0 ) ;
  primitive ( 579 , 89 , 0 ) ;
  primitive ( 580 , 69 , 0 ) ;
  primitive ( 581 , 69 , 1 ) ;
  primitive ( 582 , 107 , 0 ) ;
  primitive ( 583 , 0 , 256 ) ;
  hash [15521 ].v.RH = 583 ;
  eqtb [15521 ]= eqtb [curval ];
  primitive ( 584 , 109 , 0 ) ;
  primitive ( 585 , 121 , 0 ) ;
  primitive ( 428 , 77 , membot ) ;
  primitive ( 361 , 41 , 0 ) ;
  primitive ( 586 , 36 , 0 ) ;
  primitive ( 587 , 59 , 0 ) ;
  primitive ( 588 , 38 , 0 ) ;
  primitive ( 650 , 13 , 256 ) ;
  parloc = curval ;
  partoken = 65535L + parloc ;
  primitive ( 688 , 116 , 0 ) ;
  primitive ( 689 , 116 , 1 ) ;
  primitive ( 690 , 122 , 0 ) ;
  primitive ( 691 , 122 , 1 ) ;
  primitive ( 692 , 122 , 2 ) ;
  primitive ( 693 , 122 , 3 ) ;
  primitive ( 694 , 122 , 4 ) ;
  primitive ( 510 , 100 , membot + 0 ) ;
  primitive ( 538 , 100 , membot + 1 ) ;
  primitive ( 416 , 100 , membot + 2 ) ;
  primitive ( 417 , 100 , membot + 3 ) ;
  primitive ( 732 , 88 , 114 ) ;
  primitive ( 733 , 88 , 1 ) ;
  primitive ( 734 , 91 , 0 ) ;
  primitive ( 735 , 91 , 1 ) ;
  primitive ( 736 , 92 , 1 ) ;
  primitive ( 737 , 92 , 3 ) ;
  primitive ( 738 , 92 , 2 ) ;
  primitive ( 739 , 74 , 0 ) ;
  primitive ( 740 , 74 , 1 ) ;
  primitive ( 741 , 74 , 2 ) ;
  primitive ( 742 , 74 , 5 ) ;
  primitive ( 743 , 74 , 6 ) ;
  primitive ( 804 , 120 , 0 ) ;
  primitive ( 805 , 120 , 1 ) ;
  primitive ( 806 , 120 , 3 ) ;
  primitive ( 807 , 120 , 4 ) ;
  primitive ( 808 , 120 , 5 ) ;
  primitive ( 809 , 120 , 2 ) ;
  primitive ( 810 , 120 , 6 ) ;
  primitive ( 811 , 120 , 7 ) ;
  primitive ( 812 , 120 , 8 ) ;
  primitive ( 813 , 120 , 9 ) ;
  primitive ( 814 , 120 , 17 ) ;
  primitive ( 844 , 117 , 0 ) ;
  primitive ( 845 , 117 , 1 ) ;
  primitive ( 846 , 117 , 2 ) ;
  primitive ( 847 , 117 , 3 ) ;
  primitive ( 848 , 117 , 4 ) ;
  primitive ( 849 , 117 , 5 ) ;
  primitive ( 850 , 117 , 6 ) ;
  primitive ( 851 , 117 , 7 ) ;
  primitive ( 852 , 117 , 8 ) ;
  primitive ( 853 , 117 , 9 ) ;
  primitive ( 854 , 117 , 10 ) ;
  primitive ( 855 , 117 , 11 ) ;
  primitive ( 856 , 117 , 12 ) ;
  primitive ( 857 , 117 , 13 ) ;
  primitive ( 858 , 117 , 14 ) ;
  primitive ( 859 , 117 , 15 ) ;
  primitive ( 860 , 117 , 16 ) ;
  primitive ( 861 , 117 , 20 ) ;
  primitive ( 862 , 117 , 21 ) ;
  primitive ( 863 , 117 , 22 ) ;
  primitive ( 864 , 117 , 23 ) ;
  primitive ( 865 , 117 , 24 ) ;
  primitive ( 866 , 117 , 25 ) ;
  primitive ( 867 , 117 , 26 ) ;
  primitive ( 315 , 118 , 2 ) ;
  hash [15518 ].v.RH = 315 ;
  eqtb [15518 ]= eqtb [curval ];
  primitive ( 870 , 118 , 4 ) ;
  primitive ( 871 , 118 , 3 ) ;
  primitive ( 896 , 96 , 0 ) ;
  hash [15526 ].v.RH = 896 ;
  eqtb [15526 ]= eqtb [curval ];
  primitive ( 996 , 4 , 256 ) ;
  primitive ( 997 , 5 , 257 ) ;
  hash [15515 ].v.RH = 997 ;
  eqtb [15515 ]= eqtb [curval ];
  primitive ( 998 , 5 , 258 ) ;
  hash [15519 ].v.RH = 999 ;
  hash [15520 ].v.RH = 999 ;
  eqtb [15520 ].hh.b0 = 9 ;
  eqtb [15520 ].hh .v.RH = memtop - 11 ;
  eqtb [15520 ].hh.b1 = 1 ;
  eqtb [15519 ]= eqtb [15520 ];
  eqtb [15519 ].hh.b0 = 127 ;
  primitive ( 1068 , 90 , 0 ) ;
  primitive ( 1069 , 90 , 1 ) ;
  primitive ( 1070 , 90 , 2 ) ;
  primitive ( 1071 , 90 , 3 ) ;
  primitive ( 1072 , 90 , 4 ) ;
  primitive ( 1073 , 90 , 5 ) ;
  primitive ( 1074 , 90 , 6 ) ;
  primitive ( 1075 , 90 , 7 ) ;
  primitive ( 1076 , 90 , 8 ) ;
  primitive ( 348 , 14 , 0 ) ;
  primitive ( 1126 , 14 , 1 ) ;
  primitive ( 1127 , 29 , 5 ) ;
  primitive ( 1128 , 29 , 0 ) ;
  primitive ( 1129 , 29 , 1 ) ;
  primitive ( 1130 , 29 , 2 ) ;
  primitive ( 1131 , 29 , 3 ) ;
  primitive ( 1132 , 29 , 4 ) ;
  primitive ( 1133 , 30 , 5 ) ;
  primitive ( 1134 , 30 , 0 ) ;
  primitive ( 1135 , 30 , 1 ) ;
  primitive ( 1136 , 30 , 2 ) ;
  primitive ( 1137 , 30 , 3 ) ;
  primitive ( 1138 , 30 , 4 ) ;
  primitive ( 341 , 31 , 6 ) ;
  primitive ( 345 , 32 , 1 ) ;
  primitive ( 347 , 33 , 99 ) ;
  primitive ( 1156 , 24 , 1 ) ;
  primitive ( 1157 , 24 , 0 ) ;
  primitive ( 1158 , 25 , 1 ) ;
  primitive ( 1159 , 25 , 0 ) ;
  primitive ( 430 , 23 , 0 ) ;
  primitive ( 1160 , 23 , 1 ) ;
  primitive ( 1161 , 23 , 2 ) ;
  primitive ( 1063 , 23 , 3 ) ;
  primitive ( 1162 , 23 , 4 ) ;
  primitive ( 1065 , 23 , 5 ) ;
  primitive ( 1163 , 23 , 118 ) ;
  primitive ( 1164 , 76 , 3 ) ;
  primitive ( 1165 , 76 , 4 ) ;
  primitive ( 1166 , 76 , 1 ) ;
  primitive ( 1167 , 34 , 99 ) ;
  primitive ( 1168 , 34 , 100 ) ;
  primitive ( 1169 , 34 , 101 ) ;
  primitive ( 1170 , 34 , 102 ) ;
  primitive ( 1197 , 46 , 1 ) ;
  primitive ( 1198 , 46 , 0 ) ;
  primitive ( 1209 , 28 , 14 ) ;
  primitive ( 1210 , 28 , 13 ) ;
  primitive ( 1211 , 28 , 12 ) ;
  primitive ( 1212 , 26 , 0 ) ;
  primitive ( 1213 , 26 , 1 ) ;
  primitive ( 1214 , 27 , 0 ) ;
  primitive ( 1215 , 27 , 1 ) ;
  primitive ( 45 , 50 , 1 ) ;
  primitive ( 358 , 50 , 0 ) ;
  primitive ( 1248 , 51 , 0 ) ;
  primitive ( 1249 , 51 , 1 ) ;
  primitive ( 962 , 53 , 18 ) ;
  primitive ( 963 , 53 , 19 ) ;
  primitive ( 964 , 53 , 20 ) ;
  primitive ( 965 , 53 , 21 ) ;
  primitive ( 966 , 53 , 22 ) ;
  primitive ( 967 , 53 , 23 ) ;
  primitive ( 968 , 53 , 24 ) ;
  primitive ( 969 , 53 , 25 ) ;
  primitive ( 971 , 53 , 28 ) ;
  primitive ( 970 , 53 , 29 ) ;
  primitive ( 1253 , 54 , 0 ) ;
  primitive ( 975 , 54 , 1 ) ;
  primitive ( 976 , 54 , 2 ) ;
  primitive ( 957 , 56 , 0 ) ;
  primitive ( 958 , 56 , 2 ) ;
  primitive ( 959 , 56 , 4 ) ;
  primitive ( 960 , 56 , 6 ) ;
  primitive ( 1271 , 55 , 0 ) ;
  primitive ( 1272 , 55 , 1 ) ;
  primitive ( 1273 , 55 , 2 ) ;
  primitive ( 1274 , 55 , 3 ) ;
  primitive ( 1275 , 55 , 4 ) ;
  primitive ( 1276 , 55 , 5 ) ;
  primitive ( 972 , 52 , 32 ) ;
  primitive ( 973 , 52 , 33 ) ;
  hash [15517 ].v.RH = 973 ;
  eqtb [15517 ]= eqtb [curval ];
  primitive ( 1296 , 104 , 1 ) ;
  primitive ( 1297 , 104 , 2 ) ;
  primitive ( 1298 , 104 , 4 ) ;
  primitive ( 1299 , 108 , 0 ) ;
  primitive ( 1300 , 108 , 1 ) ;
  primitive ( 1301 , 108 , 2 ) ;
  primitive ( 1302 , 108 , 3 ) ;
  primitive ( 1319 , 105 , 0 ) ;
  primitive ( 1320 , 105 , 1 ) ;
  primitive ( 1321 , 106 , 0 ) ;
  primitive ( 1322 , 106 , 1 ) ;
  primitive ( 1323 , 106 , 2 ) ;
  primitive ( 1324 , 106 , 3 ) ;
  primitive ( 1325 , 106 , 4 ) ;
  primitive ( 1326 , 106 , 5 ) ;
  primitive ( 1327 , 106 , 6 ) ;
  primitive ( 1328 , 106 , 7 ) ;
  if ( mltexp ) 
  {
    primitive ( 1329 , 106 , 8 ) ;
  } 
  primitive ( 436 , 94 , 26361 ) ;
  primitive ( 437 , 94 , 26617 ) ;
  primitive ( 438 , 94 , 26873 ) ;
  primitive ( 445 , 94 , 28419 ) ;
  primitive ( 1334 , 94 , 28547 ) ;
  primitive ( 442 , 94 , 27651 ) ;
  primitive ( 443 , 94 , 27907 ) ;
  primitive ( 444 , 94 , 28163 ) ;
  primitive ( 511 , 94 , 29261 ) ;
  primitive ( 1335 , 94 , 29389 ) ;
  primitive ( 433 , 95 , 25589 ) ;
  primitive ( 434 , 95 , 25845 ) ;
  primitive ( 435 , 95 , 26101 ) ;
  primitive ( 1039 , 110 , 0 ) ;
  primitive ( 1051 , 110 , 1 ) ;
  primitive ( 1354 , 84 , 0 ) ;
  primitive ( 1355 , 84 , 1 ) ;
  primitive ( 273 , 111 , 0 ) ;
  primitive ( 274 , 111 , 1 ) ;
  primitive ( 275 , 111 , 2 ) ;
  primitive ( 1364 , 111 , 3 ) ;
  primitive ( 1365 , 63 , 1 ) ;
  primitive ( 1366 , 63 , 0 ) ;
  primitive ( 1367 , 61 , 0 ) ;
  primitive ( 1368 , 61 , 1 ) ;
  primitive ( 1374 , 60 , 27651 ) ;
  primitive ( 1375 , 60 , 27907 ) ;
  primitive ( 1376 , 22 , 0 ) ;
  primitive ( 1377 , 22 , 1 ) ;
  primitive ( 1378 , 22 , 2 ) ;
  primitive ( 1379 , 22 , 3 ) ;
  primitive ( 1380 , 22 , 7 ) ;
  primitive ( 1424 , 62 , 0 ) ;
  primitive ( 647 , 62 , 1 ) ;
  writeloc = curval ;
  primitive ( 1425 , 62 , 2 ) ;
  primitive ( 1426 , 62 , 3 ) ;
  hash [15524 ].v.RH = 1426 ;
  eqtb [15524 ]= eqtb [curval ];
  primitive ( 1427 , 62 , 4 ) ;
  primitive ( 1428 , 62 , 5 ) ;
  primitive ( 1429 , 62 , 7 ) ;
  primitive ( 1563 , 79 , 28994 ) ;
  primitive ( 441 , 87 , 0 ) ;
  primitive ( 1567 , 112 , 1 ) ;
  primitive ( 1568 , 112 , 0 ) ;
  primitive ( 1569 , 112 , 3 ) ;
  primitive ( 1570 , 112 , 2 ) ;
  primitive ( 1579 , 75 , 0 ) ;
  primitive ( 1580 , 86 , 27129 ) ;
  primitive ( 1583 , 85 , 1 ) ;
  primitive ( 1584 , 85 , 2 ) ;
  nonewcontrolsequence = true ;
} 
#endif /* INITEX */
void 
mainbody ( void ) 
{
  mainbody_regmem 
  bounddefault = 0 ;
  boundname = "mem_bot" ;
  setupboundvariable ( addressof ( membot ) , boundname , bounddefault ) ;
  bounddefault = 250000L ;
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
  bounddefault = 200000L ;
  boundname = "pool_size" ;
  setupboundvariable ( addressof ( poolsize ) , boundname , bounddefault ) ;
  bounddefault = 75000L ;
  boundname = "string_vacancies" ;
  setupboundvariable ( addressof ( stringvacancies ) , boundname , 
  bounddefault ) ;
  bounddefault = 5000 ;
  boundname = "pool_free" ;
  setupboundvariable ( addressof ( poolfree ) , boundname , bounddefault ) ;
  bounddefault = 15000 ;
  boundname = "max_strings" ;
  setupboundvariable ( addressof ( maxstrings ) , boundname , bounddefault ) ;
  bounddefault = 100 ;
  boundname = "strings_free" ;
  setupboundvariable ( addressof ( stringsfree ) , boundname , bounddefault ) 
  ;
  bounddefault = 100000L ;
  boundname = "font_mem_size" ;
  setupboundvariable ( addressof ( fontmemsize ) , boundname , bounddefault ) 
  ;
  bounddefault = 500 ;
  boundname = "font_max" ;
  setupboundvariable ( addressof ( fontmax ) , boundname , bounddefault ) ;
  bounddefault = 20000 ;
  boundname = "trie_size" ;
  setupboundvariable ( addressof ( triesize ) , boundname , bounddefault ) ;
  bounddefault = 659 ;
  boundname = "hyph_size" ;
  setupboundvariable ( addressof ( hyphsize ) , boundname , bounddefault ) ;
  bounddefault = 3000 ;
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
  bounddefault = 0 ;
  boundname = "hash_extra" ;
  setupboundvariable ( addressof ( hashextra ) , boundname , bounddefault ) ;
  bounddefault = 10000 ;
  boundname = "expand_depth" ;
  setupboundvariable ( addressof ( expanddepth ) , boundname , bounddefault ) 
  ;
  {
    if ( membot < infmembot ) 
    membot = infmembot ;
    else if ( membot > supmembot ) 
    membot = supmembot ;
  } 
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
    extramembot = 0 ;
  } 
#endif /* INITEX */
  if ( extramembot > supmainmemory ) 
  extramembot = supmainmemory ;
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
  {
    if ( fontmemsize < inffontmemsize ) 
    fontmemsize = inffontmemsize ;
    else if ( fontmemsize > supfontmemsize ) 
    fontmemsize = supfontmemsize ;
  } 
  {
    if ( fontmax < inffontmax ) 
    fontmax = inffontmax ;
    else if ( fontmax > supfontmax ) 
    fontmax = supfontmax ;
  } 
  {
    if ( hashextra < infhashextra ) 
    hashextra = infhashextra ;
    else if ( hashextra > suphashextra ) 
    hashextra = suphashextra ;
  } 
  if ( errorline > 255 ) 
  errorline = 255 ;
  buffer = xmallocarray ( ASCIIcode , bufsize ) ;
  nest = xmallocarray ( liststaterecord , nestsize ) ;
  savestack = xmallocarray ( memoryword , savesize ) ;
  inputstack = xmallocarray ( instaterecord , stacksize ) ;
  inputfile = xmallocarray ( alphafile , maxinopen ) ;
  linestack = xmallocarray ( integer , maxinopen ) ;
  eofseen = xmallocarray ( boolean , maxinopen ) ;
  grpstack = xmallocarray ( savepointer , maxinopen ) ;
  ifstack = xmallocarray ( halfword , maxinopen ) ;
  sourcefilenamestack = xmallocarray ( strnumber , maxinopen ) ;
  fullsourcefilenamestack = xmallocarray ( strnumber , maxinopen ) ;
  paramstack = xmallocarray ( halfword , paramsize ) ;
  dvibuf = xmallocarray ( eightbits , dvibufsize ) ;
  hyphword = xmallocarray ( strnumber , hyphsize ) ;
  hyphlist = xmallocarray ( halfword , hyphsize ) ;
  hyphlink = xmallocarray ( hyphpointer , hyphsize ) ;
	;
#ifdef INITEX
  if ( iniversion ) 
  {
    yzmem = xmallocarray ( memoryword , memtop - membot + 1 ) ;
    zmem = yzmem - membot ;
    eqtbtop = 30053 + hashextra ;
    if ( hashextra == 0 ) 
    hashtop = 24527 ;
    else hashtop = eqtbtop ;
    yhash = xmallocarray ( twohalves , 1 + hashtop - hashoffset ) ;
    hash = yhash - hashoffset ;
    hash [514 ].v.LH = 0 ;
    hash [514 ].v.RH = 0 ;
    {register integer for_end; hashused = 515 ;for_end = hashtop ; if ( 
    hashused <= for_end) do 
      hash [hashused ]= hash [514 ];
    while ( hashused++ < for_end ) ;} 
    zeqtb = xmallocarray ( memoryword , eqtbtop ) ;
    eqtb = zeqtb ;
    strstart = xmallocarray ( poolpointer , maxstrings ) ;
    strpool = xmallocarray ( packedASCIIcode , poolsize ) ;
    fontinfo = xmallocarray ( memoryword , fontmemsize ) ;
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
  if ( 8501 > 15000 ) 
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
  if ( ( 0 > 0 ) || ( 65535L < 127 ) ) 
  bad = 11 ;
  if ( ( -268435455L > 0 ) || ( 268435455L < 32767 ) ) 
  bad = 12 ;
  if ( ( 0 < -268435455L ) || ( 65535L > 268435455L ) ) 
  bad = 13 ;
  if ( ( membot - supmainmemory < -268435455L ) || ( memtop + supmainmemory >= 
  268435455L ) || ( 0 != 0 ) ) 
  bad = 14 ;
  if ( ( 9000 < -268435455L ) || ( 9000 > 268435455L ) ) 
  bad = 15 ;
  if ( fontmax > 9000 ) 
  bad = 16 ;
  if ( ( savesize > 268435455L ) || ( maxstrings > 268435455L ) ) 
  bad = 17 ;
  if ( bufsize > 268435455L ) 
  bad = 18 ;
  if ( 65535L < 255 ) 
  bad = 19 ;
  if ( 95588L + hashextra > 268435455L ) 
  bad = 21 ;
  if ( ( hashoffset < 0 ) || ( hashoffset > 514 ) ) 
  bad = 42 ;
  if ( formatdefaultlength > maxint ) 
  bad = 31 ;
  if ( 2 * 268435455L < memtop - memmin ) 
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
    dateandtime ( eqtb [28951 ].cint , eqtb [28952 ].cint , eqtb [28953 ]
    .cint , eqtb [28954 ].cint ) ;
  } 
#endif /* INITEX */
  readyalready = 314159L ;
  lab1: selector = 17 ;
  tally = 0 ;
  termoffset = 0 ;
  fileoffset = 0 ;
  kcodepos = 0 ;
  if ( srcspecialsp || filelineerrorstylep || parsefirstlinep ) 
  fprintf ( stdout , "%s%s%s%s",  "This is e-pTeX, Version 3.14159265" , "-p3.7.1" ,   "-160201" , "-2.6" ) ;
  else
  fprintf ( stdout , "%s%s%s%s",  "This is e-pTeX, Version 3.14159265" , "-p3.7.1" ,   "-160201" , "-2.6" ) ;
  Fputs ( stdout ,  " (" ) ;
  Fputs ( stdout ,  conststringcast ( getencstring () ) ) ;
  putc ( ')' ,  stdout );
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
  if ( translatefilename ) 
  {
    Fputs ( stdout ,  " (" ) ;
    fputs ( translatefilename , stdout ) ;
    { putc ( ')' ,  stdout );  putc ( '\n',  stdout ); }
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
      ifstack [0 ]= -268435455L ;
      paramptr = 0 ;
      maxparamstack = 0 ;
      first = bufsize ;
      do {
	  buffer [first ]= 0 ;
	decr ( first ) ;
      } while ( ! ( first == 0 ) ) ;
      scannerstatus = 0 ;
      warningindex = -268435455L ;
      first = 1 ;
      curinput .statefield = 58 ;
      curinput .startfield = 1 ;
      curinput .indexfield = 0 ;
      line = 0 ;
      curinput .namefield = 0 ;
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
    == 1393 ) ) 
    {
      nonewcontrolsequence = false ;
      primitive ( 1452 , 74 , 3 ) ;
      primitive ( 1453 , 74 , 4 ) ;
      primitive ( 1454 , 74 , 10 ) ;
      primitive ( 815 , 120 , 10 ) ;
      primitive ( 542 , 115 , 1 ) ;
      primitive ( 816 , 120 , 11 ) ;
      primitive ( 817 , 120 , 12 ) ;
      primitive ( 818 , 120 , 13 ) ;
      primitive ( 819 , 120 , 14 ) ;
      primitive ( 820 , 120 , 15 ) ;
      primitive ( 821 , 120 , 16 ) ;
      primitive ( 1430 , 62 , 6 ) ;
      primitive ( 535 , 80 , 29540 ) ;
      primitive ( 536 , 80 , 29541 ) ;
      primitive ( 1455 , 74 , 7 ) ;
      primitive ( 1456 , 74 , 8 ) ;
      primitive ( 1457 , 74 , 9 ) ;
      primitive ( 869 , 117 , 27 ) ;
      primitive ( 1459 , 78 , 25071 ) ;
      primitive ( 1460 , 79 , 28995 ) ;
      primitive ( 1461 , 79 , 28996 ) ;
      primitive ( 1462 , 79 , 28997 ) ;
      primitive ( 1463 , 79 , 28998 ) ;
      primitive ( 1464 , 79 , 28999 ) ;
      primitive ( 1465 , 79 , 29000 ) ;
      primitive ( 1466 , 79 , 29001 ) ;
      primitive ( 1467 , 79 , 29002 ) ;
      primitive ( 1468 , 79 , 29003 ) ;
      primitive ( 1483 , 74 , 11 ) ;
      primitive ( 1484 , 74 , 12 ) ;
      primitive ( 1485 , 74 , 13 ) ;
      primitive ( 1486 , 74 , 14 ) ;
      primitive ( 1487 , 74 , 15 ) ;
      primitive ( 1488 , 74 , 18 ) ;
      primitive ( 1489 , 74 , 19 ) ;
      primitive ( 1490 , 74 , 20 ) ;
      primitive ( 1491 , 74 , 21 ) ;
      primitive ( 1492 , 74 , 22 ) ;
      primitive ( 1493 , 74 , 23 ) ;
      primitive ( 1494 , 74 , 24 ) ;
      primitive ( 1495 , 22 , 4 ) ;
      primitive ( 1497 , 22 , 5 ) ;
      primitive ( 1498 , 121 , 1 ) ;
      primitive ( 1499 , 121 , 5 ) ;
      primitive ( 1500 , 22 , 6 ) ;
      primitive ( 1504 , 91 , 2 ) ;
      primitive ( 974 , 52 , 1 ) ;
      primitive ( 1508 , 79 , 29004 ) ;
      primitive ( 1509 , 36 , 6 ) ;
      primitive ( 1510 , 36 , 7 ) ;
      primitive ( 1511 , 36 , 10 ) ;
      primitive ( 1512 , 36 , 11 ) ;
      primitive ( 1521 , 116 , 2 ) ;
      primitive ( 1523 , 107 , 1 ) ;
      primitive ( 868 , 114 , 1 ) ;
      primitive ( 1524 , 117 , 17 ) ;
      primitive ( 1525 , 117 , 18 ) ;
      primitive ( 1526 , 117 , 19 ) ;
      primitive ( 1310 , 104 , 8 ) ;
      primitive ( 1532 , 74 , 29 ) ;
      primitive ( 1533 , 74 , 30 ) ;
      primitive ( 1534 , 74 , 31 ) ;
      primitive ( 1535 , 74 , 32 ) ;
      primitive ( 1539 , 74 , 16 ) ;
      primitive ( 1540 , 74 , 17 ) ;
      primitive ( 1541 , 74 , 25 ) ;
      primitive ( 1542 , 74 , 26 ) ;
      primitive ( 1543 , 74 , 27 ) ;
      primitive ( 1544 , 74 , 28 ) ;
      primitive ( 1545 , 21 , 5 ) ;
      primitive ( 1546 , 122 , 5 ) ;
      primitive ( 1547 , 122 , 6 ) ;
      primitive ( 1548 , 122 , 7 ) ;
      primitive ( 1549 , 122 , 8 ) ;
      primitive ( 1550 , 122 , 9 ) ;
      primitive ( 1554 , 27 , 2 ) ;
      primitive ( 1555 , 27 , 3 ) ;
      primitive ( 1556 , 93 , 25328 ) ;
      primitive ( 1557 , 93 , 25329 ) ;
      primitive ( 1558 , 93 , 25330 ) ;
      primitive ( 1559 , 93 , 25331 ) ;
      if ( ( buffer [curinput .locfield ]== 42 ) ) 
      incr ( curinput .locfield ) ;
      eTeXmode = 1 ;
      maxregnum = 65535L ;
      maxreghelpline = 1551 ;
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
      eqtb = zeqtb ;
      while ( ( curinput .locfield < curinput .limitfield ) && ( buffer [
      curinput .locfield ]== 32 ) ) incr ( curinput .locfield ) ;
    } 
    if ( ( eTeXmode == 1 ) ) 
    fprintf ( stdout , "%s\n",  "entering extended mode" ) ;
    if ( ( eqtb [28980 ].cint < 0 ) || ( eqtb [28980 ].cint > 255 ) ) 
    decr ( curinput .limitfield ) ;
    else buffer [curinput .limitfield ]= eqtb [28980 ].cint ;
    if ( mltexenabledp ) 
    {
      fprintf ( stdout , "%s\n",  "MLTeX v2.2 enabled" ) ;
    } 
    dateandtime ( eqtb [28951 ].cint , eqtb [28952 ].cint , eqtb [28953 ]
    .cint , eqtb [28954 ].cint ) ;
    isprintutf8 = false ;
	;
#ifdef INITEX
    if ( trienotready ) 
    {
      trietrl = xmallocarray ( triepointer , triesize ) ;
      trietro = xmallocarray ( triepointer , triesize ) ;
      trietrc = xmallocarray ( quarterword , triesize ) ;
      triec = xmallocarray ( packedASCIIcode , triesize ) ;
      trieo = xmallocarray ( trieopcode , triesize ) ;
      triel = xmallocarray ( triepointer , triesize ) ;
      trier = xmallocarray ( triepointer , triesize ) ;
      triehash = xmallocarray ( triepointer , triesize ) ;
      trietaken = xmallocarray ( boolean , triesize ) ;
      triel [0 ]= 0 ;
      triec [0 ]= 0 ;
      trieptr = 0 ;
      trier [0 ]= 0 ;
      hyphstart = 0 ;
      fontdir = xmallocarray ( eightbits , fontmax ) ;
      fontnumext = xmallocarray ( integer , fontmax ) ;
      fontcheck = xmallocarray ( fourquarters , fontmax ) ;
      fontsize = xmallocarray ( scaled , fontmax ) ;
      fontdsize = xmallocarray ( scaled , fontmax ) ;
      fontparams = xmallocarray ( fontindex , fontmax ) ;
      fontname = xmallocarray ( strnumber , fontmax ) ;
      fontarea = xmallocarray ( strnumber , fontmax ) ;
      fontbc = xmallocarray ( eightbits , fontmax ) ;
      fontec = xmallocarray ( eightbits , fontmax ) ;
      fontglue = xmallocarray ( halfword , fontmax ) ;
      hyphenchar = xmallocarray ( integer , fontmax ) ;
      skewchar = xmallocarray ( integer , fontmax ) ;
      bcharlabel = xmallocarray ( fontindex , fontmax ) ;
      fontbchar = xmallocarray ( ninebits , fontmax ) ;
      fontfalsebchar = xmallocarray ( ninebits , fontmax ) ;
      ctypebase = xmallocarray ( integer , fontmax ) ;
      charbase = xmallocarray ( integer , fontmax ) ;
      widthbase = xmallocarray ( integer , fontmax ) ;
      heightbase = xmallocarray ( integer , fontmax ) ;
      depthbase = xmallocarray ( integer , fontmax ) ;
      italicbase = xmallocarray ( integer , fontmax ) ;
      ligkernbase = xmallocarray ( integer , fontmax ) ;
      kernbase = xmallocarray ( integer , fontmax ) ;
      extenbase = xmallocarray ( integer , fontmax ) ;
      parambase = xmallocarray ( integer , fontmax ) ;
      fontptr = 0 ;
      fmemptr = 7 ;
      fontdir [0 ]= 0 ;
      fontnumext [0 ]= 0 ;
      fontname [0 ]= 896 ;
      fontarea [0 ]= 343 ;
      hyphenchar [0 ]= 45 ;
      skewchar [0 ]= -1 ;
      bcharlabel [0 ]= 0 ;
      fontbchar [0 ]= 256 ;
      fontfalsebchar [0 ]= 256 ;
      fontbc [0 ]= 1 ;
      fontec [0 ]= 0 ;
      fontsize [0 ]= 0 ;
      fontdsize [0 ]= 0 ;
      ctypebase [0 ]= 0 ;
      charbase [0 ]= 0 ;
      widthbase [0 ]= 0 ;
      heightbase [0 ]= 0 ;
      depthbase [0 ]= 0 ;
      italicbase [0 ]= 0 ;
      ligkernbase [0 ]= 0 ;
      kernbase [0 ]= 0 ;
      extenbase [0 ]= 0 ;
      fontglue [0 ]= -268435455L ;
      fontparams [0 ]= 7 ;
      parambase [0 ]= -1 ;
      {register integer for_end; fontk = 0 ;for_end = 6 ; if ( fontk <= 
      for_end) do 
	fontinfo [fontk ].cint = 0 ;
      while ( fontk++ < for_end ) ;} 
    } 
#endif /* INITEX */
    fontused = xmallocarray ( boolean , fontmax ) ;
    {register integer for_end; fontk = 0 ;for_end = fontmax ; if ( fontk <= 
    for_end) do 
      fontused [fontk ]= false ;
    while ( fontk++ < for_end ) ;} 
    magicoffset = strstart [990 ]- 9 * 18 ;
    if ( interaction == 0 ) 
    selector = 16 ;
    else selector = 17 ;
    if ( ( curinput .locfield < curinput .limitfield ) && ( eqtb [26361 + 
    buffer [curinput .locfield ]].hh .v.RH != 0 ) ) 
    startinput () ;
  } 
  history = 0 ;
  synctexinitcommand () ;
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
