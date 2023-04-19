void putdown(int i){
  state[i]=thinking;
  if(state[(i+2) % 5 ] != eating)
    self[(i+1)%5].signal();
  if((state[(i+3) %5 ] != eating))
