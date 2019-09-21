#include <stdio.h>
#include <stdlib.h>

// START FUNCTIONAL PROTOTYPES //

int getNum();

int isPrime(int n);

void showDivisors(int n);

// END FUNCTIONAL PROTOTYPES //

int main()
{
	system("clear");
	int n;
	n = getNum();
	showDivisors(n);
	printf("\n");

	if (isPrime(n)) {
		printf("Your number is prime.\n");
	} else {
		printf("Your number is not prime.\n");
	}

	return 0;
}

// START OTHER FUNCTIONS //

int getNum()
{
	int num;

	printf("Please enter a number: ");
	scanf("%d", &num);

	return num;
}

int isPrime(int n)
{
	int i;

	for (i=2; i<=n/2; i++) {
		if (n%i == 0) {
			return 0;
		}
	}

	return 1;
}

void showDivisors(int n)
{
	int i;

	for (i=1; i<=n; i++) {
		if (n%i == 0) {
			printf("%d ", i);
		}
	}
}