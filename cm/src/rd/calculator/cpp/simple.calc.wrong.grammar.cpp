#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
enum tokenType { ID, PLUS, MUL, END_OF,F_ERR  };
struct token{tokenType t; double v;};
struct lex{char buf[10000]="";int index=0;
  void set(const char *inp){strcpy(buf,inp);}
  token getToken(void){token cur;cur.v=0;cur.t=F_ERR;
    while(buf[index]==' ' || buf[index]== '\t') index++;
    if(buf[index]=='+'){index++; cur.t=PLUS;}
    else if(buf[index]=='*'){index++; cur.t=MUL;}
    else if(buf[index]==0) cur.t=END_OF;
    else if(isdigit(buf[index])){int k=0;
      while(isdigit(buf[index])){k = k * 10 + buf[index]-48;index++;}
      cur.t=ID; cur.v=k;
    }else{cout<<"Error input"<<endl;exit(0);}
    cout<<cur.t<<"  "<<cur.v<<endl;
    return cur;
  }
};
class run{lex l; token cur; public:
  run(const char*s){l.set(s);cur=l.getToken();}
  double E(void){double x=T();
    cout<<"E" <<endl;
    while (cur.t == PLUS){cur=l.getToken();x+= T();}
    return x;
  }
  double T(void){double x=F();
    cout<<"T" <<endl;
    while(cur.t == MUL ){cur=l.getToken();x*=F();}
    return x;
  }
  double F(){
    if(cur.t != ID){cout<<"Need ID "<<endl; exit(0);}
    cout<<"F" <<endl;
    double x=cur.v;
    cur=l.getToken();
    return x;
  }
};
int main(){ char buf[10000]; cout<<"Enter string: ";cin>>buf;run a(buf);cout<<a.E()<<endl;  return 0;}
