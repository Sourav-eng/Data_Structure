#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isempty(struct Queue *ptr)
{
    if (ptr->r == ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct Queue *ptr)
{
    if (ptr->r == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct Queue *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("Queue is full");
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = val;
        printf("Elment in the queue are %d\n", val);
    }
}
int dequeue(struct Queue *ptr)
{
    int a = -1;
    if (isempty(ptr))
    {
        printf("Queue is empty"); /* code */
    }
    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main()
{
    struct Queue q;

    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 4);
    enqueue(&q, 42);
    enqueue(&q, 41);
    enqueue(&q, 49);
    printf("Element dequeued from queue is %d\n",dequeue(&q));
    printf("Element dequeued from queue is %d\n",dequeue(&q));
    printf("Element dequeued from queue is %d\n",dequeue(&q));
    printf("Element dequeued from queue is %d\n",dequeue(&q));
     enqueue(&q, 9);

}
