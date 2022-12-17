#include <stdio.h>
void push(int m, int *top, int stack[])
{
	stack[++(*top)] = m;
}
int pop(int stack[], int *top)
{
	if (top == -1)
		printf("empty stack....");
	else
		return stack[(*top)--];
}
int main()
{
	int stack[50], top = -1, n, m, pal = 0;
	printf("enter the number :");
	scanf("%d", &n);
	m = n;
	while (m > 0)
	{
		push(m % 10, &top, stack);
		m /= 10;
		pal = pal * 10 + pop(stack, &top);
	}
	if (pal == n)
		printf("pallindrome ...\n");
	else
		printf("NOT PALLINDROME ....\n");
	return 0;
}