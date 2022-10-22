/* Lab Exercise 3
	Write a function that takes a Queue and an element and returns true if the Queue
	contains this element or false if not. The elements in the Queue must remain in their
	original order once this method is complete. (use only queue operations)
*/

#include <stdio.h> 
#include <stdlib.h>

typedef struct {
	int *arr;
    int size;
	int front;
	int rear;
} cqueue;

void insertcq(cqueue *, int);
void displaycq(cqueue *);
int deletecq(cqueue *);
cqueue* initialize_cqueue(int);
void free_cqueue(cqueue *cq);
int searchcq(cqueue *cq, int ele);

int main() {
    int n, flag, ch, ele;
    
    printf("Enter the maximum size for the queue: ");
    scanf("%d", &n);

	cqueue* cq = initialize_cqueue(n);

	printf("Available Operations:\n");
	printf("\t1. Insert Queue\n\t2. Delete Queue\n\t3. Display Queue\n\t4. Search for Element\n\t5. Exit\n");

	while(flag) {
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter the Element: ");
				scanf("%d", &ele);
				insertcq(cq, ele);
				break;
			case 2:
				ele = deletecq(cq);
				if(ele == -5555)
					printf("Queue Empty...\n");
				else
					printf("Removed %d from the Queue\n", ele);
				break;
			case 3:
				displaycq(cq);
				break;
			case 4:
				printf("Enter the Element: ");
				scanf("%d", &ele);
                if(searchcq(cq, ele)) 
                    printf("%d was found in the queue....\n", ele);
                else   
                    printf("%d was not found in the queue....\n", ele);
				break;
            case 5:
                flag = 0;
                break;
			default:
				printf("\nWrong choice!!! Try Again.\n");
		}
	}
	
	free_cqueue(cq);
	return 0;
}


cqueue* initialize_cqueue(int size) {
    cqueue *cq = (cqueue*) malloc(sizeof(cqueue));
    cq->arr = (int *) calloc(size, sizeof(int));
    cq->size = size;
    cq->front = cq->rear = 0;
    return cq;
}

void insertcq(cqueue *cq, int ele) {
	if((cq->rear+1)%cq->size == cq->front) {
		printf("Queue Full\n");
		return;
	}
	cq->rear = (cq->rear+1) % cq->size;
	cq->arr[cq->rear] = ele;
}

int deletecq(cqueue *cq) {
	int x;
	if(cq->front == cq->rear) {
		return -5555;
	}
	else if((cq->front+1)%cq->size == cq->rear) {
		x = cq->arr[cq->rear];
		cq->front = cq->rear = 0;
		return x;
	}
	else {
		cq->front = (cq->front+1) % cq->size;
		return cq->arr[cq->front];
	}
}

void displaycq(cqueue *cq) {
	if(cq->front == 0 && cq->rear == 0) {
		printf("Queue is Empty!!!\n");
		return;
	}
	printf("Queue is:\n");
	for(int i = (cq->front+1)%cq->size; i != cq->rear; i = (i+1)%cq->size) 
		printf("\t%d", cq->arr[i]);
	printf("\t%d", cq->arr[cq->rear]);
	printf("\n");
}

int searchcq(cqueue *cq, int ele) {
    int flag = 0;
    cqueue *new = initialize_cqueue(cq->size);
    int x;
	
    for(x = deletecq(cq); x != -5555; x = deletecq(cq)) {
		if(!flag && ele == x)
			flag = 1;
		insertcq(new, x);
	}

	for(x = deletecq(new); x != -5555; x = deletecq(new)) 
		insertcq(cq, x);

	free_cqueue(new);

    return flag;
}

void free_cqueue(cqueue *cq) {
	free(cq->arr);
	free(cq);
}