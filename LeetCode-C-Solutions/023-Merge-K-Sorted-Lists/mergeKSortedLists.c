#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
LinkedList_t *mergeKLists(LinkedList_t **lists, int listsSize) {
    if(listsSize == 0)
        return NULL;
    
    LinkedList_t *list = createList();
    Node_t *dummy = (Node_t *)malloc(sizeof(Node_t));
    dummy->next = lists[0]->head;
    
    Node_t *buff;
    Node_t *index = dummy;
    
    for(int i = 1; i < listsSize; i++){
        buff = lists[i]->head;
        index = dummy;
        while(buff != NULL){
            if(index->next == NULL){
                index->next = buff;
                break;
            }
            else if(index->next->data < buff->data){
                index = index->next;
            }
            else{
                Node_t *temp = index->next;
                index->next = buff;
                buff = buff->next;
                index->next->next = temp;
            }
        }
    }
    list->head = dummy->next;
    return list;
}

int main(int argc, char *argv[]){
    LinkedList_t *list1 = createList();
    LinkedList_t *list2 = createList();
    LinkedList_t *list3 = createList();
    LinkedList_t *list4 = createList();
    createNodeAtTail(list1, 1);
    createNodeAtTail(list1, 3);
    createNodeAtTail(list1, 6);
    createNodeAtTail(list1, 8);
    createNodeAtTail(list2, 2);
    createNodeAtTail(list2, 5);
    createNodeAtTail(list2, 9);
    createNodeAtTail(list3, 4);
    createNodeAtTail(list3, 10);
    createNodeAtTail(list3, 13);
    createNodeAtTail(list3, 14);
    createNodeAtTail(list4, 6);
    createNodeAtTail(list4, 7);

    LinkedList_t **lists = (LinkedList_t **)malloc(sizeof(LinkedList_t *) * 4);
    lists[0] = list1;
    lists[1] = list2;
    lists[2] = list3;
    lists[3] = list4;

    printf("Lists: \n");
    printList(lists[0]);
    printList(lists[1]);
    printList(lists[2]);
    printList(lists[3]);
    printf("\nMerged List:\n");
    printList(mergeKLists(lists, 4));

    return 0;
}