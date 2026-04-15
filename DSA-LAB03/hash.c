#include "hash.h"
#include <stdio.h>

/*
 * First hash function
 * This decides the "starting index" for a key
 */
int h1(int key, int M) {
    return key % M;  // simple modulo hashing
}

/*
 * Second hash function
 * This decides how far we jump when a collision happens
 */
int h2(int key, int R) {
    int step = R - (key % R);

    // Just in case step becomes 0, we fix it to 1
    // because step = 0 would break probing completely
    if (step == 0) {
        step = 1;
    }

    return step;
}

/*
 * Main function that fills the hash table
 */
void hashInit(int* hashTable, int* input, int M, int R) {

    // Step 1: Mark all positions as empty
    // We use -1 to represent empty slots
    for (int i = 0; i < M; i++) {
        hashTable[i] = -1;
    }

    // Step 2: Insert each element one by one
    for (int j = 0; j < M; j++) {

        int key = input[j];   // current value we want to insert
        int i = 0;            // probe counter
        int placed = 0;       // flag to check if inserted

        // Calculate step size only once (more efficient)
        int step = h2(key, R);

        /*
         * IMPORTANT FIX:
         * If step and M share factors, we might not visit all slots.
         * So in that case, we fall back to step = 1 (linear probing).
         */
        int adjustedStep = (M % step == 0 && step > 1) ? 1 : step;

        // Keep probing until we find an empty slot
        while (!placed && i < M) {

            int index = (h1(key, M) + adjustedStep * i) % M;

            // If slot is empty, place the key
            if (hashTable[index] == -1) {
                hashTable[index] = key;
                placed = 1;
            }

            // Otherwise, try next probe
            i++;
        }

        // If we couldn't place the key (very unlikely here)
        if (!placed) {
            printf("Could not place %d\n", key);
        }
    }
}