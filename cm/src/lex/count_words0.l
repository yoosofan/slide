%%
^[0-9]+a+b+          {printf("1 ");}
[1-4]+abc*           {printf("2 ");}
[a-zA-Z]*[4-5]+      {printf("3 ");}
[^0-8]bm8*$          {printf("4 ");}
.                       ;
\n                      ;
%%
int main(){ yylex();printf("\n");return 0;}
