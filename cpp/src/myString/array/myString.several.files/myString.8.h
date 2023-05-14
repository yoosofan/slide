#pragma once
#include<iostream>
using namespace std;
#include "stringFunctions.8.h"
class myString{
	char st[200];
	public:
	myString(const char *s)
	{myStringCopy(st,s);}
	int len(void);
	void print(void);
	//char get(int index);
	//void set(char c, int index);
	//myString substr(int start,int end)
	friend void myStringCopy(myString &, const char *src);
};
