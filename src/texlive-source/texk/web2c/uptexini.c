#define EXTERN extern
#include "uptexd.h"

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
  curlist .lastjchrfield = -1073741823L ;
  curlist .auxfield .cint = -65536000L ;
  curlist .mlfield = 0 ;
  curlist .pgfield = 0 ;
  shownmode = 0 ;
  pagecontents = 0 ;
  pagetail = memtop - 2 ;
  lastglue = 1073741823L ;
  lastpenalty = 0 ;
  lastkern = 0 ;
  pagesofar [7 ]= 0 ;
  pagemaxdepth = 0 ;
  {register integer for_end; k = 28462 ;for_end = 29569 ; if ( k <= for_end) 
  do 
    xeqlevel [k ]= 1 ;
  while ( k++ < for_end ) ;} 
  nonewcontrolsequence = true ;
  saveptr = 0 ;
  curlevel = 1 ;
  curgroup = 0 ;
  curboundary = 0 ;
  maxsavestack = 0 ;
  magset = 0 ;
  skipmode = true ;
  expanddepthcount = 0 ;
  curmark [0 ]= -1073741823L ;
  curmark [1 ]= -1073741823L ;
  curmark [2 ]= -1073741823L ;
  curmark [3 ]= -1073741823L ;
  curmark [4 ]= -1073741823L ;
  curval = 0 ;
  curvallevel = 0 ;
  radix = 0 ;
  curorder = 0 ;
  {register integer for_end; k = 0 ;for_end = 16 ; if ( k <= for_end) do 
    readopen [k ]= 2 ;
  while ( k++ < for_end ) ;} 
  condptr = -1073741823L ;
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
  downptr = -1073741823L ;
  rightptr = -1073741823L ;
  adjusttail = -1073741823L ;
  lastbadness = 0 ;
  curkanjiskip = membot ;
  curxkanjiskip = membot ;
  packbeginline = 0 ;
  emptyfield .v.RH = 0 ;
  emptyfield .v.LH = -1073741823L ;
  nulldelimiter .b0 = 0 ;
  nulldelimiter .b1 = 0 ;
  nulldelimiter .b2 = 0 ;
  nulldelimiter .b3 = 0 ;
  alignptr = -1073741823L ;
  curalign = -1073741823L ;
  curspan = -1073741823L ;
  curloop = -1073741823L ;
  curhead = -1073741823L ;
  curtail = -1073741823L ;
  {register integer for_end; z = 0 ;for_end = hyphsize ; if ( z <= for_end) 
  do 
    {
      hyphword [z ]= 0 ;
      hyphlist [z ]= -1073741823L ;
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
    {register integer for_end; k = membot + 1 ;for_end = membot + 19 ; if ( 
    k <= for_end) do 
      mem [k ].cint = 0 ;
    while ( k++ < for_end ) ;} 
    k = membot ;
    while ( k <= membot + 19 ) {
	
      mem [k ].hh .v.RH = -1073741822L ;
      mem [k ].hh.b0 = 0 ;
      mem [k ].hh.b1 = 0 ;
      k = k + 4 ;
    } 
    mem [membot + 6 ].cint = 65536L ;
    mem [membot + 4 ].hh.b0 = 1 ;
    mem [membot + 10 ].cint = 65536L ;
    mem [membot + 8 ].hh.b0 = 2 ;
    mem [membot + 14 ].cint = 65536L ;
    mem [membot + 12 ].hh.b0 = 1 ;
    mem [membot + 15 ].cint = 65536L ;
    mem [membot + 12 ].hh.b1 = 1 ;
    mem [membot + 18 ].cint = -65536L ;
    mem [membot + 16 ].hh.b0 = 1 ;
    rover = membot + 20 ;
    mem [rover ].hh .v.RH = 1073741823L ;
    mem [rover ].hh .v.LH = 1000 ;
    mem [rover + 1 ].hh .v.LH = rover ;
    mem [rover + 1 ].hh .v.RH = rover ;
    lomemmax = rover + 1000 ;
    mem [lomemmax ].hh .v.RH = -1073741823L ;
    mem [lomemmax ].hh .v.LH = -1073741823L ;
    {register integer for_end; k = memtop - 13 ;for_end = memtop ; if ( k <= 
    for_end) do 
      mem [k ]= mem [lomemmax ];
    while ( k++ < for_end ) ;} 
    mem [memtop - 10 ].hh .v.LH = 536886430L ;
    mem [memtop - 9 ].hh .v.RH = 65536L ;
    mem [memtop - 9 ].hh .v.LH = -1073741823L ;
    mem [memtop - 7 ].hh.b0 = 1 ;
    mem [memtop - 6 ].hh .v.LH = 1073741823L ;
    mem [memtop - 7 ].hh.b1 = 0 ;
    mem [memtop ].hh.b1 = 255 ;
    mem [memtop ].hh.b0 = 1 ;
    mem [memtop ].hh .v.RH = memtop ;
    mem [memtop - 2 ].hh.b0 = 12 ;
    mem [memtop - 2 ].hh.b1 = 0 ;
    avail = -1073741823L ;
    memend = memtop ;
    himemmin = memtop - 13 ;
    varused = membot + 20 - membot ;
    dynused = 14 ;
    eqtb [24526 ].hh.b0 = 116 ;
    eqtb [24526 ].hh .v.RH = -1073741823L ;
    eqtb [24526 ].hh.b1 = 0 ;
    {register integer for_end; k = 1 ;for_end = eqtbtop ; if ( k <= for_end) 
    do 
      eqtb [k ]= eqtb [24526 ];
    while ( k++ < for_end ) ;} 
    eqtb [24527 ].hh .v.RH = membot ;
    eqtb [24527 ].hh.b1 = 1 ;
    eqtb [24527 ].hh.b0 = 132 ;
    {register integer for_end; k = 24528 ;for_end = 25059 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [24527 ];
    while ( k++ < for_end ) ;} 
    mem [membot ].hh .v.RH = mem [membot ].hh .v.RH + 533 ;
    eqtb [25060 ].hh .v.RH = -1073741823L ;
    eqtb [25060 ].hh.b0 = 133 ;
    eqtb [25060 ].hh.b1 = 1 ;
    {register integer for_end; k = 25061 ;for_end = 25325 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [24526 ];
    while ( k++ < for_end ) ;} 
    eqtb [25326 ].hh .v.RH = -1073741823L ;
    eqtb [25326 ].hh.b0 = 134 ;
    eqtb [25326 ].hh.b1 = 1 ;
    {register integer for_end; k = 25327 ;for_end = 25581 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [25326 ];
    while ( k++ < for_end ) ;} 
    eqtb [25582 ].hh .v.RH = 0 ;
    eqtb [25582 ].hh.b0 = 135 ;
    eqtb [25582 ].hh.b1 = 1 ;
    eqtb [25631 ].hh .v.RH = 0 ;
    eqtb [25631 ].hh.b0 = 135 ;
    eqtb [25631 ].hh.b1 = 1 ;
    eqtb [25632 ].hh .v.RH = 0 ;
    eqtb [25632 ].hh.b0 = 135 ;
    eqtb [25632 ].hh.b1 = 1 ;
    {register integer for_end; k = 25583 ;for_end = 25630 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [25582 ];
    while ( k++ < for_end ) ;} 
    eqtb [25636 ].hh .v.RH = 0 ;
    eqtb [25636 ].hh.b0 = 135 ;
    eqtb [25636 ].hh.b1 = 1 ;
    {register integer for_end; k = 25637 ;for_end = 28461 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [25636 ];
    while ( k++ < for_end ) ;} 
    eqtb [25633 ]= eqtb [25636 ];
    eqtb [25634 ]= eqtb [25636 ];
    eqtb [25635 ]= eqtb [25636 ];
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      {
	eqtb [25636 + k ].hh .v.RH = 12 ;
	eqtb [27950 + k ].hh .v.RH = k ;
	eqtb [27694 + k ].hh .v.RH = 1000 ;
	eqtb [26404 + k ].hh .v.RH = 0 ;
	eqtb [26660 + k ].hh .v.RH = 0 ;
	eqtb [26660 + k ].hh.b0 = 0 ;
	eqtb [26916 + k ].hh .v.RH = 0 ;
	eqtb [26916 + k ].hh.b0 = 0 ;
      } 
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 0 ;for_end = 512 ; if ( k <= for_end) do 
      {
	eqtb [25892 + k ].hh .v.RH = 18 ;
      } 
    while ( k++ < for_end ) ;} 
    eqtb [25649 ].hh .v.RH = 5 ;
    eqtb [25668 ].hh .v.RH = 10 ;
    eqtb [25728 ].hh .v.RH = 0 ;
    eqtb [25673 ].hh .v.RH = 14 ;
    eqtb [25763 ].hh .v.RH = 15 ;
    eqtb [25636 ].hh .v.RH = 9 ;
    {register integer for_end; k = 48 ;for_end = 57 ; if ( k <= for_end) do 
      {
	eqtb [27950 + k ].hh .v.RH = k + 28672 ;
	eqtb [26404 + k ].hh .v.RH = 3 ;
      } 
    while ( k++ < for_end ) ;} 
    eqtb [27172 ].hh .v.RH = toDVI ( fromJIS ( 8507 ) ) ;
    eqtb [27173 ].hh .v.RH = toDVI ( fromJIS ( 12396 ) ) ;
    eqtb [27174 ].hh .v.RH = toDVI ( fromJIS ( 18035 ) ) ;
    eqtb [27175 ].hh .v.RH = toDVI ( fromJIS ( 15152 ) ) ;
    eqtb [27176 ].hh .v.RH = toDVI ( fromJIS ( 15181 ) ) ;
    eqtb [27177 ].hh .v.RH = toDVI ( fromJIS ( 14430 ) ) ;
    eqtb [27178 ].hh .v.RH = toDVI ( fromJIS ( 20283 ) ) ;
    eqtb [27179 ].hh .v.RH = toDVI ( fromJIS ( 15415 ) ) ;
    eqtb [27180 ].hh .v.RH = toDVI ( fromJIS ( 18476 ) ) ;
    eqtb [27181 ].hh .v.RH = toDVI ( fromJIS ( 13925 ) ) ;
    {register integer for_end; k = 65 ;for_end = 90 ; if ( k <= for_end) do 
      {
	eqtb [25636 + k ].hh .v.RH = 11 ;
	eqtb [25636 + k + 32 ].hh .v.RH = 11 ;
	eqtb [27950 + k ].hh .v.RH = k + 28928 ;
	eqtb [27950 + k + 32 ].hh .v.RH = k + 28960 ;
	eqtb [27182 + k ].hh .v.RH = k + 32 ;
	eqtb [27182 + k + 32 ].hh .v.RH = k + 32 ;
	eqtb [27438 + k ].hh .v.RH = k ;
	eqtb [27438 + k + 32 ].hh .v.RH = k ;
	eqtb [26404 + k ].hh .v.RH = 3 ;
	eqtb [26404 + k + 32 ].hh .v.RH = 3 ;
	eqtb [27694 + k ].hh .v.RH = 999 ;
      } 
    while ( k++ < for_end ) ;} 
    if ( ( isinternalUPTEX () ) ) 
    {
      eqtb [25892 ].hh .v.RH = 15 ;
      eqtb [25927 ].hh .v.RH = 19 ;
      {register integer for_end; k = 100 ;for_end = 102 ; if ( k <= for_end) 
      do 
	eqtb [25892 + k ].hh .v.RH = 16 ;
      while ( k++ < for_end ) ;} 
      {register integer for_end; k = 104 ;for_end = 105 ; if ( k <= for_end) 
      do 
	eqtb [25892 + k ].hh .v.RH = 17 ;
      while ( k++ < for_end ) ;} 
      eqtb [25998 ].hh .v.RH = 16 ;
      eqtb [25999 ].hh .v.RH = 19 ;
      {register integer for_end; k = 108 ;for_end = 110 ; if ( k <= for_end) 
      do 
	eqtb [25892 + k ].hh .v.RH = 16 ;
      while ( k++ < for_end ) ;} 
      eqtb [26003 ].hh .v.RH = 17 ;
      eqtb [26006 ].hh .v.RH = 16 ;
      eqtb [26008 ].hh .v.RH = 16 ;
      eqtb [26024 ].hh .v.RH = 19 ;
      eqtb [26034 ].hh .v.RH = 19 ;
      eqtb [26035 ].hh .v.RH = 19 ;
      eqtb [26040 ].hh .v.RH = 16 ;
      eqtb [26113 ].hh .v.RH = 17 ;
      {register integer for_end; k = 244 ;for_end = 247 ; if ( k <= for_end) 
      do 
	eqtb [25892 + k ].hh .v.RH = 16 ;
      while ( k++ < for_end ) ;} 
      eqtb [26402 ].hh .v.RH = 17 ;
      eqtb [26403 ].hh .v.RH = 17 ;
    } 
    else {
	
      eqtb [25925 ].hh .v.RH = 18 ;
      eqtb [25926 ].hh .v.RH = 18 ;
      {register integer for_end; k = 3 ;for_end = 6 ; if ( k <= for_end) do 
	eqtb [25924 + k ].hh .v.RH = 17 ;
      while ( k++ < for_end ) ;} 
      {register integer for_end; k = 7 ;for_end = 13 ; if ( k <= for_end) do 
	eqtb [25924 + k ].hh .v.RH = 18 ;
      while ( k++ < for_end ) ;} 
      {register integer for_end; k = 14 ;for_end = 120 ; if ( k <= for_end) 
      do 
	eqtb [25924 + k ].hh .v.RH = 16 ;
      while ( k++ < for_end ) ;} 
      {register integer for_end; k = 16 ;for_end = 94 ; if ( k <= for_end) 
      do 
	eqtb [26052 + k ].hh .v.RH = 16 ;
      while ( k++ < for_end ) ;} 
    } 
    {register integer for_end; k = 28462 ;for_end = 28778 ; if ( k <= 
    for_end) do 
      eqtb [k ].cint = 0 ;
    while ( k++ < for_end ) ;} 
    eqtb [28519 ].cint = 256 ;
    eqtb [28520 ].cint = -1 ;
    eqtb [28479 ].cint = 1000 ;
    eqtb [28463 ].cint = 10000 ;
    eqtb [28503 ].cint = 1 ;
    eqtb [28502 ].cint = 25 ;
    eqtb [28508 ].cint = 92 ;
    eqtb [28511 ].cint = 13 ;
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      eqtb [28779 + k ].cint = -1 ;
    while ( k++ < for_end ) ;} 
    eqtb [28825 ].cint = 0 ;
    {register integer for_end; k = 29035 ;for_end = 29569 ; if ( k <= 
    for_end) do 
      eqtb [k ].cint = 0 ;
    while ( k++ < for_end ) ;} 
    hashused = 15514 ;
    hashhigh = 0 ;
    cscount = 0 ;
    eqtb [15523 ].hh.b0 = 131 ;
    hash [15523 ].v.RH = 534 ;
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
    hash [15514 ].v.RH = 1262 ;
    if ( iniversion ) 
    formatident = 1336 ;
    hash [15522 ].v.RH = 1378 ;
    eqtb [15522 ].hh.b1 = 1 ;
    eqtb [15522 ].hh.b0 = 128 ;
    eqtb [15522 ].hh .v.RH = -1073741823L ;
  } 
#endif /* INITEX */
  synctexoffset = 28522 ;
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
  smallnumber j  ;
  smallnumber l  ;
  if ( s < 256 ) 
  curval = s + 257 ;
  else {
      
    k = strstart [s ];
    l = strstart [s + 1 ]- k ;
    {register integer for_end; j = 0 ;for_end = l - 1 ; if ( j <= for_end) 
    do 
      buffer [j ]= strpool [k + j ];
    while ( j++ < for_end ) ;} 
    curval = idlookup ( 0 , l ) ;
    {
      decr ( strptr ) ;
      poolptr = strstart [strptr ];
    } 
    hash [curval ].v.RH = s ;
  } 
  eqtb [curval ].hh.b1 = 1 ;
  eqtb [curval ].hh.b0 = c ;
  eqtb [curval ].hh .v.RH = o ;
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
      overflow ( 1003 , trieopsize ) ;
      u = trieused [curlang ];
      if ( u == maxtrieop ) 
      overflow ( 1004 , maxtrieop - mintrieop ) ;
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
      overflow ( 1005 , triesize ) ;
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
    if ( eqtb [28513 ].cint <= 0 ) 
    curlang = 0 ;
    else if ( eqtb [28513 ].cint > 255 ) 
    curlang = 0 ;
    else curlang = eqtb [28513 ].cint ;
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
	      
	    curchr = eqtb [27182 + curchr ].hh .v.RH ;
	    if ( curchr == 0 ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 263 ) ;
		print ( 1011 ) ;
	      } 
	      {
		helpptr = 1 ;
		helpline [0 ]= 1010 ;
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
		overflow ( 1005 , triesize ) ;
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
		print ( 1012 ) ;
	      } 
	      {
		helpptr = 1 ;
		helpline [0 ]= 1010 ;
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
	    print ( 1009 ) ;
	  } 
	  printesc ( 1007 ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1010 ;
	  } 
	  error () ;
	} 
	break ;
      } 
    } 
    lab30: ;
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 263 ) ;
      print ( 1006 ) ;
    } 
    printesc ( 1007 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 1008 ;
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
  if ( triel [0 ]== 0 ) 
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
zlinebreak ( integer finalwidowpenalty ) 
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
    mem [curlist .tailfield ].hh .v.RH = -1073741823L ;
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
  initcurlang = curlist .pgfield % 65536L ;
  initlhyf = curlist .pgfield / 4194304L ;
  initrhyf = ( curlist .pgfield / 65536L ) % 64 ;
  popnest () ;
  noshrinkerroryet = true ;
  if ( ( mem [eqtb [24534 ].hh .v.RH ].hh.b1 != 0 ) && ( mem [eqtb [
  24534 ].hh .v.RH + 3 ].cint != 0 ) ) 
  {
    eqtb [24534 ].hh .v.RH = finiteshrink ( eqtb [24534 ].hh .v.RH ) ;
  } 
  if ( ( mem [eqtb [24535 ].hh .v.RH ].hh.b1 != 0 ) && ( mem [eqtb [
  24535 ].hh .v.RH + 3 ].cint != 0 ) ) 
  {
    eqtb [24535 ].hh .v.RH = finiteshrink ( eqtb [24535 ].hh .v.RH ) ;
  } 
  q = eqtb [24534 ].hh .v.RH ;
  r = eqtb [24535 ].hh .v.RH ;
  background [1 ]= mem [q + 1 ].cint + mem [r + 1 ].cint ;
  background [2 ]= 0 ;
  background [3 ]= 0 ;
  background [4 ]= 0 ;
  background [5 ]= 0 ;
  background [2 + mem [q ].hh.b0 ]= mem [q + 2 ].cint ;
  background [2 + mem [r ].hh.b0 ]= background [2 + mem [r ].hh.b0 ]+ 
  mem [r + 2 ].cint ;
  background [6 ]= mem [q + 3 ].cint + mem [r + 3 ].cint ;
  minimumdemerits = 1073741823L ;
  minimaldemerits [3 ]= 1073741823L ;
  minimaldemerits [2 ]= 1073741823L ;
  minimaldemerits [1 ]= 1073741823L ;
  minimaldemerits [0 ]= 1073741823L ;
  if ( eqtb [25060 ].hh .v.RH == -1073741823L ) {
      
    if ( eqtb [29052 ].cint == 0 ) 
    {
      lastspecialline = 0 ;
      secondwidth = eqtb [29038 ].cint ;
      secondindent = 0 ;
    } 
    else {
	
      lastspecialline = abs ( eqtb [28503 ].cint ) ;
      if ( eqtb [28503 ].cint < 0 ) 
      {
	firstwidth = eqtb [29038 ].cint - abs ( eqtb [29052 ].cint ) ;
	if ( eqtb [29052 ].cint >= 0 ) 
	firstindent = eqtb [29052 ].cint ;
	else firstindent = 0 ;
	secondwidth = eqtb [29038 ].cint ;
	secondindent = 0 ;
      } 
      else {
	  
	firstwidth = eqtb [29038 ].cint ;
	firstindent = 0 ;
	secondwidth = eqtb [29038 ].cint - abs ( eqtb [29052 ].cint ) ;
	if ( eqtb [29052 ].cint >= 0 ) 
	secondindent = eqtb [29052 ].cint ;
	else secondindent = 0 ;
      } 
    } 
  } 
  else {
      
    lastspecialline = mem [eqtb [25060 ].hh .v.RH ].hh .v.LH - 1 ;
    secondwidth = mem [eqtb [25060 ].hh .v.RH + 2 * ( lastspecialline + 1 ) 
    ].cint ;
    secondindent = mem [eqtb [25060 ].hh .v.RH + 2 * lastspecialline + 1 ]
    .cint ;
  } 
  if ( eqtb [28481 ].cint == 0 ) 
  easyline = lastspecialline ;
  else easyline = 1073741823L ;
  threshold = eqtb [28462 ].cint ;
  if ( threshold >= 0 ) 
  {
	;
#ifdef STAT
    if ( eqtb [28494 ].cint > 0 ) 
    {
      begindiagnostic () ;
      printnl ( 987 ) ;
    } 
#endif /* STAT */
    secondpass = false ;
    finalpass = false ;
  } 
  else {
      
    threshold = eqtb [28463 ].cint ;
    secondpass = true ;
    finalpass = ( eqtb [29055 ].cint <= 0 ) ;
	;
#ifdef STAT
    if ( eqtb [28494 ].cint > 0 ) 
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
    } 
    q = getnode ( 3 ) ;
    mem [q ].hh.b0 = 0 ;
    mem [q ].hh.b1 = 2 ;
    mem [q ].hh .v.RH = memtop - 7 ;
    mem [q + 1 ].hh .v.RH = -1073741823L ;
    mem [q + 1 ].hh .v.LH = curlist .pgfield + 1 ;
    mem [q + 2 ].cint = 0 ;
    mem [memtop - 7 ].hh .v.RH = q ;
    activewidth [1 ]= background [1 ];
    activewidth [2 ]= background [2 ];
    activewidth [3 ]= background [3 ];
    activewidth [4 ]= background [4 ];
    activewidth [5 ]= background [5 ];
    activewidth [6 ]= background [6 ];
    passive = -1073741823L ;
    printednode = memtop - 3 ;
    passnumber = 0 ;
    fontinshortdisplay = 0 ;
    curp = mem [memtop - 3 ].hh .v.RH ;
    autobreaking = true ;
    prevp = curp ;
    while ( ( curp != -1073741823L ) && ( mem [memtop - 7 ].hh .v.RH != 
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
	      activewidth [6 ]= activewidth [6 ]+ mem [curkanjiskip + 3 ]
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
	  activewidth [6 ]= activewidth [6 ]+ mem [q + 3 ].cint ;
	  if ( secondpass && autobreaking ) 
	  {
	    prevs = curp ;
	    s = mem [prevs ].hh .v.RH ;
	    if ( s != -1073741823L ) 
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
		    
		  if ( mem [s + 1 ].hh .v.RH == -1073741823L ) 
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
		else if ( mem [s ].hh.b0 == 10 ) 
		{
		  if ( mem [s ].hh.b1 == 4 ) 
		  {
		    curlang = mem [s + 1 ].hh .v.RH ;
		    lhyf = mem [s + 1 ].hh.b0 ;
		    rhyf = mem [s + 1 ].hh.b1 ;
		  } 
		  goto lab22 ;
		} 
		else goto lab31 ;
		if ( eqtb [27182 + c ].hh .v.RH != 0 ) {
		    
		  if ( ( eqtb [27182 + c ].hh .v.RH == c ) || ( eqtb [28500 
		  ].cint > 0 ) ) 
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
		  if ( eqtb [27182 + c ].hh .v.RH == 0 ) 
		  goto lab33 ;
		  if ( hn == 63 ) 
		  goto lab33 ;
		  hb = s ;
		  incr ( hn ) ;
		  hu [hn ]= c ;
		  hc [hn ]= eqtb [27182 + c ].hh .v.RH ;
		  hyfbchar = 256 ;
		} 
		else if ( mem [s ].hh.b0 == 8 ) 
		{
		  if ( mem [s + 1 ].hh.b0 != hf ) 
		  goto lab33 ;
		  j = hn ;
		  q = mem [s + 1 ].hh .v.RH ;
		  if ( q > -1073741823L ) 
		  hyfbchar = mem [q ].hh.b1 ;
		  while ( q > -1073741823L ) {
		      
		    c = mem [q ].hh.b1 ;
		    if ( eqtb [27182 + c ].hh .v.RH == 0 ) 
		    goto lab33 ;
		    if ( j == 63 ) 
		    goto lab33 ;
		    incr ( j ) ;
		    hu [j ]= c ;
		    hc [j ]= eqtb [27182 + c ].hh .v.RH ;
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
	  if ( s == -1073741823L ) 
	  trybreak ( eqtb [28466 ].cint , 1 ) ;
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
		confusion ( 991 ) ;
		break ;
	      } 
	      s = mem [s ].hh .v.RH ;
	    } while ( ! ( s == -1073741823L ) ) ;
	    activewidth [1 ]= activewidth [1 ]+ discwidth ;
	    trybreak ( eqtb [28465 ].cint , 1 ) ;
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
	      confusion ( 992 ) ;
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
	  autobreaking = ( mem [curp ].hh.b1 == 1 ) ;
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
	confusion ( 990 ) ;
	break ;
      } 
      prevp = curp ;
      curp = mem [curp ].hh .v.RH ;
      lab35: ;
    } 
    if ( curp == -1073741823L ) 
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
	if ( eqtb [28481 ].cint == 0 ) 
	goto lab30 ;
	{
	  r = mem [memtop - 7 ].hh .v.RH ;
	  actuallooseness = 0 ;
	  do {
	      if ( mem [r ].hh.b0 != 2 ) 
	    {
	      linediff = mem [r + 1 ].hh .v.LH - bestline ;
	      if ( ( ( linediff < actuallooseness ) && ( eqtb [28481 ].cint 
	      <= linediff ) ) || ( ( linediff > actuallooseness ) && ( eqtb [
	      28481 ].cint >= linediff ) ) ) 
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
	if ( ( actuallooseness == eqtb [28481 ].cint ) || finalpass ) 
	goto lab30 ;
      } 
    } 
    q = mem [memtop - 7 ].hh .v.RH ;
    while ( q != memtop - 7 ) {
	
      curp = mem [q ].hh .v.RH ;
      if ( mem [q ].hh.b0 == 2 ) 
      freenode ( q , 7 ) ;
      else freenode ( q , 3 ) ;
      q = curp ;
    } 
    q = passive ;
    while ( q != -1073741823L ) {
	
      curp = mem [q ].hh .v.RH ;
      freenode ( q , 2 ) ;
      q = curp ;
    } 
    if ( ! secondpass ) 
    {
	;
#ifdef STAT
      if ( eqtb [28494 ].cint > 0 ) 
      printnl ( 988 ) ;
#endif /* STAT */
      threshold = eqtb [28463 ].cint ;
      secondpass = true ;
      finalpass = ( eqtb [29055 ].cint <= 0 ) ;
    } 
    else {
	
	;
#ifdef STAT
      if ( eqtb [28494 ].cint > 0 ) 
      printnl ( 989 ) ;
#endif /* STAT */
      background [2 ]= background [2 ]+ eqtb [29055 ].cint ;
      finalpass = true ;
    } 
  } 
  lab30: 
	;
#ifdef STAT
  if ( eqtb [28494 ].cint > 0 ) 
  {
    enddiagnostic ( true ) ;
    normalizeselector () ;
  } 
#endif /* STAT */
  postlinebreak ( finalwidowpenalty ) ;
  q = mem [memtop - 7 ].hh .v.RH ;
  while ( q != memtop - 7 ) {
      
    curp = mem [q ].hh .v.RH ;
    if ( mem [q ].hh.b0 == 2 ) 
    freenode ( q , 7 ) ;
    else freenode ( q , 3 ) ;
    q = curp ;
  } 
  q = passive ;
  while ( q != -1073741823L ) {
      
    curp = mem [q ].hh .v.RH ;
    freenode ( q , 2 ) ;
    q = curp ;
  } 
  packbeginline = 0 ;
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
  while ( curcmd == 106 ) {
      
    if ( ! odd ( a / curchr ) ) 
    a = a + curchr ;
    do {
	getxtoken () ;
    } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
    if ( curcmd <= 78 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 263 ) ;
	print ( 1251 ) ;
      } 
      printcmdchr ( curcmd , curchr ) ;
      printchar ( 39 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 1252 ;
      } 
      backerror () ;
      return ;
    } 
  } 
  if ( ( curcmd != 110 ) && ( a % 4 != 0 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 263 ) ;
      print ( 723 ) ;
    } 
    printesc ( 1243 ) ;
    print ( 1253 ) ;
    printesc ( 1244 ) ;
    print ( 1254 ) ;
    printcmdchr ( curcmd , curchr ) ;
    printchar ( 39 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 1255 ;
    } 
    error () ;
  } 
  if ( eqtb [28505 ].cint != 0 ) {
      
    if ( eqtb [28505 ].cint < 0 ) 
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
  {case 98 : 
    {
      if ( fontdir [curchr ]== 4 ) {
	  
	if ( ( a >= 4 ) ) 
	geqdefine ( 25631 , 135 , curchr ) ;
	else eqdefine ( 25631 , 135 , curchr ) ;
      } 
      else if ( fontdir [curchr ]== 3 ) {
	  
	if ( ( a >= 4 ) ) 
	geqdefine ( 25632 , 135 , curchr ) ;
	else eqdefine ( 25632 , 135 , curchr ) ;
      } 
      else if ( ( a >= 4 ) ) 
      geqdefine ( 25582 , 135 , curchr ) ;
      else eqdefine ( 25582 , 135 , curchr ) ;
    } 
    break ;
  case 110 : 
    {
      if ( odd ( curchr ) && ! ( a >= 4 ) && ( eqtb [28505 ].cint >= 0 ) ) 
      a = a + 4 ;
      e = ( curchr >= 2 ) ;
      getrtoken () ;
      p = curcs ;
      q = scantoks ( true , e ) ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 126 + ( a % 4 ) , defref ) ;
      else eqdefine ( p , 126 + ( a % 4 ) , defref ) ;
    } 
    break ;
  case 107 : 
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
      if ( curcmd >= 126 ) 
      incr ( mem [curchr ].hh .v.LH ) ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , curcmd , curchr ) ;
      else eqdefine ( p , curcmd , curchr ) ;
    } 
    break ;
  case 108 : 
    if ( curchr == 7 ) 
    {
      scancharnum () ;
      p = 28206 + curval ;
      scanoptionalequals () ;
      scancharnum () ;
      n = curval ;
      scancharnum () ;
      if ( ( eqtb [28521 ].cint > 0 ) ) 
      {
	begindiagnostic () ;
	printnl ( 1274 ) ;
	print ( p - 28206 ) ;
	print ( 1275 ) ;
	print ( n ) ;
	printchar ( 32 ) ;
	print ( curval ) ;
	enddiagnostic ( false ) ;
      } 
      n = n * 256 + curval ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 135 , n ) ;
      else eqdefine ( p , 135 , n ) ;
      if ( ( p - 28206 ) < eqtb [28519 ].cint ) {
	  
	if ( ( a >= 4 ) ) 
	geqworddefine ( 28519 , p - 28206 ) ;
	else eqworddefine ( 28519 , p - 28206 ) ;
      } 
      if ( ( p - 28206 ) > eqtb [28520 ].cint ) {
	  
	if ( ( a >= 4 ) ) 
	geqworddefine ( 28520 , p - 28206 ) ;
	else eqworddefine ( 28520 , p - 28206 ) ;
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
	  geqdefine ( p , 73 , curval ) ;
	  else eqdefine ( p , 73 , curval ) ;
	} 
	break ;
      case 8 : 
	{
	  scancharnum () ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 74 , curval ) ;
	  else eqdefine ( p , 74 , curval ) ;
	} 
	break ;
      case 1 : 
	{
	  scanfifteenbitint () ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 75 , curval ) ;
	  else eqdefine ( p , 75 , curval ) ;
	} 
	break ;
	default: 
	{
	  scaneightbitint () ;
	  switch ( n ) 
	  {case 2 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 81 , 28523 + curval ) ;
	    else eqdefine ( p , 81 , 28523 + curval ) ;
	    break ;
	  case 3 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 82 , 29058 + curval ) ;
	    else eqdefine ( p , 82 , 29058 + curval ) ;
	    break ;
	  case 4 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 83 , 24548 + curval ) ;
	    else eqdefine ( p , 83 , 24548 + curval ) ;
	    break ;
	  case 5 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 84 , 24804 + curval ) ;
	    else eqdefine ( p , 84 , 24804 + curval ) ;
	    break ;
	  case 6 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 80 , 25070 + curval ) ;
	    else eqdefine ( p , 80 , 25070 + curval ) ;
	    break ;
	  } 
	} 
	break ;
      } 
    } 
    break ;
  case 109 : 
    {
      scanint () ;
      n = curval ;
      if ( ! scankeyword ( 895 ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 1138 ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1276 ;
	  helpline [0 ]= 1277 ;
	} 
	error () ;
      } 
      getrtoken () ;
      p = curcs ;
      readtoks ( n , p ) ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 126 , curval ) ;
      else eqdefine ( p , 126 , curval ) ;
    } 
    break ;
  case 79 : 
  case 80 : 
    {
      q = curcs ;
      if ( curcmd == 79 ) 
      {
	scaneightbitint () ;
	p = 25070 + curval ;
      } 
      else p = curchr ;
      scanoptionalequals () ;
      do {
	  getxtoken () ;
      } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
      if ( curcmd != 1 ) 
      {
	if ( curcmd == 79 ) 
	{
	  scaneightbitint () ;
	  curcmd = 80 ;
	  curchr = 25070 + curval ;
	} 
	if ( curcmd == 80 ) 
	{
	  q = eqtb [curchr ].hh .v.RH ;
	  if ( q == -1073741823L ) {
	      
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 116 , -1073741823L ) ;
	    else eqdefine ( p , 116 , -1073741823L ) ;
	  } 
	  else {
	      
	    incr ( mem [q ].hh .v.LH ) ;
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 126 , q ) ;
	    else eqdefine ( p , 126 , q ) ;
	  } 
	  goto lab30 ;
	} 
      } 
      backinput () ;
      curcs = q ;
      q = scantoks ( false , false ) ;
      if ( mem [defref ].hh .v.RH == -1073741823L ) 
      {
	if ( ( a >= 4 ) ) 
	geqdefine ( p , 116 , -1073741823L ) ;
	else eqdefine ( p , 116 , -1073741823L ) ;
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
	  
	if ( p == 25061 ) 
	{
	  mem [q ].hh .v.RH = getavail () ;
	  q = mem [q ].hh .v.RH ;
	  mem [q ].hh .v.LH = 637 ;
	  q = getavail () ;
	  mem [q ].hh .v.LH = 379 ;
	  mem [q ].hh .v.RH = mem [defref ].hh .v.RH ;
	  mem [defref ].hh .v.RH = q ;
	} 
	if ( ( a >= 4 ) ) 
	geqdefine ( p , 126 , defref ) ;
	else eqdefine ( p , 126 , defref ) ;
      } 
    } 
    break ;
  case 81 : 
    {
      p = curchr ;
      scanoptionalequals () ;
      scanint () ;
      if ( p == 28506 ) 
      {
	if ( fontdir [eqtb [25583 + curval ].hh .v.RH ]!= 0 ) {
	    
	  if ( ( a >= 4 ) ) 
	  geqworddefine ( 28507 , curval ) ;
	  else eqworddefine ( 28507 , curval ) ;
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
  case 82 : 
    {
      p = curchr ;
      scanoptionalequals () ;
      scandimen ( false , false , false ) ;
      if ( ( a >= 4 ) ) 
      geqworddefine ( p , curval ) ;
      else eqworddefine ( p , curval ) ;
    } 
    break ;
  case 83 : 
  case 84 : 
    {
      p = curchr ;
      n = curcmd ;
      scanoptionalequals () ;
      if ( n == 84 ) 
      scanglue ( 3 ) ;
      else scanglue ( 2 ) ;
      trapzeroglue () ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 132 , curval ) ;
      else eqdefine ( p , 132 , curval ) ;
    } 
    break ;
  case 96 : 
    {
      if ( curchr == 25892 ) 
      m = 15 ;
      else m = 0 ;
      if ( curchr == 25636 ) 
      n = 15 ;
      else if ( curchr == 25892 ) 
      n = 19 ;
      else if ( curchr == 27950 ) 
      n = 32768L ;
      else if ( curchr == 27694 ) 
      n = 32767 ;
      else if ( curchr == 28779 ) 
      n = 16777215L ;
      else n = 255 ;
      p = curchr ;
      scancharnum () ;
      if ( p == 25892 ) 
      p = p + kcatcodekey ( curval ) ;
      else if ( ! ischarascii ( curval ) ) 
      p = p + Hi ( curval ) ;
      else p = p + curval ;
      scanoptionalequals () ;
      scanint () ;
      if ( ( ( curval < m ) && ( p < 28779 ) ) || ( curval > n ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 1278 ) ;
	} 
	printint ( curval ) ;
	if ( p < 28779 ) 
	{
	  print ( 1279 ) ;
	  printint ( m ) ;
	  print ( 1280 ) ;
	} 
	else print ( 1281 ) ;
	printint ( n ) ;
	if ( m == 0 ) 
	{
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1282 ;
	  } 
	  error () ;
	} 
	else {
	    
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1283 ;
	  } 
	  error () ;
	} 
	curval = m ;
      } 
      if ( p < 27950 ) {
	  
	if ( ( a >= 4 ) ) 
	geqdefine ( p , 135 , curval ) ;
	else eqdefine ( p , 135 , curval ) ;
      } 
      else if ( p < 28779 ) {
	  
	if ( ( a >= 4 ) ) 
	geqdefine ( p , 135 , curval ) ;
	else eqdefine ( p , 135 , curval ) ;
      } 
      else if ( ( a >= 4 ) ) 
      geqworddefine ( p , curval ) ;
      else eqworddefine ( p , curval ) ;
    } 
    break ;
  case 97 : 
    {
      p = curchr ;
      scanfourbitint () ;
      p = p + curval ;
      scanoptionalequals () ;
      scanfontident () ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 135 , curval ) ;
      else eqdefine ( p , 135 , curval ) ;
    } 
    break ;
  case 102 : 
  case 103 : 
  case 104 : 
  case 105 : 
    doregistercommand ( a ) ;
    break ;
  case 111 : 
    {
      scaneightbitint () ;
      if ( ( a >= 4 ) ) 
      n = 256 + curval ;
      else n = curval ;
      scanoptionalequals () ;
      if ( setboxallowed ) 
      scanbox ( 1073741824L + n ) ;
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 718 ) ;
	} 
	printesc ( 571 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1289 ;
	  helpline [0 ]= 1290 ;
	} 
	error () ;
      } 
    } 
    break ;
  case 90 : 
    alteraux () ;
    break ;
  case 91 : 
    alterprevgraf () ;
    break ;
  case 92 : 
    alterpagesofar () ;
    break ;
  case 93 : 
    alterinteger () ;
    break ;
  case 94 : 
    alterboxdimen () ;
    break ;
  case 95 : 
    {
      scanoptionalequals () ;
      scanint () ;
      n = curval ;
      if ( n <= 0 ) 
      p = -1073741823L ;
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
      geqdefine ( 25060 , 133 , p ) ;
      else eqdefine ( 25060 , 133 , p ) ;
    } 
    break ;
  case 112 : 
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
	print ( 1294 ) ;
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
  case 85 : 
    {
      findfontdimen ( true ) ;
      k = curval ;
      scanoptionalequals () ;
      scandimen ( false , false , false ) ;
      fontinfo [k ].cint = curval ;
    } 
    break ;
  case 86 : 
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
  case 101 : 
  case 100 : 
  case 99 : 
    newfont ( a ) ;
    break ;
  case 113 : 
    newinteraction () ;
    break ;
  case 89 : 
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
	  print ( 1397 ) ;
	} 
	printhex ( curval ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1398 ;
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
	  print ( 1399 ) ;
	} 
	printint ( n ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1398 ;
	} 
	error () ;
	return ;
      } 
      else if ( ( a >= 4 ) ) 
      geqdefine ( 27172 + n , n , toDVI ( curval ) ) ;
      else eqdefine ( 27172 + n , n , toDVI ( curval ) ) ;
    } 
    break ;
  case 114 : 
    {
      if ( curchr < 2 ) 
      p = 25633 ;
      else {
	  
	p = 25634 ;
	curchr = ( curchr % 2 ) ;
      } 
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 135 , curchr ) ;
      else eqdefine ( p , 135 , curchr ) ;
    } 
    break ;
  case 115 : 
    if ( ( a >= 4 ) ) 
    geqdefine ( 25635 , 135 , curchr ) ;
    else eqdefine ( 25635 , 135 , curchr ) ;
    break ;
  case 88 : 
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
	    print ( 1421 ) ;
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1398 ;
	  } 
	  error () ;
	  return ;
	} 
	if ( ( a >= 4 ) ) 
	geqdefine ( 26660 + j , curval , n ) ;
	else eqdefine ( 26660 + j , curval , n ) ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 1422 ) ;
	} 
	printhex ( n ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1398 ;
	} 
	error () ;
	return ;
      } 
    } 
    break ;
  case 87 : 
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
	    print ( 1428 ) ;
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1398 ;
	  } 
	  error () ;
	  return ;
	} 
	if ( ( p == 1 ) || ( p == 2 ) ) 
	{
	  if ( ( a >= 4 ) ) 
	  geqdefine ( 26916 + j , p , n ) ;
	  else eqdefine ( 26916 + j , p , n ) ;
	  if ( ( a >= 4 ) ) 
	  geqworddefine ( 29314 + j , curval ) ;
	  else eqworddefine ( 29314 + j , curval ) ;
	} 
	else confusion ( 532 ) ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 263 ) ;
	  print ( 1429 ) ;
	} 
	if ( p == 1 ) 
	print ( 1430 ) ;
	else if ( p == 2 ) 
	print ( 1431 ) ;
	else printchar ( 63 ) ;
	print ( 1432 ) ;
	printhex ( n ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1398 ;
	} 
	error () ;
	return ;
      } 
    } 
    break ;
    default: 
    confusion ( 1250 ) ;
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
      print ( 1337 ) ;
    } 
    {
      helpptr = 1 ;
      helpline [0 ]= 1338 ;
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
  print ( 1354 ) ;
  print ( jobname ) ;
  printchar ( 32 ) ;
  printint ( eqtb [28485 ].cint ) ;
  printchar ( 46 ) ;
  printint ( eqtb [28484 ].cint ) ;
  printchar ( 46 ) ;
  printint ( eqtb [28483 ].cint ) ;
  printchar ( 41 ) ;
  if ( interaction == 0 ) 
  selector = 18 ;
  else selector = 19 ;
  {
    if ( poolptr + 1 > poolsize ) 
    overflow ( 258 , poolsize - initpoolptr ) ;
  } 
  formatident = makestring () ;
  packjobname ( 836 ) ;
  while ( ! wopenout ( fmtfile ) ) promptfilename ( 1355 , 836 ) ;
  printnl ( 1356 ) ;
  slowprint ( wmakenamestring ( fmtfile ) ) ;
  {
    decr ( strptr ) ;
    poolptr = strstart [strptr ];
  } 
  printnl ( 344 ) ;
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
  dumpkanji ( fmtfile ) ;
  dumpint ( 180881673L ) ;
  dumpthings ( xord [0 ], 256 ) ;
  dumpthings ( xchr [0 ], 256 ) ;
  dumpthings ( xprn [0 ], 256 ) ;
  dumpint ( 1073741823L ) ;
  dumpint ( hashhigh ) ;
  dumpint ( membot ) ;
  dumpint ( memtop ) ;
  dumpint ( 29569 ) ;
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
  print ( 1339 ) ;
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
  while ( p != -1073741823L ) {
      
    decr ( dynused ) ;
    p = mem [p ].hh .v.RH ;
  } 
  dumpint ( varused ) ;
  dumpint ( dynused ) ;
  println () ;
  printint ( x ) ;
  print ( 1340 ) ;
  printint ( varused ) ;
  printchar ( 38 ) ;
  printint ( dynused ) ;
  k = 1 ;
  do {
      j = k ;
    while ( j < 28461 ) {
	
      if ( ( eqtb [j ].hh .v.RH == eqtb [j + 1 ].hh .v.RH ) && ( eqtb [j 
      ].hh.b0 == eqtb [j + 1 ].hh.b0 ) && ( eqtb [j ].hh.b1 == eqtb [j + 
      1 ].hh.b1 ) ) 
      goto lab41 ;
      incr ( j ) ;
    } 
    l = 28462 ;
    goto lab31 ;
    lab41: incr ( j ) ;
    l = j ;
    while ( j < 28461 ) {
	
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
  } while ( ! ( k == 28462 ) ) ;
  do {
      j = k ;
    while ( j < 29569 ) {
	
      if ( eqtb [j ].cint == eqtb [j + 1 ].cint ) 
      goto lab42 ;
      incr ( j ) ;
    } 
    l = 29570 ;
    goto lab32 ;
    lab42: incr ( j ) ;
    l = j ;
    while ( j < 29569 ) {
	
      if ( eqtb [j ].cint != eqtb [j + 1 ].cint ) 
      goto lab32 ;
      incr ( j ) ;
    } 
    lab32: dumpint ( l - k ) ;
    dumpthings ( eqtb [k ], l - k ) ;
    k = j + 1 ;
    dumpint ( k - l ) ;
  } while ( ! ( k > 29569 ) ) ;
  if ( hashhigh > 0 ) 
  dumpthings ( eqtb [29570 ], hashhigh ) ;
  dumpint ( parloc ) ;
  dumpint ( writeloc ) ;
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
  dumpthings ( hash [hashused + 1 ], 24525 - hashused ) ;
  if ( hashhigh > 0 ) 
  dumpthings ( hash [29570 ], hashhigh ) ;
  dumpint ( cscount ) ;
  println () ;
  printint ( cscount ) ;
  print ( 1341 ) ;
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
	printnl ( 1345 ) ;
	printesc ( hash [15525 + k ].v.RH ) ;
	printchar ( 61 ) ;
	printfilename ( fontname [k ], fontarea [k ], 344 ) ;
	if ( fontsize [k ]!= fontdsize [k ]) 
	{
	  print ( 787 ) ;
	  printscaled ( fontsize [k ]) ;
	  print ( 416 ) ;
	} 
      } 
    while ( k++ < for_end ) ;} 
  } 
  println () ;
  printint ( fmemptr - 7 ) ;
  print ( 1342 ) ;
  printint ( fontptr - 0 ) ;
  if ( fontptr != 1 ) 
  print ( 1343 ) ;
  else print ( 1344 ) ;
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
  print ( 1346 ) ;
  else print ( 1347 ) ;
  if ( trienotready ) 
  inittrie () ;
  dumpint ( triemax ) ;
  dumpthings ( trietrl [0 ], triemax + 1 ) ;
  dumpthings ( trietro [0 ], triemax + 1 ) ;
  dumpthings ( trietrc [0 ], triemax + 1 ) ;
  dumpint ( trieopptr ) ;
  dumpthings ( hyfdistance [1 ], trieopptr ) ;
  dumpthings ( hyfnum [1 ], trieopptr ) ;
  dumpthings ( hyfnext [1 ], trieopptr ) ;
  printnl ( 1348 ) ;
  printint ( triemax ) ;
  print ( 1349 ) ;
  printint ( trieopptr ) ;
  if ( trieopptr != 1 ) 
  print ( 1350 ) ;
  else print ( 1351 ) ;
  print ( 1352 ) ;
  printint ( trieopsize ) ;
  {register integer for_end; k = 255 ;for_end = 0 ; if ( k >= for_end) do 
    if ( trieused [k ]> 0 ) 
    {
      printnl ( 852 ) ;
      printint ( trieused [k ]) ;
      print ( 1353 ) ;
      printint ( k ) ;
      dumpint ( k ) ;
      dumpint ( trieused [k ]) ;
    } 
  while ( k-- > for_end ) ;} 
  dumpint ( interaction ) ;
  dumpint ( formatident ) ;
  dumpint ( 69069L ) ;
  eqtb [28493 ].cint = 0 ;
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
  undumpkanji ( fmtfile ) ;
  undumpint ( x ) ;
  if ( debugformatfile ) 
  {
    fprintf ( stderr , "%s%s",  "fmtdebug:" , "string pool checksum" ) ;
    fprintf ( stderr , "%s%ld\n",  " = " , (long)x ) ;
  } 
  if ( x != 180881673L ) 
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
  if ( x != 1073741823L ) 
  goto lab6666 ;
  undumpint ( hashhigh ) ;
  if ( ( hashhigh < 0 ) || ( hashhigh > suphashextra ) ) 
  goto lab6666 ;
  if ( hashextra < hashhigh ) 
  hashextra = hashhigh ;
  eqtbtop = 29569 + hashextra ;
  if ( hashextra == 0 ) 
  hashtop = 24526 ;
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
  eqtb [24526 ].hh.b0 = 116 ;
  eqtb [24526 ].hh .v.RH = -1073741823L ;
  eqtb [24526 ].hh.b1 = 0 ;
  {register integer for_end; x = 29570 ;for_end = eqtbtop ; if ( x <= 
  for_end) do 
    eqtb [x ]= eqtb [24526 ];
  while ( x++ < for_end ) ;} 
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
  if ( x != 29569 ) 
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
    if ( ( x < membot + 1019 ) || ( x > memtop - 14 ) ) 
    goto lab6666 ;
    else lomemmax = x ;
  } 
  {
    undumpint ( x ) ;
    if ( ( x < membot + 20 ) || ( x > lomemmax ) ) 
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
    mem [memmin ].hh .v.RH = -1073741823L ;
    mem [memmin ].hh .v.LH = -1073741823L ;
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
    if ( ( x < -1073741823L ) || ( x > memtop ) ) 
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
    if ( ( x < 1 ) || ( k + x > 29570 ) ) 
    goto lab6666 ;
    undumpthings ( eqtb [k ], x ) ;
    k = k + x ;
    undumpint ( x ) ;
    if ( ( x < 0 ) || ( k + x > 29570 ) ) 
    goto lab6666 ;
    {register integer for_end; j = k ;for_end = k + x - 1 ; if ( j <= 
    for_end) do 
      eqtb [j ]= eqtb [k - 1 ];
    while ( j++ < for_end ) ;} 
    k = k + x ;
  } while ( ! ( k > 29569 ) ) ;
  if ( hashhigh > 0 ) 
  undumpthings ( eqtb [29570 ], hashhigh ) ;
  {
    undumpint ( x ) ;
    if ( ( x < 514 ) || ( x > hashtop ) ) 
    goto lab6666 ;
    else parloc = x ;
  } 
  partoken = 536870911L + parloc ;
  {
    undumpint ( x ) ;
    if ( ( x < 514 ) || ( x > hashtop ) ) 
    goto lab6666 ;
    else
    writeloc = x ;
  } 
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
  undumpthings ( hash [hashused + 1 ], 24525 - hashused ) ;
  if ( debugformatfile ) 
  {
    printcsnames ( 514 , 24525 ) ;
  } 
  if ( hashhigh > 0 ) 
  {
    undumpthings ( hash [29570 ], hashhigh ) ;
    if ( debugformatfile ) 
    {
      printcsnames ( 29570 , hashhigh - ( 29570 ) ) ;
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
    undumpcheckedthings ( -1073741823L , 1073741823L , fontparams [0 ], 
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
    undumpcheckedthings ( -1073741823L , lomemmax , fontglue [0 ], fontptr + 
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
	if ( ( x < -1073741823L ) || ( x > 1073741823L ) ) 
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
      
    print ( 1358 ) ;
    decr ( openparens ) ;
  } 
  if ( curlevel > 1 ) 
  {
    printnl ( 40 ) ;
    printesc ( 1359 ) ;
    print ( 1360 ) ;
    printint ( curlevel - 1 ) ;
    printchar ( 41 ) ;
  } 
  while ( condptr != -1073741823L ) {
      
    printnl ( 40 ) ;
    printesc ( 1359 ) ;
    print ( 1361 ) ;
    printcmdchr ( 120 , curif ) ;
    if ( ifline != 0 ) 
    {
      print ( 1362 ) ;
      printint ( ifline ) ;
    } 
    print ( 1363 ) ;
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
	printnl ( 1364 ) ;
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
	if ( curmark [c ]!= -1073741823L ) 
	deletetokenref ( curmark [c ]) ;
      while ( c++ < for_end ) ;} 
      if ( lastglue != 1073741823L ) 
      deleteglueref ( lastglue ) ;
      storefmtfile () ;
      return ;
    } 
#endif /* INITEX */
    printnl ( 1365 ) ;
    return ;
  } 
} 
#ifdef INITEX
void 
initprim ( void ) 
{
  initprim_regmem 
  nonewcontrolsequence = false ;
  primitive ( 392 , 83 , 24527 ) ;
  primitive ( 393 , 83 , 24528 ) ;
  primitive ( 394 , 83 , 24529 ) ;
  primitive ( 395 , 83 , 24530 ) ;
  primitive ( 396 , 83 , 24531 ) ;
  primitive ( 397 , 83 , 24532 ) ;
  primitive ( 398 , 83 , 24533 ) ;
  primitive ( 399 , 83 , 24534 ) ;
  primitive ( 400 , 83 , 24535 ) ;
  primitive ( 401 , 83 , 24536 ) ;
  primitive ( 402 , 83 , 24537 ) ;
  primitive ( 403 , 83 , 24538 ) ;
  primitive ( 404 , 83 , 24539 ) ;
  primitive ( 405 , 83 , 24540 ) ;
  primitive ( 406 , 83 , 24541 ) ;
  primitive ( 407 , 84 , 24544 ) ;
  primitive ( 408 , 84 , 24545 ) ;
  primitive ( 409 , 84 , 24546 ) ;
  primitive ( 410 , 83 , 24542 ) ;
  primitive ( 411 , 83 , 24543 ) ;
  primitive ( 417 , 80 , 25061 ) ;
  primitive ( 418 , 80 , 25062 ) ;
  primitive ( 419 , 80 , 25063 ) ;
  primitive ( 420 , 80 , 25064 ) ;
  primitive ( 421 , 80 , 25065 ) ;
  primitive ( 422 , 80 , 25066 ) ;
  primitive ( 423 , 80 , 25067 ) ;
  primitive ( 424 , 80 , 25068 ) ;
  primitive ( 425 , 80 , 25069 ) ;
  primitive ( 444 , 81 , 28462 ) ;
  primitive ( 445 , 81 , 28463 ) ;
  primitive ( 446 , 81 , 28464 ) ;
  primitive ( 447 , 81 , 28465 ) ;
  primitive ( 448 , 81 , 28466 ) ;
  primitive ( 449 , 81 , 28467 ) ;
  primitive ( 450 , 81 , 28468 ) ;
  primitive ( 451 , 81 , 28469 ) ;
  primitive ( 452 , 81 , 28470 ) ;
  primitive ( 453 , 81 , 28471 ) ;
  primitive ( 454 , 81 , 28472 ) ;
  primitive ( 455 , 81 , 28473 ) ;
  primitive ( 456 , 81 , 28474 ) ;
  primitive ( 457 , 81 , 28475 ) ;
  primitive ( 458 , 81 , 28476 ) ;
  primitive ( 459 , 81 , 28477 ) ;
  primitive ( 460 , 81 , 28478 ) ;
  primitive ( 461 , 81 , 28479 ) ;
  primitive ( 462 , 81 , 28480 ) ;
  primitive ( 463 , 81 , 28481 ) ;
  primitive ( 464 , 81 , 28482 ) ;
  primitive ( 465 , 81 , 28483 ) ;
  primitive ( 466 , 81 , 28484 ) ;
  primitive ( 467 , 81 , 28485 ) ;
  primitive ( 468 , 81 , 28486 ) ;
  primitive ( 469 , 81 , 28487 ) ;
  primitive ( 470 , 81 , 28488 ) ;
  primitive ( 471 , 81 , 28489 ) ;
  primitive ( 472 , 81 , 28490 ) ;
  primitive ( 473 , 81 , 28491 ) ;
  primitive ( 474 , 81 , 28492 ) ;
  primitive ( 475 , 81 , 28493 ) ;
  primitive ( 476 , 81 , 28494 ) ;
  primitive ( 477 , 81 , 28495 ) ;
  primitive ( 478 , 81 , 28496 ) ;
  primitive ( 479 , 81 , 28497 ) ;
  primitive ( 480 , 81 , 28498 ) ;
  primitive ( 481 , 81 , 28499 ) ;
  primitive ( 482 , 81 , 28500 ) ;
  primitive ( 483 , 81 , 28501 ) ;
  primitive ( 484 , 81 , 28502 ) ;
  primitive ( 485 , 81 , 28503 ) ;
  primitive ( 486 , 81 , 28504 ) ;
  primitive ( 487 , 81 , 28505 ) ;
  primitive ( 488 , 81 , 28506 ) ;
  primitive ( 489 , 81 , 28508 ) ;
  primitive ( 490 , 81 , 28509 ) ;
  primitive ( 491 , 81 , 28510 ) ;
  primitive ( 492 , 81 , 28511 ) ;
  primitive ( 493 , 81 , 28512 ) ;
  primitive ( 494 , 81 , 28507 ) ;
  primitive ( 495 , 81 , 28518 ) ;
  primitive ( 496 , 81 , 28513 ) ;
  primitive ( 497 , 81 , 28514 ) ;
  primitive ( 498 , 81 , 28515 ) ;
  primitive ( 499 , 81 , 28516 ) ;
  primitive ( 500 , 81 , 28517 ) ;
  if ( mltexp ) 
  {
    mltexenabledp = true ;
    if ( false ) 
    primitive ( 501 , 81 , 28519 ) ;
    primitive ( 502 , 81 , 28520 ) ;
    primitive ( 503 , 81 , 28521 ) ;
  } 
  primitive ( 507 , 82 , 29035 ) ;
  primitive ( 508 , 82 , 29036 ) ;
  primitive ( 509 , 82 , 29037 ) ;
  primitive ( 510 , 82 , 29038 ) ;
  primitive ( 511 , 82 , 29039 ) ;
  primitive ( 512 , 82 , 29040 ) ;
  primitive ( 513 , 82 , 29041 ) ;
  primitive ( 514 , 82 , 29042 ) ;
  primitive ( 515 , 82 , 29043 ) ;
  primitive ( 516 , 82 , 29044 ) ;
  primitive ( 517 , 82 , 29045 ) ;
  primitive ( 518 , 82 , 29046 ) ;
  primitive ( 519 , 82 , 29047 ) ;
  primitive ( 520 , 82 , 29048 ) ;
  primitive ( 521 , 82 , 29049 ) ;
  primitive ( 522 , 82 , 29050 ) ;
  primitive ( 523 , 82 , 29051 ) ;
  primitive ( 524 , 82 , 29052 ) ;
  primitive ( 525 , 82 , 29053 ) ;
  primitive ( 526 , 82 , 29054 ) ;
  primitive ( 527 , 82 , 29056 ) ;
  primitive ( 528 , 82 , 29057 ) ;
  primitive ( 529 , 82 , 29055 ) ;
  primitive ( 32 , 69 , 0 ) ;
  primitive ( 47 , 48 , 0 ) ;
  primitive ( 540 , 49 , 0 ) ;
  primitive ( 541 , 103 , 0 ) ;
  primitive ( 542 , 44 , 0 ) ;
  primitive ( 543 , 45 , 0 ) ;
  primitive ( 544 , 66 , 0 ) ;
  primitive ( 545 , 20 , 0 ) ;
  primitive ( 546 , 54 , 0 ) ;
  primitive ( 536 , 122 , 0 ) ;
  primitive ( 547 , 15 , 0 ) ;
  primitive ( 548 , 105 , 0 ) ;
  primitive ( 537 , 72 , 0 ) ;
  primitive ( 549 , 67 , 0 ) ;
  hash [15516 ].v.RH = 549 ;
  eqtb [15516 ]= eqtb [curval ];
  primitive ( 550 , 117 , 0 ) ;
  primitive ( 551 , 99 , 0 ) ;
  primitive ( 552 , 100 , 0 ) ;
  primitive ( 553 , 101 , 0 ) ;
  primitive ( 554 , 85 , 0 ) ;
  primitive ( 555 , 36 , 0 ) ;
  primitive ( 556 , 40 , 0 ) ;
  primitive ( 557 , 43 , 0 ) ;
  primitive ( 336 , 41 , 0 ) ;
  primitive ( 359 , 22 , 0 ) ;
  primitive ( 558 , 50 , 0 ) ;
  primitive ( 559 , 21 , 0 ) ;
  primitive ( 560 , 59 , 0 ) ;
  primitive ( 561 , 104 , 0 ) ;
  primitive ( 562 , 38 , 0 ) ;
  primitive ( 563 , 70 , 0 ) ;
  primitive ( 564 , 118 , 0 ) ;
  primitive ( 341 , 60 , 0 ) ;
  primitive ( 565 , 68 , 0 ) ;
  primitive ( 427 , 95 , 0 ) ;
  primitive ( 566 , 46 , 0 ) ;
  primitive ( 567 , 91 , 0 ) ;
  primitive ( 568 , 71 , 0 ) ;
  primitive ( 569 , 109 , 0 ) ;
  primitive ( 570 , 0 , 256 ) ;
  hash [15521 ].v.RH = 570 ;
  eqtb [15521 ]= eqtb [curval ];
  primitive ( 571 , 111 , 0 ) ;
  primitive ( 572 , 124 , 0 ) ;
  primitive ( 426 , 79 , 0 ) ;
  primitive ( 360 , 42 , 0 ) ;
  primitive ( 573 , 37 , 0 ) ;
  primitive ( 574 , 61 , 0 ) ;
  primitive ( 575 , 39 , 0 ) ;
  primitive ( 632 , 13 , 256 ) ;
  parloc = curval ;
  partoken = 536870911L + parloc ;
  primitive ( 667 , 119 , 0 ) ;
  primitive ( 668 , 119 , 1 ) ;
  primitive ( 669 , 125 , 0 ) ;
  primitive ( 670 , 125 , 1 ) ;
  primitive ( 671 , 125 , 2 ) ;
  primitive ( 672 , 125 , 3 ) ;
  primitive ( 673 , 125 , 4 ) ;
  primitive ( 505 , 102 , 0 ) ;
  primitive ( 531 , 102 , 1 ) ;
  primitive ( 414 , 102 , 2 ) ;
  primitive ( 415 , 102 , 3 ) ;
  primitive ( 706 , 90 , 117 ) ;
  primitive ( 707 , 90 , 1 ) ;
  primitive ( 708 , 93 , 0 ) ;
  primitive ( 709 , 93 , 1 ) ;
  primitive ( 710 , 94 , 1 ) ;
  primitive ( 711 , 94 , 3 ) ;
  primitive ( 712 , 94 , 2 ) ;
  primitive ( 713 , 76 , 0 ) ;
  primitive ( 714 , 76 , 1 ) ;
  primitive ( 715 , 76 , 2 ) ;
  primitive ( 716 , 76 , 3 ) ;
  primitive ( 717 , 76 , 4 ) ;
  primitive ( 775 , 123 , 0 ) ;
  primitive ( 776 , 123 , 1 ) ;
  primitive ( 777 , 123 , 3 ) ;
  primitive ( 778 , 123 , 4 ) ;
  primitive ( 779 , 123 , 5 ) ;
  primitive ( 780 , 123 , 2 ) ;
  primitive ( 781 , 123 , 6 ) ;
  primitive ( 782 , 123 , 7 ) ;
  primitive ( 783 , 123 , 8 ) ;
  primitive ( 784 , 123 , 9 ) ;
  primitive ( 785 , 123 , 10 ) ;
  primitive ( 786 , 123 , 11 ) ;
  primitive ( 802 , 120 , 0 ) ;
  primitive ( 803 , 120 , 1 ) ;
  primitive ( 804 , 120 , 2 ) ;
  primitive ( 805 , 120 , 3 ) ;
  primitive ( 806 , 120 , 4 ) ;
  primitive ( 807 , 120 , 5 ) ;
  primitive ( 808 , 120 , 6 ) ;
  primitive ( 809 , 120 , 7 ) ;
  primitive ( 810 , 120 , 8 ) ;
  primitive ( 811 , 120 , 9 ) ;
  primitive ( 812 , 120 , 10 ) ;
  primitive ( 813 , 120 , 11 ) ;
  primitive ( 814 , 120 , 12 ) ;
  primitive ( 815 , 120 , 13 ) ;
  primitive ( 816 , 120 , 14 ) ;
  primitive ( 817 , 120 , 15 ) ;
  primitive ( 818 , 120 , 16 ) ;
  primitive ( 819 , 120 , 17 ) ;
  primitive ( 820 , 120 , 18 ) ;
  primitive ( 821 , 120 , 19 ) ;
  primitive ( 822 , 120 , 20 ) ;
  primitive ( 823 , 120 , 21 ) ;
  primitive ( 824 , 120 , 22 ) ;
  primitive ( 825 , 120 , 23 ) ;
  primitive ( 826 , 121 , 2 ) ;
  hash [15518 ].v.RH = 826 ;
  eqtb [15518 ]= eqtb [curval ];
  primitive ( 827 , 121 , 4 ) ;
  primitive ( 828 , 121 , 3 ) ;
  primitive ( 853 , 98 , 0 ) ;
  hash [15525 ].v.RH = 853 ;
  eqtb [15525 ]= eqtb [curval ];
  primitive ( 952 , 4 , 256 ) ;
  primitive ( 953 , 5 , 257 ) ;
  hash [15515 ].v.RH = 953 ;
  eqtb [15515 ]= eqtb [curval ];
  primitive ( 954 , 5 , 258 ) ;
  hash [15519 ].v.RH = 955 ;
  hash [15520 ].v.RH = 955 ;
  eqtb [15520 ].hh.b0 = 9 ;
  eqtb [15520 ].hh .v.RH = memtop - 11 ;
  eqtb [15520 ].hh.b1 = 1 ;
  eqtb [15519 ]= eqtb [15520 ];
  eqtb [15519 ].hh.b0 = 130 ;
  primitive ( 1024 , 92 , 0 ) ;
  primitive ( 1025 , 92 , 1 ) ;
  primitive ( 1026 , 92 , 2 ) ;
  primitive ( 1027 , 92 , 3 ) ;
  primitive ( 1028 , 92 , 4 ) ;
  primitive ( 1029 , 92 , 5 ) ;
  primitive ( 1030 , 92 , 6 ) ;
  primitive ( 1031 , 92 , 7 ) ;
  primitive ( 1080 , 14 , 0 ) ;
  primitive ( 1081 , 14 , 1 ) ;
  primitive ( 1082 , 30 , 4 ) ;
  primitive ( 1083 , 30 , 0 ) ;
  primitive ( 1084 , 30 , 1 ) ;
  primitive ( 1085 , 30 , 2 ) ;
  primitive ( 1086 , 30 , 3 ) ;
  primitive ( 1087 , 31 , 4 ) ;
  primitive ( 1088 , 31 , 0 ) ;
  primitive ( 1089 , 31 , 1 ) ;
  primitive ( 1090 , 31 , 2 ) ;
  primitive ( 1091 , 31 , 3 ) ;
  primitive ( 342 , 32 , 5 ) ;
  primitive ( 346 , 33 , 1 ) ;
  primitive ( 348 , 34 , 99 ) ;
  primitive ( 1109 , 25 , 1 ) ;
  primitive ( 1110 , 25 , 0 ) ;
  primitive ( 1111 , 26 , 1 ) ;
  primitive ( 1112 , 26 , 0 ) ;
  primitive ( 428 , 24 , 0 ) ;
  primitive ( 1113 , 24 , 1 ) ;
  primitive ( 1114 , 24 , 2 ) ;
  primitive ( 1019 , 24 , 3 ) ;
  primitive ( 1115 , 24 , 4 ) ;
  primitive ( 1021 , 24 , 5 ) ;
  primitive ( 1116 , 24 , 121 ) ;
  primitive ( 1117 , 78 , 3 ) ;
  primitive ( 1118 , 78 , 4 ) ;
  primitive ( 1119 , 78 , 1 ) ;
  primitive ( 1120 , 35 , 99 ) ;
  primitive ( 1121 , 35 , 100 ) ;
  primitive ( 1122 , 35 , 101 ) ;
  primitive ( 1123 , 35 , 102 ) ;
  primitive ( 1145 , 47 , 1 ) ;
  primitive ( 1146 , 47 , 0 ) ;
  primitive ( 1157 , 29 , 14 ) ;
  primitive ( 1158 , 29 , 13 ) ;
  primitive ( 1159 , 29 , 12 ) ;
  primitive ( 1160 , 27 , 0 ) ;
  primitive ( 1161 , 27 , 1 ) ;
  primitive ( 1162 , 28 , 0 ) ;
  primitive ( 1163 , 28 , 1 ) ;
  primitive ( 45 , 51 , 1 ) ;
  primitive ( 357 , 51 , 0 ) ;
  primitive ( 1196 , 52 , 0 ) ;
  primitive ( 1197 , 52 , 1 ) ;
  primitive ( 919 , 55 , 18 ) ;
  primitive ( 920 , 55 , 19 ) ;
  primitive ( 921 , 55 , 20 ) ;
  primitive ( 922 , 55 , 21 ) ;
  primitive ( 923 , 55 , 22 ) ;
  primitive ( 924 , 55 , 23 ) ;
  primitive ( 925 , 55 , 24 ) ;
  primitive ( 926 , 55 , 25 ) ;
  primitive ( 928 , 55 , 28 ) ;
  primitive ( 927 , 55 , 29 ) ;
  primitive ( 1201 , 56 , 0 ) ;
  primitive ( 931 , 56 , 1 ) ;
  primitive ( 932 , 56 , 2 ) ;
  primitive ( 914 , 58 , 0 ) ;
  primitive ( 915 , 58 , 2 ) ;
  primitive ( 916 , 58 , 4 ) ;
  primitive ( 917 , 58 , 6 ) ;
  primitive ( 1219 , 57 , 0 ) ;
  primitive ( 1220 , 57 , 1 ) ;
  primitive ( 1221 , 57 , 2 ) ;
  primitive ( 1222 , 57 , 3 ) ;
  primitive ( 1223 , 57 , 4 ) ;
  primitive ( 1224 , 57 , 5 ) ;
  primitive ( 929 , 53 , 32 ) ;
  primitive ( 930 , 53 , 33 ) ;
  hash [15517 ].v.RH = 930 ;
  eqtb [15517 ]= eqtb [curval ];
  primitive ( 1243 , 106 , 1 ) ;
  primitive ( 1244 , 106 , 2 ) ;
  primitive ( 1245 , 106 , 4 ) ;
  primitive ( 1246 , 110 , 0 ) ;
  primitive ( 1247 , 110 , 1 ) ;
  primitive ( 1248 , 110 , 2 ) ;
  primitive ( 1249 , 110 , 3 ) ;
  primitive ( 1263 , 107 , 0 ) ;
  primitive ( 1264 , 107 , 1 ) ;
  primitive ( 1265 , 108 , 0 ) ;
  primitive ( 1266 , 108 , 8 ) ;
  primitive ( 1267 , 108 , 1 ) ;
  primitive ( 1268 , 108 , 2 ) ;
  primitive ( 1269 , 108 , 3 ) ;
  primitive ( 1270 , 108 , 4 ) ;
  primitive ( 1271 , 108 , 5 ) ;
  primitive ( 1272 , 108 , 6 ) ;
  if ( mltexp ) 
  {
    primitive ( 1273 , 108 , 7 ) ;
  } 
  primitive ( 434 , 96 , 25636 ) ;
  primitive ( 435 , 96 , 25892 ) ;
  primitive ( 436 , 96 , 26404 ) ;
  primitive ( 443 , 96 , 27950 ) ;
  primitive ( 440 , 96 , 27182 ) ;
  primitive ( 441 , 96 , 27438 ) ;
  primitive ( 442 , 96 , 27694 ) ;
  primitive ( 506 , 96 , 28779 ) ;
  primitive ( 431 , 97 , 25583 ) ;
  primitive ( 432 , 97 , 25599 ) ;
  primitive ( 433 , 97 , 25615 ) ;
  primitive ( 995 , 112 , 0 ) ;
  primitive ( 1007 , 112 , 1 ) ;
  primitive ( 1295 , 86 , 0 ) ;
  primitive ( 1296 , 86 , 1 ) ;
  primitive ( 273 , 113 , 0 ) ;
  primitive ( 274 , 113 , 1 ) ;
  primitive ( 275 , 113 , 2 ) ;
  primitive ( 1305 , 113 , 3 ) ;
  primitive ( 1306 , 65 , 1 ) ;
  primitive ( 1307 , 65 , 0 ) ;
  primitive ( 1308 , 63 , 0 ) ;
  primitive ( 1309 , 63 , 1 ) ;
  primitive ( 1315 , 62 , 27182 ) ;
  primitive ( 1316 , 62 , 27438 ) ;
  primitive ( 1317 , 23 , 0 ) ;
  primitive ( 1318 , 23 , 1 ) ;
  primitive ( 1319 , 23 , 2 ) ;
  primitive ( 1320 , 23 , 3 ) ;
  primitive ( 1321 , 23 , 4 ) ;
  primitive ( 1367 , 64 , 0 ) ;
  primitive ( 629 , 64 , 1 ) ;
  writeloc = curval ;
  primitive ( 1368 , 64 , 2 ) ;
  primitive ( 1369 , 64 , 3 ) ;
  hash [15524 ].v.RH = 1369 ;
  eqtb [15524 ]= eqtb [curval ];
  primitive ( 1370 , 64 , 4 ) ;
  primitive ( 1371 , 64 , 5 ) ;
  primitive ( 1396 , 81 , 28522 ) ;
  primitive ( 439 , 89 , 0 ) ;
  primitive ( 1400 , 114 , 1 ) ;
  primitive ( 1401 , 114 , 0 ) ;
  primitive ( 1402 , 114 , 3 ) ;
  primitive ( 1403 , 114 , 2 ) ;
  primitive ( 1404 , 115 , 0 ) ;
  primitive ( 1405 , 115 , 1 ) ;
  primitive ( 1406 , 115 , 2 ) ;
  primitive ( 1419 , 77 , 0 ) ;
  primitive ( 1420 , 88 , 26660 ) ;
  primitive ( 1423 , 87 , 1 ) ;
  primitive ( 1424 , 87 , 2 ) ;
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
    eqtbtop = 29569 + hashextra ;
    if ( hashextra == 0 ) 
    hashtop = 24526 ;
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
  if ( ( -1073741823L > 0 ) || ( 1073741823L < 32767 ) ) 
  bad = 12 ;
  if ( ( 0 < -1073741823L ) || ( 65535L > 1073741823L ) ) 
  bad = 13 ;
  if ( ( membot - supmainmemory < -1073741823L ) || ( memtop + supmainmemory 
  >= 1073741823L ) || ( 0 != 0 ) ) 
  bad = 14 ;
  if ( ( 9000 < -1073741823L ) || ( 9000 > 1073741823L ) ) 
  bad = 15 ;
  if ( fontmax > 9000 ) 
  bad = 16 ;
  if ( ( savesize > 1073741823L ) || ( maxstrings > 1073741823L ) ) 
  bad = 17 ;
  if ( bufsize > 1073741823L ) 
  bad = 18 ;
  if ( 65535L < 255 ) 
  bad = 19 ;
  if ( 536900480L + hashextra > 1073741823L ) 
  bad = 21 ;
  if ( ( hashoffset < 0 ) || ( hashoffset > 514 ) ) 
  bad = 42 ;
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
    dateandtime ( eqtb [28482 ].cint , eqtb [28483 ].cint , eqtb [28484 ]
    .cint , eqtb [28485 ].cint ) ;
  } 
#endif /* INITEX */
  readyalready = 314159L ;
  lab1: selector = 17 ;
  tally = 0 ;
  termoffset = 0 ;
  fileoffset = 0 ;
  kcodepos = 0 ;
  if ( srcspecialsp || filelineerrorstylep || parsefirstlinep ) 
  fprintf ( stdout , "%s%s%s",  "This is upTeX, Version 3.14159265" , "-p3.7" , "-u1.20" ) 
  ;
  else
  fprintf ( stdout , "%s%s%s",  "This is upTeX, Version 3.14159265" , "-p3.7" ,   "-u1.20" ) ;
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
      paramptr = 0 ;
      maxparamstack = 0 ;
      first = bufsize ;
      do {
	  buffer [first ]= 0 ;
	decr ( first ) ;
      } while ( ! ( first == 0 ) ) ;
      scannerstatus = 0 ;
      warningindex = -1073741823L ;
      first = 1 ;
      curinput .statefield = 61 ;
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
    if ( ( formatident == 0 ) || ( buffer [curinput .locfield ]== 38 ) || 
    dumpline ) 
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
    if ( ( eqtb [28511 ].cint < 0 ) || ( eqtb [28511 ].cint > 255 ) ) 
    decr ( curinput .limitfield ) ;
    else buffer [curinput .limitfield ]= eqtb [28511 ].cint ;
    if ( mltexenabledp ) 
    {
      fprintf ( stdout , "%s\n",  "MLTeX v2.2 enabled" ) ;
    } 
    dateandtime ( eqtb [28482 ].cint , eqtb [28483 ].cint , eqtb [28484 ]
    .cint , eqtb [28485 ].cint ) ;
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
      fontname [0 ]= 853 ;
      fontarea [0 ]= 344 ;
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
      fontglue [0 ]= -1073741823L ;
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
    magicoffset = strstart [946 ]- 9 * 18 ;
    if ( interaction == 0 ) 
    selector = 16 ;
    else selector = 17 ;
    if ( ( curinput .locfield < curinput .limitfield ) && ( eqtb [25636 + 
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
