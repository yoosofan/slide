/*yoosofan@mail.com
*/
#include<iostream>
#include<cstring>
using namespace std;
class student{
  char* name = nullptr;
  long long id;
  char* address = nullptr;
  public:
  student(const char* mn1=nullptr, 
    long long d=0, char* ad=nullptr)
  {
    name=new char[strlen(mn1)];
    strcpy(name, mn1);
    address=new char[strlen(ad)];
    strcpy(address,ad);
  }
  void input(void){
    char nm[1000], ad[1000];
    cout << "Enter name: ";
    cin >> nm;
    name = new char[strlen(nm)];
    strcpy(name, nm);
    cout << "Enter address: ";
    cin >> ad;
    address = new char[strlen(ad)];
    strcpy(address, ad);
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
