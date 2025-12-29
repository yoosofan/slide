#include <fstream>
#include <iostream> //#include <cstdlib>
using namespace std;
int main(){
  string st= "ali";
  ofstream f1("2.out.txt");
  fstream f2("3.out.txt", ios::out); //ofstream
  if(!f1){
    cout << "Can not open f1" << endl;
    throw 1;
  }
  if(!f2){
    cout << "Can not open f2" << endl;
    f1.close();
    throw 2;
  }
  f1 << st << ' ' << "Hamed" << endl;
  f2 << "Sadegh" << "  Salehi " << endl;
  f2.close();
  f1.close();
  fstream f3("2.out.txt", ios::in); //ifstream
  if(!f3){
    cout << "Can not open f3" << endl;
    throw 0;
  }
  f3 >> st;
  cout << st << endl;
  f3.close();
  ifstream f4("3.out.txt");
  char cst[50];
  f4.getline(cst, 50);
  cout << cst << endl;
  f4.close();  //
}
