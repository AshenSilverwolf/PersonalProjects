#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    char choice;

    printf("Would you like my help in deciding what you will be having to eat? (y/n): ");
    scanf("%c", &choice);

    if (choice == 'y') {
        printf("\nHere are your choices:\n");
        printf("1. Ramen\n2. Mac n' Cheese\n3. Tuna\n4. Turkey Sandwich\n5. Hot Pockets\n6. Chicken Alfredo\n7. Garlic Chicken\n\n");

        srand(time(NULL));

        int rnd = (rand() % 7) + 1;

        if (rnd == 1) {
            printf("You're having Ramen, this time.\n\n");
        } else if (rnd == 2) {
            printf("You're having Macaroni, this time.\n\n");
        } else if (rnd == 3) {
            printf("You're having a Tuna Sandwich, I guess.\n\n");
        } else if (rnd == 4) {
            printf("You're having a Turkey Sandwich, sadly.\n\n");
        } else if (rnd == 5) {
            printf("You're having some Hot Pockets.\n\n");
        } else if (rnd == 6) {
            printf("You're having some delicious Chicken Alfredo.\n\n");
        } else if (rnd == 7) {
            printf("You're having some Garlic Chicken. Noice.\n\n");
        } else {
            printf("Fix your fucking program first, god damn.\n\n");
        }

        printf("Thanks for using me, now go fuck yourself.\n");
    } else if (choice == 'n') {
        printf("\nNO? Well then, why the fuck are you talking to me? Go make your food and let me fucking sleep.\n");
        return 0;
    } else {
        printf("Either pick 'y' or 'n', or go fuck off.\n\n");
    }

    return 0;
}
