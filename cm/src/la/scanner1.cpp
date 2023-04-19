#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
enum Type {ID,INT,DOUBLE,LT,LE,WHILE,IF, RETURN, ASG};
struct Token{Type t;  char *str;  int  i;  double d; int line,pos;};
bool myAlpha(char c){return (c>='A' && c<='Z') ||   (c>='a' && c<='z') ? 1 : 0;}
class symboleTable{  
  struct stCls{ char name[32]; Type t;};
  public:   int n;   stCls table[2000];
  symboleTable(){ n=0;
    table[n].t=IF;     strcpy(table[n++].name,"if");
    table[n].t=WHILE;  strcpy(table[n++].name,"while");
    table[n].t=INT;    strcpy(table[n++].name,"int");
    table[n].t=DOUBLE; strcpy(table[n++].name,"double");
    table[n].t=RETURN; strcpy(table[n++].name,"return");
  }
  char* search(char *bf, int begin, int end, Type &t1){ int i=0;
    for(i=0;i<n;i++){int j;
      for(j=0;table[i].name[j];j++)
        if(bf[begin+j]!= table[i].name[j]) break;
      if(!table[i].name[j] && begin+j == end)
      {t1=table[i].t; return table[i].name; }
    }
    for(i=0;begin+i<end;i++)  table[n].name[i]=bf[begin+i];
    table[n].name[i]=0;  t1=table[n].t=ID; n++;
    return table[n-1].name;
  }
};
symboleTable smt; const int N=200000;
class scanner{ public:
  char buffer[N];  int begin,end,lineno,pos;
  scanner(const char *fileName="pr1.c"){
    ifstream f1(fileName);
    if(!f1){cout<<"file"; exit(0);}
    f1.seekg(0,ios::end); long long t1=f1.tellg(); f1.seekg(0,ios::beg);
    f1.read(buffer,t1);  f1.close(); begin=end=lineno=pos=0;
  }
  Token getToken(void){Token t;
    for(;buffer[begin]==' ' || buffer[begin]=='\n'|| buffer[begin]=='\t'; begin++)
      if(buffer[begin]=='\n')  lineno++;
    end=begin;
    if(myAlpha(buffer[begin]) || buffer[begin]=='_'){  end ++;
      while(isalnum(buffer[end]) || buffer[end]=='_')  end++;
      end--; t.str=smt.search(buffer, begin, end, t.t);
    }
    else if(isdigit(buffer[begin])){}
    else if(buffer[begin]=='"'){}
    else
      switch(buffer[begin]){
        case '<':
          end++;
          if(buffer[end]=='=') t.t=LE;
          else{end--;t.t=LT;}
          break;
      }
    pos=begin; begin=++end;  return t;
    }
};
int main(){scanner s1;cout<<smt.n<<endl; return 0;}
