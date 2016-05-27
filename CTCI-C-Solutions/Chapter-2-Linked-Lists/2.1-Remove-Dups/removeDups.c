#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "HashTable.h"

void removeDups(Node *head){
 	if(head == NULL)
 		return;
 	Node *index = head;
 	while(index != NULL){
 		if(hashGet(index->key) == NULL){
 			hashAdd(index->key, index->data);
 			index = index->next;
 		} 
		else{
 			index = deleteNode(index, head);
 	 	}
 	}
}

int main(int argc, char *argv[]){
	Node *listHead = NULL;
	addNodeFirst(&listHead, "Dog",  1);
	addNodeFirst(&listHead, "Cat",  2);
	addNodeFirst(&listHead, "Moose",3);
	addNodeFirst(&listHead, "Duck", 4);
	addNodeFirst(&listHead, "Dog",  1);
	addNodeFirst(&listHead, "Bird", 6);
	addNodeFirst(&listHead, "Frog", 7);
	addNodeFirst(&listHead, "Cat",  2);
	addNodeFirst(&listHead, "Dog",  1);
 	printList(listHead);
 	printf("Removing duplicates...\n");
 	removeDups(listHead);
 	printList(listHead);
 	deleteList(&listHead);

 	return 0;
}