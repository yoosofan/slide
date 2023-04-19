//Error
#include<iostream>
using namespace std;
template<typename T> void swap(T& a, T &b){T temp=a;a=b;b=temp;}
int main(){
  int a=1,b=2; 
  swap<int>(a,b);
  cout<<"a:"<<a<<"\tb:"<<b<<endl;
  string s1="ali",s2="reza";
  swap<string>(s1,s2);
  cout<<"s1:"<<s1<<"\ts2:"<<s2<<endl;
  return 0;
}
