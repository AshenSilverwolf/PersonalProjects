#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double fib[1000000];
	int i, numfib, count=0;
	double x;

	fib[0] = 0;
	fib[1] = 1;

	printf("How many digits in the fibonacci sequence would you like to see? ");
	scanf("%d", &numfib);

	printf("%.0lf\n", fib[1]);

	for (i=2; i<=numfib; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
		printf("%.0lf\n", fib[i]);
		if (i==1477)
		{
			x = fib[i];
			while (x > 0)
			{
				x/=10;
				count++;
			}
			break;
		}
	}

	printf("\n\nCounter: %d\n\n", count);

	return 0;
}
