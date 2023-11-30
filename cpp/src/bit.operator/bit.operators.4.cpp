/*
a      	b    a&b    a|b     a^b
0      	0     0       0       0
0      	1 	  0      	1      	1
1      	0 	  0      	1      	1
1      	1    	1      	1      	0
*/
#include<iostream>
using namespace std;
int main(){unsigned int i=020;
	cout<<i<<"\t"<<hex<<i<<endl;
	cout<<i<<"\t"<<dec<<i<<endl;
	cout<<i<<"\t"<<oct<<i<<endl;
	unsigned int j=011;
	cout<<(i^j);
	return 0;
}
