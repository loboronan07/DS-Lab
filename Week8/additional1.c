/* Additional Exercise 1
    Implement a queue of integers using an input restricted dequeue (no addRight).
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct {
	int* arr;
    int size;
	int front;
	int rear;
} dequeue;

void insert(dequeue *, int);
void display(dequeue *);
int delete(dequeue *, int);
void freeq(dequeue *);
dequeue* initialize(int);

int main() {
	int n, i, ch, ele, flag=1;

    printf("Enter the maximum size for the queue: ");
    scanf("%d", &n);

    dequeue* q = initialize(n);

	printf("Available Operations:\n");
	printf("\t1. Insert Queue\n\t2. Delete Queue\n\t3. Display Queue\n\t4. Exit\n");

	while(flag) {
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Enter the element to be inserted: ");
				scanf("%d", &ele);
				insert(q, ele);
				break;
			case 2:
                printf("Available Ends to Delete from:\n");
				printf("\t1. Front\t2. Rear\n");
				printf("Enter End: ");
				scanf("%d", &i);
                if(i != 1 && i != 2) {
					printf("Invalid Choice... Try Again...\n");
					continue;
				}
				ele = delete(q, i-1);
				if(ele == -5555)
					printf("Queue Empty...\n");
				else 
					printf("Removed %d from the Queue\n", ele);
				break;
			case 3:
				display(q);
				break;
			case 4:
				flag = 0;
				break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	}

	freeq(q);

	return 0;
}

dequeue* initialize(int size) {
    dequeue* q = (dequeue*) malloc(sizeof(dequeue));
    q->size = size+1;
    q->arr = (int *) calloc(q->size, sizeof(int));
    q->front = q->rear = 0;
    return q;
}

void insert(dequeue *q, int ele) {
	if((q->rear+1) % q->size == q->front) {
		printf("Queue Full\n");
		return;
	}
	q->rear = (q->rear+1) % q->size;
	q->arr[q->rear] = ele;
}

int delete(dequeue *q, int i) {
	int x;
	if(q->front == q->rear) {
		x = -5555;
	}
	else if((q->front+1) % q->size == q->rear) {
		x = q->arr[q->rear];
		q->front = q->rear = 0;
	}
	else {
		if(!i) {
			q->front = (q->front+1) % q->size;
			x = q->arr[q->front];
		}
		else {
			x = q->arr[q->rear];
			q->rear = (q->rear-1 >= 0) ? q->rear-1 : q->size-1;
		}
	}
	return x;
}

void display(dequeue* q) {
	if(q->front == 0 && q->rear == 0) {
		printf("Queue is Empty!!!\n");
		return;
	}
	
	printf("Queue is:\n");
	for(int i = (q->front+1)%q->size; i != q->rear; i = (i+1)%q->size) 
		printf("\t%d", q->arr[i]);
	printf("\t%d", q->arr[q->rear]);
	printf("\n");
}

void freeq(dequeue* q) {
	free(q->arr);
    free(q);
}