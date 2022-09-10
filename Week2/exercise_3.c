/* Write a C program to
	a) Demonstrate passing pointers to a function.
	b) Demonstrate Returning pointer from a function.
	c) Using pointer to pointer.
*/
#include<stdio.h>
#include<stdlib.h>

int *allocate(int n);
float average(int *arr, int n);
void printandfree(int **p, int n);
int main(void) {
	int n, i;
	int *arr;
	float avg;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	arr = allocate(n);

	printf("Enter the elements of the array: \n");
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}

	avg = average(arr, n);

	printf("The average of the elements of the array is %.2f.\n", avg);

	printandfree(&arr, n);

	printf("\n");
	
	return 0;
}

float average(int *arr, int n) {
	float sum = 0;
	for(int i=0; i<n; i++) {
		sum += *(arr + i);
	}
	return sum / n;
}

int *allocate(int n) {
	return (int *) calloc(n, sizeof(n));
}

void printandfree(int **p, int n) {
	printf("The elements of the array are: ");
	for(int i=0, *ptr = *p; i<n; i++, ptr++) {
		printf("%d ", *ptr);
	}

	free(*p);
}