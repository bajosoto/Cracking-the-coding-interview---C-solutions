# Sort Stack

Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.

*7:39*  

**Idea 1:** time: O(n), space: O(n)
- Two stacks, S1 and S2
- when an item is going to be inserted, recursively do the following:
    + if item on top of S1 is larger, push data into this stack.
    + if item on top is smaller, pop it from S1 and push into S2
    + After being pushed, pop all items one by one from S2 and push into S1, on top of the newly inserted item

````c
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
        return;     // Report some error
    if(!isEmpty(sstack->stackSorted)){
        while(peek(sstack->stackSorted) < data && !isEmpty(sstack->stackSorted))
            push(sstack->stackBuffer, pop(sstack->stackSorted));
    }
    push(sstack->stackSorted, data);
    while(!isEmpty(sstack->stackBuffer))
        push(sstack->stackSorted, pop(sstack->stackBuffer));
}
````
*7:48* 

**EDIT:** My bad. I misunderstood the question and implemented a stack that is always sorted. The implementation of a sort(Stack s) algorithm is very similar. In fact, it can be something like this:

````c
void sortStack(Stack_t stack){
    Stack_t buffer = createStack();
    char data;
    while(!isEmpty(stack)){
        data = pop(stack);
        // From here it's the same as the avobe implementation
        if(!isEmpty(buffer)){
            while(peek(buffer) > data && !isEmpty(buffer))
                push(stack, pop(buffer));
        }
        push(buffer, data);
    }
    
    // Reverse items by moving them from buffer to stack
    while(!isEmpty(buffer))
        push(stack, pop(buffer));       
}
````

I did not have time to test this implementation, but it seems like it would work.  
Time complexity: O(n<sup>2</sup>)  
Space complexity: O(n)  