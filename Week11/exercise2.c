/* Lab Exercise 2
	Display the elements of Binary Tree created using iterative preorder, post-order
	(Use single stack), in-order and level-order traversals.
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

node* create(char);
void preorder(node*);
void inorder(node*);
void postorder(node*);
stack* initialize();
node* pop(stack*);
void push(stack*, node*);
node* atTop(stack*);

int main() {
	char data;
	printf("Enter the data for the Tree in the order specified...\n");
	printf("Enter data for root(Hit # to exit): ");
	scanf(" %c", &data);
	node* root = create(data);

	printf("\nInorder Traversal of the given tree: ");
	inorder(root);
	printf("\n");

	printf("Preorder Traversal of Tree: ");
	preorder(root);
	printf("\n");

	printf("Postorder Traversal of the given tree: ");
	postorder(root);
	printf("\n");

	return 0;
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

void preorder(node* root) {
	if(!root)
		return;
	
	stack* s = initialize();
	push(s, root);

	node* temp;
	while(temp = pop(s)) {
		printf("%c ", temp->data);
		if(temp->right)
			push(s, temp->right);
		if(temp->left)
			push(s, temp->left);
	}

	free(s);
}

void inorder(node* root) {
	int flag = 0;

	if(!root) 
		return;
	
	stack* s = initialize();
	node* curr = root;
	
	while(!flag) {
		while(curr != NULL) {
			push(s, curr);
			curr = curr->left;
		}

		if(curr = pop(s)) {
			printf("%c ", curr->data);
			curr = curr->right;
		}
		else 
			flag = 1;
	}

	free(s);
}

void postorder(node* root) {
	if(!root) 
		return;

	stack* s = initialize();

	do {
		while(root) {
			if(root->right) 
				push(s, root->right);
			push(s, root);

			root = root->left;
		}

		root = pop(s);

		if(root->right && atTop(s) == root->right) {
			pop(s);
			push(s, root);
			root = root->right;
		}
		else {
			printf("%d ", root->data);
			root = NULL;
		}
	} while(atTop(s));

	free(s);
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

node* atTop(stack* s) {
	if(s->tos == -1)
		return NULL;
	return s->arr[s->tos];
}
