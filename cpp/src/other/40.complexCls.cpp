#include <iostream>
#include <cmath>
using namespace std;

class complexCls{
   double r,i;
  public:
   complexCls(int m=0 , int n=0){r=m;i=n;}
   void Show(){cout<<r<<"+ i "<<i<<endl;}
   double Magnitude(){return sqrt(r*r+i*i);}

   complexCls operator +(complexCls b){
      complexCls result ;
      result.r = r + b.r;
      result.i = i + b.i;
      return result;
   }
   complexCls operator -(complexCls b){
      complexCls result ;
      result.r = r - b.r;
      result.i = i - b.i;
      return result;
   }
   complexCls operator *(complexCls b){
      complexCls result;
      result.r = r * b.r;
      result.i = i * b.i;
      return result;
   }

};
int main(){
      complexCls a(2,3);
      complexCls b(4,5);
      complexCls c;
      c = a + b;
      c.Show();
      c = a + 12;
      //c = 12 + a;  // Error
      c.Show();
}

