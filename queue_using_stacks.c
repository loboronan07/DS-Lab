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
	char op;
} QUEUE;


QUEUE* initialize_queue(int);
int enqueue(QUEUE*, int);
int dequeue(QUEUE*);
void free_queue(QUEUE*);

STACK* initialize_stack(int);
int push(STACK*, int);
int pop(STACK*);
int isEmpty(STACK*);
int isFull(STACK*);
void free_stack(STACK*);


int main(void) {
	int n, ele;

	printf("Enter the max size of queue: ");
	scanf("%d", &n);

	QUEUE* q = initialize_queue(n);

	printf("Starting Enqueue Operation....\n");
	while(1) {
		printf("Enter element to enqueue(hit 0 to stop): ");
		scanf("%d", &ele);
		if(ele == 0 || !enqueue(q, ele)) {
			printf("Stopping Enqueue Operation....\n");
			break;
		}
	}

	printf("Starting Dequeue Operations....\n");
	for(ele = dequeue(q); ele != -5555; ele = dequeue(q)) 
		printf("%d was dequeued from the queue\n", ele);
	printf("Stopping Dequeue Operations....\n");

	free_queue(q);
	return 0;
}


QUEUE* initialize_queue(int n) {
	QUEUE* q = (QUEUE*) malloc(sizeof(QUEUE));
	q->s1 = initialize_stack(n);
	q->s2 = initialize_stack(n);
	q->op = 'e';
	return q;
}

int enqueue(QUEUE* q, int ele) {
	if(!q->op == 'e') {
		printf("Queue not in Enqueue mode\n");
		return 0;
	}
    if(!push(q->s1, ele)) {
        printf("Queue Full...\n");
		return 0;
	}
	return 1;
}

int dequeue(QUEUE* q) {
    int popped;
	int flag = (q->op= 'e') ? 1:0;
    while(flag) {
        popped = pop(q->s1);
        if(popped != -5555) 
            push(q->s2, popped);
		else 
			break;
	}
	if(flag) 
		q->op = 'd';
	return pop(q->s2);
}

void free_queue(QUEUE* q) {
	free_stack(q->s1);
	free_stack(q->s2);
	free(q);
}

STACK* initialize_stack(int size) {
	STACK* stack = (STACK*) malloc(sizeof(STACK));
	stack->arr = (int*) calloc(size, sizeof(int));
	stack->tos = -1;
	stack->size = size;
	return stack;
}

int push(STACK* stack, int ele) {
	if(isFull(stack)) {
		return 0;
	}
	stack->arr[++stack->tos] = ele;
    return 1;
}

int pop(STACK* stack) {
    if(isEmpty(stack)) {
        return -5555;
    }
	return stack->arr[stack->tos--];
}

int isEmpty(STACK* stack) {
	return stack->tos == -1;
}

int isFull(STACK* stack) {
	return stack->tos == stack->size - 1;
}

void free_stack(STACK* stack) {
	free(stack->arr);
	free(stack);
}