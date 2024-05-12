#include<fstream>
#include<iostream>
//#include<iomanip>
using namespace std;
const int MAX_STR = 200;
int main(){
  char st[MAX_STR];
  string st2;
  ifstream f1("input.students.txt");
  if(!f1){
    cout << "couldn't open" << endl;
    throw "Cannot open file";
  }
  f1.read(st, MAX_STR - 1); // 199 charactes + \0 
  //cout << f1.read(st, MAX_STR - 1).gcount() << endl; // 199 charactes + \0 
  while(!f1.eof()){
  //~ while(getline(f1, st2)){
    //~ st[9]= 0;
    cout << st << endl;
    //~ cout << st2 << endl;
    //~ f1.seekg(9, ios::cur);
    f1.read(st, MAX_STR - 1);
  }
  cout << st << endl;
  f1.close();
  cout << std::hex << int('9') << endl;
  // sscanf
  //~ cout << std::hex << int('7') << endl;
  //~ cout << std::hex << int('4') << endl;
  //~ cout << std::hex << int('3') << endl;
}
