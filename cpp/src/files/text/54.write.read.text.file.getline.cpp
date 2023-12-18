#include <fstream>
#include<iostream>
using namespace std;
int main(){
  string st =  "ali"; 
  ofstream f1("2.out.txt"); 
  fstream f2("3.out.txt", ios::out); //ofstream
  if(!f1)
    cout << "Can not open f1" << endl;  
  if(!f2) 
    cout << "Can not open f2" << endl;
  f1 << st << endl << "Hamed" << endl;  
  f2 << "Sadegh" << "  Salehi " << endl;
  f2 << "ali" << "  Seifi " << endl;  
  f2 << "Sahar" << "  Safi " << endl; 
  f2.close();  
  f1.close();
  fstream f3("2.out.txt", ios::in);  
  if(!f3){
    cout << "Can not open f3" << endl; 
    return 0;
  }
  f3 >> st; 
  cout << st << endl;  
  f3.close();
  ifstream f4("3.out.txt");  //f4>>st; cout<<st<<endl;
  char cst[50];  //while(f4.getline(cst,50).gcount()>0)
  while(f4.getline(cst, 50))  
    cout<< cst << endl;
  f4.close();
}
