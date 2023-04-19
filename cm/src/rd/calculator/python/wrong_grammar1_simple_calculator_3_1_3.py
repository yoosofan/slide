import re
class lexical:
  def __init__(self, s):
    self.s = s.strip();
  def getToken(self):
    self.s = self.s.strip();
    if len(self.s) > 0:
      a = re.match('[0-9]+(\.[0-9]+)?', self.s)
      if a is None:
        if self.s[0] == '+':
          self.s = self.s[1:]
        return ['+', ]
      else:
        x = float(a.group())
        self.s = self.s[a.end():]
        return ['number', x]
    else:
      return ['EOF',]
    return ['unknown',]

def E(lex1):
  t1 = lex1.getToken()
  if t1[0] == 'number':
    x = t1[1]
    t1 = lex1.getToken()
    if t1[0] == '+':
      x += E(lex1)
  else:
    print('Number must be at the input')
    print('input: ', lex1.s)
    raise
  return x

s = input('Enter ') # 12+35+2 No space or tab
lex1 = lexical(s);
try:
  print(E(lex1))
except Exception as e1:
  print(type(e1))
  print(e1.args)
  print(e1)

'''    
E → a + E | a
'''
