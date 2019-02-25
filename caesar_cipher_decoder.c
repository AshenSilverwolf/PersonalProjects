#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char offset_char(char *cad, int offset)
{
    if (isupper(*cad))
    {
        *cad += offset;
        while (*cad > 90)
        {
            *cad -= 26;
        }
    }
    else if (islower(*cad))
    {
        *cad += offset;
        while (*cad > 122)
        {
            *cad -= 26;
        }
    }
}

int main()
{
    char buffer[1000];
    int choice, offset, i, j;

    printf("Please enter your text to be decoded.\n");
    fgets(buffer, 1000, stdin);

    printf("Please choose your method of decoding:\n1) Particular Offset\n2) Brute Force\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Please enter offset: ");
            scanf("%d", &offset);

            for (i = 0; i < strlen(buffer); i++)
            {
                if (isalpha(buffer[i]))
                    offset_char(&buffer[i], offset);

                printf("%c", buffer[i]);
            }
            break;
        case 2:
            printf("ENGAGE BRUTE FORCE DECODE\nDisplaying all possible offsets.\n");

            for (i = 1; i < 26; i++)
            {
                printf("%d: ", i);
                for (j = 0; j < strlen(buffer); j++)
                {
                    if (isalpha(buffer[i]))
                        offset_char(&buffer[i], 1);

                    printf("%c", buffer[i]);
                }
                printf("\n\n");
            }
            break;
        default:
            printf("Incorrect Input. Goodbye.\n");
            exit(0);
    }

    return 0;
}
