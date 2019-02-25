#include <stdio.h>
#include <stdlib.h>

int main()
{

    #define MAX 20

    char name [MAX];

    printf( "We are going to learn your name!\n\n" );

    printf("What is your name?\n");
    //gets(name);
    /*
    gets() reads user input until it encounters a newline character
    the big issue is that it doesn't have a limit on how many characters it will attempt to store within the associated array
    if your array limit is 20, and your input is greater than 20 characters, you risk a buffer overflow error
    */

    // fgets( char *str, int n, stdin );
    /*
    parameter 1 is your array of characters (you don't actually use the asterisk in your code, just the variable name
    parameter 2 is your max input size. You can set this equal to your actual array size to avoid buffer overflow
    parameter 3 is stdin, meaning that fgets() will read from the standard input, the same kind used in scanf()

    fgets() is much safer than gets() because it has a limit parameter that you can set equal to your max array size
    if used correctly, you can avoid the risk of a buffer overflow error
    */
    fgets(name, MAX, stdin);

    strtok(name, "\n"); /* what strtok() seems to do is go through the specific character array (the first parameter),
                        and run through it until it hits the specified character (the second parameter), and removes that character */

    printf("\n%s is your name!\n", name); /* Prints the exact string received from gets() */
    printf("The third letter of your name is %c.\n\n", name[2]); /* prints the character found within index 2 (spot 3) of the name array */

    printf("This is your name in all lowercase: %s\n", strlwr(name)); /* strlwr() is a function that returns the string, but in all lowercase letters */
    printf("And this is your name in all uppercase: %s\n", strupr(name)); /* likewise, strupr() is the complete opposite, returning the string in all uppercase */

    return 0;
}


/* I HAD BEEN TRYING TO FIND A WAY AROUND THE SCANF(%C) ISSUE FOR WEEKS AND ALL OF A SUDDEN, I DISCOVER GETS() AND THAT JUST SOLVES ALL OF LIFE'S PROBLEMS APPARENTLY */
