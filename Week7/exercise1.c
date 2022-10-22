/* Lab Exercise 1
	Implement a circular queue of Strings using structures. Include functions insertcq,
	deletecq and displaycq.
*/

#include <stdio.h> 
#include <stdlib.h>
#define MAX 10

typedef struct {
	int arr[MAX];
	int front;
	int rear;
} cqueue;

void insertcq(cqueue *, int);
void displaycq(cqueue);
int deletecq(cqueue *);


int main() {
	cqueue cq;
	cq.front = 0;
	cq.rear = 0;
	int ch,x,flag = 1;

	printf("Available Operations:\n");
	printf("\t1. Insert Queue\n\t2. Delete Queue\n\t3. Display Queue\n\t4. Exit\n");

	while(flag) {
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Enter the Element: ");
				scanf("%d", &x);
				insertcq(&cq, x);
				break;
			case 2:
				x = deletecq(&cq);
				if(x == -5555)
					printf("Queue Empty...\n");
				else
					printf("Removed %d from the Queue\n", x);
				break;
			case 3:
				displaycq(cq);
				break;
			case 4:
				flag = 0;
				break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	}
	return 0;
}

void insertcq(cqueue *cq, int ele) {
	if((cq->rear+1)%MAX == cq->front) {
		printf("Queue Full\n");
		return;
	}
	cq->rear = (cq->rear+1) % MAX;
	cq->arr[cq->rear] = ele;
}

int deletecq(cqueue *cq) {
	int x;
	if(cq->front == cq->rear) {
		return -5555;
	}
	else if((cq->front+1)%MAX == cq->rear) {
		x = cq->arr[cq->rear];
		cq->front = cq->rear = 0;
		return x;
	}
	else {
		cq->front = (cq->front+1) % MAX;
		return cq->arr[cq->front];
	}
}

void displaycq(cqueue cq) {
	if(cq.front == 0 && cq.rear == 0) {
		printf("Queue is Empty!!!\n");
		return;
	}
	
	printf("Queue is:\n");
	for(int i = (cq.front+1)%MAX; i != cq.rear; i = (i+1)%MAX) 
		printf("\t%d", cq.arr[i]);
	printf("\t%d", cq.arr[cq.rear]);
	printf("\n");
}