#include<iostream>
using namespace std;
class Person{
  int year;
//protected:  string job;
public:
  string name;
  Person(string name1="",
	 int year1=12):name(name1),
	 year(year1){}
  virtual string getJob(void)
  {return "";}
  void print(void){
    cout<<"name :"<<name<<endl;
    cout<<"year :"<<year<<endl;
    cout<<"job  :"<<getJob()<<endl;
  }
  int nameLen(void){return name.length();}
};
class Student: public Person{
  string stdnm;
public:
  virtual string getJob(void)
  {return "student";}
  Student(string name1="Ali", int year1=12,
	  string d="234234"):
	Person(name1, year1)
	{stdnm=d;}
};
class Employee: public Person{
public:
  virtual string getJob(void)
  {return "employee";}
  Employee(string name1="Ali",int year1=12):
    Person(name1,year1){}
};
int main(){
  Person p("Reza", 11);
  p.print();
  cout << p.nameLen() << endl;
  Student st1;
  cout << st1.getJob() << endl;
  Person* ps = &p;
  cout << ps->getJob() << endl;
  ps = &st1;
  cout << ps->getJob() << endl;
  Employee em1("Hadi", 20), * pem1 = &em1;
  em1.print();
  Person p1("abcdefg");
  cout << p1.name.empty ()<<endl;
  cout << p1.name[2] << endl;
}
