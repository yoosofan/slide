#include<iostream>
using namespace std;
template<typename T=double, typename I=string, int MAX=300>
class myArray{
  T a[MAX];
  int n;
  I s[MAX];
  public:
  myArray(){n=0;}
  T& operator[](string m1){
    int i;
    for(i=0; i<n; i++)
      if(s[i] == m1 )
        return a[i];
    if(n >= MAX) 
      throw "not suffecient memory";
    s[n] = m1;
    return a[n++];
  }
};
int main(){
  myArray<> m1;
  m1["ali"]=23;
  m1["reza"]=45;
  cout << m1["ali"] << endl;
  return 0;
}
