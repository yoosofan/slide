#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;
mutex g_display_mutex;
//https://www.runoob.com/w3cnote/cpp-std-thread.html
void foo(){
  thread::id this_id = this_thread::get_id();

  g_display_mutex.lock();
  cout << "thread " << this_id << " sleeping...\n";
  g_display_mutex.unlock();

  this_thread::sleep_for(chrono::seconds(1));
}//g++ -std=c++23 -pthread cpp20synchronized.cpp
int main(){
  thread t1(foo);
  thread t2(foo);
  t1.join();
  t2.join();
}
