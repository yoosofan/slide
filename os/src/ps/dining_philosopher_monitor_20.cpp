monitor mp{
  condition mutex;
  condition chopstick[5];

  int count_m = 5;
  bool  ach[5]={false,
    false,false,false,false};

  pickup(int i){
    count_m--;
    if(count_m == 0) 
      mutex.wait();
    if(ach[i] == true)  
      chopstick[i].wait();
    ach[i] = true;
    if(ach[(i+4)%5] == true) 
      chopstick[(i+4)%5].wait();
    ach[(i+4)%5] = true;
  }

  void putdown(int i){
    ach[i]=false;
    chopstick[i].signal();
    ach[(i+4)%5]= false;
    chopstick[(i+4)%5].signal();
    count_m++;
    if(count_m == 1)  
      mutex.signal();
  }
};

void philosopher(int i){
  do{
    thinking(); dP.pickup(i);
    eating(); dP.putdown(i);
 }while(1);
}