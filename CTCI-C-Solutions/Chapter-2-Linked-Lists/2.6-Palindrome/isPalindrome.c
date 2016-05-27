#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct palindrome{
    Node_t *next;
    int isPalindrome;
}Palindrome_t;

Palindrome_t isPalHelper(Node_t *head, int index, int isOdd);

int isPalindrome(LinkedList_t *list){
    int length = getListLength(list);
    int isOdd = length % 2;

    if(list == NULL)
        return 0;

    Palindrome_t res = isPalHelper(list->head, (length + 1) / 2, isOdd);
    return res.isPalindrome;
}

Palindrome_t isPalHelper(Node_t *head, int index, int isOdd){
    Palindrome_t segment;

    // Return true for an empty list
    if(head == NULL || index == 0){
        segment.isPalindrome = 1;
        return segment;
    }

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

int main(int argc, char *argv[]){

 	LinkedList_t *A = createList();

 	createNodeAtTail(A, 'a');
 	createNodeAtTail(A, 'b');
 	createNodeAtTail(A, 'c');
 	createNodeAtTail(A, 'd');
 	createNodeAtTail(A, 'c');
 	createNodeAtTail(A, 'b');
 	createNodeAtTail(A, 'a');

 	printList(A);
 	if(isPalindrome(A))
        printf("The list is a palindrome!\n");
    else
        printf("The list is not a palindrome...\n");

 	deleteList(A);

 	return 0;
}