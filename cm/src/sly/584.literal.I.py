from sly import Lexer
class CalcLexer(Lexer):
  tokens = {ID, NUMBER, ASSIGN, ASSIGN}
  literals = {'+', '-', '(', ')'}
  ignore = ' \t'
  ID      = r'[a-zA-Z_][a-zA-Z0-9_]*'
  ASSIGN  = r'='
  NUMBER  = '\d+'

if __name__ == '__main__':
  data = 'x += (234+d t) aa)'
  lexer = CalcLexer()
  for tok in lexer.tokenize(data):
    print('type=%r, value=%r' % (tok.type, tok.value))