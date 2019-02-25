#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int i=0, total = 0, num, j;
	int numArr[10];

	printf("Please enter a number: ");
	scanf("%d", &num);

	while (num != 0) {
		numArr[i] = num % 10;
		num /= 10;
		i++;
	}

	for (j=0; j<=i; j++) {
		total += numArr[j];
	}

	printf("The sum of the digits in your number is: %d\n", total);

	return 0;
}