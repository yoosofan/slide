#include<stdio.h>

struct date{ int year, month, day; };
struct student{
  char name[50]; 
  char stdNumber[15]; 
  struct date birthDate;
};
struct date input_date(void);
struct student input_student(void);
void print_date(struct date d1);
void print_student(struct student st);
int main(){
  struct student st1[50];
  int n, i=0;
  printf("Enter number of \
          students(0<n<50) ");
  scanf("%d",&n);
  if(n>0 && n<50)
    do{
      st1[i] = input_student();
      print_student(st1[i]);
      i++;
    }while(i<n);
  else printf("0<n<50, %d",n);
}
struct date input_date(void){
  struct date d1;
  printf("Enter year:{1350..1390} "); 
  scanf("%d",&d1.year);
  printf("Enter month{1..12}:"); 
  scanf("%d",&d1.month);
  printf("Enter day{1..31}:"); 
  scanf("%d",&d1.day);
  return d1;
}
void print_date(struct date d1){
  printf("year=%d,\tmonth=%d,\tday=%d\n",
    d1.year,d1.month,d1.day);
}
struct student input_student(void){
  struct student st;
  printf("Enter name :");
  scanf("%s",st.name);
  printf("Enter studnet number :");
  scanf("%s",st.stdNumber);
  printf("Enter birth date :"); 
  st.birthDate = input_date();
  return st;
}
void print_student(struct student st){
  printf("name=%s\n",st.name);
  printf("number=%s\n",st.stdNumber);
  print_date(st.birthDate);
}
