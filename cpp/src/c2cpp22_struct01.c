#include <stdio.h>


struct firstStruct{  };
struct secondStruct{ };
struct thirdStruct{ };
struct firstStruct f1(void);
void f2(struct firstStruct);

int main(){
  struct firstStruct myfs;
  myfs = f1();
  f2(myfs);
  return 0;
}
struct firstStruct  f1(void){
  struct firstStruct fs1;
  struct secondStruct ss1;
  struct thirdStruct ts1;
  return fs1;
}

void f2(struct firstStruct m1){
  printf("%p\n", &m1);
}
