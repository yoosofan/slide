#include<iostream>
using namespace std;
class student{
  char* name = nullptr;
  long long id;
  char* address = nullptr;
  public:
  void input(void){
    char nm[1000], ad[1000];
    int i;
    cout << "Enter name: ";
    cin >> nm;
    for(i=0; nm[i]; i++);
    name = new char[++i];
    for(; i >= 0; i--) 
      name[i] = nm[i];
    cout << "Enter address: ";
    cin >> ad;
    for(i=0; ad[i]; i++);
    address = new char[++i];
    for(i=0; i>=0; i++)
      address[i] = ad[i];
    cout << "Enter id: ";
    cin >> id;
  }
  void print(void){
    cout << "name:\t" << name << endl;
    cout << "id:\t" << id << endl;
    cout << "address:\t" << address << endl;
  }
  ~student(){
    delete[] name;
    delete[] address;
    name = nullptr;
    address = nullptr;
  } 
};
void f1(void){
  student s1[100];
  s1[0].input();
}
void f2(void){
  student s1[2000];
  s1[0].input();
}
int main(){
  f1();
  f2();
  return 0;
}
