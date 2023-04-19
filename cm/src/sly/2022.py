from sly import Lexer

class CalcLexer(Lexer):

  tokens = {NUMBER, PLUS}
  ignore = ' \t'

  PLUS    = r'\+'
  NUMBER =  r'[0-9]+' #\d+

if __name__ == '__main__':
  data = '3 + 42 +8'
  lexer = CalcLexer()
  for tok in lexer.tokenize(data):
    print('type=%r, value=%r' % (tok.type, tok.value))

class CalcParser(Parser):
  tokens = CalcLexer.tokens


  @_('E PLUS NUMBER ')
  def E(self, p):
      return p.E + p.NUMBER

  @_('E PLUS NUMBER ')
  def E(self, p):
      return p.E + p.NUMBER


  @_('expr')
  def statement(self, p):
      print(p.expr)

  @_('expr PLUS expr')
  def expr(self, p):
      return p.expr0 + p.expr1

  @_('expr MINUS expr')
  def expr(self, p):
      return p.expr0 - p.expr1

  @_('expr TIMES expr')
  def expr(self, p):
      return p.expr0 * p.expr1

  @_('expr DIVIDE expr')
  def expr(self, p):
      return p.expr0 / p.expr1

  @_('MINUS expr %prec UMINUS')
  def expr(self, p):
      return -p.expr

  @_('LPAREN expr RPAREN')
  def expr(self, p):
      return p.expr

  @_('NUMBER')
  def expr(self, p):
      return int(p.NUMBER)

  @_('NAME')
  def expr(self, p):
      try:
          return self.names[p.NAME]
      except LookupError:
          print(f'Undefined name {p.NAME!r}')
          return 0

if __name__ == '__main__':
    lexer = CalcLexer()
    parser = CalcParser()
    while True:
        try:
            text = input('calc > ')
        except EOFError:
            break
        if text:
            parser.parse(lexer.tokenize(text))
