#include <stdio.h>
#include <stdlib.h>
struct dequeue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isfull(struct dequeue *ptr)
{
    if ((ptr->r + 1) % ptr->size == ptr->f)
    {
        return 1;
    }
    return 0;
}
int isempty(struct dequeue *ptr)
{
    if (ptr->f == ptr->r == -1)
    {
        return 1;
    }
    return 0;
}
void enqueue_from_f(struct dequeue *q, int val)
{
    if (isfull(q))
    {
        printf("queue overflow\n");
    }
    else

    {
        if (isempty(q))
        {
            q->f = q->r = 0;
        }
        else
        {

            q->f = (q->f - 1 + q->size) % q->size;
        }
        q->arr[q->f] = val;

        printf("Element enqueued from f is %d\n", val);
    }
}
int dequeue_from_f(struct dequeue *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("queue is empty\n");
    }
    else
    {
        if (q->r == q->f)
        {
            q->f = q->r = -1;
        }

        else
        {
            q->f = (q->f + 1) % q->size;
        }
        a = q->arr[q->f];
    }
    return a;
}
void enqueue_from_r(struct dequeue *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("Queue is full");
    }
    else
    {
        if (isempty(ptr))
        {
            ptr->f = ptr->r = 0; /* code */
        }

        else
        {
            ptr->r = (ptr->f - 1 + ptr->size) % ptr->size;
        }
        ptr->arr[ptr->r] = val;
        printf("Elment in the  rear queue is %d\n", val);
    }
}
int dequeue_from_r(struct dequeue *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("queue is empty\n");
    }
    else
    {
        if (q->r == q->f)
        {
            q->f = q->r= -1;
        }

        else
        {
            q->f = (q->f - 1 + q->size) % q->size;
        }
        a = q->arr[q->f];

        return a;
    }
}

int main()
{
    struct dequeue dq;
    dq.size = 8;
    dq.r = dq.f = -1;
    dq.arr = (int *)malloc(dq.size * sizeof(int));
    enqueue_from_f(&dq, 2);
    enqueue_from_f(&dq, 21);
    enqueue_from_f(&dq, 23);
    enqueue_from_r(&dq, 23);
    printf("element dequeued from rear is %d\n",dequeue_from_r(&dq));
    printf("element dequeued from front is %d\n",dequeue_from_f(&dq));

   

}