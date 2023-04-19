/* program mutualexclusion */
/* const int n = number of process */

mailbox box;

void P(int i){
  message msg;
  while (true) {
    box.receive(msg);
      /* critical section */;
    box.send(msg);
      /* remainder */;
  }
}

void main(){
  box.send(null);
  cobegin{
    P(1);
    P(2);
    … ;
    P(n);
  }
}
