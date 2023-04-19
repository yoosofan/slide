import threading # src/thread/240.py
def f1():
  for i in range(10000):
    print(i,"__111")

def f2():
  for i in range(5000):
    print(i,"__222")

if __name__ == "__main__":
  th1 = threading.Thread(target=f1)
  th2 = threading.Thread(target=f2)
  th1.start();
  th2.start();
  for i in range(10000):
    print(i, "__main")
