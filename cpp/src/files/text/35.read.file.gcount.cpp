#include<fstream>
#include<iostream>
using namespace std;
const int MAX_STR = 200;
int main(){
  char st[MAX_STR];
  ifstream f1("input.students.txt");
  if(! f1){
    cout << "couldn't open" << endl;
    throw 1;
  }
  //cout<<f1.getline(st,200).gcount()<<endl;
  while(f1.getline(st, MAX_STR - 1).gcount() > 0 )    
    cout << st << endl;
  f1.close();
  int i; cout << "Enter i: "; 
  cout << (cin >> i).gcount() << endl;
}
