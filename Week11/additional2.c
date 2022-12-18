/* Additional Exercise 2
    Create an expression tree for the given prefix expression and evaluate it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void freetree(node*);
int evaluate(node*);
stack* initialize();
node* pop(stack*);
void push(stack*, node*);
char* string_reverse(char*);

int main() {
	char prefix[50];

	printf("Enter the Prefix Expression: ");
	scanf("%s", prefix);

	printf("Creating an Expression Tree for the given Prefix Expression...\n");
	node* root = create(prefix);

	int ans = evaluate(root);

	printf("The Evaulation of the given Prefix Expression resulted in %d\n", ans);

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

node* create(char* prefix) {
    char* rev = string_reverse(prefix);
    
	stack* s = initialize();
	node *root = NULL, *temp;

	char c;
	int i=0;
	while(rev[i]) {
		c = rev[i];

		if(checkop(c)) {
			temp = getnode(c);
			temp->left = pop(s);
			temp->right = pop(s);
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

char* string_reverse(char *str) {
    int len = strlen(str);
    char *rev = (char *) calloc(len+1, sizeof(char));
    for(int i=0; i < len; i++) {
        rev[i] = str[len-1-i];
    }
    rev[len] = '\0';
    return rev;
}