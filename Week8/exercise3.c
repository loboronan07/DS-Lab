/* Lab Exercise 3
	Write a program to check whether given string is a palindrome using a dequeue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* arr;
	int front;
	int rear;
	int size;
} dequeue;

int isPalin(char *);
void insert(dequeue *, char);
char* delete(dequeue *, int);
void freeq(dequeue *);

int main() {
	char str[100];

	printf("Enter a Sting: ");
	scanf("%[^\n]s", str);

	if(isPalin(str)) 
		printf("The entered string is a palindrome...\n");
	else 
		printf("The entered string is not a palindrome...\n");

	return 0;
}

int isPalin(char* str) {
	dequeue* q = (dequeue*) malloc(sizeof(dequeue));
	q->size = strlen(str) + 1;
	q->front = q->rear = 0;
	q->arr = (char*) calloc(q->size, sizeof(char));

	while(str != '\0') 
		insert(q, *str);

	int flag = 1;
	char f, r;
	
}

void insert(dequeue *q, char ele, int i) {
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

char delete(dequeue *q) {
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
	if(q->front == 0 && q->rear == 0) {
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
	free(q->arr);
	free(q);
}