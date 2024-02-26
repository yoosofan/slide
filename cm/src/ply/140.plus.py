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

"""
S → E
E → E + T
E → a
"""

def p_s(p):
  'S : E' 
  print('S → E ', p[1])

def p_e_e_a(p):
  'E : E PLUS NUMBER' # E → E + a
  p[0] = p[1] + p[3]
  print('E → E_1 + a :', 'E: ', end='')
  print(p[0], ' \t E1: ', p[1], end='')
  print('\t a: ', p[3])

def p_e_a(p):
  'E : NUMBER' # E → a
  p[0] = p[1]
  print('E → a :', p[1])

def p_error(p):
  print("Syntax error at '%s'" % p.value)

import ply.yacc as yacc;
yacc.yacc()

while True:
  s = input('calc > ')
  if s.strip()=='':break
  yacc.parse(s)
