#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "HashTable.h"

int main(int argc, char *argv[]){
	Node *head = NULL;
	addNodeFirst(&head, "!");
	addNodeFirst(&head, "World");
	addNodeFirst(&head, "Hello");
 	printList(head);
 	deleteList(head);
 	hashAdd(1, 2);
 	hashAdd(3, 4);
 	hashAdd(37, 9);
 	printf("HashTable value at index %d is: %d\n", 37, hashGet(37));
 	hashAdd(7, 7);
 	printf("HashTable value at index %d is: %d\n", 37, hashGet(37));
 	printf("HashTable value at index %d is: %d\n", 3, hashGet(3));
 	hashClear(3);
 	printf("HashTable value at index %d is: %d\n", 3, hashGet(3));

 	return 0;
}