// Error
#include<iostream>
using namespace std;
template<typename Type> class myArray{
  Type *a = nullptr;
  int n = 0;
  public:
  explicit myArray(int n=20){this->n=n; a=new Type[n];}
  ~myArray(){n=0;delete[] a; a=nullptr;}

  Type& operator[](int index){
    if(index<n && index >= 0)
      return a[index];
    throw "Index out of range";
  }
  myArray operator=(const myArray& f){
    delete[]a;
    n=f.n;
    a = new Type[n];
    for(int i=0;i<n;i++)
      a[i]=f.a[i];
    return *this;
  }
  myArray operator+=(const myArray& m1)
  {*this = *this + m1; return *this;}
  myArray(const myArray& f){
    n=f.n;
    a = new Type[n];
    for(int i=0; i < n; i++)
      a[i] = f.a[i];
  }
  myArray operator+(const myArray& m1){
    myArray retVal;
    int i;
    const myArray *pmax, *pmin;
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

  friend myArray<Type> operator-(
      const myArray<Type>& m1, const myArray<Type>& m2){
    myArray<Type> retVal;
    int i;
    const myArray<Type> *pmax, *pmin;
    pmax=m1.n>m2.n? &m1:&m2;
    pmin=m1.n<=m2.n?&m1:&m2;
    retVal.n=pmax->n;
    retVal.a=new Type[retVal.n];
    for(i=0;i<pmin->n;i++)    retVal.a[i]=pmin->a[i]-pmax->a[i];
    for(;i<pmax->n;i++)       retVal.a[i]=pmax->a[i];
    return retVal;
  }
  friend ostream& operator<<(
      ostream&o1, const myArray<Type>& m1){
    o1<<m1.n<<endl;
    for(int i=0;i<m1.n;i++)
      o1<<m1.a[i]<<endl;
    return o1;
  }
  friend istream& operator>>(
      istream&o1, myArray<Type>& m1){
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
  myArray<int> m1, m2, m3;
  myArray<double> dm;
  myArray<char> cm;
  cin >> m1;
  m3=m2=m1;   cout<<m1;  //myArray<int> m4(m1);  myArray<int>m5=m1;
  m1=m2+m3; cout<<m1;
  m1=m1+m3; cout<<m1;
  m1=m1-m2; cout<<m1;
  m1 +=m2;   cout<<m1;
  m1 = m2 + 45; cout << m1;// ???
}
