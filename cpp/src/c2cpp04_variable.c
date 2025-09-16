#include<stdio.h>
/*#include<iostream>
using namespace std;*/
int main(){
  int s1 = 2;
  // int sum = s1+4;
  printf("Enter mark\n");
  scanf("%d",& s1 );
  /*cout << "sss" ;*/
  int s2;
  printf("Enter mark\n");
  scanf("%d",& s2 );
  int s3;
  printf("Enter mark\n");
  scanf("%d",& s3 );
  // static int sum= s1 + s2 + s3;  // error
  const int m1=2, m2=3, m3=4;
  static int sum= m1 + m2 + m3; 
  // Assignment
  printf("%d\n",sum);
}
