// Error
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
  ~myArray(){
    f1.close();
  }
  T read(int index){
    T data;
    f1.seekg(index * sizeof(T), ios::beg); // ios::end   ios::cur
    f1.read((char*) &data, sizeof(T));
    return data;
  }
  void write(const T data, int index){
    f1.seekp(index * sizeof(T), ios::beg);
    f1.write((char*) &data, sizeof(T));
  }
  T readNext(void){
    T data;
    f1.read((char*) &data , sizeof(T));
    return data;
  }
  void writeNext(T data){
    f1.write((char*) &data, sizeof(T));
  }
  void rewind(void){
    f1.seekg(0, ios::beg);
    f1.seekp(0, ios::beg);
  }
 };
struct student{
  char name[20];
  char stdno[14];
  double avg;
  friend ostream & operator<<(ostream & o1, student m1){
    o1 << "( " << m1.name << " , " << m1.stdno
      << " , " << m1.avg << " ) ";
    return o1;
  }
  char& operator[](int& index);
};
int mystrlen(char* s){
  int i;
  for(i = 0; s[i]; i++);
  return i;
}
char& student::operator[](int& index){
  if(index < mystrlen(stdno))
    return stdno[index];
  return stdno[0];
}
int main(){
  myArray<student> myi("temp6.in");
  student st1 {"Ali", "933424", 15.1};
  cout << st1[1] << endl;
  st1[1] = '2';
  myi.writeNext(st1);
  strcpy(st1.name, "Reza");
  strcpy(st1.stdno, "923434");
  st1.avg = 14.2;
  myi.writeNext(st1);
  myi.rewind();
  cout << myi.readNext() << endl;
  //operator<<(cout,myi.readNext());
  //student *ps= & myi.readNext(); Error
  cout << myi.readNext() << endl;
  cout << myi.read(0) << endl;
  cout << myi.read(1) << endl;
  //myi.write(54,10);
  //cout<<myi.read(25)<<endl<<endl;
  return 0;
}
