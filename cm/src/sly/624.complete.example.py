from sly import Lexer
class CalcLexer(Lexer):
  tokens = {INT, FLOAT, ID, WHILE, PRINT, ASSIGN, LT, LE}
  literals = {'(', ')', '{', '}', ';', '+', '-', '*', '/'}
  ignore = ' \t';  ignore_comment = r'\#.*'
  ID = r'[a-zA-Z_][a-zA-Z0-9_]*'; ID['while'] = WHILE
  ID['print'] = PRINT # ID['if'] = IF # ID['else'] = ELSE
  ASSIGN  = r'=' #  EQ = r'=='
  LE      = r'<=' # NE = r'!='
  LT      = r'<' #GE=r'>='; GT=r'>'

  @_(r'\d+\.\d+')
  def FLOAT(self, t): t.value = float(t.value); return t

  @_(r'\d+')
  def INT(self, t): t.value = int(t.value); return t

  @_(r'\n+')
  def ignore_newline(self, t): self.lineno += t.value.count('\n')

  def error(self, t):
    print('Line %d: Bad character %r'%(self.lineno, t.value[0]))
    self.index += 1

data = '''x = 0.1;
while (x < 10) {
  print x: # Counting
  x = x + 1;
}'''
lexer = CalcLexer()
for tok in lexer.tokenize(data):
  print('(',tok.type,',',tok.value,',', tok.lineno, ',', 
    tok.index,')')