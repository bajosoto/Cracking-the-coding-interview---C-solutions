#ifndef TREE_H
#define TREE_H

typedef struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode_t;

void printTreeGraph(TreeNode_t *root);
void printTreeInOrder(TreeNode_t *root);
int getMaxTreeHeight(TreeNode_t *root);
TreeNode_t *createTreeNode(int data, TreeNode_t *right, TreeNode_t *left);

#endif