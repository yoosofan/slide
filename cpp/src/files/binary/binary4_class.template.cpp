#include <fstream>
#include<iostream>
#include <cstdlib>
using namespace std;
template<typename T>class myArray{   
  fstream f1;
  public:
  myArray(const char* fname = "temp1.in"){
    f1.open(fname, ios::in | ios::out | ios::binary);
    if(!f1){
      f1.open(fname, ios::out | ios::binary);
      if(!f1){ 
        cout << "Can not open file" << endl; 
        exit(0);
      }else{
        f1.close(); 
        f1.open(fname, ios::in |ios::out |ios::binary);
      }
     }
  }
  ~myArray(){ f1.close();}
  T read(int index){ T j;
    f1.seekg(index * sizeof(T), ios::beg); 
    f1.read((char*) &j, sizeof(T));
    return j;
  }
  void write(const T j, const int index){
    f1.seekp(index * sizeof(T), ios::beg);
    f1.write((char*) &j , sizeof(T));
  }
  T readNext(){ T j;
    f1.read((char*) &j , sizeof(T));
    return j;
  }
  void writeNext(T j){f1.write((char*) &j, sizeof(T));}
  void rewind(){
    f1.seekg(0, ios::beg);
    f1.seekp(0, ios::beg);
  }
 };
int main(){
  myArray<int> myi("temp4.in");
  myi.writeNext(16);  myi.writeNext(19);  myi.rewind();
  cout << myi.readNext() << endl;
  cout << myi.readNext() << endl;
  cout << myi.read(0) << endl;
  cout << myi.read(1) << endl;
  myArray<double> my2; my2.writeNext(4.23);
  my2.writeNext(5.34); my2.writeNext(67.43); my2.rewind();
  cout << my2.readNext() << endl << my2.readNext() << endl;
}
