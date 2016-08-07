#define EXTERN extern
#include "alephd.h"

void 
println ( void ) 
{
  println_regmem 
  switch ( selector ) 
  {case 19 : 
    {
      putc ('\n',  stdout );
      putc ('\n',  logfile );
      termoffset = 0 ;
      fileoffset = 0 ;
    } 
    break ;
  case 18 : 
    {
      putc ('\n',  logfile );
      fileoffset = 0 ;
    } 
    break ;
  case 17 : 
    {
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
} 
void 
zprintchar ( ASCIIcode s ) 
{
  /* 10 */ printchar_regmem 
  if ( s == neweqtbint ( 1049457L ) ) {
      
    if ( selector < 20 ) 
    {
      println () ;
      return ;
    } 
  } 
  switch ( selector ) 
  {case 19 : 
    {
      switch ( termoutmode ) 
      {case 0 : 
	putc ( Xchr (s ),  stdout );
	break ;
      case 1 : 
      case 2 : 
	putc ( Xchr (s ),  stdout );
	break ;
      case 3 : 
	{
	  putc ( Xchr (s / 256 ),  stdout );
	  putc ( Xchr (s % 256 ),  stdout );
	} 
	break ;
      case 4 : 
	{
	  putc ( Xchr (s % 256 ),  stdout );
	  putc ( Xchr (s / 256 ),  stdout );
	} 
	break ;
      } 
      switch ( termoutmode ) 
      {case 0 : 
	putc ( Xchr (s ),  logfile );
	break ;
      case 1 : 
      case 2 : 
	putc ( Xchr (s ),  logfile );
	break ;
      case 3 : 
	{
	  putc ( Xchr (s / 256 ),  logfile );
	  putc ( Xchr (s % 256 ),  logfile );
	} 
	break ;
      case 4 : 
	{
	  putc ( Xchr (s % 256 ),  logfile );
	  putc ( Xchr (s / 256 ),  logfile );
	} 
	break ;
      } 
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
  case 18 : 
    {
      switch ( termoutmode ) 
      {case 0 : 
	putc ( Xchr (s ),  logfile );
	break ;
      case 1 : 
      case 2 : 
	putc ( Xchr (s ),  logfile );
	break ;
      case 3 : 
	{
	  putc ( Xchr (s / 256 ),  logfile );
	  putc ( Xchr (s % 256 ),  logfile );
	} 
	break ;
      case 4 : 
	{
	  putc ( Xchr (s % 256 ),  logfile );
	  putc ( Xchr (s / 256 ),  logfile );
	} 
	break ;
      } 
      incr ( fileoffset ) ;
      if ( fileoffset == maxprintline ) 
      println () ;
    } 
    break ;
  case 17 : 
    {
      switch ( termoutmode ) 
      {case 0 : 
	putc ( Xchr (s ),  stdout );
	break ;
      case 1 : 
      case 2 : 
	putc ( Xchr (s ),  stdout );
	break ;
      case 3 : 
	{
	  putc ( Xchr (s / 256 ),  stdout );
	  putc ( Xchr (s % 256 ),  stdout );
	} 
	break ;
      case 4 : 
	{
	  putc ( Xchr (s % 256 ),  stdout );
	  putc ( Xchr (s / 256 ),  stdout );
	} 
	break ;
      } 
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
    trickbuf [tally % errorline ]= s ;
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
    switch ( writefilemode [selector ]) 
    {case 0 : 
      putc ( Xchr (s ),  writefile [selector ]);
      break ;
    case 1 : 
    case 2 : 
      putc ( Xchr (s ),  writefile [selector ]);
      break ;
    case 3 : 
      {
	putc ( Xchr (s / 256 ),  writefile [selector ]);
	putc ( Xchr (s % 256 ),  writefile [selector ]);
      } 
      break ;
    case 4 : 
      {
	putc ( Xchr (s % 256 ),  writefile [selector ]);
	putc ( Xchr (s / 256 ),  writefile [selector ]);
      } 
      break ;
    } 
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
  integer l  ;
  if ( s >= strptr ) 
  s = 65545L ;
  else if ( s < 65535L ) {
      
    if ( s < 0 ) 
    s = 65545L ;
    else {
	
      if ( selector > 20 ) 
      {
	printchar ( s ) ;
	return ;
      } 
      if ( ( s == neweqtbint ( 1049457L ) ) ) {
	  
	if ( selector < 20 ) 
	{
	  println () ;
	  return ;
	} 
      } 
      nl = neweqtbint ( 1049457L ) ;
      setneweqtbint ( 1049457L , -1 ) ;
      if ( s < 32 ) 
      {
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	printchar ( s + 64 ) ;
      } 
      else if ( s < 127 ) 
      printchar ( s ) ;
      else if ( s == 127 ) 
      {
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	printchar ( s - 64 ) ;
      } 
      else if ( s < 256 ) 
      {
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	l = ( s % 256 ) / 16 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
	l = s % 16 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
      } 
      else {
	  
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	l = s / 4096 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
	l = ( s % 4096 ) / 256 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
	l = ( s % 256 ) / 16 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
	l = s % 16 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
      } 
      setneweqtbint ( 1049457L , nl ) ;
      return ;
    } 
  } 
  j = strstartar [s - 65536L ];
  while ( j < strstartar [s - 65535L ]) {
      
    printchar ( strpool [j ]) ;
    incr ( j ) ;
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
zomegaprint ( strnumber s ) 
{
  omegaprint_regmem 
  strnumber news  ;
  integer ommode, omtranslation  ;
  integer j  ;
  ommode = 0 ;
  omtranslation = 0 ;
  switch ( selector ) 
  {case 19 : 
  case 18 : 
  case 17 : 
    {
      ommode = termoutmode ;
      if ( ommode != 0 ) 
      omtranslation = termouttranslation ;
    } 
    break ;
  case 16 : 
  case 20 : 
  case 21 : 
    ;
    break ;
    default: 
    {
      ommode = writefilemode [selector ];
      if ( ommode != 0 ) 
      omtranslation = writefiletranslation [selector ];
    } 
    break ;
  } 
  if ( ( ommode == 0 ) || ( ( ommode == 1 ) && ( omtranslation == 0 ) ) ) 
  {
    j = strstartar [s - 65536L ];
    while ( j < strstartar [s - 65535L ]) {
	
      news = strpool [j ];
      if ( news < 32 ) 
      {
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	printchar ( news + 64 ) ;
      } 
      else if ( news < 127 ) 
      printchar ( news ) ;
      else if ( news == 127 ) 
      {
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	printchar ( news - 64 ) ;
      } 
      else if ( news < 256 ) 
      {
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	l = ( news % 256 ) / 16 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
	l = news % 16 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
      } 
      else {
	  
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	printchar ( 94 ) ;
	l = news / 4096 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
	l = ( news % 4096 ) / 256 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
	l = ( news % 256 ) / 16 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
	l = news % 16 ;
	if ( l < 10 ) 
	printchar ( l + 48 ) ;
	else printchar ( l + 87 ) ;
      } 
      incr ( j ) ;
    } 
  } 
  else {
      
    if ( omtranslation == 0 ) 
    {
      j = strstartar [s - 65536L ];
      otpcounter = 1 ;
      while ( j < strstartar [s - 65535L ]) {
	  
	otpoutputbuf [otpcounter ]= strpool [j ];
	incr ( otpcounter ) ;
	incr ( j ) ;
      } 
      otpoutputend = otpcounter ;
    } 
    else {
	
      otpinputstart = 0 ;
      otpinputlast = 0 ;
      otpstackused = 0 ;
      otpstacklast = 0 ;
      otpstacknew = 0 ;
      otpoutputend = 0 ;
      otppc = 0 ;
      otpfinished = false ;
      otpcalcptr = 0 ;
      otpcalcs [otpcalcptr ]= 0 ;
      otpstateptr = 0 ;
      otpstates [otpstateptr ]= 0 ;
      otpinputocp = omtranslation ;
      j = strstartar [s - 65536L ];
      otpcounter = 1 ;
      while ( j < strstartar [s - 65535L ]) {
	  
	otpinputbuf [otpcounter ]= strpool [j ];
	incr ( otpcounter ) ;
	incr ( j ) ;
      } 
      otpinputend = otpcounter ;
      while ( ! otpfinished ) {
	  
	{
	  if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp ][ 
	  10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	  {
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 65548L ) ;
	      print ( 66821L ) ;
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
	  otpinstruction = ocptables [otpinputocp ][ ocptables [otpinputocp 
	  ][ ocptables [otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 ]
	  + otppc ];
	  otpinstr = otpinstruction / 16777216L ;
	  otparg = otpinstruction % 16777216L ;
	} 
	switch ( otpinstr ) 
	{case 1 : 
	  {
	    incr ( otpoutputend ) ;
	    if ( otpoutputend > ocpbufsize ) 
	    overflowocpbufsize () ;
	    otpoutputbuf [otpoutputend ]= otpcalcs [otpcalcptr ];
	    decr ( otpcalcptr ) ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 2 : 
	  {
	    incr ( otpoutputend ) ;
	    if ( otpoutputend > ocpbufsize ) 
	    overflowocpbufsize () ;
	    otpoutputbuf [otpoutputend ]= otparg ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 3 : 
	  {
	    {
	      if ( ( 1 > otparg ) || ( otparg > otpnoinputchars ) ) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66823L ) ;
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
	      if ( otparg > otpstacklast ) 
	      {
		otpcalculatedchar = otpinputbuf [otpinputstart + otparg - 
		otpstacklast ];
	      } 
	      else {
		  
		otpcalculatedchar = otpstackbuf [otparg ];
	      } 
	    } 
	    incr ( otpoutputend ) ;
	    if ( otpoutputend > ocpbufsize ) 
	    overflowocpbufsize () ;
	    otpoutputbuf [otpoutputend ]= otpcalculatedchar ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 4 : 
	  {
	    {
	      if ( ( 1 > otpnoinputchars - otparg ) || ( otpnoinputchars - 
	      otparg > otpnoinputchars ) ) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66823L ) ;
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
	      if ( otpnoinputchars - otparg > otpstacklast ) 
	      {
		otpcalculatedchar = otpinputbuf [otpinputstart + 
		otpnoinputchars - otparg - otpstacklast ];
	      } 
	      else {
		  
		otpcalculatedchar = otpstackbuf [otpnoinputchars - otparg ];
	      } 
	    } 
	    incr ( otpoutputend ) ;
	    if ( otpoutputend > ocpbufsize ) 
	    overflowocpbufsize () ;
	    otpoutputbuf [otpoutputend ]= otpcalculatedchar ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 5 : 
	  {
	    otpfirstarg = otparg + 1 ;
	    incr ( otppc ) ;
	    {
	      if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	      ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66821L ) ;
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
	      otpinstruction = ocptables [otpinputocp ][ ocptables [
	      otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	      otpstateptr ]* 2 ]+ otppc ];
	      otpinstr = otpinstruction / 16777216L ;
	      otparg = otpinstruction % 16777216L ;
	    } 
	    otpsecondarg = otpnoinputchars - otparg ;
	    {register integer for_end; otpcounter = otpfirstarg ;for_end = 
	    otpsecondarg ; if ( otpcounter <= for_end) do 
	      {
		{
		  if ( ( 1 > otpcounter ) || ( otpcounter > otpnoinputchars ) 
		  ) 
		  {
		    {
		      if ( interaction == 3 ) 
		      ;
		      if ( filelineerrorstylep ) 
		      printfileline () ;
		      else printnl ( 65548L ) ;
		      print ( 66823L ) ;
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
		  if ( otpcounter > otpstacklast ) 
		  {
		    otpcalculatedchar = otpinputbuf [otpinputstart + 
		    otpcounter - otpstacklast ];
		  } 
		  else {
		      
		    otpcalculatedchar = otpstackbuf [otpcounter ];
		  } 
		} 
		incr ( otpoutputend ) ;
		if ( otpoutputend > ocpbufsize ) 
		overflowocpbufsize () ;
		otpoutputbuf [otpoutputend ]= otpcalculatedchar ;
	      } 
	    while ( otpcounter++ < for_end ) ;} 
	    incr ( otppc ) ;
	  } 
	  break ;
	case 6 : 
	  {
	    incr ( otpstacknew ) ;
	    if ( otpstacknew >= ocpstacksize ) 
	    overflowocpstacksize () ;
	    otpstackbuf [otpstacknew ]= otpcalcs [otpcalcptr ];
	    decr ( otpcalcptr ) ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 7 : 
	  {
	    incr ( otpstacknew ) ;
	    if ( otpstacknew >= ocpstacksize ) 
	    overflowocpstacksize () ;
	    otpstackbuf [otpstacknew ]= otparg ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 8 : 
	  {
	    {
	      if ( ( 1 > otparg ) || ( otparg > otpnoinputchars ) ) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66823L ) ;
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
	      if ( otparg > otpstacklast ) 
	      {
		otpcalculatedchar = otpinputbuf [otpinputstart + otparg - 
		otpstacklast ];
	      } 
	      else {
		  
		otpcalculatedchar = otpstackbuf [otparg ];
	      } 
	    } 
	    incr ( otpstacknew ) ;
	    if ( otpstacknew >= ocpstacksize ) 
	    overflowocpstacksize () ;
	    otpstackbuf [otpstacknew ]= otpcalculatedchar ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 9 : 
	  {
	    {
	      if ( ( 1 > otpnoinputchars - otparg ) || ( otpnoinputchars - 
	      otparg > otpnoinputchars ) ) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66823L ) ;
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
	      if ( otpnoinputchars - otparg > otpstacklast ) 
	      {
		otpcalculatedchar = otpinputbuf [otpinputstart + 
		otpnoinputchars - otparg - otpstacklast ];
	      } 
	      else {
		  
		otpcalculatedchar = otpstackbuf [otpnoinputchars - otparg ];
	      } 
	    } 
	    incr ( otpstacknew ) ;
	    if ( otpstacknew >= ocpstacksize ) 
	    overflowocpstacksize () ;
	    otpstackbuf [otpstacknew ]= otpcalculatedchar ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 10 : 
	  {
	    otpfirstarg = otparg + 1 ;
	    incr ( otppc ) ;
	    {
	      if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	      ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66821L ) ;
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
	      otpinstruction = ocptables [otpinputocp ][ ocptables [
	      otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	      otpstateptr ]* 2 ]+ otppc ];
	      otpinstr = otpinstruction / 16777216L ;
	      otparg = otpinstruction % 16777216L ;
	    } 
	    otpsecondarg = otpnoinputchars - otparg ;
	    {register integer for_end; otpcounter = otpfirstarg ;for_end = 
	    otpsecondarg ; if ( otpcounter <= for_end) do 
	      {
		{
		  if ( ( 1 > otpcounter ) || ( otpcounter > otpnoinputchars ) 
		  ) 
		  {
		    {
		      if ( interaction == 3 ) 
		      ;
		      if ( filelineerrorstylep ) 
		      printfileline () ;
		      else printnl ( 65548L ) ;
		      print ( 66823L ) ;
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
		  if ( otpcounter > otpstacklast ) 
		  {
		    otpcalculatedchar = otpinputbuf [otpinputstart + 
		    otpcounter - otpstacklast ];
		  } 
		  else {
		      
		    otpcalculatedchar = otpstackbuf [otpcounter ];
		  } 
		} 
		incr ( otpstacknew ) ;
		if ( otpstacknew >= ocpstacksize ) 
		overflowocpstacksize () ;
		otpstackbuf [otpstacknew ]= otpcalculatedchar ;
	      } 
	    while ( otpcounter++ < for_end ) ;} 
	    incr ( otppc ) ;
	  } 
	  break ;
	case 11 : 
	  {
	    otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]+ 
	    otpcalcs [otpcalcptr ];
	    incr ( otppc ) ;
	    decr ( otpcalcptr ) ;
	  } 
	  break ;
	case 12 : 
	  {
	    otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]- 
	    otpcalcs [otpcalcptr ];
	    incr ( otppc ) ;
	    decr ( otpcalcptr ) ;
	  } 
	  break ;
	case 13 : 
	  {
	    otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]* 
	    otpcalcs [otpcalcptr ];
	    incr ( otppc ) ;
	    decr ( otpcalcptr ) ;
	  } 
	  break ;
	case 14 : 
	  {
	    otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]/ 
	    otpcalcs [otpcalcptr ];
	    incr ( otppc ) ;
	    decr ( otpcalcptr ) ;
	  } 
	  break ;
	case 15 : 
	  {
	    otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]% 
	    otpcalcs [otpcalcptr ];
	    incr ( otppc ) ;
	    decr ( otpcalcptr ) ;
	  } 
	  break ;
	case 16 : 
	  {
	    if ( otpcalcs [otpcalcptr ]>= ocptables [otpinputocp ][ 
	    ocptables [otpinputocp ][ 9 ]+ otpcalcs [otpcalcptr - 1 ]* 2 + 
	    1 ]) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66824L ) ;
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
	    otpcalcs [otpcalcptr - 1 ]= ocptables [otpinputocp ][ ocptables 
	    [otpinputocp ][ ocptables [otpinputocp ][ 9 ]+ otpcalcs [
	    otpcalcptr - 1 ]* 2 ]+ otpcalcs [otpcalcptr ]];
	    incr ( otppc ) ;
	    decr ( otpcalcptr ) ;
	  } 
	  break ;
	case 17 : 
	  {
	    incr ( otpcalcptr ) ;
	    if ( otpcalcptr >= ocpstacksize ) 
	    overflowocpstacksize () ;
	    otpcalcs [otpcalcptr ]= otparg ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 18 : 
	  {
	    {
	      if ( ( 1 > otparg ) || ( otparg > otpnoinputchars ) ) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66823L ) ;
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
	      if ( otparg > otpstacklast ) 
	      {
		otpcalculatedchar = otpinputbuf [otpinputstart + otparg - 
		otpstacklast ];
	      } 
	      else {
		  
		otpcalculatedchar = otpstackbuf [otparg ];
	      } 
	    } 
	    incr ( otpcalcptr ) ;
	    if ( otpcalcptr >= ocpstacksize ) 
	    overflowocpstacksize () ;
	    otpcalcs [otpcalcptr ]= otpcalculatedchar ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 19 : 
	  {
	    {
	      if ( ( 1 > otpnoinputchars - otparg ) || ( otpnoinputchars - 
	      otparg > otpnoinputchars ) ) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66823L ) ;
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
	      if ( otpnoinputchars - otparg > otpstacklast ) 
	      {
		otpcalculatedchar = otpinputbuf [otpinputstart + 
		otpnoinputchars - otparg - otpstacklast ];
	      } 
	      else {
		  
		otpcalculatedchar = otpstackbuf [otpnoinputchars - otparg ];
	      } 
	    } 
	    incr ( otpcalcptr ) ;
	    if ( otpcalcptr >= ocpstacksize ) 
	    overflowocpstacksize () ;
	    otpcalcs [otpcalcptr ]= otpcalculatedchar ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 20 : 
	  {
	    otpinputstart = otpinputlast ;
	    {register integer for_end; otpcounter = 1 ;for_end = ( 
	    otpstacknew - otpstackused ) ; if ( otpcounter <= for_end) do 
	      {
		otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
		otpstackused ];
	      } 
	    while ( otpcounter++ < for_end ) ;} 
	    otpstacknew = otpstacknew - otpstackused ;
	    otpstacklast = otpstacknew ;
	    otpstackused = 0 ;
	    otpstates [otpstateptr ]= otparg ;
	    otppc = 0 ;
	  } 
	  break ;
	case 21 : 
	  {
	    otpinputstart = otpinputlast ;
	    {register integer for_end; otpcounter = 1 ;for_end = ( 
	    otpstacknew - otpstackused ) ; if ( otpcounter <= for_end) do 
	      {
		otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
		otpstackused ];
	      } 
	    while ( otpcounter++ < for_end ) ;} 
	    otpstacknew = otpstacknew - otpstackused ;
	    otpstacklast = otpstacknew ;
	    otpstackused = 0 ;
	    incr ( otpstateptr ) ;
	    if ( otpstateptr >= ocpstacksize ) 
	    overflowocpstacksize () ;
	    otpstates [otpstateptr ]= otparg ;
	    otppc = 0 ;
	  } 
	  break ;
	case 22 : 
	  {
	    otpinputstart = otpinputlast ;
	    {register integer for_end; otpcounter = 1 ;for_end = ( 
	    otpstacknew - otpstackused ) ; if ( otpcounter <= for_end) do 
	      {
		otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
		otpstackused ];
	      } 
	    while ( otpcounter++ < for_end ) ;} 
	    otpstacknew = otpstacknew - otpstackused ;
	    otpstacklast = otpstacknew ;
	    otpstackused = 0 ;
	    if ( otpstateptr > 0 ) 
	    decr ( otpstateptr ) ;
	    otppc = 0 ;
	  } 
	  break ;
	case 23 : 
	  {
	    otpinputstart = otpinputlast ;
	    otpinputlast = otpinputstart ;
	    otpstackused = 0 ;
	    if ( ( otpstacklast == 0 ) && ( otpinputlast >= otpinputend ) ) 
	    otpfinished = true ;
	    else if ( ( otpstackused < otpstacklast ) ) 
	    {
	      incr ( otpstackused ) ;
	      otpinputchar = otpstackbuf [otpstackused ];
	      otpnoinputchars = 1 ;
	      incr ( otppc ) ;
	    } 
	    else {
		
	      incr ( otpinputlast ) ;
	      otpinputchar = otpinputbuf [otpinputlast ];
	      otpnoinputchars = 1 ;
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 24 : 
	  {
	    otpinputlast = otpinputstart ;
	    otpstackused = 0 ;
	    if ( ( otpstackused < otpstacklast ) ) 
	    {
	      incr ( otpstackused ) ;
	      otpinputchar = otpstackbuf [otpstackused ];
	      otpnoinputchars = 1 ;
	      incr ( otppc ) ;
	    } 
	    else {
		
	      incr ( otpinputlast ) ;
	      otpinputchar = otpinputbuf [otpinputlast ];
	      otpnoinputchars = 1 ;
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 25 : 
	  {
	    if ( otpinputstart < otpinputlast ) 
	    {
	      decr ( otpinputlast ) ;
	      otpinputchar = otpinputbuf [otpinputlast ];
	    } 
	    else {
		
	      decr ( otpstackused ) ;
	      otpinputchar = otpstackbuf [otpstackused ];
	    } 
	    decr ( otpnoinputchars ) ;
	    incr ( otppc ) ;
	  } 
	  break ;
	case 26 : 
	  {
	    otppc = otparg ;
	  } 
	  break ;
	case 27 : 
	  {
	    otpfirstarg = otparg ;
	    incr ( otppc ) ;
	    {
	      if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	      ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66821L ) ;
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
	      otpinstruction = ocptables [otpinputocp ][ ocptables [
	      otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	      otpstateptr ]* 2 ]+ otppc ];
	      otpinstr = otpinstruction / 16777216L ;
	      otparg = otpinstruction % 16777216L ;
	    } 
	    if ( otpinputchar != otpfirstarg ) 
	    {
	      otppc = otparg ;
	    } 
	    else {
		
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 28 : 
	  {
	    otpfirstarg = otparg ;
	    incr ( otppc ) ;
	    {
	      if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	      ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66821L ) ;
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
	      otpinstruction = ocptables [otpinputocp ][ ocptables [
	      otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	      otpstateptr ]* 2 ]+ otppc ];
	      otpinstr = otpinstruction / 16777216L ;
	      otparg = otpinstruction % 16777216L ;
	    } 
	    if ( otpinputchar == otpfirstarg ) 
	    {
	      otppc = otparg ;
	    } 
	    else {
		
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 29 : 
	  {
	    otpfirstarg = otparg ;
	    incr ( otppc ) ;
	    {
	      if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	      ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66821L ) ;
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
	      otpinstruction = ocptables [otpinputocp ][ ocptables [
	      otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	      otpstateptr ]* 2 ]+ otppc ];
	      otpinstr = otpinstruction / 16777216L ;
	      otparg = otpinstruction % 16777216L ;
	    } 
	    if ( otpinputchar < otpfirstarg ) 
	    {
	      otppc = otparg ;
	    } 
	    else {
		
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 30 : 
	  {
	    otpfirstarg = otparg ;
	    incr ( otppc ) ;
	    {
	      if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	      ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66821L ) ;
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
	      otpinstruction = ocptables [otpinputocp ][ ocptables [
	      otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	      otpstateptr ]* 2 ]+ otppc ];
	      otpinstr = otpinstruction / 16777216L ;
	      otparg = otpinstruction % 16777216L ;
	    } 
	    if ( otpinputchar <= otpfirstarg ) 
	    {
	      otppc = otparg ;
	    } 
	    else {
		
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 31 : 
	  {
	    otpfirstarg = otparg ;
	    incr ( otppc ) ;
	    {
	      if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	      ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66821L ) ;
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
	      otpinstruction = ocptables [otpinputocp ][ ocptables [
	      otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	      otpstateptr ]* 2 ]+ otppc ];
	      otpinstr = otpinstruction / 16777216L ;
	      otparg = otpinstruction % 16777216L ;
	    } 
	    if ( otpinputchar > otpfirstarg ) 
	    {
	      otppc = otparg ;
	    } 
	    else {
		
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 32 : 
	  {
	    otpfirstarg = otparg ;
	    incr ( otppc ) ;
	    {
	      if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	      ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	      {
		{
		  if ( interaction == 3 ) 
		  ;
		  if ( filelineerrorstylep ) 
		  printfileline () ;
		  else printnl ( 65548L ) ;
		  print ( 66821L ) ;
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
	      otpinstruction = ocptables [otpinputocp ][ ocptables [
	      otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	      otpstateptr ]* 2 ]+ otppc ];
	      otpinstr = otpinstruction / 16777216L ;
	      otparg = otpinstruction % 16777216L ;
	    } 
	    if ( otpinputchar >= otpfirstarg ) 
	    {
	      otppc = otparg ;
	    } 
	    else {
		
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 33 : 
	  {
	    if ( ( otpstackused < otpstacklast ) ) 
	    {
	      incr ( otpstackused ) ;
	      otpinputchar = otpstackbuf [otpstackused ];
	      incr ( otpnoinputchars ) ;
	      incr ( otppc ) ;
	    } 
	    else if ( otpinputlast >= otpinputend ) 
	    {
	      otppc = otparg ;
	    } 
	    else {
		
	      incr ( otpinputlast ) ;
	      otpinputchar = otpinputbuf [otpinputlast ];
	      incr ( otpnoinputchars ) ;
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 34 : 
	  {
	    if ( otpinputlast == 0 ) 
	    {
	      otppc = otparg ;
	    } 
	    else {
		
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 35 : 
	  {
	    if ( otpinputlast >= otpinputend ) 
	    {
	      otppc = otparg ;
	    } 
	    else {
		
	      incr ( otppc ) ;
	    } 
	  } 
	  break ;
	case 36 : 
	  {
	    otpinputstart = otpinputlast ;
	    {register integer for_end; otpcounter = 1 ;for_end = ( 
	    otpstacknew - otpstackused ) ; if ( otpcounter <= for_end) do 
	      {
		otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
		otpstackused ];
	      } 
	    while ( otpcounter++ < for_end ) ;} 
	    otpstacknew = otpstacknew - otpstackused ;
	    otpstacklast = otpstacknew ;
	    otpstackused = 0 ;
	    otppc = 0 ;
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
	      print ( 66822L ) ;
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
	  break ;
	} 
      } 
    } 
    {register integer for_end; otpcounter = 1 ;for_end = ( otpoutputend - 1 
    ) ; if ( otpcounter <= for_end) do 
      {
	news = otpoutputbuf [otpcounter ];
	if ( ( ommode < 3 ) && ( news > 255 ) ) 
	{
	  printchar ( 94 ) ;
	  printchar ( 94 ) ;
	  printchar ( 94 ) ;
	  printchar ( 94 ) ;
	  l = news / 4096 ;
	  if ( l < 10 ) 
	  printchar ( l + 48 ) ;
	  else printchar ( l + 87 ) ;
	  l = ( news % 4096 ) / 256 ;
	  if ( l < 10 ) 
	  printchar ( l + 48 ) ;
	  else printchar ( l + 87 ) ;
	  l = ( news % 256 ) / 16 ;
	  if ( l < 10 ) 
	  printchar ( l + 48 ) ;
	  else printchar ( l + 87 ) ;
	  l = news % 16 ;
	  if ( l < 10 ) 
	  printchar ( l + 48 ) ;
	  else printchar ( l + 87 ) ;
	} 
	else printchar ( news ) ;
      } 
    while ( otpcounter++ < for_end ) ;} 
  } 
} 
void 
zslowprint ( integer s ) 
{
  slowprint_regmem 
  if ( ( s >= strptr ) || ( s <= 65535L ) ) 
  print ( s ) ;
  else omegaprint ( s ) ;
} 
void 
zprintesc ( strnumber s ) 
{
  printesc_regmem 
  integer c  ;
  c = neweqtbint ( 1049453L ) ;
  if ( c >= 0 ) {
      
    if ( c <= 65535L ) 
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
  if ( p < 131074L ) {
      
    if ( p >= 65537L ) {
	
      if ( p == 131073L ) 
      {
	printesc ( 65794L ) ;
	printesc ( 65795L ) ;
	printchar ( 32 ) ;
      } 
      else {
	  
	printesc ( p - 65537L ) ;
	if ( newequiv ( 721728L + p - 65537L ) == 11 ) 
	printchar ( 32 ) ;
      } 
    } 
    else if ( p < 1 ) 
    printesc ( 65796L ) ;
    else print ( p - 1 ) ;
  } 
  else if ( p >= 393229L ) 
  printesc ( 65796L ) ;
  else if ( ( newhashtext ( 1246116L + p ) >= strptr ) ) 
  printesc ( 65797L ) ;
  else {
      
    printesc ( newhashtext ( 1246116L + p ) ) ;
    printchar ( 32 ) ;
  } 
} 
void 
zsprintcs ( halfword p ) 
{
  sprintcs_regmem 
  if ( p < 131074L ) {
      
    if ( p < 65537L ) 
    print ( p - 1 ) ;
    else if ( p < 131073L ) 
    printesc ( p - 65537L ) ;
    else {
	
      printesc ( 65794L ) ;
      printesc ( 65795L ) ;
    } 
  } 
  else printesc ( newhashtext ( 1246116L + p ) ) ;
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
    j = strstartar [a - 65536L ];
    while ( ( ! mustquote ) && ( j < strstartar [a - 65535L ]) ) {
	
      mustquote = strpool [j ]== 32 ;
      incr ( j ) ;
    } 
  } 
  if ( n != 0 ) 
  {
    j = strstartar [n - 65536L ];
    while ( ( ! mustquote ) && ( j < strstartar [n - 65535L ]) ) {
	
      mustquote = strpool [j ]== 32 ;
      incr ( j ) ;
    } 
  } 
  if ( e != 0 ) 
  {
    j = strstartar [e - 65536L ];
    while ( ( ! mustquote ) && ( j < strstartar [e - 65535L ]) ) {
	
      mustquote = strpool [j ]== 32 ;
      incr ( j ) ;
    } 
  } 
  if ( mustquote ) 
  printchar ( 34 ) ;
  if ( a != 0 ) 
  {register integer for_end; j = strstartar [a - 65536L ];for_end = 
  strstartar [a - 65535L ]- 1 ; if ( j <= for_end) do 
    if ( strpool [j ]!= 34 ) 
    printchar ( strpool [j ]) ;
  while ( j++ < for_end ) ;} 
  if ( n != 0 ) 
  {register integer for_end; j = strstartar [n - 65536L ];for_end = 
  strstartar [n - 65535L ]- 1 ; if ( j <= for_end) do 
    if ( strpool [j ]!= 34 ) 
    printchar ( strpool [j ]) ;
  while ( j++ < for_end ) ;} 
  if ( e != 0 ) 
  {register integer for_end; j = strstartar [e - 65536L ];for_end = 
  strstartar [e - 65535L ]- 1 ; if ( j <= for_end) do 
    if ( strpool [j ]!= 34 ) 
    printchar ( strpool [j ]) ;
  while ( j++ < for_end ) ;} 
  if ( mustquote ) 
  printchar ( 34 ) ;
} 
void 
zprintsize ( integer s ) 
{
  printsize_regmem 
  if ( s == 0 ) 
  printesc ( 65698L ) ;
  else if ( s == 256 ) 
  printesc ( 65699L ) ;
  else printesc ( 65700L ) ;
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
  if ( false ) 
  n = mem [q + 1 ].hh .v.RH ;
  else {
      
    n = mem [q ].hh.b0 % 16 ;
    q = mem [q ].hh .v.RH ;
    n = n + 16 * mem [q ].hh.b0 ;
    q = mem [q ].hh .v.RH ;
    n = n + 256 * ( mem [q ].hh.b0 + 16 * mem [mem [q ].hh .v.RH ].hh.b0 
    ) ;
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
      if ( newhashtext ( 1246116L + h ) > 0 ) 
      {
	{register integer for_end; c = strstartar [newhashtext ( 1246116L + 
	h ) - 65536L ];for_end = strstartar [newhashtext ( 1246116L + h ) - 
	65535L ]- 1 ; if ( c <= for_end) do 
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
  printnl ( 65548L ) ;
  else {
      
    printnl ( 65624L ) ;
    print ( fullsourcefilenamestack [level ]) ;
    print ( 58 ) ;
    if ( level == inopen ) 
    printint ( line ) ;
    else printint ( linestack [level + 1 ]) ;
    print ( 65873L ) ;
  } 
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
      print ( 65550L ) ;
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
	  helpline [1 ]= 65563L ;
	  helpline [0 ]= 65564L ;
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
	editnamestart = strstartar [inputstack [baseptr ].namefield - 
	65536L ];
	editnamelength = strstartar [inputstack [baseptr ].namefield - 
	65535L ]- strstartar [inputstack [baseptr ].namefield - 65536L ];
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
	    helpline [1 ]= 65565L ;
	    helpline [0 ]= 65566L ;
	  } 
	  do {
	      decr ( helpptr ) ;
	    print ( helpline [helpptr ]) ;
	    println () ;
	  } while ( ! ( helpptr == 0 ) ) ;
	} 
	{
	  helpptr = 4 ;
	  helpline [3 ]= 65567L ;
	  helpline [2 ]= 65566L ;
	  helpline [1 ]= 65568L ;
	  helpline [0 ]= 65569L ;
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
	    print ( 65562L ) ;
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
	print ( 65557L ) ;
	switch ( c ) 
	{case 81 : 
	  {
	    printesc ( 65558L ) ;
	    decr ( selector ) ;
	  } 
	  break ;
	case 82 : 
	  printesc ( 65559L ) ;
	  break ;
	case 83 : 
	  printesc ( 65560L ) ;
	  break ;
	} 
	print ( 65561L ) ;
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
      print ( 65551L ) ;
      printnl ( 65552L ) ;
      printnl ( 65553L ) ;
      if ( baseptr > 0 ) 
      print ( 65554L ) ;
      if ( deletionsallowed ) 
      printnl ( 65555L ) ;
      printnl ( 65556L ) ;
    } 
  } 
  incr ( errorcount ) ;
  if ( errorcount == 100 ) 
  {
    printnl ( 65549L ) ;
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
    else printnl ( 65548L ) ;
    print ( 65571L ) ;
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
    else printnl ( 65548L ) ;
    print ( 65572L ) ;
  } 
  print ( s ) ;
  printchar ( 61 ) ;
  printint ( n ) ;
  printchar ( 93 ) ;
  {
    helpptr = 2 ;
    helpline [1 ]= 65573L ;
    helpline [0 ]= 65574L ;
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
overflowocpbufsize ( void ) 
{
  overflowocpbufsize_regmem 
  overflow ( 65575L , ocpbufsize ) ;
} 
void 
overflowocpstacksize ( void ) 
{
  overflowocpstacksize_regmem 
  overflow ( 65576L , ocpstacksize ) ;
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
      else printnl ( 65548L ) ;
      print ( 65577L ) ;
    } 
    print ( s ) ;
    printchar ( 41 ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 65578L ;
    } 
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 65579L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 65580L ;
      helpline [0 ]= 65581L ;
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
    if ( ! newinputln ( stdin , terminmode , termintranslation , true ) ) 
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
integer 
zlength ( strnumber s ) 
{
  register integer Result; length_regmem 
  if ( ( s >= 65536L ) ) 
  Result = strstartar [s - 65535L ]- strstartar [s - 65536L ];
  else if ( ( s >= 32 ) && ( s < 127 ) ) 
  Result = 1 ;
  else if ( ( s <= 127 ) ) 
  Result = 3 ;
  else if ( ( s < 256 ) ) 
  Result = 4 ;
  else Result = 8 ;
  return Result ;
} 
strnumber 
makestring ( void ) 
{
  register strnumber Result; makestring_regmem 
  if ( strptr == maxstrings ) 
  overflow ( 65544L , maxstrings - initstrptr ) ;
  incr ( strptr ) ;
  strstartar [strptr - 65536L ]= poolptr ;
  Result = strptr - 1 ;
  return Result ;
} 
boolean 
zstreqbuf ( strnumber s , integer k ) 
{
  /* 45 */ register boolean Result; streqbuf_regmem 
  poolpointer j  ;
  boolean result  ;
  j = strstartar [s - 65536L ];
  while ( j < strstartar [s - 65535L ]) {
      
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
  if ( length ( s ) != length ( t ) ) 
  goto lab45 ;
  if ( ( length ( s ) == 1 ) ) 
  {
    if ( s < 65536L ) 
    {
      if ( t < 65536L ) 
      {
	if ( s != t ) 
	goto lab45 ;
      } 
      else {
	  
	if ( s != strpool [strstartar [t - 65536L ]]) 
	goto lab45 ;
      } 
    } 
    else {
	
      if ( t < 65536L ) 
      {
	if ( strpool [strstartar [s - 65536L ]]!= t ) 
	goto lab45 ;
      } 
      else {
	  
	if ( strpool [strstartar [s - 65536L ]]!= strpool [strstartar [t 
	- 65536L ]]) 
	goto lab45 ;
      } 
    } 
  } 
  else {
      
    j = strstartar [s - 65536L ];
    k = strstartar [t - 65536L ];
    while ( j < strstartar [s - 65535L ]) {
	
      if ( strpool [j ]!= strpool [k ]) 
      goto lab45 ;
      incr ( j ) ;
      incr ( k ) ;
    } 
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
  len = length ( search ) ;
  if ( len == 0 ) 
  {
    result = 65624L ;
    goto lab40 ;
  } 
  else {
      
    s = search - 1 ;
    while ( s > 65535L ) {
	
      if ( length ( s ) == len ) {
	  
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
      poolptr = strstartar [strptr - 65536L ];
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
  j = strstartar [10 ];
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
  j = strstartar [strptr - 65536L ];
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
  if ( ! newinputln ( stdin , terminmode , termintranslation , true ) ) 
  fatalerror ( 65547L ) ;
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
  print ( 65570L ) ;
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
      else printnl ( 65548L ) ;
      print ( 65582L ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 65583L ;
      helpline [1 ]= 65584L ;
      helpline [0 ]= 65585L ;
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
  while ( ( p != 0 ) && ( tally < l ) ) {
      
    if ( p == q ) 
    {
      firstcount = tally ;
      trickcount = tally + 1 + errorline - halferrorline ;
      if ( trickcount < errorline ) 
      trickcount = errorline ;
    } 
    if ( ( p < himemmin ) || ( p > memend ) ) 
    {
      printesc ( 65595L ) ;
      return ;
    } 
    if ( mem [p ].hh .v.LH >= 1048575L ) 
    printcs ( mem [p ].hh .v.LH - 1048575L ) ;
    else {
	
      m = mem [p ].hh .v.LH / 65536L ;
      c = mem [p ].hh .v.LH % 65536L ;
      if ( mem [p ].hh .v.LH < 0 ) 
      printesc ( 65860L ) ;
      else switch ( m ) 
      {case 1 : 
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
	print ( 65861L ) ;
	break ;
	default: 
	printesc ( 65860L ) ;
	break ;
      } 
    } 
    p = mem [p ].hh .v.RH ;
  } 
  if ( p != 0 ) 
  printesc ( 65694L ) ;
} 
void 
runaway ( void ) 
{
  runaway_regmem 
  halfword p  ;
  if ( scannerstatus > 1 ) 
  {
    printnl ( 65875L ) ;
    switch ( scannerstatus ) 
    {case 2 : 
      {
	print ( 65876L ) ;
	p = defref ;
      } 
      break ;
    case 3 : 
      {
	print ( 65877L ) ;
	p = memtop - 3 ;
      } 
      break ;
    case 4 : 
      {
	print ( 65878L ) ;
	p = memtop - 4 ;
      } 
      break ;
    case 5 : 
      {
	print ( 65879L ) ;
	p = defref ;
      } 
      break ;
    } 
    printchar ( 63 ) ;
    println () ;
    showtokenlist ( mem [p ].hh .v.RH , 0 , errorline - 10 ) ;
  } 
} 
halfword 
getavail ( void ) 
{
  register halfword Result; getavail_regmem 
  halfword p  ;
  p = avail ;
  if ( p != 0 ) 
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
      overflow ( 65586L , memmax + 1 - memmin ) ;
    } 
  } 
  mem [p ].hh .v.RH = 0 ;
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
  if ( p != 0 ) 
  {
    r = p ;
    do {
	q = r ;
      r = mem [r ].hh .v.RH ;
	;
#ifdef STAT
      decr ( dynused ) ;
#endif /* STAT */
    } while ( ! ( r == 0 ) ) ;
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
      mem [lomemmax ].hh .v.RH = 0 ;
      mem [lomemmax ].hh .v.LH = 0 ;
      rover = q ;
      goto lab20 ;
    } 
  } 
  overflow ( 65586L , memmax + 1 - memmin ) ;
  lab40: mem [r ].hh .v.RH = 0 ;
	;
#ifdef STAT
  varused = varused + s ;
#endif /* STAT */
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
  p = getnode ( 8 ) ;
  mem [p ].hh.b0 = 0 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].cint = 0 ;
  mem [p + 2 ].cint = 0 ;
  mem [p + 3 ].cint = 0 ;
  mem [p + 4 ].cint = 0 ;
  mem [p + 5 ].hh .v.RH = 0 ;
  mem [p + 5 ].hh.b0 = 0 ;
  mem [p + 5 ].hh.b1 = 0 ;
  mem [p + 6 ].gr = 0.0 ;
  mem [p + 7 ].cint = neweqtbint ( 1049482L ) ;
  Result = p ;
  return Result ;
} 
halfword 
newrule ( void ) 
{
  register halfword Result; newrule_regmem 
  halfword p  ;
  p = getnode ( 5 ) ;
  mem [p ].hh.b0 = 2 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].cint = -1073741824L ;
  mem [p + 2 ].cint = -1073741824L ;
  mem [p + 3 ].cint = -1073741824L ;
  mem [p + 4 ].hh .v.LH = -1 ;
  Result = p ;
  return Result ;
} 
halfword 
znewligature ( quarterword f , quarterword c , halfword q ) 
{
  register halfword Result; newligature_regmem 
  halfword p  ;
  p = getnode ( 2 ) ;
  mem [p ].hh.b0 = 6 ;
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
  mem [p + 1 ].hh .v.RH = 0 ;
  Result = p ;
  return Result ;
} 
halfword 
newdisc ( void ) 
{
  register halfword Result; newdisc_regmem 
  halfword p  ;
  p = getnode ( 2 ) ;
  mem [p ].hh.b0 = 7 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].hh .v.LH = 0 ;
  mem [p + 1 ].hh .v.RH = 0 ;
  Result = p ;
  return Result ;
} 
halfword 
znewmath ( scaled w , smallnumber s ) 
{
  register halfword Result; newmath_regmem 
  halfword p  ;
  p = getnode ( 2 ) ;
  mem [p ].hh.b0 = 9 ;
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
  mem [q ].hh .v.RH = 0 ;
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
  p = getnode ( 2 ) ;
  mem [p ].hh.b0 = 10 ;
  mem [p ].hh.b1 = n + 1 ;
  mem [p + 1 ].hh .v.RH = 0 ;
  q = newequiv ( 393230L + n ) ;
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
  p = getnode ( 2 ) ;
  mem [p ].hh.b0 = 10 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].hh .v.RH = 0 ;
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
  tempptr = newspec ( newequiv ( 393230L + n ) ) ;
  p = newglue ( tempptr ) ;
  mem [tempptr ].hh .v.RH = 0 ;
  mem [p ].hh.b1 = n + 1 ;
  Result = p ;
  return Result ;
} 
halfword 
znewkern ( scaled w ) 
{
  register halfword Result; newkern_regmem 
  halfword p  ;
  p = getnode ( 2 ) ;
  mem [p ].hh.b0 = 11 ;
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
  p = getnode ( 2 ) ;
  mem [p ].hh.b0 = 12 ;
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
  q = 0 ;
  clobbered = false ;
  while ( p != 0 ) {
      
    if ( ( p > memend ) || ( p < himemmin ) ) 
    clobbered = true ;
    else if ( freearr [p ]) 
    clobbered = true ;
    if ( clobbered ) 
    {
      printnl ( 65587L ) ;
      printint ( q ) ;
      goto lab31 ;
    } 
    freearr [p ]= true ;
    q = p ;
    p = mem [q ].hh .v.RH ;
  } 
  lab31: ;
  p = rover ;
  q = 0 ;
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
      printnl ( 65588L ) ;
      printint ( q ) ;
      goto lab32 ;
    } 
    {register integer for_end; q = p ;for_end = p + mem [p ].hh .v.LH - 1 
    ; if ( q <= for_end) do 
      {
	if ( freearr [q ]) 
	{
	  printnl ( 65589L ) ;
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
      printnl ( 65590L ) ;
      printint ( p ) ;
    } 
    while ( ( p <= lomemmax ) && ! freearr [p ]) incr ( p ) ;
    while ( ( p <= lomemmax ) && freearr [p ]) incr ( p ) ;
  } 
  if ( printlocs ) 
  {
    printnl ( 65591L ) ;
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
	printnl ( 65592L ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
      if ( mem [q ].hh .v.LH == p ) 
      {
	printnl ( 65593L ) ;
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
	printnl ( 65592L ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
      if ( mem [q ].hh .v.LH == p ) 
      {
	printnl ( 65593L ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
    } 
  while ( q++ < for_end ) ;} 
  {register integer for_end; q = 1 ;for_end = 720958L ; if ( q <= for_end) 
  do 
    {
      if ( newequiv ( q ) == p ) 
      {
	printnl ( 65791L ) ;
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
	printnl ( 65852L ) ;
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
	printnl ( 66296L ) ;
	printint ( q ) ;
	printchar ( 41 ) ;
      } 
    } 
  while ( q++ < for_end ) ;} 
} 
#endif /* TEXMF_DEBUG */
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
	  printesc ( newhashtext ( 1442736L + mem [p ].hh.b0 ) ) ;
	  printchar ( 32 ) ;
	  fontinshortdisplay = mem [p ].hh.b0 ;
	} 
	print ( mem [p ].hh.b1 ) ;
      } 
    } 
    else switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 3 : 
    case 8 : 
    case 4 : 
    case 5 : 
    case 13 : 
      print ( 65594L ) ;
      break ;
    case 2 : 
      printchar ( 124 ) ;
      break ;
    case 10 : 
      if ( mem [p + 1 ].hh .v.LH != membot ) 
      printchar ( 32 ) ;
      break ;
    case 9 : 
      printchar ( 36 ) ;
      break ;
    case 6 : 
      shortdisplay ( mem [p + 1 ].hh .v.RH ) ;
      break ;
    case 7 : 
      {
	shortdisplay ( mem [p + 1 ].hh .v.LH ) ;
	shortdisplay ( mem [p + 1 ].hh .v.RH ) ;
	n = mem [p ].hh.b1 ;
	while ( n > 0 ) {
	    
	  if ( mem [p ].hh .v.RH != 0 ) 
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
  printesc ( 65595L ) ;
  else {
      
    printesc ( newhashtext ( 1442736L + mem [p ].hh.b0 ) ) ;
    printchar ( 32 ) ;
    print ( mem [p ].hh.b1 ) ;
  } 
} 
void 
zprintmark ( integer p ) 
{
  printmark_regmem 
  printchar ( 123 ) ;
  if ( ( p < himemmin ) || ( p > memend ) ) 
  printesc ( 65595L ) ;
  else showtokenlist ( mem [p ].hh .v.RH , 0 , maxprintline - 10 ) ;
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
zprintdir ( integer d ) 
{
  printdir_regmem 
  print ( dirnames [dirprimary [d ]]) ;
  print ( dirnames [dirsecondary [d ]]) ;
  print ( dirnames [dirtertiary [d ]]) ;
} 
void 
zprintglue ( scaled d , integer order , strnumber s ) 
{
  printglue_regmem 
  printscaled ( d ) ;
  if ( ( order < 0 ) || ( order > 4 ) ) 
  print ( 65596L ) ;
  else if ( order > 0 ) 
  {
    print ( 65597L ) ;
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
      print ( 65598L ) ;
      printglue ( mem [p + 2 ].cint , mem [p ].hh.b0 , s ) ;
    } 
    if ( mem [p + 3 ].cint != 0 ) 
    {
      print ( 65599L ) ;
      printglue ( mem [p + 3 ].cint , mem [p ].hh.b1 , s ) ;
    } 
  } 
} 
void 
zprintfamandchar ( halfword p ) 
{
  printfamandchar_regmem 
  printesc ( 65750L ) ;
  printint ( mem [p ].hh.b0 ) ;
  printchar ( 32 ) ;
  print ( mem [p ].hh.b1 ) ;
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
  if ( ( poolptr - strstartar [strptr - 65536L ]) >= depththreshold ) 
  {
    if ( mem [p ].hh .v.RH != 0 ) 
    print ( 65600L ) ;
  } 
  else {
      
    {
      strpool [poolptr ]= c ;
      incr ( poolptr ) ;
    } 
    tempptr = p ;
    switch ( mem [p ].hh .v.RH ) 
    {case 1 : 
      {
	println () ;
	printcurrentstring () ;
	printfamandchar ( p ) ;
      } 
      break ;
    case 2 : 
      showinfo () ;
      break ;
    case 3 : 
      if ( mem [p ].hh .v.LH == 0 ) 
      {
	println () ;
	printcurrentstring () ;
	print ( 66215L ) ;
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
    printesc ( 66216L ) ;
    break ;
  case 1 : 
    printesc ( 66217L ) ;
    break ;
  case 2 : 
    printesc ( 66218L ) ;
    break ;
  case 3 : 
    printesc ( 66219L ) ;
    break ;
    default: 
    print ( 66220L ) ;
    break ;
  } 
} 
void 
zprintskipparam ( integer n ) 
{
  printskipparam_regmem 
  switch ( n ) 
  {case 0 : 
    printesc ( 65662L ) ;
    break ;
  case 1 : 
    printesc ( 65663L ) ;
    break ;
  case 2 : 
    printesc ( 65664L ) ;
    break ;
  case 3 : 
    printesc ( 65665L ) ;
    break ;
  case 4 : 
    printesc ( 65666L ) ;
    break ;
  case 5 : 
    printesc ( 65667L ) ;
    break ;
  case 6 : 
    printesc ( 65668L ) ;
    break ;
  case 7 : 
    printesc ( 65669L ) ;
    break ;
  case 8 : 
    printesc ( 65670L ) ;
    break ;
  case 9 : 
    printesc ( 65671L ) ;
    break ;
  case 10 : 
    printesc ( 65672L ) ;
    break ;
  case 11 : 
    printesc ( 65673L ) ;
    break ;
  case 12 : 
    printesc ( 65674L ) ;
    break ;
  case 13 : 
    printesc ( 65675L ) ;
    break ;
  case 14 : 
    printesc ( 65676L ) ;
    break ;
  case 15 : 
    printesc ( 65677L ) ;
    break ;
  case 16 : 
    printesc ( 65678L ) ;
    break ;
  case 17 : 
    printesc ( 65679L ) ;
    break ;
    default: 
    print ( 65680L ) ;
    break ;
  } 
} 
void 
zshownodelist ( integer p ) 
{
  /* 10 */ shownodelist_regmem 
  integer n  ;
  real g  ;
  if ( ( poolptr - strstartar [strptr - 65536L ]) > depththreshold ) 
  {
    if ( p > 0 ) 
    print ( 65600L ) ;
    return ;
  } 
  n = 0 ;
  while ( p > memmin ) {
      
    println () ;
    printcurrentstring () ;
    if ( p > memend ) 
    {
      print ( 65601L ) ;
      return ;
    } 
    incr ( n ) ;
    if ( n > breadthmax ) 
    {
      print ( 65602L ) ;
      return ;
    } 
    if ( ( p >= himemmin ) ) 
    printfontandchar ( p ) ;
    else switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 13 : 
      {
	if ( mem [p ].hh.b0 == 0 ) 
	printesc ( 104 ) ;
	else if ( mem [p ].hh.b0 == 1 ) 
	printesc ( 118 ) ;
	else printesc ( 65604L ) ;
	print ( 65605L ) ;
	printscaled ( mem [p + 3 ].cint ) ;
	printchar ( 43 ) ;
	printscaled ( mem [p + 2 ].cint ) ;
	print ( 65606L ) ;
	printscaled ( mem [p + 1 ].cint ) ;
	if ( mem [p ].hh.b0 == 13 ) 
	{
	  if ( mem [p ].hh.b1 != 0 ) 
	  {
	    print ( 65570L ) ;
	    printint ( mem [p ].hh.b1 + 1 ) ;
	    print ( 65609L ) ;
	  } 
	  if ( mem [p + 6 ].cint != 0 ) 
	  {
	    print ( 65610L ) ;
	    printglue ( mem [p + 6 ].cint , mem [p + 5 ].hh.b1 , 0 ) ;
	  } 
	  if ( mem [p + 4 ].cint != 0 ) 
	  {
	    print ( 65611L ) ;
	    printglue ( mem [p + 4 ].cint , mem [p + 5 ].hh.b0 , 0 ) ;
	  } 
	} 
	else {
	    
	  g = mem [p + 6 ].gr ;
	  if ( ( g != 0.0 ) && ( mem [p + 5 ].hh.b0 != 0 ) ) 
	  {
	    print ( 65612L ) ;
	    if ( mem [p + 5 ].hh.b0 == 2 ) 
	    print ( 65613L ) ;
	    if ( fabs ( g ) > 20000.0 ) 
	    {
	      if ( g > 0.0 ) 
	      printchar ( 62 ) ;
	      else print ( 65614L ) ;
	      printglue ( 20000 * 65536L , mem [p + 5 ].hh.b1 , 0 ) ;
	    } 
	    else printglue ( round ( 65536L * g ) , mem [p + 5 ].hh.b1 , 0 ) 
	    ;
	  } 
	  if ( mem [p + 4 ].cint != 0 ) 
	  {
	    print ( 65607L ) ;
	    printscaled ( mem [p + 4 ].cint ) ;
	  } 
	  print ( 65608L ) ;
	  printdir ( mem [p + 7 ].cint ) ;
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
    case 2 : 
      {
	printesc ( 65615L ) ;
	printruledimen ( mem [p + 3 ].cint ) ;
	printchar ( 43 ) ;
	printruledimen ( mem [p + 2 ].cint ) ;
	print ( 65606L ) ;
	printruledimen ( mem [p + 1 ].cint ) ;
      } 
      break ;
    case 3 : 
      {
	printesc ( 65616L ) ;
	printint ( mem [p ].hh.b1 ) ;
	print ( 65617L ) ;
	printscaled ( mem [p + 3 ].cint ) ;
	print ( 65618L ) ;
	printspec ( mem [p + 4 ].hh .v.RH , 0 ) ;
	printchar ( 44 ) ;
	printscaled ( mem [p + 2 ].cint ) ;
	print ( 65619L ) ;
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
    case 8 : 
      switch ( mem [p ].hh.b1 ) 
      {case 0 : 
	{
	  printwritewhatsit ( 66661L , p ) ;
	  printchar ( 61 ) ;
	  printfilename ( mem [p + 1 ].hh .v.RH , mem [p + 2 ].hh .v.LH , 
	  mem [p + 2 ].hh .v.RH ) ;
	} 
	break ;
      case 1 : 
	{
	  printwritewhatsit ( 65903L , p ) ;
	  printmark ( mem [p + 1 ].hh .v.RH ) ;
	} 
	break ;
      case 2 : 
	printwritewhatsit ( 66662L , p ) ;
	break ;
      case 3 : 
	{
	  printesc ( 66663L ) ;
	  printmark ( mem [p + 1 ].hh .v.RH ) ;
	} 
	break ;
      case 4 : 
	{
	  printesc ( 66665L ) ;
	  printint ( mem [p + 1 ].hh .v.RH ) ;
	  print ( 66675L ) ;
	  printint ( mem [p + 1 ].hh.b0 ) ;
	  printchar ( 44 ) ;
	  printint ( mem [p + 1 ].hh.b1 ) ;
	  printchar ( 41 ) ;
	} 
	break ;
      case 7 : 
	if ( mem [p + 1 ].hh .v.LH < 0 ) 
	{
	  printesc ( 66676L ) ;
	  print ( 32 ) ;
	  printdir ( mem [p + 1 ].hh .v.LH + 64 ) ;
	} 
	else {
	    
	  printesc ( 66677L ) ;
	  print ( 32 ) ;
	  printdir ( mem [p + 1 ].hh .v.LH ) ;
	} 
	break ;
      case 6 : 
	{
	  printesc ( 66696L ) ;
	  {
	    strpool [poolptr ]= 46 ;
	    incr ( poolptr ) ;
	  } 
	  println () ;
	  printcurrentstring () ;
	  printesc ( 66666L ) ;
	  print ( 61 ) ;
	  printint ( mem [p + 1 ].cint ) ;
	  println () ;
	  printcurrentstring () ;
	  printesc ( 66667L ) ;
	  print ( 61 ) ;
	  printint ( mem [p + 2 ].cint ) ;
	  println () ;
	  printcurrentstring () ;
	  printesc ( 66459L ) ;
	  if ( mem [p + 3 ].cint == 0 ) 
	  print ( 66697L ) ;
	  else {
	      
	    {
	      strpool [poolptr ]= 46 ;
	      incr ( poolptr ) ;
	    } 
	    shownodelist ( mem [p + 3 ].cint ) ;
	    decr ( poolptr ) ;
	  } 
	  println () ;
	  printcurrentstring () ;
	  printesc ( 66460L ) ;
	  if ( mem [p + 5 ].cint == 0 ) 
	  print ( 66697L ) ;
	  else {
	      
	    {
	      strpool [poolptr ]= 46 ;
	      incr ( poolptr ) ;
	    } 
	    shownodelist ( mem [p + 5 ].cint ) ;
	    decr ( poolptr ) ;
	  } 
	  decr ( poolptr ) ;
	} 
	break ;
	default: 
	print ( 66678L ) ;
	break ;
      } 
      break ;
    case 10 : 
      if ( mem [p ].hh.b1 >= 100 ) 
      {
	printesc ( 65624L ) ;
	if ( mem [p ].hh.b1 == 101 ) 
	printchar ( 99 ) ;
	else if ( mem [p ].hh.b1 == 102 ) 
	printchar ( 120 ) ;
	print ( 65625L ) ;
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
	  
	printesc ( 65620L ) ;
	if ( mem [p ].hh.b1 != 0 ) 
	{
	  printchar ( 40 ) ;
	  if ( mem [p ].hh.b1 < 98 ) 
	  printskipparam ( mem [p ].hh.b1 - 1 ) ;
	  else if ( mem [p ].hh.b1 == 98 ) 
	  printesc ( 65621L ) ;
	  else printesc ( 65622L ) ;
	  printchar ( 41 ) ;
	} 
	if ( mem [p ].hh.b1 != 98 ) 
	{
	  printchar ( 32 ) ;
	  if ( mem [p ].hh.b1 < 98 ) 
	  printspec ( mem [p + 1 ].hh .v.LH , 0 ) ;
	  else printspec ( mem [p + 1 ].hh .v.LH , 65623L ) ;
	} 
      } 
      break ;
    case 11 : 
      if ( mem [p ].hh.b1 != 99 ) 
      {
	printesc ( 65626L ) ;
	if ( mem [p ].hh.b1 != 0 ) 
	printchar ( 32 ) ;
	printscaled ( mem [p + 1 ].cint ) ;
	if ( mem [p ].hh.b1 == 2 ) 
	print ( 65627L ) ;
      } 
      else {
	  
	printesc ( 65628L ) ;
	printscaled ( mem [p + 1 ].cint ) ;
	print ( 65623L ) ;
      } 
      break ;
    case 9 : 
      {
	printesc ( 65629L ) ;
	if ( mem [p ].hh.b1 == 0 ) 
	print ( 65630L ) ;
	else print ( 65631L ) ;
	if ( mem [p + 1 ].cint != 0 ) 
	{
	  print ( 65632L ) ;
	  printscaled ( mem [p + 1 ].cint ) ;
	} 
      } 
      break ;
    case 6 : 
      {
	printfontandchar ( p + 1 ) ;
	print ( 65633L ) ;
	if ( mem [p ].hh.b1 > 1 ) 
	printchar ( 124 ) ;
	fontinshortdisplay = mem [p + 1 ].hh.b0 ;
	shortdisplay ( mem [p + 1 ].hh .v.RH ) ;
	if ( odd ( mem [p ].hh.b1 ) ) 
	printchar ( 124 ) ;
	printchar ( 41 ) ;
      } 
      break ;
    case 12 : 
      {
	printesc ( 65634L ) ;
	printint ( mem [p + 1 ].cint ) ;
      } 
      break ;
    case 7 : 
      {
	printesc ( 65635L ) ;
	if ( mem [p ].hh.b1 > 0 ) 
	{
	  print ( 65636L ) ;
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
    case 4 : 
      {
	printesc ( 65637L ) ;
	if ( mem [p + 1 ].hh .v.LH != 0 ) 
	{
	  printchar ( 115 ) ;
	  printint ( mem [p + 1 ].hh .v.LH ) ;
	} 
	printmark ( mem [p + 1 ].hh .v.RH ) ;
      } 
      break ;
    case 5 : 
      {
	printesc ( 65638L ) ;
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
    case 14 : 
      printstyle ( mem [p ].hh.b1 ) ;
      break ;
    case 15 : 
      {
	printesc ( 65823L ) ;
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
    case 16 : 
    case 17 : 
    case 18 : 
    case 19 : 
    case 20 : 
    case 21 : 
    case 22 : 
    case 23 : 
    case 24 : 
    case 27 : 
    case 26 : 
    case 29 : 
    case 28 : 
    case 30 : 
    case 31 : 
      {
	switch ( mem [p ].hh.b0 ) 
	{case 16 : 
	  printesc ( 66221L ) ;
	  break ;
	case 17 : 
	  printesc ( 66222L ) ;
	  break ;
	case 18 : 
	  printesc ( 66223L ) ;
	  break ;
	case 19 : 
	  printesc ( 66224L ) ;
	  break ;
	case 20 : 
	  printesc ( 66225L ) ;
	  break ;
	case 21 : 
	  printesc ( 66226L ) ;
	  break ;
	case 22 : 
	  printesc ( 66227L ) ;
	  break ;
	case 23 : 
	  printesc ( 66228L ) ;
	  break ;
	case 27 : 
	  printesc ( 66229L ) ;
	  break ;
	case 26 : 
	  printesc ( 66230L ) ;
	  break ;
	case 29 : 
	  printesc ( 65840L ) ;
	  break ;
	case 24 : 
	  {
	    printesc ( 65832L ) ;
	    printdelimiter ( p + 4 ) ;
	  } 
	  break ;
	case 28 : 
	  {
	    printesc ( 65798L ) ;
	    printfamandchar ( p + 4 ) ;
	  } 
	  break ;
	case 30 : 
	  {
	    printesc ( 66231L ) ;
	    printdelimiter ( p + 1 ) ;
	  } 
	  break ;
	case 31 : 
	  {
	    if ( mem [p ].hh.b1 == 0 ) 
	    printesc ( 66232L ) ;
	    else printesc ( 66233L ) ;
	    printdelimiter ( p + 1 ) ;
	  } 
	  break ;
	} 
	if ( mem [p ].hh.b0 < 30 ) 
	{
	  if ( mem [p ].hh.b1 != 0 ) {
	      
	    if ( mem [p ].hh.b1 == 1 ) 
	    printesc ( 66234L ) ;
	    else printesc ( 66235L ) ;
	  } 
	  printsubsidiarydata ( p + 1 , 46 ) ;
	} 
	printsubsidiarydata ( p + 2 , 94 ) ;
	printsubsidiarydata ( p + 3 , 95 ) ;
      } 
      break ;
    case 25 : 
      {
	printesc ( 66236L ) ;
	if ( mem [p + 1 ].cint == 1073741824L ) 
	print ( 66237L ) ;
	else printscaled ( mem [p + 1 ].cint ) ;
	if ( ( mem [p + 4 ].qqqq .b0 != 0 ) || ( mem [p + 4 ].qqqq .b1 != 
	0 ) || ( mem [p + 4 ].qqqq .b2 != 0 ) || ( mem [p + 4 ].qqqq .b3 
	!= 0 ) ) 
	{
	  print ( 66238L ) ;
	  printdelimiter ( p + 4 ) ;
	} 
	if ( ( mem [p + 5 ].qqqq .b0 != 0 ) || ( mem [p + 5 ].qqqq .b1 != 
	0 ) || ( mem [p + 5 ].qqqq .b2 != 0 ) || ( mem [p + 5 ].qqqq .b3 
	!= 0 ) ) 
	{
	  print ( 66239L ) ;
	  printdelimiter ( p + 5 ) ;
	} 
	printsubsidiarydata ( p + 2 , 92 ) ;
	printsubsidiarydata ( p + 3 , 47 ) ;
      } 
      break ;
      default: 
      print ( 65603L ) ;
      break ;
    } 
    p = mem [p ].hh .v.RH ;
  } 
} 
void 
zshowbox ( halfword p ) 
{
  showbox_regmem 
  depththreshold = neweqtbint ( 1049433L ) ;
  breadthmax = neweqtbint ( 1049432L ) ;
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
  if ( mem [p ].hh .v.LH == 0 ) 
  flushlist ( p ) ;
  else decr ( mem [p ].hh .v.LH ) ;
} 
void 
zdeleteglueref ( halfword p ) 
{
  deleteglueref_regmem 
  if ( mem [p ].hh .v.RH == 0 ) 
  freenode ( p , 4 ) ;
  else decr ( mem [p ].hh .v.RH ) ;
} 
void 
zflushnodelist ( halfword p ) 
{
  /* 30 */ flushnodelist_regmem 
  halfword q  ;
  while ( p != 0 ) {
      
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
      case 13 : 
	{
	  flushnodelist ( mem [p + 5 ].hh .v.RH ) ;
	  freenode ( p , 8 ) ;
	  goto lab30 ;
	} 
	break ;
      case 2 : 
	{
	  freenode ( p , 5 ) ;
	  goto lab30 ;
	} 
	break ;
      case 3 : 
	{
	  flushnodelist ( mem [p + 4 ].hh .v.LH ) ;
	  deleteglueref ( mem [p + 4 ].hh .v.RH ) ;
	  freenode ( p , 5 ) ;
	  goto lab30 ;
	} 
	break ;
      case 8 : 
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
	  case 7 : 
	    freenode ( p , 4 ) ;
	    break ;
	  case 6 : 
	    freenode ( p , 8 ) ;
	    break ;
	    default: 
	    confusion ( 66680L ) ;
	    break ;
	  } 
	  goto lab30 ;
	} 
	break ;
      case 10 : 
	{
	  {
	    if ( mem [mem [p + 1 ].hh .v.LH ].hh .v.RH == 0 ) 
	    freenode ( mem [p + 1 ].hh .v.LH , 4 ) ;
	    else decr ( mem [mem [p + 1 ].hh .v.LH ].hh .v.RH ) ;
	  } 
	  if ( mem [p + 1 ].hh .v.RH != 0 ) 
	  flushnodelist ( mem [p + 1 ].hh .v.RH ) ;
	} 
	break ;
      case 11 : 
      case 9 : 
      case 12 : 
	;
	break ;
      case 6 : 
	flushnodelist ( mem [p + 1 ].hh .v.RH ) ;
	break ;
      case 4 : 
	deletetokenref ( mem [p + 1 ].hh .v.RH ) ;
	break ;
      case 7 : 
	{
	  flushnodelist ( mem [p + 1 ].hh .v.LH ) ;
	  flushnodelist ( mem [p + 1 ].hh .v.RH ) ;
	} 
	break ;
      case 5 : 
	flushnodelist ( mem [p + 1 ].cint ) ;
	break ;
      case 14 : 
	{
	  freenode ( p , 3 ) ;
	  goto lab30 ;
	} 
	break ;
      case 15 : 
	{
	  flushnodelist ( mem [p + 1 ].hh .v.LH ) ;
	  flushnodelist ( mem [p + 1 ].hh .v.RH ) ;
	  flushnodelist ( mem [p + 2 ].hh .v.LH ) ;
	  flushnodelist ( mem [p + 2 ].hh .v.RH ) ;
	  freenode ( p , 3 ) ;
	  goto lab30 ;
	} 
	break ;
      case 16 : 
      case 17 : 
      case 18 : 
      case 19 : 
      case 20 : 
      case 21 : 
      case 22 : 
      case 23 : 
      case 24 : 
      case 27 : 
      case 26 : 
      case 29 : 
      case 28 : 
	{
	  if ( mem [p + 1 ].hh .v.RH >= 2 ) 
	  flushnodelist ( mem [p + 1 ].hh .v.LH ) ;
	  if ( mem [p + 2 ].hh .v.RH >= 2 ) 
	  flushnodelist ( mem [p + 2 ].hh .v.LH ) ;
	  if ( mem [p + 3 ].hh .v.RH >= 2 ) 
	  flushnodelist ( mem [p + 3 ].hh .v.LH ) ;
	  if ( mem [p ].hh.b0 == 24 ) 
	  freenode ( p , 5 ) ;
	  else if ( mem [p ].hh.b0 == 28 ) 
	  freenode ( p , 5 ) ;
	  else freenode ( p , 4 ) ;
	  goto lab30 ;
	} 
	break ;
      case 30 : 
      case 31 : 
	{
	  freenode ( p , 4 ) ;
	  goto lab30 ;
	} 
	break ;
      case 25 : 
	{
	  flushnodelist ( mem [p + 2 ].hh .v.LH ) ;
	  flushnodelist ( mem [p + 3 ].hh .v.LH ) ;
	  freenode ( p , 6 ) ;
	  goto lab30 ;
	} 
	break ;
	default: 
	confusion ( 65639L ) ;
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
  while ( p != 0 ) {
      
    words = 1 ;
    if ( ( p >= himemmin ) ) 
    r = getavail () ;
    else switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 13 : 
      {
	r = getnode ( 8 ) ;
	mem [r + 7 ]= mem [p + 7 ];
	mem [r + 6 ]= mem [p + 6 ];
	mem [r + 5 ]= mem [p + 5 ];
	mem [r + 5 ].hh .v.RH = copynodelist ( mem [p + 5 ].hh .v.RH ) ;
	words = 5 ;
      } 
      break ;
    case 2 : 
      {
	r = getnode ( 5 ) ;
	words = 5 ;
      } 
      break ;
    case 3 : 
      {
	r = getnode ( 5 ) ;
	mem [r + 4 ]= mem [p + 4 ];
	incr ( mem [mem [p + 4 ].hh .v.RH ].hh .v.RH ) ;
	mem [r + 4 ].hh .v.LH = copynodelist ( mem [p + 4 ].hh .v.LH ) ;
	words = 4 ;
      } 
      break ;
    case 8 : 
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
      case 7 : 
	{
	  r = getnode ( 4 ) ;
	  words = 4 ;
	} 
	break ;
      case 6 : 
	{
	  r = getnode ( 8 ) ;
	  words = 8 ;
	} 
	break ;
	default: 
	confusion ( 66679L ) ;
	break ;
      } 
      break ;
    case 10 : 
      {
	r = getnode ( 2 ) ;
	incr ( mem [mem [p + 1 ].hh .v.LH ].hh .v.RH ) ;
	mem [r + 1 ].hh .v.LH = mem [p + 1 ].hh .v.LH ;
	mem [r + 1 ].hh .v.RH = copynodelist ( mem [p + 1 ].hh .v.RH ) ;
      } 
      break ;
    case 11 : 
    case 9 : 
    case 12 : 
      {
	r = getnode ( 2 ) ;
	words = 2 ;
      } 
      break ;
    case 6 : 
      {
	r = getnode ( 2 ) ;
	mem [r + 1 ]= mem [p + 1 ];
	mem [r + 1 ].hh .v.RH = copynodelist ( mem [p + 1 ].hh .v.RH ) ;
      } 
      break ;
    case 7 : 
      {
	r = getnode ( 2 ) ;
	mem [r + 1 ].hh .v.LH = copynodelist ( mem [p + 1 ].hh .v.LH ) ;
	mem [r + 1 ].hh .v.RH = copynodelist ( mem [p + 1 ].hh .v.RH ) ;
      } 
      break ;
    case 4 : 
      {
	r = getnode ( 2 ) ;
	incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
	words = 2 ;
      } 
      break ;
    case 5 : 
      {
	r = getnode ( 2 ) ;
	mem [r + 1 ].cint = copynodelist ( mem [p + 1 ].cint ) ;
      } 
      break ;
      default: 
      confusion ( 65640L ) ;
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
  mem [q ].hh .v.RH = 0 ;
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
  switch ( m / ( 118 ) ) 
  {case 0 : 
    print ( 65641L ) ;
    break ;
  case 1 : 
    print ( 65642L ) ;
    break ;
  case 2 : 
    print ( 65643L ) ;
    break ;
  } 
  else if ( m == 0 ) 
  print ( 65644L ) ;
  else switch ( ( - (integer) m ) / ( 118 ) ) 
  {case 0 : 
    print ( 65645L ) ;
    break ;
  case 1 : 
    print ( 65646L ) ;
    break ;
  case 2 : 
    print ( 65629L ) ;
    break ;
  } 
  print ( 65647L ) ;
} 
halfword 
makelocalparnode ( void ) 
{
  register halfword Result; makelocalparnode_regmem 
  halfword p  ;
  p = getnode ( 8 ) ;
  mem [p ].hh.b0 = 8 ;
  mem [p ].hh.b1 = 6 ;
  mem [p ].hh .v.RH = 0 ;
  mem [p + 1 ].cint = neweqtbint ( 1049463L ) ;
  mem [p + 2 ].cint = neweqtbint ( 1049464L ) ;
  if ( newequiv ( 655421L ) == 0 ) 
  {
    mem [p + 3 ].cint = 0 ;
    mem [p + 4 ].cint = 0 ;
  } 
  else {
      
    mem [p + 3 ].cint = copynodelist ( newequiv ( 655421L ) ) ;
    mem [p + 4 ].cint = mem [newequiv ( 655421L ) + 1 ].cint ;
  } 
  if ( newequiv ( 655422L ) == 0 ) 
  {
    mem [p + 5 ].cint = 0 ;
    mem [p + 6 ].cint = 0 ;
  } 
  else {
      
    mem [p + 5 ].cint = copynodelist ( newequiv ( 655422L ) ) ;
    mem [p + 6 ].cint = mem [newequiv ( 655422L ) + 1 ].cint ;
  } 
  mem [p + 7 ].cint = neweqtbint ( 1049481L ) ;
  Result = p ;
  return Result ;
} 
halfword 
znewdir ( smallnumber s ) 
{
  register halfword Result; newdir_regmem 
  halfword p  ;
  p = getnode ( 4 ) ;
  mem [p ].hh.b0 = 8 ;
  mem [p ].hh.b1 = 7 ;
  mem [p + 1 ].hh .v.LH = s ;
  mem [p + 3 ].hh .v.LH = 0 ;
  mem [p + 2 ].hh .v.LH = -1 ;
  mem [p + 1 ].hh .v.RH = curlevel ;
  Result = p ;
  return Result ;
} 
void 
pushnest ( void ) 
{
  pushnest_regmem 
  if ( nestptr > maxneststack ) 
  {
    maxneststack = nestptr ;
    if ( nestptr == nestsize ) 
    overflow ( 65648L , nestsize ) ;
  } 
  nest [nestptr ]= curlist ;
  incr ( nestptr ) ;
  curlist .headfield = getavail () ;
  curlist .tailfield = curlist .headfield ;
  curlist .pgfield = 0 ;
  curlist .mlfield = line ;
  curlist .eTeXauxfield = 0 ;
  curlist .dirsfield = 0 ;
  curlist .mathfield = false ;
  curlist .localparfield = makelocalparnode () ;
  curlist .localparboolfield = false ;
} 
void 
popnest ( void ) 
{
  popnest_regmem 
  if ( curlist .localparfield != 0 ) 
  {
    if ( curlist .localparboolfield ) 
    {
      ;
    } 
    else freenode ( curlist .localparfield , 8 ) ;
  } 
  {
    mem [curlist .headfield ].hh .v.RH = avail ;
    avail = curlist .headfield ;
	;
#ifdef STAT
    decr ( dynused ) ;
#endif /* STAT */
  } 
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
  printnl ( 65624L ) ;
  println () ;
  {register integer for_end; p = nestptr ;for_end = 0 ; if ( p >= for_end) 
  do 
    {
      m = nest [p ].modefield ;
      a = nest [p ].auxfield ;
      printnl ( 65649L ) ;
      printmode ( m ) ;
      print ( 65650L ) ;
      printint ( abs ( nest [p ].mlfield ) ) ;
      if ( m == 119 ) {
	  
	if ( nest [p ].pgfield != 8585216L ) 
	{
	  print ( 65651L ) ;
	  printint ( nest [p ].pgfield % 65536L ) ;
	  print ( 65652L ) ;
	  printint ( nest [p ].pgfield / 4194304L ) ;
	  printchar ( 44 ) ;
	  printint ( ( nest [p ].pgfield / 65536L ) % 64 ) ;
	  printchar ( 41 ) ;
	} 
      } 
      if ( nest [p ].mlfield < 0 ) 
      print ( 65653L ) ;
      if ( p == 0 ) 
      {
	if ( memtop - 2 != pagetail ) 
	{
	  printnl ( 66337L ) ;
	  if ( outputactive ) 
	  print ( 66338L ) ;
	  showbox ( mem [memtop - 2 ].hh .v.RH ) ;
	  if ( pagecontents > 0 ) 
	  {
	    printnl ( 66339L ) ;
	    printtotals () ;
	    printnl ( 66340L ) ;
	    printscaled ( pagesofar [0 ]) ;
	    r = mem [memtop ].hh .v.RH ;
	    while ( r != memtop ) {
		
	      println () ;
	      printesc ( 65616L ) ;
	      t = mem [r ].hh.b1 ;
	      printint ( t ) ;
	      print ( 66341L ) ;
	      if ( neweqtbint ( 1049484L + t ) == 1000 ) 
	      t = mem [r + 3 ].cint ;
	      else t = xovern ( mem [r + 3 ].cint , 1000 ) * neweqtbint ( 
	      1049484L + t ) ;
	      printscaled ( t ) ;
	      if ( mem [r ].hh.b0 == 1 ) 
	      {
		q = memtop - 2 ;
		t = 0 ;
		do {
		    q = mem [q ].hh .v.RH ;
		  if ( ( mem [q ].hh.b0 == 3 ) && ( mem [q ].hh.b1 == mem 
		  [r ].hh.b1 ) ) 
		  incr ( t ) ;
		} while ( ! ( q == mem [r + 1 ].hh .v.LH ) ) ;
		print ( 66342L ) ;
		printint ( t ) ;
		print ( 66343L ) ;
	      } 
	      r = mem [r ].hh .v.RH ;
	    } 
	  } 
	} 
	if ( mem [memtop - 1 ].hh .v.RH != 0 ) 
	printnl ( 65654L ) ;
      } 
      showbox ( mem [nest [p ].headfield ].hh .v.RH ) ;
      switch ( abs ( m ) / ( 118 ) ) 
      {case 0 : 
	{
	  printnl ( 65655L ) ;
	  if ( a .cint <= -65536000L ) 
	  print ( 65656L ) ;
	  else printscaled ( a .cint ) ;
	  if ( nest [p ].pgfield != 0 ) 
	  {
	    print ( 65657L ) ;
	    printint ( nest [p ].pgfield ) ;
	    print ( 65658L ) ;
	    if ( nest [p ].pgfield != 1 ) 
	    printchar ( 115 ) ;
	  } 
	} 
	break ;
      case 1 : 
	{
	  printnl ( 65659L ) ;
	  printint ( a .hh .v.LH ) ;
	  if ( m > 0 ) {
	      
	    if ( a .hh .v.RH > 0 ) 
	    {
	      print ( 65660L ) ;
	      printint ( a .hh .v.RH ) ;
	    } 
	  } 
	} 
	break ;
      case 2 : 
	if ( a .cint != 0 ) 
	{
	  print ( 65661L ) ;
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
    printesc ( 65706L ) ;
    break ;
  case 1 : 
    printesc ( 65707L ) ;
    break ;
  case 2 : 
    printesc ( 65708L ) ;
    break ;
  case 3 : 
    printesc ( 65709L ) ;
    break ;
  case 4 : 
    printesc ( 65710L ) ;
    break ;
  case 5 : 
    printesc ( 65711L ) ;
    break ;
  case 6 : 
    printesc ( 65712L ) ;
    break ;
  case 7 : 
    printesc ( 65713L ) ;
    break ;
  case 8 : 
    printesc ( 65714L ) ;
    break ;
  case 9 : 
    printesc ( 65715L ) ;
    break ;
  case 10 : 
    printesc ( 65716L ) ;
    break ;
  case 11 : 
    printesc ( 65717L ) ;
    break ;
  case 12 : 
    printesc ( 65718L ) ;
    break ;
  case 13 : 
    printesc ( 65719L ) ;
    break ;
  case 14 : 
    printesc ( 65720L ) ;
    break ;
  case 15 : 
    printesc ( 65721L ) ;
    break ;
  case 16 : 
    printesc ( 65722L ) ;
    break ;
  case 17 : 
    printesc ( 65723L ) ;
    break ;
  case 18 : 
    printesc ( 65724L ) ;
    break ;
  case 19 : 
    printesc ( 65725L ) ;
    break ;
  case 20 : 
    printesc ( 65726L ) ;
    break ;
  case 21 : 
    printesc ( 65727L ) ;
    break ;
  case 22 : 
    printesc ( 65728L ) ;
    break ;
  case 23 : 
    printesc ( 65729L ) ;
    break ;
  case 24 : 
    printesc ( 65730L ) ;
    break ;
  case 25 : 
    printesc ( 65731L ) ;
    break ;
  case 26 : 
    printesc ( 65732L ) ;
    break ;
  case 27 : 
    printesc ( 65733L ) ;
    break ;
  case 28 : 
    printesc ( 65734L ) ;
    break ;
  case 29 : 
    printesc ( 65735L ) ;
    break ;
  case 30 : 
    printesc ( 65736L ) ;
    break ;
  case 31 : 
    printesc ( 65737L ) ;
    break ;
  case 32 : 
    printesc ( 65738L ) ;
    break ;
  case 33 : 
    printesc ( 65739L ) ;
    break ;
  case 34 : 
    printesc ( 65740L ) ;
    break ;
  case 35 : 
    printesc ( 65741L ) ;
    break ;
  case 36 : 
    printesc ( 65742L ) ;
    break ;
  case 37 : 
    printesc ( 65743L ) ;
    break ;
  case 38 : 
    printesc ( 65744L ) ;
    break ;
  case 39 : 
    printesc ( 65745L ) ;
    break ;
  case 40 : 
    printesc ( 65746L ) ;
    break ;
  case 41 : 
    printesc ( 65747L ) ;
    break ;
  case 42 : 
    printesc ( 65748L ) ;
    break ;
  case 43 : 
    printesc ( 65749L ) ;
    break ;
  case 44 : 
    printesc ( 65750L ) ;
    break ;
  case 45 : 
    printesc ( 65751L ) ;
    break ;
  case 46 : 
    printesc ( 65752L ) ;
    break ;
  case 47 : 
    printesc ( 65753L ) ;
    break ;
  case 48 : 
    printesc ( 65754L ) ;
    break ;
  case 49 : 
    printesc ( 65755L ) ;
    break ;
  case 50 : 
    printesc ( 65756L ) ;
    break ;
  case 51 : 
    printesc ( 65757L ) ;
    break ;
  case 52 : 
    printesc ( 65758L ) ;
    break ;
  case 53 : 
    printesc ( 65759L ) ;
    break ;
  case 54 : 
    printesc ( 65760L ) ;
    break ;
  case 61 : 
    printesc ( 66710L ) ;
    break ;
  case 62 : 
    printesc ( 66711L ) ;
    break ;
  case 63 : 
    printesc ( 66712L ) ;
    break ;
  case 64 : 
    printesc ( 66713L ) ;
    break ;
  case 65 : 
    printesc ( 66714L ) ;
    break ;
  case 66 : 
    printesc ( 66715L ) ;
    break ;
  case 67 : 
    printesc ( 66716L ) ;
    break ;
  case 68 : 
    printesc ( 66717L ) ;
    break ;
  case 69 : 
    printesc ( 66718L ) ;
    break ;
    default: 
    print ( 65761L ) ;
    break ;
  } 
} 
void 
begindiagnostic ( void ) 
{
  begindiagnostic_regmem 
  oldsetting = selector ;
  if ( ( neweqtbint ( 1049437L ) <= 0 ) && ( selector == 19 ) ) 
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
  printnl ( 65624L ) ;
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
    printesc ( 65764L ) ;
    break ;
  case 1 : 
    printesc ( 65765L ) ;
    break ;
  case 2 : 
    printesc ( 65766L ) ;
    break ;
  case 3 : 
    printesc ( 65767L ) ;
    break ;
  case 4 : 
    printesc ( 65768L ) ;
    break ;
  case 5 : 
    printesc ( 65769L ) ;
    break ;
  case 6 : 
    printesc ( 65770L ) ;
    break ;
  case 7 : 
    printesc ( 65771L ) ;
    break ;
  case 8 : 
    printesc ( 65772L ) ;
    break ;
  case 9 : 
    printesc ( 65773L ) ;
    break ;
  case 10 : 
    printesc ( 65774L ) ;
    break ;
  case 11 : 
    printesc ( 65775L ) ;
    break ;
  case 12 : 
    printesc ( 65776L ) ;
    break ;
  case 13 : 
    printesc ( 65777L ) ;
    break ;
  case 14 : 
    printesc ( 65778L ) ;
    break ;
  case 15 : 
    printesc ( 65779L ) ;
    break ;
  case 16 : 
    printesc ( 65780L ) ;
    break ;
  case 17 : 
    printesc ( 65781L ) ;
    break ;
  case 18 : 
    printesc ( 65782L ) ;
    break ;
  case 19 : 
    printesc ( 65783L ) ;
    break ;
  case 20 : 
    printesc ( 65784L ) ;
    break ;
  case 21 : 
    printesc ( 65785L ) ;
    break ;
  case 22 : 
    printesc ( 65786L ) ;
    break ;
  case 23 : 
    printesc ( 65787L ) ;
    break ;
  case 24 : 
    printesc ( 65788L ) ;
    break ;
    default: 
    print ( 65789L ) ;
    break ;
  } 
} 
memoryword 
ziniteqtbentry ( halfword p ) 
{
  register memoryword Result; initeqtbentry_regmem 
  memoryword mw  ;
  if ( ( p >= 1 ) && ( p <= 393229L ) ) 
  {
    mw .hh .v.RH = 0 ;
    mw .hh.b0 = 118 ;
    mw .hh.b1 = 0 ;
  } 
  else if ( ( p >= 393230L ) && ( p <= 524321L ) ) 
  {
    mw .hh .v.RH = membot ;
    mw .hh.b0 = 134 ;
    mw .hh.b1 = 1 ;
  } 
  else if ( ( p >= 524320L ) && ( p < 524325L ) ) 
  {
    mw .hh .v.RH = 0 ;
    mw .hh.b0 = 135 ;
    mw .hh.b1 = 1 ;
  } 
  else if ( ( p >= 524325L ) && ( p <= 655420L ) ) 
  {
    mw .hh .v.RH = 0 ;
    mw .hh.b0 = 118 ;
    mw .hh.b1 = 0 ;
  } 
  else if ( ( p >= 655423L ) && ( p <= 720958L ) ) 
  {
    mw .hh .v.RH = 0 ;
    mw .hh.b0 = 136 ;
    mw .hh.b1 = 1 ;
  } 
  else if ( ( p >= 720959L ) && ( p <= 721727L ) ) 
  {
    mw .hh .v.RH = 0 ;
    mw .hh.b0 = 137 ;
    mw .hh.b1 = 1 ;
  } 
  else if ( ( p >= 721728L ) && ( p <= 787263L ) ) 
  {
    mw .hh .v.RH = 12 ;
    mw .hh.b0 = 137 ;
    mw .hh.b1 = 1 ;
  } 
  else if ( ( p >= 787264L ) && ( p <= 918335L ) ) 
  {
    mw .hh .v.RH = 0 ;
    mw .hh.b0 = 137 ;
    mw .hh.b1 = 1 ;
  } 
  else if ( ( p >= 918336L ) && ( p <= 983871L ) ) 
  {
    mw .hh .v.RH = 1000 ;
    mw .hh.b0 = 137 ;
    mw .hh.b1 = 1 ;
  } 
  else if ( ( p >= 983872L ) && ( p <= 1049407L ) ) 
  {
    mw .hh .v.RH = p - 983872L ;
    mw .hh.b0 = 137 ;
    mw .hh.b1 = 1 ;
  } 
  else if ( ( p >= 1049408L ) && ( p <= 1115019L ) ) 
  {
    setintzero ( mw , 0 ) ;
    setintone ( mw , 0 ) ;
  } 
  else if ( ( p >= 1115020L ) && ( p <= 1180555L ) ) 
  {
    setintzero ( mw , -1 ) ;
    setintone ( mw , -1 ) ;
  } 
  else if ( ( p >= 1180556L ) && ( p <= 1246116L ) ) 
  {
    setintzero ( mw , 0 ) ;
    setintone ( mw , 0 ) ;
  } 
  else {
      
    mw .hh .v.RH = 0 ;
    mw .hh.b0 = 118 ;
    mw .hh.b1 = 0 ;
  } 
  Result = mw ;
  return Result ;
} 
void 
zprintcmdchr ( quarterword cmd , halfword chrcode ) 
{
  printcmdchr_regmem 
  integer n  ;
  switch ( cmd ) 
  {case 1 : 
    {
      print ( 65862L ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 2 : 
    {
      print ( 65863L ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 3 : 
    {
      print ( 65864L ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 6 : 
    {
      print ( 65865L ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 7 : 
    {
      print ( 65866L ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 8 : 
    {
      print ( 65867L ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 9 : 
    print ( 65868L ) ;
    break ;
  case 10 : 
    {
      print ( 65869L ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 11 : 
    {
      print ( 65870L ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 12 : 
    {
      print ( 65871L ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 78 : 
  case 79 : 
    if ( chrcode < 393248L ) 
    printskipparam ( chrcode - 393230L ) ;
    else if ( chrcode < 458784L ) 
    {
      printesc ( 65681L ) ;
      printint ( chrcode - 393248L ) ;
    } 
    else {
	
      printesc ( 65682L ) ;
      printint ( chrcode - 458784L ) ;
    } 
    break ;
  case 75 : 
    if ( chrcode >= 589885L ) 
    {
      printesc ( 65693L ) ;
      printint ( chrcode - 589885L ) ;
    } 
    else switch ( chrcode ) 
    {case 524325 : 
      printesc ( 65684L ) ;
      break ;
    case 524326 : 
      printesc ( 65685L ) ;
      break ;
    case 524327 : 
      printesc ( 65686L ) ;
      break ;
    case 524328 : 
      printesc ( 65687L ) ;
      break ;
    case 524329 : 
      printesc ( 65688L ) ;
      break ;
    case 524330 : 
      printesc ( 65689L ) ;
      break ;
    case 524331 : 
      printesc ( 65690L ) ;
      break ;
    case 524332 : 
      printesc ( 65691L ) ;
      break ;
    case 524333 : 
      printesc ( 66709L ) ;
      break ;
      default: 
      printesc ( 65692L ) ;
      break ;
    } 
    break ;
  case 76 : 
    if ( chrcode < 1049484L ) 
    printparam ( chrcode - 1049408L ) ;
    else {
	
      printesc ( 65762L ) ;
      printint ( chrcode - 1049484L ) ;
    } 
    break ;
  case 77 : 
    if ( chrcode < 1180581L ) 
    printlengthparam ( chrcode - 1180556L ) ;
    else {
	
      printesc ( 65790L ) ;
      printint ( chrcode - 1180581L ) ;
    } 
    break ;
  case 45 : 
    printesc ( 65798L ) ;
    break ;
  case 96 : 
    printesc ( 65799L ) ;
    break ;
  case 40 : 
    printesc ( 65800L ) ;
    break ;
  case 41 : 
    printesc ( 65801L ) ;
    break ;
  case 80 : 
    if ( chrcode == 0 ) 
    printesc ( 65810L ) ;
    else if ( chrcode == 1 ) 
    printesc ( 65811L ) ;
    else if ( chrcode == 2 ) 
    printesc ( 65812L ) ;
    else if ( chrcode == 3 ) 
    printesc ( 65813L ) ;
    else if ( chrcode == 4 ) 
    printesc ( 65814L ) ;
    else print ( 65842L ) ;
    break ;
  case 61 : 
    printesc ( 65802L ) ;
    break ;
  case 42 : 
    printesc ( 65830L ) ;
    break ;
  case 16 : 
    printesc ( 65803L ) ;
    break ;
  case 68 : 
    if ( curchr == 0 ) 
    printesc ( 65818L ) ;
    else printesc ( 65836L ) ;
    break ;
  case 124 : 
    printesc ( 65794L ) ;
    break ;
  case 91 : 
    printesc ( 65809L ) ;
    break ;
  case 15 : 
    printesc ( 65804L ) ;
    break ;
  case 98 : 
    printesc ( 65806L ) ;
    break ;
  case 67 : 
    printesc ( 65795L ) ;
    break ;
  case 62 : 
    printesc ( 65807L ) ;
    break ;
  case 64 : 
    printesc ( 32 ) ;
    break ;
  case 119 : 
    if ( chrcode == 0 ) 
    printesc ( 65808L ) ;
    else printesc ( 66101L ) ;
    break ;
  case 32 : 
    printesc ( 65815L ) ;
    break ;
  case 36 : 
    printesc ( 65816L ) ;
    break ;
  case 39 : 
    printesc ( 65817L ) ;
    break ;
  case 37 : 
    printesc ( 65616L ) ;
    break ;
  case 44 : 
    printesc ( 47 ) ;
    break ;
  case 18 : 
    {
      printesc ( 65637L ) ;
      if ( chrcode > 0 ) 
      printchar ( 115 ) ;
    } 
    break ;
  case 46 : 
    printesc ( 65819L ) ;
    break ;
  case 17 : 
    printesc ( 65820L ) ;
    break ;
  case 54 : 
    printesc ( 65823L ) ;
    break ;
  case 97 : 
    printesc ( 65824L ) ;
    break ;
  case 34 : 
    printesc ( 65825L ) ;
    break ;
  case 65 : 
    printesc ( 65826L ) ;
    break ;
  case 120 : 
    printesc ( 65827L ) ;
    break ;
  case 55 : 
    printesc ( 65621L ) ;
    break ;
  case 63 : 
    printesc ( 65828L ) ;
    break ;
  case 66 : 
    printesc ( 65832L ) ;
    break ;
  case 102 : 
    if ( chrcode == 0 ) 
    printesc ( 65834L ) ;
    else printesc ( 66760L ) ;
    break ;
  case 0 : 
    printesc ( 65835L ) ;
    break ;
  case 104 : 
    printesc ( 65837L ) ;
    break ;
  case 83 : 
    printesc ( 65831L ) ;
    break ;
  case 87 : 
    switch ( chrcode ) 
    {case 524320 : 
      printesc ( 65829L ) ;
      break ;
    case 524321 : 
      printesc ( 66793L ) ;
      break ;
    case 524322 : 
      printesc ( 66794L ) ;
      break ;
    case 524323 : 
      printesc ( 66795L ) ;
      break ;
    case 524324 : 
      printesc ( 66796L ) ;
      break ;
    } 
    break ;
  case 126 : 
    if ( chrcode == 0 ) 
    printesc ( 65838L ) ;
    else if ( chrcode == 1 ) 
    printesc ( 66748L ) ;
    else printesc ( 66749L ) ;
    break ;
  case 74 : 
    {
      printesc ( 65693L ) ;
      if ( chrcode != membot ) 
      printsanum ( chrcode ) ;
    } 
    break ;
  case 38 : 
    printesc ( 65638L ) ;
    break ;
  case 33 : 
    printesc ( 65839L ) ;
    break ;
  case 56 : 
    printesc ( 65840L ) ;
    break ;
  case 35 : 
    printesc ( 65841L ) ;
    break ;
  case 13 : 
    printesc ( 65906L ) ;
    break ;
  case 121 : 
    if ( chrcode == 0 ) 
    printesc ( 65938L ) ;
    else if ( chrcode == 2 ) 
    printesc ( 66758L ) ;
    else printesc ( 65939L ) ;
    break ;
  case 127 : 
    {
      switch ( ( chrcode % 5 ) ) 
      {case 1 : 
	printesc ( 65941L ) ;
	break ;
      case 2 : 
	printesc ( 65942L ) ;
	break ;
      case 3 : 
	printesc ( 65943L ) ;
	break ;
      case 4 : 
	printesc ( 65944L ) ;
	break ;
	default: 
	printesc ( 65940L ) ;
	break ;
      } 
      if ( chrcode >= 5 ) 
      printchar ( 115 ) ;
    } 
    break ;
  case 92 : 
    {
      if ( ( chrcode < membot ) || ( chrcode > membot + 23 ) ) 
      cmd = ( mem [chrcode ].hh.b0 / 256 ) ;
      else {
	  
	cmd = chrcode - membot ;
	chrcode = 0 ;
      } 
      if ( cmd == 0 ) 
      printesc ( 65762L ) ;
      else if ( cmd == 1 ) 
      printesc ( 65790L ) ;
      else if ( cmd == 2 ) 
      printesc ( 65681L ) ;
      else printesc ( 65682L ) ;
      if ( chrcode != 0 ) 
      printsanum ( chrcode ) ;
    } 
    break ;
  case 82 : 
    if ( chrcode == 1 ) 
    printesc ( 65984L ) ;
    else printesc ( 65983L ) ;
    break ;
  case 85 : 
    if ( chrcode == 0 ) 
    printesc ( 65985L ) ;
    else if ( chrcode == 2 ) 
    printesc ( 66754L ) ;
    else printesc ( 65986L ) ;
    break ;
  case 86 : 
    if ( chrcode == 1 ) 
    printesc ( 65987L ) ;
    else if ( chrcode == 3 ) 
    printesc ( 65988L ) ;
    else if ( chrcode == 2 ) 
    printesc ( 65989L ) ;
    else print ( 65995L ) ;
    break ;
  case 73 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 65990L ) ;
      break ;
    case 1 : 
      printesc ( 65991L ) ;
      break ;
    case 2 : 
      printesc ( 65992L ) ;
      break ;
    case 4 : 
      printesc ( 65993L ) ;
      break ;
    case 3 : 
      printesc ( 66698L ) ;
      break ;
    case 6 : 
      printesc ( 66699L ) ;
      break ;
    case 7 : 
      printesc ( 66700L ) ;
      break ;
    case 11 : 
      printesc ( 66701L ) ;
      break ;
    case 8 : 
      printesc ( 66702L ) ;
      break ;
    case 9 : 
      printesc ( 66703L ) ;
      break ;
    case 10 : 
      printesc ( 66704L ) ;
      break ;
    case 12 : 
      printesc ( 66733L ) ;
      break ;
    case 13 : 
      printesc ( 66734L ) ;
      break ;
    case 14 : 
      printesc ( 66735L ) ;
      break ;
    case 15 : 
      printesc ( 66736L ) ;
      break ;
    case 16 : 
      printesc ( 66737L ) ;
      break ;
    case 19 : 
      printesc ( 66738L ) ;
      break ;
    case 20 : 
      printesc ( 66739L ) ;
      break ;
    case 21 : 
      printesc ( 66740L ) ;
      break ;
    case 22 : 
      printesc ( 66741L ) ;
      break ;
    case 23 : 
      printesc ( 66742L ) ;
      break ;
    case 24 : 
      printesc ( 66743L ) ;
      break ;
    case 25 : 
      printesc ( 66744L ) ;
      break ;
    case 30 : 
      printesc ( 66769L ) ;
      break ;
    case 31 : 
      printesc ( 66770L ) ;
      break ;
    case 32 : 
      printesc ( 66771L ) ;
      break ;
    case 33 : 
      printesc ( 66772L ) ;
      break ;
    case 17 : 
      printesc ( 66776L ) ;
      break ;
    case 18 : 
      printesc ( 66777L ) ;
      break ;
    case 26 : 
      printesc ( 66778L ) ;
      break ;
    case 27 : 
      printesc ( 66779L ) ;
      break ;
    case 28 : 
      printesc ( 66780L ) ;
      break ;
    case 29 : 
      printesc ( 66781L ) ;
      break ;
      default: 
      printesc ( 65994L ) ;
      break ;
    } 
    break ;
  case 125 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 66060L ) ;
      break ;
    case 1 : 
      printesc ( 66061L ) ;
      break ;
    case 2 : 
      printesc ( 66062L ) ;
      break ;
    case 3 : 
      printesc ( 66063L ) ;
      break ;
    case 4 : 
      printesc ( 66064L ) ;
      break ;
    case 5 : 
      printesc ( 66065L ) ;
      break ;
    case 6 : 
      printesc ( 66066L ) ;
      break ;
    case 7 : 
      printesc ( 66067L ) ;
      break ;
    case 8 : 
      printesc ( 66068L ) ;
      break ;
    case 9 : 
      printesc ( 66705L ) ;
      break ;
    case 10 : 
      printesc ( 66706L ) ;
      break ;
    case 11 : 
      printesc ( 66707L ) ;
      break ;
      default: 
      printesc ( 65545L ) ;
      break ;
    } 
    break ;
  case 122 : 
    {
      if ( chrcode >= 32 ) 
      printesc ( 66101L ) ;
      switch ( chrcode % 32 ) 
      {case 1 : 
	printesc ( 66085L ) ;
	break ;
      case 2 : 
	printesc ( 66086L ) ;
	break ;
      case 3 : 
	printesc ( 66087L ) ;
	break ;
      case 4 : 
	printesc ( 66088L ) ;
	break ;
      case 5 : 
	printesc ( 66089L ) ;
	break ;
      case 6 : 
	printesc ( 66090L ) ;
	break ;
      case 7 : 
	printesc ( 66091L ) ;
	break ;
      case 8 : 
	printesc ( 66092L ) ;
	break ;
      case 9 : 
	printesc ( 66093L ) ;
	break ;
      case 10 : 
	printesc ( 66094L ) ;
	break ;
      case 11 : 
	printesc ( 66095L ) ;
	break ;
      case 12 : 
	printesc ( 66096L ) ;
	break ;
      case 13 : 
	printesc ( 66097L ) ;
	break ;
      case 14 : 
	printesc ( 66098L ) ;
	break ;
      case 15 : 
	printesc ( 66099L ) ;
	break ;
      case 16 : 
	printesc ( 66100L ) ;
	break ;
      case 17 : 
	printesc ( 66761L ) ;
	break ;
      case 18 : 
	printesc ( 66762L ) ;
	break ;
      case 19 : 
	printesc ( 66763L ) ;
	break ;
	default: 
	printesc ( 66084L ) ;
	break ;
      } 
    } 
    break ;
  case 123 : 
    if ( chrcode == 2 ) 
    printesc ( 65597L ) ;
    else if ( chrcode == 4 ) 
    printesc ( 66102L ) ;
    else printesc ( 66103L ) ;
    break ;
  case 4 : 
    if ( chrcode == 65537L ) 
    printesc ( 66254L ) ;
    else {
	
      print ( 66258L ) ;
      print ( chrcode ) ;
    } 
    break ;
  case 5 : 
    if ( chrcode == 65538L ) 
    printesc ( 66255L ) ;
    else printesc ( 66256L ) ;
    break ;
  case 84 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 66326L ) ;
      break ;
    case 1 : 
      printesc ( 66327L ) ;
      break ;
    case 2 : 
      printesc ( 66328L ) ;
      break ;
    case 3 : 
      printesc ( 66329L ) ;
      break ;
    case 4 : 
      printesc ( 66330L ) ;
      break ;
    case 5 : 
      printesc ( 66331L ) ;
      break ;
    case 6 : 
      printesc ( 66332L ) ;
      break ;
      default: 
      printesc ( 66333L ) ;
      break ;
    } 
    break ;
  case 14 : 
    if ( chrcode == 1 ) 
    printesc ( 66383L ) ;
    else printesc ( 66382L ) ;
    break ;
  case 26 : 
    switch ( chrcode ) 
    {case 4 : 
      printesc ( 66384L ) ;
      break ;
    case 0 : 
      printesc ( 66385L ) ;
      break ;
    case 1 : 
      printesc ( 66386L ) ;
      break ;
    case 2 : 
      printesc ( 66387L ) ;
      break ;
      default: 
      printesc ( 66388L ) ;
      break ;
    } 
    break ;
  case 27 : 
    switch ( chrcode ) 
    {case 4 : 
      printesc ( 66389L ) ;
      break ;
    case 0 : 
      printesc ( 66390L ) ;
      break ;
    case 1 : 
      printesc ( 66391L ) ;
      break ;
    case 2 : 
      printesc ( 66392L ) ;
      break ;
      default: 
      printesc ( 66393L ) ;
      break ;
    } 
    break ;
  case 28 : 
    printesc ( 65622L ) ;
    break ;
  case 29 : 
    printesc ( 65626L ) ;
    break ;
  case 30 : 
    printesc ( 65628L ) ;
    break ;
  case 21 : 
    if ( chrcode == 1 ) 
    printesc ( 66411L ) ;
    else printesc ( 66412L ) ;
    break ;
  case 22 : 
    if ( chrcode == 1 ) 
    printesc ( 66413L ) ;
    else printesc ( 66414L ) ;
    break ;
  case 20 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 65695L ) ;
      break ;
    case 1 : 
      printesc ( 66415L ) ;
      break ;
    case 2 : 
      printesc ( 66416L ) ;
      break ;
    case 3 : 
      printesc ( 66321L ) ;
      break ;
    case 4 : 
      printesc ( 66417L ) ;
      break ;
    case 5 : 
      printesc ( 66323L ) ;
      break ;
      default: 
      printesc ( 66418L ) ;
      break ;
    } 
    break ;
  case 31 : 
    if ( chrcode == 100 ) 
    printesc ( 66420L ) ;
    else if ( chrcode == 101 ) 
    printesc ( 66421L ) ;
    else if ( chrcode == 102 ) 
    printesc ( 66422L ) ;
    else printesc ( 66419L ) ;
    break ;
  case 43 : 
    if ( chrcode == 0 ) 
    printesc ( 66439L ) ;
    else printesc ( 66438L ) ;
    break ;
  case 25 : 
    if ( chrcode == 10 ) 
    printesc ( 66450L ) ;
    else if ( chrcode == 11 ) 
    printesc ( 66449L ) ;
    else printesc ( 66448L ) ;
    break ;
  case 23 : 
    if ( chrcode == 1 ) 
    printesc ( 66452L ) ;
    else printesc ( 66451L ) ;
    break ;
  case 24 : 
    if ( chrcode == 1 ) 
    printesc ( 66454L ) ;
    else if ( chrcode == 2 ) 
    printesc ( 66791L ) ;
    else if ( chrcode == 3 ) 
    printesc ( 66792L ) ;
    else printesc ( 66453L ) ;
    break ;
  case 47 : 
    if ( chrcode == 1 ) 
    printesc ( 45 ) ;
    else printesc ( 65635L ) ;
    break ;
  case 69 : 
    if ( chrcode == 0 ) 
    printesc ( 66459L ) ;
    else printesc ( 66460L ) ;
    break ;
  case 48 : 
    if ( chrcode == 1 ) 
    printesc ( 66488L ) ;
    else printesc ( 66487L ) ;
    break ;
  case 50 : 
    switch ( chrcode ) 
    {case 16 : 
      printesc ( 66221L ) ;
      break ;
    case 17 : 
      printesc ( 66222L ) ;
      break ;
    case 18 : 
      printesc ( 66223L ) ;
      break ;
    case 19 : 
      printesc ( 66224L ) ;
      break ;
    case 20 : 
      printesc ( 66225L ) ;
      break ;
    case 21 : 
      printesc ( 66226L ) ;
      break ;
    case 22 : 
      printesc ( 66227L ) ;
      break ;
    case 23 : 
      printesc ( 66228L ) ;
      break ;
    case 26 : 
      printesc ( 66230L ) ;
      break ;
      default: 
      printesc ( 66229L ) ;
      break ;
    } 
    break ;
  case 51 : 
    if ( chrcode == 1 ) 
    printesc ( 66234L ) ;
    else if ( chrcode == 2 ) 
    printesc ( 66235L ) ;
    else printesc ( 66489L ) ;
    break ;
  case 53 : 
    printstyle ( chrcode ) ;
    break ;
  case 52 : 
    switch ( chrcode ) 
    {case 1 : 
      printesc ( 66508L ) ;
      break ;
    case 2 : 
      printesc ( 66509L ) ;
      break ;
    case 3 : 
      printesc ( 66510L ) ;
      break ;
    case 4 : 
      printesc ( 66511L ) ;
      break ;
    case 5 : 
      printesc ( 66512L ) ;
      break ;
      default: 
      printesc ( 66507L ) ;
      break ;
    } 
    break ;
  case 49 : 
    if ( chrcode == 30 ) 
    printesc ( 66231L ) ;
    else if ( chrcode == 1 ) 
    printesc ( 66233L ) ;
    else printesc ( 66232L ) ;
    break ;
  case 99 : 
    if ( chrcode == 1 ) 
    printesc ( 66532L ) ;
    else if ( chrcode == 2 ) 
    printesc ( 66533L ) ;
    else if ( chrcode == 8 ) 
    printesc ( 66546L ) ;
    else printesc ( 66534L ) ;
    break ;
  case 103 : 
    if ( chrcode == 0 ) 
    printesc ( 66535L ) ;
    else if ( chrcode == 1 ) 
    printesc ( 66536L ) ;
    else if ( chrcode == 2 ) 
    printesc ( 66537L ) ;
    else printesc ( 66538L ) ;
    break ;
  case 100 : 
    if ( chrcode != 0 ) 
    printesc ( 66556L ) ;
    else printesc ( 66555L ) ;
    break ;
  case 101 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 66557L ) ;
      break ;
    case 1 : 
      printesc ( 66558L ) ;
      break ;
    case 3 : 
      printesc ( 66560L ) ;
      break ;
    case 4 : 
      printesc ( 66561L ) ;
      break ;
    case 5 : 
      printesc ( 66562L ) ;
      break ;
    case 6 : 
      printesc ( 66563L ) ;
      break ;
      default: 
      printesc ( 66564L ) ;
      break ;
    } 
    break ;
  case 70 : 
    {
      printesc ( 65803L ) ;
      printhex ( chrcode ) ;
    } 
    break ;
  case 71 : 
    {
      printesc ( 65820L ) ;
      printhex ( chrcode ) ;
    } 
    break ;
  case 88 : 
    if ( chrcode == 721728L ) 
    printesc ( 65701L ) ;
    else if ( chrcode == 983872L ) 
    printesc ( 65705L ) ;
    else if ( chrcode == 787264L ) 
    printesc ( 65702L ) ;
    else if ( chrcode == 852800L ) 
    printesc ( 65703L ) ;
    else if ( chrcode == 918336L ) 
    printesc ( 65704L ) ;
    else printesc ( 65763L ) ;
    break ;
  case 89 : 
    printsize ( chrcode - 720960L ) ;
    break ;
  case 105 : 
    if ( chrcode == 1 ) 
    printesc ( 66309L ) ;
    else printesc ( 66297L ) ;
    break ;
  case 81 : 
    if ( chrcode == 0 ) 
    printesc ( 66588L ) ;
    else printesc ( 66589L ) ;
    break ;
  case 90 : 
    {
      print ( 66601L ) ;
      slowprint ( fonttables [chrcode ][ 10 ].cint ) ;
      if ( fonttables [chrcode ][ 6 ].cint != fonttables [chrcode ][ 7 ]
      .cint ) 
      {
	print ( 66069L ) ;
	printscaled ( fonttables [chrcode ][ 6 ].cint ) ;
	print ( 65683L ) ;
      } 
    } 
    break ;
  case 106 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 65558L ) ;
      break ;
    case 1 : 
      printesc ( 65559L ) ;
      break ;
    case 2 : 
      printesc ( 65560L ) ;
      break ;
      default: 
      printesc ( 66602L ) ;
      break ;
    } 
    break ;
  case 60 : 
    if ( chrcode == 0 ) 
    printesc ( 66604L ) ;
    else printesc ( 66603L ) ;
    break ;
  case 58 : 
    if ( chrcode == 0 ) 
    printesc ( 66605L ) ;
    else printesc ( 66606L ) ;
    break ;
  case 57 : 
    if ( chrcode == 787264L ) 
    printesc ( 66612L ) ;
    else printesc ( 66613L ) ;
    break ;
  case 19 : 
    switch ( chrcode ) 
    {case 1 : 
      printesc ( 66615L ) ;
      break ;
    case 2 : 
      printesc ( 66616L ) ;
      break ;
    case 3 : 
      printesc ( 66617L ) ;
      break ;
    case 4 : 
      printesc ( 66745L ) ;
      break ;
    case 5 : 
      printesc ( 66747L ) ;
      break ;
    case 6 : 
      printesc ( 66750L ) ;
      break ;
      default: 
      printesc ( 66614L ) ;
      break ;
    } 
    break ;
  case 118 : 
    print ( 66624L ) ;
    break ;
  case 128 : 
  case 129 : 
  case 130 : 
  case 131 : 
    {
      n = cmd - 128 ;
      if ( mem [mem [chrcode ].hh .v.RH ].hh .v.LH == 917505L ) 
      n = n + 4 ;
      if ( odd ( n / 4 ) ) 
      printesc ( 66546L ) ;
      if ( odd ( n ) ) 
      printesc ( 66532L ) ;
      if ( odd ( n / 2 ) ) 
      printesc ( 66533L ) ;
      if ( n > 0 ) 
      printchar ( 32 ) ;
      print ( 66625L ) ;
    } 
    break ;
  case 132 : 
    printesc ( 66626L ) ;
    break ;
  case 59 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 66661L ) ;
      break ;
    case 1 : 
      printesc ( 65903L ) ;
      break ;
    case 2 : 
      printesc ( 66662L ) ;
      break ;
    case 3 : 
      printesc ( 66663L ) ;
      break ;
    case 4 : 
      printesc ( 66664L ) ;
      break ;
    case 5 : 
      printesc ( 66665L ) ;
      break ;
      default: 
      print ( 66673L ) ;
      break ;
    } 
    break ;
  case 116 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 66797L ) ;
      break ;
    case 1 : 
      printesc ( 66798L ) ;
      break ;
    case 2 : 
      printesc ( 66799L ) ;
      break ;
    case 3 : 
      printesc ( 66800L ) ;
      break ;
    case 4 : 
      printesc ( 66801L ) ;
      break ;
    case 5 : 
      printesc ( 66802L ) ;
      break ;
    case 6 : 
      printesc ( 66803L ) ;
      break ;
    case 7 : 
      printesc ( 66804L ) ;
      break ;
    } 
    break ;
  case 117 : 
    switch ( chrcode ) 
    {case 0 : 
      printesc ( 66805L ) ;
      break ;
    case 1 : 
      printesc ( 66806L ) ;
      break ;
    case 2 : 
      printesc ( 66807L ) ;
      break ;
    case 3 : 
      printesc ( 66808L ) ;
      break ;
    case 4 : 
      printesc ( 66809L ) ;
      break ;
    case 5 : 
      printesc ( 66810L ) ;
      break ;
    case 6 : 
      printesc ( 66811L ) ;
      break ;
    case 7 : 
      printesc ( 66812L ) ;
      break ;
    } 
    break ;
  case 107 : 
    {
      print ( 66836L ) ;
      slowprint ( ocptables [chrcode ][ 1 ]) ;
    } 
    break ;
  case 108 : 
    if ( curchr == 0 ) 
    printesc ( 66825L ) ;
    else printesc ( 66826L ) ;
    break ;
  case 109 : 
    print ( 66837L ) ;
    break ;
  case 110 : 
    printesc ( 66827L ) ;
    break ;
  case 112 : 
    printesc ( 66828L ) ;
    break ;
  case 113 : 
    printesc ( 66829L ) ;
    break ;
  case 111 : 
    printesc ( 66830L ) ;
    break ;
  case 114 : 
    if ( chrcode == 1 ) 
    printesc ( 66831L ) ;
    else if ( chrcode == 2 ) 
    printesc ( 66832L ) ;
    else if ( chrcode == 3 ) 
    printesc ( 66833L ) ;
    else printesc ( 66834L ) ;
    break ;
  case 115 : 
    printesc ( 66835L ) ;
    break ;
    default: 
    print ( 65872L ) ;
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
  else if ( n < 393230L ) 
  {
    sprintcs ( n ) ;
    printchar ( 61 ) ;
    printcmdchr ( neweqtype ( n ) , newequiv ( n ) ) ;
    if ( neweqtype ( n ) >= 128 ) 
    {
      printchar ( 58 ) ;
      showtokenlist ( mem [newequiv ( n ) ].hh .v.RH , 0 , 32 ) ;
    } 
  } 
  else if ( n < 524320L ) {
      
    if ( n < 393248L ) 
    {
      printskipparam ( n - 393230L ) ;
      printchar ( 61 ) ;
      if ( n < 393245L ) 
      printspec ( newequiv ( n ) , 65683L ) ;
      else printspec ( newequiv ( n ) , 65623L ) ;
    } 
    else if ( n < 458784L ) 
    {
      printesc ( 65681L ) ;
      printint ( n - 393248L ) ;
      printchar ( 61 ) ;
      printspec ( newequiv ( n ) , 65683L ) ;
    } 
    else {
	
      printesc ( 65682L ) ;
      printint ( n - 458784L ) ;
      printchar ( 61 ) ;
      printspec ( newequiv ( n ) , 65623L ) ;
    } 
  } 
  else if ( n < 1049408L ) {
      
    if ( n < 524325L ) 
    {
      printcmdchr ( 87 , n ) ;
      printchar ( 61 ) ;
      if ( newequiv ( n ) == 0 ) 
      printchar ( 48 ) ;
      else if ( n > 524320L ) 
      {
	printint ( mem [newequiv ( n ) + 1 ].cint ) ;
	printchar ( 32 ) ;
	printint ( mem [newequiv ( n ) + 2 ].cint ) ;
	if ( mem [newequiv ( n ) + 1 ].cint > 1 ) 
	printesc ( 65694L ) ;
      } 
      else printint ( mem [newequiv ( 524320L ) ].hh .v.LH ) ;
    } 
    else if ( n < 589885L ) 
    {
      printcmdchr ( 75 , n ) ;
      printchar ( 61 ) ;
      if ( newequiv ( n ) != 0 ) 
      showtokenlist ( mem [newequiv ( n ) ].hh .v.RH , 0 , 32 ) ;
    } 
    else if ( n < 655423L ) 
    {
      printesc ( 65693L ) ;
      printint ( n - 589885L ) ;
      printchar ( 61 ) ;
      if ( newequiv ( n ) != 0 ) 
      showtokenlist ( mem [newequiv ( n ) ].hh .v.RH , 0 , 32 ) ;
    } 
    else if ( n < 720959L ) 
    {
      printesc ( 65695L ) ;
      printint ( n - 655423L ) ;
      printchar ( 61 ) ;
      if ( newequiv ( n ) == 0 ) 
      print ( 65696L ) ;
      else {
	  
	depththreshold = 0 ;
	breadthmax = 1 ;
	shownodelist ( newequiv ( n ) ) ;
      } 
    } 
    else if ( n < 721728L ) 
    {
      if ( n == 720959L ) 
      print ( 65697L ) ;
      else if ( n < 721216L ) 
      {
	printesc ( 65698L ) ;
	printint ( n - 720960L ) ;
      } 
      else if ( n < 721472L ) 
      {
	printesc ( 65699L ) ;
	printint ( n - 721216L ) ;
      } 
      else {
	  
	printesc ( 65700L ) ;
	printint ( n - 721472L ) ;
      } 
      printchar ( 61 ) ;
      printesc ( newhashtext ( 1442736L + newequiv ( n ) ) ) ;
    } 
    else if ( n < 983872L ) 
    {
      if ( n < 787264L ) 
      {
	printesc ( 65701L ) ;
	printint ( n - 721728L ) ;
      } 
      else if ( n < 852800L ) 
      {
	printesc ( 65702L ) ;
	printint ( n - 787264L ) ;
      } 
      else if ( n < 918336L ) 
      {
	printesc ( 65703L ) ;
	printint ( n - 852800L ) ;
      } 
      else {
	  
	printesc ( 65704L ) ;
	printint ( n - 918336L ) ;
      } 
      printchar ( 61 ) ;
      printint ( newequiv ( n ) ) ;
    } 
    else {
	
      printesc ( 65705L ) ;
      printint ( n - 983872L ) ;
      printchar ( 61 ) ;
      printint ( newequiv ( n ) ) ;
    } 
  } 
  else if ( n < 1180556L ) 
  {
    if ( n < 1049484L ) 
    printparam ( n - 1049408L ) ;
    else if ( n < 1115020L ) 
    {
      printesc ( 65762L ) ;
      printint ( n - 1049484L ) ;
    } 
    else {
	
      printesc ( 65763L ) ;
      printint ( n - 1115020L ) ;
    } 
    printchar ( 61 ) ;
    printint ( neweqtbint ( n ) ) ;
  } 
  else if ( n <= 1246116L ) 
  {
    if ( n < 1180581L ) 
    printlengthparam ( n - 1180556L ) ;
    else {
	
      printesc ( 65790L ) ;
      printint ( n - 1180581L ) ;
    } 
    printchar ( 61 ) ;
    printscaled ( neweqtbsc ( n ) ) ;
    print ( 65683L ) ;
  } 
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
  integer newstring  ;
  h = buffer [j ];
  {register integer for_end; k = j + 1 ;for_end = j + l - 1 ; if ( k <= 
  for_end) do 
    {
      h = h + h + buffer [k ];
      while ( h >= 55711L ) h = h - 55711L ;
    } 
  while ( k++ < for_end ) ;} 
  p = h + 131074L ;
  while ( true ) {
      
    if ( newhashtext ( 1246116L + p ) > 0 ) {
	
      if ( length ( newhashtext ( 1246116L + p ) ) == l ) {
	  
	if ( streqbuf ( newhashtext ( 1246116L + p ) , j ) ) 
	goto lab40 ;
      } 
    } 
    if ( newhashnext ( 1246116L + p ) == 0 ) 
    {
      if ( nonewcontrolsequence ) 
      p = 393229L ;
      else {
	  
	if ( newhashtext ( 1246116L + p ) > 0 ) 
	{
	  do {
	      if ( ( hashused == 131074L ) ) 
	    overflow ( 65793L , 65536L ) ;
	    decr ( hashused ) ;
	  } while ( ! ( newhashtext ( 1246116L + hashused ) == 0 ) ) ;
	  sethashnext ( 1246116L + p , hashused ) ;
	  p = hashused ;
	} 
	{
	  if ( poolptr + l > poolsize ) 
	  overflow ( 65543L , poolsize - initpoolptr ) ;
	} 
	d = ( poolptr - strstartar [strptr - 65536L ]) ;
	while ( poolptr > strstartar [strptr - 65536L ]) {
	    
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
	newstring = makestring () ;
	sethashtext ( 1246116L + p , newstring ) ;
	poolptr = poolptr + d ;
	;
#ifdef STAT
	incr ( cscount ) ;
#endif /* STAT */
      } 
      goto lab40 ;
    } 
    p = newhashnext ( 1246116L + p ) ;
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
      print ( 66719L ) ;
      return ;
    } 
    break ;
  case 1 : 
  case 14 : 
    {
      if ( curgroup == 14 ) 
      print ( 66720L ) ;
      print ( 66721L ) ;
    } 
    break ;
  case 2 : 
  case 3 : 
    {
      if ( curgroup == 3 ) 
      print ( 66722L ) ;
      print ( 66418L ) ;
    } 
    break ;
  case 4 : 
    print ( 66323L ) ;
    break ;
  case 5 : 
    print ( 66417L ) ;
    break ;
  case 6 : 
  case 7 : 
    {
      if ( curgroup == 7 ) 
      print ( 66723L ) ;
      print ( 66724L ) ;
    } 
    break ;
  case 8 : 
    print ( 65684L ) ;
    break ;
  case 10 : 
    print ( 66725L ) ;
    break ;
  case 11 : 
    print ( 65616L ) ;
    break ;
  case 12 : 
    print ( 65840L ) ;
    break ;
  case 9 : 
  case 13 : 
  case 15 : 
  case 16 : 
    {
      print ( 65629L ) ;
      if ( curgroup == 13 ) 
      print ( 66726L ) ;
      else if ( curgroup == 15 ) 
      print ( 66727L ) ;
      else if ( curgroup == 16 ) 
      print ( 66728L ) ;
    } 
    break ;
  } 
  print ( 66729L ) ;
  printint ( curlevel ) ;
  printchar ( 41 ) ;
  if ( savestack [saveptr - 1 ].cint != 0 ) 
  {
    if ( e ) 
    print ( 65650L ) ;
    else print ( 66730L ) ;
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
  print ( 66731L ) ;
  else print ( 66732L ) ;
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
  if ( p == 0 ) 
  Result = false ;
  else {
      
    mem [pseudofiles ].hh .v.LH = mem [p ].hh .v.RH ;
    sz = mem [p ].hh .v.LH ;
    if ( 4 * sz - 3 >= bufsize - last ) 
    {
      curinput .locfield = first ;
      curinput .limitfield = last - 1 ;
      overflow ( 65542L , bufsize ) ;
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
  while ( q != 0 ) {
      
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
      
    if ( neweqtbint ( 1049473L ) > 0 ) 
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
    printnl ( 66765L ) ;
    printgroup ( true ) ;
    print ( 66766L ) ;
    println () ;
    if ( neweqtbint ( 1049473L ) > 1 ) 
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
      
    if ( neweqtbint ( 1049473L ) > 0 ) 
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
    printnl ( 66765L ) ;
    printcmdchr ( 122 , curif ) ;
    if ( ifline != 0 ) 
    {
      print ( 66751L ) ;
      printint ( ifline ) ;
    } 
    print ( 66766L ) ;
    println () ;
    if ( neweqtbint ( 1049473L ) > 1 ) 
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
    printnl ( 66767L ) ;
    printgroup ( true ) ;
    print ( 66768L ) ;
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
      
    printnl ( 66767L ) ;
    printcmdchr ( 122 , curif ) ;
    if ( iflimit == 2 ) 
    printesc ( 66103L ) ;
    if ( ifline != 0 ) 
    {
      print ( 66751L ) ;
      printint ( ifline ) ;
    } 
    print ( 66768L ) ;
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
  if ( neweqtbint ( 1049473L ) > 1 ) 
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
  if ( mem [q + 1 ].hh .v.LH != 0 ) 
  return ;
  if ( false ) {
      
    if ( mem [q + 2 ].cint == 0 ) 
    s = 3 ;
    else return ;
  } 
  else {
      
    if ( false ) {
	
      if ( mem [q + 1 ].hh .v.RH == membot ) 
      deleteglueref ( membot ) ;
      else return ;
    } 
    else if ( mem [q + 1 ].hh .v.RH != 0 ) 
    return ;
    s = 2 ;
  } 
  do {
      i = mem [q ].hh.b0 % 16 ;
    p = q ;
    q = mem [p ].hh .v.RH ;
    freenode ( p , s ) ;
    if ( q == 0 ) 
    {
      samark = 0 ;
      return ;
    } 
    {
      if ( odd ( i ) ) 
      mem [q + ( i / 2 ) + 1 ].hh .v.RH = 0 ;
      else mem [q + ( i / 2 ) + 1 ].hh .v.LH = 0 ;
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
  begindiagnostic () ;
  printchar ( 123 ) ;
  print ( s ) ;
  printchar ( 32 ) ;
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
      overflow ( 65843L , savesize ) ;
    } 
    savestack [saveptr ].hh.b0 = 4 ;
    savestack [saveptr ].hh.b1 = salevel ;
    savestack [saveptr ].hh .v.RH = sachain ;
    incr ( saveptr ) ;
    sachain = 0 ;
    salevel = curlevel ;
  } 
  i = mem [p ].hh.b0 ;
  if ( false ) 
  {
    if ( mem [p + 2 ].cint == 0 ) 
    {
      q = getnode ( 2 ) ;
      i = i ;
    } 
    else {
	
      q = getnode ( 3 ) ;
      mem [q + 2 ].cint = mem [p + 2 ].cint ;
    } 
    mem [q + 1 ].hh .v.RH = 0 ;
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
  if ( false ) 
  deleteglueref ( mem [p + 1 ].hh .v.RH ) ;
  else if ( mem [p + 1 ].hh .v.RH != 0 ) {
      
    if ( false ) 
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
    if ( neweqtbint ( 1049469L ) > 0 ) 
    showsa ( p , 65845L ) ;
#endif /* STAT */
    sadestroy ( p ) ;
  } 
  else {
      
	;
#ifdef STAT
    if ( neweqtbint ( 1049469L ) > 0 ) 
    showsa ( p , 65846L ) ;
#endif /* STAT */
    if ( mem [p ].hh.b1 == curlevel ) 
    sadestroy ( p ) ;
    else sasave ( p ) ;
    mem [p ].hh.b1 = curlevel ;
    mem [p + 1 ].hh .v.RH = e ;
	;
#ifdef STAT
    if ( neweqtbint ( 1049469L ) > 0 ) 
    showsa ( p , 65847L ) ;
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
    if ( neweqtbint ( 1049469L ) > 0 ) 
    showsa ( p , 65845L ) ;
#endif /* STAT */
  } 
  else {
      
	;
#ifdef STAT
    if ( neweqtbint ( 1049469L ) > 0 ) 
    showsa ( p , 65846L ) ;
#endif /* STAT */
    if ( mem [p ].hh.b1 != curlevel ) 
    sasave ( p ) ;
    mem [p ].hh.b1 = curlevel ;
    mem [p + 2 ].cint = w ;
	;
#ifdef STAT
    if ( neweqtbint ( 1049469L ) > 0 ) 
    showsa ( p , 65847L ) ;
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
  if ( neweqtbint ( 1049469L ) > 0 ) 
  showsa ( p , 65848L ) ;
#endif /* STAT */
  sadestroy ( p ) ;
  mem [p ].hh.b1 = 1 ;
  mem [p + 1 ].hh .v.RH = e ;
	;
#ifdef STAT
  if ( neweqtbint ( 1049469L ) > 0 ) 
  showsa ( p , 65847L ) ;
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
  if ( neweqtbint ( 1049469L ) > 0 ) 
  showsa ( p , 65848L ) ;
#endif /* STAT */
  mem [p ].hh.b1 = 1 ;
  mem [p + 2 ].cint = w ;
	;
#ifdef STAT
  if ( neweqtbint ( 1049469L ) > 0 ) 
  showsa ( p , 65847L ) ;
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
      sadestroy ( sachain ) ;
	;
#ifdef STAT
      if ( neweqtbint ( 1049445L ) > 0 ) 
      showsa ( p , 65850L ) ;
#endif /* STAT */
    } 
    else {
	
      if ( false ) {
	  
	if ( false ) 
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
      if ( neweqtbint ( 1049445L ) > 0 ) 
      showsa ( p , 65851L ) ;
#endif /* STAT */
    } 
    deletesaref ( p ) ;
    p = sachain ;
    sachain = mem [p ].hh .v.RH ;
    if ( false ) 
    freenode ( p , 3 ) ;
    else freenode ( p , 2 ) ;
  } while ( ! ( sachain == 0 ) ) ;
} 
void 
znewsavelevel ( groupcode c ) 
{
  newsavelevel_regmem 
  if ( saveptr > maxsavestack ) 
  {
    maxsavestack = saveptr ;
    if ( maxsavestack > savesize - 7 ) 
    overflow ( 65843L , savesize ) ;
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
  overflow ( 65844L , 65535L ) ;
  curboundary = saveptr ;
  curgroup = c ;
	;
#ifdef STAT
  if ( neweqtbint ( 1049470L ) > 0 ) 
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
  {case 128 : 
  case 129 : 
  case 130 : 
  case 131 : 
    deletetokenref ( w .hh .v.RH ) ;
    break ;
  case 134 : 
    deleteglueref ( w .hh .v.RH ) ;
    break ;
  case 135 : 
    {
      q = w .hh .v.RH ;
      if ( q != 0 ) 
      freenode ( q , mem [q ].hh .v.LH + mem [q ].hh .v.LH + 1 ) ;
    } 
    break ;
  case 136 : 
    flushnodelist ( w .hh .v.RH ) ;
    break ;
  case 74 : 
  case 92 : 
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
    overflow ( 65843L , savesize ) ;
  } 
  if ( l == 0 ) 
  savestack [saveptr ].hh.b0 = 1 ;
  else {
      
    savestack [saveptr ]= neweqtb ( p ) ;
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
  if ( ( eTeXmode == 1 ) && ( neweqtype ( p ) == t ) && ( newequiv ( p ) == e 
  ) ) 
  {
	;
#ifdef STAT
    if ( neweqtbint ( 1049469L ) > 0 ) 
    restoretrace ( p , 65845L ) ;
#endif /* STAT */
    eqdestroy ( neweqtb ( p ) ) ;
    return ;
  } 
	;
#ifdef STAT
  if ( neweqtbint ( 1049469L ) > 0 ) 
  restoretrace ( p , 65846L ) ;
#endif /* STAT */
  if ( neweqlevel ( p ) == curlevel ) 
  eqdestroy ( neweqtb ( p ) ) ;
  else if ( curlevel > 1 ) 
  eqsave ( p , neweqlevel ( p ) ) ;
  seteqlevel ( p , curlevel ) ;
  seteqtype ( p , t ) ;
  setequiv ( p , e ) ;
	;
#ifdef STAT
  if ( neweqtbint ( 1049469L ) > 0 ) 
  restoretrace ( p , 65847L ) ;
#endif /* STAT */
} 
void 
zeqworddefine ( halfword p , integer w ) 
{
  /* 10 */ eqworddefine_regmem 
  if ( ( eTeXmode == 1 ) && ( neweqtbint ( p ) == w ) ) 
  {
	;
#ifdef STAT
    if ( neweqtbint ( 1049469L ) > 0 ) 
    restoretrace ( p , 65845L ) ;
#endif /* STAT */
    return ;
  } 
	;
#ifdef STAT
  if ( neweqtbint ( 1049469L ) > 0 ) 
  restoretrace ( p , 65846L ) ;
#endif /* STAT */
  if ( newxeqlevel ( 2492232L + p ) != curlevel ) 
  {
    eqsave ( p , newxeqlevel ( 2492232L + p ) ) ;
    setneweqtbint ( 2492232L + p , curlevel ) ;
  } 
  setneweqtbint ( p , w ) ;
	;
#ifdef STAT
  if ( neweqtbint ( 1049469L ) > 0 ) 
  restoretrace ( p , 65847L ) ;
#endif /* STAT */
} 
void 
zdeleqworddefine ( halfword p , integer w , integer wone ) 
{
  deleqworddefine_regmem 
  if ( newxeqlevel ( 2492232L + p ) != curlevel ) 
  {
    eqsave ( p , newxeqlevel ( 2492232L + p ) ) ;
    setneweqtbint ( 2492232L + p , curlevel ) ;
  } 
  setequiv ( p , w ) ;
  setequiv1 ( p , wone ) ;
} 
void 
zgeqdefine ( halfword p , quarterword t , halfword e ) 
{
  geqdefine_regmem 
	;
#ifdef STAT
  if ( neweqtbint ( 1049469L ) > 0 ) 
  restoretrace ( p , 65848L ) ;
#endif /* STAT */
  {
    eqdestroy ( neweqtb ( p ) ) ;
    seteqlevel ( p , 1 ) ;
    seteqtype ( p , t ) ;
    setequiv ( p , e ) ;
  } 
	;
#ifdef STAT
  if ( neweqtbint ( 1049469L ) > 0 ) 
  restoretrace ( p , 65847L ) ;
#endif /* STAT */
} 
void 
zgeqworddefine ( halfword p , integer w ) 
{
  geqworddefine_regmem 
	;
#ifdef STAT
  if ( neweqtbint ( 1049469L ) > 0 ) 
  restoretrace ( p , 65848L ) ;
#endif /* STAT */
  {
    setneweqtbint ( p , w ) ;
    setneweqtbint ( 2492232L + p , 1 ) ;
  } 
	;
#ifdef STAT
  if ( neweqtbint ( 1049469L ) > 0 ) 
  restoretrace ( p , 65847L ) ;
#endif /* STAT */
} 
void 
zdelgeqworddefine ( halfword p , integer w , integer wone ) 
{
  delgeqworddefine_regmem 
  setequiv ( p , w ) ;
  setequiv1 ( p , wone ) ;
  setneweqtbint ( 2492232L + p , 1 ) ;
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
      overflow ( 65843L , savesize ) ;
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
	  if ( curtok < 196608L ) {
	      
	    if ( curtok < 131072L ) 
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
	else savestack [saveptr ]= neweqtb ( 393229L ) ;
	if ( p < 1049408L ) {
	    
	  if ( neweqlevel ( p ) == 1 ) 
	  {
	    eqdestroy ( savestack [saveptr ]) ;
	;
#ifdef STAT
	    if ( neweqtbint ( 1049445L ) > 0 ) 
	    restoretrace ( p , 65850L ) ;
#endif /* STAT */
	  } 
	  else {
	      
	    eqdestroy ( neweqtb ( p ) ) ;
	    setneweqtb ( p , savestack [saveptr ]) ;
	;
#ifdef STAT
	    if ( neweqtbint ( 1049445L ) > 0 ) 
	    restoretrace ( p , 65851L ) ;
#endif /* STAT */
	  } 
	} 
	else if ( newxeqlevel ( 2492232L + p ) != 1 ) 
	{
	  setneweqtb ( p , savestack [saveptr ]) ;
	  setneweqtbint ( 2492232L + p , l ) ;
	;
#ifdef STAT
	  if ( neweqtbint ( 1049445L ) > 0 ) 
	  restoretrace ( p , 65851L ) ;
#endif /* STAT */
	} 
	else {
	    
	;
#ifdef STAT
	  if ( neweqtbint ( 1049445L ) > 0 ) 
	  restoretrace ( p , 65850L ) ;
#endif /* STAT */
	} 
      } 
    } 
    lab30: 
	;
#ifdef STAT
    if ( neweqtbint ( 1049470L ) > 0 ) 
    grouptrace ( true ) ;
#endif /* STAT */
    if ( grpstack [inopen ]== curboundary ) 
    groupwarning () ;
    curgroup = savestack [saveptr ].hh.b1 ;
    curboundary = savestack [saveptr ].hh .v.RH ;
    if ( ( eTeXmode == 1 ) ) 
    decr ( saveptr ) ;
  } 
  else confusion ( 65849L ) ;
} 
void 
preparemag ( void ) 
{
  preparemag_regmem 
  if ( ( magset > 0 ) && ( neweqtbint ( 1049425L ) != magset ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 65853L ) ;
    } 
    printint ( neweqtbint ( 1049425L ) ) ;
    print ( 65854L ) ;
    printnl ( 65855L ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 65856L ;
      helpline [0 ]= 65857L ;
    } 
    interror ( magset ) ;
    geqworddefine ( 1049425L , magset ) ;
  } 
  if ( ( neweqtbint ( 1049425L ) <= 0 ) || ( neweqtbint ( 1049425L ) > 32768L 
  ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 65858L ) ;
    } 
    {
      helpptr = 1 ;
      helpline [0 ]= 65859L ;
    } 
    interror ( neweqtbint ( 1049425L ) ) ;
    geqworddefine ( 1049425L , 1000 ) ;
  } 
  magset = neweqtbint ( 1049425L ) ;
} 
void 
ztokenshow ( halfword p ) 
{
  tokenshow_regmem 
  if ( p != 0 ) 
  showtokenlist ( mem [p ].hh .v.RH , 0 , 10000000L ) ;
} 
void 
printmeaning ( void ) 
{
  printmeaning_regmem 
  printcmdchr ( curcmd , curchr ) ;
  if ( curcmd >= 128 ) 
  {
    printchar ( 58 ) ;
    println () ;
    tokenshow ( curchr ) ;
  } 
  else if ( ( curcmd == 127 ) && ( curchr < 5 ) ) 
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
    print ( 65873L ) ;
    shownmode = curlist .modefield ;
  } 
  printcmdchr ( curcmd , curchr ) ;
  if ( neweqtbint ( 1049471L ) > 0 ) {
      
    if ( curcmd >= 122 ) {
	
      if ( curcmd <= 123 ) 
      {
	print ( 65873L ) ;
	if ( curcmd == 123 ) 
	{
	  printcmdchr ( 122 , curif ) ;
	  printchar ( 32 ) ;
	  n = 0 ;
	  l = ifline ;
	} 
	else {
	    
	  n = 1 ;
	  l = line ;
	} 
	p = condptr ;
	while ( p != 0 ) {
	    
	  incr ( n ) ;
	  p = mem [p ].hh .v.RH ;
	} 
	print ( 65874L ) ;
	printint ( n ) ;
	printchar ( 41 ) ;
	if ( l != 0 ) 
	{
	  print ( 66751L ) ;
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
  /* 30 */ showcontext_regmem 
  unsigned char oldsetting  ;
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
    if ( ( baseptr == inputptr ) || bottomline || ( nn < neweqtbint ( 1049462L 
    ) ) ) 
    {
      if ( ( baseptr == inputptr ) || ( curinput .statefield != 0 ) || ( 
      curinput .indexfield != 3 ) || ( curinput .locfield != 0 ) ) 
      {
	tally = 0 ;
	oldsetting = selector ;
	if ( curinput .ocplstackfield > 0 ) 
	{
	  printnl ( 65880L ) ;
	  printscaled ( curinput .ocplstackfield ) ;
	  print ( 65881L ) ;
	  printint ( curinput .ocpnofield ) ;
	  print ( 58 ) ;
	  {
	    l = tally ;
	    tally = 0 ;
	    selector = 20 ;
	    trickcount = 1000000L ;
	  } 
	  if ( buffer [curinput .limitfield ]== neweqtbint ( 1049456L ) ) 
	  j = curinput .limitfield ;
	  else j = curinput .limitfield + 1 ;
	  if ( j > 0 ) 
	  {register integer for_end; i = curinput .startfield ;for_end = j - 
	  1 ; if ( i <= for_end) do 
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
	else if ( curinput .statefield != 0 ) 
	{
	  if ( curinput .namefield <= 17 ) {
	      
	    if ( ( curinput .namefield == 0 ) ) {
		
	      if ( baseptr == 0 ) 
	      printnl ( 65882L ) ;
	      else printnl ( 65883L ) ;
	    } 
	    else {
		
	      printnl ( 65884L ) ;
	      if ( curinput .namefield == 17 ) 
	      printchar ( 42 ) ;
	      else printint ( curinput .namefield - 1 ) ;
	      printchar ( 62 ) ;
	    } 
	  } 
	  else {
	      
	    printnl ( 65885L ) ;
	    if ( curinput .indexfield == inopen ) 
	    printint ( line ) ;
	    else printint ( linestack [curinput .indexfield + 1 ]) ;
	  } 
	  printchar ( 32 ) ;
	  {
	    l = tally ;
	    tally = 0 ;
	    selector = 20 ;
	    trickcount = 1000000L ;
	  } 
	  if ( buffer [curinput .limitfield ]== neweqtbint ( 1049456L ) ) 
	  j = curinput .limitfield ;
	  else j = curinput .limitfield + 1 ;
	  if ( j > 0 ) 
	  {register integer for_end; i = curinput .startfield ;for_end = j - 
	  1 ; if ( i <= for_end) do 
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
	  {case 0 : 
	    printnl ( 65886L ) ;
	    break ;
	  case 1 : 
	  case 2 : 
	    printnl ( 65887L ) ;
	    break ;
	  case 3 : 
	    if ( curinput .locfield == 0 ) 
	    printnl ( 65888L ) ;
	    else printnl ( 65889L ) ;
	    break ;
	  case 4 : 
	    printnl ( 65890L ) ;
	    break ;
	  case 5 : 
	    {
	      println () ;
	      printcs ( curinput .namefield ) ;
	    } 
	    break ;
	  case 6 : 
	    printnl ( 65891L ) ;
	    break ;
	  case 7 : 
	    printnl ( 65892L ) ;
	    break ;
	  case 8 : 
	    printnl ( 65893L ) ;
	    break ;
	  case 9 : 
	    printnl ( 65894L ) ;
	    break ;
	  case 10 : 
	    printnl ( 65895L ) ;
	    break ;
	  case 11 : 
	    printnl ( 65896L ) ;
	    break ;
	  case 12 : 
	    printnl ( 65897L ) ;
	    break ;
	  case 13 : 
	    printnl ( 65898L ) ;
	    break ;
	  case 14 : 
	    printnl ( 65899L ) ;
	    break ;
	  case 15 : 
	    printnl ( 65900L ) ;
	    break ;
	  case 16 : 
	    printnl ( 65901L ) ;
	    break ;
	    default: 
	    printnl ( 63 ) ;
	    break ;
	  } 
	  {
	    l = tally ;
	    tally = 0 ;
	    selector = 20 ;
	    trickcount = 1000000L ;
	  } 
	  if ( curinput .indexfield < 5 ) 
	  showtokenlist ( curinput .startfield , curinput .locfield , 100000L 
	  ) ;
	  else showtokenlist ( mem [curinput .startfield ].hh .v.RH , 
	  curinput .locfield , 100000L ) ;
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
	    
	  print ( 65561L ) ;
	  p = l + firstcount - halferrorline + 3 ;
	  n = halferrorline ;
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
	{register integer for_end; q = firstcount ;for_end = p - 1 ; if ( q 
	<= for_end) do 
	  printchar ( trickbuf [q % errorline ]) ;
	while ( q++ < for_end ) ;} 
	if ( m + n > errorline ) 
	print ( 65561L ) ;
	incr ( nn ) ;
      } 
    } 
    else if ( nn == neweqtbint ( 1049462L ) ) 
    {
      printnl ( 65561L ) ;
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
      overflow ( 65902L , stacksize ) ;
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
      if ( neweqtbint ( 1049438L ) > 1 ) 
      {
	begindiagnostic () ;
	printnl ( 65624L ) ;
	switch ( t ) 
	{case 15 : 
	  printesc ( 65637L ) ;
	  break ;
	case 16 : 
	  printesc ( 65903L ) ;
	  break ;
	  default: 
	  printcmdchr ( 75 , t + 524319L ) ;
	  break ;
	} 
	print ( 65861L ) ;
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
    else fatalerror ( 65904L ) ;
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
  while ( ( curinput .statefield == 0 ) && ( curinput .locfield == 0 ) && ( 
  curinput .indexfield != 2 ) ) endtokenlist () ;
  p = getavail () ;
  mem [p ].hh .v.LH = curtok ;
  if ( curtok < 196608L ) {
      
    if ( curtok < 131072L ) 
    decr ( alignstate ) ;
    else incr ( alignstate ) ;
  } 
  {
    if ( inputptr > maxinstack ) 
    {
      maxinstack = inputptr ;
      if ( inputptr == stacksize ) 
      overflow ( 65902L , stacksize ) ;
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
  overflow ( 65905L , maxinopen ) ;
  if ( first == bufsize ) 
  overflow ( 65542L , bufsize ) ;
  incr ( inopen ) ;
  {
    if ( inputptr > maxinstack ) 
    {
      maxinstack = inputptr ;
      if ( inputptr == stacksize ) 
      overflow ( 65902L , stacksize ) ;
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
	mem [p ].hh .v.LH = 1048575L + curcs ;
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
	else printnl ( 65548L ) ;
	print ( 65913L ) ;
      } 
      else {
	  
	curcs = 0 ;
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 65914L ) ;
	} 
      } 
      print ( 65915L ) ;
      p = getavail () ;
      switch ( scannerstatus ) 
      {case 2 : 
	{
	  print ( 65876L ) ;
	  mem [p ].hh .v.LH = 131197L ;
	} 
	break ;
      case 3 : 
	{
	  print ( 65921L ) ;
	  mem [p ].hh .v.LH = partoken ;
	  longstate = 130 ;
	} 
	break ;
      case 4 : 
	{
	  print ( 65878L ) ;
	  mem [p ].hh .v.LH = 131197L ;
	  q = p ;
	  p = getavail () ;
	  mem [p ].hh .v.RH = q ;
	  mem [p ].hh .v.LH = 1245186L ;
	  alignstate = -1000000L ;
	} 
	break ;
      case 5 : 
	{
	  print ( 65879L ) ;
	  mem [p ].hh .v.LH = 131197L ;
	} 
	break ;
      } 
      begintokenlist ( p , 4 ) ;
      print ( 65916L ) ;
      sprintcs ( warningindex ) ;
      {
	helpptr = 4 ;
	helpline [3 ]= 65917L ;
	helpline [2 ]= 65918L ;
	helpline [1 ]= 65919L ;
	helpline [0 ]= 65920L ;
      } 
      error () ;
    } 
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 65907L ) ;
      } 
      printcmdchr ( 122 , curif ) ;
      print ( 65908L ) ;
      printint ( skipline ) ;
      {
	helpptr = 3 ;
	helpline [2 ]= 65909L ;
	helpline [1 ]= 65910L ;
	helpline [0 ]= 65911L ;
      } 
      if ( curcs != 0 ) 
      curcs = 0 ;
      else helpline [2 ]= 65912L ;
      curtok = 1245189L ;
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
  ASCIIcode c, cc, ccc, cccc  ;
  unsigned char d  ;
  lab20: curcs = 0 ;
  if ( curinput .statefield != 0 ) 
  {
    lab25: if ( curinput .locfield <= curinput .limitfield ) 
    {
      curchr = buffer [curinput .locfield ];
      incr ( curinput .locfield ) ;
      lab21: curcmd = newequiv ( 721728L + curchr ) ;
      switch ( curinput .statefield + curcmd ) 
      {case 10 : 
      case 26 : 
      case 42 : 
      case 27 : 
      case 43 : 
	goto lab25 ;
	break ;
      case 1 : 
      case 17 : 
      case 33 : 
	{
	  if ( curinput .locfield > curinput .limitfield ) 
	  curcs = 131073L ;
	  else {
	      
	    lab26: k = curinput .locfield ;
	    curchr = buffer [k ];
	    cat = newequiv ( 721728L + curchr ) ;
	    incr ( k ) ;
	    if ( cat == 11 ) 
	    curinput .statefield = 17 ;
	    else if ( cat == 10 ) 
	    curinput .statefield = 17 ;
	    else curinput .statefield = 1 ;
	    if ( ( cat == 11 ) && ( k <= curinput .limitfield ) ) 
	    {
	      do {
		  curchr = buffer [k ];
		cat = newequiv ( 721728L + curchr ) ;
		incr ( k ) ;
	      } while ( ! ( ( cat != 11 ) || ( k > curinput .limitfield ) ) ) 
	      ;
	      {
		if ( buffer [k ]== curchr ) {
		    
		  if ( cat == 7 ) {
		      
		    if ( k < curinput .limitfield ) 
		    {
		      if ( ( curchr == buffer [k + 1 ]) && ( curchr == 
		      buffer [k + 2 ]) && ( ( k + 6 ) <= curinput 
		      .limitfield ) ) 
		      {
			c = buffer [k + 3 ];
			cc = buffer [k + 4 ];
			ccc = buffer [k + 5 ];
			cccc = buffer [k + 6 ];
			if ( ( ( ( c >= 48 ) && ( c <= 57 ) ) || ( ( c >= 97 ) 
			&& ( c <= 102 ) ) ) && ( ( ( cc >= 48 ) && ( cc <= 57 
			) ) || ( ( cc >= 97 ) && ( cc <= 102 ) ) ) && ( ( ( 
			ccc >= 48 ) && ( ccc <= 57 ) ) || ( ( ccc >= 97 ) && ( 
			ccc <= 102 ) ) ) && ( ( ( cccc >= 48 ) && ( cccc <= 57 
			) ) || ( ( cccc >= 97 ) && ( cccc <= 102 ) ) ) ) 
			{
			  d = 7 ;
			  if ( c <= 57 ) 
			  curchr = c - 48 ;
			  else curchr = c - 87 ;
			  if ( cc <= 57 ) 
			  curchr = 16 * curchr + cc - 48 ;
			  else curchr = 16 * curchr + cc - 87 ;
			  if ( ccc <= 57 ) 
			  curchr = 16 * curchr + ccc - 48 ;
			  else curchr = 16 * curchr + ccc - 87 ;
			  if ( cccc <= 57 ) 
			  curchr = 16 * curchr + cccc - 48 ;
			  else curchr = 16 * curchr + cccc - 87 ;
			  buffer [k - 1 ]= curchr ;
			  while ( k <= curinput .limitfield ) {
			      
			    buffer [k ]= buffer [k + d ];
			    incr ( k ) ;
			  } 
			  goto lab26 ;
			} 
		      } 
		      else {
			  
			c = buffer [k + 1 ];
			if ( c < 128 ) 
			{
			  d = 2 ;
			  if ( ( ( ( c >= 48 ) && ( c <= 57 ) ) || ( ( c >= 97 
			  ) && ( c <= 102 ) ) ) ) {
			      
			    if ( k + 2 <= curinput .limitfield ) 
			    {
			      cc = buffer [k + 2 ];
			      if ( ( ( ( cc >= 48 ) && ( cc <= 57 ) ) || ( ( 
			      cc >= 97 ) && ( cc <= 102 ) ) ) ) 
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
			  while ( k <= curinput .limitfield ) {
			      
			    buffer [k ]= buffer [k + d ];
			    incr ( k ) ;
			  } 
			  goto lab26 ;
			} 
		      } 
		    } 
		  } 
		} 
	      } 
	      if ( cat != 11 ) 
	      decr ( k ) ;
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
		    if ( ( curchr == buffer [k + 1 ]) && ( curchr == buffer 
		    [k + 2 ]) && ( ( k + 6 ) <= curinput .limitfield ) ) 
		    {
		      c = buffer [k + 3 ];
		      cc = buffer [k + 4 ];
		      ccc = buffer [k + 5 ];
		      cccc = buffer [k + 6 ];
		      if ( ( ( ( c >= 48 ) && ( c <= 57 ) ) || ( ( c >= 97 ) 
		      && ( c <= 102 ) ) ) && ( ( ( cc >= 48 ) && ( cc <= 57 ) 
		      ) || ( ( cc >= 97 ) && ( cc <= 102 ) ) ) && ( ( ( ccc >= 
		      48 ) && ( ccc <= 57 ) ) || ( ( ccc >= 97 ) && ( ccc <= 
		      102 ) ) ) && ( ( ( cccc >= 48 ) && ( cccc <= 57 ) ) || ( 
		      ( cccc >= 97 ) && ( cccc <= 102 ) ) ) ) 
		      {
			d = 7 ;
			if ( c <= 57 ) 
			curchr = c - 48 ;
			else curchr = c - 87 ;
			if ( cc <= 57 ) 
			curchr = 16 * curchr + cc - 48 ;
			else curchr = 16 * curchr + cc - 87 ;
			if ( ccc <= 57 ) 
			curchr = 16 * curchr + ccc - 48 ;
			else curchr = 16 * curchr + ccc - 87 ;
			if ( cccc <= 57 ) 
			curchr = 16 * curchr + cccc - 48 ;
			else curchr = 16 * curchr + cccc - 87 ;
			buffer [k - 1 ]= curchr ;
			while ( k <= curinput .limitfield ) {
			    
			  buffer [k ]= buffer [k + d ];
			  incr ( k ) ;
			} 
			goto lab26 ;
		      } 
		    } 
		    else {
			
		      c = buffer [k + 1 ];
		      if ( c < 128 ) 
		      {
			d = 2 ;
			if ( ( ( ( c >= 48 ) && ( c <= 57 ) ) || ( ( c >= 97 ) 
			&& ( c <= 102 ) ) ) ) {
			    
			  if ( k + 2 <= curinput .limitfield ) 
			  {
			    cc = buffer [k + 2 ];
			    if ( ( ( ( cc >= 48 ) && ( cc <= 57 ) ) || ( ( cc 
			    >= 97 ) && ( cc <= 102 ) ) ) ) 
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
			while ( k <= curinput .limitfield ) {
			    
			  buffer [k ]= buffer [k + d ];
			  incr ( k ) ;
			} 
			goto lab26 ;
		      } 
		    } 
		  } 
		} 
	      } 
	    } 
	    curcs = 65537L + buffer [curinput .locfield ];
	    incr ( curinput .locfield ) ;
	  } 
	  lab40: curcmd = neweqtype ( curcs ) ;
	  curchr = newequiv ( curcs ) ;
	  if ( curcmd >= 130 ) 
	  checkoutervalidity () ;
	} 
	break ;
      case 14 : 
      case 30 : 
      case 46 : 
	{
	  curcs = curchr + 1 ;
	  curcmd = neweqtype ( curcs ) ;
	  curchr = newequiv ( curcs ) ;
	  curinput .statefield = 1 ;
	  if ( curcmd >= 130 ) 
	  checkoutervalidity () ;
	} 
	break ;
      case 8 : 
      case 24 : 
      case 40 : 
	{
	  if ( curchr == buffer [curinput .locfield ]) {
	      
	    if ( curinput .locfield < curinput .limitfield ) 
	    {
	      if ( ( curchr == buffer [curinput .locfield + 1 ]) && ( curchr 
	      == buffer [curinput .locfield + 2 ]) && ( ( curinput .locfield 
	      + 6 ) <= curinput .limitfield ) ) 
	      {
		c = buffer [curinput .locfield + 3 ];
		cc = buffer [curinput .locfield + 4 ];
		ccc = buffer [curinput .locfield + 5 ];
		cccc = buffer [curinput .locfield + 6 ];
		if ( ( ( ( c >= 48 ) && ( c <= 57 ) ) || ( ( c >= 97 ) && ( c 
		<= 102 ) ) ) && ( ( ( cc >= 48 ) && ( cc <= 57 ) ) || ( ( cc 
		>= 97 ) && ( cc <= 102 ) ) ) && ( ( ( ccc >= 48 ) && ( ccc <= 
		57 ) ) || ( ( ccc >= 97 ) && ( ccc <= 102 ) ) ) && ( ( ( cccc 
		>= 48 ) && ( cccc <= 57 ) ) || ( ( cccc >= 97 ) && ( cccc <= 
		102 ) ) ) ) 
		{
		  curinput .locfield = curinput .locfield + 7 ;
		  if ( c <= 57 ) 
		  curchr = c - 48 ;
		  else curchr = c - 87 ;
		  if ( cc <= 57 ) 
		  curchr = 16 * curchr + cc - 48 ;
		  else curchr = 16 * curchr + cc - 87 ;
		  if ( ccc <= 57 ) 
		  curchr = 16 * curchr + ccc - 48 ;
		  else curchr = 16 * curchr + ccc - 87 ;
		  if ( cccc <= 57 ) 
		  curchr = 16 * curchr + cccc - 48 ;
		  else curchr = 16 * curchr + cccc - 87 ;
		  goto lab21 ;
		} 
	      } 
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
      case 32 : 
      case 48 : 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 65922L ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 65923L ;
	    helpline [0 ]= 65924L ;
	  } 
	  deletionsallowed = false ;
	  error () ;
	  deletionsallowed = true ;
	  goto lab20 ;
	} 
	break ;
      case 11 : 
	{
	  curinput .statefield = 17 ;
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
      case 22 : 
      case 15 : 
      case 31 : 
      case 47 : 
	{
	  curinput .locfield = curinput .limitfield + 1 ;
	  goto lab25 ;
	} 
	break ;
      case 38 : 
	{
	  curinput .locfield = curinput .limitfield + 1 ;
	  curcs = parloc ;
	  curcmd = neweqtype ( curcs ) ;
	  curchr = newequiv ( curcs ) ;
	  if ( curcmd >= 130 ) 
	  checkoutervalidity () ;
	} 
	break ;
      case 2 : 
	incr ( alignstate ) ;
	break ;
      case 18 : 
      case 34 : 
	{
	  curinput .statefield = 1 ;
	  incr ( alignstate ) ;
	} 
	break ;
      case 3 : 
	decr ( alignstate ) ;
	break ;
      case 19 : 
      case 35 : 
	{
	  curinput .statefield = 1 ;
	  decr ( alignstate ) ;
	} 
	break ;
      case 20 : 
      case 21 : 
      case 23 : 
      case 25 : 
      case 28 : 
      case 29 : 
      case 36 : 
      case 37 : 
      case 39 : 
      case 41 : 
      case 44 : 
      case 45 : 
	curinput .statefield = 1 ;
	break ;
	default: 
	;
	break ;
      } 
    } 
    else {
	
      if ( curinput .ocplstackfield > 0 ) 
      {
	{
	  decr ( inputptr ) ;
	  curinput = inputstack [inputptr ];
	} 
	goto lab20 ;
      } 
      curinput .statefield = 33 ;
      if ( curinput .namefield > 17 ) 
      {
	incr ( line ) ;
	first = curinput .startfield ;
	if ( ! forceeof ) {
	    
	  if ( curinput .namefield <= 19 ) 
	  {
	    if ( pseudoinput () ) 
	    firmuptheline () ;
	    else if ( ( newequiv ( 524333L ) != 0 ) && ! eofseen [curinput 
	    .indexfield ]) 
	    {
	      curinput .limitfield = first - 1 ;
	      eofseen [curinput .indexfield ]= true ;
	      begintokenlist ( newequiv ( 524333L ) , 14 ) ;
	      goto lab20 ;
	    } 
	    else forceeof = true ;
	  } 
	  else {
	      
	    if ( newinputln ( inputfile [curinput .indexfield ], 
	    inputfilemode [curinput .indexfield ], inputfiletranslation [
	    curinput .indexfield ], true ) ) 
	    firmuptheline () ;
	    else if ( ( newequiv ( 524333L ) != 0 ) && ! eofseen [curinput 
	    .indexfield ]) 
	    {
	      curinput .limitfield = first - 1 ;
	      eofseen [curinput .indexfield ]= true ;
	      begintokenlist ( newequiv ( 524333L ) , 14 ) ;
	      goto lab20 ;
	    } 
	    else forceeof = true ;
	  } 
	} 
	if ( forceeof ) 
	{
	  if ( neweqtbint ( 1049473L ) > 0 ) {
	      
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
	if ( ( neweqtbint ( 1049456L ) < 0 ) || ( neweqtbint ( 1049456L ) > 
	255 ) ) 
	decr ( curinput .limitfield ) ;
	else buffer [curinput .limitfield ]= neweqtbint ( 1049456L ) ;
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
	  if ( ( neweqtbint ( 1049456L ) < 0 ) || ( neweqtbint ( 1049456L ) > 
	  255 ) ) 
	  incr ( curinput .limitfield ) ;
	  if ( curinput .limitfield == curinput .startfield ) 
	  printnl ( 65925L ) ;
	  println () ;
	  first = curinput .startfield ;
	  {
	    ;
	    print ( 42 ) ;
	    terminput () ;
	  } 
	  curinput .limitfield = last ;
	  if ( ( neweqtbint ( 1049456L ) < 0 ) || ( neweqtbint ( 1049456L ) > 
	  255 ) ) 
	  decr ( curinput .limitfield ) ;
	  else buffer [curinput .limitfield ]= neweqtbint ( 1049456L ) ;
	  first = curinput .limitfield + 1 ;
	  curinput .locfield = curinput .startfield ;
	} 
	else fatalerror ( 65926L ) ;
      } 
      {
	if ( interrupt != 0 ) 
	pauseforinstructions () ;
      } 
      goto lab25 ;
    } 
  } 
  else if ( curinput .locfield != 0 ) 
  {
    t = mem [curinput .locfield ].hh .v.LH ;
    curinput .locfield = mem [curinput .locfield ].hh .v.RH ;
    if ( t >= 1048575L ) 
    {
      curcs = t - 1048575L ;
      curcmd = neweqtype ( curcs ) ;
      curchr = newequiv ( curcs ) ;
      if ( curcmd >= 130 ) {
	  
	if ( curcmd == 133 ) 
	{
	  curcs = mem [curinput .locfield ].hh .v.LH - 1048575L ;
	  curinput .locfield = 0 ;
	  curcmd = neweqtype ( curcs ) ;
	  curchr = newequiv ( curcs ) ;
	  if ( curcmd > 117 ) 
	  {
	    curcmd = 0 ;
	    curchr = 65537L ;
	  } 
	} 
	else checkoutervalidity () ;
      } 
    } 
    else {
	
      curcmd = t / 65536L ;
      curchr = t % 65536L ;
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
	if ( ( scannerstatus == 4 ) || ( curalign == 0 ) ) 
	fatalerror ( 65904L ) ;
	curcmd = mem [curalign + 5 ].hh .v.LH ;
	mem [curalign + 5 ].hh .v.LH = curchr ;
	if ( curcmd == 63 ) 
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
  if ( neweqtbint ( 1049436L ) > 0 ) {
      
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
	print ( 65927L ) ;
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
  if ( curcs == 0 ) 
  curtok = ( curcmd * 65536L ) + curchr ;
  else curtok = 1048575L + curcs ;
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
  if ( neweqtbint ( 1049438L ) > 0 ) 
  {
    begindiagnostic () ;
    println () ;
    printcs ( warningindex ) ;
    tokenshow ( refcount ) ;
    enddiagnostic ( false ) ;
  } 
  if ( mem [r ].hh .v.LH == 917505L ) 
  r = mem [r ].hh .v.RH ;
  if ( mem [r ].hh .v.LH != 917504L ) 
  {
    scannerstatus = 3 ;
    unbalance = 0 ;
    longstate = neweqtype ( curcs ) ;
    if ( longstate >= 130 ) 
    longstate = longstate - 2 ;
    do {
	mem [memtop - 3 ].hh .v.RH = 0 ;
      if ( ( mem [r ].hh .v.LH >= 917504L ) || ( mem [r ].hh .v.LH < 
      851968L ) ) 
      s = 0 ;
      else {
	  
	matchchr = mem [r ].hh .v.LH - 851968L ;
	s = mem [r ].hh .v.RH ;
	r = s ;
	p = memtop - 3 ;
	m = 0 ;
      } 
      lab22: gettoken () ;
      if ( curtok == mem [r ].hh .v.LH ) 
      {
	r = mem [r ].hh .v.RH ;
	if ( ( mem [r ].hh .v.LH >= 851968L ) && ( mem [r ].hh .v.LH <= 
	917504L ) ) 
	{
	  if ( curtok < 131072L ) 
	  decr ( alignstate ) ;
	  goto lab40 ;
	} 
	else goto lab22 ;
      } 
      if ( s != r ) {
	  
	if ( s == 0 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 65959L ) ;
	  } 
	  sprintcs ( warningindex ) ;
	  print ( 65960L ) ;
	  {
	    helpptr = 4 ;
	    helpline [3 ]= 65961L ;
	    helpline [2 ]= 65962L ;
	    helpline [1 ]= 65963L ;
	    helpline [0 ]= 65964L ;
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
	  
	if ( longstate != 129 ) 
	{
	  if ( longstate == 128 ) 
	  {
	    runaway () ;
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 65548L ) ;
	      print ( 65954L ) ;
	    } 
	    sprintcs ( warningindex ) ;
	    print ( 65955L ) ;
	    {
	      helpptr = 3 ;
	      helpline [2 ]= 65956L ;
	      helpline [1 ]= 65957L ;
	      helpline [0 ]= 65958L ;
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
      if ( curtok < 196608L ) {
	  
	if ( curtok < 131072L ) 
	{
	  unbalance = 1 ;
	  while ( true ) {
	      
	    {
	      {
		q = avail ;
		if ( q == 0 ) 
		q = getavail () ;
		else {
		    
		  avail = mem [q ].hh .v.RH ;
		  mem [q ].hh .v.RH = 0 ;
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
		
	      if ( longstate != 129 ) 
	      {
		if ( longstate == 128 ) 
		{
		  runaway () ;
		  {
		    if ( interaction == 3 ) 
		    ;
		    if ( filelineerrorstylep ) 
		    printfileline () ;
		    else printnl ( 65548L ) ;
		    print ( 65954L ) ;
		  } 
		  sprintcs ( warningindex ) ;
		  print ( 65955L ) ;
		  {
		    helpptr = 3 ;
		    helpline [2 ]= 65956L ;
		    helpline [1 ]= 65957L ;
		    helpline [0 ]= 65958L ;
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
	    if ( curtok < 196608L ) {
		
	      if ( curtok < 131072L ) 
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
	    else printnl ( 65548L ) ;
	    print ( 65946L ) ;
	  } 
	  sprintcs ( warningindex ) ;
	  print ( 65947L ) ;
	  {
	    helpptr = 6 ;
	    helpline [5 ]= 65948L ;
	    helpline [4 ]= 65949L ;
	    helpline [3 ]= 65950L ;
	    helpline [2 ]= 65951L ;
	    helpline [1 ]= 65952L ;
	    helpline [0 ]= 65953L ;
	  } 
	  incr ( alignstate ) ;
	  longstate = 128 ;
	  curtok = partoken ;
	  inserror () ;
	  goto lab22 ;
	} 
      } 
      else {
	  
	if ( curtok == 655392L ) {
	    
	  if ( mem [r ].hh .v.LH <= 917504L ) {
	      
	    if ( mem [r ].hh .v.LH >= 851968L ) 
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
      if ( mem [r ].hh .v.LH > 917504L ) 
      goto lab22 ;
      if ( mem [r ].hh .v.LH < 851968L ) 
      goto lab22 ;
      lab40: if ( s != 0 ) 
      {
	if ( ( m == 1 ) && ( mem [p ].hh .v.LH < 196608L ) && ( p != memtop 
	- 3 ) ) 
	{
	  mem [rbraceptr ].hh .v.RH = 0 ;
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
	if ( neweqtbint ( 1049438L ) > 0 ) 
	{
	  begindiagnostic () ;
	  printnl ( matchchr ) ;
	  printint ( n ) ;
	  print ( 65965L ) ;
	  showtokenlist ( pstack [n - 1 ], 0 , 1000 ) ;
	  enddiagnostic ( false ) ;
	} 
      } 
    } while ( ! ( mem [r ].hh .v.LH == 917504L ) ) ;
  } 
  while ( ( curinput .statefield == 0 ) && ( curinput .locfield == 0 ) && ( 
  curinput .indexfield != 2 ) ) endtokenlist () ;
  begintokenlist ( refcount , 5 ) ;
  curinput .namefield = warningindex ;
  curinput .locfield = mem [r ].hh .v.RH ;
  if ( n > 0 ) 
  {
    if ( paramptr + n > maxparamstack ) 
    {
      maxparamstack = paramptr + n ;
      if ( maxparamstack > paramsize ) 
      overflow ( 65945L , paramsize ) ;
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
  curtok = 1048575L + curcs ;
  backinput () ;
  curtok = 1245192L ;
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
  /* 45 46 47 48 49 10 */ findsaelement_regmem 
  halfword q  ;
  smallnumber i  ;
  {
    if ( t != 8 ) 
    {
      curptr = 0 ;
      return ;
    } 
  } 
  curptr = samark ;
  {
    if ( curptr == 0 ) {
	
      if ( w ) 
      goto lab45 ;
      else return ;
    } 
  } 
  q = curptr ;
  i = n / 4096 ;
  if ( odd ( i ) ) 
  curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
  else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
  {
    if ( curptr == 0 ) {
	
      if ( w ) 
      goto lab46 ;
      else return ;
    } 
  } 
  q = curptr ;
  i = ( n / 256 ) % 16 ;
  if ( odd ( i ) ) 
  curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
  else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
  {
    if ( curptr == 0 ) {
	
      if ( w ) 
      goto lab47 ;
      else return ;
    } 
  } 
  q = curptr ;
  i = ( n / 16 ) % 16 ;
  if ( odd ( i ) ) 
  curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
  else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
  {
    if ( curptr == 0 ) {
	
      if ( w ) 
      goto lab48 ;
      else return ;
    } 
  } 
  q = curptr ;
  i = n % 16 ;
  if ( odd ( i ) ) 
  curptr = mem [q + ( i / 2 ) + 1 ].hh .v.RH ;
  else curptr = mem [q + ( i / 2 ) + 1 ].hh .v.LH ;
  if ( ( curptr == 0 ) && w ) 
  goto lab49 ;
  return ;
  lab45: newindex ( t , 0 ) ;
  samark = curptr ;
  q = curptr ;
  i = n / 4096 ;
  lab46: newindex ( i , q ) ;
  {
    if ( odd ( i ) ) 
    mem [q + ( i / 2 ) + 1 ].hh .v.RH = curptr ;
    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = curptr ;
    incr ( mem [q ].hh.b1 ) ;
  } 
  q = curptr ;
  i = ( n / 256 ) % 16 ;
  lab47: newindex ( i , q ) ;
  {
    if ( odd ( i ) ) 
    mem [q + ( i / 2 ) + 1 ].hh .v.RH = curptr ;
    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = curptr ;
    incr ( mem [q ].hh.b1 ) ;
  } 
  q = curptr ;
  i = ( n / 16 ) % 16 ;
  lab48: newindex ( i , q ) ;
  {
    if ( odd ( i ) ) 
    mem [q + ( i / 2 ) + 1 ].hh .v.RH = curptr ;
    else mem [q + ( i / 2 ) + 1 ].hh .v.LH = curptr ;
    incr ( mem [q ].hh.b1 ) ;
  } 
  q = curptr ;
  i = n % 16 ;
  lab49: if ( t == 8 ) 
  {
    curptr = getnode ( 4 ) ;
    mem [curptr + 1 ]= sanull ;
    mem [curptr + 2 ]= sanull ;
    mem [curptr + 3 ]= sanull ;
  } 
  mem [curptr ].hh.b0 = 256 * t + i ;
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
  cvbackup = curval ;
  cvlbackup = curvallevel ;
  radixbackup = radix ;
  cobackup = curorder ;
  backupbackup = mem [memtop - 13 ].hh .v.RH ;
  lab21: if ( curcmd < 128 ) 
  {
    if ( neweqtbint ( 1049444L ) > 1 ) 
    showcurcmdchr () ;
    switch ( curcmd ) 
    {case 127 : 
      {
	t = curchr % 5 ;
	if ( curchr >= 5 ) 
	scanregisternum () ;
	else curval = 0 ;
	if ( curval == 0 ) 
	curptr = curmark [t ];
	else {
	    
	  findsaelement ( 8 , curval , false ) ;
	  if ( curptr != 0 ) {
	      
	    if ( odd ( t ) ) 
	    curptr = mem [curptr + ( t / 2 ) + 1 ].hh .v.RH ;
	    else curptr = mem [curptr + ( t / 2 ) + 1 ].hh .v.LH ;
	  } 
	} 
	if ( curptr != 0 ) 
	begintokenlist ( curptr , 15 ) ;
      } 
      break ;
    case 119 : 
      if ( curchr == 0 ) 
      {
	gettoken () ;
	t = curtok ;
	gettoken () ;
	if ( curcmd > 117 ) 
	expand () ;
	else backinput () ;
	curtok = t ;
	backinput () ;
      } 
      else {
	  
	gettoken () ;
	if ( ( curcmd == 122 ) && ( curchr != 16 ) ) 
	{
	  curchr = curchr + 32 ;
	  goto lab21 ;
	} 
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66002L ) ;
	} 
	printesc ( 66101L ) ;
	print ( 66764L ) ;
	printcmdchr ( curcmd , curchr ) ;
	printchar ( 39 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 65924L ;
	} 
	backerror () ;
      } 
      break ;
    case 120 : 
      {
	savescannerstatus = scannerstatus ;
	scannerstatus = 0 ;
	gettoken () ;
	scannerstatus = savescannerstatus ;
	t = curtok ;
	backinput () ;
	if ( t >= 1048575L ) 
	{
	  p = getavail () ;
	  mem [p ].hh .v.LH = 1245194L ;
	  mem [p ].hh .v.RH = curinput .locfield ;
	  curinput .startfield = p ;
	  curinput .locfield = p ;
	} 
      } 
      break ;
    case 124 : 
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
	if ( curcmd != 67 ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 65934L ) ;
	  } 
	  printesc ( 65795L ) ;
	  print ( 65935L ) ;
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 65936L ;
	    helpline [0 ]= 65937L ;
	  } 
	  backerror () ;
	} 
	j = first ;
	p = mem [r ].hh .v.RH ;
	while ( p != 0 ) {
	    
	  if ( j >= maxbufstack ) 
	  {
	    maxbufstack = j + 1 ;
	    if ( maxbufstack == bufsize ) 
	    overflow ( 65542L , bufsize ) ;
	  } 
	  buffer [j ]= mem [p ].hh .v.LH % 65536L ;
	  incr ( j ) ;
	  p = mem [p ].hh .v.RH ;
	} 
	if ( j > first + 1 ) 
	{
	  nonewcontrolsequence = false ;
	  curcs = idlookup ( first , j - first ) ;
	  nonewcontrolsequence = true ;
	} 
	else if ( j == first ) 
	curcs = 131073L ;
	else curcs = 65537L + buffer [first ];
	flushlist ( r ) ;
	if ( neweqtype ( curcs ) == 118 ) 
	{
	  eqdefine ( curcs , 0 , 65536L ) ;
	} 
	curtok = curcs + 1048575L ;
	backinput () ;
      } 
      break ;
    case 125 : 
      convtoks () ;
      break ;
    case 126 : 
      insthetoks () ;
      break ;
    case 122 : 
      conditional () ;
      break ;
    case 123 : 
      {
	if ( neweqtbint ( 1049471L ) > 0 ) {
	    
	  if ( neweqtbint ( 1049444L ) <= 1 ) 
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
	      else printnl ( 65548L ) ;
	      print ( 66104L ) ;
	    } 
	    printcmdchr ( 123 , curchr ) ;
	    {
	      helpptr = 1 ;
	      helpline [0 ]= 66105L ;
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
    case 121 : 
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
	  else printnl ( 65548L ) ;
	  print ( 65928L ) ;
	} 
	{
	  helpptr = 5 ;
	  helpline [4 ]= 65929L ;
	  helpline [3 ]= 65930L ;
	  helpline [2 ]= 65931L ;
	  helpline [1 ]= 65932L ;
	  helpline [0 ]= 65933L ;
	} 
	error () ;
      } 
      break ;
    } 
  } 
  else if ( curcmd < 132 ) 
  macrocall () ;
  else {
      
    curtok = 1245191L ;
    backinput () ;
  } 
  curval = cvbackup ;
  curvallevel = cvlbackup ;
  radix = radixbackup ;
  curorder = cobackup ;
  mem [memtop - 13 ].hh .v.RH = backupbackup ;
} 
void 
getxtoken ( void ) 
{
  /* 20 30 */ getxtoken_regmem 
  lab20: getnext () ;
  if ( curcmd <= 117 ) 
  goto lab30 ;
  if ( curcmd >= 128 ) {
      
    if ( curcmd < 132 ) 
    macrocall () ;
    else {
	
      curcs = 196616L ;
      curcmd = 9 ;
      goto lab30 ;
    } 
  } 
  else expand () ;
  goto lab20 ;
  lab30: if ( curcs == 0 ) 
  curtok = ( curcmd * 65536L ) + curchr ;
  else curtok = 1048575L + curcs ;
} 
void 
xtoken ( void ) 
{
  xtoken_regmem 
  while ( curcmd > 117 ) {
      
    expand () ;
    getnext () ;
  } 
  if ( curcs == 0 ) 
  curtok = ( curcmd * 65536L ) + curchr ;
  else curtok = 1048575L + curcs ;
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
      else printnl ( 65548L ) ;
      print ( 65966L ) ;
    } 
    {
      helpptr = 4 ;
      helpline [3 ]= 65967L ;
      helpline [2 ]= 65968L ;
      helpline [1 ]= 65969L ;
      helpline [0 ]= 65970L ;
    } 
    backerror () ;
    curtok = 65659L ;
    curcmd = 1 ;
    curchr = 123 ;
    incr ( alignstate ) ;
  } 
} 
void 
scanrightbrace ( void ) 
{
  scanrightbrace_regmem 
  do {
      getxtoken () ;
  } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
  if ( curcmd != 2 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 65966L ) ;
    } 
    {
      helpptr = 4 ;
      helpline [3 ]= 65971L ;
      helpline [2 ]= 65968L ;
      helpline [1 ]= 65969L ;
      helpline [0 ]= 65970L ;
    } 
    backerror () ;
    curtok = 131197L ;
    curcmd = 2 ;
    curchr = 125 ;
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
  if ( curtok != 786493L ) 
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
  mem [p ].hh .v.RH = 0 ;
  if ( s < 65536L ) 
  {
    while ( true ) {
	
      getxtoken () ;
      if ( ( curcs == 0 ) && ( ( curchr == s ) || ( curchr == s - 32 ) ) ) 
      {
	{
	  q = getavail () ;
	  mem [p ].hh .v.RH = q ;
	  mem [q ].hh .v.LH = curtok ;
	  p = q ;
	} 
	flushlist ( mem [memtop - 13 ].hh .v.RH ) ;
	Result = true ;
	return Result ;
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
  } 
  k = strstartar [s - 65536L ];
  while ( k < strstartar [s - 65535L ]) {
      
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
    else printnl ( 65548L ) ;
    print ( 65972L ) ;
  } 
  {
    helpptr = 1 ;
    helpline [0 ]= 65973L ;
  } 
  error () ;
} 
void 
scandir ( void ) 
{
  scandir_regmem 
  integer d1, d2, d3  ;
  getxtoken () ;
  if ( curcmd == 95 ) 
  {
    curval = neweqtbint ( curchr ) ;
    return ;
  } 
  else backinput () ;
  {
    if ( scankeyword ( 84 ) ) 
    d1 = 0 ;
    else if ( scankeyword ( 76 ) ) 
    d1 = 1 ;
    else if ( scankeyword ( 66 ) ) 
    d1 = 2 ;
    else if ( scankeyword ( 82 ) ) 
    d1 = 3 ;
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66004L ) ;
      } 
      curval = 0 ;
      return ;
    } 
  } 
  {
    if ( scankeyword ( 84 ) ) 
    d2 = 0 ;
    else if ( scankeyword ( 76 ) ) 
    d2 = 1 ;
    else if ( scankeyword ( 66 ) ) 
    d2 = 2 ;
    else if ( scankeyword ( 82 ) ) 
    d2 = 3 ;
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66004L ) ;
      } 
      curval = 0 ;
      return ;
    } 
  } 
  if ( ( ( d1 ) % 2 ) == ( ( d2 ) % 2 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66004L ) ;
    } 
    curval = 0 ;
    return ;
  } 
  {
    if ( scankeyword ( 84 ) ) 
    d3 = 0 ;
    else if ( scankeyword ( 76 ) ) 
    d3 = 1 ;
    else if ( scankeyword ( 66 ) ) 
    d3 = 2 ;
    else if ( scankeyword ( 82 ) ) 
    d3 = 3 ;
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66004L ) ;
      } 
      curval = 0 ;
      return ;
    } 
  } 
  curval = d1 * 8 + dirrearrange [d2 ]* 4 + d3 ;
} 
void 
scaneightbitint ( void ) 
{
  scaneightbitint_regmem 
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 65535L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66005L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66006L ;
      helpline [0 ]= 65976L ;
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
  if ( ( curval < 0 ) || ( curval > 65535L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66007L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66008L ;
      helpline [0 ]= 65976L ;
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
      else printnl ( 65548L ) ;
      print ( 66009L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66010L ;
      helpline [0 ]= 65976L ;
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
      else printnl ( 65548L ) ;
      print ( 66009L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66011L ;
      helpline [0 ]= 65976L ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
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
      else printnl ( 65548L ) ;
      print ( 66012L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66013L ;
      helpline [0 ]= 65976L ;
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
      else printnl ( 65548L ) ;
      print ( 66012L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66013L ;
      helpline [0 ]= 65976L ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
  curval = ( ( curval / 4096 ) * 16777216L ) + ( ( ( curval % 4096 ) / 256 ) * 
  65536L ) + ( curval % 256 ) ;
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
      else printnl ( 65548L ) ;
      print ( 66014L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66015L ;
      helpline [0 ]= 65976L ;
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
      else printnl ( 65548L ) ;
      print ( 66016L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 65978L ;
      helpline [0 ]= 65976L ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
  curval1 = ( ( ( curval % 4096 ) / 256 ) * 65536L ) + ( curval % 256 ) ;
  curval = curval / 4096 ;
  curval = ( ( curval / 4096 ) * 16777216L ) + ( ( ( curval % 4096 ) / 256 ) * 
  65536L ) + ( curval % 256 ) ;
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
      else printnl ( 65548L ) ;
      print ( 66016L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66017L ;
      helpline [0 ]= 65976L ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
  iiii = curval ;
  scanint () ;
  if ( ( curval < 0 ) || ( curval > 16777215L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66016L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66018L ;
      helpline [0 ]= 65976L ;
    } 
    interror ( curval ) ;
    curval = 0 ;
  } 
  curval1 = curval ;
  curval = iiii ;
} 
void 
scanstringargument ( void ) 
{
  scanstringargument_regmem 
  integer s  ;
  scanleftbrace () ;
  getxtoken () ;
  while ( ( curcmd != 2 ) ) {
      
    if ( ( curcmd == 11 ) || ( curcmd == 12 ) ) 
    {
      {
	if ( poolptr + 1 > poolsize ) 
	overflow ( 65543L , poolsize - initpoolptr ) ;
      } 
      {
	strpool [poolptr ]= curchr ;
	incr ( poolptr ) ;
      } 
    } 
    else if ( ( curcmd == 10 ) ) 
    {
      {
	if ( poolptr + 1 > poolsize ) 
	overflow ( 65543L , poolsize - initpoolptr ) ;
      } 
      {
	strpool [poolptr ]= 32 ;
	incr ( poolptr ) ;
      } 
    } 
    else {
	
      print ( 66019L ) ;
    } 
    getxtoken () ;
  } 
  s = makestring () ;
  if ( streqstr ( 66020L , s ) ) 
  s = 66020L ;
  if ( streqstr ( 66021L , s ) ) 
  s = 66021L ;
  if ( streqstr ( 66022L , s ) ) 
  s = 66022L ;
  curval = s ;
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
      else printnl ( 65548L ) ;
      print ( 66005L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= maxreghelpline ;
      helpline [0 ]= 65976L ;
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
      else printnl ( 65548L ) ;
      print ( 66009L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66010L ;
      helpline [0 ]= 65976L ;
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
    if ( curcmd <= 117 ) 
    return ;
    if ( ( curcmd >= 128 ) && ( curcmd < 132 ) ) {
	
      if ( mem [mem [curchr ].hh .v.RH ].hh .v.LH == 917505L ) 
      return ;
    } 
    expand () ;
  } 
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
  if ( curcmd == 91 ) 
  f = newequiv ( 720959L ) ;
  else if ( curcmd == 90 ) 
  f = curchr ;
  else if ( curcmd == 89 ) 
  {
    m = curchr ;
    scanbigfourbitint () ;
    f = newequiv ( m + curval ) ;
  } 
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66146L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66147L ;
      helpline [0 ]= 66148L ;
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
  dimenfont = f ;
  if ( n <= 0 ) 
  curval = fonttables [f ][ 0 ].cint ;
  else {
      
    if ( writing && ( n <= 4 ) && ( n >= 2 ) && ( fonttables [f ][ 14 ].cint 
    != 0 ) ) 
    {
      deleteglueref ( fonttables [f ][ 14 ].cint ) ;
      fonttables [f ][ 14 ].cint = 0 ;
    } 
    if ( n > fonttables [f ][ 8 ].cint ) {
	
      if ( f < fontptr ) 
      curval = fonttables [f ][ 0 ].cint ;
      else {
	  
	if ( n + fonttables [f ][ 8 ].cint > fonttables [f ][ 0 ].cint ) 
	{
	  printnl ( 66153L ) ;
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
	do {
	    fonttables [f ][ fonttables [f ][ 43 ].cint + fonttables [f 
	  ][ 8 ].cint ].cint = 0 ;
	  incr ( fonttables [f ][ 8 ].cint ) ;
	} while ( ! ( n == fonttables [f ][ 8 ].cint ) ) ;
	curval = fonttables [f ][ 43 ].cint + fonttables [f ][ 8 ].cint ;
      } 
    } 
    else curval = n + fonttables [f ][ 43 ].cint ;
  } 
  if ( curval == fonttables [f ][ 0 ].cint ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66131L ) ;
    } 
    printesc ( newhashtext ( 1442736L + f ) ) ;
    print ( 66149L ) ;
    printint ( fonttables [f ][ 8 ].cint ) ;
    print ( 66150L ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 66151L ;
      helpline [0 ]= 66152L ;
    } 
    error () ;
  } 
} 
void 
scanocpident ( void ) 
{
  scanocpident_regmem 
  internalocpnumber f  ;
  do {
      getxtoken () ;
  } while ( ! ( curcmd != 10 ) ) ;
  if ( curcmd == 107 ) 
  f = curchr ;
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66169L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66147L ;
      helpline [0 ]= 66170L ;
    } 
    backerror () ;
    f = 0 ;
  } 
  curval = f ;
} 
void 
zscansomethinginternal ( smallnumber level , boolean negative ) 
{
  /* 10 */ scansomethinginternal_regmem 
  halfword m  ;
  halfword q  ;
  fourquarters i  ;
  integer p  ;
  m = curchr ;
  switch ( curcmd ) 
  {case 88 : 
    {
      scancharnum () ;
      if ( m == 983872L ) 
      {
	curval1 = newequiv ( 983872L + curval ) ;
	if ( ( ( curval1 / 16777216L ) > 8 ) || ( ( ( curval1 % 16777216L ) / 
	65536L ) > 15 ) || ( ( curval1 % 65536L ) > 255 ) ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 65974L ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 65975L ;
	    helpline [0 ]= 65976L ;
	  } 
	  interror ( curval1 ) ;
	  curval1 = 0 ;
	} 
	curval1 = ( ( curval1 / 16777216L ) * 4096 ) + ( ( ( curval1 % 
	16777216L ) / 65536L ) * 256 ) + ( curval1 % 65536L ) ;
	{
	  curval = curval1 ;
	  curvallevel = 0 ;
	} 
      } 
      else if ( m == ( 984128L ) ) 
      {
	curval = newequiv ( 983872L + curval ) ;
	curvallevel = 0 ;
      } 
      else if ( m == 1115020L ) 
      {
	curval1 = newequiv1 ( 1115020L + curval ) ;
	curval = newequiv ( 1115020L + curval ) ;
	curval1 = ( curval1 / 65536L ) * 256 + ( curval1 % 65536L ) ;
	curval = ( curval / 65536L ) * 256 + ( curval % 65536L ) ;
	if ( ( ( curval / 256 ) % 256 > 15 ) || ( curval1 >= 4096 ) ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 65977L ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 65978L ;
	    helpline [0 ]= 65976L ;
	  } 
	  error () ;
	  {
	    curval = 0 ;
	    curvallevel = 0 ;
	  } 
	} 
	else {
	    
	  curval = curval * 4096 + curval1 ;
	  curvallevel = 0 ;
	} 
      } 
      else if ( m == ( 1115276L ) ) 
      {
	{
	  curval = -1 ;
	  curvallevel = 0 ;
	} 
      } 
      else if ( m < 983872L ) 
      {
	curval = newequiv ( m + curval ) ;
	curvallevel = 0 ;
      } 
      else {
	  
	curval = neweqtbint ( m + curval ) ;
	curvallevel = 0 ;
      } 
    } 
    break ;
  case 74 : 
  case 75 : 
  case 89 : 
  case 90 : 
  case 91 : 
    if ( level != 6 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 65979L ) ;
      } 
      {
	helpptr = 3 ;
	helpline [2 ]= 65980L ;
	helpline [1 ]= 65981L ;
	helpline [0 ]= 65982L ;
      } 
      backerror () ;
      {
	curval = 0 ;
	curvallevel = 1 ;
      } 
    } 
    else if ( curcmd <= 75 ) 
    {
      if ( curcmd < 75 ) 
      {
	scaneightbitint () ;
	m = 589885L + curval ;
      } 
      {
	curval = newequiv ( m ) ;
	curvallevel = 6 ;
      } 
    } 
    else {
	
      backinput () ;
      scanfontident () ;
      {
	curval = 196620L + curval ;
	curvallevel = 5 ;
      } 
    } 
    break ;
  case 76 : 
    {
      curval = neweqtbint ( m ) ;
      curvallevel = 0 ;
    } 
    break ;
  case 94 : 
    {
      scaneightbitint () ;
      m = curval ;
      if ( newequiv ( 655423L + m ) != 0 ) 
      curval = mem [newequiv ( 655423L + m ) + 7 ].cint ;
      else curval = 0 ;
      curvallevel = 4 ;
    } 
    break ;
  case 95 : 
    {
      curval = neweqtbint ( m ) ;
      curvallevel = 4 ;
    } 
    break ;
  case 77 : 
    {
      curval = neweqtbsc ( m ) ;
      curvallevel = 1 ;
    } 
    break ;
  case 78 : 
    {
      curval = newequiv ( m ) ;
      curvallevel = 2 ;
    } 
    break ;
  case 79 : 
    {
      curval = newequiv ( m ) ;
      curvallevel = 3 ;
    } 
    break ;
  case 82 : 
    if ( abs ( curlist .modefield ) != m ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 65996L ) ;
      } 
      printcmdchr ( 82 , m ) ;
      {
	helpptr = 4 ;
	helpline [3 ]= 65997L ;
	helpline [2 ]= 65998L ;
	helpline [1 ]= 65999L ;
	helpline [0 ]= 66000L ;
      } 
      error () ;
      if ( level != 6 ) 
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
  case 83 : 
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
  case 85 : 
    {
      if ( m == 0 ) 
      curval = deadcycles ;
      else if ( m == 2 ) 
      curval = interaction ;
      else curval = insertpenalties ;
      curvallevel = 0 ;
    } 
    break ;
  case 84 : 
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
  case 87 : 
    {
      if ( m > 524320L ) 
      {
	scanint () ;
	if ( ( newequiv ( m ) == 0 ) || ( curval < 0 ) ) 
	curval = 0 ;
	else {
	    
	  if ( curval > mem [newequiv ( m ) + 1 ].cint ) 
	  curval = mem [newequiv ( m ) + 1 ].cint ;
	  curval = mem [newequiv ( m ) + curval + 1 ].cint ;
	} 
      } 
      else if ( newequiv ( 524320L ) == 0 ) 
      curval = 0 ;
      else curval = mem [newequiv ( 524320L ) ].hh .v.LH ;
      curvallevel = 0 ;
    } 
    break ;
  case 86 : 
    if ( m <= 3 ) 
    {
      scanregisternum () ;
      if ( curval < 65536L ) 
      q = newequiv ( 655423L + curval ) ;
      else {
	  
	findsaelement ( 7 , curval , false ) ;
	if ( curptr == 0 ) 
	q = 0 ;
	else q = mem [curptr + 1 ].hh .v.RH ;
      } 
      if ( q == 0 ) 
      curval = 0 ;
      else curval = mem [q + m ].cint ;
      curvallevel = 1 ;
    } 
    else {
	
      confusion ( 66001L ) ;
    } 
    break ;
  case 70 : 
  case 71 : 
  case 72 : 
    {
      curval = curchr ;
      curvallevel = 0 ;
    } 
    break ;
  case 80 : 
    if ( m == 0 ) 
    {
      findfontdimen ( false ) ;
      fonttables [dimenfont ][ fonttables [dimenfont ][ 0 ].cint ].cint = 
      0 ;
      {
	curval = fonttables [dimenfont ][ curval ].cint ;
	curvallevel = 1 ;
      } 
    } 
    else {
	
      scancharnum () ;
      if ( m == 1 ) 
      {
	curval = fonttables [mainf ][ fonttables [mainf ][ 36 ].cint + 
	fonttables [mainf ][ fonttables [mainf ][ 34 ].cint - fonttables [
	mainf ][ 5 ].cint + curval ].qqqq .b0 ].cint ;
      } 
      else if ( m == 2 ) 
      {
	curval = fonttables [mainf ][ fonttables [mainf ][ 37 ].cint + ( 
	fonttables [mainf ][ fonttables [mainf ][ 34 ].cint - fonttables [
	mainf ][ 5 ].cint + curval ].qqqq .b1 ) / 256 ].cint ;
      } 
      else if ( m == 3 ) 
      {
	curval = fonttables [mainf ][ fonttables [mainf ][ 38 ].cint + ( 
	fonttables [mainf ][ fonttables [mainf ][ 34 ].cint - fonttables [
	mainf ][ 5 ].cint + curval ].qqqq .b1 ) % 256 ].cint ;
      } 
      else if ( m == 4 ) 
      {
	curval = fonttables [mainf ][ fonttables [mainf ][ 39 ].cint + ( 
	fonttables [mainf ][ fonttables [mainf ][ 34 ].cint - fonttables [
	mainf ][ 5 ].cint + curval ].qqqq .b2 ) / 256 ].cint ;
      } 
      else confusion ( 65810L ) ;
      curvallevel = 1 ;
    } 
    break ;
  case 81 : 
    {
      scanfontident () ;
      if ( m == 0 ) 
      {
	curval = fonttables [curval ][ 16 ].cint ;
	curvallevel = 0 ;
      } 
      else {
	  
	curval = fonttables [curval ][ 17 ].cint ;
	curvallevel = 0 ;
      } 
    } 
    break ;
  case 92 : 
    {
      scaneightbitint () ;
      switch ( m ) 
      {case 0 : 
	curval = neweqtbint ( 1049484L + curval ) ;
	break ;
      case 1 : 
	curval = neweqtbsc ( 1180581L + ( curval ) ) ;
	break ;
      case 2 : 
	curval = newequiv ( 393248L + curval ) ;
	break ;
      case 3 : 
	curval = newequiv ( 458784L + curval ) ;
	break ;
      } 
      curvallevel = m ;
    } 
    break ;
  case 73 : 
    if ( m > 3 ) {
	
      if ( m >= 28 ) 
      {
	if ( m < 29 ) 
	{
	  switch ( m ) 
	  {case 28 : 
	    scanmuglue () ;
	    break ;
	  } 
	  curvallevel = 2 ;
	} 
	else if ( m < 30 ) 
	{
	  switch ( m ) 
	  {case 29 : 
	    scannormalglue () ;
	    break ;
	  } 
	  curvallevel = 3 ;
	} 
	else {
	    
	  curvallevel = m - 30 ;
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
      else if ( m >= 19 ) 
      {
	switch ( m ) 
	{case 19 : 
	case 20 : 
	case 21 : 
	case 22 : 
	  {
	    scanfontident () ;
	    q = curval ;
	    scancharnum () ;
	    if ( ( fonttables [q ][ 12 ].cint <= curval ) && ( fonttables [
	    q ][ 13 ].cint >= curval ) ) 
	    {
	      i = fonttables [q ][ fonttables [q ][ 34 ].cint - fonttables 
	      [q ][ 5 ].cint + curval ].qqqq ;
	      switch ( m ) 
	      {case 19 : 
		curval = fonttables [q ][ fonttables [q ][ 36 ].cint + i 
		.b0 ].cint ;
		break ;
	      case 20 : 
		curval = fonttables [q ][ fonttables [q ][ 37 ].cint + ( i 
		.b1 ) / 256 ].cint ;
		break ;
	      case 21 : 
		curval = fonttables [q ][ fonttables [q ][ 38 ].cint + ( i 
		.b1 ) % 256 ].cint ;
		break ;
	      case 22 : 
		curval = fonttables [q ][ fonttables [q ][ 39 ].cint + ( i 
		.b2 ) / 256 ].cint ;
		break ;
	      } 
	    } 
	    else curval = 0 ;
	  } 
	  break ;
	case 23 : 
	case 24 : 
	case 25 : 
	  {
	    q = curchr - 23 ;
	    scanint () ;
	    if ( ( newequiv ( 524320L ) == 0 ) || ( curval <= 0 ) ) 
	    curval = 0 ;
	    else {
		
	      if ( q == 2 ) 
	      {
		q = curval % 2 ;
		curval = ( curval + q ) / 2 ;
	      } 
	      if ( curval > mem [newequiv ( 524320L ) ].hh .v.LH ) 
	      curval = mem [newequiv ( 524320L ) ].hh .v.LH ;
	      curval = mem [newequiv ( 524320L ) + 2 * curval - q ].cint ;
	    } 
	    curvallevel = 1 ;
	  } 
	  break ;
	case 26 : 
	case 27 : 
	  {
	    scannormalglue () ;
	    q = curval ;
	    if ( m == 26 ) 
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
	{case 4 : 
	  curval = line ;
	  break ;
	case 5 : 
	  curval = lastbadness ;
	  break ;
	case 6 : 
	  curval = 0 ;
	  break ;
	case 7 : 
	  curval = 1 ;
	  break ;
	case 11 : 
	  curval = 2 ;
	  break ;
	case 8 : 
	  curval = 0 ;
	  break ;
	case 9 : 
	  curval = 15 ;
	  break ;
	case 10 : 
	  curval = 1 ;
	  break ;
	case 12 : 
	  curval = curlevel - 1 ;
	  break ;
	case 13 : 
	  curval = curgroup ;
	  break ;
	case 14 : 
	  {
	    q = condptr ;
	    curval = 0 ;
	    while ( q != 0 ) {
		
	      incr ( curval ) ;
	      q = mem [q ].hh .v.RH ;
	    } 
	  } 
	  break ;
	case 15 : 
	  if ( condptr == 0 ) 
	  curval = 0 ;
	  else if ( curif < 32 ) 
	  curval = curif + 1 ;
	  else curval = - (integer) ( curif - 31 ) ;
	  break ;
	case 16 : 
	  if ( ( iflimit == 4 ) || ( iflimit == 3 ) ) 
	  curval = 1 ;
	  else if ( iflimit == 2 ) 
	  curval = -1 ;
	  else curval = 0 ;
	  break ;
	case 17 : 
	case 18 : 
	  {
	    scannormalglue () ;
	    q = curval ;
	    if ( m == 17 ) 
	    curval = mem [q ].hh.b0 ;
	    else curval = mem [q ].hh.b1 ;
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
      if ( curchr == 3 ) 
      {
	curval = 0 ;
	if ( ( curlist .tailfield == curlist .headfield ) || ( curlist 
	.modefield == 0 ) ) 
	curval = -1 ;
      } 
      else curvallevel = curchr ;
      if ( ! ( curlist .tailfield >= himemmin ) && ( curlist .modefield != 0 ) 
      ) 
      switch ( curchr ) 
      {case 0 : 
	if ( mem [curlist .tailfield ].hh.b0 == 12 ) 
	curval = mem [curlist .tailfield + 1 ].cint ;
	break ;
      case 1 : 
	if ( mem [curlist .tailfield ].hh.b0 == 11 ) 
	curval = mem [curlist .tailfield + 1 ].cint ;
	break ;
      case 2 : 
	if ( mem [curlist .tailfield ].hh.b0 == 10 ) 
	{
	  curval = mem [curlist .tailfield + 1 ].hh .v.LH ;
	  if ( mem [curlist .tailfield ].hh.b1 == 99 ) 
	  curvallevel = 3 ;
	} 
	break ;
      case 3 : 
	if ( ( mem [curlist .tailfield ].hh.b0 != 9 ) ) {
	    
	  if ( mem [curlist .tailfield ].hh.b0 <= 13 ) 
	  curval = mem [curlist .tailfield ].hh.b0 + 1 ;
	  else curval = 15 ;
	} 
	break ;
      } 
      else if ( ( curlist .modefield == 1 ) && ( curlist .tailfield == curlist 
      .headfield ) ) 
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
    default: 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66002L ) ;
      } 
      printcmdchr ( curcmd , curchr ) ;
      print ( 66003L ) ;
      printesc ( 65838L ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 66000L ;
      } 
      error () ;
      if ( level != 6 ) 
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
  /* 30 */ scanint_regmem 
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
    if ( curtok == 786477L ) 
    {
      negative = ! negative ;
      curtok = 786475L ;
    } 
  } while ( ! ( curtok != 786475L ) ) ;
  if ( curtok == 786528L ) 
  {
    gettoken () ;
    if ( curtok < 1048575L ) 
    {
      curval = curchr ;
      if ( curcmd <= 2 ) {
	  
	if ( curcmd == 2 ) 
	incr ( alignstate ) ;
	else decr ( alignstate ) ;
      } 
    } 
    else if ( curtok < 1114112L ) 
    curval = curtok - 1048576L ;
    else curval = curtok - 1114112L ;
    if ( curval > 65535L ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66023L ) ;
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 66024L ;
	helpline [0 ]= 66025L ;
      } 
      curval = 48 ;
      backerror () ;
    } 
    else {
	
      getxtoken () ;
      if ( curcmd != 10 ) 
      backinput () ;
    } 
  } 
  else if ( ( curcmd >= 70 ) && ( curcmd <= 95 ) ) 
  scansomethinginternal ( 0 , false ) ;
  else {
      
    radix = 10 ;
    m = 214748364L ;
    if ( curtok == 786471L ) 
    {
      radix = 8 ;
      m = 268435456L ;
      getxtoken () ;
    } 
    else if ( curtok == 786466L ) 
    {
      radix = 16 ;
      m = 134217728L ;
      getxtoken () ;
    } 
    vacuous = true ;
    curval = 0 ;
    while ( true ) {
	
      if ( ( curtok < 786480L + radix ) && ( curtok >= 786480L ) && ( curtok 
      <= 786489L ) ) 
      d = curtok - 786480L ;
      else if ( radix == 16 ) {
	  
	if ( ( curtok <= 720966L ) && ( curtok >= 720961L ) ) 
	d = curtok - 720951L ;
	else if ( ( curtok <= 786502L ) && ( curtok >= 786497L ) ) 
	d = curtok - 786487L ;
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
	    else printnl ( 65548L ) ;
	    print ( 66026L ) ;
	  } 
	  {
	    helpptr = 2 ;
	    helpline [1 ]= 66027L ;
	    helpline [0 ]= 66028L ;
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
	else printnl ( 65548L ) ;
	print ( 65979L ) ;
      } 
      {
	helpptr = 3 ;
	helpline [2 ]= 65980L ;
	helpline [1 ]= 65981L ;
	helpline [0 ]= 65982L ;
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
      if ( curtok == 786477L ) 
      {
	negative = ! negative ;
	curtok = 786475L ;
      } 
    } while ( ! ( curtok != 786475L ) ) ;
    if ( ( curcmd >= 70 ) && ( curcmd <= 95 ) ) {
	
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
      if ( curtok == 786476L ) 
      curtok = 786478L ;
      if ( curtok != 786478L ) 
      scanint () ;
      else {
	  
	radix = 10 ;
	curval = 0 ;
      } 
      if ( curtok == 786476L ) 
      curtok = 786478L ;
      if ( ( radix == 10 ) && ( curtok == 786478L ) ) 
      {
	k = 0 ;
	p = 0 ;
	gettoken () ;
	while ( true ) {
	    
	  getxtoken () ;
	  if ( ( curtok > 786489L ) || ( curtok < 786480L ) ) 
	  goto lab31 ;
	  if ( k < 17 ) 
	  {
	    q = getavail () ;
	    mem [q ].hh .v.RH = p ;
	    mem [q ].hh .v.LH = curtok - 786480L ;
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
      
    if ( scankeyword ( 65597L ) ) 
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
	    else printnl ( 65548L ) ;
	    print ( 66030L ) ;
	  } 
	  print ( 66031L ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 66032L ;
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
  if ( ( curcmd < 70 ) || ( curcmd > 95 ) ) 
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
  if ( scankeyword ( 66033L ) ) 
  v = ( fonttables [newequiv ( 720959L ) ][ fonttables [newequiv ( 720959L ) 
  ][ 43 ].cint + 6 ].cint ) ;
  else if ( scankeyword ( 66034L ) ) 
  v = ( fonttables [newequiv ( 720959L ) ][ fonttables [newequiv ( 720959L ) 
  ][ 43 ].cint + 5 ].cint ) ;
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
      
    if ( scankeyword ( 65623L ) ) 
    goto lab88 ;
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66030L ) ;
      } 
      print ( 66035L ) ;
      {
	helpptr = 4 ;
	helpline [3 ]= 66036L ;
	helpline [2 ]= 66037L ;
	helpline [1 ]= 66038L ;
	helpline [0 ]= 66039L ;
      } 
      error () ;
      goto lab88 ;
    } 
  } 
  if ( scankeyword ( 66029L ) ) 
  {
    preparemag () ;
    if ( neweqtbint ( 1049425L ) != 1000 ) 
    {
      curval = xnoverd ( curval , 1000 , neweqtbint ( 1049425L ) ) ;
      f = ( 1000 * f + 65536L * texremainder ) / neweqtbint ( 1049425L ) ;
      curval = curval + ( f / 65536L ) ;
      f = f % 65536L ;
    } 
  } 
  if ( scankeyword ( 65683L ) ) 
  goto lab88 ;
  if ( scankeyword ( 66040L ) ) 
  {
    num = 7227 ;
    denom = 100 ;
  } 
  else if ( scankeyword ( 66041L ) ) 
  {
    num = 12 ;
    denom = 1 ;
  } 
  else if ( scankeyword ( 66042L ) ) 
  {
    num = 7227 ;
    denom = 254 ;
  } 
  else if ( scankeyword ( 66043L ) ) 
  {
    num = 7227 ;
    denom = 2540 ;
  } 
  else if ( scankeyword ( 66044L ) ) 
  {
    num = 7227 ;
    denom = 7200 ;
  } 
  else if ( scankeyword ( 66045L ) ) 
  {
    num = 1238 ;
    denom = 1157 ;
  } 
  else if ( scankeyword ( 66046L ) ) 
  {
    num = 14856 ;
    denom = 1157 ;
  } 
  else if ( scankeyword ( 66047L ) ) 
  goto lab30 ;
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66030L ) ;
    } 
    print ( 66048L ) ;
    {
      helpptr = 6 ;
      helpline [5 ]= 66049L ;
      helpline [4 ]= 66050L ;
      helpline [3 ]= 66051L ;
      helpline [2 ]= 66037L ;
      helpline [1 ]= 66038L ;
      helpline [0 ]= 66039L ;
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
      else printnl ( 65548L ) ;
      print ( 66052L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66053L ;
      helpline [0 ]= 66054L ;
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
    if ( curtok == 786477L ) 
    {
      negative = ! negative ;
      curtok = 786475L ;
    } 
  } while ( ! ( curtok != 786475L ) ) ;
  if ( ( curcmd >= 70 ) && ( curcmd <= 95 ) ) 
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
  if ( scankeyword ( 66055L ) ) 
  {
    scandimen ( mu , true , false ) ;
    mem [q + 2 ].cint = curval ;
    mem [q ].hh.b0 = curorder ;
  } 
  if ( scankeyword ( 66056L ) ) 
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
  p = 0 ;
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
  if ( curtok == 786472L ) 
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
  if ( curtok == 786475L ) 
  o = 1 ;
  else if ( curtok == 786477L ) 
  o = 2 ;
  else if ( curtok == 786474L ) 
  o = 3 ;
  else if ( curtok == 786479L ) 
  o = 4 ;
  else {
      
    o = 0 ;
    if ( p == 0 ) 
    {
      if ( curcmd != 0 ) 
      backinput () ;
    } 
    else if ( curtok != 786473L ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66774L ) ;
      } 
      {
	helpptr = 1 ;
	helpline [0 ]= 66775L ;
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
  if ( p != 0 ) 
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
      else printnl ( 65548L ) ;
      print ( 66575L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66773L ;
      helpline [0 ]= 66577L ;
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
  if ( curcmd == 35 ) 
  {
    mem [q + 1 ].cint = 26214 ;
    mem [q + 4 ].hh .v.LH = neweqtbint ( 1049480L ) ;
  } 
  else {
      
    mem [q + 3 ].cint = 26214 ;
    mem [q + 2 ].cint = 0 ;
    mem [q + 4 ].hh .v.LH = neweqtbint ( 1049482L ) ;
  } 
  lab21: if ( scankeyword ( 66057L ) ) 
  {
    scandimen ( false , false , false ) ;
    mem [q + 1 ].cint = curval ;
    goto lab21 ;
  } 
  if ( scankeyword ( 66058L ) ) 
  {
    scandimen ( false , false , false ) ;
    mem [q + 3 ].cint = curval ;
    goto lab21 ;
  } 
  if ( scankeyword ( 66059L ) ) 
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
  mem [defref ].hh .v.LH = 0 ;
  p = defref ;
  scanleftbrace () ;
  unbalance = 1 ;
  while ( true ) {
      
    gettoken () ;
    if ( curtok < 196608L ) {
	
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
  if ( q == 0 ) 
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
    overflow ( 65543L , poolsize - initpoolptr ) ;
  } 
  s = makestring () ;
  strpool [poolptr ]= 32 ;
  l = strstartar [s - 65536L ];
  nl = neweqtbint ( 1049457L ) ;
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
    poolptr = strstartar [strptr - 65536L ];
  } 
  beginfilereading () ;
  line = 0 ;
  curinput .limitfield = curinput .startfield ;
  curinput .locfield = curinput .limitfield + 1 ;
  if ( neweqtbint ( 1049472L ) > 0 ) 
  {
    if ( termoffset > maxprintline - 3 ) 
    println () ;
    else if ( ( termoffset > 0 ) || ( fileoffset > 0 ) ) 
    printchar ( 32 ) ;
    curinput .namefield = 19 ;
    print ( 66759L ) ;
    incr ( openparens ) ;
    fflush ( stdout ) ;
  } 
  else curinput .namefield = 18 ;
} 
halfword 
zstrtoks ( poolpointer b ) 
{
  register halfword Result; strtoks_regmem 
  halfword p  ;
  halfword q  ;
  halfword t  ;
  poolpointer k  ;
  {
    if ( poolptr + 1 > poolsize ) 
    overflow ( 65543L , poolsize - initpoolptr ) ;
  } 
  p = memtop - 3 ;
  mem [p ].hh .v.RH = 0 ;
  k = b ;
  while ( k < poolptr ) {
      
    t = strpool [k ];
    if ( t == 32 ) 
    t = 655392L ;
    else t = 786432L + t ;
    {
      {
	q = avail ;
	if ( q == 0 ) 
	q = getavail () ;
	else {
	    
	  avail = mem [q ].hh .v.RH ;
	  mem [q ].hh .v.RH = 0 ;
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
  scansomethinginternal ( 6 , false ) ;
  if ( curvallevel >= 5 ) 
  {
    p = memtop - 3 ;
    mem [p ].hh .v.RH = 0 ;
    if ( curvallevel == 5 ) 
    {
      q = getavail () ;
      mem [p ].hh .v.RH = q ;
      mem [q ].hh .v.LH = 1048575L + curval ;
      p = q ;
    } 
    else if ( curval != 0 ) 
    {
      r = mem [curval ].hh .v.RH ;
      while ( r != 0 ) {
	  
	{
	  {
	    q = avail ;
	    if ( q == 0 ) 
	    q = getavail () ;
	    else {
		
	      avail = mem [q ].hh .v.RH ;
	      mem [q ].hh .v.RH = 0 ;
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
    case 4 : 
      printdir ( curval ) ;
      break ;
    case 1 : 
      {
	printscaled ( curval ) ;
	print ( 65683L ) ;
      } 
      break ;
    case 2 : 
      {
	printspec ( curval , 65683L ) ;
	deleteglueref ( curval ) ;
      } 
      break ;
    case 3 : 
      {
	printspec ( curval , 65623L ) ;
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
  smallnumber c  ;
  smallnumber savescannerstatus  ;
  poolpointer b  ;
  c = curchr ;
  switch ( c ) 
  {case 0 : 
  case 1 : 
    scanint () ;
    break ;
  case 2 : 
  case 3 : 
    {
      savescannerstatus = scannerstatus ;
      scannerstatus = 0 ;
      gettoken () ;
      scannerstatus = savescannerstatus ;
    } 
    break ;
  case 4 : 
    scanfontident () ;
    break ;
  case 5 : 
    ;
    break ;
  case 6 : 
    ;
    break ;
  case 7 : 
    ;
    break ;
  case 8 : 
    if ( jobname == 0 ) 
    openlogfile () ;
    break ;
  case 9 : 
    ;
    break ;
  case 10 : 
    ;
    break ;
  case 11 : 
    ;
    break ;
  } 
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
  case 2 : 
    if ( curcs != 0 ) 
    sprintcs ( curcs ) ;
    else printchar ( curchr ) ;
    break ;
  case 3 : 
    printmeaning () ;
    break ;
  case 4 : 
    {
      print ( fonttables [curval ][ 10 ].cint ) ;
      if ( fonttables [curval ][ 6 ].cint != fonttables [curval ][ 7 ]
      .cint ) 
      {
	print ( 66069L ) ;
	printscaled ( fonttables [curval ][ 6 ].cint ) ;
	print ( 65683L ) ;
      } 
    } 
    break ;
  case 5 : 
    print ( 65536L ) ;
    break ;
  case 6 : 
    print ( 65537L ) ;
    break ;
  case 7 : 
    print ( 65538L ) ;
    break ;
  case 8 : 
    print ( jobname ) ;
    break ;
  case 9 : 
    print ( 65541L ) ;
    break ;
  case 10 : 
    print ( 65540L ) ;
    break ;
  case 11 : 
    print ( 65539L ) ;
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
  mem [defref ].hh .v.LH = 0 ;
  p = defref ;
  hashbrace = 0 ;
  t = 786480L ;
  if ( macrodef ) 
  {
    while ( true ) {
	
      gettoken () ;
      if ( curtok < 196608L ) 
      goto lab31 ;
      if ( curcmd == 6 ) 
      {
	s = 851968L + curchr ;
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
	    mem [q ].hh .v.LH = 917504L ;
	    p = q ;
	  } 
	  goto lab30 ;
	} 
	if ( t == 786489L ) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 66072L ) ;
	  } 
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 66073L ;
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
	      else printnl ( 65548L ) ;
	      print ( 66074L ) ;
	    } 
	    {
	      helpptr = 2 ;
	      helpline [1 ]= 66075L ;
	      helpline [0 ]= 66076L ;
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
      mem [q ].hh .v.LH = 917504L ;
      p = q ;
    } 
    if ( curcmd == 2 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 65966L ) ;
      } 
      incr ( alignstate ) ;
      {
	helpptr = 2 ;
	helpline [1 ]= 66070L ;
	helpline [0 ]= 66071L ;
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
	if ( curcmd >= 128 ) {
	    
	  if ( mem [mem [curchr ].hh .v.RH ].hh .v.LH == 917505L ) 
	  {
	    curcmd = 0 ;
	    curchr = 65537L ;
	  } 
	} 
	if ( curcmd <= 117 ) 
	goto lab32 ;
	if ( curcmd != 126 ) 
	expand () ;
	else {
	    
	  q = thetoks () ;
	  if ( mem [memtop - 3 ].hh .v.RH != 0 ) 
	  {
	    mem [p ].hh .v.RH = mem [memtop - 3 ].hh .v.RH ;
	    p = q ;
	  } 
	} 
      } 
      lab32: xtoken () ;
    } 
    else gettoken () ;
    if ( curtok < 196608L ) {
	
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
	    
	  if ( ( curtok <= 786480L ) || ( curtok > t ) ) 
	  {
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 65548L ) ;
	      print ( 66077L ) ;
	    } 
	    sprintcs ( warningindex ) ;
	    {
	      helpptr = 3 ;
	      helpline [2 ]= 66078L ;
	      helpline [1 ]= 66079L ;
	      helpline [0 ]= 66080L ;
	    } 
	    backerror () ;
	    curtok = s ;
	  } 
	  else curtok = 327632L + curchr ;
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
  mem [defref ].hh .v.LH = 0 ;
  p = defref ;
  {
    q = getavail () ;
    mem [p ].hh .v.RH = q ;
    mem [q ].hh .v.LH = 917504L ;
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
	  print ( 65624L ) ;
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
      else fatalerror ( 66081L ) ;
    } 
    else if ( readopen [m ]== 1 ) 
    {
      readfilemode [m ]= getfilemode ( readfile [m ], newequiv ( 589875L ) 
      ) ;
      if ( readfilemode [m ]> 0 ) 
      readfiletranslation [m ]= newequiv ( 589876L + readfilemode [m ]- 1 
      ) ;
      if ( newinputln ( readfile [m ], readfilemode [m ], 
      readfiletranslation [m ], false ) ) 
      readopen [m ]= 0 ;
      else {
	  
	aclose ( readfile [m ]) ;
	readopen [m ]= 2 ;
      } 
    } 
    else {
	
      if ( ! newinputln ( readfile [m ], readfilemode [m ], 
      readfiletranslation [m ], true ) ) 
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
	    else printnl ( 65548L ) ;
	    print ( 66082L ) ;
	  } 
	  printesc ( 65834L ) ;
	  {
	    helpptr = 1 ;
	    helpline [0 ]= 66083L ;
	  } 
	  alignstate = 1000000L ;
	  error () ;
	} 
      } 
    } 
    curinput .limitfield = last ;
    if ( ( neweqtbint ( 1049456L ) < 0 ) || ( neweqtbint ( 1049456L ) > 255 ) 
    ) 
    decr ( curinput .limitfield ) ;
    else buffer [curinput .limitfield ]= neweqtbint ( 1049456L ) ;
    first = curinput .limitfield + 1 ;
    curinput .locfield = curinput .startfield ;
    curinput .statefield = 33 ;
    if ( j == 1 ) 
    {
      while ( curinput .locfield <= curinput .limitfield ) {
	  
	curchr = buffer [curinput .locfield ];
	incr ( curinput .locfield ) ;
	if ( curchr == 32 ) 
	curtok = 655392L ;
	else curtok = curchr + 786432L ;
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
    if ( curcmd == 123 ) 
    {
      if ( l == 0 ) 
      goto lab30 ;
      if ( curchr == 2 ) 
      decr ( l ) ;
    } 
    else if ( curcmd == 122 ) 
    incr ( l ) ;
  } 
  lab30: scannerstatus = savescannerstatus ;
  if ( neweqtbint ( 1049471L ) > 0 ) 
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
	
      if ( q == 0 ) 
      confusion ( 66084L ) ;
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
  if ( neweqtbint ( 1049471L ) > 0 ) {
      
    if ( neweqtbint ( 1049444L ) <= 1 ) 
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
	    
	  if ( curchr == 65537L ) 
	  {
	    curcmd = 13 ;
	    curchr = curtok - 1048576L ;
	  } 
	} 
      } 
      if ( ( curcmd > 13 ) || ( curchr > 65535L ) ) 
      {
	m = 0 ;
	n = 65536L ;
      } 
      else {
	  
	m = curcmd ;
	n = curchr ;
      } 
      {
	getxtoken () ;
	if ( curcmd == 0 ) {
	    
	  if ( curchr == 65537L ) 
	  {
	    curcmd = 13 ;
	    curchr = curtok - 1048576L ;
	  } 
	} 
      } 
      if ( ( curcmd > 13 ) || ( curchr > 65535L ) ) 
      {
	curcmd = 0 ;
	curchr = 65536L ;
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
      if ( ( curtok >= 786492L ) && ( curtok <= 786494L ) ) 
      r = curtok - 786432L ;
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66108L ) ;
	} 
	printcmdchr ( 122 , thisif ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 66109L ;
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
    b = ( abs ( curlist .modefield ) == 119 ) ;
    break ;
  case 7 : 
    b = ( abs ( curlist .modefield ) == 237 ) ;
    break ;
  case 8 : 
    b = ( curlist .modefield < 0 ) ;
    break ;
  case 9 : 
  case 10 : 
  case 11 : 
    {
      scanregisternum () ;
      if ( curval < 65536L ) 
      p = newequiv ( 655423L + curval ) ;
      else {
	  
	findsaelement ( 7 , curval , false ) ;
	if ( curptr == 0 ) 
	p = 0 ;
	else p = mem [curptr + 1 ].hh .v.RH ;
      } 
      if ( thisif == 9 ) 
      b = ( p == 0 ) ;
      else if ( p == 0 ) 
      b = false ;
      else if ( thisif == 10 ) 
      b = ( mem [p ].hh.b0 == 0 ) ;
      else b = ( mem [p ].hh.b0 == 1 ) ;
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
      else if ( curcmd < 128 ) 
      b = ( curchr == q ) ;
      else {
	  
	p = mem [curchr ].hh .v.RH ;
	q = mem [newequiv ( n ) ].hh .v.RH ;
	if ( p == q ) 
	b = true ;
	else {
	    
	  while ( ( p != 0 ) && ( q != 0 ) ) if ( mem [p ].hh .v.LH != mem [
	  q ].hh .v.LH ) 
	  p = 0 ;
	  else {
	      
	    p = mem [p ].hh .v.RH ;
	    q = mem [q ].hh .v.RH ;
	  } 
	  b = ( ( p == 0 ) && ( q == 0 ) ) ;
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
      b = ( curcmd != 118 ) ;
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
      if ( curcmd != 67 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 65934L ) ;
	} 
	printesc ( 65795L ) ;
	print ( 65935L ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 65936L ;
	  helpline [0 ]= 65937L ;
	} 
	backerror () ;
      } 
      m = first ;
      p = mem [n ].hh .v.RH ;
      while ( p != 0 ) {
	  
	if ( m >= maxbufstack ) 
	{
	  maxbufstack = m + 1 ;
	  if ( maxbufstack == bufsize ) 
	  overflow ( 65542L , bufsize ) ;
	} 
	buffer [m ]= mem [p ].hh .v.LH % 256 ;
	incr ( m ) ;
	p = mem [p ].hh .v.RH ;
      } 
      if ( m > first + 1 ) 
      curcs = idlookup ( first , m - first ) ;
      else if ( m == first ) 
      curcs = 131073L ;
      else curcs = 65537L + buffer [first ];
      flushlist ( n ) ;
      b = ( neweqtype ( curcs ) != 118 ) ;
    } 
    break ;
  case 19 : 
    {
      scanfontident () ;
      n = curval ;
      scancharnum () ;
      if ( ( fonttables [n ][ 12 ].cint <= curval ) && ( fonttables [n ][ 
      13 ].cint >= curval ) ) 
      b = ( fonttables [n ][ fonttables [n ][ 34 ].cint - fonttables [n ][ 
      5 ].cint + curval ].qqqq .b0 > 0 ) ;
      else b = false ;
    } 
    break ;
  case 16 : 
    {
      scanint () ;
      n = curval ;
      if ( neweqtbint ( 1049444L ) > 1 ) 
      {
	begindiagnostic () ;
	print ( 66110L ) ;
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
  if ( neweqtbint ( 1049444L ) > 1 ) 
  {
    begindiagnostic () ;
    if ( b ) 
    print ( 66106L ) ;
    else print ( 66107L ) ;
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
	else printnl ( 65548L ) ;
	print ( 66104L ) ;
      } 
      printesc ( 66102L ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 66105L ;
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
      overflow ( 65543L , poolsize - initpoolptr ) ;
    } 
    {
      strpool [poolptr ]= c ;
      incr ( poolptr ) ;
    } 
    if ( ISDIRSEP ( c ) ) 
    {
      areadelimiter = ( poolptr - strstartar [strptr - 65536L ]) ;
      extdelimiter = 0 ;
    } 
    else if ( c == 46 ) 
    extdelimiter = ( poolptr - strstartar [strptr - 65536L ]) ;
    Result = true ;
  } 
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
  overflow ( 65544L , maxstrings - initstrptr ) ;
  {
    if ( poolptr + 6 > poolsize ) 
    overflow ( 65543L , poolsize - initpoolptr ) ;
  } 
  if ( areadelimiter != 0 ) 
  {
    mustquote = false ;
    s = strstartar [strptr - 65536L ];
    t = strstartar [strptr - 65536L ]+ areadelimiter ;
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
  s = strstartar [strptr - 65536L ]+ areadelimiter ;
  if ( extdelimiter == 0 ) 
  t = poolptr ;
  else t = strstartar [strptr - 65536L ]+ extdelimiter - 1 ;
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
    s = strstartar [strptr - 65536L ]+ extdelimiter - 1 ;
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
  curarea = 65624L ;
  else {
      
    curarea = strptr ;
    strstartar [strptr - 65535L ]= strstartar [strptr - 65536L ]+ 
    areadelimiter ;
    incr ( strptr ) ;
    tempstr = searchstring ( curarea ) ;
    if ( tempstr > 0 ) 
    {
      curarea = tempstr ;
      decr ( strptr ) ;
      {register integer for_end; j = strstartar [strptr - 65535L ];for_end 
      = poolptr - 1 ; if ( j <= for_end) do 
	{
	  strpool [j - areadelimiter ]= strpool [j ];
	} 
      while ( j++ < for_end ) ;} 
      poolptr = poolptr - areadelimiter ;
    } 
  } 
  if ( extdelimiter == 0 ) 
  {
    curext = 65624L ;
    curname = slowmakestring () ;
  } 
  else {
      
    curname = strptr ;
    strstartar [strptr - 65535L ]= strstartar [strptr - 65536L ]+ 
    extdelimiter - areadelimiter - 1 ;
    incr ( strptr ) ;
    curext = makestring () ;
    decr ( strptr ) ;
    tempstr = searchstring ( curname ) ;
    if ( tempstr > 0 ) 
    {
      curname = tempstr ;
      decr ( strptr ) ;
      {register integer for_end; j = strstartar [strptr - 65535L ];for_end 
      = poolptr - 1 ; if ( j <= for_end) do 
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
  nameoffile = xmallocarray ( char , 1 + length ( a ) + length ( n ) + length 
  ( e ) ) ;
  {register integer for_end; j = strstartar [a - 65536L ];for_end = 
  strstartar [a - 65535L ]- 1 ; if ( j <= for_end) do 
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
  {register integer for_end; j = strstartar [n - 65536L ];for_end = 
  strstartar [n - 65535L ]- 1 ; if ( j <= for_end) do 
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
  {register integer for_end; j = strstartar [e - 65536L ];for_end = 
  strstartar [e - 65535L ]- 1 ; if ( j <= for_end) do 
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
  nameoffile = xmallocarray ( char , 1 + n + ( b - a + 1 ) + 4 ) ;
  {register integer for_end; j = 1 ;for_end = n ; if ( j <= for_end) do 
    {
      c = TEXformatdefault [j ];
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
      c = TEXformatdefault [j ];
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
  poolptr - strstartar [strptr - 65536L ]) > 0 ) ) 
  Result = 63 ;
  else {
      
    {register integer for_end; k = 1 ;for_end = namelength ; if ( k <= 
    for_end) do 
      {
	strpool [poolptr ]= nameoffile [k ];
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
  while ( true ) {
      
    if ( ( curcmd > 12 ) || ( curchr > 65535L ) ) 
    {
      backinput () ;
      goto lab30 ;
    } 
    if ( ( curchr == 32 ) && ( curinput .statefield != 0 ) && ( curinput 
    .locfield > curinput .limitfield ) ) 
    goto lab30 ;
    if ( ! morename ( curchr ) ) 
    goto lab30 ;
    getxtoken () ;
  } 
  lab30: endname () ;
  nameinprogress = false ;
} 
void 
zpackjobname ( strnumber s ) 
{
  packjobname_regmem 
  curarea = 65624L ;
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
  if ( s == 66113L ) 
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 65548L ) ;
    print ( 66114L ) ;
  } 
  else {
      
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 65548L ) ;
    print ( 66115L ) ;
  } 
  printfilename ( curname , curarea , curext ) ;
  print ( 66116L ) ;
  if ( ( e == 66117L ) || ( e == 65624L ) ) 
  showcontext () ;
  println () ;
  printcstring ( promptfilenamehelpmsg ) ;
  if ( ( e != 65624L ) ) 
  {
    print ( 66118L ) ;
    print ( e ) ;
    print ( 39 ) ;
  } 
  print ( 41 ) ;
  println () ;
  printnl ( 66119L ) ;
  print ( s ) ;
  if ( interaction < 2 ) 
  fatalerror ( 66120L ) ;
  savedcurname = curname ;
  savedcurext = curext ;
  savedcurarea = curarea ;
  {
    ;
    print ( 65873L ) ;
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
  if ( ( length ( curname ) == 0 ) && ( curext == 65624L ) && ( curarea == 
  65624L ) ) 
  {
    curname = savedcurname ;
    curext = savedcurext ;
    curarea = savedcurarea ;
  } 
  else if ( curext == 65624L ) 
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
  jobname = getjobname ( 66123L ) ;
  packjobname ( 66124L ) ;
  recorderchangefilename ( stringcast ( nameoffile + 1 ) ) ;
  packjobname ( 66125L ) ;
  while ( ! aopenout ( logfile ) ) {
      
    selector = 17 ;
    promptfilename ( 66127L , 66125L ) ;
  } 
  texmflogname = amakenamestring ( logfile ) ;
  selector = 18 ;
  logopened = true ;
  {
    if ( srcspecialsp || filelineerrorstylep || parsefirstlinep ) 
    fprintf ( logfile , "%s%s%c%s%c%s",  "This is Aleph, Version 3.14159265-" , "1.15" , '-' ,     "2.1" , '-' , "0.1" ) ;
    else
    fprintf ( logfile , "%s%s%c%s%c%s",  "This is Aleph, Version 3.14159265-" , "1.15" , '-'     , "2.1" , '-' , "0.1" ) ;
    Fputs ( logfile ,  versionstring ) ;
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
    slowprint ( formatident ) ;
    printnl ( 65624L ) ;
    printint ( neweqtbint ( 1049429L ) ) ;
    printchar ( 32 ) ;
    months = " JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC" ;
    {register integer for_end; k = 3 * neweqtbint ( 1049430L ) - 2 ;for_end 
    = 3 * neweqtbint ( 1049430L ) ; if ( k <= for_end) do 
      putc ( months [k ],  logfile );
    while ( k++ < for_end ) ;} 
    printchar ( 32 ) ;
    printint ( neweqtbint ( 1049431L ) ) ;
    printchar ( 32 ) ;
    printtwo ( neweqtbint ( 1049428L ) / 60 ) ;
    printchar ( 58 ) ;
    printtwo ( neweqtbint ( 1049428L ) % 60 ) ;
    printnl ( 66128L ) ;
    printnl ( 66129L ) ;
    if ( ( eTeXmode == 1 ) ) 
    {
      ;
      putc ('\n',  logfile );
      Fputs ( logfile ,  "entering extended mode" ) ;
    } 
  } 
  inputstack [inputptr ]= curinput ;
  printnl ( 66126L ) ;
  l = inputstack [0 ].limitfield ;
  if ( buffer [l ]== neweqtbint ( 1049456L ) ) 
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
    if ( kpseinnameok ( nameoffile + 1 ) && aopenin ( inputfile [curinput 
    .indexfield ], kpsetexformat ) ) 
    goto lab30 ;
    endfilereading () ;
    promptfilename ( 66113L , 65624L ) ;
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
	poolptr = strstartar [strptr - 65536L ];
      } 
    } 
  } 
  if ( jobname == 0 ) 
  {
    jobname = getjobname ( curname ) ;
    openlogfile () ;
  } 
  if ( termoffset + length ( curinput .namefield ) > maxprintline - 2 ) 
  println () ;
  else if ( ( termoffset > 0 ) || ( fileoffset > 0 ) ) 
  printchar ( 32 ) ;
  printchar ( 40 ) ;
  incr ( openparens ) ;
  slowprint ( curinput .namefield ) ;
  fflush ( stdout ) ;
  curinput .statefield = 33 ;
  {
    line = 1 ;
    inputfilemode [curinput .indexfield ]= getfilemode ( inputfile [
    curinput .indexfield ], newequiv ( 589875L ) ) ;
    if ( inputfilemode [curinput .indexfield ]> 0 ) 
    inputfiletranslation [curinput .indexfield ]= newequiv ( 589876L + 
    inputfilemode [curinput .indexfield ]- 1 ) ;
    if ( newinputln ( inputfile [curinput .indexfield ], inputfilemode [
    curinput .indexfield ], inputfiletranslation [curinput .indexfield ], 
    false ) ) 
    ;
    firmuptheline () ;
    if ( ( neweqtbint ( 1049456L ) < 0 ) || ( neweqtbint ( 1049456L ) > 255 ) 
    ) 
    decr ( curinput .limitfield ) ;
    else buffer [curinput .limitfield ]= neweqtbint ( 1049456L ) ;
    first = curinput .limitfield + 1 ;
    curinput .locfield = curinput .startfield ;
  } 
} 
internalfontnumber 
zreadfontinfo ( halfword u , strnumber nom , strnumber aire , scaled s , 
quarterword offset , integer naturaldir ) 
{
  /* 30 11 45 */ register internalfontnumber Result; readfontinfo_regmem 
  fontindex k  ;
  boolean nametoolong  ;
  boolean fileopened  ;
  halfword lf, lh, bc, ec, nw, nh, nd, ni, nl, nk, ne, np  ;
  halfword fontdir  ;
  internalfontnumber f  ;
  internalfontnumber g  ;
  integer a, b, c, d  ;
  integer i, kparam, param, fontcounter  ;
  integer fontlevel, headerlength  ;
  integer nco, ncw, npc, nlw, neew  ;
  integer nki, nwi, nkf, nwf, nkm, nwm  ;
  integer nkr, nwr, nkg, nwg, nkp, nwp  ;
  integer tablesize[32]  ;
  integer bytesperentry, extracharbytes  ;
  integer repeatno, tablecounter  ;
  fourquarters qw  ;
  scaled sw  ;
  integer bchlabel  ;
  integer bchar  ;
  integer firsttwo  ;
  scaled z  ;
  integer alpha  ;
  unsigned char beta  ;
  g = 0 ;
  fileopened = false ;
  nametoolong = ( length ( nom ) > 255 ) || ( length ( aire ) > 255 ) ;
  if ( nametoolong ) 
  goto lab11 ;
  packfilename ( nom , aire , 65624L ) ;
  if ( ! ofmopenin ( tfmfile ) ) 
  goto lab11 ;
  fileopened = true ;
  nco = 0 ;
  ncw = 0 ;
  npc = 0 ;
  nki = 0 ;
  nwi = 0 ;
  nkf = 0 ;
  nwf = 0 ;
  nkm = 0 ;
  nwm = 0 ;
  nkr = 0 ;
  nwr = 0 ;
  nkg = 0 ;
  nwg = 0 ;
  nkp = 0 ;
  nwp = 0 ;
  {
    firsttwo = tfmtemp ;
    if ( firsttwo > 127 ) 
    goto lab11 ;
    tfmtemp = getc ( tfmfile ) ;
    firsttwo = firsttwo * 256 + tfmtemp ;
  } 
  if ( firsttwo != 0 ) 
  {
    fontlevel = -1 ;
    lf = firsttwo ;
    tfmtemp = getc ( tfmfile ) ;
    {
      lh = tfmtemp ;
      if ( lh > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      lh = lh * 256 + tfmtemp ;
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
    headerlength = 6 ;
    ncw = ( ec - bc + 1 ) ;
    nlw = nl ;
    neew = ne ;
  } 
  else {
      
    tfmtemp = getc ( tfmfile ) ;
    {
      fontlevel = tfmtemp ;
      if ( fontlevel > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      fontlevel = fontlevel * 256 + tfmtemp ;
    } 
    if ( ( fontlevel != 0 ) && ( fontlevel != 1 ) ) 
    goto lab11 ;
    tfmtemp = getc ( tfmfile ) ;
    {
      lf = tfmtemp ;
      if ( lf > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      lf = lf * 256 + tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      lf = lf * 256 + tfmtemp ;
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
      tfmtemp = getc ( tfmfile ) ;
      lh = lh * 256 + tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      lh = lh * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      bc = tfmtemp ;
      if ( bc > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      bc = bc * 256 + tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      bc = bc * 256 + tfmtemp ;
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
      tfmtemp = getc ( tfmfile ) ;
      ec = ec * 256 + tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      ec = ec * 256 + tfmtemp ;
    } 
    if ( ( bc > ec + 1 ) || ( ec > 65535L ) ) 
    goto lab11 ;
    if ( bc > 65535L ) 
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
      tfmtemp = getc ( tfmfile ) ;
      nw = nw * 256 + tfmtemp ;
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
      tfmtemp = getc ( tfmfile ) ;
      nh = nh * 256 + tfmtemp ;
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
      tfmtemp = getc ( tfmfile ) ;
      nd = nd * 256 + tfmtemp ;
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
      tfmtemp = getc ( tfmfile ) ;
      ni = ni * 256 + tfmtemp ;
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
      tfmtemp = getc ( tfmfile ) ;
      nl = nl * 256 + tfmtemp ;
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
      tfmtemp = getc ( tfmfile ) ;
      nk = nk * 256 + tfmtemp ;
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
      tfmtemp = getc ( tfmfile ) ;
      ne = ne * 256 + tfmtemp ;
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
      tfmtemp = getc ( tfmfile ) ;
      np = np * 256 + tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      np = np * 256 + tfmtemp ;
    } 
    tfmtemp = getc ( tfmfile ) ;
    {
      fontdir = tfmtemp ;
      if ( fontdir > 127 ) 
      goto lab11 ;
      tfmtemp = getc ( tfmfile ) ;
      fontdir = fontdir * 256 + tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      fontdir = fontdir * 256 + tfmtemp ;
      tfmtemp = getc ( tfmfile ) ;
      fontdir = fontdir * 256 + tfmtemp ;
    } 
    nlw = 2 * nl ;
    neew = 2 * ne ;
    if ( fontlevel == 0 ) 
    {
      headerlength = 14 ;
      ncw = 2 * ( ec - bc + 1 ) ;
    } 
    else {
	
      headerlength = 29 ;
      tfmtemp = getc ( tfmfile ) ;
      {
	nco = tfmtemp ;
	if ( nco > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nco = nco * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nco = nco * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nco = nco * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	ncw = tfmtemp ;
	if ( ncw > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	ncw = ncw * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	ncw = ncw * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	ncw = ncw * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	npc = tfmtemp ;
	if ( npc > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	npc = npc * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	npc = npc * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	npc = npc * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nki = tfmtemp ;
	if ( nki > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nki = nki * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nki = nki * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nki = nki * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nwi = tfmtemp ;
	if ( nwi > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nwi = nwi * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwi = nwi * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwi = nwi * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nkf = tfmtemp ;
	if ( nkf > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nkf = nkf * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nkf = nkf * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nkf = nkf * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nwf = tfmtemp ;
	if ( nwf > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nwf = nwf * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwf = nwf * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwf = nwf * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nkm = tfmtemp ;
	if ( nkm > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nkm = nkm * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nkm = nkm * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nkm = nkm * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nwm = tfmtemp ;
	if ( nwm > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nwm = nwm * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwm = nwm * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwm = nwm * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nkr = tfmtemp ;
	if ( nkr > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nkr = nkr * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nkr = nkr * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nkr = nkr * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nwr = tfmtemp ;
	if ( nwr > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nwr = nwr * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwr = nwr * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwr = nwr * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nkg = tfmtemp ;
	if ( nkg > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nkg = nkg * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nkg = nkg * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nkg = nkg * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nwg = tfmtemp ;
	if ( nwg > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nwg = nwg * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwg = nwg * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwg = nwg * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nkp = tfmtemp ;
	if ( nkp > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nkp = nkp * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nkp = nkp * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nkp = nkp * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	nwp = tfmtemp ;
	if ( nwp > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	nwp = nwp * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwp = nwp * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	nwp = nwp * 256 + tfmtemp ;
      } 
    } 
  } 
  if ( lf != ( headerlength + lh + ncw + nw + nh + nd + ni + nlw + nk + neew + 
  np + nki + nwi + nkf + nwf + nkm + nwm + nkr + nwr + nkg + nwg + nkp + nwp ) 
  ) 
  goto lab11 ;
  switch ( fontlevel ) 
  {case -1 : 
    lf = lf - 6 - lh ;
    break ;
  case 0 : 
    lf = lf - 14 - lh - ( ec - bc + 1 ) - nl - ne ;
    break ;
  case 1 : 
    lf = lf - 29 - lh - ncw + ( 1 + npc ) * ( ec - bc + 1 ) - nl - ne ;
    break ;
  } 
  if ( np < 7 ) 
  lf = lf + 7 - np ;
  if ( ( fontptr == fontmax ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66131L ) ;
    } 
    sprintcs ( u ) ;
    printchar ( 61 ) ;
    printfilename ( nom , aire , 65624L ) ;
    if ( s >= 0 ) 
    {
      print ( 66069L ) ;
      printscaled ( s ) ;
      print ( 65683L ) ;
    } 
    else if ( s != -1000 ) 
    {
      print ( 66132L ) ;
      printint ( - (integer) s ) ;
    } 
    print ( 66141L ) ;
    {
      helpptr = 4 ;
      helpline [3 ]= 66142L ;
      helpline [2 ]= 66143L ;
      helpline [1 ]= 66144L ;
      helpline [0 ]= 66145L ;
    } 
    error () ;
    goto lab30 ;
  } 
  f = fontptr + 1 ;
  allocatefonttable ( f , 44 + lf + 100 ) ;
  fonttables [f ][ 0 ].cint = 44 + lf + 100 ;
  fonttables [f ][ 15 ].cint = false ;
  fonttables [f ][ 5 ].cint = offset ;
  fonttables [f ][ 21 ].cint = naturaldir ;
  fonttables [f ][ 34 ].cint = 44 - bc ;
  fonttables [f ][ 35 ].cint = fonttables [f ][ 34 ].cint + ec + 1 ;
  fonttables [f ][ 22 ].cint = fonttables [f ][ 35 ].cint + npc * ( ec - 
  bc + 1 ) ;
  fonttables [f ][ 23 ].cint = fonttables [f ][ 22 ].cint + nki ;
  fonttables [f ][ 24 ].cint = fonttables [f ][ 23 ].cint + nkf ;
  fonttables [f ][ 25 ].cint = fonttables [f ][ 24 ].cint + nkm ;
  fonttables [f ][ 26 ].cint = fonttables [f ][ 25 ].cint + nkr ;
  fonttables [f ][ 27 ].cint = fonttables [f ][ 26 ].cint + nkg ;
  fonttables [f ][ 28 ].cint = fonttables [f ][ 27 ].cint + nkp ;
  fonttables [f ][ 29 ].cint = fonttables [f ][ 28 ].cint + nwi ;
  fonttables [f ][ 30 ].cint = fonttables [f ][ 29 ].cint + nwf ;
  fonttables [f ][ 31 ].cint = fonttables [f ][ 30 ].cint + nwm ;
  fonttables [f ][ 32 ].cint = fonttables [f ][ 31 ].cint + nwr ;
  fonttables [f ][ 33 ].cint = fonttables [f ][ 32 ].cint + nwg ;
  fonttables [f ][ 36 ].cint = fonttables [f ][ 33 ].cint + nwp ;
  fonttables [f ][ 37 ].cint = fonttables [f ][ 36 ].cint + nw ;
  fonttables [f ][ 38 ].cint = fonttables [f ][ 37 ].cint + nh ;
  fonttables [f ][ 39 ].cint = fonttables [f ][ 38 ].cint + nd ;
  fonttables [f ][ 40 ].cint = fonttables [f ][ 39 ].cint + ni ;
  fonttables [f ][ 41 ].cint = fonttables [f ][ 40 ].cint + nl - 256 * ( 
  128 ) ;
  fonttables [f ][ 42 ].cint = fonttables [f ][ 41 ].cint + 256 * ( 128 ) 
  + nk ;
  fonttables [f ][ 43 ].cint = fonttables [f ][ 42 ].cint + ne ;
  {
    if ( lh < 2 ) 
    goto lab11 ;
    tfmtemp = getc ( tfmfile ) ;
    fonttables [f ][ 1 ].cint = tfmtemp ;
    tfmtemp = getc ( tfmfile ) ;
    fonttables [f ][ 2 ].cint = tfmtemp ;
    tfmtemp = getc ( tfmfile ) ;
    fonttables [f ][ 3 ].cint = tfmtemp ;
    tfmtemp = getc ( tfmfile ) ;
    fonttables [f ][ 4 ].cint = tfmtemp ;
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
    fonttables [f ][ 7 ].cint = z ;
    if ( s != -1000 ) {
	
      if ( s >= 0 ) 
      z = s ;
      else z = xnoverd ( z , - (integer) s , 1000 ) ;
    } 
    fonttables [f ][ 6 ].cint = z ;
  } 
  if ( fontlevel == 1 ) 
  {
    i = 0 ;
    k = fonttables [f ][ 22 ].cint ;
    fontcounter = fonttables [f ][ 28 ].cint ;
    while ( k < fonttables [f ][ 23 ].cint ) {
	
      {
	param = tfmtemp ;
	if ( param > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
      } 
      fonttables [f ][ k ].cint = fontcounter ;
      fontcounter = fontcounter + param ;
      tablesize [i ]= 1 ;
      incr ( i ) ;
      incr ( k ) ;
    } 
    while ( k < fonttables [f ][ 24 ].cint ) {
	
      {
	param = tfmtemp ;
	if ( param > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
      } 
      fonttables [f ][ k ].cint = fontcounter ;
      fontcounter = fontcounter + param ;
      tablesize [i ]= 1 ;
      incr ( i ) ;
      incr ( k ) ;
    } 
    while ( k < fonttables [f ][ 25 ].cint ) {
	
      {
	param = tfmtemp ;
	if ( param > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
      } 
      fonttables [f ][ k ].cint = fontcounter ;
      fontcounter = fontcounter + param ;
      tablesize [i ]= 1 ;
      incr ( i ) ;
      incr ( k ) ;
    } 
    while ( k < fonttables [f ][ 26 ].cint ) {
	
      {
	param = tfmtemp ;
	if ( param > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
      } 
      fonttables [f ][ k ].cint = fontcounter ;
      fontcounter = fontcounter + param * 3 ;
      tablesize [i ]= 3 ;
      incr ( i ) ;
      incr ( k ) ;
    } 
    while ( k < fonttables [f ][ 27 ].cint ) {
	
      {
	param = tfmtemp ;
	if ( param > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
      } 
      fonttables [f ][ k ].cint = fontcounter ;
      fontcounter = fontcounter + param * 4 ;
      tablesize [i ]= 4 ;
      incr ( i ) ;
      incr ( k ) ;
    } 
    while ( k < fonttables [f ][ 28 ].cint ) {
	
      {
	param = tfmtemp ;
	if ( param > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	param = param * 256 + tfmtemp ;
      } 
      fonttables [f ][ k ].cint = fontcounter ;
      fontcounter = fontcounter + param * 1 ;
      tablesize [i ]= 1 ;
      incr ( i ) ;
      incr ( k ) ;
    } 
    while ( k < fonttables [f ][ 29 ].cint ) {
	
      {
	fonttables [f ][ k ].cint = tfmtemp ;
	if ( fonttables [f ][ k ].cint > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
      } 
      incr ( k ) ;
    } 
    while ( k < fonttables [f ][ 30 ].cint ) {
	
      {
	fonttables [f ][ k ].cint = tfmtemp ;
	if ( fonttables [f ][ k ].cint > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
      } 
      incr ( k ) ;
    } 
    while ( k < fonttables [f ][ 31 ].cint ) {
	
      {
	fonttables [f ][ k ].cint = tfmtemp ;
	if ( fonttables [f ][ k ].cint > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
      } 
      incr ( k ) ;
    } 
    while ( k < fonttables [f ][ 32 ].cint ) {
	
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
	fonttables [f ][ k ].cint = sw ;
	else if ( a == 255 ) 
	fonttables [f ][ k ].cint = sw - alpha ;
	else goto lab11 ;
      } 
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
	fonttables [f ][ k + 1 ].cint = sw ;
	else if ( a == 255 ) 
	fonttables [f ][ k + 1 ].cint = sw - alpha ;
	else goto lab11 ;
      } 
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
	fonttables [f ][ k + 2 ].cint = sw ;
	else if ( a == 255 ) 
	fonttables [f ][ k + 2 ].cint = sw - alpha ;
	else goto lab11 ;
      } 
      k = k + 3 ;
    } 
    while ( k < fonttables [f ][ 33 ].cint ) {
	
      tfmtemp = getc ( tfmfile ) ;
      {
	fonttables [f ][ k ].hh .lhfield = tfmtemp ;
	if ( fonttables [f ][ k ].hh .lhfield > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].hh .lhfield = fonttables [f ][ k ].hh 
	.lhfield * 256 + tfmtemp ;
      } 
      tfmtemp = getc ( tfmfile ) ;
      {
	fonttables [f ][ k ].hh .v.RH = tfmtemp ;
	if ( fonttables [f ][ k ].hh .v.RH > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].hh .v.RH = fonttables [f ][ k ].hh .v.RH * 
	256 + tfmtemp ;
      } 
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
	fonttables [f ][ k + 1 ].cint = sw ;
	else if ( a == 255 ) 
	fonttables [f ][ k + 1 ].cint = sw - alpha ;
	else goto lab11 ;
      } 
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
	fonttables [f ][ k + 2 ].cint = sw ;
	else if ( a == 255 ) 
	fonttables [f ][ k + 2 ].cint = sw - alpha ;
	else goto lab11 ;
      } 
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
	fonttables [f ][ k + 3 ].cint = sw ;
	else if ( a == 255 ) 
	fonttables [f ][ k + 3 ].cint = sw - alpha ;
	else goto lab11 ;
      } 
      k = k + 4 ;
    } 
    while ( k < 44 ) {
	
      {
	fonttables [f ][ k ].cint = tfmtemp ;
	if ( fonttables [f ][ k ].cint > 127 ) 
	goto lab11 ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	fonttables [f ][ k ].cint = fonttables [f ][ k ].cint * 256 + 
	tfmtemp ;
      } 
      incr ( k ) ;
    } 
  } 
  k = fonttables [f ][ 34 ].cint + bc ;
  kparam = fonttables [f ][ 35 ].cint ;
  bytesperentry = ( 12 + 2 * npc ) / 4 * 4 ;
  extracharbytes = bytesperentry - ( 10 + 2 * npc ) ;
  while ( k < fonttables [f ][ 35 ].cint ) {
      
    {
      if ( ( fontlevel != -1 ) ) 
      {
	tfmtemp = getc ( tfmfile ) ;
	{
	  a = tfmtemp ;
	  tfmtemp = getc ( tfmfile ) ;
	  a = a * 256 + tfmtemp ;
	} 
	qw .b0 = a ;
	tfmtemp = getc ( tfmfile ) ;
	{
	  b = tfmtemp ;
	  tfmtemp = getc ( tfmfile ) ;
	  b = b * 256 + tfmtemp ;
	} 
	qw .b1 = b ;
	tfmtemp = getc ( tfmfile ) ;
	{
	  c = tfmtemp ;
	  tfmtemp = getc ( tfmfile ) ;
	  c = c * 256 + tfmtemp ;
	} 
	qw .b2 = c ;
	tfmtemp = getc ( tfmfile ) ;
	{
	  d = tfmtemp ;
	  tfmtemp = getc ( tfmfile ) ;
	  d = d * 256 + tfmtemp ;
	} 
	qw .b3 = d ;
	fonttables [f ][ k ].qqqq = qw ;
      } 
      else {
	  
	tfmtemp = getc ( tfmfile ) ;
	a = tfmtemp ;
	qw .b0 = a ;
	tfmtemp = getc ( tfmfile ) ;
	b = tfmtemp ;
	b = ( ( b / 16 ) * 256 ) + ( b % 16 ) ;
	qw .b1 = b ;
	tfmtemp = getc ( tfmfile ) ;
	c = tfmtemp ;
	c = ( ( c / 4 ) * 256 ) + ( c % 4 ) ;
	qw .b2 = c ;
	tfmtemp = getc ( tfmfile ) ;
	d = tfmtemp ;
	qw .b3 = d ;
	fonttables [f ][ k ].qqqq = qw ;
      } 
    } 
    if ( ( a >= nw ) || ( ( b / 256 ) >= nh ) || ( ( b % 256 ) >= nd ) || ( ( 
    c / 256 ) >= ni ) ) 
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
	while ( d < k - fonttables [f ][ 34 ].cint ) {
	    
	  qw = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f 
	  ][ 5 ].cint + d ].qqqq ;
	  if ( ( ( qw .b2 ) % 4 ) != 2 ) 
	  goto lab45 ;
	  d = qw .b3 ;
	} 
	if ( d == k - fonttables [f ][ 34 ].cint ) 
	goto lab11 ;
	lab45: ;
      } 
      break ;
      default: 
      ;
      break ;
    } 
    incr ( k ) ;
    if ( fontlevel == 1 ) 
    {
      tfmtemp = getc ( tfmfile ) ;
      {
	repeatno = tfmtemp ;
	tfmtemp = getc ( tfmfile ) ;
	repeatno = repeatno * 256 + tfmtemp ;
      } 
      {register integer for_end; i = 0 ;for_end = npc - 1 ; if ( i <= 
      for_end) do 
	{
	  tfmtemp = getc ( tfmfile ) ;
	  {
	    param = tfmtemp ;
	    if ( param > 127 ) 
	    goto lab11 ;
	    tfmtemp = getc ( tfmfile ) ;
	    param = param * 256 + tfmtemp ;
	  } 
	  fonttables [f ][ kparam ].cint = fonttables [f ][ fonttables [f 
	  ][ 22 ].cint + i ].cint + param * tablesize [i ];
	  incr ( kparam ) ;
	} 
      while ( i++ < for_end ) ;} 
      {register integer for_end; i = 1 ;for_end = extracharbytes ; if ( i <= 
      for_end) do 
	tfmtemp = getc ( tfmfile ) ;
      while ( i++ < for_end ) ;} 
      {register integer for_end; i = 1 ;for_end = repeatno ; if ( i <= 
      for_end) do 
	{
	  fonttables [f ][ k ]= fonttables [f ][ k - 1 ];
	  incr ( k ) ;
	  {register integer for_end; tablecounter = 0 ;for_end = npc - 1 
	  ; if ( tablecounter <= for_end) do 
	    {
	      fonttables [f ][ kparam ].cint = fonttables [f ][ kparam - 
	      npc ].cint ;
	      incr ( kparam ) ;
	    } 
	  while ( tablecounter++ < for_end ) ;} 
	} 
      while ( i++ < for_end ) ;} 
    } 
  } 
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
    {register integer for_end; k = fonttables [f ][ 36 ].cint ;for_end = 
    fonttables [f ][ 40 ].cint - 1 ; if ( k <= for_end) do 
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
	fonttables [f ][ k ].cint = sw ;
	else if ( a == 255 ) 
	fonttables [f ][ k ].cint = sw - alpha ;
	else goto lab11 ;
      } 
    while ( k++ < for_end ) ;} 
    if ( fonttables [f ][ fonttables [f ][ 36 ].cint ].cint != 0 ) 
    goto lab11 ;
    if ( fonttables [f ][ fonttables [f ][ 37 ].cint ].cint != 0 ) 
    goto lab11 ;
    if ( fonttables [f ][ fonttables [f ][ 38 ].cint ].cint != 0 ) 
    goto lab11 ;
    if ( fonttables [f ][ fonttables [f ][ 39 ].cint ].cint != 0 ) 
    goto lab11 ;
  } 
  bchlabel = nl ;
  bchar = 65536L ;
  if ( nl > 0 ) 
  {
    {register integer for_end; k = fonttables [f ][ 40 ].cint ;for_end = 
    fonttables [f ][ 41 ].cint + 256 * ( 128 ) - 1 ; if ( k <= for_end) do 
      {
	{
	  if ( ( fontlevel != -1 ) ) 
	  {
	    tfmtemp = getc ( tfmfile ) ;
	    {
	      a = tfmtemp ;
	      tfmtemp = getc ( tfmfile ) ;
	      a = a * 256 + tfmtemp ;
	    } 
	    qw .b0 = a ;
	    tfmtemp = getc ( tfmfile ) ;
	    {
	      b = tfmtemp ;
	      tfmtemp = getc ( tfmfile ) ;
	      b = b * 256 + tfmtemp ;
	    } 
	    qw .b1 = b ;
	    tfmtemp = getc ( tfmfile ) ;
	    {
	      c = tfmtemp ;
	      tfmtemp = getc ( tfmfile ) ;
	      c = c * 256 + tfmtemp ;
	    } 
	    qw .b2 = c ;
	    tfmtemp = getc ( tfmfile ) ;
	    {
	      d = tfmtemp ;
	      tfmtemp = getc ( tfmfile ) ;
	      d = d * 256 + tfmtemp ;
	    } 
	    qw .b3 = d ;
	    fonttables [f ][ k ].qqqq = qw ;
	  } 
	  else {
	      
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
	    fonttables [f ][ k ].qqqq = qw ;
	  } 
	} 
	if ( a > 128 ) 
	{
	  if ( 256 * c + d >= nl ) 
	  goto lab11 ;
	  if ( a == 255 ) {
	      
	    if ( k == fonttables [f ][ 40 ].cint ) 
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
	    qw = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [
	    f ][ 5 ].cint + b + fonttables [f ][ 5 ].cint ].qqqq ;
	    if ( ! ( qw .b0 > 0 ) ) 
	    goto lab11 ;
	  } 
	  if ( c < 128 ) 
	  {
	    {
	      if ( ( d < bc ) || ( d > ec ) ) 
	      goto lab11 ;
	    } 
	    qw = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [
	    f ][ 5 ].cint + d + fonttables [f ][ 5 ].cint ].qqqq ;
	    if ( ! ( qw .b0 > 0 ) ) 
	    goto lab11 ;
	  } 
	  else if ( 256 * ( c - 128 ) + d >= nk ) 
	  goto lab11 ;
	  if ( a < 128 ) {
	      
	    if ( k - fonttables [f ][ 40 ].cint + a + 1 >= nl ) 
	    goto lab11 ;
	  } 
	} 
      } 
    while ( k++ < for_end ) ;} 
    if ( a == 255 ) 
    bchlabel = 256 * c + d ;
  } 
  {register integer for_end; k = fonttables [f ][ 41 ].cint + 256 * ( 128 ) 
  ;for_end = fonttables [f ][ 42 ].cint - 1 ; if ( k <= for_end) do 
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
      fonttables [f ][ k ].cint = sw ;
      else if ( a == 255 ) 
      fonttables [f ][ k ].cint = sw - alpha ;
      else goto lab11 ;
    } 
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = fonttables [f ][ 42 ].cint ;for_end = 
  fonttables [f ][ 43 ].cint - 1 ; if ( k <= for_end) do 
    {
      {
	if ( ( fontlevel != -1 ) ) 
	{
	  tfmtemp = getc ( tfmfile ) ;
	  {
	    a = tfmtemp ;
	    tfmtemp = getc ( tfmfile ) ;
	    a = a * 256 + tfmtemp ;
	  } 
	  qw .b0 = a ;
	  tfmtemp = getc ( tfmfile ) ;
	  {
	    b = tfmtemp ;
	    tfmtemp = getc ( tfmfile ) ;
	    b = b * 256 + tfmtemp ;
	  } 
	  qw .b1 = b ;
	  tfmtemp = getc ( tfmfile ) ;
	  {
	    c = tfmtemp ;
	    tfmtemp = getc ( tfmfile ) ;
	    c = c * 256 + tfmtemp ;
	  } 
	  qw .b2 = c ;
	  tfmtemp = getc ( tfmfile ) ;
	  {
	    d = tfmtemp ;
	    tfmtemp = getc ( tfmfile ) ;
	    d = d * 256 + tfmtemp ;
	  } 
	  qw .b3 = d ;
	  fonttables [f ][ k ].qqqq = qw ;
	} 
	else {
	    
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
	  fonttables [f ][ k ].qqqq = qw ;
	} 
      } 
      if ( a != 0 ) 
      {
	{
	  if ( ( a < bc ) || ( a > ec ) ) 
	  goto lab11 ;
	} 
	qw = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f 
	][ 5 ].cint + a + fonttables [f ][ 5 ].cint ].qqqq ;
	if ( ! ( qw .b0 > 0 ) ) 
	goto lab11 ;
      } 
      if ( b != 0 ) 
      {
	{
	  if ( ( b < bc ) || ( b > ec ) ) 
	  goto lab11 ;
	} 
	qw = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f 
	][ 5 ].cint + b + fonttables [f ][ 5 ].cint ].qqqq ;
	if ( ! ( qw .b0 > 0 ) ) 
	goto lab11 ;
      } 
      if ( c != 0 ) 
      {
	{
	  if ( ( c < bc ) || ( c > ec ) ) 
	  goto lab11 ;
	} 
	qw = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f 
	][ 5 ].cint + c + fonttables [f ][ 5 ].cint ].qqqq ;
	if ( ! ( qw .b0 > 0 ) ) 
	goto lab11 ;
      } 
      {
	{
	  if ( ( d < bc ) || ( d > ec ) ) 
	  goto lab11 ;
	} 
	qw = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f 
	][ 5 ].cint + d + fonttables [f ][ 5 ].cint ].qqqq ;
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
	fonttables [f ][ fonttables [f ][ 43 ].cint ].cint = ( sw * 16 ) + 
	( tfmtemp / 16 ) ;
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
	fonttables [f ][ fonttables [f ][ 43 ].cint + k - 1 ].cint = sw ;
	else if ( a == 255 ) 
	fonttables [f ][ fonttables [f ][ 43 ].cint + k - 1 ].cint = sw - 
	alpha ;
	else goto lab11 ;
      } 
    while ( k++ < for_end ) ;} 
    if ( feof ( tfmfile ) ) 
    goto lab11 ;
    {register integer for_end; k = np + 1 ;for_end = 7 ; if ( k <= for_end) 
    do 
      fonttables [f ][ fonttables [f ][ 43 ].cint + k - 1 ].cint = 0 ;
    while ( k++ < for_end ) ;} 
  } 
  if ( np >= 7 ) 
  fonttables [f ][ 8 ].cint = np ;
  else fonttables [f ][ 8 ].cint = 7 ;
  fonttables [f ][ 5 ].cint = offset ;
  fonttables [f ][ 16 ].cint = neweqtbint ( 1049454L ) + offset ;
  fonttables [f ][ 17 ].cint = neweqtbint ( 1049455L ) + offset ;
  bchar = bchar + offset ;
  if ( bchlabel < nl ) 
  fonttables [f ][ 18 ].cint = bchlabel + fonttables [f ][ 40 ].cint ;
  else fonttables [f ][ 18 ].cint = 0 ;
  fonttables [f ][ 19 ].cint = bchar ;
  fonttables [f ][ 20 ].cint = bchar ;
  if ( bchar <= ec ) {
      
    if ( bchar >= bc ) 
    {
      qw = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f ][ 
      5 ].cint + bchar ].qqqq ;
      if ( ( qw .b0 > 0 ) ) 
      fonttables [f ][ 20 ].cint = 65536L ;
    } 
  } 
  fonttables [f ][ 10 ].cint = nom ;
  fonttables [f ][ 11 ].cint = aire ;
  fonttables [f ][ 12 ].cint = bc ;
  fonttables [f ][ 13 ].cint = ec ;
  fonttables [f ][ 14 ].cint = 0 ;
  fonttables [f ][ 12 ].cint = bc + offset ;
  fonttables [f ][ 13 ].cint = ec + offset ;
  fonttables [f ][ 14 ].cint = 0 ;
  fonttables [f ][ 34 ].cint = fonttables [f ][ 34 ].cint ;
  fonttables [f ][ 36 ].cint = fonttables [f ][ 36 ].cint ;
  fonttables [f ][ 40 ].cint = fonttables [f ][ 40 ].cint ;
  fonttables [f ][ 41 ].cint = fonttables [f ][ 41 ].cint ;
  fonttables [f ][ 42 ].cint = fonttables [f ][ 42 ].cint ;
  decr ( fonttables [f ][ 43 ].cint ) ;
  fontptr = f ;
  g = f ;
  goto lab30 ;
  lab11: {
      
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 65548L ) ;
    print ( 66131L ) ;
  } 
  sprintcs ( u ) ;
  printchar ( 61 ) ;
  printfilename ( nom , aire , 65624L ) ;
  if ( s >= 0 ) 
  {
    print ( 66069L ) ;
    printscaled ( s ) ;
    print ( 65683L ) ;
  } 
  else if ( s != -1000 ) 
  {
    print ( 66132L ) ;
    printint ( - (integer) s ) ;
  } 
  if ( fileopened ) 
  print ( 66133L ) ;
  else if ( nametoolong ) 
  print ( 66134L ) ;
  else print ( 66135L ) ;
  {
    helpptr = 5 ;
    helpline [4 ]= 66136L ;
    helpline [3 ]= 66137L ;
    helpline [2 ]= 66138L ;
    helpline [1 ]= 66139L ;
    helpline [0 ]= 66140L ;
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
  integer oldsetting  ;
  if ( neweqtbint ( 1049443L ) > 0 ) 
  {
    oldsetting = neweqtbint ( 1049437L ) ;
    if ( ( eTeXmode == 1 ) && ( neweqtbint ( 1049443L ) > 1 ) ) 
    setneweqtbint ( 1049437L , 1 ) ;
    {
      begindiagnostic () ;
      printnl ( 66154L ) ;
      print ( c ) ;
      print ( 66155L ) ;
      slowprint ( fonttables [f ][ 10 ].cint ) ;
      printchar ( 33 ) ;
      enddiagnostic ( false ) ;
    } 
    setneweqtbint ( 1049437L , oldsetting ) ;
  } 
} 
halfword 
znewcharacter ( internalfontnumber f , eightbits c ) 
{
  /* 10 */ register halfword Result; newcharacter_regmem 
  halfword p  ;
  if ( fonttables [f ][ 12 ].cint <= c ) {
      
    if ( fonttables [f ][ 13 ].cint >= c ) {
	
      if ( ( fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f 
      ][ 5 ].cint + c ].qqqq .b0 > 0 ) ) 
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
  Result = 0 ;
  return Result ;
} 
integer 
zislastocp ( scaled llstackno , integer counter ) 
{
  register integer Result; islastocp_regmem 
  activeminptr = newequiv ( 524337L ) ;
  activemaxptr = newequiv ( 524338L ) ;
  activereal = activeminptr ;
  while ( ( activereal < activemaxptr ) && ( activeinfo [activereal + 1 ]
  .cint < llstackno ) ) {
      
    activereal = activereal + 2 ;
  } 
  while ( ( activereal < activemaxptr ) && ( activeinfo [activereal + 1 ]
  .cint == llstackno ) && ( activeinfo [activereal ].hh.b1 <= counter ) ) {
      
    activereal = activereal + 2 ;
  } 
  Result = ( activereal == activemaxptr ) ;
  return Result ;
} 
void 
printactiveocps ( void ) 
{
  printactiveocps_regmem 
  integer i  ;
  printnl ( 66156L ) ;
  i = activeminptr ;
  while ( i < activemaxptr ) {
      
    print ( 40 ) ;
    printscaled ( activeinfo [i + 1 ].cint ) ;
    print ( 44 ) ;
    printint ( activeinfo [i ].hh.b1 ) ;
    print ( 44 ) ;
    printesc ( newhashtext ( 1508273L + activeinfo [i ].hh.b0 ) ) ;
    print ( 41 ) ;
    if ( i != ( activemaxptr - 2 ) ) 
    print ( 44 ) ;
    i = i + 2 ;
  } 
  print ( 93 ) ;
} 
void 
zaddocpstack ( integer minindex , scaled minvalue ) 
{
  addocpstack_regmem 
  ocplstackindex p  ;
  scaled llstackno  ;
  integer counter  ;
  p = ocplistinfo [holding [minindex ]].hh.b1 ;
  llstackno = ocplistinfo [holding [minindex ]+ 1 ].cint ;
  counter = 0 ;
  while ( ! ( p == 0 ) ) {
      
    activeinfo [activemaxptr ].hh.b0 = ocplstackinfo [p ].hh.b1 ;
    activeinfo [activemaxptr ].hh.b1 = counter ;
    activeinfo [activemaxptr + 1 ].cint = llstackno ;
    p = ocplstackinfo [p ].hh.b0 ;
    activemaxptr = activemaxptr + 2 ;
    incr ( counter ) ;
  } 
} 
void 
activecompile ( void ) 
{
  activecompile_regmem 
  integer i  ;
  integer minindex  ;
  scaled minstackocp  ;
  scaled oldmin  ;
  integer maxactive  ;
  scaled stackvalue  ;
  activeminptr = activemaxptr ;
  minstackocp = ocpmaxint ;
  maxactive = newequiv ( 524336L ) - 1 ;
  {register integer for_end; i = maxactive ;for_end = 0 ; if ( i >= for_end) 
  do 
    {
      holding [i ]= ocplistlist [newequiv ( 524339L + i ) ];
      stackvalue = ocplistinfo [holding [i ]+ 1 ].cint ;
      if ( stackvalue < minstackocp ) 
      {
	minindex = i ;
	minstackocp = stackvalue ;
      } 
    } 
  while ( i-- > for_end ) ;} 
  while ( minstackocp < ocpmaxint ) {
      
    addocpstack ( minindex , minstackocp ) ;
    oldmin = minstackocp ;
    minstackocp = ocpmaxint ;
    {register integer for_end; i = maxactive ;for_end = 0 ; if ( i >= 
    for_end) do 
      {
	stackvalue = ocplistinfo [holding [i ]+ 1 ].cint ;
	while ( oldmin == stackvalue ) {
	    
	  holding [i ]= ocplistinfo [holding [i ]].hh.b0 ;
	  stackvalue = ocplistinfo [holding [i ]+ 1 ].cint ;
	} 
	if ( stackvalue < minstackocp ) 
	{
	  minindex = i ;
	  minstackocp = stackvalue ;
	} 
      } 
    while ( i-- > for_end ) ;} 
  } 
} 
internalocpnumber 
zreadocpinfo ( halfword u , strnumber nom , strnumber aire , strnumber ext , 
boolean externalocp ) 
{
  /* 30 11 45 */ register internalocpnumber Result; readocpinfo_regmem 
  boolean fileopened  ;
  internalocpnumber f  ;
  internalocpnumber g  ;
  integer ocpword  ;
  ocpindex ocpmemrunptr  ;
  integer ocplength, realocplength  ;
  ocpindex previousaddress  ;
  integer tempocpinput  ;
  integer tempocpoutput  ;
  integer tempocpnotables  ;
  integer tempocpnostates  ;
  integer i, newoffset, roomfortables, roomforstates  ;
  g = 0 ;
  fileopened = false ;
  if ( ( ocpptr == 65535L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66159L ) ;
    } 
    sprintcs ( u ) ;
    printchar ( 61 ) ;
    printfilename ( nom , aire , 65624L ) ;
    print ( 66141L ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 66164L ;
      helpline [0 ]= 66163L ;
    } 
    error () ;
    goto lab30 ;
  } 
  if ( externalocp ) 
  {
    packfilename ( nom , aire , ext ) ;
    btestin () ;
    if ( namelength == 0 ) 
    {
      print ( 66158L ) ;
      print ( 66165L ) ;
      print ( 41 ) ;
      println () ;
      goto lab11 ;
    } 
    f = ocpptr + 1 ;
    allocateocptable ( f , 13 ) ;
    ocptables [f ][ 0 ]= 13 ;
    {register integer for_end; i = 1 ;for_end = namelength ; if ( i <= 
    for_end) do 
      {
	{
	  strpool [poolptr ]= nameoffile [i ];
	  incr ( poolptr ) ;
	} 
      } 
    while ( i++ < for_end ) ;} 
    ocptables [f ][ 3 ]= makestring () ;
    scanstringargument () ;
    ocptables [f ][ 4 ]= curval ;
    ocptables [f ][ 1 ]= 65624L ;
    ocptables [f ][ 2 ]= 65624L ;
    ocptables [f ][ 10 ]= 0 ;
    ocptables [f ][ 9 ]= 0 ;
    ocptables [f ][ 5 ]= 1 ;
    ocptables [f ][ 6 ]= 1 ;
    ocptables [f ][ 11 ]= 0 ;
    ocpptr = f ;
    g = f ;
    goto lab30 ;
  } 
  else {
      
    packfilename ( nom , aire , 66166L ) ;
    if ( ! ocpopenin ( ocpfile ) ) 
    {
      print ( 66158L ) ;
      print ( 66165L ) ;
      print ( 41 ) ;
      println () ;
      goto lab11 ;
    } 
    fileopened = true ;
    {
      f = ocpptr + 1 ;
      ocpmemrunptr = 11 ;
      {
	ocpword = ocptemp ;
	if ( ocpword > 127 ) 
	{
	  print ( 66158L ) ;
	  print ( 66167L ) ;
	  print ( 41 ) ;
	  println () ;
	  goto lab11 ;
	} 
	ocptemp = getc ( ocpfile ) ;
	ocpword = ocpword * 256 + ocptemp ;
	ocptemp = getc ( ocpfile ) ;
	ocpword = ocpword * 256 + ocptemp ;
	ocptemp = getc ( ocpfile ) ;
	ocpword = ocpword * 256 + ocptemp ;
	ocplength = ocpword ;
      } 
      realocplength = ocplength - 7 ;
      {
	ocptemp = getc ( ocpfile ) ;
	{
	  ocpword = ocptemp ;
	  if ( ocpword > 127 ) 
	  {
	    print ( 66158L ) ;
	    print ( 66167L ) ;
	    print ( 41 ) ;
	    println () ;
	    goto lab11 ;
	  } 
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  tempocpinput = ocpword ;
	} 
      } 
      {
	ocptemp = getc ( ocpfile ) ;
	{
	  ocpword = ocptemp ;
	  if ( ocpword > 127 ) 
	  {
	    print ( 66158L ) ;
	    print ( 66167L ) ;
	    print ( 41 ) ;
	    println () ;
	    goto lab11 ;
	  } 
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  tempocpoutput = ocpword ;
	} 
      } 
      {
	ocptemp = getc ( ocpfile ) ;
	{
	  ocpword = ocptemp ;
	  if ( ocpword > 127 ) 
	  {
	    print ( 66158L ) ;
	    print ( 66167L ) ;
	    print ( 41 ) ;
	    println () ;
	    goto lab11 ;
	  } 
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  tempocpnotables = ocpword ;
	} 
      } 
      {
	ocptemp = getc ( ocpfile ) ;
	{
	  ocpword = ocptemp ;
	  if ( ocpword > 127 ) 
	  {
	    print ( 66158L ) ;
	    print ( 66167L ) ;
	    print ( 41 ) ;
	    println () ;
	    goto lab11 ;
	  } 
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  roomfortables = ocpword ;
	} 
      } 
      {
	ocptemp = getc ( ocpfile ) ;
	{
	  ocpword = ocptemp ;
	  if ( ocpword > 127 ) 
	  {
	    print ( 66158L ) ;
	    print ( 66167L ) ;
	    print ( 41 ) ;
	    println () ;
	    goto lab11 ;
	  } 
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  tempocpnostates = ocpword ;
	} 
      } 
      {
	ocptemp = getc ( ocpfile ) ;
	{
	  ocpword = ocptemp ;
	  if ( ocpword > 127 ) 
	  {
	    print ( 66158L ) ;
	    print ( 66167L ) ;
	    print ( 41 ) ;
	    println () ;
	    goto lab11 ;
	  } 
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  ocptemp = getc ( ocpfile ) ;
	  ocpword = ocpword * 256 + ocptemp ;
	  roomforstates = ocpword ;
	} 
      } 
      if ( realocplength != ( tempocpnotables + roomfortables + 
      tempocpnostates + roomforstates ) ) 
      {
	print ( 66158L ) ;
	print ( 66168L ) ;
	print ( 41 ) ;
	println () ;
	goto lab11 ;
      } 
      realocplength = realocplength + 12 + tempocpnostates + tempocpnotables ;
      allocateocptable ( f , realocplength ) ;
      ocptables [f ][ 3 ]= 0 ;
      ocptables [f ][ 4 ]= 0 ;
      ocptables [f ][ 0 ]= realocplength ;
      ocptables [f ][ 5 ]= tempocpinput ;
      ocptables [f ][ 6 ]= tempocpoutput ;
      ocptables [f ][ 7 ]= tempocpnotables ;
      ocptables [f ][ 8 ]= tempocpnostates ;
      ocptables [f ][ 9 ]= ocpmemrunptr ;
      if ( ocptables [f ][ 7 ]!= 0 ) 
      {
	previousaddress = ocpmemrunptr + 2 * ( ocptables [f ][ 7 ]) ;
	{register integer for_end; i = 1 ;for_end = ocptables [f ][ 7 ]
	; if ( i <= for_end) do 
	  {
	    {
	      ocptables [f ][ ocpmemrunptr ]= previousaddress ;
	      incr ( ocpmemrunptr ) ;
	    } 
	    {
	      ocptemp = getc ( ocpfile ) ;
	      {
		ocpword = ocptemp ;
		if ( ocpword > 127 ) 
		{
		  print ( 66158L ) ;
		  print ( 66167L ) ;
		  print ( 41 ) ;
		  println () ;
		  goto lab11 ;
		} 
		ocptemp = getc ( ocpfile ) ;
		ocpword = ocpword * 256 + ocptemp ;
		ocptemp = getc ( ocpfile ) ;
		ocpword = ocpword * 256 + ocptemp ;
		ocptemp = getc ( ocpfile ) ;
		ocpword = ocpword * 256 + ocptemp ;
		newoffset = ocpword ;
	      } 
	    } 
	    {
	      ocptables [f ][ ocpmemrunptr ]= newoffset ;
	      incr ( ocpmemrunptr ) ;
	    } 
	    previousaddress = previousaddress + newoffset ;
	  } 
	while ( i++ < for_end ) ;} 
      } 
      if ( roomfortables != 0 ) 
      {
	{register integer for_end; i = 1 ;for_end = roomfortables ; if ( i 
	<= for_end) do 
	  {
	    {
	      {
		ocptemp = getc ( ocpfile ) ;
		{
		  ocpword = ocptemp ;
		  if ( ocpword > 127 ) 
		  {
		    print ( 66158L ) ;
		    print ( 66167L ) ;
		    print ( 41 ) ;
		    println () ;
		    goto lab11 ;
		  } 
		  ocptemp = getc ( ocpfile ) ;
		  ocpword = ocpword * 256 + ocptemp ;
		  ocptemp = getc ( ocpfile ) ;
		  ocpword = ocpword * 256 + ocptemp ;
		  ocptemp = getc ( ocpfile ) ;
		  ocpword = ocpword * 256 + ocptemp ;
		  ocpword = ocpword ;
		} 
	      } 
	      {
		ocptables [f ][ ocpmemrunptr ]= ocpword ;
		incr ( ocpmemrunptr ) ;
	      } 
	    } 
	  } 
	while ( i++ < for_end ) ;} 
      } 
      ocptables [f ][ 10 ]= ocpmemrunptr ;
      if ( ocptables [f ][ 8 ]!= 0 ) 
      {
	previousaddress = ocpmemrunptr + 2 * ( ocptables [f ][ 8 ]) ;
	{register integer for_end; i = 1 ;for_end = ocptables [f ][ 8 ]
	; if ( i <= for_end) do 
	  {
	    {
	      ocptables [f ][ ocpmemrunptr ]= previousaddress ;
	      incr ( ocpmemrunptr ) ;
	    } 
	    {
	      ocptemp = getc ( ocpfile ) ;
	      {
		ocpword = ocptemp ;
		if ( ocpword > 127 ) 
		{
		  print ( 66158L ) ;
		  print ( 66167L ) ;
		  print ( 41 ) ;
		  println () ;
		  goto lab11 ;
		} 
		ocptemp = getc ( ocpfile ) ;
		ocpword = ocpword * 256 + ocptemp ;
		ocptemp = getc ( ocpfile ) ;
		ocpword = ocpword * 256 + ocptemp ;
		ocptemp = getc ( ocpfile ) ;
		ocpword = ocpword * 256 + ocptemp ;
		newoffset = ocpword ;
	      } 
	    } 
	    {
	      ocptables [f ][ ocpmemrunptr ]= newoffset ;
	      incr ( ocpmemrunptr ) ;
	    } 
	    previousaddress = previousaddress + newoffset ;
	  } 
	while ( i++ < for_end ) ;} 
      } 
      if ( roomforstates != 0 ) 
      {
	{register integer for_end; i = 1 ;for_end = roomforstates ; if ( i 
	<= for_end) do 
	  {
	    {
	      {
		ocptemp = getc ( ocpfile ) ;
		{
		  ocpword = ocptemp ;
		  if ( ocpword > 127 ) 
		  {
		    print ( 66158L ) ;
		    print ( 66167L ) ;
		    print ( 41 ) ;
		    println () ;
		    goto lab11 ;
		  } 
		  ocptemp = getc ( ocpfile ) ;
		  ocpword = ocpword * 256 + ocptemp ;
		  ocptemp = getc ( ocpfile ) ;
		  ocpword = ocpword * 256 + ocptemp ;
		  ocptemp = getc ( ocpfile ) ;
		  ocpword = ocpword * 256 + ocptemp ;
		  ocpword = ocpword ;
		} 
	      } 
	      {
		ocptables [f ][ ocpmemrunptr ]= ocpword ;
		incr ( ocpmemrunptr ) ;
	      } 
	    } 
	  } 
	while ( i++ < for_end ) ;} 
      } 
      ocpptr = f ;
      g = f ;
      goto lab30 ;
    } 
  } 
  ocptables [f ][ 1 ]= nom ;
  ocptables [f ][ 2 ]= aire ;
  lab11: {
      
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 65548L ) ;
    print ( 66159L ) ;
  } 
  sprintcs ( u ) ;
  printchar ( 61 ) ;
  printfilename ( nom , aire , 65624L ) ;
  if ( fileopened ) 
  print ( 66160L ) ;
  else print ( 66161L ) ;
  {
    helpptr = 2 ;
    helpline [1 ]= 66162L ;
    helpline [0 ]= 66163L ;
  } 
  error () ;
  lab30: if ( fileopened ) 
  bclose ( ocpfile ) ;
  Result = g ;
  return Result ;
} 
ocplistindex 
zmakeocplistnode ( ocplstackindex llstack , scaled llstackno , ocplistindex 
llnext ) 
{
  register ocplistindex Result; makeocplistnode_regmem 
  ocplistindex p  ;
  p = ocplistmemrunptr ;
  ocplistinfo [p ].hh.b1 = llstack ;
  ocplistinfo [p + 1 ].cint = llstackno ;
  ocplistinfo [p ].hh.b0 = llnext ;
  ocplistmemrunptr = ocplistmemrunptr + 2 ;
  Result = p ;
  return Result ;
} 
ocplstackindex 
zmakeocplstacknode ( internalocpnumber locp , ocplstackindex llnext ) 
{
  register ocplstackindex Result; makeocplstacknode_regmem 
  ocplstackindex p  ;
  p = ocplstackmemrunptr ;
  ocplstackinfo [p ].hh.b1 = locp ;
  ocplstackinfo [p ].hh.b0 = llnext ;
  incr ( ocplstackmemrunptr ) ;
  Result = p ;
  return Result ;
} 
ocplstackindex 
zcopyocplstack ( ocplstackindex llstack ) 
{
  register ocplstackindex Result; copyocplstack_regmem 
  ocplstackindex result  ;
  if ( llstack == 0 ) 
  result = 0 ;
  else result = makeocplstacknode ( ocplstackinfo [llstack ].hh.b1 , 
  copyocplstack ( ocplstackinfo [llstack ].hh.b0 ) ) ;
  Result = result ;
  return Result ;
} 
ocplistindex 
zcopyocplist ( ocplistindex list ) 
{
  register ocplistindex Result; copyocplist_regmem 
  ocplistindex result  ;
  if ( ocplistinfo [list + 1 ].cint == ocpmaxint ) 
  result = makeocplistnode ( 0 , ocpmaxint , 0 ) ;
  else result = makeocplistnode ( copyocplstack ( ocplistinfo [list ].hh.b1 
  ) , ocplistinfo [list + 1 ].cint , copyocplist ( ocplistinfo [list ]
  .hh.b0 ) ) ;
  Result = result ;
  return Result ;
} 
ocplistindex 
zocpensurelstack ( ocplistindex list , scaled llstackno ) 
{
  register ocplistindex Result; ocpensurelstack_regmem 
  ocplistindex p  ;
  ocplistindex q  ;
  p = list ;
  if ( ocplistinfo [p + 1 ].cint == ocpmaxint ) 
  {
    ocplistinfo [p + 1 ].cint = llstackno ;
    ocplistinfo [p ].hh.b0 = makeocplistnode ( 0 , ocpmaxint , 0 ) ;
  } 
  else if ( ocplistinfo [p + 1 ].cint > llstackno ) 
  {
    ocplistinfo [p ].hh.b0 = makeocplistnode ( ocplistinfo [p ].hh.b1 , 
    ocplistinfo [p + 1 ].cint , ocplistinfo [p ].hh.b0 ) ;
    ocplistinfo [p ].hh.b1 = 0 ;
    ocplistinfo [p + 1 ].cint = llstackno ;
  } 
  else {
      
    q = ocplistinfo [p ].hh.b0 ;
    while ( ( ! ( ocplistinfo [q + 1 ].cint == ocpmaxint ) ) && ocplistinfo 
    [q + 1 ].cint <= llstackno ) {
	
      p = q ;
      q = ocplistinfo [q ].hh.b0 ;
    } 
    if ( ocplistinfo [p + 1 ].cint < llstackno ) 
    {
      ocplistinfo [p ].hh.b0 = makeocplistnode ( 0 , llstackno , q ) ;
      p = ocplistinfo [p ].hh.b0 ;
    } 
  } 
  Result = p ;
  return Result ;
} 
void 
zocpapplyadd ( ocplistindex listentry , boolean lbefore , internalocpnumber 
locp ) 
{
  ocpapplyadd_regmem 
  ocplstackindex p  ;
  ocplstackindex q  ;
  p = ocplistinfo [listentry ].hh.b1 ;
  if ( lbefore || ( p == 0 ) ) 
  {
    ocplistinfo [listentry ].hh.b1 = makeocplstacknode ( locp , p ) ;
  } 
  else {
      
    q = ocplstackinfo [p ].hh.b0 ;
    while ( q != 0 ) {
	
      p = q ;
      q = ocplstackinfo [q ].hh.b0 ;
    } 
    ocplstackinfo [p ].hh.b0 = makeocplstacknode ( locp , 0 ) ;
  } 
} 
void 
zocpapplyremove ( ocplistindex listentry , boolean lbefore ) 
{
  ocpapplyremove_regmem 
  ocplstackindex p  ;
  ocplstackindex q  ;
  ocplstackindex r  ;
  p = ocplistinfo [listentry ].hh.b1 ;
  if ( p == 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66172L ) ;
    } 
    println () ;
  } 
  else {
      
    q = ocplstackinfo [p ].hh.b0 ;
    if ( lbefore || ( q == 0 ) ) 
    ocplistinfo [listentry ].hh.b1 = q ;
    else {
	
      r = ocplstackinfo [q ].hh.b0 ;
      while ( r != 0 ) {
	  
	p = q ;
	q = r ;
	r = ocplstackinfo [r ].hh.b0 ;
      } 
      ocplstackinfo [p ].hh.b0 = 0 ;
    } 
  } 
} 
void 
scanscaled ( void ) 
{
  /* 30 31 32 40 45 88 */ scanscaled_regmem 
  boolean negative  ;
  integer f  ;
  smallnumber k, kk  ;
  halfword p, q  ;
  f = 0 ;
  aritherror = false ;
  negative = false ;
  negative = false ;
  do {
      do { getxtoken () ;
    } while ( ! ( curcmd != 10 ) ) ;
    if ( curtok == 786477L ) 
    {
      negative = ! negative ;
      curtok = 786475L ;
    } 
  } while ( ! ( curtok != 786475L ) ) ;
  backinput () ;
  if ( curtok == 786476L ) 
  curtok = 786478L ;
  if ( curtok != 786478L ) 
  scanint () ;
  else {
      
    radix = 10 ;
    curval = 0 ;
  } 
  if ( curtok == 786476L ) 
  curtok = 786478L ;
  if ( ( radix == 10 ) && ( curtok == 786478L ) ) 
  {
    k = 0 ;
    p = 0 ;
    gettoken () ;
    while ( true ) {
	
      getxtoken () ;
      if ( ( curtok > 786489L ) || ( curtok < 786480L ) ) 
      goto lab31 ;
      if ( k < 17 ) 
      {
	q = getavail () ;
	mem [q ].hh .v.RH = p ;
	mem [q ].hh .v.LH = curtok - 786480L ;
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
  if ( curval < 0 ) 
  {
    negative = ! negative ;
    curval = - (integer) curval ;
  } 
  if ( curval > 16384 ) 
  aritherror = true ;
  else curval = curval * 65536L + f ;
  if ( aritherror || ( abs ( curval ) >= 1073741824L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66173L ) ;
    } 
  } 
  if ( negative ) 
  curval = - (integer) curval ;
} 
void 
zprintocplstack ( ocplstackindex lstackentry ) 
{
  printocplstack_regmem 
  ocplstackindex p  ;
  p = lstackentry ;
  while ( ( p != 0 ) ) {
      
    printesc ( newhashtext ( 1508273L + ocplstackinfo [p ].hh.b1 ) ) ;
    p = ocplstackinfo [p ].hh.b0 ;
    if ( ( p != 0 ) ) 
    print ( 44 ) ;
  } 
} 
void 
zprintocplist ( ocplistindex listentry ) 
{
  printocplist_regmem 
  ocplistindex p  ;
  print ( 91 ) ;
  p = listentry ;
  while ( ! ( ocplistinfo [p + 1 ].cint == ocpmaxint ) ) {
      
    print ( 40 ) ;
    printscaled ( ocplistinfo [p + 1 ].cint ) ;
    print ( 66174L ) ;
    printocplstack ( ocplistinfo [p ].hh.b1 ) ;
    print ( 41 ) ;
    p = ocplistinfo [p ].hh.b0 ;
    if ( ! ( ocplistinfo [p + 1 ].cint == ocpmaxint ) ) 
    print ( 66175L ) ;
  } 
  print ( 93 ) ;
} 
ocplistindex 
scanocplist ( void ) 
{
  register ocplistindex Result; scanocplist_regmem 
  scaled llstackno  ;
  quarterword lop  ;
  ocplistindex lstackentry  ;
  ocplistindex otherlist  ;
  internalocpnumber ocpident  ;
  ocplistindex result  ;
  getrtoken () ;
  if ( curcmd == 109 ) 
  result = copyocplist ( ocplistlist [curchr ]) ;
  else if ( curcmd != 114 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66176L ) ;
    } 
    {
      helpptr = 1 ;
      helpline [0 ]= 66177L ;
    } 
    result = makeocplistnode ( 0 , ocpmaxint , 0 ) ;
  } 
  else {
      
    lop = curchr ;
    scanscaled () ;
    llstackno = curval ;
    if ( ( llstackno <= 0 ) || ( llstackno >= ocpmaxint ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66178L ) ;
      } 
      result = makeocplistnode ( 0 , ocpmaxint , 0 ) ;
    } 
    else {
	
      if ( lop <= 2 ) 
      {
	scanocpident () ;
	ocpident = curval ;
      } 
      otherlist = scanocplist () ;
      lstackentry = ocpensurelstack ( otherlist , llstackno ) ;
      if ( lop <= 2 ) 
      ocpapplyadd ( lstackentry , ( lop == 1 ) , ocpident ) ;
      else ocpapplyremove ( lstackentry , ( lop == 3 ) ) ;
      result = otherlist ;
    } 
  } 
  Result = result ;
  return Result ;
} 
internalocplistnumber 
readocplist ( void ) 
{
  register internalocplistnumber Result; readocplist_regmem 
  internalocplistnumber f  ;
  internalocplistnumber g  ;
  g = 0 ;
  f = ocplistptr + 1 ;
  ocplistmemrunptr = ocplistmemptr ;
  ocplstackmemrunptr = ocplstackmemptr ;
  ocplistlist [f ]= scanocplist () ;
  ocplistptr = f ;
  ocplistmemptr = ocplistmemrunptr ;
  ocplstackmemptr = ocplstackmemrunptr ;
  g = f ;
  Result = g ;
  return Result ;
} 
void 
scanocplistident ( void ) 
{
  scanocplistident_regmem 
  internalocplistnumber f  ;
  do {
      getxtoken () ;
  } while ( ! ( curcmd != 10 ) ) ;
  if ( curcmd == 109 ) 
  f = curchr ;
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66179L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66147L ;
      helpline [0 ]= 66180L ;
    } 
    backerror () ;
    f = 0 ;
  } 
  curval = f ;
} 
void 
dviswap ( void ) 
{
  dviswap_regmem 
  if ( dviptr > ( 2147483647L - dvioffset ) ) 
  {
    curs = -2 ;
    fatalerror ( 66181L ) ;
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
  oval = f - 1 ;
  ocmd = 243 ;
  {
    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
    {
      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
	  
	if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
	oval = oval + 171 ;
	else {
	    
	  {
	    dvibuf [dviptr ]= ocmd ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	} 
      } 
    } 
    else {
	
      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
      {
	{
	  dvibuf [dviptr ]= ocmd + 1 ;
	  incr ( dviptr ) ;
	  if ( dviptr == dvilimit ) 
	  dviswap () ;
	} 
      } 
      else {
	  
	if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
	{
	  {
	    dvibuf [dviptr ]= ocmd + 2 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	} 
	else {
	    
	  {
	    {
	      dvibuf [dviptr ]= ocmd + 3 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	  } 
	  if ( oval >= 0 ) 
	  {
	    {
	      dvibuf [dviptr ]= oval / 16777216L ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	  } 
	  else {
	      
	    oval = oval + 1073741824L ;
	    oval = oval + 1073741824L ;
	    {
	      {
		dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	    oval = oval % 16777216L ;
	  } 
	  {
	    {
	      dvibuf [dviptr ]= oval / 65536L ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	  } 
	  oval = oval % 65536L ;
	} 
	{
	  {
	    dvibuf [dviptr ]= oval / 65536L ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	} 
	oval = oval % 65536L ;
      } 
      {
	{
	  dvibuf [dviptr ]= oval / 256 ;
	  incr ( dviptr ) ;
	  if ( dviptr == dvilimit ) 
	  dviswap () ;
	} 
      } 
      oval = oval % 256 ;
    } 
    {
      {
	dvibuf [dviptr ]= oval ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
    } 
  } 
  {
    dvibuf [dviptr ]= fonttables [f ][ 1 ].cint ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {
    dvibuf [dviptr ]= fonttables [f ][ 2 ].cint ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {
    dvibuf [dviptr ]= fonttables [f ][ 3 ].cint ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {
    dvibuf [dviptr ]= fonttables [f ][ 4 ].cint ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  dvifour ( fonttables [f ][ 6 ].cint ) ;
  dvifour ( fonttables [f ][ 7 ].cint ) ;
  {
    dvibuf [dviptr ]= length ( fonttables [f ][ 11 ].cint ) ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {
    dvibuf [dviptr ]= length ( fonttables [f ][ 10 ].cint ) ;
    incr ( dviptr ) ;
    if ( dviptr == dvilimit ) 
    dviswap () ;
  } 
  {register integer for_end; k = strstartar [fonttables [f ][ 11 ].cint - 
  65536L ];for_end = strstartar [fonttables [f ][ 11 ].cint - 65535L ]- 
  1 ; if ( k <= for_end) do 
    {
      dvibuf [dviptr ]= strpool [k ];
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
  while ( k++ < for_end ) ;} 
  {register integer for_end; k = strstartar [fonttables [f ][ 10 ].cint - 
  65536L ];for_end = strstartar [fonttables [f ][ 10 ].cint - 65535L ]- 
  1 ; if ( k <= for_end) do 
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
  switch ( ( dvidirection / 4 ) ) 
  {case 0 : 
    {
      ;
    } 
    break ;
  case 1 : 
    {
      if ( o == 143 ) 
      w = - (integer) w ;
    } 
    break ;
  case 2 : 
    {
      if ( o == 143 ) 
      o = 157 ;
      else o = 143 ;
    } 
    break ;
  case 3 : 
    {
      if ( o == 143 ) 
      {
	o = 157 ;
	w = - (integer) w ;
      } 
      else o = 143 ;
    } 
    break ;
  case 4 : 
    {
      if ( o == 157 ) 
      w = - (integer) w ;
    } 
    break ;
  case 5 : 
    {
      w = - (integer) w ;
    } 
    break ;
  case 6 : 
    {
      if ( o == 143 ) 
      o = 157 ;
      else {
	  
	o = 143 ;
	w = - (integer) w ;
      } 
    } 
    break ;
  case 7 : 
    {
      if ( o == 143 ) 
      o = 157 ;
      else o = 143 ;
      w = - (integer) w ;
    } 
    break ;
  } 
  if ( false ) 
  {
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
    while ( p != 0 ) {
	
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
  } 
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
  while ( downptr != 0 ) {
      
    if ( mem [downptr + 2 ].cint < l ) 
    goto lab30 ;
    p = downptr ;
    downptr = mem [p ].hh .v.RH ;
    freenode ( p , 3 ) ;
  } 
  lab30: while ( rightptr != 0 ) {
      
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
  specialout_regmem 
  unsigned char oldsetting  ;
  poolpointer k  ;
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
  showtokenlist ( mem [mem [p + 1 ].hh .v.RH ].hh .v.RH , 0 , poolsize - 
  poolptr ) ;
  selector = oldsetting ;
  {
    if ( poolptr + 1 > poolsize ) 
    overflow ( 65543L , poolsize - initpoolptr ) ;
  } 
  if ( ( poolptr - strstartar [strptr - 65536L ]) < 256 ) 
  {
    {
      dvibuf [dviptr ]= 239 ;
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
    {
      dvibuf [dviptr ]= ( poolptr - strstartar [strptr - 65536L ]) ;
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
    dvifour ( ( poolptr - strstartar [strptr - 65536L ]) ) ;
  } 
  {register integer for_end; k = strstartar [strptr - 65536L ];for_end = 
  poolptr - 1 ; if ( k <= for_end) do 
    {
      dvibuf [dviptr ]= strpool [k ];
      incr ( dviptr ) ;
      if ( dviptr == dvilimit ) 
      dviswap () ;
    } 
  while ( k++ < for_end ) ;} 
  poolptr = strstartar [strptr - 65536L ];
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
  mem [q ].hh .v.LH = 131197L ;
  r = getavail () ;
  mem [q ].hh .v.RH = r ;
  mem [r ].hh .v.LH = 1245193L ;
  begintokenlist ( q , 4 ) ;
  begintokenlist ( mem [p + 1 ].hh .v.RH , 16 ) ;
  q = getavail () ;
  mem [q ].hh .v.LH = 65659L ;
  begintokenlist ( q , 4 ) ;
  oldmode = curlist .modefield ;
  curlist .modefield = 0 ;
  curcs = writeloc ;
  q = scantoks ( false , true ) ;
  gettoken () ;
  if ( curtok != 1245193L ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66690L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66691L ;
      helpline [0 ]= 66369L ;
    } 
    error () ;
    do {
	gettoken () ;
    } while ( ! ( curtok == 1245193L ) ) ;
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
    printnl ( 65624L ) ;
  } 
  tokenshow ( defref ) ;
  println () ;
  flushlist ( defref ) ;
  if ( j == 18 ) 
  {
    if ( ( neweqtbint ( 1049437L ) <= 0 ) ) 
    selector = 18 ;
    else selector = 19 ;
    if ( ! logopened ) 
    selector = 17 ;
    printnl ( 66682L ) ;
    {register integer for_end; d = 0 ;for_end = ( poolptr - strstartar [
    strptr - 65536L ]) - 1 ; if ( d <= for_end) do 
      {
	print ( strpool [strstartar [strptr - 65536L ]+ d ]) ;
      } 
    while ( d++ < for_end ) ;} 
    print ( 66683L ) ;
    if ( shellenabledp ) 
    {
      {
	if ( poolptr + 1 > poolsize ) 
	overflow ( 65543L , poolsize - initpoolptr ) ;
      } 
      {
	strpool [poolptr ]= 0 ;
	incr ( poolptr ) ;
      } 
      clobbered = false ;
      {register integer for_end; d = 0 ;for_end = ( poolptr - strstartar [
      strptr - 65536L ]) - 1 ; if ( d <= for_end) do 
	{
	  strpool [strstartar [strptr - 65536L ]+ d ]= xchr [strpool [
	  strstartar [strptr - 65536L ]+ d ]];
	  if ( ( strpool [strstartar [strptr - 65536L ]+ d ]== 0 ) && ( d 
	  < ( poolptr - strstartar [strptr - 65536L ]) - 1 ) ) 
	  clobbered = true ;
	} 
      while ( d++ < for_end ) ;} 
      if ( clobbered ) 
      print ( 66684L ) ;
      else {
	  
	{register integer for_end; d = 0 ;for_end = ( poolptr - strstartar [
	strptr - 65536L ]) - 1 ; if ( d <= for_end) do 
	  {
	    outsidestringarray [d ]= xchr [strpool [strstartar [strptr - 
	    65536L ]+ d ]];
	  } 
	while ( d++ < for_end ) ;} 
	outsidestringarray [( poolptr - strstartar [strptr - 65536L ]) ]= 
	0 ;
	runsystemret = runsystem ( stringcast ( outsidestringarray ) ) ;
	if ( runsystemret == -1 ) 
	print ( 66685L ) ;
	else if ( runsystemret == 0 ) 
	print ( 66686L ) ;
	else if ( runsystemret == 1 ) 
	print ( 66687L ) ;
	else if ( runsystemret == 2 ) 
	print ( 66688L ) ;
      } 
    } 
    else {
	
      print ( 66689L ) ;
    } 
    printchar ( 46 ) ;
    printnl ( 65624L ) ;
    println () ;
    poolptr = strstartar [strptr - 65536L ];
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
	  if ( curext == 65624L ) 
	  curext = 66117L ;
	  packfilename ( curname , curarea , curext ) ;
	  while ( ! kpseoutnameok ( nameoffile + 1 ) || ! aopenout ( writefile 
	  [j ]) ) promptfilename ( 66693L , 66117L ) ;
	  writeopen [j ]= true ;
	  if ( logopened ) 
	  {
	    oldsetting = selector ;
	    if ( ( neweqtbint ( 1049437L ) <= 0 ) ) 
	    selector = 18 ;
	    else selector = 19 ;
	    printnl ( 66694L ) ;
	    printint ( j ) ;
	    print ( 66695L ) ;
	    printfilename ( curname , curarea , curext ) ;
	    print ( 66116L ) ;
	    printnl ( 65624L ) ;
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
    ;
    break ;
    default: 
    confusion ( 66692L ) ;
    break ;
  } 
} 
void 
hlistout ( void ) 
{
  /* 21 13 14 15 */ hlistout_regmem 
  scaled baseline  ;
  scaled cwd, cht, cdp  ;
  quarterword chtdp  ;
  fourquarters cinfo  ;
  scaled edgev  ;
  scaled edgeh  ;
  scaled effectivehorizontal  ;
  scaled basepointhorizontal  ;
  scaled basepointvertical  ;
  scaled savingh  ;
  scaled savingv  ;
  integer savedirection  ;
  halfword dirtmp, dirptr  ;
  integer dvidirh, dvidirptr, dvitempptr  ;
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
  real gluetemp  ;
  real curglue  ;
  scaled curg  ;
  curg = 0 ;
  curglue = 0.0 ;
  thisbox = tempptr ;
  gorder = mem [thisbox + 5 ].hh.b1 ;
  gsign = mem [thisbox + 5 ].hh.b0 ;
  p = mem [thisbox + 5 ].hh .v.RH ;
  savedirection = dvidirection ;
  dvidirection = mem [thisbox + 7 ].cint ;
  {
    dirptr = 0 ;
    {
      dirtmp = newdir ( dvidirection ) ;
      mem [dirtmp ].hh .v.RH = dirptr ;
      dirptr = dirtmp ;
      dirptr = dirtmp ;
    } 
    mem [dirptr + 2 ].hh .v.LH = dviptr ;
  } 
  savingh = dvih ;
  savingv = dviv ;
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
  baseline = curv ;
  leftedge = curh ;
  while ( p != 0 ) lab21: if ( ( p >= himemmin ) ) 
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
    do {
	f = mem [p ].hh.b0 ;
      c = mem [p ].hh.b1 ;
      if ( f != dvif ) 
      {
	if ( ! fonttables [f ][ 15 ].cint ) 
	{
	  dvifontdef ( f ) ;
	  fonttables [f ][ 15 ].cint = true ;
	} 
	oval = f - 1 ;
	ocmd = 235 ;
	{
	  if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	  {
	    if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		
	      if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
	      oval = oval + 171 ;
	      else {
		  
		{
		  dvibuf [dviptr ]= ocmd ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	    } 
	  } 
	  else {
	      
	    if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	    {
	      {
		dvibuf [dviptr ]= ocmd + 1 ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	    else {
		
	      if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 2 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		{
		  {
		    dvibuf [dviptr ]= ocmd + 3 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		if ( oval >= 0 ) 
		{
		  {
		    dvibuf [dviptr ]= oval / 16777216L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  oval = oval + 1073741824L ;
		  oval = oval + 1073741824L ;
		  {
		    {
		      dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 16777216L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 65536L ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 65536L ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval / 256 ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	    oval = oval % 256 ;
	  } 
	  {
	    {
	      dvibuf [dviptr ]= oval ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	  } 
	} 
	dvif = f ;
      } 
      cinfo = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f 
      ][ 5 ].cint + c ].qqqq ;
      chtdp = cinfo .b1 ;
      if ( ( ( dirsecondary [dvidirection ]) % 2 ) == ( ( dirtertiary [
      dvidirection ]) % 2 ) ) 
      {
	cht = fonttables [f ][ fonttables [f ][ 36 ].cint + cinfo .b0 ]
	.cint / 2 ;
	cwd = fonttables [f ][ fonttables [f ][ 37 ].cint + ( chtdp ) / 256 
	].cint + fonttables [f ][ fonttables [f ][ 38 ].cint + ( chtdp ) % 
	256 ].cint ;
      } 
      else {
	  
	cht = fonttables [f ][ fonttables [f ][ 37 ].cint + ( chtdp ) / 256 
	].cint ;
	cdp = fonttables [f ][ fonttables [f ][ 38 ].cint + ( chtdp ) % 256 
	].cint ;
	cwd = fonttables [f ][ fonttables [f ][ 36 ].cint + cinfo .b0 ]
	.cint ;
      } 
      curh = curh + cwd ;
      if ( ( fonttables [f ][ 21 ].cint != -1 ) ) 
      switch ( ( dvidirection % 16 ) ) 
      {case 0 : 
      case 2 : 
	{
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 128 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	} 
	break ;
      case 4 : 
      case 6 : 
	{
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cwd ) ;
	} 
	break ;
      case 9 : 
      case 11 : 
	{
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cwd ) ;
	} 
	break ;
      case 13 : 
      case 15 : 
	{
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cwd ) ;
	} 
	break ;
      case 1 : 
      case 3 : 
	{
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cwd ) ;
	} 
	break ;
      case 5 : 
      case 7 : 
	{
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cwd ) ;
	} 
	break ;
      case 8 : 
      case 10 : 
	{
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cwd ) ;
	} 
	break ;
      case 12 : 
      case 14 : 
	{
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cwd ) ;
	} 
	break ;
      } 
      else switch ( ( dvidirection % 16 ) ) 
      {case 0 : 
	{
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 128 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	} 
	break ;
      case 2 : 
	{
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cht ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 128 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cht ) ;
	} 
	break ;
      case 4 : 
	{
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cwd ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	} 
	break ;
      case 6 : 
	{
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cwd ) ;
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cht ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cht ) ;
	} 
	break ;
      case 9 : 
	{
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cwd ) ;
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cht ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cht ) ;
	} 
	break ;
      case 11 : 
	{
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cwd ) ;
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cdp ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cdp ) ;
	} 
	break ;
      case 13 : 
	{
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cht ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cht ) ;
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cwd ) ;
	} 
	break ;
      case 15 : 
	{
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cdp ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cdp ) ;
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cwd ) ;
	} 
	break ;
      case 1 : 
      case 3 : 
	{
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cht ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cht ) ;
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cwd ) ;
	} 
	break ;
      case 5 : 
      case 7 : 
	{
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cwd ) ;
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cht ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cht ) ;
	} 
	break ;
      case 8 : 
      case 10 : 
	{
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cwd ) ;
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cht ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cht ) ;
	} 
	break ;
      case 12 : 
      case 14 : 
	{
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cht ) ;
	  oval = c - fonttables [f ][ 5 ].cint ;
	  ocmd = 133 ;
	  {
	    if ( ( oval < 256 ) && ( oval >= 0 ) ) 
	    {
	      if ( ( ocmd != 128 ) || ( oval > 127 ) ) {
		  
		if ( ( ocmd == 235 ) && ( oval < 64 ) ) 
		oval = oval + 171 ;
		else {
		    
		  {
		    dvibuf [dviptr ]= ocmd ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
	      } 
	    } 
	    else {
		
	      if ( ( oval < 65536L ) && ( oval >= 0 ) ) 
	      {
		{
		  dvibuf [dviptr ]= ocmd + 1 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      else {
		  
		if ( ( oval < 16777216L ) && ( oval >= 0 ) ) 
		{
		  {
		    dvibuf [dviptr ]= ocmd + 2 ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		else {
		    
		  {
		    {
		      dvibuf [dviptr ]= ocmd + 3 ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  if ( oval >= 0 ) 
		  {
		    {
		      dvibuf [dviptr ]= oval / 16777216L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  else {
		      
		    oval = oval + 1073741824L ;
		    oval = oval + 1073741824L ;
		    {
		      {
			dvibuf [dviptr ]= ( oval / 16777216L ) + 128 ;
			incr ( dviptr ) ;
			if ( dviptr == dvilimit ) 
			dviswap () ;
		      } 
		    } 
		    oval = oval % 16777216L ;
		  } 
		  {
		    {
		      dvibuf [dviptr ]= oval / 65536L ;
		      incr ( dviptr ) ;
		      if ( dviptr == dvilimit ) 
		      dviswap () ;
		    } 
		  } 
		  oval = oval % 65536L ;
		} 
		{
		  {
		    dvibuf [dviptr ]= oval / 65536L ;
		    incr ( dviptr ) ;
		    if ( dviptr == dvilimit ) 
		    dviswap () ;
		  } 
		} 
		oval = oval % 65536L ;
	      } 
	      {
		{
		  dvibuf [dviptr ]= oval / 256 ;
		  incr ( dviptr ) ;
		  if ( dviptr == dvilimit ) 
		  dviswap () ;
		} 
	      } 
	      oval = oval % 256 ;
	    } 
	    {
	      {
		dvibuf [dviptr ]= oval ;
		incr ( dviptr ) ;
		if ( dviptr == dvilimit ) 
		dviswap () ;
	      } 
	    } 
	  } 
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( cht ) ;
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) cwd ) ;
	} 
	break ;
      } 
      p = mem [p ].hh .v.RH ;
    } while ( ! ( ! ( p >= himemmin ) ) ) ;
    dvih = curh ;
  } 
  else {
      
    switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
      {
	if ( ! ( ( ( dirprimary [mem [p + 7 ].cint ]) % 2 ) != ( 
	dirprimary [dvidirection ]% 2 ) ) ) 
	{
	  effectivehorizontal = mem [p + 1 ].cint ;
	  basepointvertical = 0 ;
	  if ( ( ( ( dirsecondary [mem [p + 7 ].cint ]) + 2 ) % 4 ) == ( ( 
	  dirsecondary [dvidirection ]) % 4 ) ) 
	  basepointhorizontal = mem [p + 1 ].cint ;
	  else basepointhorizontal = 0 ;
	} 
	else {
	    
	  effectivehorizontal = mem [p + 3 ].cint + mem [p + 2 ].cint ;
	  if ( ! ( ( ( ( dirprimary [mem [p + 7 ].cint ]) + 2 ) % 4 ) == ( 
	  ( dirtertiary [mem [p + 7 ].cint ]) % 4 ) ) ) {
	      
	    if ( ( dirprimary [mem [p + 7 ].cint ]) == ( dirsecondary [
	    dvidirection ]) ) 
	    basepointhorizontal = mem [p + 3 ].cint ;
	    else basepointhorizontal = mem [p + 2 ].cint ;
	  } 
	  else if ( ( dirprimary [mem [p + 7 ].cint ]) == ( dirsecondary [
	  dvidirection ]) ) 
	  basepointhorizontal = mem [p + 2 ].cint ;
	  else basepointhorizontal = mem [p + 3 ].cint ;
	  if ( ( dirsecondary [mem [p + 7 ].cint ]) == ( dirprimary [
	  dvidirection ]) ) 
	  basepointvertical = - (integer) ( mem [p + 1 ].cint / 2 ) ;
	  else basepointvertical = ( mem [p + 1 ].cint / 2 ) ;
	} 
	if ( ! ( ( ( ( dirprimary [dvidirection ]) + 2 ) % 4 ) == ( ( 
	dirtertiary [dvidirection ]) % 4 ) ) ) 
	basepointvertical = basepointvertical + mem [p + 4 ].cint ;
	else basepointvertical = basepointvertical - mem [p + 4 ].cint ;
	if ( mem [p + 5 ].hh .v.RH == 0 ) 
	curh = curh + effectivehorizontal ;
	else {
	    
	  tempptr = p ;
	  edge = curh ;
	  curh = curh + basepointhorizontal ;
	  edgev = curv ;
	  curv = baseline + basepointvertical ;
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
	  saveh = dvih ;
	  savev = dviv ;
	  if ( mem [p ].hh.b0 == 1 ) 
	  vlistout () ;
	  else hlistout () ;
	  dvih = saveh ;
	  dviv = savev ;
	  curh = edge + effectivehorizontal ;
	  curv = baseline ;
	} 
      } 
      break ;
    case 2 : 
      {
	if ( ! ( ( ( dirprimary [mem [p + 4 ].hh .v.LH ]) % 2 ) != ( 
	dirprimary [dvidirection ]% 2 ) ) ) 
	{
	  ruleht = mem [p + 3 ].cint ;
	  ruledp = mem [p + 2 ].cint ;
	  rulewd = mem [p + 1 ].cint ;
	} 
	else {
	    
	  ruleht = mem [p + 1 ].cint / 2 ;
	  ruledp = mem [p + 1 ].cint / 2 ;
	  rulewd = mem [p + 3 ].cint + mem [p + 2 ].cint ;
	} 
	goto lab14 ;
      } 
      break ;
    case 8 : 
      if ( mem [p ].hh.b1 != 7 ) 
      outwhat ( p ) ;
      else {
	  
	if ( mem [p + 1 ].hh .v.LH >= 0 ) 
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
	    dirtmp = getnode ( 4 ) ;
	    mem [dirtmp ].hh.b0 = 8 ;
	    mem [dirtmp ].hh.b1 = 7 ;
	    mem [dirtmp + 1 ].hh .v.LH = mem [p + 1 ].hh .v.LH ;
	    mem [dirtmp + 1 ].hh .v.RH = mem [p + 1 ].hh .v.RH ;
	    mem [dirtmp + 3 ].hh .v.LH = mem [p + 3 ].hh .v.LH ;
	    mem [dirtmp + 2 ].hh .v.LH = mem [p + 2 ].hh .v.LH ;
	    mem [dirtmp ].hh .v.RH = dirptr ;
	    dirptr = dirtmp ;
	  } 
	  if ( ( ( ( dirsecondary [mem [dirptr + 1 ].hh .v.LH ]) + 2 ) % 4 
	  ) == ( ( dirsecondary [dvidirection ]) % 4 ) ) 
	  {
	    if ( ( dirsecondary [dvidirection ]== 0 ) || ( dirsecondary [
	    dvidirection ]== 2 ) ) 
	    {
	      dvibuf [dviptr ]= 160 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    else {
		
	      dvibuf [dviptr ]= 146 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    mem [dirptr + 2 ].hh .v.LH = dviptr ;
	    mem [dirptr + 3 ].hh .v.LH = dvih ;
	    dvifour ( 0 ) ;
	    curh = 0 ;
	    dvih = 0 ;
	  } 
	  else {
	      
	    mem [dirptr + 2 ].hh .v.LH = dviptr ;
	    mem [dirptr + 3 ].hh .v.LH = dvih ;
	  } 
	  dvidirection = mem [dirptr + 1 ].hh .v.LH ;
	} 
	else {
	    
	  dvidirh = mem [dirptr + 3 ].hh .v.LH ;
	  dvidirptr = mem [dirptr + 2 ].hh .v.LH ;
	  {
	    dirtmp = dirptr ;
	    dirptr = mem [dirtmp ].hh .v.RH ;
	    freenode ( dirtmp , 4 ) ;
	  } 
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
	  dvidirection = mem [dirptr + 1 ].hh .v.LH ;
	  if ( ( ( ( dirsecondary [mem [p + 1 ].hh .v.LH + 64 ]) + 2 ) % 4 
	  ) == ( ( dirsecondary [dvidirection ]) % 4 ) ) 
	  {
	    dvitempptr = dviptr ;
	    dviptr = dvidirptr ;
	    if ( ( dirsecondary [dvidirection ]== 0 ) || ( dirsecondary [
	    dvidirection ]== 1 ) ) 
	    dvifour ( dvih ) ;
	    else dvifour ( - (integer) dvih ) ;
	    dviptr = dvitempptr ;
	    if ( ( dirsecondary [dvidirection ]== 0 ) || ( dirsecondary [
	    dvidirection ]== 2 ) ) 
	    {
	      dvibuf [dviptr ]= 160 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    else {
		
	      dvibuf [dviptr ]= 146 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    if ( ( dirsecondary [dvidirection ]== 0 ) || ( dirsecondary [
	    dvidirection ]== 1 ) ) 
	    dvifour ( dvih ) ;
	    else dvifour ( - (integer) dvih ) ;
	  } 
	  curh = dvidirh + dvih ;
	  dvih = curh ;
	} 
      } 
      break ;
    case 10 : 
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
	if ( mem [p ].hh.b1 >= 100 ) 
	{
	  leaderbox = mem [p + 1 ].hh .v.RH ;
	  if ( mem [leaderbox ].hh.b0 == 2 ) 
	  {
	    ruleht = mem [leaderbox + 3 ].cint ;
	    ruledp = mem [leaderbox + 2 ].cint ;
	    goto lab14 ;
	  } 
	  if ( ! ( ( ( dirprimary [mem [leaderbox + 7 ].cint ]) % 2 ) != ( 
	  dirprimary [dvidirection ]% 2 ) ) ) 
	  leaderwd = mem [leaderbox + 1 ].cint ;
	  else leaderwd = mem [leaderbox + 3 ].cint + mem [leaderbox + 2 ]
	  .cint ;
	  if ( ( leaderwd > 0 ) && ( rulewd > 0 ) ) 
	  {
	    rulewd = rulewd + 10 ;
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
		
	      if ( ! ( ( ( dirprimary [mem [leaderbox + 7 ].cint ]) % 2 ) 
	      != ( dirprimary [dvidirection ]% 2 ) ) ) 
	      {
		basepointvertical = 0 ;
		if ( ( ( ( dirsecondary [mem [leaderbox + 7 ].cint ]) + 2 
		) % 4 ) == ( ( dirsecondary [dvidirection ]) % 4 ) ) 
		basepointhorizontal = mem [leaderbox + 1 ].cint ;
		else basepointhorizontal = 0 ;
	      } 
	      else {
		  
		if ( ! ( ( ( ( dirprimary [mem [leaderbox + 7 ].cint ]) + 
		2 ) % 4 ) == ( ( dirtertiary [mem [leaderbox + 7 ].cint ]) 
		% 4 ) ) ) {
		    
		  if ( ( dirprimary [mem [leaderbox + 7 ].cint ]) == ( 
		  dirsecondary [dvidirection ]) ) 
		  basepointhorizontal = mem [leaderbox + 3 ].cint ;
		  else basepointhorizontal = mem [leaderbox + 2 ].cint ;
		} 
		else if ( ( dirprimary [mem [leaderbox + 7 ].cint ]) == ( 
		dirsecondary [dvidirection ]) ) 
		basepointhorizontal = mem [leaderbox + 2 ].cint ;
		else basepointhorizontal = mem [leaderbox + 3 ].cint ;
		if ( ( dirsecondary [mem [leaderbox + 7 ].cint ]) == ( 
		dirprimary [dvidirection ]) ) 
		basepointvertical = - (integer) ( mem [leaderbox + 1 ].cint 
		/ 2 ) ;
		else basepointvertical = ( mem [leaderbox + 1 ].cint / 2 ) ;
	      } 
	      if ( ! ( ( ( ( dirprimary [dvidirection ]) + 2 ) % 4 ) == ( ( 
	      dirtertiary [dvidirection ]) % 4 ) ) ) 
	      basepointvertical = basepointvertical + mem [leaderbox + 4 ]
	      .cint ;
	      else basepointvertical = basepointvertical - mem [leaderbox + 4 
	      ].cint ;
	      tempptr = leaderbox ;
	      edgeh = curh ;
	      curh = curh + basepointhorizontal ;
	      edgev = curv ;
	      curv = baseline + basepointvertical ;
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
	      saveh = dvih ;
	      savev = dviv ;
	      outerdoingleaders = doingleaders ;
	      doingleaders = true ;
	      if ( mem [leaderbox ].hh.b0 == 1 ) 
	      vlistout () ;
	      else hlistout () ;
	      doingleaders = outerdoingleaders ;
	      dvih = saveh ;
	      dviv = savev ;
	      curh = edgeh + leaderwd + lx ;
	      curv = baseline ;
	    } 
	    curh = edge - 10 ;
	    goto lab15 ;
	  } 
	} 
	goto lab13 ;
      } 
      break ;
    case 11 : 
    case 9 : 
      curh = curh + mem [p + 1 ].cint ;
      break ;
    case 6 : 
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
    goto lab15 ;
    lab14: if ( ( ruleht == -1073741824L ) ) 
    ruleht = mem [thisbox + 3 ].cint ;
    if ( ( ruledp == -1073741824L ) ) 
    ruledp = mem [thisbox + 2 ].cint ;
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
      switch ( ( dvidirection % 16 ) ) 
      {case 0 : 
	{
	  {
	    dvibuf [dviptr ]= 132 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( ruleht ) ;
	  dvifour ( rulewd ) ;
	} 
	break ;
      case 2 : 
	{
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( ruleht ) ;
	  {
	    dvibuf [dviptr ]= 132 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( ruleht ) ;
	  dvifour ( rulewd ) ;
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) ruleht ) ;
	} 
	break ;
      case 4 : 
	{
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) rulewd ) ;
	  {
	    dvibuf [dviptr ]= 137 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( ruleht ) ;
	  dvifour ( rulewd ) ;
	} 
	break ;
      case 6 : 
	{
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) rulewd ) ;
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( ruleht ) ;
	  {
	    dvibuf [dviptr ]= 137 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( ruleht ) ;
	  dvifour ( rulewd ) ;
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) ruleht ) ;
	} 
	break ;
      case 9 : 
	{
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( rulewd ) ;
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) ruleht ) ;
	  {
	    dvibuf [dviptr ]= 132 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( rulewd ) ;
	  dvifour ( ruleht ) ;
	} 
	break ;
      case 11 : 
	{
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( rulewd ) ;
	  {
	    dvibuf [dviptr ]= 137 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( rulewd ) ;
	  dvifour ( ruleht ) ;
	} 
	break ;
      case 13 : 
	{
	  {
	    dvibuf [dviptr ]= 146 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) ruleht ) ;
	  {
	    dvibuf [dviptr ]= 132 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( rulewd ) ;
	  dvifour ( ruleht ) ;
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) rulewd ) ;
	} 
	break ;
      case 15 : 
	{
	  {
	    dvibuf [dviptr ]= 137 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( rulewd ) ;
	  dvifour ( ruleht ) ;
	  {
	    dvibuf [dviptr ]= 160 ;
	    incr ( dviptr ) ;
	    if ( dviptr == dvilimit ) 
	    dviswap () ;
	  } 
	  dvifour ( - (integer) rulewd ) ;
	} 
	break ;
      } 
      curv = baseline ;
      dvih = dvih + rulewd ;
    } 
    lab13: curh = curh + rulewd ;
    lab15: p = mem [p ].hh .v.RH ;
  } 
  curh = savingh ;
  curv = savingv ;
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
  prunemovements ( saveloc ) ;
  if ( curs > 0 ) 
  dvipop ( saveloc ) ;
  decr ( curs ) ;
  dvidirection = savedirection ;
  {
    while ( dirptr != 0 ) {
	
      dirtmp = dirptr ;
      dirptr = mem [dirtmp ].hh .v.RH ;
      freenode ( dirtmp , 4 ) ;
    } 
  } 
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
  integer savedirection  ;
  scaled effectivevertical  ;
  scaled basepointhorizontal  ;
  scaled basepointvertical  ;
  scaled edgev  ;
  scaled savingv  ;
  scaled savingh  ;
  curg = 0 ;
  curglue = 0.0 ;
  thisbox = tempptr ;
  gorder = mem [thisbox + 5 ].hh.b1 ;
  gsign = mem [thisbox + 5 ].hh.b0 ;
  p = mem [thisbox + 5 ].hh .v.RH ;
  savingv = dviv ;
  savingh = dvih ;
  savedirection = dvidirection ;
  dvidirection = mem [thisbox + 7 ].cint ;
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
  leftedge = curh ;
  curv = curv - mem [thisbox + 3 ].cint ;
  topedge = curv ;
  while ( p != 0 ) {
      
    if ( ( p >= himemmin ) ) 
    confusion ( 66183L ) ;
    else {
	
      switch ( mem [p ].hh.b0 ) 
      {case 0 : 
      case 1 : 
	{
	  if ( ! ( ( ( dirprimary [mem [p + 7 ].cint ]) % 2 ) != ( 
	  dirprimary [dvidirection ]% 2 ) ) ) 
	  {
	    effectivevertical = mem [p + 3 ].cint + mem [p + 2 ].cint ;
	    if ( ( mem [p ].hh.b0 == 0 ) && ( ( ( ( dirprimary [mem [p + 7 
	    ].cint ]) + 2 ) % 4 ) == ( ( dirtertiary [mem [p + 7 ].cint ]
	    ) % 4 ) ) ) 
	    basepointvertical = mem [p + 2 ].cint ;
	    else basepointvertical = mem [p + 3 ].cint ;
	    if ( ( ( ( dirsecondary [mem [p + 7 ].cint ]) + 2 ) % 4 ) == ( 
	    ( dirsecondary [dvidirection ]) % 4 ) ) 
	    basepointhorizontal = mem [p + 1 ].cint ;
	    else basepointhorizontal = 0 ;
	  } 
	  else {
	      
	    effectivevertical = mem [p + 1 ].cint ;
	    if ( ! ( ( ( ( dirprimary [mem [p + 7 ].cint ]) + 2 ) % 4 ) == 
	    ( ( dirtertiary [mem [p + 7 ].cint ]) % 4 ) ) ) {
		
	      if ( ( dirprimary [mem [p + 7 ].cint ]) == ( dirsecondary [
	      dvidirection ]) ) 
	      basepointhorizontal = mem [p + 3 ].cint ;
	      else basepointhorizontal = mem [p + 2 ].cint ;
	    } 
	    else if ( ( dirprimary [mem [p + 7 ].cint ]) == ( dirsecondary 
	    [dvidirection ]) ) 
	    basepointhorizontal = mem [p + 2 ].cint ;
	    else basepointhorizontal = mem [p + 3 ].cint ;
	    if ( ( dirsecondary [mem [p + 7 ].cint ]) == ( dirprimary [
	    dvidirection ]) ) 
	    basepointvertical = 0 ;
	    else basepointvertical = mem [p + 1 ].cint ;
	  } 
	  basepointhorizontal = basepointhorizontal + mem [p + 4 ].cint ;
	  if ( mem [p + 5 ].hh .v.RH == 0 ) 
	  {
	    curv = curv + effectivevertical ;
	  } 
	  else {
	      
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
	    edgev = curv ;
	    curh = leftedge + basepointhorizontal ;
	    curv = curv + basepointvertical ;
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
	    saveh = dvih ;
	    savev = dviv ;
	    tempptr = p ;
	    if ( mem [p ].hh.b0 == 1 ) 
	    vlistout () ;
	    else hlistout () ;
	    dvih = saveh ;
	    dviv = savev ;
	    curh = leftedge ;
	    curv = edgev + effectivevertical ;
	  } 
	} 
	break ;
      case 2 : 
	{
	  if ( ! ( ( ( dirprimary [mem [p + 4 ].hh .v.LH ]) % 2 ) != ( 
	  dirprimary [dvidirection ]% 2 ) ) ) 
	  {
	    ruleht = mem [p + 3 ].cint ;
	    ruledp = mem [p + 2 ].cint ;
	    rulewd = mem [p + 1 ].cint ;
	  } 
	  else {
	      
	    ruleht = mem [p + 1 ].cint / 2 ;
	    ruledp = mem [p + 1 ].cint / 2 ;
	    rulewd = mem [p + 3 ].cint + mem [p + 2 ].cint ;
	  } 
	  goto lab14 ;
	} 
	break ;
      case 8 : 
	outwhat ( p ) ;
	break ;
      case 10 : 
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
	    if ( mem [leaderbox ].hh.b0 == 2 ) 
	    {
	      rulewd = mem [leaderbox + 1 ].cint ;
	      ruledp = 0 ;
	      goto lab14 ;
	    } 
	    if ( ! ( ( ( dirprimary [mem [leaderbox + 7 ].cint ]) % 2 ) != 
	    ( dirprimary [dvidirection ]% 2 ) ) ) 
	    leaderht = mem [leaderbox + 3 ].cint + mem [leaderbox + 2 ]
	    .cint ;
	    else leaderht = mem [leaderbox + 1 ].cint ;
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
		  
		if ( ! ( ( ( dirprimary [mem [leaderbox + 7 ].cint ]) % 2 
		) != ( dirprimary [dvidirection ]% 2 ) ) ) 
		{
		  effectivevertical = mem [leaderbox + 3 ].cint + mem [
		  leaderbox + 2 ].cint ;
		  if ( ( mem [leaderbox ].hh.b0 == 0 ) && ( ( ( ( dirprimary 
		  [mem [leaderbox + 7 ].cint ]) + 2 ) % 4 ) == ( ( 
		  dirtertiary [mem [leaderbox + 7 ].cint ]) % 4 ) ) ) 
		  basepointvertical = mem [leaderbox + 2 ].cint ;
		  else basepointvertical = mem [leaderbox + 3 ].cint ;
		  if ( ( ( ( dirsecondary [mem [leaderbox + 7 ].cint ]) + 
		  2 ) % 4 ) == ( ( dirsecondary [dvidirection ]) % 4 ) ) 
		  basepointhorizontal = mem [leaderbox + 1 ].cint ;
		  else basepointhorizontal = 0 ;
		} 
		else {
		    
		  effectivevertical = mem [leaderbox + 1 ].cint ;
		  if ( ! ( ( ( ( dirprimary [mem [leaderbox + 7 ].cint ]) 
		  + 2 ) % 4 ) == ( ( dirtertiary [mem [leaderbox + 7 ].cint 
		  ]) % 4 ) ) ) {
		      
		    if ( ( dirprimary [mem [leaderbox + 7 ].cint ]) == ( 
		    dirsecondary [dvidirection ]) ) 
		    basepointhorizontal = mem [leaderbox + 3 ].cint ;
		    else basepointhorizontal = mem [leaderbox + 2 ].cint ;
		  } 
		  else if ( ( dirprimary [mem [leaderbox + 7 ].cint ]) == 
		  ( dirsecondary [dvidirection ]) ) 
		  basepointhorizontal = mem [leaderbox + 2 ].cint ;
		  else basepointhorizontal = mem [leaderbox + 3 ].cint ;
		  if ( ( dirsecondary [mem [leaderbox + 7 ].cint ]) == ( 
		  dirprimary [dvidirection ]) ) 
		  basepointvertical = mem [leaderbox + 1 ].cint ;
		  else basepointvertical = 0 ;
		} 
		basepointhorizontal = basepointhorizontal + mem [leaderbox + 
		4 ].cint ;
		tempptr = leaderbox ;
		curh = leftedge + basepointhorizontal ;
		edgev = curv ;
		curv = curv + basepointvertical ;
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
		saveh = dvih ;
		savev = dviv ;
		outerdoingleaders = doingleaders ;
		doingleaders = true ;
		if ( mem [leaderbox ].hh.b0 == 1 ) 
		vlistout () ;
		else hlistout () ;
		doingleaders = outerdoingleaders ;
		dvih = saveh ;
		dviv = savev ;
		curh = leftedge ;
		curv = edgev + leaderht + lx ;
	      } 
	      curv = edge - 10 ;
	      goto lab15 ;
	    } 
	  } 
	  goto lab13 ;
	} 
	break ;
      case 11 : 
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
	switch ( ( dvidirection % 16 ) ) 
	{case 0 : 
	  {
	    {
	      dvibuf [dviptr ]= 137 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( ruleht ) ;
	    dvifour ( rulewd ) ;
	  } 
	  break ;
	case 2 : 
	  {
	    {
	      dvibuf [dviptr ]= 160 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( ruleht ) ;
	    {
	      dvibuf [dviptr ]= 137 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( ruleht ) ;
	    dvifour ( rulewd ) ;
	    {
	      dvibuf [dviptr ]= 160 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( - (integer) ruleht ) ;
	  } 
	  break ;
	case 4 : 
	  {
	    {
	      dvibuf [dviptr ]= 146 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( - (integer) rulewd ) ;
	    {
	      dvibuf [dviptr ]= 132 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( ruleht ) ;
	    dvifour ( rulewd ) ;
	  } 
	  break ;
	case 6 : 
	  {
	    {
	      dvibuf [dviptr ]= 160 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( ruleht ) ;
	    {
	      dvibuf [dviptr ]= 146 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( - (integer) rulewd ) ;
	    {
	      dvibuf [dviptr ]= 132 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( ruleht ) ;
	    dvifour ( rulewd ) ;
	    {
	      dvibuf [dviptr ]= 160 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( - (integer) ruleht ) ;
	  } 
	  break ;
	case 9 : 
	  {
	    {
	      dvibuf [dviptr ]= 160 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( rulewd ) ;
	    {
	      dvibuf [dviptr ]= 146 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( - (integer) ruleht ) ;
	    {
	      dvibuf [dviptr ]= 132 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( rulewd ) ;
	    dvifour ( ruleht ) ;
	    {
	      dvibuf [dviptr ]= 160 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( - (integer) rulewd ) ;
	  } 
	  break ;
	case 11 : 
	  {
	    {
	      dvibuf [dviptr ]= 160 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( rulewd ) ;
	    {
	      dvibuf [dviptr ]= 137 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( rulewd ) ;
	    dvifour ( ruleht ) ;
	    {
	      dvibuf [dviptr ]= 160 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( - (integer) rulewd ) ;
	  } 
	  break ;
	case 13 : 
	  {
	    {
	      dvibuf [dviptr ]= 146 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( - (integer) ruleht ) ;
	    {
	      dvibuf [dviptr ]= 132 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( rulewd ) ;
	    dvifour ( ruleht ) ;
	  } 
	  break ;
	case 15 : 
	  {
	    {
	      dvibuf [dviptr ]= 137 ;
	      incr ( dviptr ) ;
	      if ( dviptr == dvilimit ) 
	      dviswap () ;
	    } 
	    dvifour ( rulewd ) ;
	    dvifour ( ruleht ) ;
	  } 
	  break ;
	} 
      } 
      goto lab15 ;
      lab13: curv = curv + ruleht ;
    } 
    lab15: p = mem [p ].hh .v.RH ;
  } 
  curv = savingv ;
  curh = savingh ;
  if ( curv != dviv ) 
  {
    movement ( curv - dviv , 157 ) ;
    dviv = curv ;
  } 
  if ( curh != dvih ) 
  {
    movement ( curh - dvih , 143 ) ;
    dvih = curh ;
  } 
  prunemovements ( saveloc ) ;
  if ( curs > 0 ) 
  dvipop ( saveloc ) ;
  decr ( curs ) ;
  dvidirection = savedirection ;
} 
void 
zshipout ( halfword p ) 
{
  /* 30 */ shipout_regmem 
  integer pageloc  ;
  unsigned char j, k  ;
  poolpointer s  ;
  unsigned char oldsetting  ;
  if ( neweqtbint ( 1049442L ) > 0 ) 
  {
    printnl ( 65624L ) ;
    println () ;
    print ( 66184L ) ;
  } 
  if ( termoffset > maxprintline - 9 ) 
  println () ;
  else if ( ( termoffset > 0 ) || ( fileoffset > 0 ) ) 
  printchar ( 32 ) ;
  printchar ( 91 ) ;
  j = 9 ;
  while ( ( neweqtbint ( 1049484L + j ) == 0 ) && ( j > 0 ) ) decr ( j ) ;
  {register integer for_end; k = 0 ;for_end = j ; if ( k <= for_end) do 
    {
      printint ( neweqtbint ( 1049484L + k ) ) ;
      if ( k < j ) 
      printchar ( 46 ) ;
    } 
  while ( k++ < for_end ) ;} 
  fflush ( stdout ) ;
  if ( neweqtbint ( 1049442L ) > 0 ) 
  {
    printchar ( 93 ) ;
    begindiagnostic () ;
    showbox ( p ) ;
    enddiagnostic ( true ) ;
  } 
  if ( ( mem [p + 3 ].cint > 1073741823L ) || ( mem [p + 2 ].cint > 
  1073741823L ) || ( mem [p + 3 ].cint + mem [p + 2 ].cint + neweqtbsc ( 
  1180556L + ( 19 ) ) > 1073741823L ) || ( mem [p + 1 ].cint + neweqtbsc ( 
  1180556L + ( 18 ) ) > 1073741823L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66188L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66189L ;
      helpline [0 ]= 66190L ;
    } 
    error () ;
    if ( neweqtbint ( 1049442L ) <= 0 ) 
    {
      begindiagnostic () ;
      printnl ( 66191L ) ;
      showbox ( p ) ;
      enddiagnostic ( true ) ;
    } 
    goto lab30 ;
  } 
  if ( mem [p + 3 ].cint + mem [p + 2 ].cint + neweqtbsc ( 1180556L + ( 19 
  ) ) > maxv ) 
  maxv = mem [p + 3 ].cint + mem [p + 2 ].cint + neweqtbsc ( 1180556L + ( 
  19 ) ) ;
  if ( mem [p + 1 ].cint + neweqtbsc ( 1180556L + ( 18 ) ) > maxh ) 
  maxh = mem [p + 1 ].cint + neweqtbsc ( 1180556L + ( 18 ) ) ;
  dvih = 0 ;
  dviv = 0 ;
  curh = 0 ;
  curv = 0 ;
  dvif = 0 ;
  if ( outputfilename == 0 ) 
  {
    if ( jobname == 0 ) 
    openlogfile () ;
    packjobname ( 66121L ) ;
    while ( ! bopenout ( dvifile ) ) promptfilename ( 66122L , 66121L ) ;
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
    dvifour ( neweqtbint ( 1049425L ) ) ;
    if ( outputcomment ) 
    {
      l = strlen ( outputcomment ) ;
      {
	dvibuf [dviptr ]= l ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      {register integer for_end; s = 0 ;for_end = l - 1 ; if ( s <= for_end) 
      do 
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
      print ( 66182L ) ;
      printint ( neweqtbint ( 1049431L ) ) ;
      printchar ( 46 ) ;
      printtwo ( neweqtbint ( 1049430L ) ) ;
      printchar ( 46 ) ;
      printtwo ( neweqtbint ( 1049429L ) ) ;
      printchar ( 58 ) ;
      printtwo ( neweqtbint ( 1049428L ) / 60 ) ;
      printtwo ( neweqtbint ( 1049428L ) % 60 ) ;
      selector = oldsetting ;
      {
	dvibuf [dviptr ]= ( poolptr - strstartar [strptr - 65536L ]) ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      {register integer for_end; s = strstartar [strptr - 65536L ];for_end 
      = poolptr - 1 ; if ( s <= for_end) do 
	{
	  dvibuf [dviptr ]= strpool [s ];
	  incr ( dviptr ) ;
	  if ( dviptr == dvilimit ) 
	  dviswap () ;
	} 
      while ( s++ < for_end ) ;} 
      poolptr = strstartar [strptr - 65536L ];
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
    dvifour ( neweqtbint ( 1049484L + k ) ) ;
  while ( k++ < for_end ) ;} 
  dvifour ( lastbop ) ;
  lastbop = pageloc ;
  dvidirection = neweqtbint ( 1049479L ) ;
  switch ( ( dvidirection / 4 ) ) 
  {case 0 : 
  case 2 : 
    {
      ;
    } 
    break ;
  case 1 : 
  case 6 : 
    {
      {
	dvibuf [dviptr ]= 146 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( neweqtbsc ( 1180556L + ( 21 ) ) - neweqtbsc ( 1180556L + ( 23 
      ) ) ) ;
      dvih = - (integer) neweqtbsc ( 1180556L + ( 23 ) ) ;
    } 
    break ;
  case 7 : 
  case 5 : 
    {
      {
	dvibuf [dviptr ]= 146 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( neweqtbsc ( 1180556L + ( 21 ) ) - neweqtbsc ( 1180556L + ( 23 
      ) ) ) ;
      {
	dvibuf [dviptr ]= 160 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( neweqtbsc ( 1180556L + ( 22 ) ) - neweqtbsc ( 1180556L + ( 24 
      ) ) ) ;
      dvih = - (integer) neweqtbsc ( 1180556L + ( 23 ) ) ;
      dviv = - (integer) neweqtbsc ( 1180556L + ( 24 ) ) ;
    } 
    break ;
  case 4 : 
  case 3 : 
    {
      {
	dvibuf [dviptr ]= 160 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( neweqtbsc ( 1180556L + ( 22 ) ) - neweqtbsc ( 1180556L + ( 24 
      ) ) ) ;
      dviv = - (integer) neweqtbsc ( 1180556L + ( 24 ) ) ;
    } 
    break ;
  } 
  curh = neweqtbsc ( 1180556L + ( 18 ) ) ;
  curv = mem [p + 3 ].cint + neweqtbsc ( 1180556L + ( 19 ) ) ;
  switch ( ( dvidirection / 4 ) ) 
  {case 0 : 
    {
      {
	dvibuf [dviptr ]= 146 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( curh ) ;
      {
	dvibuf [dviptr ]= 160 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( curv ) ;
    } 
    break ;
  case 1 : 
    {
      {
	dvibuf [dviptr ]= 146 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( - (integer) curh ) ;
      {
	dvibuf [dviptr ]= 160 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( curv ) ;
    } 
    break ;
  case 2 : 
    {
      {
	dvibuf [dviptr ]= 146 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( curv ) ;
      {
	dvibuf [dviptr ]= 160 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( curh ) ;
    } 
    break ;
  case 3 : 
    {
      {
	dvibuf [dviptr ]= 146 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( curv ) ;
      {
	dvibuf [dviptr ]= 160 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( - (integer) curh ) ;
    } 
    break ;
  case 4 : 
    {
      {
	dvibuf [dviptr ]= 146 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( curh ) ;
      {
	dvibuf [dviptr ]= 160 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( - (integer) curv ) ;
    } 
    break ;
  case 5 : 
    {
      {
	dvibuf [dviptr ]= 146 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( - (integer) curh ) ;
      {
	dvibuf [dviptr ]= 160 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( - (integer) curv ) ;
    } 
    break ;
  case 6 : 
    {
      {
	dvibuf [dviptr ]= 146 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( - (integer) curv ) ;
      {
	dvibuf [dviptr ]= 160 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( curh ) ;
    } 
    break ;
  case 7 : 
    {
      {
	dvibuf [dviptr ]= 146 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( - (integer) curv ) ;
      {
	dvibuf [dviptr ]= 160 ;
	incr ( dviptr ) ;
	if ( dviptr == dvilimit ) 
	dviswap () ;
      } 
      dvifour ( - (integer) curh ) ;
    } 
    break ;
  } 
  tempptr = p ;
  dvih = dvih + curh ;
  dviv = dviv + curv ;
  if ( mem [p ].hh.b0 == 1 ) 
  vlistout () ;
  else hlistout () ;
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
      fatalerror ( 66181L ) ;
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
  if ( neweqtbint ( 1049442L ) <= 0 ) 
  printchar ( 93 ) ;
  deadcycles = 0 ;
  fflush ( stdout ) ;
	;
#ifdef STAT
  if ( neweqtbint ( 1049439L ) > 1 ) 
  {
    printnl ( 66185L ) ;
    printint ( varused ) ;
    printchar ( 38 ) ;
    printint ( dynused ) ;
    printchar ( 59 ) ;
  } 
#endif /* STAT */
  flushnodelist ( p ) ;
	;
#ifdef STAT
  if ( neweqtbint ( 1049439L ) > 1 ) 
  {
    print ( 66186L ) ;
    printint ( varused ) ;
    printchar ( 38 ) ;
    printint ( dynused ) ;
    print ( 66187L ) ;
    printint ( himemmin - lomemmax - 1 ) ;
    println () ;
  } 
#endif /* STAT */
} 
void 
zscanspec ( groupcode c , boolean threecodes ) 
{
  /* 40 */ scanspec_regmem 
  integer s  ;
  unsigned char speccode  ;
  if ( threecodes ) 
  s = savestack [saveptr + 0 ].cint ;
  if ( ( c != 6 ) && ( c != 12 ) ) 
  {
    if ( scankeyword ( 66196L ) ) 
    {
      scandir () ;
      specdirection = curval ;
    } 
  } 
  if ( scankeyword ( 66197L ) ) 
  speccode = 0 ;
  else if ( scankeyword ( 66198L ) ) 
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
  if ( ( c != 6 ) && ( c != 12 ) ) 
  {
    savestack [saveptr + 2 ].cint = specdirection ;
    {
      if ( specdirection != -1 ) 
      {
	savestack [saveptr + 3 ].cint = textdirptr ;
	textdirptr = newdir ( specdirection ) ;
      } 
      else savestack [saveptr + 3 ].cint = 0 ;
    } 
    saveptr = saveptr + 4 ;
    newsavelevel ( c ) ;
    scanleftbrace () ;
    eqworddefine ( 1049480L , specdirection ) ;
    eqworddefine ( 1049481L , specdirection ) ;
    eqworddefine ( 1049482L , specdirection ) ;
    eqworddefine ( 1049467L , curlevel ) ;
  } 
  else {
      
    saveptr = saveptr + 2 ;
    newsavelevel ( c ) ;
    scanleftbrace () ;
  } 
  specdirection = -1 ;
} 
halfword 
zhpack ( halfword p , scaled w , smallnumber m ) 
{
  /* 21 50 10 */ register halfword Result; hpack_regmem 
  halfword r  ;
  halfword q  ;
  scaled h, d, x  ;
  scaled s  ;
  halfword g  ;
  glueord o  ;
  internalfontnumber f  ;
  fourquarters i  ;
  eightbits hd  ;
  halfword dirtmp, dirptr  ;
  integer hpackdir  ;
  lastbadness = 0 ;
  r = getnode ( 8 ) ;
  mem [r ].hh.b0 = 0 ;
  if ( packdirection == -1 ) 
  mem [r + 7 ].cint = neweqtbint ( 1049482L ) ;
  else {
      
    mem [r + 7 ].cint = packdirection ;
    packdirection = -1 ;
  } 
  hpackdir = mem [r + 7 ].cint ;
  {
    dirptr = 0 ;
    {
      dirtmp = newdir ( hpackdir ) ;
      mem [dirtmp ].hh .v.RH = dirptr ;
      dirptr = dirtmp ;
      dirptr = dirtmp ;
    } 
  } 
  mem [r ].hh.b1 = 0 ;
  mem [r + 4 ].cint = 0 ;
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
  while ( p != 0 ) {
      
    lab21: while ( ( p >= himemmin ) ) {
	
      f = mem [p ].hh.b0 ;
      i = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f ][ 5 
      ].cint + mem [p ].hh.b1 ].qqqq ;
      hd = i .b1 ;
      if ( ( ( dirsecondary [hpackdir ]) % 2 ) == ( ( dirtertiary [hpackdir 
      ]) % 2 ) ) 
      {
	x = x + fonttables [f ][ fonttables [f ][ 37 ].cint + ( hd ) / 256 
	].cint + fonttables [f ][ fonttables [f ][ 38 ].cint + ( hd ) % 
	256 ].cint ;
	s = fonttables [f ][ fonttables [f ][ 36 ].cint + i .b0 ].cint / 2 
	;
	if ( s > h ) 
	h = s ;
	s = fonttables [f ][ fonttables [f ][ 36 ].cint + i .b0 ].cint / 2 
	;
	if ( s > d ) 
	d = s ;
      } 
      else if ( ( ( ( dirtertiary [hpackdir ]) + 2 ) % 4 ) == ( ( 
      dirtertiary [mem [r + 7 ].cint ]) % 4 ) ) 
      {
	x = x + fonttables [f ][ fonttables [f ][ 36 ].cint + i .b0 ].cint 
	;
	s = fonttables [f ][ fonttables [f ][ 38 ].cint + ( hd ) % 256 ]
	.cint ;
	if ( s > h ) 
	h = s ;
	s = fonttables [f ][ fonttables [f ][ 37 ].cint + ( hd ) / 256 ]
	.cint ;
	if ( s > d ) 
	d = s ;
      } 
      else {
	  
	x = x + fonttables [f ][ fonttables [f ][ 36 ].cint + i .b0 ].cint 
	;
	s = fonttables [f ][ fonttables [f ][ 37 ].cint + ( hd ) / 256 ]
	.cint ;
	if ( s > h ) 
	h = s ;
	s = fonttables [f ][ fonttables [f ][ 38 ].cint + ( hd ) % 256 ]
	.cint ;
	if ( s > d ) 
	d = s ;
      } 
      p = mem [p ].hh .v.RH ;
    } 
    if ( p != 0 ) 
    {
      switch ( mem [p ].hh.b0 ) 
      {case 0 : 
      case 1 : 
      case 2 : 
      case 13 : 
	{
	  if ( ( mem [p ].hh.b0 == 0 ) || ( mem [p ].hh.b0 == 1 ) ) 
	  {
	    if ( ( ( dirprimary [mem [p + 7 ].cint ]) % 2 ) != ( 
	    dirprimary [hpackdir ]% 2 ) ) 
	    {
	      x = x + mem [p + 3 ].cint + mem [p + 2 ].cint ;
	      s = mem [p + 4 ].cint ;
	      if ( ( mem [p + 1 ].cint / 2 ) - s > h ) 
	      h = ( mem [p + 1 ].cint / 2 ) - s ;
	      if ( ( mem [p + 1 ].cint / 2 ) + s > d ) 
	      d = ( mem [p + 1 ].cint / 2 ) + s ;
	    } 
	    else if ( ( mem [p ].hh.b0 == 0 ) && ( ( ( ( dirprimary [
	    hpackdir ]) + 2 ) % 4 ) == ( ( dirtertiary [hpackdir ]) % 4 ) ) 
	    ) 
	    {
	      x = x + mem [p + 1 ].cint ;
	      s = mem [p + 4 ].cint ;
	      if ( mem [p + 2 ].cint - s > h ) 
	      h = mem [p + 2 ].cint - s ;
	      if ( mem [p + 3 ].cint + s > d ) 
	      d = mem [p + 3 ].cint + s ;
	    } 
	    else {
		
	      x = x + mem [p + 1 ].cint ;
	      s = mem [p + 4 ].cint ;
	      if ( mem [p + 3 ].cint - s > h ) 
	      h = mem [p + 3 ].cint - s ;
	      if ( mem [p + 2 ].cint + s > d ) 
	      d = mem [p + 2 ].cint + s ;
	    } 
	  } 
	  else {
	      
	    x = x + mem [p + 1 ].cint ;
	    if ( mem [p ].hh.b0 >= 2 ) 
	    s = 0 ;
	    else s = mem [p + 4 ].cint ;
	    if ( mem [p + 3 ].cint - s > h ) 
	    h = mem [p + 3 ].cint - s ;
	    if ( mem [p + 2 ].cint + s > d ) 
	    d = mem [p + 2 ].cint + s ;
	  } 
	} 
	break ;
      case 3 : 
      case 4 : 
      case 5 : 
	if ( adjusttail != 0 ) 
	{
	  while ( mem [q ].hh .v.RH != p ) q = mem [q ].hh .v.RH ;
	  if ( mem [p ].hh.b0 == 5 ) 
	  {
	    mem [adjusttail ].hh .v.RH = mem [p + 1 ].cint ;
	    while ( mem [adjusttail ].hh .v.RH != 0 ) adjusttail = mem [
	    adjusttail ].hh .v.RH ;
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
      case 8 : 
	{
	  if ( mem [p ].hh.b1 == 7 ) 
	  {
	    {
	      if ( mem [p + 1 ].hh .v.LH >= 0 ) 
	      {
		hpackdir = mem [p + 1 ].hh .v.LH ;
		{
		  dirtmp = getnode ( 4 ) ;
		  mem [dirtmp ].hh.b0 = 8 ;
		  mem [dirtmp ].hh.b1 = 7 ;
		  mem [dirtmp + 1 ].hh .v.LH = mem [p + 1 ].hh .v.LH ;
		  mem [dirtmp + 1 ].hh .v.RH = mem [p + 1 ].hh .v.RH ;
		  mem [dirtmp + 3 ].hh .v.LH = mem [p + 3 ].hh .v.LH ;
		  mem [dirtmp + 2 ].hh .v.LH = mem [p + 2 ].hh .v.LH ;
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
		hpackdir = mem [dirptr + 1 ].hh .v.LH ;
	      } 
	    } 
	  } 
	} 
	break ;
      case 10 : 
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
      case 11 : 
      case 9 : 
	x = x + mem [p + 1 ].cint ;
	break ;
      case 6 : 
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
  if ( adjusttail != 0 ) 
  mem [adjusttail ].hh .v.RH = 0 ;
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
	
      if ( mem [r + 5 ].hh .v.RH != 0 ) 
      {
	lastbadness = badness ( x , totalstretch [0 ]) ;
	if ( lastbadness > neweqtbint ( 1049434L ) ) 
	{
	  println () ;
	  if ( lastbadness > 100 ) 
	  printnl ( 66199L ) ;
	  else printnl ( 66200L ) ;
	  print ( 66201L ) ;
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
    ].hh .v.RH != 0 ) ) 
    {
      lastbadness = 1000000L ;
      mem [r + 6 ].gr = 1.0 ;
      if ( ( - (integer) x - totalshrink [0 ]> neweqtbsc ( 1180556L + ( 8 ) 
      ) ) || ( neweqtbint ( 1049434L ) < 100 ) ) 
      {
	if ( ( neweqtbsc ( 1180556L + ( 16 ) ) > 0 ) && ( - (integer) x - 
	totalshrink [0 ]> neweqtbsc ( 1180556L + ( 8 ) ) ) ) 
	{
	  while ( mem [q ].hh .v.RH != 0 ) q = mem [q ].hh .v.RH ;
	  mem [q ].hh .v.RH = newrule () ;
	  mem [mem [q ].hh .v.RH + 4 ].hh .v.LH = mem [r + 7 ].cint ;
	  mem [mem [q ].hh .v.RH + 1 ].cint = neweqtbsc ( 1180556L + ( 16 
	  ) ) ;
	} 
	println () ;
	printnl ( 66207L ) ;
	printscaled ( - (integer) x - totalshrink [0 ]) ;
	print ( 66208L ) ;
	goto lab50 ;
      } 
    } 
    else if ( o == 0 ) {
	
      if ( mem [r + 5 ].hh .v.RH != 0 ) 
      {
	lastbadness = badness ( - (integer) x , totalshrink [0 ]) ;
	if ( lastbadness > neweqtbint ( 1049434L ) ) 
	{
	  println () ;
	  printnl ( 66209L ) ;
	  printint ( lastbadness ) ;
	  goto lab50 ;
	} 
      } 
    } 
    goto lab10 ;
  } 
  lab50: if ( outputactive ) 
  print ( 66202L ) ;
  else {
      
    if ( packbeginline != 0 ) 
    {
      if ( packbeginline > 0 ) 
      print ( 66203L ) ;
      else print ( 66204L ) ;
      printint ( abs ( packbeginline ) ) ;
      print ( 66205L ) ;
    } 
    else print ( 66206L ) ;
    printint ( line ) ;
  } 
  println () ;
  fontinshortdisplay = 0 ;
  shortdisplay ( mem [r + 5 ].hh .v.RH ) ;
  println () ;
  begindiagnostic () ;
  showbox ( r ) ;
  enddiagnostic ( true ) ;
  lab10: {
      
    while ( dirptr != 0 ) {
	
      dirtmp = dirptr ;
      dirptr = mem [dirtmp ].hh .v.RH ;
      freenode ( dirtmp , 4 ) ;
    } 
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
  r = getnode ( 8 ) ;
  mem [r ].hh.b0 = 1 ;
  if ( packdirection == -1 ) 
  mem [r + 7 ].cint = neweqtbint ( 1049480L ) ;
  else {
      
    mem [r + 7 ].cint = packdirection ;
    packdirection = -1 ;
  } 
  mem [r ].hh.b1 = 0 ;
  mem [r + 4 ].cint = 0 ;
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
  while ( p != 0 ) {
      
    if ( ( p >= himemmin ) ) 
    confusion ( 66210L ) ;
    else switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 2 : 
    case 13 : 
      {
	if ( ( mem [p ].hh.b0 == 0 ) || ( mem [p ].hh.b0 == 1 ) ) 
	{
	  if ( ( ( dirprimary [mem [p + 7 ].cint ]) % 2 ) != ( dirprimary 
	  [mem [r + 7 ].cint ]% 2 ) ) 
	  {
	    x = x + d + ( mem [p + 1 ].cint / 2 ) ;
	    d = mem [p + 1 ].cint / 2 ;
	    s = mem [p + 4 ].cint ;
	    if ( mem [p + 2 ].cint + mem [p + 3 ].cint + s > w ) 
	    w = mem [p + 2 ].cint + mem [p + 3 ].cint + s ;
	  } 
	  else if ( ( mem [p ].hh.b0 == 0 ) && ( ( ( ( dirprimary [mem [p 
	  + 7 ].cint ]) + 2 ) % 4 ) == ( ( dirtertiary [mem [p + 7 ].cint 
	  ]) % 4 ) ) ) 
	  {
	    x = x + d + mem [p + 2 ].cint ;
	    d = mem [p + 3 ].cint ;
	    s = mem [p + 4 ].cint ;
	    if ( mem [p + 1 ].cint + s > w ) 
	    w = mem [p + 1 ].cint + s ;
	  } 
	  else {
	      
	    x = x + d + mem [p + 3 ].cint ;
	    d = mem [p + 2 ].cint ;
	    s = mem [p + 4 ].cint ;
	    if ( mem [p + 1 ].cint + s > w ) 
	    w = mem [p + 1 ].cint + s ;
	  } 
	} 
	else {
	    
	  x = x + d + mem [p + 3 ].cint ;
	  d = mem [p + 2 ].cint ;
	  if ( mem [p ].hh.b0 >= 2 ) 
	  s = 0 ;
	  else s = mem [p + 4 ].cint ;
	  if ( mem [p + 1 ].cint + s > w ) 
	  w = mem [p + 1 ].cint + s ;
	} 
      } 
      break ;
    case 8 : 
      ;
      break ;
    case 10 : 
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
    case 11 : 
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
	
      if ( mem [r + 5 ].hh .v.RH != 0 ) 
      {
	lastbadness = badness ( x , totalstretch [0 ]) ;
	if ( lastbadness > neweqtbint ( 1049435L ) ) 
	{
	  println () ;
	  if ( lastbadness > 100 ) 
	  printnl ( 66199L ) ;
	  else printnl ( 66200L ) ;
	  print ( 66211L ) ;
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
    ].hh .v.RH != 0 ) ) 
    {
      lastbadness = 1000000L ;
      mem [r + 6 ].gr = 1.0 ;
      if ( ( - (integer) x - totalshrink [0 ]> neweqtbsc ( 1180556L + ( 9 ) 
      ) ) || ( neweqtbint ( 1049435L ) < 100 ) ) 
      {
	println () ;
	printnl ( 66212L ) ;
	printscaled ( - (integer) x - totalshrink [0 ]) ;
	print ( 66213L ) ;
	goto lab50 ;
      } 
    } 
    else if ( o == 0 ) {
	
      if ( mem [r + 5 ].hh .v.RH != 0 ) 
      {
	lastbadness = badness ( - (integer) x , totalshrink [0 ]) ;
	if ( lastbadness > neweqtbint ( 1049435L ) ) 
	{
	  println () ;
	  printnl ( 66214L ) ;
	  printint ( lastbadness ) ;
	  goto lab50 ;
	} 
      } 
    } 
    goto lab10 ;
  } 
  lab50: if ( outputactive ) 
  print ( 66202L ) ;
  else {
      
    if ( packbeginline != 0 ) 
    {
      print ( 66204L ) ;
      printint ( abs ( packbeginline ) ) ;
      print ( 66205L ) ;
    } 
    else print ( 66206L ) ;
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
    if ( ( mem [b ].hh.b0 == 0 ) && ( ( ( ( dirprimary [mem [b + 7 ].cint 
    ]) + 2 ) % 4 ) == ( ( dirtertiary [mem [b + 7 ].cint ]) % 4 ) ) ) 
    d = mem [newequiv ( 393231L ) + 1 ].cint - curlist .auxfield .cint - mem 
    [b + 2 ].cint ;
    else d = mem [newequiv ( 393231L ) + 1 ].cint - curlist .auxfield .cint 
    - mem [b + 3 ].cint ;
    if ( d < neweqtbsc ( 1180556L + ( 2 ) ) ) 
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
  if ( ( mem [b ].hh.b0 == 0 ) && ( ( ( ( dirprimary [mem [b + 7 ].cint ]
  ) + 2 ) % 4 ) == ( ( dirtertiary [mem [b + 7 ].cint ]) % 4 ) ) ) 
  curlist .auxfield .cint = mem [b + 3 ].cint ;
  else curlist .auxfield .cint = mem [b + 2 ].cint ;
} 
halfword 
newnoad ( void ) 
{
  register halfword Result; newnoad_regmem 
  halfword p  ;
  p = getnode ( 4 ) ;
  mem [p ].hh.b0 = 16 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].hh = emptyfield ;
  mem [p + 3 ].hh = emptyfield ;
  mem [p + 2 ].hh = emptyfield ;
  Result = p ;
  return Result ;
} 
halfword 
znewstyle ( smallnumber s ) 
{
  register halfword Result; newstyle_regmem 
  halfword p  ;
  p = getnode ( 3 ) ;
  mem [p ].hh.b0 = 14 ;
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
  mem [p ].hh.b0 = 15 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].hh .v.LH = 0 ;
  mem [p + 1 ].hh .v.RH = 0 ;
  mem [p + 2 ].hh .v.LH = 0 ;
  mem [p + 2 ].hh .v.RH = 0 ;
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
  mem [p + 4 ].hh .v.LH = neweqtbint ( 1049483L ) ;
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
  packdirection = neweqtbint ( 1049483L ) ;
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
  q = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f ][ 5 ]
  .cint + c ].qqqq ;
  hd = q .b1 ;
  b = newnullbox () ;
  mem [b + 1 ].cint = fonttables [f ][ fonttables [f ][ 36 ].cint + q .b0 
  ].cint + fonttables [f ][ fonttables [f ][ 39 ].cint + ( q .b2 ) / 256 ]
  .cint ;
  mem [b + 3 ].cint = fonttables [f ][ fonttables [f ][ 37 ].cint + ( hd 
  ) / 256 ].cint ;
  mem [b + 2 ].cint = fonttables [f ][ fonttables [f ][ 38 ].cint + ( hd 
  ) % 256 ].cint ;
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
  q = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f ][ 5 ]
  .cint + c ].qqqq ;
  hd = q .b1 ;
  Result = fonttables [f ][ fonttables [f ][ 37 ].cint + ( hd ) / 256 ]
  .cint + fonttables [f ][ fonttables [f ][ 38 ].cint + ( hd ) % 256 ]
  .cint ;
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
	g = newequiv ( 720960L + z ) ;
	if ( g != 0 ) 
	{
	  y = x ;
	  if ( ( y >= fonttables [g ][ 12 ].cint ) && ( y <= fonttables [g 
	  ][ 13 ].cint ) ) 
	  {
	    lab22: q = fonttables [g ][ fonttables [g ][ 34 ].cint - 
	    fonttables [g ][ 5 ].cint + y ].qqqq ;
	    if ( ( q .b0 > 0 ) ) 
	    {
	      if ( ( ( q .b2 ) % 4 ) == 3 ) 
	      {
		f = g ;
		c = y ;
		goto lab40 ;
	      } 
	      hd = q .b1 ;
	      u = fonttables [g ][ fonttables [g ][ 37 ].cint + ( hd ) / 
	      256 ].cint + fonttables [g ][ fonttables [g ][ 38 ].cint + ( 
	      hd ) % 256 ].cint ;
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
      r = fonttables [f ][ fonttables [f ][ 42 ].cint + q .b3 ].qqqq ;
      c = fonttables [f ][ 5 ].cint + r .b3 ;
      u = heightplusdepth ( f , c ) ;
      w = 0 ;
      q = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f ][ 5 
      ].cint + c ].qqqq ;
      mem [b + 1 ].cint = fonttables [f ][ fonttables [f ][ 36 ].cint + q 
      .b0 ].cint + fonttables [f ][ fonttables [f ][ 39 ].cint + ( q .b2 ) 
      / 256 ].cint ;
      c = fonttables [f ][ 5 ].cint + r .b2 ;
      if ( c != 0 ) 
      w = w + heightplusdepth ( f , c ) ;
      c = fonttables [f ][ 5 ].cint + r .b1 ;
      if ( c != 0 ) 
      w = w + heightplusdepth ( f , c ) ;
      c = fonttables [f ][ 5 ].cint + r .b0 ;
      if ( c != 0 ) 
      w = w + heightplusdepth ( f , c ) ;
      n = 0 ;
      if ( u > 0 ) 
      while ( w < v ) {
	  
	w = w + u ;
	incr ( n ) ;
	if ( ( fonttables [f ][ 5 ].cint + r .b1 ) != 0 ) 
	w = w + u ;
      } 
      c = fonttables [f ][ 5 ].cint + r .b2 ;
      if ( c != 0 ) 
      stackintobox ( b , f , c ) ;
      c = fonttables [f ][ 5 ].cint + r .b3 ;
      {register integer for_end; m = 1 ;for_end = n ; if ( m <= for_end) do 
	stackintobox ( b , f , c ) ;
      while ( m++ < for_end ) ;} 
      c = fonttables [f ][ 5 ].cint + r .b1 ;
      if ( c != 0 ) 
      {
	stackintobox ( b , f , c ) ;
	c = fonttables [f ][ 5 ].cint + r .b3 ;
	{register integer for_end; m = 1 ;for_end = n ; if ( m <= for_end) 
	do 
	  stackintobox ( b , f , c ) ;
	while ( m++ < for_end ) ;} 
      } 
      c = fonttables [f ][ 5 ].cint + r .b0 ;
      if ( c != 0 ) 
      stackintobox ( b , f , c ) ;
      mem [b + 2 ].cint = w - mem [b + 3 ].cint ;
    } 
    else b = charbox ( f , c ) ;
  } 
  else {
      
    b = newnullbox () ;
    mem [b + 1 ].cint = neweqtbsc ( 1180556L + ( 11 ) ) ;
  } 
  z = cursize ;
  cursize = s ;
  mem [b + 4 ].cint = half ( mem [b + 3 ].cint - mem [b + 2 ].cint ) - 
  fonttables [newequiv ( 720962L + cursize ) ][ 22 + fonttables [newequiv ( 
  720962L + cursize ) ][ 43 ].cint ].cint ;
  cursize = z ;
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
  if ( ( mem [b + 1 ].cint != w ) && ( mem [b + 5 ].hh .v.RH != 0 ) ) 
  {
    if ( mem [b ].hh.b0 == 1 ) 
    b = hpack ( b , 0 , 1 ) ;
    p = mem [b + 5 ].hh .v.RH ;
    if ( ( ( p >= himemmin ) ) && ( mem [p ].hh .v.RH == 0 ) ) 
    {
      f = mem [p ].hh.b0 ;
      v = fonttables [f ][ fonttables [f ][ 36 ].cint + fonttables [f ][ 
      fonttables [f ][ 34 ].cint - fonttables [f ][ 5 ].cint + mem [p ]
      .hh.b1 ].qqqq .b0 ].cint ;
      if ( v != mem [b + 1 ].cint ) 
      mem [p ].hh .v.RH = newkern ( mem [b + 1 ].cint - v ) ;
    } 
    freenode ( b , 8 ) ;
    b = newglue ( membot + 16 ) ;
    mem [b ].hh .v.RH = p ;
    while ( mem [p ].hh .v.RH != 0 ) p = mem [p ].hh .v.RH ;
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
  mem [curlist .headfield ].hh .v.RH = 0 ;
  curlist .tailfield = curlist .headfield ;
  curlist .auxfield .cint = 0 ;
} 
halfword 
zcleanbox ( halfword p , integer s ) 
{
  /* 40 */ register halfword Result; cleanbox_regmem 
  halfword q  ;
  integer savestyle  ;
  halfword x  ;
  halfword r  ;
  switch ( mem [p ].hh .v.RH ) 
  {case 1 : 
    {
      curmlist = newnoad () ;
      mem [curmlist + 1 ]= mem [p ];
    } 
    break ;
  case 2 : 
    {
      q = mem [p ].hh .v.LH ;
      goto lab40 ;
    } 
    break ;
  case 3 : 
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
    curmu = xovern ( fonttables [newequiv ( 720962L + cursize ) ][ 6 + 
    fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint , 18 ) ;
  } 
  lab40: if ( ( q >= himemmin ) || ( q == 0 ) ) 
  x = hpack ( q , 0 , 1 ) ;
  else if ( ( mem [q ].hh .v.RH == 0 ) && ( mem [q ].hh.b0 <= 1 ) && ( mem 
  [q + 4 ].cint == 0 ) ) 
  x = q ;
  else x = hpack ( q , 0 , 1 ) ;
  q = mem [x + 5 ].hh .v.RH ;
  if ( ( q >= himemmin ) ) 
  {
    r = mem [q ].hh .v.RH ;
    if ( r != 0 ) {
	
      if ( mem [r ].hh .v.RH == 0 ) {
	  
	if ( ! ( r >= himemmin ) ) {
	    
	  if ( mem [r ].hh.b0 == 11 ) 
	  {
	    freenode ( r , 2 ) ;
	    mem [q ].hh .v.RH = 0 ;
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
  curf = newequiv ( 720960L + mem [a ].hh.b0 + cursize ) ;
  if ( curf == 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 65624L ) ;
    } 
    printsize ( cursize ) ;
    printchar ( 32 ) ;
    printint ( mem [a ].hh.b0 ) ;
    print ( 66240L ) ;
    print ( curc ) ;
    printchar ( 41 ) ;
    {
      helpptr = 4 ;
      helpline [3 ]= 66241L ;
      helpline [2 ]= 66242L ;
      helpline [1 ]= 66243L ;
      helpline [0 ]= 66244L ;
    } 
    error () ;
    curi = nullcharacter ;
    mem [a ].hh .v.RH = 0 ;
  } 
  else {
      
    if ( ( curc >= fonttables [curf ][ 12 ].cint ) && ( curc <= fonttables [
    curf ][ 13 ].cint ) ) 
    curi = fonttables [curf ][ fonttables [curf ][ 34 ].cint - fonttables [
    curf ][ 5 ].cint + curc ].qqqq ;
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
  + 1 ) , 3 * fonttables [newequiv ( 720963L + cursize ) ][ 8 + fonttables [
  newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint , fonttables [newequiv 
  ( 720963L + cursize ) ][ 8 + fonttables [newequiv ( 720963L + cursize ) ][ 
  43 ].cint ].cint ) ;
  mem [q + 1 ].hh .v.RH = 2 ;
} 
void 
zmakeunder ( halfword q ) 
{
  makeunder_regmem 
  halfword p, x, y  ;
  scaled delta  ;
  x = cleanbox ( q + 1 , curstyle ) ;
  p = newkern ( 3 * fonttables [newequiv ( 720963L + cursize ) ][ 8 + 
  fonttables [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ) ;
  mem [x ].hh .v.RH = p ;
  mem [p ].hh .v.RH = fractionrule ( fonttables [newequiv ( 720963L + 
  cursize ) ][ 8 + fonttables [newequiv ( 720963L + cursize ) ][ 43 ].cint ]
  .cint ) ;
  packdirection = neweqtbint ( 1049483L ) ;
  y = vpackage ( x , 0 , 1 , 1073741823L ) ;
  delta = mem [y + 3 ].cint + mem [y + 2 ].cint + fonttables [newequiv ( 
  720963L + cursize ) ][ 8 + fonttables [newequiv ( 720963L + cursize ) ][ 43 
  ].cint ].cint ;
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
  if ( mem [v ].hh.b0 != 1 ) 
  confusion ( 65840L ) ;
  delta = mem [v + 3 ].cint + mem [v + 2 ].cint ;
  mem [v + 3 ].cint = fonttables [newequiv ( 720962L + cursize ) ][ 22 + 
  fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint + half ( 
  delta ) ;
  mem [v + 2 ].cint = delta - mem [v + 3 ].cint ;
} 
void 
zmakeradical ( halfword q ) 
{
  makeradical_regmem 
  halfword x, y  ;
  scaled delta, clr  ;
  x = cleanbox ( q + 1 , 2 * ( curstyle / 2 ) + 1 ) ;
  if ( curstyle < 2 ) 
  clr = fonttables [newequiv ( 720963L + cursize ) ][ 8 + fonttables [
  newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint + ( abs ( fonttables [
  newequiv ( 720962L + cursize ) ][ 5 + fonttables [newequiv ( 720962L + 
  cursize ) ][ 43 ].cint ].cint ) / 4 ) ;
  else {
      
    clr = fonttables [newequiv ( 720963L + cursize ) ][ 8 + fonttables [
    newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ;
    clr = clr + ( abs ( clr ) / 4 ) ;
  } 
  y = vardelimiter ( q + 4 , cursize , mem [x + 3 ].cint + mem [x + 2 ]
  .cint + clr + fonttables [newequiv ( 720963L + cursize ) ][ 8 + fonttables 
  [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ) ;
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
  fetch ( q + 4 ) ;
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
	a = fonttables [curf ][ 40 ].cint + curi .b3 ;
	curi = fonttables [curf ][ a ].qqqq ;
	if ( ( curi .b0 % 256 ) > 128 ) 
	{
	  a = fonttables [curf ][ 40 ].cint + 256 * curi .b2 + curi .b3 + 
	  32768L - 256 * ( 128 ) ;
	  curi = fonttables [curf ][ a ].qqqq ;
	} 
	while ( true ) {
	    
	  if ( ( fonttables [curf ][ 5 ].cint + curi .b1 ) == fonttables [
	  curf ][ 17 ].cint ) 
	  {
	    if ( curi .b2 >= 128 ) {
		
	      if ( ( curi .b0 % 256 ) <= 128 ) 
	      s = fonttables [curf ][ fonttables [curf ][ 41 ].cint + 256 * 
	      curi .b2 + curi .b3 ].cint ;
	    } 
	    goto lab31 ;
	  } 
	  if ( ( curi .b0 % 256 ) >= 128 ) 
	  goto lab31 ;
	  a = a + ( curi .b0 % 256 ) + 1 ;
	  curi = fonttables [curf ][ a ].qqqq ;
	} 
      } 
    } 
    lab31: ;
    x = cleanbox ( q + 1 , 2 * ( curstyle / 2 ) + 1 ) ;
    w = mem [x + 1 ].cint ;
    h = mem [x + 3 ].cint ;
    while ( true ) {
	
      if ( ( ( i .b2 ) % 4 ) != 2 ) 
      goto lab30 ;
      y = i .b3 ;
      i = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f ][ 5 
      ].cint + y ].qqqq ;
      if ( ! ( i .b0 > 0 ) ) 
      goto lab30 ;
      if ( fonttables [f ][ fonttables [f ][ 36 ].cint + i .b0 ].cint > w 
      ) 
      goto lab30 ;
      c = y ;
    } 
    lab30: ;
    if ( h < fonttables [f ][ fonttables [f ][ 43 ].cint + 5 ].cint ) 
    delta = h ;
    else delta = fonttables [f ][ fonttables [f ][ 43 ].cint + 5 ].cint ;
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
	mem [q + 1 ].hh .v.RH = 3 ;
	mem [q + 1 ].hh .v.LH = x ;
	x = cleanbox ( q + 1 , curstyle ) ;
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
    packdirection = neweqtbint ( 1049483L ) ;
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
  mem [q + 1 ].cint = fonttables [newequiv ( 720963L + cursize ) ][ 8 + 
  fonttables [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ;
  x = cleanbox ( q + 2 , curstyle + 2 - 2 * ( curstyle / 6 ) ) ;
  z = cleanbox ( q + 3 , 2 * ( curstyle / 2 ) + 3 - 2 * ( curstyle / 6 ) ) ;
  if ( mem [x + 1 ].cint < mem [z + 1 ].cint ) 
  x = rebox ( x , mem [z + 1 ].cint ) ;
  else z = rebox ( z , mem [x + 1 ].cint ) ;
  if ( curstyle < 2 ) 
  {
    shiftup = fonttables [newequiv ( 720962L + cursize ) ][ 8 + fonttables [
    newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
    shiftdown = fonttables [newequiv ( 720962L + cursize ) ][ 11 + fonttables 
    [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
  } 
  else {
      
    shiftdown = fonttables [newequiv ( 720962L + cursize ) ][ 12 + fonttables 
    [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
    if ( mem [q + 1 ].cint != 0 ) 
    shiftup = fonttables [newequiv ( 720962L + cursize ) ][ 9 + fonttables [
    newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
    else shiftup = fonttables [newequiv ( 720962L + cursize ) ][ 10 + 
    fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
  } 
  if ( mem [q + 1 ].cint == 0 ) 
  {
    if ( curstyle < 2 ) 
    clr = 7 * fonttables [newequiv ( 720963L + cursize ) ][ 8 + fonttables [
    newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ;
    else clr = 3 * fonttables [newequiv ( 720963L + cursize ) ][ 8 + 
    fonttables [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ;
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
    delta1 = clr - ( ( shiftup - mem [x + 2 ].cint ) - ( fonttables [
    newequiv ( 720962L + cursize ) ][ 22 + fonttables [newequiv ( 720962L + 
    cursize ) ][ 43 ].cint ].cint + delta ) ) ;
    delta2 = clr - ( ( fonttables [newequiv ( 720962L + cursize ) ][ 22 + 
    fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint - delta 
    ) - ( mem [z + 3 ].cint - shiftdown ) ) ;
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
    p = newkern ( ( fonttables [newequiv ( 720962L + cursize ) ][ 22 + 
    fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint - delta 
    ) - ( mem [z + 3 ].cint - shiftdown ) ) ;
    mem [y ].hh .v.RH = p ;
    mem [p ].hh .v.RH = z ;
    p = newkern ( ( shiftup - mem [x + 2 ].cint ) - ( fonttables [newequiv 
    ( 720962L + cursize ) ][ 22 + fonttables [newequiv ( 720962L + cursize ) 
    ][ 43 ].cint ].cint + delta ) ) ;
    mem [p ].hh .v.RH = y ;
  } 
  mem [x ].hh .v.RH = p ;
  mem [v + 5 ].hh .v.RH = x ;
  if ( curstyle < 2 ) 
  delta = fonttables [newequiv ( 720962L + cursize ) ][ 20 + fonttables [
  newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
  else delta = fonttables [newequiv ( 720962L + cursize ) ][ 21 + fonttables 
  [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
  x = vardelimiter ( q + 4 , cursize , delta ) ;
  mem [x ].hh .v.RH = v ;
  z = vardelimiter ( q + 5 , cursize , delta ) ;
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
      i = fonttables [curf ][ fonttables [curf ][ 34 ].cint - fonttables [
      curf ][ 5 ].cint + c ].qqqq ;
      if ( ( i .b0 > 0 ) ) 
      {
	curc = c ;
	curi = i ;
	mem [q + 1 ].hh.b1 = c ;
      } 
    } 
    delta = fonttables [curf ][ fonttables [curf ][ 39 ].cint + ( curi .b2 
    ) / 256 ].cint ;
    x = cleanbox ( q + 1 , curstyle ) ;
    if ( ( mem [q + 3 ].hh .v.RH != 0 ) && ( mem [q ].hh.b1 != 1 ) ) 
    mem [x + 1 ].cint = mem [x + 1 ].cint - delta ;
    mem [x + 4 ].cint = half ( mem [x + 3 ].cint - mem [x + 2 ].cint ) - 
    fonttables [newequiv ( 720962L + cursize ) ][ 22 + fonttables [newequiv 
    ( 720962L + cursize ) ][ 43 ].cint ].cint ;
    mem [q + 1 ].hh .v.RH = 2 ;
    mem [q + 1 ].hh .v.LH = x ;
  } 
  else delta = 0 ;
  if ( mem [q ].hh.b1 == 1 ) 
  {
    x = cleanbox ( q + 2 , 2 * ( curstyle / 4 ) + 4 + ( curstyle % 2 ) ) ;
    y = cleanbox ( q + 1 , curstyle ) ;
    z = cleanbox ( q + 3 , 2 * ( curstyle / 4 ) + 5 ) ;
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
      freenode ( x , 8 ) ;
      mem [v + 5 ].hh .v.RH = y ;
    } 
    else {
	
      shiftup = fonttables [newequiv ( 720963L + cursize ) ][ 11 + fonttables 
      [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint - mem [x + 2 ]
      .cint ;
      if ( shiftup < fonttables [newequiv ( 720963L + cursize ) ][ 9 + 
      fonttables [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ) 
      shiftup = fonttables [newequiv ( 720963L + cursize ) ][ 9 + fonttables 
      [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ;
      p = newkern ( shiftup ) ;
      mem [p ].hh .v.RH = y ;
      mem [x ].hh .v.RH = p ;
      p = newkern ( fonttables [newequiv ( 720963L + cursize ) ][ 13 + 
      fonttables [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ) ;
      mem [p ].hh .v.RH = x ;
      mem [v + 5 ].hh .v.RH = p ;
      mem [v + 3 ].cint = mem [v + 3 ].cint + fonttables [newequiv ( 
      720963L + cursize ) ][ 13 + fonttables [newequiv ( 720963L + cursize ) 
      ][ 43 ].cint ].cint + mem [x + 3 ].cint + mem [x + 2 ].cint + 
      shiftup ;
    } 
    if ( mem [q + 3 ].hh .v.RH == 0 ) 
    freenode ( z , 8 ) ;
    else {
	
      shiftdown = fonttables [newequiv ( 720963L + cursize ) ][ 12 + 
      fonttables [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint - mem 
      [z + 3 ].cint ;
      if ( shiftdown < fonttables [newequiv ( 720963L + cursize ) ][ 10 + 
      fonttables [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ) 
      shiftdown = fonttables [newequiv ( 720963L + cursize ) ][ 10 + 
      fonttables [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ;
      p = newkern ( shiftdown ) ;
      mem [y ].hh .v.RH = p ;
      mem [p ].hh .v.RH = z ;
      p = newkern ( fonttables [newequiv ( 720963L + cursize ) ][ 13 + 
      fonttables [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint ) ;
      mem [z ].hh .v.RH = p ;
      mem [v + 2 ].cint = mem [v + 2 ].cint + fonttables [newequiv ( 
      720963L + cursize ) ][ 13 + fonttables [newequiv ( 720963L + cursize ) 
      ][ 43 ].cint ].cint + mem [z + 3 ].cint + mem [z + 2 ].cint + 
      shiftdown ;
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
  halfword p, r  ;
  lab20: if ( mem [q + 3 ].hh .v.RH == 0 ) {
      
    if ( mem [q + 2 ].hh .v.RH == 0 ) {
	
      if ( mem [q + 1 ].hh .v.RH == 1 ) 
      {
	p = mem [q ].hh .v.RH ;
	if ( p != 0 ) {
	    
	  if ( ( mem [p ].hh.b0 >= 16 ) && ( mem [p ].hh.b0 <= 22 ) ) {
	      
	    if ( mem [p + 1 ].hh .v.RH == 1 ) {
		
	      if ( mem [p + 1 ].hh.b0 == mem [q + 1 ].hh.b0 ) 
	      {
		mem [q + 1 ].hh .v.RH = 4 ;
		fetch ( q + 1 ) ;
		if ( ( ( curi .b2 ) % 4 ) == 1 ) 
		{
		  a = fonttables [curf ][ 40 ].cint + curi .b3 ;
		  curc = mem [p + 1 ].hh.b1 ;
		  curi = fonttables [curf ][ a ].qqqq ;
		  if ( ( curi .b0 % 256 ) > 128 ) 
		  {
		    a = fonttables [curf ][ 40 ].cint + 256 * curi .b2 + 
		    curi .b3 + 32768L - 256 * ( 128 ) ;
		    curi = fonttables [curf ][ a ].qqqq ;
		  } 
		  while ( true ) {
		      
		    if ( ( fonttables [curf ][ 5 ].cint + curi .b1 ) == curc 
		    ) {
			
		      if ( ( curi .b0 % 256 ) <= 128 ) {
			  
			if ( curi .b2 >= 128 ) 
			{
			  p = newkern ( fonttables [curf ][ fonttables [curf 
			  ][ 41 ].cint + 256 * curi .b2 + curi .b3 ].cint ) 
			  ;
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
			      else mem [r + 1 ].hh .v.RH = 4 ;
			    } 
			    break ;
			    default: 
			    {
			      mem [q ].hh .v.RH = mem [p ].hh .v.RH ;
			      mem [q + 1 ].hh.b1 = curi .b3 ;
			      mem [q + 3 ]= mem [p + 3 ];
			      mem [q + 2 ]= mem [p + 2 ];
			      freenode ( p , 4 ) ;
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
		    if ( ( curi .b0 % 256 ) >= 128 ) 
		    return ;
		    a = a + ( curi .b0 % 256 ) + 1 ;
		    curi = fonttables [curf ][ a ].qqqq ;
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
    t = cursize ;
    if ( curstyle < 4 ) 
    cursize = 256 ;
    else cursize = 512 ;
    shiftup = mem [z + 3 ].cint - fonttables [newequiv ( 720962L + cursize 
    ) ][ 18 + fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ]
    .cint ;
    shiftdown = mem [z + 2 ].cint + fonttables [newequiv ( 720962L + 
    cursize ) ][ 19 + fonttables [newequiv ( 720962L + cursize ) ][ 43 ]
    .cint ].cint ;
    cursize = t ;
    freenode ( z , 8 ) ;
  } 
  if ( mem [q + 2 ].hh .v.RH == 0 ) 
  {
    x = cleanbox ( q + 3 , 2 * ( curstyle / 4 ) + 5 ) ;
    mem [x + 1 ].cint = mem [x + 1 ].cint + neweqtbsc ( 1180556L + ( 12 ) 
    ) ;
    if ( shiftdown < fonttables [newequiv ( 720962L + cursize ) ][ 16 + 
    fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ) 
    shiftdown = fonttables [newequiv ( 720962L + cursize ) ][ 16 + fonttables 
    [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
    clr = mem [x + 3 ].cint - ( abs ( fonttables [newequiv ( 720962L + 
    cursize ) ][ 5 + fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint 
    ].cint * 4 ) / 5 ) ;
    if ( shiftdown < clr ) 
    shiftdown = clr ;
    mem [x + 4 ].cint = shiftdown ;
  } 
  else {
      
    {
      x = cleanbox ( q + 2 , 2 * ( curstyle / 4 ) + 4 + ( curstyle % 2 ) ) ;
      mem [x + 1 ].cint = mem [x + 1 ].cint + neweqtbsc ( 1180556L + ( 12 
      ) ) ;
      if ( odd ( curstyle ) ) 
      clr = fonttables [newequiv ( 720962L + cursize ) ][ 15 + fonttables [
      newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
      else if ( curstyle < 2 ) 
      clr = fonttables [newequiv ( 720962L + cursize ) ][ 13 + fonttables [
      newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
      else clr = fonttables [newequiv ( 720962L + cursize ) ][ 14 + 
      fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
      if ( shiftup < clr ) 
      shiftup = clr ;
      clr = mem [x + 2 ].cint + ( abs ( fonttables [newequiv ( 720962L + 
      cursize ) ][ 5 + fonttables [newequiv ( 720962L + cursize ) ][ 43 ]
      .cint ].cint ) / 4 ) ;
      if ( shiftup < clr ) 
      shiftup = clr ;
    } 
    if ( mem [q + 3 ].hh .v.RH == 0 ) 
    mem [x + 4 ].cint = - (integer) shiftup ;
    else {
	
      y = cleanbox ( q + 3 , 2 * ( curstyle / 4 ) + 5 ) ;
      mem [y + 1 ].cint = mem [y + 1 ].cint + neweqtbsc ( 1180556L + ( 12 
      ) ) ;
      if ( shiftdown < fonttables [newequiv ( 720962L + cursize ) ][ 17 + 
      fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ) 
      shiftdown = fonttables [newequiv ( 720962L + cursize ) ][ 17 + 
      fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
      clr = 4 * fonttables [newequiv ( 720963L + cursize ) ][ 8 + fonttables 
      [newequiv ( 720963L + cursize ) ][ 43 ].cint ].cint - ( ( shiftup - 
      mem [x + 2 ].cint ) - ( mem [y + 3 ].cint - shiftdown ) ) ;
      if ( clr > 0 ) 
      {
	shiftdown = shiftdown + clr ;
	clr = ( abs ( fonttables [newequiv ( 720962L + cursize ) ][ 5 + 
	fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint * 4 
	) / 5 ) - ( shiftup - mem [x + 2 ].cint ) ;
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
      packdirection = neweqtbint ( 1049483L ) ;
      x = vpackage ( x , 0 , 1 , 1073741823L ) ;
      mem [x + 4 ].cint = shiftdown ;
    } 
  } 
  if ( mem [q + 1 ].cint == 0 ) 
  mem [q + 1 ].cint = x ;
  else {
      
    p = mem [q + 1 ].cint ;
    while ( mem [p ].hh .v.RH != 0 ) p = mem [p ].hh .v.RH ;
    mem [p ].hh .v.RH = x ;
  } 
} 
integer 
zmakeleftright ( halfword q , integer style , scaled maxd , scaled maxh ) 
{
  register integer Result; makeleftright_regmem 
  scaled delta, delta1, delta2  ;
  curstyle = style ;
  {
    if ( curstyle < 4 ) 
    cursize = 0 ;
    else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
    curmu = xovern ( fonttables [newequiv ( 720962L + cursize ) ][ 6 + 
    fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint , 18 ) ;
  } 
  delta2 = maxd + fonttables [newequiv ( 720962L + cursize ) ][ 22 + 
  fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
  delta1 = maxh + maxd - delta2 ;
  if ( delta2 > delta1 ) 
  delta1 = delta2 ;
  delta = ( delta1 / 500 ) * neweqtbint ( 1049426L ) ;
  delta2 = delta1 + delta1 - neweqtbsc ( 1180556L + ( 10 ) ) ;
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
  integer style  ;
  integer savestyle  ;
  halfword q  ;
  halfword r  ;
  integer rtype  ;
  integer t  ;
  halfword p, x, y, z  ;
  integer pen  ;
  integer s  ;
  scaled maxh, maxd  ;
  scaled delta  ;
  mlist = curmlist ;
  penalties = mlistpenalties ;
  style = curstyle ;
  q = mlist ;
  r = 0 ;
  rtype = 17 ;
  maxh = 0 ;
  maxd = 0 ;
  {
    if ( curstyle < 4 ) 
    cursize = 0 ;
    else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
    curmu = xovern ( fonttables [newequiv ( 720962L + cursize ) ][ 6 + 
    fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint , 18 ) ;
  } 
  while ( q != 0 ) {
      
    lab21: delta = 0 ;
    switch ( mem [q ].hh.b0 ) 
    {case 18 : 
      switch ( rtype ) 
      {case 18 : 
      case 17 : 
      case 19 : 
      case 20 : 
      case 22 : 
      case 30 : 
	{
	  mem [q ].hh.b0 = 16 ;
	  goto lab21 ;
	} 
	break ;
	default: 
	;
	break ;
      } 
      break ;
    case 19 : 
    case 21 : 
    case 22 : 
    case 31 : 
      {
	if ( rtype == 18 ) 
	mem [r ].hh.b0 = 16 ;
	if ( mem [q ].hh.b0 == 31 ) 
	goto lab80 ;
      } 
      break ;
    case 30 : 
      goto lab80 ;
      break ;
    case 25 : 
      {
	makefraction ( q ) ;
	goto lab82 ;
      } 
      break ;
    case 17 : 
      {
	delta = makeop ( q ) ;
	if ( mem [q ].hh.b1 == 1 ) 
	goto lab82 ;
      } 
      break ;
    case 16 : 
      makeord ( q ) ;
      break ;
    case 20 : 
    case 23 : 
      ;
      break ;
    case 24 : 
      makeradical ( q ) ;
      break ;
    case 27 : 
      makeover ( q ) ;
      break ;
    case 26 : 
      makeunder ( q ) ;
      break ;
    case 28 : 
      makemathaccent ( q ) ;
      break ;
    case 29 : 
      makevcenter ( q ) ;
      break ;
    case 14 : 
      {
	curstyle = mem [q ].hh.b1 ;
	{
	  if ( curstyle < 4 ) 
	  cursize = 0 ;
	  else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
	  curmu = xovern ( fonttables [newequiv ( 720962L + cursize ) ][ 6 + 
	  fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint , 
	  18 ) ;
	} 
	goto lab81 ;
      } 
      break ;
    case 15 : 
      {
	switch ( curstyle / 2 ) 
	{case 0 : 
	  {
	    p = mem [q + 1 ].hh .v.LH ;
	    mem [q + 1 ].hh .v.LH = 0 ;
	  } 
	  break ;
	case 1 : 
	  {
	    p = mem [q + 1 ].hh .v.RH ;
	    mem [q + 1 ].hh .v.RH = 0 ;
	  } 
	  break ;
	case 2 : 
	  {
	    p = mem [q + 2 ].hh .v.LH ;
	    mem [q + 2 ].hh .v.LH = 0 ;
	  } 
	  break ;
	case 3 : 
	  {
	    p = mem [q + 2 ].hh .v.RH ;
	    mem [q + 2 ].hh .v.RH = 0 ;
	  } 
	  break ;
	} 
	flushnodelist ( mem [q + 1 ].hh .v.LH ) ;
	flushnodelist ( mem [q + 1 ].hh .v.RH ) ;
	flushnodelist ( mem [q + 2 ].hh .v.LH ) ;
	flushnodelist ( mem [q + 2 ].hh .v.RH ) ;
	mem [q ].hh.b0 = 14 ;
	mem [q ].hh.b1 = curstyle ;
	mem [q + 1 ].cint = 0 ;
	mem [q + 2 ].cint = 0 ;
	if ( p != 0 ) 
	{
	  z = mem [q ].hh .v.RH ;
	  mem [q ].hh .v.RH = p ;
	  while ( mem [p ].hh .v.RH != 0 ) p = mem [p ].hh .v.RH ;
	  mem [p ].hh .v.RH = z ;
	} 
	goto lab81 ;
      } 
      break ;
    case 3 : 
    case 4 : 
    case 5 : 
    case 8 : 
    case 12 : 
    case 7 : 
      goto lab81 ;
      break ;
    case 2 : 
      {
	if ( mem [q + 3 ].cint > maxh ) 
	maxh = mem [q + 3 ].cint ;
	if ( mem [q + 2 ].cint > maxd ) 
	maxd = mem [q + 2 ].cint ;
	goto lab81 ;
      } 
      break ;
    case 10 : 
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
	  if ( p != 0 ) {
	      
	    if ( ( mem [p ].hh.b0 == 10 ) || ( mem [p ].hh.b0 == 11 ) ) 
	    {
	      mem [q ].hh .v.RH = mem [p ].hh .v.RH ;
	      mem [p ].hh .v.RH = 0 ;
	      flushnodelist ( p ) ;
	    } 
	  } 
	} 
	goto lab81 ;
      } 
      break ;
    case 11 : 
      {
	mathkern ( q , curmu ) ;
	goto lab81 ;
      } 
      break ;
      default: 
      confusion ( 66245L ) ;
      break ;
    } 
    switch ( mem [q + 1 ].hh .v.RH ) 
    {case 1 : 
    case 4 : 
      {
	fetch ( q + 1 ) ;
	if ( ( curi .b0 > 0 ) ) 
	{
	  delta = fonttables [curf ][ fonttables [curf ][ 39 ].cint + ( 
	  curi .b2 ) / 256 ].cint ;
	  p = newcharacter ( curf , curc ) ;
	  if ( ( mem [q + 1 ].hh .v.RH == 4 ) && ( fonttables [curf ][ 
	  fonttables [curf ][ 43 ].cint + 2 ].cint != 0 ) ) 
	  delta = 0 ;
	  if ( ( mem [q + 3 ].hh .v.RH == 0 ) && ( delta != 0 ) ) 
	  {
	    mem [p ].hh .v.RH = newkern ( delta ) ;
	    delta = 0 ;
	  } 
	} 
	else p = 0 ;
      } 
      break ;
    case 0 : 
      p = 0 ;
      break ;
    case 2 : 
      p = mem [q + 1 ].hh .v.LH ;
      break ;
    case 3 : 
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
	  curmu = xovern ( fonttables [newequiv ( 720962L + cursize ) ][ 6 + 
	  fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint , 
	  18 ) ;
	} 
	p = hpack ( mem [memtop - 3 ].hh .v.RH , 0 , 1 ) ;
      } 
      break ;
      default: 
      confusion ( 66246L ) ;
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
    freenode ( z , 8 ) ;
    lab80: r = q ;
    rtype = mem [r ].hh.b0 ;
    if ( rtype == 31 ) 
    {
      rtype = 30 ;
      curstyle = style ;
      {
	if ( curstyle < 4 ) 
	cursize = 0 ;
	else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
	curmu = xovern ( fonttables [newequiv ( 720962L + cursize ) ][ 6 + 
	fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint , 18 
	) ;
      } 
    } 
    lab81: q = mem [q ].hh .v.RH ;
  } 
  if ( rtype == 18 ) 
  mem [r ].hh.b0 = 16 ;
  p = memtop - 3 ;
  mem [p ].hh .v.RH = 0 ;
  q = mlist ;
  rtype = 0 ;
  curstyle = style ;
  {
    if ( curstyle < 4 ) 
    cursize = 0 ;
    else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
    curmu = xovern ( fonttables [newequiv ( 720962L + cursize ) ][ 6 + 
    fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint , 18 ) ;
  } 
  while ( q != 0 ) {
      
    t = 16 ;
    s = 4 ;
    pen = 10000 ;
    switch ( mem [q ].hh.b0 ) 
    {case 17 : 
    case 20 : 
    case 21 : 
    case 22 : 
    case 23 : 
      t = mem [q ].hh.b0 ;
      break ;
    case 18 : 
      {
	t = 18 ;
	pen = neweqtbint ( 1049417L ) ;
      } 
      break ;
    case 19 : 
      {
	t = 19 ;
	pen = neweqtbint ( 1049418L ) ;
      } 
      break ;
    case 16 : 
    case 29 : 
    case 27 : 
    case 26 : 
      ;
      break ;
    case 24 : 
      s = 5 ;
      break ;
    case 28 : 
      s = 5 ;
      break ;
    case 25 : 
      {
	t = 23 ;
	s = 6 ;
      } 
      break ;
    case 30 : 
    case 31 : 
      t = makeleftright ( q , style , maxd , maxh ) ;
      break ;
    case 14 : 
      {
	curstyle = mem [q ].hh.b1 ;
	s = 3 ;
	{
	  if ( curstyle < 4 ) 
	  cursize = 0 ;
	  else cursize = 256 * ( ( curstyle - 2 ) / 2 ) ;
	  curmu = xovern ( fonttables [newequiv ( 720962L + cursize ) ][ 6 + 
	  fonttables [newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint , 
	  18 ) ;
	} 
	goto lab83 ;
      } 
      break ;
    case 8 : 
    case 12 : 
    case 2 : 
    case 7 : 
    case 5 : 
    case 3 : 
    case 4 : 
    case 10 : 
    case 11 : 
      {
	mem [p ].hh .v.RH = q ;
	p = q ;
	q = mem [q ].hh .v.RH ;
	mem [p ].hh .v.RH = 0 ;
	goto lab30 ;
      } 
      break ;
      default: 
      confusion ( 66247L ) ;
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
	x = 15 ;
	else x = 0 ;
	break ;
      case 50 : 
	x = 15 ;
	break ;
      case 51 : 
	if ( curstyle < 4 ) 
	x = 16 ;
	else x = 0 ;
	break ;
      case 52 : 
	if ( curstyle < 4 ) 
	x = 17 ;
	else x = 0 ;
	break ;
	default: 
	confusion ( 66249L ) ;
	break ;
      } 
      if ( x != 0 ) 
      {
	y = mathglue ( newequiv ( 393230L + x ) , curmu ) ;
	z = newglue ( y ) ;
	mem [y ].hh .v.RH = 0 ;
	mem [p ].hh .v.RH = z ;
	p = z ;
	mem [z ].hh.b1 = x + 1 ;
      } 
    } 
    if ( mem [q + 1 ].cint != 0 ) 
    {
      mem [p ].hh .v.RH = mem [q + 1 ].cint ;
      do {
	  p = mem [p ].hh .v.RH ;
      } while ( ! ( mem [p ].hh .v.RH == 0 ) ) ;
    } 
    if ( penalties ) {
	
      if ( mem [q ].hh .v.RH != 0 ) {
	  
	if ( pen < 10000 ) 
	{
	  rtype = mem [mem [q ].hh .v.RH ].hh.b0 ;
	  if ( rtype != 12 ) {
	      
	    if ( rtype != 19 ) 
	    {
	      z = newpenalty ( pen ) ;
	      mem [p ].hh .v.RH = z ;
	      p = z ;
	    } 
	  } 
	} 
      } 
    } 
    if ( mem [q ].hh.b0 == 31 ) 
    t = 20 ;
    rtype = t ;
    lab83: r = q ;
    q = mem [q ].hh .v.RH ;
    freenode ( r , s ) ;
    lab30: ;
  } 
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
  while ( ( curchr == 65537L ) && ( curcmd == 4 ) ) {
      
    gettoken () ;
    if ( curcmd > 117 ) 
    {
      expand () ;
      gettoken () ;
    } 
  } 
  if ( curcmd == 9 ) 
  fatalerror ( 65904L ) ;
  if ( ( curcmd == 78 ) && ( curchr == 393241L ) ) 
  {
    scanoptionalequals () ;
    scanglue ( 2 ) ;
    if ( neweqtbint ( 1049451L ) > 0 ) 
    geqdefine ( 393241L , 134 , curval ) ;
    else eqdefine ( 393241L , 134 , curval ) ;
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
  if ( ( curlist .modefield == 237 ) && ( ( curlist .tailfield != curlist 
  .headfield ) || ( curlist .auxfield .cint != 0 ) ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 65996L ) ;
    } 
    printesc ( 65815L ) ;
    print ( 66250L ) ;
    {
      helpptr = 3 ;
      helpline [2 ]= 66251L ;
      helpline [1 ]= 66252L ;
      helpline [0 ]= 66253L ;
    } 
    error () ;
    flushmath () ;
  } 
  pushnest () ;
  if ( curlist .modefield == 237 ) 
  {
    curlist .modefield = -1 ;
    curlist .auxfield .cint = nest [nestptr - 2 ].auxfield .cint ;
  } 
  else if ( curlist .modefield > 0 ) 
  curlist .modefield = - (integer) curlist .modefield ;
  scanspec ( 6 , false ) ;
  mem [memtop - 8 ].hh .v.RH = 0 ;
  curalign = memtop - 8 ;
  curloop = 0 ;
  scannerstatus = 4 ;
  warningindex = savecsptr ;
  alignstate = -1000000L ;
  while ( true ) {
      
    mem [curalign ].hh .v.RH = newparamglue ( 11 ) ;
    curalign = mem [curalign ].hh .v.RH ;
    if ( curcmd == 5 ) 
    goto lab30 ;
    p = memtop - 4 ;
    mem [p ].hh .v.RH = 0 ;
    while ( true ) {
	
      getpreambletoken () ;
      if ( curcmd == 6 ) 
      goto lab31 ;
      if ( ( curcmd <= 5 ) && ( curcmd >= 4 ) && ( alignstate == -1000000L ) ) 
      {
	if ( ( p == memtop - 4 ) && ( curloop == 0 ) && ( curcmd == 4 ) ) 
	curloop = curalign ;
	else {
	    
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 66259L ) ;
	  } 
	  {
	    helpptr = 3 ;
	    helpline [2 ]= 66260L ;
	    helpline [1 ]= 66261L ;
	    helpline [0 ]= 66262L ;
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
    mem [p ].hh .v.RH = 0 ;
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
	  else printnl ( 65548L ) ;
	  print ( 66263L ) ;
	} 
	{
	  helpptr = 3 ;
	  helpline [2 ]= 66260L ;
	  helpline [1 ]= 66261L ;
	  helpline [0 ]= 66264L ;
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
    mem [p ].hh .v.LH = 1245190L ;
    mem [curalign + 2 ].cint = mem [memtop - 4 ].hh .v.RH ;
  } 
  lab30: scannerstatus = 0 ;
  newsavelevel ( 6 ) ;
  if ( newequiv ( 524332L ) != 0 ) 
  begintokenlist ( newequiv ( 524332L ) , 13 ) ;
  alignpeek () ;
} 
void 
zinitspan ( halfword p ) 
{
  initspan_regmem 
  pushnest () ;
  if ( curlist .modefield == -119 ) 
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
  curlist .modefield = ( -120 ) - curlist .modefield ;
  if ( curlist .modefield == -119 ) 
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
  if ( curcmd == 63 ) 
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
  if ( curalign == 0 ) 
  confusion ( 66265L ) ;
  q = mem [curalign ].hh .v.RH ;
  if ( q == 0 ) 
  confusion ( 66265L ) ;
  if ( alignstate < 500000L ) 
  fatalerror ( 65904L ) ;
  p = mem [q ].hh .v.RH ;
  if ( ( p == 0 ) && ( mem [curalign + 5 ].hh .v.LH < 65538L ) ) {
      
    if ( curloop != 0 ) 
    {
      mem [q ].hh .v.RH = newnullbox () ;
      p = mem [q ].hh .v.RH ;
      mem [p ].hh .v.LH = memtop - 9 ;
      mem [p + 1 ].cint = -1073741824L ;
      curloop = mem [curloop ].hh .v.RH ;
      q = memtop - 4 ;
      r = mem [curloop + 3 ].cint ;
      while ( r != 0 ) {
	  
	mem [q ].hh .v.RH = getavail () ;
	q = mem [q ].hh .v.RH ;
	mem [q ].hh .v.LH = mem [r ].hh .v.LH ;
	r = mem [r ].hh .v.RH ;
      } 
      mem [q ].hh .v.RH = 0 ;
      mem [p + 3 ].cint = mem [memtop - 4 ].hh .v.RH ;
      q = memtop - 4 ;
      r = mem [curloop + 2 ].cint ;
      while ( r != 0 ) {
	  
	mem [q ].hh .v.RH = getavail () ;
	q = mem [q ].hh .v.RH ;
	mem [q ].hh .v.LH = mem [r ].hh .v.LH ;
	r = mem [r ].hh .v.RH ;
      } 
      mem [q ].hh .v.RH = 0 ;
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
	else printnl ( 65548L ) ;
	print ( 66266L ) ;
      } 
      printesc ( 66255L ) ;
      {
	helpptr = 3 ;
	helpline [2 ]= 66267L ;
	helpline [1 ]= 66268L ;
	helpline [0 ]= 66269L ;
      } 
      mem [curalign + 5 ].hh .v.LH = 65538L ;
      error () ;
    } 
  } 
  if ( mem [curalign + 5 ].hh .v.LH != 65537L ) 
  {
    unsave () ;
    newsavelevel ( 6 ) ;
    {
      if ( curlist .modefield == -119 ) 
      {
	adjusttail = curtail ;
	u = hpack ( mem [curlist .headfield ].hh .v.RH , 0 , 1 ) ;
	w = mem [u + 1 ].cint ;
	curtail = adjusttail ;
	adjusttail = 0 ;
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
	confusion ( 66270L ) ;
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
      mem [u ].hh.b0 = 13 ;
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
    if ( mem [curalign + 5 ].hh .v.LH >= 65538L ) 
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
  if ( curlist .modefield == -119 ) 
  {
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
  mem [p ].hh.b0 = 13 ;
  mem [p + 6 ].cint = 0 ;
  if ( newequiv ( 524332L ) != 0 ) 
  begintokenlist ( newequiv ( 524332L ) , 13 ) ;
  alignpeek () ;
} 
void 
finalign ( void ) 
{
  finalign_regmem 
  halfword p, q, r, s, u, v  ;
  scaled t, w  ;
  scaled o  ;
  halfword n  ;
  scaled rulesave  ;
  memoryword auxsave  ;
  if ( curgroup != 6 ) 
  confusion ( 66271L ) ;
  unsave () ;
  if ( curgroup != 6 ) 
  confusion ( 66272L ) ;
  unsave () ;
  if ( nest [nestptr - 1 ].modefield == 237 ) 
  o = neweqtbsc ( 1180556L + ( 15 ) ) ;
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
    mem [q ].hh.b0 = 13 ;
    mem [q ].hh.b1 = 0 ;
    mem [q + 3 ].cint = 0 ;
    mem [q + 2 ].cint = 0 ;
    mem [q + 5 ].hh.b1 = 0 ;
    mem [q + 5 ].hh.b0 = 0 ;
    mem [q + 6 ].cint = 0 ;
    mem [q + 4 ].cint = 0 ;
    q = p ;
  } while ( ! ( q == 0 ) ) ;
  saveptr = saveptr - 2 ;
  packbeginline = - (integer) curlist .mlfield ;
  if ( curlist .modefield == -1 ) 
  {
    rulesave = neweqtbsc ( 1180556L + ( 16 ) ) ;
    setneweqtbsc ( 1180572L , 0 ) ;
    p = hpack ( mem [memtop - 8 ].hh .v.RH , savestack [saveptr + 1 ].cint 
    , savestack [saveptr + 0 ].cint ) ;
    setneweqtbsc ( 1180572L , rulesave ) ;
  } 
  else {
      
    q = mem [mem [memtop - 8 ].hh .v.RH ].hh .v.RH ;
    do {
	mem [q + 3 ].cint = mem [q + 1 ].cint ;
      mem [q + 1 ].cint = 0 ;
      q = mem [mem [q ].hh .v.RH ].hh .v.RH ;
    } while ( ! ( q == 0 ) ) ;
    p = vpackage ( mem [memtop - 8 ].hh .v.RH , savestack [saveptr + 1 ]
    .cint , savestack [saveptr + 0 ].cint , 1073741823L ) ;
    q = mem [mem [memtop - 8 ].hh .v.RH ].hh .v.RH ;
    do {
	mem [q + 1 ].cint = mem [q + 3 ].cint ;
      mem [q + 3 ].cint = 0 ;
      q = mem [mem [q ].hh .v.RH ].hh .v.RH ;
    } while ( ! ( q == 0 ) ) ;
  } 
  packbeginline = 0 ;
  q = mem [curlist .headfield ].hh .v.RH ;
  s = curlist .headfield ;
  while ( q != 0 ) {
      
    if ( ! ( q >= himemmin ) ) {
	
      if ( mem [q ].hh.b0 == 13 ) 
      {
	if ( curlist .modefield == -1 ) 
	{
	  mem [q ].hh.b0 = 0 ;
	  mem [q + 1 ].cint = mem [p + 1 ].cint ;
	} 
	else {
	    
	  mem [q ].hh.b0 = 1 ;
	  mem [q + 3 ].cint = mem [p + 3 ].cint ;
	} 
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
	} while ( ! ( r == 0 ) ) ;
      } 
      else if ( mem [q ].hh.b0 == 2 ) 
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
	  mem [q ].hh .v.RH = 0 ;
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
  if ( curlist .modefield == 237 ) 
  {
    doassignments () ;
    if ( curcmd != 3 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66531L ) ;
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 66251L ;
	helpline [0 ]= 66252L ;
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
	  else printnl ( 65548L ) ;
	  print ( 66527L ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66528L ;
	  helpline [0 ]= 66529L ;
	} 
	backerror () ;
      } 
    } 
    popnest () ;
    {
      mem [curlist .tailfield ].hh .v.RH = newpenalty ( neweqtbint ( 
      1049419L ) ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = newparamglue ( 3 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    mem [curlist .tailfield ].hh .v.RH = p ;
    if ( p != 0 ) 
    curlist .tailfield = q ;
    {
      mem [curlist .tailfield ].hh .v.RH = newpenalty ( neweqtbint ( 
      1049420L ) ) ;
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
    if ( p != 0 ) 
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
  if ( curcmd == 34 ) 
  {
    scanleftbrace () ;
    newsavelevel ( 7 ) ;
    if ( curlist .modefield == -1 ) 
    normalparagraph () ;
  } 
  else if ( curcmd == 2 ) 
  finalign () ;
  else if ( ( curcmd == 5 ) && ( curchr == 65539L ) ) 
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
      else printnl ( 65548L ) ;
      print ( 66273L ) ;
    } 
    {
      helpptr = 5 ;
      helpline [4 ]= 66274L ;
      helpline [3 ]= 66275L ;
      helpline [2 ]= 66276L ;
      helpline [1 ]= 66277L ;
      helpline [0 ]= 66278L ;
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
		
	      if ( curp != 0 ) 
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
		    if ( ( ( dirsecondary [linebreakdir ]) % 2 ) == ( ( 
		    dirtertiary [linebreakdir ]) % 2 ) ) 
		    {
		      breakchtdp = fonttables [f ][ fonttables [f ][ 34 ]
		      .cint - fonttables [f ][ 5 ].cint + mem [v ].hh.b1 ]
		      .qqqq .b1 ;
		      breakwidth [1 ]= breakwidth [1 ]- fonttables [f ][ 
		      fonttables [f ][ 37 ].cint + ( breakchtdp ) / 256 ]
		      .cint - fonttables [f ][ fonttables [f ][ 38 ].cint + 
		      ( breakchtdp ) % 256 ].cint ;
		    } 
		    else breakwidth [1 ]= breakwidth [1 ]- fonttables [f 
		    ][ fonttables [f ][ 36 ].cint + fonttables [f ][ 
		    fonttables [f ][ 34 ].cint - fonttables [f ][ 5 ].cint 
		    + mem [v ].hh.b1 ].qqqq .b0 ].cint ;
		  } 
		  else switch ( mem [v ].hh.b0 ) 
		  {case 6 : 
		    {
		      f = mem [v + 1 ].hh.b0 ;
		      if ( ( ( dirsecondary [linebreakdir ]) % 2 ) == ( ( 
		      dirtertiary [linebreakdir ]) % 2 ) ) 
		      {
			breakchtdp = fonttables [f ][ fonttables [f ][ 34 ]
			.cint - fonttables [f ][ 5 ].cint + mem [v + 1 ]
			.hh.b1 ].qqqq .b1 ;
			breakwidth [1 ]= breakwidth [1 ]- fonttables [f 
			][ fonttables [f ][ 37 ].cint + ( breakchtdp ) / 256 
			].cint - fonttables [f ][ fonttables [f ][ 38 ]
			.cint + ( breakchtdp ) % 256 ].cint ;
		      } 
		      else breakwidth [1 ]= breakwidth [1 ]- fonttables [
		      f ][ fonttables [f ][ 36 ].cint + fonttables [f ][ 
		      fonttables [f ][ 34 ].cint - fonttables [f ][ 5 ]
		      .cint + mem [v + 1 ].hh.b1 ].qqqq .b0 ].cint ;
		    } 
		    break ;
		  case 0 : 
		  case 1 : 
		    if ( ! ( ( ( dirprimary [mem [v + 7 ].cint ]) % 2 ) != 
		    ( dirprimary [linebreakdir ]% 2 ) ) ) 
		    breakwidth [1 ]= breakwidth [1 ]- mem [v + 1 ].cint 
		    ;
		    else breakwidth [1 ]= breakwidth [1 ]- ( mem [v + 2 ]
		    .cint + mem [v + 3 ].cint ) ;
		    break ;
		  case 2 : 
		  case 11 : 
		    breakwidth [1 ]= breakwidth [1 ]- mem [v + 1 ].cint 
		    ;
		    break ;
		    default: 
		    confusion ( 66279L ) ;
		    break ;
		  } 
		} 
		while ( s != 0 ) {
		    
		  if ( ( s >= himemmin ) ) 
		  {
		    f = mem [s ].hh.b0 ;
		    if ( ( ( dirsecondary [linebreakdir ]) % 2 ) == ( ( 
		    dirtertiary [linebreakdir ]) % 2 ) ) 
		    {
		      breakchtdp = fonttables [f ][ fonttables [f ][ 34 ]
		      .cint - fonttables [f ][ 5 ].cint + mem [s ].hh.b1 ]
		      .qqqq .b1 ;
		      breakwidth [1 ]= breakwidth [1 ]+ fonttables [f ][ 
		      fonttables [f ][ 37 ].cint + ( breakchtdp ) / 256 ]
		      .cint + fonttables [f ][ fonttables [f ][ 38 ].cint + 
		      ( breakchtdp ) % 256 ].cint ;
		    } 
		    else breakwidth [1 ]= breakwidth [1 ]+ fonttables [f 
		    ][ fonttables [f ][ 36 ].cint + fonttables [f ][ 
		    fonttables [f ][ 34 ].cint - fonttables [f ][ 5 ].cint 
		    + mem [s ].hh.b1 ].qqqq .b0 ].cint ;
		  } 
		  else switch ( mem [s ].hh.b0 ) 
		  {case 6 : 
		    {
		      f = mem [s + 1 ].hh.b0 ;
		      if ( ( ( dirsecondary [linebreakdir ]) % 2 ) == ( ( 
		      dirtertiary [linebreakdir ]) % 2 ) ) 
		      {
			breakchtdp = fonttables [f ][ fonttables [f ][ 34 ]
			.cint - fonttables [f ][ 5 ].cint + mem [s + 1 ]
			.hh.b1 ].qqqq .b1 ;
			breakwidth [1 ]= breakwidth [1 ]+ fonttables [f 
			][ fonttables [f ][ 37 ].cint + ( breakchtdp ) / 256 
			].cint + fonttables [f ][ fonttables [f ][ 38 ]
			.cint + ( breakchtdp ) % 256 ].cint ;
		      } 
		      else breakwidth [1 ]= breakwidth [1 ]+ fonttables [
		      f ][ fonttables [f ][ 36 ].cint + fonttables [f ][ 
		      fonttables [f ][ 34 ].cint - fonttables [f ][ 5 ]
		      .cint + mem [s + 1 ].hh.b1 ].qqqq .b0 ].cint ;
		    } 
		    break ;
		  case 0 : 
		  case 1 : 
		    if ( ! ( ( ( dirprimary [mem [s + 7 ].cint ]) % 2 ) != 
		    ( dirprimary [linebreakdir ]% 2 ) ) ) 
		    breakwidth [1 ]= breakwidth [1 ]+ mem [s + 1 ].cint 
		    ;
		    else breakwidth [1 ]= breakwidth [1 ]+ ( mem [s + 2 ]
		    .cint + mem [s + 3 ].cint ) ;
		    break ;
		  case 2 : 
		  case 11 : 
		    breakwidth [1 ]= breakwidth [1 ]+ mem [s + 1 ].cint 
		    ;
		    break ;
		    default: 
		    confusion ( 66280L ) ;
		    break ;
		  } 
		  s = mem [s ].hh .v.RH ;
		} 
		breakwidth [1 ]= breakwidth [1 ]+ discwidth ;
		if ( mem [curp + 1 ].hh .v.RH == 0 ) 
		s = mem [v ].hh .v.RH ;
	      } 
	    } 
	    while ( s != 0 ) {
		
	      if ( ( s >= himemmin ) ) 
	      goto lab30 ;
	      switch ( mem [s ].hh.b0 ) 
	      {case 10 : 
		{
		  v = mem [s + 1 ].hh .v.LH ;
		  breakwidth [1 ]= breakwidth [1 ]- mem [v + 1 ].cint ;
		  breakwidth [2 + mem [v ].hh.b0 ]= breakwidth [2 + mem [
		  v ].hh.b0 ]- mem [v + 2 ].cint ;
		  breakwidth [7 ]= breakwidth [7 ]- mem [v + 3 ].cint ;
		} 
		break ;
	      case 12 : 
		;
		break ;
	      case 9 : 
		breakwidth [1 ]= breakwidth [1 ]- mem [s + 1 ].cint ;
		break ;
	      case 11 : 
		if ( mem [s ].hh.b1 != 1 ) 
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
	  if ( abs ( neweqtbint ( 1049424L ) ) >= 1073741823L - 
	  minimumdemerits ) 
	  minimumdemerits = 1073741822L ;
	  else minimumdemerits = minimumdemerits + abs ( neweqtbint ( 1049424L 
	  ) ) ;
	  {register integer for_end; fitclass = 0 ;for_end = 3 ; if ( 
	  fitclass <= for_end) do 
	    {
	      if ( minimaldemerits [fitclass ]<= minimumdemerits ) 
	      {
		q = getnode ( 10 ) ;
		mem [q ].hh .v.RH = passive ;
		passive = q ;
		mem [q + 1 ].hh .v.RH = curp ;
	;
#ifdef STAT
		incr ( passnumber ) ;
		mem [q ].hh .v.LH = passnumber ;
#endif /* STAT */
		mem [q + 1 ].hh .v.LH = bestplace [fitclass ];
		mem [q + 2 ].cint = internalpeninter ;
		mem [q + 3 ].cint = internalpenbroken ;
		mem [q + 6 ].cint = internalleftbox ;
		mem [q + 7 ].cint = internalleftboxwidth ;
		if ( mem [q + 1 ].hh .v.LH != 0 ) 
		{
		  mem [q + 4 ].cint = mem [mem [q + 1 ].hh .v.LH + 6 ]
		  .cint ;
		  mem [q + 5 ].cint = mem [mem [q + 1 ].hh .v.LH + 7 ]
		  .cint ;
		} 
		else {
		    
		  mem [q + 4 ].cint = initinternalleftbox ;
		  mem [q + 5 ].cint = initinternalleftboxwidth ;
		} 
		mem [q + 8 ].cint = internalrightbox ;
		mem [q + 9 ].cint = internalrightboxwidth ;
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
		if ( neweqtbint ( 1049440L ) > 0 ) 
		{
		  printnl ( 66281L ) ;
		  printint ( mem [passive ].hh .v.LH ) ;
		  print ( 66282L ) ;
		  printint ( mem [q + 1 ].hh .v.LH - 1 ) ;
		  printchar ( 46 ) ;
		  printint ( fitclass ) ;
		  if ( breaktype == 1 ) 
		  printchar ( 45 ) ;
		  print ( 66283L ) ;
		  printint ( mem [q + 2 ].cint ) ;
		  if ( dolastlinefit ) 
		  {
		    print ( 66789L ) ;
		    printscaled ( mem [q + 3 ].cint ) ;
		    if ( curp == 0 ) 
		    print ( 66790L ) ;
		    else print ( 66353L ) ;
		    printscaled ( mem [q + 4 ].cint ) ;
		  } 
		  print ( 66284L ) ;
		  if ( mem [passive + 1 ].hh .v.LH == 0 ) 
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
	  else if ( newequiv ( 524320L ) == 0 ) 
	  linewidth = firstwidth ;
	  else linewidth = mem [newequiv ( 524320L ) + 2 * l ].cint ;
	} 
      } 
    } 
    {
      artificialdemerits = false ;
      shortfall = linewidth - curactivewidth [1 ];
      if ( mem [r + 1 ].hh .v.RH == 0 ) 
      shortfall = shortfall - initinternalleftboxwidth ;
      else shortfall = shortfall - mem [mem [r + 1 ].hh .v.RH + 7 ].cint ;
      shortfall = shortfall - internalrightboxwidth ;
      if ( shortfall > 0 ) {
	  
	if ( ( curactivewidth [3 ]!= 0 ) || ( curactivewidth [4 ]!= 0 ) || 
	( curactivewidth [5 ]!= 0 ) || ( curactivewidth [6 ]!= 0 ) ) 
	{
	  if ( dolastlinefit ) 
	  {
	    if ( curp == 0 ) 
	    {
	      if ( ( mem [r + 3 ].cint == 0 ) || ( mem [r + 4 ].cint <= 0 
	      ) ) 
	      goto lab45 ;
	      if ( ( curactivewidth [3 ]!= fillwidth [0 ]) || ( 
	      curactivewidth [4 ]!= fillwidth [1 ]) || ( curactivewidth [
	      5 ]!= fillwidth [2 ]) ) 
	      goto lab45 ;
	      if ( mem [r + 3 ].cint > 0 ) 
	      g = curactivewidth [2 ];
	      else g = curactivewidth [6 ];
	      if ( g <= 0 ) 
	      goto lab45 ;
	      aritherror = false ;
	      g = fract ( g , mem [r + 3 ].cint , mem [r + 4 ].cint , 
	      1073741823L ) ;
	      if ( neweqtbint ( 1049475L ) < 1000 ) 
	      g = fract ( g , neweqtbint ( 1049475L ) , 1000 , 1073741823L ) ;
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
		if ( - (integer) g > curactivewidth [6 ]) 
		g = - (integer) curactivewidth [6 ];
		b = badness ( - (integer) g , curactivewidth [6 ]) ;
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
	if ( curp == 0 ) 
	shortfall = 0 ;
	if ( shortfall > 0 ) 
	g = curactivewidth [2 ];
	else if ( shortfall < 0 ) 
	g = curactivewidth [6 ];
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
	  
	d = neweqtbint ( 1049410L ) + b ;
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
	    
	  if ( curp != 0 ) 
	  d = d + neweqtbint ( 1049422L ) ;
	  else d = d + neweqtbint ( 1049423L ) ;
	} 
	if ( abs ( fitclass - mem [r ].hh.b1 ) > 1 ) 
	d = d + neweqtbint ( 1049424L ) ;
      } 
	;
#ifdef STAT
      if ( neweqtbint ( 1049440L ) > 0 ) 
      {
	if ( printednode != curp ) 
	{
	  printnl ( 65624L ) ;
	  if ( curp == 0 ) 
	  shortdisplay ( mem [printednode ].hh .v.RH ) ;
	  else {
	      
	    savelink = mem [curp ].hh .v.RH ;
	    mem [curp ].hh .v.RH = 0 ;
	    printnl ( 65624L ) ;
	    shortdisplay ( mem [printednode ].hh .v.RH ) ;
	    mem [curp ].hh .v.RH = savelink ;
	  } 
	  printednode = curp ;
	} 
	printnl ( 64 ) ;
	if ( curp == 0 ) 
	printesc ( 65906L ) ;
	else if ( mem [curp ].hh.b0 != 10 ) 
	{
	  if ( mem [curp ].hh.b0 == 12 ) 
	  printesc ( 65830L ) ;
	  else if ( mem [curp ].hh.b0 == 7 ) 
	  printesc ( 65635L ) ;
	  else if ( mem [curp ].hh.b0 == 11 ) 
	  printesc ( 65626L ) ;
	  else printesc ( 65629L ) ;
	} 
	print ( 66285L ) ;
	if ( mem [r + 1 ].hh .v.RH == 0 ) 
	printchar ( 48 ) ;
	else printint ( mem [mem [r + 1 ].hh .v.RH ].hh .v.LH ) ;
	print ( 66286L ) ;
	if ( b > 10000 ) 
	printchar ( 42 ) ;
	else printint ( b ) ;
	print ( 66287L ) ;
	printint ( pi ) ;
	print ( 66288L ) ;
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
      
    if ( curp != 0 ) {
	
      if ( mem [curp ].hh.b0 == 7 ) 
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
  dirptr = curlist .dirsfield ;
  q = mem [bestbet + 1 ].hh .v.RH ;
  curp = 0 ;
  do {
      r = q ;
    q = mem [q + 1 ].hh .v.LH ;
    mem [r + 1 ].hh .v.LH = curp ;
    curp = r ;
  } while ( ! ( q == 0 ) ) ;
  curline = curlist .pgfield + 1 ;
  do {
      { 
      dirrover = dirptr ;
      while ( dirrover != 0 ) {
	  
	dirtmp = newdir ( mem [dirrover + 1 ].hh .v.LH ) ;
	mem [dirtmp ].hh .v.RH = mem [memtop - 3 ].hh .v.RH ;
	mem [memtop - 3 ].hh .v.RH = dirtmp ;
	dirrover = mem [dirrover ].hh .v.RH ;
      } 
    } 
    {
      flushnodelist ( dirptr ) ;
      dirptr = 0 ;
      q = mem [memtop - 3 ].hh .v.RH ;
      while ( q != mem [curp + 1 ].hh .v.RH ) {
	  
	if ( ! ( q >= himemmin ) ) {
	    
	  if ( mem [q ].hh.b0 == 8 ) {
	      
	    if ( mem [q ].hh.b1 == 7 ) 
	    {
	      if ( mem [q + 1 ].hh .v.LH >= 0 ) 
	      {
		{
		  dirtmp = getnode ( 4 ) ;
		  mem [dirtmp ].hh.b0 = 8 ;
		  mem [dirtmp ].hh.b1 = 7 ;
		  mem [dirtmp + 1 ].hh .v.LH = mem [q + 1 ].hh .v.LH ;
		  mem [dirtmp + 1 ].hh .v.RH = mem [q + 1 ].hh .v.RH ;
		  mem [dirtmp + 3 ].hh .v.LH = mem [q + 3 ].hh .v.LH ;
		  mem [dirtmp + 2 ].hh .v.LH = mem [q + 2 ].hh .v.LH ;
		  mem [dirtmp ].hh .v.RH = dirptr ;
		  dirptr = dirtmp ;
		} 
	      } 
	      else if ( dirptr != 0 ) {
		  
		if ( mem [dirptr + 1 ].hh .v.LH == ( mem [q + 1 ].hh .v.LH 
		+ 64 ) ) 
		{
		  {
		    dirtmp = dirptr ;
		    dirptr = mem [dirtmp ].hh .v.RH ;
		    freenode ( dirtmp , 4 ) ;
		  } 
		} 
	      } 
	    } 
	  } 
	} 
	q = mem [q ].hh .v.RH ;
      } 
    } 
    q = mem [curp + 1 ].hh .v.RH ;
    discbreak = false ;
    postdiscbreak = false ;
    if ( q != 0 ) {
	
      if ( mem [q ].hh.b0 == 10 ) 
      {
	if ( mem [curp + 8 ].cint != 0 ) 
	{
	  r = memtop - 3 ;
	  while ( mem [r ].hh .v.RH != q ) r = mem [r ].hh .v.RH ;
	  if ( dirptr != 0 ) 
	  {
	    if ( mem [r ].hh .v.RH == q ) 
	    {
	      dirrover = dirptr ;
	      while ( dirrover != 0 ) {
		  
		dirtmp = newdir ( mem [dirrover + 1 ].hh .v.LH - 64 ) ;
		mem [dirtmp ].hh .v.RH = q ;
		mem [r ].hh .v.RH = dirtmp ;
		r = dirtmp ;
		dirrover = mem [dirrover ].hh .v.RH ;
	      } 
	    } 
	    else if ( r == finalparglue ) 
	    {
	      s = memtop - 3 ;
	      while ( mem [s ].hh .v.RH != r ) s = mem [s ].hh .v.RH ;
	      dirrover = dirptr ;
	      while ( dirrover != 0 ) {
		  
		dirtmp = newdir ( mem [dirrover + 1 ].hh .v.LH - 64 ) ;
		mem [dirtmp ].hh .v.RH = q ;
		mem [s ].hh .v.RH = dirtmp ;
		s = dirtmp ;
		dirrover = mem [dirrover ].hh .v.RH ;
	      } 
	    } 
	    else {
		
	      dirrover = dirptr ;
	      s = mem [q ].hh .v.RH ;
	      while ( dirrover != 0 ) {
		  
		dirtmp = newdir ( mem [dirrover + 1 ].hh .v.LH - 64 ) ;
		mem [dirtmp ].hh .v.RH = s ;
		mem [q ].hh .v.RH = dirtmp ;
		q = dirtmp ;
		dirrover = mem [dirrover ].hh .v.RH ;
	      } 
	      r = q ;
	    } 
	  } 
	  s = copynodelist ( mem [curp + 8 ].cint ) ;
	  mem [r ].hh .v.RH = s ;
	  mem [s ].hh .v.RH = q ;
	} 
	else {
	    
	  r = memtop - 3 ;
	  while ( mem [r ].hh .v.RH != q ) r = mem [r ].hh .v.RH ;
	  if ( dirptr != 0 ) 
	  {
	    if ( mem [r ].hh .v.RH == q ) 
	    {
	      dirrover = dirptr ;
	      while ( dirrover != 0 ) {
		  
		dirtmp = newdir ( mem [dirrover + 1 ].hh .v.LH - 64 ) ;
		mem [dirtmp ].hh .v.RH = q ;
		mem [r ].hh .v.RH = dirtmp ;
		r = dirtmp ;
		dirrover = mem [dirrover ].hh .v.RH ;
	      } 
	    } 
	    else if ( r == finalparglue ) 
	    {
	      s = memtop - 3 ;
	      while ( mem [s ].hh .v.RH != r ) s = mem [s ].hh .v.RH ;
	      dirrover = dirptr ;
	      while ( dirrover != 0 ) {
		  
		dirtmp = newdir ( mem [dirrover + 1 ].hh .v.LH - 64 ) ;
		mem [dirtmp ].hh .v.RH = q ;
		mem [s ].hh .v.RH = dirtmp ;
		s = dirtmp ;
		dirrover = mem [dirrover ].hh .v.RH ;
	      } 
	    } 
	    else {
		
	      dirrover = dirptr ;
	      s = mem [q ].hh .v.RH ;
	      while ( dirrover != 0 ) {
		  
		dirtmp = newdir ( mem [dirrover + 1 ].hh .v.LH - 64 ) ;
		mem [dirtmp ].hh .v.RH = s ;
		mem [q ].hh .v.RH = dirtmp ;
		q = dirtmp ;
		dirrover = mem [dirrover ].hh .v.RH ;
	      } 
	      r = q ;
	    } 
	  } 
	} 
	deleteglueref ( mem [q + 1 ].hh .v.LH ) ;
	mem [q + 1 ].hh .v.LH = newequiv ( 393238L ) ;
	mem [q ].hh.b1 = 9 ;
	incr ( mem [newequiv ( 393238L ) ].hh .v.RH ) ;
	goto lab30 ;
      } 
      else {
	  
	if ( mem [q ].hh.b0 == 7 ) 
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
	    mem [s ].hh .v.RH = 0 ;
	    flushnodelist ( mem [q ].hh .v.RH ) ;
	    mem [q ].hh.b1 = 0 ;
	  } 
	  if ( mem [q + 1 ].hh .v.RH != 0 ) 
	  {
	    s = mem [q + 1 ].hh .v.RH ;
	    while ( mem [s ].hh .v.RH != 0 ) s = mem [s ].hh .v.RH ;
	    mem [s ].hh .v.RH = r ;
	    r = mem [q + 1 ].hh .v.RH ;
	    mem [q + 1 ].hh .v.RH = 0 ;
	    postdiscbreak = true ;
	  } 
	  if ( mem [q + 1 ].hh .v.LH != 0 ) 
	  {
	    s = mem [q + 1 ].hh .v.LH ;
	    mem [q ].hh .v.RH = s ;
	    while ( mem [s ].hh .v.RH != 0 ) s = mem [s ].hh .v.RH ;
	    mem [q + 1 ].hh .v.LH = 0 ;
	    q = s ;
	  } 
	  mem [q ].hh .v.RH = r ;
	  discbreak = true ;
	} 
	else if ( ( mem [q ].hh.b0 == 9 ) || ( mem [q ].hh.b0 == 11 ) ) 
	mem [q + 1 ].cint = 0 ;
      } 
    } 
    else {
	
      q = memtop - 3 ;
      while ( mem [q ].hh .v.RH != 0 ) q = mem [q ].hh .v.RH ;
    } 
    r = q ;
    if ( dirptr != 0 ) 
    {
      if ( mem [r ].hh .v.RH == q ) 
      {
	dirrover = dirptr ;
	while ( dirrover != 0 ) {
	    
	  dirtmp = newdir ( mem [dirrover + 1 ].hh .v.LH - 64 ) ;
	  mem [dirtmp ].hh .v.RH = q ;
	  mem [r ].hh .v.RH = dirtmp ;
	  r = dirtmp ;
	  dirrover = mem [dirrover ].hh .v.RH ;
	} 
      } 
      else if ( r == finalparglue ) 
      {
	s = memtop - 3 ;
	while ( mem [s ].hh .v.RH != r ) s = mem [s ].hh .v.RH ;
	dirrover = dirptr ;
	while ( dirrover != 0 ) {
	    
	  dirtmp = newdir ( mem [dirrover + 1 ].hh .v.LH - 64 ) ;
	  mem [dirtmp ].hh .v.RH = q ;
	  mem [s ].hh .v.RH = dirtmp ;
	  s = dirtmp ;
	  dirrover = mem [dirrover ].hh .v.RH ;
	} 
      } 
      else {
	  
	dirrover = dirptr ;
	s = mem [q ].hh .v.RH ;
	while ( dirrover != 0 ) {
	    
	  dirtmp = newdir ( mem [dirrover + 1 ].hh .v.LH - 64 ) ;
	  mem [dirtmp ].hh .v.RH = s ;
	  mem [q ].hh .v.RH = dirtmp ;
	  q = dirtmp ;
	  dirrover = mem [dirrover ].hh .v.RH ;
	} 
	r = q ;
      } 
    } 
    if ( mem [curp + 8 ].cint != 0 ) 
    {
      r = copynodelist ( mem [curp + 8 ].cint ) ;
      mem [r ].hh .v.RH = mem [q ].hh .v.RH ;
      mem [q ].hh .v.RH = r ;
      q = r ;
    } 
    r = newparamglue ( 8 ) ;
    mem [r ].hh .v.RH = mem [q ].hh .v.RH ;
    mem [q ].hh .v.RH = r ;
    q = r ;
    lab30: ;
    r = mem [q ].hh .v.RH ;
    mem [q ].hh .v.RH = 0 ;
    q = mem [memtop - 3 ].hh .v.RH ;
    mem [memtop - 3 ].hh .v.RH = r ;
    if ( mem [curp + 4 ].cint != 0 ) 
    {
      r = copynodelist ( mem [curp + 4 ].cint ) ;
      s = mem [q ].hh .v.RH ;
      mem [r ].hh .v.RH = q ;
      q = r ;
      if ( ( curline == curlist .pgfield + 1 ) && ( s != 0 ) ) {
	  
	if ( mem [s ].hh.b0 == 0 ) {
	    
	  if ( mem [s + 5 ].hh .v.RH == 0 ) 
	  {
	    q = mem [q ].hh .v.RH ;
	    mem [r ].hh .v.RH = mem [s ].hh .v.RH ;
	    mem [s ].hh .v.RH = r ;
	  } 
	} 
      } 
    } 
    if ( newequiv ( 393237L ) != membot ) 
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
    else if ( newequiv ( 524320L ) == 0 ) 
    {
      curwidth = firstwidth ;
      curindent = firstindent ;
    } 
    else {
	
      curwidth = mem [newequiv ( 524320L ) + 2 * curline ].cint ;
      curindent = mem [newequiv ( 524320L ) + 2 * curline - 1 ].cint ;
    } 
    adjusttail = memtop - 5 ;
    packdirection = paragraphdir ;
    justbox = hpack ( q , curwidth , 0 ) ;
    mem [justbox + 4 ].cint = curindent ;
    appendtovlist ( justbox ) ;
    if ( memtop - 5 != adjusttail ) 
    {
      mem [curlist .tailfield ].hh .v.RH = mem [memtop - 5 ].hh .v.RH ;
      curlist .tailfield = adjusttail ;
    } 
    adjusttail = 0 ;
    if ( curline + 1 != bestline ) 
    {
      q = newequiv ( 524321L ) ;
      if ( q != 0 ) 
      {
	r = curline ;
	if ( r > mem [q + 1 ].cint ) 
	r = mem [q + 1 ].cint ;
	pen = mem [q + r + 1 ].cint ;
      } 
      else {
	  
	if ( mem [curp + 2 ].cint != 0 ) 
	pen = mem [curp + 2 ].cint ;
	else pen = neweqtbint ( 1049421L ) ;
      } 
      q = newequiv ( 524322L ) ;
      if ( q != 0 ) 
      {
	r = curline - curlist .pgfield ;
	if ( r > mem [q + 1 ].cint ) 
	r = mem [q + 1 ].cint ;
	pen = pen + mem [q + r + 1 ].cint ;
      } 
      else if ( curline == curlist .pgfield + 1 ) 
      pen = pen + neweqtbint ( 1049413L ) ;
      if ( d ) 
      q = newequiv ( 524324L ) ;
      else q = newequiv ( 524323L ) ;
      if ( q != 0 ) 
      {
	r = bestline - curline - 1 ;
	if ( r > mem [q + 1 ].cint ) 
	r = mem [q + 1 ].cint ;
	pen = pen + mem [q + r + 1 ].cint ;
      } 
      else if ( curline + 2 == bestline ) {
	  
	if ( d ) 
	pen = pen + neweqtbint ( 1049415L ) ;
	else pen = pen + neweqtbint ( 1049414L ) ;
      } 
      if ( discbreak ) {
	  
	if ( mem [curp + 3 ].cint != 0 ) 
	pen = pen + mem [curp + 3 ].cint ;
	else pen = pen + neweqtbint ( 1049416L ) ;
      } 
      if ( pen != 0 ) 
      {
	r = newpenalty ( pen ) ;
	mem [curlist .tailfield ].hh .v.RH = r ;
	curlist .tailfield = r ;
      } 
    } 
    incr ( curline ) ;
    curp = mem [curp + 1 ].hh .v.LH ;
    if ( curp != 0 ) {
	
      if ( ! postdiscbreak ) 
      {
	r = memtop - 3 ;
	while ( true ) {
	    
	  q = mem [r ].hh .v.RH ;
	  if ( q == mem [curp + 1 ].hh .v.RH ) 
	  goto lab31 ;
	  if ( ( q >= himemmin ) ) 
	  goto lab31 ;
	  if ( ( ( mem [q ].hh.b0 == 8 ) && ( mem [q ].hh.b1 == 6 ) ) ) 
	  {
	    ;
	  } 
	  else {
	      
	    if ( ( mem [q ].hh.b0 < 9 ) ) 
	    goto lab31 ;
	    if ( mem [q ].hh.b0 == 11 ) {
		
	      if ( mem [q ].hh.b1 != 1 ) 
	      goto lab31 ;
	    } 
	  } 
	  r = q ;
	} 
	lab31: if ( r != memtop - 3 ) 
	{
	  mem [r ].hh .v.RH = 0 ;
	  flushnodelist ( mem [memtop - 3 ].hh .v.RH ) ;
	  mem [memtop - 3 ].hh .v.RH = q ;
	} 
      } 
    } 
  } while ( ! ( curp == 0 ) ) ;
  if ( ( curline != bestline ) || ( mem [memtop - 3 ].hh .v.RH != 0 ) ) 
  confusion ( 66295L ) ;
  curlist .pgfield = bestline - 1 ;
  curlist .dirsfield = dirptr ;
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
  mem [memtop - 4 ].hh .v.RH = 0 ;
  curl = hu [j ];
  curq = t ;
  if ( j == 0 ) 
  {
    ligaturepresent = initlig ;
    p = initlist ;
    if ( ligaturepresent ) 
    lfthit = initlft ;
    while ( p > 0 ) {
	
      {
	mem [t ].hh .v.RH = getavail () ;
	t = mem [t ].hh .v.RH ;
	mem [t ].hh.b0 = hf ;
	mem [t ].hh.b1 = mem [p ].hh.b1 ;
      } 
      p = mem [p ].hh .v.RH ;
    } 
  } 
  else if ( curl < 65536L ) 
  {
    mem [t ].hh .v.RH = getavail () ;
    t = mem [t ].hh .v.RH ;
    mem [t ].hh.b0 = hf ;
    mem [t ].hh.b1 = curl ;
  } 
  ligstack = 0 ;
  {
    if ( j < n ) 
    curr = hu [j + 1 ];
    else curr = bchar ;
    if ( odd ( hyf [j ]) ) 
    currh = hchar ;
    else currh = 65536L ;
  } 
  lab22: if ( curl == 65536L ) 
  {
    k = fonttables [hf ][ 18 ].cint ;
    if ( k == 0 ) 
    goto lab30 ;
    else q = fonttables [hf ][ k ].qqqq ;
  } 
  else {
      
    q = fonttables [hf ][ fonttables [hf ][ 34 ].cint - fonttables [hf ][ 
    5 ].cint + curl ].qqqq ;
    if ( ( ( q .b2 ) % 4 ) != 1 ) 
    goto lab30 ;
    k = fonttables [hf ][ 40 ].cint + q .b3 ;
    q = fonttables [hf ][ k ].qqqq ;
    if ( ( q .b0 % 256 ) > 128 ) 
    {
      k = fonttables [hf ][ 40 ].cint + 256 * q .b2 + q .b3 + 32768L - 256 * 
      ( 128 ) ;
      q = fonttables [hf ][ k ].qqqq ;
    } 
  } 
  if ( currh < 65536L ) 
  testchar = currh ;
  else testchar = curr ;
  while ( true ) {
      
    if ( ( fonttables [hf ][ 5 ].cint + q .b1 ) == testchar ) {
	
      if ( ( q .b0 % 256 ) <= 128 ) {
	  
	if ( currh < 65536L ) 
	{
	  hyphenpassed = j ;
	  hchar = 65536L ;
	  currh = 65536L ;
	  goto lab22 ;
	} 
	else {
	    
	  if ( hchar < 65536L ) {
	      
	    if ( odd ( hyf [j ]) ) 
	    {
	      hyphenpassed = j ;
	      hchar = 65536L ;
	    } 
	  } 
	  if ( q .b2 < 128 ) 
	  {
	    if ( curl == 65536L ) 
	    lfthit = true ;
	    if ( j == n ) {
		
	      if ( ligstack == 0 ) 
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
		if ( ligstack > 0 ) 
		mem [ligstack ].hh.b1 = curr ;
		else {
		    
		  ligstack = newligitem ( curr ) ;
		  if ( j == n ) 
		  bchar = 65536L ;
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
		      
		    if ( ligstack == 0 ) 
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
		if ( ligstack > 0 ) 
		{
		  if ( mem [ligstack + 1 ].hh .v.RH > 0 ) 
		  {
		    mem [t ].hh .v.RH = mem [ligstack + 1 ].hh .v.RH ;
		    t = mem [t ].hh .v.RH ;
		    incr ( j ) ;
		  } 
		  p = ligstack ;
		  ligstack = mem [p ].hh .v.RH ;
		  freenode ( p , 2 ) ;
		  if ( ligstack == 0 ) 
		  {
		    if ( j < n ) 
		    curr = hu [j + 1 ];
		    else curr = bchar ;
		    if ( odd ( hyf [j ]) ) 
		    currh = hchar ;
		    else currh = 65536L ;
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
		    else currh = 65536L ;
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
	  w = fonttables [hf ][ fonttables [hf ][ 41 ].cint + 256 * q .b2 + 
	  q .b3 ].cint ;
	  goto lab30 ;
	} 
      } 
    } 
    if ( ( q .b0 % 256 ) >= 128 ) {
	
      if ( currh == 65536L ) 
      goto lab30 ;
      else {
	  
	currh = 65536L ;
	goto lab22 ;
      } 
    } 
    k = k + ( q .b0 % 256 ) + 1 ;
    q = fonttables [hf ][ k ].qqqq ;
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
	
      if ( ligstack == 0 ) 
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
  } 
  if ( ligstack > 0 ) 
  {
    curq = t ;
    curl = mem [ligstack ].hh.b1 ;
    ligaturepresent = true ;
    {
      if ( mem [ligstack + 1 ].hh .v.RH > 0 ) 
      {
	mem [t ].hh .v.RH = mem [ligstack + 1 ].hh .v.RH ;
	t = mem [t ].hh .v.RH ;
	incr ( j ) ;
      } 
      p = ligstack ;
      ligstack = mem [p ].hh .v.RH ;
      freenode ( p , 2 ) ;
      if ( ligstack == 0 ) 
      {
	if ( j < n ) 
	curr = hu [j + 1 ];
	else curr = bchar ;
	if ( odd ( hyf [j ]) ) 
	currh = hchar ;
	else currh = 65536L ;
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
    if ( length ( k ) == hn ) 
    {
      j = 1 ;
      u = strstartar [k - 65536L ];
      do {
	  if ( strpool [u ]!= hc [j ]) 
	goto lab30 ;
	incr ( j ) ;
	incr ( u ) ;
      } while ( ! ( j > hn ) ) ;
      s = hyphlist [h ];
      while ( s != 0 ) {
	  
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
  if ( trie [curlang + 1 ].b1 != curlang ) 
  return ;
  hc [0 ]= 0 ;
  hc [hn + 1 ]= 0 ;
  hc [hn + 2 ]= maxhyphchar ;
  {register integer for_end; j = 0 ;for_end = hn - rhyf + 1 ; if ( j <= 
  for_end) do 
    {
      z = trie [curlang + 1 ].v.RH + hc [j ];
      l = j ;
      while ( hc [l ]== trie [z ].b1 ) {
	  
	if ( trie [z ].b0 != 0 ) 
	{
	  v = trie [z ].b0 ;
	  do {
	      v = v + opstart [curlang ];
	    i = l - hyfdistance [v ];
	    if ( hyfnum [v ]> hyf [i ]) 
	    hyf [i ]= hyfnum [v ];
	    v = hyfnext [v ];
	  } while ( ! ( v == 0 ) ) ;
	} 
	incr ( l ) ;
	z = trie [z ].v.RH + hc [l ];
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
  mem [hb ].hh .v.RH = 0 ;
  r = mem [ha ].hh .v.RH ;
  mem [ha ].hh .v.RH = 0 ;
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
  else if ( mem [ha ].hh.b0 == 6 ) {
      
    if ( mem [ha + 1 ].hh.b0 != hf ) 
    goto lab42 ;
    else {
	
      initlist = mem [ha + 1 ].hh .v.RH ;
      initlig = true ;
      initlft = ( mem [ha ].hh.b1 > 1 ) ;
      hu [0 ]= mem [ha + 1 ].hh.b1 ;
      if ( initlist == 0 ) {
	  
	if ( initlft ) 
	{
	  hu [0 ]= maxhyphchar ;
	  initlig = false ;
	} 
      } 
      freenode ( ha , 2 ) ;
    } 
  } 
  else {
      
    if ( ! ( r >= himemmin ) ) {
	
      if ( mem [r ].hh.b0 == 6 ) {
	  
	if ( mem [r ].hh.b1 > 1 ) 
	goto lab42 ;
      } 
    } 
    j = 1 ;
    s = ha ;
    initlist = 0 ;
    goto lab50 ;
  } 
  s = curp ;
  while ( mem [s ].hh .v.RH != ha ) s = mem [s ].hh .v.RH ;
  j = 0 ;
  goto lab50 ;
  lab42: s = ha ;
  j = 0 ;
  hu [0 ]= maxhyphchar ;
  initlig = false ;
  initlist = 0 ;
  lab50: flushnodelist ( r ) ;
  do {
      l = j ;
    j = reconstitute ( j , hn , bchar , hyfchar ) + 1 ;
    if ( hyphenpassed == 0 ) 
    {
      mem [s ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
      while ( mem [s ].hh .v.RH > 0 ) s = mem [s ].hh .v.RH ;
      if ( odd ( hyf [j - 1 ]) ) 
      {
	l = j ;
	hyphenpassed = j - 1 ;
	mem [memtop - 4 ].hh .v.RH = 0 ;
      } 
    } 
    if ( hyphenpassed > 0 ) 
    do {
	r = getnode ( 2 ) ;
      mem [r ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
      mem [r ].hh.b0 = 7 ;
      majortail = r ;
      rcount = 0 ;
      while ( mem [majortail ].hh .v.RH > 0 ) {
	  
	majortail = mem [majortail ].hh .v.RH ;
	incr ( rcount ) ;
      } 
      i = hyphenpassed ;
      hyf [i ]= 0 ;
      minortail = 0 ;
      mem [r + 1 ].hh .v.LH = 0 ;
      hyfnode = newcharacter ( hf , hyfchar ) ;
      if ( hyfnode != 0 ) 
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
	  
	l = reconstitute ( l , i , fonttables [hf ][ 19 ].cint , 65536L ) + 
	1 ;
	if ( mem [memtop - 4 ].hh .v.RH > 0 ) 
	{
	  if ( minortail == 0 ) 
	  mem [r + 1 ].hh .v.LH = mem [memtop - 4 ].hh .v.RH ;
	  else mem [minortail ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
	  minortail = mem [memtop - 4 ].hh .v.RH ;
	  while ( mem [minortail ].hh .v.RH > 0 ) minortail = mem [
	  minortail ].hh .v.RH ;
	} 
      } 
      if ( hyfnode != 0 ) 
      {
	hu [i ]= c ;
	l = i ;
	decr ( i ) ;
      } 
      minortail = 0 ;
      mem [r + 1 ].hh .v.RH = 0 ;
      cloc = 0 ;
      if ( fonttables [hf ][ 18 ].cint != 0 ) 
      {
	decr ( l ) ;
	c = hu [l ];
	cloc = l ;
	hu [l ]= maxhyphchar ;
      } 
      while ( l < j ) {
	  
	do {
	    l = reconstitute ( l , hn , bchar , 65536L ) + 1 ;
	  if ( cloc > 0 ) 
	  {
	    hu [cloc ]= c ;
	    cloc = 0 ;
	  } 
	  if ( mem [memtop - 4 ].hh .v.RH > 0 ) 
	  {
	    if ( minortail == 0 ) 
	    mem [r + 1 ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
	    else mem [minortail ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
	    minortail = mem [memtop - 4 ].hh .v.RH ;
	    while ( mem [minortail ].hh .v.RH > 0 ) minortail = mem [
	    minortail ].hh .v.RH ;
	  } 
	} while ( ! ( l >= j ) ) ;
	while ( l > j ) {
	    
	  j = reconstitute ( j , hn , bchar , 65536L ) + 1 ;
	  mem [majortail ].hh .v.RH = mem [memtop - 4 ].hh .v.RH ;
	  while ( mem [majortail ].hh .v.RH > 0 ) {
	      
	    majortail = mem [majortail ].hh .v.RH ;
	    incr ( rcount ) ;
	  } 
	} 
      } 
      if ( rcount > 127 ) 
      {
	mem [s ].hh .v.RH = mem [r ].hh .v.RH ;
	mem [r ].hh .v.RH = 0 ;
	flushnodelist ( r ) ;
      } 
      else {
	  
	mem [s ].hh .v.RH = r ;
	mem [r ].hh.b1 = rcount ;
      } 
      s = majortail ;
      hyphenpassed = j - 1 ;
      mem [memtop - 4 ].hh .v.RH = 0 ;
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
      else printnl ( 65548L ) ;
      print ( 65996L ) ;
    } 
    printcmdchr ( j , k ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 66708L ;
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
  printnl ( 65624L ) ;
  println () ;
  while ( true ) {
      
    printnl ( 65649L ) ;
    printgroup ( true ) ;
    if ( curgroup == 0 ) 
    goto lab30 ;
    do {
	m = nest [p ].modefield ;
      if ( p > 0 ) 
      decr ( p ) ;
      else m = 1 ;
    } while ( ! ( m != 119 ) ) ;
    print ( 65570L ) ;
    switch ( curgroup ) 
    {case 1 : 
      {
	incr ( p ) ;
	goto lab42 ;
      } 
      break ;
    case 2 : 
    case 3 : 
      s = 66418L ;
      break ;
    case 4 : 
      s = 66323L ;
      break ;
    case 5 : 
      s = 66417L ;
      break ;
    case 6 : 
      if ( a == 0 ) 
      {
	if ( m == -1 ) 
	s = 65815L ;
	else s = 65839L ;
	a = 1 ;
	goto lab41 ;
      } 
      else {
	  
	if ( a == 1 ) 
	print ( 66746L ) ;
	else printesc ( 66255L ) ;
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
	printesc ( 65825L ) ;
	goto lab42 ;
      } 
      break ;
    case 8 : 
      {
	printesc ( 65684L ) ;
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
	printesc ( 65635L ) ;
	else printesc ( 65823L ) ;
	{register integer for_end; i = 1 ;for_end = 3 ; if ( i <= for_end) 
	do 
	  if ( i <= savestack [saveptr - 2 ].cint ) 
	  print ( 66215L ) ;
	while ( i++ < for_end ) ;} 
	goto lab42 ;
      } 
      break ;
    case 11 : 
      {
	if ( savestack [saveptr - 2 ].cint == 255 ) 
	printesc ( 65638L ) ;
	else {
	    
	  printesc ( 65616L ) ;
	  printint ( savestack [saveptr - 2 ].cint ) ;
	} 
	goto lab42 ;
      } 
      break ;
    case 12 : 
      {
	s = 65840L ;
	goto lab41 ;
      } 
      break ;
    case 14 : 
      {
	incr ( p ) ;
	printesc ( 65802L ) ;
	goto lab40 ;
      } 
      break ;
    case 15 : 
      {
	if ( m == 237 ) 
	printchar ( 36 ) ;
	else if ( nest [p ].modefield == 237 ) 
	{
	  printcmdchr ( 48 , savestack [saveptr - 2 ].cint ) ;
	  goto lab40 ;
	} 
	printchar ( 36 ) ;
	goto lab40 ;
      } 
      break ;
    case 16 : 
      {
	if ( mem [nest [p + 1 ].eTeXauxfield ].hh.b0 == 30 ) 
	printesc ( 66231L ) ;
	else printesc ( 66233L ) ;
	goto lab40 ;
      } 
      break ;
    } 
    i = savestack [saveptr - 4 ].cint ;
    if ( i != 0 ) {
	
      if ( i < 1073741824L ) 
      {
	if ( abs ( nest [p ].modefield ) == 1 ) 
	j = 21 ;
	else j = 22 ;
	if ( i > 0 ) 
	printcmdchr ( j , 0 ) ;
	else printcmdchr ( j , 1 ) ;
	printscaled ( abs ( i ) ) ;
	print ( 65683L ) ;
      } 
      else if ( i < ( ( ( 1073807360L ) + 65536L ) + 1 ) ) 
      {
	if ( i >= ( 1073807360L ) ) 
	{
	  printesc ( 66534L ) ;
	  i = i - ( ( 1073807360L ) - 1073741824L ) ;
	} 
	printesc ( 65837L ) ;
	printint ( i - 1073741824L ) ;
	printchar ( 61 ) ;
      } 
      else printcmdchr ( 31 , i - ( ( ( ( 1073807360L ) + 65536L ) + 1 ) - 99 
      ) ) ;
    } 
    lab41: printesc ( s ) ;
    if ( savestack [saveptr - 2 ].cint != 0 ) 
    {
      printchar ( 32 ) ;
      if ( savestack [saveptr - 3 ].cint == 0 ) 
      print ( 66197L ) ;
      else print ( 66198L ) ;
      printscaled ( savestack [saveptr - 2 ].cint ) ;
      print ( 65683L ) ;
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
  while ( p != 0 ) switch ( mem [p ].hh.b0 ) 
  {case 0 : 
  case 1 : 
  case 2 : 
    {
      q = newskipparam ( 10 ) ;
      mem [prevp ].hh .v.RH = q ;
      mem [q ].hh .v.RH = p ;
      if ( mem [tempptr + 1 ].cint > mem [p + 3 ].cint ) 
      mem [tempptr + 1 ].cint = mem [tempptr + 1 ].cint - mem [p + 3 ]
      .cint ;
      else mem [tempptr + 1 ].cint = 0 ;
      p = 0 ;
    } 
    break ;
  case 8 : 
  case 4 : 
  case 3 : 
    {
      prevp = p ;
      p = mem [prevp ].hh .v.RH ;
    } 
    break ;
  case 10 : 
  case 11 : 
  case 12 : 
    {
      q = p ;
      p = mem [q ].hh .v.RH ;
      mem [q ].hh .v.RH = 0 ;
      mem [prevp ].hh .v.RH = p ;
      if ( s ) 
      {
	if ( discptr [3 ]== 0 ) 
	discptr [3 ]= q ;
	else mem [r ].hh .v.RH = q ;
	r = q ;
      } 
      else flushnodelist ( q ) ;
    } 
    break ;
    default: 
    confusion ( 66315L ) ;
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
      
    if ( p == 0 ) 
    pi = -10000 ;
    else switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 2 : 
      {
	activewidth [1 ]= activewidth [1 ]+ prevdp + mem [p + 3 ].cint ;
	prevdp = mem [p + 2 ].cint ;
	goto lab45 ;
      } 
      break ;
    case 8 : 
      goto lab45 ;
      break ;
    case 10 : 
      if ( ( mem [prevp ].hh.b0 < 9 ) ) 
      pi = 0 ;
      else goto lab90 ;
      break ;
    case 11 : 
      {
	if ( mem [p ].hh .v.RH == 0 ) 
	t = 12 ;
	else t = mem [mem [p ].hh .v.RH ].hh.b0 ;
	if ( t == 10 ) 
	pi = 0 ;
	else goto lab90 ;
      } 
      break ;
    case 12 : 
      pi = mem [p + 1 ].cint ;
      break ;
    case 4 : 
    case 3 : 
      goto lab45 ;
      break ;
      default: 
      confusion ( 66316L ) ;
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
    if ( ( mem [p ].hh.b0 < 10 ) || ( mem [p ].hh.b0 > 11 ) ) 
    goto lab45 ;
    lab90: if ( mem [p ].hh.b0 == 11 ) 
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
	  else printnl ( 65548L ) ;
	  print ( 66317L ) ;
	} 
	{
	  helpptr = 4 ;
	  helpline [3 ]= 66318L ;
	  helpline [2 ]= 66319L ;
	  helpline [1 ]= 66320L ;
	  helpline [0 ]= 66278L ;
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
  integer vdir  ;
  halfword p  ;
  halfword q  ;
  curval = n ;
  if ( curval < 65536L ) 
  v = newequiv ( 655423L + curval ) ;
  else {
      
    findsaelement ( 7 , curval , false ) ;
    if ( curptr == 0 ) 
    v = 0 ;
    else v = mem [curptr + 1 ].hh .v.RH ;
  } 
  vdir = mem [v + 7 ].cint ;
  flushnodelist ( discptr [3 ]) ;
  discptr [3 ]= 0 ;
  if ( samark != 0 ) {
      
    if ( domarks ( 0 , 0 , samark ) ) 
    samark = 0 ;
  } 
  if ( curmark [3 ]!= 0 ) 
  {
    deletetokenref ( curmark [3 ]) ;
    curmark [3 ]= 0 ;
    deletetokenref ( curmark [4 ]) ;
    curmark [4 ]= 0 ;
  } 
  if ( v == 0 ) 
  {
    Result = 0 ;
    return Result ;
  } 
  if ( mem [v ].hh.b0 != 1 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 65624L ) ;
    } 
    printesc ( 66321L ) ;
    print ( 66322L ) ;
    printesc ( 66323L ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 66324L ;
      helpline [0 ]= 66325L ;
    } 
    error () ;
    Result = 0 ;
    return Result ;
  } 
  q = vertbreak ( mem [v + 5 ].hh .v.RH , h , neweqtbsc ( 1180556L + ( 6 ) ) 
  ) ;
  p = mem [v + 5 ].hh .v.RH ;
  if ( p == q ) 
  mem [v + 5 ].hh .v.RH = 0 ;
  else while ( true ) {
      
    if ( mem [p ].hh.b0 == 4 ) {
	
      if ( mem [p + 1 ].hh .v.LH != 0 ) 
      {
	findsaelement ( 8 , mem [p + 1 ].hh .v.LH , true ) ;
	if ( mem [curptr + 2 ].hh .v.RH == 0 ) 
	{
	  mem [curptr + 2 ].hh .v.RH = mem [p + 1 ].hh .v.RH ;
	  incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
	} 
	else deletetokenref ( mem [curptr + 3 ].hh .v.LH ) ;
	mem [curptr + 3 ].hh .v.LH = mem [p + 1 ].hh .v.RH ;
	incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
      } 
      else if ( curmark [3 ]== 0 ) 
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
      mem [p ].hh .v.RH = 0 ;
      goto lab30 ;
    } 
    p = mem [p ].hh .v.RH ;
  } 
  lab30: ;
  q = prunepagetop ( q , neweqtbint ( 1049476L ) > 0 ) ;
  p = mem [v + 5 ].hh .v.RH ;
  freenode ( v , 8 ) ;
  packdirection = vdir ;
  if ( q != 0 ) 
  q = vpackage ( q , 0 , 1 , 1073741823L ) ;
  setequiv ( 655423L + curval , q ) ;
  Result = vpackage ( p , h , 0 , neweqtbsc ( 1180556L + ( 6 ) ) ) ;
  return Result ;
} 
void 
printtotals ( void ) 
{
  printtotals_regmem 
  printscaled ( pagesofar [1 ]) ;
  if ( pagesofar [2 ]!= 0 ) 
  {
    print ( 65598L ) ;
    printscaled ( pagesofar [2 ]) ;
    print ( 65624L ) ;
  } 
  if ( pagesofar [3 ]!= 0 ) 
  {
    print ( 65598L ) ;
    printscaled ( pagesofar [3 ]) ;
    print ( 66334L ) ;
  } 
  if ( pagesofar [4 ]!= 0 ) 
  {
    print ( 65598L ) ;
    printscaled ( pagesofar [4 ]) ;
    print ( 66335L ) ;
  } 
  if ( pagesofar [5 ]!= 0 ) 
  {
    print ( 65598L ) ;
    printscaled ( pagesofar [5 ]) ;
    print ( 66336L ) ;
  } 
  if ( pagesofar [6 ]!= 0 ) 
  {
    print ( 65599L ) ;
    printscaled ( pagesofar [6 ]) ;
  } 
} 
void 
zfreezepagespecs ( smallnumber s ) 
{
  freezepagespecs_regmem 
  pagecontents = s ;
  pagesofar [0 ]= neweqtbsc ( 1180556L + ( 4 ) ) ;
  pagemaxdepth = neweqtbsc ( 1180556L + ( 5 ) ) ;
  pagesofar [7 ]= 0 ;
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
  if ( neweqtbint ( 1049441L ) > 0 ) 
  {
    begindiagnostic () ;
    printnl ( 66344L ) ;
    printscaled ( pagesofar [0 ]) ;
    print ( 66345L ) ;
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
  printnl ( 66191L ) ;
  showbox ( newequiv ( 655423L + n ) ) ;
  enddiagnostic ( true ) ;
  flushnodelist ( newequiv ( 655423L + n ) ) ;
  setequiv ( 655423L + n , 0 ) ;
} 
void 
zensurevbox ( eightbits n ) 
{
  ensurevbox_regmem 
  halfword p  ;
  p = newequiv ( 655423L + n ) ;
  if ( p != 0 ) {
      
    if ( mem [p ].hh.b0 == 0 ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66346L ) ;
      } 
      {
	helpptr = 3 ;
	helpline [2 ]= 66347L ;
	helpline [1 ]= 66348L ;
	helpline [0 ]= 66349L ;
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
  unsigned short n  ;
  boolean wait  ;
  integer savevbadness  ;
  scaled savevfuzz  ;
  halfword savesplittopskip  ;
  if ( mem [bestpagebreak ].hh.b0 == 12 ) 
  {
    geqworddefine ( 1049447L , mem [bestpagebreak + 1 ].cint ) ;
    mem [bestpagebreak + 1 ].cint = 10000 ;
  } 
  else geqworddefine ( 1049447L , 10000 ) ;
  if ( samark != 0 ) {
      
    if ( domarks ( 1 , 0 , samark ) ) 
    samark = 0 ;
  } 
  if ( curmark [2 ]!= 0 ) 
  {
    if ( curmark [0 ]!= 0 ) 
    deletetokenref ( curmark [0 ]) ;
    curmark [0 ]= curmark [2 ];
    incr ( mem [curmark [0 ]].hh .v.LH ) ;
    deletetokenref ( curmark [1 ]) ;
    curmark [1 ]= 0 ;
  } 
  if ( c == bestpagebreak ) 
  bestpagebreak = 0 ;
  if ( newequiv ( 655678L ) != 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 65624L ) ;
    } 
    printesc ( 65695L ) ;
    print ( 66360L ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 66361L ;
      helpline [0 ]= 66349L ;
    } 
    boxerror ( 255 ) ;
  } 
  insertpenalties = 0 ;
  savesplittopskip = newequiv ( 393240L ) ;
  if ( neweqtbint ( 1049461L ) <= 0 ) 
  {
    r = mem [memtop ].hh .v.RH ;
    while ( r != memtop ) {
	
      if ( mem [r + 2 ].hh .v.LH != 0 ) 
      {
	n = mem [r ].hh.b1 ;
	ensurevbox ( n ) ;
	if ( newequiv ( 655423L + n ) == 0 ) 
	setequiv ( 655423L + n , newnullbox () ) ;
	p = newequiv ( 655423L + n ) + 5 ;
	while ( mem [p ].hh .v.RH != 0 ) p = mem [p ].hh .v.RH ;
	mem [r + 2 ].hh .v.RH = p ;
      } 
      r = mem [r ].hh .v.RH ;
    } 
  } 
  q = memtop - 4 ;
  mem [q ].hh .v.RH = 0 ;
  prevp = memtop - 2 ;
  p = mem [prevp ].hh .v.RH ;
  while ( p != bestpagebreak ) {
      
    if ( mem [p ].hh.b0 == 3 ) 
    {
      if ( neweqtbint ( 1049461L ) <= 0 ) 
      {
	r = mem [memtop ].hh .v.RH ;
	while ( mem [r ].hh.b1 != mem [p ].hh.b1 ) r = mem [r ].hh .v.RH 
	;
	if ( mem [r + 2 ].hh .v.LH == 0 ) 
	wait = true ;
	else {
	    
	  wait = false ;
	  s = mem [r + 2 ].hh .v.RH ;
	  mem [s ].hh .v.RH = mem [p + 4 ].hh .v.LH ;
	  if ( mem [r + 2 ].hh .v.LH == p ) 
	  {
	    if ( mem [r ].hh.b0 == 1 ) {
		
	      if ( ( mem [r + 1 ].hh .v.LH == p ) && ( mem [r + 1 ].hh 
	      .v.RH != 0 ) ) 
	      {
		while ( mem [s ].hh .v.RH != mem [r + 1 ].hh .v.RH ) s = 
		mem [s ].hh .v.RH ;
		mem [s ].hh .v.RH = 0 ;
		setequiv ( 393240L , mem [p + 4 ].hh .v.RH ) ;
		mem [p + 4 ].hh .v.LH = prunepagetop ( mem [r + 1 ].hh 
		.v.RH , false ) ;
		if ( mem [p + 4 ].hh .v.LH != 0 ) 
		{
		  tempptr = vpackage ( mem [p + 4 ].hh .v.LH , 0 , 1 , 
		  1073741823L ) ;
		  mem [p + 3 ].cint = mem [tempptr + 3 ].cint + mem [
		  tempptr + 2 ].cint ;
		  freenode ( tempptr , 8 ) ;
		  wait = true ;
		} 
	      } 
	    } 
	    mem [r + 2 ].hh .v.LH = 0 ;
	    n = mem [r ].hh.b1 ;
	    tempptr = mem [newequiv ( 655423L + n ) + 5 ].hh .v.RH ;
	    freenode ( newequiv ( 655423L + n ) , 8 ) ;
	    packdirection = neweqtbint ( 1049480L ) ;
	    setequiv ( 655423L + n , vpackage ( tempptr , 0 , 1 , 1073741823L 
	    ) ) ;
	  } 
	  else {
	      
	    while ( mem [s ].hh .v.RH != 0 ) s = mem [s ].hh .v.RH ;
	    mem [r + 2 ].hh .v.RH = s ;
	  } 
	} 
	mem [prevp ].hh .v.RH = mem [p ].hh .v.RH ;
	mem [p ].hh .v.RH = 0 ;
	if ( wait ) 
	{
	  mem [q ].hh .v.RH = p ;
	  q = p ;
	  incr ( insertpenalties ) ;
	} 
	else {
	    
	  deleteglueref ( mem [p + 4 ].hh .v.RH ) ;
	  freenode ( p , 5 ) ;
	} 
	p = prevp ;
      } 
    } 
    else if ( mem [p ].hh.b0 == 4 ) {
	
      if ( mem [p + 1 ].hh .v.LH != 0 ) 
      {
	findsaelement ( 8 , mem [p + 1 ].hh .v.LH , true ) ;
	if ( mem [curptr + 1 ].hh .v.RH == 0 ) 
	{
	  mem [curptr + 1 ].hh .v.RH = mem [p + 1 ].hh .v.RH ;
	  incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
	} 
	if ( mem [curptr + 2 ].hh .v.LH != 0 ) 
	deletetokenref ( mem [curptr + 2 ].hh .v.LH ) ;
	mem [curptr + 2 ].hh .v.LH = mem [p + 1 ].hh .v.RH ;
	incr ( mem [mem [p + 1 ].hh .v.RH ].hh .v.LH ) ;
      } 
      else {
	  
	if ( curmark [1 ]== 0 ) 
	{
	  curmark [1 ]= mem [p + 1 ].hh .v.RH ;
	  incr ( mem [curmark [1 ]].hh .v.LH ) ;
	} 
	if ( curmark [2 ]!= 0 ) 
	deletetokenref ( curmark [2 ]) ;
	curmark [2 ]= mem [p + 1 ].hh .v.RH ;
	incr ( mem [curmark [2 ]].hh .v.LH ) ;
      } 
    } 
    prevp = p ;
    p = mem [prevp ].hh .v.RH ;
  } 
  setequiv ( 393240L , savesplittopskip ) ;
  if ( p != 0 ) 
  {
    if ( mem [memtop - 1 ].hh .v.RH == 0 ) {
	
      if ( nestptr == 0 ) 
      curlist .tailfield = pagetail ;
      else nest [0 ].tailfield = pagetail ;
    } 
    mem [pagetail ].hh .v.RH = mem [memtop - 1 ].hh .v.RH ;
    mem [memtop - 1 ].hh .v.RH = p ;
    mem [prevp ].hh .v.RH = 0 ;
  } 
  savevbadness = neweqtbint ( 1049435L ) ;
  setneweqtbint ( 1049435L , 10000 ) ;
  savevfuzz = neweqtbsc ( 1180556L + ( 9 ) ) ;
  setneweqtbsc ( 1180565L , 1073741823L ) ;
  packdirection = neweqtbint ( 1049480L ) ;
  setequiv ( 655678L , vpackage ( mem [memtop - 2 ].hh .v.RH , bestsize , 0 
  , pagemaxdepth ) ) ;
  setneweqtbint ( 1049435L , savevbadness ) ;
  setneweqtbsc ( 1180565L , savevfuzz ) ;
  if ( lastglue != 1073741823L ) 
  deleteglueref ( lastglue ) ;
  pagecontents = 0 ;
  pagetail = memtop - 2 ;
  mem [memtop - 2 ].hh .v.RH = 0 ;
  lastglue = 1073741823L ;
  lastpenalty = 0 ;
  lastkern = 0 ;
  lastnodetype = -1 ;
  pagesofar [7 ]= 0 ;
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
  if ( samark != 0 ) {
      
    if ( domarks ( 2 , 0 , samark ) ) 
    samark = 0 ;
  } 
  if ( ( curmark [0 ]!= 0 ) && ( curmark [1 ]== 0 ) ) 
  {
    curmark [1 ]= curmark [0 ];
    incr ( mem [curmark [0 ]].hh .v.LH ) ;
  } 
  if ( newequiv ( 524325L ) != 0 ) {
      
    if ( deadcycles >= neweqtbint ( 1049448L ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66362L ) ;
      } 
      printint ( deadcycles ) ;
      print ( 66363L ) ;
      {
	helpptr = 3 ;
	helpline [2 ]= 66364L ;
	helpline [1 ]= 66365L ;
	helpline [0 ]= 66366L ;
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
      begintokenlist ( newequiv ( 524325L ) , 6 ) ;
      newsavelevel ( 8 ) ;
      normalparagraph () ;
      scanleftbrace () ;
      return ;
    } 
  } 
  {
    if ( mem [memtop - 2 ].hh .v.RH != 0 ) 
    {
      if ( mem [memtop - 1 ].hh .v.RH == 0 ) {
	  
	if ( nestptr == 0 ) 
	curlist .tailfield = pagetail ;
	else nest [0 ].tailfield = pagetail ;
      } 
      else mem [pagetail ].hh .v.RH = mem [memtop - 1 ].hh .v.RH ;
      mem [memtop - 1 ].hh .v.RH = mem [memtop - 2 ].hh .v.RH ;
      mem [memtop - 2 ].hh .v.RH = 0 ;
      pagetail = memtop - 2 ;
    } 
    flushnodelist ( discptr [2 ]) ;
    discptr [2 ]= 0 ;
    shipout ( newequiv ( 655678L ) ) ;
    setequiv ( 655678L , 0 ) ;
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
  unsigned short n  ;
  scaled delta, h, w  ;
  if ( ( mem [memtop - 1 ].hh .v.RH == 0 ) || outputactive ) 
  return ;
  do {
      lab22: p = mem [memtop - 1 ].hh .v.RH ;
    if ( lastglue != 1073741823L ) 
    deleteglueref ( lastglue ) ;
    lastpenalty = 0 ;
    lastkern = 0 ;
    lastnodetype = mem [p ].hh.b0 + 1 ;
    if ( mem [p ].hh.b0 == 10 ) 
    {
      lastglue = mem [p + 1 ].hh .v.LH ;
      incr ( mem [lastglue ].hh .v.RH ) ;
    } 
    else {
	
      lastglue = 1073741823L ;
      if ( mem [p ].hh.b0 == 12 ) 
      lastpenalty = mem [p + 1 ].cint ;
      else if ( mem [p ].hh.b0 == 11 ) 
      lastkern = mem [p + 1 ].cint ;
    } 
    switch ( mem [p ].hh.b0 ) 
    {case 0 : 
    case 1 : 
    case 2 : 
      if ( pagecontents < 2 ) 
      {
	if ( pagecontents == 0 ) 
	freezepagespecs ( 2 ) ;
	else pagecontents = 2 ;
	q = newskipparam ( 9 ) ;
	if ( ( mem [p ].hh.b0 == 0 ) && ( ( ( ( dirprimary [neweqtbint ( 
	1049480L ) ]) + 2 ) % 4 ) == ( ( dirtertiary [neweqtbint ( 1049480L 
	) ]) % 4 ) ) ) 
	{
	  if ( mem [tempptr + 1 ].cint > mem [p + 2 ].cint ) 
	  mem [tempptr + 1 ].cint = mem [tempptr + 1 ].cint - mem [p + 2 
	  ].cint ;
	  else mem [tempptr + 1 ].cint = 0 ;
	} 
	else {
	    
	  if ( mem [tempptr + 1 ].cint > mem [p + 3 ].cint ) 
	  mem [tempptr + 1 ].cint = mem [tempptr + 1 ].cint - mem [p + 3 
	  ].cint ;
	  else mem [tempptr + 1 ].cint = 0 ;
	} 
	mem [q ].hh .v.RH = p ;
	mem [memtop - 1 ].hh .v.RH = q ;
	goto lab22 ;
      } 
      else {
	  
	if ( ( mem [p ].hh.b0 == 0 ) && ( ( ( ( dirprimary [neweqtbint ( 
	1049480L ) ]) + 2 ) % 4 ) == ( ( dirtertiary [neweqtbint ( 1049480L 
	) ]) % 4 ) ) ) 
	{
	  pagesofar [1 ]= pagesofar [1 ]+ pagesofar [7 ]+ mem [p + 2 ]
	  .cint ;
	  pagesofar [7 ]= mem [p + 3 ].cint ;
	} 
	else {
	    
	  pagesofar [1 ]= pagesofar [1 ]+ pagesofar [7 ]+ mem [p + 3 ]
	  .cint ;
	  pagesofar [7 ]= mem [p + 2 ].cint ;
	} 
	goto lab80 ;
      } 
      break ;
    case 8 : 
      goto lab80 ;
      break ;
    case 10 : 
      if ( pagecontents < 2 ) 
      goto lab31 ;
      else if ( ( mem [pagetail ].hh.b0 < 9 ) ) 
      pi = 0 ;
      else goto lab90 ;
      break ;
    case 11 : 
      if ( pagecontents < 2 ) 
      goto lab31 ;
      else if ( mem [p ].hh .v.RH == 0 ) 
      return ;
      else if ( mem [mem [p ].hh .v.RH ].hh.b0 == 10 ) 
      pi = 0 ;
      else goto lab90 ;
      break ;
    case 12 : 
      if ( pagecontents < 2 ) 
      goto lab31 ;
      else pi = mem [p + 1 ].cint ;
      break ;
    case 4 : 
      goto lab80 ;
      break ;
    case 3 : 
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
	  if ( newequiv ( 655423L + n ) == 0 ) 
	  mem [r + 3 ].cint = 0 ;
	  else mem [r + 3 ].cint = mem [newequiv ( 655423L + n ) + 3 ]
	  .cint + mem [newequiv ( 655423L + n ) + 2 ].cint ;
	  mem [r + 2 ].hh .v.LH = 0 ;
	  q = newequiv ( 393248L + n ) ;
	  if ( neweqtbint ( 1049484L + n ) == 1000 ) 
	  h = mem [r + 3 ].cint ;
	  else h = xovern ( mem [r + 3 ].cint , 1000 ) * neweqtbint ( 
	  1049484L + n ) ;
	  pagesofar [0 ]= pagesofar [0 ]- h - mem [q + 1 ].cint ;
	  pagesofar [2 + mem [q ].hh.b0 ]= pagesofar [2 + mem [q ]
	  .hh.b0 ]+ mem [q + 2 ].cint ;
	  pagesofar [6 ]= pagesofar [6 ]+ mem [q + 3 ].cint ;
	  if ( ( mem [q ].hh.b1 != 0 ) && ( mem [q + 3 ].cint != 0 ) ) 
	  {
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 65548L ) ;
	      print ( 66355L ) ;
	    } 
	    printesc ( 65681L ) ;
	    printint ( n ) ;
	    {
	      helpptr = 3 ;
	      helpline [2 ]= 66356L ;
	      helpline [1 ]= 66357L ;
	      helpline [0 ]= 66278L ;
	    } 
	    error () ;
	  } 
	} 
	if ( mem [r ].hh.b0 == 1 ) 
	insertpenalties = insertpenalties + mem [p + 1 ].cint ;
	else {
	    
	  mem [r + 2 ].hh .v.RH = p ;
	  delta = pagesofar [0 ]- pagesofar [1 ]- pagesofar [7 ]+ 
	  pagesofar [6 ];
	  if ( neweqtbint ( 1049484L + n ) == 1000 ) 
	  h = mem [p + 3 ].cint ;
	  else h = xovern ( mem [p + 3 ].cint , 1000 ) * neweqtbint ( 
	  1049484L + n ) ;
	  if ( ( ( h <= 0 ) || ( h <= delta ) ) && ( mem [p + 3 ].cint + mem 
	  [r + 3 ].cint <= neweqtbsc ( 1180581L + ( n ) ) ) ) 
	  {
	    pagesofar [0 ]= pagesofar [0 ]- h ;
	    mem [r + 3 ].cint = mem [r + 3 ].cint + mem [p + 3 ].cint ;
	  } 
	  else {
	      
	    if ( neweqtbint ( 1049484L + n ) <= 0 ) 
	    w = 1073741823L ;
	    else {
		
	      w = pagesofar [0 ]- pagesofar [1 ]- pagesofar [7 ];
	      if ( neweqtbint ( 1049484L + n ) != 1000 ) 
	      w = xovern ( w , neweqtbint ( 1049484L + n ) ) * 1000 ;
	    } 
	    if ( w > neweqtbsc ( 1180581L + ( n ) ) - mem [r + 3 ].cint ) 
	    w = neweqtbsc ( 1180581L + ( n ) ) - mem [r + 3 ].cint ;
	    q = vertbreak ( mem [p + 4 ].hh .v.LH , w , mem [p + 2 ].cint 
	    ) ;
	    mem [r + 3 ].cint = mem [r + 3 ].cint + bestheightplusdepth ;
	;
#ifdef STAT
	    if ( neweqtbint ( 1049441L ) > 0 ) 
	    {
	      begindiagnostic () ;
	      printnl ( 66358L ) ;
	      printint ( n ) ;
	      print ( 66359L ) ;
	      printscaled ( w ) ;
	      printchar ( 44 ) ;
	      printscaled ( bestheightplusdepth ) ;
	      print ( 66287L ) ;
	      if ( q == 0 ) 
	      printint ( -10000 ) ;
	      else if ( mem [q ].hh.b0 == 12 ) 
	      printint ( mem [q + 1 ].cint ) ;
	      else printchar ( 48 ) ;
	      enddiagnostic ( false ) ;
	    } 
#endif /* STAT */
	    if ( neweqtbint ( 1049484L + n ) != 1000 ) 
	    bestheightplusdepth = xovern ( bestheightplusdepth , 1000 ) * 
	    neweqtbint ( 1049484L + n ) ;
	    pagesofar [0 ]= pagesofar [0 ]- bestheightplusdepth ;
	    mem [r ].hh.b0 = 1 ;
	    mem [r + 1 ].hh .v.RH = q ;
	    mem [r + 1 ].hh .v.LH = p ;
	    if ( q == 0 ) 
	    insertpenalties = insertpenalties - 10000 ;
	    else if ( mem [q ].hh.b0 == 12 ) 
	    insertpenalties = insertpenalties + mem [q + 1 ].cint ;
	  } 
	} 
	goto lab80 ;
      } 
      break ;
      default: 
      confusion ( 66350L ) ;
      break ;
    } 
    if ( pi < 10000 ) 
    {
      if ( pagesofar [1 ]< pagesofar [0 ]) {
	  
	if ( ( pagesofar [3 ]!= 0 ) || ( pagesofar [4 ]!= 0 ) || ( 
	pagesofar [5 ]!= 0 ) ) 
	b = 0 ;
	else b = badness ( pagesofar [0 ]- pagesofar [1 ], pagesofar [2 ]
	) ;
      } 
      else if ( pagesofar [1 ]- pagesofar [0 ]> pagesofar [6 ]) 
      b = 1073741823L ;
      else b = badness ( pagesofar [1 ]- pagesofar [0 ], pagesofar [6 ]) 
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
      if ( neweqtbint ( 1049441L ) > 0 ) 
      {
	begindiagnostic () ;
	printnl ( 37 ) ;
	print ( 66283L ) ;
	printtotals () ;
	print ( 66353L ) ;
	printscaled ( pagesofar [0 ]) ;
	print ( 66286L ) ;
	if ( b == 1073741823L ) 
	printchar ( 42 ) ;
	else printint ( b ) ;
	print ( 66287L ) ;
	printint ( pi ) ;
	print ( 66354L ) ;
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
    if ( ( mem [p ].hh.b0 < 10 ) || ( mem [p ].hh.b0 > 11 ) ) 
    goto lab80 ;
    lab90: if ( mem [p ].hh.b0 == 11 ) 
    q = p ;
    else {
	
      q = mem [p + 1 ].hh .v.LH ;
      pagesofar [2 + mem [q ].hh.b0 ]= pagesofar [2 + mem [q ].hh.b0 ]
      + mem [q + 2 ].cint ;
      pagesofar [6 ]= pagesofar [6 ]+ mem [q + 3 ].cint ;
      if ( ( mem [q ].hh.b1 != 0 ) && ( mem [q + 3 ].cint != 0 ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66351L ) ;
	} 
	{
	  helpptr = 4 ;
	  helpline [3 ]= 66352L ;
	  helpline [2 ]= 66319L ;
	  helpline [1 ]= 66320L ;
	  helpline [0 ]= 66278L ;
	} 
	error () ;
	r = newspec ( q ) ;
	mem [r ].hh.b1 = 0 ;
	deleteglueref ( q ) ;
	mem [p + 1 ].hh .v.LH = r ;
	q = r ;
      } 
    } 
    pagesofar [1 ]= pagesofar [1 ]+ pagesofar [7 ]+ mem [q + 1 ].cint 
    ;
    pagesofar [7 ]= 0 ;
    lab80: if ( pagesofar [7 ]> pagemaxdepth ) 
    {
      pagesofar [1 ]= pagesofar [1 ]+ pagesofar [7 ]- pagemaxdepth ;
      pagesofar [7 ]= pagemaxdepth ;
    } 
    mem [pagetail ].hh .v.RH = p ;
    pagetail = p ;
    mem [memtop - 1 ].hh .v.RH = mem [p ].hh .v.RH ;
    mem [p ].hh .v.RH = 0 ;
    goto lab30 ;
    lab31: mem [memtop - 1 ].hh .v.RH = mem [p ].hh .v.RH ;
    mem [p ].hh .v.RH = 0 ;
    if ( neweqtbint ( 1049476L ) > 0 ) 
    {
      if ( discptr [2 ]== 0 ) 
      discptr [2 ]= p ;
      else mem [discptr [1 ]].hh .v.RH = p ;
      discptr [1 ]= p ;
    } 
    else flushnodelist ( p ) ;
    lab30: ;
  } while ( ! ( mem [memtop - 1 ].hh .v.RH == 0 ) ) ;
  if ( nestptr == 0 ) 
  curlist .tailfield = memtop - 1 ;
  else nest [0 ].tailfield = memtop - 1 ;
} 
void 
appspace ( void ) 
{
  appspace_regmem 
  halfword q  ;
  if ( ( curlist .auxfield .hh .v.LH >= 2000 ) && ( newequiv ( 393243L ) != 
  membot ) ) 
  q = newparamglue ( 13 ) ;
  else {
      
    if ( newequiv ( 393242L ) != membot ) 
    mainp = newequiv ( 393242L ) ;
    else {
	
      mainp = fonttables [newequiv ( 720959L ) ][ 14 ].cint ;
      if ( mainp == 0 ) 
      {
	mainp = newspec ( membot ) ;
	maink = fonttables [newequiv ( 720959L ) ][ 43 ].cint + 2 ;
	mem [mainp + 1 ].cint = fonttables [newequiv ( 720959L ) ][ maink ]
	.cint ;
	mem [mainp + 2 ].cint = fonttables [newequiv ( 720959L ) ][ maink + 
	1 ].cint ;
	mem [mainp + 3 ].cint = fonttables [newequiv ( 720959L ) ][ maink + 
	2 ].cint ;
	fonttables [newequiv ( 720959L ) ][ 14 ].cint = mainp ;
      } 
    } 
    mainp = newspec ( mainp ) ;
    if ( curlist .auxfield .hh .v.LH >= 2000 ) 
    mem [mainp + 1 ].cint = mem [mainp + 1 ].cint + fonttables [newequiv 
    ( 720959L ) ][ fonttables [newequiv ( 720959L ) ][ 43 ].cint + 7 ].cint 
    ;
    mem [mainp + 2 ].cint = xnoverd ( mem [mainp + 2 ].cint , curlist 
    .auxfield .hh .v.LH , 1000 ) ;
    mem [mainp + 3 ].cint = xnoverd ( mem [mainp + 3 ].cint , 1000 , 
    curlist .auxfield .hh .v.LH ) ;
    q = newglue ( mainp ) ;
    mem [mainp ].hh .v.RH = 0 ;
  } 
  mem [curlist .tailfield ].hh .v.RH = q ;
  curlist .tailfield = q ;
} 
void 
insertdollarsign ( void ) 
{
  insertdollarsign_regmem 
  backinput () ;
  curtok = 196644L ;
  {
    if ( interaction == 3 ) 
    ;
    if ( filelineerrorstylep ) 
    printfileline () ;
    else printnl ( 65548L ) ;
    print ( 66374L ) ;
  } 
  {
    helpptr = 2 ;
    helpline [1 ]= 66375L ;
    helpline [0 ]= 66376L ;
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
    else printnl ( 65548L ) ;
    print ( 66002L ) ;
  } 
  printcmdchr ( curcmd , curchr ) ;
  print ( 66377L ) ;
  printmode ( curlist .modefield ) ;
} 
void 
reportillegalcase ( void ) 
{
  reportillegalcase_regmem 
  youcant () ;
  {
    helpptr = 4 ;
    helpline [3 ]= 66378L ;
    helpline [2 ]= 66379L ;
    helpline [1 ]= 66380L ;
    helpline [0 ]= 66381L ;
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
    mem [curlist .tailfield + 1 ].cint = neweqtbsc ( 1180556L + ( 3 ) ) ;
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
    curval = membot + 8 ;
    break ;
  case 1 : 
    curval = membot + 12 ;
    break ;
  case 2 : 
    curval = membot + 16 ;
    break ;
  case 3 : 
    curval = membot + 20 ;
    break ;
  case 4 : 
    scanglue ( 2 ) ;
    break ;
  case 5 : 
    scanglue ( 3 ) ;
    break ;
  } 
  {
    mem [curlist .tailfield ].hh .v.RH = newglue ( curval ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  if ( s >= 4 ) 
  {
    decr ( mem [curval ].hh .v.RH ) ;
    if ( s > 4 ) 
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
  {
    mem [curlist .tailfield ].hh .v.RH = newkern ( curval ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  mem [curlist .tailfield ].hh.b1 = s ;
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
      else printnl ( 65548L ) ;
      print ( 66104L ) ;
    } 
    printcmdchr ( curcmd , curchr ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 66400L ;
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
      else printnl ( 65548L ) ;
      print ( 65934L ) ;
    } 
    switch ( curgroup ) 
    {case 14 : 
      {
	mem [p ].hh .v.LH = 1245187L ;
	printesc ( 65807L ) ;
      } 
      break ;
    case 15 : 
      {
	mem [p ].hh .v.LH = 196644L ;
	printchar ( 36 ) ;
      } 
      break ;
    case 16 : 
      {
	mem [p ].hh .v.LH = 1245188L ;
	mem [p ].hh .v.RH = getavail () ;
	p = mem [p ].hh .v.RH ;
	mem [p ].hh .v.LH = 786478L ;
	printesc ( 66399L ) ;
      } 
      break ;
      default: 
      {
	mem [p ].hh .v.LH = 131197L ;
	printchar ( 125 ) ;
      } 
      break ;
    } 
    print ( 65935L ) ;
    begintokenlist ( mem [memtop - 3 ].hh .v.RH , 4 ) ;
    {
      helpptr = 5 ;
      helpline [4 ]= 66394L ;
      helpline [3 ]= 66395L ;
      helpline [2 ]= 66396L ;
      helpline [1 ]= 66397L ;
      helpline [0 ]= 66398L ;
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
    else printnl ( 65548L ) ;
    print ( 66405L ) ;
  } 
  switch ( curgroup ) 
  {case 14 : 
    printesc ( 65807L ) ;
    break ;
  case 15 : 
    printchar ( 36 ) ;
    break ;
  case 16 : 
    printesc ( 66232L ) ;
    break ;
  } 
  {
    helpptr = 5 ;
    helpline [4 ]= 66406L ;
    helpline [3 ]= 66407L ;
    helpline [2 ]= 66408L ;
    helpline [1 ]= 66409L ;
    helpline [0 ]= 66410L ;
  } 
  error () ;
  incr ( alignstate ) ;
} 
void 
normalparagraph ( void ) 
{
  normalparagraph_regmem 
  if ( neweqtbint ( 1049427L ) != 0 ) 
  eqworddefine ( 1049427L , 0 ) ;
  if ( neweqtbsc ( 1180556L + ( 17 ) ) != 0 ) 
  eqworddefine ( 1180573L , 0 ) ;
  if ( neweqtbint ( 1049449L ) != 1 ) 
  eqworddefine ( 1049449L , 1 ) ;
  if ( newequiv ( 524320L ) != 0 ) 
  eqdefine ( 524320L , 135 , 0 ) ;
  if ( newequiv ( 524321L ) != 0 ) 
  eqdefine ( 524321L , 135 , 0 ) ;
} 
void 
zboxend ( integer boxcontext ) 
{
  boxend_regmem 
  halfword p  ;
  if ( boxcontext < 1073741824L ) 
  {
    if ( curbox != 0 ) 
    {
      mem [curbox + 4 ].cint = boxcontext ;
      if ( abs ( curlist .modefield ) == 1 ) 
      {
	appendtovlist ( curbox ) ;
	if ( adjusttail != 0 ) 
	{
	  if ( memtop - 5 != adjusttail ) 
	  {
	    mem [curlist .tailfield ].hh .v.RH = mem [memtop - 5 ].hh 
	    .v.RH ;
	    curlist .tailfield = adjusttail ;
	  } 
	  adjusttail = 0 ;
	} 
	if ( curlist .modefield > 0 ) 
	buildpage () ;
      } 
      else {
	  
	if ( abs ( curlist .modefield ) == 119 ) 
	curlist .auxfield .hh .v.LH = 1000 ;
	else {
	    
	  p = newnoad () ;
	  mem [p + 1 ].hh .v.RH = 2 ;
	  mem [p + 1 ].hh .v.LH = curbox ;
	  curbox = p ;
	} 
	mem [curlist .tailfield ].hh .v.RH = curbox ;
	curlist .tailfield = curbox ;
      } 
    } 
  } 
  else if ( boxcontext < ( ( ( 1073807360L ) + 65536L ) + 1 ) ) {
      
    if ( boxcontext < ( 1073807360L ) ) 
    eqdefine ( 655423L + boxcontext - 1073741824L , 136 , curbox ) ;
    else geqdefine ( 655423L + boxcontext - ( 1073807360L ) , 136 , curbox ) ;
  } 
  else if ( curbox != 0 ) {
      
    if ( boxcontext > ( ( ( 1073807360L ) + 65536L ) + 1 ) ) 
    {
      do {
	  getxtoken () ;
      } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
      if ( ( ( curcmd == 26 ) && ( abs ( curlist .modefield ) != 1 ) ) || ( ( 
      curcmd == 27 ) && ( abs ( curlist .modefield ) == 1 ) ) ) 
      {
	appendglue () ;
	mem [curlist .tailfield ].hh.b1 = boxcontext - ( ( ( ( 1073807360L ) 
	+ 65536L ) + 1 ) - 99 ) ;
	mem [curlist .tailfield + 1 ].hh .v.RH = curbox ;
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66424L ) ;
	} 
	{
	  helpptr = 3 ;
	  helpline [2 ]= 66425L ;
	  helpline [1 ]= 66426L ;
	  helpline [0 ]= 66427L ;
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
  quarterword m  ;
  halfword k  ;
  eightbits n  ;
  switch ( curchr ) 
  {case 0 : 
    {
      scaneightbitint () ;
      curbox = newequiv ( 655423L + curval ) ;
      setequiv ( 655423L + curval , 0 ) ;
    } 
    break ;
  case 1 : 
    {
      scaneightbitint () ;
      curbox = copynodelist ( newequiv ( 655423L + curval ) ) ;
    } 
    break ;
  case 2 : 
    {
      curbox = 0 ;
      if ( abs ( curlist .modefield ) == 237 ) 
      {
	youcant () ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 66428L ;
	} 
	error () ;
      } 
      else if ( ( curlist .modefield == 1 ) && ( curlist .headfield == curlist 
      .tailfield ) ) 
      {
	youcant () ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66429L ;
	  helpline [0 ]= 66430L ;
	} 
	error () ;
      } 
      else {
	  
	if ( ! ( curlist .tailfield >= himemmin ) ) {
	    
	  if ( ( mem [curlist .tailfield ].hh.b0 == 0 ) || ( mem [curlist 
	  .tailfield ].hh.b0 == 1 ) ) 
	  {
	    q = curlist .headfield ;
	    do {
		p = q ;
	      if ( ! ( q >= himemmin ) ) {
		  
		if ( mem [q ].hh.b0 == 7 ) 
		{
		  {register integer for_end; m = 1 ;for_end = mem [q ]
		  .hh.b1 ; if ( m <= for_end) do 
		    p = mem [p ].hh .v.RH ;
		  while ( m++ < for_end ) ;} 
		  if ( p == curlist .tailfield ) 
		  goto lab30 ;
		} 
	      } 
	      q = mem [p ].hh .v.RH ;
	    } while ( ! ( q == curlist .tailfield ) ) ;
	    curbox = curlist .tailfield ;
	    mem [curbox + 4 ].cint = 0 ;
	    curlist .tailfield = p ;
	    mem [p ].hh .v.RH = 0 ;
	    lab30: ;
	  } 
	} 
      } 
    } 
    break ;
  case 3 : 
    {
      scaneightbitint () ;
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
	  helpline [1 ]= 66432L ;
	  helpline [0 ]= 66433L ;
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
      switch ( abs ( curlist .modefield ) ) 
      {case 1 : 
	specdirection = neweqtbint ( 1049480L ) ;
	break ;
      case 119 : 
	specdirection = neweqtbint ( 1049482L ) ;
	break ;
      case 237 : 
	specdirection = neweqtbint ( 1049483L ) ;
	break ;
      } 
      if ( k == 119 ) {
	  
	if ( ( boxcontext < 1073741824L ) && ( abs ( curlist .modefield ) == 1 
	) ) 
	scanspec ( 3 , true ) ;
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
      if ( k == 1 ) 
      {
	curlist .auxfield .cint = -65536000L ;
	if ( newequiv ( 524330L ) != 0 ) 
	begintokenlist ( newequiv ( 524330L ) , 11 ) ;
      } 
      else {
	  
	curlist .auxfield .hh .v.LH = 1000 ;
	if ( newequiv ( 524329L ) != 0 ) 
	begintokenlist ( newequiv ( 524329L ) , 10 ) ;
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
  if ( curcmd == 20 ) 
  beginbox ( boxcontext ) ;
  else if ( ( boxcontext >= ( ( ( 1073807360L ) + 65536L ) + 1 ) + 1 ) && ( ( 
  curcmd == 36 ) || ( curcmd == 35 ) ) ) 
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
      else printnl ( 65548L ) ;
      print ( 66434L ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 66435L ;
      helpline [1 ]= 66436L ;
      helpline [0 ]= 66437L ;
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
  d = neweqtbsc ( 1180556L + ( 7 ) ) ;
  unsave () ;
  saveptr = saveptr - 5 ;
  packdirection = savestack [saveptr + 3 ].cint ;
  if ( curlist .modefield == -119 ) 
  curbox = hpack ( mem [curlist .headfield ].hh .v.RH , savestack [saveptr 
  + 2 ].cint , savestack [saveptr + 1 ].cint ) ;
  else {
      
    curbox = vpackage ( mem [curlist .headfield ].hh .v.RH , savestack [
    saveptr + 2 ].cint , savestack [saveptr + 1 ].cint , d ) ;
    if ( c == 4 ) 
    {
      h = 0 ;
      p = mem [curbox + 5 ].hh .v.RH ;
      if ( p != 0 ) {
	  
	if ( mem [p ].hh.b0 <= 2 ) 
	h = mem [p + 3 ].cint ;
      } 
      mem [curbox + 2 ].cint = mem [curbox + 2 ].cint - h + mem [curbox + 
      3 ].cint ;
      mem [curbox + 3 ].cint = h ;
    } 
  } 
  if ( savestack [saveptr + 4 ].cint != 0 ) 
  {
    flushnodelist ( textdirptr ) ;
    textdirptr = savestack [saveptr + 4 ].cint ;
  } 
  popnest () ;
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
  halfword p, q, dirgraftmp  ;
  curlist .pgfield = 0 ;
  if ( ( curlist .modefield == 1 ) || ( curlist .headfield != curlist 
  .tailfield ) ) 
  {
    mem [curlist .tailfield ].hh .v.RH = newparamglue ( 2 ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  pushnest () ;
  curlist .modefield = 119 ;
  curlist .auxfield .hh .v.LH = 1000 ;
  if ( neweqtbint ( 1049458L ) <= 0 ) 
  curlang = 0 ;
  else if ( neweqtbint ( 1049458L ) > 255 ) 
  curlang = 0 ;
  else curlang = neweqtbint ( 1049458L ) ;
  curlist .auxfield .hh .v.RH = curlang ;
  curlist .pgfield = ( normmin ( neweqtbint ( 1049459L ) ) * 64 + normmin ( 
  neweqtbint ( 1049460L ) ) ) * 65536L + curlang ;
  {
    {
      mem [curlist .tailfield ].hh .v.RH = makelocalparnode () ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
  } 
  if ( indented ) 
  {
    p = newnullbox () ;
    mem [p + 7 ].cint = neweqtbint ( 1049481L ) ;
    mem [p + 1 ].cint = neweqtbsc ( 1180556L + ( 0 ) ) ;
    {
      mem [curlist .tailfield ].hh .v.RH = p ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    if ( ( insertsrcspecialeverypar ) ) 
    insertsrcspecial () ;
  } 
  q = curlist .tailfield ;
  dirrover = textdirptr ;
  while ( dirrover != 0 ) {
      
    if ( ( mem [dirrover ].hh .v.RH != 0 ) || ( mem [dirrover + 1 ].hh 
    .v.LH != neweqtbint ( 1049481L ) ) ) 
    {
      dirgraftmp = newdir ( mem [dirrover + 1 ].hh .v.LH ) ;
      mem [dirgraftmp ].hh .v.RH = mem [q ].hh .v.RH ;
      mem [q ].hh .v.RH = dirgraftmp ;
    } 
    dirrover = mem [dirrover ].hh .v.RH ;
  } 
  q = curlist .headfield ;
  while ( mem [q ].hh .v.RH != 0 ) q = mem [q ].hh .v.RH ;
  curlist .tailfield = q ;
  if ( newequiv ( 524326L ) != 0 ) 
  begintokenlist ( newequiv ( 524326L ) , 7 ) ;
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
    mem [p + 1 ].cint = neweqtbsc ( 1180556L + ( 0 ) ) ;
    if ( abs ( curlist .modefield ) == 119 ) 
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
      
    if ( curcmd != 36 ) 
    offsave () ;
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66002L ) ;
      } 
      printesc ( 65816L ) ;
      print ( 66440L ) ;
      {
	helpptr = 2 ;
	helpline [1 ]= 66441L ;
	helpline [0 ]= 66442L ;
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
  if ( curlist .modefield == 119 ) 
  {
    if ( ( curlist .headfield == curlist .tailfield ) || ( mem [curlist 
    .headfield ].hh .v.RH == curlist .tailfield ) ) 
    popnest () ;
    else linebreak ( neweqtbint ( 1049414L ) ) ;
    if ( curlist .dirsfield != 0 ) 
    {
      flushnodelist ( curlist .dirsfield ) ;
      curlist .dirsfield = 0 ;
    } 
    normalparagraph () ;
    errorcount = 0 ;
  } 
} 
void 
begininsertoradjust ( void ) 
{
  begininsertoradjust_regmem 
  if ( curcmd == 38 ) 
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
	else printnl ( 65548L ) ;
	print ( 66443L ) ;
      } 
      printesc ( 65616L ) ;
      printint ( 255 ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 66444L ;
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
  mem [p ].hh.b0 = 4 ;
  mem [p ].hh.b1 = 0 ;
  mem [p + 1 ].hh .v.RH = defref ;
  mem [curlist .tailfield ].hh .v.RH = p ;
  curlist .tailfield = p ;
} 
void 
appendpenalty ( void ) 
{
  appendpenalty_regmem 
  scanint () ;
  {
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
  quarterword m  ;
  if ( ( curlist .modefield == 1 ) && ( curlist .tailfield == curlist 
  .headfield ) ) 
  {
    if ( ( curchr != 10 ) || ( lastglue != 1073741823L ) ) 
    {
      youcant () ;
      {
	helpptr = 2 ;
	helpline [1 ]= 66429L ;
	helpline [0 ]= 66445L ;
      } 
      if ( curchr == 11 ) 
      helpline [0 ]= ( 66446L ) ;
      else if ( curchr != 10 ) 
      helpline [0 ]= ( 66447L ) ;
      error () ;
    } 
  } 
  else {
      
    if ( ! ( curlist .tailfield >= himemmin ) ) {
	
      if ( mem [curlist .tailfield ].hh.b0 == curchr ) 
      {
	q = curlist .headfield ;
	do {
	    p = q ;
	  if ( ! ( q >= himemmin ) ) {
	      
	    if ( mem [q ].hh.b0 == 7 ) 
	    {
	      {register integer for_end; m = 1 ;for_end = mem [q ].hh.b1 
	      ; if ( m <= for_end) do 
		p = mem [p ].hh .v.RH ;
	      while ( m++ < for_end ) ;} 
	      if ( p == curlist .tailfield ) 
	      return ;
	    } 
	  } 
	  q = mem [p ].hh .v.RH ;
	} while ( ! ( q == curlist .tailfield ) ) ;
	mem [p ].hh .v.RH = 0 ;
	flushnodelist ( curlist .tailfield ) ;
	curlist .tailfield = p ;
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
  if ( curchr > 1 ) 
  {
    mem [curlist .tailfield ].hh .v.RH = discptr [curchr ];
    discptr [curchr ]= 0 ;
    goto lab30 ;
  } 
  c = curchr ;
  scaneightbitint () ;
  p = newequiv ( 655423L + curval ) ;
  if ( p == 0 ) 
  return ;
  if ( ( abs ( curlist .modefield ) == 237 ) || ( ( abs ( curlist .modefield ) 
  == 1 ) && ( mem [p ].hh.b0 != 1 ) ) || ( ( abs ( curlist .modefield ) == 
  119 ) && ( mem [p ].hh.b0 != 0 ) ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66455L ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 66456L ;
      helpline [1 ]= 66457L ;
      helpline [0 ]= 66458L ;
    } 
    error () ;
    return ;
  } 
  if ( c == 1 ) 
  mem [curlist .tailfield ].hh .v.RH = copynodelist ( mem [p + 5 ].hh 
  .v.RH ) ;
  else {
      
    mem [curlist .tailfield ].hh .v.RH = mem [p + 5 ].hh .v.RH ;
    setequiv ( 655423L + curval , 0 ) ;
    freenode ( p , 8 ) ;
  } 
  lab30: while ( mem [curlist .tailfield ].hh .v.RH != 0 ) curlist 
  .tailfield = mem [curlist .tailfield ].hh .v.RH ;
} 
void 
appenditaliccorrection ( void ) 
{
  /* 10 */ appenditaliccorrection_regmem 
  halfword p  ;
  internalfontnumber f  ;
  if ( curlist .tailfield != curlist .headfield ) 
  {
    if ( ( curlist .tailfield >= himemmin ) ) 
    p = curlist .tailfield ;
    else if ( mem [curlist .tailfield ].hh.b0 == 6 ) 
    p = curlist .tailfield + 1 ;
    else return ;
    f = mem [p ].hh.b0 ;
    {
      mem [curlist .tailfield ].hh .v.RH = newkern ( fonttables [f ][ 
      fonttables [f ][ 39 ].cint + ( fonttables [f ][ fonttables [f ][ 34 
      ].cint - fonttables [f ][ 5 ].cint + mem [p ].hh.b1 ].qqqq .b2 ) / 
      256 ].cint ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    mem [curlist .tailfield ].hh.b1 = 1 ;
  } 
} 
void 
zappendlocalbox ( integer kind ) 
{
  appendlocalbox_regmem 
  incr ( saveptr ) ;
  savestack [saveptr - 1 ].cint = kind ;
  newsavelevel ( 17 ) ;
  scanleftbrace () ;
  pushnest () ;
  curlist .modefield = -119 ;
  curlist .auxfield .hh .v.LH = 1000 ;
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
    c = fonttables [newequiv ( 720959L ) ][ 16 ].cint ;
    if ( c >= 0 ) {
	
      if ( c <= 65535L ) 
      mem [curlist .tailfield + 1 ].hh .v.LH = newcharacter ( newequiv ( 
      720959L ) , c ) ;
    } 
  } 
  else {
      
    incr ( saveptr ) ;
    savestack [saveptr - 1 ].cint = 0 ;
    newsavelevel ( 10 ) ;
    scanleftbrace () ;
    pushnest () ;
    curlist .modefield = -119 ;
    curlist .auxfield .hh .v.LH = 1000 ;
  } 
} 
void 
buildlocalbox ( void ) 
{
  buildlocalbox_regmem 
  halfword p  ;
  integer kind  ;
  unsave () ;
  kind = savestack [saveptr - 1 ].cint ;
  decr ( saveptr ) ;
  p = mem [curlist .headfield ].hh .v.RH ;
  popnest () ;
  p = hpack ( p , 0 , 1 ) ;
  if ( kind == 0 ) 
  eqdefine ( 655421L , 136 , p ) ;
  else eqdefine ( 655422L , 136 , p ) ;
  if ( abs ( curlist .modefield ) == 119 ) 
  {
    {
      mem [curlist .tailfield ].hh .v.RH = makelocalparnode () ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
  } 
  eqworddefine ( 1049465L , neweqtbint ( 1049465L ) + 1 ) ;
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
  while ( p != 0 ) {
      
    if ( ! ( p >= himemmin ) ) {
	
      if ( mem [p ].hh.b0 > 2 ) {
	  
	if ( mem [p ].hh.b0 != 11 ) {
	    
	  if ( mem [p ].hh.b0 != 6 ) 
	  {
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 65548L ) ;
	      print ( 66467L ) ;
	    } 
	    {
	      helpptr = 1 ;
	      helpline [0 ]= 66468L ;
	    } 
	    error () ;
	    begindiagnostic () ;
	    printnl ( 66469L ) ;
	    showbox ( p ) ;
	    enddiagnostic ( true ) ;
	    flushnodelist ( p ) ;
	    mem [q ].hh .v.RH = 0 ;
	    goto lab30 ;
	  } 
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
      if ( ( n > 0 ) && ( abs ( curlist .modefield ) == 237 ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66461L ) ;
	} 
	printesc ( 65635L ) ;
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66462L ;
	  helpline [0 ]= 66463L ;
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
	  else printnl ( 65548L ) ;
	  print ( 66464L ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66465L ;
	  helpline [0 ]= 66466L ;
	} 
	error () ;
      } 
      if ( n > 0 ) 
      curlist .tailfield = q ;
      decr ( saveptr ) ;
      return ;
    } 
    break ;
  } 
  incr ( savestack [saveptr - 1 ].cint ) ;
  newsavelevel ( 10 ) ;
  scanleftbrace () ;
  pushnest () ;
  curlist .modefield = -119 ;
  curlist .auxfield .hh .v.LH = 1000 ;
} 
void 
makeaccent ( void ) 
{
  makeaccent_regmem 
  real s, t  ;
  halfword p, q, r  ;
  internalfontnumber f  ;
  scaled a, h, x, w, delta  ;
  fourquarters i  ;
  scancharnum () ;
  f = newequiv ( 720959L ) ;
  p = newcharacter ( f , curval ) ;
  if ( p != 0 ) 
  {
    x = fonttables [f ][ fonttables [f ][ 43 ].cint + 5 ].cint ;
    s = fonttables [f ][ fonttables [f ][ 43 ].cint + 1 ].cint / ((double) 
    65536.0 ) ;
    a = fonttables [f ][ fonttables [f ][ 36 ].cint + fonttables [f ][ 
    fonttables [f ][ 34 ].cint - fonttables [f ][ 5 ].cint + mem [p ]
    .hh.b1 ].qqqq .b0 ].cint ;
    doassignments () ;
    q = 0 ;
    f = newequiv ( 720959L ) ;
    if ( ( curcmd == 11 ) || ( curcmd == 12 ) || ( curcmd == 70 ) ) 
    q = newcharacter ( f , curchr ) ;
    else if ( curcmd == 16 ) 
    {
      scancharnum () ;
      q = newcharacter ( f , curval ) ;
    } 
    else backinput () ;
    if ( q != 0 ) 
    {
      t = fonttables [f ][ fonttables [f ][ 43 ].cint + 1 ].cint 
      / ((double) 65536.0 ) ;
      i = fonttables [f ][ fonttables [f ][ 34 ].cint - fonttables [f ][ 5 
      ].cint + mem [q ].hh.b1 ].qqqq ;
      w = fonttables [f ][ fonttables [f ][ 36 ].cint + i .b0 ].cint ;
      h = fonttables [f ][ fonttables [f ][ 37 ].cint + ( i .b1 ) / 256 ]
      .cint ;
      if ( h != x ) 
      {
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
      mem [p ].hh .v.RH = curlist .tailfield ;
      p = q ;
    } 
    mem [curlist .tailfield ].hh .v.RH = p ;
    curlist .tailfield = p ;
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
      else printnl ( 65548L ) ;
      print ( 66474L ) ;
    } 
    printcmdchr ( curcmd , curchr ) ;
    if ( curtok == 262182L ) 
    {
      {
	helpptr = 6 ;
	helpline [5 ]= 66475L ;
	helpline [4 ]= 66476L ;
	helpline [3 ]= 66477L ;
	helpline [2 ]= 66478L ;
	helpline [1 ]= 66479L ;
	helpline [0 ]= 66480L ;
      } 
    } 
    else {
	
      {
	helpptr = 5 ;
	helpline [4 ]= 66475L ;
	helpline [3 ]= 66481L ;
	helpline [2 ]= 66478L ;
	helpline [1 ]= 66479L ;
	helpline [0 ]= 66480L ;
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
	else printnl ( 65548L ) ;
	print ( 65966L ) ;
      } 
      incr ( alignstate ) ;
      curtok = 65659L ;
    } 
    else {
	
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66470L ) ;
      } 
      decr ( alignstate ) ;
      curtok = 131197L ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 66471L ;
      helpline [1 ]= 66472L ;
      helpline [0 ]= 66473L ;
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
    else printnl ( 65548L ) ;
    print ( 66474L ) ;
  } 
  printesc ( 65825L ) ;
  {
    helpptr = 2 ;
    helpline [1 ]= 66482L ;
    helpline [0 ]= 66483L ;
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
    else printnl ( 65548L ) ;
    print ( 66474L ) ;
  } 
  printesc ( 65828L ) ;
  {
    helpptr = 2 ;
    helpline [1 ]= 66484L ;
    helpline [0 ]= 66483L ;
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
  baseptr ].locfield == 0 ) && ( inputstack [baseptr ].statefield == 0 ) ) 
  decr ( baseptr ) ;
  if ( ( inputstack [baseptr ].indexfield != 2 ) || ( inputstack [baseptr ]
  .locfield != 0 ) || ( inputstack [baseptr ].statefield != 0 ) ) 
  fatalerror ( 65904L ) ;
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
    else printnl ( 65548L ) ;
    print ( 66104L ) ;
  } 
  printesc ( 65795L ) ;
  {
    helpptr = 1 ;
    helpline [0 ]= 66486L ;
  } 
  error () ;
} 
void 
zpushmath ( groupcode c ) 
{
  pushmath_regmem 
  if ( neweqtbint ( 1049483L ) != neweqtbint ( 1049482L ) ) 
  curlist .mathfield = true ;
  pushnest () ;
  curlist .modefield = -237 ;
  curlist .auxfield .cint = 0 ;
  {
    savestack [saveptr + 0 ].cint = textdirptr ;
    textdirptr = newdir ( neweqtbint ( 1049483L ) ) ;
    incr ( saveptr ) ;
    newsavelevel ( c ) ;
    eqworddefine ( 1049480L , neweqtbint ( 1049483L ) ) ;
    eqworddefine ( 1049481L , neweqtbint ( 1049483L ) ) ;
    eqworddefine ( 1049482L , neweqtbint ( 1049483L ) ) ;
    eqworddefine ( 1049467L , curlevel ) ;
  } 
} 
void 
initmath ( void ) 
{
  /* 21 40 45 30 */ initmath_regmem 
  scaled w  ;
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
    if ( curlist .headfield == curlist .tailfield ) 
    {
      popnest () ;
      w = -1073741823L ;
    } 
    else {
	
      linebreak ( neweqtbint ( 1049415L ) ) ;
      v = mem [justbox + 4 ].cint + 2 * fonttables [newequiv ( 720959L ) ][ 
      fonttables [newequiv ( 720959L ) ][ 43 ].cint + 6 ].cint ;
      w = -1073741823L ;
      p = mem [justbox + 5 ].hh .v.RH ;
      while ( p != 0 ) {
	  
	lab21: if ( ( p >= himemmin ) ) 
	{
	  f = mem [p ].hh.b0 ;
	  d = fonttables [f ][ fonttables [f ][ 36 ].cint + fonttables [f 
	  ][ fonttables [f ][ 34 ].cint - fonttables [f ][ 5 ].cint + mem 
	  [p ].hh.b1 ].qqqq .b0 ].cint ;
	  goto lab40 ;
	} 
	switch ( mem [p ].hh.b0 ) 
	{case 0 : 
	case 1 : 
	case 2 : 
	  {
	    d = mem [p + 1 ].cint ;
	    goto lab40 ;
	  } 
	  break ;
	case 6 : 
	  {
	    mem [memtop - 12 ]= mem [p + 1 ];
	    mem [memtop - 12 ].hh .v.RH = mem [p ].hh .v.RH ;
	    p = memtop - 12 ;
	    goto lab21 ;
	  } 
	  break ;
	case 11 : 
	case 9 : 
	  d = mem [p + 1 ].cint ;
	  break ;
	case 10 : 
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
	case 8 : 
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
      lab30: ;
    } 
    if ( newequiv ( 524320L ) == 0 ) {
	
      if ( ( neweqtbsc ( 1180556L + ( 17 ) ) != 0 ) && ( ( ( neweqtbint ( 
      1049449L ) >= 0 ) && ( curlist .pgfield + 2 > neweqtbint ( 1049449L ) ) 
      ) || ( curlist .pgfield + 1 < - (integer) neweqtbint ( 1049449L ) ) ) ) 
      {
	l = neweqtbsc ( 1180556L + ( 3 ) ) - abs ( neweqtbsc ( 1180556L + ( 17 
	) ) ) ;
	if ( neweqtbsc ( 1180556L + ( 17 ) ) > 0 ) 
	s = neweqtbsc ( 1180556L + ( 17 ) ) ;
	else s = 0 ;
      } 
      else {
	  
	l = neweqtbsc ( 1180556L + ( 3 ) ) ;
	s = 0 ;
      } 
    } 
    else {
	
      n = mem [newequiv ( 524320L ) ].hh .v.LH ;
      if ( curlist .pgfield + 2 >= n ) 
      p = newequiv ( 524320L ) + 2 * n ;
      else p = newequiv ( 524320L ) + 2 * ( curlist .pgfield + 2 ) ;
      s = mem [p - 1 ].cint ;
      l = mem [p ].cint ;
    } 
    pushmath ( 15 ) ;
    curlist .modefield = 237 ;
    eqworddefine ( 1049452L , -1 ) ;
    eqworddefine ( 1180569L , w ) ;
    eqworddefine ( 1180570L , l ) ;
    eqworddefine ( 1180571L , s ) ;
    if ( newequiv ( 524328L ) != 0 ) 
    begintokenlist ( newequiv ( 524328L ) , 9 ) ;
    if ( nestptr == 1 ) 
    buildpage () ;
  } 
  else {
      
    backinput () ;
    {
      pushmath ( 15 ) ;
      eqworddefine ( 1049452L , -1 ) ;
      if ( ( insertsrcspecialeverymath ) ) 
      insertsrcspecial () ;
      if ( newequiv ( 524327L ) != 0 ) 
      begintokenlist ( newequiv ( 524327L ) , 8 ) ;
    } 
  } 
} 
void 
starteqno ( void ) 
{
  starteqno_regmem 
  savestack [saveptr + 0 ].cint = curchr ;
  incr ( saveptr ) ;
  {
    pushmath ( 15 ) ;
    eqworddefine ( 1049452L , -1 ) ;
    if ( ( insertsrcspecialeverymath ) ) 
    insertsrcspecial () ;
    if ( newequiv ( 524327L ) != 0 ) 
    begintokenlist ( newequiv ( 524327L ) , 8 ) ;
  } 
} 
halfword 
zfinmlist ( halfword p ) 
{
  register halfword Result; finmlist_regmem 
  halfword q  ;
  if ( curlist .auxfield .cint != 0 ) 
  {
    mem [curlist .auxfield .cint + 3 ].hh .v.RH = 3 ;
    mem [curlist .auxfield .cint + 3 ].hh .v.LH = mem [curlist .headfield ]
    .hh .v.RH ;
    if ( p == 0 ) 
    q = curlist .auxfield .cint ;
    else {
	
      q = mem [curlist .auxfield .cint + 2 ].hh .v.LH ;
      if ( ( mem [q ].hh.b0 != 30 ) || ( curlist .eTeXauxfield == 0 ) ) 
      confusion ( 66232L ) ;
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
zscanmath ( halfword p ) 
{
  /* 20 21 10 */ scanmath_regmem 
  integer c  ;
  lab20: do {
      getxtoken () ;
  } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
  lab21: switch ( curcmd ) 
  {case 11 : 
  case 12 : 
  case 70 : 
    {
      c = newequiv ( 983872L + curchr ) ;
      if ( c == 134217728L ) 
      {
	{
	  curcs = curchr + 1 ;
	  curcmd = neweqtype ( curcs ) ;
	  curchr = newequiv ( curcs ) ;
	  xtoken () ;
	  backinput () ;
	} 
	goto lab20 ;
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
  case 17 : 
    {
      if ( curchr == 0 ) 
      scanfifteenbitint () ;
      else scanbigfifteenbitint () ;
      c = curval ;
    } 
    break ;
  case 71 : 
    {
      c = ( ( curchr / 4096 ) * 16777216L ) + ( ( ( curchr % 4096 ) / 256 ) * 
      65536L ) + ( curchr % 256 ) ;
    } 
    break ;
  case 72 : 
    {
      c = curchr ;
    } 
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
  mem [p ].hh .v.RH = 1 ;
  mem [p ].hh.b1 = c % 65536L ;
  if ( ( c >= 117440512L ) && ( ( neweqtbint ( 1049452L ) >= 0 ) && ( 
  neweqtbint ( 1049452L ) < 256 ) ) ) 
  mem [p ].hh.b0 = neweqtbint ( 1049452L ) ;
  else mem [p ].hh.b0 = ( c / 65536L ) % 256 ;
} 
void 
zsetmathchar ( integer c ) 
{
  setmathchar_regmem 
  halfword p  ;
  if ( c >= 134217728L ) 
  {
    curcs = curchr + 1 ;
    curcmd = neweqtype ( curcs ) ;
    curchr = newequiv ( curcs ) ;
    xtoken () ;
    backinput () ;
  } 
  else {
      
    p = newnoad () ;
    mem [p + 1 ].hh .v.RH = 1 ;
    mem [p + 1 ].hh.b1 = c % 65536L ;
    mem [p + 1 ].hh.b0 = ( c / 65536L ) % 256 ;
    if ( c >= 117440512L ) 
    {
      if ( ( ( neweqtbint ( 1049452L ) >= 0 ) && ( neweqtbint ( 1049452L ) < 
      256 ) ) ) 
      mem [p + 1 ].hh.b0 = neweqtbint ( 1049452L ) ;
      mem [p ].hh.b0 = 16 ;
    } 
    else mem [p ].hh.b0 = 16 + ( c / 16777216L ) ;
    mem [curlist .tailfield ].hh .v.RH = p ;
    curlist .tailfield = p ;
  } 
} 
void 
mathlimitswitch ( void ) 
{
  /* 10 */ mathlimitswitch_regmem 
  if ( curlist .headfield != curlist .tailfield ) {
      
    if ( mem [curlist .tailfield ].hh.b0 == 17 ) 
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
    else printnl ( 65548L ) ;
    print ( 66490L ) ;
  } 
  {
    helpptr = 1 ;
    helpline [0 ]= 66491L ;
  } 
  error () ;
} 
void 
zscandelimiter ( halfword p , integer r ) 
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
	curval = newequiv ( 1115020L + curchr ) ;
	curval1 = newequiv1 ( 1115020L + curchr ) ;
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
	else printnl ( 65548L ) ;
	print ( 66492L ) ;
      } 
      {
	helpptr = 6 ;
	helpline [5 ]= 66493L ;
	helpline [4 ]= 66494L ;
	helpline [3 ]= 66495L ;
	helpline [2 ]= 66496L ;
	helpline [1 ]= 66497L ;
	helpline [0 ]= 66498L ;
      } 
      backerror () ;
      curval = 0 ;
    } 
    curval1 = 0 ;
  } 
  mem [p ].qqqq .b0 = ( curval / 65536L ) % 256 ;
  mem [p ].qqqq .b1 = curval % 65536L ;
  mem [p ].qqqq .b2 = ( curval1 / 65536L ) % 256 ;
  mem [p ].qqqq .b3 = curval1 % 65536L ;
} 
void 
mathradical ( void ) 
{
  mathradical_regmem 
  {
    mem [curlist .tailfield ].hh .v.RH = getnode ( 5 ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  mem [curlist .tailfield ].hh.b0 = 24 ;
  mem [curlist .tailfield ].hh.b1 = 0 ;
  mem [curlist .tailfield + 1 ].hh = emptyfield ;
  mem [curlist .tailfield + 3 ].hh = emptyfield ;
  mem [curlist .tailfield + 2 ].hh = emptyfield ;
  scandelimiter ( curlist .tailfield + 4 , curchr + 1 ) ;
  scanmath ( curlist .tailfield + 1 ) ;
} 
void 
mathac ( void ) 
{
  mathac_regmem 
  if ( curcmd == 45 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66499L ) ;
    } 
    printesc ( 65819L ) ;
    print ( 66500L ) ;
    {
      helpptr = 2 ;
      helpline [1 ]= 66501L ;
      helpline [0 ]= 66502L ;
    } 
    error () ;
  } 
  {
    mem [curlist .tailfield ].hh .v.RH = getnode ( 5 ) ;
    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
  } 
  mem [curlist .tailfield ].hh.b0 = 28 ;
  mem [curlist .tailfield ].hh.b1 = 0 ;
  mem [curlist .tailfield + 1 ].hh = emptyfield ;
  mem [curlist .tailfield + 3 ].hh = emptyfield ;
  mem [curlist .tailfield + 2 ].hh = emptyfield ;
  mem [curlist .tailfield + 4 ].hh .v.RH = 1 ;
  if ( curchr == 0 ) 
  scanfifteenbitint () ;
  else scanbigfifteenbitint () ;
  mem [curlist .tailfield + 4 ].hh.b1 = curval % 65536L ;
  if ( ( curval >= 117440512L ) && ( ( neweqtbint ( 1049452L ) >= 0 ) && ( 
  neweqtbint ( 1049452L ) < 256 ) ) ) 
  mem [curlist .tailfield + 4 ].hh.b0 = neweqtbint ( 1049452L ) ;
  else mem [curlist .tailfield + 4 ].hh.b0 = ( curval / 65536L ) % 256 ;
  scanmath ( curlist .tailfield + 1 ) ;
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
void 
buildchoices ( void ) 
{
  /* 10 */ buildchoices_regmem 
  halfword p  ;
  {
    unsave () ;
    decr ( saveptr ) ;
    flushnodelist ( textdirptr ) ;
    textdirptr = savestack [saveptr + 0 ].cint ;
  } 
  p = finmlist ( 0 ) ;
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
  p = 0 ;
  if ( curlist .tailfield != curlist .headfield ) {
      
    if ( ( mem [curlist .tailfield ].hh.b0 >= 16 ) && ( mem [curlist 
    .tailfield ].hh.b0 < 30 ) ) 
    {
      p = curlist .tailfield + 2 + curcmd - 7 ;
      t = mem [p ].hh .v.RH ;
    } 
  } 
  if ( ( p == 0 ) || ( t != 0 ) ) 
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
	  else printnl ( 65548L ) ;
	  print ( 66503L ) ;
	} 
	{
	  helpptr = 1 ;
	  helpline [0 ]= 66504L ;
	} 
      } 
      else {
	  
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66505L ) ;
	} 
	{
	  helpptr = 1 ;
	  helpline [0 ]= 66506L ;
	} 
      } 
      error () ;
    } 
  } 
  scanmath ( p ) ;
} 
void 
mathfraction ( void ) 
{
  mathfraction_regmem 
  smallnumber c  ;
  c = curchr ;
  if ( curlist .auxfield .cint != 0 ) 
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
      else printnl ( 65548L ) ;
      print ( 66513L ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 66514L ;
      helpline [1 ]= 66515L ;
      helpline [0 ]= 66516L ;
    } 
    error () ;
  } 
  else {
      
    curlist .auxfield .cint = getnode ( 6 ) ;
    mem [curlist .auxfield .cint ].hh.b0 = 25 ;
    mem [curlist .auxfield .cint ].hh.b1 = 0 ;
    mem [curlist .auxfield .cint + 2 ].hh .v.RH = 3 ;
    mem [curlist .auxfield .cint + 2 ].hh .v.LH = mem [curlist .headfield ]
    .hh .v.RH ;
    mem [curlist .auxfield .cint + 3 ].hh = emptyfield ;
    mem [curlist .auxfield .cint + 4 ].qqqq = nulldelimiter ;
    mem [curlist .auxfield .cint + 5 ].qqqq = nulldelimiter ;
    mem [curlist .headfield ].hh .v.RH = 0 ;
    curlist .tailfield = curlist .headfield ;
    if ( c >= 3 ) 
    {
      scandelimiter ( curlist .auxfield .cint + 4 , false ) ;
      scandelimiter ( curlist .auxfield .cint + 5 , false ) ;
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
  if ( ( t != 30 ) && ( curgroup != 16 ) ) 
  {
    if ( curgroup == 15 ) 
    {
      scandelimiter ( memtop - 12 , false ) ;
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66104L ) ;
      } 
      if ( t == 1 ) 
      {
	printesc ( 66233L ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 66517L ;
	} 
      } 
      else {
	  
	printesc ( 66232L ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 66518L ;
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
      mem [p ].hh.b0 = 31 ;
      mem [p ].hh.b1 = 1 ;
    } 
    if ( t == 30 ) 
    q = p ;
    else {
	
      q = finmlist ( p ) ;
      {
	unsave () ;
	decr ( saveptr ) ;
	flushnodelist ( textdirptr ) ;
	textdirptr = savestack [saveptr + 0 ].cint ;
      } 
    } 
    if ( t != 31 ) 
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
      mem [curlist .tailfield ].hh.b0 = 23 ;
      mem [curlist .tailfield + 1 ].hh .v.RH = 3 ;
      mem [curlist .tailfield + 1 ].hh .v.LH = q ;
    } 
  } 
} 
void 
aftermath ( void ) 
{
  aftermath_regmem 
  boolean l  ;
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
  danger = false ;
  if ( ( fonttables [newequiv ( 720962L ) ][ 8 ].cint < 22 ) || ( fonttables 
  [newequiv ( 721218L ) ][ 8 ].cint < 22 ) || ( fonttables [newequiv ( 
  721474L ) ][ 8 ].cint < 22 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66519L ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 66520L ;
      helpline [1 ]= 66521L ;
      helpline [0 ]= 66522L ;
    } 
    error () ;
    flushmath () ;
    danger = true ;
  } 
  else if ( ( fonttables [newequiv ( 720963L ) ][ 8 ].cint < 13 ) || ( 
  fonttables [newequiv ( 721219L ) ][ 8 ].cint < 13 ) || ( fonttables [
  newequiv ( 721475L ) ][ 8 ].cint < 13 ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66523L ) ;
    } 
    {
      helpptr = 3 ;
      helpline [2 ]= 66524L ;
      helpline [1 ]= 66525L ;
      helpline [0 ]= 66526L ;
    } 
    error () ;
    flushmath () ;
    danger = true ;
  } 
  m = curlist .modefield ;
  l = false ;
  p = finmlist ( 0 ) ;
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
	  else printnl ( 65548L ) ;
	  print ( 66527L ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66528L ;
	  helpline [0 ]= 66529L ;
	} 
	backerror () ;
      } 
    } 
    curmlist = p ;
    curstyle = 2 ;
    mlistpenalties = false ;
    mlisttohlist () ;
    a = hpack ( mem [memtop - 3 ].hh .v.RH , 0 , 1 ) ;
    {
      unsave () ;
      decr ( saveptr ) ;
      flushnodelist ( textdirptr ) ;
      textdirptr = savestack [saveptr + 0 ].cint ;
    } 
    decr ( saveptr ) ;
    if ( savestack [saveptr + 0 ].cint == 1 ) 
    l = true ;
    danger = false ;
    if ( ( fonttables [newequiv ( 720962L ) ][ 8 ].cint < 22 ) || ( 
    fonttables [newequiv ( 721218L ) ][ 8 ].cint < 22 ) || ( fonttables [
    newequiv ( 721474L ) ][ 8 ].cint < 22 ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66519L ) ;
      } 
      {
	helpptr = 3 ;
	helpline [2 ]= 66520L ;
	helpline [1 ]= 66521L ;
	helpline [0 ]= 66522L ;
      } 
      error () ;
      flushmath () ;
      danger = true ;
    } 
    else if ( ( fonttables [newequiv ( 720963L ) ][ 8 ].cint < 13 ) || ( 
    fonttables [newequiv ( 721219L ) ][ 8 ].cint < 13 ) || ( fonttables [
    newequiv ( 721475L ) ][ 8 ].cint < 13 ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66523L ) ;
      } 
      {
	helpptr = 3 ;
	helpline [2 ]= 66524L ;
	helpline [1 ]= 66525L ;
	helpline [0 ]= 66526L ;
      } 
      error () ;
      flushmath () ;
      danger = true ;
    } 
    m = curlist .modefield ;
    p = finmlist ( 0 ) ;
  } 
  else a = 0 ;
  if ( m < 0 ) 
  {
    {
      mem [curlist .tailfield ].hh .v.RH = newmath ( neweqtbsc ( 1180556L + 
      ( 1 ) ) , 0 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    if ( curlist .mathfield ) 
    {
      mem [curlist .tailfield ].hh .v.RH = newdir ( neweqtbint ( 1049483L ) 
      ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    curmlist = p ;
    curstyle = 2 ;
    mlistpenalties = ( curlist .modefield > 0 ) ;
    mlisttohlist () ;
    mem [curlist .tailfield ].hh .v.RH = mem [memtop - 3 ].hh .v.RH ;
    while ( mem [curlist .tailfield ].hh .v.RH != 0 ) curlist .tailfield = 
    mem [curlist .tailfield ].hh .v.RH ;
    if ( curlist .mathfield ) 
    {
      mem [curlist .tailfield ].hh .v.RH = newdir ( neweqtbint ( 1049483L ) 
      - 64 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    curlist .mathfield = false ;
    {
      mem [curlist .tailfield ].hh .v.RH = newmath ( neweqtbsc ( 1180556L + 
      ( 1 ) ) , 1 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    curlist .auxfield .hh .v.LH = 1000 ;
    {
      unsave () ;
      decr ( saveptr ) ;
      flushnodelist ( textdirptr ) ;
      textdirptr = savestack [saveptr + 0 ].cint ;
    } 
  } 
  else {
      
    if ( a == 0 ) 
    {
      getxtoken () ;
      if ( curcmd != 3 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66527L ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66528L ;
	  helpline [0 ]= 66529L ;
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
    adjusttail = 0 ;
    w = mem [b + 1 ].cint ;
    z = neweqtbsc ( 1180556L + ( 14 ) ) ;
    s = neweqtbsc ( 1180556L + ( 15 ) ) ;
    if ( ( a == 0 ) || danger ) 
    {
      e = 0 ;
      q = 0 ;
    } 
    else {
	
      e = mem [a + 1 ].cint ;
      q = e + fonttables [newequiv ( 720962L + cursize ) ][ 6 + fonttables [
      newequiv ( 720962L + cursize ) ][ 43 ].cint ].cint ;
    } 
    if ( w + q > z ) 
    {
      if ( ( e != 0 ) && ( ( w - totalshrink [0 ]+ q <= z ) || ( totalshrink 
      [1 ]!= 0 ) || ( totalshrink [2 ]!= 0 ) || ( totalshrink [3 ]!= 0 ) 
      || ( totalshrink [4 ]!= 0 ) ) ) 
      {
	freenode ( b , 8 ) ;
	b = hpack ( p , z - q , 0 ) ;
      } 
      else {
	  
	e = 0 ;
	if ( w > z ) 
	{
	  freenode ( b , 8 ) ;
	  b = hpack ( p , z , 0 ) ;
	} 
      } 
      w = mem [b + 1 ].cint ;
    } 
    d = half ( z - w ) ;
    if ( ( e > 0 ) && ( d < 2 * e ) ) 
    {
      d = half ( z - w - e ) ;
      if ( p != 0 ) {
	  
	if ( ! ( p >= himemmin ) ) {
	    
	  if ( mem [p ].hh.b0 == 10 ) 
	  d = 0 ;
	} 
      } 
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = newpenalty ( neweqtbint ( 
      1049419L ) ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    if ( ( d + s <= neweqtbsc ( 1180556L + ( 13 ) ) ) || l ) 
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
      mem [a + 4 ].cint = s ;
      appendtovlist ( a ) ;
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
    mem [b + 4 ].cint = s + d ;
    appendtovlist ( b ) ;
    if ( ( a != 0 ) && ( e == 0 ) && ! l ) 
    {
      {
	mem [curlist .tailfield ].hh .v.RH = newpenalty ( 10000 ) ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [a + 4 ].cint = s + z - mem [a + 1 ].cint ;
      appendtovlist ( a ) ;
      g2 = 0 ;
    } 
    if ( t != memtop - 5 ) 
    {
      mem [curlist .tailfield ].hh .v.RH = mem [memtop - 5 ].hh .v.RH ;
      curlist .tailfield = t ;
    } 
    {
      mem [curlist .tailfield ].hh .v.RH = newpenalty ( neweqtbint ( 
      1049420L ) ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    if ( g2 > 0 ) 
    {
      mem [curlist .tailfield ].hh .v.RH = newparamglue ( g2 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    resumeafterdisplay () ;
  } 
} 
void 
resumeafterdisplay ( void ) 
{
  resumeafterdisplay_regmem 
  if ( curgroup != 15 ) 
  confusion ( 66530L ) ;
  {
    unsave () ;
    decr ( saveptr ) ;
    flushnodelist ( textdirptr ) ;
    textdirptr = savestack [saveptr + 0 ].cint ;
  } 
  curlist .pgfield = curlist .pgfield + 3 ;
  pushnest () ;
  curlist .modefield = 119 ;
  curlist .auxfield .hh .v.LH = 1000 ;
  if ( neweqtbint ( 1049458L ) <= 0 ) 
  curlang = 0 ;
  else if ( neweqtbint ( 1049458L ) > 255 ) 
  curlang = 0 ;
  else curlang = neweqtbint ( 1049458L ) ;
  curlist .auxfield .hh .v.RH = curlang ;
  curlist .pgfield = ( normmin ( neweqtbint ( 1049459L ) ) * 64 + normmin ( 
  neweqtbint ( 1049460L ) ) ) * 65536L + curlang ;
  {
    {
      mem [curlist .tailfield ].hh .v.RH = makelocalparnode () ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
  } 
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
  } while ( ! ( curtok != 655392L ) ) ;
  if ( ( curcs == 0 ) || ( curcs > 196610L ) ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66548L ) ;
    } 
    {
      helpptr = 5 ;
      helpline [4 ]= 66549L ;
      helpline [3 ]= 66550L ;
      helpline [2 ]= 66551L ;
      helpline [1 ]= 66552L ;
      helpline [0 ]= 66553L ;
    } 
    if ( curcs == 0 ) 
    backinput () ;
    curtok = 1245185L ;
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
  q = curcmd ;
  {
    if ( q != 92 ) 
    {
      getxtoken () ;
      if ( ( curcmd >= 76 ) && ( curcmd <= 79 ) ) 
      {
	l = curchr ;
	p = curcmd - 76 ;
	goto lab40 ;
      } 
      if ( curcmd != 92 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66002L ) ;
	} 
	printcmdchr ( curcmd , curchr ) ;
	print ( 66003L ) ;
	printcmdchr ( q , 0 ) ;
	{
	  helpptr = 1 ;
	  helpline [0 ]= 66578L ;
	} 
	error () ;
	return ;
      } 
    } 
    p = curchr ;
    scaneightbitint () ;
    switch ( p ) 
    {case 0 : 
      l = curval + 1049484L ;
      break ;
    case 1 : 
      l = curval + 1180581L ;
      break ;
    case 2 : 
      l = curval + 393248L ;
      break ;
    case 3 : 
      l = curval + 458784L ;
      break ;
    } 
  } 
  lab40: ;
  if ( q == 92 ) 
  scanoptionalequals () ;
  else if ( scankeyword ( 66574L ) ) 
  ;
  aritherror = false ;
  if ( q < 97 ) {
      
    if ( p < 2 ) 
    {
      if ( p == 0 ) 
      scanint () ;
      else scandimen ( false , false , false ) ;
      if ( q == 96 ) 
      curval = curval + neweqtbint ( l ) ;
    } 
    else {
	
      scanglue ( p ) ;
      if ( q == 96 ) 
      {
	q = newspec ( curval ) ;
	r = newequiv ( l ) ;
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
	
      if ( q == 97 ) {
	  
	if ( p == 0 ) 
	curval = multandadd ( neweqtbint ( l ) , curval , 0 , 2147483647L ) ;
	else curval = multandadd ( neweqtbint ( l ) , curval , 0 , 1073741823L 
	) ;
      } 
      else curval = xovern ( neweqtbint ( l ) , curval ) ;
    } 
    else {
	
      s = newequiv ( l ) ;
      r = newspec ( s ) ;
      if ( q == 97 ) 
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
      else printnl ( 65548L ) ;
      print ( 66575L ) ;
    } 
    {
      helpptr = 2 ;
      helpline [1 ]= 66576L ;
      helpline [0 ]= 66577L ;
    } 
    if ( p >= 2 ) 
    deleteglueref ( curval ) ;
    error () ;
    return ;
  } 
  if ( p < 2 ) {
      
    if ( ( a >= 4 ) ) 
    geqworddefine ( l , curval ) ;
    else eqworddefine ( l , curval ) ;
  } 
  else {
      
    trapzeroglue () ;
    if ( ( a >= 4 ) ) 
    geqdefine ( l , 134 , curval ) ;
    else eqdefine ( l , 134 , curval ) ;
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
	  else printnl ( 65548L ) ;
	  print ( 66581L ) ;
	} 
	{
	  helpptr = 1 ;
	  helpline [0 ]= 66582L ;
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
      else printnl ( 65548L ) ;
      print ( 66311L ) ;
    } 
    printesc ( 65831L ) ;
    {
      helpptr = 1 ;
      helpline [0 ]= 66583L ;
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
	else printnl ( 65548L ) ;
	print ( 66755L ) ;
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 66756L ;
	helpline [0 ]= 66757L ;
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
  eightbits b  ;
  c = curchr ;
  scaneightbitint () ;
  b = curval ;
  scanoptionalequals () ;
  scandimen ( false , false , false ) ;
  if ( newequiv ( 655423L + b ) != 0 ) 
  mem [newequiv ( 655423L + b ) + c ].cint = curval ;
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
  integer offset  ;
  integer naturaldir  ;
  if ( jobname == 0 ) 
  openlogfile () ;
  getrtoken () ;
  u = curcs ;
  if ( u >= 131074L ) 
  t = newhashtext ( 1246116L + u ) ;
  else if ( u >= 65537L ) {
      
    if ( u == 131073L ) 
    t = 66590L ;
    else t = u - 65537L ;
  } 
  else {
      
    oldsetting = selector ;
    selector = 21 ;
    print ( 66590L ) ;
    print ( u - 1 ) ;
    selector = oldsetting ;
    {
      if ( poolptr + 1 > poolsize ) 
      overflow ( 65543L , poolsize - initpoolptr ) ;
    } 
    t = makestring () ;
  } 
  if ( ( a >= 4 ) ) 
  geqdefine ( u , 90 , 0 ) ;
  else eqdefine ( u , 90 , 0 ) ;
  scanoptionalequals () ;
  scanfilename () ;
  nameinprogress = true ;
  if ( scankeyword ( 66595L ) ) 
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
	else printnl ( 65548L ) ;
	print ( 66597L ) ;
      } 
      printscaled ( s ) ;
      print ( 66598L ) ;
      {
	helpptr = 2 ;
	helpline [1 ]= 66599L ;
	helpline [0 ]= 66600L ;
      } 
      error () ;
      s = 10 * 65536L ;
    } 
  } 
  else if ( scankeyword ( 66596L ) ) 
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
	else printnl ( 65548L ) ;
	print ( 65858L ) ;
      } 
      {
	helpptr = 1 ;
	helpline [0 ]= 65859L ;
      } 
      interror ( curval ) ;
      s = -1000 ;
    } 
  } 
  else s = -1000 ;
  nameinprogress = false ;
  nameinprogress = true ;
  if ( scankeyword ( 66591L ) ) 
  {
    scanint () ;
    offset = curval ;
    if ( ( curval < 0 ) ) 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66592L ) ;
      } 
      {
	helpptr = 1 ;
	helpline [0 ]= 66593L ;
      } 
      interror ( curval ) ;
      offset = 0 ;
    } 
  } 
  else offset = 0 ;
  if ( scankeyword ( 66594L ) ) 
  {
    scandir () ;
    naturaldir = curval ;
  } 
  else naturaldir = -1 ;
  nameinprogress = false ;
  {register integer for_end; f = 1 ;for_end = fontptr ; if ( f <= for_end) 
  do 
    {
      if ( streqstr ( fonttables [f ][ 10 ].cint , curname ) && streqstr ( 
      fonttables [f ][ 11 ].cint , curarea ) ) 
      {
	if ( s > 0 ) 
	{
	  if ( s == fonttables [f ][ 6 ].cint ) 
	  goto lab50 ;
	} 
	else if ( fonttables [f ][ 6 ].cint == xnoverd ( fonttables [f ][ 7 
	].cint , - (integer) s , 1000 ) ) 
	goto lab50 ;
      } 
    } 
  while ( f++ < for_end ) ;} 
  f = readfontinfo ( u , curname , curarea , s , offset , naturaldir ) ;
  lab50: setequiv ( u , f ) ;
  setneweqtb ( 196620L + f , neweqtb ( u ) ) ;
  sethashtext ( 1442736L + f , t ) ;
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
scanfilereferrent ( void ) 
{
  scanfilereferrent_regmem 
  if ( scankeyword ( 66813L ) ) 
  curval = 1073741823L ;
  else scanint () ;
} 
void 
scanmode ( void ) 
{
  scanmode_regmem 
  if ( scankeyword ( 66814L ) ) 
  curval = 1 ;
  else if ( scankeyword ( 66815L ) ) 
  curval = 2 ;
  else if ( scankeyword ( 66816L ) ) 
  curval = 3 ;
  else if ( scankeyword ( 66817L ) ) 
  curval = 4 ;
  else {
      
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66818L ) ;
    } 
    curval = 0 ;
  } 
} 
void 
dochartranslation ( void ) 
{
  dochartranslation_regmem 
  halfword kind  ;
  halfword fileref  ;
  halfword moderef  ;
  halfword ocpref  ;
  fileref = 0 ;
  moderef = 0 ;
  ocpref = 0 ;
  kind = curchr ;
  if ( ( kind % 4 ) <= 1 ) 
  {
    scanfilereferrent () ;
    fileref = curval ;
  } 
  else {
      
    scanmode () ;
    moderef = curval ;
  } 
  if ( kind < 4 ) 
  {
    scanocpident () ;
    ocpref = curval ;
  } 
  switch ( ( kind % 4 ) ) 
  {case 0 : 
    {
      if ( ( fileref >= 0 ) && ( fileref <= 15 ) ) 
      {
	readfiletranslation [fileref ]= ocpref ;
      } 
      else if ( fileref != 1073741823L ) 
      {
	termintranslation = ocpref ;
      } 
      else {
	  
	baseptr = inputptr ;
	inputstack [baseptr ]= curinput ;
	while ( curinput .statefield == 0 ) {
	    
	  decr ( baseptr ) ;
	  curinput = inputstack [baseptr ];
	} 
	if ( curinput .namefield > 17 ) 
	inputfiletranslation [curinput .indexfield ]= ocpref ;
	curinput = inputstack [inputptr ];
      } 
    } 
    break ;
  case 1 : 
    {
      if ( ( fileref >= 0 ) && ( fileref <= 15 ) ) 
      {
	writefiletranslation [fileref ]= ocpref ;
      } 
      else {
	  
	termouttranslation = ocpref ;
      } 
    } 
    break ;
  case 2 : 
    {
      geqdefine ( 589875L + moderef , 137 , ocpref ) ;
    } 
    break ;
  case 3 : 
    {
      geqdefine ( 589880L + moderef , 137 , ocpref ) ;
    } 
    break ;
  } 
} 
void 
docharmode ( void ) 
{
  docharmode_regmem 
  halfword kind  ;
  halfword fileref  ;
  halfword moderef  ;
  fileref = 0 ;
  moderef = 0 ;
  kind = curchr ;
  if ( ( kind % 4 ) <= 1 ) 
  {
    scanfilereferrent () ;
    fileref = curval ;
  } 
  if ( kind < 4 ) 
  {
    scanmode () ;
    moderef = curval ;
  } 
  switch ( ( kind % 4 ) ) 
  {case 0 : 
    {
      if ( ( fileref >= 0 ) && ( fileref <= 15 ) ) 
      {
	readfilemode [fileref ]= moderef ;
      } 
      else if ( fileref != 1073741823L ) 
      {
	terminmode = moderef ;
      } 
      else {
	  
	baseptr = inputptr ;
	inputstack [baseptr ]= curinput ;
	while ( curinput .statefield == 0 ) {
	    
	  decr ( baseptr ) ;
	  curinput = inputstack [baseptr ];
	} 
	if ( curinput .namefield > 17 ) 
	inputfilemode [curinput .indexfield ]= moderef ;
	curinput = inputstack [inputptr ];
      } 
    } 
    break ;
  case 1 : 
    {
      if ( ( fileref >= 0 ) && ( fileref <= 15 ) ) 
      {
	writefilemode [fileref ]= moderef ;
      } 
      else {
	  
	termoutmode = moderef ;
      } 
    } 
    break ;
  case 2 : 
    {
      geqdefine ( 589875L , 137 , moderef ) ;
    } 
    break ;
  case 3 : 
    {
      geqdefine ( 589880L , 137 , moderef ) ;
    } 
    break ;
  } 
} 
boolean 
zpnewinputln ( alphafile f , halfword themode , halfword translation , boolean 
bypasseoln ) 
{
  register boolean Result; pnewinputln_regmem 
  if ( ( themode == 0 ) || ( ( themode == 1 ) && ( translation == 0 ) ) ) 
  Result = inputln ( f , bypasseoln ) ;
  else if ( ! newinputline ( f , themode , bypasseoln ) ) 
  Result = false ;
  else if ( translation == 0 ) 
  {
    if ( ( first + otpinputend ) >= bufsize ) 
    overflow ( 65542L , bufsize ) ;
    curinput .statefield = 33 ;
    curinput .startfield = first ;
    last = curinput .startfield ;
    curinput .locfield = curinput .startfield ;
    {register integer for_end; otpcounter = 1 ;for_end = otpinputend ; if ( 
    otpcounter <= for_end) do 
      {
	buffer [last ]= otpinputbuf [otpcounter ];
	incr ( last ) ;
      } 
    while ( otpcounter++ < for_end ) ;} 
    while ( buffer [last - 1 ]== ' ' ) decr ( last ) ;
    curinput .limitfield = last - 1 ;
    Result = true ;
  } 
  else {
      
    otpinputstart = 0 ;
    otpinputlast = 0 ;
    otpstackused = 0 ;
    otpstacklast = 0 ;
    otpstacknew = 0 ;
    otpoutputend = 0 ;
    otppc = 0 ;
    otpfinished = false ;
    otpcalcptr = 0 ;
    otpcalcs [otpcalcptr ]= 0 ;
    otpstateptr = 0 ;
    otpstates [otpstateptr ]= 0 ;
    otpinputocp = translation ;
    while ( ! otpfinished ) {
	
      {
	if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp ][ 10 
	]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	{
	  {
	    if ( interaction == 3 ) 
	    ;
	    if ( filelineerrorstylep ) 
	    printfileline () ;
	    else printnl ( 65548L ) ;
	    print ( 66821L ) ;
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
	otpinstruction = ocptables [otpinputocp ][ ocptables [otpinputocp ][ 
	ocptables [otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 ]+ 
	otppc ];
	otpinstr = otpinstruction / 16777216L ;
	otparg = otpinstruction % 16777216L ;
      } 
      switch ( otpinstr ) 
      {case 1 : 
	{
	  incr ( otpoutputend ) ;
	  if ( otpoutputend > ocpbufsize ) 
	  overflowocpbufsize () ;
	  otpoutputbuf [otpoutputend ]= otpcalcs [otpcalcptr ];
	  decr ( otpcalcptr ) ;
	  incr ( otppc ) ;
	} 
	break ;
      case 2 : 
	{
	  incr ( otpoutputend ) ;
	  if ( otpoutputend > ocpbufsize ) 
	  overflowocpbufsize () ;
	  otpoutputbuf [otpoutputend ]= otparg ;
	  incr ( otppc ) ;
	} 
	break ;
      case 3 : 
	{
	  {
	    if ( ( 1 > otparg ) || ( otparg > otpnoinputchars ) ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66823L ) ;
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
	    if ( otparg > otpstacklast ) 
	    {
	      otpcalculatedchar = otpinputbuf [otpinputstart + otparg - 
	      otpstacklast ];
	    } 
	    else {
		
	      otpcalculatedchar = otpstackbuf [otparg ];
	    } 
	  } 
	  incr ( otpoutputend ) ;
	  if ( otpoutputend > ocpbufsize ) 
	  overflowocpbufsize () ;
	  otpoutputbuf [otpoutputend ]= otpcalculatedchar ;
	  incr ( otppc ) ;
	} 
	break ;
      case 4 : 
	{
	  {
	    if ( ( 1 > otpnoinputchars - otparg ) || ( otpnoinputchars - 
	    otparg > otpnoinputchars ) ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66823L ) ;
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
	    if ( otpnoinputchars - otparg > otpstacklast ) 
	    {
	      otpcalculatedchar = otpinputbuf [otpinputstart + 
	      otpnoinputchars - otparg - otpstacklast ];
	    } 
	    else {
		
	      otpcalculatedchar = otpstackbuf [otpnoinputchars - otparg ];
	    } 
	  } 
	  incr ( otpoutputend ) ;
	  if ( otpoutputend > ocpbufsize ) 
	  overflowocpbufsize () ;
	  otpoutputbuf [otpoutputend ]= otpcalculatedchar ;
	  incr ( otppc ) ;
	} 
	break ;
      case 5 : 
	{
	  otpfirstarg = otparg + 1 ;
	  incr ( otppc ) ;
	  {
	    if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	    ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66821L ) ;
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
	    otpinstruction = ocptables [otpinputocp ][ ocptables [
	    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	    otpstateptr ]* 2 ]+ otppc ];
	    otpinstr = otpinstruction / 16777216L ;
	    otparg = otpinstruction % 16777216L ;
	  } 
	  otpsecondarg = otpnoinputchars - otparg ;
	  {register integer for_end; otpcounter = otpfirstarg ;for_end = 
	  otpsecondarg ; if ( otpcounter <= for_end) do 
	    {
	      {
		if ( ( 1 > otpcounter ) || ( otpcounter > otpnoinputchars ) ) 
		{
		  {
		    if ( interaction == 3 ) 
		    ;
		    if ( filelineerrorstylep ) 
		    printfileline () ;
		    else printnl ( 65548L ) ;
		    print ( 66823L ) ;
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
		if ( otpcounter > otpstacklast ) 
		{
		  otpcalculatedchar = otpinputbuf [otpinputstart + otpcounter 
		  - otpstacklast ];
		} 
		else {
		    
		  otpcalculatedchar = otpstackbuf [otpcounter ];
		} 
	      } 
	      incr ( otpoutputend ) ;
	      if ( otpoutputend > ocpbufsize ) 
	      overflowocpbufsize () ;
	      otpoutputbuf [otpoutputend ]= otpcalculatedchar ;
	    } 
	  while ( otpcounter++ < for_end ) ;} 
	  incr ( otppc ) ;
	} 
	break ;
      case 6 : 
	{
	  incr ( otpstacknew ) ;
	  if ( otpstacknew >= ocpstacksize ) 
	  overflowocpstacksize () ;
	  otpstackbuf [otpstacknew ]= otpcalcs [otpcalcptr ];
	  decr ( otpcalcptr ) ;
	  incr ( otppc ) ;
	} 
	break ;
      case 7 : 
	{
	  incr ( otpstacknew ) ;
	  if ( otpstacknew >= ocpstacksize ) 
	  overflowocpstacksize () ;
	  otpstackbuf [otpstacknew ]= otparg ;
	  incr ( otppc ) ;
	} 
	break ;
      case 8 : 
	{
	  {
	    if ( ( 1 > otparg ) || ( otparg > otpnoinputchars ) ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66823L ) ;
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
	    if ( otparg > otpstacklast ) 
	    {
	      otpcalculatedchar = otpinputbuf [otpinputstart + otparg - 
	      otpstacklast ];
	    } 
	    else {
		
	      otpcalculatedchar = otpstackbuf [otparg ];
	    } 
	  } 
	  incr ( otpstacknew ) ;
	  if ( otpstacknew >= ocpstacksize ) 
	  overflowocpstacksize () ;
	  otpstackbuf [otpstacknew ]= otpcalculatedchar ;
	  incr ( otppc ) ;
	} 
	break ;
      case 9 : 
	{
	  {
	    if ( ( 1 > otpnoinputchars - otparg ) || ( otpnoinputchars - 
	    otparg > otpnoinputchars ) ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66823L ) ;
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
	    if ( otpnoinputchars - otparg > otpstacklast ) 
	    {
	      otpcalculatedchar = otpinputbuf [otpinputstart + 
	      otpnoinputchars - otparg - otpstacklast ];
	    } 
	    else {
		
	      otpcalculatedchar = otpstackbuf [otpnoinputchars - otparg ];
	    } 
	  } 
	  incr ( otpstacknew ) ;
	  if ( otpstacknew >= ocpstacksize ) 
	  overflowocpstacksize () ;
	  otpstackbuf [otpstacknew ]= otpcalculatedchar ;
	  incr ( otppc ) ;
	} 
	break ;
      case 10 : 
	{
	  otpfirstarg = otparg + 1 ;
	  incr ( otppc ) ;
	  {
	    if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	    ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66821L ) ;
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
	    otpinstruction = ocptables [otpinputocp ][ ocptables [
	    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	    otpstateptr ]* 2 ]+ otppc ];
	    otpinstr = otpinstruction / 16777216L ;
	    otparg = otpinstruction % 16777216L ;
	  } 
	  otpsecondarg = otpnoinputchars - otparg ;
	  {register integer for_end; otpcounter = otpfirstarg ;for_end = 
	  otpsecondarg ; if ( otpcounter <= for_end) do 
	    {
	      {
		if ( ( 1 > otpcounter ) || ( otpcounter > otpnoinputchars ) ) 
		{
		  {
		    if ( interaction == 3 ) 
		    ;
		    if ( filelineerrorstylep ) 
		    printfileline () ;
		    else printnl ( 65548L ) ;
		    print ( 66823L ) ;
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
		if ( otpcounter > otpstacklast ) 
		{
		  otpcalculatedchar = otpinputbuf [otpinputstart + otpcounter 
		  - otpstacklast ];
		} 
		else {
		    
		  otpcalculatedchar = otpstackbuf [otpcounter ];
		} 
	      } 
	      incr ( otpstacknew ) ;
	      if ( otpstacknew >= ocpstacksize ) 
	      overflowocpstacksize () ;
	      otpstackbuf [otpstacknew ]= otpcalculatedchar ;
	    } 
	  while ( otpcounter++ < for_end ) ;} 
	  incr ( otppc ) ;
	} 
	break ;
      case 11 : 
	{
	  otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]+ otpcalcs 
	  [otpcalcptr ];
	  incr ( otppc ) ;
	  decr ( otpcalcptr ) ;
	} 
	break ;
      case 12 : 
	{
	  otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]- otpcalcs 
	  [otpcalcptr ];
	  incr ( otppc ) ;
	  decr ( otpcalcptr ) ;
	} 
	break ;
      case 13 : 
	{
	  otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]* otpcalcs 
	  [otpcalcptr ];
	  incr ( otppc ) ;
	  decr ( otpcalcptr ) ;
	} 
	break ;
      case 14 : 
	{
	  otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]/ otpcalcs 
	  [otpcalcptr ];
	  incr ( otppc ) ;
	  decr ( otpcalcptr ) ;
	} 
	break ;
      case 15 : 
	{
	  otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]% otpcalcs 
	  [otpcalcptr ];
	  incr ( otppc ) ;
	  decr ( otpcalcptr ) ;
	} 
	break ;
      case 16 : 
	{
	  if ( otpcalcs [otpcalcptr ]>= ocptables [otpinputocp ][ ocptables 
	  [otpinputocp ][ 9 ]+ otpcalcs [otpcalcptr - 1 ]* 2 + 1 ]) 
	  {
	    {
	      if ( interaction == 3 ) 
	      ;
	      if ( filelineerrorstylep ) 
	      printfileline () ;
	      else printnl ( 65548L ) ;
	      print ( 66824L ) ;
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
	  otpcalcs [otpcalcptr - 1 ]= ocptables [otpinputocp ][ ocptables [
	  otpinputocp ][ ocptables [otpinputocp ][ 9 ]+ otpcalcs [
	  otpcalcptr - 1 ]* 2 ]+ otpcalcs [otpcalcptr ]];
	  incr ( otppc ) ;
	  decr ( otpcalcptr ) ;
	} 
	break ;
      case 17 : 
	{
	  incr ( otpcalcptr ) ;
	  if ( otpcalcptr >= ocpstacksize ) 
	  overflowocpstacksize () ;
	  otpcalcs [otpcalcptr ]= otparg ;
	  incr ( otppc ) ;
	} 
	break ;
      case 18 : 
	{
	  {
	    if ( ( 1 > otparg ) || ( otparg > otpnoinputchars ) ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66823L ) ;
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
	    if ( otparg > otpstacklast ) 
	    {
	      otpcalculatedchar = otpinputbuf [otpinputstart + otparg - 
	      otpstacklast ];
	    } 
	    else {
		
	      otpcalculatedchar = otpstackbuf [otparg ];
	    } 
	  } 
	  incr ( otpcalcptr ) ;
	  if ( otpcalcptr >= ocpstacksize ) 
	  overflowocpstacksize () ;
	  otpcalcs [otpcalcptr ]= otpcalculatedchar ;
	  incr ( otppc ) ;
	} 
	break ;
      case 19 : 
	{
	  {
	    if ( ( 1 > otpnoinputchars - otparg ) || ( otpnoinputchars - 
	    otparg > otpnoinputchars ) ) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66823L ) ;
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
	    if ( otpnoinputchars - otparg > otpstacklast ) 
	    {
	      otpcalculatedchar = otpinputbuf [otpinputstart + 
	      otpnoinputchars - otparg - otpstacklast ];
	    } 
	    else {
		
	      otpcalculatedchar = otpstackbuf [otpnoinputchars - otparg ];
	    } 
	  } 
	  incr ( otpcalcptr ) ;
	  if ( otpcalcptr >= ocpstacksize ) 
	  overflowocpstacksize () ;
	  otpcalcs [otpcalcptr ]= otpcalculatedchar ;
	  incr ( otppc ) ;
	} 
	break ;
      case 20 : 
	{
	  otpinputstart = otpinputlast ;
	  {register integer for_end; otpcounter = 1 ;for_end = ( otpstacknew 
	  - otpstackused ) ; if ( otpcounter <= for_end) do 
	    {
	      otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
	      otpstackused ];
	    } 
	  while ( otpcounter++ < for_end ) ;} 
	  otpstacknew = otpstacknew - otpstackused ;
	  otpstacklast = otpstacknew ;
	  otpstackused = 0 ;
	  otpstates [otpstateptr ]= otparg ;
	  otppc = 0 ;
	} 
	break ;
      case 21 : 
	{
	  otpinputstart = otpinputlast ;
	  {register integer for_end; otpcounter = 1 ;for_end = ( otpstacknew 
	  - otpstackused ) ; if ( otpcounter <= for_end) do 
	    {
	      otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
	      otpstackused ];
	    } 
	  while ( otpcounter++ < for_end ) ;} 
	  otpstacknew = otpstacknew - otpstackused ;
	  otpstacklast = otpstacknew ;
	  otpstackused = 0 ;
	  incr ( otpstateptr ) ;
	  if ( otpstateptr >= ocpstacksize ) 
	  overflowocpstacksize () ;
	  otpstates [otpstateptr ]= otparg ;
	  otppc = 0 ;
	} 
	break ;
      case 22 : 
	{
	  otpinputstart = otpinputlast ;
	  {register integer for_end; otpcounter = 1 ;for_end = ( otpstacknew 
	  - otpstackused ) ; if ( otpcounter <= for_end) do 
	    {
	      otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
	      otpstackused ];
	    } 
	  while ( otpcounter++ < for_end ) ;} 
	  otpstacknew = otpstacknew - otpstackused ;
	  otpstacklast = otpstacknew ;
	  otpstackused = 0 ;
	  if ( otpstateptr > 0 ) 
	  decr ( otpstateptr ) ;
	  otppc = 0 ;
	} 
	break ;
      case 23 : 
	{
	  otpinputstart = otpinputlast ;
	  otpinputlast = otpinputstart ;
	  otpstackused = 0 ;
	  if ( ( otpstacklast == 0 ) && ( otpinputlast >= otpinputend ) ) 
	  otpfinished = true ;
	  else if ( ( otpstackused < otpstacklast ) ) 
	  {
	    incr ( otpstackused ) ;
	    otpinputchar = otpstackbuf [otpstackused ];
	    otpnoinputchars = 1 ;
	    incr ( otppc ) ;
	  } 
	  else {
	      
	    incr ( otpinputlast ) ;
	    otpinputchar = otpinputbuf [otpinputlast ];
	    otpnoinputchars = 1 ;
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 24 : 
	{
	  otpinputlast = otpinputstart ;
	  otpstackused = 0 ;
	  if ( ( otpstackused < otpstacklast ) ) 
	  {
	    incr ( otpstackused ) ;
	    otpinputchar = otpstackbuf [otpstackused ];
	    otpnoinputchars = 1 ;
	    incr ( otppc ) ;
	  } 
	  else {
	      
	    incr ( otpinputlast ) ;
	    otpinputchar = otpinputbuf [otpinputlast ];
	    otpnoinputchars = 1 ;
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 25 : 
	{
	  if ( otpinputstart < otpinputlast ) 
	  {
	    decr ( otpinputlast ) ;
	    otpinputchar = otpinputbuf [otpinputlast ];
	  } 
	  else {
	      
	    decr ( otpstackused ) ;
	    otpinputchar = otpstackbuf [otpstackused ];
	  } 
	  decr ( otpnoinputchars ) ;
	  incr ( otppc ) ;
	} 
	break ;
      case 26 : 
	{
	  otppc = otparg ;
	} 
	break ;
      case 27 : 
	{
	  otpfirstarg = otparg ;
	  incr ( otppc ) ;
	  {
	    if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	    ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66821L ) ;
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
	    otpinstruction = ocptables [otpinputocp ][ ocptables [
	    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	    otpstateptr ]* 2 ]+ otppc ];
	    otpinstr = otpinstruction / 16777216L ;
	    otparg = otpinstruction % 16777216L ;
	  } 
	  if ( otpinputchar != otpfirstarg ) 
	  {
	    otppc = otparg ;
	  } 
	  else {
	      
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 28 : 
	{
	  otpfirstarg = otparg ;
	  incr ( otppc ) ;
	  {
	    if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	    ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66821L ) ;
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
	    otpinstruction = ocptables [otpinputocp ][ ocptables [
	    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	    otpstateptr ]* 2 ]+ otppc ];
	    otpinstr = otpinstruction / 16777216L ;
	    otparg = otpinstruction % 16777216L ;
	  } 
	  if ( otpinputchar == otpfirstarg ) 
	  {
	    otppc = otparg ;
	  } 
	  else {
	      
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 29 : 
	{
	  otpfirstarg = otparg ;
	  incr ( otppc ) ;
	  {
	    if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	    ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66821L ) ;
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
	    otpinstruction = ocptables [otpinputocp ][ ocptables [
	    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	    otpstateptr ]* 2 ]+ otppc ];
	    otpinstr = otpinstruction / 16777216L ;
	    otparg = otpinstruction % 16777216L ;
	  } 
	  if ( otpinputchar < otpfirstarg ) 
	  {
	    otppc = otparg ;
	  } 
	  else {
	      
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 30 : 
	{
	  otpfirstarg = otparg ;
	  incr ( otppc ) ;
	  {
	    if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	    ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66821L ) ;
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
	    otpinstruction = ocptables [otpinputocp ][ ocptables [
	    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	    otpstateptr ]* 2 ]+ otppc ];
	    otpinstr = otpinstruction / 16777216L ;
	    otparg = otpinstruction % 16777216L ;
	  } 
	  if ( otpinputchar <= otpfirstarg ) 
	  {
	    otppc = otparg ;
	  } 
	  else {
	      
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 31 : 
	{
	  otpfirstarg = otparg ;
	  incr ( otppc ) ;
	  {
	    if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	    ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66821L ) ;
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
	    otpinstruction = ocptables [otpinputocp ][ ocptables [
	    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	    otpstateptr ]* 2 ]+ otppc ];
	    otpinstr = otpinstruction / 16777216L ;
	    otparg = otpinstruction % 16777216L ;
	  } 
	  if ( otpinputchar > otpfirstarg ) 
	  {
	    otppc = otparg ;
	  } 
	  else {
	      
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 32 : 
	{
	  otpfirstarg = otparg ;
	  incr ( otppc ) ;
	  {
	    if ( otppc >= ocptables [otpinputocp ][ ocptables [otpinputocp 
	    ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
	    {
	      {
		if ( interaction == 3 ) 
		;
		if ( filelineerrorstylep ) 
		printfileline () ;
		else printnl ( 65548L ) ;
		print ( 66821L ) ;
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
	    otpinstruction = ocptables [otpinputocp ][ ocptables [
	    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
	    otpstateptr ]* 2 ]+ otppc ];
	    otpinstr = otpinstruction / 16777216L ;
	    otparg = otpinstruction % 16777216L ;
	  } 
	  if ( otpinputchar >= otpfirstarg ) 
	  {
	    otppc = otparg ;
	  } 
	  else {
	      
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 33 : 
	{
	  if ( ( otpstackused < otpstacklast ) ) 
	  {
	    incr ( otpstackused ) ;
	    otpinputchar = otpstackbuf [otpstackused ];
	    incr ( otpnoinputchars ) ;
	    incr ( otppc ) ;
	  } 
	  else if ( otpinputlast >= otpinputend ) 
	  {
	    otppc = otparg ;
	  } 
	  else {
	      
	    incr ( otpinputlast ) ;
	    otpinputchar = otpinputbuf [otpinputlast ];
	    incr ( otpnoinputchars ) ;
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 34 : 
	{
	  if ( otpinputlast == 0 ) 
	  {
	    otppc = otparg ;
	  } 
	  else {
	      
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 35 : 
	{
	  if ( otpinputlast >= otpinputend ) 
	  {
	    otppc = otparg ;
	  } 
	  else {
	      
	    incr ( otppc ) ;
	  } 
	} 
	break ;
      case 36 : 
	{
	  otpinputstart = otpinputlast ;
	  {register integer for_end; otpcounter = 1 ;for_end = ( otpstacknew 
	  - otpstackused ) ; if ( otpcounter <= for_end) do 
	    {
	      otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
	      otpstackused ];
	    } 
	  while ( otpcounter++ < for_end ) ;} 
	  otpstacknew = otpstacknew - otpstackused ;
	  otpstacklast = otpstacknew ;
	  otpstackused = 0 ;
	  otppc = 0 ;
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
	    print ( 66822L ) ;
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
	break ;
      } 
    } 
    if ( ( first + otpoutputend ) >= bufsize ) 
    overflow ( 65542L , bufsize ) ;
    curinput .statefield = 33 ;
    curinput .startfield = first ;
    last = curinput .startfield ;
    curinput .locfield = curinput .startfield ;
    {register integer for_end; otpcounter = 1 ;for_end = otpoutputend ; if ( 
    otpcounter <= for_end) do 
      {
	buffer [last ]= otpoutputbuf [otpcounter ];
	incr ( last ) ;
      } 
    while ( otpcounter++ < for_end ) ;} 
    while ( buffer [last - 1 ]== ' ' ) decr ( last ) ;
    curinput .limitfield = last - 1 ;
    Result = true ;
  } 
  return Result ;
} 
void 
znewocp ( smallnumber a ) 
{
  /* 50 */ newocp_regmem 
  halfword u  ;
  internalocpnumber f  ;
  strnumber t  ;
  unsigned char oldsetting  ;
  strnumber flushablestring  ;
  boolean externalocp  ;
  if ( jobname == 0 ) 
  openlogfile () ;
  if ( curchr == 1 ) 
  externalocp = true ;
  else externalocp = false ;
  getrtoken () ;
  u = curcs ;
  if ( u >= 131074L ) 
  t = newhashtext ( 1246116L + u ) ;
  else if ( u >= 65537L ) {
      
    if ( u == 131073L ) 
    t = 66842L ;
    else t = u - 65537L ;
  } 
  else {
      
    oldsetting = selector ;
    selector = 21 ;
    print ( 66842L ) ;
    print ( u - 1 ) ;
    selector = oldsetting ;
    {
      if ( poolptr + 1 > poolsize ) 
      overflow ( 65543L , poolsize - initpoolptr ) ;
    } 
    t = makestring () ;
  } 
  if ( ( a >= 4 ) ) 
  geqdefine ( u , 107 , 0 ) ;
  else eqdefine ( u , 107 , 0 ) ;
  scanoptionalequals () ;
  scanfilename () ;
  flushablestring = strptr - 1 ;
  {register integer for_end; f = 1 ;for_end = ocpptr ; if ( f <= for_end) do 
    if ( streqstr ( ocptables [f ][ 1 ], curname ) && streqstr ( ocptables [
    f ][ 2 ], curarea ) ) 
    {
      if ( curname == flushablestring ) 
      {
	{
	  decr ( strptr ) ;
	  poolptr = strstartar [strptr - 65536L ];
	} 
	curname = ocptables [f ][ 1 ];
      } 
      goto lab50 ;
    } 
  while ( f++ < for_end ) ;} 
  f = readocpinfo ( u , curname , curarea , curext , externalocp ) ;
  lab50: setequiv ( u , f ) ;
  setneweqtb ( 262157L + f , neweqtb ( u ) ) ;
  sethashtext ( 1508273L + f , t ) ;
  if ( newequiv ( 524335L ) == 1 ) 
  {
    printnl ( 65624L ) ;
    printesc ( 66825L ) ;
    printesc ( t ) ;
    print ( 61 ) ;
    print ( curname ) ;
  } 
} 
void 
znewocplist ( smallnumber a ) 
{
  newocplist_regmem 
  halfword u  ;
  internalocplistnumber f  ;
  strnumber t  ;
  unsigned char oldsetting  ;
  if ( jobname == 0 ) 
  openlogfile () ;
  getrtoken () ;
  u = curcs ;
  if ( u >= 131074L ) 
  t = newhashtext ( 1246116L + u ) ;
  else if ( u >= 65537L ) {
      
    if ( u == 131073L ) 
    t = 66843L ;
    else t = u - 65537L ;
  } 
  else {
      
    oldsetting = selector ;
    selector = 21 ;
    print ( 66843L ) ;
    print ( u - 1 ) ;
    selector = oldsetting ;
    {
      if ( poolptr + 1 > poolsize ) 
      overflow ( 65543L , poolsize - initpoolptr ) ;
    } 
    t = makestring () ;
  } 
  if ( ( a >= 4 ) ) 
  geqdefine ( u , 109 , 0 ) ;
  else eqdefine ( u , 109 , 0 ) ;
  scanoptionalequals () ;
  f = readocplist () ;
  setequiv ( u , f ) ;
  setneweqtb ( 327693L + f , neweqtb ( u ) ) ;
  sethashtext ( 1573809L + f , t ) ;
  if ( newequiv ( 524335L ) == 1 ) 
  {
    printnl ( 65624L ) ;
    printesc ( 66827L ) ;
    printesc ( t ) ;
    print ( 61 ) ;
    printocplist ( ocplistlist [f ]) ;
  } 
} 
void 
zdopushocplist ( smallnumber a ) 
{
  dopushocplist_regmem 
  halfword ocplistno  ;
  halfword oldnumber  ;
  integer i  ;
  scanocplistident () ;
  ocplistno = curval ;
  oldnumber = newequiv ( 524336L ) ;
  if ( ( a >= 4 ) ) 
  geqdefine ( 524339L + oldnumber , 137 , ocplistno ) ;
  else eqdefine ( 524339L + oldnumber , 137 , ocplistno ) ;
  if ( ( a >= 4 ) ) 
  geqdefine ( 524336L , 137 , ( oldnumber + 1 ) ) ;
  else eqdefine ( 524336L , 137 , ( oldnumber + 1 ) ) ;
  if ( newequiv ( 524335L ) == 1 ) 
  {
    printnl ( 66844L ) ;
    {register integer for_end; i = oldnumber ;for_end = 0 ; if ( i >= 
    for_end) do 
      {
	printesc ( newhashtext ( 1573809L + newequiv ( 524339L + i ) ) ) ;
	print ( 61 ) ;
	printocplist ( ocplistlist [newequiv ( 524339L + i ) ]) ;
	if ( i != 0 ) 
	print ( 44 ) ;
      } 
    while ( i-- > for_end ) ;} 
    print ( 125 ) ;
  } 
  activecompile () ;
  if ( ( a >= 4 ) ) 
  geqdefine ( 524337L , 137 , activeminptr ) ;
  else eqdefine ( 524337L , 137 , activeminptr ) ;
  if ( ( a >= 4 ) ) 
  geqdefine ( 524338L , 137 , activemaxptr ) ;
  else eqdefine ( 524338L , 137 , activemaxptr ) ;
} 
void 
zdopopocplist ( smallnumber a ) 
{
  dopopocplist_regmem 
  halfword oldnumber  ;
  integer i  ;
  oldnumber = newequiv ( 524336L ) ;
  if ( oldnumber == 0 ) 
  {
    {
      if ( interaction == 3 ) 
      ;
      if ( filelineerrorstylep ) 
      printfileline () ;
      else printnl ( 65548L ) ;
      print ( 66845L ) ;
    } 
  } 
  else if ( ( a >= 4 ) ) 
  geqdefine ( 524336L , 137 , ( oldnumber - 1 ) ) ;
  else eqdefine ( 524336L , 137 , ( oldnumber - 1 ) ) ;
  if ( newequiv ( 524335L ) == 1 ) 
  {
    printnl ( 66844L ) ;
    {register integer for_end; i = ( oldnumber - 2 ) ;for_end = 0 ; if ( i 
    >= for_end) do 
      {
	printesc ( newhashtext ( 1573809L + newequiv ( 524339L + i ) ) ) ;
	print ( 61 ) ;
	printocplist ( ocplistlist [newequiv ( 524339L + i ) ]) ;
	if ( i != 0 ) 
	print ( 44 ) ;
      } 
    while ( i-- > for_end ) ;} 
    print ( 125 ) ;
  } 
  activecompile () ;
  if ( ( a >= 4 ) ) 
  geqdefine ( 524337L , 137 , activeminptr ) ;
  else eqdefine ( 524337L , 137 , activeminptr ) ;
  if ( ( a >= 4 ) ) 
  geqdefine ( 524338L , 137 , activemaxptr ) ;
  else eqdefine ( 524338L , 137 , activemaxptr ) ;
} 
void 
zdoclearocplists ( smallnumber a ) 
{
  doclearocplists_regmem 
  if ( ( a >= 4 ) ) 
  geqdefine ( 524336L , 137 , 0 ) ;
  else eqdefine ( 524336L , 137 , 0 ) ;
  activecompile () ;
  if ( ( a >= 4 ) ) 
  geqdefine ( 524337L , 137 , activeminptr ) ;
  else eqdefine ( 524337L , 137 , activeminptr ) ;
  if ( ( a >= 4 ) ) 
  geqdefine ( 524338L , 137 , activemaxptr ) ;
  else eqdefine ( 524338L , 137 , activemaxptr ) ;
} 
void 
doassignments ( void ) 
{
  /* 10 */ doassignments_regmem 
  while ( true ) {
      
    do {
	getxtoken () ;
    } while ( ! ( ( curcmd != 10 ) && ( curcmd != 0 ) ) ) ;
    if ( curcmd <= 73 ) 
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
    if ( kpseinnameok ( nameoffile + 1 ) && aopenin ( readfile [n ], 
    kpsetexformat ) ) 
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
    overflow ( 65543L , poolsize - initpoolptr ) ;
  } 
  s = makestring () ;
  if ( c == 0 ) 
  {
    if ( termoffset + length ( s ) > maxprintline - 2 ) 
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
      else printnl ( 65548L ) ;
      print ( 65624L ) ;
    } 
    slowprint ( s ) ;
    if ( newequiv ( 524334L ) != 0 ) 
    useerrhelp = true ;
    else if ( longhelpseen ) 
    {
      helpptr = 1 ;
      helpline [0 ]= 66607L ;
    } 
    else {
	
      if ( interaction < 3 ) 
      longhelpseen = true ;
      {
	helpptr = 4 ;
	helpline [3 ]= 66608L ;
	helpline [2 ]= 66609L ;
	helpline [1 ]= 66610L ;
	helpline [0 ]= 66611L ;
      } 
    } 
    error () ;
    useerrhelp = false ;
  } 
  {
    decr ( strptr ) ;
    poolptr = strstartar [strptr - 65536L ];
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
  while ( p != 0 ) {
      
    t = mem [p ].hh .v.LH ;
    if ( t < 1114112L ) 
    {
      c = t % 65536L ;
      if ( newequiv ( b + c ) != 0 ) 
      mem [p ].hh .v.LH = t - c + newequiv ( b + c ) ;
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
      scaneightbitint () ;
      begindiagnostic () ;
      printnl ( 66627L ) ;
      printint ( curval ) ;
      printchar ( 61 ) ;
      if ( newequiv ( 655423L + curval ) == 0 ) 
      print ( 65696L ) ;
      else showbox ( newequiv ( 655423L + curval ) ) ;
    } 
    break ;
  case 0 : 
    {
      gettoken () ;
      if ( interaction == 3 ) 
      ;
      printnl ( 66623L ) ;
      if ( curcs != 0 ) 
      {
	sprintcs ( curcs ) ;
	printchar ( 61 ) ;
      } 
      printmeaning () ;
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
      printnl ( 65624L ) ;
      println () ;
      if ( condptr == 0 ) 
      {
	printnl ( 65649L ) ;
	print ( 66752L ) ;
      } 
      else {
	  
	p = condptr ;
	n = 0 ;
	do {
	    incr ( n ) ;
	  p = mem [p ].hh .v.RH ;
	} while ( ! ( p == 0 ) ) ;
	p = condptr ;
	t = curif ;
	l = ifline ;
	m = iflimit ;
	do {
	    printnl ( 66753L ) ;
	  printint ( n ) ;
	  print ( 65873L ) ;
	  printcmdchr ( 122 , t ) ;
	  if ( m == 2 ) 
	  printesc ( 66103L ) ;
	  if ( l != 0 ) 
	  {
	    print ( 66751L ) ;
	    printint ( l ) ;
	  } 
	  decr ( n ) ;
	  t = mem [p ].hh.b1 ;
	  l = mem [p + 1 ].cint ;
	  m = mem [p ].hh.b0 ;
	  p = mem [p ].hh .v.RH ;
	} while ( ! ( p == 0 ) ) ;
      } 
    } 
    break ;
    default: 
    {
      p = thetoks () ;
      if ( interaction == 3 ) 
      ;
      printnl ( 66623L ) ;
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
    else printnl ( 65548L ) ;
    print ( 66628L ) ;
  } 
  if ( selector == 19 ) {
      
    if ( neweqtbint ( 1049437L ) <= 0 ) 
    {
      selector = 17 ;
      print ( 66629L ) ;
      selector = 19 ;
    } 
  } 
  lab50: if ( interaction < 3 ) 
  {
    helpptr = 0 ;
    decr ( errorcount ) ;
  } 
  else if ( neweqtbint ( 1049437L ) > 0 ) 
  {
    {
      helpptr = 3 ;
      helpline [2 ]= 66618L ;
      helpline [1 ]= 66619L ;
      helpline [0 ]= 66620L ;
    } 
  } 
  else {
      
    {
      helpptr = 5 ;
      helpline [4 ]= 66618L ;
      helpline [3 ]= 66619L ;
      helpline [2 ]= 66620L ;
      helpline [1 ]= 66621L ;
      helpline [0 ]= 66622L ;
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
  mem [p ].hh.b0 = 8 ;
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
      mem [curlist .tailfield + 1 ].hh .v.RH = 0 ;
    } 
    break ;
  case 3 : 
    {
      newwhatsit ( 3 , 2 ) ;
      mem [curlist .tailfield + 1 ].hh .v.LH = 0 ;
      p = scantoks ( false , true ) ;
      mem [curlist .tailfield + 1 ].hh .v.RH = defref ;
    } 
    break ;
  case 4 : 
    {
      getxtoken () ;
      if ( ( curcmd == 59 ) && ( curchr <= 2 ) ) 
      {
	p = curlist .tailfield ;
	doextension () ;
	outwhat ( curlist .tailfield ) ;
	flushnodelist ( curlist .tailfield ) ;
	curlist .tailfield = p ;
	mem [p ].hh .v.RH = 0 ;
      } 
      else backinput () ;
    } 
    break ;
  case 5 : 
    if ( abs ( curlist .modefield ) != 119 ) 
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
      mem [curlist .tailfield + 1 ].hh.b0 = normmin ( neweqtbint ( 1049459L 
      ) ) ;
      mem [curlist .tailfield + 1 ].hh.b1 = normmin ( neweqtbint ( 1049460L 
      ) ) ;
    } 
    break ;
    default: 
    confusion ( 66674L ) ;
    break ;
  } 
} 
void 
fixlanguage ( void ) 
{
  fixlanguage_regmem 
  ASCIIcode l  ;
  if ( neweqtbint ( 1049458L ) <= 0 ) 
  l = 0 ;
  else if ( neweqtbint ( 1049458L ) > 255 ) 
  l = 0 ;
  else l = neweqtbint ( 1049458L ) ;
  if ( l != curlist .auxfield .hh .v.RH ) 
  {
    newwhatsit ( 4 , 2 ) ;
    mem [curlist .tailfield + 1 ].hh .v.RH = l ;
    curlist .auxfield .hh .v.RH = l ;
    mem [curlist .tailfield + 1 ].hh.b0 = normmin ( neweqtbint ( 1049459L ) 
    ) ;
    mem [curlist .tailfield + 1 ].hh.b1 = normmin ( neweqtbint ( 1049460L ) 
    ) ;
  } 
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
    mem [p ].hh .v.LH = specialtoken ;
    mem [p ].hh .v.RH = getavail () ;
    p = mem [p ].hh .v.RH ;
    mem [p ].hh .v.LH = 65659L ;
    q = strtoks ( makesrcspecial ( sourcefilenamestack [inopen ], line ) ) ;
    mem [p ].hh .v.RH = mem [memtop - 3 ].hh .v.RH ;
    p = q ;
    mem [p ].hh .v.RH = getavail () ;
    p = mem [p ].hh .v.RH ;
    mem [p ].hh .v.LH = 131197L ;
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
    mem [defref ].hh .v.LH = 0 ;
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
  scaled d  ;
  integer f  ;
  switch ( curgroup ) 
  {case 1 : 
    {
      tempnowhatsits = neweqtbint ( 1049465L ) ;
      tempnodirs = neweqtbint ( 1049466L ) ;
      temporarydir = neweqtbint ( 1049482L ) ;
      if ( mem [textdirptr + 1 ].hh .v.RH == curlevel ) 
      {
	textdirtmp = mem [textdirptr ].hh .v.RH ;
	freenode ( textdirptr , 4 ) ;
	textdirptr = textdirtmp ;
      } 
      unsave () ;
      if ( abs ( curlist .modefield ) == 119 ) 
      {
	if ( tempnodirs != 0 ) 
	{
	  {
	    mem [curlist .tailfield ].hh .v.RH = newdir ( neweqtbint ( 
	    1049482L ) ) ;
	    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	  } 
	  mem [curlist .tailfield + 1 ].hh .v.LH = temporarydir - 64 ;
	} 
	if ( tempnowhatsits != 0 ) 
	{
	  {
	    mem [curlist .tailfield ].hh .v.RH = makelocalparnode () ;
	    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	  } 
	} 
      } 
    } 
    break ;
  case 0 : 
    {
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 66401L ) ;
      } 
      {
	helpptr = 2 ;
	helpline [1 ]= 66402L ;
	helpline [0 ]= 66403L ;
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
    package ( 0 ) ;
    break ;
  case 3 : 
    {
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
      q = newequiv ( 393240L ) ;
      incr ( mem [q ].hh .v.RH ) ;
      d = neweqtbsc ( 1180556L + ( 6 ) ) ;
      f = neweqtbint ( 1049450L ) ;
      unsave () ;
      decr ( saveptr ) ;
      p = vpackage ( mem [curlist .headfield ].hh .v.RH , 0 , 1 , 
      1073741823L ) ;
      popnest () ;
      if ( savestack [saveptr + 0 ].cint != 255 ) 
      {
	{
	  mem [curlist .tailfield ].hh .v.RH = getnode ( 5 ) ;
	  curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	} 
	mem [curlist .tailfield ].hh.b0 = 3 ;
	mem [curlist .tailfield ].hh.b1 = savestack [saveptr + 0 ].cint ;
	mem [curlist .tailfield + 3 ].cint = mem [p + 3 ].cint + mem [p + 
	2 ].cint ;
	mem [curlist .tailfield + 4 ].hh .v.LH = mem [p + 5 ].hh .v.RH ;
	mem [curlist .tailfield + 4 ].hh .v.RH = q ;
	mem [curlist .tailfield + 2 ].cint = d ;
	mem [curlist .tailfield + 1 ].cint = f ;
      } 
      else {
	  
	{
	  mem [curlist .tailfield ].hh .v.RH = getnode ( 2 ) ;
	  curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	} 
	mem [curlist .tailfield ].hh.b0 = 5 ;
	mem [curlist .tailfield ].hh.b1 = 0 ;
	mem [curlist .tailfield + 1 ].cint = mem [p + 5 ].hh .v.RH ;
	deleteglueref ( q ) ;
      } 
      freenode ( p , 8 ) ;
      if ( nestptr == 0 ) 
      buildpage () ;
    } 
    break ;
  case 8 : 
    {
      if ( ( curinput .locfield != 0 ) || ( ( curinput .indexfield != 6 ) && ( 
      curinput .indexfield != 3 ) ) ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66367L ) ;
	} 
	{
	  helpptr = 2 ;
	  helpline [1 ]= 66368L ;
	  helpline [0 ]= 66369L ;
	} 
	error () ;
	do {
	    gettoken () ;
	} while ( ! ( curinput .locfield == 0 ) ) ;
      } 
      endtokenlist () ;
      endgraf () ;
      unsave () ;
      outputactive = false ;
      insertpenalties = 0 ;
      if ( newequiv ( 655678L ) != 0 ) 
      {
	{
	  if ( interaction == 3 ) 
	  ;
	  if ( filelineerrorstylep ) 
	  printfileline () ;
	  else printnl ( 65548L ) ;
	  print ( 66370L ) ;
	} 
	printesc ( 65695L ) ;
	printint ( 255 ) ;
	{
	  helpptr = 3 ;
	  helpline [2 ]= 66371L ;
	  helpline [1 ]= 66372L ;
	  helpline [0 ]= 66373L ;
	} 
	boxerror ( 255 ) ;
      } 
      if ( curlist .tailfield != curlist .headfield ) 
      {
	mem [pagetail ].hh .v.RH = mem [curlist .headfield ].hh .v.RH ;
	pagetail = curlist .tailfield ;
      } 
      if ( mem [memtop - 2 ].hh .v.RH != 0 ) 
      {
	if ( mem [memtop - 1 ].hh .v.RH == 0 ) 
	nest [0 ].tailfield = pagetail ;
	mem [pagetail ].hh .v.RH = mem [memtop - 1 ].hh .v.RH ;
	mem [memtop - 1 ].hh .v.RH = mem [memtop - 2 ].hh .v.RH ;
	mem [memtop - 2 ].hh .v.RH = 0 ;
	pagetail = memtop - 2 ;
      } 
      flushnodelist ( discptr [2 ]) ;
      discptr [2 ]= 0 ;
      popnest () ;
      buildpage () ;
    } 
    break ;
  case 10 : 
    builddiscretionary () ;
    break ;
  case 17 : 
    buildlocalbox () ;
    break ;
  case 6 : 
    {
      backinput () ;
      curtok = 1245186L ;
      {
	if ( interaction == 3 ) 
	;
	if ( filelineerrorstylep ) 
	printfileline () ;
	else printnl ( 65548L ) ;
	print ( 65934L ) ;
      } 
      printesc ( 66255L ) ;
      print ( 65935L ) ;
      {
	helpptr = 1 ;
	helpline [0 ]= 66485L ;
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
      popnest () ;
      {
	mem [curlist .tailfield ].hh .v.RH = newnoad () ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [curlist .tailfield ].hh.b0 = 29 ;
      mem [curlist .tailfield + 1 ].hh .v.RH = 2 ;
      mem [curlist .tailfield + 1 ].hh .v.LH = p ;
    } 
    break ;
  case 13 : 
    buildchoices () ;
    break ;
  case 9 : 
    {
      {
	unsave () ;
	decr ( saveptr ) ;
	flushnodelist ( textdirptr ) ;
	textdirptr = savestack [saveptr + 0 ].cint ;
      } 
      decr ( saveptr ) ;
      mem [savestack [saveptr + 0 ].cint ].hh .v.RH = 3 ;
      p = finmlist ( 0 ) ;
      mem [savestack [saveptr + 0 ].cint ].hh .v.LH = p ;
      if ( p != 0 ) {
	  
	if ( mem [p ].hh .v.RH == 0 ) {
	    
	  if ( mem [p ].hh.b0 == 16 ) 
	  {
	    if ( mem [p + 3 ].hh .v.RH == 0 ) {
		
	      if ( mem [p + 2 ].hh .v.RH == 0 ) 
	      {
		mem [savestack [saveptr + 0 ].cint ].hh = mem [p + 1 ]
		.hh ;
		freenode ( p , 4 ) ;
	      } 
	    } 
	  } 
	  else if ( mem [p ].hh.b0 == 28 ) {
	      
	    if ( savestack [saveptr + 0 ].cint == curlist .tailfield + 1 ) {
		
	      if ( mem [curlist .tailfield ].hh.b0 == 16 ) 
	      {
		q = curlist .headfield ;
		while ( mem [q ].hh .v.RH != curlist .tailfield ) q = mem [
		q ].hh .v.RH ;
		mem [q ].hh .v.RH = p ;
		freenode ( curlist .tailfield , 4 ) ;
		curlist .tailfield = p ;
	      } 
	    } 
	  } 
	} 
      } 
    } 
    break ;
    default: 
    confusion ( 66404L ) ;
    break ;
  } 
} 
void 
maincontrol ( void ) 
{
  /* 60 21 70 80 90 91 92 95 100 101 110 111 112 120 10 */ 
  maincontrol_regmem 
  integer t  ;
  if ( newequiv ( 524331L ) != 0 ) 
  begintokenlist ( newequiv ( 524331L ) , 12 ) ;
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
  if ( neweqtbint ( 1049444L ) > 0 ) 
  showcurcmdchr () ;
  switch ( abs ( curlist .modefield ) + curcmd ) 
  {case 130 : 
  case 131 : 
  case 189 : 
    goto lab70 ;
    break ;
  case 135 : 
    {
      scancharnum () ;
      curchr = curval ;
      goto lab70 ;
    } 
    break ;
  case 184 : 
    {
      getxtoken () ;
      if ( ( curcmd == 11 ) || ( curcmd == 12 ) || ( curcmd == 70 ) || ( 
      curcmd == 16 ) ) 
      cancelboundary = true ;
      goto lab21 ;
    } 
    break ;
  case 187 : 
    {
      t = curchr ;
      getxtoken () ;
      if ( ( curcmd == 11 ) || ( curcmd == 12 ) || ( curcmd == 70 ) || ( 
      curcmd == 16 ) ) 
      {
	if ( t == 0 ) 
	newleftghost = true ;
	else newrightghost = true ;
      } 
      goto lab21 ;
    } 
    break ;
  case 129 : 
    if ( curlist .auxfield .hh .v.LH == 1000 ) 
    goto lab120 ;
    else appspace () ;
    break ;
  case 183 : 
  case 301 : 
    goto lab120 ;
    break ;
  case 1 : 
  case 119 : 
  case 237 : 
  case 11 : 
  case 247 : 
  case 302 : 
    ;
    break ;
  case 40 : 
  case 158 : 
  case 276 : 
    {
      do {
	  getxtoken () ;
      } while ( ! ( curcmd != 10 ) ) ;
      goto lab21 ;
    } 
    break ;
  case 15 : 
    if ( itsallover () ) 
    return ;
    break ;
  case 23 : 
  case 140 : 
  case 258 : 
  case 74 : 
  case 192 : 
  case 310 : 
  case 39 : 
  case 45 : 
  case 49 : 
  case 167 : 
  case 7 : 
  case 125 : 
  case 243 : 
    reportillegalcase () ;
    break ;
  case 8 : 
  case 126 : 
  case 9 : 
  case 127 : 
  case 18 : 
  case 136 : 
  case 72 : 
  case 190 : 
  case 73 : 
  case 191 : 
  case 51 : 
  case 169 : 
  case 16 : 
  case 134 : 
  case 50 : 
  case 168 : 
  case 53 : 
  case 171 : 
  case 67 : 
  case 185 : 
  case 54 : 
  case 172 : 
  case 55 : 
  case 173 : 
  case 57 : 
  case 175 : 
  case 56 : 
  case 174 : 
  case 31 : 
  case 149 : 
  case 52 : 
  case 170 : 
  case 29 : 
  case 147 : 
  case 47 : 
  case 165 : 
  case 246 : 
  case 250 : 
  case 251 : 
  case 264 : 
  case 261 : 
  case 270 : 
  case 273 : 
    insertdollarsign () ;
    break ;
  case 37 : 
  case 154 : 
  case 272 : 
    {
      {
	mem [curlist .tailfield ].hh .v.RH = scanrulespec () ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      if ( abs ( curlist .modefield ) == 1 ) 
      curlist .auxfield .cint = -65536000L ;
      else if ( abs ( curlist .modefield ) == 119 ) 
      curlist .auxfield .hh .v.LH = 1000 ;
    } 
    break ;
  case 28 : 
  case 145 : 
  case 263 : 
  case 265 : 
    appendglue () ;
    break ;
  case 30 : 
  case 148 : 
  case 266 : 
  case 267 : 
    appendkern () ;
    break ;
  case 2 : 
  case 120 : 
    {
      newsavelevel ( 1 ) ;
      eqworddefine ( 1049465L , 0 ) ;
      eqworddefine ( 1049466L , 0 ) ;
    } 
    break ;
  case 62 : 
  case 180 : 
  case 298 : 
    {
      newsavelevel ( 14 ) ;
      eqworddefine ( 1049465L , 0 ) ;
      eqworddefine ( 1049466L , 0 ) ;
    } 
    break ;
  case 63 : 
  case 181 : 
  case 299 : 
    if ( curgroup == 14 ) 
    {
      tempnowhatsits = neweqtbint ( 1049465L ) ;
      tempnodirs = neweqtbint ( 1049466L ) ;
      temporarydir = neweqtbint ( 1049482L ) ;
      if ( mem [textdirptr + 1 ].hh .v.RH == curlevel ) 
      {
	textdirtmp = mem [textdirptr ].hh .v.RH ;
	freenode ( textdirptr , 4 ) ;
	textdirptr = textdirtmp ;
      } 
      unsave () ;
      if ( abs ( curlist .modefield ) == 119 ) 
      {
	if ( tempnodirs != 0 ) 
	{
	  {
	    mem [curlist .tailfield ].hh .v.RH = newdir ( neweqtbint ( 
	    1049482L ) ) ;
	    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	  } 
	  mem [curlist .tailfield + 1 ].hh .v.LH = temporarydir - 64 ;
	} 
	if ( tempnowhatsits != 0 ) 
	{
	  {
	    mem [curlist .tailfield ].hh .v.RH = makelocalparnode () ;
	    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	  } 
	} 
      } 
    } 
    else offsave () ;
    break ;
  case 3 : 
  case 121 : 
  case 239 : 
    handlerightbrace () ;
    break ;
  case 22 : 
  case 141 : 
  case 259 : 
    {
      t = curchr ;
      scandimen ( false , false , false ) ;
      if ( t == 0 ) 
      scanbox ( curval ) ;
      else scanbox ( - (integer) curval ) ;
    } 
    break ;
  case 32 : 
  case 150 : 
  case 268 : 
    scanbox ( ( ( ( 1073807360L ) + 65536L ) + 1 ) - 99 + curchr ) ;
    break ;
  case 21 : 
  case 139 : 
  case 257 : 
    beginbox ( 0 ) ;
    break ;
  case 95 : 
  case 213 : 
  case 331 : 
    {
      scaneightbitint () ;
      curbox = newequiv ( 655423L + curval ) ;
      scanoptionalequals () ;
      scandir () ;
      if ( curbox != 0 ) 
      mem [curbox + 7 ].cint = curval ;
    } 
    break ;
  case 44 : 
    newgraf ( curchr > 0 ) ;
    break ;
  case 12 : 
  case 13 : 
  case 17 : 
  case 71 : 
  case 69 : 
  case 4 : 
  case 24 : 
  case 36 : 
  case 46 : 
  case 48 : 
  case 27 : 
  case 34 : 
  case 65 : 
  case 66 : 
    {
      backinput () ;
      newgraf ( true ) ;
    } 
    break ;
  case 162 : 
  case 280 : 
    indentinhmode () ;
    break ;
  case 14 : 
    {
      normalparagraph () ;
      if ( curlist .modefield > 0 ) 
      buildpage () ;
    } 
    break ;
  case 132 : 
    {
      if ( alignstate < 0 ) 
      offsave () ;
      endgraf () ;
      if ( curlist .modefield == 1 ) 
      buildpage () ;
    } 
    break ;
  case 133 : 
  case 146 : 
  case 155 : 
  case 143 : 
  case 151 : 
    headforvmode () ;
    break ;
  case 38 : 
  case 156 : 
  case 274 : 
  case 157 : 
  case 275 : 
    begininsertoradjust () ;
    break ;
  case 19 : 
  case 137 : 
  case 255 : 
    makemark () ;
    break ;
  case 43 : 
  case 161 : 
  case 279 : 
    appendpenalty () ;
    break ;
  case 26 : 
  case 144 : 
  case 262 : 
    deletelast () ;
    break ;
  case 25 : 
  case 142 : 
  case 260 : 
    unpackage () ;
    break ;
  case 163 : 
    appenditaliccorrection () ;
    break ;
  case 281 : 
    {
      mem [curlist .tailfield ].hh .v.RH = newkern ( 0 ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    break ;
  case 166 : 
  case 284 : 
    appenddiscretionary () ;
    break ;
  case 70 : 
  case 188 : 
  case 306 : 
    appendlocalbox ( curchr ) ;
    break ;
  case 164 : 
    makeaccent () ;
    break ;
  case 6 : 
  case 124 : 
  case 242 : 
  case 5 : 
  case 123 : 
  case 241 : 
    alignerror () ;
    break ;
  case 35 : 
  case 153 : 
  case 271 : 
    noalignerror () ;
    break ;
  case 64 : 
  case 182 : 
  case 300 : 
    omiterror () ;
    break ;
  case 33 : 
  case 152 : 
    initalign () ;
    break ;
  case 269 : 
    if ( privileged () ) {
	
      if ( curgroup == 15 ) 
      initalign () ;
      else offsave () ;
    } 
    break ;
  case 10 : 
  case 128 : 
    doendv () ;
    break ;
  case 68 : 
  case 186 : 
  case 304 : 
    cserror () ;
    break ;
  case 122 : 
    initmath () ;
    break ;
  case 285 : 
    if ( privileged () ) {
	
      if ( curgroup == 15 ) 
      starteqno () ;
      else offsave () ;
    } 
    break ;
  case 238 : 
    {
      {
	mem [curlist .tailfield ].hh .v.RH = newnoad () ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      backinput () ;
      scanmath ( curlist .tailfield + 1 ) ;
    } 
    break ;
  case 248 : 
  case 249 : 
  case 307 : 
    setmathchar ( newequiv ( 983872L + curchr ) ) ;
    break ;
  case 253 : 
    {
      scancharnum () ;
      curchr = curval ;
      setmathchar ( newequiv ( 983872L + curchr ) ) ;
    } 
    break ;
  case 254 : 
    {
      if ( curchr == 0 ) 
      scanfifteenbitint () ;
      else scanbigfifteenbitint () ;
      setmathchar ( curval ) ;
    } 
    break ;
  case 308 : 
    {
      setmathchar ( ( ( curchr / 4096 ) * 16777216L ) + ( ( ( curchr % 4096 ) 
      / 256 ) * 65536L ) + ( curchr % 256 ) ) ;
    } 
    break ;
  case 309 : 
    {
      setmathchar ( curchr ) ;
    } 
    break ;
  case 252 : 
    {
      if ( curchr == 0 ) 
      scantwentysevenbitint () ;
      else scanfiftyonebitint () ;
      setmathchar ( curval ) ;
    } 
    break ;
  case 287 : 
    {
      {
	mem [curlist .tailfield ].hh .v.RH = newnoad () ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [curlist .tailfield ].hh.b0 = curchr ;
      scanmath ( curlist .tailfield + 1 ) ;
    } 
    break ;
  case 288 : 
    mathlimitswitch () ;
    break ;
  case 303 : 
    mathradical () ;
    break ;
  case 282 : 
  case 283 : 
    mathac () ;
    break ;
  case 293 : 
    {
      scanspec ( 12 , false ) ;
      normalparagraph () ;
      pushnest () ;
      curlist .modefield = -1 ;
      curlist .auxfield .cint = -65536000L ;
      if ( ( insertsrcspecialeveryvbox ) ) 
      insertsrcspecial () ;
      if ( newequiv ( 524330L ) != 0 ) 
      begintokenlist ( newequiv ( 524330L ) , 11 ) ;
    } 
    break ;
  case 290 : 
    {
      mem [curlist .tailfield ].hh .v.RH = newstyle ( curchr ) ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    break ;
  case 292 : 
    {
      {
	mem [curlist .tailfield ].hh .v.RH = newglue ( membot ) ;
	curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
      } 
      mem [curlist .tailfield ].hh.b1 = 98 ;
    } 
    break ;
  case 291 : 
    appendchoices () ;
    break ;
  case 245 : 
  case 244 : 
    subsup () ;
    break ;
  case 289 : 
    mathfraction () ;
    break ;
  case 286 : 
    mathleftright () ;
    break ;
  case 240 : 
    if ( curgroup == 15 ) 
    aftermath () ;
    else offsave () ;
    break ;
  case 75 : 
  case 193 : 
  case 311 : 
  case 76 : 
  case 194 : 
  case 312 : 
  case 77 : 
  case 195 : 
  case 313 : 
  case 96 : 
  case 214 : 
  case 332 : 
  case 78 : 
  case 196 : 
  case 314 : 
  case 79 : 
  case 197 : 
  case 315 : 
  case 80 : 
  case 198 : 
  case 316 : 
  case 81 : 
  case 199 : 
  case 317 : 
  case 82 : 
  case 200 : 
  case 318 : 
  case 83 : 
  case 201 : 
  case 319 : 
  case 84 : 
  case 202 : 
  case 320 : 
  case 85 : 
  case 203 : 
  case 321 : 
  case 86 : 
  case 204 : 
  case 322 : 
  case 87 : 
  case 205 : 
  case 323 : 
  case 88 : 
  case 206 : 
  case 324 : 
  case 89 : 
  case 207 : 
  case 325 : 
  case 90 : 
  case 208 : 
  case 326 : 
  case 91 : 
  case 209 : 
  case 327 : 
  case 92 : 
  case 210 : 
  case 328 : 
  case 93 : 
  case 211 : 
  case 329 : 
  case 97 : 
  case 215 : 
  case 333 : 
  case 98 : 
  case 216 : 
  case 334 : 
  case 99 : 
  case 217 : 
  case 335 : 
  case 100 : 
  case 218 : 
  case 336 : 
  case 101 : 
  case 219 : 
  case 337 : 
  case 102 : 
  case 220 : 
  case 338 : 
  case 103 : 
  case 221 : 
  case 339 : 
  case 104 : 
  case 222 : 
  case 340 : 
  case 105 : 
  case 223 : 
  case 341 : 
  case 106 : 
  case 224 : 
  case 342 : 
  case 107 : 
  case 225 : 
  case 343 : 
  case 108 : 
  case 226 : 
  case 344 : 
  case 109 : 
  case 227 : 
  case 345 : 
  case 110 : 
  case 228 : 
  case 346 : 
  case 111 : 
  case 229 : 
  case 347 : 
  case 112 : 
  case 230 : 
  case 348 : 
  case 113 : 
  case 231 : 
  case 349 : 
  case 114 : 
  case 232 : 
  case 350 : 
  case 115 : 
  case 233 : 
  case 351 : 
  case 116 : 
  case 234 : 
  case 352 : 
    prefixedcommand () ;
    break ;
  case 118 : 
  case 236 : 
  case 354 : 
    docharmode () ;
    break ;
  case 117 : 
  case 235 : 
  case 353 : 
    dochartranslation () ;
    break ;
  case 41 : 
  case 159 : 
  case 277 : 
    {
      gettoken () ;
      aftertoken = curtok ;
    } 
    break ;
  case 42 : 
  case 160 : 
  case 278 : 
    {
      gettoken () ;
      saveforafter ( curtok ) ;
    } 
    break ;
  case 61 : 
  case 179 : 
  case 297 : 
    openorclosein () ;
    break ;
  case 59 : 
  case 177 : 
  case 295 : 
    issuemessage () ;
    break ;
  case 58 : 
  case 176 : 
  case 294 : 
    shiftcase () ;
    break ;
  case 20 : 
  case 138 : 
  case 256 : 
    showwhatever () ;
    break ;
  case 60 : 
  case 178 : 
  case 296 : 
    doextension () ;
    break ;
  } 
  goto lab60 ;
  lab70: if ( islastocp ( curinput .ocplstackfield , curinput .ocpnofield ) ) 
  {
    if ( ( ( curlist .headfield == curlist .tailfield ) && ( curlist 
    .modefield > 0 ) ) ) 
    {
      if ( ( insertsrcspecialauto ) ) 
      appendsrcspecial () ;
    } 
    mains = newequiv ( 918336L + curchr ) ;
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
    mainf = newequiv ( 720959L ) ;
    bchar = fonttables [mainf ][ 19 ].cint ;
    falsebchar = fonttables [mainf ][ 20 ].cint ;
    if ( curlist .modefield > 0 ) {
	
      if ( neweqtbint ( 1049458L ) != curlist .auxfield .hh .v.RH ) 
      fixlanguage () ;
    } 
    {
      ligstack = avail ;
      if ( ligstack == 0 ) 
      ligstack = getavail () ;
      else {
	  
	avail = mem [ligstack ].hh .v.RH ;
	mem [ligstack ].hh .v.RH = 0 ;
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
      leftghost = newleftghost ;
      rightghost = newrightghost ;
      newleftghost = false ;
      newrightghost = false ;
    } 
    else maink = fonttables [mainf ][ 18 ].cint ;
    if ( maink == 0 ) 
    goto lab92 ;
    curr = curl ;
    curl = 65536L ;
    if ( ! newrightghost ) 
    goto lab111 ;
    lab80: if ( curl < 65536L ) 
    {
      if ( mem [curq ].hh .v.RH > 0 ) {
	  
	if ( mem [curlist .tailfield ].hh.b1 == fonttables [mainf ][ 16 ]
	.cint ) 
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
	    
	  if ( ligstack == 0 ) 
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
    lab90: if ( ligstack == 0 ) 
    goto lab21 ;
    curq = curlist .tailfield ;
    curl = mem [ligstack ].hh.b1 ;
    lab91: if ( ! ( ligstack >= himemmin ) ) 
    goto lab95 ;
    lab92: leftghost = newleftghost ;
    rightghost = newrightghost ;
    newleftghost = false ;
    newrightghost = false ;
    if ( ( curchr < fonttables [mainf ][ 12 ].cint ) || ( curchr > 
    fonttables [mainf ][ 13 ].cint ) ) 
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
    maini = fonttables [mainf ][ fonttables [mainf ][ 34 ].cint - 
    fonttables [mainf ][ 5 ].cint + curl ].qqqq ;
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
    if ( ! ( leftghost || rightghost ) ) 
    {
      mem [curlist .tailfield ].hh .v.RH = ligstack ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    lab100: getnext () ;
    if ( curcmd == 11 ) 
    goto lab101 ;
    if ( curcmd == 12 ) 
    goto lab101 ;
    if ( curcmd == 70 ) 
    goto lab101 ;
    xtoken () ;
    if ( curcmd == 11 ) 
    goto lab101 ;
    if ( curcmd == 12 ) 
    goto lab101 ;
    if ( curcmd == 70 ) 
    goto lab101 ;
    if ( curcmd == 16 ) 
    {
      scancharnum () ;
      curchr = curval ;
      goto lab101 ;
    } 
    if ( curcmd == 68 ) 
    {
      t = curchr ;
      getxtoken () ;
      if ( ( curcmd == 11 ) || ( curcmd == 12 ) || ( curcmd == 70 ) || ( 
      curcmd == 16 ) ) 
      {
	if ( t == 0 ) 
	newleftghost = true ;
	else newrightghost = true ;
	backinput () ;
	goto lab100 ;
      } 
    } 
    if ( curcmd == 65 ) 
    bchar = 65536L ;
    curr = bchar ;
    ligstack = 0 ;
    goto lab110 ;
    lab101: mains = newequiv ( 918336L + curchr ) ;
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
    {
      ligstack = avail ;
      if ( ligstack == 0 ) 
      ligstack = getavail () ;
      else {
	  
	avail = mem [ligstack ].hh .v.RH ;
	mem [ligstack ].hh .v.RH = 0 ;
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
    curr = 65536L ;
    lab110: if ( newrightghost || leftghost ) 
    goto lab80 ;
    if ( ( ( maini .b2 ) % 4 ) != 1 ) 
    goto lab80 ;
    maink = fonttables [mainf ][ 40 ].cint + maini .b3 ;
    mainj = fonttables [mainf ][ maink ].qqqq ;
    if ( ( mainj .b0 % 256 ) <= 128 ) 
    goto lab112 ;
    maink = fonttables [mainf ][ 40 ].cint + 256 * mainj .b2 + mainj .b3 + 
    32768L - 256 * ( 128 ) ;
    lab111: mainj = fonttables [mainf ][ maink ].qqqq ;
    lab112: if ( ( mainj .b0 / 256 ) == 0 ) 
    {
      if ( fonttables [mainf ][ 5 ].cint + mainj .b1 == curr ) {
	  
	if ( ( mainj .b0 % 256 ) <= 128 ) 
	{
	  if ( mainj .b2 >= 128 ) 
	  {
	    if ( curl < 65536L ) 
	    {
	      if ( mem [curq ].hh .v.RH > 0 ) {
		  
		if ( mem [curlist .tailfield ].hh.b1 == fonttables [mainf 
		][ 16 ].cint ) 
		insdisc = true ;
	      } 
	      if ( ligaturepresent ) 
	      {
		mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH ) 
		;
		if ( lfthit ) 
		{
		  mem [mainp ].hh.b1 = 2 ;
		  lfthit = false ;
		} 
		if ( rthit ) {
		    
		  if ( ligstack == 0 ) 
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
	      mem [curlist .tailfield ].hh .v.RH = newkern ( fonttables [
	      mainf ][ fonttables [mainf ][ 41 ].cint + 256 * mainj .b2 + 
	      mainj .b3 ].cint ) ;
	      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
	    } 
	    if ( newleftghost || rightghost ) 
	    {
	      mem [curlist .tailfield ].hh.b1 = 1 ;
	    } 
	    goto lab90 ;
	  } 
	  if ( newleftghost || rightghost ) 
	  goto lab80 ;
	  if ( curl == 65536L ) 
	  lfthit = true ;
	  else if ( ligstack == 0 ) 
	  rthit = true ;
	  {
	    if ( interrupt != 0 ) 
	    pauseforinstructions () ;
	  } 
	  switch ( mainj .b2 ) 
	  {case 1 : 
	  case 5 : 
	    {
	      curl = fonttables [mainf ][ 5 ].cint + mainj .b3 ;
	      maini = fonttables [mainf ][ fonttables [mainf ][ 34 ].cint - 
	      fonttables [mainf ][ 5 ].cint + curl ].qqqq ;
	      ligaturepresent = true ;
	    } 
	    break ;
	  case 2 : 
	  case 6 : 
	    {
	      curr = fonttables [mainf ][ 5 ].cint + mainj .b3 ;
	      if ( ligstack == 0 ) 
	      {
		ligstack = newligitem ( curr ) ;
		bchar = 65536L ;
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
	      curr = fonttables [mainf ][ 5 ].cint + mainj .b3 ;
	      mainp = ligstack ;
	      ligstack = newligitem ( curr ) ;
	      mem [ligstack ].hh .v.RH = mainp ;
	    } 
	    break ;
	  case 7 : 
	  case 11 : 
	    {
	      if ( curl < 65536L ) 
	      {
		if ( mem [curq ].hh .v.RH > 0 ) {
		    
		  if ( mem [curlist .tailfield ].hh.b1 == fonttables [mainf 
		  ][ 16 ].cint ) 
		  insdisc = true ;
		} 
		if ( ligaturepresent ) 
		{
		  mainp = newligature ( mainf , curl , mem [curq ].hh .v.RH 
		  ) ;
		  if ( lfthit ) 
		  {
		    mem [mainp ].hh.b1 = 2 ;
		    lfthit = false ;
		  } 
		  if ( false ) {
		      
		    if ( ligstack == 0 ) 
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
		    curlist .tailfield = mem [curlist .tailfield ].hh .v.RH 
		    ;
		  } 
		} 
	      } 
	      curq = curlist .tailfield ;
	      curl = fonttables [mainf ][ 5 ].cint + mainj .b3 ;
	      maini = fonttables [mainf ][ fonttables [mainf ][ 34 ].cint - 
	      fonttables [mainf ][ 5 ].cint + curl ].qqqq ;
	      ligaturepresent = true ;
	    } 
	    break ;
	    default: 
	    {
	      curl = fonttables [mainf ][ 5 ].cint + mainj .b3 ;
	      ligaturepresent = true ;
	      if ( ligstack == 0 ) 
	      goto lab80 ;
	      else goto lab91 ;
	    } 
	    break ;
	  } 
	  if ( mainj .b2 > 4 ) {
	      
	    if ( mainj .b2 != 7 ) 
	    goto lab80 ;
	  } 
	  if ( curl < 65536L ) 
	  goto lab110 ;
	  maink = fonttables [mainf ][ 18 ].cint ;
	  goto lab111 ;
	} 
      } 
    } 
    else {
	
      if ( ( fonttables [mainf ][ 12 ].cint <= curr ) ) {
	  
	if ( ( fonttables [mainf ][ 13 ].cint >= curr ) ) {
	    
	  if ( ( ( fonttables [mainf ][ fonttables [mainf ][ 34 ].cint - 
	  fonttables [mainf ][ 5 ].cint + curr ].qqqq .b0 > 0 ) ) ) {
	      
	    if ( curr != bchar ) {
		
	      if ( fonttables [mainf ][ 5 ].cint + mainj .b1 == fonttables [
	      mainf ][ fonttables [mainf ][ fonttables [mainf ][ 35 ].cint 
	      + curr ].cint ].cint ) 
	      {
		if ( newleftghost || rightghost ) 
		goto lab80 ;
		switch ( mainj .b2 ) 
		{case 20 : 
		  {
		    if ( curl < 65536L ) 
		    {
		      if ( mem [curq ].hh .v.RH > 0 ) {
			  
			if ( mem [curlist .tailfield ].hh.b1 == fonttables [
			mainf ][ 16 ].cint ) 
			insdisc = true ;
		      } 
		      if ( ligaturepresent ) 
		      {
			mainp = newligature ( mainf , curl , mem [curq ].hh 
			.v.RH ) ;
			if ( lfthit ) 
			{
			  mem [mainp ].hh.b1 = 2 ;
			  lfthit = false ;
			} 
			if ( rthit ) {
			    
			  if ( ligstack == 0 ) 
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
			  curlist .tailfield = mem [curlist .tailfield ].hh 
			  .v.RH ;
			} 
		      } 
		    } 
		    {
		      mem [curlist .tailfield ].hh .v.RH = newkern ( 
		      fonttables [mainf ][ fonttables [mainf ][ 30 ].cint + 
		      mainj .b3 ].cint ) ;
		      curlist .tailfield = mem [curlist .tailfield ].hh 
		      .v.RH ;
		    } 
		  } 
		  break ;
		case 18 : 
		  {
		    if ( curl < 65536L ) 
		    {
		      if ( mem [curq ].hh .v.RH > 0 ) {
			  
			if ( mem [curlist .tailfield ].hh.b1 == fonttables [
			mainf ][ 16 ].cint ) 
			insdisc = true ;
		      } 
		      if ( ligaturepresent ) 
		      {
			mainp = newligature ( mainf , curl , mem [curq ].hh 
			.v.RH ) ;
			if ( lfthit ) 
			{
			  mem [mainp ].hh.b1 = 2 ;
			  lfthit = false ;
			} 
			if ( rthit ) {
			    
			  if ( ligstack == 0 ) 
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
			  curlist .tailfield = mem [curlist .tailfield ].hh 
			  .v.RH ;
			} 
		      } 
		    } 
		    kglue = fonttables [mainf ][ 32 ].cint + ( mainj .b3 * 4 
		    ) ;
		    fontgluespec = newspec ( membot ) ;
		    mem [fontgluespec + 1 ].cint = fonttables [mainf ][ 
		    kglue + 1 ].cint ;
		    mem [fontgluespec + 2 ].cint = fonttables [mainf ][ 
		    kglue + 2 ].cint ;
		    mem [fontgluespec + 3 ].cint = fonttables [mainf ][ 
		    kglue + 3 ].cint ;
		    {
		      mem [curlist .tailfield ].hh .v.RH = newglue ( 
		      fontgluespec ) ;
		      curlist .tailfield = mem [curlist .tailfield ].hh 
		      .v.RH ;
		    } 
		  } 
		  break ;
		case 19 : 
		  {
		    if ( curl < 65536L ) 
		    {
		      if ( mem [curq ].hh .v.RH > 0 ) {
			  
			if ( mem [curlist .tailfield ].hh.b1 == fonttables [
			mainf ][ 16 ].cint ) 
			insdisc = true ;
		      } 
		      if ( ligaturepresent ) 
		      {
			mainp = newligature ( mainf , curl , mem [curq ].hh 
			.v.RH ) ;
			if ( lfthit ) 
			{
			  mem [mainp ].hh.b1 = 2 ;
			  lfthit = false ;
			} 
			if ( rthit ) {
			    
			  if ( ligstack == 0 ) 
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
			  curlist .tailfield = mem [curlist .tailfield ].hh 
			  .v.RH ;
			} 
		      } 
		    } 
		    {
		      mem [curlist .tailfield ].hh .v.RH = newpenalty ( 
		      fonttables [mainf ][ fonttables [mainf ][ 33 ].cint + 
		      ( mainj .b3 / 256 ) ].cint ) ;
		      curlist .tailfield = mem [curlist .tailfield ].hh 
		      .v.RH ;
		    } 
		    kglue = fonttables [mainf ][ 32 ].cint + ( ( mainj .b3 % 
		    256 ) * 4 ) ;
		    fontgluespec = newspec ( membot ) ;
		    mem [fontgluespec + 1 ].cint = fonttables [mainf ][ 
		    kglue + 1 ].cint ;
		    mem [fontgluespec + 2 ].cint = fonttables [mainf ][ 
		    kglue + 2 ].cint ;
		    mem [fontgluespec + 3 ].cint = fonttables [mainf ][ 
		    kglue + 3 ].cint ;
		    {
		      mem [curlist .tailfield ].hh .v.RH = newglue ( 
		      fontgluespec ) ;
		      curlist .tailfield = mem [curlist .tailfield ].hh 
		      .v.RH ;
		    } 
		  } 
		  break ;
		case 17 : 
		  {
		    if ( curl < 65536L ) 
		    {
		      if ( mem [curq ].hh .v.RH > 0 ) {
			  
			if ( mem [curlist .tailfield ].hh.b1 == fonttables [
			mainf ][ 16 ].cint ) 
			insdisc = true ;
		      } 
		      if ( ligaturepresent ) 
		      {
			mainp = newligature ( mainf , curl , mem [curq ].hh 
			.v.RH ) ;
			if ( lfthit ) 
			{
			  mem [mainp ].hh.b1 = 2 ;
			  lfthit = false ;
			} 
			if ( rthit ) {
			    
			  if ( ligstack == 0 ) 
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
			  curlist .tailfield = mem [curlist .tailfield ].hh 
			  .v.RH ;
			} 
		      } 
		    } 
		    {
		      mem [curlist .tailfield ].hh .v.RH = newpenalty ( 
		      fonttables [mainf ][ fonttables [mainf ][ 33 ].cint + 
		      mainj .b3 ].cint ) ;
		      curlist .tailfield = mem [curlist .tailfield ].hh 
		      .v.RH ;
		    } 
		  } 
		  break ;
		} 
		goto lab90 ;
	      } 
	    } 
	  } 
	} 
      } 
    } 
    if ( ( mainj .b0 % 256 ) == 0 ) 
    incr ( maink ) ;
    else {
	
      if ( ( mainj .b0 % 256 ) >= 128 ) 
      goto lab80 ;
      maink = maink + ( mainj .b0 % 256 ) + 1 ;
    } 
    goto lab111 ;
    lab95: mainp = mem [ligstack + 1 ].hh .v.RH ;
    if ( mainp > 0 ) 
    {
      mem [curlist .tailfield ].hh .v.RH = mainp ;
      curlist .tailfield = mem [curlist .tailfield ].hh .v.RH ;
    } 
    tempptr = ligstack ;
    ligstack = mem [tempptr ].hh .v.RH ;
    freenode ( tempptr , 2 ) ;
    maini = fonttables [mainf ][ fonttables [mainf ][ 34 ].cint - 
    fonttables [mainf ][ 5 ].cint + curl ].qqqq ;
    ligaturepresent = true ;
    if ( ligstack == 0 ) {
	
      if ( mainp > 0 ) 
      goto lab100 ;
      else curr = bchar ;
    } 
    else curr = mem [ligstack ].hh.b1 ;
    goto lab110 ;
  } 
  else {
      
    {
      if ( ( curcmd == 70 ) || ( curcmd == 16 ) ) 
      {
	backinput () ;
	curinput .ocplstackfield = activeinfo [activereal + 1 ].cint ;
	curinput .ocpnofield = activeinfo [activereal ].hh.b1 ;
      } 
      else {
	  
	{
	  otpinitinputend = 0 ;
	  while ( ( curcmd == 11 ) || ( curcmd == 12 ) || ( curcmd == 10 ) ) {
	      
	    incr ( otpinitinputend ) ;
	    if ( otpinitinputend > ocpbufsize ) 
	    overflowocpbufsize () ;
	    otpinitinputbuf [otpinitinputend ]= curchr ;
	    getxtoken () ;
	    if ( ( curcmd == 16 ) ) 
	    {
	      scancharnum () ;
	      curchr = curval ;
	    } 
	  } 
	  backinput () ;
	  otpinputend = otpinitinputend ;
	  {register integer for_end; otpi = 0 ;for_end = otpinitinputend 
	  ; if ( otpi <= for_end) do 
	    {
	      otpinputbuf [otpi ]= otpinitinputbuf [otpi ];
	    } 
	  while ( otpi++ < for_end ) ;} 
	} 
	{
	  otpinputocp = activeinfo [activereal ].hh.b0 ;
	  if ( otpinputocp == 0 ) 
	  {
	    printnl ( 66819L ) ;
	    otpoutputend = 0 ;
	  } 
	  else if ( ocptables [otpinputocp ][ 3 ]== 0 ) 
	  {
	    otpinputstart = 0 ;
	    otpinputlast = 0 ;
	    otpstackused = 0 ;
	    otpstacklast = 0 ;
	    otpstacknew = 0 ;
	    otpoutputend = 0 ;
	    otppc = 0 ;
	    otpfinished = false ;
	    otpcalcptr = 0 ;
	    otpcalcs [otpcalcptr ]= 0 ;
	    otpstateptr = 0 ;
	    otpstates [otpstateptr ]= 0 ;
	    while ( ! otpfinished ) {
		
	      {
		if ( otppc >= ocptables [otpinputocp ][ ocptables [
		otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]) 
		{
		  {
		    if ( interaction == 3 ) 
		    ;
		    if ( filelineerrorstylep ) 
		    printfileline () ;
		    else printnl ( 65548L ) ;
		    print ( 66821L ) ;
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
		otpinstruction = ocptables [otpinputocp ][ ocptables [
		otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates [
		otpstateptr ]* 2 ]+ otppc ];
		otpinstr = otpinstruction / 16777216L ;
		otparg = otpinstruction % 16777216L ;
	      } 
	      switch ( otpinstr ) 
	      {case 1 : 
		{
		  incr ( otpoutputend ) ;
		  if ( otpoutputend > ocpbufsize ) 
		  overflowocpbufsize () ;
		  otpoutputbuf [otpoutputend ]= otpcalcs [otpcalcptr ];
		  decr ( otpcalcptr ) ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 2 : 
		{
		  incr ( otpoutputend ) ;
		  if ( otpoutputend > ocpbufsize ) 
		  overflowocpbufsize () ;
		  otpoutputbuf [otpoutputend ]= otparg ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 3 : 
		{
		  {
		    if ( ( 1 > otparg ) || ( otparg > otpnoinputchars ) ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66823L ) ;
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
		    if ( otparg > otpstacklast ) 
		    {
		      otpcalculatedchar = otpinputbuf [otpinputstart + otparg 
		      - otpstacklast ];
		    } 
		    else {
			
		      otpcalculatedchar = otpstackbuf [otparg ];
		    } 
		  } 
		  incr ( otpoutputend ) ;
		  if ( otpoutputend > ocpbufsize ) 
		  overflowocpbufsize () ;
		  otpoutputbuf [otpoutputend ]= otpcalculatedchar ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 4 : 
		{
		  {
		    if ( ( 1 > otpnoinputchars - otparg ) || ( otpnoinputchars 
		    - otparg > otpnoinputchars ) ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66823L ) ;
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
		    if ( otpnoinputchars - otparg > otpstacklast ) 
		    {
		      otpcalculatedchar = otpinputbuf [otpinputstart + 
		      otpnoinputchars - otparg - otpstacklast ];
		    } 
		    else {
			
		      otpcalculatedchar = otpstackbuf [otpnoinputchars - 
		      otparg ];
		    } 
		  } 
		  incr ( otpoutputend ) ;
		  if ( otpoutputend > ocpbufsize ) 
		  overflowocpbufsize () ;
		  otpoutputbuf [otpoutputend ]= otpcalculatedchar ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 5 : 
		{
		  otpfirstarg = otparg + 1 ;
		  incr ( otppc ) ;
		  {
		    if ( otppc >= ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]
		    ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66821L ) ;
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
		    otpinstruction = ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates 
		    [otpstateptr ]* 2 ]+ otppc ];
		    otpinstr = otpinstruction / 16777216L ;
		    otparg = otpinstruction % 16777216L ;
		  } 
		  otpsecondarg = otpnoinputchars - otparg ;
		  {register integer for_end; otpcounter = otpfirstarg ;
		  for_end = otpsecondarg ; if ( otpcounter <= for_end) do 
		    {
		      {
			if ( ( 1 > otpcounter ) || ( otpcounter > 
			otpnoinputchars ) ) 
			{
			  {
			    if ( interaction == 3 ) 
			    ;
			    if ( filelineerrorstylep ) 
			    printfileline () ;
			    else printnl ( 65548L ) ;
			    print ( 66823L ) ;
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
			if ( otpcounter > otpstacklast ) 
			{
			  otpcalculatedchar = otpinputbuf [otpinputstart + 
			  otpcounter - otpstacklast ];
			} 
			else {
			    
			  otpcalculatedchar = otpstackbuf [otpcounter ];
			} 
		      } 
		      incr ( otpoutputend ) ;
		      if ( otpoutputend > ocpbufsize ) 
		      overflowocpbufsize () ;
		      otpoutputbuf [otpoutputend ]= otpcalculatedchar ;
		    } 
		  while ( otpcounter++ < for_end ) ;} 
		  incr ( otppc ) ;
		} 
		break ;
	      case 6 : 
		{
		  incr ( otpstacknew ) ;
		  if ( otpstacknew >= ocpstacksize ) 
		  overflowocpstacksize () ;
		  otpstackbuf [otpstacknew ]= otpcalcs [otpcalcptr ];
		  decr ( otpcalcptr ) ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 7 : 
		{
		  incr ( otpstacknew ) ;
		  if ( otpstacknew >= ocpstacksize ) 
		  overflowocpstacksize () ;
		  otpstackbuf [otpstacknew ]= otparg ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 8 : 
		{
		  {
		    if ( ( 1 > otparg ) || ( otparg > otpnoinputchars ) ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66823L ) ;
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
		    if ( otparg > otpstacklast ) 
		    {
		      otpcalculatedchar = otpinputbuf [otpinputstart + otparg 
		      - otpstacklast ];
		    } 
		    else {
			
		      otpcalculatedchar = otpstackbuf [otparg ];
		    } 
		  } 
		  incr ( otpstacknew ) ;
		  if ( otpstacknew >= ocpstacksize ) 
		  overflowocpstacksize () ;
		  otpstackbuf [otpstacknew ]= otpcalculatedchar ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 9 : 
		{
		  {
		    if ( ( 1 > otpnoinputchars - otparg ) || ( otpnoinputchars 
		    - otparg > otpnoinputchars ) ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66823L ) ;
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
		    if ( otpnoinputchars - otparg > otpstacklast ) 
		    {
		      otpcalculatedchar = otpinputbuf [otpinputstart + 
		      otpnoinputchars - otparg - otpstacklast ];
		    } 
		    else {
			
		      otpcalculatedchar = otpstackbuf [otpnoinputchars - 
		      otparg ];
		    } 
		  } 
		  incr ( otpstacknew ) ;
		  if ( otpstacknew >= ocpstacksize ) 
		  overflowocpstacksize () ;
		  otpstackbuf [otpstacknew ]= otpcalculatedchar ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 10 : 
		{
		  otpfirstarg = otparg + 1 ;
		  incr ( otppc ) ;
		  {
		    if ( otppc >= ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]
		    ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66821L ) ;
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
		    otpinstruction = ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates 
		    [otpstateptr ]* 2 ]+ otppc ];
		    otpinstr = otpinstruction / 16777216L ;
		    otparg = otpinstruction % 16777216L ;
		  } 
		  otpsecondarg = otpnoinputchars - otparg ;
		  {register integer for_end; otpcounter = otpfirstarg ;
		  for_end = otpsecondarg ; if ( otpcounter <= for_end) do 
		    {
		      {
			if ( ( 1 > otpcounter ) || ( otpcounter > 
			otpnoinputchars ) ) 
			{
			  {
			    if ( interaction == 3 ) 
			    ;
			    if ( filelineerrorstylep ) 
			    printfileline () ;
			    else printnl ( 65548L ) ;
			    print ( 66823L ) ;
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
			if ( otpcounter > otpstacklast ) 
			{
			  otpcalculatedchar = otpinputbuf [otpinputstart + 
			  otpcounter - otpstacklast ];
			} 
			else {
			    
			  otpcalculatedchar = otpstackbuf [otpcounter ];
			} 
		      } 
		      incr ( otpstacknew ) ;
		      if ( otpstacknew >= ocpstacksize ) 
		      overflowocpstacksize () ;
		      otpstackbuf [otpstacknew ]= otpcalculatedchar ;
		    } 
		  while ( otpcounter++ < for_end ) ;} 
		  incr ( otppc ) ;
		} 
		break ;
	      case 11 : 
		{
		  otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]+ 
		  otpcalcs [otpcalcptr ];
		  incr ( otppc ) ;
		  decr ( otpcalcptr ) ;
		} 
		break ;
	      case 12 : 
		{
		  otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]- 
		  otpcalcs [otpcalcptr ];
		  incr ( otppc ) ;
		  decr ( otpcalcptr ) ;
		} 
		break ;
	      case 13 : 
		{
		  otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]* 
		  otpcalcs [otpcalcptr ];
		  incr ( otppc ) ;
		  decr ( otpcalcptr ) ;
		} 
		break ;
	      case 14 : 
		{
		  otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]/ 
		  otpcalcs [otpcalcptr ];
		  incr ( otppc ) ;
		  decr ( otpcalcptr ) ;
		} 
		break ;
	      case 15 : 
		{
		  otpcalcs [otpcalcptr - 1 ]= otpcalcs [otpcalcptr - 1 ]% 
		  otpcalcs [otpcalcptr ];
		  incr ( otppc ) ;
		  decr ( otpcalcptr ) ;
		} 
		break ;
	      case 16 : 
		{
		  if ( otpcalcs [otpcalcptr ]>= ocptables [otpinputocp ][ 
		  ocptables [otpinputocp ][ 9 ]+ otpcalcs [otpcalcptr - 1 ]
		  * 2 + 1 ]) 
		  {
		    {
		      if ( interaction == 3 ) 
		      ;
		      if ( filelineerrorstylep ) 
		      printfileline () ;
		      else printnl ( 65548L ) ;
		      print ( 66824L ) ;
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
		  otpcalcs [otpcalcptr - 1 ]= ocptables [otpinputocp ][ 
		  ocptables [otpinputocp ][ ocptables [otpinputocp ][ 9 ]+ 
		  otpcalcs [otpcalcptr - 1 ]* 2 ]+ otpcalcs [otpcalcptr ]
		  ];
		  incr ( otppc ) ;
		  decr ( otpcalcptr ) ;
		} 
		break ;
	      case 17 : 
		{
		  incr ( otpcalcptr ) ;
		  if ( otpcalcptr >= ocpstacksize ) 
		  overflowocpstacksize () ;
		  otpcalcs [otpcalcptr ]= otparg ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 18 : 
		{
		  {
		    if ( ( 1 > otparg ) || ( otparg > otpnoinputchars ) ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66823L ) ;
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
		    if ( otparg > otpstacklast ) 
		    {
		      otpcalculatedchar = otpinputbuf [otpinputstart + otparg 
		      - otpstacklast ];
		    } 
		    else {
			
		      otpcalculatedchar = otpstackbuf [otparg ];
		    } 
		  } 
		  incr ( otpcalcptr ) ;
		  if ( otpcalcptr >= ocpstacksize ) 
		  overflowocpstacksize () ;
		  otpcalcs [otpcalcptr ]= otpcalculatedchar ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 19 : 
		{
		  {
		    if ( ( 1 > otpnoinputchars - otparg ) || ( otpnoinputchars 
		    - otparg > otpnoinputchars ) ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66823L ) ;
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
		    if ( otpnoinputchars - otparg > otpstacklast ) 
		    {
		      otpcalculatedchar = otpinputbuf [otpinputstart + 
		      otpnoinputchars - otparg - otpstacklast ];
		    } 
		    else {
			
		      otpcalculatedchar = otpstackbuf [otpnoinputchars - 
		      otparg ];
		    } 
		  } 
		  incr ( otpcalcptr ) ;
		  if ( otpcalcptr >= ocpstacksize ) 
		  overflowocpstacksize () ;
		  otpcalcs [otpcalcptr ]= otpcalculatedchar ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 20 : 
		{
		  otpinputstart = otpinputlast ;
		  {register integer for_end; otpcounter = 1 ;for_end = ( 
		  otpstacknew - otpstackused ) ; if ( otpcounter <= for_end) 
		  do 
		    {
		      otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
		      otpstackused ];
		    } 
		  while ( otpcounter++ < for_end ) ;} 
		  otpstacknew = otpstacknew - otpstackused ;
		  otpstacklast = otpstacknew ;
		  otpstackused = 0 ;
		  otpstates [otpstateptr ]= otparg ;
		  otppc = 0 ;
		} 
		break ;
	      case 21 : 
		{
		  otpinputstart = otpinputlast ;
		  {register integer for_end; otpcounter = 1 ;for_end = ( 
		  otpstacknew - otpstackused ) ; if ( otpcounter <= for_end) 
		  do 
		    {
		      otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
		      otpstackused ];
		    } 
		  while ( otpcounter++ < for_end ) ;} 
		  otpstacknew = otpstacknew - otpstackused ;
		  otpstacklast = otpstacknew ;
		  otpstackused = 0 ;
		  incr ( otpstateptr ) ;
		  if ( otpstateptr >= ocpstacksize ) 
		  overflowocpstacksize () ;
		  otpstates [otpstateptr ]= otparg ;
		  otppc = 0 ;
		} 
		break ;
	      case 22 : 
		{
		  otpinputstart = otpinputlast ;
		  {register integer for_end; otpcounter = 1 ;for_end = ( 
		  otpstacknew - otpstackused ) ; if ( otpcounter <= for_end) 
		  do 
		    {
		      otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
		      otpstackused ];
		    } 
		  while ( otpcounter++ < for_end ) ;} 
		  otpstacknew = otpstacknew - otpstackused ;
		  otpstacklast = otpstacknew ;
		  otpstackused = 0 ;
		  if ( otpstateptr > 0 ) 
		  decr ( otpstateptr ) ;
		  otppc = 0 ;
		} 
		break ;
	      case 23 : 
		{
		  otpinputstart = otpinputlast ;
		  otpinputlast = otpinputstart ;
		  otpstackused = 0 ;
		  if ( ( otpstacklast == 0 ) && ( otpinputlast >= otpinputend 
		  ) ) 
		  otpfinished = true ;
		  else if ( ( otpstackused < otpstacklast ) ) 
		  {
		    incr ( otpstackused ) ;
		    otpinputchar = otpstackbuf [otpstackused ];
		    otpnoinputchars = 1 ;
		    incr ( otppc ) ;
		  } 
		  else {
		      
		    incr ( otpinputlast ) ;
		    otpinputchar = otpinputbuf [otpinputlast ];
		    otpnoinputchars = 1 ;
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 24 : 
		{
		  otpinputlast = otpinputstart ;
		  otpstackused = 0 ;
		  if ( ( otpstackused < otpstacklast ) ) 
		  {
		    incr ( otpstackused ) ;
		    otpinputchar = otpstackbuf [otpstackused ];
		    otpnoinputchars = 1 ;
		    incr ( otppc ) ;
		  } 
		  else {
		      
		    incr ( otpinputlast ) ;
		    otpinputchar = otpinputbuf [otpinputlast ];
		    otpnoinputchars = 1 ;
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 25 : 
		{
		  if ( otpinputstart < otpinputlast ) 
		  {
		    decr ( otpinputlast ) ;
		    otpinputchar = otpinputbuf [otpinputlast ];
		  } 
		  else {
		      
		    decr ( otpstackused ) ;
		    otpinputchar = otpstackbuf [otpstackused ];
		  } 
		  decr ( otpnoinputchars ) ;
		  incr ( otppc ) ;
		} 
		break ;
	      case 26 : 
		{
		  otppc = otparg ;
		} 
		break ;
	      case 27 : 
		{
		  otpfirstarg = otparg ;
		  incr ( otppc ) ;
		  {
		    if ( otppc >= ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]
		    ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66821L ) ;
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
		    otpinstruction = ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates 
		    [otpstateptr ]* 2 ]+ otppc ];
		    otpinstr = otpinstruction / 16777216L ;
		    otparg = otpinstruction % 16777216L ;
		  } 
		  if ( otpinputchar != otpfirstarg ) 
		  {
		    otppc = otparg ;
		  } 
		  else {
		      
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 28 : 
		{
		  otpfirstarg = otparg ;
		  incr ( otppc ) ;
		  {
		    if ( otppc >= ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]
		    ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66821L ) ;
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
		    otpinstruction = ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates 
		    [otpstateptr ]* 2 ]+ otppc ];
		    otpinstr = otpinstruction / 16777216L ;
		    otparg = otpinstruction % 16777216L ;
		  } 
		  if ( otpinputchar == otpfirstarg ) 
		  {
		    otppc = otparg ;
		  } 
		  else {
		      
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 29 : 
		{
		  otpfirstarg = otparg ;
		  incr ( otppc ) ;
		  {
		    if ( otppc >= ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]
		    ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66821L ) ;
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
		    otpinstruction = ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates 
		    [otpstateptr ]* 2 ]+ otppc ];
		    otpinstr = otpinstruction / 16777216L ;
		    otparg = otpinstruction % 16777216L ;
		  } 
		  if ( otpinputchar < otpfirstarg ) 
		  {
		    otppc = otparg ;
		  } 
		  else {
		      
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 30 : 
		{
		  otpfirstarg = otparg ;
		  incr ( otppc ) ;
		  {
		    if ( otppc >= ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]
		    ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66821L ) ;
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
		    otpinstruction = ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates 
		    [otpstateptr ]* 2 ]+ otppc ];
		    otpinstr = otpinstruction / 16777216L ;
		    otparg = otpinstruction % 16777216L ;
		  } 
		  if ( otpinputchar <= otpfirstarg ) 
		  {
		    otppc = otparg ;
		  } 
		  else {
		      
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 31 : 
		{
		  otpfirstarg = otparg ;
		  incr ( otppc ) ;
		  {
		    if ( otppc >= ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]
		    ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66821L ) ;
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
		    otpinstruction = ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates 
		    [otpstateptr ]* 2 ]+ otppc ];
		    otpinstr = otpinstruction / 16777216L ;
		    otparg = otpinstruction % 16777216L ;
		  } 
		  if ( otpinputchar > otpfirstarg ) 
		  {
		    otppc = otparg ;
		  } 
		  else {
		      
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 32 : 
		{
		  otpfirstarg = otparg ;
		  incr ( otppc ) ;
		  {
		    if ( otppc >= ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ 10 ]+ otpstates [otpstateptr ]* 2 + 1 ]
		    ) 
		    {
		      {
			if ( interaction == 3 ) 
			;
			if ( filelineerrorstylep ) 
			printfileline () ;
			else printnl ( 65548L ) ;
			print ( 66821L ) ;
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
		    otpinstruction = ocptables [otpinputocp ][ ocptables [
		    otpinputocp ][ ocptables [otpinputocp ][ 10 ]+ otpstates 
		    [otpstateptr ]* 2 ]+ otppc ];
		    otpinstr = otpinstruction / 16777216L ;
		    otparg = otpinstruction % 16777216L ;
		  } 
		  if ( otpinputchar >= otpfirstarg ) 
		  {
		    otppc = otparg ;
		  } 
		  else {
		      
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 33 : 
		{
		  if ( ( otpstackused < otpstacklast ) ) 
		  {
		    incr ( otpstackused ) ;
		    otpinputchar = otpstackbuf [otpstackused ];
		    incr ( otpnoinputchars ) ;
		    incr ( otppc ) ;
		  } 
		  else if ( otpinputlast >= otpinputend ) 
		  {
		    otppc = otparg ;
		  } 
		  else {
		      
		    incr ( otpinputlast ) ;
		    otpinputchar = otpinputbuf [otpinputlast ];
		    incr ( otpnoinputchars ) ;
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 34 : 
		{
		  if ( otpinputlast == 0 ) 
		  {
		    otppc = otparg ;
		  } 
		  else {
		      
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 35 : 
		{
		  if ( otpinputlast >= otpinputend ) 
		  {
		    otppc = otparg ;
		  } 
		  else {
		      
		    incr ( otppc ) ;
		  } 
		} 
		break ;
	      case 36 : 
		{
		  otpinputstart = otpinputlast ;
		  {register integer for_end; otpcounter = 1 ;for_end = ( 
		  otpstacknew - otpstackused ) ; if ( otpcounter <= for_end) 
		  do 
		    {
		      otpstackbuf [otpcounter ]= otpstackbuf [otpcounter + 
		      otpstackused ];
		    } 
		  while ( otpcounter++ < for_end ) ;} 
		  otpstacknew = otpstacknew - otpstackused ;
		  otpstacklast = otpstacknew ;
		  otpstackused = 0 ;
		  otppc = 0 ;
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
		    print ( 66822L ) ;
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
		break ;
	      } 
	    } 
	  } 
	  else {
	      
	    k = 0 ;
	    if ( nameoffile ) 
	    libcfree ( nameoffile ) ;
	    otpextstr = ocptables [otpinputocp ][ 3 ];
	    otpextstrarg = ocptables [otpinputocp ][ 4 ];
	    nameoffile = xmalloc ( 4 + length ( otpextstr ) + length ( 
	    otpextstrarg ) ) ;
	    {register integer for_end; otpexti = strstartar [otpextstr - 
	    65536L ];for_end = strstartar [otpextstr - 65536L ]+ length ( 
	    otpextstr ) - 1 ; if ( otpexti <= for_end) do 
	      {
		c = strpool [otpexti ];
		if ( ! ( c == 34 ) ) 
		{
		  incr ( k ) ;
		  if ( k <= maxint ) 
		  nameoffile [k ]= xchr [c ];
		} 
	      } 
	    while ( otpexti++ < for_end ) ;} 
	    {
	      c = 32 ;
	      if ( ! ( c == 34 ) ) 
	      {
		incr ( k ) ;
		if ( k <= maxint ) 
		nameoffile [k ]= xchr [c ];
	      } 
	    } 
	    {register integer for_end; otpexti = strstartar [otpextstrarg - 
	    65536L ];for_end = strstartar [otpextstrarg - 65536L ]+ length 
	    ( otpextstrarg ) - 1 ; if ( otpexti <= for_end) do 
	      {
		c = strpool [otpexti ];
		if ( ! ( c == 34 ) ) 
		{
		  incr ( k ) ;
		  if ( k <= maxint ) 
		  nameoffile [k ]= xchr [c ];
		} 
	      } 
	    while ( otpexti++ < for_end ) ;} 
	    nameoffile [length ( otpextstr ) + length ( otpextstrarg ) + 2 ]
	    = 0 ;
	    runexternalocp ( nameoffile ) ;
	  } 
	} 
	if ( otpoutputend > 0 ) 
	{
	  if ( ( first + otpoutputend ) >= bufsize ) 
	  {
	    overflow ( 66820L , bufsize ) ;
	  } 
	  {
	    if ( inputptr > maxinstack ) 
	    {
	      maxinstack = inputptr ;
	      if ( inputptr == stacksize ) 
	      overflow ( 65902L , stacksize ) ;
	    } 
	    inputstack [inputptr ]= curinput ;
	    incr ( inputptr ) ;
	  } 
	  curinput .ocplstackfield = activeinfo [activereal + 1 ].cint ;
	  curinput .ocpnofield = activeinfo [activereal ].hh.b1 ;
	  curinput .statefield = 1 ;
	  last = first ;
	  curinput .startfield = first ;
	  curinput .locfield = first ;
	  {register integer for_end; otpcounter = 1 ;for_end = otpoutputend 
	  ; if ( otpcounter <= for_end) do 
	    {
	      buffer [last ]= otpoutputbuf [otpcounter ];
	      incr ( last ) ;
	    } 
	  while ( otpcounter++ < for_end ) ;} 
	  curinput .limitfield = last - 1 ;
	  first = last ;
	} 
      } 
      goto lab60 ;
    } 
  } 
  lab120: if ( newequiv ( 393242L ) == membot ) 
  {
    {
      mainp = fonttables [newequiv ( 720959L ) ][ 14 ].cint ;
      if ( mainp == 0 ) 
      {
	mainp = newspec ( membot ) ;
	maink = fonttables [newequiv ( 720959L ) ][ 43 ].cint + 2 ;
	mem [mainp + 1 ].cint = fonttables [newequiv ( 720959L ) ][ maink ]
	.cint ;
	mem [mainp + 2 ].cint = fonttables [newequiv ( 720959L ) ][ maink + 
	1 ].cint ;
	mem [mainp + 3 ].cint = fonttables [newequiv ( 720959L ) ][ maink + 
	2 ].cint ;
	fonttables [newequiv ( 720959L ) ][ 14 ].cint = mainp ;
      } 
    } 
    tempptr = newglue ( mainp ) ;
  } 
  else tempptr = newparamglue ( 12 ) ;
  mem [curlist .tailfield ].hh .v.RH = tempptr ;
  curlist .tailfield = tempptr ;
  goto lab60 ;
} 
void 
giveerrhelp ( void ) 
{
  giveerrhelp_regmem 
  tokenshow ( newequiv ( 524334L ) ) ;
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
    fputs ( nameoffile + 1 , stdout ) ;
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
  if ( neweqtbint ( 1049439L ) > 0 ) {
      
    if ( logopened ) 
    {
      { putc ( ' ' ,  logfile );  putc ( '\n',  logfile ); }
      fprintf ( logfile , "%s%s\n",  "Here is how much of Omega's memory" , " you used:"       ) ;
      fprintf ( logfile , "%c%ld%s",  ' ' , (long)strptr - initstrptr , " string" ) ;
      if ( strptr != initstrptr + 1 ) 
      putc ( 's' ,  logfile );
      fprintf ( logfile , "%s%ld\n",  " out of " , (long)maxstrings - initstrptr ) ;
      fprintf ( logfile , "%c%ld%s%ld\n",  ' ' , (long)poolptr - initpoolptr ,       " string characters out of " , (long)poolsize - initpoolptr ) ;
      fprintf ( logfile , "%c%ld%s%ld\n",  ' ' , (long)lomemmax - memmin + memend - himemmin + 2 ,       " words of memory out of " , (long)memend + 1 - memmin ) ;
      fprintf ( logfile , "%c%ld%s%ld\n",  ' ' , (long)cscount ,       " multiletter control sequences out of " , (long)65536L ) ;
      fprintf ( logfile , "%ld%s",  (long)fontptr - 0 , " font" ) ;
      if ( fontptr != 1 ) 
      putc ( 's' ,  logfile );
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
  printnl ( 66192L ) ;
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
    dvifour ( neweqtbint ( 1049425L ) ) ;
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
	
      if ( fonttables [fontptr ][ 15 ].cint ) 
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
    {
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
      fatalerror ( 66181L ) ;
    } 
    if ( dviptr > 0 ) 
    writedvi ( 0 , dviptr - 1 ) ;
    printnl ( 66193L ) ;
    printfilename ( 0 , outputfilename , 0 ) ;
    print ( 65570L ) ;
    printint ( totalpages ) ;
    print ( 66194L ) ;
    if ( totalpages != 1 ) 
    printchar ( 115 ) ;
    print ( 66175L ) ;
    printint ( dvioffset + dviptr ) ;
    print ( 66195L ) ;
    bclose ( dvifile ) ;
  } 
  if ( logopened ) 
  {
    putc ('\n',  logfile );
    aclose ( logfile ) ;
    selector = selector - 2 ;
    if ( selector == 17 ) 
    {
      printnl ( 66651L ) ;
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
    printnl ( 66660L ) ;
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
	printword ( neweqtb ( n ) ) ;
	break ;
      case 5 : 
	;
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
	showtokenlist ( n , 0 , 1000 ) ;
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
  Result = 65624L ;
  return Result ;
} 
