keywords =  ('double', 'int', )
tokens = keywords + ('ID', 'COMMA', 'SEMI' )
t_COMMA      = r'\,'
t_SEMI    = r'\;'
t_ignore = " \t"
def t_ID(t):
  r'[a-zA-Z_][a-zA-Z_0-9]*'
  if t.value in keywords:
    t.type = t.value
  return t
def t_error(t):
  print("Illegal character '%s'" %
    t.value[0])
  t.lexer.skip(1)
import ply.lex as lex;lex.lex()
start = 'S'
ds1 = []
def p_S(p):
  'S : T L SEMI' # S → E
  print(p[1])
  print(ds1)
def p_Ttype(p):
  """T : int
       | double"""
  p[0] = p[1]
def p_id_m(p):
  'L : ID M' 
  ds1.append(p[1])
def p_m_empty(p):
  'M : '
  pass
def p_MLFcomma(p):
  'M : COMMA L'
  pass
def p_error(p):
  print("Syntax error at '%s'" % p)
import ply.yacc as yacc; yacc.yacc()
while True:
  try:  # .double x,y;
    s = input('int a,b,c; > ')
    if s.strip()=='':break
    yacc.parse(s)
    ds1=[]
  except: 
    print('unexpected error')