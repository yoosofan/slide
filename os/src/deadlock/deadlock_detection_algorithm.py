N = 100 # number of Processes
M = 200 # number of Resources
Available = [0] * M # array(M)
Allocation = [[0] * M] * N # array(N,M)
Request = [[0] * M] * N # array(N,M)
################################################
finish  = [False] * N #array(N)
work = Available.copy()
flag = True
for i in range(0, N):
  if all(k == 0 for k in Allocation[i]):
    finish[i] = True
################################################
while flag == True:
  flag = False
  for i in range(0, N):
    if finish[i] == False and all(k<=m for k, m in zip(Request[i], work)):
      finish[i] = True
      work = [x+y for x, y in zip(work, Allocation[i])]
      flag = True
################################################
deadlocked = [i for i in range(0, N) if finish[i] == False]
if len(deadlocked) !=0:
  print("The system is deadlocked")
else:
  print("The system is not deadlocked")
