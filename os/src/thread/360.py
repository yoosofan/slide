import threading, time
class MyShare:  
  counter = 0; end = 120;  array = [0] * end
def f1(sh1):
  sh1.array[0] = 1;
  for i in range(5000):pass #time.sleep(1)
  for i in range(5):  print("1_1_", i)
  for i in range(10000):pass
  for i in range(5):  print("1_2_", i)
  sh1.array[1] = 4;
def f2(sh2):
  sh2.array[2] = 8;
  for i in range(5000):pass #time.sleep(1)
  for i in range(5):  print("2_1_", i)
  for i in range(10000):pass
  for i in range(5):  print("2_2_", i)
  sh2.array[3] = 16;
myShare = MyShare()
th1 = threading.Thread(target=f1, args=(myShare,))
th2 = threading.Thread(target=f2, args=(myShare,))
th1.start(); th2.start(); #time.sleep(1)
for i in range(7): 
  for k in range(100000): pass
  print(myShare.array[i])
th1.join(); th2.join();
