#include <stdio.h>
void push(int m, int *top, char stack[])
{
	if (m >= 0 && m <= 9)
		stack[++(*top)] = m + 48;
	else
		stack[++(*top)] = m + 55;
}
int pop(char stack[], int i)
{
	if (i == -1)
		printf("empty stack....");
	else
		return stack[i];
}
int main()
{
	char stack[50];
	int top = -1, n, m, k;
	printf("enter the number :");
	scanf("%d", &n);
	m = n;
	printf("2:binary 8:octal 16:hexadecimal \n");
	printf("enter the base :");
	scanf("%d", &k);
	while (m > 0)
	{
		push(m % k, &top, stack);
		m /= k;
	}
	printf("the number in %d system is :", k);
	for (int i = top; i >= 0; i--)
		printf("%c", pop(stack, i));
	return 0;
}