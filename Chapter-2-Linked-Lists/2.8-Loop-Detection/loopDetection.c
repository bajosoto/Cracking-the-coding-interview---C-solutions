#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node_t *findLoop(LinkedList_t *list){
    Node_t *fast = list->head;
    Node_t *slow = list->head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }

    if(fast == NULL || fast->next == NULL)
        return NULL;

    slow = list->head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;    
}

int main(int argc, char *argv[]){

 	LinkedList_t *A = createList();
    LinkedList_t *B = createList();

 	createNodeAtTail(A, 'a');
 	createNodeAtTail(A, 'b');
 	createNodeAtTail(A, 'c');
 	createNodeAtTail(A, 'd');
 	createNodeAtTail(A, 'e');
 	createNodeAtTail(A, 'f');
 	createNodeAtTail(A, 'g');

    printf("List: ");
 	printList(A);

    // Make loop
    A->tail->next = A->head->next->next->next;
    printf("Making 'g' loop into 'd'.\n");

    Node_t *loop = findLoop(A);

    if(loop != NULL)
        printf("The loop happened at: %c\n", loop->data);
    else
        printf("There was no loop.\n");

    // Removing intersection to avoid bugs when deleting list
    A->tail->next = NULL;
 	deleteList(A);

 	return 0;
}