#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/* Reusing test code from last exercise so I can have a pointer to a given node. Could have implemented a find function for this too */
int main(int argc, char *argv[]){
 	if(argc != 2){
 		printf("Please input a number k... \n");
 		return -1;
 	}

 	LinkedList_t *list = createList();
 	int k = atoi(argv[1]);
 	Node_t *kthNode;

 	createNodeAtHead(list, "Dog");
 	createNodeAtHead(list, "Cat");
 	createNodeAtHead(list, "Mouse");
 	createNodeAtHead(list, "Zebra");
  	createNodeAtTail(list, "Elephant");
 	createNodeAtHead(list, "Gnu");
 	createNodeAtHead(list, "Donkey");
 	createNodeAtHead(list, "Horse");
 	createNodeAtHead(list, "Duck");
 	createNodeAtHead(list, "Giraffe");
 	printList(list);
 	
 	kthNode = kthToLast(list, k);
 	
 	if(kthNode != NULL)
 		printf("Node %d positions away from the last is: %s. It will now be deleted.\n", k, kthNode->data);
 	else
 		printf("There is no node %d positions away from the last.\n", k);
 	if(k != 0)
 		deleteMidNode(list, kthNode);
 	else
 		printf("...or not. This function deletes MIDDLE nodes, although it works for the first node too. :p\n");
 	printList(list);

 	return 0;
}