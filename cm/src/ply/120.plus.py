tokens = ('NUMBER','PLUS')
t_PLUS    = r'\+'
def t_NUMBER(t):
  r'[0-9]+'
  t.value = int(t.value)
  return t
t_ignore = " \t"
import ply.lex as lex
lex.lex()
lex.input("5434+2882 +   45")
while True:
  tok = lex.token()
  if not tok: 
    break
  print(tok)
