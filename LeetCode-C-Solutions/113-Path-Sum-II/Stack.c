#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack_t *createStack(){
	Stack_t *stack = (Stack_t *)malloc(sizeof(Stack_t));
	stack->count = 0;
	stack->list = createList();
	return stack;
}

int deleteStack(Stack_t *stack){
	if(stack == NULL)
		return -1;
	deleteList(stack->list);
	free(stack);
 	return 0;
}

int isEmpty(Stack_t *stack){
	if(stack == NULL)
		return -1;
 	return !(stack->count); 
}

int push(Stack_t *stack, int data){
	if(stack == NULL)
		return -1;
	createNodeAtTail(stack->list, data);
	stack->count++;
	return 0;
}

int peek(Stack_t *stack){
	if(stack == NULL || isEmpty(stack))
		return '\0';
	return stack->list->tail->data;
}

int pop(Stack_t *stack){
	if(stack == NULL || isEmpty(stack)){
		printf("Stack is empty!\n");
		return '\0';
	}
	char res = stack->list->tail->data;

	// If there was only one element left
	if(stack->count == 1){
		free(stack->list->head);
		stack->list->head = NULL;
		stack->list->tail = NULL;
	}
	else{
		// Singly Linked List, so we have to iterate to second-last element...
		Node_t *newTail = stack->list->head;
		while(newTail->next != stack->list->tail){
 			newTail = newTail->next;
		}
 		free(newTail->next);
 		newTail->next = NULL;
 		stack->list->tail = newTail;
	}
	stack->count--;
	return res;
}