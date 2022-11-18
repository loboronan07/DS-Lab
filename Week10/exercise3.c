/* Lab Exercise 3
	Reverse a doubly linked list containing words in the data field.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char* str;
	struct node* next;
	struct node* prev;
} node;

node* initialize();
void reverse(node**);
void display(node*);
void freell(node**);

int main(void) {
	node* head = initialize();

	printf("Original Linked List Contains:\n");
	display(head);

	reverse(&head);

	printf("After Reversing Linked List Contains:\n");
	display(head);

	freell(&head);

	return 0;
}

node* initialize() {
	int n;
	char str[20];
	node* head = NULL;
	node* temp;

	printf("Enter the number of nodes in the Linked List: ");
	scanf("%d", &n);

	printf("Enter the data for the nodes:\n");
	for(int i=0; i<n; i++) {
		if(!head) {
			head = temp = (node*) malloc(sizeof(node));
			head->prev = NULL;
		}
		else {
			temp->next = (node*) malloc(sizeof(node));
			temp->next->prev = temp;
			temp = temp->next;
		}

		printf("Enter the word for Node %d: ", i+1);
		scanf("%s", str);

		temp->str = (char*) calloc(strlen(str) + 1, sizeof(char));
		strcpy(temp->str, str);
	}
	temp->next = NULL;

	return head;
}

void reverse(node** head) {
	node *curr, *temp, *prev;

	if(*head == NULL) 
		return;

	curr = *head;
	while(curr != NULL) {
		temp = curr->next;
		curr->next = curr->prev;
		curr->prev = temp;

		prev = curr;
		curr = curr->prev;
	}

	*head = prev;
}

void display(node* head) {
	if(head == NULL) {
		printf("Linked List is Empty...\n");
		return;
	}

	node* curr = head;

	printf("Linked List Contains:");
	while(curr != NULL) {
		printf("\n\t%s", curr->str);
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
		free(temp->str);
		free(temp);
	}

	*head = NULL;
}