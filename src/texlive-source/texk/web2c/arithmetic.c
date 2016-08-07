/*1:*/
#line 22 "./luatexdir/tex/arithmetic.w"



#include "ptexlib.h"

/*:1*//*2:*/
#line 50 "./luatexdir/tex/arithmetic.w"

int half(int x)
{
if(odd(x))
return((x+1)/2);
else
return(x/2);
}


/*:2*//*3:*/
#line 64 "./luatexdir/tex/arithmetic.w"

scaled round_decimals(int k)
{
int a;
a= 0;
while(k--> 0){
a= (a+dig[k]*two)/10;
}
return((a+1)/2);
}


/*:3*//*4:*/
#line 88 "./luatexdir/tex/arithmetic.w"

void print_scaled(scaled s)
{
scaled delta;
char buffer[20];
int i= 0;
if(s<0){
print_char('-');
negate(s);
}
print_int(s/unity);
buffer[i++]= '.';
s= 10*(s%unity)+5;
delta= 10;
do{
if(delta> unity)
s= s+0100000-50000;
buffer[i++]= '0'+(s/unity);
s= 10*(s%unity);
delta= delta*10;
}while(s> delta);
buffer[i++]= '\0';
tprint(buffer);
}

/*:4*//*5:*/
#line 138 "./luatexdir/tex/arithmetic.w"

boolean arith_error;
scaled tex_remainder;


/*:5*//*6:*/
#line 147 "./luatexdir/tex/arithmetic.w"

scaled mult_and_add(int n,scaled x,scaled y,scaled max_answer)
{
if(n==0)
return y;
if(n<0){
negate(x);
negate(n);
}
if(((x<=(max_answer-y)/n)&&(-x<=(max_answer+y)/n))){
return(n*x+y);
}else{
arith_error= true;
return 0;
}
}

/*:6*//*7:*/
#line 165 "./luatexdir/tex/arithmetic.w"

scaled x_over_n(scaled x,int n)
{
boolean negative;
negative= false;
if(n==0){
arith_error= true;
tex_remainder= x;
return 0;
}else{
if(n<0){
negate(x);
negate(n);
negative= true;
}
if(x>=0){
tex_remainder= x%n;
if(negative)
negate(tex_remainder);
return(x/n);
}else{
tex_remainder= -((-x)%n);
if(negative)
negate(tex_remainder);
return(-((-x)/n));
}
}
}


/*:7*//*8:*/
#line 202 "./luatexdir/tex/arithmetic.w"

scaled xn_over_d(scaled x,int n,int d)
{
nonnegative_integer t,u,v,xx,dd;
boolean positive= true;
if(x<0){
negate(x);
positive= false;
}
xx= (nonnegative_integer)x;
dd= (nonnegative_integer)d;
t= ((xx%0100000)*(nonnegative_integer)n);
u= ((xx/0100000)*(nonnegative_integer)n+(t/0100000));
v= (u%dd)*0100000+(t%0100000);
if(u/dd>=0100000)
arith_error= true;
else
u= 0100000*(u/dd)+(v/dd);
if(positive){
tex_remainder= (int)(v%dd);
return(scaled)u;
}else{

tex_remainder= -(int)(v%dd);
return-(scaled)(u);
}
}


/*:8*//*9:*/
#line 249 "./luatexdir/tex/arithmetic.w"

halfword badness(scaled t,scaled s)
{
int r;

if(t==0){
return 0;
}else if(s<=0){
return inf_bad;
}else{
if(t<=7230584)
r= (t*297)/s;
else if(s>=1663497)
r= t/(s/297);
else
r= t;
if(r> 1290)
return inf_bad;
else
return((r*r*r+0400000)/01000000);

}
}


/*:9*//*11:*/
#line 317 "./luatexdir/tex/arithmetic.w"

static int randoms[55];
static int j_random;
scaled random_seed;

/*:11*//*12:*/
#line 324 "./luatexdir/tex/arithmetic.w"

#define fraction_half 01000000000       
#define fraction_one 02000000000        
#define fraction_four 010000000000      
#define el_gordo 017777777777   

/*:12*//*13:*/
#line 367 "./luatexdir/tex/arithmetic.w"

static int make_frac(int p,int q)
{
int f;
int n;
register int be_careful;
boolean negative= false;
if(p<0){
negate(p);
negative= true;
}
if(q<=0){
#ifdef DEBUG
if(q==0)
confusion("/");
#endif
negate(q);
negative= !negative;
}
n= p/q;
p= p%q;
if(n>=8){
arith_error= true;
if(negative)
return(-el_gordo);
else
return el_gordo;
}else{
n= (n-1)*fraction_one;













f= 1;
do{
be_careful= p-q;
p= be_careful+p;
if(p>=0)
f= f+f+1;
else{
f+= f;
p= p+q;
}
}while(f<fraction_one);
be_careful= p-q;
if(be_careful+p>=0)
incr(f);

if(negative)
return(-(f+n));
else
return(f+n);
}
}

/*:13*//*14:*/
#line 431 "./luatexdir/tex/arithmetic.w"

static int take_frac(int q,int f)
{
int p;
int n;
register int be_careful;
boolean negative= false;

if(f<0){
negate(f);
negative= true;
}
if(q<0){
negate(q);
negative= !negative;
}

if(f<fraction_one){
n= 0;
}else{
n= f/fraction_one;
f= f%fraction_one;
if(q<=el_gordo/n){
n= n*q;
}else{
arith_error= true;
n= el_gordo;
}
}
f= f+fraction_one;





p= fraction_half;
if(q<fraction_four){
do{
if(odd(f))
p= halfp(p+q);
else
p= halfp(p);
f= halfp(f);
}while(f!=1);
}else{
do{
if(odd(f))
p= p+halfp(q-p);
else
p= halfp(p);
f= halfp(f);
}while(f!=1);
}

be_careful= n-el_gordo;
if(be_careful+p> 0){
arith_error= true;
n= el_gordo-p;
}
if(negative)
return(-(n+p));
else
return(n+p);
}



/*:14*//*15:*/
#line 505 "./luatexdir/tex/arithmetic.w"

static int two_to_the[31];
static int spec_log[29];

/*:15*//*16:*/
#line 509 "./luatexdir/tex/arithmetic.w"

void initialize_arithmetic(void)
{
int k;
two_to_the[0]= 1;
for(k= 1;k<=30;k++)
two_to_the[k]= 2*two_to_the[k-1];
spec_log[1]= 93032640;
spec_log[2]= 38612034;
spec_log[3]= 17922280;
spec_log[4]= 8662214;
spec_log[5]= 4261238;
spec_log[6]= 2113709;
spec_log[7]= 1052693;
spec_log[8]= 525315;
spec_log[9]= 262400;
spec_log[10]= 131136;
spec_log[11]= 65552;
spec_log[12]= 32772;
spec_log[13]= 16385;
for(k= 14;k<=27;k++)
spec_log[k]= two_to_the[27-k];
spec_log[28]= 1;
}

/*:16*//*17:*/
#line 534 "./luatexdir/tex/arithmetic.w"

static int m_log(int x)
{
int y,z;
int k;
if(x<=0){

print_err("Logarithm of ");
print_scaled(x);
tprint(" has been replaced by 0");
help2("Since I don't take logs of non-positive numbers,",
"I'm zeroing this one. Proceed, with fingers crossed.");
error();
return 0;
}else{
y= 1302456956+4-100;
z= 27595+6553600;
while(x<fraction_four){
x+= x;
y= y-93032639;
z= z-48782;
}

y= y+(z/unity);
k= 2;
while(x> fraction_four+4){


z= ((x-1)/two_to_the[k])+1;
while(x<fraction_four+z){
z= halfp(z+1);
k= k+1;
}
y= y+spec_log[k];
x= x-z;
}
return(y/8);
}
}



/*:17*//*18:*/
#line 581 "./luatexdir/tex/arithmetic.w"

static int ab_vs_cd(int a,int b,int c,int d)
{
int q,r;

if(a<0){
negate(a);
negate(b);
}
if(c<0){
negate(c);
negate(d);
}
if(d<=0){
if(b>=0)
return(((a==0||b==0)&&(c==0||d==0))?0:1);
if(d==0)
return(a==0?0:-1);
q= a;
a= c;
c= q;
q= -b;
b= -d;
d= q;
}else if(b<=0){
if(b<0&&a> 0)
return-1;
return(c==0?0:-1);
}

while(1){
q= a/d;
r= c/b;
if(q!=r)
return(q> r?1:-1);
q= a%d;
r= c%b;
if(r==0)
return(q==0?0:1);
if(q==0)
return-1;
a= b;
b= q;
c= d;
d= r;
}
}



/*:18*//*19:*/
#line 634 "./luatexdir/tex/arithmetic.w"

#define next_random() do {     \
 if (j_random==0) new_randoms(); else decr(j_random); \
    } while (0)

static void new_randoms(void)
{
int k;
int x;
for(k= 0;k<=23;k++){
x= randoms[k]-randoms[k+31];
if(x<0)
x= x+fraction_one;
randoms[k]= x;
}
for(k= 24;k<=54;k++){
x= randoms[k]-randoms[k-24];
if(x<0)
x= x+fraction_one;
randoms[k]= x;
}
j_random= 54;
}


/*:19*//*20:*/
#line 661 "./luatexdir/tex/arithmetic.w"

void init_randoms(int seed)
{
int j,jj,k;
int i;
j= abs(seed);
while(j>=fraction_one)
j= halfp(j);
k= 1;
for(i= 0;i<=54;i++){
jj= k;
k= j-k;
j= jj;
if(k<0)
k= k+fraction_one;
randoms[(i*21)%55]= j;
}
new_randoms();
new_randoms();
new_randoms();
}


/*:20*//*21:*/
#line 691 "./luatexdir/tex/arithmetic.w"

int unif_rand(int x)
{
int y;
next_random();
y= take_frac(abs(x),randoms[j_random]);
if(y==abs(x))
return 0;
else if(x> 0)
return y;
else
return-y;
}


/*:21*//*22:*/
#line 710 "./luatexdir/tex/arithmetic.w"

int norm_rand(void)
{
int x,u,l;
do{
do{
next_random();
x= take_frac(112429,randoms[j_random]-fraction_half);

next_random();
u= randoms[j_random];
}while(abs(x)>=u);
x= make_frac(x,u);
l= 139548960-m_log(u);
}while(ab_vs_cd(1024,l,x,x)<0);
return x;
}

/*:22*//*23:*/
#line 731 "./luatexdir/tex/arithmetic.w"

int fix_int(int val,int min,int max)
{
return(val<min?min:(val> max?max:val));
}/*:23*/
