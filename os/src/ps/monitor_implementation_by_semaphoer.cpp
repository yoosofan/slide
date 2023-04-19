semaphore mutex=1;semaphore next=0; int next-count = 0;
//Each external procedure F will be replaced by
    mutex.P();
//    body of F;
    if (next-count > 0)     next.V()
    else                    mutex.V();
//For each condition variable x, we  have:
semaphore x-sem=0;  int x-count = 0;
//The operation x.wait can be implemented as:
x-count++;
if (next-count > 0)     next.V();
else                    mutex.V();
x-sem.P();      x-count--;
//The operation x.signal can be implemented as:
if (x-count > 0)
{next-count++;  x-sem.V();  next.P();   next-count--;}
