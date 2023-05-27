#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class myIntArray{ int *a; 
 fstream f1;int n;
 public:
  myIntArray(const char*fileName="input3.txt"){
    int i,b;
    f1.open(fileName); 
    if(!f1){cout<<"file ";exit(0);}
    //a = new int[2000]; int k=2000;
    for(i=0;f1>>b;i++);
    f1.close(); 
    a = new int[n=i];
    f1.open(fileName);
    for(i=0;i<n && f1>>a[i];i++);
    f1.close();
  }
  ~myIntArray(){delete[] a;}
  void sort(void){
    int i,j;
    for(i=0;i<n-1;i++)
      for(j=i+1;j<n;j++)
        if(a[i]>a[j]){int temp = a[i]; a[i]=a[j]; a[j]=temp;}
  }
  int search(int key){
    for(int i=0;i<n;i++) if(a[i]==key) return i;
    return -1;
  }
  void print(void){for(int i=0; i<n; i++) cout<<a[i]<<endl;}
};
int main(){
  myIntArray m1("input3.txt");m1.sort();cout<<m1.search(12)<<endl;
  m1.print();
  return 0;
}
