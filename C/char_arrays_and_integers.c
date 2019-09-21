#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char arr[20];
	int i;

	printf("Gimme your sword...\n");
	scanf("%s", arr);

	for (i=0; i<strlen(arr); i++) {
		printf("%c\n", arr[i]);
	}

//When you scanf() a set of numerical digits into a character array as a string, 
//it stores each number as it's own character
//
//You can use this to separate each character into its own spot in the array
//for later referencing. Matthew thought of this as a way to store very large numbers
//in arrays without running into a an overflow or core dump error

	return 0;
}