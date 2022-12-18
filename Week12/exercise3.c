/* Lab Exercise 3
    Given a Binary Tree and a key, write a function that prints all the ancestors of the
    key in the given binary tree.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

node* create(int);
void inorder(node*);
void freetree(node*);
int search(node*, int);
int print_ancestors(node*, int);

int main() {
	int data;
	printf("Enter the data for the Binary Tree in the order specified...\n");
	printf("Enter data for root(Hit 0 to exit): ");
	scanf("%d", &data);
	node* root = create(data);

	printf("Inorder Traversal of the given tree: ");
	inorder(root);
	printf("\n");

    printf("Enter the node whose ancestors is to be found: ");
    scanf("%d", &data);

    if(search(root, data)) {
    	printf("The ancestors of %d from node to root are: ", data);
    	print_ancestors(root, data);
    	printf("\n");
    }
    else 
    	printf("%d does not exist in the tree...\n", data);
    
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

int search(node* root, int ele) {
   	if(!root)
   		return 0;
    
    if(root->data == ele)
    	return 1;

    return (search(root->left, ele) || search(root->right, ele));
}

int print_ancestors(node* root, int ele) { 
    if(!root)
    	return 0;

    if(root->data == ele)
    	return 1;

    if(print_ancestors(root->right, ele) || print_ancestors(root->left, ele)) {
    	printf("\t%d", root->data);
    	return 1;
    }

    return 0;
}