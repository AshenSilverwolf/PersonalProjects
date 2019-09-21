#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

FILE* fileopen()
{
	FILE *fp;
	fp = fopen("/mnt/c/users/ashen/documents/school_work/computer_science/readfile.txt", "r");
	// tried using the directory shortcut "csp" in the file location for fopen; did not work

	if (fp == NULL)
	{
		printf("File failed to open.\n");
		exit(-1);
	}

	return fp;
}

void count_characters(FILE *fp, int **count)
{
	char word[20];
	int i;

	while (!feof(fp))
	{
		fscanf(fp, "%s", word);
		for (i=0; i<strlen(word); i++)
		{
			switch(tolower(word[i]))
			{
				case 'a':
					count[0][1]++;
					break;
				case 'b':
					count[1][1]++;
					break;
				case 'c':
					count[2][1]++;
					break;
				case 'd':
					count[3][1]++;
					break;
				case 'e':
					count[4][1]++;
					break;
				case 'f':
					count[5][1]++;
					break;
				case 'g':
					count[6][1]++;
					break;
				case 'h':
					count[7][1]++;
					break;
				case 'i':
					count[8][1]++;
					break;
				case 'j':
					count[9][1]++;
					break;
				case 'k':
					count[10][1]++;
					break;
				case 'l':
					count[11][1]++;
					break;
				case 'm':
					count[12][1]++;
					break;
				case 'n':
					count[13][1]++;
					break;
				case 'o':
					count[14][1]++;
					break;
				case 'p':
					count[15][1]++;
					break;
				case 'q':
					count[16][1]++;
					break;
				case 'r':
					count[17][1]++;
					break;
				case 's':
					count[18][1]++;
					break;
				case 't':
					count[19][1]++;
					break;
				case 'u':
					count[20][1]++;
					break;
				case 'v':
					count[21][1]++;
					break;
				case 'w':
					count[22][1]++;
					break;
				case 'x':
					count[23][1]++;
					break;
				case 'y':
					count[24][1]++;
					break;
				case 'z':
					count[25][1]++;
					break;
				default:
					break;
			} // end switch
		} // end for word length
	} // end while loop
}

int** sort_high_low(int **array)
{
	int i, j, max, temp;
	int **finarr;
	finarr = calloc(26, 2*sizeof(int));
	for (i=0; i<26; i++)
	{
		finarr[i] = calloc(2, sizeof(int));
	}

	for (i=0; i<26; i++)
	{
		max=-1;
		for (j=0; j<26; j++)
		{
			if (array[j][1] > max)
			{
				max = array[j][1];
				temp = array[j][0];
			}
		}

		finarr[i][1] = max;
		finarr[i][0] = temp;

		for (j=0; j<26; j++)
		{
			if (array[j][1] == max)
			{
				array[j][1] = -1;
				array[j][0] = -1;
				break;
			}
		}
	}

	return finarr;
}

void print_results(int **array)
{
	int i;

	for (i=0; i<26; i++)
	{
		printf("%c: %d\n", array[i][0], array[i][1]);
	}
}

int main()
{
	FILE *fp;
	printf("Make sure that you have the desired text within the readfile.txt document in the School Work folder.\n\n");
	fp = fileopen();
	char word[20];
	int i, **count;
	count = calloc(26, 2*sizeof(int));
	for (i=0; i<26; i++)
	{
		count[i] = calloc(2, sizeof(int));
		count[i][0] = i+65;
	}
	// calloc is actually very useful here because by default, it zeroes out all of the values
	// it allows me to move on without zeroing out the values manually through a for loop

	count_characters(fp, count);

	count = sort_high_low(count);

	print_results(count);

	fclose(fp);
	free(count);
	

	return 0;
}