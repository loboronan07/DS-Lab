/* Lab Exercise 4
	To convert a prefix expression to postfix using stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *arr;
	int tos;
} STACK;

STACK* initialize_stack(int);
void push(STACK*, char);
char pop(STACK*);
void free_stack(STACK*);
char* prefix_to_postfix(char*);
int is_operator(char);
int check_precedence(char, char);
int is_empty(STACK*);

int main(void) {
	char prefix[100];

	printf("Enter the prefix expression: ");
	scanf("%[^\n]s", prefix);

	char *postfix = prefix_to_postfix(prefix);

	printf("The equivalent postfix expression of the above given prefix expression is %s.\n", postfix);

	free(postfix);
	return 0;
}

STACK* initialize_stack(int size) {
	STACK* stack = (STACK*) malloc(sizeof(STACK));
	stack->arr = (char*) calloc(size, sizeof(char));
	stack->tos = -1;
	return stack;
}

void push(STACK* stack, char ele) {
	stack->arr[++stack->tos] = ele;
}

char pop(STACK* stack) {
	return stack->arr[stack->tos--];
}

void free_stack(STACK* stack) {
	free(stack->arr);
	free(stack);
}

char* reverse(char *str) {
	int len = strlen(str);
	char* rev = (char*) calloc(len + 1, sizeof(char));
	for(int i=0; i<len; i++) 
		rev[i] = str[len-1-i];
	rev[len] = '\0';
	return rev;
}

int is_operator(char c) {
	switch(c) {
		case '+':
		case '-':
		case '/':
		case '*':
		case '%':
			return 1;
		default:
			return 0;
	}
}

int is_empty(STACK* stack) {
	return stack->tos == -1;
}

char* prefix_to_postfix(char* prefix) {
	STACK* stack = initialize_stack(strlen(prefix));
	char c, op;
	char *postfix = (char *) calloc(strlen(prefix) + 1, sizeof(char));
	int ind = -1;
	int count = 0;

	for(int i=0; prefix[i] != '\0'; i++) {
		c = prefix[i];

		if(is_operator(c)) {
			push(stack, c);
			count = 0;
			continue;
		}
		postfix[++ind] = c;
		if(count != 0) 
			postfix[++ind] = pop(stack);
		count = 1;
	}
	while(!is_empty(stack)) 
		postfix[++ind] = pop(stack);

	postfix[++ind] = '\0';
	
	free_stack(stack);

	return postfix;
}
