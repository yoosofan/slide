monitor mp{
  condition notfull, notempty;  int count = 0, nextin = 0, nextout = 0;
  void append (char x){
    if (count == N) notfull.wait(); /* buffer is full; avoid overflow */
    buffer[nextin] = x;
    nextin = (nextin + 1) % N;
    count++; /* one more item in buffer */
    notempty.signal(); /* notify any waiting consumer */
  }
  char take (void){
    if (count == 0) notempty.wait(); /* buffer is empty; avoid underflow */
    char x = buffer[nextout];
    nextout = (nextout + 1) % N);
    count--; /* one fewer item in buffer */
    notfull.signal(); /* notify any waiting producer */
    return x
  }
};
void producer(void){char x;do{ x = produce();  mp.append(x);}while(1);}
void consume(void){char x;do{ x = mp.take();  consume(x); } while(1);}
