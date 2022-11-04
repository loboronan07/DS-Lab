/* Lab Exercise 1
	Implement an ascending priority queue.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 15

typedef struct {
	int arr[MAX];
	int front;
	int rear;
} apq;

apq* initialize();
void pqinsert(apq*, int);
int pqmindelete(apq*);

int main() {
	apq* q = initialize();
	int ch,flag = 1;
	int val;

	printf("Available Operations:\n");
	printf("\t1. Insert Queue\n\t2. Delete Queue\n\t3. Exit\n");

	while(flag) {
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Enter the element: ");
				scanf("%d", &val);
				pqinsert(q, val);
				break;
			case 2:
				val = pqmindelete(q);
				if(val == -5555)
					printf("Queue Empty...\n");
				else
					printf("Removed %d from the Queue\n", val);
				break;
			case 3:
				flag = 0;
				break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	}

	free(q);

	return 0;
}

apq* initialize() {
	apq* q = (apq*) malloc(sizeof(apq));
	q->front = q->rear = 0;
	return q;
}

void pqinsert(apq *q, int x) {
	if((q->rear+1)%MAX == q->front) {
		printf("Queue Full\n");
		return;
	}
	q->rear = (q->rear+1) % MAX;
	q->arr[q->rear] = x;
}

int pqmindelete(apq *q) {
	int x, pos;
	if(q->front == q->rear) {
		x = -5555;
	}
	else if((q->front+1)%MAX == q->rear) {
		x = q->arr[q->rear];
		q->front = q->rear = 0;
	}
	else {
		pos = (q->front+1)%MAX;
		for(int i = (q->front+1)%MAX; i != q->rear; i = (i+1)%MAX) 
			if(q->arr[i] < q->arr[pos])
				pos = i;
		if(q->arr[q->rear] < q->arr[pos])
			pos = q->rear;
		
		x = q->arr[pos];

		for(int i=pos; i != q->rear; i = (i+1)%MAX)
			q->arr[i] = q->arr[(i+1) % MAX];
		q->rear = (q->rear - 1 >= 0) ? q->rear-1 : MAX-1;
	}
	return x;
}

