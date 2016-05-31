# 141. Linked List Cycle  

Difficulty: Easy

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

**My solution:**
- In order to not use extra space(i.e. a *visited* field in the nodes, or a Hash Table), I used the runner technique.
- The runner index runs twice as fast as the lagging index. 
    + If they is a cycle, they will meet.
    + If there was no cycle, the runner index will reach a null or a node before a null.

````c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *run = head;
    struct ListNode *lag = head;
    
    if(head == NULL)
        return false;
    
    while(run->next != NULL && run->next->next != NULL){
        run = run->next->next;
        lag = lag->next;
        
        if(run == lag)
            return true;
    }
    return false;
}
````

Sample output:
````
Original list:
a -> b -> c -> d -> e -> f -> g
The list has no cycles
Linking g -> d
The list has a cycle.
````
