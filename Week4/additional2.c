/* Additional Exercise 2
	To read a line of text and write it out backwards using Recursion.
*/

#include <stdio.h>
#include <string.h>

void print_reverse(char *letter) {
	if(*letter == 1) 
		return;
	printf("%c", *letter);
	print_reverse(letter-1);
}

int main(void) {
	char string[100];
	string[0] = 1; // The ascii 1 is selected arbitrarily to denote beginning of the string
	printf("Enter a string: ");
	scanf("%[^\n]s", string+1);
	
	print_reverse(string + strlen(string) - 1);
	printf("\n");
	return 0;
}
