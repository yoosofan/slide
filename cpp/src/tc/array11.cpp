#include<iostream>
using namespace std;
template<class Type> class array{  Type *a;  int n;  public:
  array(int n=20)  {this->n=n;a=new Type[n];}
  ~array(){n=0;delete[] a; a=0;}
  Type & operator[](int index){  if(index<n && index >= 0) return a[index];
    return a[0];
  }array operator=(array f){ delete[]a;n=f.n;a=new Type[n];
    for(int i=0;i<n;i++)a[i]=f.a[i];
    return *this;
  } array operator+=(array m1){ *this =m1+*this; return *this;}
  array(const array &f){n=f.n;a=new Type[n];    for(int i=0;i<n;i++)a[i]=f.a[i];  }
  array operator+(array m1){array retVal;int i; array *pmax,*pmin;
    pmax=m1.n>this->n? &m1:this;     pmin=m1.n<=this->n?&m1:this;
    retVal.n=pmax->n;     retVal.a=new Type[retVal.n];
    for(i=0;i<pmin->n;i++)     retVal.a[i]=pmin->a[i]+pmax->a[i];
    for(;i<pmax->n;i++)        retVal.a[i]=pmax->a[i];
    return retVal;
  } template<class T> friend array<T> operator-(array<T>&, array<T>&);
  template<class T>friend ostream& operator<<(ostream&o1,array<T> m1);
}; template<class T> array<T> operator-(array<T>&m1,array<T>&m2){array<T> retVal;int i;
    array<T> *pmax,*pmin; pmax=m1.n>m2.n? &m1:&m2; pmin=m1.n<=m2.n?&m1:&m2;
    retVal.n=pmax->n; retVal.a=new T[retVal.n];
    for(i=0;i<pmin->n;i++)    retVal.a[i]=pmin->a[i]-pmax->a[i];
    for(;i<pmax->n;i++)       retVal.a[i]=pmax->a[i];
    return retVal;
} template<class T> ostream& operator<<(ostream&o1,array<T> m1)
{o1<<m1.n<<endl;  for(int i=0;i<m1.n;i++)    o1<<m1.a[i]<<endl;  return o1;}
int main(){array<int> m1,m2,m3; array<double> dm;   array<char> cm;  cout<<m1;
  m3=m2=m1;   cout<<m1;  //array<int> m4(m1);  array<int>m5=m1;
  m1=m2+m3; cout<<m1;   m1=m1+m3; cout<<m1;  m1=m1-m2; cout<<m1;
  m1+=m2;   cout<<m1;  return 0;
}
