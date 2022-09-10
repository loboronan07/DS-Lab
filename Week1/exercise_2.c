                                                                    
/* Implement an iterative Lsearch(….) function to search for an element in an 1D
	array of type integer using linear search technique. 
*/

#include<stdio.h>

int Lsearch(int array[], int n, int ele);

int main(void) {
	int array[10], n, ele, index;

	// Get the number of elements in the array from the user
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	// Get the elements 
	printf("Enter the elements of the array: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &array[i]);
	}

	// Prompt the user for the search element
	printf("Enter the search element: ");
	scanf("%d", &ele);

	// Get the index of the ele in the array using the function Lsearch
	index = Lsearch(array, n, ele);

	// If index exists, then print out the index
	if(index >= 0) {
		printf("The search element %d was found at index %d.\n", ele, index);
	}
	// Else print element not found
	else {
		printf("The search element %d was not found in the array.\n", ele);
	}

	return 0;
}

int Lsearch(int array[], int n, int ele) {
	/* This function uses the linear search technique to find the index of the 
		search element ele in the array.
		It return a negative value if the search element does not exist in the 
		array, else otherwise.
	*/
	// Initialize the index to negative value
	int index = -1;

	// Iterate through the elements of the array 
	for(int i=0; i<n; i++) {
		// If element is found, store the index and break out of the loop
		if(array[i] == ele) {
			index = i;
			break;
		}
		// Else continue the search
	}

	// Return the index found
	return index;
}