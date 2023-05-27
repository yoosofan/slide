#include<iostream>
using namespace std;
struct complexCls{double r,i;};
void init(complexCls&c, double j=0, double f=0);
void display(complexCls);
complexCls input(string str1);
int main(){
  complexCls x; x.r=5; x.i=7;
  display(x);//cout<<x.r<<"  "<<x.i<<endl;
  init(x,12,3);display(x);
  //cout<<x.r<<"  "<<x.i<<endl;
  complexCls m = input("m");
  display(m); complexCls f;
  init(f);
  display(f);complexCls g;
  init(g,2);
  display(g);
  return 0;
}
void init(complexCls &a, double m, double n)
{a.r=m; a.i=n;}
void display(complexCls x)
{cout<<x.r<<"+i "<<x.i<<endl;}
complexCls input(string str1){
  cout<<str1<<"  "; complexCls x;
  cout<<"Enter real part ";
  cin>>x.r;
  cout<<"Enter imaginary part ";
  cin>>x.i;
  return x;
}
