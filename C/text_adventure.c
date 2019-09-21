#include <stdio.h>
#include <stdlib.h>

int main()
{

    int choice, score = 0;

    printf("You are walking through a dark cave, with a sword in your right hand, and a torch in your left.\n");
    printf("You approach a dead-end, and see a chicken standing against the wall, looking at you.\n");
    printf("What do you do?\n");
    printf("1. Slay the chicken\n2. Turn around and walk away\n3. Pick up the chicken\n");

    do {
        printf("Your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("You stand there, wondering what to do...\n\n");
        }
    } while (choice < 1 || choice > 3);

    if (choice == 1) {
        printf("\nYour sword cuts through the chicken.\n");
        printf("You hear a faint squack as the chicken takes it's last breath, and the cave begins to shake.\n");
        printf("You are crushed by falling rocks. You are dead.\n");
        score -= 100;
    } else if (choice == 2) {
        printf("\nYou turn your back to the chicken, and begin retracing your steps out of the cavern.\n");
        printf("You emerge on the surface, and begin your journey to the nearest town.\n");
        score += 10;
    } else if (choice == 3) {
        printf("\nYou sheathe your sword, lay down your torch, and approach the chicken slowly.\n");
        printf("In one swift movement, you grab the chicken and hold it under your arm.\n");
        printf("It squacks affectionately in response to your loving embrace.\n");
        printf("You pick up your torch, and continue your journey through the cavern with your newfound friend.\n");
        score += 500;
    }

    printf("\nThe End\n");
    printf("Your Score: %d\n", score);

    return 0;
}
