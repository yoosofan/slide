#include<iostream>
using namespace std;
template<typename Type> class array{
  Type *a = nullptr;
  int n = 0;
  public:
  explicit array(int n=20){this->n=n; a=new Type[n];}
  ~array(){n=0;delete[] a; a=nullptr;}

  Type& operator[](int index){
    if(index<n && index >= 0) 
      return a[index];
    throw "Index out of range";
  }
  array operator=(const array& f){
    delete[]a;
    n=f.n;
    a = new Type[n];
    for(int i=0;i<n;i++)
      a[i]=f.a[i];
    return *this;
  }
  array operator+=(const array& m1)
  {*this = *this + m1; return *this;}
  array(const array& f){
    n=f.n;
    a = new Type[n]; 
    for(int i=0; i < n; i++)
      a[i] = f.a[i];  
  }
  array operator+(const array& m1){
    array retVal;
    int i; 
    const array *pmax, *pmin;
    pmax = m1.n > this->n ? &m1 : this; 
    pmin = m1.n <= this->n ? &m1 : this;
    // pmax -> n = 5;
    // pmax = pmin;
    retVal.n = pmax->n; 
    retVal.a = new Type[retVal.n];
    for(i = 0; i < pmin->n; i++) 
      retVal.a[i] = pmin->a[i] + pmax->a[i];
    for(; i < pmax->n;i++)    
      retVal.a[i]=pmax->a[i];
    return retVal;
  }
  array operator+(const int m1){
    array retVal(*this);
    if(this->n <= 0){
      retVal.a = new Type[retVal.n=1];
      retVal.a[0] = 0;
    }
    retVal.a[0] += m1;
    return retVal;
  }
  friend array<Type> operator-(
      const array<Type>& m1, const array<Type>& m2){
    array<Type> retVal;
    int i; 
    const array<Type> *pmax, *pmin;
    pmax=m1.n>m2.n? &m1:&m2;
    pmin=m1.n<=m2.n?&m1:&m2;
    retVal.n=pmax->n; 
    retVal.a=new Type[retVal.n];
    for(i=0;i<pmin->n;i++)    retVal.a[i]=pmin->a[i]-pmax->a[i];
    for(;i<pmax->n;i++)       retVal.a[i]=pmax->a[i];
    return retVal;
  }
  friend ostream& operator<<(
      ostream&o1, const array<Type>& m1){
    o1<<m1.n<<endl;
    for(int i=0;i<m1.n;i++)
      o1<<m1.a[i]<<endl;
    return o1;
  }
  friend istream& operator>>(
      istream&o1, array<Type>& m1){
    cout << "Enter number of Elements: ";
    o1 >> m1.n;
    for(int i=0; i < m1.n; i++){
      cout << "Enter a[" << i << "]: ";
      o1 >> m1.a[i];
    }
    return o1;
  }
};
int main(){
  array<int> m1, m2, m3; 
  array<double> dm; 
  array<char> cm;
  cin >> m1;
  m3=m2=m1;   cout<<m1;  //array<int> m4(m1);  array<int>m5=m1;
  m1=m2+m3; cout<<m1;
  m1=m1+m3; cout<<m1;
  m1=m1-m2; cout<<m1;
  m1 +=m2;   cout<<m1<<endl;
  m1 = m2 + 45;cout <<"m2::"<<endl<<m2<<endl; 
  cout << m1;
}
