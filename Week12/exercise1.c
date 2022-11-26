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
	int n;

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

	freetree(root);

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
	if(!*root) 
		return;

	node *curr = *root, *prev = NULL;
	while(curr != NULL && curr->data != ele) {
		prev = curr;
		curr = curr->data > ele ? curr->left : curr->right;
	}

	if(curr == NULL) {
		printf("Element does not exist in the tree...\n");
		return;
	}
	node* piv=curr->left, *prev_piv=curr;
	if(curr->left) {
		
		while(1) {
			if(largest->right) {
				prev_largest = largest;
				largest = largest->right;
			}
			else if(largest->left) {
				prev_largest = largest;
				largest = largest->left;
			}
			else
				break;
		}

	}
	else if(curr->right){

	}

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