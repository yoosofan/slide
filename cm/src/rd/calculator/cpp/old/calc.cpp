#include<iostream>
#include<cctype>
#include<cstdlib>
using namespace std;
enum Type{Number,PLUS,MINUS,MUL,DIV,LPAR,RPAR,EOS};
struct Token{Type t;  double x;};
double T(void);double E(void);double F(void);
Token gt;    char buffer[2000];    int index=0;
Token getToken(void){  Token t;
  if(isdigit(buffer[index])){    t.t=Number ;    double x=0,y=0;
    while(isdigit(buffer[index])){    x = x*10+buffer[index]-48;      index++;}
    if(buffer[index]=='.'){    index++;      y=10;
      while(isdigit(buffer[index])){  x+=(buffer[index]-48)/y;  index++;  y*=10;  }
    }
    t.x=x;
  }else{
    switch(buffer[index]){
      case '+':t.t=PLUS;break;
      case '-':t.t=MINUS;break;
      case '*':t.t=MUL;break;
      case '/':t.t=DIV;break;
      case '(':t.t=LPAR;break;
      case ')':t.t=RPAR;break;
      case '\0':t.t=EOS;break;
      default:  cout<<"Illigal character";  exit(0);
    }
    index++;
  }
  return t;
}
double E(void){  double x=T(); Token pt=gt;
  while(gt.t==PLUS||gt.t==MINUS){    gt=getToken();
    if(pt.t==PLUS)x+=T();
    else          x-=T();
  }
  return x;
}
double T(void){  double x=F(); Token pt=gt;
  while(gt.t==MUL||gt.t==DIV){    gt=getToken();
    if(pt.t==MUL) x*=F();
    else          x/=F();
  }
  return x;
}
double F(void){  double x;
  if(gt.t==Number){    x=gt.x;    gt=getToken();  }
  else if(gt.t==LPAR){   gt=getToken();    x=E();
    if(gt.t==RPAR)      gt=getToken();
    else{cout<<"unbalance ("<<endl;      exit(0);    }
  }
  return x;
}
int main()
{ cout<<"Enter ";  cin.getline(buffer,190); gt=getToken();  cout<<E();  return 0;}
