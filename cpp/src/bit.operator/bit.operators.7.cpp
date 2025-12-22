#include<iostream>
using namespace std;
void showbits( unsigned int x);
void showbitsChar( unsigned char x);
int main(){unsigned int i=020;
	cout<<i<<"\t"<<hex<<i<<endl;
	cout<<i<<"\t"<<dec<<i<<endl;
	cout<<i<<"\t"<<oct<<i<<endl;
	cout<<(~i)<<"\t"<<dec<<(~i)<<endl;
  showbits(i); showbits(~i);
	unsigned int j=011;
	cout<<(i^j)<<endl;
  unsigned char c=0x20;
  showbitsChar(c);showbitsChar(~c);
}
void showbits( unsigned int x){int i;
  for(i=(sizeof(int)*8)-1; i>=0; i--)
      (x&(1<<i))? cout<<'1': cout<<'0';
  cout<<endl;
}
void showbitsChar( unsigned char x){int i;
  for(i=(sizeof(char)*8)-1; i>=0; i--)
      (x&(1<<i))? cout<<'1': cout<<'0';
  cout<<endl;
}
