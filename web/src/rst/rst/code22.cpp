#include<iostream>
using namespace std;
struct date{ 
  int year, month, day; 
  void input(void){
    cout << "Enter year:{1350..1390} "; 
    cin >> year;
    cout << "Enter month{1..12}:"; 
    cin >> month;
    cout << "Enter day{1..31}:"; 
    cin >> day;
  }
  void print(void){
    cout << "year = "  << year;
    cout << "\tmonth = " << month;
    cout << "\tday = " << day << endl;
  }
};
int main(){
  date d1;
  d1.input();
  d1.print();
}
