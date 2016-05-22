# Intersection

Given two singly linked lists, determine if they intersect. Return the intersecting node. The intersection is defined based on *reference*, not value.

*11:27*

**Procedure 1:** time: O(n) space: O(1)
- Traverse both lists, calculating their lengths while checking if they end up in the same node. If they don't, they don't intersect.
    - NOTE: With the current LinkedList.h implementation, just checking if the **TAIL** of both lists are equal would have been enough to see if they intersect and their lengths could have been calculated by using **listLength()**, but for practice matters I'll do both manually.
- If they do, "even out" the lengths of them by having an index on each and running the one in the longer one (length2 - length1) nodes, then running them simultaneously.
- The first node they reach being equal will be the intersecting node.

````c
Node_t *findIntersection(LinkedList_t *list1, LinkedList_t *list2){
    if(list1 == NULL || list2 == NULL || list1->head == NULL || list2->head == NULL )
        return NULL;

    int length1 = 1;
    int length2 = 1;
    int lengthdif;
    Node_t *node1 = list1->head;
    Node_t *node2 = list2->head;

    while(node1->next != NULL){
        length1++;
        node1 = node1->next;
    }
    while(node2->next != NULL){
        length2++;
        node2 = node2->next;
    }

    // If they didn't intersect
    if(node1 != node2)
        return NULL;

    lengthdif = abs(length1 - length2);
    Node_t *shorter = (length1 < length2) ? list1->head : list2->head;
    Node_t *longer = (length1 < length2) ? list2->head : list1->head;

    int i = 0;
    for(i = 0; i < lengthdif; i++)
        longer = longer->next; 

    while(longer != shorter){
        longer = longer->next;
        shorter = shorter->next;
    }

    return longer;
}
````
*11:50*
