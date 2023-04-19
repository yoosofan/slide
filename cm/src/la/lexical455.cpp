#include<iostream>
#include<cstdlib>
using namespace std;
enum TokenType{
  NUMBER, PLUS, MINUS, MUL,
  DIV, LPAR, RPAR, EOF_INPUT
};
struct Token{
  TokenType type;
  int n;
  double r;
};

void error(const string msg)
{cout<<msg<<endl; exit(0);}

class lexical{
  Token  t;
  char buffer[200];
  int tindex =0;
  public:
  void read(void){
    cout << "Enter expression"
      << endl;
    cin>>buffer;
  }
  Token getToken(void){
    static int number_of_call = 0;
    number_of_call ++;
    if(buffer[tindex] == '(')        
      t.type = LPAR;
    else if(buffer[tindex] == ')')   
      t.type = RPAR;
    else if(buffer[tindex] == '+')   
      t.type = PLUS;
    else if(buffer[tindex] == '-')   
      t.type = MINUS;
    else if(buffer[tindex] == '*')   
      t.type = MUL;
    else if(buffer[tindex] == '/')   
      t.type = DIV;
    else if(buffer[tindex]>='0' && 
      buffer[tindex]<='9')
    {
      t.type=NUMBER; t.n = 0;
      for(; buffer[tindex] >= '0' && 
        buffer[tindex] <= '9'; tindex++)
          t.n=t.n*10+buffer[tindex]-48;
      tindex --;
    }else if(buffer[tindex] == '\0')  
      t.type = EOF_INPUT;
    else    
      error("unknown character");
    tindex++; 
    return t;
  }
  void printToken(Token t){
    cout<< "tindex: "<< tindex
      << "\t type: "<<t.type 
      <<"\t int "<< t.n << endl;
  }
};
int main(){
  lexical lex1;
  Token t;
  lex1.read();
  do{
    t=lex1.getToken();
    lex1.printToken(t);
  }while(t.type != EOF_INPUT);
  return 0;
}
