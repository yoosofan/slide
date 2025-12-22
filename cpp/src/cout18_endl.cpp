#include<iostream>
using namespace std;
struct date{ int year, month, day; };
date input_date(){
  date d1;
  cout << "Enter year:{1350..1390} " ;
  cin >> d1.year;
  cout << "Enter month{1..12}:"; 
  cin >> d1.month;
  cout << "Enter day{1..31}:"; 
  cin >> d1.day;
  return d1;
}
void print_date(date d1){
  cout << "year = " << d1.year
       << "\tmonth = " << d1.month
       << "\tday = " << d1.day << endl;
}
int main(){
  date birthDate = input_date();
  print_date(birthDate);
  return 0;
}
