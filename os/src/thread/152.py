import threading

def f1():
  print("This is a test")

print("main")
th1 = threading.Thread(target=f1)
th1.start()
print("After th1.start()")
