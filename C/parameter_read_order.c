/*
 * Apparently when reading through parameters of functions, it reads
 * from right to left. If you look at Example A, the ++ happens on
 * the far left. It goes from right to left, inputting all of the data
 * before finally moving on to the next index (i++) at n1. In Example B,
 * the ++ is on the far right. After inputting the 3 into the array,
 * it moves to the next index and stores the values 2 and 1 in the
 * second index.
*/

#include <stdio.h>
#include <stdlib.h>

struct data {
	int n1;
	int n2;
	int n3;
};

void main() {
	FILE *ifp;
	struct data *arr1 = calloc(5, sizeof(struct data));
	struct data *arr2 = calloc(5, sizeof(struct data));

	// EXAMPLE A
	ifp = fopen("input.txt", "r");
	int i = 0;
	while (fscanf(ifp, "%d %d %d", &arr1[i++].n1, &arr1[i].n2, &arr1[i].n3) != EOF) {}
	fclose(ifp);

	// EXAMPLE B
	ifp = fopen("input.txt", "r");
	i = 0;	
	while (fscanf(ifp, "%d %d %d", &arr2[i].n1, &arr2[i].n2, &arr2[i++].n3) != EOF) {}
	fclose(ifp);

	for (i = 0; i < 3; i++) {
		printf("%d %d %d\n", arr1[i].n1, arr1[i].n2, arr1[i].n3);
	}

	printf("\n");

	for (i = 0; i < 3; i++) {
		printf("%d %d %d\n", arr2[i].n1, arr2[i].n2, arr2[i].n3);
	}
}