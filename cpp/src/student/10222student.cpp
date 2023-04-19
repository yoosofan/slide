#include<iostream>
using namespace std;
int myStrcmp(char* st1, char* st2){
  for(; *st1 && *st2; st1++, st2++)
    if(*st1 < *st2) return -1;
    else if(*st1 > *st2) return 1;
  if(*st1 == '\0')
    if(*st2 == '\0') return 0;
    else return -1;
  return 1;
}
class universityClass;
class student{
  char name[20]="";
  long long  id;
  char address[50]="";
  public:
  void input(void){
    cout<<"Enter name:"; cin>>name;
    cout<<"id:"; cin>>id;
    cout<<"address:"; cin>>address;
  }
  void print(void){
    cout << "name:\t" << name << endl;
    cout << "id:\t" << id << endl;
    cout << "address:\t" << address << endl;
  }
  friend class universityClass;
};
class universityClass{
  student st[50];
  double marks[50]={0};
  int n=0;
  char instructor[20]="";
  public:
  void input(void){
    cout << "Enter number of students:";
    cin >> n;
    for(int i=0; i<n; i++)
      st[i].input();
    cout << "Enter name of instructor:";
    cin >> instructor;
  }
  void print(void){
    cout << "number of students:" << n;
    cout << endl << "instructor: " 
      << instructor << endl;
    for(int i=0; i < n; i++){
      st[i].print();
      cout << "mark: " << marks[i] << endl;
    }
  }
  void changeMark(char stName[20], 
    double mark){
    int i;
    for(i=0; i < n; i++)
     if(myStrcmp(stName, st[i].name) == 0)
       marks[i] = mark;
  }
};
int main(){ universityClass stList; 
  stList.input();
  stList.print();
}