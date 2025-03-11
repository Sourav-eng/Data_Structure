
#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;
};
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

int bst(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!bst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return bst(root->right);
    }
    else
    {
        return 1;
    }
}
struct node *searchiter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{

    struct node *p = createnode(5);
    struct node *p2 = createnode(3);
    struct node *p3 = createnode(6);
    struct node *p4 = createnode(1);
    struct node *p5 = createnode(4);
    // struct node *p6 = createnode(6);

    p->left = p2;
    p->right = p3;
    p2->left = p4;
    p2->right = p5;
    // p3->left = p6;

    inorder(p);
    printf("\n");
    // printf("%d", bst(p));
    //  printf("\n");
    struct node *n = searchiter(p, 8);
    if (n != NULL)
    {
        printf("found %d", n->data);
    }
    else
    {
        printf("elenent not found");
    }

    return 0;
}