#include<iostream>
using namespace std;
struct date{ int year, month, day; };
date input_date(void);
void print_date(date d1);
void print(int k){cout << k << endl;}
int input(void)
{int n; cout <<"Enter n "; cin >> n; return n;}
int main(){
  date d1;
  d1 = input_date();
  print_date(d1);
}
date input_date(void){
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
  cout << "year = "  << d1.year;
  cout << "\tmonth = " << d1.month;
  cout << "\tday = " << d1.day << endl;
}
