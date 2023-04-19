# Python 3   only
from threading import *; import time;
N=3;
class MyShare:counter = 0; z1= [-1]*3;buf = [z1] * N
full = Semaphore(0);empty = Semaphore(N)
class MyLog:
  def produce1(self,i):
    print('(produce_',end="",flush=True);
    print(i,end="",flush=True);
  def produce2(self,y,i):
    print(y,end="",flush=True);
    print(i,')',end="::",flush=True);
  def consume(self,x,i):
    print('(consume_',end="",flush=True);
    print(i,end=",",flush=True);
    print(x,end=",",flush=True);
    print(')',end="::",flush=True)
  def producer1(self,i):
    print(i,'{producer-before',end="::",flush=True);
  def producer2(self,i):
    print('Proudecer-',end="",flush=True);
    print('After',end="",flush=True);
    print(' ',i,'}',flush=True);
  def consumer1(self,i):
    print('{Consumer--',end="",flush=True);
    print('before ',end=" ",flush=True);
    print(i,end=" :: ",flush=True);
  def consumer2(self,i):
    print('Consumer--',end="",flush=True);
    print('After:',end="",flush=True);
    print(i,end="",flush=True);
    print('}',flush=True);
lg=MyLog();
def produce(i):
  import random
  lg.producer1(i);
  lg.produce1(i);
  y=[(i+1)%100]*(i%N+2);
  lg.produce2(y,i);
  if random.randint(0,i)%(N+5)==0: 
    time.sleep(random.random())
  return y;
def consume(x,i):
  import random;
  lg.consume(x,i);
  lg.consumer2(i)
  if random.randint(0,i)%(N+4)==0:
    time.sleep(random.random());
def producer(sh1):
  in1 = 0
  for i in range(100):
    x=produce(i);
    empty.acquire();     sh1.buf[in1] = x;     full.release();
    in1 = (in1 + 1)% N; lg.producer2(i)
def consumer(sh1):
  out =0
  for i in range(100):
    lg.consumer1(i);
    full.acquire();    x = sh1.buf[out] ;   empty.release();
    out = (out +1) % N ;    consume(x,i);
myShare = MyShare()
th1 = Thread(target=consumer,args=(myShare,))
th2 = Thread(target=producer,args=(myShare,))
th1.start();th2.start();th1.join();th2.join()
print('main --',end=" :: ",flush=True)
for i in range(N):  print(myShare.buf[i],end=" :: ",flush=True)
print("counter ",myShare.counter,flush=True)
