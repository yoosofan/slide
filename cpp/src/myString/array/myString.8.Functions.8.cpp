#include "myString.8.Functions.8.h"
#include "myString.8.h"
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
void myStringCopy(myString& dst, const char *src){
  int i=0;
  for(i=0; src[i]; i++)
    dst.st[i]=src[i];
  dst.st[i]=src[i];
  // dst.st[i]= 0;
  // dst.st[i]= '\0'; // dst.st[i] = NULL
}
