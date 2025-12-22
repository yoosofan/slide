#include <iostream>
#include <cstdlib>
using namespace std;
class myArray{// myArray.cpp
  static const int MAX = 100;
  double a[MAX]; int n;
  void copy(const  myArray& b){
    this -> n = b.n;
    for(int i = 0; i < n; i++)
	  this -> a[i] = b.a[i];
  }
  public:// myArray() = delete ;
  double get(const int index = 0 ) const{
    if(index < n) return a[index];
    cout << "Error in getting an element of myArray" << endl;
    return 0;
  }
  void set(const int index, const double value){
    if( index < n ) a[index] = value;
    cout << "Error accessing myArray " << endl;
  }
  myArray(const double *a=nullptr, int n=0){
    if( n > MAX )
      n = MAX ;
    for(this -> n = n--; n >= 0; n--)
      this -> a[n] = a[n];
  }
  explicit myArray(double x){
    n = 1;
    a[0] = x;
    cout << "construcotr myArray: " << a[0] << endl;
  }
  myArray(const myArray& b){
    cout << "copy construcotr" << endl;
    copy(b);
  }
  ~myArray(){
    cout << "Destructor" << endl;
  }
  void print() const{
    cout << " n = " << n << endl;
    for(int i = 0; i < n; i++)
      cout << "a[" << i << "] = " << a[i] << endl;
  }
  myArray& operator=(const myArray& b){
    cout << "Assignment myArray" << endl;
    copy(b);
    return *this;
  }
  myArray operator-() const{
    myArray c(*this);
    for(int i=0; i<n; i++)
      c.a[i] = - c.a[i];
    return c;
  }
  bool operator!() const{
    bool retVal = true;
    if( ! n ) // n == 0
      retVal = true;
    else{
      int i = 0;
      for(; i < n; i++)
        if( a[i] != 0 )
          break;
      if( i < n )
        retVal = false;
    }
    return retVal;
  }
  myArray operator++(){
    for(int i = 0; i < n; i++)
      a[i]++;
    return *this;
  }
  myArray operator--(int){
    myArray c(*this);
    for(int i = 0; i < n; i++)
      a[i] --;
    return c;
  }
  myArray operator--(){
    for(int i = 0; i < n; i++)
      a[i]--;
    return *this;
  }
  myArray operator++(int){
    myArray c(*this);
    for(int i = 0; i < n; i++)
      a[i] ++;
    return c;
  }
  double& operator[](int index){
    if(index >= n){
      cout << "index out of range: " << index << endl;
      index = 0;
      exit(0);
    }
    return a[index];
  }
  friend myArray operator+(const myArray& a, const myArray& b);
  friend ostream& operator<<(ostream& out1, const myArray& b);
  friend bool operator==(const myArray& a, const myArray& b);
  friend myArray operator-(const myArray& a, const myArray& b);
  friend istream& operator>>(istream& in1, myArray& b);
};
myArray operator-(const myArray& a, const myArray& b){
  myArray c;
  c.n = b.n;
  for(int i = 0; i < a.n; i++ )
    c.a[i] = a.a[i] - b.a[i];
  cout << "operator - in myArray" << endl;
  return c;
}
bool operator==(const myArray& a, const myArray& b){ // < > <= >= !=
  bool retVal = false;
  int i = 0;
  if(a.n == b.n)
    for(i = 0; i < a.n; i++)
      if(a.a[i] != b.a[i])
        break;
  if(i == a.n)
    retVal = true;
  return retVal;
}
istream& operator>>(istream& in1, myArray& b){
  // delete[] b.a;  b.a = nullptr;
  b.n = 0;
  cout << "Enter n ";
  in1 >> b.n;
  while( b.n < 0 || b.n > myArray::MAX ){
    cout << "number of element must be greater than 0 and less than  "
      << myArray::MAX << endl;
    in1 >> b.n;
  }
  // b.a = new double[b.n];
  if( b.n )
    for(int i = 0; i < b.n; i++){
      cout << "Enter a["<< i << "]: ";
      in1 >> b.a[i];
    }
  // else b.a = nullptr;
  return in1;
}
ostream& operator<<(ostream& out1, const myArray& b){
  out1 << "n = " << b.n << endl;
  for(int i = 0; i < b.n ; i++)
    out1 << "a[" << i << "]= " << b.a[i] << endl;
  return out1;
}
myArray operator+(const myArray& a, const myArray& b);
void f1(); void f2(myArray);
int main(){f1();}
myArray operator+(const myArray& a, const myArray& b){
    myArray c;
    c = a.n > b.n ? a : b;
    int min = a.n < b.n ? a.n : b.n;
    for(int i = 0; i < min; i++ )
      c.a[i] = a.a[i] + b.a[i];
    cout<< "operator + in myArray" << endl;
    cout << "In + " << endl << c << endl;
    return c;
}
void f1(){
  double x[]{10, 12, 34, 54};
  myArray d(x, sizeof(x) / sizeof(double));
  cin >> d ;
  cout << d[1] << endl;
  d[1] = 15;
  d = d + myArray(5) ;
  // d.operator=(d.operator+(5));
  d = myArray(5) + d ;
  // d.print();
  // cout << "d -- " << endl << d -- << endl;
  // cout << "-- d " << endl << -- d << endl;
  // operator<<(operator<<(cout, d), endl);

  // cout << "before call f2" << endl;
  // f2(d);
}
void f2(myArray k){
  k.print();
  if( !k )
    cout << "k is empty (k.n == 0 or all k.a[i] == 0 ) " << endl;
  else
    cout << "k is not empty (k.n != 0 and exists i for k.a[i] != 0 ) " << endl;
  myArray b;
  if( !b )
    cout << "b is empty (b.n == 0 or all b.a[i] == 0 ) " << endl;
  else
    cout << "b is not empty (b.n != 0 and exists i for b.a[i] != 0 ) " << endl;
}
