#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]){

 	LinkedList_t *A = createList();
 	LinkedList_t *B = createList();
 	LinkedList_t *R;

 	createNodeAtTail(A, 7);
 	createNodeAtTail(A, 1);
 	createNodeAtTail(A, 6);
 	createNodeAtTail(B, 5);
  	createNodeAtTail(B, 9);
 	createNodeAtTail(B, 8);
 	printf("\t");
 	printList(A);
 	printf("+\t");
 	printList(B);
 	printf("=\t");
 	R = sumLists(A, B);
 	printList(R);

 	return 0;
}