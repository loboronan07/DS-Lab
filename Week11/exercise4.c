/* Lab Exercise 4
	Implement recursive functions to do the following:
		a) To create a copy of a BT.
		b) Testing for equality of two BTs.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
} node;

node* create(char ele);
node* copy(node*);
int check_equals(node*, node*);
void inorder(node*);
void freetree(node*);

int main() {
	char data;

	printf("Enter the data for the Tree A in the order specified...\n");
	printf("Enter data for root(Hit # to exit): ");
	scanf(" %c", &data);
	node* rootA = create(data);

	printf("\nEnter the data for the Tree B in the order specified...\n");
	printf("Enter data for root(Hit # to exit): ");
	scanf(" %c", &data);
	node* rootB = create(data);

	printf("\nInorder Traversal of Tree A: ");
	inorder(rootA);
	printf("\n");

	printf("Inorder Traversal of Tree B: ");
	inorder(rootB);
	printf("\n");

	printf("\nCreating a Copy of Tree A...\n");
	node* copyA = copy(rootA);

	printf("Inorder Traversal of Copy of Tree A: ");
	inorder(copyA);
	printf("\n");

	if(check_equals(rootA, rootB)) 
		printf("\nTree A and B are equal to each other...\n");
	else
		printf("\nTree A and B are not equal to each other...\n");

	if(check_equals(rootA, copyA)) 
		printf("Tree A and Copy of Tree A are equal to each other...\n");
	else
		printf("Tree A and Copy of Tree A are not equal to each other...\n");

	freetree(rootA); 
	freetree(rootB);
	freetree(copyA);

	return 0;
}

void inorder(node* root) {
	if(!root) 
		return;

	inorder(root->left);
	printf("%c ", root->data);
	inorder(root->right);
}

node* copy(node* root) {
	if(!root) 
		return NULL;

	node* temp = (node*) malloc(sizeof(node));
	temp->data = root->data;
	temp->left = copy(root->left);
	temp->right = copy(root->right);

	return temp;
}

int check_equals(node* A, node* B) {
	if(!A && !B)
		return 1;

	if(!A || !B || A->data != B->data) 
		return 0;

	return check_equals(A->left, B->left) && check_equals(A->right, B->right);
}

void freetree(node* root) {
	if(!root) 
		return;

	freetree(root->left);
	freetree(root->right);
	free(root);
}

node* create(char ele){
	if(ele == '#') 
		return NULL;

	char x;

	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;

	printf("Enter data for left child of %c(Hit # to exit): ", ele);
	scanf(" %c", &x);
	temp->left = create(x);

	printf("Enter data for right child of %c(Hit # to exit): ", ele);
	scanf(" %c", &x);
	temp->right = create(x);

	return temp;
}