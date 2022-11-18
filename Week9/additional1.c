/* Additional Exercise 1
	Write a program to implement the Josephus Circle Problem: There are n people
	standing in a circle waiting to be executed. The counting out begins at some point
	in the circle and proceeds around the circle in a fixed direction. In each step, a
	certain number of people are skipped and the next person is executed. The
	elimination proceeds around the circle (which is becoming smaller and smaller as
	the executed people are removed), until only the last person remains, who is given
	freedom. Given the total number of persons, n and a number m which indicates that
	m-1 persons are skipped and m th person is killed in circle. The task is to choose the
	place in the initial circle so that you are the last one remaining and so survive.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

node* getll(int);
void delete(node**, int);


int main() {
	int n, m;
	printf("Enter the number of people, n: ");
	scanf("%d", &n);

	node* head = getll(n);

	printf("Enter the number of people skipped in each iteration, m: ");
	scanf("%d", &m);

	delete(&head, m);

	printf("The last person remaining is at position %d from the 1st person...\n", head->data);

	free(head);

	return 0;
}


node* getll(int n) {
	node *head=NULL, *temp;

	for(int i=0; i<n; i++) {
		if(head == NULL)
			head = temp = (node*) malloc(sizeof(node));
		else {
			temp->next = (node*) malloc(sizeof(node));
			temp = temp->next;
		}
		temp->data = i+1;
	}
	temp->next = head;

	return head;
}

void delete(node **head, int m) {
	node *curr, *prev;
	curr = prev = *head;
	while((*head)->next != *head) {
		for(int i=0; i<m-1; i++) {
			prev = curr;
			curr = curr->next;
		}
		if(*head == curr) {
			*head = (*head)->next;
			prev->next = *head;
			free(curr);
			curr = *head;
		}
		else {
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
		}
	}
}

