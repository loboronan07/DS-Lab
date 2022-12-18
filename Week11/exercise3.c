/* Lab Exercise 3
	Create an expression tree for the given postfix expression and evaluate it.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
} node;

typedef struct {
	struct node* arr[MAX];
	int tos;
} stack;

int checkop(char);
node* create(char*);
int evaluate(node*);
void freetree(node*);
stack* initialize();
node* pop(stack*);
void push(stack*, node*);

int main() {
	char postfix[50];

	printf("Enter the Postfix Expression: ");
	scanf("%s", postfix);

	printf("Creating an Expression Tree for the given Post Fix Expression...\n");
	node* root = create(postfix);

	int ans = evaluate(root);

	printf("The Evaulation of the given PostFix Expression resulted in %d\n", ans);

	freetree(root);

	return 0;
}

int checkop(char ele) {
	switch (ele) {
		case '+': 
		case '-':
		case '*': 
		case '/':
		case '%': 
			return 1;
		default:
			return 0;
	}
}

node* getnode(char ele) {
	node* new = (node*) malloc(sizeof(node));
	new->data = ele;
	new->left = new->right = NULL;

	return new;
}

node* create(char* postfix) {
	stack* s = initialize();
	node *root = NULL, *temp;

	char c;
	int i=0;
	while(postfix[i]) {
		c = postfix[i];

		if(checkop(c)) {
			temp = getnode(c);
			temp->right = pop(s);
			temp->left = pop(s);
			push(s, temp);
		}
		else 
			push(s, getnode(c));

		i++;
	}

	temp = pop(s);

	free(s);

	return temp;
}

int evaluate(node* root) {
	if(!root) 
		return 0;

	char op = root->data;

	if(op == '+')
		return evaluate(root->left) + evaluate(root->right);
	else if(op == '-')
		return evaluate(root->left) - evaluate(root->right);
	else if(op == '*')
		return evaluate(root->left) * evaluate(root->right);
	else if(op == '/')
		return evaluate(root->left) / evaluate(root->right);
	else if(op == '%')
		return evaluate(root->left) % evaluate(root->right);
	else
		return op - '0';
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
