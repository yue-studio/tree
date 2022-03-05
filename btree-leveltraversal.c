// based on https://www.geeksforgeeks.org/level-order-tree-traversal/
//
// Recursive C program for level
// order traversal of Binary Tree
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data,
pointer to left child
and a pointer to right child */
struct node {
	int data;
	struct node *left, *right;
};

/* Function prototypes */
void printCurrentLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);

/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++){
	    printf("height: %d: \n",i);
		printCurrentLevel(root, i); }
}

/* Print nodes at a current level */
void printCurrentLevel(struct node* root, int level)
{
    printf("at level: %d\n", level);
	if (root == NULL)
		return;
	if (level == 1)
		printf("level: %d data: %d\n", level, root->data);
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(struct node* node)
{
	if (node == NULL) {
	    printf("end\n");
		return 0; 
	} else {
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

	    printf("height %d %d data %d\n", lheight, rheight, node->data);

		/* use the larger one */
		if (lheight > rheight) {
		    printf("height %d data %d\n", lheight+1, node->data);
			return (lheight + 1);
		} else {
		    printf("height %d data %d\n", rheight+1, node->data);
			return (rheight + 1);
		}
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	printf("Level Order traversal of binary tree is \n");
	printLevelOrder(root);

	return 0;
}
