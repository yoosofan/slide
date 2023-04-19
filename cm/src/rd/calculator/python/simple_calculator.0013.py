import re
def GetNumber(s):
    a = re.match('[0-9]+(\.[0-9]+)?', s)
    if a is None: raise 
    x = float(a.group())
    s = s[a.end():].strip()
    return s, x
def E(s):
    s, x = GetNumber(s)
    while len(s) > 0 and (s[0] == '-' or s[0] == '+'):
      if s[0] == '-':
        s, x2 = GetNumber(s[1:].strip())
        x -= x2
      elif s[0] == '+':
        s, x2 = GetNumber(s[1:].strip())
        x += x2
      else: raise 'Error'
    return s, x
 
s = input('Enter ') # 12+35+2 No space or tab
try:
    s, x=E(s.strip())
    if len(s)>0:
      print('Error: ',s)
    else:
      print('success: ', x)
except:
    print('Error')
'''    
E → E + a | E - a | a

E → a E'
E' → + a E' | - a E' |λ
'''
