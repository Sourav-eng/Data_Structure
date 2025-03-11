#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;
void traversal(struct node *p)
{
    while (p != NULL)
    {
        printf("element are %d\n", p->data);
        p = p->next;
    }
}
void enqueue( int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        if (f == NULL)
        {
            f = r = ptr;
        }
        else
        {
            r->next = ptr;
            r = ptr;
        }
    }
}
int dequeue(struct node *f)
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("Queeue is underfloe");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}


int main()
{
    traversal(f);
    enqueue(3);
    enqueue(4);
    enqueue(65);
    enqueue(1);
    traversal(f);
    printf("Element dequeued is %d\n",dequeue(f));
}
