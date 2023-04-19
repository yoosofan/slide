import re;
class error(BaseException):
  def __init__(self,s):self.s=s;
class Lexical:
  def __init__(self,s='4+5'):self.ct=['$',0];self.s=s;self.index=0;self.pi=0;print(self.s);
  def getToken(self): 
    res=[]; self.pi=self.index;
    if   len(self.s)==self.index: res=['$',0]
    elif self.s[self.index] in '*/+-()':res=[self.s[self.index],0]
    elif '0' <= self.s[self.index] <= '9':
      a=re.match('[0-9]+(\.[0-9]+)?',self.s[self.index:]);
      res=['n',float(a.group())]; self.index+=a.end()-1;
    else: raise error('lexical error ')
    self.index+=1; self.ct=res;print(self.ct);return res;
  def unget(self):    self.index=self.pi;
def E(lex):
  x=T(lex);
  while lex.ct[0] in '+-':
    p=lex.ct[0];lex.getToken();y=T(lex);
    if p=='+':x+=y;
    else:     x-=y;
  return x;
def T(lex):
  x=F(lex);
  while lex.ct[0] in '*/':
    p=lex.ct[0];lex.getToken();y=F(lex);
    if p=='*': x*=y;
    else:      x/=y;
  return x;
def F(lex):
  x=0;
  if lex.ct[0]=='n': x=lex.ct[1];
  elif lex.ct[0]=='(':
    lex.getToken(); x=E(lex) 
    if lex.ct[0] != ')': raise error(' ) is missing ')
  else: raise error(' Error in F ');
  lex.getToken(); return x;
s=input('Enter >> ');
while s!='':
  try:    lex=Lexical(s);lex.getToken();print(E(lex));
  except: print('Error Input');
  s=input('Enter >> ')
