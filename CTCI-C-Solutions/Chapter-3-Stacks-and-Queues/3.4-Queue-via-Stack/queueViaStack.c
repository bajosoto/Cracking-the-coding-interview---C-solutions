#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum command {PUSH, POP, INVALID, EXIT, PRINT} command;

typedef struct myQueue{
 	Stack_t *stackIn;
 	Stack_t *stackOut;
}myQueue_t;

myQueue_t *createMyQueue(){
	myQueue_t *queue = (myQueue_t *)malloc(sizeof(myQueue_t));
	queue->stackIn = createStack();
	queue->stackOut = createStack();
	return queue;
}

void deleteMyQueue(myQueue_t *queue){
 	deleteStack(queue->stackIn);
 	deleteStack(queue->stackOut);
 	free(queue);
}

void pushMyQueue(myQueue_t *queue, char data){
 	if(queue == NULL)
 		return; 	// Report some error
 	push(queue->stackIn, data);
}

char popMyQueue(myQueue_t *queue){
 	 if(queue == NULL)
 		return '\0'; 	// Report some error
 	if(isEmpty(queue->stackOut)){
 		if(!isEmpty(queue->stackIn)){
 			while(!isEmpty(queue->stackIn))
 				push(queue->stackOut, pop(queue->stackIn));
 		}
 		else{
 			printf("myQueue is empty!\n");
 			return '\0';
 		}
 	}
 	return pop(queue->stackOut);
}


command parseCmd(char *cmd){
	command parsedAns;
 	int length = strlen(cmd);
 	if(!strcmp(cmd, "exit"))
 		parsedAns = EXIT;
 	else if(!strcmp(cmd, "push"))
 		parsedAns = PUSH;
 	else if(!strcmp(cmd, "pop"))
 		parsedAns = POP;
 	else if(!strcmp(cmd, "print"))
 		parsedAns = PRINT;
 	else
 		parsedAns = INVALID;

 	return parsedAns;
}

int main(int argc, char *argv[]){
 	command cmd;
 	char buffer[20];
 	char charbuff;
 	myQueue_t *myQueue = createMyQueue();

 	do{
 		printf("> ");
 		scanf("%s", buffer);
 		cmd = parseCmd(buffer);
 		if(cmd == PUSH)
 			scanf(" %c", &charbuff);
 		switch(cmd){
 			case PUSH:
 			 	pushMyQueue(myQueue, charbuff);
 			 	break;
 			case POP:
 			 	printf("%c\n", popMyQueue(myQueue));
 			 	break;
 			case INVALID:
 			 	printf("Invalid command.\n");
 			 	break;
 			case PRINT:
 			 	printf("IN: ");
 			 	printList(myQueue->stackIn->list);
 			 	printf("OUT: ");
 			 	printList(myQueue->stackOut->list);
 			 	break;
 			case EXIT:
 			 	printf("\n");
 			 	break;
 		}
 	}while(cmd != EXIT);

 	deleteMyQueue(myQueue);
	return 0;
}