#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node_t *findIntersection(LinkedList_t *list1, LinkedList_t *list2){
    if(list1 == NULL || list2 == NULL || list1->head == NULL || list2->head == NULL )
        return NULL;

    int length1 = 1;
    int length2 = 1;
    int lengthdif;
    Node_t *node1 = list1->head;
    Node_t *node2 = list2->head;

    while(node1->next != NULL){
        length1++;
        node1 = node1->next;
    }
    while(node2->next != NULL){
        length2++;
        node2 = node2->next;
    }

    // If they didn't intersect
    if(node1 != node2)
        return NULL;

    lengthdif = abs(length1 - length2);
    Node_t *shorter = (length1 < length2) ? list1->head : list2->head;
    Node_t *longer = (length1 < length2) ? list2->head : list1->head;

    int i;
    for(i = 0; i < lengthdif; i++)
        longer = longer->next; 

    while(longer != shorter){
        longer = longer->next;
        shorter = shorter->next;
    }

    return longer;
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
    //createNodeAtTail(B, 'A');
    createNodeAtTail(B, 'B');
    createNodeAtTail(B, 'C');

    printf("List A: ");
 	printList(A);
    printf("List B: ");
    printList(B);

    // Intersecting nodes
    B->tail->next = A->head->next->next->next;
    printf("Lists after intersecting B into A:\n");
    printf("List A: ");
    printList(A);
    printf("List B: ");
    printList(B);

    Node_t *intersection = findIntersection(A, B);

    if(intersection != NULL)
        printf("The intersection happened at: %c\n", intersection->data);
    else
        printf("The lists don't intersect.\n");

    // Removing intersection to avoid bugs when deleting list
    B->tail->next = NULL;

 	deleteList(A);
    deleteList(B);

 	return 0;
}