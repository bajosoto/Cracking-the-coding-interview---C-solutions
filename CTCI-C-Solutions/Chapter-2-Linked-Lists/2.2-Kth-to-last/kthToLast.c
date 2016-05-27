#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>


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
 		printf("Node %d positions away from the last is: %s\n", k, kthNode->data);
 	else
 		printf("There is no node %d positions away from the last.\n", k);
 	return 0;
}