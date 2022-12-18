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

typedef struct {
	node* arr[MAX];
	int front;
	int rear;
} queue;

node* create(char);
void preorder(node*);
void inorder(node*);
void postorder(node*);
void levelorder(node*);
node* getnode(char);
void freetree(node*);
stack* initializes();
node* pop(stack*);
void push(stack*, node*);
node* atTop(stack*);
queue* initializeq();
void insertq(queue*, node*);
node* deleteq(queue*);

int main() {
	char data;
	printf("Enter the data for the Tree in the order specified...\n");
	printf("Enter data for root(Hit # to exit): ");
	scanf(" %c", &data);
	node* root = create(data);

	printf("\nInorder Traversal of the given tree: ");
	inorder(root);
	printf("\n");

	printf("Preorder Traversal of the given tree: ");
	preorder(root);
	printf("\n");

	printf("Postorder Traversal of the given tree: ");
	postorder(root);
	printf("\n");

	printf("Levelorder Traversal of the given tree: ");
	levelorder(root);
	printf("\n");

	freetree(root);

	return 0;
}

node* getnode(char ele) {
	node* new = (node*) malloc(sizeof(node));
	new->data = ele;
	new->left = new->right = NULL;

	return new;
}

node* create(char ele){
	if(ele == '#') 
		return NULL;

	char x;

	node* temp = getnode(ele);

	printf("Enter data for left child of %c(Hit # to exit): ", ele);
	scanf(" %c", &x);
	temp->left = create(x);

	printf("Enter data for right child of %c(Hit # to exit): ", ele);
	scanf(" %c", &x);
	temp->right = create(x);

	return temp;
}

void preorder(node* root) {
	if(!root) {
		printf("Tree is Empty..");
		return;
	}
	
	stack* s = initializes();
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

	if(!root) {
		printf("Tree is Empty..");
		return;
	}
	
	stack* s = initializes();
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
	if(!root) {
		printf("Tree is Empty..");
		return;
	}

	stack* s = initializes();

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
			printf("%c ", root->data);
			root = NULL;
		}
	} while(atTop(s));

	free(s);
}

void levelorder(node* root) {
	if(!root) {
		printf("Tree is Empty..");
		return;
	}

	queue* q = initializeq();
	node* curr=NULL;
	
	insertq(q, root);

	while(curr = deleteq(q)) {
		printf("%c ", curr->data);
		if(curr->left)
			insertq(q, curr->left);
		if(curr->right) 
			insertq(q, curr->right);
	}

	free(q);
}

void freetree(node* root) {
	if(!root) 
		return;

	freetree(root->left);
	freetree(root->right);
	free(root);
}

stack* initializes() {
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

queue* initializeq() {
	queue* q = (queue*) malloc(sizeof(queue));
	q->front = 	q->rear = 0;
	return q;
}

void insertq(queue *q, node* ele) {
	q->rear = (q->rear+1) % MAX;
	q->arr[q->rear] = ele;
}

node* deleteq(queue *q) {
	node* x;
	if(q->front == q->rear) 
		x = NULL;
	else if((q->front+1)%MAX == q->rear) {
		x = q->arr[q->rear];
		q->front = q->rear = 0;
	}
	else {
		q->front = (q->front+1) % MAX;
		x = q->arr[q->front];
	}
	return x;
}