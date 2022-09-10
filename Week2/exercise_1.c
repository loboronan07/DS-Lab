/* Write a function Reverse to reverse the elements of an integer array using pointer.
	Access the elements of the array using dereference operator. Read the values from
	the keyboard in main function. Display the result in the main function.
*/
#include<stdio.h>
#include<stdlib.h>

void Reverse(int *arr, int n);

int main(void) {
	int arr[100];
	int n, i;
	int *p = arr;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	printf("Enter the elements of the array: ");
	for(i=0, p=arr; i<n; i++, p++) {
		scanf("%d", p);
	}

	printf("Array before reversing the elements: ");
	for(i=0, p=arr; i<n; i++, p++) {
		printf("%d ", *p);
	}
	printf("\n");

	Reverse(arr, n);

	printf("Array after reversing the elements: ");
	for(i=0, p=arr; i<n; i++, p++) {
		printf("%d ", *p);
	}
	printf("\n");
	
	return 0;
}

void Reverse(int *arr, int n) {
	int temp;
	for(int i=0; i< n/2; i++) {
		temp = *(arr + i);
		*(arr + i) = *(arr + n - 1 - i);
		*(arr + n - 1 - i) = temp;
	}
}