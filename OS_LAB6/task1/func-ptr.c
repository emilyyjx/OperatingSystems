#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

#include "process.h"
#include "util.h"

#define DEBUG 0 // change this to 1 to enable verbose output

/**
 * Signature for a function pointer that can compare
 * You need to cast the input into its actual 
 * type and then compare them according to your
 * custom logic
 */
typedef int (*Comparer) (const void *a, const void *b);

/**
 * compares 2 processes
 * You can assume: 
 * - Process ids will be unique
 * - No 2 processes will have the same arrival time
 */
int my_comparer(const void *this, const void *that) {
    // Cast the void pointers to Process pointers
    const Process *process1 = (const Process *)this;
    const Process *process2 = (const Process *)that;

    // Compare based on arrival time first
    if (process1->arrival_time < process2->arrival_time) {
        return -1;
    } else if (process1->arrival_time > process2->arrival_time) {
        return 1;
    } else {
        // If arrival times are the same, compare by priority
        if (process1->priority > process2->priority) {
            return -1;
        } else if (process1->priority < process2->priority) {
            return 1;
        } else {
            return 0; // Processes are equivalent in sorting terms
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./func-ptr <input-file-path>\n");
        fflush(stdout);
        return 1;
    }

    // Parse the input file
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error: Invalid filepath\n");
        fflush(stdout);
        return 1;
    }

    Process *processes = parse_file(input_file);

    // Sort the input using qsort and the comparer function
    Comparer process_comparer = &my_comparer;
    qsort(processes, P_SIZE, sizeof(Process), process_comparer);

    // Print the sorted data
    for (int i = 0; i < P_SIZE; i++) {
        printf("%d (%d, %d)\n", processes[i].pid, processes[i].priority, processes[i].arrival_time);
    }
    fflush(stdout);
    fflush(stderr);

    // Clean up
    free(processes);
    fclose(input_file);
    return 0;
}
