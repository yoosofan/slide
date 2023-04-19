import threading
def f1(j):
  for i in range(5):
    print(j,"__",i,"__This is a test")

if __name__ == "__main__":
  th1 = threading.Thread(target=f1,args=(1,))
  th2 = threading.Thread(target=f1,args=(2,))
  #for i in range(10):  print('OOOOO__',i)
  th1.start()
  #for i in range(10):  print('LLLLL__',i)
  th1.join()
  for i in range(10):
    print("iii__",i)
  th2.start()
  th2.join()
