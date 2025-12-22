#include<iostream>
#include<fstream>
using namespace std;
struct myMat{int n; double**p;};
myMat read(const char *name){
  myMat m;m.n=0;m.p=0;double *pd=0;
  ifstream f(name);
  if(!f){cout<<"cannot open file"<<endl;return m;}
  f.read((char*)&m.n,sizeof(int));
  pd=new double[m.n*m.n];
  f.read((char*)pd,sizeof(double)*m.n*m.n);
  f.close();
  m.p=new double*[m.n];
  for(int i=0;i<m.n;i++){
    m.p[i]=new double[m.n];
    for(int j=0;j<m.n;j++)
      m.p[i][j]=pd[i*m.n+j];
  }
  delete[]pd;
  f.close();
  return m;
}
bool write(const char*name,myMat m){
  ofstream  f1(name);
  if(!f1){cout<<"cannot open file"<<endl;return false;}
  double*pd=new double[m.n*m.n];
  for(int i=0;i<m.n;i++)
    for(int j=0;j<m.n;j++)
      pd[i*m.n+j]=m.p[i][j];
  f1.write((char*)&m.n,sizeof(int));
  f1.write((char*)pd,sizeof(double)*m.n*m.n);
  f1.close();
  return true;
}
struct mat2{int n; double p[100][100];};
mat2  read2(const char*name){
  mat2 m; m.n=0;
  ifstream f(name);
  if(!f){cout<<""<<endl;exit(0);}
  f.read((char*)&m.n,sizeof(int));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      f.read((char*)&m.p[i][j],sizeof(double));
  f.close();
}
bool write2(const char*name,mat2 m){
  ofstream  f1(name);
  if(!f1){cout<<"cannot open file"<<endl;return false;}
  f1.write((char*)&m.n,sizeof(int));
  for(int i=0;i<m.n;i++)
    for(int j=0;j<m.n;j++)
      f1.write((char*)&m.p[i][j],sizeof(double));
  f1.close();
  return true;
}
myMat input(){
  int i,j;myMat m;
  cout<<"enter n "; cin>>m.n;
  m.p=new double*[m.n];
  for(i=0;i<m.n;i++){
    m.p[i]=new double[m.n];
    for(j=0;j<m.n;j++){
      cout<<"enter a["<<i<<"]["<<j<<"]:";
      cin>>m.p[i][j];
    }
  }
  return m;
}
void print(myMat m){
  int i,j;cout<<m.n<<endl;
  for(i=0;i<m.n;i++){
    for(j=0;j<m.n;j++) cout<<m.p[i][j]<<'\t';
    cout<<endl;
  }
}
myMat mult(myMat m1, myMat m2){
  myMat m3;m3.n=m1.n;m3.p=new double*[m1.n];
  for(int i=0;i<m1.n;i++){
    m3.p[i]=new double[m1.n];
    for(int j=0;j<m1.n;j++){
      double sum=0;
      for(int k=0;k<m1.n;k++) sum+=m1.p[i][k]*m2.p[k][j];
      m3.p[i][j]=sum;
    }
  }
  return m3;
}
int main(){
  //myMat m1,m2; m1=input();m2=input();write("mat1.in",m1);write("mat2.in",m2);
  myMat m1=read("mat1.in"),m2=read("mat2.in"),m3;
  print(m1);print(m2);  
  m3=mult(m1,m2);  
  write("mat3.in",m3);
  print(m3);
  return 0;
}
