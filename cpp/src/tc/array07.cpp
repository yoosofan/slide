#include<iostream>
using namespace std;
class complexCls{
  double re, im;
 public:
  complexCls(double a=0, double b=0)
  {re=a;im=b;}
  friend istream& operator>>(
      istream& io1,complexCls &m1){
    cout << "re: "; io1 >> m1.re;
    cout << "im: "; io1 >> m1.im;
    return io1;
  }
  friend ostream& operator<<(
      ostream& io1,const complexCls &m1){
    io1 << m1.re << ',' << m1.im << endl;
    return io1;
  }
  friend bool operator==(
      const complexCls &m1,
      const complexCls &m2){
    if(m1.re == m2.re && m1.im == m2.im)
      return true;
    return false;
  }/*
  bool operator==(const complexCls&m2){
    if(re == m2.re && this->im == m2.im)
      return true;
    return false;
  }*/
};
template<typename Type> class myArray{
  static const int MAX = 200;
  Type a[MAX];  int n = 0;
  public:
  void input(){
    cout<<"Enter n: ";
    cin>>n;
    if(n < 0 || n > MAX)
      throw "n is greater than 200";//exit(0);
    for(int i=0; i < n; i++){
      cout << "Enter a[" << i << "]: ";
      cin >> a[i];
    }
  }
  void print(){
    cout<<"n: "<<n<<endl;
    for(int i=0;i<n;i++)
      cout<<a[i]<<endl;
  }
  int search(Type key){
    for(int i=0;i<n;i++)
      if(a[i] == key)
        return i;
    return -1;
  }
};
int main(){
  myArray<complexCls> ccm1;
  ccm1.input();ccm1.print();
  complexCls c2(4);
  if(c2==4) cout<<"equals"<<endl;
  complexCls c1(4);
  if(4==c1) cout<<"equals"<<endl;
  cout<<ccm1.search(c1)<<endl;
}
