#include<iostream>
using namespace std;
template<typename Type> class myArray{
  static const int MAX = 200;
  Type a[MAX];
  int n = 0;
public:
  void input(void){
    cout<<"Enter n: ";
    cin>>n;
    for(int i=0;i<n;i++){
      cout<<"Enter a["<<i<<"]: ";
      cin>>a[i];
    }
  }
  void print(void){
    cout << "n: " << n << endl;
    for(int i=0;i<n;i++)
      cout << a[i] << endl;
    }
};
int main(){
  myArray<int> m1,m2,m3;
  myArray<double> dm;
  myArray<char> cm;
  m1.input(); // m2.input();
  m1.print();
}
