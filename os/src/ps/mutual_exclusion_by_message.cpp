/* program mutualexclusion */
/* const int n = number of process */
mailbox box;

void P(int i){
  message msg;
  while (true) {
    receive(box, msg);
      /* Critical Section */;
    send(box, msg);
      /* Remainder Section */;
  }
}

void main()
{
  send(box, null);
  cobegin{
    P(1);
    P(2);
    … ;
    P(n);
  }
}
