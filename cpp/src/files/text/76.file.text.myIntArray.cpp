#include<iostream>
#include<fstream>
using namespace std;
class myIntArray{
  const static int N = 2000;
  int a[N];
  ifstream f1;
  int n;
 public:
  myIntArray(const char* fileName = "input.integers.txt"){
    int i;
    f1.open(fileName);
    if(!f1){
      cout<<"file ";
      throw "cannot open file";
    }
    for(i=0; f1 >> a[i] && i<N; i++)
      ;
    n = i;
    f1.close();
  }
  void sort(){
    int i,j, temp;
    for(i=0;i<n-1;i++)
      for(j=i+1;j<n;j++)
        if(a[i]>a[j]){
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
  }
  int search(int key){
    for(int i=0; i < n; i++)
      if(a[i] == key)
        return i;
    return -1;
  }
  void print(){
    for(int i=0; i<n; i++)
      cout << a[i] << endl;
  }
};
int main(){
  myIntArray m1("input.integers.txt");
  m1.sort();
  cout << m1.search(12) << endl;
  m1.print();
}
