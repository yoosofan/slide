#include<iostream>
#include<fstream>
using namespace std;
class myIntArray{ 
  int* a = nullptr; 
  int n = 0;
  int max = 0;
  public:
  myIntArray(const char* fileName="input.integers.txt"){
    int i;
    fstream f1(fileName);
    if(!f1){
      cout << "file ";
      throw "cannot open file";
    }
    a = new int[2000]; 
    int k = 2000;
    for(i=0; f1 >> a[i]; i++)
      if(i > k-2){
        int* b = new int[k *= 2];
        for(int j=0; j < i; j++)
          b[j] = a[j];
        delete[] a;
        a = b;
      }
    n = i;
    max = k;
    f1.close();
  }
  ~myIntArray(){delete[] a;}
  void sort(){
    int i, j, temp;
    for(i=0; i<n-1; i++)
      for(j=i+1; j<n; j++)
        if(a[i] > a[j]){
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
