/* A very basic hash table implementation with no collision control*/
#include <stdlib.h>
#include <stdio.h>
#include "HashTable.h"

#define MAX_KEYS	30

static char *hashTable[MAX_KEYS] = {NULL};

char *hashGet(int key){
 	return hashTable[key % MAX_KEYS];
}

void hashAdd(int key, char *value){
 	hashTable[key % MAX_KEYS] = value;
}

void hashClear(int key){
 	hashTable[key % MAX_KEYS] = 0;
}

