/* Lab Exercise 3
	Create a circular singly linked LIST by merging two sorted singly circular linked
	lists containing char data, such that the final LIST is sorted
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* next;
} node;

node* getll();
void display(node*);
void insert(node**, char);
node* merge(node*, node*);
void freell(node*);

int main() {
	printf("Enter Data for Linked List A:\n");
	node* headA = getll();

	printf("Enter Data for Linked List B:\n");
	node* headB = getll();

	printf("\nElements of the Linked List Received:");
	printf("\nLinked List A:\n");
	display(headA);
	printf("Linked List B:\n");
	display(headB);

	node* headM = merge(headA, headB);

	printf("Merged Linked List:\n");
	display(headM);

	freell(headA);
	freell(headB);
	freell(headM);

	return 0;
}


node* getll() {
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	node *head, *temp;
	head = temp = (node*) malloc(sizeof(node));
	head->data = '\0';

	printf("Enter the character elements in sorted order: ");
	for(int i=0; i<n; i++) {
		temp->next = (node*) malloc(sizeof(node));
		temp = temp->next;
		scanf(" %c", &temp->data);
	}
	temp->next = head;

	return head;
}

void display(node* head) {
	if(head->next == head) {
		printf("Linked List is Empty!!!\n");
		return;
	}
	printf("Linked List Contains:\n");
	head = head->next;
	while(head->data != '\0') {
		printf("\t%c", head->data);
		head = head->next;
	}
	printf("\n");
}

void insert(node** head, char ele) {
	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;
	temp->next = *head;

	if((*head)->next == *head) 
		(*head)->next = temp;
	else {
		node* curr = (*head)->next, *prev;
		while(curr != *head && curr->data < ele) {
			prev = curr;
			curr = curr->next;
		}
		if(curr->data != ele) {
			prev->next = temp;
			temp->next = curr;
		}
	}
}

node* merge(node* A, node* B) {
	node *head;
	head = (node*) malloc(sizeof(node));
	head->data = '\0';
	head->next = head;
	A = A->next; B = B->next;

	while(A->data != '\0' && B->data != '\0') {
		if(A->data < B->data) {
			insert(&head, A->data);
			A = A->next;
		}
		else {
			insert(&head, B->data);
			B = B->next;
		}
	}
	while(A->data != '\0') {
		insert(&head, A->data);
		A = A->next;
	}
	while(B->data != '\0') {
		insert(&head, B->data);
		B = B->next;
	}

	return head;
}

void freell(node* head) {
	node* temp = head->next;
	node* curr;
	while(temp != head) {
		curr = temp;
		temp = temp->next;
		free(curr);
	}
	free(head);
}
