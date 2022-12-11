#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct NODE
{
	int info;
	struct NODE *next;
	struct NODE *prev;
};
typedef struct NODE node;
node *createlist(node *, int);
node *addbegin(node *, int);
node *add_end(node *, int);
int count(node *);
node *search(node *, int);
void display(node *);
node *add_before(node *, int);
node *add_after(node *, int);
node *add_position(node *, int, int);
node *reverse(node *);
node *delete_node(node *, int);
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
node *addbegin(node *start, int data)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->info = data;
	if (start == NULL)
	{
		temp->next = NULL;
		temp->prev = NULL;
		start = temp;
		return start;
	}
	else
	{
		temp->next = start;
		temp->prev = NULL;
		start->prev = temp;
		start = temp;
		return start;
	}
}
node *add_end(node *start, int data)
{
	node *temp = start, *p;
	p = (node *)malloc(sizeof(node));
	p->info = data;
	if (start == NULL)
	{
		start = p;
		p->prev = NULL;
		p->next = NULL;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = p;
	p->next = NULL;
	p->prev = temp;
	return start;
}
node *add_before(node *start, int data)
{
	node *temp, *p = start;
	temp = (node *)malloc(sizeof(node));
	printf("enter the number to be inserted :");
	scanf("%d", &temp->info);
	if (start->info == data)
	{
		start->prev = temp;
		temp->next = start;
		temp->prev = NULL;
		start = temp;
		return start;
	}
	else
	{
		while (p->next != NULL)
		{
			if (p->next->info == data)
			{
				temp->next = p->next;
				temp->prev = p;
				p->next->prev = temp;
				p->next = temp;
				return start;
			}
			p = p->next;
		}
	}
	printf("element not found ...\n");
	return start;
}
node *add_after(node *start, int data)
{
	node *temp, *p = start;
	temp = (node *)malloc(sizeof(node));
	printf("enter the number to be inserted :");
	scanf("%d", &temp->info);
	if (start == NULL)
	{
		printf("empty list..\n");
		return start;
	}
	while (p->next != NULL)
	{
		if (p->info == data)
		{
			temp->next = p->next;
			temp->prev = p;
			p->next->prev = temp;
			p->next = temp;
			return start;
		}
		p = p->next;
	}
	if (p->info == data)
	{
		p->next = temp;
		temp->prev = p;
		temp->next = NULL;
		return start;
	}
	else
	{
		printf("element not found ....");
		free(temp);
		return start;
	}
}
node *add_position(node *start, int data, int pos)
{
	node *temp, *p;
	p = start;
	temp = (node *)malloc(sizeof(node));
	temp->info = data;
	if (pos == 1)
	{
		temp->next = start;
		temp->prev = NULL;
		start->prev = temp;
		start = temp;
		return start;
	}
	else
	{
		int i;
		for (i = 1; i < pos - 1 && p->next != NULL; i++)
			p = p->next;
		if (!p->next)
		{
			temp->next = p->next;
			p->next->prev = temp;
			p->next = temp;
			temp->prev = p;
			return start;
		}
	}
	printf("position limit exceeded ...\n");
	return start;
}
int count(node *start)
{
	int count = 0;
	node *temp = start;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}
node *search(node *start, int data)
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
			printf("element %d is found at location %d...", data, n);
			return start;
		}
		temp = temp->next;
		n++;
	}
	printf("element not found....");
	return start;
}
node *delete_node(node *start, int data)
{
	node *p;
	p = start;
	if (start == NULL)
	{
		printf("empty list ....\n");
		return start;
	}
	if (start->info == data)
	{
		start = start->next;
		free(p);
		start->prev = NULL;
		return start;
	}
	else
	{
		p = p->next;
		while (p->next != NULL)
		{
			if (p->info == data)
			{
				p->next->prev = p->prev;
				p->prev->next = p->next;
				free(p);
				return start;
			}
			p = p->next;
		}
		if (p->info == data)
		{
			p->prev->next = NULL;
			free(p);
			return start;
		}
		printf("ELEMENT %d not found ...\n", data);
		return start;
	}
}
node *reverse(node *start)
{
	node *p, *next, *prev;
	prev = NULL;
	p = start;
	while (p != NULL)
	{
		next = p->next;
		p->next = prev;
		p->prev = next;
		prev = p;
		p = next;
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
		temp = temp->next;
	}
}
int main()
{
	node *start = NULL;
	int choice, n, data, size = 0, pos;
	do
	{
		printf("\n1:creation\n2:add at beginning\n3:add at end\n4:insertion before\n5:insertion after\n6:insertion at position\n7:count\n8:searching\n9:deletion\n10:reverse\n11:display\nENTER YOUR CHOICE :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter the number of nodes :");
			scanf("%d", &n);
			start = createlist(start, n);
			break;
		case 2:
			printf("enter the number :");
			scanf("%d", &data);
			start = addbegin(start, data);
			break;
		case 3:
			printf("enter the element :");
			scanf("%d", &data);
			add_end(start, data);
			break;
		case 4:
			printf("enter the element :");
			scanf("%d", &data);
			start = add_before(start, data);
			break;
		case 5:
			printf("enter the element :");
			scanf("%d", &data);
			start = add_after(start, data);
			break;
		case 6:
			printf("enter the element to be stored :");
			scanf("%d", &data);
			printf("enter the pos :");
			scanf("%d", &pos);
			start = add_position(start, data, pos);
			break;
		case 7:
			size = count(start);
			printf("the number of elements in the list is :%d\n", size);
			break;
		case 8:
			printf("enter the data :");
			scanf("%d", &data);
			start = search(start, data);
			break;
		case 9:
			printf("enter the element :");
			scanf("%d", &data);
			start = delete_node(start, data);
			break;
		case 10:
			start = reverse(start);
			break;
		case 11:
			display(start);
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
