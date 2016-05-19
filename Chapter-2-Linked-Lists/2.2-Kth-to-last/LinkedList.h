typedef struct Node{
	char *data;
	struct Node *next;
}Node_t;


typedef struct LinkedList{
	Node_t *head;
	Node_t *tail;
}LinkedList_t;

LinkedList_t *createList();

Node_t *createNodeAtHead(LinkedList_t *list, char *data);

Node_t *createNodeAtTail(LinkedList_t *list, char *data);

Node_t *kthToLast(LinkedList_t *list, int k);

void printList(LinkedList_t *list);