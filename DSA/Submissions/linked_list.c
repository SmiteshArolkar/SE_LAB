#include <stdio.h>
struct NODE
{
	int info;
	struct NODE *link;
};
typedef struct NODE node;
node *addbegin(node *start, int data)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
}
node *add_end(node *start, int data)
{
	node *temp = start, *p;
	p = (node *)malloc(sizeof(node));
	p->info = data;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = p;
	p->link = NULL;
	return start;
}
node *createlist(node *start, int size)
{
	int data;
	if (size > 0)
	{
		printf("enter the data :");
		scanf("%d", &data);
		start = addbegin(start, data);
		for (int i = 2; i <= size; i++)
		{
			printf("enter the data :");
			scanf("%d", &data);
			start = add_end(start, data);
		}
	}
	return start;
}
node *add_before(node *start, int data, int item)
{
	node *p, *temp;
	if (start == NULL)
	{
		printf("list is empty ....");
		return start;
	}
	if (start->info == item)
	{
		temp = (node *)malloc(sizeof(node));
		temp->info = data;
		temp->link = start;
		start = temp;
		return start;
	}
	p = start;
	while (p->link != NULL)
	{
		if (p->link->info == item)
		{
			temp = (node *)malloc(sizeof(node));
			temp->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
	}
	printf("its not found ....\n");
}
node *add_after(node *start, int data, int item)
{
	node *p, *temp;
	p = start;
	while (p != NULL)
	{
		if (p->info == item)
		{
			temp = (node *)malloc(sizeof(node));
			temp->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
	}
	printf("item not found .....\n");
	return start;
}
node *add_position(node *start, int data, int pos)
{
	node *temp, *p;
	p = start;
	int i;
	temp = (node *)malloc(sizeof(node));
	temp->info = data;
	if (pos == 1)
	{
		temp->link = start;
		start = temp;
		return start;
	}
	for (i = 0; i < pos - i && p != NULL; i++)
		p = p->link;
	if (p == NULL)
	{
		printf("positon limit exceeded\n");
		return start;
	}
	else
	{
		temp->link = p->link;
		p->link = temp;
		return start;
	}
}
int count(node *start)
{
	int count = 0;
	node *temp = start;
	while (temp != NULL)
	{
		temp = temp->link;
		count++;
	}
	return count;
}
void search(node *start, int data)
{
	int n = 1;
	node *temp = start;
	if (start == NULL)
	{
		printf("the list is empty ...");
		return start;
	}
	while (temp != NULL)
	{
		if (temp->info == data)
		{
			printf("element %d is found at location %d...\n", data, n);
			return start;
		}
		n++;
		temp = temp->link;
	}
	printf("element not found....");
}
node *delete(node *start, int data)
{
	node *temp = start, *temp2;
	temp2 = temp->link;
	if (start->info == data)
	{
		start = start->link;
		free(temp);
		return start;
	}
	while (temp->link != NULL)
	{
		if (temp2->info == data)
		{
			temp->link = temp2->link;
			free(temp2);
			return start;
		}
		temp = temp->link;
		temp2 = temp2->link;
	}
	printf("the element is not found ....\n");
	return start;
}
node *reverse(node *start)
{
	node *next, *prev, *ptr;
	ptr = start;
	prev = NULL;
	while (ptr != NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}
void display(node *start)
{
	node *temp = start;
	printf("the linked list is :");
	while (temp != NULL)
	{
		printf("%d ", temp->info);
		temp = temp->link;
	}
}
int main()
{
	node *start = NULL;
	int choice, n, data, size = 0, pos, item;
	do
	{
		printf("1:creation\n2:add at beginning\n3:add at end\n4:insertion before\n5:insertion after\n6:insertion at position\n7:count\n8:searching\n9:deletion\n10:reverse\n11:display\nENTER YOUR CHOICE :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter the number of nodes :");
			scanf("%d", &size);
			start = createlist(start, size);
			break;
		case 2:
			printf("enter the number :");
			scanf("%d", &data);
			start = addbegin(start, data);
			break;
		case 3:
			printf("enter the element :");
			scanf("%d", &data);
			start = add_end(start, data);
			break;
		case 4:
			printf("enter the element :");
			scanf("%d", &data);
			printf("enter the number before which the number is to be inserted :");
			scanf("%d", &item);
			start = add_before(start, data, item);
			break;
		case 5:
			printf("enter the element :");
			scanf("%d", &data);
			printf("enter the number after which the number is to be inserted :");
			scanf("%d", &item);
			start = add_after(start, data, item);
		case 6:
			printf("enter the element to be stored :");
			scanf("%d", &data);
			printf("enter the pos :");
			scanf("%d", &pos);
			start = add_position(start, data, pos);
			break;
		case 7:
			size = count(start);
			printf("COUNT=%d\n", size);
			break;
		case 8:
			printf("enter the data :");
			scanf("%d", &data);
			search(start, data);
			break;
		case 9:
			printf("enter the element :");
			scanf("%d", data);
			start = delete (start, data);
		case 10:
			start = reverse(start);
		case 11:
			display(start);
			printf("\n");
			break;
		case 0:
			exit(1);
		default:
			printf("wrong choice ...");
			break;
		}
	} while (choice);
	return 0;
}