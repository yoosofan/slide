#include<iostream>
using namespace std;
template<class T>
class myArray{
  T a[300];
  int n;
  string s[300];
  public:
  myArray(){n=0;}
  T& operator[](string m1){
    int i;
    for(i=0; i<n; i++)
      if(s[i] == m1 )
        return a[i];
    s[n]=m1;
    return a[n++];
  }
};
int main(){
  myArray<double> m1;
  m1["ali"]=23;
  m1["reza"]=45;
  cout<<m1["ali"]<<endl;
  return 0;
}
