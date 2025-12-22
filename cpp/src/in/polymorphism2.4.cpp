#include<iostream>
using namespace std;
class Person{  
  string name;  
  int year;public:

  Person(string name1="Ali", 
    int year1=12):name(name1), year(year1){}

  virtual string getJob() = 0;
  
  void print(){
    cout << "name :" << name << endl;
    cout << "year :" << year << endl;
    cout << "job  :" << getJob() << endl;
  }
};
class Student: public Person{  
  string stdnm;
public:
  virtual string getJob() {return "student";}
  Student(string name1="Ali", int year1=12, 
    string d="234234"):Person(name1,year1)
	{stdnm=d;}
};
class Employee: public Person{
public:
  virtual string getJob() {return "employee";}

  Employee(string name1="Ali", 
    int year1=12):Person(name1,year1){}
};
int main(){  //Person p1;
  Student st1;  
  cout << st1.getJob() << endl;
  Person *ps;  //cout<<ps->getJob()<<endl;
  ps = &st1;
  cout << ps->getJob() << endl;
  Employee em1("Hadi", 20), *pem1 = &em1;
  em1.print();
}
