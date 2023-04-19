tokens = ('NUMBER','PLUS', 
  'MUL', 'LPAR', 'RPAR')
t_PLUS     = r'\+'
t_MUL    = r'\*'
t_LPAR    = r'\('
t_RPAR    = r'\)'

def t_NUMBER(t):
  r'[0-9]+'
  t.value = int(t.value)
  return t
t_ignore = " \t"

def t_error(t):
  print("Illegal character '%s'"
     % t.value[0])
  t.lexer.skip(1)
import ply.lex as lex;lex.lex()

lastTempValue = 0  
def newTemp():
  global lastTempValue
  lastTempValue +=1
  s1 = 't' + str(lastTempValue)
  return s1;

def p_S(p):
  'S : E' # S → E 
  print(p[1]["code"])

def p_E_plus_T(p):
  'E : E PLUS T' # E → E + T
  p[0] = {}
  p[0]["loc"] = newTemp()
  p[0]["code"] = p[1]["code"]+\
    p[3]["code"]+\
    'add '+ str(p[0]["loc"])+\
    ', ' + str(p[1]["loc"])+\
    ', ' + str(p[3]["loc"])+'\n'

def p_E_T(p):
  'E : T' # E → T
  p[0]=p[1]

def p_T_MUL_F(p):
  'T : T MUL F' # T → T * F
  p[0] = {}
  p[0]["loc"] = newTemp()
  p[0]["code"] = p[1]["code"]+\
    p[3]["code"]+\
    'mult '+str(p[0]["loc"])+\
    ', '+str(p[1]["loc"])+\
    ', '+str(p[3]["loc"])+'\n'

def p_T_F(p):
  'T : F' # T → F
  p[0]=p[1]

def p_F_a(p):
  'F : NUMBER' # F → a
  p[0] = {}
  p[0]["loc"] = p[1]
  p[0]["code"] = ''

def p_F_lpar_E_rpar(p):
  'F : LPAR E RPAR' # F → ( E )
  p[0] = p[2]

def p_error(p):
  print("Syntax error at '%s'" % p)

import ply.yacc as yacc; 
yacc.yacc()
while True:
  try:
    s = input('calc > ').strip()
    if s == '':break
    yacc.parse(s)
  except: 
    print('unexpected error')
