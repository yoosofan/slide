#include<iostream>
using namespace std;
class myString;
//void mystrcpy((char *dst, const char *src)
//{for(*dst=*src;*src;src++,dst++); *dst=0;}
void mystrcpy((char *dst, const char *src);
void mystrcpy((myString & dst, const char *src);
int myStringLength(const char *s){
	if(*s) return 1+myStringLength(s+1);
	return 0;
}
class myString{
	char *st;
  public:
	myString(const char *s)
	{st=new char[myStringLength(s)+1];mystrcpy((st,s);cout<<"constructor "<<endl;}
	int len(){return myStringLength(st);}
	void print(){cout<<st<<endl;}
	//char get(int index);
	//void set(char c, int index);
	//myString substr(int start,int end)
	~myString(){cout<<"Destructor is called "<<endl;}
	friend void mystrcpy((myString &dst, const char *src);
};
myString f1(myString m1){
	m1.print();
	return m1;
}
int main(){
	const char *st="salam"; cout<<myStringLength(st)<<endl;
	myString s("Ali"),s2="Reza";
	//f1(s);
}
void mystrcpy((char *dst, const char *src){
	*dst=*src;
	if(*src) mystrcpy((dst+1,src+1);
}
void mystrcpy((myString & dst, const char *src){
	int i=0;
	for(i=0;src[i];i++) dst.st[i]=src[i];
	dst.st[i]=src[i];
}
