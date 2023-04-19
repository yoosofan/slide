#include<iostream>
#include<cstdlib>
using namespace std;
enum TokenType{NUMBER, PLUS, MINUS, MUL, DIV, LPAR, RPAR, EOF};
struct Token {TokenType type; int n; double r;};
void error(const string msg){cout<<msg<<endl; exit(0);}
Token  t;
char buffer[200];
int tindex =0; 
void E(void); void T(void); void F(void); 
void read(void){cout << "Enter expression"<<endl; cin>>buffer;}
Token getToken(void){
  static int number_of_call = 0;  
  number_of_call ++;
  if(buffer[tindex] == '(')        t.type = LPAR;
  else if(buffer[tindex] == ')')   t.type = RPAR;
  else if(buffer[tindex] == '+')   t.type = PLUS;
  else if(buffer[tindex] == '-')   t.type = MINUS;
  else if(buffer[tindex] == '*')   t.type = MUL;
  else if(buffer[tindex] == '/')   t.type = DIV;
  else if(buffer[tindex]>='0' && buffer[tindex]<='9'){t.type=NUMBER; t.n = 0;
    for(;buffer[tindex]>='0'&&buffer[tindex]<='9';tindex++)t.n=t.n*10+buffer[tindex]-48;
    tindex --;
  }else if(buffer[tindex] == '\0')  t.type = EOF;
  else  error("unknown character");//cout << t.type<<'\t'<<tindex<<'\t'<<number_of_call<<'\t'<<t.n<<endl;
  tindex++; return t;
}
void A(void){
  t=getToken();
  E();
  if(t.type!=EOF)
    error("unrecognized token");
  else cout<<"Accept"<<endl;
}
void E(void){T();while(t.type==PLUS||t.type==MINUS){t=getToken();T();}}
void T(void){F();while(t.type==MUL || t.type==DIV ){t=getToken();F();}}
void F(void){
  if(t.type==LPAR){t=getToken(); E();if(t.type!=RPAR)error(" ) is missing");}
  else if(t.type==NUMBER) ;  else  error("Wrong token ");
  t=getToken();
}
void tryGetToken(void){do{t= getToken();}while(t.type != EOF);}
int main(){read(); /*tryGetToken();*/     A();    return 0;}
/*2-(3-2)/(3-(2-1)/(5-2*2))-1+2*/