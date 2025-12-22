#include<iostream>
using namespace std;
// const int MAX=200;
// #define MAX 200
template<typename Type> class myArray{
  static const int MAX = 200;
  Type a[MAX];
  int n = 0;
  public:
  void input(void){
    do{
      cout << "Enter number of Elements > 0 :";
      cin >> n;
    }while(n < 1);
    for(auto i=0 ; i < n; i++){
      cout << "Enter a[" << i << ']' ;
      cin >> a[i];
    }
  }
};
int main(){
  myArray<int> m1, m2, m3;
  myArray<double> dm;
  myArray<char> cm;
  myArray<string> sm;
}
