#include <stdio.h>
#include <stdlib.h>

void added_interest(double* bal, double* rate);

int main(void)
{
	double balance, rate;
	int years, i;

	printf("What is your current account balance: ");
	scanf("%lf", &balance);
	printf("What is your interest rate as a percentage: ");
	scanf("%lf", &rate);
	printf("How many years would you like to calculate interest for: ");
	scanf("%d", &years);

	for (i=0; i<years; i++) {
		added_interest(&balance, &rate);
	}

	printf("Here is your new balance after %d years: %.2lf\n", years, balance);

	return 0;
}

void added_interest(double* ptrBal, double* ptrRate)
{
	*ptrBal = *ptrBal*(1 + *ptrRate/100);
}