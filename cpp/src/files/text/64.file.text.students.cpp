#include<fstream>
#include<iostream>
using namespace std;
struct student{
  int std_no;
  char name[100]; 
  double avg;
  char course[100];   
  int m, n;
  void readFromFile(ifstream& f1){
    f1 >> std_no;   
    f1 >> name;
    f1 >> avg;      
    f1 >> course;  
    f1 >> m;       
    f1 >> n;  
  }
  void print(){
    cout << std_no <<'\t';
    cout << name << '\t';
    cout << avg << '\t';
    cout << course << '\t';
    cout << m << '\t';
    cout << n << endl;
  }
};
int main(){
  int i; 
  double x; 
  char st[100];
  student m1;
  ifstream f1("input.students.txt"); // ofstream , ifstream, fstream
  m1.readFromFile(f1);
  while(!f1.eof()){ 
    m1.print();
    m1.readFromFile(f1);
  }
  //while(f1>>i) cout<<i<<'\t';cout<<endl;
  //f1.close();  f1.open("1.inp.txt");
  //f1.seekg(0,ios::beg); 
  //while(!f1.eof()){ cout<<i<<'\t';f1>>i;} cout<<endl;
  f1.close();
}
/*
  void read2(ifstream&f1){
  constexpr auto max_string=1000;
  constexpr auto max_stringMinus1=1000-1;
  char st[max_string];
  f1.getline(st,max_stringMinus1);
  sscanf(st,"%d%s%lf%s%d%d",&std_no,name, &avg, course, &m, &n);
  }
*/
