// BEGIN INCLUDES/DEFINES/STRUCTURES //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// END INCLUDES/DEFINES/STRUCTURES //

// BEGIN FUNCTIONAL PROTOTYPES //

void codeMaker(char *code);

char checkLetter(int rnd);

int theGame(char *masterCode);

void compareUnique(char *master, char *guess, int *spot, int *color);

void showBoard(char **guesses, char *master, int n, int con, int **status);

// END FUNCTIONAL PROTOTYPES //

// BEGIN MAIN FUNCTION //

int main()
{
	srand(time(NULL));
	char masterCode[5], again[5];
	int win;

	do
	{
		system("clear");
		codeMaker(masterCode);
		win = theGame(masterCode);
		(win) ? printf("Congrats, you won!\n") : printf("Aww, you lost.\n") ;
		printf("Would you like to play again? (Y/N) ");
		scanf("%s", again);
		strtok(again, "\r\n");
	} while (!strcasecmp(again, "Y"));

	return 0;
}

// END MAIN FUNCTION //

// BEGIN FUNCTION DEFINITIONS //

void codeMaker(char *code)
{
	int rnd, i, j, flag;

	for (i=0; i<4; i++)
	{
		if (i == 0)
		{
			rnd = rand() % 6;
			code[i] = checkLetter(rnd);
			//printf("%d, %c\n", i, code[i]);
		} // end if
		else
		{
			do
			{
				flag=0;
				rnd = rand() % 6;
				code[i] = checkLetter(rnd);
				//printf("%d, %c\n", i, code[i]);
				for (j=0; j<i; j++)
				{
					if (code[j] == code[i])
					{
						flag=1;
						break;
					} // end if
				} // end for(j)
			} while (flag); // end do-while
		} // end else
	} // end for(i)

	code[4] = '\0';

	// printf("%s\n", code); // debug
}

char checkLetter(int rnd)
{
	switch (rnd)
	{
		case 0:
			return 'R';
		case 1:
			return 'G';
		case 2:
			return 'U';
		case 3:
			return 'Y';
		case 4:
			return 'B';
		case 5:
			return 'W';
		default:
			printf("Fucked up checkLetter()\n");
			exit(0);
	}
}

int theGame(char *masterCode)
{
	char **board;
	board = calloc(10, sizeof(char*));
	for (int i=0; i<10; i++)
	{
		board[i] = calloc(5, sizeof(char));
	}

	int **status;
	status = calloc(10, sizeof(int*));
	for (int i=0; i<10; i++)
	{
		status[i] = calloc(2, sizeof(int));
	}

	char guess[10];

	int i, j, flag=0;
	int spot=0, color=0;

	for (i=0; i<10; i++)
	{
		//printf("%s\n", masterCode);
		showBoard(board, masterCode, i, 0, status);
		spot=0;
		color=0;
		printf("Red = R\nGreen = G\nYellow = Y\nBlue = U\nBlack = B\nWhite = W\n\n");
		printf("What do you think the master code is?\n");
		printf("Please format with four characters, no spaces.\n");
		scanf("%s", guess);
		strcpy(board[i], guess);
		compareUnique(masterCode, guess, &spot, &color);
		status[i][0] = spot;
		status[i][1] = color;
		system("clear");
		if (spot == 4)
		{
			showBoard(board, masterCode, i+1, 1, status);
			return 1;
		}
	} // end for(i)

	showBoard(board, masterCode, i, 1, status);
	return 0;
}

void compareUnique(char *master, char *guess, int *spot, int *color)
{
	int i, j, flag=0, exists=0;
//	int b=0, u=0, r=0, w=0, y=0, g=0;
	int bs=0, us=0, rs=0, ws=0, ys=0, gs=0;
	int bc=0, uc=0, rc=0, wc=0, yc=0, gc=0;
/*
	for (i=0; i<4; i++)
	{
		switch (guess[i])
		{
			case 'B':
				b++;
				break;
			case 'U':
				u++;
				break;
			case 'R':
				r++;
				break;
			case 'W':
				w++;
				break;
			case 'Y':
				y++;
				break;
			case 'G':
				g++;
				break;
			default:
				printf("Broken Switch code lettercount.\n");
				exit(0);
		} // end switch check letter frequency
	} // end for check letter frequency

	printf("B: %d, U: %d, R: %d, W: %d, Y: %d, G: %d\n", b, u, r, w, y, g);
*/
	if (guess[0] == guess[1] && guess[0] == guess[2] && guess[0] == guess[3])
	{
		flag=1;
	}

	for (i=0; i<4; i++)
	{
		for (j=0; j<4; j++)
		{
			if (master[i] == guess[j])
			{
				exists=1;
				if (i==j) // if same spot
				{
					switch (guess[j])
					{
						case 'B':
							bs++;
							break;
						case 'U':
							us++;
							break;
						case 'R':
							rs++;
							break;
						case 'W':
							ws++;
							break;
						case 'Y':
							ys++;
							break;
						case 'G':
							gs++;
							break;
						default:
							printf("Broken Switch spots.\n");
							exit(0);
					} // end switch guess[j]
				} // end if same spot
				else
				{ // if different spot
					switch (guess[j])
					{
						case 'B':
							bc++;
							break;
						case 'U':
							uc++;
							break;
						case 'R':
							rc++;
							break;
						case 'W':
							wc++;
							break;
						case 'Y':
							yc++;
							break;
						case 'G':
							gc++;
							break;
						default:
							printf("Broken Switch colors.\n");
							exit(0);
					} // end switch guess[j]
				} // end spot/color if-else
				guess[j] = 'Z';
			} // end sameChar if
		} // end for(j)
	} // end for(i)

//	printf("bs: %d, us: %d, rs: %d, ws: %d, ys: %d, gs: %d\n", bs, us, rs, ws, ys, gs);
//	printf("bc: %d, uc: %d, rc: %d, wc: %d, yc: %d, gc: %d\n", bc, uc, rc, wc, ys, gc);

	if (bc > 1)
	{
		bc = 1;
	}
	if (uc > 1)
	{
		uc = 1;
	}
	if (rc > 1)
	{
		rc = 1;
	}
	if (wc > 1)
	{
		wc = 1;
	}
	if (yc > 1)
	{
		yc = 1;
	}
	if (gc > 1)
	{
		gc = 1;
	}
/*
	printf("after check.\n");
	printf("bs: %d, us: %d, rs: %d, ws: %d, ys: %d, gs: %d\n", bs, us, rs, ws, ys, gs);
	printf("bc: %d, uc: %d, rc: %d, wc: %d, yc: %d, gc: %d\n", bc, uc, rc, wc, ys, gc);
*/
	*spot = bs + us + rs + ws + ys + gs;
	*color = bc + uc + rc + wc + yc + gc;

	if (flag)
	{
		if (exists)
		{
			*spot = 1;
			*color = 0;
		}
		else
		{
			*spot = 0;
			*color = 0;
		}
	}

//	printf("spots: %d, colors: %d\n", *spot, *color);
} // end compareUnique()

void showBoard(char **guesses, char *master, int n, int con, int **status)
{
	if (!con)
	{
		printf("\n  M A S T E R M I N D\n\n");
		printf("   #---#---#---#---#\n");
		printf("   | # | # | # | # | Master Code\n");
		printf("   #---#---#---#---#\n\n");

		for (int i=10; i>n; i--)
		{
			printf("   #---#---#---#---#\n");
			printf(" %d |   |   |   |   |\n", i%10);
		}
		for (int i=n; i>0; i--)
		{
			printf("   #---#---#---#---#\n");
			printf(" %d | %c | %c | %c | %c | Spots: %d, Colors: %d\n", i%10, guesses[i-1][0], guesses[i-1][1], guesses[i-1][2], guesses[i-1][3], status[i-1][0], status[i-1][1]);
		}

		printf("   #---#---#---#---#\n\n");
	}
	else
	{
		printf("\n  M A S T E R M I N D\n\n");
		printf("   #---#---#---#---#\n");
		printf("   | %c | %c | %c | %c | Master Code\n", master[0], master[1], master[2], master[3]);
		printf("   #---#---#---#---#\n\n");

		for (int i=10; i>n; i--)
		{
			printf("   #---#---#---#---#\n");
			printf(" %d |   |   |   |   |\n", i%10);
		}
		for (int i=n; i>0; i--)
		{
			printf("   #---#---#---#---#\n");
			printf(" %d | %c | %c | %c | %c |\n", i%10, guesses[i-1][0], guesses[i-1][1], guesses[i-1][2], guesses[i-1][3]);
		}

		printf("   #---#---#---#---#\n\n");
	}
}

// END FUNCTION DEFINITIONS //

/*/ BEGIN GENERAL NOTES //

Red - R
Green - G
Blue - U
Black - B
White - W
Yellow - Y

// END GENERAL NOTES /*/
