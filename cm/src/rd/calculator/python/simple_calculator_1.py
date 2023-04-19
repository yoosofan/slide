import re
def E(s1):
  [s1,x]=T(s1)
  while len(s1)>0 and (s1[0]=='+' or s1[0]=='-'):
    if s1[0]=='+': flag=True 
    else: flag=False;
    [s1,y]=T(s1[1:])
    if flag==True: x+=y;      
    else: x-=y
  return [s1,x]
def T(s1):
  [s1,x]=f(s1)
  while len(s1)>0 and (s1[0]=='*' or s1[0]=='/'):
    if s1[0]=='*': flag=True;     
    else: flag=False;
    [s1,y]=f(s1[1:])
    if flag==True: x*=y;          
    else: x/=y
  return [s1,x]
def f(s1):
  if s1[0]=='(': s1=s1[1:];[s1,x]=E(s1);s1=s1[1:];return [s1,x] 
  else:
    a=re.match('[0-9]+(\.[0-9]+)?',s1)
    s1=s1[a.end():]
    return [s1,float(a.group())]
st='1'; st=input('Enter >> ');#st='12+35-2'
while st!="":[s1,val]=E(st);print(val);st=input('Enter >> ');#st='12+35-2'
