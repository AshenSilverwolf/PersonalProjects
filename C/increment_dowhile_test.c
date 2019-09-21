#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{

    int tester, tracker = 0;
    int max = 10, min = 1;
    bool boo1 = false, boo2 = false, boo3 = false, boo4 = false, boo5 = false;

    do {
        printf( "Please enter a number between 1 and 10: " );
        scanf("%d", &tester);

        printf("Tracker: %d\n", tracker);

        if ((tester < min || tester > max) && boo1 == false) {
            printf( "You did not do what I said. Do it right this time.\n\n");
            boo1 = true;
            tracker++;
            continue;
        }

        if ((tester < min || tester > max) && boo2 == false) {
            printf( "Again with this? Really? Just put in the correct value please.\n\n");
            boo2 = true;
            tracker++;
            continue;
        }

        if ((tester < min || tester > max) && boo3 == false) {
            printf( "Okay this is getting ridiculous. I'm going to assume you don't understand. Put in any of the first 10 numbers.\n\n");
            boo3 = true;
            tracker++;
            continue;
        }

        if ((tester < min || tester > max) && boo4 == false) {
            printf( "Now you're just trying to mess with me. You can keep going if you like. It's only wasting your time. I am a computer program. I have no feelings.\n\n");
            boo4 = true;
            tracker++;
            continue;
        }

        if ((tester < min || tester > max) && boo5 == false) {
            printf( "You're just making a fool of yourself now. Have fun with this.\n\n");
            boo5 = true;
            tracker++;
            continue;
        }

        tracker++;

    } while (tester < min || tester > max);

    if (tracker >= 10 && tracker < 25) {
        printf("\nTook you long enough to get it right.\n");
    } else if (tracker >= 25) {
        printf("\nOkay this is just ridiculous.\n");
    }

    return 0;
}
