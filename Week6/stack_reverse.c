/* Additional Exercise 2
    Reverse a stack using recursion [Note: Only the IsEmpty, Push and Pop operations
    are allowed on stack]
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int tos;
    int size;
} stack;

stack* initialize_stack(int size);
int IsEmpty(stack *s);
void Push(stack *s, int ele);
int Pop(stack *s);
void display(stack *s);
void reverse_stack(stack* destination, stack* source);
void free_stack(stack *s);

int main() {
    int size;
    int choice, ele;

    printf("Enter the maximum of elements in the array: ");
    scanf("%d", &size);

    stack *s = initialize_stack(size);

    printf("Available Operations on Stack:\n");
    printf("\t1. Push\n");
    printf("\t2. Pop\n");
    printf("\t3. Display Stack Elements\n");
    printf("\t4. Move to Reversing Stack\n");

    while(1) {
        printf("Enter Operation: ");
        scanf("%d", &choice);
        
        if(choice == 4) {
            break;
        }

        switch(choice) {
            case 1: 
                printf("Enter element to be pushed: ");
                scanf("%d", &ele);
                Push(s, ele);
                break;
            case 2:
                ele = Pop(s);
                if(ele == -5555) 
                    printf("Stack Empty...\n");
                else 
                    printf("%d was popped from the stack...\n", ele);
                break;
            case 3:
                printf("Stack Elements:\n");
                display(s);
                break;
            default:
                printf("Please enter a valid operation... Try Again...\n");
                break;
        }
    }

    printf("\nElements in the original stack:\n");
    display(s);

    stack *rev = initialize_stack(size);

    printf("\nReversing the elements of the stack...\n");
    reverse_stack(rev, s);

    printf("\nElements in the reversed stack:\n");
    display(rev);

    free_stack(s);
    free_stack(rev);

    return 0;
}

stack* initialize_stack(int size) {
    stack *s = (stack*) malloc(sizeof(stack));
    s->arr = (int*) calloc(size, sizeof(int));
    s->size = size;
    s->tos = -1;
    return s;
}

int IsEmpty(stack *s) {
    return (s->tos == -1) ? 1:0;
}

void Push(stack *s, int ele) {
    if(s->tos == s->size - 1) {
        printf("Stack Full...\n");
        return;
    }
    s->arr[++(s->tos)] = ele;
}

int Pop(stack *s) {
    if(IsEmpty(s)) {
        return -5555;
    }
    return s->arr[s->tos--];
}

void display(stack *s) {
    if(IsEmpty(s)) {
        printf("Stack Empty...\n");
        return;
    }
    for(int i=0; i<=s->tos; i++) 
        printf("\t%d", s->arr[i]);
    printf("\n");
}

void reverse_stack(stack* destination, stack* source) {
    if(!IsEmpty(source)) {
        Push(destination, Pop(source));
        reverse_stack(destination, source);
    }
}

void free_stack(stack *s) {
    free(s->arr);
    free(s);
}