/* Lab Exercise 2
	To copy one string to another using Recursion.
*/

#include <stdio.h>

void copy_string(char *inp_str, char *out_str) {
	*out_str = *inp_str;
	
	if(*inp_str == '\0') {
		return;
	}
	
	copy_string(inp_str+1, out_str+1);
}

int main(void) {
	char input[100], output[100];
	printf("Enter a string:\n");
	scanf("%[^\n]s", input);
	
	copy_string(input, output);

	printf("The copied new string using recursion is:\n%s\n", output);

	return 0;
}