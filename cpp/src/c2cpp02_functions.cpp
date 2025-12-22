#include<cstdio> /* ./a.out >a1.txt */
using namespace std;
int min(int, int); int input();
void myf();void printTriangle();
void printSquare(); void menu();
int main(){
  menu()
  return 0;
}
void menu(){int n;
  do{
    printf("Enter your choice. \
             Enter 4 for end\n");
    n=input();
    if(n==1)  myf();
    else if(n==2)printTriangle();
    else if(n==3)printSquare();
    else if(n!=4)printf("wrong number\n");
  }while(n!=4);
}
void printSquare(){
  int n,i,j; n=input();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)   printf("*");
    printf("\n");
  }
}
void printTriangle(){
  int n,i,j; n=input();
  for(i=0;i<n;i++){
    for(j=0;j<=i;j++) printf("*");
    printf("\n");
  }
}int min(int a, int b){return a<b ? a : b;}
int input(){int a;
  do{
    printf("Enter a>0: ");
    scanf("%d",&a);
  }while(a<=0);
  return a;
}void myf(){
  int a=input(), b=input();
  printf("min %d\n",min(a,b));
}
