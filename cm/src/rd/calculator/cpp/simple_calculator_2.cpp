#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
enum TokenType {NUMBER, PLUS, MINUS, MUL , DIV, LPAR, RPAR, EOF};
struct Token {TokenType type; int n; double r;  string s;};
Token  t;  
bool debug_mod = true; 
char buffer[200]; 
int tindex=0;
double E(void); double T(void); double F(void);
void debug(const char*,unsigned,const char*s="",double d=0);
void error(const char*);void read(void);void reset_all(void);
Token getToken(void){
  if(buffer[tindex] == '(')    t.type = LPAR;
  else if (buffer[tindex] == ')') t.type = RPAR;
  else if(buffer[tindex] == '+')  t.type = PLUS;
  else if(buffer[tindex] == '-')  t.type = MINUS;
  else if(buffer[tindex] == '*')  t.type = MUL;
  else if(buffer[tindex] == '/')  t.type = DIV;
  else if(buffer[tindex] >= '0'&&buffer[tindex] <='9'){
    t.type=NUMBER;t.n=0;
    for(;buffer[tindex]>='0'&&buffer[tindex]<='9';tindex++) 
      t.n=t.n*10+buffer[tindex]-48;
    tindex--;
  }else if(buffer[tindex] == '\0') t.type = EOF;
  else  error("unknown character");
  tindex++; //debug(__func__,__LINE__);
  return t;
}
void A(void){ double x; t = getToken();  x= E();
  if(t.type != EOF) error("unrecognized token");
  cout<<"result is :"<<x<<endl;
}
double E(void){double x,y; TokenType prev; x=T();
  while(t.type==PLUS||t.type==MINUS){debug(__func__,__LINE__);
    prev=t.type; t=getToken();y=T();
    if(prev == PLUS) x+= y;
    else             x-=y;
    debug(__func__,__LINE__,"After + or - :: ",x);
  } debug(__func__,__LINE__,"End E",x);  return x;
}
double T(void){double x,y; TokenType prev;  x=F();
  while(t.type==MUL||t.type==DIV){debug(__func__,__LINE__);
    prev=t.type;t=getToken();y=F();
    if(prev==MUL)   x*=y;
    else            x/=y;
    debug(__func__,__LINE__,"After * or / :: ",x);
  } debug(__func__,__LINE__,"End T",x); return x;
}
double F(void){double x;debug(__func__,__LINE__);
  if(t.type==LPAR){
    t=getToken();
    x=E();
    if(t.type != RPAR)
      error(" ) is missings");}
  else if(t.type==NUMBER) 
    x=t.n ;
  else  error("Wrong token ");
  t=getToken();debug(__func__,__LINE__,"After F :: ",x);
  return x;
}
int main(){while(1){reset_all();read();A();for(int i=0;i<45;i++)cout<<"=";cout<<endl;}}
void reset_all(void){tindex=0;}
void debug(const char *fname,unsigned lineno,const char *st,
    double val){ 
  static int number_of_call = 0;
  number_of_call++;
  if(debug_mod==true || strcmp(fname,"error")==0){
    cout<<fname<<'\t'<<lineno<<'\t'<<st<<"\t\t\t"<<val<<endl;
    cout << "t.type"<<'\t'<<"tindex"<<'\t'
        <<"number_of_call"<<'\t'<<"t.n"<<endl;
    cout << t.type<<'\t'<<tindex<<'\t'
        <<number_of_call<<'\t'<<t.n<<endl;
    cout<<"buffer=\t"<<buffer+tindex<<endl;
    for(int i=0;i<45;i++)cout<<"-"; cout<<endl;
    //int ii; cin>>ii;
  }
}void error(const char* msg)
{debug(__func__,__LINE__,msg); exit(0);}
void read(void){cout << "Enter expression"<<endl;cin >> buffer;}
