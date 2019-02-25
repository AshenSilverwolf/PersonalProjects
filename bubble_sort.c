#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int *array, int m, int n)
{
	int temp;
	temp = array[m];
	array[m] = array[n];
	array[n] = temp;
}

void bubbleSort(int *array, int len)
{
	int i, j;

	for (i = len - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (array[j] > array[j+1])
				swap(array, j, j+1);
}

void generate_list(int *array, int len, int max)
{
	int i;

	for (i = 0; i < len; i++)
		array[i] = rand() % max + 1;
}

void display_list(int *array, int len)
{
	int i;

	for (i = 0; i < len; i++)
		printf("%d ", array[i]);

	printf("\n");
}

int main(void)
{
	srand(time(NULL));
	int *array, len, max, i;

	printf("How many numbers would you like to be sorted?\n");
	scanf("%d", &len);
	printf("What is the highest number you would like to see in the list?\n");
	scanf("%d", &max);

	array = calloc(len, sizeof(int));

	generate_list(array, len, max);
	display_list(array, len);
	bubbleSort(array, len);
	display_list(array, len);

	return 0;
}