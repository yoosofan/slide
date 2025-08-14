#include<stdio.h>
int bin_search(int a[], int n, int v);
int main(){
  int v;
  int a[]=
    {0, 2, 7, 9, 12, 14, 20, 25, 32, 44} ;
  printf("Enter number "); scanf("%d",&v);
  printf("%d",bin_search( a, sizeof(a)/sizeof(int), v));
  return 0;
}

int bin_search(int a[], int n, int v){
  int end=n,start=0,mid;
  while(start <= end){
    mid=(start+end)/2;
    if(a[mid] < v )     start    =mid +1 ;
    else if(a[mid] > v) end  =mid-1;
    else      break;
  }
  if(start>end) mid=-1;
  return mid;
}
