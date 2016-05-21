# Partition

Write code to partition a linked list around a value c, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x. The partition element x can appear anywhere in the "right partition". It does not need to appear between the left and right partitions.

````
Ex.
Input:  3 - 5 - 8 - 5 - 10 - 2 - 1  [partition = 5]
Output: 3 - 1 - 2 - 10 - 5 - 5 - 8
````

*10:49*

**Idea 1:** time: O(n) + O(n) = O(n), space: O(1)
- Traverse the list, and for each element:
    - If it is smaller than the partition, send it to HEAD
    - If it is smaller, send it to TAIL
- This would require knowing the length of the list to avoid going through the nodes sent to tail again.
- This implementation is not stable (it will not hold the original order of items)

**Idea 2:** time: O(n), space: O(1)
- Traverse the list, and for each element:
    - If smaller than the partition value, send it to a linked list holding the smaller ones
    - If larger, send it to another one holding the bigger or equal ones
- Merge both linked lists.
- This implementation is stable

````c
#include "LinkedList.h"
#include <stdlib.h>

void partitionList(LinkedList_t *list, int k){
    LinkedList_t *smaller = createList();
    LinkedList_t *larger = createList();
    Node_t *node, nextNode;

    if(list == NULL)
        return NULL;
    
    // Separate into two lists
    node = list->head;
    while(node != NULL){
        nextNode = node->next;
        if(node->data < k){
            if(smaller->tail == NULL)
                smaller->tail = node;
            node->next = smaller->head;
            smaller->head = node;
        }
        else{
            if(larger->tail == NULL)
                larger->tail = node;
            node->next = larger->head;
            larger->head = node;
        }
        node = nextNode;
    }
    
    // Merge back into one
    smaller->tail->next = larger->head;
    list->head = smaller->head;
    list->tail = larger->tail;

    return;
}
````

*11:13*
