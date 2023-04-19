from sly import Lexer

class CalcLexer(Lexer):

  tokens = {NUMBER, PLUS}
  ignore = ' \t'

  PLUS    = r'\+'
  NUMBER =  r'[0-9]+' #\d+

  def error(self, t):
    print("Illegal character '%s'" % t.value[0])
    self.index += 1

if __name__ == '__main__':
  data = '3 + 42 +8.43+456'
  lexer = CalcLexer()
  for tok in lexer.tokenize(data):
    print('type=%r, value=%r' % (tok.type, tok.value))
