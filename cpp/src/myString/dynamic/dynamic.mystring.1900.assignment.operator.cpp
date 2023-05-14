#include<iostream>
#include<cstring>
using namespace std;
const int MaxTempstrlen = 200;
class myString{
  char* s;
  void init(const char* m){
    s = new char[strlen(m)+1];
    strcpy(s,m);
  }
  public:
  myString(const char* m=""){init(m);}
  myString(myString&mys){init(mys.s);}
  int len(void){return strlen(s);}
  ~myString(){delete[]s;}
  myString& operator=(const myString& mys){
    delete[] s; 
    init(mys.s); 
    return *this;
  }
  friend ostream& operator<<(ostream&out, const myString& mys){
    out << mys.s;
    return out;
  }
  friend istream& operator>>(istream&in, myString& mys){
    char st[MaxTempstrlen];
    in.getline(st, MaxTempstrlen-1);
    delete[] mys.s;
    mys.init(st);
    return in;
  }
    
};
int main(){
  myString m("rose"), m2;
  m2 = m;
  cin >> m;
  cout << m.len() << ":\t" << m << endl;
  cout<< m2.len() <<":\t" << m2 << endl;
  return 0;
}
