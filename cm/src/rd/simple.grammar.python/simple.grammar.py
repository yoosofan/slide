# S --> AB
# A --> aA | b
# B --> ba
def A(s1):
	if s1[0]=='a': 
    s1=s1[1:]
    print('5: '+s1)
    s1=A(s1)
	elif s1[0]=='b': 
    s1=s1[1:]; 
    print('6: '+ s1);
	else: 
    print('Error 7: '+s1)
	return s1
def B(s1):
	if s1[0:2]=='ba': 
    s1=s1[2:]
    print('10 :'+s1)
  else: 
    print('Error 10' + s1)
	return s1
def S(s1):
	s1=A(s1)
	print('14: '+s1)
	s1=B(s1)
	if len(s1)>0: print('Error 16: '+s1)
	else: print('Accept ')

s1='aabba'
s1='aabbaq'
s1='ababbaq'
S(s1)
