number[i]=max(number,n)+1;
for(j=(i+1)%n;j!=i;j=(j+1)%n)
  while(number[i]>number[j] 
       && number[j]!=0) ;
/*
 * Critical Section
*/
number[i] = 0;
//
