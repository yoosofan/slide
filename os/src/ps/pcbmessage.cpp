const int  capacity = 100;
/* buffering capacity  ; 1 = empty message */ ;

mailbox<char, 100> mayproduce;
mailbox<object, 100> mayconsume;

void producer(){
  object x;
  while(true){
    mayproduce.receive();
    x = produce();
    mayconsume.send(x);
  }
}

void consumer(){
  object x;
  while(true) {
    x = mayconsume.receive();
    consume(x);
    mayproduce.send(1);
  }
}

void main(){
  for (int i = 1; i <= capacity; i++)
    mayproduce.send(1);
  cobegin{
    producer();
    consumer();
  }
}
