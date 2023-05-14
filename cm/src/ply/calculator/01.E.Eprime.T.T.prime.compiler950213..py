tokens = (
    'NUMBER',
    'PLUS''TIMES',
    )
# Tokens
t_PLUS    = r'\+'
t_TIMES   = r'\*'
def t_NUMBER(t):
  r'\d+'
  try:   t.value = int(t.value)
  except ValueError:
    print("Integer value too large %d", t.value)
    t.value = 0
  return t
# Ignored characters
t_ignore = " \t"
def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)
# Build the lexer
import ply.lex as lex
lexer = lex.lex()

class myMemory:
  def __init__(self):
    self.n=0;
    self.m=[]
  def newTemp(self,val=None):
    self.m.append(val)
    self.n+=1
    return self.n-1
  def __getitem__(self,index):
    return self.m[index]
  def __setitem__(self,index,val):
    self.m[index]=val

mem1=myMemory()

# Parsing rules
def p_statement_expr(p):
  'statement : expression'
  print(p[1])
def p_expression(p):
  'expression : term eprime'
  p[0]={}
  p[0]['node']=[ p[1]['node'] , p[2]['node'] ]
  p[0]['a']={}
  p[0]['a']['v']=p[2]['a']['v']
  p[2]['a']['s']=p[1]['a']['v']

def p_eprime(p):
  '''eprime : PLUS term eprime 
            |'''
  p[0]={}
  if len(p)==4 : 
    p[0]['a']={}
    p[0]['a']['s']=mem1.newTemp()
    p[0]['a']['v']=mem1.newTemp()
    p[0]['node']=['+', p[2]['node'], p[3]['node']]
  else:    p[0]['node']=[]

def p_term(p):
  '''term : factor tprime 
          |'''
  p[0]={}
  p[0]['a']={}
  p[0]['a']['s']=mem1.newTemp()
  p[0]['a']['v']=mem1.newTemp()
  if len(p)==3: p[0]['node']=[p[1]['node'], p[2]['node'] ]
  else: p[0]['node']=[]

def p_tprime(p):
  '''tprime : TIMES factor tprime
            |'''
  p[0]={}
  p[0]['a']={}
  p[0]['a']['s']=mem1.newTemp()
  p[0]['a']['v']=mem1.newTemp()
  if len(p)==4: p[0]['node']=['*',p[2]['node'], p[3]['node'] ]
  else: p[0]['node']=[]

def p_factor(p):
  'factor : NUMBER'
  p[0]={}
  p[0]['a']={}
  p[0]['a']['v']=mem1.newTemp(p[1])
  p[0]['node']=[]

def p_error(t):
    print("Syntax error at '%s'" % t.value)

import ply.yacc as yacc
parser = yacc.yacc()
s = input('calc &gt; ')   # Use raw_input on Python 2
parser.parse(s)
