%%
[0-9]+                      {printf("INT:%s\n",yytext);}
[a-zA-Z_][a-zA-Z_]*      {printf("ID :%s\n",yytext);}
.                       ;
\n                      ;
%%

int main(){ 
  yylex();
  printf("\n");
  return 0;
}
/*
sudo apt install g++
sudo apt install flex

flex 01.count_words.l
gcc lex.yy.c -lfl
./a.out < count_words_input_1.txt
*/
