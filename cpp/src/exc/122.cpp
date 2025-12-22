#include <iostream>
using namespace std;
struct retFlagInt{
  bool flag = true;
  int ret = 1;
};
bool f1(int i){
  if(i <= 0)
    return false;
  else
    cout << i <<endl;
  return true;
}
bool f2(int mm){
  if (mm > 20)
    return false;
  else
    cout << mm << endl;
  return true;
}
bool f4(int mm){
  bool retVal = true;
  if(mm<10) 
    retVal = false ;
  else 
    cout << "In f4 mm " << mm << endl;
  return retVal;
}
retFlagInt f3(){
  retFlagInt x;
  x.ret = 4;
  if(!f1(3)){ 
    cout << "In f3 " << endl;
    x.flag = false;
  }else if(!f4(2)){ 
    cout << "In f3 " << endl;
    x.flag = false;
  }
  return x;
}
int main(){
  if(!f1(1)) 
  {cout << "In main"<< endl;return 1;}
  if(!f2(12)) 
  {cout << "In main" << endl;return 1;}
  retFlagInt z = f3();
  if(z.flag == false)
  {cout << "In main" << endl;return 1;}
  if(!f2(13)) 
  {cout << "In main" << endl;return 1;}
  cout<< "End" << endl;
}
