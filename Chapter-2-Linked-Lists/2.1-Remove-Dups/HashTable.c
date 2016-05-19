/* A very basic hash table implementation with no collision control*/

#include "HashTable.h"

#define MAX_KEYS	30

static int hashTable[MAX_KEYS];

int hashGet(int key){
 	return hashTable[key % MAX_KEYS];
}

void hashAdd(int key, int value){
 	hashTable[key % MAX_KEYS] = value;
}

void hashClear(int key){
 	hashTable[key % MAX_KEYS] = 0;
}

