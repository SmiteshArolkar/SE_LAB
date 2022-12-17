#include <stdio.h>
#include <malloc.h>
struct NODE
{
	int data;
	struct NODE *next;
};
typedef struct NODE node;
node *front = NULL;
node *rear = NULL;
void insert(int);
void del();
void display();
void peek();
void insert(int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	if (front == NULL)
		front = rear = temp;
	else
	{
		rear->next = temp;
		rear = temp;
	}
}
void del()
{
	if (front == NULL)
	{
		printf("empty queue ....\n");
	}
	else if (front == rear)
	{
		printf("the number %d has been deleted ...\n", front->data);
		free(front);
		front = rear = NULL;
	}
	else
	{
		node *temp = front;
		printf("the number %d has been deleted ...\n", front->data);
		front = front->next;
		free(temp);
	}
}
void display()
{
	if (front == NULL)
	{
		printf("empty queue ....\n");
		return;
	}
	node *temp = front;
	printf("stack contents : ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void peek()
{
	if (front == NULL)
	{
		printf("empty queue ....\n");
		return;
	}
	else
		printf("the front element is : %d", front->data);
	printf("\n");
}
int main()
{
	int choice, data;
	do
	{
		printf("\n1:insert \n2:delete \n3:display\n4:peek\n0:exit\nENTER YOUR CHOICE : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter the data : ");
			scanf("%d", &data);
			insert(data);
			break;
		case 2:
			del();
			break;
		case 3:
			display();
			break;
		case 4:
			peek();
			break;
		case 0:
			break;
		default:
			printf("wrong choice ...\n");
			break;
		}
	} while (choice);
	return 0;
}