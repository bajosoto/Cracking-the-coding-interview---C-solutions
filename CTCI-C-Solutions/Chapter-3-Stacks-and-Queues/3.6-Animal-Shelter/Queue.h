#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

typedef struct Queue{
	LinkedList_t *list;
}Queue_t;

Queue_t *createQueue();

void deleteQueue(Queue_t *queue);

void pushQueue(Queue_t *queue, char data, int timestamp);

Node_t *popQueue(Queue_t *queue);

Node_t *peekQueue(Queue_t *queue);

#endif