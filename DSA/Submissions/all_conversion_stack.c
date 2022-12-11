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
	return stack[i];
}
int main()
{
	char stackb[50], stacko[30], stackh[20];
	int topb = -1, topo = -1, toph = -1, n, m, k;
	printf("enter the number :");
	scanf("%d", &n);
	m = n;
	while (m > 0)
	{
		push(m % 2, &topb, stackb);
		m /= 2;
	}
	m = n;
	while (m > 0)
	{
		push(m % 8, &topo, stacko);
		m /= 8;
	}
	m = n;
	while (m > 0)
	{
		push(m % 16, &toph, stackh);
		m /= 16;
	}
	printf("\nbinary number :");
	for (int i = topb; i >= 0; i--)
		printf("%c", pop(stackb, i));
	printf("\noctal number :");
	for (int i = topo; i >= 0; i--)
		printf("%c", pop(stacko, i));
	printf("\nhexa decimal number :");
	for (int i = toph; i >= 0; i--)
		printf("%c", pop(stackh, i));
	return 0;
}