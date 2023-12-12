"""  → , λ
S --> T L ;    # L.t = T.t
T --> INT      # T.t = INT
T --> DOUBLE   # T.t = DOUBLE
L --> a M      # type(a, L.t); M.t = L.t
M -->  λ       #
M --> , L      # L.t = M.t
double x,y,z;
int a,b;
"""
keywords =  ('double', 'int', )
tokens = keywords + ('ID', )
literals = [',', ';']

t_ignore = " \t"

def t_ID(t):
  r'[a-zA-Z_][a-zA-Z_0-9]*'
  if t.value in keywords:
    t.type = t.value
  return t

def t_error(t):
  print("Illegal '%s'" %t.value[0])
  t.lexer.skip(1)

import ply.lex as lex;lex.lex()

start = 'S'
ds1 = []

def p_S(p):
  'S : T L ";"' # S → E
  # p[2] = p[1]  # print('S → T L; ')
  print(p[1])
  print(ds1)

def p_Ttype(p):
  """T : int
       | double"""
  #print('T : INT | DOUBLE' )
  p[0] = p[1]

def p_id_m(p):
  'L : ID M' 
  # p[2] = p[0] , type(ID) = p[0]
  #print('L : ID M')
  ds1.append(p[1])

def p_m_empty(p):
  'M :'
  #print('M --> ')
  pass

def p_MLFcomma(p):
  'M : "," L'
  #print('M : COMMA L')
  # p[2] = p[0]
  pass

def p_error(p):
  print("Syntax error at '%s'" % p)

import ply.yacc as yacc; yacc.yacc()
while True:
  try:  # .double x,y;
    s = input('int a,b,c; > ')
    if s.strip()=='': break
    yacc.parse(s)
  except: print('unexpected error')
  finally: ds1 = []