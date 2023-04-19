from sly import Lexer

class CalcLexer(Lexer):
  # Set of token names.   
  # This is always required
  tokens = { ID, NUMBER, PLUS, MINUS, TIMES,
             DIVIDE, ASSIGN, LPAREN, RPAREN }

  # String containing ignored characters
  # between tokens
  ignore = ' \t'

  # Regular expression rules for tokens
  ID      = r'[a-zA-Z_][a-zA-Z0-9_]*'
  NUMBER  = r'\d+'
  PLUS    = r'\+'
  MINUS   = r'-'
  TIMES   = r'\*'
  DIVIDE  = r'/'
  ASSIGN  = r'='
  LPAREN  = r'\('
  RPAREN  = r'\)'

if __name__ == '__main__':
  data = 'x = 3 + 42 * (s - t)'
  lexer = CalcLexer()
  for tok in lexer.tokenize(data):
    print('type=%r, value=%r' % (tok.type, tok.value))