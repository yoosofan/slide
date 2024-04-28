#include<stdio.h>
int cmb(int,int);
int main(){
  int m,n;
  printf("Enter n > 0 : "); scanf("%d",&n);
  printf("Enter m >= n: "); scanf("%d",&m);
  printf("%d\n",cmb(n,m));
  return 0;
}
int cmb(int n, int m){
  if(n==m || m==0) return 1;
  return cmb(n-1,m)+cmb(n-1,m-1);
}
