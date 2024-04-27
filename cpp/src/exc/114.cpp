#include <iostream>
using namespace std;
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
bool f3(void){
    if(!f1(3)){ 
      cout << "In f3 " << endl;
      return false;
    }
    if(!f4(2)){ 
      cout << "In f3 " << endl;
      return false;
    }
    return true;
}
int main(){
  if(!f1(1)) 
  {cout << "In main"<< endl;return 1;}
  if(!f2(12)) 
  {cout << "In main" << endl;return 1;}
  if(!f3()) 
  {cout << "In main" << endl;return 1;}
  if(!f2(13)) 
  {cout << "In main" << endl;return 1;}
  cout<< "End" << endl;
}
