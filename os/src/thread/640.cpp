#include<iostream>
#include<thread>
using namespace std;
void f(void){
  cout << "In thread " << endl;
  cout << "the next output" << endl;
}
int main(){
  const int N = 4;
  thread t[N];
  for(int i = 0; i < N; i++) 
    t[i]=thread(f);
  cout << "In main" << endl;
  cout << "second in main" << endl;
  for(int i=0;i<N;i++)
    t[i].join();
  return 0;
}
