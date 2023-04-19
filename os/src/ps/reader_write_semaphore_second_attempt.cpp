#include<iostream>
using namespace std;
void write(void){cout <<"writing"<<endl;}
void read(void){cout<<"reading"<<endl;}
void RemainingWork(void){}

semaphore wx = 1;
int read_count = 0;

void writer(void){
  do{
    wx.P();
    write();
    wx.V();
    RemainingWork();
  }while(1);
}

void reader(void){
    do{
        if(read_count == 0)
            wx.P();
        read_count ++;
        read();
        read_count --;
        if( read_count == 0)
            wx.V();
        RemainingWork();
    }while(1);
}
// problem 1: 2 readers come to line 22 then one of them stuck
// problem 2: one write in line 13 then new readers will run wx.P() 
// problem 3: 2 readers come to line 25 and set read_count zero then both of them 
// will run wx.V();
int main(){
  cobegin{ philosopher(0); philosopher(1);
    philosopher(2); philosopher(3); philosopher(4);
  }
  return 0;
}
