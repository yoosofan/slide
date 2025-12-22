// warning
/*
g++ -Wall -o "myString.41" "myString.41.cpp" (in directory: /media/ahmad/back/yoosofanFiles/yoosofan/course/cpp/semester/932/931212)
myString.41.cpp: In member function ‘char& myString::operator[](int)’:
myString.41.cpp:16:17: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
   if(i<strlen(st)) return st[i];
                 ^
Compilation finished successfully.
*/
#include<iostream>
#include<cstring>
using namespace std;
class myString{char *st;
	void copy(const char *s)
  {st=new char[strlen(s)+1];strcpy(st,s);}
 public:
	myString(const char *s=""){copy(s);}
	myString(const myString&m1)
	{copy(m1.st);}
	int len() const {return strlen(st);}
	//myString substr(int start,int end)
	~myString(){delete[]st;}
	char & operator[](const int i){
		if(i<strlen(st) ) return st[i];
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
	friend ostream& operator<<(ostream & o1, const myString & m1);
	friend istream& operator>>(istream & i1, myString & m1);
  friend myString operator+(const myString s1,const myString m1);
};
myString operator+(const myString s1,const myString s2){
  char *ps;
  ps = new char[s1.len()+s2.len()+1];
  strcpy(ps,s1.st);
  strcat(ps,s2.st);
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
int main(){myString s1("Ali"),s2="Reza",s3;
  //cin>>s2;
  cout<<s2<<endl;
  s3=s2+s1;
  cout<<s3<<endl;
  s2+=s1;
  cout<<s2<<endl;
}
