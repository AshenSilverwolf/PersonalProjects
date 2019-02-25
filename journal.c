#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

FILE* fileopen()
{
	FILE *fp;
	fp = fopen("/mnt/c/users/ashen/documents/GAVIN/Journal.txt", "a");

	if (fp == NULL)
	{
		printf("File failed to open.\n");
		exit(-1);
	}

	return fp;
}

int main()
{
	FILE *fp;
	char *entry;
	char month[10], date[10];
	int day;
	entry = calloc(10000, sizeof(char));

	fp = fileopen();


	fgets(entry, 10000, stdin);
	printf("Month: ");
	scanf("%s", month);
	printf("Day of the Week: ");
	scanf("%s", date);
	printf("Day Number: ");
	scanf("%d", &day);
	fprintf(fp, "%s, %s %d\n%s\n\n", date, month, day, entry);

	fclose(fp);
	free(entry);

	return 0;
}