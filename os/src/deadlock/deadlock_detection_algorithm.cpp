/* ********************* 1   ************************** */
bool finish[N]; int work[M];  int i,j; bool flag=true;
work = Available
for(i=0; i<N; i++)
  if(Allocation[i]!=0)    finish[i]=false;
  else                    finish[i]=true;
/* ********************* 2   ************************** */
flag=true;
while(flag==true){
  flag=false;
  for(i=0;i<N;i++)
    if( (finish[i] == false) && (Request[i] <= work){
          finish[i]=true;
          work += Allocation[i];
          flag=true;
        }
    }
}/* ********************* 3   ************************** */
flag = false;
for(i=0;i<N; i++)
  if(finish[i] == false){ flag=true;    cout<<"process "<<i<<" is deadlocked."<<endl;  }
if(flag==true)  cout<<"The system is deadlocked"<<endl;
else cout<<"The system is not deadlocked"<<endl;
