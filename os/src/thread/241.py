import threading # src/thread/241.py
def f1():
  k = 0
  for i in range(1000000):
    for j in range(100000):
      k+=1
    print(i,"__111")

def f2():
  k = 0
  for i in range(1000000):
    for j in range(100000):
      k+=1
    print(i,"__222")

if __name__ == "__main__":
  k = 0
  th1 = threading.Thread(target=f1)
  th2 = threading.Thread(target=f2)
  th1.start();
  th2.start();
  for i in range(1000000):
    for j in range(100000):
      k+=1
    print(i, "__main")
