monitor diningPhilosopher{  condition self[5];
  enum {thinking , hungry , eating } state[5];
  void pickup(int i){
    state[i] = hungry;  test(i);
    if ( state[i] != eating ) self[i].wait();   
  } 
  void putdown(int i)
  {state[i]=thinking; test( (i+4) % 5); test( (i+1) % 5);} 
  void test(int i){
    if ( (state[(i+4) % 5 ] != eating) && (state[i] == hungry )  &&
         (state[(i+1) %5 ] != eating))
      {state[i] = eating;   self[i].signal();}   
  }
   diningPhilosopher()
   {for(int i=0; i<5; i++)    state[i]= thinking;}
};
void philosopher(int i){
   do{   //thinking
         diningPhilosopher.pickup(i);     // eating
         diningPhilosopher.putdown(i);
   }while(1);
}
