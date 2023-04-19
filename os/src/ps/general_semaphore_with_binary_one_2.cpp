struct semaphore {
  binary_semaphore sm; int count; queue<int> L;
  void P(){ sm.P();   count--;
    if (count < 0) {
      L.Add(myPID);
      sm.V();
      os.block_me();
    }
    else sm.V();
  }
  void V(){ sm.P();  count++;
    if (count<= 0){
      n1=L.Remove();
      os.wakeup(n1);
    }
    sm.V();
  }
};
