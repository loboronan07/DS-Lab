/* Lab Exercise 2
	Add two long positive integers represented using circular doubly linked list with
	header node.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	short digit;
	struct node* next;
	struct node* prev;
} node;

node* getlong();
node* add(node*, node*);
void display(node*);
void freell(node*);

int main(void) {
	printf("Enter the First Number: ");
	node* num1 = getlong();

	printf("Enter the Second Number: ");
	node* num2 = getlong();

	printf("\nFirst Number: ");
	display(num1);
	printf("Second Number: ");
	display(num2);

	node* sum = add(num1, num2);

	printf("\nSum of the Two Numbers: ");
	display(sum);

	freell(num1);
	freell(num2);
	freell(sum);

	return 0;
}	

node* getlong() {
	char digit;

	node* head = (node*) malloc(sizeof(node));
	head->digit = -1;
	head->next = head;
	head->prev = head;

	node* temp = NULL;

	while(1) {
		scanf("%c", &digit);
		if(digit == '\n') 
			break;

		if(head->next == head) {
			head->next = temp = (node*) malloc(sizeof(node));
			temp->prev = head;
		}
		else {
			temp->next = (node*) malloc(sizeof(node));
			temp->next->prev = temp;
			temp = temp->next;
		}

		temp->digit = digit - '0';
	}
	if(temp) {
		temp->next = head;
		head->prev = temp;
	}

	return head;
}

void display(node* head) {
	node* curr = head->next;

	while(curr->digit != -1) {
		printf("%d", curr->digit);
		curr = curr->next;
	}
	printf("\n");
}

node* add(node* n1, node* n2) {
	node* head = (node*) malloc(sizeof(node));
	head->digit = -1;
	head->next = head;
	head->prev = head;

	n1 = n1->prev;
	n2 = n2->prev;

	node* temp = NULL;
	short carry = 0;

	while(n1->digit != -1 || n2->digit != -1 || carry) {
		if(head->prev == head) {
			head->prev = temp = (node*) malloc(sizeof(node));
			temp->next = head;
		}
		else {
			temp->prev = (node*) malloc(sizeof(node));
			temp->prev->next = temp;
			temp = temp->prev;
		}

		if(n1->digit != -1 && n2->digit != -1) {
			temp->digit = n1->digit + n2->digit + carry;
			n1 = n1->prev;
			n2 = n2->prev;
		}
		else if(n1->digit != -1) {
			temp->digit = n1->digit + carry;
			n1 = n1->prev;
		}
		else if(n2->digit != -1) {
			temp->digit = n2->digit + carry;
			n2 = n2->prev;
		}
		else {
			temp->digit = carry;
		}
		carry = temp->digit / 10;
		temp->digit = temp->digit % 10;
	}
	temp->prev = head;
	head->next = temp;

	return head;
}


void freell(node* head) {
	node *temp, *curr;
	curr = head->next;

	while(curr->digit != -1) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}

	free(head);
}