#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum command {PUSH, PEEK, POP, INVALID, EXIT, PRINT} command;

#define MAX_STACKS 20
#define MAX_PLATES 5

typedef struct PlateStack{
 	Stack_t *stacks[MAX_STACKS];
 	int stackCnt;
}PlateStack_t;

// This function is not implemented in Stack.h since stacks are handled by Linked lists that "can't be full"
int isFull(Stack_t *stack){
	int cnt = 0;
	Node_t *node = stack->list->head;
	while(node != NULL){
		cnt++;
		node = node->next;
	}
	return cnt >= MAX_PLATES ? 1 : 0; 
}

PlateStack_t *createPlateStack(){
 	PlateStack_t *pStack = (PlateStack_t *)malloc(sizeof(PlateStack_t));
 	pStack->stacks[0] = createStack();
 	pStack->stackCnt = 1;
 	return pStack;
}

void deletePlateStack(PlateStack_t *pStack){
	for(int i = 0; i < pStack->stackCnt; i++){
		deleteStack(pStack->stacks[i]);
	}
	free(pStack);
}

void pushPlateStack(PlateStack_t *pStack, char data){
 	if(pStack == NULL)
 		return;	 	// Report some error
 	if(!isFull(pStack->stacks[pStack->stackCnt - 1])){
 		push(pStack->stacks[pStack->stackCnt - 1], data);
 	}
 	else{
 		if(pStack->stackCnt >= MAX_PLATES){
 			return; 	// Report some error. Stack max reached
 		}
 		else{
 			pStack->stackCnt++;
 			pStack->stacks[pStack->stackCnt - 1] = createStack();
 			push(pStack->stacks[pStack->stackCnt - 1], data);
 		}
 	}
}

char peekPlateStack(PlateStack_t *pStack){
 	if(pStack == NULL)
 		return '\0';	 	// Report some error 	
 	return peek(pStack->stacks[pStack->stackCnt - 1]);
}

char popPlateStack(PlateStack_t *pStack){
 	if(pStack == NULL)
 		return '\0';	 	// Report some error
 	char data;
 	if(!isEmpty(pStack->stacks[pStack->stackCnt - 1]))
 		data = pop(pStack->stacks[pStack->stackCnt - 1]);
 	if(isEmpty(pStack->stacks[pStack->stackCnt - 1])){
 		deleteStack(pStack->stacks[pStack->stackCnt - 1]);
 		pStack->stackCnt--;
 	}
 	return data;
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
 	else if(!strcmp(cmd, "peek"))
 		parsedAns = PEEK;
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
 	PlateStack_t *myPlateStack = createPlateStack();

 	do{
 		printf("> ");
 		scanf("%s", buffer);
 		cmd = parseCmd(buffer);
 		if(cmd == PUSH)
 			scanf(" %c", &charbuff);
 		switch(cmd){
 			case PUSH:
 			 	pushPlateStack(myPlateStack, charbuff);
 			 	break;
 			case POP:
 			 	printf("%c\n", popPlateStack(myPlateStack));
 			 	break;
 			case PEEK:
 			 	printf("%c\n", peekPlateStack(myPlateStack));
 			 	break;
 			case INVALID:
 			 	printf("Invalid command.\n");
 			 	break;
 			case PRINT:
 			 	for(int i = 0; i < myPlateStack->stackCnt; i++)
 			 	 	printList(myPlateStack->stacks[i]->list);
 			 	break;
 			case EXIT:
 			 	printf("\n");
 			 	break;
 		}
 	}while(cmd != EXIT);

 	deletePlateStack(myPlateStack);
	return 0;
}