#include<stdio.h>
#include<malloc.h>
struct NODE
{
	int info;
	struct NODE *next;
};
typedef struct NODE node;
node*altdel(node *,int);
node * createlist(node*,int);
void display(node*);
node*createlist(node *last,int size)
{
	if(size>0)
	{
		int data;
		node *tmp;
		printf("Enter data :");
		scanf("%d",&data);
		tmp=(node*)malloc(sizeof(node));
		tmp->info=data;
		tmp->next=tmp;
		last=tmp;
		for(int i=1;i<size;i++)
		{
			printf("Enter data :");
		    scanf("%d",&data);
			tmp=(node*)malloc(sizeof(node));
			tmp->info=data;
			tmp->next=last->next;
			last->next=tmp;
			last=tmp;
		}
		return last;
	}
}
void display(node*last)
{
	if(last==NULL)
	{
		printf("The list is empty...\n");
		return;
	}
	node *tmp=last->next;
	do
	{
		printf("%d ",tmp->info);
		tmp=tmp->next;
	}while(tmp!=last->next);
}
node *altdel(node*last,int n)
{
	if(last==NULL)
	printf("empty list :");
	if(last->next==last)
	return last;
	else
	{
		node *tmp=last->next;
		if(n&1)
		{
		do
		{
			node *q=tmp->next;
			tmp->next=q->next;
			free(q);
			tmp=tmp->next;
			//printf("\nlis :");
			//display(last);
		}while(tmp!=last);
		}
		else
		{
            do
		{
			node *q=tmp->next;
			tmp->next=q->next;
			free(q);
			tmp=tmp->next;
			//printf("\nlis :");
			//display(last);
		}while(tmp->next!=last);
			tmp->next=last->next;
			free(last);
			return tmp;
		}

	}

}
int main()
{
	int n;
	node *last=NULL;
	printf("enter the number of nodes required : ");
	scanf("%d",&n);
	last=createlist(last,n);
	printf("the original list is : ");
	display(last);
	last=altdel(last,n);
	printf("\nthe list after deletion is : ");
	display(last);
	return 0;
}
