/* Lab Exercise 2 
	Perform UNION and INTERSECTION set operations on singly linked lists with
	and without header node.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

node* getll();
void display(node*);
void freell(node*);
node* unionll(node*, node*);
node* intersectll(node*, node*);

int main() {
	printf("Linked List A:\n");
	node* headA = getll();

	printf("Linked List B:\n");
	node* headB = getll();

	printf("\nElements of the Linked List Received:");
	printf("\nLinked List A:\n");
	display(headA);
	printf("Linked List B:\n");
	display(headB);

	node* headU = unionll(headA, headB);
	node* headI = intersectll(headA, headB);

	printf("Elements of the Union and Intersection Linked Lists:\n");
	printf("Union of A and B:\n");
	display(headU);
	printf("Intersection of A and B:\n");
	display(headI);

	freell(headA);
	freell(headB);
	freell(headU);
	freell(headI);

	return 0;
}


node* getll() {
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	node *head=NULL, *temp;

	printf("Enter the elements: ");
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

void freell(node* head) {
	node* temp;
	while(head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

node* unionll(node* A, node* B) {
	node *curr;
	node *head = NULL, *temp;
	int flag;
	while(A != NULL) {
		flag = 1;
		for(curr = head; curr != NULL; curr = curr->next)
			if(curr->data == A->data) {
				flag = 0;
				break;
			}

		if(flag) {
			if(head == NULL) 
				head = temp = (node*) malloc(sizeof(node));
			else {
				temp->next = (node*) malloc(sizeof(node));
				temp = temp->next;
			}
			temp->data = A->data;
		}

		A = A->next;
	}
	while(B != NULL) {
		flag = 1;
		for(curr = head; curr != NULL; curr = curr->next)
			if(curr->data == B->data) {
				flag = 0;
				break;
			}

		if(flag) {
			if(head == NULL) 
				head = temp = (node*) malloc(sizeof(node));
			else {
				temp->next = (node*) malloc(sizeof(node));
				temp = temp->next;
			}
			temp->data = B->data;
		}

		B = B->next;
	}
	if(head) 
		temp->next = NULL;

	return head;
}

node* intersectll(node* A, node* B) {
	node *curr;
	node *head = NULL, *temp;
	int flag;
	while(A != NULL) {
		flag = 0;
		for(curr = B; curr != NULL; curr = curr->next)
			if(curr->data == A->data) {
				flag = 1;
				break;
			}
		for(curr = head; curr != NULL; curr = curr->next)
			if(curr->data == A->data) {
				flag = 0;
				break;
			}

		if(flag) {
			if(head == NULL) 
				head = temp = (node*) malloc(sizeof(node));
			else {
				temp->next = (node*) malloc(sizeof(node));
				temp = temp->next;
			}
			temp->data = A->data;
		}

		A = A->next;
	}
	if(head) 
		temp->next = NULL;

	return head;
}