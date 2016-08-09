#define EXTERN extern
#include "mfluajitd.h"

#ifdef INIMF
boolean 
getstringsstarted ( void ) 
{
  /* 30 10 */ register boolean Result; unsigned char k, l  ;
  strnumber g  ;
  poolptr = 0 ;
  strptr = 0 ;
  maxpoolptr = 0 ;
  maxstrptr = 0 ;
  strstart [0 ]= 0 ;
  {register integer for_end; k = 0 ;for_end = 255 ; if ( k <= for_end) do 
    {
      if ( ( ( k < 32 ) || ( k > 126 ) ) ) 
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
      strref [g ]= 127 ;
    } 
  while ( k++ < for_end ) ;} 
  g = loadpoolstrings ( ( poolsize - stringvacancies ) ) ;
  if ( g == 0 ) 
  {
    ;
    fprintf ( stdout , "%s\n",  "! You have to increase POOLSIZE." ) ;
    Result = false ;
    goto lab10 ;
  } 
  Result = true ;
  lab10: ;
  return Result ;
} 
#endif /* INIMF */
#ifdef INIMF
void 
sortavail ( void ) 
{
  halfword p, q, r  ;
  halfword oldrover  ;
  p = getnode ( 1073741824L ) ;
  p = mem [rover + 1 ].hhfield .v.RH ;
  mem [rover + 1 ].hhfield .v.RH = 268435455L ;
  oldrover = rover ;
  while ( p != oldrover ) if ( p < rover ) 
  {
    q = p ;
    p = mem [q + 1 ].hhfield .v.RH ;
    mem [q + 1 ].hhfield .v.RH = rover ;
    rover = q ;
  } 
  else {
      
    q = rover ;
    while ( mem [q + 1 ].hhfield .v.RH < p ) q = mem [q + 1 ].hhfield 
    .v.RH ;
    r = mem [p + 1 ].hhfield .v.RH ;
    mem [p + 1 ].hhfield .v.RH = mem [q + 1 ].hhfield .v.RH ;
    mem [q + 1 ].hhfield .v.RH = p ;
    p = r ;
  } 
  p = rover ;
  while ( mem [p + 1 ].hhfield .v.RH != 268435455L ) {
      
    mem [mem [p + 1 ].hhfield .v.RH + 1 ].hhfield .lhfield = p ;
    p = mem [p + 1 ].hhfield .v.RH ;
  } 
  mem [p + 1 ].hhfield .v.RH = rover ;
  mem [rover + 1 ].hhfield .lhfield = p ;
} 
#endif /* INIMF */
#ifdef INIMF
void 
zprimitive ( strnumber s , halfword c , halfword o ) 
{
  poolpointer k  ;
  smallnumber j  ;
  smallnumber l  ;
  k = strstart [s ];
  l = strstart [s + 1 ]- k ;
  {register integer for_end; j = 0 ;for_end = l - 1 ; if ( j <= for_end) do 
    buffer [j ]= strpool [k + j ];
  while ( j++ < for_end ) ;} 
  cursym = idlookup ( 0 , l ) ;
  if ( s >= 256 ) 
  {
    flushstring ( strptr - 1 ) ;
    hash [cursym ].v.RH = s ;
  } 
  eqtb [cursym ].lhfield = c ;
  eqtb [cursym ].v.RH = o ;
} 
#endif /* INIMF */
#ifdef INIMF
void 
storebasefile ( void ) 
{
  integer k  ;
  halfword p, q  ;
  integer x  ;
  fourquarters w  ;
  ASCIIcode * baseengine  ;
  selector = 5 ;
  print ( 1074 ) ;
  print ( jobname ) ;
  printchar ( 32 ) ;
  printint ( roundunscaled ( internal [14 ]) ) ;
  printchar ( 46 ) ;
  printint ( roundunscaled ( internal [15 ]) ) ;
  printchar ( 46 ) ;
  printint ( roundunscaled ( internal [16 ]) ) ;
  printchar ( 41 ) ;
  if ( interaction == 0 ) 
  selector = 2 ;
  else selector = 3 ;
  {
    if ( poolptr + 1 > maxpoolptr ) 
    {
      if ( poolptr + 1 > poolsize ) 
      overflow ( 257 , poolsize - initpoolptr ) ;
      maxpoolptr = poolptr + 1 ;
    } 
  } 
  baseident = makestring () ;
  strref [baseident ]= 127 ;
  packjobname ( 743 ) ;
  while ( ! wopenout ( basefile ) ) promptfilename ( 1075 , 743 ) ;
  printnl ( 1076 ) ;
  slowprint ( wmakenamestring ( basefile ) ) ;
  flushstring ( strptr - 1 ) ;
  printnl ( 261 ) ;
  slowprint ( baseident ) ;
  dumpint ( 1462914374L ) ;
  x = strlen ( enginename ) ;
  baseengine = xmallocarray ( ASCIIcode , x + 4 ) ;
  strcpy ( stringcast ( baseengine ) , enginename ) ;
  {register integer for_end; k = x ;for_end = x + 3 ; if ( k <= for_end) do 
    baseengine [k ]= 0 ;
  while ( k++ < for_end ) ;} 
  x = x + 4 - ( x % 4 ) ;
  dumpint ( x ) ;
  dumpthings ( baseengine [0 ], x ) ;
  libcfree ( baseengine ) ;
  dumpint ( 228418379L ) ;
  dumpthings ( xord [0 ], 256 ) ;
  dumpthings ( xchr [0 ], 256 ) ;
  dumpthings ( xprn [0 ], 256 ) ;
  dumpint ( 0 ) ;
  dumpint ( memtop ) ;
  dumpint ( 9500 ) ;
  dumpint ( 7919 ) ;
  dumpint ( 15 ) ;
  dumpint ( poolptr ) ;
  dumpint ( strptr ) ;
  {register integer for_end; k = 0 ;for_end = strptr ; if ( k <= for_end) do 
    dumpint ( strstart [k ]) ;
  while ( k++ < for_end ) ;} 
  k = 0 ;
  while ( k + 4 < poolptr ) {
      
    w .b0 = strpool [k ];
    w .b1 = strpool [k + 1 ];
    w .b2 = strpool [k + 2 ];
    w .b3 = strpool [k + 3 ];
    dumpqqqq ( w ) ;
    k = k + 4 ;
  } 
  k = poolptr - 4 ;
  w .b0 = strpool [k ];
  w .b1 = strpool [k + 1 ];
  w .b2 = strpool [k + 2 ];
  w .b3 = strpool [k + 3 ];
  dumpqqqq ( w ) ;
  println () ;
  printint ( strptr ) ;
  print ( 1071 ) ;
  printint ( poolptr ) ;
  sortavail () ;
  varused = 0 ;
  dumpint ( lomemmax ) ;
  dumpint ( rover ) ;
  p = 0 ;
  q = rover ;
  x = 0 ;
  do {
      { register integer for_end; k = p ;for_end = q + 1 ; if ( k <= 
    for_end) do 
      dumpwd ( mem [k ]) ;
    while ( k++ < for_end ) ;} 
    x = x + q + 2 - p ;
    varused = varused + q - p ;
    p = q + mem [q ].hhfield .lhfield ;
    q = mem [q + 1 ].hhfield .v.RH ;
  } while ( ! ( q == rover ) ) ;
  varused = varused + lomemmax - p ;
  dynused = memend + 1 - himemmin ;
  {register integer for_end; k = p ;for_end = lomemmax ; if ( k <= for_end) 
  do 
    dumpwd ( mem [k ]) ;
  while ( k++ < for_end ) ;} 
  x = x + lomemmax + 1 - p ;
  dumpint ( himemmin ) ;
  dumpint ( avail ) ;
  {register integer for_end; k = himemmin ;for_end = memend ; if ( k <= 
  for_end) do 
    dumpwd ( mem [k ]) ;
  while ( k++ < for_end ) ;} 
  x = x + memend + 1 - himemmin ;
  p = avail ;
  while ( p != 0 ) {
      
    decr ( dynused ) ;
    p = mem [p ].hhfield .v.RH ;
  } 
  dumpint ( varused ) ;
  dumpint ( dynused ) ;
  println () ;
  printint ( x ) ;
  print ( 1072 ) ;
  printint ( varused ) ;
  printchar ( 38 ) ;
  printint ( dynused ) ;
  dumpint ( hashused ) ;
  stcount = 9756 - hashused ;
  {register integer for_end; p = 1 ;for_end = hashused ; if ( p <= for_end) 
  do 
    if ( hash [p ].v.RH != 0 ) 
    {
      dumpint ( p ) ;
      dumphh ( hash [p ]) ;
      dumphh ( eqtb [p ]) ;
      incr ( stcount ) ;
    } 
  while ( p++ < for_end ) ;} 
  {register integer for_end; p = hashused + 1 ;for_end = 9769 ; if ( p <= 
  for_end) do 
    {
      dumphh ( hash [p ]) ;
      dumphh ( eqtb [p ]) ;
    } 
  while ( p++ < for_end ) ;} 
  dumpint ( stcount ) ;
  println () ;
  printint ( stcount ) ;
  print ( 1073 ) ;
  dumpint ( intptr ) ;
  {register integer for_end; k = 1 ;for_end = intptr ; if ( k <= for_end) do 
    {
      dumpint ( internal [k ]) ;
      dumpint ( intname [k ]) ;
    } 
  while ( k++ < for_end ) ;} 
  dumpint ( startsym ) ;
  dumpint ( interaction ) ;
  dumpint ( baseident ) ;
  dumpint ( bgloc ) ;
  dumpint ( egloc ) ;
  dumpint ( serialno ) ;
  dumpint ( 69069L ) ;
  internal [12 ]= 0 ;
  wclose ( basefile ) ;
} 
#endif /* INIMF */
boolean 
loadbasefile ( void ) 
{
  /* 6666 10 */ register boolean Result; integer k  ;
  halfword p, q  ;
  integer x  ;
  fourquarters w  ;
  ASCIIcode * baseengine  ;
  ASCIIcode dummyxord  ;
  ASCIIcode dummyxchr  ;
  ASCIIcode dummyxprn  ;
  undumpint ( x ) ;
  if ( x != 1462914374L ) 
  goto lab6666 ;
  undumpint ( x ) ;
  if ( ( x < 0 ) || ( x > 256 ) ) 
  goto lab6666 ;
  baseengine = xmallocarray ( ASCIIcode , x ) ;
  undumpthings ( baseengine [0 ], x ) ;
  baseengine [x - 1 ]= 0 ;
  if ( strcmp ( enginename , stringcast ( baseengine ) ) ) 
  {
    ;
    fprintf ( stdout , "%s%s%s%s\n",  "---! " , stringcast ( nameoffile + 1 ) ,     " was written by " , stringcast ( baseengine ) ) ;
    libcfree ( baseengine ) ;
    goto lab6666 ;
  } 
  libcfree ( baseengine ) ;
  undumpint ( x ) ;
  if ( x != 228418379L ) 
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
  if ( x != 0 ) 
  goto lab6666 ;
	;
#ifdef INIMF
  if ( iniversion ) 
  {
    libcfree ( mem ) ;
  } 
#endif /* INIMF */
  undumpint ( memtop ) ;
  if ( memmax < memtop ) 
  memmax = memtop ;
  if ( 1100 > memtop ) 
  goto lab6666 ;
  mem = xmallocarray ( memoryword , memmax + 1 ) ;
  undumpint ( x ) ;
  if ( x != 9500 ) 
  goto lab6666 ;
  undumpint ( x ) ;
  if ( x != 7919 ) 
  goto lab6666 ;
  undumpint ( x ) ;
  if ( x != 15 ) 
  goto lab6666 ;
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > poolsize ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "string pool size" ) ;
      goto lab6666 ;
    } 
    else poolptr = x ;
  } 
  {
    undumpint ( x ) ;
    if ( x < 0 ) 
    goto lab6666 ;
    if ( x > maxstrings ) 
    {
      ;
      fprintf ( stdout , "%s%s\n",  "---! Must increase the " , "max strings" ) ;
      goto lab6666 ;
    } 
    else strptr = x ;
  } 
  {register integer for_end; k = 0 ;for_end = strptr ; if ( k <= for_end) do 
    {
      {
	undumpint ( x ) ;
	if ( ( x < 0 ) || ( x > poolptr ) ) 
	goto lab6666 ;
	else strstart [k ]= x ;
      } 
      strref [k ]= 127 ;
    } 
  while ( k++ < for_end ) ;} 
  k = 0 ;
  while ( k + 4 < poolptr ) {
      
    undumpqqqq ( w ) ;
    strpool [k ]= w .b0 ;
    strpool [k + 1 ]= w .b1 ;
    strpool [k + 2 ]= w .b2 ;
    strpool [k + 3 ]= w .b3 ;
    k = k + 4 ;
  } 
  k = poolptr - 4 ;
  undumpqqqq ( w ) ;
  strpool [k ]= w .b0 ;
  strpool [k + 1 ]= w .b1 ;
  strpool [k + 2 ]= w .b2 ;
  strpool [k + 3 ]= w .b3 ;
  initstrptr = strptr ;
  initpoolptr = poolptr ;
  maxstrptr = strptr ;
  maxpoolptr = poolptr ;
  {
    undumpint ( x ) ;
    if ( ( x < 1022 ) || ( x > memtop - 3 ) ) 
    goto lab6666 ;
    else lomemmax = x ;
  } 
  {
    undumpint ( x ) ;
    if ( ( x < 23 ) || ( x > lomemmax ) ) 
    goto lab6666 ;
    else rover = x ;
  } 
  p = 0 ;
  q = rover ;
  do {
      { register integer for_end; k = p ;for_end = q + 1 ; if ( k <= 
    for_end) do 
      undumpwd ( mem [k ]) ;
    while ( k++ < for_end ) ;} 
    p = q + mem [q ].hhfield .lhfield ;
    if ( ( p > lomemmax ) || ( ( q >= mem [q + 1 ].hhfield .v.RH ) && ( mem 
    [q + 1 ].hhfield .v.RH != rover ) ) ) 
    goto lab6666 ;
    q = mem [q + 1 ].hhfield .v.RH ;
  } while ( ! ( q == rover ) ) ;
  {register integer for_end; k = p ;for_end = lomemmax ; if ( k <= for_end) 
  do 
    undumpwd ( mem [k ]) ;
  while ( k++ < for_end ) ;} 
  {
    undumpint ( x ) ;
    if ( ( x < lomemmax + 1 ) || ( x > memtop - 2 ) ) 
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
  {register integer for_end; k = himemmin ;for_end = memend ; if ( k <= 
  for_end) do 
    undumpwd ( mem [k ]) ;
  while ( k++ < for_end ) ;} 
  undumpint ( varused ) ;
  undumpint ( dynused ) ;
  {
    undumpint ( x ) ;
    if ( ( x < 1 ) || ( x > 9757 ) ) 
    goto lab6666 ;
    else hashused = x ;
  } 
  p = 0 ;
  do {
      { 
      undumpint ( x ) ;
      if ( ( x < p + 1 ) || ( x > hashused ) ) 
      goto lab6666 ;
      else p = x ;
    } 
    undumphh ( hash [p ]) ;
    undumphh ( eqtb [p ]) ;
  } while ( ! ( p == hashused ) ) ;
  {register integer for_end; p = hashused + 1 ;for_end = 9769 ; if ( p <= 
  for_end) do 
    {
      undumphh ( hash [p ]) ;
      undumphh ( eqtb [p ]) ;
    } 
  while ( p++ < for_end ) ;} 
  undumpint ( stcount ) ;
  {
    undumpint ( x ) ;
    if ( ( x < 41 ) || ( x > maxinternal ) ) 
    goto lab6666 ;
    else intptr = x ;
  } 
  {register integer for_end; k = 1 ;for_end = intptr ; if ( k <= for_end) do 
    {
      undumpint ( internal [k ]) ;
      {
	undumpint ( x ) ;
	if ( ( x < 0 ) || ( x > strptr ) ) 
	goto lab6666 ;
	else intname [k ]= x ;
      } 
    } 
  while ( k++ < for_end ) ;} 
  {
    undumpint ( x ) ;
    if ( ( x < 0 ) || ( x > 9757 ) ) 
    goto lab6666 ;
    else startsym = x ;
  } 
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
    else baseident = x ;
  } 
  {
    undumpint ( x ) ;
    if ( ( x < 1 ) || ( x > 9769 ) ) 
    goto lab6666 ;
    else bgloc = x ;
  } 
  {
    undumpint ( x ) ;
    if ( ( x < 1 ) || ( x > 9769 ) ) 
    goto lab6666 ;
    else egloc = x ;
  } 
  undumpint ( serialno ) ;
  undumpint ( x ) ;
  if ( x != 69069L ) 
  goto lab6666 ;
  Result = true ;
  goto lab10 ;
  lab6666: ;
  fprintf ( stdout , "%s\n",  "(Fatal base file error; I'm stymied)" ) ;
  Result = false ;
  lab10: ;
  return Result ;
} 
void 
finalcleanup ( void ) 
{
  /* 10 */ smallnumber c  ;
  c = curmod ;
  if ( jobname == 0 ) 
  openlogfile () ;
  while ( inputptr > 0 ) if ( ( curinput .indexfield > 15 ) ) 
  endtokenlist () ;
  else endfilereading () ;
  while ( loopptr != 0 ) stopiteration () ;
  while ( openparens > 0 ) {
      
    print ( 1078 ) ;
    decr ( openparens ) ;
  } 
  while ( condptr != 0 ) {
      
    printnl ( 1079 ) ;
    printcmdmod ( 2 , curif ) ;
    if ( ifline != 0 ) 
    {
      print ( 1080 ) ;
      printint ( ifline ) ;
    } 
    print ( 1081 ) ;
    ifline = mem [condptr + 1 ].cint ;
    curif = mem [condptr ].hhfield .b1 ;
    loopptr = condptr ;
    condptr = mem [condptr ].hhfield .v.RH ;
    freenode ( loopptr , 2 ) ;
  } 
  if ( history != 0 ) {
      
    if ( ( ( history == 1 ) || ( interaction < 3 ) ) ) {
	
      if ( selector == 3 ) 
      {
	selector = 1 ;
	printnl ( 1082 ) ;
	selector = 3 ;
      } 
    } 
  } 
  if ( c == 1 ) 
  {
	;
#ifdef INIMF
    if ( iniversion ) 
    {
      storebasefile () ;
      goto lab10 ;
    } 
#endif /* INIMF */
    printnl ( 1083 ) ;
    goto lab10 ;
  } 
  lab10: ;
} 
#ifdef INIMF
void 
initprim ( void ) 
{
  primitive ( 409 , 41 , 1 ) ;
  primitive ( 410 , 41 , 2 ) ;
  primitive ( 411 , 41 , 3 ) ;
  primitive ( 412 , 41 , 4 ) ;
  primitive ( 413 , 41 , 5 ) ;
  primitive ( 414 , 41 , 6 ) ;
  primitive ( 415 , 41 , 7 ) ;
  primitive ( 416 , 41 , 8 ) ;
  primitive ( 417 , 41 , 9 ) ;
  primitive ( 418 , 41 , 10 ) ;
  primitive ( 419 , 41 , 11 ) ;
  primitive ( 420 , 41 , 12 ) ;
  primitive ( 421 , 41 , 13 ) ;
  primitive ( 422 , 41 , 14 ) ;
  primitive ( 423 , 41 , 15 ) ;
  primitive ( 424 , 41 , 16 ) ;
  primitive ( 425 , 41 , 17 ) ;
  primitive ( 426 , 41 , 18 ) ;
  primitive ( 427 , 41 , 19 ) ;
  primitive ( 428 , 41 , 20 ) ;
  primitive ( 429 , 41 , 21 ) ;
  primitive ( 430 , 41 , 22 ) ;
  primitive ( 431 , 41 , 23 ) ;
  primitive ( 432 , 41 , 24 ) ;
  primitive ( 433 , 41 , 25 ) ;
  primitive ( 434 , 41 , 26 ) ;
  primitive ( 435 , 41 , 27 ) ;
  primitive ( 436 , 41 , 28 ) ;
  primitive ( 437 , 41 , 29 ) ;
  primitive ( 438 , 41 , 30 ) ;
  primitive ( 439 , 41 , 31 ) ;
  primitive ( 440 , 41 , 32 ) ;
  primitive ( 441 , 41 , 33 ) ;
  primitive ( 442 , 41 , 34 ) ;
  primitive ( 443 , 41 , 35 ) ;
  primitive ( 444 , 41 , 36 ) ;
  primitive ( 445 , 41 , 37 ) ;
  primitive ( 446 , 41 , 38 ) ;
  primitive ( 447 , 41 , 39 ) ;
  primitive ( 448 , 41 , 40 ) ;
  primitive ( 449 , 41 , 41 ) ;
  primitive ( 408 , 48 , 0 ) ;
  primitive ( 91 , 64 , 0 ) ;
  eqtb [9760 ]= eqtb [cursym ];
  primitive ( 93 , 65 , 0 ) ;
  primitive ( 125 , 66 , 0 ) ;
  primitive ( 123 , 47 , 0 ) ;
  primitive ( 58 , 82 , 0 ) ;
  eqtb [9762 ]= eqtb [cursym ];
  primitive ( 459 , 81 , 0 ) ;
  primitive ( 460 , 80 , 0 ) ;
  primitive ( 461 , 78 , 0 ) ;
  primitive ( 44 , 83 , 0 ) ;
  primitive ( 59 , 84 , 0 ) ;
  eqtb [9763 ]= eqtb [cursym ];
  primitive ( 92 , 7 , 0 ) ;
  primitive ( 462 , 19 , 0 ) ;
  primitive ( 463 , 73 , 0 ) ;
  primitive ( 464 , 60 , 0 ) ;
  primitive ( 465 , 33 , 0 ) ;
  bgloc = cursym ;
  primitive ( 466 , 58 , 0 ) ;
  primitive ( 467 , 20 , 0 ) ;
  primitive ( 468 , 61 , 0 ) ;
  primitive ( 469 , 28 , 0 ) ;
  primitive ( 470 , 12 , 0 ) ;
  primitive ( 453 , 85 , 0 ) ;
  eqtb [9767 ]= eqtb [cursym ];
  egloc = cursym ;
  primitive ( 471 , 27 , 0 ) ;
  primitive ( 472 , 6 , 0 ) ;
  primitive ( 473 , 10 , 0 ) ;
  primitive ( 474 , 71 , 0 ) ;
  primitive ( 475 , 74 , 0 ) ;
  primitive ( 476 , 14 , 0 ) ;
  primitive ( 477 , 15 , 0 ) ;
  primitive ( 478 , 16 , 0 ) ;
  primitive ( 479 , 70 , 0 ) ;
  primitive ( 480 , 29 , 0 ) ;
  primitive ( 481 , 25 , 0 ) ;
  primitive ( 482 , 9 , 0 ) ;
  primitive ( 483 , 13 , 0 ) ;
  primitive ( 484 , 8 , 0 ) ;
  primitive ( 485 , 18 , 0 ) ;
  primitive ( 486 , 79 , 0 ) ;
  primitive ( 487 , 75 , 0 ) ;
  primitive ( 488 , 36 , 0 ) ;
  primitive ( 489 , 59 , 0 ) ;
  primitive ( 490 , 72 , 0 ) ;
  primitive ( 491 , 76 , 0 ) ;
  primitive ( 656 , 17 , 1 ) ;
  primitive ( 657 , 17 , 2 ) ;
  primitive ( 658 , 17 , 54 ) ;
  primitive ( 659 , 17 , 45 ) ;
  primitive ( 660 , 17 , 50 ) ;
  primitive ( 454 , 17 , 0 ) ;
  eqtb [9765 ]= eqtb [cursym ];
  primitive ( 661 , 4 , 9770 ) ;
  primitive ( 662 , 4 , 9920 ) ;
  primitive ( 663 , 4 , 1 ) ;
  primitive ( 455 , 4 , 0 ) ;
  eqtb [9764 ]= eqtb [cursym ];
  primitive ( 664 , 62 , 0 ) ;
  primitive ( 665 , 62 , 1 ) ;
  primitive ( 64 , 62 , 2 ) ;
  primitive ( 666 , 62 , 3 ) ;
  primitive ( 677 , 57 , 9770 ) ;
  primitive ( 678 , 57 , 9920 ) ;
  primitive ( 679 , 57 , 10070 ) ;
  primitive ( 680 , 57 , 1 ) ;
  primitive ( 681 , 57 , 2 ) ;
  primitive ( 682 , 57 , 3 ) ;
  primitive ( 692 , 3 , 0 ) ;
  primitive ( 618 , 3 , 1 ) ;
  primitive ( 719 , 1 , 1 ) ;
  primitive ( 452 , 2 , 2 ) ;
  eqtb [9766 ]= eqtb [cursym ];
  primitive ( 720 , 2 , 3 ) ;
  primitive ( 721 , 2 , 4 ) ;
  primitive ( 347 , 34 , 30 ) ;
  primitive ( 348 , 34 , 31 ) ;
  primitive ( 349 , 34 , 32 ) ;
  primitive ( 350 , 34 , 33 ) ;
  primitive ( 351 , 34 , 34 ) ;
  primitive ( 352 , 34 , 35 ) ;
  primitive ( 353 , 34 , 36 ) ;
  primitive ( 354 , 34 , 37 ) ;
  primitive ( 355 , 35 , 38 ) ;
  primitive ( 356 , 35 , 39 ) ;
  primitive ( 357 , 35 , 40 ) ;
  primitive ( 358 , 35 , 41 ) ;
  primitive ( 359 , 35 , 42 ) ;
  primitive ( 360 , 35 , 43 ) ;
  primitive ( 361 , 35 , 44 ) ;
  primitive ( 362 , 35 , 45 ) ;
  primitive ( 363 , 35 , 46 ) ;
  primitive ( 364 , 35 , 47 ) ;
  primitive ( 365 , 35 , 48 ) ;
  primitive ( 366 , 35 , 49 ) ;
  primitive ( 367 , 35 , 50 ) ;
  primitive ( 368 , 35 , 51 ) ;
  primitive ( 369 , 35 , 52 ) ;
  primitive ( 370 , 35 , 53 ) ;
  primitive ( 371 , 35 , 54 ) ;
  primitive ( 372 , 35 , 55 ) ;
  primitive ( 373 , 35 , 56 ) ;
  primitive ( 374 , 35 , 57 ) ;
  primitive ( 375 , 35 , 58 ) ;
  primitive ( 376 , 35 , 59 ) ;
  primitive ( 377 , 35 , 60 ) ;
  primitive ( 378 , 35 , 61 ) ;
  primitive ( 379 , 35 , 62 ) ;
  primitive ( 380 , 35 , 63 ) ;
  primitive ( 381 , 35 , 64 ) ;
  primitive ( 382 , 35 , 65 ) ;
  primitive ( 383 , 35 , 66 ) ;
  primitive ( 384 , 35 , 67 ) ;
  primitive ( 385 , 37 , 68 ) ;
  primitive ( 43 , 44 , 69 ) ;
  primitive ( 45 , 44 , 70 ) ;
  primitive ( 42 , 56 , 71 ) ;
  primitive ( 47 , 55 , 72 ) ;
  eqtb [9761 ]= eqtb [cursym ];
  primitive ( 386 , 46 , 73 ) ;
  primitive ( 310 , 46 , 74 ) ;
  primitive ( 388 , 53 , 76 ) ;
  primitive ( 387 , 46 , 75 ) ;
  primitive ( 60 , 51 , 77 ) ;
  primitive ( 389 , 51 , 78 ) ;
  primitive ( 62 , 51 , 79 ) ;
  primitive ( 390 , 51 , 80 ) ;
  primitive ( 61 , 52 , 81 ) ;
  primitive ( 391 , 51 , 82 ) ;
  primitive ( 401 , 38 , 94 ) ;
  primitive ( 402 , 38 , 95 ) ;
  primitive ( 403 , 38 , 96 ) ;
  primitive ( 404 , 38 , 97 ) ;
  primitive ( 405 , 38 , 98 ) ;
  primitive ( 406 , 38 , 99 ) ;
  primitive ( 407 , 38 , 100 ) ;
  primitive ( 38 , 49 , 83 ) ;
  primitive ( 392 , 56 , 84 ) ;
  primitive ( 393 , 56 , 85 ) ;
  primitive ( 394 , 56 , 86 ) ;
  primitive ( 395 , 56 , 87 ) ;
  primitive ( 396 , 56 , 88 ) ;
  primitive ( 397 , 56 , 89 ) ;
  primitive ( 398 , 56 , 90 ) ;
  primitive ( 399 , 56 , 91 ) ;
  primitive ( 400 , 46 , 92 ) ;
  primitive ( 340 , 31 , 15 ) ;
  primitive ( 326 , 31 , 4 ) ;
  primitive ( 324 , 31 , 2 ) ;
  primitive ( 331 , 31 , 9 ) ;
  primitive ( 328 , 31 , 6 ) ;
  primitive ( 333 , 31 , 11 ) ;
  primitive ( 335 , 31 , 13 ) ;
  primitive ( 336 , 31 , 14 ) ;
  primitive ( 913 , 86 , 0 ) ;
  primitive ( 914 , 86 , 1 ) ;
  primitive ( 273 , 24 , 0 ) ;
  primitive ( 274 , 24 , 1 ) ;
  primitive ( 275 , 24 , 2 ) ;
  primitive ( 920 , 24 , 3 ) ;
  primitive ( 921 , 22 , 0 ) ;
  primitive ( 922 , 22 , 1 ) ;
  primitive ( 936 , 23 , 0 ) ;
  primitive ( 937 , 23 , 1 ) ;
  primitive ( 938 , 23 , 2 ) ;
  primitive ( 939 , 23 , 3 ) ;
  primitive ( 940 , 23 , 4 ) ;
  primitive ( 957 , 69 , 1 ) ;
  primitive ( 958 , 69 , 0 ) ;
  primitive ( 959 , 69 , 2 ) ;
  primitive ( 960 , 67 , 6 ) ;
  primitive ( 961 , 67 , 16 ) ;
  primitive ( 962 , 68 , 0 ) ;
  primitive ( 963 , 68 , 1 ) ;
  primitive ( 993 , 26 , 0 ) ;
  primitive ( 994 , 26 , 1 ) ;
  primitive ( 995 , 26 , 2 ) ;
  primitive ( 1005 , 21 , 0 ) ;
  primitive ( 1006 , 21 , 1 ) ;
  primitive ( 1007 , 21 , 2 ) ;
  primitive ( 1008 , 21 , 3 ) ;
  primitive ( 1009 , 21 , 4 ) ;
  primitive ( 1027 , 77 , 0 ) ;
  primitive ( 1028 , 77 , 1 ) ;
  primitive ( 1029 , 77 , 5 ) ;
  primitive ( 1030 , 77 , 2 ) ;
  primitive ( 1031 , 77 , 6 ) ;
  primitive ( 1032 , 77 , 3 ) ;
  primitive ( 1033 , 77 , 7 ) ;
  primitive ( 1034 , 77 , 11 ) ;
  primitive ( 1035 , 77 , 128 ) ;
  primitive ( 1060 , 30 , 4 ) ;
  primitive ( 1061 , 30 , 16 ) ;
} 
void 
inittab ( void ) 
{
  integer k  ;
  rover = 23 ;
  mem [rover ].hhfield .v.RH = 268435455L ;
  mem [rover ].hhfield .lhfield = 1000 ;
  mem [rover + 1 ].hhfield .lhfield = rover ;
  mem [rover + 1 ].hhfield .v.RH = rover ;
  lomemmax = rover + 1000 ;
  mem [lomemmax ].hhfield .v.RH = 0 ;
  mem [lomemmax ].hhfield .lhfield = 0 ;
  {register integer for_end; k = memtop - 2 ;for_end = memtop ; if ( k <= 
  for_end) do 
    mem [k ]= mem [lomemmax ];
  while ( k++ < for_end ) ;} 
  avail = 0 ;
  memend = memtop ;
  himemmin = memtop - 2 ;
  varused = 23 ;
  dynused = memtop + 1 - himemmin ;
  intname [1 ]= 409 ;
  intname [2 ]= 410 ;
  intname [3 ]= 411 ;
  intname [4 ]= 412 ;
  intname [5 ]= 413 ;
  intname [6 ]= 414 ;
  intname [7 ]= 415 ;
  intname [8 ]= 416 ;
  intname [9 ]= 417 ;
  intname [10 ]= 418 ;
  intname [11 ]= 419 ;
  intname [12 ]= 420 ;
  intname [13 ]= 421 ;
  intname [14 ]= 422 ;
  intname [15 ]= 423 ;
  intname [16 ]= 424 ;
  intname [17 ]= 425 ;
  intname [18 ]= 426 ;
  intname [19 ]= 427 ;
  intname [20 ]= 428 ;
  intname [21 ]= 429 ;
  intname [22 ]= 430 ;
  intname [23 ]= 431 ;
  intname [24 ]= 432 ;
  intname [25 ]= 433 ;
  intname [26 ]= 434 ;
  intname [27 ]= 435 ;
  intname [28 ]= 436 ;
  intname [29 ]= 437 ;
  intname [30 ]= 438 ;
  intname [31 ]= 439 ;
  intname [32 ]= 440 ;
  intname [33 ]= 441 ;
  intname [34 ]= 442 ;
  intname [35 ]= 443 ;
  intname [36 ]= 444 ;
  intname [37 ]= 445 ;
  intname [38 ]= 446 ;
  intname [39 ]= 447 ;
  intname [40 ]= 448 ;
  intname [41 ]= 449 ;
  hashused = 9757 ;
  stcount = 0 ;
  hash [9768 ].v.RH = 451 ;
  hash [9766 ].v.RH = 452 ;
  hash [9767 ].v.RH = 453 ;
  hash [9765 ].v.RH = 454 ;
  hash [9764 ].v.RH = 455 ;
  hash [9763 ].v.RH = 59 ;
  hash [9762 ].v.RH = 58 ;
  hash [9761 ].v.RH = 47 ;
  hash [9760 ].v.RH = 91 ;
  hash [9759 ].v.RH = 41 ;
  hash [9757 ].v.RH = 456 ;
  eqtb [9759 ].lhfield = 63 ;
  mem [19 ].hhfield .lhfield = 9770 ;
  mem [19 ].hhfield .v.RH = 0 ;
  mem [memtop ].hhfield .lhfield = 268435455L ;
  mem [3 ].hhfield .lhfield = 0 ;
  mem [3 ].hhfield .v.RH = 0 ;
  mem [4 ].hhfield .lhfield = 1 ;
  mem [4 ].hhfield .v.RH = 0 ;
  {register integer for_end; k = 5 ;for_end = 11 ; if ( k <= for_end) do 
    mem [k ]= mem [4 ];
  while ( k++ < for_end ) ;} 
  mem [12 ].cint = 0 ;
  mem [0 ].hhfield .v.RH = 0 ;
  mem [0 ].hhfield .lhfield = 0 ;
  mem [1 ].cint = 0 ;
  mem [2 ].cint = 0 ;
  serialno = 0 ;
  mem [13 ].hhfield .v.RH = 13 ;
  mem [14 ].hhfield .lhfield = 13 ;
  mem [13 ].hhfield .lhfield = 0 ;
  mem [14 ].hhfield .v.RH = 0 ;
  mem [21 ].hhfield .b1 = 0 ;
  mem [21 ].hhfield .v.RH = 9768 ;
  eqtb [9768 ].v.RH = 21 ;
  eqtb [9768 ].lhfield = 42 ;
  eqtb [9758 ].lhfield = 92 ;
  hash [9758 ].v.RH = 736 ;
  mem [17 ].hhfield .b1 = 11 ;
  mem [20 ].cint = 1073741824L ;
  mem [16 ].cint = 0 ;
  mem [15 ].hhfield .lhfield = 0 ;
  if ( iniversion ) 
  baseident = 1070 ;
} 
#endif /* INIMF */
void mainbody( void ) {
    
  bounddefault = 250000L ;
  boundname = "main_memory" ;
  setupboundvariable ( addressof ( mainmemory ) , boundname , bounddefault ) ;
  bounddefault = 3000 ;
  boundname = "buf_size" ;
  setupboundvariable ( addressof ( bufsize ) , boundname , bounddefault ) ;
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
  bounddefault = 768 ;
  boundname = "screen_width" ;
  setupboundvariable ( addressof ( screenwidth ) , boundname , bounddefault ) 
  ;
  bounddefault = 1024 ;
  boundname = "screen_depth" ;
  setupboundvariable ( addressof ( screendepth ) , boundname , bounddefault ) 
  ;
  bounddefault = 16384 ;
  boundname = "gf_buf_size" ;
  setupboundvariable ( addressof ( gfbufsize ) , boundname , bounddefault ) ;
  if ( errorline > 255 ) 
  errorline = 255 ;
  if ( screenwidth > 32767 ) 
  screenwidth = 32767 ;
  if ( screendepth > 32767 ) 
  screendepth = 32767 ;
  {
    if ( mainmemory < infmainmemory ) 
    mainmemory = infmainmemory ;
    else if ( mainmemory > supmainmemory ) 
    mainmemory = supmainmemory ;
  } 
  memtop = 0 + mainmemory - 1 ;
  memmax = memtop ;
  {
    if ( bufsize < infbufsize ) 
    bufsize = infbufsize ;
    else if ( bufsize > supbufsize ) 
    bufsize = supbufsize ;
  } 
  buffer = xmallocarray ( ASCIIcode , bufsize ) ;
  rowtransition = xmallocarray ( screencol , screenwidth ) ;
  gfbuf = xmallocarray ( eightbits , gfbufsize ) ;
  sourcefilenamestack = xmallocarray ( strnumber , 15 ) ;
  fullsourcefilenamestack = xmallocarray ( strnumber , 15 ) ;
#ifdef INIMF
  if ( iniversion ) 
  {
    mem = xmallocarray ( memoryword , memtop + 1 ) ;
  } 
#endif /* INIMF */
  mfluabeginprogram () ;
  history = 3 ;
  if ( readyalready == 314159L ) 
  goto lab1 ;
  bad = 0 ;
  if ( ( halferrorline < 30 ) || ( halferrorline > errorline - 15 ) ) 
  bad = 1 ;
  if ( maxprintline < 60 ) 
  bad = 2 ;
  if ( gfbufsize % 8 != 0 ) 
  bad = 3 ;
  if ( 1100 > memtop ) 
  bad = 4 ;
  if ( 7919 > 9500 ) 
  bad = 5 ;
  if ( headersize % 4 != 0 ) 
  bad = 6 ;
  if ( ( ligtablesize < 255 ) || ( ligtablesize > 32510 ) ) 
  bad = 7 ;
#ifdef INIMF
  if ( memmax != memtop ) 
  bad = 10 ;
#endif /* INIMF */
  if ( memmax < memtop ) 
  bad = 10 ;
  if ( ( 0 > 0 ) || ( 255 < 127 ) ) 
  bad = 11 ;
  if ( ( 0 > 0 ) || ( 268435455L < 32767 ) ) 
  bad = 12 ;
  if ( ( 0 < 0 ) || ( 255 > 268435455L ) ) 
  bad = 13 ;
  if ( ( 0 < 0 ) || ( memmax >= 268435455L ) ) 
  bad = 14 ;
  if ( maxstrings > 268435455L ) 
  bad = 15 ;
  if ( bufsize > 268435455L ) 
  bad = 16 ;
  if ( ( 255 < 255 ) || ( 268435455L < 65535L ) ) 
  bad = 17 ;
  if ( 9769 + maxinternal > 268435455L ) 
  bad = 21 ;
  if ( 10220 > 268435455L ) 
  bad = 22 ;
  if ( 15 * 11 > bistacksize ) 
  bad = 31 ;
  if ( 20 + 17 * 45 > bistacksize ) 
  bad = 32 ;
  if ( basedefaultlength > maxint ) 
  bad = 41 ;
  if ( bad > 0 ) 
  {
    fprintf ( stdout , "%s%s%ld\n",  "Ouch---my internal constants have been clobbered!" ,     "---case " , (long)bad ) ;
    goto lab9999 ;
  } 
  initialize () ;
#ifdef INIMF
  if ( iniversion ) 
  {
    if ( ! getstringsstarted () ) 
    goto lab9999 ;
    inittab () ;
    initprim () ;
    initstrptr = strptr ;
    initpoolptr = poolptr ;
    maxstrptr = strptr ;
    maxpoolptr = poolptr ;
    fixdateandtime () ;
  } 
#endif /* INIMF */
  readyalready = 314159L ;
  mfluaPREstartofMF () ;
  lab1: selector = 1 ;
  tally = 0 ;
  termoffset = 0 ;
  fileoffset = 0 ;
  fprintf ( stdout , "%s%s",  "This is MFLuaJIT, Version 2.7182818" , "-0.5" ) ;
  Fputs ( stdout ,  versionstring ) ;
  if ( baseident == 0 ) 
  fprintf ( stdout , "%s%s%c\n",  " (preloaded base=" , dumpname , ')' ) ;
  else {
      
    slowprint ( baseident ) ;
    println () ;
  } 
  if ( translatefilename ) 
  {
    putc ( '(' ,  stdout );
    fputs ( translatefilename , stdout ) ;
    { putc ( ')' ,  stdout );  putc ( '\n',  stdout ); }
  } 
  fflush ( stdout ) ;
  jobname = 0 ;
  logopened = false ;
  outputfilename = 0 ;
  {
    {
      inputptr = 0 ;
      maxinstack = 0 ;
      inopen = 0 ;
      openparens = 0 ;
      maxbufstack = 0 ;
      paramptr = 0 ;
      maxparamstack = 0 ;
      first = 1 ;
      curinput .startfield = 1 ;
      curinput .indexfield = 0 ;
      line = 0 ;
      curinput .namefield = 0 ;
      forceeof = false ;
      if ( ! initterminal () ) 
      goto lab9999 ;
      curinput .limitfield = last ;
      first = last + 1 ;
    } 
    scannerstatus = 0 ;
    if ( ( baseident == 0 ) || ( buffer [curinput .locfield ]== 38 ) ) 
    {
      if ( baseident != 0 ) 
      initialize () ;
      if ( ! openbasefile () ) 
      goto lab9999 ;
      if ( ! loadbasefile () ) 
      {
	wclose ( basefile ) ;
	goto lab9999 ;
      } 
      wclose ( basefile ) ;
      while ( ( curinput .locfield < curinput .limitfield ) && ( buffer [
      curinput .locfield ]== 32 ) ) incr ( curinput .locfield ) ;
    } 
    buffer [curinput .limitfield ]= 37 ;
    fixdateandtime () ;
    initrandoms ( ( internal [17 ]/ 65536L ) + internal [16 ]) ;
    if ( interaction == 0 ) 
    selector = 0 ;
    else selector = 1 ;
    if ( curinput .locfield < curinput .limitfield ) {
	
      if ( buffer [curinput .locfield ]!= 92 ) 
      startinput () ;
    } 
  } 
  history = 0 ;
  mfluainitialize () ;
  if ( startsym > 0 ) 
  {
    cursym = startsym ;
    backinput () ;
  } 
  mfluaPREmaincontrol () ;
  maincontrol () ;
  mfluaPOSTmaincontrol () ;
  finalcleanup () ;
  mfluaPOSTfinalcleanup () ;
  closefilesandterminate () ;
  lab9999: {
      
    fflush ( stdout ) ;
    readyalready = 0 ;
    if ( ( history != 0 ) && ( history != 1 ) ) 
    uexit ( 1 ) ;
    else uexit ( 0 ) ;
  } 
} 
