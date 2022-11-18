/* Lab Exercise 1
	Implement a queue using singly linked list without header node.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} queue;

queue* initialize();
void enqueue(queue*, int);
int dequeue(queue*);
void display(queue*);
void freeq(queue*);

int main() {
    queue* q = initialize();
	int ch, flag=1, ele;

	printf("Available Operations:\n");
	printf("\t1. Insert Queue\n\t2. Delete Queue\n\t3. Display Queue\n\t4. Exit\n");

	while(flag) {
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
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
				else {
					printf("Removed %d from the Queue\n", ele);
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
	free(q);
	return 0;
}

queue* initialize() {
    queue* q = (queue*) malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(queue* q, int ele) {
	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;
	temp->next = NULL;

	if(q->rear == NULL) 
		q->front = q->rear = temp;
	else {
		q->rear->next = temp;
        q->rear = temp;
	}
}

int dequeue(queue* q) {
	int x;
	if(q->front == NULL) 
		x = -5555;
	else {
		node* temp = q->front;
		if(q->front->next == NULL) 
            q->front = q->rear = NULL;
        else   
            q->front = q->front->next;
		x = temp->data;
		free(temp);
	}
	return x;
}

void display(queue* q) {
	if(q->front == NULL) {
		printf("Queue is Empty!!!\n");
		return;
	}
    node* temp = q->front;
	printf("Queue is:\n");
	while(temp != NULL) {
		printf("\t%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void freeq(queue* q) {
    node* temp;
	node* curr = q->front;
	while(curr != NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}
}
