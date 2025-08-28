#include<iostream>
#include<cstdlib>
using namespace std;

void error(const string msg)
{cout<<msg<<endl; exit(0);}

string typeString[] = {
  "INT", "PLUS", "MINUS", "MUL",
  "DIV", "OP", "CP", "EOI"
};

char buffer[200]; 
int tindex =0;

void read(void){
  cout << "Enter: ";
  cin.get(buffer, 200);
}

enum TokenType{
  INT, PLUS, MINUS, MUL,
  DIV, OP, CP, EOI
};

struct Token{
  TokenType type;
  int n;
};

void printToken(Token t){
  cout<< "tindex: "<< tindex
    << "\t type: "
    <<typeString[int(t.type)]
    <<"\t int "<< t.n << endl;
}

Token getToken(void);

int main(){
  Token t; read();
  do{
    t=getToken();
    printToken(t);
  }while(t.type != EOI);
}

Token getToken(void){
  Token  t; t.n = 0;
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
  else  error("unknown character");
  tindex++; 
  return t;
}