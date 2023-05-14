tokens = ('NUMBER','PLUS','MINUS','MUL');t_PLUS=r'\+';
t_MINUS=r'\-';t_MUL=r'\*'
def t_NUMBER(t):
  r'[0-9]+(\.[0-9]*)?'
  t.value = float(t.value);  return t
t_ignore = " \t"
def t_error(t):
  print("Illegal character pppp3333 '%s'" % t.value[0]);  t.lexer.skip(1)
import ply.lex as lex;lex.lex()
def p_s(p):
  'S : E'
  print('S->E ',p[1])
def p_e_e_a(p):
  'E : E PLUS T'
  p[0] = p[1]+p[3]; print('E->E1+T;E:',p[0],'E1:',p[1],'T:',p[3]);
def p_e_e_a1(p):
  'E : E MINUS T'
  p[0] = p[1]-p[3];  print('E->E1-T;E:',p[0],'E1:',p[1],'T:',p[3]);
def p_e_t(p):
  'E : T'	
  p[0]=p[1]; print('E -> T ; T:',p[0]);
def p_t_t_a(p):
  'T : T MUL NUMBER'
  p[0] = p[1]*p[3]; print('T->T1*a;T:',p[0],'T1:',p[1],'a:',p[3]);
def p_t_a(p):
  'T : NUMBER'	
  p[0]=p[1]; print('T->a ; a: ',p[0]);
def p_error(p):
  print("Syntax error at '%s'" % p.value)
import ply.yacc as yacc; yacc.yacc()
while True:
  s = input('calc > ');
  if s.strip()=='':break # با یک Enter که ورودی خالی باشد برنامه پایان یابد
  yacc.parse(s)
