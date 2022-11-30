/* Lab Exercise 4
	Given two polynomials, write a program to perform the following operations on
	singly circular linked list with header node. Use menu driven approach to input two
	polynomials, subtract, multiply and display the result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	int exp;
	int coeff;
	struct node* next;
} node;

node* getnode(int, int);
node* getpoly();
node* subtract(node*, node*);
node* multiply(node*, node*);
void display(node*);
void freell(node*);

int main(void) {
	printf("Enter the data for the first polynomial:\n");
	node* headA = getpoly();

	printf("Enter the data for the second polynomial:\n");
	node* headB = getpoly();

	printf("\nEntered Polynomials:\n");
	printf("Poly A = ");
	display(headA);
	printf("Poly B = ");
	display(headB);

	node* sub = subtract(headA, headB);
	node* mul = multiply(headA, headB);

	printf("\nPoly A - Poly B = ");
	display(sub);

	printf("Poly A * Poly B = ");
	display(mul);

	freell(headA);
	freell(headB);
	freell(sub);
	freell(mul);

	return 0;
}

node* getnode(int exp, int coeff) {
	node* new = (node*) malloc(sizeof(node));
	new->exp = exp;
	new->coeff = coeff;
	new->next = NULL;
	return new;
}

node* getpoly() {
	node* head = getnode(-1, 0);
	head->next = head;

	node* temp = NULL;
	int coeff, exp;

	printf("Enter the polynomial in decreasing order of exponent(Press -1 to exit):\n");
	printf("Enter the exponent and coeff:\n");
	while(1) {
		scanf("%d", &exp);

		if(exp == -1) 
			break;

		scanf("%d", &coeff);

		if(coeff == 0)
			continue;

		if(head->next == head) 
			head->next = temp = getnode(exp, coeff);
		else {
			temp->next = getnode(exp, coeff);
			temp = temp->next;
		}
	}
	if(temp) 
		temp->next = head;

	return head;
}

void display(node* head) {
	if(head->next == head) {
		printf("0\n");
		return;
	}

	node* curr = head->next;

	if(curr->exp != -1) 
		if(curr->coeff < 0)
			printf("- ");

	while(curr->exp != -1) {
		if(curr->exp != 0)
			printf("%d x^%d", abs(curr->coeff), curr->exp);
		else 
			printf("%d", abs(curr->coeff));
		curr = curr->next;
		if(curr->exp != -1) 
			printf(" %c ", curr->coeff > 0 ? '+' : '-');
	}
	printf("\n");
}

node* subtract(node* A, node* B) {
	node* head = getnode(-1, 0);
	head->next = head;

	node* temp;
	A = A->next;
	B = B->next;

	while(A->exp != -1 || B->exp != -1)	{
		if(head->next == head) 
			head->next = temp = (node*) malloc(sizeof(node));
		else {
			temp->next = (node*) malloc(sizeof(node));
			temp = temp->next;
		}

		if(A->exp > B->exp) {
			temp->exp = A->exp;
			temp->coeff = A->coeff;
			A = A->next;
		}
		else if(A->exp == B->exp) {
			if(A->exp == -1)
				break;
			temp->exp = A->exp;
			temp->coeff = A->coeff - B->coeff;
			A = A->next;
			B = B->next;
		}
		else {
			temp->exp = B->exp;
			temp->coeff = - B->coeff;
			B = B->next;
		}
	}
	if(temp) 
		temp->next = head;

	node* curr = head->next, *prev = head;

	while(curr->exp != -1) {
		if(curr->coeff == 0) {
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}

	return head;
}

node* multiply(node* A, node* B) {
	node* head = getnode(-1, 0);
	head->next = head;

	node* temp = NULL;

	A = A->next;
	B = B->next;

	while(A->exp != -1) {
		while(B->exp != -1) {
			if(head->next == head)
				head->next = temp = getnode(A->exp+B->exp, A->coeff * B->coeff);
			else {
				temp->next = getnode(A->exp+B->exp, A->coeff * B->coeff);
				temp = temp->next;
			}
			B = B->next;
		}
		B = B->next;
		A = A->next;
	}
	if(temp)
		temp->next = head;

	node* pivot = head->next;
	node* curr, *prev = NULL;

	while(pivot->exp != -1) {
		curr = pivot->next;
		prev = pivot;
		while(curr->exp != -1) {
			if(curr->exp == pivot->exp) {
				pivot->coeff += curr->coeff;
				prev->next = curr->next;
				free(curr);
				curr = prev->next;
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
		pivot = pivot->next;
	}

	return head;
}

void freell(node* head) {
	node* curr = head->next;
	node* temp;
	while(curr != head) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(head);
}