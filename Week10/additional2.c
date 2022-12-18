/* Additional Exercise 1
	Write a ‘C’ program to represent a sparse matrix using doubly linked lists. A
	Matrix with most of its elements being zero is called a sparse matrix.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int i;
	int j;
	struct node* prev;
	struct node* next;
} node;

typedef struct {
	int m;
	int n;
	node* start;	
} head;

head* create(int, int);
void printsparse(head*);
void freell(head*);
node* getnode(int, int, int);

int main() {
	int m, n;

	printf("Enter the order of the matrix: ");
	scanf("%d %d", &m, &n);

	printf("Enter the data for the matrix:\n");
	head* root = create(m, n);

	printf("Matrix entered:\n");
	printsparse(root);

	freell(root);

	return 0;
}

head* create(int m, int n) {
	head* root = (head*) malloc(sizeof(head));
	root->m = m;
	root->n = n;
	root->start = NULL;

	node* temp = NULL;
	int ele;

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", &ele);

			if(ele == 0) 
				continue;

			if(root->start == NULL) 
				root->start = temp = getnode(ele, i, j);
			else {
				temp->next = getnode(ele, i, j);
				temp->next->prev = temp;
				temp = temp->next;
			}
		}
	}

	return root;
}

void printsparse(head* root) {
	node* curr = root->start;

	for(int i=0; i < root->m; i++) {
		for(int j=0; j < root->n; j++) {
			if(!curr || curr->i != i || curr->j != j)
				printf("%4d", 0);
			else {
				printf("%4d", curr->data);
				curr = curr->next;
			}
		}
		printf("\n");
	}
}

void freell(head* root) {
	node* curr = root->start;
	node* temp;

	while(curr) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}

	free(root);
}

node* getnode(int ele, int i, int j) {
	node* new = (node*) malloc(sizeof(node));
	
	new->data = ele;
	new->i = i;
	new->j = j;
	new->next = new->prev = NULL;

	return new;
}

