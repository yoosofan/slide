tokens = ('NUMBER','PLUS', 'MUL', 'ID')
t_PLUS    = r'\+'
t_MUL    = r'\*'
t_ID = r'[a-zA-Z_][a-zA-Z_0-9]*'

def t_NUMBER(t):
  r'[0-9]+'
  t.value = int(t.value)
  return t

t_ignore = " \t"

def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)

import ply.lex as lex
lex.lex()
lex.input("wwe2+4+23*34+123")
while True:
  tok = lex.token()
  if not tok:  break
  print(tok)
"""
lex$ python3 130.id.py 
LexToken(ID,'wwe2',1,0)
LexToken(PLUS,'+',1,4)
LexToken(NUMBER,4,1,5)
LexToken(PLUS,'+',1,6)
LexToken(NUMBER,23,1,7)
LexToken(MUL,'*',1,9)
LexToken(NUMBER,34,1,10)
LexToken(PLUS,'+',1,12)
LexToken(NUMBER,123,1,13)
lex$ 
"""

