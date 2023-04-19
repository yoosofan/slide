struct semaphore {
  int count;
  queueType queue;
};
void semWait(semaphore s){
  s.count--;
  if (s.count < 0) {
    /* place this process in s.queue */;
    /* block this process */;
  }
}
void semSignal(semaphore s){
  s.count++;
  if (s.count<= 0){
    /* remove a process P from s.queue */;
    /* place process P on ready list */;
  }
}
