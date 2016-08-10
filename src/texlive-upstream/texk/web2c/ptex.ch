@x
@d banner==TeX_banner
@d banner_k==TeX_banner_k
@y
@d pTeX_version_string=='-p3.7.1' {current p\TeX\ version}
@#
@d pTeX_banner=='This is pTeX, Version 3.14159265',pTeX_version_string
@d pTeX_banner_k==pTeX_banner
  {printed when p\TeX\ starts}
@#
@d banner==pTeX_banner
@d banner_k==pTeX_banner_k
@z

@x
@!ASCII_code=0..255; {eight-bit numbers}
@y
@!ASCII_code=0..255; {eight-bit numbers}
@!KANJI_code=0..65535; {sixteen-bit numbers}
@z

@x
@!eight_bits=0..255; {unsigned one-byte quantity}
@y
@!eight_bits=0..255; {unsigned one-byte quantity}
@!sixteen_bits=0..65535; {unsigned two-bytes quantity}
@z

@x
@ All of the file opening functions are defined in C.
@y
@ All of the file opening functions are defined in C.

@ Kanji code handling.
@z

@x
@!init function get_strings_started:boolean; {initializes the string pool,
  but returns |false| if something goes wrong}
label done,exit;
var k,@!l:0..255; {small indices or counters}
@y
@!init function get_strings_started:boolean; {initializes the string pool,
  but returns |false| if something goes wrong}
label done,exit;
var k,@!l:KANJI_code; {small indices or counters}
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
@<Character |k| cannot be printed@>=
  (k<" ")or(k>"~")
@y
@<Character |k| cannot be printed@>=
   not (ismultiprn(k) or xprn[k])
@z

@x
@ @d bad_pool(#)==begin wake_up_terminal; write_ln(term_out,#);
  a_close(pool_file); get_strings_started:=false; return;
  end
@<Read the other strings...@>=
name_length := strlen (pool_name);
name_of_file := xmalloc_array (ASCII_code, name_length + 1);
strcpy (stringcast(name_of_file+1), pool_name); {copy the string}
if a_open_in (pool_file, kpse_texpool_format) then
  begin c:=false;
  repeat @<Read one string, but return |false| if the
    string memory space is getting too tight for comfort@>;
  until c;
  a_close(pool_file); get_strings_started:=true;
  end
else  bad_pool('! I can''t read ', pool_name, '; bad path?')
@.I can't read TEX.POOL@>

@ @<Read one string...@>=
begin if eof(pool_file) then bad_pool('! ', pool_name, ' has no check sum.');
@.TEX.POOL has no check sum@>
read(pool_file,m); read(pool_file,n); {read two digits of string length}
if m='*' then @<Check the pool check sum@>
else  begin if (xord[m]<"0")or(xord[m]>"9")or@|
      (xord[n]<"0")or(xord[n]>"9") then
    bad_pool('! ', pool_name, ' line doesn''t begin with two digits.');
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
  bad_pool('! ', pool_name, ' check sum doesn''t have nine digits.');
@.TEX.POOL check sum...@>
  a:=10*a+xord[n]-"0";
  if k=9 then goto done;
  incr(k); read(pool_file,n);
  end;
done: if a<>@$ then
  bad_pool('! ', pool_name, ' doesn''t match; tangle me again (or fix the path).');
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
@!trick_buf:array[0..ssup_error_line] of ASCII_code; {circular buffer for
  pseudoprinting}
@y
@!trick_buf:array[0..ssup_error_line] of ASCII_code; {circular buffer for
  pseudoprinting}
@!trick_buf2:array[0..ssup_error_line] of 0..2; {pTeX: buffer for KANJI}
@!kcode_pos: 0..2; {pTeX: denotes whether first byte or second byte of KANJI}
@!prev_char: ASCII_code;
@z

@x
@ @<Initialize the output routines@>=
selector:=term_only; tally:=0; term_offset:=0; file_offset:=0;
@y
@ @<Initialize the output routines@>=
selector:=term_only; tally:=0; term_offset:=0; file_offset:=0;
kcode_pos:=0;
@z

@x
procedure print_ln; {prints an end-of-line}
begin case selector of
term_and_log: begin wterm_cr; wlog_cr;
  term_offset:=0; file_offset:=0;
  end;
log_only: begin wlog_cr; file_offset:=0;
  end;
term_only: begin wterm_cr; term_offset:=0;
  end;
no_print,pseudo,new_string: do_nothing;
othercases write_ln(write_file[selector])
endcases;@/
@y
procedure print_ln; {prints an end-of-line}
begin case selector of
term_and_log: begin
  if kcode_pos=1 then begin wterm(' '); wlog(' '); end;
  wterm_cr; wlog_cr; term_offset:=0; file_offset:=0;
  end;
log_only: begin if kcode_pos=1 then wlog(' ');
  wlog_cr; file_offset:=0;
  end;
term_only: begin if kcode_pos=1 then wterm(' ');
  wterm_cr; term_offset:=0;
  end;
no_print,pseudo,new_string: do_nothing;
othercases write_ln(write_file[selector])
endcases;@/
kcode_pos:=0;
@z

@x
procedure print_char(@!s:ASCII_code); {prints a single character}
label exit;
begin if @<Character |s| is the current new-line character@> then
 if selector<pseudo then
  begin print_ln; return;
  end;
case selector of
term_and_log: begin wterm(xchr[s]); wlog(xchr[s]);
  incr(term_offset); incr(file_offset);
  if term_offset=max_print_line then
    begin wterm_cr; term_offset:=0;
    end;
  if file_offset=max_print_line then
    begin wlog_cr; file_offset:=0;
    end;
  end;
log_only: begin wlog(xchr[s]); incr(file_offset);
  if file_offset=max_print_line then print_ln;
  end;
term_only: begin wterm(xchr[s]); incr(term_offset);
  if term_offset=max_print_line then print_ln;
  end;
no_print: do_nothing;
pseudo: if tally<trick_count then trick_buf[tally mod error_line]:=s;
@y
procedure print_char(@!s:ASCII_code); {prints a single character}
label exit; {label is not used but nonetheless kept (for other changes?)}
begin if @<Character |s| is the current new-line character@> then
 if selector<pseudo then
  begin print_ln; return;
  end;
if kcode_pos=1 then kcode_pos:=2
else if iskanji1(xchr[s]) then
  begin kcode_pos:=1;
  if (selector=term_and_log)or(selector=log_only) then
    if file_offset>=max_print_line-1 then
       begin wlog_cr; file_offset:=0;
       end;
  if (selector=term_and_log)or(selector=term_only) then
    if term_offset>=max_print_line-1 then
       begin wterm_cr; term_offset:=0;
       end;
  end
else kcode_pos:=0;
case selector of
term_and_log: begin wterm(xchr[s]); incr(term_offset);
  if term_offset=max_print_line then
    begin wterm_cr; term_offset:=0;
    end;
  wlog(xchr[s]); incr(file_offset);
  if file_offset=max_print_line then
    begin wlog_cr; file_offset:=0;
    end;
  end;
log_only: begin wlog(xchr[s]); incr(file_offset);
  if file_offset=max_print_line then print_ln;
  end;
term_only: begin wterm(xchr[s]); incr(term_offset);
  if term_offset=max_print_line then print_ln;
  end;
no_print: do_nothing;
pseudo: if tally<trick_count then
  begin trick_buf[tally mod error_line]:=s;
  trick_buf2[tally mod error_line]:=kcode_pos;
  end;
@z

@x
procedure print(@!s:integer); {prints string |s|}
label exit;
var j:pool_pointer; {current character code position}
@!nl:integer; {new-line character to restore}
begin if s>=str_ptr then s:="???" {this can't happen}
@.???@>
else if s<256 then
  if s<0 then s:="???" {can't happen}
  else begin if selector>pseudo then
      begin print_char(s); return; {internal strings are not expanded}
      end;
    if (@<Character |s| is the current new-line character@>) then
      if selector<pseudo then
        begin print_ln; return;
        end;
    nl:=new_line_char; new_line_char:=-1;
      {temporarily disable new-line character}
    j:=str_start[s];
    while j<str_start[s+1] do
      begin print_char(so(str_pool[j])); incr(j);
      end;
    new_line_char:=nl; return;
    end;
j:=str_start[s];
while j<str_start[s+1] do
  begin print_char(so(str_pool[j])); incr(j);
  end;
exit:end;
@y
procedure print(@!s:integer); {prints string |s|}
label exit;
var j:pool_pointer; {current character code position}
@!nl:integer; {new-line character to restore}
begin if s>=str_ptr then s:="???" {this can't happen}
@.???@>
else if s<256 then
  if s<0 then s:="???" {can't happen}
  else begin if selector>pseudo then
      begin print_char(s); return; {internal strings are not expanded}
      end;
    if (@<Character |s| is the current new-line character@>) then
      if selector<pseudo then
        begin print_ln; return;
        end;
    nl:=new_line_char; new_line_char:=-1;
      {temporarily disable new-line character}
    j:=str_start[s];
    while j<str_start[s+1] do
      begin print_char(so(str_pool[j])); incr(j);
      end;
    new_line_char:=nl; return;
    end;
j:=str_start[s];
while j<str_start[s+1] do
  begin print_char(so(str_pool[j])); incr(j);
  end;
exit:end;
@z

@x
@<Initialize the output...@>=
if src_specials_p or file_line_error_style_p or parse_first_line_p then
  wterm(banner_k)
else
  wterm(banner);
@y
@<Initialize the output...@>=
if src_specials_p or file_line_error_style_p or parse_first_line_p then
  wterm(banner_k)
else
  wterm(banner);
  wterm(' (');
  wterm(conststringcast(get_enc_string));
  wterm(')');
@z

@x
  (mem_top+sup_main_memory>=max_halfword) then bad:=14;
@y
  (mem_top+sup_main_memory>=max_halfword)or@|
  (hi(0)<>0) then bad:=14;
@z

@x
sufficiently large.
@y
sufficiently large and this is required for p\TeX.
@z

@x
@d ho(#)==# {to take a sixteen-bit item from a halfword}
@y
@d ho(#)==# {to take a sixteen-bit item from a halfword}
@d KANJI(#)==# {pTeX: to output a KANJI code}
@d tokanji(#)==# {pTeX: to take a KANJI code from a halfword}
@d tonum(#)==# {pTeX: to put a KANJI code into a halfword}
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
|fil|, |fill|, or |filll|). The |subtype| field is not used.
@y
|fil|, |fill|, or |filll|). The |subtype| field is not used in \TeX.
In p\TeX\ the |subtype| field records the box direction |box_dir|.
@z

@x
@d hlist_node=0 {|type| of hlist nodes}
@d box_node_size=7 {number of words to allocate for a box node}
@d width_offset=1 {position of |width| field in a box node}
@d depth_offset=2 {position of |depth| field in a box node}
@d height_offset=3 {position of |height| field in a box node}
@d width(#) == mem[#+width_offset].sc {width of the box, in sp}
@d depth(#) == mem[#+depth_offset].sc {depth of the box, in sp}
@d height(#) == mem[#+height_offset].sc {height of the box, in sp}
@d shift_amount(#) == mem[#+4].sc {repositioning distance, in sp}
@d list_offset=5 {position of |list_ptr| field in a box node}
@d list_ptr(#) == link(#+list_offset) {beginning of the list inside the box}
@d glue_order(#) == subtype(#+list_offset) {applicable order of infinity}
@d glue_sign(#) == type(#+list_offset) {stretching or shrinking}
@d normal=0 {the most common case when several cases are named}
@d stretching = 1 {glue setting applies to the stretch components}
@d shrinking = 2 {glue setting applies to the shrink components}
@d glue_offset = 6 {position of |glue_set| in a box node}
@d glue_set(#) == mem[#+glue_offset].gr
  {a word of type |glue_ratio| for glue setting}
@y
@d synctex_field_size=2 {Declare the {\sl Sync\TeX} field size to store the {\sl Sync\TeX} information:
                          2 integers for file tag and line}
@d sync_tag(#) == mem[#-synctex_field_size].int {The tag subfield}
@d sync_line(#) == mem[#-synctex_field_size+1].int {The line subfield}
@#
@d hlist_node=0 {|type| of hlist nodes}
@d box_node_size=8+synctex_field_size {number of words to allocate for a box node}
@#
@d box_dir(#) == (qo(subtype(#))) {direction of a box}
@d set_box_dir(#) == subtype(#):=set_box_dir_end
@d set_box_dir_end(#) == qi(#)
@#
@d dir_default = 0 {direction of the box, default Left to Right}
@d dir_dtou = 1 {direction of the box, Bottom to Top}
@d dir_tate = 3 {direction of the box, Top to Bottom}
@d dir_yoko = 4 {direction of the box, equal default}
@d any_dir == dir_yoko,dir_tate,dir_dtou
@#
@d width_offset=1 {position of |width| field in a box node}
@d depth_offset=2 {position of |depth| field in a box node}
@d height_offset=3 {position of |height| field in a box node}
@d width(#) == mem[#+width_offset].sc {width of the box, in sp}
@d depth(#) == mem[#+depth_offset].sc {depth of the box, in sp}
@d height(#) == mem[#+height_offset].sc {height of the box, in sp}
@d shift_amount(#) == mem[#+4].sc {repositioning distance, in sp}
@d list_offset=5 {position of |list_ptr| field in a box node}
@d list_ptr(#) == link(#+list_offset) {beginning of the list inside the box}
@d glue_order(#) == subtype(#+list_offset) {applicable order of infinity}
@d glue_sign(#) == type(#+list_offset) {stretching or shrinking}
@d normal=0 {the most common case when several cases are named}
@d stretching = 1 {glue setting applies to the stretch components}
@d shrinking = 2 {glue setting applies to the shrink components}
@d glue_offset = 6 {position of |glue_set| in a box node}
@d glue_set(#) == mem[#+glue_offset].gr
  {a word of type |glue_ratio| for glue setting}
@d space_offset = 7 {position of |glue_set| in a box node}
@d space_ptr(#) == link(#+space_offset)
@d xspace_ptr(#) == info(#+space_offset)
@z

@x
width(p):=0; depth(p):=0; height(p):=0; shift_amount(p):=0; list_ptr(p):=null;
glue_sign(p):=normal; glue_order(p):=normal; set_glue_ratio_zero(glue_set(p));
@y
width(p):=0; depth(p):=0; height(p):=0; shift_amount(p):=0; list_ptr(p):=null;
glue_sign(p):=normal; glue_order(p):=normal; set_glue_ratio_zero(glue_set(p));
space_ptr(p):=zero_glue; xspace_ptr(p):=zero_glue;
add_glue_ref(zero_glue); add_glue_ref(zero_glue);
@z

@x
@d vlist_node=1 {|type| of vlist nodes}
@y
@d vlist_node=1 {|type| of vlist nodes}

@ A |dir_node| stands for direction change.

@d dir_node=2 {|type| of dir nodes}

@p function new_dir_node(b:pointer; dir:eight_bits):pointer;
var p:pointer; {the new node}
begin if type(b)>vlist_node then confusion("new_dir_node:not box");
p:=new_null_box; type(p):=dir_node; set_box_dir(p)(dir);
case box_dir(b) of
  dir_yoko: @<Yoko to other direction@>;
  dir_tate: @<Tate to other direction@>;
  dir_dtou: @<DtoU to other direction@>;
  othercases confusion("new_dir_node:illegal dir");
endcases;
link(b):=null; list_ptr(p):=b;
new_dir_node:=p;
end;

@ @<Yoko to other direction@>=
  case dir of
  dir_tate: begin width(p):=height(b)+depth(b);
      depth(p):=width(b)/2; height(p):=width(b)-depth(p);
      end;
  dir_dtou: begin width(p):=height(b)+depth(b);
      depth(p):=0; height(p):=width(b);
      end;
  othercases confusion("new_dir_node:y->?");
  endcases

@ @<Tate to other direction@>=
  case dir of
  dir_yoko: begin width(p):=height(b)+depth(b);
      depth(p):=0; height(p):=width(b);
      end;
  dir_dtou: begin width(p):=width(b);
      depth(p):=height(b); height(p):=depth(b);
      end;
  othercases confusion("new_dir_node:t->?");
  endcases

@ @<DtoU to other direction@>=
  case dir of
  dir_yoko: begin width(p):=height(b)+depth(b);
      depth(p):=0; height(p):=width(b);
      end;
  dir_tate: begin width(p):=width(b);
      depth(p):=height(b); height(p):=depth(b);
      end;
  othercases confusion("new_dir_node:d->?");
  endcases
@z

@x
@d rule_node=2 {|type| of rule nodes}
@y
@d rule_node=3 {|type| of rule nodes}
@z

@x
@d rule_node_size=4 {number of words to allocate for a rule node}
@y
@d rule_node_size=4+synctex_field_size {number of words to allocate for a rule node}
@z

@x
@d ins_node=3 {|type| of insertion nodes}
@d ins_node_size=5 {number of words to allocate for an insertion}
@d float_cost(#)==mem[#+1].int {the |floating_penalty| to be used}
@d ins_ptr(#)==info(#+4) {the vertical list to be inserted}
@d split_top_ptr(#)==link(#+4) {the |split_top_skip| to be used}
@y
@d ins_node=4 {|type| of insertion nodes}
@d ins_node_size=6 {number of words to allocate for an insertion}
@d float_cost(#)==mem[#+1].int {the |floating_penalty| to be used}
@d ins_ptr(#)==info(#+4) {the vertical list to be inserted}
@d split_top_ptr(#)==link(#+4) {the |split_top_skip| to be used}
@d ins_dir(#)==subtype(#+5) {direction of |ins_node|}
@z

@x
@ A |mark_node| has a |mark_ptr| field that points to the reference count
@y
@ A |disp_node| has a |disp_dimen| field that points to the displacement
distance of the baselineshift between Latin characters and Kanji chatacters.

@d disp_node=5 {|type| of a displace node}
@d disp_dimen(#)==mem[#+1].sc

@ A |mark_node| has a |mark_ptr| field that points to the reference count
@z

@x
@d mark_node=4 {|type| of a mark node}
@y
@d mark_node=6 {|type| of a mark node}
@z

@x
@d small_node_size=2 {number of words to allocate for most node types}
@y
@d small_node_size=2 {number of words to allocate for most node types}
@d medium_node_size=small_node_size+synctex_field_size {number of words to
           allocate for synchronized node types like math, kern, glue and penalty nodes}
@z

@x
@d adjust_node=5 {|type| of an adjust node}
@y
@d adjust_node=7 {|type| of an adjust node}
@z

@x
@d ligature_node=6 {|type| of a ligature node}
@y
@d ligature_node=8 {|type| of a ligature node}
@z

@x
@d disc_node=7 {|type| of a discretionary node}
@y
@d disc_node=9 {|type| of a discretionary node}
@z

@x
@d whatsit_node=8 {|type| of special extension nodes}
@y
@d whatsit_node=10 {|type| of special extension nodes}
@z

@x
@d math_node=9 {|type| of a math node}
@y
@d math_node=11 {|type| of a math node}
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
@d glue_node=10 {|type| of node that points to a glue specification}
@y
@d glue_node=12 {|type| of node that points to a glue specification}
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
@d kern_node=11 {|type| of a kern node}
@d explicit=1 {|subtype| of kern nodes from \.{\\kern} and \.{\\/}}
@d acc_kern=2 {|subtype| of kern nodes from accents}
@y
@d kern_node=13 {|type| of a kern node}
@d explicit=1 {|subtype| of kern nodes from \.{\\kern}}
@d acc_kern=2 {|subtype| of kern nodes from accents}
@d ita_kern=3 {|subtype| of kern nodes from \.{\\/}}
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
@d penalty_node=12 {|type| of a penalty node}
@y
@d penalty_node=14 {|type| of a penalty node}
@d widow_pena=1 {|subtype| of penalty nodes from \.{\\jchrwidowpenalty}}
@d kinsoku_pena=2 {|subtype| of penalty nodes from kinsoku}
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
@d unset_node=13 {|type| for an unset node}
@y
@d unset_node=15 {|type| for an unset node}
@z

@x
@ In fact, there are still more types coming. When we get to math formula
processing we will see that a |style_node| has |type=14|; and a number
of larger type codes will also be defined, for use in math mode only.
@y
@ In fact, there are still more types coming. When we get to math formula
processing we will see that a |style_node| has |type=16|; and a number
of larger type codes will also be defined, for use in math mode only.
@z

@x
      print_ASCII(qo(character(p)));
@y
      if font_dir[font(p)]<>dir_default then
        begin p:=link(p); print_kanji(info(p));
        end
      else print_ASCII(qo(character(p)));
@z

@x
hlist_node,vlist_node,ins_node,whatsit_node,mark_node,adjust_node,
  unset_node: print("[]");
@y
hlist_node,vlist_node,dir_node,ins_node,whatsit_node,
  mark_node,adjust_node,unset_node: print("[]");
@z

@x
  print_char(" "); print_ASCII(qo(character(p)));
@y
  print_char(" ");
  if font_dir[font(p)]<>dir_default then
    begin p:=link(p); print_kanji(info(p));
    end
  else print_ASCII(qo(character(p)));
@z

@x
if is_char_node(p) then print_font_and_char(p)
else  case type(p) of
  hlist_node,vlist_node,unset_node: @<Display box |p|@>;
  rule_node: @<Display rule |p|@>;
  ins_node: @<Display insertion |p|@>;
  whatsit_node: @<Display the whatsit node |p|@>;
@y
if is_char_node(p) then
  begin print_font_and_char(p);
  if font_dir[font(p)]<>dir_default then p:=link(p)
  end
else  case type(p) of
  hlist_node,vlist_node,dir_node,unset_node: @<Display box |p|@>;
  rule_node: @<Display rule |p|@>;
  ins_node: @<Display insertion |p|@>;
  whatsit_node: @<Display the whatsit node |p|@>;
  disp_node: begin print_esc("displace "); print_scaled(disp_dimen(p));
    end;
@z

@x
@ @<Display box |p|@>=
begin if type(p)=hlist_node then print_esc("h")
else if type(p)=vlist_node then print_esc("v")
else print_esc("unset");
@y
@ @<Display box |p|@>=
begin case type(p) of
  hlist_node: print_esc("h");
  vlist_node: print_esc("v");
  dir_node: print_esc("dir");
  othercases print_esc("unset")
  endcases@/;
@z

@x
  if shift_amount(p)<>0 then
    begin print(", shifted "); print_scaled(shift_amount(p));
    end;
@y
  if shift_amount(p)<>0 then
    begin print(", shifted "); print_scaled(shift_amount(p));
    end;
@z

@x
  end;
@y
  if box_dir(p)<>dir_default then
    begin print(", "); print_direction(box_dir(p));
    end;
  end;
@z

@x
@ @<Display insertion |p|@>=
begin print_esc("insert"); print_int(qo(subtype(p)));
print(", natural size "); print_scaled(height(p));
@y
@ @<Display insertion |p|@>=
begin print_esc("insert"); print_int(qo(subtype(p)));
print_dir(ins_dir(p));
print(", natural size "); print_scaled(height(p));
@z

@x
@ @<Display penalty |p|@>=
begin print_esc("penalty "); print_int(penalty(p));
end
@y
@ @<Display penalty |p|@>=
begin print_esc("penalty "); print_int(penalty(p));
if subtype(p)=widow_pena then print("(for \jchrwidowpenalty)")
else if subtype(p)=kinsoku_pena then print("(for kinsoku)");
end
@z

@x
@p procedure flush_node_list(@!p:pointer); {erase list of nodes starting at |p|}
@y
@p procedure flush_node_list(@!p:pointer); {erase list of nodes starting at |p|}
@z

@x
    hlist_node,vlist_node,unset_node: begin flush_node_list(list_ptr(p));
      free_node(p,box_node_size); goto done;
      end;
@y
    hlist_node,vlist_node,dir_node,unset_node:
      begin flush_node_list(list_ptr(p));
      fast_delete_glue_ref(space_ptr(p));
      fast_delete_glue_ref(xspace_ptr(p));
      free_node(p,box_node_size); goto done;
      end;
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
    disp_node: do_nothing;
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
  mem[r+6]:=mem[p+6]; mem[r+5]:=mem[p+5]; {copy the last two words}
@y
dir_node,
hlist_node,vlist_node,unset_node: begin r:=get_node(box_node_size);
  @<Copy the box {\sl Sync\TeX} information@>;
  mem[r+7]:=mem[p+7];
  mem[r+6]:=mem[p+6]; mem[r+5]:=mem[p+5]; {copy the last three words}
  add_glue_ref(space_ptr(r)); add_glue_ref(xspace_ptr(r));
@z

@x
rule_node: begin r:=get_node(rule_node_size); words:=rule_node_size;
@y
rule_node: begin r:=get_node(rule_node_size); words:=rule_node_size-synctex_field_size;{{\sl Sync\TeX}: do not let \TeX\ copy the {\sl Sync\TeX} information}
  @<Copy the rule {\sl Sync\TeX} information@>;
@z

@x
ins_node: begin r:=get_node(ins_node_size); mem[r+4]:=mem[p+4];
  add_glue_ref(split_top_ptr(p));
  ins_ptr(r):=copy_node_list(ins_ptr(p)); {this affects |mem[r+4]|}
  words:=ins_node_size-1;
  end;
@y
ins_node: begin r:=get_node(ins_node_size);
  mem[r+5]:=mem[p+5]; mem[r+4]:=mem[p+4];
  add_glue_ref(split_top_ptr(p));
  ins_ptr(r):=copy_node_list(ins_ptr(p)); {this affects |mem[r+4]|}
  words:=ins_node_size-2;
  end;
@z

@x
glue_node: begin r:=get_node(small_node_size); add_glue_ref(glue_ptr(p));
@y
glue_node: begin r:=get_node(medium_node_size); add_glue_ref(glue_ptr(p));
  @<Copy the medium sized node {\sl Sync\TeX} information@>;
@z

@x
kern_node,math_node,penalty_node: begin r:=get_node(small_node_size);
@y
disp_node: begin r:=get_node(small_node_size);
  words:=small_node_size;
  end;
@z

@x
  words:=small_node_size;
  end;
@y
kern_node,math_node,penalty_node: begin r:=get_node(medium_node_size);
  words:=medium_node_size;
  end;
@z

@x
@d max_char_code=15 {largest catcode for individual characters}
@y
@d kanji=16 {kanji}
@d kana=17 {hiragana, katakana, alphabet}
@d other_kchar=18 {kanji codes}
@d max_char_code=18 {largest catcode for individual characters}
@z

@x
@d char_num=16 {character specified numerically ( \.{\\char} )}
@d math_char_num=17 {explicit math code ( \.{\\mathchar} )}
@d mark=18 {mark definition ( \.{\\mark} )}
@d xray=19 {peek inside of \TeX\ ( \.{\\show}, \.{\\showbox}, etc.~)}
@d make_box=20 {make a box ( \.{\\box}, \.{\\copy}, \.{\\hbox}, etc.~)}
@d hmove=21 {horizontal motion ( \.{\\moveleft}, \.{\\moveright} )}
@d vmove=22 {vertical motion ( \.{\\raise}, \.{\\lower} )}
@d un_hbox=23 {unglue a box ( \.{\\unhbox}, \.{\\unhcopy} )}
@d un_vbox=24 {unglue a box ( \.{\\unvbox}, \.{\\unvcopy} )}
@y
@d char_num=max_char_code+1 {character specified numerically ( \.{\\char} )}
@d math_char_num=char_num+1 {explicit math code ( \.{\\mathchar} )}
@d mark=math_char_num+1 {mark definition ( \.{\\mark} )}
@d xray=mark+1 {peek inside of \TeX\ ( \.{\\show}, \.{\\showbox}, etc.~)}
@d make_box=xray+1 {make a box ( \.{\\box}, \.{\\copy}, \.{\\hbox}, etc.~)}
@d hmove=make_box+1 {horizontal motion ( \.{\\moveleft}, \.{\\moveright} )}
@d vmove=hmove+1 {vertical motion ( \.{\\raise}, \.{\\lower} )}
@d un_hbox=vmove+1 {unglue a box ( \.{\\unhbox}, \.{\\unhcopy} )}
@d un_vbox=un_hbox+1 {unglue a box ( \.{\\unvbox}, \.{\\unvcopy} )}
@z

@x
@d remove_item=25 {nullify last item ( \.{\\unpenalty},
  \.{\\unkern}, \.{\\unskip} )}
@d hskip=26 {horizontal glue ( \.{\\hskip}, \.{\\hfil}, etc.~)}
@d vskip=27 {vertical glue ( \.{\\vskip}, \.{\\vfil}, etc.~)}
@d mskip=28 {math glue ( \.{\\mskip} )}
@d kern=29 {fixed space ( \.{\\kern})}
@d mkern=30 {math kern ( \.{\\mkern} )}
@d leader_ship=31 {use a box ( \.{\\shipout}, \.{\\leaders}, etc.~)}
@d halign=32 {horizontal table alignment ( \.{\\halign} )}
@d valign=33 {vertical table alignment ( \.{\\valign} )}
@y
@d remove_item=un_vbox+1 {nullify last item ( \.{\\unpenalty},
  \.{\\unkern}, \.{\\unskip} )}
@d hskip=remove_item+1 {horizontal glue ( \.{\\hskip}, \.{\\hfil}, etc.~)}
@d vskip=hskip+1 {vertical glue ( \.{\\vskip}, \.{\\vfil}, etc.~)}
@d mskip=vskip+1 {math glue ( \.{\\mskip} )}
@d kern=mskip+1 {fixed space ( \.{\\kern})}
@d mkern=kern+1 {math kern ( \.{\\mkern} )}
@d leader_ship=mkern+1 {use a box ( \.{\\shipout}, \.{\\leaders}, etc.~)}
@d halign=leader_ship+1 {horizontal table alignment ( \.{\\halign} )}
@d valign=halign+1 {vertical table alignment ( \.{\\valign} )}
@z

@x
@d no_align=34 {temporary escape from alignment ( \.{\\noalign} )}
@d vrule=35 {vertical rule ( \.{\\vrule} )}
@d hrule=36 {horizontal rule ( \.{\\hrule} )}
@d insert=37 {vlist inserted in box ( \.{\\insert} )}
@d vadjust=38 {vlist inserted in enclosing paragraph ( \.{\\vadjust} )}
@d ignore_spaces=39 {gobble |spacer| tokens ( \.{\\ignorespaces} )}
@d after_assignment=40 {save till assignment is done ( \.{\\afterassignment} )}
@d after_group=41 {save till group is done ( \.{\\aftergroup} )}
@d break_penalty=42 {additional badness ( \.{\\penalty} )}
@d start_par=43 {begin paragraph ( \.{\\indent}, \.{\\noindent} )}
@d ital_corr=44 {italic correction ( \.{\\/} )}
@d accent=45 {attach accent in text ( \.{\\accent} )}
@d math_accent=46 {attach accent in math ( \.{\\mathaccent} )}
@d discretionary=47 {discretionary texts ( \.{\\-}, \.{\\discretionary} )}
@d eq_no=48 {equation number ( \.{\\eqno}, \.{\\leqno} )}
@d left_right=49 {variable delimiter ( \.{\\left}, \.{\\right} )}
@y
@d no_align=valign+1 {temporary escape from alignment ( \.{\\noalign} )}
@d vrule=no_align+1 {vertical rule ( \.{\\vrule} )}
@d hrule=vrule+1 {horizontal rule ( \.{\\hrule} )}
@d insert=hrule+1 {vlist inserted in box ( \.{\\insert} )}
@d vadjust=insert+1 {vlist inserted in enclosing paragraph ( \.{\\vadjust} )}
@d ignore_spaces=vadjust+1 {gobble |spacer| tokens ( \.{\\ignorespaces} )}
@d after_assignment=ignore_spaces+1 {save till assignment is done ( \.{\\afterassignment} )}
@d after_group=after_assignment+1 {save till group is done ( \.{\\aftergroup} )}
@d break_penalty=after_group+1 {additional badness ( \.{\\penalty} )}
@d start_par=break_penalty+1 {begin paragraph ( \.{\\indent}, \.{\\noindent} )}
@d ital_corr=start_par+1 {italic correction ( \.{\\/} )}
@d accent=ital_corr+1 {attach accent in text ( \.{\\accent} )}
@d math_accent=accent+1 {attach accent in math ( \.{\\mathaccent} )}
@d discretionary=math_accent+1 {discretionary texts ( \.{\\-}, \.{\\discretionary} )}
@d eq_no=discretionary+1 {equation number ( \.{\\eqno}, \.{\\leqno} )}
@d left_right=eq_no+1 {variable delimiter ( \.{\\left}, \.{\\right} )}
@z

@x
@d math_comp=50 {component of formula ( \.{\\mathbin}, etc.~)}
@d limit_switch=51 {diddle limit conventions ( \.{\\displaylimits}, etc.~)}
@d above=52 {generalized fraction ( \.{\\above}, \.{\\atop}, etc.~)}
@d math_style=53 {style specification ( \.{\\displaystyle}, etc.~)}
@d math_choice=54 {choice specification ( \.{\\mathchoice} )}
@d non_script=55 {conditional math glue ( \.{\\nonscript} )}
@d vcenter=56 {vertically center a vbox ( \.{\\vcenter} )}
@d case_shift=57 {force specific case ( \.{\\lowercase}, \.{\\uppercase}~)}
@d message=58 {send to user ( \.{\\message}, \.{\\errmessage} )}
@d extension=59 {extensions to \TeX\ ( \.{\\write}, \.{\\special}, etc.~)}
@d in_stream=60 {files for reading ( \.{\\openin}, \.{\\closein} )}
@d begin_group=61 {begin local grouping ( \.{\\begingroup} )}
@d end_group=62 {end local grouping ( \.{\\endgroup} )}
@d omit=63 {omit alignment template ( \.{\\omit} )}
@d ex_space=64 {explicit space ( \.{\\\ } )}
@d no_boundary=65 {suppress boundary ligatures ( \.{\\noboundary} )}
@d radical=66 {square root and similar signs ( \.{\\radical} )}
@d end_cs_name=67 {end control sequence ( \.{\\endcsname} )}
@d min_internal=68 {the smallest code that can follow \.{\\the}}
@d char_given=68 {character code defined by \.{\\chardef}}
@d math_given=69 {math code defined by \.{\\mathchardef}}
@d last_item=70 {most recent item ( \.{\\lastpenalty},
  \.{\\lastkern}, \.{\\lastskip} )}
@d max_non_prefixed_command=70 {largest command code that can't be \.{\\global}}
@y
@d math_comp=left_right+1 {component of formula ( \.{\\mathbin}, etc.~)}
@d limit_switch=math_comp+1 {diddle limit conventions ( \.{\\displaylimits}, etc.~)}
@d above=limit_switch+1 {generalized fraction ( \.{\\above}, \.{\\atop}, etc.~)}
@d math_style=above+1 {style specification ( \.{\\displaystyle}, etc.~)}
@d math_choice=math_style+1 {choice specification ( \.{\\mathchoice} )}
@d non_script=math_choice+1 {conditional math glue ( \.{\\nonscript} )}
@d vcenter=non_script+1 {vertically center a vbox ( \.{\\vcenter} )}
@d case_shift=vcenter+1 {force specific case ( \.{\\lowercase}, \.{\\uppercase}~)}
@d message=case_shift+1 {send to user ( \.{\\message}, \.{\\errmessage} )}
@d extension=message+1 {extensions to \TeX\ ( \.{\\write}, \.{\\special}, etc.~)}
@d in_stream=extension+1 {files for reading ( \.{\\openin}, \.{\\closein} )}
@d begin_group=in_stream+1 {begin local grouping ( \.{\\begingroup} )}
@d end_group=begin_group+1 {end local grouping ( \.{\\endgroup} )}
@d omit=end_group+1 {omit alignment template ( \.{\\omit} )}
@d ex_space=omit+1 {explicit space ( \.{\\\ } )}
@d no_boundary=ex_space+1 {suppress boundary ligatures ( \.{\\noboundary} )}
@d radical=no_boundary+1 {square root and similar signs ( \.{\\radical} )}
@d end_cs_name=radical+1 {end control sequence ( \.{\\endcsname} )}
@d min_internal=end_cs_name+1 {the smallest code that can follow \.{\\the}}
@d char_given=min_internal {character code defined by \.{\\chardef}}
@d math_given=char_given+1 {math code defined by \.{\\mathchardef}}
@d last_item=math_given+1 {most recent item ( \.{\\lastpenalty},
  \.{\\lastkern}, \.{\\lastskip} )}
@d inhibit_glue=last_item+1 {inhibit adjust glue ( \.{\\inhibitglue} )}
@d chg_dir=inhibit_glue+1 {change dir mode by \.{\\tate}, \.{\\yoko}}
@d max_non_prefixed_command=chg_dir {largest command code that can't be \.{\\global}}
@z

@x
@d toks_register=71 {token list register ( \.{\\toks} )}
@d assign_toks=72 {special token list ( \.{\\output}, \.{\\everypar}, etc.~)}
@d assign_int=73 {user-defined integer ( \.{\\tolerance}, \.{\\day}, etc.~)}
@d assign_dimen=74 {user-defined length ( \.{\\hsize}, etc.~)}
@d assign_glue=75 {user-defined glue ( \.{\\baselineskip}, etc.~)}
@d assign_mu_glue=76 {user-defined muglue ( \.{\\thinmuskip}, etc.~)}
@d assign_font_dimen=77 {user-defined font dimension ( \.{\\fontdimen} )}
@d assign_font_int=78 {user-defined font integer ( \.{\\hyphenchar},
  \.{\\skewchar} )}
@d set_aux=79 {specify state info ( \.{\\spacefactor}, \.{\\prevdepth} )}
@d set_prev_graf=80 {specify state info ( \.{\\prevgraf} )}
@d set_page_dimen=81 {specify state info ( \.{\\pagegoal}, etc.~)}
@d set_page_int=82 {specify state info ( \.{\\deadcycles},
@y
@d toks_register=max_non_prefixed_command+1 {token list register ( \.{\\toks} )}
@d assign_toks=toks_register+1
  {special token list ( \.{\\output}, \.{\\everypar}, etc.~)}
@d assign_int=assign_toks+1
  {user-defined integer ( \.{\\tolerance}, \.{\\day}, etc.~)}
@d assign_dimen=assign_int+1 {user-defined length ( \.{\\hsize}, etc.~)}
@d assign_glue=assign_dimen+1 {user-defined glue ( \.{\\baselineskip}, etc.~)}
@d assign_mu_glue=assign_glue+1 {user-defined muglue ( \.{\\thinmuskip}, etc.~)}
@d assign_font_dimen=assign_mu_glue+1
  {user-defined font dimension ( \.{\\fontdimen} )}
@d assign_font_int=assign_font_dimen+1
  {user-defined font integer ( \.{\\hyphenchar}, \.{\\skewchar} )}
@d assign_kinsoku=assign_font_int+1
  {user-defined kinsoku character ( \.{\\prebreakpenalty},
   \.{\\postbreakpenalty} )}
@d assign_inhibit_xsp_code=assign_kinsoku+1
  {user-defined inhibit xsp character ( \.{\\inhibitxspcode} )}
@d set_kansuji_char=assign_inhibit_xsp_code+1
  {user-defined kansuji character ( \.{\\kansujichar} )}
@d set_aux=set_kansuji_char+1
  {specify state info ( \.{\\spacefactor}, \.{\\prevdepth} )}
@d set_prev_graf=set_aux+1 {specify state info ( \.{\\prevgraf} )}
@d set_page_dimen=set_prev_graf+1 {specify state info ( \.{\\pagegoal}, etc.~)}
@d set_page_int=set_page_dimen+1 {specify state info ( \.{\\deadcycles},
@z

@x
@d set_box_dimen=83 {change dimension of box ( \.{\\wd}, \.{\\ht}, \.{\\dp} )}
@d set_shape=84 {specify fancy paragraph shape ( \.{\\parshape} )}
@y
@d set_box_dimen=set_page_int+1 {change dimension of box ( \.{\\wd}, \.{\\ht}, \.{\\dp} )}
@d set_shape=set_box_dimen+1 {specify fancy paragraph shape ( \.{\\parshape} )}
@z

@x
@d def_code=85 {define a character code ( \.{\\catcode}, etc.~)}
@d def_family=86 {declare math fonts ( \.{\\textfont}, etc.~)}
@d set_font=87 {set current font ( font identifiers )}
@d def_font=88 {define a font file ( \.{\\font} )}
@d register=89 {internal register ( \.{\\count}, \.{\\dimen}, etc.~)}
@d max_internal=89 {the largest code that can follow \.{\\the}}
@d advance=90 {advance a register or parameter ( \.{\\advance} )}
@d multiply=91 {multiply a register or parameter ( \.{\\multiply} )}
@d divide=92 {divide a register or parameter ( \.{\\divide} )}
@d prefix=93 {qualify a definition ( \.{\\global}, \.{\\long}, \.{\\outer} )}
@y
@d def_code=set_shape+1 {define a character code ( \.{\\catcode}, etc.~)}
@d def_family=def_code+1 {declare math fonts ( \.{\\textfont}, etc.~)}
@d set_font=def_family+1 {set current font ( font identifiers )}
@d def_font=set_font+1 {define a font file ( \.{\\font} )}
@d def_jfont=def_font+1 {define a font file ( \.{\\jfont} )}
@d def_tfont=def_jfont+1 {define a font file ( \.{\\tfont} )}
@d register=def_tfont+1 {internal register ( \.{\\count}, \.{\\dimen}, etc.~)}
@d max_internal=register {the largest code that can follow \.{\\the}}
@d advance=max_internal+1 {advance a register or parameter ( \.{\\advance} )}
@d multiply=advance+1 {multiply a register or parameter ( \.{\\multiply} )}
@d divide=multiply+1 {divide a register or parameter ( \.{\\divide} )}
@d prefix=divide+1 {qualify a definition ( \.{\\global}, \.{\\long}, \.{\\outer} )}
@z

@x
@d let=94 {assign a command code ( \.{\\let}, \.{\\futurelet} )}
@d shorthand_def=95 {code definition ( \.{\\chardef}, \.{\\countdef}, etc.~)}
  {or \.{\\charsubdef}}
@d read_to_cs=96 {read into a control sequence ( \.{\\read} )}
@y
@d let=prefix+1 {assign a command code ( \.{\\let}, \.{\\futurelet} )}
@d shorthand_def=let+1 {code definition ( \.{\\chardef}, \.{\\countdef}, etc.~)}
  {or \.{\\charsubdef}}
@d read_to_cs=shorthand_def+1 {read into a control sequence ( \.{\\read} )}
@z

@x
@d def=97 {macro definition ( \.{\\def}, \.{\\gdef}, \.{\\xdef}, \.{\\edef} )}
@d set_box=98 {set a box ( \.{\\setbox} )}
@d hyph_data=99 {hyphenation data ( \.{\\hyphenation}, \.{\\patterns} )}
@d set_interaction=100 {define level of interaction ( \.{\\batchmode}, etc.~)}
@d max_command=100 {the largest command code seen at |big_switch|}
@y
@d def=read_to_cs+1 {macro definition ( \.{\\def}, \.{\\gdef}, \.{\\xdef}, \.{\\edef} )}
@d set_box=def+1 {set a box ( \.{\\setbox} )}
@d hyph_data=set_box+1 {hyphenation data ( \.{\\hyphenation}, \.{\\patterns} )}
@d set_interaction=hyph_data+1 {define level of interaction ( \.{\\batchmode}, etc.~)}
@d set_auto_spacing=set_interaction+1 {set auto spaceing mode
  ( \.{\\autospacing}, \.{\\noautospacing}, ( \.{\\autoxspacing}, \.{\\noautoxspacing} )}
@d max_command=set_auto_spacing {the largest command code seen at |big_switch|}
@z

@x
@<Types...@>=
@!list_state_record=record@!mode_field:-mmode..mmode;@+
  @!head_field,@!tail_field: pointer;
@y
@<Types...@>=
@!list_state_record=record@!mode_field:-mmode..mmode;@+
  @!dir_field,@!adj_dir_field: -dir_yoko..dir_yoko;
  @!pdisp_field: scaled;
  @!head_field,@!tail_field,@!pnode_field,@!last_jchr_field: pointer;
@z

@x
@d head==cur_list.head_field {header node of current list}
@d tail==cur_list.tail_field {final node on current list}
@y
@d direction==cur_list.dir_field {current direction}
@d adjust_dir==cur_list.adj_dir_field {current adjust direction}
@d head==cur_list.head_field {header node of current list}
@d tail==cur_list.tail_field {final node on current list}
@d prev_node==cur_list.pnode_field {previous to last |disp_node|}
@d prev_disp==cur_list.pdisp_field {displacemant at |prev_node|}
@d last_jchr==cur_list.last_jchr_field {final jchar node on current list}
@z

@x
@d tail_append(#)==begin link(tail):=#; tail:=link(tail);
  end
@y
@d tail_append(#)==begin link(tail):=#; tail:=link(tail);
  end
@d prev_append(#)==begin link(prev_node):=#;
  link(link(prev_node)):=tail; prev_node:=link(prev_node);
  end
@z

@x
mode:=vmode; head:=contrib_head; tail:=contrib_head;
@y
mode:=vmode; head:=contrib_head; tail:=contrib_head; prev_node:=tail;
direction:=dir_yoko; adjust_dir:=direction; prev_disp:=0; last_jchr:=null;
@z

@x
incr(nest_ptr); head:=get_avail; tail:=head; prev_graf:=0; mode_line:=line;
@y
incr(nest_ptr); head:=new_null_box; tail:=head; prev_node:=tail;
prev_graf:=0; prev_disp:=0; last_jchr:=null; mode_line:=line;
@z

@x
@p procedure pop_nest; {leave a semantic level, re-enter the old}
begin free_avail(head); decr(nest_ptr); cur_list:=nest[nest_ptr];
end;
@y
@p procedure pop_nest; {leave a semantic level, re-enter the old}
begin
fast_delete_glue_ref(space_ptr(head)); fast_delete_glue_ref(xspace_ptr(head));
free_node(head,box_node_size); decr(nest_ptr); cur_list:=nest[nest_ptr];
end;
@z

@x
  print_nl("### "); print_mode(m);
@y
  print_nl("### "); print_direction(nest[p].dir_field);
  print(", "); print_mode(m);
@z

@x
@d thin_mu_skip_code=15 {thin space in math formula}
@d med_mu_skip_code=16 {medium space in math formula}
@d thick_mu_skip_code=17 {thick space in math formula}
@d glue_pars=18 {total number of glue parameters}
@y
@d kanji_skip_code=15 {between kanji-kanji space}
@d xkanji_skip_code=16 {between latin-kanji or kanji-latin space}
@d thin_mu_skip_code=17 {thin space in math formula}
@d med_mu_skip_code=18 {medium space in math formula}
@d thick_mu_skip_code=19 {thick space in math formula}
@d jfm_skip=20 {space refer from JFM}
@d glue_pars=21 {total number of glue parameters}
@z

@x
@d thick_mu_skip==glue_par(thick_mu_skip_code)
@y
@d thick_mu_skip==glue_par(thick_mu_skip_code)
@d kanji_skip==glue_par(kanji_skip_code)
@d xkanji_skip==glue_par(xkanji_skip_code)
@z

@x
thick_mu_skip_code: print_esc("thickmuskip");
othercases print("[unknown glue parameter!]")
@y
thick_mu_skip_code: print_esc("thickmuskip");
kanji_skip_code: print_esc("kanjiskip");
xkanji_skip_code: print_esc("xkanjiskip");
jfm_skip: print("refer from jfm");
othercases print("[unknown glue parameter!]")
@z

@x
primitive("thickmuskip",assign_mu_glue,glue_base+thick_mu_skip_code);@/
@!@:thick_mu_skip_}{\.{\\thickmuskip} primitive@>
@y
primitive("thickmuskip",assign_mu_glue,glue_base+thick_mu_skip_code);@/
@!@:thick_mu_skip_}{\.{\\thickmuskip} primitive@>
primitive("kanjiskip",assign_glue,glue_base+kanji_skip_code);@/
@!@:kanji_skip_}{\.{\\kanjiskip} primitive@>
primitive("xkanjiskip",assign_glue,glue_base+xkanji_skip_code);@/
@!@:xkanji_skip_}{\.{\\xkanjiskip} primitive@>
@z

@x
@d math_font_base=cur_font_loc+1 {table of 48 math font numbers}
@d cat_code_base=math_font_base+48
  {table of 256 command codes (the ``catcodes'')}
@d lc_code_base=cat_code_base+256 {table of 256 lowercase mappings}
@y
@d math_font_base=cur_font_loc+1 {table of 48 math font numbers}
@d cur_jfont_loc=math_font_base+48
@d cur_tfont_loc=cur_jfont_loc+1
@d auto_spacing_code=cur_tfont_loc+1
@d auto_xspacing_code=auto_spacing_code+1
@d cat_code_base=auto_xspacing_code+1
  {table of 256 command codes (the ``catcodes'')}
@d kcat_code_base=cat_code_base+256
  {table of 256 command codes for the wchar's catcodes }
@d auto_xsp_code_base=kcat_code_base+256 {table of 256 auto spacer flag}
@d inhibit_xsp_code_base=auto_xsp_code_base+256
@d kinsoku_base=inhibit_xsp_code_base+256 {table of 256 kinsoku mappings}
@d kansuji_base=kinsoku_base+256 {table of 10 kansuji mappings}
@d lc_code_base=kansuji_base+10 {table of 256 lowercase mappings}
@z

@x
@d char_sub_code(#)==equiv(char_sub_code_base+#)
  {Note: |char_sub_code(c)| is the true substitution info plus |min_halfword|}
@y
@d char_sub_code(#)==equiv(char_sub_code_base+#)
  {Note: |char_sub_code(c)| is the true substitution info plus |min_halfword|}
@#
@d cur_jfont==equiv(cur_jfont_loc) {pTeX: }
@d cur_tfont==equiv(cur_tfont_loc)
@d auto_spacing==equiv(auto_spacing_code)
@d auto_xspacing==equiv(auto_xspacing_code)
@d kcat_code(#)==equiv(kcat_code_base+#)
@d auto_xsp_code(#)==equiv(auto_xsp_code_base+#)
@d inhibit_xsp_type(#)==eq_type(inhibit_xsp_code_base+#)
@d inhibit_xsp_code(#)==equiv(inhibit_xsp_code_base+#)
@d kinsoku_type(#)==eq_type(kinsoku_base+#)
@d kinsoku_code(#)==equiv(kinsoku_base+#)
@d kansuji_char(#)==equiv(kansuji_base+#)
@z

@x
cur_font:=null_font; eq_type(cur_font_loc):=data;
eq_level(cur_font_loc):=level_one;@/
@y
cur_font:=null_font; eq_type(cur_font_loc):=data;
eq_level(cur_font_loc):=level_one;@/
cur_jfont:=null_font; eq_type(cur_jfont_loc):=data;
eq_level(cur_jfont_loc):=level_one;@/
cur_tfont:=null_font; eq_type(cur_tfont_loc):=data;
eq_level(cur_tfont_loc):=level_one;@/
@z

@x
for k:=0 to 255 do
  begin cat_code(k):=other_char; math_code(k):=hi(k); sf_code(k):=1000;
  end;
@y
eqtb[auto_spacing_code]:=eqtb[cat_code_base];
eqtb[auto_xspacing_code]:=eqtb[cat_code_base];
for k:=0 to 255 do
  begin cat_code(k):=other_char; kcat_code(k):=other_kchar;
  math_code(k):=hi(k); sf_code(k):=1000;
  auto_xsp_code(k):=0; inhibit_xsp_code(k):=0; inhibit_xsp_type(k):=0;
  kinsoku_code(k):=0; kinsoku_type(k):=0;
  end;
@z

@x
for k:="0" to "9" do math_code(k):=hi(k+var_code);
for k:="A" to "Z" do
  begin cat_code(k):=letter; cat_code(k+"a"-"A"):=letter;@/
  math_code(k):=hi(k+var_code+@"100);
  math_code(k+"a"-"A"):=hi(k+"a"-"A"+var_code+@"100);@/
  lc_code(k):=k+"a"-"A"; lc_code(k+"a"-"A"):=k+"a"-"A";@/
  uc_code(k):=k; uc_code(k+"a"-"A"):=k;@/
  sf_code(k):=999;
  end;
@y
for k:="0" to "9" do
  begin math_code(k):=hi(k+var_code);
  auto_xsp_code(k):=3;
  end;
kansuji_char(0):=toDVI(fromJIS(@"213B));
kansuji_char(1):=toDVI(fromJIS(@"306C));
kansuji_char(2):=toDVI(fromJIS(@"4673));
kansuji_char(3):=toDVI(fromJIS(@"3B30));
kansuji_char(4):=toDVI(fromJIS(@"3B4D));
kansuji_char(5):=toDVI(fromJIS(@"385E));
kansuji_char(6):=toDVI(fromJIS(@"4F3B));
kansuji_char(7):=toDVI(fromJIS(@"3C37));
kansuji_char(8):=toDVI(fromJIS(@"482C));
kansuji_char(9):=toDVI(fromJIS(@"3665));
for k:="A" to "Z" do
  begin cat_code(k):=letter; cat_code(k+"a"-"A"):=letter;@/
  math_code(k):=hi(k+var_code+@"100);
  math_code(k+"a"-"A"):=hi(k+"a"-"A"+var_code+@"100);@/
  lc_code(k):=k+"a"-"A"; lc_code(k+"a"-"A"):=k+"a"-"A";@/
  uc_code(k):=k; uc_code(k+"a"-"A"):=k;@/
  auto_xsp_code(k):=3; auto_xsp_code(k+"a"-"A"):=3;@/
  sf_code(k):=999;
  end;
@t\hskip10pt@>kcat_code(@"20+1):=other_kchar; {1 ku}
@t\hskip10pt@>kcat_code(@"20+2):=other_kchar; {2 ku}
@+@t\1@>for k:=3 to 6 do kcat_code(@"20+k):=kana; {3 ku ... 6 ku}
@+@t\1@>for k:=7 to 8 do kcat_code(@"20+k):=other_kchar; {7 ku ... 8 ku}
@+@t\1@>for k:=16 to 84 do kcat_code(@"20+k):=kanji; {16 ku ... 84 ku}
{ $\.{@@"20}+|k| = |kcatcodekey|(|fromKUTEN|(|HILO|(k,1))$ }
@z

@x
@ @<Show the halfword code in |eqtb[n]|@>=
if n<math_code_base then
  begin if n<lc_code_base then
    begin print_esc("catcode"); print_int(n-cat_code_base);
    end
@y
@ @<Show the halfword code in |eqtb[n]|@>=
if n<math_code_base then
  begin if n<kcat_code_base then
    begin print_esc("catcode"); print_int(n-cat_code_base);
    end
  else if n<auto_xsp_code_base then
    begin print_esc("kcatcode"); print_int(n-kcat_code_base);
    end
  else if n<inhibit_xsp_code_base then
    begin print_esc("xspcode"); print_int(n-auto_xsp_code_base);
    end
  else if n<kinsoku_base then
    begin print("(inhibitxspcode table) "); print_int(n-inhibit_xsp_code_base);
    end
  else if n<kansuji_base then
    begin print("(kinsoku table) "); print_int(n-kinsoku_base);
    end
  else if n<lc_code_base then
    begin print_esc("kansujichar"); print_int(n-kansuji_base);
    end
@z

@x
@d pretolerance_code=0 {badness tolerance before hyphenation}
@y

@d pretolerance_code=0 {badness tolerance before hyphenation}
@z

@x
@d cur_fam_code=44 {current family}
@d escape_char_code=45 {escape character for token output}
@d default_hyphen_char_code=46 {value of \.{\\hyphenchar} when a font is loaded}
@d default_skew_char_code=47 {value of \.{\\skewchar} when a font is loaded}
@d end_line_char_code=48 {character placed at the right end of the buffer}
@d new_line_char_code=49 {character that prints as |print_ln|}
@d language_code=50 {current hyphenation table}
@d left_hyphen_min_code=51 {minimum left hyphenation fragment size}
@d right_hyphen_min_code=52 {minimum right hyphenation fragment size}
@d holding_inserts_code=53 {do not remove insertion nodes from \.{\\box255}}
@d error_context_lines_code=54 {maximum intermediate line pairs shown}
@d tex_int_pars=55 {total number of \TeX's integer parameters}
@#
@d web2c_int_base=tex_int_pars {base for web2c's integer parameters}
@d char_sub_def_min_code=web2c_int_base {smallest value in the charsubdef list}
@d char_sub_def_max_code=web2c_int_base+1 {largest value in the charsubdef list}
@d tracing_char_sub_def_code=web2c_int_base+2 {traces changes to a charsubdef def}
@d web2c_int_pars=web2c_int_base+3 {total number of web2c's integer parameters}
@#
@d int_pars=web2c_int_pars {total number of integer parameters}
@d count_base=int_base+int_pars {256 user \.{\\count} registers}
@y
@d cur_fam_code=44 {current family}
@d cur_jfam_code=45 {current kanji family}
@d escape_char_code=46 {escape character for token output}
@d default_hyphen_char_code=47 {value of \.{\\hyphenchar} when a font is loaded}
@d default_skew_char_code=48 {value of \.{\\skewchar} when a font is loaded}
@d end_line_char_code=49 {character placed at the right end of the buffer}
@d new_line_char_code=50 {character that prints as |print_ln|}
@d language_code=51 {current hyphenation table}
@d left_hyphen_min_code=52 {minimum left hyphenation fragment size}
@d right_hyphen_min_code=53 {minimum right hyphenation fragment size}
@d holding_inserts_code=54 {do not remove insertion nodes from \.{\\box255}}
@d error_context_lines_code=55 {maximum intermediate line pairs shown}
@d jchr_widow_penalty_code=56
			{penalty for creating a widow KANJI character line}
@d text_baseline_shift_factor_code=57
@d script_baseline_shift_factor_code=58
@d scriptscript_baseline_shift_factor_code=59
@d char_sub_def_min_code=60 {smallest value in the charsubdef list}
@d char_sub_def_max_code=61 {largest value in the charsubdef list}
@d tracing_char_sub_def_code=62 {traces changes to a charsubdef def}
@d synctex_code=63
@d int_pars=synctex_code+1 {total number of integer parameters}
@d count_base=int_base+int_pars {256 user \.{\\count} registers}
@z

@x
@d cur_fam==int_par(cur_fam_code)
@d escape_char==int_par(escape_char_code)
@y
@d cur_fam==int_par(cur_fam_code)
@d cur_jfam==int_par(cur_jfam_code)
@d escape_char==int_par(escape_char_code)
@d jchr_widow_penalty==int_par(jchr_widow_penalty_code)
@d text_baseline_shift_factor==int_par(text_baseline_shift_factor_code)
@d script_baseline_shift_factor==int_par(script_baseline_shift_factor_code)
@d scriptscript_baseline_shift_factor==int_par(scriptscript_baseline_shift_factor_code)
@z

@x
@d error_context_lines==int_par(error_context_lines_code)
@y
@d error_context_lines==int_par(error_context_lines_code)
@#
@d synctex == int_par(synctex_code)
@z

@x
new_line_char_code:print_esc("newlinechar");
@y
new_line_char_code:print_esc("newlinechar");
cur_jfam_code:print_esc("jfam");
jchr_widow_penalty_code:print_esc("jcharwidowpenalty");
text_baseline_shift_factor_code:print_esc("textbaselineshiftfactor");
script_baseline_shift_factor_code:print_esc("scriptbaselineshiftfactor");
scriptscript_baseline_shift_factor_code:print_esc("scriptscriptbaselineshiftfactor");
@z

@x
primitive("newlinechar",assign_int,int_base+new_line_char_code);@/
@!@:new_line_char_}{\.{\\newlinechar} primitive@>
@y
primitive("newlinechar",assign_int,int_base+new_line_char_code);@/
@!@:new_line_char_}{\.{\\newlinechar} primitive@>
primitive("jfam",assign_int,int_base+cur_jfam_code);@/
@!@:cur_jfam_}{\.{\\jfam} primitive@>
primitive("jcharwidowpenalty",assign_int,int_base+jchr_widow_penalty_code);@/
@!@:jchr_widow_penalty}{\.{\\jcharwidowpenalty} primitive@>
primitive("textbaselineshiftfactor",assign_int,int_base+text_baseline_shift_factor_code);@/
@!@:text_baseline_shift_factor}{\.{\\textbaselineshiftfactor} primitive@>
primitive("scriptbaselineshiftfactor",assign_int,int_base+script_baseline_shift_factor_code);@/
@!@:script_baseline_shift_factor}{\.{\\scriptbaselineshiftfactor} primitive@>
primitive("scriptscriptbaselineshiftfactor",assign_int,int_base+scriptscript_baseline_shift_factor_code);@/
@!@:scriptscript_baseline_shift_factor}{\.{\\scriptscriptbaselineshiftfactor} primitive@>
@z

@x
@d h_offset_code=18 {amount of horizontal offset when shipping pages out}
@d v_offset_code=19 {amount of vertical offset when shipping pages out}
@d emergency_stretch_code=20 {reduces badnesses on final pass of line-breaking}
@d dimen_pars=21 {total number of dimension parameters}
@d scaled_base=dimen_base+dimen_pars
  {table of 256 user-defined \.{\\dimen} registers}
@d eqtb_size=scaled_base+255 {largest subscript of |eqtb|}
@y
@d h_offset_code=18 {amount of horizontal offset when shipping pages out}
@d v_offset_code=19 {amount of vertical offset when shipping pages out}
@d emergency_stretch_code=20 {reduces badnesses on final pass of line-breaking}
@d t_baseline_shift_code=21 {shift amount when mixing TATE-kumi and Alphabet}
@d y_baseline_shift_code=22 {shift amount when mixing YOKO-kumi and Alphabet}
@d dimen_pars=23 {total number of dimension parameters}
@d scaled_base=dimen_base+dimen_pars
  {table of 256 user-defined \.{\\dimen} registers}
@d kinsoku_penalty_base=scaled_base+256 {table of 256 kinsoku registers}
@d eqtb_size=kinsoku_penalty_base+255 {largest subscript of |eqtb|}
@z

@x
@d dimen(#)==eqtb[scaled_base+#].sc
@d dimen_par(#)==eqtb[dimen_base+#].sc {a scaled quantity}
@y
@d dimen(#)==eqtb[scaled_base+#].sc
@d dimen_par(#)==eqtb[dimen_base+#].sc {a scaled quantity}
@d kinsoku_penalty(#)==eqtb[kinsoku_penalty_base+#].int
@z

@x
@d h_offset==dimen_par(h_offset_code)
@d v_offset==dimen_par(v_offset_code)
@y
@d h_offset==dimen_par(h_offset_code)
@d v_offset==dimen_par(v_offset_code)
@d t_baseline_shift==dimen_par(t_baseline_shift_code)
@d y_baseline_shift==dimen_par(y_baseline_shift_code)
@z

@x
h_offset_code:print_esc("hoffset");
v_offset_code:print_esc("voffset");
emergency_stretch_code:print_esc("emergencystretch");
othercases print("[unknown dimen parameter!]")
@y
h_offset_code:print_esc("hoffset");
v_offset_code:print_esc("voffset");
t_baseline_shift_code:print_esc("tbaselineshift");
y_baseline_shift_code:print_esc("ybaselineshift");
emergency_stretch_code:print_esc("emergencystretch");
othercases print("[unknown dimen parameter!]")
@z

@x
primitive("hoffset",assign_dimen,dimen_base+h_offset_code);@/
@!@:h_offset_}{\.{\\hoffset} primitive@>
primitive("voffset",assign_dimen,dimen_base+v_offset_code);@/
@!@:v_offset_}{\.{\\voffset} primitive@>
@y
primitive("hoffset",assign_dimen,dimen_base+h_offset_code);@/
@!@:h_offset_}{\.{\\hoffset} primitive@>
primitive("voffset",assign_dimen,dimen_base+v_offset_code);@/
@!@:v_offset_}{\.{\\voffset} primitive@>
primitive("tbaselineshift",assign_dimen,dimen_base+t_baseline_shift_code);@/
@!@:t_baseline_shift_}{\.{\\tbaselineshift} primitive@>
primitive("ybaselineshift",assign_dimen,dimen_base+y_baseline_shift_code);@/
@!@:y_baseline_shift_}{\.{\\ybaselineshift} primitive@>
@z

@x
else if n<=eqtb_size then @<Show equivalent |n|, in region 6@>
else print_char("?"); {this can't happen either}
end;
tats
@y
else if n<kinsoku_penalty_base then @<Show equivalent |n|, in region 6@>
else if n<=eqtb_size then print("kinsoku")
else print_char("?"); {this can't happen either}
end;
tats
@z

@x
primitive("font",def_font,0);@/
@!@:font_}{\.{\\font} primitive@>
@y
primitive("font",def_font,0);@/
@!@:font_}{\.{\\font} primitive@>
primitive("jfont",def_jfont,0);@/
@!@:jfont_}{\.{\\jfont} primitive@>
primitive("tfont",def_tfont,0);@/
@!@:tfont_}{\.{\\tfont} primitive@>
@z

@x
def_font: print_esc("font");
@y
def_font: print_esc("font");
def_jfont: print_esc("jfont");
def_tfont: print_esc("tfont");
@z

@x
@d cs_token_flag==@'7777 {amount added to the |eqtb| location in a
  token that stands for a control sequence; is a multiple of~256, less~1}
@y
@d cs_token_flag==@"FFFF {amount added to the |eqtb| location in a
token that stands for a control sequence; is a multiple of~256, less~1}
@z

@x
@ @<Display token |p|...@>=
if (p<hi_mem_min) or (p>mem_end) then
  begin print_esc("CLOBBERED."); return;
@.CLOBBERED@>
  end;
if info(p)>=cs_token_flag then print_cs(info(p)-cs_token_flag)
else  begin m:=info(p) div @'400; c:=info(p) mod @'400;
  if info(p)<0 then print_esc("BAD.")
@.BAD@>
  else @<Display the token $(|m|,|c|)$@>;
  end
@y
@ @<Display token |p|...@>=
if (p<hi_mem_min) or (p>mem_end) then
  begin print_esc("CLOBBERED."); return;
@.CLOBBERED@>
  end;
if info(p)>=cs_token_flag then print_cs(info(p)-cs_token_flag) {|wchar_token|}
else  begin
  if check_kanji(info(p)) then {|wchar_token|}
    begin m:=kcat_code(kcatcodekey(info(p))); c:=info(p);
    end
  else  begin m:=Hi(info(p)); c:=Lo(info(p));
    end;
  if (m<kanji)and(c>256) then print_esc("BAD.")
@.BAD@>
  else @<Display the token $(|m|,|c|)$@>;
end
@z

@x
@<Display the token ...@>=
case m of
left_brace,right_brace,math_shift,tab_mark,sup_mark,sub_mark,spacer,
  letter,other_char: print(c);
@y
@<Display the token ...@>=
case m of
kanji,kana,other_kchar: print_kanji(KANJI(c));
left_brace,right_brace,math_shift,tab_mark,sup_mark,sub_mark,spacer,
  letter,other_char: print(c);
@z

@x
other_char: chr_cmd("the character ");
@y
other_char: chr_cmd("the character ");
kanji,kana,other_kchar: begin print("kanji character ");
  print_kanji(KANJI(chr_code)); end;
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
@d name==cur_input.name_field {name of the current file}
@y
@d name==cur_input.name_field {name of the current file}
@d synctex_tag==cur_input.synctex_tag_field {{\sl Sync\TeX} tag of the current file}
@z

@x
1) |state=mid_line| is the normal state.\cr
2) |state=skip_blanks| is like |mid_line|, but blanks are ignored.\cr
3) |state=new_line| is the state at the beginning of a line.\cr}}$$
@y
1) |state=mid_line| is the normal state.\cr
2) |state=mid_kanji| is like |mid_line|, and internal KANJI string.\cr
3) |state=skip_blanks| is like |mid_line|, but blanks are ignored.\cr
4) |state=new_line| is the state at the beginning of a line.\cr}}$$
@z

@x
@d mid_line=1 {|state| code when scanning a line of characters}
@d skip_blanks=2+max_char_code {|state| code when ignoring blanks}
@d new_line=3+max_char_code+max_char_code {|state| code at start of line}
@y
@d mid_line=1 {|state| code when scanning a line of characters}
@d mid_kanji=2+max_char_code {|state| code when scanning a line of characters}
@d skip_blanks=3+max_char_code+max_char_code {|state| code when ignoring blanks}
@d new_line=4+max_char_code+max_char_code+max_char_code
   {|state| code at start of line}
@z

@x
@p procedure show_context; {prints where the scanner is}
label done;
var old_setting:0..max_selector; {saved |selector| setting}
@y
@p procedure show_context; {prints where the scanner is}
label done, done1;
var old_setting:0..max_selector; {saved |selector| setting}
@!s: pointer; {temporary pointer}
@z

@x
@d begin_pseudoprint==
  begin l:=tally; tally:=0; selector:=pseudo;
  trick_count:=1000000;
  end
@y
@d begin_pseudoprint==
  begin l:=tally; tally:=0; selector:=pseudo; kcode_pos:=0;
  trick_count:=1000000;
  end
@z

@x
@d set_trick_count==
  begin first_count:=tally;
  trick_count:=tally+1+error_line-half_error_line;
  if trick_count<error_line then trick_count:=error_line;
  end
@y
@d set_trick_count==
  begin first_count:=tally;
  if (first_count>0)and(trick_buf2[(first_count-1)mod error_line]=1) then
      incr(first_count);
  trick_count:=first_count+1+error_line-half_error_line;
  if trick_count<error_line then trick_count:=error_line;
  end
@z

@x
for q:=p to first_count-1 do print_char(trick_buf[q mod error_line]);
print_ln;
for q:=1 to n do print_char(" "); {print |n| spaces to begin line~2}
if m+n<=error_line then p:=first_count+m else p:=first_count+(error_line-n-3);
@y
if trick_buf2[p mod error_line]=2 then
  begin p:=p+1; n:=n-1;
  end;
for q:=p to first_count-1 do print_char(trick_buf[q mod error_line]);
print_ln;
for q:=1 to n do print_char(" "); {print |n| spaces to begin line~2}
if m+n<=error_line then p:=first_count+m else p:=first_count+(error_line-n-3);
if trick_buf2[(p-1) mod error_line]=1 then p:=p-1;
@z

@x
@ @<Pseudoprint the token list@>=
begin_pseudoprint;
if token_type<macro then show_token_list(start,loc,100000)
else show_token_list(link(start),loc,100000) {avoid reference count}
@y
@ @<Pseudoprint the token list@>=
begin_pseudoprint;
if token_type<macro then
  begin  if (token_type=backed_up)and(loc<>null) then
    begin  if (link(start)=null)and(check_kanji(info(start))) then {|wchar_token|}
      begin cur_input:=input_stack[base_ptr-1];
      s:=get_avail; info(s):=Lo(info(loc));
      cur_input:=input_stack[base_ptr];
      link(start):=s;
      show_token_list(start,loc,100000);
      free_avail(s);link(start):=null;
      goto done1;
      end;
    end;
  show_token_list(start,loc,100000);
  end
else show_token_list(link(start),loc,100000); {avoid reference count}
done1:
@z

@x
@p procedure begin_file_reading;
@y
@p procedure begin_file_reading;
@z

@x
name:=0; {|terminal_input| is now |true|}
@y
name:=0; {|terminal_input| is now |true|}
@<Prepare terminal input {\sl Sync\TeX} information@>;
@z

@x
@!cat:0..max_char_code; {|cat_code(cur_chr)|, usually}
@y
@!cat:escape..max_char_code; {|cat_code(cur_chr)|, usually}
@!l:0..buf_size; {temporary index into |buffer|}
@z

@x
@ @<Input from external file, |goto restart| if no input found@>=
@^inner loop@>
begin switch: if loc<=limit then {current line not yet finished}
  begin cur_chr:=buffer[loc]; incr(loc);
  reswitch: cur_cmd:=cat_code(cur_chr);
@y
@ @<Input from external file, |goto restart| if no input found@>=
@^inner loop@>
begin switch: if loc<=limit then {current line not yet finished}
  begin cur_chr:=buffer[loc]; incr(loc);
    if multistrlen(ustringcast(buffer), limit+1, loc-1)=2 then
      begin cur_chr:=fromBUFF(ustringcast(buffer), limit+1, loc-1);
      cur_cmd:=kcat_code(kcatcodekey(cur_chr));
      incr(loc);
      end
    else reswitch: cur_cmd:=cat_code(cur_chr);
@z

@x
@d any_state_plus(#) == mid_line+#,skip_blanks+#,new_line+#
@y
@d any_state_plus(#) == mid_line+#,mid_kanji+#,skip_blanks+#,new_line+#
@z

@x
@ @d add_delims_to(#)==#+math_shift,#+tab_mark,#+mac_param,
  #+sub_mark,#+letter,#+other_char
@y
@ @d add_delims_to(#)==#+math_shift,#+tab_mark,#+mac_param,
  #+sub_mark,#+letter,#+other_char
@d all_jcode(#)==#+kanji,#+kana,#+other_kchar
@z

@x
mid_line+spacer:@<Enter |skip_blanks| state, emit a space@>;
mid_line+car_ret:@<Finish line, emit a space@>;
skip_blanks+car_ret,any_state_plus(comment):
  @<Finish line, |goto switch|@>;
new_line+car_ret:@<Finish line, emit a \.{\\par}@>;
mid_line+left_brace: incr(align_state);
skip_blanks+left_brace,new_line+left_brace: begin
  state:=mid_line; incr(align_state);
  end;
mid_line+right_brace: decr(align_state);
skip_blanks+right_brace,new_line+right_brace: begin
  state:=mid_line; decr(align_state);
  end;
add_delims_to(skip_blanks),add_delims_to(new_line): state:=mid_line;
@y
mid_kanji+spacer,mid_line+spacer:@<Enter |skip_blanks| state, emit a space@>;
mid_line+car_ret:@<Finish line, emit a space@>;
mid_kanji+car_ret: if skip_mode then @<Finish line, |goto switch|@>
  else @<Finish line, emit a space@>;
skip_blanks+car_ret,any_state_plus(comment):
  @<Finish line, |goto switch|@>;
new_line+car_ret:@<Finish line, emit a \.{\\par}@>;
mid_line+left_brace,mid_kanji+left_brace: incr(align_state);
skip_blanks+left_brace,new_line+left_brace: begin
  state:=mid_line; incr(align_state);
  end;
mid_line+right_brace,mid_kanji+right_brace: decr(align_state);
skip_blanks+right_brace,new_line+right_brace: begin
  state:=mid_line; decr(align_state);
  end;
add_delims_to(skip_blanks),add_delims_to(new_line),add_delims_to(mid_kanji):
  state:=mid_line;
all_jcode(skip_blanks),all_jcode(new_line),all_jcode(mid_line):
  state:=mid_kanji;

@ @<Global...@>=
skip_mode:boolean;

@ @<Set init...@>=
skip_mode:=true;
@z

@x
@<Scan a control...@>=
begin if loc>limit then cur_cs:=null_cs {|state| is irrelevant in this case}
else  begin start_cs: k:=loc; cur_chr:=buffer[k]; cat:=cat_code(cur_chr);
  incr(k);
  if cat=letter then state:=skip_blanks
  else if cat=spacer then state:=skip_blanks
  else state:=mid_line;
  if (cat=letter)and(k<=limit) then
    @<Scan ahead in the buffer until finding a nonletter;
    if an expanded code is encountered, reduce it
    and |goto start_cs|; otherwise if a multiletter control
    sequence is found, adjust |cur_cs| and |loc|, and
    |goto found|@>
  else @<If an expanded code is present, reduce it and |goto start_cs|@>;
  cur_cs:=single_base+buffer[loc]; incr(loc);
  end;
found: cur_cmd:=eq_type(cur_cs); cur_chr:=equiv(cur_cs);
if cur_cmd>=outer_call then check_outer_validity;
end
@y
@<Scan a control...@>=
begin if loc>limit then cur_cs:=null_cs {|state| is irrelevant in this case}
else  begin k:=loc; cur_chr:=buffer[k]; incr(k);
  if multistrlen(ustringcast(buffer), limit+1, k-1)=2 then
    begin cat:=kcat_code(kcatcodekey(fromBUFF(ustringcast(buffer), limit+1, k-1))); incr(k);
    end
  else cat:=cat_code(cur_chr);
start_cs:
  if (cat=letter)or(cat=kanji)or(cat=kana) then state:=skip_blanks
  else if cat=spacer then state:=skip_blanks
  else state:=mid_line;
  if cat=other_kchar then
    begin cur_cs:=id_lookup(loc,k-loc); loc:=k; goto found;
    end
  else if ((cat=letter)or(cat=kanji)or(cat=kana))and(k<=limit) then
    @<Scan ahead in the buffer until finding a nonletter;
    if an expanded code is encountered, reduce it
    and |goto start_cs|; otherwise if a multiletter control
    sequence is found, adjust |cur_cs| and |loc|, and
    |goto found|@>
  else @<If an expanded code is present, reduce it and |goto start_cs|@>;
  cur_cs:=single_base+buffer[loc]; incr(loc);
  end;
found: cur_cmd:=eq_type(cur_cs); cur_chr:=equiv(cur_cs);
if cur_cmd>=outer_call then check_outer_validity;
end
@z

@x
@<If an expanded...@>=
begin if buffer[k]=cur_chr then @+if cat=sup_mark then @+if k<limit then
  begin c:=buffer[k+1]; @+if c<@'200 then {yes, one is indeed present}
    begin d:=2;
    if is_hex(c) then @+if k+2<=limit then
      begin cc:=buffer[k+2]; @+if is_hex(cc) then incr(d);
      end;
    if d>2 then
      begin hex_to_cur_chr; buffer[k-1]:=cur_chr;
      end
    else if c<@'100 then buffer[k-1]:=c+@'100
    else buffer[k-1]:=c-@'100;
    limit:=limit-d; first:=first-d;
    while k<=limit do
      begin buffer[k]:=buffer[k+d]; incr(k);
      end;
    goto start_cs;
    end;
  end;
end
@y
@<If an expanded...@>=
begin if buffer[k]=cur_chr then @+if cat=sup_mark then @+if k<limit then
  begin c:=buffer[k+1]; @+if c<@'200 then {yes, one is indeed present}
    begin d:=2;
    if is_hex(c) then @+if k+2<=limit then
      begin cc:=buffer[k+2]; @+if is_hex(cc) then incr(d);
      end;
    if d>2 then
      begin hex_to_cur_chr; buffer[k-1]:=cur_chr;
      end
    else if c<@'100 then buffer[k-1]:=c+@'100
    else buffer[k-1]:=c-@'100;
    limit:=limit-d; first:=first-d;
    l:=k; cur_chr:=buffer[k-1]; cat:=cat_code(cur_chr);
    while l<=limit do
      begin buffer[l]:=buffer[l+d]; incr(l);
      end;
    goto start_cs;
    end;
  end;
end
@z

@x
@ @<Scan ahead in the buffer...@>=
begin repeat cur_chr:=buffer[k]; cat:=cat_code(cur_chr); incr(k);
until (cat<>letter)or(k>limit);
@<If an expanded...@>;
if cat<>letter then decr(k);
  {now |k| points to first nonletter}
if k>loc+1 then {multiletter control sequence has been scanned}
  begin cur_cs:=id_lookup(loc,k-loc); loc:=k; goto found;
  end;
end
@y
@ @<Scan ahead in the buffer...@>=
begin repeat cur_chr:=buffer[k]; incr(k);
  if multistrlen(ustringcast(buffer), limit+1, k-1)=2 then
    begin cat:=kcat_code(kcatcodekey(fromBUFF(ustringcast(buffer), limit+1, k-1))); incr(k);
    end
  else cat:=cat_code(cur_chr);
  while (buffer[k]=cur_chr)and(cat=sup_mark)and(k<limit) do
    begin c:=buffer[k+1]; @+if c<@'200 then {yes, one is indeed present}
      begin d:=2;
      if is_hex(c) then @+if k+2<=limit then
        begin cc:=buffer[k+2]; @+if is_hex(cc) then incr(d);
        end;
      if d>2 then
        begin hex_to_cur_chr;
        end
      else if c<@'100 then cur_chr:=c+@'100
      else cur_chr:=c-@'100;
      cat:=cat_code(cur_chr);
      if (cat=letter)or(cat=sup_mark) then
        begin buffer[k-1]:=cur_chr;
        limit:=limit-d; first:=first-d;
        l:=k;
        while l<=limit do
          begin buffer[l]:=buffer[l+d]; incr(l);
          end;
        end;
      end;
    end;
until not((cat=letter)or(cat=kanji)or(cat=kana))or(k>limit);
{@@<If an expanded...@@>;}
if not((cat=letter)or(cat=kanji)or(cat=kana)) then decr(k);
if cat=other_kchar then decr(k); {now |k| points to first nonletter}
if k>loc+1 then {multiletter control sequence has been scanned}
  begin cur_cs:=id_lookup(loc,k-loc); loc:=k; goto found;
  end;
end
@z

@x
@<Input from token list, |goto restart| if end of list or
  if a parameter needs to be expanded@>=
if loc<>null then {list not exhausted}
@^inner loop@>
  begin t:=info(loc); loc:=link(loc); {move to next}
  if t>=cs_token_flag then {a control sequence token}
    begin cur_cs:=t-cs_token_flag;
    cur_cmd:=eq_type(cur_cs); cur_chr:=equiv(cur_cs);
    if cur_cmd>=outer_call then
      if cur_cmd=dont_expand then
        @<Get the next token, suppressing expansion@>
      else check_outer_validity;
    end
  else  begin cur_cmd:=t div @'400; cur_chr:=t mod @'400;
    case cur_cmd of
    left_brace: incr(align_state);
    right_brace: decr(align_state);
    out_param: @<Insert macro parameter and |goto restart|@>;
    othercases do_nothing
    endcases;
    end;
  end
else  begin {we are done with this token list}
  end_token_list; goto restart; {resume previous level}
  end
@y
@<Input from token list, |goto restart| if end of list or
  if a parameter needs to be expanded@>=
if loc<>null then {list not exhausted}
@^inner loop@>
  begin t:=info(loc); loc:=link(loc); {move to next}
  if t>=cs_token_flag then {a control sequence token}
    begin cur_cs:=t-cs_token_flag;
    cur_cmd:=eq_type(cur_cs); cur_chr:=equiv(cur_cs);
    if cur_cmd>=outer_call then
      if cur_cmd=dont_expand then
        @<Get the next token, suppressing expansion@>
      else check_outer_validity;
    end
  else if check_kanji(t) then {|wchar_token|}
    begin cur_chr:=t; cur_cmd:=kcat_code(kcatcodekey(t));
    end
  else
    begin cur_cmd:=Hi(t); cur_chr:=Lo(t);
    case cur_cmd of
    left_brace: incr(align_state);
    right_brace: decr(align_state);
    out_param: @<Insert macro parameter and |goto restart|@>;
    othercases do_nothing
    endcases;
    end;
  end
else  begin {we are done with this token list}
  end_token_list; goto restart; {resume previous level}
  end
@z

@x
@p procedure get_token; {sets |cur_cmd|, |cur_chr|, |cur_tok|}
begin no_new_control_sequence:=false; get_next; no_new_control_sequence:=true;
@^inner loop@>
if cur_cs=0 then cur_tok:=(cur_cmd*@'400)+cur_chr
else cur_tok:=cs_token_flag+cur_cs;
end;
@y
@p procedure get_token; {sets |cur_cmd|, |cur_chr|, |cur_tok|}
begin no_new_control_sequence:=false; get_next; no_new_control_sequence:=true;
@^inner loop@>
if cur_cs=0 then
  if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then {|wchar_token|}
    cur_tok:=cur_chr
  else cur_tok:=(cur_cmd*@'400)+cur_chr
else cur_tok:=cs_token_flag+cur_cs;
end;
@z

@x
@ @<Look up the characters of list |r| in the hash table...@>=
j:=first; p:=link(r);
while p<>null do
  begin if j>=max_buf_stack then
    begin max_buf_stack:=j+1;
    if max_buf_stack=buf_size then
      overflow("buffer size",buf_size);
@:TeX capacity exceeded buffer size}{\quad buffer size@>
    end;
  buffer[j]:=info(p) mod @'400; incr(j); p:=link(p);
  end;
@y
@ @<Look up the characters of list |r| in the hash table...@>=
j:=first; p:=link(r);
while p<>null do
  begin if j>=max_buf_stack then
    begin max_buf_stack:=j+1;
    if max_buf_stack=buf_size then
      overflow("buffer size",buf_size);
@:TeX capacity exceeded buffer size}{\quad buffer size@>
    end;
  if check_kanji(info(p)) then {|wchar_token|}
    begin buffer[j]:=Hi(info(p)); incr(j);
    end;
  buffer[j]:=Lo(info(p)); incr(j); p:=link(p);
  end;
@z

@x
@p procedure get_x_token; {sets |cur_cmd|, |cur_chr|, |cur_tok|,
  and expands macros}
label restart,done;
begin restart: get_next;
@^inner loop@>
if cur_cmd<=max_command then goto done;
if cur_cmd>=call then
  if cur_cmd<end_template then macro_call
  else  begin cur_cs:=frozen_endv; cur_cmd:=endv;
    goto done; {|cur_chr=null_list|}
    end
else expand;
goto restart;
done: if cur_cs=0 then cur_tok:=(cur_cmd*@'400)+cur_chr
else cur_tok:=cs_token_flag+cur_cs;
end;
@y
@p procedure get_x_token; {sets |cur_cmd|, |cur_chr|, |cur_tok|,
  and expands macros}
label restart,done;
begin restart: get_next;
@^inner loop@>
if cur_cmd<=max_command then goto done;
if cur_cmd>=call then
  if cur_cmd<end_template then macro_call
  else  begin cur_cs:=frozen_endv; cur_cmd:=endv;
    goto done; {|cur_chr=null_list|}
    end
else expand;
goto restart;
done: if cur_cs=0 then
  if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then
    cur_tok:=cur_chr
  else cur_tok:=(cur_cmd*@'400)+cur_chr
else cur_tok:=cs_token_flag+cur_cs;
end;
@z

@x
@p procedure x_token; {|get_x_token| without the initial |get_next|}
begin while cur_cmd>max_command do
  begin expand;
  get_next;
  end;
if cur_cs=0 then cur_tok:=(cur_cmd*@'400)+cur_chr
else cur_tok:=cs_token_flag+cur_cs;
@y
@p procedure x_token; {|get_x_token| without the initial |get_next|}
begin while cur_cmd>max_command do
  begin expand;
  get_next;
  end;
if cur_cs=0 then
  if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then
    cur_tok:=cur_chr
  else cur_tok:=(cur_cmd*@'400)+cur_chr
else cur_tok:=cs_token_flag+cur_cs;
@z

@x
@p procedure scan_something_internal(@!level:small_number;@!negative:boolean);
@y
@p @t\4@>@<Declare procedures needed in |scan_something_internal|@>@t@>@/
procedure scan_something_internal(@!level:small_number;@!negative:boolean);
@z

@x
var m:halfword; {|chr_code| part of the operand token}
@y
var m:halfword; {|chr_code| part of the operand token}
@!tx:pointer; {effective tail node}
@!qx:halfword; {general purpose index}
@z

@x
begin m:=cur_chr;
case cur_cmd of
def_code: @<Fetch a character code from some table@>;
toks_register,assign_toks,def_family,set_font,def_font: @<Fetch a token list or
  font identifier, provided that |level=tok_val|@>;
@y
@!q,@!r:pointer;
begin m:=cur_chr;
case cur_cmd of
assign_kinsoku: @<Fetch breaking penalty from some table@>;
assign_inhibit_xsp_code: @<Fetch inhibit type from some table@>;
def_code: @<Fetch a character code from some table@>;
toks_register,assign_toks,def_family,set_font,def_font,def_jfont,def_tfont:
  @<Fetch a token list or font identifier, provided that |level=tok_val|@>;
@z

@x
if m=math_code_base then scanned_result(ho(math_code(cur_val)))(int_val)
else if m<math_code_base then scanned_result(equiv(m+cur_val))(int_val)
else scanned_result(eqtb[m+cur_val].int)(int_val);
@y
if m=math_code_base then scanned_result(ho(math_code(cur_val)))(int_val)
else if m=kcat_code_base then scanned_result(equiv(m+kcatcodekey(cur_val)))(int_val)
else if m<math_code_base then { \.{\\lccode}, \.{\\uccode}, \.{\\sfcode}, \.{\\catcode} }
  begin if not is_char_ascii(cur_val) then
  scanned_result(equiv(m+Hi(cur_val)))(int_val)
  else scanned_result(equiv(m+cur_val))(int_val)
  end
else { \.{\\delcode} }
  begin if not is_char_ascii(cur_val) then
  scanned_result(eqtb[m+Hi(cur_val)].int)(int_val)
  else scanned_result(eqtb[m+cur_val].int)(int_val)
  end;
@z

@x
begin scan_eight_bit_int;
if box(cur_val)=null then cur_val:=0 @+else cur_val:=mem[box(cur_val)+m].sc;
@y
begin scan_eight_bit_int; q:=box(cur_val);
if q=null then cur_val:=0
else  begin qx:=q;
  while (q<>null)and(box_dir(q)<>abs(direction)) do q:=link(q);
  if q=null then
    begin r:=link(qx); link(qx):=null;
    q:=new_dir_node(qx,abs(direction)); link(qx):=r;
    cur_val:=mem[q+m].sc;
    delete_glue_ref(space_ptr(q)); delete_glue_ref(xspace_ptr(q));
    free_node(q,box_node_size);
    end
  else cur_val:=mem[q+m].sc;
  end;
@z

@x
legal in similar contexts.
@y
legal in similar contexts.

The macro |find_effective_tail_pTeX| sets |tx| to the last non-|disp_node|
of the current list.
@z

@x
@<Fetch an item in the current node...@>=
@y
@d find_effective_tail_pTeX==
tx:=tail;
if not is_char_node(tx) then
  if type(tx)=disp_node then
    begin tx:=prev_node;
    if not is_char_node(tx) then
      if type(tx)=disp_node then {|disp_node| from a discretionary}
        begin tx:=head; q:=link(head);
        while q<>prev_node do
          begin if is_char_node(q) then tx:=q
          else if type(q)<>disp_node then tx:=q;
          end;
        q:=link(q);
        end;
    end
@#
@d find_effective_tail==find_effective_tail_pTeX

@<Fetch an item in the current node...@>=
@z

@x
else begin if cur_chr=glue_val then cur_val:=zero_glue@+else cur_val:=0;
@y
else begin if cur_chr=glue_val then cur_val:=zero_glue@+else cur_val:=0;
  find_effective_tail;
@z

@x
  if not is_char_node(tail)and(mode<>0) then
    case cur_chr of
    int_val: if type(tail)=penalty_node then cur_val:=penalty(tail);
    dimen_val: if type(tail)=kern_node then cur_val:=width(tail);
    glue_val: if type(tail)=glue_node then
      begin cur_val:=glue_ptr(tail);
      if subtype(tail)=mu_glue then cur_val_level:=mu_val;
      end;
@y
  if not is_char_node(tx)and(tx<>head)and(mode<>0) then
    case cur_chr of
    int_val: if type(tx)=penalty_node then cur_val:=penalty(tx);
    dimen_val: if type(tx)=kern_node then cur_val:=width(tx);
    glue_val: if type(tx)=glue_node then
      begin cur_val:=glue_ptr(tx);
      if subtype(tx)=mu_glue then cur_val_level:=mu_val;
      end;
@z

@x
  else if (mode=vmode)and(tail=head) then
@y
  else if (mode=vmode)and(tx=head) then
@z

@x
procedure scan_char_num;
begin scan_int;
if (cur_val<0)or(cur_val>255) then
  begin print_err("Bad character code");
@.Bad character code@>
  help2("A character number must be between 0 and 255.")@/
    ("I changed this one to zero."); int_error(cur_val); cur_val:=0;
  end;
end;
@y
procedure scan_char_num;
begin scan_int;
if not is_char_ascii(cur_val) and not is_char_kanji(cur_val) then
  begin print_err("Bad character code");
@.Bad character code@>
  help2("A character number must be between 0 and 255, or KANJI code.")@/
    ("I changed this one to zero."); int_error(cur_val); cur_val:=0;
  end;
end;
@z

@x
@<Scan an alphabetic character code into |cur_val|@>=
begin get_token; {suppress macro expansion}
if cur_tok<cs_token_flag then
  begin cur_val:=cur_chr;
  if cur_cmd<=right_brace then
    if cur_cmd=right_brace then incr(align_state)
    else decr(align_state);
  end
else if cur_tok<cs_token_flag+single_base then
  cur_val:=cur_tok-cs_token_flag-active_base
else cur_val:=cur_tok-cs_token_flag-single_base;
if cur_val>255 then
  begin print_err("Improper alphabetic constant");
@.Improper alphabetic constant@>
  help2("A one-character control sequence belongs after a ` mark.")@/
    ("So I'm essentially inserting \0 here.");
  cur_val:="0"; back_error;
  end
else @<Scan an optional space@>;
end
@y
@<Scan an alphabetic character code into |cur_val|@>=
begin get_token; {suppress macro expansion}
if cur_tok<cs_token_flag then
  if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then {|wchar_token|}
    begin skip_mode:=false; cur_val:=tonum(cur_chr);
    end
  else begin cur_val:=cur_chr;
  if cur_cmd<=right_brace then
    if cur_cmd=right_brace then incr(align_state)
    else decr(align_state);
  end
else if cur_tok<cs_token_flag+single_base then
  cur_val:=cur_tok-cs_token_flag-active_base
else cur_val:=cur_tok-cs_token_flag-single_base;
if (cur_val>255)and((cur_cmd<kanji)or(cur_cmd>max_char_code)) then
  begin print_err("Improper alphabetic or KANJI constant");
@.Improper alphabetic constant@>
  help2("A one-character control sequence belongs after a ` mark.")@/
    ("So I'm essentially inserting \0 here.");
  cur_val:="0"; back_error;
  end
else @<Scan an optional space@>;
skip_mode:=true;
end
@z

@x
if scan_keyword("em") then v:=(@<The em width for |cur_font|@>)
@.em@>
else if scan_keyword("ex") then v:=(@<The x-height for |cur_font|@>)
@.ex@>
else goto not_found;
@y
if scan_keyword("em") then v:=(@<The em width for |cur_font|@>)
@.em@>
else if scan_keyword("ex") then v:=(@<The x-height for |cur_font|@>)
@.ex@>
else if scan_keyword("zw") then @<The KANJI width for |cur_jfont|@>
@.ze@>
else if scan_keyword("zh") then @<The KANJI height for |cur_jfont|@>
@.zh@>
else goto not_found;
@z

@x
else if scan_keyword("sp") then goto done
@.sp@>
@y
else if scan_keyword("H") then set_conversion(7227)(10160)
@.H@>
else if scan_keyword("Q") then set_conversion(7227)(10160)
@.Q@>
else if scan_keyword("sp") then goto done
@.sp@>
@z

@x
  if t=" " then t:=space_token
  else t:=other_token+t;
@y
  if multistrlen(ustringcast(str_pool), pool_ptr, k)=2 then
    begin t:=fromBUFF(ustringcast(str_pool), pool_ptr, k); incr(k);
    end
  else if t=" " then t:=space_token
  else t:=other_token+t;
@z

@x
@d number_code=0 {command code for \.{\\number}}
@d roman_numeral_code=1 {command code for \.{\\romannumeral}}
@d string_code=2 {command code for \.{\\string}}
@d meaning_code=3 {command code for \.{\\meaning}}
@d font_name_code=4 {command code for \.{\\fontname}}
@d job_name_code=5 {command code for \.{\\jobname}}
@y
@d number_code=0 {command code for \.{\\number}}
@d roman_numeral_code=1 {command code for \.{\\romannumeral}}
@d kansuji_code=2 {command code for \.{\\kansuji}}
@d string_code=3 {command code for \.{\\string}}
@d meaning_code=4 {command code for \.{\\meaning}}
@d font_name_code=5 {command code for \.{\\fontname}}
@d euc_code=6 {command code for \.{\\euc}}
@d sjis_code=7 {command code for \.{\\sjis}}
@d jis_code=8 {command code for \.{\\jis}}
@d kuten_code=9 {command code for \.{\\kuten}}
@d ptex_convert_codes=10 {end of \pTeX's command codes}
@d job_name_code=ptex_convert_codes {command code for \.{\\jobname}}
@z

@x
primitive("fontname",convert,font_name_code);@/
@!@:font_name_}{\.{\\fontname} primitive@>
@y
primitive("fontname",convert,font_name_code);@/
@!@:font_name_}{\.{\\fontname} primitive@>
primitive("kansuji",convert,kansuji_code);
@!@:kansuji_}{\.{\\kansuji} primitive@>
primitive("euc",convert,euc_code);
@!@:euc_}{\.{\\euc} primitive@>
primitive("sjis",convert,sjis_code);
@!@:sjis_}{\.{\\sjis} primitive@>
primitive("jis",convert,jis_code);
@!@:jis_}{\.{\\jis} primitive@>
primitive("kuten",convert,kuten_code);
@!@:kuten_}{\.{\\kuten} primitive@>
@z

@x
  font_name_code: print_esc("fontname");
@y
  font_name_code: print_esc("fontname");
  kansuji_code: print_esc("kansuji");
  euc_code:print_esc("euc");
  sjis_code:print_esc("sjis");
  jis_code:print_esc("jis");
  kuten_code:print_esc("kuten");
@z

@x
@p procedure conv_toks;
var old_setting:0..max_selector; {holds |selector| setting}
@y
@p procedure conv_toks;
var old_setting:0..max_selector; {holds |selector| setting}
@!cx:KANJI_code; {temporary register for KANJI}
@z

@x
@ @<Scan the argument for command |c|@>=
case c of
number_code,roman_numeral_code: scan_int;
string_code, meaning_code: begin save_scanner_status:=scanner_status;
  scanner_status:=normal; get_token; scanner_status:=save_scanner_status;
  end;
@y
@ @<Scan the argument for command |c|@>=
KANJI(cx):=0;
case c of
number_code,roman_numeral_code,
kansuji_code,euc_code,sjis_code,jis_code,kuten_code: scan_int;
string_code, meaning_code: begin save_scanner_status:=scanner_status;
  scanner_status:=normal; get_token;
  if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then {|wchar_token|}
    KANJI(cx):=cur_tok;
  scanner_status:=save_scanner_status;
  end;
@z

@x
@ @<Print the result of command |c|@>=
case c of
number_code: print_int(cur_val);
roman_numeral_code: print_roman_int(cur_val);
string_code:if cur_cs<>0 then sprint_cs(cur_cs)
  else print_char(cur_chr);
@y
@ @<Print the result of command |c|@>=
case c of
number_code: print_int(cur_val);
roman_numeral_code: print_roman_int(cur_val);
jis_code:   print_int(fromJIS(cur_val));
euc_code:   print_int(fromEUC(cur_val));
sjis_code:  print_int(fromSJIS(cur_val));
kuten_code: print_int(fromKUTEN(cur_val));
kansuji_code: print_kansuji(cur_val);
string_code:if cur_cs<>0 then sprint_cs(cur_cs)
  else if KANJI(cx)=0 then print_char(cur_chr)
  else print_kanji(cx);
@z

@x
@d if_case_code=16 { `\.{\\ifcase}' }
@y
@d if_case_code=16 { `\.{\\ifcase}' }
@#
@d if_tdir_code=if_case_code+1 { `\.{\\iftdir}' }
@d if_ydir_code=if_tdir_code+1 { `\.{\\ifydir}' }
@d if_ddir_code=if_ydir_code+1 { `\.{\\ifddir}' }
@d if_mdir_code=if_ddir_code+1 { `\.{\\ifmdir}' }
@d if_tbox_code=if_mdir_code+1 { `\.{\\iftbox}' }
@d if_ybox_code=if_tbox_code+1 { `\.{\\ifybox}' }
@d if_dbox_code=if_ybox_code+1 { `\.{\\ifdbox}' }
@z

@x
primitive("ifcase",if_test,if_case_code);
@!@:if_case_}{\.{\\ifcase} primitive@>
@y
primitive("ifcase",if_test,if_case_code);
@!@:if_case_}{\.{\\ifcase} primitive@>
primitive("iftdir",if_test,if_tdir_code);
@!@:if_tdir_}{\.{\\iftdir} primitive@>
primitive("ifydir",if_test,if_ydir_code);
@!@:if_ydir_}{\.{\\ifydir} primitive@>
primitive("ifddir",if_test,if_ddir_code);
@!@:if_ddir_}{\.{\\ifddir} primitive@>
primitive("ifmdir",if_test,if_mdir_code);
@!@:if_mdir_}{\.{\\ifmdir} primitive@>
primitive("iftbox",if_test,if_tbox_code);
@!@:if_tbox_}{\.{\\iftbox} primitive@>
primitive("ifybox",if_test,if_ybox_code);
@!@:if_ybox_}{\.{\\ifybox} primitive@>
primitive("ifdbox",if_test,if_dbox_code);
@!@:if_dbox_}{\.{\\ifdbox} primitive@>
@z

@x
  if_case_code:print_esc("ifcase");
@y
  if_case_code:print_esc("ifcase");
  if_tdir_code:print_esc("iftdir");
  if_ydir_code:print_esc("ifydir");
  if_ddir_code:print_esc("ifddir");
  if_mdir_code:print_esc("ifmdir");
  if_tbox_code:print_esc("iftbox");
  if_ybox_code:print_esc("ifybox");
  if_dbox_code:print_esc("ifdbox");
@z

@x
if_void_code, if_hbox_code, if_vbox_code: @<Test box register status@>;
@y
if_tdir_code: b:=(abs(direction)=dir_tate);
if_ydir_code: b:=(abs(direction)=dir_yoko);
if_ddir_code: b:=(abs(direction)=dir_dtou);
if_mdir_code: b:=(direction<0);
if_void_code, if_hbox_code, if_vbox_code, if_tbox_code, if_ybox_code, if_dbox_code:
  @<Test box register status@>;
@z

@x
if this_if=if_void_code then b:=(p=null)
else if p=null then b:=false
else if this_if=if_hbox_code then b:=(type(p)=hlist_node)
else b:=(type(p)=vlist_node);
@y
if this_if=if_void_code then b:=(p=null)
else if p=null then b:=false
else begin
  if type(p)=dir_node then p:=list_ptr(p);
  if this_if=if_hbox_code then b:=(type(p)=hlist_node)
  else if this_if=if_vbox_code then b:=(type(p)=vlist_node)
  else if this_if=if_tbox_code then b:=(box_dir(p)=dir_tate)
  else if this_if=if_ybox_code then b:=(box_dir(p)=dir_yoko)
  else b:=(box_dir(p)=dir_dtou);
  end
@z

@x
if (cur_cmd>active_char)or(cur_chr>255) then {not a character}
  begin m:=relax; n:=256;
  end
else  begin m:=cur_cmd; n:=cur_chr;
  end;
get_x_token_or_active_char;
if (cur_cmd>active_char)or(cur_chr>255) then
  begin cur_cmd:=relax; cur_chr:=256;
  end;
@y
if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then
  begin m:=cur_cmd; n:=cur_chr;
  end
else if (cur_cmd>active_char)or(cur_chr>255) then
  begin m:=relax; n:=256;
  end
else  begin m:=cur_cmd; n:=cur_chr;
  end;
get_x_token_or_active_char;
if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then
  begin cur_cmd:=cur_cmd;
  end {dummy}
else if (cur_cmd>active_char)or(cur_chr>255) then
  begin cur_cmd:=relax; cur_chr:=256;
  end;
@z

@x
@p procedure begin_name;
begin area_delimiter:=0; ext_delimiter:=0; quoted_filename:=false;
end;
@y
@p procedure begin_name;
begin area_delimiter:=0; ext_delimiter:=0; quoted_filename:=false; prev_char:=0;
end;
@z

@x
else  begin str_room(1); append_char(c); {contribute |c| to the current string}
  if IS_DIR_SEP(c) then
    begin area_delimiter:=cur_length; ext_delimiter:=0;
    end
  else if c="." then ext_delimiter:=cur_length;
  more_name:=true;
  end;
end;
@y
else  begin str_room(1); append_char(c); {contribute |c| to the current string}
  if (IS_DIR_SEP(c)and(not_kanji_char_seq(prev_char,c))) then
    begin area_delimiter:=cur_length; ext_delimiter:=0;
    end
  else if c="." then ext_delimiter:=cur_length;
  more_name:=true;
  end;
  prev_char:=c;
end;
@z

@x
loop@+begin if (cur_cmd>other_char)or(cur_chr>255) then {not a character}
    begin back_input; goto done;
    end;
  {If |cur_chr| is a space and we're not scanning a token list, check
   whether we're at the end of the buffer. Otherwise we end up adding
   spurious spaces to file names in some cases.}
  if (cur_chr=" ") and (state<>token_list) and (loc>limit) then goto done;
  if not more_name(cur_chr) then goto done;
  get_x_token;
  end;
done: end_name; name_in_progress:=false;
@y
skip_mode:=false;
loop@+begin
  if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then {is kanji}
    begin str_room(2);
    append_char(Hi(cur_chr)); {kanji upper byte}
    append_char(Lo(cur_chr)); {kanji lower byte}
    end
  else if (cur_cmd>other_char)or(cur_chr>255) then {not a alphabet}
    begin back_input; goto done;
    end
  {If |cur_chr| is a space and we're not scanning a token list, check
   whether we're at the end of the buffer. Otherwise we end up adding
   spurious spaces to file names in some cases.}
   else if ((cur_chr=" ") and (state<>token_list) and (loc>limit)) or not more_name(cur_chr) then goto done;
  get_x_token;
  end;
done: end_name; name_in_progress:=false;
skip_mode:=true;
@z

@x
begin
if src_specials_p or file_line_error_style_p or parse_first_line_p
then
  wlog(banner_k)
else
  wlog(banner);
@y
begin
if src_specials_p or file_line_error_style_p or parse_first_line_p
then
  wlog(banner_k)
else
  wlog(banner);
  wlog(' (');
  wlog(conststringcast(get_enc_string));
  wlog(')');
@z

@x
@p procedure start_input; {\TeX\ will \.{\\input} something}
@y
@p procedure start_input; {\TeX\ will \.{\\input} something}
@z

@x
@<Read the first line of the new file@>;
@y
@<Prepare new file {\sl Sync\TeX} information@>;
@<Read the first line of the new file@>;
@z

@x
This is called BigEndian order.
@!@^BigEndian order@>
@y
This is called BigEndian order.
@!@^BigEndian order@>

We use to get \TeX\ knowledge about KANJI fonts from \.{JFM} files.
The \.{JFM} format holds more two 16-bit integers ,|id| and |nt|,
at the top of the file.
$$\vbox{\halign{\hfil#&$\null=\null$#\hfil\cr
|id|&identification code of the file;\cr
|nt|&number of words in the |char_type| table;\cr}}$$
The identification byte, |id| equals~11 or~9. When \TeX read a font file,
the |id| equals~11 or~9 then the font is the \.{JFM}, othercases it is
the \.{TFM} file. The \.{TFM} holds |lf| at the same postion of |id|,
usually it take a larger number than~9 or~11.
The |nt| is nonngative and less than $2^{15}$.

We must have |ec=0|,
$$\hbox{|lf=7+lh+nt+(ec-bc+1)+nw+nh+nd+ni+nl+nk+ne+np|.}$$

@d yoko_jfm_id=11 {for `yoko-kumi' fonts}
@d tate_jfm_id=9  {for `tate-kumi' fonts}
@z

@x
operation looks for both |list_tag| and |ext_tag|.
@y
operation looks for both |list_tag| and |ext_tag|.

If the \.{JFM}, the |lig_tag| is called |gk_tag|. The |gk_tag| means that
this character has a glue/kerning program starting at position |remainder|
in the |glue_kern| array. And a \.{JFM} not used |tag=2| and |tag=3|.
@z

@x
@d lig_tag=1 {character has a ligature/kerning program}
@y
@d lig_tag=1 {character has a ligature/kerning program}
@d gk_tag=1 {character has a glue/kerning program}
@z

@x
@<Glob...@>=
@!font_info: ^fmemory_word;
@y
@<Glob...@>=
@!font_info: ^memory_word; {pTeX: use halfword for |char_type| table.}
@!font_dir: ^eight_bits;
  {pTeX: direction of fonts, 0 is default, 1 is Yoko, 2 is Tate}
@!font_num_ext: ^integer;
  {pTeX: number of the |char_type| table.}
@z

@x
@!char_base: ^integer;
  {base addresses for |char_info|}
@y
@!char_base: ^integer;
  {base addresses for |char_info|}
@!ctype_base: ^integer;
  {pTeX: base addresses for KANJI character type parameters}
@z

@x
@d orig_char_info_end(#)==#].qqqq
@d orig_char_info(#)==font_info[char_base[#]+orig_char_info_end
@y
@d orig_char_info_end(#)==#].qqqq
@d orig_char_info(#)==font_info[char_base[#]+orig_char_info_end
@#
@d kchar_code_end(#)==#].hh.rh
@d kchar_code(#)==font_info[ctype_base[#]+kchar_code_end
@d kchar_type_end(#)==#].hh.lhfield
@d kchar_type(#)==font_info[ctype_base[#]+kchar_type_end
@z

@x
@d lig_kern_start(#)==lig_kern_base[#]+rem_byte {beginning of lig/kern program}
@y
@d lig_kern_start(#)==lig_kern_base[#]+rem_byte {beginning of lig/kern program}
@d glue_kern_start(#)==lig_kern_base[#]+rem_byte
  {beginning of glue/kern program}
@z

@x
var k:font_index; {index into |font_info|}
@y
var k:font_index; {index into |font_info|}
@!jfm_flag:dir_default..dir_tate; {direction of the \.{JFM}}
@!nt:halfword; {number of the |char_type| tables}
@!cx:KANJI_code; {kanji code}
@z

@x
@ @<Read the {\.{TFM}} size fields@>=
begin read_sixteen(lf);
fget; read_sixteen(lh);
fget; read_sixteen(bc);
fget; read_sixteen(ec);
if (bc>ec+1)or(ec>255) then abort;
if bc>255 then {|bc=256| and |ec=255|}
  begin bc:=1; ec:=0;
  end;
fget; read_sixteen(nw);
fget; read_sixteen(nh);
fget; read_sixteen(nd);
fget; read_sixteen(ni);
fget; read_sixteen(nl);
fget; read_sixteen(nk);
fget; read_sixteen(ne);
fget; read_sixteen(np);
if lf<>6+lh+(ec-bc+1)+nw+nh+nd+ni+nl+nk+ne+np then abort;
if (nw=0)or(nh=0)or(nd=0)or(ni=0) then abort;
end
@y
@ @<Read the {\.{TFM}} size fields@>=
begin read_sixteen(lf);
fget; read_sixteen(lh);
if lf=yoko_jfm_id then
  begin jfm_flag:=dir_yoko; nt:=lh;
  fget; read_sixteen(lf);
  fget; read_sixteen(lh);
  end
else if lf=tate_jfm_id then
  begin jfm_flag:=dir_tate; nt:=lh;
  fget; read_sixteen(lf);
  fget; read_sixteen(lh);
  end
else begin jfm_flag:=dir_default; nt:=0;
  end;
fget; read_sixteen(bc);
fget; read_sixteen(ec);
if (bc>ec+1)or(ec>255) then abort;
if bc>255 then {|bc=256| and |ec=255|}
  begin bc:=1; ec:=0;
  end;
fget; read_sixteen(nw);
fget; read_sixteen(nh);
fget; read_sixteen(nd);
fget; read_sixteen(ni);
fget; read_sixteen(nl);
fget; read_sixteen(nk);
fget; read_sixteen(ne);
fget; read_sixteen(np);
if jfm_flag<>dir_default then
  begin if lf<>7+lh+nt+(ec-bc+1)+nw+nh+nd+ni+nl+nk+ne+np then abort;
  end
else
  begin if lf<>6+lh+(ec-bc+1)+nw+nh+nd+ni+nl+nk+ne+np then abort;
  end;
if (nw=0)or(nh=0)or(nd=0)or(ni=0) then abort;
end
@z

@x
@<Use size fields to allocate font information@>=
lf:=lf-6-lh; {|lf| words should be loaded into |font_info|}
if np<7 then lf:=lf+7-np; {at least seven parameters will appear}
if (font_ptr=font_max)or(fmem_ptr+lf>font_mem_size) then
  @<Apologize for not loading the font, |goto done|@>;
f:=font_ptr+1;
char_base[f]:=fmem_ptr-bc;
width_base[f]:=char_base[f]+ec+1;
height_base[f]:=width_base[f]+nw;
depth_base[f]:=height_base[f]+nh;
italic_base[f]:=depth_base[f]+nd;
lig_kern_base[f]:=italic_base[f]+ni;
kern_base[f]:=lig_kern_base[f]+nl-kern_base_offset;
exten_base[f]:=kern_base[f]+kern_base_offset+nk;
param_base[f]:=exten_base[f]+ne
@y
@<Use size fields to allocate font information@>=
if jfm_flag<>dir_default then
  lf:=lf-7-lh  {If \.{JFM}, |lf| holds more two-16bit records than \.{TFM}}
else
  lf:=lf-6-lh; {|lf| words should be loaded into |font_info|}
if np<7 then lf:=lf+7-np; {at least seven parameters will appear}
if (font_ptr=font_max)or(fmem_ptr+lf>font_mem_size) then
  @<Apologize for not loading the font, |goto done|@>;
f:=font_ptr+1;
font_dir[f]:=jfm_flag;
font_num_ext[f]:=nt;
ctype_base[f]:=fmem_ptr;
char_base[f]:=ctype_base[f]+nt-bc;
width_base[f]:=char_base[f]+ec+1;
height_base[f]:=width_base[f]+nw;
depth_base[f]:=height_base[f]+nh;
italic_base[f]:=depth_base[f]+nd;
lig_kern_base[f]:=italic_base[f]+ni;
kern_base[f]:=lig_kern_base[f]+nl-kern_base_offset;
exten_base[f]:=kern_base[f]+kern_base_offset+nk;
param_base[f]:=exten_base[f]+ne;
@z

@x
@ @<Read character data@>=
for k:=fmem_ptr to width_base[f]-1 do
  begin store_four_quarters(font_info[k].qqqq);
@y
@ @<Read character data@>=
if jfm_flag<>dir_default then
  for k:=ctype_base[f] to ctype_base[f]+nt-1 do
    begin
    fget; read_sixteen(cx); font_info[k].hh.rh:=tokanji(cx); {|kchar_code|}
    fget; read_sixteen(cx); font_info[k].hh.lhfield:=tonum(cx); {|kchar_type|}
    end;
for k:=char_base[f]+bc to width_base[f]-1 do
  begin store_four_quarters(font_info[k].qqqq);
@z

@x
@d current_character_being_worked_on==k+bc-fmem_ptr
@y
@d current_character_being_worked_on==k-char_base[f]
@z

@x
    if a>128 then
      begin if 256*c+d>=nl then abort;
      if a=255 then if k=lig_kern_base[f] then bchar:=b;
      end
    else begin if b<>bchar then check_existence(b);
      if c<128 then check_existence(d) {check ligature}
      else if 256*(c-128)+d>=nk then abort; {check kern}
      if a<128 then if k-lig_kern_base[f]+a+1>=nl then abort;
      end;
    end;
@y
    if a>128 then
      begin if 256*c+d>=nl then abort;
      if a=255 then if k=lig_kern_base[f] then bchar:=b;
      end
    else begin if b<>bchar then check_existence(b);
      if c<128 then begin
          if jfm_flag<>dir_default then begin if d>=ne then abort; end
        else check_existence(d); {check ligature}
      end else if 256*(c-128)+d>=nk then abort; {check kern}
      if a<128 then if k-lig_kern_base[f]+a+1>=nl then abort;
      end;
    end;
@z

@x
for k:=exten_base[f] to param_base[f]-1 do
  begin store_four_quarters(font_info[k].qqqq);
@y
if jfm_flag<>dir_default then
  for k:=exten_base[f] to param_base[f]-1 do
    store_scaled(font_info[k].sc) {NOTE: this area subst for glue program}
else for k:=exten_base[f] to param_base[f]-1 do
  begin store_four_quarters(font_info[k].qqqq);
@z

@x
adjust(char_base); adjust(width_base); adjust(lig_kern_base);
@y
adjust(ctype_base);
adjust(char_base); adjust(width_base); adjust(lig_kern_base);
@z

@x
if cur_cmd=def_font then f:=cur_font
@y
if cur_cmd=def_jfont then f:=cur_jfont
else if cur_cmd=def_tfont then f:=cur_tfont
else if cur_cmd=def_font then f:=cur_font
@z

@x
@p procedure char_warning(@!f:internal_font_number;@!c:eight_bits);
@y
@d print_lc_hex(#)==l:=#;
  if l<10 then print_char(l+"0")@+else print_char(l-10+"a")

@p procedure char_warning(@!f:internal_font_number;@!c:eight_bits);
var @!l:0..255; {small indices or counters}
@z

@x
  print_ASCII(c); print(" in font ");
@y
  if (c<" ")or(c>"~") then
    begin print_char("^"); print_char("^");
    if c<64 then print_char(c+64)
    else if c<128 then print_char(c-64)
    else begin print_lc_hex(c div 16);  print_lc_hex(c mod 16); end
    end
  else print_ASCII(c);
  print(" in font ");
@z

@x
@d set1=128 {typeset a character and move right}
@y
@d set1=128 {typeset a character and move right}
@d set2=129 {typeset a character and move right}
@z

@x
@d post_post=249 {postamble ending}
@y
@d post_post=249 {postamble ending}
@d dirchg=255 {direction change}
@z

@x
@d id_byte=2 {identifies the kind of \.{DVI} files described here}
@y
@d id_byte=2 {identifies the kind of \.{DVI} files described here}
@d ex_id_byte=3 {identifies the kind of extended \.{DVI} files}
@z

@x
@ The last part of the postamble, following the |post_post| byte that
signifies the end of the font definitions, contains |q|, a pointer to the
|post| command that started the postamble.  An identification byte, |i|,
comes next; this currently equals~2, as in the preamble.
@y
@ The last part of the postamble, following the |post_post| byte that
signifies the end of the font definitions, contains |q|, a pointer to the
|post| command that started the postamble.  An identification byte, |i|,
comes next; this equals~2 or~3. If not used p\TeX primitives then the
identification byte equals~2, othercase this is set to~3.
@z

@x
 {character and font in current |char_node|}
@!c:quarterword;
@!f:internal_font_number;
@y
 {character and font in current |char_node|}
@!c:quarterword;
@!f:internal_font_number;
@!dir_used:boolean; {Is this dvi extended?}
@z

@x
doing_leaders:=false; dead_cycles:=0; cur_s:=-1;
@y
doing_leaders:=false; dead_cycles:=0; cur_s:=-1; dir_used:=false;
@z

@x
dvi_h:=0; dvi_v:=0; cur_h:=h_offset; dvi_f:=null_font;
@y
dvi_h:=0; dvi_v:=0; cur_h:=h_offset; dvi_f:=null_font;
dvi_dir:=dir_yoko; cur_dir_hv:=dvi_dir;
@z

@x
procedure hlist_out; {output an |hlist_node| box}
label reswitch, move_past, fin_rule, next_p, continue, found;
var base_line: scaled; {the baseline coordinate for this box}
@y
procedure hlist_out; {output an |hlist_node| box}
label reswitch, move_past, fin_rule, next_p, continue, found;
var base_line: scaled; {the baseline coordinate for this box}
@!disp: scaled; {displacement}
@!save_dir:eight_bits; {what |dvi_dir| should pop to}
@!jc:KANJI_code; {temporary register for KANJI codes}
@!ksp_ptr:pointer; {position of |auto_spacing_glue| in the hlist}
@z

@x
incr(cur_s);
if cur_s>0 then dvi_out(push);
if cur_s>max_push then max_push:=cur_s;
save_loc:=dvi_offset+dvi_ptr; base_line:=cur_v; left_edge:=cur_h;
@y
ksp_ptr:=space_ptr(this_box);
incr(cur_s);
if cur_s>0 then dvi_out(push);
if cur_s>max_push then max_push:=cur_s;
save_loc:=dvi_offset+dvi_ptr;
synch_dir;
base_line:=cur_v; left_edge:=cur_h; disp:=0;
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
@<Output node |p| for |hlist_out|...@>=
reswitch: if is_char_node(p) then
  begin synch_h; synch_v;
  repeat f:=font(p); c:=character(p);
  if f<>dvi_f then @<Change font |dvi_f| to |f|@>;
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
  p:=link(p);
  until not is_char_node(p);
  dvi_h:=cur_h;
  end
else @<Output the non-|char_node| |p| for |hlist_out|
    and move to the next node@>
@y
@<Output node |p| for |hlist_out|...@>=
reswitch: if is_char_node(p) then
  begin synch_h; synch_v;
  chain:=false;
  repeat f:=font(p); c:=character(p);
  if f<>dvi_f then @<Change font |dvi_f| to |f|@>;
  if font_dir[f]=dir_default then
    begin chain:=false;
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
    end
  else
    begin if chain=false then chain:=true
    else begin cur_h:=cur_h+width(ksp_ptr);
      if g_sign<>normal then
        begin  if g_sign=stretching then
          begin  if stretch_order(ksp_ptr)=g_order then
            cur_h:=cur_h+round(float(glue_set(this_box))*stretch(ksp_ptr));
@^real multiplication@>
          end
        else
          begin  if shrink_order(ksp_ptr)=g_order then
            cur_h:=cur_h-round(float(glue_set(this_box))*shrink(ksp_ptr));
@^real multiplication@>
          end;
        end;
      synch_h;
      end;
    p:=link(p);
	jc:=toDVI(KANJI(info(p)));
    dvi_out(set2); dvi_out(Hi(jc)); dvi_out(Lo(jc));
    cur_h:=cur_h+char_width(f)(orig_char_info(f)(c)); {not |jc|}
    end;
  dvi_h:=cur_h; p:=link(p);
  until not is_char_node(p);
  @<Record current point {\sl Sync\TeX} information@>;
  chain:=false;
  end
else @<Output the non-|char_node| |p| for |hlist_out|
    and move to the next node@>
@z

@x
@ @<Output the non-|char_node| |p| for |hlist_out|...@>=
begin case type(p) of
hlist_node,vlist_node:@<Output a box in an hlist@>;
rule_node: begin rule_ht:=height(p); rule_dp:=depth(p); rule_wd:=width(p);
  goto fin_rule;
  end;
whatsit_node: @<Output the whatsit node |p| in an hlist@>;
@y
@ @<Output the non-|char_node| |p| for |hlist_out|...@>=
begin case type(p) of
hlist_node,vlist_node,dir_node:@<Output a box in an hlist@>;
rule_node: begin rule_ht:=height(p); rule_dp:=depth(p); rule_wd:=width(p);
  goto fin_rule;
  end;
whatsit_node: @<Output the whatsit node |p| in an hlist@>;
disp_node: begin disp:=disp_dimen(p); cur_v:=base_line+disp; end;
@z

@x
kern_node,math_node:cur_h:=cur_h+width(p);
@y
kern_node: begin
  @<Record |kern_node| {\sl Sync\TeX} information@>;
  cur_h:=cur_h+width(p);
end;
math_node: begin
  @<Record |math_node| {\sl Sync\TeX} information@>;
  cur_h:=cur_h+width(p);
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
else  begin save_h:=dvi_h; save_v:=dvi_v;
  cur_v:=base_line+shift_amount(p); {shift the box down}
@y
@ @<Output a box in an hlist@>=
if list_ptr(p)=null then begin
  if type(p)<>dir_node then
    @<Record void list {\sl Sync\TeX} information@>;
  cur_h:=cur_h+width(p);
end
else  begin save_h:=dvi_h; save_v:=dvi_v; save_dir:=dvi_dir;
  cur_v:=base_line+disp+shift_amount(p); {shift the box down}
@z

@x
  if type(p)=vlist_node then vlist_out@+else hlist_out;
  dvi_h:=save_h; dvi_v:=save_v;
  cur_h:=edge+width(p); cur_v:=base_line;
  end
@y
  case type(p) of
    hlist_node:hlist_out;
    vlist_node:vlist_out;
    dir_node:dir_out;
  endcases;
  dvi_h:=save_h; dvi_v:=save_v; dvi_dir:=save_dir;
  cur_h:=edge+width(p); cur_v:=base_line+disp; cur_dir_hv:=save_dir;
  end
@z

@x
@ @<Output a rule in an hlist@>=
if is_running(rule_ht) then rule_ht:=height(this_box);
if is_running(rule_dp) then rule_dp:=depth(this_box);
@y
@ @<Output a rule in an hlist@>=
if is_running(rule_ht) then rule_ht:=height(this_box)+disp;
if is_running(rule_dp) then rule_dp:=depth(this_box)-disp;
@z

@x
@<Output a leader box at |cur_h|, ...@>=
begin cur_v:=base_line+shift_amount(leader_box); synch_v; save_v:=dvi_v;@/
synch_h; save_h:=dvi_h; temp_ptr:=leader_box;
@y
@<Output a leader box at |cur_h|, ...@>=
begin cur_v:=base_line+disp+shift_amount(leader_box); synch_v; save_v:=dvi_v;@/
synch_h; save_h:=dvi_h; save_dir:=dvi_dir; temp_ptr:=leader_box;
@z

@x
if type(leader_box)=vlist_node then vlist_out@+else hlist_out;
doing_leaders:=outer_doing_leaders;
dvi_v:=save_v; dvi_h:=save_h; cur_v:=base_line;
cur_h:=save_h+leader_wd+lx;
end
@y
case type(leader_box) of
  hlist_node:hlist_out;
  vlist_node:vlist_out;
  dir_node:dir_out;
endcases;
doing_leaders:=outer_doing_leaders;
dvi_v:=save_v; dvi_h:=save_h; dvi_dir:=save_dir;
cur_v:=base_line; cur_h:=save_h+leader_wd+lx; cur_dir_hv:=save_dir;
end
@z

@x
@p procedure vlist_out; {output a |vlist_node| box}
@y
@p procedure vlist_out; {output a |vlist_node| box}
@z

@x
begin cur_g:=0; cur_glue:=float_constant(0);
this_box:=temp_ptr; g_order:=glue_order(this_box);
g_sign:=glue_sign(this_box); p:=list_ptr(this_box);
incr(cur_s);
if cur_s>0 then dvi_out(push);
if cur_s>max_push then max_push:=cur_s;
save_loc:=dvi_offset+dvi_ptr; left_edge:=cur_h; cur_v:=cur_v-height(this_box);
@y
@!save_dir:integer; {what |dvi_dir| should pop to}
begin cur_g:=0; cur_glue:=float_constant(0);
this_box:=temp_ptr; g_order:=glue_order(this_box);
g_sign:=glue_sign(this_box); p:=list_ptr(this_box);
incr(cur_s);
if cur_s>0 then dvi_out(push);
if cur_s>max_push then max_push:=cur_s;
save_loc:=dvi_offset+dvi_ptr;
synch_dir;
@z

@x
top_edge:=cur_v;
@y
left_edge:=cur_h;
@<Start vlist {\sl Sync\TeX} information record@>;
cur_v:=cur_v-height(this_box);
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
@ @<Output the non-|char_node| |p| for |vlist_out|@>=
begin case type(p) of
hlist_node,vlist_node:@<Output a box in a vlist@>;
rule_node: begin rule_ht:=height(p); rule_dp:=depth(p); rule_wd:=width(p);
  goto fin_rule;
  end;
@y
@ @<Output the non-|char_node| |p| for |vlist_out|@>=
begin case type(p) of
hlist_node,vlist_node,dir_node: @<Output a box in a vlist@>;
rule_node: begin rule_ht:=height(p); rule_dp:=depth(p); rule_wd:=width(p);
  goto fin_rule;
  end;
@z

@x
@<Output a box in a vlist@>=
if list_ptr(p)=null then cur_v:=cur_v+height(p)+depth(p)
else  begin cur_v:=cur_v+height(p); synch_v;
  save_h:=dvi_h; save_v:=dvi_v;
@y
@<Output a box in a vlist@>=
if list_ptr(p)=null then begin
  cur_v:=cur_v+height(p);
  if type(p)<>dir_node then
    @<Record void list {\sl Sync\TeX} information@>;
  cur_v:=cur_v+depth(p);
end
else begin cur_v:=cur_v+height(p); synch_v;
  save_h:=dvi_h; save_v:=dvi_v; save_dir:=dvi_dir;
@z

@x
  if type(p)=vlist_node then vlist_out@+else hlist_out;
  dvi_h:=save_h; dvi_v:=save_v;
  cur_v:=save_v+depth(p); cur_h:=left_edge;
  end
@y
  case type(p) of
    hlist_node:hlist_out;
    vlist_node:vlist_out;
    dir_node:dir_out;
  endcases;
  dvi_h:=save_h; dvi_v:=save_v; dvi_dir:=save_dir;
  cur_v:=save_v+depth(p); cur_h:=left_edge; cur_dir_hv:=save_dir;
  end
@z

@x
@<Output a leader box at |cur_v|, ...@>=
@y
@<Output a leader box at |cur_v|, ...@>=
@z

@x
cur_v:=cur_v+height(leader_box); synch_v; save_v:=dvi_v;
temp_ptr:=leader_box;
outer_doing_leaders:=doing_leaders; doing_leaders:=true;
if type(leader_box)=vlist_node then vlist_out@+else hlist_out;
doing_leaders:=outer_doing_leaders;
dvi_v:=save_v; dvi_h:=save_h; cur_h:=left_edge;
cur_v:=save_v-height(leader_box)+leader_ht+lx;
end
@y
cur_v:=cur_v+height(leader_box); synch_v; save_v:=dvi_v; save_dir:=dvi_dir;
temp_ptr:=leader_box;
outer_doing_leaders:=doing_leaders; doing_leaders:=true;
case type(leader_box) of
  hlist_node:hlist_out;
  vlist_node:vlist_out;
  dir_node:dir_out;
endcases;
doing_leaders:=outer_doing_leaders;
dvi_v:=save_v; dvi_h:=save_h; dvi_dir:=save_dir;
cur_h:=left_edge; cur_v:=save_v-height(leader_box)+leader_ht+lx;
cur_dir_hv:=save_dir;
end
@z

@x
@p procedure ship_out(@!p:pointer); {output the box |p|}
label done;
var page_loc:integer; {location of the current |bop|}
@y
@p procedure ship_out(@!p:pointer); {output the box |p|}
label done;
var page_loc:integer; {location of the current |bop|}
@!del_node:pointer; {used when delete the |dir_node| continued box}
@z

@x
@!old_setting:0..max_selector; {saved |selector| setting}
@y
@!old_setting:0..max_selector; {saved |selector| setting}
begin @<Start sheet {\sl Sync\TeX} information record@>;
@z

@x
@<Ship box |p| out@>;
@y
if type(p)=dir_node then
  begin del_node:=p; p:=list_ptr(p);
  delete_glue_ref(space_ptr(del_node));
  delete_glue_ref(xspace_ptr(del_node));
  free_node(del_node,box_node_size);
  end;
flush_node_list(link(p)); link(p):=null;
if box_dir(p)<>dir_yoko then p:=new_dir_node(p,dir_yoko);
@<Ship box |p| out@>;
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
if type(p)=vlist_node then vlist_out@+else hlist_out;
@y
case type(p) of
  hlist_node:hlist_out;
  vlist_node:vlist_out;
  dir_node:dir_out;
endcases;
@z

@x
  @<Output the font definitions for all fonts that were used@>;
  dvi_out(post_post); dvi_four(last_bop); dvi_out(id_byte);@/
@y
  @<Output the font definitions for all fonts that were used@>;
  dvi_out(post_post); dvi_four(last_bop);
  if dir_used then dvi_out(ex_id_byte) else dvi_out(id_byte);@/
@z

@x
@< Glob...@>=
@!adjust_tail:pointer; {tail of adjustment list}
@y
@< Glob...@>=
@!adjust_tail:pointer; {tail of adjustment list}
@!last_disp:scaled; {displacement at end of list}
@!cur_kanji_skip:pointer;
@!cur_xkanji_skip:pointer;
@z

@x
@ @<Set init...@>=adjust_tail:=null; last_badness:=0;
@y
@ @<Set init...@>=adjust_tail:=null; last_badness:=0;
  cur_kanji_skip:=zero_glue; cur_xkanji_skip:=zero_glue;
{ koko
  |incr(glue_ref_count(cur_kanji_skip));|
  |incr(glue_ref_count(cur_xkanji_skip));|
}
@z

@x
@p function hpack(@!p:pointer;@!w:scaled;@!m:small_number):pointer;
label reswitch, common_ending, exit;
var r:pointer; {the box node that will be returned}
@y
@p function hpack(@!p:pointer;@!w:scaled;@!m:small_number):pointer;
label reswitch, common_ending, exit;
var r:pointer; {the box node that will be returned}
@!k:pointer; {points to a |kanji_space| specification}
@!disp:scaled; {displacement}
@z

@x
q:=r+list_offset; link(q):=p;@/
h:=0; @<Clear dimensions to zero@>;
@y
space_ptr(r):=cur_kanji_skip; xspace_ptr(r):=cur_xkanji_skip;
add_glue_ref(cur_kanji_skip); add_glue_ref(cur_xkanji_skip);
k:=cur_kanji_skip;
q:=r+list_offset; link(q):=p;@/
h:=0; @<Clear dimensions to zero@>;
disp:=0;
@z

@x
while p<>null do @<Examine node |p| in the hlist, taking account of its effect
  on the dimensions of the new box, or moving it to the adjustment list;
  then advance |p| to the next node@>;
if adjust_tail<>null then link(adjust_tail):=null;
height(r):=h; depth(r):=d;@/
@<Determine the value of |width(r)| and the appropriate glue setting;
  then |return| or |goto common_ending|@>;
common_ending: @<Finish issuing a diagnostic message
      for an overfull or underfull hbox@>;
exit: hpack:=r;
end;
@y
while p<>null do @<Examine node |p| in the hlist, taking account of its effect
  on the dimensions of the new box, or moving it to the adjustment list;
  then advance |p| to the next node@>;
if adjust_tail<>null then link(adjust_tail):=null;
height(r):=h; depth(r):=d;@/
@<Determine the value of |width(r)| and the appropriate glue setting;
  then |return| or |goto common_ending|@>;
common_ending:
  @<Finish issuing a diagnostic message for an overfull or underfull hbox@>;
exit: last_disp:=disp; hpack:=r;
end;
@z

@x
@ @<Examine node |p| in the hlist, taking account of its effect...@>=
@^inner loop@>
begin reswitch: while is_char_node(p) do
  @<Incorporate character dimensions into the dimensions of
    the hbox that will contain~it, then move to the next node@>;
if p<>null then
  begin case type(p) of
  hlist_node,vlist_node,rule_node,unset_node:
    @<Incorporate box dimensions into the dimensions of
      the hbox that will contain~it@>;
  ins_node,mark_node,adjust_node: if adjust_tail<>null then
    @<Transfer node |p| to the adjustment list@>;
  whatsit_node:@<Incorporate a whatsit node into an hbox@>;
@y
@ @<Examine node |p| in the hlist, taking account of its effect...@>=
@^inner loop@>
begin reswitch: chain:=false;
while is_char_node(p) do
  @<Incorporate character dimensions into the dimensions of
    the hbox that will contain~it, then move to the next node@>;
if p<>null then
  begin case type(p) of
  hlist_node,vlist_node,dir_node,rule_node,unset_node:
    @<Incorporate box dimensions into the dimensions of
      the hbox that will contain~it@>;
  ins_node,mark_node,adjust_node:
    if adjust_tail<>null then @<Transfer node |p| to the adjustment list@>;
  whatsit_node:@<Incorporate a whatsit node into an hbox@>;
  disp_node:disp:=disp_dimen(p);
@z

@x
@<Incorporate box dimensions into the dimensions of the hbox...@>=
begin x:=x+width(p);
if type(p)>=rule_node then s:=0 @+else s:=shift_amount(p);
if height(p)-s>h then h:=height(p)-s;
if depth(p)+s>d then d:=depth(p)+s;
end
@y
@<Incorporate box dimensions into the dimensions of the hbox...@>=
begin x:=x+width(p);
if type(p)>=rule_node then s:=disp @+else s:=shift_amount(p)+disp;
if height(p)-s>h then h:=height(p)-s;
if depth(p)+s>d then d:=depth(p)+s;
end
@z

@x
@<Incorporate character dimensions into the dimensions of the hbox...@>=
begin f:=font(p); i:=char_info(f)(character(p)); hd:=height_depth(i);
x:=x+char_width(f)(i);@/
s:=char_height(f)(hd);@+if s>h then h:=s;
s:=char_depth(f)(hd);@+if s>d then d:=s;
p:=link(p);
end
@y
@<Incorporate character dimensions into the dimensions of the hbox...@>=
begin f:=font(p); i:=char_info(f)(character(p)); hd:=height_depth(i);
x:=x+char_width(f)(i);@/
s:=char_height(f)(hd)-disp; if s>h then h:=s;
s:=char_depth(f)(hd)+disp; if s>d then d:=s;
if font_dir[f]<>dir_default then
  begin p:=link(p);
  if chain then
    begin x:=x+width(k);@/
    o:=stretch_order(k); total_stretch[o]:=total_stretch[o]+stretch(k);
    o:=shrink_order(k); total_shrink[o]:=total_shrink[o]+shrink(k);
    end
  else chain:=true;
  end
else chain:=false;
p:=link(p);
end
@z

@x
begin last_badness:=0; r:=get_node(box_node_size); type(r):=vlist_node;
subtype(r):=min_quarterword; shift_amount(r):=0;
@y
begin last_badness:=0; r:=get_node(box_node_size); type(r):=vlist_node;
subtype(r):=min_quarterword; shift_amount(r):=0;
space_ptr(r):=zero_glue; xspace_ptr(r):=zero_glue;
add_glue_ref(zero_glue); add_glue_ref(zero_glue);
@z

@x
@ @<Examine node |p| in the vlist, taking account of its effect...@>=
begin if is_char_node(p) then confusion("vpack")
@:this can't happen vpack}{\quad vpack@>
else  case type(p) of
  hlist_node,vlist_node,rule_node,unset_node:
    @<Incorporate box dimensions into the dimensions of
      the vbox that will contain~it@>;
@y
@ @<Examine node |p| in the vlist, taking account of its effect...@>=
begin if is_char_node(p) then confusion("vpack")
@:this can't happen vpack}{\quad vpack@>
else  case type(p) of
  hlist_node,vlist_node,dir_node,rule_node,unset_node:
    @<Incorporate box dimensions into the dimensions of
      the vbox that will contain~it@>;
@z

@x
@d noad_size=4 {number of words in a normal noad}
@d nucleus(#)==#+1 {the |nucleus| field of a noad}
@d supscr(#)==#+2 {the |supscr| field of a noad}
@d subscr(#)==#+3 {the |subscr| field of a noad}
@y
\yskip\hang In Japanese, |math_type(q)=math_jchar| means that |fam(q)|
refers to one of the sixteen kanji font families, and |KANJI(q)| is the
internal kanji code number.
@^Japanese extentions@>

@d noad_size=5 {number of words in a normal noad}
@d nucleus(#)==#+1 {the |nucleus| field of a noad}
@d supscr(#)==#+2 {the |supscr| field of a noad}
@d subscr(#)==#+3 {the |subscr| field of a noad}
@d kcode_noad(#)==#+4
@d math_kcode(#)==info(#+4) {the |kanji character| field of a noad}
@d kcode_noad_nucleus(#)==#+3
@d math_kcode_nucleus(#)==info(#+3)
	{the |kanji character| field offset from nucleus}
@#
@d math_jchar=6
@d math_text_jchar=7
@z

@x
@d math_char=1 {|math_type| when the attribute is simple}
@d sub_box=2 {|math_type| when the attribute is a box}
@d sub_mlist=3 {|math_type| when the attribute is a formula}
@d math_text_char=4 {|math_type| when italic correction is dubious}
@y
@d math_char=1 {|math_type| when the attribute is simple}
@d sub_box=2 {|math_type| when the attribute is a box}
@d sub_exp_box=3 {|math_type| when the attribute is an explicit created box}
@d sub_mlist=4 {|math_type| when the attribute is a formula}
@d math_text_char=5 {|math_type| when italic correction is dubious}

@<Initialize table entries...@>=
text_baseline_shift_factor:=1000;
script_baseline_shift_factor:=700;
scriptscript_baseline_shift_factor:=500;

@z

@x
@d left_delimiter(#)==#+4 {first delimiter field of a noad}
@d right_delimiter(#)==#+5 {second delimiter field of a fraction noad}
@d radical_noad=inner_noad+1 {|type| of a noad for square roots}
@d radical_noad_size=5 {number of |mem| words in a radical noad}
@y
@d left_delimiter(#)==#+5 {first delimiter field of a noad}
@d right_delimiter(#)==#+4 {second delimiter field of a fraction noad}
@d radical_noad=inner_noad+1 {|type| of a noad for square roots}
@d radical_noad_size=6 {number of |mem| words in a radical noad}
@z

@x
mem[supscr(p)].hh:=empty_field;
new_noad:=p;
@y
mem[supscr(p)].hh:=empty_field;
mem[kcode_noad(p)].hh:=empty_field;
new_noad:=p;
@z

@x
@d accent_noad_size=5 {number of |mem| words in an accent noad}
@d accent_chr(#)==#+4 {the |accent_chr| field of an accent noad}
@y
@d accent_noad_size=6 {number of |mem| words in an accent noad}
@d accent_chr(#)==#+5 {the |accent_chr| field of an accent noad}
@z

@x
procedure print_fam_and_char(@!p:pointer); {prints family and character}
begin print_esc("fam"); print_int(fam(p)); print_char(" ");
print_ASCII(qo(character(p)));
@y
procedure print_fam_and_char(@!p:pointer;@!t:small_number);
					{prints family and character}
var @!cx:KANJI_code; {temporary register for KANJI}
begin print_esc("fam"); print_int(fam(p)); print_char(" ");
if t=math_char then print_ASCII(qo(character(p)))
else  begin KANJI(cx):=math_kcode_nucleus(p); print_kanji(cx);
  end;
@z

@x
  math_char: begin print_ln; print_current_string; print_fam_and_char(p);
    end;
  sub_box: show_info; {recursive call}
@y
  math_char, math_jchar: begin print_ln; print_current_string;
    print_fam_and_char(p,math_type(p));
    end;
  sub_box, sub_exp_box: show_info; {recursive call}
@z

@x
accent_noad: begin print_esc("accent"); print_fam_and_char(accent_chr(p));
@y
accent_noad: begin print_esc("accent");
  print_fam_and_char(accent_chr(p),math_char);
@z

@x
  begin if math_type(nucleus(p))>=sub_box then
    flush_node_list(info(nucleus(p)));
  if math_type(supscr(p))>=sub_box then
    flush_node_list(info(supscr(p)));
  if math_type(subscr(p))>=sub_box then
    flush_node_list(info(subscr(p)));
@y
  begin if (math_type(nucleus(p))>=sub_box)
       and (math_type(nucleus(p))<>math_jchar)
       and (math_type(nucleus(p))<>math_text_jchar) then
    flush_node_list(info(nucleus(p)));
  if math_type(supscr(p))>=sub_box
       and (math_type(supscr(p))<>math_jchar)
       and (math_type(supscr(p))<>math_text_jchar) then
    flush_node_list(info(supscr(p)));
  if math_type(subscr(p))>=sub_box
       and (math_type(subscr(p))<>math_jchar)
       and (math_type(subscr(p))<>math_text_jchar) then
    flush_node_list(info(subscr(p)));
@z

@x
  begin if type(b)=vlist_node then b:=hpack(b,natural);
  p:=list_ptr(b);
  if (is_char_node(p))and(link(p)=null) then
    begin f:=font(p); v:=char_width(f)(char_info(f)(character(p)));
    if v<>width(b) then link(p):=new_kern(width(b)-v);
    end;
@y
  begin if type(b)<>hlist_node then b:=hpack(b,natural);
  p:=list_ptr(b);
  if is_char_node(p) then
    if font_dir[font(p)]<>dir_default then
      begin if link(link(p))=null then
        begin f:=font(p); v:=char_width(f)(orig_char_info(f)(character(p)));
        if v<>width(b) then link(link(p)):=new_kern(width(b)-v);
        end
      end
    else if link(p)=null then
      begin f:=font(p); v:=char_width(f)(orig_char_info(f)(character(p)));
      if v<>width(b) then link(p):=new_kern(width(b)-v);
      end;
  delete_glue_ref(space_ptr(b)); delete_glue_ref(xspace_ptr(b));
@z

@x
function clean_box(@!p:pointer;@!s:small_number):pointer;
@y
function shift_sub_exp_box(@!q:pointer):pointer;
  { We assume that |math_type(q)=sub_exp_box| }
  var d: halfword; {displacement}
  begin
    if direction=dir_tate then d:=t_baseline_shift
    else d:=y_baseline_shift;
    if cur_style<script_style then
      d:=xn_over_d(d,text_baseline_shift_factor, 1000)
    else if cur_style<script_script_style then
      d:=xn_over_d(d,script_baseline_shift_factor, 1000)
    else
      d:=xn_over_d(d,scriptscript_baseline_shift_factor, 1000);
    shift_amount(info(q)):=shift_amount(info(q))-d;
    math_type(q):=sub_box;
    shift_sub_exp_box:=info(q);
  end;
function clean_box(@!p:pointer;@!s:small_number;@!jc:halfword):pointer;
@z

@x
math_char: begin cur_mlist:=new_noad; mem[nucleus(cur_mlist)]:=mem[p];
  end;
sub_box: begin q:=info(p); goto found;
  end;
@y
math_char: begin cur_mlist:=new_noad; mem[nucleus(cur_mlist)]:=mem[p];
  end;
math_jchar: begin cur_mlist:=new_noad; mem[nucleus(cur_mlist)]:=mem[p];
  math_kcode(cur_mlist):=jc;
  end;
sub_box: begin q:=info(p); goto found;
  end;
sub_exp_box: begin q:=shift_sub_exp_box(p); goto found;
  end;
@z

@x
found: if is_char_node(q)or(q=null) then x:=hpack(q,natural)
  else if (link(q)=null)and(type(q)<=vlist_node)and(shift_amount(q)=0) then
    x:=q {it's already clean}
  else x:=hpack(q,natural);
@y
found: if is_char_node(q)or(q=null) then x:=hpack(q,natural)
  else if (link(q)=null)and(type(q)<=dir_node)and(shift_amount(q)=0) then
    x:=q {it's already clean}
  else x:=hpack(q,natural);
@z

@x
@<Simplify a trivial box@>=
@y
@<Simplify a trivial box@>=
@z

@x
if is_char_node(q) then
  begin r:=link(q);
@y
if is_char_node(q) then
  begin if font_dir[font(q)]<>dir_default then q:=link(q);
  r:=link(q);
@z

@x
    begin free_node(r,small_node_size); link(q):=null;
@y
    begin free_node(r,medium_node_size); link(q):=null;
@z

@x
else  begin if (qo(cur_c)>=font_bc[cur_f])and(qo(cur_c)<=font_ec[cur_f]) then
    cur_i:=orig_char_info(cur_f)(cur_c)
  else cur_i:=null_character;
  if not(char_exists(cur_i)) then
    begin char_warning(cur_f,qo(cur_c));
    math_type(a):=empty;
    end;
  end;
@y
else  begin if font_dir[cur_f]<>dir_default then
    cur_c:=qi(get_jfm_pos(KANJI(math_kcode_nucleus(a)),cur_f));
  if (qo(cur_c)>=font_bc[cur_f])and(qo(cur_c)<=font_ec[cur_f]) then
    cur_i:=orig_char_info(cur_f)(cur_c)
  else cur_i:=null_character;
  if not(char_exists(cur_i)) then
    begin char_warning(cur_f,qo(cur_c));
    math_type(a):=empty;
    end;
  end;
@z

@x
var mlist:pointer; {beginning of the given list}
@!penalties:boolean; {should penalty nodes be inserted?}
@!style:small_number; {the given style}
@y
var mlist:pointer; {beginning of the given list}
@!penalties:boolean; {should penalty nodes be inserted?}
@!style:small_number; {the given style}
@!u:pointer; {temporary register}
@z

@x
@<Make a second pass over the mlist, removing all noads and inserting the
  proper spacing and penalties@>;
end;
@y
@<Make a second pass over the mlist, removing all noads and inserting the
  proper spacing and penalties@>;
p:=new_null_box; link(p):=link(temp_head);
adjust_hlist(p,false); link(temp_head):=link(p);
delete_glue_ref(space_ptr(p)); delete_glue_ref(xspace_ptr(p));
free_node(p,box_node_size);
end;
@z

@x
free_node(z,box_node_size);
@y
delete_glue_ref(space_ptr(z)); delete_glue_ref(xspace_ptr(z));
free_node(z,box_node_size);
@z

@x
kern_node: begin math_kern(q,cur_mu); goto done_with_node;
  end;
@y
kern_node: begin math_kern(q,cur_mu); goto done_with_node;
  end;
disp_node: goto done_with_node;
@z

@x
  overbar(clean_box(nucleus(q),cramped_style(cur_style)),@|
@y
  overbar(clean_box(nucleus(q),cramped_style(cur_style),math_kcode(q)),@|
@z

@x
begin x:=clean_box(nucleus(q),cur_style);
@y
begin x:=clean_box(nucleus(q),cur_style,math_kcode(q));
@z

@x
if type(v)<>vlist_node then confusion("vcenter");
@y
if type(v)=dir_node then
  begin if type(list_ptr(v))<>vlist_node then confusion("dircenter")
  end
else  begin if type(v)<>vlist_node then confusion("vcenter")
  end;
@z

@x
begin x:=clean_box(nucleus(q),cramped_style(cur_style));
@y
begin x:=clean_box(nucleus(q),cramped_style(cur_style),math_kcode(q));
@z

@x
  x:=clean_box(nucleus(q),cramped_style(cur_style)); w:=width(x); h:=height(x);
@y
  x:=clean_box(nucleus(q),cramped_style(cur_style),math_kcode(q));
  w:=width(x); h:=height(x);
@z

@x
x:=clean_box(nucleus(q),cur_style); delta:=delta+height(x)-h; h:=height(x);
@y
x:=clean_box(nucleus(q),cur_style,math_kcode(q));
delta:=delta+height(x)-h; h:=height(x);
@z

@x
x:=clean_box(numerator(q),num_style(cur_style));
z:=clean_box(denominator(q),denom_style(cur_style));
@y
x:=clean_box(numerator(q),num_style(cur_style),math_kcode(q));
z:=clean_box(denominator(q),denom_style(cur_style),math_kcode(q));
@z

@x
  delta:=char_italic(cur_f)(cur_i); x:=clean_box(nucleus(q),cur_style);
@y
  delta:=char_italic(cur_f)(cur_i);
  x:=clean_box(nucleus(q),cur_style,math_kcode(q));
@z

@x
begin x:=clean_box(supscr(q),sup_style(cur_style));
y:=clean_box(nucleus(q),cur_style);
z:=clean_box(subscr(q),sub_style(cur_style));
@y
begin x:=clean_box(supscr(q),sup_style(cur_style),math_kcode(q));
y:=clean_box(nucleus(q),cur_style,math_kcode(q));
z:=clean_box(subscr(q),sub_style(cur_style),math_kcode(q));
@z

@x
  begin free_node(x,box_node_size); list_ptr(v):=y;
  end
@y
  begin
    delete_glue_ref(space_ptr(x)); delete_glue_ref(xspace_ptr(x));
    free_node(x,box_node_size); list_ptr(v):=y;
  end
@z

@x
if math_type(subscr(q))=empty then free_node(z,box_node_size)
@y
if math_type(subscr(q))=empty then begin
  delete_glue_ref(space_ptr(z)); delete_glue_ref(xspace_ptr(z));
  free_node(z,box_node_size)
end
@z

@x
procedure make_ord(@!q:pointer);
label restart,exit;
var a:integer; {address of lig/kern instruction}
@!p,@!r:pointer; {temporary registers for list manipulation}
begin restart:@t@>@;@/
if math_type(subscr(q))=empty then if math_type(supscr(q))=empty then
 if math_type(nucleus(q))=math_char then
  begin p:=link(q);
  if p<>null then if (type(p)>=ord_noad)and(type(p)<=punct_noad) then
    if math_type(nucleus(p))=math_char then
    if fam(nucleus(p))=fam(nucleus(q)) then
      begin math_type(nucleus(q)):=math_text_char;
      fetch(nucleus(q));
      if char_tag(cur_i)=lig_tag then
        begin a:=lig_kern_start(cur_f)(cur_i);
        cur_c:=character(nucleus(p));
        cur_i:=font_info[a].qqqq;
        if skip_byte(cur_i)>stop_flag then
          begin a:=lig_kern_restart(cur_f)(cur_i);
          cur_i:=font_info[a].qqqq;
          end;
        loop@+ begin @<If instruction |cur_i| is a kern with |cur_c|, attach
            the kern after~|q|; or if it is a ligature with |cur_c|, combine
            noads |q| and~|p| appropriately; then |return| if the cursor has
            moved past a noad, or |goto restart|@>;
          if skip_byte(cur_i)>=stop_flag then return;
          a:=a+qo(skip_byte(cur_i))+1;
          cur_i:=font_info[a].qqqq;
          end;
        end;
      end;
  end;
exit:end;
@y
procedure make_ord(@!q:pointer);
label restart,exit;
var a:integer; {address of lig/kern instruction}
@!gp,@!gq,@!p,@!r:pointer; {temporary registers for list manipulation}
@!rr:halfword;
begin restart:@t@>@;@/
if (math_type(subscr(q))=empty)and(math_type(supscr(q))=empty)and@|
((math_type(nucleus(q))=math_char)or(math_type(nucleus(q))=math_jchar)) then
  begin p:=link(q);
  if p<>null then if (type(p)>=ord_noad)and(type(p)<=punct_noad) then
   if fam(nucleus(p))=fam(nucleus(q)) then
    if math_type(nucleus(p))=math_char then
      begin math_type(nucleus(q)):=math_text_char;
      fetch(nucleus(q));
      if char_tag(cur_i)=lig_tag then
        begin a:=lig_kern_start(cur_f)(cur_i);
        cur_c:=character(nucleus(p));
        cur_i:=font_info[a].qqqq;
        if skip_byte(cur_i)>stop_flag then
          begin a:=lig_kern_restart(cur_f)(cur_i);
          cur_i:=font_info[a].qqqq;
          end;
        loop@+ begin @<If instruction |cur_i| is a kern with |cur_c|, attach
            the kern after~|q|; or if it is a ligature with |cur_c|, combine
            noads |q| and~|p| appropriately; then |return| if the cursor has
            moved past a noad, or |goto restart|@>;
          if skip_byte(cur_i)>=stop_flag then return;
          a:=a+qo(skip_byte(cur_i))+1;
          cur_i:=font_info[a].qqqq;
          end;
        end;
      end
    else  if math_type(nucleus(p))=math_jchar then
      begin math_type(nucleus(q)):=math_text_jchar;
      fetch(nucleus(p)); a:=cur_c; fetch(nucleus(q));
      if char_tag(cur_i)=gk_tag then
        begin cur_c:=a; a:=glue_kern_start(cur_f)(cur_i);
        {|cur_c|:=qi(|get_jfm_pos|(|math_kcode|(p),
                   |fam_fnt|(fam(nucleus(p))+|cur_size|)));}
        repeat
         cur_i:=font_info[a].qqqq;
         if next_char(cur_i)=cur_c then
         if op_byte(cur_i)<kern_flag then
           begin gp:=font_glue[cur_f]; rr:=rem_byte(cur_i);
           if gp<>null then begin
             while((type(gp)<>rr)and(link(gp)<>null)) do begin gp:=link(gp);
               end;
             gq:=glue_ptr(gp);
             end
           else begin gp:=get_node(small_node_size);
             font_glue[cur_f]:=gp; gq:=null;
             end;
           if gq=null then
             begin type(gp):=rr; gq:=new_spec(zero_glue); glue_ptr(gp):=gq;
             a:=exten_base[cur_f]+qi((qo(rr))*3); width(gq):=font_info[a].sc;
             stretch(gq):=font_info[a+1].sc; shrink(gq):=font_info[a+2].sc;
             add_glue_ref(gq); link(gp):=get_node(small_node_size);
             gp:=link(gp); glue_ptr(gp):=null; link(gp):=null;
             end;
           p:=new_glue(gq); link(p):=link(q); link(q):=p; return;
           end
         else begin p:=new_kern(char_kern(cur_f)(cur_i));
           link(p):=link(q); link(q):=p; return;
           end;
         incr(a);
        until skip_byte(cur_i)>=stop_flag;
        end;
      end;
  end;
exit:end;
@z

@x
math_char, math_text_char:
@y
math_char, math_text_char, math_jchar, math_text_jchar:
@z

@x
sub_box: p:=info(nucleus(q));
@y
sub_box: p:=info(nucleus(q));
sub_exp_box: p:=shift_sub_exp_box(nucleus(q));
@z

@x
  begin delta:=char_italic(cur_f)(cur_i); p:=new_character(cur_f,qo(cur_c));
  if (math_type(nucleus(q))=math_text_char)and(space(cur_f)<>0) then
    delta:=0; {no italic correction in mid-word of text font}
  if (math_type(subscr(q))=empty)and(delta<>0) then
    begin link(p):=new_kern(delta); delta:=0;
@y
  begin delta:=char_italic(cur_f)(cur_i); p:=new_character(cur_f,qo(cur_c));
  u:=p;
  if font_dir[cur_f]<>dir_default then begin
    link(u):=get_avail; u:=link(u); info(u):=math_kcode(q);
  end;
  if ((math_type(nucleus(q))=math_text_char)or
      (math_type(nucleus(q))=math_text_jchar))and(space(cur_f)<>0) then
    delta:=0; {no italic correction in mid-word of text font}
  if (math_type(subscr(q))=empty)and(delta<>0) then begin
    link(u):=new_kern(delta); delta:=0;
@z

@x
  shift_down:=depth(z)+sub_drop(t);
  free_node(z,box_node_size);
  end;
@y
  shift_down:=depth(z)+sub_drop(t);
  delete_glue_ref(space_ptr(z)); delete_glue_ref(xspace_ptr(z));
  free_node(z,box_node_size);
  end;
@z

@x
begin x:=clean_box(subscr(q),sub_style(cur_style));
@y
begin x:=clean_box(subscr(q),sub_style(cur_style),math_kcode(q));
@z

@x
begin x:=clean_box(supscr(q),sup_style(cur_style));
@y
begin x:=clean_box(supscr(q),sup_style(cur_style),math_kcode(q));
@z

@x
begin y:=clean_box(subscr(q),sub_style(cur_style));
@y
begin y:=clean_box(subscr(q),sub_style(cur_style),math_kcode(q));
@z

@x
othercases confusion("mlist3")
@y
disp_node: begin link(p):=q; p:=q; q:=link(q); link(p):=null; goto done;
  end;
othercases confusion("mlist3")
@z

@x
  begin adjust_tail:=cur_tail; u:=hpack(link(head),natural); w:=width(u);
@y
  begin adjust_tail:=cur_tail; adjust_hlist(head,false);
  delete_glue_ref(cur_kanji_skip); delete_glue_ref(cur_xkanji_skip);
  cur_kanji_skip:=space_ptr(head); cur_xkanji_skip:=xspace_ptr(head);
  add_glue_ref(cur_kanji_skip); add_glue_ref(cur_xkanji_skip);
  u:=hpack(link(head),natural); w:=width(u);
@z

@x
  begin p:=hpack(link(head),natural);
@y
  begin adjust_hlist(head,false);
  delete_glue_ref(cur_kanji_skip); delete_glue_ref(cur_xkanji_skip);
  cur_kanji_skip:=space_ptr(head); cur_xkanji_skip:=xspace_ptr(head);
  add_glue_ref(cur_kanji_skip); add_glue_ref(cur_xkanji_skip);
  p:=hpack(link(head),natural);
@z

@x
var @!p,@!q,@!r,@!s,@!u,@!v: pointer; {registers for the list operations}
@y
var @!p,@!q,@!r,@!s,@!u,@!v,@!z: pointer; {registers for the list operations}
@z

@x
  p:=hpack(preamble,saved(1),saved(0)); overfull_rule:=rule_save;
@y
  z:=new_null_box; link(z):=preamble;
  adjust_hlist(z,false);
  delete_glue_ref(cur_kanji_skip); delete_glue_ref(cur_xkanji_skip);
  cur_kanji_skip:=space_ptr(z); cur_xkanji_skip:=xspace_ptr(z);
  add_glue_ref(cur_kanji_skip); add_glue_ref(cur_xkanji_skip);
  p:=hpack(preamble,saved(1),saved(0)); overfull_rule:=rule_save;
  delete_glue_ref(space_ptr(z)); delete_glue_ref(xspace_ptr(z));
  free_node(z,box_node_size);
@z

@x
glue_order(q):=glue_order(p); glue_sign(q):=glue_sign(p);
glue_set(q):=glue_set(p); shift_amount(q):=o;
r:=link(list_ptr(q)); s:=link(list_ptr(p));
@y
set_box_dir(q)(abs(direction));
glue_order(q):=glue_order(p); glue_sign(q):=glue_sign(p);
glue_set(q):=glue_set(p); shift_amount(q):=o;
r:=link(list_ptr(q)); s:=link(list_ptr(p));
@z

@x
s:=link(s); link(u):=new_null_box; u:=link(u); t:=t+width(s);
if mode=-vmode then width(u):=width(s)@+else
  begin type(u):=vlist_node; height(u):=width(s);
  end
@y
s:=link(s); link(u):=new_null_box; u:=link(u); t:=t+width(s);
if mode=-vmode then width(u):=width(s)@+else
  begin type(u):=vlist_node; height(u):=width(s);
  end;
set_box_dir(u)(abs(direction))
@z

@x
width(r):=w; type(r):=hlist_node;
end
@y
width(r):=w; type(r):=hlist_node;
set_box_dir(r)(abs(direction));
end
@z

@x
height(r):=w; type(r):=vlist_node;
@y
height(r):=w; type(r):=vlist_node;
set_box_dir(r)(abs(direction));
@z

@x
link(temp_head):=link(head);
if is_char_node(tail) then tail_append(new_penalty(inf_penalty))
else if type(tail)<>glue_node then tail_append(new_penalty(inf_penalty))
@y
first_use:=true; chain:=false;
delete_glue_ref(cur_kanji_skip); delete_glue_ref(cur_xkanji_skip);
cur_kanji_skip:=space_ptr(head); cur_xkanji_skip:=xspace_ptr(head);
add_glue_ref(cur_kanji_skip); add_glue_ref(cur_xkanji_skip);
link(temp_head):=link(head);
if not is_char_node(tail)and(type(tail)=disp_node) then
  begin free_node(tail,small_node_size); tail:=prev_node; link(tail):=null
  end;
if is_char_node(tail) then tail_append(new_penalty(inf_penalty))
else if type(tail)<>glue_node then tail_append(new_penalty(inf_penalty))
@z

@x
@!cur_p:pointer; {the current breakpoint under consideration}
@y
@!cur_p:pointer; {the current breakpoint under consideration}
@!chain:boolean; {chain current line and next line?}
@z

@x
begin no_break_yet:=false; do_all_six(set_break_width_to_background);
s:=cur_p;
if break_type>unhyphenated then if cur_p<>null then
  @<Compute the discretionary |break_width| values@>;
while s<>null do
  begin if is_char_node(s) then goto done;
@y
begin no_break_yet:=false; do_all_six(set_break_width_to_background);
s:=cur_p;
if break_type>unhyphenated then if cur_p<>null then
  @<Compute the discretionary |break_width| values@>;
while s<>null do
  begin if is_char_node(s) then
    begin if chain then
      begin break_width[1]:=break_width[1]-width(cur_kanji_skip);
      break_width[2+stretch_order(cur_kanji_skip)]:=
         break_width[2+stretch_order(cur_kanji_skip)]-stretch(cur_kanji_skip);
      break_width[6]:=break_width[6]-shrink(cur_kanji_skip);
      end;
    goto done end;
@z

@x
  kern_node: if subtype(s)<>explicit then goto done
    else break_width[1]:=break_width[1]-width(s);
@y
  kern_node: if (subtype(s)<>explicit)and(subtype(s)<>ita_kern) then
    goto done
    else break_width[1]:=break_width[1]-width(s);
@z

@x
if is_char_node(v) then
  begin f:=font(v);
  break_width[1]:=break_width[1]-char_width(f)(char_info(f)(character(v)));
  end
else  case type(v) of
  ligature_node: begin f:=font(lig_char(v));@/
    break_width[1]:=@|break_width[1]-
      char_width(f)(char_info(f)(character(lig_char(v))));
    end;
  hlist_node,vlist_node,rule_node,kern_node:
    break_width[1]:=break_width[1]-width(v);
  othercases confusion("disc1")
@:this can't happen disc1}{\quad disc1@>
  endcases
@y
if is_char_node(v) then
  begin f:=font(v);
  break_width[1]:=break_width[1]-char_width(f)(orig_char_info(f)(character(v)));
  if font_dir[f]<>dir_default then v:=link(v);
  end
else case type(v) of
  ligature_node: begin f:=font(lig_char(v));@/
    break_width[1]:=@|break_width[1]-
      char_width(f)(orig_char_info(f)(character(lig_char(v))));
    end;
  hlist_node,vlist_node,dir_node,rule_node,kern_node:
    break_width[1]:=break_width[1]-width(v);
  disp_node: do_nothing;
  othercases confusion("disc1")
@:this can't happen disc1}{\quad disc1@>
  endcases
@z

@x
  break_width[1]:=@|break_width[1]+char_width(f)(char_info(f)(character(s)));
  end
else  case type(s) of
  ligature_node: begin f:=font(lig_char(s));
    break_width[1]:=break_width[1]+
      char_width(f)(char_info(f)(character(lig_char(s))));
    end;
  hlist_node,vlist_node,rule_node,kern_node:
    break_width[1]:=break_width[1]+width(s);
@y
  break_width[1]:=@|break_width[1]+char_width(f)(orig_char_info(f)(character(s)));
  if font_dir[f]<>dir_default then s:=link(s);
  end
else  case type(s) of
  ligature_node: begin f:=font(lig_char(s));
    break_width[1]:=break_width[1]+
      char_width(f)(orig_char_info(f)(character(lig_char(s))));
    end;
  hlist_node,vlist_node,dir_node,rule_node,kern_node:
    break_width[1]:=break_width[1]+width(s);
  disp_node: do_nothing;
@z

@x
if cur_p=null then print_esc("par")
else if type(cur_p)<>glue_node then
  begin if type(cur_p)=penalty_node then print_esc("penalty")
  else if type(cur_p)=disc_node then print_esc("discretionary")
@y
if cur_p=null then print_esc("par")
else if (type(cur_p)<>glue_node)and(not is_char_node(cur_p)) then
  begin if type(cur_p)=penalty_node then print_esc("penalty")
  else if type(cur_p)=disc_node then print_esc("discretionary")
@z

@x
@!auto_breaking:boolean; {is node |cur_p| outside a formula?}
@!prev_p:pointer; {helps to determine when glue nodes are breakpoints}
@!q,@!r,@!s,@!prev_s:pointer; {miscellaneous nodes of temporary interest}
@!f:internal_font_number; {used when calculating character widths}
@y
@!auto_breaking:boolean; {is node |cur_p| outside a formula?}
@!prev_p:pointer; {helps to determine when glue nodes are breakpoints}
@!q,@!r,@!s,@!prev_s:pointer; {miscellaneous nodes of temporary interest}
@!f,@!post_f:internal_font_number; {used when calculating character widths}
@!post_p:pointer;
@!cc:ASCII_code;
@!first_use:boolean;
@z

@x
case type(cur_p) of
hlist_node,vlist_node,rule_node: act_width:=act_width+width(cur_p);
@y
case type(cur_p) of
hlist_node,vlist_node,dir_node,rule_node: act_width:=act_width+width(cur_p);
@z

@x
kern_node: if subtype(cur_p)=explicit then kern_break
  else act_width:=act_width+width(cur_p);
@y
kern_node: if (subtype(cur_p)=explicit)or(subtype(cur_p)=ita_kern) then
  kern_break
  else act_width:=act_width+width(cur_p);
@z

@x
mark_node,ins_node,adjust_node: do_nothing;
@y
disp_node,mark_node,ins_node,adjust_node: do_nothing;
@z

@x
@<Advance \(c)|cur_p| to the node following the present string...@>=
begin prev_p:=cur_p;
repeat f:=font(cur_p);
act_width:=act_width+char_width(f)(char_info(f)(character(cur_p)));
cur_p:=link(cur_p);
until not is_char_node(cur_p);
end
@y
@<Advance \(c)|cur_p| to the node following the present string...@>=
begin chain:=false;
if is_char_node(cur_p) then
  if font_dir[font(cur_p)]<>dir_default then
    begin case type(prev_p) of
    hlist_node,vlist_node,dir_node,rule_node,
    ligature_node,disc_node,math_node: begin
      cur_p:=prev_p; try_break(0,unhyphenated); cur_p:=link(cur_p);
      end;
    othercases do_nothing;
    endcases;
    end;
  prev_p:=cur_p; post_p:=cur_p; post_f:=font(post_p);
  repeat f:=post_f; cc:=character(cur_p);
  act_width:=act_width+char_width(f)(orig_char_info(f)(cc));
  post_p:=link(cur_p);
  if font_dir[f]<>dir_default then
    begin prev_p:=cur_p; cur_p:=post_p; post_p:=link(post_p);
    if is_char_node(post_p) then
      begin post_f:=font(post_p);
      if font_dir[post_f]<>dir_default then chain:=true else chain:=false;
      try_break(0,unhyphenated);
      end
    else
      begin chain:=false;
      case type(post_p) of
      hlist_node,vlist_node,dir_node,rule_node,ligature_node,
        disc_node,math_node: try_break(0,unhyphenated);
      othercases do_nothing;
      endcases;
      end;
    if chain then
      begin if first_use then
        begin check_shrinkage(cur_kanji_skip);
        first_use:=false;
        end;
      act_width:=act_width+width(cur_kanji_skip);@|
      active_width[2+stretch_order(cur_kanji_skip)]:=@|
          active_width[2+stretch_order(cur_kanji_skip)]
          +stretch(cur_kanji_skip);@/
      active_width[6]:=active_width[6]+shrink(cur_kanji_skip);
      end;
    prev_p:=cur_p;
    end
  else  if is_char_node(post_p) then
    begin post_f:=font(post_p); chain:=false;
    if font_dir[post_f]<>dir_default then try_break(0,unhyphenated);
    end;
  cur_p:=post_p;
  until not is_char_node(cur_p);
chain:=false;
end
@z

@x
  else if (type(prev_p)=kern_node)and(subtype(prev_p)<>explicit) then
    try_break(0,unhyphenated);
@y
  else if type(prev_p)=kern_node then
    if (subtype(prev_p)<>explicit)and(subtype(prev_p)<>ita_kern) then
    try_break(0,unhyphenated);
@z

@x
  disc_width:=disc_width+char_width(f)(char_info(f)(character(s)));
  end
else  case type(s) of
  ligature_node: begin f:=font(lig_char(s));
    disc_width:=disc_width+
      char_width(f)(char_info(f)(character(lig_char(s))));
    end;
  hlist_node,vlist_node,rule_node,kern_node:
    disc_width:=disc_width+width(s);
@y
  disc_width:=disc_width+char_width(f)(orig_char_info(f)(character(s)));
  if font_dir[f]<>dir_default then s:=link(s)
  end
else  case type(s) of
  ligature_node: begin f:=font(lig_char(s));
    disc_width:=disc_width+
      char_width(f)(orig_char_info(f)(character(lig_char(s))));
    end;
  hlist_node,vlist_node,dir_node,rule_node,kern_node:
    disc_width:=disc_width+width(s);
  disp_node: do_nothing;
@z

@x
  act_width:=act_width+char_width(f)(char_info(f)(character(s)));
  end
else  case type(s) of
  ligature_node: begin f:=font(lig_char(s));
    act_width:=act_width+
      char_width(f)(char_info(f)(character(lig_char(s))));
    end;
  hlist_node,vlist_node,rule_node,kern_node:
    act_width:=act_width+width(s);
@y
  act_width:=act_width+char_width(f)(orig_char_info(f)(character(s)));
  if font_dir[f]<>dir_default then s:=link(s)
  end
else  case type(s) of
  ligature_node: begin f:=font(lig_char(s));
    act_width:=act_width+
      char_width(f)(orig_char_info(f)(character(lig_char(s))));
    end;
  hlist_node,vlist_node,dir_node,rule_node,kern_node:
    act_width:=act_width+width(s);
  disp_node: do_nothing;
@z

@x
cur_line:=prev_graf+1;
@y
cur_line:=prev_graf+1; last_disp:=0;
@z

@x
  if type(q)=kern_node then if subtype(q)<>explicit then goto done1;
@y
  if type(q)=kern_node then
    if (subtype(q)<>explicit)and(subtype(q)<>ita_kern) then goto done1;
@z

@x
if q<>null then {|q| cannot be a |char_node|}
  if type(q)=glue_node then
    begin delete_glue_ref(glue_ptr(q));
    glue_ptr(q):=right_skip;
    subtype(q):=right_skip_code+1; add_glue_ref(right_skip);
    goto done;
    end
  else  begin if type(q)=disc_node then
      @<Change discretionary to compulsory and set
        |disc_break:=true|@>
@y
if q<>null then {|q| may be a |char_node|}
  begin if not is_char_node(q) then
    if type(q)=glue_node then
      begin delete_glue_ref(glue_ptr(q));
      glue_ptr(q):=right_skip;
      subtype(q):=right_skip_code+1; add_glue_ref(right_skip);
      goto done;
      end
    else  begin if type(q)=disc_node then
        @<Change discretionary to compulsory and set
          |disc_break:=true|@>
@z

@x
    end
@y
      end
  end
@z

@x
r:=link(q); link(q):=null; q:=link(temp_head); link(temp_head):=r;
@y
r:=link(q); link(q):=null; q:=link(temp_head); link(temp_head):=r;
if last_disp<>0 then begin
  r:=get_node(small_node_size);
  type(r):=disp_node; disp_dimen(r):=last_disp;
  link(r):=q; q:=r;
  end;
@z

@x
loop@+  begin if is_char_node(s) then
    begin c:=qo(character(s)); hf:=font(s);
    end
@y
loop@+  begin if is_char_node(s) then
    begin hf:=font(s);
    if font_dir[hf]<>dir_default then
      begin prev_s:=s; s:=link(prev_s); c:=info(s); goto continue;
      end else c:=qo(character(s));
    end
  else if type(s)=disp_node then goto continue
  else if (type(s)=penalty_node)and(not subtype(s)=normal) then goto continue
@z

@x
    whatsit_node,glue_node,penalty_node,ins_node,adjust_node,mark_node:
      goto done4;
@y
    disp_node: do_nothing;
    whatsit_node,glue_node,penalty_node,ins_node,adjust_node,mark_node:
      goto done4;
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
  hlist_node,vlist_node,rule_node:@<Insert glue for |split_top_skip|
@y
  dir_node,
  hlist_node,vlist_node,rule_node:@<Insert glue for |split_top_skip|
@z

@x
hlist_node,vlist_node,rule_node: begin@t@>@;@/
@y
dir_node,
hlist_node,vlist_node,rule_node: begin@t@>@;@/
@z

@x
var v:pointer; {the box to be split}
@y
var v:pointer; {the box to be split}
w:pointer; {|dir_node|}
@z

@x
q:=prune_page_top(q); p:=list_ptr(v); free_node(v,box_node_size);
if q=null then box(n):=null {the |eq_level| of the box stays the same}
else box(n):=vpack(q,natural);
vsplit:=vpackage(p,h,exactly,split_max_depth);
@y
q:=prune_page_top(q); p:=list_ptr(v);
if q=null then box(n):=null {the |eq_level| of the box stays the same}
else begin
  box(n):=vpack(q,natural); set_box_dir(box(n))(box_dir(v));
  end;
q:=vpackage(p,h,exactly,split_max_depth);
set_box_dir(q)(box_dir(v));
delete_glue_ref(space_ptr(v)); delete_glue_ref(xspace_ptr(v));
free_node(v,box_node_size);
vsplit:=q;
@z

@x
if type(v)<>vlist_node then
  begin print_err(""); print_esc("vsplit"); print(" needs a ");
  print_esc("vbox");
@:vsplit_}{\.{\\vsplit needs a \\vbox}@>
  help2("The box you are trying to split is an \hbox.")@/
  ("I can't split such a box, so I'll leave it alone.");
  error; vsplit:=null; return;
  end
@y
if type(v)=dir_node then begin
  w:=v; v:=list_ptr(v);
  delete_glue_ref(space_ptr(w));
  delete_glue_ref(xspace_ptr(w));
  free_node(w,box_node_size);
end;
if type(v)<>vlist_node then begin
  print_err(""); print_esc("vsplit"); print(" needs a ");
  print_esc("vbox");
@:vsplit_}{\.{\\vsplit needs a \\vbox}@>
  help2("The box you are trying to split is an \hbox.")@/
  ("I can't split such a box, so I'll leave it alone.");
  error; vsplit:=null; return;
end;
flush_node_list(link(v)); link(v):=null
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
begin p:=box(n);
if p<>null then if type(p)=hlist_node then
  begin print_err("Insertions can only be added to a vbox");
@y
begin p:=box(n);
if p<>null then if type(p)=dir_node then
  begin p:=list_ptr(p);
  delete_glue_ref(space_ptr(box(n)));
  delete_glue_ref(xspace_ptr(box(n)));
  free_node(box(n),box_node_size);
  box(n):=p
end;
if p<>null then if type(p)<>vlist_node then begin
  print_err("Insertions can only be added to a vbox");
@z

@x
hlist_node,vlist_node,rule_node: if page_contents<box_there then
    @<Initialize the current page, insert the \.{\\topskip} glue
      ahead of |p|, and |goto continue|@>
@y
hlist_node,vlist_node,dir_node,rule_node: if page_contents<box_there then
    @<Initialize the current page, insert the \.{\\topskip} glue
      ahead of |p|, and |goto continue|@>
@z

@x
if box(n)=null then height(r):=0
else height(r):=height(box(n))+depth(box(n));
@y
if box(n)=null then height(r):=0
else
  begin if ins_dir(p)<>box_dir(box(n)) then
    begin print_err("Insertions can only be added to a same direction vbox");
@.Insertions can only...@>
    help3("Tut tut: You're trying to \insert into a")@/
      ("\box register that now have a different direction.")@/
      ("Proceed, and I'll discard its present contents.");
    box_error(n)
    end
  else
    height(r):=height(box(n))+depth(box(n));
  end;
@z

@x
box(255):=vpackage(link(page_head),best_size,exactly,page_max_depth);
@y
box(255):=vpackage(link(page_head),best_size,exactly,page_max_depth);
set_box_dir(box(255))(page_dir);
@z

@x
if best_ins_ptr(r)=null then wait:=true
else  begin wait:=false; s:=last_ins_ptr(r); link(s):=ins_ptr(p);
@y
if best_ins_ptr(r)=null then wait:=true
else  begin wait:=false;
  n:=qo(subtype(p));
  case box_dir(box(n)) of
    any_dir:
      if ins_dir(p)<>box_dir(box(n)) then begin
        print_err("Insertions can only be added to a same direction vbox");
@.Insertions can only...@>
        help3("Tut tut: You're trying to \insert into a")@/
          ("\box register that now have a different direction.")@/
          ("Proceed, and I'll discard its present contents.");
        box_error(n);
        box(n):=new_null_box; last_ins_ptr(r):=box(n)+list_offset;
      end;
    othercases
      set_box_dir(box(n))(ins_dir(p));
  endcases;
  s:=last_ins_ptr(r); link(s):=ins_ptr(p);
@z

@x
      free_node(temp_ptr,box_node_size); wait:=true;
@y
      delete_glue_ref(space_ptr(temp_ptr));
      delete_glue_ref(xspace_ptr(temp_ptr));
      free_node(temp_ptr,box_node_size); wait:=true;
@z

@x
free_node(box(n),box_node_size);
box(n):=vpack(temp_ptr,natural);
@y
delete_glue_ref(space_ptr(box(n)));
delete_glue_ref(xspace_ptr(box(n)));
flush_node_list(link(box(n)));
free_node(box(n),box_node_size);
box(n):=vpack(temp_ptr,natural); set_box_dir(box(n))(ins_dir(p));
@z

@x
@d append_normal_space=120 {go here to append a normal space between words}
@y
@d append_normal_space=120 {go here to append a normal space between words}
@d main_loop_j=130 {like |main_loop|, but |cur_chr| holds a KANJI code}
@d skip_loop=141
@d again_2=150
@z

@x
procedure main_control; {governs \TeX's activities}
label big_switch,reswitch,main_loop,main_loop_wrapup,
@y
procedure main_control; {governs \TeX's activities}
label big_switch,reswitch,main_loop,main_loop_wrapup,
  main_loop_j,main_loop_j+1,main_loop_j+3,skip_loop,again_2,
@z

@x
var@!t:integer; {general-purpose temporary variable}
@y
var@!t:integer; {general-purpose temporary variable}
@!cx:KANJI_code; {kanji character}
@!kp:pointer; {kinsoku penalty register}
@!gp,gq:pointer; {temporary registers for list manipulation}
@!disp:scaled; {displacement register}
@!ins_kp:boolean; {whether insert kinsoku penalty}
@z

@x
case abs(mode)+cur_cmd of
hmode+letter,hmode+other_char,hmode+char_given: goto main_loop;
hmode+char_num: begin scan_char_num; cur_chr:=cur_val; goto main_loop;@+end;
hmode+no_boundary: begin get_x_token;
  if (cur_cmd=letter)or(cur_cmd=other_char)or(cur_cmd=char_given)or
   (cur_cmd=char_num) then cancel_boundary:=true;
  goto reswitch;
  end;
@y
ins_kp:=false;
case abs(mode)+cur_cmd of
hmode+letter,hmode+other_char: goto main_loop;
hmode+kanji,hmode+kana,hmode+other_kchar: goto main_loop_j;
hmode+char_given:
  if is_char_ascii(cur_chr) then goto main_loop else goto main_loop_j;
hmode+char_num: begin scan_char_num; cur_chr:=cur_val;
  if is_char_ascii(cur_chr) then goto main_loop else goto main_loop_j;
  end;
hmode+no_boundary: begin get_x_token;
  if (cur_cmd=letter)or(cur_cmd=other_char)or
   (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar)or
   (cur_cmd=char_given)or(cur_cmd=char_num) then cancel_boundary:=true;
  goto reswitch;
  end;
@z

@x
main_loop:@<Append character |cur_chr| and the following characters (if~any)
  to the current hlist in the current font; |goto reswitch| when
  a non-character has been fetched@>;
@y
main_loop_j:@<Append KANJI-character |cur_chr|
  to the current hlist in the current font; |goto reswitch| when
  a non-character has been fetched@>;
main_loop: inhibit_glue_flag:=false;
@<Append character |cur_chr| and the following characters (if~any)
  to the current hlist in the current font; |goto reswitch| when
  a non-character has been fetched@>;
@z

@x
@<Append character |cur_chr|...@>=
if ((head=tail) and (mode>0)) then begin
  if (insert_src_special_auto) then append_src_special;
end;
adjust_space_factor;@/
@y
@<Append character |cur_chr|...@>=
if ((head=tail) and (mode>0)) then begin
  if (insert_src_special_auto) then append_src_special;
end;
adjust_space_factor;@/
if direction=dir_tate then disp:=t_baseline_shift else disp:=y_baseline_shift;
@<Append |disp_node| at begin of displace area@>;
@z

@x
if lig_stack=null then goto reswitch;
@y
if lig_stack=null then
  begin @<Append |disp_node| at end of displace area@>;
  goto reswitch;
  end;
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
@<Look ahead for another character...@>=
get_next; {set only |cur_cmd| and |cur_chr|, for speed}
if cur_cmd=letter then goto main_loop_lookahead+1;
if cur_cmd=other_char then goto main_loop_lookahead+1;
if cur_cmd=char_given then goto main_loop_lookahead+1;
x_token; {now expand and set |cur_cmd|, |cur_chr|, |cur_tok|}
if cur_cmd=letter then goto main_loop_lookahead+1;
if cur_cmd=other_char then goto main_loop_lookahead+1;
if cur_cmd=char_given then goto main_loop_lookahead+1;
if cur_cmd=char_num then
  begin scan_char_num; cur_chr:=cur_val; goto main_loop_lookahead+1;
  end;
if cur_cmd=no_boundary then bchar:=non_char;
cur_r:=bchar; lig_stack:=null; goto main_lig_loop;
main_loop_lookahead+1: adjust_space_factor;
fast_get_avail(lig_stack); font(lig_stack):=main_f;
cur_r:=qi(cur_chr); character(lig_stack):=cur_r;
if cur_r=false_bchar then cur_r:=non_char {this prevents spurious ligatures}
@y
@<Look ahead for another character...@>=
get_next; {set only |cur_cmd| and |cur_chr|, for speed}
if cur_cmd=letter then goto main_loop_lookahead+1;
if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then
  @<goto |main_lig_loop|@>;
if cur_cmd=other_char then goto main_loop_lookahead+1;
if cur_cmd=char_given then
  begin if is_char_ascii(cur_chr) then goto main_loop_lookahead+1
  else @<goto |main_lig_loop|@>;
  end;
x_token; {now expand and set |cur_cmd|, |cur_chr|, |cur_tok|}
if cur_cmd=letter then goto main_loop_lookahead+1;
if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then
  @<goto |main_lig_loop|@>;
if cur_cmd=other_char then goto main_loop_lookahead+1;
if cur_cmd=char_given then
  begin if is_char_ascii(cur_chr) then goto main_loop_lookahead+1
  else @<goto |main_lig_loop|@>;
  end;
if cur_cmd=char_num then
  begin scan_char_num; cur_chr:=cur_val;
  if is_char_ascii(cur_chr) then goto main_loop_lookahead+1
  else @<goto |main_lig_loop|@>;
  end;
if cur_cmd=inhibit_glue then
  begin inhibit_glue_flag:=true; goto main_loop_lookahead;
  end;
if cur_cmd=no_boundary then bchar:=non_char;
cur_r:=bchar; lig_stack:=null; goto main_lig_loop;
main_loop_lookahead+1: adjust_space_factor;
inhibit_glue_flag:=false;
fast_get_avail(lig_stack); font(lig_stack):=main_f;
cur_r:=qi(cur_chr); character(lig_stack):=cur_r;
if cur_r=false_bchar then cur_r:=non_char {this prevents spurious ligatures}

@ @<goto |main_lig_loop|@>=
begin bchar:=non_char; cur_r:=bchar; lig_stack:=null;
if ligature_present then pack_lig(rt_hit);
if ins_kp=true then
  begin cx:=cur_l; @<Insert kinsoku penalty@>;
  end;
ins_kp:=false;
goto main_loop_j;
end
@z

@x
link(tail):=temp_ptr; tail:=temp_ptr;
@y
if not is_char_node(tail)and(type(tail)=disp_node) then
  begin link(prev_node):=temp_ptr; link(temp_ptr):=tail; prev_node:=temp_ptr;
  end
else begin link(tail):=temp_ptr; tail:=temp_ptr;
  end;
@z

@x
link(tail):=q; tail:=q;
@y
if not is_char_node(tail)and(type(tail)=disp_node) then
  begin link(prev_node):=q; link(q):=tail; prev_node:=q;
  end
else begin link(tail):=q; tail:=q;
  end
@z

@x
end; {now |cur_val| points to the glue specification}
tail_append(new_glue(cur_val));
if s>=skip_code then
@y
end; {now |cur_val| points to the glue specification}
tail_append(new_glue(cur_val));
inhibit_glue_flag := false;
if s>=skip_code then
@z

@x
begin s:=cur_chr; scan_dimen(s=mu_glue,false,false);
tail_append(new_kern(cur_val)); subtype(tail):=s;
end;
@y
begin s:=cur_chr; scan_dimen(s=mu_glue,false,false);
inhibit_glue_flag := false;
if not is_char_node(tail)and(type(tail)=disp_node) then
  begin prev_append(new_kern(cur_val)); subtype(prev_node):=s;
  end
else
  begin tail_append(new_kern(cur_val)); subtype(tail):=s;
  end;
end;
@z

@x
var p,@!q:pointer; {for short-term use}
@y
var p,@!q:pointer; {for short-term use}
@!r:pointer; {temporaly}
@z

@x
primitive("hbox",make_box,vtop_code+hmode);@/
@!@:hbox_}{\.{\\hbox} primitive@>
@y
primitive("hbox",make_box,vtop_code+hmode);@/
@!@:hbox_}{\.{\\hbox} primitive@>
primitive("tate",chg_dir,dir_tate);@/
@!@:tate_}{\.{\\tate} primitive@>
primitive("yoko",chg_dir,dir_yoko);@/
@!@:yoko_}{\.{\\yoko} primitive@>
primitive("dtou",chg_dir,dir_dtou);@/
@!@:dtou_}{\.{\\dtou} primitive@>
@z

@x
  othercases print_esc("hbox")
  endcases;
leader_ship: if chr_code=a_leaders then print_esc("leaders")
@y
  othercases print_esc("hbox")
  endcases;
chg_dir:
  case chr_code of
    dir_yoko: print_esc("yoko");
    dir_tate: print_esc("tate");
    dir_dtou: print_esc("dtou");
  endcases;
leader_ship: if chr_code=a_leaders then print_esc("leaders")
@z

@x
any_mode(make_box): begin_box(0);
@y
any_mode(make_box): begin_box(0);
any_mode(chg_dir):
  begin  if cur_group<>align_group then
    if head=tail then
      begin direction:=cur_chr;
      if mode=vmode then page_dir:=cur_chr;
      end
    else begin print_err("Use `"); print_cmd_chr(cur_cmd,cur_chr);
      print("' at top of list");
      help2("Direction change command is available only while")
      ("current list is null."); error;
      end
  else begin print_err("You can't use `"); print_cmd_chr(cur_cmd,cur_chr);
    print("' in an align");
    help2("To change direction in an align,")
    ("you shold use \hbox or \vbox with \tate or \yoko."); error;
    end
  end;
@z

@x
var p:pointer; {|ord_noad| for new box in math mode}
@y
var p:pointer; {|ord_noad| for new box in math mode}
q:pointer;
@z

@x
  begin shift_amount(cur_box):=box_context;
@y
  begin p:=link(cur_box); link(cur_box):=null;
  while p<>null do begin
    q:=p; p:=link(p);
    if box_dir(q)=abs(direction) then
      begin list_ptr(q):=cur_box; cur_box:=q; link(cur_box):=null;
      end
    else begin
      delete_glue_ref(space_ptr(q));
      delete_glue_ref(xspace_ptr(q));
      free_node(q,box_node_size);
      end;
  end;
  if box_dir(cur_box)<>abs(direction) then
    cur_box:=new_dir_node(cur_box,abs(direction));
  shift_amount(cur_box):=box_context;
@z

@x
    else  begin p:=new_noad;
      math_type(nucleus(p)):=sub_box;
@y
    else  begin p:=new_noad;
      math_type(nucleus(p)):=sub_exp_box;
@z

@x
  begin append_glue; subtype(tail):=box_context-(leader_flag-a_leaders);
  leader_ptr(tail):=cur_box;
  end
@y
  begin append_glue; subtype(tail):=box_context-(leader_flag-a_leaders);
  if type(cur_box)<=dir_node then
    begin p:=link(cur_box); link(cur_box):=null;
    while p<>null do
      begin q:=p; p:=link(p);
      if box_dir(q)=abs(direction) then
        begin list_ptr(q):=cur_box; cur_box:=q; link(cur_box):=null;
        end
      else begin
        delete_glue_ref(space_ptr(q));
        delete_glue_ref(xspace_ptr(q));
        free_node(q,box_node_size);
        end;
      end;
    if box_dir(cur_box)<>abs(direction) then
      cur_box:=new_dir_node(cur_box,abs(direction));
    end;
  leader_ptr(tail):=cur_box;
  end
@z

@x
@!m:quarterword; {the length of a replacement list}
@y
@!r:pointer; {running behind |p|}
@!fd:boolean; {a final |disp_node| pair?}
@!disp,@!pdisp:scaled; {displacement}
@!a_dir:eight_bits; {adjust direction}
@!tx:pointer; {effective tail node}
@!m:quarterword; {the length of a replacement list}
@z

@x
@ Note that the condition |not is_char_node(tail)| implies that |head<>tail|,
since |head| is a one-word node.
@y
@ Note that in \TeX\ the condition |not is_char_node(tail)| implies that
|head<>tail|, since |head| is a one-word node; this is not so for p\TeX.
@z

@x
@<If the current list ends with a box node, delete it...@>=
@y
@d check_effective_tail_pTeX(#)==
tx:=tail;
if not is_char_node(tx) then
  if type(tx)=disp_node then
    begin tx:=prev_node;
    if not is_char_node(tx) then
      if type(tx)=disp_node then #; {|disp_node| from a discretionary}
    end
@#
@d fetch_effective_tail_pTeX(#)== {extract |tx|, merge |disp_node| pair}
q:=head; p:=null; disp:=0; pdisp:=0;
repeat r:=p; p:=q; fd:=false;
if not is_char_node(q) then
  if type(q)=disc_node then
    begin for m:=1 to replace_count(q) do p:=link(p);
    if p=tx then #;
    end
  else if type(q)=disp_node then
    begin pdisp:=disp; disp:=disp_dimen(q); fd:=true;@+end;
q:=link(p);
until q=tx; {found |r|$\to$|p|$\to$|q=tx|}
q:=link(tx); link(p):=q; link(tx):=null;
if q=null then tail:=p
else if fd then {|r|$\to$|p=disp_node|$\to$|q=disp_node|}
  begin prev_node:=r; prev_disp:=pdisp; link(p):=null; tail:=p;
  disp_dimen(p):=disp_dimen(q); free_node(q,small_node_size);
  end
else prev_node:=p
@#
@d check_effective_tail==check_effective_tail_pTeX
@d fetch_effective_tail==fetch_effective_tail_pTeX

@<If the current list ends with a box node, delete it...@>=
@z

@x
else  begin if not is_char_node(tail) then
    if (type(tail)=hlist_node)or(type(tail)=vlist_node) then
      @<Remove the last box, unless it's part of a discretionary@>;
  end;
@y
else  begin check_effective_tail(goto done);
  if not is_char_node(tx)and(head<>tx) then
    if (type(tx)=hlist_node)or(type(tx)=vlist_node)
       or(type(tx)=dir_node) then
      @<Remove the last box, unless it's part of a discretionary@>;
  done:end;
@z

@x
begin q:=head;
repeat p:=q;
if not is_char_node(q) then if type(q)=disc_node then
  begin for m:=1 to replace_count(q) do p:=link(p);
  if p=tail then goto done;
  end;
q:=link(p);
until q=tail;
cur_box:=tail; shift_amount(cur_box):=0;
tail:=p; link(p):=null;
done:end
@y
begin fetch_effective_tail(goto done);
cur_box:=tx; shift_amount(cur_box):=0;
if type(cur_box)=dir_node then
  begin link(list_ptr(cur_box)):=cur_box;
  cur_box:=list_ptr(cur_box);
  list_ptr(link(cur_box)):=null;
  end
else
  if box_dir(cur_box)=dir_default then set_box_dir(cur_box)(abs(direction));
end
@z

@x
if k=hmode then
  if (box_context<box_flag)and(abs(mode)=vmode) then
    scan_spec(adjusted_hbox_group,true)
  else scan_spec(hbox_group,true)
else  begin if k=vmode then scan_spec(vbox_group,true)
  else  begin scan_spec(vtop_group,true); k:=vmode;
    end;
  normal_paragraph;
  end;
push_nest; mode:=-k;
@y
a_dir:=adjust_dir;
if k=hmode then
  if (box_context<box_flag)and(abs(mode)=vmode) then
    begin a_dir:=abs(direction); scan_spec(adjusted_hbox_group,true);
    end
  else scan_spec(hbox_group,true)
else  begin if k=vmode then scan_spec(vbox_group,true)
  else  begin scan_spec(vtop_group,true); k:=vmode;
    end;
  normal_paragraph;
  end;
push_nest; mode:=-k; adjust_dir:=a_dir;
@z

@x
hbox_group: package(0);
adjusted_hbox_group: begin adjust_tail:=adjust_head; package(0);
  end;
@y
hbox_group: begin adjust_hlist(head,false); package(0);
  end;
adjusted_hbox_group: begin adjust_hlist(head,false);
  adjust_tail:=adjust_head; package(0);
  end;
@z

@x
begin d:=box_max_depth; unsave; save_ptr:=save_ptr-3;
if mode=-hmode then cur_box:=hpack(link(head),saved(2),saved(1))
else  begin cur_box:=vpackage(link(head),saved(2),saved(1),d);
  if c=vtop_code then @<Readjust the height and depth of |cur_box|,
    for \.{\\vtop}@>;
  end;
pop_nest; box_end(saved(0));
end;
@y
begin d:=box_max_depth;
  delete_glue_ref(cur_kanji_skip); delete_glue_ref(cur_xkanji_skip);
  if auto_spacing>0 then cur_kanji_skip:=kanji_skip
  else cur_kanji_skip:=zero_glue;
  if auto_xspacing>0 then cur_xkanji_skip:=xkanji_skip
  else cur_xkanji_skip:=zero_glue;
  add_glue_ref(cur_kanji_skip); add_glue_ref(cur_xkanji_skip);
  unsave; save_ptr:=save_ptr-3;
  if mode=-hmode then begin
    cur_box:=hpack(link(head),saved(2),saved(1));
    set_box_dir(cur_box)(abs(direction)); pop_nest;
  end else begin
    cur_box:=vpackage(link(head),saved(2),saved(1),d);
    set_box_dir(cur_box)(abs(direction)); pop_nest;
    if c=vtop_code then
      @<Readjust the height and depth of |cur_box|, for \.{\\vtop}@>;
  end;
  box_end(saved(0));
end;
@z

@x
vmode+letter,vmode+other_char,vmode+char_num,vmode+char_given,
   vmode+math_shift,vmode+un_hbox,vmode+vrule,
   vmode+accent,vmode+discretionary,vmode+hskip,vmode+valign,
   vmode+ex_space,vmode+no_boundary:@t@>@;@/
  begin back_input; new_graf(true);
  end;
@y
vmode+letter,vmode+other_char,vmode+char_num,vmode+char_given,
   vmode+math_shift,vmode+un_hbox,vmode+vrule,
   vmode+accent,vmode+discretionary,vmode+hskip,vmode+valign,
   vmode+kanji,vmode+kana,vmode+other_kchar,
   vmode+ex_space,vmode+no_boundary:@t@>@;@/
  begin back_input; new_graf(true);
  end;
@z

@x
push_nest; mode:=hmode; space_factor:=1000; set_cur_lang; clang:=cur_lang;
@y
inhibit_glue_flag := false;
push_nest; adjust_dir:=abs(direction);
mode:=hmode; space_factor:=1000; set_cur_lang; clang:=cur_lang;
@z

@x
  begin if head=tail then pop_nest {null paragraphs are ignored}
  else line_break(widow_penalty);
@y
  begin if head=tail then pop_nest {null paragraphs are ignored}
  else begin adjust_hlist(head,true); line_break(widow_penalty)
       end;
@z

@x
new_save_level(insert_group); scan_left_brace; normal_paragraph;
push_nest; mode:=-vmode; prev_depth:=ignore_depth;
@y
new_save_level(insert_group); scan_left_brace; normal_paragraph;
push_nest; mode:=-vmode; direction:=adjust_dir; prev_depth:=ignore_depth;
@z

@x
insert_group: begin end_graf; q:=split_top_skip; add_glue_ref(q);
  d:=split_max_depth; f:=floating_penalty; unsave; decr(save_ptr);
  {now |saved(0)| is the insertion number, or 255 for |vadjust|}
  p:=vpack(link(head),natural); pop_nest;
  if saved(0)<255 then
    begin tail_append(get_node(ins_node_size));
    type(tail):=ins_node; subtype(tail):=qi(saved(0));
    height(tail):=height(p)+depth(p); ins_ptr(tail):=list_ptr(p);
    split_top_ptr(tail):=q; depth(tail):=d; float_cost(tail):=f;
    end
  else  begin tail_append(get_node(small_node_size));
    type(tail):=adjust_node;@/
    subtype(tail):=0; {the |subtype| is not used}
    adjust_ptr(tail):=list_ptr(p); delete_glue_ref(q);
    end;
  free_node(p,box_node_size);
  if nest_ptr=0 then build_page;
  end;
@y
insert_group: begin end_graf; q:=split_top_skip; add_glue_ref(q);
  d:=split_max_depth; f:=floating_penalty; unsave; decr(save_ptr);
  {now |saved(0)| is the insertion number, or 255 for |vadjust|}
  p:=vpack(link(head),natural); set_box_dir(p)(abs(direction)); pop_nest;
  if saved(0)<255 then
    begin r:=get_node(ins_node_size);
    type(r):=ins_node; subtype(r):=qi(saved(0));
    height(r):=height(p)+depth(p); ins_ptr(r):=list_ptr(p);
    split_top_ptr(r):=q; depth(r):=d; float_cost(r):=f;
    ins_dir(r):=box_dir(p);
    if not is_char_node(tail)and(type(tail)=disp_node) then
      prev_append(r)
    else tail_append(r);
    end
  else  begin
    if box_dir(p)<>adjust_dir then
      begin print_err("Direction Incompatible.");
      help1("\vadjust's argument and outer vlist must have same direction.");
      error; flush_node_list(list_ptr(p));
      end
    else  begin
      r:=get_node(small_node_size); type(r):=adjust_node;@/
      adjust_ptr(r):=list_ptr(p); delete_glue_ref(q);
      if not is_char_node(tail)and(type(tail)=disp_node) then
        prev_append(r)
      else tail_append(r);
      end;
    end;
  delete_glue_ref(space_ptr(p));
  delete_glue_ref(xspace_ptr(p));
  free_node(p,box_node_size);
  if nest_ptr=0 then build_page;
  end;
@z

@x
mark_ptr(p):=def_ref; link(tail):=p; tail:=p;
@y
mark_ptr(p):=def_ref;
if not is_char_node(tail)and(type(tail)=disp_node) then
  prev_append(p)
else tail_append(p);
@z

@x
procedure append_penalty;
begin scan_int; tail_append(new_penalty(cur_val));
if mode=vmode then build_page;
end;
@y
procedure append_penalty;
begin scan_int;
  if not is_char_node(tail)and(type(tail)=disp_node) then
    prev_append(new_penalty(cur_val))
  else tail_append(new_penalty(cur_val));
  if mode=vmode then build_page;
end;
@z

@x
@!m:quarterword; {the length of a replacement list}
@y
@!r:pointer; {running behind |p|}
@!fd:boolean; {a final |disp_node| pair?}
@!disp,@!pdisp:scaled; {displacement}
@!tx:pointer; {effective tail node}
@!m:quarterword; {the length of a replacement list}
@z

@x
else  begin if not is_char_node(tail) then if type(tail)=cur_chr then
    begin q:=head;
    repeat p:=q;
    if not is_char_node(q) then if type(q)=disc_node then
      begin for m:=1 to replace_count(q) do p:=link(p);
      if p=tail then return;
      end;
    q:=link(p);
    until q=tail;
    link(p):=null; flush_node_list(tail); tail:=p;
@y
else  begin check_effective_tail(return);
  if not is_char_node(tx) then if type(tx)=cur_chr then
    begin fetch_effective_tail(return);
    flush_node_list(tx);
@z

@x
var p:pointer; {the box}
@!c:box_code..copy_code; {should we copy?}
@y
var p:pointer; {the box}
@!c:box_code..copy_code; {should we copy?}
@!disp:scaled; {displacement}
@z

@x
if (abs(mode)=mmode)or((abs(mode)=vmode)and(type(p)<>vlist_node))or@|
   ((abs(mode)=hmode)and(type(p)<>hlist_node)) then
  begin print_err("Incompatible list can't be unboxed");
@.Incompatible list...@>
  help3("Sorry, Pandora. (You sneaky devil.)")@/
  ("I refuse to unbox an \hbox in vertical mode or vice versa.")@/
  ("And I can't open any boxes in math mode.");@/
  error; return;
  end;
if c=copy_code then link(tail):=copy_node_list(list_ptr(p))
else  begin link(tail):=list_ptr(p); box(cur_val):=null;
  free_node(p,box_node_size);
  end;
@y
if type(p)=dir_node then p:=list_ptr(p);
if (abs(mode)=mmode)or((abs(mode)=vmode)and(type(p)<>vlist_node))or@|
    ((abs(mode)=hmode)and(type(p)<>hlist_node)) then
  begin print_err("Incompatible list can't be unboxed");
@.Incompatible list...@>
  help3("Sorry, Pandora. (You sneaky devil.)")@/
  ("I refuse to unbox an \hbox in vertical mode or vice versa.")@/
  ("And I can't open any boxes in math mode.");@/
  error; return;
end;
case box_dir(p) of
  any_dir:
    if abs(direction)<>box_dir(p) then begin
      print_err("Incompatible direction list can't be unboxed");
      help2("Sorry, Pandora. (You sneaky devil.)")@/
      ("I refuse to unbox a box in differrent direction.");@/
      error; return;
    end;
endcases;
disp:=0;
if c=copy_code then link(tail):=copy_node_list(list_ptr(p))
else
  begin if type(box(cur_val))=dir_node then
    begin delete_glue_ref(space_ptr(box(cur_val)));
    delete_glue_ref(xspace_ptr(box(cur_val)));
    free_node(box(cur_val),box_node_size);
    end;
  flush_node_list(link(p));
  link(tail):=list_ptr(p); box(cur_val):=null;
  delete_glue_ref(space_ptr(p));
  delete_glue_ref(xspace_ptr(p));
  free_node(p,box_node_size);
  end;
@z

@x
while link(tail)<>null do tail:=link(tail);
@y
while link(tail)<>null do
  begin p:=tail; tail:=link(tail);
  if not is_char_node(tail) then
    case type(tail) of
    glue_node :
      if (subtype(tail)=kanji_skip_code+1)
             or(subtype(tail)=xkanji_skip_code+1) then
        begin link(p):=link(tail);
        delete_glue_ref(glue_ptr(tail));
        free_node(tail,small_node_size); tail:=p;
        end;
    penalty_node :
      if subtype(tail)=widow_pena then
        begin link(p):=link(tail); free_node(tail,small_node_size);
        tail:=p;
        end;
    disp_node :
      begin prev_disp:=disp; disp:=disp_dimen(tail); prev_node:=p;
      end;
    endcases;
  end;
@z

@x
procedure append_italic_correction;
label exit;
var p:pointer; {|char_node| at the tail of the current list}
@!f:internal_font_number; {the font in the |char_node|}
begin if tail<>head then
  begin if is_char_node(tail) then p:=tail
  else if type(tail)=ligature_node then p:=lig_char(tail)
  else return;
  f:=font(p);
  tail_append(new_kern(char_italic(f)(char_info(f)(character(p)))));
  subtype(tail):=explicit;
  end;
@y
procedure append_italic_correction;
label exit;
var p:pointer; {|char_node| at the tail of the current list}
@!f:internal_font_number; {the font in the |char_node|}
@!d:pointer; {|disp_node|}
begin if tail<>head then
  begin
  if not is_char_node(tail)and(type(tail)=disp_node) then
    begin d:=tail; tail:=prev_node;
    end
  else d:=null;
  if (last_jchr<>null)and(link(last_jchr)=tail)and(is_char_node(tail)) then
    p:=last_jchr
  else if is_char_node(tail) then p:=tail
  else if type(tail)=ligature_node then p:=lig_char(tail)
  else return;
  f:=font(p);
  tail_append(new_kern(char_italic(f)(char_info(f)(character(p)))));
  subtype(tail):=ita_kern;
  if d<>null then
    begin prev_node:=tail; tail_append(d);
    end;
  end;
@z

@x
decr(save_ptr); return;
@y
decr(save_ptr);
prev_node:=tail; tail_append(get_node(small_node_size));
type(tail):=disp_node; disp_dimen(tail):=0; prev_disp:=0;
return;
@z

@x
  begin if not is_char_node(p) then if type(p)>rule_node then
    if type(p)<>kern_node then if type(p)<>ligature_node then
      begin print_err("Improper discretionary list");
@y
  begin if not is_char_node(p) then
    if (type(p)>rule_node)and(type(p)<>kern_node)and
         (type(p)<>ligature_node)and(type(p)<>disp_node) then
      if (type(p)=penalty_node)and(subtype(p)<>normal) then
        begin link(q):=link(p); free_node(p,small_node_size); p:=q;
        end
      else
        begin print_err("Improper discretionary list");
@z

@x
var s,@!t: real; {amount of slant}
@y
var s,@!t: real; {amount of slant}
@!disp:scaled; {displacement}
@!cx:KANJI_code; {temporary register for KANJI}
@z

@x
begin scan_char_num; f:=cur_font; p:=new_character(f,cur_val);
@y
begin scan_char_num;
if not is_char_ascii(cur_val) then
  begin KANJI(cx):=cur_val;
  if direction=dir_tate then f:=cur_tfont else f:=cur_jfont;
  p:=new_character(f,get_jfm_pos(KANJI(cx),f));
  if p<>null then
    begin
      link(p):=get_avail; info(link(p)):=KANJI(cx);
    end;
  end
else begin f:=cur_font; p:=new_character(f,cur_val);
  end;
@z

@x
  link(tail):=p; tail:=p; space_factor:=1000;
@y
  link(tail):=p;
  if link(p)<>null then tail:=link(p) else tail:=p;
  @<Append |disp_node| at end of displace area@>;
  space_factor:=1000;
@z

@x
q:=null; f:=cur_font;
if (cur_cmd=letter)or(cur_cmd=other_char)or(cur_cmd=char_given) then
  q:=new_character(f,cur_chr)
else if cur_cmd=char_num then
  begin scan_char_num; q:=new_character(f,cur_val);
  end
else back_input
@y
q:=null; f:=cur_font; KANJI(cx):=empty;
if (cur_cmd=letter)or(cur_cmd=other_char) then
  q:=new_character(f,cur_chr)
else if (cur_cmd=kanji)or(cur_cmd=kana)or(cur_cmd=other_kchar) then
  begin  if direction=dir_tate then f:=cur_tfont else f:=cur_jfont;
  cx:=cur_chr;
  end
else if cur_cmd=char_given then
  if is_char_ascii(cur_chr) then q:=new_character(f,cur_chr)
  else begin
    if direction=dir_tate then f:=cur_tfont else f:=cur_jfont;
    KANJI(cx):=cur_chr
    end
  else if cur_cmd=char_num then
    begin scan_char_num;
    if is_char_ascii(cur_val) then q:=new_character(f,cur_val)
    else  begin
      if direction=dir_tate then f:=cur_tfont else f:=cur_jfont;
      KANJI(cx):=cur_val
    end
  end
else back_input;
if direction=dir_tate then
  begin if font_dir[f]=dir_tate then disp:=0
  else if font_dir[f]=dir_yoko then disp:=t_baseline_shift-y_baseline_shift
  else disp:=t_baseline_shift
  end
else  begin if font_dir[f]=dir_yoko then disp:=0
  else if font_dir[f]=dir_tate then disp:=y_baseline_shift-t_baseline_shift
  else disp:=y_baseline_shift
  end;
@<Append |disp_node| at begin of displace area@>;
if KANJI(cx)<>empty then
  begin q:=new_character(f,get_jfm_pos(KANJI(cx),f));
  link(q):=get_avail; info(link(q)):=KANJI(cx); last_jchr:=q;
  end;
@z

@x
if h<>x then {the accent must be shifted up or down}
  begin p:=hpack(p,natural); shift_amount(p):=x-h;
  end;
@y
if h<>x then {the accent must be shifted up or down}
  begin delete_glue_ref(cur_kanji_skip); delete_glue_ref(cur_xkanji_skip);
  cur_kanji_skip:=zero_glue; cur_xkanji_skip:=zero_glue;
  add_glue_ref(cur_kanji_skip); add_glue_ref(cur_xkanji_skip);
  p:=hpack(p,natural); shift_amount(p):=x-h;
  end;
@z

@x
tail:=new_kern(-a-delta); subtype(tail):=acc_kern; link(p):=tail; p:=q;
@y
tail:=new_kern(-a-delta); subtype(tail):=acc_kern;
if h=x then begin
  if font_dir[font(p)]<>dir_default then link(link(p)):=tail
  else link(p):=tail; end
else link(p):=tail;
{ bugfix: if |p| is KANJI char, |link(p)|:=|tail| collapses |p| and kern after accent. }
p:=q;
@z

@x
if (cur_cmd=math_shift)and(mode>0) then @<Go into display math mode@>
else  begin back_input; @<Go into ordinary math mode@>;
  end;
@y
if (cur_cmd=math_shift)and(mode>0) then @<Go into display math mode@>
else  begin back_input; @<Go into ordinary math mode@>;
  end;
direction:=-abs(direction);
@z

@x
else  begin line_break(display_widow_penalty);@/
@y
else  begin adjust_hlist(head,true); line_break(display_widow_penalty);@/
@z

@x
reswitch: if is_char_node(p) then
  begin f:=font(p); d:=char_width(f)(char_info(f)(character(p)));
  goto found;
  end;
case type(p) of
hlist_node,vlist_node,rule_node: begin d:=width(p); goto found;
  end;
@y
reswitch: if is_char_node(p) then
  begin f:=font(p); d:=char_width(f)(orig_char_info(f)(character(p)));
  if font_dir[f]<>dir_default then p:=link(p);
  goto found;
  end;
case type(p) of
hlist_node,vlist_node,dir_node,rule_node: begin d:=width(p); goto found;
  end;
@z

@x
mmode+left_brace: begin tail_append(new_noad);
  back_input; scan_math(nucleus(tail));
  end;
@y
mmode+left_brace: begin tail_append(new_noad);
  back_input; scan_math(nucleus(tail),kcode_noad(tail));
  end;
@z

@x
procedure scan_math(@!p:pointer);
label restart,reswitch,exit;
var c:integer; {math character code}
begin restart:@<Get the next non-blank non-relax...@>;
reswitch:case cur_cmd of
letter,other_char,char_given: begin c:=ho(math_code(cur_chr));
    if c=@'100000 then
      begin @<Treat |cur_chr| as an active character@>;
      goto restart;
      end;
    end;
@y
procedure scan_math(@!p,@!q:pointer);
label restart,reswitch,exit;
var c:integer; {math character code}
cx:KANJI_code; {temporary register for KANJI}
begin KANJI(cx):=0;
restart: @<Get the next non-blank non-relax...@>;
reswitch:case cur_cmd of
letter,other_char,char_given:
  if (is_char_ascii(cur_chr) or (cur_chr=256)) then begin
    c:=ho(math_code(cur_chr));
    if c=@'100000 then
      begin @<Treat |cur_chr| as an active character@>;
      goto restart;
      end;
    end
  else
    KANJI(cx):=cur_chr;
kanji,kana,other_kchar: cx:=cur_chr;
@z

@x
math_type(p):=math_char; character(p):=qi(c mod 256);
if (c>=var_code)and fam_in_range then fam(p):=cur_fam
else fam(p):=(c div 256) mod 16;
@y
if KANJI(cx)=0 then
  begin math_type(p):=math_char; character(p):=qi(c mod 256);
  if (c>=var_code)and(fam_in_range) then fam(p):=cur_fam
  else fam(p):=(c div 256) mod 16;
  if font_dir[fam_fnt(fam(p)+cur_size)]<>dir_default then
    begin print_err("Not one-byte family");
    help1("IGNORE.");@/
    error;
    end
  end
else  begin
  if q=null then
    begin math_type(p):=sub_mlist; info(p):=new_noad;
    p:=nucleus(info(p)); q:=kcode_noad_nucleus(p);
    end;
  math_type(p):=math_jchar; fam(p):=cur_jfam; character(p):=qi(0);
  math_kcode(p-1):=KANJI(cx);
  if font_dir[fam_fnt(fam(p)+cur_size)]=dir_default then
    begin print_err("Not two-byte family");
    help1("IGNORE.");@/
    error;
    end
  end;
@z

@x
mmode+letter,mmode+other_char,mmode+char_given:
  set_math_char(ho(math_code(cur_chr)));
mmode+char_num: begin scan_char_num; cur_chr:=cur_val;
  set_math_char(ho(math_code(cur_chr)));
  end;
@y
mmode+letter,mmode+other_char,mmode+char_given:
  if is_char_ascii(cur_chr) then
    if cur_chr<128 then set_math_char(ho(math_code(cur_chr)))
    else set_math_char(cur_chr)
  else set_math_kchar(cur_chr);
mmode+kanji,mmode+kana,mmode+other_kchar: begin
    cx:=cur_chr; set_math_kchar(KANJI(cx));
  end;
mmode+char_num: begin scan_char_num; cur_chr:=cur_val;
  if is_char_ascii(cur_chr) then
    if cur_chr<128 then set_math_char(ho(math_code(cur_chr)))
    else set_math_char(cur_chr)
  else set_math_kchar(cur_chr);
  end;
@z

@x
  link(tail):=p; tail:=p;
@y
  link(tail):=p; tail:=p;
  if font_dir[fam_fnt(fam(nucleus(p))+cur_size)]<>dir_default then begin
    print_err("Not one-byte family");
    help1("IGNORE.");@/
    error;
  end;
  inhibit_glue_flag:=false;
@z

@x
  type(tail):=cur_chr; scan_math(nucleus(tail));
@y
  type(tail):=cur_chr; scan_math(nucleus(tail),kcode_noad(tail));
@z

@x
scan_delimiter(left_delimiter(tail),true); scan_math(nucleus(tail));
@y
scan_delimiter(left_delimiter(tail),true);
scan_math(nucleus(tail),kcode_noad(tail));
@z

@x
scan_math(nucleus(tail));
@y
scan_math(nucleus(tail),kcode_noad(tail));
@z

@x
mmode+vcenter: begin scan_spec(vcenter_group,false); normal_paragraph;
@y
mmode+vcenter: begin
  scan_spec(vcenter_group,false); normal_paragraph;
  inhibit_glue_flag:=false;
@z

@x
vcenter_group: begin end_graf; unsave; save_ptr:=save_ptr-2;
  p:=vpack(link(head),saved(1),saved(0)); pop_nest;
  tail_append(new_noad); type(tail):=vcenter_noad;
  math_type(nucleus(tail)):=sub_box; info(nucleus(tail)):=p;
  end;
@y
vcenter_group: begin end_graf; unsave; save_ptr:=save_ptr-2;
  p:=vpack(link(head),saved(1),saved(0));
  set_box_dir(p)(abs(direction)); pop_nest;
  if box_dir(p)<>abs(direction) then p:=new_dir_node(p,abs(direction));
  tail_append(new_noad); type(tail):=vcenter_noad;
  math_type(nucleus(tail)):=sub_box; info(nucleus(tail)):=p;
  end;
@z

@x
procedure sub_sup;
var t:small_number; {type of previous sub/superscript}
@!p:pointer; {field to be filled by |scan_math|}
begin t:=empty; p:=null;
@y
procedure sub_sup;
var t:small_number; {type of previous sub/superscript}
@!p:pointer; {field to be filled by |scan_math|}
begin t:=empty; p:=null;
inhibit_glue_flag:=false;
@z

@x
scan_math(p);
@y
scan_math(p,null);
@z

@x
begin c:=cur_chr;
@y
begin c:=cur_chr; inhibit_glue_flag:=false;
@z

@x
     if math_type(supscr(p))=empty then
      begin mem[saved(0)].hh:=mem[nucleus(p)].hh;
@y
     if ((math_type(supscr(p))=empty)and(math_kcode(p)=null)) then
      begin mem[saved(0)].hh:=mem[nucleus(p)].hh;
@z

@x
begin t:=cur_chr;
@y
begin t:=cur_chr; inhibit_glue_flag:=false;
@z

@x
var l:boolean; {`\.{\\leqno}' instead of `\.{\\eqno}'}
@y
var l:boolean; {`\.{\\leqno}' instead of `\.{\\eqno}'}
@!disp:scaled; {displacement}
@z

@x
m:=mode; l:=false; p:=fin_mlist(null); {this pops the nest}
@y
delete_glue_ref(cur_kanji_skip); delete_glue_ref(cur_xkanji_skip);
if auto_spacing>0 then cur_kanji_skip:=kanji_skip
else cur_kanji_skip:=zero_glue;
if auto_xspacing>0 then cur_xkanji_skip:=xkanji_skip
else cur_xkanji_skip:=zero_glue;
add_glue_ref(cur_kanji_skip); add_glue_ref(cur_xkanji_skip);
m:=mode; l:=false; p:=fin_mlist(null); {this pops the nest}
@z

@x
begin tail_append(new_math(math_surround,before));
cur_mlist:=p; cur_style:=text_style; mlist_penalties:=(mode>0); mlist_to_hlist;
link(tail):=link(temp_head);
while link(tail)<>null do tail:=link(tail);
tail_append(new_math(math_surround,after));
space_factor:=1000; unsave;
end
@y
begin if direction=dir_tate then disp:=t_baseline_shift
      else disp:=y_baseline_shift;
@<Append |disp_node| at begin of displace area@>;
tail_append(new_math(math_surround,before));
cur_mlist:=p; cur_style:=text_style; mlist_penalties:=(mode>0); mlist_to_hlist;
link(tail):=link(temp_head);
while link(tail)<>null do tail:=link(tail);
tail_append(new_math(math_surround,after));
@<Append |disp_node| at end of displace area@>;
space_factor:=1000; unsave;
end
@z

@x
push_nest; mode:=hmode; space_factor:=1000; set_cur_lang; clang:=cur_lang;
@y
push_nest; adjust_dir:=abs(direction);
mode:=hmode; space_factor:=1000; set_cur_lang; clang:=cur_lang;
@z

@x
  begin free_node(b,box_node_size);
@y
  begin delete_glue_ref(space_ptr(b)); delete_glue_ref(xspace_ptr(b));
  free_node(b,box_node_size);
@z

@x
    begin free_node(b,box_node_size);
@y
    begin delete_glue_ref(space_ptr(b)); delete_glue_ref(xspace_ptr(b));
    free_node(b,box_node_size);
@z

@x
any_mode(toks_register),
any_mode(assign_toks),
any_mode(assign_int),
@y
any_mode(assign_kinsoku),
any_mode(assign_inhibit_xsp_code),
any_mode(set_auto_spacing),
any_mode(set_kansuji_char),
any_mode(toks_register),
any_mode(assign_toks),
any_mode(assign_int),
any_mode(def_jfont),
any_mode(def_tfont),
@z

@x
procedure prefixed_command;
label done,exit;
var a:small_number; {accumulated prefix codes so far}
@y
procedure prefixed_command;
label done,exit;
var a:small_number; {accumulated prefix codes so far}
@!m:integer; {ditto}
@z

@x
set_font: define(cur_font_loc,data,cur_chr);
@y
set_font: begin
  if font_dir[cur_chr]=dir_yoko then
    define(cur_jfont_loc,data,cur_chr)
  else if font_dir[cur_chr]=dir_tate then
    define(cur_tfont_loc,data,cur_chr)
  else
    define(cur_font_loc,data,cur_chr)
end;
@z

@x
primitive("futurelet",let,normal+1);@/
@!@:future_let_}{\.{\\futurelet} primitive@>

@ @<Cases of |print_cmd_chr|...@>=
let: if chr_code<>normal then print_esc("futurelet")@+else print_esc("let");

@ @<Assignments@>=
let:  begin n:=cur_chr;
@y
primitive("futurelet",let,normal+1);@/
@!@:future_let_}{\.{\\futurelet} primitive@>

@ @<Cases of |print_cmd_chr|...@>=
let: if chr_code<>normal then print_esc("futurelet")@+else print_esc("let");

@ @<Assignments@>=
let:  begin n:=cur_chr;
@z

@x
assign_int: begin p:=cur_chr; scan_optional_equals; scan_int;
  word_define(p,cur_val);
  end;
@y
assign_int: begin p:=cur_chr; scan_optional_equals; scan_int;
  if p=int_base+cur_fam_code then
    begin if font_dir[fam_fnt(cur_val)]<>dir_default then
      word_define(int_base+cur_jfam_code,cur_val)
    else word_define(p,cur_val);
    end
  else word_define(p,cur_val);
  end;
@z

@x
@<Put each...@>=
primitive("catcode",def_code,cat_code_base);
@!@:cat_code_}{\.{\\catcode} primitive@>
@y
@<Put each...@>=
primitive("catcode",def_code,cat_code_base);
@!@:cat_code_}{\.{\\catcode} primitive@>
primitive("kcatcode",def_code,kcat_code_base);
@!@:cat_code_}{\.{\\kcatcode} primitive@>
primitive("xspcode",def_code,auto_xsp_code_base);
@!@:auto_xsp_code_}{\.{\\xspcode} primitive@>
@z

@x
def_code: if chr_code=cat_code_base then print_esc("catcode")
  else if chr_code=math_code_base then print_esc("mathcode")
@y
def_code: if chr_code=cat_code_base then print_esc("catcode")
  else if chr_code=kcat_code_base then print_esc("kcatcode")
  else if chr_code=auto_xsp_code_base then print_esc("xspcode")
  else if chr_code=math_code_base then print_esc("mathcode")
@z

@x
def_code: begin @<Let |n| be the largest legal code value, based on |cur_chr|@>;
  p:=cur_chr; scan_char_num; p:=p+cur_val; scan_optional_equals;
  scan_int;
  if ((cur_val<0)and(p<del_code_base))or(cur_val>n) then
    begin print_err("Invalid code ("); print_int(cur_val);
@.Invalid code@>
    if p<del_code_base then print("), should be in the range 0..")
    else print("), should be at most ");
    print_int(n);
    help1("I'm going to use 0 instead of that illegal code value.");@/
    error; cur_val:=0;
    end;
  if p<math_code_base then define(p,data,cur_val)
  else if p<del_code_base then define(p,data,hi(cur_val))
  else word_define(p,cur_val);
  end;
@y
def_code: begin
  @<Let |m| be the minimal legal code value, based on |cur_chr|@>;
  @<Let |n| be the largest legal code value, based on |cur_chr|@>;
  p:=cur_chr; scan_char_num;
  if p=kcat_code_base then p:=p+kcatcodekey(cur_val)
  else if not is_char_ascii(cur_val) then p:=p+Hi(cur_val)
    { If |cur_val| is a KANJI code, we use its upper half, as the case of retrieving. }
  else p:=p+cur_val;
  scan_optional_equals; scan_int;
  if ((cur_val<m)and(p<del_code_base))or(cur_val>n) then
  begin print_err("Invalid code ("); print_int(cur_val);
@.Invalid code@>
    if p<del_code_base then
      begin print("), should be in the range "); print_int(m); print("..");
      end
    else print("), should be at most ");
    print_int(n);
    if m=0 then
      begin help1("I'm going to use 0 instead of that illegal code value.");@/
      error;
      end
    else
      begin help1("I'm going to use 16 instead of that illegal code value.");@/
      error;
      end;
    cur_val:=m;
  end;
  if p<math_code_base then define(p,data,cur_val)
  else if p<del_code_base then define(p,data,hi(cur_val))
  else word_define(p,cur_val);
  end;
@z

@x
@ @<Let |n| be the largest...@>=
if cur_chr=cat_code_base then n:=max_char_code
@y
@ @<Let |m| be the minimal...@>=
if cur_chr=kcat_code_base then m:=kanji else m:=0

@ @<Let |n| be the largest...@>=
if cur_chr=cat_code_base then n:=invalid_char {1byte |max_char_code|}
else if cur_chr=kcat_code_base then n:=max_char_code
@z

@x
procedure alter_box_dimen;
var c:small_number; {|width_offset| or |height_offset| or |depth_offset|}
@y
procedure alter_box_dimen;
var c:small_number; {|width_offset| or |height_offset| or |depth_offset|}
@!p,q:pointer; {temporary registers}
@z

@x
scan_normal_dimen;
if box(b)<>null then mem[box(b)+c].sc:=cur_val;
end;
@y
scan_normal_dimen;
if box(b)<>null then
  begin q:=box(b); p:=link(q);
  while p<>null do
    begin if abs(direction)=box_dir(p) then q:=p;
    p:=link(p);
    end;
  if box_dir(q)<>abs(direction) then
    begin p:=link(box(b)); link(box(b)):=null;
    q:=new_dir_node(q,abs(direction)); list_ptr(q):=null;
    link(q):=p; link(box(b)):=q;
    end;
    mem[q+c].sc:=cur_val;
  end;
end;
@z

@x
def_font: new_font(a);
@y
def_tfont,def_jfont,def_font: new_font(a);
@z

@x
@<Change the case of the token in |p|, if a change is appropriate@>=
t:=info(p);
if t<cs_token_flag+single_base then
  begin c:=t mod 256;
  if equiv(b+c)<>0 then info(p):=t-c+equiv(b+c);
  end
@y
@<Change the case of the token in |p|, if a change is appropriate@>=
t:=info(p);
if (t<cs_token_flag+single_base)and(not check_kanji(t)) then
  begin c:=t mod 256;
  if equiv(b+c)<>0 then info(p):=t-c+equiv(b+c);
  end
@z

@x
@d show_lists=3 { \.{\\showlists} }
@y
@d show_lists=3 { \.{\\showlists} }
@d show_mode=4 { \.{\\showmode} }
@z

@x
primitive("showlists",xray,show_lists);
@!@:show_lists_}{\.{\\showlists} primitive@>
@y
primitive("showlists",xray,show_lists);
@!@:show_lists_}{\.{\\showlists} primitive@>
primitive("showmode",xray,show_mode);
@!@:show_mode_}{\.{\\showmode} primitive@>
@z

@x
  othercases print_esc("show")
@y
  show_mode:print_esc("showmode");
  othercases print_esc("show")
@z

@x
show_code: @<Show the current meaning of a token, then |goto common_ending|@>;
@y
show_code: @<Show the current meaning of a token, then |goto common_ending|@>;
show_mode: @<Show the current japanese processing mode@>;
@z

@x
font_info:=xmalloc_array(fmemory_word, font_mem_size);
@y
font_info:=xmalloc_array(memory_word, font_mem_size);
@z

@x
@ @<Dump the array info for internal font number |k|@>=
begin
dump_things(font_check[null_font], font_ptr+1-null_font);
@y
@ @<Dump the array info for internal font number |k|@>=
begin
dump_things(font_dir[null_font], font_ptr+1-null_font);
dump_things(font_num_ext[null_font], font_ptr+1-null_font);
dump_things(font_check[null_font], font_ptr+1-null_font);
@z

@x
dump_things(char_base[null_font], font_ptr+1-null_font);
@y
dump_things(ctype_base[null_font], font_ptr+1-null_font);
dump_things(char_base[null_font], font_ptr+1-null_font);
@z

@x
@<Undump the array info for internal font number |k|@>=
begin {Allocate the font arrays}
@y
@<Undump the array info for internal font number |k|@>=
begin {Allocate the font arrays}
font_dir:=xmalloc_array(eight_bits, font_max);
font_num_ext:=xmalloc_array(integer, font_max);
@z

@x
char_base:=xmalloc_array(integer, font_max);
@y
ctype_base:=xmalloc_array(integer, font_max);
char_base:=xmalloc_array(integer, font_max);
@z

@x
undump_things(font_check[null_font], font_ptr+1-null_font);
@y
undump_things(font_dir[null_font], font_ptr+1-null_font);
undump_things(font_num_ext[null_font], font_ptr+1-null_font);
undump_things(font_check[null_font], font_ptr+1-null_font);
@z

@x
undump_things(char_base[null_font], font_ptr+1-null_font);
@y
undump_things(ctype_base[null_font], font_ptr+1-null_font);
undump_things(char_base[null_font], font_ptr+1-null_font);
@z

@x
  font_info:=xmalloc_array (fmemory_word, font_mem_size);
@y
  font_info:=xmalloc_array (memory_word, font_mem_size);
@z

@x
history:=spotless; {ready to go!}
@y
history:=spotless; {ready to go!}
@<Initialize synctex primitive@>
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
  font_check:=xmalloc_array(four_quarters, font_max);
@y
  font_dir:=xmalloc_array(eight_bits, font_max);
  font_num_ext:=xmalloc_array(integer, font_max);
  font_check:=xmalloc_array(four_quarters, font_max);
@z

@x
  char_base:=xmalloc_array(integer, font_max);
@y
  ctype_base:=xmalloc_array(integer, font_max);
  char_base:=xmalloc_array(integer, font_max);
@z

@x
  font_ptr:=null_font; fmem_ptr:=7;
@y
  font_ptr:=null_font; fmem_ptr:=7;
  font_dir[null_font]:=dir_default;
  font_num_ext[null_font]:=0;
@z

@x
  char_base[null_font]:=0; width_base[null_font]:=0;
@y
  ctype_base[null_font]:=0; char_base[null_font]:=0; width_base[null_font]:=0;
@z

@x
@<Glob...@> =
@!debug_format_file: boolean;
@y
@<Glob...@> =
@!debug_format_file: boolean;

@ @<Set init...@>=
@!debug debug_format_file:=true; @+gubed;
@z

@x
@* \[54] System-dependent changes.
@y
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

@* \[55/p\TeX] System-dependent changes for p\TeX.
This section described extended variables, procesures, functions and so on
for pTeX.

@<Declare procedures that scan font-related stuff@>=
function get_jfm_pos(@!kcode:KANJI_code;@!f:internal_font_number):eight_bits;
var @!jc:KANJI_code; {temporary register for KANJI}
@!sp,@!mp,@!ep:pointer;
begin@/
if f=null_font then
  begin get_jfm_pos:=kchar_type(null_font)(0); return;
  end;
jc:=toDVI(kcode);
sp:=1; { start position }
ep:=font_num_ext[f]-1; { end position }
if (ep>=1)and(kchar_code(f)(sp)<=jc)and(jc<=kchar_code(f)(ep)) then
  begin while (sp <= ep) do
    begin mp:=sp+((ep-sp) div 2);
    if jc<kchar_code(f)(mp) then ep:=mp-1
    else if jc>kchar_code(f)(mp) then sp:=mp+1
    else
      begin get_jfm_pos:=kchar_type(f)(mp); return;
      end;
    end;
  end;
get_jfm_pos:=kchar_type(f)(0);
end;

@ Following codes are used to calcutation a KANJI width and height.

@<Local variables for dimension calculations@>=
@!t: eight_bits;

@ @<The KANJI width for |cur_jfont|@>=
if direction=dir_tate then
  v:=char_width(cur_tfont)(orig_char_info(cur_tfont)(qi(0)))
else
  v:=char_width(cur_jfont)(orig_char_info(cur_jfont)(qi(0)))

@ @<The KANJI height for |cur_jfont|@>=
if direction=dir_tate then begin
  t:=height_depth(orig_char_info(cur_tfont)(qi(0)));
  v:=char_height(cur_tfont)(t)+char_depth(cur_tfont)(t);
end else begin
  t:=height_depth(orig_char_info(cur_jfont)(qi(0)));
  v:=char_height(cur_jfont)(t)+char_depth(cur_jfont)(t);
end

@ set a kansuji character.

@ @<Put each...@>=
primitive("kansujichar",set_kansuji_char,0);
@!@:kansujichar_}{\.{\\kansujichar} primitive@>

@ @<Cases of |print_cmd_chr|...@>=
set_kansuji_char: print_esc("kansujichar");

@ @<Assignments@>=
set_kansuji_char:
begin p:=cur_chr; scan_int; n:=cur_val; scan_optional_equals; scan_int;
if not is_char_kanji(cur_val) then
  begin print_err("Invalid KANSUJI char (");
  print_hex(cur_val); print_char(")");
@.Invalid KANSUJI char@>
  help1("I'm skip this control sequences.");@/
  error; return;
  end
else if (n<0)or(n>9) then
  begin print_err("Invalid KANSUJI number ("); print_int(n); print_char(")");
@.Invalid KANSUJI number@>
  help1("I'm skip this control sequences.");@/
  error; return;
  end
else
  define(kansuji_base+n,n,tokanji(toDVI(cur_val)));
end;

@ |print_kansuji| procedure converts a number to KANJI number.

@ @<Declare procedures needed in |scan_something_internal|@>=
procedure print_kansuji(@!n:integer);
var @!k:0..23; {index to current digit; we assume that $|n|<10^{23}$}
@!cx: KANJI_code; {temporary register for KANJI}
begin k:=0;
  if n<0 then return; {nonpositive input produces no output}
  repeat dig[k]:=n mod 10; n:=n div 10; incr(k);
  until n=0;
  begin while k>0 do
    begin decr(k);
	cx:=kansuji_char(dig[k]);
	print_kanji(fromDVI(cx));
    end;
  end;
end;

@ pTeX inserts a glue specified by \.{\\kanjiskip} between 2byte-characters,
automatically, if \.{\\autospacing}.  This glue is suppressed by
\.{\\noautospacing}.
\.{\\xkanjiskip}, \.{\\noautoxspacing}, \.{\\autoxspacing}, \.{\\xspcode} is
used to control between 2byte and 1byte characters.

@d reset_auto_spacing_code=0
@d set_auto_spacing_code=1
@d reset_auto_xspacing_code=2
@d set_auto_xspacing_code=3

@<Put each...@>=
primitive("autospacing",set_auto_spacing,set_auto_spacing_code);
@!@:auto_spacing_}{\.{\\autospacing} primitive@>
primitive("noautospacing",set_auto_spacing,reset_auto_spacing_code);
@!@:no_auto_spacing_}{\.{\\noautospacing} primitive@>
primitive("autoxspacing",set_auto_spacing,set_auto_xspacing_code);
@!@:auto_xspacing_}{\.{\\autoxspacing} primitive@>
primitive("noautoxspacing",set_auto_spacing,reset_auto_xspacing_code);
@!@:no_auto_xspacing_}{\.{\\noautoxspacing} primitive@>

@ @<Cases of |print_cmd_chr|...@>=
set_auto_spacing:begin
  if (chr_code mod 2)=0 then print_esc("noauto") else print_esc("auto");
  if chr_code<2 then print("spacing") else print("xspacing");
end;

@ @<Assignments@>=
set_auto_spacing:begin
  if cur_chr<2 then p:=auto_spacing_code
  else begin p:=auto_xspacing_code; cur_chr:=(cur_chr mod 2); end;
  define(p,data,cur_chr);
end;

@ Following codes are used in section 49.

@<Show the current japanese processing mode@>=
begin print_nl("> ");
if auto_spacing>0 then print("auto spacing mode; ")
  else print("no auto spacing mode; ");
print_nl("> ");
if auto_xspacing>0 then print("auto xspacing mode")
  else print("no auto xspacing mode");
goto common_ending;
end

@ The \.{\\inhibitglue} primitive control to insert a glue specified
JFM (Japanese Font Metic) file.  The \.{\\inhibitxspcode} is used to control
inserting a space between 2byte-char and 1byte-char.

@d inhibit_both=0     {disable to insert space before 2byte-char and after it}
@d inhibit_previous=1 {disable to insert space before 2byte-char}
@d inhibit_after=2    {disable to insert space after 2byte-char}
@d no_entry=1000
@d new_pos=0
@d cur_pos=1

@<Global...@>=
  inhibit_glue_flag:boolean;

@ @<Set init...@>=
  inhibit_glue_flag:=false;

@ @<Cases of |main_control| that don't...@>=
  any_mode(inhibit_glue): inhibit_glue_flag:=true;

@ @<Put each...@>=
primitive("inhibitglue",inhibit_glue,0);
@!@:inhibit_glue_}{\.{\\inhibitglue} primitive@>
primitive("inhibitxspcode",assign_inhibit_xsp_code,inhibit_xsp_code_base);
@!@:inhibit_xsp_code_}{\.{\\inhibitxspcode} primitive@>

@ @<Cases of |print_cmd_chr|...@>=
inhibit_glue: print_esc("inhibitglue");
assign_inhibit_xsp_code: print_esc("inhibitxspcode");

@ @<Declare procedures needed in |scan_something_internal|@>=
function get_inhibit_pos(c:KANJI_code; n:small_number):pointer;
label done, done1;
var p,s:pointer;
begin s:=calc_pos(c); p:=s;
if n=new_pos then
  begin repeat
  if (inhibit_xsp_code(p)=0)or(inhibit_xsp_code(p)=c) then goto done;
  incr(p); if p>255 then p:=0;
  until s=p; p:=no_entry;
  end
else
  begin repeat
  if inhibit_xsp_code(p)=0 then goto done1;
  if inhibit_xsp_code(p)=c then goto done;
  incr(p); if p>255 then p:=0;
  until s=p;
done1: p:=no_entry;
  end;
done: get_inhibit_pos:=p;
end;

@ @<Assignments@>=
assign_inhibit_xsp_code:
begin p:=cur_chr; scan_int; n:=cur_val; scan_optional_equals; scan_int;
if is_char_kanji(n) then
  begin j:=get_inhibit_pos(tokanji(n),new_pos);
  if j=no_entry then
    begin print_err("Inhibit table is full!!");
    help1("I'm skip this control sequences.");@/
    error; return;
  end;
  define(inhibit_xsp_code_base+j,cur_val,n);
  end
else
  begin print_err("Invalid KANJI code ("); print_hex(n); print_char(")");
@.Invalid KANJI code@>
  help1("I'm skip this control sequences.");@/
  error; return;
  end;
end;

@ @<Fetch inhibit type from some table@>=
begin scan_int; q:=get_inhibit_pos(tokanji(cur_val),cur_pos);
cur_val_level:=int_val; cur_val:=3;
if q<>no_entry then cur_val:=inhibit_xsp_type(q);
end

@ The \.{\\prebreakpenalty} is used to specified amount of penalties inserted
before the 2byte-char which is first argument of this primitive.
The \.{\\postbreakpenalty} is inserted after the 2byte-char.

@d pre_break_penalty_code=1
@d post_break_penalty_code=2

@<Put each...@>=
primitive("prebreakpenalty",assign_kinsoku,pre_break_penalty_code);
@!@:pre_break_penalty_}{\.{\\prebreakpenalty} primitive@>
primitive("postbreakpenalty",assign_kinsoku,post_break_penalty_code);
@!@:post_break_penalty_}{\.{\\postbreakpenalty} primitive@>

@ @<Cases of |print_cmd_chr|...@>=
assign_kinsoku: case chr_code of
  pre_break_penalty_code: print_esc("prebreakpenalty");
  post_break_penalty_code: print_esc("postbreakpenalty");
  endcases;

@ @<Declare procedures needed in |scan_something_internal|@>=
function get_kinsoku_pos(c:KANJI_code; n:small_number):pointer;
label done, done1;
var p,s:pointer;
begin s:=calc_pos(c); p:=s;
@!debug
print_ln; print("c:="); print_int(c); print(", p:="); print_int(s);
if p+kinsoku_base<0 then
  begin print("p is negative value"); print_ln;
  end;
gubed
if n=new_pos then
  begin repeat
  if (kinsoku_type(p)=0)or(kinsoku_code(p)=c) then goto done;
  incr(p); if p>255 then p:=0;
  until s=p;
  p:=no_entry;
  end
else
  begin repeat
  if kinsoku_type(p)=0 then goto done1;
  if kinsoku_code(p)=c then goto done;
  incr(p); if p>255 then p:=0;
  until s=p;
done1: p:=no_entry;
  end;
done: get_kinsoku_pos:=p;
end;

@ @<Assignments@>=
assign_kinsoku:
begin p:=cur_chr; scan_int; n:=cur_val; scan_optional_equals; scan_int;
if is_char_ascii(n) or is_char_kanji(n) then
  begin j:=get_kinsoku_pos(tokanji(n),new_pos);
  if j=no_entry then
    begin print_err("KINSOKU table is full!!");
    help1("I'm skip this control sequences.");@/
    error; return;
    end;
  if (p=pre_break_penalty_code)or(p=post_break_penalty_code) then
    begin define(kinsoku_base+j,p,tokanji(n));
    word_define(kinsoku_penalty_base+j,cur_val);
    end
  else confusion("kinsoku");
@:this can't happen kinsoku}{\quad kinsoku@>
  end
else
  begin print_err("Invalid KANJI code for ");
  if p=pre_break_penalty_code then print("pre")
  else if p=post_break_penalty_code then print("post")
  else print_char("?");
  print("breakpenalty ("); print_hex(n); print_char(")");
@.Invalid KANJI code@>
  help1("I'm skip this control sequences.");@/
  error; return;
  end;
end;

@ @<Fetch breaking penalty from some table@>=
begin scan_int; q:=get_kinsoku_pos(tokanji(cur_val),cur_pos);
cur_val_level:=int_val; cur_val:=0;
if (q<>no_entry)and(m=kinsoku_type(q)) then
    scanned_result(kinsoku_penalty(q))(int_val);
end

@ Following codes are used in |main_control|.

@<Insert kinsoku penalty@>=
begin kp:=get_kinsoku_pos(cx,cur_pos);
if kp<>no_entry then
  begin if kinsoku_type(kp)=pre_break_penalty_code then
    begin if not is_char_node(cur_q)and(type(cur_q)=penalty_node) then
      penalty(cur_q):=penalty(cur_q)+kinsoku_penalty(kp)
    else
      begin main_p:=link(cur_q); link(cur_q):=new_penalty(kinsoku_penalty(kp));
      subtype(link(cur_q)):=kinsoku_pena; link(link(cur_q)):=main_p;
      end;
    end
  else if kinsoku_type(kp)=post_break_penalty_code then
    begin tail_append(new_penalty(kinsoku_penalty(kp)));
    subtype(tail):=kinsoku_pena;
    end;
  end;
end;

@ @<Insert |pre_break_penalty| of |cur_chr|@>=
begin kp:=get_kinsoku_pos(cur_chr,cur_pos);
if kp<>no_entry then
  begin if kinsoku_type(kp)=pre_break_penalty_code then
    if not is_char_node(tail)and(type(tail)=penalty_node) then
      penalty(tail):=penalty(tail)+kinsoku_penalty(kp)
    else
      begin tail_append(new_penalty(kinsoku_penalty(kp)));
      subtype(tail):=kinsoku_pena;
      end;
  end;
end;

@ @<Insert |post_break_penalty|@>=
begin kp:=get_kinsoku_pos(cx,cur_pos);
if kp<>no_entry then
  begin if kinsoku_type(kp)=post_break_penalty_code then
    begin tail_append(new_penalty(kinsoku_penalty(kp)));
    subtype(tail):=kinsoku_pena;
    end;
  end;
end;

@ This is a part of section 32.

The procedure |synch_dir| is used in |hlist_out| and |vlist_out|.

@d dvi_yoko=0
@d dvi_tate=1
@d dvi_dtou=3

@<Glob...@>=
@!dvi_dir:integer; {a \.{DVI} reader program thinks we direct to}
@!cur_dir_hv:integer; {\TeX\ thinks we direct to}
@!page_dir:eight_bits;

@ @<Set init...@>=
page_dir:=dir_yoko;

@ @<Declare procedures needed in |hlist_out|, |vlist_out|@>=
procedure synch_dir;
var tmp:scaled; {temporary resister}
begin
  case cur_dir_hv of
  dir_yoko:
    if dvi_dir<>cur_dir_hv then begin
      synch_h; synch_v; dvi_out(dirchg); dvi_out(dvi_yoko);
      dir_used:=true;
      case dvi_dir of
        dir_tate: begin tmp:=cur_h; cur_h:=-cur_v; cur_v:=tmp end;
        dir_dtou: begin tmp:=cur_h; cur_h:=cur_v; cur_v:=-tmp end;
      endcases;
      dvi_h:=cur_h; dvi_v:=cur_v; dvi_dir:=cur_dir_hv;
    end;
  dir_tate:
    if dvi_dir<>cur_dir_hv then begin
      synch_h; synch_v; dvi_out(dirchg); dvi_out(dvi_tate);
      dir_used:=true;
      case dvi_dir of
        dir_yoko: begin tmp:=cur_h; cur_h:=cur_v; cur_v:=-tmp end;
        dir_dtou: begin cur_v:=-cur_v; cur_h:=-cur_h; end;
      endcases;
      dvi_h:=cur_h; dvi_v:=cur_v; dvi_dir:=cur_dir_hv;
    end;
  dir_dtou:
    if dvi_dir<>cur_dir_hv then begin
      synch_h; synch_v; dvi_out(dirchg); dvi_out(dvi_dtou);
      dir_used:=true;
      case dvi_dir of
        dir_yoko: begin tmp:=cur_h; cur_h:=-cur_v; cur_v:=tmp end;
        dir_tate: begin cur_v:=-cur_v; cur_h:=-cur_h; end;
      endcases;
      dvi_h:=cur_h; dvi_v:=cur_v; dvi_dir:=cur_dir_hv;
    end;
  othercases
    confusion("synch_dir");
  endcases
end;

@ This function is called from |adjust_hlist| to used to check, whether
a list which pointed |box_p| contain a printing character.
If the list contain such a character, then return `true', otherwise `false'.
If the first matter is a character, |first_char| is stored it.
|last_char| is stored a last character.  If no printing characters exist
in the list, |first_char| and |last_char| is null.
@^recursion@>

Note that |first_char| and |last_char| may be |math_node|.

@<Glob...@>=
@!first_char:pointer; {first printable character}
@!last_char:pointer; {last printable character}
@!find_first_char:boolean; {find for a first printable character?}

@ @<Declare procedures needed in |hlist_out|, |vlist_out|@>=
function check_box(box_p:pointer):boolean;
label done;
var @!p:pointer; {run through the current box}
@!flag:boolean; {found any printable character?}
begin flag:=false; p:=box_p;
while p<>null do
  begin if is_char_node(p) then
    repeat
    if find_first_char then
      begin first_char:=p; find_first_char:=false
      end;
    last_char:=p; flag:=true;
    if font_dir[font(p)]<>dir_default then p:=link(p);
    p:=link(p);
    if p=null then goto done;
    until not is_char_node(p);
  case type(p) of
  hlist_node:
    begin flag:=true;
      if shift_amount(p)=0 then
        begin if check_box(list_ptr(p)) then flag:=true;
        end
      else if find_first_char then find_first_char:=false
        else last_char:=null;
    end;
  ligature_node: if check_box(lig_ptr(p)) then flag:=true;
  ins_node,disp_node,mark_node,adjust_node,whatsit_node,penalty_node:
    do_nothing;
  math_node:
    if (subtype(p)=before)or(subtype(p)=after) then
      begin if find_first_char then
        begin find_first_char:=false; first_char:=p;
        end;
        last_char:=p; flag:=true;
      end
    else do_nothing; {\.{\\beginR} etc.}
  kern_node:
    if subtype(p)=acc_kern then
      begin p:=link(p);
        if is_char_node(p) then
	  if font_dir[font(p)]<>dir_default then p:=link(p);
        p:=link(link(p));
        if find_first_char then
          begin find_first_char:=false; first_char:=p;
          end;
        last_char:=p; flag:=true;
        if font_dir[font(p)]<>dir_default then p:=link(p);
        end
    else
      begin flag:=true;
        if find_first_char then find_first_char:=false
        else last_char:=null;
        end;
  othercases begin flag:=true;
    if find_first_char then find_first_char:=false
    else last_char:=null;
    end;
  endcases;
  p:=link(p);
  end;
done: check_box:=flag;
end;

@ Following procedure |adjust_hlist| inserts \.{\\xkanjiskip} between
2byte-char and 1byte-char in hlist which pointed |p|.
Note that the skip is inserted into a place where too difficult to decide
whether inserting or not (i.e, before penalty, after penalty).

If |pf| is true then insert |jchr_widow_penalty| that is penalty for
creating a widow KANJI character line.

@d no_skip=0
@d after_schar=1 {denote after single byte character}
@d after_wchar=2 {denote after double bytes character}

@<Declare procedures needed in |hlist_out|, |vlist_out|@>=
procedure adjust_hlist(p:pointer;pf:boolean);
label exit;
var q,s,t,u,v,x,z:pointer;
  i,k:halfword;
  a: pointer; { temporary pointer for accent }
  insert_skip:no_skip..after_wchar;
  cx:KANJI_code; {temporaly register for KANJI character}
  ax:ASCII_code; {temporaly register for ASCII character}
  do_ins:boolean; {for inserting |xkanji_skip| into prevous (or after) KANJI}
begin if link(p)=null then goto exit;
if auto_spacing>0 then
  begin delete_glue_ref(space_ptr(p)); space_ptr(p):=kanji_skip;
  add_glue_ref(kanji_skip);
  end;
if auto_xspacing>0 then
  begin delete_glue_ref(xspace_ptr(p)); xspace_ptr(p):=xkanji_skip;
  add_glue_ref(xkanji_skip);
  end;
u:=space_ptr(p); add_glue_ref(u);
s:=xspace_ptr(p); add_glue_ref(s);
if not is_char_node(link(p)) {p1.0.9d}
    and(type(link(p))=glue_node)and(subtype(link(p))=jfm_skip+1) then
  begin v:=link(p); link(p):=link(v);
  fast_delete_glue_ref(glue_ptr(v)); free_node(v,small_node_size);
  end;
i:=0; insert_skip:=no_skip; p:=link(p); v:=p; q:=p;
while p<>null do
  begin if is_char_node(p) then
    begin repeat @<Insert a space around the character |p|@>;
      q:=p; p:=link(p); incr(i);
      if (i>5)and pf then
        begin if is_char_node(v) then
        if font_dir[font(v)]<>dir_default then v:=link(v);
        v:=link(v);
        end;
    until not is_char_node(p);
    end
  else
    begin case type(p) of
    hlist_node: @<Insert hbox surround spacing@>;
    ligature_node: @<Insert ligature surround spacing@>;
    penalty_node,disp_node: @<Insert penalty or displace surround spacing@>;
    kern_node: if subtype(p)=explicit then insert_skip:=no_skip
      else if subtype(p)=acc_kern then begin
        { When we insert \.{\\xkanjiskip}, we first ignore accent (and kerns) and
          insert \.{\\xkanjiskip}, then we recover the accent. }
        if q=p then begin t:=link(p);
          { if p is beginning on the list, we have only to ignore nodes. }
          if is_char_node(t) then
            if font_dir[font(t)]<>dir_default then t:=link(t);
          p:=link(link(t));
	  if font_dir[font(p)]<>dir_default then
            begin p:=link(p); insert_skip:=after_wchar; end
          else  insert_skip:=after_schar;
          end
        else begin
          a:=p; t:=link(p);
          if is_char_node(t) then
            if font_dir[font(t)]<>dir_default then t:=link(t);
          t:=link(link(t)); link(q):=t; p:=t;
          @<Insert a space around the character |p|@>; incr(i);
          if (i>5)and pf then
            begin if is_char_node(v) then
            if font_dir[font(v)]<>dir_default then v:=link(v);
            v:=link(v);
            end;
          if link(q)<>t then link(link(q)):=a else link(q):=a;
          end;
        end;
    math_node: @<Insert math surround spacing@>;
    mark_node,adjust_node,ins_node,whatsit_node:
      {These nodes are vanished when typeset is done}
      do_nothing;
    othercases insert_skip:=no_skip;
    endcases;
    q:=p; p:=link(p);
    end;
  end;
if not is_char_node(q)and(type(q)=glue_node)and(subtype(q)=jfm_skip+1) then
  begin fast_delete_glue_ref(glue_ptr(q));
  glue_ptr(q):=zero_glue; add_glue_ref(zero_glue);
  end;
delete_glue_ref(u); delete_glue_ref(s);
if (v<>null)and pf and(i>5) then @<Make |jchr_widow_penalty| node@>;
exit:
end;

@ @<Insert a space around the character |p|@>=
if font_dir[font(p)]<>dir_default then
  begin KANJI(cx):=info(link(p));
  if insert_skip=after_schar then @<Insert ASCII-KANJI spacing@>;
  p:=link(p); insert_skip:=after_wchar;
  end
else
  begin ax:=qo(character(p));
  if insert_skip=after_wchar then @<Insert KANJI-ASCII spacing@>;
  if auto_xsp_code(ax)>=2 then
    insert_skip:=after_schar else insert_skip:=no_skip;
  end

@ @<Insert hbox surround spacing@>=
begin find_first_char:=true; first_char:=null; last_char:=null;
if shift_amount(p)=0 then
  begin if check_box(list_ptr(p)) then
    begin if first_char<>null then @<Insert a space before the |first_char|@>;
    if last_char<>null then
      begin @<Insert a space after the |last_char|@>;
      end else insert_skip:=no_skip;
    end else insert_skip:=no_skip;
  end else insert_skip:=no_skip;
end

@ @<Insert a space before the |first_char|@>=
if type(first_char)=math_node then
  begin ax:=qo("0");
  if insert_skip=after_wchar then @<Insert KANJI-ASCII spacing@>;
  end
else if font_dir[font(first_char)]<>dir_default then
  begin KANJI(cx):=info(link(first_char));
  if insert_skip=after_schar then @<Insert ASCII-KANJI spacing@>
  else if insert_skip=after_wchar then @<Insert KANJI-KANJI spacing@>;
  end
else
  begin ax:=qo(character(first_char));
  if insert_skip=after_wchar then @<Insert KANJI-ASCII spacing@>;
  end;

@ @<Insert a space after the |last_char|@>=
if type(last_char)=math_node then
  begin ax:=qo("0");
  if auto_xsp_code(ax)>=2 then
    insert_skip:=after_schar else insert_skip:=no_skip;
  end
else if font_dir[font(last_char)]<>dir_default then
  begin insert_skip:=after_wchar; KANJI(cx):=info(link(last_char));
  if is_char_node(link(p))and(font_dir[font(link(p))]<>dir_default) then
    begin @<Append KANJI-KANJI spacing@>; p:=link(p);
    end;
  end
else
  begin ax:=qo(character(last_char));
  if auto_xsp_code(ax)>=2 then
    insert_skip:=after_schar else insert_skip:=no_skip;
  end;

@ @<Insert math surround spacing@>=
begin if (subtype(p)=before)and(insert_skip=after_wchar) then
  begin ax:=qo("0"); @<Insert KANJI-ASCII spacing@>;
  insert_skip:=no_skip;
  end
else if subtype(p)=after then
  begin ax:=qo("0");
  if auto_xsp_code(ax)>=2 then
    insert_skip:=after_schar else insert_skip:=no_skip;
  end
else insert_skip:=no_skip;
end

@ @<Insert ligature surround spacing@>=
begin t:=lig_ptr(p);
if is_char_node(t) then
  begin ax:=qo(character(t));
  if insert_skip=after_wchar then @<Insert KANJI-ASCII spacing@>;
  while link(t)<>null do t:=link(t);
  if is_char_node(t) then
    begin ax:=qo(character(t));
    if auto_xsp_code(ax)>=2 then
      insert_skip:=after_schar else insert_skip:=no_skip;
    end;
  end;
end

@ @<Insert penalty or displace surround spacing@>=
begin if is_char_node(link(p)) then
  begin q:=p; p:=link(p);
  if font_dir[font(p)]<>dir_default then
    begin KANJI(cx):=info(link(p));
    if insert_skip=after_schar then @<Insert ASCII-KANJI spacing@>
    else if insert_skip=after_wchar then @<Insert KANJI-KANJI spacing@>;
    p:=link(p); insert_skip:=after_wchar;
    end
  else
    begin ax:=qo(character(p));
    if insert_skip=after_wchar then @<Insert KANJI-ASCII spacing@>;
    if auto_xsp_code(ax)>=2 then
      insert_skip:=after_schar else insert_skip:=no_skip;
    end;
  end
end

@ @<Insert ASCII-KANJI spacing@>=
begin
  begin x:=get_inhibit_pos(cx,cur_pos);
  if x<>no_entry then
    if (inhibit_xsp_type(x)=inhibit_both)or
       (inhibit_xsp_type(x)=inhibit_previous) then
      do_ins:=false else do_ins:=true
  else do_ins:=true;
  end;
if do_ins then
  begin z:=new_glue(s); subtype(z):=xkanji_skip_code+1;
  link(z):=link(q); link(q):=z; q:=z;
  end;
end

@ @<Insert KANJI-ASCII spacing@>=
begin if (auto_xsp_code(ax) mod 2)=1 then
  begin x:=get_inhibit_pos(cx,cur_pos);
  if x<>no_entry then
    if (inhibit_xsp_type(x)=inhibit_both)or
       (inhibit_xsp_type(x)=inhibit_after) then
      do_ins:=false else do_ins:=true
  else do_ins:=true;
  end
else do_ins:=false;
if do_ins then
  begin z:=new_glue(s); subtype(z):=xkanji_skip_code+1;
  link(z):=link(q); link(q):=z; q:=z;
  end;
end

@ @<Insert KANJI-KANJI spacing@>=
begin z:=new_glue(u); subtype(z):=kanji_skip_code+1;
link(z):=link(q); link(q):=z; q:=z;
end

@ @<Append KANJI-KANJI spacing@>=
begin z:=new_glue(u); subtype(z):=kanji_skip_code+1;
link(z):=link(p); link(p):=z; p:=link(z); q:=z;
end

@ @<Make |jchr_widow_penalty| node@>=
begin q:=v; p:=link(v);
if is_char_node(v)and(font_dir[font(v)]<>dir_default) then
  begin q:=p; p:=link(p);
  end;
t:=q; s:=null;
@<Seek list and make |t| pointing widow penalty position@>;
if s<>null then
  begin s:=link(t);
    if not is_char_node(s)and(type(s)=penalty_node) then
      penalty(s):=penalty(s)+jchr_widow_penalty
    else if jchr_widow_penalty<>0 then
      begin s:=new_penalty(jchr_widow_penalty); subtype(s):=widow_pena;
      link(s):=link(t); link(t):=s; t:=link(s);
      while(not is_char_node(t)) do
        begin if (type(t)=glue_node)or(type(t)=kern_node) then goto exit;
        t:=link(t);
        end;
      z:=new_glue(u); subtype(z):=kanji_skip_code+1;
      link(z):=link(s); link(s):=z;
      end;
  end;
end;

@ @<Seek list and make |t| pointing widow penalty position@>=
while(p<>null) do
begin if is_char_node(p) then
  begin if font_dir[font(p)]<>dir_default then
    begin KANJI(cx):=info(link(p)); i:=kcat_code(kcatcodekey(cx)); k:=0;
    if (i=kanji)or(i=kana) then begin t:=q; s:=p; end;
    p:=link(p); q:=p;
    end
  else begin k:=k+1;
    if k>1 then begin q:=p; s:=null; end;
    end;
  end
else begin case type(p) of
  penalty_node,mark_node,adjust_node,whatsit_node,
  glue_node,kern_node,math_node,disp_node:
    do_nothing;
  othercases begin q:=p; s:=null; end;
  endcases;
  end;
p:=link(p);
end

@ @<Declare procedures needed in |hlist_out|, |vlist_out|@>=
procedure dir_out;
var @!this_box: pointer; {pointer to containing box}
begin this_box:=temp_ptr;
  temp_ptr:=list_ptr(this_box);
  if (type(temp_ptr)<>hlist_node)and(type(temp_ptr)<>vlist_node) then
    confusion("dir_out");
  case box_dir(this_box) of
  dir_yoko:
    case box_dir(temp_ptr) of
    dir_tate: {Tate in Yoko}
      begin cur_v:=cur_v-height(this_box); cur_h:=cur_h+depth(temp_ptr) end;
    dir_dtou: {DtoU in Yoko}
      begin cur_v:=cur_v+depth(this_box); cur_h:=cur_h+height(temp_ptr) end;
    endcases;
  dir_tate:
    case box_dir(temp_ptr) of
    dir_yoko: {Yoko in Tate}
      begin cur_v:=cur_v+depth(this_box); cur_h:=cur_h+height(temp_ptr) end;
    dir_dtou: {DtoU in Tate}
      begin
        cur_v:=cur_v+depth(this_box)-height(temp_ptr);
        cur_h:=cur_h+width(temp_ptr)
      end;
    endcases;
  dir_dtou:
    case box_dir(temp_ptr) of
    dir_yoko: {Yoko in DtoU}
      begin cur_v:=cur_v-height(this_box); cur_h:=cur_h+depth(temp_ptr) end;
    dir_tate: {Tate in DtoU}
      begin
        cur_v:=cur_v+depth(this_box)-height(temp_ptr);
        cur_h:=cur_h+width(temp_ptr)
      end;
    endcases;
  endcases;
  cur_dir_hv:=box_dir(temp_ptr);
  if type(temp_ptr)=vlist_node then vlist_out@+else hlist_out;
end;

@ These routines are used to output diagnostic which related direction.

@ @<Basic printing procedures@>=
procedure print_dir(@!dir:eight_bits); {prints |dir| data}
begin if dir=dir_yoko then print_char("Y")
else if dir=dir_tate then print_char("T")
else if dir=dir_dtou then print_char("D")
end;
@#
procedure print_direction(@!d:integer); {print the direction represented by d}
begin case abs(d) of
dir_yoko: print("yoko");
dir_tate: print("tate");
dir_dtou: print("dtou");
end;
if d<0 then print("(math)");
print(" direction");
end;

@ The procedure |set_math_kchar| is same as |set_math_char| which
written in section 48.

@<Declare act...@>=
procedure set_math_kchar(@!c:integer);
var p:pointer; {the new noad}
begin p:=new_noad; math_type(nucleus(p)):=math_jchar;
inhibit_glue_flag:=false;
character(nucleus(p)):=qi(0);
math_kcode(p):=c; fam(nucleus(p)):=cur_jfam;
if font_dir[fam_fnt(fam(nucleus(p))+cur_size)]=dir_default then
  begin print_err("Not two-byte family");
  help1("IGNORE.");@/
  error;
  end;
type(p):=ord_noad;
link(tail):=p; tail:=p;
end;

@ This section is a part of |main_control|.

@<Append KANJI-character |cur_chr| ...@>=
if is_char_node(tail) then
  begin cx:=qo(character(tail)); @<Insert |post_break_penalty|@>;
  end
else if type(tail)=ligature_node then
  begin cx:=qo(character(lig_char(tail))); @<Insert |post_break_penalty|@>;
  end;
if direction=dir_tate then
  begin if font_dir[main_f]=dir_tate then disp:=0
  else if font_dir[main_f]=dir_yoko then disp:=t_baseline_shift-y_baseline_shift
  else disp:=t_baseline_shift;
  main_f:=cur_tfont;
  end
else
  begin if font_dir[main_f]=dir_yoko then disp:=0
  else if font_dir[main_f]=dir_tate then disp:=y_baseline_shift-t_baseline_shift
  else disp:=y_baseline_shift;
  main_f:=cur_jfont;
  end;
@<Append |disp_node| at end of displace area@>;
ins_kp:=false; ligature_present:=false;
cur_l:=qi(get_jfm_pos(KANJI(cur_chr),main_f));
main_i:=orig_char_info(main_f)(qi(0));
goto main_loop_j+3;
@#
main_loop_j+1: space_factor:=1000;
  if main_f<>null_font then
    begin fast_get_avail(main_p); font(main_p):=main_f; character(main_p):=cur_l;
    link(tail):=main_p; tail:=main_p; last_jchr:=tail;
    fast_get_avail(main_p); info(main_p):=KANJI(cur_chr);
    link(tail):=main_p; tail:=main_p;
    cx:=cur_chr; @<Insert kinsoku penalty@>;
  end;
  ins_kp:=false;
again_2:
  get_next;
  main_i:=orig_char_info(main_f)(cur_l);
  case cur_cmd of
    kanji,kana,other_kchar: begin
      cur_l:=qi(get_jfm_pos(KANJI(cur_chr),main_f)); goto main_loop_j+3;
      end;
    letter,other_char: begin ins_kp:=true; cur_l:=qi(0); goto main_loop_j+3;
      end;
  endcases;
  x_token;
  case cur_cmd of
    kanji,kana,other_kchar: cur_l:=qi(get_jfm_pos(KANJI(cur_chr),main_f));
    letter,other_char: begin ins_kp:=true; cur_l:=qi(0); end;
    char_given: begin
      if is_char_ascii(cur_chr) then
        begin ins_kp:=true; cur_l:=qi(0);
        end
      else cur_l:=qi(get_jfm_pos(KANJI(cur_chr),main_f));
      end;
    char_num: begin scan_char_num; cur_chr:=cur_val;
      if is_char_ascii(cur_chr) then
        begin ins_kp:=true; cur_l:=qi(0);
        end
      else cur_l:=qi(get_jfm_pos(KANJI(cur_chr),main_f));
      end;
    inhibit_glue: begin inhibit_glue_flag:=true; goto again_2; end;
    othercases begin ins_kp:=max_halfword;
      cur_l:=qi(0); cur_r:=non_char; lig_stack:=null;
      end;
  endcases;
@#
main_loop_j+3:
  if ins_kp=true then @<Insert |pre_break_penalty| of |cur_chr|@>;
  if main_f<>null_font then
    begin @<Look ahead for glue or kerning@>;
    end
  else inhibit_glue_flag:=false;
  if ins_kp=false then begin { Kanji -> Kanji }
    goto main_loop_j+1;
  end else if ins_kp=true then begin { Kanji -> Ascii }
    {@@<Append |disp_node| at begin of displace area@@>;}
    ins_kp:=false; goto main_loop;
  end else begin { Kanji -> cs }
    {@@<Append |disp_node| at begin of displace area@@>;}
    goto reswitch;
  end;

@ @<Append |disp_node| at begin ...@>=
begin if not is_char_node(tail)and(type(tail)=disp_node) then
  begin if prev_disp=disp then
    begin free_node(tail,small_node_size); tail:=prev_node; link(tail):=null;
    end
  else disp_dimen(tail):=disp;
  end
else
  if disp<>0 then
    begin prev_node:=tail; tail_append(get_node(small_node_size));
    type(tail):=disp_node; disp_dimen(tail):=disp; prev_disp:=disp;
    end;
end;

@ @<Append |disp_node| at end ...@>=
if disp<>0 then
begin if not is_char_node(tail)and(type(tail)=disp_node) then
  begin disp_dimen(tail):=0;
  end
else
  begin prev_node:=tail; tail_append(get_node(small_node_size));
  type(tail):=disp_node; disp_dimen(tail):=0; prev_disp:=disp;
  end;
end;

@ @<Look ahead for glue or kerning@>=
cur_q:=tail;
if inhibit_glue_flag<>true then
  begin if char_tag(main_i)=gk_tag then
    begin main_k:=glue_kern_start(main_f)(main_i);
    repeat main_j:=font_info[main_k].qqqq;
    if next_char(main_j)=cur_l then
      begin if op_byte(main_j)<kern_flag then
        begin gp:=font_glue[main_f]; cur_r:=rem_byte(main_j);
        if gp<>null then
          begin while((type(gp)<>cur_r)and(link(gp)<>null)) do gp:=link(gp);
          gq:=glue_ptr(gp);
          end
        else
          begin gp:=get_node(small_node_size); font_glue[main_f]:=gp;
          gq:=null;
          end;
        if gq=null then
          begin type(gp):=cur_r; gq:=new_spec(zero_glue);
          glue_ptr(gp):=gq;
          main_k:=exten_base[main_f]+qi((qo(cur_r))*3);
          width(gq):=font_info[main_k].sc;
          stretch(gq):=font_info[main_k+1].sc;
          shrink(gq):=font_info[main_k+2].sc;
          add_glue_ref(gq); link(gp):=get_node(small_node_size);
          gp:=link(gp); glue_ptr(gp):=null; link(gp):=null;
          end;
        tail_append(new_glue(gq)); subtype(tail):=jfm_skip+1;
        goto skip_loop;
        end
      else  begin
        tail_append(new_kern(char_kern(main_f)(main_j)));
        goto skip_loop;
        end;
    end;
  incr(main_k);
  until skip_byte(main_j)>=stop_flag;
  end;
end;
skip_loop: inhibit_glue_flag:=false;

@ @<Basic printing...@>=
procedure print_kanji(@!s:KANJI_code); {prints a single character}
begin
if s>255 then
  begin print_char(Hi(s)); print_char(Lo(s));
  end else print_char(s);
end;

@* \[56] System-dependent changes.
@z
