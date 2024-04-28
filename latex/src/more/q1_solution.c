#include<stdio.h>
int main(){
  int i,n,a[100], sum; /* sum */
  i=0;
  printf("Enter  0 < n < 100 : ");
  scanf("%d",& n);
  if(n>0){
    if(i<n){
      while(i<n){
        printf("Enter a[%d] : ", i);
        scanf("%d",& a[i]);
        i = i + 1;
      }
      sum = 0;
      i = 0 ;  /* i =0 */
      while(i<n){
        sum = sum+a[i];
        i = i + 1 ;
      }
      printf("The output is: %d", sum);
    }
    else{
      printf("Wrong input! n>=100 \n");
    }
  }
  else{
    printf("Wrong input. n <=0 \n");
  }
  return 0;
}
