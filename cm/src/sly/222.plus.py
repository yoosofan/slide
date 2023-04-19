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
