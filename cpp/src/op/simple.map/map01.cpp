#include<iostream>
using namespace std;
class myArray{
  double a[300];
  int n;
  string s[300];
  public:
  myArray(){n=0;}
  //double operator[](string m1){
  double& operator[](string m1){
    int i;
    for(i=0; i<n; i++)
      if(s[i] == m1 )
        return a[i];
    s[n]=m1;
    //n++;
    //return a[n-1];
    return a[n++];
  }
};
int main(){
  myArray m1; double x=3; double y=3.0; double z(3.0);
  m1["ali"]=23;
  m1["reza"]=45;
  m1["kamran"]=12;
  m1["hamid"]=12.5;
  cout<<m1["ali"]<<endl;
  cout<<m1["reza"]<<endl;
  return 0;
}
