#include "LinkedList.h"
#include "Queue.h"
#include <stdlib.h>

Queue_t *createQueue(){
	Queue_t *queue = (Queue_t *)malloc(sizeof(Queue_t));
	queue->list = createList();
	return queue;
}

void deleteQueue(Queue_t *queue){
 	deleteList(queue->list);
 	free(queue);
}

void pushQueue(Queue_t *queue, char data, int timestamp){
	if(queue == NULL)
		return; 		// Report some error
	createNodeAtTail(queue->list, data, timestamp);
}

int isEmptyQueue(Queue_t *queue){
	if(queue == NULL)
		return -1;
	return queue->list->head == NULL ? 1 : 0;
}

Node_t *popQueue(Queue_t *queue){
	if(queue == NULL || isEmptyQueue(queue))
		return NULL;	// Report some error
	Node_t *out = queue->list->head;
 	Node_t *prevHead = queue->list->head;
 	queue->list->head = queue->list->head->next;
 	free(prevHead);
 	return out;
}

Node_t *peekQueue(Queue_t *queue){
	if(queue == NULL || isEmptyQueue(queue))
		return NULL;	// Report some error
	return queue->list->head;
}




