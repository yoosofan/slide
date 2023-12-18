#include <fstream>
#include<iostream>
using namespace std;
int main(){
  int i = 12;
  ofstream f1("a1.txt", ios::binary);
  if(!f1)
    throw "Cannot Open File";
  f1.write((char*) &i, sizeof(int));
  const char* st1="ABC";
  const char st2[]{'A', 'B', 'C', '\0'};
  const char st3[]{65, 66, 67, 0};
  const char st4[]{0x41, 0x42, 0x43, 0x0};
  f1.write((char*) st1, 4 * sizeof(char));
  f1.write((char*) st2, 4 * sizeof(char));
  f1.write((char*) st3, 4 * sizeof(char));
  f1.write((char*) st4, 4 * sizeof(char));
  f1.write((char*) &(++i), sizeof(int));
  // f1.write((char *) &(i++),sizeof(int));
  // f1.write((char *) &(i+1),sizeof(int));
  i = 0;
  f1.write((char*) &(i += 234234), sizeof(int));
  cout << std::hex << i << endl;
  f1.close(); // little Endian , Big Endian
}
