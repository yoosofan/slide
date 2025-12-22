#include<iostream>
#include<string>
using namespace std;
class complexCls{
  double r, i;
  public:
  complexCls(double a = 0, double b = 0){
    r=a;
    i=b;
  }
  complexCls operator+(const complexCls a){
    complexCls ret;
    ret.r = r + a.r;
    ret.i = i + a.i;
    return ret;
  }
  friend ostream& operator<<(ostream&o1,
      const complexCls m){
    o1 << '(' << m.r << ',' << m.i << ')';
    return o1;
  }
  bool operator==(complexCls m2){
    if(r == m2.r && i == m2.i)
      return true;
    return false;
  }
};
template<typename T> class Node{
  T v;
  Node *next;
  public:
  Node(T *m1 = nullptr){
    if(m1)
      v = *m1;
    next = nullptr;
  }
  bool operator==(Node m2){
    if(v == m2.v)
      return true;
    return false;
  }
};
template<typename Type> class myArray{
  Type* a;
  int n, count;
  public:
  myArray(int n = 20){
    this -> n = n;
    a = new Type[n];
    count = 0;
  }
  ~myArray(){
    n=0;
    delete[] a;
    a=nullptr;
  }
  Type& operator[](int index){
    if(index < count)
      return a[index];
    if(index<n){return a[count++];}
    return a[0];
  }
}; int main(){
  myArray<int> m1(10);
  m1[0] = 34;
  cout << m1[0] << endl;
  m1[1] = 34;
  cout << m1[1] << endl;
  myArray<string> cm1;
  cm1[0] = "ali";
  cm1[1] = "Reza";
  cout<<cm1[0]<<endl;
  cout<<cm1[1]<<endl;
  myArray<complexCls> am1;
  am1[0]=complexCls(3,4);
  cout<<am1[0]<<endl;
}
