#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

int main(void)
{
	int x=3, y=7;

	printf("These are the values x=%d and y=%d before the swap.\n", x, y);

	swap(&x, &y);

	printf("These are the values x=%d and y=%d after the swap.\n", x, y);

	return 0;
}

void swap(int* a, int* b)
{
	int temp;
	temp = *a; //temp is set to value stored at the address "a"
	*a = *b; //the value at the address "a" is set to the value at the address "b"
	*b = temp; //the value at the address "b" is set to the temp value, which WAS the "a" value
}