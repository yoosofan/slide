/* flex programName.l
   gcc lex.yy.c -lfl
   ./a.out <input.txt
*/
%%
[0-9]ab+       {printf("1 ");}
[0-7]*abc+     {printf("2 ");}
[a-z]+[0-9]+   {printf("3 ");}
[^0-8]bm8*     {printf("4 ");}
\n             {printf("9 ");}
.              {printf("5 ");}
%%
main(){ yylex();printf("\n");return 0;}
