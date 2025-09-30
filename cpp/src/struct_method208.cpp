#include<iostream>
using namespace std;
struct date{ 
  int year, month, day; 
  void input(){
    cout << "Year: "; 
    cin >> year;
    cout << "Month: "; 
    cin >> month;
    cout << "Day: "; 
    cin >> day;
  }
  void print(){
    cout << year << '/' << month 
      << '/' << day << endl;
  }
};
int main(){
  date d1;
  d1.input();
  d1.print();
  date d2;
  d2.input();
  d2.print();
}