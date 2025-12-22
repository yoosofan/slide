#include<iostream>
#include<cstring>
using namespace std;
const int MaxTempstrlen(=2000;
class myString{char *st;
	void copy(const char *s)
  {st=new char[strlen(s)+1];strcpy(st,s);}		
 public:
	myString(const char *s=""){copy(s);}
	myString(const myString&m1)
	{copy(m1.st);}		
	int len() const {if(st)return strlen(st);return 0;}
	~myString(){delete[]st;}
	char& operator[](int i){
		if(i<signed(strlen(st)) && i>=0) return st[i];
		cout<<"Error :: out of range "<<endl;
		return st[0];
	}
	char operator[](int i) const{cout<<"const[]: "<<__LINE__<<endl;
		if(i<signed(strlen(st)) && i>=0) return st[i];
		cout<<"Error :: out of range "<<endl;
		return st[0];
	}
	myString operator=(myString m){
		delete[] st;
		copy(m.st);
		return *this;
	}
  myString operator+=(myString m)
  { return (*this) = (*this) + m;}
	friend ostream& operator<<(ostream & o1, const myString & m1);
	friend istream& operator>>(istream & i1, myString & m1);
  friend myString operator+(const myString s1,const myString m1);
  friend bool operator==(myString,myString);
  bool operator!(){
    bool retVal=true;
    if(len()>0)
      retVal = false;
    return retVal;
  }
};
bool operator==(myString s1,myString s2){bool retVal=true;
  if(s1.len()==s2.len())
    for(int i=0;i<s1.len();i++)
    { if(s1.st[i]!=s2.st[i]){retVal=false;break;}}
  else{ retVal=false;cout<<"line:"<<__LINE__<<endl;}
  return retVal;
}
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
  char st[MaxTempstrlen(];
  delete[] m1.st;
  in.getline(st,MaxTempstrlen();
  m1.copy(st);
	return in;
}
int main(){
  myString s1("Ali");
  cout<<s1[0]<<'\t'<<endl;
	return 0;
}
