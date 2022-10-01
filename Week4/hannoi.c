#include<stdio.h>
int hannoi(int n, char source, char aux, char dest){
	int count=0;
	if (n==1){
		printf("Move a disk from rod %c to rod %c.\n", source, dest);
		count++;
	}
	else {
		count += hanoi(n-1, source, dest, aux);
		printf("Move a disk from rod %c to rod %c.\n", source, dest);
		count++;
		count += hanoi(n-1, aux, source, dest);
	}
	return count;
}
void main(){
	int n, count;
	char source, aux, dest;
	printf("Enter the source : ");
	scanf("%c",&source);
	printf("Enter the auxiliary : ");
	scanf("%c",&aux);
	printf("Enter the destination : ")
	scanf("%c", &dest);
	printf("Enter the number of disks at the source %c: ", source);
	scanf("%d", &n);

	count = hanoi(n, source, aux, dest);

	printf("The number of moves to solve the tower of hanoi is %d.\n", count);
}