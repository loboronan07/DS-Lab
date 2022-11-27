/* Lab Exercise 1
	Implement Binary Tree(BT) using iterative function and display the elements of the
	BT using recursive in-order, pre-order, post-order traversal methods.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
} node;

typedef struct {
	struct node* arr[MAX];
	int tos;
} stack;

void printorder(node*, int);
node* create();
node* getnode(char);
void freetree(node*);
node* pop(stack*);
void push(stack*, node*);
stack* initialize();

int main() {
	printf("Enter the data for the Tree A in the order specified...\n");
	node* root = create();

	printf("\nInorder Traversal of the given tree: ");
	printorder(root, 2);
	printf("\n");

	printf("Preorder Traversal of the given tree: ");
	printorder(root, 1);
	printf("\n");

	printf("Postorder Traversal of the given tree: ");
	printorder(root, 3);
	printf("\n");

	freetree(root);

	return 0;
}

node* create() {
	node* root = NULL;
	stack* s = initialize();

	char ele, elel, eler;
	node* temp;

	printf("Enter data for root(Hit # to exit): ");
	scanf("%c", &ele);

	if(ele != '#') {
		root = (node*) malloc(sizeof(node));
		root->data = ele;
		push(s, root);
	}

	while(temp = pop(s)) {
		printf("Enter data for left child of %c(Hit # to exit): ", temp->data);
		scanf(" %c", &elel);
		printf("Enter data for right child of %c(Hit # to exit): ", temp->data);
		scanf(" %c", &eler);

		if(eler != '#') {
			temp->right = getnode(eler);
			push(s, temp->right);
		}
		else 
			temp->right = NULL;

		if(elel != '#') {
			temp->left = getnode(elel);
			push(s, temp->left);
		}
		else 
			temp->left = NULL;
	}

	free(s);

	return root;
}

void printorder(node* root, int order) {
	if(!root) 
		return;

	if(order == 1)
		printf("%c ", root->data);
	printorder(root->left, order);
	if(order == 2)
		printf("%c ", root->data);
	printorder(root->right, order);
	if(order == 3)
		printf("%c ", root->data);
}

void freetree(node* root) {
	if(!root) 
		return;

	freetree(root->left);
	freetree(root->right);
	free(root);
}

stack* initialize() {
	stack* s = (stack*) malloc(sizeof(stack));
	s->tos = -1;
	return s;
}

node* pop(stack* s) {
    if(s->tos == -1)
        return NULL;
    return s->arr[(s->tos)--];
}

void push(stack* s, node* n) {
    s->arr[++(s->tos)] = n;
}

node* getnode(char ele) {
	node* new = (node*) malloc(sizeof(node));
	new->data = ele;
	new->left = new->right = NULL;

	return new;
}
