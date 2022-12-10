#include<stdio.h>
#include<string.h>
int flag=1;
void push(char stack[],int *top,char symbol)
{
	stack[++(*top)]=symbol;
}
int pop(int top)
{
	if(is_empty(top))
	{
		flag=0;
	}
	else
	return (top-1);
}
int is_empty(int top)
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int main()
{
	char  stackr[20],stacks[20],stackc[20],parenthesis[30],symbol;
	int topr,tops,topc,n;
	topr=-1;
	tops=-1;
	topc=-1;
	printf("enter a series of prenthesis :");
	scanf("%s",parenthesis);
	n=strlen(parenthesis);
	for(int i=0;i<n;i++)
	{
		symbol=parenthesis[i];
		switch(symbol)
		{
			case '(':push(stackr,&topr,symbol);break;
			case '[':push(stacks,&tops,symbol);break;
			case '{':push(stackc,&topc,symbol);break;
			case ')':topr=pop(topr);break;
			case ']':tops=pop(tops);break;
			case '}':topc=pop(topc);break;
			default:break;
		}
	}
	if((!is_empty(topr)) || (!is_empty(tops)) || (!is_empty(topc)))
	{
		flag=0;
	}
	if(flag)
	printf("\n\t<<BALANCED>>");
	else
	printf("\n\t<<NOT BALANCED>>");
	return 0;
}