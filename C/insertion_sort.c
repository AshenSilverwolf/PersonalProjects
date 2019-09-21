#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_arrays(int root[], int finarr[], int* len, int high);

void sort_low_high(int arr[], int finarr[], int len);

void print_final(int final[], int len);

int main(void)
{
	srand(time(NULL));
	int i, length, max;
	int* ptrlen;

	system("clear");

	printf("How large would you like the arrays to be?\n");
	scanf("%d", &length);
	printf("What would you like the highest number to be?\n");
	scanf("%d", &max);

	ptrlen = &length;
	int array[length], finarr[length];

	fill_arrays(array, finarr, ptrlen, max);

	system("clear");

	for (i=0; i<length; i++) {
		printf("%d\n", array[i]);
	}

	printf("\n");

	sort_low_high(array, finarr, length);

	print_final(finarr, length);

	return 0;
}

void fill_arrays(int root[], int finarr[], int* len, int high)
{
	int i;

	for (i=0; i<*len; i++) {
		finarr[i] = 0;
	}

	for (i=0; i<*len; i++) {
		root[i] = rand() % high + 1;
	}
}

void sort_low_high(int arr[], int finarr[], int len)
{
	int i, j, max;

	for (i=len-1; i>=0; i--) {
		max=0;
		for (j=0; j<len; j++) {
			if (arr[j] > max) {
				max = arr[j];
			}
		}

		finarr[i] = max;
		
		for (j=0; j<len; j++) {
			if (arr[j] == max) {
				arr[j] = 0;
				break;
			}
		}
	}
}

void print_final(int final[], int len)
{
	int i;

	for (i=0; i<len; i++) {
		printf("%d\n", final[i]);
	}
}