%{
int numberOfInt=0   , numberOfDouble=0 , 
  numberOfString = 0 ,  numberOfLine =0 ;
int numberOfDot =0 , numberOfOther=0;
%}
%%
\n              {numberOfLine++;}
[0-9]+          {numberOfInt++;}
[0-9]*\.[0-9]+  {numberOfDouble++;}
\.              {numberOfDot++;}
[a-zA-Z]+       {numberOfString++;}
[ \t]           {}
.               {numberOfOther++;}
%%
int main(){
  yylex();
  printf("Int::%d\n", numberOfInt);
  printf("Double::%d\n", numberOfDouble);
  printf("Double::%d\n", numberOfString);
  printf("Line::%d\n", numberOfLine);
  printf("Dot::%d\n", numberOfDot);
  printf("Other::%d\n", numberOfOther);
}