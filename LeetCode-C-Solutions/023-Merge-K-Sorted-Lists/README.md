# 23. Merge k Sorted 

Difficulty: Hard

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

**My Solution:**
- Add the first list to the final list
- Create 2 indexes. 
    - One keeps track of the list currently being added to (or the remainder of elements to be added from it)
    - The other keeps track of where the elements are currently being inserted. Since the lists are sorted, this element doesn't have to backtrack all the way to the beginning for each new node to be inserted, since it can't be smaller than the previous one. (it is backtracked however at the beginning of the insertion of a new list once the previos one was finished with)
- Gotchas:
    + A temporary node element is necessary to keep track of the rest of the list during a middle insertion. Otherwise, the rest of the list is lost.
    + When the pointer *index* is pointing at the last element of the list, the next list (or whatever is in *buff* can be inserted entirely).

Code I submitted at LeetCode (the one in the files use my own LinkedList.h):
````c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0)
        return NULL;
    
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = lists[0];
    
    struct ListNode *buff;
    struct ListNode *index = head;
    
    for(int i = 1; i < listsSize; i++){
        buff = lists[i];
        index = head;
        while(buff != NULL){
            if(index->next == NULL){
                index->next = buff;
                break;
            }
            else if(index->next->val < buff->val){
                index = index->next;
            }
            else{
                struct ListNode *temp = index->next;
                index->next = buff;
                buff = buff->next;
                index->next->next = temp;
            }
        }
    }
    return head->next;
}
````


Sample output:

````
Sergio$ ./mergeKSortedLists 
Lists: 
1  -> 3  -> 6  -> 8 
2  -> 5  -> 9 
4  -> 10  -> 13  -> 14 
6  -> 7 

Merged List:
1  -> 2  -> 3  -> 4  -> 5  -> 6  -> 6  -> 7  -> 8  -> 9  -> 10  -> 13  -> 14 
````