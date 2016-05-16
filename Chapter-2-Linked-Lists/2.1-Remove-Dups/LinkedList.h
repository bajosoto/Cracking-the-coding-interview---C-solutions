#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
 	char *data;
 	struct Node *next;
}Node;

void addNodeFirst(Node **head, char *data);
void destroyNode(Node *node);
void printList(Node *head);
void deleteList(Node *head);

#endif