#pragma once
#include<iostream>
using namespace std;
//#include "myString.8.h"
class myString;
void myStringCopy(char *dst, const char *src);
void myStringCopy(myString & dst, const char *src);
int myStringLength(const char *s);
