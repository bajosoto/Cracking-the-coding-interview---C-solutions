#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>


void printTreeGraph(TreeNode_t *root){

}

void printInOrderHelper(TreeNode_t *node){
 	if(node == NULL)
 		return;
 	printInOrderHelper(node->left);
 	printf("%d ", node->data);
 	printInOrderHelper(node->right);
}

void printTreeInOrder(TreeNode_t *root){
	printf("[ ");
	printInOrderHelper(root);
	printf("]\n");
}

void getMaxTreeHeightHelper(TreeNode_t *node, int *max, int *curr){
	if(node == NULL)
		return;
	(*curr)++;
	if(*curr > *max)
		*max = *curr;
	getMaxTreeHeightHelper(node->left, max, curr);
	getMaxTreeHeightHelper(node->right, max, curr);
	(*curr)--;
}

int getMaxTreeHeight(TreeNode_t *root){
	int maxHeight = -1;
	int height = -1;
	getMaxTreeHeightHelper(root, &maxHeight, &height);
	return maxHeight;
}

TreeNode_t *createTreeNode(int data, TreeNode_t *right, TreeNode_t *left){
	TreeNode_t *newNode = (TreeNode_t *)malloc(sizeof(TreeNode_t));
	newNode->data = data;
	newNode->left = left;
	newNode->right = right;
	return newNode;
}