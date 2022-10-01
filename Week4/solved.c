/* Solved Exercise
	Program to perform binary search on a set of keys.
*/

#include <stdio.h>
#include "binary_search_function.h"

void main() {
	int i, pos, a[30], n, item;
	printf("Enter number of items:");
	scanf("%d", &n);
	printf("Enter the elements in ascending order:\n");
	for(i = 0; i<n; i++)
		scanf("%d", &a[i]);
	printf("Enter element to be searched:");
	scanf("%d", &item);
	pos = bin_search(0, n-1, item, a);
	if(pos != -1)
		printf("Item found at location %d\n", pos+1);
	else
		printf("Item not found\n");
}
