#include <iostream>
using namespace std;
class myArray{
	double* a = nullptr;
	int n = 0;
	public:
	myArray(const double* ma=nullptr, int n=0){ /// myArray(const *ma, ...
		if(n==0 || ma==nullptr){n=0; a=nullptr;}
		else{
			a=new double[this->n=n];
			for(int i=0;i<n;i++)a[i]=ma[i];
		}
	}
	~myArray(){delete[]a;a=nullptr;n=0;cout<<"in destructor"<<endl;}
	double& operator[](int index){return a[index];}
	void operator=(const myArray& b){
		this->a = new double[this->n=b.n];
		for(int i=0;i<n;i++)a[i]=b.a[i];
	}
};
/*void f1(myArray b){ /// int f1 ... 	myArray c;	c=b;	c[1]=8;}*/
int main(){//// double x= ...
	double x[100000]={10,12,34,54};
	myArray d(x,sizeof(x)/sizeof(double));
	cout<<d[1]<<endl;
	cout.flush();
	myArray g;
	g=d;
	g[1]=8;
	//f1(d);
	cout<<d[3]<<endl;
	cout<<d[1]<<endl;
	d[3]=4;
	cout<<d[3]<<endl;
}
