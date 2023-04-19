#include<iostream>
using namespace std;
void think(void){cout <<"Eating"<<endl;}
void eat(void){cout<<"thinking"<<endl;}
semaphore forks[5]={1,1,1,1,1};
//----------------------------
void philosopher(int i){
  while (1){
    think();
    forks[i].P();
    forks[(i+1)%5].P();
    eat();
    forks[(i+1)%5].V();
    forks[i].V();
  }
}
int main(){
  cobegin{ philosopher(0); philosopher(1);
    philosopher(2); philosopher(3); philosopher(4);
  }
  return 0;
}
