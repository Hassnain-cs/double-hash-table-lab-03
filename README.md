# Double Hash Table Implementation

## Overview
This project implements a hash table using double hashing for collision resolution. The implementation follows specific hash functions as required by the lab assignment.

## Hash Functions Used
- Primary hash: `h1(k) = k mod M`
- Secondary hash: `h2(k) = R - (k mod R)`
- Double hash: `h(k) = (h1(k) + h2(k) * i) mod M`

## Files Structure
- `hash.h` - Header file with function declarations
- `hash.c` - Implementation of hash table functions
- `main.c` - Driver program to test the implementation

## Compilation
```bash
gcc -o hash_program main.c hash.c
