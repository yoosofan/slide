#include<iostream>
using namespace std;

struct date{ int year, month, day; };
struct student{
  char name[50]; 
  char stdNumber[15]; 
  date birthDate;
};
date input_date();
student input_student();
void print_date(date d1);
void print_student(student st);
int main(){
  student st1[50];
  int n, i=0;
  cout << "Enter number of students(0<n<50) ";
  cin >> n;
  if(n>0 && n<50)
    do{
      st1[i] = input_student();
      print_student(st1[i]);
      i++;
    }while(i<n);
  else  { cout << "0<n<50 "; cout << n;}
}
date input_date(){
  date d1;
  cout << "Enter year:{1350..1390} "; 
  cin >> d1.year;
  cout << "Enter month{1..12}:"; 
  cin >> d1.month;
  cout << "Enter day{1..31}:"; 
  cin >> d1.day;
  return d1;
}
void print_date(date d1){
  cout << "year = ";  cout << d1.year;
  cout << "\tmonth = "; cout << d1.month;
  cout << "\tday = "; 
  cout << d1.day; cout << "\n";
}
student input_student(){
  student st;
  cout << "Enter name :";
  cin >> st.name;
  cout << "Enter studnet number :";
  cin >> st.stdNumber;
  cout << "Enter birth date :"; 
  st.birthDate = input_date();
  return st;
}
void print_student(student st){
  cout << "name = "; cout << st.name;
  cout << "\n"; cout << "number = ";
  cout << st.stdNumber; cout << "\n";
  print_date(st.birthDate);
}
