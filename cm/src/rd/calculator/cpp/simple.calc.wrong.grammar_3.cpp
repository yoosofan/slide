#include <iostream>
using namespace std;
bool checkDigit(char c){return c<='9' && c>='0'? true:false;}
enum tokenType { ID, PLUS, MUL, END_OF,F_ERR  };
struct token{tokenType t; double v;
  void print(void){
    switch(t){
      case ID:
      cout<<"number: "<<v<<endl;
      break;
      case PLUS:
      cout<<" + "<<endl;
      break;
      case MUL:
      cout<<" * "<<endl;
      break;
      case END_OF:
      cout<<"End of input"<<endl;
      break;
      case F_ERR:
      cout<<"Token error"<<endl;
      break;
      default:
      cout<<"Unknown token type"<<endl;
      break;
    }
  }
};
struct lex{char *buf=nullptr;int index=0;
  void set(char *inp){buf=inp;}
  token getToken(void){token cur;cur.v=0;cur.t=F_ERR;
    while(buf[index]==' ' || buf[index]== '\t') index++;
    if(buf[index]=='+'){index++; cur.t=PLUS;}
    else if(buf[index]=='*'){index++; cur.t=MUL;}
    else if(buf[index]==0) cur.t=END_OF;
    else if(checkDigit(buf[index])){int k=0;
      while(checkDigit(buf[index])){k = k * 10 + buf[index]-48;index++;}
      cur.t=ID; cur.v=k;
    }else{cout<<"Error input"<<endl;exit(0);}
    //cout<<"getToken is called: ";
    //cur.print();
    return cur;
  }
};
class run{lex l; token cur; public:
  run(char*s){l.set(s);cur=l.getToken();}
  double E(void){    cout<<"E" <<endl; double x=T();
    while (cur.t == PLUS){cur=l.getToken();x+= T();}
    cout<<x<<endl;
    return x;
  }
  double T(void){    cout<<"T" <<endl; double x=F();
    while(cur.t == MUL ){cur=l.getToken();x*=F();}
    cout<<x<<endl;
    return x;
  }
  double F(){cout<<"F" <<endl;
    if(cur.t != ID){cout<<"Need ID "<<endl; exit(0);}
    double x=cur.v;
    cur=l.getToken();
    cout<<x<<endl;
    return x;
  }
};
int main(){ char buf[10000]; cout<<"Enter string: ";cin>>buf;run a(buf);cout<<a.E()<<endl;  return 0;}
