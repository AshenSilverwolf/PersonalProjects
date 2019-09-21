#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	char game_board[5][5];
	int i, j, randr, randc, guessc, guessr, count=0;
	randr = rand() % 5;
	randc = rand() % 5;

	for (i=0; i<5; i++) {
		for (j=0; j<5; j++) {
			game_board[i][j] = '#';
		}
	}

//	game_board[randr][randc] = '@';

	do {
		printf("     1   2   3   4   5\n");
		for (i=0; i<5; i++) {	
			printf("   +---+---+---+---+---+\n");
			printf(" %d | %c | %c | %c | %c | %c |\n",
				i+1, game_board[i][0], game_board[i][1], game_board[i][2], game_board[i][3], game_board[i][4]);
		}
		printf("   +---+---+---+---+---+\n\n");
		

		printf("Choose a row, 1 through 5: ");
		scanf("%d", &guessr);
		printf("Choose a column, 1 through 5: ");
		scanf("%d", &guessc);
	
		guessr-=1;
		guessc-=1;

		system("clear");

		if (guessr != randr || guessc != randc) {
			printf("You guessed wrong. Try again.\n");
			game_board[guessr][guessc] = 'X';
			if (guessr == randr) {
				printf("You're on the right row though!\n\n");
			} else if (guessc == randc) {
				printf("You're on the right column though!\n\n");
			} else {
				printf("\n");
			}
		}
		count++;
	} while (guessr != randr || guessc != randc);
	
	game_board[guessr][guessc] = '@';
	printf("You guessed right!\n");
	printf("It took you %d tries.\n\n", count);
	printf("     %d   %d   %d   %d   %d\n", 1, 2, 3, 4, 5);
	for (i=0; i<5; i++) {
		printf("   +---+---+---+---+---+\n");
		printf(" %d | %c | %c | %c | %c | %c |\n",
			i+1, game_board[i][0], game_board[i][1], game_board[i][2], game_board[i][3], game_board[i][4]);
	}
	printf("   +---+---+---+---+---+\n\n");
	

	return 0;
}