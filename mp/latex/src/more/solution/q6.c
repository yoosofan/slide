#include<stdio.h>
typedef struct {int a[1000];int n;}hn; 
hn add(hn*a1, hn*a2); void print(hn h1);
hn read_hn(const char*msg);
int main(){
  hn h1,h2;
  h1=read_hn("Enter number 1 ");print(h1);
  h2=read_hn("Enter number 2 ");print(h2);
  print(add(&h1,&h2));
  return 0;
}
hn add(hn*h1, hn*h2){
  hn res,*ph;
  int c=0,i,s ;
  for(i=0; i<h1->n && i<h2->n; i++){
    s=h1->a[i]+h2->a[i]+c;
    res.a[i]=s%10;
    c=s/10;
  }
  ph=h1;
  if(i==h1->n)
    ph=h2;
  for(;i<ph->n; i++){
    s=ph->a[i]+c;
    res.a[i]=s%10;
    c=s/10;
  }
  res.n=ph->n;
  if(c)  res.a[res.n++]=c;
  return res;
}
hn read_hn(const char*msg){
  char number1[100],*ps=number1;
  hn h1; int i;
  printf("%s ",msg);scanf("%10s",number1); 
  for(i=0;*ps;ps++,i++)
    h1.a[i]= *ps-48;
  h1.n=i;
  return h1;
}
void print(hn h1){
  int i;
  for(i=0;i<h1.n;i++)
    printf("%d",h1.a[i]);
  printf("\n");
}
  
  
