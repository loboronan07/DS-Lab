/* Lab Exercise 3
	Create an expression tree for the given postfix expression and evaluate it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
} node;

node* create(char*);
void freetree(node*);
int evaluate(node*);
void freetree(node*);

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

node* create(char* postfix) {

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
	else if(op == '^')
		return pow(evaluate(root->left), evaluate(root->right));
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