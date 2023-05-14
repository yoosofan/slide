tokens = ('NUMBER','PLUS', 'MINUS', 'MUL', 'DIV')
t_PLUS    = r'\+'
t_MINUS    = r'\-'
t_MUL    = r'\*'
t_DIV    = r'\/'
def t_NUMBER(t):
  r'[0-9]+'
  t.value = int(t.value)
  return t
t_ignore = " \t"
def t_error(t):
  print("Illegal character '%s'" % t.value[0])
  t.lexer.skip(1)
import ply.lex as lex;lex.lex()
def p_S_E(p):
  'S : E' # S → E
  print('S → E ', p[1])
def p_E_plus_T(p):
  'E : E PLUS T' # E → E + T
  p[0] = p[1] + p[3]
  print('E → E + T :', 'E: ',p[0], ' \t E1: ', p[1], '\t T: ', p[3])
def p_E_minus_T(p):
  'E : E MINUS T' # E → E - T
  p[0] = p[1] - p[3]
  print('E → E - T :', 'E: ',p[0], ' \t E1: ', p[1], '\t T: ', p[3])
def p_E_T(p):
  'E : T' # E → T
  p[0] = p[1]
  print('E → T :', 'E: ',p[0], ' \t T: ', p[1])
def p_T_mul_a(p):
  'T : T MUL NUMBER' # T → T * a 
  p[0] = p[1] * p[3]
  print('T → T * a :', 'T: ',p[0], ' \t T1: ', p[1], '\t a: ', p[3])
def p_T_div_a(p):
  'T : T DIV NUMBER' # T → T / a 
  p[0] = p[1] / p[3]
  print('T → T / a :', 'T: ',p[0], ' \t T1: ', p[1], '\t a: ', p[3])
def p_T_a(p):
  'T : NUMBER' # T → a
  p[0]=p[1]
  print('T → a :', p[1])
def p_error(p):
  print("Syntax error at '%s'" % p.value)
import ply.yacc as yacc; yacc.yacc()
while True:
  s = input('calc > ')
  if s.strip()=='':break
  yacc.parse(s)
