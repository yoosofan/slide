#include<iostream>
#include<fstream>
using namespace std;
class myIntArray{
  static const int N = 2000;
  int a[N]; 
  ifstream f1;
  int n;
  public:
  myIntArray(const char* fileName = "input.integers.txt"){
    int i;
    f1.open(fileName); 
    if(!f1){
      cout << "file ";
      throw "cannot open file"; // throw
    }
    for(i=0; f1 >> a[i] && i < N; i++) 
      ; 
    n = i;
    f1.close();
  }
  void sort(void){
    int i, j;
    for(i = 0; i < n-1; i++)
      for(j = i+1; j < n; j++)
        if(a[i] > a[j]){
          int temp = a[i]; 
          a[i] = a[j]; 
          a[j]=temp;
        }
  }
  int search(int key){
    for(auto i = 0; i < n; i++) 
      if(a[i] == key) 
        return i;
    return -1;
  }
  void print(void){
    for(auto i = 0; i < n; i++) 
      cout << a[i] << endl;
    }
  bool operator!(){return n>0 ? false: true;}
};
int main(){
  myIntArray m1("input.integers.txt");
  m1.sort();
  cout << m1.search(12) << endl;
  m1.print();
  if(!m1) cout << "empty" << endl;
  else cout << "have element" << endl;

}
