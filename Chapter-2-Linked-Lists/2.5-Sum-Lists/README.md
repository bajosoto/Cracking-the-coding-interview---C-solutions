# Sum Lists

You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in *reverse* order, such that the 1-s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

````
Ex. 
Input:  7 -> 1 -> 6  +  5 -> 9 -> 2    (which is 617 + 295)
Output: 2 -> 1 -> 9                    (which is 912)
````

*14:54*

**Solution:** time: O(n) space: O(1) (not counting the output space of course...)
- Add first 2 integers and save a carry
- Repeat (either recursively or iteratively). I'll implement the iterative.
````c
LinkedList_t *sumLists(LinkedList_t *lA, LinkedList_t *lB){
    int carry = 0;
    Node_t *nA = lA->head;
    Node_t *nB = lB->head;
    LinkedList_t *lR = createList();

    int result;

    while(nA != NULL || nB != NULL || carry != 0){
        result = 0;
        if(nA != NULL) result += nA->data;
        if(nB != NULL) result += nB->data;
        result += carry;
        carry = result / 10;
        result = result % 10;

        createNodeAtTail(lR, result);

        nA = (nA == NULL) ? NULL : nA->next;
        nB = (nB == NULL) ? NULL : nB->next;
    }
    return lR;
}
````
*15:07*

## Follow up

Supose digits are stored in forward order. Repeat the above problem.

**Solution:**
- Similar to above, but doing an initial run on both lists to calculate lengths and pad with zeros the shorter one. 
- Since the carry will be carried backwards, recursive approach is more *"elegant"*
- I won't implement this one right now.