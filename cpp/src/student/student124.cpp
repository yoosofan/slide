#include<iostream>
using namespace std;
struct student{
  char name[20];
  int  id;
  char address[50];
  void input(void){
    cout << "Enter name:"; cin >> name;
    cout << "id:"; cin >> id;
    cout << "address:"; cin >> address;
  }
  void print(void){
    cout << "name:\t\t" << name << endl;
    cout << "id:\t\t" << id << endl;
    cout << "address:\t\t" << address << endl;
  }
};
int main(){
  student std;
  std.input();
  std.print();
  student st2;
  st2.input();
  st2.print();
}
