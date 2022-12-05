#include "stdio.h"
#include "malloc.h"

struct NODE
{
    int data;
    struct node *lchild;
    struct node *rchild;
    int balance_factor;
};

typedef struct NODE node;

node *insert(node *root, int key);
void displayIn();

int main()
{
}

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->lchild = temp->rchild = NULL;
        temp->data = key;
        return temp;
    }
    else
    {
        node *ptr = root;
        node *par = ptr;
        while (ptr != NULL)
        {
            par = ptr;
            if (par->data < key)
            {
                ptr = ptr->rchild;
            }
            else
            {
                ptr = ptr->lchild;
            }
        }
        node *temp = (node *)malloc(sizeof(node));
        temp->data = key;
        temp->lchild = temp->rchild = NULL;

        if (par->data < key)
        {
            par->rchild = temp;
        }
        else {
            par->lchild = temp;
        }
    }
    return root;
}