#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int main()
{
	int rootArr[MAX], finArr[MAX], x, i, j, k, l, low, numNums, start, end, timer;
	srand(time(NULL));

	printf("Please enter an integer (max 100): ");
	//scanf("%d", &numNums);
	numNums=MAX;

	for (x=0; x<numNums; x++) {
		rootArr[x] = rand() % 10000 + 1;
	}

/*	debugging to see rootArr[] 
	for (i=0; i<numNums; i++) {
        printf("%d\n", rootArr[i]);
	}
*/
	start = time(0);
	for (i=0; i<numNums; i++) {
		printf("%d\n", i);
		low = 10050;
		for (k=0; k<numNums; k++) {
			if (rootArr[k] < low) {
				low = rootArr[k];
			}
		}
		finArr[i] = low;
		for (l=0; l<numNums; l++) {
			if (rootArr[l] == low) {
				rootArr[l] = 10100;
				break;
			}
		}
	}
	end = time(0);
	timer = end - start;
	printf("\n\nLowest to Highest\n\n");

	for (j=0; j<numNums; j++) {
		printf("Num %d: %d\n", j+1, finArr[j]);
	}

	printf("Total Runtime: %d seconds.\n", timer);

    return 0;
}
