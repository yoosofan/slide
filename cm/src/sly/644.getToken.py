from sly import Lexer
class CalcLexer(Lexer):
  tokens = {NUMBER, PLUS}
  ignore = ' \t'
  PLUS    = r'\+'

  @_(r'\d+(\.\d+)?')
  def NUMBER(self, t):
    t.value = float(t.value)
    return t

  def error(self, t):
    print('Line %d: Bad character %r'%(self.lineno, t.value[0]))
    self.index += 1

  def __init__(self, s1):
    self.listOfTokens = self.tokenize(s1)

  def getToken(self):
    try: return next(self.listOfTokens)
    except StopIteration:
      class myEofToken: 
        type = 'EOF'
        value = ''
        lineno = self.lineno
        index  = self.index
    return myEofToken

if __name__ == '__main__':
  data = '3 + 42 +8'
  lexer = CalcLexer(data)
  tok = lexer.getToken()
  while True:
    try:
      tok = lexer.getToken()
      print(tok.type, tok.value, tok.index, tok.lineno)
      if tok.type == 'EOF': break
    except EOFError: break
