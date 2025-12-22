#include<iostream>
#include<cstring>
using namespace std;
class myString{
  char* s;
  public:
  myString(const char* m = ""){
    s = new char[strlen(m)+1];
    strcpy(s,m);
  }
  int len(){return strlen(s);}
  ~myString(){delete[]s;}
  friend ostream& operator<<(ostream&o1, myString m){
    o1 << m.s;
    return o1;
  }
};
int main(){
  myString m("rose");
  cout << m.len() << ":\t" << m << endl;
}
