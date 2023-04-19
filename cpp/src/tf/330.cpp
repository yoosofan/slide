#include<iostream>
using namespace std;
class complexCls{
  double r, i;
  public:
  complexCls(double m=0, double n=0)
  {r=m;i=n;}
  friend complexCls operator+(
const complexCls& a,
      const complexCls& b){
    complexCls result ;
    result.r = a.r + b.r;
    result.i = a.i + b.i;
    return result;
  }
  friend complexCls operator-(
      const complexCls& a,
      const complexCls& b){
    complexCls result ;
    result.r = a.r - b.r;
    result.i = a.i - b.i;
    return result;
  }
  friend complexCls operator*(
      const complexCls& a,
      const complexCls& b){
    complexCls result;
    result.r = a.r * b.r;
    result.i = a.i * b.i;
    return result;
  }
  friend bool operator==(
      const complexCls& a,
      const complexCls& b)
  {return a.r==b.r && a.i==b.i;}
  friend ostream& operator<<(
      ostream&o1, complexCls&a){
    o1 << '(' << a.r << " , " << a.i 
      << ')' ; 
    return o1;
  }
};
template<typename T> int search(
    T* a, T v, int n){
  for(int i=0; i < n; i++)
    if(a[i] == v)
      return i;
  return -1;
}
int main(){
  double ae[] = {3, 4, 5, 6, 8, 9};
  cout << search<double>(ae, 3, 6) 
    << endl;
  cout << search<double>(ae, 33, 6)
    << endl;
  string am[] = 
    {"ali", "reza", "kamran", "hamid"};
  cout << search<string>(am, "reza", 4)
    << endl;
  complexCls ac[] = {
    complexCls(1, 2), complexCls(3, 4), complexCls(6,7)
  };
  //int mm=search<complexCls>(ac,complexCls(6,7), sizeof(ac)/sizeof(complexCls));
  int mm = search<complexCls>(
    ac, complexCls(6, 7), 3);
  cout << mm << endl;
  mm = search<complexCls>(ac,
    complexCls(1, 7), 3);
  cout << mm << endl;
}
