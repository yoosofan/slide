#include <iostream>
#include <cmath>
using namespace std;
#include "side.h"
#include "mycomplex.h"
#include "triangle.h"
#include "other_functions.h"
void f2(void){
	side a(3);
	side b(4),c(5);
	side d;
	d = a + b;
	d.show();
	cout<<endl;
	d = a + -3;
	d.show();
	int k=3;
	side e(k);
	d = a + e;
	d.show();
	int i=1;
	double x =1;
	x = x + i;
	double y;
	y = i;
	y = (double)i;
	y = double(i);
	y = static_cast<double>(i);

	//triangle t(a,b,c);
	//t.show();
}
int f1(void){
  complexCls a(2,3),b(2,1),c(a);
  c=a.add(b);
  c.Show();
  c=add(a,b);
  c.Show();
}
