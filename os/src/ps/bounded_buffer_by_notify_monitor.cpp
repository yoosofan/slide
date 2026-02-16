monitor mp{
  condition notfull, notempty;
  int count=0, nextin=0, nextout=0;
  void append(char x){
    while(count==N) notfull.wait();
    buffer[nextin] = x;
    nextin=(nextin+1)%N;
    count++;
    notempty.notify();
  }
  char take (){
    while(count==0) notempty.wait();
    char x = buffer[nextout];
    nextout = (nextout + 1) % N);
    count--;
    notfull.notify();
    return x
  }
};
void producer(){char x;
  do{
    x = produce();
    mp.append(x);
  }while(1);
}
void consume(){char x;
  do{
    x = mp.take();
    consume(x);
  }while(1);
}
