#include <iostream> 
using namespace std;
struct myArray{// 100488.02.this
  static const int MAX = 100;
  static int other_static;
  double a[MAX];
  int n; // myArray* this = & ...
  myArray(const double a[], int n){
    if( n > MAX) n = MAX ;
    for(this->n = n--; n >= 0; n--)
      this-> a[n] = a[n];
  }
  void print(void){int i=0;
    cout<<" n= "<<this->n<<"\tother:" 
      << other_static << endl;
    for(; i < (*this).n; i++)
      cout<< this->a[i] << endl;
  }
  static void printStatic(void){
    cout<<"MAX: "<<MAX<<"\tother: " 
      << other_static << endl;
  }
};
int myArray::other_static = 20 ;
int main(){double x[]{10, 12, 34, 54};
  myArray d(x, 4); myArray b(x, 4);
  b.printStatic(); d.print();b.a[1]=94;
  b.other_static = 94;d.print();
  b.print(); myArray::printStatic();
}