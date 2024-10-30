#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t alarm_count = 0;
volatile sig_atomic_t exiting = 0;

void alrm_handler(int signum) {
    alarm_count++;
    alarm(1);
}

void int_handler(int signum) {
    exiting = 1;
}

int main(int argc, char * argv[]) {
    signal(SIGALRM, alrm_handler);
    signal(SIGINT, int_handler);
    alarm(1);
    while(!exiting);
    printf("Program ran for %d seconds\n", alarm_count);
    return 0;
}
