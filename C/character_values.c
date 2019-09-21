#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;

	for (i=0; i<26; i++)
	{
		printf("%c = %d\n", i+97, i+97);
	}

	for (i=0; i<26; i++)
	{
		printf("%c = %d\n", i+65, i+65);
	}

	printf("%d\n", '\t');

	return 0;
}