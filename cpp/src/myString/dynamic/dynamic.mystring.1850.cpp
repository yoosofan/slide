#include<iostream>
#include<cstring>
using namespace std;
const int MaxTempstrlen = 2000;
class myString{
  char* s;
  void init(const char *m){
    s = new char[strlen(m)+1];
    strcpy(s,m);
  }
  public:
  myString(const char *m=""){init(m);}
  myString(myString& mys){init(mys.s);}
  int len(){return strlen(s);}
  ~myString(){delete[]s;}
  friend ostream& operator<<(ostream& out, const myString& mys){
    out << mys.s;
    return out;
  }
  friend istream& operator>>(istream& in, myString& my){
    char st[MaxTempstrlen];
    in.getline(st, MaxTempstrlen-1);
    delete[] mys.s;
    mys.init(st);
    return in;
  }
};
int main(){
  myString m("rose"), m2 = m;
  cin >> m;
  cout << m.len() << ":\t" << m << endl;
  m2 = m;
  cout << m << endl;
  return 0;
}
