..  section-numbering::

===================================================
Process Synchronization
===================================================


Software solution for 2 process
========================================================================================

Shared code

.. code:: cpp

    bool need[2]={false, false};
    int turn = 0;

Pi (P0)

.. code:: cpp

    need[i] = true;
    while(need[j] == true && turn == i)
      ;

    CS

    need[i] = false;
    turn = j;

Pj (P1)

.. code:: cpp

    need[j] = true;
    while(need[i] == true && turn == j)
      ;

    CS

    need[j] = false;
    turn = i;

Trace

.. code:: sh

    p0-1
    p0-3
    p1-1
    p1-2
    p0-4
    p1-1
    ...

    p0-5
    p1-3


+---------------------------------------------------------+
| .. code:: cpp                                           |
|     :number-lines:                                      |
|                                                         |
|     // Shared section                                   |
|     int turn = 1;                                       |
|     bool need[2] = {false, false};                      |
+----------------------------+----------------------------+
| .. code:: cpp              | .. code:: cpp              |
|     :number-lines:         |     :number-lines:         |
|                            |                            |
|     void P0(){             |     void P1(void){         |
|       do{                  |       do{                  |
|         need[0] = true;    |         need[1] = true;    |
|         turn = 1;          |         turn = 0;          |
|         while(need[1]==true|         while(need[0]==true|
|               && turn == 1)|               && turn == 0)|    
|             ;              |             ;              |
|                            |                            |
|         // Critical Section|         // Critical Section|
|                            |                            |
|         need[1] = false;   |         need[0] = false;   |
|                            |                            |
|         // Reminder Section|         // Reminder Section|
|                            |                            |
|      }while(true);         |      }while(true);         |
+----------------------------+----------------------------+

.. code:: cpp
   :number-lines:

    // Share section
    int number[n] = {0};
    bool choose[n]= {false};

    // Each process
    number[i]=max(number,n)+1;
    for(j=(i+1)%n;j!=i;j=(j+1)%n){
      while((number[i]>number[j]
           && number[j]!=0) ||
           ((number[i]==number[j])
           && i<j  ) );
    /* Critical Section */
    number[i] = 0;
    //

.. code:: cpp
   :number-lines:

    // Share section
    int number[3] = {0};
    bool choose[3]= {false};

    // P0
    t=max(number,3);
    number[0]=t+1;
    for(j=(0+1)%3;j!=0;j=(j+1)%3){
      while((number[0]>number[j] && number[j]!=0)||((number[0]==number[j])&& 0<j));
    /* Critical Section */
    number[0] = 0;

    // P1
    t=max(number,3);
    number[1]=t+1;
    for(j=(1+1)%n;j!=1;j=(j+1)%n){
      while((number[1]>number[j] && number[j]!=0)||((number[1]==number[j])&& 1<j));
    /* Critical Section */
    number[1] = 0;

    // P2
    t=max(number,3);
    number[2]=t+1;
    for(j=(2+1)%3;j!=2;j=(j+1)%3){
      while((number[2]>number[j] && number[j]!=0)||((number[2]==number[j])&& 2<j));
    /* Critical Section */
    number[2] = 0;

.. csv-table::

    P0-6 (number[0]==0), P1-16 (number[1]== 1), P2-24 (number[2]== 2), P1-19 (number[1] == 0), P2-26 (number[2] == 2), P0-8 (number[0] == 1), P0-10 (number[0] == 1)


Mutual exclusion violation



.. code:: cpp

    int number[n] = {0};
    bool choose[n]= {false};

.. code:: cpp

    choose[i]=true;
    number[i]=max(number,n)+1;
    choose[i]=false;
    for(j=(i+1)%n;j!=i;j=(j+1)%n){
      while(choose[j]==true)
          ;
      while((number[i]>number[j]
           && number[j]!=0) ||
           ((number[i]==number[j])
           && i<j  ) );
    /* Critical Section */
    number[i] = 0;
    //

Hardware
========================================================================================

.. code:: cpp

    // Share section
    bool lock=false;

    // Each process
    while(testAndSet(lock))
          ;

          // CRITICAL SECTION

    lock=false;


.. code:: cpp
    :number-lines:

    // P0
    do{
      while(TS(lock))
        ;
      // CS
      lock = false;
      // RS
    }while(1);

    // P1
    do{
      while(TS(lock))
        ;
      // CS
      lock = false;
      // RS
    }

    // P2
    do{
      while(TS(lock))
        ;
      // CS
      lock = false;
      // RS
    }

.. csv-table::

    P0-3 , P1-12 , P2-21
    P0-3 , P1-14 , P2-21
    P0-3 , P1-16 , P2-21
    P0-3 , P1-16 , P2-23
    P0-3 , P1-12 , P2-23
    P0-3 , P1-12 , P2-25
    P0-3 , P1-14 , P2-25
    P0-3 , P1-14 , P2-21
    P0-3 , P1-16 , P2-21
    P0-3 , P1-16 , P2-23
    P0-3 , P1-12 , P2-23
    `....` , `....`  , `....`

P0 : starvation


.. code:: cpp

    // Share section
    const int n=20;
    bool waiting[n]={false, ... , false};
    bool lock=false;

    do{
      waiting[i] = true;
      bool key=true;
      while(waiting[i] && key)
         key=testAndSet(lock);
      waiting[i]=false;

      // CRITICAL SECTION

      int j=(i+1)%n;
      while((j!=i) && !waiting[j])
         j=(j+1)%n;
      if(j==i)  lock=false;
      else      waiting[j]=false;

      // REMINDER SECTION

    }while(1);



Semaphore
========================================================================================


First semaphore implementation with busy waiting
----------------------------------------------------------------------------------------------------

.. code:: cpp

    class Semaphore{
      int s;
      public:
      Semaphore(int n){s=n;}
      P(void){
        while(s<=0)
          ;
        s--;
      }

      V(void){
        s++;
      }
    }
    
    
    // Shared section
    Semaphore mutex=1;
    
    // Each process use the following structure for CS
    void f(void){
      mutex.P();

      // CS

      mutex.V();
    }


Second semaphore implementation without busy waiting
----------------------------------------------------------------------------------------------------

.. code:: cpp

    class semaphore{
       int s; myIntQueue q;
      public:
       void P(){
         s--;
         if(s<0){
           q.add(OS_getMyProcessPID());
           OS_block_me(); // get cpu from me and do not add me to ready queue
         }
       }
       void V(void){
         s++;
         if(s<=0){
           int i=q.del(); // remove and return first element of queue
           OS_wakeup_process(i); // add process number i (PID==i) to ready queue, so it can be run
         }
       }
       semaphore(int i=1){s=i;}
    };

external functions and class for semaphore
----------------------------------------------------------------------------------------------------

.. code:: cpp

    bool testAndSet(bool &target){
       bool rv=target;
       target=true;
       return rv;
    }
    class myIntQueue {
      private:
        int bufferOfQueue[MAX_NUMBER_WAIT_PROCESS_FOR_A_SEMAPHORE];
        int first,last;

      public:
        myIntQueue(){first=last=0;}
        int add(int i){
          bufferOfQueue[last]=i;
          last=(last+1)%MAX_NUMBER_WAIT_PROCESS_FOR_A_SEMAPHORE ;
          return i;
        }
        int del(void){
          int i=bufferOfQueue[first];
          first=(first+1)%MAX_NUMBER_WAIT_PROCESS_FOR_A_SEMAPHORE ;
          return i;
        }
    };
    void OS_wakeup_process(int pid){} // add process number i (PID==i) to ready queue, so it can be run
    void OS_block_me(void){} // get cpu from me and do not add me to ready queue
    int OS_getMyProcessPID(void){return 1;}


Third semaphore implementation using hardware mutual exclusion in P and V
----------------------------------------------------------------------------------------------------

.. code:: cpp


    class semaphore{
       int s; myIntQueue q; bool lock;
      public:
       void P(){
          while(testAndSet(lock))  ;
          s--;
          if(s<0){
            q.add(OS_getMyProcessPID());
            lock=false;
            OS_block_me();
          }else lock=false;
       }
       void V(void){
          while(testAndSet(lock))  ;
          s++;
          if(s<=0){
             OS_wakeup_process(q.del());
          }
          lock=false;
       }
       semaphore(int i){s=i;lock=false;}
    };


//shared section
semaphore mutex=1;

Pi

mutex.P();

//   Critical Section

mutex.V()



semaphore sem_printer=1, sem_scanner=1;


sem_printer.P();

// work with printer

sem_printer.V();


....

sem_scanner.P();

// Work with scanner

sem_sanner.V();

===========

ready queue


// shared between os process
semaphore sem_ready_queue=1;


sem_ready_queue.P();

// work ready queue


sem_ready_queue.V();






fourth semaphore implementation without starvation
----------------------------------------------------------------------------------------------------

.. code:: cpp

    class semaphore{
       int s; myIntQueue q; bool lock; bool waiting[n];int numberOfWaitProcess;
       public:
       void P(){
          int i = OS_getMyProcessPID();
          waiting[i] = true;
          bool key=true;
          while(waiting[i] && key)
             key=testAndSet(lock);
          waiting[i]=false;

          s--;
          if(s<0){
            q.add(OS_getMyProcessPID());

          int j=(i+1)%n;
          while((j!=i) && !waiting[j])
             j=(j+1)%n;
          if(j==i)  lock=false;
          else      waiting[j]=false;

          OS_block_me();
          }
         else{
            int j=(i+1)%n;
            while((j!=i) && !waiting[j])
               j=(j+1)%n;
            if(j==i)  lock=false;
            else      waiting[j]=false;
          }
       }
       void V(void){
          int i = OS_getMyProcessPID();
          waiting[i] = true;
          bool key=true;
          while(waiting[i] && key)
             key=testAndSet(lock);
          waiting[i]=false;

          s++;
          if(s<=0){
            int i=q.del();
             OS_wakeup_process(i);
          }

          int j=(i+1)%n;
          while((j!=i) && !waiting[j])
             j=(j+1)%n;
          if(j==i)  lock=false;
          else      waiting[j]=false;

       }
       semaphore(){
         s=0;
         numberOfWaitProcess=0;
         for(int i=0;i<n;i++)waiting[i]=false;
         lock=false;
       }
       semaphore(int i){
         value=i;
         numberOfWaitProcess=0;
         for(int i=0;i<n;i++)waiting[i]=false;
         lock=false;
       }

Produces consumer unbounded buffer semaphore
========================================================================================

.. code:: cpp

    class ObjectCls{int a; int b ; double x;};

    Object buffer[9000];
    semaphore full = 0 ;

    void producer(void){
        Object temp;
        int in = 0;
        do{
            x = produce();
            buffer[in] = x;
            full.V();
            in ++;
        }while(1);
    }
    void consumer(void){
        Object temp;
        int out = 0;
        do{
            full.P();
            temp = buffer[out];
            out ++;
        }while(1);
    }
    int main(){
       producer();
       consumer();
       return 0;
    }


producer consumer semaphore bounded buffer
========================================================================================

.. code:: cpp

    struct ObjectCls{int a; int b ; double x;};
    ObjectCls produce(void){ObjectCls x; x.a = 1; return x;}
    void consume(ObjectCls){}
    const int N=100;
    ObjectCls buffer[N];
    semaphore full = 0 ;
    semaphore empty=N

    void producer(void){
        ObjectCls x;
        int in = 0;
        do{
            x = produce();
            empty.P();
            buffer[in] = x;
            full.V();
            in = (in+1)%N;
        }while(1);
    }
    void consumer(void){
        ObjectCls x;
        int out = 0;
        do{
            full.P();
            x = buffer[out];
            empty.V();
            out = (out + 1) % N;
            consume(x);
        }while(1);
    }
    int main(){
       producer();
       consumer();
       return 0;
    }

Python producer consumer semaphore
========================================================================================


.. code::python

    #import threading, time
    from threading import *
    class MyShare:
      counter = 0; n = 10;buf = [-1] * n
    full = Semaphore(0);empty= Semaphore(10)
    def produce(x,i):print('produce ',(x+1)%100,i);return (x+1)%100
    def consume(x,i):print('consume ',x,i)
    def producer(sh1):
        x = -1;    in1 = 0
        for i in range(50):
            x = produce(x,in1)
            empty.acquire();
            sh1.buf[in1] = x
            in1 = (in1 + 1)%sh1.n
            full.release();
    def consumer(sh1):
        out =0; x=0
        for i in range(50):
            full.acquire()
            x=sh1.buf[out];sh1.buf[out]=-1;out=(out +1)%sh1.n
            empty.release()
            consume(x,out)
    myShare = MyShare()
    th1 = Thread(target=consumer,args=(myShare,))
    th2 = Thread(target=producer,args=(myShare,))
    th1.start();th2.start();th1.join();th2.join()
    for i in range(4):  print(myShare.buf[i])
    print("counter ",myShare.counter)


.. code:: python

    from threading import *; import time;
    class MyShare:counter = 0; n = 10;z1= [-1]*5;buf = [z1] * n
    full = Semaphore(0);empty = Semaphore(10)
    def produce(i):y=[(i+1)%12]*(i%10+2);print(i,'__produce=',y);return y;
    def consume(x,i):print(i,'__consume=',x)
    def producer(sh1):
      in1 = 0
      for i in range(450):
        print(i,' before produce');      x=produce(i);
        if i%20==0: time.sleep(0.1)
        empty.acquire();     sh1.buf[in1] = x;     full.release();
        print(i, 'After put in buffer'); in1 = (in1 + 1)%sh1.n
    def consumer(sh1):
      out =0
      for i in range(450):
        print(i,' before get from buffer');
        if i%25==0:time.sleep(0.1);
        full.acquire();    x = sh1.buf[out] ;   empty.release();
        out = (out +1) % sh1.n ;    consume(x,i); print(i,' After consume');
    myShare = MyShare()
    th1 = Thread(target=consumer,args=(myShare,))
    th2 = Thread(target=producer,args=(myShare,))
    th1.start();th2.start();th1.join();th2.join()
    for i in range(4):  print(myShare.buf[i])
    print("counter ",myShare.counter)


.. code:: python

    # Python 3   only
    from threading import *; import time;
    class MyShare:counter = 0; n = 10;z1= [-1]*5;buf = [z1] * n
    full = Semaphore(0);empty = Semaphore(10)
    def produce(i):y=[(i+1)%100]*(i%10+2);print(i,'__produce=',y,end=" :: ",flush=True);return y;
    def consume(x,i):print(i,'__consume=',x,end=" :: ",flush=True)
    def producer(sh1):
      in1 = 0
      for i in range(150):
        print(i,' before produce',end=" :: ",flush=True);      x=produce(i);
        if i%12==0: time.sleep(0.1)
        empty.acquire();     sh1.buf[in1] = x;     full.release();
        print(i, 'After put in buffer',flush=True); in1 = (in1 + 1)%sh1.n
    def consumer(sh1):
      out =0
      for i in range(150):
        print(i,' before get from buffer',end=" :: ",flush=True);
        if i%13==0:time.sleep(0.1);
        full.acquire();    x = sh1.buf[out] ;   empty.release();
        out = (out +1) % sh1.n ;    consume(x,i); print(i,' After consume',flush=True);
    myShare = MyShare()
    th1 = Thread(target=consumer,args=(myShare,))
    th2 = Thread(target=producer,args=(myShare,))
    th1.start();th2.start();th1.join();th2.join()
    print('main --',end=" :: ",flush=True)
    for i in range(4):  print(myShare.buf[i],end=" :: ",flush=True)
    print("counter ",myShare.counter,flush=True)


.. code:: python

    # Python 3   only
    from threading import *; import time;
    class MyShare:counter = 0; n = 10;z1= [-1]*5;buf = [z1] * n
    full = Semaphore(0);empty = Semaphore(10)
    def produce(i):
      print('(pro_',end="",flush=True);print(i,end="",flush=True);
      y=((i+1)%100)*(i%6+2);
      print(y,end="",flush=True);
      print(')',end=":: ",flush=True);
      return y;
    def consume(x,i):
      print('(con_',end="",flush=True);
      print(i,end=",",flush=True)
      print(x,end=",",flush=True)
      print(')',end=":: ",flush=True)
    def producer(sh1):
      in1 = 0
      for i in range(150):
        print(i,'{pro ',end=":: ",flush=True);    x=produce(i);
        if i%12==0: time.sleep(0.1)
        empty.acquire();     sh1.buf[in1] = x;     full.release();
        print('Pro ',end="",flush=True);
        print('After',end="",flush=True);
        print('}',end="",flush=True);
        in1 = (in1 + 1)%sh1.n
        print(flush=True);
    def consumer(sh1):
      out =0
      for i in range(150):
        print('{Con ',end="",flush=True);
        print('before ',end=" ",flush=True);
        print(i,end=" :: ",flush=True);
        if i%13==0:time.sleep(0.1);
        full.acquire();    x = sh1.buf[out] ;   empty.release();
        out = (out +1) % sh1.n ;    consume(x,i);
        print('Con',end="",flush=True);
        print('After:',end="",flush=True);
        print(i,end="",flush=True);
        print('}',flush=True);
    myShare = MyShare()
    th1 = Thread(target=consumer,args=(myShare,))
    th2 = Thread(target=producer,args=(myShare,))
    th1.start();th2.start();th1.join();th2.join()
    print('main --',end=" :: ",flush=True)
    for i in range(4):  print(myShare.buf[i],end=" :: ",flush=True)
    print("counter ",myShare.counter,flush=True)


.. code::python

    # Python 3   only
    from threading import *; import time;
    class MyShare:counter = 0; n = 4;z1= [-1]*3;buf = [z1] * n
    full = Semaphore(0);empty = Semaphore(4)
    class MyLog:
      def produce1(self,i):
        print('(produce_',end="",flush=True);
        print(i,end="",flush=True);
      def produce2(self,y,i):
        print(y,end="",flush=True);
        print(i,')',end=":: ",flush=True);
      def consume(self,x,i):
        print('(consume_',end="",flush=True);
        print(i,end=",",flush=True);
        print(x,end=",",flush=True);
        print(')',end=":: ",flush=True)
      def producer1(self,i):
        print(i,'{producer-before',end="::",flush=True);
      def producer2(self,i):
        print('Proudecer-',end="",flush=True);
        print('After',end="",flush=True);
        print(' ',i,'}',end="",flush=True);
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
      lg.producer1(i);
      lg.produce1(i);
      y=[(i+1)%100]*(i%6+2);
      lg.produce2(y,i);
      if i%12==0:
        time.sleep((i%5+1)/10)
      return y;
    def consume(x,i):
      lg.consume(x,i);
      lg.consumer2(i)
      if i%13==0:
        time.sleep((i%7+1)/10);
    def producer(sh1):
      in1 = 0
      for i in range(100):
        x=produce(i);
        empty.acquire();     sh1.buf[in1] = x;     full.release();
        in1 = (in1 + 1)%sh1.n; lg.producer2(i)
    def consumer(sh1):
      out =0
      for i in range(100):
        lg.consumer1(i);
        full.acquire();    x = sh1.buf[out] ;   empty.release();
        out = (out +1) % sh1.n ;    consume(x,i);
    myShare = MyShare()
    th1 = Thread(target=consumer,args=(myShare,))
    th2 = Thread(target=producer,args=(myShare,))
    th1.start();th2.start();th1.join();th2.join()
    print('main --',end=" :: ",flush=True)
    for i in range(4):  print(myShare.buf[i],end=" :: ",flush=True)
    print("counter ",myShare.counter,flush=True)


Dining philosophers problem
========================================================================================
In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present formulation.[1][2][3]


.. image:: img/ps/An_illustration_of_the_dining_philosophers_problem_big.png
   :align: center
   :scale: 50%


Pickup forks one by one (semaphore)
--------------------------------------

.. code:: cpp

    #include<iostream>
    using namespace std;
    void think(void){cout <<"Eating"<<endl;}
    void eat(void){cout<<"thinking"<<endl;}
    semaphore forks[5]={1,1,1,1,1};
    //----------------------------
    void philosopher(int i){
      while (1){
        think();
        forks[i].P();
        forks[(i+1)%5].P();
        eat();
        forks[(i+1)%5].V();
        forks[i].V();
      }
    }
    int main(){
      cobegin{ philosopher(0); philosopher(1);
        philosopher(2); philosopher(3); philosopher(4);
      }
      return 0;
    }

Pickup two forks at the same time (semaphore)
--------------------------------------------------

.. code:: cpp

    enum {thinking , hungry , eating } state[5];
    semaphore self[5]{0,0,0,0,0};
    void pickup(int i){
      state[i] = hungry;
      if(state[(i-1)%5] == eating || state[(i+1)%5 == eating)
        self[i].P()
      state[i] = eating;
    }
    void putdown(int i){
      if(state[(i-1)%5] == hungry && state[(i-2)%5 != eating )
        self[(i-1)%5].V();
      if(state[(i+1)%5] == hungry && state[(i+2)%5 != eating )
        self[(i+1)%5].V();
      state[i]=thinking;
    }
    void philosopher(int i){
       do{   //thinking
             pickup(i);
             // eating
             putdown(i);
       }while(1);
    }
    int main(){
      for(int i=0; i<5; i++) state[i]= thinking;
     cobegin{ philosopher(0); philosopher(1); philosopher(2); philosopher(3); philosopher(4);}
      return 0;
    }

Pickup two forks at the same time
-----------------------------------------

.. code:: cpp

    monitor diningPhilosopher{   
      condition self[5];
      enum {thinking,hungry,eating } state[5];
      void pickup(int i){ 
        state[i]=hungry;
        if((state[(i+4)%5 ]== eating)||  (state[(i+1)%5]==eating))
          self[i].wait();
        state[i] = eating;
      }
      void putdown(int i){
        state[i]=thinking;
        if(state[(i+2)%5]!=eating) self[(i+1)%5].signal();
        if(state[(i+3)%5]!=eating) self[(i+4)%5].signal();
      }
      diningPhilosopher()
      {for(int i=0;i<5;i++)state[i]=thinking;}
    };diningPhilosopher dp;
    void philosopher(int i)
    {do{
      /*thinking*/ dp.pickup(i);/* eating */ dp.putdown(i);
     }while(1);
    }
    int main(){cobegin{
                  philosopher(0);philosopher(1);philosopher(2);
                  philosopher(3);philosopher(4);
       } return 0;
    }   

.. comments:

   rst2html.py process_synchronization.rst process_synchronization.html

