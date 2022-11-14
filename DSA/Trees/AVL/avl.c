#include "stdio.h"
#include "malloc.h"

struct NODE
{
    int key;
    struct NODE *lchild;
    struct NODE *rchild;
    int height;
};
typedef struct NODE node;

int height(node *root); // get height

int max(int a, int b) // max of 2
{
    return (a > b) ? a : b;
}

// helper function new node
node *newNode(int key)
{
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    n->lchild = n->rchild = NULL;
    n->height = 1;
    return n;
}

node *rightRotate(node *y)
{
    /*
     y                                x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
    */

    node *x = y->lchild;
    node *t2 = x->rchild;

    x->rchild = y;
    y->lchild = t2;

    y->height = max(height(y->lchild), height(y->rchild) + 1);
    x->height = max(height(x->lchild), height(x->rchild) + 1);

    return x;
}

node *leftRotate(node *x)
{
    /*
    y                                x
   / \     Right Rotation          /  \
  x   T3   - - - - - - - >        T1   y
 / \       < - - - - - - -            / \
T1  T2     Left Rotation            T2  T3
   */
    node *y = x->rchild;
    node *t2 = y->lchild;

    y->lchild = x;
    x->rchild = t2;

    x->height = max(height(x->lchild), height(x->rchild) + 1);
    y->height = max(height(y->lchild), height(y->rchild) + 1);

    return y;
}

int getBalance(node *n)
{
    if (n == NULL)
        return 0;

    return height(n->lchild) - height(n->rchild);
}

node *insert(node *n, int key)
{
    if (n == NULL)
        return (newNode(key));

    if (key < n->key)
        n->lchild = insert(n->lchild, key);

    else if (key > n->key)
        n->rchild = insert(n->rchild, key);

    else
        return n;

    n->height = 1 + max(height(n->lchild), height(n->rchild));

    int balance = getBalance(n);

    // if node is unbalanced
    /*
    LL CASE
    T1, T2, T3 and T4 are subtrees.
         z                                      y
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
    */
    if (balance > 1 && key < n->lchild->key)
        return rightRotate(n);

    /* RR CASE

     z                                y
   /  \                            /   \
  T1   y     Left Rotate(z)       z      x
     /  \   - - - - - - - ->    / \    / \
    T2   x                     T1  T2 T3  T4
        / \
      T3  T4
 */
    if (balance < -1 && key > n->rchild->key)
        return leftRotate(n);

    /* LR CASE
    z                               z                           x
    / \                            /   \                        /  \
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2
    */
    if (balance > 1 && key > n->lchild->key)
    {
        n->lchild = leftRotate(n->lchild);
        return rightRotate(n);
    }

    /* RL CASE
        z                            z                            x
      / \                          / \                          /  \
    T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
        / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
       x   T4                      T2   y                  T1  T2  T3  T4
      / \                              /  \
    T2   T3                           T3   T4

    */

    if (balance < -1 && key < n->rchild->key)
    {
        n->rchild = rightRotate(n->rchild);
        return leftRotate(n);
    }

    // unchanged case
    return n;
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

int main()
{
    node *root;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
    */

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);
}

int height(node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}