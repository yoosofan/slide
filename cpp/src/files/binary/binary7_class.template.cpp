#include <fstream>
#include<iostream>
#include <cstdlib>
#include<cstring>
using namespace std;
template<typename T> class myArray{
  fstream f1;
  public:
  myArray(const string fname = "temp1.in"){
    f1.open(fname, ios::in | ios::out | ios::binary);
    if(!f1){
      f1.open(fname, ios::out | ios::binary);
      if(!f1)
        throw fname + "Can not open file";
      else{
        f1.close();
        f1.open(fname, ios::in | ios::out | ios::binary);
      }
    }
  }
  ~myArray(){ f1.close();}
  T read(int index){
    T j;
    f1.seekg(index * sizeof(T), ios::beg);
    f1.read((char*) &j , sizeof(T));
    return j;
  }
  void write(T j, int index){
    f1.seekp(index * sizeof(T), ios::beg);
    f1.write((char*) &j, sizeof(T));
  }
  T readNext(){
    T j;
    f1.read((char*) &j, sizeof(T));
    return j;
  }
  void writeNext(T j){
    f1.write((char*) &j, sizeof(T));
    f1.flush();
  }
  void rewind(){
    f1.seekg(0, ios::beg);
    f1.seekp(0, ios::beg);
  }
 };
struct student{
  char name[20];
  char stdno[14];
  double avg;
  friend ostream& operator<<(ostream & o1, student m1){
    o1<<"( "<<m1.name<<" , "<<m1.stdno<<
    " , "<<m1.avg<<" ) ";
    return o1;
  }
  char& operator[](const int& index){
    if(unsigned(index) < strlen(stdno))
      return stdno[index];
    return stdno[0];
  }
};
int main(){
  myArray<student> myi("temp6.in");
  student st1 = {"Ali", "933424", 15.1};
  int a = 1;
  cout << st1[a] << endl;
  st1[a] = '2';
  myi.writeNext(st1);
  strcpy(st1.name, "Reza");
  strcpy(st1.stdno, "923434");
  st1.avg = 14.2;
  myi.writeNext(st1);
  myi.rewind();
  cout << myi.readNext() << endl;
  cout << myi.readNext() << endl;
  cout << myi.read(0) << endl;
  cout << myi.read(1) << endl;
}
