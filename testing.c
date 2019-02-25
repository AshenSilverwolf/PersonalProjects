#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char name1[] = "Gavin";
	char name2[] = "Zelda";
	int x;
	
	x = strcmp(name1, name2);

	printf("%d\n", x);
}