import re
def E(s):
    print('a + E\t\t::\t\t',s)
    a = re.match('[0-9]+(\.[0-9]+)?', s)
    if a is None: raise
    s = s[a.end():]
    if len(s) > 0 and s[0] == '+':
        print('+EE\t\t::\t\t',s)
        return E(s[1:])
    elif len(s) > 0:
      print('Error unknown token:', s[0])
      return False
    return True
s = input('Enter ') # 12.1+35.45+2 No space or tab
try:
    print(E(s))
except:
    print('Error')

