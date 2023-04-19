void process(int i){
  number[i]=max(number,n)+1;
  int j;
  while(1){
    for(j=(i+1)%n; i!=n; i=(i+1)%n )
      if(number[i]>number[j])
        break;
    if(i == j)  break;
  }
  /*
   * Critical Section
  */
  number[i] = 0;
}
