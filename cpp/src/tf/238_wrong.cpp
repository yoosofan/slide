#include<iostream>
using namespace std;
template<typename T>int search(
    T* a, T v, int n){
  for(int i=0; i<n; i++) 
    if(a[i]==v) 
      return i;
  return -1;
}
template<typename T>void mySwap(
    T& a,T& b){
  T t = a;
  a = b;
  b = t;
}
template<typename T> void sort_wrong(T a[],int n){
  int i,j; 
  T temp;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(a[i]>a[j]){
        cout<<"swap a["<<i<<"]="<<a[i]<<" , a["<<j<<"]="<<a[j]<<endl;
        temp=a[i]; 
        a[i]=a[j]; 
        a[j]=temp;
        for(int k=0; k<n; k++)
          cout<<a[k]<<'\t'; cout<<endl;
      }
}
template<typename T> void sort( a[],int n){
  int i,j; 
  T temp;
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
      if(a[i]>a[j]){
        temp=a[i]; 
        a[i]=a[j]; 
        a[j]=temp;
      }
}
int main(){ 
  double ae[20]{5,6,4,2,1}; 
  int i=1,j=2;
  //for(i=0; i<6; i++) ae[i]=36-i;
  cout<<search<double>(ae,4,5)<<endl;
  cout<<search<double>(ae,33,5)<<endl;
  mySwap<int>(i,j);   cout<<"i= "<<i<<"\tj= "<<j<<endl;
  for(i=0;i<5;i++) cout<<ae[i]<<'\t';  cout<<endl;
  sort<double>(ae,5); for(i=0;i<5;i++) cout<<ae[i]<<'\t';  cout<<endl;
  return 0;
}
