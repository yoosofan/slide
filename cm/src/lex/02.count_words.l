%%
[0-9]+                 {printf("int:%s\n",yytext);}
[a-zA-Z_][a-zA-Z_0-9]+ {printf("ID :%s\n",yytext);}
[1-4]+abc*             {printf("2  :%s\n",yytext);}
.   ;
\n  ;
%%
int main(){ 
  yylex();
  printf("\n");
  return 0;
}