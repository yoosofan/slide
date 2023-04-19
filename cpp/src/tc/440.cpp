#include <iostream>
#include <cstdlib>
#include<cmath>
using namespace std;
class myException {
/*  string message;
   public:
  myException(string msg){message = msg;}
  string what(void){return message;}*/
};
template<typename T> class ArrayCls{
  T* data;
  int size;
 public:
  ArrayCls() = default;
  ArrayCls(T* a, int sz){
    data = new T[ size = sz ] ;
    if (!data) throw myException();//
    for(int i=0 ; i<size; i++) 
      data[i] = a[i];
  }
  ~ArrayCls(){
    cout<<" in destructor "<<endl;
    delete[] data; data=nullptr;
  }
  ArrayCls(const ArrayCls& a){
    data=new T[size=a.size];
    for(int i=0; i<size; i++)     
      data[i]=a.data[i];
  }
  ArrayCls(ArrayCls&& a){
    data = a.data;
    size = a.size;
    a.data = nullptr;
    a.size = 0;
    cout<<"move constructor "<<endl;
  }
  ArrayCls operator+(ArrayCls& a){
    if(size != a.size) 
      throw myException();
    ArrayCls retVal(size);
    for(int i=0; i<size ; i++)
      retVal.data[i] = data[i] + a.data[i];
    return retVal;
  }
  ArrayCls operator-(ArrayCls & a){
    if(size != a.size) throw myException();
    ArrayCls retVal(size);
    for(int i=0; i<size ; i++)
      retVal.data[i]=data[i]-a.data[i];
    return retVal;
  }
  ArrayCls operator=(const ArrayCls& a){
    delete[] data;
    size = a.size ;
    data = new T[size];
    for(int i=0; i<size; i++)
      data[i] = a.data[i];
    cout<<"regular assignment "<<endl;
    return *this;
  }
  ArrayCls operator=(ArrayCls&& a){
    delete[] data;
    size = a.size;
    data = a.data;
    a.data = nullptr; 
    a.size = 0;
    cout<<"move assignment "<<endl;
    return *this;
  } 
  T & operator[](int index){
    if(index>=size || index < 0) throw myException();//"Index is out of range");
    return data[index];
  }
};
class complexCls{double r,i;
  public:
   complexCls(int m=0 , int n=0){r=m;i=n;}
   void Show(){cout<<r<<"+ i "<<i<<endl;}
   double Magnitude(){return sqrt(r*r+i*i);}

   complexCls operator += (complexCls &a){
      r += a.r;
      i += a.i;
      return *this;
   }
   complexCls operator -= (complexCls &a){
      r -= a.r;
      i -= a.i;
      return *this;
   }
   complexCls operator *= (complexCls &a){
      r = r * a.r - i * a.i;
      i = i * a.r + r * a.i;
      return *this;
   } // It is not necessary to implement the = operator
   // for this class, because the default behavior of
   // this operator is identical to the following
   // implementation.
   complexCls operator = (const complexCls a){
      r = a.r;
      i = a.i;
      return *this;
   }
   complexCls(const complexCls & a){
      r = a.r;
      i = a.i;
   }
   double & operator [] (const int index){
      if(index == 0)  return r;
      if(index == 1)  return i;
      cout<< " Error in accessing the value;\n";
      return r;
   }
   friend complexCls operator +(const complexCls  a , const complexCls  b);
   friend complexCls operator -(const complexCls  a , const complexCls  b);
   friend complexCls operator *(const complexCls  a , const complexCls  b);
   friend ostream& operator<<(ostream &o,complexCls a);
};
complexCls operator +(const complexCls  a ,const  complexCls  b){
      complexCls result ;
      result.r = a.r + b.r;
      result.i = a.i + b.i;
      return result;
}
complexCls operator -(const complexCls  a , const complexCls  b){
   complexCls result ;
   result.r = a.r - b.r;
   result.i = a.i - b.i;
   return result;
}
complexCls operator *(const complexCls  a , const complexCls  b){
   complexCls result;
   result.r = a.r * b.r - a.i * b.i;
   result.i = a.i * b.r + a.r * b.i;
   return result;
}
ostream& operator<<(ostream &o,complexCls a){
  o<<"("<<a.r<<","<<a.i<<")";
  return o;
}
template<class T> ArrayCls<T> f1(int n){
  ArrayCls<T> a(n);
  cout<<"in f1 "<<endl;
  return a;
}
int main(){
  complexCls t1[]={
    complexCls(1,4),complexCls(2,9),3,4,5,6} , 
    t2[]= {11,12,13,14,15,16};
  for(int k=0;k<5;k++)cout<<t1[k]<<endl;
  complexCls t3[]={21,22,23,24,25,26} , t4[]= {1,2}, t5[]={3,4} ;
  ArrayCls<complexCls> a(t1,6), b(t2,6) , c(t3,6), d(t4,2), e(t5,2), f, g;
  try{
    f = a + b - c ;
    f = a + b  ;
    f = a + c  ;
    f=a;
    cout<<"after first assignment"<<endl;
    g = e + f;
    
    f = a - e;
    f = b - d;
  }
  catch(myException &ex1){ cout<<"exception"<<endl;}
  catch(...){cout<<"unknown exception"<<endl;}
  try{
    a[1] = 12 ;
    cout << a[1]<<endl;
    a[2] = 8;
    cout << a[0]<<endl;
  }
  catch(myException & ex1){cout<<"exception"<<endl;}
  catch(...){cout<<"unknown exception"<<endl;}
  ArrayCls<double> y=f1<double>(5);
  cout<<"after f1"<<endl;
  return 0;
}
