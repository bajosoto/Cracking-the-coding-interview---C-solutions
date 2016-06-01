#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"


void findSumPaths(TreeNode_t *node, int sum, int **arrays, int *columnSizes, int *returnSize, Stack_t *stack){
	if(node == NULL)
		return;
	// Add this node to the stack
	push(stack, node->data);
	if(node->data == sum && !(node->left) && !(node->right)){
		// Increment the number of paths found counter		
		*returnSize += 1;
		// Add stack to a new array
		Stack_t *buffer = createStack();
		arrays = (int **)realloc(arrays, sizeof(int *) * (*returnSize));
		arrays[*returnSize - 1] = (int *)malloc(sizeof(int) * stack->count);
		// Copy from stack to buffer stack and to array
		for(int i = 0; i < stack->count; i++){
			push(buffer, pop(stack));
			arrays[*returnSize - 1][i] = peek(buffer);
		}
		// Return to stack elements from buffer
		for(int i = 0; i < buffer->count; i++){
			push(stack, pop(buffer));
		}
		// Store size of array in returnSize
		columnSizes[*returnSize - 1] = buffer->count;		
	}
	findSumPaths(node->left, sum - node->data, arrays, columnSizes, returnSize, stack);
	findSumPaths(node->left, sum - node->data, arrays, columnSizes, returnSize, stack);
	pop(stack);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(TreeNode_t *root, int sum, int *columnSizes, int *returnSize) {
    *returnSize = 0;
    int **arrays = (int **)malloc(sizeof(int *));
    Stack_t *stack = createStack();

    findSumPaths(root, sum, arrays, columnSizes, returnSize, stack);
    return arrays;
}

int main(int argc, char *argv[]){
	TreeNode_t *root = createTreeNode(8,    createTreeNode(12, createTreeNode(14, createTreeNode(15, NULL, NULL), 
		 																		  createTreeNode(13, NULL, NULL)),
															   createTreeNode(10, createTreeNode(11, NULL, NULL),
															   	 				  createTreeNode(9 , NULL, NULL))),
		 									createTreeNode(4 , createTreeNode(6 , createTreeNode(7 , NULL, NULL), 
		 																		  createTreeNode(5 , NULL, NULL)),
															   createTreeNode(2 , createTreeNode(3 , NULL, NULL),
															   	 				  createTreeNode(1 , NULL, NULL)))
										);
	printf("Tree height: %d\n", getMaxTreeHeight(root));
	printf("In-order traversal: ");
	printTreeInOrder(root);
	return 0;
}