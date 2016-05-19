#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void addNodeFirst(Node **head, char *data, int key){
 	Node *this = (Node *)malloc(sizeof(Node));
 	this->data = data;
 	this->next = *head;
 	this->key = key;
 	*head = this;
}

Node *deleteNode(Node *node, Node *head){
	if(node->next != NULL){
	 	node->data = node->next->data;
 		node->key = node->next->key;
 		Node *temp = node->next->next;
 		free(node->next);
 		node->next = temp;
 		return node;
 	}else{
 		Node *temp = head;
 		while(temp->next->next != NULL)
 			temp = temp->next;
 		free(node);
 		temp->next = NULL;
 		return NULL;
 	}
}

void deleteList(Node **head){
	Node *temp;
 	while(*head != NULL){
 		temp = (*head)->next;
 		free(*head);
 		*head = temp;
 	}
 	*head = NULL;
}

void printList(Node *head){
 	Node *index = head;
 	while(index != NULL){
 		printf("%s -> ", index->data);
 		index = index->next;
 	}
 	printf("\n");
}