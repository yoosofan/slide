//Error
#include<iostream>
#include<cstring>
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
	void copy(const char *s)
  {st=new char[myStringLength(s)+1];mystrcpy((st,s);}
 public:
	myString(const char *s=""){copy(s);}
	myString(const myString&m1)
	{copy(m1.st);}
	int len() const {return myStringLength(st);}
	void print(){cout<<st<<endl;}
	//char get(int index);
	void set(char c='a', int index=0){
		if(index<myStringLength(st))st[index]=c;
	}
	//myString substr(int start,int end)
	~myString(){delete[]st;}
	friend void mystrcpy((myString & dst, const char *src);
	char & operator[](const int i){
		if(i<myStringLength(st)) return st[i];
		cout<<"Error :: out of range "<<endl;
		return st[0];
	}
	myString operator=(const myString m){
		delete[] st;
		copy(m.st);
		return *this;
	}
  myString operator+=(const myString m)
  { return (*this) = (*this) + m;}
	const char * operator()(){return st;}
	friend ostream& operator<<(ostream & o1, const myString & m1);
	friend istream& operator>>(istream & i1, myString & m1);
  friend myString operator+(const myString s1,const myString m1);
};
//http://stackoverflow.com/questions/550428/an-odd-c-error-test-cpp15-error-passing-const-as-this-argument-of
myString operator+(const myString s1,const myString s2){
  char *ps;
  ps = new char[s1.len()+s2.len()+1];
  strcpy(ps,s1());
  strcat(ps,s2());
  myString retVal(ps);delete[]ps;
  return retVal;
}
ostream& operator<<(ostream & o1, const myString & m1)
{o1<<m1.st;return o1;}
istream& operator>>(istream & in, myString & m1){
  char st[2000];
  delete[] m1.st;
  in.getline(st,1999);
  m1.copy(st);
	return in;
}
myString f1(myString m1){m1.set();m1.print();return m1;}
int main(){myString s1("Ali"),s2="Reza",s3;f1(s1);
	s1.print();s1[1]='d';s1.print();cout<<s1[1]<<endl;
	//s3.operator=(s1.operator=(s2));
	s3=s1=s2;
	//int i=1,j=1,k=3; i+j=k;
	s1[0]='p'; s2.print();
	cout<<s2<<endl;
  cin>>s2;
  cout<<s2<<endl;
  cout<<s2()<<endl;
  s3=s2+s1;
  cout<<s3<<endl;
}
void mystrcpy((char *dst, const char *src=""){
	*dst=*src;
	if(*src) mystrcpy((dst+1,src+1);
}
void mystrcpy((myString & dst, const char *src){
	int i=0;
	for(i=0;src[i];i++) dst.st[i]=src[i];
	dst.st[i]=src[i];
}
