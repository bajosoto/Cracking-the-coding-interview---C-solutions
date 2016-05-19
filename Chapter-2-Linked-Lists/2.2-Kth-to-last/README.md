# Return K<sup>th</sup> to last

Implement an algorithm to return the K<sup>th</sup> to last element of a singly linked list.

*14:24*

**Brute Force:** Time O(n) space: O(1)
- Traverse list to calculate length
- Traverse lenght - k on second run

**Runner approach:** time: O(n) space: O(1)
- Start 2 indexes at root
- Traverse runner k positions
- Traverse runner and lagger indexes until runner hits NULL
- Returh the lagger index

````c
Node_t *kthToLast(LinkedList_t *list, int k){
    Node_t *lagger = list->head;
    Node_t *runner = list->head;
    int i;

    for(i = 0; i < k; i++){
        if(runner->next == NULL)
            return NULL;
        runner = runner->next;
    }
    while(runner->next != NULL){
        lagger = lagger->next;
        runner = runner->next;
    }
    return lagger;
}
````
*14:32*
