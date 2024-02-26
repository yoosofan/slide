# 128.pluse.mul.py
tokens = ('NUMBER','PLUS', 'MUL')
t_PLUS    = r'\+'
t_MUL    = r'\*'


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
lex.input("*445+23*34+123")

while True:
  tok = lex.token()
  if not tok:  break
  print(tok)

"""
lex$ python3 128.plus.mul.py 
LexToken(MUL,'*',1,0)
LexToken(NUMBER,445,1,1)
LexToken(PLUS,'+',1,4)
LexToken(NUMBER,23,1,5)
LexToken(MUL,'*',1,7)
LexToken(NUMBER,34,1,8)
LexToken(PLUS,'+',1,10)
LexToken(NUMBER,123,1,11)
lex$ 
"""

