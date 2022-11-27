/* Lab Exercise 4
    Write a program to construct a BT for given pre-order and the post-order traversal
    sequences.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

node* getnode(int);
void inorder(node*);
void freetree(node*);
node* create(int*, int*, int);

int main() {
    int n;

    printf("Enter the number of nodes in the Binary Tree: ");
    scanf("%d", &n);

    int* pre = (int*) calloc(n, sizeof(int));
    int* post = (int*) calloc(n, sizeof(int));

    printf("Enter the pre-order traversal of the tree: ");
    for(int i=0; i<n; i++) 
        scanf("%d", pre+i);

    printf("Enter the post-order traversal of the tree: ");
    for(int i=0; i<n; i++) 
        scanf("%d", post+i);

    printf("\nCreating the Binary Tree from the traversals given...\n");
    node* root = create(pre, post, n);

    printf("\nThe Inorder Traversal of the given tree: ");
    inorder(root);
    printf("\n");

    freetree(root);
    free(pre);
    free(post);

    return 0;
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

node* create(int* pre, int* post, int n) {
    if(n <= 0) 
        return NULL;

    int il, targetl;
    node* root = getnode(pre[0]);
    
    if(n >= 2) {
        targetl = pre[1];
        
        for(il=0; post[il] != targetl; il++);

        root->left = create(pre+1, post, il+1);
        root->right = create(pre+il+2, post+il+1, n-il-2);
    }

    return root;
}

node* getnode(int ele) {
	node* new = (node*) malloc(sizeof(node));
	new->data = ele;
	new->left = new->right = NULL;

	return new;
}