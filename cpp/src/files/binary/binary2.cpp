#include <fstream>
#include<iostream>
using namespace std;
void write2file(const char* fname);
void readFromFile(const char* fname);
int main(){
  write2file("a1.bin");
  readFromFile("a1.bin");
}
void write2file(const char* fname = "a1.bin"){
  ofstream f1(fname, ios::binary);
  // fstream f1(fname, ios::out | ios::binary);
  if(!f1) throw "Cannot Open File";
  int i = 6, j = 1;
  f1.write((char*) &i, sizeof(int));
  for(; i > 0; i--)
    f1.write((char*) &(j += 3), sizeof(int));
  f1.close();
}
void readFromFile(const char* fname = "a1.bin"){
    //fstream f3(fname, ios::in | ios::binary);
    ifstream f3(fname, ios::binary);
    if(!f3)   throw "Cannot Open File";
    int n, j;
    f3.read((char*) &n, sizeof(int));
    for(; n > 0; n--){
        f3.read((char*) &j, sizeof(int));
        cout << j << endl;
    }
    f3.close();
}