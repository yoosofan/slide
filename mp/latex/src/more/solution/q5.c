#include<stdio.h>
double exp(double x);
int main(){
  double x;
  printf("Enter number "); scanf("%lf",&x);
  printf("%lf",exp(x));
  return 0;
}
double exp(double x){
  double sum=x+1, term=x, nm=x, f=1; int i;
  for(i=2; term>0.001; sum+=term, i++)
    term = (nm *= x)/(f *= i);
  return sum;
}
