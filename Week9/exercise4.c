/* Lab Exercise 4
	You're given the pointer to the head node of a sorted singly linked list, where the
	data in the nodes is in ascending order. Delete as few nodes as possible so that the
	list does not contain any value more than once (deleting duplicates). The given head
	pointer may be null indicating that the list is empty.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

void delduplicates(node*);
node* getll();
void display(node*);
void freell(node*);

int main() {
	node* head = getll();

	printf("Original Linked List:\n");
	display(head);

	delduplicates(head);

	printf("Linked List after Deleting Duplicates:\n");
	display(head);

	freell(head);

	return 0;
}

node* getll() {
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	node *head=NULL, *temp;

	printf("Enter the elements in sorted order: ");
	for(int i=0; i<n; i++) {
		if(head == NULL)
			head = temp = (node*) malloc(sizeof(node));
		else {
			temp->next = (node*) malloc(sizeof(node));
			temp = temp->next;
		}
		scanf("%d", &temp->data);
	}
	if(head)
		temp->next = NULL;

	return head;
}

void display(node* head) {
	if(head == NULL) {
		printf("Linked List is Empty!!!\n");
		return;
	}
	printf("Linked List Contains:\n");
	while(head != NULL) {
		printf("\t%d", head->data);
		head = head->next;
	}
	printf("\n");
}

void delduplicates(node* head) {
	node *curr;

	while(head != NULL) {
		curr = head->next;
		while(curr != NULL) {
			if(curr->data == head->data) { 
				head->next = curr->next;
				free(curr);
				curr = head->next;
			}
			else 
				break;
		}
		head = head->next;
	}
}

void freell(node* head) {
	node* temp;
	while(head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}