#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum command {PUSH, INVALID, EXIT, PRINT} command;

typedef struct SortedStack{
 	Stack_t *stackSorted;
 	Stack_t *stackBuffer;
}SortedStack_t;

SortedStack_t *createSortedStack(){
	SortedStack_t *sstack = (SortedStack_t *)malloc(sizeof(SortedStack_t));
	sstack->stackSorted = createStack();
	sstack->stackBuffer = createStack();
	return sstack;
}

void deleteSortedStack(SortedStack_t *sstack){
 	deleteStack(sstack->stackSorted);
 	deleteStack(sstack->stackBuffer);
 	free(sstack);
}

void pushSortedStack(SortedStack_t *sstack, char data){
 	if(sstack == NULL)
 		return; 	// Report some error
 	if(!isEmpty(sstack->stackSorted)){
 		while(peek(sstack->stackSorted) < data && !isEmpty(sstack->stackSorted))
 			push(sstack->stackBuffer, pop(sstack->stackSorted));
 	}
 	push(sstack->stackSorted, data);
 	while(!isEmpty(sstack->stackBuffer))
 		push(sstack->stackSorted, pop(sstack->stackBuffer));
}

command parseCmd(char *cmd){
	command parsedAns;
 	int length = strlen(cmd);
 	if(!strcmp(cmd, "exit"))
 		parsedAns = EXIT;
 	else if(!strcmp(cmd, "push"))
 		parsedAns = PUSH;
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
 	SortedStack_t *mySortedStack = createSortedStack();

 	do{
 		printf("> ");
 		scanf("%s", buffer);
 		cmd = parseCmd(buffer);
 		if(cmd == PUSH)
 			scanf(" %c", &charbuff);
 		switch(cmd){
 			case PUSH:
 			 	pushSortedStack(mySortedStack, charbuff);
 			 	break;
 			case INVALID:
 			 	printf("Invalid command.\n");
 			 	break;
 			case PRINT:
 			 	printf("SORTED STACK: ");
 			 	printList(mySortedStack->stackSorted->list);
 			 	break;
 			case EXIT:
 			 	printf("\n");
 			 	break;
 		}
 	}while(cmd != EXIT);

 	deleteSortedStack(mySortedStack);
	return 0;
}