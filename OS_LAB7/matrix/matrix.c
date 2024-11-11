#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MATRIX_SIZE 20
#define NUM_THREADS 10

int matA[MATRIX_SIZE][MATRIX_SIZE]; 
int matB[MATRIX_SIZE][MATRIX_SIZE]; 

int matSumResult[MATRIX_SIZE][MATRIX_SIZE];
int matDiffResult[MATRIX_SIZE][MATRIX_SIZE]; 
int matProductResult[MATRIX_SIZE][MATRIX_SIZE];

// Structure to hold cell coordinates for each thread
typedef struct {
    int startRow;
    int endRow;
} ThreadData;

// Fill matrix with random values
void fillMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

// Print matrix values
void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Computes the sum for a segment of the matrix
void* computeSum(void* args) {
    ThreadData* data = (ThreadData*) args;
    for (int i = data->startRow; i < data->endRow; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matSumResult[i][j] = matA[i][j] + matB[i][j];
        }
    }
    pthread_exit(0);
}

// Computes the difference for a segment of the matrix
void* computeDiff(void* args) {
    ThreadData* data = (ThreadData*) args;
    for (int i = data->startRow; i < data->endRow; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matDiffResult[i][j] = matA[i][j] - matB[i][j];
        }
    }
    pthread_exit(0);
}

// Computes the product for a segment of the matrix
void* computeProduct(void* args) {
    ThreadData* data = (ThreadData*) args;
    for (int i = data->startRow; i < data->endRow; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matProductResult[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                matProductResult[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    pthread_exit(0);
}

int main() {
    srand(time(0));  // Initialize random seed
    
    // Fill matrices with random values
    fillMatrix(matA);
    fillMatrix(matB);

    // Print initial matrices
    printf("Matrix A:\n");
    printMatrix(matA);
    printf("Matrix B:\n");
    printMatrix(matB);

    // Array of threads and data for each thread
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];

    // Calculate rows each thread should handle
    int rowsPerThread = MATRIX_SIZE / NUM_THREADS;

    // Create threads for addition
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].startRow = i * rowsPerThread;
        threadData[i].endRow = (i + 1) * rowsPerThread;
        pthread_create(&threads[i], NULL, computeSum, (void*) &threadData[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create threads for subtraction
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, computeDiff, (void*) &threadData[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create threads for dot product
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, computeProduct, (void*) &threadData[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    printf("Results:\n");
    printf("Sum:\n");
    printMatrix(matSumResult);
    printf("Difference:\n");
    printMatrix(matDiffResult);
    printf("Product:\n");
    printMatrix(matProductResult);

    return 0;
}
