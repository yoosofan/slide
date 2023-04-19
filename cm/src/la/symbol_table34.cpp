enum Type{ID,INT,DOUBLE,LT,LE,WHILE,IF, RETURN, ASG};
struct Token{
  Type t;  char *str; int  i;  
  double d; int line,pos;
};
class symboleTable{  
  struct stCls{char name[32]; Type t;};
  public: int n; stCls table[2000];
  symboleTable(){n=0; 
    table[n].t=IF;     strcpy(table[n++].name,"if");
    table[n].t=WHILE;  strcpy(table[n++].name,"while");
    table[n].t=INT;    strcpy(table[n++].name,"int");
    table[n].t=DOUBLE; strcpy(table[n++].name,"double");
    table[n].t=RETURN; strcpy(table[n++].name,"return");
  }
  int search(char *bf, int begin, int end, Type &t1){
    int i=0;
    for(i=0;i<n;i++){int j;
      for(j=0;table[i].name[j];j++)
        if(bf[begin+j]!= table[i].name[j])  break;
      if(!table[i].name[j] && begin+j == end)
      {t1=table[i].t; return i;}
    }
    for(i=0;begin+i<end;i++) table[n].name[i]=bf[begin+i];
    table[n].name[i]=0; t1=table[n].t=ID; n++;
    return n-1;
  }
};
