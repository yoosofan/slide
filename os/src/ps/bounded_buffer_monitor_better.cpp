monitor mp{
  condition notfull, notempty;
  int count=0;
  void beforeAppend()
  {if (count==N) notfull.wait();}
  void afterAppend()
  {count++; notempty.signal();}
  void beforeTake()
  {if(count==0) notempty.wait();}
  void afterTake()
  {count--;notfull.signal();}
};
void producer(){
  char x; int nextin=0
  do{
    x = produce();
    mp.beforeAppend();
    buffer[nextin] = x;
    afterAppend()
    nextin=(nextin+1)%N;
  }while(1);
}
void consume(){
  char x; int nextout=0;
  do{
    mp.beforeTake();
    x=buffer[nextout];
    mp.afterTake();
    nextout=(nextout+1)%N;
    consume(x);
  }while(1);
}