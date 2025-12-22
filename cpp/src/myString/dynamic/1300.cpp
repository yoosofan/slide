#include<iostream>
using namespace std;
int stringLenght(const char *s){int i=0;while(*s++)i++; return i;}
void stringCopy(char*dest,const char*src){for(*dest=*src;*dest;*++dest=*++src);}
class myString{
  char* s;
  public:
  myString(const char *m=""){
    s = new char[stringLenght(m)+1];
    stringCopy(s,m);
  }
  int len(){return stringLenght(s);}
  ~myString(){delete[]s;}
};
int main(){
  myString m("rose");
}
