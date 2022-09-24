#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 50
int postflix_eval(char[]);
int stack[MAX];
int power(int, int);
int top = -1;
int prefix_eval(char prefix[])
{
	int temp;
	int i, n = strlen(prefix);
	int a, b;
	for (i = n - 1; i >= 0; i--)
	{
		char symbol = prefix[i];
		if (symbol <= '9' && symbol >= '0')
		{
			int t = symbol - '0';
			push(t);
		}
		else
		{
			a = pop();
			b = pop();
			switch (symbol)
			{
			case '+':
				temp = a + b;
				break;
			case '*':
				temp = a * b;
				break;
			case '-':
				temp = a - b;
				break;
			case '/':
				temp = a / b;
				break;
			case '%':
				temp = a % b;
				break;
			case '^':
				temp = power(a, b);
				break;
			}
			push(temp);
		}
	}
	return pop();
}
void push(int data)
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
int pop()
{
	if (is_empty())
		printf("stack underflow ...\n");
	else
	{
		return stack[top--];
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
	if (top == MAX - 1)
		return 1;
	else
		return 0;
}
int power(int a, int b)
{
	if (b == 1)
		return a;
	else
		return a * power(a, b - 1);
}
int main()
{
	int eval;
	char prefix[30];
	printf("enter the prefix :");
	scanf("%s", prefix);
	eval = prefix_eval(prefix);
	printf("the evaluated expression is :%d", eval);
	return 0;
}
