/* Lab Exercise 4
	Given an array arr with n elements and a number k, k<n. The task is to delete k
	elements which are smaller than next element (i.e., we delete arr[i] if arr[i] <
	arr[i+1]) or become smaller than next because next element is deleted. Example:
		Input: arr[] = {20, 10, 25, 30, 40}, k = 2
		Output: 25 30 40
	Explanation: First we delete 10 because it follows arr[i] < arr[i+1]. Then we delete 20
	because 25 is moved next to it and it also starts following the condition.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *arr;
	int tos;
} STACK;

STACK* initialize_stack(int);
void push(STACK*, int);
void pop(STACK*);
int isEmpty(STACK*);
int isFull(STACK*);
void free_stack(STACK*);
int atTop(STACK*);
int* toArr(STACK*, int*);

int main(void) {
	int n, k;

	printf("Enter the number of elements in the array, n: ");
	scanf("%d", &n);

	int *arr = (int *) calloc(n, sizeof(int));

	printf("Enter %d elements of the array: ", n);
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}
	printf("Enter the number of elements to be deleted, k: ");
	scanf("%d", &k);

	STACK* stack = initialize_stack(n);
	int deleted = 0;

	for(int i=0; i<n; i++) {
		while(!isEmpty(stack) && deleted < k && arr[i] > atTop(stack)) {
			pop(stack);
			deleted++;
		}
		push(stack, arr[i]);
	}
	
	free(arr);
	arr = toArr(stack, &n);

	printf("Elements in the array after processing: \n");
	for(int i=0; i<n; i++) {
		printf("\t%d", arr[i]);
	}
	printf("\n");	

	free(arr);
	free_stack(stack);

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

void pop(STACK* stack) {
	stack->tos--;
}

int isEmpty(STACK* stack) {
	return stack->tos == -1;
}

void free_stack(STACK* stack) {
	free(stack->arr);
	free(stack);
}

int atTop(STACK* stack) {
	return stack->arr[stack->tos];
}

int* toArr(STACK* stack, int* n) {
	*n = stack->tos + 1;
	int *arr = (int *) calloc(*n, sizeof(int));

	for(int i=0; i<*n; i++) {
		arr[i] = stack->arr[i];
	}

	return arr;
}