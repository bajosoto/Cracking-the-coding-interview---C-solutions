#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum command {PUSH, PEEK, POP, MIN, INVALID, EXIT, PRINT} command;

command parseCmd(char *cmd){
	command parsedAns;
 	int length = strlen(cmd);
 	if(!strcmp(cmd, "exit"))
 		parsedAns = EXIT;
 	else if(!strcmp(cmd, "push"))
 		parsedAns = PUSH;
 	else if(!strcmp(cmd, "pop"))
 		parsedAns = POP;
 	else if(!strcmp(cmd, "peek"))
 		parsedAns = PEEK;
 	else if(!strcmp(cmd, "print"))
 		parsedAns = PRINT;
 	else if(!strcmp(cmd, "min"))
 		parsedAns = MIN;
 	else
 		parsedAns = INVALID;

 	return parsedAns;
}

typedef struct MinStack{
    Stack_t *stack;
    Stack_t *minstack;
}MinStack_t;

MinStack_t *createMinStack(){
    MinStack_t *myMinStack = (MinStack_t *)malloc(sizeof(MinStack_t));
    myMinStack->stack = createStack();
    myMinStack->minstack = createStack();
    return myMinStack;
}

void deleteMinStack(MinStack_t *minst){
	deleteStack(minst->stack);
	deleteStack(minst->minstack);
	free(minst);
}

void pushMin(MinStack_t *minst, char data){
 	push(minst->stack, data);
 	if(isEmpty(minst->minstack))
 		push(minst->minstack, data);
 	else if(data <= peek(minst->minstack))
 		push(minst->minstack, data);
}

 char popMin(MinStack_t *minst){
 	char out = pop(minst->stack);
 	if(out == peek(minst->minstack))
 		pop(minst->minstack);
 	return out;
 }

char minMin(MinStack_t *minst){
	return peek(minst->minstack);
}

char peekMin(MinStack_t *minst){
	return peek(minst->stack);
}

int main(int argc, char *argv[]){
 	command cmd;
 	char buffer[20];
 	char charbuff;
 	MinStack_t *myMinStack = createMinStack();

 	do{
 		printf("> ");
 		scanf("%s", buffer);
 		cmd = parseCmd(buffer);
 		if(cmd == PUSH)
 			scanf(" %c", &charbuff);
 		switch(cmd){
 			case PUSH:
 			 	pushMin(myMinStack, charbuff);
 			 	break;
 			case POP:
 			 	printf("%c\n", popMin(myMinStack));
 			 	break;
 			case PEEK:
 			 	printf("%c\n", peekMin(myMinStack));
 			 	break;
 			case MIN:
 			 	printf("%c\n", minMin(myMinStack));
 			 	break;
 			case INVALID:
 			 	printf("Invalid command.\n");
 			 	break;
 			case PRINT:
 			 	printList(myMinStack->stack->list);
 			 	printList(myMinStack->minstack->list);
 			 	break;
 			case EXIT:
 			 	printf("\n");
 			 	break;
 		}
 	}while(cmd != EXIT);

 	deleteMinStack(myMinStack);
	return 0;
}