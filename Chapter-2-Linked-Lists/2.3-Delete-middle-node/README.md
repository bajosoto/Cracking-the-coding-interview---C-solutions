# Delete Middle Node

Implement an algorithm to delete a node in the middle (any node but first or last) of a singly linked list, given only access to that node.

*14:35*

**Idea 1:** 
- Copy into the node to be deleted the contents of the next node (including its node->next)
- Delete the node to be deleted's ->next node.

````c
Node_t deleteMidNode(LinkedList_t *list, Node_t *nodeToDel){
    nodeToDel->data = nodeToDel->next->data;
    Node_t *temp = nodeToDel->next->next;
    free(nodeToDel->next);
    nodeToDel->next = temp;
    return nodeToDel;
}
````
*14:40*
