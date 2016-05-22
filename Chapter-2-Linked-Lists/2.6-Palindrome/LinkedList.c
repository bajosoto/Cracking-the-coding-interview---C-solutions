#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

LinkedList_t *createList(){
    LinkedList_t *list = (LinkedList_t *)malloc(sizeof(LinkedList_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void deleteList(LinkedList_t *list){
    Node_t *node = list->head;
    Node_t *temp;
    while(node != NULL){
        temp = node->next;
        free(node);
        node = temp;
    }
    free(list);
}

Node_t *createNodeAtHead(LinkedList_t *list, char data){
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    node->data = data;
    node->next = list->head;
    list->head = node;
    if(list->tail == NULL)
        list->tail = node;

    return node;
}

Node_t *createNodeAtTail(LinkedList_t *list, char data){
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    node->data = data;
    if(list->tail != NULL)
        list->tail->next = node;
    node->next = NULL;
    list->tail = node;
    if(list->head == NULL)
        list->head = node;    
    return node;
}

void printList(LinkedList_t *list){
    if(list == NULL)
        return;
    Node_t *node = list->head;
    while(node != NULL){
        printf("%c", node->data);
        if(node->next != NULL)
            printf(" -> ");
        node = node->next;
    }
    printf("\n");
}

int getListLength(LinkedList_t *list){
    int length = 0;
    Node_t *node = list->head;
    
    if(list == NULL)
        return -1;
    
    while(node != NULL){
        length++;
        node = node->next;
    }
    return length;
}