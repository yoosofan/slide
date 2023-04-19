import re
def GetNumber(s):
    a = re.match('[0-9]+(\.[0-9]+)?', s)
    if a is None: raise 
    x = float(a.group())
    s = s[a.end():].strip()
    return s, x
def E(s):
    s, x = GetNumber(s)
    s = E_p(s)
    return s

def E_p(s):
    if len(s) > 0:
      if s[0] == '-':
        s, x = GetNumber(s[1:].strip())
        s = E_p(s)
      elif s[0] == '+':
        s, x = GetNumber(s[1:].strip())
        s = E_p(s)
      else: raise 'Error'
    return s
 
s = input('Enter ') # 12+35+2 No space or tab
try:
    s=E(s.strip())
    if len(s)>0:
      print('Error')
    else:
      print('success')
except:
    print('Error')
'''    
E → E + a | E - a | a

E → a E'
E' → + a E' | - a E' |λ
'''
