%%
^aa             {printf("AAAAAAA\n"); }
^ss             {printf("SSSSSSS\n"); }
[0-9]+          {printf("Integer:: %s\n",yytext);}
[0-9]+\.[0-9]+   {printf("Real :: %s\n",yytext);}
.                       ;
\n                      ;
%%
int main(){ 
    yylex();
    printf("\n");
    return 0;
}
/*
 flex simpleNumber.l
 gcc lex.yy.c -lfl
 ./a.out < simpleNumber_input.txt
*/
