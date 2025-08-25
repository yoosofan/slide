#include<iostream>
using namespace std;

string typeString[] = {
  "INT", "PLUS", "MINUS", "MUL",
  "DIV", "OP", "CP", "EOI"
};
 
enum TokenType{
  INT, PLUS, MINUS, MUL,
  DIV, OP, CP, EOI
};
struct Token{
  TokenType type;
  int n = 0;
};

void error(const string msg)
{cout<<msg<<endl; throw 0;}

class lexical{
  Token  t;
  char buffer[200];
  int tindex = 0;

  public:

  void read(void){
    cout << "Enter: ";
    cin.get(buffer,200);
  }

  void printToken(Token t){
    cout<< "tindex: "<< tindex
      << "\t type: "
      <<typeString[int(t.type)]
      <<"\t int "<< t.n << endl;
  }

  Token getToken(void);
};

int main(){
  lexical lex1;
  Token t;
  lex1.read();
  do{
    t=lex1.getToken();
    lex1.printToken(t);
  }while(t.type != EOI);
}

Token lexical::getToken(void){
  t.n = -1;
  if(buffer[tindex] == '(')        t.type = OP;
  else if(buffer[tindex] == ')')   t.type = CP;
  else if(buffer[tindex] == '+')   t.type = PLUS;
  else if(buffer[tindex] == '-')   t.type = MINUS;
  else if(buffer[tindex] == '*')   t.type = MUL;
  else if(buffer[tindex] == '/')   t.type = DIV;
  else if(buffer[tindex] == '\0')  t.type = EOI;

  else if(buffer[tindex]>='0' && buffer[tindex]<='9'){
    t.type=INT; t.n = 0;
    for(; buffer[tindex] >= '0' && buffer[tindex] <= '9'; tindex++)
        t.n=t.n*10+buffer[tindex]-48;
    tindex --;
  }
  else    error("unknown character");
  tindex++; 
  return t;
}