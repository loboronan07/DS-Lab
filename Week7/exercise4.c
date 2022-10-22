/* Lab Exercise 4
	Implement a queue with two stacks without transferring the elements of the second
	stack back to stack one. (use stack1 as an input stack and stack2 as an output stack)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *arr;
	int size;
	int tos;
} STACK;

typedef struct {
	STACK* s1;
	STACK* s2;
	STACK* curr;
} QUEUE;


QUEUE* initialize_queue(int);
void enqueue(QUEUE*, int);
int dequeue(QUEUE*);
void display(QUEUE*);
void free_queue(QUEUE*);

STACK* initialize_stack(int);
void push(STACK*, int);
int pop(STACK*);
int isEmpty(STACK*);
int isFull(STACK*);
void free_stack(STACK*);


QUEUE* initialize_queue(int n) {
	QUEUE* q = (QUEUE*) malloc(sizeof(QUEUE));
	q->curr = q->s1 = initialize_stack(n);
	q->s2 = initialize_stack(n);
	return q;
}

void enqueue(QUEUE* q, int ele) {

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