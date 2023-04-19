//Error
#include<iostream>
using namespace std;
struct complexCls{
  double r,i;
  complexCls(double m=0 , double n=0){r=m;i=n;}
  void Show(){cout<<r<<"+ i "<<i<<endl;}
  double Magnitude(){return sqrt(r*r+i*i);}
};

complexCls operator +(const complexCls& a,const complexCls& b){
  complexCls result ;  result.r = a.r + b.r;
  result.i = a.i + b.i;  return result;
}

complexCls operator -(const complexCls& a,const complexCls& b){
  complexCls result ;  result.r = a.r - b.r;  result.i = a.i - b.i;  return result;
}

complexCls operator *(const complexCls& a,const complexCls& b){
  complexCls result; result.r = a.r * b.r;
  result.i = a.i * b.i;
  return result;
}

class myArray{
  complexCls a[300];
  int n = 0;
  string s[300];
public:

  myArray() = default;

  complexCls& operator[](string m1){
    int i;
    for(i=0; i<n; i++)
      if(s[i] == m1 )        return a[i];
    s[n]=m1;
    return a[n++];
  }
};

int main(){
  myArray m1;
  double x=3, y=3.0, z(3.0);
  m1["ali"] = complexCls(2,3);
  m1["reza"] = complexCls(3,1);
  m1["kamran"] = complexCls(4,3);
  m1["hamid"] = complexCls(5,7);
  cout << m1["ali"] << endl;
  cout << m1["reza"] << endl;
  return 0;
}
