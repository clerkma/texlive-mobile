{2:}
 @define var tfm;
program OFM2OPL(tfmfile,plfile,output);label{3:}9999;{:3}const{4:}
ligsize=800000;hashsize=130003;hashmult=16007;maxchar=1114111;
xmaxchar=1114112;xxmaxchar=1114113;xmaxlabel=80001;{:4}{126:}
charcodeascii=0;charcodehex=1;charcodedefault=2;{:126}type{19:}
byte=0..255;indextype=integer;chartype=0..1114111;xchartype=0..1114112;
xxchartype=0..1114113;xxxchartype=0..1114114;{:19}{125:}
charcodeformattype=charcodeascii..charcodedefault;{:125}var{6:}
tfmfile:packed file of 0..255;{:6}{8:}
ofmlevel,nco,ncw,npc,nki,nwi,nkf,nwf,nkr,nwr,nkg,nwg,nkp,nwp,nkm,nwm,
reallf,nlw,neew,lf,lh,bc,ec,nw,nh,nd,ni,nl,nk,ne,np,fontdir:integer;
ofmon:boolean;{:8}{17:}plfile:text;{:17}{20:}
#define tfm (tfmfilearray + 1001);
tfmfilearray:^byte;
topchar,topwidth,topheight,topdepth,topitalic:integer;
startptr,checksum,designsize,scheme,family,randomword:integer;
headerlength,charptr,copies,j:integer;{:20}{23:}
ivaluesstart,fvaluesstart,mvaluesstart,rulesstart,gluesstart,
penaltiesstart:integer;
ivaluesbase,fvaluesbase,mvaluesbase,rulesbase,gluesbase,penaltiesbase:
integer;charbase,widthbase,heightbase,depthbase,italicbase:integer;
ligkernbase,kernbase,extenbase,parambase:integer;
charstart:array[0..maxchar]of integer;bytesperentry:integer;{:23}{26:}
fonttype:0..2;{:26}{28:}ASCII04,ASCII10,ASCII14:constcstring;
ASCIIall:packed array[0..256]of char;
MBLstring,RIstring,RCEstring:constcstring;HEX:constcstring;{:28}{30:}
dig:array[0..32]of integer;{:30}{33:}level:0..5;{:33}{46:}
charsonline:0..9;perfect:boolean;{:46}{48:}i:integer;c:xchartype;d:0..3;
k:indextype;r:0..maxchar;count:0..127;{:48}{63:}
startcounter,basecounter,numberentries:integer;value:integer;{:63}{73:}
gluesubtype,glueargumentkind,gluestretchorder,glueshrinkorder,
glueargument:integer;{:73}{78:}
labeltable:array[xxxchartype]of record cc:xchartype;rr:0..ligsize;
ischar:boolean;end;labelptr:xxchartype;sortptr:xxchartype;
boundarychar:xchartype;bcharlabel:0..xmaxlabel;{:78}{80:}
activity:array[0..ligsize]of 0..2;ai,acti:0..ligsize;{:80}{87:}
outputclabels:array[0..256]of boolean;clabelrunner:integer;{:87}{103:}
extenchar:integer;{:103}{107:}hash:array[0..hashsize]of integer64;
classvar:array[0..hashsize]of 0..4;ligz:array[0..hashsize]of xxchartype;
hashptr:0..hashsize;hashlist:array[0..hashsize]of 0..hashsize;
h,hh:0..hashsize;xligcycle,yligcycle:integer;{:107}{122:}
verbose:cinttype;{:122}{127:}charcodeformat:charcodeformattype;{:127}
{130:}tfmname,plname:constcstring;{:130}{118:}procedure parsearguments;
const noptions=4;var longoptions:array[0..noptions]of getoptstruct;
getoptreturnval:integer;optionindex:cinttype;currentoption:0..noptions;
begin{123:}verbose:=false;{:123}{128:}charcodeformat:=charcodedefault;
{:128};{119:}currentoption:=0;longoptions[currentoption].name:='help';
longoptions[currentoption].hasarg:=0;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;currentoption:=currentoption+1;{:119}
{120:}longoptions[currentoption].name:='version';
longoptions[currentoption].hasarg:=0;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;currentoption:=currentoption+1;{:120}
{121:}longoptions[currentoption].name:='verbose';
longoptions[currentoption].hasarg:=0;
longoptions[currentoption].flag:=addressof(verbose);
longoptions[currentoption].val:=1;currentoption:=currentoption+1;{:121}
{124:}longoptions[currentoption].name:='charcode-format';
longoptions[currentoption].hasarg:=1;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;currentoption:=currentoption+1;{:124}
{129:}longoptions[currentoption].name:=0;
longoptions[currentoption].hasarg:=0;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;{:129};
repeat getoptreturnval:=getoptlongonly(argc,argv,'',longoptions,
addressof(optionindex));if getoptreturnval=-1 then begin;
end else if getoptreturnval=63 then begin usage('ofm2opl');
end else if(strcmp(longoptions[optionindex].name,'help')=0)then begin
usagehelp(OFM2OPLHELP,nil);
end else if(strcmp(longoptions[optionindex].name,'version')=0)then begin
printversionandexit('This is OFM2OPL, Version 1.13',nil,
'J. Plaice, Y. Haralambous, D.E. Knuth',nil);
end else if(strcmp(longoptions[optionindex].name,'charcode-format')=0)
then begin if strcmp(optarg,'ascii')=0 then charcodeformat:=
charcodeascii else if strcmp(optarg,'hex')=0 then charcodeformat:=
charcodehex else writeln(stderr,'Bad character code format ',stringcast(
optarg),'.');end;until getoptreturnval=-1;
if(optind+1<>argc)and(optind+2<>argc)then begin writeln(stderr,'ofm2opl'
,': Need one or two file arguments.');usage('ofm2opl');end;
tfmname:=cmdline(optind);end;{:118}procedure initialize;
begin kpsesetprogramname(argv[0],'ofm2opl');
kpseinitprog('OFM2OPL',0,nil,nil);tfmfilearray:=xmallocarray(byte,1008);
parsearguments;{7:}tfmfile:=kpseopenfile(tfmname,kpseofmformat);
if verbose then begin write(stderr,'This is OFM2OPL, Version 1.13');
writeln(stderr,versionstring);end;{:7}{9:}ofmon:=false;ofmlevel:=-1;
lf:=0;lh:=0;nco:=0;ncw:=0;npc:=0;bc:=0;ec:=0;nw:=0;nh:=0;nd:=0;ni:=0;
nl:=0;nk:=0;ne:=0;np:=0;nki:=0;nwi:=0;nkf:=0;nwf:=0;nkm:=0;nwm:=0;
reallf:=0;nkr:=0;nwr:=0;nkg:=0;nwg:=0;nkp:=0;nwp:=0;fontdir:=0;{:9}{18:}
if optind+1=argc then begin plfile:=stdout;
end else begin plname:=extendfilename(cmdline(optind+1),'opl');
rewrite(plfile,plname);end;{:18}{29:}
ASCII04:='  !"#$%&''()*+,-./0123456789:;<=>?';
ASCII10:=' @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_';
ASCII14:=' `abcdefghijklmnopqrstuvwxyz{|}~ ';strcpy(ASCIIall,ASCII04);
strcat(ASCIIall,'@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_');
strcat(ASCIIall,'`abcdefghijklmnopqrstuvwxyz{|}~');MBLstring:=' MBL';
RIstring:=' RI ';RCEstring:=' RCE';HEX:=' 0123456789ABCDEF';{:29}{34:}
level:=0;{:34}{47:}charsonline:=0;perfect:=true;{:47}{79:}
boundarychar:=xmaxchar;bcharlabel:=xmaxlabel;labelptr:=0;
labeltable[0].rr:=0;{:79}{88:}
for clabelrunner:=0 to 256 do outputclabels[clabelrunner]:=false;{:88}
end;{:2}{25:}function widthindex(c:chartype):integer;
begin if not ofmon then widthindex:=tfm[charstart[c]]else widthindex:=
256*tfm[charstart[c]]+tfm[charstart[c]+1];end;
function heightindex(c:chartype):integer;
begin if not ofmon then heightindex:=tfm[charstart[c]+1]div 16 else
heightindex:=tfm[charstart[c]+2];end;
function depthindex(c:chartype):integer;
begin if not ofmon then depthindex:=tfm[charstart[c]+1]mod 16 else
depthindex:=tfm[charstart[c]+3];end;
function italicindex(c:chartype):integer;
begin if not ofmon then italicindex:=tfm[charstart[c]+2]div 4 else
italicindex:=tfm[charstart[c]+4];end;function tag(c:chartype):integer;
begin if not ofmon then tag:=tfm[charstart[c]+2]mod 4 else tag:=tfm[
charstart[c]+5]mod 4;end;procedure setnotag(c:chartype);
begin if not ofmon then tfm[charstart[c]+2]:=(tfm[charstart[c]+2]div 64)
*64+0 else tfm[charstart[c]+5]:=(tfm[charstart[c]+5]div 64)*64+0;end;
procedure checkunused(c:chartype);var x:integer;
begin if ofmlevel=1 then x:=tfm[charstart[c]+5]div 8 else x:=tfm[
charstart[c]+5]div 4;
if x<>0 then begin if ofmlevel=1 then x:=tfm[charstart[c]+5]mod 8 else x
:=tfm[charstart[c]+5]mod 4;tfm[charstart[c]+5]:=x;perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Ignoring non-zero unused char info bits');end;end;
function ctag(c:chartype):boolean;
begin if not(ofmlevel=1)then ctag:=false else ctag:=tfm[charstart[c]+5]
div 4 mod 2;end;procedure setnoctag(c:chartype);
begin if not(ofmlevel=1)then tfm[charstart[c]+5]:=tfm[charstart[c]+5]div
8*8+tfm[charstart[c]+5]mod 4;end;function norepeats(c:chartype):integer;
begin if ofmlevel<=0 then norepeats:=0 else norepeats:=256*tfm[charstart
[c]+8]+tfm[charstart[c]+9];end;function charparam(c:chartype;
i:integer):integer;
begin charparam:=256*tfm[charstart[c]+2*i+10]+tfm[charstart[c]+2*i+11];
end;function rremainder(c:chartype):integer;
begin if not ofmon then rremainder:=tfm[charstart[c]+3]else rremainder:=
256*tfm[charstart[c]+6]+tfm[charstart[c]+7];end;
function ligstep(c:chartype):integer;
begin if not ofmon then ligstep:=4*(ligkernbase+c)else ligstep:=4*(
ligkernbase+2*c);end;function exten(c:chartype):integer;
begin if not ofmon then exten:=4*(extenbase+rremainder(c))else exten:=4*
(extenbase+2*rremainder(c));end;function lskipbyte(c:integer):integer;
begin if not ofmon then lskipbyte:=tfm[c]else lskipbyte:=256*tfm[c]+tfm[
c+1];end;procedure setlskipbyte(c:integer;newc:integer);
begin if not ofmon then tfm[c]:=newc else begin tfm[c]:=newc div 256;
tfm[c+1]:=newc mod 256 end end;function lnextchar(c:integer):integer;
begin if not ofmon then lnextchar:=tfm[c+1]else lnextchar:=256*tfm[c+2]+
tfm[c+3];end;procedure setlnextchar(c:integer;newc:chartype);
begin if not ofmon then tfm[c+1]:=newc else begin tfm[c+2]:=newc div 256
;tfm[c+3]:=newc mod 256 end end;function lopbyte(c:integer):integer;
begin if not ofmon then lopbyte:=tfm[c+2]else lopbyte:=256*tfm[c+4]+tfm[
c+5];end;procedure setlopbyte(c:integer;newc:integer);
begin if not ofmon then tfm[c+2]:=newc else begin tfm[c+2]:=newc div 256
;tfm[c+3]:=newc mod 256 end end;function lremainder(c:integer):integer;
begin if not ofmon then lremainder:=tfm[c+3]else lremainder:=256*tfm[c+6
]+tfm[c+7];end;procedure setlremainder(c:integer;newc:chartype);
begin if not ofmon then tfm[c+3]:=newc else begin tfm[c+6]:=newc div 256
;tfm[c+7]:=newc mod 256 end end;{:25}{31:}procedure outdigs(j:integer);
begin repeat j:=j-1;write(plfile,HEX[1+dig[j]]);until j=0;end;
procedure printdigs(j:integer);begin repeat j:=j-1;
write(stderr,HEX[1+dig[j]]);until j=0;end;{:31}{32:}
procedure printnumber(c:integer;form:integer);var j:0..32;begin j:=0;
if(c<0)then begin writeln(stderr,
'Internal error: print_number (negative value)');c:=0;end;
if form=8 then write(stderr,'''')else if form=16 then write(stderr,'"')
else if form<>10 then begin writeln(stderr,
'Internal error: print_number (form)');form:=16;end;
while(c>0)or(j=0)do begin dig[j]:=c mod form;c:=c div form;j:=j+1;end;
printdigs(j);end;{:32}{35:}procedure outln;var l:0..5;
begin writeln(plfile);for l:=1 to level do write(plfile,'   ');end;
procedure left;begin level:=level+1;write(plfile,'(');end;
procedure right;begin level:=level-1;write(plfile,')');outln;end;{:35}
{36:}procedure outBCPL(k:indextype);var l:0..39;begin write(plfile,' ');
l:=tfm[k];while l>0 do begin k:=k+1;l:=l-1;
case tfm[k]div 32 of 1:write(plfile,ASCII04[1+(tfm[k]mod 32)]);
2:write(plfile,ASCII10[1+(tfm[k]mod 32)]);
3:write(plfile,ASCII14[1+(tfm[k]mod 32)]);end;end;end;{:36}{37:}
procedure outnumber(c:integer;form:integer);var j:0..32;begin j:=0;
if(c<0)then begin writeln(stderr,
'Internal error: print_number (negative value)');c:=0;end;
if form=8 then write(plfile,' O ')else if form=10 then write(plfile,
' D ')else if form=16 then write(plfile,' H ')else begin writeln(stderr,
'Internal error: print_number (form)');form:=16;write(plfile,' H ')end;
while(c>0)or(j=0)do begin dig[j]:=c mod form;c:=c div form;j:=j+1;end;
outdigs(j);end;procedure outhex(k,l:indextype);var a:0..2147483647;
b:0..32;j:0..11;begin write(plfile,' H ');a:=0;b:=0;j:=0;
while l>0 do{38:}begin l:=l-1;
if tfm[k+l]<>0 then begin while b>3 do begin dig[j]:=a mod 16;
a:=a div 16;b:=b-4;j:=j+1;end;case b of 0:a:=tfm[k+l];1:a:=a+2*tfm[k+l];
2:a:=a+4*tfm[k+l];3:a:=a+8*tfm[k+l];end;end;b:=b+8;end{:38};
while(a>0)or(j=0)do begin dig[j]:=a mod 16;a:=a div 16;j:=j+1;end;
outdigs(j);end;{:37}{39:}procedure outchar(c:integer);
begin if(fonttype>0)or(charcodeformat=charcodehex)then outnumber(c,16)
else if(charcodeformat=charcodeascii)and(c>32)and(c<=126)and(c<>40)and(c
<>41)then write(plfile,' C ',ASCIIall[c-31])else outnumber(c,16);end;
{:39}{40:}procedure outface(k:indextype);var s:0..1;b:0..8;
begin if tfm[k]>=18 then outhex(k,1)else begin write(plfile,' F ');
s:=tfm[k]mod 2;b:=tfm[k]div 2;putbyte(MBLstring[1+(b mod 3)],plfile);
putbyte(RIstring[1+s],plfile);putbyte(RCEstring[1+(b div 3)],plfile);
end;end;{:40}{41:}procedure outfix(k:indextype);var a:0..4095;f:integer;
j:0..12;delta:integer;begin write(plfile,' R ');
a:=(tfm[k]*16)+(tfm[k+1]div 16);
f:=((tfm[k+1]mod 16)*256+tfm[k+2])*256+tfm[k+3];if a>2047 then{44:}
begin write(plfile,'-');a:=4096-a;if f>0 then begin f:=1048576-f;a:=a-1;
end;end{:44};{42:}begin j:=0;repeat dig[j]:=a mod 10;a:=a div 10;j:=j+1;
until a=0;outdigs(j);end{:42};{43:}begin write(plfile,'.');f:=10*f+5;
delta:=10;repeat if delta>1048576 then f:=f+524288-(delta div 2);
write(plfile,f div 1048576:1);f:=10*(f mod 1048576);delta:=delta*10;
until f<=delta;end;{:43};end;{:41}{53:}
procedure checkBCPL(k,l:indextype);var j:indextype;c:integer;
begin if tfm[k]>=l then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ',
'String is too long; I''ve shortened it drastically.');end;tfm[k]:=1;
end;for j:=k+1 to k+tfm[k]do begin c:=tfm[j];
if(c=40)or(c=41)then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ',
'Parenthesis in string has been changed to slash.');end;tfm[j]:=47;
end else if(c<32)or(c>126)then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ',
'Nonstandard ASCII code has been blotted out.');end;tfm[j]:=63;
end else if(c>=97)and(c<=122)then tfm[j]:=c-32;end;end;{:53}{110:}
procedure hashinput;label 30;var cc:0..3;zz:chartype;y:chartype;
key:integer64;t64:integer64;t:integer;
begin if hashptr=hashsize then goto 30;{111:}k:=ligstep(i);
y:=lnextchar(k);t:=lopbyte(k);cc:=0;zz:=lremainder(k);
if t>=128 then zz:=y else begin case t of 0,6:;5,11:zz:=y;1,7:cc:=1;
2:cc:=2;3:cc:=3;end;end{:111};key:=int64cast(xmaxchar)*c+y+1;
h:=(hashmult*key)mod hashsize;
while hash[h]>0 do begin if hash[h]<=key then begin if hash[h]=key then
goto 30;t64:=hash[h];hash[h]:=key;key:=t64;t:=classvar[h];
classvar[h]:=cc;cc:=t;t:=ligz[h];ligz[h]:=zz;zz:=t;end;
if h>0 then h:=h-1 else h:=hashsize;end;hash[h]:=key;classvar[h]:=cc;
ligz[h]:=zz;hashptr:=hashptr+1;hashlist[hashptr]:=h;30:end;{:110}{112:}
ifdef('notdef')function ffn(h,x,y:indextype):indextype;begin end;
endif('notdef')function eval(x,y:indextype):indextype;var key:integer64;
begin key:=int64cast(xmaxchar)*x+y+1;h:=(hashmult*key)mod hashsize;
while hash[h]>key do if h>0 then h:=h-1 else h:=hashsize;
if hash[h]<key then eval:=y else eval:=ffn(h,x,y);end;{:112}{113:}
function ffn(h,x,y:indextype):indextype;begin case classvar[h]of 0:;
1:begin classvar[h]:=4;ligz[h]:=eval(ligz[h],y);classvar[h]:=0;end;
2:begin classvar[h]:=4;ligz[h]:=eval(x,ligz[h]);classvar[h]:=0;end;
3:begin classvar[h]:=4;ligz[h]:=eval(eval(x,ligz[h]),y);classvar[h]:=0;
end;4:begin xligcycle:=x;yligcycle:=y;ligz[h]:=xxmaxchar;classvar[h]:=0;
end;end;ffn:=ligz[h];end;{:113}{114:}function organize:boolean;
var tfmptr:indextype;begin{21:}read(tfmfile,tfm[0]);
if tfm[0]>127 then begin writeln(stderr,
'The first byte of the input file exceeds 127!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if eof(tfmfile)then begin writeln(stderr,
'The input file is only one byte long!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;read(tfmfile,tfm[1]);lf:=tfm[0]*256+tfm[1];
if lf=0 then begin for i:=2 to 7 do begin if eof(tfmfile)then begin
writeln(stderr,'The input file is too short to designate its length!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;read(tfmfile,tfm[i]);end;ofmon:=true;
ofmlevel:=tfm[2]*256+tfm[3];
if ofmlevel>1 then begin writeln(stderr,'OFMLEVEL ',ofmlevel:1,
' not supported, must be 0 or 1!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if tfm[4]>127 then begin writeln(stderr,
'The fifth byte of the input file exceeds 127!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;lf:=tfm[4]*16777216+tfm[5]*65536+tfm[6]*256+tfm[7];
end else begin ofmon:=false;end;case ofmlevel of-1:begin startptr:=2;
checksum:=24;end;0:begin startptr:=8;checksum:=56;end;
1:begin startptr:=8;checksum:=116;end;end;designsize:=checksum+4;
scheme:=designsize+4;family:=scheme+40;randomword:=family+20;
if lf=0 then begin writeln(stderr,
'The file claims to have length zero, but that''s impossible!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;tfmfilearray:=xreallocarray(tfmfilearray,byte,4*lf+1000);
for tfmptr:=startptr to 4*lf-1 do begin if eof(tfmfile)then begin
writeln(stderr,'The file has fewer bytes than it claims!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;read(tfmfile,tfm[tfmptr]);end;
if not eof(tfmfile)then begin writeln(stderr,
'There''s some extra junk at the end of the OFM file,');
writeln(stderr,'but I''ll proceed as if it weren''t there.');end{:21};
{22:}begin if not ofmon then begin tfmptr:=2;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;lh:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;bc:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;ec:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;nw:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;nh:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;nd:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;ni:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;nl:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;nk:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;ne:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;np:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
ncw:=(ec-bc+1);nlw:=nl;neew:=ne;headerlength:=6;topchar:=255;
topwidth:=255;topheight:=15;topdepth:=15;topitalic:=63;
end else begin tfmptr:=8;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
lh:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
bc:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
ec:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nw:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nh:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nd:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
ni:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nl:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nk:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
ne:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
np:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
fontdir:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;nlw:=2*nl;neew:=2*ne;topchar:=1114111;
topwidth:=1114111;topheight:=255;topdepth:=255;topitalic:=255;
if ofmlevel=0 then begin headerlength:=14;ncw:=2*(ec-bc+1);
end else begin headerlength:=29;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nco:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
ncw:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
npc:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nki:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwi:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nkf:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwf:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nkm:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwm:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nkr:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwr:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nkg:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwg:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nkp:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwp:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;end;end;
if lf<>(headerlength+lh+ncw+nw+nh+nd+ni+nlw+nk+neew+np+nki+nwi+nkf+nwf+
nkm+nwm+nkr+nwr+nkg+nwg+nkp+nwp)then begin writeln(stderr,
'Subfile sizes don''t add up to the stated total!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
if lh<2 then begin writeln(stderr,'The header length is only ',lh:1,'!')
;
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if nl>ligsize then begin writeln(stderr,
'The lig/kern program is longer than I can handle!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if(bc>ec+1)or(ec>topchar)then begin writeln(stderr,
'The character code range ',bc:1,'..',ec:1,' is illegal!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if ec>maxchar then begin writeln(stderr,'Character ',ec:1,
'is too large.  Ask a wizard to enlarge me.');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if(nw=0)or(nh=0)or(nd=0)or(ni=0)then begin writeln(stderr,
'Incomplete subfiles for character dimensions!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
if ne>(topchar+1)then begin writeln(stderr,'There are ',ne:1,
' extensible recipes!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;end{:22};{24:}begin ivaluesstart:=headerlength+lh;
fvaluesstart:=ivaluesstart+nki;mvaluesstart:=fvaluesstart+nkf;
rulesstart:=mvaluesstart+nkm;gluesstart:=rulesstart+nkr;
penaltiesstart:=gluesstart+nkg;ivaluesbase:=penaltiesstart+nkp;
fvaluesbase:=ivaluesbase+nwi;mvaluesbase:=fvaluesbase+nwf;
rulesbase:=mvaluesbase+nwm;gluesbase:=rulesbase+nwr;
penaltiesbase:=gluesbase+nwg;charbase:=penaltiesbase+nwp;
bytesperentry:=(12+2*npc)div 4*4;
if not ofmon then begin for i:=bc to ec do begin charstart[i]:=4*
charbase+4*(i-bc);end;
end else if ofmlevel=0 then begin for i:=bc to ec do begin charstart[i]
:=4*charbase+8*(i-bc);end;end else begin charptr:=4*charbase;i:=bc;
while i<=ec do begin copies:=1+256*tfm[charptr+8]+tfm[charptr+9];
for j:=1 to copies do begin charstart[i]:=charptr;i:=i+1;end;
charptr:=charptr+bytesperentry;end;
if charptr<>(4*(charbase+ncw))then begin writeln(stderr,
'Length of char info table does not correspond to specification');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;end;widthbase:=charbase+ncw;heightbase:=widthbase+nw;
depthbase:=heightbase+nh;italicbase:=depthbase+nd;
ligkernbase:=italicbase+ni;kernbase:=ligkernbase+nlw;
extenbase:=kernbase+nk;parambase:=extenbase+neew-1;end{:24};
organize:=true end;{:114}{115:}procedure dosimplethings;var i:integer;
begin{49:}begin case ofmlevel of 0:begin write(plfile,'(OFMLEVEL H 0)');
outln;end;1:begin write(plfile,'(OFMLEVEL H 1)');outln;end;end;
if ofmon then begin left;
if fontdir<=7 then write(plfile,'FONTDIR')else write(plfile,'NFONTDIR');
case fontdir mod 8 of 0:write(plfile,' TL');1:write(plfile,' LT');
2:write(plfile,' TR');3:write(plfile,' LB');4:write(plfile,' BL');
5:write(plfile,' RT');6:write(plfile,' BR');7:write(plfile,' RB');end;
right end;fonttype:=0;if lh>=12 then begin{54:}
begin checkBCPL(scheme,40);
if(tfm[scheme]>=11)and(tfm[scheme+1]=84)and(tfm[scheme+2]=69)and(tfm[
scheme+3]=88)and(tfm[scheme+4]=32)and(tfm[scheme+5]=77)and(tfm[scheme+6]
=65)and(tfm[scheme+7]=84)and(tfm[scheme+8]=72)and(tfm[scheme+9]=32)then
begin if(tfm[scheme+10]=83)and(tfm[scheme+11]=89)then fonttype:=1 else
if(tfm[scheme+10]=69)and(tfm[scheme+11]=88)then fonttype:=2;end;end{:54}
;if lh>=17 then begin{56:}left;write(plfile,'FAMILY');
checkBCPL(family,20);outBCPL(family);right{:56};if lh>=18 then{57:}
begin left;write(plfile,'FACE');outface(randomword+3);right;
for i:=18 to lh-1 do begin left;write(plfile,'HEADER D ',i:1);
outhex(checksum+4*i,4);right;end;end{:57};end;{55:}left;
write(plfile,'CODINGSCHEME');outBCPL(scheme);right{:55};end;{52:}left;
write(plfile,'DESIGNSIZE');
if tfm[designsize]>127 then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Design size ','negative','!');end;
writeln(stderr,'I''ve set it to 10 points.');write(plfile,' D 10');
end else if(tfm[designsize]=0)and(tfm[designsize+1]<16)then begin begin
perfect:=false;if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Design size ','too small','!');end;
writeln(stderr,'I''ve set it to 10 points.');write(plfile,' D 10');
end else outfix(designsize);right;
write(plfile,'(COMMENT DESIGNSIZE IS IN POINTS)');outln;
write(plfile,'(COMMENT OTHER SIZES ARE MULTIPLES OF DESIGNSIZE)');
outln{:52};{50:}left;write(plfile,'CHECKSUM');outhex(checksum,4);
right{:50};{58:}if ofmon then begin left;
write(plfile,'SEVENBITSAFEFLAG FALSE');right;
end else if(lh>17)and(tfm[randomword]>127)then begin left;
write(plfile,'SEVENBITSAFEFLAG TRUE');right;end{:58};end{:49};{59:}
if np>0 then begin left;write(plfile,'FONTDIMEN');outln;
for i:=1 to np do{61:}begin left;
if i=1 then write(plfile,'SLANT')else begin if(tfm[4*(parambase+i)]>0)
and(tfm[4*(parambase+i)]<255)then begin tfm[4*(parambase+i)]:=0;
tfm[(4*(parambase+i))+1]:=0;tfm[(4*(parambase+i))+2]:=0;
tfm[(4*(parambase+i))+3]:=0;begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Parameter',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;{62:}
if i<=7 then case i of 2:write(plfile,'SPACE');
3:write(plfile,'STRETCH');4:write(plfile,'SHRINK');
5:write(plfile,'XHEIGHT');6:write(plfile,'QUAD');
7:write(plfile,'EXTRASPACE')end else if(i<=22)and(fonttype=1)then case i
of 8:write(plfile,'NUM1');9:write(plfile,'NUM2');
10:write(plfile,'NUM3');11:write(plfile,'DENOM1');
12:write(plfile,'DENOM2');13:write(plfile,'SUP1');
14:write(plfile,'SUP2');15:write(plfile,'SUP3');16:write(plfile,'SUB1');
17:write(plfile,'SUB2');18:write(plfile,'SUPDROP');
19:write(plfile,'SUBDROP');20:write(plfile,'DELIM1');
21:write(plfile,'DELIM2');
22:write(plfile,'AXISHEIGHT')end else if(i<=13)and(fonttype=2)then if i=
8 then write(plfile,'DEFAULTRULETHICKNESS')else write(plfile,
'BIGOPSPACING',i-8:1)else write(plfile,'PARAMETER D ',i:1){:62};end;
outfix(4*(parambase+i));right;end{:61};right;end;{60:}
if(fonttype=1)and(np<>22)then writeln(stderr,
'Unusual number of fontdimen parameters for a math symbols font (',np:1,
' not 22).')else if(fonttype=2)and(np<>13)then writeln(stderr,
'Unusual number of fontdimen parameters for an extension font (',np:1,
' not 13).'){:60};{:59};{64:}
if nki>0 then begin startcounter:=ivaluesstart*4;
basecounter:=ivaluesbase*4;for i:=0 to nki-1 do{65:}begin left;
write(plfile,'FONTIVALUE');outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(plfile,'IVALUE');
outnumber(j,16);outln;value:=256*tfm[basecounter+2]+tfm[basecounter+3];
left;write(plfile,'IVALUEVAL');outnumber(value,16);right;right;
basecounter:=basecounter+4;end;right;startcounter:=startcounter+4;end;
{:65};end;{:64};{66:}if nkf>0 then begin startcounter:=fvaluesstart*4;
basecounter:=fvaluesbase*4;for i:=0 to nkf-1 do{67:}begin left;
write(plfile,'FONTFVALUE');outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(plfile,'FVALUE');
outnumber(j,16);outln;left;write(plfile,'FVALUEVAL');
outfix(basecounter);right;right;basecounter:=basecounter+4;end;right;
startcounter:=startcounter+4;end;{:67};end;{:66};{68:}
if nkm>0 then begin startcounter:=mvaluesstart*4;
basecounter:=mvaluesbase*4;for i:=0 to nkm-1 do{69:}begin left;
write(plfile,'FONTMVALUE');outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(plfile,'MVALUE');
outnumber(j,16);outln;left;write(plfile,'MVALUEVAL');
outfix(basecounter);right;right;basecounter:=basecounter+4;end;right;
startcounter:=startcounter+4;end;{:69};end;{:68};{70:}
if nkr>0 then begin startcounter:=rulesstart*4;basecounter:=rulesbase*4;
for i:=0 to nkr-1 do{71:}begin left;write(plfile,'FONTRULE');
outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(plfile,'RULE');
outnumber(j,16);outln;left;write(plfile,'RULEWD');outfix(basecounter);
right;left;write(plfile,'RULEHT');outfix(basecounter+4);right;left;
write(plfile,'RULEDP');outfix(basecounter+8);right;right;
basecounter:=basecounter+12;end;right;startcounter:=startcounter+4;end;
{:71};end{:70};{72:}if nkg>0 then begin startcounter:=gluesstart*4;
basecounter:=gluesbase*4;for i:=0 to nkg-1 do{74:}begin left;
write(plfile,'FONTGLUE');outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(plfile,'GLUE');
outnumber(j,16);outln;gluesubtype:=tfm[basecounter]div 16;
glueargumentkind:=tfm[basecounter]mod 16;
gluestretchorder:=tfm[basecounter+1]div 16;
glueshrinkorder:=tfm[basecounter+1]mod 16;
glueargument:=tfm[basecounter+2]*256+tfm[basecounter+3];left;
write(plfile,'GLUETYPE');case gluesubtype of 0:write(plfile,' H 0');
1:write(plfile,' H 1');2:write(plfile,' H 2');3:write(plfile,' H 3');
end;right;case glueargumentkind of 1:begin left;
write(plfile,'GLUERULE');outnumber(glueargument,16);right;end;
2:begin left;write(plfile,'GLUECHAR');outnumber(glueargument,16);right;
end;end;left;write(plfile,'GLUESTRETCHORDER');
case gluestretchorder of 0:write(plfile,' H 0');1:write(plfile,' H 1');
2:write(plfile,' H 2');3:write(plfile,' H 3');4:write(plfile,' H 4');
end;right;left;write(plfile,'GLUESHRINKORDER');
case glueshrinkorder of 0:write(plfile,' H 0');1:write(plfile,' H 1');
2:write(plfile,' H 2');3:write(plfile,' H 3');4:write(plfile,' H 4');
end;right;left;write(plfile,'GLUEWD');outfix(basecounter+4);right;left;
write(plfile,'GLUESTRETCH');outfix(basecounter+8);right;left;
write(plfile,'GLUESHRINK');outfix(basecounter+12);right;right;
basecounter:=basecounter+16;end;right;startcounter:=startcounter+4;end;
{:74};end;{:72};{75:}if nkp>0 then begin startcounter:=penaltiesstart*4;
basecounter:=penaltiesbase*4;for i:=0 to nkp-1 do{76:}begin left;
write(plfile,'FONTPENALTY');outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(plfile,'PENALTY');
outnumber(j,16);outln;value:=256*tfm[basecounter+2]+tfm[basecounter+3];
left;write(plfile,'PENALTYVAL');outnumber(value,16);right;right;
basecounter:=basecounter+4;end;right;startcounter:=startcounter+4;end;
{:76};end;{:75};{77:}
if(tfm[4*widthbase]>0)or(tfm[4*widthbase+1]>0)or(tfm[4*widthbase+2]>0)or
(tfm[4*widthbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','width[0] should be zero.');end;
if(tfm[4*heightbase]>0)or(tfm[4*heightbase+1]>0)or(tfm[4*heightbase+2]>0
)or(tfm[4*heightbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','height[0] should be zero.');end;
if(tfm[4*depthbase]>0)or(tfm[4*depthbase+1]>0)or(tfm[4*depthbase+2]>0)or
(tfm[4*depthbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','depth[0] should be zero.');end;
if(tfm[4*italicbase]>0)or(tfm[4*italicbase+1]>0)or(tfm[4*italicbase+2]>0
)or(tfm[4*italicbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','italic[0] should be zero.');end;
for i:=0 to nw-1 do if(tfm[4*(widthbase+i)]>0)and(tfm[4*(widthbase+i)]<
255)then begin tfm[4*(widthbase+i)]:=0;tfm[(4*(widthbase+i))+1]:=0;
tfm[(4*(widthbase+i))+2]:=0;tfm[(4*(widthbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad OFM file: ','Width',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
for i:=0 to nh-1 do if(tfm[4*(heightbase+i)]>0)and(tfm[4*(heightbase+i)]
<255)then begin tfm[4*(heightbase+i)]:=0;tfm[(4*(heightbase+i))+1]:=0;
tfm[(4*(heightbase+i))+2]:=0;tfm[(4*(heightbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad OFM file: ','Height',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
for i:=0 to nd-1 do if(tfm[4*(depthbase+i)]>0)and(tfm[4*(depthbase+i)]<
255)then begin tfm[4*(depthbase+i)]:=0;tfm[(4*(depthbase+i))+1]:=0;
tfm[(4*(depthbase+i))+2]:=0;tfm[(4*(depthbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad OFM file: ','Depth',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
for i:=0 to ni-1 do if(tfm[4*(italicbase+i)]>0)and(tfm[4*(italicbase+i)]
<255)then begin tfm[4*(italicbase+i)]:=0;tfm[(4*(italicbase+i))+1]:=0;
tfm[(4*(italicbase+i))+2]:=0;tfm[(4*(italicbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad OFM file: ','Italic correction',' ',i:1,
' is too big;');end;writeln(stderr,'I have set it to zero.');end;
if nk>0 then for i:=0 to nk-1 do if(tfm[4*(kernbase+i)]>0)and(tfm[4*(
kernbase+i)]<255)then begin tfm[4*(kernbase+i)]:=0;
tfm[(4*(kernbase+i))+1]:=0;tfm[(4*(kernbase+i))+2]:=0;
tfm[(4*(kernbase+i))+3]:=0;begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Kern',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;{:77}end;{:115}{116:}
procedure docharacters;var c:integer;k:indextype;ai:0..ligsize;
begin{95:}sortptr:=0;c:=bc;
while(c<=ec)do begin if widthindex(c)>0 then begin if charsonline>=8
then begin writeln(stderr,' ');charsonline:=1;
end else begin if charsonline>0 then write(stderr,' ');
if verbose then charsonline:=charsonline+1;end;
if norepeats(c)>0 then begin if verbose then begin printnumber(c,16);
write(stderr,'-');printnumber(c+norepeats(c),16);
charsonline:=charsonline+1;end;left;write(plfile,'CHARREPEAT');
outchar(c);outchar(norepeats(c));outln;
end else begin if verbose then printnumber(c,16);left;
write(plfile,'CHARACTER');outchar(c);outln;end;
if ofmon then checkunused(c);{96:}
if widthindex(c)>=nw then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Width',' index for character ');printnumber(c,16);
writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(plfile,'CHARWD');outfix(4*(widthbase+widthindex(c)));right;
end{:96};if heightindex(c)>0 then{97:}
if heightindex(c)>=nh then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Height',' index for character ');printnumber(c,16);
writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(plfile,'CHARHT');outfix(4*(heightbase+heightindex(c)));right;
end{:97};if depthindex(c)>0 then{98:}
if depthindex(c)>=nd then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Depth',' index for character ');printnumber(c,16);
writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(plfile,'CHARDP');outfix(4*(depthbase+depthindex(c)));right;
end{:98};if italicindex(c)>0 then{99:}
if italicindex(c)>=ni then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Italic correction',' index for character ');
printnumber(c,16);writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(plfile,'CHARIC');outfix(4*(italicbase+italicindex(c)));right;
end{:99};case tag(c)of 0:;1:{100:}begin left;write(plfile,'COMMENT');
outln;i:=rremainder(c);r:=ligstep(i);
if(lskipbyte(r)mod 256)>128 then i:=256*lopbyte(r)+lremainder(r);
repeat{91:}begin k:=ligstep(i);
if(lskipbyte(k)div 256)=1 then begin case lopbyte(k)of 17:begin left;
write(plfile,'CPEN');outnumber(lnextchar(k),16);
outnumber(lremainder(k),16);right;end;18:begin left;
write(plfile,'CGLUE');outnumber(lnextchar(k),16);
outnumber(lremainder(k),16);right;end;19:begin left;
write(plfile,'CPENGLUE');outnumber(lnextchar(k),16);
outnumber(lremainder(k)div 256,16);outnumber(lremainder(k)mod 256,16);
right;end;20:begin left;write(plfile,'CKRN');outnumber(lnextchar(k),16);
r:=lremainder(k);if r>=nk then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Kern index too large.');end;
write(plfile,' R 0.0');end else outfix(4*(kernbase+r));right;end;end;
end else if lskipbyte(k)>128 then begin if(256*lopbyte(k)+lremainder(k))
>=nl then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ',
'Ligature unconditional stop command address is too big.');end;
end else if lopbyte(k)>=128 then{93:}
begin if((lnextchar(k)<bc)or(lnextchar(k)>ec)or(widthindex(lnextchar(k))
=0))then if lnextchar(k)<>boundarychar then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Kern step for',' nonexistent character ')
;printnumber(lnextchar(k),16);writeln(stderr,'.');setlnextchar(k,0)end;
left;write(plfile,'KRN');outchar(lnextchar(k));
r:=256*(lopbyte(k)-128)+lremainder(k);
if r>=nk then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Kern index too large.');end;
write(plfile,' R 0.0');end else outfix(4*(kernbase+r));right;end{:93}
else{94:}
begin if((lnextchar(k)<bc)or(lnextchar(k)>ec)or(widthindex(lnextchar(k))
=0))then if lnextchar(k)<>boundarychar then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Ligature step for',
' nonexistent character ');printnumber(lnextchar(k),16);
writeln(stderr,'.');setlnextchar(k,0)end;
if((lremainder(k)<bc)or(lremainder(k)>ec)or(widthindex(lremainder(k))=0)
)then begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
write(stderr,'Bad OFM file: ','Ligature step produces the',
' nonexistent character ');printnumber(lremainder(k),16);
writeln(stderr,'.');setlremainder(k,0)end;left;r:=lopbyte(k);
if(r=4)or((r>7)and(r<>11))then begin writeln(stderr,
'Ligature step with nonstandard code changed to LIG');r:=0;
setlopbyte(k,0);end;if r mod 4>1 then write(plfile,'/');
write(plfile,'LIG');if odd(r)then write(plfile,'/');
while r>3 do begin write(plfile,'>');r:=r-4;end;outchar(lnextchar(k));
outchar(lremainder(k));right;end{:94};
if(lskipbyte(k)mod 256)>0 then if level=1 then{92:}
begin if(lskipbyte(k)mod 256)>=128 then write(plfile,'(STOP)')else begin
count:=0;
for ai:=i+1 to(i+(lskipbyte(k)mod 256))do if activity[ai]=2 then count:=
count+1;write(plfile,'(SKIP D ',count:1,')');end;outln;end{:92};end{:91}
;
if(lskipbyte(k)mod 256)>=128 then i:=nl else i:=i+1+(lskipbyte(k)mod 256
);until i>=nl;right;end{:100};2:{101:}begin r:=rremainder(c);
if((r<bc)or(r>ec)or(widthindex(r)=0))then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Character list link to',
' nonexistent character ');printnumber(r,16);writeln(stderr,'.');end;
setnotag(c);end else begin while(r<c)and(tag(r)=2)do r:=rremainder(r);
if r=c then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Cycle in a character list!');end;
write(stderr,'Character ');printnumber(c,16);
writeln(stderr,' now ends the list.');setnotag(c);end else begin left;
write(plfile,'NEXTLARGER');outchar(rremainder(c));right;end;end;
end{:101};3:{102:}if rremainder(c)>=ne then begin begin perfect:=false;
writeln(stderr,' ');write(stderr,'Extensible',' index for character ');
printnumber(c,16);writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end;setnotag(c);
end else begin left;write(plfile,'VARCHAR');outln;{104:}
for d:=0 to 3 do begin if not ofmon then begin k:=exten(c)+d;
extenchar:=tfm[k];end else begin k:=exten(c)+2*d;
extenchar:=256*tfm[k]+tfm[k+1];end;
if(d=3)or(extenchar>0)then begin left;case d of 0:write(plfile,'TOP');
1:write(plfile,'MID');2:write(plfile,'BOT');3:write(plfile,'REP')end;
if((extenchar<bc)or(extenchar>ec)or(widthindex(extenchar)=0))then
outchar(c)else outchar(extenchar);right;end end{:104};right;end{:102};
end;for i:=0 to npc-1 do begin if charparam(c,i)<>0 then begin left;
if i<nki then begin write(plfile,'CHARIVALUE');outnumber(i,16);
end else if i<(nki+nkf)then begin write(plfile,'CHARFVALUE');
outnumber(i-nki,16);
end else if i<(nki+nkf+nkm)then begin write(plfile,'CHARMVALUE');
outnumber(i-nki-nkf,16);
end else if i<(nki+nkf+nkm+nkr)then begin write(plfile,'CHARRULE');
outnumber(i-nki-nkf-nkm,16);
end else if i<(nki+nkf+nkm+nkr+nkg)then begin write(plfile,'CHARGLUE');
outnumber(i-nki-nkf-nkm-nkr,16);
end else if i<(nki+nkf+nkm+nkr+nkg+nkp)then begin write(plfile,
'CHARPENALTY');outnumber(i-nki-nkf-nkm-nkr-nkg,16);end;
outnumber(charparam(c,i),16);right;end;end;right;end;
c:=c+1+norepeats(c);end{:95};end;{:116}{117:}begin initialize;
if not organize then uexit(1);dosimplethings;{81:}
if nl>0 then begin for ai:=0 to nl-1 do activity[ai]:=0;{84:}
if lskipbyte(ligstep(0))=255 then begin left;
write(plfile,'BOUNDARYCHAR');boundarychar:=lnextchar(ligstep(0));
outchar(boundarychar);right;activity[0]:=1;end;
if lskipbyte(ligstep(nl-1))=255 then begin r:=256*lopbyte(ligstep(nl-1))
+lremainder(ligstep(nl-1));if r>=nl then begin perfect:=false;
writeln(stderr,' ');write(stderr,
'Ligature/kern starting index for boundarychar is too large;');
writeln(stderr,'so I removed it.');end else begin labelptr:=1;
labeltable[1].cc:=xmaxchar;labeltable[1].rr:=r;bcharlabel:=r;
activity[r]:=2;end;activity[nl-1]:=1;end{:84};end;{82:}
for c:=bc to ec do if(tag(c)=1)or(ctag(c))then begin r:=rremainder(c);
if(lskipbyte(ligstep(r))div 256)=0 then begin if r<nl then begin if
lskipbyte(ligstep(r))>128 then begin r:=256*lopbyte(ligstep(r))+
lremainder(ligstep(r));
if r<nl then if activity[rremainder(c)]=0 then activity[rremainder(c)]:=
1;end;end;end;if r>=nl then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Ligature/kern starting index for character ');
printnumber(c,16);writeln(stderr,' is too large;');
writeln(stderr,'so I removed it.');setnotag(c);setnoctag(c);
end else{83:}begin sortptr:=labelptr;
while labeltable[sortptr].rr>r do begin labeltable[sortptr+1]:=
labeltable[sortptr];sortptr:=sortptr-1;end;
labeltable[sortptr+1].ischar:=not ctag(c);
if ctag(c)then labeltable[sortptr+1].cc:=charparam(c,0)else labeltable[
sortptr+1].cc:=c;labeltable[sortptr+1].rr:=r;labelptr:=labelptr+1;
activity[r]:=2;end{:83};end;labeltable[labelptr+1].rr:=ligsize;{:82};
if nl>0 then begin left;write(plfile,'LIGTABLE');outln;{85:}
for ai:=0 to(nl-1)do if(lskipbyte(ligstep(ai))div 256)=1 then activity[
ai]:=2 else if activity[ai]=2 then begin r:=lskipbyte(ligstep(ai));
if r<128 then begin r:=r+ai+1;if r>=nl then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Ligature/kern step ',ai:1,
' skips too far;');end;writeln(stderr,'I made it stop.');
setlskipbyte(ligstep(ai),128);end else activity[r]:=2;end;end{:85};{86:}
sortptr:=1;
for acti:=0 to nl-1 do if activity[acti]<>1 then begin i:=acti;{90:}
if activity[i]=0 then begin if level=1 then begin left;
write(plfile,'COMMENT THIS PART OF THE PROGRAM IS NEVER USED!');outln;
end end else if level=2 then right{:90};{89:}
while i=labeltable[sortptr].rr do begin if labeltable[sortptr].cc<>
xmaxchar and not labeltable[sortptr].ischar then begin if not
outputclabels[labeltable[sortptr].cc]then begin outputclabels[labeltable
[sortptr].cc]:=true;left;write(plfile,'CLABEL');
outchar(labeltable[sortptr].cc);right;end end else begin left;
write(plfile,'LABEL');
if labeltable[sortptr].cc=xmaxchar then write(plfile,' BOUNDARYCHAR')
else outchar(labeltable[sortptr].cc);right;end;sortptr:=sortptr+1;
end{:89};{91:}begin k:=ligstep(i);
if(lskipbyte(k)div 256)=1 then begin case lopbyte(k)of 17:begin left;
write(plfile,'CPEN');outnumber(lnextchar(k),16);
outnumber(lremainder(k),16);right;end;18:begin left;
write(plfile,'CGLUE');outnumber(lnextchar(k),16);
outnumber(lremainder(k),16);right;end;19:begin left;
write(plfile,'CPENGLUE');outnumber(lnextchar(k),16);
outnumber(lremainder(k)div 256,16);outnumber(lremainder(k)mod 256,16);
right;end;20:begin left;write(plfile,'CKRN');outnumber(lnextchar(k),16);
r:=lremainder(k);if r>=nk then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Kern index too large.');end;
write(plfile,' R 0.0');end else outfix(4*(kernbase+r));right;end;end;
end else if lskipbyte(k)>128 then begin if(256*lopbyte(k)+lremainder(k))
>=nl then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ',
'Ligature unconditional stop command address is too big.');end;
end else if lopbyte(k)>=128 then{93:}
begin if((lnextchar(k)<bc)or(lnextchar(k)>ec)or(widthindex(lnextchar(k))
=0))then if lnextchar(k)<>boundarychar then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Kern step for',' nonexistent character ')
;printnumber(lnextchar(k),16);writeln(stderr,'.');setlnextchar(k,0)end;
left;write(plfile,'KRN');outchar(lnextchar(k));
r:=256*(lopbyte(k)-128)+lremainder(k);
if r>=nk then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Kern index too large.');end;
write(plfile,' R 0.0');end else outfix(4*(kernbase+r));right;end{:93}
else{94:}
begin if((lnextchar(k)<bc)or(lnextchar(k)>ec)or(widthindex(lnextchar(k))
=0))then if lnextchar(k)<>boundarychar then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Ligature step for',
' nonexistent character ');printnumber(lnextchar(k),16);
writeln(stderr,'.');setlnextchar(k,0)end;
if((lremainder(k)<bc)or(lremainder(k)>ec)or(widthindex(lremainder(k))=0)
)then begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
write(stderr,'Bad OFM file: ','Ligature step produces the',
' nonexistent character ');printnumber(lremainder(k),16);
writeln(stderr,'.');setlremainder(k,0)end;left;r:=lopbyte(k);
if(r=4)or((r>7)and(r<>11))then begin writeln(stderr,
'Ligature step with nonstandard code changed to LIG');r:=0;
setlopbyte(k,0);end;if r mod 4>1 then write(plfile,'/');
write(plfile,'LIG');if odd(r)then write(plfile,'/');
while r>3 do begin write(plfile,'>');r:=r-4;end;outchar(lnextchar(k));
outchar(lremainder(k));right;end{:94};
if(lskipbyte(k)mod 256)>0 then if level=1 then{92:}
begin if(lskipbyte(k)mod 256)>=128 then write(plfile,'(STOP)')else begin
count:=0;
for ai:=i+1 to(i+(lskipbyte(k)mod 256))do if activity[ai]=2 then count:=
count+1;write(plfile,'(SKIP D ',count:1,')');end;outln;end{:92};end{:91}
;end;if level=2 then right{:86};right;{108:}hashptr:=0;
yligcycle:=xmaxchar;for hh:=0 to hashsize do hash[hh]:=0;
for c:=bc to ec do if tag(c)=1 then begin i:=rremainder(c);
if(lskipbyte(ligstep(i))mod 256)>128 then i:=256*lopbyte(ligstep(i))+
lremainder(ligstep(i));{109:}repeat hashinput;k:=lskipbyte(ligstep(i));
if k>=128 then i:=nl else i:=i+1+k;until i>=nl{:109};end;
if bcharlabel<nl then begin c:=xmaxchar;i:=bcharlabel;{109:}
repeat hashinput;k:=lskipbyte(ligstep(i));
if k>=128 then i:=nl else i:=i+1+k;until i>=nl{:109};end;
if hashptr=hashsize then begin writeln(stderr,
'Sorry, I haven''t room for so many ligature/kern pairs!');uexit(1);end;
for hh:=1 to hashptr do begin r:=hashlist[hh];
if classvar[r]>0 then r:=ffn(r,(hash[r]-1)div xmaxchar,(hash[r]-1)mod
xmaxchar);end;if yligcycle<xmaxchar then begin write(stderr,
'Infinite ligature loop starting with ');
if xligcycle=xmaxchar then write(stderr,'boundary')else printnumber(
xligcycle,16);write(stderr,' and ');printnumber(yligcycle,16);
writeln(stderr,'!');
write(plfile,'(INFINITE LIGATURE LOOP MUST BE BROKEN!)');outln;
perfect:=false;end{:108};end{:81};{105:}
if ne>0 then for c:=0 to ne-1 do for d:=0 to 3 do begin if not ofmon
then begin k:=4*(extenbase+c)+d;extenchar:=tfm[k];
end else begin k:=4*(extenbase+c)+2*d;extenchar:=256*tfm[k]+tfm[k+1];
end;
if(extenchar>0)or(d=3)then begin if((extenchar<bc)or(extenchar>ec)or(
widthindex(extenchar)=0))then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Extensible recipe involves the',
' nonexistent character ');printnumber(extenchar,16);
writeln(stderr,'.');end;
if d<3 then begin if not ofmon then begin tfm[k]:=0;
end else begin tfm[k]:=0;tfm[k+1]:=0;end;end;end;end;end{:105};
docharacters;if verbose then writeln(stderr,'.');
if level<>0 then writeln(stderr,'This program isn''t working!');
if not perfect then begin write(plfile,
'(COMMENT THE OFM FILE WAS BAD, SO THE DATA HAS BEEN CHANGED!)');
writeln(plfile);end;end.{:117}
