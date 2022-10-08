/* Lab Exercise 1
	Evaluate a given prefix expression using stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int *arr;
	int tos;
} STACK;

STACK* initialize_stack(int);
void push(STACK*, int);
int pop(STACK*);
void free_stack(STACK*);
int evaluate_prefix(char*);
int evaluate(int, int, char);
char* reverse(char *);

int main(void) {
	char expr[100];

	printf("Enter the Prefix Expresiion to be evaluated: ");
	scanf("%[^\n]s", expr);

	int ans = evaluate_prefix(expr);

	printf("The prefix expression evaluates to %d.\n", ans);

	return 0;	
}

STACK* initialize_stack(int size) {
	STACK* stack = (STACK*) malloc(sizeof(STACK));
	stack->arr = (int*) calloc(size, sizeof(int));
	stack->tos = -1;
	return stack;
}

void push(STACK* stack, int ele) {
	stack->arr[++stack->tos] = ele;
}

int pop(STACK* stack) {
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

int evaluate_prefix(char *expr) {
	char *rev = reverse(expr);
	STACK* stack = initialize_stack(strlen(expr));
	char c;
	int op1, op2;

	for(int i=0; rev[i] != '\0'; i++) {
		c = rev[i];
		if(c >= '0' && c <= '9') {
			push(stack, c-'0');
			continue;
		}
		op1 = pop(stack);
		op2 = pop(stack);

		push(stack, evaluate(op1, op2, c));
	}

	int val = pop(stack);

	free(rev);
	free_stack(stack);

	return val;
}

int evaluate(int op1, int op2, char op) {
	switch(op) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		case '%':
			return op1 % op2;
		default:
			exit(100);
	}
}