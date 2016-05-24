#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum command {PUSH, PEEK, POP, INVALID, EXIT, PRINT} command;

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
 	Stack_t *stack = createStack();

 	do{
 		printf("> ");
 		scanf("%s", buffer);
 		cmd = parseCmd(buffer);
 		if(cmd == PUSH)
 			scanf(" %c", &charbuff);
 		switch(cmd){
 			case PUSH:
 			 	push(stack, charbuff);
 			 	break;
 			case POP:
 			 	printf("%c\n", pop(stack));
 			 	break;
 			case PEEK:
 			 	printf("%c\n", peek(stack));
 			 	break;
 			case INVALID:
 			 	printf("Invalid command.\n");
 			 	break;
 			case PRINT:
 			 	printList(stack->list);
 			 	break;
 			case EXIT:
 			 	printf("\n");
 			 	break;
 		}
 	}while(cmd != EXIT);

 	deleteStack(stack);
	return 0;
}