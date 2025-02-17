tokens = ('NUMBER','PLUS', 'MUL', 'ID', 'ASG',
  'COMP', )
t_PLUS    = r'\+'
t_MUL    = r'\*'
t_ASG = '='
t_COMP = '=='
t_NUMBER = r'[0-9]+'
t_ignore = " \t\n"

def t_ID(t):
  r'[a-zA-Z_][a-zA-Z_0-9]*'
  l1 = ['if','while','for','do','break','else','continue','delete','new','nullptr']
  for m1 in l1:
    if m1 in t.value:
      t.type= m1 #'ID2'
      return t
  return t

def t_error(t):
    print("Illegal rrr '%s'" % t.value[0])
    t.lexer.skip(1)

import ply.lex as lex
lex.lex()
lex.input("""wwe2 == 4+23 = *34 +123
count+34+435
x=y
""")

while True:
  tok = lex.token()
  if not tok:  break
  print(tok)

"""
lex$ python3 132.assign.py 
LexToken(ID,'wwe2',1,0)
LexToken(ASG,'=',1,5)
LexToken(NUMBER,4,1,7)
LexToken(PLUS,'+',1,8)
LexToken(NUMBER,23,1,9)
LexToken(MUL,'*',1,12)
LexToken(NUMBER,34,1,13)
LexToken(PLUS,'+',1,16)
LexToken(NUMBER,123,1,17)
LexToken(ID,'count',1,21)
LexToken(PLUS,'+',1,26)
LexToken(NUMBER,34,1,27)
LexToken(PLUS,'+',1,29)
LexToken(NUMBER,435,1,30)
LexToken(ID,'x',1,34)
LexToken(ASG,'=',1,35)
LexToken(ID,'y',1,36)
lex$ 
"""