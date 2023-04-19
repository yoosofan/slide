#include<iostream>
#include<thread>
using namespace std; // g++ -std=c++17 -pthread 650.cpp 
void f(int i){
  cout << "In thread : " << i << endl;
  cout << "the next output" << endl;
}
int main(){
  const int N = 4;
  thread t[N];
  for(int i = 0; i < N; i++) 
    t[i]=thread(f, i);
  cout << "In main" << endl;
  cout << "second in main" << endl;
  for(int i=0;i<N;i++)
    t[i].join();
  return 0;
}
