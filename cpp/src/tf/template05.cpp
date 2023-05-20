#include<iostream>
template<typename T> void swap2(T& a, T& b)
{T temp=a;a=b;b=temp;}
int main(){
  int a=1,b=2; 
  swap2<int>(a,b);
  std::cout<<"a:"<<a<<"\tb:"<<b<<std::endl;
  std::string s1="ali",s2="reza";
  swap2<std::string>(s1,s2);
  std::cout<<"s1:"<<s1<<"\ts2:"<<s2<<std::endl;
}
