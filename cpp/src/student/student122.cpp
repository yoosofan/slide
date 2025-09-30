#include<iostream>
using namespace std;
struct student{
  char name[20];
  int  id;
  char address[50];
};
student input_student(){
  student s1;
  cout << "Enter name:";
  cin >> s1.name;
  cout << "id:";
  cin >> s1.id;
  cout << "address:";
  cin >> s1.address;
  return s1;
}
void print(student st1){
  cout << "name:\t\t"
    << st1.name << endl;
  cout << "id:\t\t"
    << st1.id << endl;
  cout << "address:\t\t"
    << st1.address << endl;
}
int main(){
  student st1;
  st1 = input_student();
  print(st1);
  student st2;
  st2 = input_student();
  print(st2);
}
