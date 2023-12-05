#include<iostream>
using namespace std;
class complexCls{
  double re,im;
 public:
  complexCls(double a=0,double b=0){re=a;im=b;}
  friend istream& operator>>(
      istream& io1,complexCls &m1){
    cout<<"re: "; io1>>m1.re;
    cout<<"im: "; io1>>m1.im; 
    return io1;
  }
  friend ostream& operator<<(
      ostream& io1, const complexCls &m1){
    io1 << m1.re << ',' << m1.im << endl;
    return io1;
  }
template<typename Type> class array{
  static const int MAX = 200;
  Type a[MAX];  int n = 0;
public:
  void input(void){
    cout<<"Enter n: "; cin>>n;
    for(int i=0;i<n;i++){
      cout<<"Enter a["<<i<<"]: ";
      cin>>a[i];
    }
  }
  void print(void){
    cout<<"n: "<<n<<endl;
    for(int i=0;i<n;i++)
      cout<<a[i]<<endl;
  }
};
int main(){
  array<complexCls> ccm1; ccm1.input();
  ccm1.print();
}
