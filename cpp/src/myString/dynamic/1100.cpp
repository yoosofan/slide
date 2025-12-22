#include<iostream>
using namespace std;
int stringLenght(const char* s){
  int i=0;
  while(*s++)
    i++;
  return i;
}
void stringCopy(char* dest, const char* src){
  for(*dest=*src; *dest; *++dest=*++src)
    ;
}
class myString{
  char *s;
  public:
  myString(const char *m=""){
    s = new char[stringLenght(m)+1];
    stringCopy(s,m);
  }
};
int main(){
  const char *s1="rose";
  cout << stringLenght(s1) << ":\t" << s1 << endl;
  char s2[20];
  stringCopy(s2,s1);
  cout << stringLenght(s2) << ":\t" << s2 << endl;
  myString m(s2);
}
