#include<iostream>
#include<string>
using namespace std;
class complexCls{
  double r,i;
 public:
  complexCls(double a=0,double b=0)
  {r=a; i=b;}
  complexCls operator+(const complexCls& a){
    complexCls ret; ret.r=r+a.r;
    ret.i=i+a.i; return ret;
  }
  friend ostream& operator<<(
    ostream&o1, const complexCls& m)
  {o1<<'('<<m.r<<','<<m.i<<')';return o1;}
  bool operator==(complexCls m2)
  {return r == m2.r && i == m2.i;}
};
template<typename T> class Node{
  T v; Node<T>* next;
  public:
  Node(T* m1=nullptr)
  {if(m1)v=*m1;next=nullptr;}
  bool operator==(Node m2)
  {return v==m2.v;}
};
template<typename Type=string,
  typename Index=int, int N=20>
class myArray{
  Type* a = nullptr;
  int n = N,
  count = 0;
  Index *ind = nullptr;
public:
  myArray(){
    this->n=N;
    a=new Type[n];
    ind=new Index[n];
    count=0;
  }
  ~myArray()
  {n=0; delete[] a; delete[]ind;}
  myArray(const myArray& m1){
    n=m1.n; a=new Type[n];
    ind=new Index[n];
    count=m1.count;
    for(int i=0;i<count;i++)
      a[i]=m1.a[i] , ind[i]=m1.ind[i];
  }/*myArray(myArray&& m1){n=m1.n; a=m1.a; ind=m1.ind; count=m1.count; m1.n=0; m1.a=nullptr;m1.ind=nullptr;}*/
  Type& operator[](const Index& index){
    int i;
    for(i=0; i<count;i++)
     if(ind[i]==index) return a[i];
    if(i<n){ind[count]=index; return a[count++];}
    throw 1;
  }
  myArray operator=(const myArray&m1){
    n=m1.n;a=new Type[n]; ind=new Index[n]; count=m1.count;
    for(int i=0;i<count;i++)
      a[i]=m1.a[i] , ind[i]=m1.ind[i];
    return *this;
  }
  template<class T,class I,int K>
  friend ostream&operator<<(ostream&o1,myArray<T,I,K>);
};
template<class T,class I,int K>
ostream&operator<<(ostream&o1,const myArray<T,I,K>m1){
  o1<<m1.n<<"   "<<m1.count<<endl;
  for(int i=0;i<m1.count;i++)
    o1<<'['<<m1.ind[i]<<"]="<<m1.a[i]<<endl;
  return o1;
}
void f1(){throw "dghdd";}
int main(){
  myArray<int, Node<int> >m1;
  int aa=12; Node<int> n1(&aa);  m1[n1]=44;
  cout<<m1[n1]<<endl;  aa=4;
  m1[Node<int>(&aa)]=4;
  cout<<m1[Node<int>(new int(4))]<<endl;
  try{ myArray<int,string,3> cm1;
    myArray<string,complexCls> am1;
    myArray<string> kl1; kl1[0]="dddd";kl1[13]="asddd"; cout<<kl1;
    cm1["ali"]=4; cout<<"line: "<< __LINE__ <<endl;
    cm1["Reza"]=7; myArray<> hk1;// myArray cfw1;
    cout<<cm1["ali"]<<endl;
    cout<<cm1["Reza"]<<endl;
    am1[complexCls(3,4)]="Hamid";   f1();
    cout<<am1[complexCls(3,4)]<<endl;
    cout<<cm1;  cout<<am1;
  }catch(const int &a){cout<<"out of range"<<endl;}
  //}catch(const myException &a){cout<<"out of range"<<a.what()<<endl;}
   catch(...){cout<<"Exception .... "<<endl;}
}
