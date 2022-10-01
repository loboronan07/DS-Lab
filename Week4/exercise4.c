/* Lab Exercise 4
	Simulate the working of Tower of Hanoi for n disks. Print the number of moves.
*/

#include <stdio.h>

int tower_of_hanoi(int n, char source, char auxiliary, char destination) {
	int count = 0;
	if(n == 1) {
		printf("Move a disk from rod %c to rod %c.\n", source, destination);
		count++;
	}
	else {
		count += tower_of_hanoi(n-1, source, destination, auxiliary);
		printf("Move a disk from rod %c to rod %c.\n", source, destination);
		count++;
		count += tower_of_hanoi(n-1, auxiliary, source, destination);
	}
	return count;
}

int main(void) {
	int n, count;
	char source, auxiliary, destination;

	printf("Enter the source, auxiliary and destination: ");
	scanf("%c %c %c", &source, &auxiliary, &destination);

	printf("Enter the number of disks initially at the source %c: ", source);
	scanf("%d", &n);

	count = tower_of_hanoi(n, source, auxiliary, destination);

	printf("The number of moves to solve the tower of hanoi is %d.\n", count);

	return 0;
}