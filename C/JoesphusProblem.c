#include <stdio.h>
#include <stdlib.h>

typedef struct Soldier {
	int data;
	struct Soldier *next;
	struct Soldier *prev;
} soldier;

soldier* create_soldier(int sequence)
{
	soldier *new = malloc(sizeof(soldier));

	new->data = sequence;
	new->next = NULL;
	new->prev = NULL;

	return new;
}

soldier* create_reverse_circle(int n)
{
	soldier *new, *head = NULL;
	int i;
	for (i = 1; i <= n; i++) 
	{
		new = create_soldier(i);
		if (head == NULL)
		{
			head = new;
			new->next = new;
			new->prev = new;
		}
		else
		{
			new->next = head;
			new->prev = head->prev;
			new->next->prev = new;
			new->prev->next = new;
			head = new;
		}
	}

	return head;
}

soldier* rearrange_circle(soldier *head)
{
	soldier *travList = head->prev;
	soldier *copy = malloc(sizeof(soldier));
	soldier *travCopy = copy;
	travCopy->data = travList->data;
	travCopy->next = malloc(sizeof(soldier));
	travList = travList->prev;

	do
	{
		travCopy->next->data = travList->data;
		travCopy->next->prev = travCopy;
		travCopy->next->next = malloc(sizeof(soldier));
		travCopy = travCopy->next;
		travList = travList->prev;
	} while (travList != head);

	travCopy->next->data = travList->data;
	travCopy->next->prev = travCopy;
	travCopy->next->next = copy;
	copy->prev = travCopy->next;

	return copy;
}

void display(soldier *head)
{
	soldier *trav = head;

	do
	{
		printf("%d\n", trav->data);
		trav = trav->next;
	} while (trav != head);
	printf("\n");
}

soldier* copyLL(soldier *head)
{
	soldier *travList = head;
	soldier *copy = malloc(sizeof(soldier));
	soldier *travCopy = copy;
	travCopy->data = travList->data;
	travCopy->next = malloc(sizeof(soldier));
	travList = travList->next;

	do
	{
		travCopy->next->data = travList->data;
		travCopy->next->prev = travCopy;
		if (travList->next != head)
		{
			travCopy->next->next = malloc(sizeof(soldier));
		}
		travCopy = travCopy->next;
		travList = travList->next;
	} while (travList != head);

	travCopy->next = copy;
	copy->prev = travCopy;

	return copy;
}

void delete(soldier *trav)
{
	soldier *n2d = trav->next;
	trav->next = trav->next->next;
	trav->next->prev = trav;
	free(n2d);
}

int kill(soldier *head, int n, int k)
{
	soldier *copy = copyLL(head);
	soldier *trav = copy;

	for (int i = 1; i < n; i++)
	{
		for (int j = 2; j < k; j++)
		{
			trav = trav->next;
		}
		delete(trav);
		trav = trav->next;
	}

	return trav->data;
}

void main()
{
	int n, k;
	printf("Please enter a number of soldiers: ");
	scanf("%d", &n);
	printf("Please enter a skip value: ");
	scanf("%d", &k);
	soldier *head = create_reverse_circle(n);
	//display(head);
	head = rearrange_circle(head);
	//display(head);
	//display(copyLL(head));
	printf("Survivor: %d\n", kill(head, n, k));
}