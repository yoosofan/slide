from threading import Thread

def f1(j):
  for i in range(51):
    print(j,"_",i,"_ test")

if __name__ == "__main__":
  th1 = Thread(target=f1, args=(1,))
  th2 = Thread(target=f1, args=(2,))
  th1.start()
  th2.start()
  th1.join()
  th2.join()
