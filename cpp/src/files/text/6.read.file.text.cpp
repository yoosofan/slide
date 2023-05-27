#include<iostream>
#include<fstream>
using namespace std;
int main(){
  ifstream f1("input.integers.txt");
  if(!f1){
    cout << "The file could not be opened " << endl;
    throw 1;
  }
  int i; //cin>>i;
  f1 >> i;
  cout << i << endl;
  f1 >> i;
  cout << i << endl;
  f1.close();
}
