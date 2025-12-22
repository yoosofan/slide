// Error : no match for ‘operator=’ (operand types are ‘myString’ and ‘myString’)
#include<iostream>
#include<cstring>
using namespace std;
const int MaxTempstrlen=200;
class myString{
  char *s;
  void init(const char *m){s=new char[strlen(m)+1];strcpy(s,m);}
  public:
  myString(const char* m=""){init(m);}
  myString(myString& mys){init(mys.s);}
  int len(){return strlen(s);}
  ~myString(){delete[]s;}
  myString& operator=(myString& mys){
    delete[] s; 
    init(mys.s); 
    return *this;
  }
  char& operator[](int index){
    if(index<len() && index >= 0) 
      return s[index];
    throw "index out of range";
  }
  myString operator+(const myString& mys){
    char* st = new char[len() + mys.len() + 1];
    strcpy(st, s);
    strcpy(st+len(), mys.s);
    myString mys1(st);
    return mys1;
  }
  friend ostream& operator<<(ostream& out, myString& mys){
    out << mys.s;
    return out;
  }
  friend istream& operator>>(istream&in,myString& mys){
    char st[MaxTempstrlen];
    in.getline(st, MaxTempstrlen-1);
    delete[] mys.s;
    mys.init(st);
    return in;
  }
};
int main(){
  myString m1("rose"), m2, m3;
  m2 = m1;
  cin >> m1;
  cout << m1.len() << ":\t" << m1 << endl;
  cout << m2.len() << ":\t" << m2 << endl;
  m3 = m1 + m2; 
  cout << m3 << endl;
  cout << m2[2] << endl;
  m2[2] = 'z';
  cout << m2 << endl;
  return 0;
}
