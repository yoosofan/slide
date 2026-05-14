import re, traceback as tb

class RegexMatch:

  def __init__(self, pattern):
    self.pattern = re.compile(pattern)
    self.match = None

  def __eq__(self, other):
    self.match = self.pattern.match(str(other))
    return self.match is not None

class Patterns:
    NUM = RegexMatch(r"[0-9]")

class yo_error(BaseException):
  def __init__(self,s, s2=''):self.s=s+str(s2)

class Lexical:
  def __init__(self, s = '4'):
    self.reset(s)

  def reset(self, s):
    self.ct = ['$', 0]; self.s = s
    self.index = 0; self.pi = 0

  def __str__(self):
      return f'i:{self.index}, '+\
        f'ct:{self.ct}, s:{self.s}'

  def getToken(self):
    res = ['$', 0]
    while self.index < len(self.s) \
        and s[self.index] in [' ', '\t']:
      self.index +=1
    if len(self.s) <= self.index:
      return res
    self.pi = self.index;
    match self.s[self.index]:
      case '+': res[0] = '+'
      case '-': res[0] = '-'
      case '*': res[0] = '*'
      case '/': res[0] = '/'
      case '(': res[0] = '('
      case ')': res[0] = ')'
      case Patterns.NUM:
        p = r'[0-9]+(\.[0-9]+)?'
        a = re.match(p,
          self.s[self.index:])
        res = ['n', float(a.group())]
        self.index += a.end() - 1;
      case _:
        raise yo_error('lexical:', self.s)
    self.index += 1
    self.ct = res
    return res

class Parser:
  def __init__(self, lex):
    self.lex = lex

  def F(self):
    x = 0
    match self.lex.ct[0]:
      case 'n': x=self.lex.ct[1]
      case '(':
        self.lex.getToken()
        x = self.E();
        if self.lex.ct[0] != ')':
          raise yo_error('):: ',self.lex)
      case _:
        raise yo_error('F()',
          self.lex)
    self.lex.getToken()
    return x;

  def E(self):
    x = self.T();
    while self.lex.ct[0] in ['+', '-']:
      p = self.lex.ct[0]
      self.lex.getToken()
      y = self.T();
      if p == '+': x += y
      else: x -= y;
    return x;

  def T(self):
    x = self.F();
    while self.lex.ct[0] in ['*', '/']:
      p=self.lex.ct[0]
      self.lex.getToken()
      y = self.F();
      if p == '*': x *= y
      else:        x /= y;
    return x;

def getInput():
  s = input('Enter>> ')
  return s.strip()

if __name__ == '__main__':
  lex = Lexical()
  parse=Parser(lex)
  while True:
    s = getInput(); lex.reset(s)
    if len(s.strip()) == 0 :break
    try:
      lex.getToken();
      print(parse.E());
    except yo_error as yo:
      print('yo_error ', yo.s);
    except Exception as e:
      dt=tb.format_exception(e)
      print("".join(td))
