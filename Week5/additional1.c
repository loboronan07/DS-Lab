/* Additional Exercise 1
	Write a program to implement multiple stacks (say n stacks) in a single array.
	Implement ADD(i. X) and DELETE(i) to add X and delete an element from stack i,
	1<= i <= n.
*/

#include <stdio.h>
#include <stdlib.h>

#define MULTI_STACK_SIZE 50

typedef struct {
	int *arr;
	int *tos;
	int *boundary;
} MULTI;

MULTI* initialize_multi_stack(int, int);
void push(MULTI*, int, int);
void pop(MULTI*, int);
int isFull(MULTI*, int);
int isEmpty(MULTI*, int);
void display(MULTI*, int);
void free_stack(MULTI*);

int main(void) {
	int size, n;
	int schoice, choice, ele;
	printf("Enter the maximum stack size: ");
	scanf("%d", &size);
	printf("Enter the number of stacks: ");
	scanf("%d", &n);
	
	MULTI* multi = initialize_multi_stack(size, n);
	
	while(1) {
		printf("Available Stacks:\n");
		for(int i=0; i<n; i++) 
			printf("\t%d. Stack %d\n", i+1, i+1);
		printf("Enter your stack choice(Hit 0 to exit): ");
		scanf("%d", &schoice);

		if(!schoice) {
			break;
		}

		printf("Available Operations:\n");
		printf("\t1. Push an Element\n");
		printf("\t2. Pop an Element\n");
		printf("\t3. Display Stack\n");
		printf("Enter opration(Hit 0 to exit): ");
		scanf("%d", &choice);

		if(!choice) {
			break;
		}

		switch(choice) {
			case 1:
				printf("Enter element to be pushed: ");
				scanf("%d", &ele);
				push(multi, ele, schoice-1);
				break;
			case 2:
				pop(multi, schoice-1);
				break;
			case 3:
				display(multi, schoice-1);
				break;
			default:
				printf("Please enter a valid operation...\n");
				break;
		}
	}
	
	free_stack(multi);
	
	return 0;
}

MULTI* initialize_multi_stack(int size, int n) {
	MULTI* multi = (MULTI*) malloc(sizeof(MULTI));
	multi->arr = (int*) calloc(size, sizeof(int));
	multi->tos = (int*) calloc(n, sizeof(int));
	multi->boundary = (int*) calloc(n+1, sizeof(int));

	multi->tos[0] = multi->boundary[0] = -1;
	for(int i=1; i<=n; i++) 
		multi->tos[i] = multi->boundary[i] = size/n * i - 1;
	multi->boundary[n] = size-1;

	return multi;
}

void push(MULTI* multi, int ele, int stack) {
	if(isFull(multi, stack)) {
		printf("Stack Overflow... Stack %d is currently full...\n", stack+1);
		return;
	}
	printf("Pushing %d into stack %d...\n", ele, stack+1);
	multi->arr[++multi->tos[stack]] = ele;
}

void pop(MULTI* multi, int stack) {
	if(isEmpty(multi, stack)) {
		printf("Stack Underflow... Stack %d is currently empty...\n", stack+1);
		return;
	}
	printf("Popping %d from stack %d...\n", multi->arr[multi->tos[stack]], stack);
	multi->tos[stack]--;
}

int isFull(MULTI* multi, int stack) {
	return multi->tos[stack] == multi->boundary[stack+1];
}

int isEmpty(MULTI* multi, int stack) {
	return multi->tos[stack] == multi->boundary[stack];
}

void display(MULTI* multi, int stack) {
	if(isEmpty(multi, stack)) {
		printf("Stack %d is currently empty...\n", stack+1);
		return;
	}
	printf("Stack %d consists of: \n", stack+1);
	for(int i=multi->boundary[stack] + 1; i<=multi->tos[stack]; i++)
		printf("\t%d", multi->arr[i]);
	printf("\n");
}

void free_stack(MULTI* multi) {
	free(multi->arr);
	free(multi->tos);
	free(multi->boundary);
	free(multi);
}