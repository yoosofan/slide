tokens = ('NUMBER','PLUS')
t_PLUS    = r'\+'

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
lex.input("*4+2")
while True:
  tok = lex.token()
  if not tok:  break
  print(tok)
