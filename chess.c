// BEGIN INCLUDES //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// BEGIN STRUCTURE/ENUMERATION DEFINITIONS //

enum pieces
{
    pawn = 80,
    knight = 78,
    bishop = 66,
    rook = 82,
    queen = 81,
    king = 75
};

enum colors
{
    white = 35,
    black = 32
};

struct square
{
    enum pieces piece;
    enum colors piece_color;
    enum colors square_color;
};

// BEGIN FUNCTION PROTOTYPES //

struct square** setup_board(int color);

void show_board(int **board);

// BEGIN MAIN FUNCTION //

void main()
{
    int i, color;
    struct square **chessboard;

    printf("What color would you like to be?\n1) White\n2) Black\n3) Random\n");
    scanf("%d", &color);
    chessboard = setup_board(color);
    show_board(chessboard);

    return;
}



// BEGIN FUNCTION DEFINITIONS //

struct square** setup_board(int color)
{
    srand(time(NULL));
    int i, j;
    struct square **board;
    board = malloc(8 * sizeof(struct square*));
    for (i = 0; i < 8; i++)
        board[i] = malloc(8 * sizeof(struct square));

    // assign square colors
    for (i = 0; i < 8; i
    {
        for (j = 0; j < 8; j++)
        {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                board[i][j].square_color = white;
            else
                board[i][j].square_color = black;
        }
    }

    switch (color)
    {
        case 1:
            white:
            // placing black pieces on top
            board[0][0].piece = board[0][7].piece = rook;
            board[0][1].piece = board[0][6].piece = knight;
            board[0][2].piece = board[0][5].piece = bishop;
            board[0][3].piece = queen;
            board[0][4].piece = king;
            for (i = 0; i < 8; i++)
                board[1][i].piece = pawn;
            for (i = 0; i < 2; i++) // assigning black piece colors
                for (j = 0; j < 8; j++)
                    board[i][j].piece_color = black;

            // placing white pieces on bottom
            board[7][0].piece = board[7][7].piece = rook;
            board[7][1].piece = board[7][6].piece = knight;
            board[7][2].piece = board[7][5].piece = bishop;
            board[7][3].piece = queen;
            board[7][4].piece = king;
            for (i = 0; i < 8; i++)
                board[6][i].piece = pawn;
            for (i = 6; i < 8; i++) // assigning white piece colors
                for (j = 0; j < 8; j++)
                    board[i][j].piece_color = white;

            return board;
        case 2:
            black:
            // placing black pieces on top
            board[0][0].piece = board[0][7].piece = rook;
            board[0][1].piece = board[0][6].piece = knight;
            board[0][2].piece = board[0][5].piece = bishop;
            board[0][3].piece = king;
            board[0][4].piece = queen;
            for (i = 0; i < 8; i++)
                board[1][i].piece = pawn;
            for (i = 0; i < 2; i++) // assigning black piece colors
                for (j = 0; j < 8; j++)
                    board[i][j].piece_color = white;

            // placing white pieces on bottom
            board[7][0].piece = board[7][7].piece = rook;
            board[7][1].piece = board[7][6].piece = knight;
            board[7][2].piece = board[7][5].piece = bishop;
            board[7][3].piece = king;
            board[7][4].piece = queen;
            for (i = 0; i < 8; i++)
                board[6][i].piece = pawn;
            for (i = 6; i < 8; i++) // assigning white piece colors
                for (j = 0; j < 8; j++)
                    board[i][j].piece_color = black;

            return board;
        case 3:
            int rnd = rand() % 2;
            if (rnd)
                goto black;
            else
                goto white;
    } // end switch
}

void show_board(int **board)
{
    int i, j;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("+---+---+---+---+---+---+---+---+\n");
            printf("|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|\n",
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color);
            printf("|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|\n",
                board[i][j].square_color, board[i][j].piece, board[i][j].square_color,
                board[i][j].square_color, board[i][j].piece, board[i][j].square_color,
                board[i][j].square_color, board[i][j].piece, board[i][j].square_color,
                board[i][j].square_color, board[i][j].piece, board[i][j].square_color,
                board[i][j].square_color, board[i][j].piece, board[i][j].square_color,
                board[i][j].square_color, board[i][j].piece, board[i][j].square_color,
                board[i][j].square_color, board[i][j].piece, board[i][j].square_color,
                board[i][j].square_color, board[i][j].piece, board[i][j].square_color);
            printf("|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|%c%c%c|\n",
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color,
                board[i][j].square_color, board[i][j].square_color, board[i][j].square_color);
        }
    }
    printf("+---+---+---+---+---+---+---+---+\n");
}
