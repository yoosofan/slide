import re
class myExcept(Exception):
    def error(self):
        return 'Error program'
def GetNumber(s):
    a = re.match('[0-9]+(\.[0-9]+)?', s)
    if a is None: 
      print('error in get Number: ',s)
      raise myExcept()
    x = float(a.group())
    s = s[a.end():].strip()
    return s, x

def E(s):
    s, x = GetNumber(s)
    s = E_p(s)
    return s

def E_p(s):
    s = s.strip()
    if len(s) > 0:
      if s[0] == '-':
        s = s[1:].strip()
        s, x = GetNumber(s)
        s = E_p(s)
      elif s[0] == '+':
        s = s[1:].strip()
        s, x = GetNumber(s)
        s = E_p(s)
      else: 
        print('Error in E_p',s, ' ', len(s))
        raise  myExcept()
    return s
  
s = input('Enter ') # 12+35+2 No space or tab
try:
    s=E(s.strip())
    if len(s)>0:
      print('Error end', len(s))
    else:
      print('input is correct')
except  myExcept:
    print('Error between')
except:
    print('other')

