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
void producer(void){
  char x; int nextin=0
  do{ 
    x = produce();  
    mp.beforeAppend();
    buffer[nextin] = x;
    nextin=(nextin+1)%N;
    afterAppend()
  }while(1);
}
void consume(void){
  char x; int nextout=0;
  do{ 
    mp.beforeTake();  
    x=buffer[nextout];
    nextout=(nextout+1)%N;
    mp.afterTake();  
    consume(x); 
  }while(1);
}