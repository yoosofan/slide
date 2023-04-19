%%
[\t ]+   {/* ignore white space */ ;}
aaa|bb {printf("%s :::: mytest\n",yytext);}
is|am|are|were|was|be {printf("%s: is a verb\n", yytext);}
being|been|do|does  {printf("%s: is a verb\n", yytext);}
did|will|would|should {printf("%s: is a verb\n", yytext);}
can|could|has|have {printf("%s: is a verb\n", yytext);}
had|go  {printf("%s: is a verb\n", yytext);}
very|simply|gently {printf("%s: is an adverb\n", yytext);}
quietly|calmly|angrily {printf("%s: is an adverb\n",yytext);}
to|from|behind { printf("%s: is a preposition\n", yytext);}
above|below  {printf("%s: is a preposition\n", yytext);}
between|below {printf("%s: is a preposition\n", yytext);}
if|then|and {printf("%s: is a conjunction\n", yytext);}
but|or {printf("%s: is a conjunction\n", yytext);}
their|my|your {printf("%s: is an adjective\n", yytext);}
his|her|its  {printf("%s: is an adjective\n", yytext);}
I|you|he|she {printf("%s: in a pronoun\n", yytext);}
we|they {printf("%s: in a pronoun\n", yytext);}
[a-zA-Z]+ {printf("%s: don't recognize, a noun\n",yytext);}
\&.|\n    { ECHO; /* normal default anyway */ }
%%
int main(){ yylex(); }
