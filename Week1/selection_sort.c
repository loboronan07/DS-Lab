/* Write a C program to sort given list of n integers into ascending order using
	selection sort. Use function to sort.
*/

#include<stdio.h>
#include "selection_sort_fun.h"

int main(void) {
	int array[10];
	int i, j, n, temp;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	printf("Enter the elements: ");
	for(i = 0; i<n; i++) {
		scanf("%d", &array[i]);
	}
	/* Selection sorting begins */
	SelectionSort(array, n);
	printf("The sorted aray lsit is (using selection sort): ");
	for(i = 0; i < n; i++) {
		printf("%d  ", array[i]);
	}
	printf("\n");
}
