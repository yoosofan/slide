#include<iostream>
using namespace std;
struct complexCls{
  double r,i;
  void init(double m=0, double n=0)
  {r=m; i=n;}
  void display()
  {cout<<r<<"+i "<<i<<endl;}
  void input(string str1){
    cout<<str1<<"  ";
    cout<<"Enter real part ";
    cin>>r;
    cout<<"Enter imaginary part ";
    cin>>i;
  }
  complexCls add(complexCls a){
    complexCls retVal;
    retVal.r = r + a.r;
    retVal.i = i + a.i;
    return retVal;
};
int main(){
  complexCls x; x.r=5; x.i=7;
  x.display();//cout<<x.r<<"  "<<x.i<<endl;
  x.init(12,3);x.display();
  //cout<<x.r<<"  "<<x.i<<endl;
  complexCls m; m.input("m");
  m.display(); complexCls f;
  f.init();
  f.display();complexCls g;
  g.init(2); g = f.add(x);
  g.display();
}
