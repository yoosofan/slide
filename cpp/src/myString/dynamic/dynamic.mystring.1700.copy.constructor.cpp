#include<iostream>
#include<cstring>
using namespace std;
class myString{
  char* s;
  void init(const char *m){
    s = new char[strlen(m)+1];
    strcpy(s,m);
  }
  public:
  myString(const char *m=""){init(m);}
  myString(myString& mys){init(mys.s);}
  int len(void){return strlen(s);}
  ~myString(){delete[]s;}
  friend ostream& operator<<(ostream& out, const myString mys){
    out << mys.s;
    return out;
  }
  friend istream& operator>>(istream&in,myString& mys){
    char st[2000];
    in.getline(st, 1999);
    delete[] mys.s;
    mys.init(st);
    return in;
  }
};
int main(){
  myString m("rose");
  cout << "Enter a string " << endl;
  cin >> m;
  cout << m.len() << ":\t" << m << endl;
  return 0;
}
