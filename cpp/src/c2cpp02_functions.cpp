#include<cstdio> /* ./a.out >a1.txt */
using namespace std;
int min(int, int); int input(void);
void myf(void);void printTriangle(void);
void printSquare(void); void menu(void);
int main(){
  menu()
  return 0;
}
void menu(void){int n;
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
void printSquare(void){
  int n,i,j; n=input();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)   printf("*");
    printf("\n");
  }
}
void printTriangle(void){
  int n,i,j; n=input();
  for(i=0;i<n;i++){
    for(j=0;j<=i;j++) printf("*");
    printf("\n");
  }
}int min(int a, int b){return a<b ? a : b;}
int input(void){int a;
  do{
    printf("Enter a>0: ");
    scanf("%d",&a);
  }while(a<=0);
  return a;
}void myf(void){
  int a=input(), b=input();
  printf("min %d\n",min(a,b));
}
