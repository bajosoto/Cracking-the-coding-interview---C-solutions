#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node_t* removeNthFromEnd(Node_t* head, int n) {
    Node_t *lag = head;
    Node_t *run = head;
    Node_t *prev = head;
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

int main(){
    LinkedList_t *list = createList();
    createNodeAtTail(list, 'a');
    createNodeAtTail(list, 'b');
    createNodeAtTail(list, 'c');
    createNodeAtTail(list, 'd');
    createNodeAtTail(list, 'e');
    createNodeAtTail(list, 'f');
    createNodeAtTail(list, 'g');
    createNodeAtTail(list, 'h');
    printf("Original: ");
    printList(list);
    printf("Removing 3rd to last: ");
    removeNthFromEnd(list->head, 3);
    printList(list);
    return 0;
}