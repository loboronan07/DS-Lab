/* Implement a C program to read, display and to find the product of two matrices
	using functions with suitable parameters. Check for the compatibility of the input
	matrices before multiplication.
*/
#include<stdio.h>
#include<stdlib.h>

// Function Prototype Declaration
void ReadMatrix(int matrix[][10], int m, int n);
void Multiply(int A[][10], int B[][10], int product[][10], int m1, int n1, int m2, int n2);
void DisplayMatrix(int matrix[][10], int m, int n);

int main(void) {
	int A[10][10], B[10][10], prod[10][10]; // Actual Matrices
	int m1, n1, m2, n2; // Dimensions of the input matrices
	int pr, pc; //Dimensions of the product matrix

	// Prompt the user for the dimensions of the matrices A and B
	 

	// Check for incompatibility of matrices for matrix multiplication
	if(n1 != m2) {
		printf("Invalid matrix dimensions for multplication of two matrices.\n");
		exit(1);
	}

	// Define the dimensions of the product matrix
	pr = m1;
	pc = n2;

	// Prompt the user for the elements of the matrices
	printf("Enter the elements of the first matrix: \n");
	ReadMatrix(A, m1, n1);

	printf("Enter the elements of the second matrix: \n");
	ReadMatrix(B, m2, n2);

	// Print out the matrices read
	printf("The first matrix read is: \n");
	DisplayMatrix(A, m1, n1);

	printf("The second matrix read is: \n");
	DisplayMatrix(B, m2, n2);

	// Mutiply the matrices A and B and store it in matrix prod using the function
	Multiply(A, B, prod, m1, n1, m2, n2);

	// Display the product matrix
	printf("The product of the two matrices is: \n");
	DisplayMatrix(prod, m1, n2);

	return 0;
}

void ReadMatrix(int matrix[][10], int m, int n) {
	/* Function to read a matrix */
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
}

void DisplayMatrix(int matrix[][10], int m, int n) {
	/* Function to display the matrix */
	for (int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			printf("%3d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

void Multiply(int A[][10], int B[][10], int product[][10], int m1, int n1, int m2, int n2) {
	/* Function to multiply the matrices A and B and to store the resultant product in matrix
		product. Check for compatibility to be done before the function is called. 
	*/
	for(int i=0; i<m1; i++) { // Iterate through A's rows
		for(int j=0; j<n2; j++) { // Iterate through B's columns
			product[i][j] = 0; // Initialize the value to 0
			for(int k=0; k<n1; k++) { // Dot product of A's  i'th row with B's j'th column
				product[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}