/* Lab Exercise 2
	Display the elements of Binary Tree created using iterative preorder, post-order
	(Use single stack), in-order and level-order traversals.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

typedef struct {
	struct node* arr[MAX];
	int tos;
} stack;

stack* initialize()