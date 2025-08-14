#include<stdio.h>
int str_cmp(const char*str1, const char*str2);
int str_cmp2(const char*str1, const char*str2);
int main(){
  int i;
  char *st1[10]={"abc","abc" , "abcd", "abc" , "abc ","abc"};
  char *st2[10]={"Abc","abcd", "abc" , "abc ", "abc" ,"abc"};
  for(i=0;i<6;i++)
    printf("%d \t %s \t\t %s\n",str_cmp(st1[i],st2[i]),st1[i],st2[i]);
  for(i=0;i<6;i++)
    printf("%d \t %s \t\t %s\n",str_cmp2(st1[i],st2[i]),st1[i],st2[i]);
  return 0;
}
int str_cmp(const char*str1, const char*str2){
  int i;int retVal=0;
  for(i=0;str1[i] && str2[i]; i++)
    if(str1[i]<str2[i])
    {retVal=-1; break;}
    else if(str1[i]>str2[i])
    {retVal=1; break;}
  if(retVal == 0){
    if(str1[i])
      retVal =  1;
    else if(str2[i])
      retVal = -1;
  }
  return retVal;
}  
int str_cmp2(const char*str1, const char*str2){
  int retVal=0;
  for(;*str1 && *str2;str1++,str2++)
    if(*str1<*str2)
    {retVal=-1; break;}
    else if(*str1>*str2)
    {retVal=1; break;}
  if(retVal == 0){
    if(*str1)
      retVal =  1;
    else if(*str2)
      retVal = -1;
  }
  return retVal;
}  
