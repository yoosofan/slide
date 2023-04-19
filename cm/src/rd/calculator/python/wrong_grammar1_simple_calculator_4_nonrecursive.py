import re
def GetNumber(s):
    a = re.match('[0-9]+(\.[0-9]+)?', s)
    if a is None: raise 
    x = float(a.group())
    s = s[a.end():]
    return s, x
def E(s):
    s, x = GetNumber(s)
    while len(s) > 0 and s[0] == '+':
        s , x2 = GetNumber(s[1:])
        x += x2
    return x
s = input('Enter ') # 12+35+2 No space or tab
try:
    print(E(s))
except:
    print('Error')
