#include "hash.h"
#include <stdio.h>

int main() {

    // The 21 numbers given in the assignment 
    int input[21] = {
        1234, 5678, 9012, 3456, 7890, 2345, 6789,
        123, 4567, 8901, 1235, 5679, 9013, 3457,
        7891, 2346, 6790, 124, 4568, 8902, 1236
    };

    // Make a hash table with 23 spots (prime number works better for hashing)
    int hashTable[23];

    int M = 23;  // Table size
    int R = 5;   // The R value for the second hash function

    // Fill up the hash table with our numbers
    hashInit(hashTable, input, M, R);

    // Print out what's in the hash table
    printf("Hash Table (size 23):\n");
    for (int i = 0; i < M; i++) {
        if (hashTable[i] != -1) {
            // This spot has a number in it
            printf("Index %d: %d\n", i, hashTable[i]);
        }
        else {
            // This spot is still empty (-1 means empty)
            printf("Index %d: empty\n", i);
        }
    }

    return 0;
}