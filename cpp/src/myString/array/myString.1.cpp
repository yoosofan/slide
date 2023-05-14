#include<iostream>
using namespace std;
void myStringCopyLoop(char *dst, const char *src)
{for(; *dst = *src; src++, dst++);}
void myStringCopy(char *dst, const char *src){
  *dst = *src;
  if(*src) myStringCopy(dst+1, src+1);
} // "ABC" {'A', 'B', 'C', '\0'} {'A', 'B', 'C', 0}
int myStringLength(const char *s){
  if(*s) return 1 + myStringLength(s+1);
  return 0;
}
int myStringLengthLoop(const char *s){
  const char *p = s;
  for(; *s; s++);
  return s-p;
}
class myString{
  char st[200];
  public:
  myString(const char *s){myStringCopy(st, s);}
  int len(void){return myStringLength(st);}
};
int main(){ const char *st="salam";  // string st;
  cout << myStringLength(st) << endl;
  myString s("Ali");
}
