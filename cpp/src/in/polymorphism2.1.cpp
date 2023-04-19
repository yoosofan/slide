#include<iostream>
using namespace std;
class Person{
  string name;
  int year;
protected:
  string job;
public:
  Person(string name1="Ali",int year1=12,
	string job1="student"):name(name1),
	year(year1), job(job1){}
  virtual string getJob(void)
  {return job;}
  void print(void){
    cout<<"name :"<<name<<endl;
    cout<<"year :"<<year<<endl;
    cout<<"job  :"<<job <<endl;
  }
};
class Student: public Person{
  string stdnm;
public:
  virtual string getJob(void)
  {return job;}
  Student(string name1="Ali", int year1=12,
	  string job1 = "student", string d = "234234"):
	Person(name1, year1, job1)
	{stdnm=d;}
};
int main(){
  Person p("Reza", 11, "student");
  p.print();
  Student st1;
  cout << st1.getJob() << endl;
  Person* ps = &p;
  cout << ps->getJob() << endl;
  ps = &st1;
  cout << ps->getJob() << endl;
  return 0;
}
