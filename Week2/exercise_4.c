/* Implement a C program to read, display and to find the product of two matrices
	using functions with suitable parameters. Note that the matrices should be created
	using dynamic memory allocation functions and the elements are accessed using
	array dereferencing.
*/
#include<stdio.h>
#include<stdlib.h>

int **Alloc(int m, int n);
void ReadMat(int **Mat, int m, int n);
void DispMat(int **Mat, int m, int n);
void MatMul(int **A, int **B, int **R, int m1, int n1, int m2, int n2);
void FreeMat(int **Mat, int m, int n);

int main(void) {
	int m1, n1, m2, n2, r1, r2;
	int **A, **B, **R;
	printf("Enter the dimensions of the first matrix: ");
	scanf("%d %d", &m1, &n1);

	printf("Enter the dimensions of the second matrix: ");
	scanf("%d %d", &m2, &n2);

	if(n1 != m2) {
		printf("Invalid matrix dimensions for multplication of two matrices.\n");
		exit(1);
	}

	A = Alloc(m1, n1);
	printf("Enter the elements of the first matrix: \n");
	ReadMat(A, m1, n1);

	B = Alloc(m2, n2);
	printf("Enter the elements of the second matrix: \n");
	ReadMat(B, m2 ,n2);

	r1 = m1; r2 = n2;
	R = Alloc(r1, r2);
	MatMul(A, B, R, m1, n1, m2, n2);

	printf("The first matrix read is: \n");
	DispMat(A, m1, n1);
	printf("The second matrix read is: \n");
	DispMat(B, m2, n2);
	printf("The product of the two matrices is: \n");
	DispMat(R, r1, r2);

	FreeMat(A, m1, n2);
	FreeMat(B, m2, n2);
	FreeMat(R, r1, r2);

	return 0;
}

int **Alloc(int m, int n) {
	int **matrix = (int **) calloc(m, sizeof(int *));
	for(int i=0; i<n; i++) {
		*(matrix + i) = (int *) calloc(n, sizeof(int));
	}

	return matrix;
}

void ReadMat(int **Mat, int m, int n) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", (*(Mat + i) + j));
		}
	}
}

void DispMat(int **Mat, int m, int n) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			printf("%d\t", *(*(Mat + i) + j));
		}
		printf("\n");
	}
}

void MatMul(int **A, int **B, int **R, int m1, int n1, int m2, int n2) {
	for(int i=0; i<m1; i++) { 
		for(int j=0; j<n2; j++) { 
			*(*(R + i) + j) = 0;
			for(int k=0; k<n1; k++) { 
				*(*(R + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
			}
		}
	}
	return;
}

void FreeMat(int **Mat, int m, int n) {
	for(int i=0; i<m; i++) {
		free(*(Mat + i));
	}
	free(Mat);
}