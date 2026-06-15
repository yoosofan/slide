def P(i, sh1):
  for m in range(1000):
    print("P_0 before Entry: ", sh1.turn)

    sh1.need[0] = True
    sh1.turn = 1
    while sh1.need[1] == True and sh1.turn == 1:
      pass

    print("P_", i, " after Entry: ", sh1.turn)
    for m in range(5000): pass
    print("\t Critical Section of P_", i, " first")
    for m in range(5000): pass
    print("\t Critical Section of P_", i, " second")
    for m in range(5000): pass
    print("P_", i, ": Before Exit")

    sh1.need[0] = False

    print("P_", i, ": After Exit")
    for m in range(1000): pass
    print("Reminder Section")
    for m in range(10000): pass

import threading, time
class MyShare:
  turn = 0
  need = [False, False]

sh1 = MyShare()
th1 = threading.Thread(target=P, args=(0, sh1,))
th2 = threading.Thread(target=P, args=(1, sh1,));
th1.start();th2.start();

for i in range(10):
  for j in range(1000): pass
  print("main before 55: ", sh1.turn)
  for j in range(1000): pass
  sh1.turn = 55
  for j in range(1000): pass
  print("main after 55: ", sh1.turn)
  for j in range(1000): pass
  sh1.turn = 88
  for j in range(1000): pass
  print("main after 88: ", sh1.turn)
  for j in range(1000): pass

th1.join();th2.join();
