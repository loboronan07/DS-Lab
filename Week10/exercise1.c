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

void insertf(node**, int);
void inserte(node**, int);
int deletef(node**);
int deletee(node**);
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

		if(choice == 1) {
			printf("Enter the value to insert: ");
			scanf("%d", &ele);

			insertf(&head, ele);
		}
		else if(choice == 2) {
			printf("Enter the value to insert: ");
			scanf("%d", &ele);

			inserte(&head, ele);
		}
		else if(choice == 3) {
			ele = deletef(&head);
			if(ele != -5555) {
				printf("%d was deleted from the linked list...\n", ele);
			}
			else {
				printf("Linked list is Empty...\n");
			}
		}
		else if(choice == 4) {
			ele = deletee(&head);
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


void insertf(node** head, int ele) {
	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;
	temp->next = *head;
	temp->prev = NULL;
	if(*head)
		(*head)->prev = temp;
	*head = temp;
}


void inserte(node** head, int ele) {
	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;
	temp->next = NULL;

	if(*head == NULL) {
		*head = temp;
		temp->prev = NULL;
		return;
	}

	node *curr;
	curr = *head;

	while(curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = temp;
	temp->prev = curr;
}

int deletef(node** head) {
	int ele;
	if(*head == NULL) {
		ele = -5555;
	}
	else {
		ele = (*head)->data;
		node* temp = *head;
		*head = (*head)->next;
		if(*head)
			(*head)->prev = NULL;
		free(temp);
	}
	return ele;
}

int deletee(node** head) {
	int ele;
	if(*head == NULL) {
		ele = -5555;
	}
	else if((*head)->next == NULL) {
		ele = (*head)->data;
		free(*head);
		*head = NULL;
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