# 30 state machine
import re
class lexical:
  def __init__(self, s):
    self.s = s.strip();
    self.t1 = ['EOF',]
  def getToken(self):
    self.t1 = ['unknown',]
    self.s = self.s.strip();
    if len(self.s) > 0:
      a = re.match('[0-9]+(\.[0-9]+)?', self.s)
      if a is None:
        if self.s[0] == '+':
          self.s = self.s[1:]
          self.t1 = ['+', ]
        elif self.s[0] == '-':
          self.s = self.s[1:]
          self.t1 = ['-', ]
        elif self.s[0] == '*':
          self.s = self.s[1:]
          self.t1 = ['*', ]
        elif self.s[0] == '/':
          self.s = self.s[1:]
          self.t1 = ['/', ]
      else:
        x = float(a.group())
        self.s = self.s[a.end():]
        self.t1 = ['number', x]
    else:
      self.t1 = ['EOF',]
    return self.t1

def E(lex1):
  x = T(lex1)
  t1 = lex1.t1
  print(t1)
  if t1[0] == '+':
    x += E(lex1)
  elif t1[0] == '-':
    x -= E(lex1)
  return x

def T(lex1):
  x = 0
  t1 = lex1.getToken()
  if t1[0] == 'number':
    x = t1[1]
    t1 = lex1.getToken()
    if t1[0] == '*':
      x *= T(lex1)
    elif t1[0] == '/':
      x /= T(lex1)
  return x

def S(lex1):
  return E(lex1)

s = input('Enter ') # 12+35+2 No space or tab
lex1 = lexical(s);
try:
  print(S(lex1))
except Exception as e1:
  print(type(e1))
  print(e1.args)
  print(e1)

'''    
E → a + E | a
'''
