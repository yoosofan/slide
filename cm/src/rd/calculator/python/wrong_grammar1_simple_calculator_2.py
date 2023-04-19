import re
def E(s):
    a = re.match('[0-9]+(\.[0-9]+)?', s)
    if a is None: raise 
    x = float(a.group())
    s = s[a.end():]
    if len(s) > 0 and s[0] == '+':
        return x + E(s[1:])
    return x
s = input('Enter ') # 12+35+2 No space or tab
try:
    print(E(s))
except:
    print('Error')
