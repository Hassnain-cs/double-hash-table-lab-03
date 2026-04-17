#pragma once
#ifndef HASH_H
#define HASH_H

/*
 * This function is responsible for creating and filling a hash table.
 * We are using double hashing to handle collisions.
 *
 * hashTable, the array where final hashed values will be stored
 * input,array of values we want to insert
 * M, size of the table (and number of elements)
 * R, used in second hash function (step size)
 */
void hashInit(int* hashTable, int* input, int M, int R);

#endif