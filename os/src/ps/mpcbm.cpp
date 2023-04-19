const int N = 100; 
int in = 0, out = 0, n = 0 ;

class Type; 
Type buffer[N];

Type produce(void){
  Type x;
  return x;
} 

void consume(Type x){}

monitor mp{ 
  condition full, empty ;
  
  void add(Type x){
    if(n == N)            
      full.wait();
    buffer[in]=x;         
    in = (in + 1) % N;
    n++;                  
    empty.signal();
  }
  
  Type remove(void){  
    Type x;
    if(n == 0)            
      empty.wait();
    x = buffer[out];      
    out = (out + 1) % N;
    n--;    
    full.signal();  return x;
  } 
};

void producer(void){
  do{
    Type x = produce();  
    mp.add(x); 
  }while(1);
}

void consumer(void){
  Type x;
  do{
    x = mp.remove();    
    consume(x);
  } while(1);}

int main(){
  cobegin{
    producer(); 
    consumer();
  }    
  return 0;
}

