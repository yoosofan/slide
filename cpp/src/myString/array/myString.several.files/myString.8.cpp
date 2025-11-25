#include<iostream>
#include<cstring>
using namespace std;
#include "stringFunctions.8.h"
#include "myString.8.h"
int myString::len(){return myStringLength(st);}
void myString::print(){}

void myStringCopy(char *dst, const char *src){strcpy(dst, src);}
int myStringLength(const char *s){return strlen(s);}
