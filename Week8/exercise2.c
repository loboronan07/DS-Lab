/* Lab Exercise 2
	Implement a queue of strings using an output restricted dequeue (no deleteRight).
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
	char* arr[MAX];
	int front;
	int rear;
} dequeue;

void insert(dequeue *, char *, int);
void display(dequeue *);
char* delete(dequeue *);
void freeq(dequeue *);

int main() {
	dequeue* q = (dequeue*) malloc(sizeof(dequeue));
	q->front = q->rear = 0;
	int ch, i, flag = 1;
	char ele[50];
	char* x;

	printf("Available Operations:\n");
	printf("\t1. Insert Queue\n\t2. Delete Queue\n\t3. Display Queue\n\t4. Exit\n");

	while(flag) {
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Available Ends to Insert at:\n");
				printf("\t1. Front\t2. Rear\n");
				printf("Enter End: ");
				scanf("%d", &i);
				if(i != 1 && i != 2) {
					printf("Invalid Choice... Try Again...\n");
					continue;
				}
				printf("Enter the String Element: ");
				scanf(" %[^\n]s", ele);
				insert(q, ele, i-1);
				break;
			case 2:
				x = delete(q);
				if(x == NULL)
					printf("Queue Empty...\n");
				else {
					printf("Removed \"%s\" from the Queue\n", x);
					free(x);
				}
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

void insert(dequeue *q, char* ele, int i) {
	if((q->rear+1)%MAX == q->front) {
		printf("Queue Full\n");
		return;
	}

	int pos;
	if(!i) {
		pos = q->front;
		q->front = (q->front-1 >= 0) ? q->front-1 : MAX-1;
	}
	else 
		q->rear = pos = (q->rear+1) % MAX;

	q->arr[pos] = (char*) calloc(strlen(ele)+1, sizeof(char));
	strcpy(q->arr[pos], ele);
}

char* delete(dequeue *q) {
	char* x;
	if(q->front == q->rear) {
		x = NULL;
	}
	else if((q->front+1)%MAX == q->rear) {
		x = q->arr[q->rear];
		q->arr[q->rear] = NULL;
		q->front = q->rear = 0;
	}
	else {
		q->front = (q->front+1) % MAX;
		x = q->arr[q->front];
		q->arr[q->front] = NULL;
	}
	return x;
}

void display(dequeue* q) {
	if(q->front == q->rear) {
		printf("Queue is Empty!!!\n");
		return;
	}
	
	printf("Queue is:\n");
	for(int i = (q->front+1)%MAX; i != q->rear; i = (i+1)%MAX) 
		printf("\t\"%s\"\n", q->arr[i]);
	printf("\t\"%s\"", q->arr[q->rear]);
	printf("\n");
}

void freeq(dequeue* q) {
	if(q->front == q->rear) {
		free(q)
		return;
	}
	for(int i = (q->front+1)%MAX; i != q->rear; i = (i+1)%MAX) 
		free(q->arr[i]);
	free(q->arr[q->rear]);
	free(q);
}
