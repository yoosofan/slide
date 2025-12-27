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
  myArray<complexCls, int, 20> m2;
  m2[4] = complexCls(5,6);
  cout << m2[4] << endl;
  myArray<int, complexCls, 30> m3;
  m3[complexCls(2,4)] = 5;
  cout << m3[complexCls(2,4)] << endl;
  complexCls c2(4,7); m3[c2]=9;
  cout << m3[c2] << endl;
}