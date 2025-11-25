#include "mycomplex.h"
using namespace std;
complexCls::complexCls(int m=0,int n=0)
{r=m;i=n;}

void complexCls::Show()
{cout<<r<<"+ i "<<i<<endl;}

double complexCls::Magnitude()
{return sqrt(r*r+i*i);}

void complexCls::input(){
    cout<<"Enter real:"; cin>>r;
    cout<<"Enter imaginary:"; cin>>i;
}

complexCls complexCls::add(complexCls b){
    complexCls c;
    c.r = r + b.r;
    c.i = this->i + b.i;
    return c;
  }
complexCls add(complexCls a, complexCls b){
  complexCls c=a;
  c.r += b.r;
  c.i += b.i;
  return c;
}
