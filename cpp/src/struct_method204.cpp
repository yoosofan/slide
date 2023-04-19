#include<iostream>
using namespace std;
struct date{ int year, month, day; };
date input(void){
  date d1;
  cout << "Year: "; 
  cin >> d1.year;
  cout << "Month: "; 
  cin >> d1.month;
  cout << "Day: "; 
  cin >> d1.day;
  return d1;
}
void print(date d1){
  cout << d1.year << '/' << d1.month 
    << '/' << d1.day << endl;
}
int main(){
  date d1;
  d1 = input();
  print(d1);
  date d2;
  d2 = input();
  print(d2);
}
