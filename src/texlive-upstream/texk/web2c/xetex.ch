@x
  \def\?##1]{\hbox to 1in{\hfil##1.\ }}
  }
@y
  \def\?##1]{\hbox{Changes to \hbox to 1em{\hfil##1}.\ }}
  }
\let\maybe=\iftrue
@z

@x
November 1984].
@y
November 1984].

ML\TeX{} will add new primitives changing the behaviour of \TeX.  The
|banner| string has to be changed.  We do not change the |banner|
string, but will output an additional line to make clear that this is
a modified \TeX{} version.

@z

@x
@d banner=='This is TeX, Version 3.14159265' {printed when \TeX\ starts}
@y
@d TeX_banner_k=='This is TeXk, Version 3.14159265' {printed when \TeX\ starts}
@d TeX_banner=='This is TeX, Version 3.14159265' {printed when \TeX\ starts}
@#
@d banner==XeTeX_banner
@d banner_k==XeTeX_banner
@z

@x
Actually the heading shown here is not quite normal: The |program| line
does not mention any |output| file, because \ph\ would ask the \TeX\ user
to specify a file name if |output| were specified here.
@:PASCAL H}{\ph@>
@^system dependencies@>
@y
@z

@x
program TEX; {all file names are defined dynamically}
label @<Labels in the outer block@>@/
@y
program TEX; {all file names are defined dynamically}
@z

@x
@ Three labels must be declared in the main program, so we give them
symbolic names.

@d start_of_TEX=1 {go here when \TeX's variables are initialized}
@d end_of_TEX=9998 {go here to close files and terminate gracefully}
@d final_end=9999 {this label marks the ending of the program}

@<Labels in the out...@>=
start_of_TEX@t\hskip-2pt@>, end_of_TEX@t\hskip-2pt@>,@,final_end;
  {key control points}
@y
@ For Web2c, labels are not declared in the main program, but
we still have to declare the symbolic names.

@d start_of_TEX=1 {go here when \TeX's variables are initialized}
@d final_end=9999 {this label marks the ending of the program}
@z

@x
@d debug==@{ {change this to `$\\{debug}\equiv\null$' when debugging}
@d gubed==@t@>@} {change this to `$\\{gubed}\equiv\null$' when debugging}
@y
@d debug==ifdef('TEXMF_DEBUG')
@d gubed==endif('TEXMF_DEBUG')
@z

@x
@d stat==@{ {change this to `$\\{stat}\equiv\null$' when gathering
  usage statistics}
@d tats==@t@>@} {change this to `$\\{tats}\equiv\null$' when gathering
  usage statistics}
@y
@d stat==ifdef('STAT')
@d tats==endif('STAT')
@z

@x
the codewords `$|init|\ldots|tini|$'.

@d init== {change this to `$\\{init}\equiv\.{@@\{}$' in the production version}
@d tini== {change this to `$\\{tini}\equiv\.{@@\}}$' in the production version}
@y
the codewords `$|init|\ldots|tini|$' for declarations and by the codewords
`$|Init|\ldots|Tini|$' for executable code.  This distinction is helpful for
implementations where a run-time switch differentiates between the two
versions of the program.

@d init==ifdef('INITEX')
@d tini==endif('INITEX')
@d Init==init if ini_version then begin
@d Tini==end;@+tini
@f Init==begin
@f Tini==end
@z

@x
@!init @<Initialize table entries (done by \.{INITEX} only)@>@;@+tini
@y
@!Init @<Initialize table entries (done by \.{INITEX} only)@>@;@+Tini
@z

@x
@<Constants...@>=
@!mem_max=30000; {greatest index in \TeX's internal |mem| array;
  must be strictly less than |max_halfword|;
  must be equal to |mem_top| in \.{INITEX}, otherwise |>=mem_top|}
@!mem_min=0; {smallest index in \TeX's internal |mem| array;
  must be |min_halfword| or more;
  must be equal to |mem_bot| in \.{INITEX}, otherwise |<=mem_bot|}
@!buf_size=500; {maximum number of characters simultaneously present in
  current lines of open files and in control sequences between
  \.{\\csname} and \.{\\endcsname}; must not exceed |max_halfword|}
@!error_line=72; {width of context lines on terminal error messages}
@!half_error_line=42; {width of first lines of contexts in terminal
  error messages; should be between 30 and |error_line-15|}
@!max_print_line=79; {width of longest text lines output; should be at least 60}
@!stack_size=200; {maximum number of simultaneous input sources}
@!max_in_open=6; {maximum number of input files and error insertions that
  can be going on simultaneously}
@!font_max=75; {maximum internal font number; must not exceed |max_quarterword|
  and must be at most |font_base+256|}
@!font_mem_size=20000; {number of words of |font_info| for all fonts}
@!param_size=60; {maximum number of simultaneous macro parameters}
@!nest_size=40; {maximum number of semantic levels simultaneously active}
@!max_strings=3000; {maximum number of strings; must not exceed |max_halfword|}
@!string_vacancies=8000; {the minimum number of characters that should be
  available for the user's control sequences and font names,
  after \TeX's own error messages are stored}
@!pool_size=32000; {maximum number of characters in strings, including all
  error messages and help texts, and the names of all fonts and
  control sequences; must exceed |string_vacancies| by the total
  length of \TeX's own strings, which is currently about 23000}
@!save_size=600; {space for saving values outside of current group; must be
  at most |max_halfword|}
@!trie_size=8000; {space for hyphenation patterns; should be larger for
  \.{INITEX} than it is in production versions of \TeX}
@!trie_op_size=500; {space for ``opcodes'' in the hyphenation patterns}
@!dvi_buf_size=800; {size of the output buffer; must be a multiple of 8}
@!file_name_size=40; {file names shouldn't be longer than this}
@!pool_name='TeXformats:TEX.POOL                     ';
  {string of length |file_name_size|; tells where the string pool appears}
@y
@d file_name_size == maxint
@d ssup_error_line = 255
@d ssup_max_strings == 2097151
{Larger values than 65536 cause the arrays to consume much more memory.}
@d ssup_trie_opcode == 65535
@d ssup_trie_size == @"3FFFFF

@d ssup_hyph_size == 65535 {Changing this requires changing (un)dumping!}
@d iinf_hyphen_size == 610 {Must be not less than |hyph_prime|!}

@d max_font_max=9000 {maximum number of internal fonts; this can be
                      increased, but |hash_size+max_font_max|
                      should not exceed 29000.}
@d font_base=0 {smallest internal font number; must be
                |>= min_quarterword|; do not change this without
                modifying the dynamic definition of the font arrays.}


@<Constants...@>=
@!hash_offset=514; {smallest index in hash array, i.e., |hash_base| }
  {Use |hash_offset=0| for compilers which cannot decrement pointers.}
@!trie_op_size=35111; {space for ``opcodes'' in the hyphenation patterns;
  best if relatively prime to 313, 361, and 1009.}
@!neg_trie_op_size=-35111; {for lower |trie_op_hash| array bound;
  must be equal to |-trie_op_size|.}
@!min_trie_op=0; {first possible trie op code for any language}
@!max_trie_op=ssup_trie_opcode; {largest possible trie opcode for any language}
@!pool_name=TEXMF_POOL_NAME; {this is configurable, for the sake of ML-\TeX}
  {string of length |file_name_size|; tells where the string pool appears}
@!engine_name=TEXMF_ENGINE_NAME; {the name of this engine}
@#
@!inf_mem_bot = 0;
@!sup_mem_bot = 1;

@!inf_main_memory = 3000;
@!sup_main_memory = 256000000;

@!inf_trie_size = 8000;
@!sup_trie_size = ssup_trie_size;

@!inf_max_strings = 3000;
@!sup_max_strings = ssup_max_strings;
@!inf_strings_free = 100;
@!sup_strings_free = sup_max_strings;

@!inf_buf_size = 500;
@!sup_buf_size = 30000000;

@!inf_nest_size = 40;
@!sup_nest_size = 4000;

@!inf_max_in_open = 6;
@!sup_max_in_open = 127;

@!inf_param_size = 60;
@!sup_param_size = 32767;

@!inf_save_size = 600;
@!sup_save_size = 80000;

@!inf_stack_size = 200;
@!sup_stack_size = 30000;

@!inf_dvi_buf_size = 800;
@!sup_dvi_buf_size = 65536;

@!inf_font_mem_size = 20000;
@!sup_font_mem_size = 147483647; {|integer|-limited, so 2 could be prepended?}

@!sup_font_max = max_font_max;
@!inf_font_max = 50; {could be smaller, but why?}

@!inf_pool_size = 32000;
@!sup_pool_size = 40000000;
@!inf_pool_free = 1000;
@!sup_pool_free = sup_pool_size;
@!inf_string_vacancies = 8000;
@!sup_string_vacancies = sup_pool_size - 23000;

@!sup_hash_extra = sup_max_strings;
@!inf_hash_extra = 0;

@!sup_hyph_size = ssup_hyph_size;
@!inf_hyph_size = iinf_hyphen_size; {Must be not less than |hyph_prime|!}

@!inf_expand_depth = 10;
@!sup_expand_depth = 10000000;
@z

@x
@d mem_bot=0 {smallest index in the |mem| array dumped by \.{INITEX};
  must not be less than |mem_min|}
@d mem_top==30000 {largest index in the |mem| array dumped by \.{INITEX};
  must be substantially larger than |mem_bot|
  and not greater than |mem_max|}
@d font_base=0 {smallest internal font number; must not be less
  than |min_quarterword|}
@d hash_size=2100 {maximum number of control sequences; it should be at most
  about |(mem_max-mem_min)/10|}
@d hash_prime=1777 {a prime number equal to about 85\pct! of |hash_size|}
@d hyph_size=307 {another prime; the number of \.{\\hyphenation} exceptions}
@y
@d hash_size=15000 {maximum number of control sequences; it should be at most
  about |(mem_max-mem_min)/10|; see also |font_max|}
@d hash_prime=8501 {a prime number equal to about 85\pct! of |hash_size|}
@d hyph_prime=607 {another prime for hashing \.{\\hyphenation} exceptions;
                if you change this, you should also change |iinf_hyphen_size|.}
@z

@x
@d incr(#) == #:=#+1 {increase a variable by unity}
@d decr(#) == #:=#-1 {decrease a variable by unity}
@y
@z

@x
@d text_char == char {the data type of characters in text files}
@y
@d text_char == ASCII_code {the data type of characters in text files}
@z

@x
@!xchr: array [ASCII_code] of text_char;
  {specifies conversion of output characters}
@y
@!xchr: ^text_char;
  {dummy variable so tangle doesn't complain; not actually used}
@z

@x
for i:=0 to @'37 do xchr[i]:=' ';
for i:=@'177 to @'377 do xchr[i]:=' ';
@y
@z

@x
for i:=0 to @'176 do xord[xchr[i]]:=i;
@y
@z

@x
@!name_of_file:packed array[1..file_name_size] of char;@;@/
  {on some systems this may be a \&{record} variable}
@y
@!name_of_file:^UTF8_code; {we build filenames in utf8 to pass to the OS}
@z

@x
@!name_of_file16:array[1..file_name_size] of UTF16_code;@;@/
@y
@!name_of_file16:^UTF16_code;
@z

@x
@ The \ph\ compiler with which the present version of \TeX\ was prepared has
extended the rules of \PASCAL\ in a very convenient way. To open file~|f|,
we can write
$$\vbox{\halign{#\hfil\qquad&#\hfil\cr
|reset(f,@t\\{name}@>,'/O')|&for input;\cr
|rewrite(f,@t\\{name}@>,'/O')|&for output.\cr}}$$
The `\\{name}' parameter, which is of type `{\bf packed array
$[\langle\\{any}\rangle]$ of \\{char}}', stands for the name of
the external file that is being opened for input or output.
Blank spaces that might appear in \\{name} are ignored.

The `\.{/O}' parameter tells the operating system not to issue its own
error messages if something goes wrong. If a file of the specified name
cannot be found, or if such a file cannot be opened for some other reason
(e.g., someone may already be trying to write the same file), we will have
|@!erstat(f)<>0| after an unsuccessful |reset| or |rewrite|.  This allows
\TeX\ to undertake appropriate corrective action.
@:PASCAL H}{\ph@>
@^system dependencies@>

\TeX's file-opening procedures return |false| if no file identified by
|name_of_file| could be opened.

@d reset_OK(#)==erstat(#)=0
@d rewrite_OK(#)==erstat(#)=0

@p function a_open_in(var f:alpha_file):boolean;
  {open a text file for input}
begin reset(f,name_of_file,'/O'); a_open_in:=reset_OK(f);
end;
@#
function a_open_out(var f:alpha_file):boolean;
  {open a text file for output}
begin rewrite(f,name_of_file,'/O'); a_open_out:=rewrite_OK(f);
end;
@#
function b_open_in(var f:byte_file):boolean;
  {open a binary file for input}
begin reset(f,name_of_file,'/O'); b_open_in:=reset_OK(f);
end;
@#
function b_open_out(var f:byte_file):boolean;
  {open a binary file for output}
begin rewrite(f,name_of_file,'/O'); b_open_out:=rewrite_OK(f);
end;
@#
function w_open_in(var f:word_file):boolean;
  {open a word file for input}
begin reset(f,name_of_file,'/O'); w_open_in:=reset_OK(f);
end;
@#
function w_open_out(var f:word_file):boolean;
  {open a word file for output}
begin rewrite(f,name_of_file,'/O'); w_open_out:=rewrite_OK(f);
end;
@y
@ All of the file opening functions are defined in C.
@z

@x
@ Files can be closed with the \ph\ routine `|close(f)|', which
@:PASCAL H}{\ph@>
@^system dependencies@>
should be used when all input or output with respect to |f| has been completed.
This makes |f| available to be opened again, if desired; and if |f| was used for
output, the |close| operation makes the corresponding external file appear
on the user's area, ready to be read.

These procedures should not generate error messages if a file is
being closed before it has been successfully opened.

@p procedure a_close(var f:alpha_file); {close a text file}
begin close(f);
end;
@#
procedure b_close(var f:byte_file); {close a binary file}
begin close(f);
end;
@#
procedure w_close(var f:word_file); {close a word file}
begin close(f);
end;
@y
@ And all the file closing routines as well.
@z

@x
@!buffer:array[0..buf_size] of ASCII_code; {lines of characters being read}
@y
@!buffer:^UnicodeScalar; {lines of characters being read}
@z

@x
@p function input_ln(var f:alpha_file;@!bypass_eoln:boolean):boolean;
  {inputs the next line or returns |false|}
var last_nonblank:0..buf_size; {|last| with trailing blanks removed}
begin if bypass_eoln then if not eof(f) then get(f);
  {input the first character of the line into |f^|}
last:=first; {cf.\ Matthew 19\thinspace:\thinspace30}
if eof(f) then input_ln:=false
else  begin last_nonblank:=first;
  while not eoln(f) do
    begin if last>=max_buf_stack then
      begin max_buf_stack:=last+1;
      if max_buf_stack=buf_size then
        @<Report overflow of the input buffer, and abort@>;
      end;
    buffer[last]:=xord[f^]; get(f); incr(last);
    if buffer[last-1]<>" " then last_nonblank:=last;
    end;
  last:=last_nonblank; input_ln:=true;
  end;
end;
@y
We define |input_ln| in C, for efficiency. Nevertheless we quote the module
`Report overflow of the input buffer, and abort' here in order to make
\.{WEAVE} happy, since part of that module is needed by e-TeX.

@p @{ @<Report overflow of the input buffer, and abort@> @}
@z

@x
@<Glob...@>=
@!term_in:alpha_file; {the terminal as an input file}
@!term_out:alpha_file; {the terminal as an output file}
@y
@d term_out==stdout {the terminal as an output file}

@<Glob...@>=
@!init
@!ini_version:boolean; {are we \.{INITEX}?}
@!dump_option:boolean; {was the dump name option used?}
@!dump_line:boolean; {was a \.{\%\AM format} line seen?}
tini@/
@#
@!dump_name:const_cstring; {format name for terminal display}
@#
@!term_in:unicode_file;
@#
@!bound_default:integer; {temporary for setup}
@!bound_name:const_cstring; {temporary for setup}
@#
@!mem_bot:integer;{smallest index in the |mem| array dumped by \.{INITEX};
  must not be less than |mem_min|}
@!main_memory:integer; {total memory words allocated in initex}
@!extra_mem_bot:integer; {|mem_min:=mem_bot-extra_mem_bot| except in \.{INITEX}}
@!mem_min:integer; {smallest index in \TeX's internal |mem| array;
  must be |min_halfword| or more;
  must be equal to |mem_bot| in \.{INITEX}, otherwise |<=mem_bot|}
@!mem_top:integer; {largest index in the |mem| array dumped by \.{INITEX};
  must be substantially larger than |mem_bot|,
  equal to |mem_max| in \.{INITEX}, else not greater than |mem_max|}
@!extra_mem_top:integer; {|mem_max:=mem_top+extra_mem_top| except in \.{INITEX}}
@!mem_max:integer; {greatest index in \TeX's internal |mem| array;
  must be strictly less than |max_halfword|;
  must be equal to |mem_top| in \.{INITEX}, otherwise |>=mem_top|}
@!error_line:integer; {width of context lines on terminal error messages}
@!half_error_line:integer; {width of first lines of contexts in terminal
  error messages; should be between 30 and |error_line-15|}
@!max_print_line:integer;
  {width of longest text lines output; should be at least 60}
@!max_strings:integer; {maximum number of strings; must not exceed |max_halfword|}
@!strings_free:integer; {strings available after format loaded}
@!string_vacancies:integer; {the minimum number of characters that should be
  available for the user's control sequences and font names,
  after \TeX's own error messages are stored}
@!pool_size:integer; {maximum number of characters in strings, including all
  error messages and help texts, and the names of all fonts and
  control sequences; must exceed |string_vacancies| by the total
  length of \TeX's own strings, which is currently about 23000}
@!pool_free:integer;{pool space free after format loaded}
@!font_mem_size:integer; {number of words of |font_info| for all fonts}
@!font_max:integer; {maximum internal font number; ok to exceed |max_quarterword|
  and must be at most |font_base|+|max_font_max|}
@!font_k:integer; {loop variable for initialization}
@!hyph_size:integer; {maximun number of hyphen exceptions}
@!trie_size:integer; {space for hyphenation patterns; should be larger for
  \.{INITEX} than it is in production versions of \TeX.  50000 is
  needed for English, German, and Portuguese.}
@!buf_size:integer; {maximum number of characters simultaneously present in
  current lines of open files and in control sequences between
  \.{\\csname} and \.{\\endcsname}; must not exceed |max_halfword|}
@!stack_size:integer; {maximum number of simultaneous input sources}
@!max_in_open:integer; {maximum number of input files and error insertions that
  can be going on simultaneously}
@!param_size:integer; {maximum number of simultaneous macro parameters}
@!nest_size:integer; {maximum number of semantic levels simultaneously active}
@!save_size:integer; {space for saving values outside of current group; must be
  at most |max_halfword|}
@!dvi_buf_size:integer; {size of the output buffer; must be a multiple of 8}
@!expand_depth:integer; {limits recursive calls to the |expand| procedure}
@!parse_first_line_p:cinttype; {parse the first line for options}
@!file_line_error_style_p:cinttype; {format messages as file:line:error}
@!eight_bit_p:cinttype; {make all characters printable by default}
@!halt_on_error_p:cinttype; {stop at first error}
@!quoted_filename:boolean; {current filename is quoted}
{Variables for source specials}
@!src_specials_p : boolean;{Whether |src_specials| are enabled at all}
@!insert_src_special_auto : boolean;
@!insert_src_special_every_par : boolean;
@!insert_src_special_every_parend : boolean;
@!insert_src_special_every_cr : boolean;
@!insert_src_special_every_math : boolean;
@!insert_src_special_every_hbox : boolean;
@!insert_src_special_every_vbox : boolean;
@!insert_src_special_every_display : boolean;
@z

@x
@ Here is how to open the terminal files
in \ph. The `\.{/I}' switch suppresses the first |get|.
@:PASCAL H}{\ph@>
@^system dependencies@>

@d t_open_in==reset(term_in,'TTY:','/O/I') {open the terminal for text input}
@d t_open_out==rewrite(term_out,'TTY:','/O') {open the terminal for text output}
@y
@ Here is how to open the terminal files.  |t_open_out| does nothing.
|t_open_in|, on the other hand, does the work of ``rescanning,'' or getting
any command line arguments the user has provided.  It's defined in C.

@d t_open_out == {output already open for text output}
@z

@x
these operations can be specified in \ph:
@:PASCAL H}{\ph@>
@^system dependencies@>

@d update_terminal == break(term_out) {empty the terminal output buffer}
@d clear_terminal == break_in(term_in,true) {clear the terminal input buffer}
@y
these operations can be specified with {\mc UNIX}.  |update_terminal|
does an |fflush|. |clear_terminal| is redefined
to do nothing, since the user should control the terminal.
@^system dependencies@>

@d update_terminal == fflush (term_out)
@d clear_terminal == do_nothing
@z

@x
@<Report overflow of the input buffer, and abort@>=
if format_ident=0 then
  begin write_ln(term_out,'Buffer size exceeded!'); goto final_end;
@.Buffer size exceeded@>
  end
else begin cur_input.loc_field:=first; cur_input.limit_field:=last-1;
@y
Routine is implemented in C; part of module is, however, needed for e-TeX.

@<Report overflow of the input buffer, and abort@>=
  begin cur_input.loc_field:=first; cur_input.limit_field:=last-1;
@z

@x
@ The following program does the required initialization
without retrieving a possible command line.
It should be clear how to modify this routine to deal with command lines,
if the system permits them.
@^system dependencies@>

@p function init_terminal:boolean; {gets the terminal input started}
label exit;
begin t_open_in;
@y
@ The following program does the required initialization.
Iff anything has been specified on the command line, then |t_open_in|
will return with |last > first|.
@^system dependencies@>

@p function init_terminal:boolean; {gets the terminal input started}
label exit;
begin t_open_in;
if last > first then
  begin loc := first;
  while (loc < last) and (buffer[loc]=' ') do incr(loc);
  if loc < last then
    begin init_terminal := true; goto exit;
    end;
  end;
@z

@x
    write(term_out,'! End of file on the terminal... why?');
@y
    write_ln(term_out,'! End of file on the terminal... why?');
@z

@x
@!pool_pointer = 0..pool_size; {for variables that point into |str_pool|}
@!str_number = 0..max_strings; {for variables that point into |str_start|}
@y
@!pool_pointer = integer; {for variables that point into |str_pool|}
@!str_number = 0..ssup_max_strings; {for variables that point into |str_start|}
@z

@x
@!str_pool:packed array[pool_pointer] of packed_ASCII_code; {the characters}
@!str_start : array[str_number] of pool_pointer; {the starting pointers}
@y
@!str_pool: ^packed_ASCII_code; {the characters}
@!str_start : ^pool_pointer; {the starting pointers}
@z

@x
@p @!init function get_strings_started:boolean; {initializes the string pool,
@y
@p @t\4@>@<Declare additional routines for string recycling@>@/

@!init function get_strings_started:boolean; {initializes the string pool,
@z

@x
@!m,@!n:text_char; {characters input from |pool_file|}
@!g:str_number; {garbage}
@!a:integer; {accumulator for check sum}
@!c:boolean; {check sum has been checked}
@y
@!g:str_number; {garbage}
@z

@x
would like string @'32 to be the single character @'32 instead of the
@y
would like string @'32 to be printed as the single character @'32
instead of the
@z

@x
@ @d bad_pool(#)==begin wake_up_terminal; write_ln(term_out,#);
  a_close(pool_file); get_strings_started:=false; return;
  end
@<Read the other strings...@>=
name_of_file:=pool_name; {we needn't set |name_length|}
if a_open_in(pool_file) then
  begin c:=false;
  repeat @<Read one string, but return |false| if the
    string memory space is getting too tight for comfort@>;
  until c;
  a_close(pool_file); get_strings_started:=true;
  end
else  bad_pool('! I can''t read TEX.POOL.')
@.I can't read TEX.POOL@>

@ @<Read one string...@>=
begin if eof(pool_file) then bad_pool('! TEX.POOL has no check sum.');
@.TEX.POOL has no check sum@>
read(pool_file,m,n); {read two digits of string length}
if m='*' then @<Check the pool check sum@>
else  begin if (xord[m]<"0")or(xord[m]>"9")or@|
      (xord[n]<"0")or(xord[n]>"9") then
    bad_pool('! TEX.POOL line doesn''t begin with two digits.');
@.TEX.POOL line doesn't...@>
  l:=xord[m]*10+xord[n]-"0"*11; {compute the length}
  if pool_ptr+l+string_vacancies>pool_size then
    bad_pool('! You have to increase POOLSIZE.');
@.You have to increase POOLSIZE@>
  for k:=1 to l do
    begin if eoln(pool_file) then m:=' '@+else read(pool_file,m);
    append_char(xord[m]);
    end;
  read_ln(pool_file); g:=make_string;
  end;
end

@ The \.{WEB} operation \.{@@\$} denotes the value that should be at the
end of this \.{TEX.POOL} file; any other value means that the wrong pool
file has been loaded.
@^check sum@>

@<Check the pool check sum@>=
begin a:=0; k:=1;
loop@+  begin if (xord[n]<"0")or(xord[n]>"9") then
  bad_pool('! TEX.POOL check sum doesn''t have nine digits.');
@.TEX.POOL check sum...@>
  a:=10*a+xord[n]-"0";
  if k=9 then goto done;
  incr(k); read(pool_file,n);
  end;
done: if a<>@$ then bad_pool('! TEX.POOL doesn''t match; TANGLE me again.');
@.TEX.POOL doesn't match@>
c:=true;
end
@y
@ @<Read the other strings...@>=
  g := loadpoolstrings((pool_size-string_vacancies));
  if g=0 then begin
     wake_up_terminal; write_ln(term_out,'! You have to increase POOLSIZE.');
     get_strings_started:=false;
     return;
  end;
  get_strings_started:=true;

@ Empty module

@ Empty module
@z

@x
@!trick_buf:array[0..error_line] of ASCII_code; {circular buffer for
@y
@!trick_buf:array[0..ssup_error_line] of ASCII_code; {circular buffer for
@z

@x
wterm(banner);
@y
if src_specials_p or file_line_error_style_p or parse_first_line_p then
  wterm(banner_k)
else
  wterm(banner);
@z

@x
if format_ident=0 then wterm_ln(' (no format preloaded)')
else  begin slow_print(format_ident); print_ln;
  end;
@y
wterm(version_string);
if format_ident=0 then wterm_ln(' (preloaded format=',dump_name,')')
else  begin slow_print(format_ident); print_ln;
  end;
if shellenabledp then begin
  wterm(' ');
  if restrictedshell then begin
    wterm('restricted ');
  end;
  wterm_ln('\write18 enabled.');
end;
if src_specials_p then begin
  wterm_ln(' Source specials enabled.')
end;
if translate_filename then begin
  wterm(' (WARNING: translate-file "');
  fputs(translate_filename, stdout);
  wterm_ln('" ignored)');
end;
@z

@x
@d error_stop_mode=3 {stops at every opportunity to interact}
@y
@d error_stop_mode=3 {stops at every opportunity to interact}
@d unspecified_mode=4 {extra value for command-line switch}
@z

@x
  print_nl("! "); print(#);
@y
  if file_line_error_style_p then print_file_line
  else print_nl("! ");
  print(#);
@z

@x
@!interaction:batch_mode..error_stop_mode; {current level of interaction}
@y
@!interaction:batch_mode..error_stop_mode; {current level of interaction}
@!interaction_option:batch_mode..unspecified_mode; {set from command line}
@z

@x
@ @<Set init...@>=interaction:=error_stop_mode;
@y
@ @<Set init...@>=if interaction_option=unspecified_mode then
  interaction:=error_stop_mode
else
  interaction:=interaction_option;
@z

@x
@<Error hand...@>=
procedure jump_out;
begin goto end_of_TEX;
end;
@y
@d do_final_end==begin
   update_terminal;
   ready_already:=0;
   if (history <> spotless) and (history <> warning_issued) then
       uexit(1)
   else
       uexit(0);
   end

@<Error hand...@>=
noreturn procedure jump_out;
begin
close_files_and_terminate;
do_final_end;
end;
@z

@x
print_char("."); show_context;
@y
print_char("."); show_context;
if (halt_on_error_p) then begin
  history:=fatal_error_stop; jump_out;
end;
@z

@x
line ready to be edited. But such an extension requires some system
wizardry, so the present implementation simply types out the name of the
file that should be
edited and the relevant line number.
@^system dependencies@>

There is a secret `\.D' option available when the debugging routines haven't
been commented~out.
@^debugging@>
@y
line ready to be edited.
We do this by calling the external procedure |call_edit| with a pointer to
the filename, its length, and the line number.
However, here we just set up the variables that will be used as arguments,
since we don't want to do the switch-to-editor until after TeX has closed
its files.
@^system dependencies@>

There is a secret `\.D' option available when the debugging routines haven't
been commented~out.
@^debugging@>
@d edit_file==input_stack[base_ptr]
@z

@x
"E": if base_ptr>0 then
  begin print_nl("You want to edit file ");
@.You want to edit file x@>
  slow_print(input_stack[base_ptr].name_field);
  print(" at line "); print_int(line);
  interaction:=scroll_mode; jump_out;
@y
"E": if base_ptr>0 then
    begin edit_name_start:=str_start_macro(edit_file.name_field);
    edit_name_length:=str_start_macro(edit_file.name_field+1) -
                      str_start_macro(edit_file.name_field);
    edit_line:=line;
    jump_out;
@z

@x
procedure fatal_error(@!s:str_number); {prints |s|, and that's it}
@y
noreturn procedure fatal_error(@!s:str_number); {prints |s|, and that's it}
@z

@x
procedure overflow(@!s:str_number;@!n:integer); {stop due to finiteness}
@y
noreturn procedure overflow(@!s:str_number;@!n:integer); {stop due to finiteness}
@z

@x
procedure confusion(@!s:str_number);
@y
noreturn procedure confusion(@!s:str_number);
@z

@x
|remainder|, holds the remainder after a division.

@<Glob...@>=
@y
|remainder|, holds the remainder after a division.

@d remainder==tex_remainder

@<Glob...@>=
@z

@x
@!glue_ratio=real; {one-word representation of a glue expansion factor}
@y
@z

@x
@d min_halfword==-@"FFFFFFF {smallest allowable value in a |halfword|}
@d max_halfword==@"3FFFFFFF {largest allowable value in a |halfword|}
@y
@d min_halfword==-@"FFFFFFF {smallest allowable value in a |halfword|}
@d max_halfword==@"3FFFFFFF {largest allowable value in a |halfword|}
@z

@x
if (mem_min<min_halfword)or(mem_max>=max_halfword)or@|
  (mem_bot-mem_min>max_halfword+1) then bad:=14;
@y
if (mem_bot-sup_main_memory<min_halfword)or@|
  (mem_top+sup_main_memory>=max_halfword) then bad:=14;
@z

@x
if (font_base<min_quarterword)or(font_max>max_quarterword) then bad:=15;
if font_max>font_base+256 then bad:=16;
@y
if (max_font_max<min_halfword)or(max_font_max>max_halfword) then bad:=15;
if font_max>font_base+max_font_max then bad:=16;
@z

@x
macros are simplified in the obvious way when |min_quarterword=0|.
@^inner loop@>@^system dependencies@>

@d qi(#)==#+min_quarterword
  {to put an |eight_bits| item into a quarterword}
@d qo(#)==#-min_quarterword
  {to take an |eight_bits| item out of a quarterword}
@d hi(#)==#+min_halfword
  {to put a sixteen-bit item into a halfword}
@d ho(#)==#-min_halfword
  {to take a sixteen-bit item from a halfword}
@y
macros are simplified in the obvious way when |min_quarterword=0|.
So they have been simplified here in the obvious way.
@^inner loop@>@^system dependencies@>

The \.{WEB} source for \TeX\ defines |hi(#)==#+min_halfword| which can be
simplified when |min_halfword=0|.  The Web2C implemetation of \TeX\ can use
|hi(#)==#| together with |min_halfword<0| as long as |max_halfword| is
sufficiently large.

@d qi(#)==# {to put an |eight_bits| item into a quarterword}
@d qo(#)==# {to take an |eight_bits| item from a quarterword}
@d hi(#)==# {to put a sixteen-bit item into a halfword}
@d ho(#)==# {to take a sixteen-bit item from a halfword}
@z

@x
@!quarterword = min_quarterword..max_quarterword; {1/4 of a word}
@!halfword=min_halfword..max_halfword; {1/2 of a word}
@!two_choices = 1..2; {used when there are two variants in a record}
@!four_choices = 1..4; {used when there are four variants in a record}
@!two_halves = packed record@;@/
  @!rh:halfword;
  case two_choices of
  1: (@!lh:halfword);
  2: (@!b0:quarterword; @!b1:quarterword);
  end;
@!four_quarters = packed record@;@/
  @!b0:quarterword;
  @!b1:quarterword;
  @!b2:quarterword;
  @!b3:quarterword;
  end;
@!memory_word = record@;@/
  case four_choices of
  1: (@!int:integer);
  2: (@!gr:glue_ratio);
  3: (@!hh:two_halves);
  4: (@!qqqq:four_quarters);
  end;
@y
@!quarterword = min_quarterword..max_quarterword;
@!halfword = min_halfword..max_halfword;
@!two_choices = 1..2; {used when there are two variants in a record}
@!four_choices = 1..4; {used when there are four variants in a record}
@=#include "texmfmem.h";@>
@z

@x
@!mem : array[mem_min..mem_max] of memory_word; {the big dynamic storage area}
@y
@!yzmem : ^memory_word; {the big dynamic storage area}
@!zmem : ^memory_word; {the big dynamic storage area}
@z

@x
@p function get_node(@!s:integer):pointer; {variable-size node allocation}
@y
@p function get_node(@!s:integer):pointer; {variable-size node allocation}
@z

@x
get_node:=r;
@y
@<Initialize bigger nodes with {\sl Sync\TeX} information@>;
get_node:=r;
@z

@x
@d hlist_node=0 {|type| of hlist nodes}
@y
@d synctex_field_size=1 {Declare the {\sl Sync\TeX} field size to store the {\sl Sync\TeX} information:
                         we will put file tag and line into lh and rh fields of one word}
@d sync_tag(#) == mem[#-synctex_field_size].hh.lh {The tag subfield}
@d sync_line(#) == mem[#-synctex_field_size].hh.rh {The line subfield}
@#
@d hlist_node=0 {|type| of hlist nodes}
@z

@x
@d box_node_size=7 {number of words to allocate for a box node}
@y
@d box_node_size=7+synctex_field_size {number of words to allocate for a box node}
@z

@x
@d rule_node_size=4 {number of words to allocate for a rule node}
@y
@d rule_node_size=4+synctex_field_size {number of words to allocate for a rule node}
@z

@x
@d small_node_size=2 {number of words to allocate for most node types}
@y
@d small_node_size=2 {number of words to allocate for most node types}
@d medium_node_size=small_node_size+synctex_field_size {number of words to
           allocate for synchronized node types like math, kern, glue and penalty nodes}
@z

@x
@p function new_ligature(@!f,@!c:quarterword; @!q:pointer):pointer;
@y
@p function new_ligature(@!f:internal_font_number; @!c:quarterword;
                         @!q:pointer):pointer;
@z

@x
@p function new_math(@!w:scaled;@!s:small_number):pointer;
@y
@p function new_math(@!w:scaled;@!s:small_number):pointer;
@z

@x
begin p:=get_node(small_node_size); type(p):=math_node;
@y
begin p:=get_node(medium_node_size); type(p):=math_node;
@z

@x
@p function new_param_glue(@!n:small_number):pointer;
@y
@p function new_param_glue(@!n:small_number):pointer;
@z

@x
begin p:=get_node(small_node_size); type(p):=glue_node; subtype(p):=n+1;
@y
begin p:=get_node(medium_node_size); type(p):=glue_node; subtype(p):=n+1;
@z

@x
@p function new_glue(@!q:pointer):pointer;
@y
@p function new_glue(@!q:pointer):pointer;
@z

@x
begin p:=get_node(small_node_size); type(p):=glue_node; subtype(p):=normal;
@y
begin p:=get_node(medium_node_size); type(p):=glue_node; subtype(p):=normal;
@z

@x
@p function new_kern(@!w:scaled):pointer;
@y
@p function new_kern(@!w:scaled):pointer;
@z

@x
begin p:=get_node(small_node_size); type(p):=kern_node;
@y
begin p:=get_node(medium_node_size); type(p):=kern_node;
@z

@x
@p function new_penalty(@!m:integer):pointer;
@y
@p function new_penalty(@!m:integer):pointer;
@z

@x
begin p:=get_node(small_node_size); type(p):=penalty_node;
@y
begin p:=get_node(medium_node_size); type(p):=penalty_node;
@z

@x
are debugging.)
@y
are debugging.)

@d free==free_arr
@z

@x
@!debug @!free: packed array [mem_min..mem_max] of boolean; {free cells}
@t\hskip10pt@>@!was_free: packed array [mem_min..mem_max] of boolean;
@y
 {The debug memory arrays have not been mallocated yet.}
@!debug @!free: packed array [0..9] of boolean; {free cells}
@t\hskip10pt@>@!was_free: packed array [0..9] of boolean;
@z

@x
        begin if (font(p)<font_base)or(font(p)>font_max) then
@y
        begin if (font(p)>font_max) then
@z

@x
@p procedure print_font_and_char(@!p:integer); {prints |char_node| data}
begin if p>mem_end then print_esc("CLOBBERED.")
else  begin if (font(p)<font_base)or(font(p)>font_max) then print_char("*")
@y
@p procedure print_font_and_char(@!p:integer); {prints |char_node| data}
begin if p>mem_end then print_esc("CLOBBERED.")
else  begin if (font(p)>font_max) then print_char("*")
@z

@x
  if abs(mem[p+glue_offset].int)<@'4000000 then print("?.?")
  else if abs(g)>float_constant(20000) then
@y
  { The Unix |pc| folks removed this restriction with a remark that
    invalid bit patterns were vanishingly improbable, so we follow
    their example without really understanding it.
  |if abs(mem[p+glue_offset].int)<@'4000000 then print('?.?')|
  |else| }
  if fabs(g)>float_constant(20000) then
@z

@x
@p procedure flush_node_list(@!p:pointer); {erase list of nodes starting at |p|}
@y
@p procedure flush_node_list(@!p:pointer); {erase list of nodes starting at |p|}
@z

@x
    glue_node: begin fast_delete_glue_ref(glue_ptr(p));
      if leader_ptr(p)<>null then flush_node_list(leader_ptr(p));
      end;
@y
    glue_node: begin fast_delete_glue_ref(glue_ptr(p));
      if leader_ptr(p)<>null then flush_node_list(leader_ptr(p));
        free_node(p, medium_node_size);
        goto done;
      end;
@z

@x
    kern_node,math_node,penalty_node: do_nothing;
@y
    kern_node,math_node,penalty_node:begin
        free_node(p, medium_node_size);
        goto done;
      end;
@z

@x
@ @<Case statement to copy...@>=
@y
@ @<Case statement to copy...@>=
@z

@x
hlist_node,vlist_node,unset_node: begin r:=get_node(box_node_size);
@y
hlist_node,vlist_node,unset_node: begin r:=get_node(box_node_size);
  @<Copy the box {\sl Sync\TeX} information@>;
@z

@x
rule_node: begin r:=get_node(rule_node_size); words:=rule_node_size;
@y
rule_node: begin r:=get_node(rule_node_size); words:=rule_node_size-synctex_field_size;{{\sl Sync\TeX}: do not let \TeX\ copy the {\sl Sync\TeX} information}
  @<Copy the rule {\sl Sync\TeX} information@>;
@z

@x
glue_node: begin r:=get_node(small_node_size); add_glue_ref(glue_ptr(p));
@y
glue_node: begin r:=get_node(medium_node_size); add_glue_ref(glue_ptr(p));
  @<Copy the medium sized node {\sl Sync\TeX} information@>;
@z

@x
kern_node,math_node,penalty_node: begin r:=get_node(small_node_size);
  words:=small_node_size;
  end;
@y
kern_node,math_node,penalty_node: begin r:=get_node(medium_node_size);
  words:=medium_node_size;
  end;
@z

@x
@d shorthand_def=97 {code definition ( \.{\\chardef}, \.{\\countdef}, etc.~)}
@y
@d shorthand_def=97 {code definition ( \.{\\chardef}, \.{\\countdef}, etc.~)}
  {or \.{\\charsubdef}}
@z

@x
begin if m>0 then
  case m div (max_command+1) of
  0:print("vertical");
  1:print("horizontal");
  2:print("display math");
  end
else if m=0 then print("no")
else  case (-m) div (max_command+1) of
  0:print("internal vertical");
  1:print("restricted horizontal");
  2:print("math");
  end;
print(" mode");
end;
@y
begin if m>0 then
  case m div (max_command+1) of
  0:print("vertical mode");
  1:print("horizontal mode");
  2:print("display math mode");
  end
else if m=0 then print("no mode")
else  case (-m) div (max_command+1) of
  0:print("internal vertical mode");
  1:print("restricted horizontal mode");
  2:print("math mode");
  end;
end;

procedure print_in_mode(@!m:integer); {prints the mode represented by |m|}
begin if m>0 then
  case m div (max_command+1) of
  0:print("' in vertical mode");
  1:print("' in horizontal mode");
  2:print("' in display math mode");
  end
else if m=0 then print("' in no mode")
else  case (-m) div (max_command+1) of
  0:print("' in internal vertical mode");
  1:print("' in restricted horizontal mode");
  2:print("' in math mode");
  end;
end;
@z

@x
@!nest:array[0..nest_size] of list_state_record;
@y
@!nest:^list_state_record;
@z

@x
prev_graf:=0; shown_mode:=0;
@<Start a new current page@>;
@y
prev_graf:=0; shown_mode:=0;
@/{The following piece of code is a copy of module 991:}
page_contents:=empty; page_tail:=page_head; {|link(page_head):=null;|}@/
last_glue:=max_halfword; last_penalty:=0; last_kern:=0;
page_depth:=0; page_max_depth:=0;
@z

@x
    print_int(nest[p].pg_field); print(" line");
    if nest[p].pg_field<>1 then print_char("s");
@y
    print_int(nest[p].pg_field);
    if nest[p].pg_field<>1 then print(" lines")
    else print(" line");
@z

@x
paragraph shape.
@y
paragraph shape.
Additionally region~4 contains the table with ML\TeX's character
substitution definitions.
@z

@x
@d frozen_null_font=frozen_control_sequence+10
@y
@d frozen_special=frozen_control_sequence+10
  {permanent `\.{\\special}'}
@d frozen_primitive=frozen_control_sequence+11
  {permanent `\.{\\primitive}'}
@d frozen_null_font=frozen_control_sequence+12
@z

@x
@d undefined_control_sequence=frozen_null_font+257 {dummy location}
@y
@d undefined_control_sequence=frozen_null_font+max_font_max+1 {dummy location}
@z

@x
for k:=active_base to undefined_control_sequence-1 do
  eqtb[k]:=eqtb[undefined_control_sequence];
@y
for k:=active_base to eqtb_top do
  eqtb[k]:=eqtb[undefined_control_sequence];
@z

@x
@d int_base=math_code_base+number_usvs {beginning of region 5}
@y
@d char_sub_code_base=math_code_base+number_usvs {table of character substitutions}
@d int_base=char_sub_code_base+number_usvs {beginning of region 5}
@z

@x
  {Note: |math_code(c)| is the true math code plus |min_halfword|}
@y
  {Note: |math_code(c)| is the true math code plus |min_halfword|}
@d char_sub_code(#)==equiv(char_sub_code_base+#)
  {Note: |char_sub_code(c)| is the true substitution info plus |min_halfword|}
@z

@x
@d pretolerance_code=0 {badness tolerance before hyphenation}
@y

@d pretolerance_code=0 {badness tolerance before hyphenation}
@z

@x
@d tex_int_pars=55 {total number of \TeX's integer parameters}
@y
@d tex_int_pars=55 {total number of \TeX's integer parameters}
@#
@d web2c_int_base=tex_int_pars {base for web2c's integer parameters}
@d char_sub_def_min_code=web2c_int_base {smallest value in the charsubdef list}
@d char_sub_def_max_code=web2c_int_base+1 {largest value in the charsubdef list}
@d tracing_char_sub_def_code=web2c_int_base+2 {traces changes to a charsubdef def}
@d web2c_int_pars=web2c_int_base+3 {total number of web2c's integer parameters}
@#
@z

@x
@#
@d etex_int_base=tex_int_pars {base for \eTeX's integer parameters}
@y
@d etex_int_base=web2c_int_pars {base for \eTeX's integer parameters}
@z

@x
@d int_pars=etex_int_pars {total number of integer parameters}
@y
@d synctex_code=etex_int_pars
@d int_pars=synctex_code+1 {total number of integer parameters}
@z

@x
@d error_context_lines==int_par(error_context_lines_code)
@y
@d error_context_lines==int_par(error_context_lines_code)
@#
@d synctex == int_par(synctex_code)
@#
@d char_sub_def_min==int_par(char_sub_def_min_code)
@d char_sub_def_max==int_par(char_sub_def_max_code)
@d tracing_char_sub_def==int_par(tracing_char_sub_def_code)
@z

@x
error_context_lines_code:print_esc("errorcontextlines");
@y
error_context_lines_code:print_esc("errorcontextlines");
char_sub_def_min_code:print_esc("charsubdefmin");
char_sub_def_max_code:print_esc("charsubdefmax");
tracing_char_sub_def_code:print_esc("tracingcharsubdef");
@z

@x
@/@<Cases for |print_param|@>@/
othercases print("[unknown integer parameter!]")
@y
@/@<synctex case for |print_param|@>@/
@/@<Cases for |print_param|@>@/
othercases print("[unknown integer parameter!]")
@z

@x
@!@:error_context_lines_}{\.{\\errorcontextlines} primitive@>
@y
@!@:error_context_lines_}{\.{\\errorcontextlines} primitive@>
if mltex_p then
  begin mltex_enabled_p:=true;  {enable character substitution}
  if false then {remove the if-clause to enable \.{\\charsubdefmin}}
  primitive("charsubdefmin",assign_int,int_base+char_sub_def_min_code);@/
@!@:char_sub_def_min_}{\.{\\charsubdefmin} primitive@>
  primitive("charsubdefmax",assign_int,int_base+char_sub_def_max_code);@/
@!@:char_sub_def_max_}{\.{\\charsubdefmax} primitive@>
  primitive("tracingcharsubdef",assign_int,int_base+tracing_char_sub_def_code);@/
@!@:tracing_char_sub_def_}{\.{\\tracingcharsubdef} primitive@>
  end;
@z

@x
for k:=int_base to del_code_base-1 do eqtb[k].int:=0;
@y
for k:=int_base to del_code_base-1 do eqtb[k].int:=0;
char_sub_def_min:=256; char_sub_def_max:=-1;
{allow \.{\\charsubdef} for char 0}@/
{|tracing_char_sub_def:=0| is already done}@/
@z

@x
@ The following procedure, which is called just before \TeX\ initializes its
input and output, establishes the initial values of the date and time.
@^system dependencies@>
Since standard \PASCAL\ cannot provide such information, something special
is needed. The program here simply specifies July 4, 1776, at noon; but
users probably want a better approximation to the truth.

@p procedure fix_date_and_time;
begin time:=12*60; {minutes since midnight}
day:=4; {fourth day of the month}
month:=7; {seventh month of the year}
year:=1776; {Anno Domini}
end;
@y
@ The following procedure, which is called just before \TeX\ initializes its
input and output, establishes the initial values of the date and time.
It calls a macro-defined |date_and_time| routine.  |date_and_time|
in turn is a C macro, which calls |get_date_and_time|, passing
it the addresses of the day, month, etc., so they can be set by the
routine.  |get_date_and_time| also sets up interrupt catching if that
is conditionally compiled in the C code.
@^system dependencies@>

@d fix_date_and_time==date_and_time(time,day,month,year)
@z

@x
else if n<glue_base then @<Show equivalent |n|, in region 1 or 2@>
@y
else if (n<glue_base) or ((n>eqtb_size)and(n<=eqtb_top)) then
  @<Show equivalent |n|, in region 1 or 2@>
@z

@x
@!eqtb:array[active_base..eqtb_size] of memory_word;
@y
@!zeqtb:^memory_word;
@z

@x
@!hash: array[hash_base..undefined_control_sequence-1] of two_halves;
  {the hash table}
@!hash_used:pointer; {allocation pointer for |hash|}
@y
@!hash: ^two_halves; {the hash table}
@!yhash: ^two_halves; {auxiliary pointer for freeing hash}
@!hash_used:pointer; {allocation pointer for |hash|}
@!hash_extra:pointer; {|hash_extra=hash| above |eqtb_size|}
@!hash_top:pointer; {maximum of the hash array}
@!eqtb_top:pointer; {maximum of the |eqtb|}
@!hash_high:pointer; {pointer to next high hash location}
@z

@x
next(hash_base):=0; text(hash_base):=0;
for k:=hash_base+1 to undefined_control_sequence-1 do hash[k]:=hash[hash_base];
@y
@z

@x
hash_used:=frozen_control_sequence; {nothing is used}
@y
hash_used:=frozen_control_sequence; {nothing is used}
hash_high:=0;
@z

@x
@ @<Insert a new control...@>=
begin if text(p)>0 then
  begin repeat if hash_is_full then overflow("hash size",hash_size);
@:TeX capacity exceeded hash size}{\quad hash size@>
  decr(hash_used);
  until text(hash_used)=0; {search for an empty location in |hash|}
  next(p):=hash_used; p:=hash_used;
  end;
@y
@ @<Insert a new control...@>=
begin if text(p)>0 then
  begin if hash_high<hash_extra then
      begin incr(hash_high);
      next(p):=hash_high+eqtb_size; p:=hash_high+eqtb_size;
      end
    else begin
      repeat if hash_is_full then overflow("hash size",hash_size+hash_extra);
@:TeX capacity exceeded hash size}{\quad hash size@>
      decr(hash_used);
      until text(hash_used)=0; {search for an empty location in |hash|}
    next(p):=hash_used; p:=hash_used;
    end;
  end;
@z

@x
else if p>=undefined_control_sequence then print_esc("IMPOSSIBLE.")
@y
else if ((p>=undefined_control_sequence)and(p<=eqtb_size))or(p>eqtb_top) then
  print_esc("IMPOSSIBLE.")
@z

@x
else if (text(p)<0)or(text(p)>=str_ptr) then print_esc("NONEXISTENT.")
@y
else if (text(p)>=str_ptr) then print_esc("NONEXISTENT.")
@z

@x
@!save_stack : array[0..save_size] of memory_word;
@y
@!save_stack : ^memory_word;
@z

@x
if p<int_base then
@y
if (p<int_base)or(p>eqtb_size) then
@z

@x
if cs_token_flag+undefined_control_sequence>max_halfword then bad:=21;
@y
if cs_token_flag+eqtb_size+hash_extra>max_halfword then bad:=21;
if (hash_offset<0)or(hash_offset>hash_base) then bad:=42;
@z

@x
@!in_state_record = record
  @!state_field, @!index_field: quarterword;
  @!start_field,@!loc_field, @!limit_field, @!name_field: halfword;
  end;
@y
@!in_state_record = record
  @!state_field, @!index_field: quarterword;
  @!start_field,@!loc_field, @!limit_field, @!name_field: halfword;
  @!synctex_tag_field: integer; {stack the tag of the current file}
  end;
@z

@x
@!input_stack : array[0..stack_size] of in_state_record;
@y
@!input_stack : ^in_state_record;
@z

@x
@d name==cur_input.name_field {name of the current file}
@y
@d name==cur_input.name_field {name of the current file}
@d synctex_tag==cur_input.synctex_tag_field {{\sl Sync\TeX} tag of the current file}
@z

@x
@!input_file : array[1..max_in_open] of alpha_file;
@!line : integer; {current line number in the current source file}
@!line_stack : array[1..max_in_open] of integer;
@y
@!input_file : ^unicode_file;
@!line : integer; {current line number in the current source file}
@!line_stack : ^integer;
@!source_filename_stack : ^str_number;
@!full_source_filename_stack : ^str_number;
@z

@x
  begin print_nl("Runaway ");
@.Runaway...@>
  case scanner_status of
  defining: begin print("definition"); p:=def_ref;
    end;
  matching: begin print("argument"); p:=temp_head;
    end;
  aligning: begin print("preamble"); p:=hold_head;
    end;
  absorbing: begin print("text"); p:=def_ref;
    end;
  end; {there are no other cases}
@y
  begin
@.Runaway...@>
  case scanner_status of
  defining: begin print_nl("Runaway definition"); p:=def_ref;
    end;
  matching: begin print_nl("Runaway argument"); p:=temp_head;
    end;
  aligning: begin print_nl("Runaway preamble"); p:=hold_head;
    end;
  absorbing: begin print_nl("Runaway text"); p:=def_ref;
    end;
  end; {there are no other cases}
@z

@x
@!param_stack:array [0..param_size] of pointer;
  {token list pointers for parameters}
@y
@!param_stack: ^pointer;
  {token list pointers for parameters}
@z

@x
@p procedure begin_file_reading;
@y
@p procedure begin_file_reading;
@z

@x
incr(in_open); push_input; index:=in_open;
@y
incr(in_open); push_input; index:=in_open;
source_filename_stack[index]:=0;full_source_filename_stack[index]:=0;
@z

@x
name:=0; {|terminal_input| is now |true|}
@y
name:=0; {|terminal_input| is now |true|}
@<Prepare terminal input {\sl Sync\TeX} information@>;
@z

@x
begin input_ptr:=0; max_in_stack:=0;
@y
begin input_ptr:=0; max_in_stack:=0;
source_filename_stack[0]:=0;full_source_filename_stack[0]:=0;
@z

@x
print(" while scanning ");
@y
@z

@x
defining:begin print("definition"); info(p):=right_brace_token+"}";
  end;
matching:begin print("use"); info(p):=par_token; long_state:=outer_call;
  end;
aligning:begin print("preamble"); info(p):=right_brace_token+"}"; q:=p;
  p:=get_avail; link(p):=q; info(p):=cs_token_flag+frozen_cr;
  align_state:=-1000000;
  end;
absorbing:begin print("text"); info(p):=right_brace_token+"}";
@y
defining:begin print(" while scanning definition"); info(p):=right_brace_token+"}";
  end;
matching:begin print(" while scanning use"); info(p):=par_token; long_state:=outer_call;
  end;
aligning:begin print(" while scanning preamble"); info(p):=right_brace_token+"}"; q:=p;
  p:=get_avail; link(p):=q; info(p):=cs_token_flag+frozen_cr;
  align_state:=-1000000;
  end;
absorbing:begin print(" while scanning text"); info(p):=right_brace_token+"}";
@z

@x
The |expand| subroutine is used when |cur_cmd>max_command|. It removes a
@y
@ Sometimes, recursive calls to the following |expand| routine may
cause exhaustion of the run-time calling stack, resulting in
forced execution stops by the operating system. To diminish the chance
of this happening, a counter is used to keep track of the recursion
depth, in conjunction with a constant called |expand_depth|.

This does not catch all possible infinite recursion loops, just the ones
that exhaust the application calling stack. The actual maximum value of
|expand_depth| is outside of our control, but the initial setting of
|10000| should be enough to prevent problems.
@^system dependencies@>

@<Global...@>=
expand_depth_count:integer;

@ @<Set init...@>=
expand_depth_count:=0;

@ The |expand| subroutine is used when |cur_cmd>max_command|. It removes a
@z

@x
begin cv_backup:=cur_val; cvl_backup:=cur_val_level; radix_backup:=radix;
@y
begin
incr(expand_depth_count);
if expand_depth_count>=expand_depth then overflow("expansion depth",expand_depth);
cv_backup:=cur_val; cvl_backup:=cur_val_level; radix_backup:=radix;
@z

@x
cur_order:=co_backup; link(backup_head):=backup_backup;
@y
cur_order:=co_backup; link(backup_head):=backup_backup;
decr(expand_depth_count);
@z

@x
if_eof_code: begin scan_four_bit_int; b:=(read_open[cur_val]=closed);
  end;
@y
if_eof_code: begin scan_four_bit_int_or_18;
  if cur_val=18 then b:=not shellenabledp
  else b:=(read_open[cur_val]=closed);
  end;
@z

@x
@ The file names we shall deal with for illustrative purposes have the
following structure:  If the name contains `\.>' or `\.:', the file area
consists of all characters up to and including the final such character;
otherwise the file area is null.  If the remaining file name contains
`\..', the file extension consists of all such characters from the first
remaining `\..' to the end, otherwise the file extension is null.
@y
@ The file names we shall deal with have the
following structure:  If the name contains `\./' or `\.:'
(for Amiga only), the file area
consists of all characters up to and including the final such character;
otherwise the file area is null.  If the remaining file name contains
`\..', the file extension consists of all such characters from the last
`\..' to the end, otherwise the file extension is null.
@z

@x
@!area_delimiter:pool_pointer; {the most recent `\.>' or `\.:', if any}
@!ext_delimiter:pool_pointer; {the relevant `\..', if any}
@y
@!area_delimiter:pool_pointer; {the most recent `\./', if any}
@!ext_delimiter:pool_pointer; {the most recent `\..', if any}
@z

@x
@d TEX_area=="TeXinputs:"
@.TeXinputs@>
@d TEX_font_area=="TeXfonts:"
@.TeXfonts@>
@y
In C, the default paths are specified separately.
@z

@x
begin area_delimiter:=0; ext_delimiter:=0;
@y
begin area_delimiter:=0; ext_delimiter:=0; quoted_filename:=false;
@z

@x
begin if c=" " then more_name:=false
@y
begin if stop_at_space and (c=" ") and (file_name_quote_char=0) then
  more_name:=false
else if stop_at_space and (file_name_quote_char<>0) and (c=file_name_quote_char) then begin
  file_name_quote_char:=0;
  more_name:=true;
  end
else if stop_at_space and (file_name_quote_char=0) and ((c="""") or (c="'")) then begin
  file_name_quote_char:=c;
  quoted_filename:=true;
  more_name:=true;
  end
@z

@x
  if (c=">")or(c=":") then
@y
  if IS_DIR_SEP(c) then
@z

@x
  else if (c=".")and(ext_delimiter=0) then ext_delimiter:=cur_length;
@y
  else if c="." then ext_delimiter:=cur_length;
@z

@x
@ The third.
@^system dependencies@>

@p procedure end_name;
@y
@ The third.
@^system dependencies@>
If a string is already in the string pool, the function
|slow_make_string| does not create a new string but returns this string
number, thus saving string space.  Because of this new property of the
returned string number it is not possible to apply |flush_string| to
these strings.

@p procedure end_name;
var temp_str: str_number; {result of file name cache lookups}
@!j: pool_pointer; {running index}
@z

@x
@:TeX capacity exceeded number of strings}{\quad number of strings@>
@y
@:TeX capacity exceeded number of strings}{\quad number of strings@>
@z

@x
  end;
if ext_delimiter=0 then
  begin cur_ext:=""; cur_name:=make_string;
@y
  temp_str:=search_string(cur_area);
  if temp_str>0 then
    begin cur_area:=temp_str;
    decr(str_ptr);  {no |flush_string|, |pool_ptr| will be wrong!}
    for j:=str_start_macro(str_ptr+1) to pool_ptr-1 do
      begin str_pool[j-area_delimiter]:=str_pool[j];
      end;
    pool_ptr:=pool_ptr-area_delimiter; {update |pool_ptr|}
    end;
  end;
if ext_delimiter=0 then
  begin cur_ext:=""; cur_name:=slow_make_string;
@z

@x
  incr(str_ptr); cur_ext:=make_string;
@y
  incr(str_ptr); cur_ext:=make_string;
  decr(str_ptr); {undo extension string to look at name part}
  temp_str:=search_string(cur_name);
  if temp_str>0 then
    begin cur_name:=temp_str;
    decr(str_ptr);  {no |flush_string|, |pool_ptr| will be wrong!}
    for j:=str_start_macro(str_ptr+1) to pool_ptr-1 do
      begin str_pool[j-ext_delimiter+area_delimiter+1]:=str_pool[j];
      end;
    pool_ptr:=pool_ptr-ext_delimiter+area_delimiter+1;  {update |pool_ptr|}
    end;
  cur_ext:=slow_make_string;  {remake extension string}
@z

@x
some operating systems put the file area last instead of first.)
@^system dependencies@>
@y
some operating systems put the file area last instead of first.)
@^system dependencies@>

@d check_quoted(#) == {check if string |#| needs quoting}
if #<>0 then begin
  j:=str_start_macro(#);
  while ((not must_quote) or (quote_char=0)) and (j<str_start_macro(#+1)) do begin
    if str_pool[j]=" " then must_quote:=true
    else if (str_pool[j]="""") or (str_pool[j]="'") then begin
      must_quote:=true;
      quote_char:="""" + "'" - str_pool[j];
    end;
    incr(j);
  end;
end
@#
@d print_quoted(#) == {print string |#|, omitting quotes}
if #<>0 then
  for j:=str_start_macro(#) to str_start_macro(#+1)-1 do begin
    if str_pool[j]=quote_char then begin
      print(quote_char);
      quote_char:="""" + "'" - quote_char;
      print(quote_char);
    end;
    print(str_pool[j]);
  end
@z

@x
begin slow_print(a); slow_print(n); slow_print(e);
@y
var must_quote: boolean; {whether to quote the filename}
@!quote_char: integer; {current quote char (single or double)}
@!j:pool_pointer; {index into |str_pool|}
begin
must_quote:=false;
quote_char:=0;
check_quoted(a); check_quoted(n); check_quoted(e);
if must_quote then begin
  if quote_char=0 then quote_char:="""";
  print_char(quote_char);
end;
print_quoted(a); print_quoted(n); print_quoted(e);
if quote_char<>0 then print_char(quote_char);
@z

@x
@d append_to_name(#)==begin c:=#; incr(k);
  if k<=file_name_size then name_of_file[k]:=xchr[c];
  end
@y
@d append_to_name(#)==begin c:=#; incr(k);
  if k<=file_name_size then begin
      if (c < 128) then name_of_file[k]:=c
      else if (c < @"800) then begin
        name_of_file[k]:=@"C0 + c div @"40; incr(k);
        name_of_file[k]:=@"80 + c mod @"40;
      end else begin
		name_of_file[k]:=@"E0 + c div @"1000; incr(k);
		name_of_file[k]:=@"80 + (c mod @"1000) div @"40; incr(k);
		name_of_file[k]:=@"80 + (c mod @"1000) mod @"40;
      end
    end
  end
@z

@x
begin k:=0;
@y
begin k:=0;
if name_of_file then libc_free (name_of_file);
name_of_file:= xmalloc_array (UTF8_code, (length(a)+length(n)+length(e))*3+1);
@z

@x
for k:=name_length+1 to file_name_size do name_of_file[k]:=' ';
@y
name_of_file[name_length+1]:=0;
@z

@x
@d format_default_length=20 {length of the |TEX_format_default| string}
@d format_area_length=11 {length of its area part}
@d format_ext_length=4 {length of its `\.{.fmt}' part}
@y
Under {\mc UNIX} we don't give the area part, instead depending
on the path searching that will happen during file opening.  Also, the
length will be set in the main program.

@d format_area_length=0 {length of its area part}
@d format_ext_length=4 {length of its `\.{.fmt}' part}
@z

@x
@!TEX_format_default:packed array[1..format_default_length] of char;

@ @<Set init...@>=
TEX_format_default:='TeXformats:plain.fmt';
@y
@!format_default_length: integer;
@!TEX_format_default: cstring;

@ We set the name of the default format file and the length of that name
in C, instead of Pascal, since we want them to depend on the name of the
program.
@z

@x
for j:=1 to n do append_to_name(xord[TEX_format_default[j]]);
for j:=a to b do append_to_name(buffer[j]);
for j:=format_default_length-format_ext_length+1 to format_default_length do
  append_to_name(xord[TEX_format_default[j]]);
if k<=file_name_size then name_length:=k@+else name_length:=file_name_size;
for k:=name_length+1 to file_name_size do name_of_file[k]:=' ';
@y
if name_of_file then libc_free (name_of_file);
name_of_file := xmalloc_array (UTF8_code, n+(b-a+1)+format_ext_length+1);
for j:=1 to n do append_to_name(TEX_format_default[j]);
for j:=a to b do append_to_name(buffer[j]);
for j:=format_default_length-format_ext_length+1 to format_default_length do
  append_to_name(TEX_format_default[j]);
if k<=file_name_size then name_length:=k@+else name_length:=file_name_size;
name_of_file[name_length+1]:=0;
@z

@x
  pack_buffered_name(0,loc,j-1); {try first without the system file area}
  if w_open_in(fmt_file) then goto found;
  pack_buffered_name(format_area_length,loc,j-1);
    {now try the system format file area}
  if w_open_in(fmt_file) then goto found;
@y
  pack_buffered_name(0,loc,j-1); {Kpathsea does everything}
  if w_open_in(fmt_file) then goto found;
@z

@x
  wterm_ln('Sorry, I can''t find that format;',' will try PLAIN.');
@y
  wterm ('Sorry, I can''t find the format `');
  fputs (stringcast(name_of_file + 1), stdout);
  wterm ('''; will try `');
  fputs (TEX_format_default + 1, stdout);
  wterm_ln ('''.');
@z

@x
  wterm_ln('I can''t find the PLAIN format file!');
@.I can't find PLAIN...@>
@y
  wterm ('I can''t find the format file `');
  fputs (TEX_format_default + 1, stdout);
  wterm_ln ('''!');
@.I can't find the format...@>
@z

@x
begin if (pool_ptr+name_length>pool_size)or(str_ptr=max_strings)or
@y
save_area_delimiter, save_ext_delimiter: pool_pointer;
save_name_in_progress, save_stop_at_space: boolean;
begin if (pool_ptr+name_length>pool_size)or(str_ptr=max_strings)or
@z

@x
  make_name_string:=make_string;
@y
  make_name_string:=make_string;
  {At this point we also set |cur_name|, |cur_ext|, and |cur_area| to
   match the contents of |name_of_file|.}
  save_area_delimiter:=area_delimiter; save_ext_delimiter:=ext_delimiter;
  save_name_in_progress:=name_in_progress; save_stop_at_space:=stop_at_space;
  name_in_progress:=true;
  begin_name;
  stop_at_space:=false;
  k:=0;
  while (k<name_length16)and(more_name(name_of_file16[k])) do
    incr(k);
  stop_at_space:=save_stop_at_space;
  end_name;
  name_in_progress:=save_name_in_progress;
  area_delimiter:=save_area_delimiter; ext_delimiter:=save_ext_delimiter;
@z

@x
  if not more_name(cur_chr) then goto done;
@y
  if not more_name(cur_chr) then goto done;
@z

@x
var k:0..buf_size; {index into |buffer|}
@y
var k:0..buf_size; {index into |buffer|}
@!saved_cur_name:str_number; {to catch empty terminal input}
@!saved_cur_ext:str_number; {to catch empty terminal input}
@!saved_cur_area:str_number; {to catch empty terminal input}
@z

@x
if e=".tex" then show_context;
@y
if (e=".tex") or (e="") then show_context;
print_ln; print_c_string(prompt_file_name_help_msg);
if (e<>"") then
  begin
    print("; default file extension is `"); print(e); print("'");
  end;
print(")"); print_ln;
@z

@x
clear_terminal; prompt_input(": "); @<Scan file name in the buffer@>;
if cur_ext="" then cur_ext:=e;
@y
saved_cur_name:=cur_name;
saved_cur_ext:=cur_ext;
saved_cur_area:=cur_area;
clear_terminal; prompt_input(": "); @<Scan file name in the buffer@>;
if (length(cur_name)=0) and (cur_ext="") and (cur_area="") then
  begin
    cur_name:=saved_cur_name;
    cur_ext:=saved_cur_ext;
    cur_area:=saved_cur_area;
  end
else
  if cur_ext="" then cur_ext:=e;
@z

@x
@d ensure_dvi_open==if output_file_name=0 then
@y
@d log_name == texmf_log_name
@d ensure_dvi_open==if output_file_name=0 then
@z

@x
@!months:packed array [1..36] of char; {abbreviations of month names}
@y
@!months:const_cstring;
@z

@x
if job_name=0 then job_name:="texput";
@.texput@>
@y
if job_name=0 then job_name:=get_job_name("texput");
@.texput@>
pack_job_name(".fls");
recorder_change_filename(stringcast(name_of_file+1));
@z

@x
@<Print the banner line, including the date and time@>;
@y
@<Print the banner line, including the date and time@>;
if mltex_enabled_p then
  begin wlog_cr; wlog('MLTeX v2.2 enabled');
  end;
@z

@x
begin wlog(banner);
@y
begin
if src_specials_p or file_line_error_style_p or parse_first_line_p
then
  wlog(banner_k)
else
  wlog(banner);
@z

@x
slow_print(format_ident); print("  ");
@y
wlog(version_string);
slow_print(format_ident); print("  ");
@z

@x
months:='JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC';
@y
months := ' JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC';
@z

@x
end
@y
if shellenabledp then begin
  wlog_cr;
  wlog(' ');
  if restrictedshell then begin
    wlog('restricted ');
  end;
  wlog('\write18 enabled.')
  end;
if src_specials_p then begin
  wlog_cr;
  wlog(' Source specials enabled.')
  end;
if file_line_error_style_p then begin
  wlog_cr;
  wlog(' file:line:error style messages enabled.')
  end;
if parse_first_line_p then begin
  wlog_cr;
  wlog(' %&-line parsing enabled.');
  end;
if translate_filename then begin
  wlog_cr;
  wlog(' (WARNING: translate-file "');
  fputs(translate_filename, log_file);
  wlog('" ignored)');
  end;
end
@z

@x
@p procedure start_input; {\TeX\ will \.{\\input} something}
@y
@p procedure start_input; {\TeX\ will \.{\\input} something}
@z

@x
begin scan_file_name; {set |cur_name| to desired file name}
if cur_ext="" then cur_ext:=".tex";
pack_cur_name;
loop@+  begin begin_file_reading; {set up |cur_file| and new level of input}
  if a_open_in(cur_file) then goto done;
  if cur_area="" then
    begin pack_file_name(cur_name,TEX_area,cur_ext);
    if a_open_in(cur_file) then goto done;
    end;
@y
var temp_str: str_number;
@!k:0..file_name_size; {index into |name_of_file16|}
begin scan_file_name; {set |cur_name| to desired file name}
pack_cur_name;
loop@+begin
  begin_file_reading; {set up |cur_file| and new level of input}
  tex_input_type := 1; {Tell |open_input| we are \.{\\input}.}
  {Kpathsea tries all the various ways to get the file.}
  if kpse_in_name_ok(stringcast(name_of_file+1))
     and u_open_in(cur_file, kpse_tex_format, XeTeX_default_input_mode, XeTeX_default_input_encoding) then
    {At this point |name_of_file| contains the actual name found, as a UTF8 string.
     We convert to UTF16, then extract the |cur_area|, |cur_name|, and |cur_ext| from it.}
    begin
    make_utf16_name;
    name_in_progress:=true;
    begin_name;
    stop_at_space:=false;
    k:=0;
    while (k<name_length16)and(more_name(name_of_file16[k])) do
      incr(k);
    stop_at_space:=true;
    end_name;
    name_in_progress:=false;
    goto done;
    end;
@z

@x
  prompt_file_name("input file name",".tex");
@y
  prompt_file_name("input file name","");
@z

@x
done: name:=a_make_name_string(cur_file);
@y
done: name:=a_make_name_string(cur_file);
source_filename_stack[in_open]:=name;
full_source_filename_stack[in_open]:=make_full_name_string;
if name=str_ptr-1 then {we can try to conserve string pool space now}
  begin temp_str:=search_string(name);
  if temp_str>0 then
    begin name:=temp_str; flush_string;
    end;
  end;
@z

@x
  begin job_name:=cur_name; open_log_file;
@y
  begin job_name:=get_job_name(cur_name); open_log_file;
@z

@x
if term_offset+length(name)>max_print_line-2 then print_ln
else if (term_offset>0)or(file_offset>0) then print_char(" ");
print_char("("); incr(open_parens); slow_print(name); update_terminal;
@y
if term_offset+length(full_source_filename_stack[in_open])>max_print_line-2
then print_ln
else if (term_offset>0)or(file_offset>0) then print_char(" ");
print_char("("); incr(open_parens);
slow_print(full_source_filename_stack[in_open]); update_terminal;
@z

@x
if name=str_ptr-1 then {we can conserve string pool space now}
  begin flush_string; name:=cur_name;
  end;
@<Read the first line of the new file@>;
@y
@<Prepare new file {\sl Sync\TeX} information@>;
@<Read the first line of the new file@>;
@z

@x
@!internal_font_number=font_base..font_max; {|font| in a |char_node|}
@!font_index=0..font_mem_size; {index into |font_info|}
@y
@!internal_font_number=integer; {|font| in a |char_node|}
@!font_index=integer; {index into |font_info|}
@!nine_bits=min_quarterword..non_char;
@z

@x
@!font_info:array[font_index] of memory_word;
  {the big collection of font data}
@!fmem_ptr:font_index; {first unused word of |font_info|}
@!font_ptr:internal_font_number; {largest internal font number in use}
@!font_check:array[internal_font_number] of four_quarters; {check sum}
@!font_size:array[internal_font_number] of scaled; {``at'' size}
@!font_dsize:array[internal_font_number] of scaled; {``design'' size}
@!font_params:array[internal_font_number] of font_index; {how many font
  parameters are present}
@!font_name:array[internal_font_number] of str_number; {name of the font}
@!font_area:array[internal_font_number] of str_number; {area of the font}
@!font_bc:array[internal_font_number] of eight_bits;
  {beginning (smallest) character code}
@!font_ec:array[internal_font_number] of eight_bits;
  {ending (largest) character code}
@!font_glue:array[internal_font_number] of pointer;
  {glue specification for interword space, |null| if not allocated}
@!font_used:array[internal_font_number] of boolean;
  {has a character from this font actually appeared in the output?}
@!hyphen_char:array[internal_font_number] of integer;
  {current \.{\\hyphenchar} values}
@!skew_char:array[internal_font_number] of integer;
  {current \.{\\skewchar} values}
@!bchar_label:array[internal_font_number] of font_index;
  {start of |lig_kern| program for left boundary character,
  |non_address| if there is none}
@!font_bchar:array[internal_font_number] of min_quarterword..non_char;
  {right boundary character, |non_char| if there is none}
@!font_false_bchar:array[internal_font_number] of min_quarterword..non_char;
  {|font_bchar| if it doesn't exist in the font, otherwise |non_char|}
@y
@!font_info: ^fmemory_word;
  {the big collection of font data}
@!fmem_ptr:font_index; {first unused word of |font_info|}
@!font_ptr:internal_font_number; {largest internal font number in use}
@!font_check: ^four_quarters; {check sum}
@!font_size: ^scaled; {``at'' size}
@!font_dsize: ^scaled; {``design'' size}
@!font_params: ^font_index; {how many font
  parameters are present}
@!font_name: ^str_number; {name of the font}
@!font_area: ^str_number; {area of the font}
@!font_bc: ^UTF16_code;
  {beginning (smallest) character code}
@!font_ec: ^UTF16_code;
  {ending (largest) character code}
@!font_glue: ^pointer;
  {glue specification for interword space, |null| if not allocated}
@!font_used: ^boolean;
  {has a character from this font actually appeared in the output?}
@!hyphen_char: ^integer;
  {current \.{\\hyphenchar} values}
@!skew_char: ^integer;
  {current \.{\\skewchar} values}
@!bchar_label: ^font_index;
  {start of |lig_kern| program for left boundary character,
  |non_address| if there is none}
@!font_bchar: ^nine_bits;
  {right boundary character, |non_char| if there is none}
@!font_false_bchar: ^nine_bits;
  {|font_bchar| if it doesn't exist in the font, otherwise |non_char|}
@#
@!font_layout_engine: ^void_pointer; {either an CFDictionaryRef or a XeTeXLayoutEngine}
@!font_mapping: ^void_pointer; { |TECkit_Converter| or 0 }
@!font_flags: ^char; { flags:
  0x01: |font_colored|
  0x02: |font_vertical| }
@!font_letter_space: ^scaled; { letterspacing to be applied to the font }
@!loaded_font_mapping: void_pointer; { used by |load_native_font| to return mapping, if any }
@!loaded_font_flags: char; { used by |load_native_font| to return flags }
@!loaded_font_letter_space: scaled;
@!loaded_font_design_size: scaled;
@!mapped_text: ^UTF16_code; { scratch buffer used while applying font mappings }
@!xdv_buffer: ^char; { scratch buffer used in generating XDV output }
@z

@x
@!char_base:array[internal_font_number] of integer;
  {base addresses for |char_info|}
@!width_base:array[internal_font_number] of integer;
  {base addresses for widths}
@!height_base:array[internal_font_number] of integer;
  {base addresses for heights}
@!depth_base:array[internal_font_number] of integer;
  {base addresses for depths}
@!italic_base:array[internal_font_number] of integer;
  {base addresses for italic corrections}
@!lig_kern_base:array[internal_font_number] of integer;
  {base addresses for ligature/kerning programs}
@!kern_base:array[internal_font_number] of integer;
  {base addresses for kerns}
@!exten_base:array[internal_font_number] of integer;
  {base addresses for extensible recipes}
@!param_base:array[internal_font_number] of integer;
  {base addresses for font parameters}
@y
@!char_base: ^integer;
  {base addresses for |char_info|}
@!width_base: ^integer;
  {base addresses for widths}
@!height_base: ^integer;
  {base addresses for heights}
@!depth_base: ^integer;
  {base addresses for depths}
@!italic_base: ^integer;
  {base addresses for italic corrections}
@!lig_kern_base: ^integer;
  {base addresses for ligature/kerning programs}
@!kern_base: ^integer;
  {base addresses for kerns}
@!exten_base: ^integer;
  {base addresses for extensible recipes}
@!param_base: ^integer;
  {base addresses for font parameters}
@z

@x
for k:=font_base to font_max do font_used[k]:=false;
@y
@z

@x
font_ptr:=null_font; fmem_ptr:=7;
font_name[null_font]:="nullfont"; font_area[null_font]:="";
hyphen_char[null_font]:="-"; skew_char[null_font]:=-1;
bchar_label[null_font]:=non_address;
font_bchar[null_font]:=non_char; font_false_bchar[null_font]:=non_char;
font_bc[null_font]:=1; font_ec[null_font]:=0;
font_size[null_font]:=0; font_dsize[null_font]:=0;
char_base[null_font]:=0; width_base[null_font]:=0;
height_base[null_font]:=0; depth_base[null_font]:=0;
italic_base[null_font]:=0; lig_kern_base[null_font]:=0;
kern_base[null_font]:=0; exten_base[null_font]:=0;
font_glue[null_font]:=null; font_params[null_font]:=7;
param_base[null_font]:=-1;
for k:=0 to 6 do font_info[k].sc:=0;
@y
@z

@x
as fast as possible under the circumstances.
@^inner loop@>

@d char_info_end(#)==#].qqqq
@d char_info(#)==font_info[char_base[#]+char_info_end
@y
as fast as possible under the circumstances.
@^inner loop@>

ML\TeX{} will assume that a character |c| exists iff either exists in
the current font or a character substitution definition for this
character was defined using \.{\\charsubdef}.  To avoid the
distinction between these two cases, ML\TeX{} introduces the notion
``effective character'' of an input character |c|.  If |c| exists in
the current font, the effective character of |c| is the character |c|
itself.  If it doesn't exist but a character substitution is defined,
the effective character of |c| is the base character defined in the
character substitution.  If there is an effective character for a
non-existing character |c|, the ``virtual character'' |c| will get
appended to the horizontal lists.

The effective character is used within |char_info| to access
appropriate character descriptions in the font.  For example, when
calculating the width of a box, ML\TeX{} will use the metrics of the
effective characters.  For the case of a substitution, ML\TeX{} uses
the metrics of the base character, ignoring the metrics of the accent
character.

If character substitutions are changed, it will be possible that a
character |c| neither exists in a font nor there is a valid character
substitution for |c|.  To handle these cases |effective_char| should
be called with its first argument set to |true| to ensure that it
will still return an existing character in the font.  If neither |c|
nor the substituted base character in the current character
substitution exists, |effective_char| will output a warning and
return the character |font_bc[f]| (which is incorrect, but can not be
changed within the current framework).

Sometimes character substitutions are unwanted, therefore the
original definition of |char_info| can be used using the macro
|orig_char_info|.  Operations in which character substitutions should
be avoided are, for example, loading a new font and checking the font
metric information in this font, and character accesses in math mode.

@d char_list_exists(#)==(char_sub_code(#)>hi(0))
@d char_list_accent(#)==(ho(char_sub_code(#)) div 256)
@d char_list_char(#)==(ho(char_sub_code(#)) mod 256)
@#
@d char_info_end(#)== #@=)@>].qqqq
@d char_info(#)==
  font_info[char_base[#]+effective_char@=(@>true,#,char_info_end
@#
@d orig_char_info_end(#)==#].qqqq
@d orig_char_info(#)==font_info[char_base[#]+orig_char_info_end
@#
@z

@x
@p function read_font_info(@!u:pointer;@!nom,@!aire:str_number;
@y
@p @t\4@>@<Declare additional functions for ML\TeX@>@/

function read_font_info(@!u:pointer;@!nom,@!aire:str_number;
@z

@x
@!file_opened:boolean; {was |tfm_file| successfully opened?}
@y
@!name_too_long:boolean; {|nom| or |aire| exceeds 255 bytes?}
@!file_opened:boolean; {was |tfm_file| successfully opened?}
@z

@x
else print(" not loadable: Metric (TFM) file not found");
@y
else if name_too_long then print(" not loadable: Metric (TFM) file name too long")
else print(" not loadable: Metric (TFM) file or installed font not found");
@z

@x
if aire="" then pack_file_name(nom,TEX_font_area,".tfm")
else pack_file_name(nom,aire,".tfm");
@y
name_too_long:=(length(nom)>255)or(length(aire)>255);
if name_too_long then abort;
{|kpse_find_file| will append the |".tfm"|, and avoid searching the disk
 before the font alias files as well.}
pack_file_name(nom,aire,"");
@z

@x
@d fget==get(tfm_file)
@d fbyte==tfm_file^
@y
@d fget==tfm_temp:=getc(tfm_file)
@d fbyte==tfm_temp
@z

@x
  begin qw:=char_info(f)(d);
@y
  begin qw:=orig_char_info(f)(d);
@z

@x
  qw:=char_info(f)(#); {N.B.: not |qi(#)|}
@y
  qw:=orig_char_info(f)(#); {N.B.: not |qi(#)|}
@z

@x
if eof(tfm_file) then abort;
@y
if feof(tfm_file) then abort;
@z

@x
  begin qw:=char_info(f)(bchar); {N.B.: not |qi(bchar)|}
@y
  begin qw:=orig_char_info(f)(bchar); {N.B.: not |qi(bchar)|}
@z

@x
@ We need a few subroutines for |new_character|.

@p @t\4@>@<Declare subroutines for |new_character|@>@;
@y
@ The subroutines for |new_character| have been moved.
@z

@x
@p function new_character(@!f:internal_font_number;@!c:eight_bits):pointer;
label exit;
var p:pointer; {newly allocated node}
begin if font_bc[f]<=c then if font_ec[f]>=c then
  if char_exists(char_info(f)(qi(c))) then
@y

This allows a character node to be used if there is an equivalent
in the |char_sub_code| list.

@p function new_character(@!f:internal_font_number;@!c:ASCII_code):pointer;
label exit;
var p:pointer; {newly allocated node}
@!ec:quarterword;  {effective character of |c|}
begin
if is_native_font(f) then
  begin new_character:=new_native_character(f,c); return;
  end;
ec:=effective_char(false,f,qi(c));
if font_bc[f]<=qo(ec) then if font_ec[f]>=qo(ec) then
  if char_exists(orig_char_info(f)(ec)) then  {N.B.: not |char_info|}
@z

@x
@!c,@!f:quarterword; {character and font in current |char_node|}
@y
 {character and font in current |char_node|}
@!c:quarterword;
@!f:internal_font_number;
@z

@x
@!dvi_buf:array[dvi_index] of eight_bits; {buffer for \.{DVI} output}
@!half_buf:dvi_index; {half of |dvi_buf_size|}
@!dvi_limit:dvi_index; {end of the current half buffer}
@!dvi_ptr:dvi_index; {the next available buffer address}
@y
@!dvi_buf:^eight_bits; {buffer for \.{DVI} output}
@!half_buf:integer; {half of |dvi_buf_size|}
@!dvi_limit:integer; {end of the current half buffer}
@!dvi_ptr:integer; {the next available buffer address}
@z

@x
@p procedure write_dvi(@!a,@!b:dvi_index);
var k:dvi_index;
begin for k:=a to b do write(dvi_file,dvi_buf[k]);
end;
@y
In C, we use a macro to call |fwrite| or |write| directly, writing all
the bytes in one shot.  Much better even than writing four
bytes at a time.
@z

@x
each time, we use the macro |dvi_out|.
@y
each time, we use the macro |dvi_out|.

The length of |dvi_file| should not exceed |@"7FFFFFFF|; we set |cur_s:=-2|
to prevent further \.{DVI} output causing infinite recursion.
@z

@x
begin if dvi_limit=dvi_buf_size then
@y
begin if dvi_ptr>(@"7FFFFFFF-dvi_offset) then
  begin cur_s:=-2;
  fatal_error("dvi length exceeds ""7FFFFFFF");
@.dvi length exceeds...@>
  end;
if dvi_limit=dvi_buf_size then
@z

@x
if dvi_ptr>0 then write_dvi(0,dvi_ptr-1)
@y
if dvi_ptr>(@"7FFFFFFF-dvi_offset) then
  begin cur_s:=-2;
  fatal_error("dvi length exceeds ""7FFFFFFF");
@.dvi length exceeds...@>
  end;
if dvi_ptr>0 then write_dvi(0,dvi_ptr-1)
@z

@x
begin dvi_out(fnt_def1);
dvi_out(f-font_base-1);@/
@y
begin if f<=256+font_base then
  begin dvi_out(fnt_def1);
  dvi_out(f-font_base-1);
  end
else begin dvi_out(fnt_def1+1);
  dvi_out((f-font_base-1) div @'400);
  dvi_out((f-font_base-1) mod @'400);
  end;
@z

@x
  old_setting:=selector; selector:=new_string;
@y
if output_comment then
  begin l:=strlen(output_comment); dvi_out(l);
  for s:=0 to l-1 do dvi_out(output_comment[s]);
  end
else begin {the default code is unchanged}
  old_setting:=selector; selector:=new_string;
@z

@x
  end
@y
end;
  end
@z

@x
procedure hlist_out; {output an |hlist_node| box}
label reswitch, move_past, fin_rule, next_p;
@y
procedure hlist_out; {output an |hlist_node| box}
label reswitch, move_past, fin_rule, next_p, continue, found, check_next, end_node_run;
@z

@x
while p<>null do @<Output node |p| for |hlist_out| and move to the next node,
  maintaining the condition |cur_v=base_line|@>;
@y
@<Start hlist {\sl Sync\TeX} information record@>;
while p<>null do @<Output node |p| for |hlist_out| and move to the next node,
  maintaining the condition |cur_v=base_line|@>;
@<Finish hlist {\sl Sync\TeX} information record@>;
@z

@x
reaching a non-|char_node|. The program uses the fact that |set_char_0=0|.
@^inner loop@>
@y
reaching a non-|char_node|. The program uses the fact that |set_char_0=0|.

In ML\TeX{} this part looks for the existence of a substitution
definition for a character |c|, if |c| does not exist in the font,
and create appropriate \.{DVI} commands.  Former versions of ML\TeX{}
have spliced appropriate character, kern, and box nodes into the
horizontal list.
%
% 91/05/08 \charsubdefmax bug detected by Bernd Raichle
Because the user can change character substitions or
\.{\\charsubdefmax} on the fly, we have to test a again
for valid substitutions.
%
% 93/10/29 \leaders bug detected by Eberhard Mattes
(Additional it is necessary to be careful---if leaders are used
the current hlist is normally traversed more than once!)
@^inner loop@>
@z

@x
@<Output node |p| for |hlist_out|...@>=
@y
@<Output node |p| for |hlist_out|...@>=
@z

@x
  if c>=qi(128) then dvi_out(set1);
  dvi_out(qo(c));@/
  cur_h:=cur_h+char_width(f)(char_info(f)(c));
@y
  if font_ec[f]>=qo(c) then if font_bc[f]<=qo(c) then
    if char_exists(orig_char_info(f)(c)) then  {N.B.: not |char_info|}
      begin if c>=qi(128) then dvi_out(set1);
      dvi_out(qo(c));@/
      cur_h:=cur_h+char_width(f)(orig_char_info(f)(c));
      goto continue;
      end;
  if mltex_enabled_p then
    @<Output a substitution, |goto continue| if not possible@>;
continue:
@z

@x
  until not is_char_node(p);
@y
  until not is_char_node(p);
  @<Record current point {\sl Sync\TeX} information@>;
@z

@x
else  begin dvi_out(fnt1); dvi_out(f-font_base-1);
  end;
@y
else if f<=256+font_base then
  begin dvi_out(fnt1); dvi_out(f-font_base-1);
  end
else begin dvi_out(fnt1+1);
  dvi_out((f-font_base-1) div @'400);
  dvi_out((f-font_base-1) mod @'400);
  end;
@z

@x
@ @<Output the non-|char_node| |p| for |hlist_out|...@>=
@y
@ @<Output the non-|char_node| |p| for |hlist_out|...@>=
@z

@x
kern_node:cur_h:=cur_h+width(p);
math_node: @<Handle a math node in |hlist_out|@>;
@y
kern_node: begin
  @<Record |kern_node| {\sl Sync\TeX} information@>;
  cur_h:=cur_h+width(p);
end;
math_node: begin
  @<Record |math_node| {\sl Sync\TeX} information@>;
  @<Handle a math node in |hlist_out|@>;
end;
@z

@x
move_past: cur_h:=cur_h+rule_wd;
@y
move_past: begin
  cur_h:=cur_h+rule_wd;
  @<Record horizontal |rule_node| or |glue_node| {\sl Sync\TeX} information@>;
end;
@z

@x
@ @<Output a box in an hlist@>=
if list_ptr(p)=null then cur_h:=cur_h+width(p)
@y
@ @<Output a box in an hlist@>=
if list_ptr(p)=null then begin
  @<Record void list {\sl Sync\TeX} information@>;
  cur_h:=cur_h+width(p);
end
@z

@x
@p procedure vlist_out; {output a |vlist_node| box}
@y
@p procedure vlist_out; {output a |vlist_node| box}
@z

@x
if upwards then cur_v:=cur_v+depth(this_box) else cur_v:=cur_v-height(this_box);
top_edge:=cur_v;
@y
@<Start vlist {\sl Sync\TeX} information record@>;
if upwards then cur_v:=cur_v+depth(this_box) else cur_v:=cur_v-height(this_box);
top_edge:=cur_v;
@z

@x
while p<>null do @<Output node |p| for |vlist_out| and move to the next node,
  maintaining the condition |cur_h=left_edge|@>;
@y
while p<>null do @<Output node |p| for |vlist_out| and move to the next node,
  maintaining the condition |cur_h=left_edge|@>;
@<Finish vlist {\sl Sync\TeX} information record@>;
@z

@x
@<Output a box in a vlist@>=
if list_ptr(p)=null then cur_v:=cur_v+height(p)+depth(p)
@y
@<Output a box in a vlist@>=
if list_ptr(p)=null then begin
  if upwards then cur_v:=cur_v-depth(p) else cur_v:=cur_v+height(p);
  @<Record void list {\sl Sync\TeX} information@>;
  if upwards then cur_v:=cur_v-height(p) else cur_v:=cur_v+depth(p);
end
@z

@x
@!old_setting:0..max_selector; {saved |selector| setting}
@y
@!old_setting:0..max_selector; {saved |selector| setting}
begin @<Start sheet {\sl Sync\TeX} information record@>;
@z

@x
@<Flush the box from memory, showing statistics if requested@>;
end;
@y
@<Flush the box from memory, showing statistics if requested@>;
end;
@<Finish sheet {\sl Sync\TeX} information record@>;
end;
@z

@x
done:
@y
ifdef ('IPC')
if ipc_on>0 then
  begin if dvi_limit=half_buf then
    begin write_dvi(half_buf, dvi_buf_size-1);
    flush_dvi;
    dvi_gone:=dvi_gone+half_buf;
    end;
  if dvi_ptr>(@"7FFFFFFF-dvi_offset) then
    begin cur_s:=-2;
    fatal_error("dvi length exceeds ""7FFFFFFF");
@.dvi length exceeds...@>
    end;
  if dvi_ptr>0 then
    begin write_dvi(0, dvi_ptr-1);
    flush_dvi;
    dvi_offset:=dvi_offset+dvi_ptr; dvi_gone:=dvi_gone+dvi_ptr;
    end;
  dvi_ptr:=0; dvi_limit:=dvi_buf_size;
  ipc_page(dvi_gone);
  end;
endif ('IPC');
done:
@z

@x
else  begin dvi_out(post); {beginning of the postamble}
@y
else if cur_s<>-2 then
  begin dvi_out(post); {beginning of the postamble}
@z

@x
  k:=4+((dvi_buf_size-dvi_ptr) mod 4); {the number of 223's}
@y
ifdef ('IPC')
  k:=7-((3+dvi_offset+dvi_ptr) mod 4); {the number of 223's}
endif ('IPC')
ifndef ('IPC')
  k:=4+((dvi_buf_size-dvi_ptr) mod 4); {the number of 223's}
endifn ('IPC')
@z

@x
  print_nl("Output written on "); slow_print(output_file_name);
@.Output written on x@>
  print(" ("); print_int(total_pages); print(" page");
  if total_pages<>1 then print_char("s");
  print(", "); print_int(dvi_offset+dvi_ptr); print(" bytes).");
  b_close(dvi_file);
@y
  k:=dvi_close(dvi_file);
  if k=0 then begin
    print_nl("Output written on "); print(output_file_name);
@.Output written on x@>
    print(" ("); print_int(total_pages);
    if total_pages<>1 then print(" pages")
    else print(" page");
    if no_pdf_output then begin
      print(", "); print_int(dvi_offset+dvi_ptr); print(" bytes).");
    end else print(").");
  end else begin
    print_nl("Error "); print_int(k); print(" (");
    if no_pdf_output then print_c_string(strerror(k))
    else print("driver return code");
    print(") generating output;");
    print_nl("file "); print(output_file_name); print(" may not be valid.");
    end;
@z

@x
if (qo(y)>=font_bc[g])and(qo(y)<=font_ec[g]) then
  begin continue: q:=char_info(g)(y);
@y
if (qo(y)>=font_bc[g])and(qo(y)<=font_ec[g]) then
  begin continue: q:=orig_char_info(g)(y);
@z

@x
@<Simplify a trivial box@>=
@y
@<Simplify a trivial box@>=
@z

@x
    begin free_node(r,small_node_size); link(q):=null;
@y
    begin free_node(r,medium_node_size); link(q):=null;
@z

@x
    cur_i:=char_info(cur_f)(cur_c)
@y
    cur_i:=orig_char_info(cur_f)(cur_c)
@z

@x
  i:=char_info(f)(y);
@y
  i:=orig_char_info(f)(y);
@z

@x
      begin c:=rem_byte(cur_i); i:=char_info(cur_f)(c);
@y
    begin c:=rem_byte(cur_i); i:=orig_char_info(cur_f)(c);
@z

@x
@<Append a ligature and/or kern to the translation...@>=
@y
@<Append a ligature and/or kern to the translation...@>=
@z

@x
if w<>0 then
  begin link(t):=new_kern(w); t:=link(t); w:=0;
@y
if w<>0 then
  begin link(t):=new_kern(w); t:=link(t); w:=0;
    sync_tag(t+medium_node_size):=0; {{\sl Sync\TeX}: do nothing, it is too late}
@z

@x
Comparatively few different number sequences $n_0\ldots n_k$ actually occur,
since most of the |n|'s are generally zero. Therefore the number sequences
are encoded in such a way that |trie_op|$(z_k)$ is only one byte long.
If |trie_op(@t$z_k$@>)<>min_quarterword|, when $p_1\ldots p_k$ has matched
the letters in |hc[(l-k+1)..l@,]| of language |t|,
we perform all of the required operations
for this pattern by carrying out the following little program: Set
|v:=trie_op(@t$z_k$@>)|. Then set |v:=v+op_start[t]|,
|hyf[l-hyf_distance[v]]:=@tmax@>(hyf[l-hyf_distance[v]], hyf_num[v])|,
and |v:=hyf_next[v]|; repeat, if necessary, until |v=min_quarterword|.
@y
The theory that comparatively few different number sequences $n_0\ldots n_k$
actually occur, since most of the |n|'s are generally zero, seems to fail
at least for the large German hyphenation patterns.
Therefore the number sequences cannot any longer be encoded in such a way
that |trie_op|$(z_k)$ is only one byte long.
We have introduced a new constant |max_trie_op| for the maximum allowable
hyphenation operation code value; |max_trie_op| might be different for
\TeX\ and \.{INITEX} and must not exceed |max_halfword|.
An opcode will occupy a halfword if |max_trie_op| exceeds |max_quarterword|
or a quarterword otherwise.
@^system dependencies@>
If |trie_op(@t$z_k$@>)<>min_trie_op|, when $p_1\ldots p_k$ has matched
the letters in |hc[(l-k+1)..l@,]| of language |t|,
we perform all of the required operations
for this pattern by carrying out the following little program: Set
|v:=trie_op(@t$z_k$@>)|. Then set |v:=v+op_start[t]|,
|hyf[l-hyf_distance[v]]:=@tmax@>(hyf[l-hyf_distance[v]], hyf_num[v])|,
and |v:=hyf_next[v]|; repeat, if necessary, until |v=min_trie_op|.
@z

@x
@!trie_pointer=0..trie_size; {an index into |trie|}
@y
@!trie_pointer=0..ssup_trie_size; {an index into |trie|}
@!trie_opcode=0..ssup_trie_opcode;  {a trie opcode}
@z

@x
@ @d trie_link(#)==trie[#].rh {``downward'' link in a trie}
@d trie_char(#)==trie[#].b1 {character matched at this trie location}
@d trie_op(#)==trie[#].b0 {program for hyphenation at this trie location}
@y
@ For more than 255 trie op codes, the three fields |trie_link|, |trie_char|,
and |trie_op| will no longer fit into one memory word; thus using web2c
we define |trie| as three array instead of an array of records.
The variant will be implented by reusing the opcode field later on with
another macro.

@d trie_link(#)==trie_trl[#] {``downward'' link in a trie}
@d trie_char(#)==trie_trc[#] {character matched at this trie location}
@d trie_op(#)==trie_tro[#] {program for hyphenation at this trie location}
@z

@x
@!trie:array[trie_pointer] of two_halves; {|trie_link|, |trie_char|, |trie_op|}
@y
{We will dynamically allocate these arrays.}
@!trie_trl:^trie_pointer; {|trie_link|}
@!trie_tro:^trie_pointer; {|trie_op|}
@!trie_trc:^quarterword; {|trie_char|}
@z

@x
@!hyf_next:array[1..trie_op_size] of quarterword; {continuation code}
@y
@!hyf_next:array[1..trie_op_size] of trie_opcode; {continuation code}
@z

@x
    begin if trie_op(z)<>min_quarterword then
@y
    begin if trie_op(z)<>min_trie_op then
@z

@x
until v=min_quarterword;
@y
until v=min_trie_op;
@z

@x
different from $\alpha$, we can conclude that $\alpha$ is not in the table.
@y
different from $\alpha$, we can conclude that $\alpha$ is not in the table.
This is a clever scheme which saves the need for a hash link array.
However, it is difficult to increase the size of the hyphen exception
arrays. To make this easier, the ordered hash has been replaced by
a simple hash, using an additional array |hyph_link|. The value
|0| in |hyph_link[k]| means that there are no more entries corresponding
to the specific hash chain. When |hyph_link[k]>0|, the next entry in
the hash chain is |hyph_link[k]-1|. This value is used because the
arrays start at |0|.
@z

@x
@!hyph_pointer=0..hyph_size; {an index into the ordered hash table}
@y
@!hyph_pointer=0..ssup_hyph_size; {index into hyphen exceptions hash table;
                     enlarging this requires changing (un)dump code}
@z

@x
@!hyph_word:array[hyph_pointer] of str_number; {exception words}
@!hyph_list:array[hyph_pointer] of pointer; {lists of hyphen positions}
@!hyph_count:hyph_pointer; {the number of words in the exception dictionary}
@y
@!hyph_word: ^str_number; {exception words}
@!hyph_list: ^pointer; {lists of hyphen positions}
@!hyph_link: ^hyph_pointer; {link array for hyphen exceptions hash table}
@!hyph_count:integer; {the number of words in the exception dictionary}
@!hyph_next:integer; {next free slot in hyphen exceptions hash table}
@z

@x
for z:=0 to hyph_size do
  begin hyph_word[z]:=0; hyph_list[z]:=null;
  end;
hyph_count:=0;
@y
for z:=0 to hyph_size do
  begin hyph_word[z]:=0; hyph_list[z]:=null; hyph_link[z]:=0;
  end;
hyph_count:=0;
hyph_next:=hyph_prime+1; if hyph_next>hyph_size then hyph_next:=hyph_prime;
@z

@x
h:=hc[1]; incr(hn); hc[hn]:=cur_lang;
for j:=2 to hn do h:=(h+h+hc[j]) mod hyph_size;
loop@+  begin @<If the string |hyph_word[h]| is less than \(hc)|hc[1..hn]|,
    |goto not_found|; but if the two strings are equal,
    set |hyf| to the hyphen positions and |goto found|@>;
  if h>0 then decr(h)@+else h:=hyph_size;
  end;
not_found: decr(hn)
@y
h:=hc[1]; incr(hn); hc[hn]:=cur_lang;
for j:=2 to hn do h:=(h+h+hc[j]) mod hyph_prime;
loop@+  begin @<If the string |hyph_word[h]| is less than \(hc)|hc[1..hn]|,
    |goto not_found|; but if the two strings are equal,
    set |hyf| to the hyphen positions and |goto found|@>;
  h:=hyph_link[h]; if h=0 then goto not_found;
  decr(h);
  end;
not_found: decr(hn)
@z

@x
@ @<If the string |hyph_word[h]| is less than \(hc)...@>=
k:=hyph_word[h]; if k=0 then goto not_found;
if length(k)<hn then goto not_found;
@y
@ @<If the string |hyph_word[h]| is less than \(hc)...@>=
{This is now a simple hash list, not an ordered one, so
the module title is no longer descriptive.}
k:=hyph_word[h]; if k=0 then goto not_found;
@z

@x
  repeat if so(str_pool[u])<hc[j] then goto not_found;
  if so(str_pool[u])>hc[j] then goto done;
@y
  repeat
  if so(str_pool[u])<>hc[j] then goto done;
@z

@x
@!s,@!t:str_number; {strings being compared or stored}
@y
@!s:str_number; {strings being compared or stored}
@z

@x
  begin h:=(h+h+hc[j]) mod hyph_size;
@y
  begin h:=(h+h+hc[j]) mod hyph_prime;
@z

@x
@ @<Insert the \(p)pair |(s,p)|...@>=
if hyph_count=hyph_size then overflow("exception dictionary",hyph_size);
@:TeX capacity exceeded exception dictionary}{\quad exception dictionary@>
incr(hyph_count);
while hyph_word[h]<>0 do
  begin @<If the string |hyph_word[h]| is less than \(or)or equal to
  |s|, interchange |(hyph_word[h],hyph_list[h])| with |(s,p)|@>;
  if h>0 then decr(h)@+else h:=hyph_size;
  end;
hyph_word[h]:=s; hyph_list[h]:=p
@y
@ @<Insert the \(p)pair |(s,p)|...@>=
  if hyph_next <= hyph_prime then
     while (hyph_next>0) and (hyph_word[hyph_next-1]>0) do decr(hyph_next);
if (hyph_count=hyph_size)or(hyph_next=0) then
   overflow("exception dictionary",hyph_size);
@:TeX capacity exceeded exception dictionary}{\quad exception dictionary@>
incr(hyph_count);
while hyph_word[h]<>0 do
  begin @<If the string |hyph_word[h]| is less than \(or)or equal to
  |s|, interchange |(hyph_word[h],hyph_list[h])| with |(s,p)|@>;
  if hyph_link[h]=0 then
  begin
    hyph_link[h]:=hyph_next;
    if hyph_next >= hyph_size then hyph_next:=hyph_prime;
    if hyph_next > hyph_prime then incr(hyph_next);
  end;
  h:=hyph_link[h]-1;
  end;

found: hyph_word[h]:=s; hyph_list[h]:=p
@z

@x
@ @<If the string |hyph_word[h]| is less than \(or)...@>=
k:=hyph_word[h];
if length(k)<length(s) then goto found;
if length(k)>length(s) then goto not_found;
@y
@ @<If the string |hyph_word[h]| is less than \(or)...@>=
{This is now a simple hash list, not an ordered one, so
the module title is no longer descriptive.}
k:=hyph_word[h];
if length(k)<>length(s) then goto not_found;
@z

@x
repeat if str_pool[u]<str_pool[v] then goto found;
if str_pool[u]>str_pool[v] then goto not_found;
@y
repeat if str_pool[u]<>str_pool[v] then goto not_found;
@z

@x
found:q:=hyph_list[h]; hyph_list[h]:=p; p:=q;@/
t:=hyph_word[h]; hyph_word[h]:=s; s:=t;
not_found:
@y
{repeat hyphenation exception; flushing old data}
flush_string; s:=hyph_word[h]; {avoid |slow_make_string|!}
decr(hyph_count);
{ We could also |flush_list(hyph_list[h]);|, but it interferes
  with \.{trip.log}. }
goto found;
not_found:
@z

@x
|hyf_next[@t$v^\prime$@>]=min_quarterword|.
@y
|hyf_next[@t$v^\prime$@>]=min_trie_op|.
@z

@x
$$\hbox{|@t$v^\prime$@>:=new_trie_op(0,1,min_quarterword)|,\qquad
@y
$$\hbox{|@t$v^\prime$@>:=new_trie_op(0,1,min_trie_op)|,\qquad
@z

@x
@!init@! trie_op_hash:array[-trie_op_size..trie_op_size] of 0..trie_op_size;
@y
@!init@! trie_op_hash:array[neg_trie_op_size..trie_op_size] of 0..trie_op_size;
@z

@x
@!trie_used:array[ASCII_code] of quarterword;
@y
@!trie_used:array[0..biggest_lang] of trie_opcode;
@z

@x
@!trie_op_val:array[1..trie_op_size] of quarterword;
@y
@!trie_op_val:array[1..trie_op_size] of trie_opcode;
@z

@x
tini
@y
tini@;
@!max_op_used:trie_opcode; {largest opcode used for any language}
@!small_op:boolean; {flag used while dumping or undumping}
@z

@x
|new_trie_op| could return |min_quarterword| (thereby simply ignoring
@y
|new_trie_op| could return |min_trie_op| (thereby simply ignoring
@z

@x
function new_trie_op(@!d,@!n:small_number;@!v:quarterword):quarterword;
label exit;
var h:-trie_op_size..trie_op_size; {trial hash location}
@!u:quarterword; {trial op code}
@y
function new_trie_op(@!d,@!n:small_number;@!v:trie_opcode):trie_opcode;
label exit;
var h:neg_trie_op_size..trie_op_size; {trial hash location}
@!u:trie_opcode; {trial op code}
@z

@x
begin h:=abs(n+313*d+361*v+1009*cur_lang) mod (trie_op_size+trie_op_size)
  - trie_op_size;
@y
begin h:=abs(n+313*d+361*v+1009*cur_lang) mod (trie_op_size-neg_trie_op_size)
  + neg_trie_op_size;
@z

@x
    if u=max_quarterword then
      overflow("pattern memory ops per language",
        max_quarterword-min_quarterword);
    incr(trie_op_ptr); incr(u); trie_used[cur_lang]:=u;
@y
    if u=max_trie_op then
      overflow("pattern memory ops per language",
      max_trie_op-min_trie_op);
    incr(trie_op_ptr); incr(u); trie_used[cur_lang]:=u;
    if u>max_op_used then max_op_used:=u;
@z

@x
op_start[0]:=-min_quarterword;
@y
op_start[0]:=-min_trie_op;
@z

@x
for k:=0 to 255 do trie_used[k]:=min_quarterword;
@y
for k:=0 to biggest_lang do trie_used[k]:=min_trie_op;
@z

@x
trie_op_ptr:=0;
@y
max_op_used:=min_trie_op;
trie_op_ptr:=0;
@z

@x
@!init @!trie_c:packed array[trie_pointer] of packed_ASCII_code;
  {characters to match}
@t\hskip10pt@>@!trie_o:packed array[trie_pointer] of quarterword;
  {operations to perform}
@t\hskip10pt@>@!trie_l:packed array[trie_pointer] of trie_pointer;
  {left subtrie links}
@t\hskip10pt@>@!trie_r:packed array[trie_pointer] of trie_pointer;
  {right subtrie links}
@t\hskip10pt@>@!trie_ptr:trie_pointer; {the number of nodes in the trie}
@t\hskip10pt@>@!trie_hash:packed array[trie_pointer] of trie_pointer;
  {used to identify equivalent subtries}
tini
@y
@!init @!trie_c:^packed_ASCII_code;
  {characters to match}
@t\hskip10pt@>@!trie_o:^trie_opcode;
  {operations to perform}
@t\hskip10pt@>@!trie_l:^trie_pointer;
  {left subtrie links}
@t\hskip10pt@>@!trie_r:^trie_pointer;
  {right subtrie links}
@t\hskip10pt@>@!trie_ptr:trie_pointer; {the number of nodes in the trie}
@t\hskip10pt@>@!trie_hash:^trie_pointer;
  {used to identify equivalent subtries}
tini
@z

@x
@d trie_back(#)==trie[#].lh {backward links in |trie| holes}
@y
@d trie_back(#)==trie_tro[#] {use the opcode field now for backward links}
@z

@x
@!init@!trie_taken:packed array[1..trie_size] of boolean;
  {does a family start here?}
@t\hskip10pt@>@!trie_min:array[ASCII_code] of trie_pointer;
  {the first possible slot for each character}
@t\hskip10pt@>@!trie_max:trie_pointer; {largest location used in |trie|}
@t\hskip10pt@>@!trie_not_ready:boolean; {is the trie still in linked form?}
tini
@y
@!init@!trie_taken: ^boolean;
  {does a family start here?}
@t\hskip10pt@>@!trie_min:array[ASCII_code] of trie_pointer;
  {the first possible slot for each character}
@t\hskip10pt@>@!trie_max:trie_pointer; {largest location used in |trie|}
@t\hskip10pt@>@!trie_not_ready:boolean; {is the trie still in linked form?}
tini
@z

@x
trie_not_ready:=true; trie_root:=0; trie_c[0]:=si(0); trie_ptr:=0;
@y
trie_not_ready:=true;
@z

@x
@<Move the data into |trie|@>=
h.rh:=0; h.b0:=min_quarterword; h.b1:=min_quarterword; {|trie_link:=0|,
  |trie_op:=min_quarterword|, |trie_char:=qi(0)|}
@y
@d clear_trie == {clear |trie[r]|}
  begin trie_link(r):=0;
  trie_op(r):=min_trie_op;
  trie_char(r):=min_quarterword; {|trie_char:=qi(0)|}
  end

@<Move the data into |trie|@>=
@z

@x
  begin for r:=0 to 256 do trie[r]:=h;
  trie_max:=256;
@y
  begin for r:=0 to max_hyph_char do clear_trie;
  trie_max:=max_hyph_char;
@z

@x
  repeat s:=trie_link(r); trie[r]:=h; r:=s;
@y
  repeat s:=trie_link(r); clear_trie; r:=s;
@z

@x
@!v:quarterword; {trie op code}
@y
@!v:trie_opcode; {trie op code}
@z

@x
if trie_o[q]<>min_quarterword then
@y
if trie_o[q]<>min_trie_op then
@z

@x
trie_c[p]:=si(c); trie_o[p]:=min_quarterword;
@y
trie_c[p]:=si(c); trie_o[p]:=min_trie_op;
@z

@x
l:=k; v:=min_quarterword;
@y
l:=k; v:=min_trie_op;
@z

@x
@!h:two_halves; {template used to zero out |trie|'s holes}
@y
@z

@x
@<Initialize the special list...@>=
type(page_head):=glue_node; subtype(page_head):=normal;
@y
@<Initialize the special list...@>=
type(page_head):=glue_node; subtype(page_head):=normal;
        {{\sl Sync\TeX} watch point: box(|page_head|) size >= |glue_node| size}
@z

@x
@<Append character |cur_chr|...@>=
@y
@<Append character |cur_chr|...@>=
if ((head=tail) and (mode>0)) then begin
  if (insert_src_special_auto) then append_src_special;
end;
@z

@x
main_loop_move+2:if(cur_chr<font_bc[main_f])or(cur_chr>font_ec[main_f]) then
@y
main_loop_move+2:
if(qo(effective_char(false,main_f,qi(cur_chr)))>font_ec[main_f])or
  (qo(effective_char(false,main_f,qi(cur_chr)))<font_bc[main_f]) then
@z

@x
main_i:=char_info(main_f)(cur_l);
@y
main_i:=effective_char_info(main_f,cur_l);
@z

@x
@<Move the cursor past a pseudo-ligature...@>=
@y
@<Move the cursor past a pseudo-ligature...@>=
@z

@x
free_node(temp_ptr,small_node_size);
@y
free_node(temp_ptr,small_node_size); {{\sl Sync\TeX} watch point: proper size!}
@z

@x
print("' in "); print_mode(mode);
@y
print_in_mode(mode);
@z

@x
if indented then
  begin tail:=new_null_box; link(head):=tail; width(tail):=par_indent;@+
  end;
@y
if indented then
  begin tail:=new_null_box; link(head):=tail; width(tail):=par_indent;
  if (insert_src_special_every_par) then insert_src_special;@+
  end;
@z

@x
if every_math<>null then begin_token_list(every_math,every_math_text);
@y
if (insert_src_special_every_math) then insert_src_special;
if every_math<>null then begin_token_list(every_math,every_math_text);
@z

@x
  if every_vbox<>null then begin_token_list(every_vbox,every_vbox_text);
@y
  if (insert_src_special_every_vbox) then insert_src_special;
  if every_vbox<>null then begin_token_list(every_vbox,every_vbox_text);
@z

@x
if (cur_cs=0)or(cur_cs>frozen_control_sequence) then
@y
if (cur_cs=0)or(cur_cs>eqtb_top)or
  ((cur_cs>frozen_control_sequence)and(cur_cs<=eqtb_size)) then
@z

@x
@d toks_def_code=6 {|shorthand_def| for \.{\\toksdef}}
@y
@d toks_def_code=6 {|shorthand_def| for \.{\\toksdef}}
@d char_sub_def_code=7 {|shorthand_def| for \.{\\charsubdef}}
@z

@x
@!@:toks_def_}{\.{\\toksdef} primitive@>
@y
@!@:toks_def_}{\.{\\toksdef} primitive@>
if mltex_p then
  begin
  primitive("charsubdef",shorthand_def,char_sub_def_code);@/
@!@:char_sub_def_}{\.{\\charsubdef} primitive@>
  end;
@z

@x
  othercases print_esc("toksdef")
@y
  char_sub_def_code: print_esc("charsubdef");
  othercases print_esc("toksdef")
@z

@x
shorthand_def: begin n:=cur_chr; get_r_token; p:=cur_cs; define(p,relax,256);
@y
shorthand_def: if cur_chr=char_sub_def_code then
 begin scan_char_num; p:=char_sub_code_base+cur_val; scan_optional_equals;
  scan_char_num; n:=cur_val; {accent character in substitution}
  scan_char_num;
  if (tracing_char_sub_def>0) then
    begin begin_diagnostic; print_nl("New character substitution: ");
    print_ASCII(p-char_sub_code_base); print(" = ");
    print_ASCII(n); print_char(" ");
    print_ASCII(cur_val); end_diagnostic(false);
    end;
  n:=n*256+cur_val;
  define(p,data,hi(n));
  if (p-char_sub_code_base)<char_sub_def_min then
    word_define(int_base+char_sub_def_min_code,p-char_sub_code_base);
  if (p-char_sub_code_base)>char_sub_def_max then
    word_define(int_base+char_sub_def_max_code,p-char_sub_code_base);
 end
else begin n:=cur_chr; get_r_token; p:=cur_cs; define(p,relax,too_big_usv);
@z

@x
    begin @!init new_patterns; goto done;@;@+tini@/
@y
    begin @!Init new_patterns; goto done;@;@+Tini@/
@z

@x
@!flushable_string:str_number; {string not yet referenced}
@y
@z

@x
flushable_string:=str_ptr-1;
@y
@z

@x
    begin if cur_name=flushable_string then
      begin flush_string; cur_name:=font_name[f];
      end;
    if s>0 then
@y
    begin if s>0 then
@z

@x
interaction:=cur_chr;
@y
interaction:=cur_chr;
if interaction = batch_mode
then kpse_make_tex_discard_errors := 1
else kpse_make_tex_discard_errors := 0;
@z

@x
var c:0..1; {1 for \.{\\openin}, 0 for \.{\\closein}}
@!n:0..15; {stream number}
@y
var c:0..1; {1 for \.{\\openin}, 0 for \.{\\closein}}
@!n:0..15; {stream number}
@!k:0..file_name_size; {index into |name_of_file16|}
@z

@x
  if cur_ext="" then cur_ext:=".tex";
  pack_cur_name;
  if a_open_in(read_file[n]) then read_open[n]:=just_open;
@y
  pack_cur_name;
  tex_input_type:=0; {Tell |open_input| we are \.{\\openin}.}
  if kpse_in_name_ok(stringcast(name_of_file+1))
     and u_open_in(read_file[n], kpse_tex_format, XeTeX_default_input_mode, XeTeX_default_input_encoding) then
    begin
    make_utf16_name;
    name_in_progress:=true;
    begin_name;
    stop_at_space:=false;
    k:=0;
    while (k<name_length16)and(more_name(name_of_file16[k])) do
      incr(k);
    stop_at_space:=true;
    end_name;
    name_in_progress:=false;
    read_open[n]:=just_open;
    end;
@z

@x
format_ident:=" (INITEX)";
@y
if ini_version then format_ident:=" (INITEX)";
@z

@x
@!w: four_quarters; {four ASCII codes}
@y
@!format_engine: ^char;
@z

@x
@<Dump constants for consistency check@>;
@y
@<Dump constants for consistency check@>;
@<Dump ML\TeX-specific data@>;
@z

@x
@!w: four_quarters; {four ASCII codes}
@y
@!format_engine: ^char;
@z

@x
begin @<Undump constants for consistency check@>;
@y
begin @<Undump constants for consistency check@>;
@<Undump ML\TeX-specific data@>;
@z

@x
@d dump_wd(#)==begin fmt_file^:=#; put(fmt_file);@+end
@d dump_int(#)==begin fmt_file^.int:=#; put(fmt_file);@+end
@d dump_hh(#)==begin fmt_file^.hh:=#; put(fmt_file);@+end
@d dump_qqqq(#)==begin fmt_file^.qqqq:=#; put(fmt_file);@+end
@y
@z

@x
@d undump_wd(#)==begin get(fmt_file); #:=fmt_file^;@+end
@d undump_int(#)==begin get(fmt_file); #:=fmt_file^.int;@+end
@d undump_hh(#)==begin get(fmt_file); #:=fmt_file^.hh;@+end
@d undump_qqqq(#)==begin get(fmt_file); #:=fmt_file^.qqqq;@+end
@y
@z

@x
@d undump_size_end_end(#)==too_small(#)@+else undump_end_end
@y
@d format_debug_end(#)==
    write_ln (stderr, ' = ', #);
  end;
@d format_debug(#)==
  if debug_format_file then begin
    write (stderr, 'fmtdebug:', #);
    format_debug_end
@d undump_size_end_end(#)==
  too_small(#)@+else format_debug (#)(x); undump_end_end
@z

@x
dump_int(@$);@/
@y
dump_int(@"57325458);  {Web2C \TeX's magic constant: "W2TX"}
{Align engine to 4 bytes with one or more trailing NUL}
x:=strlen(engine_name);
format_engine:=xmalloc_array(char,x+4);
strcpy(stringcast(format_engine), engine_name);
for k:=x to x+3 do format_engine[k]:=0;
x:=x+4-(x mod 4);
dump_int(x);dump_things(format_engine[0], x);
libc_free(format_engine);@/
dump_int(@$);@/
dump_int(max_halfword);@/
dump_int(hash_high);
@z

@x
dump_int(hyph_size)
@y
dump_int(hyph_prime)
@z

@x
x:=fmt_file^.int;
if x<>@$ then goto bad_fmt; {check that strings are the same}
@y
@+Init
libc_free(font_info); libc_free(str_pool); libc_free(str_start);
libc_free(yhash); libc_free(zeqtb); libc_free(yzmem);
@+Tini
undump_int(x);
format_debug('format magic number')(x);
if x<>@"57325458 then goto bad_fmt; {not a format file}
undump_int(x);
format_debug('engine name size')(x);
if (x<0) or (x>256) then goto bad_fmt; {corrupted format file}
format_engine:=xmalloc_array(char, x);
undump_things(format_engine[0], x);
format_engine[x-1]:=0; {force string termination, just in case}
if strcmp(engine_name, stringcast(format_engine)) then
  begin wake_up_terminal;
  wterm_ln('---! ', stringcast(name_of_file+1), ' was written by ', format_engine);
  libc_free(format_engine);
  goto bad_fmt;
end;
libc_free(format_engine);
undump_int(x);
format_debug('string pool checksum')(x);
if x<>@$ then begin {check that strings are the same}
  wake_up_terminal;
  wterm_ln('---! ', stringcast(name_of_file+1), ' doesn''t match ', pool_name);
  goto bad_fmt;
end;
undump_int(x);
if x<>max_halfword then goto bad_fmt; {check |max_halfword|}
undump_int(hash_high);
  if (hash_high<0)or(hash_high>sup_hash_extra) then goto bad_fmt;
  if hash_extra<hash_high then hash_extra:=hash_high;
  eqtb_top:=eqtb_size+hash_extra;
  if hash_extra=0 then hash_top:=undefined_control_sequence else
        hash_top:=eqtb_top;
  yhash:=xmalloc_array(two_halves,1+hash_top-hash_offset);
  hash:=yhash - hash_offset;
  next(hash_base):=0; text(hash_base):=0;
  for x:=hash_base+1 to hash_top do hash[x]:=hash[hash_base];
  zeqtb:=xmalloc_array (memory_word,eqtb_top+1);
  eqtb:=zeqtb;

  eq_type(undefined_control_sequence):=undefined_cs;
  equiv(undefined_control_sequence):=null;
  eq_level(undefined_control_sequence):=level_zero;
  for x:=eqtb_size+1 to eqtb_top do
    eqtb[x]:=eqtb[undefined_control_sequence];
@z

@x
undump_int(x);
if x<>mem_bot then goto bad_fmt;
undump_int(x);
if x<>mem_top then goto bad_fmt;
@y
undump_int(x); format_debug ('mem_bot')(x);
if x<>mem_bot then goto bad_fmt;
undump_int(mem_top); format_debug ('mem_top')(mem_top);
if mem_bot+1100>mem_top then goto bad_fmt;


head:=contrib_head; tail:=contrib_head;
     page_tail:=page_head;  {page initialization}

mem_min := mem_bot - extra_mem_bot;
mem_max := mem_top + extra_mem_top;

yzmem:=xmalloc_array (memory_word, mem_max - mem_min + 1);
zmem := yzmem - mem_min;   {this pointer arithmetic fails with some compilers}
mem := zmem;
@z

@x
if x<>hyph_size then goto bad_fmt
@y
if x<>hyph_prime then goto bad_fmt
@z

@x
for k:=0 to str_ptr do dump_int(str_start[k]);
k:=0;
while k+4<pool_ptr do
  begin dump_four_ASCII; k:=k+4;
  end;
k:=pool_ptr-4; dump_four_ASCII;
@y
dump_things(str_start_macro(too_big_char), str_ptr+1-too_big_char);
dump_things(str_pool[0], pool_ptr);
@z

@x
undump_size(0)(pool_size)('string pool size')(pool_ptr);
undump_size(0)(max_strings)('max strings')(str_ptr);
for k:=0 to str_ptr do undump(0)(pool_ptr)(str_start[k]);
k:=0;
while k+4<pool_ptr do
  begin undump_four_ASCII; k:=k+4;
  end;
k:=pool_ptr-4; undump_four_ASCII;
@y
undump_size(0)(sup_pool_size-pool_free)('string pool size')(pool_ptr);
if pool_size<pool_ptr+pool_free then
  pool_size:=pool_ptr+pool_free;
undump_size(0)(sup_max_strings-strings_free)('sup strings')(str_ptr);@/
if max_strings<str_ptr+strings_free then
  max_strings:=str_ptr+strings_free;
str_start:=xmalloc_array(pool_pointer, max_strings);
undump_checked_things(0, pool_ptr, str_start_macro(too_big_char), str_ptr+1-too_big_char);@/
str_pool:=xmalloc_array(packed_ASCII_code, pool_size);
undump_things(str_pool[0], pool_ptr);
@z

@x
repeat for k:=p to q+1 do dump_wd(mem[k]);
@y
repeat dump_things(mem[p], q+2-p);
@z

@x
for k:=p to lo_mem_max do dump_wd(mem[k]);
@y
dump_things(mem[p], lo_mem_max+1-p);
@z

@x
for k:=hi_mem_min to mem_end do dump_wd(mem[k]);
@y
dump_things(mem[hi_mem_min], mem_end+1-hi_mem_min);
@z

@x
repeat for k:=p to q+1 do undump_wd(mem[k]);
@y
repeat undump_things(mem[p], q+2-p);
@z

@x
for k:=p to lo_mem_max do undump_wd(mem[k]);
@y
undump_things(mem[p], lo_mem_max+1-p);
@z

@x
for k:=hi_mem_min to mem_end do undump_wd(mem[k]);
@y
undump_things (mem[hi_mem_min], mem_end+1-hi_mem_min);
@z

@x
undump(hash_base)(frozen_control_sequence)(par_loc);
par_token:=cs_token_flag+par_loc;@/
undump(hash_base)(frozen_control_sequence)(write_loc);@/
@y
undump(hash_base)(hash_top)(par_loc);
par_token:=cs_token_flag+par_loc;@/
undump(hash_base)(hash_top)(write_loc);@/
@z

@x
while k<l do
  begin dump_wd(eqtb[k]); incr(k);
  end;
@y
dump_things(eqtb[k], l-k);
@z

@x
while k<l do
  begin dump_wd(eqtb[k]); incr(k);
  end;
@y
dump_things(eqtb[k], l-k);
@z

@x
k:=j+1; dump_int(k-l);
until k>eqtb_size
@y
k:=j+1; dump_int(k-l);
until k>eqtb_size;
if hash_high>0 then dump_things(eqtb[eqtb_size+1],hash_high);
  {dump |hash_extra| part}
@z

@x
for j:=k to k+x-1 do undump_wd(eqtb[j]);
@y
undump_things(eqtb[k], x);
@z

@x
until k>eqtb_size
@y
until k>eqtb_size;
if hash_high>0 then undump_things(eqtb[eqtb_size+1],hash_high);
  {undump |hash_extra| part}
@z

@x
dump_int(hash_used); cs_count:=frozen_control_sequence-1-hash_used;
@y
dump_int(hash_used); cs_count:=frozen_control_sequence-1-hash_used+hash_high;
@z

@x
for p:=hash_used+1 to undefined_control_sequence-1 do dump_hh(hash[p]);
@y
dump_things(hash[hash_used+1], undefined_control_sequence-1-hash_used);
if hash_high>0 then dump_things(hash[eqtb_size+1], hash_high);
@z

@x
for p:=hash_used+1 to undefined_control_sequence-1 do undump_hh(hash[p]);
@y
undump_things (hash[hash_used+1], undefined_control_sequence-1-hash_used);
if debug_format_file then begin
  print_csnames (hash_base, undefined_control_sequence - 1);
end;
if hash_high > 0 then begin
  undump_things (hash[eqtb_size+1], hash_high);
  if debug_format_file then begin
    print_csnames (eqtb_size + 1, hash_high - (eqtb_size + 1));
  end;
end;
@z

@x
for k:=0 to fmem_ptr-1 do dump_wd(font_info[k]);
dump_int(font_ptr);
for k:=null_font to font_ptr do
  @<Dump the array info for internal font number |k|@>;
@y
dump_things(font_info[0], fmem_ptr);
dump_int(font_ptr);
@<Dump the array info for internal font number |k|@>;
@z

@x
print_int(font_ptr-font_base); print(" preloaded font");
if font_ptr<>font_base+1 then print_char("s")
@y
print_int(font_ptr-font_base);
if font_ptr<>font_base+1 then print(" preloaded fonts")
else print(" preloaded font")
@z

@x
undump_size(7)(font_mem_size)('font mem size')(fmem_ptr);
for k:=0 to fmem_ptr-1 do undump_wd(font_info[k]);
undump_size(font_base)(font_max)('font max')(font_ptr);
for k:=null_font to font_ptr do
  @<Undump the array info for internal font number |k|@>
@y
undump_size(7)(sup_font_mem_size)('font mem size')(fmem_ptr);
if fmem_ptr>font_mem_size then font_mem_size:=fmem_ptr;
font_info:=xmalloc_array(fmemory_word, font_mem_size);
undump_things(font_info[0], fmem_ptr);@/
undump_size(font_base)(font_base+max_font_max)('font max')(font_ptr);
{This undumps all of the font info, despite the name.}
@<Undump the array info for internal font number |k|@>;
@z

@x
@ @<Dump the array info for internal font number |k|@>=
begin dump_qqqq(font_check[k]);
dump_int(font_size[k]);
dump_int(font_dsize[k]);
dump_int(font_params[k]);@/
dump_int(hyphen_char[k]);
dump_int(skew_char[k]);@/
dump_int(font_name[k]);
dump_int(font_area[k]);@/
dump_int(font_bc[k]);
dump_int(font_ec[k]);@/
dump_int(char_base[k]);
dump_int(width_base[k]);
dump_int(height_base[k]);@/
dump_int(depth_base[k]);
dump_int(italic_base[k]);
dump_int(lig_kern_base[k]);@/
dump_int(kern_base[k]);
dump_int(exten_base[k]);
dump_int(param_base[k]);@/
dump_int(font_glue[k]);@/
dump_int(bchar_label[k]);
dump_int(font_bchar[k]);
dump_int(font_false_bchar[k]);@/
print_nl("\font"); print_esc(font_id_text(k)); print_char("=");
print_file_name(font_name[k],font_area[k],"");
if font_size[k]<>font_dsize[k] then
  begin print(" at "); print_scaled(font_size[k]); print("pt");
  end;
end
@y
@ @<Dump the array info for internal font number |k|@>=
begin
dump_things(font_check[null_font], font_ptr+1-null_font);
dump_things(font_size[null_font], font_ptr+1-null_font);
dump_things(font_dsize[null_font], font_ptr+1-null_font);
dump_things(font_params[null_font], font_ptr+1-null_font);
dump_things(hyphen_char[null_font], font_ptr+1-null_font);
dump_things(skew_char[null_font], font_ptr+1-null_font);
dump_things(font_name[null_font], font_ptr+1-null_font);
dump_things(font_area[null_font], font_ptr+1-null_font);
dump_things(font_bc[null_font], font_ptr+1-null_font);
dump_things(font_ec[null_font], font_ptr+1-null_font);
dump_things(char_base[null_font], font_ptr+1-null_font);
dump_things(width_base[null_font], font_ptr+1-null_font);
dump_things(height_base[null_font], font_ptr+1-null_font);
dump_things(depth_base[null_font], font_ptr+1-null_font);
dump_things(italic_base[null_font], font_ptr+1-null_font);
dump_things(lig_kern_base[null_font], font_ptr+1-null_font);
dump_things(kern_base[null_font], font_ptr+1-null_font);
dump_things(exten_base[null_font], font_ptr+1-null_font);
dump_things(param_base[null_font], font_ptr+1-null_font);
dump_things(font_glue[null_font], font_ptr+1-null_font);
dump_things(bchar_label[null_font], font_ptr+1-null_font);
dump_things(font_bchar[null_font], font_ptr+1-null_font);
dump_things(font_false_bchar[null_font], font_ptr+1-null_font);
for k:=null_font to font_ptr do
  begin print_nl("\font"); print_esc(font_id_text(k)); print_char("=");
  if is_native_font(k) or (font_mapping[k]<>0) then
    begin print_file_name(font_name[k],"","");
    print_err("Can't \dump a format with native fonts or font-mappings");
    help3("You really, really don't want to do this.")
    ("It won't work, and only confuses me.")
    ("(Load them at runtime, not as part of the format file.)");
    error;
    end
  else print_file_name(font_name[k],font_area[k],"");
  if font_size[k]<>font_dsize[k] then
    begin print(" at "); print_scaled(font_size[k]); print("pt");
    end;
  end;
end
@z

@x
@ @<Undump the array info for internal font number |k|@>=
begin undump_qqqq(font_check[k]);@/
undump_int(font_size[k]);
undump_int(font_dsize[k]);
undump(min_halfword)(max_halfword)(font_params[k]);@/
undump_int(hyphen_char[k]);
undump_int(skew_char[k]);@/
undump(0)(str_ptr)(font_name[k]);
undump(0)(str_ptr)(font_area[k]);@/
undump(0)(255)(font_bc[k]);
undump(0)(255)(font_ec[k]);@/
undump_int(char_base[k]);
undump_int(width_base[k]);
undump_int(height_base[k]);@/
undump_int(depth_base[k]);
undump_int(italic_base[k]);
undump_int(lig_kern_base[k]);@/
undump_int(kern_base[k]);
undump_int(exten_base[k]);
undump_int(param_base[k]);@/
undump(min_halfword)(lo_mem_max)(font_glue[k]);@/
undump(0)(fmem_ptr-1)(bchar_label[k]);
undump(min_quarterword)(non_char)(font_bchar[k]);
undump(min_quarterword)(non_char)(font_false_bchar[k]);
end
@y
@ This module should now be named `Undump all the font arrays'.

@<Undump the array info for internal font number |k|@>=
begin {Allocate the font arrays}
font_mapping:=xmalloc_array(void_pointer, font_max);
font_layout_engine:=xmalloc_array(void_pointer, font_max);
font_flags:=xmalloc_array(char, font_max);
font_letter_space:=xmalloc_array(scaled, font_max);
font_check:=xmalloc_array(four_quarters, font_max);
font_size:=xmalloc_array(scaled, font_max);
font_dsize:=xmalloc_array(scaled, font_max);
font_params:=xmalloc_array(font_index, font_max);
font_name:=xmalloc_array(str_number, font_max);
font_area:=xmalloc_array(str_number, font_max);
font_bc:=xmalloc_array(UTF16_code, font_max);
font_ec:=xmalloc_array(UTF16_code, font_max);
font_glue:=xmalloc_array(halfword, font_max);
hyphen_char:=xmalloc_array(integer, font_max);
skew_char:=xmalloc_array(integer, font_max);
bchar_label:=xmalloc_array(font_index, font_max);
font_bchar:=xmalloc_array(nine_bits, font_max);
font_false_bchar:=xmalloc_array(nine_bits, font_max);
char_base:=xmalloc_array(integer, font_max);
width_base:=xmalloc_array(integer, font_max);
height_base:=xmalloc_array(integer, font_max);
depth_base:=xmalloc_array(integer, font_max);
italic_base:=xmalloc_array(integer, font_max);
lig_kern_base:=xmalloc_array(integer, font_max);
kern_base:=xmalloc_array(integer, font_max);
exten_base:=xmalloc_array(integer, font_max);
param_base:=xmalloc_array(integer, font_max);

for k:=null_font to font_ptr do font_mapping[k]:=0;
undump_things(font_check[null_font], font_ptr+1-null_font);
undump_things(font_size[null_font], font_ptr+1-null_font);
undump_things(font_dsize[null_font], font_ptr+1-null_font);
undump_checked_things(min_halfword, max_halfword,
                      font_params[null_font], font_ptr+1-null_font);
undump_things(hyphen_char[null_font], font_ptr+1-null_font);
undump_things(skew_char[null_font], font_ptr+1-null_font);
undump_upper_check_things(str_ptr, font_name[null_font], font_ptr+1-null_font);
undump_upper_check_things(str_ptr, font_area[null_font], font_ptr+1-null_font);
{There's no point in checking these values against the range $[0,255]$,
 since the data type is |unsigned char|, and all values of that type are
 in that range by definition.}
undump_things(font_bc[null_font], font_ptr+1-null_font);
undump_things(font_ec[null_font], font_ptr+1-null_font);
undump_things(char_base[null_font], font_ptr+1-null_font);
undump_things(width_base[null_font], font_ptr+1-null_font);
undump_things(height_base[null_font], font_ptr+1-null_font);
undump_things(depth_base[null_font], font_ptr+1-null_font);
undump_things(italic_base[null_font], font_ptr+1-null_font);
undump_things(lig_kern_base[null_font], font_ptr+1-null_font);
undump_things(kern_base[null_font], font_ptr+1-null_font);
undump_things(exten_base[null_font], font_ptr+1-null_font);
undump_things(param_base[null_font], font_ptr+1-null_font);
undump_checked_things(min_halfword, lo_mem_max,
                     font_glue[null_font], font_ptr+1-null_font);
undump_checked_things(0, fmem_ptr-1,
                     bchar_label[null_font], font_ptr+1-null_font);
undump_checked_things(min_quarterword, non_char,
                     font_bchar[null_font], font_ptr+1-null_font);
undump_checked_things(min_quarterword, non_char,
                     font_false_bchar[null_font], font_ptr+1-null_font);
end
@z

@x
dump_int(hyph_count);
for k:=0 to hyph_size do if hyph_word[k]<>0 then
  begin dump_int(k); dump_int(hyph_word[k]); dump_int(hyph_list[k]);
  end;
@y
dump_int(hyph_count);
if hyph_next <= hyph_prime then hyph_next:=hyph_size;
dump_int(hyph_next);{minumum value of |hyphen_size| needed}
for k:=0 to hyph_size do if hyph_word[k]<>0 then
  begin dump_int(k+65536*hyph_link[k]);
        {assumes number of hyphen exceptions does not exceed 65535}
   dump_int(hyph_word[k]); dump_int(hyph_list[k]);
  end;
@z

@x
print_ln; print_int(hyph_count); print(" hyphenation exception");
if hyph_count<>1 then print_char("s");
@y
print_ln; print_int(hyph_count);
if hyph_count<>1 then print(" hyphenation exceptions")
else print(" hyphenation exception");
@z

@x
for k:=0 to trie_max do dump_hh(trie[k]);
@y
dump_things(trie_trl[0], trie_max+1);
dump_things(trie_tro[0], trie_max+1);
dump_things(trie_trc[0], trie_max+1);
@z

@x
for k:=1 to trie_op_ptr do
  begin dump_int(hyf_distance[k]);
  dump_int(hyf_num[k]);
  dump_int(hyf_next[k]);
  end;
@y
dump_things(hyf_distance[1], trie_op_ptr);
dump_things(hyf_num[1], trie_op_ptr);
dump_things(hyf_next[1], trie_op_ptr);
@z

@x
print(" has "); print_int(trie_op_ptr); print(" op");
if trie_op_ptr<>1 then print_char("s");
@y
print(" has "); print_int(trie_op_ptr);
if trie_op_ptr<>1 then print(" ops")
else print(" op");
@z

@x
undump(0)(hyph_size)(hyph_count);
for k:=1 to hyph_count do
  begin undump(0)(hyph_size)(j);
  undump(0)(str_ptr)(hyph_word[j]);
  undump(min_halfword)(max_halfword)(hyph_list[j]);
  end;
@y
undump_size(0)(hyph_size)('hyph_size')(hyph_count);
undump_size(hyph_prime)(hyph_size)('hyph_size')(hyph_next);
j:=0;
for k:=1 to hyph_count do
  begin undump_int(j); if j<0 then goto bad_fmt;
   if j>65535 then
   begin hyph_next:= j div 65536; j:=j - hyph_next * 65536; end
       else hyph_next:=0;
   if (j>=hyph_size)or(hyph_next>hyph_size) then goto bad_fmt;
   hyph_link[j]:=hyph_next;
  undump(0)(str_ptr)(hyph_word[j]);
  undump(min_halfword)(max_halfword)(hyph_list[j]);
  end;
  {|j| is now the largest occupied location in |hyph_word|}
  incr(j);
  if j<hyph_prime then j:=hyph_prime;
  hyph_next:=j;
  if hyph_next >= hyph_size then hyph_next:=hyph_prime else
  if hyph_next >= hyph_prime then incr(hyph_next);
@z

@x
for k:=0 to j do undump_hh(trie[k]);
@y
{These first three haven't been allocated yet unless we're \.{INITEX};
 we do that precisely so we don't allocate more space than necessary.}
if not trie_trl then trie_trl:=xmalloc_array(trie_pointer,j+1);
undump_things(trie_trl[0], j+1);
if not trie_tro then trie_tro:=xmalloc_array(trie_pointer,j+1);
undump_things(trie_tro[0], j+1);
if not trie_trc then trie_trc:=xmalloc_array(quarterword, j+1);
undump_things(trie_trc[0], j+1);
@z

@x
for k:=1 to j do
  begin undump(0)(63)(hyf_distance[k]); {a |small_number|}
  undump(0)(63)(hyf_num[k]);
  undump(min_quarterword)(max_quarterword)(hyf_next[k]);
  end;
@y
{I'm not sure we have such a strict limitation (64) on these values, so
 let's leave them unchecked.}
undump_things(hyf_distance[1], j);
undump_things(hyf_num[1], j);
undump_upper_check_things(max_trie_op, hyf_next[1], j);
@z

@x
undump(batch_mode)(error_stop_mode)(interaction);
@y
undump(batch_mode)(error_stop_mode)(interaction);
if interaction_option<>unspecified_mode then interaction:=interaction_option;
@z

@x
if (x<>69069)or eof(fmt_file) then goto bad_fmt
@y
if x<>69069 then goto bad_fmt
@z

@x
@p begin @!{|start_here|}
@y
@d const_chk(#)==begin if # < inf@&# then # := inf@&# else
                         if # > sup@&# then # := sup@&# end

{|setup_bound_var| stuff duplicated in \.{mf.ch}.}
@d setup_bound_var(#)==bound_default:=#; setup_bound_var_end
@d setup_bound_var_end(#)==bound_name:=#; setup_bound_var_end_end
@d setup_bound_var_end_end(#)==
  setup_bound_variable(addressof(#), bound_name, bound_default)

@p procedure main_body;
begin @!{|start_here|}

{Bounds that may be set from the configuration file. We want the user to
 be able to specify the names with underscores, but \.{TANGLE} removes
 underscores, so we're stuck giving the names twice, once as a string,
 once as the identifier. How ugly.}
  setup_bound_var (0)('mem_bot')(mem_bot);
  setup_bound_var (250000)('main_memory')(main_memory);
    {|memory_word|s for |mem| in \.{INITEX}}
  setup_bound_var (0)('extra_mem_top')(extra_mem_top);
    {increase high mem in \.{VIRTEX}}
  setup_bound_var (0)('extra_mem_bot')(extra_mem_bot);
    {increase low mem in \.{VIRTEX}}
  setup_bound_var (200000)('pool_size')(pool_size);
  setup_bound_var (75000)('string_vacancies')(string_vacancies);
  setup_bound_var (5000)('pool_free')(pool_free); {min pool avail after fmt}
  setup_bound_var (15000)('max_strings')(max_strings);
  max_strings:=max_strings+too_big_char; {the |max_strings| value doesn't include the 64K synthetic strings}
  setup_bound_var (100)('strings_free')(strings_free);
  setup_bound_var (100000)('font_mem_size')(font_mem_size);
  setup_bound_var (500)('font_max')(font_max);
  setup_bound_var (20000)('trie_size')(trie_size);
    {if |ssup_trie_size| increases, recompile}
  setup_bound_var (659)('hyph_size')(hyph_size);
  setup_bound_var (3000)('buf_size')(buf_size);
  setup_bound_var (50)('nest_size')(nest_size);
  setup_bound_var (15)('max_in_open')(max_in_open);
  setup_bound_var (60)('param_size')(param_size);
  setup_bound_var (4000)('save_size')(save_size);
  setup_bound_var (300)('stack_size')(stack_size);
  setup_bound_var (16384)('dvi_buf_size')(dvi_buf_size);
  setup_bound_var (79)('error_line')(error_line);
  setup_bound_var (50)('half_error_line')(half_error_line);
  setup_bound_var (79)('max_print_line')(max_print_line);
  setup_bound_var (0)('hash_extra')(hash_extra);
  setup_bound_var (10000)('expand_depth')(expand_depth);

  const_chk (mem_bot);
  const_chk (main_memory);
@+Init
  extra_mem_top := 0;
  extra_mem_bot := 0;
@+Tini
  if extra_mem_bot>sup_main_memory then extra_mem_bot:=sup_main_memory;
  if extra_mem_top>sup_main_memory then extra_mem_top:=sup_main_memory;
  {|mem_top| is an index, |main_memory| a size}
  mem_top := mem_bot + main_memory -1;
  mem_min := mem_bot;
  mem_max := mem_top;

  {Check other constants against their sup and inf.}
  const_chk (trie_size);
  const_chk (hyph_size);
  const_chk (buf_size);
  const_chk (nest_size);
  const_chk (max_in_open);
  const_chk (param_size);
  const_chk (save_size);
  const_chk (stack_size);
  const_chk (dvi_buf_size);
  const_chk (pool_size);
  const_chk (string_vacancies);
  const_chk (pool_free);
  const_chk (max_strings);
  const_chk (strings_free);
  const_chk (font_mem_size);
  const_chk (font_max);
  const_chk (hash_extra);
  if error_line > ssup_error_line then error_line := ssup_error_line;

  {array memory allocation}
  buffer:=xmalloc_array (UnicodeScalar, buf_size);
  nest:=xmalloc_array (list_state_record, nest_size);
  save_stack:=xmalloc_array (memory_word, save_size);
  input_stack:=xmalloc_array (in_state_record, stack_size);
  input_file:=xmalloc_array (unicode_file, max_in_open);
  line_stack:=xmalloc_array (integer, max_in_open);
  eof_seen:=xmalloc_array (boolean, max_in_open);
  grp_stack:=xmalloc_array (save_pointer, max_in_open);
  if_stack:=xmalloc_array (pointer, max_in_open);
  source_filename_stack:=xmalloc_array (str_number, max_in_open);
  full_source_filename_stack:=xmalloc_array (str_number, max_in_open);
  param_stack:=xmalloc_array (halfword, param_size);
  dvi_buf:=xmalloc_array (eight_bits, dvi_buf_size);
  hyph_word :=xmalloc_array (str_number, hyph_size);
  hyph_list :=xmalloc_array (halfword, hyph_size);
  hyph_link :=xmalloc_array (hyph_pointer, hyph_size);
@+Init
  yzmem:=xmalloc_array (memory_word, mem_top - mem_bot + 1);
  zmem := yzmem - mem_bot;   {Some compilers require |mem_bot=0|}
  eqtb_top := eqtb_size+hash_extra;
  if hash_extra=0 then hash_top:=undefined_control_sequence else
        hash_top:=eqtb_top;
  yhash:=xmalloc_array (two_halves,1+hash_top-hash_offset);
  hash:=yhash - hash_offset;   {Some compilers require |hash_offset=0|}
  next(hash_base):=0; text(hash_base):=0;
  for hash_used:=hash_base+1 to hash_top do hash[hash_used]:=hash[hash_base];
  zeqtb:=xmalloc_array (memory_word, eqtb_top);
  eqtb:=zeqtb;

  str_start:=xmalloc_array (pool_pointer, max_strings);
  str_pool:=xmalloc_array (packed_ASCII_code, pool_size);
  font_info:=xmalloc_array (fmemory_word, font_mem_size);
@+Tini
@z

@x
@!init if not get_strings_started then goto final_end;
init_prim; {call |primitive| for each primitive}
init_str_ptr:=str_ptr; init_pool_ptr:=pool_ptr; fix_date_and_time;
tini@/
@y
@!Init if not get_strings_started then goto final_end;
init_prim; {call |primitive| for each primitive}
init_str_ptr:=str_ptr; init_pool_ptr:=pool_ptr; fix_date_and_time;
Tini@/
@z

@x
history:=spotless; {ready to go!}
@y
history:=spotless; {ready to go!}
@<Initialize synctex primitive@>
@z

@x
end_of_TEX: close_files_and_terminate;
final_end: ready_already:=0;
end.
@y
close_files_and_terminate;
final_end: do_final_end;
end {|main_body|};
@z

@x
procedure close_files_and_terminate;
@y
procedure close_files_and_terminate;
@z

@x
if log_opened then
@y
@<Close {\sl Sync\TeX} file and write status@>;
if log_opened then
@z

@x
    slow_print(log_name); print_char(".");
    end;
  end;
@y
    print(log_name); print_char(".");
    end;
  end;
print_ln;
if (edit_name_start<>0) and (interaction>batch_mode) then
  call_edit(str_pool,edit_name_start,edit_name_length,edit_line);
@z

@x
  wlog_ln(' ',cs_count:1,' multiletter control sequences out of ',
    hash_size:1);@/
@y
  wlog_ln(' ',cs_count:1,' multiletter control sequences out of ',
    hash_size:1, '+', hash_extra:1);@/
@z

@x
  begin @!init for c:=top_mark_code to split_bot_mark_code do
@y
  begin @!Init for c:=top_mark_code to split_bot_mark_code do
@z

@x
  store_fmt_file; return;@+tini@/
@y
  store_fmt_file; return;@+Tini@/
@z

@x
if (format_ident=0)or(buffer[loc]="&") then
@y
if (format_ident=0)or(buffer[loc]="&")or dump_line then
@z

@x
  w_close(fmt_file);
@y
  w_close(fmt_file);
  eqtb:=zeqtb;
@z

@x
fix_date_and_time;@/
@y
if mltex_enabled_p then
  begin wterm_ln('MLTeX v2.2 enabled');
  end;
fix_date_and_time;@/

@!init
if trie_not_ready then begin {initex without format loaded}
  trie_trl:=xmalloc_array (trie_pointer, trie_size);
  trie_tro:=xmalloc_array (trie_pointer, trie_size);
  trie_trc:=xmalloc_array (quarterword, trie_size);

  trie_c:=xmalloc_array (packed_ASCII_code, trie_size);
  trie_o:=xmalloc_array (trie_opcode, trie_size);
  trie_l:=xmalloc_array (trie_pointer, trie_size);
  trie_r:=xmalloc_array (trie_pointer, trie_size);
  trie_hash:=xmalloc_array (trie_pointer, trie_size);
  trie_taken:=xmalloc_array (boolean, trie_size);

  trie_root:=0; trie_c[0]:=si(0); trie_ptr:=0;
  hyph_root:=0; hyph_start:=0;

  {Allocate and initialize font arrays}
  font_mapping:=xmalloc_array(void_pointer, font_max);
  font_layout_engine:=xmalloc_array(void_pointer, font_max);
  font_flags:=xmalloc_array(char, font_max);
  font_letter_space:=xmalloc_array(scaled, font_max);
  font_check:=xmalloc_array(four_quarters, font_max);
  font_size:=xmalloc_array(scaled, font_max);
  font_dsize:=xmalloc_array(scaled, font_max);
  font_params:=xmalloc_array(font_index, font_max);
  font_name:=xmalloc_array(str_number, font_max);
  font_area:=xmalloc_array(str_number, font_max);
  font_bc:=xmalloc_array(UTF16_code, font_max);
  font_ec:=xmalloc_array(UTF16_code, font_max);
  font_glue:=xmalloc_array(halfword, font_max);
  hyphen_char:=xmalloc_array(integer, font_max);
  skew_char:=xmalloc_array(integer, font_max);
  bchar_label:=xmalloc_array(font_index, font_max);
  font_bchar:=xmalloc_array(nine_bits, font_max);
  font_false_bchar:=xmalloc_array(nine_bits, font_max);
  char_base:=xmalloc_array(integer, font_max);
  width_base:=xmalloc_array(integer, font_max);
  height_base:=xmalloc_array(integer, font_max);
  depth_base:=xmalloc_array(integer, font_max);
  italic_base:=xmalloc_array(integer, font_max);
  lig_kern_base:=xmalloc_array(integer, font_max);
  kern_base:=xmalloc_array(integer, font_max);
  exten_base:=xmalloc_array(integer, font_max);
  param_base:=xmalloc_array(integer, font_max);

  font_ptr:=null_font; fmem_ptr:=7;
  font_name[null_font]:="nullfont"; font_area[null_font]:="";
  hyphen_char[null_font]:="-"; skew_char[null_font]:=-1;
  bchar_label[null_font]:=non_address;
  font_bchar[null_font]:=non_char; font_false_bchar[null_font]:=non_char;
  font_bc[null_font]:=1; font_ec[null_font]:=0;
  font_size[null_font]:=0; font_dsize[null_font]:=0;
  char_base[null_font]:=0; width_base[null_font]:=0;
  height_base[null_font]:=0; depth_base[null_font]:=0;
  italic_base[null_font]:=0; lig_kern_base[null_font]:=0;
  kern_base[null_font]:=0; exten_base[null_font]:=0;
  font_glue[null_font]:=null; font_params[null_font]:=7;
  font_mapping[null_font]:=0;
  param_base[null_font]:=-1;
  for font_k:=0 to 6 do font_info[font_k].sc:=0;
  end;
  tini@/

  font_used:=xmalloc_array (boolean, font_max);
  for font_k:=font_base to font_max do font_used[font_k]:=false;
@z

@x
    begin goto breakpoint;@\ {go to every label at least once}
    breakpoint: m:=0; @{'BREAKPOINT'@}@\
    end
@y
    dump_core {do something to cause a core dump}
@z

@x
5: print_word(font_info[n]);
@y
5: begin print_scaled(font_info[n].sc); print_char(" ");@/
  print_int(font_info[n].qqqq.b0); print_char(":");@/
  print_int(font_info[n].qqqq.b1); print_char(":");@/
  print_int(font_info[n].qqqq.b2); print_char(":");@/
  print_int(font_info[n].qqqq.b3);
  end;
@z

@x
primitive("special",extension,special_node);@/
@y
primitive("special",extension,special_node);@/
text(frozen_special):="special"; eqtb[frozen_special]:=eqtb[cur_val];@/
@z

@x
var i,@!j,@!k:integer; {all-purpose integers}
@!p,@!q,@!r:pointer; {all-purpose pointers}
@y
var i,@!j,@!k:integer; {all-purpose integers}
@!p:pointer; {all-purpose pointers}
@z

@x
  else if cur_val>15 then cur_val:=16;
@y
  else if (cur_val>15) and (cur_val <> 18) then cur_val:=16;
@z

@x
begin @<Expand macros in the token list
@y
@!d:integer; {number of characters in incomplete current string}
@!clobbered:boolean; {system string is ok?}
@!runsystem_ret:integer; {return value from |runsystem|}
begin @<Expand macros in the token list
@z

@x
if write_open[j] then selector:=j
@y
if j=18 then selector := new_string
else if write_open[j] then selector:=j
@z

@x
flush_list(def_ref); selector:=old_setting;
@y
flush_list(def_ref);
if j=18 then
  begin if (tracing_online<=0) then
    selector:=log_only  {Show what we're doing in the log file.}
  else selector:=term_and_log;  {Show what we're doing.}
  {If the log file isn't open yet, we can only send output to the terminal.
   Calling |open_log_file| from here seems to result in bad data in the log.}
  if not log_opened then selector:=term_only;
  print_nl("runsystem(");
  for d:=0 to cur_length-1 do
    begin {|print| gives up if passed |str_ptr|, so do it by hand.}
    print(so(str_pool[str_start_macro(str_ptr)+d])); {N.B.: not |print_char|}
    end;
  print(")...");
  if shellenabledp then begin
    str_room(1); append_char(0); {Append a null byte to the expansion.}
    clobbered:=false;
    for d:=0 to cur_length-1 do {Convert to external character set.}
      begin
      if (str_pool[str_start_macro(str_ptr)+d]=null_code)
           and (d<cur_length-1) then clobbered:=true;
        {minimal checking: NUL not allowed in argument string of |system|()}
      end;
    if clobbered then print("clobbered")
    else begin {We have the command.  See if we're allowed to execute it,
         and report in the log.  We don't check the actual exit status of
         the command, or do anything with the output.}
      if name_of_file then libc_free(name_of_file);
      name_of_file := xmalloc(cur_length * 3 + 2);
      k := 0;
      for d:=0 to cur_length-1 do
        append_to_name(str_pool[str_start_macro(str_ptr)+d]);
      name_of_file[k+1] := 0;
      runsystem_ret := runsystem(conststringcast(name_of_file+1));
      if runsystem_ret = -1 then print("quotation error in system command")
      else if runsystem_ret = 0 then print("disabled (restricted)")
      else if runsystem_ret = 1 then print("executed")
      else if runsystem_ret = 2 then print("executed safely (allowed)")
    end;
  end else begin
    print("disabled"); {|shellenabledp| false}
  end;
  print_char("."); print_nl(""); print_ln;
  pool_ptr:=str_start_macro(str_ptr);  {erase the string}
end;
selector:=old_setting;
@z

@x
procedure out_what(@!p:pointer);
var j:small_number; {write stream number}
@y
procedure out_what(@!p:pointer);
var j:small_number; {write stream number}
    @!old_setting:0..max_selector;
@z

@x
      while not a_open_out(write_file[j]) do
        prompt_file_name("output file name",".tex");
      write_open[j]:=true;
@y
      while not kpse_out_name_ok(stringcast(name_of_file+1))
            or not a_open_out(write_file[j]) do
        prompt_file_name("output file name",".tex");
      write_open[j]:=true;
      {If on first line of input, log file is not ready yet, so don't log.}
      if log_opened then begin
        old_setting:=selector;
        if (tracing_online<=0) then
          selector:=log_only  {Show what we're doing in the log file.}
        else selector:=term_and_log;  {Show what we're doing.}
        print_nl("\openout");
        print_int(j);
        print(" = `");
        print_file_name(cur_name,cur_area,cur_ext);
        print("'."); print_nl(""); print_ln;
        selector:=old_setting;
      end;
@z

@x
@!init if (buffer[loc]="*")and(format_ident=" (INITEX)") then
@y
@!init if (etex_p or(buffer[loc]="*"))and(format_ident=" (INITEX)") then
@z

@x
  incr(loc); eTeX_mode:=1; {enter extended mode}
@y
  if buffer[loc]="*" then incr(loc);
  eTeX_mode:=1; {enter extended mode}
@z

@x
@!eTeX_mode: 0..1; {identifies compatibility and extended mode}
@y
@!eTeX_mode: 0..1; {identifies compatibility and extended mode}
@!etex_p: boolean; {was the -etex option specified}
@z

@x
@!eof_seen : array[1..max_in_open] of boolean; {has eof been seen?}
@y
@!eof_seen : ^boolean; {has eof been seen?}
@z

@x
@<Reverse the complete hlist...@>=
begin save_h:=cur_h; temp_ptr:=p; p:=new_kern(0); link(prev_p):=p;
@y
@<Reverse the complete hlist...@>=
begin save_h:=cur_h; temp_ptr:=p; p:=new_kern(0);
sync_tag(p+medium_node_size):=0; {{\sl Sync\TeX}: do nothing, it is too late}
link(prev_p):=p;
@z

@x
@<Reverse an hlist segment...@>=
begin save_h:=cur_h; temp_ptr:=link(p); rule_wd:=width(p);
free_node(p,small_node_size);
@y
@<Reverse an hlist segment...@>=
begin save_h:=cur_h; temp_ptr:=link(p); rule_wd:=width(p);
free_node(p,medium_node_size); {{\sl Sync\TeX}: p is a |math_node|}
@z

@x
if type(p)=kern_node then if (rule_wd=0)or(l=null) then
  begin free_node(p,small_node_size); p:=l;
  end;
@y
if type(p)=kern_node then if (rule_wd=0)or(l=null) then
  begin free_node(p,medium_node_size); p:=l;
  end;
@z

@x
@<Finish the reversed...@>=
begin free_node(p,small_node_size);
link(t):=q; width(t):=rule_wd; edge_dist(t):=-cur_h-rule_wd; goto done;
end
@y
@<Finish the reversed...@>=
begin free_node(p,medium_node_size); {{\sl Sync\TeX}: p is a |kern_node|}
link(t):=q; width(t):=rule_wd; edge_dist(t):=-cur_h-rule_wd; goto done;
end
@z

@x
  hlist_node,vlist_node: begin r:=get_node(box_node_size);
@y
  hlist_node,vlist_node: begin r:=get_node(box_node_size);
    @<Copy the box {\sl Sync\TeX} information@>;
@z

@x
  kern_node,math_node: begin r:=get_node(small_node_size);
    words:=small_node_size;
    end;
  glue_node: begin r:=get_node(small_node_size); add_glue_ref(glue_ptr(p));
    glue_ptr(r):=glue_ptr(p); leader_ptr(r):=null;
    end;
@y
  kern_node,math_node: begin
      words:=medium_node_size; {{\sl Sync\TeX}: proper size for math and kern}
      r:=get_node(words);
    end;
  glue_node: begin r:=get_node(medium_node_size); add_glue_ref(glue_ptr(p));
                                                 {{\sl Sync\TeX}: proper size for glue}
    @<Copy the medium sized node {\sl Sync\TeX} information@>;
    glue_ptr(r):=glue_ptr(p); leader_ptr(r):=null;
    end;
@z

@x
procedure just_reverse(@!p:pointer);
label found,done;
@y
procedure just_reverse(@!p:pointer);
label done;
@z

@x
found:width(t):=width(p); link(t):=q; free_node(p,small_node_size);
@y
width(t):=width(p); link(t):=q; free_node(p,small_node_size);
@z

@x
    begin type(p):=kern_node; incr(LR_problems);
    end
  else  begin pop_LR;
    if n>min_halfword then
      begin decr(n); decr(subtype(p)); {change |after| into |before|}
      end
    else  begin if m>min_halfword then decr(m)@+else goto found;
      type(p):=kern_node;
      end;
    end
else  begin push_LR(p);
  if (n>min_halfword)or(LR_dir(p)<>cur_dir) then
    begin incr(n); incr(subtype(p)); {change |before| into |after|}
    end
  else  begin type(p):=kern_node; incr(m);
    end;
  end
@y
    begin type(p):=kern_node; incr(LR_problems);
        {{\sl Sync\TeX} node size watch point: |math_node| size == |kern_node| size}
    end
  else  begin pop_LR;
    if n>min_halfword then
      begin decr(n); decr(subtype(p)); {change |after| into |before|}
      end
    else  begin if m>min_halfword then decr(m)@+else begin
    width(t):=width(p); link(t):=q; free_node(p,medium_node_size);
{{\sl Sync\TeX}: no more "goto found", and proper node size}
    goto done;
  end;
  type(p):=kern_node;
            {{\sl Sync\TeX} node size watch point: |math_node| size == |kern_node| size}
      end;
    end
else  begin push_LR(p);
  if (n>min_halfword)or(LR_dir(p)<>cur_dir) then
    begin incr(n); incr(subtype(p)); {change |before| into |after|}
    end
  else  begin type(p):=kern_node; incr(m);
            {{\sl Sync\TeX} node size watch point: |math_node| size == |kern_node| size}
    end;
  end
@z

@x
  name:=19; print("( "); incr(open_parens); update_terminal;
  end
else name:=18
@y
  name:=19; print("( "); incr(open_parens); update_terminal;
  end
else begin
    name:=18;
    @<Prepare pseudo file {\sl Sync\TeX} information@>;
end
@z

@x
@!grp_stack : array[0..max_in_open] of save_pointer; {initial |cur_boundary|}
@!if_stack : array[0..max_in_open] of pointer; {initial |cond_ptr|}
@y
@!grp_stack : ^save_pointer; {initial |cur_boundary|}
@!if_stack : ^pointer; {initial |cond_ptr|}
@z

@x
@* \[54] System-dependent changes.
@y
@* \[54/web2c] System-dependent changes for Web2c.
Here are extra variables for Web2c.  (This numbering of the
system-dependent section allows easy integration of Web2c and e-\TeX, etc.)
@^<system dependencies@>

@<Glob...@>=
@!edit_name_start: pool_pointer; {where the filename to switch to starts}
@!edit_name_length,@!edit_line: integer; {what line to start editing at}
@!ipc_on: cinttype; {level of IPC action, 0 for none [default]}
@!stop_at_space: boolean; {whether |more_name| returns false for space}

@ The |edit_name_start| will be set to point into |str_pool| somewhere after
its beginning if \TeX\ is supposed to switch to an editor on exit.

@<Set init...@>=
edit_name_start:=0;
stop_at_space:=true;

@ These are used when we regenerate the representation of the first 256
strings.

@<Global...@> =
@!save_str_ptr: str_number;
@!save_pool_ptr: pool_pointer;
@!shellenabledp: cinttype;
@!restrictedshell: cinttype;
@!output_comment: ^char;
@!k,l: 0..255; {used by `Make the first 256 strings', etc.}

@ When debugging a macro package, it can be useful to see the exact
control sequence names in the format file.  For example, if ten new
csnames appear, it's nice to know what they are, to help pinpoint where
they came from.  (This isn't a truly ``basic'' printing procedure, but
that's a convenient module in which to put it.)

@<Basic printing procedures@> =
procedure print_csnames (hstart:integer; hfinish:integer);
var c,h:integer;
begin
  write_ln(stderr, 'fmtdebug:csnames from ', hstart, ' to ', hfinish, ':');
  for h := hstart to hfinish do begin
    if text(h) > 0 then begin {if have anything at this position}
      for c := str_start_macro(text(h)) to str_start_macro(text(h) + 1) - 1
      do begin
        put_byte(str_pool[c], stderr); {print the characters}
      end;
      write_ln(stderr, '|');
    end;
  end;
end;

@ Are we printing extra info as we read the format file?

@<Glob...@> =
@!debug_format_file: boolean;


@ A helper for printing file:line:error style messages.  Look for a
filename in |full_source_filename_stack|, and if we fail to find
one fall back on the non-file:line:error style.

@<Basic print...@>=
procedure print_file_line;
var level: 0..max_in_open;
begin
  level:=in_open;
  while (level>0) and (full_source_filename_stack[level]=0) do
    decr(level);
  if level=0 then
    print_nl("! ")
  else begin
    print_nl (""); print (full_source_filename_stack[level]); print (":");
    if level=in_open then print_int (line)
    else print_int (line_stack[level+1]);
    print (": ");
  end;
end;

@ To be able to determine whether \.{\\write18} is enabled from within
\TeX\ we also implement \.{\\eof18}.  We sort of cheat by having an
additional route |scan_four_bit_int_or_18| which is the same as
|scan_four_bit_int| except it also accepts the value 18.

@<Declare procedures that scan restricted classes of integers@>=
procedure scan_four_bit_int_or_18;
begin scan_int;
if (cur_val<0)or((cur_val>15)and(cur_val<>18)) then
  begin print_err("Bad number");
@.Bad number@>
  help2("Since I expected to read a number between 0 and 15,")@/
    ("I changed this one to zero."); int_error(cur_val); cur_val:=0;
  end;
end;

@* \[54/web2c-string] The string recycling routines.
\TeX{} uses 2 upto 4 {\it new\/} strings when scanning a filename in an
\.{\\input}, \.{\\openin}, or \.{\\openout} operation.  These strings are
normally lost because the reference to them are not saved after finishing
the operation.  |search_string| searches through the string pool for the
given string and returns either 0 or the found string number.

@<Declare additional routines for string recycling@>=
function search_string(@!search:str_number):str_number;
label found;
var result: str_number;
@!s: str_number; {running index}
@!len: integer; {length of searched string}
begin result:=0; len:=length(search);
if len=0 then  {trivial case}
  begin result:=""; goto found;
  end
else  begin s:=search-1;  {start search with newest string below |s|; |search>1|!}
  while s>65535 do  {first 64K strings don't really exist in the pool!}
    begin if length(s)=len then
      if str_eq_str(s,search) then
        begin result:=s; goto found;
        end;
    decr(s);
    end;
  end;
found:search_string:=result;
end;

@ The following routine is a variant of |make_string|.  It searches
the whole string pool for a string equal to the string currently built
and returns a found string.  Otherwise a new string is created and
returned.  Be cautious, you can not apply |flush_string| to a replaced
string!

@<Declare additional routines for string recycling@>=
function slow_make_string : str_number;
label exit;
var s: str_number; {result of |search_string|}
@!t: str_number; {new string}
begin t:=make_string; s:=search_string(t);
if s>0 then
  begin flush_string; slow_make_string:=s; return;
  end;
slow_make_string:=t;
exit:end;


@* \[54/ML\TeX] System-dependent changes for ML\TeX.

The boolean variable |mltex_p| is set by web2c according to the given
command line option (or an entry in the configuration file) before any
\TeX{} function is called.

@<Global...@> =
@!mltex_p: boolean;

@ The boolean variable |mltex_enabled_p| is used to enable ML\TeX's
character substitution.  It is initialised to |false|.  When loading
a \.{FMT} it is set to the value of the boolean |mltex_p| saved in
the \.{FMT} file.  Additionally it is set to the value of |mltex_p|
in Ini\TeX.

@<Glob...@>=
@!mltex_enabled_p:boolean;  {enable character substitution}
@!native_font_type_flag:integer; {used by XeTeX font loading code to record which font technology was used}
@!xtx_ligature_present:boolean; {to suppress tfm font mapping of char codes from ligature nodes (already mapped)}


@ @<Set init...@>=
mltex_enabled_p:=false;


@ The function |effective_char| computes the effective character with
respect to font information.  The effective character is either the
base character part of a character substitution definition, if the
character does not exist in the font or the character itself.

Inside |effective_char| we can not use |char_info| because the macro
|char_info| uses |effective_char| calling this function a second time
with the same arguments.

If neither the character |c| exists in font |f| nor a character
substitution for |c| was defined, you can not use the function value
as a character offset in |char_info| because it will access an
undefined or invalid |font_info| entry!  Therefore inside |char_info|
and in other places, |effective_char|'s boolean parameter |err_p| is
set to |true| to issue a warning and return the incorrect
replacement, but always existing character |font_bc[f]|.
@^inner loop@>

@<Declare \eTeX\ procedures for sc...@>=
function effective_char(@!err_p:boolean;
                        @!f:internal_font_number;@!c:quarterword):integer;
label found;
var base_c: integer; {or |eightbits|: replacement base character}
@!result: integer; {or |quarterword|}
begin if (not xtx_ligature_present) and (font_mapping[f]<>nil) then
  c:=apply_tfm_font_mapping(font_mapping[f],c);
xtx_ligature_present:=false;
result:=c;  {return |c| unless it does not exist in the font}
if not mltex_enabled_p then goto found;
if font_ec[f]>=qo(c) then if font_bc[f]<=qo(c) then
  if char_exists(orig_char_info(f)(c)) then  {N.B.: not |char_info|(f)(c)}
    goto found;
if qo(c)>=char_sub_def_min then if qo(c)<=char_sub_def_max then
  if char_list_exists(qo(c)) then
    begin base_c:=char_list_char(qo(c));
    result:=qi(base_c);  {return |base_c|}
    if not err_p then goto found;
    if font_ec[f]>=base_c then if font_bc[f]<=base_c then
      if char_exists(orig_char_info(f)(qi(base_c))) then goto found;
    end;
if err_p then  {print error and return existing character?}
  begin begin_diagnostic;
  print_nl("Missing character: There is no "); print("substitution for ");
@.Missing character@>
  print_ASCII(qo(c)); print(" in font ");
  slow_print(font_name[f]); print_char("!"); end_diagnostic(false);
  result:=qi(font_bc[f]); {N.B.: not non-existing character |c|!}
  end;
found: effective_char:=result;
end;


@ The function |effective_char_info| is equivalent to |char_info|,
except it will return |null_character| if neither the character |c|
exists in font |f| nor is there a substitution definition for |c|.
(For these cases |char_info| using |effective_char| will access an
undefined or invalid |font_info| entry.  See the documentation of
|effective_char| for more information.)
@^inner loop@>

@<Declare additional functions for ML\TeX@>=
function effective_char_info(@!f:internal_font_number;
                             @!c:quarterword):four_quarters;
label exit;
var ci:four_quarters; {character information bytes for |c|}
@!base_c:integer; {or |eightbits|: replacement base character}
begin if (not xtx_ligature_present) and (font_mapping[f]<>nil) then
  c:=apply_tfm_font_mapping(font_mapping[f],c);
xtx_ligature_present:=false;
if not mltex_enabled_p then
  begin effective_char_info:=orig_char_info(f)(c); return;
  end;
if font_ec[f]>=qo(c) then if font_bc[f]<=qo(c) then
  begin ci:=orig_char_info(f)(c);  {N.B.: not |char_info|(f)(c)}
  if char_exists(ci) then
    begin effective_char_info:=ci; return;
    end;
  end;
if qo(c)>=char_sub_def_min then if qo(c)<=char_sub_def_max then
  if char_list_exists(qo(c)) then
    begin {|effective_char_info:=char_info(f)(qi(char_list_char(qo(c))));|}
    base_c:=char_list_char(qo(c));
    if font_ec[f]>=base_c then if font_bc[f]<=base_c then
      begin ci:=orig_char_info(f)(qi(base_c));  {N.B.: not |char_info|(f)(c)}
      if char_exists(ci) then
        begin effective_char_info:=ci; return;
        end;
      end;
    end;
effective_char_info:=null_character;
exit:end;
@#
@<Declare subroutines for |new_character|@>@;


@ This code is called for a virtual character |c| in |hlist_out|
during |ship_out|.  It tries to built a character substitution
construct for |c| generating appropriate \.{DVI} code using the
character substitution definition for this character.  If a valid
character substitution exists \.{DVI} code is created as if
|make_accent| was used.  In all other cases the status of the
substituion for this character has been changed between the creation
of the character node in the hlist and the output of the page---the
created \.{DVI} code will be correct but the visual result will be
undefined.

Former ML\TeX\ versions have replaced the character node by a
sequence of character, box, and accent kern nodes splicing them into
the original horizontal list.  This version does not do this to avoid
a)~a memory overflow at this processing stage, b)~additional code to
add a pointer to the previous node needed for the replacement, and
c)~to avoid wrong code resulting in anomalies because of the use
within a \.{\\leaders} box.

@<Output a substitution, |goto continue| if not possible@>=
  begin
  @<Get substitution information, check it, goto |found|
  if all is ok, otherwise goto |continue|@>;
found: @<Print character substition tracing log@>;
  @<Rebuild character using substitution information@>;
  end


@ The global variables for the code to substitute a virtual character
can be declared as local.  Nonetheless we declare them as global to
avoid stack overflows because |hlist_out| can be called recursivly.

@<Glob...@>=
@!accent_c,@!base_c,@!replace_c:integer;
@!ia_c,@!ib_c:four_quarters; {accent and base character information}
@!base_slant,@!accent_slant:real; {amount of slant}
@!base_x_height:scaled; {accent is designed for characters of this height}
@!base_width,@!base_height:scaled; {height and width for base character}
@!accent_width,@!accent_height:scaled; {height and width for accent}
@!delta:scaled; {amount of right shift}


@ Get the character substitution information in |char_sub_code| for
the character |c|.  The current code checks that the substition
exists and is valid and all substitution characters exist in the
font, so we can {\it not\/} substitute a character used in a
substitution.  This simplifies the code because we have not to check
for cycles in all character substitution definitions.

@<Get substitution information, check it...@>=
  if qo(c)>=char_sub_def_min then if qo(c)<=char_sub_def_max then
    if char_list_exists(qo(c)) then
      begin  base_c:=char_list_char(qo(c));
      accent_c:=char_list_accent(qo(c));
      if (font_ec[f]>=base_c) then if (font_bc[f]<=base_c) then
        if (font_ec[f]>=accent_c) then if (font_bc[f]<=accent_c) then
          begin ia_c:=char_info(f)(qi(accent_c));
          ib_c:=char_info(f)(qi(base_c));
          if char_exists(ib_c) then
            if char_exists(ia_c) then goto found;
          end;
      begin_diagnostic;
      print_nl("Missing character: Incomplete substitution ");
@.Missing character@>
      print_ASCII(qo(c)); print(" = "); print_ASCII(accent_c);
      print(" "); print_ASCII(base_c); print(" in font ");
      slow_print(font_name[f]); print_char("!"); end_diagnostic(false);
      goto continue;
      end;
  begin_diagnostic;
  print_nl("Missing character: There is no "); print("substitution for ");
@.Missing character@>
  print_ASCII(qo(c)); print(" in font ");
  slow_print(font_name[f]); print_char("!"); end_diagnostic(false);
  goto continue


@ For |tracinglostchars>99| the substitution is shown in the log file.

@<Print character substition tracing log@>=
 if tracing_lost_chars>99 then
   begin begin_diagnostic;
   print_nl("Using character substitution: ");
   print_ASCII(qo(c)); print(" = ");
   print_ASCII(accent_c); print(" "); print_ASCII(base_c);
   print(" in font "); slow_print(font_name[f]); print_char(".");
   end_diagnostic(false);
   end


@ This outputs the accent and the base character given in the
substitution.  It uses code virtually identical to the |make_accent|
procedure, but without the node creation steps.

Additionally if the accent character has to be shifted vertically it
does {\it not\/} create the same code.  The original routine in
|make_accent| and former versions of ML\TeX{} creates a box node
resulting in |push| and |pop| operations, whereas this code simply
produces vertical positioning operations.  This can influence the
pixel rounding algorithm in some \.{DVI} drivers---and therefore will
probably be changed in one of the next ML\TeX{} versions.

@<Rebuild character using substitution information@>=
  base_x_height:=x_height(f);
  base_slant:=slant(f)/float_constant(65536);
@^real division@>
  accent_slant:=base_slant; {slant of accent character font}
  base_width:=char_width(f)(ib_c);
  base_height:=char_height(f)(height_depth(ib_c));
  accent_width:=char_width(f)(ia_c);
  accent_height:=char_height(f)(height_depth(ia_c));
  @/{compute necessary horizontal shift (don't forget slant)}@/
  delta:=round((base_width-accent_width)/float_constant(2)+
            base_height*base_slant-base_x_height*accent_slant);
@^real multiplication@>
@^real addition@>
  dvi_h:=cur_h;  {update |dvi_h|, similar to the last statement in module 620}
  @/{1. For centering/horizontal shifting insert a kern node.}@/
  cur_h:=cur_h+delta; synch_h;
  @/{2. Then insert the accent character possibly shifted up or down.}@/
  if ((base_height<>base_x_height) and (accent_height>0)) then
    begin {the accent must be shifted up or down}
    cur_v:=base_line+(base_x_height-base_height); synch_v;
    if accent_c>=128 then dvi_out(set1);
    dvi_out(accent_c);@/
    cur_v:=base_line;
    end
  else begin synch_v;
    if accent_c>=128 then dvi_out(set1);
    dvi_out(accent_c);@/
    end;
  cur_h:=cur_h+accent_width; dvi_h:=cur_h;
  @/{3. For centering/horizontal shifting insert another kern node.}@/
  cur_h:=cur_h+(-accent_width-delta);
  @/{4. Output the base character.}@/
  synch_h; synch_v;
  if base_c>=128 then dvi_out(set1);
  dvi_out(base_c);@/
  cur_h:=cur_h+base_width;
  dvi_h:=cur_h {update of |dvi_h| is unnecessary, will be set in module 620}

@ Dumping ML\TeX-related material.  This is just the flag in the
format that tells us whether ML\TeX{} is enabled.

@<Dump ML\TeX-specific data@>=
dump_int(@"4D4C5458);  {ML\TeX's magic constant: "MLTX"}
if mltex_p then dump_int(1)
else dump_int(0);

@ Undump ML\TeX-related material, which is just a flag in the format
that tells us whether ML\TeX{} is enabled.

@<Undump ML\TeX-specific data@>=
undump_int(x);   {check magic constant of ML\TeX}
if x<>@"4D4C5458 then goto bad_fmt;
undump_int(x);   {undump |mltex_p| flag into |mltex_enabled_p|}
if x=1 then mltex_enabled_p:=true
else if x<>0 then goto bad_fmt;


@* \[54/SyncTeX] The {\sl Synchronize \TeX nology}.
This section is devoted to the {\sl Synchronize \TeX nology}
- or simply {\sl Sync\TeX} - used to synchronize between input and output.
This section explains how synchronization basics are implemented.
Before we enter into more technical details,
let us recall in a few words what is synchronization.

\TeX\ typesetting system clearly separates the input and the output material,
and synchronization will provide a new link between both that can help
text editors and viewers to work together.
More precisely, forwards synchronization is the ability,
given a location in the input source file,
to find what is the corresponding place in the output.
Backwards synchronization just performs the opposite:
given a location in the output,
retrieve the corresponding material in the input source file.

For better code management and maintainance, we adopt a naming convention.
Throughout this program, code related to the {\sl Synchronize \TeX nology} is tagged
with the ``{\sl synctex}'' key word. Any code extract where {\sl Sync\TeX} plays
its part, either explicitly or implicitly, (should) contain the string ``{\sl synctex}''.
This naming convention also holds for external files.
Moreover, all the code related to {\sl Sync\TeX} is gathered in this section,
except the definitions.

@ Enabling synchronization should be performed from the command line,
|synctexoption| is used for that purpose.
This global integer variable is declared here but it is not used here.
This is just a placeholder where the command line controller will put
the {\sl Sync\TeX} related options, and the {\sl Sync\TeX} controller will read them.

@ @<Glob...@>=
@!synctexoption:integer;

@ A convenient primitive is provided:
\.{\\synctex=1} in the input source file enables synchronization whereas
\.{\\synctex=0} disables it.
Its memory address is |synctex_code|.
It is initialized by the {\sl Sync\TeX} controller to the command-line option if given.
The controller may filter some reserved bits.

@ @<Put each...@>=
primitive("synctex",assign_int,int_base+synctex_code);@/
@!@:synctex_}{\.{\\synctex} primitive@>

@ @<synctex case for |print_param|@>=
synctex_code:    print_esc("synctex");

@ In order to give the {\sl Sync\TeX} controller read and write access to
the contents of the \.{\\synctex} primitive, we declare |synctexoffset|,
such that |mem[synctexoffset]| and \.{\\synctex} correspond to
the same memory storage. |synctexoffset| is initialized to
the correct value when quite everything is initialized.

@ @<Glob...@>=
@!synctexoffset:integer; {holds the true value of |synctex_code|}

@ @<Initialize whatever...@>=
synctexoffset:=int_base+synctex_code;

@ @<Initialize synctex primitive@>=
synctex_init_command;

@ Synchronization is achieved with the help of an auxiliary file named
`\.{{\sl jobname}.synctex}' ({\sl jobname} is the contents of the
\.{\\jobname} macro), where a {\sl Sync\TeX} controller implemented
in the external |synctex.c| file will store geometrical information.
This {\sl Sync\TeX} controller will take care of every technical details
concerning the {\sl Sync\TeX} file, we will only focus on the messages
the controller will receive from the \TeX\ program.

The most accurate synchronization information should allow to map
any character of the input source file to the corresponding location
in the output, if relevant.
Ideally, the synchronization information of the input material consists of
the file name, the line and column numbers of every character.
The synchronization information in the output is simply the page number and
either point coordinates, or box dimensions and position.
The problem is that the mapping between these informations is only known at
ship out time, which means that we must keep track of the input
synchronization information until the pages ship out.

As \TeX\ only knows about file names and line numbers,
but forgets the column numbers, we only consider a
restricted input synchronization information called {\sl Sync\TeX\ information}.
It consists of a unique file name identifier, the {\sl Sync\TeX\ file tag},
and the line number.

Keeping track of such information,
should be different whether characters or nodes are involved.
Actually, only certain nodes are involved in {\sl Sync\TeX},
we call them {\sl synchronized nodes}.
Synchronized nodes store the {\sl Sync\TeX} information in their last two words:
the first one contains a {\sl Sync\TeX\ file tag} uniquely identifying
the input file, and the second one contains the current line number,
as returned by the \.{\\inputlineno} primitive.
The |synctex_field_size| macro contains the necessary size to store
the {\sl Sync\TeX} information in a node.

When declaring the size of a new node, it is recommanded to use the following
convention: if the node is synchronized, use a definition similar to
|my_synchronized_node_size|={\sl xxx}+|synctex_field_size|.
Moreover, one should expect that the {\sl Sync\TeX} information is always stored
in the last two words of a synchronized node.

@ By default, every node with a sufficiently big size is initialized
at creation time in the |get_node| routine with the current
{\sl Sync\TeX} information, whether or not the node is synchronized.
One purpose is to set this information very early in order to minimize code
dependencies, including forthcoming extensions.
Another purpose is to avoid the assumption that every node type has a dedicated getter,
where initialization should take place. Actually, it appears that some nodes are created
using directly the |get_node| routine and not the dedicated constructor.
And finally, initializing the node at only one place is less error prone.

@ @<Initialize bigger nodes with {\sl Sync\TeX} information@>=
if s>=medium_node_size then
begin
  sync_tag(r+s):=synctex_tag;
  sync_line(r+s):=line;
end;

@ Instead of storing the input file name, it is better to store just an identifier.
Each time \TeX\ opens a new file, it notifies the {\sl Sync\TeX} controller with
a |synctex_start_input| message.
This controller will create a new {\sl Sync\TeX} file tag and
will update the current input state record accordingly.
If the input comes from the terminal or a pseudo file, the |synctex_tag| is set to 0.
It results in automatically disabling synchronization for material
input from the terminal or pseudo files.

@ @<Prepare new file {\sl Sync\TeX} information@>=
synctex_start_input; {Give control to the {\sl Sync\TeX} controller}

@ @<Prepare terminal input {\sl Sync\TeX} information@>=
synctex_tag:=0;

@ @<Prepare pseudo file {\sl Sync\TeX} information@>=
synctex_tag:=0;

@ @<Close {\sl Sync\TeX} file and write status@>=
synctex_terminate(log_opened); {Let the {\sl Sync\TeX} controller close its files.}

@ Synchronized nodes are boxes, math, kern and glue nodes.
Other nodes should be synchronized too, in particular math noads.
\TeX\ assumes that math, kern and glue nodes have the same size,
this is why both are synchronized.
{\sl In fine}, only horizontal lists are really used in {\sl Sync\TeX},
but all box nodes are considered the same with respect to synchronization,
because a box node type is allowed to change at execution time.

The next sections are the various messages sent to the {\sl Sync\TeX} controller.
The argument is either the box or the node currently shipped out.
The vertical boxes are not recorded, but the code is available for clients.

@ @<Start sheet {\sl Sync\TeX} information record@>=
synctex_sheet(mag);

@ @<Finish sheet {\sl Sync\TeX} information record@>=
synctex_teehs;

@ @<Start vlist {\sl Sync\TeX} information record@>=
synctex_vlist(this_box);

@ @<Finish vlist {\sl Sync\TeX} information record@>=
synctex_tsilv(this_box);

@ @<Start hlist {\sl Sync\TeX} information record@>=
synctex_hlist(this_box);

@ @<Finish hlist {\sl Sync\TeX} information record@>=
synctex_tsilh(this_box);

@ @<Record void list {\sl Sync\TeX} information@>=
  if type(p)=vlist_node then begin
      synctex_void_vlist(p,this_box);
    end
  else begin
      synctex_void_hlist(p,this_box);
    end;

@ @<Record current point {\sl Sync\TeX} information@>=
synctex_current;

@ @<Record horizontal |rule_node| or |glue_node| {\sl Sync\TeX} information@>=
synctex_horizontal_rule_or_glue(p,this_box);

@ @<Record |kern_node| {\sl Sync\TeX} information@>=
synctex_kern(p,this_box);

@ @<Record |math_node| {\sl Sync\TeX} information@>=
synctex_math(p,this_box);

@ When making a copy of a synchronized node, we might also have to duplicate
the {\sl Sync\TeX} information by copying the two last words.
This is the case for a |box_node| and for a |glue_node|,
but not for a |math_node| nor a |kern_node|. These last two nodes always keep
the {\sl Sync\TeX} information they received at creation time.

@ @<Copy the box {\sl Sync\TeX} information@>=
sync_tag(r+box_node_size):=sync_tag(p+box_node_size);
sync_line(r+box_node_size):=sync_line(p+box_node_size);

@ @<Copy the rule {\sl Sync\TeX} information@>=
{sync_tag(r+rule_node_size):=sync_tag(p+rule_node_size);
sync_line(r+rule_node_size):=sync_line(p+rule_node_size);}

@ @<Copy the medium sized node {\sl Sync\TeX} information@>=
sync_tag(r+medium_node_size):=sync_tag(p+medium_node_size);
sync_line(r+medium_node_size):=sync_line(p+medium_node_size);

@ {\sl Nota Bene:}
The {\sl Sync\TeX} code is very close to the memory model.
It is not connected to any other part of the code,
except for memory management. It is possible to neutralize the {\sl Sync\TeX} code
rather simply. The first step is to define a null |synctex_field_size|.
The second step is to comment out the code in ``Initialize bigger nodes...'' and every
``Copy ... {\sl Sync\TeX} information''.
The last step will be to comment out the |synctex_tag_field| related code in the
definition of |synctex_tag| and the various ``Prepare ... {\sl Sync\TeX} information''.
Then all the remaining code should be just harmless.
The resulting program would behave exactly the same as if absolutely no {\sl Sync\TeX}
related code was there, including memory management.
Of course, all this assumes that {\sl Sync\TeX} is turned off from the command line.
@^synctex@>
@^synchronization@>

@* \[54] System-dependent changes.
@z

@x
@* \[55] Index.
@y

@ @<Declare action procedures for use by |main_control|@>=

procedure insert_src_special;
var toklist, p, q : pointer;
begin
  if (source_filename_stack[in_open] > 0 and is_new_source (source_filename_stack[in_open]
, line)) then begin
    toklist := get_avail;
    p := toklist;
    info(p) := cs_token_flag+frozen_special;
    link(p) := get_avail; p := link(p);
    info(p) := left_brace_token+"{";
    q := str_toks (make_src_special (source_filename_stack[in_open], line));
    link(p) := link(temp_head);
    p := q;
    link(p) := get_avail; p := link(p);
    info(p) := right_brace_token+"}";
    ins_list (toklist);
    remember_source_info (source_filename_stack[in_open], line);
  end;
end;

procedure append_src_special;
var q : pointer;
begin
  if (source_filename_stack[in_open] > 0 and is_new_source (source_filename_stack[in_open]
, line)) then begin
    new_whatsit (special_node, write_node_size);
    write_stream(tail) := 0;
    def_ref := get_avail;
    token_ref_count(def_ref) := null;
    q := str_toks (make_src_special (source_filename_stack[in_open], line));
    link(def_ref) := link(temp_head);
    write_tokens(tail) := def_ref;
    remember_source_info (source_filename_stack[in_open], line);
  end;
end;

@ This function used to be in pdftex, but is useful in tex too.

@p function get_nullstr: str_number;
begin
    get_nullstr := "";
end;

@* \[55] Index.
@z

