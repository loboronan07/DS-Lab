/* Lab Exercise 4
	Given a queue of integers, write a program to reverse the queue, using only the following operations:
		i.	enqueue(x): Add an item x to rear of queue.
		ii.	dequeue() : Remove an item from front of queue.
		iii.empty() : Checks if a queue is empty or not.
*/

#include <stdio.h> 
#include <stdlib.h>

typedef struct {
	int *arr;
    int size;
	int front;
	int rear;
} queue;

void enqueue(queue *, int);
void display(queue *);
int dequeue(queue *);
queue* initialize(int);
void free_queue(queue *);
void reverse(queue *);
int empty(queue *);

int main() {
    int n, flag=1, ch, ele;
    
    printf("Enter the maximum size for the queue: ");
    scanf("%d", &n);

	queue* q = initialize(n);

	printf("Available Operations:\n");
	printf("\t1. Insert Queue\n\t2. Delete Queue\n\t3. Display Queue\n\t4. Reverse Queue\n\t5. Exit\n");

	while(flag) {
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter the Element: ");
				scanf("%d", &ele);
				enqueue(q, ele);
				break;
			case 2:
				ele = dequeue(q);
				if(ele == -5555)
					printf("Queue Empty...\n");
				else
					printf("Removed %d from the Queue\n", ele);
				break;
			case 3:
				display(q);
				break;
			case 4:
				printf("Reversing the Queue....\n");
				reverse(q);
				break;
            case 5:
                flag = 0;
                break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	}
	
	free_queue(q);
	return 0;
}


queue* initialize(int size) {
    queue *q = (queue*) malloc(sizeof(queue));
    q->arr = (int *) calloc(size, sizeof(int));
    q->size = size;
    q->front = q->rear = 0;
    return q;
}

void enqueue(queue *q, int ele) {
	if((q->rear+1) % q->size == q->front) {
		printf("Queue Full\n");
		return;
	}
	q->rear = (q->rear+1) % q->size;
	q->arr[q->rear] = ele;
}

int dequeue(queue *q) {
	int x;
	if(empty(q)) {
		x = -5555;
	}
	else if((q->front+1)%q->size == q->rear) {
		x = q->arr[q->rear];
		q->front = q->rear = 0;
	}
	else {
		q->front = (q->front+1) % q->size;
		x = q->arr[q->front];
	}
	return x;
}

void display(queue *q) {
	if(empty(q)) {
		printf("Queue is Empty!!!\n");
		return;
	}
	printf("Queue is:\n");
	for(int i = (q->front+1)%q->size; i != q->rear; i = (i+1)%q->size) 
		printf("\t%d", q->arr[i]);
	printf("\t%d", q->arr[q->rear]);
	printf("\n");
}

int empty(queue* q) {
	return q->front == q->rear;
}

void reverse(queue* q) {
	if(empty(q)) 
		return;

	int f = dequeue(q);
	reverse(q);
	enqueue(q, f);
}

void free_queue(queue *q) {
	free(q->arr);
	free(q);
}
