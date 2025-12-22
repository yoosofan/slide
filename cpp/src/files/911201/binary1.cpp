#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class MyClass{
  fstream f1;
  struct myDate{int year,month,day;
    void input(){
      cout<<"Enter year ";cin>>year;
      cout<<"Enter month ";cin>>month;
      cout<<"Enter day ";cin>>this->day;
    }
    void print(){
      cout<<"year "<<year<<endl;
      cout<<"month "<<month<<endl;
      cout<<"day  "<<day<<endl;
    }   
  };
  struct person{
    char fname[20],lname[20],ssn[15];
    myDate bd;
  };
public:
  MyClass(const char *fname="input1.b"){
    f1.open(fname,
      ios::binary|ios::in|ios::out);
    if(!f1.is_open()){
      ofstream f2;
      f2.open(fname,ios::binary);
      if(!f2){cout<<"1. The file did not opened"<<endl;  exit(0);   }
      f2.close();
      f1.open(fname,
	ios::binary|ios::in|ios::out);
      if(!f1.is_open()){cout<<"2. The file did not opened"<<endl;  exit(0);   }
    }
  }
  ~MyClass(){f1.close();}
  void write(person p)
  {
    f1.write((char*)&p,sizeof(p));
    //f1.flush();    
  }
  person read(){person p;
    f1.read((char*)&p,sizeof(p));
    return p;
  }
  person input(){person p;
    cout<<"Enter first name ";
    cin>>p.fname;
    cout<<"Enter last name ";
    cin>>p.lname;
    cout<<"Enter social security number ";
    cin>>p.ssn;
    cout<<"Enter birth date"<<endl;
    p.bd.input();
    return p;
  }
  void print(person p){
    cout<<"first name : ";cout<<p.fname;
    cout<<"last name : ";cout<<p.lname;
    cout<<"Social security number :";
    cout<<p.ssn;
    cout<<"birth date :"<<endl;
    p.bd.print();
  }
  void run(){ person p;int i;
    for(i=0;i<1;i++)
    {p=input();  write(p); }
    f1.seekg(0,ios::beg);
    for(i=0;i<1;i++)
    { p=read();  print(p);}
  }
};
int main(){
  MyClass m1;
  m1.run();
  return 0;
}  
