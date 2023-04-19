/*
Copyright 2018 Ahmad Yoosofan <yoosofan@myfastmail.com>, yoosofan@mail.com, yoosofan@kashanu.ac.ir
http://yoosofan.github.io
http://yoosofan.kashanu.ac.ir
University of Kashan (http://kashanu.ac.ir)
Do not remove this comment as copyright
*/

#include<iostream>
using namespace std;const int N=100; /* number of processes*/const int M=200; // number of resources
int Available[M];/*={ ... }*/; int Allocation[N][M];/*= { ... };*/
int Request[N][M];/* = { ... };*/
int deadlock_detection(void){
  bool finish[N]; int work[M];  int i,j; bool flag=true;
  for(i=0;i<N;i++) work[i] = Available[i];//work = Available ;
  for(i=0; i<N; i++){
    for(j=0;j<M;j++) if(Allocation[i][j]!=0) break;
    if(j==M) finish[i]=false;  else finish[i]=true;
  }
  flag=true;
  while(flag==true){
    flag=false;
    for(i=0;i<N;i++)
      if(finish[i]== false){
        for(j=0;j<M;j++)
          if(Request[i][j] > work[j]) break;
        if(j==M){
            finish[i]=true;
            for(j=0;j<M;j++) work[j] += Allocation[i][j]; //work += Allocation[i];
            flag=true;
          }
      }
  } j=0; int deadlocked_process[N];
  for(i=0;i<N;i++)deadlocked_process[i]=-1;/*={-1,-1,...,-1 };*/
  for(i=0;i<N; i++)
    if(finish[i] == false)
      deadlocked_process[j++]=i;
  if(j!=0){
    cout<<"The system is in a deadlocked"<<endl;
    for(i=0;i<j;i++) cout<<"process "<<deadlocked_process[i]<<" is deadlocked."<<endl;
  }
  return j;
}
int main(){
  deadlock_detection();
  return 0;
}
