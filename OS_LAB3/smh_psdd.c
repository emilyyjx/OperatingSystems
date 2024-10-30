#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define BANK_ACCOUNT 0
#define TURN 1

void ClientProcess(int SharedMem[]);
void random_sleep();
int random_amount(int max);

int main() {
    int ShmID;
    int *ShmPTR;
    pid_t pid;
    int status;
    int local_account, balance;

    ShmID = shmget(IPC_PRIVATE, 2*sizeof(int), IPC_CREAT | 0666);
    if (ShmID < 0) {
        printf("*** shmget error (server) ***\n");
        exit(1);
    }
    printf("Server has received a shared memory...\n");

    ShmPTR = (int *) shmat(ShmID, NULL, 0);
    if (*ShmPTR == -1) {
        printf("*** shmat error (server) ***\n");
        exit(1);
    }
    printf("Server has attached the shared memory...\n");

    // Initialize shared variables
    ShmPTR[BANK_ACCOUNT] = 0; // BankAccount
    ShmPTR[TURN] = 0; // Turn

    printf("Server is about to fork a child process...\n");
    pid = fork();
    if (pid < 0) {
        printf("*** fork error (server) ***\n");
        exit(1);
    } else if (pid == 0) {
        ClientProcess(ShmPTR);
        exit(0);
    }

    // Parent process (Dear Old Dad)
    for (int i = 0; i < 25; i++) {
        random_sleep();

        while (ShmPTR[TURN] != 0); // Wait for turn to be 0

        local_account = ShmPTR[BANK_ACCOUNT];
        if (local_account <= 100) {
            balance = random_amount(100);
            if (balance % 2 == 0) {
                local_account += balance;
                printf("Dear old Dad: Deposits $%d / Balance = $%d\n", balance, local_account);
            } else {
                printf("Dear old Dad: Doesn't have any money to give\n");
            }
        } else {
            printf("Dear old Dad: Thinks Student has enough Cash ($%d)\n", local_account);
        }

        ShmPTR[BANK_ACCOUNT] = local_account;
        ShmPTR[TURN] = 1; // Set turn to 1 for child
    }

    wait(&status); // Wait for child to complete
    printf("Server has detected the completion of its child...\n");

    shmdt((void *) ShmPTR);
    printf("Server has detached its shared memory...\n");
    shmctl(ShmID, IPC_RMID, NULL);
    printf("Server has removed its shared memory...\n");
    printf("Server exits...\n");

    return 0;
}

void ClientProcess(int SharedMem[]) {
    int local_account, balance;

    for (int i = 0; i < 25; i++) {
        random_sleep();

        while (SharedMem[TURN] != 1); // Wait for turn to be 1

        local_account = SharedMem[BANK_ACCOUNT];
        balance = random_amount(50);
        printf("Poor Student needs $%d\n", balance);

        if (balance <= local_account) {
            local_account -= balance;
            printf("Poor Student: Withdraws $%d / Balance = $%d\n", balance, local_account);
        } else {
            printf("Poor Student: Not Enough Cash ($%d)\n", local_account);
        }

        SharedMem[BANK_ACCOUNT] = local_account;
        SharedMem[TURN] = 0; // Set turn to 0 for parent
    }
    printf("   Client is about to exit\n");
}

void random_sleep() {
    int time = rand() % 6; // Random sleep time between 0-5 seconds
    sleep(time);
}

int random_amount(int max) {
    return rand() % (max + 1);
}