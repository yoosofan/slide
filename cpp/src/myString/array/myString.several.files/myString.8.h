#pragma once
#include<iostream>
using namespace std;
#include "stringFunctions.8.h"
class myString{
	char st[200];
	public:
	myString(const char *s)
	{strcpy(st,s);}
	int len();
	void print();
	void myStringCopy(const char *src){strcpy(st, src);}
};
