#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
 	char *data;
 	int key;
 	struct Node *next;
}Node;

void addNodeFirst(Node **head, char *data, int key);
Node *deleteNode(Node *node, Node *head);
void printList(Node *head);
void deleteList(Node **head);

#endif