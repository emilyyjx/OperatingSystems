#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void child_process(){
    srandom(time(NULL)^(getpid()<<16));
    int numbers = random() % 31;
    int i;
    for(i=0; i<numbers; i++) {
      printf("Child PId: %d is going to sleep! \n", getpid());
      sleep(random() % 11);
      printf("Child Pid: %d is awake! \nWhere is my Parent: %d?/n", getpid(), getppid());
    }
    exit(0);
}

int main() {
    pid_t child1, child2;
    child1 = fork();
    if(child1 == 0){
        child_process();
    } else {
        child2 = fork();
        if(child2 == 0) {
            child_process();
        } else {
            int status;
            pid_t pid = wait(&status);
            printf("Child Pid: %d has completed\n", pid);
            pid = wait(&status);
            printf("Child PIid: %d has completed\n", pid);
        }

    }
    return 0;
}