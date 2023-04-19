from sly import Lexer
class CalcLexer(Lexer):
  tokens = {NUMBER, PLUS, ID, IF, ELSE, WHILE}
  ignore = ' \t'
  ignore_comment = r'\#.*'
  PLUS    = r'\+'
  ID = r'[a-zA-Z_][a-zA-Z0-9_]*'

  # Special cases
  ID['if'] = IF
  ID['else'] = ELSE
  ID['while'] = WHILE  

  @_(r'\d+')
  def NUMBER(self, t):
    t.value = int(t.value)
    return t

  # Line number tracking
  @_(r'\n+')
  def ignore_newline(self, t):
    self.lineno += t.value.count('\n')

  def error(self, t):
    print("Illegal character '%s'" % t.value[0])
    self.index += 1

if __name__ == '__main__':
  data = 'count+ if +ifelse+8+while # First comment'
  lexer = CalcLexer()
  for tok in lexer.tokenize(data):
    print('type=%r, value=%r' % (tok.type, tok.value))