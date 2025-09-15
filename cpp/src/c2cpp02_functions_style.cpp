#include<stdio.h>
//c2cpp02_functions_style.cpp
int min(int, int); 
int input();
void myf();
void printTriangle();
void printSquare();

int main(){
  int n = 0;
  do{
    printf("Enter your choice. \
             Enter 4 for end\n");
    n = input();
    if(n == 1)  
      myf();
    else if(n == 2)
      printTriangle();
    else if(n == 3)
      printSquare();
    else if(n != 4)
      printf("wrong number\n");
  }while(n != 4);
}

void printSquare(void){
  int n, i = 0, j; 
  n = input();
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++)   
      printf("*");
    printf("\n");
  }
}

void printTriangle(){
  int n, i, j; 
  n = input();
  for(i = 0; i < n; i++){
    for(j = 0; j <= i; j++) 
      printf("*");
    printf("\n");
  }
}

int min(int a, int b)
{return a < b ? a : b;}

int input(void){
  int a;
  do{
    printf("Enter a>0: ");
    scanf("%d", &a);
  }while(a <= 0);
  return a;
}

void myf(){
  int a = input(), b = input();
  printf("min %d\n", min(a, b));
}
