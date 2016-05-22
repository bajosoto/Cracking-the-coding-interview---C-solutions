# Palindrome

Implement a function to check if a linked list is a palindrome

*8:03*

**Idea 1:**
- Push the first half up to the middle element into a stack
- Pop elements in the stack after the middle, comparing.

**Idea 2:**
- Assuming it was a doubly linked list, have two indexes one at HEAD and one at TAIL
- Have them traverse to the middle while comparing their values. If they reach the middle (odd number of nodes) or go over the other (even number of nodes) without failing a comparison, it is a palindrome.

**Idea 3:** 
- Recursive aproach. Requires knowing the length.
- Each node would check if the interior part of the list is a palindrome, recursing all the way to the middle 1 or 2 nodes.
- Each function call has to return if the interior list was palindrome AND the address of the next to compare
````
[a -> [b -> [c] -> b] -> a]
1      2     3     4     5

[a -> [b -> [c -> c] -> b] -> a]
1      2    3     4     5     6
````

I'll implement idea 3.

````c
#include "LinkedList.h"

typedef struct palindrome{
    Node_t *next;
    int isPalindrome;
}Palindrome_t;

int isPalindrome(LinkedList_t *list){
    int length = getListLength(list);
    int odd = length % 2;

    if(list == NULL)
        return false;

    Palindrome_t res = isPalHelper(list->head, (length + 1) / 2, isOdd);
    return res->isPalindrome;
}

Palindrome_t isPalHelper(Node_t *head, int index, int isOdd){
    Palindrome_t segment;

    // Return true for an empty list
    if(head == NULL || index == 0)
        return true;

    if(index == 1){
        if(isOdd){
            segment.isPalindrome = 1;
            segment.next = head->next;
        }
        else{
            segment.isPalindrome = (head->data == head->next->data) ? 1 : 0;
            segment.next = head->next->next;
        }
    }   
    else{
        segment = isPalHelper(head->next, index - 1, isOdd);
        segment.isPalindrome = segment.isPalindrome && (segment.next->data == head->data);
        segment.next = segment.next->next;  
    }
    return segment;
}
````
*8:44*
