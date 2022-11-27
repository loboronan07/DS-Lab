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
void print_ancestors(node*, int);

int main() {
	int data;
	printf("Enter the data for the Binary Search Tree in the order specified...\n");
	printf("Enter data for root(Hit 0 to exit): ");
	scanf("%d", &data);
	node* root = create(data);

	printf("Inorder Traversal of the given tree: ");
	inorder(root);
	printf("\n");

    printf("Enter the node whose ancestors is to be found: ");
    scanf("%d", &data);

    print_ancestors(root, data);

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

void print_ancestors(node* root, int ele) { 
    if(search(root, ele)) {
        node* curr = root;

        printf("The ancestors of the node %d is: ", ele);
        while(curr->data != ele) {
            printf("%d ", curr->data);
            curr = ele < curr->data ? curr->left : curr->right;
        }
        printf("\n");
    }
    else 
        printf("%d does not exist in the BST.\n", ele);
}