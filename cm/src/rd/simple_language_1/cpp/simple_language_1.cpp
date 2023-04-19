#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;
enum TokenType {IDENTIFIER, INT_NUMBER, REAL_NUMBER, CONSTANT_STRING, WHILE_KEYWORD, PLUS_OPERATOR , MINUS_OPERATOR, MUL_OPERATOR , DIV_OPERATOR , LPAR_OPERATOR , RPAR_OPERATOR , END_INPUT_FILE, UNKNOWN_TOKEN, LET_INSTRUCTION, PRINT_INSTRUCTION, BEGIN_KEYWORD , END_KEYWORD, EOL_DELIMETER, ASSIGN_OPERATOR };
const char*nameOfTokenTypes[]={"IDENTIFIER", "INT_NUMBER", "REAL_NUMBER", "CONSTANT_STRING", "WHILE_KEYWORD", "PLUS_OPERATOR" , "MINUS_OPERATOR", "MUL_OPERATOR" , "DIV_OPERATOR" , "LPAR_OPERATOR" , "RPAR_OPERATOR" , "END_INPUT_FILE", "UNKNOWN_TOKEN", "LET_INSTRUCTION", "PRINT_INSTRUCTION", "BEGIN_KEYWORD" , "END_KEYWORD", "EOL_DELIMETER", "ASSIGN_OPERATOR" };
struct Token {TokenType type; int n; double r; string s;} t ;
bool run_mode=true;bool debug_mod = false;const int MAX_NUMBER_OF_CHARACTER = 10000;
char buffer[MAX_NUMBER_OF_CHARACTER];int tindex =0;
void B(void); void do_assign(void); void do_while(void); void do_print(void);void L(void);
struct nodeSymbolTable{string name;TokenType type;double value;};
class symboleTable{int n; nodeSymbolTable sm[200]; public:
  symboleTable(){n=5;
    sm[0].name = "BEGIN"; sm[0].type = BEGIN_KEYWORD;
    sm[1].name = "END";   sm[1].type = END_KEYWORD;
    sm[2].name = "WHILE"; sm[2].type = WHILE_KEYWORD;
    sm[3].name = "LET";   sm[3].type = LET_INSTRUCTION;
    sm[4].name = "PRINT"; sm[4].type = PRINT_INSTRUCTION;
  }TokenType search(string n1 ){
    for(int i=0;i<n;i++)  if(n1==sm[i].name) return sm[i].type;
    return UNKNOWN_TOKEN;
  }TokenType insert(string n1){if(n>198){cout<<"Symbol table overflow"<<endl;exit(0);}
    sm[n].name=n1;sm[n].type=IDENTIFIER;sm[n].value=0;n++;return IDENTIFIER;
  }bool assign(string n1, double val){int i; bool retVal = true;
    for(i=0;i<n;i++) if(n1 == sm[i].name){ sm[i].value = val; break;}
    if(i==n){cout<<"Error in Assign in symbol table"<<endl;retVal = false;}
    return retVal;
  }double readVal(string n1){
    for(int i=0; i<n ; i++) if(sm[i].name == n1)  return sm[i].value;
    cout<<"Unknown name in read in symbol table"<<endl;   return 0;
  }
} sm1;
double E(void);double T(void);double F(void);void debug(void);void error(const string msg);void read(void);
Token getToken(void){while(buffer[tindex]==' '||buffer[tindex]=='\t')tindex++;
  switch(buffer[tindex]){
    case '(' : t.type = LPAR_OPERATOR;  break;
    case ')' : t.type = RPAR_OPERATOR;  break;
    case '+' : t.type = PLUS_OPERATOR;  break;
    case '-' : t.type = MINUS_OPERATOR; break;
    case '*' : t.type = MUL_OPERATOR;   break;
    case '/' : t.type = DIV_OPERATOR;   break;
    case '=' : t.type = ASSIGN_OPERATOR;break;
    case '\n': t.type = EOL_DELIMETER;
      tindex++;while(isspace(buffer[tindex]))tindex++;
      tindex--;break;
    default:
      if(buffer[tindex]>='0'&&buffer[tindex]<='9'){t.type=INT_NUMBER;t.n = 0;
        for(;buffer[tindex] >= '0' && buffer[tindex] <= '9' ; tindex ++)
          t.n = t.n * 10 + buffer[tindex] - 48 ;
        tindex --;
      }else if(buffer[tindex]>='A' && buffer[tindex]<='z'){t.type=IDENTIFIER; t.s="";
         for(;isalnum(buffer[tindex]);tindex++)t.s += buffer[tindex];
         tindex --;  t.type = sm1.search(t.s); 
         if(t.type==UNKNOWN_TOKEN)t.type=sm1.insert(t.s);
      }else if(buffer[tindex]=='\0')  t.type = END_INPUT_FILE;
      else               error("unknown character");
    break;
  }tindex ++;  if(debug_mod == true) debug();  return t;
}void A(void){t=getToken(); B(); t=getToken();
  if(t.type!=END_INPUT_FILE)error("unrecognized token A");
  cout <<"Accept"<<endl;
}void B(void){
  if(t.type!=BEGIN_KEYWORD)error("Your block must be started with BEGIN_KEYWORD");
  t=getToken();if(t.type != EOL_DELIMETER )error("\\n after BEGIN is missing");
  t=getToken();
  while(t.type==LET_INSTRUCTION||t.type==PRINT_INSTRUCTION||t.type==WHILE_KEYWORD){
    L();if(t.type != EOL_DELIMETER ) error("A line must be ended by \\n ");
    t=getToken();
  }
  if(t.type !=END_KEYWORD) error("Your block must be terminated by END_KEYWORD");
  t=getToken();
  if(t.type != EOL_DELIMETER )error("\\n after END is missing");
}void L(void){ 
  switch(t.type){
    case LET_INSTRUCTION:   do_assign();        break;
    case PRINT_INSTRUCTION: do_print();         break;
    case WHILE_KEYWORD:     do_while();         break;
    default: break;
  }
}void do_assign(void){t = getToken();
  if(t.type != IDENTIFIER) error("Left assignment needs IDENTIFIER");
  Token var1 = t;  t = getToken(); 
  if(t.type != ASSIGN_OPERATOR) error("Let statement must have = ");
  t=getToken(); double val=E();if(run_mode)sm1.assign(var1.s , val);
}void do_print(void){t=getToken();double val=E(); if(run_mode) cout<<val<<endl;}
void do_while(void){ int val,prun=run_mode,prev = tindex; t = getToken();
  while( 1 ){val=E();   if(!prun)val=0;   if(val==0)run_mode=false;
    if(t.type != EOL_DELIMETER) error("There is an error in while statement, \\n needs after E");
    t=getToken();     B();
    if(val==0){run_mode=prun;break;}  else{tindex = prev;  t = getToken();}
  }
}double E(void){double x,y; TokenType prev;  x=T();
  while(t.type == PLUS_OPERATOR || t.type == MINUS_OPERATOR ){
    prev =  t.type;   t=getToken();y= T(); 
    if(prev == PLUS_OPERATOR) x+= y;
    else             x-=y;
  }return x;
}double T(void){double x,y;TokenType prev; x=F();
  while( t.type == MUL_OPERATOR || t.type == DIV_OPERATOR ){
    prev = t.type;  t= getToken(); y=F();
    if(prev==MUL_OPERATOR)   x*=y;
    else                     x/=y;
  }return x;
}double F(void){double x;
  if(t.type == LPAR_OPERATOR){t=getToken(); x=E();
    if(t.type != RPAR_OPERATOR) error(" ) is missing");
  }else if(t.type == INT_NUMBER ) x= t.n ; 
  else if(t.type == IDENTIFIER )  x= sm1.readVal(t.s); 
  else    error("Wrong token in F");
  t=getToken(); return x; 
}int main(){read();A();return 0;}
void debug(void){  static int number_of_call = 0;  number_of_call ++;
  cout << "t.type"<<'\t'<<"tindex"<<'\t'<<"number_of_call"<<'\t'<<"t.n"<<endl;
  cout << nameOfTokenTypes[t.type]<<'\t'<<tindex<<'\t'<<number_of_call<<'\t'<<t.n<<endl;
  cout<<"buffer= "<<buffer+tindex<<endl;
}void error(const string msg){cout<<msg<<endl;debug(); exit(0);}
void read(void){char fileName1[200]="test1.txt";//cout<<"Enter name of input file"<<endl; cin>> fileName1;
  ifstream inpFile1(fileName1);if(!inpFile1){cout<<"Could not open input file: "<<fileName1<<endl; exit(0);}
  inpFile1.read(buffer , MAX_NUMBER_OF_CHARACTER);inpFile1.close();
}
