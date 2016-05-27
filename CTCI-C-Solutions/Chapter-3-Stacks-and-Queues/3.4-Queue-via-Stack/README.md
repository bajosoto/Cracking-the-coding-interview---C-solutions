# Queue via Stack

Implement a *MyQueue* class which implements a queue using two stacks.
*7:14*  

**Idea 1:**
- Two stacks, S1 and S2
- Whenever an item is pushed, it goes to S1.
- Whenever an item is popped, if S2 is empty, all items from S1 are popped and pushed to S2, then the top of S2 is returned
- If S2 is not empty, just pop the element at the top and return it.

````c
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
        return;     // Report some error
    push(queue->stackIn, data);
}

char popMyQueue(myQueue_t *queue){
     if(queue == NULL)
        return '\0';    // Report some error
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
````
*7:26*