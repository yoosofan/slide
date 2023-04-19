#include<iostream>
using namespace std;
semaphore chopstic[5]={1,1,1,1,1}; semaphore mutex=4;
void philosopher(int i){
  do{
    //thinking()
    mutex.P();
    chopstic[i].P();
    chopstic[(i+4)%5].P();
    // eating
    chopstic[(i+4)%5].V();
    chopstic[i].V();
    mutex.V();
  }while(1);
}
