#include<iostream>
using namespace std;
class complexCls{ double re,im;
 public:complexCls(double a=0,double b=0)
 {re=a;im=b;}
};
template<typename Type> class array{
  static const int MAX = 200;
  Type a[MAX];  
  int n = 0;
  public:
  void input(void){cout<<"Enter n: ";cin>>n;
    for(int i=0;i<n;i++){cout<<"Enter a["<<i<<"]: ";cin>>a[i];}
  }
  void print(void){cout<<"n: "<<n<<endl;for(int i=0;i<n;i++)cout<<a[i]<<endl;}
};
int main(){
  array<int> m1,m2,m3; 
  array<double> dm;   
  array<char> cm;
  array<complexCls> ccm1;
  m1.input();
  m1.print(); // ccm1.input(); ccm1.print();
}
