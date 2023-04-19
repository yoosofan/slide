void process(int i){
  number[i]=max(number,n)+1;
  int j;
  for(j=(i+1)%n ; j!=i;j=(j+1)%n)
    while(number[i]>number[j])
      ;
  /*
   * Critical Section
  */
  number[i] = 0;
}
