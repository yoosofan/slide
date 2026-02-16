from threading import Semaphore, Thread
import time

full = Semaphore(1)

class MyShare:
  n = 0

def f1(sh1, j: int):
  i = 1
  while i < 999999999:
    full.acquire()# full.P()

    sh1.n = i
    i += 1
    print(j)
    print(j, '__first print')
    print(j, '__second print')
    print(j, '__third print')

    full.release()#full.V()
    #if i % 10000 == 0:
    #  time.sleep(0.01)

if __name__ == "__main__":
  sh1 = MyShare()
  th1=Thread(target=f1,args=(sh1, 1))
  th2=Thread(target=f1,args=(sh1, 2))
  th1.start()
  th2.start()
  th1.join()
  th2.join()
  print("counter ", sh1.n)
