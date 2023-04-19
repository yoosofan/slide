%%
[0-9]+                 {printf("INT:%s\n",yytext);}
[a-zA-Z_][a-zA-Z_0-9]* {printf("ID :%s\n",yytext);}
.   ;
\n  ;
%%

int main(){ 
  yylex();
  printf("\n");
  return 0;
}