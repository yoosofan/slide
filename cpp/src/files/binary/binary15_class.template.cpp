#include <fstream>
#include<iostream>
#include <cstdlib>
#include<cstring>
using namespace std;
template<typename T>class myFileArray{fstream f1;
   public:
   myFileArray(const char *fname="temp1.in"){
     f1.open(fname,ios::in|ios::out|ios::binary);
     if(!f1){
       f1.open(fname,ios::out|ios::binary);
       if(!f1){ cout<<"Can not open file"<<endl; exit(0);}
       else{f1.close(); f1.open(fname,ios::in|ios::out|ios::binary);}
     }
   }
   ~myFileArray(){ f1.close();}
   T read(int index){
     T j;
     f1.seekg(0,ios::end);
     long long int l1=f1.tellg();
     l1 /= sizeof(T);
     if(index>=l1){cout<<"Index is out of range\n";exit(0);}
     f1.seekg(index*sizeof(T),ios::beg); // ios::end   ios::cur
     f1.read((char *)&j , sizeof(T));
     return j;
   }
   void write(T j, int index){
     f1.seekg(0,ios::end);
     long long int l1=f1.tellg();
     l1 /= sizeof(T);
     if(index>l1){cout<<"Index is out of range\n";exit(0);}
     f1.seekp(index*sizeof(T),ios::beg);
     f1.write((char *) &j , sizeof(T));
   }
   T readNext(){
     T j;
     long long int pos=f1.tellg();
     f1.seekg(0,ios::end);
     long long int l1=f1.tellg();
     if(pos == l1)
     {cout<<"Index is out of range\n";exit(0);}
     f1.seekg(pos,ios::beg);
     f1.read((char *)&j , sizeof(T));
     return j;
   }
   void writeNext(T j){
     f1.write((char *)&j, sizeof(T));
     f1.flush();
   }
   void rewind(){ f1.seekg(0,ios::beg);f1.seekp(0,ios::beg);}
 };
struct student{
  char name[20];
  char stdno[14];
  double avg;
  // Error
  //friend ostream& operator<<(ostream & o1, student &);
  friend ostream& operator<<(ostream & o1, student );
  char & operator[](int  index);
};
int mystrlen(char *s){int i;for(i=0;s[i];i++); return i;}
//if(unsigned(index)<strlen(stdno)) return stdno[index];
char & student::operator[](int  index){
  if(index<mystrlen(stdno)) return stdno[index];
  return stdno[0];
}
// Error
//ostream& operator<<(ostream & o1, student & m1){
ostream& operator<<(ostream & o1, student  m1){
  o1<<"( "<<m1.name<<" , "<<m1.stdno<<
  " , "<<m1.avg<<" ) ";
  return o1;
}
int main(){myFileArray<student> myi("temp6.in");
  student st1={"Ali","933424",15.1};int a=1;
  cout<<st1<<endl;operator<<(cout,st1);
  cout<<st1[a]<<endl; st1[1]='2'; st1.operator[](1) = '2';
  myi.writeNext(st1);
  strcpy(st1.name,"Reza");strcpy(st1.stdno,"923434");
  st1.avg=14.2; myi.writeNext(st1); myi.rewind();
  cout<<myi.readNext()<<endl;
  //operator<<(cout,myi.readNext());
  //student *ps= & myi.readNext(); Error
  cout<<myi.readNext()<<endl<<endl;
  cout<<myi.read(0)<<endl;
  cout<<myi.read(1)<<endl;
  myi.write(st1,10);
  cout<<myi.read(25)<<endl<<endl;
}
