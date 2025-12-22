//http://en.wikipedia.org/wiki/Bitwise_operations_in_C
#include<iostream>
using namespace std;
void showbits(unsigned int x){int i;
  for(i=(sizeof(int)*8)-1; i>=0; i--)
      (x&(1<<i))? cout<<'1': cout<<'0';
  cout<<endl;
}
int main(){
  int j = 5225, m, n;
  showbits(j);
  for ( m = 0; m <= 5; m++ ) {
    n = j >> m;
    cout<<j<<" right shift "<< m <<endl;
    showbits(n);
  }
}
