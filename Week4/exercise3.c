#include <stdio.h>

int palin(char *first, char *last) {
	if(first >= last) {
		return 1;
	}
	if(*first != *last) {
		return 0;
	}
	return palin(first+1, last-1);
}

int palincheck(char *str) {
	char *last;
	for(last = str; *(last+1) != '\0'; last++);

	return palin(str, last);
}

int main(void) {
	char str[100];
	
	printf("Enter a string: \n");
	scanf("%[^\n]s", str);
	if(palincheck(str)) {
		printf("The entered string is a palindrome.\n");
	}
	else {
		printf("The entered string is not a palindrome.\n");
	}
	return 0;
}