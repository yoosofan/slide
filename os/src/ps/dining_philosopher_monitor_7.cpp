void philosopher(int i){
  do{
    //thinking
    pickup(i);
    // eating
    putdown(i);
  }while(1);
}
int main(){
  cobegin{
    philosopher(0);
    philosopher(1);
    philosopher(2);
    philosopher(3);
    philosopher(4);
  }  return 0;
} 
