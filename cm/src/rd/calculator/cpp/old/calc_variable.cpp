#include<iostream>
#include<cctype>
#include<cstdlib>
using namespace std;
enum Type{Number,PLUS, MINUS,MUL,DIV,LPAR,RPAR,EOS,  NEWLINE,ASSIGN,ID,PRINT};
struct Token{Type t;double x;  char s[200];};
class SymbolTable{  string ids[1000];  double val[1000];  int n;
public:  SymbolTable(){n=0;}
  void add(string m,double x=0){   int i=0;
    for(;i<n;i++)    if(m==ids[i]) break;
    if(i==n)    n++;
    ids[i]=m;    val[i]=x;
  }
  double getVal(string m){ int i=0;double d=1;
    for(;i<n;i++)   if(m==ids[i]) break;
    if(i==n){  cout<<"Error value var ";      cout<<m<<endl;    }
    else d=ids[i];
    return d;
  }
};
SymbolTable symt;double T(void);double E(void);double F(void);
Token gt;char buffer[20000];int index=0;
void read(void){  fstream f1("inp.txt");  f1.read(buffer,20000-1);  f1.close();}
Token getToken(void){  Token t;
  while(buffer[index]==' ')    index++;
  if(isdigit(buffer[index])){    t.t=Number ;    double x=0,y=0;
    while(isdigit(buffer[index])){      x = x*10+buffer[index]-48; index++;}
    if(buffer[index]=='.'){index++;  y=10;
      while(isdigit(buffer[index])){x+=(buffer[index]-48)/y;	index++;	y*=10;}
    }
    t.x=x;
  }
  else if(isalpha(buffer[index])){
    t.t=ID; int i=0;
    for(;
isalnum(buffer[index]);index++)
      t.s[i]=buffer[index];
    t.s[i]='\0';
    if(strcpy(t.s[i],"print")){
      t.t=PRINT;
    else symt.add(t.s[i]);
  }
  else{
    switch(buffer[index]){
      case '+':t.t=PLUS;break;
      case '-':t.t=MINUS;break;
      case '*':t.t=MUL;break;
      case '/':t.t=DIV;break;
      case '(':t.t=LPAR;break;
      case ')':t.t=RPAR;break;
      case '\0':t.t=EOS;break;
      case '\n':t.t=NEWLINE;break;
      case '=':t.t=ASSIGN;break;
      default:
	cout<<"Illigal character";
	exit(0);
    }
    index++;
  }
  return t;
}
void Assign(void){
  if(gt.t==ID){
    string id1;
    id1=gt.s;gt=getToken();
    if(gt.t==ASSIGN){
      gt=getToken();
      double x=E();
      symt.add(id1,x);
    }
  }
  else if(gt.t==PRINT){
    gt=getToken();
    cout<<E();
  }
  else{cout<<"error ASSIGN";}
  gt=getToken();//newline
}
double E(void){
  double x=T();
  while(gt.t==PLUS||gt.t==MINUS){
    gt=getToken();
    x+=T();
  }
  return x;
}
double T(void){
  double x=F();
  while(gt.t==MUL||gt.t==DIV){
    gt=getToken();
    x*=F();
  }
  return x;
}
double F(void){
  double x;
  if(gt.t==Number){
    x=gt.x;
    gt=getToken();
  }
  else if(gt.t==ID){
    x=symt.getVal(gt.s)
    gt=getToken();
  }
  else if(gt.t==LPAR){
    gt=getToken();
    x=E();
    if(gt.t==RPAR)
      gt=getToken();
    else{
      cout<<"unbalance ("<<endl;
      exit(0);
    }
  }
  return x;
}
int main(){ cout<<"Enter ";
  cin.getline(buffer,190);
  gt=getToken();  cout<<E();
  return 0;
}
