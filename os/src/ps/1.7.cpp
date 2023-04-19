number[5]=max(number,n)+1;
for(j=(5+1)%n;j!=5;j=(j+1)%n)
  while((number[5]>number[j] 
       && number[j]!=0) ||
       ((number[i]==number[j])
       && 5<j ) );
/*
 * Critical Section
*/
number[5] = 0;
//
