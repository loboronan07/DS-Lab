/* Lab Exercise 1
	Implement a queue using singly linked list without header node.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

void enqueue(node**, int);
int dequeue(node**);
void display(node*);
void freell(node*);

int main() {
	node *head = NULL;
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
				enqueue(&head, ele);
				break;
			case 2:
				ele = dequeue(&head);
				if(ele == -5555)
					printf("Queue Empty...\n");
				else {
					printf("Removed %d from the Queue\n", ele);
				}
				break;
			case 3:
				display(head);
				break;
			case 4:
				flag = 0;
				break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	}

	freell(head);

	return 0;
}

void enqueue(node** head, int ele) {
	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;
	temp->next = NULL;

	if(*head == NULL) 
		*head = temp;
	else {
		node* last = *head;
		while(last->next != NULL) 
			last = last->next;
		last->next = temp;
	}
}

int dequeue(node** head) {
	int x;
	if(*head == NULL) 
		x = -5555;
	else {
		node* temp = *head;
		*head = (*head)->next;
		x = temp->data;
		free(temp);
	}
	return x;
}

void display(node* head) {
	if(head == NULL) {
		printf("Queue is Empty!!!\n");
		return;
	}
	printf("Queue is:\n");
	while(head != NULL) {
		printf("\t%d", head->data);
		head = head->next;
	}
	printf("\n");
}

void freell(node* head) {
	node* temp;
	while(head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}