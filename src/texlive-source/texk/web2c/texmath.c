/*1:*/
#line 20 "./luatexdir/tex/texmath.w"



#include "ptexlib.h"

/*:1*//*2:*/
#line 25 "./luatexdir/tex/texmath.w"

#define mode          cur_list.mode_field
#define head          cur_list.head_field
#define tail          cur_list.tail_field
#define prev_graf     cur_list.pg_field
#define eTeX_aux      cur_list.eTeX_aux_field
#define delim_ptr     eTeX_aux
#define space_factor  cur_list.space_factor_field
#define incompleat_noad cur_list.incompleat_noad_field

#define cur_fam int_par(cur_fam_code)














#define display_skip_mode int_par(math_display_skip_mode_code)

#define math_skip glue_par(math_skip_code)

#define var_code 7

/*:2*//*3:*/
#line 57 "./luatexdir/tex/texmath.w"

#define back_error(A,B) do {                    \
    OK_to_interrupt= false;                      \
    back_input();                               \
    OK_to_interrupt= true;                       \
    tex_error(A,B);                             \
  } while (0)

/*:3*//*4:*/
#line 65 "./luatexdir/tex/texmath.w"

int scan_math(pointer,int);
int scan_math_style(pointer,int);
pointer fin_mlist(pointer);

#define pre_display_size dimen_par(pre_display_size_code)
#define hsize            dimen_par(hsize_code)
#define display_width    dimen_par(display_width_code)
#define display_indent   dimen_par(display_indent_code)
#define math_surround    dimen_par(math_surround_code)
#define hang_indent      dimen_par(hang_indent_code)
#define hang_after       int_par(hang_after_code)
#define every_math       equiv(every_math_loc)
#define every_display    equiv(every_display_loc)
#define par_shape_ptr    equiv(par_shape_loc)

#define math_eqno_gap_step int_par(math_eqno_gap_step_code)

/*:4*//*5:*/
#line 161 "./luatexdir/tex/texmath.w"

static void unsave_math(void)
{
unsave();
decr(save_ptr);
flush_node_list(text_dir_ptr);
assert(saved_type(0)==saved_textdir);
text_dir_ptr= saved_value(0);
}

/*:5*//*6:*/
#line 174 "./luatexdir/tex/texmath.w"

void flush_math(void)
{
flush_node_list(vlink(head));
flush_node_list(incompleat_noad);
vlink(head)= null;
tail= head;
incompleat_noad= null;
}

/*:6*//*7:*/
#line 186 "./luatexdir/tex/texmath.w"

#define MATHFONTSTACK  8
#define MATHFONTDEFAULT 0       

static sa_tree math_fam_head= NULL;

/*:7*//*8:*/
#line 192 "./luatexdir/tex/texmath.w"

int fam_fnt(int fam_id,int size_id)
{
int n= fam_id+(256*size_id);
return(int)get_sa_item(math_fam_head,n).int_value;
}

void def_fam_fnt(int fam_id,int size_id,int f,int lvl)
{
int n= fam_id+(256*size_id);
sa_tree_item sa_value= {0};
sa_value.int_value= f;
set_sa_item(math_fam_head,n,sa_value,lvl);
fixup_math_parameters(fam_id,size_id,f,lvl);
if(int_par(tracing_assigns_code)> 1){
begin_diagnostic();
tprint("{assigning");
print_char(' ');
print_cmd_chr(def_family_cmd,size_id);
print_int(fam_id);
print_char('=');
print_font_identifier(fam_fnt(fam_id,size_id));
print_char('}');
end_diagnostic(false);
}
}

/*:8*//*9:*/
#line 219 "./luatexdir/tex/texmath.w"

static void unsave_math_fam_data(int gl)
{
sa_stack_item st;
if(math_fam_head->stack==NULL)
return;
while(math_fam_head->stack_ptr> 0&&
abs(math_fam_head->stack[math_fam_head->stack_ptr].level)
>=(int)gl){
st= math_fam_head->stack[math_fam_head->stack_ptr];
if(st.level> 0){
rawset_sa_item(math_fam_head,st.code,st.value);

if(int_par(tracing_restores_code)> 1){
int size_id= st.code/256;
int fam_id= st.code%256;
begin_diagnostic();
tprint("{restoring");
print_char(' ');
print_cmd_chr(def_family_cmd,size_id);
print_int(fam_id);
print_char('=');
print_font_identifier(fam_fnt(fam_id,size_id));
print_char('}');
end_diagnostic(false);
}
}
(math_fam_head->stack_ptr)--;
}
}

/*:9*//*10:*/
#line 252 "./luatexdir/tex/texmath.w"

#define MATHPARAMSTACK  8
#define MATHPARAMDEFAULT undefined_math_parameter

static sa_tree math_param_head= NULL;

/*:10*//*11:*/
#line 258 "./luatexdir/tex/texmath.w"

void def_math_param(int param_id,int style_id,scaled value,int lvl)
{
int n= param_id+(256*style_id);
sa_tree_item sa_value= {0};
sa_value.int_value= (int)value;
set_sa_item(math_param_head,n,sa_value,lvl);
if(int_par(tracing_assigns_code)> 1){
begin_diagnostic();
tprint("{assigning");
print_char(' ');
print_cmd_chr(set_math_param_cmd,param_id);
print_cmd_chr(math_style_cmd,style_id);
print_char('=');
print_int(value);
print_char('}');
end_diagnostic(false);
}
}

scaled get_math_param(int param_id,int style_id)
{
int n= param_id+(256*style_id);
return(scaled)get_sa_item(math_param_head,n).int_value;
}

/*:11*//*12:*/
#line 284 "./luatexdir/tex/texmath.w"

static void unsave_math_param_data(int gl)
{
sa_stack_item st;
if(math_param_head->stack==NULL)
return;
while(math_param_head->stack_ptr> 0&&
abs(math_param_head->stack[math_param_head->stack_ptr].level)
>=(int)gl){
st= math_param_head->stack[math_param_head->stack_ptr];
if(st.level> 0){
rawset_sa_item(math_param_head,st.code,st.value);

if(int_par(tracing_restores_code)> 1){
int param_id= st.code%256;
int style_id= st.code/256;
begin_diagnostic();
tprint("{restoring");
print_char(' ');
print_cmd_chr(set_math_param_cmd,param_id);
print_cmd_chr(math_style_cmd,style_id);
print_char('=');
print_int(get_math_param(param_id,style_id));
print_char('}');
end_diagnostic(false);
}
}
(math_param_head->stack_ptr)--;
}
}

/*:12*//*13:*/
#line 317 "./luatexdir/tex/texmath.w"

void unsave_math_data(int gl)
{
unsave_math_fam_data(gl);
unsave_math_param_data(gl);
}

/*:13*//*14:*/
#line 325 "./luatexdir/tex/texmath.w"

void dump_math_data(void)
{
sa_tree_item sa_value= {0};
if(math_fam_head==NULL){
sa_value.int_value= MATHFONTDEFAULT;
math_fam_head= new_sa_tree(MATHFONTSTACK,1,sa_value);
}
dump_sa_tree(math_fam_head,"mathfonts");
if(math_param_head==NULL){
sa_value.int_value= MATHPARAMDEFAULT;
math_param_head= new_sa_tree(MATHPARAMSTACK,1,sa_value);
}
dump_sa_tree(math_param_head,"mathparameters");
}

void undump_math_data(void)
{
math_fam_head= undump_sa_tree("mathfonts");
math_param_head= undump_sa_tree("mathparameters");
}

/*:14*//*15:*/
#line 347 "./luatexdir/tex/texmath.w"

void initialize_math(void)
{
sa_tree_item sa_value= {0};
if(math_fam_head==NULL){
sa_value.int_value= MATHFONTDEFAULT;
math_fam_head= new_sa_tree(MATHFONTSTACK,1,sa_value);
}
if(math_param_head==NULL){
sa_value.int_value= MATHPARAMDEFAULT;
math_param_head= new_sa_tree(MATHPARAMSTACK,1,sa_value);
initialize_math_spacing();
}
return;
}

/*:15*//*17:*/
#line 409 "./luatexdir/tex/texmath.w"

pointer new_noad(void)
{
pointer p;
p= new_node(simple_noad,ord_noad_type);

return p;
}

/*:17*//*18:*/
#line 418 "./luatexdir/tex/texmath.w"

pointer new_sub_box(pointer curbox)
{
pointer p,q;
p= new_noad();
q= new_node(sub_box_node,0);
nucleus(p)= q;
math_list(nucleus(p))= curbox;
return p;
}

/*:18*//*20:*/
#line 462 "./luatexdir/tex/texmath.w"

const char*math_style_names[]= {
"display","crampeddisplay",
"text","crampedtext",
"script","crampedscript",
"scriptscript","crampedscriptscript",
NULL
};

const char*math_param_names[]= {
"quad","axis","operatorsize",
"overbarkern","overbarrule","overbarvgap",
"underbarkern","underbarrule","underbarvgap",
"radicalkern","radicalrule","radicalvgap",
"radicaldegreebefore","radicaldegreeafter","radicaldegreeraise",
"stackvgap","stacknumup","stackdenomdown",
"fractionrule","fractionnumvgap","fractionnumup",
"fractiondenomvgap","fractiondenomdown","fractiondelsize",
"limitabovevgap","limitabovebgap","limitabovekern",
"limitbelowvgap","limitbelowbgap","limitbelowkern",
"underdelimitervgap","underdelimiterbgap",
"overdelimitervgap","overdelimiterbgap",
"subshiftdrop","supshiftdrop","subshiftdown",
"subsupshiftdown","subtopmax","supshiftup",
"supbottommin","supsubbottommax","subsupvgap",
"spaceafterscript","connectoroverlapmin",
"ordordspacing","ordopspacing","ordbinspacing","ordrelspacing",
"ordopenspacing","ordclosespacing","ordpunctspacing","ordinnerspacing",
"opordspacing","opopspacing","opbinspacing","oprelspacing",
"opopenspacing","opclosespacing","oppunctspacing","opinnerspacing",
"binordspacing","binopspacing","binbinspacing","binrelspacing",
"binopenspacing","binclosespacing","binpunctspacing","bininnerspacing",
"relordspacing","relopspacing","relbinspacing","relrelspacing",
"relopenspacing","relclosespacing","relpunctspacing","relinnerspacing",
"openordspacing","openopspacing","openbinspacing","openrelspacing",
"openopenspacing","openclosespacing","openpunctspacing",
"openinnerspacing",
"closeordspacing","closeopspacing","closebinspacing","closerelspacing",
"closeopenspacing","closeclosespacing","closepunctspacing",
"closeinnerspacing",
"punctordspacing","punctopspacing","punctbinspacing","punctrelspacing",
"punctopenspacing","punctclosespacing","punctpunctspacing",
"punctinnerspacing",
"innerordspacing","inneropspacing","innerbinspacing","innerrelspacing",
"inneropenspacing","innerclosespacing","innerpunctspacing",
"innerinnerspacing",
NULL
};

/*:20*//*21:*/
#line 511 "./luatexdir/tex/texmath.w"

pointer new_style(small_number s)
{
m_style= s;
return new_node(style_node,s);
}

/*:21*//*22:*/
#line 522 "./luatexdir/tex/texmath.w"

static pointer new_choice(void)
{
return new_node(choice_node,0);
}

/*:22*//*23:*/
#line 543 "./luatexdir/tex/texmath.w"

void display_normal_noad(pointer p);
void display_fence_noad(pointer p);
void display_fraction_noad(pointer p);

void show_math_node(pointer p)
{
switch(type(p)){
case style_node:
print_cmd_chr(math_style_cmd,subtype(p));
break;
case choice_node:
tprint_esc("mathchoice");
append_char('D');
show_node_list(display_mlist(p));
flush_char();
append_char('T');
show_node_list(text_mlist(p));
flush_char();
append_char('S');
show_node_list(script_mlist(p));
flush_char();
append_char('s');
show_node_list(script_script_mlist(p));
flush_char();
break;
case simple_noad:
case radical_noad:
case accent_noad:
display_normal_noad(p);
break;
case fence_noad:
display_fence_noad(p);
break;
case fraction_noad:
display_fraction_noad(p);
break;
default:
tprint("Unknown node type!");
break;
}
}

/*:23*//*24:*/
#line 588 "./luatexdir/tex/texmath.w"

static void print_fam_and_char(pointer p)
{
tprint_esc("fam");
print_int(math_fam(p));
print_char(' ');
print(math_character(p));
}

/*:24*//*25:*/
#line 597 "./luatexdir/tex/texmath.w"

static void print_delimiter(pointer p)
{
int a;
if(delimiteroptionset(p)){
tprint(" [ ");
if(delimiteraxis(p))
tprint("axis ");
if(delimiternoaxis(p))
tprint("noaxis ");
if(delimiterexact(p))
tprint("exact ");
tprint("]");
}
if(delimiterheight(p)){
tprint("height=");
print_scaled(delimiterheight(p));
tprint(" ");
}
if(delimiterdepth(p)){
tprint("depth=");
print_scaled(delimiterdepth(p));
tprint(" ");
}
if(delimiterclass(p)){
tprint("class=");
print_int(delimiterclass(p));
tprint(" ");
}
if(small_fam(p)<0){
print_int(-1);
}else if(small_fam(p)<16&&large_fam(p)<16&&
small_char(p)<256&&large_char(p)<256){

a= small_fam(p)*256+small_char(p);
a= a*0x1000+large_fam(p)*256+large_char(p);
print_hex(a);
}else if((large_fam(p)==0&&large_char(p)==0)||
small_char(p)> 65535||large_char(p)> 65535){

print_hex(small_fam(p));
print_hex(small_char(p));
}
}

/*:25*//*26:*/
#line 649 "./luatexdir/tex/texmath.w"

static void print_subsidiary_data(pointer p,ASCII_code c)
{
if((int)cur_length>=depth_threshold){
if(p!=null)
tprint(" []");
}else{
append_char(c);
if(p!=null){
switch(type(p)){
case math_char_node:
print_ln();
print_current_string();
print_fam_and_char(p);
break;
case sub_box_node:
show_node_list(math_list(p));
break;
case sub_mlist_node:
if(math_list(p)==null){
print_ln();
print_current_string();
tprint("{}");
}else{
show_node_list(math_list(p));
}
break;
}
}
flush_char();
}
}

/*:26*//*27:*/
#line 682 "./luatexdir/tex/texmath.w"

void display_normal_noad(pointer p)
{
switch(type(p)){
case simple_noad:
switch(subtype(p)){
case ord_noad_type:
tprint_esc("mathord");
break;
case op_noad_type_normal:
case op_noad_type_limits:
case op_noad_type_no_limits:
tprint_esc("mathop");
if(subtype(p)==op_noad_type_limits)
tprint_esc("limits");
else if(subtype(p)==op_noad_type_no_limits)
tprint_esc("nolimits");
break;
case bin_noad_type:
tprint_esc("mathbin");
break;
case rel_noad_type:
tprint_esc("mathrel");
break;
case open_noad_type:
tprint_esc("mathopen");
break;
case close_noad_type:
tprint_esc("mathclose");
break;
case punct_noad_type:
tprint_esc("mathpunct");
break;
case inner_noad_type:
tprint_esc("mathinner");
break;
case over_noad_type:
tprint_esc("overline");
break;
case under_noad_type:
tprint_esc("underline");
break;
case vcenter_noad_type:
tprint_esc("vcenter");
break;
default:
tprint("<unknown noad type!>");
break;
}
break;
case radical_noad:
if(subtype(p)==6)
tprint_esc("Udelimiterover");
else if(subtype(p)==5)
tprint_esc("Udelimiterunder");
else if(subtype(p)==4)
tprint_esc("Uoverdelimiter");
else if(subtype(p)==3)
tprint_esc("Uunderdelimiter");
else if(subtype(p)==2)
tprint_esc("Uroot");
else
tprint_esc("radical");
print_delimiter(left_delimiter(p));
if(degree(p)!=null){
print_subsidiary_data(degree(p),'/');
}
if(radicalwidth(p)){
tprint("width=");
print_scaled(radicalwidth(p));
tprint(" ");
}
if(radicaloptionset(p)){
tprint(" [ ");
if(radicalexact(p))
tprint("exact ");
if(radicalleft(p))
tprint("left ");
if(radicalmiddle(p))
tprint("middle ");
if(radicalright(p))
tprint("right ");
tprint("]");
}
break;
case accent_noad:
if(top_accent_chr(p)!=null){
if(bot_accent_chr(p)!=null){
tprint_esc("Umathaccent both");
}else{
tprint_esc("Umathaccent");
}
}else if(bot_accent_chr(p)!=null){
tprint_esc("Umathaccent bottom");
}else{
tprint_esc("Umathaccent overlay");
}
if(accentfraction(p)){
tprint(" fraction=");
print_int(accentfraction(p));
tprint(" ");
}
switch(subtype(p)){
case 0:
if(top_accent_chr(p)!=null){
if(bot_accent_chr(p)!=null){
print_fam_and_char(top_accent_chr(p));
print_fam_and_char(bot_accent_chr(p));
}else{
print_fam_and_char(top_accent_chr(p));
}
}else if(bot_accent_chr(p)!=null){
print_fam_and_char(bot_accent_chr(p));
}else{
print_fam_and_char(overlay_accent_chr(p));
}
break;
case 1:
if(top_accent_chr(p)!=null){
tprint(" fixed ");
print_fam_and_char(top_accent_chr(p));
if(bot_accent_chr(p)!=null){
print_fam_and_char(bot_accent_chr(p));
}
}else{
confusion("display_accent_noad");
}
break;
case 2:
if(bot_accent_chr(p)!=null){
if(top_accent_chr(p)!=null){
print_fam_and_char(top_accent_chr(p));
}
tprint(" fixed ");
print_fam_and_char(bot_accent_chr(p));
}else{
confusion("display_accent_noad");
}
break;
case 3:
if(top_accent_chr(p)!=null&&bot_accent_chr(p)!=null){
tprint(" fixed ");
print_fam_and_char(top_accent_chr(p));
tprint(" fixed ");
print_fam_and_char(bot_accent_chr(p));
}else{
confusion("display_accent_noad");
}
break;
}
break;
}
print_subsidiary_data(nucleus(p),'.');
print_subsidiary_data(supscr(p),'^');
print_subsidiary_data(subscr(p),'_');
}

/*:27*//*28:*/
#line 839 "./luatexdir/tex/texmath.w"

void display_fence_noad(pointer p)
{
if(subtype(p)==right_noad_side)
tprint_esc("right");
else if(subtype(p)==left_noad_side)
tprint_esc("left");
else
tprint_esc("middle");
print_delimiter(delimiter(p));
}

/*:28*//*29:*/
#line 851 "./luatexdir/tex/texmath.w"

void display_fraction_noad(pointer p)
{
tprint_esc("fraction, thickness ");
if(thickness(p)==default_code)
tprint("= default");
else
print_scaled(thickness(p));
if((left_delimiter(p)!=null)&&
((small_fam(left_delimiter(p))!=0)||
(small_char(left_delimiter(p))!=0)||
(large_fam(left_delimiter(p))!=0)||
(large_char(left_delimiter(p))!=0))){
tprint(", left-delimiter ");
print_delimiter(left_delimiter(p));
}
if((right_delimiter(p)!=null)&&
((small_fam(right_delimiter(p))!=0)||
(small_char(right_delimiter(p))!=0)||
(large_fam(right_delimiter(p))!=0)||
(large_char(right_delimiter(p))!=0))){
tprint(", right-delimiter ");
print_delimiter(right_delimiter(p));
}
print_subsidiary_data(numerator(p),'\\');
print_subsidiary_data(denominator(p),'/');
}

/*:29*//*30:*/
#line 888 "./luatexdir/tex/texmath.w"

static void new_save_level_math(group_code c)
{
set_saved_record(0,saved_textdir,0,text_dir_ptr);
text_dir_ptr= new_dir(math_direction);
incr(save_ptr);
new_save_level(c);
eq_word_define(int_base+body_direction_code,math_direction);
eq_word_define(int_base+par_direction_code,math_direction);
eq_word_define(int_base+text_direction_code,math_direction);
}

/*:30*//*31:*/
#line 900 "./luatexdir/tex/texmath.w"

static void push_math(group_code c,int mstyle)
{
if(math_direction!=text_direction)
dir_math_save= true;
push_nest();
mode= -mmode;
incompleat_noad= null;
m_style= mstyle;
new_save_level_math(c);
}

/*:31*//*32:*/
#line 912 "./luatexdir/tex/texmath.w"

static void enter_ordinary_math(void)
{
push_math(math_shift_group,text_style);
eq_word_define(int_base+cur_fam_code,-1);
if(every_math!=null)
begin_token_list(every_math,every_math_text);
}

/*:32*//*33:*/
#line 921 "./luatexdir/tex/texmath.w"

void enter_display_math(void);

/*:33*//*34:*/
#line 929 "./luatexdir/tex/texmath.w"

void init_math(void)
{
if(cur_cmd==math_shift_cmd){
get_token();
if((cur_cmd==math_shift_cmd)&&(mode> 0)){
enter_display_math();
}else{
back_input();
enter_ordinary_math();
}
}else if(cur_cmd==math_shift_cs_cmd&&cur_chr==display_style&&(mode> 0)){
enter_display_math();
}else if(cur_cmd==math_shift_cs_cmd&&cur_chr==text_style){
enter_ordinary_math();
}else{
you_cant();
}
}

/*:34*//*36:*/
#line 957 "./luatexdir/tex/texmath.w"

void start_eq_no(void)
{
set_saved_record(0,saved_eqno,0,cur_chr);
incr(save_ptr);
enter_ordinary_math();
}

/*:36*//*37:*/
#line 979 "./luatexdir/tex/texmath.w"

void math_left_brace(void)
{
pointer q;
tail_append(new_noad());
q= new_node(math_char_node,0);
nucleus(tail)= q;
back_input();
(void)scan_math(nucleus(tail),m_style);
}

/*:37*//*38:*/
#line 1001 "./luatexdir/tex/texmath.w"

static boolean math_and_text_reversed_p(void)
{
int i= save_ptr-1;
while(save_type(i)!=level_boundary)
i--;
while(i<save_ptr){
if(save_type(i)==restore_old_value&&
save_value(i)==int_base+par_direction_code){
if(textdir_opposite(math_direction,save_value(i-1)))
return true;
}
i++;
}
return false;
}

/*:38*//*39:*/
#line 1023 "./luatexdir/tex/texmath.w"

void enter_display_math(void)
{
scaled w;
scaled l;
scaled s;
pointer p;
int n;
if(head==tail||
(vlink(head)==tail&&
type(tail)==local_par_node&&vlink(tail)==null)){
if(vlink(head)==tail){



flush_node(tail);
}
pop_nest();
w= -max_dimen;
}else{
line_break(true,math_shift_group);
w= actual_box_width(just_box,(2*quad(get_cur_font())));
}



if(par_shape_ptr==null){
if((hang_indent!=0)&&
(((hang_after>=0)&&(prev_graf+2> hang_after))||
(prev_graf+1<-hang_after))){
l= hsize-abs(hang_indent);
if(hang_indent> 0)
s= hang_indent;
else
s= 0;
}else{
l= hsize;
s= 0;
}
}else{
n= vinfo(par_shape_ptr+1);
if(prev_graf+2>=n)
p= par_shape_ptr+2*n+1;
else
p= par_shape_ptr+2*(prev_graf+2)+1;
s= varmem[(p-1)].cint;
l= varmem[p].cint;
}

push_math(math_shift_group,display_style);
mode= mmode;
eq_word_define(int_base+cur_fam_code,-1);
eq_word_define(dimen_base+pre_display_size_code,w);
eq_word_define(dimen_base+display_width_code,l);
eq_word_define(dimen_base+display_indent_code,s);
eq_word_define(int_base+pre_display_direction_code,(math_and_text_reversed_p()?-1:0));
if(every_display!=null)
begin_token_list(every_display,every_display_text);
if(nest_ptr==1){
if(!output_active)
lua_node_filter_s(buildpage_filter_callback,lua_key_index(before_display));
build_page();
}
}

/*:39*//*40:*/
#line 1093 "./luatexdir/tex/texmath.w"

#define fam_in_range ((cur_fam>=0)&&(cur_fam<256))

static delcodeval do_scan_extdef_del_code(int extcode,boolean doclass)
{
const char*hlp[]= {
"I'm going to use 0 instead of that illegal code value.",
NULL
};
delcodeval d;
int mcls= 0,msfam= 0,mschr= 0,mlfam= 0,mlchr= 0;
if(extcode==tex_mathcode){
scan_int();

if(doclass){
mcls= (cur_val/0x1000000);
cur_val= (cur_val&0xFFFFFF);
}
if(cur_val> 0xFFFFFF){
tex_error("Invalid delimiter code",hlp);
cur_val= 0;
}
msfam= (cur_val/0x100000);
mschr= (cur_val%0x100000)/0x1000;
mlfam= (cur_val&0xFFF)/0x100;
mlchr= (cur_val%0x100);
}else if(extcode==umath_mathcode){

if(doclass){
scan_int();
mcls= cur_val;
}
scan_int();
msfam= cur_val;
scan_char_num();
mschr= cur_val;
if(msfam<0||msfam> 255){
tex_error("Invalid delimiter code",hlp);
msfam= 0;
mschr= 0;
}
mlfam= 0;
mlchr= 0;
}else if(extcode==umathnum_mathcode){




if(doclass){
confusion("umathnum_mathcode");
}
scan_int();
msfam= (cur_val/0x200000);
mschr= cur_val&0x1FFFFF;
if(msfam<0||msfam> 255||mschr> 0x10FFFF){
tex_error("Invalid delimiter code",hlp);
msfam= 0;
mschr= 0;
}
mlfam= 0;
mlchr= 0;
}else{

confusion("unknown_extcode");
}
d.class_value= mcls;
d.small_family_value= msfam;
d.small_character_value= mschr;
d.large_family_value= mlfam;
d.large_character_value= mlchr;
return d;
}

/*:40*//*41:*/
#line 1166 "./luatexdir/tex/texmath.w"

void scan_extdef_del_code(int level,int extcode)
{
delcodeval d;
int p;
scan_char_num();
p= cur_val;
scan_optional_equals();
d= do_scan_extdef_del_code(extcode,false);
set_del_code(p,d.small_family_value,d.small_character_value,
d.large_family_value,d.large_character_value,
(quarterword)(level));
}

/*:41*//*42:*/
#line 1180 "./luatexdir/tex/texmath.w"

mathcodeval scan_mathchar(int extcode)
{
char errstr[255]= {0};
const char*hlp[]= {
"I'm going to use 0 instead of that illegal code value.",
NULL
};
mathcodeval d;
int mcls= 0,mfam= 0,mchr= 0;
if(extcode==tex_mathcode){

scan_int();
if(cur_val> 0x8000){





mfam= (cur_val/0x200000)&0x7FF;
mcls= mfam%0x08;
mfam= mfam/0x08;
mchr= cur_val&0x1FFFFF;
if(mchr> 0x10FFFF){
tex_error("Invalid math code during > 0x8000 mathcode fallback",hlp);
mcls= 0;
mfam= 0;
mchr= 0;
}
}else{
if(cur_val<0){
snprintf(errstr,255,"Bad mathchar (%d)",(int)cur_val);
tex_error(errstr,hlp);
cur_val= 0;
}
mcls= (cur_val/0x1000);
mfam= ((cur_val%0x1000)/0x100);
mchr= (cur_val%0x100);
}
}else if(extcode==umath_mathcode){

scan_int();
mcls= cur_val;
scan_int();
mfam= cur_val;
scan_char_num();
mchr= cur_val;
if(mcls<0||mcls> 7||mfam> 255){
tex_error("Invalid math code",hlp);
mchr= 0;
mfam= 0;
mcls= 0;
}
}else if(extcode==umathnum_mathcode){





scan_int();
mfam= (cur_val/0x200000)&0x7FF;
mcls= mfam%0x08;
mfam= mfam/0x08;
mchr= cur_val&0x1FFFFF;
if(mchr> 0x10FFFF){
tex_error("Invalid math code",hlp);
mcls= 0;
mfam= 0;
mchr= 0;
}
}else{

confusion("unknown_extcode");
}
d.class_value= mcls;
d.family_value= mfam;
d.character_value= mchr;
return d;
}

/*:42*//*43:*/
#line 1260 "./luatexdir/tex/texmath.w"

void scan_extdef_math_code(int level,int extcode)
{
mathcodeval d;
int p;
scan_char_num();
p= cur_val;
scan_optional_equals();
d= scan_mathchar(extcode);
set_math_code(p,d.class_value,
d.family_value,d.character_value,(quarterword)(level));
}

/*:43*//*44:*/
#line 1274 "./luatexdir/tex/texmath.w"

mathcodeval scan_delimiter_as_mathchar(int extcode)
{
delcodeval dval;
mathcodeval mval;
dval= do_scan_extdef_del_code(extcode,true);
mval.class_value= dval.class_value;
mval.family_value= dval.small_family_value;
mval.character_value= dval.small_character_value;
return mval;
}

/*:44*//*45:*/
#line 1293 "./luatexdir/tex/texmath.w"

#define get_next_nb_nr() do { get_x_token(); } while (cur_cmd==spacer_cmd||cur_cmd==relax_cmd)

int scan_math_style(pointer p,int mstyle)
{
get_next_nb_nr();
back_input();
scan_left_brace();
set_saved_record(0,saved_math,0,p);
incr(save_ptr);
push_math(math_group,mstyle);
return 1;
}

int scan_math(pointer p,int mstyle)
{

mathcodeval mval= {0,0,0};
assert(p!=null);
RESTART:
get_next_nb_nr();
RESWITCH:
switch(cur_cmd){
case letter_cmd:
case other_char_cmd:
case char_given_cmd:
mval= get_math_code(cur_chr);
if(mval.class_value==8){

cur_cs= active_to_cs(cur_chr,true);
cur_cmd= eq_type(cur_cs);
cur_chr= equiv(cur_cs);
x_token();
back_input();
goto RESTART;
}
break;
case char_num_cmd:
scan_char_num();
cur_chr= cur_val;
cur_cmd= char_given_cmd;
goto RESWITCH;
break;
case math_char_num_cmd:
if(cur_chr==0)
mval= scan_mathchar(tex_mathcode);
else if(cur_chr==1)
mval= scan_mathchar(umath_mathcode);
else if(cur_chr==2)
mval= scan_mathchar(umathnum_mathcode);
else
confusion("scan_math");
break;
case math_given_cmd:
mval= mathchar_from_integer(cur_chr,tex_mathcode);
break;
case xmath_given_cmd:
mval= mathchar_from_integer(cur_chr,umath_mathcode);
break;
case delim_num_cmd:
if(cur_chr==0)
mval= scan_delimiter_as_mathchar(tex_mathcode);
else if(cur_chr==1)
mval= scan_delimiter_as_mathchar(umath_mathcode);
else
confusion("scan_math");
break;
default:


back_input();
scan_left_brace();
set_saved_record(0,saved_math,0,p);
incr(save_ptr);
push_math(math_group,mstyle);
return 1;
}
type(p)= math_char_node;
math_character(p)= mval.character_value;
if((mval.class_value==var_code)&&fam_in_range)
math_fam(p)= cur_fam;
else
math_fam(p)= mval.family_value;
return 0;
}

/*:45*//*46:*/
#line 1384 "./luatexdir/tex/texmath.w"

void set_math_char(mathcodeval mval)
{
pointer p;
if(mval.class_value==8){

cur_cs= active_to_cs(cur_chr,true);
cur_cmd= eq_type(cur_cs);
cur_chr= equiv(cur_cs);
x_token();
back_input();
}else{
pointer q;
p= new_noad();
q= new_node(math_char_node,0);
nucleus(p)= q;
math_character(nucleus(p))= mval.character_value;
math_fam(nucleus(p))= mval.family_value;
if(mval.class_value==var_code){
if(fam_in_range)
math_fam(nucleus(p))= cur_fam;
subtype(p)= ord_noad_type;
}else{
switch(mval.class_value){

case 0:subtype(p)= ord_noad_type;break;
case 1:subtype(p)= op_noad_type_normal;break;
case 2:subtype(p)= bin_noad_type;break;
case 3:subtype(p)= rel_noad_type;break;
case 4:subtype(p)= open_noad_type;break;
case 5:subtype(p)= close_noad_type;break;
case 6:subtype(p)= punct_noad_type;break;

}
}
vlink(tail)= p;
tail= p;
}
}

/*:46*//*47:*/
#line 1429 "./luatexdir/tex/texmath.w"

void math_char_in_text(mathcodeval mval)
{
pointer p;
if(mval.class_value==8){

cur_cs= active_to_cs(cur_chr,true);
cur_cmd= eq_type(cur_cs);
cur_chr= equiv(cur_cs);
x_token();
back_input();
}else{
p= new_char(fam_fnt(mval.family_value,text_size),mval.character_value);
vlink(tail)= p;
tail= p;
}
}

/*:47*//*48:*/
#line 1447 "./luatexdir/tex/texmath.w"

void math_math_comp(void)
{
pointer q;
tail_append(new_noad());
subtype(tail)= (quarterword)cur_chr;
q= new_node(math_char_node,0);
nucleus(tail)= q;
if(cur_chr==over_noad_type)
(void)scan_math(nucleus(tail),cramped_style(m_style));
else
(void)scan_math(nucleus(tail),m_style);
}

/*:48*//*49:*/
#line 1461 "./luatexdir/tex/texmath.w"

void math_limit_switch(void)
{
const char*hlp[]= {
"I'm ignoring this misplaced \\limits or \\nolimits command.",
NULL
};
if(head!=tail){
if(type(tail)==simple_noad&&
(subtype(tail)==op_noad_type_normal||
subtype(tail)==op_noad_type_limits||
subtype(tail)==op_noad_type_no_limits)){
subtype(tail)= (quarterword)cur_chr;
return;
}
}
tex_error("Limit controls must follow a math operator",hlp);
}

/*:49*//*50:*/
#line 1485 "./luatexdir/tex/texmath.w"

static void scan_delimiter(pointer p,int r)
{
delcodeval dval= {0,0,0,0,0};
if(r==tex_mathcode){
dval= do_scan_extdef_del_code(tex_mathcode,true);
}else if(r==umath_mathcode){
dval= do_scan_extdef_del_code(umath_mathcode,false);
}else if(r==no_mathcode){
get_next_nb_nr();
switch(cur_cmd){
case letter_cmd:
case other_char_cmd:
dval= get_del_code(cur_chr);
break;
case delim_num_cmd:
if(cur_chr==0)
dval= do_scan_extdef_del_code(tex_mathcode,true);
else if(cur_chr==1)
dval= do_scan_extdef_del_code(umath_mathcode,true);
else
confusion("scan_delimiter1");
break;
default:
dval.small_family_value= -1;
break;
}
}else{
confusion("scan_delimiter2");
}
if(p==null)
return;
if(dval.small_family_value<0){
const char*hlp[]= {
"I was expecting to see something like `(' or `\\{' or",
"`\\}' here. If you typed, e.g., `{' instead of `\\{', you",
"should probably delete the `{' by typing `1' now, so that",
"braces don't get unbalanced. Otherwise just proceed",
"Acceptable delimiters are characters whose \\delcode is",
"nonnegative, or you can use `\\delimiter <delimiter code>'.",
NULL
};
back_error("Missing delimiter (. inserted)",hlp);
small_fam(p)= 0;
small_char(p)= 0;
large_fam(p)= 0;
large_char(p)= 0;
}else{
small_fam(p)= dval.small_family_value;
small_char(p)= dval.small_character_value;
large_fam(p)= dval.large_family_value;
large_char(p)= dval.large_character_value;
}
return;
}

/*:50*//*51:*/
#line 1541 "./luatexdir/tex/texmath.w"

void math_radical(void)
{
halfword q;
int chr_code= cur_chr;
halfword options= 0;
tail_append(new_node(radical_noad,chr_code));
q= new_node(delim_node,0);
left_delimiter(tail)= q;
while(1){
if(scan_keyword("width")){
scan_dimen(false,false,false);
radicalwidth(tail)= cur_val;
}else if(scan_keyword("left")){
options= options|noad_option_left;
}else if(scan_keyword("middle")){
options= options|noad_option_middle;
}else if(scan_keyword("right")){
options= options|noad_option_right;
}else{
break;
}
}
radicaloptions(tail)= options;
if(chr_code==0)
scan_delimiter(left_delimiter(tail),tex_mathcode);
else if(chr_code==1)
scan_delimiter(left_delimiter(tail),umath_mathcode);
else if(chr_code==2)
scan_delimiter(left_delimiter(tail),umath_mathcode);
else if(chr_code==3)
scan_delimiter(left_delimiter(tail),umath_mathcode);
else if(chr_code==4)
scan_delimiter(left_delimiter(tail),umath_mathcode);
else if(chr_code==5)
scan_delimiter(left_delimiter(tail),umath_mathcode);
else if(chr_code==6)
scan_delimiter(left_delimiter(tail),umath_mathcode);
else if(chr_code==7)
scan_delimiter(left_delimiter(tail),umath_mathcode);
else
confusion("math_radical");
if(chr_code==7){
q= new_node(sub_box_node,0);
nucleus(tail)= q;
return;
}else if(chr_code==2){


q= new_node(math_char_node,0);
vlink(q)= tail;
degree(tail)= q;
if(!scan_math(degree(tail),sup_sup_style(m_style))){
vlink(degree(tail))= null;
q= new_node(math_char_node,0);
nucleus(tail)= q;
(void)scan_math(nucleus(tail),cramped_style(m_style));
}
}else{
q= new_node(math_char_node,0);
nucleus(tail)= q;
(void)scan_math(nucleus(tail),cramped_style(m_style));
}
}

/*:51*//*52:*/
#line 1606 "./luatexdir/tex/texmath.w"

void math_ac(void)
{
halfword q;
mathcodeval t= {0,0,0};
mathcodeval b= {0,0,0};
mathcodeval o= {0,0,0};
if(cur_cmd==accent_cmd){
const char*hlp[]= {
"I'm changing \\accent to \\mathaccent here; wish me luck.",
"(Accents are not the same in formulas as they are in text.)",
NULL
};
tex_error("Please use \\mathaccent for accents in math mode",hlp);
}
tail_append(new_node(accent_noad,0));
if(cur_chr==0){
t= scan_mathchar(tex_mathcode);
}else if(cur_chr==1){
if(scan_keyword("fixed")){

subtype(tail)= 1;
t= scan_mathchar(umath_mathcode);
}else if(scan_keyword("both")){

if(scan_keyword("fixed")){
subtype(tail)= 1;
}
t= scan_mathchar(umath_mathcode);
if(scan_keyword("fixed")){
subtype(tail)+= 2;
}
b= scan_mathchar(umath_mathcode);
}else if(scan_keyword("bottom")){

if(scan_keyword("fixed")){
subtype(tail)= 2;
}
b= scan_mathchar(umath_mathcode);
}else if(scan_keyword("top")){

if(scan_keyword("fixed")){
subtype(tail)= 1;
}
t= scan_mathchar(umath_mathcode);
}else if(scan_keyword("overlay")){

if(scan_keyword("fixed")){
subtype(tail)= 1;
}
o= scan_mathchar(umath_mathcode);
}else{

t= scan_mathchar(umath_mathcode);
}
if(scan_keyword("fraction")){
scan_int();
accentfraction(tail)= cur_val;
}
}else{
confusion("mathaccent");
}
if(!(t.character_value==0&&t.family_value==0)){
q= new_node(math_char_node,0);
top_accent_chr(tail)= q;
math_character(top_accent_chr(tail))= t.character_value;
if((t.class_value==var_code)&&fam_in_range)
math_fam(top_accent_chr(tail))= cur_fam;
else
math_fam(top_accent_chr(tail))= t.family_value;
}
if(!(b.character_value==0&&b.family_value==0)){
q= new_node(math_char_node,0);
bot_accent_chr(tail)= q;
math_character(bot_accent_chr(tail))= b.character_value;
if((b.class_value==var_code)&&fam_in_range)
math_fam(bot_accent_chr(tail))= cur_fam;
else
math_fam(bot_accent_chr(tail))= b.family_value;
}
if(!(o.character_value==0&&o.family_value==0)){
q= new_node(math_char_node,0);
overlay_accent_chr(tail)= q;
math_character(overlay_accent_chr(tail))= o.character_value;
if((o.class_value==var_code)&&fam_in_range)
math_fam(overlay_accent_chr(tail))= cur_fam;
else
math_fam(overlay_accent_chr(tail))= o.family_value;
}
q= new_node(math_char_node,0);
nucleus(tail)= q;
(void)scan_math(nucleus(tail),cramped_style(m_style));
}

/*:52*//*53:*/
#line 1700 "./luatexdir/tex/texmath.w"

pointer math_vcenter_group(pointer p)
{
pointer q,r;
q= new_noad();
subtype(q)= vcenter_noad_type;
r= new_node(sub_box_node,0);
nucleus(q)= r;
math_list(nucleus(q))= p;
return q;
}

/*:53*//*54:*/
#line 1715 "./luatexdir/tex/texmath.w"

void append_choices(void)
{
tail_append(new_choice());
incr(save_ptr);
set_saved_record(-1,saved_choices,0,0);
push_math(math_choice_group,display_style);
scan_left_brace();
}

/*:54*//*55:*/
#line 1725 "./luatexdir/tex/texmath.w"

void build_choices(void)
{
pointer p;
int prev_style;
prev_style= m_style;
unsave_math();
p= fin_mlist(null);
assert(saved_type(-1)==saved_choices);
switch(saved_value(-1)){
case 0:
display_mlist(tail)= p;
break;
case 1:
text_mlist(tail)= p;
break;
case 2:
script_mlist(tail)= p;
break;
case 3:
script_script_mlist(tail)= p;
decr(save_ptr);
return;
break;
}
set_saved_record(-1,saved_choices,0,(saved_value(-1)+1));
push_math(math_choice_group,(prev_style+2));
scan_left_brace();
}

/*:55*//*56:*/
#line 1758 "./luatexdir/tex/texmath.w"

void sub_sup(void)
{
pointer q;
if(tail==head||(!scripts_allowed(tail))){
tail_append(new_noad());
q= new_node(sub_mlist_node,0);
nucleus(tail)= q;
}
if(cur_cmd==sup_mark_cmd||cur_chr==sup_mark_cmd){
if(supscr(tail)!=null){
const char*hlp[]= {
"I treat `x^1^2' essentially like `x^1{}^2'.",NULL
};
tail_append(new_noad());
q= new_node(sub_mlist_node,0);
nucleus(tail)= q;
tex_error("Double superscript",hlp);
}
q= new_node(math_char_node,0);
supscr(tail)= q;
(void)scan_math(supscr(tail),sup_style(m_style));
}else if(cur_cmd==sub_mark_cmd||cur_chr==sub_mark_cmd){
if(subscr(tail)!=null){
const char*hlp[]= {
"I treat `x_1_2' essentially like `x_1{}_2'.",NULL
};
tail_append(new_noad());
q= new_node(sub_mlist_node,0);
nucleus(tail)= q;
tex_error("Double subscript",hlp);
}
q= new_node(math_char_node,0);
subscr(tail)= q;
(void)scan_math(subscr(tail),sub_style(m_style));
}
}

/*:56*//*57:*/
#line 1804 "./luatexdir/tex/texmath.w"

void math_fraction(void)
{
halfword c;
pointer q;
halfword options= 0;
c= cur_chr;
if(incompleat_noad!=null){
const char*hlp[]= {
"I'm ignoring this fraction specification, since I don't",
"know whether a construction like `x \\over y \\over z'",
"means `{x \\over y} \\over z' or `x \\over {y \\over z}'.",
NULL
};
if(c>=delimited_code){
scan_delimiter(null,no_mathcode);
scan_delimiter(null,no_mathcode);
}
if((c%delimited_code)==above_code)
scan_normal_dimen();
tex_error("Ambiguous; you need another { and }",hlp);
}else{
incompleat_noad= new_node(fraction_noad,0);
numerator(incompleat_noad)= new_node(sub_mlist_node,0);
math_list(numerator(incompleat_noad))= vlink(head);
vlink(head)= null;
tail= head;
m_style= cramped_style(m_style);

if((c%delimited_code)==skewed_code){
q= new_node(delim_node,0);
middle_delimiter(incompleat_noad)= q;
scan_delimiter(middle_delimiter(incompleat_noad),no_mathcode);
}
if(c>=delimited_code){
q= new_node(delim_node,0);
left_delimiter(incompleat_noad)= q;
q= new_node(delim_node,0);
right_delimiter(incompleat_noad)= q;
scan_delimiter(left_delimiter(incompleat_noad),no_mathcode);
scan_delimiter(right_delimiter(incompleat_noad),no_mathcode);
}
switch(c%delimited_code){
case above_code:
while(1){
if(scan_keyword("exact")){
options= options|noad_option_exact;
}else{
break;
}
}
fractionoptions(incompleat_noad)= options;
scan_normal_dimen();
thickness(incompleat_noad)= cur_val;
break;
case over_code:
thickness(incompleat_noad)= default_code;
break;
case atop_code:
thickness(incompleat_noad)= 0;
break;
case skewed_code:
while(1){
if(scan_keyword("exact")){
options= options|noad_option_exact;
}else if(scan_keyword("noaxis")){
options= options|noad_option_no_axis;
}else{
break;
}
}
fractionoptions(incompleat_noad)= options;
thickness(incompleat_noad)= 0;
break;
}
}
}

/*:57*//*58:*/
#line 1888 "./luatexdir/tex/texmath.w"

pointer fin_mlist(pointer p)
{
pointer q;
if(incompleat_noad!=null){
if(denominator(incompleat_noad)!=null){
type(denominator(incompleat_noad))= sub_mlist_node;
}else{
q= new_node(sub_mlist_node,0);
denominator(incompleat_noad)= q;
}
math_list(denominator(incompleat_noad))= vlink(head);
if(p==null){
q= incompleat_noad;
}else{
q= math_list(numerator(incompleat_noad));
if((type(q)!=fence_noad)||(subtype(q)!=left_noad_side)
||(delim_ptr==null))
confusion("right");
math_list(numerator(incompleat_noad))= vlink(delim_ptr);
vlink(delim_ptr)= incompleat_noad;
vlink(incompleat_noad)= p;
}
}else{
vlink(tail)= p;
q= vlink(head);
}
pop_nest();
return q;
}

/*:58*//*59:*/
#line 1924 "./luatexdir/tex/texmath.w"

void close_math_group(pointer p)
{
int old_style= m_style;
unsave_math();

decr(save_ptr);
assert(saved_type(0)==saved_math);
type(saved_value(0))= sub_mlist_node;
p= fin_mlist(null);
math_list(saved_value(0))= p;
if(p!=null){
if(vlink(p)==null){
if(type(p)==simple_noad&&subtype(p)==ord_noad_type){
if(subscr(p)==null&&supscr(p)==null){
type(saved_value(0))= type(nucleus(p));
if(type(nucleus(p))==math_char_node){
math_fam(saved_value(0))= math_fam(nucleus(p));
math_character(saved_value(0))= 
math_character(nucleus(p));
}else{
math_list(saved_value(0))= math_list(nucleus(p));
math_list(nucleus(p))= null;
}
delete_attribute_ref(node_attr(saved_value(0)));
node_attr(saved_value(0))= node_attr(nucleus(p));
node_attr(nucleus(p))= null;
flush_node(p);
}
}else if(type(p)==accent_noad){
if(saved_value(0)==nucleus(tail)){
if(type(tail)==simple_noad
&&subtype(tail)==ord_noad_type){
pointer q= head;
while(vlink(q)!=tail)
q= vlink(q);
vlink(q)= p;
nucleus(tail)= null;
subscr(tail)= null;
supscr(tail)= null;
delete_attribute_ref(node_attr(p));
node_attr(p)= node_attr(tail);
node_attr(tail)= null;
flush_node(tail);
tail= p;
}
}
}
}
}
if(vlink(saved_value(0))> 0){
pointer q;
q= new_node(math_char_node,0);
nucleus(vlink(saved_value(0)))= q;
vlink(saved_value(0))= null;
saved_value(0)= q;
(void)scan_math(saved_value(0),old_style);

}
}

/*:59*//*60:*/
#line 1990 "./luatexdir/tex/texmath.w"

void math_left_right(void)
{
halfword t;
pointer p;
pointer q;
pointer r;
halfword ht= 0;
halfword dp= 0;
halfword options= 0;
halfword type= -1;
t= cur_chr;

if(t> 10){

t= t-10;
while(1){
if(scan_keyword("height")){
scan_dimen(false,false,false);
ht= cur_val;
}else if(scan_keyword("depth")){
scan_dimen(false,false,false);
dp= cur_val;
}else if(scan_keyword("axis")){
options= options|noad_option_axis;
}else if(scan_keyword("noaxis")){
options= options|noad_option_no_axis;
}else if(scan_keyword("exact")){
options= options|noad_option_exact;
}else if(scan_keyword("class")){
scan_int();
type= cur_val;
}else{
break;
}
}
}

if((t!=no_noad_side)&&(t!=left_noad_side)&&(cur_group!=math_left_group)){
if(cur_group==math_shift_group){
scan_delimiter(null,no_mathcode);
if(t==middle_noad_side){
const char*hlp[]= {
"I'm ignoring a \\middle that had no matching \\left.",
NULL
};
tex_error("Extra \\middle",hlp);
}else{
const char*hlp[]= {
"I'm ignoring a \\right that had no matching \\left.",
NULL
};
tex_error("Extra \\right",hlp);
}
}else{
off_save();
}
}else{
p= new_noad();
type(p)= fence_noad;
subtype(p)= (quarterword)t;
r= new_node(delim_node,0);
delimiter(p)= r;

delimiterheight(p)= ht;
delimiterdepth(p)= dp;
delimiteroptions(p)= options;
delimiterclass(p)= type;
delimiteritalic(p)= 0;

scan_delimiter(delimiter(p),no_mathcode);

if(t==no_noad_side){
tail_append(new_noad());
subtype(tail)= inner_noad_type;
r= new_node(sub_mlist_node,0);
nucleus(tail)= r;
math_list(nucleus(tail))= p;
return;
}

if(t==left_noad_side){
q= p;
}else{
q= fin_mlist(p);
unsave_math();
}
if(t!=right_noad_side){
push_math(math_left_group,m_style);
vlink(head)= q;
tail= p;
delim_ptr= p;
}else{
tail_append(new_noad());
subtype(tail)= inner_noad_type;
r= new_node(sub_mlist_node,0);
nucleus(tail)= r;
math_list(nucleus(tail))= q;
}
}
}

/*:60*//*61:*/
#line 2095 "./luatexdir/tex/texmath.w"

static void check_second_math_shift(void)
{
get_x_token();
if(cur_cmd!=math_shift_cmd){
const char*hlp[]= {
"The `$' that I just saw supposedly matches a previous `$$'.",
"So I shall assume that you typed `$$' both times.",
NULL
};
back_error("Display math should end with $$",hlp);
}
}

static void check_display_math_end(void)
{
if(cur_chr!=cramped_display_style){
const char*hlp[]= {
"I shall assume that you typed that.",
NULL
};
tex_error("Display math should end with \\Ustopdisplaymath",hlp);
}
}

static void check_inline_math_end(void)
{
if(cur_chr!=cramped_text_style){
const char*hlp[]= {
"I shall assume that you typed that.",
NULL
};
tex_error("Inline math should end with \\Ustopmath",hlp);
}
}

/*:61*//*62:*/
#line 2131 "./luatexdir/tex/texmath.w"

static void resume_after_display(void)
{
if(cur_group!=math_shift_group)
confusion("display");
unsave_math();
prev_graf= prev_graf+3;
push_nest();
mode= hmode;
space_factor= 1000;
tail_append(make_local_par_node());

get_x_token();
if(cur_cmd!=spacer_cmd)
back_input();
if(nest_ptr==1){
lua_node_filter_s(buildpage_filter_callback,lua_key_index(after_display));
build_page();
}
}

/*:62*//*63:*/
#line 2161 "./luatexdir/tex/texmath.w"

static void finish_displayed_math(boolean l,pointer eqno_box,pointer p)
{
pointer eq_box;
scaled eq_w;
scaled line_w;
scaled eqno_w;
scaled eqno_w2;
scaled line_s;
scaled d;
small_number g1,g2;
pointer r,s;
pointer t;
pointer pre_t;
boolean swap_dir;
scaled eqno_width;
swap_dir= (int_par(pre_display_direction_code)<0?true:false);
if(eqno_box!=null&&swap_dir)
l= !l;
adjust_tail= adjust_head;
pre_adjust_tail= pre_adjust_head;
eq_box= hpack(p,0,additional,-1);
subtype(eq_box)= equation_list;
build_attribute_list(eq_box);
p= list_ptr(eq_box);
t= adjust_tail;
adjust_tail= null;
pre_t= pre_adjust_tail;
pre_adjust_tail= null;
eq_w= width(eq_box);
line_w= display_width;
line_s= display_indent;
if(eqno_box==null){
eqno_w= 0;
eqno_width= 0;
eqno_w2= 0;
}else{
eqno_w= width(eqno_box);
eqno_width= eqno_w;
eqno_w2= eqno_w+round_xn_over_d(math_eqno_gap_step,get_math_quad(text_size),1000);
subtype(eqno_box)= equation_number_list;

}
if(eq_w+eqno_w2> line_w){


if((eqno_w!=0)&&((eq_w-total_shrink[normal]+eqno_w2<=line_w)
||(total_shrink[sfi]!=0)
||(total_shrink[fil]!=0)
||(total_shrink[fill]!=0)
||(total_shrink[filll]!=0))){
list_ptr(eq_box)= null;
flush_node(eq_box);
eq_box= hpack(p,line_w-eqno_w2,exactly,-1);
subtype(eq_box)= equation_list;
build_attribute_list(eq_box);
}else{
eqno_w= 0;
if(eq_w> line_w){
list_ptr(eq_box)= null;
flush_node(eq_box);
eq_box= hpack(p,line_w,exactly,-1);
subtype(eq_box)= equation_list;
build_attribute_list(eq_box);
}
}
eq_w= width(eq_box);
}








d= half(line_w-eq_w);
if((eqno_w> 0)&&(d<2*eqno_w)){
d= half(line_w-eq_w-eqno_w);
if(p!=null)
if(!is_char_node(p))
if(type(p)==glue_node)
d= 0;
}

tail_append(new_penalty(int_par(pre_display_penalty_code)));
if((d+line_s<=pre_display_size)||l){
g1= above_display_skip_code;
g2= below_display_skip_code;
}else{
g1= above_display_short_skip_code;
g2= below_display_short_skip_code;
}










if(eqno_box&&l&&(eqno_w==0)){

shift_amount(eqno_box)= 0;


append_to_vlist(eqno_box,lua_key_index(equation_number));
tail_append(new_penalty(inf_penalty));
}else{
switch(display_skip_mode){
case 0:
tail_append(new_param_glue(g1));
break;
case 1:
tail_append(new_param_glue(g1));
break;
case 2:
if(g1!=0)
tail_append(new_param_glue(g1));
break;
case 3:
break;
}
}

if(eqno_w!=0){
r= new_kern(line_w-eq_w-eqno_w-d);
if(l){
if(swap_dir){
if(math_direction==dir_TLT){

#ifdef DEBUG
fprintf(stderr,"\nDEBUG: CASE 1\n");
#endif
s= new_kern(width(r)+eqno_w);
try_couple_nodes(eqno_box,r);
try_couple_nodes(r,eq_box);
try_couple_nodes(eq_box,s);
}else{

#ifdef DEBUG
fprintf(stderr,"\nDEBUG: CASE 2\n");
#endif
try_couple_nodes(eqno_box,r);
try_couple_nodes(r,eq_box);
}
}else{
if(math_direction==dir_TLT){

#ifdef DEBUG
fprintf(stderr,"\nDEBUG: CASE 3\n");
#endif
s= new_kern(width(r)+eqno_w);
}else{

#ifdef DEBUG
fprintf(stderr,"\nDEBUG: CASE 4\n");
#endif
s= new_kern(width(r));
}
try_couple_nodes(eqno_box,r);
try_couple_nodes(r,eq_box);
try_couple_nodes(eq_box,s);
}
eq_box= eqno_box;
}else{
if(swap_dir){
if(math_direction==dir_TLT){

#ifdef DEBUG
fprintf(stderr,"\nDEBUG: CASE 5\n");
#endif
}else{

#ifdef DEBUG
fprintf(stderr,"\nDEBUG: CASE 6\n");
#endif
}
try_couple_nodes(eq_box,r);
try_couple_nodes(r,eqno_box);
}else{
if(math_direction==dir_TLT){

#ifdef DEBUG
fprintf(stderr,"\nDEBUG: CASE 7\n");
#endif
s= new_kern(d);
}else{

#ifdef DEBUG
fprintf(stderr,"\nDEBUG: CASE 8\n");
#endif
s= new_kern(width(r)+eqno_w);
}
try_couple_nodes(s,eq_box);
try_couple_nodes(eq_box,r);
try_couple_nodes(r,eqno_box);
eq_box= s;
}
}
eq_box= hpack(eq_box,0,additional,-1);
subtype(eq_box)= equation_list;
build_attribute_list(eq_box);
shift_amount(eq_box)= line_s;
}else{
shift_amount(eq_box)= line_s+d;
}

append_to_vlist(eq_box,lua_key_index(equation));

if((eqno_box!=null)&&(eqno_w==0)&&!l){
tail_append(new_penalty(inf_penalty));

shift_amount(eqno_box)= line_s+line_w-eqno_width;


append_to_vlist(eqno_box,lua_key_index(equation_number));
g2= 0;
}
if(t!=adjust_head){
vlink(tail)= vlink(adjust_head);

alink(adjust_tail)= alink(tail);
tail= t;
}
if(pre_t!=pre_adjust_head){
vlink(tail)= vlink(pre_adjust_head);

alink(pre_adjust_tail)= alink(tail);
tail= pre_t;
}
tail_append(new_penalty(int_par(post_display_penalty_code)));

switch(display_skip_mode){
case 0:
if(g2> 0)
tail_append(new_param_glue(g2));
break;
case 1:
tail_append(new_param_glue(g2));
break;
case 2:
if(g2!=0)
tail_append(new_param_glue(g2));
break;
case 3:
break;
}

resume_after_display();
}

/*:63*//*64:*/
#line 2415 "./luatexdir/tex/texmath.w"

void after_math(void)
{
int m;
pointer p;
pointer a= null;
boolean l= false;
m= mode;
p= fin_mlist(null);
if(cur_cmd==math_shift_cs_cmd&&
(cur_chr==text_style||cur_chr==display_style)){
you_cant();
}
if(mode==-m){
if(cur_cmd==math_shift_cmd){
check_second_math_shift();
}else{
check_display_math_end();
}
run_mlist_to_hlist(p,false,text_style);
a= hpack(vlink(temp_head),0,additional,-1);
build_attribute_list(a);
unsave_math();
decr(save_ptr);
assert(saved_type(0)==saved_eqno);
if(saved_value(0)==1)
l= true;
m= mode;
p= fin_mlist(null);

}
if(m<0){






if(cur_cmd==math_shift_cs_cmd){
check_inline_math_end();
}
tail_append(new_math(math_surround,before));

if(math_skip!=zero_glue){
glue_ptr(tail)= math_skip;
add_glue_ref(math_skip);
}

if(dir_math_save){
tail_append(new_dir(math_direction));
}
run_mlist_to_hlist(p,(mode> 0),text_style);
vlink(tail)= vlink(temp_head);
while(vlink(tail)!=null)
tail= vlink(tail);
if(dir_math_save){
tail_append(new_dir(math_direction-dir_swap));
}
dir_math_save= false;
tail_append(new_math(math_surround,after));

if(math_skip!=zero_glue){
glue_ptr(tail)= math_skip;
add_glue_ref(math_skip);
}

space_factor= 1000;
unsave_math();
}else{
if(a==null){
if(cur_cmd==math_shift_cmd){
check_second_math_shift();
}else{
check_display_math_end();
}
}
run_mlist_to_hlist(p,false,display_style);
finish_displayed_math(l,a,vlink(temp_head));
}
}

/*:64*//*65:*/
#line 2501 "./luatexdir/tex/texmath.w"

void finish_display_alignment(pointer p,pointer q,halfword saved_prevdepth)
{
do_assignments();
if(cur_cmd==math_shift_cmd){
check_second_math_shift();
}else{
check_display_math_end();
}
pop_nest();
tail_append(new_penalty(int_par(pre_display_penalty_code)));
tail_append(new_param_glue(above_display_skip_code));
vlink(tail)= p;
if(p!=null)
tail= q;
tail_append(new_penalty(int_par(post_display_penalty_code)));
tail_append(new_param_glue(below_display_skip_code));
cur_list.prev_depth_field= saved_prevdepth;
resume_after_display();
}

/*:65*//*66:*/
#line 2524 "./luatexdir/tex/texmath.w"

void setup_math_style(void)
{
pointer q;
tail_append(new_noad());
q= new_node(math_char_node,0);
nucleus(tail)= q;
(void)scan_math_style(nucleus(tail),num_style(m_style));
}

/*:66*//*67:*/
#line 2534 "./luatexdir/tex/texmath.w"

void print_math_style(void)
{
if(abs(mode)==mmode)
print_int(m_style);
else
print_int(-1);
}/*:67*/
