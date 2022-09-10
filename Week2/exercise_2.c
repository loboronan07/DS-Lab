/* Write a function Smallest to find the smallest element in an array using pointer.
	Create a dynamically allocated array and read the values from keyboard in main.
	Display the result in the main function.
*/
#include<stdio.h>
#include<stdlib.h>

int *Smallest(int *arr, int n);

int main(void) {
	int n, i;
	int *arr, *smallest;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	arr = (int *) calloc(n, sizeof(int));

	printf("Enter the elements of the array: \n");
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}

	smallest = Smallest(arr, n);

	printf("The smallest element of the array is %d.\n", *smallest);

	free(arr);

	return 0;
}

int *Smallest(int *arr, int n) {
	int *small = arr;
	arr++;
	for(int i=1; i<n; i++, arr++) {
		if(*arr < *small) {
			small = arr;
		}
	}
	return small;
}