#include<stdio.h>
/*#include<iostream>
using namespace std;*/
int f1(const int m1);
# define m33 50
const int global_variable_m44 = 50;
int main(){
  int s1 = 2;
  int arr[50];
  int i;
  for(i=0; i< 50; i++)
    arr[i] = i*2;
  int arr2[m33];
  for(i=0; i< m33; i++)
    arr2[i] = i*2;
  int arr3[global_variable_m44];
  for(i=0; i< global_variable_m44; i++)
    arr2[i] = i*2;
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
  printf("%d\n",f1(m2));
}
int f1(const int m1){
  static int sum = 5;
  sum = 5;
  return sum++ + m1;
}
