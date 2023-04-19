import threading
def f1():
  for i in range(51):
    print(i,"__This is a test")

def f2():
  for i in range(50):
    print(i,"__The second function is called");

if __name__ == "__main__":
  th1 = threading.Thread(target=f1)
  th2 = threading.Thread(target=f2)
  th1.start()
  th2.start()
  th1.join()
  th2.join()
  for i in range(1):
    print(i, "__In main");

