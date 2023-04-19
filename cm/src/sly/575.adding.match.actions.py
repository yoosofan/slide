from sly import Lexer
class CalcLexer(Lexer):
  # Set of token names.   
  # This is always required
  tokens = { ID, NUMBER, PLUS, TIMES, ASSIGN, EQ}

  # String containing ignored characters
  # between tokens
  ignore = ' \t'

  # Regular expression rules for tokens
  ID      = r'[a-zA-Z_][a-zA-Z0-9_]*'
  PLUS    = r'\+'
  ASSIGN  = r'='
  EQ      = r'=='  # MUST APPEAR FIRST! (LONGER)  

  @_(r'0x[0-9a-fA-F]+', r'\d+')
  def NUMBER(self, t):
    if t.value.startswith('0x'):
      t.value = int(t.value[2:], 16)
    else:
      t.value = int(t.value)
    return t
    
if __name__ == '__main__':
  data = 'x = 3 + 0xa2 33ab  s == t'
  lexer = CalcLexer()
  for tok in lexer.tokenize(data):
    print('type=%r, value=%r' % (tok.type, tok.value))