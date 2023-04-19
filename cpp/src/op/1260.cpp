#include <iostream>
using namespace std;
class myArray{ 
	double* a = nullptr;
	int n = 0;
	public:
	myArray(const double* ma=nullptr, int n=0){ /// myArray(const *ma, ...
		if(! (n==0 || ma==nullptr)){
			a=new double[this->n=n];
			for(int i=0;i<n;i++)
				a[i]=ma[i];
		}
	}
	~myArray(){
    delete[]a;
    cout<<"in destructor"<<endl;
  }
	double& operator[](int index){return a[index];}

	myArray& operator=(const myArray& b){
		this->a = new double[this->n=b.n];
		for(int i=0; i<n; i++)
      a[i] = b.a[i];
    return *this;
	}
};
/*void f1(myArray b){ /// int f1 ... 
	myArray c;
	c=b;
	c[1]=8;
}
*/
int main(){
	double x[100000]={10,12,34,54};
	myArray d(x, sizeof(x)/sizeof(double));
	cout << d[1] <<endl;
	cout.flush();
	myArray g,h;
	h = g = d;
	g[1]=8;
	//f1(d);
	cout<<d[3]<<endl;
	cout<<d[1]<<endl;
	d[3]=4;
	cout<<d[3]<<endl;
}
