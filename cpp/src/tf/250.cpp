#include<iostream>
using namespace std;
template<typename T>int search(T* a, T v, int n){
  for(int i=0; i<n; i++) if(a[i]==v) return i;
  return -1;
}
template<typename T> void mySwap(T & a,T & b){T t=a;a=b;b=t;}
template<typename T>
void sort(T a[],int n){
  int i,j; T temp;
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
      if(a[i]>a[j]){
         temp=a[i];
         a[i]=a[j];
         a[j]=temp;
       }
}
int main(){
  double ae[20];
  int i,j=2;
  for(i=0; i<6; i++) ae[i]=36-i;
  cout<<search<double>(ae,3,6)<<endl;
  cout<<search<double>(ae,33,6)<<endl;
  cout<<"i= "<<i<<"\tj= "<<j<<endl;
  mySwap<int>(i,j);
  cout<<"i= "<<i<<"\tj= "<<j<<endl;
  sort<double>(ae,6);
  for(i=0;i<6;i++) cout<<ae[i]<<'\t';
  cout<<endl;
  return 0;
}
