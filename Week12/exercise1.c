/* Lab Exercise 1
	Write a menu driven program to do the following using iterative functions:
		i. To create a BST for a given set of integer numbers
		ii. To delete a given element from BST .
			Note: Replace the element to be deleted with the largest element in the LST (Left
			Sub Tree) ) when the node to be deleted has both LST (Left Sub Tree) and RST
			(Right Sub Tree).
		iii. To display the elements using in-order traversal.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

void insert(node**, int);
void delete(node**, int);
node* create(int*, int);
void inorder(node*);
void freetree(node*);

int main() {
	int n, ele;

	printf("Enter the number of integers: ");
	scanf("%d", &n);

	int *arr = (int*) calloc(n, sizeof(int));

	printf("Enter the integer list: ");
	for(int i=0; i<n; i++) 
		scanf("%d", arr+i);

	printf("Creating a Binary Search Tree using the integers provided...\n");
	node* root = create(arr, n);

	printf("Inorder Traversal of the given tree: ");
	inorder(root);
	printf("\n");

	printf("Enter the node to be deleted: ");
	scanf("%d", &ele);
	delete(&root, ele);	

	printf("Inorder Traversal of the given tree after deletion: ");
	inorder(root);
	printf("\n");

	freetree(root);
	free(arr);

	return 0;
}

node* create(int* arr, int n) {
	node* root = NULL;

	for(int i=0; i<n; i++) 
		insert(&root, arr[i]);

	return root;
}

void insert(node** root, int ele) {
	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;
	temp->left = temp->right = NULL;

	if(*root == NULL) {
		*root = temp;
		return;
	}

	node* prev = NULL, *curr = *root;
	while(curr != NULL) {
		if(curr->data == ele) {
			free(temp);
			return;
		}
		else if(curr->data > ele) {
			prev = curr;
			curr = curr->left;
		}
		else {
			prev = curr;
			curr = curr->right;
		}
	}

	if(prev->data > ele) 
		prev->left = temp;
	else
		prev->right = temp;
} 

void delete(node** root, int ele) {
	if(!*root) {
		printf("Tree is Empty..\n");
		return;
	}

	node *curr = *root, *parent = NULL;
	while(curr && curr->data != ele) {
		parent = curr;
		curr = curr->data > ele ? curr->left : curr->right;
	}

	if(curr == NULL) {
		printf("Element does not exist in the tree...\n");
		return;
	}


	node *piv, *prev_piv;
	if(curr->left) {
		piv = curr->left;
		prev_piv = curr;
		while(piv->right) {
			prev_piv = piv;
			piv = piv->right;
		}
		if(prev_piv != curr)
			prev_piv->right = piv->left;
		
		if(parent)
			if(parent->left == curr) 
				parent->left = piv;
			else
				parent->right = piv;
		else 
			*root = piv;

		if(prev_piv != curr)
			piv->left = curr->left;
		piv->right = curr->right;
	}
	else {
		if(parent)
			if(parent->left == curr) 
				parent->left = curr->right;
			else
				parent->right = curr->right;
		else
			*root = curr->right;
	}

	free(curr);
}

void inorder(node* root) {
	if(!root) 
		return;

	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void freetree(node* root) {
	if(!root) 
		return;

	freetree(root->left);
	freetree(root->right);
	free(root);
}
