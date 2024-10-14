class Symbol_table:
  def __init__(self):
    self.Global_n=0
    self.Global_name=[]
    self.Global_value=[]

tokens = ('NUMBER','PLUS', 'MINUS', 'MUL', 'DIV', 'LPAR', 'RPAR', 'ASG', 'ID')
t_PLUS     = r'\+'
t_MINUS    = r'\-'
t_MUL    = r'\*'
t_DIV    = r'/'
t_LPAR    = r'\('
t_RPAR    = r'\)'
t_ASG    = r'='
t_ID    = r'[a-zA-z]+[a-zA-Z0-9]*'

def t_NUMBER(t):
  r'[0-9]+'
  t.value = int(t.value)
  return t
t_ignore = " \t"
def t_error(t):
  print("Illegal character '%s'" % t.value[0])
  t.lexer.skip(1)
import ply.lex as lex;lex.lex()
def p_S(p):
  'S : E' # S → E
  print('S → E ', p[1])
def p_SL(p):
  'S : L' # S → L
  print('S → L ', p[1])
def p_L(p):
  ' L : ID ASG E' # L → id = E
  if p[1] not in st.Global_name : 
    st.Global_name.append(p[1])
    st.Global_value.append(p[3])
    st.Global_n += 1
  else:
    i = st.Global_name.index(p[1])
    st.Global_value[i] = p[3]
  print('L : id = E ', p[1],'\t' , p[3])
  p[0] = p[3]

def p_E_plus_T(p):
  'E : E PLUS T' # E → E + T
  p[0] = p[1] + p[3]
  print('E → E + T :', 'E: ',p[0], ' \t E1: ', p[1], '\t T: ', p[3])
def p_E_MINUS_T(p):
  'E : E MINUS T' # E → E - T
  p[0] = p[1] - p[3]
  print('E → E - T :', 'E: ',p[0], ' \t E1: ', p[1], '\t T: ', p[3])
def p_E_T(p):
  'E : T' # E → T
  p[0]=p[1]
  print('E → T :', p[1])
def p_T_MUL_F(p):
  'T : T MUL F' # T → T * F
  p[0] = p[1] * p[3]
  print('T → T * F :', 'T: ',p[0], ' \t T1: ', p[1], '\t F: ', p[3])
def p_T_DIV_F(p):
  'T : T DIV F' # T → T / F
  if p[3] != 0:  p[0] = p[1] / p[3]
  else: print('Error: Divide by zero '); p[0]=p[1]
  print('T → T / F :', 'T: ',p[0], ' \t T1: ', p[1], '\t F: ', p[3])
def p_T_F(p):
  'T : F' # T → F
  p[0]=p[1]
  print('T → F :', p[1])
def p_F_a(p):
  'F : NUMBER' # F → a
  p[0]=p[1]
  print('F → a :', p[1])
def p_F_id(p):
  'F : ID' # F → a
  i = st.Global_name.index(p[1])
  p[0] = st.Global_value[i]
  print('F → a :', p[1])
def p_F_lpar_E_rpar(p):
  'F : LPAR E RPAR' # F → ( E )
  p[0]=p[2]
  print('F → (E) :', p[0])
def p_error(p):
  print("Syntax error at '%s'" % p.value)
import ply.yacc as yacc; yacc.yacc()

st = Symbol_table()
while True:
  s = input('calc > ')
  if s.strip()=='':break
  yacc.parse(s)

