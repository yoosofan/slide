#include<iostream>
#include<thread> // 620.cpp
using namespace std;
// g++ -std=c++17 -pthread 
// clang++ 630.cpp --std=c++17 -lpthread
void f(void){
  cout << "In thread " << endl;
  cout << "the next output in thread" << endl;
}

int main(){
  thread t(f);
  cout << "In main" << endl;
  cout << "second in main" << endl;
  t.join();
  return 0;
}
