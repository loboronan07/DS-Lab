/* Additional Exercise 1
	To find the first capital letter in a string using Recursion.
*/

#include <stdio.h>

char find_capital(char *letter) {
	if(*letter == '\0' || (*letter >= 'A' && *letter <= 'Z'))
		return *letter;
	return find_capital(letter+1);
}

int main(void) {
	char string[100], capital;
	printf("Enter a string: ");
	scanf("%[^\n]s", string);
	
	capital = find_capital(string);
	if(capital) 
		printf("The first capital letter in the input string is %c.\n", capital);
	else
		printf("The input string does not contain a capital letter.\n");
	
	return 0;
}
