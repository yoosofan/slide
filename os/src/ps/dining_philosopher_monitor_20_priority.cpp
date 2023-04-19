monitor mp{
  condition mutex;
  int count_m = 5;
  condition chopstick[5];
  bool       ach[5]={false,false,false,false,false};
  pickup(int i){
    count_m--;
    if(count_m == 0) mutex.wait();
    if(ach[i] == true)  chopstick[i].wait(i);
    ach[i] = true;
    if(ach[(i+4)%5] == true) chopstick[(i+4)%5].wait(i);
    ach[(i+4)%5] = true;
  }
  void putdown(int i){
    ach[i]=false;
    chopstick[i].signal();
    ach[(i+4)%5]= false;
    chopstick[(i+4)%5].signal();
    count_m++;
    if(count_m == 1)  mutex.signal();
  }
};
