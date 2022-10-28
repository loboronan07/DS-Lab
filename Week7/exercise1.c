/* Lab Exercise 1
	Implement a circular queue of Strings using structures. Include functions insertcq,
	deletecq and displaycq.
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
	char* arr[MAX];
	int front;
	int rear;
} cqueue;

void insertcq(cqueue *, char *);
void displaycq(cqueue *);
char* deletecq(cqueue *);
void freecq(cqueue *);


int main() {
	cqueue cq;
	cq.front = 0;
	cq.rear = 0;
	int ch,flag = 1;
	char ele[50];
	char* x;

	printf("Available Operations:\n");
	printf("\t1. Insert Queue\n\t2. Delete Queue\n\t3. Display Queue\n\t4. Exit\n");

	while(flag) {
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Enter the String Element: ");
				scanf(" %[^\n]s", ele);
				insertcq(&cq, ele);
				break;
			case 2:
				x = deletecq(&cq);
				if(x == NULL)
					printf("Queue Empty...\n");
				else {
					printf("Removed \"%s\" from the Queue\n", x);
					free(x);
				}
				break;
			case 3:
				displaycq(&cq);
				break;
			case 4:
				flag = 0;
				break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	}

	freecq(&cq);

	return 0;
}

void insertcq(cqueue *cq, char* ele) {
	if((cq->rear+1)%MAX == cq->front) {
		printf("Queue Full\n");
		return;
	}
	cq->rear = (cq->rear+1) % MAX;
	cq->arr[cq->rear] = (char*) calloc(strlen(ele)+1, sizeof(char));
	strcpy(cq->arr[cq->rear], ele);
}

char* deletecq(cqueue *cq) {
	char* x;
	if(cq->front == cq->rear) {
		x = NULL;
	}
	else if((cq->front+1)%MAX == cq->rear) {
		x = cq->arr[cq->rear];
		cq->arr[cq->rear] = NULL;
		cq->front = cq->rear = 0;
	}
	else {
		cq->front = (cq->front+1) % MAX;
		x = cq->arr[cq->front];
		cq->arr[cq->front] = NULL;
	}
	return x;
}

void displaycq(cqueue* cq) {
	if(cq->front == 0 && cq->rear == 0) {
		printf("Queue is Empty!!!\n");
		return;
	}
	
	printf("Queue is:\n");
	for(int i = (cq->front+1)%MAX; i != cq->rear; i = (i+1)%MAX) 
		printf("\t\"%s\"\n", cq->arr[i]);
	printf("\t\"%s\"", cq->arr[cq->rear]);
	printf("\n");
}

void freecq(cqueue* cq) {
	if(cq->front == 0 && cq->rear == 0) 
		return;
	for(int i = (cq->front+1)%MAX; i != cq->rear; i = (i+1)%MAX) 
		free(cq->arr[i]);
	free(cq->arr[cq->rear]);
}