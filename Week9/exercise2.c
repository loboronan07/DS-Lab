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
void insert(node**, int);
void delduplicates(node*);
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
	int n, ele;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	node *head=NULL, *temp;

	printf("Enter the elements: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &ele);
		insert(&head, ele);
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

void insert(node** head, int ele) {
	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;
	temp->next = NULL;

	if(*head == NULL) 
		*head = temp;
	else {
		node* curr = *head;
		while(curr->next != NULL) 
			curr = curr->next;
		curr->next = temp;
	}
}

void delduplicates(node* head) {
	node *curr, *prev;

	while(head != NULL) {
		prev = head;
		curr = head->next;
		while(curr != NULL) {
			if(curr->data == head->data) { 
				prev->next = curr->next;
				free(curr);
				curr = prev->next;
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
		head = head->next;
	}
}

node* unionll(node* A, node* B) {
	node *head = NULL;
	while(A != NULL) {
		insert(&head, A->data);
		A = A->next;
	}
	while(B != NULL) {
		insert(&head, B->data);
		B = B->next;
	}

	delduplicates(head);

	return head;
}

node* intersectll(node* A, node* B) {
	node *head = NULL, *curr;
	int flag;
	while(A != NULL) {
		flag = 0;
		for(curr = B; curr != NULL; curr = curr->next)
			if(curr->data == A->data) {
				flag = 1;
				break;
			}
		if(flag) {
			insert(&head, A->data);
		}

		A = A->next;
	}

	delduplicates(head);

	return head;
}