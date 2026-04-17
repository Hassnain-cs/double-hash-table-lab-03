#include "hash.h"
#include <stdio.h>

// First hash function, just modulo to get starting position
int h1(int key, int M) {
    return key % M;
}

// Second hash function, determines step size when there's a collision
int h2(int key, int R) {
    return R - (key % R);
}

// Main function that fills the hash table
void hashInit(int* hashTable, int* input, int M, int R) {

    // Start with empty slots (using -1 to mean empty)
    for (int i = 0; i < M; i++) {
        hashTable[i] = -1;
    }

    // Go through each number we need to insert
    // We have 21 numbers total (that's why j < 21)

    for (int j = 0; j < 21; j++) {
        int key = input[j];     // the number we want to insert
        int i = 0;              // how many steps we've tried
        int placed = 0;         // whether we found a spot yet

        int step = h2(key, R);  // how far to jump when there's a collision

        // Keep looking for an empty spot until we find one or run out of tries
        while (!placed && i < M) {
            // Double hashing formula: start position + (step * attempt) mod table size
            int index = (h1(key, M) + step * i) % M;

            // If this spot is empty, put the number here
            if (hashTable[index] == -1) {
                hashTable[index] = key;
                placed = 1;     // we're done with this number
            }
            i++;  // try the next spot if this one was taken
        }

        // If we tried all spots and couldn't place it (shouldn't happen with M=23)
        if (!placed) {
            printf("Could not place %d\n", key);
        }
    }
}