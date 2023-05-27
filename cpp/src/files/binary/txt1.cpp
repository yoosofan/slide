#include<fstream>
#include<iostream>
using namespace std;
int main(){
  int i = 12;
  ofstream f1("a1.txt");
  if(!f1)
    throw "Cannot Open File";
  f1 << i << ' ';
  const char* st1="ABC"; 
  const char st2[]{'A', 'B', 'C', '\0'};
  const char st3[]{65, 66, 67, 0};
  const char st4[]{0x41, 0x42, 0x43, 0x0};
  f1 << st1 << ' ';
  f1 << st2 << '\t';
  f1 << st3 << endl;
  f1 << st4 << ' ';
  f1 << ++i << '\t';
  f1 << ++i << ' ';
  f1 << (i += 234234) << endl ;
  f1.close();
}
