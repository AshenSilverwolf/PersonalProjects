#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
	int i, start, end, timer;

	start = time(0);
	for (i=0; i<1000001; i++) {
		printf("%d\n", i);
	}
	end = time(0);
	timer = end - start;

	printf("Total Runtime: %d\n", timer);
}