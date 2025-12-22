// Error : unwanted free memory
#include<iostream>
using namespace std;
int stringLenght(const char *s){int i=0;while(*s++)i++; return i;}
void stringCopy(char*dest,const char*src){for(*dest=*src;*dest;*++dest=*++src);}
class myString{
  char *s;
  void init(const char *m=""){s=new char[stringLenght(m)+1];stringCopy(s,m);}
  public:
  myString(const char *m=""){init(m);}
  int len(){return stringLenght(s);}
  ~myString(){delete[]s;}
  friend ostream& operator<<(ostream&out,myString );
  friend istream& operator>>(istream&in,myString );
};
ostream& operator<<(ostream&out,myString m){out<<m.s;return out;}
istream& operator>>(istream&in,myString m) // myString &m
{char st[200];in.getline(st,199);delete[] m.s;m.init(st);return in;}

int main(){
  myString m("rose");
  cin>>m;cout<<m.len()<<":\t"<<m<<endl;
}
