#define EXTERN extern
#include "euptexd.h"

void 
println ( void ) 
{
  println_regmem 
  integer ii  ;
  switch ( selector ) 
  {case 19 : 
    {
      if ( nrestmultichr ( kcodepos ) > 0 ) 
      {register integer for_end; ii = 0 ;for_end = nrestmultichr ( kcodepos 
      ) - 1 ; if ( ii <= for_end) do 
	{
	  putc ( ' ' ,  stdout );
	  putc ( ' ' ,  logfile );
	} 
      while ( ii++ < for_end ) ;} 
      putc ('\n',  stdout );
      putc ('\n',  logfile );
      termoffset = 0 ;
      fileoffset = 0 ;
    } 
    break ;
  case 18 : 
    {
      if ( nrestmultichr ( kcodepos ) > 0 ) 
      {register integer for_end; ii = 0 ;for_end = nrestmultichr ( kcodepos 
      ) - 1 ; if ( ii <= for_end) do 
	putc ( ' ' ,  logfile );
      while ( ii++ < for_end ) ;} 
      putc ('\n',  logfile );
      fileoffset = 0 ;
    } 
    break ;
  case 17 : 
    {
      if ( nrestmultichr ( kcodepos ) > 0 ) 
      {register integer for_end; ii = 0 ;for_end = nrestmultichr ( kcodepos 
      ) - 1 ; if ( ii <= for_end) do 
	putc ( ' ' ,  stdout );
      while ( ii++ < for_end ) ;} 
      putc ('\n',  stdout );
      termoffset = 0 ;
    } 
    break ;
  case 16 : 
  case 20 : 
  case 21 : 
    ;
    break ;
    default: 
    putc ('\n',  writefile [selector ]);
    break ;
  } 
  kcodepos = 0 ;
} 
void 
zprintchar ( ASCIIcode s ) 
{
  /* 10 */ printchar_regmem 
  if ( s == eqtb [29238 ].cint ) {
      
    if ( selector < 20 ) 
    {
      println () ;
      return ;
    } 
  } 
  if ( ( kcodepos == 1 ) || ( ( kcodepos >= 9 ) && ( kcodepos <= 10 ) ) || ( ( 
  kcodepos >= 17 ) && ( kcodepos <= 19 ) ) ) 
  incr ( kcodepos ) ;
  else if ( iskanji1 ( xchr [s ]) ) 
  {
    if ( ( ismultichr ( 4 , 1 , xchr [s ]) ) ) 
    kcodepos = 17 ;
    else if ( ( ismultichr ( 3 , 1 , xchr [s ]) ) ) 
    kcodepos = 9 ;
    else kcodepos = 1 ;
    if ( ( selector == 19 ) || ( selector == 18 ) ) {
	
      if ( fileoffset >= maxprintline - nrestmultichr ( kcodepos ) ) 
      {
	putc ('\n',  logfile );
	fileoffset = 0 ;
      } 
    } 
    if ( ( selector == 19 ) || ( selector == 17 ) ) {
	
      if ( termoffset >= maxprintline - nrestmultichr ( kcodepos ) ) 
      {
	putc ('\n',  stdout );
	termoffset = 0 ;
      } 
    } 
  } 
  else kcodepos = 0 ;
  switch ( selector ) 
  {case 19 : 
    {
      putc ( Xchr (s ),  stdout );
      incr ( termoffset ) ;
      if ( termoffset == maxprintline ) 
      {
	putc ('\n',  stdout );
	termoffset = 0 ;
      } 
      putc ( Xchr (s ),  logfile );
      incr ( fileoffset ) ;
      if ( fileoffset == maxprintline ) 
      {
	putc ('\n',  logfile );
	fileoffset = 0 ;
      } 
    } 
    break ;
  case 18 : 
    {
      putc ( Xchr (s ),  logfile );
      incr ( fileoffset ) ;
      if ( fileoffset == maxprintline ) 
      println () ;
    } 
    break ;
  case 17 : 
    {
      putc ( Xchr (s ),  stdout );
      incr ( termoffset ) ;
      if ( termoffset == maxprintline ) 
      println () ;
    } 
    break ;
  case 16 : 
    ;
    break ;
  case 20 : 
    if ( tally < trickcount ) 
    {
      trickbuf [tally % errorline ]= s ;
      trickbuf2 [tally % errorline ]= kcodepos ;
    } 
    break ;
  case 21 : 
    {
      if ( poolptr < poolsize ) 
      {
	strpool [poolptr ]= s ;
	incr ( poolptr ) ;
      } 
    } 
    break ;
    default: 
    putc ( Xchr (s ),  writefile [selector ]);
    break ;
  } 
  incr ( tally ) ;
} 
void 
zprint ( integer s ) 
{
  /* 10 */ print_regmem 
  poolpointer j  ;
  integer nl  ;
  if ( s >= strptr ) 
  s = 261 ;
  else if ( s < 256 ) {
      
    if ( s < 0 ) 
    s = 261 ;
    else {
	
      if ( selector > 20 ) 
      {
	printchar ( s ) ;
	return ;
      } 
      if ( ( s == eqtb [29238 ].cint ) ) {
	  
	if ( selector < 20 ) 
	{
	  println () ;
	  return ;
	} 
      } 
      nl = eqtb [29238 ].cint ;
      eqtb [29238 ].cint = -1 ;
      j = strstart [s ];
      while ( j < strstart [s + 1 ]) {
	  
	printchar ( strpool [j ]) ;
	incr ( j ) ;
      } 
      eqtb [29238 ].cint = nl ;
      return ;
    } 
  } 
  j = strstart [s ];
  while ( j < strstart [s + 1 ]) {
      
    printchar ( strpool [j ]) ;
    incr ( j ) ;
  } 
} 
void 
zslowprint ( integer s ) 
{
  slowprint_regmem 
  poolpointer j  ;
  if ( ( s >= strptr ) || ( s < 256 ) ) 
  print ( s ) ;
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
  printnl_regmem 
  if ( ( ( termoffset > 0 ) && ( odd ( selector ) ) ) || ( ( fileoffset > 0 ) 
  && ( selector >= 18 ) ) ) 
  println () ;
  print ( s ) ;
} 
void 
zprintesc ( strnumber s ) 
{
  printesc_regmem 
  integer c  ;
  c = eqtb [29234 ].cint ;
  if ( c >= 0 ) {
      
    if ( c < 256 ) 
    print ( c ) ;
  } 
  slowprint ( s ) ;
} 
void 
zprintthedigs ( eightbits k ) 
{
  printthedigs_regmem 
  while ( k > 0 ) {
      
    decr ( k ) ;
    if ( dig [k ]< 10 ) 
    printchar ( 48 + dig [k ]) ;
    else printchar ( 55 + dig [k ]) ;
  } 
} 
void 
zprintint ( integer n ) 
{
  printint_regmem 
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
zprintcs ( integer p ) 
{
  printcs_regmem 
  if ( p < 514 ) {
      
    if ( p >= 257 ) {
	
      if ( p == 513 ) 
      {
	printesc ( 546 ) ;
	printesc ( 547 ) ;
	printchar ( 32 ) ;
      } 
      else {
	  
	printesc ( p - 257 ) ;
	if ( eqtb [26362 + p - 257 ].hh .v.RH == 11 ) 
	printchar ( 32 ) ;
      } 
    } 
    else if ( p < 1 ) 
    printesc ( 548 ) ;
    else print ( p - 1 ) ;
  } 
  else if ( ( ( p >= 24527 ) && ( p <= 30310 ) ) || ( p > eqtbtop ) ) 
  printesc ( 548 ) ;
  else if ( ( hash [p ].v.RH >= strptr ) ) 
  printesc ( 549 ) ;
  else {
      
    printesc ( hash [p ].v.RH ) ;
    printchar ( 32 ) ;
  } 
} 
void 
zsprintcs ( halfword p ) 
{
  sprintcs_regmem 
  if ( p < 514 ) {
      
    if ( p < 257 ) 
    print ( p - 1 ) ;
    else if ( p < 513 ) 
    printesc ( p - 257 ) ;
    else {
	
      printesc ( 546 ) ;
      printesc ( 547 ) ;
    } 
  } 
  else printesc ( hash [p ].v.RH ) ;
} 
void 
zprintfilename ( integer n , integer a , integer e ) 
{
  printfilename_regmem 
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
  printchar ( 34 ) ;
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
  printchar ( 34 ) ;
} 
void 
zprintsize ( integer s ) 
{
  printsize_regmem 
  if ( s == 0 ) 
  printesc ( 434 ) ;
  else if ( s == 256 ) 
  printesc ( 435 ) ;
  else printesc ( 436 ) ;
} 
void 
zprintwritewhatsit ( strnumber s , halfword p ) 
{
  printwritewhatsit_regmem 
  printesc ( s ) ;
  if ( mem [p + 1 ].hh .v.LH < 16 ) 
  printint ( mem [p + 1 ].hh .v.LH ) ;
  else if ( mem [p + 1 ].hh .v.LH == 16 ) 
  printchar ( 42 ) ;
  else printchar ( 45 ) ;
} 
void 
zprintsanum ( halfword q ) 
{
  printsanum_regmem 
  halfword n  ;
  if ( mem [q ].hh.b0 < 32 ) 
  n = mem [q + 1 ].hh .v.RH ;
  else {
      
    n = mem [q ].hh.b0 % 16 ;
    q = mem [q ].hh .v.RH ;
    n = n + 16 * mem [q ].hh.b0 ;
    q = mem [q ].hh .v.RH ;
    n = n + 256 * ( mem [q ].hh.b0 + 16 * mem [mem [q ].hh .v.RH ].hh.b0 
    ) ;
    q = mem [mem [q ].hh .v.RH ].hh .v.RH ;
    n = n + 65536L * mem [q ].hh.b0 ;
  } 
  printint ( n ) ;
} 
void 
zprintcsnames ( integer hstart , integer hfinish ) 
{
  printcsnames_regmem 
  integer c, h  ;
  fprintf ( stderr , "%s%ld%s%ld%c\n",  "fmtdebug:csnames from " , (long)hstart , " to " , (long)hfinish ,   ':' ) ;
  {register integer for_end; h = hstart ;for_end = hfinish ; if ( h <= 
  for_end) do 
    {
      if ( hash [h ].v.RH > 0 ) 
      {
	{register integer for_end; c = strstart [hash [h ].v.RH ];
	for_end = strstart [hash [h ].v.RH + 1 ]- 1 ; if ( c <= for_end) 
	do 
	  {
	    putbyte ( strpool [c ], stderr ) ;
	  } 
	while ( c++ < for_end ) ;} 
	{ putc ( '|' ,  stderr );  putc ( '\n',  stderr ); }
      } 
    } 
  while ( h++ < for_end ) ;} 
} 
void 
printfileline ( void ) 
{
  printfileline_regmem 
  integer level  ;
  level = inopen ;
  while ( ( level > 0 ) && ( fullsourcefilenamestack [level ]== 0 ) ) decr ( 
  level ) ;
  if ( level == 0 ) 
  printnl ( 264 ) ;
  else {
      
    printnl ( 344 ) ;
    print ( fullsourcefilenamestack [level ]) ;
    print ( 58 ) ;
    if ( level == inopen ) 
    printint ( line ) ;
    else printint ( linestack [level + 1 ]) ;
    print ( 622 ) ;
  } 
} 
void 
zprintdir ( eightbits dir ) 
{
  printdir_regmem 
  if ( dir == 4 ) 
  printchar ( 89 ) ;
  else if ( dir == 3 ) 
  printchar ( 84 ) ;
  else if ( dir == 1 ) 
  printchar ( 68 ) ;
} 
void 
zprintdirectionalt ( integer d ) 
{
  printdirectionalt_regmem 
  boolean x  ;
  x = false ;
  switch ( abs ( d ) ) 
  {case 4 : 
    {
      print ( 1606 ) ;
      x = true ;
    } 
    break ;
  case 3 : 
    {
      print ( 1607 ) ;
      x = true ;
    } 
    break ;
  case 1 : 
    {
      print ( 1608 ) ;
      x = true ;
    } 
    break ;
  } 
  if ( x ) 
  {
    if ( d < 0 ) 
    print ( 1609 ) ;
    print ( 1610 ) ;
  } 
} 
void 
zprintdirection ( integer d ) 
{
  printdirection_regmem 
  switch ( abs ( d ) ) 
  {case 4 : 
    print ( 1168 ) ;
    break ;
  case 3 : 
    print ( 1167 ) ;
    break ;
  case 1 : 
    print ( 1169 ) ;
    break ;
  } 
  if ( d < 0 ) 
  print ( 1609 ) ;
  print ( 1610 ) ;
} 
void 
zprintkanji ( KANJIcode s ) 
{
  printkanji_regmem 
  if ( isprintutf8 ) 
  s = UCStoUTF8 ( toUCS ( s % 16777216L ) ) ;
  else s = toBUFF ( s % 16777216L ) ;
  if ( BYTE1 ( s ) != 0 ) 
  printchar ( BYTE1 ( s ) ) ;
  if ( BYTE2 ( s ) != 0 ) 
  printchar ( BYTE2 ( s ) ) ;
  if ( BYTE3 ( s ) != 0 ) 
  printchar ( BYTE3 ( s ) ) ;
  printchar ( BYTE4 ( s ) ) ;
} 
integer 
zcheckkcatcode ( integer ct ) 
{
  register integer Result; checkkcatcode_regmem 
  if ( ( ( ct >= 16 ) && ( eqtb [26361 ].hh .v.RH == 0 ) ) || ( eqtb [26361 
  ].hh .v.RH == 2 ) ) 
  Result = 1 ;
  else Result = 0 ;
  return Result ;
} 
integer 
zcheckecharrange ( integer c ) 
{
  register integer Result; checkecharrange_regmem 
  if ( ( c >= 0 ) && ( c < 256 ) ) 
  Result = 1 ;
  else Result = 0 ;
  return Result ;
} 
#ifdef TEXMF_DEBUG
#endif /* TEXMF_DEBUG */
void 
jumpout ( void ) 
{
  jumpout_regmem 
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
  /* 22 10 */ error_regmem 
  ASCIIcode c  ;
  integer s1, s2, s3, s4  ;
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
      print ( 266 ) ;
      terminput () ;
    } 
    if ( last == first ) 
    return ;
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
	s1 = curtok ;
	s2 = curcmd ;
	s3 = curchr ;
	s4 = alignstate ;
	alignstate = 1000000L ;
	OKtointerrupt = false ;
	if ( ( last > first + 1 ) && ( buffer [first + 1 ]>= 48 ) && ( 
	buffer [first + 1 ]<= 57 ) ) 
	c = c * 10 + buffer [first + 1 ]- 48 * 11 ;
	else c = c - 48 ;
	while ( c > 0 ) {
	    
	  gettoken () ;
	  decr ( c ) ;
	} 
	curtok = s1 ;
	curcmd = s2 ;
	curchr = s3 ;
	alignstate = s4 ;
	OKtointerrupt = true ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 279 ;
	  helpline [0 ]= 280 ;
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
      if ( baseptr > 0 ) 
      {
	editnamestart = strstart [inputstack [baseptr ].namefield ];
	editnamelength = strstart [inputstack [baseptr ].namefield + 1 ]- 
	strstart [inputstack [baseptr ].namefield ];
	editline = line ;
	jumpout () ;
      } 
      break ;
    case 72 : 
      {
	if ( useerrhelp ) 
	{
	  giveerrhelp () ;
	  useerrhelp = false ;
	} 
	else {
	    
	  if ( helpptr == 0 ) 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 281 ;
	    helpline [0 ]= 282 ;
	  } 
	  do {
	      decr ( helpptr ) ;
	    print ( helpline [helpptr ]) ;
	    println () ;
	  } while ( ! ( helpptr == 0 ) ) ;
	} 
	{
	  helpptr = 4 ;
	  helpline [3 ]= 283 ;
	  helpline [2 ]= 282 ;
	  helpline [1 ]= 284 ;
	  helpline [0 ]= 285 ;
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
	    print ( 278 ) ;
	    terminput () ;
	  } 
	  curinput .locfield = first ;
	} 
	first = last ;
	curinput .limitfield = last - 1 ;
	return ;
      } 
      break ;
    case 81 : 
    case 82 : 
    case 83 : 
      {
	errorcount = 0 ;
	interaction = 0 + c - 81 ;
	print ( 273 ) ;
	switch ( c ) 
	{case 81 : 
	  {
	    printesc ( 274 ) ;
	    decr ( selector ) ;
	  } 
	  break ;
	case 82 : 
	  printesc ( 275 ) ;
	  break ;
	case 83 : 
	  printesc ( 276 ) ;
	  break ;
	} 
	print ( 277 ) ;
	println () ;
	fflush ( stdout ) ;
	return ;
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
      print ( 267 ) ;
      printnl ( 268 ) ;
      printnl ( 269 ) ;
      if ( baseptr > 0 ) 
      print ( 270 ) ;
      if ( deletionsallowed ) 
      printnl ( 271 ) ;
      printnl ( 272 ) ;
    } 
  } 
  incr ( errorcount ) ;
  if ( errorcount == 100 ) 
  {
    printnl ( 265 ) ;
    history = 3 ;
    jumpout () ;
  } 
  if ( interaction > 0 ) 
  decr ( selector ) ;
  if ( useerrhelp ) 
  {
    println () ;
    giveerrhelp () ;
  } 
  else while ( helpptr > 0 ) {
      
    decr ( helpptr ) ;
    printnl ( helpline [helpptr ]) ;
  } 
  println () ;
  if ( interaction > 0 ) 
  incr ( selector ) ;
  println () ;
} 
void 
zfatalerror ( strnumber s ) 
{
  fatalerror_regmem 
  normalizeselector () ;
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 287 ) ;
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
  overflow_regmem 
  normalizeselector () ;
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 288 ) ;
  } 
  print ( s ) ;
  printchar ( 61 ) ;
  printint ( n ) ;
  printchar ( 93 ) ;
  {
    helpptr = 2 ;
    helpline [1 ]= 289 ;
    helpline [0 ]= 290 ;
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
  confusion_regmem 
  normalizeselector () ;
  if ( history < 2 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 291 ) ;
    } 
    print ( s ) ;
    printchar ( 41 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 292 ;
    } 
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 293 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 294 ;
      helpline [0 ]= 295 ;
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
  /* 10 */ register boolean Result; initterminal_regmem 
  topenin () ;
  if ( last > first ) 
  {
    curinput .locfield = first ;
    while ( ( curinput .locfield < last ) && ( buffer [curinput .locfield ]
    == ' ' ) ) incr ( curinput .locfield ) ;
    if ( curinput .locfield < last ) 
    {
      Result = true ;
      return Result ;
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
      return Result ;
    } 
    curinput .locfield = first ;
    while ( ( curinput .locfield < last ) && ( buffer [curinput .locfield ]
    == 32 ) ) incr ( curinput .locfield ) ;
    if ( curinput .locfield < last ) 
    {
      Result = true ;
      return Result ;
    } 
    fprintf ( stdout , "%s\n",  "Please type the name of your input file." ) ;
  } 
  return Result ;
} 
strnumber 
makestring ( void ) 
{
  register strnumber Result; makestring_regmem 
  if ( strptr == maxstrings ) 
  overflow ( 260 , maxstrings - initstrptr ) ;
  incr ( strptr ) ;
  strstart [strptr ]= poolptr ;
  Result = strptr - 1 ;
  return Result ;
} 
boolean 
zstreqbuf ( strnumber s , integer k ) 
{
  /* 45 */ register boolean Result; streqbuf_regmem 
  poolpointer j  ;
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
boolean 
zstreqstr ( strnumber s , strnumber t ) 
{
  /* 45 */ register boolean Result; streqstr_regmem 
  poolpointer j, k  ;
  boolean result  ;
  result = false ;
  if ( ( strstart [s + 1 ]- strstart [s ]) != ( strstart [t + 1 ]- 
  strstart [t ]) ) 
  goto lab45 ;
  j = strstart [s ];
  k = strstart [t ];
  while ( j < strstart [s + 1 ]) {
      
    if ( strpool [j ]!= strpool [k ]) 
    goto lab45 ;
    incr ( j ) ;
    incr ( k ) ;
  } 
  result = true ;
  lab45: Result = result ;
  return Result ;
} 
strnumber 
zsearchstring ( strnumber search ) 
{
  /* 40 */ register strnumber Result; searchstring_regmem 
  strnumber result  ;
  strnumber s  ;
  integer len  ;
  result = 0 ;
  len = ( strstart [search + 1 ]- strstart [search ]) ;
  if ( len == 0 ) 
  {
    result = 344 ;
    goto lab40 ;
  } 
  else {
      
    s = search - 1 ;
    while ( s > 255 ) {
	
      if ( ( strstart [s + 1 ]- strstart [s ]) == len ) {
	  
	if ( streqstr ( s , search ) ) 
	{
	  result = s ;
	  goto lab40 ;
	} 
      } 
      decr ( s ) ;
    } 
  } 
  lab40: Result = result ;
  return Result ;
} 
strnumber 
slowmakestring ( void ) 
{
  /* 10 */ register strnumber Result; slowmakestring_regmem 
  strnumber s  ;
  strnumber t  ;
  t = makestring () ;
  s = searchstring ( t ) ;
  if ( s > 0 ) 
  {
    {
      decr ( strptr ) ;
      poolptr = strstart [strptr ];
    } 
    Result = s ;
    return Result ;
  } 
  Result = t ;
  return Result ;
} 
void 
zprinttwo ( integer n ) 
{
  printtwo_regmem 
  n = abs ( n ) % 100 ;
  printchar ( 48 + ( n / 10 ) ) ;
  printchar ( 48 + ( n % 10 ) ) ;
} 
void 
zprinthex ( integer n ) 
{
  printhex_regmem 
  unsigned char k  ;
  k = 0 ;
  printchar ( 34 ) ;
  do {
      dig [k ]= n % 16 ;
    n = n / 16 ;
    incr ( k ) ;
  } while ( ! ( n == 0 ) ) ;
  printthedigs ( k ) ;
} 
void 
zprintromanint ( integer n ) 
{
  /* 10 */ printromanint_regmem 
  poolpointer j, k  ;
  nonnegativeinteger u, v  ;
  j = strstart [262 ];
  v = 1000 ;
  while ( true ) {
      
    while ( n >= v ) {
	
      printchar ( strpool [j ]) ;
      n = n - v ;
    } 
    if ( n <= 0 ) 
    return ;
    k = j + 2 ;
    u = v / ( strpool [k - 1 ]- 48 ) ;
    if ( strpool [k - 1 ]== 50 ) 
    {
      k = k + 2 ;
      u = u / ( strpool [k - 1 ]- 48 ) ;
    } 
    if ( n + u >= v ) 
    {
      printchar ( strpool [k ]) ;
      n = n + u ;
    } 
    else {
	
      j = j + 2 ;
      v = v / ( strpool [j - 1 ]- 48 ) ;
    } 
  } 
} 
void 
printcurrentstring ( void ) 
{
  printcurrentstring_regmem 
  poolpointer j  ;
  j = strstart [strptr ];
  while ( j < poolptr ) {
      
    printchar ( strpool [j ]) ;
    incr ( j ) ;
  } 
} 
void 
terminput ( void ) 
{
  terminput_regmem 
  integer k  ;
  fflush ( stdout ) ;
  if ( ! inputln ( stdin , true ) ) 
  fatalerror ( 263 ) ;
  termoffset = 0 ;
  decr ( selector ) ;
  if ( last != first ) 
  {register integer for_end; k = first ;for_end = last - 1 ; if ( k <= 
  for_end) do 
    print ( buffer [k ]) ;
  while ( k++ < for_end ) ;} 
  println () ;
  incr ( selector ) ;
} 
void 
zinterror ( integer n ) 
{
  interror_regmem 
  print ( 286 ) ;
  printint ( n ) ;
  printchar ( 41 ) ;
  error () ;
} 
void 
normalizeselector ( void ) 
{
  normalizeselector_regmem 
  if ( logopened ) 
  selector = 19 ;
  else selector = 17 ;
  if ( jobname == 0 ) 
  openlogfile () ;
  if ( interaction == 0 ) 
  decr ( selector ) ;
} 
void 
pauseforinstructions ( void ) 
{
  pauseforinstructions_regmem 
  if ( OKtointerrupt ) 
  {
    interaction = 3 ;
    if ( ( selector == 18 ) || ( selector == 16 ) ) 
    incr ( selector ) ;
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 296 ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 297 ;
      helpline [1 ]= 298 ;
      helpline [0 ]= 299 ;
    } 
    deletionsallowed = false ;
    error () ;
    deletionsallowed = true ;
    interrupt = 0 ;
  } 
} 
integer 
zhalf ( integer x ) 
{
  register integer Result; half_regmem 
  if ( odd ( x ) ) 
  Result = ( x + 1 ) / 2 ;
  else Result = x / 2 ;
  return Result ;
} 
scaled 
zrounddecimals ( smallnumber k ) 
{
  register scaled Result; rounddecimals_regmem 
  integer a  ;
  a = 0 ;
  while ( k > 0 ) {
      
    decr ( k ) ;
    a = ( a + dig [k ]* 131072L ) / 10 ;
  } 
  Result = ( a + 1 ) / 2 ;
  return Result ;
} 
void 
zprintscaled ( scaled s ) 
{
  printscaled_regmem 
  scaled delta  ;
  if ( s < 0 ) 
  {
    printchar ( 45 ) ;
    s = - (integer) s ;
  } 
  printint ( s / 65536L ) ;
  printchar ( 46 ) ;
  s = 10 * ( s % 65536L ) + 5 ;
  delta = 10 ;
  do {
      if ( delta > 65536L ) 
    s = s - 17232 ;
    printchar ( 48 + ( s / 65536L ) ) ;
    s = 10 * ( s % 65536L ) ;
    delta = delta * 10 ;
  } while ( ! ( s <= delta ) ) ;
} 
scaled 
zmultandadd ( integer n , scaled x , scaled y , scaled maxanswer ) 
{
  register scaled Result; multandadd_regmem 
  if ( n < 0 ) 
  {
    x = - (integer) x ;
    n = - (integer) n ;
  } 
  if ( n == 0 ) 
  Result = y ;
  else if ( ( ( x <= ( maxanswer - y ) / n ) && ( - (integer) x <= ( maxanswer 
  + y ) / n ) ) ) 
  Result = n * x + y ;
  else {
      
    aritherror = true ;
    Result = 0 ;
  } 
  return Result ;
} 
scaled 
zxovern ( scaled x , integer n ) 
{
  register scaled Result; xovern_regmem 
  boolean negative  ;
  negative = false ;
  if ( n == 0 ) 
  {
    aritherror = true ;
    Result = 0 ;
    texremainder = x ;
  } 
  else {
      
    if ( n < 0 ) 
    {
      x = - (integer) x ;
      n = - (integer) n ;
      negative = true ;
    } 
    if ( x >= 0 ) 
    {
      Result = x / n ;
      texremainder = x % n ;
    } 
    else {
	
      Result = - (integer) ( ( - (integer) x ) / n ) ;
      texremainder = - (integer) ( ( - (integer) x ) % n ) ;
    } 
  } 
  if ( negative ) 
  texremainder = - (integer) texremainder ;
  return Result ;
} 
scaled 
zxnoverd ( scaled x , integer n , integer d ) 
{
  register scaled Result; xnoverd_regmem 
  boolean positive  ;
  nonnegativeinteger t, u, v  ;
  if ( x >= 0 ) 
  positive = true ;
  else {
      
    x = - (integer) x ;
    positive = false ;
  } 
  t = ( x % 32768L ) * n ;
  u = ( x / 32768L ) * n + ( t / 32768L ) ;
  v = ( u % d ) * 32768L + ( t % 32768L ) ;
  if ( u / d >= 32768L ) 
  aritherror = true ;
  else u = 32768L * ( u / d ) + ( v / d ) ;
  if ( positive ) 
  {
    Result = u ;
    texremainder = v % d ;
  } 
  else {
      
    Result = - (integer) u ;
    texremainder = - (integer) ( v % d ) ;
  } 
  return Result ;
} 
halfword 
zbadness ( scaled t , scaled s ) 
{
  register halfword Result; badness_regmem 
  integer r  ;
  if ( t == 0 ) 
  Result = 0 ;
  else if ( s <= 0 ) 
  Result = 10000 ;
  else {
      
    if ( t <= 7230584L ) 
    r = ( t * 297 ) / s ;
    else if ( s >= 1663497L ) 
    r = t / ( s / 297 ) ;
    else r = t ;
    if ( r > 1290 ) 
    Result = 10000 ;
    else Result = ( r * r * r + 131072L ) / 262144L ;
  } 
  return Result ;
} 
#ifdef TEXMF_DEBUG
void 
zprintword ( memoryword w ) 
{
  printword_regmem 
  printint ( w .cint ) ;
  printchar ( 32 ) ;
  printscaled ( w .cint ) ;
  printchar ( 32 ) ;
  printscaled ( round ( 65536L * w .gr ) ) ;
  println () ;
  printint ( w .hh .v.LH ) ;
  printchar ( 61 ) ;
  printint ( w .hh.b0 ) ;
  printchar ( 58 ) ;
  printint ( w .hh.b1 ) ;
  printchar ( 59 ) ;
  printint ( w .hh .v.RH ) ;
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
zshowtokenlist ( integer p , integer q , integer l ) 
{
  /* 10 */ showtokenlist_regmem 
  integer m, c  ;
  ASCIIcode matchchr  ;
  ASCIIcode n  ;
  matchchr = 35 ;
  n = 48 ;
  tally = 0 ;
  while ( ( p != -1073741823L ) && ( tally < l ) ) {
      
    if ( p == q ) 
    {
      firstcount = tally ;
      kcp = trickbuf2 [( firstcount - 1 ) % errorline ];
      if ( ( firstcount > 0 ) && ( kcp > 0 ) ) 
      firstcount = firstcount + nrestmultichr ( kcp ) ;
      trickcount = firstcount + 1 + errorline - halferrorline ;
      if ( trickcount < errorline ) 
      trickcount = errorline ;
    } 
    if ( ( p < himemmin ) || ( p > memend ) ) 
    {
      printesc ( 314 ) ;
      return ;
    } 
    if ( mem [p ].hh .v.LH >= 536870911L ) 
    printcs ( mem [p ].hh .v.LH - 536870911L ) ;
    else {
	
      if ( checkkanji ( mem [p ].hh .v.LH ) ) 
      {
	m = mem [p ].hh .v.LH / 16777216L ;
	c = mem [p ].hh .v.LH % 16777216L ;
      } 
      else {
	  
	m = mem [p ].hh .v.LH / 256 ;
	c = mem [p ].hh .v.LH % 256 ;
      } 
      if ( ( m < 16 ) && ( c > 256 ) ) 
      printesc ( 608 ) ;
      else switch ( m ) 
      {case 16 : 
      case 17 : 
      case 18 : 
      case 19 : 
	printkanji ( c ) ;
	break ;
      case 1 : 
      case 2 : 
      case 3 : 
      case 4 : 
      case 7 : 
      case 8 : 
      case 10 : 
      case 11 : 
      case 12 : 
	print ( c ) ;
	break ;
      case 6 : 
	{
	  print ( c ) ;
	  print ( c ) ;
	} 
	break ;
      case 5 : 
	{
	  print ( matchchr ) ;
	  if ( c <= 9 ) 
	  printchar ( c + 48 ) ;
	  else {
	      
	    printchar ( 33 ) ;
	    return ;
	  } 
	} 
	break ;
      case 13 : 
	{
	  matchchr = c ;
	  print ( c ) ;
	  incr ( n ) ;
	  printchar ( n ) ;
	  if ( n > 57 ) 
	  return ;
	} 
	break ;
      case 14 : 
	if ( c == 0 ) 
	print ( 609 ) ;
	break ;
	default: 
	printesc ( 608 ) ;
	break ;
      } 
    } 
    p = mem [p ].hh .v.RH ;
  } 
  if ( p != -1073741823L ) 
  printesc ( 430 ) ;
} 
void 
runaway ( void ) 
{
  runaway_regmem 
  halfword p  ;
  if ( scannerstatus > 1 ) 
  {
    switch ( scannerstatus ) 
    {case 2 : 
      {
	printnl ( 624 ) ;
	p = defref ;
      } 
      break ;
    case 3 : 
      {
	printnl ( 625 ) ;
	p = memtop - 3 ;
      } 
      break ;
    case 4 : 
      {
	printnl ( 626 ) ;
	p = memtop - 4 ;
      } 
      break ;
    case 5 : 
      {
	printnl ( 627 ) ;
	p = defref ;
      } 
      break ;
    } 
    printchar ( 63 ) ;
    println () ;
    showtokenlist ( mem [p ].hh .v.RH , -1073741823L , errorline - 10 ) ;
  } 
} 
halfword 
getavail ( void ) 
{
  register halfword Result; getavail_regmem 
  halfword p  ;
  p = avail ;
  if ( p != -1073741823L ) 
  avail = mem [avail ].hh .v.RH ;
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
      overflow ( 300 , memmax + 1 - memmin ) ;
    } 
  } 
  mem [p ].hh .v.RH = -1073741823L ;
	;
#ifdef STAT
  incr ( dynused ) ;
#endif /* STAT */
  Result = p ;
  return Result ;
} 
void 
zflushlist ( halfword p ) 
{
  flushlist_regmem 
  halfword q, r  ;
  if ( p != -1073741823L ) 
  {
    r = p ;
    do {
	q = r ;
      r = mem [r ].hh .v.RH ;
	;
#ifdef STAT
      decr ( dynused ) ;
#endif /* STAT */
    } while ( ! ( r == -1073741823L ) ) ;
    mem [q ].hh .v.RH = avail ;
    avail = p ;
  } 
} 
halfword 
zgetnode ( integer s ) 
{
  /* 40 10 20 */ register halfword Result; getnode_regmem 
  halfword p  ;
  halfword q  ;
  integer r  ;
  integer t  ;
  lab20: p = rover ;
  do {
      q = p + mem [p ].hh .v.LH ;
    while ( ( mem [q ].hh .v.RH == 1073741823L ) ) {
	
      t = mem [q + 1 ].hh .v.RH ;
      if ( q == rover ) 
      rover = t ;
      mem [t + 1 ].hh .v.LH = mem [q + 1 ].hh .v.LH ;
      mem [mem [q + 1 ].hh .v.LH + 1 ].hh .v.RH = t ;
      q = q + mem [q ].hh .v.LH ;
    } 
    r = q - s ;
    if ( r > p + 1 ) 
    {
      mem [p ].hh .v.LH = r - p ;
      rover = p ;
      goto lab40 ;
    } 
    if ( r == p ) {
	
      if ( mem [p + 1 ].hh .v.RH != p ) 
      {
	rover = mem [p + 1 ].hh .v.RH ;
	t = mem [p + 1 ].hh .v.LH ;
	mem [rover + 1 ].hh .v.LH = t ;
	mem [t + 1 ].hh .v.RH = rover ;
	goto lab40 ;
      } 
    } 
    mem [p ].hh .v.LH = q - p ;
    p = mem [p + 1 ].hh .v.RH ;
  } while ( ! ( p == rover ) ) ;
  if ( s == 1073741824L ) 
  {
    Result = 1073741823L ;
    return Result ;
  } 
  if ( lomemmax + 2 < himemmin ) {
      
    if ( lomemmax + 2 <= membot + 1073741823L ) 
    {
      if ( himemmin - lomemmax >= 1998 ) 
      t = lomemmax + 1000 ;
      else t = lomemmax + 1 + ( himemmin - lomemmax ) / 2 ;
      p = mem [rover + 1 ].hh .v.LH ;
      q = lomemmax ;
      mem [p + 1 ].hh .v.RH = q ;
      mem [rover + 1 ].hh .v.LH = q ;
      if ( t > membot + 1073741823L ) 
      t = membot + 1073741823L ;
      mem [q + 1 ].hh .v.RH = rover ;
      mem [q + 1 ].hh .v.LH = p ;
      mem [q ].hh .v.RH = 1073741823L ;
      mem [q ].hh .v.LH = t - lomemmax ;
      lomemmax = t ;
      mem [lomemmax ].hh .v.RH = -1073741823L ;
      mem [lomemmax ].hh .v.LH = -1073741823L ;
      rover = q ;
      goto lab20 ;
    } 
  } 
  overflow ( 300 , memmax + 1 - memmin ) ;
  lab40: mem [r ].hh .v.RH = -1073741823L ;
	;
#ifdef STAT
  varused = varused + s ;
#endif /* STAT */
  if ( s >= 4 ) 
  {
    mem [r + s - 2 ].cint = curinput .synctextagfield ;
    mem [r + s - 1 ].cint = line ;
  } 
  Result = r ;
  return Result ;
} 
void 
zfreenode ( halfword p , halfword s ) 
{
  freenode_regmem 
  halfword q  ;
  mem [p ].hh .v.LH = s ;
  mem [p ].hh .v.RH = 1073741823L ;
  q = mem [rover + 1 ].hh .v.LH ;
  mem [p + 1 ].hh .v.LH = q ;
  mem [p + 1 ].hh .v.RH = rover ;
  mem [rover + 1 ].hh .v.LH = p ;
  mem [q + 1 ].hh .v.RH = p ;
	;
#ifdef STAT
  varused = varused - s ;
#endif /* STAT */
} 
halfword 
newnullbox ( void ) 
{
  register halfword Result; newnullbox_regmem 
  halfword p  ;
  p = getnode ( 10 ) ;
  mem [p ].hh.b0 = 0 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].cint = 0 ;
  mem [p + 2 ].cint = 0 ;
  mem [p + 3 ].cint = 0 ;
  mem [p + 4 ].cint = 0 ;
  mem [p + 5 ].hh .v.RH = -1073741823L ;
  mem [p + 5 ].hh.b0 = 0 ;
  mem [p + 5 ].hh.b1 = 0 ;
  mem [p + 6 ].gr = 0.0 ;
  mem [p + 7 ].hh .v.RH = membot ;
  mem [p + 7 ].hh .v.LH = membot ;
  incr ( mem [membot ].hh .v.RH ) ;
  incr ( mem [membot ].hh .v.RH ) ;
  Result = p ;
  return Result ;
} 
halfword 
znewdirnode ( halfword b , eightbits dir ) 
{
  register halfword Result; newdirnode_regmem 
  halfword p  ;
  if ( mem [b ].hh.b0 > 1 ) 
  confusion ( 301 ) ;
  p = newnullbox () ;
  mem [p ].hh.b0 = 2 ;
  mem [p ].hh.b1 = ( ( mem [p ].hh.b1 ) / 8 ) * 8 + dir ;
  switch ( ( ( mem [b ].hh.b1 ) % 8 ) ) 
  {case 4 : 
    switch ( dir ) 
    {case 3 : 
      {
	mem [p + 1 ].cint = mem [b + 3 ].cint + mem [b + 2 ].cint ;
	mem [p + 2 ].cint = mem [b + 1 ].cint / ((double) 2 ) ;
	mem [p + 3 ].cint = mem [b + 1 ].cint - mem [p + 2 ].cint ;
      } 
      break ;
    case 1 : 
      {
	mem [p + 1 ].cint = mem [b + 3 ].cint + mem [b + 2 ].cint ;
	mem [p + 2 ].cint = 0 ;
	mem [p + 3 ].cint = mem [b + 1 ].cint ;
      } 
      break ;
      default: 
      confusion ( 303 ) ;
      break ;
    } 
    break ;
  case 3 : 
    switch ( dir ) 
    {case 4 : 
      {
	mem [p + 1 ].cint = mem [b + 3 ].cint + mem [b + 2 ].cint ;
	mem [p + 2 ].cint = 0 ;
	mem [p + 3 ].cint = mem [b + 1 ].cint ;
      } 
      break ;
    case 1 : 
      {
	mem [p + 1 ].cint = mem [b + 1 ].cint ;
	mem [p + 2 ].cint = mem [b + 3 ].cint ;
	mem [p + 3 ].cint = mem [b + 2 ].cint ;
      } 
      break ;
      default: 
      confusion ( 304 ) ;
      break ;
    } 
    break ;
  case 1 : 
    switch ( dir ) 
    {case 4 : 
      {
	mem [p + 1 ].cint = mem [b + 3 ].cint + mem [b + 2 ].cint ;
	mem [p + 2 ].cint = 0 ;
	mem [p + 3 ].cint = mem [b + 1 ].cint ;
      } 
      break ;
    case 3 : 
      {
	mem [p + 1 ].cint = mem [b + 1 ].cint ;
	mem [p + 2 ].cint = mem [b + 3 ].cint ;
	mem [p + 3 ].cint = mem [b + 2 ].cint ;
      } 
      break ;
      default: 
      confusion ( 305 ) ;
      break ;
    } 
    break ;
    default: 
    confusion ( 302 ) ;
    break ;
  } 
  mem [b ].hh .v.RH = -1073741823L ;
  mem [p + 5 ].hh .v.RH = b ;
  Result = p ;
  return Result ;
} 
halfword 
newrule ( void ) 
{
  register halfword Result; newrule_regmem 
  halfword p  ;
  p = getnode ( 6 ) ;
  mem [p ].hh.b0 = 3 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].cint = -1073741824L ;
  mem [p + 2 ].cint = -1073741824L ;
  mem [p + 3 ].cint = -1073741824L ;
  Result = p ;
  return Result ;
} 
halfword 
znewligature ( internalfontnumber f , quarterword c , halfword q ) 
{
  register halfword Result; newligature_regmem 
  halfword p  ;
  p = getnode ( 2 ) ;
  mem [p ].hh.b0 = 8 ;
  mem [p + 1 ].hh.b0 = f ;
  mem [p + 1 ].hh.b1 = c ;
  mem [p + 1 ].hh .v.RH = q ;
  mem [p ].hh.b1 = 0 ;
  Result = p ;
  return Result ;
} 
halfword 
znewligitem ( quarterword c ) 
{
  register halfword Result; newligitem_regmem 
  halfword p  ;
  p = getnode ( 2 ) ;
  mem [p ].hh.b1 = c ;
  mem [p + 1 ].hh .v.RH = -1073741823L ;
  Result = p ;
  return Result ;
} 
halfword 
newdisc ( void ) 
{
  register halfword Result; newdisc_regmem 
  halfword p  ;
  p = getnode ( 2 ) ;
  mem [p ].hh.b0 = 9 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].hh .v.LH = -1073741823L ;
  mem [p + 1 ].hh .v.RH = -1073741823L ;
  Result = p ;
  return Result ;
} 
halfword 
znewmath ( scaled w , smallnumber s ) 
{
  register halfword Result; newmath_regmem 
  halfword p  ;
  p = getnode ( 4 ) ;
  mem [p ].hh.b0 = 11 ;
  mem [p ].hh.b1 = s ;
  mem [p + 1 ].cint = w ;
  Result = p ;
  return Result ;
} 
halfword 
znewspec ( halfword p ) 
{
  register halfword Result; newspec_regmem 
  halfword q  ;
  q = getnode ( 4 ) ;
  mem [q ]= mem [p ];
  mem [q ].hh .v.RH = -1073741823L ;
  mem [q + 1 ].cint = mem [p + 1 ].cint ;
  mem [q + 2 ].cint = mem [p + 2 ].cint ;
  mem [q + 3 ].cint = mem [p + 3 ].cint ;
  Result = q ;
  return Result ;
} 
halfword 
znewparamglue ( smallnumber n ) 
{
  register halfword Result; newparamglue_regmem 
  halfword p  ;
  halfword q  ;
  p = getnode ( 4 ) ;
  mem [p ].hh.b0 = 12 ;
  mem [p ].hh.b1 = n + 1 ;
  mem [p + 1 ].hh .v.RH = -1073741823L ;
  q = eqtb [24528 + n ].hh .v.RH ;
  mem [p + 1 ].hh .v.LH = q ;
  incr ( mem [q ].hh .v.RH ) ;
  Result = p ;
  return Result ;
} 
halfword 
znewglue ( halfword q ) 
{
  register halfword Result; newglue_regmem 
  halfword p  ;
  p = getnode ( 4 ) ;
  mem [p ].hh.b0 = 12 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].hh .v.RH = -1073741823L ;
  mem [p + 1 ].hh .v.LH = q ;
  incr ( mem [q ].hh .v.RH ) ;
  Result = p ;
  return Result ;
} 
halfword 
znewskipparam ( smallnumber n ) 
{
  register halfword Result; newskipparam_regmem 
  halfword p  ;
  tempptr = newspec ( eqtb [24528 + n ].hh .v.RH ) ;
  p = newglue ( tempptr ) ;
  mem [tempptr ].hh .v.RH = -1073741823L ;
  mem [p ].hh.b1 = n + 1 ;
  Result = p ;
  return Result ;
} 
halfword 
znewkern ( scaled w ) 
{
  register halfword Result; newkern_regmem 
  halfword p  ;
  p = getnode ( 4 ) ;
  mem [p ].hh.b0 = 13 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].cint = w ;
  Result = p ;
  return Result ;
} 
halfword 
znewpenalty ( integer m ) 
{
  register halfword Result; newpenalty_regmem 
  halfword p  ;
  p = getnode ( 4 ) ;
  mem [p ].hh.b0 = 14 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].cint = m ;
  Result = p ;
  return Result ;
} 
#ifdef TEXMF_DEBUG
void 
zcheckmem ( boolean printlocs ) 
{
  /* 31 32 */ checkmem_regmem 
  halfword p, q  ;
  boolean clobbered  ;
  {register integer for_end; p = memmin ;for_end = lomemmax ; if ( p <= 
  for_end) do 
    freearr [p ]= false ;
  while ( p++ < for_end ) ;} 
  {register integer for_end; p = himemmin ;for_end = memend ; if ( p <= 
  for_end) do 
    freearr [p ]= false ;
  while ( p++ < for_end ) ;} 
  p = avail ;
  q = -1073741823L ;
  clobbered = false ;
  while ( p != -1073741823L ) {
      
    if ( ( p > memend ) || ( p < himemmin ) ) 
    clobbered = true ;
    else if ( freearr [p ]) 
    clobbered = true ;
    if ( clobbered ) 
    {
      printnl ( 306 ) ;
      printint ( q ) ;
      goto lab31 ;
    } 
    freearr [p ]= true ;
    q = p ;
    p = mem [q ].hh .v.RH ;
  } 
  lab31: ;
  p = rover ;
  q = -1073741823L ;
  clobbered = false ;
  do {
      if ( ( p >= lomemmax ) || ( p < memmin ) ) 
    clobbered = true ;
    else if ( ( mem [p + 1 ].hh .v.RH >= lomemmax ) || ( mem [p + 1 ].hh 
    .v.RH < memmin ) ) 
    clobbered = true ;
    else if ( ! ( ( mem [p ].hh .v.RH == 1073741823L ) ) || ( mem [p ].hh 
    .v.LH < 2 ) || ( p + mem [p ].hh .v.LH > lomemmax ) || ( mem [mem [p + 
    1 ].hh .v.RH + 1 ].hh .v.LH != p ) ) 
    clobbered = true ;
    if ( clobbered ) 
    {
      printnl ( 307 ) ;
      printint ( q ) ;
      goto lab32 ;
    } 
    {register integer for_end; q = p ;for_end = p + mem [p ].hh .v.LH - 1 
    ; if ( q <= for_end) do 
      {
	if ( freearr [q ]) 
	{
	  printnl ( 308 ) ;
	  printint ( q ) ;
	  goto lab32 ;
	} 
	freearr [q ]= true ;
      } 
    while ( q++ < for_end ) ;} 
    q = p ;
    p = mem [p + 1 ].hh .v.RH ;
  } while ( ! ( p == rover ) ) ;
  lab32: ;
  p = memmin ;
  while ( p <= lomemmax ) {
      
    if ( ( mem [p ].hh .v.RH == 1073741823L ) ) 
    {
      printnl ( 309 ) ;
      printint ( p ) ;
    } 
    while ( ( p <= lomemmax ) && ! freearr [p ]) incr ( p ) ;
    while ( ( p <= lomemmax ) && freearr [p ]) incr ( p ) ;
  } 
  if ( printlocs ) 
  {
    printnl ( 310 ) ;
    {register integer for_end; p = memmin ;for_end = lomemmax ; if ( p <= 
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
  {register integer for_end; p = memmin ;for_end = lomemmax ; if ( p <= 
  for_end) do 
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
  searchmem_regmem 
  integer q  ;
  {register integer for_end; q = memmin ;for_end = lomemmax ; if ( q <= 
  for_end) do 
    {
      if ( mem [q ].hh .v.RH == p ) 
      {
	printnl ( 311 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
      if ( mem [q ].hh .v.LH == p ) 
      {
	printnl ( 312 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
    } 
  while ( q++ < for_end ) ;} 
  {register integer for_end; q = himemmin ;for_end = memend ; if ( q <= 
  for_end) do 
    {
      if ( mem [q ].hh .v.RH == p ) 
      {
	printnl ( 311 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
      if ( mem [q ].hh .v.LH == p ) 
      {
	printnl ( 312 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
    } 
  while ( q++ < for_end ) ;} 
  {register integer for_end; q = 1 ;for_end = 25587 ; if ( q <= for_end) do 
    {
      if ( eqtb [q ].hh .v.RH == p ) 
      {
	printnl ( 541 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
    } 
  while ( q++ < for_end ) ;} 
  if ( saveptr > 0 ) 
  {register integer for_end; q = 0 ;for_end = saveptr - 1 ; if ( q <= 
  for_end) do 
    {
      if ( savestack [q ].hh .v.RH == p ) 
      {
	printnl ( 600 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
    } 
  while ( q++ < for_end ) ;} 
  {register integer for_end; q = 0 ;for_end = hyphsize ; if ( q <= for_end) 
  do 
    {
      if ( hyphlist [q ]== p ) 
      {
	printnl ( 1041 ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
    } 
  while ( q++ < for_end ) ;} 
} 
#endif /* TEXMF_DEBUG */
void 
zpdferror ( strnumber t , strnumber p ) 
{
  pdferror_regmem 
  normalizeselector () ;
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 1611 ) ;
  } 
  if ( t != 0 ) 
  {
    print ( 286 ) ;
    print ( t ) ;
    print ( 41 ) ;
  } 
  print ( 622 ) ;
  print ( p ) ;
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
strnumber 
ztokenstostring ( halfword p ) 
{
  register strnumber Result; tokenstostring_regmem 
  if ( selector == 21 ) 
  pdferror ( 1612 , 1613 ) ;
  oldsetting = selector ;
  selector = 21 ;
  showtokenlist ( mem [p ].hh .v.RH , -1073741823L , poolsize - poolptr ) ;
  selector = oldsetting ;
  lasttokensstring = makestring () ;
  Result = lasttokensstring ;
  return Result ;
} 
void 
zflushstr ( strnumber s ) 
{
  flushstr_regmem 
  if ( ( s == strptr - 1 ) ) 
  {
    decr ( strptr ) ;
    poolptr = strstart [strptr ];
  } 
} 
void 
zshortdisplay ( integer p ) 
{
  shortdisplay_regmem 
  integer n  ;
  while ( p > memmin ) {
      
    if ( ( p >= himemmin ) ) 
    {
      if ( p <= memend ) 
      {
	if ( mem [p ].hh.b0 != fontinshortdisplay ) 
	{
	  if ( ( mem [p ].hh.b0 > fontmax ) ) 
	  printchar ( 42 ) ;
	  else printesc ( hash [15526 + mem [p ].hh.b0 ].v.RH ) ;
	  printchar ( 32 ) ;
	  fontinshortdisplay = mem [p ].hh.b0 ;
	} 
	if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
	{
	  p = mem [p ].hh .v.RH ;
	  printkanji ( mem [p ].hh .v.LH ) ;
	} 
	else print ( mem [p ].hh.b1 ) ;
      } 
    } 
    else switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 2 : 
    case 4 : 
    case 10 : 
    case 6 : 
    case 7 : 
    case 15 : 
      print ( 313 ) ;
      break ;
    case 3 : 
      printchar ( 124 ) ;
      break ;
    case 12 : 
      if ( mem [p + 1 ].hh .v.LH != membot ) 
      printchar ( 32 ) ;
      break ;
    case 11 : 
      if ( mem [p ].hh.b1 >= 4 ) 
      print ( 313 ) ;
      else printchar ( 36 ) ;
      break ;
    case 8 : 
      shortdisplay ( mem [p + 1 ].hh .v.RH ) ;
      break ;
    case 9 : 
      {
	shortdisplay ( mem [p + 1 ].hh .v.LH ) ;
	shortdisplay ( mem [p + 1 ].hh .v.RH ) ;
	n = mem [p ].hh.b1 ;
	while ( n > 0 ) {
	    
	  if ( mem [p ].hh .v.RH != -1073741823L ) 
	  p = mem [p ].hh .v.RH ;
	  decr ( n ) ;
	} 
      } 
      break ;
      default: 
      ;
      break ;
    } 
    p = mem [p ].hh .v.RH ;
  } 
} 
void 
zprintfontandchar ( integer p ) 
{
  printfontandchar_regmem 
  if ( p > memend ) 
  printesc ( 314 ) ;
  else {
      
    if ( ( mem [p ].hh.b0 > fontmax ) ) 
    printchar ( 42 ) ;
    else printesc ( hash [15526 + mem [p ].hh.b0 ].v.RH ) ;
    printchar ( 32 ) ;
    if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
    {
      p = mem [p ].hh .v.RH ;
      printkanji ( mem [p ].hh .v.LH ) ;
    } 
    else print ( mem [p ].hh.b1 ) ;
  } 
} 
void 
zprintmark ( integer p ) 
{
  printmark_regmem 
  printchar ( 123 ) ;
  if ( ( p < himemmin ) || ( p > memend ) ) 
  printesc ( 314 ) ;
  else showtokenlist ( mem [p ].hh .v.RH , -1073741823L , maxprintline - 10 
  ) ;
  printchar ( 125 ) ;
} 
void 
zprintruledimen ( scaled d ) 
{
  printruledimen_regmem 
  if ( ( d == -1073741824L ) ) 
  printchar ( 42 ) ;
  else printscaled ( d ) ;
} 
void 
zprintglue ( scaled d , integer order , strnumber s ) 
{
  printglue_regmem 
  printscaled ( d ) ;
  if ( ( order < 0 ) || ( order > 4 ) ) 
  print ( 315 ) ;
  else if ( order > 0 ) 
  {
    print ( 316 ) ;
    while ( order > 1 ) {
	
      printchar ( 108 ) ;
      decr ( order ) ;
    } 
  } 
  else if ( s != 0 ) 
  print ( s ) ;
} 
void 
zprintspec ( integer p , strnumber s ) 
{
  printspec_regmem 
  if ( ( p < memmin ) || ( p >= lomemmax ) ) 
  printchar ( 42 ) ;
  else {
      
    printscaled ( mem [p + 1 ].cint ) ;
    if ( s != 0 ) 
    print ( s ) ;
    if ( mem [p + 2 ].cint != 0 ) 
    {
      print ( 317 ) ;
      printglue ( mem [p + 2 ].cint , mem [p ].hh.b0 , s ) ;
    } 
    if ( mem [p + 3 ].cint != 0 ) 
    {
      print ( 318 ) ;
      printglue ( mem [p + 3 ].cint , mem [p ].hh.b1 , s ) ;
    } 
  } 
} 
void 
zprintfamandchar ( halfword p , integer t ) 
{
  printfamandchar_regmem 
  KANJIcode cx  ;
  printesc ( 491 ) ;
  printint ( mem [p ].hh.b0 ) ;
  printchar ( 32 ) ;
  if ( t == 1 ) 
  print ( mem [p ].hh.b1 ) ;
  else {
      
    cx = mem [p + 3 ].hh .v.LH ;
    printkanji ( cx ) ;
  } 
} 
void 
zprintdelimiter ( halfword p ) 
{
  printdelimiter_regmem 
  integer a  ;
  a = mem [p ].qqqq .b0 * 256 + mem [p ].qqqq .b1 ;
  a = a * 4096 + mem [p ].qqqq .b2 * 256 + mem [p ].qqqq .b3 ;
  if ( a < 0 ) 
  printint ( a ) ;
  else printhex ( a ) ;
} 
void 
zprintsubsidiarydata ( halfword p , ASCIIcode c ) 
{
  printsubsidiarydata_regmem 
  if ( ( poolptr - strstart [strptr ]) >= depththreshold ) 
  {
    if ( mem [p ].hh .v.RH != 0 ) 
    print ( 319 ) ;
  } 
  else {
      
    {
      strpool [poolptr ]= c ;
      incr ( poolptr ) ;
    } 
    tempptr = p ;
    switch ( mem [p ].hh .v.RH ) 
    {case 1 : 
    case 6 : 
      {
	println () ;
	printcurrentstring () ;
	printfamandchar ( p , mem [p ].hh .v.RH ) ;
      } 
      break ;
    case 2 : 
    case 3 : 
      showinfo () ;
      break ;
    case 4 : 
      if ( mem [p ].hh .v.LH == -1073741823L ) 
      {
	println () ;
	printcurrentstring () ;
	print ( 959 ) ;
      } 
      else showinfo () ;
      break ;
      default: 
      ;
      break ;
    } 
    decr ( poolptr ) ;
  } 
} 
void 
zprintstyle ( integer c ) 
{
  printstyle_regmem 
  switch ( c / 2 ) 
  {case 0 : 
    printesc ( 960 ) ;
    break ;
  case 1 : 
    printesc ( 961 ) ;
    break ;
  case 2 : 
    printesc ( 962 ) ;
    break ;
  case 3 : 
    printesc ( 963 ) ;
    break ;
    default: 
    print ( 964 ) ;
    break ;
  } 
} 
void 
zprintskipparam ( integer n ) 
{
  printskipparam_regmem 
  switch ( n ) 
  {case 0 : 
    printesc ( 395 ) ;
    break ;
  case 1 : 
    printesc ( 396 ) ;
    break ;
  case 2 : 
    printesc ( 397 ) ;
    break ;
  case 3 : 
    printesc ( 398 ) ;
    break ;
  case 4 : 
    printesc ( 399 ) ;
    break ;
  case 5 : 
    printesc ( 400 ) ;
    break ;
  case 6 : 
    printesc ( 401 ) ;
    break ;
  case 7 : 
    printesc ( 402 ) ;
    break ;
  case 8 : 
    printesc ( 403 ) ;
    break ;
  case 9 : 
    printesc ( 404 ) ;
    break ;
  case 10 : 
    printesc ( 405 ) ;
    break ;
  case 11 : 
    printesc ( 406 ) ;
    break ;
  case 12 : 
    printesc ( 407 ) ;
    break ;
  case 13 : 
    printesc ( 408 ) ;
    break ;
  case 14 : 
    printesc ( 409 ) ;
    break ;
  case 17 : 
    printesc ( 410 ) ;
    break ;
  case 18 : 
    printesc ( 411 ) ;
    break ;
  case 19 : 
    printesc ( 412 ) ;
    break ;
  case 15 : 
    printesc ( 413 ) ;
    break ;
  case 16 : 
    printesc ( 414 ) ;
    break ;
  case 20 : 
    print ( 415 ) ;
    break ;
    default: 
    print ( 416 ) ;
    break ;
  } 
} 
void 
zshownodelist ( integer p ) 
{
  /* 10 */ shownodelist_regmem 
  integer n  ;
  real g  ;
  if ( ( poolptr - strstart [strptr ]) > depththreshold ) 
  {
    if ( p > -1073741823L ) 
    print ( 319 ) ;
    return ;
  } 
  n = 0 ;
  while ( p > memmin ) {
      
    println () ;
    printcurrentstring () ;
    if ( p > memend ) 
    {
      print ( 320 ) ;
      return ;
    } 
    incr ( n ) ;
    if ( n > breadthmax ) 
    {
      print ( 321 ) ;
      return ;
    } 
    if ( ( p >= himemmin ) ) 
    {
      printfontandchar ( p ) ;
      if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
      p = mem [p ].hh .v.RH ;
    } 
    else switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 2 : 
    case 15 : 
      {
	switch ( mem [p ].hh.b0 ) 
	{case 0 : 
	  printesc ( 104 ) ;
	  break ;
	case 1 : 
	  printesc ( 118 ) ;
	  break ;
	case 2 : 
	  printesc ( 324 ) ;
	  break ;
	  default: 
	  printesc ( 325 ) ;
	  break ;
	} 
	print ( 326 ) ;
	printscaled ( mem [p + 3 ].cint ) ;
	printchar ( 43 ) ;
	printscaled ( mem [p + 2 ].cint ) ;
	print ( 327 ) ;
	printscaled ( mem [p + 1 ].cint ) ;
	if ( mem [p ].hh.b0 == 15 ) 
	{
	  if ( mem [p ].hh.b1 != 0 ) 
	  {
	    print ( 286 ) ;
	    printint ( mem [p ].hh.b1 + 1 ) ;
	    print ( 329 ) ;
	  } 
	  if ( mem [p + 6 ].cint != 0 ) 
	  {
	    print ( 330 ) ;
	    printglue ( mem [p + 6 ].cint , mem [p + 5 ].hh.b1 , 0 ) ;
	  } 
	  if ( mem [p + 4 ].cint != 0 ) 
	  {
	    print ( 331 ) ;
	    printglue ( mem [p + 4 ].cint , mem [p + 5 ].hh.b0 , 0 ) ;
	  } 
	} 
	else {
	    
	  g = mem [p + 6 ].gr ;
	  if ( ( g != 0.0 ) && ( mem [p + 5 ].hh.b0 != 0 ) ) 
	  {
	    print ( 332 ) ;
	    if ( mem [p + 5 ].hh.b0 == 2 ) 
	    print ( 333 ) ;
	    if ( fabs ( g ) > 20000.0 ) 
	    {
	      if ( g > 0.0 ) 
	      printchar ( 62 ) ;
	      else print ( 334 ) ;
	      printglue ( 20000 * 65536L , mem [p + 5 ].hh.b1 , 0 ) ;
	    } 
	    else printglue ( round ( 65536L * g ) , mem [p + 5 ].hh.b1 , 0 ) 
	    ;
	  } 
	  if ( mem [p + 4 ].cint != 0 ) 
	  {
	    print ( 328 ) ;
	    printscaled ( mem [p + 4 ].cint ) ;
	  } 
	  if ( ( eTeXmode == 1 ) ) {
	      
	    if ( ( mem [p ].hh.b0 == 0 ) && ( ( ( mem [p ].hh.b1 ) / 8 ) 
	    == 2 ) ) 
	    print ( 1517 ) ;
	  } 
	  if ( ( ( mem [p ].hh.b1 ) % 8 ) != 0 ) 
	  {
	    printdirectionalt ( ( ( mem [p ].hh.b1 ) % 8 ) ) ;
	  } 
	} 
	{
	  {
	    strpool [poolptr ]= 46 ;
	    incr ( poolptr ) ;
	  } 
	  shownodelist ( mem [p + 5 ].hh .v.RH ) ;
	  decr ( poolptr ) ;
	} 
      } 
      break ;
    case 3 : 
      {
	printesc ( 335 ) ;
	printruledimen ( mem [p + 3 ].cint ) ;
	printchar ( 43 ) ;
	printruledimen ( mem [p + 2 ].cint ) ;
	print ( 327 ) ;
	printruledimen ( mem [p + 1 ].cint ) ;
      } 
      break ;
    case 4 : 
      {
	printesc ( 336 ) ;
	printint ( mem [p ].hh.b1 ) ;
	printdir ( mem [p + 5 ].hh.b1 ) ;
	print ( 337 ) ;
	printscaled ( mem [p + 3 ].cint ) ;
	print ( 338 ) ;
	printspec ( mem [p + 4 ].hh .v.RH , 0 ) ;
	printchar ( 44 ) ;
	printscaled ( mem [p + 2 ].cint ) ;
	print ( 339 ) ;
	printint ( mem [p + 1 ].cint ) ;
	{
	  {
	    strpool [poolptr ]= 46 ;
	    incr ( poolptr ) ;
	  } 
	  shownodelist ( mem [p + 4 ].hh .v.LH ) ;
	  decr ( poolptr ) ;
	} 
      } 
      break ;
    case 10 : 
      switch ( mem [p ].hh.b1 ) 
      {case 0 : 
	{
	  printwritewhatsit ( 1428 , p ) ;
	  printchar ( 61 ) ;
	  printfilename ( mem [p + 1 ].hh .v.RH , mem [p + 2 ].hh .v.LH , 
	  mem [p + 2 ].hh .v.RH ) ;
	} 
	break ;
      case 1 : 
	{
	  printwritewhatsit ( 649 , p ) ;
	  printmark ( mem [p + 1 ].hh .v.RH ) ;
	} 
	break ;
      case 2 : 
	printwritewhatsit ( 1429 , p ) ;
	break ;
      case 3 : 
	{
	  printesc ( 1430 ) ;
	  printmark ( mem [p + 1 ].hh .v.RH ) ;
	} 
	break ;
      case 4 : 
	{
	  printesc ( 1432 ) ;
	  printint ( mem [p + 1 ].hh .v.RH ) ;
	  print ( 1437 ) ;
	  printint ( mem [p + 1 ].hh.b0 ) ;
	  printchar ( 44 ) ;
	  printint ( mem [p + 1 ].hh.b1 ) ;
	  printchar ( 41 ) ;
	} 
	break ;
      case 6 : 
	printesc ( 1434 ) ;
	break ;
	default: 
	print ( 1438 ) ;
	break ;
      } 
      break ;
    case 5 : 
      {
	printesc ( 322 ) ;
	printscaled ( mem [p + 1 ].cint ) ;
      } 
      break ;
    case 12 : 
      if ( mem [p ].hh.b1 >= 100 ) 
      {
	printesc ( 344 ) ;
	if ( mem [p ].hh.b1 == 101 ) 
	printchar ( 99 ) ;
	else if ( mem [p ].hh.b1 == 102 ) 
	printchar ( 120 ) ;
	print ( 345 ) ;
	printspec ( mem [p + 1 ].hh .v.LH , 0 ) ;
	{
	  {
	    strpool [poolptr ]= 46 ;
	    incr ( poolptr ) ;
	  } 
	  shownodelist ( mem [p + 1 ].hh .v.RH ) ;
	  decr ( poolptr ) ;
	} 
      } 
      else {
	  
	printesc ( 340 ) ;
	if ( mem [p ].hh.b1 != 0 ) 
	{
	  printchar ( 40 ) ;
	  if ( mem [p ].hh.b1 < 98 ) 
	  printskipparam ( mem [p ].hh.b1 - 1 ) ;
	  else if ( mem [p ].hh.b1 == 98 ) 
	  printesc ( 341 ) ;
	  else printesc ( 342 ) ;
	  printchar ( 41 ) ;
	} 
	if ( mem [p ].hh.b1 != 98 ) 
	{
	  printchar ( 32 ) ;
	  if ( mem [p ].hh.b1 < 98 ) 
	  printspec ( mem [p + 1 ].hh .v.LH , 0 ) ;
	  else printspec ( mem [p + 1 ].hh .v.LH , 343 ) ;
	} 
      } 
      break ;
    case 13 : 
      if ( mem [p ].hh.b1 != 99 ) 
      {
	printesc ( 346 ) ;
	if ( mem [p ].hh.b1 != 0 ) 
	printchar ( 32 ) ;
	printscaled ( mem [p + 1 ].cint ) ;
	if ( mem [p ].hh.b1 == 2 ) 
	print ( 347 ) ;
      } 
      else {
	  
	printesc ( 348 ) ;
	printscaled ( mem [p + 1 ].cint ) ;
	print ( 343 ) ;
      } 
      break ;
    case 11 : 
      if ( mem [p ].hh.b1 > 1 ) 
      {
	if ( odd ( mem [p ].hh.b1 ) ) 
	printesc ( 349 ) ;
	else printesc ( 350 ) ;
	if ( mem [p ].hh.b1 > 8 ) 
	printchar ( 82 ) ;
	else if ( mem [p ].hh.b1 > 4 ) 
	printchar ( 76 ) ;
	else printchar ( 77 ) ;
      } 
      else {
	  
	printesc ( 351 ) ;
	if ( mem [p ].hh.b1 == 0 ) 
	print ( 352 ) ;
	else print ( 353 ) ;
	if ( mem [p + 1 ].cint != 0 ) 
	{
	  print ( 354 ) ;
	  printscaled ( mem [p + 1 ].cint ) ;
	} 
      } 
      break ;
    case 8 : 
      {
	printfontandchar ( p + 1 ) ;
	print ( 355 ) ;
	if ( mem [p ].hh.b1 > 1 ) 
	printchar ( 124 ) ;
	fontinshortdisplay = mem [p + 1 ].hh.b0 ;
	shortdisplay ( mem [p + 1 ].hh .v.RH ) ;
	if ( odd ( mem [p ].hh.b1 ) ) 
	printchar ( 124 ) ;
	printchar ( 41 ) ;
      } 
      break ;
    case 14 : 
      {
	printesc ( 356 ) ;
	printint ( mem [p + 1 ].cint ) ;
	if ( mem [p ].hh.b1 == 1 ) 
	print ( 357 ) ;
	else if ( mem [p ].hh.b1 == 2 ) 
	print ( 358 ) ;
      } 
      break ;
    case 9 : 
      {
	printesc ( 359 ) ;
	if ( mem [p ].hh.b1 > 0 ) 
	{
	  print ( 360 ) ;
	  printint ( mem [p ].hh.b1 ) ;
	} 
	{
	  {
	    strpool [poolptr ]= 46 ;
	    incr ( poolptr ) ;
	  } 
	  shownodelist ( mem [p + 1 ].hh .v.LH ) ;
	  decr ( poolptr ) ;
	} 
	{
	  strpool [poolptr ]= 124 ;
	  incr ( poolptr ) ;
	} 
	shownodelist ( mem [p + 1 ].hh .v.RH ) ;
	decr ( poolptr ) ;
      } 
      break ;
    case 6 : 
      {
	printesc ( 361 ) ;
	if ( mem [p + 1 ].hh .v.LH != 0 ) 
	{
	  printchar ( 115 ) ;
	  printint ( mem [p + 1 ].hh .v.LH ) ;
	} 
	printmark ( mem [p + 1 ].hh .v.RH ) ;
      } 
      break ;
    case 7 : 
      {
	printesc ( 362 ) ;
	{
	  {
	    strpool [poolptr ]= 46 ;
	    incr ( poolptr ) ;
	  } 
	  shownodelist ( mem [p + 1 ].cint ) ;
	  decr ( poolptr ) ;
	} 
      } 
      break ;
    case 16 : 
      printstyle ( mem [p ].hh.b1 ) ;
      break ;
    case 17 : 
      {
	printesc ( 573 ) ;
	{
	  strpool [poolptr ]= 68 ;
	  incr ( poolptr ) ;
	} 
	shownodelist ( mem [p + 1 ].hh .v.LH ) ;
	decr ( poolptr ) ;
	{
	  strpool [poolptr ]= 84 ;
	  incr ( poolptr ) ;
	} 
	shownodelist ( mem [p + 1 ].hh .v.RH ) ;
	decr ( poolptr ) ;
	{
	  strpool [poolptr ]= 83 ;
	  incr ( poolptr ) ;
	} 
	shownodelist ( mem [p + 2 ].hh .v.LH ) ;
	decr ( poolptr ) ;
	{
	  strpool [poolptr ]= 115 ;
	  incr ( poolptr ) ;
	} 
	shownodelist ( mem [p + 2 ].hh .v.RH ) ;
	decr ( poolptr ) ;
      } 
      break ;
    case 18 : 
    case 19 : 
    case 20 : 
    case 21 : 
    case 22 : 
    case 23 : 
    case 24 : 
    case 25 : 
    case 26 : 
    case 29 : 
    case 28 : 
    case 31 : 
    case 30 : 
    case 32 : 
    case 33 : 
      {
	switch ( mem [p ].hh.b0 ) 
	{case 18 : 
	  printesc ( 965 ) ;
	  break ;
	case 19 : 
	  printesc ( 966 ) ;
	  break ;
	case 20 : 
	  printesc ( 967 ) ;
	  break ;
	case 21 : 
	  printesc ( 968 ) ;
	  break ;
	case 22 : 
	  printesc ( 969 ) ;
	  break ;
	case 23 : 
	  printesc ( 970 ) ;
	  break ;
	case 24 : 
	  printesc ( 971 ) ;
	  break ;
	case 25 : 
	  printesc ( 972 ) ;
	  break ;
	case 29 : 
	  printesc ( 973 ) ;
	  break ;
	case 28 : 
	  printesc ( 974 ) ;
	  break ;
	case 31 : 
	  printesc ( 589 ) ;
	  break ;
	case 26 : 
	  {
	    printesc ( 582 ) ;
	    printdelimiter ( p + 5 ) ;
	  } 
	  break ;
	case 30 : 
	  {
	    printesc ( 550 ) ;
	    printfamandchar ( p + 5 , 1 ) ;
	  } 
	  break ;
	case 32 : 
	  {
	    printesc ( 975 ) ;
	    printdelimiter ( p + 1 ) ;
	  } 
	  break ;
	case 33 : 
	  {
	    if ( mem [p ].hh.b1 == 0 ) 
	    printesc ( 976 ) ;
	    else printesc ( 977 ) ;
	    printdelimiter ( p + 1 ) ;
	  } 
	  break ;
	} 
	if ( mem [p ].hh.b0 < 32 ) 
	{
	  if ( mem [p ].hh.b1 != 0 ) {
	      
	    if ( mem [p ].hh.b1 == 1 ) 
	    printesc ( 978 ) ;
	    else printesc ( 979 ) ;
	  } 
	  printsubsidiarydata ( p + 1 , 46 ) ;
	} 
	printsubsidiarydata ( p + 2 , 94 ) ;
	printsubsidiarydata ( p + 3 , 95 ) ;
      } 
      break ;
    case 27 : 
      {
	printesc ( 980 ) ;
	if ( mem [p + 1 ].cint == 1073741824L ) 
	print ( 981 ) ;
	else printscaled ( mem [p + 1 ].cint ) ;
	if ( ( mem [p + 5 ].qqqq .b0 != 0 ) || ( mem [p + 5 ].qqqq .b1 != 
	0 ) || ( mem [p + 5 ].qqqq .b2 != 0 ) || ( mem [p + 5 ].qqqq .b3 
	!= 0 ) ) 
	{
	  print ( 982 ) ;
	  printdelimiter ( p + 5 ) ;
	} 
	if ( ( mem [p + 4 ].qqqq .b0 != 0 ) || ( mem [p + 4 ].qqqq .b1 != 
	0 ) || ( mem [p + 4 ].qqqq .b2 != 0 ) || ( mem [p + 4 ].qqqq .b3 
	!= 0 ) ) 
	{
	  print ( 983 ) ;
	  printdelimiter ( p + 4 ) ;
	} 
	printsubsidiarydata ( p + 2 , 92 ) ;
	printsubsidiarydata ( p + 3 , 47 ) ;
      } 
      break ;
      default: 
      print ( 323 ) ;
      break ;
    } 
    p = mem [p ].hh .v.RH ;
  } 
} 
void 
zshowbox ( halfword p ) 
{
  showbox_regmem 
  depththreshold = eqtb [29213 ].cint ;
  breadthmax = eqtb [29212 ].cint ;
  if ( breadthmax <= 0 ) 
  breadthmax = 5 ;
  if ( poolptr + depththreshold >= poolsize ) 
  depththreshold = poolsize - poolptr - 1 ;
  shownodelist ( p ) ;
  println () ;
} 
void 
zdeletetokenref ( halfword p ) 
{
  deletetokenref_regmem 
  if ( mem [p ].hh .v.LH == -1073741823L ) 
  flushlist ( p ) ;
  else decr ( mem [p ].hh .v.LH ) ;
} 
void 
zdeleteglueref ( halfword p ) 
{
  deleteglueref_regmem 
  if ( mem [p ].hh .v.RH == -1073741823L ) 
  freenode ( p , 4 ) ;
  else decr ( mem [p ].hh .v.RH ) ;
} 
void 
zflushnodelist ( halfword p ) 
{
  /* 30 */ flushnodelist_regmem 
  halfword q  ;
  while ( p != -1073741823L ) {
      
    q = mem [p ].hh .v.RH ;
    if ( ( p >= himemmin ) ) 
    {
      mem [p ].hh .v.RH = avail ;
      avail = p ;
	;
#ifdef STAT
      decr ( dynused ) ;
#endif /* STAT */
    } 
    else {
	
      switch ( mem [p ].hh.b0 ) 
      {case 0 : 
      case 1 : 
      case 2 : 
      case 15 : 
	{
	  flushnodelist ( mem [p + 5 ].hh .v.RH ) ;
	  {
	    if ( mem [mem [p + 7 ].hh .v.RH ].hh .v.RH == -1073741823L ) 
	    freenode ( mem [p + 7 ].hh .v.RH , 4 ) ;
	    else decr ( mem [mem [p + 7 ].hh .v.RH ].hh .v.RH ) ;
	  } 
	  {
	    if ( mem [mem [p + 7 ].hh .v.LH ].hh .v.RH == -1073741823L ) 
	    freenode ( mem [p + 7 ].hh .v.LH , 4 ) ;
	    else decr ( mem [mem [p + 7 ].hh .v.LH ].hh .v.RH ) ;
	  } 
	  freenode ( p , 10 ) ;
	  goto lab30 ;
	} 
	break ;
      case 3 : 
	{
	  freenode ( p , 6 ) ;
	  goto lab30 ;
	} 
	break ;
      case 4 : 
	{
	  flushnodelist ( mem [p + 4 ].hh .v.LH ) ;
	  deleteglueref ( mem [p + 4 ].hh .v.RH ) ;
	  freenode ( p , 6 ) ;
	  goto lab30 ;
	} 
	break ;
      case 10 : 
	{
	  switch ( mem [p ].hh.b1 ) 
	  {case 0 : 
	    freenode ( p , 3 ) ;
	    break ;
	  case 1 : 
	  case 3 : 
	    {
	      deletetokenref ( mem [p + 1 ].hh .v.RH ) ;
	      freenode ( p , 2 ) ;
	      goto lab30 ;
	    } 
	    break ;
	  case 2 : 
	  case 4 : 
	    freenode ( p , 2 ) ;
	    break ;
	  case 6 : 
	    freenode ( p , 2 ) ;
	    break ;
	    default: 
	    confusion ( 1440 ) ;
	    break ;
	  } 
	  goto lab30 ;
	} 
	break ;
      case 12 : 
	{
	  {
	    if ( mem [mem [p + 1 ].hh .v.LH ].hh .v.RH == -1073741823L ) 
	    freenode ( mem [p + 1 ].hh .v.LH , 4 ) ;
	    else decr ( mem [mem [p + 1 ].hh .v.LH ].hh .v.RH ) ;
	  } 
	  if ( mem [p + 1 ].hh .v.RH != -1073741823L ) 
	  flushnodelist ( mem [p + 1 ].hh .v.RH ) ;
	  freenode ( p , 4 ) ;
	  goto lab30 ;
	} 
	break ;
      case 5 : 
	;
	break ;
      case 13 : 
      case 11 : 
      case 14 : 
	{
	  freenode ( p , 4 ) ;
	  goto lab30 ;
	} 
	break ;
      case 8 : 
	flushnodelist ( mem [p + 1 ].hh .v.RH ) ;
	break ;
      case 6 : 
	deletetokenref ( mem [p + 1 ].hh .v.RH ) ;
	break ;
      case 9 : 
	{
	  flushnodelist ( mem [p + 1 ].hh .v.LH ) ;
	  flushnodelist ( mem [p + 1 ].hh .v.RH ) ;
	} 
	break ;
      case 7 : 
	flushnodelist ( mem [p + 1 ].cint ) ;
	break ;
      case 16 : 
	{
	  freenode ( p , 3 ) ;
	  goto lab30 ;
	} 
	break ;
      case 17 : 
	{
	  flushnodelist ( mem [p + 1 ].hh .v.LH ) ;
	  flushnodelist ( mem [p + 1 ].hh .v.RH ) ;
	  flushnodelist ( mem [p + 2 ].hh .v.LH ) ;
	  flushnodelist ( mem [p + 2 ].hh .v.RH ) ;
	  freenode ( p , 3 ) ;
	  goto lab30 ;
	} 
	break ;
      case 18 : 
      case 19 : 
      case 20 : 
      case 21 : 
      case 22 : 
      case 23 : 
      case 24 : 
      case 25 : 
      case 26 : 
      case 29 : 
      case 28 : 
      case 31 : 
      case 30 : 
	{
	  if ( ( mem [p + 1 ].hh .v.RH >= 2 ) && ( mem [p + 1 ].hh .v.RH 
	  != 6 ) && ( mem [p + 1 ].hh .v.RH != 7 ) ) 
	  flushnodelist ( mem [p + 1 ].hh .v.LH ) ;
	  if ( mem [p + 2 ].hh .v.RH >= 2 && ( mem [p + 2 ].hh .v.RH != 6 
	  ) && ( mem [p + 2 ].hh .v.RH != 7 ) ) 
	  flushnodelist ( mem [p + 2 ].hh .v.LH ) ;
	  if ( mem [p + 3 ].hh .v.RH >= 2 && ( mem [p + 3 ].hh .v.RH != 6 
	  ) && ( mem [p + 3 ].hh .v.RH != 7 ) ) 
	  flushnodelist ( mem [p + 3 ].hh .v.LH ) ;
	  if ( mem [p ].hh.b0 == 26 ) 
	  freenode ( p , 6 ) ;
	  else if ( mem [p ].hh.b0 == 30 ) 
	  freenode ( p , 6 ) ;
	  else freenode ( p , 5 ) ;
	  goto lab30 ;
	} 
	break ;
      case 32 : 
      case 33 : 
	{
	  freenode ( p , 5 ) ;
	  goto lab30 ;
	} 
	break ;
      case 27 : 
	{
	  flushnodelist ( mem [p + 2 ].hh .v.LH ) ;
	  flushnodelist ( mem [p + 3 ].hh .v.LH ) ;
	  freenode ( p , 6 ) ;
	  goto lab30 ;
	} 
	break ;
	default: 
	confusion ( 363 ) ;
	break ;
      } 
      freenode ( p , 2 ) ;
      lab30: ;
    } 
    p = q ;
  } 
} 
halfword 
zcopynodelist ( halfword p ) 
{
  register halfword Result; copynodelist_regmem 
  halfword h  ;
  halfword q  ;
  halfword r  ;
  unsigned char words  ;
  h = getavail () ;
  q = h ;
  while ( p != -1073741823L ) {
      
    words = 1 ;
    if ( ( p >= himemmin ) ) 
    r = getavail () ;
    else switch ( mem [p ].hh.b0 ) 
    {case 2 : 
    case 0 : 
    case 1 : 
    case 15 : 
      {
	r = getnode ( 10 ) ;
	mem [r + 8 ].cint = mem [p + 8 ].cint ;
	mem [r + 9 ].cint = mem [p + 9 ].cint ;
	mem [r + 7 ]= mem [p + 7 ];
	mem [r + 6 ]= mem [p + 6 ];
	mem [r + 5 ]= mem [p + 5 ];
	incr ( mem [mem [r + 7 ].hh .v.RH ].hh .v.RH ) ;
	incr ( mem [mem [r + 7 ].hh .v.LH ].hh .v.RH ) ;
	mem [r + 5 ].hh .v.RH = copynodelist ( mem [p + 5 ].hh .v.RH ) ;
	words = 5 ;
      } 
      break ;
    case 3 : 
      {
	r = getnode ( 6 ) ;
	words = 4 ;
      } 
      break ;
    case 4 : 
      {
	r = getnode ( 6 ) ;
	mem [r + 5 ]= mem [p + 5 ];
	mem [r + 4 ]= mem [p + 4 ];
	incr ( mem [mem [p + 4 ].hh .v.RH ].hh .v.RH ) ;
	mem [r + 4 ].hh .v.LH = copynodelist ( mem [p + 4 ].hh .v.LH ) ;
	words = 4 ;
      } 
      break ;
    case 10 : 
      switch ( mem [p ].hh.b1 ) 
      {case 0 : 
	{
	  r = getnode ( 3 ) ;
	  words = 3 ;
	} 
	break ;
      case 1 : 
      case 3 : 
	{
	  r = getnode ( 2 ) ;
	  incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
	  words = 2 ;
	} 
	break ;
      case 2 : 
      case 4 : 
	{
	  r = getnode ( 2 ) ;
	  words = 2 ;
	} 
	break ;
      case 6 : 
	r = getnode ( 2 ) ;
	break ;
	default: 
	confusion ( 1439 ) ;
	break ;
      } 
      break ;
    case 12 : 
      {
	r = getnode ( 4 ) ;
	incr ( mem [mem [p + 1 ].hh .v.LH ].hh .v.RH ) ;
	mem [r + 2 ].cint = mem [p + 2 ].cint ;
	mem [r + 3 ].cint = mem [p + 3 ].cint ;
	mem [r + 1 ].hh .v.LH = mem [p + 1 ].hh .v.LH ;
	mem [r + 1 ].hh .v.RH = copynodelist ( mem [p + 1 ].hh .v.RH ) ;
      } 
      break ;
    case 5 : 
      {
	r = getnode ( 2 ) ;
	words = 2 ;
      } 
      break ;
    case 13 : 
    case 11 : 
    case 14 : 
      {
	r = getnode ( 4 ) ;
	words = 4 ;
      } 
      break ;
    case 8 : 
      {
	r = getnode ( 2 ) ;
	mem [r + 1 ]= mem [p + 1 ];
	mem [r + 1 ].hh .v.RH = copynodelist ( mem [p + 1 ].hh .v.RH ) ;
      } 
      break ;
    case 9 : 
      {
	r = getnode ( 2 ) ;
	mem [r + 1 ].hh .v.LH = copynodelist ( mem [p + 1 ].hh .v.LH ) ;
	mem [r + 1 ].hh .v.RH = copynodelist ( mem [p + 1 ].hh .v.RH ) ;
      } 
      break ;
    case 6 : 
      {
	r = getnode ( 2 ) ;
	incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
	words = 2 ;
      } 
      break ;
    case 7 : 
      {
	r = getnode ( 2 ) ;
	mem [r + 1 ].cint = copynodelist ( mem [p + 1 ].cint ) ;
      } 
      break ;
      default: 
      confusion ( 364 ) ;
      break ;
    } 
    while ( words > 0 ) {
	
      decr ( words ) ;
      mem [r + words ]= mem [p + words ];
    } 
    mem [q ].hh .v.RH = r ;
    q = r ;
    p = mem [p ].hh .v.RH ;
  } 
  mem [q ].hh .v.RH = -1073741823L ;
  q = mem [h ].hh .v.RH ;
  {
    mem [h ].hh .v.RH = avail ;
    avail = h ;
	;
#ifdef STAT
    decr ( dynused ) ;
#endif /* STAT */
  } 
  Result = q ;
  return Result ;
} 
void 
zprintmode ( integer m ) 
{
  printmode_regmem 
  if ( m > 0 ) 
  switch ( m / ( 117 ) ) 
  {case 0 : 
    print ( 365 ) ;
    break ;
  case 1 : 
    print ( 366 ) ;
    break ;
  case 2 : 
    print ( 367 ) ;
    break ;
  } 
  else if ( m == 0 ) 
  print ( 368 ) ;
  else switch ( ( - (integer) m ) / ( 117 ) ) 
  {case 0 : 
    print ( 369 ) ;
    break ;
  case 1 : 
    print ( 370 ) ;
    break ;
  case 2 : 
    print ( 371 ) ;
    break ;
  } 
} 
void 
zprintinmode ( integer m ) 
{
  printinmode_regmem 
  if ( m > 0 ) 
  switch ( m / ( 117 ) ) 
  {case 0 : 
    print ( 372 ) ;
    break ;
  case 1 : 
    print ( 373 ) ;
    break ;
  case 2 : 
    print ( 374 ) ;
    break ;
  } 
  else if ( m == 0 ) 
  print ( 375 ) ;
  else switch ( ( - (integer) m ) / ( 117 ) ) 
  {case 0 : 
    print ( 376 ) ;
    break ;
  case 1 : 
    print ( 377 ) ;
    break ;
  case 2 : 
    print ( 378 ) ;
    break ;
  } 
} 
void 
pushnest ( void ) 
{
  pushnest_regmem 
  if ( nestptr > maxneststack ) 
  {
    maxneststack = nestptr ;
    if ( nestptr == nestsize ) 
    overflow ( 379 , nestsize ) ;
  } 
  nest [nestptr ]= curlist ;
  incr ( nestptr ) ;
  curlist .headfield = newnullbox () ;
  curlist .tailfield = curlist .headfield ;
  curlist .pnodefield = curlist .tailfield ;
  curlist .pgfield = 0 ;
  curlist .pdispfield = 0 ;
  curlist .lastjchrfield = -1073741823L ;
  curlist .mlfield = line ;
  curlist .eTeXauxfield = -1073741823L ;
} 
void 
popnest ( void ) 
{
  popnest_regmem 
  {
    if ( mem [mem [curlist .headfield + 7 ].hh .v.RH ].hh .v.RH == 
    -1073741823L ) 
    freenode ( mem [curlist .headfield + 7 ].hh .v.RH , 4 ) ;
    else decr ( mem [mem [curlist .headfield + 7 ].hh .v.RH ].hh .v.RH ) ;
  } 
  {
    if ( mem [mem [curlist .headfield + 7 ].hh .v.LH ].hh .v.RH == 
    -1073741823L ) 
    freenode ( mem [curlist .headfield + 7 ].hh .v.LH , 4 ) ;
    else decr ( mem [mem [curlist .headfield + 7 ].hh .v.LH ].hh .v.RH ) ;
  } 
  freenode ( curlist .headfield , 10 ) ;
  decr ( nestptr ) ;
  curlist = nest [nestptr ];
} 
void 
showactivities ( void ) 
{
  showactivities_regmem 
  integer p  ;
  short m  ;
  memoryword a  ;
  halfword q, r  ;
  integer t  ;
  nest [nestptr ]= curlist ;
  printnl ( 344 ) ;
  println () ;
  {register integer for_end; p = nestptr ;for_end = 0 ; if ( p >= for_end) 
  do 
    {
      m = nest [p ].modefield ;
      a = nest [p ].auxfield ;
      printnl ( 380 ) ;
      printdirection ( nest [p ].dirfield ) ;
      print ( 381 ) ;
      printmode ( m ) ;
      print ( 382 ) ;
      printint ( abs ( nest [p ].mlfield ) ) ;
      if ( m == 118 ) {
	  
	if ( nest [p ].pgfield != 8585216L ) 
	{
	  print ( 383 ) ;
	  printint ( nest [p ].pgfield % 65536L ) ;
	  print ( 384 ) ;
	  printint ( nest [p ].pgfield / 4194304L ) ;
	  printchar ( 44 ) ;
	  printint ( ( nest [p ].pgfield / 65536L ) % 64 ) ;
	  printchar ( 41 ) ;
	} 
      } 
      if ( nest [p ].mlfield < 0 ) 
      print ( 385 ) ;
      if ( p == 0 ) 
      {
	if ( memtop - 2 != pagetail ) 
	{
	  printnl ( 1083 ) ;
	  if ( outputactive ) 
	  print ( 1084 ) ;
	  showbox ( mem [memtop - 2 ].hh .v.RH ) ;
	  if ( pagecontents > 0 ) 
	  {
	    printnl ( 1085 ) ;
	    printtotals () ;
	    printnl ( 1086 ) ;
	    printscaled ( pagesofar [0 ]) ;
	    r = mem [memtop ].hh .v.RH ;
	    while ( r != memtop ) {
		
	      println () ;
	      printesc ( 336 ) ;
	      t = mem [r ].hh.b1 ;
	      printint ( t ) ;
	      print ( 1087 ) ;
	      if ( eqtb [29262 + t ].cint == 1000 ) 
	      t = mem [r + 3 ].cint ;
	      else t = xovern ( mem [r + 3 ].cint , 1000 ) * eqtb [29262 + 
	      t ].cint ;
	      printscaled ( t ) ;
	      if ( mem [r ].hh.b0 == 1 ) 
	      {
		q = memtop - 2 ;
		t = 0 ;
		do {
		    q = mem [q ].hh .v.RH ;
		  if ( ( mem [q ].hh.b0 == 4 ) && ( mem [q ].hh.b1 == mem 
		  [r ].hh.b1 ) ) 
		  incr ( t ) ;
		} while ( ! ( q == mem [r + 1 ].hh .v.LH ) ) ;
		print ( 1088 ) ;
		printint ( t ) ;
		print ( 1089 ) ;
	      } 
	      r = mem [r ].hh .v.RH ;
	    } 
	  } 
	} 
	if ( mem [memtop - 1 ].hh .v.RH != -1073741823L ) 
	printnl ( 386 ) ;
      } 
      showbox ( mem [nest [p ].headfield ].hh .v.RH ) ;
      switch ( abs ( m ) / ( 117 ) ) 
      {case 0 : 
	{
	  printnl ( 387 ) ;
	  if ( a .cint <= -65536000L ) 
	  print ( 388 ) ;
	  else printscaled ( a .cint ) ;
	  if ( nest [p ].pgfield != 0 ) 
	  {
	    print ( 389 ) ;
	    printint ( nest [p ].pgfield ) ;
	    if ( nest [p ].pgfield != 1 ) 
	    print ( 390 ) ;
	    else print ( 391 ) ;
	  } 
	} 
	break ;
      case 1 : 
	{
	  printnl ( 392 ) ;
	  printint ( a .hh .v.LH ) ;
	  if ( m > 0 ) {
	      
	    if ( a .hh .v.RH > 0 ) 
	    {
	      print ( 393 ) ;
	      printint ( a .hh .v.RH ) ;
	    } 
	  } 
	} 
	break ;
      case 2 : 
	if ( a .cint != -1073741823L ) 
	{
	  print ( 394 ) ;
	  showbox ( a .cint ) ;
	} 
	break ;
      } 
    } 
  while ( p-- > for_end ) ;} 
} 
void 
zprintparam ( integer n ) 
{
  printparam_regmem 
  switch ( n ) 
  {case 0 : 
    printesc ( 447 ) ;
    break ;
  case 1 : 
    printesc ( 448 ) ;
    break ;
  case 2 : 
    printesc ( 449 ) ;
    break ;
  case 3 : 
    printesc ( 450 ) ;
    break ;
  case 4 : 
    printesc ( 451 ) ;
    break ;
  case 5 : 
    printesc ( 452 ) ;
    break ;
  case 6 : 
    printesc ( 453 ) ;
    break ;
  case 7 : 
    printesc ( 454 ) ;
    break ;
  case 8 : 
    printesc ( 455 ) ;
    break ;
  case 9 : 
    printesc ( 456 ) ;
    break ;
  case 10 : 
    printesc ( 457 ) ;
    break ;
  case 11 : 
    printesc ( 458 ) ;
    break ;
  case 12 : 
    printesc ( 459 ) ;
    break ;
  case 13 : 
    printesc ( 460 ) ;
    break ;
  case 14 : 
    printesc ( 461 ) ;
    break ;
  case 15 : 
    printesc ( 462 ) ;
    break ;
  case 16 : 
    printesc ( 463 ) ;
    break ;
  case 17 : 
    printesc ( 464 ) ;
    break ;
  case 18 : 
    printesc ( 465 ) ;
    break ;
  case 19 : 
    printesc ( 466 ) ;
    break ;
  case 20 : 
    printesc ( 467 ) ;
    break ;
  case 21 : 
    printesc ( 468 ) ;
    break ;
  case 22 : 
    printesc ( 469 ) ;
    break ;
  case 23 : 
    printesc ( 470 ) ;
    break ;
  case 24 : 
    printesc ( 471 ) ;
    break ;
  case 25 : 
    printesc ( 472 ) ;
    break ;
  case 26 : 
    printesc ( 473 ) ;
    break ;
  case 27 : 
    printesc ( 474 ) ;
    break ;
  case 28 : 
    printesc ( 475 ) ;
    break ;
  case 29 : 
    printesc ( 476 ) ;
    break ;
  case 30 : 
    printesc ( 477 ) ;
    break ;
  case 31 : 
    printesc ( 478 ) ;
    break ;
  case 32 : 
    printesc ( 479 ) ;
    break ;
  case 33 : 
    printesc ( 480 ) ;
    break ;
  case 34 : 
    printesc ( 481 ) ;
    break ;
  case 35 : 
    printesc ( 482 ) ;
    break ;
  case 36 : 
    printesc ( 483 ) ;
    break ;
  case 37 : 
    printesc ( 484 ) ;
    break ;
  case 38 : 
    printesc ( 485 ) ;
    break ;
  case 39 : 
    printesc ( 486 ) ;
    break ;
  case 40 : 
    printesc ( 487 ) ;
    break ;
  case 41 : 
    printesc ( 488 ) ;
    break ;
  case 42 : 
    printesc ( 489 ) ;
    break ;
  case 43 : 
    printesc ( 490 ) ;
    break ;
  case 44 : 
    printesc ( 491 ) ;
    break ;
  case 46 : 
    printesc ( 492 ) ;
    break ;
  case 47 : 
    printesc ( 493 ) ;
    break ;
  case 48 : 
    printesc ( 494 ) ;
    break ;
  case 49 : 
    printesc ( 495 ) ;
    break ;
  case 50 : 
    printesc ( 496 ) ;
    break ;
  case 45 : 
    printesc ( 497 ) ;
    break ;
  case 56 : 
    printesc ( 498 ) ;
    break ;
  case 57 : 
    printesc ( 499 ) ;
    break ;
  case 58 : 
    printesc ( 500 ) ;
    break ;
  case 59 : 
    printesc ( 501 ) ;
    break ;
  case 51 : 
    printesc ( 502 ) ;
    break ;
  case 52 : 
    printesc ( 503 ) ;
    break ;
  case 53 : 
    printesc ( 504 ) ;
    break ;
  case 54 : 
    printesc ( 505 ) ;
    break ;
  case 55 : 
    printesc ( 506 ) ;
    break ;
  case 60 : 
    printesc ( 507 ) ;
    break ;
  case 61 : 
    printesc ( 508 ) ;
    break ;
  case 62 : 
    printesc ( 509 ) ;
    break ;
  case 63 : 
    printesc ( 1567 ) ;
    break ;
  case 64 : 
    printesc ( 1464 ) ;
    break ;
  case 65 : 
    printesc ( 1465 ) ;
    break ;
  case 66 : 
    printesc ( 1466 ) ;
    break ;
  case 67 : 
    printesc ( 1467 ) ;
    break ;
  case 68 : 
    printesc ( 1468 ) ;
    break ;
  case 69 : 
    printesc ( 1469 ) ;
    break ;
  case 70 : 
    printesc ( 1470 ) ;
    break ;
  case 71 : 
    printesc ( 1471 ) ;
    break ;
  case 72 : 
    printesc ( 1472 ) ;
    break ;
  case 73 : 
    printesc ( 1512 ) ;
    break ;
    default: 
    print ( 510 ) ;
    break ;
  } 
} 
void 
begindiagnostic ( void ) 
{
  begindiagnostic_regmem 
  oldsetting = selector ;
  if ( ( eqtb [29217 ].cint <= 0 ) && ( selector == 19 ) ) 
  {
    decr ( selector ) ;
    if ( history == 0 ) 
    history = 1 ;
  } 
} 
void 
zenddiagnostic ( boolean blankline ) 
{
  enddiagnostic_regmem 
  printnl ( 344 ) ;
  if ( blankline ) 
  println () ;
  selector = oldsetting ;
} 
void 
zprintlengthparam ( integer n ) 
{
  printlengthparam_regmem 
  switch ( n ) 
  {case 0 : 
    printesc ( 513 ) ;
    break ;
  case 1 : 
    printesc ( 514 ) ;
    break ;
  case 2 : 
    printesc ( 515 ) ;
    break ;
  case 3 : 
    printesc ( 516 ) ;
    break ;
  case 4 : 
    printesc ( 517 ) ;
    break ;
  case 5 : 
    printesc ( 518 ) ;
    break ;
  case 6 : 
    printesc ( 519 ) ;
    break ;
  case 7 : 
    printesc ( 520 ) ;
    break ;
  case 8 : 
    printesc ( 521 ) ;
    break ;
  case 9 : 
    printesc ( 522 ) ;
    break ;
  case 10 : 
    printesc ( 523 ) ;
    break ;
  case 11 : 
    printesc ( 524 ) ;
    break ;
  case 12 : 
    printesc ( 525 ) ;
    break ;
  case 13 : 
    printesc ( 526 ) ;
    break ;
  case 14 : 
    printesc ( 527 ) ;
    break ;
  case 15 : 
    printesc ( 528 ) ;
    break ;
  case 16 : 
    printesc ( 529 ) ;
    break ;
  case 17 : 
    printesc ( 530 ) ;
    break ;
  case 18 : 
    printesc ( 531 ) ;
    break ;
  case 19 : 
    printesc ( 532 ) ;
    break ;
  case 21 : 
    printesc ( 533 ) ;
    break ;
  case 22 : 
    printesc ( 534 ) ;
    break ;
  case 20 : 
    printesc ( 535 ) ;
    break ;
  case 23 : 
    printesc ( 536 ) ;
    break ;
  case 24 : 
    printesc ( 537 ) ;
    break ;
    default: 
    print ( 538 ) ;
    break ;
  } 
} 
void 
zprintcmdchr ( quarterword cmd , halfword chrcode ) 
{
  printcmdchr_regmem 
  integer n  ;
  switch ( cmd ) 
  {case 1 : 
    {
      print ( 610 ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 2 : 
    {
      print ( 611 ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 3 : 
    {
      print ( 612 ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 6 : 
    {
      print ( 613 ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 7 : 
    {
      print ( 614 ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 8 : 
    {
      print ( 615 ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 9 : 
    print ( 616 ) ;
    break ;
  case 10 : 
    {
      print ( 617 ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 11 : 
    {
      print ( 618 ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 12 : 
    {
      print ( 619 ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 16 : 
  case 17 : 
  case 18 : 
  case 19 : 
    {
      print ( 620 ) ;
      printkanji ( chrcode ) ;
    } 
    break ;
  case 84 : 
  case 85 : 
    if ( chrcode < 24549 ) 
    printskipparam ( chrcode - 24528 ) ;
    else if ( chrcode < 24805 ) 
    {
      printesc ( 417 ) ;
      printint ( chrcode - 24549 ) ;
    } 
    else {
	
      printesc ( 418 ) ;
      printint ( chrcode - 24805 ) ;
    } 
    break ;
  case 81 : 
    if ( chrcode >= 25072 ) 
    {
      printesc ( 429 ) ;
      printint ( chrcode - 25072 ) ;
    } 
    else switch ( chrcode ) 
    {case 25062 : 
      printesc ( 420 ) ;
      break ;
    case 25063 : 
      printesc ( 421 ) ;
      break ;
    case 25064 : 
      printesc ( 422 ) ;
      break ;
    case 25065 : 
      printesc ( 423 ) ;
      break ;
    case 25066 : 
      printesc ( 424 ) ;
      break ;
    case 25067 : 
      printesc ( 425 ) ;
      break ;
    case 25068 : 
      printesc ( 426 ) ;
      break ;
    case 25069 : 
      printesc ( 427 ) ;
      break ;
    case 25071 : 
      printesc ( 1463 ) ;
      break ;
      default: 
      printesc ( 428 ) ;
      break ;
    } 
    break ;
  case 82 : 
    if ( chrcode < 29262 ) 
    printparam ( chrcode - 29188 ) ;
    else {
	
      printesc ( 511 ) ;
      printint ( chrcode - 29262 ) ;
    } 
    break ;
  case 83 : 
    if ( chrcode < 29799 ) 
    printlengthparam ( chrcode - 29774 ) ;
    else {
	
      printesc ( 539 ) ;
      printint ( chrcode - 29799 ) ;
    } 
    break ;
  case 49 : 
    printesc ( 550 ) ;
    break ;
  case 104 : 
    printesc ( 551 ) ;
    break ;
  case 44 : 
    printesc ( 552 ) ;
    break ;
  case 45 : 
    printesc ( 553 ) ;
    break ;
  case 86 : 
    printesc ( 565 ) ;
    break ;
  case 66 : 
    printesc ( 554 ) ;
    break ;
  case 46 : 
    printesc ( 580 ) ;
    break ;
  case 20 : 
    printesc ( 555 ) ;
    break ;
  case 123 : 
    printesc ( 546 ) ;
    break ;
  case 100 : 
    printesc ( 562 ) ;
    break ;
  case 101 : 
    printesc ( 563 ) ;
    break ;
  case 102 : 
    printesc ( 564 ) ;
    break ;
  case 15 : 
    printesc ( 557 ) ;
    break ;
  case 106 : 
    printesc ( 559 ) ;
    break ;
  case 72 : 
    printesc ( 547 ) ;
    break ;
  case 67 : 
    printesc ( 560 ) ;
    break ;
  case 69 : 
    printesc ( 32 ) ;
    break ;
  case 118 : 
    if ( chrcode == 0 ) 
    printesc ( 561 ) ;
    else printesc ( 871 ) ;
    break ;
  case 36 : 
    printesc ( 566 ) ;
    break ;
  case 40 : 
    printesc ( 567 ) ;
    break ;
  case 43 : 
    if ( chrcode == 0 ) 
    printesc ( 568 ) ;
    else printesc ( 543 ) ;
    break ;
  case 41 : 
    printesc ( 336 ) ;
    break ;
  case 48 : 
    printesc ( 47 ) ;
    break ;
  case 54 : 
    printesc ( 556 ) ;
    break ;
  case 22 : 
    {
      printesc ( 361 ) ;
      if ( chrcode > 0 ) 
      printchar ( 115 ) ;
    } 
    break ;
  case 50 : 
    printesc ( 569 ) ;
    break ;
  case 21 : 
    printesc ( 570 ) ;
    break ;
  case 59 : 
    printesc ( 573 ) ;
    break ;
  case 105 : 
    printesc ( 574 ) ;
    break ;
  case 38 : 
    printesc ( 575 ) ;
    break ;
  case 70 : 
    printesc ( 576 ) ;
    break ;
  case 119 : 
    if ( chrcode == 0 ) 
    printesc ( 577 ) ;
    else printesc ( 543 ) ;
    break ;
  case 60 : 
    printesc ( 341 ) ;
    break ;
  case 68 : 
    printesc ( 578 ) ;
    break ;
  case 71 : 
    printesc ( 582 ) ;
    break ;
  case 110 : 
    if ( chrcode == 0 ) 
    printesc ( 584 ) ;
    else printesc ( 1527 ) ;
    break ;
  case 0 : 
    printesc ( 585 ) ;
    break ;
  case 112 : 
    printesc ( 586 ) ;
    break ;
  case 92 : 
    printesc ( 581 ) ;
    break ;
  case 96 : 
    switch ( chrcode ) 
    {case 25061 : 
      printesc ( 579 ) ;
      break ;
    case 25328 : 
      printesc ( 1560 ) ;
      break ;
    case 25329 : 
      printesc ( 1561 ) ;
      break ;
    case 25330 : 
      printesc ( 1562 ) ;
      break ;
    case 25331 : 
      printesc ( 1563 ) ;
      break ;
    } 
    break ;
  case 125 : 
    if ( chrcode == 0 ) 
    printesc ( 587 ) ;
    else if ( chrcode == 1 ) 
    printesc ( 1502 ) ;
    else printesc ( 1503 ) ;
    break ;
  case 80 : 
    {
      printesc ( 429 ) ;
      if ( chrcode != membot ) 
      printsanum ( chrcode ) ;
    } 
    break ;
  case 42 : 
    printesc ( 362 ) ;
    break ;
  case 37 : 
    if ( chrcode == 0 ) 
    printesc ( 588 ) ;
    else switch ( chrcode ) 
    {case 6 : 
      printesc ( 1513 ) ;
      break ;
    case 7 : 
      printesc ( 1514 ) ;
      break ;
    case 10 : 
      printesc ( 1515 ) ;
      break ;
      default: 
      printesc ( 1516 ) ;
      break ;
    } 
    break ;
  case 61 : 
    printesc ( 589 ) ;
    break ;
  case 39 : 
    printesc ( 590 ) ;
    break ;
  case 13 : 
    printesc ( 652 ) ;
    break ;
  case 120 : 
    if ( chrcode == 0 ) 
    printesc ( 690 ) ;
    else if ( chrcode == 2 ) 
    printesc ( 1525 ) ;
    else printesc ( 691 ) ;
    break ;
  case 126 : 
    {
      switch ( ( chrcode % 5 ) ) 
      {case 1 : 
	printesc ( 693 ) ;
	break ;
      case 2 : 
	printesc ( 694 ) ;
	break ;
      case 3 : 
	printesc ( 695 ) ;
	break ;
      case 4 : 
	printesc ( 696 ) ;
	break ;
	default: 
	printesc ( 692 ) ;
	break ;
      } 
      if ( chrcode >= 5 ) 
      printchar ( 115 ) ;
    } 
    break ;
  case 103 : 
    {
      if ( ( chrcode < membot ) || ( chrcode > membot + 23 ) ) 
      cmd = ( mem [chrcode ].hh.b0 / 16 ) ;
      else {
	  
	cmd = chrcode - membot ;
	chrcode = -1073741823L ;
      } 
      if ( cmd == 0 ) 
      printesc ( 511 ) ;
      else if ( cmd == 1 ) 
      printesc ( 539 ) ;
      else if ( cmd == 2 ) 
      printesc ( 417 ) ;
      else printesc ( 418 ) ;
      if ( chrcode != -1073741823L ) 
      printsanum ( chrcode ) ;
    } 
    break ;
  case 91 : 
    if ( chrcode == 1 ) 
    printesc ( 735 ) ;
    else printesc ( 734 ) ;
    break ;
  case 94 : 
    if ( chrcode == 0 ) 
    printesc ( 736 ) ;
    else if ( chrcode == 2 ) 
    printesc ( 1508 ) ;
    else printesc ( 737 ) ;
    break ;
  case 95 : 
    if ( chrcode == 1 ) 
    printesc ( 738 ) ;
    else if ( chrcode == 3 ) 
    printesc ( 739 ) ;
    else printesc ( 740 ) ;
    break ;
  case 77 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 741 ) ;
      break ;
    case 1 : 
      printesc ( 742 ) ;
      break ;
    case 2 : 
      printesc ( 743 ) ;
      break ;
    case 5 : 
      printesc ( 744 ) ;
      break ;
    case 3 : 
      printesc ( 1456 ) ;
      break ;
    case 4 : 
      printesc ( 1457 ) ;
      break ;
    case 10 : 
      printesc ( 1458 ) ;
      break ;
    case 7 : 
      printesc ( 1459 ) ;
      break ;
    case 8 : 
      printesc ( 1460 ) ;
      break ;
    case 9 : 
      printesc ( 1461 ) ;
      break ;
    case 11 : 
      printesc ( 1487 ) ;
      break ;
    case 12 : 
      printesc ( 1488 ) ;
      break ;
    case 13 : 
      printesc ( 1489 ) ;
      break ;
    case 14 : 
      printesc ( 1490 ) ;
      break ;
    case 15 : 
      printesc ( 1491 ) ;
      break ;
    case 18 : 
      printesc ( 1492 ) ;
      break ;
    case 19 : 
      printesc ( 1493 ) ;
      break ;
    case 20 : 
      printesc ( 1494 ) ;
      break ;
    case 21 : 
      printesc ( 1495 ) ;
      break ;
    case 22 : 
      printesc ( 1496 ) ;
      break ;
    case 23 : 
      printesc ( 1497 ) ;
      break ;
    case 24 : 
      printesc ( 1498 ) ;
      break ;
    case 29 : 
      printesc ( 1536 ) ;
      break ;
    case 30 : 
      printesc ( 1537 ) ;
      break ;
    case 31 : 
      printesc ( 1538 ) ;
      break ;
    case 32 : 
      printesc ( 1539 ) ;
      break ;
    case 16 : 
      printesc ( 1543 ) ;
      break ;
    case 17 : 
      printesc ( 1544 ) ;
      break ;
    case 25 : 
      printesc ( 1545 ) ;
      break ;
    case 26 : 
      printesc ( 1546 ) ;
      break ;
    case 27 : 
      printesc ( 1547 ) ;
      break ;
    case 28 : 
      printesc ( 1548 ) ;
      break ;
      default: 
      printesc ( 745 ) ;
      break ;
    } 
    break ;
  case 124 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 806 ) ;
      break ;
    case 1 : 
      printesc ( 807 ) ;
      break ;
    case 3 : 
      printesc ( 808 ) ;
      break ;
    case 4 : 
      printesc ( 809 ) ;
      break ;
    case 5 : 
      printesc ( 810 ) ;
      break ;
    case 2 : 
      printesc ( 811 ) ;
      break ;
    case 6 : 
      printesc ( 812 ) ;
      break ;
    case 7 : 
      printesc ( 813 ) ;
      break ;
    case 8 : 
      printesc ( 814 ) ;
      break ;
    case 9 : 
      printesc ( 815 ) ;
      break ;
    case 10 : 
      printesc ( 816 ) ;
      break ;
    case 11 : 
      printesc ( 818 ) ;
      break ;
    case 12 : 
      printesc ( 819 ) ;
      break ;
    case 13 : 
      printesc ( 820 ) ;
      break ;
    case 14 : 
      printesc ( 821 ) ;
      break ;
    case 15 : 
      printesc ( 822 ) ;
      break ;
    case 16 : 
      printesc ( 823 ) ;
      break ;
    case 17 : 
      printesc ( 824 ) ;
      break ;
      default: 
      printesc ( 817 ) ;
      break ;
    } 
    break ;
  case 121 : 
    {
      if ( chrcode >= 32 ) 
      printesc ( 871 ) ;
      switch ( chrcode % 32 ) 
      {case 1 : 
	printesc ( 848 ) ;
	break ;
      case 2 : 
	printesc ( 849 ) ;
	break ;
      case 3 : 
	printesc ( 850 ) ;
	break ;
      case 4 : 
	printesc ( 851 ) ;
	break ;
      case 5 : 
	printesc ( 852 ) ;
	break ;
      case 6 : 
	printesc ( 853 ) ;
	break ;
      case 7 : 
	printesc ( 854 ) ;
	break ;
      case 8 : 
	printesc ( 855 ) ;
	break ;
      case 9 : 
	printesc ( 856 ) ;
	break ;
      case 10 : 
	printesc ( 857 ) ;
	break ;
      case 11 : 
	printesc ( 858 ) ;
	break ;
      case 12 : 
	printesc ( 859 ) ;
	break ;
      case 13 : 
	printesc ( 860 ) ;
	break ;
      case 14 : 
	printesc ( 861 ) ;
	break ;
      case 15 : 
	printesc ( 862 ) ;
	break ;
      case 16 : 
	printesc ( 863 ) ;
	break ;
      case 20 : 
	printesc ( 864 ) ;
	break ;
      case 21 : 
	printesc ( 865 ) ;
	break ;
      case 22 : 
	printesc ( 866 ) ;
	break ;
      case 23 : 
	printesc ( 867 ) ;
	break ;
      case 24 : 
	printesc ( 868 ) ;
	break ;
      case 25 : 
	printesc ( 869 ) ;
	break ;
      case 26 : 
	printesc ( 870 ) ;
	break ;
      case 27 : 
	printesc ( 872 ) ;
	break ;
      case 17 : 
	printesc ( 1528 ) ;
	break ;
      case 18 : 
	printesc ( 1529 ) ;
	break ;
      case 19 : 
	printesc ( 1530 ) ;
	break ;
	default: 
	printesc ( 847 ) ;
	break ;
      } 
    } 
    break ;
  case 122 : 
    if ( chrcode == 2 ) 
    printesc ( 316 ) ;
    else if ( chrcode == 4 ) 
    printesc ( 873 ) ;
    else printesc ( 874 ) ;
    break ;
  case 4 : 
    if ( chrcode == 256 ) 
    printesc ( 999 ) ;
    else {
	
      print ( 1003 ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 5 : 
    if ( chrcode == 257 ) 
    printesc ( 1000 ) ;
    else printesc ( 1001 ) ;
    break ;
  case 93 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 1071 ) ;
      break ;
    case 1 : 
      printesc ( 1072 ) ;
      break ;
    case 2 : 
      printesc ( 1073 ) ;
      break ;
    case 3 : 
      printesc ( 1074 ) ;
      break ;
    case 4 : 
      printesc ( 1075 ) ;
      break ;
    case 5 : 
      printesc ( 1076 ) ;
      break ;
    case 6 : 
      printesc ( 1077 ) ;
      break ;
    case 7 : 
      printesc ( 1078 ) ;
      break ;
      default: 
      printesc ( 1079 ) ;
      break ;
    } 
    break ;
  case 14 : 
    if ( chrcode == 1 ) 
    printesc ( 1129 ) ;
    else printesc ( 349 ) ;
    break ;
  case 30 : 
    switch ( chrcode ) 
    {case 5 : 
      printesc ( 1130 ) ;
      break ;
    case 0 : 
      printesc ( 1131 ) ;
      break ;
    case 1 : 
      printesc ( 1132 ) ;
      break ;
    case 2 : 
      printesc ( 1133 ) ;
      break ;
    case 3 : 
      printesc ( 1134 ) ;
      break ;
      default: 
      printesc ( 1135 ) ;
      break ;
    } 
    break ;
  case 31 : 
    switch ( chrcode ) 
    {case 5 : 
      printesc ( 1136 ) ;
      break ;
    case 0 : 
      printesc ( 1137 ) ;
      break ;
    case 1 : 
      printesc ( 1138 ) ;
      break ;
    case 2 : 
      printesc ( 1139 ) ;
      break ;
    case 3 : 
      printesc ( 1140 ) ;
      break ;
      default: 
      printesc ( 1141 ) ;
      break ;
    } 
    break ;
  case 32 : 
    printesc ( 342 ) ;
    break ;
  case 33 : 
    printesc ( 346 ) ;
    break ;
  case 34 : 
    printesc ( 348 ) ;
    break ;
  case 25 : 
    if ( chrcode == 1 ) 
    printesc ( 1159 ) ;
    else printesc ( 1160 ) ;
    break ;
  case 26 : 
    if ( chrcode == 1 ) 
    printesc ( 1161 ) ;
    else printesc ( 1162 ) ;
    break ;
  case 24 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 431 ) ;
      break ;
    case 1 : 
      printesc ( 1163 ) ;
      break ;
    case 2 : 
      printesc ( 1164 ) ;
      break ;
    case 3 : 
      printesc ( 1066 ) ;
      break ;
    case 4 : 
      printesc ( 1165 ) ;
      break ;
    case 5 : 
      printesc ( 1068 ) ;
      break ;
      default: 
      printesc ( 1166 ) ;
      break ;
    } 
    break ;
  case 79 : 
    switch ( chrcode ) 
    {case 4 : 
      printesc ( 1168 ) ;
      break ;
    case 3 : 
      printesc ( 1167 ) ;
      break ;
    case 1 : 
      printesc ( 1169 ) ;
      break ;
    } 
    break ;
  case 35 : 
    if ( chrcode == 100 ) 
    printesc ( 1171 ) ;
    else if ( chrcode == 101 ) 
    printesc ( 1172 ) ;
    else if ( chrcode == 102 ) 
    printesc ( 1173 ) ;
    else printesc ( 1170 ) ;
    break ;
  case 47 : 
    if ( chrcode == 0 ) 
    printesc ( 1201 ) ;
    else printesc ( 1200 ) ;
    break ;
  case 29 : 
    if ( chrcode == 12 ) 
    printesc ( 1214 ) ;
    else if ( chrcode == 13 ) 
    printesc ( 1213 ) ;
    else printesc ( 1212 ) ;
    break ;
  case 27 : 
    if ( chrcode == 1 ) 
    printesc ( 1216 ) ;
    else printesc ( 1215 ) ;
    break ;
  case 28 : 
    if ( chrcode == 1 ) 
    printesc ( 1218 ) ;
    else if ( chrcode == 2 ) 
    printesc ( 1558 ) ;
    else if ( chrcode == 3 ) 
    printesc ( 1559 ) ;
    else printesc ( 1217 ) ;
    break ;
  case 51 : 
    if ( chrcode == 1 ) 
    printesc ( 45 ) ;
    else printesc ( 359 ) ;
    break ;
  case 52 : 
    if ( chrcode == 1 ) 
    printesc ( 1252 ) ;
    else printesc ( 1251 ) ;
    break ;
  case 55 : 
    switch ( chrcode ) 
    {case 18 : 
      printesc ( 965 ) ;
      break ;
    case 19 : 
      printesc ( 966 ) ;
      break ;
    case 20 : 
      printesc ( 967 ) ;
      break ;
    case 21 : 
      printesc ( 968 ) ;
      break ;
    case 22 : 
      printesc ( 969 ) ;
      break ;
    case 23 : 
      printesc ( 970 ) ;
      break ;
    case 24 : 
      printesc ( 971 ) ;
      break ;
    case 25 : 
      printesc ( 972 ) ;
      break ;
    case 28 : 
      printesc ( 974 ) ;
      break ;
      default: 
      printesc ( 973 ) ;
      break ;
    } 
    break ;
  case 56 : 
    if ( chrcode == 1 ) 
    printesc ( 978 ) ;
    else if ( chrcode == 2 ) 
    printesc ( 979 ) ;
    else printesc ( 1256 ) ;
    break ;
  case 58 : 
    printstyle ( chrcode ) ;
    break ;
  case 57 : 
    switch ( chrcode ) 
    {case 1 : 
      printesc ( 1275 ) ;
      break ;
    case 2 : 
      printesc ( 1276 ) ;
      break ;
    case 3 : 
      printesc ( 1277 ) ;
      break ;
    case 4 : 
      printesc ( 1278 ) ;
      break ;
    case 5 : 
      printesc ( 1279 ) ;
      break ;
      default: 
      printesc ( 1274 ) ;
      break ;
    } 
    break ;
  case 53 : 
    if ( chrcode == 32 ) 
    printesc ( 975 ) ;
    else if ( chrcode == 1 ) 
    printesc ( 977 ) ;
    else printesc ( 976 ) ;
    break ;
  case 107 : 
    if ( chrcode == 1 ) 
    printesc ( 1299 ) ;
    else if ( chrcode == 2 ) 
    printesc ( 1300 ) ;
    else if ( chrcode == 8 ) 
    printesc ( 1313 ) ;
    else printesc ( 1301 ) ;
    break ;
  case 111 : 
    if ( chrcode == 0 ) 
    printesc ( 1302 ) ;
    else if ( chrcode == 1 ) 
    printesc ( 1303 ) ;
    else if ( chrcode == 2 ) 
    printesc ( 1304 ) ;
    else printesc ( 1305 ) ;
    break ;
  case 108 : 
    if ( chrcode != 0 ) 
    printesc ( 1323 ) ;
    else printesc ( 1322 ) ;
    break ;
  case 109 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 1324 ) ;
      break ;
    case 9 : 
      printesc ( 1325 ) ;
      break ;
    case 1 : 
      printesc ( 1326 ) ;
      break ;
    case 2 : 
      printesc ( 1327 ) ;
      break ;
    case 3 : 
      printesc ( 1328 ) ;
      break ;
    case 4 : 
      printesc ( 1329 ) ;
      break ;
    case 5 : 
      printesc ( 1330 ) ;
      break ;
    case 6 : 
      printesc ( 1331 ) ;
      break ;
    case 8 : 
      printesc ( 1333 ) ;
      break ;
      default: 
      printesc ( 1332 ) ;
      break ;
    } 
    break ;
  case 73 : 
    {
      printesc ( 555 ) ;
      printhex ( chrcode ) ;
    } 
    break ;
  case 74 : 
    {
      printesc ( 556 ) ;
      printhex ( chrcode ) ;
    } 
    break ;
  case 75 : 
    {
      printesc ( 570 ) ;
      printhex ( chrcode ) ;
    } 
    break ;
  case 76 : 
    {
      printesc ( 572 ) ;
      printhex ( chrcode ) ;
    } 
    break ;
  case 97 : 
    if ( chrcode == 26362 ) 
    printesc ( 437 ) ;
    else if ( chrcode == 26618 ) 
    printesc ( 438 ) ;
    else if ( chrcode == 27130 ) 
    printesc ( 439 ) ;
    else if ( chrcode == 28676 ) 
    printesc ( 446 ) ;
    else if ( chrcode == 28804 ) 
    printesc ( 1338 ) ;
    else if ( chrcode == 27908 ) 
    printesc ( 443 ) ;
    else if ( chrcode == 28164 ) 
    printesc ( 444 ) ;
    else if ( chrcode == 28420 ) 
    printesc ( 445 ) ;
    else if ( chrcode == 29518 ) 
    printesc ( 512 ) ;
    else printesc ( 1339 ) ;
    break ;
  case 98 : 
    printsize ( chrcode - 25589 ) ;
    break ;
  case 113 : 
    if ( chrcode == 1 ) 
    printesc ( 1054 ) ;
    else printesc ( 1042 ) ;
    break ;
  case 87 : 
    if ( chrcode == 0 ) 
    printesc ( 1358 ) ;
    else printesc ( 1359 ) ;
    break ;
  case 99 : 
    {
      print ( 1367 ) ;
      slowprint ( fontname [chrcode ]) ;
      if ( fontsize [chrcode ]!= fontdsize [chrcode ]) 
      {
	print ( 832 ) ;
	printscaled ( fontsize [chrcode ]) ;
	print ( 419 ) ;
      } 
    } 
    break ;
  case 114 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 274 ) ;
      break ;
    case 1 : 
      printesc ( 275 ) ;
      break ;
    case 2 : 
      printesc ( 276 ) ;
      break ;
      default: 
      printesc ( 1368 ) ;
      break ;
    } 
    break ;
  case 65 : 
    if ( chrcode == 0 ) 
    printesc ( 1370 ) ;
    else printesc ( 1369 ) ;
    break ;
  case 63 : 
    if ( chrcode == 0 ) 
    printesc ( 1371 ) ;
    else printesc ( 1372 ) ;
    break ;
  case 62 : 
    if ( chrcode == 27908 ) 
    printesc ( 1378 ) ;
    else printesc ( 1379 ) ;
    break ;
  case 23 : 
    switch ( chrcode ) 
    {case 1 : 
      printesc ( 1381 ) ;
      break ;
    case 2 : 
      printesc ( 1382 ) ;
      break ;
    case 3 : 
      printesc ( 1383 ) ;
      break ;
    case 4 : 
      printesc ( 1499 ) ;
      break ;
    case 5 : 
      printesc ( 1501 ) ;
      break ;
    case 6 : 
      printesc ( 1504 ) ;
      break ;
    case 7 : 
      printesc ( 1384 ) ;
      break ;
      default: 
      printesc ( 1380 ) ;
      break ;
    } 
    break ;
  case 117 : 
    print ( 1391 ) ;
    break ;
  case 127 : 
  case 128 : 
  case 129 : 
  case 130 : 
    {
      n = cmd - 127 ;
      if ( mem [mem [chrcode ].hh .v.RH ].hh .v.LH == 3585 ) 
      n = n + 4 ;
      if ( odd ( n / 4 ) ) 
      printesc ( 1313 ) ;
      if ( odd ( n ) ) 
      printesc ( 1299 ) ;
      if ( odd ( n / 2 ) ) 
      printesc ( 1300 ) ;
      if ( n > 0 ) 
      printchar ( 32 ) ;
      print ( 1392 ) ;
    } 
    break ;
  case 131 : 
    printesc ( 1393 ) ;
    break ;
  case 64 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 1428 ) ;
      break ;
    case 1 : 
      printesc ( 649 ) ;
      break ;
    case 2 : 
      printesc ( 1429 ) ;
      break ;
    case 3 : 
      printesc ( 1430 ) ;
      break ;
    case 4 : 
      printesc ( 1431 ) ;
      break ;
    case 5 : 
      printesc ( 1432 ) ;
      break ;
    case 6 : 
      printesc ( 1434 ) ;
      break ;
    case 7 : 
      printesc ( 1433 ) ;
      break ;
      default: 
      print ( 1435 ) ;
      break ;
    } 
    break ;
  case 90 : 
    printesc ( 442 ) ;
    break ;
  case 115 : 
    {
      if ( ( chrcode % 2 ) == 0 ) 
      printesc ( 1578 ) ;
      else printesc ( 1579 ) ;
      if ( chrcode < 2 ) 
      print ( 1580 ) ;
      else print ( 1581 ) ;
    } 
    break ;
  case 116 : 
    {
      if ( chrcode == 0 ) 
      printesc ( 1582 ) ;
      else if ( chrcode == 1 ) 
      printesc ( 1583 ) ;
      else printesc ( 1584 ) ;
      print ( 1585 ) ;
    } 
    break ;
  case 78 : 
    printesc ( 1590 ) ;
    break ;
  case 89 : 
    printesc ( 1591 ) ;
    break ;
  case 88 : 
    switch ( chrcode ) 
    {case 1 : 
      printesc ( 1594 ) ;
      break ;
    case 2 : 
      printesc ( 1595 ) ;
      break ;
    } 
    break ;
    default: 
    print ( 621 ) ;
    break ;
  } 
} 
#ifdef STAT
void 
zshoweqtb ( halfword n ) 
{
  showeqtb_regmem 
  if ( n < 1 ) 
  printchar ( 63 ) ;
  else if ( ( n < 24528 ) || ( ( n > 30310 ) && ( n <= eqtbtop ) ) ) 
  {
    sprintcs ( n ) ;
    printchar ( 61 ) ;
    printcmdchr ( eqtb [n ].hh.b0 , eqtb [n ].hh .v.RH ) ;
    if ( eqtb [n ].hh.b0 >= 127 ) 
    {
      printchar ( 58 ) ;
      showtokenlist ( mem [eqtb [n ].hh .v.RH ].hh .v.RH , -1073741823L , 
      32 ) ;
    } 
  } 
  else if ( n < 25061 ) {
      
    if ( n < 24549 ) 
    {
      printskipparam ( n - 24528 ) ;
      printchar ( 61 ) ;
      if ( n < 24545 ) 
      printspec ( eqtb [n ].hh .v.RH , 419 ) ;
      else printspec ( eqtb [n ].hh .v.RH , 343 ) ;
    } 
    else if ( n < 24805 ) 
    {
      printesc ( 417 ) ;
      printint ( n - 24549 ) ;
      printchar ( 61 ) ;
      printspec ( eqtb [n ].hh .v.RH , 419 ) ;
    } 
    else {
	
      printesc ( 418 ) ;
      printint ( n - 24805 ) ;
      printchar ( 61 ) ;
      printspec ( eqtb [n ].hh .v.RH , 343 ) ;
    } 
  } 
  else if ( n < 29188 ) {
      
    if ( ( n == 25061 ) || ( ( n >= 25328 ) && ( n < 25332 ) ) ) 
    {
      printcmdchr ( 96 , n ) ;
      printchar ( 61 ) ;
      if ( eqtb [n ].hh .v.RH == -1073741823L ) 
      printchar ( 48 ) ;
      else if ( n > 25061 ) 
      {
	printint ( mem [eqtb [n ].hh .v.RH + 1 ].cint ) ;
	printchar ( 32 ) ;
	printint ( mem [eqtb [n ].hh .v.RH + 2 ].cint ) ;
	if ( mem [eqtb [n ].hh .v.RH + 1 ].cint > 1 ) 
	printesc ( 430 ) ;
      } 
      else printint ( mem [eqtb [25061 ].hh .v.RH ].hh .v.LH ) ;
    } 
    else if ( n < 25072 ) 
    {
      printcmdchr ( 81 , n ) ;
      printchar ( 61 ) ;
      if ( eqtb [n ].hh .v.RH != -1073741823L ) 
      showtokenlist ( mem [eqtb [n ].hh .v.RH ].hh .v.RH , -1073741823L , 
      32 ) ;
    } 
    else if ( n < 25332 ) 
    {
      printesc ( 429 ) ;
      printint ( n - 25072 ) ;
      printchar ( 61 ) ;
      if ( eqtb [n ].hh .v.RH != -1073741823L ) 
      showtokenlist ( mem [eqtb [n ].hh .v.RH ].hh .v.RH , -1073741823L , 
      32 ) ;
    } 
    else if ( n < 25588 ) 
    {
      printesc ( 431 ) ;
      printint ( n - 25332 ) ;
      printchar ( 61 ) ;
      if ( eqtb [n ].hh .v.RH == -1073741823L ) 
      print ( 432 ) ;
      else {
	  
	depththreshold = 0 ;
	breadthmax = 1 ;
	shownodelist ( eqtb [n ].hh .v.RH ) ;
      } 
    } 
    else if ( n < 26362 ) 
    {
      if ( n == 25588 ) 
      print ( 433 ) ;
      else if ( n < 25845 ) 
      {
	printesc ( 434 ) ;
	printint ( n - 25589 ) ;
      } 
      else if ( n < 26101 ) 
      {
	printesc ( 435 ) ;
	printint ( n - 25845 ) ;
      } 
      else {
	  
	printesc ( 436 ) ;
	printint ( n - 26101 ) ;
      } 
      printchar ( 61 ) ;
      printesc ( hash [15526 + eqtb [n ].hh .v.RH ].v.RH ) ;
    } 
    else if ( n < 28676 ) 
    {
      if ( n < 26618 ) 
      {
	printesc ( 437 ) ;
	printint ( n - 26362 ) ;
      } 
      else if ( n < 27130 ) 
      {
	printesc ( 438 ) ;
	printint ( n - 26618 ) ;
      } 
      else if ( n < 27386 ) 
      {
	printesc ( 439 ) ;
	printint ( n - 27130 ) ;
      } 
      else if ( n < 27642 ) 
      {
	print ( 440 ) ;
	printint ( n - 27386 ) ;
      } 
      else if ( n < 27898 ) 
      {
	print ( 441 ) ;
	printint ( n - 27642 ) ;
      } 
      else if ( n < 27908 ) 
      {
	printesc ( 442 ) ;
	printint ( n - 27898 ) ;
      } 
      else if ( n < 28164 ) 
      {
	printesc ( 443 ) ;
	printint ( n - 27908 ) ;
      } 
      else if ( n < 28420 ) 
      {
	printesc ( 444 ) ;
	printint ( n - 28164 ) ;
      } 
      else {
	  
	printesc ( 445 ) ;
	printint ( n - 28420 ) ;
      } 
      printchar ( 61 ) ;
      printint ( eqtb [n ].hh .v.RH ) ;
    } 
    else {
	
      printesc ( 446 ) ;
      printint ( n - 28676 ) ;
      printchar ( 61 ) ;
      printint ( eqtb [n ].hh .v.RH ) ;
    } 
  } 
  else if ( n < 29774 ) 
  {
    if ( n < 29262 ) 
    printparam ( n - 29188 ) ;
    else if ( n < 29518 ) 
    {
      printesc ( 511 ) ;
      printint ( n - 29262 ) ;
    } 
    else {
	
      printesc ( 512 ) ;
      printint ( n - 29518 ) ;
    } 
    printchar ( 61 ) ;
    printint ( eqtb [n ].cint ) ;
  } 
  else if ( n < 30055 ) 
  {
    if ( n < 29799 ) 
    printlengthparam ( n - 29774 ) ;
    else {
	
      printesc ( 539 ) ;
      printint ( n - 29799 ) ;
    } 
    printchar ( 61 ) ;
    printscaled ( eqtb [n ].cint ) ;
    print ( 419 ) ;
  } 
  else if ( n <= 30310 ) 
  print ( 540 ) ;
  else printchar ( 63 ) ;
} 
#endif /* STAT */
halfword 
zidlookup ( integer j , integer l ) 
{
  /* 40 */ register halfword Result; idlookup_regmem 
  integer h  ;
  integer d  ;
  halfword p  ;
  halfword k  ;
  h = buffer [j ];
  {register integer for_end; k = j + 1 ;for_end = j + l - 1 ; if ( k <= 
  for_end) do 
    {
      h = h + h + buffer [k ];
      while ( h >= 8501 ) h = h - 8501 ;
    } 
  while ( k++ < for_end ) ;} 
  p = h + 514 ;
  while ( true ) {
      
    if ( hash [p ].v.RH > 0 ) {
	
      if ( ( strstart [hash [p ].v.RH + 1 ]- strstart [hash [p ].v.RH ]
      ) == l ) {
	  
	if ( streqbuf ( hash [p ].v.RH , j ) ) 
	goto lab40 ;
      } 
    } 
    if ( hash [p ].v.LH == 0 ) 
    {
      if ( nonewcontrolsequence ) 
      p = 24527 ;
      else {
	  
	if ( hash [p ].v.RH > 0 ) 
	{
	  if ( hashhigh < hashextra ) 
	  {
	    incr ( hashhigh ) ;
	    hash [p ].v.LH = hashhigh + 30310 ;
	    p = hashhigh + 30310 ;
	  } 
	  else {
	      
	    do {
		if ( ( hashused == 514 ) ) 
	      overflow ( 544 , 15000 + hashextra ) ;
	      decr ( hashused ) ;
	    } while ( ! ( hash [hashused ].v.RH == 0 ) ) ;
	    hash [p ].v.LH = hashused ;
	    p = hashused ;
	  } 
	} 
	{
	  if ( poolptr + l > poolsize ) 
	  overflow ( 259 , poolsize - initpoolptr ) ;
	} 
	d = ( poolptr - strstart [strptr ]) ;
	while ( poolptr > strstart [strptr ]) {
	    
	  decr ( poolptr ) ;
	  strpool [poolptr + l ]= strpool [poolptr ];
	} 
	{register integer for_end; k = j ;for_end = j + l - 1 ; if ( k <= 
	for_end) do 
	  {
	    strpool [poolptr ]= buffer [k ];
	    incr ( poolptr ) ;
	  } 
	while ( k++ < for_end ) ;} 
	hash [p ].v.RH = makestring () ;
	poolptr = poolptr + d ;
	;
#ifdef STAT
	incr ( cscount ) ;
#endif /* STAT */
      } 
      goto lab40 ;
    } 
    p = hash [p ].v.LH ;
  } 
  lab40: Result = p ;
  return Result ;
} 
halfword 
zprimlookup ( strnumber s ) 
{
  /* 40 */ register halfword Result; primlookup_regmem 
  integer h  ;
  halfword p  ;
  halfword k  ;
  integer j, l  ;
  if ( s < 256 ) 
  {
    p = s ;
    if ( ( p < 0 ) || ( primeqtb [p ].hh.b1 != 1 ) ) 
    p = 0 ;
  } 
  else {
      
    j = strstart [s ];
    if ( s == strptr ) 
    l = ( poolptr - strstart [strptr ]) ;
    else l = ( strstart [s + 1 ]- strstart [s ]) ;
    h = strpool [j ];
    {register integer for_end; k = j + 1 ;for_end = j + l - 1 ; if ( k <= 
    for_end) do 
      {
	h = h + h + strpool [k ];
	while ( h >= 1777 ) h = h - 1777 ;
      } 
    while ( k++ < for_end ) ;} 
    p = h + 1 ;
    while ( true ) {
	
      if ( prim [p ].v.RH > 0 ) {
	  
	if ( ( strstart [prim [p ].v.RH + 1 ]- strstart [prim [p ].v.RH 
	]) == l ) {
	    
	  if ( streqstr ( prim [p ].v.RH , s ) ) 
	  goto lab40 ;
	} 
      } 
      if ( prim [p ].v.LH == 0 ) 
      {
	if ( nonewcontrolsequence ) 
	p = 0 ;
	else {
	    
	  if ( prim [p ].v.RH > 0 ) 
	  {
	    do {
		if ( ( primused == 1 ) ) 
	      overflow ( 545 , 2100 ) ;
	      decr ( primused ) ;
	    } while ( ! ( prim [primused ].v.RH == 0 ) ) ;
	    prim [p ].v.LH = primused ;
	    p = primused ;
	  } 
	  prim [p ].v.RH = s ;
	} 
	goto lab40 ;
      } 
      p = prim [p ].v.LH ;
    } 
  } 
  lab40: Result = p ;
  return Result ;
} 
#ifdef STAT
void 
zrestoretrace ( halfword p , strnumber s ) 
{
  restoretrace_regmem 
  begindiagnostic () ;
  printchar ( 123 ) ;
  print ( s ) ;
  printchar ( 32 ) ;
  showeqtb ( p ) ;
  printchar ( 125 ) ;
  enddiagnostic ( false ) ;
} 
#endif /* STAT */
void 
zprintgroup ( boolean e ) 
{
  /* 10 */ printgroup_regmem 
  switch ( curgroup ) 
  {case 0 : 
    {
      print ( 1473 ) ;
      return ;
    } 
    break ;
  case 1 : 
  case 14 : 
    {
      if ( curgroup == 14 ) 
      print ( 1474 ) ;
      print ( 1475 ) ;
    } 
    break ;
  case 2 : 
  case 3 : 
    {
      if ( curgroup == 3 ) 
      print ( 1476 ) ;
      print ( 1166 ) ;
    } 
    break ;
  case 4 : 
    print ( 1068 ) ;
    break ;
  case 5 : 
    print ( 1165 ) ;
    break ;
  case 6 : 
  case 7 : 
    {
      if ( curgroup == 7 ) 
      print ( 1477 ) ;
      print ( 1478 ) ;
    } 
    break ;
  case 8 : 
    print ( 420 ) ;
    break ;
  case 10 : 
    print ( 1479 ) ;
    break ;
  case 11 : 
    print ( 336 ) ;
    break ;
  case 12 : 
    print ( 589 ) ;
    break ;
  case 9 : 
  case 13 : 
  case 15 : 
  case 16 : 
    {
      print ( 351 ) ;
      if ( curgroup == 13 ) 
      print ( 1480 ) ;
      else if ( curgroup == 15 ) 
      print ( 1481 ) ;
      else if ( curgroup == 16 ) 
      print ( 1482 ) ;
    } 
    break ;
  } 
  print ( 1483 ) ;
  printint ( curlevel ) ;
  printchar ( 41 ) ;
  if ( savestack [saveptr - 1 ].cint != 0 ) 
  {
    if ( e ) 
    print ( 382 ) ;
    else print ( 1484 ) ;
    printint ( savestack [saveptr - 1 ].cint ) ;
  } 
} 
#ifdef STAT
void 
zgrouptrace ( boolean e ) 
{
  grouptrace_regmem 
  begindiagnostic () ;
  printchar ( 123 ) ;
  if ( e ) 
  print ( 1485 ) ;
  else print ( 1486 ) ;
  printgroup ( e ) ;
  printchar ( 125 ) ;
  enddiagnostic ( false ) ;
} 
#endif /* STAT */
boolean 
pseudoinput ( void ) 
{
  register boolean Result; pseudoinput_regmem 
  halfword p  ;
  integer sz  ;
  fourquarters w  ;
  halfword r  ;
  last = first ;
  p = mem [pseudofiles ].hh .v.LH ;
  if ( p == -1073741823L ) 
  Result = false ;
  else {
      
    mem [pseudofiles ].hh .v.LH = mem [p ].hh .v.RH ;
    sz = mem [p ].hh .v.LH ;
    if ( 4 * sz - 3 >= bufsize - last ) 
    {
      curinput .locfield = first ;
      curinput .limitfield = last - 1 ;
      overflow ( 258 , bufsize ) ;
    } 
    last = first ;
    {register integer for_end; r = p + 1 ;for_end = p + sz - 1 ; if ( r <= 
    for_end) do 
      {
	w = mem [r ].qqqq ;
	buffer [last ]= w .b0 ;
	buffer [last + 1 ]= w .b1 ;
	buffer [last + 2 ]= w .b2 ;
	buffer [last + 3 ]= w .b3 ;
	last = last + 4 ;
      } 
    while ( r++ < for_end ) ;} 
    if ( last >= maxbufstack ) 
    maxbufstack = last + 1 ;
    while ( ( last > first ) && ( buffer [last - 1 ]== 32 ) ) decr ( last ) 
    ;
    freenode ( p , sz ) ;
    Result = true ;
  } 
  return Result ;
} 
void 
pseudoclose ( void ) 
{
  pseudoclose_regmem 
  halfword p, q  ;
  p = mem [pseudofiles ].hh .v.RH ;
  q = mem [pseudofiles ].hh .v.LH ;
  {
    mem [pseudofiles ].hh .v.RH = avail ;
    avail = pseudofiles ;
	;
#ifdef STAT
    decr ( dynused ) ;
#endif /* STAT */
  } 
  pseudofiles = p ;
  while ( q != -1073741823L ) {
      
    p = q ;
    q = mem [p ].hh .v.RH ;
    freenode ( p , mem [p ].hh .v.LH ) ;
  } 
} 
void 
groupwarning ( void ) 
{
  groupwarning_regmem 
  integer i  ;
  boolean w  ;
  baseptr = inputptr ;
  inputstack [baseptr ]= curinput ;
  i = inopen ;
  w = false ;
  while ( ( grpstack [i ]== curboundary ) && ( i > 0 ) ) {
      
    if ( eqtb [29256 ].cint > 0 ) 
    {
      while ( ( inputstack [baseptr ].statefield == 0 ) || ( inputstack [
      baseptr ].indexfield > i ) ) decr ( baseptr ) ;
      if ( inputstack [baseptr ].namefield > 17 ) 
      w = true ;
    } 
    grpstack [i ]= savestack [saveptr ].hh .v.RH ;
    decr ( i ) ;
  } 
  if ( w ) 
  {
    printnl ( 1532 ) ;
    printgroup ( true ) ;
    print ( 1533 ) ;
    println () ;
    if ( eqtb [29256 ].cint > 1 ) 
    showcontext () ;
    if ( history == 0 ) 
    history = 1 ;
  } 
} 
void 
ifwarning ( void ) 
{
  ifwarning_regmem 
  integer i  ;
  boolean w  ;
  baseptr = inputptr ;
  inputstack [baseptr ]= curinput ;
  i = inopen ;
  w = false ;
  while ( ifstack [i ]== condptr ) {
      
    if ( eqtb [29256 ].cint > 0 ) 
    {
      while ( ( inputstack [baseptr ].statefield == 0 ) || ( inputstack [
      baseptr ].indexfield > i ) ) decr ( baseptr ) ;
      if ( inputstack [baseptr ].namefield > 17 ) 
      w = true ;
    } 
    ifstack [i ]= mem [condptr ].hh .v.RH ;
    decr ( i ) ;
  } 
  if ( w ) 
  {
    printnl ( 1532 ) ;
    printcmdchr ( 121 , curif ) ;
    if ( ifline != 0 ) 
    {
      print ( 1505 ) ;
      printint ( ifline ) ;
    } 
    print ( 1533 ) ;
    println () ;
    if ( eqtb [29256 ].cint > 1 ) 
    showcontext () ;
    if ( history == 0 ) 
    history = 1 ;
  } 
} 
void 
filewarning ( void ) 
{
  filewarning_regmem 
  halfword p  ;
  quarterword l  ;
  quarterword c  ;
  integer i  ;
  p = saveptr ;
  l = curlevel ;
  c = curgroup ;
  saveptr = curboundary ;
  while ( grpstack [inopen ]!= saveptr ) {
      
    decr ( curlevel ) ;
    printnl ( 1534 ) ;
    printgroup ( true ) ;
    print ( 1535 ) ;
    curgroup = savestack [saveptr ].hh.b1 ;
    saveptr = savestack [saveptr ].hh .v.RH ;
  } 
  saveptr = p ;
  curlevel = l ;
  curgroup = c ;
  p = condptr ;
  l = iflimit ;
  c = curif ;
  i = ifline ;
  while ( ifstack [inopen ]!= condptr ) {
      
    printnl ( 1534 ) ;
    printcmdchr ( 121 , curif ) ;
    if ( iflimit == 2 ) 
    printesc ( 874 ) ;
    if ( ifline != 0 ) 
    {
      print ( 1505 ) ;
      printint ( ifline ) ;
    } 
    print ( 1535 ) ;
    ifline = mem [condptr + 1 ].cint ;
    curif = mem [condptr ].hh.b1 ;
    iflimit = mem [condptr ].hh.b0 ;
    condptr = mem [condptr ].hh .v.RH ;
  } 
  condptr = p ;
  iflimit = l ;
  curif = c ;
  ifline = i ;
  println () ;
  if ( eqtb [29256 ].cint > 1 ) 
  showcontext () ;
  if ( history == 0 ) 
  history = 1 ;
} 
void 
zdeletesaref ( halfword q ) 
{
  /* 10 */ deletesaref_regmem 
  halfword p  ;
  smallnumber i  ;
  smallnumber s  ;
  decr ( mem [q + 1 ].hh .v.LH ) ;
  if ( mem [q + 1 ].hh .v.LH != -1073741823L ) 
  return ;
  if ( mem [q ].hh.b0 < 32 ) {
      
    if ( mem [q + 2 ].cint == 0 ) 
    s = 3 ;
    else return ;
  } 
  else {
      
    if ( mem [q ].hh.b0 < 64 ) {
	
      if ( mem [q + 1 ].hh .v.RH == membot ) 
      deleteglueref ( membot ) ;
      else return ;
    } 
    else if ( mem [q + 1 ].hh .v.RH != -1073741823L ) 
    return ;
    s = 2 ;
  } 
  do {
      i = mem [q ].hh.b0 % 16 ;
    p = q ;
    q = mem [p ].hh .v.RH ;
    freenode ( p , s ) ;
    if ( q == -1073741823L ) 
    {
      saroot [i ]= -1073741823L ;
      return ;
    } 
    {
      if ( odd ( i ) ) 
      mem [q + ( i / 2 ) + 1 ].hh .v.RH = -1073741823L ;
      else mem [q + ( i / 2 ) + 1 ].hh .v.LH = -1073741823L ;
      decr ( mem [q ].hh.b1 ) ;
    } 
    s = 9 ;
  } while ( ! ( mem [q ].hh.b1 > 0 ) ) ;
} 
#ifdef STAT
void 
zshowsa ( halfword p , strnumber s ) 
{
  showsa_regmem 
  smallnumber t  ;
  begindiagnostic () ;
  printchar ( 123 ) ;
  print ( s ) ;
  printchar ( 32 ) ;
  if ( p == -1073741823L ) 
  printchar ( 63 ) ;
  else {
      
    t = ( mem [p ].hh.b0 / 16 ) ;
    if ( t < 4 ) 
    printcmdchr ( 103 , p ) ;
    else if ( t == 4 ) 
    {
      printesc ( 431 ) ;
      printsanum ( p ) ;
    } 
    else if ( t == 5 ) 
    printcmdchr ( 80 , p ) ;
    else printchar ( 63 ) ;
    printchar ( 61 ) ;
    if ( t == 0 ) 
    printint ( mem [p + 2 ].cint ) ;
    else if ( t == 1 ) 
    {
      printscaled ( mem [p + 2 ].cint ) ;
      print ( 419 ) ;
    } 
    else {
	
      p = mem [p + 1 ].hh .v.RH ;
      if ( t == 2 ) 
      printspec ( p , 419 ) ;
      else if ( t == 3 ) 
      printspec ( p , 343 ) ;
      else if ( t == 4 ) {
	  
	if ( p == -1073741823L ) 
	print ( 432 ) ;
	else {
	    
	  depththreshold = 0 ;
	  breadthmax = 1 ;
	  shownodelist ( p ) ;
	} 
      } 
      else if ( t == 5 ) 
      {
	if ( p != -1073741823L ) 
	showtokenlist ( mem [p ].hh .v.RH , -1073741823L , 32 ) ;
      } 
      else printchar ( 63 ) ;
    } 
  } 
  printchar ( 125 ) ;
  enddiagnostic ( false ) ;
} 
#endif /* STAT */
void 
zsasave ( halfword p ) 
{
  sasave_regmem 
  halfword q  ;
  quarterword i  ;
  if ( curlevel != salevel ) 
  {
    if ( saveptr > maxsavestack ) 
    {
      maxsavestack = saveptr ;
      if ( maxsavestack > savesize - 7 ) 
      overflow ( 591 , savesize ) ;
    } 
    savestack [saveptr ].hh.b0 = 4 ;
    savestack [saveptr ].hh.b1 = salevel ;
    savestack [saveptr ].hh .v.RH = sachain ;
    incr ( saveptr ) ;
    sachain = -1073741823L ;
    salevel = curlevel ;
  } 
  i = mem [p ].hh.b0 ;
  if ( i < 32 ) 
  {
    if ( mem [p + 2 ].cint == 0 ) 
    {
      q = getnode ( 2 ) ;
      i = 96 ;
    } 
    else {
	
      q = getnode ( 3 ) ;
      mem [q + 2 ].cint = mem [p + 2 ].cint ;
    } 
    mem [q + 1 ].hh .v.RH = -1073741823L ;
  } 
  else {
      
    q = getnode ( 2 ) ;
    mem [q + 1 ].hh .v.RH = mem [p + 1 ].hh .v.RH ;
  } 
  mem [q + 1 ].hh .v.LH = p ;
  mem [q ].hh.b0 = i ;
  mem [q ].hh.b1 = mem [p ].hh.b1 ;
  mem [q ].hh .v.RH = sachain ;
  sachain = q ;
  incr ( mem [p + 1 ].hh .v.LH ) ;
} 
void 
zsadestroy ( halfword p ) 
{
  sadestroy_regmem 
  if ( mem [p ].hh.b0 < 64 ) 
  deleteglueref ( mem [p + 1 ].hh .v.RH ) ;
  else if ( mem [p + 1 ].hh .v.RH != -1073741823L ) {
      
    if ( mem [p ].hh.b0 < 80 ) 
    flushnodelist ( mem [p + 1 ].hh .v.RH ) ;
    else deletetokenref ( mem [p + 1 ].hh .v.RH ) ;
  } 
} 
void 
zsadef ( halfword p , halfword e ) 
{
  sadef_regmem 
  incr ( mem [p + 1 ].hh .v.LH ) ;
  if ( mem [p + 1 ].hh .v.RH == e ) 
  {
	;
#ifdef STAT
    if ( eqtb [29252 ].cint > 0 ) 
    showsa ( p , 593 ) ;
#endif /* STAT */
    sadestroy ( p ) ;
  } 
  else {
      
	;
#ifdef STAT
    if ( eqtb [29252 ].cint > 0 ) 
    showsa ( p , 594 ) ;
#endif /* STAT */
    if ( mem [p ].hh.b1 == curlevel ) 
    sadestroy ( p ) ;
    else sasave ( p ) ;
    mem [p ].hh.b1 = curlevel ;
    mem [p + 1 ].hh .v.RH = e ;
	;
#ifdef STAT
    if ( eqtb [29252 ].cint > 0 ) 
    showsa ( p , 595 ) ;
#endif /* STAT */
  } 
  deletesaref ( p ) ;
} 
void 
zsawdef ( halfword p , integer w ) 
{
  sawdef_regmem 
  incr ( mem [p + 1 ].hh .v.LH ) ;
  if ( mem [p + 2 ].cint == w ) 
  {
	;
#ifdef STAT
    if ( eqtb [29252 ].cint > 0 ) 
    showsa ( p , 593 ) ;
#endif /* STAT */
  } 
  else {
      
	;
#ifdef STAT
    if ( eqtb [29252 ].cint > 0 ) 
    showsa ( p , 594 ) ;
#endif /* STAT */
    if ( mem [p ].hh.b1 != curlevel ) 
    sasave ( p ) ;
    mem [p ].hh.b1 = curlevel ;
    mem [p + 2 ].cint = w ;
	;
#ifdef STAT
    if ( eqtb [29252 ].cint > 0 ) 
    showsa ( p , 595 ) ;
#endif /* STAT */
  } 
  deletesaref ( p ) ;
} 
void 
zgsadef ( halfword p , halfword e ) 
{
  gsadef_regmem 
  incr ( mem [p + 1 ].hh .v.LH ) ;
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  showsa ( p , 596 ) ;
#endif /* STAT */
  sadestroy ( p ) ;
  mem [p ].hh.b1 = 1 ;
  mem [p + 1 ].hh .v.RH = e ;
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  showsa ( p , 595 ) ;
#endif /* STAT */
  deletesaref ( p ) ;
} 
void 
zgsawdef ( halfword p , integer w ) 
{
  gsawdef_regmem 
  incr ( mem [p + 1 ].hh .v.LH ) ;
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  showsa ( p , 596 ) ;
#endif /* STAT */
  mem [p ].hh.b1 = 1 ;
  mem [p + 2 ].cint = w ;
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  showsa ( p , 595 ) ;
#endif /* STAT */
  deletesaref ( p ) ;
} 
void 
sarestore ( void ) 
{
  sarestore_regmem 
  halfword p  ;
  do {
      p = mem [sachain + 1 ].hh .v.LH ;
    if ( mem [p ].hh.b1 == 1 ) 
    {
      if ( mem [p ].hh.b0 >= 32 ) 
      sadestroy ( sachain ) ;
	;
#ifdef STAT
      if ( eqtb [29225 ].cint > 0 ) 
      showsa ( p , 598 ) ;
#endif /* STAT */
    } 
    else {
	
      if ( mem [p ].hh.b0 < 32 ) {
	  
	if ( mem [sachain ].hh.b0 < 32 ) 
	mem [p + 2 ].cint = mem [sachain + 2 ].cint ;
	else mem [p + 2 ].cint = 0 ;
      } 
      else {
	  
	sadestroy ( p ) ;
	mem [p + 1 ].hh .v.RH = mem [sachain + 1 ].hh .v.RH ;
      } 
      mem [p ].hh.b1 = mem [sachain ].hh.b1 ;
	;
#ifdef STAT
      if ( eqtb [29225 ].cint > 0 ) 
      showsa ( p , 599 ) ;
#endif /* STAT */
    } 
    deletesaref ( p ) ;
    p = sachain ;
    sachain = mem [p ].hh .v.RH ;
    if ( mem [p ].hh.b0 < 32 ) 
    freenode ( p , 3 ) ;
    else freenode ( p , 2 ) ;
  } while ( ! ( sachain == -1073741823L ) ) ;
} 
void 
znewsavelevel ( groupcode c ) 
{
  newsavelevel_regmem 
  if ( saveptr > maxsavestack ) 
  {
    maxsavestack = saveptr ;
    if ( maxsavestack > savesize - 7 ) 
    overflow ( 591 , savesize ) ;
  } 
  if ( ( eTeXmode == 1 ) ) 
  {
    savestack [saveptr + 0 ].cint = line ;
    incr ( saveptr ) ;
  } 
  savestack [saveptr ].hh.b0 = 3 ;
  savestack [saveptr ].hh.b1 = curgroup ;
  savestack [saveptr ].hh .v.RH = curboundary ;
  if ( curlevel == 65535L ) 
  overflow ( 592 , 65535L ) ;
  curboundary = saveptr ;
  curgroup = c ;
	;
#ifdef STAT
  if ( eqtb [29253 ].cint > 0 ) 
  grouptrace ( false ) ;
#endif /* STAT */
  incr ( curlevel ) ;
  incr ( saveptr ) ;
} 
void 
zeqdestroy ( memoryword w ) 
{
  eqdestroy_regmem 
  halfword q  ;
  switch ( w .hh.b0 ) 
  {case 127 : 
  case 128 : 
  case 129 : 
  case 130 : 
    deletetokenref ( w .hh .v.RH ) ;
    break ;
  case 133 : 
    deleteglueref ( w .hh .v.RH ) ;
    break ;
  case 134 : 
    {
      q = w .hh .v.RH ;
      if ( q != -1073741823L ) 
      freenode ( q , mem [q ].hh .v.LH + mem [q ].hh .v.LH + 1 ) ;
    } 
    break ;
  case 135 : 
    flushnodelist ( w .hh .v.RH ) ;
    break ;
  case 80 : 
  case 103 : 
    if ( ( w .hh .v.RH < membot ) || ( w .hh .v.RH > membot + 23 ) ) 
    deletesaref ( w .hh .v.RH ) ;
    break ;
    default: 
    ;
    break ;
  } 
} 
void 
zeqsave ( halfword p , quarterword l ) 
{
  eqsave_regmem 
  if ( saveptr > maxsavestack ) 
  {
    maxsavestack = saveptr ;
    if ( maxsavestack > savesize - 7 ) 
    overflow ( 591 , savesize ) ;
  } 
  if ( l == 0 ) 
  savestack [saveptr ].hh.b0 = 1 ;
  else {
      
    savestack [saveptr ]= eqtb [p ];
    incr ( saveptr ) ;
    savestack [saveptr ].hh.b0 = 0 ;
  } 
  savestack [saveptr ].hh.b1 = l ;
  savestack [saveptr ].hh .v.RH = p ;
  incr ( saveptr ) ;
} 
void 
zeqdefine ( halfword p , quarterword t , halfword e ) 
{
  /* 10 */ eqdefine_regmem 
  if ( ( eTeXmode == 1 ) && ( eqtb [p ].hh.b0 == t ) && ( eqtb [p ].hh 
  .v.RH == e ) ) 
  {
	;
#ifdef STAT
    if ( eqtb [29252 ].cint > 0 ) 
    restoretrace ( p , 593 ) ;
#endif /* STAT */
    eqdestroy ( eqtb [p ]) ;
    return ;
  } 
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 594 ) ;
#endif /* STAT */
  if ( eqtb [p ].hh.b1 == curlevel ) 
  eqdestroy ( eqtb [p ]) ;
  else if ( curlevel > 1 ) 
  eqsave ( p , eqtb [p ].hh.b1 ) ;
  eqtb [p ].hh.b1 = curlevel ;
  eqtb [p ].hh.b0 = t ;
  eqtb [p ].hh .v.RH = e ;
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 595 ) ;
#endif /* STAT */
} 
void 
zeqworddefine ( halfword p , integer w ) 
{
  /* 10 */ eqworddefine_regmem 
  if ( ( eTeXmode == 1 ) && ( eqtb [p ].cint == w ) ) 
  {
	;
#ifdef STAT
    if ( eqtb [29252 ].cint > 0 ) 
    restoretrace ( p , 593 ) ;
#endif /* STAT */
    return ;
  } 
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 594 ) ;
#endif /* STAT */
  if ( xeqlevel [p ]!= curlevel ) 
  {
    eqsave ( p , xeqlevel [p ]) ;
    xeqlevel [p ]= curlevel ;
  } 
  eqtb [p ].cint = w ;
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 595 ) ;
#endif /* STAT */
} 
void 
zdeleqworddefine ( halfword p , integer w , integer wone ) 
{
  /* 10 */ deleqworddefine_regmem 
  if ( ( eTeXmode == 1 ) && ( eqtb [p ].cint == w ) && ( getintone ( eqtb [
  p ]) == wone ) ) 
  {
	;
#ifdef STAT
    if ( eqtb [29252 ].cint > 0 ) 
    restoretrace ( p , 593 ) ;
#endif /* STAT */
    return ;
  } 
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 594 ) ;
#endif /* STAT */
  if ( xeqlevel [p ]!= curlevel ) 
  {
    eqsave ( p , xeqlevel [p ]) ;
    xeqlevel [p ]= curlevel ;
  } 
  eqtb [p ].cint = w ;
  setintone ( eqtb [p ], wone ) ;
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 595 ) ;
#endif /* STAT */
} 
void 
zgeqdefine ( halfword p , quarterword t , halfword e ) 
{
  geqdefine_regmem 
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 596 ) ;
#endif /* STAT */
  {
    eqdestroy ( eqtb [p ]) ;
    eqtb [p ].hh.b1 = 1 ;
    eqtb [p ].hh.b0 = t ;
    eqtb [p ].hh .v.RH = e ;
  } 
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 595 ) ;
#endif /* STAT */
} 
void 
zgeqworddefine ( halfword p , integer w ) 
{
  geqworddefine_regmem 
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 596 ) ;
#endif /* STAT */
  {
    eqtb [p ].cint = w ;
    xeqlevel [p ]= 1 ;
  } 
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 595 ) ;
#endif /* STAT */
} 
void 
zdelgeqworddefine ( halfword p , integer w , integer wone ) 
{
  delgeqworddefine_regmem 
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 596 ) ;
#endif /* STAT */
  {
    eqtb [p ].cint = w ;
    setintone ( eqtb [p ], wone ) ;
    xeqlevel [p ]= 1 ;
  } 
	;
#ifdef STAT
  if ( eqtb [29252 ].cint > 0 ) 
  restoretrace ( p , 595 ) ;
#endif /* STAT */
} 
void 
zsaveforafter ( halfword t ) 
{
  saveforafter_regmem 
  if ( curlevel > 1 ) 
  {
    if ( saveptr > maxsavestack ) 
    {
      maxsavestack = saveptr ;
      if ( maxsavestack > savesize - 7 ) 
      overflow ( 591 , savesize ) ;
    } 
    savestack [saveptr ].hh.b0 = 2 ;
    savestack [saveptr ].hh.b1 = 0 ;
    savestack [saveptr ].hh .v.RH = t ;
    incr ( saveptr ) ;
  } 
} 
void 
unsave ( void ) 
{
  /* 30 */ unsave_regmem 
  halfword p  ;
  quarterword l  ;
  halfword t  ;
  boolean a  ;
  a = false ;
  if ( curlevel > 1 ) 
  {
    decr ( curlevel ) ;
    while ( true ) {
	
      decr ( saveptr ) ;
      if ( savestack [saveptr ].hh.b0 == 3 ) 
      goto lab30 ;
      p = savestack [saveptr ].hh .v.RH ;
      if ( savestack [saveptr ].hh.b0 == 2 ) 
      {
	t = curtok ;
	curtok = p ;
	if ( a ) 
	{
	  p = getavail () ;
	  mem [p ].hh .v.LH = curtok ;
	  mem [p ].hh .v.RH = curinput .locfield ;
	  curinput .locfield = p ;
	  curinput .startfield = p ;
	  if ( curtok < 768 ) {
	      
	    if ( curtok < 512 ) 
	    decr ( alignstate ) ;
	    else incr ( alignstate ) ;
	  } 
	} 
	else {
	    
	  backinput () ;
	  a = ( eTeXmode == 1 ) ;
	} 
	curtok = t ;
      } 
      else if ( savestack [saveptr ].hh.b0 == 4 ) 
      {
	sarestore () ;
	sachain = p ;
	salevel = savestack [saveptr ].hh.b1 ;
      } 
      else {
	  
	if ( savestack [saveptr ].hh.b0 == 0 ) 
	{
	  l = savestack [saveptr ].hh.b1 ;
	  decr ( saveptr ) ;
	} 
	else savestack [saveptr ]= eqtb [24527 ];
	if ( ( p < 29188 ) || ( p > 30310 ) ) {
	    
	  if ( eqtb [p ].hh.b1 == 1 ) 
	  {
	    eqdestroy ( savestack [saveptr ]) ;
	;
#ifdef STAT
	    if ( eqtb [29225 ].cint > 0 ) 
	    restoretrace ( p , 598 ) ;
#endif /* STAT */
	  } 
	  else {
	      
	    eqdestroy ( eqtb [p ]) ;
	    eqtb [p ]= savestack [saveptr ];
	;
#ifdef STAT
	    if ( eqtb [29225 ].cint > 0 ) 
	    restoretrace ( p , 599 ) ;
#endif /* STAT */
	  } 
	} 
	else if ( xeqlevel [p ]!= 1 ) 
	{
	  eqtb [p ]= savestack [saveptr ];
	  xeqlevel [p ]= l ;
	;
#ifdef STAT
	  if ( eqtb [29225 ].cint > 0 ) 
	  restoretrace ( p , 599 ) ;
#endif /* STAT */
	} 
	else {
	    
	;
#ifdef STAT
	  if ( eqtb [29225 ].cint > 0 ) 
	  restoretrace ( p , 598 ) ;
#endif /* STAT */
	} 
      } 
    } 
    lab30: 
	;
#ifdef STAT
    if ( eqtb [29253 ].cint > 0 ) 
    grouptrace ( true ) ;
#endif /* STAT */
    if ( grpstack [inopen ]== curboundary ) 
    groupwarning () ;
    curgroup = savestack [saveptr ].hh.b1 ;
    curboundary = savestack [saveptr ].hh .v.RH ;
    if ( ( eTeXmode == 1 ) ) 
    decr ( saveptr ) ;
  } 
  else confusion ( 597 ) ;
} 
void 
preparemag ( void ) 
{
  preparemag_regmem 
  if ( ( magset > 0 ) && ( eqtb [29205 ].cint != magset ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 601 ) ;
    } 
    printint ( eqtb [29205 ].cint ) ;
    print ( 602 ) ;
    printnl ( 603 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 604 ;
      helpline [0 ]= 605 ;
    } 
    interror ( magset ) ;
    geqworddefine ( 29205 , magset ) ;
  } 
  if ( ( eqtb [29205 ].cint <= 0 ) || ( eqtb [29205 ].cint > 32768L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 606 ) ;
    } 
    {
      helpptr = 1 ;
      helpline [0 ]= 607 ;
    } 
    interror ( eqtb [29205 ].cint ) ;
    geqworddefine ( 29205 , 1000 ) ;
  } 
  magset = eqtb [29205 ].cint ;
} 
void 
ztokenshow ( halfword p ) 
{
  tokenshow_regmem 
  if ( p != -1073741823L ) 
  showtokenlist ( mem [p ].hh .v.RH , -1073741823L , 10000000L ) ;
} 
void 
printmeaning ( void ) 
{
  printmeaning_regmem 
  printcmdchr ( curcmd , curchr ) ;
  if ( curcmd >= 127 ) 
  {
    printchar ( 58 ) ;
    println () ;
    tokenshow ( curchr ) ;
  } 
  else if ( ( curcmd == 126 ) && ( curchr < 5 ) ) 
  {
    printchar ( 58 ) ;
    println () ;
    tokenshow ( curmark [curchr ]) ;
  } 
} 
void 
showcurcmdchr ( void ) 
{
  showcurcmdchr_regmem 
  integer n  ;
  integer l  ;
  halfword p  ;
  begindiagnostic () ;
  printnl ( 123 ) ;
  if ( curlist .modefield != shownmode ) 
  {
    printmode ( curlist .modefield ) ;
    print ( 622 ) ;
    shownmode = curlist .modefield ;
  } 
  printcmdchr ( curcmd , curchr ) ;
  if ( eqtb [29254 ].cint > 0 ) {
      
    if ( curcmd >= 121 ) {
	
      if ( curcmd <= 122 ) 
      {
	print ( 622 ) ;
	if ( curcmd == 122 ) 
	{
	  printcmdchr ( 121 , curif ) ;
	  printchar ( 32 ) ;
	  n = 0 ;
	  l = ifline ;
	} 
	else {
	    
	  n = 1 ;
	  l = line ;
	} 
	p = condptr ;
	while ( p != -1073741823L ) {
	    
	  incr ( n ) ;
	  p = mem [p ].hh .v.RH ;
	} 
	print ( 623 ) ;
	printint ( n ) ;
	printchar ( 41 ) ;
	if ( l != 0 ) 
	{
	  print ( 1505 ) ;
	  printint ( l ) ;
	} 
      } 
    } 
  } 
  printchar ( 125 ) ;
  enddiagnostic ( false ) ;
} 
void 
showcontext ( void ) 
{
  /* 30 31 */ showcontext_regmem 
  unsigned char oldsetting  ;
  halfword s  ;
  integer nn  ;
  boolean bottomline  ;
  integer i  ;
  integer j  ;
  integer l  ;
  integer m  ;
  integer n  ;
  integer p  ;
  integer q  ;
  baseptr = inputptr ;
  inputstack [baseptr ]= curinput ;
  nn = -1 ;
  bottomline = false ;
  while ( true ) {
      
    curinput = inputstack [baseptr ];
    if ( ( curinput .statefield != 0 ) ) {
	
      if ( ( curinput .namefield > 19 ) || ( baseptr == 0 ) ) 
      bottomline = true ;
    } 
    if ( ( baseptr == inputptr ) || bottomline || ( nn < eqtb [29243 ].cint 
    ) ) 
    {
      if ( ( baseptr == inputptr ) || ( curinput .statefield != 0 ) || ( 
      curinput .indexfield != 3 ) || ( curinput .locfield != -1073741823L ) ) 
      {
	tally = 0 ;
	oldsetting = selector ;
	if ( curinput .statefield != 0 ) 
	{
	  if ( curinput .namefield <= 17 ) {
	      
	    if ( ( curinput .namefield == 0 ) ) {
		
	      if ( baseptr == 0 ) 
	      printnl ( 628 ) ;
	      else printnl ( 629 ) ;
	    } 
	    else {
		
	      printnl ( 630 ) ;
	      if ( curinput .namefield == 17 ) 
	      printchar ( 42 ) ;
	      else printint ( curinput .namefield - 1 ) ;
	      printchar ( 62 ) ;
	    } 
	  } 
	  else {
	      
	    printnl ( 631 ) ;
	    if ( curinput .indexfield == inopen ) 
	    printint ( line ) ;
	    else printint ( linestack [curinput .indexfield + 1 ]) ;
	  } 
	  printchar ( 32 ) ;
	  {
	    l = tally ;
	    tally = 0 ;
	    selector = 20 ;
	    kcodepos = 0 ;
	    trickcount = 1000000L ;
	  } 
	  if ( buffer [curinput .limitfield ]== eqtb [29237 ].cint ) 
	  j = curinput .limitfield ;
	  else j = curinput .limitfield + 1 ;
	  if ( j > 0 ) 
	  {register integer for_end; i = curinput .startfield ;for_end = j - 
	  1 ; if ( i <= for_end) do 
	    {
	      if ( i == curinput .locfield ) 
	      {
		firstcount = tally ;
		kcp = trickbuf2 [( firstcount - 1 ) % errorline ];
		if ( ( firstcount > 0 ) && ( kcp > 0 ) ) 
		firstcount = firstcount + nrestmultichr ( kcp ) ;
		trickcount = firstcount + 1 + errorline - halferrorline ;
		if ( trickcount < errorline ) 
		trickcount = errorline ;
	      } 
	      print ( buffer [i ]) ;
	    } 
	  while ( i++ < for_end ) ;} 
	} 
	else {
	    
	  switch ( curinput .indexfield ) 
	  {case 0 : 
	    printnl ( 632 ) ;
	    break ;
	  case 1 : 
	  case 2 : 
	    printnl ( 633 ) ;
	    break ;
	  case 3 : 
	    if ( curinput .locfield == -1073741823L ) 
	    printnl ( 634 ) ;
	    else printnl ( 635 ) ;
	    break ;
	  case 4 : 
	    printnl ( 636 ) ;
	    break ;
	  case 5 : 
	    {
	      println () ;
	      printcs ( curinput .namefield ) ;
	    } 
	    break ;
	  case 6 : 
	    printnl ( 637 ) ;
	    break ;
	  case 7 : 
	    printnl ( 638 ) ;
	    break ;
	  case 8 : 
	    printnl ( 639 ) ;
	    break ;
	  case 9 : 
	    printnl ( 640 ) ;
	    break ;
	  case 10 : 
	    printnl ( 641 ) ;
	    break ;
	  case 11 : 
	    printnl ( 642 ) ;
	    break ;
	  case 12 : 
	    printnl ( 643 ) ;
	    break ;
	  case 13 : 
	    printnl ( 644 ) ;
	    break ;
	  case 14 : 
	    printnl ( 645 ) ;
	    break ;
	  case 15 : 
	    printnl ( 646 ) ;
	    break ;
	  case 16 : 
	    printnl ( 647 ) ;
	    break ;
	    default: 
	    printnl ( 63 ) ;
	    break ;
	  } 
	  {
	    l = tally ;
	    tally = 0 ;
	    selector = 20 ;
	    kcodepos = 0 ;
	    trickcount = 1000000L ;
	  } 
	  if ( curinput .indexfield < 5 ) 
	  {
	    if ( ( curinput .indexfield == 3 ) && ( curinput .locfield != 
	    -1073741823L ) ) 
	    {
	      if ( ( mem [curinput .startfield ].hh .v.RH == -1073741823L ) 
	      && ( checkkanji ( mem [curinput .startfield ].hh .v.LH ) ) ) 
	      {
		curinput = inputstack [baseptr - 1 ];
		s = getavail () ;
		mem [s ].hh .v.LH = ( mem [curinput .locfield ].hh .v.LH % 
		256 ) ;
		curinput = inputstack [baseptr ];
		mem [curinput .startfield ].hh .v.RH = s ;
		showtokenlist ( curinput .startfield , curinput .locfield , 
		100000L ) ;
		{
		  mem [s ].hh .v.RH = avail ;
		  avail = s ;
	;
#ifdef STAT
		  decr ( dynused ) ;
#endif /* STAT */
		} 
		mem [curinput .startfield ].hh .v.RH = -1073741823L ;
		goto lab31 ;
	      } 
	    } 
	    showtokenlist ( curinput .startfield , curinput .locfield , 
	    100000L ) ;
	  } 
	  else showtokenlist ( mem [curinput .startfield ].hh .v.RH , 
	  curinput .locfield , 100000L ) ;
	  lab31: ;
	} 
	selector = oldsetting ;
	if ( trickcount == 1000000L ) 
	{
	  firstcount = tally ;
	  kcp = trickbuf2 [( firstcount - 1 ) % errorline ];
	  if ( ( firstcount > 0 ) && ( kcp > 0 ) ) 
	  firstcount = firstcount + nrestmultichr ( kcp ) ;
	  trickcount = firstcount + 1 + errorline - halferrorline ;
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
	    
	  print ( 277 ) ;
	  p = l + firstcount - halferrorline + 3 ;
	  n = halferrorline ;
	} 
	kcp = trickbuf2 [p % errorline ];
	if ( ( kcp % 8 ) > 1 ) 
	{
	  p = p + nrestmultichr ( kcp ) + 1 ;
	  n = n - nrestmultichr ( kcp ) - 1 ;
	} 
	{register integer for_end; q = p ;for_end = firstcount - 1 ; if ( q 
	<= for_end) do 
	  printchar ( trickbuf [q % errorline ]) ;
	while ( q++ < for_end ) ;} 
	println () ;
	{register integer for_end; q = 1 ;for_end = n ; if ( q <= for_end) 
	do 
	  printchar ( 32 ) ;
	while ( q++ < for_end ) ;} 
	if ( m + n <= errorline ) 
	p = firstcount + m ;
	else p = firstcount + ( errorline - n - 3 ) ;
	kcp = trickbuf2 [( p - 1 ) % errorline ];
	if ( ( ( kcp % 8 ) > 0 ) && ( nrestmultichr ( kcp ) > 0 ) ) 
	p = p - ( kcp % 8 ) ;
	{register integer for_end; q = firstcount ;for_end = p - 1 ; if ( q 
	<= for_end) do 
	  printchar ( trickbuf [q % errorline ]) ;
	while ( q++ < for_end ) ;} 
	if ( m + n > errorline ) 
	print ( 277 ) ;
	incr ( nn ) ;
      } 
    } 
    else if ( nn == eqtb [29243 ].cint ) 
    {
      printnl ( 277 ) ;
      incr ( nn ) ;
    } 
    if ( bottomline ) 
    goto lab30 ;
    decr ( baseptr ) ;
  } 
  lab30: curinput = inputstack [inputptr ];
} 
void 
zbegintokenlist ( halfword p , quarterword t ) 
{
  begintokenlist_regmem 
  {
    if ( inputptr > maxinstack ) 
    {
      maxinstack = inputptr ;
      if ( inputptr == stacksize ) 
      overflow ( 648 , stacksize ) ;
    } 
    inputstack [inputptr ]= curinput ;
    incr ( inputptr ) ;
  } 
  curinput .statefield = 0 ;
  curinput .startfield = p ;
  curinput .indexfield = t ;
  if ( t >= 5 ) 
  {
    incr ( mem [p ].hh .v.LH ) ;
    if ( t == 5 ) 
    curinput .limitfield = paramptr ;
    else {
	
      curinput .locfield = mem [p ].hh .v.RH ;
      if ( eqtb [29218 ].cint > 1 ) 
      {
	begindiagnostic () ;
	printnl ( 344 ) ;
	switch ( t ) 
	{case 14 : 
	  printesc ( 361 ) ;
	  break ;
	case 16 : 
	  printesc ( 649 ) ;
	  break ;
	  default: 
	  printcmdchr ( 81 , t + 25056 ) ;
	  break ;
	} 
	print ( 609 ) ;
	tokenshow ( p ) ;
	enddiagnostic ( false ) ;
      } 
    } 
  } 
  else curinput .locfield = p ;
} 
void 
endtokenlist ( void ) 
{
  endtokenlist_regmem 
  if ( curinput .indexfield >= 3 ) 
  {
    if ( curinput .indexfield <= 4 ) 
    flushlist ( curinput .startfield ) ;
    else {
	
      deletetokenref ( curinput .startfield ) ;
      if ( curinput .indexfield == 5 ) 
      while ( paramptr > curinput .limitfield ) {
	  
	decr ( paramptr ) ;
	flushlist ( paramstack [paramptr ]) ;
      } 
    } 
  } 
  else if ( curinput .indexfield == 1 ) {
      
    if ( alignstate > 500000L ) 
    alignstate = 0 ;
    else fatalerror ( 650 ) ;
  } 
  {
    decr ( inputptr ) ;
    curinput = inputstack [inputptr ];
  } 
  {
    if ( interrupt != 0 ) 
    pauseforinstructions () ;
  } 
} 
void 
backinput ( void ) 
{
  backinput_regmem 
  halfword p  ;
  while ( ( curinput .statefield == 0 ) && ( curinput .locfield == 
  -1073741823L ) && ( curinput .indexfield != 2 ) ) endtokenlist () ;
  p = getavail () ;
  mem [p ].hh .v.LH = curtok ;
  if ( curtok < 768 ) {
      
    if ( curtok < 512 ) 
    decr ( alignstate ) ;
    else incr ( alignstate ) ;
  } 
  {
    if ( inputptr > maxinstack ) 
    {
      maxinstack = inputptr ;
      if ( inputptr == stacksize ) 
      overflow ( 648 , stacksize ) ;
    } 
    inputstack [inputptr ]= curinput ;
    incr ( inputptr ) ;
  } 
  curinput .statefield = 0 ;
  curinput .startfield = p ;
  curinput .indexfield = 3 ;
  curinput .locfield = p ;
} 
void 
backerror ( void ) 
{
  backerror_regmem 
  OKtointerrupt = false ;
  backinput () ;
  OKtointerrupt = true ;
  error () ;
} 
void 
inserror ( void ) 
{
  inserror_regmem 
  OKtointerrupt = false ;
  backinput () ;
  curinput .indexfield = 4 ;
  OKtointerrupt = true ;
  error () ;
} 
void 
beginfilereading ( void ) 
{
  beginfilereading_regmem 
  if ( inopen == maxinopen ) 
  overflow ( 651 , maxinopen ) ;
  if ( first == bufsize ) 
  overflow ( 258 , bufsize ) ;
  incr ( inopen ) ;
  {
    if ( inputptr > maxinstack ) 
    {
      maxinstack = inputptr ;
      if ( inputptr == stacksize ) 
      overflow ( 648 , stacksize ) ;
    } 
    inputstack [inputptr ]= curinput ;
    incr ( inputptr ) ;
  } 
  curinput .indexfield = inopen ;
  sourcefilenamestack [curinput .indexfield ]= 0 ;
  fullsourcefilenamestack [curinput .indexfield ]= 0 ;
  eofseen [curinput .indexfield ]= false ;
  grpstack [curinput .indexfield ]= curboundary ;
  ifstack [curinput .indexfield ]= condptr ;
  linestack [curinput .indexfield ]= line ;
  curinput .startfield = first ;
  curinput .statefield = 1 ;
  curinput .namefield = 0 ;
  curinput .synctextagfield = 0 ;
} 
void 
endfilereading ( void ) 
{
  endfilereading_regmem 
  first = curinput .startfield ;
  line = linestack [curinput .indexfield ];
  if ( ( curinput .namefield == 18 ) || ( curinput .namefield == 19 ) ) 
  pseudoclose () ;
  else if ( curinput .namefield > 17 ) 
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
  clearforerrorprompt_regmem 
  while ( ( curinput .statefield != 0 ) && ( curinput .namefield == 0 ) && ( 
  inputptr > 0 ) && ( curinput .locfield > curinput .limitfield ) ) 
  endfilereading () ;
  println () ;
} 
void 
checkoutervalidity ( void ) 
{
  checkoutervalidity_regmem 
  halfword p  ;
  halfword q  ;
  if ( scannerstatus != 0 ) 
  {
    deletionsallowed = false ;
    if ( curcs != 0 ) 
    {
      if ( ( curinput .statefield == 0 ) || ( curinput .namefield < 1 ) || ( 
      curinput .namefield > 17 ) ) 
      {
	p = getavail () ;
	mem [p ].hh .v.LH = 536870911L + curcs ;
	begintokenlist ( p , 3 ) ;
      } 
      curcmd = 10 ;
      curchr = 32 ;
    } 
    if ( scannerstatus > 1 ) 
    {
      runaway () ;
      if ( curcs == 0 ) 
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 659 ) ;
      } 
      else {
	  
	curcs = 0 ;
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 660 ) ;
	} 
      } 
      p = getavail () ;
      switch ( scannerstatus ) 
      {case 2 : 
	{
	  print ( 666 ) ;
	  mem [p ].hh .v.LH = 637 ;
	} 
	break ;
      case 3 : 
	{
	  print ( 667 ) ;
	  mem [p ].hh .v.LH = partoken ;
	  longstate = 129 ;
	} 
	break ;
      case 4 : 
	{
	  print ( 668 ) ;
	  mem [p ].hh .v.LH = 637 ;
	  q = p ;
	  p = getavail () ;
	  mem [p ].hh .v.RH = q ;
	  mem [p ].hh .v.LH = 536886426L ;
	  alignstate = -1000000L ;
	} 
	break ;
      case 5 : 
	{
	  print ( 669 ) ;
	  mem [p ].hh .v.LH = 637 ;
	} 
	break ;
      } 
      begintokenlist ( p , 4 ) ;
      print ( 661 ) ;
      sprintcs ( warningindex ) ;
      {
	helpptr = 4 ;
	helpline [3 ]= 662 ;
	helpline [2 ]= 663 ;
	helpline [1 ]= 664 ;
	helpline [0 ]= 665 ;
      } 
      error () ;
    } 
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 653 ) ;
      } 
      printcmdchr ( 121 , curif ) ;
      print ( 654 ) ;
      printint ( skipline ) ;
      {
	helpptr = 3 ;
	helpline [2 ]= 655 ;
	helpline [1 ]= 656 ;
	helpline [0 ]= 657 ;
      } 
      if ( curcs != 0 ) 
      curcs = 0 ;
      else helpline [2 ]= 658 ;
      curtok = 536886429L ;
      inserror () ;
    } 
    deletionsallowed = true ;
  } 
} 
void 
getnext ( void ) 
{
  /* 20 25 21 26 40 10 */ getnext_regmem 
  integer k  ;
  halfword t  ;
  unsigned char cat  ;
  integer l  ;
  ASCIIcode c, cc  ;
  unsigned char d  ;
  lab20: curcs = 0 ;
  if ( curinput .statefield != 0 ) 
  {
    lab25: if ( curinput .locfield <= curinput .limitfield ) 
    {
      curchr = fromBUFF ( ustringcast ( buffer ) , curinput .limitfield , 
      curinput .locfield ) ;
      curcmd = eqtb [26618 + kcatcodekey ( curchr ) ].hh .v.RH ;
      if ( ( multistrlen ( ustringcast ( buffer ) , curinput .limitfield , 
      curinput .locfield ) > 1 ) && checkkcatcode ( curcmd ) ) 
      {
	if ( ( curcmd == 15 ) ) 
	curcmd = 18 ;
	curinput .locfield = curinput .locfield + multistrlen ( ustringcast ( 
	buffer ) , curinput .limitfield , curinput .locfield ) ;
      } 
      else {
	  
	curchr = buffer [curinput .locfield ];
	incr ( curinput .locfield ) ;
	lab21: curcmd = eqtb [26362 + curchr ].hh .v.RH ;
      } 
      switch ( curinput .statefield + curcmd ) 
      {case 10 : 
      case 30 : 
      case 50 : 
      case 70 : 
      case 51 : 
      case 71 : 
	goto lab25 ;
	break ;
      case 1 : 
      case 21 : 
      case 41 : 
      case 61 : 
	{
	  if ( curinput .locfield > curinput .limitfield ) 
	  curcs = 513 ;
	  else {
	      
	    k = curinput .locfield ;
	    curchr = fromBUFF ( ustringcast ( buffer ) , curinput .limitfield 
	    , k ) ;
	    cat = eqtb [26618 + kcatcodekey ( curchr ) ].hh .v.RH ;
	    if ( ( multistrlen ( ustringcast ( buffer ) , curinput .limitfield 
	    , k ) > 1 ) && checkkcatcode ( cat ) ) 
	    {
	      if ( ( cat == 15 ) ) 
	      cat = 18 ;
	      k = k + multistrlen ( ustringcast ( buffer ) , curinput 
	      .limitfield , k ) ;
	    } 
	    else {
		
	      curchr = buffer [k ];
	      cat = eqtb [26362 + curchr ].hh .v.RH ;
	      incr ( k ) ;
	    } 
	    lab26: if ( ( cat == 11 ) || ( cat == 16 ) || ( cat == 17 ) || ( 
	    cat == 19 ) ) 
	    curinput .statefield = 41 ;
	    else if ( cat == 10 ) 
	    curinput .statefield = 41 ;
	    else curinput .statefield = 1 ;
	    if ( cat == 18 ) 
	    {
	      curcs = idlookup ( curinput .locfield , k - curinput .locfield ) 
	      ;
	      curinput .locfield = k ;
	      goto lab40 ;
	    } 
	    else if ( ( ( cat == 11 ) || ( cat == 16 ) || ( cat == 17 ) || ( 
	    cat == 19 ) ) && ( k <= curinput .limitfield ) ) 
	    {
	      do {
		  curchr = fromBUFF ( ustringcast ( buffer ) , curinput 
		.limitfield , k ) ;
		cat = eqtb [26618 + kcatcodekey ( curchr ) ].hh .v.RH ;
		if ( ( multistrlen ( ustringcast ( buffer ) , curinput 
		.limitfield , k ) > 1 ) && checkkcatcode ( cat ) ) 
		{
		  if ( ( cat == 15 ) ) 
		  cat = 18 ;
		  k = k + multistrlen ( ustringcast ( buffer ) , curinput 
		  .limitfield , k ) ;
		} 
		else {
		    
		  curchr = buffer [k ];
		  cat = eqtb [26362 + curchr ].hh .v.RH ;
		  incr ( k ) ;
		} 
		while ( ( buffer [k ]== curchr ) && ( cat == 7 ) && ( k < 
		curinput .limitfield ) ) {
		    
		  c = buffer [k + 1 ];
		  if ( c < 128 ) 
		  {
		    d = 2 ;
		    if ( ( ( ( c >= 48 ) && ( c <= 57 ) ) || ( ( c >= 97 ) && 
		    ( c <= 102 ) ) ) ) {
			
		      if ( k + 2 <= curinput .limitfield ) 
		      {
			cc = buffer [k + 2 ];
			if ( ( ( ( cc >= 48 ) && ( cc <= 57 ) ) || ( ( cc >= 
			97 ) && ( cc <= 102 ) ) ) ) 
			incr ( d ) ;
		      } 
		    } 
		    if ( d > 2 ) 
		    {
		      if ( c <= 57 ) 
		      curchr = c - 48 ;
		      else curchr = c - 87 ;
		      if ( cc <= 57 ) 
		      curchr = 16 * curchr + cc - 48 ;
		      else curchr = 16 * curchr + cc - 87 ;
		    } 
		    else if ( c < 64 ) 
		    curchr = c + 64 ;
		    else curchr = c - 64 ;
		    cat = eqtb [26362 + curchr ].hh .v.RH ;
		    if ( ( cat == 11 ) || ( cat == 7 ) ) 
		    {
		      buffer [k - 1 ]= curchr ;
		      curinput .limitfield = curinput .limitfield - d ;
		      first = first - d ;
		      l = k ;
		      while ( l <= curinput .limitfield ) {
			  
			buffer [l ]= buffer [l + d ];
			incr ( l ) ;
		      } 
		    } 
		  } 
		} 
	      } while ( ! ( ! ( ( cat == 11 ) || ( cat == 16 ) || ( cat == 17 
	      ) || ( cat == 19 ) ) || ( k > curinput .limitfield ) ) ) ;
	      if ( ! ( ( cat == 11 ) || ( cat == 16 ) || ( cat == 17 ) || ( 
	      cat == 19 ) ) ) 
	      decr ( k ) ;
	      if ( cat == 18 ) 
	      k = k - multilenbuffchar ( curchr ) + 1 ;
	      if ( k > curinput .locfield + 1 ) 
	      {
		curcs = idlookup ( curinput .locfield , k - curinput .locfield 
		) ;
		curinput .locfield = k ;
		goto lab40 ;
	      } 
	    } 
	    else {
		
	      if ( buffer [k ]== curchr ) {
		  
		if ( cat == 7 ) {
		    
		  if ( k < curinput .limitfield ) 
		  {
		    c = buffer [k + 1 ];
		    if ( c < 128 ) 
		    {
		      d = 2 ;
		      if ( ( ( ( c >= 48 ) && ( c <= 57 ) ) || ( ( c >= 97 ) 
		      && ( c <= 102 ) ) ) ) {
			  
			if ( k + 2 <= curinput .limitfield ) 
			{
			  cc = buffer [k + 2 ];
			  if ( ( ( ( cc >= 48 ) && ( cc <= 57 ) ) || ( ( cc >= 
			  97 ) && ( cc <= 102 ) ) ) ) 
			  incr ( d ) ;
			} 
		      } 
		      if ( d > 2 ) 
		      {
			if ( c <= 57 ) 
			curchr = c - 48 ;
			else curchr = c - 87 ;
			if ( cc <= 57 ) 
			curchr = 16 * curchr + cc - 48 ;
			else curchr = 16 * curchr + cc - 87 ;
			buffer [k - 1 ]= curchr ;
		      } 
		      else if ( c < 64 ) 
		      buffer [k - 1 ]= c + 64 ;
		      else buffer [k - 1 ]= c - 64 ;
		      curinput .limitfield = curinput .limitfield - d ;
		      first = first - d ;
		      l = k ;
		      curchr = buffer [k - 1 ];
		      cat = eqtb [26362 + curchr ].hh .v.RH ;
		      while ( l <= curinput .limitfield ) {
			  
			buffer [l ]= buffer [l + d ];
			incr ( l ) ;
		      } 
		      goto lab26 ;
		    } 
		  } 
		} 
	      } 
	    } 
	    curcs = 257 + buffer [curinput .locfield ];
	    incr ( curinput .locfield ) ;
	  } 
	  lab40: curcmd = eqtb [curcs ].hh.b0 ;
	  curchr = eqtb [curcs ].hh .v.RH ;
	  if ( curcmd >= 129 ) 
	  checkoutervalidity () ;
	} 
	break ;
      case 14 : 
      case 34 : 
      case 54 : 
      case 74 : 
	{
	  curcs = curchr + 1 ;
	  curcmd = eqtb [curcs ].hh.b0 ;
	  curchr = eqtb [curcs ].hh .v.RH ;
	  curinput .statefield = 1 ;
	  if ( curcmd >= 129 ) 
	  checkoutervalidity () ;
	} 
	break ;
      case 8 : 
      case 28 : 
      case 48 : 
      case 68 : 
	{
	  if ( curchr == buffer [curinput .locfield ]) {
	      
	    if ( curinput .locfield < curinput .limitfield ) 
	    {
	      c = buffer [curinput .locfield + 1 ];
	      if ( c < 128 ) 
	      {
		curinput .locfield = curinput .locfield + 2 ;
		if ( ( ( ( c >= 48 ) && ( c <= 57 ) ) || ( ( c >= 97 ) && ( c 
		<= 102 ) ) ) ) {
		    
		  if ( curinput .locfield <= curinput .limitfield ) 
		  {
		    cc = buffer [curinput .locfield ];
		    if ( ( ( ( cc >= 48 ) && ( cc <= 57 ) ) || ( ( cc >= 97 ) 
		    && ( cc <= 102 ) ) ) ) 
		    {
		      incr ( curinput .locfield ) ;
		      if ( c <= 57 ) 
		      curchr = c - 48 ;
		      else curchr = c - 87 ;
		      if ( cc <= 57 ) 
		      curchr = 16 * curchr + cc - 48 ;
		      else curchr = 16 * curchr + cc - 87 ;
		      goto lab21 ;
		    } 
		  } 
		} 
		if ( c < 64 ) 
		curchr = c + 64 ;
		else curchr = c - 64 ;
		goto lab21 ;
	      } 
	    } 
	  } 
	  curinput .statefield = 1 ;
	} 
	break ;
      case 16 : 
      case 36 : 
      case 56 : 
      case 76 : 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 670 ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 671 ;
	    helpline [0 ]= 672 ;
	  } 
	  deletionsallowed = false ;
	  error () ;
	  deletionsallowed = true ;
	  goto lab20 ;
	} 
	break ;
      case 31 : 
      case 11 : 
	{
	  curinput .statefield = 41 ;
	  curchr = 32 ;
	} 
	break ;
      case 6 : 
	{
	  curinput .locfield = curinput .limitfield + 1 ;
	  curcmd = 10 ;
	  curchr = 32 ;
	} 
	break ;
      case 26 : 
	if ( skipmode ) 
	{
	  curinput .locfield = curinput .limitfield + 1 ;
	  goto lab25 ;
	} 
	else {
	    
	  curinput .locfield = curinput .limitfield + 1 ;
	  curcmd = 10 ;
	  curchr = 32 ;
	} 
	break ;
      case 46 : 
      case 15 : 
      case 35 : 
      case 55 : 
      case 75 : 
	{
	  curinput .locfield = curinput .limitfield + 1 ;
	  goto lab25 ;
	} 
	break ;
      case 66 : 
	{
	  curinput .locfield = curinput .limitfield + 1 ;
	  curcs = parloc ;
	  curcmd = eqtb [curcs ].hh.b0 ;
	  curchr = eqtb [curcs ].hh .v.RH ;
	  if ( curcmd >= 129 ) 
	  checkoutervalidity () ;
	} 
	break ;
      case 2 : 
      case 22 : 
	incr ( alignstate ) ;
	break ;
      case 42 : 
      case 62 : 
	{
	  curinput .statefield = 1 ;
	  incr ( alignstate ) ;
	} 
	break ;
      case 3 : 
      case 23 : 
	decr ( alignstate ) ;
	break ;
      case 43 : 
      case 63 : 
	{
	  curinput .statefield = 1 ;
	  decr ( alignstate ) ;
	} 
	break ;
      case 44 : 
      case 45 : 
      case 47 : 
      case 49 : 
      case 52 : 
      case 53 : 
      case 64 : 
      case 65 : 
      case 67 : 
      case 69 : 
      case 72 : 
      case 73 : 
      case 24 : 
      case 25 : 
      case 27 : 
      case 29 : 
      case 32 : 
      case 33 : 
	curinput .statefield = 1 ;
	break ;
      case 57 : 
      case 58 : 
      case 59 : 
      case 77 : 
      case 78 : 
      case 79 : 
      case 17 : 
      case 18 : 
      case 19 : 
	curinput .statefield = 21 ;
	break ;
      case 60 : 
      case 80 : 
      case 40 : 
	curinput .statefield = 1 ;
	break ;
	default: 
	;
	break ;
      } 
    } 
    else {
	
      curinput .statefield = 61 ;
      if ( curinput .namefield > 17 ) 
      {
	incr ( line ) ;
	first = curinput .startfield ;
	if ( ! forceeof ) {
	    
	  if ( curinput .namefield <= 19 ) 
	  {
	    if ( pseudoinput () ) 
	    firmuptheline () ;
	    else if ( ( eqtb [25071 ].hh .v.RH != -1073741823L ) && ! 
	    eofseen [curinput .indexfield ]) 
	    {
	      curinput .limitfield = first - 1 ;
	      eofseen [curinput .indexfield ]= true ;
	      begintokenlist ( eqtb [25071 ].hh .v.RH , 15 ) ;
	      goto lab20 ;
	    } 
	    else forceeof = true ;
	  } 
	  else {
	      
	    if ( inputln ( inputfile [curinput .indexfield ], true ) ) 
	    firmuptheline () ;
	    else if ( ( eqtb [25071 ].hh .v.RH != -1073741823L ) && ! 
	    eofseen [curinput .indexfield ]) 
	    {
	      curinput .limitfield = first - 1 ;
	      eofseen [curinput .indexfield ]= true ;
	      begintokenlist ( eqtb [25071 ].hh .v.RH , 15 ) ;
	      goto lab20 ;
	    } 
	    else forceeof = true ;
	  } 
	} 
	if ( forceeof ) 
	{
	  if ( eqtb [29256 ].cint > 0 ) {
	      
	    if ( ( grpstack [inopen ]!= curboundary ) || ( ifstack [inopen 
	    ]!= condptr ) ) 
	    filewarning () ;
	  } 
	  if ( curinput .namefield >= 19 ) 
	  {
	    printchar ( 41 ) ;
	    decr ( openparens ) ;
	    fflush ( stdout ) ;
	  } 
	  forceeof = false ;
	  endfilereading () ;
	  checkoutervalidity () ;
	  goto lab20 ;
	} 
	if ( ( eqtb [29237 ].cint < 0 ) || ( eqtb [29237 ].cint > 255 ) ) 
	decr ( curinput .limitfield ) ;
	else buffer [curinput .limitfield ]= eqtb [29237 ].cint ;
	first = curinput .limitfield + 1 ;
	curinput .locfield = curinput .startfield ;
      } 
      else {
	  
	if ( ! ( curinput .namefield == 0 ) ) 
	{
	  curcmd = 0 ;
	  curchr = 0 ;
	  return ;
	} 
	if ( inputptr > 0 ) 
	{
	  endfilereading () ;
	  goto lab20 ;
	} 
	if ( selector < 18 ) 
	openlogfile () ;
	if ( interaction > 1 ) 
	{
	  if ( ( eqtb [29237 ].cint < 0 ) || ( eqtb [29237 ].cint > 255 ) 
	  ) 
	  incr ( curinput .limitfield ) ;
	  if ( curinput .limitfield == curinput .startfield ) 
	  printnl ( 673 ) ;
	  println () ;
	  first = curinput .startfield ;
	  {
	    ;
	    print ( 42 ) ;
	    terminput () ;
	  } 
	  curinput .limitfield = last ;
	  if ( ( eqtb [29237 ].cint < 0 ) || ( eqtb [29237 ].cint > 255 ) 
	  ) 
	  decr ( curinput .limitfield ) ;
	  else buffer [curinput .limitfield ]= eqtb [29237 ].cint ;
	  first = curinput .limitfield + 1 ;
	  curinput .locfield = curinput .startfield ;
	} 
	else fatalerror ( 674 ) ;
      } 
      {
	if ( interrupt != 0 ) 
	pauseforinstructions () ;
      } 
      goto lab25 ;
    } 
  } 
  else if ( curinput .locfield != -1073741823L ) 
  {
    t = mem [curinput .locfield ].hh .v.LH ;
    curinput .locfield = mem [curinput .locfield ].hh .v.RH ;
    if ( t >= 536870911L ) 
    {
      curcs = t - 536870911L ;
      curcmd = eqtb [curcs ].hh.b0 ;
      curchr = eqtb [curcs ].hh .v.RH ;
      if ( curcmd >= 129 ) {
	  
	if ( curcmd == 132 ) 
	{
	  curcs = mem [curinput .locfield ].hh .v.LH - 536870911L ;
	  curinput .locfield = -1073741823L ;
	  curcmd = eqtb [curcs ].hh.b0 ;
	  curchr = eqtb [curcs ].hh .v.RH ;
	  if ( curcmd > 116 ) 
	  {
	    curcmd = 0 ;
	    curchr = 257 ;
	  } 
	} 
	else checkoutervalidity () ;
      } 
    } 
    else if ( checkkanji ( t ) ) 
    {
      curcmd = t / 16777216L ;
      curchr = t % 16777216L ;
    } 
    else {
	
      curcmd = t / 256 ;
      curchr = t % 256 ;
      switch ( curcmd ) 
      {case 1 : 
	incr ( alignstate ) ;
	break ;
      case 2 : 
	decr ( alignstate ) ;
	break ;
      case 5 : 
	{
	  begintokenlist ( paramstack [curinput .limitfield + curchr - 1 ], 
	  0 ) ;
	  goto lab20 ;
	} 
	break ;
	default: 
	;
	break ;
      } 
    } 
  } 
  else {
      
    endtokenlist () ;
    goto lab20 ;
  } 
  if ( curcmd <= 5 ) {
      
    if ( curcmd >= 4 ) {
	
      if ( alignstate == 0 ) 
      {
	if ( ( scannerstatus == 4 ) || ( curalign == -1073741823L ) ) 
	fatalerror ( 650 ) ;
	curcmd = mem [curalign + 5 ].hh .v.LH ;
	mem [curalign + 5 ].hh .v.LH = curchr ;
	if ( curcmd == 68 ) 
	begintokenlist ( memtop - 10 , 2 ) ;
	else begintokenlist ( mem [curalign + 2 ].cint , 2 ) ;
	alignstate = 1000000L ;
	goto lab20 ;
      } 
    } 
  } 
} 
void 
firmuptheline ( void ) 
{
  firmuptheline_regmem 
  integer k  ;
  curinput .limitfield = last ;
  if ( eqtb [29216 ].cint > 0 ) {
      
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
	print ( 675 ) ;
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
void 
gettoken ( void ) 
{
  gettoken_regmem 
  nonewcontrolsequence = false ;
  getnext () ;
  nonewcontrolsequence = true ;
  if ( curcs == 0 ) {
      
    if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
    curtok = ( curcmd * 16777216L ) + curchr ;
    else curtok = ( curcmd * 256 ) + curchr ;
  } 
  else curtok = 536870911L + curcs ;
} 
void 
macrocall ( void ) 
{
  /* 10 22 30 31 40 */ macrocall_regmem 
  halfword r  ;
  halfword p  ;
  halfword q  ;
  halfword s  ;
  halfword t  ;
  halfword u, v  ;
  halfword rbraceptr  ;
  smallnumber n  ;
  halfword unbalance  ;
  halfword m  ;
  halfword refcount  ;
  smallnumber savescannerstatus  ;
  halfword savewarningindex  ;
  ASCIIcode matchchr  ;
  savescannerstatus = scannerstatus ;
  savewarningindex = warningindex ;
  warningindex = curcs ;
  refcount = curchr ;
  r = mem [refcount ].hh .v.RH ;
  n = 0 ;
  if ( eqtb [29218 ].cint > 0 ) 
  {
    begindiagnostic () ;
    println () ;
    printcs ( warningindex ) ;
    tokenshow ( refcount ) ;
    enddiagnostic ( false ) ;
  } 
  if ( mem [r ].hh .v.LH == 3585 ) 
  r = mem [r ].hh .v.RH ;
  if ( mem [r ].hh .v.LH != 3584 ) 
  {
    scannerstatus = 3 ;
    unbalance = 0 ;
    longstate = eqtb [curcs ].hh.b0 ;
    if ( longstate >= 129 ) 
    longstate = longstate - 2 ;
    do {
	mem [memtop - 3 ].hh .v.RH = -1073741823L ;
      if ( ( mem [r ].hh .v.LH > 3583 ) || ( mem [r ].hh .v.LH < 3328 ) ) 
      s = -1073741823L ;
      else {
	  
	matchchr = mem [r ].hh .v.LH - 3328 ;
	s = mem [r ].hh .v.RH ;
	r = s ;
	p = memtop - 3 ;
	m = 0 ;
      } 
      lab22: gettoken () ;
      if ( curtok == mem [r ].hh .v.LH ) 
      {
	r = mem [r ].hh .v.RH ;
	if ( ( mem [r ].hh .v.LH >= 3328 ) && ( mem [r ].hh .v.LH <= 3584 
	) ) 
	{
	  if ( curtok < 512 ) 
	  decr ( alignstate ) ;
	  goto lab40 ;
	} 
	else goto lab22 ;
      } 
      if ( s != r ) {
	  
	if ( s == -1073741823L ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 711 ) ;
	  } 
	  sprintcs ( warningindex ) ;
	  print ( 712 ) ;
	  {
	    helpptr = 4 ;
	    helpline [3 ]= 713 ;
	    helpline [2 ]= 714 ;
	    helpline [1 ]= 715 ;
	    helpline [0 ]= 716 ;
	  } 
	  error () ;
	  goto lab10 ;
	} 
	else {
	    
	  t = s ;
	  do {
	      { 
	      q = getavail () ;
	      mem [p ].hh .v.RH = q ;
	      mem [q ].hh .v.LH = mem [t ].hh .v.LH ;
	      p = q ;
	    } 
	    incr ( m ) ;
	    u = mem [t ].hh .v.RH ;
	    v = s ;
	    while ( true ) {
		
	      if ( u == r ) {
		  
		if ( curtok != mem [v ].hh .v.LH ) 
		goto lab30 ;
		else {
		    
		  r = mem [v ].hh .v.RH ;
		  goto lab22 ;
		} 
	      } 
	      if ( mem [u ].hh .v.LH != mem [v ].hh .v.LH ) 
	      goto lab30 ;
	      u = mem [u ].hh .v.RH ;
	      v = mem [v ].hh .v.RH ;
	    } 
	    lab30: t = mem [t ].hh .v.RH ;
	  } while ( ! ( t == r ) ) ;
	  r = s ;
	} 
      } 
      if ( curtok == partoken ) {
	  
	if ( longstate != 128 ) 
	{
	  if ( longstate == 127 ) 
	  {
	    runaway () ;
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 264 ) ;
	      print ( 706 ) ;
	    } 
	    sprintcs ( warningindex ) ;
	    print ( 707 ) ;
	    {
	      helpptr = 3 ;
	      helpline [2 ]= 708 ;
	      helpline [1 ]= 709 ;
	      helpline [0 ]= 710 ;
	    } 
	    backerror () ;
	  } 
	  pstack [n ]= mem [memtop - 3 ].hh .v.RH ;
	  alignstate = alignstate - unbalance ;
	  {register integer for_end; m = 0 ;for_end = n ; if ( m <= for_end) 
	  do 
	    flushlist ( pstack [m ]) ;
	  while ( m++ < for_end ) ;} 
	  goto lab10 ;
	} 
      } 
      if ( curtok < 768 ) {
	  
	if ( curtok < 512 ) 
	{
	  unbalance = 1 ;
	  while ( true ) {
	      
	    {
	      {
		q = avail ;
		if ( q == -1073741823L ) 
		q = getavail () ;
		else {
		    
		  avail = mem [q ].hh .v.RH ;
		  mem [q ].hh .v.RH = -1073741823L ;
	;
#ifdef STAT
		  incr ( dynused ) ;
#endif /* STAT */
		} 
	      } 
	      mem [p ].hh .v.RH = q ;
	      mem [q ].hh .v.LH = curtok ;
	      p = q ;
	    } 
	    gettoken () ;
	    if ( curtok == partoken ) {
		
	      if ( longstate != 128 ) 
	      {
		if ( longstate == 127 ) 
		{
		  runaway () ;
		  {
		    if ( interaction == 3 ) 
		    ;
		    if ( filelineerrorstylep ) 
		    printfileline () ;
		    else printnl ( 264 ) ;
		    print ( 706 ) ;
		  } 
		  sprintcs ( warningindex ) ;
		  print ( 707 ) ;
		  {
		    helpptr = 3 ;
		    helpline [2 ]= 708 ;
		    helpline [1 ]= 709 ;
		    helpline [0 ]= 710 ;
		  } 
		  backerror () ;
		} 
		pstack [n ]= mem [memtop - 3 ].hh .v.RH ;
		alignstate = alignstate - unbalance ;
		{register integer for_end; m = 0 ;for_end = n ; if ( m <= 
		for_end) do 
		  flushlist ( pstack [m ]) ;
		while ( m++ < for_end ) ;} 
		goto lab10 ;
	      } 
	    } 
	    if ( curtok < 768 ) {
		
	      if ( curtok < 512 ) 
	      incr ( unbalance ) ;
	      else {
		  
		decr ( unbalance ) ;
		if ( unbalance == 0 ) 
		goto lab31 ;
	      } 
	    } 
	  } 
	  lab31: rbraceptr = p ;
	  {
	    q = getavail () ;
	    mem [p ].hh .v.RH = q ;
	    mem [q ].hh .v.LH = curtok ;
	    p = q ;
	  } 
	} 
	else {
	    
	  backinput () ;
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 698 ) ;
	  } 
	  sprintcs ( warningindex ) ;
	  print ( 699 ) ;
	  {
	    helpptr = 6 ;
	    helpline [5 ]= 700 ;
	    helpline [4 ]= 701 ;
	    helpline [3 ]= 702 ;
	    helpline [2 ]= 703 ;
	    helpline [1 ]= 704 ;
	    helpline [0 ]= 705 ;
	  } 
	  incr ( alignstate ) ;
	  longstate = 127 ;
	  curtok = partoken ;
	  inserror () ;
	  goto lab22 ;
	} 
      } 
      else {
	  
	if ( curtok == 2592 ) {
	    
	  if ( mem [r ].hh .v.LH <= 3584 ) {
	      
	    if ( mem [r ].hh .v.LH >= 3328 ) 
	    goto lab22 ;
	  } 
	} 
	{
	  q = getavail () ;
	  mem [p ].hh .v.RH = q ;
	  mem [q ].hh .v.LH = curtok ;
	  p = q ;
	} 
      } 
      incr ( m ) ;
      if ( mem [r ].hh .v.LH > 3584 ) 
      goto lab22 ;
      if ( mem [r ].hh .v.LH < 3328 ) 
      goto lab22 ;
      lab40: if ( s != -1073741823L ) 
      {
	if ( ( m == 1 ) && ( mem [p ].hh .v.LH < 768 ) && ( p != memtop - 3 
	) ) 
	{
	  mem [rbraceptr ].hh .v.RH = -1073741823L ;
	  {
	    mem [p ].hh .v.RH = avail ;
	    avail = p ;
	;
#ifdef STAT
	    decr ( dynused ) ;
#endif /* STAT */
	  } 
	  p = mem [memtop - 3 ].hh .v.RH ;
	  pstack [n ]= mem [p ].hh .v.RH ;
	  {
	    mem [p ].hh .v.RH = avail ;
	    avail = p ;
	;
#ifdef STAT
	    decr ( dynused ) ;
#endif /* STAT */
	  } 
	} 
	else pstack [n ]= mem [memtop - 3 ].hh .v.RH ;
	incr ( n ) ;
	if ( eqtb [29218 ].cint > 0 ) 
	{
	  begindiagnostic () ;
	  printnl ( matchchr ) ;
	  printint ( n ) ;
	  print ( 717 ) ;
	  showtokenlist ( pstack [n - 1 ], -1073741823L , 1000 ) ;
	  enddiagnostic ( false ) ;
	} 
      } 
    } while ( ! ( mem [r ].hh .v.LH == 3584 ) ) ;
  } 
  while ( ( curinput .statefield == 0 ) && ( curinput .locfield == 
  -1073741823L ) && ( curinput .indexfield != 2 ) ) endtokenlist () ;
  begintokenlist ( refcount , 5 ) ;
  curinput .namefield = warningindex ;
  curinput .locfield = mem [r ].hh .v.RH ;
  if ( n > 0 ) 
  {
    if ( paramptr + n > maxparamstack ) 
    {
      maxparamstack = paramptr + n ;
      if ( maxparamstack > paramsize ) 
      overflow ( 697 , paramsize ) ;
    } 
    {register integer for_end; m = 0 ;for_end = n - 1 ; if ( m <= for_end) 
    do 
      paramstack [paramptr + m ]= pstack [m ];
    while ( m++ < for_end ) ;} 
    paramptr = paramptr + n ;
  } 
  lab10: scannerstatus = savescannerstatus ;
  warningindex = savewarningindex ;
} 
void 
insertrelax ( void ) 
{
  insertrelax_regmem 
  curtok = 536870911L + curcs ;
  backinput () ;
  curtok = 536886432L ;
  backinput () ;
  curinput .indexfield = 4 ;
} 
void 
znewindex ( quarterword i , halfword q ) 
{
  newindex_regmem 
  smallnumber k  ;
  curptr = getnode ( 9 ) ;
  mem [curptr ].hh.b0 = i ;
  mem [curptr ].hh.b1 = 0 ;
  mem [curptr ].hh .v.RH = q ;
  {register integer for_end; k = 1 ;for_end = 8 ; if ( k <= for_end) do 
    mem [curptr + k ]= sanull ;
  while ( k++ < for_end ) ;} 
} 
void 
zfindsaelement ( smallnumber t , halfword n , boolean w ) 
{
  /* 45 46 47 48 49 50 10 */ findsaelement_regmem 
  halfword q  ;
  smallnumber i  ;
  curptr = saroot [t ];
  {
    if ( curptr == -1073741823L ) {
	
      if ( w ) 
      goto lab45 ;
      else return ;
    } 
  } 
  q = curptr ;
  i = n / 65536L ;
  if ( odd ( i ) ) 
  curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
  else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
  {
    if ( curptr == -1073741823L ) {
	
      if ( w ) 
      goto lab46 ;
      else return ;
    } 
  } 
  q = curptr ;
  i = ( n / 4096 ) % 16 ;
  if ( odd ( i ) ) 
  curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
  else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
  {
    if ( curptr == -1073741823L ) {
	
      if ( w ) 
      goto lab47 ;
      else return ;
    } 
  } 
  q = curptr ;
  i = ( n / 256 ) % 16 ;
  if ( odd ( i ) ) 
  curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
  else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
  {
    if ( curptr == -1073741823L ) {
	
      if ( w ) 
      goto lab48 ;
      else return ;
    } 
  } 
  q = curptr ;
  i = ( n / 16 ) % 16 ;
  if ( odd ( i ) ) 
  curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
  else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
  {
    if ( curptr == -1073741823L ) {
	
      if ( w ) 
      goto lab49 ;
      else return ;
    } 
  } 
  q = curptr ;
  i = n % 16 ;
  if ( odd ( i ) ) 
  curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
  else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
  if ( ( curptr == -1073741823L ) && w ) 
  goto lab50 ;
  return ;
  lab45: newindex ( t , -1073741823L ) ;
  saroot [t ]= curptr ;
  q = curptr ;
  i = n / 65536L ;
  lab46: newindex ( i , q ) ;
  {
    if ( odd ( i ) ) 
    mem [q + ( i / 2 ) + 1 ].hh .v.RH = curptr ;
    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = curptr ;
    incr ( mem [q ].hh.b1 ) ;
  } 
  q = curptr ;
  i = ( n / 4096 ) % 16 ;
  lab47: newindex ( i , q ) ;
  {
    if ( odd ( i ) ) 
    mem [q + ( i / 2 ) + 1 ].hh .v.RH = curptr ;
    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = curptr ;
    incr ( mem [q ].hh.b1 ) ;
  } 
  q = curptr ;
  i = ( n / 256 ) % 16 ;
  lab48: newindex ( i , q ) ;
  {
    if ( odd ( i ) ) 
    mem [q + ( i / 2 ) + 1 ].hh .v.RH = curptr ;
    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = curptr ;
    incr ( mem [q ].hh.b1 ) ;
  } 
  q = curptr ;
  i = ( n / 16 ) % 16 ;
  lab49: newindex ( i , q ) ;
  {
    if ( odd ( i ) ) 
    mem [q + ( i / 2 ) + 1 ].hh .v.RH = curptr ;
    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = curptr ;
    incr ( mem [q ].hh.b1 ) ;
  } 
  q = curptr ;
  i = n % 16 ;
  lab50: if ( t == 6 ) 
  {
    curptr = getnode ( 4 ) ;
    mem [curptr + 1 ]= sanull ;
    mem [curptr + 2 ]= sanull ;
    mem [curptr + 3 ]= sanull ;
  } 
  else {
      
    if ( t <= 1 ) 
    {
      curptr = getnode ( 3 ) ;
      mem [curptr + 2 ].cint = 0 ;
      mem [curptr + 1 ].hh .v.RH = n ;
    } 
    else {
	
      curptr = getnode ( 2 ) ;
      if ( t <= 3 ) 
      {
	mem [curptr + 1 ].hh .v.RH = membot ;
	incr ( mem [membot ].hh .v.RH ) ;
      } 
      else mem [curptr + 1 ].hh .v.RH = -1073741823L ;
    } 
    mem [curptr + 1 ].hh .v.LH = -1073741823L ;
  } 
  mem [curptr ].hh.b0 = 16 * t + i ;
  mem [curptr ].hh.b1 = 1 ;
  mem [curptr ].hh .v.RH = q ;
  {
    if ( odd ( i ) ) 
    mem [q + ( i / 2 ) + 1 ].hh .v.RH = curptr ;
    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = curptr ;
    incr ( mem [q ].hh.b1 ) ;
  } 
} 
void 
expand ( void ) 
{
  /* 21 */ expand_regmem 
  halfword t  ;
  halfword p, q, r  ;
  integer j  ;
  integer cvbackup  ;
  smallnumber cvlbackup, radixbackup, cobackup  ;
  halfword backupbackup  ;
  smallnumber savescannerstatus  ;
  incr ( expanddepthcount ) ;
  if ( expanddepthcount >= expanddepth ) 
  overflow ( 676 , expanddepth ) ;
  cvbackup = curval ;
  cvlbackup = curvallevel ;
  radixbackup = radix ;
  cobackup = curorder ;
  backupbackup = mem [memtop - 13 ].hh .v.RH ;
  lab21: if ( curcmd < 127 ) 
  {
    if ( eqtb [29224 ].cint > 1 ) 
    showcurcmdchr () ;
    switch ( curcmd ) 
    {case 126 : 
      {
	t = curchr % 5 ;
	if ( curchr >= 5 ) 
	scanregisternum () ;
	else curval = 0 ;
	if ( curval == 0 ) 
	curptr = curmark [t ];
	else {
	    
	  findsaelement ( 6 , curval , false ) ;
	  if ( curptr != -1073741823L ) {
	      
	    if ( odd ( t ) ) 
	    curptr = mem [curptr + ( t / 2 ) + 1 ].hh .v.RH ;
	    else curptr = mem [curptr + ( t / 2 ) + 1 ].hh .v.LH ;
	  } 
	} 
	if ( curptr != -1073741823L ) 
	begintokenlist ( curptr , 14 ) ;
      } 
      break ;
    case 118 : 
      if ( curchr == 0 ) 
      {
	gettoken () ;
	t = curtok ;
	gettoken () ;
	if ( curcmd > 116 ) 
	expand () ;
	else backinput () ;
	curtok = t ;
	backinput () ;
      } 
      else {
	  
	gettoken () ;
	if ( ( curcmd == 121 ) && ( curchr != 16 ) ) 
	{
	  curchr = curchr + 32 ;
	  goto lab21 ;
	} 
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 751 ) ;
	} 
	printesc ( 871 ) ;
	print ( 1531 ) ;
	printcmdchr ( curcmd , curchr ) ;
	printchar ( 39 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 672 ;
	} 
	backerror () ;
      } 
      break ;
    case 119 : 
      if ( curchr == 0 ) 
      {
	savescannerstatus = scannerstatus ;
	scannerstatus = 0 ;
	gettoken () ;
	scannerstatus = savescannerstatus ;
	t = curtok ;
	backinput () ;
	if ( t >= 536870911L ) 
	{
	  p = getavail () ;
	  mem [p ].hh .v.LH = 536886434L ;
	  mem [p ].hh .v.RH = curinput .locfield ;
	  curinput .startfield = p ;
	  curinput .locfield = p ;
	} 
      } 
      else {
	  
	savescannerstatus = scannerstatus ;
	scannerstatus = 0 ;
	gettoken () ;
	scannerstatus = savescannerstatus ;
	if ( curcs < 514 ) 
	curcs = primlookup ( curcs - 257 ) ;
	else curcs = primlookup ( hash [curcs ].v.RH ) ;
	if ( curcs != 0 ) 
	{
	  t = primeqtb [curcs ].hh.b0 ;
	  if ( t > 116 ) 
	  {
	    curcmd = t ;
	    curchr = primeqtb [curcs ].hh .v.RH ;
	    curtok = ( curcmd * 256 ) + curchr ;
	    curcs = 0 ;
	    goto lab21 ;
	  } 
	  else {
	      
	    backinput () ;
	    p = getavail () ;
	    mem [p ].hh .v.LH = 536886436L ;
	    mem [p ].hh .v.RH = curinput .locfield ;
	    curinput .locfield = p ;
	    curinput .startfield = p ;
	  } 
	} 
	else {
	    
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 677 ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 678 ;
	    helpline [0 ]= 679 ;
	  } 
	  backerror () ;
	} 
      } 
      break ;
    case 123 : 
      {
	r = getavail () ;
	p = r ;
	do {
	    getxtoken () ;
	  if ( curcs == 0 ) 
	  {
	    q = getavail () ;
	    mem [p ].hh .v.RH = q ;
	    mem [q ].hh .v.LH = curtok ;
	    p = q ;
	  } 
	} while ( ! ( curcs != 0 ) ) ;
	if ( curcmd != 72 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 686 ) ;
	  } 
	  printesc ( 547 ) ;
	  print ( 687 ) ;
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 688 ;
	    helpline [0 ]= 689 ;
	  } 
	  backerror () ;
	} 
	j = first ;
	p = mem [r ].hh .v.RH ;
	while ( p != -1073741823L ) {
	    
	  if ( j >= maxbufstack ) 
	  {
	    maxbufstack = j + 1 ;
	    if ( maxbufstack == bufsize ) 
	    overflow ( 258 , bufsize ) ;
	  } 
	  if ( checkkanji ( mem [p ].hh .v.LH ) ) 
	  {
	    t = toBUFF ( mem [p ].hh .v.LH % 16777216L ) ;
	    if ( BYTE1 ( t ) != 0 ) 
	    {
	      buffer [j ]= BYTE1 ( t ) ;
	      incr ( j ) ;
	    } 
	    if ( BYTE2 ( t ) != 0 ) 
	    {
	      buffer [j ]= BYTE2 ( t ) ;
	      incr ( j ) ;
	    } 
	    if ( BYTE3 ( t ) != 0 ) 
	    {
	      buffer [j ]= BYTE3 ( t ) ;
	      incr ( j ) ;
	    } 
	    buffer [j ]= BYTE4 ( t ) ;
	    incr ( j ) ;
	    p = mem [p ].hh .v.RH ;
	  } 
	  else {
	      
	    buffer [j ]= mem [p ].hh .v.LH % 256 ;
	    incr ( j ) ;
	    p = mem [p ].hh .v.RH ;
	  } 
	} 
	if ( j > first + 1 ) 
	{
	  nonewcontrolsequence = false ;
	  curcs = idlookup ( first , j - first ) ;
	  nonewcontrolsequence = true ;
	} 
	else if ( j == first ) 
	curcs = 513 ;
	else curcs = 257 + buffer [first ];
	flushlist ( r ) ;
	if ( eqtb [curcs ].hh.b0 == 117 ) 
	{
	  eqdefine ( curcs , 0 , 256 ) ;
	} 
	curtok = curcs + 536870911L ;
	backinput () ;
      } 
      break ;
    case 124 : 
      convtoks () ;
      break ;
    case 125 : 
      insthetoks () ;
      break ;
    case 121 : 
      conditional () ;
      break ;
    case 122 : 
      {
	if ( eqtb [29254 ].cint > 0 ) {
	    
	  if ( eqtb [29224 ].cint <= 1 ) 
	  showcurcmdchr () ;
	} 
	if ( curchr > iflimit ) {
	    
	  if ( iflimit == 1 ) 
	  insertrelax () ;
	  else {
	      
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 264 ) ;
	      print ( 875 ) ;
	    } 
	    printcmdchr ( 122 , curchr ) ;
	    {
	      helpptr = 1 ;
	      helpline [0 ]= 876 ;
	    } 
	    error () ;
	  } 
	} 
	else {
	    
	  while ( curchr != 2 ) passtext () ;
	  {
	    if ( ifstack [inopen ]== condptr ) 
	    ifwarning () ;
	    p = condptr ;
	    ifline = mem [p + 1 ].cint ;
	    curif = mem [p ].hh.b1 ;
	    iflimit = mem [p ].hh.b0 ;
	    condptr = mem [p ].hh .v.RH ;
	    freenode ( p , 2 ) ;
	  } 
	} 
      } 
      break ;
    case 120 : 
      if ( curchr == 1 ) 
      forceeof = true ;
      else if ( curchr == 2 ) 
      pseudostart () ;
      else if ( nameinprogress ) 
      insertrelax () ;
      else startinput () ;
      break ;
      default: 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 680 ) ;
	} 
	{
	  helpptr = 5 ;
	  helpline [4 ]= 681 ;
	  helpline [3 ]= 682 ;
	  helpline [2 ]= 683 ;
	  helpline [1 ]= 684 ;
	  helpline [0 ]= 685 ;
	} 
	error () ;
      } 
      break ;
    } 
  } 
  else if ( curcmd < 131 ) 
  macrocall () ;
  else {
      
    curtok = 536886431L ;
    backinput () ;
  } 
  curval = cvbackup ;
  curvallevel = cvlbackup ;
  radix = radixbackup ;
  curorder = cobackup ;
  mem [memtop - 13 ].hh .v.RH = backupbackup ;
  decr ( expanddepthcount ) ;
} 
void 
getxtoken ( void ) 
{
  /* 20 30 */ getxtoken_regmem 
  lab20: getnext () ;
  if ( curcmd <= 116 ) 
  goto lab30 ;
  if ( curcmd >= 127 ) {
      
    if ( curcmd < 131 ) 
    macrocall () ;
    else {
	
      curcs = 15520 ;
      curcmd = 9 ;
      goto lab30 ;
    } 
  } 
  else expand () ;
  goto lab20 ;
  lab30: if ( curcs == 0 ) {
      
    if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
    curtok = ( curcmd * 16777216L ) + curchr ;
    else curtok = ( curcmd * 256 ) + curchr ;
  } 
  else curtok = 536870911L + curcs ;
} 
void 
xtoken ( void ) 
{
  xtoken_regmem 
  while ( curcmd > 116 ) {
      
    expand () ;
    getnext () ;
  } 
  if ( curcs == 0 ) {
      
    if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
    curtok = ( curcmd * 16777216L ) + curchr ;
    else curtok = ( curcmd * 256 ) + curchr ;
  } 
  else curtok = 536870911L + curcs ;
} 
void 
scanleftbrace ( void ) 
{
  scanleftbrace_regmem 
  do {
      getxtoken () ;
  } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
  if ( curcmd != 1 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 718 ) ;
    } 
    {
      helpptr = 4 ;
      helpline [3 ]= 719 ;
      helpline [2 ]= 720 ;
      helpline [1 ]= 721 ;
      helpline [0 ]= 722 ;
    } 
    backerror () ;
    curtok = 379 ;
    curcmd = 1 ;
    curchr = 123 ;
    incr ( alignstate ) ;
  } 
} 
void 
scanoptionalequals ( void ) 
{
  scanoptionalequals_regmem 
  do {
      getxtoken () ;
  } while ( ! ( curcmd != 10 ) ) ;
  if ( curtok != 3133 ) 
  backinput () ;
} 
boolean 
zscankeyword ( strnumber s ) 
{
  /* 10 */ register boolean Result; scankeyword_regmem 
  halfword p  ;
  halfword q  ;
  poolpointer k  ;
  p = memtop - 13 ;
  mem [p ].hh .v.RH = -1073741823L ;
  k = strstart [s ];
  while ( k < strstart [s + 1 ]) {
      
    getxtoken () ;
    if ( ( curcs == 0 ) && ( ( curchr == strpool [k ]) || ( curchr == 
    strpool [k ]- 32 ) ) ) 
    {
      {
	q = getavail () ;
	mem [p ].hh .v.RH = q ;
	mem [q ].hh .v.LH = curtok ;
	p = q ;
      } 
      incr ( k ) ;
    } 
    else if ( ( curcmd != 10 ) || ( p != memtop - 13 ) ) 
    {
      backinput () ;
      if ( p != memtop - 13 ) 
      begintokenlist ( mem [memtop - 13 ].hh .v.RH , 3 ) ;
      Result = false ;
      return Result ;
    } 
  } 
  flushlist ( mem [memtop - 13 ].hh .v.RH ) ;
  Result = true ;
  return Result ;
} 
void 
muerror ( void ) 
{
  muerror_regmem 
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 723 ) ;
  } 
  {
    helpptr = 1 ;
    helpline [0 ]= 724 ;
  } 
  error () ;
} 
void 
scaneightbitint ( void ) 
{
  scaneightbitint_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 255 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 753 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 754 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
} 
void 
scancharnum ( void ) 
{
  scancharnum_regmem 
  scanint () ;
  if ( ! ischarascii ( curval ) && ! ischarkanji ( curval ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 755 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 756 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
} 
void 
scanfourbitint ( void ) 
{
  scanfourbitint_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 15 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 757 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 758 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
} 
void 
scanbigfourbitint ( void ) 
{
  scanbigfourbitint_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 255 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 757 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 759 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
} 
void 
scanfifteenbitint ( void ) 
{
  scanfifteenbitint_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 32767 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 760 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 761 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
  curval = ( ( curval / 4096 ) * 65536L ) + ( curval % 4096 ) ;
} 
void 
scanrealfifteenbitint ( void ) 
{
  scanrealfifteenbitint_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 32767 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 760 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 761 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
} 
void 
scanbigfifteenbitint ( void ) 
{
  scanbigfifteenbitint_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 134217727L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 762 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 763 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
  curval = ( ( curval / 65536L ) * 256 ) + ( curval % 256 ) ;
} 
void 
scanomegafifteenbitint ( void ) 
{
  scanomegafifteenbitint_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 134217727L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 762 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 763 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
} 
void 
scantwentysevenbitint ( void ) 
{
  scantwentysevenbitint_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 134217727L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 764 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 729 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
  curval1 = curval % 4096 ;
  curval = curval / 4096 ;
  curval = ( ( curval / 4096 ) * 65536L ) + ( curval % 4096 ) ;
} 
void 
scanfiftyonebitint ( void ) 
{
  scanfiftyonebitint_regmem 
  integer iiii  ;
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 134217727L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 764 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 765 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
  iiii = ( ( curval / 65536L ) * 256 ) + ( curval % 256 ) ;
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 16777215L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 764 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 766 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
  curval1 = ( ( curval / 65536L ) * 256 ) + ( curval % 256 ) ;
  curval = iiii ;
} 
void 
scanregisternum ( void ) 
{
  scanregisternum_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( curval > maxregnum ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 753 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= maxreghelpline ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
} 
void 
scanfourbitintor18 ( void ) 
{
  scanfourbitintor18_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( ( curval > 15 ) && ( curval != 18 ) ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 757 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 758 ;
      helpline [0 ]= 727 ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
} 
void 
getxorprotected ( void ) 
{
  /* 10 */ getxorprotected_regmem 
  while ( true ) {
      
    gettoken () ;
    if ( curcmd <= 116 ) 
    return ;
    if ( ( curcmd >= 127 ) && ( curcmd < 131 ) ) {
	
      if ( mem [mem [curchr ].hh .v.RH ].hh .v.LH == 3585 ) 
      return ;
    } 
    expand () ;
  } 
} 
integer 
zeffectivechar ( boolean errp , internalfontnumber f , quarterword c ) 
{
  /* 40 */ register integer Result; effectivechar_regmem 
  integer basec  ;
  integer result  ;
  result = c ;
  if ( ! mltexenabledp ) 
  goto lab40 ;
  if ( fontec [f ]>= c ) {
      
    if ( fontbc [f ]<= c ) {
	
      if ( ( fontinfo [charbase [f ]+ c ].qqqq .b0 > 0 ) ) 
      goto lab40 ;
    } 
  } 
  if ( c >= eqtb [29248 ].cint ) {
      
    if ( c <= eqtb [29249 ].cint ) {
	
      if ( ( eqtb [28932 + c ].hh .v.RH > 0 ) ) 
      {
	basec = ( eqtb [28932 + c ].hh .v.RH % 256 ) ;
	result = basec ;
	if ( ! errp ) 
	goto lab40 ;
	if ( fontec [f ]>= basec ) {
	    
	  if ( fontbc [f ]<= basec ) {
	      
	    if ( ( fontinfo [charbase [f ]+ basec ].qqqq .b0 > 0 ) ) 
	    goto lab40 ;
	  } 
	} 
      } 
    } 
  } 
  if ( errp ) 
  {
    begindiagnostic () ;
    printnl ( 923 ) ;
    print ( 1564 ) ;
    print ( c ) ;
    print ( 924 ) ;
    slowprint ( fontname [f ]) ;
    printchar ( 33 ) ;
    enddiagnostic ( false ) ;
    result = fontbc [f ];
  } 
  lab40: Result = result ;
  return Result ;
} 
void 
scanfontident ( void ) 
{
  scanfontident_regmem 
  internalfontnumber f  ;
  halfword m  ;
  do {
      getxtoken () ;
  } while ( ! ( curcmd != 10 ) ) ;
  if ( curcmd == 101 ) 
  f = eqtb [26357 ].hh .v.RH ;
  else if ( curcmd == 102 ) 
  f = eqtb [26358 ].hh .v.RH ;
  else if ( curcmd == 100 ) 
  f = eqtb [25588 ].hh .v.RH ;
  else if ( curcmd == 99 ) 
  f = curchr ;
  else if ( curcmd == 98 ) 
  {
    m = curchr ;
    scanbigfourbitint () ;
    f = eqtb [m + curval ].hh .v.RH ;
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 915 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 916 ;
      helpline [0 ]= 917 ;
    } 
    backerror () ;
    f = 0 ;
  } 
  curval = f ;
} 
void 
zfindfontdimen ( boolean writing ) 
{
  findfontdimen_regmem 
  internalfontnumber f  ;
  integer n  ;
  scanint () ;
  n = curval ;
  scanfontident () ;
  f = curval ;
  if ( n <= 0 ) 
  curval = fmemptr ;
  else {
      
    if ( writing && ( n <= 4 ) && ( n >= 2 ) && ( fontglue [f ]!= 
    -1073741823L ) ) 
    {
      deleteglueref ( fontglue [f ]) ;
      fontglue [f ]= -1073741823L ;
    } 
    if ( n > fontparams [f ]) {
	
      if ( f < fontptr ) 
      curval = fmemptr ;
      else {
	  
	do {
	    if ( fmemptr == fontmemsize ) 
	  overflow ( 922 , fontmemsize ) ;
	  fontinfo [fmemptr ].cint = 0 ;
	  incr ( fmemptr ) ;
	  incr ( fontparams [f ]) ;
	} while ( ! ( n == fontparams [f ]) ) ;
	curval = fmemptr - 1 ;
      } 
    } 
    else curval = n + parambase [f ];
  } 
  if ( curval == fmemptr ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 900 ) ;
    } 
    printesc ( hash [15526 + f ].v.RH ) ;
    print ( 918 ) ;
    printint ( fontparams [f ]) ;
    print ( 919 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 920 ;
      helpline [0 ]= 921 ;
    } 
    error () ;
  } 
} 
eightbits 
zgetjfmpos ( KANJIcode kcode , internalfontnumber f ) 
{
  register eightbits Result; getjfmpos_regmem 
  KANJIcode jc  ;
  halfword sp, mp, ep  ;
  if ( f == 0 ) 
  {
    Result = fontinfo [ctypebase [0 ]+ 0 ].hh .lhfield ;
    return Result ;
  } 
  jc = toDVI ( kcode ) ;
  sp = 1 ;
  ep = fontnumext [f ]- 1 ;
  if ( ( ep >= 1 ) && ( fontinfo [ctypebase [f ]+ sp ].hh .v.RH <= jc ) && 
  ( jc <= fontinfo [ctypebase [f ]+ ep ].hh .v.RH ) ) 
  {
    while ( ( sp <= ep ) ) {
	
      mp = sp + ( ( ep - sp ) / 2 ) ;
      if ( jc < fontinfo [ctypebase [f ]+ mp ].hh .v.RH ) 
      ep = mp - 1 ;
      else if ( jc > fontinfo [ctypebase [f ]+ mp ].hh .v.RH ) 
      sp = mp + 1 ;
      else {
	  
	Result = fontinfo [ctypebase [f ]+ mp ].hh .lhfield ;
	return Result ;
      } 
    } 
  } 
  Result = fontinfo [ctypebase [f ]+ 0 ].hh .lhfield ;
  return Result ;
} 
void 
zprintkansuji ( integer n ) 
{
  printkansuji_regmem 
  unsigned char k  ;
  KANJIcode cx  ;
  k = 0 ;
  if ( n < 0 ) 
  return ;
  do {
      dig [k ]= n % 10 ;
    n = n / 10 ;
    incr ( k ) ;
  } while ( ! ( n == 0 ) ) ;
  {
    while ( k > 0 ) {
	
      decr ( k ) ;
      cx = eqtb [27898 + dig [k ]].hh .v.RH ;
      printkanji ( fromDVI ( cx ) ) ;
    } 
  } 
} 
halfword 
zgetinhibitpos ( KANJIcode c , smallnumber n ) 
{
  /* 30 31 */ register halfword Result; getinhibitpos_regmem 
  halfword p, s  ;
  s = calcpos ( c ) ;
  p = s ;
  if ( n == 0 ) 
  {
    do {
	if ( ( eqtb [27386 + p ].hh .v.RH == 0 ) || ( eqtb [27386 + p ]
      .hh .v.RH == c ) ) 
      goto lab30 ;
      incr ( p ) ;
      if ( p > 255 ) 
      p = 0 ;
    } while ( ! ( s == p ) ) ;
    p = 1000 ;
  } 
  else {
      
    do {
	if ( eqtb [27386 + p ].hh .v.RH == 0 ) 
      goto lab31 ;
      if ( eqtb [27386 + p ].hh .v.RH == c ) 
      goto lab30 ;
      incr ( p ) ;
      if ( p > 255 ) 
      p = 0 ;
    } while ( ! ( s == p ) ) ;
    lab31: p = 1000 ;
  } 
  lab30: Result = p ;
  return Result ;
} 
halfword 
zgetkinsokupos ( KANJIcode c , smallnumber n ) 
{
  /* 30 31 */ register halfword Result; getkinsokupos_regmem 
  halfword p, s  ;
  s = calcpos ( c ) ;
  p = s ;
	;
#ifdef TEXMF_DEBUG
  println () ;
  print ( 1596 ) ;
  printint ( c ) ;
  print ( 1597 ) ;
  printint ( s ) ;
  if ( p + 27642 < 0 ) 
  {
    print ( 1598 ) ;
    println () ;
  } 
#endif /* TEXMF_DEBUG */
  if ( n == 0 ) 
  {
    do {
	if ( ( eqtb [27642 + p ].hh.b0 == 0 ) || ( eqtb [27642 + p ].hh 
      .v.RH == c ) ) 
      goto lab30 ;
      incr ( p ) ;
      if ( p > 255 ) 
      p = 0 ;
    } while ( ! ( s == p ) ) ;
    p = 1000 ;
  } 
  else {
      
    do {
	if ( eqtb [27642 + p ].hh.b0 == 0 ) 
      goto lab31 ;
      if ( eqtb [27642 + p ].hh .v.RH == c ) 
      goto lab30 ;
      incr ( p ) ;
      if ( p > 255 ) 
      p = 0 ;
    } while ( ! ( s == p ) ) ;
    lab31: p = 1000 ;
  } 
  lab30: Result = p ;
  return Result ;
} 
void 
zscansomethinginternal ( smallnumber level , boolean negative ) 
{
  /* 10 20 */ scansomethinginternal_regmem 
  halfword m  ;
  halfword tx  ;
  halfword qx  ;
  fourquarters i  ;
  integer p  ;
  halfword q, r  ;
  lab20: m = curchr ;
  switch ( curcmd ) 
  {case 88 : 
    {
      scanint () ;
      q = getkinsokupos ( curval , 1 ) ;
      curvallevel = 0 ;
      curval = 0 ;
      if ( ( q != 1000 ) && ( m == eqtb [27642 + q ].hh.b0 ) ) 
      {
	curval = eqtb [30055 + q ].cint ;
	curvallevel = 0 ;
      } 
    } 
    break ;
  case 89 : 
    {
      scanint () ;
      q = getinhibitpos ( curval , 1 ) ;
      curvallevel = 0 ;
      curval = 3 ;
      if ( q != 1000 ) 
      curval = eqtb [27386 + q ].hh.b0 ;
    } 
    break ;
  case 97 : 
    {
      scancharnum () ;
      if ( m == 28676 ) 
      {
	curval1 = eqtb [28676 + curval ].hh .v.RH ;
	if ( ( ( curval1 / 65536L ) > 8 ) || ( ( ( curval1 % 65536L ) / 256 ) 
	> 15 ) ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 725 ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 726 ;
	    helpline [0 ]= 727 ;
	  } 
	  interror ( curval1 ) ;
	  {
	    curval = 0 ;
	    curvallevel = 0 ;
	  } 
	} 
	curval1 = ( curval1 / 65536L ) * 4096 + curval1 % 4096 ;
	{
	  curval = curval1 ;
	  curvallevel = 0 ;
	} 
      } 
      else if ( m == ( 28804 ) ) 
      {
	curval1 = eqtb [28676 + curval ].hh .v.RH ;
	curval = ( curval1 / 65536L ) * 16777216L + ( ( curval1 / 256 ) % 256 
	) * 65536L + ( curval1 % 256 ) ;
	{
	  curval = curval ;
	  curvallevel = 0 ;
	} 
      } 
      else if ( m == 29518 ) 
      {
	curval1 = eqtb [29518 + curval ].cint ;
	curval = getintone ( eqtb [29518 + curval ]) ;
	if ( ( ( curval1 / 256 ) % 256 >= 16 ) || ( curval >= 4096 ) ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 728 ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 729 ;
	    helpline [0 ]= 727 ;
	  } 
	  error () ;
	  {
	    curval = 0 ;
	    curvallevel = 0 ;
	  } 
	} 
	else {
	    
	  curval = curval1 * 4096 + curval ;
	  curvallevel = 0 ;
	} 
      } 
      else if ( m == ( 29646 ) ) 
      {
	{
	  curval = -1 ;
	  curvallevel = 0 ;
	} 
      } 
      else if ( m == 26618 ) 
      {
	curval = eqtb [m + kcatcodekey ( curval ) ].hh .v.RH ;
	curvallevel = 0 ;
      } 
      else if ( m < 28676 ) 
      {
	if ( ! ischarascii ( curval ) ) 
	{
	  curval = eqtb [m + Hi ( curval ) ].hh .v.RH ;
	  curvallevel = 0 ;
	} 
	else {
	    
	  curval = eqtb [m + curval ].hh .v.RH ;
	  curvallevel = 0 ;
	} 
      } 
      else {
	  
	if ( ! ischarascii ( curval ) ) 
	{
	  curval = eqtb [m + Hi ( curval ) ].cint ;
	  curvallevel = 0 ;
	} 
	else {
	    
	  curval = eqtb [m + curval ].cint ;
	  curvallevel = 0 ;
	} 
      } 
    } 
    break ;
  case 80 : 
  case 81 : 
  case 98 : 
  case 99 : 
  case 100 : 
  case 101 : 
  case 102 : 
    if ( level != 5 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 730 ) ;
      } 
      {
	helpptr = 3 ;
	helpline [2 ]= 731 ;
	helpline [1 ]= 732 ;
	helpline [0 ]= 733 ;
      } 
      backerror () ;
      {
	curval = 0 ;
	curvallevel = 1 ;
      } 
    } 
    else if ( curcmd <= 81 ) 
    {
      if ( curcmd < 81 ) {
	  
	if ( m == membot ) 
	{
	  scanregisternum () ;
	  if ( curval < 256 ) 
	  curval = eqtb [25072 + curval ].hh .v.RH ;
	  else {
	      
	    findsaelement ( 5 , curval , false ) ;
	    if ( curptr == -1073741823L ) 
	    curval = -1073741823L ;
	    else curval = mem [curptr + 1 ].hh .v.RH ;
	  } 
	} 
	else curval = mem [m + 1 ].hh .v.RH ;
      } 
      else curval = eqtb [m ].hh .v.RH ;
      curvallevel = 5 ;
    } 
    else {
	
      backinput () ;
      scanfontident () ;
      {
	curval = 15526 + curval ;
	curvallevel = 4 ;
      } 
    } 
    break ;
  case 82 : 
    {
      curval = eqtb [m ].cint ;
      curvallevel = 0 ;
    } 
    break ;
  case 83 : 
    {
      curval = eqtb [m ].cint ;
      curvallevel = 1 ;
    } 
    break ;
  case 84 : 
    {
      curval = eqtb [m ].hh .v.RH ;
      curvallevel = 2 ;
    } 
    break ;
  case 85 : 
    {
      curval = eqtb [m ].hh .v.RH ;
      curvallevel = 3 ;
    } 
    break ;
  case 91 : 
    if ( abs ( curlist .modefield ) != m ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 746 ) ;
      } 
      printcmdchr ( 91 , m ) ;
      {
	helpptr = 4 ;
	helpline [3 ]= 747 ;
	helpline [2 ]= 748 ;
	helpline [1 ]= 749 ;
	helpline [0 ]= 750 ;
      } 
      error () ;
      if ( level != 5 ) 
      {
	curval = 0 ;
	curvallevel = 1 ;
      } 
      else {
	  
	curval = 0 ;
	curvallevel = 0 ;
      } 
    } 
    else if ( m == 1 ) 
    {
      curval = curlist .auxfield .cint ;
      curvallevel = 1 ;
    } 
    else {
	
      curval = curlist .auxfield .hh .v.LH ;
      curvallevel = 0 ;
    } 
    break ;
  case 92 : 
    if ( curlist .modefield == 0 ) 
    {
      curval = 0 ;
      curvallevel = 0 ;
    } 
    else {
	
      nest [nestptr ]= curlist ;
      p = nestptr ;
      while ( abs ( nest [p ].modefield ) != 1 ) decr ( p ) ;
      {
	curval = nest [p ].pgfield ;
	curvallevel = 0 ;
      } 
    } 
    break ;
  case 94 : 
    {
      if ( m == 0 ) 
      curval = deadcycles ;
      else if ( m == 2 ) 
      curval = interaction ;
      else curval = insertpenalties ;
      curvallevel = 0 ;
    } 
    break ;
  case 93 : 
    {
      if ( ( pagecontents == 0 ) && ( ! outputactive ) ) {
	  
	if ( m == 0 ) 
	curval = 1073741823L ;
	else curval = 0 ;
      } 
      else curval = pagesofar [m ];
      curvallevel = 1 ;
    } 
    break ;
  case 96 : 
    {
      if ( m > 25061 ) 
      {
	scanint () ;
	if ( ( eqtb [m ].hh .v.RH == -1073741823L ) || ( curval < 0 ) ) 
	curval = 0 ;
	else {
	    
	  if ( curval > mem [eqtb [m ].hh .v.RH + 1 ].cint ) 
	  curval = mem [eqtb [m ].hh .v.RH + 1 ].cint ;
	  curval = mem [eqtb [m ].hh .v.RH + curval + 1 ].cint ;
	} 
      } 
      else if ( eqtb [25061 ].hh .v.RH == -1073741823L ) 
      curval = 0 ;
      else curval = mem [eqtb [25061 ].hh .v.RH ].hh .v.LH ;
      curvallevel = 0 ;
    } 
    break ;
  case 95 : 
    {
      scanregisternum () ;
      if ( curval < 256 ) 
      q = eqtb [25332 + curval ].hh .v.RH ;
      else {
	  
	findsaelement ( 4 , curval , false ) ;
	if ( curptr == -1073741823L ) 
	q = -1073741823L ;
	else q = mem [curptr + 1 ].hh .v.RH ;
      } 
      if ( q == -1073741823L ) 
      curval = 0 ;
      else {
	  
	qx = q ;
	while ( ( q != -1073741823L ) && ( ( ( mem [q ].hh.b1 ) % 8 ) != abs 
	( curlist .dirfield ) ) ) q = mem [q ].hh .v.RH ;
	if ( q == -1073741823L ) 
	{
	  r = mem [qx ].hh .v.RH ;
	  mem [qx ].hh .v.RH = -1073741823L ;
	  q = newdirnode ( qx , abs ( curlist .dirfield ) ) ;
	  mem [qx ].hh .v.RH = r ;
	  curval = mem [q + m ].cint ;
	  deleteglueref ( mem [q + 7 ].hh .v.RH ) ;
	  deleteglueref ( mem [q + 7 ].hh .v.LH ) ;
	  freenode ( q , 10 ) ;
	} 
	else curval = mem [q + m ].cint ;
      } 
      curvallevel = 1 ;
    } 
    break ;
  case 74 : 
  case 76 : 
  case 73 : 
  case 75 : 
    {
      curval = curchr ;
      curvallevel = 0 ;
    } 
    break ;
  case 86 : 
    {
      findfontdimen ( false ) ;
      fontinfo [fmemptr ].cint = 0 ;
      {
	curval = fontinfo [curval ].cint ;
	curvallevel = 1 ;
      } 
    } 
    break ;
  case 87 : 
    {
      scanfontident () ;
      if ( m == 0 ) 
      {
	curval = hyphenchar [curval ];
	curvallevel = 0 ;
      } 
      else {
	  
	curval = skewchar [curval ];
	curvallevel = 0 ;
      } 
    } 
    break ;
  case 103 : 
    {
      if ( ( m < membot ) || ( m > membot + 23 ) ) 
      {
	curvallevel = ( mem [m ].hh.b0 / 16 ) ;
	if ( curvallevel < 2 ) 
	curval = mem [m + 2 ].cint ;
	else curval = mem [m + 1 ].hh .v.RH ;
      } 
      else {
	  
	scanregisternum () ;
	curvallevel = m - membot ;
	if ( curval > 255 ) 
	{
	  findsaelement ( curvallevel , curval , false ) ;
	  if ( curptr == -1073741823L ) {
	      
	    if ( curvallevel < 2 ) 
	    curval = 0 ;
	    else curval = membot ;
	  } 
	  else if ( curvallevel < 2 ) 
	  curval = mem [curptr + 2 ].cint ;
	  else curval = mem [curptr + 1 ].hh .v.RH ;
	} 
	else switch ( curvallevel ) 
	{case 0 : 
	  curval = eqtb [29262 + curval ].cint ;
	  break ;
	case 1 : 
	  curval = eqtb [29799 + curval ].cint ;
	  break ;
	case 2 : 
	  curval = eqtb [24549 + curval ].hh .v.RH ;
	  break ;
	case 3 : 
	  curval = eqtb [24805 + curval ].hh .v.RH ;
	  break ;
	} 
      } 
    } 
    break ;
  case 77 : 
    if ( m >= 5 ) {
	
      if ( m >= 27 ) 
      {
	if ( m < 28 ) 
	{
	  switch ( m ) 
	  {case 27 : 
	    scanmuglue () ;
	    break ;
	  } 
	  curvallevel = 2 ;
	} 
	else if ( m < 29 ) 
	{
	  switch ( m ) 
	  {case 28 : 
	    scannormalglue () ;
	    break ;
	  } 
	  curvallevel = 3 ;
	} 
	else {
	    
	  curvallevel = m - 29 ;
	  scanexpr () ;
	} 
	while ( curvallevel > level ) {
	    
	  if ( curvallevel == 2 ) 
	  {
	    m = curval ;
	    curval = mem [m + 1 ].cint ;
	    deleteglueref ( m ) ;
	  } 
	  else if ( curvallevel == 3 ) 
	  muerror () ;
	  decr ( curvallevel ) ;
	} 
	if ( negative ) {
	    
	  if ( curvallevel >= 2 ) 
	  {
	    m = curval ;
	    curval = newspec ( m ) ;
	    deleteglueref ( m ) ;
	    {
	      mem [curval + 1 ].cint = - (integer) mem [curval + 1 ].cint 
	      ;
	      mem [curval + 2 ].cint = - (integer) mem [curval + 2 ].cint 
	      ;
	      mem [curval + 3 ].cint = - (integer) mem [curval + 3 ].cint 
	      ;
	    } 
	  } 
	  else curval = - (integer) curval ;
	} 
	return ;
      } 
      else if ( m >= 18 ) 
      {
	switch ( m ) 
	{case 18 : 
	case 19 : 
	case 20 : 
	case 21 : 
	  {
	    scanfontident () ;
	    q = curval ;
	    scancharnum () ;
	    if ( fontdir [q ]!= 0 ) 
	    {
	      if ( curval >= 256 ) 
	      {
		curval = getjfmpos ( curval , q ) ;
		i = fontinfo [charbase [q ]+ curval ].qqqq ;
		switch ( m ) 
		{case 18 : 
		  curval = fontinfo [widthbase [q ]+ i .b0 ].cint ;
		  break ;
		case 19 : 
		  curval = fontinfo [heightbase [q ]+ ( i .b1 ) / 16 ]
		  .cint ;
		  break ;
		case 20 : 
		  curval = fontinfo [depthbase [q ]+ ( i .b1 ) % 16 ].cint 
		  ;
		  break ;
		case 21 : 
		  curval = fontinfo [italicbase [q ]+ ( i .b2 ) / 4 ].cint 
		  ;
		  break ;
		} 
	      } 
	      else curval = 0 ;
	    } 
	    else if ( ( fontbc [q ]<= curval ) && ( fontec [q ]>= curval ) 
	    ) 
	    {
	      i = fontinfo [charbase [q ]+ curval ].qqqq ;
	      switch ( m ) 
	      {case 18 : 
		curval = fontinfo [widthbase [q ]+ i .b0 ].cint ;
		break ;
	      case 19 : 
		curval = fontinfo [heightbase [q ]+ ( i .b1 ) / 16 ].cint 
		;
		break ;
	      case 20 : 
		curval = fontinfo [depthbase [q ]+ ( i .b1 ) % 16 ].cint ;
		break ;
	      case 21 : 
		curval = fontinfo [italicbase [q ]+ ( i .b2 ) / 4 ].cint ;
		break ;
	      } 
	    } 
	    else curval = 0 ;
	  } 
	  break ;
	case 22 : 
	case 23 : 
	case 24 : 
	  {
	    q = curchr - 22 ;
	    scanint () ;
	    if ( ( eqtb [25061 ].hh .v.RH == -1073741823L ) || ( curval <= 0 
	    ) ) 
	    curval = 0 ;
	    else {
		
	      if ( q == 2 ) 
	      {
		q = curval % 2 ;
		curval = ( curval + q ) / 2 ;
	      } 
	      if ( curval > mem [eqtb [25061 ].hh .v.RH ].hh .v.LH ) 
	      curval = mem [eqtb [25061 ].hh .v.RH ].hh .v.LH ;
	      curval = mem [eqtb [25061 ].hh .v.RH + 2 * curval - q ].cint 
	      ;
	    } 
	    curvallevel = 1 ;
	  } 
	  break ;
	case 25 : 
	case 26 : 
	  {
	    scannormalglue () ;
	    q = curval ;
	    if ( m == 25 ) 
	    curval = mem [q + 2 ].cint ;
	    else curval = mem [q + 3 ].cint ;
	    deleteglueref ( q ) ;
	  } 
	  break ;
	} 
	curvallevel = 1 ;
      } 
      else {
	  
	switch ( m ) 
	{case 5 : 
	  curval = line ;
	  break ;
	case 6 : 
	  curval = lastbadness ;
	  break ;
	case 10 : 
	  curval = 2 ;
	  break ;
	case 7 : 
	  curval = pdflastxpos ;
	  break ;
	case 8 : 
	  curval = pdflastypos ;
	  break ;
	case 9 : 
	  {
	    if ( shellenabledp ) 
	    {
	      if ( restrictedshell ) 
	      curval = 2 ;
	      else curval = 1 ;
	    } 
	    else curval = 0 ;
	  } 
	  break ;
	case 11 : 
	  curval = curlevel - 1 ;
	  break ;
	case 12 : 
	  curval = curgroup ;
	  break ;
	case 13 : 
	  {
	    q = condptr ;
	    curval = 0 ;
	    while ( q != -1073741823L ) {
		
	      incr ( curval ) ;
	      q = mem [q ].hh .v.RH ;
	    } 
	  } 
	  break ;
	case 14 : 
	  if ( condptr == -1073741823L ) 
	  curval = 0 ;
	  else if ( curif < 32 ) 
	  curval = curif + 1 ;
	  else curval = - (integer) ( curif - 31 ) ;
	  break ;
	case 15 : 
	  if ( ( iflimit == 4 ) || ( iflimit == 3 ) ) 
	  curval = 1 ;
	  else if ( iflimit == 2 ) 
	  curval = -1 ;
	  else curval = 0 ;
	  break ;
	case 16 : 
	case 17 : 
	  {
	    scannormalglue () ;
	    q = curval ;
	    if ( m == 16 ) 
	    curval = mem [q ].hh.b0 ;
	    else curval = mem [q ].hh.b1 ;
	    if ( curval > 0 ) 
	    curval = curval - 1 ;
	    deleteglueref ( q ) ;
	  } 
	  break ;
	} 
	curvallevel = 0 ;
      } 
    } 
    else {
	
      if ( curchr == 2 ) 
      curval = membot ;
      else curval = 0 ;
      tx = curlist .tailfield ;
      if ( ! ( tx >= himemmin ) ) {
	  
	if ( mem [tx ].hh.b0 == 5 ) 
	tx = curlist .pnodefield ;
      } 
      if ( ! ( tx >= himemmin ) ) {
	  
	if ( ( mem [tx ].hh.b0 == 5 ) || ( ( mem [tx ].hh.b0 == 11 ) && ( 
	mem [tx ].hh.b1 == 3 ) ) ) 
	{
	  r = curlist .headfield ;
	  q = mem [curlist .headfield ].hh .v.RH ;
	  while ( q != tx ) {
	      
	    if ( ( q >= himemmin ) ) 
	    r = q ;
	    else if ( ( mem [q ].hh.b0 != 5 ) && ( ( mem [q ].hh.b0 != 11 
	    ) || ( mem [q ].hh.b1 != 3 ) ) ) 
	    r = q ;
	    q = mem [q ].hh .v.RH ;
	  } 
	  tx = r ;
	} 
      } 
      if ( curchr == 3 ) 
      {
	curvallevel = 0 ;
	if ( ( tx == curlist .headfield ) || ( curlist .modefield == 0 ) ) 
	curval = -1 ;
      } 
      else if ( curchr == 4 ) 
      {
	curvallevel = 0 ;
	curval = -1 ;
      } 
      else curvallevel = curchr ;
      if ( ( curchr == 4 ) && ( ( tx >= himemmin ) ) && ( tx != curlist 
      .headfield ) ) 
      {
	r = curlist .headfield ;
	q = curlist .headfield ;
	while ( q != tx ) {
	    
	  r = q ;
	  q = mem [q ].hh .v.RH ;
	} 
	if ( ( r != curlist .headfield ) && ( r >= himemmin ) ) {
	    
	  if ( fontdir [mem [r ].hh.b0 ]!= 0 ) 
	  tx = r ;
	} 
	if ( fontdir [mem [tx ].hh.b0 ]!= 0 ) 
	curval = mem [mem [tx ].hh .v.RH ].hh .v.LH % 16777216L ;
	else curval = mem [tx ].hh.b1 ;
      } 
      if ( ! ( tx >= himemmin ) && ( tx != curlist .headfield ) && ( curlist 
      .modefield != 0 ) ) 
      switch ( curchr ) 
      {case 0 : 
	if ( mem [tx ].hh.b0 == 14 ) 
	curval = mem [tx + 1 ].cint ;
	break ;
      case 1 : 
	if ( mem [tx ].hh.b0 == 13 ) 
	curval = mem [tx + 1 ].cint ;
	break ;
      case 2 : 
	if ( mem [tx ].hh.b0 == 12 ) 
	{
	  curval = mem [tx + 1 ].hh .v.LH ;
	  if ( mem [tx ].hh.b1 == 99 ) 
	  curvallevel = 3 ;
	} 
	break ;
      case 3 : 
	if ( mem [tx ].hh.b0 <= 15 ) 
	{
	  if ( mem [tx ].hh.b0 == 2 ) 
	  tx = mem [tx + 5 ].hh .v.RH ;
	  curval = mem [tx ].hh.b0 ;
	  if ( curval < 2 ) 
	  curval = curval + 1 ;
	  else if ( curval > 5 ) 
	  curval = curval - 1 ;
	} 
	else curval = 15 ;
	break ;
      case 4 : 
	{
	  if ( ( ( mem [tx ].hh.b0 == 12 ) && ( mem [tx ].hh.b1 == 21 ) ) 
	  || ( ( mem [tx ].hh.b0 == 14 ) && ( mem [tx ].hh.b1 == 2 ) ) ) 
	  tx = curlist .lastjchrfield ;
	  else if ( ( mem [tx ].hh.b0 == 13 ) && ( mem [tx ].hh.b1 == 0 ) 
	  ) 
	  {
	    r = curlist .headfield ;
	    q = mem [curlist .headfield ].hh .v.RH ;
	    while ( q != tx ) {
		
	      r = q ;
	      if ( ( q >= himemmin ) ) {
		  
		if ( fontdir [mem [q ].hh.b0 ]!= 0 ) 
		q = mem [q ].hh .v.RH ;
	      } 
	      q = mem [q ].hh .v.RH ;
	    } 
	    if ( ( ( mem [r ].hh.b0 == 14 ) && ( mem [r ].hh.b1 == 2 ) ) ) 
	    tx = curlist .lastjchrfield ;
	    else tx = r ;
	  } 
	  if ( ! ( tx >= himemmin ) ) 
	  {
	    if ( mem [tx ].hh.b0 == 8 ) 
	    {
	      r = mem [tx + 1 ].hh .v.RH ;
	      while ( mem [r ].hh .v.RH != -1073741823L ) r = mem [r ].hh 
	      .v.RH ;
	      curval = mem [r ].hh.b1 ;
	    } 
	  } 
	  else if ( fontdir [mem [tx ].hh.b0 ]!= 0 ) 
	  curval = mem [mem [tx ].hh .v.RH ].hh .v.LH % 16777216L ;
	  else curval = mem [tx ].hh.b1 ;
	} 
	break ;
      } 
      else if ( ( curlist .modefield == 1 ) && ( tx == curlist .headfield ) ) 
      switch ( curchr ) 
      {case 0 : 
	curval = lastpenalty ;
	break ;
      case 1 : 
	curval = lastkern ;
	break ;
      case 2 : 
	if ( lastglue != 1073741823L ) 
	curval = lastglue ;
	break ;
      case 3 : 
	curval = lastnodetype ;
	break ;
      } 
    } 
    break ;
  case 43 : 
    if ( curchr == 1 ) 
    {
      gettoken () ;
      curcs = primlookup ( hash [curcs ].v.RH ) ;
      if ( curcs != 0 ) 
      {
	curcmd = primeqtb [curcs ].hh.b0 ;
	curchr = primeqtb [curcs ].hh .v.RH ;
	curtok = ( curcmd * 256 ) + curchr ;
      } 
      else {
	  
	curcmd = 0 ;
	curchr = 0 ;
	curtok = 536886432L ;
	curcs = 15521 ;
      } 
      goto lab20 ;
    } 
    break ;
    default: 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 751 ) ;
      } 
      printcmdchr ( curcmd , curchr ) ;
      print ( 752 ) ;
      printesc ( 587 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 750 ;
      } 
      error () ;
      if ( level != 5 ) 
      {
	curval = 0 ;
	curvallevel = 1 ;
      } 
      else {
	  
	curval = 0 ;
	curvallevel = 0 ;
      } 
    } 
    break ;
  } 
  while ( curvallevel > level ) {
      
    if ( curvallevel == 2 ) 
    curval = mem [curval + 1 ].cint ;
    else if ( curvallevel == 3 ) 
    muerror () ;
    decr ( curvallevel ) ;
  } 
  if ( negative ) {
      
    if ( curvallevel >= 2 ) 
    {
      curval = newspec ( curval ) ;
      {
	mem [curval + 1 ].cint = - (integer) mem [curval + 1 ].cint ;
	mem [curval + 2 ].cint = - (integer) mem [curval + 2 ].cint ;
	mem [curval + 3 ].cint = - (integer) mem [curval + 3 ].cint ;
      } 
    } 
    else curval = - (integer) curval ;
  } 
  else if ( ( curvallevel >= 2 ) && ( curvallevel <= 3 ) ) 
  incr ( mem [curval ].hh .v.RH ) ;
} 
void 
scanint ( void ) 
{
  /* 30 20 */ scanint_regmem 
  boolean negative  ;
  integer m  ;
  smallnumber d  ;
  boolean vacuous  ;
  boolean OKsofar  ;
  radix = 0 ;
  OKsofar = true ;
  negative = false ;
  do {
      do { getxtoken () ;
    } while ( ! ( curcmd != 10 ) ) ;
    if ( curtok == 3117 ) 
    {
      negative = ! negative ;
      curtok = 3115 ;
    } 
  } while ( ! ( curtok != 3115 ) ) ;
  lab20: if ( curtok == 3168 ) 
  {
    gettoken () ;
    if ( curtok < 536870911L ) {
	
      if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
      {
	skipmode = false ;
	curval = curchr ;
      } 
      else {
	  
	curval = curchr ;
	if ( curcmd <= 2 ) {
	    
	  if ( curcmd == 2 ) 
	  incr ( alignstate ) ;
	  else decr ( alignstate ) ;
	} 
      } 
    } 
    else if ( curtok < 536871168L ) 
    curval = curtok - 536870912L ;
    else curval = curtok - 536871168L ;
    if ( ( curval > 255 ) && ( ( curcmd < 16 ) || ( curcmd > 19 ) ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 767 ) ;
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 768 ;
	helpline [0 ]= 769 ;
      } 
      curval = 48 ;
      backerror () ;
    } 
    else {
	
      getxtoken () ;
      if ( curcmd != 10 ) 
      backinput () ;
    } 
    skipmode = true ;
  } 
  else if ( curtok == 536886436L ) 
  {
    gettoken () ;
    curcs = primlookup ( hash [curcs ].v.RH ) ;
    if ( curcs != 0 ) 
    {
      curcmd = primeqtb [curcs ].hh.b0 ;
      curchr = primeqtb [curcs ].hh .v.RH ;
      curtok = ( curcmd * 256 ) + curchr ;
    } 
    else {
	
      curcmd = 0 ;
      curchr = 0 ;
      curtok = 536886432L ;
      curcs = 15521 ;
    } 
    goto lab20 ;
  } 
  else if ( ( curcmd >= 73 ) && ( curcmd <= 103 ) ) 
  scansomethinginternal ( 0 , false ) ;
  else {
      
    radix = 10 ;
    m = 214748364L ;
    if ( curtok == 3111 ) 
    {
      radix = 8 ;
      m = 268435456L ;
      getxtoken () ;
    } 
    else if ( curtok == 3106 ) 
    {
      radix = 16 ;
      m = 134217728L ;
      getxtoken () ;
    } 
    vacuous = true ;
    curval = 0 ;
    while ( true ) {
	
      if ( ( curtok < 3120 + radix ) && ( curtok >= 3120 ) && ( curtok <= 3129 
      ) ) 
      d = curtok - 3120 ;
      else if ( radix == 16 ) {
	  
	if ( ( curtok <= 2886 ) && ( curtok >= 2881 ) ) 
	d = curtok - 2871 ;
	else if ( ( curtok <= 3142 ) && ( curtok >= 3137 ) ) 
	d = curtok - 3127 ;
	else goto lab30 ;
      } 
      else goto lab30 ;
      vacuous = false ;
      if ( ( curval >= m ) && ( ( curval > m ) || ( d > 7 ) || ( radix != 10 ) 
      ) ) 
      {
	if ( OKsofar ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 770 ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 771 ;
	    helpline [0 ]= 772 ;
	  } 
	  error () ;
	  curval = 2147483647L ;
	  OKsofar = false ;
	} 
      } 
      else curval = curval * radix + d ;
      getxtoken () ;
    } 
    lab30: ;
    if ( vacuous ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 730 ) ;
      } 
      {
	helpptr = 3 ;
	helpline [2 ]= 731 ;
	helpline [1 ]= 732 ;
	helpline [0 ]= 733 ;
      } 
      backerror () ;
    } 
    else if ( curcmd != 10 ) 
    backinput () ;
  } 
  if ( negative ) 
  curval = - (integer) curval ;
} 
void 
zscandimen ( boolean mu , boolean inf , boolean shortcut ) 
{
  /* 30 31 32 40 45 88 89 */ scandimen_regmem 
  boolean negative  ;
  integer f  ;
  integer num, denom  ;
  smallnumber k, kk  ;
  halfword p, q  ;
  scaled v  ;
  integer savecurval  ;
  eightbits t  ;
  f = 0 ;
  aritherror = false ;
  curorder = 0 ;
  negative = false ;
  if ( ! shortcut ) 
  {
    negative = false ;
    do {
	do { getxtoken () ;
      } while ( ! ( curcmd != 10 ) ) ;
      if ( curtok == 3117 ) 
      {
	negative = ! negative ;
	curtok = 3115 ;
      } 
    } while ( ! ( curtok != 3115 ) ) ;
    if ( ( curcmd >= 73 ) && ( curcmd <= 103 ) ) {
	
      if ( mu ) 
      {
	scansomethinginternal ( 3 , false ) ;
	if ( curvallevel >= 2 ) 
	{
	  v = mem [curval + 1 ].cint ;
	  deleteglueref ( curval ) ;
	  curval = v ;
	} 
	if ( curvallevel == 3 ) 
	goto lab89 ;
	if ( curvallevel != 0 ) 
	muerror () ;
      } 
      else {
	  
	scansomethinginternal ( 1 , false ) ;
	if ( curvallevel == 1 ) 
	goto lab89 ;
      } 
    } 
    else {
	
      backinput () ;
      if ( curtok == 3116 ) 
      curtok = 3118 ;
      if ( curtok != 3118 ) 
      scanint () ;
      else {
	  
	radix = 10 ;
	curval = 0 ;
      } 
      if ( curtok == 3116 ) 
      curtok = 3118 ;
      if ( ( radix == 10 ) && ( curtok == 3118 ) ) 
      {
	k = 0 ;
	p = -1073741823L ;
	gettoken () ;
	while ( true ) {
	    
	  getxtoken () ;
	  if ( ( curtok > 3129 ) || ( curtok < 3120 ) ) 
	  goto lab31 ;
	  if ( k < 17 ) 
	  {
	    q = getavail () ;
	    mem [q ].hh .v.RH = p ;
	    mem [q ].hh .v.LH = curtok - 3120 ;
	    p = q ;
	    incr ( k ) ;
	  } 
	} 
	lab31: {
	    register integer for_end; kk = k ;for_end = 1 ; if ( kk >= 
	for_end) do 
	  {
	    dig [kk - 1 ]= mem [p ].hh .v.LH ;
	    q = p ;
	    p = mem [p ].hh .v.RH ;
	    {
	      mem [q ].hh .v.RH = avail ;
	      avail = q ;
	;
#ifdef STAT
	      decr ( dynused ) ;
#endif /* STAT */
	    } 
	  } 
	while ( kk-- > for_end ) ;} 
	f = rounddecimals ( k ) ;
	if ( curcmd != 10 ) 
	backinput () ;
      } 
    } 
  } 
  if ( curval < 0 ) 
  {
    negative = ! negative ;
    curval = - (integer) curval ;
  } 
  if ( inf ) {
      
    if ( scankeyword ( 316 ) ) 
    {
      curorder = 1 ;
      while ( scankeyword ( 108 ) ) {
	  
	if ( curorder == 4 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 774 ) ;
	  } 
	  print ( 775 ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 776 ;
	  } 
	  error () ;
	} 
	else incr ( curorder ) ;
      } 
      goto lab88 ;
    } 
  } 
  savecurval = curval ;
  do {
      getxtoken () ;
  } while ( ! ( curcmd != 10 ) ) ;
  if ( ( curcmd < 73 ) || ( curcmd > 103 ) ) 
  backinput () ;
  else {
      
    if ( mu ) 
    {
      scansomethinginternal ( 3 , false ) ;
      if ( curvallevel >= 2 ) 
      {
	v = mem [curval + 1 ].cint ;
	deleteglueref ( curval ) ;
	curval = v ;
      } 
      if ( curvallevel != 3 ) 
      muerror () ;
    } 
    else scansomethinginternal ( 1 , false ) ;
    v = curval ;
    goto lab40 ;
  } 
  if ( mu ) 
  goto lab45 ;
  if ( scankeyword ( 777 ) ) 
  v = ( fontinfo [6 + parambase [eqtb [25588 ].hh .v.RH ]].cint ) ;
  else if ( scankeyword ( 778 ) ) 
  v = ( fontinfo [5 + parambase [eqtb [25588 ].hh .v.RH ]].cint ) ;
  else if ( scankeyword ( 779 ) ) {
      
    if ( curlist .dirfield == 3 ) 
    v = fontinfo [widthbase [eqtb [26358 ].hh .v.RH ]+ fontinfo [
    charbase [eqtb [26358 ].hh .v.RH ]+ 0 ].qqqq .b0 ].cint ;
    else v = fontinfo [widthbase [eqtb [26357 ].hh .v.RH ]+ fontinfo [
    charbase [eqtb [26357 ].hh .v.RH ]+ 0 ].qqqq .b0 ].cint ;
  } 
  else if ( scankeyword ( 780 ) ) {
      
    if ( curlist .dirfield == 3 ) 
    {
      t = fontinfo [charbase [eqtb [26358 ].hh .v.RH ]+ 0 ].qqqq .b1 ;
      v = fontinfo [heightbase [eqtb [26358 ].hh .v.RH ]+ ( t ) / 16 ]
      .cint + fontinfo [depthbase [eqtb [26358 ].hh .v.RH ]+ ( t ) % 16 ]
      .cint ;
    } 
    else {
	
      t = fontinfo [charbase [eqtb [26357 ].hh .v.RH ]+ 0 ].qqqq .b1 ;
      v = fontinfo [heightbase [eqtb [26357 ].hh .v.RH ]+ ( t ) / 16 ]
      .cint + fontinfo [depthbase [eqtb [26357 ].hh .v.RH ]+ ( t ) % 16 ]
      .cint ;
    } 
  } 
  else goto lab45 ;
  {
    getxtoken () ;
    if ( curcmd != 10 ) 
    backinput () ;
  } 
  lab40: curval = multandadd ( savecurval , v , xnoverd ( v , f , 65536L ) , 
  1073741823L ) ;
  goto lab89 ;
  lab45: ;
  if ( mu ) {
      
    if ( scankeyword ( 343 ) ) 
    goto lab88 ;
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 774 ) ;
      } 
      print ( 781 ) ;
      {
	helpptr = 4 ;
	helpline [3 ]= 782 ;
	helpline [2 ]= 783 ;
	helpline [1 ]= 784 ;
	helpline [0 ]= 785 ;
      } 
      error () ;
      goto lab88 ;
    } 
  } 
  if ( scankeyword ( 773 ) ) 
  {
    preparemag () ;
    if ( eqtb [29205 ].cint != 1000 ) 
    {
      curval = xnoverd ( curval , 1000 , eqtb [29205 ].cint ) ;
      f = ( 1000 * f + 65536L * texremainder ) / eqtb [29205 ].cint ;
      curval = curval + ( f / 65536L ) ;
      f = f % 65536L ;
    } 
  } 
  if ( scankeyword ( 419 ) ) 
  goto lab88 ;
  if ( scankeyword ( 786 ) ) 
  {
    num = 7227 ;
    denom = 100 ;
  } 
  else if ( scankeyword ( 787 ) ) 
  {
    num = 12 ;
    denom = 1 ;
  } 
  else if ( scankeyword ( 788 ) ) 
  {
    num = 7227 ;
    denom = 254 ;
  } 
  else if ( scankeyword ( 789 ) ) 
  {
    num = 7227 ;
    denom = 2540 ;
  } 
  else if ( scankeyword ( 790 ) ) 
  {
    num = 7227 ;
    denom = 7200 ;
  } 
  else if ( scankeyword ( 791 ) ) 
  {
    num = 1238 ;
    denom = 1157 ;
  } 
  else if ( scankeyword ( 792 ) ) 
  {
    num = 14856 ;
    denom = 1157 ;
  } 
  else if ( scankeyword ( 72 ) ) 
  {
    num = 7227 ;
    denom = 10160 ;
  } 
  else if ( scankeyword ( 81 ) ) 
  {
    num = 7227 ;
    denom = 10160 ;
  } 
  else if ( scankeyword ( 793 ) ) 
  goto lab30 ;
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 774 ) ;
    } 
    print ( 794 ) ;
    {
      helpptr = 6 ;
      helpline [5 ]= 795 ;
      helpline [4 ]= 796 ;
      helpline [3 ]= 797 ;
      helpline [2 ]= 783 ;
      helpline [1 ]= 784 ;
      helpline [0 ]= 785 ;
    } 
    error () ;
    goto lab32 ;
  } 
  curval = xnoverd ( curval , num , denom ) ;
  f = ( num * f + 65536L * texremainder ) / denom ;
  curval = curval + ( f / 65536L ) ;
  f = f % 65536L ;
  lab32: ;
  lab88: if ( curval >= 16384 ) 
  aritherror = true ;
  else curval = curval * 65536L + f ;
  lab30: ;
  {
    getxtoken () ;
    if ( curcmd != 10 ) 
    backinput () ;
  } 
  lab89: if ( aritherror || ( abs ( curval ) >= 1073741824L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 798 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 799 ;
      helpline [0 ]= 800 ;
    } 
    error () ;
    curval = 1073741823L ;
    aritherror = false ;
  } 
  if ( negative ) 
  curval = - (integer) curval ;
} 
void 
zscanglue ( smallnumber level ) 
{
  /* 10 */ scanglue_regmem 
  boolean negative  ;
  halfword q  ;
  boolean mu  ;
  mu = ( level == 3 ) ;
  negative = false ;
  do {
      do { getxtoken () ;
    } while ( ! ( curcmd != 10 ) ) ;
    if ( curtok == 3117 ) 
    {
      negative = ! negative ;
      curtok = 3115 ;
    } 
  } while ( ! ( curtok != 3115 ) ) ;
  if ( ( curcmd >= 73 ) && ( curcmd <= 103 ) ) 
  {
    scansomethinginternal ( level , negative ) ;
    if ( curvallevel >= 2 ) 
    {
      if ( curvallevel != level ) 
      muerror () ;
      return ;
    } 
    if ( curvallevel == 0 ) 
    scandimen ( mu , false , true ) ;
    else if ( level == 3 ) 
    muerror () ;
  } 
  else {
      
    backinput () ;
    scandimen ( mu , false , false ) ;
    if ( negative ) 
    curval = - (integer) curval ;
  } 
  q = newspec ( membot ) ;
  mem [q + 1 ].cint = curval ;
  if ( scankeyword ( 801 ) ) 
  {
    scandimen ( mu , true , false ) ;
    mem [q + 2 ].cint = curval ;
    mem [q ].hh.b0 = curorder ;
  } 
  if ( scankeyword ( 802 ) ) 
  {
    scandimen ( mu , true , false ) ;
    mem [q + 3 ].cint = curval ;
    mem [q ].hh.b1 = curorder ;
  } 
  curval = q ;
} 
integer 
zaddorsub ( integer x , integer y , integer maxanswer , boolean negative ) 
{
  register integer Result; addorsub_regmem 
  integer a  ;
  if ( negative ) 
  y = - (integer) y ;
  if ( x >= 0 ) {
      
    if ( y <= maxanswer - x ) 
    a = x + y ;
    else {
	
      aritherror = true ;
      a = 0 ;
    } 
  } 
  else if ( y >= - (integer) maxanswer - x ) 
  a = x + y ;
  else {
      
    aritherror = true ;
    a = 0 ;
  } 
  Result = a ;
  return Result ;
} 
integer 
zquotient ( integer n , integer d ) 
{
  register integer Result; quotient_regmem 
  boolean negative  ;
  integer a  ;
  if ( d == 0 ) 
  {
    aritherror = true ;
    a = 0 ;
  } 
  else {
      
    if ( d > 0 ) 
    negative = false ;
    else {
	
      d = - (integer) d ;
      negative = true ;
    } 
    if ( n < 0 ) 
    {
      n = - (integer) n ;
      negative = ! negative ;
    } 
    a = n / d ;
    n = n - a * d ;
    d = n - d ;
    if ( d + n >= 0 ) 
    incr ( a ) ;
    if ( negative ) 
    a = - (integer) a ;
  } 
  Result = a ;
  return Result ;
} 
integer 
zfract ( integer x , integer n , integer d , integer maxanswer ) 
{
  /* 40 41 88 30 */ register integer Result; fract_regmem 
  boolean negative  ;
  integer a  ;
  integer f  ;
  integer h  ;
  integer r  ;
  integer t  ;
  if ( d == 0 ) 
  goto lab88 ;
  a = 0 ;
  if ( d > 0 ) 
  negative = false ;
  else {
      
    d = - (integer) d ;
    negative = true ;
  } 
  if ( x < 0 ) 
  {
    x = - (integer) x ;
    negative = ! negative ;
  } 
  else if ( x == 0 ) 
  goto lab30 ;
  if ( n < 0 ) 
  {
    n = - (integer) n ;
    negative = ! negative ;
  } 
  t = n / d ;
  if ( t > maxanswer / x ) 
  goto lab88 ;
  a = t * x ;
  n = n - t * d ;
  if ( n == 0 ) 
  goto lab40 ;
  t = x / d ;
  if ( t > ( maxanswer - a ) / n ) 
  goto lab88 ;
  a = a + t * n ;
  x = x - t * d ;
  if ( x == 0 ) 
  goto lab40 ;
  if ( x < n ) 
  {
    t = x ;
    x = n ;
    n = t ;
  } 
  f = 0 ;
  r = ( d / 2 ) - d ;
  h = - (integer) r ;
  while ( true ) {
      
    if ( odd ( n ) ) 
    {
      r = r + x ;
      if ( r >= 0 ) 
      {
	r = r - d ;
	incr ( f ) ;
      } 
    } 
    n = n / 2 ;
    if ( n == 0 ) 
    goto lab41 ;
    if ( x < h ) 
    x = x + x ;
    else {
	
      t = x - d ;
      x = t + x ;
      f = f + n ;
      if ( x < n ) 
      {
	if ( x == 0 ) 
	goto lab41 ;
	t = x ;
	x = n ;
	n = t ;
      } 
    } 
  } 
  lab41: if ( f > ( maxanswer - a ) ) 
  goto lab88 ;
  a = a + f ;
  lab40: if ( negative ) 
  a = - (integer) a ;
  goto lab30 ;
  lab88: {
      
    aritherror = true ;
    a = 0 ;
  } 
  lab30: Result = a ;
  return Result ;
} 
void 
scanexpr ( void ) 
{
  /* 20 22 40 */ scanexpr_regmem 
  boolean a, b  ;
  smallnumber l  ;
  smallnumber r  ;
  smallnumber s  ;
  smallnumber o  ;
  integer e  ;
  integer t  ;
  integer f  ;
  integer n  ;
  halfword p  ;
  halfword q  ;
  l = curvallevel ;
  a = aritherror ;
  b = false ;
  p = -1073741823L ;
  lab20: r = 0 ;
  e = 0 ;
  s = 0 ;
  t = 0 ;
  n = 0 ;
  lab22: if ( s == 0 ) 
  o = l ;
  else o = 0 ;
  do {
      getxtoken () ;
  } while ( ! ( curcmd != 10 ) ) ;
  if ( curtok == 3112 ) 
  {
    q = getnode ( 4 ) ;
    mem [q ].hh .v.RH = p ;
    mem [q ].hh.b0 = l ;
    mem [q ].hh.b1 = 4 * s + r ;
    mem [q + 1 ].cint = e ;
    mem [q + 2 ].cint = t ;
    mem [q + 3 ].cint = n ;
    p = q ;
    l = o ;
    goto lab20 ;
  } 
  backinput () ;
  if ( o == 0 ) 
  scanint () ;
  else if ( o == 1 ) 
  scandimen ( false , false , false ) ;
  else if ( o == 2 ) 
  scannormalglue () ;
  else scanmuglue () ;
  f = curval ;
  lab40: do {
      getxtoken () ;
  } while ( ! ( curcmd != 10 ) ) ;
  if ( curtok == 3115 ) 
  o = 1 ;
  else if ( curtok == 3117 ) 
  o = 2 ;
  else if ( curtok == 3114 ) 
  o = 3 ;
  else if ( curtok == 3119 ) 
  o = 4 ;
  else {
      
    o = 0 ;
    if ( p == -1073741823L ) 
    {
      if ( curcmd != 0 ) 
      backinput () ;
    } 
    else if ( curtok != 3113 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1541 ) ;
      } 
      {
	helpptr = 1 ;
	helpline [0 ]= 1542 ;
      } 
      backerror () ;
    } 
  } 
  aritherror = b ;
  if ( ( l == 0 ) || ( s > 2 ) ) 
  {
    if ( ( f > 2147483647L ) || ( f < -2147483647L ) ) 
    {
      aritherror = true ;
      f = 0 ;
    } 
  } 
  else if ( l == 1 ) 
  {
    if ( abs ( f ) > 1073741823L ) 
    {
      aritherror = true ;
      f = 0 ;
    } 
  } 
  else {
      
    if ( ( abs ( mem [f + 1 ].cint ) > 1073741823L ) || ( abs ( mem [f + 2 
    ].cint ) > 1073741823L ) || ( abs ( mem [f + 3 ].cint ) > 1073741823L ) 
    ) 
    {
      aritherror = true ;
      deleteglueref ( f ) ;
      f = newspec ( membot ) ;
    } 
  } 
  switch ( s ) 
  {case 0 : 
    if ( ( l >= 2 ) && ( o != 0 ) ) 
    {
      t = newspec ( f ) ;
      deleteglueref ( f ) ;
      if ( mem [t + 2 ].cint == 0 ) 
      mem [t ].hh.b0 = 0 ;
      if ( mem [t + 3 ].cint == 0 ) 
      mem [t ].hh.b1 = 0 ;
    } 
    else t = f ;
    break ;
  case 3 : 
    if ( o == 4 ) 
    {
      n = f ;
      o = 5 ;
    } 
    else if ( l == 0 ) 
    t = multandadd ( t , f , 0 , 2147483647L ) ;
    else if ( l == 1 ) 
    t = multandadd ( t , f , 0 , 1073741823L ) ;
    else {
	
      mem [t + 1 ].cint = multandadd ( mem [t + 1 ].cint , f , 0 , 
      1073741823L ) ;
      mem [t + 2 ].cint = multandadd ( mem [t + 2 ].cint , f , 0 , 
      1073741823L ) ;
      mem [t + 3 ].cint = multandadd ( mem [t + 3 ].cint , f , 0 , 
      1073741823L ) ;
    } 
    break ;
  case 4 : 
    if ( l < 2 ) 
    t = quotient ( t , f ) ;
    else {
	
      mem [t + 1 ].cint = quotient ( mem [t + 1 ].cint , f ) ;
      mem [t + 2 ].cint = quotient ( mem [t + 2 ].cint , f ) ;
      mem [t + 3 ].cint = quotient ( mem [t + 3 ].cint , f ) ;
    } 
    break ;
  case 5 : 
    if ( l == 0 ) 
    t = fract ( t , n , f , 2147483647L ) ;
    else if ( l == 1 ) 
    t = fract ( t , n , f , 1073741823L ) ;
    else {
	
      mem [t + 1 ].cint = fract ( mem [t + 1 ].cint , n , f , 1073741823L 
      ) ;
      mem [t + 2 ].cint = fract ( mem [t + 2 ].cint , n , f , 1073741823L 
      ) ;
      mem [t + 3 ].cint = fract ( mem [t + 3 ].cint , n , f , 1073741823L 
      ) ;
    } 
    break ;
  } 
  if ( o > 2 ) 
  s = o ;
  else {
      
    s = 0 ;
    if ( r == 0 ) 
    e = t ;
    else if ( l == 0 ) 
    e = addorsub ( e , t , 2147483647L , r == 2 ) ;
    else if ( l == 1 ) 
    e = addorsub ( e , t , 1073741823L , r == 2 ) ;
    else {
	
      mem [e + 1 ].cint = addorsub ( mem [e + 1 ].cint , mem [t + 1 ]
      .cint , 1073741823L , r == 2 ) ;
      if ( mem [e ].hh.b0 == mem [t ].hh.b0 ) 
      mem [e + 2 ].cint = addorsub ( mem [e + 2 ].cint , mem [t + 2 ]
      .cint , 1073741823L , r == 2 ) ;
      else if ( ( mem [e ].hh.b0 < mem [t ].hh.b0 ) && ( mem [t + 2 ]
      .cint != 0 ) ) 
      {
	mem [e + 2 ].cint = mem [t + 2 ].cint ;
	mem [e ].hh.b0 = mem [t ].hh.b0 ;
      } 
      if ( mem [e ].hh.b1 == mem [t ].hh.b1 ) 
      mem [e + 3 ].cint = addorsub ( mem [e + 3 ].cint , mem [t + 3 ]
      .cint , 1073741823L , r == 2 ) ;
      else if ( ( mem [e ].hh.b1 < mem [t ].hh.b1 ) && ( mem [t + 3 ]
      .cint != 0 ) ) 
      {
	mem [e + 3 ].cint = mem [t + 3 ].cint ;
	mem [e ].hh.b1 = mem [t ].hh.b1 ;
      } 
      deleteglueref ( t ) ;
      if ( mem [e + 2 ].cint == 0 ) 
      mem [e ].hh.b0 = 0 ;
      if ( mem [e + 3 ].cint == 0 ) 
      mem [e ].hh.b1 = 0 ;
    } 
    r = o ;
  } 
  b = aritherror ;
  if ( o != 0 ) 
  goto lab22 ;
  if ( p != -1073741823L ) 
  {
    f = e ;
    q = p ;
    e = mem [q + 1 ].cint ;
    t = mem [q + 2 ].cint ;
    n = mem [q + 3 ].cint ;
    s = mem [q ].hh.b1 / 4 ;
    r = mem [q ].hh.b1 % 4 ;
    l = mem [q ].hh.b0 ;
    p = mem [q ].hh .v.RH ;
    freenode ( q , 4 ) ;
    goto lab40 ;
  } 
  if ( b ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1348 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 1540 ;
      helpline [0 ]= 1350 ;
    } 
    error () ;
    if ( l >= 2 ) 
    {
      deleteglueref ( e ) ;
      e = membot ;
      incr ( mem [e ].hh .v.RH ) ;
    } 
    else e = 0 ;
  } 
  aritherror = a ;
  curval = e ;
  curvallevel = l ;
} 
void 
scannormalglue ( void ) 
{
  scannormalglue_regmem 
  scanglue ( 2 ) ;
} 
void 
scanmuglue ( void ) 
{
  scanmuglue_regmem 
  scanglue ( 3 ) ;
} 
halfword 
scanrulespec ( void ) 
{
  /* 21 */ register halfword Result; scanrulespec_regmem 
  halfword q  ;
  q = newrule () ;
  if ( curcmd == 39 ) 
  mem [q + 1 ].cint = 26214 ;
  else {
      
    mem [q + 3 ].cint = 26214 ;
    mem [q + 2 ].cint = 0 ;
  } 
  lab21: if ( scankeyword ( 803 ) ) 
  {
    scandimen ( false , false , false ) ;
    mem [q + 1 ].cint = curval ;
    goto lab21 ;
  } 
  if ( scankeyword ( 804 ) ) 
  {
    scandimen ( false , false , false ) ;
    mem [q + 3 ].cint = curval ;
    goto lab21 ;
  } 
  if ( scankeyword ( 805 ) ) 
  {
    scandimen ( false , false , false ) ;
    mem [q + 2 ].cint = curval ;
    goto lab21 ;
  } 
  Result = q ;
  return Result ;
} 
void 
scangeneraltext ( void ) 
{
  /* 40 */ scangeneraltext_regmem 
  unsigned char s  ;
  halfword w  ;
  halfword d  ;
  halfword p  ;
  halfword q  ;
  halfword unbalance  ;
  s = scannerstatus ;
  w = warningindex ;
  d = defref ;
  scannerstatus = 5 ;
  warningindex = curcs ;
  defref = getavail () ;
  mem [defref ].hh .v.LH = -1073741823L ;
  p = defref ;
  scanleftbrace () ;
  unbalance = 1 ;
  while ( true ) {
      
    gettoken () ;
    if ( curtok < 768 ) {
	
      if ( curcmd < 2 ) 
      incr ( unbalance ) ;
      else {
	  
	decr ( unbalance ) ;
	if ( unbalance == 0 ) 
	goto lab40 ;
      } 
    } 
    {
      q = getavail () ;
      mem [p ].hh .v.RH = q ;
      mem [q ].hh .v.LH = curtok ;
      p = q ;
    } 
  } 
  lab40: q = mem [defref ].hh .v.RH ;
  {
    mem [defref ].hh .v.RH = avail ;
    avail = defref ;
	;
#ifdef STAT
    decr ( dynused ) ;
#endif /* STAT */
  } 
  if ( q == -1073741823L ) 
  curval = memtop - 3 ;
  else curval = p ;
  mem [memtop - 3 ].hh .v.RH = q ;
  scannerstatus = s ;
  warningindex = w ;
  defref = d ;
} 
void 
pseudostart ( void ) 
{
  pseudostart_regmem 
  unsigned char oldsetting  ;
  strnumber s  ;
  poolpointer l, m  ;
  halfword p, q, r  ;
  fourquarters w  ;
  integer nl, sz  ;
  scangeneraltext () ;
  oldsetting = selector ;
  selector = 21 ;
  tokenshow ( memtop - 3 ) ;
  selector = oldsetting ;
  flushlist ( mem [memtop - 3 ].hh .v.RH ) ;
  {
    if ( poolptr + 1 > poolsize ) 
    overflow ( 259 , poolsize - initpoolptr ) ;
  } 
  s = makestring () ;
  strpool [poolptr ]= 32 ;
  l = strstart [s ];
  nl = eqtb [29238 ].cint ;
  p = getavail () ;
  q = p ;
  while ( l < poolptr ) {
      
    m = l ;
    while ( ( l < poolptr ) && ( strpool [l ]!= nl ) ) incr ( l ) ;
    sz = ( l - m + 7 ) / 4 ;
    if ( sz == 1 ) 
    sz = 2 ;
    r = getnode ( sz ) ;
    mem [q ].hh .v.RH = r ;
    q = r ;
    mem [q ].hh .v.LH = sz ;
    while ( sz > 2 ) {
	
      decr ( sz ) ;
      incr ( r ) ;
      w .b0 = strpool [m ];
      w .b1 = strpool [m + 1 ];
      w .b2 = strpool [m + 2 ];
      w .b3 = strpool [m + 3 ];
      mem [r ].qqqq = w ;
      m = m + 4 ;
    } 
    w .b0 = 32 ;
    w .b1 = 32 ;
    w .b2 = 32 ;
    w .b3 = 32 ;
    if ( l > m ) 
    {
      w .b0 = strpool [m ];
      if ( l > m + 1 ) 
      {
	w .b1 = strpool [m + 1 ];
	if ( l > m + 2 ) 
	{
	  w .b2 = strpool [m + 2 ];
	  if ( l > m + 3 ) 
	  w .b3 = strpool [m + 3 ];
	} 
      } 
    } 
    mem [r + 1 ].qqqq = w ;
    if ( strpool [l ]== nl ) 
    incr ( l ) ;
  } 
  mem [p ].hh .v.LH = mem [p ].hh .v.RH ;
  mem [p ].hh .v.RH = pseudofiles ;
  pseudofiles = p ;
  {
    decr ( strptr ) ;
    poolptr = strstart [strptr ];
  } 
  beginfilereading () ;
  line = 0 ;
  curinput .limitfield = curinput .startfield ;
  curinput .locfield = curinput .limitfield + 1 ;
  if ( eqtb [29255 ].cint > 0 ) 
  {
    if ( termoffset > maxprintline - 3 ) 
    println () ;
    else if ( ( termoffset > 0 ) || ( fileoffset > 0 ) ) 
    printchar ( 32 ) ;
    curinput .namefield = 19 ;
    print ( 1526 ) ;
    incr ( openparens ) ;
    fflush ( stdout ) ;
  } 
  else {
      
    curinput .namefield = 18 ;
    curinput .synctextagfield = 0 ;
  } 
} 
halfword 
zstrtoks ( poolpointer b ) 
{
  register halfword Result; strtoks_regmem 
  halfword p  ;
  halfword q  ;
  halfword t  ;
  poolpointer k  ;
  unsigned char cc  ;
  {
    if ( poolptr + 1 > poolsize ) 
    overflow ( 259 , poolsize - initpoolptr ) ;
  } 
  p = memtop - 3 ;
  mem [p ].hh .v.RH = -1073741823L ;
  k = b ;
  while ( k < poolptr ) {
      
    t = fromBUFF ( ustringcast ( strpool ) , poolptr , k ) ;
    cc = eqtb [26618 + kcatcodekey ( t ) ].hh .v.RH ;
    if ( ( multistrlen ( ustringcast ( strpool ) , poolptr , k ) > 1 ) && 
    checkkcatcode ( cc ) ) 
    {
      if ( ( cc == 15 ) ) 
      cc = 18 ;
      t = t + cc * 16777216L ;
      k = k + multistrlen ( ustringcast ( strpool ) , poolptr , k ) - 1 ;
    } 
    else {
	
      t = strpool [k ];
      if ( t == 32 ) 
      t = 2592 ;
      else t = 3072 + t ;
    } 
    {
      {
	q = avail ;
	if ( q == -1073741823L ) 
	q = getavail () ;
	else {
	    
	  avail = mem [q ].hh .v.RH ;
	  mem [q ].hh .v.RH = -1073741823L ;
	;
#ifdef STAT
	  incr ( dynused ) ;
#endif /* STAT */
	} 
      } 
      mem [p ].hh .v.RH = q ;
      mem [q ].hh .v.LH = t ;
      p = q ;
    } 
    incr ( k ) ;
  } 
  poolptr = b ;
  Result = p ;
  return Result ;
} 
halfword 
thetoks ( void ) 
{
  /* 10 */ register halfword Result; thetoks_regmem 
  unsigned char oldsetting  ;
  halfword p, q, r  ;
  poolpointer b  ;
  smallnumber c  ;
  if ( odd ( curchr ) ) 
  {
    c = curchr ;
    scangeneraltext () ;
    if ( c == 1 ) 
    Result = curval ;
    else {
	
      oldsetting = selector ;
      selector = 21 ;
      b = poolptr ;
      p = getavail () ;
      mem [p ].hh .v.RH = mem [memtop - 3 ].hh .v.RH ;
      tokenshow ( p ) ;
      flushlist ( p ) ;
      selector = oldsetting ;
      Result = strtoks ( b ) ;
    } 
    return Result ;
  } 
  getxtoken () ;
  scansomethinginternal ( 5 , false ) ;
  if ( curvallevel >= 4 ) 
  {
    p = memtop - 3 ;
    mem [p ].hh .v.RH = -1073741823L ;
    if ( curvallevel == 4 ) 
    {
      q = getavail () ;
      mem [p ].hh .v.RH = q ;
      mem [q ].hh .v.LH = 536870911L + curval ;
      p = q ;
    } 
    else if ( curval != -1073741823L ) 
    {
      r = mem [curval ].hh .v.RH ;
      while ( r != -1073741823L ) {
	  
	{
	  {
	    q = avail ;
	    if ( q == -1073741823L ) 
	    q = getavail () ;
	    else {
		
	      avail = mem [q ].hh .v.RH ;
	      mem [q ].hh .v.RH = -1073741823L ;
	;
#ifdef STAT
	      incr ( dynused ) ;
#endif /* STAT */
	    } 
	  } 
	  mem [p ].hh .v.RH = q ;
	  mem [q ].hh .v.LH = mem [r ].hh .v.LH ;
	  p = q ;
	} 
	r = mem [r ].hh .v.RH ;
      } 
    } 
    Result = p ;
  } 
  else {
      
    oldsetting = selector ;
    selector = 21 ;
    b = poolptr ;
    switch ( curvallevel ) 
    {case 0 : 
      printint ( curval ) ;
      break ;
    case 1 : 
      {
	printscaled ( curval ) ;
	print ( 419 ) ;
      } 
      break ;
    case 2 : 
      {
	printspec ( curval , 419 ) ;
	deleteglueref ( curval ) ;
      } 
      break ;
    case 3 : 
      {
	printspec ( curval , 343 ) ;
	deleteglueref ( curval ) ;
      } 
      break ;
    } 
    selector = oldsetting ;
    Result = strtoks ( b ) ;
  } 
  return Result ;
} 
void 
insthetoks ( void ) 
{
  insthetoks_regmem 
  mem [memtop - 12 ].hh .v.RH = thetoks () ;
  begintokenlist ( mem [memtop - 3 ].hh .v.RH , 4 ) ;
} 
void 
convtoks ( void ) 
{
  convtoks_regmem 
  unsigned char oldsetting  ;
  KANJIcode cx  ;
  unsigned char c  ;
  smallnumber savescannerstatus  ;
  halfword savedefref  ;
  halfword savewarningindex  ;
  boolean bool  ;
  strnumber u  ;
  strnumber s  ;
  integer i  ;
  integer j  ;
  poolpointer b  ;
  c = curchr ;
  cx = 0 ;
  switch ( c ) 
  {case 0 : 
  case 1 : 
  case 2 : 
  case 6 : 
  case 7 : 
  case 8 : 
  case 9 : 
  case 10 : 
    scanint () ;
    break ;
  case 3 : 
  case 4 : 
    {
      savescannerstatus = scannerstatus ;
      scannerstatus = 0 ;
      gettoken () ;
      if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
      cx = curtok ;
      scannerstatus = savescannerstatus ;
    } 
    break ;
  case 5 : 
    scanfontident () ;
    break ;
  case 11 : 
    ;
    break ;
  case 12 : 
    {
      savescannerstatus = scannerstatus ;
      savedefref = defref ;
      if ( strstart [strptr ]< poolptr ) 
      u = makestring () ;
      else u = 0 ;
      comparestrings () ;
      defref = savedefref ;
      scannerstatus = savescannerstatus ;
      if ( u != 0 ) 
      decr ( strptr ) ;
    } 
    break ;
  case 13 : 
    {
      b = poolptr ;
      getcreationdate () ;
      mem [memtop - 12 ].hh .v.RH = strtoks ( b ) ;
      begintokenlist ( mem [memtop - 3 ].hh .v.RH , 4 ) ;
      return ;
    } 
    break ;
  case 14 : 
    {
      savescannerstatus = scannerstatus ;
      savewarningindex = warningindex ;
      savedefref = defref ;
      if ( strstart [strptr ]< poolptr ) 
      u = makestring () ;
      else u = 0 ;
      scanpdfexttoks () ;
      s = tokenstostring ( defref ) ;
      deletetokenref ( defref ) ;
      defref = savedefref ;
      warningindex = savewarningindex ;
      scannerstatus = savescannerstatus ;
      b = poolptr ;
      getfilemoddate ( s ) ;
      mem [memtop - 12 ].hh .v.RH = strtoks ( b ) ;
      flushstr ( s ) ;
      begintokenlist ( mem [memtop - 3 ].hh .v.RH , 4 ) ;
      if ( u != 0 ) 
      decr ( strptr ) ;
      return ;
    } 
    break ;
  case 15 : 
    {
      savescannerstatus = scannerstatus ;
      savewarningindex = warningindex ;
      savedefref = defref ;
      if ( strstart [strptr ]< poolptr ) 
      u = makestring () ;
      else u = 0 ;
      scanpdfexttoks () ;
      s = tokenstostring ( defref ) ;
      deletetokenref ( defref ) ;
      defref = savedefref ;
      warningindex = savewarningindex ;
      scannerstatus = savescannerstatus ;
      b = poolptr ;
      getfilesize ( s ) ;
      mem [memtop - 12 ].hh .v.RH = strtoks ( b ) ;
      flushstr ( s ) ;
      begintokenlist ( mem [memtop - 3 ].hh .v.RH , 4 ) ;
      if ( u != 0 ) 
      decr ( strptr ) ;
      return ;
    } 
    break ;
  case 16 : 
    {
      savescannerstatus = scannerstatus ;
      savewarningindex = warningindex ;
      savedefref = defref ;
      if ( strstart [strptr ]< poolptr ) 
      u = makestring () ;
      else u = 0 ;
      bool = scankeyword ( 825 ) ;
      scanpdfexttoks () ;
      if ( bool ) 
      s = tokenstostring ( defref ) ;
      else {
	  
	isprintutf8 = true ;
	s = tokenstostring ( defref ) ;
	isprintutf8 = false ;
      } 
      deletetokenref ( defref ) ;
      defref = savedefref ;
      warningindex = savewarningindex ;
      scannerstatus = savescannerstatus ;
      b = poolptr ;
      getmd5sum ( s , bool ) ;
      mem [memtop - 12 ].hh .v.RH = strtoks ( b ) ;
      flushstr ( s ) ;
      begintokenlist ( mem [memtop - 3 ].hh .v.RH , 4 ) ;
      if ( u != 0 ) 
      decr ( strptr ) ;
      return ;
    } 
    break ;
  case 17 : 
    {
      savescannerstatus = scannerstatus ;
      savewarningindex = warningindex ;
      savedefref = defref ;
      if ( strstart [strptr ]< poolptr ) 
      u = makestring () ;
      else u = 0 ;
      curval = 0 ;
      if ( ( scankeyword ( 826 ) ) ) 
      {
	scanint () ;
	if ( ( curval < 0 ) ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 827 ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 828 ;
	    helpline [0 ]= 727 ;
	  } 
	  interror ( curval ) ;
	  curval = 0 ;
	} 
      } 
      i = curval ;
      curval = 0 ;
      if ( ( scankeyword ( 829 ) ) ) 
      {
	scanint () ;
	if ( ( curval < 0 ) ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 830 ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 831 ;
	    helpline [0 ]= 727 ;
	  } 
	  interror ( curval ) ;
	  curval = 0 ;
	} 
      } 
      j = curval ;
      scanpdfexttoks () ;
      s = tokenstostring ( defref ) ;
      deletetokenref ( defref ) ;
      defref = savedefref ;
      warningindex = savewarningindex ;
      scannerstatus = savescannerstatus ;
      b = poolptr ;
      getfiledump ( s , i , j ) ;
      mem [memtop - 12 ].hh .v.RH = strtoks ( b ) ;
      flushstr ( s ) ;
      begintokenlist ( mem [memtop - 3 ].hh .v.RH , 4 ) ;
      if ( u != 0 ) 
      decr ( strptr ) ;
      return ;
    } 
    break ;
  case 18 : 
    if ( jobname == 0 ) 
    openlogfile () ;
    break ;
  } 
  u = 0 ;
  oldsetting = selector ;
  selector = 21 ;
  b = poolptr ;
  switch ( c ) 
  {case 0 : 
    printint ( curval ) ;
    break ;
  case 1 : 
    printromanint ( curval ) ;
    break ;
  case 8 : 
    printint ( fromJIS ( curval ) ) ;
    break ;
  case 6 : 
    printint ( fromEUC ( curval ) ) ;
    break ;
  case 7 : 
    printint ( fromSJIS ( curval ) ) ;
    break ;
  case 9 : 
    printint ( fromKUTEN ( curval ) ) ;
    break ;
  case 10 : 
    printint ( fromUCS ( curval ) ) ;
    break ;
  case 2 : 
    printkansuji ( curval ) ;
    break ;
  case 3 : 
    if ( curcs != 0 ) 
    sprintcs ( curcs ) ;
    else if ( cx == 0 ) 
    printchar ( curchr ) ;
    else printkanji ( cx ) ;
    break ;
  case 4 : 
    printmeaning () ;
    break ;
  case 5 : 
    {
      print ( fontname [curval ]) ;
      if ( fontsize [curval ]!= fontdsize [curval ]) 
      {
	print ( 832 ) ;
	printscaled ( fontsize [curval ]) ;
	print ( 419 ) ;
      } 
    } 
    break ;
  case 11 : 
    print ( 256 ) ;
    break ;
  case 12 : 
    printint ( curval ) ;
    break ;
  case 18 : 
    print ( jobname ) ;
    break ;
  } 
  selector = oldsetting ;
  mem [memtop - 12 ].hh .v.RH = strtoks ( b ) ;
  begintokenlist ( mem [memtop - 3 ].hh .v.RH , 4 ) ;
} 
halfword 
zscantoks ( boolean macrodef , boolean xpand ) 
{
  /* 40 30 31 32 */ register halfword Result; scantoks_regmem 
  halfword t  ;
  halfword s  ;
  halfword p  ;
  halfword q  ;
  halfword unbalance  ;
  halfword hashbrace  ;
  if ( macrodef ) 
  scannerstatus = 2 ;
  else scannerstatus = 5 ;
  warningindex = curcs ;
  defref = getavail () ;
  mem [defref ].hh .v.LH = -1073741823L ;
  p = defref ;
  hashbrace = 0 ;
  t = 3120 ;
  if ( macrodef ) 
  {
    while ( true ) {
	
      gettoken () ;
      if ( curtok < 768 ) 
      goto lab31 ;
      if ( curcmd == 6 ) 
      {
	s = 3328 + curchr ;
	gettoken () ;
	if ( curcmd == 1 ) 
	{
	  hashbrace = curtok ;
	  {
	    q = getavail () ;
	    mem [p ].hh .v.RH = q ;
	    mem [q ].hh .v.LH = curtok ;
	    p = q ;
	  } 
	  {
	    q = getavail () ;
	    mem [p ].hh .v.RH = q ;
	    mem [q ].hh .v.LH = 3584 ;
	    p = q ;
	  } 
	  goto lab30 ;
	} 
	if ( t == 3129 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 835 ) ;
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 836 ;
	  } 
	  error () ;
	} 
	else {
	    
	  incr ( t ) ;
	  if ( curtok != t ) 
	  {
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 264 ) ;
	      print ( 837 ) ;
	    } 
	    {
	      helpptr = 2 ;
	      helpline [1 ]= 838 ;
	      helpline [0 ]= 839 ;
	    } 
	    backerror () ;
	  } 
	  curtok = s ;
	} 
      } 
      {
	q = getavail () ;
	mem [p ].hh .v.RH = q ;
	mem [q ].hh .v.LH = curtok ;
	p = q ;
      } 
    } 
    lab31: {
	
      q = getavail () ;
      mem [p ].hh .v.RH = q ;
      mem [q ].hh .v.LH = 3584 ;
      p = q ;
    } 
    if ( curcmd == 2 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 718 ) ;
      } 
      incr ( alignstate ) ;
      {
	helpptr = 2 ;
	helpline [1 ]= 833 ;
	helpline [0 ]= 834 ;
      } 
      error () ;
      goto lab40 ;
    } 
    lab30: ;
  } 
  else scanleftbrace () ;
  unbalance = 1 ;
  while ( true ) {
      
    if ( xpand ) 
    {
      while ( true ) {
	  
	getnext () ;
	if ( curcmd >= 127 ) {
	    
	  if ( mem [mem [curchr ].hh .v.RH ].hh .v.LH == 3585 ) 
	  {
	    curcmd = 0 ;
	    curchr = 257 ;
	  } 
	} 
	if ( curcmd <= 116 ) 
	goto lab32 ;
	if ( curcmd != 125 ) 
	expand () ;
	else {
	    
	  q = thetoks () ;
	  if ( mem [memtop - 3 ].hh .v.RH != -1073741823L ) 
	  {
	    mem [p ].hh .v.RH = mem [memtop - 3 ].hh .v.RH ;
	    p = q ;
	  } 
	} 
      } 
      lab32: xtoken () ;
    } 
    else gettoken () ;
    if ( curtok < 768 ) {
	
      if ( curcmd < 2 ) 
      incr ( unbalance ) ;
      else {
	  
	decr ( unbalance ) ;
	if ( unbalance == 0 ) 
	goto lab40 ;
      } 
    } 
    else if ( curcmd == 6 ) {
	
      if ( macrodef ) 
      {
	s = curtok ;
	if ( xpand ) 
	getxtoken () ;
	else gettoken () ;
	if ( curcmd != 6 ) {
	    
	  if ( ( curtok <= 3120 ) || ( curtok > t ) ) 
	  {
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 264 ) ;
	      print ( 840 ) ;
	    } 
	    sprintcs ( warningindex ) ;
	    {
	      helpptr = 3 ;
	      helpline [2 ]= 841 ;
	      helpline [1 ]= 842 ;
	      helpline [0 ]= 843 ;
	    } 
	    backerror () ;
	    curtok = s ;
	  } 
	  else curtok = 1232 + curchr ;
	} 
      } 
    } 
    {
      q = getavail () ;
      mem [p ].hh .v.RH = q ;
      mem [q ].hh .v.LH = curtok ;
      p = q ;
    } 
  } 
  lab40: scannerstatus = 0 ;
  if ( hashbrace != 0 ) 
  {
    q = getavail () ;
    mem [p ].hh .v.RH = q ;
    mem [q ].hh .v.LH = hashbrace ;
    p = q ;
  } 
  Result = p ;
  return Result ;
} 
void 
zreadtoks ( integer n , halfword r , halfword j ) 
{
  /* 30 */ readtoks_regmem 
  halfword p  ;
  halfword q  ;
  integer s  ;
  smallnumber m  ;
  scannerstatus = 2 ;
  warningindex = r ;
  defref = getavail () ;
  mem [defref ].hh .v.LH = -1073741823L ;
  p = defref ;
  {
    q = getavail () ;
    mem [p ].hh .v.RH = q ;
    mem [q ].hh .v.LH = 3584 ;
    p = q ;
  } 
  if ( ( n < 0 ) || ( n > 15 ) ) 
  m = 16 ;
  else m = n ;
  s = alignstate ;
  alignstate = 1000000L ;
  do {
      beginfilereading () ;
    curinput .namefield = m + 1 ;
    if ( readopen [m ]== 2 ) {
	
      if ( interaction > 1 ) {
	  
	if ( n < 0 ) 
	{
	  ;
	  print ( 344 ) ;
	  terminput () ;
	} 
	else {
	    
	  ;
	  println () ;
	  sprintcs ( r ) ;
	  {
	    ;
	    print ( 61 ) ;
	    terminput () ;
	  } 
	  n = -1 ;
	} 
      } 
      else fatalerror ( 844 ) ;
    } 
    else if ( readopen [m ]== 1 ) {
	
      if ( inputln ( readfile [m ], false ) ) 
      readopen [m ]= 0 ;
      else {
	  
	aclose ( readfile [m ]) ;
	readopen [m ]= 2 ;
      } 
    } 
    else {
	
      if ( ! inputln ( readfile [m ], true ) ) 
      {
	aclose ( readfile [m ]) ;
	readopen [m ]= 2 ;
	if ( alignstate != 1000000L ) 
	{
	  runaway () ;
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 845 ) ;
	  } 
	  printesc ( 584 ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 846 ;
	  } 
	  alignstate = 1000000L ;
	  error () ;
	} 
      } 
    } 
    curinput .limitfield = last ;
    if ( ( eqtb [29237 ].cint < 0 ) || ( eqtb [29237 ].cint > 255 ) ) 
    decr ( curinput .limitfield ) ;
    else buffer [curinput .limitfield ]= eqtb [29237 ].cint ;
    first = curinput .limitfield + 1 ;
    curinput .locfield = curinput .startfield ;
    curinput .statefield = 61 ;
    if ( j == 1 ) 
    {
      while ( curinput .locfield <= curinput .limitfield ) {
	  
	curchr = buffer [curinput .locfield ];
	incr ( curinput .locfield ) ;
	if ( curchr == 32 ) 
	curtok = 2592 ;
	else curtok = curchr + 3072 ;
	{
	  q = getavail () ;
	  mem [p ].hh .v.RH = q ;
	  mem [q ].hh .v.LH = curtok ;
	  p = q ;
	} 
      } 
      goto lab30 ;
    } 
    while ( true ) {
	
      gettoken () ;
      if ( curtok == 0 ) 
      goto lab30 ;
      if ( alignstate < 1000000L ) 
      {
	do {
	    gettoken () ;
	} while ( ! ( curtok == 0 ) ) ;
	alignstate = 1000000L ;
	goto lab30 ;
      } 
      {
	q = getavail () ;
	mem [p ].hh .v.RH = q ;
	mem [q ].hh .v.LH = curtok ;
	p = q ;
      } 
    } 
    lab30: endfilereading () ;
  } while ( ! ( alignstate == 1000000L ) ) ;
  curval = defref ;
  scannerstatus = 0 ;
  alignstate = s ;
} 
void 
passtext ( void ) 
{
  /* 30 */ passtext_regmem 
  integer l  ;
  smallnumber savescannerstatus  ;
  savescannerstatus = scannerstatus ;
  scannerstatus = 1 ;
  l = 0 ;
  skipline = line ;
  while ( true ) {
      
    getnext () ;
    if ( curcmd == 122 ) 
    {
      if ( l == 0 ) 
      goto lab30 ;
      if ( curchr == 2 ) 
      decr ( l ) ;
    } 
    else if ( curcmd == 121 ) 
    incr ( l ) ;
  } 
  lab30: scannerstatus = savescannerstatus ;
  if ( eqtb [29254 ].cint > 0 ) 
  showcurcmdchr () ;
} 
void 
zchangeiflimit ( smallnumber l , halfword p ) 
{
  /* 10 */ changeiflimit_regmem 
  halfword q  ;
  if ( p == condptr ) 
  iflimit = l ;
  else {
      
    q = condptr ;
    while ( true ) {
	
      if ( q == -1073741823L ) 
      confusion ( 847 ) ;
      if ( mem [q ].hh .v.RH == p ) 
      {
	mem [q ].hh.b0 = l ;
	return ;
      } 
      q = mem [q ].hh .v.RH ;
    } 
  } 
} 
void 
conditional ( void ) 
{
  /* 10 50 */ conditional_regmem 
  boolean b  ;
  unsigned char r  ;
  integer m, n  ;
  halfword p, q  ;
  smallnumber savescannerstatus  ;
  halfword savecondptr  ;
  smallnumber thisif  ;
  boolean isunless  ;
  if ( eqtb [29254 ].cint > 0 ) {
      
    if ( eqtb [29224 ].cint <= 1 ) 
    showcurcmdchr () ;
  } 
  {
    p = getnode ( 2 ) ;
    mem [p ].hh .v.RH = condptr ;
    mem [p ].hh.b0 = iflimit ;
    mem [p ].hh.b1 = curif ;
    mem [p + 1 ].cint = ifline ;
    condptr = p ;
    curif = curchr ;
    iflimit = 1 ;
    ifline = line ;
  } 
  savecondptr = condptr ;
  isunless = ( curchr >= 32 ) ;
  thisif = curchr % 32 ;
  switch ( thisif ) 
  {case 0 : 
  case 1 : 
    {
      {
	getxtoken () ;
	if ( curcmd == 0 ) {
	    
	  if ( curchr == 257 ) 
	  {
	    curcmd = 13 ;
	    curchr = curtok - 536870912L ;
	  } 
	} 
      } 
      if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
      {
	m = curcmd ;
	n = curchr ;
      } 
      else if ( ( curcmd > 13 ) || ( curchr > 255 ) ) 
      {
	m = 0 ;
	n = 256 ;
      } 
      else {
	  
	m = curcmd ;
	n = curchr ;
      } 
      {
	getxtoken () ;
	if ( curcmd == 0 ) {
	    
	  if ( curchr == 257 ) 
	  {
	    curcmd = 13 ;
	    curchr = curtok - 536870912L ;
	  } 
	} 
      } 
      if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
      {
	curcmd = curcmd ;
      } 
      else if ( ( curcmd > 13 ) || ( curchr > 255 ) ) 
      {
	curcmd = 0 ;
	curchr = 256 ;
      } 
      if ( thisif == 0 ) 
      b = ( n == curchr ) ;
      else b = ( m == curcmd ) ;
    } 
    break ;
  case 2 : 
  case 3 : 
    {
      if ( thisif == 2 ) 
      scanint () ;
      else scandimen ( false , false , false ) ;
      n = curval ;
      do {
	  getxtoken () ;
      } while ( ! ( curcmd != 10 ) ) ;
      if ( ( curtok >= 3132 ) && ( curtok <= 3134 ) ) 
      r = curtok - 3072 ;
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 879 ) ;
	} 
	printcmdchr ( 121 , thisif ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 880 ;
	} 
	backerror () ;
	r = 61 ;
      } 
      if ( thisif == 2 ) 
      scanint () ;
      else scandimen ( false , false , false ) ;
      switch ( r ) 
      {case 60 : 
	b = ( n < curval ) ;
	break ;
      case 61 : 
	b = ( n == curval ) ;
	break ;
      case 62 : 
	b = ( n > curval ) ;
	break ;
      } 
    } 
    break ;
  case 4 : 
    {
      scanint () ;
      b = odd ( curval ) ;
    } 
    break ;
  case 5 : 
    b = ( abs ( curlist .modefield ) == 1 ) ;
    break ;
  case 6 : 
    b = ( abs ( curlist .modefield ) == 118 ) ;
    break ;
  case 7 : 
    b = ( abs ( curlist .modefield ) == 235 ) ;
    break ;
  case 8 : 
    b = ( curlist .modefield < 0 ) ;
    break ;
  case 20 : 
    b = ( abs ( curlist .dirfield ) == 3 ) ;
    break ;
  case 21 : 
    b = ( abs ( curlist .dirfield ) == 4 ) ;
    break ;
  case 22 : 
    b = ( abs ( curlist .dirfield ) == 1 ) ;
    break ;
  case 23 : 
    b = ( curlist .dirfield < 0 ) ;
    break ;
  case 9 : 
  case 10 : 
  case 11 : 
  case 24 : 
  case 25 : 
  case 26 : 
    {
      scanregisternum () ;
      if ( curval < 256 ) 
      p = eqtb [25332 + curval ].hh .v.RH ;
      else {
	  
	findsaelement ( 4 , curval , false ) ;
	if ( curptr == -1073741823L ) 
	p = -1073741823L ;
	else p = mem [curptr + 1 ].hh .v.RH ;
      } 
      if ( thisif == 9 ) 
      b = ( p == -1073741823L ) ;
      else if ( p == -1073741823L ) 
      b = false ;
      else {
	  
	if ( mem [p ].hh.b0 == 2 ) 
	p = mem [p + 5 ].hh .v.RH ;
	if ( thisif == 10 ) 
	b = ( mem [p ].hh.b0 == 0 ) ;
	else if ( thisif == 11 ) 
	b = ( mem [p ].hh.b0 == 1 ) ;
	else if ( thisif == 24 ) 
	b = ( ( ( mem [p ].hh.b1 ) % 8 ) == 3 ) ;
	else if ( thisif == 25 ) 
	b = ( ( ( mem [p ].hh.b1 ) % 8 ) == 4 ) ;
	else b = ( ( ( mem [p ].hh.b1 ) % 8 ) == 1 ) ;
      } 
    } 
    break ;
  case 27 : 
    {
      savescannerstatus = scannerstatus ;
      scannerstatus = 0 ;
      getnext () ;
      scannerstatus = savescannerstatus ;
      if ( curcs < 514 ) 
      m = primlookup ( curcs - 257 ) ;
      else m = primlookup ( hash [curcs ].v.RH ) ;
      b = ( ( curcmd != 117 ) && ( m != 0 ) && ( curcmd == primeqtb [m ]
      .hh.b0 ) && ( curchr == primeqtb [m ].hh .v.RH ) ) ;
    } 
    break ;
  case 12 : 
    {
      savescannerstatus = scannerstatus ;
      scannerstatus = 0 ;
      getnext () ;
      n = curcs ;
      p = curcmd ;
      q = curchr ;
      getnext () ;
      if ( curcmd != p ) 
      b = false ;
      else if ( curcmd < 127 ) 
      b = ( curchr == q ) ;
      else {
	  
	p = mem [curchr ].hh .v.RH ;
	q = mem [eqtb [n ].hh .v.RH ].hh .v.RH ;
	if ( p == q ) 
	b = true ;
	else {
	    
	  while ( ( p != -1073741823L ) && ( q != -1073741823L ) ) if ( mem [
	  p ].hh .v.LH != mem [q ].hh .v.LH ) 
	  p = -1073741823L ;
	  else {
	      
	    p = mem [p ].hh .v.RH ;
	    q = mem [q ].hh .v.RH ;
	  } 
	  b = ( ( p == -1073741823L ) && ( q == -1073741823L ) ) ;
	} 
      } 
      scannerstatus = savescannerstatus ;
    } 
    break ;
  case 13 : 
    {
      scanfourbitintor18 () ;
      if ( curval == 18 ) 
      b = ! shellenabledp ;
      else b = ( readopen [curval ]== 2 ) ;
    } 
    break ;
  case 14 : 
    b = true ;
    break ;
  case 15 : 
    b = false ;
    break ;
  case 17 : 
    {
      savescannerstatus = scannerstatus ;
      scannerstatus = 0 ;
      getnext () ;
      b = ( curcmd != 117 ) ;
      scannerstatus = savescannerstatus ;
    } 
    break ;
  case 18 : 
    {
      n = getavail () ;
      p = n ;
      do {
	  getxtoken () ;
	if ( curcs == 0 ) 
	{
	  q = getavail () ;
	  mem [p ].hh .v.RH = q ;
	  mem [q ].hh .v.LH = curtok ;
	  p = q ;
	} 
      } while ( ! ( curcs != 0 ) ) ;
      if ( curcmd != 72 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 686 ) ;
	} 
	printesc ( 547 ) ;
	print ( 687 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 688 ;
	  helpline [0 ]= 689 ;
	} 
	backerror () ;
      } 
      m = first ;
      p = mem [n ].hh .v.RH ;
      while ( p != -1073741823L ) {
	  
	if ( m >= maxbufstack ) 
	{
	  maxbufstack = m + 1 ;
	  if ( maxbufstack == bufsize ) 
	  overflow ( 258 , bufsize ) ;
	} 
	if ( checkkanji ( mem [p ].hh .v.LH ) ) 
	{
	  if ( BYTE1 ( toBUFF ( mem [p ].hh .v.LH % 16777216L ) ) != 0 ) 
	  {
	    buffer [m ]= BYTE1 ( toBUFF ( mem [p ].hh .v.LH % 16777216L ) 
	    ) ;
	    incr ( m ) ;
	  } 
	  if ( BYTE2 ( toBUFF ( mem [p ].hh .v.LH % 16777216L ) ) != 0 ) 
	  {
	    buffer [m ]= BYTE2 ( toBUFF ( mem [p ].hh .v.LH % 16777216L ) 
	    ) ;
	    incr ( m ) ;
	  } 
	  if ( BYTE3 ( toBUFF ( mem [p ].hh .v.LH % 16777216L ) ) != 0 ) 
	  {
	    buffer [m ]= BYTE3 ( toBUFF ( mem [p ].hh .v.LH % 16777216L ) 
	    ) ;
	    incr ( m ) ;
	  } 
	  buffer [m ]= BYTE4 ( toBUFF ( mem [p ].hh .v.LH % 16777216L ) ) 
	  ;
	  incr ( m ) ;
	  p = mem [p ].hh .v.RH ;
	} 
	else {
	    
	  buffer [m ]= mem [p ].hh .v.LH % 256 ;
	  incr ( m ) ;
	  p = mem [p ].hh .v.RH ;
	} 
      } 
      if ( m > first + 1 ) 
      curcs = idlookup ( first , m - first ) ;
      else if ( m == first ) 
      curcs = 513 ;
      else curcs = 257 + buffer [first ];
      flushlist ( n ) ;
      b = ( eqtb [curcs ].hh.b0 != 117 ) ;
    } 
    break ;
  case 19 : 
    {
      scanfontident () ;
      n = curval ;
      scancharnum () ;
      if ( ( fontbc [n ]<= curval ) && ( fontec [n ]>= curval ) ) 
      b = ( fontinfo [charbase [n ]+ curval ].qqqq .b0 > 0 ) ;
      else b = false ;
    } 
    break ;
  case 16 : 
    {
      scanint () ;
      n = curval ;
      if ( eqtb [29224 ].cint > 1 ) 
      {
	begindiagnostic () ;
	print ( 881 ) ;
	printint ( n ) ;
	printchar ( 125 ) ;
	enddiagnostic ( false ) ;
      } 
      while ( n != 0 ) {
	  
	passtext () ;
	if ( condptr == savecondptr ) {
	    
	  if ( curchr == 4 ) 
	  decr ( n ) ;
	  else goto lab50 ;
	} 
	else if ( curchr == 2 ) 
	{
	  if ( ifstack [inopen ]== condptr ) 
	  ifwarning () ;
	  p = condptr ;
	  ifline = mem [p + 1 ].cint ;
	  curif = mem [p ].hh.b1 ;
	  iflimit = mem [p ].hh.b0 ;
	  condptr = mem [p ].hh .v.RH ;
	  freenode ( p , 2 ) ;
	} 
      } 
      changeiflimit ( 4 , savecondptr ) ;
      return ;
    } 
    break ;
  } 
  if ( isunless ) 
  b = ! b ;
  if ( eqtb [29224 ].cint > 1 ) 
  {
    begindiagnostic () ;
    if ( b ) 
    print ( 877 ) ;
    else print ( 878 ) ;
    enddiagnostic ( false ) ;
  } 
  if ( b ) 
  {
    changeiflimit ( 3 , savecondptr ) ;
    return ;
  } 
  while ( true ) {
      
    passtext () ;
    if ( condptr == savecondptr ) 
    {
      if ( curchr != 4 ) 
      goto lab50 ;
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 875 ) ;
      } 
      printesc ( 873 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 876 ;
      } 
      error () ;
    } 
    else if ( curchr == 2 ) 
    {
      if ( ifstack [inopen ]== condptr ) 
      ifwarning () ;
      p = condptr ;
      ifline = mem [p + 1 ].cint ;
      curif = mem [p ].hh.b1 ;
      iflimit = mem [p ].hh.b0 ;
      condptr = mem [p ].hh .v.RH ;
      freenode ( p , 2 ) ;
    } 
  } 
  lab50: if ( curchr == 2 ) 
  {
    if ( ifstack [inopen ]== condptr ) 
    ifwarning () ;
    p = condptr ;
    ifline = mem [p + 1 ].cint ;
    curif = mem [p ].hh.b1 ;
    iflimit = mem [p ].hh.b0 ;
    condptr = mem [p ].hh .v.RH ;
    freenode ( p , 2 ) ;
  } 
  else iflimit = 2 ;
} 
void 
beginname ( void ) 
{
  beginname_regmem 
  areadelimiter = 0 ;
  extdelimiter = 0 ;
  quotedfilename = false ;
  prevchar = 0 ;
} 
boolean 
zmorename ( ASCIIcode c ) 
{
  register boolean Result; morename_regmem 
  if ( ( c == 32 ) && stopatspace && ( ! quotedfilename ) ) 
  Result = false ;
  else if ( c == 34 ) 
  {
    quotedfilename = ! quotedfilename ;
    Result = true ;
  } 
  else {
      
    {
      if ( poolptr + 1 > poolsize ) 
      overflow ( 259 , poolsize - initpoolptr ) ;
    } 
    {
      strpool [poolptr ]= c ;
      incr ( poolptr ) ;
    } 
    if ( ( ISDIRSEP ( c ) && ( notkanjicharseq ( prevchar , c ) ) ) ) 
    {
      areadelimiter = ( poolptr - strstart [strptr ]) ;
      extdelimiter = 0 ;
    } 
    else if ( c == 46 ) 
    extdelimiter = ( poolptr - strstart [strptr ]) ;
    Result = true ;
  } 
  prevchar = c ;
  return Result ;
} 
void 
endname ( void ) 
{
  endname_regmem 
  strnumber tempstr  ;
  poolpointer j, s, t  ;
  boolean mustquote  ;
  if ( strptr + 3 > maxstrings ) 
  overflow ( 260 , maxstrings - initstrptr ) ;
  {
    if ( poolptr + 6 > poolsize ) 
    overflow ( 259 , poolsize - initpoolptr ) ;
  } 
  if ( areadelimiter != 0 ) 
  {
    mustquote = false ;
    s = strstart [strptr ];
    t = strstart [strptr ]+ areadelimiter ;
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
      if ( extdelimiter != 0 ) 
      extdelimiter = extdelimiter + 2 ;
      areadelimiter = areadelimiter + 2 ;
      poolptr = poolptr + 2 ;
    } 
  } 
  s = strstart [strptr ]+ areadelimiter ;
  if ( extdelimiter == 0 ) 
  t = poolptr ;
  else t = strstart [strptr ]+ extdelimiter - 1 ;
  mustquote = false ;
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
    if ( extdelimiter != 0 ) 
    extdelimiter = extdelimiter + 2 ;
    poolptr = poolptr + 2 ;
  } 
  if ( extdelimiter != 0 ) 
  {
    s = strstart [strptr ]+ extdelimiter - 1 ;
    t = poolptr ;
    mustquote = false ;
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
  } 
  if ( areadelimiter == 0 ) 
  curarea = 344 ;
  else {
      
    curarea = strptr ;
    strstart [strptr + 1 ]= strstart [strptr ]+ areadelimiter ;
    incr ( strptr ) ;
    tempstr = searchstring ( curarea ) ;
    if ( tempstr > 0 ) 
    {
      curarea = tempstr ;
      decr ( strptr ) ;
      {register integer for_end; j = strstart [strptr + 1 ];for_end = 
      poolptr - 1 ; if ( j <= for_end) do 
	{
	  strpool [j - areadelimiter ]= strpool [j ];
	} 
      while ( j++ < for_end ) ;} 
      poolptr = poolptr - areadelimiter ;
    } 
  } 
  if ( extdelimiter == 0 ) 
  {
    curext = 344 ;
    curname = slowmakestring () ;
  } 
  else {
      
    curname = strptr ;
    strstart [strptr + 1 ]= strstart [strptr ]+ extdelimiter - 
    areadelimiter - 1 ;
    incr ( strptr ) ;
    curext = makestring () ;
    decr ( strptr ) ;
    tempstr = searchstring ( curname ) ;
    if ( tempstr > 0 ) 
    {
      curname = tempstr ;
      decr ( strptr ) ;
      {register integer for_end; j = strstart [strptr + 1 ];for_end = 
      poolptr - 1 ; if ( j <= for_end) do 
	{
	  strpool [j - extdelimiter + areadelimiter + 1 ]= strpool [j ];
	} 
      while ( j++ < for_end ) ;} 
      poolptr = poolptr - extdelimiter + areadelimiter + 1 ;
    } 
    curext = slowmakestring () ;
  } 
} 
void 
zpackfilename ( strnumber n , strnumber a , strnumber e ) 
{
  packfilename_regmem 
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
  packbufferedname_regmem 
  integer k  ;
  ASCIIcode c  ;
  integer j  ;
  if ( n + b - a + 5 > maxint ) 
  b = a + maxint - n - 5 ;
  k = 0 ;
  if ( nameoffile ) 
  libcfree ( nameoffile ) ;
  nameoffile = xmallocarray ( ASCIIcode , n + ( b - a + 1 ) + 5 ) ;
  {register integer for_end; j = 1 ;for_end = n ; if ( j <= for_end) do 
    {
      c = xord [ucharcast ( TEXformatdefault [j ]) ];
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
  {register integer for_end; j = formatdefaultlength - 3 ;for_end = 
  formatdefaultlength ; if ( j <= for_end) do 
    {
      c = xord [ucharcast ( TEXformatdefault [j ]) ];
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
  register strnumber Result; makenamestring_regmem 
  integer k  ;
  poolpointer saveareadelimiter, saveextdelimiter  ;
  boolean savenameinprogress, savestopatspace  ;
  if ( ( poolptr + namelength > poolsize ) || ( strptr == maxstrings ) || ( ( 
  poolptr - strstart [strptr ]) > 0 ) ) 
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
    saveareadelimiter = areadelimiter ;
    saveextdelimiter = extdelimiter ;
    savenameinprogress = nameinprogress ;
    savestopatspace = stopatspace ;
    nameinprogress = true ;
    beginname () ;
    stopatspace = false ;
    k = 1 ;
    while ( ( k <= namelength ) && ( morename ( nameoffile [k ]) ) ) incr ( 
    k ) ;
    stopatspace = savestopatspace ;
    endname () ;
    nameinprogress = savenameinprogress ;
    areadelimiter = saveareadelimiter ;
    extdelimiter = saveextdelimiter ;
  } 
  return Result ;
} 
strnumber 
zamakenamestring ( alphafile f ) 
{
  register strnumber Result; amakenamestring_regmem 
  Result = makenamestring () ;
  return Result ;
} 
strnumber 
zbmakenamestring ( bytefile f ) 
{
  register strnumber Result; bmakenamestring_regmem 
  Result = makenamestring () ;
  return Result ;
} 
strnumber 
zwmakenamestring ( wordfile f ) 
{
  register strnumber Result; wmakenamestring_regmem 
  Result = makenamestring () ;
  return Result ;
} 
void 
scanfilename ( void ) 
{
  /* 30 */ scanfilename_regmem 
  nameinprogress = true ;
  beginname () ;
  do {
      getxtoken () ;
  } while ( ! ( curcmd != 10 ) ) ;
  skipmode = false ;
  while ( true ) {
      
    if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
    {
      {
	if ( poolptr + 4 > poolsize ) 
	overflow ( 259 , poolsize - initpoolptr ) ;
      } 
      curchr = toBUFF ( curchr ) ;
      if ( BYTE1 ( curchr ) != 0 ) 
      {
	strpool [poolptr ]= BYTE1 ( curchr ) ;
	incr ( poolptr ) ;
      } 
      if ( BYTE2 ( curchr ) != 0 ) 
      {
	strpool [poolptr ]= BYTE2 ( curchr ) ;
	incr ( poolptr ) ;
      } 
      if ( BYTE3 ( curchr ) != 0 ) 
      {
	strpool [poolptr ]= BYTE3 ( curchr ) ;
	incr ( poolptr ) ;
      } 
      {
	strpool [poolptr ]= BYTE4 ( curchr ) ;
	incr ( poolptr ) ;
      } 
    } 
    else if ( ( curcmd > 12 ) || ( curchr > 255 ) ) 
    {
      backinput () ;
      goto lab30 ;
    } 
    else if ( ( ( curchr == 32 ) && ( curinput .statefield != 0 ) && ( 
    curinput .locfield > curinput .limitfield ) ) || ! morename ( curchr ) ) 
    goto lab30 ;
    getxtoken () ;
  } 
  lab30: endname () ;
  nameinprogress = false ;
  skipmode = true ;
} 
void 
zpackjobname ( strnumber s ) 
{
  packjobname_regmem 
  curarea = 344 ;
  curext = s ;
  curname = jobname ;
  packfilename ( curname , curarea , curext ) ;
} 
void 
zpromptfilename ( strnumber s , strnumber e ) 
{
  /* 30 */ promptfilename_regmem 
  integer k  ;
  strnumber savedcurname  ;
  strnumber savedcurext  ;
  strnumber savedcurarea  ;
  if ( interaction == 2 ) 
  ;
  if ( s == 883 ) 
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 884 ) ;
  } 
  else {
      
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 885 ) ;
  } 
  printfilename ( curname , curarea , curext ) ;
  print ( 886 ) ;
  if ( ( e == 887 ) || ( e == 344 ) ) 
  showcontext () ;
  println () ;
  printcstring ( promptfilenamehelpmsg ) ;
  if ( ( e != 344 ) ) 
  {
    print ( 888 ) ;
    print ( e ) ;
    print ( 39 ) ;
  } 
  print ( 41 ) ;
  println () ;
  printnl ( 889 ) ;
  print ( s ) ;
  if ( interaction < 2 ) 
  fatalerror ( 890 ) ;
  savedcurname = curname ;
  savedcurext = curext ;
  savedcurarea = curarea ;
  {
    ;
    print ( 622 ) ;
    terminput () ;
  } 
  {
    beginname () ;
    k = first ;
    while ( ( buffer [k ]== 32 ) && ( k < last ) ) incr ( k ) ;
    while ( true ) {
	
      if ( k == last ) 
      goto lab30 ;
      if ( ! morename ( buffer [k ]) ) 
      goto lab30 ;
      incr ( k ) ;
    } 
    lab30: endname () ;
  } 
  if ( ( ( strstart [curname + 1 ]- strstart [curname ]) == 0 ) && ( 
  curext == 344 ) && ( curarea == 344 ) ) 
  {
    curname = savedcurname ;
    curext = savedcurext ;
    curarea = savedcurarea ;
  } 
  else if ( curext == 344 ) 
  curext = e ;
  packfilename ( curname , curarea , curext ) ;
} 
void 
openlogfile ( void ) 
{
  openlogfile_regmem 
  unsigned char oldsetting  ;
  integer k  ;
  integer l  ;
  constcstring months  ;
  oldsetting = selector ;
  if ( jobname == 0 ) 
  jobname = getjobname ( 893 ) ;
  packjobname ( 894 ) ;
  recorderchangefilename ( stringcast ( nameoffile + 1 ) ) ;
  packjobname ( 895 ) ;
  while ( ! aopenout ( logfile ) ) {
      
    selector = 17 ;
    promptfilename ( 897 , 895 ) ;
  } 
  texmflogname = amakenamestring ( logfile ) ;
  selector = 18 ;
  logopened = true ;
  {
    if ( srcspecialsp || filelineerrorstylep || parsefirstlinep ) 
    fprintf ( logfile , "%s%s%s%s%s",  "This is e-upTeX, Version 3.14159265" , "-p3.7.1" ,     "-u1.21" , "-160201" , "-2.6" ) ;
    else
    fprintf ( logfile , "%s%s%s%s%s",  "This is e-upTeX, Version 3.14159265" , "-p3.7.1" ,     "-u1.21" , "-160201" , "-2.6" ) ;
    Fputs ( logfile ,  " (" ) ;
    Fputs ( logfile ,  conststringcast ( getencstring () ) ) ;
    putc ( ')' ,  logfile );
    Fputs ( logfile ,  versionstring ) ;
    slowprint ( formatident ) ;
    print ( 898 ) ;
    printint ( eqtb [29209 ].cint ) ;
    printchar ( 32 ) ;
    months = " JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC" ;
    {register integer for_end; k = 3 * eqtb [29210 ].cint - 2 ;for_end = 3 
    * eqtb [29210 ].cint ; if ( k <= for_end) do 
      putc ( months [k ],  logfile );
    while ( k++ < for_end ) ;} 
    printchar ( 32 ) ;
    printint ( eqtb [29211 ].cint ) ;
    printchar ( 32 ) ;
    printtwo ( eqtb [29208 ].cint / 60 ) ;
    printchar ( 58 ) ;
    printtwo ( eqtb [29208 ].cint % 60 ) ;
    if ( ( eTeXmode == 1 ) ) 
    {
      ;
      putc ('\n',  logfile );
      Fputs ( logfile ,  "entering extended mode" ) ;
    } 
    if ( shellenabledp ) 
    {
      putc ('\n',  logfile );
      putc ( ' ' ,  logfile );
      if ( restrictedshell ) 
      {
	Fputs ( logfile ,  "restricted " ) ;
      } 
      Fputs ( logfile ,  "\\write18 enabled." ) ;
    } 
    if ( srcspecialsp ) 
    {
      putc ('\n',  logfile );
      Fputs ( logfile ,  " Source specials enabled." ) ;
    } 
    if ( filelineerrorstylep ) 
    {
      putc ('\n',  logfile );
      Fputs ( logfile ,  " file:line:error style messages enabled." ) ;
    } 
    if ( parsefirstlinep ) 
    {
      putc ('\n',  logfile );
      Fputs ( logfile ,  " %&-line parsing enabled." ) ;
    } 
    if ( translatefilename ) 
    {
      putc ('\n',  logfile );
      Fputs ( logfile ,  " (" ) ;
      fputs ( translatefilename , logfile ) ;
      putc ( ')' ,  logfile );
    } 
  } 
  if ( mltexenabledp ) 
  {
    putc ('\n',  logfile );
    Fputs ( logfile ,  "MLTeX v2.2 enabled" ) ;
  } 
  inputstack [inputptr ]= curinput ;
  printnl ( 896 ) ;
  l = inputstack [0 ].limitfield ;
  if ( buffer [l ]== eqtb [29237 ].cint ) 
  decr ( l ) ;
  {register integer for_end; k = 1 ;for_end = l ; if ( k <= for_end) do 
    print ( buffer [k ]) ;
  while ( k++ < for_end ) ;} 
  println () ;
  selector = oldsetting + 2 ;
} 
void 
startinput ( void ) 
{
  /* 30 */ startinput_regmem 
  strnumber tempstr  ;
  scanfilename () ;
  packfilename ( curname , curarea , curext ) ;
  while ( true ) {
      
    beginfilereading () ;
    texinputtype = 1 ;
    if ( kpseinnameok ( stringcast ( nameoffile + 1 ) ) && aopenin ( inputfile 
    [curinput .indexfield ], kpsetexformat ) ) 
    goto lab30 ;
    endfilereading () ;
    promptfilename ( 883 , 344 ) ;
  } 
  lab30: curinput .namefield = amakenamestring ( inputfile [curinput 
  .indexfield ]) ;
  sourcefilenamestack [inopen ]= curinput .namefield ;
  fullsourcefilenamestack [inopen ]= makefullnamestring () ;
  if ( curinput .namefield == strptr - 1 ) 
  {
    tempstr = searchstring ( curinput .namefield ) ;
    if ( tempstr > 0 ) 
    {
      curinput .namefield = tempstr ;
      {
	decr ( strptr ) ;
	poolptr = strstart [strptr ];
      } 
    } 
  } 
  if ( jobname == 0 ) 
  {
    jobname = getjobname ( curname ) ;
    openlogfile () ;
  } 
  if ( termoffset + ( strstart [fullsourcefilenamestack [inopen ]+ 1 ]- 
  strstart [fullsourcefilenamestack [inopen ]]) > maxprintline - 2 ) 
  println () ;
  else if ( ( termoffset > 0 ) || ( fileoffset > 0 ) ) 
  printchar ( 32 ) ;
  printchar ( 40 ) ;
  incr ( openparens ) ;
  slowprint ( fullsourcefilenamestack [inopen ]) ;
  fflush ( stdout ) ;
  curinput .statefield = 61 ;
  synctexstartinput () ;
  {
    line = 1 ;
    if ( inputln ( inputfile [curinput .indexfield ], false ) ) 
    ;
    firmuptheline () ;
    if ( ( eqtb [29237 ].cint < 0 ) || ( eqtb [29237 ].cint > 255 ) ) 
    decr ( curinput .limitfield ) ;
    else buffer [curinput .limitfield ]= eqtb [29237 ].cint ;
    first = curinput .limitfield + 1 ;
    curinput .locfield = curinput .startfield ;
  } 
} 
fourquarters 
zeffectivecharinfo ( internalfontnumber f , quarterword c ) 
{
  /* 10 */ register fourquarters Result; effectivecharinfo_regmem 
  fourquarters ci  ;
  integer basec  ;
  if ( ! mltexenabledp ) 
  {
    Result = fontinfo [charbase [f ]+ c ].qqqq ;
    return Result ;
  } 
  if ( fontec [f ]>= c ) {
      
    if ( fontbc [f ]<= c ) 
    {
      ci = fontinfo [charbase [f ]+ c ].qqqq ;
      if ( ( ci .b0 > 0 ) ) 
      {
	Result = ci ;
	return Result ;
      } 
    } 
  } 
  if ( c >= eqtb [29248 ].cint ) {
      
    if ( c <= eqtb [29249 ].cint ) {
	
      if ( ( eqtb [28932 + c ].hh .v.RH > 0 ) ) 
      {
	basec = ( eqtb [28932 + c ].hh .v.RH % 256 ) ;
	if ( fontec [f ]>= basec ) {
	    
	  if ( fontbc [f ]<= basec ) 
	  {
	    ci = fontinfo [charbase [f ]+ basec ].qqqq ;
	    if ( ( ci .b0 > 0 ) ) 
	    {
	      Result = ci ;
	      return Result ;
	    } 
	  } 
	} 
      } 
    } 
  } 
  Result = nullcharacter ;
  return Result ;
} 
internalfontnumber 
zreadfontinfo ( halfword u , strnumber nom , strnumber aire , scaled s ) 
{
  /* 30 11 45 */ register internalfontnumber Result; readfontinfo_regmem 
  fontindex k  ;
  unsigned char jfmflag  ;
  halfword nt  ;
  KANJIcode cx  ;
  boolean nametoolong  ;
  boolean fileopened  ;
  halfword lf, lh, bc, ec, nw, nh, nd, ni, nl, nk, ne, np  ;
  internalfontnumber f  ;
  internalfontnumber g  ;
  eightbits a, b, c, d  ;
  fourquarters qw  ;
  scaled sw  ;
  integer bchlabel  ;
  short bchar  ;
  scaled z  ;
  integer alpha  ;
  unsigned char beta  ;
  g = 0 ;
  fileopened = false ;
  nametoolong = ( ( strstart [nom + 1 ]- strstart [nom ]) > 255 ) || ( ( 
  strstart [aire + 1 ]- strstart [aire ]) > 255 ) ;
  if ( nametoolong ) 
  goto lab11 ;
  packfilename ( nom , aire , 344 ) ;
  if ( ! bopenin ( tfmfile ) ) 
  goto lab11 ;
  fileopened = true ;
  {
    {
      lf = tfmtemp ;
      if ( lf > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      lf = lf * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      lh = tfmtemp ;
      if ( lh > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      lh = lh * 256 + tfmtemp ;
    } 
    if ( lf == 11 ) 
    {
      jfmflag = 4 ;
      nt = lh ;
      tfmtemp = getc ( tfmfile ) ;
      {
	lf = tfmtemp ;
	if ( lf > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	lf = lf * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	lh = tfmtemp ;
	if ( lh > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	lh = lh * 256 + tfmtemp ;
      } 
    } 
    else if ( lf == 9 ) 
    {
      jfmflag = 3 ;
      nt = lh ;
      tfmtemp = getc ( tfmfile ) ;
      {
	lf = tfmtemp ;
	if ( lf > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	lf = lf * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	lh = tfmtemp ;
	if ( lh > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	lh = lh * 256 + tfmtemp ;
      } 
    } 
    else {
	
      jfmflag = 0 ;
      nt = 0 ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      bc = tfmtemp ;
      if ( bc > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      bc = bc * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      ec = tfmtemp ;
      if ( ec > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      ec = ec * 256 + tfmtemp ;
    } 
    if ( ( bc > ec + 1 ) || ( ec > 255 ) ) 
    goto lab11 ;
    if ( bc > 255 ) 
    {
      bc = 1 ;
      ec = 0 ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      nw = tfmtemp ;
      if ( nw > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      nw = nw * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      nh = tfmtemp ;
      if ( nh > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      nh = nh * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      nd = tfmtemp ;
      if ( nd > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      nd = nd * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      ni = tfmtemp ;
      if ( ni > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      ni = ni * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      nl = tfmtemp ;
      if ( nl > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      nl = nl * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      nk = tfmtemp ;
      if ( nk > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      nk = nk * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      ne = tfmtemp ;
      if ( ne > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      ne = ne * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      np = tfmtemp ;
      if ( np > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      np = np * 256 + tfmtemp ;
    } 
    if ( jfmflag != 0 ) 
    {
      if ( lf != 7 + lh + nt + ( ec - bc + 1 ) + nw + nh + nd + ni + nl + nk + 
      ne + np ) 
      goto lab11 ;
    } 
    else {
	
      if ( lf != 6 + lh + ( ec - bc + 1 ) + nw + nh + nd + ni + nl + nk + ne + 
      np ) 
      goto lab11 ;
    } 
    if ( ( nw == 0 ) || ( nh == 0 ) || ( nd == 0 ) || ( ni == 0 ) ) 
    goto lab11 ;
  } 
  if ( jfmflag != 0 ) 
  lf = lf - 7 - lh ;
  else lf = lf - 6 - lh ;
  if ( np < 7 ) 
  lf = lf + 7 - np ;
  if ( ( fontptr == fontmax ) || ( fmemptr + lf > fontmemsize ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 900 ) ;
    } 
    sprintcs ( u ) ;
    printchar ( 61 ) ;
    printfilename ( nom , aire , 344 ) ;
    if ( s >= 0 ) 
    {
      print ( 832 ) ;
      printscaled ( s ) ;
      print ( 419 ) ;
    } 
    else if ( s != -1000 ) 
    {
      print ( 901 ) ;
      printint ( - (integer) s ) ;
    } 
    print ( 910 ) ;
    {
      helpptr = 4 ;
      helpline [3 ]= 911 ;
      helpline [2 ]= 912 ;
      helpline [1 ]= 913 ;
      helpline [0 ]= 914 ;
    } 
    error () ;
    goto lab30 ;
  } 
  f = fontptr + 1 ;
  fontdir [f ]= jfmflag ;
  fontnumext [f ]= nt ;
  ctypebase [f ]= fmemptr ;
  charbase [f ]= ctypebase [f ]+ nt - bc ;
  widthbase [f ]= charbase [f ]+ ec + 1 ;
  heightbase [f ]= widthbase [f ]+ nw ;
  depthbase [f ]= heightbase [f ]+ nh ;
  italicbase [f ]= depthbase [f ]+ nd ;
  ligkernbase [f ]= italicbase [f ]+ ni ;
  kernbase [f ]= ligkernbase [f ]+ nl - 256 * ( 128 ) ;
  extenbase [f ]= kernbase [f ]+ 256 * ( 128 ) + nk ;
  parambase [f ]= extenbase [f ]+ ne ;
  {
    if ( lh < 2 ) 
    goto lab11 ;
    {
      tfmtemp = getc ( tfmfile ) ;
      a = tfmtemp ;
      qw .b0 = a ;
      tfmtemp = getc ( tfmfile ) ;
      b = tfmtemp ;
      qw .b1 = b ;
      tfmtemp = getc ( tfmfile ) ;
      c = tfmtemp ;
      qw .b2 = c ;
      tfmtemp = getc ( tfmfile ) ;
      d = tfmtemp ;
      qw .b3 = d ;
      fontcheck [f ]= qw ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      z = tfmtemp ;
      if ( z > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      z = z * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    z = z * 256 + tfmtemp ;
    tfmtemp = getc ( tfmfile ) ;
    z = ( z * 16 ) + ( tfmtemp / 16 ) ;
    if ( z < 65536L ) 
    goto lab11 ;
    while ( lh > 2 ) {
	
      tfmtemp = getc ( tfmfile ) ;
      tfmtemp = getc ( tfmfile ) ;
      tfmtemp = getc ( tfmfile ) ;
      tfmtemp = getc ( tfmfile ) ;
      decr ( lh ) ;
    } 
    fontdsize [f ]= z ;
    if ( s != -1000 ) {
	
      if ( s >= 0 ) 
      z = s ;
      else z = xnoverd ( z , - (integer) s , 1000 ) ;
    } 
    fontsize [f ]= z ;
  } 
  if ( jfmflag != 0 ) 
  {register integer for_end; k = ctypebase [f ];for_end = ctypebase [f ]
  + nt - 1 ; if ( k <= for_end) do 
    {
      tfmtemp = getc ( tfmfile ) ;
      {
	cx = tfmtemp ;
	if ( cx > 255 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	cx = cx * 256 + tfmtemp ;
      } 
      fontinfo [k ].hh .v.RH = cx ;
      tfmtemp = getc ( tfmfile ) ;
      {
	cx = tfmtemp ;
	if ( cx > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	cx = cx * 256 + tfmtemp ;
      } 
      fontinfo [k ].hh .lhfield = cx ;
    } 
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = charbase [f ]+ bc ;for_end = widthbase [
  f ]- 1 ; if ( k <= for_end) do 
    {
      {
	tfmtemp = getc ( tfmfile ) ;
	a = tfmtemp ;
	qw .b0 = a ;
	tfmtemp = getc ( tfmfile ) ;
	b = tfmtemp ;
	qw .b1 = b ;
	tfmtemp = getc ( tfmfile ) ;
	c = tfmtemp ;
	qw .b2 = c ;
	tfmtemp = getc ( tfmfile ) ;
	d = tfmtemp ;
	qw .b3 = d ;
	fontinfo [k ].qqqq = qw ;
      } 
      if ( ( a >= nw ) || ( b / 16 >= nh ) || ( b % 16 >= nd ) || ( c / 4 >= 
      ni ) ) 
      goto lab11 ;
      switch ( c % 4 ) 
      {case 1 : 
	if ( d >= nl ) 
	goto lab11 ;
	break ;
      case 3 : 
	if ( d >= ne ) 
	goto lab11 ;
	break ;
      case 2 : 
	{
	  {
	    if ( ( d < bc ) || ( d > ec ) ) 
	    goto lab11 ;
	  } 
	  while ( d < k - charbase [f ]) {
	      
	    qw = fontinfo [charbase [f ]+ d ].qqqq ;
	    if ( ( ( qw .b2 ) % 4 ) != 2 ) 
	    goto lab45 ;
	    d = qw .b3 ;
	  } 
	  if ( d == k - charbase [f ]) 
	  goto lab11 ;
	  lab45: ;
	} 
	break ;
	default: 
	;
	break ;
      } 
    } 
  while ( k++ < for_end ) ;} 
  {
    {
      alpha = 16 ;
      while ( z >= 8388608L ) {
	  
	z = z / 2 ;
	alpha = alpha + alpha ;
      } 
      beta = 256 / alpha ;
      alpha = alpha * z ;
    } 
    {register integer for_end; k = widthbase [f ];for_end = ligkernbase [
    f ]- 1 ; if ( k <= for_end) do 
      {
	tfmtemp = getc ( tfmfile ) ;
	a = tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	b = tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	c = tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	d = tfmtemp ;
	sw = ( ( ( ( ( d * z ) / 256 ) + ( c * z ) ) / 256 ) + ( b * z ) ) / 
	beta ;
	if ( a == 0 ) 
	fontinfo [k ].cint = sw ;
	else if ( a == 255 ) 
	fontinfo [k ].cint = sw - alpha ;
	else goto lab11 ;
      } 
    while ( k++ < for_end ) ;} 
    if ( fontinfo [widthbase [f ]].cint != 0 ) 
    goto lab11 ;
    if ( fontinfo [heightbase [f ]].cint != 0 ) 
    goto lab11 ;
    if ( fontinfo [depthbase [f ]].cint != 0 ) 
    goto lab11 ;
    if ( fontinfo [italicbase [f ]].cint != 0 ) 
    goto lab11 ;
  } 
  bchlabel = 32767 ;
  bchar = 256 ;
  if ( nl > 0 ) 
  {
    {register integer for_end; k = ligkernbase [f ];for_end = kernbase [f 
    ]+ 256 * ( 128 ) - 1 ; if ( k <= for_end) do 
      {
	{
	  tfmtemp = getc ( tfmfile ) ;
	  a = tfmtemp ;
	  qw .b0 = a ;
	  tfmtemp = getc ( tfmfile ) ;
	  b = tfmtemp ;
	  qw .b1 = b ;
	  tfmtemp = getc ( tfmfile ) ;
	  c = tfmtemp ;
	  qw .b2 = c ;
	  tfmtemp = getc ( tfmfile ) ;
	  d = tfmtemp ;
	  qw .b3 = d ;
	  fontinfo [k ].qqqq = qw ;
	} 
	if ( a > 128 ) 
	{
	  if ( 256 * c + d >= nl ) 
	  goto lab11 ;
	  if ( a == 255 ) {
	      
	    if ( k == ligkernbase [f ]) 
	    bchar = b ;
	  } 
	} 
	else {
	    
	  if ( b != bchar ) 
	  {
	    {
	      if ( ( b < bc ) || ( b > ec ) ) 
	      goto lab11 ;
	    } 
	    qw = fontinfo [charbase [f ]+ b ].qqqq ;
	    if ( ! ( qw .b0 > 0 ) ) 
	    goto lab11 ;
	  } 
	  if ( c < 128 ) 
	  {
	    if ( jfmflag != 0 ) 
	    {
	      if ( d >= ne ) 
	      goto lab11 ;
	    } 
	    else {
		
	      {
		if ( ( d < bc ) || ( d > ec ) ) 
		goto lab11 ;
	      } 
	      qw = fontinfo [charbase [f ]+ d ].qqqq ;
	      if ( ! ( qw .b0 > 0 ) ) 
	      goto lab11 ;
	    } 
	  } 
	  else if ( 256 * ( c - 128 ) + d >= nk ) 
	  goto lab11 ;
	  if ( a < 128 ) {
	      
	    if ( k - ligkernbase [f ]+ a + 1 >= nl ) 
	    goto lab11 ;
	  } 
	} 
      } 
    while ( k++ < for_end ) ;} 
    if ( a == 255 ) 
    bchlabel = 256 * c + d ;
  } 
  {register integer for_end; k = kernbase [f ]+ 256 * ( 128 ) ;for_end = 
  extenbase [f ]- 1 ; if ( k <= for_end) do 
    {
      tfmtemp = getc ( tfmfile ) ;
      a = tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      b = tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      c = tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      d = tfmtemp ;
      sw = ( ( ( ( ( d * z ) / 256 ) + ( c * z ) ) / 256 ) + ( b * z ) ) / 
      beta ;
      if ( a == 0 ) 
      fontinfo [k ].cint = sw ;
      else if ( a == 255 ) 
      fontinfo [k ].cint = sw - alpha ;
      else goto lab11 ;
    } 
  while ( k++ < for_end ) ;} 
  if ( jfmflag != 0 ) 
  {register integer for_end; k = extenbase [f ];for_end = parambase [f ]
  - 1 ; if ( k <= for_end) do 
    {
      tfmtemp = getc ( tfmfile ) ;
      a = tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      b = tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      c = tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      d = tfmtemp ;
      sw = ( ( ( ( ( d * z ) / 256 ) + ( c * z ) ) / 256 ) + ( b * z ) ) / 
      beta ;
      if ( a == 0 ) 
      fontinfo [k ].cint = sw ;
      else if ( a == 255 ) 
      fontinfo [k ].cint = sw - alpha ;
      else goto lab11 ;
    } 
  while ( k++ < for_end ) ;} 
  else {
      register integer for_end; k = extenbase [f ];for_end = parambase [
  f ]- 1 ; if ( k <= for_end) do 
    {
      {
	tfmtemp = getc ( tfmfile ) ;
	a = tfmtemp ;
	qw .b0 = a ;
	tfmtemp = getc ( tfmfile ) ;
	b = tfmtemp ;
	qw .b1 = b ;
	tfmtemp = getc ( tfmfile ) ;
	c = tfmtemp ;
	qw .b2 = c ;
	tfmtemp = getc ( tfmfile ) ;
	d = tfmtemp ;
	qw .b3 = d ;
	fontinfo [k ].qqqq = qw ;
      } 
      if ( a != 0 ) 
      {
	{
	  if ( ( a < bc ) || ( a > ec ) ) 
	  goto lab11 ;
	} 
	qw = fontinfo [charbase [f ]+ a ].qqqq ;
	if ( ! ( qw .b0 > 0 ) ) 
	goto lab11 ;
      } 
      if ( b != 0 ) 
      {
	{
	  if ( ( b < bc ) || ( b > ec ) ) 
	  goto lab11 ;
	} 
	qw = fontinfo [charbase [f ]+ b ].qqqq ;
	if ( ! ( qw .b0 > 0 ) ) 
	goto lab11 ;
      } 
      if ( c != 0 ) 
      {
	{
	  if ( ( c < bc ) || ( c > ec ) ) 
	  goto lab11 ;
	} 
	qw = fontinfo [charbase [f ]+ c ].qqqq ;
	if ( ! ( qw .b0 > 0 ) ) 
	goto lab11 ;
      } 
      {
	{
	  if ( ( d < bc ) || ( d > ec ) ) 
	  goto lab11 ;
	} 
	qw = fontinfo [charbase [f ]+ d ].qqqq ;
	if ( ! ( qw .b0 > 0 ) ) 
	goto lab11 ;
      } 
    } 
  while ( k++ < for_end ) ;} 
  {
    {register integer for_end; k = 1 ;for_end = np ; if ( k <= for_end) do 
      if ( k == 1 ) 
      {
	tfmtemp = getc ( tfmfile ) ;
	sw = tfmtemp ;
	if ( sw > 127 ) 
	sw = sw - 256 ;
	tfmtemp = getc ( tfmfile ) ;
	sw = sw * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	sw = sw * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	fontinfo [parambase [f ]].cint = ( sw * 16 ) + ( tfmtemp / 16 ) ;
      } 
      else {
	  
	tfmtemp = getc ( tfmfile ) ;
	a = tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	b = tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	c = tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	d = tfmtemp ;
	sw = ( ( ( ( ( d * z ) / 256 ) + ( c * z ) ) / 256 ) + ( b * z ) ) / 
	beta ;
	if ( a == 0 ) 
	fontinfo [parambase [f ]+ k - 1 ].cint = sw ;
	else if ( a == 255 ) 
	fontinfo [parambase [f ]+ k - 1 ].cint = sw - alpha ;
	else goto lab11 ;
      } 
    while ( k++ < for_end ) ;} 
    if ( feof ( tfmfile ) ) 
    goto lab11 ;
    {register integer for_end; k = np + 1 ;for_end = 7 ; if ( k <= for_end) 
    do 
      fontinfo [parambase [f ]+ k - 1 ].cint = 0 ;
    while ( k++ < for_end ) ;} 
  } 
  if ( np >= 7 ) 
  fontparams [f ]= np ;
  else fontparams [f ]= 7 ;
  hyphenchar [f ]= eqtb [29235 ].cint ;
  skewchar [f ]= eqtb [29236 ].cint ;
  if ( bchlabel < nl ) 
  bcharlabel [f ]= bchlabel + ligkernbase [f ];
  else bcharlabel [f ]= 0 ;
  fontbchar [f ]= bchar ;
  fontfalsebchar [f ]= bchar ;
  if ( bchar <= ec ) {
      
    if ( bchar >= bc ) 
    {
      qw = fontinfo [charbase [f ]+ bchar ].qqqq ;
      if ( ( qw .b0 > 0 ) ) 
      fontfalsebchar [f ]= 256 ;
    } 
  } 
  fontname [f ]= nom ;
  fontarea [f ]= aire ;
  fontbc [f ]= bc ;
  fontec [f ]= ec ;
  fontglue [f ]= -1073741823L ;
  ctypebase [f ]= ctypebase [f ];
  charbase [f ]= charbase [f ];
  widthbase [f ]= widthbase [f ];
  ligkernbase [f ]= ligkernbase [f ];
  kernbase [f ]= kernbase [f ];
  extenbase [f ]= extenbase [f ];
  decr ( parambase [f ]) ;
  fmemptr = fmemptr + lf ;
  fontptr = f ;
  g = f ;
  goto lab30 ;
  lab11: {
      
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 900 ) ;
  } 
  sprintcs ( u ) ;
  printchar ( 61 ) ;
  printfilename ( nom , aire , 344 ) ;
  if ( s >= 0 ) 
  {
    print ( 832 ) ;
    printscaled ( s ) ;
    print ( 419 ) ;
  } 
  else if ( s != -1000 ) 
  {
    print ( 901 ) ;
    printint ( - (integer) s ) ;
  } 
  if ( fileopened ) 
  print ( 902 ) ;
  else if ( nametoolong ) 
  print ( 903 ) ;
  else print ( 904 ) ;
  {
    helpptr = 5 ;
    helpline [4 ]= 905 ;
    helpline [3 ]= 906 ;
    helpline [2 ]= 907 ;
    helpline [1 ]= 908 ;
    helpline [0 ]= 909 ;
  } 
  error () ;
  lab30: if ( fileopened ) 
  bclose ( tfmfile ) ;
  Result = g ;
  return Result ;
} 
void 
zcharwarning ( internalfontnumber f , eightbits c ) 
{
  charwarning_regmem 
  unsigned char l  ;
  integer oldsetting  ;
  if ( eqtb [29223 ].cint > 0 ) 
  {
    oldsetting = eqtb [29217 ].cint ;
    if ( ( eTeXmode == 1 ) && ( eqtb [29223 ].cint > 1 ) ) 
    eqtb [29217 ].cint = 1 ;
    {
      begindiagnostic () ;
      printnl ( 923 ) ;
      if ( ( c < 32 ) || ( c > 126 ) ) 
      {
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	if ( c < 64 ) 
	printchar ( c + 64 ) ;
	else if ( c < 128 ) 
	printchar ( c - 64 ) ;
	else {
	    
	  l = c / 16 ;
	  if ( l < 10 ) 
	  printchar ( l + 48 ) ;
	  else printchar ( l + 87 ) ;
	  l = c % 16 ;
	  if ( l < 10 ) 
	  printchar ( l + 48 ) ;
	  else printchar ( l + 87 ) ;
	} 
      } 
      else print ( c ) ;
      print ( 924 ) ;
      slowprint ( fontname [f ]) ;
      printchar ( 33 ) ;
      enddiagnostic ( false ) ;
    } 
    eqtb [29217 ].cint = oldsetting ;
  } 
} 
halfword 
znewcharacter ( internalfontnumber f , eightbits c ) 
{
  /* 10 */ register halfword Result; newcharacter_regmem 
  halfword p  ;
  quarterword ec  ;
  ec = effectivechar ( false , f , c ) ;
  if ( fontbc [f ]<= ec ) {
      
    if ( fontec [f ]>= ec ) {
	
      if ( ( fontinfo [charbase [f ]+ ec ].qqqq .b0 > 0 ) ) 
      {
	p = getavail () ;
	mem [p ].hh.b0 = f ;
	mem [p ].hh.b1 = c ;
	Result = p ;
	return Result ;
      } 
    } 
  } 
  charwarning ( f , c ) ;
  Result = -1073741823L ;
  return Result ;
} 
void 
dviswap ( void ) 
{
  dviswap_regmem 
  if ( dviptr > ( 2147483647L - dvioffset ) ) 
  {
    curs = -2 ;
    fatalerror ( 925 ) ;
  } 
  if ( dvilimit == dvibufsize ) 
  {
    writedvi ( 0 , halfbuf - 1 ) ;
    dvilimit = halfbuf ;
    dvioffset = dvioffset + dvibufsize ;
    dviptr = 0 ;
  } 
  else {
      
    writedvi ( halfbuf , dvibufsize - 1 ) ;
    dvilimit = dvibufsize ;
  } 
  dvigone = dvigone + halfbuf ;
} 
void 
zdvifour ( integer x ) 
{
  dvifour_regmem 
  if ( x >= 0 ) 
  {
    dvibuf [dviptr ]= x / 16777216L ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  else {
      
    x = x + 1073741824L ;
    x = x + 1073741824L ;
    {
      dvibuf [dviptr ]= ( x / 16777216L ) + 128 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
  } 
  x = x % 16777216L ;
  {
    dvibuf [dviptr ]= x / 65536L ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  x = x % 65536L ;
  {
    dvibuf [dviptr ]= x / 256 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {
    dvibuf [dviptr ]= x % 256 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
} 
void 
zdvipop ( integer l ) 
{
  dvipop_regmem 
  if ( ( l == dvioffset + dviptr ) && ( dviptr > 0 ) ) 
  decr ( dviptr ) ;
  else {
      
    dvibuf [dviptr ]= 142 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
} 
void 
zdvifontdef ( internalfontnumber f ) 
{
  dvifontdef_regmem 
  poolpointer k  ;
  if ( f <= 256 ) 
  {
    {
      dvibuf [dviptr ]= 243 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    {
      dvibuf [dviptr ]= f - 1 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
  } 
  else {
      
    {
      dvibuf [dviptr ]= 244 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    {
      dvibuf [dviptr ]= ( f - 1 ) / 256 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    {
      dvibuf [dviptr ]= ( f - 1 ) % 256 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
  } 
  {
    dvibuf [dviptr ]= fontcheck [f ].b0 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {
    dvibuf [dviptr ]= fontcheck [f ].b1 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {
    dvibuf [dviptr ]= fontcheck [f ].b2 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {
    dvibuf [dviptr ]= fontcheck [f ].b3 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  dvifour ( fontsize [f ]) ;
  dvifour ( fontdsize [f ]) ;
  {
    dvibuf [dviptr ]= ( strstart [fontarea [f ]+ 1 ]- strstart [
    fontarea [f ]]) ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {
    dvibuf [dviptr ]= ( strstart [fontname [f ]+ 1 ]- strstart [
    fontname [f ]]) ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {register integer for_end; k = strstart [fontarea [f ]];for_end = 
  strstart [fontarea [f ]+ 1 ]- 1 ; if ( k <= for_end) do 
    {
      dvibuf [dviptr ]= strpool [k ];
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = strstart [fontname [f ]];for_end = 
  strstart [fontname [f ]+ 1 ]- 1 ; if ( k <= for_end) do 
    {
      dvibuf [dviptr ]= strpool [k ];
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
  while ( k++ < for_end ) ;} 
} 
void 
zmovement ( scaled w , eightbits o ) 
{
  /* 10 40 45 2 1 */ movement_regmem 
  smallnumber mstate  ;
  halfword p, q  ;
  integer k  ;
  q = getnode ( 3 ) ;
  mem [q + 1 ].cint = w ;
  mem [q + 2 ].cint = dvioffset + dviptr ;
  if ( o == 157 ) 
  {
    mem [q ].hh .v.RH = downptr ;
    downptr = q ;
  } 
  else {
      
    mem [q ].hh .v.RH = rightptr ;
    rightptr = q ;
  } 
  p = mem [q ].hh .v.RH ;
  mstate = 0 ;
  while ( p != -1073741823L ) {
      
    if ( mem [p + 1 ].cint == w ) 
    switch ( mstate + mem [p ].hh .v.LH ) 
    {case 3 : 
    case 4 : 
    case 15 : 
    case 16 : 
      if ( mem [p + 2 ].cint < dvigone ) 
      goto lab45 ;
      else {
	  
	k = mem [p + 2 ].cint - dvioffset ;
	if ( k < 0 ) 
	k = k + dvibufsize ;
	dvibuf [k ]= dvibuf [k ]+ 5 ;
	mem [p ].hh .v.LH = 1 ;
	goto lab40 ;
      } 
      break ;
    case 5 : 
    case 9 : 
    case 11 : 
      if ( mem [p + 2 ].cint < dvigone ) 
      goto lab45 ;
      else {
	  
	k = mem [p + 2 ].cint - dvioffset ;
	if ( k < 0 ) 
	k = k + dvibufsize ;
	dvibuf [k ]= dvibuf [k ]+ 10 ;
	mem [p ].hh .v.LH = 2 ;
	goto lab40 ;
      } 
      break ;
    case 1 : 
    case 2 : 
    case 8 : 
    case 13 : 
      goto lab40 ;
      break ;
      default: 
      ;
      break ;
    } 
    else switch ( mstate + mem [p ].hh .v.LH ) 
    {case 1 : 
      mstate = 6 ;
      break ;
    case 2 : 
      mstate = 12 ;
      break ;
    case 8 : 
    case 13 : 
      goto lab45 ;
      break ;
      default: 
      ;
      break ;
    } 
    p = mem [p ].hh .v.RH ;
  } 
  lab45: ;
  mem [q ].hh .v.LH = 3 ;
  if ( abs ( w ) >= 8388608L ) 
  {
    {
      dvibuf [dviptr ]= o + 3 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    dvifour ( w ) ;
    return ;
  } 
  if ( abs ( w ) >= 32768L ) 
  {
    {
      dvibuf [dviptr ]= o + 2 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    if ( w < 0 ) 
    w = w + 16777216L ;
    {
      dvibuf [dviptr ]= w / 65536L ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    w = w % 65536L ;
    goto lab2 ;
  } 
  if ( abs ( w ) >= 128 ) 
  {
    {
      dvibuf [dviptr ]= o + 1 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    if ( w < 0 ) 
    w = w + 65536L ;
    goto lab2 ;
  } 
  {
    dvibuf [dviptr ]= o ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  if ( w < 0 ) 
  w = w + 256 ;
  goto lab1 ;
  lab2: {
      
    dvibuf [dviptr ]= w / 256 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  lab1: {
      
    dvibuf [dviptr ]= w % 256 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  return ;
  lab40: mem [q ].hh .v.LH = mem [p ].hh .v.LH ;
  if ( mem [q ].hh .v.LH == 1 ) 
  {
    {
      dvibuf [dviptr ]= o + 4 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    while ( mem [q ].hh .v.RH != p ) {
	
      q = mem [q ].hh .v.RH ;
      switch ( mem [q ].hh .v.LH ) 
      {case 3 : 
	mem [q ].hh .v.LH = 5 ;
	break ;
      case 4 : 
	mem [q ].hh .v.LH = 6 ;
	break ;
	default: 
	;
	break ;
      } 
    } 
  } 
  else {
      
    {
      dvibuf [dviptr ]= o + 9 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    while ( mem [q ].hh .v.RH != p ) {
	
      q = mem [q ].hh .v.RH ;
      switch ( mem [q ].hh .v.LH ) 
      {case 3 : 
	mem [q ].hh .v.LH = 4 ;
	break ;
      case 5 : 
	mem [q ].hh .v.LH = 6 ;
	break ;
	default: 
	;
	break ;
      } 
    } 
  } 
} 
void 
zprunemovements ( integer l ) 
{
  /* 30 10 */ prunemovements_regmem 
  halfword p  ;
  while ( downptr != -1073741823L ) {
      
    if ( mem [downptr + 2 ].cint < l ) 
    goto lab30 ;
    p = downptr ;
    downptr = mem [p ].hh .v.RH ;
    freenode ( p , 3 ) ;
  } 
  lab30: while ( rightptr != -1073741823L ) {
      
    if ( mem [rightptr + 2 ].cint < l ) 
    return ;
    p = rightptr ;
    rightptr = mem [p ].hh .v.RH ;
    freenode ( p , 3 ) ;
  } 
} 
void 
zspecialout ( halfword p ) 
{
  /* 30 */ specialout_regmem 
  unsigned char oldsetting  ;
  poolpointer k  ;
  scaled s, t, cw  ;
  boolean bl  ;
  smallnumber i  ;
  if ( curh != dvih ) 
  {
    movement ( curh - dvih , 143 ) ;
    dvih = curh ;
  } 
  if ( curv != dviv ) 
  {
    movement ( curv - dviv , 157 ) ;
    dviv = curv ;
  } 
  oldsetting = selector ;
  selector = 21 ;
  showtokenlist ( mem [mem [p + 1 ].hh .v.RH ].hh .v.RH , -1073741823L , 
  poolsize - poolptr ) ;
  selector = oldsetting ;
  {
    if ( poolptr + 1 > poolsize ) 
    overflow ( 259 , poolsize - initpoolptr ) ;
  } 
  if ( ( poolptr - strstart [strptr ]) < 256 ) 
  {
    {
      dvibuf [dviptr ]= 239 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    {
      dvibuf [dviptr ]= ( poolptr - strstart [strptr ]) ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
  } 
  else {
      
    {
      dvibuf [dviptr ]= 242 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    dvifour ( ( poolptr - strstart [strptr ]) ) ;
  } 
  {register integer for_end; k = strstart [strptr ];for_end = poolptr - 1 
  ; if ( k <= for_end) do 
    {
      dvibuf [dviptr ]= strpool [k ];
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
  while ( k++ < for_end ) ;} 
  if ( poolptr - strstart [strptr ]<= 10 ) 
  goto lab30 ;
  k = strstart [strptr ];
  if ( ( strpool [( k + 0 ) ]!= 'p' ) || ( strpool [( k + 1 ) ]!= 'a' ) || 
  ( strpool [( k + 2 ) ]!= 'p' ) || ( strpool [( k + 3 ) ]!= 'e' ) || ( 
  strpool [( k + 4 ) ]!= 'r' ) || ( strpool [( k + 5 ) ]!= 's' ) || ( 
  strpool [( k + 6 ) ]!= 'i' ) || ( strpool [( k + 7 ) ]!= 'z' ) || ( 
  strpool [( k + 8 ) ]!= 'e' ) ) 
  goto lab30 ;
  k = k + 9 ;
  if ( k == poolptr ) 
  goto lab30 ;
  else if ( strpool [( k ) ]== '=' ) 
  incr ( k ) ;
  s = 1 ;
  t = 0 ;
  bl = true ;
  while ( ( k < poolptr ) && ( bl ) ) {
      
    if ( ( strpool [( k ) ]>= '0' ) && ( strpool [( k ) ]<= '9' ) ) 
    {
      t = 10 * t + strpool [( k ) ]- '0' ;
      incr ( k ) ;
    } 
    else {
	
      bl = false ;
    } 
  } 
  t = t * 65536L ;
  if ( k == poolptr ) 
  goto lab30 ;
  else if ( strpool [( k ) ]== '.' ) 
  {
    incr ( k ) ;
    bl = true ;
    i = 0 ;
    while ( ( k < poolptr ) && ( bl ) && ( i <= 17 ) ) {
	
      if ( ( strpool [( k ) ]>= '0' ) && ( strpool [( k ) ]<= '9' ) ) 
      {
	dig [i ]= strpool [( k ) ]- '0' ;
	incr ( k ) ;
	incr ( i ) ;
      } 
      else {
	  
	bl = false ;
	incr ( k ) ;
	incr ( i ) ;
      } 
    } 
    t = s * ( t + rounddecimals ( i - 1 ) ) ;
  } 
  else if ( ( strpool [( k ) ]>= '0' ) && ( strpool [( k ) ]<= '9' ) ) 
  goto lab30 ;
  else {
      
    t = s * t ;
    incr ( k ) ;
  } 
  if ( k == poolptr ) 
  goto lab30 ;
  else if ( strpool [( k - 1 ) ]!= 'p' ) 
  goto lab30 ;
  if ( k == poolptr ) 
  goto lab30 ;
  else if ( strpool [( k ) ]!= 't' ) 
  goto lab30 ;
  incr ( k ) ;
  if ( k == poolptr ) 
  goto lab30 ;
  else if ( strpool [( k ) ]!= ',' ) 
  goto lab30 ;
  else incr ( k ) ;
  cw = t ;
  s = 1 ;
  t = 0 ;
  bl = true ;
  while ( ( k < poolptr ) && ( bl ) ) {
      
    if ( ( strpool [( k ) ]>= '0' ) && ( strpool [( k ) ]<= '9' ) ) 
    {
      t = 10 * t + strpool [( k ) ]- '0' ;
      incr ( k ) ;
    } 
    else {
	
      bl = false ;
    } 
  } 
  t = t * 65536L ;
  if ( k == poolptr ) 
  goto lab30 ;
  else if ( strpool [( k ) ]== '.' ) 
  {
    incr ( k ) ;
    bl = true ;
    i = 0 ;
    while ( ( k < poolptr ) && ( bl ) && ( i <= 17 ) ) {
	
      if ( ( strpool [( k ) ]>= '0' ) && ( strpool [( k ) ]<= '9' ) ) 
      {
	dig [i ]= strpool [( k ) ]- '0' ;
	incr ( k ) ;
	incr ( i ) ;
      } 
      else {
	  
	bl = false ;
	incr ( k ) ;
	incr ( i ) ;
      } 
    } 
    t = s * ( t + rounddecimals ( i - 1 ) ) ;
  } 
  else if ( ( strpool [( k ) ]>= '0' ) && ( strpool [( k ) ]<= '9' ) ) 
  goto lab30 ;
  else {
      
    t = s * t ;
    incr ( k ) ;
  } 
  if ( k == poolptr ) 
  goto lab30 ;
  else if ( strpool [( k - 1 ) ]!= 'p' ) 
  goto lab30 ;
  if ( k == poolptr ) 
  goto lab30 ;
  else if ( strpool [( k ) ]!= 't' ) 
  goto lab30 ;
  geqworddefine ( 29797 , cw ) ;
  geqworddefine ( 29798 , t ) ;
  curpageheight = t ;
  curpagewidth = cw ;
  if ( ( dvidir == 3 ) || ( dvidir == 1 ) ) 
  {
    t = curpageheight ;
    curpageheight = curpagewidth ;
    curpagewidth = t ;
  } 
  lab30: poolptr = strstart [strptr ];
} 
void 
zwriteout ( halfword p ) 
{
  writeout_regmem 
  unsigned char oldsetting  ;
  integer oldmode  ;
  smallnumber j  ;
  halfword q, r  ;
  integer d  ;
  boolean clobbered  ;
  integer runsystemret  ;
  q = getavail () ;
  mem [q ].hh .v.LH = 637 ;
  r = getavail () ;
  mem [q ].hh .v.RH = r ;
  mem [r ].hh .v.LH = 536886433L ;
  begintokenlist ( q , 4 ) ;
  begintokenlist ( mem [p + 1 ].hh .v.RH , 16 ) ;
  q = getavail () ;
  mem [q ].hh .v.LH = 379 ;
  begintokenlist ( q , 4 ) ;
  oldmode = curlist .modefield ;
  curlist .modefield = 0 ;
  curcs = writeloc ;
  q = scantoks ( false , true ) ;
  gettoken () ;
  if ( curtok != 536886433L ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1450 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 1451 ;
      helpline [0 ]= 1117 ;
    } 
    error () ;
    do {
	gettoken () ;
    } while ( ! ( curtok == 536886433L ) ) ;
  } 
  curlist .modefield = oldmode ;
  endtokenlist () ;
  oldsetting = selector ;
  j = mem [p + 1 ].hh .v.LH ;
  if ( j == 18 ) 
  selector = 21 ;
  else if ( writeopen [j ]) 
  selector = j ;
  else {
      
    if ( ( j == 17 ) && ( selector == 19 ) ) 
    selector = 18 ;
    printnl ( 344 ) ;
  } 
  tokenshow ( defref ) ;
  println () ;
  flushlist ( defref ) ;
  if ( j == 18 ) 
  {
    if ( ( eqtb [29217 ].cint <= 0 ) ) 
    selector = 18 ;
    else selector = 19 ;
    if ( ! logopened ) 
    selector = 17 ;
    printnl ( 1442 ) ;
    {register integer for_end; d = 0 ;for_end = ( poolptr - strstart [
    strptr ]) - 1 ; if ( d <= for_end) do 
      {
	print ( strpool [strstart [strptr ]+ d ]) ;
      } 
    while ( d++ < for_end ) ;} 
    print ( 1443 ) ;
    if ( shellenabledp ) 
    {
      {
	if ( poolptr + 1 > poolsize ) 
	overflow ( 259 , poolsize - initpoolptr ) ;
      } 
      {
	strpool [poolptr ]= 0 ;
	incr ( poolptr ) ;
      } 
      clobbered = false ;
      {register integer for_end; d = 0 ;for_end = ( poolptr - strstart [
      strptr ]) - 1 ; if ( d <= for_end) do 
	{
	  strpool [strstart [strptr ]+ d ]= xchr [strpool [strstart [
	  strptr ]+ d ]];
	  if ( ( strpool [strstart [strptr ]+ d ]== 0 ) && ( d < ( poolptr 
	  - strstart [strptr ]) - 1 ) ) 
	  clobbered = true ;
	} 
      while ( d++ < for_end ) ;} 
      if ( clobbered ) 
      print ( 1444 ) ;
      else {
	  
	runsystemret = runsystem ( conststringcast ( addressof ( strpool [
	strstart [strptr ]]) ) ) ;
	if ( runsystemret == -1 ) 
	print ( 1445 ) ;
	else if ( runsystemret == 0 ) 
	print ( 1446 ) ;
	else if ( runsystemret == 1 ) 
	print ( 1447 ) ;
	else if ( runsystemret == 2 ) 
	print ( 1448 ) ;
      } 
    } 
    else {
	
      print ( 1449 ) ;
    } 
    printchar ( 46 ) ;
    printnl ( 344 ) ;
    println () ;
    poolptr = strstart [strptr ];
  } 
  selector = oldsetting ;
} 
void 
zoutwhat ( halfword p ) 
{
  outwhat_regmem 
  smallnumber j  ;
  unsigned char oldsetting  ;
  switch ( mem [p ].hh.b1 ) 
  {case 0 : 
  case 1 : 
  case 2 : 
    if ( ! doingleaders ) 
    {
      j = mem [p + 1 ].hh .v.LH ;
      if ( mem [p ].hh.b1 == 1 ) 
      writeout ( p ) ;
      else {
	  
	if ( writeopen [j ]) 
	aclose ( writefile [j ]) ;
	if ( mem [p ].hh.b1 == 2 ) 
	writeopen [j ]= false ;
	else if ( j < 16 ) 
	{
	  curname = mem [p + 1 ].hh .v.RH ;
	  curarea = mem [p + 2 ].hh .v.LH ;
	  curext = mem [p + 2 ].hh .v.RH ;
	  if ( curext == 344 ) 
	  curext = 887 ;
	  packfilename ( curname , curarea , curext ) ;
	  while ( ! kpseoutnameok ( stringcast ( nameoffile + 1 ) ) || ! 
	  aopenout ( writefile [j ]) ) promptfilename ( 1453 , 887 ) ;
	  writeopen [j ]= true ;
	  if ( logopened ) 
	  {
	    oldsetting = selector ;
	    if ( ( eqtb [29217 ].cint <= 0 ) ) 
	    selector = 18 ;
	    else selector = 19 ;
	    printnl ( 1454 ) ;
	    printint ( j ) ;
	    print ( 1455 ) ;
	    printfilename ( curname , curarea , curext ) ;
	    print ( 886 ) ;
	    printnl ( 344 ) ;
	    println () ;
	    selector = oldsetting ;
	  } 
	} 
      } 
    } 
    break ;
  case 3 : 
    specialout ( p ) ;
    break ;
  case 4 : 
    ;
    break ;
  case 6 : 
    {
      switch ( dvidir ) 
      {case 4 : 
	{
	  pdflastxpos = curh ;
	  pdflastypos = curv ;
	} 
	break ;
      case 3 : 
	{
	  pdflastxpos = - (integer) curv ;
	  pdflastypos = curh ;
	} 
	break ;
      case 1 : 
	{
	  pdflastxpos = curv ;
	  pdflastypos = - (integer) curh ;
	} 
	break ;
      } 
      pdflastxpos = pdflastxpos + 4736286L ;
      switch ( dvidir ) 
      {case 3 : 
      case 1 : 
	pdflastypos = curpageheight - pdflastypos - 4736286L ;
	break ;
      case 4 : 
	pdflastypos = curpageheight - pdflastypos - 4736286L ;
	break ;
      } 
    } 
    break ;
    default: 
    confusion ( 1452 ) ;
    break ;
  } 
} 
halfword 
znewedge ( smallnumber s , scaled w ) 
{
  register halfword Result; newedge_regmem 
  halfword p  ;
  p = getnode ( 3 ) ;
  mem [p ].hh.b0 = 16 ;
  mem [p ].hh.b1 = s ;
  mem [p + 1 ].cint = w ;
  mem [p + 2 ].cint = 0 ;
  Result = p ;
  return Result ;
} 
halfword 
zzreverse ( halfword thisbox , halfword t , scaled * curg , real * curglue ) 
{
  /* 21 15 30 */ register halfword Result; reverse_regmem 
  halfword l, la  ;
  scaled disp, disp2  ;
  boolean disped  ;
  halfword p  ;
  halfword q  ;
  glueord gorder  ;
  unsigned char gsign  ;
  real gluetemp  ;
  halfword m, n  ;
  gorder = mem [thisbox + 5 ].hh.b1 ;
  gsign = mem [thisbox + 5 ].hh.b0 ;
  disp = revdisp ;
  disped = false ;
  l = t ;
  p = tempptr ;
  m = -1073741823L ;
  n = -1073741823L ;
  while ( true ) {
      
    while ( p != -1073741823L ) lab21: if ( ( p >= himemmin ) ) 
    do {
	f = mem [p ].hh.b0 ;
      c = mem [p ].hh.b1 ;
      curh = curh + fontinfo [widthbase [f ]+ fontinfo [charbase [f ]+ 
      effectivechar ( true , f , c ) ].qqqq .b0 ].cint ;
      if ( fontdir [f ]!= 0 ) 
      {
	q = mem [p ].hh .v.RH ;
	la = l ;
	l = p ;
	p = mem [q ].hh .v.RH ;
	mem [q ].hh .v.RH = la ;
      } 
      else {
	  
	q = mem [p ].hh .v.RH ;
	mem [p ].hh .v.RH = l ;
	l = p ;
	p = q ;
      } 
    } while ( ! ( ! ( p >= himemmin ) ) ) ;
    else {
	
      q = mem [p ].hh .v.RH ;
      switch ( mem [p ].hh.b0 ) 
      {case 0 : 
      case 1 : 
      case 3 : 
      case 13 : 
	rulewd = mem [p + 1 ].cint ;
	break ;
      case 12 : 
	{
	  g = mem [p + 1 ].hh .v.LH ;
	  rulewd = mem [g + 1 ].cint - *curg ;
	  if ( gsign != 0 ) 
	  {
	    if ( gsign == 1 ) 
	    {
	      if ( mem [g ].hh.b0 == gorder ) 
	      {
*                curglue = *curglue + mem [g + 2 ].cint ;
		gluetemp = mem [thisbox + 6 ].gr * *curglue ;
		if ( gluetemp > 1000000000.0 ) 
		gluetemp = 1000000000.0 ;
		else if ( gluetemp < -1000000000.0 ) 
		gluetemp = -1000000000.0 ;
*                curg = round ( gluetemp ) ;
	      } 
	    } 
	    else if ( mem [g ].hh.b1 == gorder ) 
	    {
*              curglue = *curglue - mem [g + 3 ].cint ;
	      gluetemp = mem [thisbox + 6 ].gr * *curglue ;
	      if ( gluetemp > 1000000000.0 ) 
	      gluetemp = 1000000000.0 ;
	      else if ( gluetemp < -1000000000.0 ) 
	      gluetemp = -1000000000.0 ;
*              curg = round ( gluetemp ) ;
	    } 
	  } 
	  rulewd = rulewd + *curg ;
	  if ( ( ( ( gsign == 1 ) && ( mem [g ].hh.b0 == gorder ) ) || ( ( 
	  gsign == 2 ) && ( mem [g ].hh.b1 == gorder ) ) ) ) 
	  {
	    {
	      if ( mem [g ].hh .v.RH == -1073741823L ) 
	      freenode ( g , 4 ) ;
	      else decr ( mem [g ].hh .v.RH ) ;
	    } 
	    if ( mem [p ].hh.b1 < 100 ) 
	    {
	      mem [p ].hh.b0 = 13 ;
	      mem [p + 1 ].cint = rulewd ;
	    } 
	    else {
		
	      g = getnode ( 4 ) ;
	      mem [g ].hh.b0 = 5 ;
	      mem [g ].hh.b1 = 5 ;
	      mem [g + 1 ].cint = rulewd ;
	      mem [g + 2 ].cint = 0 ;
	      mem [g + 3 ].cint = 0 ;
	      mem [p + 1 ].hh .v.LH = g ;
	    } 
	  } 
	} 
	break ;
      case 8 : 
	{
	  flushnodelist ( mem [p + 1 ].hh .v.RH ) ;
	  tempptr = p ;
	  p = getavail () ;
	  mem [p ]= mem [tempptr + 1 ];
	  mem [p ].hh .v.RH = q ;
	  freenode ( tempptr , 2 ) ;
	  goto lab21 ;
	} 
	break ;
      case 11 : 
	{
	  rulewd = mem [p + 1 ].cint ;
	  if ( odd ( mem [p ].hh.b1 ) ) {
	      
	    if ( mem [LRptr ].hh .v.LH != ( 4 * ( mem [p ].hh.b1 / 4 ) + 3 
	    ) ) 
	    {
	      mem [p ].hh.b0 = 13 ;
	      incr ( LRproblems ) ;
	    } 
	    else {
		
	      {
		tempptr = LRptr ;
		LRptr = mem [tempptr ].hh .v.RH ;
		{
		  mem [tempptr ].hh .v.RH = avail ;
		  avail = tempptr ;
	;
#ifdef STAT
		  decr ( dynused ) ;
#endif /* STAT */
		} 
	      } 
	      if ( n > -1073741823L ) 
	      {
		decr ( n ) ;
		decr ( mem [p ].hh.b1 ) ;
	      } 
	      else {
		  
		mem [p ].hh.b0 = 13 ;
		if ( m > -1073741823L ) 
		decr ( m ) ;
		else {
		    
		  freenode ( p , 4 ) ;
		  mem [t ].hh .v.RH = q ;
		  mem [t + 1 ].cint = rulewd ;
		  mem [t + 2 ].cint = - (integer) curh - rulewd ;
		  goto lab30 ;
		} 
	      } 
	    } 
	  } 
	  else {
	      
	    {
	      tempptr = getavail () ;
	      mem [tempptr ].hh .v.LH = ( 4 * ( mem [p ].hh.b1 / 4 ) + 3 ) 
	      ;
	      mem [tempptr ].hh .v.RH = LRptr ;
	      LRptr = tempptr ;
	    } 
	    if ( ( n > -1073741823L ) || ( ( mem [p ].hh.b1 / 8 ) != curdir 
	    ) ) 
	    {
	      incr ( n ) ;
	      incr ( mem [p ].hh.b1 ) ;
	    } 
	    else {
		
	      mem [p ].hh.b0 = 13 ;
	      incr ( m ) ;
	    } 
	  } 
	} 
	break ;
      case 16 : 
	confusion ( 1522 ) ;
	break ;
      case 5 : 
	{
	  disp2 = mem [p + 1 ].cint ;
	  mem [p + 1 ].cint = disp ;
	  disp = disp2 ;
	  if ( ! disped ) 
	  disped = true ;
	} 
	break ;
	default: 
	goto lab15 ;
	break ;
      } 
      curh = curh + rulewd ;
      lab15: mem [p ].hh .v.RH = l ;
      if ( mem [p ].hh.b0 == 13 ) {
	  
	if ( ( rulewd == 0 ) || ( l == -1073741823L ) ) 
	{
	  freenode ( p , 4 ) ;
	  p = l ;
	} 
      } 
      l = p ;
      p = q ;
    } 
    if ( ( t == -1073741823L ) && ( m == -1073741823L ) && ( n == -1073741823L 
    ) ) 
    goto lab30 ;
    p = newmath ( 0 , mem [LRptr ].hh .v.LH ) ;
    LRproblems = LRproblems + 10000 ;
  } 
  lab30: if ( ( l != -1073741823L ) && ( mem [l ].hh.b0 != 5 ) ) 
  {
    p = getnode ( 2 ) ;
    mem [p ].hh.b0 = 5 ;
    mem [p + 1 ].cint = disp ;
    mem [p ].hh .v.RH = l ;
    Result = p ;
  } 
  else Result = l ;
  return Result ;
} 
void 
synchdir ( void ) 
{
  synchdir_regmem 
  scaled tmp  ;
  switch ( curdirhv ) 
  {case 4 : 
    if ( dvidir != curdirhv ) 
    {
      if ( curh != dvih ) 
      {
	movement ( curh - dvih , 143 ) ;
	dvih = curh ;
      } 
      if ( curv != dviv ) 
      {
	movement ( curv - dviv , 157 ) ;
	dviv = curv ;
      } 
      {
	dvibuf [dviptr ]= 255 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      {
	dvibuf [dviptr ]= 0 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dirused = true ;
      switch ( dvidir ) 
      {case 3 : 
	{
	  tmp = curh ;
	  curh = - (integer) curv ;
	  curv = tmp ;
	} 
	break ;
      case 1 : 
	{
	  tmp = curh ;
	  curh = curv ;
	  curv = - (integer) tmp ;
	} 
	break ;
      } 
      dvih = curh ;
      dviv = curv ;
      dvidir = curdirhv ;
    } 
    break ;
  case 3 : 
    if ( dvidir != curdirhv ) 
    {
      if ( curh != dvih ) 
      {
	movement ( curh - dvih , 143 ) ;
	dvih = curh ;
      } 
      if ( curv != dviv ) 
      {
	movement ( curv - dviv , 157 ) ;
	dviv = curv ;
      } 
      {
	dvibuf [dviptr ]= 255 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      {
	dvibuf [dviptr ]= 1 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dirused = true ;
      switch ( dvidir ) 
      {case 4 : 
	{
	  tmp = curh ;
	  curh = curv ;
	  curv = - (integer) tmp ;
	} 
	break ;
      case 1 : 
	{
	  curv = - (integer) curv ;
	  curh = - (integer) curh ;
	} 
	break ;
      } 
      dvih = curh ;
      dviv = curv ;
      dvidir = curdirhv ;
    } 
    break ;
  case 1 : 
    if ( dvidir != curdirhv ) 
    {
      if ( curh != dvih ) 
      {
	movement ( curh - dvih , 143 ) ;
	dvih = curh ;
      } 
      if ( curv != dviv ) 
      {
	movement ( curv - dviv , 157 ) ;
	dviv = curv ;
      } 
      {
	dvibuf [dviptr ]= 255 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      {
	dvibuf [dviptr ]= 3 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dirused = true ;
      switch ( dvidir ) 
      {case 4 : 
	{
	  tmp = curh ;
	  curh = - (integer) curv ;
	  curv = tmp ;
	} 
	break ;
      case 3 : 
	{
	  curv = - (integer) curv ;
	  curh = - (integer) curh ;
	} 
	break ;
      } 
      dvih = curh ;
      dviv = curv ;
      dvidir = curdirhv ;
    } 
    break ;
    default: 
    confusion ( 1604 ) ;
    break ;
  } 
} 
boolean 
zcheckbox ( halfword boxp ) 
{
  /* 30 */ register boolean Result; checkbox_regmem 
  halfword p  ;
  boolean flag  ;
  flag = false ;
  p = boxp ;
  while ( p != -1073741823L ) {
      
    if ( ( p >= himemmin ) ) 
    do {
	if ( findfirstchar ) 
      {
	firstchar = p ;
	findfirstchar = false ;
      } 
      lastchar = p ;
      flag = true ;
      if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
      p = mem [p ].hh .v.RH ;
      p = mem [p ].hh .v.RH ;
      if ( p == -1073741823L ) 
      goto lab30 ;
    } while ( ! ( ! ( p >= himemmin ) ) ) ;
    switch ( mem [p ].hh.b0 ) 
    {case 0 : 
      {
	flag = true ;
	if ( mem [p + 4 ].cint == 0 ) 
	{
	  if ( checkbox ( mem [p + 5 ].hh .v.RH ) ) 
	  flag = true ;
	} 
	else if ( findfirstchar ) 
	findfirstchar = false ;
	else lastchar = -1073741823L ;
      } 
      break ;
    case 8 : 
      if ( checkbox ( mem [p + 1 ].hh .v.RH ) ) 
      flag = true ;
      break ;
    case 4 : 
    case 5 : 
    case 6 : 
    case 7 : 
    case 10 : 
    case 14 : 
      ;
      break ;
    case 11 : 
      if ( ( mem [p ].hh.b1 == 0 ) || ( mem [p ].hh.b1 == 1 ) ) 
      {
	if ( findfirstchar ) 
	{
	  findfirstchar = false ;
	  firstchar = p ;
	} 
	lastchar = p ;
	flag = true ;
      } 
      else ;
      break ;
    case 13 : 
      if ( mem [p ].hh.b1 == 2 ) 
      {
	p = mem [p ].hh .v.RH ;
	if ( ( p >= himemmin ) ) {
	    
	  if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
	  p = mem [p ].hh .v.RH ;
	} 
	p = mem [mem [p ].hh .v.RH ].hh .v.RH ;
	if ( findfirstchar ) 
	{
	  findfirstchar = false ;
	  firstchar = p ;
	} 
	lastchar = p ;
	flag = true ;
	if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
	p = mem [p ].hh .v.RH ;
      } 
      else {
	  
	flag = true ;
	if ( findfirstchar ) 
	findfirstchar = false ;
	else lastchar = -1073741823L ;
      } 
      break ;
      default: 
      {
	flag = true ;
	if ( findfirstchar ) 
	findfirstchar = false ;
	else lastchar = -1073741823L ;
      } 
      break ;
    } 
    p = mem [p ].hh .v.RH ;
  } 
  lab30: Result = flag ;
  return Result ;
} 
void 
zadjusthlist ( halfword p , boolean pf ) 
{
  /* 10 */ adjusthlist_regmem 
  halfword q, s, t, u, v, x, z  ;
  halfword i, k  ;
  halfword a  ;
  unsigned char insertskip  ;
  KANJIcode cx  ;
  ASCIIcode ax  ;
  boolean doins  ;
  if ( mem [p ].hh .v.RH == -1073741823L ) 
  return ;
  if ( eqtb [26359 ].hh .v.RH > 0 ) 
  {
    deleteglueref ( mem [p + 7 ].hh .v.RH ) ;
    mem [p + 7 ].hh .v.RH = eqtb [24543 ].hh .v.RH ;
    incr ( mem [eqtb [24543 ].hh .v.RH ].hh .v.RH ) ;
  } 
  if ( eqtb [26360 ].hh .v.RH > 0 ) 
  {
    deleteglueref ( mem [p + 7 ].hh .v.LH ) ;
    mem [p + 7 ].hh .v.LH = eqtb [24544 ].hh .v.RH ;
    incr ( mem [eqtb [24544 ].hh .v.RH ].hh .v.RH ) ;
  } 
  u = mem [p + 7 ].hh .v.RH ;
  incr ( mem [u ].hh .v.RH ) ;
  s = mem [p + 7 ].hh .v.LH ;
  incr ( mem [s ].hh .v.RH ) ;
  if ( ! ( mem [p ].hh .v.RH >= himemmin ) && ( mem [mem [p ].hh .v.RH ]
  .hh.b0 == 12 ) && ( mem [mem [p ].hh .v.RH ].hh.b1 == 21 ) ) 
  {
    v = mem [p ].hh .v.RH ;
    mem [p ].hh .v.RH = mem [v ].hh .v.RH ;
    {
      if ( mem [mem [v + 1 ].hh .v.LH ].hh .v.RH == -1073741823L ) 
      freenode ( mem [v + 1 ].hh .v.LH , 4 ) ;
      else decr ( mem [mem [v + 1 ].hh .v.LH ].hh .v.RH ) ;
    } 
    freenode ( v , 2 ) ;
  } 
  i = 0 ;
  insertskip = 0 ;
  p = mem [p ].hh .v.RH ;
  v = p ;
  q = p ;
  while ( p != -1073741823L ) {
      
    if ( ( p >= himemmin ) ) 
    {
      do {
	  if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
	{
	  cx = mem [mem [p ].hh .v.RH ].hh .v.LH % 16777216L ;
	  if ( insertskip == 1 ) 
	  {
	    {
	      x = getinhibitpos ( cx , 1 ) ;
	      if ( x != 1000 ) {
		  
		if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [27386 + x 
		].hh.b0 == 1 ) ) 
		doins = false ;
		else doins = true ;
	      } 
	      else doins = true ;
	    } 
	    if ( doins ) 
	    {
	      z = newglue ( s ) ;
	      mem [z ].hh.b1 = 17 ;
	      mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
	      mem [q ].hh .v.RH = z ;
	      q = z ;
	    } 
	  } 
	  p = mem [p ].hh .v.RH ;
	  insertskip = 2 ;
	} 
	else {
	    
	  ax = mem [p ].hh.b1 ;
	  if ( insertskip == 2 ) 
	  {
	    if ( ( eqtb [27130 + ax ].hh .v.RH % 2 ) == 1 ) 
	    {
	      x = getinhibitpos ( cx , 1 ) ;
	      if ( x != 1000 ) {
		  
		if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [27386 + x 
		].hh.b0 == 2 ) ) 
		doins = false ;
		else doins = true ;
	      } 
	      else doins = true ;
	    } 
	    else doins = false ;
	    if ( doins ) 
	    {
	      z = newglue ( s ) ;
	      mem [z ].hh.b1 = 17 ;
	      mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
	      mem [q ].hh .v.RH = z ;
	      q = z ;
	    } 
	  } 
	  if ( eqtb [27130 + ax ].hh .v.RH >= 2 ) 
	  insertskip = 1 ;
	  else insertskip = 0 ;
	} 
	q = p ;
	p = mem [p ].hh .v.RH ;
	incr ( i ) ;
	if ( ( i > 5 ) && pf ) 
	{
	  if ( ( v >= himemmin ) ) {
	      
	    if ( fontdir [mem [v ].hh.b0 ]!= 0 ) 
	    v = mem [v ].hh .v.RH ;
	  } 
	  v = mem [v ].hh .v.RH ;
	} 
      } while ( ! ( ! ( p >= himemmin ) ) ) ;
    } 
    else {
	
      switch ( mem [p ].hh.b0 ) 
      {case 0 : 
	{
	  findfirstchar = true ;
	  firstchar = -1073741823L ;
	  lastchar = -1073741823L ;
	  if ( mem [p + 4 ].cint == 0 ) 
	  {
	    if ( checkbox ( mem [p + 5 ].hh .v.RH ) ) 
	    {
	      if ( firstchar != -1073741823L ) {
		  
		if ( mem [firstchar ].hh.b0 == 11 ) 
		{
		  ax = 48 ;
		  if ( insertskip == 2 ) 
		  {
		    if ( ( eqtb [27130 + ax ].hh .v.RH % 2 ) == 1 ) 
		    {
		      x = getinhibitpos ( cx , 1 ) ;
		      if ( x != 1000 ) {
			  
			if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [
			27386 + x ].hh.b0 == 2 ) ) 
			doins = false ;
			else doins = true ;
		      } 
		      else doins = true ;
		    } 
		    else doins = false ;
		    if ( doins ) 
		    {
		      z = newglue ( s ) ;
		      mem [z ].hh.b1 = 17 ;
		      mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		      mem [q ].hh .v.RH = z ;
		      q = z ;
		    } 
		  } 
		} 
		else if ( fontdir [mem [firstchar ].hh.b0 ]!= 0 ) 
		{
		  cx = mem [mem [firstchar ].hh .v.RH ].hh .v.LH % 
		  16777216L ;
		  if ( insertskip == 1 ) 
		  {
		    {
		      x = getinhibitpos ( cx , 1 ) ;
		      if ( x != 1000 ) {
			  
			if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [
			27386 + x ].hh.b0 == 1 ) ) 
			doins = false ;
			else doins = true ;
		      } 
		      else doins = true ;
		    } 
		    if ( doins ) 
		    {
		      z = newglue ( s ) ;
		      mem [z ].hh.b1 = 17 ;
		      mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		      mem [q ].hh .v.RH = z ;
		      q = z ;
		    } 
		  } 
		  else if ( insertskip == 2 ) 
		  {
		    z = newglue ( u ) ;
		    mem [z ].hh.b1 = 16 ;
		    mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		    mem [q ].hh .v.RH = z ;
		    q = z ;
		  } 
		} 
		else {
		    
		  ax = mem [firstchar ].hh.b1 ;
		  if ( insertskip == 2 ) 
		  {
		    if ( ( eqtb [27130 + ax ].hh .v.RH % 2 ) == 1 ) 
		    {
		      x = getinhibitpos ( cx , 1 ) ;
		      if ( x != 1000 ) {
			  
			if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [
			27386 + x ].hh.b0 == 2 ) ) 
			doins = false ;
			else doins = true ;
		      } 
		      else doins = true ;
		    } 
		    else doins = false ;
		    if ( doins ) 
		    {
		      z = newglue ( s ) ;
		      mem [z ].hh.b1 = 17 ;
		      mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		      mem [q ].hh .v.RH = z ;
		      q = z ;
		    } 
		  } 
		} 
	      } 
	      if ( lastchar != -1073741823L ) 
	      {
		if ( mem [lastchar ].hh.b0 == 11 ) 
		{
		  ax = 48 ;
		  if ( eqtb [27130 + ax ].hh .v.RH >= 2 ) 
		  insertskip = 1 ;
		  else insertskip = 0 ;
		} 
		else if ( fontdir [mem [lastchar ].hh.b0 ]!= 0 ) 
		{
		  insertskip = 2 ;
		  cx = mem [mem [lastchar ].hh .v.RH ].hh .v.LH ;
		  if ( ( mem [p ].hh .v.RH >= himemmin ) && ( fontdir [mem 
		  [mem [p ].hh .v.RH ].hh.b0 ]!= 0 ) ) 
		  {
		    {
		      z = newglue ( u ) ;
		      mem [z ].hh.b1 = 16 ;
		      mem [z ].hh .v.RH = mem [p ].hh .v.RH ;
		      mem [p ].hh .v.RH = z ;
		      p = mem [z ].hh .v.RH ;
		      q = z ;
		    } 
		    p = mem [p ].hh .v.RH ;
		  } 
		} 
		else {
		    
		  ax = mem [lastchar ].hh.b1 ;
		  if ( eqtb [27130 + ax ].hh .v.RH >= 2 ) 
		  insertskip = 1 ;
		  else insertskip = 0 ;
		} 
	      } 
	      else insertskip = 0 ;
	    } 
	    else insertskip = 0 ;
	  } 
	  else insertskip = 0 ;
	} 
	break ;
      case 8 : 
	{
	  t = mem [p + 1 ].hh .v.RH ;
	  if ( ( t >= himemmin ) ) 
	  {
	    ax = mem [t ].hh.b1 ;
	    if ( insertskip == 2 ) 
	    {
	      if ( ( eqtb [27130 + ax ].hh .v.RH % 2 ) == 1 ) 
	      {
		x = getinhibitpos ( cx , 1 ) ;
		if ( x != 1000 ) {
		    
		  if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [27386 + 
		  x ].hh.b0 == 2 ) ) 
		  doins = false ;
		  else doins = true ;
		} 
		else doins = true ;
	      } 
	      else doins = false ;
	      if ( doins ) 
	      {
		z = newglue ( s ) ;
		mem [z ].hh.b1 = 17 ;
		mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		mem [q ].hh .v.RH = z ;
		q = z ;
	      } 
	    } 
	    while ( mem [t ].hh .v.RH != -1073741823L ) t = mem [t ].hh 
	    .v.RH ;
	    if ( ( t >= himemmin ) ) 
	    {
	      ax = mem [t ].hh.b1 ;
	      if ( eqtb [27130 + ax ].hh .v.RH >= 2 ) 
	      insertskip = 1 ;
	      else insertskip = 0 ;
	    } 
	  } 
	} 
	break ;
      case 14 : 
      case 5 : 
	{
	  if ( ( mem [p ].hh .v.RH >= himemmin ) ) 
	  {
	    q = p ;
	    p = mem [p ].hh .v.RH ;
	    if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
	    {
	      cx = mem [mem [p ].hh .v.RH ].hh .v.LH % 16777216L ;
	      if ( insertskip == 1 ) 
	      {
		{
		  x = getinhibitpos ( cx , 1 ) ;
		  if ( x != 1000 ) {
		      
		    if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [27386 
		    + x ].hh.b0 == 1 ) ) 
		    doins = false ;
		    else doins = true ;
		  } 
		  else doins = true ;
		} 
		if ( doins ) 
		{
		  z = newglue ( s ) ;
		  mem [z ].hh.b1 = 17 ;
		  mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		  mem [q ].hh .v.RH = z ;
		  q = z ;
		} 
	      } 
	      else if ( insertskip == 2 ) 
	      {
		z = newglue ( u ) ;
		mem [z ].hh.b1 = 16 ;
		mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		mem [q ].hh .v.RH = z ;
		q = z ;
	      } 
	      p = mem [p ].hh .v.RH ;
	      insertskip = 2 ;
	    } 
	    else {
		
	      ax = mem [p ].hh.b1 ;
	      if ( insertskip == 2 ) 
	      {
		if ( ( eqtb [27130 + ax ].hh .v.RH % 2 ) == 1 ) 
		{
		  x = getinhibitpos ( cx , 1 ) ;
		  if ( x != 1000 ) {
		      
		    if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [27386 
		    + x ].hh.b0 == 2 ) ) 
		    doins = false ;
		    else doins = true ;
		  } 
		  else doins = true ;
		} 
		else doins = false ;
		if ( doins ) 
		{
		  z = newglue ( s ) ;
		  mem [z ].hh.b1 = 17 ;
		  mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		  mem [q ].hh .v.RH = z ;
		  q = z ;
		} 
	      } 
	      if ( eqtb [27130 + ax ].hh .v.RH >= 2 ) 
	      insertskip = 1 ;
	      else insertskip = 0 ;
	    } 
	  } 
	} 
	break ;
      case 13 : 
	if ( mem [p ].hh.b1 == 1 ) 
	insertskip = 0 ;
	else if ( mem [p ].hh.b1 == 2 ) 
	{
	  if ( q == p ) 
	  {
	    t = mem [p ].hh .v.RH ;
	    if ( ( t >= himemmin ) ) {
		
	      if ( fontdir [mem [t ].hh.b0 ]!= 0 ) 
	      t = mem [t ].hh .v.RH ;
	    } 
	    p = mem [mem [t ].hh .v.RH ].hh .v.RH ;
	    if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
	    {
	      p = mem [p ].hh .v.RH ;
	      insertskip = 2 ;
	    } 
	    else insertskip = 1 ;
	  } 
	  else {
	      
	    a = p ;
	    t = mem [p ].hh .v.RH ;
	    if ( ( t >= himemmin ) ) {
		
	      if ( fontdir [mem [t ].hh.b0 ]!= 0 ) 
	      t = mem [t ].hh .v.RH ;
	    } 
	    t = mem [mem [t ].hh .v.RH ].hh .v.RH ;
	    mem [q ].hh .v.RH = t ;
	    p = t ;
	    if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
	    {
	      cx = mem [mem [p ].hh .v.RH ].hh .v.LH % 16777216L ;
	      if ( insertskip == 1 ) 
	      {
		{
		  x = getinhibitpos ( cx , 1 ) ;
		  if ( x != 1000 ) {
		      
		    if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [27386 
		    + x ].hh.b0 == 1 ) ) 
		    doins = false ;
		    else doins = true ;
		  } 
		  else doins = true ;
		} 
		if ( doins ) 
		{
		  z = newglue ( s ) ;
		  mem [z ].hh.b1 = 17 ;
		  mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		  mem [q ].hh .v.RH = z ;
		  q = z ;
		} 
	      } 
	      p = mem [p ].hh .v.RH ;
	      insertskip = 2 ;
	    } 
	    else {
		
	      ax = mem [p ].hh.b1 ;
	      if ( insertskip == 2 ) 
	      {
		if ( ( eqtb [27130 + ax ].hh .v.RH % 2 ) == 1 ) 
		{
		  x = getinhibitpos ( cx , 1 ) ;
		  if ( x != 1000 ) {
		      
		    if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [27386 
		    + x ].hh.b0 == 2 ) ) 
		    doins = false ;
		    else doins = true ;
		  } 
		  else doins = true ;
		} 
		else doins = false ;
		if ( doins ) 
		{
		  z = newglue ( s ) ;
		  mem [z ].hh.b1 = 17 ;
		  mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		  mem [q ].hh .v.RH = z ;
		  q = z ;
		} 
	      } 
	      if ( eqtb [27130 + ax ].hh .v.RH >= 2 ) 
	      insertskip = 1 ;
	      else insertskip = 0 ;
	    } 
	    incr ( i ) ;
	    if ( ( i > 5 ) && pf ) 
	    {
	      if ( ( v >= himemmin ) ) {
		  
		if ( fontdir [mem [v ].hh.b0 ]!= 0 ) 
		v = mem [v ].hh .v.RH ;
	      } 
	      v = mem [v ].hh .v.RH ;
	    } 
	    if ( mem [q ].hh .v.RH != t ) 
	    mem [mem [q ].hh .v.RH ].hh .v.RH = a ;
	    else mem [q ].hh .v.RH = a ;
	  } 
	} 
	break ;
      case 11 : 
	{
	  if ( ( mem [p ].hh.b1 == 0 ) && ( insertskip == 2 ) ) 
	  {
	    ax = 48 ;
	    {
	      if ( ( eqtb [27130 + ax ].hh .v.RH % 2 ) == 1 ) 
	      {
		x = getinhibitpos ( cx , 1 ) ;
		if ( x != 1000 ) {
		    
		  if ( ( eqtb [27386 + x ].hh.b0 == 0 ) || ( eqtb [27386 + 
		  x ].hh.b0 == 2 ) ) 
		  doins = false ;
		  else doins = true ;
		} 
		else doins = true ;
	      } 
	      else doins = false ;
	      if ( doins ) 
	      {
		z = newglue ( s ) ;
		mem [z ].hh.b1 = 17 ;
		mem [z ].hh .v.RH = mem [q ].hh .v.RH ;
		mem [q ].hh .v.RH = z ;
		q = z ;
	      } 
	    } 
	    insertskip = 0 ;
	  } 
	  else if ( mem [p ].hh.b1 == 1 ) 
	  {
	    ax = 48 ;
	    if ( eqtb [27130 + ax ].hh .v.RH >= 2 ) 
	    insertskip = 1 ;
	    else insertskip = 0 ;
	  } 
	  else insertskip = 0 ;
	} 
	break ;
      case 6 : 
      case 7 : 
      case 4 : 
      case 10 : 
	;
	break ;
	default: 
	insertskip = 0 ;
	break ;
      } 
      q = p ;
      p = mem [p ].hh .v.RH ;
    } 
  } 
  if ( ! ( q >= himemmin ) && ( mem [q ].hh.b0 == 12 ) && ( mem [q ].hh.b1 
  == 21 ) ) 
  {
    {
      if ( mem [mem [q + 1 ].hh .v.LH ].hh .v.RH == -1073741823L ) 
      freenode ( mem [q + 1 ].hh .v.LH , 4 ) ;
      else decr ( mem [mem [q + 1 ].hh .v.LH ].hh .v.RH ) ;
    } 
    mem [q + 1 ].hh .v.LH = membot ;
    incr ( mem [membot ].hh .v.RH ) ;
  } 
  deleteglueref ( u ) ;
  deleteglueref ( s ) ;
  if ( ( v != -1073741823L ) && pf && ( i > 5 ) ) 
  {
    q = v ;
    p = mem [v ].hh .v.RH ;
    if ( ( v >= himemmin ) && ( fontdir [mem [v ].hh.b0 ]!= 0 ) ) 
    {
      q = p ;
      p = mem [p ].hh .v.RH ;
    } 
    t = q ;
    s = -1073741823L ;
    while ( ( p != -1073741823L ) ) {
	
      if ( ( p >= himemmin ) ) 
      {
	if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
	{
	  cx = mem [mem [p ].hh .v.RH ].hh .v.LH % 16777216L ;
	  i = mem [mem [p ].hh .v.RH ].hh .v.LH / 16777216L ;
	  k = 0 ;
	  if ( ( i == 16 ) || ( i == 17 ) || ( i == 19 ) ) 
	  {
	    t = q ;
	    s = p ;
	  } 
	  p = mem [p ].hh .v.RH ;
	  q = p ;
	} 
	else {
	    
	  k = k + 1 ;
	  if ( k > 1 ) 
	  {
	    q = p ;
	    s = -1073741823L ;
	  } 
	} 
      } 
      else {
	  
	switch ( mem [p ].hh.b0 ) 
	{case 14 : 
	case 6 : 
	case 7 : 
	case 10 : 
	case 12 : 
	case 13 : 
	case 11 : 
	case 5 : 
	  ;
	  break ;
	  default: 
	  {
	    q = p ;
	    s = -1073741823L ;
	  } 
	  break ;
	} 
      } 
      p = mem [p ].hh .v.RH ;
    } 
    if ( s != -1073741823L ) 
    {
      s = mem [t ].hh .v.RH ;
      if ( ! ( s >= himemmin ) && ( mem [s ].hh.b0 == 14 ) ) 
      mem [s + 1 ].cint = mem [s + 1 ].cint + eqtb [29244 ].cint ;
      else if ( eqtb [29244 ].cint != 0 ) 
      {
	s = newpenalty ( eqtb [29244 ].cint ) ;
	mem [s ].hh.b1 = 1 ;
	mem [s ].hh .v.RH = mem [t ].hh .v.RH ;
	mem [t ].hh .v.RH = s ;
	t = mem [s ].hh .v.RH ;
	while ( ( ! ( t >= himemmin ) ) ) {
	    
	  if ( ( mem [t ].hh.b0 == 12 ) || ( mem [t ].hh.b0 == 13 ) ) 
	  return ;
	  t = mem [t ].hh .v.RH ;
	} 
	z = newglue ( u ) ;
	mem [z ].hh.b1 = 16 ;
	mem [z ].hh .v.RH = mem [s ].hh .v.RH ;
	mem [s ].hh .v.RH = z ;
      } 
    } 
  } 
} 
void 
dirout ( void ) 
{
  dirout_regmem 
  halfword thisbox  ;
  thisbox = tempptr ;
  tempptr = mem [thisbox + 5 ].hh .v.RH ;
  if ( ( mem [tempptr ].hh.b0 != 0 ) && ( mem [tempptr ].hh.b0 != 1 ) ) 
  confusion ( 1605 ) ;
  switch ( ( ( mem [thisbox ].hh.b1 ) % 8 ) ) 
  {case 4 : 
    switch ( ( ( mem [tempptr ].hh.b1 ) % 8 ) ) 
    {case 3 : 
      {
	curv = curv - mem [thisbox + 3 ].cint ;
	curh = curh + mem [tempptr + 2 ].cint ;
      } 
      break ;
    case 1 : 
      {
	curv = curv + mem [thisbox + 2 ].cint ;
	curh = curh + mem [tempptr + 3 ].cint ;
      } 
      break ;
    } 
    break ;
  case 3 : 
    switch ( ( ( mem [tempptr ].hh.b1 ) % 8 ) ) 
    {case 4 : 
      {
	curv = curv + mem [thisbox + 2 ].cint ;
	curh = curh + mem [tempptr + 3 ].cint ;
      } 
      break ;
    case 1 : 
      {
	curv = curv + mem [thisbox + 2 ].cint - mem [tempptr + 3 ].cint ;
	curh = curh + mem [tempptr + 1 ].cint ;
      } 
      break ;
    } 
    break ;
  case 1 : 
    switch ( ( ( mem [tempptr ].hh.b1 ) % 8 ) ) 
    {case 4 : 
      {
	curv = curv - mem [thisbox + 3 ].cint ;
	curh = curh + mem [tempptr + 2 ].cint ;
      } 
      break ;
    case 3 : 
      {
	curv = curv + mem [thisbox + 2 ].cint - mem [tempptr + 3 ].cint ;
	curh = curh + mem [tempptr + 1 ].cint ;
      } 
      break ;
    } 
    break ;
  } 
  curdirhv = ( ( mem [tempptr ].hh.b1 ) % 8 ) ;
  if ( mem [tempptr ].hh.b0 == 1 ) 
  vlistout () ;
  else hlistout () ;
} 
void 
hlistout ( void ) 
{
  /* 21 13 14 15 22 40 */ hlistout_regmem 
  scaled baseline  ;
  scaled disp  ;
  eightbits savedir  ;
  KANJIcode jc  ;
  halfword kspptr  ;
  scaled leftedge  ;
  scaled saveh, savev  ;
  halfword thisbox  ;
  glueord gorder  ;
  unsigned char gsign  ;
  halfword p  ;
  integer saveloc  ;
  halfword leaderbox  ;
  scaled leaderwd  ;
  scaled lx  ;
  boolean outerdoingleaders  ;
  scaled edge  ;
  halfword prevp  ;
  real gluetemp  ;
  real curglue  ;
  scaled curg  ;
  curg = 0 ;
  curglue = 0.0 ;
  thisbox = tempptr ;
  gorder = mem [thisbox + 5 ].hh.b1 ;
  gsign = mem [thisbox + 5 ].hh.b0 ;
  p = mem [thisbox + 5 ].hh .v.RH ;
  kspptr = mem [thisbox + 7 ].hh .v.RH ;
  incr ( curs ) ;
  if ( curs > 0 ) 
  {
    dvibuf [dviptr ]= 141 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  if ( curs > maxpush ) 
  maxpush = curs ;
  saveloc = dvioffset + dviptr ;
  synchdir () ;
  baseline = curv ;
  disp = 0 ;
  revdisp = 0 ;
  prevp = thisbox + 5 ;
  if ( ( eTeXmode == 1 ) ) 
  {
    {
      tempptr = getavail () ;
      mem [tempptr ].hh .v.LH = 0 ;
      mem [tempptr ].hh .v.RH = LRptr ;
      LRptr = tempptr ;
    } 
    if ( ( ( mem [thisbox ].hh.b1 ) / 8 ) == 2 ) {
	
      if ( curdir == 1 ) 
      {
	curdir = 0 ;
	curh = curh - mem [thisbox + 1 ].cint ;
      } 
      else mem [thisbox ].hh.b1 = ( ( mem [thisbox ].hh.b1 ) % 8 ) + 8 * ( 
      0 ) ;
    } 
    if ( ( curdir == 1 ) && ( ( ( mem [thisbox ].hh.b1 ) / 8 ) != 1 ) ) 
    {
      saveh = curh ;
      tempptr = p ;
      p = newkern ( 0 ) ;
      mem [p + 2 ].cint = 0 ;
      mem [prevp ].hh .v.RH = p ;
      curh = 0 ;
      mem [p ].hh .v.RH = reverse ( thisbox , -1073741823L , curg , curglue 
      ) ;
      mem [p + 1 ].cint = - (integer) curh ;
      curh = saveh ;
      mem [thisbox ].hh.b1 = ( ( mem [thisbox ].hh.b1 ) % 8 ) + 8 * ( 1 ) 
      ;
    } 
  } 
  leftedge = curh ;
  synctexhlist ( thisbox ) ;
  while ( p != -1073741823L ) lab21: if ( ( p >= himemmin ) ) 
  {
    if ( curh != dvih ) 
    {
      movement ( curh - dvih , 143 ) ;
      dvih = curh ;
    } 
    if ( curv != dviv ) 
    {
      movement ( curv - dviv , 157 ) ;
      dviv = curv ;
    } 
    chain = false ;
    do {
	f = mem [p ].hh.b0 ;
      c = mem [p ].hh.b1 ;
      if ( f != dvif ) 
      {
	if ( ! fontused [f ]) 
	{
	  dvifontdef ( f ) ;
	  fontused [f ]= true ;
	} 
	if ( f <= 64 ) 
	{
	  dvibuf [dviptr ]= f + 170 ;
	  incr ( dviptr ) ;
	  if ( dviptr == dvilimit ) 
	  dviswap () ;
	} 
	else if ( f <= 256 ) 
	{
	  {
	    dvibuf [dviptr ]= 235 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  {
	    dvibuf [dviptr ]= f - 1 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	} 
	else {
	    
	  {
	    dvibuf [dviptr ]= 236 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  {
	    dvibuf [dviptr ]= ( f - 1 ) / 256 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  {
	    dvibuf [dviptr ]= ( f - 1 ) % 256 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	} 
	dvif = f ;
      } 
      if ( fontdir [f ]== 0 ) 
      {
	chain = false ;
	if ( fontec [f ]>= c ) {
	    
	  if ( fontbc [f ]<= c ) {
	      
	    if ( ( fontinfo [charbase [f ]+ c ].qqqq .b0 > 0 ) ) 
	    {
	      if ( c >= 128 ) 
	      {
		dvibuf [dviptr ]= 128 ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	      {
		dvibuf [dviptr ]= c ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	      curh = curh + fontinfo [widthbase [f ]+ fontinfo [charbase [
	      f ]+ c ].qqqq .b0 ].cint ;
	      goto lab22 ;
	    } 
	  } 
	} 
	if ( mltexenabledp ) 
	{
	  if ( c >= eqtb [29248 ].cint ) {
	      
	    if ( c <= eqtb [29249 ].cint ) {
		
	      if ( ( eqtb [28932 + c ].hh .v.RH > 0 ) ) 
	      {
		basec = ( eqtb [28932 + c ].hh .v.RH % 256 ) ;
		accentc = ( eqtb [28932 + c ].hh .v.RH / 256 ) ;
		if ( ( fontec [f ]>= basec ) ) {
		    
		  if ( ( fontbc [f ]<= basec ) ) {
		      
		    if ( ( fontec [f ]>= accentc ) ) {
			
		      if ( ( fontbc [f ]<= accentc ) ) 
		      {
			iac = fontinfo [charbase [f ]+ effectivechar ( true 
			, f , accentc ) ].qqqq ;
			ibc = fontinfo [charbase [f ]+ effectivechar ( true 
			, f , basec ) ].qqqq ;
			if ( ( ibc .b0 > 0 ) ) {
			    
			  if ( ( iac .b0 > 0 ) ) 
			  goto lab40 ;
			} 
		      } 
		    } 
		  } 
		} 
		begindiagnostic () ;
		printnl ( 1565 ) ;
		print ( c ) ;
		print ( 1335 ) ;
		print ( accentc ) ;
		print ( 32 ) ;
		print ( basec ) ;
		print ( 924 ) ;
		slowprint ( fontname [f ]) ;
		printchar ( 33 ) ;
		enddiagnostic ( false ) ;
		goto lab22 ;
	      } 
	    } 
	  } 
	  begindiagnostic () ;
	  printnl ( 923 ) ;
	  print ( 1564 ) ;
	  print ( c ) ;
	  print ( 924 ) ;
	  slowprint ( fontname [f ]) ;
	  printchar ( 33 ) ;
	  enddiagnostic ( false ) ;
	  goto lab22 ;
	  lab40: if ( eqtb [29223 ].cint > 99 ) 
	  {
	    begindiagnostic () ;
	    printnl ( 1566 ) ;
	    print ( c ) ;
	    print ( 1335 ) ;
	    print ( accentc ) ;
	    print ( 32 ) ;
	    print ( basec ) ;
	    print ( 924 ) ;
	    slowprint ( fontname [f ]) ;
	    printchar ( 46 ) ;
	    enddiagnostic ( false ) ;
	  } 
	  basexheight = fontinfo [5 + parambase [f ]].cint ;
	  baseslant = fontinfo [1 + parambase [f ]].cint / ((double) 
	  65536.0 ) ;
	  accentslant = baseslant ;
	  basewidth = fontinfo [widthbase [f ]+ ibc .b0 ].cint ;
	  baseheight = fontinfo [heightbase [f ]+ ( ibc .b1 ) / 16 ].cint 
	  ;
	  accentwidth = fontinfo [widthbase [f ]+ iac .b0 ].cint ;
	  accentheight = fontinfo [heightbase [f ]+ ( iac .b1 ) / 16 ]
	  .cint ;
	  delta = round ( ( basewidth - accentwidth ) / ((double) 2.0 ) + 
	  baseheight * baseslant - basexheight * accentslant ) ;
	  dvih = curh ;
	  curh = curh + delta ;
	  if ( curh != dvih ) 
	  {
	    movement ( curh - dvih , 143 ) ;
	    dvih = curh ;
	  } 
	  if ( ( ( baseheight != basexheight ) && ( accentheight > 0 ) ) ) 
	  {
	    curv = baseline + ( basexheight - baseheight ) ;
	    if ( curv != dviv ) 
	    {
	      movement ( curv - dviv , 157 ) ;
	      dviv = curv ;
	    } 
	    if ( accentc >= 128 ) 
	    {
	      dvibuf [dviptr ]= 128 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    {
	      dvibuf [dviptr ]= accentc ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    curv = baseline ;
	  } 
	  else {
	      
	    if ( curv != dviv ) 
	    {
	      movement ( curv - dviv , 157 ) ;
	      dviv = curv ;
	    } 
	    if ( accentc >= 128 ) 
	    {
	      dvibuf [dviptr ]= 128 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    {
	      dvibuf [dviptr ]= accentc ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	  } 
	  curh = curh + accentwidth ;
	  dvih = curh ;
	  curh = curh + ( - (integer) accentwidth - delta ) ;
	  if ( curh != dvih ) 
	  {
	    movement ( curh - dvih , 143 ) ;
	    dvih = curh ;
	  } 
	  if ( curv != dviv ) 
	  {
	    movement ( curv - dviv , 157 ) ;
	    dviv = curv ;
	  } 
	  if ( basec >= 128 ) 
	  {
	    dvibuf [dviptr ]= 128 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  {
	    dvibuf [dviptr ]= basec ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  curh = curh + basewidth ;
	  dvih = curh ;
	} 
	lab22: ;
      } 
      else {
	  
	if ( chain == false ) 
	chain = true ;
	else {
	    
	  curh = curh + mem [kspptr + 1 ].cint ;
	  if ( gsign != 0 ) 
	  {
	    if ( gsign == 1 ) 
	    {
	      if ( mem [kspptr ].hh.b0 == gorder ) 
	      curh = curh + round ( mem [thisbox + 6 ].gr * mem [kspptr + 2 
	      ].cint ) ;
	    } 
	    else {
		
	      if ( mem [kspptr ].hh.b1 == gorder ) 
	      curh = curh - round ( mem [thisbox + 6 ].gr * mem [kspptr + 3 
	      ].cint ) ;
	    } 
	  } 
	  if ( curh != dvih ) 
	  {
	    movement ( curh - dvih , 143 ) ;
	    dvih = curh ;
	  } 
	} 
	prevp = mem [prevp ].hh .v.RH ;
	p = mem [p ].hh .v.RH ;
	jc = toDVI ( mem [p ].hh .v.LH % 16777216L ) ;
	if ( ( jc < 65536L ) ) 
	{
	  {
	    dvibuf [dviptr ]= 129 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	} 
	else {
	    
	  {
	    dvibuf [dviptr ]= 130 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  {
	    dvibuf [dviptr ]= BYTE2 ( jc ) ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	} 
	{
	  dvibuf [dviptr ]= BYTE3 ( jc ) ;
	  incr ( dviptr ) ;
	  if ( dviptr == dvilimit ) 
	  dviswap () ;
	} 
	{
	  dvibuf [dviptr ]= BYTE4 ( jc ) ;
	  incr ( dviptr ) ;
	  if ( dviptr == dvilimit ) 
	  dviswap () ;
	} 
	curh = curh + fontinfo [widthbase [f ]+ fontinfo [charbase [f ]+ 
	c ].qqqq .b0 ].cint ;
      } 
      dvih = curh ;
      p = mem [p ].hh .v.RH ;
    } while ( ! ( ! ( p >= himemmin ) ) ) ;
    synctexcurrent () ;
    chain = false ;
  } 
  else {
      
    switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 2 : 
      if ( mem [p + 5 ].hh .v.RH == -1073741823L ) 
      {
	if ( mem [p ].hh.b0 != 2 ) {
	    
	  if ( mem [p ].hh.b0 == 1 ) 
	  {
	    synctexvoidvlist ( p , thisbox ) ;
	  } 
	  else {
	      
	    synctexvoidhlist ( p , thisbox ) ;
	  } 
	} 
	curh = curh + mem [p + 1 ].cint ;
      } 
      else {
	  
	saveh = dvih ;
	savev = dviv ;
	savedir = dvidir ;
	curv = baseline + disp + mem [p + 4 ].cint ;
	tempptr = p ;
	edge = curh + mem [p + 1 ].cint ;
	if ( curdir == 1 ) 
	curh = edge ;
	switch ( mem [p ].hh.b0 ) 
	{case 0 : 
	  hlistout () ;
	  break ;
	case 1 : 
	  vlistout () ;
	  break ;
	case 2 : 
	  dirout () ;
	  break ;
	} 
	dvih = saveh ;
	dviv = savev ;
	dvidir = savedir ;
	curh = edge ;
	curv = baseline + disp ;
	curdirhv = savedir ;
      } 
      break ;
    case 3 : 
      {
	ruleht = mem [p + 3 ].cint ;
	ruledp = mem [p + 2 ].cint ;
	rulewd = mem [p + 1 ].cint ;
	goto lab14 ;
      } 
      break ;
    case 10 : 
      outwhat ( p ) ;
      break ;
    case 5 : 
      {
	disp = mem [p + 1 ].cint ;
	revdisp = disp ;
	curv = baseline + disp ;
      } 
      break ;
    case 12 : 
      {
	g = mem [p + 1 ].hh .v.LH ;
	rulewd = mem [g + 1 ].cint - curg ;
	if ( gsign != 0 ) 
	{
	  if ( gsign == 1 ) 
	  {
	    if ( mem [g ].hh.b0 == gorder ) 
	    {
	      curglue = curglue + mem [g + 2 ].cint ;
	      gluetemp = mem [thisbox + 6 ].gr * curglue ;
	      if ( gluetemp > 1000000000.0 ) 
	      gluetemp = 1000000000.0 ;
	      else if ( gluetemp < -1000000000.0 ) 
	      gluetemp = -1000000000.0 ;
	      curg = round ( gluetemp ) ;
	    } 
	  } 
	  else if ( mem [g ].hh.b1 == gorder ) 
	  {
	    curglue = curglue - mem [g + 3 ].cint ;
	    gluetemp = mem [thisbox + 6 ].gr * curglue ;
	    if ( gluetemp > 1000000000.0 ) 
	    gluetemp = 1000000000.0 ;
	    else if ( gluetemp < -1000000000.0 ) 
	    gluetemp = -1000000000.0 ;
	    curg = round ( gluetemp ) ;
	  } 
	} 
	rulewd = rulewd + curg ;
	if ( ( eTeXmode == 1 ) ) {
	    
	  if ( ( ( ( gsign == 1 ) && ( mem [g ].hh.b0 == gorder ) ) || ( ( 
	  gsign == 2 ) && ( mem [g ].hh.b1 == gorder ) ) ) ) 
	  {
	    {
	      if ( mem [g ].hh .v.RH == -1073741823L ) 
	      freenode ( g , 4 ) ;
	      else decr ( mem [g ].hh .v.RH ) ;
	    } 
	    if ( mem [p ].hh.b1 < 100 ) 
	    {
	      mem [p ].hh.b0 = 13 ;
	      mem [p + 1 ].cint = rulewd ;
	    } 
	    else {
		
	      g = getnode ( 4 ) ;
	      mem [g ].hh.b0 = 5 ;
	      mem [g ].hh.b1 = 5 ;
	      mem [g + 1 ].cint = rulewd ;
	      mem [g + 2 ].cint = 0 ;
	      mem [g + 3 ].cint = 0 ;
	      mem [p + 1 ].hh .v.LH = g ;
	    } 
	  } 
	} 
	if ( mem [p ].hh.b1 >= 100 ) 
	{
	  leaderbox = mem [p + 1 ].hh .v.RH ;
	  if ( mem [leaderbox ].hh.b0 == 3 ) 
	  {
	    ruleht = mem [leaderbox + 3 ].cint ;
	    ruledp = mem [leaderbox + 2 ].cint ;
	    goto lab14 ;
	  } 
	  leaderwd = mem [leaderbox + 1 ].cint ;
	  if ( ( leaderwd > 0 ) && ( rulewd > 0 ) ) 
	  {
	    rulewd = rulewd + 10 ;
	    if ( curdir == 1 ) 
	    curh = curh - 10 ;
	    edge = curh + rulewd ;
	    lx = 0 ;
	    if ( mem [p ].hh.b1 == 100 ) 
	    {
	      saveh = curh ;
	      curh = leftedge + leaderwd * ( ( curh - leftedge ) / leaderwd ) 
	      ;
	      if ( curh < saveh ) 
	      curh = curh + leaderwd ;
	    } 
	    else {
		
	      lq = rulewd / leaderwd ;
	      lr = rulewd % leaderwd ;
	      if ( mem [p ].hh.b1 == 101 ) 
	      curh = curh + ( lr / 2 ) ;
	      else {
		  
		lx = lr / ( lq + 1 ) ;
		curh = curh + ( ( lr - ( lq - 1 ) * lx ) / 2 ) ;
	      } 
	    } 
	    while ( curh + leaderwd <= edge ) {
		
	      curv = baseline + disp + mem [leaderbox + 4 ].cint ;
	      if ( curv != dviv ) 
	      {
		movement ( curv - dviv , 157 ) ;
		dviv = curv ;
	      } 
	      savev = dviv ;
	      if ( curh != dvih ) 
	      {
		movement ( curh - dvih , 143 ) ;
		dvih = curh ;
	      } 
	      saveh = dvih ;
	      savedir = dvidir ;
	      tempptr = leaderbox ;
	      if ( curdir == 1 ) 
	      curh = curh + leaderwd ;
	      outerdoingleaders = doingleaders ;
	      doingleaders = true ;
	      switch ( mem [leaderbox ].hh.b0 ) 
	      {case 0 : 
		hlistout () ;
		break ;
	      case 1 : 
		vlistout () ;
		break ;
	      case 2 : 
		dirout () ;
		break ;
	      } 
	      doingleaders = outerdoingleaders ;
	      dviv = savev ;
	      dvih = saveh ;
	      dvidir = savedir ;
	      curv = baseline ;
	      curh = saveh + leaderwd + lx ;
	      curdirhv = savedir ;
	    } 
	    if ( curdir == 1 ) 
	    curh = edge ;
	    else curh = edge - 10 ;
	    goto lab15 ;
	  } 
	} 
	goto lab13 ;
      } 
      break ;
    case 13 : 
      {
	synctexkern ( p , thisbox ) ;
	curh = curh + mem [p + 1 ].cint ;
      } 
      break ;
    case 11 : 
      {
	synctexmath ( p , thisbox ) ;
	{
	  if ( ( eTeXmode == 1 ) ) 
	  {
	    if ( odd ( mem [p ].hh.b1 ) ) {
		
	      if ( mem [LRptr ].hh .v.LH == ( 4 * ( mem [p ].hh.b1 / 4 ) + 
	      3 ) ) 
	      {
		tempptr = LRptr ;
		LRptr = mem [tempptr ].hh .v.RH ;
		{
		  mem [tempptr ].hh .v.RH = avail ;
		  avail = tempptr ;
	;
#ifdef STAT
		  decr ( dynused ) ;
#endif /* STAT */
		} 
	      } 
	      else {
		  
		if ( mem [p ].hh.b1 > 4 ) 
		incr ( LRproblems ) ;
	      } 
	    } 
	    else {
		
	      {
		tempptr = getavail () ;
		mem [tempptr ].hh .v.LH = ( 4 * ( mem [p ].hh.b1 / 4 ) + 3 
		) ;
		mem [tempptr ].hh .v.RH = LRptr ;
		LRptr = tempptr ;
	      } 
	      if ( ( mem [p ].hh.b1 / 8 ) != curdir ) 
	      {
		saveh = curh ;
		tempptr = mem [p ].hh .v.RH ;
		rulewd = mem [p + 1 ].cint ;
		freenode ( p , 4 ) ;
		curdir = 1 - curdir ;
		p = newedge ( curdir , rulewd ) ;
		mem [prevp ].hh .v.RH = p ;
		curh = curh - leftedge + rulewd ;
		mem [p ].hh .v.RH = reverse ( thisbox , newedge ( 1 - curdir 
		, 0 ) , curg , curglue ) ;
		mem [p + 2 ].cint = curh ;
		curdir = 1 - curdir ;
		curh = saveh ;
		goto lab21 ;
	      } 
	    } 
	    mem [p ].hh.b0 = 13 ;
	  } 
	  curh = curh + mem [p + 1 ].cint ;
	} 
      } 
      break ;
    case 8 : 
      {
	mem [memtop - 12 ]= mem [p + 1 ];
	mem [memtop - 12 ].hh .v.RH = mem [p ].hh .v.RH ;
	p = memtop - 12 ;
	goto lab21 ;
      } 
      break ;
    case 16 : 
      {
	curh = curh + mem [p + 1 ].cint ;
	leftedge = curh + mem [p + 2 ].cint ;
	curdir = mem [p ].hh.b1 ;
      } 
      break ;
      default: 
      ;
      break ;
    } 
    goto lab15 ;
    lab14: if ( ( ruleht == -1073741824L ) ) 
    ruleht = mem [thisbox + 3 ].cint + disp ;
    if ( ( ruledp == -1073741824L ) ) 
    ruledp = mem [thisbox + 2 ].cint - disp ;
    ruleht = ruleht + ruledp ;
    if ( ( ruleht > 0 ) && ( rulewd > 0 ) ) 
    {
      if ( curh != dvih ) 
      {
	movement ( curh - dvih , 143 ) ;
	dvih = curh ;
      } 
      curv = baseline + ruledp ;
      if ( curv != dviv ) 
      {
	movement ( curv - dviv , 157 ) ;
	dviv = curv ;
      } 
      {
	dvibuf [dviptr ]= 132 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( ruleht ) ;
      dvifour ( rulewd ) ;
      curv = baseline ;
      dvih = dvih + rulewd ;
    } 
    lab13: {
	
      curh = curh + rulewd ;
      synctexhorizontalruleorglue ( p , thisbox ) ;
    } 
    lab15: prevp = p ;
    p = mem [p ].hh .v.RH ;
  } 
  synctextsilh ( thisbox ) ;
  if ( ( eTeXmode == 1 ) ) 
  {
    {
      while ( mem [LRptr ].hh .v.LH != 0 ) {
	  
	if ( mem [LRptr ].hh .v.LH > 4 ) 
	LRproblems = LRproblems + 10000 ;
	{
	  tempptr = LRptr ;
	  LRptr = mem [tempptr ].hh .v.RH ;
	  {
	    mem [tempptr ].hh .v.RH = avail ;
	    avail = tempptr ;
	;
#ifdef STAT
	    decr ( dynused ) ;
#endif /* STAT */
	  } 
	} 
      } 
      {
	tempptr = LRptr ;
	LRptr = mem [tempptr ].hh .v.RH ;
	{
	  mem [tempptr ].hh .v.RH = avail ;
	  avail = tempptr ;
	;
#ifdef STAT
	  decr ( dynused ) ;
#endif /* STAT */
	} 
      } 
    } 
    if ( ( ( mem [thisbox ].hh.b1 ) / 8 ) == 2 ) 
    curdir = 1 ;
  } 
  prunemovements ( saveloc ) ;
  if ( curs > 0 ) 
  dvipop ( saveloc ) ;
  decr ( curs ) ;
} 
void 
vlistout ( void ) 
{
  /* 13 14 15 */ vlistout_regmem 
  scaled leftedge  ;
  scaled topedge  ;
  scaled saveh, savev  ;
  halfword thisbox  ;
  glueord gorder  ;
  unsigned char gsign  ;
  halfword p  ;
  integer saveloc  ;
  halfword leaderbox  ;
  scaled leaderht  ;
  scaled lx  ;
  boolean outerdoingleaders  ;
  scaled edge  ;
  real gluetemp  ;
  real curglue  ;
  scaled curg  ;
  integer savedir  ;
  curg = 0 ;
  curglue = 0.0 ;
  thisbox = tempptr ;
  gorder = mem [thisbox + 5 ].hh.b1 ;
  gsign = mem [thisbox + 5 ].hh.b0 ;
  p = mem [thisbox + 5 ].hh .v.RH ;
  incr ( curs ) ;
  if ( curs > 0 ) 
  {
    dvibuf [dviptr ]= 141 ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  if ( curs > maxpush ) 
  maxpush = curs ;
  saveloc = dvioffset + dviptr ;
  synchdir () ;
  leftedge = curh ;
  synctexvlist ( thisbox ) ;
  curv = curv - mem [thisbox + 3 ].cint ;
  topedge = curv ;
  while ( p != -1073741823L ) {
      
    if ( ( p >= himemmin ) ) 
    confusion ( 927 ) ;
    else {
	
      switch ( mem [p ].hh.b0 ) 
      {case 0 : 
      case 1 : 
      case 2 : 
	if ( mem [p + 5 ].hh .v.RH == -1073741823L ) 
	{
	  curv = curv + mem [p + 3 ].cint ;
	  if ( mem [p ].hh.b0 != 2 ) {
	      
	    if ( mem [p ].hh.b0 == 1 ) 
	    {
	      synctexvoidvlist ( p , thisbox ) ;
	    } 
	    else {
		
	      synctexvoidhlist ( p , thisbox ) ;
	    } 
	  } 
	  curv = curv + mem [p + 2 ].cint ;
	} 
	else {
	    
	  curv = curv + mem [p + 3 ].cint ;
	  if ( curv != dviv ) 
	  {
	    movement ( curv - dviv , 157 ) ;
	    dviv = curv ;
	  } 
	  saveh = dvih ;
	  savev = dviv ;
	  savedir = dvidir ;
	  if ( curdir == 1 ) 
	  curh = leftedge - mem [p + 4 ].cint ;
	  else curh = leftedge + mem [p + 4 ].cint ;
	  tempptr = p ;
	  switch ( mem [p ].hh.b0 ) 
	  {case 0 : 
	    hlistout () ;
	    break ;
	  case 1 : 
	    vlistout () ;
	    break ;
	  case 2 : 
	    dirout () ;
	    break ;
	  } 
	  dvih = saveh ;
	  dviv = savev ;
	  dvidir = savedir ;
	  curv = savev + mem [p + 2 ].cint ;
	  curh = leftedge ;
	  curdirhv = savedir ;
	} 
	break ;
      case 3 : 
	{
	  ruleht = mem [p + 3 ].cint ;
	  ruledp = mem [p + 2 ].cint ;
	  rulewd = mem [p + 1 ].cint ;
	  goto lab14 ;
	} 
	break ;
      case 10 : 
	outwhat ( p ) ;
	break ;
      case 12 : 
	{
	  g = mem [p + 1 ].hh .v.LH ;
	  ruleht = mem [g + 1 ].cint - curg ;
	  if ( gsign != 0 ) 
	  {
	    if ( gsign == 1 ) 
	    {
	      if ( mem [g ].hh.b0 == gorder ) 
	      {
		curglue = curglue + mem [g + 2 ].cint ;
		gluetemp = mem [thisbox + 6 ].gr * curglue ;
		if ( gluetemp > 1000000000.0 ) 
		gluetemp = 1000000000.0 ;
		else if ( gluetemp < -1000000000.0 ) 
		gluetemp = -1000000000.0 ;
		curg = round ( gluetemp ) ;
	      } 
	    } 
	    else if ( mem [g ].hh.b1 == gorder ) 
	    {
	      curglue = curglue - mem [g + 3 ].cint ;
	      gluetemp = mem [thisbox + 6 ].gr * curglue ;
	      if ( gluetemp > 1000000000.0 ) 
	      gluetemp = 1000000000.0 ;
	      else if ( gluetemp < -1000000000.0 ) 
	      gluetemp = -1000000000.0 ;
	      curg = round ( gluetemp ) ;
	    } 
	  } 
	  ruleht = ruleht + curg ;
	  if ( mem [p ].hh.b1 >= 100 ) 
	  {
	    leaderbox = mem [p + 1 ].hh .v.RH ;
	    if ( mem [leaderbox ].hh.b0 == 3 ) 
	    {
	      rulewd = mem [leaderbox + 1 ].cint ;
	      ruledp = 0 ;
	      goto lab14 ;
	    } 
	    leaderht = mem [leaderbox + 3 ].cint + mem [leaderbox + 2 ]
	    .cint ;
	    if ( ( leaderht > 0 ) && ( ruleht > 0 ) ) 
	    {
	      ruleht = ruleht + 10 ;
	      edge = curv + ruleht ;
	      lx = 0 ;
	      if ( mem [p ].hh.b1 == 100 ) 
	      {
		savev = curv ;
		curv = topedge + leaderht * ( ( curv - topedge ) / leaderht ) 
		;
		if ( curv < savev ) 
		curv = curv + leaderht ;
	      } 
	      else {
		  
		lq = ruleht / leaderht ;
		lr = ruleht % leaderht ;
		if ( mem [p ].hh.b1 == 101 ) 
		curv = curv + ( lr / 2 ) ;
		else {
		    
		  lx = lr / ( lq + 1 ) ;
		  curv = curv + ( ( lr - ( lq - 1 ) * lx ) / 2 ) ;
		} 
	      } 
	      while ( curv + leaderht <= edge ) {
		  
		if ( curdir == 1 ) 
		curh = leftedge - mem [leaderbox + 4 ].cint ;
		else curh = leftedge + mem [leaderbox + 4 ].cint ;
		if ( curh != dvih ) 
		{
		  movement ( curh - dvih , 143 ) ;
		  dvih = curh ;
		} 
		saveh = dvih ;
		curv = curv + mem [leaderbox + 3 ].cint ;
		if ( curv != dviv ) 
		{
		  movement ( curv - dviv , 157 ) ;
		  dviv = curv ;
		} 
		savev = dviv ;
		savedir = dvidir ;
		tempptr = leaderbox ;
		outerdoingleaders = doingleaders ;
		doingleaders = true ;
		switch ( mem [leaderbox ].hh.b0 ) 
		{case 0 : 
		  hlistout () ;
		  break ;
		case 1 : 
		  vlistout () ;
		  break ;
		case 2 : 
		  dirout () ;
		  break ;
		} 
		doingleaders = outerdoingleaders ;
		dviv = savev ;
		dvih = saveh ;
		dvidir = savedir ;
		curh = leftedge ;
		curv = savev - mem [leaderbox + 3 ].cint + leaderht + lx ;
		curdirhv = savedir ;
	      } 
	      curv = edge - 10 ;
	      goto lab15 ;
	    } 
	  } 
	  goto lab13 ;
	} 
	break ;
      case 13 : 
	curv = curv + mem [p + 1 ].cint ;
	break ;
	default: 
	;
	break ;
      } 
      goto lab15 ;
      lab14: if ( ( rulewd == -1073741824L ) ) 
      rulewd = mem [thisbox + 1 ].cint ;
      ruleht = ruleht + ruledp ;
      curv = curv + ruleht ;
      if ( ( ruleht > 0 ) && ( rulewd > 0 ) ) 
      {
	if ( curdir == 1 ) 
	curh = curh - rulewd ;
	if ( curh != dvih ) 
	{
	  movement ( curh - dvih , 143 ) ;
	  dvih = curh ;
	} 
	if ( curv != dviv ) 
	{
	  movement ( curv - dviv , 157 ) ;
	  dviv = curv ;
	} 
	{
	  dvibuf [dviptr ]= 137 ;
	  incr ( dviptr ) ;
	  if ( dviptr == dvilimit ) 
	  dviswap () ;
	} 
	dvifour ( ruleht ) ;
	dvifour ( rulewd ) ;
	curh = leftedge ;
      } 
      goto lab15 ;
      lab13: curv = curv + ruleht ;
    } 
    lab15: p = mem [p ].hh .v.RH ;
  } 
  synctextsilv ( thisbox ) ;
  prunemovements ( saveloc ) ;
  if ( curs > 0 ) 
  dvipop ( saveloc ) ;
  decr ( curs ) ;
} 
void 
zshipout ( halfword p ) 
{
  /* 30 */ shipout_regmem 
  integer pageloc  ;
  halfword delnode  ;
  unsigned char j, k  ;
  poolpointer s  ;
  unsigned char oldsetting  ;
  scaled t  ;
  synctexsheet ( eqtb [29205 ].cint ) ;
  {
    if ( eqtb [29222 ].cint > 0 ) 
    {
      printnl ( 344 ) ;
      println () ;
      print ( 928 ) ;
    } 
    if ( termoffset > maxprintline - 9 ) 
    println () ;
    else if ( ( termoffset > 0 ) || ( fileoffset > 0 ) ) 
    printchar ( 32 ) ;
    printchar ( 91 ) ;
    j = 9 ;
    while ( ( eqtb [29262 + j ].cint == 0 ) && ( j > 0 ) ) decr ( j ) ;
    {register integer for_end; k = 0 ;for_end = j ; if ( k <= for_end) do 
      {
	printint ( eqtb [29262 + k ].cint ) ;
	if ( k < j ) 
	printchar ( 46 ) ;
      } 
    while ( k++ < for_end ) ;} 
    fflush ( stdout ) ;
    if ( eqtb [29222 ].cint > 0 ) 
    {
      printchar ( 93 ) ;
      begindiagnostic () ;
      showbox ( p ) ;
      enddiagnostic ( true ) ;
    } 
    if ( mem [p ].hh.b0 == 2 ) 
    {
      delnode = p ;
      p = mem [p + 5 ].hh .v.RH ;
      deleteglueref ( mem [delnode + 7 ].hh .v.RH ) ;
      deleteglueref ( mem [delnode + 7 ].hh .v.LH ) ;
      freenode ( delnode , 10 ) ;
    } 
    flushnodelist ( mem [p ].hh .v.RH ) ;
    mem [p ].hh .v.RH = -1073741823L ;
    if ( ( ( mem [p ].hh.b1 ) % 8 ) != 4 ) 
    p = newdirnode ( p , 4 ) ;
    if ( ( mem [p + 3 ].cint > 1073741823L ) || ( mem [p + 2 ].cint > 
    1073741823L ) || ( mem [p + 3 ].cint + mem [p + 2 ].cint + eqtb [
    29793 ].cint > 1073741823L ) || ( mem [p + 1 ].cint + eqtb [29792 ]
    .cint > 1073741823L ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 932 ) ;
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 933 ;
	helpline [0 ]= 934 ;
      } 
      error () ;
      if ( eqtb [29222 ].cint <= 0 ) 
      {
	begindiagnostic () ;
	printnl ( 935 ) ;
	showbox ( p ) ;
	enddiagnostic ( true ) ;
      } 
      goto lab30 ;
    } 
    if ( mem [p + 3 ].cint + mem [p + 2 ].cint + eqtb [29793 ].cint > 
    maxv ) 
    maxv = mem [p + 3 ].cint + mem [p + 2 ].cint + eqtb [29793 ].cint ;
    if ( mem [p + 1 ].cint + eqtb [29792 ].cint > maxh ) 
    maxh = mem [p + 1 ].cint + eqtb [29792 ].cint ;
    if ( eqtb [29798 ].cint != 0 ) 
    curpageheight = eqtb [29798 ].cint ;
    else if ( ( mem [p ].hh.b0 == 2 ) ) 
    {
      if ( ( ( ( mem [mem [p + 5 ].hh .v.RH ].hh.b1 ) % 8 ) == 3 ) || ( ( 
      ( mem [mem [p + 5 ].hh .v.RH ].hh.b1 ) % 8 ) == 1 ) ) 
      curpageheight = mem [p + 1 ].cint + 2 * eqtb [29793 ].cint + 2 * 
      4736286L ;
      else curpageheight = mem [p + 3 ].cint + mem [p + 2 ].cint + 2 * 
      eqtb [29793 ].cint + 2 * 4736286L ;
    } 
    else curpageheight = mem [p + 3 ].cint + mem [p + 2 ].cint + 2 * eqtb 
    [29793 ].cint + 2 * 4736286L ;
    if ( eqtb [29797 ].cint != 0 ) 
    curpagewidth = eqtb [29797 ].cint ;
    else if ( ( mem [p ].hh.b0 == 2 ) ) 
    {
      if ( ( ( ( mem [mem [p + 5 ].hh .v.RH ].hh.b1 ) % 8 ) == 3 ) || ( ( 
      ( mem [mem [p + 5 ].hh .v.RH ].hh.b1 ) % 8 ) == 1 ) ) 
      curpagewidth = mem [p + 3 ].cint + mem [p + 2 ].cint + 2 * eqtb [
      29792 ].cint + 2 * 4736286L ;
      else curpagewidth = mem [p + 1 ].cint + 2 * eqtb [29792 ].cint + 2 * 
      4736286L ;
    } 
    else curpagewidth = mem [p + 1 ].cint + 2 * eqtb [29792 ].cint + 2 * 
    4736286L ;
    dvih = 0 ;
    dviv = 0 ;
    curh = eqtb [29792 ].cint ;
    dvif = 0 ;
    dvidir = 4 ;
    curdirhv = dvidir ;
    if ( outputfilename == 0 ) 
    {
      if ( jobname == 0 ) 
      openlogfile () ;
      packjobname ( 891 ) ;
      while ( ! bopenout ( dvifile ) ) promptfilename ( 892 , 891 ) ;
      outputfilename = bmakenamestring ( dvifile ) ;
    } 
    if ( totalpages == 0 ) 
    {
      {
	dvibuf [dviptr ]= 247 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      {
	dvibuf [dviptr ]= 2 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( 25400000L ) ;
      dvifour ( 473628672L ) ;
      preparemag () ;
      dvifour ( eqtb [29205 ].cint ) ;
      if ( outputcomment ) 
      {
	l = strlen ( outputcomment ) ;
	{
	  dvibuf [dviptr ]= l ;
	  incr ( dviptr ) ;
	  if ( dviptr == dvilimit ) 
	  dviswap () ;
	} 
	{register integer for_end; s = 0 ;for_end = l - 1 ; if ( s <= 
	for_end) do 
	  {
	    dvibuf [dviptr ]= outputcomment [s ];
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	while ( s++ < for_end ) ;} 
      } 
      else {
	  
	oldsetting = selector ;
	selector = 21 ;
	print ( 926 ) ;
	printint ( eqtb [29211 ].cint ) ;
	printchar ( 46 ) ;
	printtwo ( eqtb [29210 ].cint ) ;
	printchar ( 46 ) ;
	printtwo ( eqtb [29209 ].cint ) ;
	printchar ( 58 ) ;
	printtwo ( eqtb [29208 ].cint / 60 ) ;
	printtwo ( eqtb [29208 ].cint % 60 ) ;
	selector = oldsetting ;
	{
	  dvibuf [dviptr ]= ( poolptr - strstart [strptr ]) ;
	  incr ( dviptr ) ;
	  if ( dviptr == dvilimit ) 
	  dviswap () ;
	} 
	{register integer for_end; s = strstart [strptr ];for_end = 
	poolptr - 1 ; if ( s <= for_end) do 
	  {
	    dvibuf [dviptr ]= strpool [s ];
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	while ( s++ < for_end ) ;} 
	poolptr = strstart [strptr ];
      } 
    } 
    pageloc = dvioffset + dviptr ;
    {
      dvibuf [dviptr ]= 139 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    {register integer for_end; k = 0 ;for_end = 9 ; if ( k <= for_end) do 
      dvifour ( eqtb [29262 + k ].cint ) ;
    while ( k++ < for_end ) ;} 
    dvifour ( lastbop ) ;
    lastbop = pageloc ;
    curv = mem [p + 3 ].cint + eqtb [29793 ].cint ;
    tempptr = p ;
    switch ( mem [p ].hh.b0 ) 
    {case 0 : 
      hlistout () ;
      break ;
    case 1 : 
      vlistout () ;
      break ;
    case 2 : 
      dirout () ;
      break ;
    } 
    {
      dvibuf [dviptr ]= 140 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    incr ( totalpages ) ;
    curs = -1 ;
	;
#ifdef IPC
    if ( ipcon > 0 ) 
    {
      if ( dvilimit == halfbuf ) 
      {
	writedvi ( halfbuf , dvibufsize - 1 ) ;
	flushdvi () ;
	dvigone = dvigone + halfbuf ;
      } 
      if ( dviptr > ( 2147483647L - dvioffset ) ) 
      {
	curs = -2 ;
	fatalerror ( 925 ) ;
      } 
      if ( dviptr > 0 ) 
      {
	writedvi ( 0 , dviptr - 1 ) ;
	flushdvi () ;
	dvioffset = dvioffset + dviptr ;
	dvigone = dvigone + dviptr ;
      } 
      dviptr = 0 ;
      dvilimit = dvibufsize ;
      ipcpage ( dvigone ) ;
    } 
#endif /* IPC */
    lab30: ;
    if ( ( eTeXmode == 1 ) ) 
    {
      if ( LRproblems > 0 ) 
      {
	{
	  println () ;
	  printnl ( 1519 ) ;
	  printint ( LRproblems / 10000 ) ;
	  print ( 1520 ) ;
	  printint ( LRproblems % 10000 ) ;
	  print ( 1521 ) ;
	  LRproblems = 0 ;
	} 
	printchar ( 41 ) ;
	println () ;
      } 
      if ( ( LRptr != -1073741823L ) || ( curdir != 0 ) ) 
      confusion ( 1523 ) ;
    } 
    if ( eqtb [29222 ].cint <= 0 ) 
    printchar ( 93 ) ;
    deadcycles = 0 ;
    fflush ( stdout ) ;
	;
#ifdef STAT
    if ( eqtb [29219 ].cint > 1 ) 
    {
      printnl ( 929 ) ;
      printint ( varused ) ;
      printchar ( 38 ) ;
      printint ( dynused ) ;
      printchar ( 59 ) ;
    } 
#endif /* STAT */
    flushnodelist ( p ) ;
	;
#ifdef STAT
    if ( eqtb [29219 ].cint > 1 ) 
    {
      print ( 930 ) ;
      printint ( varused ) ;
      printchar ( 38 ) ;
      printint ( dynused ) ;
      print ( 931 ) ;
      printint ( himemmin - lomemmax - 1 ) ;
      println () ;
    } 
#endif /* STAT */
  } 
  synctexteehs () ;
} 
void 
zscanspec ( groupcode c , boolean threecodes ) 
{
  /* 40 */ scanspec_regmem 
  integer s  ;
  unsigned char speccode  ;
  if ( threecodes ) 
  s = savestack [saveptr + 0 ].cint ;
  if ( scankeyword ( 941 ) ) 
  speccode = 0 ;
  else if ( scankeyword ( 942 ) ) 
  speccode = 1 ;
  else {
      
    speccode = 1 ;
    curval = 0 ;
    goto lab40 ;
  } 
  scandimen ( false , false , false ) ;
  lab40: if ( threecodes ) 
  {
    savestack [saveptr + 0 ].cint = s ;
    incr ( saveptr ) ;
  } 
  savestack [saveptr + 0 ].cint = speccode ;
  savestack [saveptr + 1 ].cint = curval ;
  saveptr = saveptr + 2 ;
  newsavelevel ( c ) ;
  scanleftbrace () ;
} 
halfword 
zhpack ( halfword p , scaled w , smallnumber m ) 
{
  /* 21 50 10 */ register halfword Result; hpack_regmem 
  halfword r  ;
  halfword k  ;
  scaled disp  ;
  halfword q  ;
  scaled h, d, x  ;
  scaled s  ;
  halfword g  ;
  glueord o  ;
  internalfontnumber f  ;
  fourquarters i  ;
  eightbits hd  ;
  lastbadness = 0 ;
  r = getnode ( 10 ) ;
  mem [r ].hh.b0 = 0 ;
  mem [r ].hh.b1 = 0 ;
  mem [r + 4 ].cint = 0 ;
  mem [r + 7 ].hh .v.RH = curkanjiskip ;
  mem [r + 7 ].hh .v.LH = curxkanjiskip ;
  incr ( mem [curkanjiskip ].hh .v.RH ) ;
  incr ( mem [curxkanjiskip ].hh .v.RH ) ;
  k = curkanjiskip ;
  q = r + 5 ;
  mem [q ].hh .v.RH = p ;
  h = 0 ;
  d = 0 ;
  x = 0 ;
  totalstretch [0 ]= 0 ;
  totalshrink [0 ]= 0 ;
  totalstretch [1 ]= 0 ;
  totalshrink [1 ]= 0 ;
  totalstretch [2 ]= 0 ;
  totalshrink [2 ]= 0 ;
  totalstretch [3 ]= 0 ;
  totalshrink [3 ]= 0 ;
  totalstretch [4 ]= 0 ;
  totalshrink [4 ]= 0 ;
  disp = 0 ;
  if ( ( eqtb [29261 ].cint > 0 ) ) 
  {
    tempptr = getavail () ;
    mem [tempptr ].hh .v.LH = 0 ;
    mem [tempptr ].hh .v.RH = LRptr ;
    LRptr = tempptr ;
  } 
  while ( p != -1073741823L ) {
      
    lab21: chain = false ;
    while ( ( p >= himemmin ) ) {
	
      f = mem [p ].hh.b0 ;
      i = fontinfo [charbase [f ]+ effectivechar ( true , f , mem [p ]
      .hh.b1 ) ].qqqq ;
      hd = i .b1 ;
      x = x + fontinfo [widthbase [f ]+ i .b0 ].cint ;
      s = fontinfo [heightbase [f ]+ ( hd ) / 16 ].cint - disp ;
      if ( s > h ) 
      h = s ;
      s = fontinfo [depthbase [f ]+ ( hd ) % 16 ].cint + disp ;
      if ( s > d ) 
      d = s ;
      if ( fontdir [f ]!= 0 ) 
      {
	p = mem [p ].hh .v.RH ;
	if ( chain ) 
	{
	  x = x + mem [k + 1 ].cint ;
	  o = mem [k ].hh.b0 ;
	  totalstretch [o ]= totalstretch [o ]+ mem [k + 2 ].cint ;
	  o = mem [k ].hh.b1 ;
	  totalshrink [o ]= totalshrink [o ]+ mem [k + 3 ].cint ;
	} 
	else chain = true ;
      } 
      else chain = false ;
      p = mem [p ].hh .v.RH ;
    } 
    if ( p != -1073741823L ) 
    {
      switch ( mem [p ].hh.b0 ) 
      {case 0 : 
      case 1 : 
      case 2 : 
      case 3 : 
      case 15 : 
	{
	  x = x + mem [p + 1 ].cint ;
	  if ( mem [p ].hh.b0 >= 3 ) 
	  s = disp ;
	  else s = mem [p + 4 ].cint + disp ;
	  if ( mem [p + 3 ].cint - s > h ) 
	  h = mem [p + 3 ].cint - s ;
	  if ( mem [p + 2 ].cint + s > d ) 
	  d = mem [p + 2 ].cint + s ;
	} 
	break ;
      case 4 : 
      case 6 : 
      case 7 : 
	if ( adjusttail != -1073741823L ) 
	{
	  while ( mem [q ].hh .v.RH != p ) q = mem [q ].hh .v.RH ;
	  if ( mem [p ].hh.b0 == 7 ) 
	  {
	    mem [adjusttail ].hh .v.RH = mem [p + 1 ].cint ;
	    while ( mem [adjusttail ].hh .v.RH != -1073741823L ) adjusttail 
	    = mem [adjusttail ].hh .v.RH ;
	    p = mem [p ].hh .v.RH ;
	    freenode ( mem [q ].hh .v.RH , 2 ) ;
	  } 
	  else {
	      
	    mem [adjusttail ].hh .v.RH = p ;
	    adjusttail = p ;
	    p = mem [p ].hh .v.RH ;
	  } 
	  mem [q ].hh .v.RH = p ;
	  p = q ;
	} 
	break ;
      case 10 : 
	;
	break ;
      case 5 : 
	{
	  disp = mem [p + 1 ].cint ;
	  revdisp = disp ;
	} 
	break ;
      case 12 : 
	{
	  g = mem [p + 1 ].hh .v.LH ;
	  x = x + mem [g + 1 ].cint ;
	  o = mem [g ].hh.b0 ;
	  totalstretch [o ]= totalstretch [o ]+ mem [g + 2 ].cint ;
	  o = mem [g ].hh.b1 ;
	  totalshrink [o ]= totalshrink [o ]+ mem [g + 3 ].cint ;
	  if ( mem [p ].hh.b1 >= 100 ) 
	  {
	    g = mem [p + 1 ].hh .v.RH ;
	    if ( mem [g + 3 ].cint > h ) 
	    h = mem [g + 3 ].cint ;
	    if ( mem [g + 2 ].cint > d ) 
	    d = mem [g + 2 ].cint ;
	  } 
	} 
	break ;
      case 13 : 
	x = x + mem [p + 1 ].cint ;
	break ;
      case 11 : 
	{
	  x = x + mem [p + 1 ].cint ;
	  if ( ( eqtb [29261 ].cint > 0 ) ) {
	      
	    if ( odd ( mem [p ].hh.b1 ) ) {
		
	      if ( mem [LRptr ].hh .v.LH == ( 4 * ( mem [p ].hh.b1 / 4 ) + 
	      3 ) ) 
	      {
		tempptr = LRptr ;
		LRptr = mem [tempptr ].hh .v.RH ;
		{
		  mem [tempptr ].hh .v.RH = avail ;
		  avail = tempptr ;
	;
#ifdef STAT
		  decr ( dynused ) ;
#endif /* STAT */
		} 
	      } 
	      else {
		  
		incr ( LRproblems ) ;
		mem [p ].hh.b0 = 13 ;
		mem [p ].hh.b1 = 1 ;
	      } 
	    } 
	    else {
		
	      tempptr = getavail () ;
	      mem [tempptr ].hh .v.LH = ( 4 * ( mem [p ].hh.b1 / 4 ) + 3 ) 
	      ;
	      mem [tempptr ].hh .v.RH = LRptr ;
	      LRptr = tempptr ;
	    } 
	  } 
	} 
	break ;
      case 8 : 
	{
	  mem [memtop - 12 ]= mem [p + 1 ];
	  mem [memtop - 12 ].hh .v.RH = mem [p ].hh .v.RH ;
	  p = memtop - 12 ;
	  goto lab21 ;
	} 
	break ;
	default: 
	;
	break ;
      } 
      p = mem [p ].hh .v.RH ;
    } 
  } 
  if ( adjusttail != -1073741823L ) 
  mem [adjusttail ].hh .v.RH = -1073741823L ;
  mem [r + 3 ].cint = h ;
  mem [r + 2 ].cint = d ;
  if ( m == 1 ) 
  w = x + w ;
  mem [r + 1 ].cint = w ;
  x = w - x ;
  if ( x == 0 ) 
  {
    mem [r + 5 ].hh.b0 = 0 ;
    mem [r + 5 ].hh.b1 = 0 ;
    mem [r + 6 ].gr = 0.0 ;
    goto lab10 ;
  } 
  else if ( x > 0 ) 
  {
    if ( totalstretch [4 ]!= 0 ) 
    o = 4 ;
    else if ( totalstretch [3 ]!= 0 ) 
    o = 3 ;
    else if ( totalstretch [2 ]!= 0 ) 
    o = 2 ;
    else if ( totalstretch [1 ]!= 0 ) 
    o = 1 ;
    else o = 0 ;
    mem [r + 5 ].hh.b1 = o ;
    mem [r + 5 ].hh.b0 = 1 ;
    if ( totalstretch [o ]!= 0 ) 
    mem [r + 6 ].gr = x / ((double) totalstretch [o ]) ;
    else {
	
      mem [r + 5 ].hh.b0 = 0 ;
      mem [r + 6 ].gr = 0.0 ;
    } 
    if ( o == 0 ) {
	
      if ( mem [r + 5 ].hh .v.RH != -1073741823L ) 
      {
	lastbadness = badness ( x , totalstretch [0 ]) ;
	if ( lastbadness > eqtb [29214 ].cint ) 
	{
	  println () ;
	  if ( lastbadness > 100 ) 
	  printnl ( 943 ) ;
	  else printnl ( 944 ) ;
	  print ( 945 ) ;
	  printint ( lastbadness ) ;
	  goto lab50 ;
	} 
      } 
    } 
    goto lab10 ;
  } 
  else {
      
    if ( totalshrink [4 ]!= 0 ) 
    o = 4 ;
    else if ( totalshrink [3 ]!= 0 ) 
    o = 3 ;
    else if ( totalshrink [2 ]!= 0 ) 
    o = 2 ;
    else if ( totalshrink [1 ]!= 0 ) 
    o = 1 ;
    else o = 0 ;
    mem [r + 5 ].hh.b1 = o ;
    mem [r + 5 ].hh.b0 = 2 ;
    if ( totalshrink [o ]!= 0 ) 
    mem [r + 6 ].gr = ( - (integer) x ) / ((double) totalshrink [o ]) ;
    else {
	
      mem [r + 5 ].hh.b0 = 0 ;
      mem [r + 6 ].gr = 0.0 ;
    } 
    if ( ( totalshrink [o ]< - (integer) x ) && ( o == 0 ) && ( mem [r + 5 
    ].hh .v.RH != -1073741823L ) ) 
    {
      lastbadness = 1000000L ;
      mem [r + 6 ].gr = 1.0 ;
      if ( ( - (integer) x - totalshrink [0 ]> eqtb [29782 ].cint ) || ( 
      eqtb [29214 ].cint < 100 ) ) 
      {
	if ( ( eqtb [29790 ].cint > 0 ) && ( - (integer) x - totalshrink [0 
	]> eqtb [29782 ].cint ) ) 
	{
	  while ( mem [q ].hh .v.RH != -1073741823L ) q = mem [q ].hh 
	  .v.RH ;
	  mem [q ].hh .v.RH = newrule () ;
	  mem [mem [q ].hh .v.RH + 1 ].cint = eqtb [29790 ].cint ;
	} 
	println () ;
	printnl ( 951 ) ;
	printscaled ( - (integer) x - totalshrink [0 ]) ;
	print ( 952 ) ;
	goto lab50 ;
      } 
    } 
    else if ( o == 0 ) {
	
      if ( mem [r + 5 ].hh .v.RH != -1073741823L ) 
      {
	lastbadness = badness ( - (integer) x , totalshrink [0 ]) ;
	if ( lastbadness > eqtb [29214 ].cint ) 
	{
	  println () ;
	  printnl ( 953 ) ;
	  printint ( lastbadness ) ;
	  goto lab50 ;
	} 
      } 
    } 
    goto lab10 ;
  } 
  lab50: if ( outputactive ) 
  print ( 946 ) ;
  else {
      
    if ( packbeginline != 0 ) 
    {
      if ( packbeginline > 0 ) 
      print ( 947 ) ;
      else print ( 948 ) ;
      printint ( abs ( packbeginline ) ) ;
      print ( 949 ) ;
    } 
    else print ( 950 ) ;
    printint ( line ) ;
  } 
  println () ;
  fontinshortdisplay = 0 ;
  shortdisplay ( mem [r + 5 ].hh .v.RH ) ;
  println () ;
  begindiagnostic () ;
  showbox ( r ) ;
  enddiagnostic ( true ) ;
  lab10: lastdisp = disp ;
  if ( ( eqtb [29261 ].cint > 0 ) ) 
  {
    if ( mem [LRptr ].hh .v.LH != 0 ) 
    {
      while ( mem [q ].hh .v.RH != -1073741823L ) q = mem [q ].hh .v.RH ;
      do {
	  tempptr = q ;
	q = newmath ( 0 , mem [LRptr ].hh .v.LH ) ;
	mem [tempptr ].hh .v.RH = q ;
	LRproblems = LRproblems + 10000 ;
	{
	  tempptr = LRptr ;
	  LRptr = mem [tempptr ].hh .v.RH ;
	  {
	    mem [tempptr ].hh .v.RH = avail ;
	    avail = tempptr ;
	;
#ifdef STAT
	    decr ( dynused ) ;
#endif /* STAT */
	  } 
	} 
      } while ( ! ( mem [LRptr ].hh .v.LH == 0 ) ) ;
    } 
    if ( LRproblems > 0 ) 
    {
      {
	println () ;
	printnl ( 1519 ) ;
	printint ( LRproblems / 10000 ) ;
	print ( 1520 ) ;
	printint ( LRproblems % 10000 ) ;
	print ( 1521 ) ;
	LRproblems = 0 ;
      } 
      goto lab50 ;
    } 
    {
      tempptr = LRptr ;
      LRptr = mem [tempptr ].hh .v.RH ;
      {
	mem [tempptr ].hh .v.RH = avail ;
	avail = tempptr ;
	;
#ifdef STAT
	decr ( dynused ) ;
#endif /* STAT */
      } 
    } 
    if ( LRptr != -1073741823L ) 
    confusion ( 1518 ) ;
  } 
  Result = r ;
  return Result ;
} 
halfword 
zvpackage ( halfword p , scaled h , smallnumber m , scaled l ) 
{
  /* 50 10 */ register halfword Result; vpackage_regmem 
  halfword r  ;
  scaled w, d, x  ;
  scaled s  ;
  halfword g  ;
  glueord o  ;
  lastbadness = 0 ;
  r = getnode ( 10 ) ;
  mem [r ].hh.b0 = 1 ;
  mem [r ].hh.b1 = 0 ;
  mem [r + 4 ].cint = 0 ;
  mem [r + 7 ].hh .v.RH = membot ;
  mem [r + 7 ].hh .v.LH = membot ;
  incr ( mem [membot ].hh .v.RH ) ;
  incr ( mem [membot ].hh .v.RH ) ;
  mem [r + 5 ].hh .v.RH = p ;
  w = 0 ;
  d = 0 ;
  x = 0 ;
  totalstretch [0 ]= 0 ;
  totalshrink [0 ]= 0 ;
  totalstretch [1 ]= 0 ;
  totalshrink [1 ]= 0 ;
  totalstretch [2 ]= 0 ;
  totalshrink [2 ]= 0 ;
  totalstretch [3 ]= 0 ;
  totalshrink [3 ]= 0 ;
  totalstretch [4 ]= 0 ;
  totalshrink [4 ]= 0 ;
  while ( p != -1073741823L ) {
      
    if ( ( p >= himemmin ) ) 
    confusion ( 954 ) ;
    else switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 2 : 
    case 3 : 
    case 15 : 
      {
	x = x + d + mem [p + 3 ].cint ;
	d = mem [p + 2 ].cint ;
	if ( mem [p ].hh.b0 >= 3 ) 
	s = 0 ;
	else s = mem [p + 4 ].cint ;
	if ( mem [p + 1 ].cint + s > w ) 
	w = mem [p + 1 ].cint + s ;
      } 
      break ;
    case 10 : 
      ;
      break ;
    case 12 : 
      {
	x = x + d ;
	d = 0 ;
	g = mem [p + 1 ].hh .v.LH ;
	x = x + mem [g + 1 ].cint ;
	o = mem [g ].hh.b0 ;
	totalstretch [o ]= totalstretch [o ]+ mem [g + 2 ].cint ;
	o = mem [g ].hh.b1 ;
	totalshrink [o ]= totalshrink [o ]+ mem [g + 3 ].cint ;
	if ( mem [p ].hh.b1 >= 100 ) 
	{
	  g = mem [p + 1 ].hh .v.RH ;
	  if ( mem [g + 1 ].cint > w ) 
	  w = mem [g + 1 ].cint ;
	} 
      } 
      break ;
    case 13 : 
      {
	x = x + d + mem [p + 1 ].cint ;
	d = 0 ;
      } 
      break ;
      default: 
      ;
      break ;
    } 
    p = mem [p ].hh .v.RH ;
  } 
  mem [r + 1 ].cint = w ;
  if ( d > l ) 
  {
    x = x + d - l ;
    mem [r + 2 ].cint = l ;
  } 
  else mem [r + 2 ].cint = d ;
  if ( m == 1 ) 
  h = x + h ;
  mem [r + 3 ].cint = h ;
  x = h - x ;
  if ( x == 0 ) 
  {
    mem [r + 5 ].hh.b0 = 0 ;
    mem [r + 5 ].hh.b1 = 0 ;
    mem [r + 6 ].gr = 0.0 ;
    goto lab10 ;
  } 
  else if ( x > 0 ) 
  {
    if ( totalstretch [4 ]!= 0 ) 
    o = 4 ;
    else if ( totalstretch [3 ]!= 0 ) 
    o = 3 ;
    else if ( totalstretch [2 ]!= 0 ) 
    o = 2 ;
    else if ( totalstretch [1 ]!= 0 ) 
    o = 1 ;
    else o = 0 ;
    mem [r + 5 ].hh.b1 = o ;
    mem [r + 5 ].hh.b0 = 1 ;
    if ( totalstretch [o ]!= 0 ) 
    mem [r + 6 ].gr = x / ((double) totalstretch [o ]) ;
    else {
	
      mem [r + 5 ].hh.b0 = 0 ;
      mem [r + 6 ].gr = 0.0 ;
    } 
    if ( o == 0 ) {
	
      if ( mem [r + 5 ].hh .v.RH != -1073741823L ) 
      {
	lastbadness = badness ( x , totalstretch [0 ]) ;
	if ( lastbadness > eqtb [29215 ].cint ) 
	{
	  println () ;
	  if ( lastbadness > 100 ) 
	  printnl ( 943 ) ;
	  else printnl ( 944 ) ;
	  print ( 955 ) ;
	  printint ( lastbadness ) ;
	  goto lab50 ;
	} 
      } 
    } 
    goto lab10 ;
  } 
  else {
      
    if ( totalshrink [4 ]!= 0 ) 
    o = 4 ;
    else if ( totalshrink [3 ]!= 0 ) 
    o = 3 ;
    else if ( totalshrink [2 ]!= 0 ) 
    o = 2 ;
    else if ( totalshrink [1 ]!= 0 ) 
    o = 1 ;
    else o = 0 ;
    mem [r + 5 ].hh.b1 = o ;
    mem [r + 5 ].hh.b0 = 2 ;
    if ( totalshrink [o ]!= 0 ) 
    mem [r + 6 ].gr = ( - (integer) x ) / ((double) totalshrink [o ]) ;
    else {
	
      mem [r + 5 ].hh.b0 = 0 ;
      mem [r + 6 ].gr = 0.0 ;
    } 
    if ( ( totalshrink [o ]< - (integer) x ) && ( o == 0 ) && ( mem [r + 5 
    ].hh .v.RH != -1073741823L ) ) 
    {
      lastbadness = 1000000L ;
      mem [r + 6 ].gr = 1.0 ;
      if ( ( - (integer) x - totalshrink [0 ]> eqtb [29783 ].cint ) || ( 
      eqtb [29215 ].cint < 100 ) ) 
      {
	println () ;
	printnl ( 956 ) ;
	printscaled ( - (integer) x - totalshrink [0 ]) ;
	print ( 957 ) ;
	goto lab50 ;
      } 
    } 
    else if ( o == 0 ) {
	
      if ( mem [r + 5 ].hh .v.RH != -1073741823L ) 
      {
	lastbadness = badness ( - (integer) x , totalshrink [0 ]) ;
	if ( lastbadness > eqtb [29215 ].cint ) 
	{
	  println () ;
	  printnl ( 958 ) ;
	  printint ( lastbadness ) ;
	  goto lab50 ;
	} 
      } 
    } 
    goto lab10 ;
  } 
  lab50: if ( outputactive ) 
  print ( 946 ) ;
  else {
      
    if ( packbeginline != 0 ) 
    {
      print ( 948 ) ;
      printint ( abs ( packbeginline ) ) ;
      print ( 949 ) ;
    } 
    else print ( 950 ) ;
    printint ( line ) ;
    println () ;
  } 
  begindiagnostic () ;
  showbox ( r ) ;
  enddiagnostic ( true ) ;
  lab10: Result = r ;
  return Result ;
} 
void 
zappendtovlist ( halfword b ) 
{
  appendtovlist_regmem 
  scaled d  ;
  halfword p  ;
  if ( curlist .auxfield .cint > -65536000L ) 
  {
    d = mem [eqtb [24529 ].hh .v.RH + 1 ].cint - curlist .auxfield .cint - 
    mem [b + 3 ].cint ;
    if ( d < eqtb [29776 ].cint ) 
    p = newparamglue ( 0 ) ;
    else {
	
      p = newskipparam ( 1 ) ;
      mem [tempptr + 1 ].cint = d ;
    } 
    mem [curlist .tailfield ].hh .v.RH = p ;
    curlist .tailfield = p ;
  } 
  mem [curlist .tailfield ].hh .v.RH = b ;
  curlist .tailfield = b ;
  curlist .auxfield .cint = mem [b + 2 ].cint ;
} 
halfword 
newnoad ( void ) 
{
  register halfword Result; newnoad_regmem 
  halfword p  ;
  p = getnode ( 5 ) ;
  mem [p ].hh.b0 = 18 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].hh = emptyfield ;
  mem [p + 3 ].hh = emptyfield ;
  mem [p + 2 ].hh = emptyfield ;
  mem [p + 4 ].hh = emptyfield ;
  Result = p ;
  return Result ;
} 
halfword 
znewstyle ( smallnumber s ) 
{
  register halfword Result; newstyle_regmem 
  halfword p  ;
  p = getnode ( 3 ) ;
  mem [p ].hh.b0 = 16 ;
  mem [p ].hh.b1 = s ;
  mem [p + 1 ].cint = 0 ;
  mem [p + 2 ].cint = 0 ;
  Result = p ;
  return Result ;
} 
halfword 
newchoice ( void ) 
{
  register halfword Result; newchoice_regmem 
  halfword p  ;
  p = getnode ( 3 ) ;
  mem [p ].hh.b0 = 17 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].hh .v.LH = -1073741823L ;
  mem [p + 1 ].hh .v.RH = -1073741823L ;
  mem [p + 2 ].hh .v.LH = -1073741823L ;
  mem [p + 2 ].hh .v.RH = -1073741823L ;
  Result = p ;
  return Result ;
} 
void 
showinfo ( void ) 
{
  showinfo_regmem 
  shownodelist ( mem [tempptr ].hh .v.LH ) ;
} 
halfword 
zfractionrule ( scaled t ) 
{
  register halfword Result; fractionrule_regmem 
  halfword p  ;
  p = newrule () ;
  mem [p + 3 ].cint = t ;
  mem [p + 2 ].cint = 0 ;
  Result = p ;
  return Result ;
} 
halfword 
zoverbar ( halfword b , scaled k , scaled t ) 
{
  register halfword Result; overbar_regmem 
  halfword p, q  ;
  p = newkern ( k ) ;
  mem [p ].hh .v.RH = b ;
  q = fractionrule ( t ) ;
  mem [q ].hh .v.RH = p ;
  p = newkern ( t ) ;
  mem [p ].hh .v.RH = q ;
  Result = vpackage ( p , 0 , 1 , 1073741823L ) ;
  return Result ;
} 
halfword 
zcharbox ( internalfontnumber f , quarterword c ) 
{
  register halfword Result; charbox_regmem 
  fourquarters q  ;
  eightbits hd  ;
  halfword b, p  ;
  q = fontinfo [charbase [f ]+ effectivechar ( true , f , c ) ].qqqq ;
  hd = q .b1 ;
  b = newnullbox () ;
  mem [b + 1 ].cint = fontinfo [widthbase [f ]+ q .b0 ].cint + fontinfo 
  [italicbase [f ]+ ( q .b2 ) / 4 ].cint ;
  mem [b + 3 ].cint = fontinfo [heightbase [f ]+ ( hd ) / 16 ].cint ;
  mem [b + 2 ].cint = fontinfo [depthbase [f ]+ ( hd ) % 16 ].cint ;
  p = getavail () ;
  mem [p ].hh.b1 = c ;
  mem [p ].hh.b0 = f ;
  mem [b + 5 ].hh .v.RH = p ;
  Result = b ;
  return Result ;
} 
void 
zstackintobox ( halfword b , internalfontnumber f , quarterword c ) 
{
  stackintobox_regmem 
  halfword p  ;
  p = charbox ( f , c ) ;
  mem [p ].hh .v.RH = mem [b + 5 ].hh .v.RH ;
  mem [b + 5 ].hh .v.RH = p ;
  mem [b + 3 ].cint = mem [p + 3 ].cint ;
} 
scaled 
zheightplusdepth ( internalfontnumber f , quarterword c ) 
{
  register scaled Result; heightplusdepth_regmem 
  fourquarters q  ;
  eightbits hd  ;
  q = fontinfo [charbase [f ]+ effectivechar ( true , f , c ) ].qqqq ;
  hd = q .b1 ;
  Result = fontinfo [heightbase [f ]+ ( hd ) / 16 ].cint + fontinfo [
  depthbase [f ]+ ( hd ) % 16 ].cint ;
  return Result ;
} 
halfword 
zvardelimiter ( halfword d , integer s , scaled v ) 
{
  /* 40 22 */ register halfword Result; vardelimiter_regmem 
  halfword b  ;
  internalfontnumber f, g  ;
  quarterword c, x, y  ;
  integer m, n  ;
  scaled u  ;
  scaled w  ;
  fourquarters q  ;
  eightbits hd  ;
  fourquarters r  ;
  integer z  ;
  boolean largeattempt  ;
  f = 0 ;
  w = 0 ;
  largeattempt = false ;
  z = mem [d ].qqqq .b0 ;
  x = mem [d ].qqqq .b1 ;
  while ( true ) {
      
    if ( ( z != 0 ) || ( x != 0 ) ) 
    {
      z = z + s + 256 ;
      do {
	  z = z - 256 ;
	g = eqtb [25589 + z ].hh .v.RH ;
	if ( g != 0 ) 
	{
	  y = x ;
	  if ( ( y >= fontbc [g ]) && ( y <= fontec [g ]) ) 
	  {
	    lab22: q = fontinfo [charbase [g ]+ y ].qqqq ;
	    if ( ( q .b0 > 0 ) ) 
	    {
	      if ( ( ( q .b2 ) % 4 ) == 3 ) 
	      {
		f = g ;
		c = y ;
		goto lab40 ;
	      } 
	      hd = q .b1 ;
	      u = fontinfo [heightbase [g ]+ ( hd ) / 16 ].cint + fontinfo 
	      [depthbase [g ]+ ( hd ) % 16 ].cint ;
	      if ( u > w ) 
	      {
		f = g ;
		c = y ;
		w = u ;
		if ( u >= v ) 
		goto lab40 ;
	      } 
	      if ( ( ( q .b2 ) % 4 ) == 2 ) 
	      {
		y = q .b3 ;
		goto lab22 ;
	      } 
	    } 
	  } 
	} 
      } while ( ! ( z < 256 ) ) ;
    } 
    if ( largeattempt ) 
    goto lab40 ;
    largeattempt = true ;
    z = mem [d ].qqqq .b2 ;
    x = mem [d ].qqqq .b3 ;
  } 
  lab40: if ( f != 0 ) {
      
    if ( ( ( q .b2 ) % 4 ) == 3 ) 
    {
      b = newnullbox () ;
      mem [b ].hh.b0 = 1 ;
      r = fontinfo [extenbase [f ]+ q .b3 ].qqqq ;
      c = r .b3 ;
      u = heightplusdepth ( f , c ) ;
      w = 0 ;
      q = fontinfo [charbase [f ]+ effectivechar ( true , f , c ) ].qqqq ;
      mem [b + 1 ].cint = fontinfo [widthbase [f ]+ q .b0 ].cint + 
      fontinfo [italicbase [f ]+ ( q .b2 ) / 4 ].cint ;
      c = r .b2 ;
      if ( c != 0 ) 
      w = w + heightplusdepth ( f , c ) ;
      c = r .b1 ;
      if ( c != 0 ) 
      w = w + heightplusdepth ( f , c ) ;
      c = r .b0 ;
      if ( c != 0 ) 
      w = w + heightplusdepth ( f , c ) ;
      n = 0 ;
      if ( u > 0 ) 
      while ( w < v ) {
	  
	w = w + u ;
	incr ( n ) ;
	if ( r .b1 != 0 ) 
	w = w + u ;
      } 
      c = r .b2 ;
      if ( c != 0 ) 
      stackintobox ( b , f , c ) ;
      c = r .b3 ;
      {register integer for_end; m = 1 ;for_end = n ; if ( m <= for_end) do 
	stackintobox ( b , f , c ) ;
      while ( m++ < for_end ) ;} 
      c = r .b1 ;
      if ( c != 0 ) 
      {
	stackintobox ( b , f , c ) ;
	c = r .b3 ;
	{register integer for_end; m = 1 ;for_end = n ; if ( m <= for_end) 
	do 
	  stackintobox ( b , f , c ) ;
	while ( m++ < for_end ) ;} 
      } 
      c = r .b0 ;
      if ( c != 0 ) 
      stackintobox ( b , f , c ) ;
      mem [b + 2 ].cint = w - mem [b + 3 ].cint ;
    } 
    else b = charbox ( f , c ) ;
  } 
  else {
      
    b = newnullbox () ;
    mem [b + 1 ].cint = eqtb [29785 ].cint ;
  } 
  mem [b + 4 ].cint = half ( mem [b + 3 ].cint - mem [b + 2 ].cint ) - 
  fontinfo [22 + parambase [eqtb [25591 + s ].hh .v.RH ]].cint ;
  Result = b ;
  return Result ;
} 
halfword 
zrebox ( halfword b , scaled w ) 
{
  register halfword Result; rebox_regmem 
  halfword p  ;
  internalfontnumber f  ;
  scaled v  ;
  if ( ( mem [b + 1 ].cint != w ) && ( mem [b + 5 ].hh .v.RH != 
  -1073741823L ) ) 
  {
    if ( mem [b ].hh.b0 != 0 ) 
    b = hpack ( b , 0 , 1 ) ;
    p = mem [b + 5 ].hh .v.RH ;
    if ( ( p >= himemmin ) ) {
	
      if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
      {
	if ( mem [mem [p ].hh .v.RH ].hh .v.RH == -1073741823L ) 
	{
	  f = mem [p ].hh.b0 ;
	  v = fontinfo [widthbase [f ]+ fontinfo [charbase [f ]+ mem [p 
	  ].hh.b1 ].qqqq .b0 ].cint ;
	  if ( v != mem [b + 1 ].cint ) 
	  mem [mem [p ].hh .v.RH ].hh .v.RH = newkern ( mem [b + 1 ]
	  .cint - v ) ;
	} 
      } 
      else if ( mem [p ].hh .v.RH == -1073741823L ) 
      {
	f = mem [p ].hh.b0 ;
	v = fontinfo [widthbase [f ]+ fontinfo [charbase [f ]+ mem [p ]
	.hh.b1 ].qqqq .b0 ].cint ;
	if ( v != mem [b + 1 ].cint ) 
	mem [p ].hh .v.RH = newkern ( mem [b + 1 ].cint - v ) ;
      } 
    } 
    deleteglueref ( mem [b + 7 ].hh .v.RH ) ;
    deleteglueref ( mem [b + 7 ].hh .v.LH ) ;
    freenode ( b , 10 ) ;
    b = newglue ( membot + 16 ) ;
    mem [b ].hh .v.RH = p ;
    while ( mem [p ].hh .v.RH != -1073741823L ) p = mem [p ].hh .v.RH ;
    mem [p ].hh .v.RH = newglue ( membot + 16 ) ;
    Result = hpack ( b , w , 0 ) ;
  } 
  else {
      
    mem [b + 1 ].cint = w ;
    Result = b ;
  } 
  return Result ;
} 
halfword 
zmathglue ( halfword g , scaled m ) 
{
  register halfword Result; mathglue_regmem 
  halfword p  ;
  integer n  ;
  scaled f  ;
  n = xovern ( m , 65536L ) ;
  f = texremainder ;
  if ( f < 0 ) 
  {
    decr ( n ) ;
    f = f + 65536L ;
  } 
  p = getnode ( 4 ) ;
  mem [p + 1 ].cint = multandadd ( n , mem [g + 1 ].cint , xnoverd ( mem [
  g + 1 ].cint , f , 65536L ) , 1073741823L ) ;
  mem [p ].hh.b0 = mem [g ].hh.b0 ;
  if ( mem [p ].hh.b0 == 0 ) 
  mem [p + 2 ].cint = multandadd ( n , mem [g + 2 ].cint , xnoverd ( mem [
  g + 2 ].cint , f , 65536L ) , 1073741823L ) ;
  else mem [p + 2 ].cint = mem [g + 2 ].cint ;
  mem [p ].hh.b1 = mem [g ].hh.b1 ;
  if ( mem [p ].hh.b1 == 0 ) 
  mem [p + 3 ].cint = multandadd ( n , mem [g + 3 ].cint , xnoverd ( mem [
  g + 3 ].cint , f , 65536L ) , 1073741823L ) ;
  else mem [p + 3 ].cint = mem [g + 3 ].cint ;
  Result = p ;
  return Result ;
} 
void 
zmathkern ( halfword p , scaled m ) 
{
  mathkern_regmem 
  integer n  ;
  scaled f  ;
  if ( mem [p ].hh.b1 == 99 ) 
  {
    n = xovern ( m , 65536L ) ;
    f = texremainder ;
    if ( f < 0 ) 
    {
      decr ( n ) ;
      f = f + 65536L ;
    } 
    mem [p + 1 ].cint = multandadd ( n , mem [p + 1 ].cint , xnoverd ( mem 
    [p + 1 ].cint , f , 65536L ) , 1073741823L ) ;
    mem [p ].hh.b1 = 1 ;
  } 
} 
void 
flushmath ( void ) 
{
  flushmath_regmem 
  flushnodelist ( mem [curlist .headfield ].hh .v.RH ) ;
  flushnodelist ( curlist .auxfield .cint ) ;
  mem [curlist .headfield ].hh .v.RH = -1073741823L ;
  curlist .tailfield = curlist .headfield ;
  curlist .auxfield .cint = -1073741823L ;
} 
halfword 
zshiftsubexpbox ( halfword q ) 
{
  register halfword Result; shiftsubexpbox_regmem 
  halfword d  ;
  if ( curlist .dirfield == 3 ) 
  d = eqtb [29795 ].cint ;
  else d = eqtb [29796 ].cint ;
  if ( curstyle < 4 ) 
  d = xnoverd ( d , eqtb [29245 ].cint , 1000 ) ;
  else if ( curstyle < 6 ) 
  d = xnoverd ( d , eqtb [29246 ].cint , 1000 ) ;
  else d = xnoverd ( d , eqtb [29247 ].cint , 1000 ) ;
  mem [mem [q ].hh .v.LH + 4 ].cint = mem [mem [q ].hh .v.LH + 4 ]
  .cint - d ;
  mem [q ].hh .v.RH = 2 ;
  Result = mem [q ].hh .v.LH ;
  return Result ;
} 
halfword 
zcleanbox ( halfword p , smallnumber s , halfword jc ) 
{
  /* 40 */ register halfword Result; cleanbox_regmem 
  halfword q  ;
  smallnumber savestyle  ;
  halfword x  ;
  halfword r  ;
  switch ( mem [p ].hh .v.RH ) 
  {case 1 : 
    {
      curmlist = newnoad () ;
      mem [curmlist + 1 ]= mem [p ];
    } 
    break ;
  case 6 : 
    {
      curmlist = newnoad () ;
      mem [curmlist + 1 ]= mem [p ];
      mem [curmlist + 4 ].hh .v.LH = jc ;
    } 
    break ;
  case 2 : 
    {
      q = mem [p ].hh .v.LH ;
      goto lab40 ;
    } 
    break ;
  case 3 : 
    {
      q = shiftsubexpbox ( p ) ;
      goto lab40 ;
    } 
    break ;
  case 4 : 
    curmlist = mem [p ].hh .v.LH ;
    break ;
    default: 
    {
      q = newnullbox () ;
      goto lab40 ;
    } 
    break ;
  } 
  savestyle = curstyle ;
  curstyle = s ;
  mlistpenalties = false ;
  mlisttohlist () ;
  q = mem [memtop - 3 ].hh .v.RH ;
  curstyle = savestyle ;
  {
    if ( curstyle < 4 ) 
    cursize = 0 ;
    else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
    curmu = xovern ( fontinfo [6 + parambase [eqtb [25591 + cursize ].hh 
    .v.RH ]].cint , 18 ) ;
  } 
  lab40: if ( ( q >= himemmin ) || ( q == -1073741823L ) ) 
  x = hpack ( q , 0 , 1 ) ;
  else if ( ( mem [q ].hh .v.RH == -1073741823L ) && ( mem [q ].hh.b0 <= 2 
  ) && ( mem [q + 4 ].cint == 0 ) ) 
  x = q ;
  else x = hpack ( q , 0 , 1 ) ;
  q = mem [x + 5 ].hh .v.RH ;
  if ( ( q >= himemmin ) ) 
  {
    if ( fontdir [mem [q ].hh.b0 ]!= 0 ) 
    q = mem [q ].hh .v.RH ;
    r = mem [q ].hh .v.RH ;
    if ( r != -1073741823L ) {
	
      if ( mem [r ].hh .v.RH == -1073741823L ) {
	  
	if ( ! ( r >= himemmin ) ) {
	    
	  if ( mem [r ].hh.b0 == 13 ) 
	  {
	    freenode ( r , 4 ) ;
	    mem [q ].hh .v.RH = -1073741823L ;
	  } 
	} 
      } 
    } 
  } 
  Result = x ;
  return Result ;
} 
void 
zfetch ( halfword a ) 
{
  fetch_regmem 
  curc = mem [a ].hh.b1 ;
  curf = eqtb [25589 + mem [a ].hh.b0 + cursize ].hh .v.RH ;
  if ( curf == 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 344 ) ;
    } 
    printsize ( cursize ) ;
    printchar ( 32 ) ;
    printint ( mem [a ].hh.b0 ) ;
    print ( 984 ) ;
    print ( curc ) ;
    printchar ( 41 ) ;
    {
      helpptr = 4 ;
      helpline [3 ]= 985 ;
      helpline [2 ]= 986 ;
      helpline [1 ]= 987 ;
      helpline [0 ]= 988 ;
    } 
    error () ;
    curi = nullcharacter ;
    mem [a ].hh .v.RH = 0 ;
  } 
  else {
      
    if ( fontdir [curf ]!= 0 ) 
    curc = getjfmpos ( mem [a + 3 ].hh .v.LH , curf ) ;
    if ( ( curc >= fontbc [curf ]) && ( curc <= fontec [curf ]) ) 
    curi = fontinfo [charbase [curf ]+ curc ].qqqq ;
    else curi = nullcharacter ;
    if ( ! ( ( curi .b0 > 0 ) ) ) 
    {
      charwarning ( curf , curc ) ;
      mem [a ].hh .v.RH = 0 ;
    } 
  } 
} 
void 
zmakeover ( halfword q ) 
{
  makeover_regmem 
  mem [q + 1 ].hh .v.LH = overbar ( cleanbox ( q + 1 , 2 * ( curstyle / 2 ) 
  + 1 , mem [q + 4 ].hh .v.LH ) , 3 * fontinfo [8 + parambase [eqtb [
  25592 + cursize ].hh .v.RH ]].cint , fontinfo [8 + parambase [eqtb [
  25592 + cursize ].hh .v.RH ]].cint ) ;
  mem [q + 1 ].hh .v.RH = 2 ;
} 
void 
zmakeunder ( halfword q ) 
{
  makeunder_regmem 
  halfword p, x, y  ;
  scaled delta  ;
  x = cleanbox ( q + 1 , curstyle , mem [q + 4 ].hh .v.LH ) ;
  p = newkern ( 3 * fontinfo [8 + parambase [eqtb [25592 + cursize ].hh 
  .v.RH ]].cint ) ;
  mem [x ].hh .v.RH = p ;
  mem [p ].hh .v.RH = fractionrule ( fontinfo [8 + parambase [eqtb [25592 
  + cursize ].hh .v.RH ]].cint ) ;
  y = vpackage ( x , 0 , 1 , 1073741823L ) ;
  delta = mem [y + 3 ].cint + mem [y + 2 ].cint + fontinfo [8 + parambase 
  [eqtb [25592 + cursize ].hh .v.RH ]].cint ;
  mem [y + 3 ].cint = mem [x + 3 ].cint ;
  mem [y + 2 ].cint = delta - mem [y + 3 ].cint ;
  mem [q + 1 ].hh .v.LH = y ;
  mem [q + 1 ].hh .v.RH = 2 ;
} 
void 
zmakevcenter ( halfword q ) 
{
  makevcenter_regmem 
  halfword v  ;
  scaled delta  ;
  v = mem [q + 1 ].hh .v.LH ;
  if ( mem [v ].hh.b0 == 2 ) 
  {
    if ( mem [mem [v + 5 ].hh .v.RH ].hh.b0 != 1 ) 
    confusion ( 990 ) ;
  } 
  else {
      
    if ( mem [v ].hh.b0 != 1 ) 
    confusion ( 589 ) ;
  } 
  delta = mem [v + 3 ].cint + mem [v + 2 ].cint ;
  mem [v + 3 ].cint = fontinfo [22 + parambase [eqtb [25591 + cursize ]
  .hh .v.RH ]].cint + half ( delta ) ;
  mem [v + 2 ].cint = delta - mem [v + 3 ].cint ;
} 
void 
zmakeradical ( halfword q ) 
{
  makeradical_regmem 
  halfword x, y  ;
  scaled delta, clr  ;
  x = cleanbox ( q + 1 , 2 * ( curstyle / 2 ) + 1 , mem [q + 4 ].hh .v.LH ) 
  ;
  if ( curstyle < 2 ) 
  clr = fontinfo [8 + parambase [eqtb [25592 + cursize ].hh .v.RH ]]
  .cint + ( abs ( fontinfo [5 + parambase [eqtb [25591 + cursize ].hh 
  .v.RH ]].cint ) / 4 ) ;
  else {
      
    clr = fontinfo [8 + parambase [eqtb [25592 + cursize ].hh .v.RH ]]
    .cint ;
    clr = clr + ( abs ( clr ) / 4 ) ;
  } 
  y = vardelimiter ( q + 5 , cursize , mem [x + 3 ].cint + mem [x + 2 ]
  .cint + clr + fontinfo [8 + parambase [eqtb [25592 + cursize ].hh .v.RH 
  ]].cint ) ;
  delta = mem [y + 2 ].cint - ( mem [x + 3 ].cint + mem [x + 2 ].cint + 
  clr ) ;
  if ( delta > 0 ) 
  clr = clr + half ( delta ) ;
  mem [y + 4 ].cint = - (integer) ( mem [x + 3 ].cint + clr ) ;
  mem [y ].hh .v.RH = overbar ( x , clr , mem [y + 3 ].cint ) ;
  mem [q + 1 ].hh .v.LH = hpack ( y , 0 , 1 ) ;
  mem [q + 1 ].hh .v.RH = 2 ;
} 
void 
zmakemathaccent ( halfword q ) 
{
  /* 30 31 */ makemathaccent_regmem 
  halfword p, x, y  ;
  integer a  ;
  quarterword c  ;
  internalfontnumber f  ;
  fourquarters i  ;
  scaled s  ;
  scaled h  ;
  scaled delta  ;
  scaled w  ;
  fetch ( q + 5 ) ;
  if ( ( curi .b0 > 0 ) ) 
  {
    i = curi ;
    c = curc ;
    f = curf ;
    s = 0 ;
    if ( mem [q + 1 ].hh .v.RH == 1 ) 
    {
      fetch ( q + 1 ) ;
      if ( ( ( curi .b2 ) % 4 ) == 1 ) 
      {
	a = ligkernbase [curf ]+ curi .b3 ;
	curi = fontinfo [a ].qqqq ;
	if ( curi .b0 > 128 ) 
	{
	  a = ligkernbase [curf ]+ 256 * curi .b2 + curi .b3 + 32768L - 256 
	  * ( 128 ) ;
	  curi = fontinfo [a ].qqqq ;
	} 
	while ( true ) {
	    
	  if ( curi .b1 == skewchar [curf ]) 
	  {
	    if ( curi .b2 >= 128 ) {
		
	      if ( curi .b0 <= 128 ) 
	      s = fontinfo [kernbase [curf ]+ 256 * curi .b2 + curi .b3 ]
	      .cint ;
	    } 
	    goto lab31 ;
	  } 
	  if ( curi .b0 >= 128 ) 
	  goto lab31 ;
	  a = a + curi .b0 + 1 ;
	  curi = fontinfo [a ].qqqq ;
	} 
      } 
    } 
    lab31: ;
    x = cleanbox ( q + 1 , 2 * ( curstyle / 2 ) + 1 , mem [q + 4 ].hh .v.LH 
    ) ;
    w = mem [x + 1 ].cint ;
    h = mem [x + 3 ].cint ;
    while ( true ) {
	
      if ( ( ( i .b2 ) % 4 ) != 2 ) 
      goto lab30 ;
      y = i .b3 ;
      i = fontinfo [charbase [f ]+ y ].qqqq ;
      if ( ! ( i .b0 > 0 ) ) 
      goto lab30 ;
      if ( fontinfo [widthbase [f ]+ i .b0 ].cint > w ) 
      goto lab30 ;
      c = y ;
    } 
    lab30: ;
    if ( h < fontinfo [5 + parambase [f ]].cint ) 
    delta = h ;
    else delta = fontinfo [5 + parambase [f ]].cint ;
    if ( ( mem [q + 2 ].hh .v.RH != 0 ) || ( mem [q + 3 ].hh .v.RH != 0 ) 
    ) {
	
      if ( mem [q + 1 ].hh .v.RH == 1 ) 
      {
	flushnodelist ( x ) ;
	x = newnoad () ;
	mem [x + 1 ]= mem [q + 1 ];
	mem [x + 2 ]= mem [q + 2 ];
	mem [x + 3 ]= mem [q + 3 ];
	mem [q + 2 ].hh = emptyfield ;
	mem [q + 3 ].hh = emptyfield ;
	mem [q + 1 ].hh .v.RH = 4 ;
	mem [q + 1 ].hh .v.LH = x ;
	x = cleanbox ( q + 1 , curstyle , mem [q + 4 ].hh .v.LH ) ;
	delta = delta + mem [x + 3 ].cint - h ;
	h = mem [x + 3 ].cint ;
      } 
    } 
    y = charbox ( f , c ) ;
    mem [y + 4 ].cint = s + half ( w - mem [y + 1 ].cint ) ;
    mem [y + 1 ].cint = 0 ;
    p = newkern ( - (integer) delta ) ;
    mem [p ].hh .v.RH = x ;
    mem [y ].hh .v.RH = p ;
    y = vpackage ( y , 0 , 1 , 1073741823L ) ;
    mem [y + 1 ].cint = mem [x + 1 ].cint ;
    if ( mem [y + 3 ].cint < h ) 
    {
      p = newkern ( h - mem [y + 3 ].cint ) ;
      mem [p ].hh .v.RH = mem [y + 5 ].hh .v.RH ;
      mem [y + 5 ].hh .v.RH = p ;
      mem [y + 3 ].cint = h ;
    } 
    mem [q + 1 ].hh .v.LH = y ;
    mem [q + 1 ].hh .v.RH = 2 ;
  } 
} 
void 
zmakefraction ( halfword q ) 
{
  makefraction_regmem 
  halfword p, v, x, y, z  ;
  scaled delta, delta1, delta2, shiftup, shiftdown, clr  ;
  if ( mem [q + 1 ].cint == 1073741824L ) 
  mem [q + 1 ].cint = fontinfo [8 + parambase [eqtb [25592 + cursize ]
  .hh .v.RH ]].cint ;
  x = cleanbox ( q + 2 , curstyle + 2 - 2 * ( curstyle / 6 ) , mem [q + 4 ]
  .hh .v.LH ) ;
  z = cleanbox ( q + 3 , 2 * ( curstyle / 2 ) + 3 - 2 * ( curstyle / 6 ) , mem 
  [q + 4 ].hh .v.LH ) ;
  if ( mem [x + 1 ].cint < mem [z + 1 ].cint ) 
  x = rebox ( x , mem [z + 1 ].cint ) ;
  else z = rebox ( z , mem [x + 1 ].cint ) ;
  if ( curstyle < 2 ) 
  {
    shiftup = fontinfo [8 + parambase [eqtb [25591 + cursize ].hh .v.RH ]
    ].cint ;
    shiftdown = fontinfo [11 + parambase [eqtb [25591 + cursize ].hh .v.RH 
    ]].cint ;
  } 
  else {
      
    shiftdown = fontinfo [12 + parambase [eqtb [25591 + cursize ].hh .v.RH 
    ]].cint ;
    if ( mem [q + 1 ].cint != 0 ) 
    shiftup = fontinfo [9 + parambase [eqtb [25591 + cursize ].hh .v.RH ]
    ].cint ;
    else shiftup = fontinfo [10 + parambase [eqtb [25591 + cursize ].hh 
    .v.RH ]].cint ;
  } 
  if ( mem [q + 1 ].cint == 0 ) 
  {
    if ( curstyle < 2 ) 
    clr = 7 * fontinfo [8 + parambase [eqtb [25592 + cursize ].hh .v.RH ]
    ].cint ;
    else clr = 3 * fontinfo [8 + parambase [eqtb [25592 + cursize ].hh 
    .v.RH ]].cint ;
    delta = half ( clr - ( ( shiftup - mem [x + 2 ].cint ) - ( mem [z + 3 ]
    .cint - shiftdown ) ) ) ;
    if ( delta > 0 ) 
    {
      shiftup = shiftup + delta ;
      shiftdown = shiftdown + delta ;
    } 
  } 
  else {
      
    if ( curstyle < 2 ) 
    clr = 3 * mem [q + 1 ].cint ;
    else clr = mem [q + 1 ].cint ;
    delta = half ( mem [q + 1 ].cint ) ;
    delta1 = clr - ( ( shiftup - mem [x + 2 ].cint ) - ( fontinfo [22 + 
    parambase [eqtb [25591 + cursize ].hh .v.RH ]].cint + delta ) ) ;
    delta2 = clr - ( ( fontinfo [22 + parambase [eqtb [25591 + cursize ]
    .hh .v.RH ]].cint - delta ) - ( mem [z + 3 ].cint - shiftdown ) ) ;
    if ( delta1 > 0 ) 
    shiftup = shiftup + delta1 ;
    if ( delta2 > 0 ) 
    shiftdown = shiftdown + delta2 ;
  } 
  v = newnullbox () ;
  mem [v ].hh.b0 = 1 ;
  mem [v + 3 ].cint = shiftup + mem [x + 3 ].cint ;
  mem [v + 2 ].cint = mem [z + 2 ].cint + shiftdown ;
  mem [v + 1 ].cint = mem [x + 1 ].cint ;
  if ( mem [q + 1 ].cint == 0 ) 
  {
    p = newkern ( ( shiftup - mem [x + 2 ].cint ) - ( mem [z + 3 ].cint - 
    shiftdown ) ) ;
    mem [p ].hh .v.RH = z ;
  } 
  else {
      
    y = fractionrule ( mem [q + 1 ].cint ) ;
    p = newkern ( ( fontinfo [22 + parambase [eqtb [25591 + cursize ].hh 
    .v.RH ]].cint - delta ) - ( mem [z + 3 ].cint - shiftdown ) ) ;
    mem [y ].hh .v.RH = p ;
    mem [p ].hh .v.RH = z ;
    p = newkern ( ( shiftup - mem [x + 2 ].cint ) - ( fontinfo [22 + 
    parambase [eqtb [25591 + cursize ].hh .v.RH ]].cint + delta ) ) ;
    mem [p ].hh .v.RH = y ;
  } 
  mem [x ].hh .v.RH = p ;
  mem [v + 5 ].hh .v.RH = x ;
  if ( curstyle < 2 ) 
  delta = fontinfo [20 + parambase [eqtb [25591 + cursize ].hh .v.RH ]]
  .cint ;
  else delta = fontinfo [21 + parambase [eqtb [25591 + cursize ].hh .v.RH 
  ]].cint ;
  x = vardelimiter ( q + 5 , cursize , delta ) ;
  mem [x ].hh .v.RH = v ;
  z = vardelimiter ( q + 4 , cursize , delta ) ;
  mem [v ].hh .v.RH = z ;
  mem [q + 1 ].cint = hpack ( x , 0 , 1 ) ;
} 
scaled 
zmakeop ( halfword q ) 
{
  register scaled Result; makeop_regmem 
  scaled delta  ;
  halfword p, v, x, y, z  ;
  quarterword c  ;
  fourquarters i  ;
  scaled shiftup, shiftdown  ;
  if ( ( mem [q ].hh.b1 == 0 ) && ( curstyle < 2 ) ) 
  mem [q ].hh.b1 = 1 ;
  if ( mem [q + 1 ].hh .v.RH == 1 ) 
  {
    fetch ( q + 1 ) ;
    if ( ( curstyle < 2 ) && ( ( ( curi .b2 ) % 4 ) == 2 ) ) 
    {
      c = curi .b3 ;
      i = fontinfo [charbase [curf ]+ c ].qqqq ;
      if ( ( i .b0 > 0 ) ) 
      {
	curc = c ;
	curi = i ;
	mem [q + 1 ].hh.b1 = c ;
      } 
    } 
    delta = fontinfo [italicbase [curf ]+ ( curi .b2 ) / 4 ].cint ;
    x = cleanbox ( q + 1 , curstyle , mem [q + 4 ].hh .v.LH ) ;
    if ( ( mem [q + 3 ].hh .v.RH != 0 ) && ( mem [q ].hh.b1 != 1 ) ) 
    mem [x + 1 ].cint = mem [x + 1 ].cint - delta ;
    mem [x + 4 ].cint = half ( mem [x + 3 ].cint - mem [x + 2 ].cint ) - 
    fontinfo [22 + parambase [eqtb [25591 + cursize ].hh .v.RH ]].cint ;
    mem [q + 1 ].hh .v.RH = 2 ;
    mem [q + 1 ].hh .v.LH = x ;
  } 
  else delta = 0 ;
  if ( mem [q ].hh.b1 == 1 ) 
  {
    x = cleanbox ( q + 2 , 2 * ( curstyle / 4 ) + 4 + ( curstyle % 2 ) , mem [
    q + 4 ].hh .v.LH ) ;
    y = cleanbox ( q + 1 , curstyle , mem [q + 4 ].hh .v.LH ) ;
    z = cleanbox ( q + 3 , 2 * ( curstyle / 4 ) + 5 , mem [q + 4 ].hh .v.LH 
    ) ;
    v = newnullbox () ;
    mem [v ].hh.b0 = 1 ;
    mem [v + 1 ].cint = mem [y + 1 ].cint ;
    if ( mem [x + 1 ].cint > mem [v + 1 ].cint ) 
    mem [v + 1 ].cint = mem [x + 1 ].cint ;
    if ( mem [z + 1 ].cint > mem [v + 1 ].cint ) 
    mem [v + 1 ].cint = mem [z + 1 ].cint ;
    x = rebox ( x , mem [v + 1 ].cint ) ;
    y = rebox ( y , mem [v + 1 ].cint ) ;
    z = rebox ( z , mem [v + 1 ].cint ) ;
    mem [x + 4 ].cint = half ( delta ) ;
    mem [z + 4 ].cint = - (integer) mem [x + 4 ].cint ;
    mem [v + 3 ].cint = mem [y + 3 ].cint ;
    mem [v + 2 ].cint = mem [y + 2 ].cint ;
    if ( mem [q + 2 ].hh .v.RH == 0 ) 
    {
      deleteglueref ( mem [x + 7 ].hh .v.RH ) ;
      deleteglueref ( mem [x + 7 ].hh .v.LH ) ;
      freenode ( x , 10 ) ;
      mem [v + 5 ].hh .v.RH = y ;
    } 
    else {
	
      shiftup = fontinfo [11 + parambase [eqtb [25592 + cursize ].hh .v.RH 
      ]].cint - mem [x + 2 ].cint ;
      if ( shiftup < fontinfo [9 + parambase [eqtb [25592 + cursize ].hh 
      .v.RH ]].cint ) 
      shiftup = fontinfo [9 + parambase [eqtb [25592 + cursize ].hh .v.RH 
      ]].cint ;
      p = newkern ( shiftup ) ;
      mem [p ].hh .v.RH = y ;
      mem [x ].hh .v.RH = p ;
      p = newkern ( fontinfo [13 + parambase [eqtb [25592 + cursize ].hh 
      .v.RH ]].cint ) ;
      mem [p ].hh .v.RH = x ;
      mem [v + 5 ].hh .v.RH = p ;
      mem [v + 3 ].cint = mem [v + 3 ].cint + fontinfo [13 + parambase [
      eqtb [25592 + cursize ].hh .v.RH ]].cint + mem [x + 3 ].cint + mem 
      [x + 2 ].cint + shiftup ;
    } 
    if ( mem [q + 3 ].hh .v.RH == 0 ) 
    {
      deleteglueref ( mem [z + 7 ].hh .v.RH ) ;
      deleteglueref ( mem [z + 7 ].hh .v.LH ) ;
      freenode ( z , 10 ) ;
    } 
    else {
	
      shiftdown = fontinfo [12 + parambase [eqtb [25592 + cursize ].hh 
      .v.RH ]].cint - mem [z + 3 ].cint ;
      if ( shiftdown < fontinfo [10 + parambase [eqtb [25592 + cursize ]
      .hh .v.RH ]].cint ) 
      shiftdown = fontinfo [10 + parambase [eqtb [25592 + cursize ].hh 
      .v.RH ]].cint ;
      p = newkern ( shiftdown ) ;
      mem [y ].hh .v.RH = p ;
      mem [p ].hh .v.RH = z ;
      p = newkern ( fontinfo [13 + parambase [eqtb [25592 + cursize ].hh 
      .v.RH ]].cint ) ;
      mem [z ].hh .v.RH = p ;
      mem [v + 2 ].cint = mem [v + 2 ].cint + fontinfo [13 + parambase [
      eqtb [25592 + cursize ].hh .v.RH ]].cint + mem [z + 3 ].cint + mem 
      [z + 2 ].cint + shiftdown ;
    } 
    mem [q + 1 ].cint = v ;
  } 
  Result = delta ;
  return Result ;
} 
void 
zmakeord ( halfword q ) 
{
  /* 20 10 */ makeord_regmem 
  integer a  ;
  halfword gp, gq, p, r  ;
  halfword rr  ;
  lab20: if ( ( mem [q + 3 ].hh .v.RH == 0 ) && ( mem [q + 2 ].hh .v.RH == 
  0 ) && ( ( mem [q + 1 ].hh .v.RH == 1 ) || ( mem [q + 1 ].hh .v.RH == 6 
  ) ) ) 
  {
    p = mem [q ].hh .v.RH ;
    if ( p != -1073741823L ) {
	
      if ( ( mem [p ].hh.b0 >= 18 ) && ( mem [p ].hh.b0 <= 24 ) ) {
	  
	if ( mem [p + 1 ].hh.b0 == mem [q + 1 ].hh.b0 ) {
	    
	  if ( mem [p + 1 ].hh .v.RH == 1 ) 
	  {
	    mem [q + 1 ].hh .v.RH = 5 ;
	    fetch ( q + 1 ) ;
	    if ( ( ( curi .b2 ) % 4 ) == 1 ) 
	    {
	      a = ligkernbase [curf ]+ curi .b3 ;
	      curc = mem [p + 1 ].hh.b1 ;
	      curi = fontinfo [a ].qqqq ;
	      if ( curi .b0 > 128 ) 
	      {
		a = ligkernbase [curf ]+ 256 * curi .b2 + curi .b3 + 32768L 
		- 256 * ( 128 ) ;
		curi = fontinfo [a ].qqqq ;
	      } 
	      while ( true ) {
		  
		if ( curi .b1 == curc ) {
		    
		  if ( curi .b0 <= 128 ) {
		      
		    if ( curi .b2 >= 128 ) 
		    {
		      p = newkern ( fontinfo [kernbase [curf ]+ 256 * curi 
		      .b2 + curi .b3 ].cint ) ;
		      mem [p ].hh .v.RH = mem [q ].hh .v.RH ;
		      mem [q ].hh .v.RH = p ;
		      return ;
		    } 
		    else {
			
		      {
			if ( interrupt != 0 ) 
			pauseforinstructions () ;
		      } 
		      switch ( curi .b2 ) 
		      {case 1 : 
		      case 5 : 
			mem [q + 1 ].hh.b1 = curi .b3 ;
			break ;
		      case 2 : 
		      case 6 : 
			mem [p + 1 ].hh.b1 = curi .b3 ;
			break ;
		      case 3 : 
		      case 7 : 
		      case 11 : 
			{
			  r = newnoad () ;
			  mem [r + 1 ].hh.b1 = curi .b3 ;
			  mem [r + 1 ].hh.b0 = mem [q + 1 ].hh.b0 ;
			  mem [q ].hh .v.RH = r ;
			  mem [r ].hh .v.RH = p ;
			  if ( curi .b2 < 11 ) 
			  mem [r + 1 ].hh .v.RH = 1 ;
			  else mem [r + 1 ].hh .v.RH = 5 ;
			} 
			break ;
			default: 
			{
			  mem [q ].hh .v.RH = mem [p ].hh .v.RH ;
			  mem [q + 1 ].hh.b1 = curi .b3 ;
			  mem [q + 3 ]= mem [p + 3 ];
			  mem [q + 2 ]= mem [p + 2 ];
			  freenode ( p , 5 ) ;
			} 
			break ;
		      } 
		      if ( curi .b2 > 3 ) 
		      return ;
		      mem [q + 1 ].hh .v.RH = 1 ;
		      goto lab20 ;
		    } 
		  } 
		} 
		if ( curi .b0 >= 128 ) 
		return ;
		a = a + curi .b0 + 1 ;
		curi = fontinfo [a ].qqqq ;
	      } 
	    } 
	  } 
	  else if ( mem [p + 1 ].hh .v.RH == 6 ) 
	  {
	    mem [q + 1 ].hh .v.RH = 7 ;
	    fetch ( p + 1 ) ;
	    a = curc ;
	    fetch ( q + 1 ) ;
	    if ( ( ( curi .b2 ) % 4 ) == 1 ) 
	    {
	      curc = a ;
	      a = ligkernbase [curf ]+ curi .b3 ;
	      do {
		  curi = fontinfo [a ].qqqq ;
		if ( curi .b1 == curc ) {
		    
		  if ( curi .b2 < 128 ) 
		  {
		    gp = fontglue [curf ];
		    rr = curi .b3 ;
		    if ( gp != -1073741823L ) 
		    {
		      while ( ( ( mem [gp ].hh.b0 != rr ) && ( mem [gp ]
		      .hh .v.RH != -1073741823L ) ) ) {
			  
			gp = mem [gp ].hh .v.RH ;
		      } 
		      gq = mem [gp + 1 ].hh .v.LH ;
		    } 
		    else {
			
		      gp = getnode ( 2 ) ;
		      fontglue [curf ]= gp ;
		      gq = -1073741823L ;
		    } 
		    if ( gq == -1073741823L ) 
		    {
		      mem [gp ].hh.b0 = rr ;
		      gq = newspec ( membot ) ;
		      mem [gp + 1 ].hh .v.LH = gq ;
		      a = extenbase [curf ]+ ( rr ) * 3 ;
		      mem [gq + 1 ].cint = fontinfo [a ].cint ;
		      mem [gq + 2 ].cint = fontinfo [a + 1 ].cint ;
		      mem [gq + 3 ].cint = fontinfo [a + 2 ].cint ;
		      incr ( mem [gq ].hh .v.RH ) ;
		      mem [gp ].hh .v.RH = getnode ( 2 ) ;
		      gp = mem [gp ].hh .v.RH ;
		      mem [gp + 1 ].hh .v.LH = -1073741823L ;
		      mem [gp ].hh .v.RH = -1073741823L ;
		    } 
		    p = newglue ( gq ) ;
		    mem [p ].hh .v.RH = mem [q ].hh .v.RH ;
		    mem [q ].hh .v.RH = p ;
		    return ;
		  } 
		  else {
		      
		    p = newkern ( fontinfo [kernbase [curf ]+ 256 * curi 
		    .b2 + curi .b3 ].cint ) ;
		    mem [p ].hh .v.RH = mem [q ].hh .v.RH ;
		    mem [q ].hh .v.RH = p ;
		    return ;
		  } 
		} 
		incr ( a ) ;
	      } while ( ! ( curi .b0 >= 128 ) ) ;
	    } 
	  } 
	} 
      } 
    } 
  } 
} 
void 
zmakescripts ( halfword q , scaled delta ) 
{
  makescripts_regmem 
  halfword p, x, y, z  ;
  scaled shiftup, shiftdown, clr  ;
  integer t  ;
  p = mem [q + 1 ].cint ;
  if ( ( p >= himemmin ) ) 
  {
    shiftup = 0 ;
    shiftdown = 0 ;
  } 
  else {
      
    z = hpack ( p , 0 , 1 ) ;
    if ( curstyle < 4 ) 
    t = 256 ;
    else t = 512 ;
    shiftup = mem [z + 3 ].cint - fontinfo [18 + parambase [eqtb [25591 + 
    t ].hh .v.RH ]].cint ;
    shiftdown = mem [z + 2 ].cint + fontinfo [19 + parambase [eqtb [25591 
    + t ].hh .v.RH ]].cint ;
    deleteglueref ( mem [z + 7 ].hh .v.RH ) ;
    deleteglueref ( mem [z + 7 ].hh .v.LH ) ;
    freenode ( z , 10 ) ;
  } 
  if ( mem [q + 2 ].hh .v.RH == 0 ) 
  {
    x = cleanbox ( q + 3 , 2 * ( curstyle / 4 ) + 5 , mem [q + 4 ].hh .v.LH 
    ) ;
    mem [x + 1 ].cint = mem [x + 1 ].cint + eqtb [29786 ].cint ;
    if ( shiftdown < fontinfo [16 + parambase [eqtb [25591 + cursize ].hh 
    .v.RH ]].cint ) 
    shiftdown = fontinfo [16 + parambase [eqtb [25591 + cursize ].hh .v.RH 
    ]].cint ;
    clr = mem [x + 3 ].cint - ( abs ( fontinfo [5 + parambase [eqtb [
    25591 + cursize ].hh .v.RH ]].cint * 4 ) / 5 ) ;
    if ( shiftdown < clr ) 
    shiftdown = clr ;
    mem [x + 4 ].cint = shiftdown ;
  } 
  else {
      
    {
      x = cleanbox ( q + 2 , 2 * ( curstyle / 4 ) + 4 + ( curstyle % 2 ) , mem 
      [q + 4 ].hh .v.LH ) ;
      mem [x + 1 ].cint = mem [x + 1 ].cint + eqtb [29786 ].cint ;
      if ( odd ( curstyle ) ) 
      clr = fontinfo [15 + parambase [eqtb [25591 + cursize ].hh .v.RH ]]
      .cint ;
      else if ( curstyle < 2 ) 
      clr = fontinfo [13 + parambase [eqtb [25591 + cursize ].hh .v.RH ]]
      .cint ;
      else clr = fontinfo [14 + parambase [eqtb [25591 + cursize ].hh 
      .v.RH ]].cint ;
      if ( shiftup < clr ) 
      shiftup = clr ;
      clr = mem [x + 2 ].cint + ( abs ( fontinfo [5 + parambase [eqtb [
      25591 + cursize ].hh .v.RH ]].cint ) / 4 ) ;
      if ( shiftup < clr ) 
      shiftup = clr ;
    } 
    if ( mem [q + 3 ].hh .v.RH == 0 ) 
    mem [x + 4 ].cint = - (integer) shiftup ;
    else {
	
      y = cleanbox ( q + 3 , 2 * ( curstyle / 4 ) + 5 , mem [q + 4 ].hh 
      .v.LH ) ;
      mem [y + 1 ].cint = mem [y + 1 ].cint + eqtb [29786 ].cint ;
      if ( shiftdown < fontinfo [17 + parambase [eqtb [25591 + cursize ]
      .hh .v.RH ]].cint ) 
      shiftdown = fontinfo [17 + parambase [eqtb [25591 + cursize ].hh 
      .v.RH ]].cint ;
      clr = 4 * fontinfo [8 + parambase [eqtb [25592 + cursize ].hh .v.RH 
      ]].cint - ( ( shiftup - mem [x + 2 ].cint ) - ( mem [y + 3 ].cint 
      - shiftdown ) ) ;
      if ( clr > 0 ) 
      {
	shiftdown = shiftdown + clr ;
	clr = ( abs ( fontinfo [5 + parambase [eqtb [25591 + cursize ].hh 
	.v.RH ]].cint * 4 ) / 5 ) - ( shiftup - mem [x + 2 ].cint ) ;
	if ( clr > 0 ) 
	{
	  shiftup = shiftup + clr ;
	  shiftdown = shiftdown - clr ;
	} 
      } 
      mem [x + 4 ].cint = delta ;
      p = newkern ( ( shiftup - mem [x + 2 ].cint ) - ( mem [y + 3 ].cint 
      - shiftdown ) ) ;
      mem [x ].hh .v.RH = p ;
      mem [p ].hh .v.RH = y ;
      x = vpackage ( x , 0 , 1 , 1073741823L ) ;
      mem [x + 4 ].cint = shiftdown ;
    } 
  } 
  if ( mem [q + 1 ].cint == -1073741823L ) 
  mem [q + 1 ].cint = x ;
  else {
      
    p = mem [q + 1 ].cint ;
    while ( mem [p ].hh .v.RH != -1073741823L ) p = mem [p ].hh .v.RH ;
    mem [p ].hh .v.RH = x ;
  } 
} 
smallnumber 
zmakeleftright ( halfword q , smallnumber style , scaled maxd , scaled maxh ) 
{
  register smallnumber Result; makeleftright_regmem 
  scaled delta, delta1, delta2  ;
  curstyle = style ;
  {
    if ( curstyle < 4 ) 
    cursize = 0 ;
    else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
    curmu = xovern ( fontinfo [6 + parambase [eqtb [25591 + cursize ].hh 
    .v.RH ]].cint , 18 ) ;
  } 
  delta2 = maxd + fontinfo [22 + parambase [eqtb [25591 + cursize ].hh 
  .v.RH ]].cint ;
  delta1 = maxh + maxd - delta2 ;
  if ( delta2 > delta1 ) 
  delta1 = delta2 ;
  delta = ( delta1 / 500 ) * eqtb [29206 ].cint ;
  delta2 = delta1 + delta1 - eqtb [29784 ].cint ;
  if ( delta < delta2 ) 
  delta = delta2 ;
  mem [q + 1 ].cint = vardelimiter ( q + 1 , cursize , delta ) ;
  Result = mem [q ].hh.b0 - ( 10 ) ;
  return Result ;
} 
void 
mlisttohlist ( void ) 
{
  /* 21 82 80 81 83 30 */ mlisttohlist_regmem 
  halfword mlist  ;
  boolean penalties  ;
  smallnumber style  ;
  halfword u  ;
  smallnumber savestyle  ;
  halfword q  ;
  halfword r  ;
  smallnumber rtype  ;
  smallnumber t  ;
  halfword p, x, y, z  ;
  integer pen  ;
  integer s  ;
  scaled maxh, maxd  ;
  scaled delta  ;
  mlist = curmlist ;
  penalties = mlistpenalties ;
  style = curstyle ;
  q = mlist ;
  r = -1073741823L ;
  rtype = 19 ;
  maxh = 0 ;
  maxd = 0 ;
  {
    if ( curstyle < 4 ) 
    cursize = 0 ;
    else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
    curmu = xovern ( fontinfo [6 + parambase [eqtb [25591 + cursize ].hh 
    .v.RH ]].cint , 18 ) ;
  } 
  while ( q != -1073741823L ) {
      
    lab21: delta = 0 ;
    switch ( mem [q ].hh.b0 ) 
    {case 20 : 
      switch ( rtype ) 
      {case 20 : 
      case 19 : 
      case 21 : 
      case 22 : 
      case 24 : 
      case 32 : 
	{
	  mem [q ].hh.b0 = 18 ;
	  goto lab21 ;
	} 
	break ;
	default: 
	;
	break ;
      } 
      break ;
    case 21 : 
    case 23 : 
    case 24 : 
    case 33 : 
      {
	if ( rtype == 20 ) 
	mem [r ].hh.b0 = 18 ;
	if ( mem [q ].hh.b0 == 33 ) 
	goto lab80 ;
      } 
      break ;
    case 32 : 
      goto lab80 ;
      break ;
    case 27 : 
      {
	makefraction ( q ) ;
	goto lab82 ;
      } 
      break ;
    case 19 : 
      {
	delta = makeop ( q ) ;
	if ( mem [q ].hh.b1 == 1 ) 
	goto lab82 ;
      } 
      break ;
    case 18 : 
      makeord ( q ) ;
      break ;
    case 22 : 
    case 25 : 
      ;
      break ;
    case 26 : 
      makeradical ( q ) ;
      break ;
    case 29 : 
      makeover ( q ) ;
      break ;
    case 28 : 
      makeunder ( q ) ;
      break ;
    case 30 : 
      makemathaccent ( q ) ;
      break ;
    case 31 : 
      makevcenter ( q ) ;
      break ;
    case 16 : 
      {
	curstyle = mem [q ].hh.b1 ;
	{
	  if ( curstyle < 4 ) 
	  cursize = 0 ;
	  else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
	  curmu = xovern ( fontinfo [6 + parambase [eqtb [25591 + cursize ]
	  .hh .v.RH ]].cint , 18 ) ;
	} 
	goto lab81 ;
      } 
      break ;
    case 17 : 
      {
	switch ( curstyle / 2 ) 
	{case 0 : 
	  {
	    p = mem [q + 1 ].hh .v.LH ;
	    mem [q + 1 ].hh .v.LH = -1073741823L ;
	  } 
	  break ;
	case 1 : 
	  {
	    p = mem [q + 1 ].hh .v.RH ;
	    mem [q + 1 ].hh .v.RH = -1073741823L ;
	  } 
	  break ;
	case 2 : 
	  {
	    p = mem [q + 2 ].hh .v.LH ;
	    mem [q + 2 ].hh .v.LH = -1073741823L ;
	  } 
	  break ;
	case 3 : 
	  {
	    p = mem [q + 2 ].hh .v.RH ;
	    mem [q + 2 ].hh .v.RH = -1073741823L ;
	  } 
	  break ;
	} 
	flushnodelist ( mem [q + 1 ].hh .v.LH ) ;
	flushnodelist ( mem [q + 1 ].hh .v.RH ) ;
	flushnodelist ( mem [q + 2 ].hh .v.LH ) ;
	flushnodelist ( mem [q + 2 ].hh .v.RH ) ;
	mem [q ].hh.b0 = 16 ;
	mem [q ].hh.b1 = curstyle ;
	mem [q + 1 ].cint = 0 ;
	mem [q + 2 ].cint = 0 ;
	if ( p != -1073741823L ) 
	{
	  z = mem [q ].hh .v.RH ;
	  mem [q ].hh .v.RH = p ;
	  while ( mem [p ].hh .v.RH != -1073741823L ) p = mem [p ].hh 
	  .v.RH ;
	  mem [p ].hh .v.RH = z ;
	} 
	goto lab81 ;
      } 
      break ;
    case 4 : 
    case 6 : 
    case 7 : 
    case 10 : 
    case 14 : 
    case 9 : 
      goto lab81 ;
      break ;
    case 3 : 
      {
	if ( mem [q + 3 ].cint > maxh ) 
	maxh = mem [q + 3 ].cint ;
	if ( mem [q + 2 ].cint > maxd ) 
	maxd = mem [q + 2 ].cint ;
	goto lab81 ;
      } 
      break ;
    case 12 : 
      {
	if ( mem [q ].hh.b1 == 99 ) 
	{
	  x = mem [q + 1 ].hh .v.LH ;
	  y = mathglue ( x , curmu ) ;
	  deleteglueref ( x ) ;
	  mem [q + 1 ].hh .v.LH = y ;
	  mem [q ].hh.b1 = 0 ;
	} 
	else if ( ( cursize != 0 ) && ( mem [q ].hh.b1 == 98 ) ) 
	{
	  p = mem [q ].hh .v.RH ;
	  if ( p != -1073741823L ) {
	      
	    if ( ( mem [p ].hh.b0 == 12 ) || ( mem [p ].hh.b0 == 13 ) ) 
	    {
	      mem [q ].hh .v.RH = mem [p ].hh .v.RH ;
	      mem [p ].hh .v.RH = -1073741823L ;
	      flushnodelist ( p ) ;
	    } 
	  } 
	} 
	goto lab81 ;
      } 
      break ;
    case 13 : 
      {
	mathkern ( q , curmu ) ;
	goto lab81 ;
      } 
      break ;
    case 5 : 
      goto lab81 ;
      break ;
      default: 
      confusion ( 989 ) ;
      break ;
    } 
    switch ( mem [q + 1 ].hh .v.RH ) 
    {case 1 : 
    case 5 : 
    case 6 : 
    case 7 : 
      {
	fetch ( q + 1 ) ;
	if ( ( curi .b0 > 0 ) ) 
	{
	  delta = fontinfo [italicbase [curf ]+ ( curi .b2 ) / 4 ].cint ;
	  p = newcharacter ( curf , curc ) ;
	  u = p ;
	  if ( fontdir [curf ]!= 0 ) 
	  {
	    mem [u ].hh .v.RH = getavail () ;
	    u = mem [u ].hh .v.RH ;
	    mem [u ].hh .v.LH = mem [q + 4 ].hh .v.LH ;
	  } 
	  if ( ( ( mem [q + 1 ].hh .v.RH == 5 ) || ( mem [q + 1 ].hh .v.RH 
	  == 7 ) ) && ( fontinfo [2 + parambase [curf ]].cint != 0 ) ) 
	  delta = 0 ;
	  if ( ( mem [q + 3 ].hh .v.RH == 0 ) && ( delta != 0 ) ) 
	  {
	    mem [u ].hh .v.RH = newkern ( delta ) ;
	    delta = 0 ;
	  } 
	} 
	else p = -1073741823L ;
      } 
      break ;
    case 0 : 
      p = -1073741823L ;
      break ;
    case 2 : 
      p = mem [q + 1 ].hh .v.LH ;
      break ;
    case 3 : 
      p = shiftsubexpbox ( q + 1 ) ;
      break ;
    case 4 : 
      {
	curmlist = mem [q + 1 ].hh .v.LH ;
	savestyle = curstyle ;
	mlistpenalties = false ;
	mlisttohlist () ;
	curstyle = savestyle ;
	{
	  if ( curstyle < 4 ) 
	  cursize = 0 ;
	  else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
	  curmu = xovern ( fontinfo [6 + parambase [eqtb [25591 + cursize ]
	  .hh .v.RH ]].cint , 18 ) ;
	} 
	p = hpack ( mem [memtop - 3 ].hh .v.RH , 0 , 1 ) ;
      } 
      break ;
      default: 
      confusion ( 991 ) ;
      break ;
    } 
    mem [q + 1 ].cint = p ;
    if ( ( mem [q + 3 ].hh .v.RH == 0 ) && ( mem [q + 2 ].hh .v.RH == 0 ) 
    ) 
    goto lab82 ;
    makescripts ( q , delta ) ;
    lab82: z = hpack ( mem [q + 1 ].cint , 0 , 1 ) ;
    if ( mem [z + 3 ].cint > maxh ) 
    maxh = mem [z + 3 ].cint ;
    if ( mem [z + 2 ].cint > maxd ) 
    maxd = mem [z + 2 ].cint ;
    deleteglueref ( mem [z + 7 ].hh .v.RH ) ;
    deleteglueref ( mem [z + 7 ].hh .v.LH ) ;
    freenode ( z , 10 ) ;
    lab80: r = q ;
    rtype = mem [r ].hh.b0 ;
    if ( rtype == 33 ) 
    {
      rtype = 32 ;
      curstyle = style ;
      {
	if ( curstyle < 4 ) 
	cursize = 0 ;
	else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
	curmu = xovern ( fontinfo [6 + parambase [eqtb [25591 + cursize ]
	.hh .v.RH ]].cint , 18 ) ;
      } 
    } 
    lab81: q = mem [q ].hh .v.RH ;
  } 
  if ( rtype == 20 ) 
  mem [r ].hh.b0 = 18 ;
  p = memtop - 3 ;
  mem [p ].hh .v.RH = -1073741823L ;
  q = mlist ;
  rtype = 0 ;
  curstyle = style ;
  {
    if ( curstyle < 4 ) 
    cursize = 0 ;
    else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
    curmu = xovern ( fontinfo [6 + parambase [eqtb [25591 + cursize ].hh 
    .v.RH ]].cint , 18 ) ;
  } 
  while ( q != -1073741823L ) {
      
    t = 18 ;
    s = 5 ;
    pen = 10000 ;
    switch ( mem [q ].hh.b0 ) 
    {case 19 : 
    case 22 : 
    case 23 : 
    case 24 : 
    case 25 : 
      t = mem [q ].hh.b0 ;
      break ;
    case 20 : 
      {
	t = 20 ;
	pen = eqtb [29197 ].cint ;
      } 
      break ;
    case 21 : 
      {
	t = 21 ;
	pen = eqtb [29198 ].cint ;
      } 
      break ;
    case 18 : 
    case 31 : 
    case 29 : 
    case 28 : 
      ;
      break ;
    case 26 : 
      s = 6 ;
      break ;
    case 30 : 
      s = 6 ;
      break ;
    case 27 : 
      {
	t = 25 ;
	s = 6 ;
      } 
      break ;
    case 32 : 
    case 33 : 
      t = makeleftright ( q , style , maxd , maxh ) ;
      break ;
    case 16 : 
      {
	curstyle = mem [q ].hh.b1 ;
	s = 3 ;
	{
	  if ( curstyle < 4 ) 
	  cursize = 0 ;
	  else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
	  curmu = xovern ( fontinfo [6 + parambase [eqtb [25591 + cursize ]
	  .hh .v.RH ]].cint , 18 ) ;
	} 
	goto lab83 ;
      } 
      break ;
    case 10 : 
    case 14 : 
    case 3 : 
    case 9 : 
    case 7 : 
    case 4 : 
    case 6 : 
    case 12 : 
    case 13 : 
      {
	mem [p ].hh .v.RH = q ;
	p = q ;
	q = mem [q ].hh .v.RH ;
	mem [p ].hh .v.RH = -1073741823L ;
	goto lab30 ;
      } 
      break ;
    case 5 : 
      {
	mem [p ].hh .v.RH = q ;
	p = q ;
	q = mem [q ].hh .v.RH ;
	mem [p ].hh .v.RH = -1073741823L ;
	goto lab30 ;
      } 
      break ;
      default: 
      confusion ( 992 ) ;
      break ;
    } 
    if ( rtype > 0 ) 
    {
      switch ( strpool [rtype * 8 + t + magicoffset ]) 
      {case 48 : 
	x = 0 ;
	break ;
      case 49 : 
	if ( curstyle < 4 ) 
	x = 17 ;
	else x = 0 ;
	break ;
      case 50 : 
	x = 17 ;
	break ;
      case 51 : 
	if ( curstyle < 4 ) 
	x = 18 ;
	else x = 0 ;
	break ;
      case 52 : 
	if ( curstyle < 4 ) 
	x = 19 ;
	else x = 0 ;
	break ;
	default: 
	confusion ( 994 ) ;
	break ;
      } 
      if ( x != 0 ) 
      {
	y = mathglue ( eqtb [24528 + x ].hh .v.RH , curmu ) ;
	z = newglue ( y ) ;
	mem [y ].hh .v.RH = -1073741823L ;
	mem [p ].hh .v.RH = z ;
	p = z ;
	mem [z ].hh.b1 = x + 1 ;
      } 
    } 
    if ( mem [q + 1 ].cint != -1073741823L ) 
    {
      mem [p ].hh .v.RH = mem [q + 1 ].cint ;
      do {
	  p = mem [p ].hh .v.RH ;
      } while ( ! ( mem [p ].hh .v.RH == -1073741823L ) ) ;
    } 
    if ( penalties ) {
	
      if ( mem [q ].hh .v.RH != -1073741823L ) {
	  
	if ( pen < 10000 ) 
	{
	  rtype = mem [mem [q ].hh .v.RH ].hh.b0 ;
	  if ( rtype != 14 ) {
	      
	    if ( rtype != 21 ) 
	    {
	      z = newpenalty ( pen ) ;
	      mem [p ].hh .v.RH = z ;
	      p = z ;
	    } 
	  } 
	} 
      } 
    } 
    if ( mem [q ].hh.b0 == 33 ) 
    t = 22 ;
    rtype = t ;
    lab83: r = q ;
    q = mem [q ].hh .v.RH ;
    freenode ( r , s ) ;
    lab30: ;
  } 
  p = newnullbox () ;
  mem [p ].hh .v.RH = mem [memtop - 3 ].hh .v.RH ;
  adjusthlist ( p , false ) ;
  mem [memtop - 3 ].hh .v.RH = mem [p ].hh .v.RH ;
  deleteglueref ( mem [p + 7 ].hh .v.RH ) ;
  deleteglueref ( mem [p + 7 ].hh .v.LH ) ;
  freenode ( p , 10 ) ;
} 
void 
pushalignment ( void ) 
{
  pushalignment_regmem 
  halfword p  ;
  p = getnode ( 5 ) ;
  mem [p ].hh .v.RH = alignptr ;
  mem [p ].hh .v.LH = curalign ;
  mem [p + 1 ].hh .v.LH = mem [memtop - 8 ].hh .v.RH ;
  mem [p + 1 ].hh .v.RH = curspan ;
  mem [p + 2 ].cint = curloop ;
  mem [p + 3 ].cint = alignstate ;
  mem [p + 4 ].hh .v.LH = curhead ;
  mem [p + 4 ].hh .v.RH = curtail ;
  alignptr = p ;
  curhead = getavail () ;
} 
void 
popalignment ( void ) 
{
  popalignment_regmem 
  halfword p  ;
  {
    mem [curhead ].hh .v.RH = avail ;
    avail = curhead ;
	;
#ifdef STAT
    decr ( dynused ) ;
#endif /* STAT */
  } 
  p = alignptr ;
  curtail = mem [p + 4 ].hh .v.RH ;
  curhead = mem [p + 4 ].hh .v.LH ;
  alignstate = mem [p + 3 ].cint ;
  curloop = mem [p + 2 ].cint ;
  curspan = mem [p + 1 ].hh .v.RH ;
  mem [memtop - 8 ].hh .v.RH = mem [p + 1 ].hh .v.LH ;
  curalign = mem [p ].hh .v.LH ;
  alignptr = mem [p ].hh .v.RH ;
  freenode ( p , 5 ) ;
} 
void 
getpreambletoken ( void ) 
{
  /* 20 */ getpreambletoken_regmem 
  lab20: gettoken () ;
  while ( ( curchr == 256 ) && ( curcmd == 4 ) ) {
      
    gettoken () ;
    if ( curcmd > 116 ) 
    {
      expand () ;
      gettoken () ;
    } 
  } 
  if ( curcmd == 9 ) 
  fatalerror ( 650 ) ;
  if ( ( curcmd == 84 ) && ( curchr == 24539 ) ) 
  {
    scanoptionalequals () ;
    scanglue ( 2 ) ;
    if ( eqtb [29231 ].cint > 0 ) 
    geqdefine ( 24539 , 133 , curval ) ;
    else eqdefine ( 24539 , 133 , curval ) ;
    goto lab20 ;
  } 
} 
void 
initalign ( void ) 
{
  /* 30 31 32 22 */ initalign_regmem 
  halfword savecsptr  ;
  halfword p  ;
  savecsptr = curcs ;
  pushalignment () ;
  alignstate = -1000000L ;
  if ( ( curlist .modefield == 235 ) && ( ( curlist .tailfield != curlist 
  .headfield ) || ( curlist .auxfield .cint != -1073741823L ) ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 746 ) ;
    } 
    printesc ( 566 ) ;
    print ( 995 ) ;
    {
      helpptr = 3 ;
      helpline [2 ]= 996 ;
      helpline [1 ]= 997 ;
      helpline [0 ]= 998 ;
    } 
    error () ;
    flushmath () ;
  } 
  pushnest () ;
  if ( curlist .modefield == 235 ) 
  {
    curlist .modefield = -1 ;
    curlist .auxfield .cint = nest [nestptr - 2 ].auxfield .cint ;
  } 
  else if ( curlist .modefield > 0 ) 
  curlist .modefield = - (integer) curlist .modefield ;
  scanspec ( 6 , false ) ;
  mem [memtop - 8 ].hh .v.RH = -1073741823L ;
  curalign = memtop - 8 ;
  curloop = -1073741823L ;
  scannerstatus = 4 ;
  warningindex = savecsptr ;
  alignstate = -1000000L ;
  while ( true ) {
      
    mem [curalign ].hh .v.RH = newparamglue ( 11 ) ;
    curalign = mem [curalign ].hh .v.RH ;
    if ( curcmd == 5 ) 
    goto lab30 ;
    p = memtop - 4 ;
    mem [p ].hh .v.RH = -1073741823L ;
    while ( true ) {
	
      getpreambletoken () ;
      if ( curcmd == 6 ) 
      goto lab31 ;
      if ( ( curcmd <= 5 ) && ( curcmd >= 4 ) && ( alignstate == -1000000L ) ) 
      {
	if ( ( p == memtop - 4 ) && ( curloop == -1073741823L ) && ( curcmd == 
	4 ) ) 
	curloop = curalign ;
	else {
	    
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 1004 ) ;
	  } 
	  {
	    helpptr = 3 ;
	    helpline [2 ]= 1005 ;
	    helpline [1 ]= 1006 ;
	    helpline [0 ]= 1007 ;
	  } 
	  backerror () ;
	  goto lab31 ;
	} 
      } 
      else if ( ( curcmd != 10 ) || ( p != memtop - 4 ) ) 
      {
	mem [p ].hh .v.RH = getavail () ;
	p = mem [p ].hh .v.RH ;
	mem [p ].hh .v.LH = curtok ;
      } 
    } 
    lab31: ;
    mem [curalign ].hh .v.RH = newnullbox () ;
    curalign = mem [curalign ].hh .v.RH ;
    mem [curalign ].hh .v.LH = memtop - 9 ;
    mem [curalign + 1 ].cint = -1073741824L ;
    mem [curalign + 3 ].cint = mem [memtop - 4 ].hh .v.RH ;
    p = memtop - 4 ;
    mem [p ].hh .v.RH = -1073741823L ;
    while ( true ) {
	
      lab22: getpreambletoken () ;
      if ( ( curcmd <= 5 ) && ( curcmd >= 4 ) && ( alignstate == -1000000L ) ) 
      goto lab32 ;
      if ( curcmd == 6 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1008 ) ;
	} 
	{
	  helpptr = 3 ;
	  helpline [2 ]= 1005 ;
	  helpline [1 ]= 1006 ;
	  helpline [0 ]= 1009 ;
	} 
	error () ;
	goto lab22 ;
      } 
      mem [p ].hh .v.RH = getavail () ;
      p = mem [p ].hh .v.RH ;
      mem [p ].hh .v.LH = curtok ;
    } 
    lab32: mem [p ].hh .v.RH = getavail () ;
    p = mem [p ].hh .v.RH ;
    mem [p ].hh .v.LH = 536886430L ;
    mem [curalign + 2 ].cint = mem [memtop - 4 ].hh .v.RH ;
  } 
  lab30: scannerstatus = 0 ;
  newsavelevel ( 6 ) ;
  if ( eqtb [25069 ].hh .v.RH != -1073741823L ) 
  begintokenlist ( eqtb [25069 ].hh .v.RH , 13 ) ;
  alignpeek () ;
} 
void 
zinitspan ( halfword p ) 
{
  initspan_regmem 
  pushnest () ;
  if ( curlist .modefield == -118 ) 
  curlist .auxfield .hh .v.LH = 1000 ;
  else {
      
    curlist .auxfield .cint = -65536000L ;
    normalparagraph () ;
  } 
  curspan = p ;
} 
void 
initrow ( void ) 
{
  initrow_regmem 
  pushnest () ;
  curlist .modefield = ( -119 ) - curlist .modefield ;
  if ( curlist .modefield == -118 ) 
  curlist .auxfield .hh .v.LH = 0 ;
  else curlist .auxfield .cint = 0 ;
  {
    mem [curlist .tailfield ].hh .v.RH = newglue ( mem [mem [memtop - 8 ]
    .hh .v.RH + 1 ].hh .v.LH ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  mem [curlist .tailfield ].hh.b1 = 12 ;
  curalign = mem [mem [memtop - 8 ].hh .v.RH ].hh .v.RH ;
  curtail = curhead ;
  initspan ( curalign ) ;
} 
void 
initcol ( void ) 
{
  initcol_regmem 
  mem [curalign + 5 ].hh .v.LH = curcmd ;
  if ( curcmd == 68 ) 
  alignstate = 0 ;
  else {
      
    backinput () ;
    begintokenlist ( mem [curalign + 3 ].cint , 1 ) ;
  } 
} 
boolean 
fincol ( void ) 
{
  /* 10 */ register boolean Result; fincol_regmem 
  halfword p  ;
  halfword q, r  ;
  halfword s  ;
  halfword u  ;
  scaled w  ;
  glueord o  ;
  halfword n  ;
  if ( curalign == -1073741823L ) 
  confusion ( 1010 ) ;
  q = mem [curalign ].hh .v.RH ;
  if ( q == -1073741823L ) 
  confusion ( 1010 ) ;
  if ( alignstate < 500000L ) 
  fatalerror ( 650 ) ;
  p = mem [q ].hh .v.RH ;
  if ( ( p == -1073741823L ) && ( mem [curalign + 5 ].hh .v.LH < 257 ) ) {
      
    if ( curloop != -1073741823L ) 
    {
      mem [q ].hh .v.RH = newnullbox () ;
      p = mem [q ].hh .v.RH ;
      mem [p ].hh .v.LH = memtop - 9 ;
      mem [p + 1 ].cint = -1073741824L ;
      curloop = mem [curloop ].hh .v.RH ;
      q = memtop - 4 ;
      r = mem [curloop + 3 ].cint ;
      while ( r != -1073741823L ) {
	  
	mem [q ].hh .v.RH = getavail () ;
	q = mem [q ].hh .v.RH ;
	mem [q ].hh .v.LH = mem [r ].hh .v.LH ;
	r = mem [r ].hh .v.RH ;
      } 
      mem [q ].hh .v.RH = -1073741823L ;
      mem [p + 3 ].cint = mem [memtop - 4 ].hh .v.RH ;
      q = memtop - 4 ;
      r = mem [curloop + 2 ].cint ;
      while ( r != -1073741823L ) {
	  
	mem [q ].hh .v.RH = getavail () ;
	q = mem [q ].hh .v.RH ;
	mem [q ].hh .v.LH = mem [r ].hh .v.LH ;
	r = mem [r ].hh .v.RH ;
      } 
      mem [q ].hh .v.RH = -1073741823L ;
      mem [p + 2 ].cint = mem [memtop - 4 ].hh .v.RH ;
      curloop = mem [curloop ].hh .v.RH ;
      mem [p ].hh .v.RH = newglue ( mem [curloop + 1 ].hh .v.LH ) ;
    } 
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1011 ) ;
      } 
      printesc ( 1000 ) ;
      {
	helpptr = 3 ;
	helpline [2 ]= 1012 ;
	helpline [1 ]= 1013 ;
	helpline [0 ]= 1014 ;
      } 
      mem [curalign + 5 ].hh .v.LH = 257 ;
      error () ;
    } 
  } 
  if ( mem [curalign + 5 ].hh .v.LH != 256 ) 
  {
    unsave () ;
    newsavelevel ( 6 ) ;
    {
      if ( curlist .modefield == -118 ) 
      {
	adjusttail = curtail ;
	adjusthlist ( curlist .headfield , false ) ;
	deleteglueref ( curkanjiskip ) ;
	deleteglueref ( curxkanjiskip ) ;
	curkanjiskip = mem [curlist .headfield + 7 ].hh .v.RH ;
	curxkanjiskip = mem [curlist .headfield + 7 ].hh .v.LH ;
	incr ( mem [curkanjiskip ].hh .v.RH ) ;
	incr ( mem [curxkanjiskip ].hh .v.RH ) ;
	u = hpack ( mem [curlist .headfield ].hh .v.RH , 0 , 1 ) ;
	w = mem [u + 1 ].cint ;
	curtail = adjusttail ;
	adjusttail = -1073741823L ;
      } 
      else {
	  
	u = vpackage ( mem [curlist .headfield ].hh .v.RH , 0 , 1 , 0 ) ;
	w = mem [u + 3 ].cint ;
      } 
      n = 0 ;
      if ( curspan != curalign ) 
      {
	q = curspan ;
	do {
	    incr ( n ) ;
	  q = mem [mem [q ].hh .v.RH ].hh .v.RH ;
	} while ( ! ( q == curalign ) ) ;
	if ( n > 65535L ) 
	confusion ( 1015 ) ;
	q = curspan ;
	while ( mem [mem [q ].hh .v.LH ].hh .v.RH < n ) q = mem [q ].hh 
	.v.LH ;
	if ( mem [mem [q ].hh .v.LH ].hh .v.RH > n ) 
	{
	  s = getnode ( 2 ) ;
	  mem [s ].hh .v.LH = mem [q ].hh .v.LH ;
	  mem [s ].hh .v.RH = n ;
	  mem [q ].hh .v.LH = s ;
	  mem [s + 1 ].cint = w ;
	} 
	else if ( mem [mem [q ].hh .v.LH + 1 ].cint < w ) 
	mem [mem [q ].hh .v.LH + 1 ].cint = w ;
      } 
      else if ( w > mem [curalign + 1 ].cint ) 
      mem [curalign + 1 ].cint = w ;
      mem [u ].hh.b0 = 15 ;
      mem [u ].hh.b1 = n ;
      if ( totalstretch [4 ]!= 0 ) 
      o = 4 ;
      else if ( totalstretch [3 ]!= 0 ) 
      o = 3 ;
      else if ( totalstretch [2 ]!= 0 ) 
      o = 2 ;
      else if ( totalstretch [1 ]!= 0 ) 
      o = 1 ;
      else o = 0 ;
      mem [u + 5 ].hh.b1 = o ;
      mem [u + 6 ].cint = totalstretch [o ];
      if ( totalshrink [4 ]!= 0 ) 
      o = 4 ;
      else if ( totalshrink [3 ]!= 0 ) 
      o = 3 ;
      else if ( totalshrink [2 ]!= 0 ) 
      o = 2 ;
      else if ( totalshrink [1 ]!= 0 ) 
      o = 1 ;
      else o = 0 ;
      mem [u + 5 ].hh.b0 = o ;
      mem [u + 4 ].cint = totalshrink [o ];
      popnest () ;
      mem [curlist .tailfield ].hh .v.RH = u ;
      curlist .tailfield = u ;
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = newglue ( mem [mem [curalign ]
      .hh .v.RH + 1 ].hh .v.LH ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    mem [curlist .tailfield ].hh.b1 = 12 ;
    if ( mem [curalign + 5 ].hh .v.LH >= 257 ) 
    {
      Result = true ;
      return Result ;
    } 
    initspan ( p ) ;
  } 
  alignstate = 1000000L ;
  do {
      getxorprotected () ;
  } while ( ! ( curcmd != 10 ) ) ;
  curalign = p ;
  initcol () ;
  Result = false ;
  return Result ;
} 
void 
finrow ( void ) 
{
  finrow_regmem 
  halfword p  ;
  if ( curlist .modefield == -118 ) 
  {
    adjusthlist ( curlist .headfield , false ) ;
    deleteglueref ( curkanjiskip ) ;
    deleteglueref ( curxkanjiskip ) ;
    curkanjiskip = mem [curlist .headfield + 7 ].hh .v.RH ;
    curxkanjiskip = mem [curlist .headfield + 7 ].hh .v.LH ;
    incr ( mem [curkanjiskip ].hh .v.RH ) ;
    incr ( mem [curxkanjiskip ].hh .v.RH ) ;
    p = hpack ( mem [curlist .headfield ].hh .v.RH , 0 , 1 ) ;
    popnest () ;
    appendtovlist ( p ) ;
    if ( curhead != curtail ) 
    {
      mem [curlist .tailfield ].hh .v.RH = mem [curhead ].hh .v.RH ;
      curlist .tailfield = curtail ;
    } 
  } 
  else {
      
    p = vpackage ( mem [curlist .headfield ].hh .v.RH , 0 , 1 , 1073741823L 
    ) ;
    popnest () ;
    mem [curlist .tailfield ].hh .v.RH = p ;
    curlist .tailfield = p ;
    curlist .auxfield .hh .v.LH = 1000 ;
  } 
  mem [p ].hh.b0 = 15 ;
  mem [p + 6 ].cint = 0 ;
  if ( eqtb [25069 ].hh .v.RH != -1073741823L ) 
  begintokenlist ( eqtb [25069 ].hh .v.RH , 13 ) ;
  alignpeek () ;
} 
void 
finalign ( void ) 
{
  finalign_regmem 
  halfword p, q, r, s, u, v, z  ;
  scaled t, w  ;
  scaled o  ;
  halfword n  ;
  scaled rulesave  ;
  memoryword auxsave  ;
  if ( curgroup != 6 ) 
  confusion ( 1016 ) ;
  unsave () ;
  if ( curgroup != 6 ) 
  confusion ( 1017 ) ;
  unsave () ;
  if ( nest [nestptr - 1 ].modefield == 235 ) 
  o = eqtb [29789 ].cint ;
  else o = 0 ;
  q = mem [mem [memtop - 8 ].hh .v.RH ].hh .v.RH ;
  do {
      flushlist ( mem [q + 3 ].cint ) ;
    flushlist ( mem [q + 2 ].cint ) ;
    p = mem [mem [q ].hh .v.RH ].hh .v.RH ;
    if ( mem [q + 1 ].cint == -1073741824L ) 
    {
      mem [q + 1 ].cint = 0 ;
      r = mem [q ].hh .v.RH ;
      s = mem [r + 1 ].hh .v.LH ;
      if ( s != membot ) 
      {
	incr ( mem [membot ].hh .v.RH ) ;
	deleteglueref ( s ) ;
	mem [r + 1 ].hh .v.LH = membot ;
      } 
    } 
    if ( mem [q ].hh .v.LH != memtop - 9 ) 
    {
      t = mem [q + 1 ].cint + mem [mem [mem [q ].hh .v.RH + 1 ].hh 
      .v.LH + 1 ].cint ;
      r = mem [q ].hh .v.LH ;
      s = memtop - 9 ;
      mem [s ].hh .v.LH = p ;
      n = 1 ;
      do {
	  mem [r + 1 ].cint = mem [r + 1 ].cint - t ;
	u = mem [r ].hh .v.LH ;
	while ( mem [r ].hh .v.RH > n ) {
	    
	  s = mem [s ].hh .v.LH ;
	  n = mem [mem [s ].hh .v.LH ].hh .v.RH + 1 ;
	} 
	if ( mem [r ].hh .v.RH < n ) 
	{
	  mem [r ].hh .v.LH = mem [s ].hh .v.LH ;
	  mem [s ].hh .v.LH = r ;
	  decr ( mem [r ].hh .v.RH ) ;
	  s = r ;
	} 
	else {
	    
	  if ( mem [r + 1 ].cint > mem [mem [s ].hh .v.LH + 1 ].cint ) 
	  mem [mem [s ].hh .v.LH + 1 ].cint = mem [r + 1 ].cint ;
	  freenode ( r , 2 ) ;
	} 
	r = u ;
      } while ( ! ( r == memtop - 9 ) ) ;
    } 
    mem [q ].hh.b0 = 15 ;
    mem [q ].hh.b1 = 0 ;
    mem [q + 3 ].cint = 0 ;
    mem [q + 2 ].cint = 0 ;
    mem [q + 5 ].hh.b1 = 0 ;
    mem [q + 5 ].hh.b0 = 0 ;
    mem [q + 6 ].cint = 0 ;
    mem [q + 4 ].cint = 0 ;
    q = p ;
  } while ( ! ( q == -1073741823L ) ) ;
  saveptr = saveptr - 2 ;
  packbeginline = - (integer) curlist .mlfield ;
  if ( curlist .modefield == -1 ) 
  {
    rulesave = eqtb [29790 ].cint ;
    eqtb [29790 ].cint = 0 ;
    z = newnullbox () ;
    mem [z ].hh .v.RH = mem [memtop - 8 ].hh .v.RH ;
    adjusthlist ( z , false ) ;
    deleteglueref ( curkanjiskip ) ;
    deleteglueref ( curxkanjiskip ) ;
    curkanjiskip = mem [z + 7 ].hh .v.RH ;
    curxkanjiskip = mem [z + 7 ].hh .v.LH ;
    incr ( mem [curkanjiskip ].hh .v.RH ) ;
    incr ( mem [curxkanjiskip ].hh .v.RH ) ;
    p = hpack ( mem [memtop - 8 ].hh .v.RH , savestack [saveptr + 1 ].cint 
    , savestack [saveptr + 0 ].cint ) ;
    eqtb [29790 ].cint = rulesave ;
    deleteglueref ( mem [z + 7 ].hh .v.RH ) ;
    deleteglueref ( mem [z + 7 ].hh .v.LH ) ;
    freenode ( z , 10 ) ;
  } 
  else {
      
    q = mem [mem [memtop - 8 ].hh .v.RH ].hh .v.RH ;
    do {
	mem [q + 3 ].cint = mem [q + 1 ].cint ;
      mem [q + 1 ].cint = 0 ;
      q = mem [mem [q ].hh .v.RH ].hh .v.RH ;
    } while ( ! ( q == -1073741823L ) ) ;
    p = vpackage ( mem [memtop - 8 ].hh .v.RH , savestack [saveptr + 1 ]
    .cint , savestack [saveptr + 0 ].cint , 1073741823L ) ;
    q = mem [mem [memtop - 8 ].hh .v.RH ].hh .v.RH ;
    do {
	mem [q + 1 ].cint = mem [q + 3 ].cint ;
      mem [q + 3 ].cint = 0 ;
      q = mem [mem [q ].hh .v.RH ].hh .v.RH ;
    } while ( ! ( q == -1073741823L ) ) ;
  } 
  packbeginline = 0 ;
  q = mem [curlist .headfield ].hh .v.RH ;
  s = curlist .headfield ;
  while ( q != -1073741823L ) {
      
    if ( ! ( q >= himemmin ) ) {
	
      if ( mem [q ].hh.b0 == 15 ) 
      {
	if ( curlist .modefield == -1 ) 
	{
	  mem [q ].hh.b0 = 0 ;
	  mem [q + 1 ].cint = mem [p + 1 ].cint ;
	  if ( nest [nestptr - 1 ].modefield == 235 ) 
	  mem [q ].hh.b1 = ( ( mem [q ].hh.b1 ) % 8 ) + 8 * ( 2 ) ;
	} 
	else {
	    
	  mem [q ].hh.b0 = 1 ;
	  mem [q + 3 ].cint = mem [p + 3 ].cint ;
	} 
	mem [q ].hh.b1 = ( ( mem [q ].hh.b1 ) / 8 ) * 8 + abs ( curlist 
	.dirfield ) ;
	mem [q + 5 ].hh.b1 = mem [p + 5 ].hh.b1 ;
	mem [q + 5 ].hh.b0 = mem [p + 5 ].hh.b0 ;
	mem [q + 6 ].gr = mem [p + 6 ].gr ;
	mem [q + 4 ].cint = o ;
	r = mem [mem [q + 5 ].hh .v.RH ].hh .v.RH ;
	s = mem [mem [p + 5 ].hh .v.RH ].hh .v.RH ;
	do {
	    n = mem [r ].hh.b1 ;
	  t = mem [s + 1 ].cint ;
	  w = t ;
	  u = memtop - 4 ;
	  mem [r ].hh.b1 = ( ( mem [r ].hh.b1 ) % 8 ) + 8 * ( 0 ) ;
	  while ( n > 0 ) {
	      
	    decr ( n ) ;
	    s = mem [s ].hh .v.RH ;
	    v = mem [s + 1 ].hh .v.LH ;
	    mem [u ].hh .v.RH = newglue ( v ) ;
	    u = mem [u ].hh .v.RH ;
	    mem [u ].hh.b1 = 12 ;
	    t = t + mem [v + 1 ].cint ;
	    if ( mem [p + 5 ].hh.b0 == 1 ) 
	    {
	      if ( mem [v ].hh.b0 == mem [p + 5 ].hh.b1 ) 
	      t = t + round ( mem [p + 6 ].gr * mem [v + 2 ].cint ) ;
	    } 
	    else if ( mem [p + 5 ].hh.b0 == 2 ) 
	    {
	      if ( mem [v ].hh.b1 == mem [p + 5 ].hh.b1 ) 
	      t = t - round ( mem [p + 6 ].gr * mem [v + 3 ].cint ) ;
	    } 
	    s = mem [s ].hh .v.RH ;
	    mem [u ].hh .v.RH = newnullbox () ;
	    u = mem [u ].hh .v.RH ;
	    t = t + mem [s + 1 ].cint ;
	    if ( curlist .modefield == -1 ) 
	    mem [u + 1 ].cint = mem [s + 1 ].cint ;
	    else {
		
	      mem [u ].hh.b0 = 1 ;
	      mem [u + 3 ].cint = mem [s + 1 ].cint ;
	    } 
	    mem [u ].hh.b1 = ( ( mem [u ].hh.b1 ) / 8 ) * 8 + abs ( 
	    curlist .dirfield ) ;
	  } 
	  if ( curlist .modefield == -1 ) 
	  {
	    mem [r + 3 ].cint = mem [q + 3 ].cint ;
	    mem [r + 2 ].cint = mem [q + 2 ].cint ;
	    if ( t == mem [r + 1 ].cint ) 
	    {
	      mem [r + 5 ].hh.b0 = 0 ;
	      mem [r + 5 ].hh.b1 = 0 ;
	      mem [r + 6 ].gr = 0.0 ;
	    } 
	    else if ( t > mem [r + 1 ].cint ) 
	    {
	      mem [r + 5 ].hh.b0 = 1 ;
	      if ( mem [r + 6 ].cint == 0 ) 
	      mem [r + 6 ].gr = 0.0 ;
	      else mem [r + 6 ].gr = ( t - mem [r + 1 ].cint ) / ((double) 
	      mem [r + 6 ].cint ) ;
	    } 
	    else {
		
	      mem [r + 5 ].hh.b1 = mem [r + 5 ].hh.b0 ;
	      mem [r + 5 ].hh.b0 = 2 ;
	      if ( mem [r + 4 ].cint == 0 ) 
	      mem [r + 6 ].gr = 0.0 ;
	      else if ( ( mem [r + 5 ].hh.b1 == 0 ) && ( mem [r + 1 ].cint 
	      - t > mem [r + 4 ].cint ) ) 
	      mem [r + 6 ].gr = 1.0 ;
	      else mem [r + 6 ].gr = ( mem [r + 1 ].cint - t ) / ((double) 
	      mem [r + 4 ].cint ) ;
	    } 
	    mem [r + 1 ].cint = w ;
	    mem [r ].hh.b0 = 0 ;
	    mem [r ].hh.b1 = ( ( mem [r ].hh.b1 ) / 8 ) * 8 + abs ( 
	    curlist .dirfield ) ;
	  } 
	  else {
	      
	    mem [r + 1 ].cint = mem [q + 1 ].cint ;
	    if ( t == mem [r + 3 ].cint ) 
	    {
	      mem [r + 5 ].hh.b0 = 0 ;
	      mem [r + 5 ].hh.b1 = 0 ;
	      mem [r + 6 ].gr = 0.0 ;
	    } 
	    else if ( t > mem [r + 3 ].cint ) 
	    {
	      mem [r + 5 ].hh.b0 = 1 ;
	      if ( mem [r + 6 ].cint == 0 ) 
	      mem [r + 6 ].gr = 0.0 ;
	      else mem [r + 6 ].gr = ( t - mem [r + 3 ].cint ) / ((double) 
	      mem [r + 6 ].cint ) ;
	    } 
	    else {
		
	      mem [r + 5 ].hh.b1 = mem [r + 5 ].hh.b0 ;
	      mem [r + 5 ].hh.b0 = 2 ;
	      if ( mem [r + 4 ].cint == 0 ) 
	      mem [r + 6 ].gr = 0.0 ;
	      else if ( ( mem [r + 5 ].hh.b1 == 0 ) && ( mem [r + 3 ].cint 
	      - t > mem [r + 4 ].cint ) ) 
	      mem [r + 6 ].gr = 1.0 ;
	      else mem [r + 6 ].gr = ( mem [r + 3 ].cint - t ) / ((double) 
	      mem [r + 4 ].cint ) ;
	    } 
	    mem [r + 3 ].cint = w ;
	    mem [r ].hh.b0 = 1 ;
	    mem [r ].hh.b1 = ( ( mem [r ].hh.b1 ) / 8 ) * 8 + abs ( 
	    curlist .dirfield ) ;
	  } 
	  mem [r + 4 ].cint = 0 ;
	  if ( u != memtop - 4 ) 
	  {
	    mem [u ].hh .v.RH = mem [r ].hh .v.RH ;
	    mem [r ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
	    r = u ;
	  } 
	  r = mem [mem [r ].hh .v.RH ].hh .v.RH ;
	  s = mem [mem [s ].hh .v.RH ].hh .v.RH ;
	} while ( ! ( r == -1073741823L ) ) ;
      } 
      else if ( mem [q ].hh.b0 == 3 ) 
      {
	if ( ( mem [q + 1 ].cint == -1073741824L ) ) 
	mem [q + 1 ].cint = mem [p + 1 ].cint ;
	if ( ( mem [q + 3 ].cint == -1073741824L ) ) 
	mem [q + 3 ].cint = mem [p + 3 ].cint ;
	if ( ( mem [q + 2 ].cint == -1073741824L ) ) 
	mem [q + 2 ].cint = mem [p + 2 ].cint ;
	if ( o != 0 ) 
	{
	  r = mem [q ].hh .v.RH ;
	  mem [q ].hh .v.RH = -1073741823L ;
	  q = hpack ( q , 0 , 1 ) ;
	  mem [q + 4 ].cint = o ;
	  mem [q ].hh .v.RH = r ;
	  mem [s ].hh .v.RH = q ;
	} 
      } 
    } 
    s = q ;
    q = mem [q ].hh .v.RH ;
  } 
  flushnodelist ( p ) ;
  popalignment () ;
  auxsave = curlist .auxfield ;
  p = mem [curlist .headfield ].hh .v.RH ;
  q = curlist .tailfield ;
  popnest () ;
  if ( curlist .modefield == 235 ) 
  {
    doassignments () ;
    if ( curcmd != 3 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1298 ) ;
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 996 ;
	helpline [0 ]= 997 ;
      } 
      backerror () ;
    } 
    else {
	
      getxtoken () ;
      if ( curcmd != 3 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1294 ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1295 ;
	  helpline [0 ]= 1296 ;
	} 
	backerror () ;
      } 
    } 
    flushnodelist ( curlist .eTeXauxfield ) ;
    popnest () ;
    {
      mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [29199 ].cint 
      ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = newparamglue ( 3 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    mem [curlist .tailfield ].hh .v.RH = p ;
    if ( p != -1073741823L ) 
    curlist .tailfield = q ;
    {
      mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [29200 ].cint 
      ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = newparamglue ( 4 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    curlist .auxfield .cint = auxsave .cint ;
    resumeafterdisplay () ;
  } 
  else {
      
    curlist .auxfield = auxsave ;
    mem [curlist .tailfield ].hh .v.RH = p ;
    if ( p != -1073741823L ) 
    curlist .tailfield = q ;
    if ( curlist .modefield == 1 ) 
    buildpage () ;
  } 
} 
void 
alignpeek ( void ) 
{
  /* 20 */ alignpeek_regmem 
  lab20: alignstate = 1000000L ;
  do {
      getxorprotected () ;
  } while ( ! ( curcmd != 10 ) ) ;
  if ( curcmd == 38 ) 
  {
    scanleftbrace () ;
    newsavelevel ( 7 ) ;
    if ( curlist .modefield == -1 ) 
    normalparagraph () ;
  } 
  else if ( curcmd == 2 ) 
  finalign () ;
  else if ( ( curcmd == 5 ) && ( curchr == 258 ) ) 
  goto lab20 ;
  else {
      
    initrow () ;
    initcol () ;
  } 
} 
halfword 
zfiniteshrink ( halfword p ) 
{
  register halfword Result; finiteshrink_regmem 
  halfword q  ;
  if ( noshrinkerroryet ) 
  {
    noshrinkerroryet = false ;
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1018 ) ;
    } 
    {
      helpptr = 5 ;
      helpline [4 ]= 1019 ;
      helpline [3 ]= 1020 ;
      helpline [2 ]= 1021 ;
      helpline [1 ]= 1022 ;
      helpline [0 ]= 1023 ;
    } 
    error () ;
  } 
  q = newspec ( p ) ;
  mem [q ].hh.b1 = 0 ;
  deleteglueref ( p ) ;
  Result = q ;
  return Result ;
} 
void 
ztrybreak ( integer pi , smallnumber breaktype ) 
{
  /* 10 30 31 22 60 40 45 */ trybreak_regmem 
  halfword r  ;
  halfword prevr  ;
  halfword oldl  ;
  boolean nobreakyet  ;
  halfword prevprevr  ;
  halfword s  ;
  halfword q  ;
  halfword v  ;
  integer t  ;
  internalfontnumber f  ;
  halfword l  ;
  boolean noderstaysactive  ;
  scaled linewidth  ;
  unsigned char fitclass  ;
  halfword b  ;
  integer d  ;
  boolean artificialdemerits  ;
  halfword savelink  ;
  scaled shortfall  ;
  scaled g  ;
  if ( abs ( pi ) >= 10000 ) {
      
    if ( pi > 0 ) 
    goto lab10 ;
    else pi = -10000 ;
  } 
  nobreakyet = true ;
  prevr = memtop - 7 ;
  oldl = 0 ;
  curactivewidth [1 ]= activewidth [1 ];
  curactivewidth [2 ]= activewidth [2 ];
  curactivewidth [3 ]= activewidth [3 ];
  curactivewidth [4 ]= activewidth [4 ];
  curactivewidth [5 ]= activewidth [5 ];
  curactivewidth [6 ]= activewidth [6 ];
  curactivewidth [7 ]= activewidth [7 ];
  while ( true ) {
      
    lab22: r = mem [prevr ].hh .v.RH ;
    if ( mem [r ].hh.b0 == 2 ) 
    {
      curactivewidth [1 ]= curactivewidth [1 ]+ mem [r + 1 ].cint ;
      curactivewidth [2 ]= curactivewidth [2 ]+ mem [r + 2 ].cint ;
      curactivewidth [3 ]= curactivewidth [3 ]+ mem [r + 3 ].cint ;
      curactivewidth [4 ]= curactivewidth [4 ]+ mem [r + 4 ].cint ;
      curactivewidth [5 ]= curactivewidth [5 ]+ mem [r + 5 ].cint ;
      curactivewidth [6 ]= curactivewidth [6 ]+ mem [r + 6 ].cint ;
      curactivewidth [7 ]= curactivewidth [7 ]+ mem [r + 7 ].cint ;
      prevprevr = prevr ;
      prevr = r ;
      goto lab22 ;
    } 
    {
      l = mem [r + 1 ].hh .v.LH ;
      if ( l > oldl ) 
      {
	if ( ( minimumdemerits < 1073741823L ) && ( ( oldl != easyline ) || ( 
	r == memtop - 7 ) ) ) 
	{
	  if ( nobreakyet ) 
	  {
	    nobreakyet = false ;
	    breakwidth [1 ]= background [1 ];
	    breakwidth [2 ]= background [2 ];
	    breakwidth [3 ]= background [3 ];
	    breakwidth [4 ]= background [4 ];
	    breakwidth [5 ]= background [5 ];
	    breakwidth [6 ]= background [6 ];
	    breakwidth [7 ]= background [7 ];
	    s = curp ;
	    if ( breaktype > 0 ) {
		
	      if ( curp != -1073741823L ) 
	      {
		t = mem [curp ].hh.b1 ;
		v = curp ;
		s = mem [curp + 1 ].hh .v.RH ;
		while ( t > 0 ) {
		    
		  decr ( t ) ;
		  v = mem [v ].hh .v.RH ;
		  if ( ( v >= himemmin ) ) 
		  {
		    f = mem [v ].hh.b0 ;
		    breakwidth [1 ]= breakwidth [1 ]- fontinfo [widthbase 
		    [f ]+ fontinfo [charbase [f ]+ mem [v ].hh.b1 ]
		    .qqqq .b0 ].cint ;
		    if ( fontdir [f ]!= 0 ) 
		    v = mem [v ].hh .v.RH ;
		  } 
		  else switch ( mem [v ].hh.b0 ) 
		  {case 8 : 
		    {
		      f = mem [v + 1 ].hh.b0 ;
		      breakwidth [1 ]= breakwidth [1 ]- fontinfo [
		      widthbase [f ]+ fontinfo [charbase [f ]+ mem [v + 
		      1 ].hh.b1 ].qqqq .b0 ].cint ;
		    } 
		    break ;
		  case 0 : 
		  case 1 : 
		  case 2 : 
		  case 3 : 
		  case 13 : 
		    breakwidth [1 ]= breakwidth [1 ]- mem [v + 1 ].cint 
		    ;
		    break ;
		  case 5 : 
		    ;
		    break ;
		    default: 
		    confusion ( 1024 ) ;
		    break ;
		  } 
		} 
		while ( s != -1073741823L ) {
		    
		  if ( ( s >= himemmin ) ) 
		  {
		    f = mem [s ].hh.b0 ;
		    breakwidth [1 ]= breakwidth [1 ]+ fontinfo [widthbase 
		    [f ]+ fontinfo [charbase [f ]+ mem [s ].hh.b1 ]
		    .qqqq .b0 ].cint ;
		    if ( fontdir [f ]!= 0 ) 
		    s = mem [s ].hh .v.RH ;
		  } 
		  else switch ( mem [s ].hh.b0 ) 
		  {case 8 : 
		    {
		      f = mem [s + 1 ].hh.b0 ;
		      breakwidth [1 ]= breakwidth [1 ]+ fontinfo [
		      widthbase [f ]+ fontinfo [charbase [f ]+ mem [s + 
		      1 ].hh.b1 ].qqqq .b0 ].cint ;
		    } 
		    break ;
		  case 0 : 
		  case 1 : 
		  case 2 : 
		  case 3 : 
		  case 13 : 
		    breakwidth [1 ]= breakwidth [1 ]+ mem [s + 1 ].cint 
		    ;
		    break ;
		  case 5 : 
		    ;
		    break ;
		    default: 
		    confusion ( 1025 ) ;
		    break ;
		  } 
		  s = mem [s ].hh .v.RH ;
		} 
		breakwidth [1 ]= breakwidth [1 ]+ discwidth ;
		if ( mem [curp + 1 ].hh .v.RH == -1073741823L ) 
		s = mem [v ].hh .v.RH ;
	      } 
	    } 
	    while ( s != -1073741823L ) {
		
	      if ( ( s >= himemmin ) ) 
	      {
		if ( chain ) 
		{
		  breakwidth [1 ]= breakwidth [1 ]- mem [curkanjiskip + 1 
		  ].cint ;
		  breakwidth [2 + mem [curkanjiskip ].hh.b0 ]= breakwidth 
		  [2 + mem [curkanjiskip ].hh.b0 ]- mem [curkanjiskip + 2 
		  ].cint ;
		  breakwidth [7 ]= breakwidth [7 ]- mem [curkanjiskip + 3 
		  ].cint ;
		} 
		goto lab30 ;
	      } 
	      switch ( mem [s ].hh.b0 ) 
	      {case 12 : 
		{
		  v = mem [s + 1 ].hh .v.LH ;
		  breakwidth [1 ]= breakwidth [1 ]- mem [v + 1 ].cint ;
		  breakwidth [2 + mem [v ].hh.b0 ]= breakwidth [2 + mem [
		  v ].hh.b0 ]- mem [v + 2 ].cint ;
		  breakwidth [7 ]= breakwidth [7 ]- mem [v + 3 ].cint ;
		} 
		break ;
	      case 14 : 
		;
		break ;
	      case 11 : 
		breakwidth [1 ]= breakwidth [1 ]- mem [s + 1 ].cint ;
		break ;
	      case 13 : 
		if ( ( mem [s ].hh.b1 != 1 ) && ( mem [s ].hh.b1 != 3 ) ) 
		goto lab30 ;
		else breakwidth [1 ]= breakwidth [1 ]- mem [s + 1 ].cint 
		;
		break ;
		default: 
		goto lab30 ;
		break ;
	      } 
	      s = mem [s ].hh .v.RH ;
	    } 
	    lab30: ;
	  } 
	  if ( mem [prevr ].hh.b0 == 2 ) 
	  {
	    mem [prevr + 1 ].cint = mem [prevr + 1 ].cint - curactivewidth 
	    [1 ]+ breakwidth [1 ];
	    mem [prevr + 2 ].cint = mem [prevr + 2 ].cint - curactivewidth 
	    [2 ]+ breakwidth [2 ];
	    mem [prevr + 3 ].cint = mem [prevr + 3 ].cint - curactivewidth 
	    [3 ]+ breakwidth [3 ];
	    mem [prevr + 4 ].cint = mem [prevr + 4 ].cint - curactivewidth 
	    [4 ]+ breakwidth [4 ];
	    mem [prevr + 5 ].cint = mem [prevr + 5 ].cint - curactivewidth 
	    [5 ]+ breakwidth [5 ];
	    mem [prevr + 6 ].cint = mem [prevr + 6 ].cint - curactivewidth 
	    [6 ]+ breakwidth [6 ];
	    mem [prevr + 7 ].cint = mem [prevr + 7 ].cint - curactivewidth 
	    [7 ]+ breakwidth [7 ];
	  } 
	  else if ( prevr == memtop - 7 ) 
	  {
	    activewidth [1 ]= breakwidth [1 ];
	    activewidth [2 ]= breakwidth [2 ];
	    activewidth [3 ]= breakwidth [3 ];
	    activewidth [4 ]= breakwidth [4 ];
	    activewidth [5 ]= breakwidth [5 ];
	    activewidth [6 ]= breakwidth [6 ];
	    activewidth [7 ]= breakwidth [7 ];
	  } 
	  else {
	      
	    q = getnode ( 8 ) ;
	    mem [q ].hh .v.RH = r ;
	    mem [q ].hh.b0 = 2 ;
	    mem [q ].hh.b1 = 0 ;
	    mem [q + 1 ].cint = breakwidth [1 ]- curactivewidth [1 ];
	    mem [q + 2 ].cint = breakwidth [2 ]- curactivewidth [2 ];
	    mem [q + 3 ].cint = breakwidth [3 ]- curactivewidth [3 ];
	    mem [q + 4 ].cint = breakwidth [4 ]- curactivewidth [4 ];
	    mem [q + 5 ].cint = breakwidth [5 ]- curactivewidth [5 ];
	    mem [q + 6 ].cint = breakwidth [6 ]- curactivewidth [6 ];
	    mem [q + 7 ].cint = breakwidth [7 ]- curactivewidth [7 ];
	    mem [prevr ].hh .v.RH = q ;
	    prevprevr = prevr ;
	    prevr = q ;
	  } 
	  if ( abs ( eqtb [29204 ].cint ) >= 1073741823L - minimumdemerits ) 
	  minimumdemerits = 1073741822L ;
	  else minimumdemerits = minimumdemerits + abs ( eqtb [29204 ].cint 
	  ) ;
	  {register integer for_end; fitclass = 0 ;for_end = 3 ; if ( 
	  fitclass <= for_end) do 
	    {
	      if ( minimaldemerits [fitclass ]<= minimumdemerits ) 
	      {
		q = getnode ( 2 ) ;
		mem [q ].hh .v.RH = passive ;
		passive = q ;
		mem [q + 1 ].hh .v.RH = curp ;
	;
#ifdef STAT
		incr ( passnumber ) ;
		mem [q ].hh .v.LH = passnumber ;
#endif /* STAT */
		mem [q + 1 ].hh .v.LH = bestplace [fitclass ];
		q = getnode ( activenodesize ) ;
		mem [q + 1 ].hh .v.RH = passive ;
		mem [q + 1 ].hh .v.LH = bestplline [fitclass ]+ 1 ;
		mem [q ].hh.b1 = fitclass ;
		mem [q ].hh.b0 = breaktype ;
		mem [q + 2 ].cint = minimaldemerits [fitclass ];
		if ( dolastlinefit ) 
		{
		  mem [q + 3 ].cint = bestplshort [fitclass ];
		  mem [q + 4 ].cint = bestplglue [fitclass ];
		} 
		mem [q ].hh .v.RH = r ;
		mem [prevr ].hh .v.RH = q ;
		prevr = q ;
	;
#ifdef STAT
		if ( eqtb [29220 ].cint > 0 ) 
		{
		  printnl ( 1026 ) ;
		  printint ( mem [passive ].hh .v.LH ) ;
		  print ( 1027 ) ;
		  printint ( mem [q + 1 ].hh .v.LH - 1 ) ;
		  printchar ( 46 ) ;
		  printint ( fitclass ) ;
		  if ( breaktype == 1 ) 
		  printchar ( 45 ) ;
		  print ( 1028 ) ;
		  printint ( mem [q + 2 ].cint ) ;
		  if ( dolastlinefit ) 
		  {
		    print ( 1556 ) ;
		    printscaled ( mem [q + 3 ].cint ) ;
		    if ( curp == -1073741823L ) 
		    print ( 1557 ) ;
		    else print ( 1099 ) ;
		    printscaled ( mem [q + 4 ].cint ) ;
		  } 
		  print ( 1029 ) ;
		  if ( mem [passive + 1 ].hh .v.LH == -1073741823L ) 
		  printchar ( 48 ) ;
		  else printint ( mem [mem [passive + 1 ].hh .v.LH ].hh 
		  .v.LH ) ;
		} 
#endif /* STAT */
	      } 
	      minimaldemerits [fitclass ]= 1073741823L ;
	    } 
	  while ( fitclass++ < for_end ) ;} 
	  minimumdemerits = 1073741823L ;
	  if ( r != memtop - 7 ) 
	  {
	    q = getnode ( 8 ) ;
	    mem [q ].hh .v.RH = r ;
	    mem [q ].hh.b0 = 2 ;
	    mem [q ].hh.b1 = 0 ;
	    mem [q + 1 ].cint = curactivewidth [1 ]- breakwidth [1 ];
	    mem [q + 2 ].cint = curactivewidth [2 ]- breakwidth [2 ];
	    mem [q + 3 ].cint = curactivewidth [3 ]- breakwidth [3 ];
	    mem [q + 4 ].cint = curactivewidth [4 ]- breakwidth [4 ];
	    mem [q + 5 ].cint = curactivewidth [5 ]- breakwidth [5 ];
	    mem [q + 6 ].cint = curactivewidth [6 ]- breakwidth [6 ];
	    mem [q + 7 ].cint = curactivewidth [7 ]- breakwidth [7 ];
	    mem [prevr ].hh .v.RH = q ;
	    prevprevr = prevr ;
	    prevr = q ;
	  } 
	} 
	if ( r == memtop - 7 ) 
	goto lab10 ;
	if ( l > easyline ) 
	{
	  linewidth = secondwidth ;
	  oldl = 1073741822L ;
	} 
	else {
	    
	  oldl = l ;
	  if ( l > lastspecialline ) 
	  linewidth = secondwidth ;
	  else if ( eqtb [25061 ].hh .v.RH == -1073741823L ) 
	  linewidth = firstwidth ;
	  else linewidth = mem [eqtb [25061 ].hh .v.RH + 2 * l ].cint ;
	} 
      } 
    } 
    {
      artificialdemerits = false ;
      shortfall = linewidth - curactivewidth [1 ];
      if ( shortfall > 0 ) {
	  
	if ( ( curactivewidth [3 ]!= 0 ) || ( curactivewidth [4 ]!= 0 ) || 
	( curactivewidth [5 ]!= 0 ) || ( curactivewidth [6 ]!= 0 ) ) 
	{
	  if ( dolastlinefit ) 
	  {
	    if ( curp == -1073741823L ) 
	    {
	      if ( ( mem [r + 3 ].cint == 0 ) || ( mem [r + 4 ].cint <= 0 
	      ) ) 
	      goto lab45 ;
	      if ( ( curactivewidth [3 ]!= fillwidth [0 ]) || ( 
	      curactivewidth [4 ]!= fillwidth [1 ]) || ( curactivewidth [
	      5 ]!= fillwidth [2 ]) || ( curactivewidth [6 ]!= fillwidth 
	      [3 ]) ) 
	      goto lab45 ;
	      if ( mem [r + 3 ].cint > 0 ) 
	      g = curactivewidth [2 ];
	      else g = curactivewidth [7 ];
	      if ( g <= 0 ) 
	      goto lab45 ;
	      aritherror = false ;
	      g = fract ( g , mem [r + 3 ].cint , mem [r + 4 ].cint , 
	      1073741823L ) ;
	      if ( eqtb [29258 ].cint < 1000 ) 
	      g = fract ( g , eqtb [29258 ].cint , 1000 , 1073741823L ) ;
	      if ( aritherror ) {
		  
		if ( mem [r + 3 ].cint > 0 ) 
		g = 1073741823L ;
		else g = -1073741823L ;
	      } 
	      if ( g > 0 ) 
	      {
		if ( g > shortfall ) 
		g = shortfall ;
		if ( g > 7230584L ) {
		    
		  if ( curactivewidth [2 ]< 1663497L ) 
		  {
		    b = 10000 ;
		    fitclass = 0 ;
		    goto lab40 ;
		  } 
		} 
		b = badness ( g , curactivewidth [2 ]) ;
		if ( b > 12 ) {
		    
		  if ( b > 99 ) 
		  fitclass = 0 ;
		  else fitclass = 1 ;
		} 
		else fitclass = 2 ;
		goto lab40 ;
	      } 
	      else if ( g < 0 ) 
	      {
		if ( - (integer) g > curactivewidth [7 ]) 
		g = - (integer) curactivewidth [7 ];
		b = badness ( - (integer) g , curactivewidth [7 ]) ;
		if ( b > 12 ) 
		fitclass = 3 ;
		else fitclass = 2 ;
		goto lab40 ;
	      } 
	      lab45: ;
	    } 
	    shortfall = 0 ;
	  } 
	  b = 0 ;
	  fitclass = 2 ;
	} 
	else {
	    
	  if ( shortfall > 7230584L ) {
	      
	    if ( curactivewidth [2 ]< 1663497L ) 
	    {
	      b = 10000 ;
	      fitclass = 0 ;
	      goto lab31 ;
	    } 
	  } 
	  b = badness ( shortfall , curactivewidth [2 ]) ;
	  if ( b > 12 ) {
	      
	    if ( b > 99 ) 
	    fitclass = 0 ;
	    else fitclass = 1 ;
	  } 
	  else fitclass = 2 ;
	  lab31: ;
	} 
      } 
      else {
	  
	if ( - (integer) shortfall > curactivewidth [7 ]) 
	b = 10001 ;
	else b = badness ( - (integer) shortfall , curactivewidth [7 ]) ;
	if ( b > 12 ) 
	fitclass = 3 ;
	else fitclass = 2 ;
      } 
      if ( dolastlinefit ) 
      {
	if ( curp == -1073741823L ) 
	shortfall = 0 ;
	if ( shortfall > 0 ) 
	g = curactivewidth [2 ];
	else if ( shortfall < 0 ) 
	g = curactivewidth [7 ];
	else g = 0 ;
      } 
      lab40: if ( ( b > 10000 ) || ( pi == -10000 ) ) 
      {
	if ( finalpass && ( minimumdemerits == 1073741823L ) && ( mem [r ]
	.hh .v.RH == memtop - 7 ) && ( prevr == memtop - 7 ) ) 
	artificialdemerits = true ;
	else if ( b > threshold ) 
	goto lab60 ;
	noderstaysactive = false ;
      } 
      else {
	  
	prevr = r ;
	if ( b > threshold ) 
	goto lab22 ;
	noderstaysactive = true ;
      } 
      if ( artificialdemerits ) 
      d = 0 ;
      else {
	  
	d = eqtb [29190 ].cint + b ;
	if ( abs ( d ) >= 10000 ) 
	d = 100000000L ;
	else d = d * d ;
	if ( pi != 0 ) {
	    
	  if ( pi > 0 ) 
	  d = d + pi * pi ;
	  else if ( pi > -10000 ) 
	  d = d - pi * pi ;
	} 
	if ( ( breaktype == 1 ) && ( mem [r ].hh.b0 == 1 ) ) {
	    
	  if ( curp != -1073741823L ) 
	  d = d + eqtb [29202 ].cint ;
	  else d = d + eqtb [29203 ].cint ;
	} 
	if ( abs ( fitclass - mem [r ].hh.b1 ) > 1 ) 
	d = d + eqtb [29204 ].cint ;
      } 
	;
#ifdef STAT
      if ( eqtb [29220 ].cint > 0 ) 
      {
	if ( printednode != curp ) 
	{
	  printnl ( 344 ) ;
	  if ( curp == -1073741823L ) 
	  shortdisplay ( mem [printednode ].hh .v.RH ) ;
	  else {
	      
	    savelink = mem [curp ].hh .v.RH ;
	    mem [curp ].hh .v.RH = -1073741823L ;
	    printnl ( 344 ) ;
	    shortdisplay ( mem [printednode ].hh .v.RH ) ;
	    mem [curp ].hh .v.RH = savelink ;
	  } 
	  printednode = curp ;
	} 
	printnl ( 64 ) ;
	if ( curp == -1073741823L ) 
	printesc ( 652 ) ;
	else if ( ( mem [curp ].hh.b0 != 12 ) && ( ! ( curp >= himemmin ) ) 
	) 
	{
	  if ( mem [curp ].hh.b0 == 14 ) 
	  printesc ( 580 ) ;
	  else if ( mem [curp ].hh.b0 == 9 ) 
	  printesc ( 359 ) ;
	  else if ( mem [curp ].hh.b0 == 13 ) 
	  printesc ( 346 ) ;
	  else printesc ( 351 ) ;
	} 
	print ( 1030 ) ;
	if ( mem [r + 1 ].hh .v.RH == -1073741823L ) 
	printchar ( 48 ) ;
	else printint ( mem [mem [r + 1 ].hh .v.RH ].hh .v.LH ) ;
	print ( 1031 ) ;
	if ( b > 10000 ) 
	printchar ( 42 ) ;
	else printint ( b ) ;
	print ( 1032 ) ;
	printint ( pi ) ;
	print ( 1033 ) ;
	if ( artificialdemerits ) 
	printchar ( 42 ) ;
	else printint ( d ) ;
      } 
#endif /* STAT */
      d = d + mem [r + 2 ].cint ;
      if ( d <= minimaldemerits [fitclass ]) 
      {
	minimaldemerits [fitclass ]= d ;
	bestplace [fitclass ]= mem [r + 1 ].hh .v.RH ;
	bestplline [fitclass ]= l ;
	if ( dolastlinefit ) 
	{
	  bestplshort [fitclass ]= shortfall ;
	  bestplglue [fitclass ]= g ;
	} 
	if ( d < minimumdemerits ) 
	minimumdemerits = d ;
      } 
      if ( noderstaysactive ) 
      goto lab22 ;
      lab60: mem [prevr ].hh .v.RH = mem [r ].hh .v.RH ;
      freenode ( r , activenodesize ) ;
      if ( prevr == memtop - 7 ) 
      {
	r = mem [memtop - 7 ].hh .v.RH ;
	if ( mem [r ].hh.b0 == 2 ) 
	{
	  activewidth [1 ]= activewidth [1 ]+ mem [r + 1 ].cint ;
	  activewidth [2 ]= activewidth [2 ]+ mem [r + 2 ].cint ;
	  activewidth [3 ]= activewidth [3 ]+ mem [r + 3 ].cint ;
	  activewidth [4 ]= activewidth [4 ]+ mem [r + 4 ].cint ;
	  activewidth [5 ]= activewidth [5 ]+ mem [r + 5 ].cint ;
	  activewidth [6 ]= activewidth [6 ]+ mem [r + 6 ].cint ;
	  activewidth [7 ]= activewidth [7 ]+ mem [r + 7 ].cint ;
	  curactivewidth [1 ]= activewidth [1 ];
	  curactivewidth [2 ]= activewidth [2 ];
	  curactivewidth [3 ]= activewidth [3 ];
	  curactivewidth [4 ]= activewidth [4 ];
	  curactivewidth [5 ]= activewidth [5 ];
	  curactivewidth [6 ]= activewidth [6 ];
	  curactivewidth [7 ]= activewidth [7 ];
	  mem [memtop - 7 ].hh .v.RH = mem [r ].hh .v.RH ;
	  freenode ( r , 8 ) ;
	} 
      } 
      else if ( mem [prevr ].hh.b0 == 2 ) 
      {
	r = mem [prevr ].hh .v.RH ;
	if ( r == memtop - 7 ) 
	{
	  curactivewidth [1 ]= curactivewidth [1 ]- mem [prevr + 1 ]
	  .cint ;
	  curactivewidth [2 ]= curactivewidth [2 ]- mem [prevr + 2 ]
	  .cint ;
	  curactivewidth [3 ]= curactivewidth [3 ]- mem [prevr + 3 ]
	  .cint ;
	  curactivewidth [4 ]= curactivewidth [4 ]- mem [prevr + 4 ]
	  .cint ;
	  curactivewidth [5 ]= curactivewidth [5 ]- mem [prevr + 5 ]
	  .cint ;
	  curactivewidth [6 ]= curactivewidth [6 ]- mem [prevr + 6 ]
	  .cint ;
	  curactivewidth [7 ]= curactivewidth [7 ]- mem [prevr + 7 ]
	  .cint ;
	  mem [prevprevr ].hh .v.RH = memtop - 7 ;
	  freenode ( prevr , 8 ) ;
	  prevr = prevprevr ;
	} 
	else if ( mem [r ].hh.b0 == 2 ) 
	{
	  curactivewidth [1 ]= curactivewidth [1 ]+ mem [r + 1 ].cint ;
	  curactivewidth [2 ]= curactivewidth [2 ]+ mem [r + 2 ].cint ;
	  curactivewidth [3 ]= curactivewidth [3 ]+ mem [r + 3 ].cint ;
	  curactivewidth [4 ]= curactivewidth [4 ]+ mem [r + 4 ].cint ;
	  curactivewidth [5 ]= curactivewidth [5 ]+ mem [r + 5 ].cint ;
	  curactivewidth [6 ]= curactivewidth [6 ]+ mem [r + 6 ].cint ;
	  curactivewidth [7 ]= curactivewidth [7 ]+ mem [r + 7 ].cint ;
	  mem [prevr + 1 ].cint = mem [prevr + 1 ].cint + mem [r + 1 ]
	  .cint ;
	  mem [prevr + 2 ].cint = mem [prevr + 2 ].cint + mem [r + 2 ]
	  .cint ;
	  mem [prevr + 3 ].cint = mem [prevr + 3 ].cint + mem [r + 3 ]
	  .cint ;
	  mem [prevr + 4 ].cint = mem [prevr + 4 ].cint + mem [r + 4 ]
	  .cint ;
	  mem [prevr + 5 ].cint = mem [prevr + 5 ].cint + mem [r + 5 ]
	  .cint ;
	  mem [prevr + 6 ].cint = mem [prevr + 6 ].cint + mem [r + 6 ]
	  .cint ;
	  mem [prevr + 7 ].cint = mem [prevr + 7 ].cint + mem [r + 7 ]
	  .cint ;
	  mem [prevr ].hh .v.RH = mem [r ].hh .v.RH ;
	  freenode ( r , 8 ) ;
	} 
      } 
    } 
  } 
  lab10: 
	;
#ifdef STAT
  if ( curp == printednode ) {
      
    if ( curp != -1073741823L ) {
	
      if ( mem [curp ].hh.b0 == 9 ) 
      {
	t = mem [curp ].hh.b1 ;
	while ( t > 0 ) {
	    
	  decr ( t ) ;
	  printednode = mem [printednode ].hh .v.RH ;
	} 
      } 
#endif /* STAT */
    } 
  } 
} 
void 
zpostlinebreak ( boolean d ) 
{
  /* 30 31 */ postlinebreak_regmem 
  halfword q, r, s  ;
  boolean discbreak  ;
  boolean postdiscbreak  ;
  scaled curwidth  ;
  scaled curindent  ;
  quarterword t  ;
  integer pen  ;
  halfword curline  ;
  halfword LRptr  ;
  LRptr = curlist .eTeXauxfield ;
  q = mem [bestbet + 1 ].hh .v.RH ;
  curp = -1073741823L ;
  do {
      r = q ;
    q = mem [q + 1 ].hh .v.LH ;
    mem [r + 1 ].hh .v.LH = curp ;
    curp = r ;
  } while ( ! ( q == -1073741823L ) ) ;
  curline = curlist .pgfield + 1 ;
  lastdisp = 0 ;
  do {
      if ( ( eqtb [29261 ].cint > 0 ) ) 
    {
      q = mem [memtop - 3 ].hh .v.RH ;
      if ( LRptr != -1073741823L ) 
      {
	tempptr = LRptr ;
	r = q ;
	do {
	    s = newmath ( 0 , ( mem [tempptr ].hh .v.LH - 1 ) ) ;
	  mem [s ].hh .v.RH = r ;
	  r = s ;
	  tempptr = mem [tempptr ].hh .v.RH ;
	} while ( ! ( tempptr == -1073741823L ) ) ;
	mem [memtop - 3 ].hh .v.RH = r ;
      } 
      while ( q != mem [curp + 1 ].hh .v.RH ) {
	  
	if ( ! ( q >= himemmin ) ) {
	    
	  if ( mem [q ].hh.b0 == 11 ) {
	      
	    if ( odd ( mem [q ].hh.b1 ) ) 
	    {
	      if ( LRptr != -1073741823L ) {
		  
		if ( mem [LRptr ].hh .v.LH == ( 4 * ( mem [q ].hh.b1 / 4 ) 
		+ 3 ) ) 
		{
		  tempptr = LRptr ;
		  LRptr = mem [tempptr ].hh .v.RH ;
		  {
		    mem [tempptr ].hh .v.RH = avail ;
		    avail = tempptr ;
	;
#ifdef STAT
		    decr ( dynused ) ;
#endif /* STAT */
		  } 
		} 
	      } 
	    } 
	    else {
		
	      tempptr = getavail () ;
	      mem [tempptr ].hh .v.LH = ( 4 * ( mem [q ].hh.b1 / 4 ) + 3 ) 
	      ;
	      mem [tempptr ].hh .v.RH = LRptr ;
	      LRptr = tempptr ;
	    } 
	  } 
	} 
	q = mem [q ].hh .v.RH ;
      } 
    } 
    q = mem [curp + 1 ].hh .v.RH ;
    discbreak = false ;
    postdiscbreak = false ;
    if ( q != -1073741823L ) 
    {
      if ( ! ( q >= himemmin ) ) {
	  
	if ( mem [q ].hh.b0 == 12 ) 
	{
	  deleteglueref ( mem [q + 1 ].hh .v.LH ) ;
	  mem [q + 1 ].hh .v.LH = eqtb [24536 ].hh .v.RH ;
	  mem [q ].hh.b1 = 9 ;
	  incr ( mem [eqtb [24536 ].hh .v.RH ].hh .v.RH ) ;
	  goto lab30 ;
	} 
	else {
	    
	  if ( mem [q ].hh.b0 == 9 ) 
	  {
	    t = mem [q ].hh.b1 ;
	    if ( t == 0 ) 
	    r = mem [q ].hh .v.RH ;
	    else {
		
	      r = q ;
	      while ( t > 1 ) {
		  
		r = mem [r ].hh .v.RH ;
		decr ( t ) ;
	      } 
	      s = mem [r ].hh .v.RH ;
	      r = mem [s ].hh .v.RH ;
	      mem [s ].hh .v.RH = -1073741823L ;
	      flushnodelist ( mem [q ].hh .v.RH ) ;
	      mem [q ].hh.b1 = 0 ;
	    } 
	    if ( mem [q + 1 ].hh .v.RH != -1073741823L ) 
	    {
	      s = mem [q + 1 ].hh .v.RH ;
	      while ( mem [s ].hh .v.RH != -1073741823L ) s = mem [s ].hh 
	      .v.RH ;
	      mem [s ].hh .v.RH = r ;
	      r = mem [q + 1 ].hh .v.RH ;
	      mem [q + 1 ].hh .v.RH = -1073741823L ;
	      postdiscbreak = true ;
	    } 
	    if ( mem [q + 1 ].hh .v.LH != -1073741823L ) 
	    {
	      s = mem [q + 1 ].hh .v.LH ;
	      mem [q ].hh .v.RH = s ;
	      while ( mem [s ].hh .v.RH != -1073741823L ) s = mem [s ].hh 
	      .v.RH ;
	      mem [q + 1 ].hh .v.LH = -1073741823L ;
	      q = s ;
	    } 
	    mem [q ].hh .v.RH = r ;
	    discbreak = true ;
	  } 
	  else if ( mem [q ].hh.b0 == 13 ) 
	  mem [q + 1 ].cint = 0 ;
	  else if ( mem [q ].hh.b0 == 11 ) 
	  {
	    mem [q + 1 ].cint = 0 ;
	    if ( ( eqtb [29261 ].cint > 0 ) ) {
		
	      if ( odd ( mem [q ].hh.b1 ) ) 
	      {
		if ( LRptr != -1073741823L ) {
		    
		  if ( mem [LRptr ].hh .v.LH == ( 4 * ( mem [q ].hh.b1 / 4 
		  ) + 3 ) ) 
		  {
		    tempptr = LRptr ;
		    LRptr = mem [tempptr ].hh .v.RH ;
		    {
		      mem [tempptr ].hh .v.RH = avail ;
		      avail = tempptr ;
	;
#ifdef STAT
		      decr ( dynused ) ;
#endif /* STAT */
		    } 
		  } 
		} 
	      } 
	      else {
		  
		tempptr = getavail () ;
		mem [tempptr ].hh .v.LH = ( 4 * ( mem [q ].hh.b1 / 4 ) + 3 
		) ;
		mem [tempptr ].hh .v.RH = LRptr ;
		LRptr = tempptr ;
	      } 
	    } 
	  } 
	} 
      } 
    } 
    else {
	
      q = memtop - 3 ;
      while ( mem [q ].hh .v.RH != -1073741823L ) q = mem [q ].hh .v.RH ;
    } 
    r = newparamglue ( 8 ) ;
    mem [r ].hh .v.RH = mem [q ].hh .v.RH ;
    mem [q ].hh .v.RH = r ;
    q = r ;
    lab30: ;
    if ( ( eqtb [29261 ].cint > 0 ) ) {
	
      if ( LRptr != -1073741823L ) 
      {
	s = memtop - 3 ;
	r = mem [s ].hh .v.RH ;
	while ( r != q ) {
	    
	  s = r ;
	  r = mem [s ].hh .v.RH ;
	} 
	r = LRptr ;
	while ( r != -1073741823L ) {
	    
	  tempptr = newmath ( 0 , mem [r ].hh .v.LH ) ;
	  mem [s ].hh .v.RH = tempptr ;
	  s = tempptr ;
	  r = mem [r ].hh .v.RH ;
	} 
	mem [s ].hh .v.RH = q ;
      } 
    } 
    r = mem [q ].hh .v.RH ;
    mem [q ].hh .v.RH = -1073741823L ;
    q = mem [memtop - 3 ].hh .v.RH ;
    mem [memtop - 3 ].hh .v.RH = r ;
    if ( lastdisp != 0 ) 
    {
      r = getnode ( 2 ) ;
      mem [r ].hh.b0 = 5 ;
      mem [r + 1 ].cint = lastdisp ;
      mem [r ].hh .v.RH = q ;
      q = r ;
    } 
    if ( eqtb [24535 ].hh .v.RH != membot ) 
    {
      r = newparamglue ( 7 ) ;
      mem [r ].hh .v.RH = q ;
      q = r ;
    } 
    if ( curline > lastspecialline ) 
    {
      curwidth = secondwidth ;
      curindent = secondindent ;
    } 
    else if ( eqtb [25061 ].hh .v.RH == -1073741823L ) 
    {
      curwidth = firstwidth ;
      curindent = firstindent ;
    } 
    else {
	
      curwidth = mem [eqtb [25061 ].hh .v.RH + 2 * curline ].cint ;
      curindent = mem [eqtb [25061 ].hh .v.RH + 2 * curline - 1 ].cint ;
    } 
    adjusttail = memtop - 5 ;
    justbox = hpack ( q , curwidth , 0 ) ;
    mem [justbox + 4 ].cint = curindent ;
    appendtovlist ( justbox ) ;
    if ( memtop - 5 != adjusttail ) 
    {
      mem [curlist .tailfield ].hh .v.RH = mem [memtop - 5 ].hh .v.RH ;
      curlist .tailfield = adjusttail ;
    } 
    adjusttail = -1073741823L ;
    if ( curline + 1 != bestline ) 
    {
      q = eqtb [25328 ].hh .v.RH ;
      if ( q != -1073741823L ) 
      {
	r = curline ;
	if ( r > mem [q + 1 ].cint ) 
	r = mem [q + 1 ].cint ;
	pen = mem [q + r + 1 ].cint ;
      } 
      else pen = eqtb [29201 ].cint ;
      q = eqtb [25329 ].hh .v.RH ;
      if ( q != -1073741823L ) 
      {
	r = curline - curlist .pgfield ;
	if ( r > mem [q + 1 ].cint ) 
	r = mem [q + 1 ].cint ;
	pen = pen + mem [q + r + 1 ].cint ;
      } 
      else if ( curline == curlist .pgfield + 1 ) 
      pen = pen + eqtb [29193 ].cint ;
      if ( d ) 
      q = eqtb [25331 ].hh .v.RH ;
      else q = eqtb [25330 ].hh .v.RH ;
      if ( q != -1073741823L ) 
      {
	r = bestline - curline - 1 ;
	if ( r > mem [q + 1 ].cint ) 
	r = mem [q + 1 ].cint ;
	pen = pen + mem [q + r + 1 ].cint ;
      } 
      else if ( curline + 2 == bestline ) {
	  
	if ( d ) 
	pen = pen + eqtb [29195 ].cint ;
	else pen = pen + eqtb [29194 ].cint ;
      } 
      if ( discbreak ) 
      pen = pen + eqtb [29196 ].cint ;
      if ( pen != 0 ) 
      {
	r = newpenalty ( pen ) ;
	mem [curlist .tailfield ].hh .v.RH = r ;
	curlist .tailfield = r ;
      } 
    } 
    incr ( curline ) ;
    curp = mem [curp + 1 ].hh .v.LH ;
    if ( curp != -1073741823L ) {
	
      if ( ! postdiscbreak ) 
      {
	r = memtop - 3 ;
	while ( true ) {
	    
	  q = mem [r ].hh .v.RH ;
	  if ( q == mem [curp + 1 ].hh .v.RH ) 
	  goto lab31 ;
	  if ( ( q >= himemmin ) ) 
	  goto lab31 ;
	  if ( ( mem [q ].hh.b0 < 11 ) ) 
	  goto lab31 ;
	  if ( mem [q ].hh.b0 == 13 ) {
	      
	    if ( ( mem [q ].hh.b1 != 1 ) && ( mem [q ].hh.b1 != 3 ) ) 
	    goto lab31 ;
	  } 
	  r = q ;
	  if ( mem [q ].hh.b0 == 11 ) {
	      
	    if ( ( eqtb [29261 ].cint > 0 ) ) {
		
	      if ( odd ( mem [q ].hh.b1 ) ) 
	      {
		if ( LRptr != -1073741823L ) {
		    
		  if ( mem [LRptr ].hh .v.LH == ( 4 * ( mem [q ].hh.b1 / 4 
		  ) + 3 ) ) 
		  {
		    tempptr = LRptr ;
		    LRptr = mem [tempptr ].hh .v.RH ;
		    {
		      mem [tempptr ].hh .v.RH = avail ;
		      avail = tempptr ;
	;
#ifdef STAT
		      decr ( dynused ) ;
#endif /* STAT */
		    } 
		  } 
		} 
	      } 
	      else {
		  
		tempptr = getavail () ;
		mem [tempptr ].hh .v.LH = ( 4 * ( mem [q ].hh.b1 / 4 ) + 3 
		) ;
		mem [tempptr ].hh .v.RH = LRptr ;
		LRptr = tempptr ;
	      } 
	    } 
	  } 
	} 
	lab31: if ( r != memtop - 3 ) 
	{
	  mem [r ].hh .v.RH = -1073741823L ;
	  flushnodelist ( mem [memtop - 3 ].hh .v.RH ) ;
	  mem [memtop - 3 ].hh .v.RH = q ;
	} 
      } 
    } 
  } while ( ! ( curp == -1073741823L ) ) ;
  if ( ( curline != bestline ) || ( mem [memtop - 3 ].hh .v.RH != 
  -1073741823L ) ) 
  confusion ( 1040 ) ;
  curlist .pgfield = bestline - 1 ;
  curlist .eTeXauxfield = LRptr ;
} 
smallnumber 
zreconstitute ( smallnumber j , smallnumber n , halfword bchar , halfword 
hchar ) 
{
  /* 22 30 */ register smallnumber Result; reconstitute_regmem 
  halfword p  ;
  halfword t  ;
  fourquarters q  ;
  halfword currh  ;
  halfword testchar  ;
  scaled w  ;
  fontindex k  ;
  hyphenpassed = 0 ;
  t = memtop - 4 ;
  w = 0 ;
  mem [memtop - 4 ].hh .v.RH = -1073741823L ;
  curl = hu [j ];
  curq = t ;
  if ( j == 0 ) 
  {
    ligaturepresent = initlig ;
    p = initlist ;
    if ( ligaturepresent ) 
    lfthit = initlft ;
    while ( p > -1073741823L ) {
	
      {
	mem [t ].hh .v.RH = getavail () ;
	t = mem [t ].hh .v.RH ;
	mem [t ].hh.b0 = hf ;
	mem [t ].hh.b1 = mem [p ].hh.b1 ;
      } 
      p = mem [p ].hh .v.RH ;
    } 
  } 
  else if ( curl < 256 ) 
  {
    mem [t ].hh .v.RH = getavail () ;
    t = mem [t ].hh .v.RH ;
    mem [t ].hh.b0 = hf ;
    mem [t ].hh.b1 = curl ;
  } 
  ligstack = -1073741823L ;
  {
    if ( j < n ) 
    curr = hu [j + 1 ];
    else curr = bchar ;
    if ( odd ( hyf [j ]) ) 
    currh = hchar ;
    else currh = 256 ;
  } 
  lab22: if ( curl == 256 ) 
  {
    k = bcharlabel [hf ];
    if ( k == 0 ) 
    goto lab30 ;
    else q = fontinfo [k ].qqqq ;
  } 
  else {
      
    q = fontinfo [charbase [hf ]+ effectivechar ( true , hf , curl ) ]
    .qqqq ;
    if ( ( ( q .b2 ) % 4 ) != 1 ) 
    goto lab30 ;
    k = ligkernbase [hf ]+ q .b3 ;
    q = fontinfo [k ].qqqq ;
    if ( q .b0 > 128 ) 
    {
      k = ligkernbase [hf ]+ 256 * q .b2 + q .b3 + 32768L - 256 * ( 128 ) ;
      q = fontinfo [k ].qqqq ;
    } 
  } 
  if ( currh < 256 ) 
  testchar = currh ;
  else testchar = curr ;
  while ( true ) {
      
    if ( q .b1 == testchar ) {
	
      if ( q .b0 <= 128 ) {
	  
	if ( currh < 256 ) 
	{
	  hyphenpassed = j ;
	  hchar = 256 ;
	  currh = 256 ;
	  goto lab22 ;
	} 
	else {
	    
	  if ( hchar < 256 ) {
	      
	    if ( odd ( hyf [j ]) ) 
	    {
	      hyphenpassed = j ;
	      hchar = 256 ;
	    } 
	  } 
	  if ( q .b2 < 128 ) 
	  {
	    if ( curl == 256 ) 
	    lfthit = true ;
	    if ( j == n ) {
		
	      if ( ligstack == -1073741823L ) 
	      rthit = true ;
	    } 
	    {
	      if ( interrupt != 0 ) 
	      pauseforinstructions () ;
	    } 
	    switch ( q .b2 ) 
	    {case 1 : 
	    case 5 : 
	      {
		curl = q .b3 ;
		ligaturepresent = true ;
	      } 
	      break ;
	    case 2 : 
	    case 6 : 
	      {
		curr = q .b3 ;
		if ( ligstack > -1073741823L ) 
		mem [ligstack ].hh.b1 = curr ;
		else {
		    
		  ligstack = newligitem ( curr ) ;
		  if ( j == n ) 
		  bchar = 256 ;
		  else {
		      
		    p = getavail () ;
		    mem [ligstack + 1 ].hh .v.RH = p ;
		    mem [p ].hh.b1 = hu [j + 1 ];
		    mem [p ].hh.b0 = hf ;
		  } 
		} 
	      } 
	      break ;
	    case 3 : 
	      {
		curr = q .b3 ;
		p = ligstack ;
		ligstack = newligitem ( curr ) ;
		mem [ligstack ].hh .v.RH = p ;
	      } 
	      break ;
	    case 7 : 
	    case 11 : 
	      {
		if ( ligaturepresent ) 
		{
		  p = newligature ( hf , curl , mem [curq ].hh .v.RH ) ;
		  if ( lfthit ) 
		  {
		    mem [p ].hh.b1 = 2 ;
		    lfthit = false ;
		  } 
		  if ( false ) {
		      
		    if ( ligstack == -1073741823L ) 
		    {
		      incr ( mem [p ].hh.b1 ) ;
		      rthit = false ;
		    } 
		  } 
		  mem [curq ].hh .v.RH = p ;
		  t = p ;
		  ligaturepresent = false ;
		} 
		curq = t ;
		curl = q .b3 ;
		ligaturepresent = true ;
	      } 
	      break ;
	      default: 
	      {
		curl = q .b3 ;
		ligaturepresent = true ;
		if ( ligstack > -1073741823L ) 
		{
		  if ( mem [ligstack + 1 ].hh .v.RH > -1073741823L ) 
		  {
		    mem [t ].hh .v.RH = mem [ligstack + 1 ].hh .v.RH ;
		    t = mem [t ].hh .v.RH ;
		    incr ( j ) ;
		  } 
		  p = ligstack ;
		  ligstack = mem [p ].hh .v.RH ;
		  freenode ( p , 2 ) ;
		  if ( ligstack == -1073741823L ) 
		  {
		    if ( j < n ) 
		    curr = hu [j + 1 ];
		    else curr = bchar ;
		    if ( odd ( hyf [j ]) ) 
		    currh = hchar ;
		    else currh = 256 ;
		  } 
		  else curr = mem [ligstack ].hh.b1 ;
		} 
		else if ( j == n ) 
		goto lab30 ;
		else {
		    
		  {
		    mem [t ].hh .v.RH = getavail () ;
		    t = mem [t ].hh .v.RH ;
		    mem [t ].hh.b0 = hf ;
		    mem [t ].hh.b1 = curr ;
		  } 
		  incr ( j ) ;
		  {
		    if ( j < n ) 
		    curr = hu [j + 1 ];
		    else curr = bchar ;
		    if ( odd ( hyf [j ]) ) 
		    currh = hchar ;
		    else currh = 256 ;
		  } 
		} 
	      } 
	      break ;
	    } 
	    if ( q .b2 > 4 ) {
		
	      if ( q .b2 != 7 ) 
	      goto lab30 ;
	    } 
	    goto lab22 ;
	  } 
	  w = fontinfo [kernbase [hf ]+ 256 * q .b2 + q .b3 ].cint ;
	  goto lab30 ;
	} 
      } 
    } 
    if ( q .b0 >= 128 ) {
	
      if ( currh == 256 ) 
      goto lab30 ;
      else {
	  
	currh = 256 ;
	goto lab22 ;
      } 
    } 
    k = k + q .b0 + 1 ;
    q = fontinfo [k ].qqqq ;
  } 
  lab30: ;
  if ( ligaturepresent ) 
  {
    p = newligature ( hf , curl , mem [curq ].hh .v.RH ) ;
    if ( lfthit ) 
    {
      mem [p ].hh.b1 = 2 ;
      lfthit = false ;
    } 
    if ( rthit ) {
	
      if ( ligstack == -1073741823L ) 
      {
	incr ( mem [p ].hh.b1 ) ;
	rthit = false ;
      } 
    } 
    mem [curq ].hh .v.RH = p ;
    t = p ;
    ligaturepresent = false ;
  } 
  if ( w != 0 ) 
  {
    mem [t ].hh .v.RH = newkern ( w ) ;
    t = mem [t ].hh .v.RH ;
    w = 0 ;
    mem [t + 2 ].cint = 0 ;
  } 
  if ( ligstack > -1073741823L ) 
  {
    curq = t ;
    curl = mem [ligstack ].hh.b1 ;
    ligaturepresent = true ;
    {
      if ( mem [ligstack + 1 ].hh .v.RH > -1073741823L ) 
      {
	mem [t ].hh .v.RH = mem [ligstack + 1 ].hh .v.RH ;
	t = mem [t ].hh .v.RH ;
	incr ( j ) ;
      } 
      p = ligstack ;
      ligstack = mem [p ].hh .v.RH ;
      freenode ( p , 2 ) ;
      if ( ligstack == -1073741823L ) 
      {
	if ( j < n ) 
	curr = hu [j + 1 ];
	else curr = bchar ;
	if ( odd ( hyf [j ]) ) 
	currh = hchar ;
	else currh = 256 ;
      } 
      else curr = mem [ligstack ].hh.b1 ;
    } 
    goto lab22 ;
  } 
  Result = j ;
  return Result ;
} 
void 
hyphenate ( void ) 
{
  /* 50 30 40 41 42 45 10 */ hyphenate_regmem 
  unsigned char i, j, l  ;
  halfword q, r, s  ;
  halfword bchar  ;
  halfword majortail, minortail  ;
  ASCIIcode c  ;
  unsigned char cloc  ;
  integer rcount  ;
  halfword hyfnode  ;
  triepointer z  ;
  integer v  ;
  hyphpointer h  ;
  strnumber k  ;
  poolpointer u  ;
  {register integer for_end; j = 0 ;for_end = hn ; if ( j <= for_end) do 
    hyf [j ]= 0 ;
  while ( j++ < for_end ) ;} 
  h = hc [1 ];
  incr ( hn ) ;
  hc [hn ]= curlang ;
  {register integer for_end; j = 2 ;for_end = hn ; if ( j <= for_end) do 
    h = ( h + h + hc [j ]) % 607 ;
  while ( j++ < for_end ) ;} 
  while ( true ) {
      
    k = hyphword [h ];
    if ( k == 0 ) 
    goto lab45 ;
    if ( ( strstart [k + 1 ]- strstart [k ]) == hn ) 
    {
      j = 1 ;
      u = strstart [k ];
      do {
	  if ( strpool [u ]!= hc [j ]) 
	goto lab30 ;
	incr ( j ) ;
	incr ( u ) ;
      } while ( ! ( j > hn ) ) ;
      s = hyphlist [h ];
      while ( s != -1073741823L ) {
	  
	hyf [mem [s ].hh .v.LH ]= 1 ;
	s = mem [s ].hh .v.RH ;
      } 
      decr ( hn ) ;
      goto lab40 ;
    } 
    lab30: ;
    h = hyphlink [h ];
    if ( h == 0 ) 
    goto lab45 ;
    decr ( h ) ;
  } 
  lab45: decr ( hn ) ;
  if ( trietrc [curlang + 1 ]!= curlang ) 
  return ;
  hc [0 ]= 0 ;
  hc [hn + 1 ]= 0 ;
  hc [hn + 2 ]= 256 ;
  {register integer for_end; j = 0 ;for_end = hn - rhyf + 1 ; if ( j <= 
  for_end) do 
    {
      z = trietrl [curlang + 1 ]+ hc [j ];
      l = j ;
      while ( hc [l ]== trietrc [z ]) {
	  
	if ( trietro [z ]!= mintrieop ) 
	{
	  v = trietro [z ];
	  do {
	      v = v + opstart [curlang ];
	    i = l - hyfdistance [v ];
	    if ( hyfnum [v ]> hyf [i ]) 
	    hyf [i ]= hyfnum [v ];
	    v = hyfnext [v ];
	  } while ( ! ( v == mintrieop ) ) ;
	} 
	incr ( l ) ;
	z = trietrl [z ]+ hc [l ];
      } 
    } 
  while ( j++ < for_end ) ;} 
  lab40: {
      register integer for_end; j = 0 ;for_end = lhyf - 1 ; if ( j <= 
  for_end) do 
    hyf [j ]= 0 ;
  while ( j++ < for_end ) ;} 
  {register integer for_end; j = 0 ;for_end = rhyf - 1 ; if ( j <= for_end) 
  do 
    hyf [hn - j ]= 0 ;
  while ( j++ < for_end ) ;} 
  {register integer for_end; j = lhyf ;for_end = hn - rhyf ; if ( j <= 
  for_end) do 
    if ( odd ( hyf [j ]) ) 
    goto lab41 ;
  while ( j++ < for_end ) ;} 
  return ;
  lab41: ;
  q = mem [hb ].hh .v.RH ;
  mem [hb ].hh .v.RH = -1073741823L ;
  r = mem [ha ].hh .v.RH ;
  mem [ha ].hh .v.RH = -1073741823L ;
  bchar = hyfbchar ;
  if ( ( ha >= himemmin ) ) {
      
    if ( mem [ha ].hh.b0 != hf ) 
    goto lab42 ;
    else {
	
      initlist = ha ;
      initlig = false ;
      hu [0 ]= mem [ha ].hh.b1 ;
    } 
  } 
  else if ( mem [ha ].hh.b0 == 8 ) {
      
    if ( mem [ha + 1 ].hh.b0 != hf ) 
    goto lab42 ;
    else {
	
      initlist = mem [ha + 1 ].hh .v.RH ;
      initlig = true ;
      initlft = ( mem [ha ].hh.b1 > 1 ) ;
      hu [0 ]= mem [ha + 1 ].hh.b1 ;
      if ( initlist == -1073741823L ) {
	  
	if ( initlft ) 
	{
	  hu [0 ]= 256 ;
	  initlig = false ;
	} 
      } 
      freenode ( ha , 2 ) ;
    } 
  } 
  else {
      
    if ( ! ( r >= himemmin ) ) {
	
      if ( mem [r ].hh.b0 == 8 ) {
	  
	if ( mem [r ].hh.b1 > 1 ) 
	goto lab42 ;
      } 
    } 
    j = 1 ;
    s = ha ;
    initlist = -1073741823L ;
    goto lab50 ;
  } 
  s = curp ;
  while ( mem [s ].hh .v.RH != ha ) s = mem [s ].hh .v.RH ;
  j = 0 ;
  goto lab50 ;
  lab42: s = ha ;
  j = 0 ;
  hu [0 ]= 256 ;
  initlig = false ;
  initlist = -1073741823L ;
  lab50: flushnodelist ( r ) ;
  do {
      l = j ;
    j = reconstitute ( j , hn , bchar , hyfchar ) + 1 ;
    if ( hyphenpassed == 0 ) 
    {
      mem [s ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
      while ( mem [s ].hh .v.RH > -1073741823L ) s = mem [s ].hh .v.RH ;
      if ( odd ( hyf [j - 1 ]) ) 
      {
	l = j ;
	hyphenpassed = j - 1 ;
	mem [memtop - 4 ].hh .v.RH = -1073741823L ;
      } 
    } 
    if ( hyphenpassed > 0 ) 
    do {
	r = getnode ( 2 ) ;
      mem [r ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
      mem [r ].hh.b0 = 9 ;
      majortail = r ;
      rcount = 0 ;
      while ( mem [majortail ].hh .v.RH > -1073741823L ) {
	  
	majortail = mem [majortail ].hh .v.RH ;
	incr ( rcount ) ;
      } 
      i = hyphenpassed ;
      hyf [i ]= 0 ;
      minortail = -1073741823L ;
      mem [r + 1 ].hh .v.LH = -1073741823L ;
      hyfnode = newcharacter ( hf , hyfchar ) ;
      if ( hyfnode != -1073741823L ) 
      {
	incr ( i ) ;
	c = hu [i ];
	hu [i ]= hyfchar ;
	{
	  mem [hyfnode ].hh .v.RH = avail ;
	  avail = hyfnode ;
	;
#ifdef STAT
	  decr ( dynused ) ;
#endif /* STAT */
	} 
      } 
      while ( l <= i ) {
	  
	l = reconstitute ( l , i , fontbchar [hf ], 256 ) + 1 ;
	if ( mem [memtop - 4 ].hh .v.RH > -1073741823L ) 
	{
	  if ( minortail == -1073741823L ) 
	  mem [r + 1 ].hh .v.LH = mem [memtop - 4 ].hh .v.RH ;
	  else mem [minortail ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
	  minortail = mem [memtop - 4 ].hh .v.RH ;
	  while ( mem [minortail ].hh .v.RH > -1073741823L ) minortail = mem 
	  [minortail ].hh .v.RH ;
	} 
      } 
      if ( hyfnode != -1073741823L ) 
      {
	hu [i ]= c ;
	l = i ;
	decr ( i ) ;
      } 
      minortail = -1073741823L ;
      mem [r + 1 ].hh .v.RH = -1073741823L ;
      cloc = 0 ;
      if ( bcharlabel [hf ]!= 0 ) 
      {
	decr ( l ) ;
	c = hu [l ];
	cloc = l ;
	hu [l ]= 256 ;
      } 
      while ( l < j ) {
	  
	do {
	    l = reconstitute ( l , hn , bchar , 256 ) + 1 ;
	  if ( cloc > 0 ) 
	  {
	    hu [cloc ]= c ;
	    cloc = 0 ;
	  } 
	  if ( mem [memtop - 4 ].hh .v.RH > -1073741823L ) 
	  {
	    if ( minortail == -1073741823L ) 
	    mem [r + 1 ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
	    else mem [minortail ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
	    minortail = mem [memtop - 4 ].hh .v.RH ;
	    while ( mem [minortail ].hh .v.RH > -1073741823L ) minortail = 
	    mem [minortail ].hh .v.RH ;
	  } 
	} while ( ! ( l >= j ) ) ;
	while ( l > j ) {
	    
	  j = reconstitute ( j , hn , bchar , 256 ) + 1 ;
	  mem [majortail ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
	  while ( mem [majortail ].hh .v.RH > -1073741823L ) {
	      
	    majortail = mem [majortail ].hh .v.RH ;
	    incr ( rcount ) ;
	  } 
	} 
      } 
      if ( rcount > 127 ) 
      {
	mem [s ].hh .v.RH = mem [r ].hh .v.RH ;
	mem [r ].hh .v.RH = -1073741823L ;
	flushnodelist ( r ) ;
      } 
      else {
	  
	mem [s ].hh .v.RH = r ;
	mem [r ].hh.b1 = rcount ;
      } 
      s = majortail ;
      hyphenpassed = j - 1 ;
      mem [memtop - 4 ].hh .v.RH = -1073741823L ;
    } while ( ! ( ! odd ( hyf [j - 1 ]) ) ) ;
  } while ( ! ( j > hn ) ) ;
  mem [s ].hh .v.RH = q ;
  flushlist ( initlist ) ;
} 
boolean 
zeTeXenabled ( boolean b , quarterword j , halfword k ) 
{
  register boolean Result; eTeXenabled_regmem 
  if ( ! b ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 746 ) ;
    } 
    printcmdchr ( j , k ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 1462 ;
    } 
    error () ;
  } 
  Result = b ;
  return Result ;
} 
void 
showsavegroups ( void ) 
{
  /* 41 42 40 30 */ showsavegroups_regmem 
  integer p  ;
  short m  ;
  savepointer v  ;
  quarterword l  ;
  groupcode c  ;
  schar a  ;
  integer i  ;
  quarterword j  ;
  strnumber s  ;
  p = nestptr ;
  nest [p ]= curlist ;
  v = saveptr ;
  l = curlevel ;
  c = curgroup ;
  saveptr = curboundary ;
  decr ( curlevel ) ;
  a = 1 ;
  printnl ( 344 ) ;
  println () ;
  while ( true ) {
      
    printnl ( 380 ) ;
    printgroup ( true ) ;
    if ( curgroup == 0 ) 
    goto lab30 ;
    do {
	m = nest [p ].modefield ;
      if ( p > 0 ) 
      decr ( p ) ;
      else m = 1 ;
    } while ( ! ( m != 118 ) ) ;
    print ( 286 ) ;
    switch ( curgroup ) 
    {case 1 : 
      {
	incr ( p ) ;
	goto lab42 ;
      } 
      break ;
    case 2 : 
    case 3 : 
      s = 1166 ;
      break ;
    case 4 : 
      s = 1068 ;
      break ;
    case 5 : 
      s = 1165 ;
      break ;
    case 6 : 
      if ( a == 0 ) 
      {
	if ( m == -1 ) 
	s = 566 ;
	else s = 588 ;
	a = 1 ;
	goto lab41 ;
      } 
      else {
	  
	if ( a == 1 ) 
	print ( 1500 ) ;
	else printesc ( 1000 ) ;
	if ( p >= a ) 
	p = p - a ;
	a = 0 ;
	goto lab40 ;
      } 
      break ;
    case 7 : 
      {
	incr ( p ) ;
	a = -1 ;
	printesc ( 575 ) ;
	goto lab42 ;
      } 
      break ;
    case 8 : 
      {
	printesc ( 420 ) ;
	goto lab40 ;
      } 
      break ;
    case 9 : 
      goto lab42 ;
      break ;
    case 10 : 
    case 13 : 
      {
	if ( curgroup == 10 ) 
	printesc ( 359 ) ;
	else printesc ( 573 ) ;
	{register integer for_end; i = 1 ;for_end = 3 ; if ( i <= for_end) 
	do 
	  if ( i <= savestack [saveptr - 2 ].cint ) 
	  print ( 959 ) ;
	while ( i++ < for_end ) ;} 
	goto lab42 ;
      } 
      break ;
    case 11 : 
      {
	if ( savestack [saveptr - 2 ].cint == 255 ) 
	printesc ( 362 ) ;
	else {
	    
	  printesc ( 336 ) ;
	  printint ( savestack [saveptr - 2 ].cint ) ;
	} 
	goto lab42 ;
      } 
      break ;
    case 12 : 
      {
	s = 589 ;
	goto lab41 ;
      } 
      break ;
    case 14 : 
      {
	incr ( p ) ;
	printesc ( 554 ) ;
	goto lab40 ;
      } 
      break ;
    case 15 : 
      {
	if ( m == 235 ) 
	printchar ( 36 ) ;
	else if ( nest [p ].modefield == 235 ) 
	{
	  printcmdchr ( 52 , savestack [saveptr - 2 ].cint ) ;
	  goto lab40 ;
	} 
	printchar ( 36 ) ;
	goto lab40 ;
      } 
      break ;
    case 16 : 
      {
	if ( mem [nest [p + 1 ].eTeXauxfield ].hh.b0 == 32 ) 
	printesc ( 975 ) ;
	else printesc ( 977 ) ;
	goto lab40 ;
      } 
      break ;
    } 
    i = savestack [saveptr - 4 ].cint ;
    if ( i != 0 ) {
	
      if ( i < 1073741824L ) 
      {
	if ( abs ( nest [p ].modefield ) == 1 ) 
	j = 25 ;
	else j = 26 ;
	if ( i > 0 ) 
	printcmdchr ( j , 0 ) ;
	else printcmdchr ( j , 1 ) ;
	printscaled ( abs ( i ) ) ;
	print ( 419 ) ;
      } 
      else if ( i < 1073872896L ) 
      {
	if ( i >= 1073807360L ) 
	{
	  printesc ( 1301 ) ;
	  i = i - ( 65536L ) ;
	} 
	printesc ( 586 ) ;
	printint ( i - 1073741824L ) ;
	printchar ( 61 ) ;
      } 
      else printcmdchr ( 35 , i - ( 1073872797L ) ) ;
    } 
    lab41: printesc ( s ) ;
    if ( savestack [saveptr - 2 ].cint != 0 ) 
    {
      printchar ( 32 ) ;
      if ( savestack [saveptr - 3 ].cint == 0 ) 
      print ( 941 ) ;
      else print ( 942 ) ;
      printscaled ( savestack [saveptr - 2 ].cint ) ;
      print ( 419 ) ;
    } 
    lab42: printchar ( 123 ) ;
    lab40: printchar ( 41 ) ;
    decr ( curlevel ) ;
    curgroup = savestack [saveptr ].hh.b1 ;
    saveptr = savestack [saveptr ].hh .v.RH ;
  } 
  lab30: saveptr = v ;
  curlevel = l ;
  curgroup = c ;
} 
halfword 
zprunepagetop ( halfword p , boolean s ) 
{
  register halfword Result; prunepagetop_regmem 
  halfword prevp  ;
  halfword q, r  ;
  prevp = memtop - 3 ;
  mem [memtop - 3 ].hh .v.RH = p ;
  while ( p != -1073741823L ) switch ( mem [p ].hh.b0 ) 
  {case 2 : 
  case 0 : 
  case 1 : 
  case 3 : 
    {
      q = newskipparam ( 10 ) ;
      mem [prevp ].hh .v.RH = q ;
      mem [q ].hh .v.RH = p ;
      if ( mem [tempptr + 1 ].cint > mem [p + 3 ].cint ) 
      mem [tempptr + 1 ].cint = mem [tempptr + 1 ].cint - mem [p + 3 ]
      .cint ;
      else mem [tempptr + 1 ].cint = 0 ;
      p = -1073741823L ;
    } 
    break ;
  case 10 : 
  case 6 : 
  case 4 : 
    {
      prevp = p ;
      p = mem [prevp ].hh .v.RH ;
    } 
    break ;
  case 12 : 
  case 13 : 
  case 14 : 
    {
      q = p ;
      p = mem [q ].hh .v.RH ;
      mem [q ].hh .v.RH = -1073741823L ;
      mem [prevp ].hh .v.RH = p ;
      if ( s ) 
      {
	if ( discptr [3 ]== -1073741823L ) 
	discptr [3 ]= q ;
	else mem [r ].hh .v.RH = q ;
	r = q ;
      } 
      else flushnodelist ( q ) ;
    } 
    break ;
    default: 
    confusion ( 1060 ) ;
    break ;
  } 
  Result = mem [memtop - 3 ].hh .v.RH ;
  return Result ;
} 
halfword 
zvertbreak ( halfword p , scaled h , scaled d ) 
{
  /* 30 45 90 */ register halfword Result; vertbreak_regmem 
  halfword prevp  ;
  halfword q, r  ;
  integer pi  ;
  integer b  ;
  integer leastcost  ;
  halfword bestplace  ;
  scaled prevdp  ;
  smallnumber t  ;
  prevp = p ;
  leastcost = 1073741823L ;
  activewidth [1 ]= 0 ;
  activewidth [2 ]= 0 ;
  activewidth [3 ]= 0 ;
  activewidth [4 ]= 0 ;
  activewidth [5 ]= 0 ;
  activewidth [6 ]= 0 ;
  activewidth [7 ]= 0 ;
  prevdp = 0 ;
  while ( true ) {
      
    if ( p == -1073741823L ) 
    pi = -10000 ;
    else switch ( mem [p ].hh.b0 ) 
    {case 2 : 
    case 0 : 
    case 1 : 
    case 3 : 
      {
	activewidth [1 ]= activewidth [1 ]+ prevdp + mem [p + 3 ].cint ;
	prevdp = mem [p + 2 ].cint ;
	goto lab45 ;
      } 
      break ;
    case 10 : 
      goto lab45 ;
      break ;
    case 12 : 
      if ( ( mem [prevp ].hh.b0 < 11 ) ) 
      pi = 0 ;
      else goto lab90 ;
      break ;
    case 13 : 
      {
	if ( mem [p ].hh .v.RH == -1073741823L ) 
	t = 14 ;
	else t = mem [mem [p ].hh .v.RH ].hh.b0 ;
	if ( t == 12 ) 
	pi = 0 ;
	else goto lab90 ;
      } 
      break ;
    case 14 : 
      pi = mem [p + 1 ].cint ;
      break ;
    case 6 : 
    case 4 : 
      goto lab45 ;
      break ;
      default: 
      confusion ( 1061 ) ;
      break ;
    } 
    if ( pi < 10000 ) 
    {
      if ( activewidth [1 ]< h ) {
	  
	if ( ( activewidth [3 ]!= 0 ) || ( activewidth [4 ]!= 0 ) || ( 
	activewidth [5 ]!= 0 ) || ( activewidth [6 ]!= 0 ) ) 
	b = 0 ;
	else b = badness ( h - activewidth [1 ], activewidth [2 ]) ;
      } 
      else if ( activewidth [1 ]- h > activewidth [7 ]) 
      b = 1073741823L ;
      else b = badness ( activewidth [1 ]- h , activewidth [7 ]) ;
      if ( b < 1073741823L ) {
	  
	if ( pi <= -10000 ) 
	b = pi ;
	else if ( b < 10000 ) 
	b = b + pi ;
	else b = 100000L ;
      } 
      if ( b <= leastcost ) 
      {
	bestplace = p ;
	leastcost = b ;
	bestheightplusdepth = activewidth [1 ]+ prevdp ;
      } 
      if ( ( b == 1073741823L ) || ( pi <= -10000 ) ) 
      goto lab30 ;
    } 
    if ( ( mem [p ].hh.b0 < 12 ) || ( mem [p ].hh.b0 > 13 ) ) 
    goto lab45 ;
    lab90: if ( mem [p ].hh.b0 == 13 ) 
    q = p ;
    else {
	
      q = mem [p + 1 ].hh .v.LH ;
      activewidth [2 + mem [q ].hh.b0 ]= activewidth [2 + mem [q ]
      .hh.b0 ]+ mem [q + 2 ].cint ;
      activewidth [7 ]= activewidth [7 ]+ mem [q + 3 ].cint ;
      if ( ( mem [q ].hh.b1 != 0 ) && ( mem [q + 3 ].cint != 0 ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1062 ) ;
	} 
	{
	  helpptr = 4 ;
	  helpline [3 ]= 1063 ;
	  helpline [2 ]= 1064 ;
	  helpline [1 ]= 1065 ;
	  helpline [0 ]= 1023 ;
	} 
	error () ;
	r = newspec ( q ) ;
	mem [r ].hh.b1 = 0 ;
	deleteglueref ( q ) ;
	mem [p + 1 ].hh .v.LH = r ;
	q = r ;
      } 
    } 
    activewidth [1 ]= activewidth [1 ]+ prevdp + mem [q + 1 ].cint ;
    prevdp = 0 ;
    lab45: if ( prevdp > d ) 
    {
      activewidth [1 ]= activewidth [1 ]+ prevdp - d ;
      prevdp = d ;
    } 
    prevp = p ;
    p = mem [prevp ].hh .v.RH ;
  } 
  lab30: Result = bestplace ;
  return Result ;
} 
halfword 
zvsplit ( halfword n , scaled h ) 
{
  /* 10 30 */ register halfword Result; vsplit_regmem 
  halfword v  ;
  halfword w  ;
  halfword p  ;
  halfword q  ;
  curval = n ;
  if ( curval < 256 ) 
  v = eqtb [25332 + curval ].hh .v.RH ;
  else {
      
    findsaelement ( 4 , curval , false ) ;
    if ( curptr == -1073741823L ) 
    v = -1073741823L ;
    else v = mem [curptr + 1 ].hh .v.RH ;
  } 
  flushnodelist ( discptr [3 ]) ;
  discptr [3 ]= -1073741823L ;
  if ( saroot [6 ]!= -1073741823L ) {
      
    if ( domarks ( 0 , 0 , saroot [6 ]) ) 
    saroot [6 ]= -1073741823L ;
  } 
  if ( curmark [3 ]!= -1073741823L ) 
  {
    deletetokenref ( curmark [3 ]) ;
    curmark [3 ]= -1073741823L ;
    deletetokenref ( curmark [4 ]) ;
    curmark [4 ]= -1073741823L ;
  } 
  if ( v == -1073741823L ) 
  {
    Result = -1073741823L ;
    return Result ;
  } 
  if ( mem [v ].hh.b0 == 2 ) 
  {
    w = v ;
    v = mem [v + 5 ].hh .v.RH ;
    deleteglueref ( mem [w + 7 ].hh .v.RH ) ;
    deleteglueref ( mem [w + 7 ].hh .v.LH ) ;
    freenode ( w , 10 ) ;
  } 
  if ( mem [v ].hh.b0 != 1 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 344 ) ;
    } 
    printesc ( 1066 ) ;
    print ( 1067 ) ;
    printesc ( 1068 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 1069 ;
      helpline [0 ]= 1070 ;
    } 
    error () ;
    Result = -1073741823L ;
    return Result ;
  } 
  flushnodelist ( mem [v ].hh .v.RH ) ;
  mem [v ].hh .v.RH = -1073741823L ;
  q = vertbreak ( mem [v + 5 ].hh .v.RH , h , eqtb [29780 ].cint ) ;
  p = mem [v + 5 ].hh .v.RH ;
  if ( p == q ) 
  mem [v + 5 ].hh .v.RH = -1073741823L ;
  else while ( true ) {
      
    if ( mem [p ].hh.b0 == 6 ) {
	
      if ( mem [p + 1 ].hh .v.LH != 0 ) 
      {
	findsaelement ( 6 , mem [p + 1 ].hh .v.LH , true ) ;
	if ( mem [curptr + 2 ].hh .v.RH == -1073741823L ) 
	{
	  mem [curptr + 2 ].hh .v.RH = mem [p + 1 ].hh .v.RH ;
	  incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
	} 
	else deletetokenref ( mem [curptr + 3 ].hh .v.LH ) ;
	mem [curptr + 3 ].hh .v.LH = mem [p + 1 ].hh .v.RH ;
	incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
      } 
      else if ( curmark [3 ]== -1073741823L ) 
      {
	curmark [3 ]= mem [p + 1 ].hh .v.RH ;
	curmark [4 ]= curmark [3 ];
	mem [curmark [3 ]].hh .v.LH = mem [curmark [3 ]].hh .v.LH + 2 
	;
      } 
      else {
	  
	deletetokenref ( curmark [4 ]) ;
	curmark [4 ]= mem [p + 1 ].hh .v.RH ;
	incr ( mem [curmark [4 ]].hh .v.LH ) ;
      } 
    } 
    if ( mem [p ].hh .v.RH == q ) 
    {
      mem [p ].hh .v.RH = -1073741823L ;
      goto lab30 ;
    } 
    p = mem [p ].hh .v.RH ;
  } 
  lab30: ;
  q = prunepagetop ( q , eqtb [29259 ].cint > 0 ) ;
  p = mem [v + 5 ].hh .v.RH ;
  if ( q != -1073741823L ) 
  {
    q = vpackage ( q , 0 , 1 , 1073741823L ) ;
    mem [q ].hh.b1 = ( ( mem [q ].hh.b1 ) / 8 ) * 8 + ( ( mem [v ].hh.b1 
    ) % 8 ) ;
  } 
  if ( curval < 256 ) 
  eqtb [25332 + curval ].hh .v.RH = q ;
  else {
      
    findsaelement ( 4 , curval , false ) ;
    if ( curptr != -1073741823L ) 
    {
      mem [curptr + 1 ].hh .v.RH = q ;
      incr ( mem [curptr + 1 ].hh .v.LH ) ;
      deletesaref ( curptr ) ;
    } 
  } 
  q = vpackage ( p , h , 0 , eqtb [29780 ].cint ) ;
  mem [q ].hh.b1 = ( ( mem [q ].hh.b1 ) / 8 ) * 8 + ( ( mem [v ].hh.b1 ) 
  % 8 ) ;
  deleteglueref ( mem [v + 7 ].hh .v.RH ) ;
  deleteglueref ( mem [v + 7 ].hh .v.LH ) ;
  freenode ( v , 10 ) ;
  Result = q ;
  return Result ;
} 
void 
printtotals ( void ) 
{
  printtotals_regmem 
  printscaled ( pagesofar [1 ]) ;
  if ( pagesofar [2 ]!= 0 ) 
  {
    print ( 317 ) ;
    printscaled ( pagesofar [2 ]) ;
    print ( 344 ) ;
  } 
  if ( pagesofar [3 ]!= 0 ) 
  {
    print ( 317 ) ;
    printscaled ( pagesofar [3 ]) ;
    print ( 316 ) ;
  } 
  if ( pagesofar [4 ]!= 0 ) 
  {
    print ( 317 ) ;
    printscaled ( pagesofar [4 ]) ;
    print ( 1080 ) ;
  } 
  if ( pagesofar [5 ]!= 0 ) 
  {
    print ( 317 ) ;
    printscaled ( pagesofar [5 ]) ;
    print ( 1081 ) ;
  } 
  if ( pagesofar [6 ]!= 0 ) 
  {
    print ( 317 ) ;
    printscaled ( pagesofar [6 ]) ;
    print ( 1082 ) ;
  } 
  if ( pagesofar [7 ]!= 0 ) 
  {
    print ( 318 ) ;
    printscaled ( pagesofar [7 ]) ;
  } 
} 
void 
zfreezepagespecs ( smallnumber s ) 
{
  freezepagespecs_regmem 
  pagecontents = s ;
  pagesofar [0 ]= eqtb [29778 ].cint ;
  pagemaxdepth = eqtb [29779 ].cint ;
  pagesofar [8 ]= 0 ;
  pagesofar [1 ]= 0 ;
  pagesofar [2 ]= 0 ;
  pagesofar [3 ]= 0 ;
  pagesofar [4 ]= 0 ;
  pagesofar [5 ]= 0 ;
  pagesofar [6 ]= 0 ;
  pagesofar [7 ]= 0 ;
  leastpagecost = 1073741823L ;
	;
#ifdef STAT
  if ( eqtb [29221 ].cint > 0 ) 
  {
    begindiagnostic () ;
    printnl ( 1090 ) ;
    printscaled ( pagesofar [0 ]) ;
    print ( 1091 ) ;
    printscaled ( pagemaxdepth ) ;
    enddiagnostic ( false ) ;
  } 
#endif /* STAT */
} 
void 
zboxerror ( eightbits n ) 
{
  boxerror_regmem 
  error () ;
  begindiagnostic () ;
  printnl ( 935 ) ;
  showbox ( eqtb [25332 + n ].hh .v.RH ) ;
  enddiagnostic ( true ) ;
  flushnodelist ( eqtb [25332 + n ].hh .v.RH ) ;
  eqtb [25332 + n ].hh .v.RH = -1073741823L ;
} 
void 
zensurevbox ( eightbits n ) 
{
  ensurevbox_regmem 
  halfword p  ;
  p = eqtb [25332 + n ].hh .v.RH ;
  if ( p != -1073741823L ) {
      
    if ( mem [p ].hh.b0 == 2 ) 
    {
      p = mem [p + 5 ].hh .v.RH ;
      deleteglueref ( mem [eqtb [25332 + n ].hh .v.RH + 7 ].hh .v.RH ) ;
      deleteglueref ( mem [eqtb [25332 + n ].hh .v.RH + 7 ].hh .v.LH ) ;
      freenode ( eqtb [25332 + n ].hh .v.RH , 10 ) ;
      eqtb [25332 + n ].hh .v.RH = p ;
    } 
  } 
  if ( p != -1073741823L ) {
      
    if ( mem [p ].hh.b0 != 1 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1092 ) ;
      } 
      {
	helpptr = 3 ;
	helpline [2 ]= 1093 ;
	helpline [1 ]= 1094 ;
	helpline [0 ]= 1095 ;
      } 
      boxerror ( n ) ;
    } 
  } 
} 
void 
zfireup ( halfword c ) 
{
  /* 10 */ fireup_regmem 
  halfword p, q, r, s  ;
  halfword prevp  ;
  unsigned char n  ;
  boolean wait  ;
  integer savevbadness  ;
  scaled savevfuzz  ;
  halfword savesplittopskip  ;
  if ( mem [bestpagebreak ].hh.b0 == 14 ) 
  {
    geqworddefine ( 29227 , mem [bestpagebreak + 1 ].cint ) ;
    mem [bestpagebreak + 1 ].cint = 10000 ;
  } 
  else geqworddefine ( 29227 , 10000 ) ;
  if ( saroot [6 ]!= -1073741823L ) {
      
    if ( domarks ( 1 , 0 , saroot [6 ]) ) 
    saroot [6 ]= -1073741823L ;
  } 
  if ( curmark [2 ]!= -1073741823L ) 
  {
    if ( curmark [0 ]!= -1073741823L ) 
    deletetokenref ( curmark [0 ]) ;
    curmark [0 ]= curmark [2 ];
    incr ( mem [curmark [0 ]].hh .v.LH ) ;
    deletetokenref ( curmark [1 ]) ;
    curmark [1 ]= -1073741823L ;
  } 
  if ( c == bestpagebreak ) 
  bestpagebreak = -1073741823L ;
  if ( eqtb [25587 ].hh .v.RH != -1073741823L ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 344 ) ;
    } 
    printesc ( 431 ) ;
    print ( 1108 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 1109 ;
      helpline [0 ]= 1095 ;
    } 
    boxerror ( 255 ) ;
  } 
  insertpenalties = 0 ;
  savesplittopskip = eqtb [24538 ].hh .v.RH ;
  if ( eqtb [29242 ].cint <= 0 ) 
  {
    r = mem [memtop ].hh .v.RH ;
    while ( r != memtop ) {
	
      if ( mem [r + 2 ].hh .v.LH != -1073741823L ) 
      {
	n = mem [r ].hh.b1 ;
	ensurevbox ( n ) ;
	if ( eqtb [25332 + n ].hh .v.RH == -1073741823L ) 
	eqtb [25332 + n ].hh .v.RH = newnullbox () ;
	p = eqtb [25332 + n ].hh .v.RH + 5 ;
	while ( mem [p ].hh .v.RH != -1073741823L ) p = mem [p ].hh .v.RH 
	;
	mem [r + 2 ].hh .v.RH = p ;
      } 
      r = mem [r ].hh .v.RH ;
    } 
  } 
  q = memtop - 4 ;
  mem [q ].hh .v.RH = -1073741823L ;
  prevp = memtop - 2 ;
  p = mem [prevp ].hh .v.RH ;
  while ( p != bestpagebreak ) {
      
    if ( mem [p ].hh.b0 == 4 ) 
    {
      if ( eqtb [29242 ].cint <= 0 ) 
      {
	r = mem [memtop ].hh .v.RH ;
	while ( mem [r ].hh.b1 != mem [p ].hh.b1 ) r = mem [r ].hh .v.RH 
	;
	if ( mem [r + 2 ].hh .v.LH == -1073741823L ) 
	wait = true ;
	else {
	    
	  wait = false ;
	  n = mem [p ].hh.b1 ;
	  switch ( ( ( mem [eqtb [25332 + n ].hh .v.RH ].hh.b1 ) % 8 ) ) 
	  {case 4 : 
	  case 3 : 
	  case 1 : 
	    if ( mem [p + 5 ].hh.b1 != ( ( mem [eqtb [25332 + n ].hh 
	    .v.RH ].hh.b1 ) % 8 ) ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 264 ) ;
		print ( 1101 ) ;
	      } 
	      {
		helpptr = 3 ;
		helpline [2 ]= 1093 ;
		helpline [1 ]= 1102 ;
		helpline [0 ]= 1095 ;
	      } 
	      boxerror ( n ) ;
	      eqtb [25332 + n ].hh .v.RH = newnullbox () ;
	      mem [r + 2 ].hh .v.RH = eqtb [25332 + n ].hh .v.RH + 5 ;
	    } 
	    break ;
	    default: 
	    mem [eqtb [25332 + n ].hh .v.RH ].hh.b1 = ( ( mem [eqtb [
	    25332 + n ].hh .v.RH ].hh.b1 ) / 8 ) * 8 + mem [p + 5 ].hh.b1 
	    ;
	    break ;
	  } 
	  s = mem [r + 2 ].hh .v.RH ;
	  mem [s ].hh .v.RH = mem [p + 4 ].hh .v.LH ;
	  if ( mem [r + 2 ].hh .v.LH == p ) 
	  {
	    if ( mem [r ].hh.b0 == 1 ) {
		
	      if ( ( mem [r + 1 ].hh .v.LH == p ) && ( mem [r + 1 ].hh 
	      .v.RH != -1073741823L ) ) 
	      {
		while ( mem [s ].hh .v.RH != mem [r + 1 ].hh .v.RH ) s = 
		mem [s ].hh .v.RH ;
		mem [s ].hh .v.RH = -1073741823L ;
		eqtb [24538 ].hh .v.RH = mem [p + 4 ].hh .v.RH ;
		mem [p + 4 ].hh .v.LH = prunepagetop ( mem [r + 1 ].hh 
		.v.RH , false ) ;
		if ( mem [p + 4 ].hh .v.LH != -1073741823L ) 
		{
		  tempptr = vpackage ( mem [p + 4 ].hh .v.LH , 0 , 1 , 
		  1073741823L ) ;
		  mem [p + 3 ].cint = mem [tempptr + 3 ].cint + mem [
		  tempptr + 2 ].cint ;
		  deleteglueref ( mem [tempptr + 7 ].hh .v.RH ) ;
		  deleteglueref ( mem [tempptr + 7 ].hh .v.LH ) ;
		  freenode ( tempptr , 10 ) ;
		  wait = true ;
		} 
	      } 
	    } 
	    mem [r + 2 ].hh .v.LH = -1073741823L ;
	    n = mem [r ].hh.b1 ;
	    tempptr = mem [eqtb [25332 + n ].hh .v.RH + 5 ].hh .v.RH ;
	    deleteglueref ( mem [eqtb [25332 + n ].hh .v.RH + 7 ].hh .v.RH 
	    ) ;
	    deleteglueref ( mem [eqtb [25332 + n ].hh .v.RH + 7 ].hh .v.LH 
	    ) ;
	    flushnodelist ( mem [eqtb [25332 + n ].hh .v.RH ].hh .v.RH ) ;
	    freenode ( eqtb [25332 + n ].hh .v.RH , 10 ) ;
	    eqtb [25332 + n ].hh .v.RH = vpackage ( tempptr , 0 , 1 , 
	    1073741823L ) ;
	    mem [eqtb [25332 + n ].hh .v.RH ].hh.b1 = ( ( mem [eqtb [
	    25332 + n ].hh .v.RH ].hh.b1 ) / 8 ) * 8 + mem [p + 5 ].hh.b1 
	    ;
	  } 
	  else {
	      
	    while ( mem [s ].hh .v.RH != -1073741823L ) s = mem [s ].hh 
	    .v.RH ;
	    mem [r + 2 ].hh .v.RH = s ;
	  } 
	} 
	mem [prevp ].hh .v.RH = mem [p ].hh .v.RH ;
	mem [p ].hh .v.RH = -1073741823L ;
	if ( wait ) 
	{
	  mem [q ].hh .v.RH = p ;
	  q = p ;
	  incr ( insertpenalties ) ;
	} 
	else {
	    
	  deleteglueref ( mem [p + 4 ].hh .v.RH ) ;
	  freenode ( p , 6 ) ;
	} 
	p = prevp ;
      } 
    } 
    else if ( mem [p ].hh.b0 == 6 ) {
	
      if ( mem [p + 1 ].hh .v.LH != 0 ) 
      {
	findsaelement ( 6 , mem [p + 1 ].hh .v.LH , true ) ;
	if ( mem [curptr + 1 ].hh .v.RH == -1073741823L ) 
	{
	  mem [curptr + 1 ].hh .v.RH = mem [p + 1 ].hh .v.RH ;
	  incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
	} 
	if ( mem [curptr + 2 ].hh .v.LH != -1073741823L ) 
	deletetokenref ( mem [curptr + 2 ].hh .v.LH ) ;
	mem [curptr + 2 ].hh .v.LH = mem [p + 1 ].hh .v.RH ;
	incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
      } 
      else {
	  
	if ( curmark [1 ]== -1073741823L ) 
	{
	  curmark [1 ]= mem [p + 1 ].hh .v.RH ;
	  incr ( mem [curmark [1 ]].hh .v.LH ) ;
	} 
	if ( curmark [2 ]!= -1073741823L ) 
	deletetokenref ( curmark [2 ]) ;
	curmark [2 ]= mem [p + 1 ].hh .v.RH ;
	incr ( mem [curmark [2 ]].hh .v.LH ) ;
      } 
    } 
    prevp = p ;
    p = mem [prevp ].hh .v.RH ;
  } 
  eqtb [24538 ].hh .v.RH = savesplittopskip ;
  if ( p != -1073741823L ) 
  {
    if ( mem [memtop - 1 ].hh .v.RH == -1073741823L ) {
	
      if ( nestptr == 0 ) 
      curlist .tailfield = pagetail ;
      else nest [0 ].tailfield = pagetail ;
    } 
    mem [pagetail ].hh .v.RH = mem [memtop - 1 ].hh .v.RH ;
    mem [memtop - 1 ].hh .v.RH = p ;
    mem [prevp ].hh .v.RH = -1073741823L ;
  } 
  savevbadness = eqtb [29215 ].cint ;
  eqtb [29215 ].cint = 10000 ;
  savevfuzz = eqtb [29783 ].cint ;
  eqtb [29783 ].cint = 1073741823L ;
  eqtb [25587 ].hh .v.RH = vpackage ( mem [memtop - 2 ].hh .v.RH , 
  bestsize , 0 , pagemaxdepth ) ;
  mem [eqtb [25587 ].hh .v.RH ].hh.b1 = ( ( mem [eqtb [25587 ].hh .v.RH 
  ].hh.b1 ) / 8 ) * 8 + pagedir ;
  eqtb [29215 ].cint = savevbadness ;
  eqtb [29783 ].cint = savevfuzz ;
  if ( lastglue != 1073741823L ) 
  deleteglueref ( lastglue ) ;
  pagecontents = 0 ;
  pagetail = memtop - 2 ;
  mem [memtop - 2 ].hh .v.RH = -1073741823L ;
  lastglue = 1073741823L ;
  lastpenalty = 0 ;
  lastkern = 0 ;
  lastnodetype = -1 ;
  pagesofar [8 ]= 0 ;
  pagemaxdepth = 0 ;
  if ( q != memtop - 4 ) 
  {
    mem [memtop - 2 ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
    pagetail = q ;
  } 
  r = mem [memtop ].hh .v.RH ;
  while ( r != memtop ) {
      
    q = mem [r ].hh .v.RH ;
    freenode ( r , 4 ) ;
    r = q ;
  } 
  mem [memtop ].hh .v.RH = memtop ;
  if ( saroot [6 ]!= -1073741823L ) {
      
    if ( domarks ( 2 , 0 , saroot [6 ]) ) 
    saroot [6 ]= -1073741823L ;
  } 
  if ( ( curmark [0 ]!= -1073741823L ) && ( curmark [1 ]== -1073741823L ) 
  ) 
  {
    curmark [1 ]= curmark [0 ];
    incr ( mem [curmark [0 ]].hh .v.LH ) ;
  } 
  if ( eqtb [25062 ].hh .v.RH != -1073741823L ) {
      
    if ( deadcycles >= eqtb [29228 ].cint ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1110 ) ;
      } 
      printint ( deadcycles ) ;
      print ( 1111 ) ;
      {
	helpptr = 3 ;
	helpline [2 ]= 1112 ;
	helpline [1 ]= 1113 ;
	helpline [0 ]= 1114 ;
      } 
      error () ;
    } 
    else {
	
      outputactive = true ;
      incr ( deadcycles ) ;
      pushnest () ;
      curlist .modefield = -1 ;
      curlist .auxfield .cint = -65536000L ;
      curlist .mlfield = - (integer) line ;
      begintokenlist ( eqtb [25062 ].hh .v.RH , 6 ) ;
      newsavelevel ( 8 ) ;
      normalparagraph () ;
      scanleftbrace () ;
      return ;
    } 
  } 
  {
    if ( mem [memtop - 2 ].hh .v.RH != -1073741823L ) 
    {
      if ( mem [memtop - 1 ].hh .v.RH == -1073741823L ) {
	  
	if ( nestptr == 0 ) 
	curlist .tailfield = pagetail ;
	else nest [0 ].tailfield = pagetail ;
      } 
      else mem [pagetail ].hh .v.RH = mem [memtop - 1 ].hh .v.RH ;
      mem [memtop - 1 ].hh .v.RH = mem [memtop - 2 ].hh .v.RH ;
      mem [memtop - 2 ].hh .v.RH = -1073741823L ;
      pagetail = memtop - 2 ;
    } 
    flushnodelist ( discptr [2 ]) ;
    discptr [2 ]= -1073741823L ;
    shipout ( eqtb [25587 ].hh .v.RH ) ;
    eqtb [25587 ].hh .v.RH = -1073741823L ;
  } 
} 
void 
buildpage ( void ) 
{
  /* 10 30 31 22 80 90 */ buildpage_regmem 
  halfword p  ;
  halfword q, r  ;
  integer b, c  ;
  integer pi  ;
  unsigned char n  ;
  scaled delta, h, w  ;
  if ( ( mem [memtop - 1 ].hh .v.RH == -1073741823L ) || outputactive ) 
  return ;
  do {
      lab22: p = mem [memtop - 1 ].hh .v.RH ;
    if ( lastglue != 1073741823L ) 
    deleteglueref ( lastglue ) ;
    lastpenalty = 0 ;
    lastkern = 0 ;
    if ( mem [p ].hh.b0 < 2 ) 
    lastnodetype = mem [p ].hh.b0 + 1 ;
    else if ( mem [p ].hh.b0 == 2 ) 
    lastnodetype = mem [mem [p + 5 ].hh .v.RH ].hh.b0 + 1 ;
    else if ( mem [p ].hh.b0 < 5 ) 
    lastnodetype = mem [p ].hh.b0 ;
    else lastnodetype = mem [p ].hh.b0 - 1 ;
    if ( mem [p ].hh.b0 == 12 ) 
    {
      lastglue = mem [p + 1 ].hh .v.LH ;
      incr ( mem [lastglue ].hh .v.RH ) ;
    } 
    else {
	
      lastglue = 1073741823L ;
      if ( mem [p ].hh.b0 == 14 ) 
      lastpenalty = mem [p + 1 ].cint ;
      else if ( mem [p ].hh.b0 == 13 ) 
      lastkern = mem [p + 1 ].cint ;
    } 
    switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 2 : 
    case 3 : 
      if ( pagecontents < 2 ) 
      {
	if ( pagecontents == 0 ) 
	freezepagespecs ( 2 ) ;
	else pagecontents = 2 ;
	q = newskipparam ( 9 ) ;
	if ( mem [tempptr + 1 ].cint > mem [p + 3 ].cint ) 
	mem [tempptr + 1 ].cint = mem [tempptr + 1 ].cint - mem [p + 3 ]
	.cint ;
	else mem [tempptr + 1 ].cint = 0 ;
	mem [q ].hh .v.RH = p ;
	mem [memtop - 1 ].hh .v.RH = q ;
	goto lab22 ;
      } 
      else {
	  
	pagesofar [1 ]= pagesofar [1 ]+ pagesofar [8 ]+ mem [p + 3 ]
	.cint ;
	pagesofar [8 ]= mem [p + 2 ].cint ;
	goto lab80 ;
      } 
      break ;
    case 10 : 
      goto lab80 ;
      break ;
    case 12 : 
      if ( pagecontents < 2 ) 
      goto lab31 ;
      else if ( ( mem [pagetail ].hh.b0 < 11 ) ) 
      pi = 0 ;
      else goto lab90 ;
      break ;
    case 13 : 
      if ( pagecontents < 2 ) 
      goto lab31 ;
      else if ( mem [p ].hh .v.RH == -1073741823L ) 
      return ;
      else if ( mem [mem [p ].hh .v.RH ].hh.b0 == 12 ) 
      pi = 0 ;
      else goto lab90 ;
      break ;
    case 14 : 
      if ( pagecontents < 2 ) 
      goto lab31 ;
      else pi = mem [p + 1 ].cint ;
      break ;
    case 6 : 
      goto lab80 ;
      break ;
    case 4 : 
      {
	if ( pagecontents == 0 ) 
	freezepagespecs ( 1 ) ;
	n = mem [p ].hh.b1 ;
	r = memtop ;
	while ( n >= mem [mem [r ].hh .v.RH ].hh.b1 ) r = mem [r ].hh 
	.v.RH ;
	n = n ;
	if ( mem [r ].hh.b1 != n ) 
	{
	  q = getnode ( 4 ) ;
	  mem [q ].hh .v.RH = mem [r ].hh .v.RH ;
	  mem [r ].hh .v.RH = q ;
	  r = q ;
	  mem [r ].hh.b1 = n ;
	  mem [r ].hh.b0 = 0 ;
	  ensurevbox ( n ) ;
	  if ( eqtb [25332 + n ].hh .v.RH == -1073741823L ) 
	  mem [r + 3 ].cint = 0 ;
	  else {
	      
	    if ( mem [p + 5 ].hh.b1 != ( ( mem [eqtb [25332 + n ].hh 
	    .v.RH ].hh.b1 ) % 8 ) ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 264 ) ;
		print ( 1101 ) ;
	      } 
	      {
		helpptr = 3 ;
		helpline [2 ]= 1093 ;
		helpline [1 ]= 1102 ;
		helpline [0 ]= 1095 ;
	      } 
	      boxerror ( n ) ;
	    } 
	    else mem [r + 3 ].cint = mem [eqtb [25332 + n ].hh .v.RH + 3 
	    ].cint + mem [eqtb [25332 + n ].hh .v.RH + 2 ].cint ;
	  } 
	  mem [r + 2 ].hh .v.LH = -1073741823L ;
	  q = eqtb [24549 + n ].hh .v.RH ;
	  if ( eqtb [29262 + n ].cint == 1000 ) 
	  h = mem [r + 3 ].cint ;
	  else h = xovern ( mem [r + 3 ].cint , 1000 ) * eqtb [29262 + n ]
	  .cint ;
	  pagesofar [0 ]= pagesofar [0 ]- h - mem [q + 1 ].cint ;
	  pagesofar [2 + mem [q ].hh.b0 ]= pagesofar [2 + mem [q ]
	  .hh.b0 ]+ mem [q + 2 ].cint ;
	  pagesofar [7 ]= pagesofar [7 ]+ mem [q + 3 ].cint ;
	  if ( ( mem [q ].hh.b1 != 0 ) && ( mem [q + 3 ].cint != 0 ) ) 
	  {
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 264 ) ;
	      print ( 1103 ) ;
	    } 
	    printesc ( 417 ) ;
	    printint ( n ) ;
	    {
	      helpptr = 3 ;
	      helpline [2 ]= 1104 ;
	      helpline [1 ]= 1105 ;
	      helpline [0 ]= 1023 ;
	    } 
	    error () ;
	  } 
	} 
	if ( mem [r ].hh.b0 == 1 ) 
	insertpenalties = insertpenalties + mem [p + 1 ].cint ;
	else {
	    
	  mem [r + 2 ].hh .v.RH = p ;
	  delta = pagesofar [0 ]- pagesofar [1 ]- pagesofar [8 ]+ 
	  pagesofar [7 ];
	  if ( eqtb [29262 + n ].cint == 1000 ) 
	  h = mem [p + 3 ].cint ;
	  else h = xovern ( mem [p + 3 ].cint , 1000 ) * eqtb [29262 + n ]
	  .cint ;
	  if ( ( ( h <= 0 ) || ( h <= delta ) ) && ( mem [p + 3 ].cint + mem 
	  [r + 3 ].cint <= eqtb [29799 + n ].cint ) ) 
	  {
	    pagesofar [0 ]= pagesofar [0 ]- h ;
	    mem [r + 3 ].cint = mem [r + 3 ].cint + mem [p + 3 ].cint ;
	  } 
	  else {
	      
	    if ( eqtb [29262 + n ].cint <= 0 ) 
	    w = 1073741823L ;
	    else {
		
	      w = pagesofar [0 ]- pagesofar [1 ]- pagesofar [8 ];
	      if ( eqtb [29262 + n ].cint != 1000 ) 
	      w = xovern ( w , eqtb [29262 + n ].cint ) * 1000 ;
	    } 
	    if ( w > eqtb [29799 + n ].cint - mem [r + 3 ].cint ) 
	    w = eqtb [29799 + n ].cint - mem [r + 3 ].cint ;
	    q = vertbreak ( mem [p + 4 ].hh .v.LH , w , mem [p + 2 ].cint 
	    ) ;
	    mem [r + 3 ].cint = mem [r + 3 ].cint + bestheightplusdepth ;
	;
#ifdef STAT
	    if ( eqtb [29221 ].cint > 0 ) 
	    {
	      begindiagnostic () ;
	      printnl ( 1106 ) ;
	      printint ( n ) ;
	      print ( 1107 ) ;
	      printscaled ( w ) ;
	      printchar ( 44 ) ;
	      printscaled ( bestheightplusdepth ) ;
	      print ( 1032 ) ;
	      if ( q == -1073741823L ) 
	      printint ( -10000 ) ;
	      else if ( mem [q ].hh.b0 == 14 ) 
	      printint ( mem [q + 1 ].cint ) ;
	      else printchar ( 48 ) ;
	      enddiagnostic ( false ) ;
	    } 
#endif /* STAT */
	    if ( eqtb [29262 + n ].cint != 1000 ) 
	    bestheightplusdepth = xovern ( bestheightplusdepth , 1000 ) * eqtb 
	    [29262 + n ].cint ;
	    pagesofar [0 ]= pagesofar [0 ]- bestheightplusdepth ;
	    mem [r ].hh.b0 = 1 ;
	    mem [r + 1 ].hh .v.RH = q ;
	    mem [r + 1 ].hh .v.LH = p ;
	    if ( q == -1073741823L ) 
	    insertpenalties = insertpenalties - 10000 ;
	    else if ( mem [q ].hh.b0 == 14 ) 
	    insertpenalties = insertpenalties + mem [q + 1 ].cint ;
	  } 
	} 
	goto lab80 ;
      } 
      break ;
      default: 
      confusion ( 1096 ) ;
      break ;
    } 
    if ( pi < 10000 ) 
    {
      if ( pagesofar [1 ]< pagesofar [0 ]) {
	  
	if ( ( pagesofar [3 ]!= 0 ) || ( pagesofar [4 ]!= 0 ) || ( 
	pagesofar [5 ]!= 0 ) || ( pagesofar [6 ]!= 0 ) ) 
	b = 0 ;
	else b = badness ( pagesofar [0 ]- pagesofar [1 ], pagesofar [2 ]
	) ;
      } 
      else if ( pagesofar [1 ]- pagesofar [0 ]> pagesofar [7 ]) 
      b = 1073741823L ;
      else b = badness ( pagesofar [1 ]- pagesofar [0 ], pagesofar [7 ]) 
      ;
      if ( b < 1073741823L ) {
	  
	if ( pi <= -10000 ) 
	c = pi ;
	else if ( b < 10000 ) 
	c = b + pi + insertpenalties ;
	else c = 100000L ;
      } 
      else c = b ;
      if ( insertpenalties >= 10000 ) 
      c = 1073741823L ;
	;
#ifdef STAT
      if ( eqtb [29221 ].cint > 0 ) 
      {
	begindiagnostic () ;
	printnl ( 37 ) ;
	print ( 1028 ) ;
	printtotals () ;
	print ( 1099 ) ;
	printscaled ( pagesofar [0 ]) ;
	print ( 1031 ) ;
	if ( b == 1073741823L ) 
	printchar ( 42 ) ;
	else printint ( b ) ;
	print ( 1032 ) ;
	printint ( pi ) ;
	print ( 1100 ) ;
	if ( c == 1073741823L ) 
	printchar ( 42 ) ;
	else printint ( c ) ;
	if ( c <= leastpagecost ) 
	printchar ( 35 ) ;
	enddiagnostic ( false ) ;
      } 
#endif /* STAT */
      if ( c <= leastpagecost ) 
      {
	bestpagebreak = p ;
	bestsize = pagesofar [0 ];
	leastpagecost = c ;
	r = mem [memtop ].hh .v.RH ;
	while ( r != memtop ) {
	    
	  mem [r + 2 ].hh .v.LH = mem [r + 2 ].hh .v.RH ;
	  r = mem [r ].hh .v.RH ;
	} 
      } 
      if ( ( c == 1073741823L ) || ( pi <= -10000 ) ) 
      {
	fireup ( p ) ;
	if ( outputactive ) 
	return ;
	goto lab30 ;
      } 
    } 
    if ( ( mem [p ].hh.b0 < 12 ) || ( mem [p ].hh.b0 > 13 ) ) 
    goto lab80 ;
    lab90: if ( mem [p ].hh.b0 == 13 ) 
    q = p ;
    else {
	
      q = mem [p + 1 ].hh .v.LH ;
      pagesofar [2 + mem [q ].hh.b0 ]= pagesofar [2 + mem [q ].hh.b0 ]
      + mem [q + 2 ].cint ;
      pagesofar [7 ]= pagesofar [7 ]+ mem [q + 3 ].cint ;
      if ( ( mem [q ].hh.b1 != 0 ) && ( mem [q + 3 ].cint != 0 ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1097 ) ;
	} 
	{
	  helpptr = 4 ;
	  helpline [3 ]= 1098 ;
	  helpline [2 ]= 1064 ;
	  helpline [1 ]= 1065 ;
	  helpline [0 ]= 1023 ;
	} 
	error () ;
	r = newspec ( q ) ;
	mem [r ].hh.b1 = 0 ;
	deleteglueref ( q ) ;
	mem [p + 1 ].hh .v.LH = r ;
	q = r ;
      } 
    } 
    pagesofar [1 ]= pagesofar [1 ]+ pagesofar [8 ]+ mem [q + 1 ].cint 
    ;
    pagesofar [8 ]= 0 ;
    lab80: if ( pagesofar [8 ]> pagemaxdepth ) 
    {
      pagesofar [1 ]= pagesofar [1 ]+ pagesofar [8 ]- pagemaxdepth ;
      pagesofar [8 ]= pagemaxdepth ;
    } 
    mem [pagetail ].hh .v.RH = p ;
    pagetail = p ;
    mem [memtop - 1 ].hh .v.RH = mem [p ].hh .v.RH ;
    mem [p ].hh .v.RH = -1073741823L ;
    goto lab30 ;
    lab31: mem [memtop - 1 ].hh .v.RH = mem [p ].hh .v.RH ;
    mem [p ].hh .v.RH = -1073741823L ;
    if ( eqtb [29259 ].cint > 0 ) 
    {
      if ( discptr [2 ]== -1073741823L ) 
      discptr [2 ]= p ;
      else mem [discptr [1 ]].hh .v.RH = p ;
      discptr [1 ]= p ;
    } 
    else flushnodelist ( p ) ;
    lab30: ;
  } while ( ! ( mem [memtop - 1 ].hh .v.RH == -1073741823L ) ) ;
  if ( nestptr == 0 ) 
  curlist .tailfield = memtop - 1 ;
  else nest [0 ].tailfield = memtop - 1 ;
} 
void 
appspace ( void ) 
{
  appspace_regmem 
  halfword q  ;
  if ( ( curlist .auxfield .hh .v.LH >= 2000 ) && ( eqtb [24541 ].hh .v.RH 
  != membot ) ) 
  q = newparamglue ( 13 ) ;
  else {
      
    if ( eqtb [24540 ].hh .v.RH != membot ) 
    mainp = eqtb [24540 ].hh .v.RH ;
    else {
	
      mainp = fontglue [eqtb [25588 ].hh .v.RH ];
      if ( mainp == -1073741823L ) 
      {
	mainp = newspec ( membot ) ;
	maink = parambase [eqtb [25588 ].hh .v.RH ]+ 2 ;
	mem [mainp + 1 ].cint = fontinfo [maink ].cint ;
	mem [mainp + 2 ].cint = fontinfo [maink + 1 ].cint ;
	mem [mainp + 3 ].cint = fontinfo [maink + 2 ].cint ;
	fontglue [eqtb [25588 ].hh .v.RH ]= mainp ;
      } 
    } 
    mainp = newspec ( mainp ) ;
    if ( curlist .auxfield .hh .v.LH >= 2000 ) 
    mem [mainp + 1 ].cint = mem [mainp + 1 ].cint + fontinfo [7 + 
    parambase [eqtb [25588 ].hh .v.RH ]].cint ;
    mem [mainp + 2 ].cint = xnoverd ( mem [mainp + 2 ].cint , curlist 
    .auxfield .hh .v.LH , 1000 ) ;
    mem [mainp + 3 ].cint = xnoverd ( mem [mainp + 3 ].cint , 1000 , 
    curlist .auxfield .hh .v.LH ) ;
    q = newglue ( mainp ) ;
    mem [mainp ].hh .v.RH = -1073741823L ;
  } 
  if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield ]
  .hh.b0 == 5 ) ) 
  {
    mem [curlist .pnodefield ].hh .v.RH = q ;
    mem [q ].hh .v.RH = curlist .tailfield ;
    curlist .pnodefield = q ;
  } 
  else {
      
    mem [curlist .tailfield ].hh .v.RH = q ;
    curlist .tailfield = q ;
  } 
} 
void 
insertdollarsign ( void ) 
{
  insertdollarsign_regmem 
  backinput () ;
  curtok = 804 ;
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 1122 ) ;
  } 
  {
    helpptr = 2 ;
    helpline [1 ]= 1123 ;
    helpline [0 ]= 1124 ;
  } 
  inserror () ;
} 
void 
youcant ( void ) 
{
  youcant_regmem 
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 751 ) ;
  } 
  printcmdchr ( curcmd , curchr ) ;
  printinmode ( curlist .modefield ) ;
} 
void 
reportillegalcase ( void ) 
{
  reportillegalcase_regmem 
  youcant () ;
  {
    helpptr = 4 ;
    helpline [3 ]= 1125 ;
    helpline [2 ]= 1126 ;
    helpline [1 ]= 1127 ;
    helpline [0 ]= 1128 ;
  } 
  error () ;
} 
boolean 
privileged ( void ) 
{
  register boolean Result; privileged_regmem 
  if ( curlist .modefield > 0 ) 
  Result = true ;
  else {
      
    reportillegalcase () ;
    Result = false ;
  } 
  return Result ;
} 
boolean 
itsallover ( void ) 
{
  /* 10 */ register boolean Result; itsallover_regmem 
  if ( privileged () ) 
  {
    if ( ( memtop - 2 == pagetail ) && ( curlist .headfield == curlist 
    .tailfield ) && ( deadcycles == 0 ) ) 
    {
      Result = true ;
      return Result ;
    } 
    backinput () ;
    {
      mem [curlist .tailfield ].hh .v.RH = newnullbox () ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    mem [curlist .tailfield + 1 ].cint = eqtb [29777 ].cint ;
    {
      mem [curlist .tailfield ].hh .v.RH = newglue ( membot + 12 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = newpenalty ( -1073741824L ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    buildpage () ;
  } 
  Result = false ;
  return Result ;
} 
void 
appendglue ( void ) 
{
  appendglue_regmem 
  smallnumber s  ;
  s = curchr ;
  switch ( s ) 
  {case 0 : 
    curval = membot + 4 ;
    break ;
  case 1 : 
    curval = membot + 8 ;
    break ;
  case 2 : 
    curval = membot + 12 ;
    break ;
  case 3 : 
    curval = membot + 16 ;
    break ;
  case 4 : 
    curval = membot + 20 ;
    break ;
  case 5 : 
    scanglue ( 2 ) ;
    break ;
  case 6 : 
    scanglue ( 3 ) ;
    break ;
  } 
  {
    mem [curlist .tailfield ].hh .v.RH = newglue ( curval ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  inhibitglueflag = false ;
  if ( s >= 5 ) 
  {
    decr ( mem [curval ].hh .v.RH ) ;
    if ( s > 5 ) 
    mem [curlist .tailfield ].hh.b1 = 99 ;
  } 
} 
void 
appendkern ( void ) 
{
  appendkern_regmem 
  quarterword s  ;
  s = curchr ;
  scandimen ( s == 99 , false , false ) ;
  inhibitglueflag = false ;
  if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield ]
  .hh.b0 == 5 ) ) 
  {
    {
      mem [curlist .pnodefield ].hh .v.RH = newkern ( curval ) ;
      mem [mem [curlist .pnodefield ].hh .v.RH ].hh .v.RH = curlist 
      .tailfield ;
      curlist .pnodefield = mem [curlist .pnodefield ].hh .v.RH ;
    } 
    mem [curlist .pnodefield ].hh.b1 = s ;
  } 
  else {
      
    {
      mem [curlist .tailfield ].hh .v.RH = newkern ( curval ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    mem [curlist .tailfield ].hh.b1 = s ;
  } 
} 
void 
offsave ( void ) 
{
  offsave_regmem 
  halfword p  ;
  if ( curgroup == 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 875 ) ;
    } 
    printcmdchr ( curcmd , curchr ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 1148 ;
    } 
    error () ;
  } 
  else {
      
    backinput () ;
    p = getavail () ;
    mem [memtop - 3 ].hh .v.RH = p ;
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 686 ) ;
    } 
    switch ( curgroup ) 
    {case 14 : 
      {
	mem [p ].hh .v.LH = 536886427L ;
	printesc ( 560 ) ;
      } 
      break ;
    case 15 : 
      {
	mem [p ].hh .v.LH = 804 ;
	printchar ( 36 ) ;
      } 
      break ;
    case 16 : 
      {
	mem [p ].hh .v.LH = 536886428L ;
	mem [p ].hh .v.RH = getavail () ;
	p = mem [p ].hh .v.RH ;
	mem [p ].hh .v.LH = 3118 ;
	printesc ( 1147 ) ;
      } 
      break ;
      default: 
      {
	mem [p ].hh .v.LH = 637 ;
	printchar ( 125 ) ;
      } 
      break ;
    } 
    print ( 687 ) ;
    begintokenlist ( mem [memtop - 3 ].hh .v.RH , 4 ) ;
    {
      helpptr = 5 ;
      helpline [4 ]= 1142 ;
      helpline [3 ]= 1143 ;
      helpline [2 ]= 1144 ;
      helpline [1 ]= 1145 ;
      helpline [0 ]= 1146 ;
    } 
    error () ;
  } 
} 
void 
extrarightbrace ( void ) 
{
  extrarightbrace_regmem 
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 1153 ) ;
  } 
  switch ( curgroup ) 
  {case 14 : 
    printesc ( 560 ) ;
    break ;
  case 15 : 
    printchar ( 36 ) ;
    break ;
  case 16 : 
    printesc ( 976 ) ;
    break ;
  } 
  {
    helpptr = 5 ;
    helpline [4 ]= 1154 ;
    helpline [3 ]= 1155 ;
    helpline [2 ]= 1156 ;
    helpline [1 ]= 1157 ;
    helpline [0 ]= 1158 ;
  } 
  error () ;
  incr ( alignstate ) ;
} 
void 
normalparagraph ( void ) 
{
  normalparagraph_regmem 
  if ( eqtb [29207 ].cint != 0 ) 
  eqworddefine ( 29207 , 0 ) ;
  if ( eqtb [29791 ].cint != 0 ) 
  eqworddefine ( 29791 , 0 ) ;
  if ( eqtb [29229 ].cint != 1 ) 
  eqworddefine ( 29229 , 1 ) ;
  if ( eqtb [25061 ].hh .v.RH != -1073741823L ) 
  eqdefine ( 25061 , 134 , -1073741823L ) ;
  if ( eqtb [25328 ].hh .v.RH != -1073741823L ) 
  eqdefine ( 25328 , 134 , -1073741823L ) ;
} 
void 
zboxend ( integer boxcontext ) 
{
  boxend_regmem 
  halfword p  ;
  halfword q  ;
  smallnumber a  ;
  if ( boxcontext < 1073741824L ) 
  {
    if ( curbox != -1073741823L ) 
    {
      p = mem [curbox ].hh .v.RH ;
      mem [curbox ].hh .v.RH = -1073741823L ;
      while ( p != -1073741823L ) {
	  
	q = p ;
	p = mem [p ].hh .v.RH ;
	if ( ( ( mem [q ].hh.b1 ) % 8 ) == abs ( curlist .dirfield ) ) 
	{
	  mem [q + 5 ].hh .v.RH = curbox ;
	  curbox = q ;
	  mem [curbox ].hh .v.RH = -1073741823L ;
	} 
	else {
	    
	  deleteglueref ( mem [q + 7 ].hh .v.RH ) ;
	  deleteglueref ( mem [q + 7 ].hh .v.LH ) ;
	  freenode ( q , 10 ) ;
	} 
      } 
      if ( ( ( mem [curbox ].hh.b1 ) % 8 ) != abs ( curlist .dirfield ) ) 
      curbox = newdirnode ( curbox , abs ( curlist .dirfield ) ) ;
      mem [curbox + 4 ].cint = boxcontext ;
      if ( abs ( curlist .modefield ) == 1 ) 
      {
	appendtovlist ( curbox ) ;
	if ( adjusttail != -1073741823L ) 
	{
	  if ( memtop - 5 != adjusttail ) 
	  {
	    mem [curlist .tailfield ].hh .v.RH = mem [memtop - 5 ].hh 
	    .v.RH ;
	    curlist .tailfield = adjusttail ;
	  } 
	  adjusttail = -1073741823L ;
	} 
	if ( curlist .modefield > 0 ) 
	buildpage () ;
      } 
      else {
	  
	if ( abs ( curlist .modefield ) == 118 ) 
	curlist .auxfield .hh .v.LH = 1000 ;
	else {
	    
	  p = newnoad () ;
	  mem [p + 1 ].hh .v.RH = 3 ;
	  mem [p + 1 ].hh .v.LH = curbox ;
	  curbox = p ;
	} 
	mem [curlist .tailfield ].hh .v.RH = curbox ;
	curlist .tailfield = curbox ;
      } 
    } 
  } 
  else if ( boxcontext < 1073872896L ) 
  {
    if ( boxcontext < 1073807360L ) 
    {
      curval = boxcontext - 1073741824L ;
      a = 0 ;
    } 
    else {
	
      curval = boxcontext - 1073807360L ;
      a = 4 ;
    } 
    if ( curval < 256 ) {
	
      if ( ( a >= 4 ) ) 
      geqdefine ( 25332 + curval , 135 , curbox ) ;
      else eqdefine ( 25332 + curval , 135 , curbox ) ;
    } 
    else {
	
      findsaelement ( 4 , curval , true ) ;
      if ( ( a >= 4 ) ) 
      gsadef ( curptr , curbox ) ;
      else sadef ( curptr , curbox ) ;
    } 
  } 
  else if ( curbox != -1073741823L ) {
      
    if ( boxcontext > 1073872896L ) 
    {
      do {
	  getxtoken () ;
      } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
      if ( ( ( curcmd == 30 ) && ( abs ( curlist .modefield ) != 1 ) ) || ( ( 
      curcmd == 31 ) && ( abs ( curlist .modefield ) == 1 ) ) ) 
      {
	appendglue () ;
	mem [curlist .tailfield ].hh.b1 = boxcontext - ( 1073872797L ) ;
	if ( mem [curbox ].hh.b0 <= 2 ) 
	{
	  p = mem [curbox ].hh .v.RH ;
	  mem [curbox ].hh .v.RH = -1073741823L ;
	  while ( p != -1073741823L ) {
	      
	    q = p ;
	    p = mem [p ].hh .v.RH ;
	    if ( ( ( mem [q ].hh.b1 ) % 8 ) == abs ( curlist .dirfield ) ) 
	    {
	      mem [q + 5 ].hh .v.RH = curbox ;
	      curbox = q ;
	      mem [curbox ].hh .v.RH = -1073741823L ;
	    } 
	    else {
		
	      deleteglueref ( mem [q + 7 ].hh .v.RH ) ;
	      deleteglueref ( mem [q + 7 ].hh .v.LH ) ;
	      freenode ( q , 10 ) ;
	    } 
	  } 
	  if ( ( ( mem [curbox ].hh.b1 ) % 8 ) != abs ( curlist .dirfield ) 
	  ) 
	  curbox = newdirnode ( curbox , abs ( curlist .dirfield ) ) ;
	} 
	mem [curlist .tailfield + 1 ].hh .v.RH = curbox ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1181 ) ;
	} 
	{
	  helpptr = 3 ;
	  helpline [2 ]= 1182 ;
	  helpline [1 ]= 1183 ;
	  helpline [0 ]= 1184 ;
	} 
	backerror () ;
	flushnodelist ( curbox ) ;
      } 
    } 
    else shipout ( curbox ) ;
  } 
} 
void 
zbeginbox ( integer boxcontext ) 
{
  /* 10 30 */ beginbox_regmem 
  halfword p, q  ;
  halfword r  ;
  halfword s  ;
  halfword t  ;
  integer fm  ;
  integer gm  ;
  integer fd, gd  ;
  scaled disp, pdisp  ;
  eightbits adir  ;
  halfword tx  ;
  quarterword m  ;
  halfword k  ;
  halfword n  ;
  switch ( curchr ) 
  {case 0 : 
    {
      scanregisternum () ;
      if ( curval < 256 ) 
      curbox = eqtb [25332 + curval ].hh .v.RH ;
      else {
	  
	findsaelement ( 4 , curval , false ) ;
	if ( curptr == -1073741823L ) 
	curbox = -1073741823L ;
	else curbox = mem [curptr + 1 ].hh .v.RH ;
      } 
      if ( curval < 256 ) 
      eqtb [25332 + curval ].hh .v.RH = -1073741823L ;
      else {
	  
	findsaelement ( 4 , curval , false ) ;
	if ( curptr != -1073741823L ) 
	{
	  mem [curptr + 1 ].hh .v.RH = -1073741823L ;
	  incr ( mem [curptr + 1 ].hh .v.LH ) ;
	  deletesaref ( curptr ) ;
	} 
      } 
    } 
    break ;
  case 1 : 
    {
      scanregisternum () ;
      if ( curval < 256 ) 
      q = eqtb [25332 + curval ].hh .v.RH ;
      else {
	  
	findsaelement ( 4 , curval , false ) ;
	if ( curptr == -1073741823L ) 
	q = -1073741823L ;
	else q = mem [curptr + 1 ].hh .v.RH ;
      } 
      curbox = copynodelist ( q ) ;
    } 
    break ;
  case 2 : 
    {
      curbox = -1073741823L ;
      if ( abs ( curlist .modefield ) == 235 ) 
      {
	youcant () ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1190 ;
	} 
	error () ;
      } 
      else if ( ( curlist .modefield == 1 ) && ( curlist .headfield == curlist 
      .tailfield ) ) 
      {
	youcant () ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1191 ;
	  helpline [0 ]= 1192 ;
	} 
	error () ;
      } 
      else {
	  
	tx = curlist .tailfield ;
	if ( ! ( tx >= himemmin ) ) {
	    
	  if ( mem [tx ].hh.b0 == 5 ) 
	  tx = curlist .pnodefield ;
	} 
	if ( ! ( tx >= himemmin ) ) {
	    
	  if ( ( mem [tx ].hh.b0 == 5 ) || ( ( mem [tx ].hh.b0 == 11 ) && 
	  ( mem [tx ].hh.b1 == 3 ) ) ) 
	  {
	    r = curlist .headfield ;
	    q = mem [curlist .headfield ].hh .v.RH ;
	    while ( q != tx ) {
		
	      if ( ( q >= himemmin ) ) 
	      r = q ;
	      else if ( ( mem [q ].hh.b0 != 5 ) && ( ( mem [q ].hh.b0 != 
	      11 ) || ( mem [q ].hh.b1 != 3 ) ) ) 
	      r = q ;
	      q = mem [q ].hh .v.RH ;
	    } 
	    tx = r ;
	  } 
	} 
	if ( ! ( tx >= himemmin ) && ( curlist .headfield != tx ) ) {
	    
	  if ( ( mem [tx ].hh.b0 == 0 ) || ( mem [tx ].hh.b0 == 1 ) || ( 
	  mem [tx ].hh.b0 == 2 ) ) 
	  {
	    q = curlist .headfield ;
	    p = -1073741823L ;
	    r = -1073741823L ;
	    fm = 0 ;
	    fd = 0 ;
	    disp = 0 ;
	    pdisp = 0 ;
	    do {
		s = r ;
	      r = p ;
	      p = q ;
	      fm = fm / 2 ;
	      fd = fd / 2 ;
	      if ( ! ( q >= himemmin ) ) {
		  
		if ( mem [q ].hh.b0 == 9 ) 
		{
		  {register integer for_end; m = 1 ;for_end = mem [q ]
		  .hh.b1 ; if ( m <= for_end) do 
		    {
		      p = mem [p ].hh .v.RH ;
		      if ( p == tx ) 
		      goto lab30 ;
		    } 
		  while ( m++ < for_end ) ;} 
		} 
		else if ( ( mem [q ].hh.b0 == 11 ) && ( mem [q ].hh.b1 == 
		2 ) ) 
		fm = 2 ;
		else if ( mem [q ].hh.b0 == 5 ) 
		{
		  pdisp = disp ;
		  disp = mem [q + 1 ].cint ;
		  fd = 2 ;
		} 
	      } 
	      q = mem [p ].hh .v.RH ;
	    } while ( ! ( q == tx ) ) ;
	    q = mem [tx ].hh .v.RH ;
	    mem [p ].hh .v.RH = q ;
	    mem [tx ].hh .v.RH = -1073741823L ;
	    if ( q == -1073741823L ) 
	    {
	      curlist .tailfield = p ;
	      gm = 0 ;
	      gd = 0 ;
	    } 
	    else {
		
	      if ( mem [q ].hh.b0 == 11 ) 
	      {
		gm = 2 ;
		if ( mem [q ].hh .v.RH == -1073741823L ) 
		gd = 0 ;
		else if ( mem [mem [q ].hh .v.RH ].hh.b0 == 5 ) 
		gd = 1 ;
		else confusion ( 1186 ) ;
	      } 
	      else if ( mem [q ].hh.b0 == 5 ) 
	      {
		curlist .pnodefield = p ;
		gd = 2 ;
		if ( mem [q ].hh .v.RH == -1073741823L ) 
		gm = 0 ;
		else if ( mem [mem [q ].hh .v.RH ].hh.b0 == 11 ) 
		gm = 1 ;
		else confusion ( 1187 ) ;
	      } 
	      else confusion ( 1188 ) ;
	    } 
	    if ( gm == 0 ) {
		
	      if ( fm == 2 ) 
	      confusion ( 1185 ) ;
	      else if ( fm == 1 ) 
	      confusion ( 1189 ) ;
	    } 
	    if ( ( fm + fd ) == 1 ) 
	    {
	      fm = 0 ;
	      fd = 0 ;
	    } 
	    if ( gm == 0 ) 
	    fm = 0 ;
	    if ( gd == 0 ) 
	    fd = 0 ;
	    if ( fd > 0 ) 
	    {
	      if ( gm == 0 ) 
	      {
		t = q ;
		q = -1073741823L ;
		mem [p ].hh .v.RH = q ;
		curlist .tailfield = p ;
	      } 
	      else if ( gm == 1 ) 
	      {
		t = q ;
		q = mem [q ].hh .v.RH ;
		mem [p ].hh .v.RH = q ;
		gm = 2 ;
	      } 
	      else {
		  
		t = mem [q ].hh .v.RH ;
		mem [q ].hh .v.RH = -1073741823L ;
		curlist .tailfield = q ;
	      } 
	      if ( fd == 1 ) 
	      {
		curlist .pnodefield = s ;
		mem [r + 1 ].cint = mem [t + 1 ].cint ;
	      } 
	      else {
		  
		curlist .pnodefield = r ;
		mem [p + 1 ].cint = mem [t + 1 ].cint ;
	      } 
	      curlist .pdispfield = pdisp ;
	      freenode ( t , 2 ) ;
	      gd = 0 ;
	    } 
	    if ( fm > 0 ) 
	    {
	      if ( gd == 0 ) 
	      {
		t = q ;
		q = -1073741823L ;
		mem [p ].hh .v.RH = q ;
		curlist .tailfield = p ;
	      } 
	      else if ( gd == 1 ) 
	      {
		t = q ;
		q = mem [q ].hh .v.RH ;
		mem [p ].hh .v.RH = q ;
		curlist .pnodefield = p ;
		mem [t ].hh .v.RH = -1073741823L ;
	      } 
	      else {
		  
		t = mem [q ].hh .v.RH ;
		mem [q ].hh .v.RH = -1073741823L ;
		curlist .tailfield = q ;
	      } 
	      if ( fm == 1 ) 
	      {
		mem [s ].hh .v.RH = p ;
		mem [r ].hh .v.RH = t ;
		t = r ;
		curlist .pnodefield = s ;
	      } 
	      else {
		  
		mem [r ].hh .v.RH = q ;
		mem [p ].hh .v.RH = t ;
		t = p ;
		if ( q == -1073741823L ) 
		curlist .tailfield = r ;
		else curlist .pnodefield = r ;
	      } 
	      flushnodelist ( t ) ;
	    } 
	    curbox = tx ;
	    mem [curbox + 4 ].cint = 0 ;
	    if ( mem [curbox ].hh.b0 == 2 ) 
	    {
	      mem [mem [curbox + 5 ].hh .v.RH ].hh .v.RH = curbox ;
	      curbox = mem [curbox + 5 ].hh .v.RH ;
	      mem [mem [curbox ].hh .v.RH + 5 ].hh .v.RH = -1073741823L ;
	    } 
	    else if ( ( ( mem [curbox ].hh.b1 ) % 8 ) == 0 ) 
	    mem [curbox ].hh.b1 = ( ( mem [curbox ].hh.b1 ) / 8 ) * 8 + 
	    abs ( curlist .dirfield ) ;
	  } 
	} 
	lab30: ;
      } 
    } 
    break ;
  case 3 : 
    {
      scanregisternum () ;
      n = curval ;
      if ( ! scankeyword ( 941 ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1193 ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1194 ;
	  helpline [0 ]= 1195 ;
	} 
	error () ;
      } 
      scandimen ( false , false , false ) ;
      curbox = vsplit ( n , curval ) ;
    } 
    break ;
    default: 
    {
      k = curchr - 4 ;
      savestack [saveptr + 0 ].cint = boxcontext ;
      adir = curlist .adjdirfield ;
      if ( k == 118 ) {
	  
	if ( ( boxcontext < 1073741824L ) && ( abs ( curlist .modefield ) == 1 
	) ) 
	{
	  adir = abs ( curlist .dirfield ) ;
	  scanspec ( 3 , true ) ;
	} 
	else scanspec ( 2 , true ) ;
      } 
      else {
	  
	if ( k == 1 ) 
	scanspec ( 4 , true ) ;
	else {
	    
	  scanspec ( 5 , true ) ;
	  k = 1 ;
	} 
	normalparagraph () ;
      } 
      pushnest () ;
      curlist .modefield = - (integer) k ;
      curlist .adjdirfield = adir ;
      if ( k == 1 ) 
      {
	curlist .auxfield .cint = -65536000L ;
	if ( eqtb [25067 ].hh .v.RH != -1073741823L ) 
	begintokenlist ( eqtb [25067 ].hh .v.RH , 11 ) ;
      } 
      else {
	  
	curlist .auxfield .hh .v.LH = 1000 ;
	if ( eqtb [25066 ].hh .v.RH != -1073741823L ) 
	begintokenlist ( eqtb [25066 ].hh .v.RH , 10 ) ;
      } 
      return ;
    } 
    break ;
  } 
  boxend ( boxcontext ) ;
} 
void 
zscanbox ( integer boxcontext ) 
{
  scanbox_regmem 
  do {
      getxtoken () ;
  } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
  if ( curcmd == 24 ) 
  beginbox ( boxcontext ) ;
  else if ( ( boxcontext >= 1073872897L ) && ( ( curcmd == 40 ) || ( curcmd == 
  39 ) ) ) 
  {
    curbox = scanrulespec () ;
    boxend ( boxcontext ) ;
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1196 ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 1197 ;
      helpline [1 ]= 1198 ;
      helpline [0 ]= 1199 ;
    } 
    backerror () ;
  } 
} 
void 
zpackage ( smallnumber c ) 
{
  package_regmem 
  scaled h  ;
  halfword p  ;
  scaled d  ;
  d = eqtb [29781 ].cint ;
  deleteglueref ( curkanjiskip ) ;
  deleteglueref ( curxkanjiskip ) ;
  if ( eqtb [26359 ].hh .v.RH > 0 ) 
  curkanjiskip = eqtb [24543 ].hh .v.RH ;
  else curkanjiskip = membot ;
  if ( eqtb [26360 ].hh .v.RH > 0 ) 
  curxkanjiskip = eqtb [24544 ].hh .v.RH ;
  else curxkanjiskip = membot ;
  incr ( mem [curkanjiskip ].hh .v.RH ) ;
  incr ( mem [curxkanjiskip ].hh .v.RH ) ;
  unsave () ;
  saveptr = saveptr - 3 ;
  if ( curlist .modefield == -118 ) 
  {
    curbox = hpack ( mem [curlist .headfield ].hh .v.RH , savestack [
    saveptr + 2 ].cint , savestack [saveptr + 1 ].cint ) ;
    mem [curbox ].hh.b1 = ( ( mem [curbox ].hh.b1 ) / 8 ) * 8 + abs ( 
    curlist .dirfield ) ;
    popnest () ;
  } 
  else {
      
    curbox = vpackage ( mem [curlist .headfield ].hh .v.RH , savestack [
    saveptr + 2 ].cint , savestack [saveptr + 1 ].cint , d ) ;
    mem [curbox ].hh.b1 = ( ( mem [curbox ].hh.b1 ) / 8 ) * 8 + abs ( 
    curlist .dirfield ) ;
    popnest () ;
    if ( c == 4 ) 
    {
      h = 0 ;
      p = mem [curbox + 5 ].hh .v.RH ;
      if ( p != -1073741823L ) {
	  
	if ( mem [p ].hh.b0 <= 3 ) 
	h = mem [p + 3 ].cint ;
      } 
      mem [curbox + 2 ].cint = mem [curbox + 2 ].cint - h + mem [curbox + 
      3 ].cint ;
      mem [curbox + 3 ].cint = h ;
    } 
  } 
  boxend ( savestack [saveptr + 0 ].cint ) ;
} 
smallnumber 
znormmin ( integer h ) 
{
  register smallnumber Result; normmin_regmem 
  if ( h <= 0 ) 
  Result = 1 ;
  else if ( h >= 63 ) 
  Result = 63 ;
  else Result = h ;
  return Result ;
} 
void 
znewgraf ( boolean indented ) 
{
  newgraf_regmem 
  curlist .pgfield = 0 ;
  if ( ( curlist .modefield == 1 ) || ( curlist .headfield != curlist 
  .tailfield ) ) 
  {
    mem [curlist .tailfield ].hh .v.RH = newparamglue ( 2 ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  inhibitglueflag = false ;
  pushnest () ;
  curlist .adjdirfield = abs ( curlist .dirfield ) ;
  curlist .modefield = 118 ;
  curlist .auxfield .hh .v.LH = 1000 ;
  if ( eqtb [29239 ].cint <= 0 ) 
  curlang = 0 ;
  else if ( eqtb [29239 ].cint > 255 ) 
  curlang = 0 ;
  else curlang = eqtb [29239 ].cint ;
  curlist .auxfield .hh .v.RH = curlang ;
  curlist .pgfield = ( normmin ( eqtb [29240 ].cint ) * 64 + normmin ( eqtb 
  [29241 ].cint ) ) * 65536L + curlang ;
  if ( indented ) 
  {
    curlist .tailfield = newnullbox () ;
    mem [curlist .headfield ].hh .v.RH = curlist .tailfield ;
    mem [curlist .tailfield + 1 ].cint = eqtb [29774 ].cint ;
    if ( ( insertsrcspecialeverypar ) ) 
    insertsrcspecial () ;
  } 
  if ( eqtb [25063 ].hh .v.RH != -1073741823L ) 
  begintokenlist ( eqtb [25063 ].hh .v.RH , 7 ) ;
  if ( nestptr == 1 ) 
  buildpage () ;
} 
void 
indentinhmode ( void ) 
{
  indentinhmode_regmem 
  halfword p, q  ;
  if ( curchr > 0 ) 
  {
    p = newnullbox () ;
    mem [p + 1 ].cint = eqtb [29774 ].cint ;
    if ( abs ( curlist .modefield ) == 118 ) 
    curlist .auxfield .hh .v.LH = 1000 ;
    else {
	
      q = newnoad () ;
      mem [q + 1 ].hh .v.RH = 2 ;
      mem [q + 1 ].hh .v.LH = p ;
      p = q ;
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = p ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
  } 
} 
void 
headforvmode ( void ) 
{
  headforvmode_regmem 
  if ( curlist .modefield < 0 ) {
      
    if ( curcmd != 40 ) 
    offsave () ;
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 751 ) ;
      } 
      printesc ( 567 ) ;
      print ( 1202 ) ;
      {
	helpptr = 2 ;
	helpline [1 ]= 1203 ;
	helpline [0 ]= 1204 ;
      } 
      error () ;
    } 
  } 
  else {
      
    backinput () ;
    curtok = partoken ;
    backinput () ;
    curinput .indexfield = 4 ;
  } 
} 
void 
endgraf ( void ) 
{
  endgraf_regmem 
  if ( curlist .modefield == 118 ) 
  {
    if ( curlist .headfield == curlist .tailfield ) 
    popnest () ;
    else {
	
      adjusthlist ( curlist .headfield , true ) ;
      linebreak ( false ) ;
    } 
    if ( curlist .eTeXauxfield != -1073741823L ) 
    {
      flushlist ( curlist .eTeXauxfield ) ;
      curlist .eTeXauxfield = -1073741823L ;
    } 
    normalparagraph () ;
    errorcount = 0 ;
  } 
} 
void 
begininsertoradjust ( void ) 
{
  begininsertoradjust_regmem 
  if ( curcmd == 42 ) 
  curval = 255 ;
  else {
      
    scaneightbitint () ;
    if ( curval == 255 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1205 ) ;
      } 
      printesc ( 336 ) ;
      printint ( 255 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 1206 ;
      } 
      error () ;
      curval = 0 ;
    } 
  } 
  savestack [saveptr + 0 ].cint = curval ;
  incr ( saveptr ) ;
  newsavelevel ( 11 ) ;
  scanleftbrace () ;
  normalparagraph () ;
  pushnest () ;
  curlist .modefield = -1 ;
  curlist .dirfield = curlist .adjdirfield ;
  curlist .auxfield .cint = -65536000L ;
} 
void 
makemark ( void ) 
{
  makemark_regmem 
  halfword p  ;
  halfword c  ;
  if ( curchr == 0 ) 
  c = 0 ;
  else {
      
    scanregisternum () ;
    c = curval ;
  } 
  p = scantoks ( false , true ) ;
  p = getnode ( 2 ) ;
  mem [p + 1 ].hh .v.LH = c ;
  mem [p ].hh.b0 = 6 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].hh .v.RH = defref ;
  if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield ]
  .hh.b0 == 5 ) ) 
  {
    mem [curlist .pnodefield ].hh .v.RH = p ;
    mem [mem [curlist .pnodefield ].hh .v.RH ].hh .v.RH = curlist 
    .tailfield ;
    curlist .pnodefield = mem [curlist .pnodefield ].hh .v.RH ;
  } 
  else {
      
    mem [curlist .tailfield ].hh .v.RH = p ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
} 
void 
appendpenalty ( void ) 
{
  appendpenalty_regmem 
  scanint () ;
  if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield ]
  .hh.b0 == 5 ) ) 
  {
    mem [curlist .pnodefield ].hh .v.RH = newpenalty ( curval ) ;
    mem [mem [curlist .pnodefield ].hh .v.RH ].hh .v.RH = curlist 
    .tailfield ;
    curlist .pnodefield = mem [curlist .pnodefield ].hh .v.RH ;
  } 
  else {
      
    mem [curlist .tailfield ].hh .v.RH = newpenalty ( curval ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  if ( curlist .modefield == 1 ) 
  buildpage () ;
} 
void 
deletelast ( void ) 
{
  /* 10 */ deletelast_regmem 
  halfword p, q  ;
  halfword r  ;
  halfword s  ;
  halfword t  ;
  integer fm  ;
  integer gm  ;
  integer fd, gd  ;
  scaled disp, pdisp  ;
  halfword tx  ;
  quarterword m  ;
  if ( ( curlist .modefield == 1 ) && ( curlist .tailfield == curlist 
  .headfield ) ) 
  {
    if ( ( curchr != 12 ) || ( lastglue != 1073741823L ) ) 
    {
      youcant () ;
      {
	helpptr = 2 ;
	helpline [1 ]= 1191 ;
	helpline [0 ]= 1209 ;
      } 
      if ( curchr == 13 ) 
      helpline [0 ]= ( 1210 ) ;
      else if ( curchr != 12 ) 
      helpline [0 ]= ( 1211 ) ;
      error () ;
    } 
  } 
  else {
      
    tx = curlist .tailfield ;
    if ( ! ( tx >= himemmin ) ) {
	
      if ( mem [tx ].hh.b0 == 5 ) 
      tx = curlist .pnodefield ;
    } 
    if ( ! ( tx >= himemmin ) ) {
	
      if ( ( mem [tx ].hh.b0 == 5 ) || ( ( mem [tx ].hh.b0 == 11 ) && ( 
      mem [tx ].hh.b1 == 3 ) ) ) 
      {
	r = curlist .headfield ;
	q = mem [curlist .headfield ].hh .v.RH ;
	while ( q != tx ) {
	    
	  if ( ( q >= himemmin ) ) 
	  r = q ;
	  else if ( ( mem [q ].hh.b0 != 5 ) && ( ( mem [q ].hh.b0 != 11 ) 
	  || ( mem [q ].hh.b1 != 3 ) ) ) 
	  r = q ;
	  q = mem [q ].hh .v.RH ;
	} 
	tx = r ;
      } 
    } 
    if ( ! ( tx >= himemmin ) ) {
	
      if ( mem [tx ].hh.b0 == curchr ) 
      {
	q = curlist .headfield ;
	p = -1073741823L ;
	r = -1073741823L ;
	fm = 0 ;
	fd = 0 ;
	disp = 0 ;
	pdisp = 0 ;
	do {
	    s = r ;
	  r = p ;
	  p = q ;
	  fm = fm / 2 ;
	  fd = fd / 2 ;
	  if ( ! ( q >= himemmin ) ) {
	      
	    if ( mem [q ].hh.b0 == 9 ) 
	    {
	      {register integer for_end; m = 1 ;for_end = mem [q ].hh.b1 
	      ; if ( m <= for_end) do 
		{
		  p = mem [p ].hh .v.RH ;
		  if ( p == tx ) 
		  return ;
		} 
	      while ( m++ < for_end ) ;} 
	    } 
	    else if ( ( mem [q ].hh.b0 == 11 ) && ( mem [q ].hh.b1 == 2 ) 
	    ) 
	    fm = 2 ;
	    else if ( mem [q ].hh.b0 == 5 ) 
	    {
	      pdisp = disp ;
	      disp = mem [q + 1 ].cint ;
	      fd = 2 ;
	    } 
	  } 
	  q = mem [p ].hh .v.RH ;
	} while ( ! ( q == tx ) ) ;
	q = mem [tx ].hh .v.RH ;
	mem [p ].hh .v.RH = q ;
	mem [tx ].hh .v.RH = -1073741823L ;
	if ( q == -1073741823L ) 
	{
	  curlist .tailfield = p ;
	  gm = 0 ;
	  gd = 0 ;
	} 
	else {
	    
	  if ( mem [q ].hh.b0 == 11 ) 
	  {
	    gm = 2 ;
	    if ( mem [q ].hh .v.RH == -1073741823L ) 
	    gd = 0 ;
	    else if ( mem [mem [q ].hh .v.RH ].hh.b0 == 5 ) 
	    gd = 1 ;
	    else confusion ( 1186 ) ;
	  } 
	  else if ( mem [q ].hh.b0 == 5 ) 
	  {
	    curlist .pnodefield = p ;
	    gd = 2 ;
	    if ( mem [q ].hh .v.RH == -1073741823L ) 
	    gm = 0 ;
	    else if ( mem [mem [q ].hh .v.RH ].hh.b0 == 11 ) 
	    gm = 1 ;
	    else confusion ( 1187 ) ;
	  } 
	  else confusion ( 1188 ) ;
	} 
	if ( gm == 0 ) {
	    
	  if ( fm == 2 ) 
	  confusion ( 1185 ) ;
	  else if ( fm == 1 ) 
	  confusion ( 1189 ) ;
	} 
	if ( ( fm + fd ) == 1 ) 
	{
	  fm = 0 ;
	  fd = 0 ;
	} 
	if ( gm == 0 ) 
	fm = 0 ;
	if ( gd == 0 ) 
	fd = 0 ;
	if ( fd > 0 ) 
	{
	  if ( gm == 0 ) 
	  {
	    t = q ;
	    q = -1073741823L ;
	    mem [p ].hh .v.RH = q ;
	    curlist .tailfield = p ;
	  } 
	  else if ( gm == 1 ) 
	  {
	    t = q ;
	    q = mem [q ].hh .v.RH ;
	    mem [p ].hh .v.RH = q ;
	    gm = 2 ;
	  } 
	  else {
	      
	    t = mem [q ].hh .v.RH ;
	    mem [q ].hh .v.RH = -1073741823L ;
	    curlist .tailfield = q ;
	  } 
	  if ( fd == 1 ) 
	  {
	    curlist .pnodefield = s ;
	    mem [r + 1 ].cint = mem [t + 1 ].cint ;
	  } 
	  else {
	      
	    curlist .pnodefield = r ;
	    mem [p + 1 ].cint = mem [t + 1 ].cint ;
	  } 
	  curlist .pdispfield = pdisp ;
	  freenode ( t , 2 ) ;
	  gd = 0 ;
	} 
	if ( fm > 0 ) 
	{
	  if ( gd == 0 ) 
	  {
	    t = q ;
	    q = -1073741823L ;
	    mem [p ].hh .v.RH = q ;
	    curlist .tailfield = p ;
	  } 
	  else if ( gd == 1 ) 
	  {
	    t = q ;
	    q = mem [q ].hh .v.RH ;
	    mem [p ].hh .v.RH = q ;
	    curlist .pnodefield = p ;
	    mem [t ].hh .v.RH = -1073741823L ;
	  } 
	  else {
	      
	    t = mem [q ].hh .v.RH ;
	    mem [q ].hh .v.RH = -1073741823L ;
	    curlist .tailfield = q ;
	  } 
	  if ( fm == 1 ) 
	  {
	    mem [s ].hh .v.RH = p ;
	    mem [r ].hh .v.RH = t ;
	    t = r ;
	    curlist .pnodefield = s ;
	  } 
	  else {
	      
	    mem [r ].hh .v.RH = q ;
	    mem [p ].hh .v.RH = t ;
	    t = p ;
	    if ( q == -1073741823L ) 
	    curlist .tailfield = r ;
	    else curlist .pnodefield = r ;
	  } 
	  flushnodelist ( t ) ;
	} 
	flushnodelist ( tx ) ;
      } 
    } 
  } 
} 
void 
unpackage ( void ) 
{
  /* 30 10 */ unpackage_regmem 
  halfword p  ;
  unsigned char c  ;
  scaled disp  ;
  if ( curchr > 1 ) 
  {
    mem [curlist .tailfield ].hh .v.RH = discptr [curchr ];
    discptr [curchr ]= -1073741823L ;
    goto lab30 ;
  } 
  c = curchr ;
  scanregisternum () ;
  if ( curval < 256 ) 
  p = eqtb [25332 + curval ].hh .v.RH ;
  else {
      
    findsaelement ( 4 , curval , false ) ;
    if ( curptr == -1073741823L ) 
    p = -1073741823L ;
    else p = mem [curptr + 1 ].hh .v.RH ;
  } 
  if ( p == -1073741823L ) 
  return ;
  if ( mem [p ].hh.b0 == 2 ) 
  p = mem [p + 5 ].hh .v.RH ;
  if ( ( abs ( curlist .modefield ) == 235 ) || ( ( abs ( curlist .modefield ) 
  == 1 ) && ( mem [p ].hh.b0 != 1 ) ) || ( ( abs ( curlist .modefield ) == 
  118 ) && ( mem [p ].hh.b0 != 0 ) ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1219 ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 1220 ;
      helpline [1 ]= 1221 ;
      helpline [0 ]= 1222 ;
    } 
    error () ;
    return ;
  } 
  switch ( ( ( mem [p ].hh.b1 ) % 8 ) ) 
  {case 4 : 
  case 3 : 
  case 1 : 
    if ( abs ( curlist .dirfield ) != ( ( mem [p ].hh.b1 ) % 8 ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1223 ) ;
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 1220 ;
	helpline [0 ]= 1224 ;
      } 
      error () ;
      return ;
    } 
    break ;
  } 
  disp = 0 ;
  if ( c == 1 ) 
  mem [curlist .tailfield ].hh .v.RH = copynodelist ( mem [p + 5 ].hh 
  .v.RH ) ;
  else {
      
    if ( mem [p ].hh.b0 == 2 ) 
    {
      deleteglueref ( mem [p + 7 ].hh .v.RH ) ;
      deleteglueref ( mem [p + 7 ].hh .v.LH ) ;
      freenode ( p , 10 ) ;
    } 
    flushnodelist ( mem [p ].hh .v.RH ) ;
    mem [curlist .tailfield ].hh .v.RH = mem [p + 5 ].hh .v.RH ;
    if ( curval < 256 ) 
    eqtb [25332 + curval ].hh .v.RH = -1073741823L ;
    else {
	
      findsaelement ( 4 , curval , false ) ;
      if ( curptr != -1073741823L ) 
      {
	mem [curptr + 1 ].hh .v.RH = -1073741823L ;
	incr ( mem [curptr + 1 ].hh .v.LH ) ;
	deletesaref ( curptr ) ;
      } 
    } 
    deleteglueref ( mem [p + 7 ].hh .v.RH ) ;
    deleteglueref ( mem [p + 7 ].hh .v.LH ) ;
    freenode ( p , 10 ) ;
  } 
  lab30: while ( mem [curlist .tailfield ].hh .v.RH != -1073741823L ) {
      
    p = curlist .tailfield ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    if ( ! ( curlist .tailfield >= himemmin ) ) 
    switch ( mem [curlist .tailfield ].hh.b0 ) 
    {case 12 : 
      if ( ( mem [curlist .tailfield ].hh.b1 == 16 ) || ( mem [curlist 
      .tailfield ].hh.b1 == 17 ) ) 
      {
	mem [p ].hh .v.RH = mem [curlist .tailfield ].hh .v.RH ;
	deleteglueref ( mem [curlist .tailfield + 1 ].hh .v.LH ) ;
	freenode ( curlist .tailfield , 2 ) ;
	curlist .tailfield = p ;
      } 
      break ;
    case 14 : 
      if ( mem [curlist .tailfield ].hh.b1 == 1 ) 
      {
	mem [p ].hh .v.RH = mem [curlist .tailfield ].hh .v.RH ;
	freenode ( curlist .tailfield , 2 ) ;
	curlist .tailfield = p ;
      } 
      break ;
    case 5 : 
      {
	curlist .pdispfield = disp ;
	disp = mem [curlist .tailfield + 1 ].cint ;
	curlist .pnodefield = p ;
      } 
      break ;
    } 
  } 
} 
void 
appenditaliccorrection ( void ) 
{
  /* 10 */ appenditaliccorrection_regmem 
  halfword p  ;
  internalfontnumber f  ;
  halfword d  ;
  if ( curlist .tailfield != curlist .headfield ) 
  {
    if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield ]
    .hh.b0 == 5 ) ) 
    {
      d = curlist .tailfield ;
      curlist .tailfield = curlist .pnodefield ;
    } 
    else d = -1073741823L ;
    if ( ( curlist .lastjchrfield != -1073741823L ) && ( mem [curlist 
    .lastjchrfield ].hh .v.RH == curlist .tailfield ) && ( ( curlist 
    .tailfield >= himemmin ) ) ) 
    p = curlist .lastjchrfield ;
    else if ( ( curlist .tailfield >= himemmin ) ) 
    p = curlist .tailfield ;
    else if ( mem [curlist .tailfield ].hh.b0 == 8 ) 
    p = curlist .tailfield + 1 ;
    else return ;
    f = mem [p ].hh.b0 ;
    {
      mem [curlist .tailfield ].hh .v.RH = newkern ( fontinfo [italicbase [
      f ]+ ( fontinfo [charbase [f ]+ effectivechar ( true , f , mem [p ]
      .hh.b1 ) ].qqqq .b2 ) / 4 ].cint ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    mem [curlist .tailfield ].hh.b1 = 3 ;
    if ( d != -1073741823L ) 
    {
      curlist .pnodefield = curlist .tailfield ;
      {
	mem [curlist .tailfield ].hh .v.RH = d ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
    } 
  } 
} 
void 
appenddiscretionary ( void ) 
{
  appenddiscretionary_regmem 
  integer c  ;
  {
    mem [curlist .tailfield ].hh .v.RH = newdisc () ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  if ( curchr == 1 ) 
  {
    c = hyphenchar [eqtb [25588 ].hh .v.RH ];
    if ( c >= 0 ) {
	
      if ( c < 256 ) 
      mem [curlist .tailfield + 1 ].hh .v.LH = newcharacter ( eqtb [25588 ]
      .hh .v.RH , c ) ;
    } 
  } 
  else {
      
    incr ( saveptr ) ;
    savestack [saveptr - 1 ].cint = 0 ;
    newsavelevel ( 10 ) ;
    scanleftbrace () ;
    pushnest () ;
    curlist .modefield = -118 ;
    curlist .auxfield .hh .v.LH = 1000 ;
  } 
} 
void 
builddiscretionary ( void ) 
{
  /* 30 10 */ builddiscretionary_regmem 
  halfword p, q  ;
  integer n  ;
  unsave () ;
  q = curlist .headfield ;
  p = mem [q ].hh .v.RH ;
  n = 0 ;
  while ( p != -1073741823L ) {
      
    if ( ! ( p >= himemmin ) ) {
	
      if ( ( mem [p ].hh.b0 > 3 ) && ( mem [p ].hh.b0 != 13 ) && ( mem [p 
      ].hh.b0 != 8 ) && ( mem [p ].hh.b0 != 5 ) ) {
	  
	if ( ( mem [p ].hh.b0 == 14 ) && ( mem [p ].hh.b1 != 0 ) ) 
	{
	  mem [q ].hh .v.RH = mem [p ].hh .v.RH ;
	  freenode ( p , 2 ) ;
	  p = q ;
	} 
	else {
	    
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 1231 ) ;
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1232 ;
	  } 
	  error () ;
	  begindiagnostic () ;
	  printnl ( 1233 ) ;
	  showbox ( p ) ;
	  enddiagnostic ( true ) ;
	  flushnodelist ( p ) ;
	  mem [q ].hh .v.RH = -1073741823L ;
	  goto lab30 ;
	} 
      } 
    } 
    q = p ;
    p = mem [q ].hh .v.RH ;
    incr ( n ) ;
  } 
  lab30: ;
  p = mem [curlist .headfield ].hh .v.RH ;
  popnest () ;
  switch ( savestack [saveptr - 1 ].cint ) 
  {case 0 : 
    mem [curlist .tailfield + 1 ].hh .v.LH = p ;
    break ;
  case 1 : 
    mem [curlist .tailfield + 1 ].hh .v.RH = p ;
    break ;
  case 2 : 
    {
      if ( ( n > 0 ) && ( abs ( curlist .modefield ) == 235 ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1225 ) ;
	} 
	printesc ( 359 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1226 ;
	  helpline [0 ]= 1227 ;
	} 
	flushnodelist ( p ) ;
	n = 0 ;
	error () ;
      } 
      else mem [curlist .tailfield ].hh .v.RH = p ;
      if ( n <= 65535L ) 
      mem [curlist .tailfield ].hh.b1 = n ;
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1228 ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1229 ;
	  helpline [0 ]= 1230 ;
	} 
	error () ;
      } 
      if ( n > 0 ) 
      curlist .tailfield = q ;
      decr ( saveptr ) ;
      curlist .pnodefield = curlist .tailfield ;
      {
	mem [curlist .tailfield ].hh .v.RH = getnode ( 2 ) ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [curlist .tailfield ].hh.b0 = 5 ;
      mem [curlist .tailfield + 1 ].cint = 0 ;
      curlist .pdispfield = 0 ;
      return ;
    } 
    break ;
  } 
  incr ( savestack [saveptr - 1 ].cint ) ;
  newsavelevel ( 10 ) ;
  scanleftbrace () ;
  pushnest () ;
  curlist .modefield = -118 ;
  curlist .auxfield .hh .v.LH = 1000 ;
} 
void 
makeaccent ( void ) 
{
  makeaccent_regmem 
  real s, t  ;
  scaled disp  ;
  KANJIcode cx  ;
  halfword p, q, r  ;
  internalfontnumber f  ;
  scaled a, h, x, w, delta  ;
  fourquarters i  ;
  scancharnum () ;
  if ( checkecharrange ( curval ) == 0 ) 
  {
    cx = curval ;
    if ( curlist .dirfield == 3 ) 
    f = eqtb [26358 ].hh .v.RH ;
    else f = eqtb [26357 ].hh .v.RH ;
    p = newcharacter ( f , getjfmpos ( cx , f ) ) ;
    if ( p != -1073741823L ) 
    {
      mem [p ].hh .v.RH = getavail () ;
      mem [mem [p ].hh .v.RH ].hh .v.LH = cx + eqtb [26618 + kcatcodekey 
      ( cx ) ].hh .v.RH * 16777216L ;
    } 
  } 
  else {
      
    f = eqtb [25588 ].hh .v.RH ;
    p = newcharacter ( f , curval ) ;
  } 
  if ( p != -1073741823L ) 
  {
    x = fontinfo [5 + parambase [f ]].cint ;
    s = fontinfo [1 + parambase [f ]].cint / ((double) 65536.0 ) ;
    a = fontinfo [widthbase [f ]+ fontinfo [charbase [f ]+ effectivechar 
    ( true , f , mem [p ].hh.b1 ) ].qqqq .b0 ].cint ;
    doassignments () ;
    q = -1073741823L ;
    f = eqtb [25588 ].hh .v.RH ;
    cx = 0 ;
    if ( ( curcmd == 11 ) || ( curcmd == 12 ) ) 
    q = newcharacter ( f , curchr ) ;
    else if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
    {
      if ( curlist .dirfield == 3 ) 
      f = eqtb [26358 ].hh .v.RH ;
      else f = eqtb [26357 ].hh .v.RH ;
      cx = curchr ;
    } 
    else if ( curcmd == 73 ) {
	
      if ( checkecharrange ( curchr ) ) 
      q = newcharacter ( f , curchr ) ;
      else {
	  
	if ( curlist .dirfield == 3 ) 
	f = eqtb [26358 ].hh .v.RH ;
	else f = eqtb [26357 ].hh .v.RH ;
	cx = curchr ;
      } 
    } 
    else if ( curcmd == 20 ) 
    {
      scancharnum () ;
      if ( checkecharrange ( curval ) ) 
      q = newcharacter ( f , curval ) ;
      else {
	  
	if ( curlist .dirfield == 3 ) 
	f = eqtb [26358 ].hh .v.RH ;
	else f = eqtb [26357 ].hh .v.RH ;
	cx = curval ;
      } 
    } 
    else if ( curcmd == 74 ) 
    {
      if ( curlist .dirfield == 3 ) 
      f = eqtb [26358 ].hh .v.RH ;
      else f = eqtb [26357 ].hh .v.RH ;
      cx = curchr ;
    } 
    else if ( curcmd == 54 ) 
    {
      scancharnum () ;
      if ( curlist .dirfield == 3 ) 
      f = eqtb [26358 ].hh .v.RH ;
      else f = eqtb [26357 ].hh .v.RH ;
      cx = curval ;
    } 
    else backinput () ;
    if ( curlist .dirfield == 3 ) 
    {
      if ( fontdir [f ]== 3 ) 
      disp = 0 ;
      else if ( fontdir [f ]== 4 ) 
      disp = eqtb [29795 ].cint - eqtb [29796 ].cint ;
      else disp = eqtb [29795 ].cint ;
    } 
    else {
	
      if ( fontdir [f ]== 4 ) 
      disp = 0 ;
      else if ( fontdir [f ]== 3 ) 
      disp = eqtb [29796 ].cint - eqtb [29795 ].cint ;
      else disp = eqtb [29796 ].cint ;
    } 
    {
      if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield 
      ].hh.b0 == 5 ) ) 
      {
	if ( curlist .pdispfield == disp ) 
	{
	  freenode ( curlist .tailfield , 2 ) ;
	  curlist .tailfield = curlist .pnodefield ;
	  mem [curlist .tailfield ].hh .v.RH = -1073741823L ;
	} 
	else mem [curlist .tailfield + 1 ].cint = disp ;
      } 
      else if ( disp != 0 ) 
      {
	curlist .pnodefield = curlist .tailfield ;
	{
	  mem [curlist .tailfield ].hh .v.RH = getnode ( 2 ) ;
	  curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	} 
	mem [curlist .tailfield ].hh.b0 = 5 ;
	mem [curlist .tailfield + 1 ].cint = disp ;
	curlist .pdispfield = disp ;
      } 
    } 
    if ( cx != 0 ) 
    {
      q = newcharacter ( f , getjfmpos ( cx , f ) ) ;
      mem [q ].hh .v.RH = getavail () ;
      mem [mem [q ].hh .v.RH ].hh .v.LH = cx + eqtb [26618 + kcatcodekey 
      ( cx ) ].hh .v.RH * 16777216L ;
      curlist .lastjchrfield = q ;
    } 
    if ( q != -1073741823L ) 
    {
      t = fontinfo [1 + parambase [f ]].cint / ((double) 65536.0 ) ;
      i = fontinfo [charbase [f ]+ effectivechar ( true , f , mem [q ]
      .hh.b1 ) ].qqqq ;
      w = fontinfo [widthbase [f ]+ i .b0 ].cint ;
      h = fontinfo [heightbase [f ]+ ( i .b1 ) / 16 ].cint ;
      if ( h != x ) 
      {
	deleteglueref ( curkanjiskip ) ;
	deleteglueref ( curxkanjiskip ) ;
	curkanjiskip = membot ;
	curxkanjiskip = membot ;
	incr ( mem [curkanjiskip ].hh .v.RH ) ;
	incr ( mem [curxkanjiskip ].hh .v.RH ) ;
	p = hpack ( p , 0 , 1 ) ;
	mem [p + 4 ].cint = x - h ;
      } 
      delta = round ( ( w - a ) / ((double) 2.0 ) + h * t - x * s ) ;
      r = newkern ( delta ) ;
      mem [r ].hh.b1 = 2 ;
      mem [curlist .tailfield ].hh .v.RH = r ;
      mem [r ].hh .v.RH = p ;
      curlist .tailfield = newkern ( - (integer) a - delta ) ;
      mem [curlist .tailfield ].hh.b1 = 2 ;
      if ( h == x ) 
      {
	if ( fontdir [mem [p ].hh.b0 ]!= 0 ) 
	mem [mem [p ].hh .v.RH ].hh .v.RH = curlist .tailfield ;
	else mem [p ].hh .v.RH = curlist .tailfield ;
      } 
      else mem [p ].hh .v.RH = curlist .tailfield ;
      p = q ;
    } 
    mem [curlist .tailfield ].hh .v.RH = p ;
    if ( mem [p ].hh .v.RH != -1073741823L ) 
    curlist .tailfield = mem [p ].hh .v.RH ;
    else curlist .tailfield = p ;
    if ( disp != 0 ) 
    {
      if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield 
      ].hh.b0 == 5 ) ) 
      {
	mem [curlist .tailfield + 1 ].cint = 0 ;
      } 
      else {
	  
	curlist .pnodefield = curlist .tailfield ;
	{
	  mem [curlist .tailfield ].hh .v.RH = getnode ( 2 ) ;
	  curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	} 
	mem [curlist .tailfield ].hh.b0 = 5 ;
	mem [curlist .tailfield + 1 ].cint = 0 ;
	curlist .pdispfield = disp ;
      } 
    } 
    curlist .auxfield .hh .v.LH = 1000 ;
  } 
} 
void 
alignerror ( void ) 
{
  alignerror_regmem 
  if ( abs ( alignstate ) > 2 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1238 ) ;
    } 
    printcmdchr ( curcmd , curchr ) ;
    if ( curtok == 1062 ) 
    {
      {
	helpptr = 6 ;
	helpline [5 ]= 1239 ;
	helpline [4 ]= 1240 ;
	helpline [3 ]= 1241 ;
	helpline [2 ]= 1242 ;
	helpline [1 ]= 1243 ;
	helpline [0 ]= 1244 ;
      } 
    } 
    else {
	
      {
	helpptr = 5 ;
	helpline [4 ]= 1239 ;
	helpline [3 ]= 1245 ;
	helpline [2 ]= 1242 ;
	helpline [1 ]= 1243 ;
	helpline [0 ]= 1244 ;
      } 
    } 
    error () ;
  } 
  else {
      
    backinput () ;
    if ( alignstate < 0 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 718 ) ;
      } 
      incr ( alignstate ) ;
      curtok = 379 ;
    } 
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1234 ) ;
      } 
      decr ( alignstate ) ;
      curtok = 637 ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 1235 ;
      helpline [1 ]= 1236 ;
      helpline [0 ]= 1237 ;
    } 
    inserror () ;
  } 
} 
void 
noalignerror ( void ) 
{
  noalignerror_regmem 
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 1238 ) ;
  } 
  printesc ( 575 ) ;
  {
    helpptr = 2 ;
    helpline [1 ]= 1246 ;
    helpline [0 ]= 1247 ;
  } 
  error () ;
} 
void 
omiterror ( void ) 
{
  omiterror_regmem 
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 1238 ) ;
  } 
  printesc ( 578 ) ;
  {
    helpptr = 2 ;
    helpline [1 ]= 1248 ;
    helpline [0 ]= 1247 ;
  } 
  error () ;
} 
void 
doendv ( void ) 
{
  doendv_regmem 
  baseptr = inputptr ;
  inputstack [baseptr ]= curinput ;
  while ( ( inputstack [baseptr ].indexfield != 2 ) && ( inputstack [
  baseptr ].locfield == -1073741823L ) && ( inputstack [baseptr ]
  .statefield == 0 ) ) decr ( baseptr ) ;
  if ( ( inputstack [baseptr ].indexfield != 2 ) || ( inputstack [baseptr ]
  .locfield != -1073741823L ) || ( inputstack [baseptr ].statefield != 0 ) ) 
  fatalerror ( 650 ) ;
  if ( curgroup == 6 ) 
  {
    endgraf () ;
    if ( fincol () ) 
    finrow () ;
  } 
  else offsave () ;
} 
void 
cserror ( void ) 
{
  cserror_regmem 
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 875 ) ;
  } 
  printesc ( 547 ) ;
  {
    helpptr = 1 ;
    helpline [0 ]= 1250 ;
  } 
  error () ;
} 
void 
zpushmath ( groupcode c ) 
{
  pushmath_regmem 
  pushnest () ;
  curlist .modefield = -235 ;
  curlist .auxfield .cint = -1073741823L ;
  newsavelevel ( c ) ;
} 
void 
zjustcopy ( halfword p , halfword h , halfword t ) 
{
  /* 40 45 */ justcopy_regmem 
  halfword r  ;
  unsigned char words  ;
  while ( p != -1073741823L ) {
      
    words = 1 ;
    if ( ( p >= himemmin ) ) 
    r = getavail () ;
    else switch ( mem [p ].hh.b0 ) 
    {case 2 : 
    case 0 : 
    case 1 : 
      {
	r = getnode ( 10 ) ;
	mem [r + 8 ].cint = mem [p + 8 ].cint ;
	mem [r + 9 ].cint = mem [p + 9 ].cint ;
	mem [r + 7 ]= mem [p + 7 ];
	mem [r + 6 ]= mem [p + 6 ];
	mem [r + 5 ]= mem [p + 5 ];
	incr ( mem [mem [r + 7 ].hh .v.RH ].hh .v.RH ) ;
	incr ( mem [mem [r + 7 ].hh .v.LH ].hh .v.RH ) ;
	words = 5 ;
	mem [r + 5 ].hh .v.RH = -1073741823L ;
      } 
      break ;
    case 3 : 
      {
	r = getnode ( 6 ) ;
	words = 6 ;
      } 
      break ;
    case 8 : 
      {
	r = getavail () ;
	mem [r ]= mem [p + 1 ];
	goto lab40 ;
      } 
      break ;
    case 13 : 
    case 11 : 
      {
	words = 4 ;
	r = getnode ( words ) ;
      } 
      break ;
    case 12 : 
      {
	r = getnode ( 4 ) ;
	incr ( mem [mem [p + 1 ].hh .v.LH ].hh .v.RH ) ;
	mem [r + 2 ].cint = mem [p + 2 ].cint ;
	mem [r + 3 ].cint = mem [p + 3 ].cint ;
	mem [r + 1 ].hh .v.LH = mem [p + 1 ].hh .v.LH ;
	mem [r + 1 ].hh .v.RH = -1073741823L ;
      } 
      break ;
    case 10 : 
      switch ( mem [p ].hh.b1 ) 
      {case 0 : 
	{
	  r = getnode ( 3 ) ;
	  words = 3 ;
	} 
	break ;
      case 1 : 
      case 3 : 
	{
	  r = getnode ( 2 ) ;
	  incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
	  words = 2 ;
	} 
	break ;
      case 2 : 
      case 4 : 
	{
	  r = getnode ( 2 ) ;
	  words = 2 ;
	} 
	break ;
      case 6 : 
	r = getnode ( 2 ) ;
	break ;
	default: 
	confusion ( 1439 ) ;
	break ;
      } 
      break ;
      default: 
      goto lab45 ;
      break ;
    } 
    while ( words > 0 ) {
	
      decr ( words ) ;
      mem [r + words ]= mem [p + words ];
    } 
    lab40: mem [h ].hh .v.RH = r ;
    h = r ;
    lab45: p = mem [p ].hh .v.RH ;
  } 
  mem [h ].hh .v.RH = t ;
} 
void 
zjustreverse ( halfword p ) 
{
  /* 30 */ justreverse_regmem 
  halfword l  ;
  halfword t  ;
  halfword q  ;
  halfword m, n  ;
  m = -1073741823L ;
  n = -1073741823L ;
  if ( mem [memtop - 3 ].hh .v.RH == -1073741823L ) 
  {
    justcopy ( mem [p ].hh .v.RH , memtop - 3 , -1073741823L ) ;
    q = mem [memtop - 3 ].hh .v.RH ;
  } 
  else {
      
    q = mem [p ].hh .v.RH ;
    mem [p ].hh .v.RH = -1073741823L ;
    flushnodelist ( mem [memtop - 3 ].hh .v.RH ) ;
  } 
  t = newedge ( curdir , 0 ) ;
  l = t ;
  curdir = 1 - curdir ;
  while ( q != -1073741823L ) if ( ( q >= himemmin ) ) 
  do {
      p = q ;
    q = mem [p ].hh .v.RH ;
    mem [p ].hh .v.RH = l ;
    l = p ;
  } while ( ! ( ! ( q >= himemmin ) ) ) ;
  else {
      
    p = q ;
    q = mem [p ].hh .v.RH ;
    if ( mem [p ].hh.b0 == 11 ) {
	
      if ( odd ( mem [p ].hh.b1 ) ) {
	  
	if ( mem [LRptr ].hh .v.LH != ( 4 * ( mem [p ].hh.b1 / 4 ) + 3 ) ) 
	{
	  mem [p ].hh.b0 = 13 ;
	  incr ( LRproblems ) ;
	} 
	else {
	    
	  {
	    tempptr = LRptr ;
	    LRptr = mem [tempptr ].hh .v.RH ;
	    {
	      mem [tempptr ].hh .v.RH = avail ;
	      avail = tempptr ;
	;
#ifdef STAT
	      decr ( dynused ) ;
#endif /* STAT */
	    } 
	  } 
	  if ( n > -1073741823L ) 
	  {
	    decr ( n ) ;
	    decr ( mem [p ].hh.b1 ) ;
	  } 
	  else {
	      
	    if ( m > -1073741823L ) 
	    decr ( m ) ;
	    else {
		
	      mem [t + 1 ].cint = mem [p + 1 ].cint ;
	      mem [t ].hh .v.RH = q ;
	      freenode ( p , 4 ) ;
	      goto lab30 ;
	    } 
	    mem [p ].hh.b0 = 13 ;
	  } 
	} 
      } 
      else {
	  
	{
	  tempptr = getavail () ;
	  mem [tempptr ].hh .v.LH = ( 4 * ( mem [p ].hh.b1 / 4 ) + 3 ) ;
	  mem [tempptr ].hh .v.RH = LRptr ;
	  LRptr = tempptr ;
	} 
	if ( ( n > -1073741823L ) || ( ( mem [p ].hh.b1 / 8 ) != curdir ) ) 
	{
	  incr ( n ) ;
	  incr ( mem [p ].hh.b1 ) ;
	} 
	else {
	    
	  mem [p ].hh.b0 = 13 ;
	  incr ( m ) ;
	} 
      } 
    } 
    mem [p ].hh .v.RH = l ;
    l = p ;
  } 
  goto lab30 ;
  mem [t + 1 ].cint = mem [p + 1 ].cint ;
  mem [t ].hh .v.RH = q ;
  freenode ( p , 2 ) ;
  lab30: mem [memtop - 3 ].hh .v.RH = l ;
} 
void 
initmath ( void ) 
{
  /* 21 40 45 30 */ initmath_regmem 
  scaled w  ;
  halfword j  ;
  integer x  ;
  scaled l  ;
  scaled s  ;
  halfword p  ;
  halfword q  ;
  internalfontnumber f  ;
  integer n  ;
  scaled v  ;
  scaled d  ;
  gettoken () ;
  if ( ( curcmd == 3 ) && ( curlist .modefield > 0 ) ) 
  {
    j = -1073741823L ;
    w = -1073741823L ;
    if ( curlist .headfield == curlist .tailfield ) 
    {
      popnest () ;
      if ( curlist .eTeXauxfield == -1073741823L ) 
      x = 0 ;
      else if ( mem [curlist .eTeXauxfield ].hh .v.LH >= 8 ) 
      x = -1 ;
      else x = 1 ;
    } 
    else {
	
      adjusthlist ( curlist .headfield , true ) ;
      linebreak ( true ) ;
      if ( ( eTeXmode == 1 ) ) 
      {
	if ( eqtb [24536 ].hh .v.RH == membot ) 
	j = newkern ( 0 ) ;
	else j = newparamglue ( 8 ) ;
	if ( eqtb [24535 ].hh .v.RH == membot ) 
	p = newkern ( 0 ) ;
	else p = newparamglue ( 7 ) ;
	mem [p ].hh .v.RH = j ;
	j = newnullbox () ;
	mem [j + 1 ].cint = mem [justbox + 1 ].cint ;
	mem [j + 4 ].cint = mem [justbox + 4 ].cint ;
	mem [j + 5 ].hh .v.RH = p ;
	mem [j + 5 ].hh.b1 = mem [justbox + 5 ].hh.b1 ;
	mem [j + 5 ].hh.b0 = mem [justbox + 5 ].hh.b0 ;
	mem [j + 6 ].gr = mem [justbox + 6 ].gr ;
      } 
      v = mem [justbox + 4 ].cint ;
      if ( curlist .eTeXauxfield == -1073741823L ) 
      x = 0 ;
      else if ( mem [curlist .eTeXauxfield ].hh .v.LH >= 8 ) 
      x = -1 ;
      else x = 1 ;
      if ( x >= 0 ) 
      {
	p = mem [justbox + 5 ].hh .v.RH ;
	mem [memtop - 3 ].hh .v.RH = -1073741823L ;
      } 
      else {
	  
	v = - (integer) v - mem [justbox + 1 ].cint ;
	p = newmath ( 0 , 6 ) ;
	mem [memtop - 3 ].hh .v.RH = p ;
	justcopy ( mem [justbox + 5 ].hh .v.RH , p , newmath ( 0 , 7 ) ) ;
	curdir = 1 ;
      } 
      v = v + 2 * fontinfo [6 + parambase [eqtb [25588 ].hh .v.RH ]]
      .cint ;
      if ( ( eqtb [29261 ].cint > 0 ) ) 
      {
	tempptr = getavail () ;
	mem [tempptr ].hh .v.LH = 0 ;
	mem [tempptr ].hh .v.RH = LRptr ;
	LRptr = tempptr ;
      } 
      while ( p != -1073741823L ) {
	  
	lab21: if ( ( p >= himemmin ) ) 
	{
	  f = mem [p ].hh.b0 ;
	  d = fontinfo [widthbase [f ]+ fontinfo [charbase [f ]+ mem [p 
	  ].hh.b1 ].qqqq .b0 ].cint ;
	  if ( fontdir [f ]!= 0 ) 
	  p = mem [p ].hh .v.RH ;
	  goto lab40 ;
	} 
	switch ( mem [p ].hh.b0 ) 
	{case 0 : 
	case 1 : 
	case 2 : 
	case 3 : 
	  {
	    d = mem [p + 1 ].cint ;
	    goto lab40 ;
	  } 
	  break ;
	case 8 : 
	  {
	    mem [memtop - 12 ]= mem [p + 1 ];
	    mem [memtop - 12 ].hh .v.RH = mem [p ].hh .v.RH ;
	    p = memtop - 12 ;
	    goto lab21 ;
	  } 
	  break ;
	case 13 : 
	  d = mem [p + 1 ].cint ;
	  break ;
	case 11 : 
	  {
	    d = mem [p + 1 ].cint ;
	    if ( ( eqtb [29261 ].cint > 0 ) ) {
		
	      if ( odd ( mem [p ].hh.b1 ) ) 
	      {
		if ( mem [LRptr ].hh .v.LH == ( 4 * ( mem [p ].hh.b1 / 4 ) 
		+ 3 ) ) 
		{
		  tempptr = LRptr ;
		  LRptr = mem [tempptr ].hh .v.RH ;
		  {
		    mem [tempptr ].hh .v.RH = avail ;
		    avail = tempptr ;
	;
#ifdef STAT
		    decr ( dynused ) ;
#endif /* STAT */
		  } 
		} 
		else if ( mem [p ].hh.b1 > 4 ) 
		{
		  w = 1073741823L ;
		  goto lab30 ;
		} 
	      } 
	      else {
		  
		{
		  tempptr = getavail () ;
		  mem [tempptr ].hh .v.LH = ( 4 * ( mem [p ].hh.b1 / 4 ) + 
		  3 ) ;
		  mem [tempptr ].hh .v.RH = LRptr ;
		  LRptr = tempptr ;
		} 
		if ( ( mem [p ].hh.b1 / 8 ) != curdir ) 
		{
		  justreverse ( p ) ;
		  p = memtop - 3 ;
		} 
	      } 
	    } 
	    else if ( mem [p ].hh.b1 >= 4 ) 
	    {
	      w = 1073741823L ;
	      goto lab30 ;
	    } 
	  } 
	  break ;
	case 16 : 
	  {
	    d = mem [p + 1 ].cint ;
	    curdir = mem [p ].hh.b1 ;
	  } 
	  break ;
	case 12 : 
	  {
	    q = mem [p + 1 ].hh .v.LH ;
	    d = mem [q + 1 ].cint ;
	    if ( mem [justbox + 5 ].hh.b0 == 1 ) 
	    {
	      if ( ( mem [justbox + 5 ].hh.b1 == mem [q ].hh.b0 ) && ( mem 
	      [q + 2 ].cint != 0 ) ) 
	      v = 1073741823L ;
	    } 
	    else if ( mem [justbox + 5 ].hh.b0 == 2 ) 
	    {
	      if ( ( mem [justbox + 5 ].hh.b1 == mem [q ].hh.b1 ) && ( mem 
	      [q + 3 ].cint != 0 ) ) 
	      v = 1073741823L ;
	    } 
	    if ( mem [p ].hh.b1 >= 100 ) 
	    goto lab40 ;
	  } 
	  break ;
	case 10 : 
	  d = 0 ;
	  break ;
	  default: 
	  d = 0 ;
	  break ;
	} 
	if ( v < 1073741823L ) 
	v = v + d ;
	goto lab45 ;
	lab40: if ( v < 1073741823L ) 
	{
	  v = v + d ;
	  w = v ;
	} 
	else {
	    
	  w = 1073741823L ;
	  goto lab30 ;
	} 
	lab45: p = mem [p ].hh .v.RH ;
      } 
      lab30: if ( ( eqtb [29261 ].cint > 0 ) ) 
      {
	while ( LRptr != -1073741823L ) {
	    
	  tempptr = LRptr ;
	  LRptr = mem [tempptr ].hh .v.RH ;
	  {
	    mem [tempptr ].hh .v.RH = avail ;
	    avail = tempptr ;
	;
#ifdef STAT
	    decr ( dynused ) ;
#endif /* STAT */
	  } 
	} 
	if ( LRproblems != 0 ) 
	{
	  w = 1073741823L ;
	  LRproblems = 0 ;
	} 
      } 
      curdir = 0 ;
      flushnodelist ( mem [memtop - 3 ].hh .v.RH ) ;
    } 
    if ( eqtb [25061 ].hh .v.RH == -1073741823L ) {
	
      if ( ( eqtb [29791 ].cint != 0 ) && ( ( ( eqtb [29229 ].cint >= 0 ) 
      && ( curlist .pgfield + 2 > eqtb [29229 ].cint ) ) || ( curlist 
      .pgfield + 1 < - (integer) eqtb [29229 ].cint ) ) ) 
      {
	l = eqtb [29777 ].cint - abs ( eqtb [29791 ].cint ) ;
	if ( eqtb [29791 ].cint > 0 ) 
	s = eqtb [29791 ].cint ;
	else s = 0 ;
      } 
      else {
	  
	l = eqtb [29777 ].cint ;
	s = 0 ;
      } 
    } 
    else {
	
      n = mem [eqtb [25061 ].hh .v.RH ].hh .v.LH ;
      if ( curlist .pgfield + 2 >= n ) 
      p = eqtb [25061 ].hh .v.RH + 2 * n ;
      else p = eqtb [25061 ].hh .v.RH + 2 * ( curlist .pgfield + 2 ) ;
      s = mem [p - 1 ].cint ;
      l = mem [p ].cint ;
    } 
    pushmath ( 15 ) ;
    curlist .modefield = 235 ;
    eqworddefine ( 29232 , -1 ) ;
    eqworddefine ( 29787 , w ) ;
    curlist .eTeXauxfield = j ;
    if ( ( eTeXmode == 1 ) ) 
    eqworddefine ( 29257 , x ) ;
    eqworddefine ( 29788 , l ) ;
    eqworddefine ( 29789 , s ) ;
    if ( eqtb [25065 ].hh .v.RH != -1073741823L ) 
    begintokenlist ( eqtb [25065 ].hh .v.RH , 9 ) ;
    if ( nestptr == 1 ) 
    buildpage () ;
  } 
  else {
      
    backinput () ;
    {
      pushmath ( 15 ) ;
      eqworddefine ( 29232 , -1 ) ;
      if ( ( insertsrcspecialeverymath ) ) 
      insertsrcspecial () ;
      if ( eqtb [25064 ].hh .v.RH != -1073741823L ) 
      begintokenlist ( eqtb [25064 ].hh .v.RH , 8 ) ;
    } 
  } 
  curlist .dirfield = - (integer) abs ( curlist .dirfield ) ;
} 
void 
starteqno ( void ) 
{
  starteqno_regmem 
  savestack [saveptr + 0 ].cint = curchr ;
  incr ( saveptr ) ;
  {
    pushmath ( 15 ) ;
    eqworddefine ( 29232 , -1 ) ;
    if ( ( insertsrcspecialeverymath ) ) 
    insertsrcspecial () ;
    if ( eqtb [25064 ].hh .v.RH != -1073741823L ) 
    begintokenlist ( eqtb [25064 ].hh .v.RH , 8 ) ;
  } 
} 
void 
zscanmath ( halfword p , halfword q ) 
{
  /* 20 21 10 */ scanmath_regmem 
  integer c  ;
  KANJIcode cx  ;
  cx = 0 ;
  lab20: do {
      getxtoken () ;
  } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
  lab21: switch ( curcmd ) 
  {case 11 : 
  case 12 : 
  case 73 : 
    if ( ( curchr >= 0 ) && ( curchr <= 256 ) ) 
    {
      c = eqtb [28676 + curchr ].hh .v.RH ;
      if ( c == 524288L ) 
      {
	{
	  curcs = curchr + 1 ;
	  curcmd = eqtb [curcs ].hh.b0 ;
	  curchr = eqtb [curcs ].hh .v.RH ;
	  xtoken () ;
	  backinput () ;
	} 
	goto lab20 ;
      } 
    } 
    else cx = curchr ;
    break ;
  case 74 : 
    cx = curchr ;
    break ;
  case 16 : 
  case 17 : 
  case 18 : 
  case 19 : 
    cx = curchr ;
    break ;
  case 20 : 
    {
      scancharnum () ;
      curchr = curval ;
      curcmd = 73 ;
      goto lab21 ;
    } 
    break ;
  case 21 : 
    {
      if ( curchr == 0 ) 
      scanfifteenbitint () ;
      else scanbigfifteenbitint () ;
      c = curval ;
    } 
    break ;
  case 75 : 
    c = ( ( curchr / 4096 ) * 65536L ) + ( curchr % 4096 ) ;
    break ;
  case 76 : 
    c = ( ( curchr / 65536L ) * 256 ) + ( curchr % 256 ) ;
    break ;
  case 15 : 
    {
      if ( curchr == 0 ) 
      scantwentysevenbitint () ;
      else scanfiftyonebitint () ;
      c = curval ;
    } 
    break ;
    default: 
    {
      backinput () ;
      scanleftbrace () ;
      savestack [saveptr + 0 ].cint = p ;
      incr ( saveptr ) ;
      pushmath ( 9 ) ;
      return ;
    } 
    break ;
  } 
  if ( cx == 0 ) 
  {
    mem [p ].hh .v.RH = 1 ;
    mem [p ].hh.b1 = c % 256 ;
    if ( ( c >= 458752L ) && ( ( ( eqtb [29232 ].cint >= 0 ) && ( eqtb [
    29232 ].cint < 256 ) ) ) ) 
    mem [p ].hh.b0 = eqtb [29232 ].cint ;
    else mem [p ].hh.b0 = ( c / 256 ) % 256 ;
    if ( fontdir [eqtb [25589 + mem [p ].hh.b0 + cursize ].hh .v.RH ]!= 
    0 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1253 ) ;
      } 
      {
	helpptr = 1 ;
	helpline [0 ]= 1254 ;
      } 
      error () ;
    } 
  } 
  else {
      
    if ( q == -1073741823L ) 
    {
      mem [p ].hh .v.RH = 4 ;
      mem [p ].hh .v.LH = newnoad () ;
      p = mem [p ].hh .v.LH + 1 ;
      q = p + 3 ;
    } 
    mem [p ].hh .v.RH = 6 ;
    mem [p ].hh.b0 = eqtb [29233 ].cint ;
    mem [p ].hh.b1 = 0 ;
    mem [p + 3 ].hh .v.LH = cx + eqtb [26618 + kcatcodekey ( cx ) ].hh 
    .v.RH * 16777216L ;
    if ( fontdir [eqtb [25589 + mem [p ].hh.b0 + cursize ].hh .v.RH ]== 
    0 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1255 ) ;
      } 
      {
	helpptr = 1 ;
	helpline [0 ]= 1254 ;
      } 
      error () ;
    } 
  } 
} 
void 
zsetmathchar ( integer c ) 
{
  setmathchar_regmem 
  halfword p  ;
  if ( c >= 524288L ) 
  {
    curcs = curchr + 1 ;
    curcmd = eqtb [curcs ].hh.b0 ;
    curchr = eqtb [curcs ].hh .v.RH ;
    xtoken () ;
    backinput () ;
  } 
  else {
      
    p = newnoad () ;
    mem [p + 1 ].hh .v.RH = 1 ;
    mem [p + 1 ].hh.b1 = c % 256 ;
    mem [p + 1 ].hh.b0 = ( c / 256 ) % 256 ;
    if ( c >= 458752L ) 
    {
      if ( ( ( eqtb [29232 ].cint >= 0 ) && ( eqtb [29232 ].cint < 256 ) ) 
      ) 
      mem [p + 1 ].hh.b0 = eqtb [29232 ].cint ;
      mem [p ].hh.b0 = 18 ;
    } 
    else mem [p ].hh.b0 = 18 + ( c / 65536L ) ;
    mem [curlist .tailfield ].hh .v.RH = p ;
    curlist .tailfield = p ;
    if ( fontdir [eqtb [25589 + mem [p + 1 ].hh.b0 + cursize ].hh .v.RH ]
    != 0 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1253 ) ;
      } 
      {
	helpptr = 1 ;
	helpline [0 ]= 1254 ;
      } 
      error () ;
    } 
    inhibitglueflag = false ;
  } 
} 
void 
mathlimitswitch ( void ) 
{
  /* 10 */ mathlimitswitch_regmem 
  if ( curlist .headfield != curlist .tailfield ) {
      
    if ( mem [curlist .tailfield ].hh.b0 == 19 ) 
    {
      mem [curlist .tailfield ].hh.b1 = curchr ;
      return ;
    } 
  } 
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 1257 ) ;
  } 
  {
    helpptr = 1 ;
    helpline [0 ]= 1258 ;
  } 
  error () ;
} 
void 
zscandelimiter ( halfword p , boolean r ) 
{
  scandelimiter_regmem 
  if ( r == 1 ) 
  scantwentysevenbitint () ;
  else if ( r == 2 ) 
  scanfiftyonebitint () ;
  else {
      
    do {
	getxtoken () ;
    } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
    switch ( curcmd ) 
    {case 11 : 
    case 12 : 
      {
	curval = eqtb [29518 + curchr ].cint ;
	curval1 = getintone ( eqtb [29518 + curchr ]) ;
      } 
      break ;
    case 15 : 
      if ( curchr == 0 ) 
      scantwentysevenbitint () ;
      else scanfiftyonebitint () ;
      break ;
      default: 
      {
	curval = -1 ;
	curval1 = -1 ;
      } 
      break ;
    } 
  } 
  if ( curval < 0 ) 
  {
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1259 ) ;
      } 
      {
	helpptr = 6 ;
	helpline [5 ]= 1260 ;
	helpline [4 ]= 1261 ;
	helpline [3 ]= 1262 ;
	helpline [2 ]= 1263 ;
	helpline [1 ]= 1264 ;
	helpline [0 ]= 1265 ;
      } 
      backerror () ;
      curval = 0 ;
    } 
    curval1 = 0 ;
  } 
  mem [p ].qqqq .b0 = ( curval / 256 ) % 256 ;
  mem [p ].qqqq .b1 = curval % 256 ;
  mem [p ].qqqq .b2 = ( curval1 / 256 ) % 256 ;
  mem [p ].qqqq .b3 = curval1 % 256 ;
} 
void 
mathradical ( void ) 
{
  mathradical_regmem 
  {
    mem [curlist .tailfield ].hh .v.RH = getnode ( 6 ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  mem [curlist .tailfield ].hh.b0 = 26 ;
  mem [curlist .tailfield ].hh.b1 = 0 ;
  mem [curlist .tailfield + 1 ].hh = emptyfield ;
  mem [curlist .tailfield + 3 ].hh = emptyfield ;
  mem [curlist .tailfield + 2 ].hh = emptyfield ;
  scandelimiter ( curlist .tailfield + 5 , curchr + 1 ) ;
  scanmath ( curlist .tailfield + 1 , curlist .tailfield + 4 ) ;
} 
void 
mathac ( void ) 
{
  mathac_regmem 
  if ( curcmd == 49 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1266 ) ;
    } 
    printesc ( 569 ) ;
    print ( 1267 ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 1268 ;
      helpline [0 ]= 1269 ;
    } 
    error () ;
  } 
  {
    mem [curlist .tailfield ].hh .v.RH = getnode ( 6 ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  mem [curlist .tailfield ].hh.b0 = 30 ;
  mem [curlist .tailfield ].hh.b1 = 0 ;
  mem [curlist .tailfield + 1 ].hh = emptyfield ;
  mem [curlist .tailfield + 3 ].hh = emptyfield ;
  mem [curlist .tailfield + 2 ].hh = emptyfield ;
  mem [curlist .tailfield + 5 ].hh .v.RH = 1 ;
  if ( curchr == 0 ) 
  scanfifteenbitint () ;
  else scanbigfifteenbitint () ;
  mem [curlist .tailfield + 5 ].hh.b1 = curval % 256 ;
  if ( ( curval >= 458752L ) && ( ( eqtb [29232 ].cint >= 0 ) && ( eqtb [
  29232 ].cint < 256 ) ) ) 
  mem [curlist .tailfield + 5 ].hh.b0 = eqtb [29232 ].cint ;
  else mem [curlist .tailfield + 5 ].hh.b0 = ( curval / 256 ) % 256 ;
  scanmath ( curlist .tailfield + 1 , curlist .tailfield + 4 ) ;
} 
void 
appendchoices ( void ) 
{
  appendchoices_regmem 
  {
    mem [curlist .tailfield ].hh .v.RH = newchoice () ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  incr ( saveptr ) ;
  savestack [saveptr - 1 ].cint = 0 ;
  pushmath ( 13 ) ;
  scanleftbrace () ;
} 
halfword 
zfinmlist ( halfword p ) 
{
  register halfword Result; finmlist_regmem 
  halfword q  ;
  if ( curlist .auxfield .cint != -1073741823L ) 
  {
    mem [curlist .auxfield .cint + 3 ].hh .v.RH = 4 ;
    mem [curlist .auxfield .cint + 3 ].hh .v.LH = mem [curlist .headfield ]
    .hh .v.RH ;
    if ( p == -1073741823L ) 
    q = curlist .auxfield .cint ;
    else {
	
      q = mem [curlist .auxfield .cint + 2 ].hh .v.LH ;
      if ( ( mem [q ].hh.b0 != 32 ) || ( curlist .eTeXauxfield == 
      -1073741823L ) ) 
      confusion ( 976 ) ;
      mem [curlist .auxfield .cint + 2 ].hh .v.LH = mem [curlist 
      .eTeXauxfield ].hh .v.RH ;
      mem [curlist .eTeXauxfield ].hh .v.RH = curlist .auxfield .cint ;
      mem [curlist .auxfield .cint ].hh .v.RH = p ;
    } 
  } 
  else {
      
    mem [curlist .tailfield ].hh .v.RH = p ;
    q = mem [curlist .headfield ].hh .v.RH ;
  } 
  popnest () ;
  Result = q ;
  return Result ;
} 
void 
buildchoices ( void ) 
{
  /* 10 */ buildchoices_regmem 
  halfword p  ;
  unsave () ;
  p = finmlist ( -1073741823L ) ;
  switch ( savestack [saveptr - 1 ].cint ) 
  {case 0 : 
    mem [curlist .tailfield + 1 ].hh .v.LH = p ;
    break ;
  case 1 : 
    mem [curlist .tailfield + 1 ].hh .v.RH = p ;
    break ;
  case 2 : 
    mem [curlist .tailfield + 2 ].hh .v.LH = p ;
    break ;
  case 3 : 
    {
      mem [curlist .tailfield + 2 ].hh .v.RH = p ;
      decr ( saveptr ) ;
      return ;
    } 
    break ;
  } 
  incr ( savestack [saveptr - 1 ].cint ) ;
  pushmath ( 13 ) ;
  scanleftbrace () ;
} 
void 
subsup ( void ) 
{
  subsup_regmem 
  smallnumber t  ;
  halfword p  ;
  t = 0 ;
  p = -1073741823L ;
  inhibitglueflag = false ;
  if ( curlist .tailfield != curlist .headfield ) {
      
    if ( ( mem [curlist .tailfield ].hh.b0 >= 18 ) && ( mem [curlist 
    .tailfield ].hh.b0 < 32 ) ) 
    {
      p = curlist .tailfield + 2 + curcmd - 7 ;
      t = mem [p ].hh .v.RH ;
    } 
  } 
  if ( ( p == -1073741823L ) || ( t != 0 ) ) 
  {
    {
      mem [curlist .tailfield ].hh .v.RH = newnoad () ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    p = curlist .tailfield + 2 + curcmd - 7 ;
    if ( t != 0 ) 
    {
      if ( curcmd == 7 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1270 ) ;
	} 
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1271 ;
	} 
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1272 ) ;
	} 
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1273 ;
	} 
      } 
      error () ;
    } 
  } 
  scanmath ( p , -1073741823L ) ;
} 
void 
mathfraction ( void ) 
{
  mathfraction_regmem 
  smallnumber c  ;
  c = curchr ;
  inhibitglueflag = false ;
  if ( curlist .auxfield .cint != -1073741823L ) 
  {
    if ( c >= 3 ) 
    {
      scandelimiter ( memtop - 12 , false ) ;
      scandelimiter ( memtop - 12 , false ) ;
    } 
    if ( c % 3 == 0 ) 
    scandimen ( false , false , false ) ;
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1280 ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 1281 ;
      helpline [1 ]= 1282 ;
      helpline [0 ]= 1283 ;
    } 
    error () ;
  } 
  else {
      
    curlist .auxfield .cint = getnode ( 6 ) ;
    mem [curlist .auxfield .cint ].hh.b0 = 27 ;
    mem [curlist .auxfield .cint ].hh.b1 = 0 ;
    mem [curlist .auxfield .cint + 2 ].hh .v.RH = 4 ;
    mem [curlist .auxfield .cint + 2 ].hh .v.LH = mem [curlist .headfield ]
    .hh .v.RH ;
    mem [curlist .auxfield .cint + 3 ].hh = emptyfield ;
    mem [curlist .auxfield .cint + 5 ].qqqq = nulldelimiter ;
    mem [curlist .auxfield .cint + 4 ].qqqq = nulldelimiter ;
    mem [curlist .headfield ].hh .v.RH = -1073741823L ;
    curlist .tailfield = curlist .headfield ;
    if ( c >= 3 ) 
    {
      scandelimiter ( curlist .auxfield .cint + 5 , false ) ;
      scandelimiter ( curlist .auxfield .cint + 4 , false ) ;
    } 
    switch ( c % 3 ) 
    {case 0 : 
      {
	scandimen ( false , false , false ) ;
	mem [curlist .auxfield .cint + 1 ].cint = curval ;
      } 
      break ;
    case 1 : 
      mem [curlist .auxfield .cint + 1 ].cint = 1073741824L ;
      break ;
    case 2 : 
      mem [curlist .auxfield .cint + 1 ].cint = 0 ;
      break ;
    } 
  } 
} 
void 
mathleftright ( void ) 
{
  mathleftright_regmem 
  smallnumber t  ;
  halfword p  ;
  halfword q  ;
  t = curchr ;
  inhibitglueflag = false ;
  if ( ( t != 32 ) && ( curgroup != 16 ) ) 
  {
    if ( curgroup == 15 ) 
    {
      scandelimiter ( memtop - 12 , false ) ;
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 875 ) ;
      } 
      if ( t == 1 ) 
      {
	printesc ( 977 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1284 ;
	} 
      } 
      else {
	  
	printesc ( 976 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1285 ;
	} 
      } 
      error () ;
    } 
    else offsave () ;
  } 
  else {
      
    p = newnoad () ;
    mem [p ].hh.b0 = t ;
    scandelimiter ( p + 1 , false ) ;
    if ( t == 1 ) 
    {
      mem [p ].hh.b0 = 33 ;
      mem [p ].hh.b1 = 1 ;
    } 
    if ( t == 32 ) 
    q = p ;
    else {
	
      q = finmlist ( p ) ;
      unsave () ;
    } 
    if ( t != 33 ) 
    {
      pushmath ( 16 ) ;
      mem [curlist .headfield ].hh .v.RH = q ;
      curlist .tailfield = p ;
      curlist .eTeXauxfield = p ;
    } 
    else {
	
      {
	mem [curlist .tailfield ].hh .v.RH = newnoad () ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [curlist .tailfield ].hh.b0 = 25 ;
      mem [curlist .tailfield + 1 ].hh .v.RH = 4 ;
      mem [curlist .tailfield + 1 ].hh .v.LH = q ;
    } 
  } 
} 
void 
zappdisplay ( halfword j , halfword b , scaled d ) 
{
  appdisplay_regmem 
  scaled z  ;
  scaled s  ;
  scaled e  ;
  integer x  ;
  halfword p, q, r, t, u  ;
  s = eqtb [29789 ].cint ;
  x = eqtb [29257 ].cint ;
  if ( x == 0 ) 
  mem [b + 4 ].cint = s + d ;
  else {
      
    z = eqtb [29788 ].cint ;
    p = b ;
    if ( x > 0 ) 
    e = z - d - mem [p + 1 ].cint ;
    else {
	
      e = d ;
      d = z - e - mem [p + 1 ].cint ;
    } 
    if ( j != -1073741823L ) 
    {
      b = copynodelist ( j ) ;
      mem [b + 3 ].cint = mem [p + 3 ].cint ;
      mem [b + 2 ].cint = mem [p + 2 ].cint ;
      s = s - mem [b + 4 ].cint ;
      d = d + s ;
      e = e + mem [b + 1 ].cint - z - s ;
    } 
    if ( ( ( mem [p ].hh.b1 ) / 8 ) == 2 ) 
    q = p ;
    else {
	
      r = mem [p + 5 ].hh .v.RH ;
      freenode ( p , 10 ) ;
      if ( r == -1073741823L ) 
      confusion ( 1524 ) ;
      if ( x > 0 ) 
      {
	p = r ;
	do {
	    q = r ;
	  r = mem [r ].hh .v.RH ;
	} while ( ! ( r == -1073741823L ) ) ;
      } 
      else {
	  
	p = -1073741823L ;
	q = r ;
	do {
	    t = mem [r ].hh .v.RH ;
	  mem [r ].hh .v.RH = p ;
	  p = r ;
	  r = t ;
	} while ( ! ( r == -1073741823L ) ) ;
      } 
    } 
    if ( j == -1073741823L ) 
    {
      r = newkern ( 0 ) ;
      t = newkern ( 0 ) ;
    } 
    else {
	
      r = mem [b + 5 ].hh .v.RH ;
      t = mem [r ].hh .v.RH ;
    } 
    u = newmath ( 0 , 3 ) ;
    if ( mem [t ].hh.b0 == 12 ) 
    {
      j = newskipparam ( 8 ) ;
      mem [q ].hh .v.RH = j ;
      mem [j ].hh .v.RH = u ;
      j = mem [t + 1 ].hh .v.LH ;
      mem [tempptr ].hh.b0 = mem [j ].hh.b0 ;
      mem [tempptr ].hh.b1 = mem [j ].hh.b1 ;
      mem [tempptr + 1 ].cint = e - mem [j + 1 ].cint ;
      mem [tempptr + 2 ].cint = - (integer) mem [j + 2 ].cint ;
      mem [tempptr + 3 ].cint = - (integer) mem [j + 3 ].cint ;
      mem [u ].hh .v.RH = t ;
    } 
    else {
	
      mem [t + 1 ].cint = e ;
      mem [t ].hh .v.RH = u ;
      mem [q ].hh .v.RH = t ;
    } 
    u = newmath ( 0 , 2 ) ;
    if ( mem [r ].hh.b0 == 12 ) 
    {
      j = newskipparam ( 7 ) ;
      mem [u ].hh .v.RH = j ;
      mem [j ].hh .v.RH = p ;
      j = mem [r + 1 ].hh .v.LH ;
      mem [tempptr ].hh.b0 = mem [j ].hh.b0 ;
      mem [tempptr ].hh.b1 = mem [j ].hh.b1 ;
      mem [tempptr + 1 ].cint = d - mem [j + 1 ].cint ;
      mem [tempptr + 2 ].cint = - (integer) mem [j + 2 ].cint ;
      mem [tempptr + 3 ].cint = - (integer) mem [j + 3 ].cint ;
      mem [r ].hh .v.RH = u ;
    } 
    else {
	
      mem [r + 1 ].cint = d ;
      mem [r ].hh .v.RH = p ;
      mem [u ].hh .v.RH = r ;
      if ( j == -1073741823L ) 
      {
	b = hpack ( u , 0 , 1 ) ;
	mem [b + 4 ].cint = s ;
      } 
      else mem [b + 5 ].hh .v.RH = u ;
    } 
  } 
  appendtovlist ( b ) ;
} 
void 
aftermath ( void ) 
{
  aftermath_regmem 
  boolean l  ;
  scaled disp  ;
  boolean danger  ;
  integer m  ;
  halfword p  ;
  halfword a  ;
  halfword b  ;
  scaled w  ;
  scaled z  ;
  scaled e  ;
  scaled q  ;
  scaled d  ;
  scaled s  ;
  smallnumber g1, g2  ;
  halfword r  ;
  halfword t  ;
  halfword j  ;
  danger = false ;
  if ( curlist .modefield == 235 ) 
  j = curlist .eTeXauxfield ;
  if ( ( fontparams [eqtb [25591 ].hh .v.RH ]< 22 ) || ( fontparams [eqtb 
  [25847 ].hh .v.RH ]< 22 ) || ( fontparams [eqtb [26103 ].hh .v.RH ]< 
  22 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1286 ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 1287 ;
      helpline [1 ]= 1288 ;
      helpline [0 ]= 1289 ;
    } 
    error () ;
    flushmath () ;
    danger = true ;
  } 
  else if ( ( fontparams [eqtb [25592 ].hh .v.RH ]< 13 ) || ( fontparams [
  eqtb [25848 ].hh .v.RH ]< 13 ) || ( fontparams [eqtb [26104 ].hh .v.RH 
  ]< 13 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1290 ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 1291 ;
      helpline [1 ]= 1292 ;
      helpline [0 ]= 1293 ;
    } 
    error () ;
    flushmath () ;
    danger = true ;
  } 
  deleteglueref ( curkanjiskip ) ;
  deleteglueref ( curxkanjiskip ) ;
  if ( eqtb [26359 ].hh .v.RH > 0 ) 
  curkanjiskip = eqtb [24543 ].hh .v.RH ;
  else curkanjiskip = membot ;
  if ( eqtb [26360 ].hh .v.RH > 0 ) 
  curxkanjiskip = eqtb [24544 ].hh .v.RH ;
  else curxkanjiskip = membot ;
  incr ( mem [curkanjiskip ].hh .v.RH ) ;
  incr ( mem [curxkanjiskip ].hh .v.RH ) ;
  m = curlist .modefield ;
  l = false ;
  p = finmlist ( -1073741823L ) ;
  if ( curlist .modefield == - (integer) m ) 
  {
    {
      getxtoken () ;
      if ( curcmd != 3 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1294 ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1295 ;
	  helpline [0 ]= 1296 ;
	} 
	backerror () ;
      } 
    } 
    curmlist = p ;
    curstyle = 2 ;
    mlistpenalties = false ;
    mlisttohlist () ;
    a = hpack ( mem [memtop - 3 ].hh .v.RH , 0 , 1 ) ;
    mem [a ].hh.b1 = ( ( mem [a ].hh.b1 ) % 8 ) + 8 * ( 2 ) ;
    unsave () ;
    decr ( saveptr ) ;
    if ( savestack [saveptr + 0 ].cint == 1 ) 
    l = true ;
    danger = false ;
    if ( curlist .modefield == 235 ) 
    j = curlist .eTeXauxfield ;
    if ( ( fontparams [eqtb [25591 ].hh .v.RH ]< 22 ) || ( fontparams [
    eqtb [25847 ].hh .v.RH ]< 22 ) || ( fontparams [eqtb [26103 ].hh 
    .v.RH ]< 22 ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1286 ) ;
      } 
      {
	helpptr = 3 ;
	helpline [2 ]= 1287 ;
	helpline [1 ]= 1288 ;
	helpline [0 ]= 1289 ;
      } 
      error () ;
      flushmath () ;
      danger = true ;
    } 
    else if ( ( fontparams [eqtb [25592 ].hh .v.RH ]< 13 ) || ( fontparams 
    [eqtb [25848 ].hh .v.RH ]< 13 ) || ( fontparams [eqtb [26104 ].hh 
    .v.RH ]< 13 ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1290 ) ;
      } 
      {
	helpptr = 3 ;
	helpline [2 ]= 1291 ;
	helpline [1 ]= 1292 ;
	helpline [0 ]= 1293 ;
      } 
      error () ;
      flushmath () ;
      danger = true ;
    } 
    m = curlist .modefield ;
    p = finmlist ( -1073741823L ) ;
  } 
  else a = -1073741823L ;
  if ( m < 0 ) 
  {
    if ( curlist .dirfield == 3 ) 
    disp = eqtb [29795 ].cint ;
    else disp = eqtb [29796 ].cint ;
    {
      if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield 
      ].hh.b0 == 5 ) ) 
      {
	if ( curlist .pdispfield == disp ) 
	{
	  freenode ( curlist .tailfield , 2 ) ;
	  curlist .tailfield = curlist .pnodefield ;
	  mem [curlist .tailfield ].hh .v.RH = -1073741823L ;
	} 
	else mem [curlist .tailfield + 1 ].cint = disp ;
      } 
      else if ( disp != 0 ) 
      {
	curlist .pnodefield = curlist .tailfield ;
	{
	  mem [curlist .tailfield ].hh .v.RH = getnode ( 2 ) ;
	  curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	} 
	mem [curlist .tailfield ].hh.b0 = 5 ;
	mem [curlist .tailfield + 1 ].cint = disp ;
	curlist .pdispfield = disp ;
      } 
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = newmath ( eqtb [29775 ].cint , 
      0 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    curmlist = p ;
    curstyle = 2 ;
    mlistpenalties = ( curlist .modefield > 0 ) ;
    mlisttohlist () ;
    mem [curlist .tailfield ].hh .v.RH = mem [memtop - 3 ].hh .v.RH ;
    while ( mem [curlist .tailfield ].hh .v.RH != -1073741823L ) curlist 
    .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    {
      mem [curlist .tailfield ].hh .v.RH = newmath ( eqtb [29775 ].cint , 
      1 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    if ( disp != 0 ) 
    {
      if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield 
      ].hh.b0 == 5 ) ) 
      {
	mem [curlist .tailfield + 1 ].cint = 0 ;
      } 
      else {
	  
	curlist .pnodefield = curlist .tailfield ;
	{
	  mem [curlist .tailfield ].hh .v.RH = getnode ( 2 ) ;
	  curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	} 
	mem [curlist .tailfield ].hh.b0 = 5 ;
	mem [curlist .tailfield + 1 ].cint = 0 ;
	curlist .pdispfield = disp ;
      } 
    } 
    curlist .auxfield .hh .v.LH = 1000 ;
    unsave () ;
  } 
  else {
      
    if ( a == -1073741823L ) 
    {
      getxtoken () ;
      if ( curcmd != 3 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1294 ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1295 ;
	  helpline [0 ]= 1296 ;
	} 
	backerror () ;
      } 
    } 
    curmlist = p ;
    curstyle = 0 ;
    mlistpenalties = false ;
    mlisttohlist () ;
    p = mem [memtop - 3 ].hh .v.RH ;
    adjusttail = memtop - 5 ;
    b = hpack ( p , 0 , 1 ) ;
    p = mem [b + 5 ].hh .v.RH ;
    t = adjusttail ;
    adjusttail = -1073741823L ;
    w = mem [b + 1 ].cint ;
    z = eqtb [29788 ].cint ;
    s = eqtb [29789 ].cint ;
    if ( eqtb [29257 ].cint < 0 ) 
    s = - (integer) s - z ;
    if ( ( a == -1073741823L ) || danger ) 
    {
      e = 0 ;
      q = 0 ;
    } 
    else {
	
      e = mem [a + 1 ].cint ;
      q = e + fontinfo [6 + parambase [eqtb [25591 ].hh .v.RH ]].cint ;
    } 
    if ( w + q > z ) 
    {
      if ( ( e != 0 ) && ( ( w - totalshrink [0 ]+ q <= z ) || ( totalshrink 
      [1 ]!= 0 ) || ( totalshrink [2 ]!= 0 ) || ( totalshrink [3 ]!= 0 ) 
      || ( totalshrink [4 ]!= 0 ) ) ) 
      {
	deleteglueref ( mem [b + 7 ].hh .v.RH ) ;
	deleteglueref ( mem [b + 7 ].hh .v.LH ) ;
	freenode ( b , 10 ) ;
	b = hpack ( p , z - q , 0 ) ;
      } 
      else {
	  
	e = 0 ;
	if ( w > z ) 
	{
	  deleteglueref ( mem [b + 7 ].hh .v.RH ) ;
	  deleteglueref ( mem [b + 7 ].hh .v.LH ) ;
	  freenode ( b , 10 ) ;
	  b = hpack ( p , z , 0 ) ;
	} 
      } 
      w = mem [b + 1 ].cint ;
    } 
    mem [b ].hh.b1 = ( ( mem [b ].hh.b1 ) % 8 ) + 8 * ( 2 ) ;
    d = half ( z - w ) ;
    if ( ( e > 0 ) && ( d < 2 * e ) ) 
    {
      d = half ( z - w - e ) ;
      if ( p != -1073741823L ) {
	  
	if ( ! ( p >= himemmin ) ) {
	    
	  if ( mem [p ].hh.b0 == 12 ) 
	  d = 0 ;
	} 
      } 
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [29199 ].cint 
      ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    if ( ( d + s <= eqtb [29787 ].cint ) || l ) 
    {
      g1 = 3 ;
      g2 = 4 ;
    } 
    else {
	
      g1 = 5 ;
      g2 = 6 ;
    } 
    if ( l && ( e == 0 ) ) 
    {
      appdisplay ( j , a , 0 ) ;
      {
	mem [curlist .tailfield ].hh .v.RH = newpenalty ( 10000 ) ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
    } 
    else {
	
      mem [curlist .tailfield ].hh .v.RH = newparamglue ( g1 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    if ( e != 0 ) 
    {
      r = newkern ( z - w - e - d ) ;
      if ( l ) 
      {
	mem [a ].hh .v.RH = r ;
	mem [r ].hh .v.RH = b ;
	b = a ;
	d = 0 ;
      } 
      else {
	  
	mem [b ].hh .v.RH = r ;
	mem [r ].hh .v.RH = a ;
      } 
      b = hpack ( b , 0 , 1 ) ;
    } 
    appdisplay ( j , b , d ) ;
    if ( ( a != -1073741823L ) && ( e == 0 ) && ! l ) 
    {
      {
	mem [curlist .tailfield ].hh .v.RH = newpenalty ( 10000 ) ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      appdisplay ( j , a , z - mem [a + 1 ].cint ) ;
      g2 = 0 ;
    } 
    if ( t != memtop - 5 ) 
    {
      mem [curlist .tailfield ].hh .v.RH = mem [memtop - 5 ].hh .v.RH ;
      curlist .tailfield = t ;
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [29200 ].cint 
      ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    if ( g2 > 0 ) 
    {
      mem [curlist .tailfield ].hh .v.RH = newparamglue ( g2 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    flushnodelist ( j ) ;
    resumeafterdisplay () ;
  } 
} 
void 
resumeafterdisplay ( void ) 
{
  resumeafterdisplay_regmem 
  if ( curgroup != 15 ) 
  confusion ( 1297 ) ;
  unsave () ;
  curlist .pgfield = curlist .pgfield + 3 ;
  pushnest () ;
  curlist .adjdirfield = abs ( curlist .dirfield ) ;
  curlist .modefield = 118 ;
  curlist .auxfield .hh .v.LH = 1000 ;
  if ( eqtb [29239 ].cint <= 0 ) 
  curlang = 0 ;
  else if ( eqtb [29239 ].cint > 255 ) 
  curlang = 0 ;
  else curlang = eqtb [29239 ].cint ;
  curlist .auxfield .hh .v.RH = curlang ;
  curlist .pgfield = ( normmin ( eqtb [29240 ].cint ) * 64 + normmin ( eqtb 
  [29241 ].cint ) ) * 65536L + curlang ;
  {
    getxtoken () ;
    if ( curcmd != 10 ) 
    backinput () ;
  } 
  if ( nestptr == 1 ) 
  buildpage () ;
} 
void 
getrtoken ( void ) 
{
  /* 20 */ getrtoken_regmem 
  lab20: do {
      gettoken () ;
  } while ( ! ( curtok != 2592 ) ) ;
  if ( ( curcs == 0 ) || ( curcs > eqtbtop ) || ( ( curcs > 15514 ) && ( curcs 
  <= 30310 ) ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1315 ) ;
    } 
    {
      helpptr = 5 ;
      helpline [4 ]= 1316 ;
      helpline [3 ]= 1317 ;
      helpline [2 ]= 1318 ;
      helpline [1 ]= 1319 ;
      helpline [0 ]= 1320 ;
    } 
    if ( curcs == 0 ) 
    backinput () ;
    curtok = 536886425L ;
    inserror () ;
    goto lab20 ;
  } 
} 
void 
trapzeroglue ( void ) 
{
  trapzeroglue_regmem 
  if ( ( mem [curval + 1 ].cint == 0 ) && ( mem [curval + 2 ].cint == 0 ) 
  && ( mem [curval + 3 ].cint == 0 ) ) 
  {
    incr ( mem [membot ].hh .v.RH ) ;
    deleteglueref ( curval ) ;
    curval = membot ;
  } 
} 
void 
zdoregistercommand ( smallnumber a ) 
{
  /* 40 10 */ doregistercommand_regmem 
  halfword l, q, r, s  ;
  unsigned char p  ;
  boolean e  ;
  integer w  ;
  q = curcmd ;
  e = false ;
  {
    if ( q != 103 ) 
    {
      getxtoken () ;
      if ( ( curcmd >= 82 ) && ( curcmd <= 85 ) ) 
      {
	l = curchr ;
	p = curcmd - 82 ;
	goto lab40 ;
      } 
      if ( curcmd != 103 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 751 ) ;
	} 
	printcmdchr ( curcmd , curchr ) ;
	print ( 752 ) ;
	printcmdchr ( q , 0 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1351 ;
	} 
	error () ;
	return ;
      } 
    } 
    if ( ( curchr < membot ) || ( curchr > membot + 23 ) ) 
    {
      l = curchr ;
      p = ( mem [l ].hh.b0 / 16 ) ;
      e = true ;
    } 
    else {
	
      p = curchr - membot ;
      scanregisternum () ;
      if ( curval > 255 ) 
      {
	findsaelement ( p , curval , true ) ;
	l = curptr ;
	e = true ;
      } 
      else switch ( p ) 
      {case 0 : 
	l = curval + 29262 ;
	break ;
      case 1 : 
	l = curval + 29799 ;
	break ;
      case 2 : 
	l = curval + 24549 ;
	break ;
      case 3 : 
	l = curval + 24805 ;
	break ;
      } 
    } 
  } 
  lab40: if ( p < 2 ) {
      
    if ( e ) 
    w = mem [l + 2 ].cint ;
    else w = eqtb [l ].cint ;
  } 
  else if ( e ) 
  s = mem [l + 1 ].hh .v.RH ;
  else s = eqtb [l ].hh .v.RH ;
  if ( q == 103 ) 
  scanoptionalequals () ;
  else if ( scankeyword ( 1347 ) ) 
  ;
  aritherror = false ;
  if ( q < 105 ) {
      
    if ( p < 2 ) 
    {
      if ( p == 0 ) 
      scanint () ;
      else scandimen ( false , false , false ) ;
      if ( q == 104 ) 
      curval = curval + w ;
    } 
    else {
	
      scanglue ( p ) ;
      if ( q == 104 ) 
      {
	q = newspec ( curval ) ;
	r = s ;
	deleteglueref ( curval ) ;
	mem [q + 1 ].cint = mem [q + 1 ].cint + mem [r + 1 ].cint ;
	if ( mem [q + 2 ].cint == 0 ) 
	mem [q ].hh.b0 = 0 ;
	if ( mem [q ].hh.b0 == mem [r ].hh.b0 ) 
	mem [q + 2 ].cint = mem [q + 2 ].cint + mem [r + 2 ].cint ;
	else if ( ( mem [q ].hh.b0 < mem [r ].hh.b0 ) && ( mem [r + 2 ]
	.cint != 0 ) ) 
	{
	  mem [q + 2 ].cint = mem [r + 2 ].cint ;
	  mem [q ].hh.b0 = mem [r ].hh.b0 ;
	} 
	if ( mem [q + 3 ].cint == 0 ) 
	mem [q ].hh.b1 = 0 ;
	if ( mem [q ].hh.b1 == mem [r ].hh.b1 ) 
	mem [q + 3 ].cint = mem [q + 3 ].cint + mem [r + 3 ].cint ;
	else if ( ( mem [q ].hh.b1 < mem [r ].hh.b1 ) && ( mem [r + 3 ]
	.cint != 0 ) ) 
	{
	  mem [q + 3 ].cint = mem [r + 3 ].cint ;
	  mem [q ].hh.b1 = mem [r ].hh.b1 ;
	} 
	curval = q ;
      } 
    } 
  } 
  else {
      
    scanint () ;
    if ( p < 2 ) {
	
      if ( q == 105 ) {
	  
	if ( p == 0 ) 
	curval = multandadd ( w , curval , 0 , 2147483647L ) ;
	else curval = multandadd ( w , curval , 0 , 1073741823L ) ;
      } 
      else curval = xovern ( w , curval ) ;
    } 
    else {
	
      r = newspec ( s ) ;
      if ( q == 105 ) 
      {
	mem [r + 1 ].cint = multandadd ( mem [s + 1 ].cint , curval , 0 , 
	1073741823L ) ;
	mem [r + 2 ].cint = multandadd ( mem [s + 2 ].cint , curval , 0 , 
	1073741823L ) ;
	mem [r + 3 ].cint = multandadd ( mem [s + 3 ].cint , curval , 0 , 
	1073741823L ) ;
      } 
      else {
	  
	mem [r + 1 ].cint = xovern ( mem [s + 1 ].cint , curval ) ;
	mem [r + 2 ].cint = xovern ( mem [s + 2 ].cint , curval ) ;
	mem [r + 3 ].cint = xovern ( mem [s + 3 ].cint , curval ) ;
      } 
      curval = r ;
    } 
  } 
  if ( aritherror ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1348 ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 1349 ;
      helpline [0 ]= 1350 ;
    } 
    if ( p >= 2 ) 
    deleteglueref ( curval ) ;
    error () ;
    return ;
  } 
  if ( p < 2 ) {
      
    if ( e ) {
	
      if ( ( a >= 4 ) ) 
      gsawdef ( l , curval ) ;
      else sawdef ( l , curval ) ;
    } 
    else if ( ( a >= 4 ) ) 
    geqworddefine ( l , curval ) ;
    else eqworddefine ( l , curval ) ;
  } 
  else {
      
    trapzeroglue () ;
    if ( e ) {
	
      if ( ( a >= 4 ) ) 
      gsadef ( l , curval ) ;
      else sadef ( l , curval ) ;
    } 
    else if ( ( a >= 4 ) ) 
    geqdefine ( l , 133 , curval ) ;
    else eqdefine ( l , 133 , curval ) ;
  } 
} 
void 
alteraux ( void ) 
{
  alteraux_regmem 
  halfword c  ;
  if ( curchr != abs ( curlist .modefield ) ) 
  reportillegalcase () ;
  else {
      
    c = curchr ;
    scanoptionalequals () ;
    if ( c == 1 ) 
    {
      scandimen ( false , false , false ) ;
      curlist .auxfield .cint = curval ;
    } 
    else {
	
      scanint () ;
      if ( ( curval <= 0 ) || ( curval > 32767 ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1354 ) ;
	} 
	{
	  helpptr = 1 ;
	  helpline [0 ]= 1355 ;
	} 
	interror ( curval ) ;
      } 
      else curlist .auxfield .hh .v.LH = curval ;
    } 
  } 
} 
void 
alterprevgraf ( void ) 
{
  alterprevgraf_regmem 
  integer p  ;
  nest [nestptr ]= curlist ;
  p = nestptr ;
  while ( abs ( nest [p ].modefield ) != 1 ) decr ( p ) ;
  scanoptionalequals () ;
  scanint () ;
  if ( curval < 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1056 ) ;
    } 
    printesc ( 581 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 1356 ;
    } 
    interror ( curval ) ;
  } 
  else {
      
    nest [p ].pgfield = curval ;
    curlist = nest [nestptr ];
  } 
} 
void 
alterpagesofar ( void ) 
{
  alterpagesofar_regmem 
  unsigned char c  ;
  c = curchr ;
  scanoptionalequals () ;
  scandimen ( false , false , false ) ;
  pagesofar [c ]= curval ;
} 
void 
alterinteger ( void ) 
{
  alterinteger_regmem 
  smallnumber c  ;
  c = curchr ;
  scanoptionalequals () ;
  scanint () ;
  if ( c == 0 ) 
  deadcycles = curval ;
  else if ( c == 2 ) 
  {
    if ( ( curval < 0 ) || ( curval > 3 ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1509 ) ;
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 1510 ;
	helpline [0 ]= 1511 ;
      } 
      interror ( curval ) ;
    } 
    else {
	
      curchr = curval ;
      newinteraction () ;
    } 
  } 
  else insertpenalties = curval ;
} 
void 
alterboxdimen ( void ) 
{
  alterboxdimen_regmem 
  smallnumber c  ;
  halfword p, q  ;
  halfword b  ;
  c = curchr ;
  scanregisternum () ;
  if ( curval < 256 ) 
  b = eqtb [25332 + curval ].hh .v.RH ;
  else {
      
    findsaelement ( 4 , curval , false ) ;
    if ( curptr == -1073741823L ) 
    b = -1073741823L ;
    else b = mem [curptr + 1 ].hh .v.RH ;
  } 
  scanoptionalequals () ;
  scandimen ( false , false , false ) ;
  if ( b != -1073741823L ) 
  {
    q = b ;
    p = mem [q ].hh .v.RH ;
    while ( p != -1073741823L ) {
	
      if ( abs ( curlist .dirfield ) == ( ( mem [p ].hh.b1 ) % 8 ) ) 
      q = p ;
      p = mem [p ].hh .v.RH ;
    } 
    if ( ( ( mem [q ].hh.b1 ) % 8 ) != abs ( curlist .dirfield ) ) 
    {
      p = mem [b ].hh .v.RH ;
      mem [b ].hh .v.RH = -1073741823L ;
      q = newdirnode ( q , abs ( curlist .dirfield ) ) ;
      mem [q + 5 ].hh .v.RH = -1073741823L ;
      mem [q ].hh .v.RH = p ;
      mem [b ].hh .v.RH = q ;
    } 
    mem [q + c ].cint = curval ;
  } 
} 
void 
znewfont ( smallnumber a ) 
{
  /* 50 */ newfont_regmem 
  halfword u  ;
  scaled s  ;
  internalfontnumber f  ;
  strnumber t  ;
  unsigned char oldsetting  ;
  if ( jobname == 0 ) 
  openlogfile () ;
  getrtoken () ;
  u = curcs ;
  if ( u >= 514 ) 
  t = hash [u ].v.RH ;
  else if ( u >= 257 ) {
      
    if ( u == 513 ) 
    t = 1360 ;
    else t = u - 257 ;
  } 
  else {
      
    oldsetting = selector ;
    selector = 21 ;
    print ( 1360 ) ;
    print ( u - 1 ) ;
    selector = oldsetting ;
    {
      if ( poolptr + 1 > poolsize ) 
      overflow ( 259 , poolsize - initpoolptr ) ;
    } 
    t = makestring () ;
  } 
  if ( ( a >= 4 ) ) 
  geqdefine ( u , 99 , 0 ) ;
  else eqdefine ( u , 99 , 0 ) ;
  scanoptionalequals () ;
  scanfilename () ;
  nameinprogress = true ;
  if ( scankeyword ( 1361 ) ) 
  {
    scandimen ( false , false , false ) ;
    s = curval ;
    if ( ( s <= 0 ) || ( s >= 134217728L ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1363 ) ;
      } 
      printscaled ( s ) ;
      print ( 1364 ) ;
      {
	helpptr = 2 ;
	helpline [1 ]= 1365 ;
	helpline [0 ]= 1366 ;
      } 
      error () ;
      s = 10 * 65536L ;
    } 
  } 
  else if ( scankeyword ( 1362 ) ) 
  {
    scanint () ;
    s = - (integer) curval ;
    if ( ( curval <= 0 ) || ( curval > 32768L ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 606 ) ;
      } 
      {
	helpptr = 1 ;
	helpline [0 ]= 607 ;
      } 
      interror ( curval ) ;
      s = -1000 ;
    } 
  } 
  else s = -1000 ;
  nameinprogress = false ;
  {register integer for_end; f = 1 ;for_end = fontptr ; if ( f <= for_end) 
  do 
    if ( streqstr ( fontname [f ], curname ) && streqstr ( fontarea [f ], 
    curarea ) ) 
    {
      if ( s > 0 ) 
      {
	if ( s == fontsize [f ]) 
	goto lab50 ;
      } 
      else if ( fontsize [f ]== xnoverd ( fontdsize [f ], - (integer) s , 
      1000 ) ) 
      goto lab50 ;
    } 
  while ( f++ < for_end ) ;} 
  f = readfontinfo ( u , curname , curarea , s ) ;
  lab50: if ( ( a >= 4 ) ) 
  geqdefine ( u , 99 , f ) ;
  else eqdefine ( u , 99 , f ) ;
  eqtb [15526 + f ]= eqtb [u ];
  hash [15526 + f ].v.RH = t ;
} 
void 
newinteraction ( void ) 
{
  newinteraction_regmem 
  println () ;
  interaction = curchr ;
  if ( interaction == 0 ) 
  kpsemaketexdiscarderrors = 1 ;
  else kpsemaketexdiscarderrors = 0 ;
  if ( interaction == 0 ) 
  selector = 16 ;
  else selector = 17 ;
  if ( logopened ) 
  selector = selector + 2 ;
} 
void 
doassignments ( void ) 
{
  /* 10 */ doassignments_regmem 
  while ( true ) {
      
    do {
	getxtoken () ;
    } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
    if ( curcmd <= 79 ) 
    return ;
    setboxallowed = false ;
    prefixedcommand () ;
    setboxallowed = true ;
  } 
} 
void 
openorclosein ( void ) 
{
  openorclosein_regmem 
  unsigned char c  ;
  unsigned char n  ;
  c = curchr ;
  scanfourbitint () ;
  n = curval ;
  if ( readopen [n ]!= 2 ) 
  {
    aclose ( readfile [n ]) ;
    readopen [n ]= 2 ;
  } 
  if ( c != 0 ) 
  {
    scanoptionalequals () ;
    scanfilename () ;
    packfilename ( curname , curarea , curext ) ;
    texinputtype = 0 ;
    if ( kpseinnameok ( stringcast ( nameoffile + 1 ) ) && aopenin ( readfile 
    [n ], kpsetexformat ) ) 
    readopen [n ]= 1 ;
  } 
} 
void 
issuemessage ( void ) 
{
  issuemessage_regmem 
  unsigned char oldsetting  ;
  unsigned char c  ;
  strnumber s  ;
  c = curchr ;
  mem [memtop - 12 ].hh .v.RH = scantoks ( false , true ) ;
  oldsetting = selector ;
  selector = 21 ;
  tokenshow ( defref ) ;
  selector = oldsetting ;
  flushlist ( defref ) ;
  {
    if ( poolptr + 1 > poolsize ) 
    overflow ( 259 , poolsize - initpoolptr ) ;
  } 
  s = makestring () ;
  if ( c == 0 ) 
  {
    if ( termoffset + ( strstart [s + 1 ]- strstart [s ]) > maxprintline - 
    2 ) 
    println () ;
    else if ( ( termoffset > 0 ) || ( fileoffset > 0 ) ) 
    printchar ( 32 ) ;
    slowprint ( s ) ;
    fflush ( stdout ) ;
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 344 ) ;
    } 
    slowprint ( s ) ;
    if ( eqtb [25070 ].hh .v.RH != -1073741823L ) 
    useerrhelp = true ;
    else if ( longhelpseen ) 
    {
      helpptr = 1 ;
      helpline [0 ]= 1373 ;
    } 
    else {
	
      if ( interaction < 3 ) 
      longhelpseen = true ;
      {
	helpptr = 4 ;
	helpline [3 ]= 1374 ;
	helpline [2 ]= 1375 ;
	helpline [1 ]= 1376 ;
	helpline [0 ]= 1377 ;
      } 
    } 
    error () ;
    useerrhelp = false ;
  } 
  {
    decr ( strptr ) ;
    poolptr = strstart [strptr ];
  } 
} 
void 
shiftcase ( void ) 
{
  shiftcase_regmem 
  halfword b  ;
  halfword p  ;
  halfword t  ;
  eightbits c  ;
  b = curchr ;
  p = scantoks ( false , false ) ;
  p = mem [defref ].hh .v.RH ;
  while ( p != -1073741823L ) {
      
    t = mem [p ].hh .v.LH ;
    if ( ( t < 536871168L ) && ( ! checkkanji ( t ) ) ) 
    {
      c = t % 256 ;
      if ( eqtb [b + c ].hh .v.RH != 0 ) 
      mem [p ].hh .v.LH = t - c + eqtb [b + c ].hh .v.RH ;
    } 
    p = mem [p ].hh .v.RH ;
  } 
  begintokenlist ( mem [defref ].hh .v.RH , 3 ) ;
  {
    mem [defref ].hh .v.RH = avail ;
    avail = defref ;
	;
#ifdef STAT
    decr ( dynused ) ;
#endif /* STAT */
  } 
} 
void 
showwhatever ( void ) 
{
  /* 50 */ showwhatever_regmem 
  halfword p  ;
  smallnumber t  ;
  unsigned char m  ;
  integer l  ;
  integer n  ;
  switch ( curchr ) 
  {case 3 : 
    {
      begindiagnostic () ;
      showactivities () ;
    } 
    break ;
  case 1 : 
    {
      scanregisternum () ;
      if ( curval < 256 ) 
      p = eqtb [25332 + curval ].hh .v.RH ;
      else {
	  
	findsaelement ( 4 , curval , false ) ;
	if ( curptr == -1073741823L ) 
	p = -1073741823L ;
	else p = mem [curptr + 1 ].hh .v.RH ;
      } 
      begindiagnostic () ;
      printnl ( 1394 ) ;
      printint ( curval ) ;
      printchar ( 61 ) ;
      if ( p == -1073741823L ) 
      print ( 432 ) ;
      else showbox ( p ) ;
    } 
    break ;
  case 0 : 
    {
      gettoken () ;
      if ( interaction == 3 ) 
      ;
      printnl ( 1390 ) ;
      if ( curcs != 0 ) 
      {
	sprintcs ( curcs ) ;
	printchar ( 61 ) ;
      } 
      printmeaning () ;
      goto lab50 ;
    } 
    break ;
  case 7 : 
    {
      printnl ( 1390 ) ;
      if ( eqtb [26359 ].hh .v.RH > 0 ) 
      print ( 1586 ) ;
      else print ( 1587 ) ;
      printnl ( 1390 ) ;
      if ( eqtb [26360 ].hh .v.RH > 0 ) 
      print ( 1588 ) ;
      else print ( 1589 ) ;
      goto lab50 ;
    } 
    break ;
  case 4 : 
    {
      begindiagnostic () ;
      showsavegroups () ;
    } 
    break ;
  case 6 : 
    {
      begindiagnostic () ;
      printnl ( 344 ) ;
      println () ;
      if ( condptr == -1073741823L ) 
      {
	printnl ( 380 ) ;
	print ( 1506 ) ;
      } 
      else {
	  
	p = condptr ;
	n = 0 ;
	do {
	    incr ( n ) ;
	  p = mem [p ].hh .v.RH ;
	} while ( ! ( p == -1073741823L ) ) ;
	p = condptr ;
	t = curif ;
	l = ifline ;
	m = iflimit ;
	do {
	    printnl ( 1507 ) ;
	  printint ( n ) ;
	  print ( 622 ) ;
	  printcmdchr ( 121 , t ) ;
	  if ( m == 2 ) 
	  printesc ( 874 ) ;
	  if ( l != 0 ) 
	  {
	    print ( 1505 ) ;
	    printint ( l ) ;
	  } 
	  decr ( n ) ;
	  t = mem [p ].hh.b1 ;
	  l = mem [p + 1 ].cint ;
	  m = mem [p ].hh.b0 ;
	  p = mem [p ].hh .v.RH ;
	} while ( ! ( p == -1073741823L ) ) ;
      } 
    } 
    break ;
    default: 
    {
      p = thetoks () ;
      if ( interaction == 3 ) 
      ;
      printnl ( 1390 ) ;
      tokenshow ( memtop - 3 ) ;
      flushlist ( mem [memtop - 3 ].hh .v.RH ) ;
      goto lab50 ;
    } 
    break ;
  } 
  enddiagnostic ( true ) ;
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 264 ) ;
    print ( 1395 ) ;
  } 
  if ( selector == 19 ) {
      
    if ( eqtb [29217 ].cint <= 0 ) 
    {
      selector = 17 ;
      print ( 1396 ) ;
      selector = 19 ;
    } 
  } 
  lab50: if ( interaction < 3 ) 
  {
    helpptr = 0 ;
    decr ( errorcount ) ;
  } 
  else if ( eqtb [29217 ].cint > 0 ) 
  {
    {
      helpptr = 3 ;
      helpline [2 ]= 1385 ;
      helpline [1 ]= 1386 ;
      helpline [0 ]= 1387 ;
    } 
  } 
  else {
      
    {
      helpptr = 5 ;
      helpline [4 ]= 1385 ;
      helpline [3 ]= 1386 ;
      helpline [2 ]= 1387 ;
      helpline [1 ]= 1388 ;
      helpline [0 ]= 1389 ;
    } 
  } 
  error () ;
} 
void 
znewwhatsit ( smallnumber s , smallnumber w ) 
{
  newwhatsit_regmem 
  halfword p  ;
  p = getnode ( w ) ;
  mem [p ].hh.b0 = 10 ;
  mem [p ].hh.b1 = s ;
  mem [curlist .tailfield ].hh .v.RH = p ;
  curlist .tailfield = p ;
} 
void 
znewwritewhatsit ( smallnumber w ) 
{
  newwritewhatsit_regmem 
  newwhatsit ( curchr , w ) ;
  if ( w != 2 ) 
  scanfourbitint () ;
  else {
      
    scanint () ;
    if ( curval < 0 ) 
    curval = 17 ;
    else if ( ( curval > 15 ) && ( curval != 18 ) ) 
    curval = 16 ;
  } 
  mem [curlist .tailfield + 1 ].hh .v.LH = curval ;
} 
void 
comparestrings ( void ) 
{
  /* 30 */ comparestrings_regmem 
  strnumber s1, s2  ;
  poolpointer i1, i2, j1, j2  ;
  {
    if ( scantoks ( false , true ) != 0 ) 
    ;
  } 
  isprintutf8 = true ;
  s1 = tokenstostring ( defref ) ;
  isprintutf8 = false ;
  deletetokenref ( defref ) ;
  {
    if ( scantoks ( false , true ) != 0 ) 
    ;
  } 
  isprintutf8 = true ;
  s2 = tokenstostring ( defref ) ;
  isprintutf8 = false ;
  deletetokenref ( defref ) ;
  i1 = strstart [s1 ];
  j1 = strstart [s1 + 1 ];
  i2 = strstart [s2 ];
  j2 = strstart [s2 + 1 ];
  while ( ( i1 < j1 ) && ( i2 < j2 ) ) {
      
    if ( strpool [i1 ]< strpool [i2 ]) 
    {
      curval = -1 ;
      goto lab30 ;
    } 
    if ( strpool [i1 ]> strpool [i2 ]) 
    {
      curval = 1 ;
      goto lab30 ;
    } 
    incr ( i1 ) ;
    incr ( i2 ) ;
  } 
  if ( ( i1 == j1 ) && ( i2 == j2 ) ) 
  curval = 0 ;
  else if ( i1 < j1 ) 
  curval = 1 ;
  else curval = -1 ;
  lab30: flushstr ( s2 ) ;
  flushstr ( s1 ) ;
  curvallevel = 0 ;
} 
void 
scanpdfexttoks ( void ) 
{
  scanpdfexttoks_regmem 
  {
    if ( scantoks ( false , true ) != 0 ) 
    ;
  } 
} 
void 
doextension ( void ) 
{
  doextension_regmem 
  integer k  ;
  halfword p  ;
  switch ( curchr ) 
  {case 0 : 
    {
      newwritewhatsit ( 3 ) ;
      scanoptionalequals () ;
      scanfilename () ;
      mem [curlist .tailfield + 1 ].hh .v.RH = curname ;
      mem [curlist .tailfield + 2 ].hh .v.LH = curarea ;
      mem [curlist .tailfield + 2 ].hh .v.RH = curext ;
    } 
    break ;
  case 1 : 
    {
      k = curcs ;
      newwritewhatsit ( 2 ) ;
      curcs = k ;
      p = scantoks ( false , false ) ;
      mem [curlist .tailfield + 1 ].hh .v.RH = defref ;
    } 
    break ;
  case 2 : 
    {
      newwritewhatsit ( 2 ) ;
      mem [curlist .tailfield + 1 ].hh .v.RH = -1073741823L ;
    } 
    break ;
  case 3 : 
    {
      newwhatsit ( 3 , 2 ) ;
      mem [curlist .tailfield + 1 ].hh .v.LH = -1073741823L ;
      p = scantoks ( false , true ) ;
      mem [curlist .tailfield + 1 ].hh .v.RH = defref ;
    } 
    break ;
  case 4 : 
    {
      getxtoken () ;
      if ( ( curcmd == 64 ) && ( curchr <= 2 ) ) 
      {
	p = curlist .tailfield ;
	doextension () ;
	outwhat ( curlist .tailfield ) ;
	flushnodelist ( curlist .tailfield ) ;
	curlist .tailfield = p ;
	mem [p ].hh .v.RH = -1073741823L ;
      } 
      else backinput () ;
    } 
    break ;
  case 5 : 
    if ( abs ( curlist .modefield ) != 118 ) 
    reportillegalcase () ;
    else {
	
      newwhatsit ( 4 , 2 ) ;
      scanint () ;
      if ( curval <= 0 ) 
      curlist .auxfield .hh .v.RH = 0 ;
      else if ( curval > 255 ) 
      curlist .auxfield .hh .v.RH = 0 ;
      else curlist .auxfield .hh .v.RH = curval ;
      mem [curlist .tailfield + 1 ].hh .v.RH = curlist .auxfield .hh .v.RH ;
      mem [curlist .tailfield + 1 ].hh.b0 = normmin ( eqtb [29240 ].cint ) 
      ;
      mem [curlist .tailfield + 1 ].hh.b1 = normmin ( eqtb [29241 ].cint ) 
      ;
    } 
    break ;
  case 6 : 
    {
      newwhatsit ( 6 , 2 ) ;
    } 
    break ;
  case 7 : 
    {
      scanfilename () ;
      packfilename ( curname , curarea , curext ) ;
      if ( setinfileenc ( inputfile [curinput .indexfield ], stringcast ( 
      nameoffile + 1 ) ) == false ) 
      {
	putc ('\n',  logfile );
	Fputs ( logfile ,  "Unknown encoding `" ) ;
	fputs ( stringcast ( nameoffile + 1 ) , logfile ) ;
	putc ( '\'' ,  logfile );
      } 
    } 
    break ;
    default: 
    confusion ( 1436 ) ;
    break ;
  } 
} 
void 
fixlanguage ( void ) 
{
  fixlanguage_regmem 
  ASCIIcode l  ;
  if ( eqtb [29239 ].cint <= 0 ) 
  l = 0 ;
  else if ( eqtb [29239 ].cint > 255 ) 
  l = 0 ;
  else l = eqtb [29239 ].cint ;
  if ( l != curlist .auxfield .hh .v.RH ) 
  {
    newwhatsit ( 4 , 2 ) ;
    mem [curlist .tailfield + 1 ].hh .v.RH = l ;
    curlist .auxfield .hh .v.RH = l ;
    mem [curlist .tailfield + 1 ].hh.b0 = normmin ( eqtb [29240 ].cint ) ;
    mem [curlist .tailfield + 1 ].hh.b1 = normmin ( eqtb [29241 ].cint ) ;
  } 
} 
void 
zsetmathkchar ( integer c ) 
{
  setmathkchar_regmem 
  halfword p  ;
  p = newnoad () ;
  mem [p + 1 ].hh .v.RH = 6 ;
  inhibitglueflag = false ;
  mem [p + 1 ].hh.b1 = 0 ;
  mem [p + 4 ].hh .v.LH = c ;
  mem [p + 1 ].hh.b0 = eqtb [29233 ].cint ;
  if ( fontdir [eqtb [25589 + mem [p + 1 ].hh.b0 + cursize ].hh .v.RH ]
  == 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 264 ) ;
      print ( 1255 ) ;
    } 
    {
      helpptr = 1 ;
      helpline [0 ]= 1254 ;
    } 
    error () ;
  } 
  mem [p ].hh.b0 = 18 ;
  mem [curlist .tailfield ].hh .v.RH = p ;
  curlist .tailfield = p ;
} 
void 
insertsrcspecial ( void ) 
{
  insertsrcspecial_regmem 
  halfword toklist, p, q  ;
  if ( ( sourcefilenamestack [inopen ]> 0 && isnewsource ( 
  sourcefilenamestack [inopen ], line ) ) ) 
  {
    toklist = getavail () ;
    p = toklist ;
    mem [p ].hh .v.LH = 536886435L ;
    mem [p ].hh .v.RH = getavail () ;
    p = mem [p ].hh .v.RH ;
    mem [p ].hh .v.LH = 379 ;
    q = strtoks ( makesrcspecial ( sourcefilenamestack [inopen ], line ) ) ;
    mem [p ].hh .v.RH = mem [memtop - 3 ].hh .v.RH ;
    p = q ;
    mem [p ].hh .v.RH = getavail () ;
    p = mem [p ].hh .v.RH ;
    mem [p ].hh .v.LH = 637 ;
    begintokenlist ( toklist , 4 ) ;
    remembersourceinfo ( sourcefilenamestack [inopen ], line ) ;
  } 
} 
void 
appendsrcspecial ( void ) 
{
  appendsrcspecial_regmem 
  halfword q  ;
  if ( ( sourcefilenamestack [inopen ]> 0 && isnewsource ( 
  sourcefilenamestack [inopen ], line ) ) ) 
  {
    newwhatsit ( 3 , 2 ) ;
    mem [curlist .tailfield + 1 ].hh .v.LH = 0 ;
    defref = getavail () ;
    mem [defref ].hh .v.LH = -1073741823L ;
    q = strtoks ( makesrcspecial ( sourcefilenamestack [inopen ], line ) ) ;
    mem [defref ].hh .v.RH = mem [memtop - 3 ].hh .v.RH ;
    mem [curlist .tailfield + 1 ].hh .v.RH = defref ;
    remembersourceinfo ( sourcefilenamestack [inopen ], line ) ;
  } 
} 
void 
handlerightbrace ( void ) 
{
  handlerightbrace_regmem 
  halfword p, q  ;
  halfword r  ;
  scaled d  ;
  integer f  ;
  switch ( curgroup ) 
  {case 1 : 
    unsave () ;
    break ;
  case 0 : 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 1149 ) ;
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 1150 ;
	helpline [0 ]= 1151 ;
      } 
      error () ;
    } 
    break ;
  case 14 : 
  case 15 : 
  case 16 : 
    extrarightbrace () ;
    break ;
  case 2 : 
    {
      adjusthlist ( curlist .headfield , false ) ;
      package ( 0 ) ;
    } 
    break ;
  case 3 : 
    {
      adjusthlist ( curlist .headfield , false ) ;
      adjusttail = memtop - 5 ;
      package ( 0 ) ;
    } 
    break ;
  case 4 : 
    {
      endgraf () ;
      package ( 0 ) ;
    } 
    break ;
  case 5 : 
    {
      endgraf () ;
      package ( 4 ) ;
    } 
    break ;
  case 11 : 
    {
      endgraf () ;
      q = eqtb [24538 ].hh .v.RH ;
      incr ( mem [q ].hh .v.RH ) ;
      d = eqtb [29780 ].cint ;
      f = eqtb [29230 ].cint ;
      unsave () ;
      decr ( saveptr ) ;
      p = vpackage ( mem [curlist .headfield ].hh .v.RH , 0 , 1 , 
      1073741823L ) ;
      mem [p ].hh.b1 = ( ( mem [p ].hh.b1 ) / 8 ) * 8 + abs ( curlist 
      .dirfield ) ;
      popnest () ;
      if ( savestack [saveptr + 0 ].cint < 255 ) 
      {
	r = getnode ( 6 ) ;
	mem [r ].hh.b0 = 4 ;
	mem [r ].hh.b1 = savestack [saveptr + 0 ].cint ;
	mem [r + 3 ].cint = mem [p + 3 ].cint + mem [p + 2 ].cint ;
	mem [r + 4 ].hh .v.LH = mem [p + 5 ].hh .v.RH ;
	mem [r + 4 ].hh .v.RH = q ;
	mem [r + 2 ].cint = d ;
	mem [r + 1 ].cint = f ;
	mem [r + 5 ].hh.b1 = ( ( mem [p ].hh.b1 ) % 8 ) ;
	if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist 
	.tailfield ].hh.b0 == 5 ) ) 
	{
	  mem [curlist .pnodefield ].hh .v.RH = r ;
	  mem [mem [curlist .pnodefield ].hh .v.RH ].hh .v.RH = curlist 
	  .tailfield ;
	  curlist .pnodefield = mem [curlist .pnodefield ].hh .v.RH ;
	} 
	else {
	    
	  mem [curlist .tailfield ].hh .v.RH = r ;
	  curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	} 
      } 
      else {
	  
	if ( ( ( mem [p ].hh.b1 ) % 8 ) != curlist .adjdirfield ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 1207 ) ;
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 1208 ;
	  } 
	  error () ;
	  flushnodelist ( mem [p + 5 ].hh .v.RH ) ;
	} 
	else {
	    
	  r = getnode ( 2 ) ;
	  mem [r ].hh.b0 = 7 ;
	  mem [r + 1 ].cint = mem [p + 5 ].hh .v.RH ;
	  deleteglueref ( q ) ;
	  if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist 
	  .tailfield ].hh.b0 == 5 ) ) 
	  {
	    mem [curlist .pnodefield ].hh .v.RH = r ;
	    mem [mem [curlist .pnodefield ].hh .v.RH ].hh .v.RH = curlist 
	    .tailfield ;
	    curlist .pnodefield = mem [curlist .pnodefield ].hh .v.RH ;
	  } 
	  else {
	      
	    mem [curlist .tailfield ].hh .v.RH = r ;
	    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	  } 
	} 
      } 
      deleteglueref ( mem [p + 7 ].hh .v.RH ) ;
      deleteglueref ( mem [p + 7 ].hh .v.LH ) ;
      freenode ( p , 10 ) ;
      if ( nestptr == 0 ) 
      buildpage () ;
    } 
    break ;
  case 8 : 
    {
      if ( ( curinput .locfield != -1073741823L ) || ( ( curinput .indexfield 
      != 6 ) && ( curinput .indexfield != 3 ) ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1115 ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1116 ;
	  helpline [0 ]= 1117 ;
	} 
	error () ;
	do {
	    gettoken () ;
	} while ( ! ( curinput .locfield == -1073741823L ) ) ;
      } 
      endtokenlist () ;
      endgraf () ;
      unsave () ;
      outputactive = false ;
      insertpenalties = 0 ;
      if ( eqtb [25587 ].hh .v.RH != -1073741823L ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 1118 ) ;
	} 
	printesc ( 431 ) ;
	printint ( 255 ) ;
	{
	  helpptr = 3 ;
	  helpline [2 ]= 1119 ;
	  helpline [1 ]= 1120 ;
	  helpline [0 ]= 1121 ;
	} 
	boxerror ( 255 ) ;
      } 
      if ( curlist .tailfield != curlist .headfield ) 
      {
	mem [pagetail ].hh .v.RH = mem [curlist .headfield ].hh .v.RH ;
	pagetail = curlist .tailfield ;
      } 
      if ( mem [memtop - 2 ].hh .v.RH != -1073741823L ) 
      {
	if ( mem [memtop - 1 ].hh .v.RH == -1073741823L ) 
	nest [0 ].tailfield = pagetail ;
	mem [pagetail ].hh .v.RH = mem [memtop - 1 ].hh .v.RH ;
	mem [memtop - 1 ].hh .v.RH = mem [memtop - 2 ].hh .v.RH ;
	mem [memtop - 2 ].hh .v.RH = -1073741823L ;
	pagetail = memtop - 2 ;
      } 
      flushnodelist ( discptr [2 ]) ;
      discptr [2 ]= -1073741823L ;
      popnest () ;
      buildpage () ;
    } 
    break ;
  case 10 : 
    builddiscretionary () ;
    break ;
  case 6 : 
    {
      backinput () ;
      curtok = 536886426L ;
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 264 ) ;
	print ( 686 ) ;
      } 
      printesc ( 1000 ) ;
      print ( 687 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 1249 ;
      } 
      inserror () ;
    } 
    break ;
  case 7 : 
    {
      endgraf () ;
      unsave () ;
      alignpeek () ;
    } 
    break ;
  case 12 : 
    {
      endgraf () ;
      unsave () ;
      saveptr = saveptr - 2 ;
      p = vpackage ( mem [curlist .headfield ].hh .v.RH , savestack [
      saveptr + 1 ].cint , savestack [saveptr + 0 ].cint , 1073741823L ) ;
      mem [p ].hh.b1 = ( ( mem [p ].hh.b1 ) / 8 ) * 8 + abs ( curlist 
      .dirfield ) ;
      popnest () ;
      if ( ( ( mem [p ].hh.b1 ) % 8 ) != abs ( curlist .dirfield ) ) 
      p = newdirnode ( p , abs ( curlist .dirfield ) ) ;
      {
	mem [curlist .tailfield ].hh .v.RH = newnoad () ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [curlist .tailfield ].hh.b0 = 31 ;
      mem [curlist .tailfield + 1 ].hh .v.RH = 2 ;
      mem [curlist .tailfield + 1 ].hh .v.LH = p ;
    } 
    break ;
  case 13 : 
    buildchoices () ;
    break ;
  case 9 : 
    {
      unsave () ;
      decr ( saveptr ) ;
      mem [savestack [saveptr + 0 ].cint ].hh .v.RH = 4 ;
      p = finmlist ( -1073741823L ) ;
      mem [savestack [saveptr + 0 ].cint ].hh .v.LH = p ;
      if ( p != -1073741823L ) {
	  
	if ( mem [p ].hh .v.RH == -1073741823L ) {
	    
	  if ( mem [p ].hh.b0 == 18 ) 
	  {
	    if ( mem [p + 3 ].hh .v.RH == 0 ) {
		
	      if ( ( ( mem [p + 2 ].hh .v.RH == 0 ) && ( mem [p + 4 ].hh 
	      .v.LH == -1073741823L ) ) ) 
	      {
		mem [savestack [saveptr + 0 ].cint ].hh = mem [p + 1 ]
		.hh ;
		freenode ( p , 5 ) ;
	      } 
	    } 
	  } 
	  else if ( mem [p ].hh.b0 == 30 ) {
	      
	    if ( savestack [saveptr + 0 ].cint == curlist .tailfield + 1 ) {
		
	      if ( mem [curlist .tailfield ].hh.b0 == 18 ) 
	      {
		q = curlist .headfield ;
		while ( mem [q ].hh .v.RH != curlist .tailfield ) q = mem [
		q ].hh .v.RH ;
		mem [q ].hh .v.RH = p ;
		freenode ( curlist .tailfield , 5 ) ;
		curlist .tailfield = p ;
	      } 
	    } 
	  } 
	} 
      } 
    } 
    break ;
    default: 
    confusion ( 1152 ) ;
    break ;
  } 
} 
void 
maincontrol ( void ) 
{
  /* 60 21 70 80 130 131 133 141 150 90 91 92 95 100 101 110 111 112 120 10 
  */ maincontrol_regmem 
  integer t  ;
  KANJIcode cx  ;
  halfword kp  ;
  halfword gp, gq  ;
  scaled disp  ;
  boolean inskp  ;
  if ( eqtb [25068 ].hh .v.RH != -1073741823L ) 
  begintokenlist ( eqtb [25068 ].hh .v.RH , 12 ) ;
  lab60: getxtoken () ;
  lab21: if ( interrupt != 0 ) {
      
    if ( OKtointerrupt ) 
    {
      backinput () ;
      {
	if ( interrupt != 0 ) 
	pauseforinstructions () ;
      } 
      goto lab60 ;
    } 
  } 
	;
#ifdef TEXMF_DEBUG
  if ( panicking ) 
  checkmem ( false ) ;
#endif /* TEXMF_DEBUG */
  if ( eqtb [29224 ].cint > 0 ) 
  showcurcmdchr () ;
  inskp = false ;
  switch ( abs ( curlist .modefield ) + curcmd ) 
  {case 129 : 
  case 130 : 
    goto lab70 ;
    break ;
  case 134 : 
  case 135 : 
  case 136 : 
  case 137 : 
  case 192 : 
    goto lab130 ;
    break ;
  case 191 : 
    if ( checkecharrange ( curchr ) ) 
    goto lab70 ;
    else goto lab130 ;
    break ;
  case 138 : 
    {
      scancharnum () ;
      curchr = curval ;
      if ( checkecharrange ( curchr ) ) 
      goto lab70 ;
      else goto lab130 ;
    } 
    break ;
  case 172 : 
    {
      scancharnum () ;
      curchr = curval ;
      goto lab130 ;
    } 
    break ;
  case 188 : 
    {
      getxtoken () ;
      if ( ( curcmd == 11 ) || ( curcmd == 12 ) || ( ( curcmd >= 16 ) && ( 
      curcmd <= 19 ) ) || ( curcmd == 73 ) || ( curcmd == 20 ) || ( curcmd == 
      74 ) || ( curcmd == 54 ) ) 
      cancelboundary = true ;
      goto lab21 ;
    } 
    break ;
  case 128 : 
    if ( curlist .auxfield .hh .v.LH == 1000 ) 
    goto lab120 ;
    else appspace () ;
    break ;
  case 187 : 
  case 304 : 
    goto lab120 ;
    break ;
  case 1 : 
  case 118 : 
  case 235 : 
  case 11 : 
  case 245 : 
  case 305 : 
    ;
    break ;
  case 44 : 
  case 161 : 
  case 278 : 
    {
      if ( curchr == 0 ) 
      {
	do {
	    getxtoken () ;
	} while ( ! ( curcmd != 10 ) ) ;
	goto lab21 ;
      } 
      else {
	  
	t = scannerstatus ;
	scannerstatus = 0 ;
	getnext () ;
	scannerstatus = t ;
	if ( curcs < 514 ) 
	curcs = primlookup ( curcs - 257 ) ;
	else curcs = primlookup ( hash [curcs ].v.RH ) ;
	if ( curcs != 0 ) 
	{
	  curcmd = primeqtb [curcs ].hh.b0 ;
	  curchr = primeqtb [curcs ].hh .v.RH ;
	  goto lab21 ;
	} 
      } 
    } 
    break ;
  case 15 : 
    if ( itsallover () ) 
    return ;
    break ;
  case 27 : 
  case 143 : 
  case 260 : 
  case 78 : 
  case 195 : 
  case 312 : 
  case 43 : 
  case 49 : 
  case 53 : 
  case 170 : 
  case 7 : 
  case 124 : 
  case 241 : 
    reportillegalcase () ;
    break ;
  case 8 : 
  case 125 : 
  case 9 : 
  case 126 : 
  case 22 : 
  case 139 : 
  case 76 : 
  case 193 : 
  case 77 : 
  case 194 : 
  case 56 : 
  case 173 : 
  case 16 : 
  case 133 : 
  case 54 : 
  case 171 : 
  case 58 : 
  case 175 : 
  case 72 : 
  case 189 : 
  case 59 : 
  case 176 : 
  case 60 : 
  case 177 : 
  case 62 : 
  case 179 : 
  case 61 : 
  case 178 : 
  case 35 : 
  case 152 : 
  case 57 : 
  case 174 : 
  case 33 : 
  case 150 : 
  case 51 : 
  case 168 : 
  case 244 : 
  case 248 : 
  case 249 : 
  case 266 : 
  case 263 : 
  case 272 : 
  case 275 : 
    insertdollarsign () ;
    break ;
  case 41 : 
  case 157 : 
  case 274 : 
    {
      {
	mem [curlist .tailfield ].hh .v.RH = scanrulespec () ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      if ( abs ( curlist .modefield ) == 1 ) 
      curlist .auxfield .cint = -65536000L ;
      else if ( abs ( curlist .modefield ) == 118 ) 
      curlist .auxfield .hh .v.LH = 1000 ;
    } 
    break ;
  case 32 : 
  case 148 : 
  case 265 : 
  case 267 : 
    appendglue () ;
    break ;
  case 34 : 
  case 151 : 
  case 268 : 
  case 269 : 
    appendkern () ;
    break ;
  case 2 : 
  case 119 : 
    newsavelevel ( 1 ) ;
    break ;
  case 67 : 
  case 184 : 
  case 301 : 
    newsavelevel ( 14 ) ;
    break ;
  case 68 : 
  case 185 : 
  case 302 : 
    if ( curgroup == 14 ) 
    unsave () ;
    else offsave () ;
    break ;
  case 3 : 
  case 120 : 
  case 237 : 
    handlerightbrace () ;
    break ;
  case 26 : 
  case 144 : 
  case 261 : 
    {
      t = curchr ;
      scandimen ( false , false , false ) ;
      if ( t == 0 ) 
      scanbox ( curval ) ;
      else scanbox ( - (integer) curval ) ;
    } 
    break ;
  case 36 : 
  case 153 : 
  case 270 : 
    scanbox ( 1073872797L + curchr ) ;
    break ;
  case 25 : 
  case 142 : 
  case 259 : 
    beginbox ( 0 ) ;
    break ;
  case 80 : 
  case 197 : 
  case 314 : 
    {
      if ( curgroup != 6 ) {
	  
	if ( curlist .headfield == curlist .tailfield ) 
	{
	  curlist .dirfield = curchr ;
	  if ( curlist .modefield == 1 ) 
	  pagedir = curchr ;
	} 
	else {
	    
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 264 ) ;
	    print ( 1174 ) ;
	  } 
	  printcmdchr ( curcmd , curchr ) ;
	  print ( 1175 ) ;
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 1176 ;
	    helpline [0 ]= 1177 ;
	  } 
	  error () ;
	} 
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 264 ) ;
	  print ( 751 ) ;
	} 
	printcmdchr ( curcmd , curchr ) ;
	print ( 1178 ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 1179 ;
	  helpline [0 ]= 1180 ;
	} 
	error () ;
      } 
    } 
    break ;
  case 48 : 
    newgraf ( curchr > 0 ) ;
    break ;
  case 12 : 
  case 13 : 
  case 21 : 
  case 74 : 
  case 55 : 
  case 75 : 
  case 4 : 
  case 28 : 
  case 40 : 
  case 50 : 
  case 52 : 
  case 31 : 
  case 38 : 
  case 17 : 
  case 18 : 
  case 19 : 
  case 20 : 
  case 70 : 
  case 71 : 
    {
      backinput () ;
      newgraf ( true ) ;
    } 
    break ;
  case 165 : 
  case 282 : 
    indentinhmode () ;
    break ;
  case 14 : 
    {
      normalparagraph () ;
      if ( curlist .modefield > 0 ) 
      buildpage () ;
    } 
    break ;
  case 131 : 
    {
      if ( alignstate < 0 ) 
      offsave () ;
      endgraf () ;
      if ( curlist .modefield == 1 ) 
      buildpage () ;
    } 
    break ;
  case 132 : 
  case 149 : 
  case 158 : 
  case 146 : 
  case 154 : 
    headforvmode () ;
    break ;
  case 42 : 
  case 159 : 
  case 276 : 
  case 160 : 
  case 277 : 
    begininsertoradjust () ;
    break ;
  case 23 : 
  case 140 : 
  case 257 : 
    makemark () ;
    break ;
  case 47 : 
  case 164 : 
  case 281 : 
    appendpenalty () ;
    break ;
  case 30 : 
  case 147 : 
  case 264 : 
    deletelast () ;
    break ;
  case 29 : 
  case 145 : 
  case 262 : 
    unpackage () ;
    break ;
  case 166 : 
    appenditaliccorrection () ;
    break ;
  case 283 : 
    {
      mem [curlist .tailfield ].hh .v.RH = newkern ( 0 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    break ;
  case 169 : 
  case 286 : 
    appenddiscretionary () ;
    break ;
  case 167 : 
    makeaccent () ;
    break ;
  case 6 : 
  case 123 : 
  case 240 : 
  case 5 : 
  case 122 : 
  case 239 : 
    alignerror () ;
    break ;
  case 39 : 
  case 156 : 
  case 273 : 
    noalignerror () ;
    break ;
  case 69 : 
  case 186 : 
  case 303 : 
    omiterror () ;
    break ;
  case 37 : 
    initalign () ;
    break ;
  case 155 : 
    if ( curchr > 0 ) 
    {
      if ( eTeXenabled ( ( eqtb [29261 ].cint > 0 ) , curcmd , curchr ) ) 
      {
	mem [curlist .tailfield ].hh .v.RH = newmath ( 0 , curchr ) ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
    } 
    else initalign () ;
    break ;
  case 271 : 
    if ( privileged () ) {
	
      if ( curgroup == 15 ) 
      initalign () ;
      else offsave () ;
    } 
    break ;
  case 10 : 
  case 127 : 
    doendv () ;
    break ;
  case 73 : 
  case 190 : 
  case 307 : 
    cserror () ;
    break ;
  case 121 : 
    initmath () ;
    break ;
  case 287 : 
    if ( privileged () ) {
	
      if ( curgroup == 15 ) 
      starteqno () ;
      else offsave () ;
    } 
    break ;
  case 236 : 
    {
      {
	mem [curlist .tailfield ].hh .v.RH = newnoad () ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      backinput () ;
      scanmath ( curlist .tailfield + 1 , curlist .tailfield + 4 ) ;
    } 
    break ;
  case 246 : 
  case 247 : 
  case 308 : 
    if ( checkecharrange ( curchr ) ) {
	
      if ( curchr < 128 ) 
      setmathchar ( eqtb [28676 + curchr ].hh .v.RH ) ;
      else setmathchar ( curchr ) ;
    } 
    else setmathkchar ( curchr ) ;
    break ;
  case 251 : 
  case 252 : 
  case 253 : 
  case 254 : 
    {
      cx = curchr ;
      setmathkchar ( cx ) ;
    } 
    break ;
  case 255 : 
    {
      scancharnum () ;
      curchr = curval ;
      if ( checkecharrange ( curchr ) ) {
	  
	if ( curchr < 128 ) 
	setmathchar ( eqtb [28676 + curchr ].hh .v.RH ) ;
	else setmathchar ( curchr ) ;
      } 
      else setmathkchar ( curchr ) ;
    } 
    break ;
  case 309 : 
    setmathkchar ( curchr ) ;
    break ;
  case 289 : 
    {
      scancharnum () ;
      curchr = curval ;
      setmathkchar ( curchr ) ;
    } 
    break ;
  case 256 : 
    {
      if ( curchr == 0 ) 
      scanfifteenbitint () ;
      else scanbigfifteenbitint () ;
      setmathchar ( curval ) ;
    } 
    break ;
  case 310 : 
    {
      setmathchar ( ( ( curchr / 4096 ) * 65536L ) + ( curchr % 4096 ) ) ;
    } 
    break ;
  case 311 : 
    {
      setmathchar ( ( ( curchr / 65536L ) * 256 ) + ( curchr % 256 ) ) ;
    } 
    break ;
  case 250 : 
    {
      if ( curchr == 0 ) 
      scantwentysevenbitint () ;
      else scanfiftyonebitint () ;
      setmathchar ( curval ) ;
    } 
    break ;
  case 290 : 
    {
      {
	mem [curlist .tailfield ].hh .v.RH = newnoad () ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [curlist .tailfield ].hh.b0 = curchr ;
      scanmath ( curlist .tailfield + 1 , curlist .tailfield + 4 ) ;
    } 
    break ;
  case 291 : 
    mathlimitswitch () ;
    break ;
  case 306 : 
    mathradical () ;
    break ;
  case 284 : 
  case 285 : 
    mathac () ;
    break ;
  case 296 : 
    {
      scanspec ( 12 , false ) ;
      normalparagraph () ;
      inhibitglueflag = false ;
      pushnest () ;
      curlist .modefield = -1 ;
      curlist .auxfield .cint = -65536000L ;
      if ( ( insertsrcspecialeveryvbox ) ) 
      insertsrcspecial () ;
      if ( eqtb [25067 ].hh .v.RH != -1073741823L ) 
      begintokenlist ( eqtb [25067 ].hh .v.RH , 11 ) ;
    } 
    break ;
  case 293 : 
    {
      mem [curlist .tailfield ].hh .v.RH = newstyle ( curchr ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    break ;
  case 295 : 
    {
      {
	mem [curlist .tailfield ].hh .v.RH = newglue ( membot ) ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [curlist .tailfield ].hh.b1 = 98 ;
    } 
    break ;
  case 294 : 
    appendchoices () ;
    break ;
  case 243 : 
  case 242 : 
    subsup () ;
    break ;
  case 292 : 
    mathfraction () ;
    break ;
  case 288 : 
    mathleftright () ;
    break ;
  case 238 : 
    if ( curgroup == 15 ) 
    aftermath () ;
    else offsave () ;
    break ;
  case 89 : 
  case 206 : 
  case 323 : 
  case 90 : 
  case 207 : 
  case 324 : 
  case 116 : 
  case 233 : 
  case 350 : 
  case 117 : 
  case 234 : 
  case 351 : 
  case 91 : 
  case 208 : 
  case 325 : 
  case 81 : 
  case 198 : 
  case 315 : 
  case 82 : 
  case 199 : 
  case 316 : 
  case 83 : 
  case 200 : 
  case 317 : 
  case 102 : 
  case 219 : 
  case 336 : 
  case 103 : 
  case 220 : 
  case 337 : 
  case 84 : 
  case 201 : 
  case 318 : 
  case 85 : 
  case 202 : 
  case 319 : 
  case 86 : 
  case 203 : 
  case 320 : 
  case 87 : 
  case 204 : 
  case 321 : 
  case 88 : 
  case 205 : 
  case 322 : 
  case 92 : 
  case 209 : 
  case 326 : 
  case 93 : 
  case 210 : 
  case 327 : 
  case 94 : 
  case 211 : 
  case 328 : 
  case 95 : 
  case 212 : 
  case 329 : 
  case 96 : 
  case 213 : 
  case 330 : 
  case 97 : 
  case 214 : 
  case 331 : 
  case 98 : 
  case 215 : 
  case 332 : 
  case 99 : 
  case 216 : 
  case 333 : 
  case 100 : 
  case 217 : 
  case 334 : 
  case 101 : 
  case 218 : 
  case 335 : 
  case 104 : 
  case 221 : 
  case 338 : 
  case 105 : 
  case 222 : 
  case 339 : 
  case 106 : 
  case 223 : 
  case 340 : 
  case 107 : 
  case 224 : 
  case 341 : 
  case 108 : 
  case 225 : 
  case 342 : 
  case 109 : 
  case 226 : 
  case 343 : 
  case 110 : 
  case 227 : 
  case 344 : 
  case 111 : 
  case 228 : 
  case 345 : 
  case 112 : 
  case 229 : 
  case 346 : 
  case 113 : 
  case 230 : 
  case 347 : 
  case 114 : 
  case 231 : 
  case 348 : 
  case 115 : 
  case 232 : 
  case 349 : 
    prefixedcommand () ;
    break ;
  case 45 : 
  case 162 : 
  case 279 : 
    {
      gettoken () ;
      aftertoken = curtok ;
    } 
    break ;
  case 46 : 
  case 163 : 
  case 280 : 
    {
      gettoken () ;
      saveforafter ( curtok ) ;
    } 
    break ;
  case 66 : 
  case 183 : 
  case 300 : 
    openorclosein () ;
    break ;
  case 64 : 
  case 181 : 
  case 298 : 
    issuemessage () ;
    break ;
  case 63 : 
  case 180 : 
  case 297 : 
    shiftcase () ;
    break ;
  case 24 : 
  case 141 : 
  case 258 : 
    showwhatever () ;
    break ;
  case 79 : 
  case 196 : 
  case 313 : 
    inhibitglueflag = true ;
    break ;
  case 65 : 
  case 182 : 
  case 299 : 
    doextension () ;
    break ;
  } 
  goto lab60 ;
  lab130: if ( ( curlist .tailfield >= himemmin ) ) 
  {
    cx = mem [curlist .tailfield ].hh.b1 ;
    {
      kp = getkinsokupos ( cx , 1 ) ;
      if ( kp != 1000 ) 
      {
	if ( eqtb [27642 + kp ].hh.b0 == 2 ) 
	{
	  {
	    mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [30055 + 
	    kp ].cint ) ;
	    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	  } 
	  mem [curlist .tailfield ].hh.b1 = 2 ;
	} 
      } 
    } 
  } 
  else if ( mem [curlist .tailfield ].hh.b0 == 8 ) 
  {
    cx = mem [curlist .tailfield + 1 ].hh.b1 ;
    {
      kp = getkinsokupos ( cx , 1 ) ;
      if ( kp != 1000 ) 
      {
	if ( eqtb [27642 + kp ].hh.b0 == 2 ) 
	{
	  {
	    mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [30055 + 
	    kp ].cint ) ;
	    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	  } 
	  mem [curlist .tailfield ].hh.b1 = 2 ;
	} 
      } 
    } 
  } 
  if ( curlist .dirfield == 3 ) 
  {
    if ( fontdir [mainf ]== 3 ) 
    disp = 0 ;
    else if ( fontdir [mainf ]== 4 ) 
    disp = eqtb [29795 ].cint - eqtb [29796 ].cint ;
    else disp = eqtb [29795 ].cint ;
    mainf = eqtb [26358 ].hh .v.RH ;
  } 
  else {
      
    if ( fontdir [mainf ]== 4 ) 
    disp = 0 ;
    else if ( fontdir [mainf ]== 3 ) 
    disp = eqtb [29796 ].cint - eqtb [29795 ].cint ;
    else disp = eqtb [29796 ].cint ;
    mainf = eqtb [26357 ].hh .v.RH ;
  } 
  if ( disp != 0 ) 
  {
    if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield ]
    .hh.b0 == 5 ) ) 
    {
      mem [curlist .tailfield + 1 ].cint = 0 ;
    } 
    else {
	
      curlist .pnodefield = curlist .tailfield ;
      {
	mem [curlist .tailfield ].hh .v.RH = getnode ( 2 ) ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [curlist .tailfield ].hh.b0 = 5 ;
      mem [curlist .tailfield + 1 ].cint = 0 ;
      curlist .pdispfield = disp ;
    } 
  } 
  inskp = false ;
  ligaturepresent = false ;
  curl = getjfmpos ( curchr , mainf ) ;
  maini = fontinfo [charbase [mainf ]+ 0 ].qqqq ;
  goto lab133 ;
  lab131: curlist .auxfield .hh .v.LH = 1000 ;
  if ( mainf != 0 ) 
  {
    {
      mainp = avail ;
      if ( mainp == -1073741823L ) 
      mainp = getavail () ;
      else {
	  
	avail = mem [mainp ].hh .v.RH ;
	mem [mainp ].hh .v.RH = -1073741823L ;
	;
#ifdef STAT
	incr ( dynused ) ;
#endif /* STAT */
      } 
    } 
    mem [mainp ].hh.b0 = mainf ;
    mem [mainp ].hh.b1 = curl ;
    mem [curlist .tailfield ].hh .v.RH = mainp ;
    curlist .tailfield = mainp ;
    curlist .lastjchrfield = curlist .tailfield ;
    {
      mainp = avail ;
      if ( mainp == -1073741823L ) 
      mainp = getavail () ;
      else {
	  
	avail = mem [mainp ].hh .v.RH ;
	mem [mainp ].hh .v.RH = -1073741823L ;
	;
#ifdef STAT
	incr ( dynused ) ;
#endif /* STAT */
      } 
    } 
    mem [mainp ].hh .v.LH = curchr + curcmd * 16777216L ;
    mem [curlist .tailfield ].hh .v.RH = mainp ;
    curlist .tailfield = mainp ;
    cx = curchr ;
    {
      kp = getkinsokupos ( cx , 1 ) ;
      if ( kp != 1000 ) 
      {
	if ( eqtb [27642 + kp ].hh.b0 == 1 ) 
	{
	  if ( ! ( curq >= himemmin ) && ( mem [curq ].hh.b0 == 14 ) ) 
	  mem [curq + 1 ].cint = mem [curq + 1 ].cint + eqtb [30055 + kp 
	  ].cint ;
	  else {
	      
	    mainp = mem [curq ].hh .v.RH ;
	    mem [curq ].hh .v.RH = newpenalty ( eqtb [30055 + kp ].cint ) 
	    ;
	    mem [mem [curq ].hh .v.RH ].hh.b1 = 2 ;
	    mem [mem [curq ].hh .v.RH ].hh .v.RH = mainp ;
	  } 
	} 
	else if ( eqtb [27642 + kp ].hh.b0 == 2 ) 
	{
	  {
	    mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [30055 + 
	    kp ].cint ) ;
	    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	  } 
	  mem [curlist .tailfield ].hh.b1 = 2 ;
	} 
      } 
    } 
  } 
  inskp = false ;
  lab150: getnext () ;
  maini = fontinfo [charbase [mainf ]+ curl ].qqqq ;
  switch ( curcmd ) 
  {case 16 : 
  case 17 : 
  case 18 : 
  case 19 : 
    {
      curl = getjfmpos ( curchr , mainf ) ;
      goto lab133 ;
    } 
    break ;
  case 11 : 
  case 12 : 
    {
      inskp = true ;
      curl = 0 ;
      goto lab133 ;
    } 
    break ;
  } 
  xtoken () ;
  switch ( curcmd ) 
  {case 16 : 
  case 17 : 
  case 18 : 
  case 19 : 
    curl = getjfmpos ( curchr , mainf ) ;
    break ;
  case 11 : 
  case 12 : 
    {
      inskp = true ;
      curl = 0 ;
    } 
    break ;
  case 73 : 
    {
      if ( checkecharrange ( curchr ) ) 
      {
	inskp = true ;
	curl = 0 ;
      } 
      else curl = getjfmpos ( curchr , mainf ) ;
    } 
    break ;
  case 20 : 
    {
      scancharnum () ;
      curchr = curval ;
      if ( checkecharrange ( curchr ) ) 
      {
	inskp = true ;
	curl = 0 ;
      } 
      else curl = getjfmpos ( curchr , mainf ) ;
    } 
    break ;
  case 74 : 
    {
      curl = getjfmpos ( curchr , mainf ) ;
    } 
    break ;
  case 54 : 
    {
      scancharnum () ;
      curchr = curval ;
      curl = getjfmpos ( curchr , mainf ) ;
    } 
    break ;
  case 78 : 
    {
      inhibitglueflag = true ;
      goto lab150 ;
    } 
    break ;
    default: 
    {
      inskp = 1073741823L ;
      curl = 0 ;
      curr = 256 ;
      ligstack = -1073741823L ;
    } 
    break ;
  } 
  lab133: if ( inskp == true ) 
  {
    kp = getkinsokupos ( curchr , 1 ) ;
    if ( kp != 1000 ) 
    {
      if ( eqtb [27642 + kp ].hh.b0 == 1 ) {
	  
	if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist 
	.tailfield ].hh.b0 == 14 ) ) 
	mem [curlist .tailfield + 1 ].cint = mem [curlist .tailfield + 1 ]
	.cint + eqtb [30055 + kp ].cint ;
	else {
	    
	  {
	    mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [30055 + 
	    kp ].cint ) ;
	    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	  } 
	  mem [curlist .tailfield ].hh.b1 = 2 ;
	} 
      } 
    } 
  } 
  if ( mainf != 0 ) 
  {
    curq = curlist .tailfield ;
    if ( inhibitglueflag != true ) 
    {
      if ( ( ( maini .b2 ) % 4 ) == 1 ) 
      {
	maink = ligkernbase [mainf ]+ maini .b3 ;
	do {
	    mainj = fontinfo [maink ].qqqq ;
	  if ( mainj .b1 == curl ) 
	  {
	    if ( mainj .b2 < 128 ) 
	    {
	      gp = fontglue [mainf ];
	      curr = mainj .b3 ;
	      if ( gp != -1073741823L ) 
	      {
		while ( ( ( mem [gp ].hh.b0 != curr ) && ( mem [gp ].hh 
		.v.RH != -1073741823L ) ) ) gp = mem [gp ].hh .v.RH ;
		gq = mem [gp + 1 ].hh .v.LH ;
	      } 
	      else {
		  
		gp = getnode ( 2 ) ;
		fontglue [mainf ]= gp ;
		gq = -1073741823L ;
	      } 
	      if ( gq == -1073741823L ) 
	      {
		mem [gp ].hh.b0 = curr ;
		gq = newspec ( membot ) ;
		mem [gp + 1 ].hh .v.LH = gq ;
		maink = extenbase [mainf ]+ ( curr ) * 3 ;
		mem [gq + 1 ].cint = fontinfo [maink ].cint ;
		mem [gq + 2 ].cint = fontinfo [maink + 1 ].cint ;
		mem [gq + 3 ].cint = fontinfo [maink + 2 ].cint ;
		incr ( mem [gq ].hh .v.RH ) ;
		mem [gp ].hh .v.RH = getnode ( 2 ) ;
		gp = mem [gp ].hh .v.RH ;
		mem [gp + 1 ].hh .v.LH = -1073741823L ;
		mem [gp ].hh .v.RH = -1073741823L ;
	      } 
	      {
		mem [curlist .tailfield ].hh .v.RH = newglue ( gq ) ;
		curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	      } 
	      mem [curlist .tailfield ].hh.b1 = 21 ;
	      goto lab141 ;
	    } 
	    else {
		
	      {
		mem [curlist .tailfield ].hh .v.RH = newkern ( fontinfo [
		kernbase [mainf ]+ 256 * mainj .b2 + mainj .b3 ].cint ) ;
		curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	      } 
	      goto lab141 ;
	    } 
	  } 
	  incr ( maink ) ;
	} while ( ! ( mainj .b0 >= 128 ) ) ;
      } 
    } 
    lab141: inhibitglueflag = false ;
  } 
  else inhibitglueflag = false ;
  if ( inskp == false ) 
  {
    goto lab131 ;
  } 
  else if ( inskp == true ) 
  {
    inskp = false ;
    goto lab70 ;
  } 
  else {
      
    goto lab21 ;
  } 
  lab70: inhibitglueflag = false ;
  if ( ( ( curlist .headfield == curlist .tailfield ) && ( curlist .modefield 
  > 0 ) ) ) 
  {
    if ( ( insertsrcspecialauto ) ) 
    appendsrcspecial () ;
  } 
  mains = eqtb [28420 + curchr ].hh .v.RH ;
  if ( mains == 1000 ) 
  curlist .auxfield .hh .v.LH = 1000 ;
  else if ( mains < 1000 ) 
  {
    if ( mains > 0 ) 
    curlist .auxfield .hh .v.LH = mains ;
  } 
  else if ( curlist .auxfield .hh .v.LH < 1000 ) 
  curlist .auxfield .hh .v.LH = 1000 ;
  else curlist .auxfield .hh .v.LH = mains ;
  if ( curlist .dirfield == 3 ) 
  disp = eqtb [29795 ].cint ;
  else disp = eqtb [29796 ].cint ;
  {
    if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield ]
    .hh.b0 == 5 ) ) 
    {
      if ( curlist .pdispfield == disp ) 
      {
	freenode ( curlist .tailfield , 2 ) ;
	curlist .tailfield = curlist .pnodefield ;
	mem [curlist .tailfield ].hh .v.RH = -1073741823L ;
      } 
      else mem [curlist .tailfield + 1 ].cint = disp ;
    } 
    else if ( disp != 0 ) 
    {
      curlist .pnodefield = curlist .tailfield ;
      {
	mem [curlist .tailfield ].hh .v.RH = getnode ( 2 ) ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [curlist .tailfield ].hh.b0 = 5 ;
      mem [curlist .tailfield + 1 ].cint = disp ;
      curlist .pdispfield = disp ;
    } 
  } 
  mainf = eqtb [25588 ].hh .v.RH ;
  bchar = fontbchar [mainf ];
  falsebchar = fontfalsebchar [mainf ];
  if ( curlist .modefield > 0 ) {
      
    if ( eqtb [29239 ].cint != curlist .auxfield .hh .v.RH ) 
    fixlanguage () ;
  } 
  {
    ligstack = avail ;
    if ( ligstack == -1073741823L ) 
    ligstack = getavail () ;
    else {
	
      avail = mem [ligstack ].hh .v.RH ;
      mem [ligstack ].hh .v.RH = -1073741823L ;
	;
#ifdef STAT
      incr ( dynused ) ;
#endif /* STAT */
    } 
  } 
  mem [ligstack ].hh.b0 = mainf ;
  curl = curchr ;
  mem [ligstack ].hh.b1 = curl ;
  curq = curlist .tailfield ;
  if ( cancelboundary ) 
  {
    cancelboundary = false ;
    maink = 0 ;
  } 
  else maink = bcharlabel [mainf ];
  if ( maink == 0 ) 
  goto lab92 ;
  curr = curl ;
  curl = 256 ;
  goto lab111 ;
  lab80: if ( curl < 256 ) 
  {
    if ( mem [curq ].hh .v.RH > -1073741823L ) {
	
      if ( mem [curlist .tailfield ].hh.b1 == hyphenchar [mainf ]) 
      insdisc = true ;
    } 
    if ( ligaturepresent ) 
    {
      mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) ;
      if ( lfthit ) 
      {
	mem [mainp ].hh.b1 = 2 ;
	lfthit = false ;
      } 
      if ( rthit ) {
	  
	if ( ligstack == -1073741823L ) 
	{
	  incr ( mem [mainp ].hh.b1 ) ;
	  rthit = false ;
	} 
      } 
      mem [curq ].hh .v.RH = mainp ;
      curlist .tailfield = mainp ;
      ligaturepresent = false ;
    } 
    if ( insdisc ) 
    {
      insdisc = false ;
      if ( curlist .modefield > 0 ) 
      {
	mem [curlist .tailfield ].hh .v.RH = newdisc () ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
    } 
  } 
  lab90: if ( ligstack == -1073741823L ) 
  {
    if ( disp != 0 ) 
    {
      if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield 
      ].hh.b0 == 5 ) ) 
      {
	mem [curlist .tailfield + 1 ].cint = 0 ;
      } 
      else {
	  
	curlist .pnodefield = curlist .tailfield ;
	{
	  mem [curlist .tailfield ].hh .v.RH = getnode ( 2 ) ;
	  curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	} 
	mem [curlist .tailfield ].hh.b0 = 5 ;
	mem [curlist .tailfield + 1 ].cint = 0 ;
	curlist .pdispfield = disp ;
      } 
    } 
    goto lab21 ;
  } 
  curq = curlist .tailfield ;
  curl = mem [ligstack ].hh.b1 ;
  lab91: if ( ! ( ligstack >= himemmin ) ) 
  goto lab95 ;
  lab92: if ( ( effectivechar ( false , mainf , curchr ) > fontec [mainf ]) 
  || ( effectivechar ( false , mainf , curchr ) < fontbc [mainf ]) ) 
  {
    charwarning ( mainf , curchr ) ;
    {
      mem [ligstack ].hh .v.RH = avail ;
      avail = ligstack ;
	;
#ifdef STAT
      decr ( dynused ) ;
#endif /* STAT */
    } 
    goto lab60 ;
  } 
  maini = effectivecharinfo ( mainf , curl ) ;
  if ( ! ( maini .b0 > 0 ) ) 
  {
    charwarning ( mainf , curchr ) ;
    {
      mem [ligstack ].hh .v.RH = avail ;
      avail = ligstack ;
	;
#ifdef STAT
      decr ( dynused ) ;
#endif /* STAT */
    } 
    goto lab60 ;
  } 
  mem [curlist .tailfield ].hh .v.RH = ligstack ;
  curlist .tailfield = ligstack ;
  lab100: getnext () ;
  if ( curcmd == 11 ) 
  goto lab101 ;
  if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
  {
    bchar = 256 ;
    curr = bchar ;
    ligstack = -1073741823L ;
    if ( ligaturepresent ) 
    {
      mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) ;
      if ( lfthit ) 
      {
	mem [mainp ].hh.b1 = 2 ;
	lfthit = false ;
      } 
      if ( rthit ) {
	  
	if ( ligstack == -1073741823L ) 
	{
	  incr ( mem [mainp ].hh.b1 ) ;
	  rthit = false ;
	} 
      } 
      mem [curq ].hh .v.RH = mainp ;
      curlist .tailfield = mainp ;
      ligaturepresent = false ;
    } 
    if ( inskp == true ) 
    {
      cx = curl ;
      {
	kp = getkinsokupos ( cx , 1 ) ;
	if ( kp != 1000 ) 
	{
	  if ( eqtb [27642 + kp ].hh.b0 == 1 ) 
	  {
	    if ( ! ( curq >= himemmin ) && ( mem [curq ].hh.b0 == 14 ) ) 
	    mem [curq + 1 ].cint = mem [curq + 1 ].cint + eqtb [30055 + 
	    kp ].cint ;
	    else {
		
	      mainp = mem [curq ].hh .v.RH ;
	      mem [curq ].hh .v.RH = newpenalty ( eqtb [30055 + kp ].cint 
	      ) ;
	      mem [mem [curq ].hh .v.RH ].hh.b1 = 2 ;
	      mem [mem [curq ].hh .v.RH ].hh .v.RH = mainp ;
	    } 
	  } 
	  else if ( eqtb [27642 + kp ].hh.b0 == 2 ) 
	  {
	    {
	      mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [30055 
	      + kp ].cint ) ;
	      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	    } 
	    mem [curlist .tailfield ].hh.b1 = 2 ;
	  } 
	} 
      } 
    } 
    inskp = false ;
    goto lab130 ;
  } 
  if ( curcmd == 12 ) 
  goto lab101 ;
  if ( curcmd == 73 ) 
  {
    if ( checkecharrange ( curchr ) ) 
    goto lab101 ;
    else {
	
      bchar = 256 ;
      curr = bchar ;
      ligstack = -1073741823L ;
      if ( ligaturepresent ) 
      {
	mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) ;
	if ( lfthit ) 
	{
	  mem [mainp ].hh.b1 = 2 ;
	  lfthit = false ;
	} 
	if ( rthit ) {
	    
	  if ( ligstack == -1073741823L ) 
	  {
	    incr ( mem [mainp ].hh.b1 ) ;
	    rthit = false ;
	  } 
	} 
	mem [curq ].hh .v.RH = mainp ;
	curlist .tailfield = mainp ;
	ligaturepresent = false ;
      } 
      if ( inskp == true ) 
      {
	cx = curl ;
	{
	  kp = getkinsokupos ( cx , 1 ) ;
	  if ( kp != 1000 ) 
	  {
	    if ( eqtb [27642 + kp ].hh.b0 == 1 ) 
	    {
	      if ( ! ( curq >= himemmin ) && ( mem [curq ].hh.b0 == 14 ) ) 
	      mem [curq + 1 ].cint = mem [curq + 1 ].cint + eqtb [30055 + 
	      kp ].cint ;
	      else {
		  
		mainp = mem [curq ].hh .v.RH ;
		mem [curq ].hh .v.RH = newpenalty ( eqtb [30055 + kp ]
		.cint ) ;
		mem [mem [curq ].hh .v.RH ].hh.b1 = 2 ;
		mem [mem [curq ].hh .v.RH ].hh .v.RH = mainp ;
	      } 
	    } 
	    else if ( eqtb [27642 + kp ].hh.b0 == 2 ) 
	    {
	      {
		mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [
		30055 + kp ].cint ) ;
		curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	      } 
	      mem [curlist .tailfield ].hh.b1 = 2 ;
	    } 
	  } 
	} 
      } 
      inskp = false ;
      goto lab130 ;
    } 
  } 
  if ( curcmd == 74 ) 
  {
    bchar = 256 ;
    curr = bchar ;
    ligstack = -1073741823L ;
    if ( ligaturepresent ) 
    {
      mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) ;
      if ( lfthit ) 
      {
	mem [mainp ].hh.b1 = 2 ;
	lfthit = false ;
      } 
      if ( rthit ) {
	  
	if ( ligstack == -1073741823L ) 
	{
	  incr ( mem [mainp ].hh.b1 ) ;
	  rthit = false ;
	} 
      } 
      mem [curq ].hh .v.RH = mainp ;
      curlist .tailfield = mainp ;
      ligaturepresent = false ;
    } 
    if ( inskp == true ) 
    {
      cx = curl ;
      {
	kp = getkinsokupos ( cx , 1 ) ;
	if ( kp != 1000 ) 
	{
	  if ( eqtb [27642 + kp ].hh.b0 == 1 ) 
	  {
	    if ( ! ( curq >= himemmin ) && ( mem [curq ].hh.b0 == 14 ) ) 
	    mem [curq + 1 ].cint = mem [curq + 1 ].cint + eqtb [30055 + 
	    kp ].cint ;
	    else {
		
	      mainp = mem [curq ].hh .v.RH ;
	      mem [curq ].hh .v.RH = newpenalty ( eqtb [30055 + kp ].cint 
	      ) ;
	      mem [mem [curq ].hh .v.RH ].hh.b1 = 2 ;
	      mem [mem [curq ].hh .v.RH ].hh .v.RH = mainp ;
	    } 
	  } 
	  else if ( eqtb [27642 + kp ].hh.b0 == 2 ) 
	  {
	    {
	      mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [30055 
	      + kp ].cint ) ;
	      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	    } 
	    mem [curlist .tailfield ].hh.b1 = 2 ;
	  } 
	} 
      } 
    } 
    inskp = false ;
    goto lab130 ;
  } 
  xtoken () ;
  if ( curcmd == 11 ) 
  goto lab101 ;
  if ( ( curcmd >= 16 ) && ( curcmd <= 19 ) ) 
  {
    bchar = 256 ;
    curr = bchar ;
    ligstack = -1073741823L ;
    if ( ligaturepresent ) 
    {
      mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) ;
      if ( lfthit ) 
      {
	mem [mainp ].hh.b1 = 2 ;
	lfthit = false ;
      } 
      if ( rthit ) {
	  
	if ( ligstack == -1073741823L ) 
	{
	  incr ( mem [mainp ].hh.b1 ) ;
	  rthit = false ;
	} 
      } 
      mem [curq ].hh .v.RH = mainp ;
      curlist .tailfield = mainp ;
      ligaturepresent = false ;
    } 
    if ( inskp == true ) 
    {
      cx = curl ;
      {
	kp = getkinsokupos ( cx , 1 ) ;
	if ( kp != 1000 ) 
	{
	  if ( eqtb [27642 + kp ].hh.b0 == 1 ) 
	  {
	    if ( ! ( curq >= himemmin ) && ( mem [curq ].hh.b0 == 14 ) ) 
	    mem [curq + 1 ].cint = mem [curq + 1 ].cint + eqtb [30055 + 
	    kp ].cint ;
	    else {
		
	      mainp = mem [curq ].hh .v.RH ;
	      mem [curq ].hh .v.RH = newpenalty ( eqtb [30055 + kp ].cint 
	      ) ;
	      mem [mem [curq ].hh .v.RH ].hh.b1 = 2 ;
	      mem [mem [curq ].hh .v.RH ].hh .v.RH = mainp ;
	    } 
	  } 
	  else if ( eqtb [27642 + kp ].hh.b0 == 2 ) 
	  {
	    {
	      mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [30055 
	      + kp ].cint ) ;
	      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	    } 
	    mem [curlist .tailfield ].hh.b1 = 2 ;
	  } 
	} 
      } 
    } 
    inskp = false ;
    goto lab130 ;
  } 
  if ( curcmd == 12 ) 
  goto lab101 ;
  if ( curcmd == 73 ) 
  {
    if ( checkecharrange ( curchr ) ) 
    goto lab101 ;
    else {
	
      bchar = 256 ;
      curr = bchar ;
      ligstack = -1073741823L ;
      if ( ligaturepresent ) 
      {
	mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) ;
	if ( lfthit ) 
	{
	  mem [mainp ].hh.b1 = 2 ;
	  lfthit = false ;
	} 
	if ( rthit ) {
	    
	  if ( ligstack == -1073741823L ) 
	  {
	    incr ( mem [mainp ].hh.b1 ) ;
	    rthit = false ;
	  } 
	} 
	mem [curq ].hh .v.RH = mainp ;
	curlist .tailfield = mainp ;
	ligaturepresent = false ;
      } 
      if ( inskp == true ) 
      {
	cx = curl ;
	{
	  kp = getkinsokupos ( cx , 1 ) ;
	  if ( kp != 1000 ) 
	  {
	    if ( eqtb [27642 + kp ].hh.b0 == 1 ) 
	    {
	      if ( ! ( curq >= himemmin ) && ( mem [curq ].hh.b0 == 14 ) ) 
	      mem [curq + 1 ].cint = mem [curq + 1 ].cint + eqtb [30055 + 
	      kp ].cint ;
	      else {
		  
		mainp = mem [curq ].hh .v.RH ;
		mem [curq ].hh .v.RH = newpenalty ( eqtb [30055 + kp ]
		.cint ) ;
		mem [mem [curq ].hh .v.RH ].hh.b1 = 2 ;
		mem [mem [curq ].hh .v.RH ].hh .v.RH = mainp ;
	      } 
	    } 
	    else if ( eqtb [27642 + kp ].hh.b0 == 2 ) 
	    {
	      {
		mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [
		30055 + kp ].cint ) ;
		curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	      } 
	      mem [curlist .tailfield ].hh.b1 = 2 ;
	    } 
	  } 
	} 
      } 
      inskp = false ;
      goto lab130 ;
    } 
  } 
  if ( curcmd == 20 ) 
  {
    scancharnum () ;
    curchr = curval ;
    if ( checkecharrange ( curchr ) ) 
    goto lab101 ;
    else {
	
      bchar = 256 ;
      curr = bchar ;
      ligstack = -1073741823L ;
      if ( ligaturepresent ) 
      {
	mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) ;
	if ( lfthit ) 
	{
	  mem [mainp ].hh.b1 = 2 ;
	  lfthit = false ;
	} 
	if ( rthit ) {
	    
	  if ( ligstack == -1073741823L ) 
	  {
	    incr ( mem [mainp ].hh.b1 ) ;
	    rthit = false ;
	  } 
	} 
	mem [curq ].hh .v.RH = mainp ;
	curlist .tailfield = mainp ;
	ligaturepresent = false ;
      } 
      if ( inskp == true ) 
      {
	cx = curl ;
	{
	  kp = getkinsokupos ( cx , 1 ) ;
	  if ( kp != 1000 ) 
	  {
	    if ( eqtb [27642 + kp ].hh.b0 == 1 ) 
	    {
	      if ( ! ( curq >= himemmin ) && ( mem [curq ].hh.b0 == 14 ) ) 
	      mem [curq + 1 ].cint = mem [curq + 1 ].cint + eqtb [30055 + 
	      kp ].cint ;
	      else {
		  
		mainp = mem [curq ].hh .v.RH ;
		mem [curq ].hh .v.RH = newpenalty ( eqtb [30055 + kp ]
		.cint ) ;
		mem [mem [curq ].hh .v.RH ].hh.b1 = 2 ;
		mem [mem [curq ].hh .v.RH ].hh .v.RH = mainp ;
	      } 
	    } 
	    else if ( eqtb [27642 + kp ].hh.b0 == 2 ) 
	    {
	      {
		mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [
		30055 + kp ].cint ) ;
		curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	      } 
	      mem [curlist .tailfield ].hh.b1 = 2 ;
	    } 
	  } 
	} 
      } 
      inskp = false ;
      goto lab130 ;
    } 
  } 
  if ( curcmd == 54 ) 
  {
    scancharnum () ;
    curchr = curval ;
    {
      bchar = 256 ;
      curr = bchar ;
      ligstack = -1073741823L ;
      if ( ligaturepresent ) 
      {
	mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) ;
	if ( lfthit ) 
	{
	  mem [mainp ].hh.b1 = 2 ;
	  lfthit = false ;
	} 
	if ( rthit ) {
	    
	  if ( ligstack == -1073741823L ) 
	  {
	    incr ( mem [mainp ].hh.b1 ) ;
	    rthit = false ;
	  } 
	} 
	mem [curq ].hh .v.RH = mainp ;
	curlist .tailfield = mainp ;
	ligaturepresent = false ;
      } 
      if ( inskp == true ) 
      {
	cx = curl ;
	{
	  kp = getkinsokupos ( cx , 1 ) ;
	  if ( kp != 1000 ) 
	  {
	    if ( eqtb [27642 + kp ].hh.b0 == 1 ) 
	    {
	      if ( ! ( curq >= himemmin ) && ( mem [curq ].hh.b0 == 14 ) ) 
	      mem [curq + 1 ].cint = mem [curq + 1 ].cint + eqtb [30055 + 
	      kp ].cint ;
	      else {
		  
		mainp = mem [curq ].hh .v.RH ;
		mem [curq ].hh .v.RH = newpenalty ( eqtb [30055 + kp ]
		.cint ) ;
		mem [mem [curq ].hh .v.RH ].hh.b1 = 2 ;
		mem [mem [curq ].hh .v.RH ].hh .v.RH = mainp ;
	      } 
	    } 
	    else if ( eqtb [27642 + kp ].hh.b0 == 2 ) 
	    {
	      {
		mem [curlist .tailfield ].hh .v.RH = newpenalty ( eqtb [
		30055 + kp ].cint ) ;
		curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	      } 
	      mem [curlist .tailfield ].hh.b1 = 2 ;
	    } 
	  } 
	} 
      } 
      inskp = false ;
      goto lab130 ;
    } 
  } 
  if ( curcmd == 78 ) 
  {
    inhibitglueflag = true ;
    goto lab100 ;
  } 
  if ( curcmd == 70 ) 
  bchar = 256 ;
  curr = bchar ;
  ligstack = -1073741823L ;
  goto lab110 ;
  lab101: mains = eqtb [28420 + curchr ].hh .v.RH ;
  if ( mains == 1000 ) 
  curlist .auxfield .hh .v.LH = 1000 ;
  else if ( mains < 1000 ) 
  {
    if ( mains > 0 ) 
    curlist .auxfield .hh .v.LH = mains ;
  } 
  else if ( curlist .auxfield .hh .v.LH < 1000 ) 
  curlist .auxfield .hh .v.LH = 1000 ;
  else curlist .auxfield .hh .v.LH = mains ;
  inhibitglueflag = false ;
  {
    ligstack = avail ;
    if ( ligstack == -1073741823L ) 
    ligstack = getavail () ;
    else {
	
      avail = mem [ligstack ].hh .v.RH ;
      mem [ligstack ].hh .v.RH = -1073741823L ;
	;
#ifdef STAT
      incr ( dynused ) ;
#endif /* STAT */
    } 
  } 
  mem [ligstack ].hh.b0 = mainf ;
  curr = curchr ;
  mem [ligstack ].hh.b1 = curr ;
  if ( curr == falsebchar ) 
  curr = 256 ;
  lab110: if ( ( ( maini .b2 ) % 4 ) != 1 ) 
  goto lab80 ;
  if ( curr == 256 ) 
  goto lab80 ;
  maink = ligkernbase [mainf ]+ maini .b3 ;
  mainj = fontinfo [maink ].qqqq ;
  if ( mainj .b0 <= 128 ) 
  goto lab112 ;
  maink = ligkernbase [mainf ]+ 256 * mainj .b2 + mainj .b3 + 32768L - 256 * 
  ( 128 ) ;
  lab111: mainj = fontinfo [maink ].qqqq ;
  lab112: if ( mainj .b1 == curr ) {
      
    if ( mainj .b0 <= 128 ) 
    {
      if ( mainj .b2 >= 128 ) 
      {
	if ( curl < 256 ) 
	{
	  if ( mem [curq ].hh .v.RH > -1073741823L ) {
	      
	    if ( mem [curlist .tailfield ].hh.b1 == hyphenchar [mainf ]) 
	    insdisc = true ;
	  } 
	  if ( ligaturepresent ) 
	  {
	    mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) ;
	    if ( lfthit ) 
	    {
	      mem [mainp ].hh.b1 = 2 ;
	      lfthit = false ;
	    } 
	    if ( rthit ) {
		
	      if ( ligstack == -1073741823L ) 
	      {
		incr ( mem [mainp ].hh.b1 ) ;
		rthit = false ;
	      } 
	    } 
	    mem [curq ].hh .v.RH = mainp ;
	    curlist .tailfield = mainp ;
	    ligaturepresent = false ;
	  } 
	  if ( insdisc ) 
	  {
	    insdisc = false ;
	    if ( curlist .modefield > 0 ) 
	    {
	      mem [curlist .tailfield ].hh .v.RH = newdisc () ;
	      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	    } 
	  } 
	} 
	{
	  mem [curlist .tailfield ].hh .v.RH = newkern ( fontinfo [kernbase 
	  [mainf ]+ 256 * mainj .b2 + mainj .b3 ].cint ) ;
	  curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	} 
	goto lab90 ;
      } 
      if ( curl == 256 ) 
      lfthit = true ;
      else if ( ligstack == -1073741823L ) 
      rthit = true ;
      {
	if ( interrupt != 0 ) 
	pauseforinstructions () ;
      } 
      switch ( mainj .b2 ) 
      {case 1 : 
      case 5 : 
	{
	  curl = mainj .b3 ;
	  maini = fontinfo [charbase [mainf ]+ effectivechar ( true , mainf 
	  , curl ) ].qqqq ;
	  ligaturepresent = true ;
	} 
	break ;
      case 2 : 
      case 6 : 
	{
	  curr = mainj .b3 ;
	  if ( ligstack == -1073741823L ) 
	  {
	    ligstack = newligitem ( curr ) ;
	    bchar = 256 ;
	  } 
	  else if ( ( ligstack >= himemmin ) ) 
	  {
	    mainp = ligstack ;
	    ligstack = newligitem ( curr ) ;
	    mem [ligstack + 1 ].hh .v.RH = mainp ;
	  } 
	  else mem [ligstack ].hh.b1 = curr ;
	} 
	break ;
      case 3 : 
	{
	  curr = mainj .b3 ;
	  mainp = ligstack ;
	  ligstack = newligitem ( curr ) ;
	  mem [ligstack ].hh .v.RH = mainp ;
	} 
	break ;
      case 7 : 
      case 11 : 
	{
	  if ( curl < 256 ) 
	  {
	    if ( mem [curq ].hh .v.RH > -1073741823L ) {
		
	      if ( mem [curlist .tailfield ].hh.b1 == hyphenchar [mainf ]) 
	      insdisc = true ;
	    } 
	    if ( ligaturepresent ) 
	    {
	      mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) ;
	      if ( lfthit ) 
	      {
		mem [mainp ].hh.b1 = 2 ;
		lfthit = false ;
	      } 
	      if ( false ) {
		  
		if ( ligstack == -1073741823L ) 
		{
		  incr ( mem [mainp ].hh.b1 ) ;
		  rthit = false ;
		} 
	      } 
	      mem [curq ].hh .v.RH = mainp ;
	      curlist .tailfield = mainp ;
	      ligaturepresent = false ;
	    } 
	    if ( insdisc ) 
	    {
	      insdisc = false ;
	      if ( curlist .modefield > 0 ) 
	      {
		mem [curlist .tailfield ].hh .v.RH = newdisc () ;
		curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	      } 
	    } 
	  } 
	  curq = curlist .tailfield ;
	  curl = mainj .b3 ;
	  maini = fontinfo [charbase [mainf ]+ effectivechar ( true , mainf 
	  , curl ) ].qqqq ;
	  ligaturepresent = true ;
	} 
	break ;
	default: 
	{
	  curl = mainj .b3 ;
	  ligaturepresent = true ;
	  if ( ligstack == -1073741823L ) 
	  goto lab80 ;
	  else goto lab91 ;
	} 
	break ;
      } 
      if ( mainj .b2 > 4 ) {
	  
	if ( mainj .b2 != 7 ) 
	goto lab80 ;
      } 
      if ( curl < 256 ) 
      goto lab110 ;
      maink = bcharlabel [mainf ];
      goto lab111 ;
    } 
  } 
  if ( mainj .b0 == 0 ) 
  incr ( maink ) ;
  else {
      
    if ( mainj .b0 >= 128 ) 
    goto lab80 ;
    maink = maink + mainj .b0 + 1 ;
  } 
  goto lab111 ;
  lab95: mainp = mem [ligstack + 1 ].hh .v.RH ;
  if ( mainp > -1073741823L ) 
  {
    mem [curlist .tailfield ].hh .v.RH = mainp ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  tempptr = ligstack ;
  ligstack = mem [tempptr ].hh .v.RH ;
  freenode ( tempptr , 2 ) ;
  maini = fontinfo [charbase [mainf ]+ effectivechar ( true , mainf , curl 
  ) ].qqqq ;
  ligaturepresent = true ;
  if ( ligstack == -1073741823L ) {
      
    if ( mainp > -1073741823L ) 
    goto lab100 ;
    else curr = bchar ;
  } 
  else curr = mem [ligstack ].hh.b1 ;
  goto lab110 ;
  lab120: if ( eqtb [24540 ].hh .v.RH == membot ) 
  {
    {
      mainp = fontglue [eqtb [25588 ].hh .v.RH ];
      if ( mainp == -1073741823L ) 
      {
	mainp = newspec ( membot ) ;
	maink = parambase [eqtb [25588 ].hh .v.RH ]+ 2 ;
	mem [mainp + 1 ].cint = fontinfo [maink ].cint ;
	mem [mainp + 2 ].cint = fontinfo [maink + 1 ].cint ;
	mem [mainp + 3 ].cint = fontinfo [maink + 2 ].cint ;
	fontglue [eqtb [25588 ].hh .v.RH ]= mainp ;
      } 
    } 
    tempptr = newglue ( mainp ) ;
  } 
  else tempptr = newparamglue ( 12 ) ;
  if ( ! ( curlist .tailfield >= himemmin ) && ( mem [curlist .tailfield ]
  .hh.b0 == 5 ) ) 
  {
    mem [curlist .pnodefield ].hh .v.RH = tempptr ;
    mem [tempptr ].hh .v.RH = curlist .tailfield ;
    curlist .pnodefield = tempptr ;
  } 
  else {
      
    mem [curlist .tailfield ].hh .v.RH = tempptr ;
    curlist .tailfield = tempptr ;
  } 
  goto lab60 ;
} 
void 
giveerrhelp ( void ) 
{
  giveerrhelp_regmem 
  tokenshow ( eqtb [25070 ].hh .v.RH ) ;
} 
boolean 
openfmtfile ( void ) 
{
  /* 40 10 */ register boolean Result; openfmtfile_regmem 
  integer j  ;
  j = curinput .locfield ;
  if ( buffer [curinput .locfield ]== 38 ) 
  {
    incr ( curinput .locfield ) ;
    j = curinput .locfield ;
    buffer [last ]= 32 ;
    while ( buffer [j ]!= 32 ) incr ( j ) ;
    packbufferedname ( 0 , curinput .locfield , j - 1 ) ;
    if ( wopenin ( fmtfile ) ) 
    goto lab40 ;
    Fputs ( stdout ,  "Sorry, I can't find the format `" ) ;
    fputs ( stringcast ( nameoffile + 1 ) , stdout ) ;
    Fputs ( stdout ,  "'; will try `" ) ;
    fputs ( TEXformatdefault + 1 , stdout ) ;
    fprintf ( stdout , "%s\n",  "'." ) ;
    fflush ( stdout ) ;
  } 
  packbufferedname ( formatdefaultlength - 4 , 1 , 0 ) ;
  if ( ! wopenin ( fmtfile ) ) 
  {
    ;
    Fputs ( stdout ,  "I can't find the format file `" ) ;
    fputs ( TEXformatdefault + 1 , stdout ) ;
    fprintf ( stdout , "%s\n",  "'!" ) ;
    Result = false ;
    return Result ;
  } 
  lab40: curinput .locfield = j ;
  Result = true ;
  return Result ;
} 
void 
closefilesandterminate ( void ) 
{
  closefilesandterminate_regmem 
  integer k  ;
  {register integer for_end; k = 0 ;for_end = 15 ; if ( k <= for_end) do 
    if ( writeopen [k ]) 
    aclose ( writefile [k ]) ;
  while ( k++ < for_end ) ;} 
	;
#ifdef STAT
  if ( eqtb [29219 ].cint > 0 ) {
      
    if ( logopened ) 
    {
      { putc ( ' ' ,  logfile );  putc ( '\n',  logfile ); }
      fprintf ( logfile , "%s%s\n",  "Here is how much of TeX's memory" , " you used:" ) 
      ;
      fprintf ( logfile , "%c%ld%s",  ' ' , (long)strptr - initstrptr , " string" ) ;
      if ( strptr != initstrptr + 1 ) 
      putc ( 's' ,  logfile );
      fprintf ( logfile , "%s%ld\n",  " out of " , (long)maxstrings - initstrptr ) ;
      fprintf ( logfile , "%c%ld%s%ld\n",  ' ' , (long)poolptr - initpoolptr ,       " string characters out of " , (long)poolsize - initpoolptr ) ;
      fprintf ( logfile , "%c%ld%s%ld\n",  ' ' , (long)lomemmax - memmin + memend - himemmin + 2 ,       " words of memory out of " , (long)memend + 1 - memmin ) ;
      fprintf ( logfile , "%c%ld%s%ld%c%ld\n",  ' ' , (long)cscount ,       " multiletter control sequences out of " , (long)15000 , '+' , (long)hashextra ) ;
      fprintf ( logfile , "%c%ld%s%ld%s",  ' ' , (long)fmemptr , " words of font info for " , (long)fontptr -       0 , " font" ) ;
      if ( fontptr != 1 ) 
      putc ( 's' ,  logfile );
      fprintf ( logfile , "%s%ld%s%ld\n",  ", out of " , (long)fontmemsize , " for " , (long)fontmax - 0 ) 
      ;
      fprintf ( logfile , "%c%ld%s",  ' ' , (long)hyphcount , " hyphenation exception" ) ;
      if ( hyphcount != 1 ) 
      putc ( 's' ,  logfile );
      fprintf ( logfile , "%s%ld\n",  " out of " , (long)hyphsize ) ;
      fprintf ( logfile , "%c%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%s%ld%c\n",  ' ' , (long)maxinstack , "i," , (long)maxneststack , "n," ,       (long)maxparamstack , "p," , (long)maxbufstack + 1 , "b," , (long)maxsavestack + 6 ,       "s stack positions out of " , (long)stacksize , "i," , (long)nestsize , "n," ,       (long)paramsize , "p," , (long)bufsize , "b," , (long)savesize , 's' ) ;
    } 
  } 
#endif /* STAT */
  while ( curs > -1 ) {
      
    if ( curs > 0 ) 
    {
      dvibuf [dviptr ]= 142 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    else {
	
      {
	dvibuf [dviptr ]= 140 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      incr ( totalpages ) ;
    } 
    decr ( curs ) ;
  } 
  if ( totalpages == 0 ) 
  printnl ( 936 ) ;
  else if ( curs != -2 ) 
  {
    {
      dvibuf [dviptr ]= 248 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    dvifour ( lastbop ) ;
    lastbop = dvioffset + dviptr - 5 ;
    dvifour ( 25400000L ) ;
    dvifour ( 473628672L ) ;
    preparemag () ;
    dvifour ( eqtb [29205 ].cint ) ;
    dvifour ( maxv ) ;
    dvifour ( maxh ) ;
    {
      dvibuf [dviptr ]= maxpush / 256 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    {
      dvibuf [dviptr ]= maxpush % 256 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    {
      dvibuf [dviptr ]= ( totalpages / 256 ) % 256 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    {
      dvibuf [dviptr ]= totalpages % 256 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    while ( fontptr > 0 ) {
	
      if ( fontused [fontptr ]) 
      dvifontdef ( fontptr ) ;
      decr ( fontptr ) ;
    } 
    {
      dvibuf [dviptr ]= 249 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    dvifour ( lastbop ) ;
    if ( dirused ) 
    {
      dvibuf [dviptr ]= 3 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    else {
	
      dvibuf [dviptr ]= 2 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
	;
#ifdef IPC
    k = 7 - ( ( 3 + dvioffset + dviptr ) % 4 ) ;
#endif /* IPC */
	;
#ifndef IPC
    k = 4 + ( ( dvibufsize - dviptr ) % 4 ) ;
#endif /* not IPC */
    while ( k > 0 ) {
	
      {
	dvibuf [dviptr ]= 223 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      decr ( k ) ;
    } 
    if ( dvilimit == halfbuf ) 
    writedvi ( halfbuf , dvibufsize - 1 ) ;
    if ( dviptr > ( 2147483647L - dvioffset ) ) 
    {
      curs = -2 ;
      fatalerror ( 925 ) ;
    } 
    if ( dviptr > 0 ) 
    writedvi ( 0 , dviptr - 1 ) ;
    printnl ( 937 ) ;
    printfilename ( 0 , outputfilename , 0 ) ;
    print ( 286 ) ;
    printint ( totalpages ) ;
    if ( totalpages != 1 ) 
    print ( 938 ) ;
    else print ( 939 ) ;
    print ( 381 ) ;
    printint ( dvioffset + dviptr ) ;
    print ( 940 ) ;
    bclose ( dvifile ) ;
  } 
  synctexterminate ( logopened ) ;
  if ( logopened ) 
  {
    putc ('\n',  logfile );
    aclose ( logfile ) ;
    selector = selector - 2 ;
    if ( selector == 17 ) 
    {
      printnl ( 1418 ) ;
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
  /* 888 10 */ debughelp_regmem 
  integer k, l, m, n  ;
  while ( true ) {
      
    ;
    printnl ( 1427 ) ;
    fflush ( stdout ) ;
    read ( stdin , m ) ;
    if ( m < 0 ) 
    return ;
    else if ( m == 0 ) 
    dumpcore () ;
    else {
	
      read ( stdin , n ) ;
      switch ( m ) 
      {case 1 : 
	printword ( mem [n ]) ;
	break ;
      case 2 : 
	printint ( mem [n ].hh .v.LH ) ;
	break ;
      case 3 : 
	printint ( mem [n ].hh .v.RH ) ;
	break ;
      case 4 : 
	printword ( eqtb [n ]) ;
	break ;
      case 5 : 
	{
	  printscaled ( fontinfo [n ].cint ) ;
	  printchar ( 32 ) ;
	  printint ( fontinfo [n ].qqqq .b0 ) ;
	  printchar ( 58 ) ;
	  printint ( fontinfo [n ].qqqq .b1 ) ;
	  printchar ( 58 ) ;
	  printint ( fontinfo [n ].qqqq .b2 ) ;
	  printchar ( 58 ) ;
	  printint ( fontinfo [n ].qqqq .b3 ) ;
	} 
	break ;
      case 6 : 
	printword ( savestack [n ]) ;
	break ;
      case 7 : 
	showbox ( n ) ;
	break ;
      case 8 : 
	{
	  breadthmax = 10000 ;
	  depththreshold = poolsize - poolptr - 10 ;
	  shownodelist ( n ) ;
	} 
	break ;
      case 9 : 
	showtokenlist ( n , -1073741823L , 1000 ) ;
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
	  printcmdchr ( n , l ) ;
	} 
	break ;
      case 14 : 
	{register integer for_end; k = 0 ;for_end = n ; if ( k <= for_end) 
	do 
	  print ( buffer [k ]) ;
	while ( k++ < for_end ) ;} 
	break ;
      case 15 : 
	{
	  fontinshortdisplay = 0 ;
	  shortdisplay ( n ) ;
	} 
	break ;
      case 16 : 
	panicking = ! panicking ;
	break ;
	default: 
	print ( 63 ) ;
	break ;
      } 
    } 
  } 
} 
#endif /* TEXMF_DEBUG */
strnumber 
getnullstr ( void ) 
{
  register strnumber Result; getnullstr_regmem 
  Result = 344 ;
  return Result ;
} 
