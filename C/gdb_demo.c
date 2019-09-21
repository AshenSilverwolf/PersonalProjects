#include <stdio.h>

int* bullshit(int *a)
{
    a = 69;
    return a;
}

int main()
{
    int *p;
    int i = 420;
    p = &i;

    printf("%d\n", *p);

    p = bullshit(p);

    printf("%d\n", *p);

    return 0;
}

/*

- This is to compile the test file with the GDB stuff
gcc -g testfile.c -o test

- This is to run the program in debug mode within GDB
gdb ./test

*/
