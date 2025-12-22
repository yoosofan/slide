// myString(const myString&mys){init(mys.s);}
#include<iostream>
using namespace std;
const int MaxTempStringLenght=200;
int stringLenght(const char *s){int i=0;while(*s++)i++; return i;}
void stringCopy(char*dest,const char*src){for(*dest=*src;*dest;*++dest=*++src);}
class myString{
  char *s;
  void init(const char *m){s=new char[stringLenght(m)+1];stringCopy(s,m);}
  public:
  myString(const char *m=""){init(m);}
  myString(const myString&mys){init(mys.s);}
  int len(){return stringLenght(s);}
  ~myString(){delete[]s;}
  myString& operator=(myString mys)
  {delete[] s; init(mys.s); return *this;}
  char& operator[](int index){
    if(index<len()) return s[index];
    throw "index out of range";
  }
  myString operator+(myString &mys){
    char *st=new char[len()+mys.len()+1];
    stringCopy(st,s);
    stringCopy(st+len(),mys.s);
    myString mys1(st);
    return mys1;
  }
  friend ostream& operator<<(ostream&out,myString &);
  friend istream& operator>>(istream&in,myString& );
};
ostream& operator<<(ostream&out,myString &mys){out<<mys.s;return out;}
istream& operator>>(istream&in,myString&mys)
{char st[MaxTempStringLenght];in.getline(st,MaxTempStringLenght-1);delete[] mys.s;mys.init(st);return in;}
int main(){
  myString m1("rose"),m2,m3;m2=m1;
  cin>>m1;cout<<m1.len()<<":\t"<<m1<<endl;
  cout<<m2.len()<<":\t"<<m2<<endl;
  m3=m1+m2; cout<<m3<<endl;
  cout<<m2[2]<<endl;
  m2[2]='z';
  cout<<m2<<endl;
  return 0;
}
