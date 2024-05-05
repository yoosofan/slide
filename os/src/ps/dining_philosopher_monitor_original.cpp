monitor dP{
  enum {thinking, hungry, eating}
      state[5];
  condition self[5];

  void pickup(int i){
    state[i] = hungry;  test(i);
    if ( state[i] != eating )
      self[i].wait();
  }
  void putdown(int i){
    state[i]=thinking;
    test( (i+4) % 5);
    test( (i+1) % 5);
  }
  dP(){
    for(int i=0; i<5; i++)
      state[i]= thinking;
  }

  void test(int i){
    if ( (state[(i+4) % 5 ] != eating)
        && (state[i] == hungry )  &&
        (state[(i+1) %5 ] != eating))
    {
      state[i] = eating;
      self[i].signal();
    }
  }
};
void philosopher(int i){
   do{//thinking
      dP.pickup(i);     // eating
      dP.putdown(i);
   }while(1);
}