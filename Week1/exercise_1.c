#include<stdio.h>

double Sum(double array[], int n);

int main(void) {
	double array[10], sum;
	int n;

	// Get input for n from user
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	// Get the elements from user
	printf("Enter the elements of the array: ");
	for(int i=0; i<n; i++) {
		scanf("%lf", &array[i]);
	}

	// Get the sum of elements of the aray using Sum function
	sum = Sum(array, n);

	// Print the calculated sum
	printf("The sum of elements of the array is %lf.\n", sum);

	return 0;
}

double Sum(double array[], int n) {
	// Initialize sum to 0
	double sum = 0;

	// Iterate through the array and add the elements
	for(int i=0; i<n; i++) {
		sum += array[i];
	}

	// Return the calculated sum
	return sum;
}