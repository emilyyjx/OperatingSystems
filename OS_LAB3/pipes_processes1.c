// C program to demonstrate two-way communication using pipes
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main() 
{ 
    // Two pipes to create two-way communication
    int fd1[2]; // Used to store two ends of first pipe 
    int fd2[2]; // Used to store two ends of second pipe 

    char fixed_str1[] = "howard.edu"; 
    char fixed_str2[] = "gobison.org";
    char input_str1[100]; 
    char input_str2[100];
    pid_t p; 

    if (pipe(fd1)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    if (pipe(fd2)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 

    scanf("%s", input_str1); 
    p = fork(); 

    if (p < 0) 
    { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 

    // Parent process P1
    else if (p > 0) 
    { 
        close(fd1[0]); // Close reading end of first pipe
        close(fd2[1]); // Close writing end of second pipe

        // Write input string and close writing end of first pipe
        write(fd1[1], input_str1, strlen(input_str1)+1); 
        close(fd1[1]); 

        // Wait for child to send a string
        wait(NULL); 

        // Read the second string from child, concatenate and print
        read(fd2[0], input_str2, 100); 
        strcat(input_str2, fixed_str2);
        printf("%s\n", input_str2);

        close(fd2[0]); // Close the reading end of second pipe
    } 

    // Child process P2
    else
    { 
        close(fd1[1]); // Close writing end of first pipe
        close(fd2[0]); // Close reading end of second pipe

        // Read a string using first pipe
        char concat_str[100]; 
        read(fd1[0], concat_str, 100); 

        // Concatenate a fixed string with it
        strcat(concat_str, fixed_str1); 
        printf("%s\n", concat_str);

        close(fd1[0]); // Close reading end of first pipe

        // Get another input from user
        printf("Enter another string:");
        scanf("%s", input_str2); 
        write(fd2[1], input_str2, strlen(input_str2)+1); 
        close(fd2[1]); // Close writing end after sending

        exit(0); 
    } 
} 