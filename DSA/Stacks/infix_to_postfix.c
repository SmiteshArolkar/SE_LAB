#include <stdio.h>
#include <string.h>
#define max 50
void inflix_postflix(char[], char[]);
int incoming(char);
int instack(char);
int pop();
void push(char);
int is_empty();
int is_full();
char stack[max];
int top = -1;
void inflix_postflix(char inflix[], char postflix[])
{
	puts(inflix);
	int i, p = 0, n;
	char symbol, next;
	n = strlen(inflix);
	for (i = 0; i < n; i++)
	{
		symbol = inflix[i];
		switch (symbol)
		{
		case '(':
			push(symbol);
			break;
		case ')':
			while ((next = pop()) != '(')
			{
				postflix[p++] = next;
			}
			break;
		case '^':
		case '%':
		case '/':
		case '*':
		case '-':
		case '+':
			while (incoming(symbol) <= instack(stack[top]) && (top != -1))
			{
				postflix[p++] = pop();
			}
			push(symbol);
			break;
		default:
			postflix[p++] = symbol;
		}
	}
	while (!is_empty())
	{
		postflix[p++] = pop();
	}
	postflix[p] = '\0';
}

int incoming(char s)
{
	switch (s)
	{
	case '^':
		return 4;
		break;
	case '%':
	case '/':
	case '*':
		return 2;
		break;
	case '-':
	case '+':
		return 1;
		break;
	case '(':
		return 0;
	}
}
int instack(char s)
{
	switch (s)
	{
	case '(':
		return 0;
	case '^':
		return 3;
		break;
	case '/':
	case '%':
	case '*':
		return 2;
		break;
	case '-':
	case '+':
		return 1;
		break;
	}
}
int pop()
{
	if (is_empty())
	{
		printf("stack underflow ....\n");
	}
	else
	{
		return (stack[top--]);
	}
}
void push(char data)
{
	if (is_full())
	{
		printf("stack overflow....\n");
	}
	else
	{
		stack[++top] = data;
	}
}
int is_empty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
int is_full()
{
	if (top == max - 1)
		return 1;
	else
		return 0;
}
int main()
{
	char postflix[30];
	char inflix[30];
	printf("enter the inflix expression :");
	gets(inflix);
	inflix_postflix(inflix, postflix);
	printf("the expression is :");
	printf("%s\n", postflix);
	return 0;
}