#include<iostream>
using namespace std;
const int MaxTempstrlen=200;
class myString{
  char* s;
  void init(const char *m){s=new char[strlen(m)+1];strcpy((s,m);}
  public:
  myString(const char *m=""){init(m);}
  myString(myString&mys){init(mys.s);}
  int len(){return strlen(s);}
  ~myString(){delete[]s;}
  myString& operator=(myString&mys){delete[] s; init(mys.s); return *this;}
  char& operator[](int index){
    if(index<len() && index >= 0) return s[index];
    throw "index out of range";
  }
  friend ostream& operator<<(ostream&out,myString &);
  friend istream& operator>>(istream&in,myString& );
};
ostream& operator<<(ostream&out,myString &mys){out<<mys.s;return out;}
istream& operator>>(istream&in,myString&mys)
{char st[MaxTempstrlen];in.getline(st,MaxTempstrlen-1);delete[] mys.s;mys.init(st);return in;}
int main(){
  myString m("rose"),m2;m2=m;
  cin>>m;cout<<m.len()<<":\t"<<m<<endl;
  cout<<m2.len()<<":\t"<<m2<<endl;
  cout<<m2[2]<<endl;
  m2[2]='z';
  cout<<m2<<endl;
  return 0;
}
