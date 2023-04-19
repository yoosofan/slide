%{/* * We expand upon the first example by adding recognition of some other * parts of speech. */
%}
%%
[\t ]+   {     printf("\t")/* ignore white space */ ;}
aaa|bb {printf("%s :::: mytest\n",yytext);}
is|am|are|were|was|be|being|been|do|does|did|will|would|should|can|could|has|have|had|go   { printf("%s: is a verb\n", yytext); }
very|simply|gently|quietly|calmly|angrily        { printf("%s: is an adverb\n", yytext); }
to|from|behind|above|below|between|below    { printf("%s: is a preposition\n", yytext); }
if|then|and|but|or                { printf("%s: is a conjunction\n", yytext); }
their|my|your|his|her|its            { printf("%s: is an adjective\n", yytext); }
I|you|he|she|we|they            { printf("%s: in a pronoun\n", yytext); }
[a-zA-Z]+                     { printf("%s:  don't recognize, might be a noun\n", yytext);}
.                    { ECHO; /* normal default anyway */ }
\n                   { ECHO; /* normal default anyway */ }
%%
int main(){    yylex();}
/*
flex wordsInEnglish1.l
gcc lex.yy.c -lfl
./a.out < 12.wordsInEnglish1.input.txt
*/
