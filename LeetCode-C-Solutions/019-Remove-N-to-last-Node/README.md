# 19. Remove Nth Node From End of List 

Given a linked list, remove the nth node from the end of list and return its head.

````
For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
````

Note:
Given n will always be valid.
Try to do this in one pass.

**My solution:**
- Using a runner technique

````c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *lag = head;
    struct ListNode *run = head;
    struct ListNode *prev = head;
    int i;

    if(head == NULL || n == 0)
        return head;

    if(n == 1 && head->next == NULL){
        head = NULL;
        return head;
    }

    for(i = 0; i < n; i++)
        run = run->next;

    if(run == NULL){
        head = head->next;
        return head;
    }

    while(run != NULL){
        prev = lag;
        lag = lag->next;
        run = run->next;
    }

    prev->next = prev->next->next;

    return head;
}
````