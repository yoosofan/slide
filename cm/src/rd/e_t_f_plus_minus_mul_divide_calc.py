import re

def E(s1):
  [s1, x]=T(s1)
  while len(s1) > 0 and \
      (s1[0] == '+' or s1[0] == '-'):
    if s1[0]=='+': 
      flag = True 
    else: 
      flag = False;
    [s1, y] = T(s1[1:])
    if flag == True: 
      x += y;      
    else: 
      x -= y
  return [s1, x]

def T(s1):
  [s1, x] = F(s1)
  while len(s1) > 0 and \
      (s1[0] == '*' or s1[0] == '/'):
    if s1[0] == '*': 
      flag = True;     
    else: 
      flag = False;
    [s1, y] = F(s1[1:])
    if flag == True: 
      x *= y;          
    else: 
      x /= y
  return [s1, x]

def F(s1):
  if s1[0] == '(': 
    s1 = s1[1:]
    [s1, x] = E(s1)
    if len(s1) == 0 or s1[0] != ')':
      print('Error: ) missing')
      raise
    s1 = s1[1:]
    return [s1, x] 
  else:
    a = re.match('[0-9]+(\.[0-9]+)?', s1)
    s1 = s1[a.end():]
    return [s1, float(a.group())]

st = input('Enter >> ') #st='12+35-2'
while st != "":
  try:
    [s1, val] = E(st)
    print(val)
  except:
    print('Error')
  st = input('Enter >> ') #st='12+35-2'