#include "hash.h"
#include <stdio.h>

int main() {

    // Input values given in assignment
    int input[21] = {
        1234, 5678, 9012, 3456, 7890, 2345, 6789,
        123, 4567, 8901, 1235, 5679, 9013, 3457,
        7891, 2346, 6790, 124, 4568, 8902, 1236
    };

    int hashTable[21];

    int M = 21;  // table size
    int R = 5;   // used in second hash function

    // Call our hashing function
    hashInit(hashTable, input, M, R);

    // Print the final hash table
    printf("Hash Table:\n");
    for (int i = 0; i < M; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }

    return 0;
}