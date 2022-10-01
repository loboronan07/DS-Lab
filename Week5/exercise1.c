/* Lab Exercise 1
	Implement a menu driven program to define a stack of characters. Include push,
	pop and display functions. Also include functions for checking error conditions
	such as underflow and overflow (ref. figure 1) by defining isEmpty and isFull
	functions. Use these function in push, pop and display functions appropriately. Use
	type defined structure to define a STACK containing a character array and an
	integer top. Do not use global variables.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef struct {
	char *arr;
	int tos;
} STACK;

STACK* initialize_stack(int);
void push(STACK*, char);
void pop(STACK*);
int isEmpty(STACK*);
int isFull(STACK*);
void free_stack(STACK*);
void display(STACK*);

int main(void) {
	STACK* stack = initialize_stack(MAX_STACK_SIZE);
	int choice;
	char ele;

	printf("Available Operations:\n");
	printf("\t1. Push an Element\n");
	printf("\t2. Pop an Element\n");
	printf("\t3. Display Stack Elements\n");
	printf("\t4. Exit\n");

	while(1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);

		if(choice == 4) {
			printf("Exiting from program...\n");
			break;
		}

		switch(choice) {
			case 1:
				printf("Enter element to be pushed into stack: ");
				scanf(" %c", &ele);
				push(stack, ele);
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				display(stack);
				break;
			default:
				printf("Please enter an option from 1 to 4...\n");
				break;
		}
	}

	free_stack(stack);

	return 0;
}

STACK* initialize_stack(int size) {
	STACK* stack = (STACK*) malloc(sizeof(STACK));
	stack->arr = (char*) calloc(size, sizeof(char));
	stack->tos = -1;
	return stack;
}

void push(STACK* stack, char ele) {
	if(isFull(stack)) {
		printf("Stack Overflow... Cannot push element\n");
		return;
	}
	printf("Pushing %c into stack...\n", ele);
	stack->arr[++stack->tos] = ele;
}

void pop(STACK* stack) {
	if(isEmpty(stack)) {
		printf("Stack Underflow... No element to pop\n");
		return;
	}
	printf("Popped %c from stack...\n", stack->arr[stack->tos]);
	stack->tos--;
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

void display(STACK* stack) {
	if(isEmpty(stack)) {
		printf("Stack Empty...\n");
		return;
	}
	printf("Stack Elements: \n");
	for(int i=0; i<=stack->tos; i++) {
		printf("\t%c", stack->arr[i]);
	}
	printf("\n");
}