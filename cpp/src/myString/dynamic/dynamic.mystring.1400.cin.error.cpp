// Error :
#include<iostream>
#include<cstring>
using namespace std;
class myString{
  char* s;
  void init(const char* m){
    s = new char[strlen(m)+1];
    strcpy(s,m);
  }
  public:
  myString(const char* m=""){init(m);}
  int len(){return strlen(s);}
  ~myString(){delete[]s;}
  friend ostream& operator<<(ostream&out, myString mys){// myString &
    out << mys.s;
    return out;
  }
  friend istream& operator>>(istream&in, myString& mys){
    char st[2000];
    in.getline(st, 1999);
    delete[] mys.s;
    mys.init(st);
    return in;
  }
};
int main(){
  myString m("rose");
  cin >> m;
  cout << m.len() << ":\t" << m << endl;
  return 0;
}
