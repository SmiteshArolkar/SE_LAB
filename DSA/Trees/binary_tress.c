#include "stdio.h"
#include "malloc.h"

struct node
{
    int val;
    struct node *lchild;
    struct node *rchild;

    /* data */
};

struct list
{
    int info;
    struct list *next;
};
typedef struct list list;
typedef struct node node;

list *createList(list *start, int size);
void displayList(list *start);

void displayInorder(node *root);
void displayPostorder(node *root);
void displayPreorder(node *root);
void LevelOrder(node *root);
void CurrentLevel(node* root,int level);

int getTreeHeight(node *root)
{
    if (!root)
        return 0;
    else
    {
        int lheight = getTreeHeight(root->lchild);
        int rheight = getTreeHeight(root->rchild);

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

int depth(node* root,int data,int level)
{
    if(!root)
    {
        return 0;
    }
    if(root->data == data)
    {
        return level;
    }
    int downlevel = depth(root->lchild,data,level+1);
    if(downlevel != 0)
    {
        return downlevel;
    }
    downlevel = depth(root->rchild,data,level+1)
    return downlevel;
}

void spiralOrder(node* root)
{
    if(!root) return 0;
    node* stack1[100],*stack2[200];
    int top1 = -1 ,top2 = -1;
    stack1[++top] = root;
    while( top1 != -1 || top2 != -1)
    {
        while(top1 > 0)
        {
            node* Current = stack1[top1];
            top1--;

            printf("%d",Current->val);

            if(Current->lchild) stack2[++top2] = Current->lchild;
            if(Current->rchild) stack2[++top2] = Current->rchild;
        }

        while (top2 > 0)
        {
            node* current = pop(stack2);
            top2--;

            printf("%d",current->val);
            if(Current->lchild) stack1[++top1] = Current->lchild;
            if(Current->rchild) stack1[++top1] = Current->rchild;
        }
        
    }
    
}

void printGivenLevel(struct node* root, int level, int *count)
{
    if (root == NULL)
        return;
    if (level == 1)
        (*count)++;
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1, count);
        printGivenLevel(root->right, level-1, count);
    }
}

// Insertion in Threaded Binary Search Tree.

struct Node
{
	struct Node *left, *right;
	int info;

	// False if left pointer points to predecessor
	// in Inorder Traversal
	bool lthread;

	// False if right pointer points to successor
	// in Inorder Traversal
	bool rthread;
};

// Insert a Node in Binary Threaded Tree
struct Node *insert(struct Node *root, int ikey)
{
	// Searching for a Node with given value
	Node *ptr = root;
	Node *par = NULL; // Parent of key to be inserted
	while (ptr != NULL)
	{
		// If key already exists, return
		if (ikey == (ptr->info))
		{
			printf("Duplicate Key !\n");
			return root;
		}

		par = ptr; // Update parent pointer

		// Moving on left subtree.
		if (ikey < ptr->info)
		{
			if (ptr -> lthread == false)
				ptr = ptr -> left;
			else
				break;
		}

		// Moving on right subtree.
		else
		{
			if (ptr->rthread == false)
				ptr = ptr -> right;
			else
				break;
		}
	}

	// Create a new node
	Node *tmp = new Node;
	tmp -> info = ikey;
	tmp -> lthread = true;
	tmp -> rthread = true;

	if (par == NULL)
	{
		root = tmp;
		tmp -> left = NULL;
		tmp -> right = NULL;
	}
	else if (ikey < (par -> info))
	{
		tmp -> left = par -> left;
		tmp -> right = par;
		par -> lthread = false;
		par -> left = tmp;
	}
	else
	{
		tmp -> left = par;
		tmp -> right = par -> right;
		par -> rthread = false;
		par -> right = tmp;
	}

	return root;
}

// Returns inorder successor using rthread
struct Node *inorderSuccessor(struct Node *ptr)
{
	// If rthread is set, we can quickly find
	if (ptr -> rthread == true)
		return ptr->right;

	// Else return leftmost child of right subtree
	ptr = ptr -> right;
	while (ptr -> lthread == false)
		ptr = ptr -> left;
	return ptr;
}

// Printing the threaded tree
void inorder(struct Node *root)
{
	if (root == NULL)
		printf("Tree is empty");

	// Reach leftmost node
	struct Node *ptr = root;
	while (ptr -> lthread == false)
		ptr = ptr -> left;

	// One by one print successors
	while (ptr != NULL)
	{
		printf("%d ",ptr -> info);
		ptr = inorderSuccessor(ptr);
	}
}

// Driver Program



int getWidth(struct node* root)
{
    int maxWidth = 0;
    int width;
    int h = height(root);
    int i;

    for (i=1; i<=h; i++)
    {
        int count = 0;
        printGivenLevel(root, i, &count);
        width = count;
        if (width > maxWidth)
            maxWidth = width;
    }

    return maxWidth;
}

int main()
{
}

list *createList(list *start, int size)
{
    for (int i = 0; i < size; i++)
    {
        list *ptr = start;
        printf("Enter Data\n");
        int data;
        scanf("%d", &data);
        list *temp = (list *)malloc((sizeof(list)));
        temp->info = data;
        temp->next = NULL;
        if (start == NULL)
        {
            ptr = start = temp;
        }
        else
        {
            while (ptr->next)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
}

void display(list *start)
{
    for (list *ptr = start; ptr != NULL; ptr = ptr->next)
    {
        printf("%d\t", &ptr->info);
    }
    printf("\n");
}

void displayInoreder(node *root)
{
    if (!root)
        return;
    displayInoreder(root->lchild);
    printf("%d", root->val);
    displayInoreder(root->rchild);
}

void displayPostorder(node *root)
{
    if (!root)
        return;
    displayPostorder(root->lchild);
    displayPostorder(root->rchild);
    printf("%d", root->val);
}

void displayPreorder(node *root)
{
    if (!root)
        return;
    printf("%d", root->val);
    displayPreorder(root->lchild);
    displayPreorder(root->rchild);
}

void LevelOrder(node *root)
{
    int h = getTreeHeight(root);
    for(int i = 1 ; i <= h; i++)
    {
        CurrentLevel(root,i);
    }
}

void CurrentLevel(node* root,int level)
{
    if(!root) return;
    if(level == 1) printf("%d", root->val);
    else if (level > 1)
    {
        CurrentLevel(root->lchild,level-1);
        CurrentLevel(root->rchild, level-1);
    }
}
