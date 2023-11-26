class myMemory:
  def __init__(self):
    self.n=0;
    self.m=[]
  def newTemp(self,val=None):
    self.m.append(val)
    self.n+=1
    return self.n-1
  def __getitem__(self,index):
    return self.m[index]
  def __setitem__(self,index,val):
    self.m[index]=val

mem1=myMemory()
mem1.newTemp(2)
mem1.newTemp(4)
print(mem1[0])
mem1[0]=6
print(mem1[0])
