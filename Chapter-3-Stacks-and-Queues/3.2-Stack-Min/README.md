# Stack Min

Design a stack in which in addition to push and pop, there is a function min which returns the minimum element. All 3 functions should operate in O(1) time.

*4:01*
**Idea 1:** time: O(1), space: O(n)
- Each element added stores additionally the value of the min under the stack.

**Idea 2:** time: O(1), space: O(n) -> but less space than idea 1.
- Keep a second stack which holds the minimums. 
- Whenever an item is added to the stack, check if peek(stackmin) is smaller or equal to the one being pushed.
    + If it is, add this value to the min stack.
- min() returns peek(stackmin)

````c
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
````
*4:29*
