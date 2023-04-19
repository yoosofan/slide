%%
^aa               {printf("AAA : %s\n", yytext);}
^ss               {printf("SSS : %s\n", yytext);}
abc/.*123         {printf("ABC : %s\n", yytext); }
[0-9]+            {printf("Int : %s\n", yytext);}
[0-9]+\.[0-9]+    {printf("Real: %s\n", yytext);}
.                       ;
\n                      ;
%%
int main(){ 
    yylex();
    printf("\n");
    return 0;
}
/* input
12 234 434.45 676.45
eer
df
aa   abc bb aa
ss aa aaa  ss abcabc  654  sdfsf 123 lsdkjfsl 
aa   ss
*/
/*
flex 06.simpleNumber.l
gcc lex.yy.c -lfl
./a.out < 06.simpleNumber_input.txt
*/
