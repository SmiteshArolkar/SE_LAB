#include <stdio.h>
#include <malloc.h>
struct NODE
{
	int val;
	struct NODE *lchild;
	struct NODE *rchild;
};
struct NODES
{
	int info;
	struct NODES *link;
};
typedef struct NODE node;
typedef struct NODES list;
void CRRLevel(node *root, int level);
int height(node *node);
void spiral_level(node *root, int level, int ltr);
list *addbegin(list *start, int data)
{
	list *temp;
	temp = (list *)malloc(sizeof(list));
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
}
list *add_end(list *start, int data)
{
	list *temp = start, *p;
	p = (list *)malloc(sizeof(list));
	p->info = data;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = p;
	p->link = NULL;
	return start;
}
list *createlist(list *start, int size)
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
void display(list *start)
{
	if (start != NULL)
	{
		list *temp = start;
		while (temp != NULL)
		{
			printf("%d ", temp->info);
			temp = temp->link;
		}
	}
	printf("\n");
}
node *createtree(list *in, list *post, int size)
{
	node *temp;
	list *inp, *postp;
	int i, j;
	if (size == 0)
		return NULL;
	postp = post;
	for (i = 1; i < size; i++)
	{
		postp = postp->link;
	}
	temp = (node *)malloc(sizeof(node));
	temp->val = postp->info;
	temp->lchild = temp->rchild = NULL;
	if (size == 1)
		return temp;
	inp = in;
	for (i = 0; inp->info != postp->info; i++)
		inp = inp->link;
	temp->lchild = createtree(in, post, i);
	for (int j = 1; j <= i; j++)
		post = post->link;
	temp->rchild = createtree(inp->link, post, size - i - 1);
	return temp;
}
void displayin(node *root)
{
	if (root == NULL)
		return;
	displayin(root->lchild);
	printf(" %d", root->val);
	displayin(root->rchild);
}
void displaypost(node *root)
{
	if (root == NULL)
		return;
	displaypost(root->lchild);
	displaypost(root->rchild);
	printf(" %d", root->val);
}
void displaypre(node *root)
{
	if (root == NULL)
		return;
	printf(" %d", root->val);
	displaypre(root->lchild);
	displaypre(root->rchild);
}
void CRRLevel(node *root, int level);
int height(node *node);

void LevelOrder(node *root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		CRRLevel(root, i);
}

void CRRLevel(node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->val);
	else if (level > 1)
	{
		CRRLevel(root->lchild, level - 1);
		CRRLevel(root->rchild, level - 1);
	}
}
int height(node *node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lheight = height(node->lchild);
		int rheight = height(node->rchild);

		if (lheight > rheight)
		{
			return (lheight + 1);
		}
		else
		{
			return (rheight + 1);
		}
	}
}
void spiral(node *root)
{
	int h = height(root);
	int i;
	int ltr = 0;
	for (i = 1; i <= h; i++)
	{
		spiral_level(root, i, ltr);
		ltr = !ltr;
	}
}
void spiral_level(node *root, int level, int ltr)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->val);

	else if (level > 1)
	{
		if (ltr)
		{
			spiral_level(root->lchild, level - 1, ltr);
			spiral_level(root->rchild, level - 1, ltr);
		}
		else
		{
			spiral_level(root->rchild, level - 1, ltr);
			spiral_level(root->lchild, level - 1, ltr);
		}
	}
}
int main()
{
	list *in, *post;
	int size, h;
	in = post = NULL;
	node *root = NULL;
	int c;
	do
	{
		printf("\n1)Create Tree\n2)Level Order\n3)Spiral Order\n4)hieght");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf("enter the number of keys : ");
			scanf("%d", &size);
			printf("\nINORDER TREE\n");
			in = createlist(in, size);
			printf("\nPOSTORDER TREE\n");
			post = createlist(post, size);
			printf("inorder tree : ");
			display(in);
			printf("postorder tree : ");
			display(post);
			root = createtree(in, post, size);
			printf("\nInorder Tree\n");
			displayin(root);
			printf("\nPostorder Tree\n");
			displaypost(root);
			printf("\nPreorder Tree\n");
			displaypre(root);
			/* code */
			break;
		case 2:
			printf("\nLevel Order Traversal :");
			LevelOrder(root);

			/* code */
			break;
		case 3:
			printf("\nSpiral Order traversal : ");

			spiral(root);
			/* code */
			break;
		case 4:
			h = height(root);
			printf("\nHEIGHT = %d", h);
			/* code */
			break;

		default:
			break;
		}
	} while (c);

	return 0;
}

/*
OP
/tmp/GXtXrLGrvm.o
enter the number of keys : 7
INORDER TREE
enter the data :1
enter the data :2
enter the data :3
enter the data :6
enter the data :7
enter the data :8
enter the data :9
POSTORDER TREE
enter the data :2
enter the data :3
enter the data :1
enter the data :7
enter the data :9
enter the data :8
enter the data :6
inorder tree : 1 2 3 6 7 8 9
postorder tree : 2 3 1 7 9 8 6

Inorder Tree
 1 2 3 6 7 8 9
Postorder Tree
 2 3 1 7 9 8 6
Preorder Tree
 6 1 3 2 8 7 9
Level Order Traversal :6 1 8 3 7 9 2
Spiral Order traversal : 6 1 8 9 7 3 2
HEIGHT = 4
*/