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
