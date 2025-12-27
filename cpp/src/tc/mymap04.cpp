#include<iostream>
using namespace std;
class complexCls{
  double r,i;
 public:
  complexCls(double a=0,double b=0)
  {r=a; i=b;}
  complexCls operator+(const complexCls& a){
    complexCls ret; ret.r=r+a.r;
    ret.i=i+a.i; return ret;
  }
  friend ostream& operator<<(
    ostream&o1, const complexCls& m)
  {o1<<'('<<m.r<<','<<m.i<<')';return o1;}
  bool operator==(complexCls m2)
  {return r == m2.r && i == m2.i;}
};
template<typename T=double,
  typename I=string, int MAX=300>
class myArray{
  T a[MAX];
  int n;
  I s[MAX];
  public:
  myArray(){n=0;}
  T& operator[](I m1){
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
  myArray<> m1; m1["ali"]=23;
  m1["reza"]=45;
  cout << m1["ali"] << endl;
  myArray<complexCls, int, 20> m2;
  m2[4] = complexCls(5,6);
  cout << m2[4] << endl;
}
