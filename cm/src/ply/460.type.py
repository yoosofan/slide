"""  → , λ
S --> T {L.t = T.t} L ;    # 
T --> INT      {T.t = INT}
T --> DOUBLE   {T.t = DOUBLE}
L --> a {type(a, L.t); M.t = L.t} M      # 
M -->  λ       #
M --> , {L.t = M.t} L      # 
"""
tokens = ('ID','DOUBLE', 'INT', 
  'COMMA', 'SEMI' )
t_DOUBLE     = r'\.double'
t_INT        = r'\.int'
t_ID         = r'[a-zA-Z_][a-zA-Z_0-9]*'
t_COMMA      = r'\,'
t_SEMI    = r'\;'

t_ignore = " \t"

def t_error(t):
  print("Illegal character '%s'" %
    t.value[0])
  t.lexer.skip(1)

import ply.lex as lex;lex.lex()
'''
lex.input(".int a, b, c;")
while True:
  tok = lex.token()
  if not tok:  break
  print(tok)
'''

start = 'S'
ds1 = []

def p_S(p):
  'S : T Y L SEMI' # S → E
  # p[2] = p[1] 
  # print('S → T L; ')
  print(p[1])
  print(ds1)

def p_Yyyy(p):
  'Y :'
  print('L.t = T.t')
  
def p_Ttype(p):
  """T : INT
       | DOUBLE"""
  #print('T : INT | DOUBLE' )
  p[0] = p[1]

def p_id_m(p):
  'L : ID U M' 
  # p[2] = p[0] , type(ID) = p[0]
  #print('L : ID M')
  ds1.append(p[1])

def p_Uuu(p):
  'U :'
  print('type(a, L.t); M.t = L.t')

def p_m_empty(p):
  'M : '
  #print('M --> ')
  pass

def p_MLFcomma(p):
  'M : COMMA L'
  #print('M : COMMA L')
  # p[2] = p[0]
  pass

def p_error(p):
  print("Syntax error at '%s'" % p)

import ply.yacc as yacc; yacc.yacc()
while True:
  try:
    s = input('type > ')
    if s.strip()=='':break
    yacc.parse(s)
  except: 
    print('unexpected error')

