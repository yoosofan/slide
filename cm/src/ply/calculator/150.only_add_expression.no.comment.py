tokens = ('NUMBER','PLUS','MINUS')
t_PLUS    = r'\+'
t_MINUS    = r'\-'
def t_NUMBER(t):
  r'[0-9]+'
  t.value = int(t.value)
  return t
t_ignore = " \t"
def t_error(t):
  print("Illegal character '%s'" % t.value[0])
  t.lexer.skip(1)
import ply.lex as lex;lex.lex()
def p_s(p):
  'S : E'
  print(p[1])
def p_e_e_a(p):
  'E : E PLUS NUMBER' # E → E + T
  p[0] = p[1] + p[3]
def p_e_e_a1(p):
  'E : E MINUS NUMBER'
  p[0] = p[1]-p[3]
def p_e_a(p):
  'E : NUMBER' # E → a
  p[0]=p[1]
def p_error(p):
  print("Syntax error at '%s'" % p.value)
import ply.yacc as yacc; yacc.yacc()
while True:
  s = input('calc > ')
  if s.strip()=='':break
  yacc.parse(s)
