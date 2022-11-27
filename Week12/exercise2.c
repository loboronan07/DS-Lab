/* Lab Exercise 2
    Given a BST, write a function to find the in-order successor of a node.
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

node* create(int);
void inorder(node*);
void freetree(node*);
int search(node*, int);
void find_successor(node*, int);
stack* initialize();
node* pop(stack*);
void push(stack*, node*);

int main() {
	int data;
	printf("Enter the data for the Binary Search Tree in the order specified...\n");
	printf("Enter data for root(Hit 0 to exit): ");
	scanf("%d", &data);
	node* root = create(data);

	printf("Inorder Traversal of the given tree: ");
	inorder(root);
	printf("\n");

    printf("Enter the node whose successor is to be found: ");
    scanf("%d", &data);

    find_successor(root, data);

	freetree(root);

	return 0;
}

node* create(int ele){
	if(ele == 0) 
		return NULL;

	int x;

	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;

	printf("Enter data for left child of %d(Hit 0 to exit): ", ele);
	scanf("%d", &x);
	temp->left = create(x);

	printf("Enter data for right child of %d(Hit 0 to exit): ", ele);
	scanf("%d", &x);
	temp->right = create(x);

	return temp;
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

void find_successor(node* root, int ele) {
	if(!search(root, ele)) {
		printf("The node was not found in the tree..\n");
		return;
	}

	int flag = 0;
	stack* s = initialize();
	node* curr = root;
	
	printf("The inorder successor of %d ", ele);
	while(1) {
		while(curr != NULL) {
			push(s, curr);
			curr = curr->left;
		}

		if(curr = pop(s)) {
			if(flag) {
				printf("is %d\n", curr->data);
				flag = 0;
			}
			if(curr->data == ele) 
				flag = 1;
			curr = curr->right;
		}
		else 
			break;
	}

	free(s);
}

int search(node* root, int ele) {
    int flag = 0;
    
    node* curr = root;
    while(curr) {
        if(curr->data == ele) {
            flag=1;
            break;
        }
        curr = ele < curr->data ? curr->left : curr->right;
    }

    return flag;
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