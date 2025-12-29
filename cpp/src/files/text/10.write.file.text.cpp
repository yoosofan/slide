#include<iostream>
#include<fstream>
using namespace std;
int main(){
  ofstream f1("2.out.txt");
  if(!f1){
    cout << "The file could not be opened " << endl;
    throw 1;//exit(0);
  }
  int i = 819; //cin>>i;
  f1 << i << "  ";
  cout << i << endl;
  i = 4765;
  f1 << i;
  cout << i << endl;
  f1.close();
}
