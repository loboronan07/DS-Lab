/* Implement Complex numbers using structures. Write functions to add, multiply,
	subtract two complex numbers. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double re;
	double im;
} COMPLEX;


void get_COMPLEX(COMPLEX*);
void display_COMPLEX(COMPLEX*);
COMPLEX* add(COMPLEX*, COMPLEX*);
COMPLEX* multiply(COMPLEX*, COMPLEX*);
COMPLEX* subtract(COMPLEX*, COMPLEX*);

int main(void) {
	COMPLEX *z1 = (COMPLEX*) malloc(sizeof(COMPLEX));
	COMPLEX *z2 = (COMPLEX*) malloc(sizeof(COMPLEX));

	printf("Enter the first complex number, z1: ");
	get_COMPLEX(z1);
	printf("Enter the second complex number, z2: ");
	get_COMPLEX(z2);

	COMPLEX *sum = add(z1, z2);
	COMPLEX *product = multiply(z1, z2);
	COMPLEX *diff = subtract(z1, z2);

	printf("The first complex number entered is z1 = ");
	display_COMPLEX(z1);
	printf("The second complex number entered is z2 = ");
	display_COMPLEX(z2);
	printf("The sum of the two complex numbers is,  z1 + z2 = ");
	display_COMPLEX(sum);
	printf("The difference of the two complex numbers is,  z1 - z2 = ");
	display_COMPLEX(diff);
	printf("The product of the two complex numbers is,  z1 * z2 = ");
	display_COMPLEX(product);

	free(z1); free(z2); free(sum); free(product); free(diff);

	return 0;
}

void get_COMPLEX(COMPLEX* z) {
	scanf("%lf %lf", &z->re, &z->im);
}

void display_COMPLEX(COMPLEX* z) {
	printf("%lf %c %lf i\n", z->re, (z->im >= 0)? '+' : '-', fabs(z->im));
}

COMPLEX* add(COMPLEX* z1, COMPLEX* z2) {
	COMPLEX* sum = (COMPLEX*) malloc(sizeof(COMPLEX));
	sum->re = z1->re + z2->re;
	sum->im = z1->im + z2->im;
	return sum;
}

COMPLEX* multiply(COMPLEX* z1, COMPLEX* z2) {
	COMPLEX* product = (COMPLEX*) malloc(sizeof(COMPLEX));
	product->re = z1->re * z2->re - z1->im * z2->im;
	product->im = z1->re * z2->im + z1->im * z2->re;
	return product;
}

COMPLEX* subtract(COMPLEX* z1, COMPLEX* z2) {
	COMPLEX* diff = (COMPLEX*) malloc(sizeof(COMPLEX));
	diff->re = z1->re - z2->re;
	diff->im = z1->im - z2->im;
	return diff;
}