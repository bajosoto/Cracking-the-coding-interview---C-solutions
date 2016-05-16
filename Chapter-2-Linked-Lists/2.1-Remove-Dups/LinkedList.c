#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void addNodeFirst(Node **head, char *data){
 	Node *this = (Node *)malloc(sizeof(Node));
 	this->data = data;
 	this->next = *head;
 	*head = this;
}

void destroyNode(Node *node){
 	free(node);
}

void deleteList(Node *head){
	Node *temp;
 	while(head != NULL){
 		temp = head->next;
 		destroyNode(head);
 		head = temp;
 	}
}

void printList(Node *head){
 	Node *index = head;
 	while(index != NULL){
 		printf("%s ", index->data);
 		index = index->next;
 	}
 	printf("\n");
}