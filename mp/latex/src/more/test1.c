#include<stdio.h>
int main(){
  int a=1 , b=0, i=0;
  char aP[]=
   {'a','d','g','y',
    'u','o','j','\0'
   };
  int iap[]=
   {10,20,30,40,50,
    60,70,80,90,100
   };
  int *pi1,*pi2;
  char *pc1;
  printf("%d\n",
     a? 12:48);
  if(a || b)
    if(a && b)
      if(a != b)i=1;
      else i=2;
    else i=3;
  else i=4;
  printf("%d  ",i);
  printf("%d  ",
    (i=++a-b--)+2);
  a=12;
  printf("%d\n",
     iap[i]);
  pi1=&a;pi2=&b;
  pi1=pi2;
  printf("%d  ",a);
  pi1=iap;
  pi2=iap+3;
  pi1=pi2;
  printf("%d  " ,
     *pi2);
  pi1=++pi2;
  printf("%d  ",
     ++*++pi1);
  pc1=aP;
  printf("%c\n",
    pc1[3]);
  pc1+=5;
  printf("%s\n",pc1);
  return 0;
}
