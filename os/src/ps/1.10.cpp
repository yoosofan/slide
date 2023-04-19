choose[i]=true;
number[i]=max(number,n)+1;
choose[i]=false;
for(j=(i+1)%n;j!=i;j=(j+1)%n){
  while(choose[j]==true) 
      ;
  while((number[i]>number[j] 
       && number[j]!=0) || 
       ((number[i]==number[j])
       && i<j  ) );
/* Critical Section */
number[i] = 0;
//
