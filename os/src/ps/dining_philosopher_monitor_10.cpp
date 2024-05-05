monitor dP{
  enum {thinking, hungry, eating}
      state[5];
  condition self[5];
  void pickup(int i);
  void putdown(int i);
  dP(){
    for(int i=0; i<5; i++)
      state[i]= thinking;
  }
};
void philosopher(int i){
  do{//thinking
    dP.pickup(i);
    // eating
    dP.putdown(i);
  }while(1);
}
