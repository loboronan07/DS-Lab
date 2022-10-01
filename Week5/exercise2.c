/* Lab Exercise 2
	Convert a given decimal number to binary using stack.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 20

typedef struct {
	int *arr;
	int tos;
} STACK;

STACK* initialize_stack(int);
void push(STACK*, int);
int pop(STACK*);
int isEmpty(STACK*);
int isFull(STACK*);
void free_stack(STACK*);
long dec_to_bin(int);

int main(void) {
	int decimal;

	printf("Enter a number: ");
	scanf("%d", &decimal);

	printf("Binary Equivalent of %d is %ld.\n", decimal, dec_to_bin(decimal));

	return 0;
}

STACK* initialize_stack(int size) {
	STACK* stack = (STACK*) malloc(sizeof(STACK));
	stack->arr = (int*) calloc(size, sizeof(int));
	stack->tos = -1;
	return stack;
}

void push(STACK* stack, int ele) {
	if(isFull(stack)) {
		printf("Stack size not large enough to process this number.\n");
		free_stack(stack);
		exit(100);
	}
	stack->arr[++stack->tos] = ele;
}

int pop(STACK* stack) {
	return stack->arr[stack->tos--];
}

int isEmpty(STACK* stack) {
	return stack->tos == -1;
}

int isFull(STACK* stack) {
	return stack->tos == MAX_STACK_SIZE - 1;
}

void free_stack(STACK* stack) {
	free(stack->arr);
	free(stack);
}

long dec_to_bin(int num) {
	STACK* stack = initialize_stack(MAX_STACK_SIZE);

	while (num != 0) {
		push(stack, num%2);
		num /= 2;
	}

	long binary = 0;

	while(!isEmpty(stack)) {
		binary = binary * 10 + pop(stack);
	}

	free_stack(stack);

	return binary;
}
