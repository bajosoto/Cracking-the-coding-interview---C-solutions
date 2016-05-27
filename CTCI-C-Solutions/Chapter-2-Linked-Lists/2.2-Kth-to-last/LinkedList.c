#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

LinkedList_t *createList(){
    LinkedList_t *list = (LinkedList_t *)malloc(sizeof(LinkedList_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node_t *createNodeAtHead(LinkedList_t *list, char *data){
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    node->data = data;
    node->next = list->head;
    list->head = node;
    if(list->tail == NULL)
        list->tail = node;

    return node;
}

Node_t *createNodeAtTail(LinkedList_t *list, char *data){
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

Node_t *kthToLast(LinkedList_t *list, int k){
    Node_t *lagger = list->head;
    Node_t *runner = list->head;
    int i;

    for(i = 0; i < k; i++){
        if(runner->next == NULL)
            return NULL;
        runner = runner->next;
    }
    while(runner->next != NULL){
        lagger = lagger->next;
        runner = runner->next;
    }
    return lagger;
}

void printList(LinkedList_t *list){
    if(list == NULL)
        return;
    Node_t *node = list->head;
    while(node != NULL){
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("\n");
}