#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(){
  int i=1,a=2,b,c=3;
  b = i>a ? a>c ? c:a : i>c?c:i;
  printf("%d\t",b);
  printf("%d\n", i>a ? a>c?c:a : i>c?c:i);
  b=1;a=2;c=1;
  printf("%d\t",b+=a+=c);
  printf("%d,%d,%d\n",b,a,c);
  printf("%d\n",printf("%d\n",b));
  printf("%lf\n",sin(0.12));
  printf("%d\n",abs(-12));
  printf("%lf\n",fabs(-0.12));
  printf("%lf\n",pow(2,4));
  printf("%lf\n",sqrt(2));
  printf("%lf\n",pow(2,0.5));
  i=2;a=3;b=4;
  i= a,b; /*   */
  printf("%d\n",i);
}
