#include <iostream>
using namespace std;
int main(){
  int **ma;
  ma = new int *[10];
  for(auto i = 0; i < 10; i++)
    ma[i] = new int[20];
  for(auto i = 0; i < 10; i++){
    delete[] ma[i];
    ma[i] = nullptr;
  }
  delete[] ma;
  ma = nullptr;
  cout << " after **ma" << endl;
  cout << "Before ***pma" << endl;
  int ***pma;
  pma = new int**[10];
  for(auto i = 0; i < 10; i++){
    pma[i] = new int*[20];
    for(auto j = 0; j < 20; j++){
      *(*(pma+i)+j) = new int[30];
      for(auto k = 0; k < 30; k++)
        *(*(*(pma+i)+j)+k ) = k+i+j;
    }
  }
  for(auto i = 0; i < 10; i++){
    for(auto j = 0; j < 20; j++){
      for(auto k = 0; k < 30; k++)
        cout << *(*(*(pma+i)+j)+k ) << endl;
    }
  }
  for(auto i = 0; i < 10; i++){
    for(auto j = 0; j < 20; j++){
      delete[] *(*(pma+i)+j);
      *(*(pma+i)+j) = nullptr;
    }
    delete[] *(pma+i);
    *(pma+i) = nullptr;
  }
  delete[] pma;
  pma = nullptr;
 cout << "At the end of program" << endl;
}