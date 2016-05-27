# Loop Detection

Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

````
Ex.
Input:   A -> B -> C -> D -> E -> C
Output:  C
````

*11:47*

**Extra field in node:** time: O(n), space: O(n)
- Have nodes keep a new element, "visited" that is switched after an index traversing the nodes visits it.
- If the index reaches a node which had been visited already, that will be the loop beginning.

**Runner approach:** time: O(n), space: O(1)
- Have two node indexes, fast and slow runner, traverse the linked list. Runner moves two nodes at a time, slow runs one at a time.
- By the time slow has reached the beginning of the node (after moving k nodes), fast will k nodes ahead of slow, 2k nodes ahead of the HEAD, and k nodes into the loop.
- At this point, fast will be LOOP_LENGTH - k nodes behind slow, and since they  get closer 1 node at a time, they will collide LOOP_LENGTH - k nodes ahead from this point.
- At this new "collision" point, slow and fast will be LOOP_LENGTH - (LOOP_LENGTH - k) = k nodes away from the beginning of the loop.
- If fast is moved to the HEAD and now both indexes run at the same speed (1 node), they will eventually collide, after advancing k nodes, at the beginning of the loop.
- Return this new collision node.

````c
Node_t *findLoop(LinkedList_t *list){
    Node_t *fast = list->head;
    Node_t *slow = list->head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }

    if(fast == NULL || fast->next == NULL)
        return NULL;

    slow = list->head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;    
}
````

*12:15*
