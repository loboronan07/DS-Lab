/* Find the 2nd largest in a list of numbers using a function (do not sort the list). */
#include<stdio.h>
#include<stdlib.h>

int Second_Largest(int array[], int n);

int main(void) {
	int array[10], n, second_large;

	// Prompt the user for the number of elements
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	// Read the array elements
	printf("Enter the elements of the array: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &array[i]);
	}


	// Check if the second largest value is defined for the array
	if(n < 2) {
		printf("Cannot find second largest element of an array with size %d.\n", n);
		exit(1);
	}

	// Find the second largest element in the array using the function
	second_large = Second_Largest(array, n);

	// Display the number 
	printf("The second largest element of the array is %d.\n", second_large);

	return 0;
}

int Second_Largest(int array[], int n) {
	/* Function to find the second largest element of a given array of size n. */
	int largest, second_large;

	// Initialize the largest and second_large variable with appropriate values from the array
	if(array[0] > array[1]) {
		largest = array[0];
		second_large = array[1];
	}
	else {
		largest = array[1];
		second_large = array[0];
	}

	// Iterate through the array
	for(int i=2; i<n; i++) {
		if(array[i] > largest) { // Check if the current element is the largest
			second_large = largest;
			largest = array[i];
		}
		else if(array[i] > second_large) { // If not the largest, check with the second_large value
			second_large = array[i];
		}
	}

	// Return the value found
	return second_large;
}
