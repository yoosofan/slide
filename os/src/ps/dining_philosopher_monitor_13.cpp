monitor diningPhilosopher{  condition self[5];
  enum {thinking,hungry,eating } state[5];
  void pickup(int i){ 
    state[i]=hungry;
    if((state[(i+4)%5 ] == eating)|| (state[(i+1)%5] == eating))
      self[i].wait();
    state[i] = eating;
  } void putdown(int i){
    state[i]=thinking;
    if(state[(i+2)%5]!=eating) self[(i+1)%5].signal();
    if(state[(i+3)%5]!=eating) self[(i+4)%5].signal();
  } diningPhilosopher()
  {for(int i=0;i<5;i++)state[i]=thinking;}
};
void philosopher(int i)
{do{ thinking(); diningPhilosopher.pickup(i); eating();
  diningPhilosopher.putdown(i);
 }while(1);
} int main(){cobegin{philosopher(0);philosopher(1);
    philosopher(2); philosopher(3); philosopher(4);
   } return 0;
}   
