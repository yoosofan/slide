import re, traceback as tb
class Lexical:

  def getToken(self):
    i=self.index
    res = ['$', i];
    if len(self.s) <= i:
      return res
    self.pi = self.index
    c=self.s[self.index]
    if   c == '*': res[0]='*'
    elif c == '/': res[0]='/'
    elif c == '+': res[0]='+'
    elif c == '-': res[0]='-'
    elif c == '(': res[0]='('
    elif c == ')': res[0]=')'
    elif '0' <= c <= '9':
      p=r'[0-9]+(\.[0-9]+)?'
      a=re.match(p,self.s[i:])
      x = float(a.group())
      res=['n', x]
      self.index += a.end()-1
    else:
      raise Exception('UN:'+c)
    self.index += 1
    self.ct = res
    return res

  def __init__(self, s = '4'):
    self.ct=['$', 0]; self.s=s
    self.index=0; self.pi = 0

  def unget(self):
    self.index = self.pi

def F(lex):
  x = 0
  if lex.ct[0] == 'n':
    x = lex.ct[1];
  elif lex.ct[0] == '(':
    lex.getToken()
    x = E(lex);
    print(lex.ct)
    if lex.ct[0] != ')':
      raise Exception(')')
  else:
    raise Exception('F()', lex.ct[0])
  lex.getToken()
  return x;

def T(lex):
  x = F(lex);
  p = lex.ct[0]
  while p in ['*', '/']:
    lex.getToken()
    y = F(lex);
    if p == '*': x *= y
    else:        x /= y;
    p = lex.ct[0]
  return x;

def E(lex):
  x = T(lex);
  p = lex.ct[0]
  while p in ['+', '-']:
    lex.getToken()
    y = T(lex);
    if p == '+': x += y
    else: x -= y;
    p = lex.ct[0]
  return x;

def getInput():
  s = input('Enter>> ')
  return s.strip()

s = getInput()
while s != '':
  try:
    lex = Lexical(s)
    lex.getToken();
    print(E(lex));
  except Exception as e:
    d=tb.format_exception(e)
    print("".join(d))
  s=getInput()
