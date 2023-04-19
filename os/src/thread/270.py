import threading
def f1():
  for i in range(10000):
    print(i,"__111")

if __name__ == "__main__":
  th1 = threading.Thread(target=f1)
  th1.start();
  for i in range(10000):
    print(i, "__main")
  th1.join()
