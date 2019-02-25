#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Integer: %lu\nFloat: %lu\nDouble: %lu\nCharacter: %lu\n", 
		sizeof(int), sizeof(float), sizeof(double), sizeof(char));

	return 0;
}