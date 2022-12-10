#include<stdio.h>
void push(int m,int *top,int stack[])
{
	stack[++(*top)]=m;
}
int pop(int stack[],int *top)
{
	if(top==-1)
	printf("empty stack....");
	else
	return stack[(*top)--];
}
int main()
{
	int stack[50],top=-1,n,m,rev=0;
	printf("enter the number :");
	scanf("%d",&n);
	m=n;
	while(m>0)
	{
		push(m%10,&top,stack);
		m/=10;
		rev=rev*10+pop(stack,&top);
	}
	printf("the reverse number is :%d",rev);
	return 0;
}