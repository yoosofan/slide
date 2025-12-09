#include <iostream>
#include <cmath>
using namespace std;
class complexCls{ double r,i;
 public:
  complexCls(int m=0,int n=0)
  {r=m;i=n;}
  void Show(void)
  {cout<<r<<"+ i "<<i<<endl;}
  double Magnitude(void)
  {return sqrt(r*r+i*i);}
  void input(void){
    cout<<"Enter real:"; cin>>r;
    cout<<"Enter imaginary:"; cin>>i;
  }
  friend complexCls operator+(const complexCls& a, const complexCls& b);
    complexCls c=a;
    c.r += b.r;
    c.i += b.i;
    return c;
  }
};
class side{
  unsigned d;
  public:
  side()=default;
  //~side()=default;
  //~side()=delete;
  side(int a){
    if(a<=0){cout<<"Side of a shape connot be negative or zero"<<endl;exit(0);}
    d=a;
  }
  side(const side&a){static int counter=0;counter+=1; this->d = a.d;cout<<counter<<"\tcopy constructor:"<<d<<endl;}
  void input(void){
    cout<<"Enter length of side:"; cin>>d;
    while(d<=0){
      cout<<"Side must be >0"<<endl;
      cout<<"Enter length of side:"; cin>>d;
    }
  }
  side operator+(side& a){
    side b;
    //side b(*this); // b(a)
    b.d = this->d + a.d;
    this->show();cout<<" + "<<endl;
    return b;
  }
  bool operator>(side& a){cout<<d<<" > "<<a.d<<endl; return d>a.d;}
  void print(){cout<<d;}
};
class Shape{protected://abstract
  string name, color;
  public:
  Shape(string name="shape",
    string color="white"):
      name(name),color(color)
  {}
  virtual double Area() = 0;//abstract
  virtual void print(){
    cout << "name: " << name
      << endl << "color: "
      << color << endl;
  }
};
class Triangle: public Shape{
  side a, b, c;
  bool check()
  {return (a+b>c && a+c>b && b+c>a);}// true, false
  public:
  Triangle(side a, side b, side c):Shape("Triangle" , "Red"){
	  this->a=a;
	  this->b=b;
	  this->c=c;
	  if(!check()){
		  cout<<"These sides do not generate a triangle: ";
		  print();
	  }
  }
  virtual void print(){
    Shape::print();
    a.print();cout<<",\t";b.print();
    cout<<",\t";c.print();cout<<endl;
  }
  void input(){
    //int k;
    do{
      //cout<<"Enter a: ";cin>>k;
      //a=k;
      a.input();
      //cout<<"Enter b: ";cin>>k;
      //b=k;
      b.input();
      //cout<<"Enter c: ";cin>>k;
      //c=k;
      c.input();
    }while(!check());
  }
};
void f2(void){
	side a(3);
	side b(4),c(5);
	side d;
	d = a + b;
	d.show();
	cout<<endl;
	d = a + 3;
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
int main(){
  //f1();
  f2();
}