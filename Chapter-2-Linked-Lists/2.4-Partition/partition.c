#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void partitionList(LinkedList_t *list, int k){
    LinkedList_t *smaller = createList();
    LinkedList_t *larger = createList();
    Node_t *node, *nextNode;

    if(list == NULL)
        return;
    
    // Separate into two lists
    node = list->head;
    while(node != NULL){
        nextNode = node->next;
        if(node->data < k){
            if(smaller->tail == NULL)
                smaller->tail = node;
            node->next = smaller->head;
            smaller->head = node;
        }
        else{
            if(larger->tail == NULL)
                larger->tail = node;
            node->next = larger->head;
            larger->head = node;
        }
        node = nextNode;
    }
    
    // Merge back into one
    smaller->tail->next = larger->head;
    list->head = smaller->head;
    list->tail = larger->tail;

    free(smaller);
    free(larger);

    return;
}

int main(int argc, char *argv[]){

 	if(argc < 2) 
 		return -1;

 	int k = atoi(argv[1]);
 	LinkedList_t *A = createList();

 	createNodeAtTail(A, 3);
 	createNodeAtTail(A, 5);
 	createNodeAtTail(A, 8);
 	createNodeAtTail(A, 5);
 	createNodeAtTail(A, 10);
 	createNodeAtTail(A, 2);
 	createNodeAtTail(A, 1);

 	printList(A);
 	partitionList(A, k);
 	printList(A);

 	// Missing a deleteList() to free memory in nodes
 	free(A);

 	return 0;
}