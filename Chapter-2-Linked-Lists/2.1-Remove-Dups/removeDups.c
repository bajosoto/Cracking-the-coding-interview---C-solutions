#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(int argc, char *argv[]){
	Node *head = NULL;
	addNodeFirst(&head, "!");
	addNodeFirst(&head, "World");
	addNodeFirst(&head, "Hello");
 	printList(head);
 	deleteList(head);

 	return 0;
}