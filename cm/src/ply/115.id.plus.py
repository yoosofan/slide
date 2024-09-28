tokens = ('NUMBER','PLUS', 'MUL', 'ID')
t_PLUS    = r'\+'
t_MUL    = r'\*'
t_ID = r'[a-zA-Z_][a-zA-Z_0-9]*'
t_NUMBER = r'[0-9]+'

t_ignore = " \t"

import ply.lex as lex
lex.lex()

lex.input("5434+2882 + count34+   45")
while True:
  tok = lex.token()
  if not tok: break
  print(tok)