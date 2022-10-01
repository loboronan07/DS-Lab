/* Additional Exercise 2
	Given an array, print the Next Greater Element (NGE) for every element using
	stack. The Next Greater Element for an element x is the first greater element on the
	right side of x in array. Elements for which no greater element exist, consider next
	greater element as -1. For the input array [13, 7, 6, 12}, the next greater elements
	for each element are as follows.
*/

#include <stdio.h> 
#include <stdlib.h>

#define MAX_STACK_SIZE 50
typedef struct {
	int *arr;
	int tos;
} STACK;

STACK* initialize_stack();
void push(STACK *, int);
int pop(STACK *);
int isFull(STACK *);
int isEmpty(STACK *);
void free_stack(STACK *);
void nge(int *, int);

int main(void) {
	int n;

	printf("Enter the number of elements, n: ");
	scanf("%d", &n);

	int *arr = (int *) calloc(n, sizeof(int));

	printf("Enter %d elements: ", n);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);

	nge(arr, n);

	free(arr);
	return 0;
}

STACK* initialize_stack() {
	STACK* stack = (STACK *) malloc(sizeof(STACK));
	stack->tos = -1;
	stack->arr = (int *) calloc(MAX_STACK_SIZE, sizeof(int));
	return stack;
}

void push(STACK* stack, int ele) {
	stack->arr[++stack->tos] = ele;
}

int pop(STACK* stack) {
	return stack->arr[stack->tos--];
}

int isFull(STACK* stack) {
	return stack->tos == MAX_STACK_SIZE - 1;
}

int isEmpty(STACK* stack) {
	return stack->tos == -1;
}

void free_stack(STACK* stack) {
	free(stack->arr);
	free(stack);
}

void nge(int *arr, int n) {
	STACK* stack = initialize_stack();
	int ele, next;

	push(stack, *arr);

	printf("Element\t\tNGE\n");

	for(int i=1; i<n; i++) {
		next = *(arr + i);

		if(!isEmpty(stack)) {
			ele = pop(stack);

			while(ele < next) {
				printf("%d\t-->>\t%d\n", ele, next);
				if(isEmpty(stack)) 
					break;
				ele = pop(stack);
			}

			if(ele > next) {
				push(stack, ele);
			}
		}
		push(stack, next);
	}

	while(!isEmpty(stack)) {
		ele = pop(stack);
		printf("%d\t-->>\t%d\n", ele, -1);
	}

	free_stack(stack);
}