void pickup(int i){
  state[i] = hungry;
  if(state[(i+4)%5 ]== eating)
