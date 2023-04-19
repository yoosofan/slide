from sly import Lexer
class CalcLexer(Lexer):
  tokens = {ID, NUMBER, ASSIGN}
  literals = {'{', '}', '+', '-', '(', ')'}
  ignore = ' \t'
  ID      = r'[a-zA-Z_][a-zA-Z0-9_]*'
  ASSIGN  = r'='
  NUMBER  = '\d+'

  def __init__(self): self.nesting_level = 0

  @_(r'\{')
  def lbrace(self, t):
    # Set token type to the expected literal
    t.type = '{'
    self.nesting_level += 1
    print('nesting level: ', self.nesting_level)
    return t

  @_(r'\}')
  def rbrace(self, t):
    # Set token type to the expected literal
    t.type = '}'
    self.nesting_level -=1
    print('nesting level: ', self.nesting_level)
    return t

if __name__ == '__main__':
  data = 'x += {s ( {t)} aa}'
  lexer = CalcLexer()
  for tok in lexer.tokenize(data):
    print('type=%r, value=%r' % (tok.type, tok.value))