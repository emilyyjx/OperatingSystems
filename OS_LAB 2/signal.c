/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("Hello World!\n");
    alarm(1);
}

int main(int argc, char * argv[]) {
    signal(SIGALRM, handler);
    alarm(1); 
    while(1) {
        pause(); //wait for the next signal to be caught
        printf("Turing was right!\n");
    }
    return 0; // this line won't be executed
}