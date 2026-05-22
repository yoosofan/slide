from sly import Lexer
class BasicLexer(Lexer):
  tokens={BEGIN,END,LET,PRINT,WHILE,ID,NUMBER,NEWLINE}
  literals={'+','-','*','/','=','(',')'}
  ignore=' \t'
  BEGIN=r'BEGIN'
  END=r'END'
  LET=r'LET'
  PRINT=r'PRINT'
  WHILE=r'WHILE'
  ID=r'[A-Za-z_][A-Za-z0-9_]*'

  @_(r'\d+')
  def NUMBER(self,t):
    t.value=int(t.value)
    return t

  @_(r'\n+')
  def NEWLINE(self,t):
    return t

  def error(self,t):
    raise SyntaxError(f"Illegal character '{t.value[0]}'")

class Interpreter:
  def __init__(self,text):
    self.tokens=list(BasicLexer().tokenize(text))
    self.pos=0
    self.vars={}

  def current(self):
    return self.tokens[self.pos] if self.pos<len(self.tokens) else None

  def current_type(self):
    t=self.current()
    return t.type if t else 'EOF'

  def match(self,tp):
    if self.current_type()==tp:
      t=self.current()
      self.pos+=1
      return t

  def expect(self,tp):
    t=self.match(tp)
    if not t:
      raise SyntaxError(
        f"Expected {tp}, got {self.current_type()}")
    return t

  def program(self):
    while self.match('NEWLINE'): pass
    self.block()
    if self.current():
      raise SyntaxError("Extra input")

  def block(self):
    self.expect('BEGIN')
    self.expect('NEWLINE')
    self.statement_list()
    self.expect('END')
    if self.current():
      self.expect('NEWLINE')

  def statement_list(self):
    while self.current_type() in ('LET','PRINT','WHILE'):
      self.statement()
      self.expect('NEWLINE')

  def statement(self):
    name=self.expect('ID').value
    self.expect('=')
    if self.match('LET'):
      self.vars[self.expect('ID').value]=self.expr()

    elif self.match('PRINT'):
      print(self.expr())

    elif self.match('WHILE'):
      cp=self.pos
      self.expr()
      self.expect('NEWLINE')
      bp=self.pos
      self.block()
      ep=self.pos

      while True:
        self.pos=cp
        c=self.expr()
        self.expect('NEWLINE')
        if not c:
          break
        self.pos=bp
        self.block()

      self.pos=ep
    else:
      raise SyntaxError(
        f"Unexpected token {self.current_type()}")

  def expr(self):
    v=self.term()
    while self.current_type() in ('+','-'):
      op=self.current_type()
      self.pos+=1
      r=self.term()
      v=v+r if op=='+' else v-r
    return v

  def term(self):
    v=self.factor()
    while self.current_type() in ('*','/'):
      op=self.current_type()
      self.pos+=1
      r=self.factor()
      v=v*r if op=='*' else v//r
    return v

  def factor(self):
    t=self.current()
    if not t:
      raise SyntaxError("Unexpected EOF")
    if t.type=='NUMBER':
      self.pos+=1
      return t.value
    if t.type=='ID':
      self.pos+=1
      return self.vars.get(t.value,0)
    if t.type=='(':
      self.pos+=1
      v=self.expr()
      self.expect(')')
      return v
    raise SyntaxError(f"Unexpected token {t.type}")

source="""
BEGIN
LET X = 5
WHILE X
BEGIN
PRINT X
LET X = X - 1
END

PRINT 999
END
"""
Interpreter(source).program()

# Thanks to chatgpt.com for writing most of this code
