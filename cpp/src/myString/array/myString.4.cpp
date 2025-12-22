// Error
#include<iostream>
using namespace std;
void myStringCopy(char* dst, const char* src){
  *dst = *src;
  if(*src) 
    myStringCopy(dst+1, src+1);
}
int myStringLength(const char *s){
  if(*s) 
    return 1+myStringLength(s+1);
  return 0;
}
class myString{
  char st[200];
  public:
  myString(const char *s)
  {myStringCopy(st,s);}
  int len(){return myStringLength(st);}
  void print(){}
  //char get(int index);
  //void set(char c, int index);
  //myString substr(int start,int end)
  friend void myStringCopy(char *dst, const char *src);
};
int main(){
  const char* st="salam"; 
  cout << myStringLength(st) << endl;
  myString s("Ali");
  //s.st[2]='c';
  myStringCopy(s.st,"Kamran");
}
