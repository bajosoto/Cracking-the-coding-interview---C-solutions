#include "LinkedList.h"

typedef struct Stack{
 	LinkedList_t *list;
 	int count; 
}Stack_t;

Stack_t *createStack();

int deleteStack(Stack_t *stack);

int isEmpty(Stack_t *stack);

int push(Stack_t *stack, int data);

int peek(Stack_t *stack);

int pop(Stack_t *stack);