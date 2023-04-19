/* 
flex programName.l
gcc lex.yy.c -lfl
./a.out <input.txt
*/
%{
int numberOfInt=0   , numberOfDouble=0 , numberOfString = 0 ,  numberOfLine =0 ;
int numberOfDot =0 , numberOfOther=0;
%}

%%
\n { numberOfLine ++ ; }
[0-9]+ {numberOfInt ++ ;}
[0-9]*\.[0-9]+ {numberOfDouble ++;}
\.  {numberOfDot++;}
[a-zA-Z]+ {numberOfString++;}
[ \t] {}
. {numberOfOther++;}
%%

int main(){
  yylex();
  printf("Int::%d     Double::%d      String::%d     Line::%d \n", numberOfInt , numberOfDouble , numberOfString ,  numberOfLine);
  printf("Dot::%d    Other::%d \n", numberOfDot , numberOfOther);
}
