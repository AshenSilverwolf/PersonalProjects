#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[20];
	int num;

	printf("How many entries? ");
	scanf("%d", &num);

	for (int x = 0; x < num; x++) {
		printf("\nEnter a number: ");
		scanf("%d", &arr[x]);
	}

	for (int i = 0; i < num; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}
