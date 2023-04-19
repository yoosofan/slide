from sly import Lexer

class CalcLexer(Lexer):

  tokens = {NUMBER, PLUS}
  ignore = ' \t'

  ignore_comment = r'\#.*'
  ignore_newline = r'\n+'

  PLUS    = r'\+'

  @_(r'\d+')
  def NUMBER(self, t):
    t.value = int(t.value)
    return t

  def error(self, t):
    print("Illegal character '%s'" % t.value[0])
    self.index += 1

if __name__ == '__main__':
  data = '''3 + 42 +8 # First comment
    + 46+980+51+# Another commnet
    343+43
  '''
  lexer = CalcLexer()
  for tok in lexer.tokenize(data):
    print('type=%r, value=%r, index=%r'
       % (tok.type, tok.value, tok.index))
