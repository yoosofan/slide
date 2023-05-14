#include<iostream>
using namespace std;
#include "stringFunctions.8.h"
#include "myString.8.h"
class myString;
void myStringCopy(char *dst, const char *src){
    *dst=*src;
    if(*src) myStringCopy(dst+1,src+1);
}
void myStringCopy(myString & dst, const char *src){
    int i=0;
    for(i=0;src[i];i++) dst.st[i]=src[i];
    dst.st[i]=src[i];
}

int myStringLength(const char *s){
    if(*s) return 1+myStringLength(s+1);
    return 0;
}
