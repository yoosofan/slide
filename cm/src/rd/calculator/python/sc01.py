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
