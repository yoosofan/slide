#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
enum Type {IF,WHILE, INT,DOUBLE,RETURN, ID, LT,LE,ASG, END_INPUT};
struct Token{Type t;  char *str=nullptr;  int  i=0; int line,pos;
    void print(void){cout << t << ":\t" << str << ":\t" << i << endl;}  
};
class symboleTable{  
  struct stCls{ char name[32]; Type t;};
  public:   int n = 0;   stCls table[2000];
  symboleTable(){
    table[n].t=IF;     strcpy(table[n++].name,"if");
    table[n].t=WHILE;  strcpy(table[n++].name,"while");
    table[n].t=INT;    strcpy(table[n++].name,"int");
    table[n].t=DOUBLE; strcpy(table[n++].name,"double");
    table[n].t=RETURN; strcpy(table[n++].name,"return");
  }
  char* search(char *bf, int begin, int end, Type &t1){ int i,j;
    for(i=0; i<n; i++){
      for(j=0; table[i].name[j] && begin+j <= end; j++)
        if(bf[begin+j] != table[i].name[j]) break;
      // cout << "begin+j: " << begin+j << "\t" << end << "\t" << bf[begin+j] << endl;
      if(!table[i].name[j] && begin+j-1 == end)
      {t1=table[i].t; return table[i].name; }
    }
    for(i=0;begin+i<=end;i++)  table[n].name[i]=bf[begin+i];
    table[n].name[i]=0;  t1=table[n].t=ID; n++;
    return table[n-1].name;
  }
  void print(void){for(int i = 0; i < n; i++) cout << table[i].name << endl;}
};
class scanner{ static const int N=200000; public:
  symboleTable smt; 
  char buffer[N];  int begin,end,lineno,pos;
  scanner(const char *fileName="pr1.c"){
    ifstream f1(fileName);
    if(!f1){cout<<"file"; throw 0;}
    f1.seekg(0,ios::end); long long t1=f1.tellg(); f1.seekg(0,ios::beg);
    f1.read(buffer,t1);  f1.close(); begin=end=lineno=pos=0;
  }
  Token getToken(void){Token t;
    for(;buffer[begin]==' ' || buffer[begin]=='\n'|| buffer[begin]=='\t'; begin++)
      if(buffer[begin]=='\n')  lineno++;
    end=begin;
    if(isalpha(buffer[begin]) || buffer[begin]=='_'){  end ++;
      while(isalnum(buffer[end]) || buffer[end]=='_')  end++;
      end--; t.str=smt.search(buffer, begin, end, t.t);
    } //  cout<< buffer[begin] << " ::: " << buffer[end] << endl;
    else if(isdigit(buffer[begin])){cout << " Unexpected numeric input: "; throw 1; }
    else if(buffer[begin]=='"'){cout << " Unexpected quotation mark input: "; throw 1;}
    else
      switch(buffer[begin]){
        case '<':
          end++;
          if(buffer[end]=='=') t.t=LE;
          else{end--;t.t=LT;}
        break;
        case '=': end++; t.t=ASG; break;
        case 0 : t.t = END_INPUT; break;
        default: cout << " Unexpected quotation mark input: "; throw 1;
      }
    pos=begin; if(t.t != END_INPUT) begin=++end;  return t;
  }
};
int main(){Token t1;scanner s1;t1=s1.getToken(); 
  while(t1.t != END_INPUT){t1.print(); t1=s1.getToken();}
  s1.smt.print();
}
