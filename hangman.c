// 3 Hours Creation Time

// START INCLUDES/DEFINITIONS/STRUCTURES //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#define MAX 50

// END INCLUDES/DEFINITIONS/STRUCTURES //

// START FUNCTIONAL PROTOTYPES //

FILE* citiesOpen();

void fillPuzzle(char *entry, char *puzzle);

void showPuzzle(char *entry);

void getLine(char *line, int limit, FILE *fp);

int howManyLines();

void pickLine(char *entry, int line);

int numChars(char *string);

void runPuzzle(char *answer, char *puzzle);

// END FUNCTIONAL PROTOTYPES //

// START MAIN PROGRAM //

int main()
{
	srand(time(NULL));
	FILE *fp;
	int choice, lines, i, letters;
	char entry[MAX];
	char *puzzle;
	puzzle = calloc(strlen(entry)+1, sizeof(char));
	fp = citiesOpen();

	lines = howManyLines();
	choice = rand() % lines + 1;
	pickLine(entry, choice);
	letters = numChars(entry);

	printf("%d, %s\n", choice, entry);

	fillPuzzle(entry, puzzle);
	printf("There are %d letters.\n", letters);

	runPuzzle(entry, puzzle);

	fclose(fp);
	return 0;
}

// END MAIN PROGRAM //

// START FUNCTION DEFINITIONS //

FILE* citiesOpen()
{
	FILE *fp;
	fp = fopen("cities.txt", "r");

	if (fp==NULL)
	{
		printf("File failed to open.\n");
		exit(0);
	}

	return fp;
}

void fillPuzzle(char *entry, char *puzzle)
{
	int i;

	for (i=0; i<strlen(entry); i++)
	{
		if (isalpha(entry[i]))
		{
			puzzle[i] = '-';
		}
		else
		{
			puzzle[i] = ' ';
		}
	}

	puzzle[strlen(entry)] = '\0';
}

void getLine(char *line, int limit, FILE *fp)
{
	fgets(line, limit, fp);
	strtok(line, "\r\n");
}

int howManyLines()
{
	FILE *fp;
	fp = citiesOpen();
	char temp[MAX];
	int count=0;

	while (!feof(fp))
	{
		getLine(temp, MAX, fp);
		count++;
	}

	fclose(fp);
	return count;
}

void pickLine(char *entry, int line)
{
	FILE *fp;
	fp = citiesOpen();
	int i=1, flag=0;

	while (!feof(fp))
	{
		getLine(entry, MAX, fp);
		
		if (i == line)
		{
			flag=1;
			break;
		}

		i++;
	}

	// (flag) ? printf("Option Found.\n") : printf("Error in pickLine()\n") ;
	fclose(fp);
}

int numChars(char *string)
{
	int i, count=0;

	for (i=0; i<strlen(string); i++)
	{
		if (isalpha(string[i]))
		{
			count++;
		}
	}

	return count;
}

void runPuzzle(char *answer, char *puzzle)
{
	char guess[1];
	int *letters;
	int i, j, len, score, lose=0;
	letters = calloc(26, sizeof(int));
	len = strlen(answer);
	do 
	{
		score = 0;
		system("clear");
		//printf("%s\n", answer);
		for (i=0; i<26; i++)
		{
			if (letters[i] == 1)
			{
				printf("%c, ", i+65);
				score++;
			}
		}
		//if (score >= 6)
		//{
		//	lose=1;
		//	break;
		//}
		printf("\n");
		printf("%d Letters\n", strlen(answer));
		printf("%s\nPlease enter a letter: ", puzzle);
		scanf("%s", guess);

		for (i=0; i<26; i++)
		{
			if (!letters[toupper(guess[0])-65])
			{
				letters[toupper(guess[0])-65] = 1;
			}
		}

		for (i=0; i<len; i++)
		{
			if (toupper(guess[0]) == toupper(answer[i]))
			{
				puzzle[i] = answer[i];
				letters[toupper(guess[0])-65] = 2;
			}
		}
	} while (strcasecmp(answer, puzzle));

	system("clear");
	(lose) ? printf("You lost.\n") : printf("Congratulations, you got the answer!\n%s\n", puzzle) ;
}

// END FUNCTION DEFINITIONS //