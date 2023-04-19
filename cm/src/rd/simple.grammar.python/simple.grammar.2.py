# S --> AB  # A --> aA | b # B --> ba
class Lexical:
	def __init__(self,s1='aabba'):	
    self.s1=s1
    self.index=0
	def gnx(self): 
		if len(self.s1)>=self.index:
			retVal=self.s1[self.index]
      self.index+=1; 	return retVal;
		else: raise 'lexical error '
		# return None
	def unget(self):	self.index-=1;
	def iseos(self): 
		if self.index==len(self.s1): return True
		else: return False;
		#
def A(lx1):
	s1=lx1.gnx()
	if s1=='a': A(lx1)
	elif s1=='b': pass
	else: print('Error 7: '+s1)
def B(lx1):
	s1=lx1.gnx()
	if s1=='b':
		s1=lx1.gnx()
		if s1=='a':		pass
		else:		lx1.unget();lx1.unget();
	else:		lx1.unget();
def S(lx1):	A(lx1);	B(lx1)
s1='aabba'; s1='aabbaq';s1='ababbaq'
#s1+='$'
lx1=Lexical()
S(lx1)
if lx1.iseos()==False: print('Error 16: '+s1)
else: print('Accept ')
