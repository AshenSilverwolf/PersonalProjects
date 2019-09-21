#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void main()
{
    char **board;
    board = calloc(3, sizeof(char*));
    for (int i=0; i<3; i++)
    {
        board[i] = calloc(10, sizeof(char));
        printf("What name? ");
        scanf("%s", board[i]);
    }

    for (int i=0; i<3; i++)
    {
        printf("%d: %s\n", i+1, board[i]);
    }
}