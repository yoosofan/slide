import threading

def f1():
  print("In f1")

def f2():
  print("In f2");

if __name__ == "__main__":
  th1 = threading.Thread(target=f1)
  th2 = threading.Thread(target=f2)
  print("main")
  th1.start();
  print("After f1")
  th2.start();
  print("After f2")
