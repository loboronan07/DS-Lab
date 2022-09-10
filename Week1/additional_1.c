#include<stdio.h>

int main(void) {
	int random[10000];
	int freq[200] = {0};
	int rand_no;
	for(int i=0; i<10000; i++) {
		rand_no = random[i] % 100;
		freq[rand_no + 100] += 1;
	}
	printf("Number\t\tFrequency\n");
	for(int i=0; i<200; i++) {
		printf("%d\t\t%d\n", i-100, freq[i]);
	}
	return 0;
}