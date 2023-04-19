number[8]=max(number,n)+1;
for(j=(8+1)%n;j!=8;j=(j+1)%n)
  while(number[8]>number[j] 
       && number[j]!=0) ;
/*
 * Critical Section
*/
number[8] = 0;
//
