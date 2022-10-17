#include <stdio.h>
#include <string.h>
#define max 50
void inflix_prefix(char[], char[]);
int incoming(char);
int instack(char);
char pop();
void push(char);
int is_empty();
int is_full();
char stack[max];
void display();
int top = -1;
void inflix_prefix(char inflix[], char prefix[])
{
	int i, p = 0, n;
	char symbol, next;
	n = strlen(inflix);
	for (i = n - 1; i >= 0; i--)
	{
		symbol = inflix[i];
		switch (symbol)
		{
		case ')':
			push(symbol);
			break;
		case '(':
			next = pop();
			while (next != ')')
			{
				prefix[p++] = next;
				next = pop();
			}
			break;
		case '^':
		case '%':
		case '/':
		case '*':
		case '-':
		case '+':
			while (incoming(symbol) < instack(stack[top]) && (top != -1))
			{
				prefix[p++] = pop();
			}
			push(symbol);
			break;
		default:
			prefix[p++] = symbol;
			break;
		}
	}
	while (top != -1)
		prefix[p++] = pop();
	prefix[p] = '\0';
	for (int i = 0; i < p / 2; i++)
	{
		char var = prefix[i];
		prefix[i] = prefix[p - 1 - i];
		prefix[p - 1 - i] = var;
	}
}

int incoming(char s)
{
	switch (s)
	{
	case ')':
		return 0;
		break;
	case '^':
		return 3;
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
	}
}
int instack(char s)
{
	switch (s)
	{
	case ')':
		return 0;
		break;
	case '^':
		return 4;
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
char pop()
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
	char prefix[30];
	char inflix[30];
	printf("enter the inflix expression :");
	gets(inflix);
	inflix_prefix(inflix, prefix);
	printf("the expression is :");
	printf("%s\n", prefix);
	return 0;
}

//  OP: enter the inflix expression :(3+3)*4/2
//     the expression is :/*+3342