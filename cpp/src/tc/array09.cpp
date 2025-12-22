#include<iostream>
using namespace std;
const int MAX=200;
class complexCls{
  double re,im;
 public:
  complexCls(double a=0,double b=0){re=a;im=b;}
  friend istream& operator>>(istream& io1,complexCls &m1)
  {cout<<"re: ";io1>>m1.re;cout<<"im: ";io1>>m1.im; return io1;}

  friend ostream& operator<<(ostream& io1,const complexCls &m1)
  {io1<<m1.re<<','<<m1.im<<endl;}
  friend bool operator==(const complexCls &m1,const complexCls&m2)
  {if(m1.re==m2.re && m1.im==m2.im) return true; return false;}
};
template<typename Type> class myArray{Type a[MAX];  int n;
public:
  void input(void){cout<<"Enter n: ";cin>>n;
    if(n<0 || n>MAX) throw "n is greater than 200";
    for(int i=0;i<n;i++){cout<<"Enter a["<<i<<"]: ";cin>>a[i];}
  }
  void print(void){cout<<"n: "<<n<<endl;for(int i=0;i<n;i++)cout<<a[i]<<endl;}
  int search(Type key){
    for(int i=0;i<n;i++)if(a[i]==key) return i;
    return -1;
  }
  Type&  operator[](int index){
    if(index<0 || index>=n) throw "index out of range";
    return a[index];
  }
};
int main(){
  //myArray<int> m1,m2,m3; myArray<double> dm;   myArray<char> cm;
  try{
    myArray<complexCls> ccm1; ccm1.input();ccm1.print();
    complexCls c2(4);if(c2==4) cout<<"equals"<<endl;
    //complexCls c3(4);if(operator==(c3, complexCls(4))) cout<<"equals"<<endl;
    complexCls c1(4);if(4==c1) cout<<"equals"<<endl;
    cout<<ccm1.search(c1)<<endl;
  }catch(const char *st1){cout<<st1<<endl;}
  //m1.input();m1.print();
}
