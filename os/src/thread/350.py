import threading , time
def f1(i):
  for j in range(10):
    for k in range(50):
      print(i, "__", j, "__", k, "__1__f1")
      print(i, "__", j, "__", k, "__2__f1")
    time.sleep(0.1);

th1 = threading.Thread(target=f1,args=(1,))
th2 = threading.Thread(target=f1,args=(2,))
th3 = threading.Thread(target=f1,args=(3,))
th1.start()
th2.start()
th3.start()
for k in range(10):
  for i in range(50):
    print(i, "__main_before");
    print(i, "__main_after");
  time.sleep(0.1);
th1.join()
th2.join()
th3.join()
