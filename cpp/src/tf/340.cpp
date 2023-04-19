#include<iostream>
using namespace std;
class complexCls{
  double r, i;
  public:
  complexCls(double m=0, double n=0){r=m;i=n;}
  friend complexCls operator +(const complexCls& a,const complexCls& b){
    complexCls result ;
    result.r = a.r + b.r;
    result.i = a.i + b.i;
    return result;
  }
  friend complexCls operator -(const complexCls& a,const complexCls& b){
    complexCls result ;
    result.r = a.r - b.r;
    result.i = a.i - b.i;
    return result;
  }
  friend complexCls operator *(const complexCls& a,const complexCls& b){
    complexCls result;
    result.r = a.r * b.r;
    result.i = a.i * b.i;
    return result;
  }
  friend bool operator ==(const complexCls& a,const complexCls& b)
  {return a.r==b.r && a.i==b.i;}
  friend ostream& operator<<(ostream&o1, complexCls&a)
  {o1<<'('<<a.r<<" , "<< a.i << ')' ; return o1;}
};
template<typename T> void mySwap(T& a, T &b){
  T temp = a;
  a = b;
  b = temp;
}
int main(){
  int a = 1, b = 2; 
  mySwap<int>(a, b);
  cout << "a:" << a << "\tb:" << b << endl;
  string s1 = "ali", s2 = "reza";
  mySwap<string>(s1, s2);
  cout << "s1:" << s1 << "\ts2:" << s2 << endl;
  return 0;
}
