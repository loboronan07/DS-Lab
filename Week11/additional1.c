/* Additional Exercise 1
    Implement trees using arrays.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30 

typedef struct {
    char *arr;
    int size;
    int levels;
} tree;

typedef struct {
	int arr[MAX];
	int tos;
} stack;

tree* initialize();
void extend(tree*);
void insert(tree*, char, int);
tree* create();
void inorder(tree*);
void freetree(tree*);
int pop(stack*);
void push(stack*, int);

int main() {
    printf("Enter data for the tree as specified...\n");
    tree* t = create();

    printf("\nInorder Traversal of the tree: ");
    inorder(t);

    freetree(t);

    return 0;
}

tree* initialize() {
    tree* t = (tree*) malloc(sizeof(tree));
    t->arr = (char*) calloc(1, sizeof(char));
    t->size = 1;
    t->levels = 0;
    return t;
}

void extend(tree* t) {
    char *temp = (char*) calloc(t->size*2, sizeof(char));

    for(int i=0; i<t->size; i++)
        temp[i] = t->arr[i];

    free(t->arr);

    t->arr = temp;
    t->levels += 1;
    t->size *= 2;
}

void insert(tree* t, char ele, int pos) {
    if(pos >= t->size)
        extend(t);
    
    t->arr[pos] = ele;
}

tree* create() {
    tree* t = initialize();
    char ele;
    
    printf("Enter data for root(Hit # to exit): ");
    scanf(" %c", &ele);

    if(ele != '#') {
        int i=1;
        insert(t, ele, i);

        while(i < t->size ) {
            if(t->arr[i]) {
                printf("Enter the left child of %c(Hit # to exit): ", t->arr[i]);
                scanf(" %c", &ele);
                if(ele != '#') 
                    insert(t, ele, i*2);

                printf("Enter the right child of %c(Hit # to exit): ", t->arr[i]);
                scanf(" %c", &ele);
                if(ele != '#') 
                    insert(t, ele, i*2 + 1);
            }
            i++;
        }
    }

    return t;
}

void inorder(tree* t) {
    if(t->levels == 0) {
        printf("Tree is Empty...\n");
        return;
    }

    int flag = 0;

    stack s;
    s.tos = -1;
	int curr = 1;

    while(!flag) {
		while(curr < t->size && t->arr[curr]) {
			push(&s, curr);
			curr = curr*2;
		}

		if(curr = pop(&s)) {
			printf("%c ", t->arr[curr]);
			curr = curr*2 +1;
		}
		else 
			flag = 1;
	}
}

void freetree(tree* t) {
    free(t->arr);
    free(t);
}

int pop(stack* s) {
    if(s->tos == -1)
        return 0;
    return s->arr[(s->tos)--];
}

void push(stack* s, int ele) {
    s->arr[++(s->tos)] = ele;
}