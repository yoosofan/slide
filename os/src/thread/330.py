from threading import Thread
def f1(j):
  for i in range(500):
    print(j,"_",i,"_ test")

if __name__ == "__main__":
  th1 = Thread(target=f1,args=(1,))
  th2 = Thread(target=f1,args=(2,))
  #for i in range(10): print('O_',i)
  th1.start()
  #for i in range(10): print('L_',i)
  th1.join()
  for i in range(400):
    print("iii__",i)
  th2.start()
  th2.join()
