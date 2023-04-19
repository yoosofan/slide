def P_0(sh1):
  for i in range(1000):
    print("P_0 before Entry: ", sh1.turn)

    sh1.need[0] = True
    sh1.turn = 1
    while sh1.need[1] == True and sh1.turn == 1:
      pass

    print("P_0 after Entry: ", sh1.turn)
    for j in range(5000): pass
    print("\t Critical Section of P_0 first")
    for j in range(5000): pass
    print("\t Critical Section of P_0 second")
    for j in range(5000): pass
    print("P_0: Before Exit")

    sh1.need[0] = False

    print("P_0: After Exit")
    for j in range(1000): pass
    print("Reminder Section")
    for j in range(10000): pass

def P_1(sh1):
  for i in range(1000):
    print("P_1 before Entry: ", sh1.turn)

    sh1.need[1] = True
    sh1.turn = 0
    while sh1.need[0] == True and sh1.turn == 0:
      pass

    print("P_1 after Entry: ", sh1.turn)
    for j in range(5000): pass
    print("\t Critical Section of P_1 first")
    for j in range(5000): pass
    print("\t Critical Section of P_1 second")
    for j in range(5000): pass
    print("P_1: Before Exit")

    sh1.need[1] = False

    print("P_1: After Exit")
    for j in range(1000): pass
    print("Reminder Section")
    for j in range(10000): pass

import threading, time
class MyShare:
  turn = 0
  need = [False, False]

def P_i(sh1):
  i, j = 0, 1
  for k in range(1000):
    sh1.need[i] = True
    sh1.turn = j
    while sh1.need[j] == True and sh1.turn == j:
      pass

    print("Critical Section")

    sh1.need[0] = False
    
    print("Reminder Section")

sh1 = MyShare()
th1 = threading.Thread(target=P_0, args=(sh1,))
th2 = threading.Thread(target=P_1, args=(sh1,));
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
