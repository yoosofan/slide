#include <iostream>
#include <cmath>
using namespace std;
void f1(int i){
	if( i <= 0)   throw 1;
	cout << i<<endl;
}
void f2(int mm){
	if (mm > 20)    throw 2;
	cout<<mm<<endl;
}
void f4(int mm){
	if(mm<10) throw "Error ";
	cout << "In f4 mm "<< mm<<endl;
}
void f3(void){
	try {f1(-3); f4(2);}
  catch(int mm){cout <<"In f3 "<<mm<<endl;}
}
struct RootCls{ double root1 , root2;};
RootCls solve(double a, double b, double c){
	RootCls retVal ; double delta;
	if(a == 0 && b == 0) throw 6;
	if(a==0){ retVal.root1 = retVal.root2 = -c / b ; }
	else{
		delta = (b * b - 4 *a * c) ;
		if(delta < 0 ) throw 7;
		delta = sqrt(delta);
		retVal.root1 = (-b + delta)/(2*a);
		retVal.root2 = (-b - delta)/(2*a);
	}
	return retVal;
}

int main(){
	try{f1(1); f2(12); f3(); f4(5);}
  catch(int m){
		cout <<"catch expception "<<m<<endl;
	}catch (char const *sm){
		cout<<"catch f4 error in main "<< sm<<endl;
	}
	try{ f2(13);
		RootCls rc1 =solve(4 , 55, 2);
		cout<< rc1.root1<<" root2  "<<rc1.root2<< endl;
	}catch(int nn){
		cout <<"Second catch in main "<<nn << endl;
	}
	try{ throw 5;
		cout <<"Execution will not reach to this statement"<<endl;
	}catch(int  ll){ cout <<"Third catch in main "<<endl;}
	cout<< "End "<<endl;
}
