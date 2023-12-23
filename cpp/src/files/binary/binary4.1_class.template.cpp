#include <fstream>
#include<iostream>
#include <cstdlib>
#include<cstring>
using namespace std;
template<typename T> class myArray{
  fstream f1;
  public:
  myArray(const char* fname = "temp1.in"){
    f1.open(fname, ios::in | ios::out | ios::binary);
    if(!f1){
      f1.open(fname, ios::out | ios::binary);
      if(!f1){
        cout << "Can not open file" << endl;
        throw "Cannot Open File";
      }else{
        f1.close();
        f1.open(fname, ios::in | ios::out | ios::binary);
      }
    }
  }
  ~myArray(){f1.close();}
  T read(const int index){
    T data;
    f1.seekg(index * sizeof(T), ios::beg); 
    f1.read((char*) &data, sizeof(T));
    return data;
  }
  void write(const T&data,const int index){
    f1.seekp(index * sizeof(T), ios::beg);
    f1.write((char*) &data, sizeof(T));
  }
  T readNext(void){T data;
    f1.read((char*) &data, sizeof(T));
    return data;
  }
  void writeNext(T data)
  {f1.write((char*) &data, sizeof(T));}
  void rewind(void)
  {f1.seekg(0, ios::beg);f1.seekp(0, ios::beg);}
};
struct student{
  char name[20]; char stdno[14];
  double avg;
  void print(void){
    cout << "name:" << name << endl << "stdno:" << stdno
      << endl << "avg:" << avg << endl;
  }
};
int main(){
  myArray<student> myi("temp6.in");
  student st1{"Ali", "933424", 15.1};
  myi.writeNext(st1);
  strcpy(st1.name, "Reza");
  strcpy(st1.stdno, "923434");
  st1.avg = 14.2;
  myi.writeNext(st1); myi.rewind();
  myi.readNext().print();
  myi.readNext().print();
  myi.read(0).print();myi.read(1).print();
}
