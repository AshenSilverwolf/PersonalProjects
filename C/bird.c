#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct PetBird
{
	char name[20], color[10];
	int age;
};

void askInfo(struct PetBird *bird)
{
	printf("What is you bird's name?\n");
	scanf("%s", bird->name);
	printf("What color is your bird?\n");
	scanf("%s", bird->color);
	printf("How old is your bird?\n");
	scanf("%d", &bird->age);
}

void showInfo(struct PetBird *bird)
{
	printf("%s, %s: %d\n", 
		bird->name, bird->color, bird->age);
}

int main()
{
	struct PetBird *pb;

	pb = malloc(sizeof(struct PetBird));

	askInfo(pb);
	showInfo(pb);

	free(pb);

	return 0;
}