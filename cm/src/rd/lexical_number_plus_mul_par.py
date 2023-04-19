import re
class tokenCls:
  def __init__(self, type1='EOF',  
      v1='', l1=0, b1=0, e1=0):
    self.type = type1
    self.begin = b1
    self.end = e1
    self.value = v1
    self.lineno = l1
  def __str__(self):
    return '[type: '+ str(self.type) + \
     ',\tvalue: ' + str(self.value) + \
     '\tline: ' + str(self.lineno) + \
     '\tbegin: ' + str(self.begin) + \
     '\tend: ' + str(self.end) + ']'
class lexical:
  def __init__(self, s):
    self.s = s
    self.begin = 0
    self.end = 0
    self.lineno = 0
    self.length = len(self.s)
    self.ct = tokenCls(b1=self.begin, 
      e1=self.end)
  def getToken(self):
    self.ct = tokenCls(b1=self.begin, 
      e1=self.end)
    self.begin = self.end
    while self.end < self.length:
      a = re.match('[ \t]+', self.s[self.end:])
      if a is not None:
        self.end = self.begin = self.end + a.end()
        if self.end >= self.length:
          break

      a = re.match('\d+(\.\d+)?', 
        self.s[self.end:])
      if a is None:
        self.end += 1
        operators1 = ['+', '-', '*', '/', '(', ')']
        if self.s[self.begin:self.end] in operators1:
          self.ct.type =  self.s[self.begin:self.end]
          break
        else:
          print('Lexical error: ', self.lineno, end=' : ')
          print(self.begin, ':', self.end, end=' , ')
          print('Unknown character:', self.s[self.begin:self.end])
          self.begin += 1
      else:
        self.ct.type = 'a'
        self.ct.value = float(a.group())
        self.end += a.end()
        break
    self.ct.begin = self.begin
    self.ct.end = self.end
    self.ct.lineno = self.lineno
    return self.ct
if __name__ == '__main__':
  #s = input('Enter ') # 12+35+2
  s = '12+35+2  '
  s = '  12  +  35 + 2   '
  s = '  12  +  35 --- 2   '
  # ~ s = '1.0.'  s = '1.0=23.2+4'
  s = '12+35+2  '
  lex1 = lexical(s);
  t1 = lex1.getToken()
  i = 0
  while t1.type != 'EOF':
    print(i, ': ', t1)
    t1 = lex1.getToken()
    i+=1
    # ~ if i > 9: break
  print(i, ': ', t1)

'''
except Exception as e1:
  print(type(e1))
  print(e1.args)
  print(e1)

def E(s):
  print('a + E\t\t::\t\t',s)
  a = re.match('[0-9]+(\.[0-9]+)?', s)
  if a is None:
    print('Error: need a number ', s)
    return False
  return B(s[a.end():]
def B(s):
  if len(s) > 0 and s[0] == '+':
    print('+E\t\t::\t\t',s)
    return E(s[1:])
  elif len(s) > 0:
    print('Error a a:', s[0])
    return False
  return True
#'12.1+35.45+2' No space or tab
s = input("Enter ")
try: print(E(s))
except: print('Unknown Error')

# calculator/python/
# wrong_grammar1_simple_calculator_2.py
'''