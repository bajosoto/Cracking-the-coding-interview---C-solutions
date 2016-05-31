#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(LinkedList_t *list) {
    Node_t *run = list->head;
    Node_t *lag = list->head;
    
    if(list->head == NULL)
        return false;
    
    while(run->next != NULL && run->next->next != NULL){
        run = run->next->next;
        lag = lag->next;
        
        if(run == lag)
            return true;
    }
    return false;
}

int main(){
    LinkedList_t *list = createList();
    createNodeAtTail(list, 'a');
    createNodeAtTail(list, 'b');
    createNodeAtTail(list, 'c');
    Node_t *temp = createNodeAtTail(list, 'd');
    createNodeAtTail(list, 'e');
    createNodeAtTail(list, 'f');
    createNodeAtTail(list, 'g');
    printf("Original list: \n");
    printList(list);
    if(hasCycle(list))
        printf("The list has a cycle.\n");
    else
        printf("The list has no cycles\n");
    printf("Linking g -> d\n");
    list->tail->next = temp;
    if(hasCycle(list))
        printf("The list has a cycle.\n");
    else
        printf("The list has no cycles\n");
}