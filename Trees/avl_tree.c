#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
int getheight(struct node *n)
{
    if (n == NULL)
    {
        return NULL;
    }
    return n->height;
}
struct node *createnode(int key)
{
    struct node *a = (struct node *)malloc(sizeof(struct node));
    a->key = key;
    a->left = NULL;
    a->right = NULL;
    a->height = 1;
    return a;
}
int balancefact(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}
struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(getheight(y->right), getheight(y->left) + 1);
    x->height = max(getheight(x->right), getheight(x->left) + 1);

    return x;
}
struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t = y->right;

    y->left = x;
    x->right = t;

    y->height = max(getheight(y->right), getheight(y->left) + 1);
    x->height = max(getheight(x->right), getheight(x->left) + 1);

    return y;
}
struct node *insert(struct node *n, int key)
{
    if (n == NULL)
    {
        return createnode(key);
    }
    if (key < n->key)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->right)
    {
        n->right = insert(n->right, key);
        return n;
    }
    n->height=1+max(getheight(n->left), getheight(n->right));
    int bf = balancefact(n);
    // left left
    if (bf>1&& key< n->left->key)
    {
        /* code */
    }
    
    //  right right
    //  left right
    //  right left
}