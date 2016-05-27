# Stack of Plates

Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure *SetOfStacks* that mimics this. *SetOfStacks* should be composed of several stacks and should create a new stack once the previous one exceeds capacity. SetOFStacks.push() and *SetOfStacks*.pop() should behave identically to a single stack.

*23:20*

**Idea 1:**
- PlateStack keeps a counter of how many stacks have been created.
- Each Stack has counter of how many items it's holding
- When the last stack is full, create a new one and place the item there.
- When an item is popped and the Stack becomes empty, it is deleted and the counter in PlateStack is decreased.
- I will assume a max number of total Stacks so to put them into an array, but to make it possible to have "unlimited" Stacks, a dynamic array could be used or a linked list where just the TAIL node's Stack is accessed.

````c
#include "Stack.h"

#define MAX_STACKS 20
#define MAX_PLATES 5

typedef struct PlateStack{
    Stack_t *stacks[MAX_STACKS];
    int stackCnt;
}PlateStack_t;

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
        return;     // Report some error
    if(!isFull(pStack->stacks[pStack->stackCnt - 1])){
        push(pStack->stacks[pStack->stackCnt - 1], data);
    }
    else{
        if(pStack->stackCnt >= MAX_PLATES){
            return;     // Report some error. Stack max reached
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
        return '\0';        // Report some error    
    return peek(pStack->stacks[pStack->stackCnt - 1]);
}

char popPlateStack(PlateStack_t *pStack){
    if(pStack == NULL)
        return '\0';        // Report some error
    char data;
    if(!isEmpty(pStack->stacks[pStack->stackCnt - 1]))
        data = pop(pStack->stacks[pStack->stackCnt - 1]);
    if(isEmpty(pStack->stacks[pStack->stackCnt - 1])){
        deleteStack(pStack->stacks[pStack->stackCnt - 1]);
        pStack->stackCnt--;
    }
    return data;
}

````
*11:58*
