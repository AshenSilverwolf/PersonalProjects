#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct charStack {
	int top;
	int capacity;
	char *array;
};

struct intStack {
	int top;
	int capacity;
	int *array;
};

int stackIsEmpty(struct charStack *stacky);

char* menu();

int isBalancedParenthesis(char *infix);

int isOperator(char c);

int getOperatorPriority(char c);

int convertToInt(char c);

int calculate(int a, int b, char op);

char* convertToPostfix(char *infix);

void evaluate(char *postfix);

int power(int a, int b);

void main() {
	char *str, *postFix;
	str = menu();

	while (strcmp(str, "exit") != 0)
	{
		if (isBalancedParenthesis(str))
		{
			postFix = convertToPostfix(str);
			evaluate(postFix);
		}
		else
		{
			printf("Parenthesis imbalanced\n");
		}

		str = menu();
	}
}

char* menu()
{
	char *response;
	char *infix;

	response = malloc(sizeof(char));
	infix = malloc(50 * sizeof(char));

	printf("Would you like to enter an infix expression or exit the program?\n'e' to enter infix\n'x' to exit\n");
	scanf("%s", response);

	if (response[0] == 'e')
	{
		scanf("%s", infix);
	}
	else if (response[0] == 'x')
	{
		strcpy(infix, "exit");
	}

	return infix;
}

int isBalancedParenthesis(char *infix)
{
	int i, open = 0, closed = 0;

	for (i = 0; i < strlen(infix); i++)
	{
		if (infix[i] == '(')
			open++;
		else if (infix[i] == ')')
			closed++;
	}

	if (open == closed)
		return 1;
	else
		return 0;
}

char* convertToPostfix(char *infix)
{
	struct charStack *stacky;
	stacky = malloc(sizeof(struct charStack));
	stacky->top = -1;
	stacky->capacity = 50;
	stacky->array = malloc(stacky->capacity * sizeof(char));
	char *postfix = malloc(strlen(infix) * sizeof(char));
	int i, j = 0;

	for (i = 0; i < strlen(infix); i++)
	{
		if (isdigit(infix[i]))
		{
			postfix[j++] = infix[i];
		}
		else if (infix[i] == '(')
		{
			stacky->array[++stacky->top] = infix[i];
		}
		else if (infix[i] == ')')
		{
			while (stacky->array[stacky->top] != '(')
			{
				postfix[j++] = stacky->array[stacky->top--];
			}
			stacky->top--;
		}
		else if (infix[i] == '^')
		{
			while (!stackIsEmpty(stacky) && getOperatorPriority(infix[i]) <= getOperatorPriority(stacky->array[stacky->top]))
			{
				postfix[j++] = stacky->array[stacky->top--];
			}
			stacky->array[++stacky->top] = infix[i];
		}
		else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '%')
		{
			while (!stackIsEmpty(stacky) && getOperatorPriority(infix[i]) <= getOperatorPriority(stacky->array[stacky->top]))
			{
				postfix[j++] = stacky->array[stacky->top--];
			}
			stacky->array[++stacky->top] = infix[i];
		}
		else if (infix[i] == '+' || infix[i] == '-')
		{
			while (!stackIsEmpty(stacky) && getOperatorPriority(infix[i]) <= getOperatorPriority(stacky->array[stacky->top]))
			{
				postfix[j++] = stacky->array[stacky->top--];
			}
			stacky->array[++stacky->top] = infix[i];
		}
	}

	while (stacky->top > -1)
	{
		postfix[j++] = stacky->array[stacky->top--];
	}

	printf("%s\n", postfix);
	return postfix;
}

int stackIsEmpty(struct charStack *stacky)
{
	if (stacky->top == -1)
		return 1;
	else
		return 0;
}

int getOperatorPriority(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/' || c == '%')
		return 2;
	else if (c == '^')
		return 3;
	else if (c == '(')
		return 0;
}

int isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
		return 1;
	else
		return 0;
}

int convertToInt(char c)
{
	switch (c) 
	{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		default:
			return -1;
	}
}

void evaluate(char *postfix)
{
	struct intStack *stack;
	stack = malloc(sizeof(struct intStack));
	stack->top = -1;
	stack->capacity = 50;
	stack->array = malloc(stack->capacity * sizeof(int));
	int i, result;

	for (i = 0; i < strlen(postfix); i++)
	{
		if (isdigit(postfix[i]))
		{
			stack->array[++stack->top] = convertToInt(postfix[i]);
		}
		else if (isOperator(postfix[i]))
		{
			stack->array[++stack->top] = calculate(stack->array[stack->top--], stack->array[stack->top--], postfix[i]);
		}
	}

	printf("The result of the postfix calculation is %d.\n", stack->array[stack->top--]);
}

int calculate(int a, int b, char op)
{
	if (op == '+')
	{
		return a + b;
	}
	else if (op == '-')
	{
		return a - b;
	}
	else if (op == '*')
	{
		return a * b;
	}
	else if (op == '/')
	{
		return a / b;
	}
	else if (op == '%')
	{
		return a % b;
	}
	else if (op == '^')
	{
		return power(a, b);
	}
}

int power(int a, int b)
{
	int i, result = 1;

	for (i = 0; i < b; i++)
		result *= a;

	return result;
}