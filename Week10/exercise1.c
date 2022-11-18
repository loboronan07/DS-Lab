/* Lab Exercise 1
	Write a menu driven program to implement doubly linked list without header node
	to insert into and delete from both the sides.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
} node;

void insert(node**, int, int);
int delete(node**, int);
void display(node*);
void freell(node**);

int main(void) {
	int choice, ele;
	node* head = NULL;

	printf("Available Operations for the Linked List:");
	printf("\n\t1. Insert at Front");
	printf("\n\t2. Insert at End");
	printf("\n\t3. Delete at Front");
	printf("\n\t4. Delete at End");
	printf("\n\t5. Display Linked List");
	printf("\n\t6. Exit\n");

	while(1) {
		printf("\nEnter you Operation: ");
		scanf("%d", &choice);

		if(choice == 1 || choice == 2) {
			printf("Enter the value to insert: ");
			scanf("%d", &ele);
			if(choice == 1)
				insert(&head, ele, 0);
			else 
				insert(&head, ele, 1);
		}
		else if(choice == 3 || choice == 4) {
			ele = choice == 3 ? delete(&head, 0) : delete(&head, 1);
			if(ele != -5555) {
				printf("%d was deleted from the linked list...\n", ele);
			}
			else {
				printf("Linked list is Empty...\n");
			}
		}
		else if(choice == 5) {
			display(head);
		}
		else if(choice == 6) {
			break;
		}
		else {
			printf("Invalid Choice... Try Again..\n");
		}
	}
	freell(&head);
}


void insert(node** head, int ele, int end) {
	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;
	temp->prev = NULL;

	if(!end || *head == NULL) {
		temp->next = *head;
		if(*head)
			(*head)->prev = temp;
		*head = temp;
	}
	else {
		node *curr = *head;
		while(curr->next != NULL) {
			curr = curr->next;
		}

		curr->next = temp;
		temp->prev = curr;
	}
}

int delete(node** head, int end) {
	int ele;
	if(*head == NULL) {
		ele = -5555;
	}
	else if(!end || (*head)->next == NULL) {
		ele = (*head)->data;
		node* temp = *head;
		*head = (*head)->next;
		if(*head)
			(*head)->prev = NULL;
		free(temp);
	}
	else {
		node* curr = *head;
		while(curr->next) {
			curr = curr->next;
		}
		ele = curr->data;
		curr = curr->prev;
		free(curr->next);
		curr->next = NULL;
	}
	return ele;
}

void display(node* head) {
	if(head == NULL) {
		printf("Linked List is Empty...\n");
		return;
	}

	node* curr = head;

	printf("Linked List Contains:\n");
	while(curr != NULL) {
		printf("\t%d", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

void freell(node** head) {
	node *temp, *curr;
	curr = *head;

	while(curr != NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}

	*head = NULL;
}