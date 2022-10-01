/* Lab Exercise 1
	To generate Fibonacci series with n terms.
*/

#include <stdio.h>

int fibonacci(int n) {
	if(n == 0) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}
	return fibonacci(n-1) + fibonacci(n-2);

}
int main(void) { 
	int n;
	printf("===== Fibonacci(n) =====\n");
	printf("Enter the number, n: ");
	scanf("%d", &n);

	for(int i = 0; i <= n; i++) {
		printf("fib(%d) = %d\n", i, fibonacci(i));
	}

	return 0;
}