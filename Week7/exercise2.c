/* Lab Exercise 2
	Implement two circular queues of integers in a single array where first queue will
	run from 0 to N/2 and second queue will run from N/2+1 to N-1 where N is the size
	of the array.
*/

#include <stdio.h> 
#include <stdlib.h>

typedef struct {
	int* arr;
	int front[2];
	int rear[2];
	int bounds[3];
} cqueue2;

cqueue2* initialize_cqueue2(int);
void insertcq(cqueue2 *, int, int);
void displaycq(cqueue2 *, int);
int deletecq(cqueue2 *, int);

int main() {
	int n, ch, q, ele;

	printf("Enter the size of the array to be used as the queue: ");
	scanf("%d", &n);

	cqueue2 *cq = initialize_cqueue2(n);

	while(1) {
		printf("\nAvailable Queues:\n");
		printf("\t1. Queue 1\n\t2. Queue 2\n");
		printf("Enter Queue Choice(0 to exit): ");
		scanf("%d", &q);

		if(q == 0)
			break;

		if(q == 1 || q == 2) {
			printf("Available Operations:\n");
			printf("\t1. Insert Queue\n\t2. Delete Queue\n\t3. Display Queue\n");
			printf("Enter your choice(0 to exit): ");
			scanf("%d",&ch);

			if(ch == 0) 
				break;

			switch(ch) {
				case 1:
					printf("Enter the Element: ");
					scanf("%d", &ele);
					insertcq(cq, ele, q);
					break;
				case 2:
					ele = deletecq(cq, q);
					if(ele == -5555)
						printf("Queue Empty...\n");
					else
						printf("Removed %d from the Queue\n", ele);
					break;
				case 3:
					displaycq(cq, q);
					break;
				default:
					printf("\nWrong choice!!! Try Again.\n");
			}
		}	
		else 
			printf("Wrong Choice!!! Try Again.\n");
	}

	free(cq->arr);
	free(cq);

	return 0;
}


cqueue2* initialize_cqueue2(int size) {
	cqueue2* cq = (cqueue2 *) malloc(sizeof(cqueue2));
	cq->arr = (int *) calloc(size, sizeof(int));
	cq->front[0] = cq->rear[0] = cq->bounds[0] = 0;
	cq->front[1] = cq->rear[1] = cq->bounds[1] = size/2 + 1;
	cq->bounds[2] = size;
}

void insertcq(cqueue2* cq, int ele, int q) {
	if(cq->bounds[q-1]+(cq->rear[q-1]+1)%(cq->bounds[q]-cq->bounds[q-1]) == cq->front[q-1]) {
		printf("Queue Full\n");
		return;
	}
	cq->rear[q-1] = cq->bounds[q-1] + (cq->rear[q-1] + 1) % (cq->bounds[q] - cq->bounds[q-1]);
	cq->arr[cq->rear[q-1]] = ele;
}

int deletecq(cqueue2* cq, int q) {
	int x;

	if(cq->front[q-1] == cq->front[q-1]) 
		return -5555;
	else if(cq->bounds[q-1] + (cq->front[q-1]+1)%(cq->bounds[q]-cq->bounds[q-1]) == cq->rear[q-1]) {
		x = cq->arr[cq->rear[q-1]];
		cq->front[q-1] = cq->rear[q-1] = cq->bounds[q-1];
		return x;
	}
	else {
		cq->front[q-1] = cq->bounds[q-1] + (cq->front[q-1]+1) % (cq->bounds[q]-cq->bounds[q-1]);
		return cq->arr[cq->front[q-1]];
	}
}

void displaycq(cqueue2* cq, int q) {
	if(cq->front[q-1] == cq->bounds[q-1] && cq->rear[q-1] == cq->bounds[q-1]) {
		printf("Queue is Empty!!!\n");
		return;
	}

	printf("Queue is:\n");
	int i = cq->bounds[q-1] + (cq->front[q-1]+1)%(cq->bounds[q]-cq->bounds[q-1]);
	while(i != cq->rear[q-1]) {
		printf("\t%d", cq->arr[i]);
		i = cq->bounds[q-1] +(i+1)%(cq->bounds[q]-cq->bounds[q-1]);
	}
	printf("\t%d", cq->arr[cq->rear[q-1]]);
	printf("\n");
}