  semaphore mutex=1;
  semaphore next=0; 
  int next_count = 0;

/* Each external 
 * procedure F will 
 * be replaced by */
    mutex.P();
//    body of F;
  if(next_count > 0)
    next.V()
  else  mutex.V();

/* For each condition
 *  variable x, we  have:*/
semaphore x_sem=0;  
int x-_ount = 0;

/* The operation x.wait 
 * can be implemented as:*/
  x-count++;
  if (next-count > 0)     
    next.V();
  else
    mutex.V();
  x_sem.P();      
  x_count--;

/* The operation x.signal 
 * can be implemented as:*/
if (x-count > 0){
  next_count++;  
  x_sem.V();  
  next.P();   
  next_count--;
}