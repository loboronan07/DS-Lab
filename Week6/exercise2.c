/* Lab Exercise 2
	Convert an infix expression to prefix.
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
char* infix_to_prefix(char*);
char* reverse(char *);
int is_operator(char);
int check_precedence(char, char);
int is_empty(STACK*);

int main(void) {
	char infix[100];

	printf("Enter the infix expression: ");
	scanf("%[^\n]s", infix);

	char *prefix = infix_to_prefix(infix);

	printf("The equivalent prefix expression of the above given infix expression is %s.\n", prefix);

	free(prefix);
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

char *infix_to_prefix(char* infix) {
	char *rev = reverse(infix);
	STACK* stack = initialize_stack(strlen(infix));
	char c, op;
	char *prefix = (char *) calloc(strlen(infix) + 1, sizeof(char));
	int ind=-1;

	for(int i=0; rev[i] != '\0'; i++) {
		c = rev[i];

		if(c == '(') {
			while(op = pop(stack) && op != ')') {
				prefix[++ind] = op;
			}
			continue;
		}
		if(c == '(') {
			push(stack, c);
			continue;
		}

		if(is_operator(c)) {
			while(!is_empty(stack) && (op=pop(stack)) && check_precedence(op, c)) 
				prefix[++ind] = op;
			push(stack, c);
			continue;
		}
		prefix[++ind] = c;
	}
	while(!is_empty(stack)) 
		prefix[++ind] = pop(stack);
	prefix[++ind] = '\0';

	free(rev);

	rev = reverse(prefix);

	free(prefix);
	free_stack(stack);

	return rev;
}

int check_precedence(char op1, char op2) {
	switch(op1) {
		case '*':
		case '/':
		case '%':
			switch(op2) {
				case '*':
				case '/':
				case '%':
					return 0;
				default:
					return 1;
			}
		default:
			switch(op2) {
				case '+':
				case '-':
					return 0;
				default:
					return 1;
			}
	}
}