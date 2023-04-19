%%
[0-9]+a+b+          {printf("1:%s\n",yytext);}
[0-9]+              {printf("i:%s\n",yytext);}
[0-9]+\.[0-9]*       {printf("r:%s\n",yytext);}
[a-zA-Z]*[4-5]+      {printf("3:%s\n",yytext);}
[^0-8]bm8*$          {printf("4:%s\n",yytext);}
.                       ;
\n                      ;
%%
int main(){ yylex();printf("\n");return 0;}
