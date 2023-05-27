#include<iostream>
#include<cstring>
using namespace std;
  class myClass{
  private:
    char ssid[14];
    char fname[14];
    char lname[14];
  public:
    void init(char*id,char*f,char*l){
      strcpy(ssid,id);
      strcpy(fname,f);
      strcpy(lname,l);
    }
    void print(void){
      cout<<"ssid "<<ssid;
      cout<<"  fname "<<fname;
      cout<<"  lname "<<lname;
      cout<<endl;
    }
  };

int main(){
  myClass c1;c1.init("23","ali","Hamidi");
  c1.print();
  return 0;
}
