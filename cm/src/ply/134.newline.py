tokens = ('NUMBER','PLUS', 'MUL', 'ID', 'ASG')
t_PLUS    = r'\+'
t_MUL    = r'\*'
t_ID = r'[a-zA-Z_][a-zA-Z_0-9]*'
t_ASG = '='

def t_NUMBER(t):
  r'[0-9]+'
  t.value = int(t.value)
  return t

t_ignore = " \t"

def t_newline(t):
  r'\n+'
  t.lexer.lineno += len(t.value)
  print('new line')

def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)

import ply.lex as lex
lex.lex()
lex.input("""wwe2 = 4+23 *34 +123
count+34+435
x=y
""")

while True:
  tok = lex.token()
  if not tok:  break
  print(tok)
"""
lex$ python3 134.newline.py 
LexToken(ID,'wwe2',1,0)
LexToken(ASG,'=',1,5)
LexToken(NUMBER,4,1,7)
LexToken(PLUS,'+',1,8)
LexToken(NUMBER,23,1,9)
LexToken(MUL,'*',1,12)
LexToken(NUMBER,34,1,13)
LexToken(PLUS,'+',1,16)
LexToken(NUMBER,123,1,17)
new line
LexToken(ID,'count',2,21)
LexToken(PLUS,'+',2,26)
LexToken(NUMBER,34,2,27)
LexToken(PLUS,'+',2,29)
LexToken(NUMBER,435,2,30)
new line
LexToken(ID,'x',3,34)
LexToken(ASG,'=',3,35)
LexToken(ID,'y',3,36)
new line
"""