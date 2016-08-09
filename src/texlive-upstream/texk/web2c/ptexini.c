#define EXTERN extern
#include "ptexd.h"

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
  curlist .auxfield .cint = -65536000L ;
  curlist .mlfield = 0 ;
  curlist .pgfield = 0 ;
  shownmode = 0 ;
  pagecontents = 0 ;
  pagetail = memtop - 2 ;
  lastglue = 268435455L ;
  lastpenalty = 0 ;
  lastkern = 0 ;
  pagesofar [7 ]= 0 ;
  pagemaxdepth = 0 ;
  {register integer for_end; k = 28205 ;for_end = 29315 ; if ( k <= for_end) 
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
    mem [membot + 12 ].hh.b0 = 1 ;
    mem [membot + 15 ].cint = 65536L ;
    mem [membot + 12 ].hh.b1 = 1 ;
    mem [membot + 18 ].cint = -65536L ;
    mem [membot + 16 ].hh.b0 = 1 ;
    rover = membot + 20 ;
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
    mem [memtop - 9 ].hh .v.RH = 256 ;
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
    varused = membot + 20 - membot ;
    dynused = 14 ;
    eqtb [24526 ].hh.b0 = 112 ;
    eqtb [24526 ].hh .v.RH = -268435455L ;
    eqtb [24526 ].hh.b1 = 0 ;
    {register integer for_end; k = 1 ;for_end = eqtbtop ; if ( k <= for_end) 
    do 
      eqtb [k ]= eqtb [24526 ];
    while ( k++ < for_end ) ;} 
    eqtb [24527 ].hh .v.RH = membot ;
    eqtb [24527 ].hh.b1 = 1 ;
    eqtb [24527 ].hh.b0 = 128 ;
    {register integer for_end; k = 24528 ;for_end = 25059 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [24527 ];
    while ( k++ < for_end ) ;} 
    mem [membot ].hh .v.RH = mem [membot ].hh .v.RH + 533 ;
    eqtb [25060 ].hh .v.RH = -268435455L ;
    eqtb [25060 ].hh.b0 = 129 ;
    eqtb [25060 ].hh.b1 = 1 ;
    {register integer for_end; k = 25061 ;for_end = 25325 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [24526 ];
    while ( k++ < for_end ) ;} 
    eqtb [25326 ].hh .v.RH = -268435455L ;
    eqtb [25326 ].hh.b0 = 130 ;
    eqtb [25326 ].hh.b1 = 1 ;
    {register integer for_end; k = 25327 ;for_end = 25581 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [25326 ];
    while ( k++ < for_end ) ;} 
    eqtb [25582 ].hh .v.RH = 0 ;
    eqtb [25582 ].hh.b0 = 131 ;
    eqtb [25582 ].hh.b1 = 1 ;
    eqtb [25631 ].hh .v.RH = 0 ;
    eqtb [25631 ].hh.b0 = 131 ;
    eqtb [25631 ].hh.b1 = 1 ;
    eqtb [25632 ].hh .v.RH = 0 ;
    eqtb [25632 ].hh.b0 = 131 ;
    eqtb [25632 ].hh.b1 = 1 ;
    {register integer for_end; k = 25583 ;for_end = 25630 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [25582 ];
    while ( k++ < for_end ) ;} 
    eqtb [25635 ].hh .v.RH = 0 ;
    eqtb [25635 ].hh.b0 = 131 ;
    eqtb [25635 ].hh.b1 = 1 ;
    {register integer for_end; k = 25636 ;for_end = 28204 ; if ( k <= 
    for_end) do 
      eqtb [k ]= eqtb [25635 ];
    while ( k++ < for_end ) ;} 
    eqtb [25633 ]= eqtb [25635 ];
    eqtb [25634 ]= eqtb [25635 ];
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      {
	eqtb [25635 + k ].hh .v.RH = 12 ;
	eqtb [25891 + k ].hh .v.RH = 18 ;
	eqtb [27693 + k ].hh .v.RH = k ;
	eqtb [27437 + k ].hh .v.RH = 1000 ;
	eqtb [26147 + k ].hh .v.RH = 0 ;
	eqtb [26403 + k ].hh .v.RH = 0 ;
	eqtb [26403 + k ].hh.b0 = 0 ;
	eqtb [26659 + k ].hh .v.RH = 0 ;
	eqtb [26659 + k ].hh.b0 = 0 ;
      } 
    while ( k++ < for_end ) ;} 
    eqtb [25648 ].hh .v.RH = 5 ;
    eqtb [25667 ].hh .v.RH = 10 ;
    eqtb [25727 ].hh .v.RH = 0 ;
    eqtb [25672 ].hh .v.RH = 14 ;
    eqtb [25762 ].hh .v.RH = 15 ;
    eqtb [25635 ].hh .v.RH = 9 ;
    {register integer for_end; k = 48 ;for_end = 57 ; if ( k <= for_end) do 
      {
	eqtb [27693 + k ].hh .v.RH = k + 28672 ;
	eqtb [26147 + k ].hh .v.RH = 3 ;
      } 
    while ( k++ < for_end ) ;} 
    eqtb [26915 ].hh .v.RH = toDVI ( fromJIS ( 8507 ) ) ;
    eqtb [26916 ].hh .v.RH = toDVI ( fromJIS ( 12396 ) ) ;
    eqtb [26917 ].hh .v.RH = toDVI ( fromJIS ( 18035 ) ) ;
    eqtb [26918 ].hh .v.RH = toDVI ( fromJIS ( 15152 ) ) ;
    eqtb [26919 ].hh .v.RH = toDVI ( fromJIS ( 15181 ) ) ;
    eqtb [26920 ].hh .v.RH = toDVI ( fromJIS ( 14430 ) ) ;
    eqtb [26921 ].hh .v.RH = toDVI ( fromJIS ( 20283 ) ) ;
    eqtb [26922 ].hh .v.RH = toDVI ( fromJIS ( 15415 ) ) ;
    eqtb [26923 ].hh .v.RH = toDVI ( fromJIS ( 18476 ) ) ;
    eqtb [26924 ].hh .v.RH = toDVI ( fromJIS ( 13925 ) ) ;
    {register integer for_end; k = 65 ;for_end = 90 ; if ( k <= for_end) do 
      {
	eqtb [25635 + k ].hh .v.RH = 11 ;
	eqtb [25635 + k + 32 ].hh .v.RH = 11 ;
	eqtb [27693 + k ].hh .v.RH = k + 28928 ;
	eqtb [27693 + k + 32 ].hh .v.RH = k + 28960 ;
	eqtb [26925 + k ].hh .v.RH = k + 32 ;
	eqtb [26925 + k + 32 ].hh .v.RH = k + 32 ;
	eqtb [27181 + k ].hh .v.RH = k ;
	eqtb [27181 + k + 32 ].hh .v.RH = k ;
	eqtb [26147 + k ].hh .v.RH = 3 ;
	eqtb [26147 + k + 32 ].hh .v.RH = 3 ;
	eqtb [27437 + k ].hh .v.RH = 999 ;
      } 
    while ( k++ < for_end ) ;} 
    eqtb [25924 ].hh .v.RH = 18 ;
    eqtb [25925 ].hh .v.RH = 18 ;
    {register integer for_end; k = 3 ;for_end = 6 ; if ( k <= for_end) do 
      eqtb [25923 + k ].hh .v.RH = 17 ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 7 ;for_end = 8 ; if ( k <= for_end) do 
      eqtb [25923 + k ].hh .v.RH = 18 ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 16 ;for_end = 84 ; if ( k <= for_end) do 
      eqtb [25923 + k ].hh .v.RH = 16 ;
    while ( k++ < for_end ) ;} 
    {register integer for_end; k = 28205 ;for_end = 28524 ; if ( k <= 
    for_end) do 
      eqtb [k ].cint = 0 ;
    while ( k++ < for_end ) ;} 
    eqtb [28265 ].cint = 256 ;
    eqtb [28266 ].cint = -1 ;
    eqtb [28222 ].cint = 1000 ;
    eqtb [28206 ].cint = 10000 ;
    eqtb [28246 ].cint = 1 ;
    eqtb [28245 ].cint = 25 ;
    eqtb [28251 ].cint = 92 ;
    eqtb [28254 ].cint = 13 ;
    {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
      eqtb [28525 + k ].cint = -1 ;
    while ( k++ < for_end ) ;} 
    eqtb [28571 ].cint = 0 ;
    {register integer for_end; k = 28781 ;for_end = 29315 ; if ( k <= 
    for_end) do 
      eqtb [k ].cint = 0 ;
    while ( k++ < for_end ) ;} 
    hashused = 15514 ;
    hashhigh = 0 ;
    cscount = 0 ;
    eqtb [15523 ].hh.b0 = 127 ;
    hash [15523 ].v.RH = 536 ;
    eqtb [28262 ].cint = 1000 ;
    eqtb [28263 ].cint = 700 ;
    eqtb [28264 ].cint = 500 ;
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
    formatident = 1335 ;
    hash [15522 ].v.RH = 1377 ;
    eqtb [15522 ].hh.b1 = 1 ;
    eqtb [15522 ].hh.b0 = 124 ;
    eqtb [15522 ].hh .v.RH = -268435455L ;
  } 
#endif /* INITEX */
  synctexoffset = 28268 ;
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
    if ( eqtb [28256 ].cint <= 0 ) 
    curlang = 0 ;
    else if ( eqtb [28256 ].cint > 255 ) 
    curlang = 0 ;
    else curlang = eqtb [28256 ].cint ;
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
	      
	    curchr = eqtb [26925 + curchr ].hh .v.RH ;
	    if ( curchr == 0 ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 262 ) ;
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
		else printnl ( 262 ) ;
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
	    else printnl ( 262 ) ;
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
      else printnl ( 262 ) ;
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
  if ( eqtb [25060 ].hh .v.RH == -268435455L ) {
      
    if ( eqtb [28798 ].cint == 0 ) 
    {
      lastspecialline = 0 ;
      secondwidth = eqtb [28784 ].cint ;
      secondindent = 0 ;
    } 
    else {
	
      lastspecialline = abs ( eqtb [28246 ].cint ) ;
      if ( eqtb [28246 ].cint < 0 ) 
      {
	firstwidth = eqtb [28784 ].cint - abs ( eqtb [28798 ].cint ) ;
	if ( eqtb [28798 ].cint >= 0 ) 
	firstindent = eqtb [28798 ].cint ;
	else firstindent = 0 ;
	secondwidth = eqtb [28784 ].cint ;
	secondindent = 0 ;
      } 
      else {
	  
	firstwidth = eqtb [28784 ].cint ;
	firstindent = 0 ;
	secondwidth = eqtb [28784 ].cint - abs ( eqtb [28798 ].cint ) ;
	if ( eqtb [28798 ].cint >= 0 ) 
	secondindent = eqtb [28798 ].cint ;
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
  if ( eqtb [28224 ].cint == 0 ) 
  easyline = lastspecialline ;
  else easyline = 268435455L ;
  threshold = eqtb [28205 ].cint ;
  if ( threshold >= 0 ) 
  {
	;
#ifdef STAT
    if ( eqtb [28237 ].cint > 0 ) 
    {
      begindiagnostic () ;
      printnl ( 987 ) ;
    } 
#endif /* STAT */
    secondpass = false ;
    finalpass = false ;
  } 
  else {
      
    threshold = eqtb [28206 ].cint ;
    secondpass = true ;
    finalpass = ( eqtb [28801 ].cint <= 0 ) ;
	;
#ifdef STAT
    if ( eqtb [28237 ].cint > 0 ) 
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
    mem [q + 1 ].hh .v.RH = -268435455L ;
    mem [q + 1 ].hh .v.LH = curlist .pgfield + 1 ;
    mem [q + 2 ].cint = 0 ;
    mem [memtop - 7 ].hh .v.RH = q ;
    activewidth [1 ]= background [1 ];
    activewidth [2 ]= background [2 ];
    activewidth [3 ]= background [3 ];
    activewidth [4 ]= background [4 ];
    activewidth [5 ]= background [5 ];
    activewidth [6 ]= background [6 ];
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
		if ( eqtb [26925 + c ].hh .v.RH != 0 ) {
		    
		  if ( ( eqtb [26925 + c ].hh .v.RH == c ) || ( eqtb [28243 
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
		  if ( eqtb [26925 + c ].hh .v.RH == 0 ) 
		  goto lab33 ;
		  if ( hn == 63 ) 
		  goto lab33 ;
		  hb = s ;
		  incr ( hn ) ;
		  hu [hn ]= c ;
		  hc [hn ]= eqtb [26925 + c ].hh .v.RH ;
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
		    if ( eqtb [26925 + c ].hh .v.RH == 0 ) 
		    goto lab33 ;
		    if ( j == 63 ) 
		    goto lab33 ;
		    incr ( j ) ;
		    hu [j ]= c ;
		    hc [j ]= eqtb [26925 + c ].hh .v.RH ;
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
	  if ( s == -268435455L ) 
	  trybreak ( eqtb [28209 ].cint , 1 ) ;
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
	    } while ( ! ( s == -268435455L ) ) ;
	    activewidth [1 ]= activewidth [1 ]+ discwidth ;
	    trybreak ( eqtb [28208 ].cint , 1 ) ;
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
	if ( eqtb [28224 ].cint == 0 ) 
	goto lab30 ;
	{
	  r = mem [memtop - 7 ].hh .v.RH ;
	  actuallooseness = 0 ;
	  do {
	      if ( mem [r ].hh.b0 != 2 ) 
	    {
	      linediff = mem [r + 1 ].hh .v.LH - bestline ;
	      if ( ( ( linediff < actuallooseness ) && ( eqtb [28224 ].cint 
	      <= linediff ) ) || ( ( linediff > actuallooseness ) && ( eqtb [
	      28224 ].cint >= linediff ) ) ) 
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
	if ( ( actuallooseness == eqtb [28224 ].cint ) || finalpass ) 
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
    while ( q != -268435455L ) {
	
      curp = mem [q ].hh .v.RH ;
      freenode ( q , 2 ) ;
      q = curp ;
    } 
    if ( ! secondpass ) 
    {
	;
#ifdef STAT
      if ( eqtb [28237 ].cint > 0 ) 
      printnl ( 988 ) ;
#endif /* STAT */
      threshold = eqtb [28206 ].cint ;
      secondpass = true ;
      finalpass = ( eqtb [28801 ].cint <= 0 ) ;
    } 
    else {
	
	;
#ifdef STAT
      if ( eqtb [28237 ].cint > 0 ) 
      printnl ( 989 ) ;
#endif /* STAT */
      background [2 ]= background [2 ]+ eqtb [28801 ].cint ;
      finalpass = true ;
    } 
  } 
  lab30: 
	;
#ifdef STAT
  if ( eqtb [28237 ].cint > 0 ) 
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
  while ( q != -268435455L ) {
      
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
  while ( curcmd == 103 ) {
      
    if ( ! odd ( a / curchr ) ) 
    a = a + curchr ;
    do {
	getxtoken () ;
    } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
    if ( curcmd <= 75 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 262 ) ;
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
  if ( ( curcmd != 107 ) && ( a % 4 != 0 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 262 ) ;
      print ( 724 ) ;
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
  if ( eqtb [28248 ].cint != 0 ) {
      
    if ( eqtb [28248 ].cint < 0 ) 
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
  {case 95 : 
    {
      if ( fontdir [curchr ]== 4 ) {
	  
	if ( ( a >= 4 ) ) 
	geqdefine ( 25631 , 131 , curchr ) ;
	else eqdefine ( 25631 , 131 , curchr ) ;
      } 
      else if ( fontdir [curchr ]== 3 ) {
	  
	if ( ( a >= 4 ) ) 
	geqdefine ( 25632 , 131 , curchr ) ;
	else eqdefine ( 25632 , 131 , curchr ) ;
      } 
      else if ( ( a >= 4 ) ) 
      geqdefine ( 25582 , 131 , curchr ) ;
      else eqdefine ( 25582 , 131 , curchr ) ;
    } 
    break ;
  case 107 : 
    {
      if ( odd ( curchr ) && ! ( a >= 4 ) && ( eqtb [28248 ].cint >= 0 ) ) 
      a = a + 4 ;
      e = ( curchr >= 2 ) ;
      getrtoken () ;
      p = curcs ;
      q = scantoks ( true , e ) ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 122 + ( a % 4 ) , defref ) ;
      else eqdefine ( p , 122 + ( a % 4 ) , defref ) ;
    } 
    break ;
  case 104 : 
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
      if ( curcmd >= 122 ) 
      incr ( mem [curchr ].hh .v.LH ) ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , curcmd , curchr ) ;
      else eqdefine ( p , curcmd , curchr ) ;
    } 
    break ;
  case 105 : 
    if ( curchr == 7 ) 
    {
      scancharnum () ;
      p = 27949 + curval ;
      scanoptionalequals () ;
      scancharnum () ;
      n = curval ;
      scancharnum () ;
      if ( ( eqtb [28267 ].cint > 0 ) ) 
      {
	begindiagnostic () ;
	printnl ( 1273 ) ;
	print ( p - 27949 ) ;
	print ( 1274 ) ;
	print ( n ) ;
	printchar ( 32 ) ;
	print ( curval ) ;
	enddiagnostic ( false ) ;
      } 
      n = n * 256 + curval ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 131 , n ) ;
      else eqdefine ( p , 131 , n ) ;
      if ( ( p - 27949 ) < eqtb [28265 ].cint ) {
	  
	if ( ( a >= 4 ) ) 
	geqworddefine ( 28265 , p - 27949 ) ;
	else eqworddefine ( 28265 , p - 27949 ) ;
      } 
      if ( ( p - 27949 ) > eqtb [28266 ].cint ) {
	  
	if ( ( a >= 4 ) ) 
	geqworddefine ( 28266 , p - 27949 ) ;
	else eqworddefine ( 28266 , p - 27949 ) ;
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
	  scanfifteenbitint () ;
	  if ( ( a >= 4 ) ) 
	  geqdefine ( p , 72 , curval ) ;
	  else eqdefine ( p , 72 , curval ) ;
	} 
	break ;
	default: 
	{
	  scaneightbitint () ;
	  switch ( n ) 
	  {case 2 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 78 , 28269 + curval ) ;
	    else eqdefine ( p , 78 , 28269 + curval ) ;
	    break ;
	  case 3 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 79 , 28804 + curval ) ;
	    else eqdefine ( p , 79 , 28804 + curval ) ;
	    break ;
	  case 4 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 80 , 24548 + curval ) ;
	    else eqdefine ( p , 80 , 24548 + curval ) ;
	    break ;
	  case 5 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 81 , 24804 + curval ) ;
	    else eqdefine ( p , 81 , 24804 + curval ) ;
	    break ;
	  case 6 : 
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 77 , 25070 + curval ) ;
	    else eqdefine ( p , 77 , 25070 + curval ) ;
	    break ;
	  } 
	} 
	break ;
      } 
    } 
    break ;
  case 106 : 
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
	  else printnl ( 262 ) ;
	  print ( 1138 ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1275 ;
	  helpline [0 ]= 1276 ;
	} 
	error () ;
      } 
      getrtoken () ;
      p = curcs ;
      readtoks ( n , p ) ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 122 , curval ) ;
      else eqdefine ( p , 122 , curval ) ;
    } 
    break ;
  case 76 : 
  case 77 : 
    {
      q = curcs ;
      if ( curcmd == 76 ) 
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
	if ( curcmd == 76 ) 
	{
	  scaneightbitint () ;
	  curcmd = 77 ;
	  curchr = 25070 + curval ;
	} 
	if ( curcmd == 77 ) 
	{
	  q = eqtb [curchr ].hh .v.RH ;
	  if ( q == -268435455L ) {
	      
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 112 , -268435455L ) ;
	    else eqdefine ( p , 112 , -268435455L ) ;
	  } 
	  else {
	      
	    incr ( mem [q ].hh .v.LH ) ;
	    if ( ( a >= 4 ) ) 
	    geqdefine ( p , 122 , q ) ;
	    else eqdefine ( p , 122 , q ) ;
	  } 
	  goto lab30 ;
	} 
      } 
      backinput () ;
      curcs = q ;
      q = scantoks ( false , false ) ;
      if ( mem [defref ].hh .v.RH == -268435455L ) 
      {
	if ( ( a >= 4 ) ) 
	geqdefine ( p , 112 , -268435455L ) ;
	else eqdefine ( p , 112 , -268435455L ) ;
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
	geqdefine ( p , 122 , defref ) ;
	else eqdefine ( p , 122 , defref ) ;
      } 
    } 
    break ;
  case 78 : 
    {
      p = curchr ;
      scanoptionalequals () ;
      scanint () ;
      if ( p == 28249 ) 
      {
	if ( fontdir [eqtb [25583 + curval ].hh .v.RH ]!= 0 ) {
	    
	  if ( ( a >= 4 ) ) 
	  geqworddefine ( 28250 , curval ) ;
	  else eqworddefine ( 28250 , curval ) ;
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
  case 79 : 
    {
      p = curchr ;
      scanoptionalequals () ;
      scandimen ( false , false , false ) ;
      if ( ( a >= 4 ) ) 
      geqworddefine ( p , curval ) ;
      else eqworddefine ( p , curval ) ;
    } 
    break ;
  case 80 : 
  case 81 : 
    {
      p = curchr ;
      n = curcmd ;
      scanoptionalequals () ;
      if ( n == 81 ) 
      scanglue ( 3 ) ;
      else scanglue ( 2 ) ;
      trapzeroglue () ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 128 , curval ) ;
      else eqdefine ( p , 128 , curval ) ;
    } 
    break ;
  case 93 : 
    {
      if ( curchr == 25891 ) 
      m = 16 ;
      else m = 0 ;
      if ( curchr == 25635 ) 
      n = 15 ;
      else if ( curchr == 25891 ) 
      n = 18 ;
      else if ( curchr == 27693 ) 
      n = 32768L ;
      else if ( curchr == 27437 ) 
      n = 32767 ;
      else if ( curchr == 28525 ) 
      n = 16777215L ;
      else n = 255 ;
      p = curchr ;
      scancharnum () ;
      if ( p == 25891 ) 
      p = p + kcatcodekey ( curval ) ;
      else if ( ! ischarascii ( curval ) ) 
      p = p + Hi ( curval ) ;
      else p = p + curval ;
      scanoptionalequals () ;
      scanint () ;
      if ( ( ( curval < m ) && ( p < 28525 ) ) || ( curval > n ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 262 ) ;
	  print ( 1277 ) ;
	} 
	printint ( curval ) ;
	if ( p < 28525 ) 
	{
	  print ( 1278 ) ;
	  printint ( m ) ;
	  print ( 1279 ) ;
	} 
	else print ( 1280 ) ;
	printint ( n ) ;
	if ( m == 0 ) 
	{
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1281 ;
	  } 
	  error () ;
	} 
	else {
	    
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1282 ;
	  } 
	  error () ;
	} 
	curval = m ;
      } 
      if ( p < 27693 ) {
	  
	if ( ( a >= 4 ) ) 
	geqdefine ( p , 131 , curval ) ;
	else eqdefine ( p , 131 , curval ) ;
      } 
      else if ( p < 28525 ) {
	  
	if ( ( a >= 4 ) ) 
	geqdefine ( p , 131 , curval ) ;
	else eqdefine ( p , 131 , curval ) ;
      } 
      else if ( ( a >= 4 ) ) 
      geqworddefine ( p , curval ) ;
      else eqworddefine ( p , curval ) ;
    } 
    break ;
  case 94 : 
    {
      p = curchr ;
      scanfourbitint () ;
      p = p + curval ;
      scanoptionalequals () ;
      scanfontident () ;
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 131 , curval ) ;
      else eqdefine ( p , 131 , curval ) ;
    } 
    break ;
  case 99 : 
  case 100 : 
  case 101 : 
  case 102 : 
    doregistercommand ( a ) ;
    break ;
  case 108 : 
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
	  else printnl ( 262 ) ;
	  print ( 719 ) ;
	} 
	printesc ( 572 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1288 ;
	  helpline [0 ]= 1289 ;
	} 
	error () ;
      } 
    } 
    break ;
  case 87 : 
    alteraux () ;
    break ;
  case 88 : 
    alterprevgraf () ;
    break ;
  case 89 : 
    alterpagesofar () ;
    break ;
  case 90 : 
    alterinteger () ;
    break ;
  case 91 : 
    alterboxdimen () ;
    break ;
  case 92 : 
    {
      scanoptionalequals () ;
      scanint () ;
      n = curval ;
      if ( n <= 0 ) 
      p = -268435455L ;
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
      geqdefine ( 25060 , 129 , p ) ;
      else eqdefine ( 25060 , 129 , p ) ;
    } 
    break ;
  case 109 : 
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
	else printnl ( 262 ) ;
	print ( 1293 ) ;
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
  case 82 : 
    {
      findfontdimen ( true ) ;
      k = curval ;
      scanoptionalequals () ;
      scandimen ( false , false , false ) ;
      fontinfo [k ].cint = curval ;
    } 
    break ;
  case 83 : 
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
  case 98 : 
  case 97 : 
  case 96 : 
    newfont ( a ) ;
    break ;
  case 110 : 
    newinteraction () ;
    break ;
  case 86 : 
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
	  else printnl ( 262 ) ;
	  print ( 1396 ) ;
	} 
	printhex ( curval ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1397 ;
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
	  else printnl ( 262 ) ;
	  print ( 1398 ) ;
	} 
	printint ( n ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1397 ;
	} 
	error () ;
	return ;
      } 
      else if ( ( a >= 4 ) ) 
      geqdefine ( 26915 + n , n , toDVI ( curval ) ) ;
      else eqdefine ( 26915 + n , n , toDVI ( curval ) ) ;
    } 
    break ;
  case 111 : 
    {
      if ( curchr < 2 ) 
      p = 25633 ;
      else {
	  
	p = 25634 ;
	curchr = ( curchr % 2 ) ;
      } 
      if ( ( a >= 4 ) ) 
      geqdefine ( p , 131 , curchr ) ;
      else eqdefine ( p , 131 , curchr ) ;
    } 
    break ;
  case 85 : 
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
	    else printnl ( 262 ) ;
	    print ( 1413 ) ;
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1397 ;
	  } 
	  error () ;
	  return ;
	} 
	if ( ( a >= 4 ) ) 
	geqdefine ( 26403 + j , curval , n ) ;
	else eqdefine ( 26403 + j , curval , n ) ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 262 ) ;
	  print ( 1414 ) ;
	} 
	printhex ( n ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1397 ;
	} 
	error () ;
	return ;
      } 
    } 
    break ;
  case 84 : 
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
	    else printnl ( 262 ) ;
	    print ( 1420 ) ;
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1397 ;
	  } 
	  error () ;
	  return ;
	} 
	if ( ( p == 1 ) || ( p == 2 ) ) 
	{
	  if ( ( a >= 4 ) ) 
	  geqdefine ( 26659 + j , p , n ) ;
	  else eqdefine ( 26659 + j , p , n ) ;
	  if ( ( a >= 4 ) ) 
	  geqworddefine ( 29060 + j , curval ) ;
	  else eqworddefine ( 29060 + j , curval ) ;
	} 
	else confusion ( 534 ) ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 262 ) ;
	  print ( 1421 ) ;
	} 
	if ( p == 1 ) 
	print ( 1422 ) ;
	else if ( p == 2 ) 
	print ( 1423 ) ;
	else printchar ( 63 ) ;
	print ( 1424 ) ;
	printhex ( n ) ;
	printchar ( 41 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1397 ;
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
      else printnl ( 262 ) ;
      print ( 1336 ) ;
    } 
    {
      helpptr = 1 ;
      helpline [0 ]= 1337 ;
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
  print ( 1353 ) ;
  print ( jobname ) ;
  printchar ( 32 ) ;
  printint ( eqtb [28228 ].cint ) ;
  printchar ( 46 ) ;
  printint ( eqtb [28227 ].cint ) ;
  printchar ( 46 ) ;
  printint ( eqtb [28226 ].cint ) ;
  printchar ( 41 ) ;
  if ( interaction == 0 ) 
  selector = 18 ;
  else selector = 19 ;
  {
    if ( poolptr + 1 > poolsize ) 
    overflow ( 257 , poolsize - initpoolptr ) ;
  } 
  formatident = makestring () ;
  packjobname ( 836 ) ;
  while ( ! wopenout ( fmtfile ) ) promptfilename ( 1354 , 836 ) ;
  printnl ( 1355 ) ;
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
  dumpint ( 483236856L ) ;
  dumpthings ( xord [0 ], 256 ) ;
  dumpthings ( xchr [0 ], 256 ) ;
  dumpthings ( xprn [0 ], 256 ) ;
  dumpint ( 268435455L ) ;
  dumpint ( hashhigh ) ;
  dumpint ( membot ) ;
  dumpint ( memtop ) ;
  dumpint ( 29315 ) ;
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
  print ( 1338 ) ;
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
  while ( p != -268435455L ) {
      
    decr ( dynused ) ;
    p = mem [p ].hh .v.RH ;
  } 
  dumpint ( varused ) ;
  dumpint ( dynused ) ;
  println () ;
  printint ( x ) ;
  print ( 1339 ) ;
  printint ( varused ) ;
  printchar ( 38 ) ;
  printint ( dynused ) ;
  k = 1 ;
  do {
      j = k ;
    while ( j < 28204 ) {
	
      if ( ( eqtb [j ].hh .v.RH == eqtb [j + 1 ].hh .v.RH ) && ( eqtb [j 
      ].hh.b0 == eqtb [j + 1 ].hh.b0 ) && ( eqtb [j ].hh.b1 == eqtb [j + 
      1 ].hh.b1 ) ) 
      goto lab41 ;
      incr ( j ) ;
    } 
    l = 28205 ;
    goto lab31 ;
    lab41: incr ( j ) ;
    l = j ;
    while ( j < 28204 ) {
	
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
  } while ( ! ( k == 28205 ) ) ;
  do {
      j = k ;
    while ( j < 29315 ) {
	
      if ( eqtb [j ].cint == eqtb [j + 1 ].cint ) 
      goto lab42 ;
      incr ( j ) ;
    } 
    l = 29316 ;
    goto lab32 ;
    lab42: incr ( j ) ;
    l = j ;
    while ( j < 29315 ) {
	
      if ( eqtb [j ].cint != eqtb [j + 1 ].cint ) 
      goto lab32 ;
      incr ( j ) ;
    } 
    lab32: dumpint ( l - k ) ;
    dumpthings ( eqtb [k ], l - k ) ;
    k = j + 1 ;
    dumpint ( k - l ) ;
  } while ( ! ( k > 29315 ) ) ;
  if ( hashhigh > 0 ) 
  dumpthings ( eqtb [29316 ], hashhigh ) ;
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
  dumpthings ( hash [29316 ], hashhigh ) ;
  dumpint ( cscount ) ;
  println () ;
  printint ( cscount ) ;
  print ( 1340 ) ;
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
	printnl ( 1344 ) ;
	printesc ( hash [15525 + k ].v.RH ) ;
	printchar ( 61 ) ;
	printfilename ( fontname [k ], fontarea [k ], 343 ) ;
	if ( fontsize [k ]!= fontdsize [k ]) 
	{
	  print ( 787 ) ;
	  printscaled ( fontsize [k ]) ;
	  print ( 415 ) ;
	} 
      } 
    while ( k++ < for_end ) ;} 
  } 
  println () ;
  printint ( fmemptr - 7 ) ;
  print ( 1341 ) ;
  printint ( fontptr - 0 ) ;
  if ( fontptr != 1 ) 
  print ( 1342 ) ;
  else print ( 1343 ) ;
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
  print ( 1345 ) ;
  else print ( 1346 ) ;
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
  printnl ( 1347 ) ;
  printint ( triemax ) ;
  print ( 1348 ) ;
  printint ( trieopptr ) ;
  if ( trieopptr != 1 ) 
  print ( 1349 ) ;
  else print ( 1350 ) ;
  print ( 1351 ) ;
  printint ( trieopsize ) ;
  {register integer for_end; k = 255 ;for_end = 0 ; if ( k >= for_end) do 
    if ( trieused [k ]> 0 ) 
    {
      printnl ( 852 ) ;
      printint ( trieused [k ]) ;
      print ( 1352 ) ;
      printint ( k ) ;
      dumpint ( k ) ;
      dumpint ( trieused [k ]) ;
    } 
  while ( k-- > for_end ) ;} 
  dumpint ( interaction ) ;
  dumpint ( formatident ) ;
  dumpint ( 69069L ) ;
  eqtb [28236 ].cint = 0 ;
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
  if ( x != 483236856L ) 
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
  eqtbtop = 29315 + hashextra ;
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
  eqtb [24526 ].hh.b0 = 112 ;
  eqtb [24526 ].hh .v.RH = -268435455L ;
  eqtb [24526 ].hh.b1 = 0 ;
  {register integer for_end; x = 29316 ;for_end = eqtbtop ; if ( x <= 
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
  if ( x != 29315 ) 
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
    if ( ( x < 1 ) || ( k + x > 29316 ) ) 
    goto lab6666 ;
    undumpthings ( eqtb [k ], x ) ;
    k = k + x ;
    undumpint ( x ) ;
    if ( ( x < 0 ) || ( k + x > 29316 ) ) 
    goto lab6666 ;
    {register integer for_end; j = k ;for_end = k + x - 1 ; if ( j <= 
    for_end) do 
      eqtb [j ]= eqtb [k - 1 ];
    while ( j++ < for_end ) ;} 
    k = k + x ;
  } while ( ! ( k > 29315 ) ) ;
  if ( hashhigh > 0 ) 
  undumpthings ( eqtb [29316 ], hashhigh ) ;
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
    undumpthings ( hash [29316 ], hashhigh ) ;
    if ( debugformatfile ) 
    {
      printcsnames ( 29316 , hashhigh - ( 29316 ) ) ;
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
      
    print ( 1357 ) ;
    decr ( openparens ) ;
  } 
  if ( curlevel > 1 ) 
  {
    printnl ( 40 ) ;
    printesc ( 1358 ) ;
    print ( 1359 ) ;
    printint ( curlevel - 1 ) ;
    printchar ( 41 ) ;
  } 
  while ( condptr != -268435455L ) {
      
    printnl ( 40 ) ;
    printesc ( 1358 ) ;
    print ( 1360 ) ;
    printcmdchr ( 116 , curif ) ;
    if ( ifline != 0 ) 
    {
      print ( 1361 ) ;
      printint ( ifline ) ;
    } 
    print ( 1362 ) ;
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
	printnl ( 1363 ) ;
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
      if ( lastglue != 268435455L ) 
      deleteglueref ( lastglue ) ;
      storefmtfile () ;
      return ;
    } 
#endif /* INITEX */
    printnl ( 1364 ) ;
    return ;
  } 
} 
#ifdef INITEX
void 
initprim ( void ) 
{
  initprim_regmem 
  nonewcontrolsequence = false ;
  primitive ( 391 , 80 , 24527 ) ;
  primitive ( 392 , 80 , 24528 ) ;
  primitive ( 393 , 80 , 24529 ) ;
  primitive ( 394 , 80 , 24530 ) ;
  primitive ( 395 , 80 , 24531 ) ;
  primitive ( 396 , 80 , 24532 ) ;
  primitive ( 397 , 80 , 24533 ) ;
  primitive ( 398 , 80 , 24534 ) ;
  primitive ( 399 , 80 , 24535 ) ;
  primitive ( 400 , 80 , 24536 ) ;
  primitive ( 401 , 80 , 24537 ) ;
  primitive ( 402 , 80 , 24538 ) ;
  primitive ( 403 , 80 , 24539 ) ;
  primitive ( 404 , 80 , 24540 ) ;
  primitive ( 405 , 80 , 24541 ) ;
  primitive ( 406 , 81 , 24544 ) ;
  primitive ( 407 , 81 , 24545 ) ;
  primitive ( 408 , 81 , 24546 ) ;
  primitive ( 409 , 80 , 24542 ) ;
  primitive ( 410 , 80 , 24543 ) ;
  primitive ( 416 , 77 , 25061 ) ;
  primitive ( 417 , 77 , 25062 ) ;
  primitive ( 418 , 77 , 25063 ) ;
  primitive ( 419 , 77 , 25064 ) ;
  primitive ( 420 , 77 , 25065 ) ;
  primitive ( 421 , 77 , 25066 ) ;
  primitive ( 422 , 77 , 25067 ) ;
  primitive ( 423 , 77 , 25068 ) ;
  primitive ( 424 , 77 , 25069 ) ;
  primitive ( 443 , 78 , 28205 ) ;
  primitive ( 444 , 78 , 28206 ) ;
  primitive ( 445 , 78 , 28207 ) ;
  primitive ( 446 , 78 , 28208 ) ;
  primitive ( 447 , 78 , 28209 ) ;
  primitive ( 448 , 78 , 28210 ) ;
  primitive ( 449 , 78 , 28211 ) ;
  primitive ( 450 , 78 , 28212 ) ;
  primitive ( 451 , 78 , 28213 ) ;
  primitive ( 452 , 78 , 28214 ) ;
  primitive ( 453 , 78 , 28215 ) ;
  primitive ( 454 , 78 , 28216 ) ;
  primitive ( 455 , 78 , 28217 ) ;
  primitive ( 456 , 78 , 28218 ) ;
  primitive ( 457 , 78 , 28219 ) ;
  primitive ( 458 , 78 , 28220 ) ;
  primitive ( 459 , 78 , 28221 ) ;
  primitive ( 460 , 78 , 28222 ) ;
  primitive ( 461 , 78 , 28223 ) ;
  primitive ( 462 , 78 , 28224 ) ;
  primitive ( 463 , 78 , 28225 ) ;
  primitive ( 464 , 78 , 28226 ) ;
  primitive ( 465 , 78 , 28227 ) ;
  primitive ( 466 , 78 , 28228 ) ;
  primitive ( 467 , 78 , 28229 ) ;
  primitive ( 468 , 78 , 28230 ) ;
  primitive ( 469 , 78 , 28231 ) ;
  primitive ( 470 , 78 , 28232 ) ;
  primitive ( 471 , 78 , 28233 ) ;
  primitive ( 472 , 78 , 28234 ) ;
  primitive ( 473 , 78 , 28235 ) ;
  primitive ( 474 , 78 , 28236 ) ;
  primitive ( 475 , 78 , 28237 ) ;
  primitive ( 476 , 78 , 28238 ) ;
  primitive ( 477 , 78 , 28239 ) ;
  primitive ( 478 , 78 , 28240 ) ;
  primitive ( 479 , 78 , 28241 ) ;
  primitive ( 480 , 78 , 28242 ) ;
  primitive ( 481 , 78 , 28243 ) ;
  primitive ( 482 , 78 , 28244 ) ;
  primitive ( 483 , 78 , 28245 ) ;
  primitive ( 484 , 78 , 28246 ) ;
  primitive ( 485 , 78 , 28247 ) ;
  primitive ( 486 , 78 , 28248 ) ;
  primitive ( 487 , 78 , 28249 ) ;
  primitive ( 488 , 78 , 28251 ) ;
  primitive ( 489 , 78 , 28252 ) ;
  primitive ( 490 , 78 , 28253 ) ;
  primitive ( 491 , 78 , 28254 ) ;
  primitive ( 492 , 78 , 28255 ) ;
  primitive ( 493 , 78 , 28250 ) ;
  primitive ( 494 , 78 , 28261 ) ;
  primitive ( 495 , 78 , 28262 ) ;
  primitive ( 496 , 78 , 28263 ) ;
  primitive ( 497 , 78 , 28264 ) ;
  primitive ( 498 , 78 , 28256 ) ;
  primitive ( 499 , 78 , 28257 ) ;
  primitive ( 500 , 78 , 28258 ) ;
  primitive ( 501 , 78 , 28259 ) ;
  primitive ( 502 , 78 , 28260 ) ;
  if ( mltexp ) 
  {
    mltexenabledp = true ;
    if ( false ) 
    primitive ( 503 , 78 , 28265 ) ;
    primitive ( 504 , 78 , 28266 ) ;
    primitive ( 505 , 78 , 28267 ) ;
  } 
  primitive ( 509 , 79 , 28781 ) ;
  primitive ( 510 , 79 , 28782 ) ;
  primitive ( 511 , 79 , 28783 ) ;
  primitive ( 512 , 79 , 28784 ) ;
  primitive ( 513 , 79 , 28785 ) ;
  primitive ( 514 , 79 , 28786 ) ;
  primitive ( 515 , 79 , 28787 ) ;
  primitive ( 516 , 79 , 28788 ) ;
  primitive ( 517 , 79 , 28789 ) ;
  primitive ( 518 , 79 , 28790 ) ;
  primitive ( 519 , 79 , 28791 ) ;
  primitive ( 520 , 79 , 28792 ) ;
  primitive ( 521 , 79 , 28793 ) ;
  primitive ( 522 , 79 , 28794 ) ;
  primitive ( 523 , 79 , 28795 ) ;
  primitive ( 524 , 79 , 28796 ) ;
  primitive ( 525 , 79 , 28797 ) ;
  primitive ( 526 , 79 , 28798 ) ;
  primitive ( 527 , 79 , 28799 ) ;
  primitive ( 528 , 79 , 28800 ) ;
  primitive ( 529 , 79 , 28802 ) ;
  primitive ( 530 , 79 , 28803 ) ;
  primitive ( 531 , 79 , 28801 ) ;
  primitive ( 32 , 67 , 0 ) ;
  primitive ( 47 , 47 , 0 ) ;
  primitive ( 542 , 48 , 0 ) ;
  primitive ( 543 , 100 , 0 ) ;
  primitive ( 544 , 43 , 0 ) ;
  primitive ( 545 , 44 , 0 ) ;
  primitive ( 546 , 64 , 0 ) ;
  primitive ( 547 , 19 , 0 ) ;
  primitive ( 538 , 118 , 0 ) ;
  primitive ( 548 , 15 , 0 ) ;
  primitive ( 549 , 102 , 0 ) ;
  primitive ( 539 , 70 , 0 ) ;
  primitive ( 550 , 65 , 0 ) ;
  hash [15516 ].v.RH = 550 ;
  eqtb [15516 ]= eqtb [curval ];
  primitive ( 551 , 113 , 0 ) ;
  primitive ( 552 , 96 , 0 ) ;
  primitive ( 553 , 97 , 0 ) ;
  primitive ( 554 , 98 , 0 ) ;
  primitive ( 555 , 82 , 0 ) ;
  primitive ( 556 , 35 , 0 ) ;
  primitive ( 557 , 39 , 0 ) ;
  primitive ( 558 , 42 , 0 ) ;
  primitive ( 335 , 40 , 0 ) ;
  primitive ( 358 , 21 , 0 ) ;
  primitive ( 559 , 49 , 0 ) ;
  primitive ( 560 , 20 , 0 ) ;
  primitive ( 561 , 57 , 0 ) ;
  primitive ( 562 , 101 , 0 ) ;
  primitive ( 563 , 37 , 0 ) ;
  primitive ( 564 , 68 , 0 ) ;
  primitive ( 565 , 114 , 0 ) ;
  primitive ( 340 , 58 , 0 ) ;
  primitive ( 566 , 66 , 0 ) ;
  primitive ( 426 , 92 , 0 ) ;
  primitive ( 567 , 45 , 0 ) ;
  primitive ( 568 , 88 , 0 ) ;
  primitive ( 569 , 69 , 0 ) ;
  primitive ( 570 , 106 , 0 ) ;
  primitive ( 571 , 0 , 256 ) ;
  hash [15521 ].v.RH = 571 ;
  eqtb [15521 ]= eqtb [curval ];
  primitive ( 572 , 108 , 0 ) ;
  primitive ( 573 , 120 , 0 ) ;
  primitive ( 425 , 76 , 0 ) ;
  primitive ( 359 , 41 , 0 ) ;
  primitive ( 574 , 36 , 0 ) ;
  primitive ( 575 , 59 , 0 ) ;
  primitive ( 576 , 38 , 0 ) ;
  primitive ( 633 , 13 , 256 ) ;
  parloc = curval ;
  partoken = 65535L + parloc ;
  primitive ( 668 , 115 , 0 ) ;
  primitive ( 669 , 115 , 1 ) ;
  primitive ( 670 , 121 , 0 ) ;
  primitive ( 671 , 121 , 1 ) ;
  primitive ( 672 , 121 , 2 ) ;
  primitive ( 673 , 121 , 3 ) ;
  primitive ( 674 , 121 , 4 ) ;
  primitive ( 507 , 99 , 0 ) ;
  primitive ( 533 , 99 , 1 ) ;
  primitive ( 413 , 99 , 2 ) ;
  primitive ( 414 , 99 , 3 ) ;
  primitive ( 707 , 87 , 113 ) ;
  primitive ( 708 , 87 , 1 ) ;
  primitive ( 709 , 90 , 0 ) ;
  primitive ( 710 , 90 , 1 ) ;
  primitive ( 711 , 91 , 1 ) ;
  primitive ( 712 , 91 , 3 ) ;
  primitive ( 713 , 91 , 2 ) ;
  primitive ( 714 , 73 , 0 ) ;
  primitive ( 715 , 73 , 1 ) ;
  primitive ( 716 , 73 , 2 ) ;
  primitive ( 717 , 73 , 3 ) ;
  primitive ( 718 , 73 , 4 ) ;
  primitive ( 776 , 119 , 0 ) ;
  primitive ( 777 , 119 , 1 ) ;
  primitive ( 778 , 119 , 3 ) ;
  primitive ( 779 , 119 , 4 ) ;
  primitive ( 780 , 119 , 5 ) ;
  primitive ( 781 , 119 , 2 ) ;
  primitive ( 782 , 119 , 6 ) ;
  primitive ( 783 , 119 , 7 ) ;
  primitive ( 784 , 119 , 8 ) ;
  primitive ( 785 , 119 , 9 ) ;
  primitive ( 786 , 119 , 10 ) ;
  primitive ( 802 , 116 , 0 ) ;
  primitive ( 803 , 116 , 1 ) ;
  primitive ( 804 , 116 , 2 ) ;
  primitive ( 805 , 116 , 3 ) ;
  primitive ( 806 , 116 , 4 ) ;
  primitive ( 807 , 116 , 5 ) ;
  primitive ( 808 , 116 , 6 ) ;
  primitive ( 809 , 116 , 7 ) ;
  primitive ( 810 , 116 , 8 ) ;
  primitive ( 811 , 116 , 9 ) ;
  primitive ( 812 , 116 , 10 ) ;
  primitive ( 813 , 116 , 11 ) ;
  primitive ( 814 , 116 , 12 ) ;
  primitive ( 815 , 116 , 13 ) ;
  primitive ( 816 , 116 , 14 ) ;
  primitive ( 817 , 116 , 15 ) ;
  primitive ( 818 , 116 , 16 ) ;
  primitive ( 819 , 116 , 17 ) ;
  primitive ( 820 , 116 , 18 ) ;
  primitive ( 821 , 116 , 19 ) ;
  primitive ( 822 , 116 , 20 ) ;
  primitive ( 823 , 116 , 21 ) ;
  primitive ( 824 , 116 , 22 ) ;
  primitive ( 825 , 116 , 23 ) ;
  primitive ( 826 , 117 , 2 ) ;
  hash [15518 ].v.RH = 826 ;
  eqtb [15518 ]= eqtb [curval ];
  primitive ( 827 , 117 , 4 ) ;
  primitive ( 828 , 117 , 3 ) ;
  primitive ( 853 , 95 , 0 ) ;
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
  eqtb [15519 ].hh.b0 = 126 ;
  primitive ( 1024 , 89 , 0 ) ;
  primitive ( 1025 , 89 , 1 ) ;
  primitive ( 1026 , 89 , 2 ) ;
  primitive ( 1027 , 89 , 3 ) ;
  primitive ( 1028 , 89 , 4 ) ;
  primitive ( 1029 , 89 , 5 ) ;
  primitive ( 1030 , 89 , 6 ) ;
  primitive ( 1031 , 89 , 7 ) ;
  primitive ( 1080 , 14 , 0 ) ;
  primitive ( 1081 , 14 , 1 ) ;
  primitive ( 1082 , 29 , 4 ) ;
  primitive ( 1083 , 29 , 0 ) ;
  primitive ( 1084 , 29 , 1 ) ;
  primitive ( 1085 , 29 , 2 ) ;
  primitive ( 1086 , 29 , 3 ) ;
  primitive ( 1087 , 30 , 4 ) ;
  primitive ( 1088 , 30 , 0 ) ;
  primitive ( 1089 , 30 , 1 ) ;
  primitive ( 1090 , 30 , 2 ) ;
  primitive ( 1091 , 30 , 3 ) ;
  primitive ( 341 , 31 , 5 ) ;
  primitive ( 345 , 32 , 1 ) ;
  primitive ( 347 , 33 , 99 ) ;
  primitive ( 1109 , 24 , 1 ) ;
  primitive ( 1110 , 24 , 0 ) ;
  primitive ( 1111 , 25 , 1 ) ;
  primitive ( 1112 , 25 , 0 ) ;
  primitive ( 427 , 23 , 0 ) ;
  primitive ( 1113 , 23 , 1 ) ;
  primitive ( 1114 , 23 , 2 ) ;
  primitive ( 1019 , 23 , 3 ) ;
  primitive ( 1115 , 23 , 4 ) ;
  primitive ( 1021 , 23 , 5 ) ;
  primitive ( 1116 , 23 , 117 ) ;
  primitive ( 1117 , 75 , 3 ) ;
  primitive ( 1118 , 75 , 4 ) ;
  primitive ( 1119 , 75 , 1 ) ;
  primitive ( 1120 , 34 , 99 ) ;
  primitive ( 1121 , 34 , 100 ) ;
  primitive ( 1122 , 34 , 101 ) ;
  primitive ( 1123 , 34 , 102 ) ;
  primitive ( 1145 , 46 , 1 ) ;
  primitive ( 1146 , 46 , 0 ) ;
  primitive ( 1157 , 28 , 14 ) ;
  primitive ( 1158 , 28 , 13 ) ;
  primitive ( 1159 , 28 , 12 ) ;
  primitive ( 1160 , 26 , 0 ) ;
  primitive ( 1161 , 26 , 1 ) ;
  primitive ( 1162 , 27 , 0 ) ;
  primitive ( 1163 , 27 , 1 ) ;
  primitive ( 45 , 50 , 1 ) ;
  primitive ( 356 , 50 , 0 ) ;
  primitive ( 1196 , 51 , 0 ) ;
  primitive ( 1197 , 51 , 1 ) ;
  primitive ( 919 , 53 , 18 ) ;
  primitive ( 920 , 53 , 19 ) ;
  primitive ( 921 , 53 , 20 ) ;
  primitive ( 922 , 53 , 21 ) ;
  primitive ( 923 , 53 , 22 ) ;
  primitive ( 924 , 53 , 23 ) ;
  primitive ( 925 , 53 , 24 ) ;
  primitive ( 926 , 53 , 25 ) ;
  primitive ( 928 , 53 , 28 ) ;
  primitive ( 927 , 53 , 29 ) ;
  primitive ( 1201 , 54 , 0 ) ;
  primitive ( 931 , 54 , 1 ) ;
  primitive ( 932 , 54 , 2 ) ;
  primitive ( 914 , 56 , 0 ) ;
  primitive ( 915 , 56 , 2 ) ;
  primitive ( 916 , 56 , 4 ) ;
  primitive ( 917 , 56 , 6 ) ;
  primitive ( 1219 , 55 , 0 ) ;
  primitive ( 1220 , 55 , 1 ) ;
  primitive ( 1221 , 55 , 2 ) ;
  primitive ( 1222 , 55 , 3 ) ;
  primitive ( 1223 , 55 , 4 ) ;
  primitive ( 1224 , 55 , 5 ) ;
  primitive ( 929 , 52 , 32 ) ;
  primitive ( 930 , 52 , 33 ) ;
  hash [15517 ].v.RH = 930 ;
  eqtb [15517 ]= eqtb [curval ];
  primitive ( 1243 , 103 , 1 ) ;
  primitive ( 1244 , 103 , 2 ) ;
  primitive ( 1245 , 103 , 4 ) ;
  primitive ( 1246 , 107 , 0 ) ;
  primitive ( 1247 , 107 , 1 ) ;
  primitive ( 1248 , 107 , 2 ) ;
  primitive ( 1249 , 107 , 3 ) ;
  primitive ( 1263 , 104 , 0 ) ;
  primitive ( 1264 , 104 , 1 ) ;
  primitive ( 1265 , 105 , 0 ) ;
  primitive ( 1266 , 105 , 1 ) ;
  primitive ( 1267 , 105 , 2 ) ;
  primitive ( 1268 , 105 , 3 ) ;
  primitive ( 1269 , 105 , 4 ) ;
  primitive ( 1270 , 105 , 5 ) ;
  primitive ( 1271 , 105 , 6 ) ;
  if ( mltexp ) 
  {
    primitive ( 1272 , 105 , 7 ) ;
  } 
  primitive ( 433 , 93 , 25635 ) ;
  primitive ( 434 , 93 , 25891 ) ;
  primitive ( 435 , 93 , 26147 ) ;
  primitive ( 442 , 93 , 27693 ) ;
  primitive ( 439 , 93 , 26925 ) ;
  primitive ( 440 , 93 , 27181 ) ;
  primitive ( 441 , 93 , 27437 ) ;
  primitive ( 508 , 93 , 28525 ) ;
  primitive ( 430 , 94 , 25583 ) ;
  primitive ( 431 , 94 , 25599 ) ;
  primitive ( 432 , 94 , 25615 ) ;
  primitive ( 995 , 109 , 0 ) ;
  primitive ( 1007 , 109 , 1 ) ;
  primitive ( 1294 , 83 , 0 ) ;
  primitive ( 1295 , 83 , 1 ) ;
  primitive ( 272 , 110 , 0 ) ;
  primitive ( 273 , 110 , 1 ) ;
  primitive ( 274 , 110 , 2 ) ;
  primitive ( 1304 , 110 , 3 ) ;
  primitive ( 1305 , 63 , 1 ) ;
  primitive ( 1306 , 63 , 0 ) ;
  primitive ( 1307 , 61 , 0 ) ;
  primitive ( 1308 , 61 , 1 ) ;
  primitive ( 1314 , 60 , 26925 ) ;
  primitive ( 1315 , 60 , 27181 ) ;
  primitive ( 1316 , 22 , 0 ) ;
  primitive ( 1317 , 22 , 1 ) ;
  primitive ( 1318 , 22 , 2 ) ;
  primitive ( 1319 , 22 , 3 ) ;
  primitive ( 1320 , 22 , 4 ) ;
  primitive ( 1366 , 62 , 0 ) ;
  primitive ( 630 , 62 , 1 ) ;
  writeloc = curval ;
  primitive ( 1367 , 62 , 2 ) ;
  primitive ( 1368 , 62 , 3 ) ;
  hash [15524 ].v.RH = 1368 ;
  eqtb [15524 ]= eqtb [curval ];
  primitive ( 1369 , 62 , 4 ) ;
  primitive ( 1370 , 62 , 5 ) ;
  primitive ( 1395 , 78 , 28268 ) ;
  primitive ( 438 , 86 , 0 ) ;
  primitive ( 1399 , 111 , 1 ) ;
  primitive ( 1400 , 111 , 0 ) ;
  primitive ( 1401 , 111 , 3 ) ;
  primitive ( 1402 , 111 , 2 ) ;
  primitive ( 1411 , 74 , 0 ) ;
  primitive ( 1412 , 85 , 26403 ) ;
  primitive ( 1415 , 84 , 1 ) ;
  primitive ( 1416 , 84 , 2 ) ;
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
    eqtbtop = 29315 + hashextra ;
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
  if ( ( 0 > 0 ) || ( 255 < 127 ) ) 
  bad = 11 ;
  if ( ( -268435455L > 0 ) || ( 268435455L < 32767 ) ) 
  bad = 12 ;
  if ( ( 0 < -268435455L ) || ( 255 > 268435455L ) ) 
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
  if ( 255 < 255 ) 
  bad = 19 ;
  if ( 94850L + hashextra > 268435455L ) 
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
    dateandtime ( eqtb [28225 ].cint , eqtb [28226 ].cint , eqtb [28227 ]
    .cint , eqtb [28228 ].cint ) ;
  } 
#endif /* INITEX */
  readyalready = 314159L ;
  lab1: selector = 17 ;
  tally = 0 ;
  termoffset = 0 ;
  fileoffset = 0 ;
  kcodepos = 0 ;
  if ( srcspecialsp || filelineerrorstylep || parsefirstlinep ) 
  fprintf ( stdout , "%s%s",  "This is pTeX, Version 3.14159265" , "-p3.7.1" ) ;
  else
  fprintf ( stdout , "%s%s",  "This is pTeX, Version 3.14159265" , "-p3.7.1" ) ;
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
    if ( ( eqtb [28254 ].cint < 0 ) || ( eqtb [28254 ].cint > 255 ) ) 
    decr ( curinput .limitfield ) ;
    else buffer [curinput .limitfield ]= eqtb [28254 ].cint ;
    if ( mltexenabledp ) 
    {
      fprintf ( stdout , "%s\n",  "MLTeX v2.2 enabled" ) ;
    } 
    dateandtime ( eqtb [28225 ].cint , eqtb [28226 ].cint , eqtb [28227 ]
    .cint , eqtb [28228 ].cint ) ;
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
    magicoffset = strstart [946 ]- 9 * 18 ;
    if ( interaction == 0 ) 
    selector = 16 ;
    else selector = 17 ;
    if ( ( curinput .locfield < curinput .limitfield ) && ( eqtb [25635 + 
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
