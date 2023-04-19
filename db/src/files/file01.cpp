#include <fstream> // 
#include<iostream>
using namespace std;
struct student{
  char name[50]; //string name;
  char number[15];
  double mark;
  void input(void){
    cout << "Enter name: ";  cin >> name;
    cout << "Enter number:"; cin >> number;
    cout << "Enter mark: " ; cin >> mark;
  }
  void print(void){
    cout << "name: " << name << endl;
    cout << "number: " << number << endl;
    cout << "mark: " << endl;
  }
};
void GetStudentsWrite(void){
  student st[100];
  int i, n;
  cout << "Enter number of Student "; cin >> n;
  for(i = 0; i < n ; i++)
    st[i].input();
  ofstream f1("students.b");
  f1.write(reinterpret_cast<char*>(&n), sizeof(int));
  for(i = 0 ; i < n ; i++){
    f1.write(reinterpret_cast<char*>(st[i].name), 50 * sizeof(char));
    f1.write(reinterpret_cast<char*>(st[i].number), 15 * sizeof(char));
    f1.write(reinterpret_cast<char*>(& st[i].mark), sizeof(double));
  }
  f1.close();
}
void readFromFilePrint(void){
  student st[100];
  int i, n;
  ifstream f1("students.b");
  f1.read(reinterpret_cast<char *>(&n), sizeof(int));
  for(i = 0 ; i < n ; i++){
    f1.read(reinterpret_cast<char *>(st[i].name), 50 * sizeof(char));
    f1.read(reinterpret_cast<char *>(st[i].number), 15 * sizeof(char));
    f1.read(reinterpret_cast<char *>(&st[i].mark), sizeof(double));
  }
  f1.close();
  for(i = 0; i < n; i++)
    st[i].print();
}  
int main(){
  GetStudentsWrite();
  readFromFilePrint();
}
