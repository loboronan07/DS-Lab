/* Lab Exercise 3
	Determine whether a given string is palindrome or not using stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
	char *arr;
	int tos;
} STACK;

STACK* initialize_stack(int);
void push(STACK*, char);
char pop(STACK*);
void free_stack(STACK*);
int isPalin(char*);

int main(void) {
	char str[SIZE];

	printf("Enter a string: ");
	scanf("%[^\n]s", str);

	if(isPalin(str)) {
		printf("The entered string is a Palindrome.\n");
	}
	else {
		printf("The entered string is not a Palindrome.\n");
	}

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

int isPalin(char *str) {
	STACK* stack = initialize_stack(SIZE);

	int len = strlen(str);
	int i;

	for(i=0; i < len/2; i++) {
		push(stack, str[i]);
	}

	if(len%2 == 1)
		i++;

	int palin = 1;

	for(; i<len; i++) {
		if(pop(stack) != str[i]) {
			palin = 0;
			break;
		}
	}

	free_stack(stack);

	return palin;
}