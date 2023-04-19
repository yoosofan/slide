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
  cobegin{ philosopher(0);philosopher(1);philosopher(2);philosopher(3);philosopher(4);}
  return 0;
}
